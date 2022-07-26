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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGloBiases.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_glo_biases() {
    {
        let mut payload = Cursor::new(vec![
            85, 117, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77, 211,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGloBiases(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x75,
                    "Incorrect message type, expected 0x75, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0,
                    "incorrect sender id, expected 0, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l1ca_bias, 0,
                    "incorrect value for l1ca_bias, expected 0, is {}",
                    msg.l1ca_bias
                );
                assert_eq!(
                    msg.l1p_bias, 0,
                    "incorrect value for l1p_bias, expected 0, is {}",
                    msg.l1p_bias
                );
                assert_eq!(
                    msg.l2ca_bias, 0,
                    "incorrect value for l2ca_bias, expected 0, is {}",
                    msg.l2ca_bias
                );
                assert_eq!(
                    msg.l2p_bias, 0,
                    "incorrect value for l2p_bias, expected 0, is {}",
                    msg.l2p_bias
                );
                assert_eq!(
                    msg.mask, 0,
                    "incorrect value for mask, expected 0, is {}",
                    msg.mask
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGloBiases"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_glo_biases() {
    {
        let json_input = r#"{"mask":0,"l1ca_bias":0,"l1p_bias":0,"l2ca_bias":0,"l2p_bias":0,"preamble":85,"msg_type":117,"sender":0,"payload":"AAAAAAAAAAAA","crc":54093,"length":9}"#.as_bytes();

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
            sbp::messages::Sbp::MsgGloBiases(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x75,
                    "Incorrect message type, expected 0x75, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0,
                    "incorrect sender id, expected 0, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l1ca_bias, 0,
                    "incorrect value for l1ca_bias, expected 0, is {}",
                    msg.l1ca_bias
                );
                assert_eq!(
                    msg.l1p_bias, 0,
                    "incorrect value for l1p_bias, expected 0, is {}",
                    msg.l1p_bias
                );
                assert_eq!(
                    msg.l2ca_bias, 0,
                    "incorrect value for l2ca_bias, expected 0, is {}",
                    msg.l2ca_bias
                );
                assert_eq!(
                    msg.l2p_bias, 0,
                    "incorrect value for l2p_bias, expected 0, is {}",
                    msg.l2p_bias
                );
                assert_eq!(
                    msg.mask, 0,
                    "incorrect value for mask, expected 0, is {}",
                    msg.mask
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGloBiases"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_glo_biases`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_glo_biases() {
    {
        let mut payload = Cursor::new(vec![
            85, 117, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77, 211,
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
        let sbp_msg = sbp::messages::Sbp::MsgGloBiases(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgGloBiases(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x75,
                    "Incorrect message type, expected 0x75, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0,
                    "incorrect sender id, expected 0, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l1ca_bias, 0,
                    "incorrect value for l1ca_bias, expected 0, is {}",
                    msg.l1ca_bias
                );
                assert_eq!(
                    msg.l1p_bias, 0,
                    "incorrect value for l1p_bias, expected 0, is {}",
                    msg.l1p_bias
                );
                assert_eq!(
                    msg.l2ca_bias, 0,
                    "incorrect value for l2ca_bias, expected 0, is {}",
                    msg.l2ca_bias
                );
                assert_eq!(
                    msg.l2p_bias, 0,
                    "incorrect value for l2p_bias, expected 0, is {}",
                    msg.l2p_bias
                );
                assert_eq!(
                    msg.mask, 0,
                    "incorrect value for mask, expected 0, is {}",
                    msg.mask
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGloBiases"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
