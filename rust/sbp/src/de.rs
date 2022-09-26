use std::{
    io,
    time::{Duration, Instant},
};

use bytes::{Buf, BytesMut};
use dencode::FramedRead;

use crate::{wire_format, Sbp, CRC_LEN, HEADER_LEN, MAX_FRAME_LEN, PAYLOAD_INDEX, PREAMBLE};

/// Deserialize the IO stream into an iterator of messages.
///
/// # Example
///
/// ```
/// use std::io::Cursor;
///
/// use sbp::messages::logging::MsgLog;
///
/// fn main() -> Result<(), Box<dyn std::error::Error>> {
///     let mut data = Vec::new();
///     sbp::to_writer(
///         &mut data,
///         &MsgLog {
///             sender_id: Some(1),
///             level: 1,
///             text: String::from("hello").into(),
///         },
///     )?;
///     sbp::to_writer(
///         &mut data,
///         &MsgLog {
///             sender_id: Some(1),
///             level: 1,
///             text: String::from("world").into(),
///         },
///     )?;
///     let messages = sbp::iter_messages(Cursor::new(data));
///     assert_eq!(messages.count(), 2);
///     Ok(())
/// }
/// ```
pub fn iter_messages<R: io::Read>(input: R) -> impl Iterator<Item = Result<Sbp, Error>> {
    Decoder::new(input)
}

/// Deserialize the IO stream into an iterator of messages. Provide a timeout
/// for the maximum allowed duration without a successful message.
pub fn iter_messages_with_timeout<R: io::Read>(
    input: R,
    timeout_duration: Duration,
) -> impl Iterator<Item = Result<Sbp, Error>> {
    TimeoutDecoder::new(input, timeout_duration)
}

/// Deserialize the async IO stream into an stream of messages.
#[cfg(feature = "async")]
pub fn stream_messages<R: futures::AsyncRead + Unpin>(
    input: R,
) -> impl futures::Stream<Item = Result<Sbp, Error>> {
    Decoder::new(input)
}

#[cfg(feature = "async")]
pub fn stream_messages_with_timeout<R: futures::AsyncRead + Unpin>(
    input: R,
    timeout_duration: Duration,
) -> impl futures::Stream<Item = Result<Sbp, Error>> {
    TimeoutDecoder::new(input, timeout_duration)
}

/// All errors that can occur while reading messages.
#[derive(Debug)]
pub enum Error {
    PayloadParseError(wire_format::PayloadParseError),
    CrcError(CrcError),
    IoError(io::Error),
}

impl std::fmt::Display for Error {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Error::PayloadParseError(e) => e.fmt(f),
            Error::CrcError(e) => e.fmt(f),
            Error::IoError(e) => e.fmt(f),
        }
    }
}

impl std::error::Error for Error {}

impl From<wire_format::PayloadParseError> for Error {
    fn from(e: wire_format::PayloadParseError) -> Self {
        Error::PayloadParseError(e)
    }
}

impl From<CrcError> for Error {
    fn from(e: CrcError) -> Self {
        Error::CrcError(e)
    }
}

impl From<io::Error> for Error {
    fn from(e: io::Error) -> Self {
        Error::IoError(e)
    }
}

#[derive(Debug, Clone)]
pub struct CrcError {
    pub msg_type: u16,
    pub sender_id: u16,
    pub crc: u16,
}

impl std::fmt::Display for CrcError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "crc validation failed: sender_id={:#02X?} msg_type={:#02X?} crc={:#02X?}",
            self.msg_type, self.sender_id, self.crc
        )
    }
}

impl std::error::Error for CrcError {}

pub struct Framer<R>(FramedRead<R, FramerImpl>);

impl<R> Framer<R> {
    pub fn new(reader: R) -> Self {
        Self(FramedRead::new(reader, FramerImpl))
    }
}

impl<R: io::Read> Iterator for Framer<R> {
    type Item = Result<Frame, Error>;

    fn next(&mut self) -> Option<Self::Item> {
        self.0.next()
    }
}

#[cfg(feature = "async")]
impl<R: futures::AsyncRead + Unpin> futures::Stream for Framer<R> {
    type Item = Result<Frame, Error>;
    fn poll_next(
        mut self: std::pin::Pin<&mut Self>,
        cx: &mut std::task::Context<'_>,
    ) -> std::task::Poll<Option<Self::Item>> {
        std::pin::Pin::new(&mut self.0).poll_next(cx)
    }
}

pub struct Decoder<R>(FramedRead<R, FramerImpl>);

impl<R> Decoder<R> {
    pub fn new(reader: R) -> Self {
        Decoder(FramedRead::new(reader, FramerImpl))
    }
}

impl<R: io::Read> Iterator for Decoder<R> {
    type Item = Result<Sbp, Error>;

    fn next(&mut self) -> Option<Self::Item> {
        self.0.next().map(|f| match f {
            Ok(frame) => frame.to_sbp(),
            Err(err) => Err(err),
        })
    }
}

#[cfg(feature = "async")]
impl<R: futures::AsyncRead + Unpin> futures::Stream for Decoder<R> {
    type Item = Result<Sbp, Error>;

    fn poll_next(
        mut self: std::pin::Pin<&mut Self>,
        cx: &mut std::task::Context<'_>,
    ) -> std::task::Poll<Option<Self::Item>> {
        let frame = match futures::ready!(std::pin::Pin::new(&mut self.0).poll_next(cx)) {
            Some(Ok(frame)) => frame,
            Some(Err(e)) => return std::task::Poll::Ready(Some(Err(e.into()))),
            None => return std::task::Poll::Ready(None),
        };
        std::task::Poll::Ready(Some(frame.to_sbp()))
    }
}

#[derive(Debug, Clone, Default)]
struct FramerImpl;

impl dencode::Decoder for FramerImpl {
    type Item = Frame;
    type Error = Error;

    fn decode(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>, Self::Error> {
        let start = match src.iter().position(|b| b == &PREAMBLE) {
            Some(idx) => idx,
            None => {
                src.clear();
                return Ok(None);
            }
        };
        src.advance(start);
        if src.len() < HEADER_LEN {
            src.reserve(MAX_FRAME_LEN);
            return Ok(None);
        }
        let end = HEADER_LEN + src[PAYLOAD_INDEX] as usize + CRC_LEN;
        if src.len() < end {
            src.reserve(MAX_FRAME_LEN);
            return Ok(None);
        }
        Ok(Some(Frame(src.split_to(end))))
    }
}

/// The wire representation of an SBP message.
#[derive(Debug)]
pub struct Frame(BytesMut);

impl Frame {
    pub fn msg_type(&self) -> u16 {
        let mut slice = &self.0.chunk()[1..];
        slice.get_u16_le()
    }

    pub fn sender_id(&self) -> u16 {
        let mut slice = &self.0.chunk()[3..];
        slice.get_u16_le()
    }

    pub fn payload_len(&self) -> usize {
        self.0.chunk()[PAYLOAD_INDEX] as usize
    }

    pub fn payload(&self) -> &[u8] {
        &self.0.chunk()[HEADER_LEN..HEADER_LEN + self.payload_len()]
    }

    pub fn crc(&self) -> u16 {
        let mut slice = &self.0.chunk()[HEADER_LEN + self.payload_len()..];
        slice.get_u16_le()
    }

    pub fn check_crc(&self) -> Result<u16, CrcError> {
        let actual = self.crc();
        let data = &self.0.chunk()[1..HEADER_LEN + self.payload_len()];
        if actual == crc16::State::<crc16::XMODEM>::calculate(data) {
            Ok(actual)
        } else {
            Err(CrcError {
                msg_type: self.msg_type(),
                sender_id: self.sender_id(),
                crc: actual,
            })
        }
    }

    pub fn len(&self) -> usize {
        self.0.chunk().len()
    }

    pub fn is_empty(&self) -> bool {
        self.len() == 0
    }

    pub fn to_sbp(&self) -> Result<Sbp, Error> {
        self.check_crc()?;
        Ok(Sbp::from_parts(
            self.msg_type(),
            self.sender_id(),
            self.payload(),
        )?)
    }

    pub fn as_bytes(&self) -> &[u8] {
        self.0.chunk()
    }
}

struct TimeoutDecoderImpl<D> {
    timeout_duration: Duration,
    last_msg_received: Instant,
    inner: D,
}

impl<D> TimeoutDecoderImpl<D> {
    fn new(inner: D, timeout_duration: Duration) -> Self {
        Self {
            inner,
            timeout_duration,
            last_msg_received: Instant::now(),
        }
    }
}

impl<D: dencode::Decoder> dencode::Decoder for TimeoutDecoderImpl<D> {
    type Item = D::Item;
    type Error = D::Error;

    fn decode(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>, Self::Error> {
        if self.last_msg_received.elapsed() > self.timeout_duration {
            return Err(io::Error::new(io::ErrorKind::TimedOut, "timeout").into());
        }
        let next = self.inner.decode(src)?;
        if next.is_some() {
            self.last_msg_received = Instant::now();
        }
        Ok(next)
    }
}

struct TimeoutDecoder<R>(FramedRead<R, TimeoutDecoderImpl<FramerImpl>>);

impl<R> TimeoutDecoder<R> {
    pub fn new(reader: R, timeout: Duration) -> Self {
        Self(FramedRead::new(
            reader,
            TimeoutDecoderImpl::new(FramerImpl, timeout),
        ))
    }
}

impl<R: io::Read> Iterator for TimeoutDecoder<R> {
    type Item = Result<Sbp, Error>;

    fn next(&mut self) -> Option<Self::Item> {
        self.0.next().map(|f| match f {
            Ok(frame) => frame.to_sbp(),
            Err(err) => Err(err),
        })
    }
}

#[cfg(feature = "async")]
impl<R: futures::AsyncRead + Unpin> futures::Stream for TimeoutDecoder<R> {
    type Item = Result<Sbp, Error>;

    fn poll_next(
        mut self: std::pin::Pin<&mut Self>,
        cx: &mut std::task::Context<'_>,
    ) -> std::task::Poll<Option<Self::Item>> {
        match futures::ready!(std::pin::Pin::new(&mut self.0).poll_next(cx)) {
            Some(Ok(frame)) => std::task::Poll::Ready(Some(frame.to_sbp())),
            Some(Err(e)) => std::task::Poll::Ready(Some(Err(e.into()))),
            None => std::task::Poll::Ready(None),
        }
    }
}

#[cfg(test)]
mod tests {
    use bytes::BufMut;
    use dencode::Decoder;
    use std::{
        convert::TryInto,
        io::{Cursor, Write},
    };

    use crate::{messages::navigation::MsgBaselineEcef, wire_format::WireFormat};

    use super::*;

    struct NeverPreambleReader;

    impl std::io::Read for NeverPreambleReader {
        fn read(&mut self, mut buf: &mut [u8]) -> std::io::Result<usize> {
            buf.write_all(&[0])?;
            Ok(1)
        }
    }

    /// Test iter_messages_with_timeout for handling a reader that never returns a PREAMBLE.
    #[test]
    fn test_iter_messages_with_timeout() {
        let rdr = NeverPreambleReader;
        let timeout_duration = Duration::from_secs(2);
        let now = Instant::now();
        let mut messages = iter_messages_with_timeout(rdr, timeout_duration);
        for msg in &mut messages {
            assert!(matches!(msg, Err(Error::IoError(_))));
            break;
        }
        assert!(now.elapsed() >= timeout_duration);
    }

    /// Test parsing when we don't have enough data for a frame message
    #[test]
    fn test_parse_frame_incomplete() {
        let packet = [
            0x55u8, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff,
            0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb,
        ];
        let missing_byte = 0xbf;
        let mut buf = BytesMut::from(&packet[..]);

        let res = FramerImpl.decode(&mut buf).unwrap();
        assert!(res.is_none());
        assert_eq!(buf.len(), packet.len());

        buf.put_u8(missing_byte);

        let res = FramerImpl.decode(&mut buf).unwrap().unwrap();
        assert_eq!(res.msg_type(), 523); // 0x020B
        assert_eq!(res.sender_id(), 35027); // 0x88D3
        assert_eq!(
            res.payload(),
            BytesMut::from(&packet[HEADER_LEN..packet.len() - 1])
        );
        assert!(buf.is_empty());
    }

    #[test]
    fn test_parse_nothing() {
        let data = vec![0u8; 1000];
        let mut bytes = BytesMut::from(&data[..]);
        assert_eq!(bytes.len(), 1000);
        assert!(matches!(FramerImpl.decode(&mut bytes).unwrap(), None));
    }

    #[test]
    fn test_parse_bad_message() {
        // Properly framed data but the payload isn't right given the message type
        let data: Vec<u8> = vec![0x55, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x65, 0x8D];
        let bytes = BytesMut::from(&data[..]);
        let mut actual = crate::de::Decoder::new(bytes.reader());
        assert!(matches!(
            actual.next().unwrap(),
            Err(Error::PayloadParseError(_))
        ));
    }

    #[test]
    fn test_iter_messages() {
        let mut payload = vec![
            0x55u8, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff,
            0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf,
        ];
        payload.append(&mut payload.clone());
        let input = Cursor::new(payload);
        let mut count = 0;
        for msg in iter_messages(input) {
            assert!(msg.is_ok());
            count += 1;
        }
        assert_eq!(count, 2);
    }

    #[test]
    fn test_parse_crc_error() {
        let packet = vec![
            // Start with a mostly valid message, with a single byte error
            0x55, 0x0c, // This byte should be 0x0b, changed to intentionally cause a CRC error
            0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff, 0xbe, 0x40,
            0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf, 0xde, 0xad,
            0xbe, 0xef, // Include another valid message to properly parse
            0x55, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff,
            0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf,
            0xde, 0xad, 0xbe, 0xef,
        ];
        let mut msgs = iter_messages(Cursor::new(packet));

        let res = msgs.next().unwrap().unwrap_err();
        assert!(matches!(res, Error::CrcError(..)));

        let res = msgs.next().unwrap();
        assert!(res.is_ok());
    }

    #[test]
    fn test_invalid_utf8() {
        let packet = vec![
            0x55, 0xa7, 0x0, 0x0, 0x10, 0x48, 0x8, 0x0, 0x73, 0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f,
            0x6e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb6, 0xe8, 0xab,
        ];
        let mut msgs = iter_messages(Cursor::new(packet));

        let sbp_result = msgs.next().unwrap();
        assert!(sbp_result.is_ok());

        let sbp_message = sbp_result.unwrap();
        assert_eq!(sbp_message.len(), 72);
    }

    #[test]
    fn test_decode_sbp() {
        let packet = BytesMut::from(
            &[
                0x55u8, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee,
                0xff, 0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb,
                0xbf,
            ][..],
        );
        let baseline_ecef_expectation = MsgBaselineEcef {
            sender_id: Some(0x88d3),
            accuracy: 0,
            flags: 0,
            n_sats: 14,
            tow: 326825000,
            x: -1154410,
            y: 1327294,
            z: 631798,
        };

        let msg = crate::de::Decoder::new(packet.reader())
            .next()
            .unwrap()
            .unwrap();

        let msg: MsgBaselineEcef = msg.try_into().unwrap();
        assert_eq!(msg.sender_id, baseline_ecef_expectation.sender_id);
        assert_eq!(msg.accuracy, baseline_ecef_expectation.accuracy);
        assert_eq!(msg.flags, baseline_ecef_expectation.flags);
        assert_eq!(msg.n_sats, baseline_ecef_expectation.n_sats);
        assert_eq!(msg.tow, baseline_ecef_expectation.tow);
        assert_eq!(msg.x, baseline_ecef_expectation.x);
        assert_eq!(msg.y, baseline_ecef_expectation.y);
        assert_eq!(msg.z, baseline_ecef_expectation.z);
    }
}
