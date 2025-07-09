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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSysStateDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_linux_msg_linux_sys_state_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 2, 127, 84, 56, 10, 188, 163, 211, 194, 115, 71, 101, 103, 124, 201, 223, 223,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxSysStateDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f02,
                    "Incorrect message type, expected 0x7f02, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x3854,
                    "incorrect sender id, expected 0x3854, is {sender_id}"
                );
                assert_eq!(
                    msg.mem_total, 41916,
                    "incorrect value for mem_total, expected 41916, is {}",
                    msg.mem_total
                );
                assert_eq!(
                    msg.pcpu, 211,
                    "incorrect value for pcpu, expected 211, is {}",
                    msg.pcpu
                );
                assert_eq!(
                    msg.pid_count, 51580,
                    "incorrect value for pid_count, expected 51580, is {}",
                    msg.pid_count
                );
                assert_eq!(
                    msg.pmem, 194,
                    "incorrect value for pmem, expected 194, is {}",
                    msg.pmem
                );
                assert_eq!(
                    msg.procs_starting, 18291,
                    "incorrect value for procs_starting, expected 18291, is {}",
                    msg.procs_starting
                );
                assert_eq!(
                    msg.procs_stopping, 26469,
                    "incorrect value for procs_stopping, expected 26469, is {}",
                    msg.procs_stopping
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxSysStateDepA"),
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
fn test_json2sbp_auto_check_sbp_linux_msg_linux_sys_state_dep_a() {
    {
        let json_input = r#"{"crc":57311,"length":10,"msg_type":32514,"payload":"vKPTwnNHZWd8yQ==","preamble":85,"sender":14420,"mem_total":41916,"pcpu":211,"pmem":194,"procs_starting":18291,"procs_stopping":26469,"pid_count":51580}"#.as_bytes();

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
            sbp::messages::Sbp::MsgLinuxSysStateDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f02,
                    "Incorrect message type, expected 0x7f02, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x3854,
                    "incorrect sender id, expected 0x3854, is {sender_id}"
                );
                assert_eq!(
                    msg.mem_total, 41916,
                    "incorrect value for mem_total, expected 41916, is {}",
                    msg.mem_total
                );
                assert_eq!(
                    msg.pcpu, 211,
                    "incorrect value for pcpu, expected 211, is {}",
                    msg.pcpu
                );
                assert_eq!(
                    msg.pid_count, 51580,
                    "incorrect value for pid_count, expected 51580, is {}",
                    msg.pid_count
                );
                assert_eq!(
                    msg.pmem, 194,
                    "incorrect value for pmem, expected 194, is {}",
                    msg.pmem
                );
                assert_eq!(
                    msg.procs_starting, 18291,
                    "incorrect value for procs_starting, expected 18291, is {}",
                    msg.procs_starting
                );
                assert_eq!(
                    msg.procs_stopping, 26469,
                    "incorrect value for procs_stopping, expected 26469, is {}",
                    msg.procs_stopping
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxSysStateDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_linux_msg_linux_sys_state_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_linux_msg_linux_sys_state_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 2, 127, 84, 56, 10, 188, 163, 211, 194, 115, 71, 101, 103, 124, 201, 223, 223,
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
        let sbp_msg = sbp::messages::Sbp::MsgLinuxSysStateDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxSysStateDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f02,
                    "Incorrect message type, expected 0x7f02, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x3854,
                    "incorrect sender id, expected 0x3854, is {sender_id}"
                );
                assert_eq!(
                    msg.mem_total, 41916,
                    "incorrect value for mem_total, expected 41916, is {}",
                    msg.mem_total
                );
                assert_eq!(
                    msg.pcpu, 211,
                    "incorrect value for pcpu, expected 211, is {}",
                    msg.pcpu
                );
                assert_eq!(
                    msg.pid_count, 51580,
                    "incorrect value for pid_count, expected 51580, is {}",
                    msg.pid_count
                );
                assert_eq!(
                    msg.pmem, 194,
                    "incorrect value for pmem, expected 194, is {}",
                    msg.pmem
                );
                assert_eq!(
                    msg.procs_starting, 18291,
                    "incorrect value for procs_starting, expected 18291, is {}",
                    msg.procs_starting
                );
                assert_eq!(
                    msg.procs_stopping, 26469,
                    "incorrect value for procs_stopping, expected 26469, is {}",
                    msg.procs_stopping
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxSysStateDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
