use std::io::{Read, Write};

use sbp::{
    json::{Json2JsonEncoder, JsonEncoder},
    HandleParseError, SbpEncoder,
};
use serde_json::ser::Formatter;

pub type Result<T> = std::result::Result<T, Box<dyn std::error::Error + Send + Sync>>;

#[derive(Copy, Clone, Debug)]
pub enum ErrorHandlerOptions {
    ReturnOnFirstError,
    FilterOutErrors,
    CoerceErrorsToInvalidMsg,
}

impl std::str::FromStr for ErrorHandlerOptions {
    type Err = String;

    fn from_str(s: &str) -> std::result::Result<ErrorHandlerOptions, Self::Err> {
        match s {
            s if s.eq_ignore_ascii_case("Return") => Ok(ErrorHandlerOptions::ReturnOnFirstError),
            s if s.eq_ignore_ascii_case("Skip") => Ok(ErrorHandlerOptions::FilterOutErrors),
            s if s.eq_ignore_ascii_case("ToInvalid")
                | s.eq_ignore_ascii_case("to-invalid")
                | s.eq_ignore_ascii_case("to_invalid") =>
            {
                Ok(ErrorHandlerOptions::CoerceErrorsToInvalidMsg)
            }

            s => Err(format!(
                "Unable to cast option {} to a valid error handler option. \
                    Valid options are 'return', 'skip', & 'to-invalid')",
                s
            )),
        }
    }
}

/// Impl from bool for backwards compatibility
impl From<bool> for ErrorHandlerOptions {
    fn from(bool_flag: bool) -> Self {
        if bool_flag {
            Self::ReturnOnFirstError
        } else {
            Self::FilterOutErrors
        }
    }
}

/// This struct is a wrapper of an iter that returns messages or errors.
pub struct ErrorHandler<'a, T, E: std::error::Error + Send + Sync + HandleParseError<T>> {
    inner_iter: Box<dyn Iterator<Item = std::result::Result<T, E>> + 'a>,
    opts: ErrorHandlerOptions,
}

impl<'a, T, E: std::error::Error + Send + Sync + HandleParseError<T>> ErrorHandler<'a, T, E> {
    pub fn new(
        inner_iter: impl Iterator<Item = std::result::Result<T, E>> + 'a,
        opts: ErrorHandlerOptions,
    ) -> Self {
        Self {
            inner_iter: Box::new(inner_iter),
            opts,
        }
    }
}

impl<M, E: std::error::Error + Send + Sync + HandleParseError<M>> Iterator
    for ErrorHandler<'_, M, E>
{
    type Item = M;

    fn next(&mut self) -> Option<M> {
        match (self.opts, self.inner_iter.next()) {
            (_, None) => None,
            (_, Some(Ok(x))) => Some(x),
            (ErrorHandlerOptions::ReturnOnFirstError, Some(Err(e))) => {
                eprintln!("{e}");
                None
            }
            (ErrorHandlerOptions::FilterOutErrors, Some(Err(e))) => {
                eprintln!("{e}");
                self.next()
            }
            (ErrorHandlerOptions::CoerceErrorsToInvalidMsg, Some(Err(e))) => {
                eprintln!("{e}");
                Some(e.handle_parse_error())
            }
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
    let source = ErrorHandler::new(sbp::json::iter_messages(input), error_handler_opt.into());
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
    let source = ErrorHandler::new(
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
    let opt = error_handler_opt.into();
    if matches!(opt, ErrorHandlerOptions::CoerceErrorsToInvalidMsg) {
        unimplemented!(
            "We do not yet support coverting to invalid messages \
        in json2json."
        );
    }
    let source = ErrorHandler::new(sbp::json::iter_json2json_messages(input), opt);
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
    let source = ErrorHandler::new(sbp::iter_messages(input), error_handler_opt.into());
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
