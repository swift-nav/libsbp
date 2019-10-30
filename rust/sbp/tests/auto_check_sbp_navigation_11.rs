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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTimeDepA.yaml by generate.py. Do not modify by hand!

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
fn test_auto_check_sbp_navigation_11() {
    {
        use sbp::messages::navigation::MsgGPSTimeDepA;
        let payload: Vec<u8> = vec![
            85, 0, 1, 246, 215, 11, 251, 6, 120, 46, 39, 0, 0, 0, 0, 0, 0, 133, 36,
        ];

        assert_eq!(
            MsgGPSTimeDepA::MSG_ID,
            0x100,
            "Incorrect message type, expected 0x100, is {}",
            MsgGPSTimeDepA::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgGPSTimeDepA(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 0,
                    "incorrect value for ns_residual, expected 0, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 2567800,
                    "incorrect value for tow, expected 2567800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1787,
                    "incorrect value for wn, expected 1787, is {}",
                    msg.wn
                );
            }
            _ => assert!(false, "Invalid message type! Expected a MsgGPSTimeDepA"),
        };
    }
    {
        use sbp::messages::navigation::MsgGPSTimeDepA;
        let payload: Vec<u8> = vec![
            85, 0, 1, 246, 215, 11, 251, 6, 220, 46, 39, 0, 0, 0, 0, 0, 0, 36, 160,
        ];

        assert_eq!(
            MsgGPSTimeDepA::MSG_ID,
            0x100,
            "Incorrect message type, expected 0x100, is {}",
            MsgGPSTimeDepA::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgGPSTimeDepA(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 0,
                    "incorrect value for ns_residual, expected 0, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 2567900,
                    "incorrect value for tow, expected 2567900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1787,
                    "incorrect value for wn, expected 1787, is {}",
                    msg.wn
                );
            }
            _ => assert!(false, "Invalid message type! Expected a MsgGPSTimeDepA"),
        };
    }
    {
        use sbp::messages::navigation::MsgGPSTimeDepA;
        let payload: Vec<u8> = vec![
            85, 0, 1, 246, 215, 11, 251, 6, 64, 47, 39, 0, 0, 0, 0, 0, 0, 171, 190,
        ];

        assert_eq!(
            MsgGPSTimeDepA::MSG_ID,
            0x100,
            "Incorrect message type, expected 0x100, is {}",
            MsgGPSTimeDepA::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgGPSTimeDepA(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 0,
                    "incorrect value for ns_residual, expected 0, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 2568000,
                    "incorrect value for tow, expected 2568000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1787,
                    "incorrect value for wn, expected 1787, is {}",
                    msg.wn
                );
            }
            _ => assert!(false, "Invalid message type! Expected a MsgGPSTimeDepA"),
        };
    }
    {
        use sbp::messages::navigation::MsgGPSTimeDepA;
        let payload: Vec<u8> = vec![
            85, 0, 1, 246, 215, 11, 251, 6, 164, 47, 39, 0, 0, 0, 0, 0, 0, 211, 101,
        ];

        assert_eq!(
            MsgGPSTimeDepA::MSG_ID,
            0x100,
            "Incorrect message type, expected 0x100, is {}",
            MsgGPSTimeDepA::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgGPSTimeDepA(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 0,
                    "incorrect value for ns_residual, expected 0, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 2568100,
                    "incorrect value for tow, expected 2568100, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1787,
                    "incorrect value for wn, expected 1787, is {}",
                    msg.wn
                );
            }
            _ => assert!(false, "Invalid message type! Expected a MsgGPSTimeDepA"),
        };
    }
    {
        use sbp::messages::navigation::MsgGPSTimeDepA;
        let payload: Vec<u8> = vec![
            85, 0, 1, 246, 215, 11, 251, 6, 8, 48, 39, 0, 0, 0, 0, 0, 0, 251, 44,
        ];

        assert_eq!(
            MsgGPSTimeDepA::MSG_ID,
            0x100,
            "Incorrect message type, expected 0x100, is {}",
            MsgGPSTimeDepA::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgGPSTimeDepA(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 0,
                    "incorrect value for ns_residual, expected 0, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 2568200,
                    "incorrect value for tow, expected 2568200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1787,
                    "incorrect value for wn, expected 1787, is {}",
                    msg.wn
                );
            }
            _ => assert!(false, "Invalid message type! Expected a MsgGPSTimeDepA"),
        };
    }
}
