mod common;

use crate::common::{data_path, find_project_root};
use assert_cmd::cargo::CommandCargoExt;
use assert_cmd::Command;

/// Asserts termination of json decoder on broken inputs
#[test]
fn test_json_converters_termination() {
    let input_path = data_path("test_data/errors/error_eof.json");
    let mut cmd = Command::cargo_bin("json2sbp").unwrap();
    cmd.arg(input_path)
        .assert()
        .success()
        .stderr("expected `,` or `}` at line 1 column 185\n");
}

/// Asserts error for invalid msg_type
#[test]
fn test_json_untagged() {
    let input_path = data_path("test_data/errors/error_untagged.json");
    let mut cmd = Command::cargo_bin("json2sbp").unwrap();
    cmd.arg(input_path)
        .assert()
        .success()
        .stderr("data did not match any variant of untagged enum JsonInput\n");
}
