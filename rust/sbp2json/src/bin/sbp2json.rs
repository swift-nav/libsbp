use std::io;

use sbp::json::{CompactFormatter, HaskellishFloatFormatter};
use structopt::StructOpt;

use converters::{sbp2json, Result};

#[global_allocator]
static GLOBAL: mimalloc::MiMalloc = mimalloc::MiMalloc;

/// Convert binary SBP data to JSON.
///
/// Typical usage:
///
///     cat sbp.dat | sbp2json
///
/// Or combined with socat:
///
///     socat tcp:192.168.1.222:55555 - | sbp2json
#[derive(Debug, StructOpt)]
#[structopt(name = "sbp2json", verbatim_doc_comment)]
pub struct Options {
    /// Try to be compatible with the float formatting of the Haskell version of sbp2json
    #[structopt(long)]
    float_compat: bool,

    /// Print debugging messages to standard error
    #[structopt(short = "d", long)]
    debug: bool,

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
        sbp2json(
            stdin,
            stdout,
            HaskellishFloatFormatter {},
            options.buffered,
            options.fatal_errors,
        )
    } else {
        sbp2json(
            stdin,
            stdout,
            CompactFormatter {},
            options.buffered,
            options.fatal_errors,
        )
    }
}
