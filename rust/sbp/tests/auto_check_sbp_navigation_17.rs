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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLHDepA.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_17() {
    {
        let payload: Vec<u8> = vec![
            85, 1, 2, 246, 215, 34, 20, 46, 39, 0, 250, 29, 226, 186, 235, 182, 66, 64, 19, 203,
            51, 196, 24, 139, 94, 192, 31, 157, 160, 232, 122, 115, 81, 64, 0, 0, 0, 0, 9, 0, 236,
            139,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosLLHDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.get_message_type()
                );
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
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.98043767517560667e+01),
                    "incorrect value for height, expected 6.98043767517560667e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290689090812094e+01),
                    "incorrect value for lat, expected 3.74290689090812094e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173386622027735e+02),
                    "incorrect value for lon, expected -1.22173386622027735e+02, is {:e}",
                    msg.lon
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 1, 2, 246, 215, 34, 20, 46, 39, 0, 161, 51, 75, 148, 235, 182, 66, 64, 36, 41, 246,
            30, 25, 139, 94, 192, 254, 218, 49, 127, 10, 108, 81, 64, 0, 0, 0, 0, 9, 1, 25, 117,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosLLHDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.96881406771535410e+01),
                    "incorrect value for height, expected 6.96881406771535410e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290643088527375e+01),
                    "incorrect value for lat, expected 3.74290643088527375e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173408260718645e+02),
                    "incorrect value for lon, expected -1.22173408260718645e+02, is {:e}",
                    msg.lon
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 1, 2, 246, 215, 34, 120, 46, 39, 0, 56, 214, 210, 65, 235, 182, 66, 64, 13, 46,
            132, 80, 25, 139, 94, 192, 22, 143, 46, 234, 191, 95, 81, 64, 0, 0, 0, 0, 9, 0, 174,
            105,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosLLHDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.get_message_type()
                );
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
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.94960885481526418e+01),
                    "incorrect value for height, expected 6.94960885481526418e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290544776417278e+01),
                    "incorrect value for lat, expected 3.74290544776417278e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173420075494690e+02),
                    "incorrect value for lon, expected -1.22173420075494690e+02, is {:e}",
                    msg.lon
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 1, 2, 246, 215, 34, 120, 46, 39, 0, 251, 117, 115, 140, 235, 182, 66, 64, 152, 134,
            167, 12, 25, 139, 94, 192, 160, 22, 137, 253, 4, 108, 81, 64, 0, 0, 0, 0, 9, 1, 122,
            127,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosLLHDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.96878045881990147e+01),
                    "incorrect value for height, expected 6.96878045881990147e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290633739255654e+01),
                    "incorrect value for lat, expected 3.74290633739255654e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173403895949718e+02),
                    "incorrect value for lon, expected -1.22173403895949718e+02, is {:e}",
                    msg.lon
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 1, 2, 246, 215, 34, 220, 46, 39, 0, 51, 124, 88, 251, 235, 182, 66, 64, 153, 5,
            250, 16, 25, 139, 94, 192, 146, 60, 187, 219, 152, 161, 81, 64, 0, 0, 0, 0, 9, 0, 194,
            158,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosLLHDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.get_message_type()
                );
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
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(7.05249547317964982e+01),
                    "incorrect value for height, expected 7.05249547317964982e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290765935951626e+01),
                    "incorrect value for lat, expected 3.74290765935951626e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173404926454523e+02),
                    "incorrect value for lon, expected -1.22173404926454523e+02, is {:e}",
                    msg.lon
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
