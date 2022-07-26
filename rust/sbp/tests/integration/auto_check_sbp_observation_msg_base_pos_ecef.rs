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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgBasePosEcef.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_base_pos_ecef() {
    {
        let mut payload = Cursor::new(vec![
            85, 72, 0, 0, 0, 24, 228, 131, 158, 245, 87, 205, 68, 193, 66, 62, 232, 209, 32, 118,
            80, 193, 213, 231, 106, 251, 63, 20, 77, 65, 194, 125,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBasePosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x48,
                    "Incorrect message type, expected 0x48, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0,
                    "incorrect sender id, expected 0, is {}",
                    sender_id
                );
                assert!(
                    msg.x.almost_eq(-2.72657591889999993e+06),
                    "incorrect value for x, expected -2.72657591889999993e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31526727979999967e+06),
                    "incorrect value for y, expected -4.31526727979999967e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.81145596419999981e+06),
                    "incorrect value for z, expected 3.81145596419999981e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBasePosECEF"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_base_pos_ecef() {
    {
        let json_input = r#"{"x":-2726575.9189,"y":-4315267.2798,"z":3811455.9642,"preamble":85,"msg_type":72,"sender":0,"payload":"5IOe9VfNRMFCPujRIHZQwdXnavs/FE1B","crc":32194,"length":24}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBasePosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x48,
                    "Incorrect message type, expected 0x48, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0,
                    "incorrect sender id, expected 0, is {}",
                    sender_id
                );
                assert!(
                    msg.x.almost_eq(-2.72657591889999993e+06),
                    "incorrect value for x, expected -2.72657591889999993e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31526727979999967e+06),
                    "incorrect value for y, expected -4.31526727979999967e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.81145596419999981e+06),
                    "incorrect value for z, expected 3.81145596419999981e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBasePosECEF"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_base_pos_ecef`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_base_pos_ecef() {
    {
        let mut payload = Cursor::new(vec![
            85, 72, 0, 0, 0, 24, 228, 131, 158, 245, 87, 205, 68, 193, 66, 62, 232, 209, 32, 118,
            80, 193, 213, 231, 106, 251, 63, 20, 77, 65, 194, 125,
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
        let sbp_msg = sbp::messages::Sbp::MsgBasePosEcef(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBasePosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x48,
                    "Incorrect message type, expected 0x48, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0,
                    "incorrect sender id, expected 0, is {}",
                    sender_id
                );
                assert!(
                    msg.x.almost_eq(-2.72657591889999993e+06),
                    "incorrect value for x, expected -2.72657591889999993e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31526727979999967e+06),
                    "incorrect value for y, expected -4.31526727979999967e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.81145596419999981e+06),
                    "incorrect value for z, expected 3.81145596419999981e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBasePosECEF"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
