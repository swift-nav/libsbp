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

    /// payload here is actually the raw frame with the given
    /// crc, msg_id & sender_id, if any
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
        // note here we don't add the header and crc etc because the
        // invalid message holds the entire frame in
        // its payload
        WireFormat::len(self)
    }

    fn is_invalid(&self) -> bool {
        true
    }
}

impl WireFormat for Invalid {
    fn len(&self) -> usize {
        self.payload.len()
    }

    fn write<B: BufMut>(&self, buf: &mut B) {
        self.payload.write(buf)
    }

    /// In general it is better to construct invalid messages
    /// from thrown errors, not to directly parse to them
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
            raw_invalid_payload_bytes: msg_payload,
        }: SbpMsgParseError,
    ) -> Self {
        // payload here is the whole frame
        let mut payload =
            Vec::with_capacity(msg_payload.len() + crate::HEADER_LEN + crate::CRC_LEN);
        crate::PREAMBLE.write(&mut payload);
        msg_type.write(&mut payload);
        sender_id.write(&mut payload);
        (msg_payload.len() as u8).write(&mut payload);
        msg_payload.write(&mut payload);
        let crc =
            crc16::State::<crc16::XMODEM>::calculate(&payload.get(1..).expect("vec has capacity"));
        crc.write(&mut payload);

        Self {
            msg_id: Some(msg_type),
            sender_id: Some(sender_id),
            payload,
            crc: Some(crc),
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
            msg_id: msg_type,
            sender_id: sender_id,
            payload,
            crc: crc,
        }
    }
}
