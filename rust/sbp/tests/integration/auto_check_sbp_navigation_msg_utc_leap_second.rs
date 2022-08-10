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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgUTCLeapSecond.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_utc_leap_second() {
    {
        let mut payload = Cursor::new(vec![
            85, 58, 2, 66, 0, 14, 1, 0, 2, 0, 3, 4, 5, 0, 6, 0, 7, 0, 8, 9, 50, 232,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgUtcLeapSecond(msg) => {
                assert_eq!(
                    msg.message_type(),
                    570,
                    "Incorrect message type, expected 570, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.count_after, 9,
                    "incorrect value for count_after, expected 9, is {}",
                    msg.count_after
                );
                assert_eq!(
                    msg.count_before, 4,
                    "incorrect value for count_before, expected 4, is {}",
                    msg.count_before
                );
                assert_eq!(
                    msg.ref_dn, 8,
                    "incorrect value for ref_dn, expected 8, is {}",
                    msg.ref_dn
                );
                assert_eq!(
                    msg.ref_wn, 7,
                    "incorrect value for ref_wn, expected 7, is {}",
                    msg.ref_wn
                );
                assert_eq!(
                    msg.reserved_0, 1,
                    "incorrect value for reserved_0, expected 1, is {}",
                    msg.reserved_0
                );
                assert_eq!(
                    msg.reserved_1, 2,
                    "incorrect value for reserved_1, expected 2, is {}",
                    msg.reserved_1
                );
                assert_eq!(
                    msg.reserved_2, 3,
                    "incorrect value for reserved_2, expected 3, is {}",
                    msg.reserved_2
                );
                assert_eq!(
                    msg.reserved_3, 5,
                    "incorrect value for reserved_3, expected 5, is {}",
                    msg.reserved_3
                );
                assert_eq!(
                    msg.reserved_4, 6,
                    "incorrect value for reserved_4, expected 6, is {}",
                    msg.reserved_4
                );
            }
            _ => panic!("Invalid message type! Expected a MsgUtcLeapSecond"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_utc_leap_second() {
    {
        let json_input = r#"{"reserved_0": 1, "reserved_1": 2, "reserved_2": 3, "count_before": 4, "reserved_3": 5, "reserved_4": 6, "ref_wn": 7, "ref_dn": 8, "count_after": 9, "preamble": 85, "msg_type": 570, "sender": 66, "length": 14, "payload": "AQACAAMEBQAGAAcACAk=", "crc": 59442}"#.as_bytes();

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
            sbp::messages::Sbp::MsgUtcLeapSecond(msg) => {
                assert_eq!(
                    msg.message_type(),
                    570,
                    "Incorrect message type, expected 570, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.count_after, 9,
                    "incorrect value for count_after, expected 9, is {}",
                    msg.count_after
                );
                assert_eq!(
                    msg.count_before, 4,
                    "incorrect value for count_before, expected 4, is {}",
                    msg.count_before
                );
                assert_eq!(
                    msg.ref_dn, 8,
                    "incorrect value for ref_dn, expected 8, is {}",
                    msg.ref_dn
                );
                assert_eq!(
                    msg.ref_wn, 7,
                    "incorrect value for ref_wn, expected 7, is {}",
                    msg.ref_wn
                );
                assert_eq!(
                    msg.reserved_0, 1,
                    "incorrect value for reserved_0, expected 1, is {}",
                    msg.reserved_0
                );
                assert_eq!(
                    msg.reserved_1, 2,
                    "incorrect value for reserved_1, expected 2, is {}",
                    msg.reserved_1
                );
                assert_eq!(
                    msg.reserved_2, 3,
                    "incorrect value for reserved_2, expected 3, is {}",
                    msg.reserved_2
                );
                assert_eq!(
                    msg.reserved_3, 5,
                    "incorrect value for reserved_3, expected 5, is {}",
                    msg.reserved_3
                );
                assert_eq!(
                    msg.reserved_4, 6,
                    "incorrect value for reserved_4, expected 6, is {}",
                    msg.reserved_4
                );
            }
            _ => panic!("Invalid message type! Expected a MsgUtcLeapSecond"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_utc_leap_second`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_utc_leap_second() {
    {
        let mut payload = Cursor::new(vec![
            85, 58, 2, 66, 0, 14, 1, 0, 2, 0, 3, 4, 5, 0, 6, 0, 7, 0, 8, 9, 50, 232,
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
        let sbp_msg = sbp::messages::Sbp::MsgUtcLeapSecond(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgUtcLeapSecond(msg) => {
                assert_eq!(
                    msg.message_type(),
                    570,
                    "Incorrect message type, expected 570, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.count_after, 9,
                    "incorrect value for count_after, expected 9, is {}",
                    msg.count_after
                );
                assert_eq!(
                    msg.count_before, 4,
                    "incorrect value for count_before, expected 4, is {}",
                    msg.count_before
                );
                assert_eq!(
                    msg.ref_dn, 8,
                    "incorrect value for ref_dn, expected 8, is {}",
                    msg.ref_dn
                );
                assert_eq!(
                    msg.ref_wn, 7,
                    "incorrect value for ref_wn, expected 7, is {}",
                    msg.ref_wn
                );
                assert_eq!(
                    msg.reserved_0, 1,
                    "incorrect value for reserved_0, expected 1, is {}",
                    msg.reserved_0
                );
                assert_eq!(
                    msg.reserved_1, 2,
                    "incorrect value for reserved_1, expected 2, is {}",
                    msg.reserved_1
                );
                assert_eq!(
                    msg.reserved_2, 3,
                    "incorrect value for reserved_2, expected 3, is {}",
                    msg.reserved_2
                );
                assert_eq!(
                    msg.reserved_3, 5,
                    "incorrect value for reserved_3, expected 5, is {}",
                    msg.reserved_3
                );
                assert_eq!(
                    msg.reserved_4, 6,
                    "incorrect value for reserved_4, expected 6, is {}",
                    msg.reserved_4
                );
            }
            _ => panic!("Invalid message type! Expected a MsgUtcLeapSecond"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
