use std::io::{Read, Write};

use sbp::{
    json::{Json2JsonEncoder, JsonEncoder},
    SbpEncoder,
};
use serde_json::ser::Formatter;

pub type Result<T> = std::result::Result<T, Box<dyn std::error::Error + Send + Sync>>;

pub enum ErrorHandlerOptions {
    FailOnError,
    FilterOutErrors,
    CoerceToInvalidMsg,
}

/// Impl from bool for backwards compatibility
impl From<bool> for ErrorHandlerOptions {
    fn from(bool_flag: bool) -> Self {
        if bool_flag {
            Self::FailOnError
        } else {
            Self::FilterOutErrors
        }
    }
}

pub fn json2sbp<R, W>(
    input: R,
    output: W,
    buffered: bool,
    error_handler_opt: impl Into<ErrorHandlerOptions>,
) -> Result<()>
where
    R: Read,
    W: Write,
{
    let source = maybe_fatal_errors(sbp::json::iter_messages(input), error_handler_opt.into());
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

pub fn jsonfields2sbp<R, W>(
    input: R,
    output: W,
    buffered: bool,
    error_handler_opt: impl Into<ErrorHandlerOptions>,
) -> Result<()>
where
    R: Read,
    W: Write,
{
    let source = maybe_fatal_errors(
        sbp::json::iter_messages_from_fields(input),
        error_handler_opt.into(),
    );
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
    error_handler_opt: impl Into<ErrorHandlerOptions>,
) -> Result<()>
where
    R: Read,
    W: Write,
    F: Formatter + Clone,
{
    let source = maybe_fatal_errors(
        sbp::json::iter_json2json_messages(input),
        error_handler_opt.into(),
    );
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
    error_handler_opt: impl Into<ErrorHandlerOptions>,
) -> Result<()>
where
    R: Read,
    W: Write,
    F: Formatter + Clone,
{
    let source = maybe_fatal_errors(sbp::iter_messages(input), error_handler_opt.into());
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
    opts: ErrorHandlerOptions,
) -> Box<dyn Iterator<Item = M> + 'a>
where
    M: 'a,
    I: Iterator<Item = std::result::Result<M, E>> + 'a,
    E: std::error::Error + 'a,
{
    match opts {
        ErrorHandlerOptions::FailOnError => Box::new(
            messages
                .take_while(|m| m.as_ref().map_err(|e| eprintln!("{e}")).is_ok())
                .map(|m| m.unwrap()),
        ),
        ErrorHandlerOptions::FilterOutErrors => {
            Box::new(messages.filter_map(|m| m.map_err(|e| eprintln!("{e}")).ok()))
        }
        ErrorHandlerOptions::CoerceToInvalidMsg => {
            todo!("final part of this ticket");
        }
    }
}
