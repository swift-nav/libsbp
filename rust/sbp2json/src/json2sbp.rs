use std::boxed::Box;
use std::io::Write;
use std::rc::Rc;

use structopt::StructOpt;

use sbp::sbp2json::{json2sbp_read_loop, Result};

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

fn main() -> Result<()> {
    let options = Options::from_args();
    let mut stdout: Rc<Box<dyn Write>> = Rc::new(Box::new(std::io::stdout()));
    json2sbp_read_loop(options.debug, &mut std::io::stdin(), &mut stdout)
}
