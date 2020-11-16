//
// Copyright (C) 2019 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
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
            85, 10, 255, 238, 238, 9, 1, 2, 3, 10, 255, 10, 2, 2, 255, 2, 14,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new(std::io::Cursor::new(&payload));
        let msg_result = parser.parse();
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
            }
            _ => panic!("Invalid message type! Expected a MsgGroupMeta"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
