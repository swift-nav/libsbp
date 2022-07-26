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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCov.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_pos_ecef_cov() {
    {
        let mut payload = Cursor::new(vec![
            85, 20, 2, 66, 0, 54, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 64, 0, 0, 0, 0, 0, 0, 240, 63,
            0, 0, 0, 0, 0, 0, 16, 64, 0, 0, 0, 65, 0, 0, 224, 64, 0, 0, 0, 64, 0, 0, 192, 64, 0, 0,
            0, 65, 0, 0, 160, 64, 4, 5, 249, 167,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefCov(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x214,
                    "Incorrect message type, expected 0x214, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(8.00000000000000000e+00),
                    "incorrect value for cov_x_x, expected 8.00000000000000000e+00, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(7.00000000000000000e+00),
                    "incorrect value for cov_x_y, expected 7.00000000000000000e+00, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_z, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(6.00000000000000000e+00),
                    "incorrect value for cov_y_y, expected 6.00000000000000000e+00, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(8.00000000000000000e+00),
                    "incorrect value for cov_y_z, expected 8.00000000000000000e+00, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(5.00000000000000000e+00),
                    "incorrect value for cov_z_z, expected 5.00000000000000000e+00, is {:e}",
                    msg.cov_z_z
                );
                assert_eq!(
                    msg.flags, 5,
                    "incorrect value for flags, expected 5, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 4,
                    "incorrect value for n_sats, expected 4, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 7,
                    "incorrect value for tow, expected 7, is {}",
                    msg.tow
                );
                assert!(
                    msg.x.almost_eq(6.00000000000000000e+00),
                    "incorrect value for x, expected 6.00000000000000000e+00, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(1.00000000000000000e+00),
                    "incorrect value for y, expected 1.00000000000000000e+00, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(4.00000000000000000e+00),
                    "incorrect value for z, expected 4.00000000000000000e+00, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFCov"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_pos_ecef_cov() {
    {
        let json_input = r#"{"cov_y_z": 8, "cov_y_y": 6, "n_sats": 4, "sender": 66, "msg_type": 532, "cov_x_z": 2, "cov_x_y": 7, "cov_x_x": 8, "tow": 7, "crc": 43001, "length": 54, "flags": 5, "y": 1, "x": 6, "z": 4, "preamble": 85, "payload": "BwAAAAAAAAAAABhAAAAAAAAA8D8AAAAAAAAQQAAAAEEAAOBAAAAAQAAAwEAAAABBAACgQAQF", "cov_z_z": 5}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosEcefCov(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x214,
                    "Incorrect message type, expected 0x214, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(8.00000000000000000e+00),
                    "incorrect value for cov_x_x, expected 8.00000000000000000e+00, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(7.00000000000000000e+00),
                    "incorrect value for cov_x_y, expected 7.00000000000000000e+00, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_z, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(6.00000000000000000e+00),
                    "incorrect value for cov_y_y, expected 6.00000000000000000e+00, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(8.00000000000000000e+00),
                    "incorrect value for cov_y_z, expected 8.00000000000000000e+00, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(5.00000000000000000e+00),
                    "incorrect value for cov_z_z, expected 5.00000000000000000e+00, is {:e}",
                    msg.cov_z_z
                );
                assert_eq!(
                    msg.flags, 5,
                    "incorrect value for flags, expected 5, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 4,
                    "incorrect value for n_sats, expected 4, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 7,
                    "incorrect value for tow, expected 7, is {}",
                    msg.tow
                );
                assert!(
                    msg.x.almost_eq(6.00000000000000000e+00),
                    "incorrect value for x, expected 6.00000000000000000e+00, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(1.00000000000000000e+00),
                    "incorrect value for y, expected 1.00000000000000000e+00, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(4.00000000000000000e+00),
                    "incorrect value for z, expected 4.00000000000000000e+00, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFCov"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_pos_ecef_cov`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_pos_ecef_cov() {
    {
        let mut payload = Cursor::new(vec![
            85, 20, 2, 66, 0, 54, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 64, 0, 0, 0, 0, 0, 0, 240, 63,
            0, 0, 0, 0, 0, 0, 16, 64, 0, 0, 0, 65, 0, 0, 224, 64, 0, 0, 0, 64, 0, 0, 192, 64, 0, 0,
            0, 65, 0, 0, 160, 64, 4, 5, 249, 167,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosEcefCov(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefCov(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x214,
                    "Incorrect message type, expected 0x214, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(8.00000000000000000e+00),
                    "incorrect value for cov_x_x, expected 8.00000000000000000e+00, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(7.00000000000000000e+00),
                    "incorrect value for cov_x_y, expected 7.00000000000000000e+00, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_z, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(6.00000000000000000e+00),
                    "incorrect value for cov_y_y, expected 6.00000000000000000e+00, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(8.00000000000000000e+00),
                    "incorrect value for cov_y_z, expected 8.00000000000000000e+00, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(5.00000000000000000e+00),
                    "incorrect value for cov_z_z, expected 5.00000000000000000e+00, is {:e}",
                    msg.cov_z_z
                );
                assert_eq!(
                    msg.flags, 5,
                    "incorrect value for flags, expected 5, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 4,
                    "incorrect value for n_sats, expected 4, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 7,
                    "incorrect value for tow, expected 7, is {}",
                    msg.tow
                );
                assert!(
                    msg.x.almost_eq(6.00000000000000000e+00),
                    "incorrect value for x, expected 6.00000000000000000e+00, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(1.00000000000000000e+00),
                    "incorrect value for y, expected 1.00000000000000000e+00, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(4.00000000000000000e+00),
                    "incorrect value for z, expected 4.00000000000000000e+00, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFCov"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
