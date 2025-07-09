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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIq.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_tracking_msg_tracking_iq() {
    {
        let mut payload = Cursor::new(vec![
            85, 45, 0, 2, 80, 15, 145, 121, 203, 47, 217, 239, 55, 45, 38, 189, 88, 159, 19, 208,
            12, 97, 167,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingIq(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2d,
                    "Incorrect message type, expected 0x2d, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5002,
                    "incorrect sender id, expected 0x5002, is {sender_id}"
                );
                assert_eq!(
                    msg.channel, 145,
                    "incorrect value for channel, expected 145, is {}",
                    msg.channel
                );
                assert_eq!(
                    msg.corrs[0].i, -9937,
                    "incorrect value for corrs[0].i, expected -9937, is {}",
                    msg.corrs[0].i
                );
                assert_eq!(
                    msg.corrs[0].q, 14319,
                    "incorrect value for corrs[0].q, expected 14319, is {}",
                    msg.corrs[0].q
                );
                assert_eq!(
                    msg.corrs[1].i, 9773,
                    "incorrect value for corrs[1].i, expected 9773, is {}",
                    msg.corrs[1].i
                );
                assert_eq!(
                    msg.corrs[1].q, 22717,
                    "incorrect value for corrs[1].q, expected 22717, is {}",
                    msg.corrs[1].q
                );
                assert_eq!(
                    msg.corrs[2].i, 5023,
                    "incorrect value for corrs[2].i, expected 5023, is {}",
                    msg.corrs[2].i
                );
                assert_eq!(
                    msg.corrs[2].q, 3280,
                    "incorrect value for corrs[2].q, expected 3280, is {}",
                    msg.corrs[2].q
                );
                assert_eq!(
                    msg.sid.code, 203,
                    "incorrect value for sid.code, expected 203, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 121,
                    "incorrect value for sid.sat, expected 121, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingIq"),
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
fn test_json2sbp_auto_check_sbp_tracking_msg_tracking_iq() {
    {
        let json_input = r#"{"crc":42849,"length":15,"msg_type":45,"payload":"kXnLL9nvNy0mvVifE9AM","preamble":85,"sender":20482,"channel":145,"sid":{"sat":121,"code":203},"corrs":[{"I":-9937,"Q":14319},{"I":9773,"Q":22717},{"I":5023,"Q":3280}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingIq(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2d,
                    "Incorrect message type, expected 0x2d, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5002,
                    "incorrect sender id, expected 0x5002, is {sender_id}"
                );
                assert_eq!(
                    msg.channel, 145,
                    "incorrect value for channel, expected 145, is {}",
                    msg.channel
                );
                assert_eq!(
                    msg.corrs[0].i, -9937,
                    "incorrect value for corrs[0].i, expected -9937, is {}",
                    msg.corrs[0].i
                );
                assert_eq!(
                    msg.corrs[0].q, 14319,
                    "incorrect value for corrs[0].q, expected 14319, is {}",
                    msg.corrs[0].q
                );
                assert_eq!(
                    msg.corrs[1].i, 9773,
                    "incorrect value for corrs[1].i, expected 9773, is {}",
                    msg.corrs[1].i
                );
                assert_eq!(
                    msg.corrs[1].q, 22717,
                    "incorrect value for corrs[1].q, expected 22717, is {}",
                    msg.corrs[1].q
                );
                assert_eq!(
                    msg.corrs[2].i, 5023,
                    "incorrect value for corrs[2].i, expected 5023, is {}",
                    msg.corrs[2].i
                );
                assert_eq!(
                    msg.corrs[2].q, 3280,
                    "incorrect value for corrs[2].q, expected 3280, is {}",
                    msg.corrs[2].q
                );
                assert_eq!(
                    msg.sid.code, 203,
                    "incorrect value for sid.code, expected 203, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 121,
                    "incorrect value for sid.sat, expected 121, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingIq"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_tracking_msg_tracking_iq`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_tracking_msg_tracking_iq() {
    {
        let mut payload = Cursor::new(vec![
            85, 45, 0, 2, 80, 15, 145, 121, 203, 47, 217, 239, 55, 45, 38, 189, 88, 159, 19, 208,
            12, 97, 167,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingIq(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingIq(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2d,
                    "Incorrect message type, expected 0x2d, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5002,
                    "incorrect sender id, expected 0x5002, is {sender_id}"
                );
                assert_eq!(
                    msg.channel, 145,
                    "incorrect value for channel, expected 145, is {}",
                    msg.channel
                );
                assert_eq!(
                    msg.corrs[0].i, -9937,
                    "incorrect value for corrs[0].i, expected -9937, is {}",
                    msg.corrs[0].i
                );
                assert_eq!(
                    msg.corrs[0].q, 14319,
                    "incorrect value for corrs[0].q, expected 14319, is {}",
                    msg.corrs[0].q
                );
                assert_eq!(
                    msg.corrs[1].i, 9773,
                    "incorrect value for corrs[1].i, expected 9773, is {}",
                    msg.corrs[1].i
                );
                assert_eq!(
                    msg.corrs[1].q, 22717,
                    "incorrect value for corrs[1].q, expected 22717, is {}",
                    msg.corrs[1].q
                );
                assert_eq!(
                    msg.corrs[2].i, 5023,
                    "incorrect value for corrs[2].i, expected 5023, is {}",
                    msg.corrs[2].i
                );
                assert_eq!(
                    msg.corrs[2].q, 3280,
                    "incorrect value for corrs[2].q, expected 3280, is {}",
                    msg.corrs[2].q
                );
                assert_eq!(
                    msg.sid.code, 203,
                    "incorrect value for sid.code, expected 203, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 121,
                    "incorrect value for sid.sat, expected 121, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingIq"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
