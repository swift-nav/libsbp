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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessFdCount.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_linux_msg_linux_process_fd_count() {
    {
        let mut payload = Cursor::new(vec![
            85, 6, 127, 30, 195, 51, 164, 189, 165, 5, 139, 47, 112, 97, 116, 104, 47, 116, 111,
            47, 112, 114, 111, 99, 101, 115, 115, 45, 110, 97, 109, 101, 32, 97, 114, 103, 48, 32,
            97, 114, 103, 49, 32, 97, 114, 103, 50, 32, 97, 114, 103, 51, 32, 97, 114, 103, 52, 2,
            94,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxProcessFdCount(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f06,
                    "Incorrect message type, expected 0x7f06, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc31e,
                    "incorrect sender id, expected 0xc31e, is {sender_id}"
                );
                assert_eq!(
                    msg.cmdline.as_bytes(),
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 112, 114, 111, 99, 101, 115, 115,
                        45, 110, 97, 109, 101, 32, 97, 114, 103, 48, 32, 97, 114, 103, 49, 32, 97,
                        114, 103, 50, 32, 97, 114, 103, 51, 32, 97, 114, 103, 52
                    ],
                    "incorrect value for msg.cmdline, expected string '{:?}', is '{:?}'",
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 112, 114, 111, 99, 101, 115, 115,
                        45, 110, 97, 109, 101, 32, 97, 114, 103, 48, 32, 97, 114, 103, 49, 32, 97,
                        114, 103, 50, 32, 97, 114, 103, 51, 32, 97, 114, 103, 52
                    ],
                    msg.cmdline.as_bytes()
                );
                assert_eq!(
                    msg.fd_count, 35589,
                    "incorrect value for fd_count, expected 35589, is {}",
                    msg.fd_count
                );
                assert_eq!(
                    msg.index, 164,
                    "incorrect value for index, expected 164, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.pid, 42429,
                    "incorrect value for pid, expected 42429, is {}",
                    msg.pid
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxProcessFdCount"),
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
fn test_json2sbp_auto_check_sbp_linux_msg_linux_process_fd_count() {
    {
        let json_input = r#"{"crc":24066,"length":51,"msg_type":32518,"payload":"pL2lBYsvcGF0aC90by9wcm9jZXNzLW5hbWUgYXJnMCBhcmcxIGFyZzIgYXJnMyBhcmc0","preamble":85,"sender":49950,"index":164,"pid":42429,"fd_count":35589,"cmdline":"/path/to/process-name arg0 arg1 arg2 arg3 arg4"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgLinuxProcessFdCount(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f06,
                    "Incorrect message type, expected 0x7f06, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc31e,
                    "incorrect sender id, expected 0xc31e, is {sender_id}"
                );
                assert_eq!(
                    msg.cmdline.as_bytes(),
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 112, 114, 111, 99, 101, 115, 115,
                        45, 110, 97, 109, 101, 32, 97, 114, 103, 48, 32, 97, 114, 103, 49, 32, 97,
                        114, 103, 50, 32, 97, 114, 103, 51, 32, 97, 114, 103, 52
                    ],
                    "incorrect value for msg.cmdline, expected string '{:?}', is '{:?}'",
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 112, 114, 111, 99, 101, 115, 115,
                        45, 110, 97, 109, 101, 32, 97, 114, 103, 48, 32, 97, 114, 103, 49, 32, 97,
                        114, 103, 50, 32, 97, 114, 103, 51, 32, 97, 114, 103, 52
                    ],
                    msg.cmdline.as_bytes()
                );
                assert_eq!(
                    msg.fd_count, 35589,
                    "incorrect value for fd_count, expected 35589, is {}",
                    msg.fd_count
                );
                assert_eq!(
                    msg.index, 164,
                    "incorrect value for index, expected 164, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.pid, 42429,
                    "incorrect value for pid, expected 42429, is {}",
                    msg.pid
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxProcessFdCount"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_linux_msg_linux_process_fd_count`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_linux_msg_linux_process_fd_count() {
    {
        let mut payload = Cursor::new(vec![
            85, 6, 127, 30, 195, 51, 164, 189, 165, 5, 139, 47, 112, 97, 116, 104, 47, 116, 111,
            47, 112, 114, 111, 99, 101, 115, 115, 45, 110, 97, 109, 101, 32, 97, 114, 103, 48, 32,
            97, 114, 103, 49, 32, 97, 114, 103, 50, 32, 97, 114, 103, 51, 32, 97, 114, 103, 52, 2,
            94,
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
        let sbp_msg = sbp::messages::Sbp::MsgLinuxProcessFdCount(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxProcessFdCount(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f06,
                    "Incorrect message type, expected 0x7f06, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc31e,
                    "incorrect sender id, expected 0xc31e, is {sender_id}"
                );
                assert_eq!(
                    msg.cmdline.as_bytes(),
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 112, 114, 111, 99, 101, 115, 115,
                        45, 110, 97, 109, 101, 32, 97, 114, 103, 48, 32, 97, 114, 103, 49, 32, 97,
                        114, 103, 50, 32, 97, 114, 103, 51, 32, 97, 114, 103, 52
                    ],
                    "incorrect value for msg.cmdline, expected string '{:?}', is '{:?}'",
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 112, 114, 111, 99, 101, 115, 115,
                        45, 110, 97, 109, 101, 32, 97, 114, 103, 48, 32, 97, 114, 103, 49, 32, 97,
                        114, 103, 50, 32, 97, 114, 103, 51, 32, 97, 114, 103, 52
                    ],
                    msg.cmdline.as_bytes()
                );
                assert_eq!(
                    msg.fd_count, 35589,
                    "incorrect value for fd_count, expected 35589, is {}",
                    msg.fd_count
                );
                assert_eq!(
                    msg.index, 164,
                    "incorrect value for index, expected 164, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.pid, 42429,
                    "incorrect value for pid, expected 42429, is {}",
                    msg.pid
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxProcessFdCount"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
