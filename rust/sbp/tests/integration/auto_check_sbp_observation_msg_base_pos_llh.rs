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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgBasePosLLH.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_base_pos_llh() {
    {
        let mut payload = Cursor::new(vec![
            85, 68, 0, 123, 0, 24, 225, 237, 238, 90, 42, 160, 66, 64, 59, 143, 70, 235, 0, 120,
            94, 192, 51, 181, 124, 240, 65, 248, 66, 64, 82, 230,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBasePosLlh(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x44,
                    "Incorrect message type, expected 0x44, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert!(
                    msg.height.almost_eq(3.79395123108792163e+01),
                    "incorrect value for height, expected 3.79395123108792163e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72512925783773952e+01),
                    "incorrect value for lat, expected 3.72512925783773952e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875056094079739e+02),
                    "incorrect value for lon, expected -1.21875056094079739e+02, is {:e}",
                    msg.lon
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBasePosLLH"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_base_pos_llh() {
    {
        let json_input = r#"{"crc":58962,"length":24,"msg_type":68,"payload":"4e3uWiqgQkA7j0brAHhewDO1fPBB+EJA","preamble":85,"sender":123,"lat":37.251292578377395,"lon":-121.87505609407974,"height":37.939512310879216}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBasePosLlh(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x44,
                    "Incorrect message type, expected 0x44, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert!(
                    msg.height.almost_eq(3.79395123108792163e+01),
                    "incorrect value for height, expected 3.79395123108792163e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72512925783773952e+01),
                    "incorrect value for lat, expected 3.72512925783773952e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875056094079739e+02),
                    "incorrect value for lon, expected -1.21875056094079739e+02, is {:e}",
                    msg.lon
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBasePosLLH"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_base_pos_llh`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_base_pos_llh() {
    {
        let mut payload = Cursor::new(vec![
            85, 68, 0, 123, 0, 24, 225, 237, 238, 90, 42, 160, 66, 64, 59, 143, 70, 235, 0, 120,
            94, 192, 51, 181, 124, 240, 65, 248, 66, 64, 82, 230,
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
        let sbp_msg = sbp::messages::Sbp::MsgBasePosLlh(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBasePosLlh(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x44,
                    "Incorrect message type, expected 0x44, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert!(
                    msg.height.almost_eq(3.79395123108792163e+01),
                    "incorrect value for height, expected 3.79395123108792163e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72512925783773952e+01),
                    "incorrect value for lat, expected 3.72512925783773952e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875056094079739e+02),
                    "incorrect value for lon, expected -1.21875056094079739e+02, is {:e}",
                    msg.lon
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBasePosLLH"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
