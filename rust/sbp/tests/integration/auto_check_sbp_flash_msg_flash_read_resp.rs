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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashReadResp.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_flash_msg_flash_read_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 225, 0, 195, 4, 5, 136, 155, 52, 172, 124, 149, 135,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgFlashReadResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xe1,
                    "Incorrect message type, expected 0xe1, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.addr_len, 124,
                    "incorrect value for addr_len, expected 124, is {}",
                    msg.addr_len
                );
                assert_eq!(
                    msg.addr_start[0], 155,
                    "incorrect value for addr_start[0], expected 155, is {}",
                    msg.addr_start[0]
                );
                assert_eq!(
                    msg.addr_start[1], 52,
                    "incorrect value for addr_start[1], expected 52, is {}",
                    msg.addr_start[1]
                );
                assert_eq!(
                    msg.addr_start[2], 172,
                    "incorrect value for addr_start[2], expected 172, is {}",
                    msg.addr_start[2]
                );
                assert_eq!(
                    msg.target, 136,
                    "incorrect value for target, expected 136, is {}",
                    msg.target
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFlashReadResp"),
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
fn test_json2sbp_auto_check_sbp_flash_msg_flash_read_resp() {
    {
        let json_input = r#"{"crc":34709,"length":5,"msg_type":225,"payload":"iJs0rHw=","preamble":85,"sender":1219,"target":136,"addr_start":[155,52,172],"addr_len":124}"#.as_bytes();

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
            sbp::messages::Sbp::MsgFlashReadResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xe1,
                    "Incorrect message type, expected 0xe1, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.addr_len, 124,
                    "incorrect value for addr_len, expected 124, is {}",
                    msg.addr_len
                );
                assert_eq!(
                    msg.addr_start[0], 155,
                    "incorrect value for addr_start[0], expected 155, is {}",
                    msg.addr_start[0]
                );
                assert_eq!(
                    msg.addr_start[1], 52,
                    "incorrect value for addr_start[1], expected 52, is {}",
                    msg.addr_start[1]
                );
                assert_eq!(
                    msg.addr_start[2], 172,
                    "incorrect value for addr_start[2], expected 172, is {}",
                    msg.addr_start[2]
                );
                assert_eq!(
                    msg.target, 136,
                    "incorrect value for target, expected 136, is {}",
                    msg.target
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFlashReadResp"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_flash_msg_flash_read_resp`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_flash_msg_flash_read_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 225, 0, 195, 4, 5, 136, 155, 52, 172, 124, 149, 135,
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
        let sbp_msg = sbp::messages::Sbp::MsgFlashReadResp(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgFlashReadResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xe1,
                    "Incorrect message type, expected 0xe1, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.addr_len, 124,
                    "incorrect value for addr_len, expected 124, is {}",
                    msg.addr_len
                );
                assert_eq!(
                    msg.addr_start[0], 155,
                    "incorrect value for addr_start[0], expected 155, is {}",
                    msg.addr_start[0]
                );
                assert_eq!(
                    msg.addr_start[1], 52,
                    "incorrect value for addr_start[1], expected 52, is {}",
                    msg.addr_start[1]
                );
                assert_eq!(
                    msg.addr_start[2], 172,
                    "incorrect value for addr_start[2], expected 172, is {}",
                    msg.addr_start[2]
                );
                assert_eq!(
                    msg.target, 136,
                    "incorrect value for target, expected 136, is {}",
                    msg.target
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFlashReadResp"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
