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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgAlmanacGPS.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_almanac_gps() {
    {
        let mut payload = Cursor::new(vec![
            85, 114, 0, 195, 4, 94, 22, 0, 176, 207, 6, 0, 106, 8, 154, 153, 153, 153, 153, 153, 1,
            64, 64, 56, 0, 0, 1, 0, 142, 41, 5, 235, 95, 135, 150, 191, 0, 0, 0, 32, 191, 247, 124,
            63, 0, 0, 192, 206, 140, 33, 180, 64, 41, 131, 179, 134, 141, 248, 253, 191, 227, 133,
            81, 54, 204, 30, 67, 190, 216, 59, 199, 39, 96, 168, 239, 191, 71, 11, 217, 147, 145,
            228, 237, 63, 0, 0, 0, 0, 108, 177, 68, 191, 0, 0, 0, 0, 0, 192, 163, 61, 190, 45,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAlmanacGps(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x72,
                    "Incorrect message type, expected 0x72, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert!(
                    msg.af0.almost_eq(-6.31501898169517517e-04),
                    "incorrect value for af0, expected -6.31501898169517517e-04, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(8.98126018000766635e-12),
                    "incorrect value for af1, expected 8.98126018000766635e-12, is {:e}",
                    msg.af1
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
                    msg.ecc.almost_eq(7.07220705226063728e-03),
                    "incorrect value for ecc, expected 7.07220705226063728e-03, is {:e}",
                    msg.ecc
                );
                assert!(
                    msg.inc.almost_eq(9.34151448025979714e-01),
                    "incorrect value for inc, expected 9.34151448025979714e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.m0.almost_eq(-2.20007884211468815e-02),
                    "incorrect value for m0, expected -2.20007884211468815e-02, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(-1.87318184487976169e+00),
                    "incorrect value for omega0, expected -1.87318184487976169e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-8.90358515577419627e-09),
                    "incorrect value for omegadot, expected -8.90358515577419627e-09, is {:e}",
                    msg.omegadot
                );
                assert!(
                    msg.sqrta.almost_eq(5.15355002975463867e+03),
                    "incorrect value for sqrta, expected 5.15355002975463867e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.w.almost_eq(-9.89303662959964747e-01),
                    "incorrect value for w, expected -9.89303662959964747e-01, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAlmanacGPS"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_almanac_gps() {
    {
        let json_input = r#"{"preamble":85,"msg_type":114,"sender":1219,"length":94,"payload":"FgCwzwYAagiamZmZmZkBQEA4AAABAI4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/AAAAAGyxRL8AAAAAAMCjPQ==","crc":11710,"common":{"sid":{"sat":22,"code":0},"toa":{"tow":446384,"wn":2154},"ura":2.2,"fit_interval":14400,"valid":1,"health_bits":0},"m0":-0.02200078842114688,"ecc":0.007072207052260637,"sqrta":5153.550029754639,"omega0":-1.8731818448797617,"omegadot":-8.903585155774196e-09,"w":-0.9893036629599647,"inc":0.9341514480259797,"af0":-0.0006315018981695175,"af1":8.981260180007666e-12}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAlmanacGps(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x72,
                    "Incorrect message type, expected 0x72, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert!(
                    msg.af0.almost_eq(-6.31501898169517517e-04),
                    "incorrect value for af0, expected -6.31501898169517517e-04, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(8.98126018000766635e-12),
                    "incorrect value for af1, expected 8.98126018000766635e-12, is {:e}",
                    msg.af1
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
                    msg.ecc.almost_eq(7.07220705226063728e-03),
                    "incorrect value for ecc, expected 7.07220705226063728e-03, is {:e}",
                    msg.ecc
                );
                assert!(
                    msg.inc.almost_eq(9.34151448025979714e-01),
                    "incorrect value for inc, expected 9.34151448025979714e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.m0.almost_eq(-2.20007884211468815e-02),
                    "incorrect value for m0, expected -2.20007884211468815e-02, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(-1.87318184487976169e+00),
                    "incorrect value for omega0, expected -1.87318184487976169e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-8.90358515577419627e-09),
                    "incorrect value for omegadot, expected -8.90358515577419627e-09, is {:e}",
                    msg.omegadot
                );
                assert!(
                    msg.sqrta.almost_eq(5.15355002975463867e+03),
                    "incorrect value for sqrta, expected 5.15355002975463867e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.w.almost_eq(-9.89303662959964747e-01),
                    "incorrect value for w, expected -9.89303662959964747e-01, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAlmanacGPS"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_almanac_gps`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_almanac_gps() {
    {
        let mut payload = Cursor::new(vec![
            85, 114, 0, 195, 4, 94, 22, 0, 176, 207, 6, 0, 106, 8, 154, 153, 153, 153, 153, 153, 1,
            64, 64, 56, 0, 0, 1, 0, 142, 41, 5, 235, 95, 135, 150, 191, 0, 0, 0, 32, 191, 247, 124,
            63, 0, 0, 192, 206, 140, 33, 180, 64, 41, 131, 179, 134, 141, 248, 253, 191, 227, 133,
            81, 54, 204, 30, 67, 190, 216, 59, 199, 39, 96, 168, 239, 191, 71, 11, 217, 147, 145,
            228, 237, 63, 0, 0, 0, 0, 108, 177, 68, 191, 0, 0, 0, 0, 0, 192, 163, 61, 190, 45,
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
        let sbp_msg = sbp::messages::Sbp::MsgAlmanacGps(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAlmanacGps(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x72,
                    "Incorrect message type, expected 0x72, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert!(
                    msg.af0.almost_eq(-6.31501898169517517e-04),
                    "incorrect value for af0, expected -6.31501898169517517e-04, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(8.98126018000766635e-12),
                    "incorrect value for af1, expected 8.98126018000766635e-12, is {:e}",
                    msg.af1
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
                    msg.ecc.almost_eq(7.07220705226063728e-03),
                    "incorrect value for ecc, expected 7.07220705226063728e-03, is {:e}",
                    msg.ecc
                );
                assert!(
                    msg.inc.almost_eq(9.34151448025979714e-01),
                    "incorrect value for inc, expected 9.34151448025979714e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.m0.almost_eq(-2.20007884211468815e-02),
                    "incorrect value for m0, expected -2.20007884211468815e-02, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(-1.87318184487976169e+00),
                    "incorrect value for omega0, expected -1.87318184487976169e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-8.90358515577419627e-09),
                    "incorrect value for omegadot, expected -8.90358515577419627e-09, is {:e}",
                    msg.omegadot
                );
                assert!(
                    msg.sqrta.almost_eq(5.15355002975463867e+03),
                    "incorrect value for sqrta, expected 5.15355002975463867e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.w.almost_eq(-9.89303662959964747e-01),
                    "incorrect value for w, expected -9.89303662959964747e-01, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAlmanacGPS"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
