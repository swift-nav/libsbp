//
// Copyright (C) 2019 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCov.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_13() {
    {
        let payload: Vec<u8> = vec![
            85, 20, 2, 66, 0, 54, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 64, 0, 0, 0, 0, 0, 0, 240, 63,
            0, 0, 0, 0, 0, 0, 16, 64, 0, 0, 0, 65, 0, 0, 224, 64, 0, 0, 0, 64, 0, 0, 192, 64, 0, 0,
            0, 65, 0, 0, 160, 64, 4, 5, 249, 167,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosECEFCov(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x214,
                    "Incorrect message type, expected 0x214, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(8.00000000000000000e+00),
                    "incorrect value for cov_x_x, expected 8.00000000000000000e+00, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(7.00000000000000000e+00),
                    "incorrect value for cov_x_y, expected 7.00000000000000000e+00, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(2.00000000000000000e+00),
                    "incorrect value for cov_x_z, expected 2.00000000000000000e+00, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(6.00000000000000000e+00),
                    "incorrect value for cov_y_y, expected 6.00000000000000000e+00, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(8.00000000000000000e+00),
                    "incorrect value for cov_y_z, expected 8.00000000000000000e+00, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(5.00000000000000000e+00),
                    "incorrect value for cov_z_z, expected 5.00000000000000000e+00, is {:e}",
                    msg.cov_z_z
                );
                assert_eq!(
                    msg.flags, 5,
                    "incorrect value for flags, expected 5, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 4,
                    "incorrect value for n_sats, expected 4, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 7,
                    "incorrect value for tow, expected 7, is {}",
                    msg.tow
                );
                assert!(
                    msg.x.almost_eq(6.00000000000000000e+00),
                    "incorrect value for x, expected 6.00000000000000000e+00, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(1.00000000000000000e+00),
                    "incorrect value for y, expected 1.00000000000000000e+00, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(4.00000000000000000e+00),
                    "incorrect value for z, expected 4.00000000000000000e+00, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFCov"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
