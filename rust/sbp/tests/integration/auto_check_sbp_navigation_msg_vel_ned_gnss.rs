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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNedGnss.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_vel_ned_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 46, 2, 0, 16, 22, 168, 230, 233, 29, 251, 255, 255, 255, 0, 0, 0, 0, 246, 255, 255,
            255, 40, 0, 89, 0, 21, 2, 99, 171,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x22e,
                    "Incorrect message type, expected 0x22e, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -10,
                    "incorrect value for d, expected -10, is {}",
                    msg.d
                );
                assert_eq!(msg.e, 0, "incorrect value for e, expected 0, is {}", msg.e);
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 40,
                    "incorrect value for h_accuracy, expected 40, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -5,
                    "incorrect value for n, expected -5, is {}",
                    msg.n
                );
                assert_eq!(
                    msg.n_sats, 21,
                    "incorrect value for n_sats, expected 21, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501868200,
                    "incorrect value for tow, expected 501868200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 89,
                    "incorrect value for v_accuracy, expected 89, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDGnss"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_vel_ned_gnss() {
    {
        let json_input = r#"{"tow":501868200,"n":-5,"e":0,"d":-10,"h_accuracy":40,"v_accuracy":89,"n_sats":21,"flags":2,"preamble":85,"msg_type":558,"sender":4096,"payload":"qObpHfv///8AAAAA9v///ygAWQAVAg==","crc":43875,"length":22}"#.as_bytes();

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
            sbp::messages::Sbp::MsgVelNedGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x22e,
                    "Incorrect message type, expected 0x22e, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -10,
                    "incorrect value for d, expected -10, is {}",
                    msg.d
                );
                assert_eq!(msg.e, 0, "incorrect value for e, expected 0, is {}", msg.e);
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 40,
                    "incorrect value for h_accuracy, expected 40, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -5,
                    "incorrect value for n, expected -5, is {}",
                    msg.n
                );
                assert_eq!(
                    msg.n_sats, 21,
                    "incorrect value for n_sats, expected 21, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501868200,
                    "incorrect value for tow, expected 501868200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 89,
                    "incorrect value for v_accuracy, expected 89, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDGnss"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_vel_ned_gnss`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_vel_ned_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 46, 2, 0, 16, 22, 168, 230, 233, 29, 251, 255, 255, 255, 0, 0, 0, 0, 246, 255, 255,
            255, 40, 0, 89, 0, 21, 2, 99, 171,
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
        let sbp_msg = sbp::messages::Sbp::MsgVelNedGnss(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x22e,
                    "Incorrect message type, expected 0x22e, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -10,
                    "incorrect value for d, expected -10, is {}",
                    msg.d
                );
                assert_eq!(msg.e, 0, "incorrect value for e, expected 0, is {}", msg.e);
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 40,
                    "incorrect value for h_accuracy, expected 40, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -5,
                    "incorrect value for n, expected -5, is {}",
                    msg.n
                );
                assert_eq!(
                    msg.n_sats, 21,
                    "incorrect value for n_sats, expected 21, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501868200,
                    "incorrect value for tow, expected 501868200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 89,
                    "incorrect value for v_accuracy, expected 89, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDGnss"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
