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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/vehicle/test_MsgWheeltick.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_vehicle_msg_wheeltick() {
    {
        let mut payload = Cursor::new(vec![
            85, 4, 9, 107, 69, 14, 254, 27, 114, 44, 26, 0, 0, 0, 1, 146, 225, 51, 9, 210, 36, 56,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgWheeltick(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x904,
                    "Incorrect message type, expected 0x904, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x456b,
                    "incorrect sender id, expected 0x456b, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.source, 146,
                    "incorrect value for source, expected 146, is {}",
                    msg.source
                );
                assert_eq!(
                    msg.ticks, -771148831,
                    "incorrect value for ticks, expected -771148831, is {}",
                    msg.ticks
                );
                assert_eq!(
                    msg.time, 112414825470,
                    "incorrect value for time, expected 112414825470, is {}",
                    msg.time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgWheeltick"),
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
fn test_json2sbp_auto_check_sbp_vehicle_msg_wheeltick() {
    {
        let json_input = r#"{"preamble":85,"msg_type":2308,"sender":17771,"length":14,"payload":"/htyLBoAAAABkuEzCdI=","crc":14372,"time":112414825470,"flags":1,"source":146,"ticks":-771148831}"#.as_bytes();

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
            sbp::messages::Sbp::MsgWheeltick(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x904,
                    "Incorrect message type, expected 0x904, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x456b,
                    "incorrect sender id, expected 0x456b, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.source, 146,
                    "incorrect value for source, expected 146, is {}",
                    msg.source
                );
                assert_eq!(
                    msg.ticks, -771148831,
                    "incorrect value for ticks, expected -771148831, is {}",
                    msg.ticks
                );
                assert_eq!(
                    msg.time, 112414825470,
                    "incorrect value for time, expected 112414825470, is {}",
                    msg.time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgWheeltick"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_vehicle_msg_wheeltick`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_vehicle_msg_wheeltick() {
    {
        let mut payload = Cursor::new(vec![
            85, 4, 9, 107, 69, 14, 254, 27, 114, 44, 26, 0, 0, 0, 1, 146, 225, 51, 9, 210, 36, 56,
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
        let sbp_msg = sbp::messages::Sbp::MsgWheeltick(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgWheeltick(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x904,
                    "Incorrect message type, expected 0x904, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x456b,
                    "incorrect sender id, expected 0x456b, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.source, 146,
                    "incorrect value for source, expected 146, is {}",
                    msg.source
                );
                assert_eq!(
                    msg.ticks, -771148831,
                    "incorrect value for ticks, expected -771148831, is {}",
                    msg.ticks
                );
                assert_eq!(
                    msg.time, 112414825470,
                    "incorrect value for time, expected 112414825470, is {}",
                    msg.time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgWheeltick"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
