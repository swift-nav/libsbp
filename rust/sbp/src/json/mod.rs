//! Encode/decode SBP messages as JSON.

mod de;
mod ser;

use std::collections::HashMap;
use std::io;

use serde::{Deserialize, Serialize};
use serde_json::{ser::Formatter, Value};

pub use serde_json::ser::CompactFormatter;

#[cfg(feature = "async")]
pub use de::stream_messages;
pub use de::{iter_json2json_messages, iter_messages};

pub use ser::{to_vec, to_writer, Json2JsonEncoder, JsonEncoder};

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum JsonInput {
    Input(CommonJsonInput),
    Nested { data: CommonJsonInput },
}

impl JsonInput {
    fn into_inner(self) -> CommonJsonInput {
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
    crc: u16,
    length: u8,
    msg_type: u16,
    payload: &'a str,
    preamble: u8,
    sender: u16,
}

#[derive(Debug, Serialize)]
struct JsonOutput<'a, M> {
    #[serde(flatten)]
    common: CommonJson<'a>,

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
    PayloadParseError(crate::wire_format::PayloadParseError),
    CrcError(crate::de::CrcError),
    WriteFrameError(crate::ser::WriteFrameError),
    IoError(io::Error),
    Base64Error(base64::DecodeError),
    SerdeJsonError(serde_json::Error),
}

impl std::fmt::Display for JsonError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            JsonError::PayloadParseError(e) => e.fmt(f),
            JsonError::CrcError(e) => e.fmt(f),
            JsonError::WriteFrameError(e) => e.fmt(f),
            JsonError::IoError(e) => e.fmt(f),
            JsonError::Base64Error(e) => e.fmt(f),
            JsonError::SerdeJsonError(e) => e.fmt(f),
        }
    }
}

impl std::error::Error for JsonError {}

impl From<crate::wire_format::PayloadParseError> for JsonError {
    fn from(e: crate::wire_format::PayloadParseError) -> Self {
        JsonError::PayloadParseError(e)
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
