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

use crate::common::run_jsonfields2sbp;
use serde_json::ser::CompactFormatter;

use sbp::json::HaskellishFloatFormatter;
use serde_json::json;

#[test]
fn test_invalid_message_round_trip() {
    // Properly framed data but the payload isn't right given the message type
    let data: Vec<u8> = vec![0x55, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x65, 0x8D];
    let mut sbp2json_out: Vec<u8> = Vec::new();

    let mut expected_json = json!({"msg_name": "INVALID", "payload": "VQEBAQEBAWWN"});
    let expected_json = expected_json.as_object_mut().expect("is a map");
    let input = Cursor::new(data.clone());
    let error_handler_opt = converters::ErrorHandlerOptions::CoerceErrorsToInvalidMsg;
    converters::sbp2json(
        input,
        &mut sbp2json_out,
        HaskellishFloatFormatter {},
        true,
        error_handler_opt,
    )
    .expect("can run sbp2json");

    let mut out_as_json: serde_json::Value =
        serde_json::from_str(std::str::from_utf8(&sbp2json_out).expect("is valid utf8"))
            .expect("is valid JSON");

    for key in &["msg_name".to_string(), "payload".to_string()] {
        assert!(expected_json.get(key).is_some());
        assert_eq!(
            out_as_json.as_object_mut().and_then(|m| m.remove(key)),
            expected_json.clone().remove(key),
            "{key} values must be equal"
        );
    }
    assert!(
        out_as_json
            .as_object()
            .map(|m| m.is_empty())
            .unwrap_or(false),
        "out object should contain no additional keys"
    );

    let mut json2sbp_out: Vec<u8> = Vec::new();

    converters::json2sbp(
        Cursor::new(sbp2json_out),
        &mut json2sbp_out,
        true,
        error_handler_opt,
    )
    .expect("can run json2sbp");

    assert_eq!(data, json2sbp_out, "completed round trip");
}

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
    let input_path = root.join(format!("test_data/{}", "short.sbp.json"));

    let mut source = File::open(input_path).unwrap();

    assert_eq!(sbp::iter_messages(&mut source).count(), 355);
}

#[test]
fn test_sbp2json() {
    let tranform1 = |reader, writer| run_sbp2json(reader, writer, true);
    let tranform2 = run_json2sbp;

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
    let tranform1 = run_json2sbp;
    let tranform2 = |reader, writer| run_sbp2json(reader, writer, true);

    test_round_trip(
        tranform1,
        tranform2,
        "json2sbp",
        "roundtrip_float_compat.json",
        make_none_transform!(),
        true,
    )
}

#[test]
fn test_jsonfields2sbp() {
    let tranform1 = run_jsonfields2sbp;
    let tranform2 = |reader, writer| run_sbp2json(reader, writer, false);

    test_round_trip(
        tranform1,
        tranform2,
        "jsonfields2sbp",
        "roundtrip.json",
        make_none_transform!(),
        true,
    )
}

#[test]
fn test_json2json() {
    let tranform1 = run_json2json;
    let tranform2 = run_json2sbp;

    let third_transform = ThirdTransform {
        transform: |reader, writer| run_sbp2json(reader, writer, true),
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
