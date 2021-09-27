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

((*- for p in packages *))
((*- for m in p.definitions *))
((*- if m.is_real_message *))
use self::(((p.identifier|mod_name)))::(((m.identifier|camel_case)));
((*- endif *))
((*- endfor *))
((*- endfor *))
use self::unknown::Unknown;

mod lib {
    //! Common imports so we can just `use super::lib::*` in all the message files

    pub use std::convert::{TryFrom, TryInto};

    pub use crate::wire_format::{WireFormat, PayloadParseError};
    pub use crate::sbp_string::{SbpString, Unterminated, NullTerminated, Multipart, DoubleNullTerminated};

    #[cfg(feature = "swiftnav-rs")]
    pub use crate::time;

    pub use super::{ConcreteMessage, Sbp, SbpMessage, TryFromSbpError};
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
    /// Get the GPS time associated with the message.
    #[cfg(feature = "swiftnav-rs")]
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
    (((m.identifier|camel_case)))( (((m.identifier|camel_case))) ),
    ((*- endfor *))
    /// Unknown message type
    Unknown( Unknown ),
}

impl Sbp {
    pub(crate) fn from_frame(mut frame: crate::de::Frame) -> Result<Sbp, PayloadParseError> {
        match frame.msg_type {
            ((*- for m in msgs *))
            (((m.identifier|camel_case)))::MESSAGE_TYPE => {
                let mut msg = (((m.identifier|camel_case)))::parse(&mut frame.payload)?;
                msg.set_sender_id(frame.sender_id);
                Ok(Sbp::(((m.identifier|camel_case)))(msg))
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
            Sbp::(((m.identifier|camel_case)))(msg) => {
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
            Sbp::(((m.identifier|camel_case)))(msg) => {
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
            Sbp::(((m.identifier|camel_case)))(msg) => {
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
            Sbp::(((m.identifier|camel_case)))(msg) => {
                msg.set_sender_id(new_id)
            },
            ((*- endfor *))
            Sbp::Unknown(msg) => {
                msg.set_sender_id(new_id)
            },
        }
    }

    #[cfg(feature = "swiftnav-rs")]
    fn gps_time(&self) -> Option<std::result::Result<crate::time::MessageTime, crate::time::GpsTimeError>> {
        match self {
            ((*- for m in msgs *))
            Sbp::(((m.identifier|camel_case)))(msg) => {
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
    const MIN_ENCODED_LEN: usize = crate::MAX_FRAME_LEN;

    fn parse_unchecked(_: &mut bytes::BytesMut) -> Self {
        unimplemented!("Sbp must be parsed with Sbp::from_frame");
    }

    fn write(&self, buf: &mut bytes::BytesMut) {
        match self {
            ((*- for m in msgs *))
            Sbp::(((m.identifier|camel_case)))(msg) => {
                WireFormat::write(msg, buf)
            },
            ((*- endfor *))
            Sbp::Unknown(msg) => {
                WireFormat::write(msg, buf)
            },
        }
    }

    fn encoded_len(&self) -> usize {
        match self {
            ((*- for m in msgs *))
            Sbp::(((m.identifier|camel_case)))(msg) => {
                WireFormat::encoded_len(msg)
            },
            ((*- endfor *))
            Sbp::Unknown(msg) => {
                WireFormat::encoded_len(msg)
            },
        }
    }
}

((* for m in msgs *))
impl From<(((m.identifier|camel_case)))> for Sbp {
    fn from(msg: (((m.identifier|camel_case)))) -> Self {
        Sbp::(((m.identifier|camel_case)))(msg)
    }

}
((* endfor *))
impl From<Unknown> for Sbp {
    fn from(msg: Unknown) -> Self {
        Sbp::Unknown(msg)
    }
}
