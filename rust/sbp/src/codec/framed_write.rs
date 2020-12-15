use std::{
    io::{Error, ErrorKind},
    marker::Unpin,
    ops::{Deref, DerefMut},
    pin::Pin,
    task::{Context, Poll},
};

use bytes::{Buf, BytesMut};
use futures::{
    io::{AsyncRead, AsyncWrite},
    ready,
    sink::Sink,
};
use pin_project_lite::pin_project;

use super::{fuse::Fuse, Encoder};

// 2^17 bytes, which is slightly over 60% of the default
// TCP send buffer size (SO_SNDBUF)
const DEFAULT_SEND_HIGH_WATER_MARK: usize = 131072;

pin_project! {
    /// A `Sink` of frames encoded to an `AsyncWrite`.
    ///
    /// # Example
    /// ```
    /// use bytes::Bytes;
    /// use futures_codec::{FramedWrite, BytesCodec};
    /// use futures::SinkExt;
    ///
    /// # futures::executor::block_on(async move {
    /// let mut buf = Vec::new();
    /// let mut framed = FramedWrite::new(&mut buf, BytesCodec {});
    ///
    /// let bytes = Bytes::from("Hello World!");
    /// framed.send(bytes.clone()).await?;
    ///
    /// assert_eq!(&buf[..], &bytes[..]);
    /// # Ok::<_, std::io::Error>(())
    /// # }).unwrap();
    /// ```
    #[derive(Debug)]
    pub struct FramedWrite<T, E> {
        #[pin]
        inner: FramedWriteImpl<Fuse<T, E>>,
    }
}

impl<T, E> FramedWrite<T, E>
where
    T: AsyncWrite,
    E: Encoder,
{
    /// Creates a new `FramedWrite` transport with the given `Encoder`.
    pub fn new(inner: T, encoder: E) -> Self {
        Self {
            inner: FramedWriteImpl::new(Fuse::new(inner, encoder)),
        }
    }

    /// High-water mark for writes, in bytes
    ///
    /// The send *high-water mark* prevents the `FramedWrite`
    /// from accepting additional messages to send when its
    /// buffer exceeds this length, in bytes. Attempts to enqueue
    /// additional messages will be deferred until progress is
    /// made on the underlying `AsyncWrite`. This applies
    /// back-pressure on fast senders and prevents unbounded
    /// buffer growth.
    ///
    /// See [`set_send_high_water_mark()`](#method.set_send_high_water_mark).
    pub fn send_high_water_mark(&self) -> usize {
        self.inner.high_water_mark
    }

    /// Sets high-water mark for writes, in bytes
    ///
    /// The send *high-water mark* prevents the `FramedWrite`
    /// from accepting additional messages to send when its
    /// buffer exceeds this length, in bytes. Attempts to enqueue
    /// additional messages will be deferred until progress is
    /// made on the underlying `AsyncWrite`. This applies
    /// back-pressure on fast senders and prevents unbounded
    /// buffer growth.
    ///
    /// The default high-water mark is 2^17 bytes. Applications
    /// which desire low latency may wish to reduce this value.
    /// There is little point to increasing this value beyond
    /// your socket's `SO_SNDBUF` size. On linux, this defaults
    /// to 212992 bytes but is user-adjustable.
    pub fn set_send_high_water_mark(&mut self, hwm: usize) {
        self.inner.high_water_mark = hwm;
    }

    /// Release the I/O and Encoder
    pub fn release(self) -> (T, E) {
        let fuse = self.inner.release();
        (fuse.t, fuse.u)
    }

    /// Consumes the `FramedWrite`, returning its underlying I/O stream.
    ///
    /// Note that care should be taken to not tamper with the underlying stream
    /// of data coming in as it may corrupt the stream of frames otherwise
    /// being worked with.
    pub fn into_inner(self) -> T {
        self.release().0
    }

    /// Returns a reference to the underlying encoder.
    ///
    /// Note that care should be taken to not tamper with the underlying encoder
    /// as it may corrupt the stream of frames otherwise being worked with.
    pub fn encoder(&self) -> &E {
        &self.inner.u
    }

    /// Returns a mutable reference to the underlying encoder.
    ///
    /// Note that care should be taken to not tamper with the underlying encoder
    /// as it may corrupt the stream of frames otherwise being worked with.
    pub fn encoder_mut(&mut self) -> &mut E {
        &mut self.inner.u
    }
}

impl<T, E> Sink<E::Item> for FramedWrite<T, E>
where
    T: AsyncWrite + Unpin,
    E: Encoder,
{
    type Error = E::Error;

    fn poll_ready(self: Pin<&mut Self>, cx: &mut Context) -> Poll<Result<(), Self::Error>> {
        self.project().inner.poll_ready(cx)
    }
    fn start_send(self: Pin<&mut Self>, item: E::Item) -> Result<(), Self::Error> {
        self.project().inner.start_send(item)
    }
    fn poll_flush(self: Pin<&mut Self>, cx: &mut Context) -> Poll<Result<(), Self::Error>> {
        self.project().inner.poll_flush(cx)
    }
    fn poll_close(self: Pin<&mut Self>, cx: &mut Context) -> Poll<Result<(), Self::Error>> {
        self.project().inner.poll_close(cx)
    }
}

// impl<T, E> Deref for FramedWrite<T, E> {
//     type Target = T;

//     fn deref(&self) -> &T {
//         &self.inner
//     }
// }

// impl<T, E> DerefMut for FramedWrite<T, E> {
//     fn deref_mut(&mut self) -> &mut T {
//         &mut self.inner
//     }
// }

pin_project! {
    #[derive(Debug)]
    pub struct FramedWriteImpl<T> {
        #[pin]
        pub inner: T,
        pub high_water_mark: usize,
        buffer: BytesMut,
    }
}

impl<T> FramedWriteImpl<T> {
    pub fn new(inner: T) -> Self {
        FramedWriteImpl {
            inner,
            high_water_mark: DEFAULT_SEND_HIGH_WATER_MARK,
            buffer: BytesMut::with_capacity(1028 * 8),
        }
    }

    pub fn release(self) -> T {
        self.inner
    }
}

impl<T> Deref for FramedWriteImpl<T> {
    type Target = T;

    fn deref(&self) -> &T {
        &self.inner
    }
}

impl<T> DerefMut for FramedWriteImpl<T> {
    fn deref_mut(&mut self) -> &mut T {
        &mut self.inner
    }
}

impl<T: AsyncRead + Unpin> AsyncRead for FramedWriteImpl<T> {
    fn poll_read(
        self: Pin<&mut Self>,
        cx: &mut Context<'_>,
        buf: &mut [u8],
    ) -> Poll<Result<usize, Error>> {
        self.project().inner.poll_read(cx, buf)
    }
}

impl<T> Sink<T::Item> for FramedWriteImpl<T>
where
    T: AsyncWrite + Encoder + Unpin,
{
    type Error = T::Error;

    fn poll_ready(mut self: Pin<&mut Self>, cx: &mut Context) -> Poll<Result<(), Self::Error>> {
        let this = &mut *self;
        while this.buffer.len() >= this.high_water_mark {
            let num_write = ready!(Pin::new(&mut this.inner).poll_write(cx, &this.buffer))?;

            if num_write == 0 {
                return Poll::Ready(Err(err_eof().into()));
            }

            this.buffer.advance(num_write);
        }

        Poll::Ready(Ok(()))
    }
    fn start_send(mut self: Pin<&mut Self>, item: T::Item) -> Result<(), Self::Error> {
        let this = &mut *self;
        this.inner.encode(item, &mut this.buffer)
    }
    fn poll_flush(self: Pin<&mut Self>, cx: &mut Context) -> Poll<Result<(), Self::Error>> {
        let mut this = self.project();

        while !this.buffer.is_empty() {
            let num_write = ready!(Pin::new(&mut this.inner).poll_write(cx, &this.buffer))?;

            if num_write == 0 {
                return Poll::Ready(Err(err_eof().into()));
            }

            this.buffer.advance(num_write);
        }

        this.inner.poll_flush(cx).map_err(Into::into)
    }
    fn poll_close(mut self: Pin<&mut Self>, cx: &mut Context) -> Poll<Result<(), Self::Error>> {
        ready!(self.as_mut().poll_flush(cx))?;
        self.project().inner.poll_close(cx).map_err(Into::into)
    }
}

impl<T: super::Decoder> super::Decoder for FramedWriteImpl<T> {
    type Item = T::Item;
    type Error = T::Error;

    fn decode(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>, Self::Error> {
        self.inner.decode(src)
    }

    fn decode_eof(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>, Self::Error> {
        self.inner.decode_eof(src)
    }
}

fn err_eof() -> Error {
    Error::new(ErrorKind::UnexpectedEof, "End of file")
}
