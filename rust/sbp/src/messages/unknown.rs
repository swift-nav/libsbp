//! Unknown messages.

use bytes::{Buf, BufMut};

use crate::{wire_format::WireFormat, SbpMessage};

/// The message returned by the parser when the message type does not correspond to a known message.
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
#[derive(Debug, Eq, PartialEq, Clone)]
pub struct Unknown {
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
    /// Raw payload of the message.
    pub payload: Vec<u8>,
}

impl SbpMessage for Unknown {
    fn message_name(&self) -> &'static str {
        "UNKNOWN"
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

    fn is_invalid(&self) -> bool {
        false
    }
}

impl WireFormat for Unknown {
    fn len(&self) -> usize {
        self.payload.len()
    }

    fn write<B: BufMut>(&self, buf: &mut B) {
        self.payload.write(buf)
    }

    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        Unknown {
            msg_id: None,
            sender_id: None,
            payload: WireFormat::parse_unchecked(buf),
        }
    }
}
