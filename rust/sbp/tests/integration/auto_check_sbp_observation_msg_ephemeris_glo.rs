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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGLO.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_ephemeris_glo() {
    {
        let mut payload = Cursor::new(vec![
            85, 139, 0, 10, 9, 92, 4, 3, 70, 197, 6, 0, 106, 8, 0, 0, 160, 64, 96, 9, 0, 0, 1, 0,
            0, 0, 128, 43, 128, 97, 175, 184, 0, 0, 64, 177, 0, 0, 128, 66, 246, 57, 103, 193, 0,
            0, 0, 34, 170, 78, 34, 65, 0, 0, 240, 199, 84, 86, 117, 193, 0, 0, 0, 98, 6, 250, 154,
            192, 0, 0, 0, 217, 58, 221, 163, 192, 0, 0, 0, 184, 138, 46, 139, 64, 0, 0, 122, 53, 0,
            0, 122, 53, 0, 128, 59, 54, 14, 100, 89, 149,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgEphemerisGlo(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x8b,
                    "Incorrect message type, expected 0x8b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x90a,
                    "incorrect sender id, expected 0x90a, is {}",
                    sender_id
                );
                assert!(
                    msg.acc[0].almost_eq(9.31322574615478516e-07),
                    "incorrect value for acc[0], expected 9.31322574615478516e-07, is {:e}",
                    msg.acc[0]
                );
                assert!(
                    msg.acc[1].almost_eq(9.31322574615478516e-07),
                    "incorrect value for acc[1], expected 9.31322574615478516e-07, is {:e}",
                    msg.acc[1]
                );
                assert!(
                    msg.acc[2].almost_eq(2.79396772384643555e-06),
                    "incorrect value for acc[2], expected 2.79396772384643555e-06, is {:e}",
                    msg.acc[2]
                );
                assert_eq!(
                    msg.common.fit_interval, 2400,
                    "incorrect value for common.fit_interval, expected 2400, is {}",
                    msg.common.fit_interval
                );
                assert_eq!(
                    msg.common.health_bits, 0,
                    "incorrect value for common.health_bits, expected 0, is {}",
                    msg.common.health_bits
                );
                assert_eq!(
                    msg.common.sid.code, 3,
                    "incorrect value for common.sid.code, expected 3, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 4,
                    "incorrect value for common.sid.sat, expected 4, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toe.tow, 443718,
                    "incorrect value for common.toe.tow, expected 443718, is {}",
                    msg.common.toe.tow
                );
                assert_eq!(
                    msg.common.toe.wn, 2154,
                    "incorrect value for common.toe.wn, expected 2154, is {}",
                    msg.common.toe.wn
                );
                assert!(
                    msg.common.ura.almost_eq(5.00000000000000000e+00),
                    "incorrect value for common.ura, expected 5.00000000000000000e+00, is {:e}",
                    msg.common.ura
                );
                assert_eq!(
                    msg.common.valid, 1,
                    "incorrect value for common.valid, expected 1, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.d_tau.almost_eq(-2.79396772384643555e-09),
                    "incorrect value for d_tau, expected -2.79396772384643555e-09, is {:e}",
                    msg.d_tau
                );
                assert_eq!(
                    msg.fcn, 14,
                    "incorrect value for fcn, expected 14, is {}",
                    msg.fcn
                );
                assert!(
                    msg.gamma.almost_eq(9.09494701772928238e-13),
                    "incorrect value for gamma, expected 9.09494701772928238e-13, is {:e}",
                    msg.gamma
                );
                assert_eq!(
                    msg.iod, 100,
                    "incorrect value for iod, expected 100, is {}",
                    msg.iod
                );
                assert!(
                    msg.pos[0].almost_eq(-1.21773300781250000e+07),
                    "incorrect value for pos[0], expected -1.21773300781250000e+07, is {:e}",
                    msg.pos[0]
                );
                assert!(
                    msg.pos[1].almost_eq(5.99893066406250000e+05),
                    "incorrect value for pos[1], expected 5.99893066406250000e+05, is {:e}",
                    msg.pos[1]
                );
                assert!(
                    msg.pos[2].almost_eq(-2.23737084960937500e+07),
                    "incorrect value for pos[2], expected -2.23737084960937500e+07, is {:e}",
                    msg.pos[2]
                );
                assert!(
                    msg.tau.almost_eq(-8.36281105875968933e-05),
                    "incorrect value for tau, expected -8.36281105875968933e-05, is {:e}",
                    msg.tau
                );
                assert!(
                    msg.vel[0].almost_eq(-1.72650623321533203e+03),
                    "incorrect value for vel[0], expected -1.72650623321533203e+03, is {:e}",
                    msg.vel[0]
                );
                assert!(
                    msg.vel[1].almost_eq(-2.54261493682861328e+03),
                    "incorrect value for vel[1], expected -2.54261493682861328e+03, is {:e}",
                    msg.vel[1]
                );
                assert!(
                    msg.vel[2].almost_eq(8.69817733764648438e+02),
                    "incorrect value for vel[2], expected 8.69817733764648438e+02, is {:e}",
                    msg.vel[2]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisGlo"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_ephemeris_glo() {
    {
        let json_input = r#"{"common":{"sid":{"sat":4,"code":3},"toe":{"tow":443718,"wn":2154},"ura":5.0,"fit_interval":2400,"valid":1,"health_bits":0},"gamma":9.094947017729282e-13,"tau":-8.36281105875969e-05,"d_tau":-2.7939677238464355e-09,"pos":[-12177330.078125,599893.06640625,-22373708.49609375],"vel":[-1726.506233215332,-2542.6149368286133,869.8177337646484],"acc":[9.313225746154785e-07,9.313225746154785e-07,2.7939677238464355e-06],"fcn":14,"iod":100,"preamble":85,"msg_type":139,"sender":2314,"payload":"BANGxQYAaggAAKBAYAkAAAEAAACAK4Bhr7gAAECxAACAQvY5Z8EAAAAiqk4iQQAA8MdUVnXBAAAAYgb6msAAAADZOt2jwAAAALiKLotAAAB6NQAAejUAgDs2DmQ=","crc":38233,"length":92}"#.as_bytes();

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
            sbp::messages::Sbp::MsgEphemerisGlo(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x8b,
                    "Incorrect message type, expected 0x8b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x90a,
                    "incorrect sender id, expected 0x90a, is {}",
                    sender_id
                );
                assert!(
                    msg.acc[0].almost_eq(9.31322574615478516e-07),
                    "incorrect value for acc[0], expected 9.31322574615478516e-07, is {:e}",
                    msg.acc[0]
                );
                assert!(
                    msg.acc[1].almost_eq(9.31322574615478516e-07),
                    "incorrect value for acc[1], expected 9.31322574615478516e-07, is {:e}",
                    msg.acc[1]
                );
                assert!(
                    msg.acc[2].almost_eq(2.79396772384643555e-06),
                    "incorrect value for acc[2], expected 2.79396772384643555e-06, is {:e}",
                    msg.acc[2]
                );
                assert_eq!(
                    msg.common.fit_interval, 2400,
                    "incorrect value for common.fit_interval, expected 2400, is {}",
                    msg.common.fit_interval
                );
                assert_eq!(
                    msg.common.health_bits, 0,
                    "incorrect value for common.health_bits, expected 0, is {}",
                    msg.common.health_bits
                );
                assert_eq!(
                    msg.common.sid.code, 3,
                    "incorrect value for common.sid.code, expected 3, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 4,
                    "incorrect value for common.sid.sat, expected 4, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toe.tow, 443718,
                    "incorrect value for common.toe.tow, expected 443718, is {}",
                    msg.common.toe.tow
                );
                assert_eq!(
                    msg.common.toe.wn, 2154,
                    "incorrect value for common.toe.wn, expected 2154, is {}",
                    msg.common.toe.wn
                );
                assert!(
                    msg.common.ura.almost_eq(5.00000000000000000e+00),
                    "incorrect value for common.ura, expected 5.00000000000000000e+00, is {:e}",
                    msg.common.ura
                );
                assert_eq!(
                    msg.common.valid, 1,
                    "incorrect value for common.valid, expected 1, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.d_tau.almost_eq(-2.79396772384643555e-09),
                    "incorrect value for d_tau, expected -2.79396772384643555e-09, is {:e}",
                    msg.d_tau
                );
                assert_eq!(
                    msg.fcn, 14,
                    "incorrect value for fcn, expected 14, is {}",
                    msg.fcn
                );
                assert!(
                    msg.gamma.almost_eq(9.09494701772928238e-13),
                    "incorrect value for gamma, expected 9.09494701772928238e-13, is {:e}",
                    msg.gamma
                );
                assert_eq!(
                    msg.iod, 100,
                    "incorrect value for iod, expected 100, is {}",
                    msg.iod
                );
                assert!(
                    msg.pos[0].almost_eq(-1.21773300781250000e+07),
                    "incorrect value for pos[0], expected -1.21773300781250000e+07, is {:e}",
                    msg.pos[0]
                );
                assert!(
                    msg.pos[1].almost_eq(5.99893066406250000e+05),
                    "incorrect value for pos[1], expected 5.99893066406250000e+05, is {:e}",
                    msg.pos[1]
                );
                assert!(
                    msg.pos[2].almost_eq(-2.23737084960937500e+07),
                    "incorrect value for pos[2], expected -2.23737084960937500e+07, is {:e}",
                    msg.pos[2]
                );
                assert!(
                    msg.tau.almost_eq(-8.36281105875968933e-05),
                    "incorrect value for tau, expected -8.36281105875968933e-05, is {:e}",
                    msg.tau
                );
                assert!(
                    msg.vel[0].almost_eq(-1.72650623321533203e+03),
                    "incorrect value for vel[0], expected -1.72650623321533203e+03, is {:e}",
                    msg.vel[0]
                );
                assert!(
                    msg.vel[1].almost_eq(-2.54261493682861328e+03),
                    "incorrect value for vel[1], expected -2.54261493682861328e+03, is {:e}",
                    msg.vel[1]
                );
                assert!(
                    msg.vel[2].almost_eq(8.69817733764648438e+02),
                    "incorrect value for vel[2], expected 8.69817733764648438e+02, is {:e}",
                    msg.vel[2]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisGlo"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_ephemeris_glo`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_ephemeris_glo() {
    {
        let mut payload = Cursor::new(vec![
            85, 139, 0, 10, 9, 92, 4, 3, 70, 197, 6, 0, 106, 8, 0, 0, 160, 64, 96, 9, 0, 0, 1, 0,
            0, 0, 128, 43, 128, 97, 175, 184, 0, 0, 64, 177, 0, 0, 128, 66, 246, 57, 103, 193, 0,
            0, 0, 34, 170, 78, 34, 65, 0, 0, 240, 199, 84, 86, 117, 193, 0, 0, 0, 98, 6, 250, 154,
            192, 0, 0, 0, 217, 58, 221, 163, 192, 0, 0, 0, 184, 138, 46, 139, 64, 0, 0, 122, 53, 0,
            0, 122, 53, 0, 128, 59, 54, 14, 100, 89, 149,
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
        let sbp_msg = sbp::messages::Sbp::MsgEphemerisGlo(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgEphemerisGlo(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x8b,
                    "Incorrect message type, expected 0x8b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x90a,
                    "incorrect sender id, expected 0x90a, is {}",
                    sender_id
                );
                assert!(
                    msg.acc[0].almost_eq(9.31322574615478516e-07),
                    "incorrect value for acc[0], expected 9.31322574615478516e-07, is {:e}",
                    msg.acc[0]
                );
                assert!(
                    msg.acc[1].almost_eq(9.31322574615478516e-07),
                    "incorrect value for acc[1], expected 9.31322574615478516e-07, is {:e}",
                    msg.acc[1]
                );
                assert!(
                    msg.acc[2].almost_eq(2.79396772384643555e-06),
                    "incorrect value for acc[2], expected 2.79396772384643555e-06, is {:e}",
                    msg.acc[2]
                );
                assert_eq!(
                    msg.common.fit_interval, 2400,
                    "incorrect value for common.fit_interval, expected 2400, is {}",
                    msg.common.fit_interval
                );
                assert_eq!(
                    msg.common.health_bits, 0,
                    "incorrect value for common.health_bits, expected 0, is {}",
                    msg.common.health_bits
                );
                assert_eq!(
                    msg.common.sid.code, 3,
                    "incorrect value for common.sid.code, expected 3, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 4,
                    "incorrect value for common.sid.sat, expected 4, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toe.tow, 443718,
                    "incorrect value for common.toe.tow, expected 443718, is {}",
                    msg.common.toe.tow
                );
                assert_eq!(
                    msg.common.toe.wn, 2154,
                    "incorrect value for common.toe.wn, expected 2154, is {}",
                    msg.common.toe.wn
                );
                assert!(
                    msg.common.ura.almost_eq(5.00000000000000000e+00),
                    "incorrect value for common.ura, expected 5.00000000000000000e+00, is {:e}",
                    msg.common.ura
                );
                assert_eq!(
                    msg.common.valid, 1,
                    "incorrect value for common.valid, expected 1, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.d_tau.almost_eq(-2.79396772384643555e-09),
                    "incorrect value for d_tau, expected -2.79396772384643555e-09, is {:e}",
                    msg.d_tau
                );
                assert_eq!(
                    msg.fcn, 14,
                    "incorrect value for fcn, expected 14, is {}",
                    msg.fcn
                );
                assert!(
                    msg.gamma.almost_eq(9.09494701772928238e-13),
                    "incorrect value for gamma, expected 9.09494701772928238e-13, is {:e}",
                    msg.gamma
                );
                assert_eq!(
                    msg.iod, 100,
                    "incorrect value for iod, expected 100, is {}",
                    msg.iod
                );
                assert!(
                    msg.pos[0].almost_eq(-1.21773300781250000e+07),
                    "incorrect value for pos[0], expected -1.21773300781250000e+07, is {:e}",
                    msg.pos[0]
                );
                assert!(
                    msg.pos[1].almost_eq(5.99893066406250000e+05),
                    "incorrect value for pos[1], expected 5.99893066406250000e+05, is {:e}",
                    msg.pos[1]
                );
                assert!(
                    msg.pos[2].almost_eq(-2.23737084960937500e+07),
                    "incorrect value for pos[2], expected -2.23737084960937500e+07, is {:e}",
                    msg.pos[2]
                );
                assert!(
                    msg.tau.almost_eq(-8.36281105875968933e-05),
                    "incorrect value for tau, expected -8.36281105875968933e-05, is {:e}",
                    msg.tau
                );
                assert!(
                    msg.vel[0].almost_eq(-1.72650623321533203e+03),
                    "incorrect value for vel[0], expected -1.72650623321533203e+03, is {:e}",
                    msg.vel[0]
                );
                assert!(
                    msg.vel[1].almost_eq(-2.54261493682861328e+03),
                    "incorrect value for vel[1], expected -2.54261493682861328e+03, is {:e}",
                    msg.vel[1]
                );
                assert!(
                    msg.vel[2].almost_eq(8.69817733764648438e+02),
                    "incorrect value for vel[2], expected 8.69817733764648438e+02, is {:e}",
                    msg.vel[2]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisGlo"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
