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
pub use de::{iter_messages, Error as DeserializeError, Frame};

#[cfg(feature = "async")]
#[doc(inline)]
pub use de::stream_messages;

#[doc(inline)]
pub use sbp_iter_ext::SbpIterExt;

#[doc(inline)]
pub use sbp_string::SbpString;
