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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCommandOutput.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_piksi_msg_command_output() {
    {
        let mut payload = Cursor::new(vec![
            85, 188, 0, 50, 84, 20, 126, 164, 116, 149, 83, 111, 109, 101, 32, 111, 117, 116, 112,
            117, 116, 32, 116, 101, 120, 116, 11, 109,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgCommandOutput(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xbc,
                    "Incorrect message type, expected 0xbc, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5432,
                    "incorrect sender id, expected 0x5432, is {sender_id}"
                );
                assert_eq!(
                    msg.line.as_bytes(),
                    &[83, 111, 109, 101, 32, 111, 117, 116, 112, 117, 116, 32, 116, 101, 120, 116],
                    "incorrect value for msg.line, expected string '{:?}', is '{:?}'",
                    &[83, 111, 109, 101, 32, 111, 117, 116, 112, 117, 116, 32, 116, 101, 120, 116],
                    msg.line.as_bytes()
                );
                assert_eq!(
                    msg.sequence, 2507449470,
                    "incorrect value for sequence, expected 2507449470, is {}",
                    msg.sequence
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCommandOutput"),
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
fn test_json2sbp_auto_check_sbp_piksi_msg_command_output() {
    {
        let json_input = r#"{"crc":27915,"length":20,"msg_type":188,"payload":"fqR0lVNvbWUgb3V0cHV0IHRleHQ=","preamble":85,"sender":21554,"sequence":2507449470,"line":"Some output text"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgCommandOutput(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xbc,
                    "Incorrect message type, expected 0xbc, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5432,
                    "incorrect sender id, expected 0x5432, is {sender_id}"
                );
                assert_eq!(
                    msg.line.as_bytes(),
                    &[83, 111, 109, 101, 32, 111, 117, 116, 112, 117, 116, 32, 116, 101, 120, 116],
                    "incorrect value for msg.line, expected string '{:?}', is '{:?}'",
                    &[83, 111, 109, 101, 32, 111, 117, 116, 112, 117, 116, 32, 116, 101, 120, 116],
                    msg.line.as_bytes()
                );
                assert_eq!(
                    msg.sequence, 2507449470,
                    "incorrect value for sequence, expected 2507449470, is {}",
                    msg.sequence
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCommandOutput"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_piksi_msg_command_output`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_piksi_msg_command_output() {
    {
        let mut payload = Cursor::new(vec![
            85, 188, 0, 50, 84, 20, 126, 164, 116, 149, 83, 111, 109, 101, 32, 111, 117, 116, 112,
            117, 116, 32, 116, 101, 120, 116, 11, 109,
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
        let sbp_msg = sbp::messages::Sbp::MsgCommandOutput(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgCommandOutput(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xbc,
                    "Incorrect message type, expected 0xbc, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5432,
                    "incorrect sender id, expected 0x5432, is {sender_id}"
                );
                assert_eq!(
                    msg.line.as_bytes(),
                    &[83, 111, 109, 101, 32, 111, 117, 116, 112, 117, 116, 32, 116, 101, 120, 116],
                    "incorrect value for msg.line, expected string '{:?}', is '{:?}'",
                    &[83, 111, 109, 101, 32, 111, 117, 116, 112, 117, 116, 32, 116, 101, 120, 116],
                    msg.line.as_bytes()
                );
                assert_eq!(
                    msg.sequence, 2507449470,
                    "incorrect value for sequence, expected 2507449470, is {}",
                    msg.sequence
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCommandOutput"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
