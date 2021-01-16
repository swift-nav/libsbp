//! Simple parsing functionality for extracting SBP
//! messages from binary streams

extern crate byteorder;
extern crate nom;
use self::byteorder::{LittleEndian, ReadBytesExt};
use self::nom::bytes::complete::is_a;
use self::nom::error::ErrorKind;
use self::nom::multi::length_data;
use self::nom::number::complete::{le_u16, le_u8};
use self::nom::sequence::tuple;
use crate::messages::SBP;
use crate::{BoundedSbpString, UnboundedSbpString};
use crate::{Error, Result};
use std::convert::TryInto;
use std::io::{BufReader, Read};

const MSG_HEADER_LEN: usize = 1 /*preamble*/ + 2 /*msg_type*/ + 2 /*sender_id*/ + 1 /*len*/;

/// Attempts to extract a single SBP message from a data
/// slice
///
/// This function returns a tuple of a result and the
/// number of  bytes processed
/// from the slice. In regardless of the result the
/// processed bytes should be
/// removed from the slice before calling `frame()` again.
/// If the result is a
/// success then the SBP message has been fully validated.
pub fn frame(input: &[u8]) -> (Result<SBP>, usize) {
    if input.len() < MSG_HEADER_LEN {
        return (Err(crate::Error::NotEnoughData), 0);
    }

    let original_size = input.len();
    let preamble = is_a("\x55");
    let payload = length_data(le_u8);

    let result = tuple((preamble, le_u16, le_u16, payload, le_u16))(input);

    match result {
        Ok((o, (_preamble, msg_type, sender_id, payload, crc_in))) => {
            let mut crc = crc16::State::<crc16::XMODEM>::new();
            crc.update(&msg_type.to_le_bytes());
            crc.update(&sender_id.to_le_bytes());
            crc.update(&[payload.len() as u8]);
            crc.update(payload);
            if crc.get() == crc_in {
                let bytes_read = original_size - o.len();
                (
                    SBP::parse(msg_type, sender_id, &mut &payload[..]),
                    bytes_read,
                )
            } else {
                (Err(crate::Error::CrcError), 1)
            }
        }
        // Act like we didn't read anything
        Err(self::nom::Err::Incomplete(_)) => (Err(crate::Error::NotEnoughData), 0),
        // Act like we only read a single byte
        Err(self::nom::Err::Error((_data, kind))) => match kind {
            ErrorKind::Eof => (Err(crate::Error::NotEnoughData), 0),
            _ => (Err(crate::Error::ParseError), 1),
        },
        // Act like we didn't read anything
        Err(self::nom::Err::Failure((_, _))) => (Err(crate::Error::UnrecoverableFailure), 0),
    }
}

/// A basic parser for SBP messages
///
/// This object reads data from a source and attempts to
/// read SBP messages from
/// the stream. A Parser buffers some data locally to
/// reduce the number of
/// calls to read data.
pub struct Parser<R>
where
    R: Read,
{
    reader: BufReader<R>,
    buffer: Vec<u8>,
}

impl<R> Parser<R>
where
    R: Read,
{
    const BUF_SIZE: usize = 1024usize;

    /// Creates a new Parser object
    pub fn new(reader: R) -> Parser<R> {
        Parser {
            reader: BufReader::new(reader),
            buffer: vec![0; 0],
        }
    }

    /// Consumes the Parser object and returns the inner reader object
    pub fn into_inner(self) -> R {
        self.reader.into_inner()
    }

    /// Attempts to read a single SBP message from the
    /// input stream
    ///
    /// This function will read data from the input source
    /// as needed
    /// until either a message is successfully parsed or an
    /// error occurs
    pub fn parse(&mut self) -> Result<SBP> {
        if self.buffer.len() == 0 {
            self.read_more()?;
        }

        loop {
            match self.parse_remaining() {
                Ok(msg) => break Ok(msg),
                Err(crate::Error::NotEnoughData) => {
                    if let Err(e) = self.read_more() {
                        break Err(e);
                    }
                }
                Err(e) => break Err(e),
            };
        }
    }

    fn read_more(&mut self) -> Result<usize> {
        let mut local_buffer = vec![0; Self::BUF_SIZE];
        let read_bytes = self.reader.read(local_buffer.as_mut())?;
        if read_bytes == 0 {
            return Err(crate::Error::IoError(std::io::Error::new(
                std::io::ErrorKind::UnexpectedEof,
                "",
            )));
        }
        self.buffer.extend_from_slice(&local_buffer[..read_bytes]);
        Ok(read_bytes)
    }

    fn parse_remaining(&mut self) -> Result<SBP> {
        loop {
            let result = frame(&self.buffer);

            match result {
                (Ok(msg), bytes_read) => {
                    self.buffer = self.buffer[bytes_read..].to_vec();
                    break Ok(msg);
                }
                (Err(e), bytes_read) => {
                    if bytes_read >= self.buffer.len() {
                        self.buffer.clear()
                    } else {
                        self.buffer = self.buffer[bytes_read..].to_vec();
                    }

                    if let crate::Error::ParseError = e {
                        // Continue parsing
                    } else {
                        break Err(e);
                    }
                }
            }

            if self.buffer.is_empty() {
                break Err(crate::Error::NotEnoughData);
            }
        }
    }
}

pub(crate) trait SbpParse<T> {
    fn parse(&mut self) -> Result<T>;
}

impl SbpParse<u8> for &[u8] {
    fn parse(&mut self) -> Result<u8> {
        self.read_u8().map_err(|e| Error::IoError(e))
    }
}

impl SbpParse<i8> for &[u8] {
    fn parse(&mut self) -> Result<i8> {
        self.read_i8().map_err(|e| Error::IoError(e))
    }
}

impl SbpParse<u16> for &[u8] {
    fn parse(&mut self) -> Result<u16> {
        self.read_u16::<LittleEndian>()
            .map_err(|e| Error::IoError(e))
    }
}

impl SbpParse<i16> for &[u8] {
    fn parse(&mut self) -> Result<i16> {
        self.read_i16::<LittleEndian>()
            .map_err(|e| Error::IoError(e))
    }
}

impl SbpParse<u32> for &[u8] {
    fn parse(&mut self) -> Result<u32> {
        self.read_u32::<LittleEndian>()
            .map_err(|e| Error::IoError(e))
    }
}

impl SbpParse<i32> for &[u8] {
    fn parse(&mut self) -> Result<i32> {
        self.read_i32::<LittleEndian>()
            .map_err(|e| Error::IoError(e))
    }
}

impl SbpParse<u64> for &[u8] {
    fn parse(&mut self) -> Result<u64> {
        self.read_u64::<LittleEndian>()
            .map_err(|e| Error::IoError(e))
    }
}

impl SbpParse<i64> for &[u8] {
    fn parse(&mut self) -> Result<i64> {
        self.read_i64::<LittleEndian>()
            .map_err(|e| Error::IoError(e))
    }
}

impl SbpParse<f32> for &[u8] {
    fn parse(&mut self) -> Result<f32> {
        self.read_f32::<LittleEndian>()
            .map_err(|e| Error::IoError(e))
    }
}

impl SbpParse<f64> for &[u8] {
    fn parse(&mut self) -> Result<f64> {
        self.read_f64::<LittleEndian>()
            .map_err(|e| Error::IoError(e))
    }
}

impl<'a, T, const SIZE: usize> SbpParse<[T; SIZE]> for &'a [u8]
where
    &'a [u8]: SbpParse<T>,
{
    fn parse(&mut self) -> Result<[T; SIZE]> {
        let mut vec = Vec::new();
        for _ in 0..SIZE {
            vec.push(self.parse()?);
        }
        vec.try_into().map_err(|_| crate::Error::ParseError)
    }
}

impl<'a, T> SbpParse<Vec<T>> for &'a [u8]
where
    &'a [u8]: SbpParse<T>,
{
    fn parse(&mut self) -> Result<Vec<T>> {
        let mut vec = Vec::new();
        while self.len() > 0 {
            vec.push(self.parse()?);
        }
        Ok(vec)
    }
}

impl SbpParse<UnboundedSbpString> for &[u8] {
    fn parse(&mut self) -> Result<UnboundedSbpString> {
        self.try_into()
    }
}

impl<const SIZE: usize> SbpParse<BoundedSbpString<SIZE>> for &[u8] {
    fn parse(&mut self) -> Result<BoundedSbpString<SIZE>> {
        self.try_into()
    }
}

#[test]
fn test_read_string_invalid_utf8() {
    // (9 * 8) - 2 = 70
    let buf = vec![
        0x73, 0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f, 0x6e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb6,
    ];

    let mut slice = &buf[..];

    let sbp_string: UnboundedSbpString = (&mut slice).parse().unwrap();

    let string: String = sbp_string.clone().into();
    let vec: Vec<u8> = sbp_string.into();

    // The last 0xb6 get's transformed into 3 UTF-8 bytes (� aka U+FFFD REPLACEMENT CHARACTER)
    assert_eq!(string.len(), 69 + 3);
    assert_eq!(vec.len(), 70);
}

#[test]
fn test_read_string() {
    let v = b"hi, imma string";
    let mut slice = &v[..];

    let string: String = SbpParse::<UnboundedSbpString>::parse(&mut slice)
        .unwrap()
        .into();
    assert_eq!(string, "hi, imma string".to_string());

    let string: String = SbpParse::<UnboundedSbpString>::parse(&mut slice)
        .unwrap()
        .into();
    assert_eq!(string, "".to_string());

    let v = b"hi, imma string";
    let mut slice = &v[..];

    let string: String = SbpParse::<BoundedSbpString<8>>::parse(&mut slice)
        .unwrap()
        .into();
    assert_eq!(string, "hi, imma".to_string());

    let string: String = SbpParse::<BoundedSbpString<8>>::parse(&mut slice)
        .unwrap()
        .into();
    assert_eq!(string, " string\0".to_string());
}

#[test]
fn test_read_u16_array() {
    // A basic unit test for read_u16_array, LittleEndian convention assumed everywhere
    let mock_data: [u8; 4] = [0b00000001, 0b00010000, 0b00000010, 0b00000001];
    let mut expected_vec = Vec::with_capacity(2);
    // 0b00010000+0b00000001
    expected_vec.push(4097);
    expected_vec.push(258);
    let returned_vec: Vec<u16> = (&mut &mock_data[..]).parse().unwrap();
    assert_eq!(expected_vec, returned_vec);
}
