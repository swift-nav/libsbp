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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessFdSummary.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_linux_msg_linux_process_fd_summary() {
    {
        let mut payload = Cursor::new(vec![
            85, 7, 127, 103, 248, 29, 19, 131, 200, 77, 102, 100, 49, 0, 102, 100, 50, 0, 102, 100,
            51, 0, 102, 100, 52, 0, 102, 100, 53, 0, 102, 100, 54, 0, 0, 129, 80,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxProcessFdSummary(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f07,
                    "Incorrect message type, expected 0x7f07, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf867,
                    "incorrect sender id, expected 0xf867, is {sender_id}"
                );
                assert_eq!(
                    msg.most_opened.as_bytes(),
                    &[
                        102, 100, 49, 0, 102, 100, 50, 0, 102, 100, 51, 0, 102, 100, 52, 0, 102,
                        100, 53, 0, 102, 100, 54, 0, 0
                    ],
                    "incorrect value for msg.most_opened, expected string '{:?}', is '{:?}'",
                    &[
                        102, 100, 49, 0, 102, 100, 50, 0, 102, 100, 51, 0, 102, 100, 52, 0, 102,
                        100, 53, 0, 102, 100, 54, 0, 0
                    ],
                    msg.most_opened.as_bytes()
                );
                assert_eq!(
                    msg.sys_fd_count, 1304986387,
                    "incorrect value for sys_fd_count, expected 1304986387, is {}",
                    msg.sys_fd_count
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxProcessFdSummary"),
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
fn test_json2sbp_auto_check_sbp_linux_msg_linux_process_fd_summary() {
    {
        let json_input = r#"{"crc":20609,"length":29,"msg_type":32519,"payload":"E4PITWZkMQBmZDIAZmQzAGZkNABmZDUAZmQ2AAA=","preamble":85,"sender":63591,"sys_fd_count":1304986387,"most_opened":"fd1\u0000fd2\u0000fd3\u0000fd4\u0000fd5\u0000fd6\u0000\u0000"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgLinuxProcessFdSummary(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f07,
                    "Incorrect message type, expected 0x7f07, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf867,
                    "incorrect sender id, expected 0xf867, is {sender_id}"
                );
                assert_eq!(
                    msg.most_opened.as_bytes(),
                    &[
                        102, 100, 49, 0, 102, 100, 50, 0, 102, 100, 51, 0, 102, 100, 52, 0, 102,
                        100, 53, 0, 102, 100, 54, 0, 0
                    ],
                    "incorrect value for msg.most_opened, expected string '{:?}', is '{:?}'",
                    &[
                        102, 100, 49, 0, 102, 100, 50, 0, 102, 100, 51, 0, 102, 100, 52, 0, 102,
                        100, 53, 0, 102, 100, 54, 0, 0
                    ],
                    msg.most_opened.as_bytes()
                );
                assert_eq!(
                    msg.sys_fd_count, 1304986387,
                    "incorrect value for sys_fd_count, expected 1304986387, is {}",
                    msg.sys_fd_count
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxProcessFdSummary"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_linux_msg_linux_process_fd_summary`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_linux_msg_linux_process_fd_summary() {
    {
        let mut payload = Cursor::new(vec![
            85, 7, 127, 103, 248, 29, 19, 131, 200, 77, 102, 100, 49, 0, 102, 100, 50, 0, 102, 100,
            51, 0, 102, 100, 52, 0, 102, 100, 53, 0, 102, 100, 54, 0, 0, 129, 80,
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
        let sbp_msg = sbp::messages::Sbp::MsgLinuxProcessFdSummary(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxProcessFdSummary(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f07,
                    "Incorrect message type, expected 0x7f07, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf867,
                    "incorrect sender id, expected 0xf867, is {sender_id}"
                );
                assert_eq!(
                    msg.most_opened.as_bytes(),
                    &[
                        102, 100, 49, 0, 102, 100, 50, 0, 102, 100, 51, 0, 102, 100, 52, 0, 102,
                        100, 53, 0, 102, 100, 54, 0, 0
                    ],
                    "incorrect value for msg.most_opened, expected string '{:?}', is '{:?}'",
                    &[
                        102, 100, 49, 0, 102, 100, 50, 0, 102, 100, 51, 0, 102, 100, 52, 0, 102,
                        100, 53, 0, 102, 100, 54, 0, 0
                    ],
                    msg.most_opened.as_bytes()
                );
                assert_eq!(
                    msg.sys_fd_count, 1304986387,
                    "incorrect value for sys_fd_count, expected 1304986387, is {}",
                    msg.sys_fd_count
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxProcessFdSummary"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
