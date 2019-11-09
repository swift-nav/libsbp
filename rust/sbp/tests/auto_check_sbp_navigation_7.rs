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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNEDDepA.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_7() {
    {
        let payload: Vec<u8> = vec![
            85, 3, 2, 246, 215, 22, 20, 46, 39, 0, 243, 134, 254, 255, 234, 153, 255, 255, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 1, 93, 193,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -26134,
                    "incorrect value for e, expected -26134, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -96525,
                    "incorrect value for n, expected -96525, is {}",
                    msg.n
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
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 3, 2, 246, 215, 22, 120, 46, 39, 0, 139, 134, 254, 255, 109, 155, 255, 255, 0, 0,
            0, 0, 0, 0, 0, 0, 9, 1, 38, 39,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -25747,
                    "incorrect value for e, expected -25747, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -96629,
                    "incorrect value for n, expected -96629, is {}",
                    msg.n
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
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 3, 2, 246, 215, 22, 220, 46, 39, 0, 37, 134, 254, 255, 240, 156, 255, 255, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 1, 58, 133,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -25360,
                    "incorrect value for e, expected -25360, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -96731,
                    "incorrect value for n, expected -96731, is {}",
                    msg.n
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
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 3, 2, 246, 215, 22, 64, 47, 39, 0, 193, 133, 254, 255, 115, 158, 255, 255, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 1, 56, 214,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -24973,
                    "incorrect value for e, expected -24973, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -96831,
                    "incorrect value for n, expected -96831, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 3, 2, 246, 215, 22, 164, 47, 39, 0, 93, 133, 254, 255, 246, 159, 255, 255, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 1, 234, 244,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -24586,
                    "incorrect value for e, expected -24586, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -96931,
                    "incorrect value for n, expected -96931, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
