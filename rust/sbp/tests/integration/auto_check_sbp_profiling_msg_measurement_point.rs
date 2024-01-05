//
// Copyright (C) 2019-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgMeasurementPoint.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_profiling_msg_measurement_point() {
    {
        let mut payload = Cursor::new(vec![
            85, 0, 207, 0, 16, 48, 250, 7, 0, 0, 180, 0, 2, 0, 0, 0, 40, 0, 0, 0, 130, 201, 148,
            141, 97, 85, 0, 0, 18, 130, 201, 148, 0, 0, 0, 0, 66, 64, 157, 15, 0, 0, 0, 0, 18, 0,
            114, 111, 117, 116, 101, 40, 41, 0, 212, 165,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgMeasurementPoint(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xCF00,
                    "Incorrect message type, expected 0xCF00, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.func.as_bytes(),
                    &[114, 111, 117, 116, 101, 40, 41, 0],
                    "incorrect value for msg.func, expected string '{:?}', is '{:?}'",
                    &[114, 111, 117, 116, 101, 40, 41, 0],
                    msg.func.as_bytes()
                );
                assert_eq!(
                    msg.id, 2496234002,
                    "incorrect value for id, expected 2496234002, is {}",
                    msg.id
                );
                assert_eq!(
                    msg.line, 18,
                    "incorrect value for line, expected 18, is {}",
                    msg.line
                );
                assert_eq!(
                    msg.max, 40,
                    "incorrect value for max, expected 40, is {}",
                    msg.max
                );
                assert_eq!(
                    msg.min, 2,
                    "incorrect value for min, expected 2, is {}",
                    msg.min
                );
                assert_eq!(
                    msg.num_executions, 180,
                    "incorrect value for num_executions, expected 180, is {}",
                    msg.num_executions
                );
                assert_eq!(
                    msg.return_addr, 93877475527042,
                    "incorrect value for return_addr, expected 93877475527042, is {}",
                    msg.return_addr
                );
                assert_eq!(
                    msg.slice_time, 261963842,
                    "incorrect value for slice_time, expected 261963842, is {}",
                    msg.slice_time
                );
                assert_eq!(
                    msg.total_time, 2042,
                    "incorrect value for total_time, expected 2042, is {}",
                    msg.total_time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgMeasurementPoint"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}

/// Tests [`sbp::json::iter_messages`] for JSON payload -> SBP message
/// and [`sbp::json::iter_messages_from_fields`] for JSON fields -> SBP message.
///
/// Asserts:
/// -   SBP message constructed via payload is identical to from fields
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_json2sbp_auto_check_sbp_profiling_msg_measurement_point() {
    {
        let json_input = r#"{"crc": 42452, "preamble": 85, "sender": 4096, "length": 48, "msg_type": 52992, "total_time": 2042, "num_executions": 180, "min": 2, "max": 40, "return_addr": 93877475527042, "id": 2496234002, "slice_time": 261963842, "line": 18, "func": "route()\u0000", "payload": "+gcAALQAAgAAACgAAACCyZSNYVUAABKCyZQAAAAAQkCdDwAAAAASAHJvdXRlKCkA" }"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgMeasurementPoint(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xCF00,
                    "Incorrect message type, expected 0xCF00, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.func.as_bytes(),
                    &[114, 111, 117, 116, 101, 40, 41, 0],
                    "incorrect value for msg.func, expected string '{:?}', is '{:?}'",
                    &[114, 111, 117, 116, 101, 40, 41, 0],
                    msg.func.as_bytes()
                );
                assert_eq!(
                    msg.id, 2496234002,
                    "incorrect value for id, expected 2496234002, is {}",
                    msg.id
                );
                assert_eq!(
                    msg.line, 18,
                    "incorrect value for line, expected 18, is {}",
                    msg.line
                );
                assert_eq!(
                    msg.max, 40,
                    "incorrect value for max, expected 40, is {}",
                    msg.max
                );
                assert_eq!(
                    msg.min, 2,
                    "incorrect value for min, expected 2, is {}",
                    msg.min
                );
                assert_eq!(
                    msg.num_executions, 180,
                    "incorrect value for num_executions, expected 180, is {}",
                    msg.num_executions
                );
                assert_eq!(
                    msg.return_addr, 93877475527042,
                    "incorrect value for return_addr, expected 93877475527042, is {}",
                    msg.return_addr
                );
                assert_eq!(
                    msg.slice_time, 261963842,
                    "incorrect value for slice_time, expected 261963842, is {}",
                    msg.slice_time
                );
                assert_eq!(
                    msg.total_time, 2042,
                    "incorrect value for total_time, expected 2042, is {}",
                    msg.total_time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgMeasurementPoint"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_profiling_msg_measurement_point`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_profiling_msg_measurement_point() {
    {
        let mut payload = Cursor::new(vec![
            85, 0, 207, 0, 16, 48, 250, 7, 0, 0, 180, 0, 2, 0, 0, 0, 40, 0, 0, 0, 130, 201, 148,
            141, 97, 85, 0, 0, 18, 130, 201, 148, 0, 0, 0, 0, 66, 64, 157, 15, 0, 0, 0, 0, 18, 0,
            114, 111, 117, 116, 101, 40, 41, 0, 212, 165,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgMeasurementPoint(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgMeasurementPoint(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xCF00,
                    "Incorrect message type, expected 0xCF00, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.func.as_bytes(),
                    &[114, 111, 117, 116, 101, 40, 41, 0],
                    "incorrect value for msg.func, expected string '{:?}', is '{:?}'",
                    &[114, 111, 117, 116, 101, 40, 41, 0],
                    msg.func.as_bytes()
                );
                assert_eq!(
                    msg.id, 2496234002,
                    "incorrect value for id, expected 2496234002, is {}",
                    msg.id
                );
                assert_eq!(
                    msg.line, 18,
                    "incorrect value for line, expected 18, is {}",
                    msg.line
                );
                assert_eq!(
                    msg.max, 40,
                    "incorrect value for max, expected 40, is {}",
                    msg.max
                );
                assert_eq!(
                    msg.min, 2,
                    "incorrect value for min, expected 2, is {}",
                    msg.min
                );
                assert_eq!(
                    msg.num_executions, 180,
                    "incorrect value for num_executions, expected 180, is {}",
                    msg.num_executions
                );
                assert_eq!(
                    msg.return_addr, 93877475527042,
                    "incorrect value for return_addr, expected 93877475527042, is {}",
                    msg.return_addr
                );
                assert_eq!(
                    msg.slice_time, 261963842,
                    "incorrect value for slice_time, expected 261963842, is {}",
                    msg.slice_time
                );
                assert_eq!(
                    msg.total_time, 2042,
                    "incorrect value for total_time, expected 2042, is {}",
                    msg.total_time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgMeasurementPoint"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
