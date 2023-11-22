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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgStmUniqueIdResp.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_flash_msg_stm_unique_id_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 229, 0, 195, 4, 12, 196, 16, 15, 163, 85, 221, 119, 102, 32, 194, 56, 144, 221, 196,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgStmUniqueIdResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xe5,
                    "Incorrect message type, expected 0xe5, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.stm_id[0], 196,
                    "incorrect value for stm_id[0], expected 196, is {}",
                    msg.stm_id[0]
                );
                assert_eq!(
                    msg.stm_id[1], 16,
                    "incorrect value for stm_id[1], expected 16, is {}",
                    msg.stm_id[1]
                );
                assert_eq!(
                    msg.stm_id[2], 15,
                    "incorrect value for stm_id[2], expected 15, is {}",
                    msg.stm_id[2]
                );
                assert_eq!(
                    msg.stm_id[3], 163,
                    "incorrect value for stm_id[3], expected 163, is {}",
                    msg.stm_id[3]
                );
                assert_eq!(
                    msg.stm_id[4], 85,
                    "incorrect value for stm_id[4], expected 85, is {}",
                    msg.stm_id[4]
                );
                assert_eq!(
                    msg.stm_id[5], 221,
                    "incorrect value for stm_id[5], expected 221, is {}",
                    msg.stm_id[5]
                );
                assert_eq!(
                    msg.stm_id[6], 119,
                    "incorrect value for stm_id[6], expected 119, is {}",
                    msg.stm_id[6]
                );
                assert_eq!(
                    msg.stm_id[7], 102,
                    "incorrect value for stm_id[7], expected 102, is {}",
                    msg.stm_id[7]
                );
                assert_eq!(
                    msg.stm_id[8], 32,
                    "incorrect value for stm_id[8], expected 32, is {}",
                    msg.stm_id[8]
                );
                assert_eq!(
                    msg.stm_id[9], 194,
                    "incorrect value for stm_id[9], expected 194, is {}",
                    msg.stm_id[9]
                );
                assert_eq!(
                    msg.stm_id[10], 56,
                    "incorrect value for stm_id[10], expected 56, is {}",
                    msg.stm_id[10]
                );
                assert_eq!(
                    msg.stm_id[11], 144,
                    "incorrect value for stm_id[11], expected 144, is {}",
                    msg.stm_id[11]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgStmUniqueIdResp"),
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
fn test_json2sbp_auto_check_sbp_flash_msg_stm_unique_id_resp() {
    {
        let json_input = r#"{"crc":50397,"length":12,"msg_type":229,"payload":"xBAPo1Xdd2YgwjiQ","preamble":85,"sender":1219,"stm_id":[196,16,15,163,85,221,119,102,32,194,56,144]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgStmUniqueIdResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xe5,
                    "Incorrect message type, expected 0xe5, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.stm_id[0], 196,
                    "incorrect value for stm_id[0], expected 196, is {}",
                    msg.stm_id[0]
                );
                assert_eq!(
                    msg.stm_id[1], 16,
                    "incorrect value for stm_id[1], expected 16, is {}",
                    msg.stm_id[1]
                );
                assert_eq!(
                    msg.stm_id[2], 15,
                    "incorrect value for stm_id[2], expected 15, is {}",
                    msg.stm_id[2]
                );
                assert_eq!(
                    msg.stm_id[3], 163,
                    "incorrect value for stm_id[3], expected 163, is {}",
                    msg.stm_id[3]
                );
                assert_eq!(
                    msg.stm_id[4], 85,
                    "incorrect value for stm_id[4], expected 85, is {}",
                    msg.stm_id[4]
                );
                assert_eq!(
                    msg.stm_id[5], 221,
                    "incorrect value for stm_id[5], expected 221, is {}",
                    msg.stm_id[5]
                );
                assert_eq!(
                    msg.stm_id[6], 119,
                    "incorrect value for stm_id[6], expected 119, is {}",
                    msg.stm_id[6]
                );
                assert_eq!(
                    msg.stm_id[7], 102,
                    "incorrect value for stm_id[7], expected 102, is {}",
                    msg.stm_id[7]
                );
                assert_eq!(
                    msg.stm_id[8], 32,
                    "incorrect value for stm_id[8], expected 32, is {}",
                    msg.stm_id[8]
                );
                assert_eq!(
                    msg.stm_id[9], 194,
                    "incorrect value for stm_id[9], expected 194, is {}",
                    msg.stm_id[9]
                );
                assert_eq!(
                    msg.stm_id[10], 56,
                    "incorrect value for stm_id[10], expected 56, is {}",
                    msg.stm_id[10]
                );
                assert_eq!(
                    msg.stm_id[11], 144,
                    "incorrect value for stm_id[11], expected 144, is {}",
                    msg.stm_id[11]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgStmUniqueIdResp"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_flash_msg_stm_unique_id_resp`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_flash_msg_stm_unique_id_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 229, 0, 195, 4, 12, 196, 16, 15, 163, 85, 221, 119, 102, 32, 194, 56, 144, 221, 196,
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
        let sbp_msg = sbp::messages::Sbp::MsgStmUniqueIdResp(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgStmUniqueIdResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xe5,
                    "Incorrect message type, expected 0xe5, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.stm_id[0], 196,
                    "incorrect value for stm_id[0], expected 196, is {}",
                    msg.stm_id[0]
                );
                assert_eq!(
                    msg.stm_id[1], 16,
                    "incorrect value for stm_id[1], expected 16, is {}",
                    msg.stm_id[1]
                );
                assert_eq!(
                    msg.stm_id[2], 15,
                    "incorrect value for stm_id[2], expected 15, is {}",
                    msg.stm_id[2]
                );
                assert_eq!(
                    msg.stm_id[3], 163,
                    "incorrect value for stm_id[3], expected 163, is {}",
                    msg.stm_id[3]
                );
                assert_eq!(
                    msg.stm_id[4], 85,
                    "incorrect value for stm_id[4], expected 85, is {}",
                    msg.stm_id[4]
                );
                assert_eq!(
                    msg.stm_id[5], 221,
                    "incorrect value for stm_id[5], expected 221, is {}",
                    msg.stm_id[5]
                );
                assert_eq!(
                    msg.stm_id[6], 119,
                    "incorrect value for stm_id[6], expected 119, is {}",
                    msg.stm_id[6]
                );
                assert_eq!(
                    msg.stm_id[7], 102,
                    "incorrect value for stm_id[7], expected 102, is {}",
                    msg.stm_id[7]
                );
                assert_eq!(
                    msg.stm_id[8], 32,
                    "incorrect value for stm_id[8], expected 32, is {}",
                    msg.stm_id[8]
                );
                assert_eq!(
                    msg.stm_id[9], 194,
                    "incorrect value for stm_id[9], expected 194, is {}",
                    msg.stm_id[9]
                );
                assert_eq!(
                    msg.stm_id[10], 56,
                    "incorrect value for stm_id[10], expected 56, is {}",
                    msg.stm_id[10]
                );
                assert_eq!(
                    msg.stm_id[11], 144,
                    "incorrect value for stm_id[11], expected 144, is {}",
                    msg.stm_id[11]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgStmUniqueIdResp"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
