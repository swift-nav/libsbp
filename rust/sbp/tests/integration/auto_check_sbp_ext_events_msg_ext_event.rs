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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ext_events/test_MsgExtEvent.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ext_events_msg_ext_event() {
    {
        let mut payload = Cursor::new(vec![
            85, 1, 1, 245, 6, 12, 48, 7, 199, 216, 49, 15, 202, 65, 15, 0, 3, 0, 62, 204,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgExtEvent(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x101,
                    "Incorrect message type, expected 0x101, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6f5,
                    "incorrect sender id, expected 0x6f5, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 3,
                    "incorrect value for flags, expected 3, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 999882,
                    "incorrect value for ns_residual, expected 999882, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.pin, 0,
                    "incorrect value for pin, expected 0, is {}",
                    msg.pin
                );
                assert_eq!(
                    msg.tow, 254924999,
                    "incorrect value for tow, expected 254924999, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1840,
                    "incorrect value for wn, expected 1840, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgExtEvent"),
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
fn test_json2sbp_auto_check_sbp_ext_events_msg_ext_event() {
    {
        let json_input = r#"{"sender": 1781, "msg_type": 257, "wn": 1840, "tow": 254924999, "crc": 52286, "length": 12, "flags": 3, "pin": 0, "ns_residual": 999882, "preamble": 85, "payload": "MAfH2DEPykEPAAMA"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgExtEvent(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x101,
                    "Incorrect message type, expected 0x101, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6f5,
                    "incorrect sender id, expected 0x6f5, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 3,
                    "incorrect value for flags, expected 3, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 999882,
                    "incorrect value for ns_residual, expected 999882, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.pin, 0,
                    "incorrect value for pin, expected 0, is {}",
                    msg.pin
                );
                assert_eq!(
                    msg.tow, 254924999,
                    "incorrect value for tow, expected 254924999, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1840,
                    "incorrect value for wn, expected 1840, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgExtEvent"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ext_events_msg_ext_event`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ext_events_msg_ext_event() {
    {
        let mut payload = Cursor::new(vec![
            85, 1, 1, 245, 6, 12, 48, 7, 199, 216, 49, 15, 202, 65, 15, 0, 3, 0, 62, 204,
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
        let sbp_msg = sbp::messages::Sbp::MsgExtEvent(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgExtEvent(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x101,
                    "Incorrect message type, expected 0x101, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6f5,
                    "incorrect sender id, expected 0x6f5, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 3,
                    "incorrect value for flags, expected 3, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 999882,
                    "incorrect value for ns_residual, expected 999882, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.pin, 0,
                    "incorrect value for pin, expected 0, is {}",
                    msg.pin
                );
                assert_eq!(
                    msg.tow, 254924999,
                    "incorrect value for tow, expected 254924999, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1840,
                    "incorrect value for wn, expected 1840, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgExtEvent"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
