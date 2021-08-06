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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelEcefGnss.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_navigation_MsgVelEcefGnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 45, 2, 0, 16, 20, 224, 229, 233, 29, 253, 255, 255, 255, 1, 0, 0, 0, 4, 0, 0, 0,
            89, 0, 21, 2, 205, 16,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEFGnss(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x22d,
                    "Incorrect message type, expected 0x22d, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 89,
                    "incorrect value for accuracy, expected 89, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 21,
                    "incorrect value for n_sats, expected 21, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501868000,
                    "incorrect value for tow, expected 501868000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -3,
                    "incorrect value for x, expected -3, is {}",
                    msg.x
                );
                assert_eq!(msg.y, 1, "incorrect value for y, expected 1, is {}", msg.y);
                assert_eq!(msg.z, 4, "incorrect value for z, expected 4, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFGnss"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
