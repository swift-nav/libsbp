//! Functionality for parsing/writing SBP message payloads with in memory buffers

use std::{
    self,
    mem::{self, MaybeUninit},
    ptr,
};

use bytes::{Buf, BufMut};

use crate::BUFLEN;

pub trait WireFormat: Sized {
    /// Minimum number of bytes this type will take in the frame.
    const MIN_LEN: usize = mem::size_of::<Self>();

    /// The actual number of bytes the type will take in the frame.
    fn len(&self) -> usize {
        Self::MIN_LEN
    }

    /// Write the type to a buffer.
    fn write<B: BufMut>(&self, buf: &mut B);

    /// Read the type out of a buffer, without checking any invariants.
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self;

    /// Read the type out of a buffer.
    fn parse<B: Buf>(buf: &mut B) -> Result<Self, PayloadParseError> {
        if buf.remaining() >= Self::MIN_LEN {
            Ok(Self::parse_unchecked(buf))
        } else {
            Err(PayloadParseError {})
        }
    }
}

impl<T> WireFormat for Vec<T>
where
    T: WireFormat,
{
    // A variable length array with no elements takes 0 bytes
    const MIN_LEN: usize = 0;

    fn len(&self) -> usize {
        self.iter().map(WireFormat::len).sum()
    }

    fn write<B: BufMut>(&self, buf: &mut B) {
        for item in self.iter() {
            item.write(buf);
        }
    }

    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        let mut v = Vec::with_capacity(BUFLEN);
        while buf.remaining() >= T::MIN_LEN {
            v.push(T::parse_unchecked(buf));
        }
        v
    }
}

impl<T, const LEN: usize> WireFormat for [T; LEN]
where
    T: WireFormat,
{
    const MIN_LEN: usize = T::MIN_LEN * LEN;

    fn write<B: BufMut>(&self, buf: &mut B) {
        for item in self {
            item.write(buf);
        }
    }

    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        // Safety: MaybeUninit`s do not require initialization so we can call assume_init()
        // https://doc.rust-lang.org/stable/std/mem/union.MaybeUninit.html#initializing-an-array-element-by-element
        let mut a: [MaybeUninit<T>; LEN] = unsafe { MaybeUninit::uninit().assume_init() };
        for el in &mut a[..] {
            unsafe {
                ptr::write(el.as_mut_ptr(), T::parse_unchecked(buf));
            }
        }
        // Safety: Everything is initialized
        unsafe { ptr::read(&a as *const _ as *const Self) }
    }
}

impl WireFormat for u8 {
    fn write<B: BufMut>(&self, buf: &mut B) {
        buf.put_u8(*self)
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        buf.get_u8()
    }
}

impl WireFormat for u16 {
    fn write<B: BufMut>(&self, buf: &mut B) {
        buf.put_u16_le(*self)
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        buf.get_u16_le()
    }
}

impl WireFormat for u32 {
    fn write<B: BufMut>(&self, buf: &mut B) {
        buf.put_u32_le(*self)
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        buf.get_u32_le()
    }
}

impl WireFormat for u64 {
    fn write<B: BufMut>(&self, buf: &mut B) {
        buf.put_u64_le(*self)
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        buf.get_u64_le()
    }
}

impl WireFormat for i8 {
    fn write<B: BufMut>(&self, buf: &mut B) {
        buf.put_i8(*self)
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        buf.get_i8()
    }
}

impl WireFormat for i16 {
    fn write<B: BufMut>(&self, buf: &mut B) {
        buf.put_i16_le(*self)
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        buf.get_i16_le()
    }
}

impl WireFormat for i32 {
    fn write<B: BufMut>(&self, buf: &mut B) {
        buf.put_i32_le(*self)
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        buf.get_i32_le()
    }
}

impl WireFormat for i64 {
    fn write<B: BufMut>(&self, buf: &mut B) {
        buf.put_i64_le(*self)
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        buf.get_i64_le()
    }
}

impl WireFormat for f32 {
    fn write<B: BufMut>(&self, buf: &mut B) {
        buf.put_f32_le(*self)
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        buf.get_f32_le()
    }
}

impl WireFormat for f64 {
    fn write<B: BufMut>(&self, buf: &mut B) {
        buf.put_f64_le(*self)
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        buf.get_f64_le()
    }
}

#[derive(Debug, Clone)]
pub struct PayloadParseError {}

impl std::fmt::Display for PayloadParseError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "error parsing payload")
    }
}

impl std::error::Error for PayloadParseError {}

#[cfg(test)]
mod tests {
    use bytes::BytesMut;

    use super::*;

    #[test]
    fn test_parse_u16_vec() {
        let mut buf = BytesMut::from(&[0b00000001, 0b00010000, 0b00000010, 0b00000001][..]);
        let expected = vec![4097, 258];
        let actual: Vec<u16> = WireFormat::parse_unchecked(&mut buf);
        assert_eq!(expected, actual);
        assert!(buf.is_empty());
    }

    #[test]
    fn test_parse_u16_array() {
        let mut buf = BytesMut::from(&[0b00000001, 0b00010000, 0b00000010, 0b00000001][..]);
        let expected = [4097, 258];
        let actual: [u16; 2] = WireFormat::parse_unchecked(&mut buf);
        assert_eq!(expected, actual);
        assert!(buf.is_empty());
    }
}
