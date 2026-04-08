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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingQueueInfo.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_profiling_msg_profiling_queue_info() {
    {
        let mut payload = Cursor::new(vec![
            85, 4, 207, 0, 16, 58, 0, 1, 136, 19, 0, 0, 0, 0, 0, 0, 67, 111, 104, 101, 115, 105,
            118, 101, 83, 98, 112, 77, 115, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 10, 0, 50, 0, 0, 0, 138, 42,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgProfilingQueueInfo(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xcf04,
                    "Incorrect message type, expected 0xcf04, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.queues[0].current_fill, 10,
                    "incorrect value for queues[0].current_fill, expected 10, is {}",
                    msg.queues[0].current_fill
                );
                assert_eq!(
                    msg.queues[0].drop_count, 0,
                    "incorrect value for queues[0].drop_count, expected 0, is {}",
                    msg.queues[0].drop_count
                );
                assert_eq!(
                    msg.queues[0].name.as_bytes(),
                    &[
                        67, 111, 104, 101, 115, 105, 118, 101, 83, 98, 112, 77, 115, 103, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    "incorrect value for msg.queues[0].name, expected string '{:?}', is '{:?}'",
                    &[
                        67, 111, 104, 101, 115, 105, 118, 101, 83, 98, 112, 77, 115, 103, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    msg.queues[0].name.as_bytes()
                );
                assert_eq!(
                    msg.queues[0].peak_fill, 50,
                    "incorrect value for queues[0].peak_fill, expected 50, is {}",
                    msg.queues[0].peak_fill
                );
                assert_eq!(
                    msg.queues[0].size, 100,
                    "incorrect value for queues[0].size, expected 100, is {}",
                    msg.queues[0].size
                );
                assert_eq!(
                    msg.queues[0].timestamp, 5000,
                    "incorrect value for queues[0].timestamp, expected 5000, is {}",
                    msg.queues[0].timestamp
                );
                assert_eq!(
                    msg.seq_len, 1,
                    "incorrect value for seq_len, expected 1, is {}",
                    msg.seq_len
                );
                assert_eq!(
                    msg.seq_no, 0,
                    "incorrect value for seq_no, expected 0, is {}",
                    msg.seq_no
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProfilingQueueInfo"),
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
fn test_json2sbp_auto_check_sbp_profiling_msg_profiling_queue_info() {
    {
        let json_input = r#"{"crc": 10890, "preamble": 85, "sender": 4096, "length": 58, "msg_type": 52996, "seq_no": 0, "seq_len": 1, "queues": [{"timestamp": 5000, "name": "CohesiveSbpMsg\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000", "size": 100, "current_fill": 10, "peak_fill": 50, "drop_count": 0}], "payload": "AAGIEwAAAAAAAENvaGVzaXZlU2JwTXNnAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABkAAoAMgAAAA=="}
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
            sbp::messages::Sbp::MsgProfilingQueueInfo(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xcf04,
                    "Incorrect message type, expected 0xcf04, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.queues[0].current_fill, 10,
                    "incorrect value for queues[0].current_fill, expected 10, is {}",
                    msg.queues[0].current_fill
                );
                assert_eq!(
                    msg.queues[0].drop_count, 0,
                    "incorrect value for queues[0].drop_count, expected 0, is {}",
                    msg.queues[0].drop_count
                );
                assert_eq!(
                    msg.queues[0].name.as_bytes(),
                    &[
                        67, 111, 104, 101, 115, 105, 118, 101, 83, 98, 112, 77, 115, 103, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    "incorrect value for msg.queues[0].name, expected string '{:?}', is '{:?}'",
                    &[
                        67, 111, 104, 101, 115, 105, 118, 101, 83, 98, 112, 77, 115, 103, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    msg.queues[0].name.as_bytes()
                );
                assert_eq!(
                    msg.queues[0].peak_fill, 50,
                    "incorrect value for queues[0].peak_fill, expected 50, is {}",
                    msg.queues[0].peak_fill
                );
                assert_eq!(
                    msg.queues[0].size, 100,
                    "incorrect value for queues[0].size, expected 100, is {}",
                    msg.queues[0].size
                );
                assert_eq!(
                    msg.queues[0].timestamp, 5000,
                    "incorrect value for queues[0].timestamp, expected 5000, is {}",
                    msg.queues[0].timestamp
                );
                assert_eq!(
                    msg.seq_len, 1,
                    "incorrect value for seq_len, expected 1, is {}",
                    msg.seq_len
                );
                assert_eq!(
                    msg.seq_no, 0,
                    "incorrect value for seq_no, expected 0, is {}",
                    msg.seq_no
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProfilingQueueInfo"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_profiling_msg_profiling_queue_info`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_profiling_msg_profiling_queue_info() {
    {
        let mut payload = Cursor::new(vec![
            85, 4, 207, 0, 16, 58, 0, 1, 136, 19, 0, 0, 0, 0, 0, 0, 67, 111, 104, 101, 115, 105,
            118, 101, 83, 98, 112, 77, 115, 103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 10, 0, 50, 0, 0, 0, 138, 42,
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
        let sbp_msg = sbp::messages::Sbp::MsgProfilingQueueInfo(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgProfilingQueueInfo(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xcf04,
                    "Incorrect message type, expected 0xcf04, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.queues[0].current_fill, 10,
                    "incorrect value for queues[0].current_fill, expected 10, is {}",
                    msg.queues[0].current_fill
                );
                assert_eq!(
                    msg.queues[0].drop_count, 0,
                    "incorrect value for queues[0].drop_count, expected 0, is {}",
                    msg.queues[0].drop_count
                );
                assert_eq!(
                    msg.queues[0].name.as_bytes(),
                    &[
                        67, 111, 104, 101, 115, 105, 118, 101, 83, 98, 112, 77, 115, 103, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    "incorrect value for msg.queues[0].name, expected string '{:?}', is '{:?}'",
                    &[
                        67, 111, 104, 101, 115, 105, 118, 101, 83, 98, 112, 77, 115, 103, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    msg.queues[0].name.as_bytes()
                );
                assert_eq!(
                    msg.queues[0].peak_fill, 50,
                    "incorrect value for queues[0].peak_fill, expected 50, is {}",
                    msg.queues[0].peak_fill
                );
                assert_eq!(
                    msg.queues[0].size, 100,
                    "incorrect value for queues[0].size, expected 100, is {}",
                    msg.queues[0].size
                );
                assert_eq!(
                    msg.queues[0].timestamp, 5000,
                    "incorrect value for queues[0].timestamp, expected 5000, is {}",
                    msg.queues[0].timestamp
                );
                assert_eq!(
                    msg.seq_len, 1,
                    "incorrect value for seq_len, expected 1, is {}",
                    msg.seq_len
                );
                assert_eq!(
                    msg.seq_no, 0,
                    "incorrect value for seq_no, expected 0, is {}",
                    msg.seq_no
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProfilingQueueInfo"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
