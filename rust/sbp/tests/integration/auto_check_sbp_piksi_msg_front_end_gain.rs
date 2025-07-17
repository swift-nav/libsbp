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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgFrontEndGain.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_piksi_msg_front_end_gain() {
    {
        let mut payload = Cursor::new(vec![
            85, 191, 0, 175, 245, 16, 41, 133, 134, 10, 105, 20, 38, 38, 246, 233, 216, 80, 187,
            213, 85, 2, 235, 135,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgFrontEndGain(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xbf,
                    "Incorrect message type, expected 0xbf, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf5af,
                    "incorrect sender id, expected 0xf5af, is {sender_id}"
                );
                assert_eq!(
                    msg.if_gain[0], -10,
                    "incorrect value for if_gain[0], expected -10, is {}",
                    msg.if_gain[0]
                );
                assert_eq!(
                    msg.if_gain[1], -23,
                    "incorrect value for if_gain[1], expected -23, is {}",
                    msg.if_gain[1]
                );
                assert_eq!(
                    msg.if_gain[2], -40,
                    "incorrect value for if_gain[2], expected -40, is {}",
                    msg.if_gain[2]
                );
                assert_eq!(
                    msg.if_gain[3], 80,
                    "incorrect value for if_gain[3], expected 80, is {}",
                    msg.if_gain[3]
                );
                assert_eq!(
                    msg.if_gain[4], -69,
                    "incorrect value for if_gain[4], expected -69, is {}",
                    msg.if_gain[4]
                );
                assert_eq!(
                    msg.if_gain[5], -43,
                    "incorrect value for if_gain[5], expected -43, is {}",
                    msg.if_gain[5]
                );
                assert_eq!(
                    msg.if_gain[6], 85,
                    "incorrect value for if_gain[6], expected 85, is {}",
                    msg.if_gain[6]
                );
                assert_eq!(
                    msg.if_gain[7], 2,
                    "incorrect value for if_gain[7], expected 2, is {}",
                    msg.if_gain[7]
                );
                assert_eq!(
                    msg.rf_gain[0], 41,
                    "incorrect value for rf_gain[0], expected 41, is {}",
                    msg.rf_gain[0]
                );
                assert_eq!(
                    msg.rf_gain[1], -123,
                    "incorrect value for rf_gain[1], expected -123, is {}",
                    msg.rf_gain[1]
                );
                assert_eq!(
                    msg.rf_gain[2], -122,
                    "incorrect value for rf_gain[2], expected -122, is {}",
                    msg.rf_gain[2]
                );
                assert_eq!(
                    msg.rf_gain[3], 10,
                    "incorrect value for rf_gain[3], expected 10, is {}",
                    msg.rf_gain[3]
                );
                assert_eq!(
                    msg.rf_gain[4], 105,
                    "incorrect value for rf_gain[4], expected 105, is {}",
                    msg.rf_gain[4]
                );
                assert_eq!(
                    msg.rf_gain[5], 20,
                    "incorrect value for rf_gain[5], expected 20, is {}",
                    msg.rf_gain[5]
                );
                assert_eq!(
                    msg.rf_gain[6], 38,
                    "incorrect value for rf_gain[6], expected 38, is {}",
                    msg.rf_gain[6]
                );
                assert_eq!(
                    msg.rf_gain[7], 38,
                    "incorrect value for rf_gain[7], expected 38, is {}",
                    msg.rf_gain[7]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFrontEndGain"),
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
fn test_json2sbp_auto_check_sbp_piksi_msg_front_end_gain() {
    {
        let json_input = r#"{"crc":34795,"length":16,"msg_type":191,"payload":"KYWGCmkUJib26dhQu9VVAg==","preamble":85,"sender":62895,"rf_gain":[41,-123,-122,10,105,20,38,38],"if_gain":[-10,-23,-40,80,-69,-43,85,2]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgFrontEndGain(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xbf,
                    "Incorrect message type, expected 0xbf, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf5af,
                    "incorrect sender id, expected 0xf5af, is {sender_id}"
                );
                assert_eq!(
                    msg.if_gain[0], -10,
                    "incorrect value for if_gain[0], expected -10, is {}",
                    msg.if_gain[0]
                );
                assert_eq!(
                    msg.if_gain[1], -23,
                    "incorrect value for if_gain[1], expected -23, is {}",
                    msg.if_gain[1]
                );
                assert_eq!(
                    msg.if_gain[2], -40,
                    "incorrect value for if_gain[2], expected -40, is {}",
                    msg.if_gain[2]
                );
                assert_eq!(
                    msg.if_gain[3], 80,
                    "incorrect value for if_gain[3], expected 80, is {}",
                    msg.if_gain[3]
                );
                assert_eq!(
                    msg.if_gain[4], -69,
                    "incorrect value for if_gain[4], expected -69, is {}",
                    msg.if_gain[4]
                );
                assert_eq!(
                    msg.if_gain[5], -43,
                    "incorrect value for if_gain[5], expected -43, is {}",
                    msg.if_gain[5]
                );
                assert_eq!(
                    msg.if_gain[6], 85,
                    "incorrect value for if_gain[6], expected 85, is {}",
                    msg.if_gain[6]
                );
                assert_eq!(
                    msg.if_gain[7], 2,
                    "incorrect value for if_gain[7], expected 2, is {}",
                    msg.if_gain[7]
                );
                assert_eq!(
                    msg.rf_gain[0], 41,
                    "incorrect value for rf_gain[0], expected 41, is {}",
                    msg.rf_gain[0]
                );
                assert_eq!(
                    msg.rf_gain[1], -123,
                    "incorrect value for rf_gain[1], expected -123, is {}",
                    msg.rf_gain[1]
                );
                assert_eq!(
                    msg.rf_gain[2], -122,
                    "incorrect value for rf_gain[2], expected -122, is {}",
                    msg.rf_gain[2]
                );
                assert_eq!(
                    msg.rf_gain[3], 10,
                    "incorrect value for rf_gain[3], expected 10, is {}",
                    msg.rf_gain[3]
                );
                assert_eq!(
                    msg.rf_gain[4], 105,
                    "incorrect value for rf_gain[4], expected 105, is {}",
                    msg.rf_gain[4]
                );
                assert_eq!(
                    msg.rf_gain[5], 20,
                    "incorrect value for rf_gain[5], expected 20, is {}",
                    msg.rf_gain[5]
                );
                assert_eq!(
                    msg.rf_gain[6], 38,
                    "incorrect value for rf_gain[6], expected 38, is {}",
                    msg.rf_gain[6]
                );
                assert_eq!(
                    msg.rf_gain[7], 38,
                    "incorrect value for rf_gain[7], expected 38, is {}",
                    msg.rf_gain[7]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFrontEndGain"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_piksi_msg_front_end_gain`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_piksi_msg_front_end_gain() {
    {
        let mut payload = Cursor::new(vec![
            85, 191, 0, 175, 245, 16, 41, 133, 134, 10, 105, 20, 38, 38, 246, 233, 216, 80, 187,
            213, 85, 2, 235, 135,
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
        let sbp_msg = sbp::messages::Sbp::MsgFrontEndGain(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgFrontEndGain(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xbf,
                    "Incorrect message type, expected 0xbf, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf5af,
                    "incorrect sender id, expected 0xf5af, is {sender_id}"
                );
                assert_eq!(
                    msg.if_gain[0], -10,
                    "incorrect value for if_gain[0], expected -10, is {}",
                    msg.if_gain[0]
                );
                assert_eq!(
                    msg.if_gain[1], -23,
                    "incorrect value for if_gain[1], expected -23, is {}",
                    msg.if_gain[1]
                );
                assert_eq!(
                    msg.if_gain[2], -40,
                    "incorrect value for if_gain[2], expected -40, is {}",
                    msg.if_gain[2]
                );
                assert_eq!(
                    msg.if_gain[3], 80,
                    "incorrect value for if_gain[3], expected 80, is {}",
                    msg.if_gain[3]
                );
                assert_eq!(
                    msg.if_gain[4], -69,
                    "incorrect value for if_gain[4], expected -69, is {}",
                    msg.if_gain[4]
                );
                assert_eq!(
                    msg.if_gain[5], -43,
                    "incorrect value for if_gain[5], expected -43, is {}",
                    msg.if_gain[5]
                );
                assert_eq!(
                    msg.if_gain[6], 85,
                    "incorrect value for if_gain[6], expected 85, is {}",
                    msg.if_gain[6]
                );
                assert_eq!(
                    msg.if_gain[7], 2,
                    "incorrect value for if_gain[7], expected 2, is {}",
                    msg.if_gain[7]
                );
                assert_eq!(
                    msg.rf_gain[0], 41,
                    "incorrect value for rf_gain[0], expected 41, is {}",
                    msg.rf_gain[0]
                );
                assert_eq!(
                    msg.rf_gain[1], -123,
                    "incorrect value for rf_gain[1], expected -123, is {}",
                    msg.rf_gain[1]
                );
                assert_eq!(
                    msg.rf_gain[2], -122,
                    "incorrect value for rf_gain[2], expected -122, is {}",
                    msg.rf_gain[2]
                );
                assert_eq!(
                    msg.rf_gain[3], 10,
                    "incorrect value for rf_gain[3], expected 10, is {}",
                    msg.rf_gain[3]
                );
                assert_eq!(
                    msg.rf_gain[4], 105,
                    "incorrect value for rf_gain[4], expected 105, is {}",
                    msg.rf_gain[4]
                );
                assert_eq!(
                    msg.rf_gain[5], 20,
                    "incorrect value for rf_gain[5], expected 20, is {}",
                    msg.rf_gain[5]
                );
                assert_eq!(
                    msg.rf_gain[6], 38,
                    "incorrect value for rf_gain[6], expected 38, is {}",
                    msg.rf_gain[6]
                );
                assert_eq!(
                    msg.rf_gain[7], 38,
                    "incorrect value for rf_gain[7], expected 38, is {}",
                    msg.rf_gain[7]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFrontEndGain"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
