pub mod client;
pub mod messages;

extern crate byteorder;
use self::byteorder::{LittleEndian,ReadBytesExt};
use std::io::{self, Read};

#[derive(Debug)]
pub enum Error {
    InvalidPreamble,
    CRCMismatch,
    ParseError,
    IoError(io::Error)
}

impl From<io::Error> for Error {
    fn from(error: io::Error) -> Self {
        Error::IoError(error)
    }
}

fn read_string(buf: &mut Read) -> Result<String, Error> {
    let mut s = String::new();
    buf.read_to_string(&mut s)?;
    Ok(s)
}

fn read_string_limit(buf: &mut Read, n: u64) -> Result<String, Error> {
    read_string(&mut buf.take(n))
}

fn read_u8_array(buf: &mut &[u8]) -> Result<Vec<u8>, Error> {
    Ok(buf.to_vec())
}

fn read_u8_array_limit(buf: &mut &[u8], n:usize) -> Result<Vec<u8>, Error> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_u8()?);
    }
    Ok(v)
}

fn read_double_array_limit(buf: &mut &[u8], n:usize) -> Result<Vec<f64>, Error> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_f64::<LittleEndian>()?);
    }
    Ok(v)
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
