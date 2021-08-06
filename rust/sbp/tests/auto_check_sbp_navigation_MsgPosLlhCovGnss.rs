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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhCovGnss.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_navigation_MsgPosLlhCovGnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 49, 2, 0, 16, 54, 24, 229, 233, 29, 73, 123, 28, 207, 101, 234, 66, 64, 100, 168,
            19, 20, 86, 146, 94, 192, 214, 198, 35, 120, 209, 100, 49, 192, 12, 102, 245, 59, 6,
            181, 192, 185, 168, 79, 243, 58, 96, 60, 148, 59, 253, 58, 93, 186, 159, 174, 6, 61,
            18, 4, 10, 196,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgPosLLHCovGnss(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x231,
                    "Incorrect message type, expected 0x231, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_d_d.almost_eq(3.28813754022121429e-02),
                    "incorrect value for cov_d_d, expected 3.28813754022121429e-02, is {:e}",
                    msg.cov_d_d
                );
                assert!(
                    msg.cov_e_d.almost_eq(-8.43927089590579271e-04),
                    "incorrect value for cov_e_d, expected -8.43927089590579271e-04, is {:e}",
                    msg.cov_e_d
                );
                assert!(
                    msg.cov_e_e.almost_eq(4.52379882335662842e-03),
                    "incorrect value for cov_e_e, expected 4.52379882335662842e-03, is {:e}",
                    msg.cov_e_e
                );
                assert!(
                    msg.cov_n_d.almost_eq(1.85631681233644485e-03),
                    "incorrect value for cov_n_d, expected 1.85631681233644485e-03, is {:e}",
                    msg.cov_n_d
                );
                assert!(
                    msg.cov_n_e.almost_eq(-3.67559667211025953e-04),
                    "incorrect value for cov_n_e, expected -3.67559667211025953e-04, is {:e}",
                    msg.cov_n_e
                );
                assert!(
                    msg.cov_n_n.almost_eq(7.48897157609462738e-03),
                    "incorrect value for cov_n_n, expected 7.48897157609462738e-03, is {:e}",
                    msg.cov_n_n
                );
                assert_eq!(
                    msg.flags, 4,
                    "incorrect value for flags, expected 4, is {}",
                    msg.flags
                );
                assert!(
                    msg.height.almost_eq(-1.73938212478013483e+01),
                    "incorrect value for height, expected -1.73938212478013483e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.78312319649763324e+01),
                    "incorrect value for lat, expected 3.78312319649763324e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22286503810116812e+02),
                    "incorrect value for lon, expected -1.22286503810116812e+02, is {:e}",
                    msg.lon
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
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHCovGnss"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
