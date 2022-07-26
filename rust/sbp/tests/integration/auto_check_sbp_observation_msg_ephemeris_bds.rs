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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisBds.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_ephemeris_bds() {
    {
        let mut payload = Cursor::new(vec![
            85, 137, 0, 128, 240, 147, 8, 12, 174, 179, 6, 0, 106, 8, 0, 0, 0, 64, 48, 42, 0, 0, 1,
            0, 125, 99, 52, 50, 207, 46, 151, 176, 0, 112, 96, 67, 0, 164, 106, 67, 0, 60, 255, 54,
            0, 224, 47, 53, 0, 0, 143, 179, 0, 192, 190, 52, 146, 101, 162, 196, 109, 104, 19, 62,
            253, 87, 86, 202, 62, 28, 251, 63, 0, 0, 0, 96, 151, 60, 117, 63, 0, 0, 128, 154, 127,
            93, 185, 64, 151, 193, 64, 0, 10, 166, 4, 192, 160, 75, 174, 98, 8, 201, 35, 190, 205,
            29, 12, 71, 189, 150, 5, 192, 176, 72, 249, 189, 193, 172, 240, 63, 72, 249, 188, 180,
            160, 203, 9, 62, 0, 0, 0, 0, 92, 51, 77, 191, 0, 128, 174, 43, 0, 0, 88, 161, 174, 179,
            6, 0, 106, 8, 6, 5, 0, 157, 249,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgEphemerisBds(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x89,
                    "Incorrect message type, expected 0x89, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf080,
                    "incorrect sender id, expected 0xf080, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(-8.91132280230522156e-04),
                    "incorrect value for af0, expected -8.91132280230522156e-04, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(1.23989707390137482e-12),
                    "incorrect value for af1, expected 1.23989707390137482e-12, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(-7.31836466427715493e-19),
                    "incorrect value for af2, expected -7.31836466427715493e-19, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(-6.65895640850067139e-08),
                    "incorrect value for c_ic, expected -6.65895640850067139e-08, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(3.55299562215805054e-07),
                    "incorrect value for c_is, expected 3.55299562215805054e-07, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(2.34640625000000000e+02),
                    "incorrect value for c_rc, expected 2.34640625000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(2.24437500000000000e+02),
                    "incorrect value for c_rs, expected 2.24437500000000000e+02, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(7.60657712817192078e-06),
                    "incorrect value for c_uc, expected 7.60657712817192078e-06, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(6.55185431241989136e-07),
                    "incorrect value for c_us, expected 6.55185431241989136e-07, is {:e}",
                    msg.c_us
                );
                assert_eq!(
                    msg.common.fit_interval, 10800,
                    "incorrect value for common.fit_interval, expected 10800, is {}",
                    msg.common.fit_interval
                );
                assert_eq!(
                    msg.common.health_bits, 0,
                    "incorrect value for common.health_bits, expected 0, is {}",
                    msg.common.health_bits
                );
                assert_eq!(
                    msg.common.sid.code, 12,
                    "incorrect value for common.sid.code, expected 12, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 8,
                    "incorrect value for common.sid.sat, expected 8, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toe.tow, 439214,
                    "incorrect value for common.toe.tow, expected 439214, is {}",
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
                    msg.dn.almost_eq(1.12968991326221325e-09),
                    "incorrect value for dn, expected 1.12968991326221325e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(5.18473749980330467e-03),
                    "incorrect value for ecc, expected 5.18473749980330467e-03, is {:e}",
                    msg.ecc
                );
                assert!(
                    msg.inc.almost_eq(1.04217695435049151e+00),
                    "incorrect value for inc, expected 1.04217695435049151e+00, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(7.50745557280168303e-10),
                    "incorrect value for inc_dot, expected 7.50745557280168303e-10, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iodc, 5,
                    "incorrect value for iodc, expected 5, is {}",
                    msg.iodc
                );
                assert_eq!(
                    msg.iode, 6,
                    "incorrect value for iode, expected 6, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(1.69439581907272374e+00),
                    "incorrect value for m0, expected 1.69439581907272374e+00, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(-2.58107376287098189e+00),
                    "incorrect value for omega0, expected -2.58107376287098189e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-2.30331022783054511e-09),
                    "incorrect value for omegadot, expected -2.30331022783054511e-09, is {:e}",
                    msg.omegadot
                );
                assert!(
                    msg.sqrta.almost_eq(6.49349845123291016e+03),
                    "incorrect value for sqrta, expected 6.49349845123291016e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.tgd1.almost_eq(1.04999999805954758e-08),
                    "incorrect value for tgd1, expected 1.04999999805954758e-08, is {:e}",
                    msg.tgd1
                );
                assert!(
                    msg.tgd2.almost_eq(-1.09999997999210564e-09),
                    "incorrect value for tgd2, expected -1.09999997999210564e-09, is {:e}",
                    msg.tgd2
                );
                assert_eq!(
                    msg.toc.tow, 439214,
                    "incorrect value for toc.tow, expected 439214, is {}",
                    msg.toc.tow
                );
                assert_eq!(
                    msg.toc.wn, 2154,
                    "incorrect value for toc.wn, expected 2154, is {}",
                    msg.toc.wn
                );
                assert!(
                    msg.w.almost_eq(-2.69860320573545787e+00),
                    "incorrect value for w, expected -2.69860320573545787e+00, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisBds"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_ephemeris_bds() {
    {
        let json_input = r#"{"common":{"sid":{"sat":8,"code":12},"toe":{"tow":439214,"wn":2154},"ura":2.0,"fit_interval":10800,"valid":1,"health_bits":0},"tgd1":1.0499999980595476e-08,"tgd2":-1.0999999799921056e-09,"c_rs":224.4375,"c_rc":234.640625,"c_uc":7.606577128171921e-06,"c_us":6.551854312419891e-07,"c_ic":-6.658956408500671e-08,"c_is":3.5529956221580505e-07,"dn":1.1296899132622133e-09,"m0":1.6943958190727237,"ecc":0.005184737499803305,"sqrta":6493.49845123291,"omega0":-2.581073762870982,"omegadot":-2.303310227830545e-09,"w":-2.698603205735458,"inc":1.0421769543504915,"inc_dot":7.507455572801683e-10,"af0":-0.0008911322802305222,"af1":1.2398970739013748e-12,"af2":-7.318364664277155e-19,"toc":{"tow":439214,"wn":2154},"iode":6,"iodc":5,"preamble":85,"msg_type":137,"sender":61568,"payload":"CAyuswYAaggAAABAMCoAAAEAfWM0Ms8ul7AAcGBDAKRqQwA8/zYA4C81AACPswDAvjSSZaLEbWgTPv1XVso+HPs/AAAAYJc8dT8AAICaf125QJfBQAAKpgTAoEuuYgjJI77NHQxHvZYFwLBI+b3BrPA/SPm8tKDLCT4AAAAAXDNNvwCArisAAFihrrMGAGoIBgUA","crc":63901,"length":147}"#.as_bytes();

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
            sbp::messages::Sbp::MsgEphemerisBds(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x89,
                    "Incorrect message type, expected 0x89, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf080,
                    "incorrect sender id, expected 0xf080, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(-8.91132280230522156e-04),
                    "incorrect value for af0, expected -8.91132280230522156e-04, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(1.23989707390137482e-12),
                    "incorrect value for af1, expected 1.23989707390137482e-12, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(-7.31836466427715493e-19),
                    "incorrect value for af2, expected -7.31836466427715493e-19, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(-6.65895640850067139e-08),
                    "incorrect value for c_ic, expected -6.65895640850067139e-08, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(3.55299562215805054e-07),
                    "incorrect value for c_is, expected 3.55299562215805054e-07, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(2.34640625000000000e+02),
                    "incorrect value for c_rc, expected 2.34640625000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(2.24437500000000000e+02),
                    "incorrect value for c_rs, expected 2.24437500000000000e+02, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(7.60657712817192078e-06),
                    "incorrect value for c_uc, expected 7.60657712817192078e-06, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(6.55185431241989136e-07),
                    "incorrect value for c_us, expected 6.55185431241989136e-07, is {:e}",
                    msg.c_us
                );
                assert_eq!(
                    msg.common.fit_interval, 10800,
                    "incorrect value for common.fit_interval, expected 10800, is {}",
                    msg.common.fit_interval
                );
                assert_eq!(
                    msg.common.health_bits, 0,
                    "incorrect value for common.health_bits, expected 0, is {}",
                    msg.common.health_bits
                );
                assert_eq!(
                    msg.common.sid.code, 12,
                    "incorrect value for common.sid.code, expected 12, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 8,
                    "incorrect value for common.sid.sat, expected 8, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toe.tow, 439214,
                    "incorrect value for common.toe.tow, expected 439214, is {}",
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
                    msg.dn.almost_eq(1.12968991326221325e-09),
                    "incorrect value for dn, expected 1.12968991326221325e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(5.18473749980330467e-03),
                    "incorrect value for ecc, expected 5.18473749980330467e-03, is {:e}",
                    msg.ecc
                );
                assert!(
                    msg.inc.almost_eq(1.04217695435049151e+00),
                    "incorrect value for inc, expected 1.04217695435049151e+00, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(7.50745557280168303e-10),
                    "incorrect value for inc_dot, expected 7.50745557280168303e-10, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iodc, 5,
                    "incorrect value for iodc, expected 5, is {}",
                    msg.iodc
                );
                assert_eq!(
                    msg.iode, 6,
                    "incorrect value for iode, expected 6, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(1.69439581907272374e+00),
                    "incorrect value for m0, expected 1.69439581907272374e+00, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(-2.58107376287098189e+00),
                    "incorrect value for omega0, expected -2.58107376287098189e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-2.30331022783054511e-09),
                    "incorrect value for omegadot, expected -2.30331022783054511e-09, is {:e}",
                    msg.omegadot
                );
                assert!(
                    msg.sqrta.almost_eq(6.49349845123291016e+03),
                    "incorrect value for sqrta, expected 6.49349845123291016e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.tgd1.almost_eq(1.04999999805954758e-08),
                    "incorrect value for tgd1, expected 1.04999999805954758e-08, is {:e}",
                    msg.tgd1
                );
                assert!(
                    msg.tgd2.almost_eq(-1.09999997999210564e-09),
                    "incorrect value for tgd2, expected -1.09999997999210564e-09, is {:e}",
                    msg.tgd2
                );
                assert_eq!(
                    msg.toc.tow, 439214,
                    "incorrect value for toc.tow, expected 439214, is {}",
                    msg.toc.tow
                );
                assert_eq!(
                    msg.toc.wn, 2154,
                    "incorrect value for toc.wn, expected 2154, is {}",
                    msg.toc.wn
                );
                assert!(
                    msg.w.almost_eq(-2.69860320573545787e+00),
                    "incorrect value for w, expected -2.69860320573545787e+00, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisBds"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_ephemeris_bds`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_ephemeris_bds() {
    {
        let mut payload = Cursor::new(vec![
            85, 137, 0, 128, 240, 147, 8, 12, 174, 179, 6, 0, 106, 8, 0, 0, 0, 64, 48, 42, 0, 0, 1,
            0, 125, 99, 52, 50, 207, 46, 151, 176, 0, 112, 96, 67, 0, 164, 106, 67, 0, 60, 255, 54,
            0, 224, 47, 53, 0, 0, 143, 179, 0, 192, 190, 52, 146, 101, 162, 196, 109, 104, 19, 62,
            253, 87, 86, 202, 62, 28, 251, 63, 0, 0, 0, 96, 151, 60, 117, 63, 0, 0, 128, 154, 127,
            93, 185, 64, 151, 193, 64, 0, 10, 166, 4, 192, 160, 75, 174, 98, 8, 201, 35, 190, 205,
            29, 12, 71, 189, 150, 5, 192, 176, 72, 249, 189, 193, 172, 240, 63, 72, 249, 188, 180,
            160, 203, 9, 62, 0, 0, 0, 0, 92, 51, 77, 191, 0, 128, 174, 43, 0, 0, 88, 161, 174, 179,
            6, 0, 106, 8, 6, 5, 0, 157, 249,
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
        let sbp_msg = sbp::messages::Sbp::MsgEphemerisBds(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgEphemerisBds(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x89,
                    "Incorrect message type, expected 0x89, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf080,
                    "incorrect sender id, expected 0xf080, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(-8.91132280230522156e-04),
                    "incorrect value for af0, expected -8.91132280230522156e-04, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(1.23989707390137482e-12),
                    "incorrect value for af1, expected 1.23989707390137482e-12, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(-7.31836466427715493e-19),
                    "incorrect value for af2, expected -7.31836466427715493e-19, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(-6.65895640850067139e-08),
                    "incorrect value for c_ic, expected -6.65895640850067139e-08, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(3.55299562215805054e-07),
                    "incorrect value for c_is, expected 3.55299562215805054e-07, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(2.34640625000000000e+02),
                    "incorrect value for c_rc, expected 2.34640625000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(2.24437500000000000e+02),
                    "incorrect value for c_rs, expected 2.24437500000000000e+02, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(7.60657712817192078e-06),
                    "incorrect value for c_uc, expected 7.60657712817192078e-06, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(6.55185431241989136e-07),
                    "incorrect value for c_us, expected 6.55185431241989136e-07, is {:e}",
                    msg.c_us
                );
                assert_eq!(
                    msg.common.fit_interval, 10800,
                    "incorrect value for common.fit_interval, expected 10800, is {}",
                    msg.common.fit_interval
                );
                assert_eq!(
                    msg.common.health_bits, 0,
                    "incorrect value for common.health_bits, expected 0, is {}",
                    msg.common.health_bits
                );
                assert_eq!(
                    msg.common.sid.code, 12,
                    "incorrect value for common.sid.code, expected 12, is {}",
                    msg.common.sid.code
                );
                assert_eq!(
                    msg.common.sid.sat, 8,
                    "incorrect value for common.sid.sat, expected 8, is {}",
                    msg.common.sid.sat
                );
                assert_eq!(
                    msg.common.toe.tow, 439214,
                    "incorrect value for common.toe.tow, expected 439214, is {}",
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
                    msg.dn.almost_eq(1.12968991326221325e-09),
                    "incorrect value for dn, expected 1.12968991326221325e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(5.18473749980330467e-03),
                    "incorrect value for ecc, expected 5.18473749980330467e-03, is {:e}",
                    msg.ecc
                );
                assert!(
                    msg.inc.almost_eq(1.04217695435049151e+00),
                    "incorrect value for inc, expected 1.04217695435049151e+00, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(7.50745557280168303e-10),
                    "incorrect value for inc_dot, expected 7.50745557280168303e-10, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iodc, 5,
                    "incorrect value for iodc, expected 5, is {}",
                    msg.iodc
                );
                assert_eq!(
                    msg.iode, 6,
                    "incorrect value for iode, expected 6, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(1.69439581907272374e+00),
                    "incorrect value for m0, expected 1.69439581907272374e+00, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(-2.58107376287098189e+00),
                    "incorrect value for omega0, expected -2.58107376287098189e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-2.30331022783054511e-09),
                    "incorrect value for omegadot, expected -2.30331022783054511e-09, is {:e}",
                    msg.omegadot
                );
                assert!(
                    msg.sqrta.almost_eq(6.49349845123291016e+03),
                    "incorrect value for sqrta, expected 6.49349845123291016e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.tgd1.almost_eq(1.04999999805954758e-08),
                    "incorrect value for tgd1, expected 1.04999999805954758e-08, is {:e}",
                    msg.tgd1
                );
                assert!(
                    msg.tgd2.almost_eq(-1.09999997999210564e-09),
                    "incorrect value for tgd2, expected -1.09999997999210564e-09, is {:e}",
                    msg.tgd2
                );
                assert_eq!(
                    msg.toc.tow, 439214,
                    "incorrect value for toc.tow, expected 439214, is {}",
                    msg.toc.tow
                );
                assert_eq!(
                    msg.toc.wn, 2154,
                    "incorrect value for toc.wn, expected 2154, is {}",
                    msg.toc.wn
                );
                assert!(
                    msg.w.almost_eq(-2.69860320573545787e+00),
                    "incorrect value for w, expected -2.69860320573545787e+00, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisBds"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
