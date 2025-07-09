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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgBaselineHeading.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_orientation_msg_baseline_heading() {
    {
        let mut payload = Cursor::new(vec![
            85, 15, 2, 211, 93, 10, 156, 45, 13, 196, 44, 84, 197, 61, 91, 91, 224, 254,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineHeading(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x20f,
                    "Incorrect message type, expected 0x20f, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5dd3,
                    "incorrect sender id, expected 0x5dd3, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 91,
                    "incorrect value for flags, expected 91, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.heading, 1036342316,
                    "incorrect value for heading, expected 1036342316, is {}",
                    msg.heading
                );
                assert_eq!(
                    msg.n_sats, 91,
                    "incorrect value for n_sats, expected 91, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 3289197980,
                    "incorrect value for tow, expected 3289197980, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineHeading"),
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
fn test_json2sbp_auto_check_sbp_orientation_msg_baseline_heading() {
    {
        let json_input = r#"{"crc":65248,"length":10,"msg_type":527,"payload":"nC0NxCxUxT1bWw==","preamble":85,"sender":24019,"tow":3289197980,"heading":1036342316,"n_sats":91,"flags":91}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineHeading(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x20f,
                    "Incorrect message type, expected 0x20f, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5dd3,
                    "incorrect sender id, expected 0x5dd3, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 91,
                    "incorrect value for flags, expected 91, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.heading, 1036342316,
                    "incorrect value for heading, expected 1036342316, is {}",
                    msg.heading
                );
                assert_eq!(
                    msg.n_sats, 91,
                    "incorrect value for n_sats, expected 91, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 3289197980,
                    "incorrect value for tow, expected 3289197980, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineHeading"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_orientation_msg_baseline_heading`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_orientation_msg_baseline_heading() {
    {
        let mut payload = Cursor::new(vec![
            85, 15, 2, 211, 93, 10, 156, 45, 13, 196, 44, 84, 197, 61, 91, 91, 224, 254,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineHeading(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineHeading(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x20f,
                    "Incorrect message type, expected 0x20f, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5dd3,
                    "incorrect sender id, expected 0x5dd3, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 91,
                    "incorrect value for flags, expected 91, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.heading, 1036342316,
                    "incorrect value for heading, expected 1036342316, is {}",
                    msg.heading
                );
                assert_eq!(
                    msg.n_sats, 91,
                    "incorrect value for n_sats, expected 91, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 3289197980,
                    "incorrect value for tow, expected 3289197980, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineHeading"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
