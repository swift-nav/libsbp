#[cfg(feature = "json")]
pub use json::{json2json, json2sbp, sbp2json, CompactFormatter, HaskellishFloatFormatter};

pub(crate) mod sbp {
    use bytes::{Buf, BufMut, BytesMut};
    use futures::stream::Stream;
    use tokio::io::{AsyncRead, AsyncWrite};
    use tokio_util::codec::{Decoder, Encoder, FramedRead, FramedWrite};

    use crate::{
        messages::{SBPMessage, SBP},
        parser::{parse_sbp, ParseResult},
        Error, Result,
    };

    const MAX_FRAME_LENGTH: usize =
        crate::MSG_HEADER_LEN + crate::SBP_MAX_PAYLOAD_SIZE + crate::MSG_CRC_LEN;

    pub fn stream_messages<R: AsyncRead>(input: R) -> impl Stream<Item = Result<SBP>> {
        SbpDecoder::decode_reader(input)
    }

    pub struct SbpDecoder {}

    impl SbpDecoder {
        pub fn decode_reader<R: AsyncRead>(input: R) -> FramedRead<R, SbpDecoder> {
            FramedRead::new(input, SbpDecoder {})
        }
    }

    impl Decoder for SbpDecoder {
        type Item = SBP;
        type Error = Error;

        fn decode(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>> {
            match parse_sbp(&src) {
                ParseResult::Ok((bytes_read, msg)) => {
                    src.advance(bytes_read);
                    log::trace!("{:?}", msg);
                    Ok(Some(msg))
                }
                ParseResult::Err((bytes_read, err)) => {
                    src.advance(bytes_read);
                    log::warn!("{}", err);
                    Ok(None)
                }
                ParseResult::Incomplete => {
                    src.reserve(MAX_FRAME_LENGTH);
                    Ok(None)
                }
            }
        }

        fn decode_eof(&mut self, buf: &mut BytesMut) -> Result<Option<Self::Item>> {
            match self.decode(buf) {
                Ok(Some(frame)) => Ok(Some(frame)),
                _ => Ok(None),
            }
        }
    }

    pub struct SbpEncoder {
        frame: Vec<u8>,
    }

    impl SbpEncoder {
        pub fn encode_writer<W: AsyncWrite>(writer: W) -> FramedWrite<W, SbpEncoder> {
            FramedWrite::new(
                writer,
                SbpEncoder {
                    frame: Vec::with_capacity(MAX_FRAME_LENGTH),
                },
            )
        }
    }

    impl Encoder<SBP> for SbpEncoder {
        type Error = Error;

        fn encode(&mut self, msg: SBP, dst: &mut BytesMut) -> Result<()> {
            self.frame.clear();
            match msg.write_frame(&mut self.frame) {
                Ok(_) => dst.put_slice(self.frame.as_slice()),
                Err(err) => log::error!("Error converting sbp message to frame: {}", err),
            }
            Ok(())
        }
    }
}

#[cfg(feature = "json")]
pub(crate) mod json {
    use std::collections::HashMap;

    use bytes::{Buf, BufMut, BytesMut};
    use futures::StreamExt;
    use serde::{de::DeserializeOwned, Deserialize, Serialize};
    use serde_json::{ser::Formatter, Deserializer, Serializer, Value};
    use tokio::io::{AsyncRead, AsyncWrite};
    use tokio_util::codec::{Decoder, Encoder, FramedRead, FramedWrite};

    pub use serde_json::ser::CompactFormatter;

    use crate::{
        messages::{SBPMessage, SBP},
        serialize::SbpSerialize,
        Error, Result,
    };

    pub async fn json2sbp<R, W>(input: R, output: W) -> Result<()>
    where
        R: AsyncRead + Unpin,
        W: AsyncWrite,
    {
        let source = JsonDecoder::decode_reader(input);
        let sink = super::sbp::SbpEncoder::encode_writer(output);
        source.forward(sink).await
    }

    pub async fn json2json<R, W, F>(input: R, output: W, formatter: F) -> Result<()>
    where
        R: AsyncRead + Unpin,
        W: AsyncWrite,
        F: Formatter + Clone,
    {
        let source = Json2JsonDecoder::decode_reader(input);
        let sink = JsonEncoder::encode_writer(output, formatter);
        source.forward(sink).await
    }

    pub async fn sbp2json<R, W, F>(input: R, output: W, formatter: F) -> Result<()>
    where
        R: AsyncRead,
        W: AsyncWrite,
        F: Formatter + Clone,
    {
        let source = super::sbp::SbpDecoder::decode_reader(input);
        let sink = JsonEncoder::encode_writer(output, formatter);
        source.forward(sink).await
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
        pub fn decode_reader<R: AsyncRead>(input: R) -> FramedRead<R, JsonDecoder> {
            FramedRead::new(
                input,
                JsonDecoder {
                    payload_buf: Vec::with_capacity(crate::SBP_MAX_PAYLOAD_SIZE),
                },
            )
        }

        fn parse_json(&mut self, input: JsonInput) -> Result<SBP> {
            let data = input.into_inner();

            self.payload_buf.clear();
            base64::decode_config_buf(data.payload, base64::STANDARD, &mut self.payload_buf)
                .map_err(|err| Error::JsonParseError {
                    details: format!("Invalid base64 payload: {}", err),
                })?;
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
    struct Json2JsonInput {
        data: OwnedCommonJson,

        #[serde(flatten)]
        other: HashMap<String, Value>,
    }

    #[derive(Debug, Serialize, Deserialize)]
    struct OwnedCommonJson {
        crc: u16,
        length: u8,
        msg_type: u16,
        payload: String,
        preamble: u8,
        sender: u16,
    }

    struct Json2JsonDecoder {}

    impl Json2JsonDecoder {
        pub fn decode_reader<R: AsyncRead>(input: R) -> FramedRead<R, Json2JsonDecoder> {
            FramedRead::new(input, Json2JsonDecoder {})
        }
    }

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

    struct JsonEncoder<F> {
        payload_buf: String,
        frame_buf: Vec<u8>,
        formatter: F,
    }

    impl<F: Formatter + Clone> JsonEncoder<F> {
        pub fn encode_writer<W: AsyncWrite>(
            sink: W,
            formatter: F,
        ) -> FramedWrite<W, JsonEncoder<F>> {
            const BASE64_SBP_MAX_PAYLOAD_SIZE: usize = crate::SBP_MAX_PAYLOAD_SIZE / 3 * 4 + 4;

            FramedWrite::new(
                sink,
                JsonEncoder {
                    frame_buf: Vec::with_capacity(crate::SBP_MAX_PAYLOAD_SIZE),
                    payload_buf: String::with_capacity(BASE64_SBP_MAX_PAYLOAD_SIZE),
                    formatter,
                },
            )
        }

        fn get_common_fields(&mut self, msg: &SBP) -> Result<CommonJson> {
            self.payload_buf.clear();
            self.frame_buf.clear();

            let length = msg.sbp_size();

            msg.write_frame(&mut self.frame_buf)?;

            let crc = {
                let crc_b0 = self.frame_buf[crate::MSG_HEADER_LEN + length
                    ..crate::MSG_HEADER_LEN + length + crate::MSG_CRC_LEN][0]
                    as u16;
                let crc_b1 = self.frame_buf[crate::MSG_HEADER_LEN + length
                    ..crate::MSG_HEADER_LEN + length + crate::MSG_CRC_LEN][1]
                    as u16;
                (crc_b1 << 8) | crc_b0
            };

            base64::encode_config_buf(
                &self.frame_buf[crate::MSG_HEADER_LEN..crate::MSG_HEADER_LEN + length],
                base64::STANDARD,
                &mut self.payload_buf,
            );

            Ok(CommonJson {
                preamble: 0x55,
                sender: msg.get_sender_id().unwrap_or(0),
                msg_type: msg.get_message_type(),
                length: length as u8,
                payload: &self.payload_buf,
                crc,
            })
        }
    }

    #[derive(Debug, Serialize)]
    struct JsonOutput<'a> {
        #[serde(flatten)]
        common: CommonJson<'a>,

        #[serde(flatten)]
        msg: SBP,
    }

    impl<F: Formatter + Clone> Encoder<SBP> for JsonEncoder<F> {
        type Error = Error;

        fn encode(&mut self, msg: SBP, dst: &mut BytesMut) -> Result<()> {
            let formatter = self.formatter.clone();
            let common = self.get_common_fields(&msg)?;
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

    impl<F: Formatter + Clone> Encoder<Json2JsonInput> for JsonEncoder<F> {
        type Error = Error;

        fn encode(&mut self, input: Json2JsonInput, dst: &mut BytesMut) -> Result<()> {
            let formatter = self.formatter.clone();

            let payload =
                base64::decode(input.data.payload).map_err(|err| Error::JsonParseError {
                    details: format!("Invalid base64 payload: {}", err),
                })?;

            let msg = {
                let mut payload = payload.as_slice();
                SBP::parse(input.data.msg_type, input.data.sender, &mut payload)?
            };

            let output = Json2JsonOutput {
                data: JsonOutput {
                    common: self.get_common_fields(&msg)?,
                    msg,
                },
                other: input.other,
            };

            let mut ser = Serializer::with_formatter(dst.writer(), formatter);
            output.serialize(&mut ser)?;
            dst.put_slice(b"\n");

            Ok(())
        }
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
}
