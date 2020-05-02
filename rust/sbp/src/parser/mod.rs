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
use std::io::{BufRead, Read};
use buf_redux::{BufReader, policy::MinBuffered};

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
        Err(self::nom::Err::Failure((_, _))) => (Err(crate::Error::UnrecoverableFailure), 1),
    }
}

/// A basic parser for SBP messages
///
/// This object reads data from a source and attempts to
/// read SBP messages from
/// the stream. A Parser buffers some data locally to
/// reduce the number of
/// calls to read data.
pub struct Parser<R: Read> {
    reader: BufReader<R, MinBuffered>,
}

impl<R: Read> Parser<R> {
    /// Creates a new Parser object
    pub fn new(reader: R) -> Self {
        Self {
            reader: BufReader::new(reader).set_policy(MinBuffered(MSG_HEADER_LEN)),
        }
    }

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
        loop {
            self.reader.fill_buf();
            let (result, bytes_read) = frame(self.reader.buffer());
            self.reader.consume(bytes_read);

            match result {
                Ok(msg) => break Ok(msg),
                Err(crate::Error::ParseError) => (),
                Err(crate::Error::NotEnoughData) => {
                    self.reader.make_room();
                    let prev_size = self.reader.buffer().len();
                    match self.reader.read_into_buf() {
                        Err(e) => break Err(crate::Error::IoError(e)),
                        Ok(read_count) => {
                            // If we need more data, but we've hit EOF (read count of 0)
                            // then there isn't anything more we can process
                            if read_count == 0 {
                                break Err(crate::Error::Eof);
                            }
                        }
                    }
                }
                Err(e) => break Err(e),
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
