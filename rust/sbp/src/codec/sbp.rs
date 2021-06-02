use std::borrow::Borrow;

use bytes::{Buf, BufMut, BytesMut};
use dencode::{Decoder, Encoder, FramedRead, FramedWrite};

use crate::{
    messages::{SBPMessage, SBP},
    parser::{parse_sbp, ParseResult},
    Error, Result,
};

const MAX_FRAME_LENGTH: usize =
    crate::MSG_HEADER_LEN + crate::SBP_MAX_PAYLOAD_SIZE + crate::MSG_CRC_LEN;

const PREAMBLE: u8 = 0x55;

#[cfg(feature = "async")]
pub fn stream_messages<R: futures::AsyncRead + Unpin>(
    input: R,
) -> impl futures::Stream<Item = Result<SBP>> {
    FramedRead::new(input, SbpDecoder::new())
}

pub fn iter_messages<R: std::io::Read>(input: R) -> impl Iterator<Item = Result<SBP>> {
    FramedRead::new(input, SbpDecoder::new())
}

pub struct SbpDecoder {}

impl SbpDecoder {
    pub fn new() -> Self {
        Self {}
    }
}

impl Decoder for SbpDecoder {
    type Item = SBP;
    type Error = Error;

    fn decode(&mut self, src: &mut BytesMut) -> Result<Option<Self::Item>> {
        let start = match src.iter().position(|b| b == &PREAMBLE) {
            Some(idx) => idx,
            None => {
                src.clear();
                return Ok(None);
            }
        };

        src.advance(start);

        match parse_sbp(&src) {
            ParseResult::Ok((bytes_read, msg)) => {
                src.advance(bytes_read);
                log::trace!("{:?}", msg);
                Ok(Some(msg))
            }
            ParseResult::Err((bytes_read, err)) => {
                src.advance(bytes_read);
                Err(err)
            }
            ParseResult::Incomplete => {
                src.reserve(MAX_FRAME_LENGTH);
                Ok(None)
            }
        }
    }

    fn decode_eof(&mut self, buf: &mut BytesMut) -> Result<Option<Self::Item>> {
        let res = match self.decode(buf) {
            Ok(Some(frame)) => Ok(Some(frame)),
            _ => Ok(None),
        };
        buf.clear();
        res
    }
}

pub struct SbpEncoder {
    frame: Vec<u8>,
}

impl SbpEncoder {
    pub fn new() -> Self {
        SbpEncoder {
            frame: Vec::with_capacity(MAX_FRAME_LENGTH),
        }
    }

    pub fn framed<W>(writer: W) -> FramedWrite<W, Self> {
        FramedWrite::new(writer, Self::new())
    }
}

impl<T> Encoder<T> for SbpEncoder
where
    T: Borrow<SBP>,
{
    type Error = Error;

    fn encode(&mut self, msg: T, dst: &mut BytesMut) -> Result<()> {
        self.frame.clear();
        match msg.borrow().write_frame(&mut self.frame) {
            Ok(_) => dst.put_slice(self.frame.as_slice()),
            Err(err) => log::error!("Error converting sbp message to frame: {}", err),
        }
        Ok(())
    }
}
