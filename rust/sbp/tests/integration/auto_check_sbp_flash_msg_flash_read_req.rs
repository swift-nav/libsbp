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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashReadReq.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_flash_msg_flash_read_req() {
    {
        let mut payload = Cursor::new(vec![85, 231, 0, 195, 4, 5, 241, 28, 75, 244, 71, 210, 57]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgFlashReadReq(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xe7,
                    "Incorrect message type, expected 0xe7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.addr_len, 71,
                    "incorrect value for addr_len, expected 71, is {}",
                    msg.addr_len
                );
                assert_eq!(
                    msg.addr_start[0], 28,
                    "incorrect value for addr_start[0], expected 28, is {}",
                    msg.addr_start[0]
                );
                assert_eq!(
                    msg.addr_start[1], 75,
                    "incorrect value for addr_start[1], expected 75, is {}",
                    msg.addr_start[1]
                );
                assert_eq!(
                    msg.addr_start[2], 244,
                    "incorrect value for addr_start[2], expected 244, is {}",
                    msg.addr_start[2]
                );
                assert_eq!(
                    msg.target, 241,
                    "incorrect value for target, expected 241, is {}",
                    msg.target
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFlashReadReq"),
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
fn test_json2sbp_auto_check_sbp_flash_msg_flash_read_req() {
    {
        let json_input = r#"{"crc":14802,"length":5,"msg_type":231,"payload":"8RxL9Ec=","preamble":85,"sender":1219,"target":241,"addr_start":[28,75,244],"addr_len":71}"#.as_bytes();

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
            sbp::messages::Sbp::MsgFlashReadReq(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xe7,
                    "Incorrect message type, expected 0xe7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.addr_len, 71,
                    "incorrect value for addr_len, expected 71, is {}",
                    msg.addr_len
                );
                assert_eq!(
                    msg.addr_start[0], 28,
                    "incorrect value for addr_start[0], expected 28, is {}",
                    msg.addr_start[0]
                );
                assert_eq!(
                    msg.addr_start[1], 75,
                    "incorrect value for addr_start[1], expected 75, is {}",
                    msg.addr_start[1]
                );
                assert_eq!(
                    msg.addr_start[2], 244,
                    "incorrect value for addr_start[2], expected 244, is {}",
                    msg.addr_start[2]
                );
                assert_eq!(
                    msg.target, 241,
                    "incorrect value for target, expected 241, is {}",
                    msg.target
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFlashReadReq"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_flash_msg_flash_read_req`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_flash_msg_flash_read_req() {
    {
        let mut payload = Cursor::new(vec![85, 231, 0, 195, 4, 5, 241, 28, 75, 244, 71, 210, 57]);

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
        let sbp_msg = sbp::messages::Sbp::MsgFlashReadReq(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgFlashReadReq(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xe7,
                    "Incorrect message type, expected 0xe7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.addr_len, 71,
                    "incorrect value for addr_len, expected 71, is {}",
                    msg.addr_len
                );
                assert_eq!(
                    msg.addr_start[0], 28,
                    "incorrect value for addr_start[0], expected 28, is {}",
                    msg.addr_start[0]
                );
                assert_eq!(
                    msg.addr_start[1], 75,
                    "incorrect value for addr_start[1], expected 75, is {}",
                    msg.addr_start[1]
                );
                assert_eq!(
                    msg.addr_start[2], 244,
                    "incorrect value for addr_start[2], expected 244, is {}",
                    msg.addr_start[2]
                );
                assert_eq!(
                    msg.target, 241,
                    "incorrect value for target, expected 241, is {}",
                    msg.target
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFlashReadReq"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
