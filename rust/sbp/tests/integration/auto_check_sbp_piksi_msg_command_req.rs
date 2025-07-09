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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCommandReq.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_piksi_msg_command_req() {
    {
        let mut payload = Cursor::new(vec![
            85, 184, 0, 170, 184, 31, 51, 77, 163, 104, 47, 112, 97, 116, 104, 47, 116, 111, 47,
            99, 111, 109, 109, 97, 110, 100, 32, 119, 105, 116, 104, 32, 97, 114, 103, 115, 0, 38,
            24,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgCommandReq(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xb8,
                    "Incorrect message type, expected 0xb8, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xb8aa,
                    "incorrect sender id, expected 0xb8aa, is {sender_id}"
                );
                assert_eq!(
                    msg.command.as_bytes(),
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 99, 111, 109, 109, 97, 110, 100,
                        32, 119, 105, 116, 104, 32, 97, 114, 103, 115, 0
                    ],
                    "incorrect value for msg.command, expected string '{:?}', is '{:?}'",
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 99, 111, 109, 109, 97, 110, 100,
                        32, 119, 105, 116, 104, 32, 97, 114, 103, 115, 0
                    ],
                    msg.command.as_bytes()
                );
                assert_eq!(
                    msg.sequence, 1755532595,
                    "incorrect value for sequence, expected 1755532595, is {}",
                    msg.sequence
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCommandReq"),
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
fn test_json2sbp_auto_check_sbp_piksi_msg_command_req() {
    {
        let json_input = r#"{"crc":6182,"length":31,"msg_type":184,"payload":"M02jaC9wYXRoL3RvL2NvbW1hbmQgd2l0aCBhcmdzAA==","preamble":85,"sender":47274,"sequence":1755532595,"command":"/path/to/command with args\u0000"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgCommandReq(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xb8,
                    "Incorrect message type, expected 0xb8, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xb8aa,
                    "incorrect sender id, expected 0xb8aa, is {sender_id}"
                );
                assert_eq!(
                    msg.command.as_bytes(),
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 99, 111, 109, 109, 97, 110, 100,
                        32, 119, 105, 116, 104, 32, 97, 114, 103, 115, 0
                    ],
                    "incorrect value for msg.command, expected string '{:?}', is '{:?}'",
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 99, 111, 109, 109, 97, 110, 100,
                        32, 119, 105, 116, 104, 32, 97, 114, 103, 115, 0
                    ],
                    msg.command.as_bytes()
                );
                assert_eq!(
                    msg.sequence, 1755532595,
                    "incorrect value for sequence, expected 1755532595, is {}",
                    msg.sequence
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCommandReq"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_piksi_msg_command_req`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_piksi_msg_command_req() {
    {
        let mut payload = Cursor::new(vec![
            85, 184, 0, 170, 184, 31, 51, 77, 163, 104, 47, 112, 97, 116, 104, 47, 116, 111, 47,
            99, 111, 109, 109, 97, 110, 100, 32, 119, 105, 116, 104, 32, 97, 114, 103, 115, 0, 38,
            24,
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
        let sbp_msg = sbp::messages::Sbp::MsgCommandReq(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgCommandReq(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xb8,
                    "Incorrect message type, expected 0xb8, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xb8aa,
                    "incorrect sender id, expected 0xb8aa, is {sender_id}"
                );
                assert_eq!(
                    msg.command.as_bytes(),
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 99, 111, 109, 109, 97, 110, 100,
                        32, 119, 105, 116, 104, 32, 97, 114, 103, 115, 0
                    ],
                    "incorrect value for msg.command, expected string '{:?}', is '{:?}'",
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 99, 111, 109, 109, 97, 110, 100,
                        32, 119, 105, 116, 104, 32, 97, 114, 103, 115, 0
                    ],
                    msg.command.as_bytes()
                );
                assert_eq!(
                    msg.sequence, 1755532595,
                    "incorrect value for sequence, expected 1755532595, is {}",
                    msg.sequence
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCommandReq"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
