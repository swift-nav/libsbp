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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGal.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_ephemeris_gal() {
    {
        let mut payload = Cursor::new(vec![
            85, 141, 0, 128, 240, 153, 27, 14, 32, 217, 6, 0, 106, 8, 20, 174, 71, 64, 64, 56, 0,
            0, 1, 0, 0, 0, 16, 49, 0, 0, 16, 49, 0, 0, 34, 65, 0, 184, 132, 67, 0, 0, 16, 53, 0, 0,
            134, 54, 0, 0, 8, 179, 0, 0, 8, 179, 217, 204, 130, 105, 128, 182, 43, 62, 248, 106,
            31, 220, 8, 136, 253, 191, 0, 0, 0, 0, 151, 92, 38, 63, 0, 0, 0, 55, 154, 64, 181, 64,
            56, 38, 1, 141, 255, 182, 242, 63, 222, 147, 136, 39, 79, 186, 56, 190, 80, 114, 204,
            251, 193, 92, 191, 63, 237, 55, 19, 41, 177, 73, 239, 63, 49, 65, 189, 240, 8, 216,
            245, 189, 255, 255, 255, 255, 67, 235, 241, 190, 255, 255, 255, 255, 255, 255, 161,
            189, 0, 0, 0, 0, 32, 217, 6, 0, 106, 8, 108, 0, 108, 0, 0, 71, 208,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgEphemerisGal(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x8d,
                    "Incorrect message type, expected 0x8d, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf080,
                    "incorrect sender id, expected 0xf080, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(-1.70888961292803254e-05),
                    "incorrect value for af0, expected -1.70888961292803254e-05, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(-8.18545231595635253e-12),
                    "incorrect value for af1, expected -8.18545231595635253e-12, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.bgd_e1e5a.almost_eq(2.09547579288482666e-09),
                    "incorrect value for bgd_e1e5a, expected 2.09547579288482666e-09, is {:e}",
                    msg.bgd_e1e5a
                );
                assert!(
                    msg.bgd_e1e5b.almost_eq(2.09547579288482666e-09),
                    "incorrect value for bgd_e1e5b, expected 2.09547579288482666e-09, is {:e}",
                    msg.bgd_e1e5b
                );
                assert!(
                    msg.c_ic.almost_eq(-3.16649675369262695e-08),
                    "incorrect value for c_ic, expected -3.16649675369262695e-08, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(-3.16649675369262695e-08),
                    "incorrect value for c_is, expected -3.16649675369262695e-08, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(2.65437500000000000e+02),
                    "incorrect value for c_rc, expected 2.65437500000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(1.01250000000000000e+01),
                    "incorrect value for c_rs, expected 1.01250000000000000e+01, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(5.36441802978515625e-07),
                    "incorrect value for c_uc, expected 5.36441802978515625e-07, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(3.99351119995117188e-06),
                    "incorrect value for c_us, expected 3.99351119995117188e-06, is {:e}",
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
                    msg.common.sid.code, 14,
                    "incorrect value for common.sid.code, expected 14, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 27,
                    "incorrect value for common.sid.sat, expected 27, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toe.tow, 448800,
                    "incorrect value for common.toe.tow, expected 448800, is {}",
                    msg.common.toe.tow
                );
                assert_eq!(
                    msg.common.toe.wn, 2154,
                    "incorrect value for common.toe.wn, expected 2154, is {}",
                    msg.common.toe.wn
                );
                assert!(
                    msg.common.ura.almost_eq(3.11999988555908203e+00),
                    "incorrect value for common.ura, expected 3.11999988555908203e+00, is {:e}",
                    msg.common.ura
                );
                assert_eq!(
                    msg.common.valid, 1,
                    "incorrect value for common.valid, expected 1, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.dn.almost_eq(3.22620581299322575e-09),
                    "incorrect value for dn, expected 3.22620581299322575e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(1.70606072060763836e-04),
                    "incorrect value for ecc, expected 1.70606072060763836e-04, is {:e}",
                    msg.ecc
                );
                assert!(
                    msg.inc.almost_eq(9.77745609497785773e-01),
                    "incorrect value for inc, expected 9.77745609497785773e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(-3.17870383434514646e-10),
                    "incorrect value for inc_dot, expected -3.17870383434514646e-10, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iodc, 108,
                    "incorrect value for iodc, expected 108, is {}",
                    msg.iodc
                );
                assert_eq!(
                    msg.iode, 108,
                    "incorrect value for iode, expected 108, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(-1.84571157441558675e+00),
                    "incorrect value for m0, expected -1.84571157441558675e+00, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(1.16967730598334008e+00),
                    "incorrect value for omega0, expected 1.16967730598334008e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-5.75738267524087236e-09),
                    "incorrect value for omegadot, expected -5.75738267524087236e-09, is {:e}",
                    msg.omegadot
                );
                assert_eq!(
                    msg.source, 0,
                    "incorrect value for source, expected 0, is {}",
                    msg.source
                );
                assert!(
                    msg.sqrta.almost_eq(5.44060240173339844e+03),
                    "incorrect value for sqrta, expected 5.44060240173339844e+03, is {:e}",
                    msg.sqrta
                );
                assert_eq!(
                    msg.toc.tow, 448800,
                    "incorrect value for toc.tow, expected 448800, is {}",
                    msg.toc.tow
                );
                assert_eq!(
                    msg.toc.wn, 2154,
                    "incorrect value for toc.wn, expected 2154, is {}",
                    msg.toc.wn
                );
                assert!(
                    msg.w.almost_eq(1.22509120916626246e-01),
                    "incorrect value for w, expected 1.22509120916626246e-01, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisGal"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_ephemeris_gal() {
    {
        let json_input = r#"{"common":{"sid":{"sat":27,"code":14},"toe":{"tow":448800,"wn":2154},"ura":3.119999885559082,"fit_interval":14400,"valid":1,"health_bits":0},"bgd_e1e5a":2.0954757928848267e-09,"bgd_e1e5b":2.0954757928848267e-09,"c_rs":10.125,"c_rc":265.4375,"c_uc":5.364418029785156e-07,"c_us":3.993511199951172e-06,"c_ic":-3.166496753692627e-08,"c_is":-3.166496753692627e-08,"dn":3.2262058129932258e-09,"m0":-1.8457115744155868,"ecc":0.00017060607206076384,"sqrta":5440.602401733398,"omega0":1.16967730598334,"omegadot":-5.757382675240872e-09,"w":0.12250912091662625,"inc":0.9777456094977858,"inc_dot":-3.1787038343451465e-10,"af0":-1.7088896129280325e-05,"af1":-8.185452315956353e-12,"af2":0.0,"toc":{"tow":448800,"wn":2154},"iode":108,"iodc":108,"source":0,"preamble":85,"msg_type":141,"sender":61568,"payload":"Gw4g2QYAaggUrkdAQDgAAAEAAAAQMQAAEDEAACJBALiEQwAAEDUAAIY2AAAIswAACLPZzIJpgLYrPvhqH9wIiP2/AAAAAJdcJj8AAAA3mkC1QDgmAY3/tvI/3pOIJ0+6OL5Qcsz7wVy/P+03EymxSe8/MUG98AjY9b3/////Q+vxvv///////6G9AAAAACDZBgBqCGwAbAAA","crc":53319,"length":153}"#.as_bytes();

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
            sbp::messages::Sbp::MsgEphemerisGal(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x8d,
                    "Incorrect message type, expected 0x8d, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf080,
                    "incorrect sender id, expected 0xf080, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(-1.70888961292803254e-05),
                    "incorrect value for af0, expected -1.70888961292803254e-05, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(-8.18545231595635253e-12),
                    "incorrect value for af1, expected -8.18545231595635253e-12, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.bgd_e1e5a.almost_eq(2.09547579288482666e-09),
                    "incorrect value for bgd_e1e5a, expected 2.09547579288482666e-09, is {:e}",
                    msg.bgd_e1e5a
                );
                assert!(
                    msg.bgd_e1e5b.almost_eq(2.09547579288482666e-09),
                    "incorrect value for bgd_e1e5b, expected 2.09547579288482666e-09, is {:e}",
                    msg.bgd_e1e5b
                );
                assert!(
                    msg.c_ic.almost_eq(-3.16649675369262695e-08),
                    "incorrect value for c_ic, expected -3.16649675369262695e-08, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(-3.16649675369262695e-08),
                    "incorrect value for c_is, expected -3.16649675369262695e-08, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(2.65437500000000000e+02),
                    "incorrect value for c_rc, expected 2.65437500000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(1.01250000000000000e+01),
                    "incorrect value for c_rs, expected 1.01250000000000000e+01, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(5.36441802978515625e-07),
                    "incorrect value for c_uc, expected 5.36441802978515625e-07, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(3.99351119995117188e-06),
                    "incorrect value for c_us, expected 3.99351119995117188e-06, is {:e}",
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
                    msg.common.sid.code, 14,
                    "incorrect value for common.sid.code, expected 14, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 27,
                    "incorrect value for common.sid.sat, expected 27, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toe.tow, 448800,
                    "incorrect value for common.toe.tow, expected 448800, is {}",
                    msg.common.toe.tow
                );
                assert_eq!(
                    msg.common.toe.wn, 2154,
                    "incorrect value for common.toe.wn, expected 2154, is {}",
                    msg.common.toe.wn
                );
                assert!(
                    msg.common.ura.almost_eq(3.11999988555908203e+00),
                    "incorrect value for common.ura, expected 3.11999988555908203e+00, is {:e}",
                    msg.common.ura
                );
                assert_eq!(
                    msg.common.valid, 1,
                    "incorrect value for common.valid, expected 1, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.dn.almost_eq(3.22620581299322575e-09),
                    "incorrect value for dn, expected 3.22620581299322575e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(1.70606072060763836e-04),
                    "incorrect value for ecc, expected 1.70606072060763836e-04, is {:e}",
                    msg.ecc
                );
                assert!(
                    msg.inc.almost_eq(9.77745609497785773e-01),
                    "incorrect value for inc, expected 9.77745609497785773e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(-3.17870383434514646e-10),
                    "incorrect value for inc_dot, expected -3.17870383434514646e-10, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iodc, 108,
                    "incorrect value for iodc, expected 108, is {}",
                    msg.iodc
                );
                assert_eq!(
                    msg.iode, 108,
                    "incorrect value for iode, expected 108, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(-1.84571157441558675e+00),
                    "incorrect value for m0, expected -1.84571157441558675e+00, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(1.16967730598334008e+00),
                    "incorrect value for omega0, expected 1.16967730598334008e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-5.75738267524087236e-09),
                    "incorrect value for omegadot, expected -5.75738267524087236e-09, is {:e}",
                    msg.omegadot
                );
                assert_eq!(
                    msg.source, 0,
                    "incorrect value for source, expected 0, is {}",
                    msg.source
                );
                assert!(
                    msg.sqrta.almost_eq(5.44060240173339844e+03),
                    "incorrect value for sqrta, expected 5.44060240173339844e+03, is {:e}",
                    msg.sqrta
                );
                assert_eq!(
                    msg.toc.tow, 448800,
                    "incorrect value for toc.tow, expected 448800, is {}",
                    msg.toc.tow
                );
                assert_eq!(
                    msg.toc.wn, 2154,
                    "incorrect value for toc.wn, expected 2154, is {}",
                    msg.toc.wn
                );
                assert!(
                    msg.w.almost_eq(1.22509120916626246e-01),
                    "incorrect value for w, expected 1.22509120916626246e-01, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisGal"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_ephemeris_gal`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_ephemeris_gal() {
    {
        let mut payload = Cursor::new(vec![
            85, 141, 0, 128, 240, 153, 27, 14, 32, 217, 6, 0, 106, 8, 20, 174, 71, 64, 64, 56, 0,
            0, 1, 0, 0, 0, 16, 49, 0, 0, 16, 49, 0, 0, 34, 65, 0, 184, 132, 67, 0, 0, 16, 53, 0, 0,
            134, 54, 0, 0, 8, 179, 0, 0, 8, 179, 217, 204, 130, 105, 128, 182, 43, 62, 248, 106,
            31, 220, 8, 136, 253, 191, 0, 0, 0, 0, 151, 92, 38, 63, 0, 0, 0, 55, 154, 64, 181, 64,
            56, 38, 1, 141, 255, 182, 242, 63, 222, 147, 136, 39, 79, 186, 56, 190, 80, 114, 204,
            251, 193, 92, 191, 63, 237, 55, 19, 41, 177, 73, 239, 63, 49, 65, 189, 240, 8, 216,
            245, 189, 255, 255, 255, 255, 67, 235, 241, 190, 255, 255, 255, 255, 255, 255, 161,
            189, 0, 0, 0, 0, 32, 217, 6, 0, 106, 8, 108, 0, 108, 0, 0, 71, 208,
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
        let sbp_msg = sbp::messages::Sbp::MsgEphemerisGal(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgEphemerisGal(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x8d,
                    "Incorrect message type, expected 0x8d, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf080,
                    "incorrect sender id, expected 0xf080, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(-1.70888961292803254e-05),
                    "incorrect value for af0, expected -1.70888961292803254e-05, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(-8.18545231595635253e-12),
                    "incorrect value for af1, expected -8.18545231595635253e-12, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.bgd_e1e5a.almost_eq(2.09547579288482666e-09),
                    "incorrect value for bgd_e1e5a, expected 2.09547579288482666e-09, is {:e}",
                    msg.bgd_e1e5a
                );
                assert!(
                    msg.bgd_e1e5b.almost_eq(2.09547579288482666e-09),
                    "incorrect value for bgd_e1e5b, expected 2.09547579288482666e-09, is {:e}",
                    msg.bgd_e1e5b
                );
                assert!(
                    msg.c_ic.almost_eq(-3.16649675369262695e-08),
                    "incorrect value for c_ic, expected -3.16649675369262695e-08, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(-3.16649675369262695e-08),
                    "incorrect value for c_is, expected -3.16649675369262695e-08, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(2.65437500000000000e+02),
                    "incorrect value for c_rc, expected 2.65437500000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(1.01250000000000000e+01),
                    "incorrect value for c_rs, expected 1.01250000000000000e+01, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(5.36441802978515625e-07),
                    "incorrect value for c_uc, expected 5.36441802978515625e-07, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(3.99351119995117188e-06),
                    "incorrect value for c_us, expected 3.99351119995117188e-06, is {:e}",
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
                    msg.common.sid.code, 14,
                    "incorrect value for common.sid.code, expected 14, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 27,
                    "incorrect value for common.sid.sat, expected 27, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toe.tow, 448800,
                    "incorrect value for common.toe.tow, expected 448800, is {}",
                    msg.common.toe.tow
                );
                assert_eq!(
                    msg.common.toe.wn, 2154,
                    "incorrect value for common.toe.wn, expected 2154, is {}",
                    msg.common.toe.wn
                );
                assert!(
                    msg.common.ura.almost_eq(3.11999988555908203e+00),
                    "incorrect value for common.ura, expected 3.11999988555908203e+00, is {:e}",
                    msg.common.ura
                );
                assert_eq!(
                    msg.common.valid, 1,
                    "incorrect value for common.valid, expected 1, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.dn.almost_eq(3.22620581299322575e-09),
                    "incorrect value for dn, expected 3.22620581299322575e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(1.70606072060763836e-04),
                    "incorrect value for ecc, expected 1.70606072060763836e-04, is {:e}",
                    msg.ecc
                );
                assert!(
                    msg.inc.almost_eq(9.77745609497785773e-01),
                    "incorrect value for inc, expected 9.77745609497785773e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(-3.17870383434514646e-10),
                    "incorrect value for inc_dot, expected -3.17870383434514646e-10, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iodc, 108,
                    "incorrect value for iodc, expected 108, is {}",
                    msg.iodc
                );
                assert_eq!(
                    msg.iode, 108,
                    "incorrect value for iode, expected 108, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(-1.84571157441558675e+00),
                    "incorrect value for m0, expected -1.84571157441558675e+00, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(1.16967730598334008e+00),
                    "incorrect value for omega0, expected 1.16967730598334008e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-5.75738267524087236e-09),
                    "incorrect value for omegadot, expected -5.75738267524087236e-09, is {:e}",
                    msg.omegadot
                );
                assert_eq!(
                    msg.source, 0,
                    "incorrect value for source, expected 0, is {}",
                    msg.source
                );
                assert!(
                    msg.sqrta.almost_eq(5.44060240173339844e+03),
                    "incorrect value for sqrta, expected 5.44060240173339844e+03, is {:e}",
                    msg.sqrta
                );
                assert_eq!(
                    msg.toc.tow, 448800,
                    "incorrect value for toc.tow, expected 448800, is {}",
                    msg.toc.tow
                );
                assert_eq!(
                    msg.toc.wn, 2154,
                    "incorrect value for toc.wn, expected 2154, is {}",
                    msg.toc.wn
                );
                assert!(
                    msg.w.almost_eq(1.22509120916626246e-01),
                    "incorrect value for w, expected 1.22509120916626246e-01, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisGal"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
