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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgAcknowledge.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_integrity_msg_acknowledge() {
    {
        let mut payload = Cursor::new(vec![
            85, 210, 11, 42, 0, 11, 30, 64, 226, 1, 0, 0, 1, 0, 1, 0, 2, 86, 178,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcknowledge(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xBD2,
                    "Incorrect message type, expected 0xBD2, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2A,
                    "incorrect sender id, expected 0x2A, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.area_id, 123456,
                    "incorrect value for area_id, expected 123456, is {}",
                    msg.area_id
                );
                assert_eq!(
                    msg.correction_mask_on_demand, 1,
                    "incorrect value for correction_mask_on_demand, expected 1, is {}",
                    msg.correction_mask_on_demand
                );
                assert_eq!(
                    msg.correction_mask_stream, 1,
                    "incorrect value for correction_mask_stream, expected 1, is {}",
                    msg.correction_mask_stream
                );
                assert_eq!(
                    msg.request_id, 30,
                    "incorrect value for request_id, expected 30, is {}",
                    msg.request_id
                );
                assert_eq!(
                    msg.response_code, 0,
                    "incorrect value for response_code, expected 0, is {}",
                    msg.response_code
                );
                assert_eq!(
                    msg.solution_id, 2,
                    "incorrect value for solution_id, expected 2, is {}",
                    msg.solution_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcknowledge"),
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
fn test_json2sbp_auto_check_sbp_integrity_msg_acknowledge() {
    {
        let json_input = r#"{"preamble": 85, "msg_type": 3026, "sender": 42, "length": 11, "payload": "HkDiAQAAAQABAAI=", "crc": 45654, "request_id": 30, "area_id": 123456, "response_code": 0, "correction_mask_on_demand": 1, "correction_mask_stream": 1, "solution_id": 2}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcknowledge(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xBD2,
                    "Incorrect message type, expected 0xBD2, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2A,
                    "incorrect sender id, expected 0x2A, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.area_id, 123456,
                    "incorrect value for area_id, expected 123456, is {}",
                    msg.area_id
                );
                assert_eq!(
                    msg.correction_mask_on_demand, 1,
                    "incorrect value for correction_mask_on_demand, expected 1, is {}",
                    msg.correction_mask_on_demand
                );
                assert_eq!(
                    msg.correction_mask_stream, 1,
                    "incorrect value for correction_mask_stream, expected 1, is {}",
                    msg.correction_mask_stream
                );
                assert_eq!(
                    msg.request_id, 30,
                    "incorrect value for request_id, expected 30, is {}",
                    msg.request_id
                );
                assert_eq!(
                    msg.response_code, 0,
                    "incorrect value for response_code, expected 0, is {}",
                    msg.response_code
                );
                assert_eq!(
                    msg.solution_id, 2,
                    "incorrect value for solution_id, expected 2, is {}",
                    msg.solution_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcknowledge"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_integrity_msg_acknowledge`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_integrity_msg_acknowledge() {
    {
        let mut payload = Cursor::new(vec![
            85, 210, 11, 42, 0, 11, 30, 64, 226, 1, 0, 0, 1, 0, 1, 0, 2, 86, 178,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcknowledge(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcknowledge(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xBD2,
                    "Incorrect message type, expected 0xBD2, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2A,
                    "incorrect sender id, expected 0x2A, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.area_id, 123456,
                    "incorrect value for area_id, expected 123456, is {}",
                    msg.area_id
                );
                assert_eq!(
                    msg.correction_mask_on_demand, 1,
                    "incorrect value for correction_mask_on_demand, expected 1, is {}",
                    msg.correction_mask_on_demand
                );
                assert_eq!(
                    msg.correction_mask_stream, 1,
                    "incorrect value for correction_mask_stream, expected 1, is {}",
                    msg.correction_mask_stream
                );
                assert_eq!(
                    msg.request_id, 30,
                    "incorrect value for request_id, expected 30, is {}",
                    msg.request_id
                );
                assert_eq!(
                    msg.response_code, 0,
                    "incorrect value for response_code, expected 0, is {}",
                    msg.response_code
                );
                assert_eq!(
                    msg.solution_id, 2,
                    "incorrect value for solution_id, expected 2, is {}",
                    msg.solution_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcknowledge"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
