use std::{
    convert::TryInto,
    io,
    time::{Duration, Instant},
};

use bytes::{Buf, BytesMut};
use dencode::FramedRead;

#[cfg(feature = "async")]
use futures::StreamExt;

use crate::{
    messages::{invalid::Invalid, SbpMsgParseError},
    HandleParseError, Sbp, CRC_LEN, HEADER_LEN, MAX_FRAME_LEN, PAYLOAD_INDEX, PREAMBLE,
};

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

/// Deserialize IO stream into iterator of raw frames
pub fn iter_frames<R: io::Read>(input: R) -> impl Iterator<Item = Result<Frame, Error>> {
    Framer::new(input)
}

/// Deserialize the IO stream into an iterator of messages. Provide a timeout
/// for the maximum allowed duration without a successful message.
pub fn iter_messages_with_timeout<R: io::Read>(
    input: R,
    timeout_duration: Duration,
) -> impl Iterator<Item = Result<Sbp, Error>> {
    TimeoutDecoder::new(input, timeout_duration).map(|res| res.and_then(|frame| frame.to_sbp()))
}

/// Deserialize the IO stream into an iterator of frames. Provide a timeout
/// for the maximum allowed duration without a successful message.
pub fn iter_frames_with_timeout<R: io::Read>(
    input: R,
    timeout_duration: Duration,
) -> impl Iterator<Item = Result<Frame, Error>> {
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
    TimeoutDecoder::new(input, timeout_duration).map(|res| res.and_then(|frame| frame.to_sbp()))
}

/// Deserialize the async IO stream into stream of frames
#[cfg(feature = "async")]
pub fn stream_frames<R: futures::AsyncRead + Unpin>(
    input: R,
) -> impl futures::Stream<Item = Result<Frame, Error>> {
    Framer::new(input)
}

#[cfg(feature = "async")]
pub fn stream_frames_with_timeout<R: futures::AsyncRead + Unpin>(
    input: R,
    timeout_duration: Duration,
) -> impl futures::Stream<Item = Result<Frame, Error>> {
    TimeoutDecoder::new(input, timeout_duration)
}

/// All errors that can occur while reading messages.
#[derive(Debug)]
pub enum Error {
    SbpMsgParseError(SbpMsgParseError),
    CrcError(CrcError),
    IoError(io::Error),
}

impl HandleParseError<Sbp> for Error {
    fn handle_parse_error(self) -> Sbp {
        match self {
            Error::SbpMsgParseError(e) => Invalid::from(e).into(),
            Error::CrcError(e) => Invalid::from(e).into(),
            Error::IoError(e) => {
                panic!("unrecoverable I/O error: {}", e);
            }
        }
    }
}

impl std::fmt::Display for Error {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Error::SbpMsgParseError(e) => e.fmt(f),
            Error::CrcError(e) => e.fmt(f),
            Error::IoError(e) => e.fmt(f),
        }
    }
}

impl std::error::Error for Error {}

impl From<SbpMsgParseError> for Error {
    fn from(e: SbpMsgParseError) -> Self {
        Error::SbpMsgParseError(e)
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
    pub msg_type: Option<u16>,
    pub sender_id: Option<u16>,
    pub crc: Option<u16>,
    pub invalid_frame: Vec<u8>,
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
            Some(Err(e)) => return std::task::Poll::Ready(Some(Err(e))),
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
    #[allow(clippy::assertions_on_constants)]
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

        debug_assert!(
            PAYLOAD_INDEX < HEADER_LEN,
            "payload_index must be less than header len"
        );
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
    pub fn msg_type(&self) -> Option<u16> {
        self.as_bytes()
            .get(1..3)
            .and_then(|slice| TryInto::<[u8; 2]>::try_into(slice).ok())
            .map(u16::from_le_bytes)
    }

    pub fn sender_id(&self) -> Option<u16> {
        self.as_bytes()
            .get(3..5)
            .and_then(|slice| TryInto::<[u8; 2]>::try_into(slice).ok())
            .map(u16::from_le_bytes)
    }
    pub fn payload_len(&self) -> Option<usize> {
        self.as_bytes().get(PAYLOAD_INDEX).map(|&x| x as usize)
    }

    pub fn payload(&self) -> Option<&[u8]> {
        self.payload_len()
            .and_then(|payload_len| self.as_bytes().get(HEADER_LEN..HEADER_LEN + payload_len))
    }

    pub fn crc(&self) -> Option<u16> {
        self.payload_len()
            .and_then(|payload_len| {
                let start = HEADER_LEN + payload_len;
                self.as_bytes().get(start..start + CRC_LEN)
            })
            .and_then(|slice| TryInto::<[u8; CRC_LEN]>::try_into(slice).ok())
            .map(u16::from_le_bytes)
    }

    pub fn check_crc(&self) -> Result<u16, CrcError> {
        let given = self.crc();
        let measured_crc = self
            .payload_len()
            .and_then(|payload_len| self.as_bytes().get(1..HEADER_LEN + payload_len))
            .map(crc16::State::<crc16::XMODEM>::calculate);

        match (given, measured_crc) {
            (Some(given), Some(crc)) if given == crc => Ok(given),
            (given, _measured) => Err(CrcError {
                msg_type: self.msg_type(),
                sender_id: self.sender_id(),
                crc: given,
                invalid_frame: self.as_bytes().to_vec(),
            }),
        }
    }

    pub fn len(&self) -> usize {
        self.as_bytes().len()
    }

    pub fn is_empty(&self) -> bool {
        self.len() == 0
    }

    pub fn to_sbp(&self) -> Result<Sbp, Error> {
        self.check_crc()?;

        match (self.msg_type(), self.sender_id(), self.payload()) {
            (Some(msg_type), Some(sender_id), Some(payload)) => {
                Ok(Sbp::from_parts(msg_type, sender_id, payload)?)
            }
            (msg_type, sender_id, _payload) => Err(CrcError {
                msg_type,
                sender_id,
                crc: self.crc(),
                invalid_frame: self.as_bytes().to_vec(),
            }
            .into()),
        }
    }

    #[inline]
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
    type Item = Result<Frame, Error>;

    fn next(&mut self) -> Option<Self::Item> {
        self.0.next()
    }
}

#[cfg(feature = "async")]
impl<R: futures::AsyncRead + Unpin> futures::Stream for TimeoutDecoder<R> {
    type Item = Result<Frame, Error>;

    fn poll_next(
        mut self: std::pin::Pin<&mut Self>,
        cx: &mut std::task::Context<'_>,
    ) -> std::task::Poll<Option<Self::Item>> {
        match futures::ready!(std::pin::Pin::new(&mut self.0).poll_next(cx)) {
            Some(Ok(frame)) => std::task::Poll::Ready(Some(Ok(frame))),
            Some(Err(e)) => std::task::Poll::Ready(Some(Err(e))),
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

    use crate::{
        messages::{invalid::Invalid, navigation::MsgBaselineEcef},
        wire_format::WireFormat,
    };

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
        assert!(matches!(
            messages.next().unwrap().unwrap_err(),
            Error::IoError(_)
        ));
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
        assert_eq!(res.msg_type(), Some(523)); // 0x020B
        assert_eq!(res.sender_id(), Some(35027)); // 0x88D3
        assert_eq!(
            res.payload().unwrap(),
            BytesMut::from(&packet[HEADER_LEN..packet.len() - 1])
        );
        assert!(buf.is_empty());
    }

    #[test]
    fn test_parse_nothing() {
        let data = vec![0u8; 1000];
        let mut bytes = BytesMut::from(&data[..]);
        assert_eq!(bytes.len(), 1000);
        assert!(FramerImpl.decode(&mut bytes).unwrap().is_none());
    }

    #[test]
    fn test_parse_bad_message() {
        // Properly framed data but the payload isn't right given the message type
        let data: Vec<u8> = vec![0x55, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x65, 0x8D];
        let input = Cursor::new(data.clone());
        let mut msgs = iter_messages(input);
        if let Some(Err(Error::SbpMsgParseError(e))) = msgs.next() {
            let invalid = Invalid::from(e);
            assert_eq!(
                invalid,
                Invalid {
                    msg_id: Some(257),
                    sender_id: Some(257),
                    crc: Some(36197),
                    invalid_frame: data
                }
            )
        } else {
            panic!(
                "expecting unable to parse error because message is framed \
            but not valid"
            );
        }
        // msgs should be exhausted
        assert_eq!(msgs.count(), 0);
    }

    #[test]
    fn test_iter_messages() {
        let mut payload = vec![
            0x55u8, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff,
            0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf,
        ];
        payload.extend(payload.clone());
        let input = Cursor::new(payload);
        let mut count = 0;
        for msg in iter_messages(input) {
            assert!(msg.is_ok());
            count += 1;
        }
        assert_eq!(count, 2);
    }

    #[test]
    fn test_no_message_if_improperly_framed() {
        let corrupted_input: Vec<u8> = vec![
            0x55, 0x28, 0x61, 0xb2, 0x99, 0xba, 0xd6, 0x1d, 0x42, 0x15, 0xf7, 0x9f, 0x36, 0xf8,
            0xca, 0x72, 0x97, 0x41, 0xaf, 0x29, 0xb9, 0x0b, 0xf1, 0x0e, 0xd3, 0x1d, 0xef, 0xab,
            0xd4, 0x70, 0xac, 0x1e, 0x02, 0x71, 0xa0, 0x59, 0xc1, 0x78, 0x95, 0x5d, 0xf9, 0xe5,
            0xf9, 0x00, 0x6a, 0x38, 0x06, 0x69, 0x06, 0x8d, 0xf1, 0x80, 0xa3, 0xe2, 0xa1, 0x3c,
            0x6b, 0xab, 0x42, 0xe8, 0x18, 0x0a, 0xf0, 0x70,
        ];
        let mut msgs = iter_messages(Cursor::new(corrupted_input.clone()));
        match msgs.next() {
            None if corrupted_input[PAYLOAD_INDEX] as usize > corrupted_input.len() => {
                // in theory some day we want to recover here with a invalid message
                // however that will require a change to how framed reads are
                // taken in
            }
            _ => {
                panic!(
                    "Expecting None because the data are not large enough to hold the \
                expected frame"
                );
            }
        }
    }
    #[test]
    fn test_parse_crc_error() {
        let valid_message = vec![
            0x55, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff,
            0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf,
            0xde, 0xad, 0xbe, 0xef,
        ];

        // A mostly valid message
        let invalid_message_bytes = {
            let mut invalid = valid_message.clone();
            // add one to one of the bytes in the header to intentionally cause a CRC error
            invalid[1] += 1;
            invalid
        };

        let packet: Vec<_> = invalid_message_bytes
            .iter()
            .cloned()
            .chain(valid_message)
            .collect();

        let mut msgs = iter_messages(Cursor::new(packet));

        let crc_err = if let Some(Err(Error::CrcError(inner_err))) = msgs.next() {
            inner_err
        } else {
            panic!("expecting CrcError because CRC is incorrect.")
        };

        let invalid_msg = Invalid::from(crc_err);
        assert_eq!(
            invalid_msg,
            Invalid {
                msg_id: Some(524),
                sender_id: Some(35027),
                crc: Some(49115),
                // note that the message here is missing the values in
                // 28..32 (not sure if that is desired behavior but hard
                // to fix without more breaking changes)
                invalid_frame: invalid_message_bytes[0..28].to_vec(),
            }
        );

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
