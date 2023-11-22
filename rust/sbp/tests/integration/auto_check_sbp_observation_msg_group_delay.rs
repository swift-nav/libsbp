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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGroupDelay.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_group_delay() {
    {
        let mut payload = Cursor::new(vec![
            85, 148, 0, 123, 0, 15, 176, 207, 6, 0, 106, 8, 22, 0, 1, 254, 253, 165, 255, 237, 23,
            2, 201,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGroupDelay(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x94,
                    "Incorrect message type, expected 0x94, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert_eq!(
                    msg.isc_l1ca, -91,
                    "incorrect value for isc_l1ca, expected -91, is {}",
                    msg.isc_l1ca
                );
                assert_eq!(
                    msg.isc_l2c, 6125,
                    "incorrect value for isc_l2c, expected 6125, is {}",
                    msg.isc_l2c
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 22,
                    "incorrect value for sid.sat, expected 22, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.t_op.tow, 446384,
                    "incorrect value for t_op.tow, expected 446384, is {}",
                    msg.t_op.tow
                );
                assert_eq!(
                    msg.t_op.wn, 2154,
                    "incorrect value for t_op.wn, expected 2154, is {}",
                    msg.t_op.wn
                );
                assert_eq!(
                    msg.tgd, -514,
                    "incorrect value for tgd, expected -514, is {}",
                    msg.tgd
                );
                assert_eq!(
                    msg.valid, 1,
                    "incorrect value for valid, expected 1, is {}",
                    msg.valid
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGroupDelay"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_group_delay() {
    {
        let json_input = r#"{"crc":51458,"length":15,"msg_type":148,"payload":"sM8GAGoIFgAB/v2l/+0X","preamble":85,"sender":123,"t_op":{"tow":446384,"wn":2154},"sid":{"sat":22,"code":0},"valid":1,"tgd":-514,"isc_l1ca":-91,"isc_l2c":6125}"#.as_bytes();

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
            sbp::messages::Sbp::MsgGroupDelay(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x94,
                    "Incorrect message type, expected 0x94, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert_eq!(
                    msg.isc_l1ca, -91,
                    "incorrect value for isc_l1ca, expected -91, is {}",
                    msg.isc_l1ca
                );
                assert_eq!(
                    msg.isc_l2c, 6125,
                    "incorrect value for isc_l2c, expected 6125, is {}",
                    msg.isc_l2c
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 22,
                    "incorrect value for sid.sat, expected 22, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.t_op.tow, 446384,
                    "incorrect value for t_op.tow, expected 446384, is {}",
                    msg.t_op.tow
                );
                assert_eq!(
                    msg.t_op.wn, 2154,
                    "incorrect value for t_op.wn, expected 2154, is {}",
                    msg.t_op.wn
                );
                assert_eq!(
                    msg.tgd, -514,
                    "incorrect value for tgd, expected -514, is {}",
                    msg.tgd
                );
                assert_eq!(
                    msg.valid, 1,
                    "incorrect value for valid, expected 1, is {}",
                    msg.valid
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGroupDelay"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_group_delay`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_group_delay() {
    {
        let mut payload = Cursor::new(vec![
            85, 148, 0, 123, 0, 15, 176, 207, 6, 0, 106, 8, 22, 0, 1, 254, 253, 165, 255, 237, 23,
            2, 201,
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
        let sbp_msg = sbp::messages::Sbp::MsgGroupDelay(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgGroupDelay(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x94,
                    "Incorrect message type, expected 0x94, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert_eq!(
                    msg.isc_l1ca, -91,
                    "incorrect value for isc_l1ca, expected -91, is {}",
                    msg.isc_l1ca
                );
                assert_eq!(
                    msg.isc_l2c, 6125,
                    "incorrect value for isc_l2c, expected 6125, is {}",
                    msg.isc_l2c
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 22,
                    "incorrect value for sid.sat, expected 22, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.t_op.tow, 446384,
                    "incorrect value for t_op.tow, expected 446384, is {}",
                    msg.t_op.tow
                );
                assert_eq!(
                    msg.t_op.wn, 2154,
                    "incorrect value for t_op.wn, expected 2154, is {}",
                    msg.t_op.wn
                );
                assert_eq!(
                    msg.tgd, -514,
                    "incorrect value for tgd, expected -514, is {}",
                    msg.tgd
                );
                assert_eq!(
                    msg.valid, 1,
                    "incorrect value for valid, expected 1, is {}",
                    msg.valid
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGroupDelay"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
