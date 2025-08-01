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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineHeadingDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_baseline_heading_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 7, 2, 124, 206, 10, 82, 109, 88, 176, 68, 14, 82, 203, 186, 58, 173, 182,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineHeadingDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x207,
                    "Incorrect message type, expected 0x207, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xce7c,
                    "incorrect sender id, expected 0xce7c, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 58,
                    "incorrect value for flags, expected 58, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.heading, 3411152452,
                    "incorrect value for heading, expected 3411152452, is {}",
                    msg.heading
                );
                assert_eq!(
                    msg.n_sats, 186,
                    "incorrect value for n_sats, expected 186, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2958585170,
                    "incorrect value for tow, expected 2958585170, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineHeadingDepA"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_baseline_heading_dep_a() {
    {
        let json_input = r#"{"crc":46765,"length":10,"msg_type":519,"payload":"Um1YsEQOUsu6Og==","preamble":85,"sender":52860,"tow":2958585170,"heading":3411152452,"n_sats":186,"flags":58}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineHeadingDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x207,
                    "Incorrect message type, expected 0x207, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xce7c,
                    "incorrect sender id, expected 0xce7c, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 58,
                    "incorrect value for flags, expected 58, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.heading, 3411152452,
                    "incorrect value for heading, expected 3411152452, is {}",
                    msg.heading
                );
                assert_eq!(
                    msg.n_sats, 186,
                    "incorrect value for n_sats, expected 186, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2958585170,
                    "incorrect value for tow, expected 2958585170, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineHeadingDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_baseline_heading_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_baseline_heading_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 7, 2, 124, 206, 10, 82, 109, 88, 176, 68, 14, 82, 203, 186, 58, 173, 182,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineHeadingDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineHeadingDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x207,
                    "Incorrect message type, expected 0x207, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xce7c,
                    "incorrect sender id, expected 0xce7c, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 58,
                    "incorrect value for flags, expected 58, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.heading, 3411152452,
                    "incorrect value for heading, expected 3411152452, is {}",
                    msg.heading
                );
                assert_eq!(
                    msg.n_sats, 186,
                    "incorrect value for n_sats, expected 186, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2958585170,
                    "incorrect value for tow, expected 2958585170, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineHeadingDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
