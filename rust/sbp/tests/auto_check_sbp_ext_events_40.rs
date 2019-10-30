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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_ext_events.yaml by generate.py. Do not modify by hand!

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
fn test_auto_check_sbp_ext_events_40() {
    {
        use sbp::messages::ext_events::MsgExtEvent;
        let payload: Vec<u8> = vec![
            85, 1, 1, 245, 6, 12, 48, 7, 199, 216, 49, 15, 202, 65, 15, 0, 3, 0, 62, 204,
        ];

        assert_eq!(
            MsgExtEvent::MSG_ID,
            0x101,
            "Incorrect message type, expected 0x101, is {}",
            MsgExtEvent::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgExtEvent(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6f5,
                    "incorrect sender id, expected 0x6f5, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 3,
                    "incorrect value for flags, expected 3, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 999882,
                    "incorrect value for ns_residual, expected 999882, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.pin, 0,
                    "incorrect value for pin, expected 0, is {}",
                    msg.pin
                );
                assert_eq!(
                    msg.tow, 254924999,
                    "incorrect value for tow, expected 254924999, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1840,
                    "incorrect value for wn, expected 1840, is {}",
                    msg.wn
                );
            }
            _ => assert!(false, "Invalid message type! Expected a MsgExtEvent"),
        };
    }
}
