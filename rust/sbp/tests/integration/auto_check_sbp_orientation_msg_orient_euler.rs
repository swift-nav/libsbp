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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientEuler.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_orientation_msg_orient_euler() {
    {
        let mut payload = Cursor::new(vec![
            85, 33, 2, 66, 0, 29, 1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 8, 0, 0, 0, 0, 0, 224, 64, 0,
            0, 64, 64, 0, 0, 224, 64, 3, 44, 226,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgOrientEuler(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x221,
                    "Incorrect message type, expected 0x221, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 3,
                    "incorrect value for flags, expected 3, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.pitch, 2,
                    "incorrect value for pitch, expected 2, is {}",
                    msg.pitch
                );
                assert!(
                    msg.pitch_accuracy.almost_eq(3.00000000000000000e+00),
                    "incorrect value for pitch_accuracy, expected 3.00000000000000000e+00, is {:e}",
                    msg.pitch_accuracy
                );
                assert_eq!(
                    msg.roll, 1,
                    "incorrect value for roll, expected 1, is {}",
                    msg.roll
                );
                assert!(
                    msg.roll_accuracy.almost_eq(7.00000000000000000e+00),
                    "incorrect value for roll_accuracy, expected 7.00000000000000000e+00, is {:e}",
                    msg.roll_accuracy
                );
                assert_eq!(
                    msg.tow, 1,
                    "incorrect value for tow, expected 1, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.yaw, 8,
                    "incorrect value for yaw, expected 8, is {}",
                    msg.yaw
                );
                assert!(
                    msg.yaw_accuracy.almost_eq(7.00000000000000000e+00),
                    "incorrect value for yaw_accuracy, expected 7.00000000000000000e+00, is {:e}",
                    msg.yaw_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgOrientEuler"),
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
fn test_json2sbp_auto_check_sbp_orientation_msg_orient_euler() {
    {
        let json_input = r#"{"pitch": 2, "sender": 66, "msg_type": 545, "roll": 1, "yaw": 8, "tow": 1, "roll_accuracy": 7, "crc": 57900, "length": 29, "flags": 3, "pitch_accuracy": 3, "yaw_accuracy": 7, "preamble": 85, "payload": "AQAAAAEAAAACAAAACAAAAAAA4EAAAEBAAADgQAM="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgOrientEuler(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x221,
                    "Incorrect message type, expected 0x221, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 3,
                    "incorrect value for flags, expected 3, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.pitch, 2,
                    "incorrect value for pitch, expected 2, is {}",
                    msg.pitch
                );
                assert!(
                    msg.pitch_accuracy.almost_eq(3.00000000000000000e+00),
                    "incorrect value for pitch_accuracy, expected 3.00000000000000000e+00, is {:e}",
                    msg.pitch_accuracy
                );
                assert_eq!(
                    msg.roll, 1,
                    "incorrect value for roll, expected 1, is {}",
                    msg.roll
                );
                assert!(
                    msg.roll_accuracy.almost_eq(7.00000000000000000e+00),
                    "incorrect value for roll_accuracy, expected 7.00000000000000000e+00, is {:e}",
                    msg.roll_accuracy
                );
                assert_eq!(
                    msg.tow, 1,
                    "incorrect value for tow, expected 1, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.yaw, 8,
                    "incorrect value for yaw, expected 8, is {}",
                    msg.yaw
                );
                assert!(
                    msg.yaw_accuracy.almost_eq(7.00000000000000000e+00),
                    "incorrect value for yaw_accuracy, expected 7.00000000000000000e+00, is {:e}",
                    msg.yaw_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgOrientEuler"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_orientation_msg_orient_euler`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_orientation_msg_orient_euler() {
    {
        let mut payload = Cursor::new(vec![
            85, 33, 2, 66, 0, 29, 1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 8, 0, 0, 0, 0, 0, 224, 64, 0,
            0, 64, 64, 0, 0, 224, 64, 3, 44, 226,
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
        let sbp_msg = sbp::messages::Sbp::MsgOrientEuler(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgOrientEuler(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x221,
                    "Incorrect message type, expected 0x221, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 3,
                    "incorrect value for flags, expected 3, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.pitch, 2,
                    "incorrect value for pitch, expected 2, is {}",
                    msg.pitch
                );
                assert!(
                    msg.pitch_accuracy.almost_eq(3.00000000000000000e+00),
                    "incorrect value for pitch_accuracy, expected 3.00000000000000000e+00, is {:e}",
                    msg.pitch_accuracy
                );
                assert_eq!(
                    msg.roll, 1,
                    "incorrect value for roll, expected 1, is {}",
                    msg.roll
                );
                assert!(
                    msg.roll_accuracy.almost_eq(7.00000000000000000e+00),
                    "incorrect value for roll_accuracy, expected 7.00000000000000000e+00, is {:e}",
                    msg.roll_accuracy
                );
                assert_eq!(
                    msg.tow, 1,
                    "incorrect value for tow, expected 1, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.yaw, 8,
                    "incorrect value for yaw, expected 8, is {}",
                    msg.yaw
                );
                assert!(
                    msg.yaw_accuracy.almost_eq(7.00000000000000000e+00),
                    "incorrect value for yaw_accuracy, expected 7.00000000000000000e+00, is {:e}",
                    msg.yaw_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgOrientEuler"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
