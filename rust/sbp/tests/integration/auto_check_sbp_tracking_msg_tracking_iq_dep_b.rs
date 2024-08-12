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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIqDepB.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_tracking_msg_tracking_iq_dep_b() {
    {
        let mut payload = Cursor::new(vec![
            85, 44, 0, 39, 101, 27, 45, 188, 183, 72, 185, 157, 15, 187, 249, 101, 24, 135, 146,
            180, 224, 123, 235, 142, 208, 102, 112, 25, 21, 177, 96, 116, 68, 246, 153,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingIqDepB(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2c,
                    "Incorrect message type, expected 0x2c, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6527,
                    "incorrect sender id, expected 0x6527, is {sender_id}"
                );
                assert_eq!(
                    msg.channel, 45,
                    "incorrect value for channel, expected 45, is {}",
                    msg.channel
                );
                assert_eq!(
                    msg.corrs[0].i, 261994824,
                    "incorrect value for corrs[0].i, expected 261994824, is {}",
                    msg.corrs[0].i
                );
                assert_eq!(
                    msg.corrs[0].q, 409336251,
                    "incorrect value for corrs[0].q, expected 409336251, is {}",
                    msg.corrs[0].q
                );
                assert_eq!(
                    msg.corrs[1].i, -525036921,
                    "incorrect value for corrs[1].i, expected -525036921, is {}",
                    msg.corrs[1].i
                );
                assert_eq!(
                    msg.corrs[1].q, -795939973,
                    "incorrect value for corrs[1].q, expected -795939973, is {}",
                    msg.corrs[1].q
                );
                assert_eq!(
                    msg.corrs[2].i, 353988710,
                    "incorrect value for corrs[2].i, expected 353988710, is {}",
                    msg.corrs[2].i
                );
                assert_eq!(
                    msg.corrs[2].q, 1148477617,
                    "incorrect value for corrs[2].q, expected 1148477617, is {}",
                    msg.corrs[2].q
                );
                assert_eq!(
                    msg.sid.code, 183,
                    "incorrect value for sid.code, expected 183, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 188,
                    "incorrect value for sid.sat, expected 188, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingIqDepB"),
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
fn test_json2sbp_auto_check_sbp_tracking_msg_tracking_iq_dep_b() {
    {
        let json_input = r#"{"crc":39414,"length":27,"msg_type":44,"payload":"Lby3SLmdD7v5ZRiHkrTge+uO0GZwGRWxYHRE","preamble":85,"sender":25895,"channel":45,"sid":{"sat":188,"code":183},"corrs":[{"I":261994824,"Q":409336251},{"I":-525036921,"Q":-795939973},{"I":353988710,"Q":1148477617}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingIqDepB(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2c,
                    "Incorrect message type, expected 0x2c, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6527,
                    "incorrect sender id, expected 0x6527, is {sender_id}"
                );
                assert_eq!(
                    msg.channel, 45,
                    "incorrect value for channel, expected 45, is {}",
                    msg.channel
                );
                assert_eq!(
                    msg.corrs[0].i, 261994824,
                    "incorrect value for corrs[0].i, expected 261994824, is {}",
                    msg.corrs[0].i
                );
                assert_eq!(
                    msg.corrs[0].q, 409336251,
                    "incorrect value for corrs[0].q, expected 409336251, is {}",
                    msg.corrs[0].q
                );
                assert_eq!(
                    msg.corrs[1].i, -525036921,
                    "incorrect value for corrs[1].i, expected -525036921, is {}",
                    msg.corrs[1].i
                );
                assert_eq!(
                    msg.corrs[1].q, -795939973,
                    "incorrect value for corrs[1].q, expected -795939973, is {}",
                    msg.corrs[1].q
                );
                assert_eq!(
                    msg.corrs[2].i, 353988710,
                    "incorrect value for corrs[2].i, expected 353988710, is {}",
                    msg.corrs[2].i
                );
                assert_eq!(
                    msg.corrs[2].q, 1148477617,
                    "incorrect value for corrs[2].q, expected 1148477617, is {}",
                    msg.corrs[2].q
                );
                assert_eq!(
                    msg.sid.code, 183,
                    "incorrect value for sid.code, expected 183, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 188,
                    "incorrect value for sid.sat, expected 188, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingIqDepB"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_tracking_msg_tracking_iq_dep_b`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_tracking_msg_tracking_iq_dep_b() {
    {
        let mut payload = Cursor::new(vec![
            85, 44, 0, 39, 101, 27, 45, 188, 183, 72, 185, 157, 15, 187, 249, 101, 24, 135, 146,
            180, 224, 123, 235, 142, 208, 102, 112, 25, 21, 177, 96, 116, 68, 246, 153,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingIqDepB(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingIqDepB(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2c,
                    "Incorrect message type, expected 0x2c, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6527,
                    "incorrect sender id, expected 0x6527, is {sender_id}"
                );
                assert_eq!(
                    msg.channel, 45,
                    "incorrect value for channel, expected 45, is {}",
                    msg.channel
                );
                assert_eq!(
                    msg.corrs[0].i, 261994824,
                    "incorrect value for corrs[0].i, expected 261994824, is {}",
                    msg.corrs[0].i
                );
                assert_eq!(
                    msg.corrs[0].q, 409336251,
                    "incorrect value for corrs[0].q, expected 409336251, is {}",
                    msg.corrs[0].q
                );
                assert_eq!(
                    msg.corrs[1].i, -525036921,
                    "incorrect value for corrs[1].i, expected -525036921, is {}",
                    msg.corrs[1].i
                );
                assert_eq!(
                    msg.corrs[1].q, -795939973,
                    "incorrect value for corrs[1].q, expected -795939973, is {}",
                    msg.corrs[1].q
                );
                assert_eq!(
                    msg.corrs[2].i, 353988710,
                    "incorrect value for corrs[2].i, expected 353988710, is {}",
                    msg.corrs[2].i
                );
                assert_eq!(
                    msg.corrs[2].q, 1148477617,
                    "incorrect value for corrs[2].q, expected 1148477617, is {}",
                    msg.corrs[2].q
                );
                assert_eq!(
                    msg.sid.code, 183,
                    "incorrect value for sid.code, expected 183, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 188,
                    "incorrect value for sid.sat, expected 188, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingIqDepB"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
