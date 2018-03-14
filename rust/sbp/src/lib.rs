pub mod client;
pub mod messages;

extern crate byteorder;
use self::byteorder::{LittleEndian,ReadBytesExt};
use std::io::Read;

fn read_string(buf: &mut Read) -> String {
    let mut s = String::new();
    buf.read_to_string(&mut s).unwrap();
    s
}

fn read_string_limit(buf: &mut Read, n: u64) -> String {
    read_string(&mut buf.take(n))
}

fn read_u8_array(buf: &mut &[u8]) -> Vec<u8> {
    buf.to_vec()
}

fn read_u8_array_limit(buf: &mut &[u8], n:usize) -> Vec<u8> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_u8().unwrap())
    }
    v
}

fn read_double_array_limit(buf: &mut &[u8], n:usize) -> Vec<f64> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_f64::<LittleEndian>().unwrap())
    }
    v
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
