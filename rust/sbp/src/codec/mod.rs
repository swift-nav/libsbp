#[cfg(feature = "json")]
pub mod json;
pub mod sbp;

#[cfg(feature = "json")]
pub use json::{CompactFormatter, HaskellishFloatFormatter};

#[cfg(feature = "json")]
pub mod converters {
    use std::io::{Read, Write};

    use dencode::{FramedRead, FramedWrite, IterSinkExt};
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
        let source = FramedRead::new(input, JsonDecoder::new());
        let mut sink = FramedWrite::new(output, crate::codec::sbp::SbpEncoder::new());
        sink.send_all(source)?;
        Ok(())
    }

    pub fn json2json<R, W, F>(input: R, output: W, formatter: F) -> Result<()>
    where
        R: Read,
        W: Write,
        F: Formatter + Clone,
    {
        let source = FramedRead::new(input, Json2JsonDecoder {});
        let mut sink = FramedWrite::new(output, Json2JsonEncoder::new(formatter));
        sink.send_all(source)?;
        Ok(())
    }

    pub fn sbp2json<R, W, F>(input: R, output: W, formatter: F) -> Result<()>
    where
        R: Read,
        W: Write,
        F: Formatter + Clone,
    {
        let source = FramedRead::new(input, crate::codec::sbp::SbpDecoder {});
        let mut sink = FramedWrite::new(output, JsonEncoder::new(formatter));
        sink.send_all(source)?;
        Ok(())
    }
}
