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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSysState.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_linux_msg_linux_sys_state() {
    {
        let mut payload = Cursor::new(vec![
            85, 10, 127, 85, 167, 15, 20, 207, 125, 215, 196, 71, 161, 229, 250, 186, 108, 30, 106,
            5, 9, 229, 242,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxSysState(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f0a,
                    "Incorrect message type, expected 0x7f0a, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xa755,
                    "incorrect sender id, expected 0xa755, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 9,
                    "incorrect value for flags, expected 9, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.mem_total, 53012,
                    "incorrect value for mem_total, expected 53012, is {}",
                    msg.mem_total
                );
                assert_eq!(
                    msg.pcpu, 125,
                    "incorrect value for pcpu, expected 125, is {}",
                    msg.pcpu
                );
                assert_eq!(
                    msg.pid_count, 47866,
                    "incorrect value for pid_count, expected 47866, is {}",
                    msg.pid_count
                );
                assert_eq!(
                    msg.pmem, 215,
                    "incorrect value for pmem, expected 215, is {}",
                    msg.pmem
                );
                assert_eq!(
                    msg.procs_starting, 18372,
                    "incorrect value for procs_starting, expected 18372, is {}",
                    msg.procs_starting
                );
                assert_eq!(
                    msg.procs_stopping, 58785,
                    "incorrect value for procs_stopping, expected 58785, is {}",
                    msg.procs_stopping
                );
                assert_eq!(
                    msg.time, 90840684,
                    "incorrect value for time, expected 90840684, is {}",
                    msg.time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxSysState"),
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
fn test_json2sbp_auto_check_sbp_linux_msg_linux_sys_state() {
    {
        let json_input = r#"{"crc":62181,"length":15,"msg_type":32522,"payload":"FM9918RHoeX6umweagUJ","preamble":85,"sender":42837,"mem_total":53012,"pcpu":125,"pmem":215,"procs_starting":18372,"procs_stopping":58785,"pid_count":47866,"time":90840684,"flags":9}"#.as_bytes();

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
            sbp::messages::Sbp::MsgLinuxSysState(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f0a,
                    "Incorrect message type, expected 0x7f0a, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xa755,
                    "incorrect sender id, expected 0xa755, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 9,
                    "incorrect value for flags, expected 9, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.mem_total, 53012,
                    "incorrect value for mem_total, expected 53012, is {}",
                    msg.mem_total
                );
                assert_eq!(
                    msg.pcpu, 125,
                    "incorrect value for pcpu, expected 125, is {}",
                    msg.pcpu
                );
                assert_eq!(
                    msg.pid_count, 47866,
                    "incorrect value for pid_count, expected 47866, is {}",
                    msg.pid_count
                );
                assert_eq!(
                    msg.pmem, 215,
                    "incorrect value for pmem, expected 215, is {}",
                    msg.pmem
                );
                assert_eq!(
                    msg.procs_starting, 18372,
                    "incorrect value for procs_starting, expected 18372, is {}",
                    msg.procs_starting
                );
                assert_eq!(
                    msg.procs_stopping, 58785,
                    "incorrect value for procs_stopping, expected 58785, is {}",
                    msg.procs_stopping
                );
                assert_eq!(
                    msg.time, 90840684,
                    "incorrect value for time, expected 90840684, is {}",
                    msg.time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxSysState"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_linux_msg_linux_sys_state`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_linux_msg_linux_sys_state() {
    {
        let mut payload = Cursor::new(vec![
            85, 10, 127, 85, 167, 15, 20, 207, 125, 215, 196, 71, 161, 229, 250, 186, 108, 30, 106,
            5, 9, 229, 242,
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
        let sbp_msg = sbp::messages::Sbp::MsgLinuxSysState(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxSysState(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f0a,
                    "Incorrect message type, expected 0x7f0a, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xa755,
                    "incorrect sender id, expected 0xa755, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 9,
                    "incorrect value for flags, expected 9, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.mem_total, 53012,
                    "incorrect value for mem_total, expected 53012, is {}",
                    msg.mem_total
                );
                assert_eq!(
                    msg.pcpu, 125,
                    "incorrect value for pcpu, expected 125, is {}",
                    msg.pcpu
                );
                assert_eq!(
                    msg.pid_count, 47866,
                    "incorrect value for pid_count, expected 47866, is {}",
                    msg.pid_count
                );
                assert_eq!(
                    msg.pmem, 215,
                    "incorrect value for pmem, expected 215, is {}",
                    msg.pmem
                );
                assert_eq!(
                    msg.procs_starting, 18372,
                    "incorrect value for procs_starting, expected 18372, is {}",
                    msg.procs_starting
                );
                assert_eq!(
                    msg.procs_stopping, 58785,
                    "incorrect value for procs_stopping, expected 58785, is {}",
                    msg.procs_stopping
                );
                assert_eq!(
                    msg.time, 90840684,
                    "incorrect value for time, expected 90840684, is {}",
                    msg.time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxSysState"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
