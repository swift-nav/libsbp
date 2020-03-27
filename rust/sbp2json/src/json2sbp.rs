use std::io::Read;

use serde_json::Value;
use structopt::StructOpt;

use sbp::sbp2json::{json2sbp_process_with_expand, json_read_loop, Result};

#[derive(Debug, StructOpt)]
#[structopt(name = "json2sbp", verbatim_doc_comment)]
/// Convert SBP JSON data to binary SBP.
///
/// Typical usage:
///
///     cat sbp.json | json2sbp
struct Options {
    /// Print debugging messages to standard error
    #[structopt(short = "d", long)]
    debug: bool,
}

fn json2sbp_read_loop(options: &Options, stream: &mut dyn Read) -> Result<()> {
    let json2sbp_process = |value: &Value| -> Result<()> {
        json2sbp_process_with_expand(value, options.debug, false, false)
    };

    json_read_loop(stream, json2sbp_process)
}

fn main() -> Result<()> {
    let options = Options::from_args();
    json2sbp_read_loop(&options, &mut std::io::stdin())
}
