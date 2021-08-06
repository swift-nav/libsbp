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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNedGnss.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_navigation_MsgVelNedGnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 46, 2, 0, 16, 22, 168, 230, 233, 29, 251, 255, 255, 255, 0, 0, 0, 0, 246, 255, 255,
            255, 40, 0, 89, 0, 21, 2, 99, 171,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgVelNEDGnss(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x22e,
                    "Incorrect message type, expected 0x22e, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -10,
                    "incorrect value for d, expected -10, is {}",
                    msg.d
                );
                assert_eq!(msg.e, 0, "incorrect value for e, expected 0, is {}", msg.e);
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 40,
                    "incorrect value for h_accuracy, expected 40, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -5,
                    "incorrect value for n, expected -5, is {}",
                    msg.n
                );
                assert_eq!(
                    msg.n_sats, 21,
                    "incorrect value for n_sats, expected 21, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501868200,
                    "incorrect value for tow, expected 501868200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 89,
                    "incorrect value for v_accuracy, expected 89, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDGnss"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
