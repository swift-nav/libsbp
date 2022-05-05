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
