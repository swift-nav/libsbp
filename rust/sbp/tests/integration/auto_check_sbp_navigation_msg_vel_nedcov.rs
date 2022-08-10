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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNEDCOV.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_vel_nedcov() {
    {
        let mut payload = Cursor::new(vec![
            85, 18, 2, 66, 0, 42, 100, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 128, 63,
            0, 0, 128, 63, 0, 0, 128, 63, 0, 0, 128, 63, 0, 0, 128, 63, 0, 0, 128, 63, 10, 0, 88,
            205,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedCov(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x212,
                    "Incorrect message type, expected 0x212, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_d_d.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_d_d, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_d_d
                );
                assert!(
                    msg.cov_e_d.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_e_d, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_e_d
                );
                assert!(
                    msg.cov_e_e.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_e_e, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_e_e
                );
                assert!(
                    msg.cov_n_d.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_n_d, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_n_d
                );
                assert!(
                    msg.cov_n_e.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_n_e, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_n_e
                );
                assert!(
                    msg.cov_n_n.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_n_n, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_n_n
                );
                assert_eq!(msg.d, 1, "incorrect value for d, expected 1, is {}", msg.d);
                assert_eq!(msg.e, 1, "incorrect value for e, expected 1, is {}", msg.e);
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(msg.n, 1, "incorrect value for n, expected 1, is {}", msg.n);
                assert_eq!(
                    msg.n_sats, 10,
                    "incorrect value for n_sats, expected 10, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 100,
                    "incorrect value for tow, expected 100, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDCov"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_vel_nedcov() {
    {
        let json_input = r#"{"cov_e_d": 1, "cov_e_e": 1, "n_sats": 10, "sender": 66, "msg_type": 530, "cov_n_n": 1, "cov_n_e": 1, "tow": 100, "n": 1, "crc": 52568, "length": 42, "cov_n_d": 1, "flags": 0, "e": 1, "cov_d_d": 1, "preamble": 85, "payload": "ZAAAAAEAAAABAAAAAQAAAAAAgD8AAIA/AACAPwAAgD8AAIA/AACAPwoA", "d": 1}"#.as_bytes();

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
            sbp::messages::Sbp::MsgVelNedCov(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x212,
                    "Incorrect message type, expected 0x212, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_d_d.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_d_d, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_d_d
                );
                assert!(
                    msg.cov_e_d.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_e_d, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_e_d
                );
                assert!(
                    msg.cov_e_e.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_e_e, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_e_e
                );
                assert!(
                    msg.cov_n_d.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_n_d, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_n_d
                );
                assert!(
                    msg.cov_n_e.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_n_e, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_n_e
                );
                assert!(
                    msg.cov_n_n.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_n_n, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_n_n
                );
                assert_eq!(msg.d, 1, "incorrect value for d, expected 1, is {}", msg.d);
                assert_eq!(msg.e, 1, "incorrect value for e, expected 1, is {}", msg.e);
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(msg.n, 1, "incorrect value for n, expected 1, is {}", msg.n);
                assert_eq!(
                    msg.n_sats, 10,
                    "incorrect value for n_sats, expected 10, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 100,
                    "incorrect value for tow, expected 100, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDCov"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_vel_nedcov`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_vel_nedcov() {
    {
        let mut payload = Cursor::new(vec![
            85, 18, 2, 66, 0, 42, 100, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 128, 63,
            0, 0, 128, 63, 0, 0, 128, 63, 0, 0, 128, 63, 0, 0, 128, 63, 0, 0, 128, 63, 10, 0, 88,
            205,
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
        let sbp_msg = sbp::messages::Sbp::MsgVelNedCov(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedCov(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x212,
                    "Incorrect message type, expected 0x212, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_d_d.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_d_d, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_d_d
                );
                assert!(
                    msg.cov_e_d.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_e_d, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_e_d
                );
                assert!(
                    msg.cov_e_e.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_e_e, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_e_e
                );
                assert!(
                    msg.cov_n_d.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_n_d, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_n_d
                );
                assert!(
                    msg.cov_n_e.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_n_e, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_n_e
                );
                assert!(
                    msg.cov_n_n.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_n_n, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_n_n
                );
                assert_eq!(msg.d, 1, "incorrect value for d, expected 1, is {}", msg.d);
                assert_eq!(msg.e, 1, "incorrect value for e, expected 1, is {}", msg.e);
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(msg.n, 1, "incorrect value for n, expected 1, is {}", msg.n);
                assert_eq!(
                    msg.n_sats, 10,
                    "incorrect value for n_sats, expected 10, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 100,
                    "incorrect value for tow, expected 100, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDCov"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
