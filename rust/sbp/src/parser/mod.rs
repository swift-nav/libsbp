//! Simple parsing functionality for extracting SBP
//! messages from binary streams

extern crate byteorder;
extern crate nom;
use self::byteorder::{LittleEndian, ReadBytesExt};
use self::nom::bytes::complete::is_a;
use self::nom::multi::length_data;
use self::nom::number::complete::{le_u16, le_u8};
use self::nom::sequence::tuple;
use crate::messages::SBP;
use crate::Result;
use std::io::Read;

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
    let original_size = input.len();
    let preamble = is_a("\x55");
    let payload = length_data(le_u8);

    let result = tuple((preamble, le_u16, le_u16, payload, le_u16))(input);

    match result {
        Ok((o, (_preamble, msg_type, sender_id, payload, _crc))) => {
            let mut crc = crc16::State::<crc16::XMODEM>::new();
            crc.update(&msg_type.to_le_bytes());
            crc.update(&sender_id.to_le_bytes());
            crc.update(&[payload.len() as u8]);
            crc.update(payload);
            if crc.get() == _crc {
                let bytes_read = original_size - o.len();
                (
                    SBP::parse(msg_type, sender_id, &mut &payload[..]),
                    bytes_read,
                )
            } else {
                (Err(crate::Error::ParseError), 1)
            }
        }
        // Act like we didn't read anything
        Err(self::nom::Err::Incomplete(_)) => (Err(crate::Error::NotEnoughData), 0),
        // Act like we only read a single byte
        Err(self::nom::Err::Error((_, _))) => (Err(crate::Error::ParseError), 1),
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
pub struct Parser {
    buffer: Vec<u8>,
}

impl Parser {
    const BUF_SIZE: usize = 1024usize;

    /// Creates a new Parser object
    pub fn new() -> Parser {
        Parser { buffer: vec![0; 0] }
    }

    /// Attempts to read a single SBP message from the
    /// input stream
    ///
    /// This function will read data from the input source
    /// as needed
    /// until either a message is successfully parsed or an
    /// error occurs
    pub fn parse<R: Read>(&mut self, input: &mut R) -> Result<SBP> {
        if self.buffer.len() == 0 {
            self.read_more(input)?;
        }

        loop {
            match self.parse_remaining() {
                Ok(msg) => break Ok(msg),
                Err(crate::Error::NotEnoughData) => {
                    if let Err(e) = self.read_more(input) {
                        break Err(e);
                    }
                }
                Err(e) => break Err(e),
            };
        }
    }

    fn read_more<R: Read>(&mut self, input: &mut R) -> Result<usize> {
        let mut local_buffer = vec![0; Parser::BUF_SIZE];
        let read_bytes = input.read(local_buffer.as_mut())?;
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
                (Err(crate::Error::ParseError), bytes_read) => {
                    if bytes_read >= self.buffer.len() {
                        self.buffer.clear()
                    } else {
                        self.buffer = self.buffer[bytes_read..].to_vec();
                    }
                }
                (Err(e), _bytes_read) => break Err(e),
            }

            if self.buffer.is_empty() {
                break Err(crate::Error::NotEnoughData);
            }
        }
    }
}

pub fn read_string(buf: &mut dyn Read) -> Result<String> {
    let mut s = String::new();
    buf.read_to_string(&mut s)?;
    Ok(s)
}

pub fn read_string_limit(buf: &mut dyn Read, n: u64) -> Result<String> {
    read_string(&mut buf.take(n))
}

pub fn read_u8_array(buf: &mut &[u8]) -> Result<Vec<u8>> {
    Ok(buf.to_vec())
}

pub fn read_u8_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<u8>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_u8()?);
    }
    Ok(v)
}

pub fn read_s8_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<i8>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_i8()?);
    }
    Ok(v)
}

pub fn read_s16_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<i16>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_i16::<LittleEndian>()?);
    }
    Ok(v)
}

pub fn read_u16_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<u16>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_u16::<LittleEndian>()?);
    }
    Ok(v)
}

pub fn read_float_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<f32>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_f32::<LittleEndian>()?);
    }
    Ok(v)
}

pub fn read_double_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<f64>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_f64::<LittleEndian>()?);
    }
    Ok(v)
}
