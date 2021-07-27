use std::{
    fs::File,
    io::{BufRead, BufReader, Cursor},
};

#[macro_use]
mod common;

use common::{
    find_project_root, run_json2json, run_json2sbp, run_sbp2json, test_round_trip,
    DeleteTestOutput, ThirdTransform,
};

use serde_json::ser::CompactFormatter;

#[test]
fn test_stop_on_error() {
    let root = find_project_root().unwrap();
    let root = root.as_path();
    let input_path = root.join(format!("test_data/{}", "short.sbp"));

    let source = File::open(input_path).unwrap();
    let mut sink = Cursor::new(vec![]);

    let _ = converters::sbp2json(source, &mut sink, CompactFormatter {}, false, true);

    sink.set_position(0);
    assert_eq!(sbp::iter_messages(&mut sink).count(), 1);
}

#[test]
fn test_continue_on_error() {
    let root = find_project_root().unwrap();
    let root = root.as_path();
    let input_path = root.join(format!("test_data/{}", "short.sbp"));

    let source = File::open(input_path).unwrap();
    let mut sink = Cursor::new(vec![]);

    let _ = converters::sbp2json(source, &mut sink, CompactFormatter {}, false, false);

    sink.set_position(0);
    assert_eq!(sbp::iter_messages(&mut sink).count(), 355);
}

#[test]
fn test_sbp2json() {
    let tranform1 = |reader, writer| run_sbp2json(reader, writer);
    let tranform2 = |reader, writer| run_json2sbp(reader, writer);

    test_round_trip(
        tranform1,
        tranform2,
        "sbp2json",
        "roundtrip.sbp",
        make_none_transform!(),
        false,
    )
}

#[test]
fn test_json2sbp() {
    let tranform1 = |reader, writer| run_json2sbp(reader, writer);
    let tranform2 = |reader, writer| run_sbp2json(reader, writer);

    test_round_trip(
        tranform1,
        tranform2,
        "json2sbp",
        "roundtrip.json",
        make_none_transform!(),
        true,
    )
}

#[test]
fn test_json2json() {
    let tranform1 = |reader, writer| run_json2json(reader, writer);
    let tranform2 = |reader, writer| run_json2sbp(reader, writer);

    let third_transform = ThirdTransform {
        transform: |reader, writer| run_sbp2json(reader, writer),
        expected_output: "roundtrip.json2json.output".into(),
    };

    test_round_trip(
        tranform1,
        tranform2,
        "json2json",
        "roundtrip.json2json.input",
        Some(third_transform),
        true,
    )
}

#[test]
fn test_json2json_maintain_fields() {
    let mut del_test_output = DeleteTestOutput::new();

    let root = find_project_root().unwrap();
    let root = root.as_path();
    let output_path = root.join("test_data/serial-link.log.json.output");

    {
        let input_path = root.join("test_data/serial-link.log.json");
        let input_file = File::open(input_path).expect("could not open input file");
        del_test_output.add_test_output(&output_path);
        let output_file = File::create(&output_path).expect("could not create output file");

        run_json2json(input_file, output_file);
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
}
