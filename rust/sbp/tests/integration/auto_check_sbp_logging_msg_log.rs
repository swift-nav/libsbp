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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgLog.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_logging_msg_log() {
    {
        let mut payload = Cursor::new(vec![
            85, 1, 4, 10, 9, 44, 6, 70, 105, 108, 116, 101, 114, 101, 100, 32, 97, 108, 108, 32,
            111, 98, 115, 32, 102, 114, 111, 109, 32, 50, 51, 49, 52, 32, 97, 116, 32, 116, 111,
            119, 32, 56, 51, 46, 53, 51, 57, 48, 49, 57, 177, 163,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgLog(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x0401,
                    "Incorrect message type, expected 0x0401, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x90a,
                    "incorrect sender id, expected 0x90a, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.level, 6,
                    "incorrect value for level, expected 6, is {}",
                    msg.level
                );
                assert_eq!(
                    msg.text.to_string(),
                    "Filtered all obs from 2314 at tow 83.539019".to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "Filtered all obs from 2314 at tow 83.539019".to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLog"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
