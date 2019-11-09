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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEFDepA.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_21() {
    {
        let payload: Vec<u8> = vec![
            85, 4, 2, 246, 215, 20, 20, 46, 39, 0, 218, 11, 0, 0, 134, 245, 255, 255, 163, 252,
            255, 255, 0, 0, 9, 0, 80, 236,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.get_message_type()
                );
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
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
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
                    msg.x, 3034,
                    "incorrect value for x, expected 3034, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -2682,
                    "incorrect value for y, expected -2682, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -861,
                    "incorrect value for z, expected -861, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 4, 2, 246, 215, 20, 120, 46, 39, 0, 68, 11, 0, 0, 24, 246, 255, 255, 220, 252, 255,
            255, 0, 0, 9, 0, 248, 138,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.get_message_type()
                );
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
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
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
                    msg.x, 2884,
                    "incorrect value for x, expected 2884, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -2536,
                    "incorrect value for y, expected -2536, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -804,
                    "incorrect value for z, expected -804, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 4, 2, 246, 215, 20, 220, 46, 39, 0, 21, 11, 0, 0, 77, 246, 255, 255, 247, 252, 255,
            255, 0, 0, 9, 0, 25, 174,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.get_message_type()
                );
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
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
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
                    msg.x, 2837,
                    "incorrect value for x, expected 2837, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -2483,
                    "incorrect value for y, expected -2483, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -777,
                    "incorrect value for z, expected -777, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 4, 2, 246, 215, 20, 64, 47, 39, 0, 121, 11, 0, 0, 2, 246, 255, 255, 234, 252, 255,
            255, 0, 0, 9, 0, 195, 228,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.get_message_type()
                );
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
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
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
                    msg.x, 2937,
                    "incorrect value for x, expected 2937, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -2558,
                    "incorrect value for y, expected -2558, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -790,
                    "incorrect value for z, expected -790, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 4, 2, 246, 215, 20, 164, 47, 39, 0, 31, 11, 0, 0, 93, 246, 255, 255, 16, 253, 255,
            255, 0, 0, 9, 0, 219, 164,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.get_message_type()
                );
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
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
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
                    msg.x, 2847,
                    "incorrect value for x, expected 2847, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -2467,
                    "incorrect value for y, expected -2467, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -752,
                    "incorrect value for z, expected -752, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
