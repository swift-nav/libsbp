use std::io;

use bytes::{Buf, BytesMut};
use dencode::{Decoder, FramedRead};

use crate::{wire_format, Sbp, CRC_LEN, HEADER_LEN, MAX_FRAME_LEN, PREAMBLE};

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
    SbpDecoder::framed(input)
}

/// Deserialize the async IO stream into an stream of messages.
#[cfg(feature = "async")]
pub fn stream_messages<R: futures::AsyncRead + Unpin>(
    input: R,
) -> impl futures::Stream<Item = Result<Sbp, Error>> {
    SbpDecoder::framed(input)
}

pub fn parse_frame(buf: &mut BytesMut) -> Option<Result<Frame<BytesMut>, CrcError>> {
    if buf.len() < HEADER_LEN {
        return None;
    }
    // use a separate slice to parse the header so we don't advance the buffer
    // until we know we have enough bytes to parse the payload + crc
    let mut slice = &buf[1..];
    let msg_type = slice.get_u16_le();
    let sender_id = slice.get_u16_le();
    let payload_len = slice.get_u8() as usize;
    if slice.len() < payload_len + CRC_LEN {
        return None;
    }
    buf.advance(HEADER_LEN);
    let payload = buf.split_to(payload_len);
    let crc = buf.get_u16_le();
    if check_crc(msg_type, sender_id, &payload, crc) {
        Some(Ok(Frame {
            msg_type,
            sender_id,
            payload,
        }))
    } else {
        Some(Err(CrcError {
            msg_type,
            sender_id,
            crc,
        }))
    }
}

fn check_crc(msg_type: u16, sender_id: u16, payload: &[u8], crc_in: u16) -> bool {
    let mut crc = crc16::State::<crc16::XMODEM>::new();
    crc.update(&msg_type.to_le_bytes());
    crc.update(&sender_id.to_le_bytes());
    crc.update(&[payload.len() as u8]);
    crc.update(payload);
    crc.get() == crc_in
}

/// The wire representation of an SBP message.
#[derive(Debug)]
pub struct Frame<B> {
    pub msg_type: u16,
    pub sender_id: u16,
    pub payload: B,
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

#[derive(Debug, Clone, Default)]
struct SbpDecoder;

impl SbpDecoder {
    fn framed<W>(writer: W) -> FramedRead<W, SbpDecoder> {
        FramedRead::new(writer, SbpDecoder)
    }
}

impl Decoder for SbpDecoder {
    type Item = Sbp;
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
        match parse_frame(src) {
            Some(Ok(frame)) => Ok(Some(Sbp::from_frame(frame)?)),
            Some(Err(err)) => Err(err.into()),
            None => {
                src.reserve(MAX_FRAME_LEN);
                Ok(None)
            }
        }
    }

    fn decode_eof(&mut self, buf: &mut BytesMut) -> Result<Option<Self::Item>, Self::Error> {
        let res = match self.decode(buf) {
            Ok(Some(frame)) => Ok(Some(frame)),
            _ => Ok(None),
        };
        buf.clear();
        res
    }
}

#[cfg(test)]
mod tests {
    use std::{convert::TryInto, io::Cursor};

    use bytes::BufMut;

    use crate::{messages::navigation::MsgBaselineEcef, wire_format::WireFormat};

    use super::*;

    /// Test parsing when we don't have enough data for a frame message
    #[test]
    fn test_parse_frame_incomplete() {
        let packet = [
            0x55u8, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff,
            0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb,
        ];
        let missing_byte = 0xbf;
        let mut buf = BytesMut::from(&packet[..]);

        let res = parse_frame(&mut buf);
        assert!(res.is_none());
        assert_eq!(buf.len(), packet.len());

        buf.put_u8(missing_byte);

        let res = parse_frame(&mut buf).unwrap().unwrap();
        assert_eq!(res.msg_type, 523); // 0x020B
        assert_eq!(res.sender_id, 35027); // 0x88D3
        assert_eq!(
            res.payload,
            BytesMut::from(&packet[HEADER_LEN..packet.len() - 1])
        );
        assert!(buf.is_empty());
    }

    #[test]
    fn test_parse_nothing() {
        let data = vec![0u8; 1000];
        let mut bytes = BytesMut::from(&data[..]);
        assert_eq!(bytes.len(), 1000);
        assert!(matches!(SbpDecoder.decode(&mut bytes), Ok(None)));
        assert!(bytes.is_empty());
    }

    #[test]
    fn test_parse_bad_message() {
        // Properly framed data but the payload isn't right given the message type
        let data: Vec<u8> = vec![0x55, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x65, 0x8D];
        let mut bytes = BytesMut::from(&data[..]);
        let actual = SbpDecoder.decode(&mut bytes);
        assert!(matches!(actual, Err(Error::PayloadParseError(_))));
        assert!(bytes.is_empty());
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
        let mut packet = BytesMut::from(
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

        let msg = SbpDecoder.decode(&mut packet).unwrap().unwrap();
        assert!(packet.is_empty());

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
