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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientEuler.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_orientation_28() {
    {
        let payload: Vec<u8> = vec![
            85, 33, 2, 66, 0, 29, 1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 8, 0, 0, 0, 0, 0, 224, 64, 0,
            0, 64, 64, 0, 0, 224, 64, 3, 44, 226,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgOrientEuler(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x221,
                    "Incorrect message type, expected 0x221, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 3,
                    "incorrect value for flags, expected 3, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.pitch, 2,
                    "incorrect value for pitch, expected 2, is {}",
                    msg.pitch
                );
                assert!(
                    msg.pitch_accuracy.almost_eq(3.00000000000000000e+00),
                    "incorrect value for pitch_accuracy, expected 3.00000000000000000e+00, is {:e}",
                    msg.pitch_accuracy
                );
                assert_eq!(
                    msg.roll, 1,
                    "incorrect value for roll, expected 1, is {}",
                    msg.roll
                );
                assert!(
                    msg.roll_accuracy.almost_eq(7.00000000000000000e+00),
                    "incorrect value for roll_accuracy, expected 7.00000000000000000e+00, is {:e}",
                    msg.roll_accuracy
                );
                assert_eq!(
                    msg.tow, 1,
                    "incorrect value for tow, expected 1, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.yaw, 8,
                    "incorrect value for yaw, expected 8, is {}",
                    msg.yaw
                );
                assert!(
                    msg.yaw_accuracy.almost_eq(7.00000000000000000e+00),
                    "incorrect value for yaw_accuracy, expected 7.00000000000000000e+00, is {:e}",
                    msg.yaw_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgOrientEuler"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
