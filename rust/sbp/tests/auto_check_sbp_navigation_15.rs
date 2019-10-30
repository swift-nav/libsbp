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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLH.yaml by generate.py. Do not modify by hand!

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
fn test_auto_check_sbp_navigation_15() {
    {
        use sbp::messages::navigation::MsgPosLLH;
        let payload: Vec<u8> = vec![
            85, 10, 2, 211, 136, 34, 40, 244, 122, 19, 201, 106, 155, 186, 42, 160, 66, 64, 168,
            109, 26, 225, 0, 120, 94, 192, 130, 102, 237, 230, 43, 54, 60, 64, 0, 0, 0, 0, 14, 2,
            175, 162,
        ];

        assert_eq!(
            MsgPosLLH::MSG_ID,
            0x20a,
            "Incorrect message type, expected 0x20a, is {}",
            MsgPosLLH::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgPosLLH(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.82116073922720787e+01),
                    "incorrect value for height, expected 2.82116073922720787e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72513039835808470e+01),
                    "incorrect value for lat, expected 3.72513039835808470e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875053668793612e+02),
                    "incorrect value for lon, expected -1.21875053668793612e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 14,
                    "incorrect value for n_sats, expected 14, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326825000,
                    "incorrect value for tow, expected 326825000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => assert!(false, "Invalid message type! Expected a MsgPosLLH"),
        };
    }
    {
        use sbp::messages::navigation::MsgPosLLH;
        let payload: Vec<u8> = vec![
            85, 10, 2, 211, 136, 34, 16, 248, 122, 19, 52, 177, 251, 178, 42, 160, 66, 64, 237, 22,
            97, 224, 0, 120, 94, 192, 107, 188, 109, 90, 247, 189, 59, 64, 0, 0, 0, 0, 15, 2, 38,
            177,
        ];

        assert_eq!(
            MsgPosLLH::MSG_ID,
            0x20a,
            "Incorrect message type, expected 0x20a, is {}",
            MsgPosLLH::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgPosLLH(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.77420555608663726e+01),
                    "incorrect value for height, expected 2.77420555608663726e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72513030747381038e+01),
                    "incorrect value for lat, expected 3.72513030747381038e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875053496183412e+02),
                    "incorrect value for lon, expected -1.21875053496183412e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326826000,
                    "incorrect value for tow, expected 326826000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => assert!(false, "Invalid message type! Expected a MsgPosLLH"),
        };
    }
    {
        use sbp::messages::navigation::MsgPosLLH;
        let payload: Vec<u8> = vec![
            85, 10, 2, 211, 136, 34, 248, 251, 122, 19, 135, 66, 9, 163, 42, 160, 66, 64, 146, 8,
            99, 225, 0, 120, 94, 192, 45, 181, 143, 219, 28, 157, 59, 64, 0, 0, 0, 0, 15, 2, 51,
            40,
        ];

        assert_eq!(
            MsgPosLLH::MSG_ID,
            0x20a,
            "Incorrect message type, expected 0x20a, is {}",
            MsgPosLLH::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgPosLLH(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.76137215829705163e+01),
                    "incorrect value for height, expected 2.76137215829705163e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72513011737074109e+01),
                    "incorrect value for lat, expected 3.72513011737074109e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875053736412411e+02),
                    "incorrect value for lon, expected -1.21875053736412411e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326827000,
                    "incorrect value for tow, expected 326827000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => assert!(false, "Invalid message type! Expected a MsgPosLLH"),
        };
    }
    {
        use sbp::messages::navigation::MsgPosLLH;
        let payload: Vec<u8> = vec![
            85, 10, 2, 211, 136, 34, 224, 255, 122, 19, 18, 44, 253, 119, 42, 160, 66, 64, 48, 109,
            39, 231, 0, 120, 94, 192, 185, 76, 48, 17, 119, 205, 59, 64, 0, 0, 0, 0, 15, 2, 12,
            194,
        ];

        assert_eq!(
            MsgPosLLH::MSG_ID,
            0x20a,
            "Incorrect message type, expected 0x20a, is {}",
            MsgPosLLH::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgPosLLH(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.78025980704230484e+01),
                    "incorrect value for height, expected 2.78025980704230484e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72512960420791757e+01),
                    "incorrect value for lat, expected 3.72512960420791757e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875055111410575e+02),
                    "incorrect value for lon, expected -1.21875055111410575e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326828000,
                    "incorrect value for tow, expected 326828000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => assert!(false, "Invalid message type! Expected a MsgPosLLH"),
        };
    }
    {
        use sbp::messages::navigation::MsgPosLLH;
        let payload: Vec<u8> = vec![
            85, 10, 2, 211, 136, 34, 200, 3, 123, 19, 225, 237, 238, 90, 42, 160, 66, 64, 59, 143,
            70, 235, 0, 120, 94, 192, 101, 106, 249, 224, 131, 240, 59, 64, 0, 0, 0, 0, 15, 2, 34,
            103,
        ];

        assert_eq!(
            MsgPosLLH::MSG_ID,
            0x20a,
            "Incorrect message type, expected 0x20a, is {}",
            MsgPosLLH::MSG_ID
        );

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::MsgPosLLH(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.79395123108792127e+01),
                    "incorrect value for height, expected 2.79395123108792127e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72512925783773952e+01),
                    "incorrect value for lat, expected 3.72512925783773952e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875056094079739e+02),
                    "incorrect value for lon, expected -1.21875056094079739e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326829000,
                    "incorrect value for tow, expected 326829000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => assert!(false, "Invalid message type! Expected a MsgPosLLH"),
        };
    }
}
