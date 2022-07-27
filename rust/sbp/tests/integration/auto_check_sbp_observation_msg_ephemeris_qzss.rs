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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_msgEphemerisQzss.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_ephemeris_qzss() {
    {
        let mut payload = Cursor::new(vec![
            85, 142, 0, 128, 240, 139, 193, 31, 208, 221, 6, 0, 106, 8, 0, 0, 0, 64, 64, 56, 0, 0,
            0, 0, 0, 0, 192, 177, 0, 232, 228, 195, 0, 160, 19, 194, 0, 224, 135, 183, 0, 96, 10,
            55, 0, 192, 157, 181, 0, 0, 46, 52, 167, 72, 107, 105, 179, 1, 39, 62, 15, 224, 158,
            211, 241, 164, 211, 63, 0, 0, 0, 24, 251, 83, 179, 63, 0, 0, 0, 34, 44, 93, 185, 64,
            143, 62, 206, 232, 193, 181, 242, 191, 207, 216, 69, 106, 98, 255, 39, 190, 65, 132,
            95, 22, 48, 15, 249, 191, 249, 82, 67, 94, 30, 100, 231, 63, 117, 167, 187, 233, 187,
            253, 181, 61, 160, 129, 193, 185, 0, 0, 168, 172, 0, 0, 0, 0, 208, 221, 6, 0, 106, 8,
            49, 49, 3, 126, 23,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgEphemerisQzss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x8e,
                    "Incorrect message type, expected 0x8e, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf080,
                    "incorrect sender id, expected 0xf080, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(-3.69084067642688751e-04),
                    "incorrect value for af0, expected -3.69084067642688751e-04, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(-4.77484718430787325e-12),
                    "incorrect value for af1, expected -4.77484718430787325e-12, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(-1.17532908916473389e-06),
                    "incorrect value for c_ic, expected -1.17532908916473389e-06, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(1.62050127983093262e-07),
                    "incorrect value for c_is, expected 1.62050127983093262e-07, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(-3.69062500000000000e+01),
                    "incorrect value for c_rc, expected -3.69062500000000000e+01, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(-4.57812500000000000e+02),
                    "incorrect value for c_rs, expected -4.57812500000000000e+02, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(-1.61975622177124023e-05),
                    "incorrect value for c_uc, expected -1.61975622177124023e-05, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(8.24779272079467773e-06),
                    "incorrect value for c_us, expected 8.24779272079467773e-06, is {:e}",
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
                    msg.common.sid.code, 31,
                    "incorrect value for common.sid.code, expected 31, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 193,
                    "incorrect value for common.sid.sat, expected 193, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toe.tow, 450000,
                    "incorrect value for common.toe.tow, expected 450000, is {}",
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
                    msg.common.valid, 0,
                    "incorrect value for common.valid, expected 0, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.dn.almost_eq(2.67832584873643293e-09),
                    "incorrect value for dn, expected 2.67832584873643293e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(7.55001958459615707e-02),
                    "incorrect value for ecc, expected 7.55001958459615707e-02, is {:e}",
                    msg.ecc
                );
                assert!(
                    msg.inc.almost_eq(7.30971511943237506e-01),
                    "incorrect value for inc, expected 7.30971511943237506e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(2.00008331149806980e-11),
                    "incorrect value for inc_dot, expected 2.00008331149806980e-11, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iodc, 817,
                    "incorrect value for iodc, expected 817, is {}",
                    msg.iodc
                );
                assert_eq!(
                    msg.iode, 49,
                    "incorrect value for iode, expected 49, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(3.06942421589611436e-01),
                    "incorrect value for m0, expected 3.06942421589611436e-01, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(-1.16937437953666623e+00),
                    "incorrect value for omega0, expected -1.16937437953666623e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-2.79368779688176837e-09),
                    "incorrect value for omegadot, expected -2.79368779688176837e-09, is {:e}",
                    msg.omegadot
                );
                assert!(
                    msg.sqrta.almost_eq(6.49317239379882812e+03),
                    "incorrect value for sqrta, expected 6.49317239379882812e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.tgd.almost_eq(-5.58793544769287109e-09),
                    "incorrect value for tgd, expected -5.58793544769287109e-09, is {:e}",
                    msg.tgd
                );
                assert_eq!(
                    msg.toc.tow, 450000,
                    "incorrect value for toc.tow, expected 450000, is {}",
                    msg.toc.tow
                );
                assert_eq!(
                    msg.toc.wn, 2154,
                    "incorrect value for toc.wn, expected 2154, is {}",
                    msg.toc.wn
                );
                assert!(
                    msg.w.almost_eq(-1.56620796908852378e+00),
                    "incorrect value for w, expected -1.56620796908852378e+00, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisQzss"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_ephemeris_qzss() {
    {
        let json_input = r#"{"common":{"sid":{"sat":193,"code":31},"toe":{"tow":450000,"wn":2154},"ura":2.0,"fit_interval":14400,"valid":0,"health_bits":0},"tgd":-5.587935447692871e-09,"c_rs":-457.8125,"c_rc":-36.90625,"c_uc":-1.6197562217712402e-05,"c_us":8.247792720794678e-06,"c_ic":-1.1753290891647339e-06,"c_is":1.6205012798309326e-07,"dn":2.678325848736433e-09,"m0":0.30694242158961144,"ecc":0.07550019584596157,"sqrta":6493.172393798828,"omega0":-1.1693743795366662,"omegadot":-2.7936877968817684e-09,"w":-1.5662079690885238,"inc":0.7309715119432375,"inc_dot":2.0000833114980698e-11,"af0":-0.00036908406764268875,"af1":-4.774847184307873e-12,"af2":0.0,"toc":{"tow":450000,"wn":2154},"iode":49,"iodc":817,"preamble":85,"msg_type":142,"sender":61568,"payload":"wR/Q3QYAaggAAABAQDgAAAAAAADAsQDo5MMAoBPCAOCHtwBgCjcAwJ21AAAuNKdIa2mzASc+D+Ce0/Gk0z8AAAAY+1OzPwAAACIsXblAjz7O6MG18r/P2EVqYv8nvkGEXxYwD/m/+VJDXh5k5z91p7vpu/21PaCBwbkAAKisAAAAANDdBgBqCDExAw==","crc":6014,"length":139}"#.as_bytes();

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
            sbp::messages::Sbp::MsgEphemerisQzss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x8e,
                    "Incorrect message type, expected 0x8e, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf080,
                    "incorrect sender id, expected 0xf080, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(-3.69084067642688751e-04),
                    "incorrect value for af0, expected -3.69084067642688751e-04, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(-4.77484718430787325e-12),
                    "incorrect value for af1, expected -4.77484718430787325e-12, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(-1.17532908916473389e-06),
                    "incorrect value for c_ic, expected -1.17532908916473389e-06, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(1.62050127983093262e-07),
                    "incorrect value for c_is, expected 1.62050127983093262e-07, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(-3.69062500000000000e+01),
                    "incorrect value for c_rc, expected -3.69062500000000000e+01, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(-4.57812500000000000e+02),
                    "incorrect value for c_rs, expected -4.57812500000000000e+02, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(-1.61975622177124023e-05),
                    "incorrect value for c_uc, expected -1.61975622177124023e-05, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(8.24779272079467773e-06),
                    "incorrect value for c_us, expected 8.24779272079467773e-06, is {:e}",
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
                    msg.common.sid.code, 31,
                    "incorrect value for common.sid.code, expected 31, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 193,
                    "incorrect value for common.sid.sat, expected 193, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toe.tow, 450000,
                    "incorrect value for common.toe.tow, expected 450000, is {}",
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
                    msg.common.valid, 0,
                    "incorrect value for common.valid, expected 0, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.dn.almost_eq(2.67832584873643293e-09),
                    "incorrect value for dn, expected 2.67832584873643293e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(7.55001958459615707e-02),
                    "incorrect value for ecc, expected 7.55001958459615707e-02, is {:e}",
                    msg.ecc
                );
                assert!(
                    msg.inc.almost_eq(7.30971511943237506e-01),
                    "incorrect value for inc, expected 7.30971511943237506e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(2.00008331149806980e-11),
                    "incorrect value for inc_dot, expected 2.00008331149806980e-11, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iodc, 817,
                    "incorrect value for iodc, expected 817, is {}",
                    msg.iodc
                );
                assert_eq!(
                    msg.iode, 49,
                    "incorrect value for iode, expected 49, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(3.06942421589611436e-01),
                    "incorrect value for m0, expected 3.06942421589611436e-01, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(-1.16937437953666623e+00),
                    "incorrect value for omega0, expected -1.16937437953666623e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-2.79368779688176837e-09),
                    "incorrect value for omegadot, expected -2.79368779688176837e-09, is {:e}",
                    msg.omegadot
                );
                assert!(
                    msg.sqrta.almost_eq(6.49317239379882812e+03),
                    "incorrect value for sqrta, expected 6.49317239379882812e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.tgd.almost_eq(-5.58793544769287109e-09),
                    "incorrect value for tgd, expected -5.58793544769287109e-09, is {:e}",
                    msg.tgd
                );
                assert_eq!(
                    msg.toc.tow, 450000,
                    "incorrect value for toc.tow, expected 450000, is {}",
                    msg.toc.tow
                );
                assert_eq!(
                    msg.toc.wn, 2154,
                    "incorrect value for toc.wn, expected 2154, is {}",
                    msg.toc.wn
                );
                assert!(
                    msg.w.almost_eq(-1.56620796908852378e+00),
                    "incorrect value for w, expected -1.56620796908852378e+00, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisQzss"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_ephemeris_qzss`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_ephemeris_qzss() {
    {
        let mut payload = Cursor::new(vec![
            85, 142, 0, 128, 240, 139, 193, 31, 208, 221, 6, 0, 106, 8, 0, 0, 0, 64, 64, 56, 0, 0,
            0, 0, 0, 0, 192, 177, 0, 232, 228, 195, 0, 160, 19, 194, 0, 224, 135, 183, 0, 96, 10,
            55, 0, 192, 157, 181, 0, 0, 46, 52, 167, 72, 107, 105, 179, 1, 39, 62, 15, 224, 158,
            211, 241, 164, 211, 63, 0, 0, 0, 24, 251, 83, 179, 63, 0, 0, 0, 34, 44, 93, 185, 64,
            143, 62, 206, 232, 193, 181, 242, 191, 207, 216, 69, 106, 98, 255, 39, 190, 65, 132,
            95, 22, 48, 15, 249, 191, 249, 82, 67, 94, 30, 100, 231, 63, 117, 167, 187, 233, 187,
            253, 181, 61, 160, 129, 193, 185, 0, 0, 168, 172, 0, 0, 0, 0, 208, 221, 6, 0, 106, 8,
            49, 49, 3, 126, 23,
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
        let sbp_msg = sbp::messages::Sbp::MsgEphemerisQzss(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgEphemerisQzss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x8e,
                    "Incorrect message type, expected 0x8e, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf080,
                    "incorrect sender id, expected 0xf080, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(-3.69084067642688751e-04),
                    "incorrect value for af0, expected -3.69084067642688751e-04, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(-4.77484718430787325e-12),
                    "incorrect value for af1, expected -4.77484718430787325e-12, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(-1.17532908916473389e-06),
                    "incorrect value for c_ic, expected -1.17532908916473389e-06, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(1.62050127983093262e-07),
                    "incorrect value for c_is, expected 1.62050127983093262e-07, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(-3.69062500000000000e+01),
                    "incorrect value for c_rc, expected -3.69062500000000000e+01, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(-4.57812500000000000e+02),
                    "incorrect value for c_rs, expected -4.57812500000000000e+02, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(-1.61975622177124023e-05),
                    "incorrect value for c_uc, expected -1.61975622177124023e-05, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(8.24779272079467773e-06),
                    "incorrect value for c_us, expected 8.24779272079467773e-06, is {:e}",
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
                    msg.common.sid.code, 31,
                    "incorrect value for common.sid.code, expected 31, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 193,
                    "incorrect value for common.sid.sat, expected 193, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toe.tow, 450000,
                    "incorrect value for common.toe.tow, expected 450000, is {}",
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
                    msg.common.valid, 0,
                    "incorrect value for common.valid, expected 0, is {}",
                    msg.common.valid
                );
                assert!(
                    msg.dn.almost_eq(2.67832584873643293e-09),
                    "incorrect value for dn, expected 2.67832584873643293e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(7.55001958459615707e-02),
                    "incorrect value for ecc, expected 7.55001958459615707e-02, is {:e}",
                    msg.ecc
                );
                assert!(
                    msg.inc.almost_eq(7.30971511943237506e-01),
                    "incorrect value for inc, expected 7.30971511943237506e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(2.00008331149806980e-11),
                    "incorrect value for inc_dot, expected 2.00008331149806980e-11, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iodc, 817,
                    "incorrect value for iodc, expected 817, is {}",
                    msg.iodc
                );
                assert_eq!(
                    msg.iode, 49,
                    "incorrect value for iode, expected 49, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(3.06942421589611436e-01),
                    "incorrect value for m0, expected 3.06942421589611436e-01, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(-1.16937437953666623e+00),
                    "incorrect value for omega0, expected -1.16937437953666623e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-2.79368779688176837e-09),
                    "incorrect value for omegadot, expected -2.79368779688176837e-09, is {:e}",
                    msg.omegadot
                );
                assert!(
                    msg.sqrta.almost_eq(6.49317239379882812e+03),
                    "incorrect value for sqrta, expected 6.49317239379882812e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.tgd.almost_eq(-5.58793544769287109e-09),
                    "incorrect value for tgd, expected -5.58793544769287109e-09, is {:e}",
                    msg.tgd
                );
                assert_eq!(
                    msg.toc.tow, 450000,
                    "incorrect value for toc.tow, expected 450000, is {}",
                    msg.toc.tow
                );
                assert_eq!(
                    msg.toc.wn, 2154,
                    "incorrect value for toc.wn, expected 2154, is {}",
                    msg.toc.wn
                );
                assert!(
                    msg.w.almost_eq(-1.56620796908852378e+00),
                    "incorrect value for w, expected -1.56620796908852378e+00, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisQzss"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
