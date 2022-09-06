use std::fs::File;
use std::io;
use std::io::{Read, Write};
use std::path::PathBuf;

use clap::Parser;

use converters::{json2sbp, jsonfields2sbp, Result};

#[global_allocator]
static GLOBAL: mimalloc::MiMalloc = mimalloc::MiMalloc;

/// Convert SBP JSON data to binary SBP.
#[derive(Debug, Parser)]
#[clap(name = "json2sbp", verbatim_doc_comment, version = env!("VERGEN_SEMVER_LIGHTWEIGHT"))]
struct Options {
    /// Path to input file
    input: Option<PathBuf>,

    /// Path to output file
    output: Option<PathBuf>,

    /// Print debugging messages to standard error
    #[clap(long)]
    debug: bool,

    /// Buffer output before flushing
    #[clap(short, long)]
    buffered: bool,

    /// Stop on first error encountered
    #[clap(long)]
    fatal_errors: bool,

    /// Generate SBP from the json fields instead of the base64 encoded payload
    #[clap(long)]
    from_fields: bool,
}

fn main() -> Result<()> {
    let options: Options = Options::parse();

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

    if options.from_fields {
        jsonfields2sbp(stdin, stdout, options.buffered, options.fatal_errors)
    } else {
        json2sbp(stdin, stdout, options.buffered, options.fatal_errors)
    }
}
