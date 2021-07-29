//
// Copyright (C) 2019-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgGroupMeta.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_system_MsgGroupMeta() {
    {
        let mut payload = Cursor::new(vec![
            85, 10, 255, 238, 238, 9, 1, 2, 3, 10, 255, 10, 2, 2, 255, 2, 14,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
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
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 10, 255, 21, 3, 31, 1, 1, 14, 2, 1, 3, 1, 10, 2, 17, 2, 9, 2, 20, 2, 14, 2, 18, 2,
            13, 2, 21, 2, 33, 2, 3, 255, 6, 255, 14, 255, 82, 154,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
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
                    sender_id, 0x315,
                    "incorrect sender id, expected 0x315, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.group_id, 1,
                    "incorrect value for group_id, expected 1, is {}",
                    msg.group_id
                );
                assert_eq!(
                    msg.group_msgs[0], 258,
                    "incorrect value for group_msgs[0], expected 258, is {}",
                    msg.group_msgs[0]
                );
                assert_eq!(
                    msg.group_msgs[1], 259,
                    "incorrect value for group_msgs[1], expected 259, is {}",
                    msg.group_msgs[1]
                );
                assert_eq!(
                    msg.group_msgs[2], 522,
                    "incorrect value for group_msgs[2], expected 522, is {}",
                    msg.group_msgs[2]
                );
                assert_eq!(
                    msg.group_msgs[3], 529,
                    "incorrect value for group_msgs[3], expected 529, is {}",
                    msg.group_msgs[3]
                );
                assert_eq!(
                    msg.group_msgs[4], 521,
                    "incorrect value for group_msgs[4], expected 521, is {}",
                    msg.group_msgs[4]
                );
                assert_eq!(
                    msg.group_msgs[5], 532,
                    "incorrect value for group_msgs[5], expected 532, is {}",
                    msg.group_msgs[5]
                );
                assert_eq!(
                    msg.group_msgs[6], 526,
                    "incorrect value for group_msgs[6], expected 526, is {}",
                    msg.group_msgs[6]
                );
                assert_eq!(
                    msg.group_msgs[7], 530,
                    "incorrect value for group_msgs[7], expected 530, is {}",
                    msg.group_msgs[7]
                );
                assert_eq!(
                    msg.group_msgs[8], 525,
                    "incorrect value for group_msgs[8], expected 525, is {}",
                    msg.group_msgs[8]
                );
                assert_eq!(
                    msg.group_msgs[9], 533,
                    "incorrect value for group_msgs[9], expected 533, is {}",
                    msg.group_msgs[9]
                );
                assert_eq!(
                    msg.group_msgs[10], 545,
                    "incorrect value for group_msgs[10], expected 545, is {}",
                    msg.group_msgs[10]
                );
                assert_eq!(
                    msg.group_msgs[11], 65283,
                    "incorrect value for group_msgs[11], expected 65283, is {}",
                    msg.group_msgs[11]
                );
                assert_eq!(
                    msg.group_msgs[12], 65286,
                    "incorrect value for group_msgs[12], expected 65286, is {}",
                    msg.group_msgs[12]
                );
                assert_eq!(
                    msg.group_msgs[13], 65294,
                    "incorrect value for group_msgs[13], expected 65294, is {}",
                    msg.group_msgs[13]
                );
                assert_eq!(
                    msg.n_group_msgs, 14,
                    "incorrect value for n_group_msgs, expected 14, is {}",
                    msg.n_group_msgs
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGroupMeta"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
