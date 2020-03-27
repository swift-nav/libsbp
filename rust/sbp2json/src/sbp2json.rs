use std::boxed::Box;
use std::io;
use std::io::Write;
use std::rc::Rc;

use structopt::StructOpt;

use sbp::sbp2json::{sbp2json_read_loop, Result};

#[derive(Debug, StructOpt)]
#[structopt(name = "sbp2json", verbatim_doc_comment)]
/// Convert binary SBP data to JSON.
///
/// Typical usage:
///
///     cat sbp.dat | sbp2json
///
/// Or combined with socat:
///
///     socat tcp:192.168.1.222:55555 - | sbp2json
pub struct Options {
    /// Try to be compatible with the float formatting of the Haskell version of sbp2json
    #[structopt(long = "float-compat")]
    float_compat: bool,

    /// Print debugging messages to standard error
    #[structopt(short = "d", long)]
    debug: bool,

    /// Print debugging messages about memory usage to standard error
    #[structopt(short = "m", long = "debug-memory")]
    debug_memory: bool,
}

fn main() -> Result<()> {
    let options = Options::from_args();
    let mut stdout: Rc<Box<dyn Write>> = Rc::new(Box::new(io::stdout()));
    sbp2json_read_loop(
        options.debug,
        options.debug_memory,
        options.float_compat,
        &mut std::io::stdin(),
        &mut stdout,
    )
}
