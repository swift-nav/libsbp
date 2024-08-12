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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessSocketQueues.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_linux_msg_linux_process_socket_queues() {
    {
        let mut payload = Cursor::new(vec![
            85, 4, 127, 187, 232, 121, 181, 135, 75, 249, 211, 35, 252, 80, 109, 15, 223, 97, 100,
            100, 114, 101, 115, 115, 32, 111, 102, 32, 108, 97, 114, 103, 101, 115, 116, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 47, 112, 97, 116, 104, 47, 116, 111, 47, 112,
            114, 111, 99, 101, 115, 115, 45, 110, 97, 109, 101, 32, 97, 114, 103, 48, 32, 97, 114,
            103, 49, 32, 97, 114, 103, 50, 32, 97, 114, 103, 51, 32, 97, 114, 103, 52, 2, 247,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxProcessSocketQueues(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f04,
                    "Incorrect message type, expected 0x7f04, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xe8bb,
                    "incorrect sender id, expected 0xe8bb, is {sender_id}"
                );
                assert_eq!(
                    msg.address_of_largest.as_bytes(),
                    &[
                        97, 100, 100, 114, 101, 115, 115, 32, 111, 102, 32, 108, 97, 114, 103, 101,
                        115, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    "incorrect value for msg.address_of_largest, expected string '{:?}', is '{:?}'",
                    &[
                        97, 100, 100, 114, 101, 115, 115, 32, 111, 102, 32, 108, 97, 114, 103, 101,
                        115, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    msg.address_of_largest.as_bytes()
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
                    msg.index, 181,
                    "incorrect value for index, expected 181, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.pid, 19335,
                    "incorrect value for pid, expected 19335, is {}",
                    msg.pid
                );
                assert_eq!(
                    msg.recv_queued, 54265,
                    "incorrect value for recv_queued, expected 54265, is {}",
                    msg.recv_queued
                );
                assert_eq!(
                    msg.send_queued, 64547,
                    "incorrect value for send_queued, expected 64547, is {}",
                    msg.send_queued
                );
                assert_eq!(
                    msg.socket_states, 57103,
                    "incorrect value for socket_states, expected 57103, is {}",
                    msg.socket_states
                );
                assert_eq!(
                    msg.socket_types, 27984,
                    "incorrect value for socket_types, expected 27984, is {}",
                    msg.socket_types
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxProcessSocketQueues"),
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
fn test_json2sbp_auto_check_sbp_linux_msg_linux_process_socket_queues() {
    {
        let json_input = r#"{"crc":63234,"length":121,"msg_type":32516,"payload":"tYdL+dMj/FBtD99hZGRyZXNzIG9mIGxhcmdlc3QAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNA==","preamble":85,"sender":59579,"index":181,"pid":19335,"recv_queued":54265,"send_queued":64547,"socket_types":27984,"socket_states":57103,"address_of_largest":"address of largest\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","cmdline":"/path/to/process-name arg0 arg1 arg2 arg3 arg4"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgLinuxProcessSocketQueues(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f04,
                    "Incorrect message type, expected 0x7f04, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xe8bb,
                    "incorrect sender id, expected 0xe8bb, is {sender_id}"
                );
                assert_eq!(
                    msg.address_of_largest.as_bytes(),
                    &[
                        97, 100, 100, 114, 101, 115, 115, 32, 111, 102, 32, 108, 97, 114, 103, 101,
                        115, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    "incorrect value for msg.address_of_largest, expected string '{:?}', is '{:?}'",
                    &[
                        97, 100, 100, 114, 101, 115, 115, 32, 111, 102, 32, 108, 97, 114, 103, 101,
                        115, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    msg.address_of_largest.as_bytes()
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
                    msg.index, 181,
                    "incorrect value for index, expected 181, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.pid, 19335,
                    "incorrect value for pid, expected 19335, is {}",
                    msg.pid
                );
                assert_eq!(
                    msg.recv_queued, 54265,
                    "incorrect value for recv_queued, expected 54265, is {}",
                    msg.recv_queued
                );
                assert_eq!(
                    msg.send_queued, 64547,
                    "incorrect value for send_queued, expected 64547, is {}",
                    msg.send_queued
                );
                assert_eq!(
                    msg.socket_states, 57103,
                    "incorrect value for socket_states, expected 57103, is {}",
                    msg.socket_states
                );
                assert_eq!(
                    msg.socket_types, 27984,
                    "incorrect value for socket_types, expected 27984, is {}",
                    msg.socket_types
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxProcessSocketQueues"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_linux_msg_linux_process_socket_queues`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_linux_msg_linux_process_socket_queues() {
    {
        let mut payload = Cursor::new(vec![
            85, 4, 127, 187, 232, 121, 181, 135, 75, 249, 211, 35, 252, 80, 109, 15, 223, 97, 100,
            100, 114, 101, 115, 115, 32, 111, 102, 32, 108, 97, 114, 103, 101, 115, 116, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 47, 112, 97, 116, 104, 47, 116, 111, 47, 112,
            114, 111, 99, 101, 115, 115, 45, 110, 97, 109, 101, 32, 97, 114, 103, 48, 32, 97, 114,
            103, 49, 32, 97, 114, 103, 50, 32, 97, 114, 103, 51, 32, 97, 114, 103, 52, 2, 247,
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
        let sbp_msg = sbp::messages::Sbp::MsgLinuxProcessSocketQueues(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxProcessSocketQueues(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f04,
                    "Incorrect message type, expected 0x7f04, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xe8bb,
                    "incorrect sender id, expected 0xe8bb, is {sender_id}"
                );
                assert_eq!(
                    msg.address_of_largest.as_bytes(),
                    &[
                        97, 100, 100, 114, 101, 115, 115, 32, 111, 102, 32, 108, 97, 114, 103, 101,
                        115, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    "incorrect value for msg.address_of_largest, expected string '{:?}', is '{:?}'",
                    &[
                        97, 100, 100, 114, 101, 115, 115, 32, 111, 102, 32, 108, 97, 114, 103, 101,
                        115, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    msg.address_of_largest.as_bytes()
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
                    msg.index, 181,
                    "incorrect value for index, expected 181, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.pid, 19335,
                    "incorrect value for pid, expected 19335, is {}",
                    msg.pid
                );
                assert_eq!(
                    msg.recv_queued, 54265,
                    "incorrect value for recv_queued, expected 54265, is {}",
                    msg.recv_queued
                );
                assert_eq!(
                    msg.send_queued, 64547,
                    "incorrect value for send_queued, expected 64547, is {}",
                    msg.send_queued
                );
                assert_eq!(
                    msg.socket_states, 57103,
                    "incorrect value for socket_states, expected 57103, is {}",
                    msg.socket_states
                );
                assert_eq!(
                    msg.socket_types, 27984,
                    "incorrect value for socket_types, expected 27984, is {}",
                    msg.socket_types
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxProcessSocketQueues"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
