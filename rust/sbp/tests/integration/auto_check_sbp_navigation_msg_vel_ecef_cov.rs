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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEFCov.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_vel_ecef_cov() {
    {
        let mut payload = Cursor::new(vec![
            85, 21, 2, 66, 0, 42, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 64, 0,
            0, 0, 64, 0, 0, 0, 64, 0, 0, 0, 64, 0, 0, 128, 63, 0, 0, 64, 64, 3, 4, 91, 254,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefCov(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x215,
                    "Incorrect message type, expected 0x215, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_x, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_y, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_z, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_y_y, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_y_z, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(3.00000000000000000e+00),
                    "incorrect value for cov_z_z, expected 3.00000000000000000e+00, is {:e}",
                    msg.cov_z_z
                );
                assert_eq!(
                    msg.flags, 4,
                    "incorrect value for flags, expected 4, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 3,
                    "incorrect value for n_sats, expected 3, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2,
                    "incorrect value for tow, expected 2, is {}",
                    msg.tow
                );
                assert_eq!(msg.x, 0, "incorrect value for x, expected 0, is {}", msg.x);
                assert_eq!(msg.y, 0, "incorrect value for y, expected 0, is {}", msg.y);
                assert_eq!(msg.z, 6, "incorrect value for z, expected 6, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFCov"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_vel_ecef_cov() {
    {
        let json_input = r#"{"cov_y_z": 1, "cov_y_y": 2, "n_sats": 3, "sender": 66, "msg_type": 533, "cov_x_z": 2, "cov_x_y": 2, "cov_x_x": 2, "tow": 2, "crc": 65115, "length": 42, "flags": 4, "y": 0, "x": 0, "z": 6, "preamble": 85, "payload": "AgAAAAAAAAAAAAAABgAAAAAAAEAAAABAAAAAQAAAAEAAAIA/AABAQAME", "cov_z_z": 3}"#.as_bytes();

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
            sbp::messages::Sbp::MsgVelEcefCov(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x215,
                    "Incorrect message type, expected 0x215, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_x, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_y, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_z, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_y_y, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_y_z, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(3.00000000000000000e+00),
                    "incorrect value for cov_z_z, expected 3.00000000000000000e+00, is {:e}",
                    msg.cov_z_z
                );
                assert_eq!(
                    msg.flags, 4,
                    "incorrect value for flags, expected 4, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 3,
                    "incorrect value for n_sats, expected 3, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2,
                    "incorrect value for tow, expected 2, is {}",
                    msg.tow
                );
                assert_eq!(msg.x, 0, "incorrect value for x, expected 0, is {}", msg.x);
                assert_eq!(msg.y, 0, "incorrect value for y, expected 0, is {}", msg.y);
                assert_eq!(msg.z, 6, "incorrect value for z, expected 6, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFCov"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_vel_ecef_cov`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_vel_ecef_cov() {
    {
        let mut payload = Cursor::new(vec![
            85, 21, 2, 66, 0, 42, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 64, 0,
            0, 0, 64, 0, 0, 0, 64, 0, 0, 0, 64, 0, 0, 128, 63, 0, 0, 64, 64, 3, 4, 91, 254,
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
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefCov(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefCov(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x215,
                    "Incorrect message type, expected 0x215, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_x, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_y, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_z, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_y_y, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_y_z, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(3.00000000000000000e+00),
                    "incorrect value for cov_z_z, expected 3.00000000000000000e+00, is {:e}",
                    msg.cov_z_z
                );
                assert_eq!(
                    msg.flags, 4,
                    "incorrect value for flags, expected 4, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 3,
                    "incorrect value for n_sats, expected 3, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2,
                    "incorrect value for tow, expected 2, is {}",
                    msg.tow
                );
                assert_eq!(msg.x, 0, "incorrect value for x, expected 0, is {}", msg.x);
                assert_eq!(msg.y, 0, "incorrect value for y, expected 0, is {}", msg.y);
                assert_eq!(msg.z, 6, "incorrect value for z, expected 6, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFCov"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
