//
// Copyright (C) 2015-2018 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgAngularRate.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

trait AlmostEq {
    fn almost_eq(self, rhs: Self) -> bool;
}

impl AlmostEq for f32 {
    fn almost_eq(self, rhs: Self) -> bool {
        const ULP: f32 = 5.0;
        ((self - rhs).abs() <= (std::f32::EPSILON * (self + rhs).abs() * ULP))
            || ((self - rhs).abs() < std::f32::MIN)
    }
}

impl AlmostEq for f64 {
    fn almost_eq(self, rhs: Self) -> bool {
        const ULP: f64 = 5.0;
        ((self - rhs).abs() <= (std::f64::EPSILON * (self + rhs).abs() * ULP))
            || ((self - rhs).abs() < std::f64::MIN)
    }
}

#[test]
fn test_auto_check_sbp_orientation_27() {
    {
        use sbp::messages::orientation::MsgAngularRate;
        let payload: Vec<u8> = vec![
            85, 34, 2, 66, 0, 17, 2, 0, 0, 0, 2, 0, 0, 0, 5, 0, 0, 0, 2, 0, 0, 0, 0, 88, 70,
        ];

        assert_eq!(
            MsgAngularRate::MSG_ID,
            0x222,
            "Incorrect message type, expected 0x222, is {}",
            MsgAngularRate::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgAngularRate(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.tow, 2,
                    "incorrect value for tow, expected 2, is {}",
                    msg.tow
                );
                assert_eq!(msg.x, 2, "incorrect value for x, expected 2, is {}", msg.x);
                assert_eq!(msg.y, 5, "incorrect value for y, expected 5, is {}", msg.y);
                assert_eq!(msg.z, 2, "incorrect value for z, expected 2, is {}", msg.z);
            }
            _ => assert!(false, "Invalid message type! Expected a MsgAngularRate"),
        };
    }
}
