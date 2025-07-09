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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgReferenceFrameParam.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_reference_frame_param() {
    {
        let mut payload = Cursor::new(vec![
            85, 68, 2, 66, 0, 124, 1, 102, 111, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98, 97, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 0, 6, 0, 7, 0, 0, 0, 8, 0,
            0, 0, 9, 0, 0, 0, 10, 0, 0, 0, 11, 0, 0, 0, 12, 0, 0, 0, 13, 0, 0, 0, 14, 0, 0, 0, 15,
            0, 0, 0, 16, 0, 0, 0, 17, 0, 0, 0, 18, 0, 0, 0, 19, 0, 0, 0, 20, 0, 6, 161,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgReferenceFrameParam(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 580,
                    "Incorrect message type, expected 580, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {sender_id}"
                );
                assert_eq!(
                    msg.delta_x0, 7,
                    "incorrect value for delta_x0, expected 7, is {}",
                    msg.delta_x0
                );
                assert_eq!(
                    msg.delta_y0, 8,
                    "incorrect value for delta_y0, expected 8, is {}",
                    msg.delta_y0
                );
                assert_eq!(
                    msg.delta_z0, 9,
                    "incorrect value for delta_z0, expected 9, is {}",
                    msg.delta_z0
                );
                assert_eq!(
                    msg.dot_delta_x0, 14,
                    "incorrect value for dot_delta_x0, expected 14, is {}",
                    msg.dot_delta_x0
                );
                assert_eq!(
                    msg.dot_delta_y0, 15,
                    "incorrect value for dot_delta_y0, expected 15, is {}",
                    msg.dot_delta_y0
                );
                assert_eq!(
                    msg.dot_delta_z0, 16,
                    "incorrect value for dot_delta_z0, expected 16, is {}",
                    msg.dot_delta_z0
                );
                assert_eq!(
                    msg.dot_scale, 20,
                    "incorrect value for dot_scale, expected 20, is {}",
                    msg.dot_scale
                );
                assert_eq!(
                    msg.dot_theta_01, 17,
                    "incorrect value for dot_theta_01, expected 17, is {}",
                    msg.dot_theta_01
                );
                assert_eq!(
                    msg.dot_theta_02, 18,
                    "incorrect value for dot_theta_02, expected 18, is {}",
                    msg.dot_theta_02
                );
                assert_eq!(
                    msg.dot_theta_03, 19,
                    "incorrect value for dot_theta_03, expected 19, is {}",
                    msg.dot_theta_03
                );
                assert_eq!(
                    msg.re_t0, 6,
                    "incorrect value for re_t0, expected 6, is {}",
                    msg.re_t0
                );
                assert_eq!(
                    msg.scale, 13,
                    "incorrect value for scale, expected 13, is {}",
                    msg.scale
                );
                assert_eq!(
                    msg.sin, 4,
                    "incorrect value for sin, expected 4, is {}",
                    msg.sin
                );
                assert_eq!(
                    msg.sn.as_bytes(),
                    &[
                        102, 111, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    "incorrect value for msg.sn, expected string '{:?}', is '{:?}'",
                    &[
                        102, 111, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    msg.sn.as_bytes()
                );
                assert_eq!(
                    msg.ssr_iod, 1,
                    "incorrect value for ssr_iod, expected 1, is {}",
                    msg.ssr_iod
                );
                assert_eq!(
                    msg.theta_01, 10,
                    "incorrect value for theta_01, expected 10, is {}",
                    msg.theta_01
                );
                assert_eq!(
                    msg.theta_02, 11,
                    "incorrect value for theta_02, expected 11, is {}",
                    msg.theta_02
                );
                assert_eq!(
                    msg.theta_03, 12,
                    "incorrect value for theta_03, expected 12, is {}",
                    msg.theta_03
                );
                assert_eq!(
                    msg.tn.as_bytes(),
                    &[
                        98, 97, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    "incorrect value for msg.tn, expected string '{:?}', is '{:?}'",
                    &[
                        98, 97, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    msg.tn.as_bytes()
                );
                assert_eq!(
                    msg.utn, 5,
                    "incorrect value for utn, expected 5, is {}",
                    msg.utn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgReferenceFrameParam"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_reference_frame_param() {
    {
        let json_input = r#"{"ssr_iod": 1, "sn": "foo\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000", "tn": "bar\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000", "sin": 4, "utn": 5, "re_t0": 6, "delta_X0": 7, "delta_Y0": 8, "delta_Z0": 9, "theta_01": 10, "theta_02": 11, "theta_03": 12, "scale": 13, "dot_delta_X0": 14, "dot_delta_Y0": 15, "dot_delta_Z0": 16, "dot_theta_01": 17, "dot_theta_02": 18, "dot_theta_03": 19, "dot_scale": 20, "preamble": 85, "msg_type": 580, "sender": 66, "length": 124, "payload": "AWZvbwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYmFyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEBQAGAAcAAAAIAAAACQAAAAoAAAALAAAADAAAAA0AAAAOAAAADwAAABAAAAARAAAAEgAAABMAAAAUAA==", "crc": 41222}"#.as_bytes();

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
            sbp::messages::Sbp::MsgReferenceFrameParam(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 580,
                    "Incorrect message type, expected 580, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {sender_id}"
                );
                assert_eq!(
                    msg.delta_x0, 7,
                    "incorrect value for delta_x0, expected 7, is {}",
                    msg.delta_x0
                );
                assert_eq!(
                    msg.delta_y0, 8,
                    "incorrect value for delta_y0, expected 8, is {}",
                    msg.delta_y0
                );
                assert_eq!(
                    msg.delta_z0, 9,
                    "incorrect value for delta_z0, expected 9, is {}",
                    msg.delta_z0
                );
                assert_eq!(
                    msg.dot_delta_x0, 14,
                    "incorrect value for dot_delta_x0, expected 14, is {}",
                    msg.dot_delta_x0
                );
                assert_eq!(
                    msg.dot_delta_y0, 15,
                    "incorrect value for dot_delta_y0, expected 15, is {}",
                    msg.dot_delta_y0
                );
                assert_eq!(
                    msg.dot_delta_z0, 16,
                    "incorrect value for dot_delta_z0, expected 16, is {}",
                    msg.dot_delta_z0
                );
                assert_eq!(
                    msg.dot_scale, 20,
                    "incorrect value for dot_scale, expected 20, is {}",
                    msg.dot_scale
                );
                assert_eq!(
                    msg.dot_theta_01, 17,
                    "incorrect value for dot_theta_01, expected 17, is {}",
                    msg.dot_theta_01
                );
                assert_eq!(
                    msg.dot_theta_02, 18,
                    "incorrect value for dot_theta_02, expected 18, is {}",
                    msg.dot_theta_02
                );
                assert_eq!(
                    msg.dot_theta_03, 19,
                    "incorrect value for dot_theta_03, expected 19, is {}",
                    msg.dot_theta_03
                );
                assert_eq!(
                    msg.re_t0, 6,
                    "incorrect value for re_t0, expected 6, is {}",
                    msg.re_t0
                );
                assert_eq!(
                    msg.scale, 13,
                    "incorrect value for scale, expected 13, is {}",
                    msg.scale
                );
                assert_eq!(
                    msg.sin, 4,
                    "incorrect value for sin, expected 4, is {}",
                    msg.sin
                );
                assert_eq!(
                    msg.sn.as_bytes(),
                    &[
                        102, 111, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    "incorrect value for msg.sn, expected string '{:?}', is '{:?}'",
                    &[
                        102, 111, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    msg.sn.as_bytes()
                );
                assert_eq!(
                    msg.ssr_iod, 1,
                    "incorrect value for ssr_iod, expected 1, is {}",
                    msg.ssr_iod
                );
                assert_eq!(
                    msg.theta_01, 10,
                    "incorrect value for theta_01, expected 10, is {}",
                    msg.theta_01
                );
                assert_eq!(
                    msg.theta_02, 11,
                    "incorrect value for theta_02, expected 11, is {}",
                    msg.theta_02
                );
                assert_eq!(
                    msg.theta_03, 12,
                    "incorrect value for theta_03, expected 12, is {}",
                    msg.theta_03
                );
                assert_eq!(
                    msg.tn.as_bytes(),
                    &[
                        98, 97, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    "incorrect value for msg.tn, expected string '{:?}', is '{:?}'",
                    &[
                        98, 97, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    msg.tn.as_bytes()
                );
                assert_eq!(
                    msg.utn, 5,
                    "incorrect value for utn, expected 5, is {}",
                    msg.utn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgReferenceFrameParam"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_reference_frame_param`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_reference_frame_param() {
    {
        let mut payload = Cursor::new(vec![
            85, 68, 2, 66, 0, 124, 1, 102, 111, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98, 97, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 0, 6, 0, 7, 0, 0, 0, 8, 0,
            0, 0, 9, 0, 0, 0, 10, 0, 0, 0, 11, 0, 0, 0, 12, 0, 0, 0, 13, 0, 0, 0, 14, 0, 0, 0, 15,
            0, 0, 0, 16, 0, 0, 0, 17, 0, 0, 0, 18, 0, 0, 0, 19, 0, 0, 0, 20, 0, 6, 161,
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
        let sbp_msg = sbp::messages::Sbp::MsgReferenceFrameParam(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgReferenceFrameParam(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 580,
                    "Incorrect message type, expected 580, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {sender_id}"
                );
                assert_eq!(
                    msg.delta_x0, 7,
                    "incorrect value for delta_x0, expected 7, is {}",
                    msg.delta_x0
                );
                assert_eq!(
                    msg.delta_y0, 8,
                    "incorrect value for delta_y0, expected 8, is {}",
                    msg.delta_y0
                );
                assert_eq!(
                    msg.delta_z0, 9,
                    "incorrect value for delta_z0, expected 9, is {}",
                    msg.delta_z0
                );
                assert_eq!(
                    msg.dot_delta_x0, 14,
                    "incorrect value for dot_delta_x0, expected 14, is {}",
                    msg.dot_delta_x0
                );
                assert_eq!(
                    msg.dot_delta_y0, 15,
                    "incorrect value for dot_delta_y0, expected 15, is {}",
                    msg.dot_delta_y0
                );
                assert_eq!(
                    msg.dot_delta_z0, 16,
                    "incorrect value for dot_delta_z0, expected 16, is {}",
                    msg.dot_delta_z0
                );
                assert_eq!(
                    msg.dot_scale, 20,
                    "incorrect value for dot_scale, expected 20, is {}",
                    msg.dot_scale
                );
                assert_eq!(
                    msg.dot_theta_01, 17,
                    "incorrect value for dot_theta_01, expected 17, is {}",
                    msg.dot_theta_01
                );
                assert_eq!(
                    msg.dot_theta_02, 18,
                    "incorrect value for dot_theta_02, expected 18, is {}",
                    msg.dot_theta_02
                );
                assert_eq!(
                    msg.dot_theta_03, 19,
                    "incorrect value for dot_theta_03, expected 19, is {}",
                    msg.dot_theta_03
                );
                assert_eq!(
                    msg.re_t0, 6,
                    "incorrect value for re_t0, expected 6, is {}",
                    msg.re_t0
                );
                assert_eq!(
                    msg.scale, 13,
                    "incorrect value for scale, expected 13, is {}",
                    msg.scale
                );
                assert_eq!(
                    msg.sin, 4,
                    "incorrect value for sin, expected 4, is {}",
                    msg.sin
                );
                assert_eq!(
                    msg.sn.as_bytes(),
                    &[
                        102, 111, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    "incorrect value for msg.sn, expected string '{:?}', is '{:?}'",
                    &[
                        102, 111, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    msg.sn.as_bytes()
                );
                assert_eq!(
                    msg.ssr_iod, 1,
                    "incorrect value for ssr_iod, expected 1, is {}",
                    msg.ssr_iod
                );
                assert_eq!(
                    msg.theta_01, 10,
                    "incorrect value for theta_01, expected 10, is {}",
                    msg.theta_01
                );
                assert_eq!(
                    msg.theta_02, 11,
                    "incorrect value for theta_02, expected 11, is {}",
                    msg.theta_02
                );
                assert_eq!(
                    msg.theta_03, 12,
                    "incorrect value for theta_03, expected 12, is {}",
                    msg.theta_03
                );
                assert_eq!(
                    msg.tn.as_bytes(),
                    &[
                        98, 97, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    "incorrect value for msg.tn, expected string '{:?}', is '{:?}'",
                    &[
                        98, 97, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0
                    ],
                    msg.tn.as_bytes()
                );
                assert_eq!(
                    msg.utn, 5,
                    "incorrect value for utn, expected 5, is {}",
                    msg.utn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgReferenceFrameParam"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
