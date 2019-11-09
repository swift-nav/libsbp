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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEF.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_19() {
    {
        let payload: Vec<u8> = vec![
            85, 13, 2, 211, 136, 20, 40, 244, 122, 19, 248, 255, 255, 255, 251, 255, 255, 255, 10,
            0, 0, 0, 0, 0, 14, 0, 181, 99,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20d,
                    "Incorrect message type, expected 0x20d, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.x, -8,
                    "incorrect value for x, expected -8, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -5,
                    "incorrect value for y, expected -5, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 10,
                    "incorrect value for z, expected 10, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 13, 2, 211, 136, 20, 28, 246, 122, 19, 244, 255, 255, 255, 238, 255, 255, 255, 11,
            0, 0, 0, 0, 0, 15, 0, 215, 120,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20d,
                    "Incorrect message type, expected 0x20d, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326825500,
                    "incorrect value for tow, expected 326825500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -12,
                    "incorrect value for x, expected -12, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -18,
                    "incorrect value for y, expected -18, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 11,
                    "incorrect value for z, expected 11, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 13, 2, 211, 136, 20, 16, 248, 122, 19, 248, 255, 255, 255, 250, 255, 255, 255, 7,
            0, 0, 0, 0, 0, 15, 0, 248, 221,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20d,
                    "Incorrect message type, expected 0x20d, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.x, -8,
                    "incorrect value for x, expected -8, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -6,
                    "incorrect value for y, expected -6, is {}",
                    msg.y
                );
                assert_eq!(msg.z, 7, "incorrect value for z, expected 7, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 13, 2, 211, 136, 20, 4, 250, 122, 19, 249, 255, 255, 255, 239, 255, 255, 255, 16,
            0, 0, 0, 0, 0, 15, 0, 1, 167,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20d,
                    "Incorrect message type, expected 0x20d, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326826500,
                    "incorrect value for tow, expected 326826500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -7,
                    "incorrect value for x, expected -7, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -17,
                    "incorrect value for y, expected -17, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 16,
                    "incorrect value for z, expected 16, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 13, 2, 211, 136, 20, 248, 251, 122, 19, 247, 255, 255, 255, 243, 255, 255, 255, 14,
            0, 0, 0, 0, 0, 15, 0, 191, 43,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20d,
                    "Incorrect message type, expected 0x20d, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.x, -9,
                    "incorrect value for x, expected -9, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -13,
                    "incorrect value for y, expected -13, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 14,
                    "incorrect value for z, expected 14, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
