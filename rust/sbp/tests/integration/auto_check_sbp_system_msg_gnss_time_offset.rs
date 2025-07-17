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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgGnssTimeOffset.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_system_msg_gnss_time_offset() {
    {
        let mut payload = Cursor::new(vec![
            85, 7, 255, 22, 15, 9, 9, 58, 82, 83, 9, 103, 22, 37, 221, 84, 100,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGnssTimeOffset(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff07,
                    "Incorrect message type, expected 0xff07, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0f16,
                    "incorrect sender id, expected 0x0f16, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 221,
                    "incorrect value for flags, expected 221, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.microseconds, 9494,
                    "incorrect value for microseconds, expected 9494, is {}",
                    msg.microseconds
                );
                assert_eq!(
                    msg.milliseconds, 1728664402,
                    "incorrect value for milliseconds, expected 1728664402, is {}",
                    msg.milliseconds
                );
                assert_eq!(
                    msg.weeks, 14857,
                    "incorrect value for weeks, expected 14857, is {}",
                    msg.weeks
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGnssTimeOffset"),
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
fn test_json2sbp_auto_check_sbp_system_msg_gnss_time_offset() {
    {
        let json_input = r#"{"preamble":85,"msg_type":65287,"sender":3862,"length":9,"payload":"CTpSUwlnFiXd","crc":25684,"weeks":14857,"milliseconds":1728664402,"microseconds":9494,"flags":221}"#.as_bytes();

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
            sbp::messages::Sbp::MsgGnssTimeOffset(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff07,
                    "Incorrect message type, expected 0xff07, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0f16,
                    "incorrect sender id, expected 0x0f16, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 221,
                    "incorrect value for flags, expected 221, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.microseconds, 9494,
                    "incorrect value for microseconds, expected 9494, is {}",
                    msg.microseconds
                );
                assert_eq!(
                    msg.milliseconds, 1728664402,
                    "incorrect value for milliseconds, expected 1728664402, is {}",
                    msg.milliseconds
                );
                assert_eq!(
                    msg.weeks, 14857,
                    "incorrect value for weeks, expected 14857, is {}",
                    msg.weeks
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGnssTimeOffset"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_system_msg_gnss_time_offset`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_system_msg_gnss_time_offset() {
    {
        let mut payload = Cursor::new(vec![
            85, 7, 255, 22, 15, 9, 9, 58, 82, 83, 9, 103, 22, 37, 221, 84, 100,
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
        let sbp_msg = sbp::messages::Sbp::MsgGnssTimeOffset(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgGnssTimeOffset(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff07,
                    "Incorrect message type, expected 0xff07, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0f16,
                    "incorrect sender id, expected 0x0f16, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 221,
                    "incorrect value for flags, expected 221, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.microseconds, 9494,
                    "incorrect value for microseconds, expected 9494, is {}",
                    msg.microseconds
                );
                assert_eq!(
                    msg.milliseconds, 1728664402,
                    "incorrect value for milliseconds, expected 1728664402, is {}",
                    msg.milliseconds
                );
                assert_eq!(
                    msg.weeks, 14857,
                    "incorrect value for weeks, expected 14857, is {}",
                    msg.weeks
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGnssTimeOffset"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
