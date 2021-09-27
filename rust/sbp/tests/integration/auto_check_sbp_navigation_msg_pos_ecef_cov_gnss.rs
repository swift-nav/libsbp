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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCovGNSS.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_pos_ecef_cov_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 52, 2, 0, 16, 54, 24, 229, 233, 29, 52, 254, 158, 218, 42, 142, 68, 193, 69, 162,
            89, 91, 34, 68, 80, 193, 131, 21, 176, 129, 239, 174, 77, 65, 158, 232, 30, 60, 218,
            221, 20, 60, 129, 136, 198, 187, 205, 120, 166, 60, 5, 166, 35, 188, 122, 177, 115, 60,
            18, 4, 159, 102,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefCovGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x234,
                    "Incorrect message type, expected 0x234, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(9.69901494681835175e-03),
                    "incorrect value for cov_x_x, expected 9.69901494681835175e-03, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(9.08609665930271149e-03),
                    "incorrect value for cov_x_y, expected 9.08609665930271149e-03, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(-6.05875300243496895e-03),
                    "incorrect value for cov_x_z, expected -6.05875300243496895e-03, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(2.03212741762399673e-02),
                    "incorrect value for cov_y_y, expected 2.03212741762399673e-02, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(-9.98831260949373245e-03),
                    "incorrect value for cov_y_z, expected -9.98831260949373245e-03, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(1.48738566786050797e-02),
                    "incorrect value for cov_z_z, expected 1.48738566786050797e-02, is {:e}",
                    msg.cov_z_z
                );
                assert_eq!(
                    msg.flags, 4,
                    "incorrect value for flags, expected 4, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 18,
                    "incorrect value for n_sats, expected 18, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501867800,
                    "incorrect value for tow, expected 501867800, is {}",
                    msg.tow
                );
                assert!(
                    msg.x.almost_eq(-2.69422970797708072e+06),
                    "incorrect value for x, expected -2.69422970797708072e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.26407342734581698e+06),
                    "incorrect value for y, expected -4.26407342734581698e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.89065501318615815e+06),
                    "incorrect value for z, expected 3.89065501318615815e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFCovGnss"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
