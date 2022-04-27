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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNedCovGnss.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_vel_ned_cov_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 50, 2, 0, 16, 42, 168, 230, 233, 29, 251, 255, 255, 255, 0, 0, 0, 0, 246, 255, 255,
            255, 15, 58, 207, 58, 248, 139, 116, 55, 103, 197, 57, 57, 203, 186, 129, 58, 109, 171,
            44, 57, 135, 39, 1, 60, 21, 2, 155, 3,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedCovGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x232,
                    "Incorrect message type, expected 0x232, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_d_d.almost_eq(7.88295920938253403e-03),
                    "incorrect value for cov_d_d, expected 7.88295920938253403e-03, is {:e}",
                    msg.cov_d_d
                );
                assert!(
                    msg.cov_e_d.almost_eq(1.64670593221671879e-04),
                    "incorrect value for cov_e_d, expected 1.64670593221671879e-04, is {:e}",
                    msg.cov_e_d
                );
                assert!(
                    msg.cov_e_e.almost_eq(9.89758758805692196e-04),
                    "incorrect value for cov_e_e, expected 9.89758758805692196e-04, is {:e}",
                    msg.cov_e_e
                );
                assert!(
                    msg.cov_n_d.almost_eq(1.77165129571221769e-04),
                    "incorrect value for cov_n_d, expected 1.77165129571221769e-04, is {:e}",
                    msg.cov_n_d
                );
                assert!(
                    msg.cov_n_e.almost_eq(1.45761223393492401e-05),
                    "incorrect value for cov_n_e, expected 1.45761223393492401e-05, is {:e}",
                    msg.cov_n_e
                );
                assert!(
                    msg.cov_n_n.almost_eq(1.58101494889706373e-03),
                    "incorrect value for cov_n_n, expected 1.58101494889706373e-03, is {:e}",
                    msg.cov_n_n
                );
                assert_eq!(
                    msg.d, -10,
                    "incorrect value for d, expected -10, is {}",
                    msg.d
                );
                assert_eq!(msg.e, 0, "incorrect value for e, expected 0, is {}", msg.e);
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n, -5,
                    "incorrect value for n, expected -5, is {}",
                    msg.n
                );
                assert_eq!(
                    msg.n_sats, 21,
                    "incorrect value for n_sats, expected 21, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501868200,
                    "incorrect value for tow, expected 501868200, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDCovGnss"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
