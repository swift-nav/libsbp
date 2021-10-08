use std::{borrow::Borrow, io};

use bytes::{BufMut, BytesMut};
use dencode::{Encoder, FramedWrite, IterSinkExt};
use serde::Serialize;
use serde_json::{ser::Formatter, Serializer};

use super::{JsonError, JsonOutput};

use crate::{
    de::Frame,
    json::{CommonJson, HaskellishFloatFormatter, Json2JsonInput, Json2JsonOutput},
    messages::Sbp,
    SbpMessage, BUFLEN, CRC_LEN, HEADER_LEN, PREAMBLE,
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
    M: SbpMessage + Serialize,
{
    let output = JsonOutput {
        common: get_common_fields(payload_buf, frame_buf, msg)?,
        msg,
    };
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
        let payload = base64::decode(input.data.payload)?;
        let msg = Sbp::from_frame(Frame {
            msg_type: input.data.msg_type,
            sender_id: input.data.sender,
            payload: BytesMut::from(&payload[..]),
        })?;
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

fn get_common_fields<'a, M: SbpMessage>(
    payload_buf: &'a mut String,
    mut frame_buf: &'a mut BytesMut,
    msg: &M,
) -> Result<CommonJson<'a>, JsonError> {
    payload_buf.clear();
    frame_buf.clear();
    let size = msg.len();
    crate::ser::to_buffer(&mut frame_buf, msg)?;
    let crc = {
        let crc_b0 = frame_buf[HEADER_LEN + size..HEADER_LEN + size + CRC_LEN][0] as u16;
        let crc_b1 = frame_buf[HEADER_LEN + size..HEADER_LEN + size + CRC_LEN][1] as u16;
        (crc_b1 << 8) | crc_b0
    };
    base64::encode_config_buf(
        &frame_buf[HEADER_LEN..HEADER_LEN + size],
        base64::STANDARD,
        payload_buf,
    );
    Ok(CommonJson {
        preamble: PREAMBLE,
        sender: msg.sender_id().unwrap_or(0),
        msg_type: msg.message_type(),
        length: size as u8,
        payload: payload_buf,
        crc,
    })
}
