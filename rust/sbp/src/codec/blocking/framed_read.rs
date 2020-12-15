use std::io::{self, Read};

use bytes::BytesMut;

use crate::codec::Decoder;

const INITIAL_CAPACITY: usize = 8 * 1024;

pub struct FramedRead<T, D> {
    inner: FramedReadImpl<T, D>,
}

impl<T, D> FramedRead<T, D>
where
    T: Read,
    D: Decoder,
{
    /// Creates a new `FramedRead` transport with the given `Decoder`.
    pub fn new(inner: T, decoder: D) -> Self {
        Self {
            inner: FramedReadImpl {
                inner,
                decoder,
                buffer: BytesMut::with_capacity(INITIAL_CAPACITY),
            },
        }
    }

    /// Release the I/O and Decoder
    pub fn release(self) -> (T, D) {
        self.inner.release()
    }

    /// Consumes the `FramedRead`, returning its underlying I/O stream.
    ///
    /// Note that care should be taken to not tamper with the underlying stream
    /// of data coming in as it may corrupt the stream of frames otherwise
    /// being worked with.
    pub fn into_inner(self) -> T {
        self.release().0
    }

    /// Returns a reference to the underlying decoder.
    ///
    /// Note that care should be taken to not tamper with the underlying decoder
    /// as it may corrupt the stream of frames otherwise being worked with.
    pub fn decoder(&self) -> &D {
        &self.inner.decoder
    }

    /// Returns a mutable reference to the underlying decoder.
    ///
    /// Note that care should be taken to not tamper with the underlying decoder
    /// as it may corrupt the stream of frames otherwise being worked with.
    pub fn decoder_mut(&mut self) -> &mut D {
        &mut self.inner.decoder
    }

    /// Returns a reference to the read buffer.
    pub fn buffer(&self) -> &BytesMut {
        &self.inner.buffer
    }
}

impl<T, D> Iterator for FramedRead<T, D>
where
    T: Read,
    D: Decoder,
    D::Error: From<io::Error>,
{
    type Item = Result<D::Item, D::Error>;

    fn next(&mut self) -> Option<Self::Item> {
        self.inner.next()
    }
}

struct FramedReadImpl<T, D> {
    inner: T,
    decoder: D,
    buffer: BytesMut,
}

impl<T, D> FramedReadImpl<T, D> {
    pub fn release(self) -> (T, D) {
        (self.inner, self.decoder)
    }
}

impl<T, D> Iterator for FramedReadImpl<T, D>
where
    T: Read,
    D: Decoder,
    D::Error: From<io::Error>,
{
    type Item = Result<D::Item, D::Error>;

    fn next(&mut self) -> Option<Self::Item> {
        match self.decoder.decode(&mut self.buffer) {
            Ok(Some(item)) => return Some(Ok(item)),
            Err(e) => return Some(Err(e)),
            Ok(None) => (),
        };

        let mut buf = [0u8; INITIAL_CAPACITY];

        loop {
            let n = match self.inner.read(&mut buf) {
                Ok(n) => n,
                Err(e) => return Some(Err(e.into())),
            };

            self.buffer.extend_from_slice(&buf[..n]);

            match self.decoder.decode(&mut self.buffer) {
                Ok(Some(item)) => return Some(Ok(item)),
                Ok(None) if n == 0 => return None,
                Err(e) => return Some(Err(e)),
                _ => continue,
            };
        }
    }
}
