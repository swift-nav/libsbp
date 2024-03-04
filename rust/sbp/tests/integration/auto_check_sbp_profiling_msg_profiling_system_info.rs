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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingSystemInfo.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_profiling_msg_profiling_system_info() {
    {
        let mut payload = Cursor::new(vec![
            85, 1, 207, 0, 16, 21, 98, 40, 52, 0, 0, 0, 0, 0, 114, 12, 157, 0, 0, 0, 0, 0, 27, 72,
            195, 226, 0, 252, 65,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgProfilingSystemInfo(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xcf01,
                    "Incorrect message type, expected 0xcf01, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.age, 10292338,
                    "incorrect value for age, expected 10292338, is {}",
                    msg.age
                );
                assert_eq!(
                    msg.heap_usage, 14861128,
                    "incorrect value for heap_usage, expected 14861128, is {}",
                    msg.heap_usage
                );
                assert_eq!(
                    msg.n_threads, 27,
                    "incorrect value for n_threads, expected 27, is {}",
                    msg.n_threads
                );
                assert_eq!(
                    msg.total_cpu_time, 3418210,
                    "incorrect value for total_cpu_time, expected 3418210, is {}",
                    msg.total_cpu_time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProfilingSystemInfo"),
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
fn test_json2sbp_auto_check_sbp_profiling_msg_profiling_system_info() {
    {
        let json_input = r#"{"crc": 16892, "preamble": 85, "sender": 4096, "length": 21, "msg_type": 52993,  "total_cpu_time": 3418210, "age": 10292338, "n_threads": 27, "heap_usage": 14861128, "payload": "Yig0AAAAAAByDJ0AAAAAABtIw+IA"}
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
            sbp::messages::Sbp::MsgProfilingSystemInfo(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xcf01,
                    "Incorrect message type, expected 0xcf01, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.age, 10292338,
                    "incorrect value for age, expected 10292338, is {}",
                    msg.age
                );
                assert_eq!(
                    msg.heap_usage, 14861128,
                    "incorrect value for heap_usage, expected 14861128, is {}",
                    msg.heap_usage
                );
                assert_eq!(
                    msg.n_threads, 27,
                    "incorrect value for n_threads, expected 27, is {}",
                    msg.n_threads
                );
                assert_eq!(
                    msg.total_cpu_time, 3418210,
                    "incorrect value for total_cpu_time, expected 3418210, is {}",
                    msg.total_cpu_time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProfilingSystemInfo"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_profiling_msg_profiling_system_info`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_profiling_msg_profiling_system_info() {
    {
        let mut payload = Cursor::new(vec![
            85, 1, 207, 0, 16, 21, 98, 40, 52, 0, 0, 0, 0, 0, 114, 12, 157, 0, 0, 0, 0, 0, 27, 72,
            195, 226, 0, 252, 65,
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
        let sbp_msg = sbp::messages::Sbp::MsgProfilingSystemInfo(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgProfilingSystemInfo(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xcf01,
                    "Incorrect message type, expected 0xcf01, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.age, 10292338,
                    "incorrect value for age, expected 10292338, is {}",
                    msg.age
                );
                assert_eq!(
                    msg.heap_usage, 14861128,
                    "incorrect value for heap_usage, expected 14861128, is {}",
                    msg.heap_usage
                );
                assert_eq!(
                    msg.n_threads, 27,
                    "incorrect value for n_threads, expected 27, is {}",
                    msg.n_threads
                );
                assert_eq!(
                    msg.total_cpu_time, 3418210,
                    "incorrect value for total_cpu_time, expected 3418210, is {}",
                    msg.total_cpu_time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProfilingSystemInfo"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
