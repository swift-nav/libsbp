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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_system.yaml by generate.py. Do not modify by hand!

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
fn test_auto_check_sbp_system_46() {
    {
        use sbp::messages::system::MsgStartup;
        let payload: Vec<u8> = vec![85, 0, 255, 195, 4, 4, 0, 0, 0, 0, 127, 181];

        assert_eq!(
            MsgStartup::MSG_ID,
            0xff00,
            "Incorrect message type, expected 0xff00, is {}",
            MsgStartup::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgStartup(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.reserved, 0,
                    "incorrect value for reserved, expected 0, is {}",
                    msg.reserved
                );
            }
            _ => assert!(false, "Invalid message type! Expected a MsgStartup"),
        };
    }
    {
        use sbp::messages::system::MsgHeartbeat;
        let payload: Vec<u8> = vec![85, 255, 255, 195, 4, 4, 0, 0, 0, 0, 66, 57];

        assert_eq!(
            MsgHeartbeat::MSG_ID,
            0xffff,
            "Incorrect message type, expected 0xffff, is {}",
            MsgHeartbeat::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgHeartbeat(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
            }
            _ => assert!(false, "Invalid message type! Expected a MsgHeartbeat"),
        };
    }
}
