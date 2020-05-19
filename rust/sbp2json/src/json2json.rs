use std::boxed::Box;
use std::io::Write;
use std::rc::Rc;

use lazy_static::lazy_static;
use structopt::StructOpt;

use sbp::sbp2json::{json2json_read_loop, Result};

#[cfg(all(not(windows), not(target_env = "musl")))]
#[global_allocator]
static ALLOC: jemallocator::Jemalloc = jemallocator::Jemalloc;

#[derive(Debug, StructOpt)]
#[structopt(name = "json2json", verbatim_doc_comment)]
/// Convert "compact" SBP JSON data to an "exploded" form
///
/// Typical usage:
///
///     cat console-json-log.json | json2json
struct Options {
    /// Print debugging messages to standard error
    #[structopt(long)]
    debug: bool,

    /// Try to be compatible with the float formatting of the Haskell version of sbp2json
    #[structopt(long = "float-compat")]
    float_compat: bool,
}

lazy_static! {
    static ref STDOUT: std::io::Stdout = std::io::stdout();
}

fn main() -> Result<()> {
    let options = Options::from_args();
    let mut stdout: Rc<Box<dyn Write>> = Rc::new(Box::new(STDOUT.lock()));
    json2json_read_loop(options.debug, options.float_compat, &mut std::io::stdin().lock(), &mut stdout)
}
