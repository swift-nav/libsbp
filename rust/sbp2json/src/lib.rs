use std::io::{Read, Write};

use sbp::{
    json::{Json2JsonEncoder, JsonEncoder},
    SbpEncoder,
};
use serde_json::ser::Formatter;

pub type Result<T> = std::result::Result<T, Box<dyn std::error::Error + Send + Sync>>;

pub fn json2sbp<R, W>(input: R, output: W, buffered: bool, fatal_errors: bool) -> Result<()>
where
    R: Read,
    W: Write,
{
    let source = maybe_fatal_errors(sbp::json::iter_messages(input), fatal_errors);
    let mut sink = SbpEncoder::new(output);
    if buffered {
        sink.send_all(source)?;
    } else {
        for msg in source {
            sink.send(&msg)?;
        }
    }
    Ok(())
}

pub fn json2json<R, W, F>(
    input: R,
    output: W,
    formatter: F,
    buffered: bool,
    fatal_errors: bool,
) -> Result<()>
where
    R: Read,
    W: Write,
    F: Formatter + Clone,
{
    let source = maybe_fatal_errors(sbp::json::iter_json2json_messages(input), fatal_errors);
    let mut sink = Json2JsonEncoder::new(output, formatter);
    if buffered {
        sink.send_all(source)?;
    } else {
        for msg in source {
            sink.send(msg)?;
        }
    }
    Ok(())
}

pub fn sbp2json<R, W, F>(
    input: R,
    output: W,
    formatter: F,
    buffered: bool,
    fatal_errors: bool,
) -> Result<()>
where
    R: Read,
    W: Write,
    F: Formatter + Clone,
{
    let source = maybe_fatal_errors(sbp::iter_messages(input), fatal_errors);
    let mut sink = JsonEncoder::new(output, formatter);
    if buffered {
        sink.send_all(source)?;
    } else {
        for msg in source {
            sink.send(&msg)?;
        }
    }
    Ok(())
}

fn maybe_fatal_errors<'a, M, I, E>(
    messages: I,
    fatal_errors: bool,
) -> Box<dyn Iterator<Item = M> + 'a>
where
    M: 'a,
    I: Iterator<Item = std::result::Result<M, E>> + 'a,
    E: std::error::Error + 'a,
{
    if fatal_errors {
        Box::new(messages.take_while(|m| m.is_ok()).map(|m| m.unwrap()))
    } else {
        Box::new(messages.filter_map(|m| m.ok()))
    }
}
