use std::io;

use sbp::json::{CompactFormatter, HaskellishFloatFormatter};
use structopt::StructOpt;

use converters::{json2json, Result};

#[global_allocator]
static GLOBAL: mimalloc::MiMalloc = mimalloc::MiMalloc;

/// Convert "compact" SBP JSON data to an "exploded" form
///
/// Typical usage:
///
///     cat console-json-log.json | json2json
#[derive(Debug, StructOpt)]
#[structopt(name = "json2json", verbatim_doc_comment)]
struct Options {
    /// Print debugging messages to standard error
    #[structopt(long)]
    debug: bool,

    /// Try to be compatible with the float formatting of the Haskell version of sbp2json
    #[structopt(long = "float-compat")]
    float_compat: bool,

    /// Buffer output before flushing
    #[structopt(short, long)]
    buffered: bool,

    /// Stop on first error encountered
    #[structopt(long)]
    fatal_errors: bool,
}

fn main() -> Result<()> {
    let options = Options::from_args();

    if options.debug {
        std::env::set_var("RUST_LOG", "debug");
    }

    env_logger::init();

    let stdin = io::stdin();
    let stdout = io::stdout();

    if options.float_compat {
        json2json(
            stdin,
            stdout,
            HaskellishFloatFormatter {},
            options.buffered,
            options.fatal_errors,
        )
    } else {
        json2json(
            stdin,
            stdout,
            CompactFormatter {},
            options.buffered,
            options.fatal_errors,
        )
    }
}
