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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgAlmanacGLO.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_almanac_glo() {
    {
        let mut payload = Cursor::new(vec![
            85, 115, 0, 195, 4, 78, 22, 0, 176, 207, 6, 0, 106, 8, 154, 153, 153, 153, 153, 153, 1,
            64, 64, 56, 0, 0, 1, 0, 142, 41, 5, 235, 95, 135, 150, 191, 0, 0, 0, 32, 191, 247, 124,
            63, 0, 0, 192, 206, 140, 33, 180, 64, 41, 131, 179, 134, 141, 248, 253, 191, 227, 133,
            81, 54, 204, 30, 67, 190, 216, 59, 199, 39, 96, 168, 239, 191, 71, 11, 217, 147, 145,
            228, 237, 63, 155, 87,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAlmanacGlo(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x73,
                    "Incorrect message type, expected 0x73, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.common.fit_interval, 14400,
                    "incorrect value for common.fit_interval, expected 14400, is {}",
                    msg.common.fit_interval
                );
                assert_eq!(
                    msg.common.health_bits, 0,
                    "incorrect value for common.health_bits, expected 0, is {}",
                    msg.common.health_bits
                );
                assert_eq!(
                    msg.common.sid.code, 0,
                    "incorrect value for common.sid.code, expected 0, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 22,
                    "incorrect value for common.sid.sat, expected 22, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toa.tow, 446384,
                    "incorrect value for common.toa.tow, expected 446384, is {}",
                    msg.common.toa.tow
                );
                assert_eq!(
                    msg.common.toa.wn, 2154,
                    "incorrect value for common.toa.wn, expected 2154, is {}",
                    msg.common.toa.wn
                );
                assert!(
                    msg.common.ura.almost_eq(2.20000000000000018e+00),
                    "incorrect value for common.ura, expected 2.20000000000000018e+00, is {:e}",
                    msg.common.ura
                );
                assert_eq!(
                    msg.common.valid, 1,
                    "incorrect value for common.valid, expected 1, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.epsilon.almost_eq(-9.89303662959964747e-01),
                    "incorrect value for epsilon, expected -9.89303662959964747e-01, is {:e}",
                    msg.epsilon
                );
                assert!(
                    msg.i.almost_eq(5.15355002975463867e+03),
                    "incorrect value for i, expected 5.15355002975463867e+03, is {:e}",
                    msg.i
                );
                assert!(
                    msg.lambda_na.almost_eq(-2.20007884211468815e-02),
                    "incorrect value for lambda_na, expected -2.20007884211468815e-02, is {:e}",
                    msg.lambda_na
                );
                assert!(
                    msg.omega.almost_eq(9.34151448025979714e-01),
                    "incorrect value for omega, expected 9.34151448025979714e-01, is {:e}",
                    msg.omega
                );
                assert!(
                    msg.t.almost_eq(-1.87318184487976169e+00),
                    "incorrect value for t, expected -1.87318184487976169e+00, is {:e}",
                    msg.t
                );
                assert!(
                    msg.t_dot.almost_eq(-8.90358515577419627e-09),
                    "incorrect value for t_dot, expected -8.90358515577419627e-09, is {:e}",
                    msg.t_dot
                );
                assert!(
                    msg.t_lambda_na.almost_eq(7.07220705226063728e-03),
                    "incorrect value for t_lambda_na, expected 7.07220705226063728e-03, is {:e}",
                    msg.t_lambda_na
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAlmanacGlo"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_almanac_glo() {
    {
        let json_input = r#"{"preamble":85,"msg_type":115,"sender":1219,"length":78,"payload":"FgCwzwYAagiamZmZmZkBQEA4AAABAI4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/","crc":22427,"common":{"sid":{"sat":22,"code":0},"toa":{"tow":446384,"wn":2154},"ura":2.2,"fit_interval":14400,"valid":1,"health_bits":0},"lambda_na":-0.02200078842114688,"t_lambda_na":0.007072207052260637,"i":5153.550029754639,"t":-1.8731818448797617,"t_dot":-8.903585155774196e-09,"epsilon":-0.9893036629599647,"omega":0.9341514480259797}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAlmanacGlo(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x73,
                    "Incorrect message type, expected 0x73, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.common.fit_interval, 14400,
                    "incorrect value for common.fit_interval, expected 14400, is {}",
                    msg.common.fit_interval
                );
                assert_eq!(
                    msg.common.health_bits, 0,
                    "incorrect value for common.health_bits, expected 0, is {}",
                    msg.common.health_bits
                );
                assert_eq!(
                    msg.common.sid.code, 0,
                    "incorrect value for common.sid.code, expected 0, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 22,
                    "incorrect value for common.sid.sat, expected 22, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toa.tow, 446384,
                    "incorrect value for common.toa.tow, expected 446384, is {}",
                    msg.common.toa.tow
                );
                assert_eq!(
                    msg.common.toa.wn, 2154,
                    "incorrect value for common.toa.wn, expected 2154, is {}",
                    msg.common.toa.wn
                );
                assert!(
                    msg.common.ura.almost_eq(2.20000000000000018e+00),
                    "incorrect value for common.ura, expected 2.20000000000000018e+00, is {:e}",
                    msg.common.ura
                );
                assert_eq!(
                    msg.common.valid, 1,
                    "incorrect value for common.valid, expected 1, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.epsilon.almost_eq(-9.89303662959964747e-01),
                    "incorrect value for epsilon, expected -9.89303662959964747e-01, is {:e}",
                    msg.epsilon
                );
                assert!(
                    msg.i.almost_eq(5.15355002975463867e+03),
                    "incorrect value for i, expected 5.15355002975463867e+03, is {:e}",
                    msg.i
                );
                assert!(
                    msg.lambda_na.almost_eq(-2.20007884211468815e-02),
                    "incorrect value for lambda_na, expected -2.20007884211468815e-02, is {:e}",
                    msg.lambda_na
                );
                assert!(
                    msg.omega.almost_eq(9.34151448025979714e-01),
                    "incorrect value for omega, expected 9.34151448025979714e-01, is {:e}",
                    msg.omega
                );
                assert!(
                    msg.t.almost_eq(-1.87318184487976169e+00),
                    "incorrect value for t, expected -1.87318184487976169e+00, is {:e}",
                    msg.t
                );
                assert!(
                    msg.t_dot.almost_eq(-8.90358515577419627e-09),
                    "incorrect value for t_dot, expected -8.90358515577419627e-09, is {:e}",
                    msg.t_dot
                );
                assert!(
                    msg.t_lambda_na.almost_eq(7.07220705226063728e-03),
                    "incorrect value for t_lambda_na, expected 7.07220705226063728e-03, is {:e}",
                    msg.t_lambda_na
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAlmanacGlo"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_almanac_glo`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_almanac_glo() {
    {
        let mut payload = Cursor::new(vec![
            85, 115, 0, 195, 4, 78, 22, 0, 176, 207, 6, 0, 106, 8, 154, 153, 153, 153, 153, 153, 1,
            64, 64, 56, 0, 0, 1, 0, 142, 41, 5, 235, 95, 135, 150, 191, 0, 0, 0, 32, 191, 247, 124,
            63, 0, 0, 192, 206, 140, 33, 180, 64, 41, 131, 179, 134, 141, 248, 253, 191, 227, 133,
            81, 54, 204, 30, 67, 190, 216, 59, 199, 39, 96, 168, 239, 191, 71, 11, 217, 147, 145,
            228, 237, 63, 155, 87,
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
        let sbp_msg = sbp::messages::Sbp::MsgAlmanacGlo(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAlmanacGlo(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x73,
                    "Incorrect message type, expected 0x73, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.common.fit_interval, 14400,
                    "incorrect value for common.fit_interval, expected 14400, is {}",
                    msg.common.fit_interval
                );
                assert_eq!(
                    msg.common.health_bits, 0,
                    "incorrect value for common.health_bits, expected 0, is {}",
                    msg.common.health_bits
                );
                assert_eq!(
                    msg.common.sid.code, 0,
                    "incorrect value for common.sid.code, expected 0, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 22,
                    "incorrect value for common.sid.sat, expected 22, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toa.tow, 446384,
                    "incorrect value for common.toa.tow, expected 446384, is {}",
                    msg.common.toa.tow
                );
                assert_eq!(
                    msg.common.toa.wn, 2154,
                    "incorrect value for common.toa.wn, expected 2154, is {}",
                    msg.common.toa.wn
                );
                assert!(
                    msg.common.ura.almost_eq(2.20000000000000018e+00),
                    "incorrect value for common.ura, expected 2.20000000000000018e+00, is {:e}",
                    msg.common.ura
                );
                assert_eq!(
                    msg.common.valid, 1,
                    "incorrect value for common.valid, expected 1, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.epsilon.almost_eq(-9.89303662959964747e-01),
                    "incorrect value for epsilon, expected -9.89303662959964747e-01, is {:e}",
                    msg.epsilon
                );
                assert!(
                    msg.i.almost_eq(5.15355002975463867e+03),
                    "incorrect value for i, expected 5.15355002975463867e+03, is {:e}",
                    msg.i
                );
                assert!(
                    msg.lambda_na.almost_eq(-2.20007884211468815e-02),
                    "incorrect value for lambda_na, expected -2.20007884211468815e-02, is {:e}",
                    msg.lambda_na
                );
                assert!(
                    msg.omega.almost_eq(9.34151448025979714e-01),
                    "incorrect value for omega, expected 9.34151448025979714e-01, is {:e}",
                    msg.omega
                );
                assert!(
                    msg.t.almost_eq(-1.87318184487976169e+00),
                    "incorrect value for t, expected -1.87318184487976169e+00, is {:e}",
                    msg.t
                );
                assert!(
                    msg.t_dot.almost_eq(-8.90358515577419627e-09),
                    "incorrect value for t_dot, expected -8.90358515577419627e-09, is {:e}",
                    msg.t_dot
                );
                assert!(
                    msg.t_lambda_na.almost_eq(7.07220705226063728e-03),
                    "incorrect value for t_lambda_na, expected 7.07220705226063728e-03, is {:e}",
                    msg.t_lambda_na
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAlmanacGlo"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}