use std::fs::File;
use std::io;
use std::io::{stdin, Read, Write, Cursor};
use std::path::PathBuf;

use clap::Parser;
use sbp::json::{CompactFormatter, HaskellishFloatFormatter};

use converters::{sbp2json, Result};
use sbp::de::{Framer, SbpDecode};
use sbp::{iter_messages, Sbp};

#[global_allocator]
static GLOBAL: mimalloc::MiMalloc = mimalloc::MiMalloc;

/// Convert binary SBP data to JSON.
#[derive(Debug, Parser)]
#[structopt(name = "sbp2json", verbatim_doc_comment, version = env!("VERGEN_SEMVER_LIGHTWEIGHT"))]
pub struct Options {
    /// Path to input file
    input: Option<PathBuf>,

    /// Path to output file
    output: Option<PathBuf>,

    /// Try to be compatible with the float formatting of the Haskell version of sbp2json
    #[clap(long)]
    float_compat: bool,

    /// Print debugging messages to standard error
    #[clap(short = 'd', long)]
    debug: bool,

    /// Buffer output before flushing
    #[clap(short, long)]
    buffered: bool,

    /// Stop on first error encountered
    #[clap(long)]
    fatal_errors: bool,
}

fn main() -> Result<()> {
    // let mut bad_bytes = 0;
    // for msg in iter_messages(stdin()) {
    //     println!("{:?}", msg);
    // }

    let packet = vec![
        // Start with a mostly valid message, with a single byte error
        0x55, 0x0c, // This byte should be 0x0b, changed to intentionally cause a CRC error
        0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff, 0xbe, 0x40,
        0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf, 0xde, 0xad,
        0xbe, 0xef, // Include another valid message to properly parse
        0x55, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff,
        0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf,
        0xde, 0xad, 0xbe, 0xef,
    ];

    for msg in iter_messages(Cursor::new(&packet)) {
        println!("{msg:?}");
    }
    println!("a");
    for msg in SbpDecode::new(Cursor::new(&packet)) {
        println!("{msg:?}")
    }
    /*
    Err(CrcError(CrcError { msg_type: 524, sender_id: 35027, crc: 49115 }))
Ok(MsgBaselineEcef(MsgBaselineEcef { sender_id: Some(35027), tow: 326825000, x: -1154410, y: 1327294, z: 631798, accuracy: 0, n_sats: 14, flags: 0 }))

     */
    // for msg in iter_messages(std::io::stdin()){
    //     println!("{:?}", msg);
    //     bad_bytes += 1;
    // }
    // println!("bad {bad_bytes}");

    // iter_messages(stdin());
    // let options = Options::parse();
    //
    // if options.debug {
    //     std::env::set_var("RUST_LOG", "debug");
    // }
    //
    // env_logger::init();
    //
    // let stdin: Box<dyn Read> = match options.input {
    //     Some(path) => Box::new(File::open(path)?),
    //     _ => Box::new(io::stdin().lock()),
    // };
    //
    // let stdout: Box<dyn Write> = match options.output {
    //     Some(path) => Box::new(File::create(path)?),
    //     _ => Box::new(io::stdout().lock()),
    // };
    //
    // if options.float_compat {
    //     sbp2json(
    //         stdin,
    //         stdout,
    //         HaskellishFloatFormatter {},
    //         options.buffered,
    //         options.fatal_errors,
    //     )
    // } else {
    //     sbp2json(
    //         stdin,
    //         stdout,
    //         CompactFormatter {},
    //         options.buffered,
    //         options.fatal_errors,
    //     )
    // }
    Ok(())
}
