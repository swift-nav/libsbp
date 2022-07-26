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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgUTCTimeGNSS.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_utc_time_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 5, 1, 21, 3, 16, 1, 24, 229, 233, 29, 229, 7, 4, 9, 19, 24, 9, 0, 8, 175, 47, 177,
            33,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgUtcTimeGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x105,
                    "Incorrect message type, expected 0x105, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x315,
                    "incorrect sender id, expected 0x315, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.day, 9,
                    "incorrect value for day, expected 9, is {}",
                    msg.day
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.hours, 19,
                    "incorrect value for hours, expected 19, is {}",
                    msg.hours
                );
                assert_eq!(
                    msg.minutes, 24,
                    "incorrect value for minutes, expected 24, is {}",
                    msg.minutes
                );
                assert_eq!(
                    msg.month, 4,
                    "incorrect value for month, expected 4, is {}",
                    msg.month
                );
                assert_eq!(
                    msg.ns, 800000000,
                    "incorrect value for ns, expected 800000000, is {}",
                    msg.ns
                );
                assert_eq!(
                    msg.seconds, 9,
                    "incorrect value for seconds, expected 9, is {}",
                    msg.seconds
                );
                assert_eq!(
                    msg.tow, 501867800,
                    "incorrect value for tow, expected 501867800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.year, 2021,
                    "incorrect value for year, expected 2021, is {}",
                    msg.year
                );
            }
            _ => panic!("Invalid message type! Expected a MsgUtcTimeGnss"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_utc_time_gnss() {
    {
        let json_input = r#"{"flags":1,"tow":501867800,"year":2021,"month":4,"day":9,"hours":19,"minutes":24,"seconds":9,"ns":800000000,"preamble":85,"msg_type":261,"sender":789,"payload":"ARjl6R3lBwQJExgJAAivLw==","crc":8625,"length":16}"#.as_bytes();

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
            sbp::messages::Sbp::MsgUtcTimeGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x105,
                    "Incorrect message type, expected 0x105, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x315,
                    "incorrect sender id, expected 0x315, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.day, 9,
                    "incorrect value for day, expected 9, is {}",
                    msg.day
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.hours, 19,
                    "incorrect value for hours, expected 19, is {}",
                    msg.hours
                );
                assert_eq!(
                    msg.minutes, 24,
                    "incorrect value for minutes, expected 24, is {}",
                    msg.minutes
                );
                assert_eq!(
                    msg.month, 4,
                    "incorrect value for month, expected 4, is {}",
                    msg.month
                );
                assert_eq!(
                    msg.ns, 800000000,
                    "incorrect value for ns, expected 800000000, is {}",
                    msg.ns
                );
                assert_eq!(
                    msg.seconds, 9,
                    "incorrect value for seconds, expected 9, is {}",
                    msg.seconds
                );
                assert_eq!(
                    msg.tow, 501867800,
                    "incorrect value for tow, expected 501867800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.year, 2021,
                    "incorrect value for year, expected 2021, is {}",
                    msg.year
                );
            }
            _ => panic!("Invalid message type! Expected a MsgUtcTimeGnss"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_utc_time_gnss`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_utc_time_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 5, 1, 21, 3, 16, 1, 24, 229, 233, 29, 229, 7, 4, 9, 19, 24, 9, 0, 8, 175, 47, 177,
            33,
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
        let sbp_msg = sbp::messages::Sbp::MsgUtcTimeGnss(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgUtcTimeGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x105,
                    "Incorrect message type, expected 0x105, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x315,
                    "incorrect sender id, expected 0x315, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.day, 9,
                    "incorrect value for day, expected 9, is {}",
                    msg.day
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.hours, 19,
                    "incorrect value for hours, expected 19, is {}",
                    msg.hours
                );
                assert_eq!(
                    msg.minutes, 24,
                    "incorrect value for minutes, expected 24, is {}",
                    msg.minutes
                );
                assert_eq!(
                    msg.month, 4,
                    "incorrect value for month, expected 4, is {}",
                    msg.month
                );
                assert_eq!(
                    msg.ns, 800000000,
                    "incorrect value for ns, expected 800000000, is {}",
                    msg.ns
                );
                assert_eq!(
                    msg.seconds, 9,
                    "incorrect value for seconds, expected 9, is {}",
                    msg.seconds
                );
                assert_eq!(
                    msg.tow, 501867800,
                    "incorrect value for tow, expected 501867800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.year, 2021,
                    "incorrect value for year, expected 2021, is {}",
                    msg.year
                );
            }
            _ => panic!("Invalid message type! Expected a MsgUtcTimeGnss"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
