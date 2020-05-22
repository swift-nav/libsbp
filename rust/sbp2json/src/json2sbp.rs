use std::boxed::Box;
use std::io::Write;
use std::rc::Rc;

use lazy_static::lazy_static;
use structopt::StructOpt;

use sbp::sbp2json::{json2sbp_read_loop, Result};

#[cfg(all(not(windows), not(target_env = "musl")))]
#[global_allocator]
static ALLOC: jemallocator::Jemalloc = jemallocator::Jemalloc;

#[derive(Debug, StructOpt)]
#[structopt(name = "json2sbp", verbatim_doc_comment)]
/// Convert SBP JSON data to binary SBP.
///
/// Typical usage:
///
///     cat sbp.json | json2sbp
struct Options {
    /// Print debugging messages to standard error
    #[structopt(long)]
    debug: bool,
}

lazy_static! {
    static ref STDOUT: std::io::Stdout = std::io::stdout();
}

fn main() -> Result<()> {
    let options = Options::from_args();
    let mut stdout: Rc<Box<dyn Write>> = Rc::new(Box::new(STDOUT.lock()));
    json2sbp_read_loop(options.debug, &mut std::io::stdin().lock(), &mut stdout)
}
