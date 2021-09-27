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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgStartup.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_system_msg_startup() {
    {
        let mut payload = Cursor::new(vec![85, 0, 255, 66, 0, 4, 0, 0, 0, 0, 70, 160]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgStartup(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xff00,
                    "Incorrect message type, expected 0xff00, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cause, 0,
                    "incorrect value for cause, expected 0, is {}",
                    msg.cause
                );
                assert_eq!(
                    msg.reserved, 0,
                    "incorrect value for reserved, expected 0, is {}",
                    msg.reserved
                );
                assert_eq!(
                    msg.startup_type, 0,
                    "incorrect value for startup_type, expected 0, is {}",
                    msg.startup_type
                );
            }
            _ => panic!("Invalid message type! Expected a MsgStartup"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![85, 0, 255, 195, 4, 4, 0, 0, 0, 0, 127, 181]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgStartup(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xff00,
                    "Incorrect message type, expected 0xff00, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cause, 0,
                    "incorrect value for cause, expected 0, is {}",
                    msg.cause
                );
                assert_eq!(
                    msg.reserved, 0,
                    "incorrect value for reserved, expected 0, is {}",
                    msg.reserved
                );
                assert_eq!(
                    msg.startup_type, 0,
                    "incorrect value for startup_type, expected 0, is {}",
                    msg.startup_type
                );
            }
            _ => panic!("Invalid message type! Expected a MsgStartup"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
