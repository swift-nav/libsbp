//! Native implementation of decoding of SBP (Swift Binary Protocol) used by products
//! made by Swift Navigation. For language agnostic description of the protocol please
//! see the [protocol specification documentation](https://github.com/swift-nav/libsbp/tree/master/docs).
//!
//! # Example: Print log messages
//!
//! This example shows how to read messages from stdin and print the contents
//! of each message `MsgLog` to stderr.
//!
//! ```no_run
//! use std::convert::TryFrom;
//! use std::error::Error;
//! use std::io;
//! use std::process;
//!
//! use sbp::messages::logging::MsgLog;
//!
//! fn example() -> Result<(), Box<dyn Error>> {
//!     let messages = sbp::iter_messages(io::stdin());
//!     for msg in messages {
//!         // The iterator yields Result<Sbp, Error>, so we check the error here.
//!         let msg = msg?;
//!         match MsgLog::try_from(msg) {
//!             Ok(msg) => eprintln!("{}", msg.text),
//!             _ => {}
//!         }
//!     }
//!     Ok(())
//! }
//!
//! fn main() {
//!     if let Err(err) = example() {
//!         eprintln!("error: {}", err);
//!         process::exit(1);
//!     }
//! }
//! ```
//!
//! # Example: Filter by sender id and write to stdout
//!
//! This example shows how to read messages from stdin and forward messages with a matching
//! sender_id to stdout.
//!
//! ```no_run
//! use std::error::Error;
//! use std::io;
//! use std::process;
//!
//! use sbp::{SbpEncoder, SbpMessage};
//!
//! fn example(sender_id: u16) -> Result<(), Box<dyn Error>> {
//!     let messages = sbp::iter_messages(io::stdin());
//!     let messages = messages.filter_map(|msg| match msg {
//!         Ok(msg) if msg.sender_id() == Some(sender_id) => Some(msg),
//!         _ => None,
//!     });
//!     SbpEncoder::new(io::stdout()).send_all(messages)?;
//!     Ok(())
//! }
//!
//! fn main() {
//!     if let Err(err) = example(42) {
//!         eprintln!("error: {}", err);
//!         process::exit(1);
//!     }
//! }
//!
//! ```
//!
//! # Bitfield Types
//!
//! A number of messages have fields that encode multiple values using a [bitfield](https://en.wikipedia.org/wiki/Bit_field).
//! This crate provides getters and setters on messages with these values. The getters and setters
//! have slightly different semantics that can be grouped into three categories.
//!
//! ## Enumerations
//!
//! Most bitfield members are mapped to a dataless enum. The setter accepts a variant of that enum.
//! The getter will return a variant of this enum wrapped in a `Result`. The getter returns `Ok`
//! if the bitfield member contains a known variant of the enum. Otherwise, the integral value of the
//! bitfield member is returned in the `Err` variant. This may be because of a malformed message,
//! or because you're SBP client is outdated and new variants of the enum were added.
//!
//! ```
//! # use sbp::messages::navigation::msg_pos_llh::{FixMode, MsgPosLlh};
//! # let msg = MsgPosLlh {
//! #     sender_id: None,
//! #     tow: 0,
//! #     lat: 0.,
//! #     lon: 0.,
//! #     height: 0.,
//! #     h_accuracy: 0,
//! #     v_accuracy: 0,
//! #     n_sats: 0,
//! #     flags: 0,
//! # }.into();
//! let mut msg = MsgPosLlh::from(msg);
//! msg.set_fix_mode(FixMode::DeadReckoning);
//! assert_eq!(msg.fix_mode(), Ok(FixMode::DeadReckoning));
//! ```
//!
//! ## Integral
//!
//! Some bitfield members are represented by an integral type. In this case, the getter accepts the
//! smallest integer type that can contain the bitfield member. For example, if the bitfield member
//! spans 6 bits, the setter will accept a `u8`, and mask off any extra bits when setting the value.
//! The getter will return the integer value, again using the smallest integer type that will contain
//! the bitfield member.
//!
//! ```
//! # use sbp::messages::system::MsgStatusReport;
//! # let msg = MsgStatusReport {
//! #     sender_id: None,
//! #     reporting_system: 0,
//! #     sbp_version: 0,
//! #     sequence: 0,
//! #     uptime: 0,
//! #     status: Vec::new(),
//! # }.into();
//! let mut msg = MsgStatusReport::from(msg);
//! msg.set_sbp_major_protocol_version_number(3);
//! assert_eq!(msg.sbp_major_protocol_version_number(), 3);
//! ```
//!
//! ## Boolean
//!
//! If the bitfield members is represented by a single bit, getters and setters use `bool`s.
//!
//! ```
//! # use sbp::messages::navigation::MsgDops;
//! # let msg = MsgDops {
//! #     sender_id: None,
//! #     tow: 0,
//! #     gdop: 0,
//! #     pdop: 0,
//! #     tdop: 0,
//! #     hdop: 0,
//! #     vdop: 0,
//! #     flags: 0,
//! # }.into();
//! let mut msg = MsgDops::from(msg);
//! msg.set_raim_repair_flag(true);
//! assert!(msg.raim_repair_flag());
//! ```

pub mod messages;
pub mod sbp_iter_ext;
pub mod sbp_string;

#[cfg(feature = "json")]
pub mod json;

#[cfg(feature = "link")]
pub mod link;

#[cfg(feature = "swiftnav")]
mod swiftnav_conversions;
#[cfg(feature = "swiftnav")]
pub mod time;

pub(crate) mod de;
pub(crate) mod ser;
pub(crate) mod wire_format;

/// Denotes the start of frame transmission.
pub const PREAMBLE: u8 = 0x55;

/// Length of the header section.
pub const HEADER_LEN: usize = 1 /*preamble*/ + 2 /*msg_type*/ + 2 /*sender_id*/ + 1 /*len*/;

/// Position of payload
pub const PAYLOAD_INDEX: usize = HEADER_LEN - 1;

/// Internal buffer length.
pub(crate) const BUFLEN: usize = 128;

/// Max length of the variable-sized payload field.
pub const MAX_PAYLOAD_LEN: usize = 255;

/// Length of the crc of the payload.
pub const CRC_LEN: usize = 2;

/// Max length of a frame (header + payload + crc).
pub const MAX_FRAME_LEN: usize = HEADER_LEN + MAX_PAYLOAD_LEN + CRC_LEN;

#[doc(inline)]
pub use messages::Sbp;

#[doc(inline)]
pub use crate::messages::SbpMessage;

#[doc(inline)]
pub use ser::{to_vec, to_writer, Error as SerializeError, SbpEncoder};

#[doc(inline)]
pub use de::{Error as DeserializeError, *};

#[cfg(feature = "async")]
#[doc(inline)]
pub use de::{stream_messages, stream_messages_with_timeout};

#[doc(inline)]
pub use sbp_iter_ext::SbpIterExt;

#[doc(inline)]
pub use sbp_string::SbpString;
