use std::io;

use bytes::{Buf, BytesMut};
use dencode::{Decoder, FramedRead};
use serde::de::DeserializeOwned;
use serde_json::Deserializer;

use crate::{
    de::Frame,
    json::{Json2JsonInput, JsonError, JsonInput},
    messages::Sbp,
    BUFLEN,
};

/// Deserialize the IO stream into an iterator of messages.
pub fn iter_messages<R: io::Read>(input: R) -> impl Iterator<Item = Result<Sbp, JsonError>> {
    JsonDecoder::framed(input)
}

/// Deserialize the IO stream into an iterator of [Json2JsonInput] messages.
pub fn iter_json2json_messages<R: io::Read>(
    input: R,
) -> impl Iterator<Item = Result<Json2JsonInput, JsonError>> {
    Json2JsonDecoder::framed(input)
}

/// Deserialize the async IO stream into an stream of messages.
#[cfg(feature = "async")]
pub fn stream_messages<R: futures::AsyncRead + Unpin>(
    input: R,
) -> impl futures::Stream<Item = Result<Sbp, JsonError>> {
    JsonDecoder::framed(input)
}

#[derive(Debug, Default)]
struct JsonDecoder {
    payload_buf: Vec<u8>,
}

impl JsonDecoder {
    fn new() -> Self {
        JsonDecoder {
            payload_buf: Vec::with_capacity(BUFLEN),
        }
    }

    fn framed<R>(input: R) -> FramedRead<R, Self> {
        FramedRead::new(input, Self::new())
    }

    fn parse_json(&mut self, input: JsonInput) -> Result<Sbp, JsonError> {
        let data = input.into_inner();
        self.payload_buf.clear();
        base64::decode_config_buf(data.payload, base64::STANDARD, &mut self.payload_buf)?;
        let msg = Sbp::from_frame(Frame {
            msg_type: data.msg_type,
            sender_id: data.sender,
            payload: BytesMut::from(&self.payload_buf[..]),
        })?;
        Ok(msg)
    }
}

impl Decoder for JsonDecoder {
    type Item = Sbp;
    type Error = JsonError;

    fn decode(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>, Self::Error> {
        let value = match decode_one::<JsonInput>(src)? {
            Some(v) => v,
            None => return Ok(None),
        };
        self.parse_json(value).map(Option::Some)
    }
}

#[derive(Debug)]
struct Json2JsonDecoder;

impl Json2JsonDecoder {
    fn framed<R>(input: R) -> FramedRead<R, Self> {
        FramedRead::new(input, Self)
    }
}

impl Decoder for Json2JsonDecoder {
    type Item = Json2JsonInput;
    type Error = JsonError;

    fn decode(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>, Self::Error> {
        decode_one::<Json2JsonInput>(src).map_err(Into::into)
    }
}

fn decode_one<T>(buf: &mut BytesMut) -> Result<Option<T>, serde_json::Error>
where
    T: DeserializeOwned,
{
    let mut de = Deserializer::from_slice(&buf).into_iter::<T>();
    let value = de.next();
    let bytes_read = de.byte_offset();
    buf.advance(bytes_read);
    match value.transpose() {
        Ok(v) => Ok(v),
        Err(e) if e.is_eof() => Ok(None),
        Err(e) => Err(e),
    }
}
