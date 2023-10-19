use std::fmt;
use std::fmt::Formatter;
use std::marker::PhantomData;

use bytes::{Buf, BufMut};
#[cfg(feature = "serde")]
use serde::de::{Error, Visitor};

use crate::wire_format::WireFormat;

/// Fixed or variable length string and its encoding.
#[derive(Debug, Eq, PartialEq, Clone)]
pub struct SbpString<T, E = Unterminated> {
    data: T,
    encoding: PhantomData<E>,
}

impl<T, E> SbpString<T, E>
where
    T: AsRef<[u8]>,
{
    /// Creates a new SbpString with a given encoding.
    /// Does not check validity of data with encoding.
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

impl<T: AsRef<[u8]>> SbpString<T, Unterminated> {
    /// Checked unterminated SbpString builder,
    pub fn unterminated(data: T) -> Self {
        SbpString::new(data)
    }
}

impl<T: AsRef<[u8]>> SbpString<T, NullTerminated> {
    pub fn null_terminated(data: T) -> Result<Self, NullTerminatedError> {
        match data.as_ref().last() {
            Some(&0) => Ok(Self::new(data)),
            _ => Err(NullTerminatedError),
        }
    }
}

/// Helper function to alternate null bytes
/// Used in [`SbpString::from_parts`]
///
/// Ex. [a, b, c] => [a, 0, b, 0, c, 0]
///
/// Returns null terminated vector
fn alt_null<R, I>(parts: I) -> Vec<u8>
where
    R: AsRef<[u8]>,
    I: IntoIterator<Item = R>,
{
    parts.into_iter().fold(Vec::new(), |mut acc, part| {
        acc.extend_from_slice(part.as_ref());
        acc.push(0);
        acc
    })
}

pub type Parts<'a> = std::slice::Split<'a, u8, fn(&u8) -> bool>;

impl SbpString<Vec<u8>, Multipart> {
    pub fn multipart(data: impl Into<Vec<u8>>) -> Result<Self, MultipartError> {
        let data = data.into();
        match data.last() {
            Some(&0) => Ok(Self::new(data)),
            _ => Err(MultipartError),
        }
    }

    /// Unchecked from parts builder to construct Multipart SbpString
    pub fn from_parts(parts: impl IntoIterator<Item = impl AsRef<[u8]>>) -> Self {
        SbpString::new(alt_null(parts))
    }

    /// Returns an iterator over the parts of the string.
    pub fn parts(&self) -> Parts<'_> {
        let slice = self.data.as_slice();
        slice[0..slice.len() - 1].split(|a| a == &0)
    }
}

impl SbpString<Vec<u8>, DoubleNullTerminated> {
    pub fn double_null_terminated(
        data: impl Into<Vec<u8>>,
    ) -> Result<Self, DoubleNullTerminatedError> {
        let vec = data.into();
        if let [.., two, one] = vec.as_slice() {
            if two == &0 && one == &0 {
                return Ok(SbpString::new(vec));
            }
        };
        Err(DoubleNullTerminatedError)
    }

    pub fn from_parts(parts: impl IntoIterator<Item = impl AsRef<[u8]>>) -> Self {
        let mut alt = alt_null(parts);
        alt.push(0);
        SbpString::new(alt)
    }

    /// Returns an iterator over the parts of the string.
    pub fn parts(&self) -> Parts<'_> {
        let slice = self.data.as_slice();
        slice[0..slice.len() - 2].split(|a| a == &0)
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

#[cfg(feature = "serde")]
impl<'de, E> serde::Deserialize<'de> for SbpString<Vec<u8>, E> {
    fn deserialize<D>(deserializer: D) -> Result<Self, D::Error>
    where
        D: serde::Deserializer<'de>,
    {
        struct SbpStringVisitor<E>(PhantomData<SbpString<Vec<u8>, E>>);

        impl<'de, E> Visitor<'de> for SbpStringVisitor<E> {
            type Value = SbpString<Vec<u8>, E>;

            fn expecting(&self, formatter: &mut fmt::Formatter) -> fmt::Result {
                formatter.write_str("string")
            }

            fn visit_str<Er>(self, v: &str) -> Result<Self::Value, Er>
            where
                Er: Error,
            {
                Ok(SbpString::new(v.as_bytes().to_vec()))
            }

            fn visit_string<Er>(self, v: String) -> Result<Self::Value, Er>
            where
                Er: Error,
            {
                Ok(SbpString::new(v.into_bytes()))
            }

            fn visit_bytes<Er>(self, v: &[u8]) -> Result<Self::Value, Er>
            where
                Er: Error,
            {
                Ok(SbpString::new(v.to_vec()))
            }

            fn visit_byte_buf<Er>(self, v: Vec<u8>) -> Result<Self::Value, Er>
            where
                Er: Error,
            {
                Ok(SbpString::new(v))
            }
        }
        deserializer.deserialize_any(SbpStringVisitor(PhantomData))
    }
}

#[cfg(feature = "serde")]
impl<'de, E, const LEN: usize> serde::Deserialize<'de> for SbpString<[u8; LEN], E> {
    fn deserialize<D>(deserializer: D) -> Result<Self, D::Error>
    where
        D: serde::Deserializer<'de>,
    {
        use std::convert::TryInto;

        struct SbpStringVisitor<E, const LEN: usize>(PhantomData<SbpString<[u8; LEN], E>>);

        impl<'de, E, const LEN: usize> Visitor<'de> for SbpStringVisitor<E, LEN> {
            type Value = SbpString<[u8; LEN], E>;

            fn expecting(&self, formatter: &mut fmt::Formatter) -> fmt::Result {
                formatter.write_str("string")
            }

            fn visit_str<Er>(self, v: &str) -> Result<Self::Value, Er>
            where
                Er: Error,
            {
                let data = v.as_bytes().try_into().map_err(|_| {
                    Error::custom(format!("was expecting a string of length {LEN}"))
                })?;
                Ok(SbpString::new(data))
            }

            fn visit_string<Er>(self, v: String) -> Result<Self::Value, Er>
            where
                Er: Error,
            {
                let data = v.into_bytes().try_into().map_err(|_| {
                    Error::custom(format!("was expecting a string of length {LEN}"))
                })?;
                Ok(SbpString::new(data))
            }

            fn visit_bytes<Er>(self, v: &[u8]) -> Result<Self::Value, Er>
            where
                Er: Error,
            {
                let data = v.try_into().map_err(|_| {
                    Error::custom(format!("was expecting a string of length {LEN}"))
                })?;
                Ok(SbpString::new(data))
            }

            fn visit_byte_buf<Er>(self, v: Vec<u8>) -> Result<Self::Value, Er>
            where
                Er: Error,
            {
                let data = v.try_into().map_err(|_| {
                    Error::custom(format!("was expecting a string of length {LEN}"))
                })?;
                Ok(SbpString::new(data))
            }
        }
        deserializer.deserialize_any(SbpStringVisitor(PhantomData))
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

#[derive(Debug, Eq, PartialEq, Clone)]
pub struct MultipartError;

impl std::error::Error for MultipartError {}

impl std::fmt::Display for MultipartError {
    fn fmt(&self, f: &mut Formatter<'_>) -> fmt::Result {
        writeln!(f, "failed multipart string validation")
    }
}

#[derive(Debug, Eq, PartialEq, Clone)]
pub struct NullTerminatedError;

impl std::error::Error for NullTerminatedError {}

impl std::fmt::Display for NullTerminatedError {
    fn fmt(&self, f: &mut Formatter<'_>) -> fmt::Result {
        writeln!(f, "failed null terminated string validation")
    }
}

#[derive(Debug, Eq, PartialEq, Clone)]
pub struct DoubleNullTerminatedError;

impl std::error::Error for DoubleNullTerminatedError {}

impl std::fmt::Display for DoubleNullTerminatedError {
    fn fmt(&self, f: &mut Formatter<'_>) -> fmt::Result {
        writeln!(f, "failed double null terminated string validation")
    }
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
#[derive(Debug, Eq, PartialEq, Clone, Copy)]
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
#[derive(Debug, Eq, PartialEq, Clone, Copy)]
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
#[derive(Debug, Eq, PartialEq, Clone, Copy)]
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
#[derive(Debug, Eq, PartialEq, Clone, Copy)]
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

    #[test]
    fn test_null_terminated_sbp_string_builder() {
        let nonnull = SbpString::null_terminated([0x1, 0x1]);
        assert!(nonnull.is_err());

        let data = &[0x1, 0x0][..];
        let null = SbpString::null_terminated(data);
        assert!(null.is_ok());
        assert_eq!(null.unwrap().data, data);
    }

    #[test]
    fn test_multipart_sbp_string_builder() {
        // Direct byte construction section
        // -----
        // representation of [a, 0, b, 0, c] as u8's delimited by 0
        // non null termination should fail multipart validation
        let nonnull: [u8; 5] = [0x61, 0, 0x62, 0, 0x63];
        let fail = SbpString::multipart(nonnull);
        assert!(fail.is_err());

        // null terminated should pass multipart validation
        let null: [u8; 6] = [0x61, 0, 0x62, 0, 0x63, 0];
        let pass = SbpString::multipart(null);
        assert!(pass.is_ok());
        assert_eq!(pass.unwrap().data, null);

        // Auto generate alternating bytes [`from_parts`] section
        // -----
        let parts = ["a", "b", "c"];
        let multipart = SbpString::<_, Multipart>::from_parts(parts);
        assert_eq!(multipart.data, null);

        // Test [`parts`] section
        // -----
        let actual = multipart
            .parts()
            .map(String::from_utf8_lossy)
            .map(|c| c.to_string())
            .collect::<Vec<String>>();
        assert_eq!(actual, parts);
    }

    #[test]
    fn test_double_null_terminated_sbp_string_builder() {
        // Direct byte construction section
        // -----
        // representation of [a, 0, b, 0, c] as u8's delimited by 0
        // non null termination should fail double null validation
        let nonnull: [u8; 5] = [0x61, 0, 0x62, 0, 0x63];
        let fail = SbpString::double_null_terminated(nonnull);
        assert!(fail.is_err());

        // representation of [a, 0, b, 0, c, 0] as u8's delimited by 0
        // single null termination should fail double null validation
        let single_null: [u8; 6] = [0x61, 0, 0x62, 0, 0x63, 0];
        let fail = SbpString::double_null_terminated(single_null);
        assert!(fail.is_err());

        // double null terminated should pass multipart validation
        let data: [u8; 7] = [0x61, 0, 0x62, 0, 0x63, 0, 0];
        let pass = SbpString::multipart(data);
        assert!(pass.is_ok());
        assert_eq!(pass.unwrap().data, data);

        // Auto generate alternating bytes [`from_parts`] section
        // -----
        let parts = ["a", "b", "c"];
        let double_null = SbpString::<_, DoubleNullTerminated>::from_parts(parts);
        assert_eq!(double_null.data, data);

        // Test [`parts`] section
        // -----
        let actual_parts = double_null
            .parts()
            .map(String::from_utf8_lossy)
            .map(|c| c.to_string())
            .collect::<Vec<String>>();
        assert_eq!(actual_parts, parts);
    }
}
