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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxCpuState.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_linux_msg_linux_cpu_state() {
    {
        let mut payload = Cursor::new(vec![
            85, 8, 127, 148, 133, 70, 101, 122, 195, 98, 215, 35, 94, 235, 20, 112, 114, 111, 99,
            101, 115, 115, 45, 110, 97, 109, 101, 0, 0, 0, 47, 112, 97, 116, 104, 47, 116, 111, 47,
            112, 114, 111, 99, 101, 115, 115, 45, 110, 97, 109, 101, 32, 97, 114, 103, 48, 32, 97,
            114, 103, 49, 32, 97, 114, 103, 50, 32, 97, 114, 103, 51, 32, 97, 114, 103, 52, 68,
            229,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxCpuState(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f08,
                    "Incorrect message type, expected 0x7f08, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x8594,
                    "incorrect sender id, expected 0x8594, is {sender_id}"
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
                    msg.flags, 20,
                    "incorrect value for flags, expected 20, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.index, 101,
                    "incorrect value for index, expected 101, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.pcpu, 98,
                    "incorrect value for pcpu, expected 98, is {}",
                    msg.pcpu
                );
                assert_eq!(
                    msg.pid, 50042,
                    "incorrect value for pid, expected 50042, is {}",
                    msg.pid
                );
                assert_eq!(
                    msg.time, 3948815319,
                    "incorrect value for time, expected 3948815319, is {}",
                    msg.time
                );
                assert_eq!(
                    msg.tname.as_bytes(),
                    &[112, 114, 111, 99, 101, 115, 115, 45, 110, 97, 109, 101, 0, 0, 0],
                    "incorrect value for msg.tname, expected string '{:?}', is '{:?}'",
                    &[112, 114, 111, 99, 101, 115, 115, 45, 110, 97, 109, 101, 0, 0, 0],
                    msg.tname.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxCpuState"),
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
fn test_json2sbp_auto_check_sbp_linux_msg_linux_cpu_state() {
    {
        let json_input = r#"{"crc":58692,"length":70,"msg_type":32520,"payload":"ZXrDYtcjXusUcHJvY2Vzcy1uYW1lAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNA==","preamble":85,"sender":34196,"index":101,"pid":50042,"pcpu":98,"time":3948815319,"flags":20,"tname":"process-name\u0000\u0000\u0000","cmdline":"/path/to/process-name arg0 arg1 arg2 arg3 arg4"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgLinuxCpuState(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f08,
                    "Incorrect message type, expected 0x7f08, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x8594,
                    "incorrect sender id, expected 0x8594, is {sender_id}"
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
                    msg.flags, 20,
                    "incorrect value for flags, expected 20, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.index, 101,
                    "incorrect value for index, expected 101, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.pcpu, 98,
                    "incorrect value for pcpu, expected 98, is {}",
                    msg.pcpu
                );
                assert_eq!(
                    msg.pid, 50042,
                    "incorrect value for pid, expected 50042, is {}",
                    msg.pid
                );
                assert_eq!(
                    msg.time, 3948815319,
                    "incorrect value for time, expected 3948815319, is {}",
                    msg.time
                );
                assert_eq!(
                    msg.tname.as_bytes(),
                    &[112, 114, 111, 99, 101, 115, 115, 45, 110, 97, 109, 101, 0, 0, 0],
                    "incorrect value for msg.tname, expected string '{:?}', is '{:?}'",
                    &[112, 114, 111, 99, 101, 115, 115, 45, 110, 97, 109, 101, 0, 0, 0],
                    msg.tname.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxCpuState"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_linux_msg_linux_cpu_state`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_linux_msg_linux_cpu_state() {
    {
        let mut payload = Cursor::new(vec![
            85, 8, 127, 148, 133, 70, 101, 122, 195, 98, 215, 35, 94, 235, 20, 112, 114, 111, 99,
            101, 115, 115, 45, 110, 97, 109, 101, 0, 0, 0, 47, 112, 97, 116, 104, 47, 116, 111, 47,
            112, 114, 111, 99, 101, 115, 115, 45, 110, 97, 109, 101, 32, 97, 114, 103, 48, 32, 97,
            114, 103, 49, 32, 97, 114, 103, 50, 32, 97, 114, 103, 51, 32, 97, 114, 103, 52, 68,
            229,
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
        let sbp_msg = sbp::messages::Sbp::MsgLinuxCpuState(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxCpuState(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f08,
                    "Incorrect message type, expected 0x7f08, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x8594,
                    "incorrect sender id, expected 0x8594, is {sender_id}"
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
                    msg.flags, 20,
                    "incorrect value for flags, expected 20, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.index, 101,
                    "incorrect value for index, expected 101, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.pcpu, 98,
                    "incorrect value for pcpu, expected 98, is {}",
                    msg.pcpu
                );
                assert_eq!(
                    msg.pid, 50042,
                    "incorrect value for pid, expected 50042, is {}",
                    msg.pid
                );
                assert_eq!(
                    msg.time, 3948815319,
                    "incorrect value for time, expected 3948815319, is {}",
                    msg.time
                );
                assert_eq!(
                    msg.tname.as_bytes(),
                    &[112, 114, 111, 99, 101, 115, 115, 45, 110, 97, 109, 101, 0, 0, 0],
                    "incorrect value for msg.tname, expected string '{:?}', is '{:?}'",
                    &[112, 114, 111, 99, 101, 115, 115, 45, 110, 97, 109, 101, 0, 0, 0],
                    msg.tname.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxCpuState"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
