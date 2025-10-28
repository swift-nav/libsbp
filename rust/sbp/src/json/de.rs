use std::io;

use base64::{prelude::BASE64_STANDARD, Engine};
use bytes::{Buf, BytesMut};
use dencode::{Decoder, FramedRead};
use serde::de::DeserializeOwned;
use serde_json::Deserializer;

use crate::{
    json::{Json2JsonInput, JsonError, JsonInput},
    messages::Sbp,
    BUFLEN,
};

/// Deserialize the IO stream into an iterator of messages.
pub fn iter_messages<R: io::Read>(input: R) -> impl Iterator<Item = Result<Sbp, JsonError>> {
    JsonDecoder::framed(input)
}

/// Deserialize the IO stream into an iterator of messages. Unlike [iter_messages], this function
/// will use the fields of the JSON message, rather than the base64 encoded payload.
pub fn iter_messages_from_fields<R: io::Read>(
    input: R,
) -> impl Iterator<Item = Result<Sbp, JsonError>> {
    Deserializer::from_reader(input)
        .into_iter()
        .map(|msg| msg.map_err(JsonError::SerdeJsonError))
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
    eof_seen: bool,
}

impl JsonDecoder {
    fn new() -> Self {
        JsonDecoder {
            payload_buf: Vec::with_capacity(BUFLEN),
            eof_seen: false,
        }
    }

    fn framed<R>(input: R) -> FramedRead<R, Self> {
        FramedRead::new(input, Self::new())
    }

    fn parse_json(&mut self, input: JsonInput) -> Result<Sbp, JsonError> {
        let data = input.into_inner()?;
        self.payload_buf.clear();

        BASE64_STANDARD.decode_vec(&data.payload, &mut self.payload_buf)?;

        Sbp::from_parts(
            data.msg_type,
            data.sender,
            BytesMut::from(&self.payload_buf[..]),
        )
        .map_err(|e| {
            eprintln!("unable to decode JsonInput {data:?}");
            e.into()
        })
    }
}

impl Decoder for JsonDecoder {
    type Item = Sbp;
    type Error = JsonError;

    fn decode(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>, Self::Error> {
        let value = match decode_one::<JsonInput>(&mut self.eof_seen, src)? {
            Some(v) => v,
            None => return Ok(None),
        };
        self.parse_json(value).map(Some)
    }
}

#[derive(Debug)]
struct Json2JsonDecoder {
    eof_seen: bool,
}

impl Json2JsonDecoder {
    fn framed<R>(input: R) -> FramedRead<R, Self> {
        FramedRead::new(input, Self { eof_seen: false })
    }
}

impl Decoder for Json2JsonDecoder {
    type Item = Json2JsonInput;
    type Error = JsonError;

    fn decode(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>, Self::Error> {
        decode_one::<Json2JsonInput>(&mut self.eof_seen, src).map_err(Into::into)
    }
}

fn decode_one<T>(eof_seen: &mut bool, buf: &mut BytesMut) -> Result<Option<T>, serde_json::Error>
where
    T: DeserializeOwned,
{
    let mut de = Deserializer::from_slice(buf).into_iter::<T>();
    let value = de.next();
    let bytes_read = de.byte_offset();
    buf.advance(bytes_read);
    match value.transpose() {
        Ok(v) => {
            *eof_seen = false;
            Ok(v)
        }
        // One EOF error is OK, if we fail to resolve it on a second read then we return an error.
        // (Note this will incorrectly fail if there is a JSON object that spans the underlying buffer of dencode,
        //  which is 8k, see https://github.com/swift-nav/dencode/blob/df889f926013085212af55d0e31d59fa71f16833/src/framed_read.rs#L10)
        Err(e) if e.is_eof() => {
            if *eof_seen {
                buf.advance(buf.len());
                Err(e)
            } else {
                *eof_seen = true;
                Ok(None)
            }
        }
        // For semantic errors, we need to dump the invalid JSON object
        Err(e) if e.is_data() => {
            let mut de = Deserializer::from_slice(buf).into_iter::<serde_json::Value>();
            let _ = de.next();
            let bytes_read = de.byte_offset();
            buf.advance(bytes_read);
            Err(e)
        }
        // For syntax (and EOF errors) we dump the whole buffer so the stream
        // will terminate.
        Err(e) if e.is_syntax() => {
            buf.advance(buf.len());
            Err(e)
        }
        Err(e) => Err(e),
    }
}
