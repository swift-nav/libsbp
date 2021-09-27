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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLHCov.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_pos_llh_cov() {
    {
        let mut payload = Cursor::new(vec![
            85, 17, 2, 66, 0, 54, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 64, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 64, 0, 0, 160, 64, 0, 0, 0, 65, 0, 0, 192, 64, 0, 0,
            128, 63, 0, 0, 0, 64, 5, 5, 151, 98,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhCov(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x211,
                    "Incorrect message type, expected 0x211, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_d_d.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_d_d, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_d_d
                );
                assert!(
                    msg.cov_e_d.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_e_d, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_e_d
                );
                assert!(
                    msg.cov_e_e.almost_eq(6.00000000000000000e+00),
                    "incorrect value for cov_e_e, expected 6.00000000000000000e+00, is {:e}",
                    msg.cov_e_e
                );
                assert!(
                    msg.cov_n_d.almost_eq(8.00000000000000000e+00),
                    "incorrect value for cov_n_d, expected 8.00000000000000000e+00, is {:e}",
                    msg.cov_n_d
                );
                assert!(
                    msg.cov_n_e.almost_eq(5.00000000000000000e+00),
                    "incorrect value for cov_n_e, expected 5.00000000000000000e+00, is {:e}",
                    msg.cov_n_e
                );
                assert!(
                    msg.cov_n_n.almost_eq(7.00000000000000000e+00),
                    "incorrect value for cov_n_n, expected 7.00000000000000000e+00, is {:e}",
                    msg.cov_n_n
                );
                assert_eq!(
                    msg.flags, 5,
                    "incorrect value for flags, expected 5, is {}",
                    msg.flags
                );
                assert!(
                    msg.height.almost_eq(0.00000000000000000e+00),
                    "incorrect value for height, expected 0.00000000000000000e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(0.00000000000000000e+00),
                    "incorrect value for lat, expected 0.00000000000000000e+00, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(7.00000000000000000e+00),
                    "incorrect value for lon, expected 7.00000000000000000e+00, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 5,
                    "incorrect value for n_sats, expected 5, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 7,
                    "incorrect value for tow, expected 7, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHCov"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
