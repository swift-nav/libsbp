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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPoseRelative.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_pose_relative() {
    {
        let mut payload = Cursor::new(vec![
            85, 69, 2, 66, 0, 90, 86, 4, 0, 0, 0, 86, 4, 0, 0, 172, 8, 0, 0, 76, 4, 0, 0, 38, 2, 0,
            0, 100, 0, 0, 0, 100, 3, 200, 204, 252, 168, 157, 255, 115, 53, 186, 144, 190, 48, 34,
            37, 0, 0, 128, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 63, 0, 0, 0, 0, 0, 0, 128, 63, 0,
            0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 64, 5, 171, 187,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPoseRelative(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x245,
                    "Incorrect message type, expected 0x245, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {sender_id}"
                );
                assert!(
                    msg.cov_c_x_x.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_c_x_x, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_c_x_x
                );
                assert!(
                    msg.cov_c_x_y.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_c_x_y, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_c_x_y
                );
                assert!(
                    msg.cov_c_x_z.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_c_x_z, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_c_x_z
                );
                assert!(
                    msg.cov_c_y_y.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_c_y_y, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_c_y_y
                );
                assert!(
                    msg.cov_c_y_z.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_c_y_z, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_c_y_z
                );
                assert!(
                    msg.cov_c_z_z.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_c_z_z, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_c_z_z
                );
                assert!(
                    msg.cov_r_x_x.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_r_x_x, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_r_x_x
                );
                assert!(
                    msg.cov_r_x_y.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_r_x_y, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_r_x_y
                );
                assert!(
                    msg.cov_r_x_z.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_r_x_z, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_r_x_z
                );
                assert!(
                    msg.cov_r_y_y.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_r_y_y, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_r_y_y
                );
                assert!(
                    msg.cov_r_y_z.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_r_y_z, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_r_y_z
                );
                assert!(
                    msg.cov_r_z_z.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_r_z_z, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_r_z_z
                );
                assert_eq!(
                    msg.flags, 5,
                    "incorrect value for flags, expected 5, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.sensor_id, 0,
                    "incorrect value for sensor_id, expected 0, is {}",
                    msg.sensor_id
                );
                assert_eq!(
                    msg.timestamp_1, 1110,
                    "incorrect value for timestamp_1, expected 1110, is {}",
                    msg.timestamp_1
                );
                assert_eq!(
                    msg.timestamp_2, 2220,
                    "incorrect value for timestamp_2, expected 2220, is {}",
                    msg.timestamp_2
                );
                assert_eq!(
                    msg.tow, 1110,
                    "incorrect value for tow, expected 1110, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.trans[0], 1100,
                    "incorrect value for trans[0], expected 1100, is {}",
                    msg.trans[0]
                );
                assert_eq!(
                    msg.trans[1], 550,
                    "incorrect value for trans[1], expected 550, is {}",
                    msg.trans[1]
                );
                assert_eq!(
                    msg.trans[2], 100,
                    "incorrect value for trans[2], expected 100, is {}",
                    msg.trans[2]
                );
                assert_eq!(
                    msg.w, -859307164,
                    "incorrect value for w, expected -859307164, is {}",
                    msg.w
                );
                assert_eq!(
                    msg.x, -6444804,
                    "incorrect value for x, expected -6444804, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -1866844813,
                    "incorrect value for y, expected -1866844813, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 622997694,
                    "incorrect value for z, expected 622997694, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPoseRelative"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_pose_relative() {
    {
        let json_input = r#"{"preamble": 85, "msg_type": 581, "sender": 66, "length": 90, "payload": "VgQAAABWBAAArAgAAEwEAAAmAgAAZAAAAGQDyMz8qJ3/czW6kL4wIiUAAIA/AAAAAAAAAAAAAIA/AAAAAAAAgD8AAABAAAAAAAAAAAAAAABAAAAAAAAAAEAF", "crc": 48043, "tow": 1110, "sensor_id": 0, "timestamp_1": 1110, "timestamp_2": 2220, "trans": [1100, 550, 100], "w": -859307164, "x": -6444804, "y": -1866844813, "z": 622997694, "cov_r_x_x": 1.0, "cov_r_x_y": 0.0, "cov_r_x_z": 0.0, "cov_r_y_y": 1.0, "cov_r_y_z": 0.0, "cov_r_z_z": 1.0, "cov_c_x_x": 2.0, "cov_c_x_y": 0.0, "cov_c_x_z": 0.0, "cov_c_y_y": 2.0, "cov_c_y_z": 0.0, "cov_c_z_z": 2.0, "flags": 5}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPoseRelative(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x245,
                    "Incorrect message type, expected 0x245, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {sender_id}"
                );
                assert!(
                    msg.cov_c_x_x.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_c_x_x, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_c_x_x
                );
                assert!(
                    msg.cov_c_x_y.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_c_x_y, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_c_x_y
                );
                assert!(
                    msg.cov_c_x_z.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_c_x_z, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_c_x_z
                );
                assert!(
                    msg.cov_c_y_y.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_c_y_y, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_c_y_y
                );
                assert!(
                    msg.cov_c_y_z.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_c_y_z, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_c_y_z
                );
                assert!(
                    msg.cov_c_z_z.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_c_z_z, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_c_z_z
                );
                assert!(
                    msg.cov_r_x_x.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_r_x_x, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_r_x_x
                );
                assert!(
                    msg.cov_r_x_y.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_r_x_y, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_r_x_y
                );
                assert!(
                    msg.cov_r_x_z.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_r_x_z, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_r_x_z
                );
                assert!(
                    msg.cov_r_y_y.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_r_y_y, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_r_y_y
                );
                assert!(
                    msg.cov_r_y_z.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_r_y_z, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_r_y_z
                );
                assert!(
                    msg.cov_r_z_z.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_r_z_z, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_r_z_z
                );
                assert_eq!(
                    msg.flags, 5,
                    "incorrect value for flags, expected 5, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.sensor_id, 0,
                    "incorrect value for sensor_id, expected 0, is {}",
                    msg.sensor_id
                );
                assert_eq!(
                    msg.timestamp_1, 1110,
                    "incorrect value for timestamp_1, expected 1110, is {}",
                    msg.timestamp_1
                );
                assert_eq!(
                    msg.timestamp_2, 2220,
                    "incorrect value for timestamp_2, expected 2220, is {}",
                    msg.timestamp_2
                );
                assert_eq!(
                    msg.tow, 1110,
                    "incorrect value for tow, expected 1110, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.trans[0], 1100,
                    "incorrect value for trans[0], expected 1100, is {}",
                    msg.trans[0]
                );
                assert_eq!(
                    msg.trans[1], 550,
                    "incorrect value for trans[1], expected 550, is {}",
                    msg.trans[1]
                );
                assert_eq!(
                    msg.trans[2], 100,
                    "incorrect value for trans[2], expected 100, is {}",
                    msg.trans[2]
                );
                assert_eq!(
                    msg.w, -859307164,
                    "incorrect value for w, expected -859307164, is {}",
                    msg.w
                );
                assert_eq!(
                    msg.x, -6444804,
                    "incorrect value for x, expected -6444804, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -1866844813,
                    "incorrect value for y, expected -1866844813, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 622997694,
                    "incorrect value for z, expected 622997694, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPoseRelative"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_pose_relative`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_pose_relative() {
    {
        let mut payload = Cursor::new(vec![
            85, 69, 2, 66, 0, 90, 86, 4, 0, 0, 0, 86, 4, 0, 0, 172, 8, 0, 0, 76, 4, 0, 0, 38, 2, 0,
            0, 100, 0, 0, 0, 100, 3, 200, 204, 252, 168, 157, 255, 115, 53, 186, 144, 190, 48, 34,
            37, 0, 0, 128, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 63, 0, 0, 0, 0, 0, 0, 128, 63, 0,
            0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 64, 5, 171, 187,
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
        let sbp_msg = sbp::messages::Sbp::MsgPoseRelative(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPoseRelative(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x245,
                    "Incorrect message type, expected 0x245, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {sender_id}"
                );
                assert!(
                    msg.cov_c_x_x.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_c_x_x, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_c_x_x
                );
                assert!(
                    msg.cov_c_x_y.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_c_x_y, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_c_x_y
                );
                assert!(
                    msg.cov_c_x_z.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_c_x_z, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_c_x_z
                );
                assert!(
                    msg.cov_c_y_y.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_c_y_y, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_c_y_y
                );
                assert!(
                    msg.cov_c_y_z.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_c_y_z, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_c_y_z
                );
                assert!(
                    msg.cov_c_z_z.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_c_z_z, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_c_z_z
                );
                assert!(
                    msg.cov_r_x_x.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_r_x_x, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_r_x_x
                );
                assert!(
                    msg.cov_r_x_y.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_r_x_y, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_r_x_y
                );
                assert!(
                    msg.cov_r_x_z.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_r_x_z, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_r_x_z
                );
                assert!(
                    msg.cov_r_y_y.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_r_y_y, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_r_y_y
                );
                assert!(
                    msg.cov_r_y_z.almost_eq(0.00000000000000000e+00),
                    "incorrect value for cov_r_y_z, expected 0.00000000000000000e+00, is {:e}",
                    msg.cov_r_y_z
                );
                assert!(
                    msg.cov_r_z_z.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_r_z_z, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_r_z_z
                );
                assert_eq!(
                    msg.flags, 5,
                    "incorrect value for flags, expected 5, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.sensor_id, 0,
                    "incorrect value for sensor_id, expected 0, is {}",
                    msg.sensor_id
                );
                assert_eq!(
                    msg.timestamp_1, 1110,
                    "incorrect value for timestamp_1, expected 1110, is {}",
                    msg.timestamp_1
                );
                assert_eq!(
                    msg.timestamp_2, 2220,
                    "incorrect value for timestamp_2, expected 2220, is {}",
                    msg.timestamp_2
                );
                assert_eq!(
                    msg.tow, 1110,
                    "incorrect value for tow, expected 1110, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.trans[0], 1100,
                    "incorrect value for trans[0], expected 1100, is {}",
                    msg.trans[0]
                );
                assert_eq!(
                    msg.trans[1], 550,
                    "incorrect value for trans[1], expected 550, is {}",
                    msg.trans[1]
                );
                assert_eq!(
                    msg.trans[2], 100,
                    "incorrect value for trans[2], expected 100, is {}",
                    msg.trans[2]
                );
                assert_eq!(
                    msg.w, -859307164,
                    "incorrect value for w, expected -859307164, is {}",
                    msg.w
                );
                assert_eq!(
                    msg.x, -6444804,
                    "incorrect value for x, expected -6444804, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -1866844813,
                    "incorrect value for y, expected -1866844813, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 622997694,
                    "incorrect value for z, expected 622997694, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPoseRelative"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
