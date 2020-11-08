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
use crate::Result;
use crate::SbpString;
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

pub(crate) fn read_string(buf: &mut &[u8]) -> Result<SbpString> {
    let amount = buf.len();
    let (head, tail) = buf.split_at(amount);
    *buf = tail;
    Ok(SbpString(head.to_vec()))
}

pub(crate) fn read_string_limit(buf: &mut &[u8], n: usize) -> Result<SbpString> {
    let n = std::cmp::min(n, buf.len());
    let (mut head, tail) = buf.split_at(n);
    read_string(&mut head).map(|sbp_string| {
        *buf = tail;
        sbp_string
    })
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

    let sbp_string = read_string(&mut slice).unwrap();

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

    let string: String = read_string(&mut slice).unwrap().into();
    assert_eq!(string, "hi, imma string".to_string());

    let string: String = read_string(&mut slice).unwrap().into();
    assert_eq!(string, "".to_string());

    let v = b"hi, imma string";
    let mut slice = &v[..];

    let string: String = read_string_limit(&mut slice, 8).unwrap().into();
    assert_eq!(string, "hi, imma".to_string());

    let string: String = read_string_limit(&mut slice, 8).unwrap().into();
    assert_eq!(string, " string".to_string());
}

pub(crate) fn read_u16_array(buf: &mut &[u8]) -> Result<Vec<u16>> {
    // buf is in fact an array of u16, so at least 2 u8 elem, unless buf is empty
    let iter = buf.chunks_exact(2);
    // collect() guarantees that it will return Err if at least one Err is found while iterating over the Vec
    // https://doc.rust-lang.org/std/iter/trait.FromIterator.html#method.from_iter-14
    // map_err necessary to convert the generic read_u16's Error into our Error enum type
    // LittleEndian means chunks are read from right-to-left
    let v = iter
        .map(|mut x| x.read_u16::<LittleEndian>().map_err(|e| e.into()))
        .collect();
    v
}

#[test]
fn test_read_u16_array() {
    // A basic unit test for read_u16_array, LittleEndian convention assumed everywhere
    let mock_data: [u8; 4] = [0b00000001, 0b00010000, 0b00000010, 0b00000001];
    let mut expected_vec = Vec::with_capacity(2);
    // 0b00010000+0b00000001
    expected_vec.push(4097);
    expected_vec.push(258);
    let returned_vec = read_u16_array(&mut &mock_data[..]).unwrap();
    assert_eq!(expected_vec, returned_vec);
}

pub(crate) fn read_u8_array(buf: &mut &[u8]) -> Result<Vec<u8>> {
    Ok(buf.to_vec())
}

pub(crate) fn read_u8_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<u8>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_u8()?);
    }
    Ok(v)
}

pub(crate) fn read_s8_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<i8>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_i8()?);
    }
    Ok(v)
}

pub(crate) fn read_s16_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<i16>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_i16::<LittleEndian>()?);
    }
    Ok(v)
}

pub(crate) fn read_u16_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<u16>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_u16::<LittleEndian>()?);
    }
    Ok(v)
}

pub(crate) fn read_float_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<f32>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_f32::<LittleEndian>()?);
    }
    Ok(v)
}

pub(crate) fn read_double_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<f64>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_f64::<LittleEndian>()?);
    }
    Ok(v)
}
