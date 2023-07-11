//! Invalid messages. This message type should be created out of two errors:
//! The SbpMsgParseError, & the CrcError. They correspond to two cases
//! 1) the Frame is invalid because either it either has an invalid CRC or
//! it is missing some metadata like msg_type or similar.
//! 2) The message is invalid because the payload is not large enough and cannot be
//! parsed into a message. This is the SbpMsgParseError.

use bytes::{Buf, BufMut};

use crate::{de::CrcError, messages::SbpMsgParseError, wire_format::WireFormat, SbpMessage};

/// Invalid messages occur when either the frame or message payload doesn't have enough bytes or
/// the CRC does not match the messages payload. If the message is well formed with a message
/// id and CRC and payload that all are consistent, but its message type is unknown, it should be
/// parsed into a Unknown message.
///
/// There is something unique about Invalid messages that the payload is actually the entire frame.
/// This is because it is possible to be able to create invalid messages from invalid frames, that
/// may not even contain a message payload.
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
#[derive(Debug, Eq, PartialEq, Clone)]
pub struct Invalid {
    /// The message id of the message.
    #[cfg_attr(feature = "serde", serde(default, skip_serializing))]
    pub msg_id: Option<u16>,
    /// The message sender_id.
    #[cfg_attr(feature = "serde", serde(default, skip_serializing, alias = "sender"))]
    pub sender_id: Option<u16>,
    /// The crc that was in the frame
    #[cfg_attr(
        feature = "serde",
        serde(default, skip_serializing_if = "Option::is_none")
    )]
    pub crc: Option<u16>,
    #[cfg_attr(feature = "json", serde(default, with = "base64"))]
    pub invalid_frame: Vec<u8>,
}

impl SbpMessage for Invalid {
    fn message_name(&self) -> &'static str {
        "INVALID"
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
        // note here we don't add the header and crc etc because the
        // invalid message holds the entire frame in
        // its payload
        WireFormat::len(self)
    }
    fn is_valid(&self) -> bool {
        // Invalid messages can never be valid
        false
    }
}

impl WireFormat for Invalid {
    /// because this is an invalid message, the length may disagree
    /// with what you would expect from parsing the frame itself
    fn len(&self) -> usize {
        self.invalid_frame.len()
    }

    fn write<B: BufMut>(&self, buf: &mut B) {
        self.invalid_frame.write(buf)
    }

    /// In general it is better to construct invalid messages
    /// from thrown errors, not to directly parse to them
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        Invalid {
            msg_id: None,
            sender_id: None,
            crc: None,
            invalid_frame: WireFormat::parse_unchecked(buf),
        }
    }
}

impl From<SbpMsgParseError> for Invalid {
    fn from(
        SbpMsgParseError {
            msg_type,
            sender_id,
            invalid_payload: msg_payload,
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
            crc16::State::<crc16::XMODEM>::calculate(payload.get(1..).expect("vec has capacity"));
        crc.write(&mut payload);

        Self {
            msg_id: Some(msg_type),
            sender_id: Some(sender_id),
            invalid_frame: payload,
            crc: Some(crc),
        }
    }
}

impl From<CrcError> for Invalid {
    fn from(
        CrcError {
            msg_type,
            sender_id,
            invalid_frame,
            crc,
        }: CrcError,
    ) -> Self {
        Self {
            msg_id: msg_type,
            sender_id,
            invalid_frame,
            crc,
        }
    }
}

#[cfg(feature = "json")]
mod base64 {
    use serde::{Deserialize, Serialize};
    use serde::{Deserializer, Serializer};

    pub fn serialize<S: Serializer>(v: &Vec<u8>, s: S) -> Result<S::Ok, S::Error> {
        let base64 = base64::encode(v);
        String::serialize(&base64, s)
    }

    pub fn deserialize<'de, D: Deserializer<'de>>(d: D) -> Result<Vec<u8>, D::Error> {
        let base64 = String::deserialize(d)?;
        base64::decode(base64.as_bytes()).map_err(serde::de::Error::custom)
    }
}
