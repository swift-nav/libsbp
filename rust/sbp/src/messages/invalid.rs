//! Invalid messages, maybe don't have enough bytes are Crc Errors.

use bytes::{Buf, BufMut};

use crate::{de::CrcError, messages::SbpMsgParseError, wire_format::WireFormat, SbpMessage};

/// The message returned by the parser when the message type does not correspond to a known message.
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
#[derive(Debug, Eq, PartialEq, Clone)]
pub struct Invalid {
    /// The message id of the message.
    #[cfg_attr(
        feature = "serde",
        serde(default, skip_serializing_if = "Option::is_none")
    )]
    pub msg_id: Option<u16>,
    /// The message sender_id.
    #[cfg_attr(
        feature = "serde",
        serde(default, skip_serializing_if = "Option::is_none")
    )]
    pub sender_id: Option<u16>,

    /// The crc that was in the frame
    #[cfg_attr(
        feature = "serde",
        serde(default, skip_serializing_if = "Option::is_none")
    )]
    pub crc: Option<u16>,

    /// Raw payload of the message.
    pub payload: Vec<u8>,
}

impl SbpMessage for Invalid {
    fn message_name(&self) -> &'static str {
        "INVALID"
    }

    fn message_type(&self) -> u16 {
        self.msg_id.unwrap_or(0xffff)
    }

    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl WireFormat for Invalid {
    fn len(&self) -> usize {
        self.payload.len()
    }

    fn write<B: BufMut>(&self, buf: &mut B) {
        self.payload.write(buf)
    }

    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        Invalid {
            msg_id: None,
            sender_id: None,
            crc: None,
            payload: WireFormat::parse_unchecked(buf),
        }
    }
}

impl From<SbpMsgParseError> for Invalid {
    fn from(
        SbpMsgParseError {
            msg_type,
            sender_id,
            raw_invalid_payload_bytes: payload,
        }: SbpMsgParseError,
    ) -> Self {
        Self {
            msg_id: Some(msg_type),
            sender_id: Some(sender_id),
            payload,
            crc: None,
        }
    }
}

impl From<CrcError> for Invalid {
    fn from(
        CrcError {
            msg_type,
            sender_id,
            raw_frame_bytes: payload,
            crc,
        }: CrcError,
    ) -> Self {
        Self {
            msg_id: Some(msg_type),
            sender_id: Some(sender_id),
            payload,
            crc: Some(crc),
        }
    }
}
