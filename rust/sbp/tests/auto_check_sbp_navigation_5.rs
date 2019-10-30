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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEFDepA.yaml by generate.py. Do not modify by hand!

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
fn test_auto_check_sbp_navigation_5() {
    {
        use sbp::messages::navigation::MsgBaselineECEFDepA;
        let payload: Vec<u8> = vec![
            85, 2, 2, 246, 215, 20, 20, 46, 39, 0, 21, 48, 255, 255, 52, 117, 255, 255, 216, 211,
            254, 255, 0, 0, 9, 1, 50, 137,
        ];

        assert_eq!(
            MsgBaselineECEFDepA::MSG_ID,
            0x202,
            "Incorrect message type, expected 0x202, is {}",
            MsgBaselineECEFDepA::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgBaselineECEFDepA(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567700,
                    "incorrect value for tow, expected 2567700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -53227,
                    "incorrect value for x, expected -53227, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -35532,
                    "incorrect value for y, expected -35532, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -76840,
                    "incorrect value for z, expected -76840, is {}",
                    msg.z
                );
            }
            _ => assert!(
                false,
                "Invalid message type! Expected a MsgBaselineECEFDepA"
            ),
        };
    }
    {
        use sbp::messages::navigation::MsgBaselineECEFDepA;
        let payload: Vec<u8> = vec![
            85, 2, 2, 246, 215, 20, 120, 46, 39, 0, 58, 49, 255, 255, 49, 116, 255, 255, 134, 211,
            254, 255, 0, 0, 9, 1, 227, 155,
        ];

        assert_eq!(
            MsgBaselineECEFDepA::MSG_ID,
            0x202,
            "Incorrect message type, expected 0x202, is {}",
            MsgBaselineECEFDepA::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgBaselineECEFDepA(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567800,
                    "incorrect value for tow, expected 2567800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -52934,
                    "incorrect value for x, expected -52934, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -35791,
                    "incorrect value for y, expected -35791, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -76922,
                    "incorrect value for z, expected -76922, is {}",
                    msg.z
                );
            }
            _ => assert!(
                false,
                "Invalid message type! Expected a MsgBaselineECEFDepA"
            ),
        };
    }
    {
        use sbp::messages::navigation::MsgBaselineECEFDepA;
        let payload: Vec<u8> = vec![
            85, 2, 2, 246, 215, 20, 220, 46, 39, 0, 97, 50, 255, 255, 47, 115, 255, 255, 52, 211,
            254, 255, 0, 0, 9, 1, 61, 126,
        ];

        assert_eq!(
            MsgBaselineECEFDepA::MSG_ID,
            0x202,
            "Incorrect message type, expected 0x202, is {}",
            MsgBaselineECEFDepA::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgBaselineECEFDepA(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567900,
                    "incorrect value for tow, expected 2567900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -52639,
                    "incorrect value for x, expected -52639, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -36049,
                    "incorrect value for y, expected -36049, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -77004,
                    "incorrect value for z, expected -77004, is {}",
                    msg.z
                );
            }
            _ => assert!(
                false,
                "Invalid message type! Expected a MsgBaselineECEFDepA"
            ),
        };
    }
    {
        use sbp::messages::navigation::MsgBaselineECEFDepA;
        let payload: Vec<u8> = vec![
            85, 2, 2, 246, 215, 20, 64, 47, 39, 0, 136, 51, 255, 255, 45, 114, 255, 255, 228, 210,
            254, 255, 0, 0, 9, 1, 200, 79,
        ];

        assert_eq!(
            MsgBaselineECEFDepA::MSG_ID,
            0x202,
            "Incorrect message type, expected 0x202, is {}",
            MsgBaselineECEFDepA::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgBaselineECEFDepA(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2568000,
                    "incorrect value for tow, expected 2568000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -52344,
                    "incorrect value for x, expected -52344, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -36307,
                    "incorrect value for y, expected -36307, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -77084,
                    "incorrect value for z, expected -77084, is {}",
                    msg.z
                );
            }
            _ => assert!(
                false,
                "Invalid message type! Expected a MsgBaselineECEFDepA"
            ),
        };
    }
    {
        use sbp::messages::navigation::MsgBaselineECEFDepA;
        let payload: Vec<u8> = vec![
            85, 2, 2, 246, 215, 20, 164, 47, 39, 0, 176, 52, 255, 255, 44, 113, 255, 255, 149, 210,
            254, 255, 0, 0, 9, 1, 104, 24,
        ];

        assert_eq!(
            MsgBaselineECEFDepA::MSG_ID,
            0x202,
            "Incorrect message type, expected 0x202, is {}",
            MsgBaselineECEFDepA::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgBaselineECEFDepA(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2568100,
                    "incorrect value for tow, expected 2568100, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -52048,
                    "incorrect value for x, expected -52048, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -36564,
                    "incorrect value for y, expected -36564, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -77163,
                    "incorrect value for z, expected -77163, is {}",
                    msg.z
                );
            }
            _ => assert!(
                false,
                "Invalid message type! Expected a MsgBaselineECEFDepA"
            ),
        };
    }
}
