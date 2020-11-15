//! Native implementation of decoding of SBP (Swift Binary Protocol) used by products
//! made by Swift Navigation. For language agnostic description of the protocol please
//! see the protocol specification documentation at https://github.com/swift-nav/libsbp/tree/master/docs

pub mod codec;
pub mod messages;
pub(crate) mod parser;
pub mod serialize;

use std::{
    convert::{From, Into},
    fmt, result,
};

use futures::{executor::block_on_stream, io::AllowStdIo, stream::Stream};
#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Deserializer, Serialize, Serializer};
use tokio::io::AsyncRead;
use tokio_util::compat::FuturesAsyncReadCompatExt;

use crate::{
    codec::sbp::SbpCodec,
    messages::{SBPMessage, SBP},
    serialize::SbpSerialize,
};

pub const SBP_MAX_PAYLOAD_SIZE: usize = 255;
pub const MSG_HEADER_LEN: usize = 1 /*preamble*/ + 2 /*msg_type*/ + 2 /*sender_id*/ + 1 /*len*/;
pub const MSG_CRC_LEN: usize = 2;

pub fn stream_messages<R: AsyncRead>(input: R) -> impl Stream<Item = Result<SBP>> {
    SbpCodec::decode_reader(input)
}

pub fn iter_messages<R: std::io::Read>(input: R) -> impl Iterator<Item = Result<SBP>> {
    let input = AllowStdIo::new(input);
    let stream = stream_messages(input.compat());
    block_on_stream(stream).into_iter()
}

#[cfg(feature = "json")]
pub mod json {
    use futures::{executor::block_on_stream, io::AllowStdIo, Stream};
    use tokio::io::AsyncRead;
    use tokio_util::compat::FuturesAsyncReadCompatExt;

    use crate::{codec::json::JsonDecoder, messages::SBP, Result};

    pub fn stream_messages<R: AsyncRead + Unpin>(
        src: R,
    ) -> impl Stream<Item = Result<SBP>> + Unpin {
        JsonDecoder::decode_reader(src)
    }

    pub fn iter_messages<R: std::io::Read>(input: R) -> impl Iterator<Item = Result<SBP>> {
        let input = AllowStdIo::new(input);
        let stream = stream_messages(input.compat());
        block_on_stream(stream).into_iter()
    }
}

#[derive(Debug, Clone)]
pub struct SbpString(Vec<u8>);

impl SbpString {
    pub fn as_bytes(&self) -> &[u8] {
        &self.0
    }
    pub fn to_string(&self) -> String {
        String::from_utf8_lossy(&self.0).into()
    }
}

#[cfg(feature = "sbp_serde")]
impl Serialize for SbpString {
    fn serialize<S>(&self, serializer: S) -> result::Result<S::Ok, S::Error>
    where
        S: Serializer,
    {
        let s: String = self.clone().into();
        serializer.serialize_str(&s)
    }
}

#[cfg(feature = "sbp_serde")]
impl<'de> Deserialize<'de> for SbpString {
    fn deserialize<D>(deserializer: D) -> result::Result<Self, D::Error>
    where
        D: Deserializer<'de>,
    {
        Deserialize::deserialize(deserializer).map(|s: String| SbpString::from(s))
    }
}

impl From<String> for SbpString {
    fn from(s: String) -> SbpString {
        SbpString(s.as_bytes().to_vec())
    }
}

impl Into<String> for SbpString {
    fn into(self) -> String {
        self.to_string()
    }
}

impl Into<String> for &SbpString {
    fn into(self) -> String {
        self.to_string()
    }
}

impl Into<Vec<u8>> for SbpString {
    fn into(self) -> Vec<u8> {
        self.0
    }
}

impl fmt::Display for SbpString {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "SbpString({})", Into::<String>::into(self.clone()))
    }
}

pub type Result<T> = result::Result<T, Error>;

#[derive(Debug, thiserror::Error)]
pub enum Error {
    #[error("An error occured during parsing. Error kind: {kind:?}")]
    ParseError { kind: nom::error::ErrorKind },

    #[cfg(feature = "json")]
    #[error("Failed to parse sbp message from json: {details}")]
    JsonParseError { details: String },

    #[error(
        "CRC validation failed: sender_id={sender_id:#02X?} msg_type={msg_type:#02X?} crc={crc:#02X?}"
    )]
    CrcError {
        msg_type: u16,
        sender_id: u16,
        crc: u16,
    },

    #[error(transparent)]
    FramerError(#[from] FramerError),

    #[cfg(feature = "json")]
    #[error(transparent)]
    SerdeJsonError(#[from] serde_json::error::Error),

    #[error(transparent)]
    IoError(#[from] std::io::Error),
}

pub(crate) fn write_frame<M: SBPMessage>(
    msg: &M,
    frame: &mut Vec<u8>,
) -> std::result::Result<(), FramerError> {
    let len = msg.sbp_size();
    if len > SBP_MAX_PAYLOAD_SIZE {
        return Err(crate::FramerError::TooLarge);
    }
    let sender_id = msg.get_sender_id().ok_or(FramerError::NoSenderId)?;

    frame.reserve(len);

    (0x55 as u8).append_to_sbp_buffer(frame);
    msg.get_message_type().append_to_sbp_buffer(frame);
    sender_id.append_to_sbp_buffer(frame);
    (len as u8).append_to_sbp_buffer(frame);
    msg.append_to_sbp_buffer(frame);
    crc16::State::<crc16::XMODEM>::calculate(&frame[1..]).append_to_sbp_buffer(frame);

    Ok(())
}

#[derive(Debug, thiserror::Error)]
pub enum FramerError {
    #[error("Message is too large to fit into an SBP frame")]
    TooLarge,

    #[error("No sender ID is present in the message bring framed")]
    NoSenderId,
}

#[cfg(test)]
mod tests {
    #[test]
    fn test_making_frame() {
        use crate::messages::SBPMessage;

        let msg = crate::messages::system::MsgStartup {
            sender_id: Some(250),
            cause: 1,
            startup_type: 45,
            reserved: 0,
        };

        let frame = msg.to_frame().unwrap();

        let expected_frame = b"\x55\x00\xFF\xFA\x00\x04\x01\x2D\x00\x00\xBC\x73";

        assert_eq!(frame, expected_frame);
    }

    #[test]
    fn test_sbp_string() {
        use crate::SbpString;

        let sbp_str = SbpString(b"1234".to_vec());
        let s = sbp_str.to_string();

        assert_eq!("1234", s);

        let sbp_str = SbpString(b"1234\xFF".to_vec());
        let s = sbp_str.to_string();

        assert_eq!("1234\u{FFFD}", s);
    }
}
