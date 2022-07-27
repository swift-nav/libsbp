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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientQuat.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_orientation_msg_orient_quat() {
    {
        let mut payload = Cursor::new(vec![
            85, 32, 2, 66, 0, 37, 0, 0, 0, 0, 3, 0, 0, 0, 7, 0, 0, 0, 8, 0, 0, 0, 4, 0, 0, 0, 0, 0,
            64, 64, 0, 0, 128, 64, 0, 0, 0, 65, 0, 0, 64, 64, 1, 186, 6,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgOrientQuat(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x220,
                    "Incorrect message type, expected 0x220, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.tow, 0,
                    "incorrect value for tow, expected 0, is {}",
                    msg.tow
                );
                assert_eq!(msg.w, 3, "incorrect value for w, expected 3, is {}", msg.w);
                assert!(
                    msg.w_accuracy.almost_eq(3.00000000000000000e+00),
                    "incorrect value for w_accuracy, expected 3.00000000000000000e+00, is {:e}",
                    msg.w_accuracy
                );
                assert_eq!(msg.x, 7, "incorrect value for x, expected 7, is {}", msg.x);
                assert!(
                    msg.x_accuracy.almost_eq(4.00000000000000000e+00),
                    "incorrect value for x_accuracy, expected 4.00000000000000000e+00, is {:e}",
                    msg.x_accuracy
                );
                assert_eq!(msg.y, 8, "incorrect value for y, expected 8, is {}", msg.y);
                assert!(
                    msg.y_accuracy.almost_eq(8.00000000000000000e+00),
                    "incorrect value for y_accuracy, expected 8.00000000000000000e+00, is {:e}",
                    msg.y_accuracy
                );
                assert_eq!(msg.z, 4, "incorrect value for z, expected 4, is {}", msg.z);
                assert!(
                    msg.z_accuracy.almost_eq(3.00000000000000000e+00),
                    "incorrect value for z_accuracy, expected 3.00000000000000000e+00, is {:e}",
                    msg.z_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgOrientQuat"),
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
fn test_json2sbp_auto_check_sbp_orientation_msg_orient_quat() {
    {
        let json_input = r#"{"sender": 66, "msg_type": 544, "tow": 0, "z_accuracy": 3, "w_accuracy": 3, "crc": 1722, "length": 37, "flags": 1, "w": 3, "y": 8, "x": 7, "z": 4, "preamble": 85, "payload": "AAAAAAMAAAAHAAAACAAAAAQAAAAAAEBAAACAQAAAAEEAAEBAAQ==", "y_accuracy": 8, "x_accuracy": 4}"#.as_bytes();

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
            sbp::messages::Sbp::MsgOrientQuat(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x220,
                    "Incorrect message type, expected 0x220, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.tow, 0,
                    "incorrect value for tow, expected 0, is {}",
                    msg.tow
                );
                assert_eq!(msg.w, 3, "incorrect value for w, expected 3, is {}", msg.w);
                assert!(
                    msg.w_accuracy.almost_eq(3.00000000000000000e+00),
                    "incorrect value for w_accuracy, expected 3.00000000000000000e+00, is {:e}",
                    msg.w_accuracy
                );
                assert_eq!(msg.x, 7, "incorrect value for x, expected 7, is {}", msg.x);
                assert!(
                    msg.x_accuracy.almost_eq(4.00000000000000000e+00),
                    "incorrect value for x_accuracy, expected 4.00000000000000000e+00, is {:e}",
                    msg.x_accuracy
                );
                assert_eq!(msg.y, 8, "incorrect value for y, expected 8, is {}", msg.y);
                assert!(
                    msg.y_accuracy.almost_eq(8.00000000000000000e+00),
                    "incorrect value for y_accuracy, expected 8.00000000000000000e+00, is {:e}",
                    msg.y_accuracy
                );
                assert_eq!(msg.z, 4, "incorrect value for z, expected 4, is {}", msg.z);
                assert!(
                    msg.z_accuracy.almost_eq(3.00000000000000000e+00),
                    "incorrect value for z_accuracy, expected 3.00000000000000000e+00, is {:e}",
                    msg.z_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgOrientQuat"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_orientation_msg_orient_quat`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_orientation_msg_orient_quat() {
    {
        let mut payload = Cursor::new(vec![
            85, 32, 2, 66, 0, 37, 0, 0, 0, 0, 3, 0, 0, 0, 7, 0, 0, 0, 8, 0, 0, 0, 4, 0, 0, 0, 0, 0,
            64, 64, 0, 0, 128, 64, 0, 0, 0, 65, 0, 0, 64, 64, 1, 186, 6,
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
        let sbp_msg = sbp::messages::Sbp::MsgOrientQuat(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgOrientQuat(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x220,
                    "Incorrect message type, expected 0x220, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.tow, 0,
                    "incorrect value for tow, expected 0, is {}",
                    msg.tow
                );
                assert_eq!(msg.w, 3, "incorrect value for w, expected 3, is {}", msg.w);
                assert!(
                    msg.w_accuracy.almost_eq(3.00000000000000000e+00),
                    "incorrect value for w_accuracy, expected 3.00000000000000000e+00, is {:e}",
                    msg.w_accuracy
                );
                assert_eq!(msg.x, 7, "incorrect value for x, expected 7, is {}", msg.x);
                assert!(
                    msg.x_accuracy.almost_eq(4.00000000000000000e+00),
                    "incorrect value for x_accuracy, expected 4.00000000000000000e+00, is {:e}",
                    msg.x_accuracy
                );
                assert_eq!(msg.y, 8, "incorrect value for y, expected 8, is {}", msg.y);
                assert!(
                    msg.y_accuracy.almost_eq(8.00000000000000000e+00),
                    "incorrect value for y_accuracy, expected 8.00000000000000000e+00, is {:e}",
                    msg.y_accuracy
                );
                assert_eq!(msg.z, 4, "incorrect value for z, expected 4, is {}", msg.z);
                assert!(
                    msg.z_accuracy.almost_eq(3.00000000000000000e+00),
                    "incorrect value for z_accuracy, expected 3.00000000000000000e+00, is {:e}",
                    msg.z_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgOrientQuat"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
