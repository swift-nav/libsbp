//! Encode/decode SBP messages as JSON.

mod de;
mod ser;

use std::collections::HashMap;
use std::io;

use serde::{Deserialize, Serialize};
use serde_json::{ser::Formatter, Value};

pub use serde_json::ser::CompactFormatter;

use crate::{messages::invalid::Invalid, HandleParseError, Sbp};
#[cfg(feature = "async")]
pub use de::stream_messages;
pub use de::{iter_json2json_messages, iter_messages, iter_messages_from_fields};

pub use ser::{to_vec, to_writer, Json2JsonEncoder, JsonEncoder};

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum JsonInput {
    Input(CommonJsonInput),
    Nested { data: CommonJsonInput },
}

impl JsonInput {
    fn into_inner(self) -> Result<MaybeValidJsonInput, JsonError> {
        let CommonJsonInput {
            msg_type,
            msg_name,
            payload,
            sender,
        } = match self {
            JsonInput::Input(data) | JsonInput::Nested { data } => data,
        };
        match (msg_type, sender) {
            (Some(msg_type), Some(sender)) if !msg_name.eq_ignore_ascii_case("INVALID") => {
                Ok(MaybeValidJsonInput {
                    msg_type,
                    payload,
                    sender,
                })
            }
            _ => Err(JsonError::InvalidMsg(InvalidMsgInput { payload })),
        }
    }
}

#[derive(Debug, Deserialize)]
struct CommonJsonInput {
    #[serde(default)]
    msg_name: String,
    #[serde(default)]
    msg_type: Option<u16>,
    payload: String,
    #[serde(default)]
    sender: Option<u16>,
}

#[derive(Debug, Deserialize)]
pub struct MaybeValidJsonInput {
    msg_type: u16,
    payload: String,
    sender: u16,
}

#[derive(Debug, Deserialize)]
pub struct InvalidMsgInput {
    payload: String,
}

/// 'Compressed' Sbp JSON messages. Unlike normal SBP json these messages
/// just contain the base64 payload of the message, not the individual fields.
#[derive(Debug, Deserialize)]
pub struct Json2JsonInput {
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

#[derive(Debug, Serialize)]
struct Json2JsonOutput<'a, M> {
    data: JsonOutput<'a, M>,

    #[serde(flatten)]
    other: HashMap<String, Value>,
}

#[derive(Debug, Serialize, Deserialize)]
struct CommonJson<'a> {
    #[serde(default, skip_serializing_if = "Option::is_none")]
    crc: Option<u16>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    length: Option<u8>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    msg_type: Option<u16>,
    msg_name: &'a str,
    payload: &'a str,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    preamble: Option<u8>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    sender: Option<u16>,
}

#[derive(Debug, Serialize)]
struct JsonOutput<'a, M> {
    #[serde(flatten)]
    common: Option<CommonJson<'a>>,

    #[serde(flatten)]
    msg: &'a M,
}

/// Provide Haskell style formatting. Output should be similar to:
/// <https://hackage.haskell.org/package/base-4.8.2.0/docs/Numeric.html#v:showFloat>
#[derive(Debug, Clone)]
pub struct HaskellishFloatFormatter;

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
    fn write_f32<W>(&mut self, writer: &mut W, value: f32) -> io::Result<()>
    where
        W: io::Write + ?Sized,
    {
        show_float!(writer, value)
    }

    #[inline]
    fn write_f64<W>(&mut self, writer: &mut W, value: f64) -> io::Result<()>
    where
        W: io::Write + ?Sized,
    {
        show_float!(writer, value)
    }
}

/// All possible error types when encoding/decoding a stream of json messages.
#[derive(Debug)]
pub enum JsonError {
    SbpMsgParseError(crate::messages::SbpMsgParseError),
    CrcError(crate::de::CrcError),
    WriteFrameError(crate::ser::WriteFrameError),
    IoError(io::Error),
    Base64Error(base64::DecodeError),
    InvalidMsg(InvalidMsgInput),
    SerdeJsonError(serde_json::Error),
}

impl HandleParseError<Sbp> for JsonError {
    fn handle_parse_error(self) -> Sbp {
        match self {
            Self::SbpMsgParseError(e) => Invalid::from(e).into(),
            Self::CrcError(e) => Invalid::from(e).into(),
            Self::InvalidMsg(InvalidMsgInput { payload }) => {
                // todo remove allocation here
                let mut invalid_frame = Vec::<u8>::new();
                base64::decode_config_buf(&payload, base64::STANDARD, &mut invalid_frame)
                    .expect("unable to recover from base64 error");
                Invalid {
                    msg_id: None,
                    sender_id: None,
                    crc: None,
                    invalid_frame,
                }
                .into()
            }
            Self::WriteFrameError(e) => {
                panic!("Unable to recover from WriteFrameError {}", e)
            }
            Self::IoError(e) => {
                panic!("Unable to recover from IoError {}", e)
            }

            Self::Base64Error(e) => {
                panic!("Unable to recover from Base64 decoding error {}", e)
            }

            Self::SerdeJsonError(e) => {
                // We may need to handle this error path if we want to recover
                // from errors with Json2Json
                panic!("Unable to recover from SerdeJsonError {}", e)
            }
        }
    }
}

impl HandleParseError<Json2JsonInput> for JsonError {
    fn handle_parse_error(self) -> Json2JsonInput {
        unimplemented!("We do not yet support falling back to invalid messages for Json2Json");
    }
}

impl std::fmt::Display for JsonError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            JsonError::SbpMsgParseError(e) => e.fmt(f),
            JsonError::CrcError(e) => e.fmt(f),
            JsonError::WriteFrameError(e) => e.fmt(f),
            JsonError::IoError(e) => e.fmt(f),
            JsonError::Base64Error(e) => e.fmt(f),
            JsonError::SerdeJsonError(e) => e.fmt(f),
            JsonError::InvalidMsg(_e) => write!(f, "Received an json value with type INVALID",),
        }
    }
}

impl std::error::Error for JsonError {}

impl From<crate::messages::SbpMsgParseError> for JsonError {
    fn from(e: crate::messages::SbpMsgParseError) -> Self {
        JsonError::SbpMsgParseError(e)
    }
}

impl From<crate::de::CrcError> for JsonError {
    fn from(e: crate::de::CrcError) -> Self {
        JsonError::CrcError(e)
    }
}

impl From<crate::ser::WriteFrameError> for JsonError {
    fn from(e: crate::ser::WriteFrameError) -> Self {
        JsonError::WriteFrameError(e)
    }
}

impl From<io::Error> for JsonError {
    fn from(e: io::Error) -> Self {
        JsonError::IoError(e)
    }
}

impl From<base64::DecodeError> for JsonError {
    fn from(e: base64::DecodeError) -> Self {
        JsonError::Base64Error(e)
    }
}

impl From<serde_json::Error> for JsonError {
    fn from(e: serde_json::Error) -> Self {
        JsonError::SerdeJsonError(e)
    }
}
