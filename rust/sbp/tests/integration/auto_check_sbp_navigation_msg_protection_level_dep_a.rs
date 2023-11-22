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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevelDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_protection_level_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 22, 2, 148, 22, 33, 52, 126, 69, 185, 47, 85, 4, 139, 51, 51, 51, 51, 51, 244, 190,
            64, 102, 102, 102, 102, 102, 204, 168, 64, 154, 153, 153, 153, 25, 39, 192, 64, 248,
            81, 104,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgProtectionLevelDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x216,
                    "Incorrect message type, expected 0x216, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1694,
                    "incorrect sender id, expected 0x1694, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 248,
                    "incorrect value for flags, expected 248, is {}",
                    msg.flags
                );
                assert!(
                    msg.height.almost_eq(8.27020000000000073e+03),
                    "incorrect value for height, expected 8.27020000000000073e+03, is {:e}",
                    msg.height
                );
                assert_eq!(
                    msg.hpl, 35588,
                    "incorrect value for hpl, expected 35588, is {}",
                    msg.hpl
                );
                assert!(
                    msg.lat.almost_eq(7.92419999999999982e+03),
                    "incorrect value for lat, expected 7.92419999999999982e+03, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(3.17419999999999982e+03),
                    "incorrect value for lon, expected 3.17419999999999982e+03, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.tow, 3108339252,
                    "incorrect value for tow, expected 3108339252, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vpl, 21807,
                    "incorrect value for vpl, expected 21807, is {}",
                    msg.vpl
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProtectionLevelDepA"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_protection_level_dep_a() {
    {
        let json_input = r#"{"crc":26705,"length":33,"msg_type":534,"payload":"NH5FuS9VBIszMzMzM/S+QGZmZmZmzKhAmpmZmRknwED4","preamble":85,"sender":5780,"tow":3108339252,"vpl":21807,"hpl":35588,"lat":7924.2,"lon":3174.2,"height":8270.2,"flags":248}"#.as_bytes();

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
            sbp::messages::Sbp::MsgProtectionLevelDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x216,
                    "Incorrect message type, expected 0x216, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1694,
                    "incorrect sender id, expected 0x1694, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 248,
                    "incorrect value for flags, expected 248, is {}",
                    msg.flags
                );
                assert!(
                    msg.height.almost_eq(8.27020000000000073e+03),
                    "incorrect value for height, expected 8.27020000000000073e+03, is {:e}",
                    msg.height
                );
                assert_eq!(
                    msg.hpl, 35588,
                    "incorrect value for hpl, expected 35588, is {}",
                    msg.hpl
                );
                assert!(
                    msg.lat.almost_eq(7.92419999999999982e+03),
                    "incorrect value for lat, expected 7.92419999999999982e+03, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(3.17419999999999982e+03),
                    "incorrect value for lon, expected 3.17419999999999982e+03, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.tow, 3108339252,
                    "incorrect value for tow, expected 3108339252, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vpl, 21807,
                    "incorrect value for vpl, expected 21807, is {}",
                    msg.vpl
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProtectionLevelDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_protection_level_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_protection_level_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 22, 2, 148, 22, 33, 52, 126, 69, 185, 47, 85, 4, 139, 51, 51, 51, 51, 51, 244, 190,
            64, 102, 102, 102, 102, 102, 204, 168, 64, 154, 153, 153, 153, 25, 39, 192, 64, 248,
            81, 104,
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
        let sbp_msg = sbp::messages::Sbp::MsgProtectionLevelDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgProtectionLevelDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x216,
                    "Incorrect message type, expected 0x216, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1694,
                    "incorrect sender id, expected 0x1694, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 248,
                    "incorrect value for flags, expected 248, is {}",
                    msg.flags
                );
                assert!(
                    msg.height.almost_eq(8.27020000000000073e+03),
                    "incorrect value for height, expected 8.27020000000000073e+03, is {:e}",
                    msg.height
                );
                assert_eq!(
                    msg.hpl, 35588,
                    "incorrect value for hpl, expected 35588, is {}",
                    msg.hpl
                );
                assert!(
                    msg.lat.almost_eq(7.92419999999999982e+03),
                    "incorrect value for lat, expected 7.92419999999999982e+03, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(3.17419999999999982e+03),
                    "incorrect value for lon, expected 3.17419999999999982e+03, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.tow, 3108339252,
                    "incorrect value for tow, expected 3108339252, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vpl, 21807,
                    "incorrect value for vpl, expected 21807, is {}",
                    msg.vpl
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProtectionLevelDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
