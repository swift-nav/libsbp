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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ext_events/test_MsgExtEvent.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_ext_events_msg_ext_event() {
    {
        let mut payload = Cursor::new(vec![
            85, 1, 1, 245, 6, 12, 48, 7, 199, 216, 49, 15, 202, 65, 15, 0, 3, 0, 62, 204,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgExtEvent(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x101,
                    "Incorrect message type, expected 0x101, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6f5,
                    "incorrect sender id, expected 0x6f5, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 3,
                    "incorrect value for flags, expected 3, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 999882,
                    "incorrect value for ns_residual, expected 999882, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.pin, 0,
                    "incorrect value for pin, expected 0, is {}",
                    msg.pin
                );
                assert_eq!(
                    msg.tow, 254924999,
                    "incorrect value for tow, expected 254924999, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1840,
                    "incorrect value for wn, expected 1840, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgExtEvent"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
