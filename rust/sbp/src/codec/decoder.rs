use std::io::Error;

use bytes::BytesMut;

/// Decoding of frames via buffers, for use with `FramedRead`.
pub trait Decoder {
    /// The type of items returned by `decode`
    type Item;
    /// The type of decoding errors.
    type Error: From<Error>;

    /// Decode an item from the src `BytesMut` into an item
    fn decode(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>, Self::Error>;

    /// Called when the input stream reaches EOF, signaling a last attempt to decode
    ///
    /// # Notes
    ///
    /// The default implementation of this method invokes the `Decoder::decode` method.
    fn decode_eof(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>, Self::Error> {
        self.decode(src)
    }
}
