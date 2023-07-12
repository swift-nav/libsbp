//! Unknown messages.

use bytes::{Buf, BufMut};

use crate::{wire_format::WireFormat, SbpMessage};

/// The message returned by the parser when the message type does not correspond to a known message.
///
/// The message should be well formed and must include a msg_id to be
/// considered valid. If it is missing these items, it should be instead be an invalid
/// message. This distinction is not enforced at compile-time nor by the type-system
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
#[derive(Debug, Eq, PartialEq, Clone)]
pub struct Unknown {
    /// The message id of the message.
    #[cfg_attr(feature = "serde", serde(default, skip_serializing))]
    pub msg_id: Option<u16>,
    /// The message sender_id.
    #[cfg_attr(feature = "serde", serde(default, skip_serializing, alias = "sender"))]
    pub sender_id: Option<u16>,
    /// Raw payload of the message.
    #[cfg_attr(feature = "serde", serde(default, skip_serializing))]
    pub payload: Vec<u8>,
}

impl SbpMessage for Unknown {
    fn message_name(&self) -> &'static str {
        "UNKNOWN"
    }

    fn message_type(&self) -> Option<u16> {
        self.msg_id
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
    fn is_valid(&self) -> bool {
        self.msg_id.is_some()
    }
    fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
        if self.is_valid() {
            Ok(self)
        } else {
            // warning this can cause loss of data because it casts a payload
            // to a frame. However, this branch should not be reached unless
            // you construct Unknown messages directly.
            Err(crate::messages::Invalid {
                msg_id: self.msg_id,
                sender_id: self.sender_id,
                invalid_frame: self.payload,
                crc: None,
            })
        }
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
