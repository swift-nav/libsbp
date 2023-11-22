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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgCsacTelemetryLabels.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_system_msg_csac_telemetry_labels() {
    {
        let mut payload = Cursor::new(vec![
            85, 5, 255, 91, 200, 12, 186, 115, 111, 109, 101, 32, 108, 97, 98, 101, 108, 115, 86,
            236,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgCsacTelemetryLabels(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff05,
                    "Incorrect message type, expected 0xff05, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc85b,
                    "incorrect sender id, expected 0xc85b, is {sender_id}"
                );
                assert_eq!(
                    msg.id, 186,
                    "incorrect value for id, expected 186, is {}",
                    msg.id
                );
                assert_eq!(
                    msg.telemetry_labels.as_bytes(),
                    &[115, 111, 109, 101, 32, 108, 97, 98, 101, 108, 115],
                    "incorrect value for msg.telemetry_labels, expected string '{:?}', is '{:?}'",
                    &[115, 111, 109, 101, 32, 108, 97, 98, 101, 108, 115],
                    msg.telemetry_labels.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCsacTelemetryLabels"),
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
fn test_json2sbp_auto_check_sbp_system_msg_csac_telemetry_labels() {
    {
        let json_input = r#"{"preamble":85,"msg_type":65285,"sender":51291,"length":12,"payload":"unNvbWUgbGFiZWxz","crc":60502,"id":186,"telemetry_labels":"some labels"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgCsacTelemetryLabels(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff05,
                    "Incorrect message type, expected 0xff05, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc85b,
                    "incorrect sender id, expected 0xc85b, is {sender_id}"
                );
                assert_eq!(
                    msg.id, 186,
                    "incorrect value for id, expected 186, is {}",
                    msg.id
                );
                assert_eq!(
                    msg.telemetry_labels.as_bytes(),
                    &[115, 111, 109, 101, 32, 108, 97, 98, 101, 108, 115],
                    "incorrect value for msg.telemetry_labels, expected string '{:?}', is '{:?}'",
                    &[115, 111, 109, 101, 32, 108, 97, 98, 101, 108, 115],
                    msg.telemetry_labels.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCsacTelemetryLabels"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_system_msg_csac_telemetry_labels`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_system_msg_csac_telemetry_labels() {
    {
        let mut payload = Cursor::new(vec![
            85, 5, 255, 91, 200, 12, 186, 115, 111, 109, 101, 32, 108, 97, 98, 101, 108, 115, 86,
            236,
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
        let sbp_msg = sbp::messages::Sbp::MsgCsacTelemetryLabels(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgCsacTelemetryLabels(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff05,
                    "Incorrect message type, expected 0xff05, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc85b,
                    "incorrect sender id, expected 0xc85b, is {sender_id}"
                );
                assert_eq!(
                    msg.id, 186,
                    "incorrect value for id, expected 186, is {}",
                    msg.id
                );
                assert_eq!(
                    msg.telemetry_labels.as_bytes(),
                    &[115, 111, 109, 101, 32, 108, 97, 98, 101, 108, 115],
                    "incorrect value for msg.telemetry_labels, expected string '{:?}', is '{:?}'",
                    &[115, 111, 109, 101, 32, 108, 97, 98, 101, 108, 115],
                    msg.telemetry_labels.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCsacTelemetryLabels"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
