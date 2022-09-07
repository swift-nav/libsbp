use std::fs::File;
use std::io;
use std::io::{Read, Write};
use std::path::PathBuf;

use clap::Parser;
use sbp::json::{CompactFormatter, HaskellishFloatFormatter};

use converters::{json2json, Result};

#[global_allocator]
static GLOBAL: mimalloc::MiMalloc = mimalloc::MiMalloc;

/// Convert "compact" SBP JSON data to an "exploded" form
#[derive(Debug, Parser)]
#[clap(name = "json2json", verbatim_doc_comment, version = env!("VERGEN_SEMVER_LIGHTWEIGHT"))]
struct Options {
    /// Path to input file
    input: Option<PathBuf>,

    /// Path to output file
    output: Option<PathBuf>,

    /// Print debugging messages to standard error
    #[clap(long)]
    debug: bool,

    /// Try to be compatible with the float formatting of the Haskell version of sbp2json
    #[clap(long = "float-compat")]
    float_compat: bool,

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

    let stdin: Box<dyn Read> = match options.input {
        Some(path) => Box::new(File::open(path)?),
        _ => Box::new(io::stdin().lock()),
    };

    let stdout: Box<dyn Write> = match options.output {
        Some(path) => Box::new(File::create(path)?),
        _ => Box::new(io::stdout().lock()),
    };

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
