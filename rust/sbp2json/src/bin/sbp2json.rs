use std::io;

use sbp::codec::{converters::sbp2json, CompactFormatter, HaskellishFloatFormatter};
use structopt::StructOpt;

#[cfg(all(not(windows), not(target_env = "musl")))]
#[global_allocator]
static ALLOC: jemallocator::Jemalloc = jemallocator::Jemalloc;

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

    /// Flush output on every message
    #[structopt(long = "unbuffered")]
    unbuffered: bool,
}

fn main() -> sbp::Result<()> {
    let options = Options::from_args();

    if options.debug {
        std::env::set_var("RUST_LOG", "debug");
    }

    env_logger::init();

    let stdin = io::stdin();
    let stdout = io::stdout();

    let buffered = atty::isnt(atty::Stream::Stdout) && !options.unbuffered;

    if options.float_compat {
        sbp2json(
            stdin,
            stdout,
            HaskellishFloatFormatter {},
            buffered,
        )
    } else {
        sbp2json(stdin, stdout, CompactFormatter {}, buffered)
    }
}
