use std::boxed::Box;
use std::io::Write;
use std::rc::Rc;

use structopt::StructOpt;

use sbp::sbp2json::{json2json_read_loop, Result};

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

fn main() -> Result<()> {
    let options = Options::from_args();
    let mut stdout: Rc<Box<dyn Write>> = Rc::new(Box::new(std::io::stdout()));
    json2json_read_loop(options.debug, options.float_compat, &mut std::io::stdin(), &mut stdout)
}
