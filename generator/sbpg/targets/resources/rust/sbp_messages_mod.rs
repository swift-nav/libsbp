// Copyright (C) 2015-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
//! SBP message definitions.

((*- for m in mods *))
pub mod (((m)));
((*- endfor *))
pub mod unknown;

((*- for m in msgs *))
((*- if m.is_real_message *))
use self::(((m.mod_name)))::(((m.msg_name)));
((*- endif *))
((*- endfor *))
use self::unknown::Unknown;

mod lib {
    //! Common imports so we can just `use super::lib::*` in all the message files

    pub use std::convert::{TryFrom, TryInto};

    pub use crate::sbp_string::{
        DoubleNullTerminated, Multipart, NullTerminated, SbpString, Unterminated,
    };
    #[cfg(feature = "swiftnav")]
    pub use crate::time;
    pub use crate::wire_format::{PayloadParseError, WireFormat};

    pub use super::{ConcreteMessage, Sbp, SbpMessage, TryFromSbpError};

    pub use bytes::{Buf, BufMut};

    macro_rules! get_bit_range {
        ($bitrange:expr, $source_ty:ty, $target_ty:ty, $msb:expr, $lsb:expr) => {{
            let bit_len = std::mem::size_of::<$source_ty>() * 8;
            let result_bit_len = std::mem::size_of::<$target_ty>() * 8;
            let result =
                (($bitrange << (bit_len - $msb - 1)) >> (bit_len - $msb - 1 + $lsb)) as $target_ty;
            result << (result_bit_len - ($msb - $lsb + 1)) >> (result_bit_len - ($msb - $lsb + 1))
        }};
    }

    macro_rules! set_bit_range {
        ($bitrange:expr, $value: expr, $source_ty:ty, $target_ty:ty, $msb:expr, $lsb:expr) => {
            let bit_len = std::mem::size_of::<$source_ty>() * 8;
            let mask: $source_ty = !(0 as $source_ty)
                << (bit_len - $msb - 1)
                >> (bit_len - $msb - 1 + $lsb)
                << ($lsb);
            *$bitrange &= !mask;
            *$bitrange |= ($value as $source_ty << $lsb) & mask;
        };
    }

    pub(crate) use get_bit_range;
    pub(crate) use set_bit_range;
}

use lib::*;

/// Common functionality available to all SBP messages.
pub trait SbpMessage: WireFormat + Clone + Sized {
    /// Get the message name.
    fn message_name(&self) -> &'static str;
    /// Get the message type.
    fn message_type(&self) -> u16;
    /// Get the sender_id if it is set.
    fn sender_id(&self) -> Option<u16>;
    /// Set the sender id.
    fn set_sender_id(&mut self, new_id: u16);
    /// Number of bytes this message will take on the wire.
    fn encoded_len(&self) -> usize;
    /// Get the GPS time associated with the message.
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<Result<crate::time::MessageTime, crate::time::GpsTimeError>> {
        None
    }
}

/// Implemented by messages who's message name and type are known at compile time.
/// This is everything that implements [SbpMessage] except for [Sbp].
pub trait ConcreteMessage: SbpMessage + TryFrom<Sbp, Error = TryFromSbpError> {
    /// The message type.
    const MESSAGE_TYPE: u16;
    /// The message name.
    const MESSAGE_NAME: &'static str;
}

/// The error returned when using [TryFrom] to convert [Sbp] to the wrong message type.
#[derive(Debug, Clone)]
pub struct TryFromSbpError;

impl std::fmt::Display for TryFromSbpError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "invalid message type for conversion")
    }
}

impl std::error::Error for TryFromSbpError {}

/// Represents any SBP message.
#[cfg_attr(feature = "serde", derive(serde::Serialize), serde(untagged))]
#[derive(Debug, Clone)]
#[non_exhaustive]
pub enum Sbp {
    ((*- for m in msgs *))
    /// (((m.short_desc | commentify(indent=2) )))
    (((m.msg_name)))( (((m.msg_name))) ),
    ((*- endfor *))
    /// Unknown message type
    Unknown( Unknown ),
}

impl Sbp {
    /// Parse a message from a [Frame](crate::Frame).
    ///
    /// # Example
    ///
    /// ```
    /// use std::convert::TryInto;
    ///
    /// use sbp::messages::logging::MsgLog;
    /// use sbp::{Frame, Sbp};
    ///
    /// fn main() -> Result<(), Box<dyn std::error::Error>> {
    ///     // log level 1 and with "hello" as the message
    ///     let payload: &[u8] = &[1, 104, 101, 108, 108, 111];
    ///     let frame = Frame {
    ///         msg_type: 1025,
    ///         sender_id: 1,
    ///         payload,
    ///     };
    ///     let msg: MsgLog = Sbp::from_frame(frame)?.try_into()?;
    ///     assert_eq!(msg.sender_id, Some(1));
    ///     assert_eq!(msg.level, 1);
    ///     assert_eq!(msg.text.as_bytes(), "hello".as_bytes());
    ///     Ok(())
    /// }
    /// ```
    pub fn from_frame<B: Buf>(mut frame: crate::Frame<B>) -> Result<Sbp, PayloadParseError> {
        match frame.msg_type {
            ((*- for m in msgs *))
            (((m.msg_name)))::MESSAGE_TYPE => {
                let mut msg = (((m.msg_name)))::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::(((m.msg_name)))(msg))
            },
            ((*- endfor *))
            _ => {
                let mut msg = Unknown::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::Unknown(msg))
            }
        }
    }
}

impl SbpMessage for Sbp {
    fn message_name(&self) -> &'static str {
        match self {
            ((*- for m in msgs *))
            Sbp::(((m.msg_name)))(msg) => {
                msg.message_name()
            },
            ((*- endfor *))
            Sbp::Unknown(msg) => {
                msg.message_name()
            },
        }
    }

    fn message_type(&self) -> u16 {
        match self {
            ((*- for m in msgs *))
            Sbp::(((m.msg_name)))(msg) => {
                msg.message_type()
            },
            ((*- endfor *))
            Sbp::Unknown(msg) => {
                msg.message_type()
            },
        }
    }

    fn sender_id(&self) -> Option<u16> {
        match self {
            ((*- for m in msgs *))
            Sbp::(((m.msg_name)))(msg) => {
                msg.sender_id()
            },
            ((*- endfor *))
            Sbp::Unknown(msg) => {
                msg.sender_id()
            },
        }
    }

    fn set_sender_id(&mut self, new_id: u16) {
        match self {
            ((*- for m in msgs *))
            Sbp::(((m.msg_name)))(msg) => {
                msg.set_sender_id(new_id)
            },
            ((*- endfor *))
            Sbp::Unknown(msg) => {
                msg.set_sender_id(new_id)
            },
        }
    }

    fn encoded_len(&self) -> usize {
        match self {
            ((*- for m in msgs *))
            Sbp::(((m.msg_name)))(msg) => {
                msg.encoded_len()
            },
            ((*- endfor *))
            Sbp::Unknown(msg) => {
                msg.encoded_len()
            },
        }
    }

    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<crate::time::MessageTime, crate::time::GpsTimeError>> {
        match self {
            ((*- for m in msgs *))
            Sbp::(((m.msg_name)))(msg) => {
                msg.gps_time()
            },
            ((*- endfor *))
            Sbp::Unknown(msg) => {
                msg.gps_time()
            },
        }
    }
}

impl WireFormat for Sbp {
    const MIN_LEN: usize = crate::MAX_FRAME_LEN;

    fn parse_unchecked<B: Buf>(_: &mut B) -> Self {
        unimplemented!("Sbp must be parsed with Sbp::from_frame");
    }

    fn write<B: BufMut>(&self, buf: &mut B) {
        match self {
            ((*- for m in msgs *))
            Sbp::(((m.msg_name)))(msg) => {
                WireFormat::write(msg, buf)
            },
            ((*- endfor *))
            Sbp::Unknown(msg) => {
                WireFormat::write(msg, buf)
            },
        }
    }

    fn len(&self) -> usize {
        match self {
            ((*- for m in msgs *))
            Sbp::(((m.msg_name)))(msg) => {
                WireFormat::len(msg)
            },
            ((*- endfor *))
            Sbp::Unknown(msg) => {
                WireFormat::len(msg)
            },
        }
    }
}

((* for m in msgs *))
impl From<(((m.msg_name)))> for Sbp {
    fn from(msg: (((m.msg_name)))) -> Self {
        Sbp::(((m.msg_name)))(msg)
    }

}
((* endfor *))
impl From<Unknown> for Sbp {
    fn from(msg: Unknown) -> Self {
        Sbp::Unknown(msg)
    }
}