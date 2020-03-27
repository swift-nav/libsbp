use std::boxed::Box;
use std::io::{BufRead, BufReader, Cursor, Read, Seek, SeekFrom, Write};
use std::rc::Rc;

use serde::ser::Serialize;

use serde_json::ser::{Formatter, Serializer};
use serde_json::Value;

use serde_json::json;

use float_pretty_print::PrettyPrintFloat;

use super::messages::SBPMessage;
use super::messages::SBP;

pub type Error = Box<dyn std::error::Error + Sync + Send>;

pub type Result<T> = std::result::Result<T, Error>;

/// The read buffer size, this buffer will be re-used with varying offsets until
/// there is no remaining space, any "leftover" data will be cycled to the front
/// of the buffer and old data will be flushed.
const BUF_SIZE: usize = 4096;

/// Size of the SBP message header, used to extract the payload portion
/// of a framed SBP message.
const MSG_HEADER_LEN: usize = 1 /*preamble*/ + 2 /*msg_type*/ + 2 /*sender_id*/ + 1 /*len*/;

/// The length of the CRC in SBP, used to extract the CRC value of a
/// framed SBP message.
const MSG_CRC_LEN: usize = 2;

/// Read `stream` line by line and parse a JSON object from each line.
/// The function specified by `func` will be called for each object
/// that's parsed.
pub fn json_read_loop<F>(stream: &mut dyn Read, mut func: F) -> Result<()>
where
    F: FnMut(&Value) -> Result<()>,
{
    let reader = BufReader::new(stream);
    for line in reader.lines() {
        match line {
            Ok(line) => {
                let line_length = line.len();
                let mut cursor = Cursor::new(line);
                let value: serde_json::Result<Value> = serde_json::from_reader(cursor.by_ref());
                match value {
                    Ok(value) => {
                        func(&value)?;
                    }
                    Err(err) => {
                        return Err(err.into());
                    }
                }
                let pos = cursor.seek(SeekFrom::Current(0))? as usize;
                if line_length != pos {
                    eprintln!("WARNING: unconsumed data on input line");
                }
            }
            Err(err) => {
                return Err(err.into());
            }
        }
    }

    Ok(())
}

/// Attempts to format a float similar to Haskell's showFloat, this mostly
/// succeeds for values that use exponential notation but fails for values that
/// do not.
fn haskellish_float<W: ?Sized, D: std::fmt::Display>(
    writer: &mut W,
    value: D,
) -> std::io::Result<()>
where
    W: std::io::Write,
    D: Into<f64> + Copy + dtoa::Floating,
{
    let f64_value: f64 = value.into();

    if f64_value.abs() >= 0.1f64 && f64_value.abs() <= 9999999f64 {
        dtoa::write(writer, f64_value).map(|_| ())
    } else {
        write!(writer, "{:.13}", PrettyPrintFloat(f64_value))
    }
}

/// Provide Haskell style formatting (sort of).  See `haskellish_float`.
struct HaskellishFloatFormatter {}

/// Provide Haskell style formatting (sort of).  See `haskellish_float`.
impl Formatter for HaskellishFloatFormatter {
    #[inline]
    fn write_f32<W: ?Sized>(&mut self, writer: &mut W, value: f32) -> std::io::Result<()>
    where
        W: std::io::Write,
    {
        haskellish_float(writer, value)
    }

    #[inline]
    fn write_f64<W: ?Sized>(&mut self, writer: &mut W, value: f64) -> std::io::Result<()>
    where
        W: std::io::Write,
    {
        haskellish_float(writer, value)
    }
}

/// Serialize a `serde_json::Value` into a serde serializer
fn serialize<S>(ser: S, value: &serde_json::Value) -> Result<()>
where
    S: serde::Serializer<Ok = ()>,
{
    value.serialize(ser).map_err(|e| format!("{}", e).into())
}

/// SBP objects from the Rust library are typically serialized with the type
/// of the object embedded as a top-level key.  For example:
///
///  {"MsgDops":{"flags":6,"gdop":174,"hdop":73,"pdop":150,...}}
///
/// This function extracts the object that's under the top-level key ("MsgDops"
/// in the above example).
fn unpack<'a>(value: &'a mut serde_json::Value) -> Option<&'a mut serde_json::Value> {
    if !value.is_object() {
        return None;
    }

    let key: Option<String>;
    {
        let map = value.as_object().unwrap();
        let mut keys = map.keys();
        if keys.len() != 1 {
            return None;
        }
        key = Some(keys.next().unwrap().clone());
    }

    let map = value.as_object_mut().unwrap();

    if let Some(key) = key {
        Some(map.get_mut(&key).unwrap())
    } else {
        None
    }
}

/// Add common fields to the input JSON object: length, msg_type, payload, preamble, crc, and
/// sender_id.
fn add_common_fields<'a>(
    msg: &dyn SBPMessage,
    payload: &[u8],
    value: &'a mut serde_json::Value,
    base64_payload: &'a mut String,
) -> &'a mut serde_json::Value {
    if !value.is_object() {
        return value;
    }

    let sender_id = msg.get_sender_id();
    let size = msg.sbp_size();
    let msg_type = msg.get_message_type();
    let map = value.as_object_mut().unwrap();

    base64_payload.clear();
    base64::encode_config_buf(
        &payload[MSG_HEADER_LEN..MSG_HEADER_LEN + size],
        base64::STANDARD,
        base64_payload,
    );

    let crc_b0: u16 = payload[MSG_HEADER_LEN + size..MSG_HEADER_LEN + size + MSG_CRC_LEN][0] as u16;
    let crc_b1: u16 = payload[MSG_HEADER_LEN + size..MSG_HEADER_LEN + size + MSG_CRC_LEN][1] as u16;
    let crc: u16 = (crc_b1 << 8) | crc_b0;

    map.insert("length".into(), json!(size));
    map.insert("msg_type".into(), json!(msg_type));
    map.insert("payload".into(), json!(base64_payload));
    map.insert("preamble".into(), json!(&payload[0]));
    map.insert("crc".into(), json!(crc));

    if map.contains_key("sender_id") {
        map.remove("sender_id");
    }
    if let Some(sender_id) = sender_id {
        map.insert("sender".into(), json!(sender_id));
    }

    value
}

/// Write's an SBP message formatted as JSON in `value` to the `Write` stream specified by
/// `stream`.  Adds all the default values ("payload" encoded as base64, "sender", "msg_type",
/// etc). to the outputted JSON object.
fn write_sbp_json_value(
    float_compat: bool,
    rewrap_data: bool,
    base64_payload: &mut String,
    common_sbp: &dyn SBPMessage,
    slice: &[u8],
    value: &mut Value,
    stream: &mut Rc<Box<dyn Write>>,
) -> Result<()> {
    let value = unpack(value);
    let value = add_common_fields(common_sbp, slice, value.unwrap(), base64_payload);
    let data_wrapped;
    let value = if rewrap_data {
        data_wrapped = json!({ "data": value });
        &data_wrapped
    } else {
        value
    };
    if float_compat {
        let io_ref = Rc::get_mut(stream).expect("could not get output stream");
        let mut ser = Serializer::with_formatter(io_ref, HaskellishFloatFormatter {});
        serialize(&mut ser, &value)?;
    } else {
        let io_ref = Rc::get_mut(stream).expect("could not get output stream");
        let mut ser = Serializer::new(io_ref);
        serialize(&mut ser, &value)?;
    };
    let io_ref = Rc::get_mut(stream).expect("could not get output stream");
    writeln!(io_ref, "")?;
    Ok(())
}

/// The Swift console stores SBP JSON in the "data" field of a JSON object, if this field is
/// present then we should unpack the SPB JSON from it.
fn unwrap_data_obj<'a>(value: &'a Value) -> (&'a Value, bool) {
    if !value.is_object() {
        return (value, false);
    }
    let map = value.as_object().unwrap();
    if map.contains_key("payload") {
        return (value, false);
    }
    if !map.contains_key("data") {
        return (value, false);
    }
    (map.get("data").unwrap(), true)
}

fn get_payload<'a>(value: &'a Value) -> Option<&'a str> {
    if !value.is_object() {
        return None;
    }
    let value = value.as_object().unwrap();
    if !value.contains_key("payload") {
        return None;
    }
    let payload = value.get("payload").unwrap();
    if !payload.is_string() {
        return None;
    }
    Some(payload.as_str().unwrap())
}

fn get_msg_type(value: &Value) -> Option<u16> {
    if !value.is_object() {
        panic!("value always expected to be an object");
    }
    let value = value.as_object().unwrap();
    if !value.contains_key("msg_type") {
        return None;
    }
    let msg_type = value.get("msg_type").unwrap();
    if msg_type.is_i64() {
        return Some(msg_type.as_i64().unwrap() as u16);
    }
    if msg_type.is_u64() {
        return Some(msg_type.as_u64().unwrap() as u16);
    }
    None
}

fn get_sender_id(value: &Value) -> u16 {
    if !value.is_object() {
        panic!("value always expected to be an object");
    }
    let value = value.as_object().unwrap();
    if !value.contains_key("sender") {
        return 0;
    }
    let sender_id = value.get("sender").unwrap();
    if sender_id.is_i64() {
        return sender_id.as_i64().unwrap() as u16;
    }
    if sender_id.is_u64() {
        return sender_id.as_u64().unwrap() as u16;
    }
    0
}

pub fn json2sbp_process_with_expand(
    value: &Value,
    debug: bool,
    float_compat: bool,
    expand_json: bool,
    stream_output: &mut Rc<Box<dyn Write>>,
) -> Result<()> {
    let mut base64_payload: String = String::with_capacity(512);
    let (value, rewrap_data) = unwrap_data_obj(&value);
    let payload = get_payload(value);
    if let Some(payload) = payload {
        let sender_id = get_sender_id(value);
        let msg_type = get_msg_type(value);
        if let Some(msg_type) = msg_type {
            let payload = payload.as_bytes();
            let payload = base64::decode(payload);
            if let Ok(payload) = payload {
                let mut payload = payload.as_slice();
                let sbp_msg = SBP::parse(msg_type, sender_id, &mut payload);
                if let Ok(sbp_msg) = sbp_msg {
                    let common_sbp = sbp_msg.as_sbp_message();
                    let res = common_sbp.to_frame();
                    if let Ok(res) = res {
                        if expand_json {
                            let mut value = serde_json::to_value(&sbp_msg)?;
                            write_sbp_json_value(
                                float_compat,
                                rewrap_data,
                                &mut base64_payload,
                                common_sbp,
                                &res[..],
                                &mut value,
                                stream_output,
                            )?;
                        } else {
                            let io_ref =
                                Rc::get_mut(stream_output).expect("could not get output stream");
                            if let Err(err) = io_ref.write_all(&res) {
                                if debug {
                                    eprintln!("IO write failed: {:?}", err);
                                }
                            }
                        }
                    } else if debug {
                        eprintln!("SBP framing failed: {:?}", res.err());
                    }
                } else if debug {
                    eprintln!("SBP parse failed: {:?}", sbp_msg.err());
                }
            } else if debug {
                eprintln!("payload decode failed: {:?}", payload.err());
            }
        } else if debug {
            eprintln!("no 'msg_type' field");
        }
    } else if debug {
        eprintln!("no 'payload' field: {}", value);
    }
    Ok(())
}

/// The main SBP read loop, uses one buffer of size `BUF_SIZE`, and tracks the following
///   markers for the buffer:
///                                             
///  ```text
///
///                                                         |<---remaining_length--->|
///                                                         |                        |
///                              |<-------read_length------>|                        |
///                              |                          |                        |
///                              read_offset                |                        |
///         unconsumed_offset    ^                          |                        |
///         ^                    |                          |                        |
///         |                    |                          |                        |
///  +------+--------------------+---------------------------------------------------+
///  |######%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&|
///  +-------------------------------------------------------------------------------+
///
///  ```
///
///  Where:
///    ### -> old data, available to be dropped or overwritten
///    %%% -> leftover data from previous read, not yet processed
///    @@@ -> newly read data data, not yet processed
///    &&& -> remaining free space in the buffer
///
///  The following definitions apply for the offsets / lengths tracked:
///
///  ```text
///
///    'unconsumed_offset' -> start of data that needs to be processed, could point to left over
///      data from a previous read, or could be the same as read_offset.
///
///      Invariant: unconsumed_offset <= read_offset
///
///    'read_offset' -> the point where a new read should place its data
///
///    'read_length' -> the size of the last read, used to update `remaining_length`
///
///    'remaining_length' -> the remaining available space in the buffer
///
///  ```
///
pub fn sbp2json_read_loop(
    debug: bool,
    debug_memory: bool,
    float_compat: bool,
    input_stream: &mut dyn Read,
    output_stream: &mut Rc<Box<dyn Write>>,
) -> Result<()> {
    let mut base64_payload: String = String::with_capacity(512);
    let mut buf = [0u8; BUF_SIZE];
    let mut unconsumed_offset = 0;
    let mut read_offset = 0;
    let mut remaining_length = buf.len();
    loop {
        if remaining_length == 0 {
            if debug {
                eprintln!(
                    "remaining_length == 0: read_offset: {}, unconsumed_offset: {}",
                    read_offset, unconsumed_offset
                );
            }
            buf.rotate_left(unconsumed_offset);
            read_offset = read_offset - unconsumed_offset;
            unconsumed_offset = 0;
            remaining_length = buf.len() - read_offset;
        }
        let read_length = input_stream.read(&mut buf[read_offset..])?;
        if debug {
            eprintln!(
                "loop: read_length: {}, unconsumed_offset: {}",
                read_offset, unconsumed_offset
            );
        }
        if read_length == 0 {
            break;
        }
        read_offset += read_length;
        remaining_length -= read_length;
        if debug_memory {
            eprintln!(
                "memory: base64_payload: {}, buf: {}",
                base64_payload.capacity(),
                buf.len()
            );
        }
        loop {
            if debug {
                eprintln!(
                    "loop.loop.enter: read_offset: {}, unconsumed_offset: {}",
                    read_offset, unconsumed_offset
                );
            }
            let bytes_available = read_offset - unconsumed_offset;
            if bytes_available == 0 {
                break;
            }
            let slice = &buf[unconsumed_offset..(unconsumed_offset + bytes_available)];
            let (res, consumed) = super::parser::frame(slice);
            match res {
                Ok(msg) => {
                    let common_sbp = msg.as_sbp_message();
                    let mut value = serde_json::to_value(&msg)?;
                    write_sbp_json_value(
                        float_compat,
                        false,
                        &mut base64_payload,
                        common_sbp,
                        slice,
                        &mut value,
                        output_stream,
                    )?;
                    unconsumed_offset += consumed;
                    if debug {
                        eprintln!(
                            "loop.loop.frame: consumed: {}, unconsumed_offset: {}",
                            consumed, unconsumed_offset
                        );
                    }
                }
                Err(err) => match err {
                    super::Error::CrcError => {
                        if debug {
                            eprintln!("loop.loop.error: crc error");
                        }
                        unconsumed_offset += consumed;
                    }
                    super::Error::ParseError => {
                        if debug {
                            eprintln!("loop.loop.error: parse error");
                        }
                        unconsumed_offset += consumed;
                    }
                    super::Error::NotEnoughData => {
                        if debug {
                            eprintln!("loop.loop.error: not enough data");
                        }
                        break;
                    }
                    super::Error::UnrecoverableFailure => panic!("unrecoverable failure"),
                    super::Error::IoError(err) => panic!("I/O error: {}", err),
                },
            }
        }
    }
    Ok(())
}

pub fn json2json_read_loop(
    debug: bool,
    float_compat: bool,
    stream_input: &mut dyn Read,
    stream_output: &mut Rc<Box<dyn Write>>,
) -> Result<()> {
    let json2json_process = |value: &Value| -> Result<()> {
        json2sbp_process_with_expand(value, debug, float_compat, true, stream_output)
    };

    json_read_loop(stream_input, json2json_process)
}

pub fn json2sbp_read_loop(
    debug: bool,
    stream_input: &mut dyn Read,
    stream_output: &mut Rc<Box<dyn Write>>,
) -> Result<()> {
    let json2sbp_process = |value: &Value| -> Result<()> {
        json2sbp_process_with_expand(value, debug, false, false, stream_output)
    };

    json_read_loop(stream_input, json2sbp_process)
}
