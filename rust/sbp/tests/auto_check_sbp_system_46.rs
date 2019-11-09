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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_system.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_system_46() {
    {
        let payload: Vec<u8> = vec![85, 0, 255, 195, 4, 4, 0, 0, 0, 0, 127, 181];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgStartup(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0xff00,
                    "Incorrect message type, expected 0xff00, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.reserved, 0,
                    "incorrect value for reserved, expected 0, is {}",
                    msg.reserved
                );
            }
            _ => panic!("Invalid message type! Expected a MsgStartup"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![85, 255, 255, 195, 4, 4, 0, 0, 0, 0, 66, 57];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgHeartbeat(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0xffff,
                    "Incorrect message type, expected 0xffff, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
            }
            _ => panic!("Invalid message type! Expected a MsgHeartbeat"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
