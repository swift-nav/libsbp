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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGPS.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_ephemeris_gps() {
    {
        let mut payload = Cursor::new(vec![
            85, 138, 0, 10, 9, 139, 22, 0, 176, 207, 6, 0, 106, 8, 0, 0, 0, 64, 64, 56, 0, 0, 1, 0,
            0, 0, 152, 178, 0, 64, 81, 194, 0, 80, 154, 67, 0, 32, 56, 182, 0, 128, 82, 54, 0, 0,
            0, 50, 0, 0, 248, 179, 114, 216, 96, 180, 49, 117, 56, 62, 142, 41, 5, 235, 95, 135,
            150, 191, 0, 0, 0, 32, 191, 247, 124, 63, 0, 0, 192, 206, 140, 33, 180, 64, 41, 131,
            179, 134, 141, 248, 253, 191, 227, 133, 81, 54, 204, 30, 67, 190, 216, 59, 199, 39, 96,
            168, 239, 191, 71, 11, 217, 147, 145, 228, 237, 63, 221, 47, 100, 224, 255, 47, 198,
            189, 96, 139, 37, 186, 0, 0, 30, 45, 0, 0, 0, 0, 176, 207, 6, 0, 106, 8, 45, 45, 0,
            170, 4,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgEphemerisGps(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x8a,
                    "Incorrect message type, expected 0x8a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x90a,
                    "incorrect sender id, expected 0x90a, is {}",
                    sender_id
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
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(7.45058059692382812e-09),
                    "incorrect value for c_ic, expected 7.45058059692382812e-09, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(-1.15483999252319336e-07),
                    "incorrect value for c_is, expected -1.15483999252319336e-07, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(3.08625000000000000e+02),
                    "incorrect value for c_rc, expected 3.08625000000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(-5.23125000000000000e+01),
                    "incorrect value for c_rs, expected -5.23125000000000000e+01, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(-2.74367630481719971e-06),
                    "incorrect value for c_uc, expected -2.74367630481719971e-06, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(3.13669443130493164e-06),
                    "incorrect value for c_us, expected 3.13669443130493164e-06, is {:e}",
                    msg.c_us
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
                    msg.common.toe.tow, 446384,
                    "incorrect value for common.toe.tow, expected 446384, is {}",
                    msg.common.toe.tow
                );
                assert_eq!(
                    msg.common.toe.wn, 2154,
                    "incorrect value for common.toe.wn, expected 2154, is {}",
                    msg.common.toe.wn
                );
                assert!(
                    msg.common.ura.almost_eq(2.00000000000000000e+00),
                    "incorrect value for common.ura, expected 2.00000000000000000e+00, is {:e}",
                    msg.common.ura
                );
                assert_eq!(
                    msg.common.valid, 1,
                    "incorrect value for common.valid, expected 1, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.dn.almost_eq(5.69452291402237483e-09),
                    "incorrect value for dn, expected 5.69452291402237483e-09, is {:e}",
                    msg.dn
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
                    msg.inc_dot.almost_eq(-4.03588239641575691e-11),
                    "incorrect value for inc_dot, expected -4.03588239641575691e-11, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iodc, 45,
                    "incorrect value for iodc, expected 45, is {}",
                    msg.iodc
                );
                assert_eq!(
                    msg.iode, 45,
                    "incorrect value for iode, expected 45, is {}",
                    msg.iode
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
                    msg.tgd.almost_eq(-1.76951289176940918e-08),
                    "incorrect value for tgd, expected -1.76951289176940918e-08, is {:e}",
                    msg.tgd
                );
                assert_eq!(
                    msg.toc.tow, 446384,
                    "incorrect value for toc.tow, expected 446384, is {}",
                    msg.toc.tow
                );
                assert_eq!(
                    msg.toc.wn, 2154,
                    "incorrect value for toc.wn, expected 2154, is {}",
                    msg.toc.wn
                );
                assert!(
                    msg.w.almost_eq(-9.89303662959964747e-01),
                    "incorrect value for w, expected -9.89303662959964747e-01, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisGPS"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_ephemeris_gps() {
    {
        let json_input = r#"{"common":{"sid":{"sat":22,"code":0},"toe":{"tow":446384,"wn":2154},"ura":2.0,"fit_interval":14400,"valid":1,"health_bits":0},"tgd":-1.7695128917694092e-08,"c_rs":-52.3125,"c_rc":308.625,"c_uc":-2.7436763048171997e-06,"c_us":3.1366944313049316e-06,"c_ic":7.450580596923828e-09,"c_is":-1.1548399925231934e-07,"dn":5.694522914022375e-09,"m0":-0.02200078842114688,"ecc":0.007072207052260637,"sqrta":5153.550029754639,"omega0":-1.8731818448797617,"omegadot":-8.903585155774196e-09,"w":-0.9893036629599647,"inc":0.9341514480259797,"inc_dot":-4.035882396415757e-11,"af0":-0.0006315018981695175,"af1":8.981260180007666e-12,"af2":0.0,"toc":{"tow":446384,"wn":2154},"iode":45,"iodc":45,"preamble":85,"msg_type":138,"sender":2314,"payload":"FgCwzwYAaggAAABAQDgAAAEAAACYsgBAUcIAUJpDACA4tgCAUjYAAAAyAAD4s3LYYLQxdTg+jikF61+Hlr8AAAAgv/d8PwAAwM6MIbRAKYOzho34/b/jhVE2zB5Dvtg7xydgqO+/RwvZk5Hk7T/dL2Tg/y/GvWCLJboAAB4tAAAAALDPBgBqCC0tAA==","crc":1194,"length":139}"#.as_bytes();

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
            sbp::messages::Sbp::MsgEphemerisGps(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x8a,
                    "Incorrect message type, expected 0x8a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x90a,
                    "incorrect sender id, expected 0x90a, is {}",
                    sender_id
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
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(7.45058059692382812e-09),
                    "incorrect value for c_ic, expected 7.45058059692382812e-09, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(-1.15483999252319336e-07),
                    "incorrect value for c_is, expected -1.15483999252319336e-07, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(3.08625000000000000e+02),
                    "incorrect value for c_rc, expected 3.08625000000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(-5.23125000000000000e+01),
                    "incorrect value for c_rs, expected -5.23125000000000000e+01, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(-2.74367630481719971e-06),
                    "incorrect value for c_uc, expected -2.74367630481719971e-06, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(3.13669443130493164e-06),
                    "incorrect value for c_us, expected 3.13669443130493164e-06, is {:e}",
                    msg.c_us
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
                    msg.common.toe.tow, 446384,
                    "incorrect value for common.toe.tow, expected 446384, is {}",
                    msg.common.toe.tow
                );
                assert_eq!(
                    msg.common.toe.wn, 2154,
                    "incorrect value for common.toe.wn, expected 2154, is {}",
                    msg.common.toe.wn
                );
                assert!(
                    msg.common.ura.almost_eq(2.00000000000000000e+00),
                    "incorrect value for common.ura, expected 2.00000000000000000e+00, is {:e}",
                    msg.common.ura
                );
                assert_eq!(
                    msg.common.valid, 1,
                    "incorrect value for common.valid, expected 1, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.dn.almost_eq(5.69452291402237483e-09),
                    "incorrect value for dn, expected 5.69452291402237483e-09, is {:e}",
                    msg.dn
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
                    msg.inc_dot.almost_eq(-4.03588239641575691e-11),
                    "incorrect value for inc_dot, expected -4.03588239641575691e-11, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iodc, 45,
                    "incorrect value for iodc, expected 45, is {}",
                    msg.iodc
                );
                assert_eq!(
                    msg.iode, 45,
                    "incorrect value for iode, expected 45, is {}",
                    msg.iode
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
                    msg.tgd.almost_eq(-1.76951289176940918e-08),
                    "incorrect value for tgd, expected -1.76951289176940918e-08, is {:e}",
                    msg.tgd
                );
                assert_eq!(
                    msg.toc.tow, 446384,
                    "incorrect value for toc.tow, expected 446384, is {}",
                    msg.toc.tow
                );
                assert_eq!(
                    msg.toc.wn, 2154,
                    "incorrect value for toc.wn, expected 2154, is {}",
                    msg.toc.wn
                );
                assert!(
                    msg.w.almost_eq(-9.89303662959964747e-01),
                    "incorrect value for w, expected -9.89303662959964747e-01, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisGPS"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_ephemeris_gps`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_ephemeris_gps() {
    {
        let mut payload = Cursor::new(vec![
            85, 138, 0, 10, 9, 139, 22, 0, 176, 207, 6, 0, 106, 8, 0, 0, 0, 64, 64, 56, 0, 0, 1, 0,
            0, 0, 152, 178, 0, 64, 81, 194, 0, 80, 154, 67, 0, 32, 56, 182, 0, 128, 82, 54, 0, 0,
            0, 50, 0, 0, 248, 179, 114, 216, 96, 180, 49, 117, 56, 62, 142, 41, 5, 235, 95, 135,
            150, 191, 0, 0, 0, 32, 191, 247, 124, 63, 0, 0, 192, 206, 140, 33, 180, 64, 41, 131,
            179, 134, 141, 248, 253, 191, 227, 133, 81, 54, 204, 30, 67, 190, 216, 59, 199, 39, 96,
            168, 239, 191, 71, 11, 217, 147, 145, 228, 237, 63, 221, 47, 100, 224, 255, 47, 198,
            189, 96, 139, 37, 186, 0, 0, 30, 45, 0, 0, 0, 0, 176, 207, 6, 0, 106, 8, 45, 45, 0,
            170, 4,
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
        let sbp_msg = sbp::messages::Sbp::MsgEphemerisGps(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgEphemerisGps(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x8a,
                    "Incorrect message type, expected 0x8a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x90a,
                    "incorrect sender id, expected 0x90a, is {}",
                    sender_id
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
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(7.45058059692382812e-09),
                    "incorrect value for c_ic, expected 7.45058059692382812e-09, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(-1.15483999252319336e-07),
                    "incorrect value for c_is, expected -1.15483999252319336e-07, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(3.08625000000000000e+02),
                    "incorrect value for c_rc, expected 3.08625000000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(-5.23125000000000000e+01),
                    "incorrect value for c_rs, expected -5.23125000000000000e+01, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(-2.74367630481719971e-06),
                    "incorrect value for c_uc, expected -2.74367630481719971e-06, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(3.13669443130493164e-06),
                    "incorrect value for c_us, expected 3.13669443130493164e-06, is {:e}",
                    msg.c_us
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
                    msg.common.toe.tow, 446384,
                    "incorrect value for common.toe.tow, expected 446384, is {}",
                    msg.common.toe.tow
                );
                assert_eq!(
                    msg.common.toe.wn, 2154,
                    "incorrect value for common.toe.wn, expected 2154, is {}",
                    msg.common.toe.wn
                );
                assert!(
                    msg.common.ura.almost_eq(2.00000000000000000e+00),
                    "incorrect value for common.ura, expected 2.00000000000000000e+00, is {:e}",
                    msg.common.ura
                );
                assert_eq!(
                    msg.common.valid, 1,
                    "incorrect value for common.valid, expected 1, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.dn.almost_eq(5.69452291402237483e-09),
                    "incorrect value for dn, expected 5.69452291402237483e-09, is {:e}",
                    msg.dn
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
                    msg.inc_dot.almost_eq(-4.03588239641575691e-11),
                    "incorrect value for inc_dot, expected -4.03588239641575691e-11, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iodc, 45,
                    "incorrect value for iodc, expected 45, is {}",
                    msg.iodc
                );
                assert_eq!(
                    msg.iode, 45,
                    "incorrect value for iode, expected 45, is {}",
                    msg.iode
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
                    msg.tgd.almost_eq(-1.76951289176940918e-08),
                    "incorrect value for tgd, expected -1.76951289176940918e-08, is {:e}",
                    msg.tgd
                );
                assert_eq!(
                    msg.toc.tow, 446384,
                    "incorrect value for toc.tow, expected 446384, is {}",
                    msg.toc.tow
                );
                assert_eq!(
                    msg.toc.wn, 2154,
                    "incorrect value for toc.wn, expected 2154, is {}",
                    msg.toc.wn
                );
                assert!(
                    msg.w.almost_eq(-9.89303662959964747e-01),
                    "incorrect value for w, expected -9.89303662959964747e-01, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisGPS"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
