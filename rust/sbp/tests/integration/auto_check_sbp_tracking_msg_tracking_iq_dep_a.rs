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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIqDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_tracking_msg_tracking_iq_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 28, 0, 184, 67, 29, 139, 28, 250, 15, 0, 99, 90, 170, 96, 71, 121, 33, 161, 52,
            211, 162, 101, 41, 36, 226, 99, 71, 75, 14, 240, 134, 82, 175, 83, 17, 34,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingIqDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x1c,
                    "Incorrect message type, expected 0x1c, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x43b8,
                    "incorrect sender id, expected 0x43b8, is {sender_id}"
                );
                assert_eq!(
                    msg.channel, 139,
                    "incorrect value for channel, expected 139, is {}",
                    msg.channel
                );
                assert_eq!(
                    msg.corrs[0].i, 1621776995,
                    "incorrect value for corrs[0].i, expected 1621776995, is {}",
                    msg.corrs[0].i
                );
                assert_eq!(
                    msg.corrs[0].q, -1591641785,
                    "incorrect value for corrs[0].q, expected -1591641785, is {}",
                    msg.corrs[0].q
                );
                assert_eq!(
                    msg.corrs[1].i, 1705169716,
                    "incorrect value for corrs[1].i, expected 1705169716, is {}",
                    msg.corrs[1].i
                );
                assert_eq!(
                    msg.corrs[1].q, 1675764777,
                    "incorrect value for corrs[1].q, expected 1675764777, is {}",
                    msg.corrs[1].q
                );
                assert_eq!(
                    msg.corrs[2].i, -267498681,
                    "incorrect value for corrs[2].i, expected -267498681, is {}",
                    msg.corrs[2].i
                );
                assert_eq!(
                    msg.corrs[2].q, 1403998854,
                    "incorrect value for corrs[2].q, expected 1403998854, is {}",
                    msg.corrs[2].q
                );
                assert_eq!(
                    msg.sid.code, 15,
                    "incorrect value for sid.code, expected 15, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 64028,
                    "incorrect value for sid.sat, expected 64028, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingIqDepA"),
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
fn test_json2sbp_auto_check_sbp_tracking_msg_tracking_iq_dep_a() {
    {
        let json_input = r#"{"crc":8721,"length":29,"msg_type":28,"payload":"ixz6DwBjWqpgR3khoTTTomUpJOJjR0sO8IZSr1M=","preamble":85,"sender":17336,"channel":139,"sid":{"sat":64028,"code":15,"reserved":0},"corrs":[{"I":1621776995,"Q":-1591641785},{"I":1705169716,"Q":1675764777},{"I":-267498681,"Q":1403998854}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingIqDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x1c,
                    "Incorrect message type, expected 0x1c, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x43b8,
                    "incorrect sender id, expected 0x43b8, is {sender_id}"
                );
                assert_eq!(
                    msg.channel, 139,
                    "incorrect value for channel, expected 139, is {}",
                    msg.channel
                );
                assert_eq!(
                    msg.corrs[0].i, 1621776995,
                    "incorrect value for corrs[0].i, expected 1621776995, is {}",
                    msg.corrs[0].i
                );
                assert_eq!(
                    msg.corrs[0].q, -1591641785,
                    "incorrect value for corrs[0].q, expected -1591641785, is {}",
                    msg.corrs[0].q
                );
                assert_eq!(
                    msg.corrs[1].i, 1705169716,
                    "incorrect value for corrs[1].i, expected 1705169716, is {}",
                    msg.corrs[1].i
                );
                assert_eq!(
                    msg.corrs[1].q, 1675764777,
                    "incorrect value for corrs[1].q, expected 1675764777, is {}",
                    msg.corrs[1].q
                );
                assert_eq!(
                    msg.corrs[2].i, -267498681,
                    "incorrect value for corrs[2].i, expected -267498681, is {}",
                    msg.corrs[2].i
                );
                assert_eq!(
                    msg.corrs[2].q, 1403998854,
                    "incorrect value for corrs[2].q, expected 1403998854, is {}",
                    msg.corrs[2].q
                );
                assert_eq!(
                    msg.sid.code, 15,
                    "incorrect value for sid.code, expected 15, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 64028,
                    "incorrect value for sid.sat, expected 64028, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingIqDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_tracking_msg_tracking_iq_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_tracking_msg_tracking_iq_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 28, 0, 184, 67, 29, 139, 28, 250, 15, 0, 99, 90, 170, 96, 71, 121, 33, 161, 52,
            211, 162, 101, 41, 36, 226, 99, 71, 75, 14, 240, 134, 82, 175, 83, 17, 34,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingIqDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingIqDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x1c,
                    "Incorrect message type, expected 0x1c, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x43b8,
                    "incorrect sender id, expected 0x43b8, is {sender_id}"
                );
                assert_eq!(
                    msg.channel, 139,
                    "incorrect value for channel, expected 139, is {}",
                    msg.channel
                );
                assert_eq!(
                    msg.corrs[0].i, 1621776995,
                    "incorrect value for corrs[0].i, expected 1621776995, is {}",
                    msg.corrs[0].i
                );
                assert_eq!(
                    msg.corrs[0].q, -1591641785,
                    "incorrect value for corrs[0].q, expected -1591641785, is {}",
                    msg.corrs[0].q
                );
                assert_eq!(
                    msg.corrs[1].i, 1705169716,
                    "incorrect value for corrs[1].i, expected 1705169716, is {}",
                    msg.corrs[1].i
                );
                assert_eq!(
                    msg.corrs[1].q, 1675764777,
                    "incorrect value for corrs[1].q, expected 1675764777, is {}",
                    msg.corrs[1].q
                );
                assert_eq!(
                    msg.corrs[2].i, -267498681,
                    "incorrect value for corrs[2].i, expected -267498681, is {}",
                    msg.corrs[2].i
                );
                assert_eq!(
                    msg.corrs[2].q, 1403998854,
                    "incorrect value for corrs[2].q, expected 1403998854, is {}",
                    msg.corrs[2].q
                );
                assert_eq!(
                    msg.sid.code, 15,
                    "incorrect value for sid.code, expected 15, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 64028,
                    "incorrect value for sid.sat, expected 64028, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingIqDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
