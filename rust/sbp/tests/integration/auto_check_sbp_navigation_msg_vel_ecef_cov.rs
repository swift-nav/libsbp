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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEFCov.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_vel_ecef_cov() {
    {
        let mut payload = Cursor::new(vec![
            85, 21, 2, 66, 0, 42, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 64, 0,
            0, 0, 64, 0, 0, 0, 64, 0, 0, 0, 64, 0, 0, 128, 63, 0, 0, 64, 64, 3, 4, 91, 254,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefCov(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x215,
                    "Incorrect message type, expected 0x215, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_x, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_y, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_z, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_y_y, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_y_z, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(3.00000000000000000e+00),
                    "incorrect value for cov_z_z, expected 3.00000000000000000e+00, is {:e}",
                    msg.cov_z_z
                );
                assert_eq!(
                    msg.flags, 4,
                    "incorrect value for flags, expected 4, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 3,
                    "incorrect value for n_sats, expected 3, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2,
                    "incorrect value for tow, expected 2, is {}",
                    msg.tow
                );
                assert_eq!(msg.x, 0, "incorrect value for x, expected 0, is {}", msg.x);
                assert_eq!(msg.y, 0, "incorrect value for y, expected 0, is {}", msg.y);
                assert_eq!(msg.z, 6, "incorrect value for z, expected 6, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFCov"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
