pub mod sbp {
    use bytes::{Buf, BufMut, BytesMut};
    use tokio::io::{AsyncRead, AsyncWrite};
    use tokio_util::codec::{Decoder, Encoder, FramedRead, FramedWrite};

    use crate::{
        messages::{SBPMessage, SBP},
        parser::{parse_sbp, ParseResult},
        Result,
    };

    pub(crate) struct SbpCodec {
        frame: Vec<u8>,
    }

    impl SbpCodec {
        pub fn decode_reader<R: AsyncRead>(input: R) -> FramedRead<R, SbpCodec> {
            FramedRead::new(input, SbpCodec { frame: Vec::new() })
        }

        pub fn encode_writer<W: AsyncWrite>(writer: W) -> FramedWrite<W, SbpCodec> {
            FramedWrite::new(writer, SbpCodec { frame: Vec::new() })
        }
    }

    impl Decoder for SbpCodec {
        type Item = SBP;
        type Error = crate::Error;

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
                    src.reserve(crate::MSG_HEADER_LEN + crate::SBP_MAX_PAYLOAD_SIZE);
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

    impl Encoder<SBP> for SbpCodec {
        type Error = crate::Error;

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
pub mod json {
    use std::collections::HashMap;

    use bytes::{Buf, BufMut, BytesMut};
    use futures::StreamExt;
    use serde::{de::DeserializeOwned, Deserialize, Serialize};
    use serde_json::{Deserializer, Value};
    use tokio::io::{AsyncRead, AsyncWrite};
    use tokio_util::codec::{Decoder, Encoder, FramedRead, FramedWrite};

    use crate::{
        messages::{SBPMessage, SBP},
        serialize::SbpSerialize,
        Result,
    };

    pub async fn json2sbp<R, W>(input: R, output: W) -> Result<()>
    where
        R: AsyncRead + Unpin,
        W: AsyncWrite,
    {
        let source = JsonDecoder::decode_reader(input);
        let sink = super::sbp::SbpCodec::encode_writer(output);
        source.forward(sink).await
    }

    pub async fn json2json<R, W>(input: R, output: W) -> Result<()>
    where
        R: AsyncRead + Unpin,
        W: AsyncWrite,
    {
        let source = Json2JsonDecoder::decode_reader(input);
        let sink = JsonEncoder::encode_writer(output);
        source.forward(sink).await
    }

    pub async fn sbp2json<R, W>(input: R, output: W) -> Result<()>
    where
        R: AsyncRead,
        W: AsyncWrite,
    {
        let source = super::sbp::SbpCodec::decode_reader(input);
        let sink = JsonEncoder::encode_writer(output);
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
                .map_err(|err| crate::Error::JsonParseError {
                    details: format!("Invalid base64 payload: {}", err),
                })?;
            let mut payload = self.payload_buf.as_slice();

            SBP::parse(data.msg_type, data.sender, &mut payload)
        }
    }

    impl Decoder for JsonDecoder {
        type Item = SBP;
        type Error = crate::Error;

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
        type Error = crate::Error;

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

    struct JsonEncoder {
        payload_buf: String,
        frame_buf: Vec<u8>,
    }

    impl JsonEncoder {
        pub fn encode_writer<W: AsyncWrite>(sink: W) -> FramedWrite<W, JsonEncoder> {
            const BASE64_SBP_MAX_PAYLOAD_SIZE: usize = crate::SBP_MAX_PAYLOAD_SIZE / 3 * 4 + 4;

            FramedWrite::new(
                sink,
                Self {
                    frame_buf: Vec::with_capacity(crate::SBP_MAX_PAYLOAD_SIZE),
                    payload_buf: String::with_capacity(BASE64_SBP_MAX_PAYLOAD_SIZE),
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

    impl Encoder<SBP> for JsonEncoder {
        type Error = crate::Error;

        fn encode(&mut self, msg: SBP, dst: &mut BytesMut) -> Result<()> {
            let common = self.get_common_fields(&msg)?;
            let output = JsonOutput { common, msg };

            let mut writer = dst.writer();
            serde_json::to_writer(&mut writer, &output)?;
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

    impl Encoder<Json2JsonInput> for JsonEncoder {
        type Error = crate::Error;

        fn encode(&mut self, input: Json2JsonInput, dst: &mut BytesMut) -> Result<()> {
            let payload =
                base64::decode(input.data.payload).map_err(|err| crate::Error::JsonParseError {
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

            let mut writer = dst.writer();
            serde_json::to_writer(&mut writer, &output)?;
            dst.put_slice(b"\n");

            Ok(())
        }
    }
}
