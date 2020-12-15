use std::io::Error;

use bytes::BytesMut;

/// Encoding of messages as bytes, for use with `FramedWrite`.
pub trait Encoder {
    /// The type of items consumed by `encode`
    type Item;
    /// The type of encoding errors.
    type Error: From<Error>;

    /// Encodes an item into the `BytesMut` provided by dst.
    fn encode(&mut self, item: Self::Item, dst: &mut BytesMut) -> Result<(), Self::Error>;
}
