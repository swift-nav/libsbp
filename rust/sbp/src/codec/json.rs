use std::collections::HashMap;

use bytes::{Buf, BufMut, BytesMut};
use dencode::{Decoder, Encoder};
use serde::{de::DeserializeOwned, Deserialize, Serialize};
use serde_json::{ser::Formatter, Deserializer, Serializer, Value};

pub use serde_json::ser::CompactFormatter;

const BASE64_SBP_MAX_PAYLOAD_SIZE: usize = crate::SBP_MAX_PAYLOAD_SIZE / 3 * 4 + 4;

use crate::{
    messages::{SBPMessage, SBP},
    serialize::SbpSerialize,
    Error, Result,
};

pub fn iter_messages<R: std::io::Read>(
    input: R,
) -> impl Iterator<Item = Result<crate::messages::SBP>> {
    dencode::FramedRead::new(input, JsonDecoder::new())
}

#[cfg(feature = "async")]
pub fn stream_messages<R: futures::AsyncRead + Unpin>(
    input: R,
) -> impl futures::Stream<Item = Result<SBP>> {
    dencode::FramedRead::new(input, JsonDecoder::new())
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum JsonInput {
    Input(CommonJsonInput),
    Nested { data: CommonJsonInput },
}

impl JsonInput {
    pub fn into_inner(self) -> CommonJsonInput {
        match self {
            JsonInput::Input(data) | JsonInput::Nested { data } => data,
        }
    }
}

#[derive(Debug, Deserialize)]
struct CommonJsonInput {
    msg_type: u16,
    payload: String,
    sender: u16,
}

pub struct JsonDecoder {
    payload_buf: Vec<u8>,
}

impl JsonDecoder {
    pub fn new() -> Self {
        JsonDecoder {
            payload_buf: Vec::with_capacity(crate::SBP_MAX_PAYLOAD_SIZE),
        }
    }

    fn parse_json(&mut self, input: JsonInput) -> Result<SBP> {
        let data = input.into_inner();

        self.payload_buf.clear();
        base64::decode_config_buf(data.payload, base64::STANDARD, &mut self.payload_buf).map_err(
            |err| Error::JsonParseError {
                details: format!("Invalid base64 payload: {}", err),
            },
        )?;
        let mut payload = self.payload_buf.as_slice();

        SBP::parse(data.msg_type, data.sender, &mut payload)
    }
}

impl Decoder for JsonDecoder {
    type Item = SBP;
    type Error = Error;

    fn decode(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>> {
        let value = match decode_one::<JsonInput>(src)? {
            Some(v) => v,
            None => return Ok(None),
        };
        self.parse_json(value).map(Option::Some)
    }
}

#[derive(Debug, Deserialize)]
pub struct Json2JsonInput {
    data: OwnedCommonJson,

    #[serde(flatten)]
    other: HashMap<String, Value>,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct OwnedCommonJson {
    crc: u16,
    length: u8,
    msg_type: u16,
    payload: String,
    preamble: u8,
    sender: u16,
}

pub struct Json2JsonDecoder {}

impl Decoder for Json2JsonDecoder {
    type Item = Json2JsonInput;
    type Error = Error;

    fn decode(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>> {
        decode_one::<Json2JsonInput>(src)
    }
}

fn decode_one<T: DeserializeOwned>(buf: &mut BytesMut) -> Result<Option<T>> {
    let mut de = Deserializer::from_slice(&buf).into_iter::<T>();
    let value = de.next();

    let bytes_read = de.byte_offset();
    buf.advance(bytes_read);

    match value.transpose() {
        Ok(v) => Ok(v),
        Err(e) if e.is_eof() => Ok(None),
        Err(e) => Err(e.into()),
    }
}

#[derive(Debug, Serialize, Deserialize)]
struct CommonJson<'a> {
    crc: u16,
    length: u8,
    msg_type: u16,
    payload: &'a str,
    preamble: u8,
    sender: u16,
}

pub struct JsonEncoder<F> {
    payload_buf: String,
    frame_buf: Vec<u8>,
    formatter: F,
}

impl<F: Formatter + Clone> JsonEncoder<F> {
    pub fn new(formatter: F) -> Self {
        JsonEncoder {
            frame_buf: Vec::with_capacity(crate::SBP_MAX_PAYLOAD_SIZE),
            payload_buf: String::with_capacity(BASE64_SBP_MAX_PAYLOAD_SIZE),
            formatter,
        }
    }
}

#[derive(Debug, Serialize)]
struct JsonOutput<'a> {
    #[serde(flatten)]
    common: CommonJson<'a>,

    #[serde(flatten)]
    msg: &'a SBP,
}

impl<F, T> Encoder<T> for JsonEncoder<F>
where
    F: Formatter + Clone,
    T: AsRef<SBP>,
{
    type Error = Error;

    fn encode(&mut self, msg: T, dst: &mut BytesMut) -> Result<()> {
        let msg = msg.as_ref();
        let formatter = self.formatter.clone();
        let common = get_common_fields(&mut self.payload_buf, &mut self.frame_buf, msg)?;
        let output = JsonOutput { common, msg };

        let mut ser = Serializer::with_formatter(dst.writer(), formatter);
        output.serialize(&mut ser)?;
        dst.put_slice(b"\n");

        Ok(())
    }
}

#[derive(Debug, Serialize)]
struct Json2JsonOutput<'a> {
    data: JsonOutput<'a>,

    #[serde(flatten)]
    other: HashMap<String, Value>,
}

pub struct Json2JsonEncoder<F> {
    payload_buf: String,
    frame_buf: Vec<u8>,
    formatter: F,
}

impl<F: Formatter + Clone> Json2JsonEncoder<F> {
    pub fn new(formatter: F) -> Self {
        Json2JsonEncoder {
            frame_buf: Vec::with_capacity(crate::SBP_MAX_PAYLOAD_SIZE),
            payload_buf: String::with_capacity(BASE64_SBP_MAX_PAYLOAD_SIZE),
            formatter,
        }
    }
}

impl<F: Formatter + Clone> Encoder<Json2JsonInput> for Json2JsonEncoder<F> {
    type Error = Error;

    fn encode(&mut self, input: Json2JsonInput, dst: &mut BytesMut) -> Result<()> {
        let formatter = self.formatter.clone();

        let payload = base64::decode(input.data.payload).map_err(|err| Error::JsonParseError {
            details: format!("Invalid base64 payload: {}", err),
        })?;

        let msg = {
            let mut payload = payload.as_slice();
            SBP::parse(input.data.msg_type, input.data.sender, &mut payload)?
        };

        let output = Json2JsonOutput {
            data: JsonOutput {
                common: get_common_fields(&mut self.payload_buf, &mut self.frame_buf, &msg)?,
                msg: &msg,
            },
            other: input.other,
        };

        let mut ser = Serializer::with_formatter(dst.writer(), formatter);
        output.serialize(&mut ser)?;
        dst.put_slice(b"\n");

        Ok(())
    }
}

fn get_common_fields<'a>(
    payload_buf: &'a mut String,
    frame_buf: &'a mut Vec<u8>,
    msg: &SBP,
) -> Result<CommonJson<'a>> {
    payload_buf.clear();
    frame_buf.clear();

    let length = msg.sbp_size();

    msg.write_frame(frame_buf)?;

    let crc = {
        let crc_b0 = frame_buf
            [crate::MSG_HEADER_LEN + length..crate::MSG_HEADER_LEN + length + crate::MSG_CRC_LEN][0]
            as u16;
        let crc_b1 = frame_buf
            [crate::MSG_HEADER_LEN + length..crate::MSG_HEADER_LEN + length + crate::MSG_CRC_LEN][1]
            as u16;
        (crc_b1 << 8) | crc_b0
    };

    base64::encode_config_buf(
        &frame_buf[crate::MSG_HEADER_LEN..crate::MSG_HEADER_LEN + length],
        base64::STANDARD,
        payload_buf,
    );

    Ok(CommonJson {
        preamble: 0x55,
        sender: msg.get_sender_id().unwrap_or(0),
        msg_type: msg.get_message_type(),
        length: length as u8,
        payload: payload_buf,
        crc,
    })
}

/// Provide Haskell style formatting. Output should be similar to: https://hackage.haskell.org/package/base-4.8.2.0/docs/Numeric.html#v:showFloat
#[derive(Clone)]
pub struct HaskellishFloatFormatter {}

macro_rules! show_float {
    ($writer:expr, $value:expr) => {
        if $value == 0.0 || $value.abs() >= 0.1 && $value.abs() <= 9_999_999.0 {
            write!($writer, "{}", $value)
        } else {
            write!($writer, "{:e}", $value)
        }
    };
}

impl Formatter for HaskellishFloatFormatter {
    #[inline]
    fn write_f32<W: ?Sized>(&mut self, writer: &mut W, value: f32) -> std::io::Result<()>
    where
        W: std::io::Write,
    {
        show_float!(writer, value)
    }

    #[inline]
    fn write_f64<W: ?Sized>(&mut self, writer: &mut W, value: f64) -> std::io::Result<()>
    where
        W: std::io::Write,
    {
        show_float!(writer, value)
    }
}
