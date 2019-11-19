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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNEDCOV.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_23() {
    {
        let payload: Vec<u8> = vec![
            85, 18, 2, 66, 0, 42, 100, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 128, 63,
            0, 0, 128, 63, 0, 0, 128, 63, 0, 0, 128, 63, 0, 0, 128, 63, 0, 0, 128, 63, 10, 0, 88,
            205,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelNEDCov(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x212,
                    "Incorrect message type, expected 0x212, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_d_d.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_d_d, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_d_d
                );
                assert!(
                    msg.cov_e_d.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_e_d, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_e_d
                );
                assert!(
                    msg.cov_e_e.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_e_e, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_e_e
                );
                assert!(
                    msg.cov_n_d.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_n_d, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_n_d
                );
                assert!(
                    msg.cov_n_e.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_n_e, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_n_e
                );
                assert!(
                    msg.cov_n_n.almost_eq(1.00000000000000000e+00),
                    "incorrect value for cov_n_n, expected 1.00000000000000000e+00, is {:e}",
                    msg.cov_n_n
                );
                assert_eq!(msg.e, 1, "incorrect value for e, expected 1, is {}", msg.e);
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(msg.n, 1, "incorrect value for n, expected 1, is {}", msg.n);
                assert_eq!(
                    msg.n_sats, 10,
                    "incorrect value for n_sats, expected 10, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 100,
                    "incorrect value for tow, expected 100, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDCov"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
