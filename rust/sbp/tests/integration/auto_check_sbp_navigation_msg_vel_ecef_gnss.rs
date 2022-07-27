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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelEcefGnss.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_vel_ecef_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 45, 2, 0, 16, 20, 224, 229, 233, 29, 253, 255, 255, 255, 1, 0, 0, 0, 4, 0, 0, 0,
            89, 0, 21, 2, 205, 16,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x22d,
                    "Incorrect message type, expected 0x22d, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 89,
                    "incorrect value for accuracy, expected 89, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 21,
                    "incorrect value for n_sats, expected 21, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501868000,
                    "incorrect value for tow, expected 501868000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -3,
                    "incorrect value for x, expected -3, is {}",
                    msg.x
                );
                assert_eq!(msg.y, 1, "incorrect value for y, expected 1, is {}", msg.y);
                assert_eq!(msg.z, 4, "incorrect value for z, expected 4, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFGnss"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_vel_ecef_gnss() {
    {
        let json_input = r#"{"tow":501868000,"x":-3,"y":1,"z":4,"accuracy":89,"n_sats":21,"flags":2,"preamble":85,"msg_type":557,"sender":4096,"payload":"4OXpHf3///8BAAAABAAAAFkAFQI=","crc":4301,"length":20}"#.as_bytes();

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
            sbp::messages::Sbp::MsgVelEcefGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x22d,
                    "Incorrect message type, expected 0x22d, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 89,
                    "incorrect value for accuracy, expected 89, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 21,
                    "incorrect value for n_sats, expected 21, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501868000,
                    "incorrect value for tow, expected 501868000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -3,
                    "incorrect value for x, expected -3, is {}",
                    msg.x
                );
                assert_eq!(msg.y, 1, "incorrect value for y, expected 1, is {}", msg.y);
                assert_eq!(msg.z, 4, "incorrect value for z, expected 4, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFGnss"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_vel_ecef_gnss`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_vel_ecef_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 45, 2, 0, 16, 20, 224, 229, 233, 29, 253, 255, 255, 255, 1, 0, 0, 0, 4, 0, 0, 0,
            89, 0, 21, 2, 205, 16,
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
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefGnss(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x22d,
                    "Incorrect message type, expected 0x22d, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 89,
                    "incorrect value for accuracy, expected 89, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 21,
                    "incorrect value for n_sats, expected 21, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501868000,
                    "incorrect value for tow, expected 501868000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -3,
                    "incorrect value for x, expected -3, is {}",
                    msg.x
                );
                assert_eq!(msg.y, 1, "incorrect value for y, expected 1, is {}", msg.y);
                assert_eq!(msg.z, 4, "incorrect value for z, expected 4, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFGnss"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
