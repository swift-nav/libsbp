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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/telemetry/test_MsgTelSv.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_telemetry_msg_tel_sv() {
    {
        let mut payload = Cursor::new(vec![
            85, 32, 1, 148, 38, 20, 175, 8, 208, 221, 62, 24, 16, 1, 40, 50, 5, 226, 255, 1, 0, 1,
            1, 1, 33, 12, 39, 105,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTelSv(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x120,
                    "Incorrect message type, expected 0x120, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2694,
                    "incorrect sender id, expected 0x2694, is {sender_id}"
                );
                assert_eq!(
                    msg.n_obs, 16,
                    "incorrect value for n_obs, expected 16, is {}",
                    msg.n_obs
                );
                assert_eq!(
                    msg.origin_flags, 1,
                    "incorrect value for origin_flags, expected 1, is {}",
                    msg.origin_flags
                );
                assert_eq!(
                    msg.sv_tel[0].availability_flags, 5,
                    "incorrect value for sv_tel[0].availability_flags, expected 5, is {}",
                    msg.sv_tel[0].availability_flags
                );
                assert_eq!(
                    msg.sv_tel[0].az, 40,
                    "incorrect value for sv_tel[0].az, expected 40, is {}",
                    msg.sv_tel[0].az
                );
                assert_eq!(
                    msg.sv_tel[0].correction_flags, 1,
                    "incorrect value for sv_tel[0].correction_flags, expected 1, is {}",
                    msg.sv_tel[0].correction_flags
                );
                assert_eq!(
                    msg.sv_tel[0].el, 50,
                    "incorrect value for sv_tel[0].el, expected 50, is {}",
                    msg.sv_tel[0].el
                );
                assert_eq!(
                    msg.sv_tel[0].ephemeris_flags, 1,
                    "incorrect value for sv_tel[0].ephemeris_flags, expected 1, is {}",
                    msg.sv_tel[0].ephemeris_flags
                );
                assert_eq!(
                    msg.sv_tel[0].outlier_flags, 1,
                    "incorrect value for sv_tel[0].outlier_flags, expected 1, is {}",
                    msg.sv_tel[0].outlier_flags
                );
                assert_eq!(
                    msg.sv_tel[0].phase_residual, 1,
                    "incorrect value for sv_tel[0].phase_residual, expected 1, is {}",
                    msg.sv_tel[0].phase_residual
                );
                assert_eq!(
                    msg.sv_tel[0].pseudorange_residual, -30,
                    "incorrect value for sv_tel[0].pseudorange_residual, expected -30, is {}",
                    msg.sv_tel[0].pseudorange_residual
                );
                assert_eq!(
                    msg.sv_tel[0].sid.code, 12,
                    "incorrect value for sv_tel[0].sid.code, expected 12, is {}",
                    msg.sv_tel[0].sid.code
                );
                assert_eq!(
                    msg.sv_tel[0].sid.sat, 33,
                    "incorrect value for sv_tel[0].sid.sat, expected 33, is {}",
                    msg.sv_tel[0].sid.sat
                );
                assert_eq!(
                    msg.tow, 406773200,
                    "incorrect value for tow, expected 406773200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 2223,
                    "incorrect value for wn, expected 2223, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTelSv"),
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
fn test_json2sbp_auto_check_sbp_telemetry_msg_tel_sv() {
    {
        let json_input = r#"{"preamble": 85, "msg_type": 288, "sender": 9876, "length": 20, "payload": "rwjQ3T4YEAEoMgXi/wEAAQEBIQw=", "crc": 26919, "wn": 2223, "tow": 406773200, "n_obs": 16, "origin_flags": 1, "sv_tel": [{"az": 40, "el": 50, "availability_flags": 5, "pseudorange_residual": -30, "phase_residual": 1, "outlier_flags": 1, "ephemeris_flags": 1, "correction_flags": 1, "sid": {"sat": 33, "code": 12}}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTelSv(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x120,
                    "Incorrect message type, expected 0x120, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2694,
                    "incorrect sender id, expected 0x2694, is {sender_id}"
                );
                assert_eq!(
                    msg.n_obs, 16,
                    "incorrect value for n_obs, expected 16, is {}",
                    msg.n_obs
                );
                assert_eq!(
                    msg.origin_flags, 1,
                    "incorrect value for origin_flags, expected 1, is {}",
                    msg.origin_flags
                );
                assert_eq!(
                    msg.sv_tel[0].availability_flags, 5,
                    "incorrect value for sv_tel[0].availability_flags, expected 5, is {}",
                    msg.sv_tel[0].availability_flags
                );
                assert_eq!(
                    msg.sv_tel[0].az, 40,
                    "incorrect value for sv_tel[0].az, expected 40, is {}",
                    msg.sv_tel[0].az
                );
                assert_eq!(
                    msg.sv_tel[0].correction_flags, 1,
                    "incorrect value for sv_tel[0].correction_flags, expected 1, is {}",
                    msg.sv_tel[0].correction_flags
                );
                assert_eq!(
                    msg.sv_tel[0].el, 50,
                    "incorrect value for sv_tel[0].el, expected 50, is {}",
                    msg.sv_tel[0].el
                );
                assert_eq!(
                    msg.sv_tel[0].ephemeris_flags, 1,
                    "incorrect value for sv_tel[0].ephemeris_flags, expected 1, is {}",
                    msg.sv_tel[0].ephemeris_flags
                );
                assert_eq!(
                    msg.sv_tel[0].outlier_flags, 1,
                    "incorrect value for sv_tel[0].outlier_flags, expected 1, is {}",
                    msg.sv_tel[0].outlier_flags
                );
                assert_eq!(
                    msg.sv_tel[0].phase_residual, 1,
                    "incorrect value for sv_tel[0].phase_residual, expected 1, is {}",
                    msg.sv_tel[0].phase_residual
                );
                assert_eq!(
                    msg.sv_tel[0].pseudorange_residual, -30,
                    "incorrect value for sv_tel[0].pseudorange_residual, expected -30, is {}",
                    msg.sv_tel[0].pseudorange_residual
                );
                assert_eq!(
                    msg.sv_tel[0].sid.code, 12,
                    "incorrect value for sv_tel[0].sid.code, expected 12, is {}",
                    msg.sv_tel[0].sid.code
                );
                assert_eq!(
                    msg.sv_tel[0].sid.sat, 33,
                    "incorrect value for sv_tel[0].sid.sat, expected 33, is {}",
                    msg.sv_tel[0].sid.sat
                );
                assert_eq!(
                    msg.tow, 406773200,
                    "incorrect value for tow, expected 406773200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 2223,
                    "incorrect value for wn, expected 2223, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTelSv"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_telemetry_msg_tel_sv`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_telemetry_msg_tel_sv() {
    {
        let mut payload = Cursor::new(vec![
            85, 32, 1, 148, 38, 20, 175, 8, 208, 221, 62, 24, 16, 1, 40, 50, 5, 226, 255, 1, 0, 1,
            1, 1, 33, 12, 39, 105,
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
        let sbp_msg = sbp::messages::Sbp::MsgTelSv(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTelSv(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x120,
                    "Incorrect message type, expected 0x120, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2694,
                    "incorrect sender id, expected 0x2694, is {sender_id}"
                );
                assert_eq!(
                    msg.n_obs, 16,
                    "incorrect value for n_obs, expected 16, is {}",
                    msg.n_obs
                );
                assert_eq!(
                    msg.origin_flags, 1,
                    "incorrect value for origin_flags, expected 1, is {}",
                    msg.origin_flags
                );
                assert_eq!(
                    msg.sv_tel[0].availability_flags, 5,
                    "incorrect value for sv_tel[0].availability_flags, expected 5, is {}",
                    msg.sv_tel[0].availability_flags
                );
                assert_eq!(
                    msg.sv_tel[0].az, 40,
                    "incorrect value for sv_tel[0].az, expected 40, is {}",
                    msg.sv_tel[0].az
                );
                assert_eq!(
                    msg.sv_tel[0].correction_flags, 1,
                    "incorrect value for sv_tel[0].correction_flags, expected 1, is {}",
                    msg.sv_tel[0].correction_flags
                );
                assert_eq!(
                    msg.sv_tel[0].el, 50,
                    "incorrect value for sv_tel[0].el, expected 50, is {}",
                    msg.sv_tel[0].el
                );
                assert_eq!(
                    msg.sv_tel[0].ephemeris_flags, 1,
                    "incorrect value for sv_tel[0].ephemeris_flags, expected 1, is {}",
                    msg.sv_tel[0].ephemeris_flags
                );
                assert_eq!(
                    msg.sv_tel[0].outlier_flags, 1,
                    "incorrect value for sv_tel[0].outlier_flags, expected 1, is {}",
                    msg.sv_tel[0].outlier_flags
                );
                assert_eq!(
                    msg.sv_tel[0].phase_residual, 1,
                    "incorrect value for sv_tel[0].phase_residual, expected 1, is {}",
                    msg.sv_tel[0].phase_residual
                );
                assert_eq!(
                    msg.sv_tel[0].pseudorange_residual, -30,
                    "incorrect value for sv_tel[0].pseudorange_residual, expected -30, is {}",
                    msg.sv_tel[0].pseudorange_residual
                );
                assert_eq!(
                    msg.sv_tel[0].sid.code, 12,
                    "incorrect value for sv_tel[0].sid.code, expected 12, is {}",
                    msg.sv_tel[0].sid.code
                );
                assert_eq!(
                    msg.sv_tel[0].sid.sat, 33,
                    "incorrect value for sv_tel[0].sid.sat, expected 33, is {}",
                    msg.sv_tel[0].sid.sat
                );
                assert_eq!(
                    msg.tow, 406773200,
                    "incorrect value for tow, expected 406773200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 2223,
                    "incorrect value for wn, expected 2223, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTelSv"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
