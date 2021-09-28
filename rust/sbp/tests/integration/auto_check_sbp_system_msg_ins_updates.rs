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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgInsUpdates.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_system_msg_ins_updates() {
    {
        let mut payload = Cursor::new(vec![
            85, 6, 255, 21, 3, 10, 84, 229, 17, 30, 0, 0, 0, 0, 0, 0, 81, 63,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgInsUpdates(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xff06,
                    "Incorrect message type, expected 0xff06, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x315,
                    "incorrect sender id, expected 0x315, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gnsspos, 0,
                    "incorrect value for gnsspos, expected 0, is {}",
                    msg.gnsspos
                );
                assert_eq!(
                    msg.gnssvel, 0,
                    "incorrect value for gnssvel, expected 0, is {}",
                    msg.gnssvel
                );
                assert_eq!(
                    msg.nhc, 0,
                    "incorrect value for nhc, expected 0, is {}",
                    msg.nhc
                );
                assert_eq!(
                    msg.speed, 0,
                    "incorrect value for speed, expected 0, is {}",
                    msg.speed
                );
                assert_eq!(
                    msg.tow, 504489300,
                    "incorrect value for tow, expected 504489300, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wheelticks, 0,
                    "incorrect value for wheelticks, expected 0, is {}",
                    msg.wheelticks
                );
                assert_eq!(
                    msg.zerovel, 0,
                    "incorrect value for zerovel, expected 0, is {}",
                    msg.zerovel
                );
            }
            _ => panic!("Invalid message type! Expected a MsgInsUpdates"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
