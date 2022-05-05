use std::io;

use clap::Parser;

use converters::{json2sbp, Result};

#[global_allocator]
static GLOBAL: mimalloc::MiMalloc = mimalloc::MiMalloc;

/// Convert SBP JSON data to binary SBP.
///
/// Typical usage:
///
///     cat sbp.json | json2sbp
#[derive(Debug, Parser)]
#[clap(name = "json2sbp", verbatim_doc_comment)]
struct Options {
    /// Print debugging messages to standard error
    #[clap(long)]
    debug: bool,

    /// Buffer output before flushing
    #[clap(short, long)]
    buffered: bool,

    /// Stop on first error encountered
    #[clap(long)]
    fatal_errors: bool,
}

fn main() -> Result<()> {
    let options = Options::parse();

    if options.debug {
        std::env::set_var("RUST_LOG", "debug");
    }

    env_logger::init();

    let stdin = io::stdin();
    let stdout = io::stdout();

    json2sbp(stdin, stdout, options.buffered, options.fatal_errors)
}
