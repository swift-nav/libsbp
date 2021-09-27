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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgAngularRate.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_orientation_msg_angular_rate() {
    {
        let mut payload = Cursor::new(vec![
            85, 34, 2, 66, 0, 17, 2, 0, 0, 0, 2, 0, 0, 0, 5, 0, 0, 0, 2, 0, 0, 0, 0, 88, 70,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAngularRate(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x222,
                    "Incorrect message type, expected 0x222, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.tow, 2,
                    "incorrect value for tow, expected 2, is {}",
                    msg.tow
                );
                assert_eq!(msg.x, 2, "incorrect value for x, expected 2, is {}", msg.x);
                assert_eq!(msg.y, 5, "incorrect value for y, expected 5, is {}", msg.y);
                assert_eq!(msg.z, 2, "incorrect value for z, expected 2, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgAngularRate"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
