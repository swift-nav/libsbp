pub fn stdin() -> impl futures::AsyncRead {
    use tokio_util::compat::Tokio02AsyncReadCompatExt;
    tokio::io::stdin().compat()
}

pub fn stdout() -> impl futures::AsyncWrite {
    use tokio_util::compat::Tokio02AsyncWriteCompatExt;
    tokio::io::stdout().compat_write()
}
