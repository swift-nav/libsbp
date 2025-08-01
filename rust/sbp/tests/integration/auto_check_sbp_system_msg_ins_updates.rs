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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgInsUpdates.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_system_msg_ins_updates() {
    {
        let mut payload = Cursor::new(vec![
            85, 6, 255, 21, 3, 10, 84, 229, 17, 30, 0, 0, 0, 0, 0, 0, 81, 63,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgInsUpdates(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff06,
                    "Incorrect message type, expected 0xff06, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x315,
                    "incorrect sender id, expected 0x315, is {sender_id}"
                );
                assert_eq!(
                    msg.gnsspos, 0,
                    "incorrect value for gnsspos, expected 0, is {}",
                    msg.gnsspos
                );
                assert_eq!(
                    msg.gnssvel, 0,
                    "incorrect value for gnssvel, expected 0, is {}",
                    msg.gnssvel
                );
                assert_eq!(
                    msg.nhc, 0,
                    "incorrect value for nhc, expected 0, is {}",
                    msg.nhc
                );
                assert_eq!(
                    msg.speed, 0,
                    "incorrect value for speed, expected 0, is {}",
                    msg.speed
                );
                assert_eq!(
                    msg.tow, 504489300,
                    "incorrect value for tow, expected 504489300, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wheelticks, 0,
                    "incorrect value for wheelticks, expected 0, is {}",
                    msg.wheelticks
                );
                assert_eq!(
                    msg.zerovel, 0,
                    "incorrect value for zerovel, expected 0, is {}",
                    msg.zerovel
                );
            }
            _ => panic!("Invalid message type! Expected a MsgInsUpdates"),
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
fn test_json2sbp_auto_check_sbp_system_msg_ins_updates() {
    {
        let json_input = r#"{"tow":504489300,"gnsspos":0,"gnssvel":0,"wheelticks":0,"speed":0,"nhc":0,"zerovel":0,"preamble":85,"msg_type":65286,"sender":789,"payload":"VOURHgAAAAAAAA==","crc":16209,"length":10}"#.as_bytes();

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
            sbp::messages::Sbp::MsgInsUpdates(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff06,
                    "Incorrect message type, expected 0xff06, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x315,
                    "incorrect sender id, expected 0x315, is {sender_id}"
                );
                assert_eq!(
                    msg.gnsspos, 0,
                    "incorrect value for gnsspos, expected 0, is {}",
                    msg.gnsspos
                );
                assert_eq!(
                    msg.gnssvel, 0,
                    "incorrect value for gnssvel, expected 0, is {}",
                    msg.gnssvel
                );
                assert_eq!(
                    msg.nhc, 0,
                    "incorrect value for nhc, expected 0, is {}",
                    msg.nhc
                );
                assert_eq!(
                    msg.speed, 0,
                    "incorrect value for speed, expected 0, is {}",
                    msg.speed
                );
                assert_eq!(
                    msg.tow, 504489300,
                    "incorrect value for tow, expected 504489300, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wheelticks, 0,
                    "incorrect value for wheelticks, expected 0, is {}",
                    msg.wheelticks
                );
                assert_eq!(
                    msg.zerovel, 0,
                    "incorrect value for zerovel, expected 0, is {}",
                    msg.zerovel
                );
            }
            _ => panic!("Invalid message type! Expected a MsgInsUpdates"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_system_msg_ins_updates`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_system_msg_ins_updates() {
    {
        let mut payload = Cursor::new(vec![
            85, 6, 255, 21, 3, 10, 84, 229, 17, 30, 0, 0, 0, 0, 0, 0, 81, 63,
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
        let sbp_msg = sbp::messages::Sbp::MsgInsUpdates(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgInsUpdates(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff06,
                    "Incorrect message type, expected 0xff06, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x315,
                    "incorrect sender id, expected 0x315, is {sender_id}"
                );
                assert_eq!(
                    msg.gnsspos, 0,
                    "incorrect value for gnsspos, expected 0, is {}",
                    msg.gnsspos
                );
                assert_eq!(
                    msg.gnssvel, 0,
                    "incorrect value for gnssvel, expected 0, is {}",
                    msg.gnssvel
                );
                assert_eq!(
                    msg.nhc, 0,
                    "incorrect value for nhc, expected 0, is {}",
                    msg.nhc
                );
                assert_eq!(
                    msg.speed, 0,
                    "incorrect value for speed, expected 0, is {}",
                    msg.speed
                );
                assert_eq!(
                    msg.tow, 504489300,
                    "incorrect value for tow, expected 504489300, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wheelticks, 0,
                    "incorrect value for wheelticks, expected 0, is {}",
                    msg.wheelticks
                );
                assert_eq!(
                    msg.zerovel, 0,
                    "incorrect value for zerovel, expected 0, is {}",
                    msg.zerovel
                );
            }
            _ => panic!("Invalid message type! Expected a MsgInsUpdates"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
