#[cfg(feature = "json")]
pub mod json;
pub mod sbp;

#[cfg(feature = "json")]
pub use json::{CompactFormatter, HaskellishFloatFormatter};

#[cfg(feature = "json")]
pub mod converters {
    use std::io::{Read, Write};

    use dencode::{Decoder, Encoder, FramedRead, FramedWrite, IterSinkExt};
    use serde_json::ser::Formatter;

    use crate::{
        codec::{
            json::{Json2JsonDecoder, Json2JsonEncoder, JsonDecoder, JsonEncoder},
            sbp::{SbpDecoder, SbpEncoder},
        },
        Error, Result,
    };

    pub fn json2sbp<R, W>(input: R, output: W, unbuffered: bool) -> Result<()>
    where
        R: Read,
        W: Write,
    {
        let source = FramedRead::new(input, JsonDecoder::new());
        let sink = FramedWrite::new(output, SbpEncoder::new());

        maybe_send_unbuffered(source, sink, unbuffered)?;

        Ok(())
    }

    pub fn json2json<R, W, F>(
        input: R,
        output: W,
        formatter: F,
        unbufferd: bool,
    ) -> Result<()>
    where
        R: Read,
        W: Write,
        F: Formatter + Clone,
    {
        let source = FramedRead::new(input, Json2JsonDecoder {});
        let sink = FramedWrite::new(output, Json2JsonEncoder::new(formatter));

        maybe_send_unbuffered(source, sink, unbufferd)?;

        Ok(())
    }

    pub fn sbp2json<R, W, F>(
        input: R,
        output: W,
        formatter: F,
        unbuffered: bool,
    ) -> Result<()>
    where
        R: Read,
        W: Write,
        F: Formatter + Clone,
    {
        let source = FramedRead::new(input, SbpDecoder {});
        let sink = FramedWrite::new(output, JsonEncoder::new(formatter));

        maybe_send_unbuffered(source, sink, unbuffered)?;

        Ok(())
    }

    fn maybe_send_unbuffered<R, W, D, E>(
        mut source: FramedRead<R, D>,
        mut sink: FramedWrite<W, E>,
        unbuffered: bool,
    ) -> Result<()>
    where
        R: Read,
        W: Write,
        D: Decoder<Item = E::Item, Error = Error>,
        E: Encoder<Error = Error>,
    {
        if unbuffered {
            while let Some(msg) = source.next() {
                sink.send(msg?)?;
            }
        } else {
            sink.send_all(source)?;
        }

        Ok(())
    }
}
