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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevel.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_protection_level() {
    {
        let mut payload = Cursor::new(vec![
            85, 23, 2, 45, 3, 76, 110, 84, 4, 242, 46, 51, 53, 160, 89, 84, 167, 41, 57, 21, 217,
            244, 61, 161, 83, 104, 140, 137, 90, 246, 51, 51, 51, 51, 51, 170, 180, 64, 154, 153,
            153, 153, 25, 88, 195, 64, 51, 51, 51, 51, 51, 195, 121, 64, 231, 251, 38, 221, 208,
            183, 167, 80, 223, 26, 97, 164, 45, 46, 186, 60, 235, 227, 183, 160, 187, 93, 116, 224,
            105, 40, 32, 33, 133, 188,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgProtectionLevel(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x217,
                    "Incorrect message type, expected 0x217, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x032d,
                    "incorrect sender id, expected 0x032d, is {sender_id}"
                );
                assert_eq!(
                    msg.atpl, 10663,
                    "incorrect value for atpl, expected 10663, is {}",
                    msg.atpl
                );
                assert_eq!(
                    msg.ctpl, 5433,
                    "incorrect value for ctpl, expected 5433, is {}",
                    msg.ctpl
                );
                assert_eq!(
                    msg.flags, 555755625,
                    "incorrect value for flags, expected 555755625, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.heading, -529244741,
                    "incorrect value for heading, expected -529244741, is {}",
                    msg.heading
                );
                assert!(
                    msg.height.almost_eq(4.12199999999999989e+02),
                    "incorrect value for height, expected 4.12199999999999989e+02, is {:e}",
                    msg.height
                );
                assert_eq!(
                    msg.hopl, 26707,
                    "incorrect value for hopl, expected 26707, is {}",
                    msg.hopl
                );
                assert_eq!(
                    msg.hpl, 41013,
                    "incorrect value for hpl, expected 41013, is {}",
                    msg.hpl
                );
                assert_eq!(
                    msg.hvpl, 62681,
                    "incorrect value for hvpl, expected 62681, is {}",
                    msg.hvpl
                );
                assert!(
                    msg.lat.almost_eq(5.29019999999999982e+03),
                    "incorrect value for lat, expected 5.29019999999999982e+03, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(9.90420000000000073e+03),
                    "incorrect value for lon, expected 9.90420000000000073e+03, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.pitch, -1598561301,
                    "incorrect value for pitch, expected -1598561301, is {}",
                    msg.pitch
                );
                assert_eq!(
                    msg.popl, 35212,
                    "incorrect value for popl, expected 35212, is {}",
                    msg.popl
                );
                assert_eq!(
                    msg.roll, 1018834477,
                    "incorrect value for roll, expected 1018834477, is {}",
                    msg.roll
                );
                assert_eq!(
                    msg.ropl, 63066,
                    "incorrect value for ropl, expected 63066, is {}",
                    msg.ropl
                );
                assert_eq!(
                    msg.tow, 4060370030,
                    "incorrect value for tow, expected 4060370030, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_x, -584647705,
                    "incorrect value for v_x, expected -584647705, is {}",
                    msg.v_x
                );
                assert_eq!(
                    msg.v_y, 1353168848,
                    "incorrect value for v_y, expected 1353168848, is {}",
                    msg.v_y
                );
                assert_eq!(
                    msg.v_z, -1537140001,
                    "incorrect value for v_z, expected -1537140001, is {}",
                    msg.v_z
                );
                assert_eq!(
                    msg.vpl, 21593,
                    "incorrect value for vpl, expected 21593, is {}",
                    msg.vpl
                );
                assert_eq!(
                    msg.vvpl, 41277,
                    "incorrect value for vvpl, expected 41277, is {}",
                    msg.vvpl
                );
                assert_eq!(
                    msg.wn, 13102,
                    "incorrect value for wn, expected 13102, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProtectionLevel"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_protection_level() {
    {
        let json_input = r#"{"preamble":85,"msg_type":535,"sender":813,"length":76,"payload":"blQE8i4zNaBZVKcpORXZ9D2hU2iMiVr2MzMzMzOqtECamZmZGVjDQDMzMzMzw3lA5/sm3dC3p1DfGmGkLS66POvjt6C7XXTgaSggIQ==","crc":48261,"tow":4060370030,"wn":13102,"hpl":41013,"vpl":21593,"atpl":10663,"ctpl":5433,"hvpl":62681,"vvpl":41277,"hopl":26707,"popl":35212,"ropl":63066,"lat":5290.2,"lon":9904.2,"height":412.2,"v_x":-584647705,"v_y":1353168848,"v_z":-1537140001,"roll":1018834477,"pitch":-1598561301,"heading":-529244741,"flags":555755625}"#.as_bytes();

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
            sbp::messages::Sbp::MsgProtectionLevel(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x217,
                    "Incorrect message type, expected 0x217, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x032d,
                    "incorrect sender id, expected 0x032d, is {sender_id}"
                );
                assert_eq!(
                    msg.atpl, 10663,
                    "incorrect value for atpl, expected 10663, is {}",
                    msg.atpl
                );
                assert_eq!(
                    msg.ctpl, 5433,
                    "incorrect value for ctpl, expected 5433, is {}",
                    msg.ctpl
                );
                assert_eq!(
                    msg.flags, 555755625,
                    "incorrect value for flags, expected 555755625, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.heading, -529244741,
                    "incorrect value for heading, expected -529244741, is {}",
                    msg.heading
                );
                assert!(
                    msg.height.almost_eq(4.12199999999999989e+02),
                    "incorrect value for height, expected 4.12199999999999989e+02, is {:e}",
                    msg.height
                );
                assert_eq!(
                    msg.hopl, 26707,
                    "incorrect value for hopl, expected 26707, is {}",
                    msg.hopl
                );
                assert_eq!(
                    msg.hpl, 41013,
                    "incorrect value for hpl, expected 41013, is {}",
                    msg.hpl
                );
                assert_eq!(
                    msg.hvpl, 62681,
                    "incorrect value for hvpl, expected 62681, is {}",
                    msg.hvpl
                );
                assert!(
                    msg.lat.almost_eq(5.29019999999999982e+03),
                    "incorrect value for lat, expected 5.29019999999999982e+03, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(9.90420000000000073e+03),
                    "incorrect value for lon, expected 9.90420000000000073e+03, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.pitch, -1598561301,
                    "incorrect value for pitch, expected -1598561301, is {}",
                    msg.pitch
                );
                assert_eq!(
                    msg.popl, 35212,
                    "incorrect value for popl, expected 35212, is {}",
                    msg.popl
                );
                assert_eq!(
                    msg.roll, 1018834477,
                    "incorrect value for roll, expected 1018834477, is {}",
                    msg.roll
                );
                assert_eq!(
                    msg.ropl, 63066,
                    "incorrect value for ropl, expected 63066, is {}",
                    msg.ropl
                );
                assert_eq!(
                    msg.tow, 4060370030,
                    "incorrect value for tow, expected 4060370030, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_x, -584647705,
                    "incorrect value for v_x, expected -584647705, is {}",
                    msg.v_x
                );
                assert_eq!(
                    msg.v_y, 1353168848,
                    "incorrect value for v_y, expected 1353168848, is {}",
                    msg.v_y
                );
                assert_eq!(
                    msg.v_z, -1537140001,
                    "incorrect value for v_z, expected -1537140001, is {}",
                    msg.v_z
                );
                assert_eq!(
                    msg.vpl, 21593,
                    "incorrect value for vpl, expected 21593, is {}",
                    msg.vpl
                );
                assert_eq!(
                    msg.vvpl, 41277,
                    "incorrect value for vvpl, expected 41277, is {}",
                    msg.vvpl
                );
                assert_eq!(
                    msg.wn, 13102,
                    "incorrect value for wn, expected 13102, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProtectionLevel"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_protection_level`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_protection_level() {
    {
        let mut payload = Cursor::new(vec![
            85, 23, 2, 45, 3, 76, 110, 84, 4, 242, 46, 51, 53, 160, 89, 84, 167, 41, 57, 21, 217,
            244, 61, 161, 83, 104, 140, 137, 90, 246, 51, 51, 51, 51, 51, 170, 180, 64, 154, 153,
            153, 153, 25, 88, 195, 64, 51, 51, 51, 51, 51, 195, 121, 64, 231, 251, 38, 221, 208,
            183, 167, 80, 223, 26, 97, 164, 45, 46, 186, 60, 235, 227, 183, 160, 187, 93, 116, 224,
            105, 40, 32, 33, 133, 188,
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
        let sbp_msg = sbp::messages::Sbp::MsgProtectionLevel(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgProtectionLevel(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x217,
                    "Incorrect message type, expected 0x217, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x032d,
                    "incorrect sender id, expected 0x032d, is {sender_id}"
                );
                assert_eq!(
                    msg.atpl, 10663,
                    "incorrect value for atpl, expected 10663, is {}",
                    msg.atpl
                );
                assert_eq!(
                    msg.ctpl, 5433,
                    "incorrect value for ctpl, expected 5433, is {}",
                    msg.ctpl
                );
                assert_eq!(
                    msg.flags, 555755625,
                    "incorrect value for flags, expected 555755625, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.heading, -529244741,
                    "incorrect value for heading, expected -529244741, is {}",
                    msg.heading
                );
                assert!(
                    msg.height.almost_eq(4.12199999999999989e+02),
                    "incorrect value for height, expected 4.12199999999999989e+02, is {:e}",
                    msg.height
                );
                assert_eq!(
                    msg.hopl, 26707,
                    "incorrect value for hopl, expected 26707, is {}",
                    msg.hopl
                );
                assert_eq!(
                    msg.hpl, 41013,
                    "incorrect value for hpl, expected 41013, is {}",
                    msg.hpl
                );
                assert_eq!(
                    msg.hvpl, 62681,
                    "incorrect value for hvpl, expected 62681, is {}",
                    msg.hvpl
                );
                assert!(
                    msg.lat.almost_eq(5.29019999999999982e+03),
                    "incorrect value for lat, expected 5.29019999999999982e+03, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(9.90420000000000073e+03),
                    "incorrect value for lon, expected 9.90420000000000073e+03, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.pitch, -1598561301,
                    "incorrect value for pitch, expected -1598561301, is {}",
                    msg.pitch
                );
                assert_eq!(
                    msg.popl, 35212,
                    "incorrect value for popl, expected 35212, is {}",
                    msg.popl
                );
                assert_eq!(
                    msg.roll, 1018834477,
                    "incorrect value for roll, expected 1018834477, is {}",
                    msg.roll
                );
                assert_eq!(
                    msg.ropl, 63066,
                    "incorrect value for ropl, expected 63066, is {}",
                    msg.ropl
                );
                assert_eq!(
                    msg.tow, 4060370030,
                    "incorrect value for tow, expected 4060370030, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_x, -584647705,
                    "incorrect value for v_x, expected -584647705, is {}",
                    msg.v_x
                );
                assert_eq!(
                    msg.v_y, 1353168848,
                    "incorrect value for v_y, expected 1353168848, is {}",
                    msg.v_y
                );
                assert_eq!(
                    msg.v_z, -1537140001,
                    "incorrect value for v_z, expected -1537140001, is {}",
                    msg.v_z
                );
                assert_eq!(
                    msg.vpl, 21593,
                    "incorrect value for vpl, expected 21593, is {}",
                    msg.vpl
                );
                assert_eq!(
                    msg.vvpl, 41277,
                    "incorrect value for vvpl, expected 41277, is {}",
                    msg.vvpl
                );
                assert_eq!(
                    msg.wn, 13102,
                    "incorrect value for wn, expected 13102, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProtectionLevel"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
