use std::boxed::Box;
use std::fs::File;
use std::io::prelude::*;
use std::io::BufReader;
use std::rc::Rc;

#[macro_use]
mod common;

use common::{find_project_root, test_round_trip, DeleteTestOutput, ThirdTransform};

use sbp::sbp2json::json2json_read_loop;
use sbp::sbp2json::json2sbp_read_loop;
use sbp::sbp2json::sbp2json_read_loop;

use sbp::sbp2json::Result;

#[test]
fn test_sbp2json() -> Result<()> {
    let tranform1 = |reader: &mut dyn Read, writer: &mut Rc<Box<dyn Write>>| -> Result<()> {
        sbp2json_read_loop(false, false, false, reader, writer)
    };

    let tranform2 = |reader: &mut dyn Read, writer: &mut Rc<Box<dyn Write>>| -> Result<()> {
        json2sbp_read_loop(false, reader, writer)
    };

    test_round_trip(
        tranform1,
        tranform2,
        "sbp2json",
        "roundtrip.sbp",
        make_none_transform!(),
    )
}

#[test]
fn test_json2sbp() -> Result<()> {
    let tranform1 = |reader: &mut dyn Read, writer: &mut Rc<Box<dyn Write>>| -> Result<()> {
        json2sbp_read_loop(false, reader, writer)
    };

    let tranform2 = |reader: &mut dyn Read, writer: &mut Rc<Box<dyn Write>>| -> Result<()> {
        sbp2json_read_loop(false, false, false, reader, writer)
    };

    test_round_trip(
        tranform1,
        tranform2,
        "json2sbp",
        "roundtrip.json",
        make_none_transform!(),
    )
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

    test_round_trip(
        tranform1,
        tranform2,
        "json2json",
        "roundtrip.json2json.input",
        third_transform,
    )
}

#[test]
fn test_json2json_maintain_fields() -> Result<()> {
    let mut del_test_output = DeleteTestOutput::new();

    let root = find_project_root().unwrap();
    let root = root.as_path();

    let output_path = root.join("test_data/serial-link.log.json.output");

    {
        let input_path = root.join("test_data/serial-link.log.json");
        let mut input_file = File::open(input_path).expect("could not open input file");

        del_test_output.add_test_output(&output_path);

        let output_file = File::create(&output_path).expect("could not create output file");

        let mut output_file: Rc<Box<dyn Write>> = Rc::new(Box::new(output_file));

        assert!(json2json_read_loop(false, false, &mut input_file, &mut output_file).is_ok());
    }

    let mut message_count = 0;

    {
        let output_file = File::open(output_path).expect("could not open input file");
        let output_file = BufReader::new(output_file);

        for line in output_file.lines() {
            let value: serde_json::Value = serde_json::from_str(&line.unwrap()).unwrap();
            assert!(value.is_object());

            let value = value.as_object().unwrap();
            assert!(value.contains_key("time"));

            message_count += 1;
        }
    }

    assert_eq!(message_count, 10);

    Ok(())
}
