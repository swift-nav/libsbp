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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgGroupMeta.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_system_36() {
    {
        let payload: Vec<u8> = vec![
            85, 10, 255, 238, 238, 19, 1, 192, 7, 64, 226, 1, 0, 0, 0, 0, 0, 3, 3, 10, 255, 10, 2,
            2, 255, 253, 141,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgGroupMeta(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0xFF0A,
                    "Incorrect message type, expected 0xFF0A, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xEEEE,
                    "incorrect sender id, expected 0xEEEE, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 3,
                    "incorrect value for flags, expected 3, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.group_id, 1,
                    "incorrect value for group_id, expected 1, is {}",
                    msg.group_id
                );
                assert_eq!(
                    msg.group_msgs[0], 65290,
                    "incorrect value for group_msgs[0], expected 65290, is {}",
                    msg.group_msgs[0]
                );
                assert_eq!(
                    msg.group_msgs[1], 522,
                    "incorrect value for group_msgs[1], expected 522, is {}",
                    msg.group_msgs[1]
                );
                assert_eq!(
                    msg.group_msgs[2], 65282,
                    "incorrect value for group_msgs[2], expected 65282, is {}",
                    msg.group_msgs[2]
                );
                assert_eq!(
                    msg.n_group_msgs, 3,
                    "incorrect value for n_group_msgs, expected 3, is {}",
                    msg.n_group_msgs
                );
                assert_eq!(
                    msg.ns_residual, 0,
                    "incorrect value for ns_residual, expected 0, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tom, 123456,
                    "incorrect value for tom, expected 123456, is {}",
                    msg.tom
                );
                assert_eq!(
                    msg.wn, 1984,
                    "incorrect value for wn, expected 1984, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGroupMeta"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
