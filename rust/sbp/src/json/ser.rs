use std::{borrow::Borrow, convert::TryInto, io};

use base64::{Engine, prelude::BASE64_STANDARD};
use bytes::{BufMut, BytesMut};
use dencode::{Encoder, FramedWrite, IterSinkExt};
use serde::Serialize;
use serde_json::{Serializer, ser::Formatter};

use crate::{
    BUFLEN, CRC_LEN, HEADER_LEN, MIN_FRAME_LEN, PREAMBLE, SbpMessage,
    json::{
        CommonJson, HaskellishFloatFormatter, Json2JsonInput, Json2JsonOutput, JsonError,
        JsonOutput,
    },
    messages::Sbp,
};

const BASE64_BUFLEN: usize = BUFLEN * 4;

/// Serialize the given message as JSON into the IO stream.
pub fn to_writer<W, M>(mut writer: W, msg: &M) -> Result<(), JsonError>
where
    W: io::Write,
    M: SbpMessage + Serialize,
{
    let mut frame = BytesMut::with_capacity(BUFLEN);
    let mut payload = String::with_capacity(BUFLEN);
    let mut buf = BytesMut::with_capacity(BUFLEN);
    to_buffer(
        &mut frame,
        &mut payload,
        &mut buf,
        HaskellishFloatFormatter,
        msg,
    )?;
    writer.write_all(&buf)?;
    Ok(())
}

/// Serialize the given message as a JSON byte vector.
pub fn to_vec<M>(msg: &M) -> Result<Vec<u8>, JsonError>
where
    M: SbpMessage + Serialize,
{
    let mut frame = BytesMut::with_capacity(BUFLEN);
    let mut payload = String::with_capacity(BUFLEN);
    let mut buf = BytesMut::with_capacity(BUFLEN);
    to_buffer(
        &mut frame,
        &mut payload,
        &mut buf,
        HaskellishFloatFormatter,
        msg,
    )?;
    Ok(buf.to_vec())
}

pub fn to_buffer<M, F>(
    frame_buf: &mut BytesMut,
    payload_buf: &mut String,
    dst: &mut BytesMut,
    formatter: F,
    msg: &M,
) -> Result<(), JsonError>
where
    F: Formatter,
    M: SbpMessage + Serialize + Clone,
{
    let output = JsonOutput::new_from_sbp(payload_buf, frame_buf, msg)?;
    let mut ser = Serializer::with_formatter(dst.writer(), formatter);
    output.serialize(&mut ser)?;
    dst.put_slice(b"\n");
    Ok(())
}

/// Writes [Sbp] messages as JSON into a writer.
#[derive(Debug)]
pub struct JsonEncoder<W, F>(FramedWrite<W, JsonEncoderInner<F>>);

impl<W, F> JsonEncoder<W, F>
where
    W: io::Write,
    F: Formatter + Clone,
{
    /// Creates a new JsonEncoder.
    pub fn new(writer: W, formatter: F) -> JsonEncoder<W, F> {
        Self(FramedWrite::new(writer, JsonEncoderInner::new(formatter)))
    }

    /// Send a message to the underlying writer. If sending multiple messages at once
    /// consider using [JsonEncoder::send_all] which buffers the writing.
    pub fn send(&mut self, message: &Sbp) -> Result<(), JsonError> {
        self.0.send(message)
    }

    /// Sends an iterator of messages to the underlying writer.
    pub fn send_all<I>(&mut self, messages: I) -> Result<(), JsonError>
    where
        I: IntoIterator<Item = Sbp>,
    {
        self.0.send_all(messages.into_iter().map(Result::Ok))
    }
}

#[derive(Debug, Default)]
struct JsonEncoderInner<F> {
    payload_buf: String,
    frame_buf: BytesMut,
    formatter: F,
}

impl<F: Formatter + Clone> JsonEncoderInner<F> {
    fn new(formatter: F) -> Self {
        JsonEncoderInner {
            frame_buf: BytesMut::with_capacity(BUFLEN),
            payload_buf: String::with_capacity(BASE64_BUFLEN),
            formatter,
        }
    }
}

impl<F, T> Encoder<T> for JsonEncoderInner<F>
where
    F: Formatter + Clone,
    T: Borrow<Sbp>,
{
    type Error = JsonError;

    fn encode(&mut self, msg: T, dst: &mut BytesMut) -> Result<(), Self::Error> {
        to_buffer(
            &mut self.frame_buf,
            &mut self.payload_buf,
            dst,
            self.formatter.clone(),
            msg.borrow(),
        )
    }
}

/// Writes [Json2JsonInput] messages as JSON into a writer.
#[derive(Debug)]
pub struct Json2JsonEncoder<W, F>(FramedWrite<W, Json2JsonEncoderInner<F>>);

impl<W, F> Json2JsonEncoder<W, F>
where
    W: io::Write,
    F: Formatter + Clone,
{
    /// Creates a new Json2JsonEncoder.
    pub fn new(writer: W, formatter: F) -> Json2JsonEncoder<W, F> {
        Self(FramedWrite::new(
            writer,
            Json2JsonEncoderInner::new(formatter),
        ))
    }

    /// Send a message to the underlying writer. If sending multiple messages at once
    /// consider using [Json2JsonEncoder::send_all] which buffers the writing.
    pub fn send(&mut self, message: Json2JsonInput) -> Result<(), JsonError> {
        self.0.send(message)
    }

    /// Sends an iterator of messages to the underlying writer.
    pub fn send_all<I>(&mut self, messages: I) -> Result<(), JsonError>
    where
        I: IntoIterator<Item = Json2JsonInput>,
    {
        self.0.send_all(messages.into_iter().map(Result::Ok))
    }
}

#[derive(Debug, Default)]
struct Json2JsonEncoderInner<F> {
    payload_buf: String,
    frame_buf: BytesMut,
    formatter: F,
}

impl<F: Formatter + Clone> Json2JsonEncoderInner<F> {
    fn new(formatter: F) -> Self {
        Json2JsonEncoderInner {
            frame_buf: BytesMut::with_capacity(BUFLEN),
            payload_buf: String::with_capacity(BASE64_BUFLEN),
            formatter,
        }
    }
}

impl<F: Formatter + Clone> Encoder<Json2JsonInput> for Json2JsonEncoderInner<F> {
    type Error = JsonError;

    fn encode(&mut self, input: Json2JsonInput, dst: &mut BytesMut) -> Result<(), Self::Error> {
        let formatter = self.formatter.clone();
        let payload = BASE64_STANDARD.decode(input.data.payload)?;
        let msg = Sbp::from_parts(
            input.data.msg_type,
            input.data.sender,
            BytesMut::from(&payload[..]),
        )?;
        let output = Json2JsonOutput {
            data: JsonOutput::new_from_sbp(&mut self.payload_buf, &mut self.frame_buf, &msg)?,

            other: input.other,
        };
        let mut ser = Serializer::with_formatter(dst.writer(), formatter);
        output.serialize(&mut ser)?;
        dst.put_slice(b"\n");
        Ok(())
    }
}

pub(super) fn get_common_fields<'a, M: SbpMessage>(
    payload_buf: &'a mut String,
    frame_buf: &'a mut BytesMut,
    msg: &M,
) -> Result<Option<CommonJson<'a>>, JsonError> {
    payload_buf.clear();
    frame_buf.clear();
    let size = msg.len();
    if let Err(crate::messages::invalid::Invalid { invalid_frame, .. }) =
        (*msg).clone().into_valid_msg()
    {
        BASE64_STANDARD.encode_string(&invalid_frame, payload_buf);
        return Ok(Some(CommonJson {
            preamble: None,
            sender: None,
            msg_name: msg.message_name(),
            msg_type: None,
            length: None,
            payload: payload_buf,
            crc: None,
        }));
    }

    crate::ser::to_buffer(frame_buf, msg)?;

    if frame_buf.len() < MIN_FRAME_LEN {
        // arguably dead code because of the invalid earlier
        return Ok(None);
    }
    let crc = frame_buf
        .get(HEADER_LEN + size..HEADER_LEN + size + CRC_LEN)
        .and_then(|slice| TryInto::<[u8; CRC_LEN]>::try_into(slice).ok())
        .map(u16::from_le_bytes);

    // won't panic because MIN_FRAME_LEN > HEADER_LEN
    BASE64_STANDARD.encode_string(&frame_buf[HEADER_LEN..HEADER_LEN + size], payload_buf);

    Ok(Some(CommonJson {
        preamble: Some(PREAMBLE),
        sender: Some(msg.sender_id().unwrap_or_default()),
        msg_name: msg.message_name(),
        msg_type: msg.message_type(),
        length: size.try_into().ok(),
        payload: payload_buf,
        crc,
    }))
}
