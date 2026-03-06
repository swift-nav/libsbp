use std::io;

use base64::{Engine, prelude::BASE64_STANDARD};
use bytes::{Buf, BytesMut};
use dencode::{Decoder, FramedRead};
use serde::de::DeserializeOwned;
use serde_json::Deserializer;

use crate::{
    BUFLEN,
    json::{Json2JsonInput, JsonError, JsonInput},
    messages::Sbp,
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
    incomplete_buf_len: Option<usize>,
}

impl JsonDecoder {
    fn new() -> Self {
        JsonDecoder {
            payload_buf: Vec::with_capacity(BUFLEN),
            incomplete_buf_len: None,
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
        let value = match decode_one::<JsonInput>(&mut self.incomplete_buf_len, src)? {
            Some(v) => v,
            None => return Ok(None),
        };
        self.parse_json(value).map(Some)
    }
}

#[derive(Debug)]
struct Json2JsonDecoder {
    incomplete_buf_len: Option<usize>,
}

impl Json2JsonDecoder {
    fn framed<R>(input: R) -> FramedRead<R, Self> {
        FramedRead::new(
            input,
            Self {
                incomplete_buf_len: None,
            },
        )
    }
}

impl Decoder for Json2JsonDecoder {
    type Item = Json2JsonInput;
    type Error = JsonError;

    fn decode(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>, Self::Error> {
        decode_one::<Json2JsonInput>(&mut self.incomplete_buf_len, src).map_err(Into::into)
    }
}

fn decode_one<T>(
    incomplete_buf_len: &mut Option<usize>,
    buf: &mut BytesMut,
) -> Result<Option<T>, serde_json::Error>
where
    T: DeserializeOwned,
{
    let mut de = Deserializer::from_slice(buf).into_iter::<T>();
    let value = de.next();
    let bytes_read = de.byte_offset();
    match value.transpose() {
        Ok(v) => {
            buf.advance(bytes_read);
            *incomplete_buf_len = None;
            Ok(v)
        }
        // is_eof() means serde hit the end of the buffer slice mid-parse, i.e.
        // the buffer contains an incomplete JSON object (not a pipe/stream EOF).
        // Return Ok(None) so that FramedRead will read more data and retry.
        // Only return an error if the buffer hasn't grown since the last
        // incomplete parse, meaning no new data arrived.
        Err(e) if e.is_eof() => match *incomplete_buf_len {
            Some(prev_len) if prev_len == buf.len() => {
                buf.advance(buf.len());
                Err(e)
            }
            _ => {
                *incomplete_buf_len = Some(buf.len());
                Ok(None)
            }
        },
        // For semantic errors, we need to dump the invalid JSON object
        Err(e) if e.is_data() => {
            buf.advance(bytes_read);
            let mut de = Deserializer::from_slice(buf).into_iter::<serde_json::Value>();
            let _ = de.next();
            let bytes_read = de.byte_offset();
            buf.advance(bytes_read);
            Err(e)
        }
        // For syntax errors we dump the whole buffer so the stream
        // will terminate.
        Err(e) if e.is_syntax() => {
            buf.advance(buf.len());
            Err(e)
        }
        Err(e) => Err(e),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_decode_one_preserves_partial_json_on_eof() {
        let payload = "A".repeat(5000);
        let full_json = format!(r#"{{"msg_type":1534,"sender":0,"payload":"{}"}}"#, payload);
        let partial = &full_json.as_bytes()[..4096];
        let mut buf = BytesMut::from(partial);
        let mut incomplete_buf_len: Option<usize> = None;

        let result = decode_one::<serde_json::Value>(&mut incomplete_buf_len, &mut buf);

        assert!(
            result.unwrap().is_none(),
            "should return Ok(None) to request more data"
        );
        assert_eq!(incomplete_buf_len, Some(4096));
        assert_eq!(
            buf.len(),
            partial.len(),
            "partial JSON must be preserved in buffer, but {} bytes were discarded",
            partial.len() - buf.len()
        );
    }

    /// Simulates the actual bug: partial JSON requires multiple reads to
    /// complete, and incomplete_buf_len must allow retries as long as the buffer grows.
    #[test]
    fn test_decode_one_multiple_partial_reads() {
        let payload = "C".repeat(5000);
        let full_json = format!(r#"{{"msg_type":1534,"sender":42,"payload":"{}"}}"#, payload);
        let full_bytes = full_json.as_bytes();
        let mut buf = BytesMut::from(&full_bytes[..1000]);
        let mut incomplete_buf_len: Option<usize> = None;

        // First call: 1000 bytes, partial → Ok(None)
        let result = decode_one::<serde_json::Value>(&mut incomplete_buf_len, &mut buf);
        assert!(result.unwrap().is_none());
        assert_eq!(incomplete_buf_len, Some(1000));

        // Simulate read of 2000 more bytes (still not enough)
        buf.extend_from_slice(&full_bytes[1000..3000]);

        // Second call: 3000 bytes, still partial → Ok(None) (not Err!)
        let result = decode_one::<serde_json::Value>(&mut incomplete_buf_len, &mut buf);
        assert!(result.unwrap().is_none(), "should retry when buffer grew");
        assert_eq!(incomplete_buf_len, Some(3000));

        // Simulate read of remaining data
        buf.extend_from_slice(&full_bytes[3000..]);

        // Third call: complete JSON → Ok(Some)
        let result = decode_one::<serde_json::Value>(&mut incomplete_buf_len, &mut buf);
        let val = result.unwrap().unwrap();
        assert_eq!(val["msg_type"], 1534);
        assert!(incomplete_buf_len.is_none());
    }

    /// When the buffer hasn't grown between EOF attempts (true end of stream),
    /// the error should be returned.
    #[test]
    fn test_decode_one_returns_error_on_stale_eof() {
        let partial = br#"{"msg_type":1534,"sender"#;
        let mut buf = BytesMut::from(&partial[..]);
        let mut incomplete_buf_len: Option<usize> = None;

        // First EOF
        let result = decode_one::<serde_json::Value>(&mut incomplete_buf_len, &mut buf);
        assert!(result.unwrap().is_none());

        // Second EOF with same buffer length (no new data) → Err
        let result = decode_one::<serde_json::Value>(&mut incomplete_buf_len, &mut buf);
        assert!(
            result.is_err(),
            "should return error when buffer didn't grow"
        );
    }

    #[test]
    fn test_decode_one_advances_past_complete_json() {
        let input = br#"{"msg_type":1534,"sender":42}
{"msg_type":1535,"sender":99}
"#;
        let mut buf = BytesMut::from(&input[..]);
        let mut incomplete_buf_len: Option<usize> = None;

        let result = decode_one::<serde_json::Value>(&mut incomplete_buf_len, &mut buf);
        let val = result.unwrap().unwrap();
        assert_eq!(val["msg_type"], 1534);

        let result = decode_one::<serde_json::Value>(&mut incomplete_buf_len, &mut buf);
        let val = result.unwrap().unwrap();
        assert_eq!(val["msg_type"], 1535);
    }
}
