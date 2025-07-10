//
// Copyright (C) 2019-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingThreadInfo.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_profiling_msg_profiling_thread_info() {
    {
        let mut payload = Cursor::new(vec![
            85, 2, 207, 0, 16, 39, 119, 91, 10, 0, 0, 0, 0, 0, 110, 5, 155, 0, 0, 0, 0, 0, 1, 0, 0,
            128, 0, 208, 53, 4, 0, 70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101,
            0, 242, 170,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgProfilingThreadInfo(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xcf02,
                    "Incorrect message type, expected 0xcf02, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.age, 10159470,
                    "incorrect value for age, expected 10159470, is {}",
                    msg.age
                );
                assert_eq!(
                    msg.name.as_bytes(),
                    &[70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101, 0],
                    "incorrect value for msg.name, expected string '{:?}', is '{:?}'",
                    &[70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101, 0],
                    msg.name.as_bytes()
                );
                assert_eq!(
                    msg.stack_size, 8388608,
                    "incorrect value for stack_size, expected 8388608, is {}",
                    msg.stack_size
                );
                assert_eq!(
                    msg.stack_usage, 275920,
                    "incorrect value for stack_usage, expected 275920, is {}",
                    msg.stack_usage
                );
                assert_eq!(
                    msg.state, 1,
                    "incorrect value for state, expected 1, is {}",
                    msg.state
                );
                assert_eq!(
                    msg.total_cpu_time, 678775,
                    "incorrect value for total_cpu_time, expected 678775, is {}",
                    msg.total_cpu_time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProfilingThreadInfo"),
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
fn test_json2sbp_auto_check_sbp_profiling_msg_profiling_thread_info() {
    {
        let json_input = r#"{"crc": 43762, "preamble": 85, "sender": 4096, "length": 39, "msg_type": 52994,  "total_cpu_time": 678775, "age": 10159470, "state": 1, "stack_size": 8388608,  "stack_usage": 275920, "name": "Fusion engine\u0000", "payload": "d1sKAAAAAABuBZsAAAAAAAEAAIAA0DUEAEZ1c2lvbiBlbmdpbmUA"}
"#.as_bytes();

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
            sbp::messages::Sbp::MsgProfilingThreadInfo(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xcf02,
                    "Incorrect message type, expected 0xcf02, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.age, 10159470,
                    "incorrect value for age, expected 10159470, is {}",
                    msg.age
                );
                assert_eq!(
                    msg.name.as_bytes(),
                    &[70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101, 0],
                    "incorrect value for msg.name, expected string '{:?}', is '{:?}'",
                    &[70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101, 0],
                    msg.name.as_bytes()
                );
                assert_eq!(
                    msg.stack_size, 8388608,
                    "incorrect value for stack_size, expected 8388608, is {}",
                    msg.stack_size
                );
                assert_eq!(
                    msg.stack_usage, 275920,
                    "incorrect value for stack_usage, expected 275920, is {}",
                    msg.stack_usage
                );
                assert_eq!(
                    msg.state, 1,
                    "incorrect value for state, expected 1, is {}",
                    msg.state
                );
                assert_eq!(
                    msg.total_cpu_time, 678775,
                    "incorrect value for total_cpu_time, expected 678775, is {}",
                    msg.total_cpu_time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProfilingThreadInfo"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_profiling_msg_profiling_thread_info`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_profiling_msg_profiling_thread_info() {
    {
        let mut payload = Cursor::new(vec![
            85, 2, 207, 0, 16, 39, 119, 91, 10, 0, 0, 0, 0, 0, 110, 5, 155, 0, 0, 0, 0, 0, 1, 0, 0,
            128, 0, 208, 53, 4, 0, 70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101,
            0, 242, 170,
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
        let sbp_msg = sbp::messages::Sbp::MsgProfilingThreadInfo(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgProfilingThreadInfo(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xcf02,
                    "Incorrect message type, expected 0xcf02, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.age, 10159470,
                    "incorrect value for age, expected 10159470, is {}",
                    msg.age
                );
                assert_eq!(
                    msg.name.as_bytes(),
                    &[70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101, 0],
                    "incorrect value for msg.name, expected string '{:?}', is '{:?}'",
                    &[70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101, 0],
                    msg.name.as_bytes()
                );
                assert_eq!(
                    msg.stack_size, 8388608,
                    "incorrect value for stack_size, expected 8388608, is {}",
                    msg.stack_size
                );
                assert_eq!(
                    msg.stack_usage, 275920,
                    "incorrect value for stack_usage, expected 275920, is {}",
                    msg.stack_usage
                );
                assert_eq!(
                    msg.state, 1,
                    "incorrect value for state, expected 1, is {}",
                    msg.state
                );
                assert_eq!(
                    msg.total_cpu_time, 678775,
                    "incorrect value for total_cpu_time, expected 678775, is {}",
                    msg.total_cpu_time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProfilingThreadInfo"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
