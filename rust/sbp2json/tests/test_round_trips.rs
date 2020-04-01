use std::boxed::Box;
use std::io::prelude::*;
use std::rc::Rc;

#[macro_use]
mod common;

use common::{ThirdTransform, test_round_trip};

use sbp::sbp2json::json2sbp_read_loop;
use sbp::sbp2json::sbp2json_read_loop;
use sbp::sbp2json::json2json_read_loop;

use sbp::sbp2json::Result;

#[test]
fn test_sbp2json() -> Result<()> {

    let tranform1 = |reader: &mut dyn Read, writer: &mut Rc<Box<dyn Write>>| -> Result<()> {
        sbp2json_read_loop(false, false, false, reader, writer)
    };

    let tranform2 = |reader: &mut dyn Read, writer: &mut Rc<Box<dyn Write>>| -> Result<()> {
        json2sbp_read_loop(false, reader, writer)
    };

    test_round_trip(tranform1, tranform2, "sbp2json", "roundtrip.sbp", make_none_transform!())
}

#[test]
fn test_json2sbp() -> Result<()> {

    let tranform1 = |reader: &mut dyn Read, writer: &mut Rc<Box<dyn Write>>| -> Result<()> {
        json2sbp_read_loop(false, reader, writer)
    };

    let tranform2 = |reader: &mut dyn Read, writer: &mut Rc<Box<dyn Write>>| -> Result<()> {
        sbp2json_read_loop(false, false, false, reader, writer)
    };

    test_round_trip(tranform1, tranform2, "json2sbp", "roundtrip.json", make_none_transform!())
}

#[test]
fn test_json2json() -> Result<()> {

    let tranform1 = |reader: &mut dyn Read, writer: &mut Rc<Box<dyn Write>>| -> Result<()> {
        json2json_read_loop(false, false, reader, writer)
    };

    let tranform2 = |reader: &mut dyn Read, writer: &mut Rc<Box<dyn Write>>| -> Result<()> {
        json2sbp_read_loop(false, reader, writer)
    };

    let tranform3 = |reader: &mut dyn Read, writer: &mut Rc<Box<dyn Write>>| -> Result<()> {
        sbp2json_read_loop(false, false, false, reader, writer)
    };

    let third_transform = ThirdTransform {
        transform: tranform3,
        expected_output: "roundtrip.json2json.output".into(),
    };

    let third_transform = Some(third_transform);

    test_round_trip(tranform1, tranform2, "json2json", "roundtrip.json2json.input", third_transform)
}
