use std::fmt;
use std::marker::PhantomData;

use bytes::{Buf, BufMut};

use crate::wire_format::WireFormat;

/// Fixed or variable length string and its encoding.
#[derive(Debug, Clone)]
pub struct SbpString<T, E = Unterminated> {
    data: T,
    encoding: PhantomData<E>,
}

impl<T, E> SbpString<T, E>
where
    T: AsRef<[u8]>,
{
    /// Creates a new SbpString.
    pub fn new(data: T) -> Self {
        Self {
            data,
            encoding: PhantomData,
        }
    }

    /// Returns a byte slice of this SbpString's contents.
    pub fn as_bytes(&self) -> &[u8] {
        self.data.as_ref()
    }

    /// Returns a byte vector of this SbpString's contents.
    pub fn to_vec(&self) -> Vec<u8> {
        self.data.as_ref().to_vec()
    }
}

impl<E> From<String> for SbpString<Vec<u8>, E> {
    fn from(s: String) -> Self {
        SbpString::new(s.into_bytes())
    }
}

impl<E> From<Vec<u8>> for SbpString<Vec<u8>, E> {
    fn from(v: Vec<u8>) -> Self {
        SbpString::new(v)
    }
}

impl<T, E> fmt::Display for SbpString<T, E>
where
    T: AsRef<[u8]>,
{
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{}", String::from_utf8_lossy(self.as_bytes()))
    }
}

#[cfg(feature = "serde")]
impl<T, E> serde::Serialize for SbpString<T, E>
where
    T: AsRef<[u8]>,
{
    fn serialize<S>(&self, serializer: S) -> Result<S::Ok, S::Error>
    where
        S: serde::Serializer,
    {
        let s = String::from_utf8_lossy(self.as_bytes());
        serializer.serialize_str(&s)
    }
}

impl<E, const LEN: usize> WireFormat for SbpString<[u8; LEN], E> {
    const MIN_LEN: usize = LEN;

    fn len(&self) -> usize {
        LEN
    }

    fn write<B: BufMut>(&self, buf: &mut B) {
        self.data.write(buf)
    }

    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        let data: [u8; LEN] = WireFormat::parse_unchecked(buf);
        SbpString::new(data)
    }
}

macro_rules! forward_payload_vec {
    ($encoding:ty, $min_len:expr) => {
        impl WireFormat for SbpString<Vec<u8>, $encoding> {
            const MIN_LEN: usize = $min_len;

            fn len(&self) -> usize {
                self.data.len()
            }

            fn write<B: BufMut>(&self, buf: &mut B) {
                self.data.write(buf)
            }

            fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
                let data: Vec<u8> = WireFormat::parse_unchecked(buf);
                SbpString::new(data)
            }
        }
    };
}

/// Handles encoding and decoding of unterminated strings.
///
/// In SBP an unterminated string is a sequence of characters without a NULL
/// terminator to indicate the end of the string. Unterminated strings can only
/// appear at the end of an SBP payload, their length is indicated by the
/// remaining length of payload when processing incoming data.
///
/// For example, the string "text" would be represented on the wire as
///
/// text
#[derive(Debug, Clone, Copy)]
pub struct Unterminated;

forward_payload_vec!(Unterminated, 0);

/// Handles encoding and decoding of NULL terminated strings.
///
/// In SBP a NULL terminated string has the same definition as string in the C
/// language. On the wire it is a sequence of characters with a NULL character to
/// indicate the end of the string.
///
/// For example the string "text" would be represented on the wire as
///
/// text\0
#[derive(Debug, Clone, Copy)]
pub struct NullTerminated;

forward_payload_vec!(NullTerminated, 1);

/// Handles encoding and decoding of multipart strings.
///
/// In SBP a multipart string is not a single C string but a collection of
/// smaller strings (or sections) each separated by a NULL character.
///
/// For example, a multipart string might contain 3 sections - "one", "two", and
/// "three". On the wire this string would be encoded as
///
/// one\0two\0three\0
///
/// for a total of 14 bytes.
///
/// A multipart string might contain no sections in which case on the wire it
/// would consist of just a single NULL character.
#[derive(Debug, Clone, Copy)]
pub struct Multipart;

forward_payload_vec!(Multipart, 0);

/// Handles encoding and decoding of double NULL terminated strings.
///
/// In SBP double NULL terminated strings are rather similar to multipart strings
/// except they have an extra NULL terminator at the end of a sequence. A double
/// NULL terminated string is not a single C style string, rather it is a
/// collection of substrings (or sections) each separated on the wire with a NULL
/// terminator with the end of sequence being marked by an extra NULL terminator.
///
/// For example, a double NULL terminated string might contain 3 sections -
/// "one", "two", and "three". On the wire this string would be encoded as
///
/// one\0two\0three\0\0
///
/// for a total of 15 bytes.
///
/// A double NULL terminated string might contain no sections in which case on
/// the wire it would consists of just two NULL terminators with no printable
/// text.
#[derive(Debug, Clone, Copy)]
pub struct DoubleNullTerminated;

forward_payload_vec!(DoubleNullTerminated, 2);

#[cfg(test)]
mod tests {
    use bytes::BytesMut;

    use super::*;

    #[test]
    fn test_parse_sbp_string_vec() {
        let mut buf = BytesMut::from(&b"hi, imma string"[..]);

        let actual: SbpString<Vec<u8>> = WireFormat::parse_unchecked(&mut buf);
        assert_eq!(actual.to_string(), "hi, imma string".to_string());
        assert!(buf.is_empty());

        let actual: SbpString<Vec<u8>> = WireFormat::parse_unchecked(&mut buf);
        assert_eq!(actual.to_string(), "".to_string());
    }

    #[test]
    fn test_parse_sbp_string_array() {
        let mut buf = BytesMut::from(&b"hi, imma string"[..]);

        let actual: SbpString<[u8; 8]> = WireFormat::parse_unchecked(&mut buf);
        assert_eq!(actual.to_string(), "hi, imma".to_string());
        assert_eq!(buf.len(), 7);

        let actual: SbpString<[u8; 7]> = WireFormat::parse_unchecked(&mut buf);
        assert_eq!(actual.to_string(), " string".to_string());
        assert!(buf.is_empty());
    }

    #[test]
    fn test_parse_sbp_string_invalid_utf8() {
        // (9 * 8) - 2 = 70
        let mut buf = BytesMut::from(
            &[
                0x73, 0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f, 0x6e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb6,
            ][..],
        );

        let sbp_string: SbpString<Vec<u8>> = WireFormat::parse_unchecked(&mut buf);
        // The last 0xb6 get's transformed into 3 UTF-8 bytes (� aka U+FFFD REPLACEMENT CHARACTER)
        assert_eq!(sbp_string.to_string().len(), 69 + 3);
        assert_eq!(sbp_string.to_vec().len(), 70);
    }
}
