use std::borrow::Borrow;
use std::io;

use bytes::BytesMut;
use dencode::{Encoder, FramedWrite, IterSinkExt};

use crate::wire_format::WireFormat;
use crate::{Sbp, SbpMessage};
use crate::{BUFLEN, MAX_PAYLOAD_LEN, PREAMBLE};

/// Serialize the given message into the IO stream.
///
/// # Example
///
/// ```
/// use sbp::messages::logging::MsgLog;
///
/// fn main() -> Result<(), Box<dyn std::error::Error>> {
///     let text = String::from("hello");
///     let msg = MsgLog {
///         sender_id: Some(1),
///         level: 1,
///         text: text.clone().into(),
///     };
///     let mut writer = Vec::new();
///     sbp::to_writer(&mut writer, &msg)?;
///     assert_eq!(
///         &writer[sbp::HEADER_LEN + 1..writer.len() - sbp::CRC_LEN],
///         text.as_bytes()
///     );
///     Ok(())
/// }
/// ```
pub fn to_writer<W, M>(mut writer: W, msg: &M) -> Result<(), Error>
where
    W: io::Write,
    M: SbpMessage,
{
    let mut buf = BytesMut::with_capacity(BUFLEN);
    to_buffer(&mut buf, msg)?;
    writer.write_all(&buf)?;
    Ok(())
}

/// Serialize the given message as a byte vector.
///
/// # Example
///
/// ```
/// use sbp::messages::logging::MsgLog;
///
/// fn main() -> Result<(), Box<dyn std::error::Error>> {
///     let text = String::from("hello");
///     let msg = MsgLog {
///         sender_id: Some(1),
///         level: 1,
///         text: text.clone().into(),
///     };
///     let bytes = sbp::to_vec(&msg)?;
///     assert_eq!(
///         &bytes[sbp::HEADER_LEN + 1..bytes.len() - sbp::CRC_LEN],
///         text.as_bytes()
///     );
///     Ok(())
/// }
/// ```
pub fn to_vec<M: SbpMessage>(msg: &M) -> Result<Vec<u8>, Error> {
    let mut buf = BytesMut::with_capacity(BUFLEN);
    to_buffer(&mut buf, msg)?;
    Ok(buf.to_vec())
}

pub fn to_buffer<M: SbpMessage>(buf: &mut BytesMut, msg: &M) -> Result<(), WriteFrameError> {
    let sender_id = msg.sender_id().ok_or(WriteFrameError::NoSenderId)?;
    let payload_len = msg.len();
    if payload_len > MAX_PAYLOAD_LEN {
        return Err(WriteFrameError::TooLarge);
    }

    let old_buf = buf.split();

    PREAMBLE.write(buf);
    msg.message_type().write(buf);
    sender_id.write(buf);
    (payload_len as u8).write(buf);
    msg.write(buf);
    let crc = crc16::State::<crc16::XMODEM>::calculate(&buf[1..]);
    crc.write(buf);

    buf.unsplit(old_buf);

    Ok(())
}

/// All errors that can occur while writing messages.
#[derive(Debug)]
pub enum Error {
    WriteFrameError(WriteFrameError),
    IoError(io::Error),
}

impl std::fmt::Display for Error {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Error::WriteFrameError(e) => e.fmt(f),
            Error::IoError(e) => e.fmt(f),
        }
    }
}

impl std::error::Error for Error {}

impl From<WriteFrameError> for Error {
    fn from(e: WriteFrameError) -> Self {
        Error::WriteFrameError(e)
    }
}

impl From<io::Error> for Error {
    fn from(e: io::Error) -> Self {
        Error::IoError(e)
    }
}

#[derive(Debug, Clone)]
pub enum WriteFrameError {
    TooLarge,
    NoSenderId,
}

impl std::fmt::Display for WriteFrameError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            WriteFrameError::TooLarge => write!(f, "message is too large to fit into a frame"),
            WriteFrameError::NoSenderId => write!(f, "no sender id present in the message"),
        }
    }
}

impl std::error::Error for WriteFrameError {}

/// Writes [Sbp] messages into a writer.
#[derive(Debug)]
pub struct SbpEncoder<W>(FramedWrite<W, SbpEncoderInner>);

impl<W: io::Write> SbpEncoder<W> {
    /// Creates a new SbpEncoder.
    pub fn new(writer: W) -> SbpEncoder<W> {
        Self(FramedWrite::new(writer, SbpEncoderInner))
    }

    /// Send a message to the underlying writer. If sending multiple messages at once
    /// consider using [SbpEncoder::send_all] which buffers the writing.
    pub fn send(&mut self, message: &Sbp) -> Result<(), Error> {
        self.0.send(message)
    }

    /// Sends an iterator of messages to the underlying writer.
    pub fn send_all<I>(&mut self, messages: I) -> Result<(), Error>
    where
        I: IntoIterator<Item = Sbp>,
    {
        self.0.send_all(messages.into_iter().map(Result::Ok))
    }
}

#[derive(Debug)]
struct SbpEncoderInner;

impl<T> Encoder<T> for SbpEncoderInner
where
    T: Borrow<Sbp>,
{
    type Error = Error;

    fn encode(&mut self, msg: T, dst: &mut BytesMut) -> Result<(), Self::Error> {
        if let Err(err) = to_buffer(dst, msg.borrow()) {
            log::error!("error serializing message: {}", err);
        }
        Ok(())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_to_vec() {
        let msg = crate::messages::system::MsgStartup {
            sender_id: Some(250),
            cause: 1,
            startup_type: 45,
            reserved: 0,
        };
        let frame = to_vec(&msg).unwrap();
        let expected_frame = b"\x55\x00\xFF\xFA\x00\x04\x01\x2D\x00\x00\xBC\x73";
        assert_eq!(frame, expected_frame);
    }

    #[test]
    fn test_to_writer() {
        let msg = crate::messages::system::MsgStartup {
            sender_id: Some(250),
            cause: 1,
            startup_type: 45,
            reserved: 0,
        };
        let mut writer = Vec::new();
        to_writer(&mut writer, &msg).unwrap();
        let expected_frame = b"\x55\x00\xFF\xFA\x00\x04\x01\x2D\x00\x00\xBC\x73";
        assert_eq!(writer, expected_frame);
    }
}
