#[cfg(feature = "json")]
pub mod json;
pub mod sbp;

#[cfg(feature = "json")]
pub use json::{CompactFormatter, HaskellishFloatFormatter};

#[cfg(feature = "json")]
pub mod converters {
    #[cfg(feature = "async")]
    use futures_codec::{FramedRead, FramedWrite};

    #[cfg(feature = "async")]
    use crate::{
        codec::{
            json::{Json2JsonDecoder, Json2JsonEncoder, JsonDecoder, JsonEncoder},
            sbp::{SbpDecoder, SbpEncoder},
        },
        Result,
    };

    #[cfg(feature = "async")]
    pub async fn json2sbp<R, W>(input: R, output: W) -> Result<()>
    where
        R: futures::AsyncRead + Unpin,
        W: futures::AsyncWrite + Unpin,
    {
        let source = FramedRead::new(input, JsonDecoder::new());
        let sink = FramedWrite::new(output, SbpEncoder::new());
        futures::StreamExt::forward(source, sink).await
    }

    #[cfg(feature = "async")]
    pub async fn json2json<R, W, F>(input: R, output: W, formatter: F) -> Result<()>
    where
        R: futures::AsyncRead + Unpin,
        W: futures::AsyncWrite + Unpin,
        F: serde_json::ser::Formatter + Clone,
    {
        let source = FramedRead::new(input, Json2JsonDecoder {});
        let sink = FramedWrite::new(output, Json2JsonEncoder::new(formatter));
        futures::StreamExt::forward(source, sink).await
    }

    #[cfg(feature = "async")]
    pub async fn sbp2json<R, W, F>(input: R, output: W, formatter: F) -> Result<()>
    where
        R: futures::AsyncRead + Unpin,
        W: futures::AsyncWrite + Unpin,
        F: serde_json::ser::Formatter + Clone,
    {
        let source = FramedRead::new(input, SbpDecoder::new());
        let sink = FramedWrite::new(output, JsonEncoder::new(formatter));
        futures::StreamExt::forward(source, sink).await
    }

    #[cfg(feature = "blocking")]
    pub mod blocking {
        use std::io::{Read, Write};

        use futures_codec::{FramedRead, FramedWrite, IterSinkExt};
        use serde_json::ser::Formatter;

        use crate::{
            codec::json::{Json2JsonDecoder, Json2JsonEncoder, JsonDecoder, JsonEncoder},
            Result,
        };

        pub fn json2sbp<R, W>(input: R, output: W) -> Result<()>
        where
            R: Read,
            W: Write,
        {
            let source = FramedRead::new_blocking(input, JsonDecoder::new());
            let mut sink = FramedWrite::new_blocking(output, crate::codec::sbp::SbpEncoder::new());
            sink.send_all(source)?;
            Ok(())
        }

        pub fn json2json<R, W, F>(input: R, output: W, formatter: F) -> Result<()>
        where
            R: Read,
            W: Write,
            F: Formatter + Clone,
        {
            let source = FramedRead::new_blocking(input, Json2JsonDecoder {});
            let mut sink = FramedWrite::new_blocking(output, Json2JsonEncoder::new(formatter));
            sink.send_all(source)?;
            Ok(())
        }

        pub fn sbp2json<R, W, F>(input: R, output: W, formatter: F) -> Result<()>
        where
            R: Read,
            W: Write,
            F: Formatter + Clone,
        {
            let source = FramedRead::new_blocking(input, crate::codec::sbp::SbpDecoder {});
            let mut sink = FramedWrite::new_blocking(output, JsonEncoder::new(formatter));
            sink.send_all(source)?;
            Ok(())
        }
    }
}
