use std::io::Read;

use serde_json::Value;
use structopt::StructOpt;

use sbp::sbp2json::{json2sbp_process_with_expand, json_read_loop, Result};

#[derive(Debug, StructOpt)]
#[structopt(name = "json2json", verbatim_doc_comment)]
/// Convert "compact" SBP JSON data to an "exploded" form
///
/// Typical usage:
///
///     cat console-json-log.json | json2json
struct Options {
    /// Print debugging messages to standard error
    #[structopt(short = "d", long)]
    debug: bool,

    /// Try to be compatible with the float formatting of the Haskell version of sbp2json
    #[structopt(long = "float-compat")]
    float_compat: bool,
}

fn json2json_read_loop(options: &Options, stream: &mut dyn Read) -> Result<()> {
    let json2json_process = |value: &Value| -> Result<()> {
        json2sbp_process_with_expand(value, options.debug, options.float_compat, true)
    };

    json_read_loop(stream, json2json_process)
}

fn main() -> Result<()> {
    let options = Options::from_args();
    json2json_read_loop(&options, &mut std::io::stdin())
}
