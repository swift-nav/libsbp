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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelEcefCovGnss.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_navigation_MsgVelEcefCovGnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 53, 2, 0, 16, 42, 224, 229, 233, 29, 253, 255, 255, 255, 1, 0, 0, 0, 4, 0, 0, 0,
            46, 224, 32, 59, 32, 214, 14, 59, 150, 147, 220, 186, 19, 63, 138, 59, 26, 150, 35,
            187, 11, 193, 119, 59, 21, 2, 22, 230,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEFCovGnss(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x235,
                    "Incorrect message type, expected 0x235, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(2.45476840063929558e-03),
                    "incorrect value for cov_x_x, expected 2.45476840063929558e-03, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(2.17951089143753052e-03),
                    "incorrect value for cov_x_y, expected 2.17951089143753052e-03, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(-1.68286520056426525e-03),
                    "incorrect value for cov_x_z, expected -1.68286520056426525e-03, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(4.21894481405615807e-03),
                    "incorrect value for cov_y_y, expected 4.21894481405615807e-03, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(-2.49612936750054359e-03),
                    "incorrect value for cov_y_z, expected -2.49612936750054359e-03, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(3.78042715601623058e-03),
                    "incorrect value for cov_z_z, expected 3.78042715601623058e-03, is {:e}",
                    msg.cov_z_z
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 21,
                    "incorrect value for n_sats, expected 21, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501868000,
                    "incorrect value for tow, expected 501868000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -3,
                    "incorrect value for x, expected -3, is {}",
                    msg.x
                );
                assert_eq!(msg.y, 1, "incorrect value for y, expected 1, is {}", msg.y);
                assert_eq!(msg.z, 4, "incorrect value for z, expected 4, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFCovGnss"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
