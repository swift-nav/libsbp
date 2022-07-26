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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelEcefCovGnss.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_vel_ecef_cov_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 53, 2, 0, 16, 42, 224, 229, 233, 29, 253, 255, 255, 255, 1, 0, 0, 0, 4, 0, 0, 0,
            46, 224, 32, 59, 32, 214, 14, 59, 150, 147, 220, 186, 19, 63, 138, 59, 26, 150, 35,
            187, 11, 193, 119, 59, 21, 2, 22, 230,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefCovGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x235,
                    "Incorrect message type, expected 0x235, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(2.45476840063929558e-03),
                    "incorrect value for cov_x_x, expected 2.45476840063929558e-03, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(2.17951089143753052e-03),
                    "incorrect value for cov_x_y, expected 2.17951089143753052e-03, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(-1.68286520056426525e-03),
                    "incorrect value for cov_x_z, expected -1.68286520056426525e-03, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(4.21894481405615807e-03),
                    "incorrect value for cov_y_y, expected 4.21894481405615807e-03, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(-2.49612936750054359e-03),
                    "incorrect value for cov_y_z, expected -2.49612936750054359e-03, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(3.78042715601623058e-03),
                    "incorrect value for cov_z_z, expected 3.78042715601623058e-03, is {:e}",
                    msg.cov_z_z
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 21,
                    "incorrect value for n_sats, expected 21, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501868000,
                    "incorrect value for tow, expected 501868000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -3,
                    "incorrect value for x, expected -3, is {}",
                    msg.x
                );
                assert_eq!(msg.y, 1, "incorrect value for y, expected 1, is {}", msg.y);
                assert_eq!(msg.z, 4, "incorrect value for z, expected 4, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFCovGnss"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_vel_ecef_cov_gnss() {
    {
        let json_input = r#"{"tow":501868000,"x":-3,"y":1,"z":4,"cov_x_x":0.0024547684006392956,"cov_x_y":0.0021795108914375305,"cov_x_z":-0.0016828652005642653,"cov_y_y":0.004218944814056158,"cov_y_z":-0.0024961293675005436,"cov_z_z":0.0037804271560162306,"n_sats":21,"flags":2,"preamble":85,"msg_type":565,"sender":4096,"payload":"4OXpHf3///8BAAAABAAAAC7gIDsg1g47lpPcuhM/ijsaliO7C8F3OxUC","crc":58902,"length":42}"#.as_bytes();

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
            sbp::messages::Sbp::MsgVelEcefCovGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x235,
                    "Incorrect message type, expected 0x235, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(2.45476840063929558e-03),
                    "incorrect value for cov_x_x, expected 2.45476840063929558e-03, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(2.17951089143753052e-03),
                    "incorrect value for cov_x_y, expected 2.17951089143753052e-03, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(-1.68286520056426525e-03),
                    "incorrect value for cov_x_z, expected -1.68286520056426525e-03, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(4.21894481405615807e-03),
                    "incorrect value for cov_y_y, expected 4.21894481405615807e-03, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(-2.49612936750054359e-03),
                    "incorrect value for cov_y_z, expected -2.49612936750054359e-03, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(3.78042715601623058e-03),
                    "incorrect value for cov_z_z, expected 3.78042715601623058e-03, is {:e}",
                    msg.cov_z_z
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 21,
                    "incorrect value for n_sats, expected 21, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501868000,
                    "incorrect value for tow, expected 501868000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -3,
                    "incorrect value for x, expected -3, is {}",
                    msg.x
                );
                assert_eq!(msg.y, 1, "incorrect value for y, expected 1, is {}", msg.y);
                assert_eq!(msg.z, 4, "incorrect value for z, expected 4, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFCovGnss"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_vel_ecef_cov_gnss`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_vel_ecef_cov_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 53, 2, 0, 16, 42, 224, 229, 233, 29, 253, 255, 255, 255, 1, 0, 0, 0, 4, 0, 0, 0,
            46, 224, 32, 59, 32, 214, 14, 59, 150, 147, 220, 186, 19, 63, 138, 59, 26, 150, 35,
            187, 11, 193, 119, 59, 21, 2, 22, 230,
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
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefCovGnss(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefCovGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x235,
                    "Incorrect message type, expected 0x235, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(2.45476840063929558e-03),
                    "incorrect value for cov_x_x, expected 2.45476840063929558e-03, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(2.17951089143753052e-03),
                    "incorrect value for cov_x_y, expected 2.17951089143753052e-03, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(-1.68286520056426525e-03),
                    "incorrect value for cov_x_z, expected -1.68286520056426525e-03, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(4.21894481405615807e-03),
                    "incorrect value for cov_y_y, expected 4.21894481405615807e-03, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(-2.49612936750054359e-03),
                    "incorrect value for cov_y_z, expected -2.49612936750054359e-03, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(3.78042715601623058e-03),
                    "incorrect value for cov_z_z, expected 3.78042715601623058e-03, is {:e}",
                    msg.cov_z_z
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 21,
                    "incorrect value for n_sats, expected 21, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501868000,
                    "incorrect value for tow, expected 501868000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -3,
                    "incorrect value for x, expected -3, is {}",
                    msg.x
                );
                assert_eq!(msg.y, 1, "incorrect value for y, expected 1, is {}", msg.y);
                assert_eq!(msg.z, 4, "incorrect value for z, expected 4, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFCovGnss"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
