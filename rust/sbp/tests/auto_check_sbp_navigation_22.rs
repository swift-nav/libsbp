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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNED.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_22() {
    {
        let payload: Vec<u8> = vec![
            85, 14, 2, 211, 136, 22, 40, 244, 122, 19, 3, 0, 0, 0, 252, 255, 255, 255, 243, 255,
            255, 255, 0, 0, 0, 0, 14, 0, 86, 209,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelNED(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20e,
                    "Incorrect message type, expected 0x20e, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -13,
                    "incorrect value for d, expected -13, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, -4,
                    "incorrect value for e, expected -4, is {}",
                    msg.e
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
                assert_eq!(msg.n, 3, "incorrect value for n, expected 3, is {}", msg.n);
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
            _ => panic!("Invalid message type! Expected a MsgVelNED"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 14, 2, 211, 136, 22, 28, 246, 122, 19, 252, 255, 255, 255, 255, 255, 255, 255, 232,
            255, 255, 255, 0, 0, 0, 0, 15, 0, 16, 228,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelNED(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20e,
                    "Incorrect message type, expected 0x20e, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -24,
                    "incorrect value for d, expected -24, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, -1,
                    "incorrect value for e, expected -1, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -4,
                    "incorrect value for n, expected -4, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNED"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 14, 2, 211, 136, 22, 16, 248, 122, 19, 0, 0, 0, 0, 253, 255, 255, 255, 244, 255,
            255, 255, 0, 0, 0, 0, 15, 0, 11, 164,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelNED(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20e,
                    "Incorrect message type, expected 0x20e, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -12,
                    "incorrect value for d, expected -12, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, -3,
                    "incorrect value for e, expected -3, is {}",
                    msg.e
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
                assert_eq!(msg.n, 0, "incorrect value for n, expected 0, is {}", msg.n);
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
            _ => panic!("Invalid message type! Expected a MsgVelNED"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 14, 2, 211, 136, 22, 4, 250, 122, 19, 2, 0, 0, 0, 3, 0, 0, 0, 232, 255, 255, 255,
            0, 0, 0, 0, 15, 0, 152, 208,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelNED(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20e,
                    "Incorrect message type, expected 0x20e, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -24,
                    "incorrect value for d, expected -24, is {}",
                    msg.d
                );
                assert_eq!(msg.e, 3, "incorrect value for e, expected 3, is {}", msg.e);
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
                assert_eq!(msg.n, 2, "incorrect value for n, expected 2, is {}", msg.n);
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNED"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 14, 2, 211, 136, 22, 248, 251, 122, 19, 1, 0, 0, 0, 0, 0, 0, 0, 235, 255, 255, 255,
            0, 0, 0, 0, 15, 0, 182, 120,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelNED(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20e,
                    "Incorrect message type, expected 0x20e, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -21,
                    "incorrect value for d, expected -21, is {}",
                    msg.d
                );
                assert_eq!(msg.e, 0, "incorrect value for e, expected 0, is {}", msg.e);
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
                assert_eq!(msg.n, 1, "incorrect value for n, expected 1, is {}", msg.n);
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
            _ => panic!("Invalid message type! Expected a MsgVelNED"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
