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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTime.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_10() {
    {
        let payload: Vec<u8> = vec![
            85, 2, 1, 211, 136, 11, 128, 7, 40, 244, 122, 19, 244, 139, 2, 0, 0, 34, 152,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTime(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x102,
                    "Incorrect message type, expected 0x102, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 166900,
                    "incorrect value for ns_residual, expected 166900, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326825000,
                    "incorrect value for tow, expected 326825000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTime"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 2, 1, 211, 136, 11, 128, 7, 28, 246, 122, 19, 126, 234, 3, 0, 0, 65, 3,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTime(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x102,
                    "Incorrect message type, expected 0x102, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 256638,
                    "incorrect value for ns_residual, expected 256638, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326825500,
                    "incorrect value for tow, expected 326825500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTime"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 2, 1, 211, 136, 11, 128, 7, 16, 248, 122, 19, 129, 12, 4, 0, 0, 12, 84,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTime(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x102,
                    "Incorrect message type, expected 0x102, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 265345,
                    "incorrect value for ns_residual, expected 265345, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326826000,
                    "incorrect value for tow, expected 326826000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTime"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 2, 1, 211, 136, 11, 128, 7, 4, 250, 122, 19, 137, 204, 4, 0, 0, 50, 165,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTime(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x102,
                    "Incorrect message type, expected 0x102, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 314505,
                    "incorrect value for ns_residual, expected 314505, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326826500,
                    "incorrect value for tow, expected 326826500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTime"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 2, 1, 211, 136, 11, 128, 7, 248, 251, 122, 19, 181, 137, 5, 0, 0, 180, 33,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTime(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x102,
                    "Incorrect message type, expected 0x102, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 362933,
                    "incorrect value for ns_residual, expected 362933, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326827000,
                    "incorrect value for tow, expected 326827000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTime"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
