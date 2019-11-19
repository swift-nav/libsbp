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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDopsDepA.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_9() {
    {
        let payload: Vec<u8> = vec![
            85, 6, 2, 246, 215, 14, 8, 48, 39, 0, 180, 0, 190, 0, 170, 0, 160, 0, 150, 0, 121, 170,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 180,
                    "incorrect value for gdop, expected 180, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 160,
                    "incorrect value for hdop, expected 160, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 190,
                    "incorrect value for pdop, expected 190, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 170,
                    "incorrect value for tdop, expected 170, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 2568200,
                    "incorrect value for tow, expected 2568200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 150,
                    "incorrect value for vdop, expected 150, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 6, 2, 246, 215, 14, 240, 51, 39, 0, 180, 0, 190, 0, 170, 0, 160, 0, 150, 0, 78, 169,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 180,
                    "incorrect value for gdop, expected 180, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 160,
                    "incorrect value for hdop, expected 160, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 190,
                    "incorrect value for pdop, expected 190, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 170,
                    "incorrect value for tdop, expected 170, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 2569200,
                    "incorrect value for tow, expected 2569200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 150,
                    "incorrect value for vdop, expected 150, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 6, 2, 246, 215, 14, 216, 55, 39, 0, 180, 0, 190, 0, 170, 0, 160, 0, 150, 0, 71, 218,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 180,
                    "incorrect value for gdop, expected 180, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 160,
                    "incorrect value for hdop, expected 160, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 190,
                    "incorrect value for pdop, expected 190, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 170,
                    "incorrect value for tdop, expected 170, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 2570200,
                    "incorrect value for tow, expected 2570200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 150,
                    "incorrect value for vdop, expected 150, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
