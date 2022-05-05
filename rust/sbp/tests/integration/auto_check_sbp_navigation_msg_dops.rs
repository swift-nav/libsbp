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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDops.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_dops() {
    {
        let mut payload = Cursor::new(vec![
            85, 8, 2, 66, 0, 15, 100, 0, 0, 0, 2, 0, 6, 0, 5, 0, 5, 0, 5, 0, 0, 244, 4,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgDops(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x208,
                    "Incorrect message type, expected 0x208, is {}",
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
                    msg.gdop, 2,
                    "incorrect value for gdop, expected 2, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 5,
                    "incorrect value for hdop, expected 5, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 6,
                    "incorrect value for pdop, expected 6, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 5,
                    "incorrect value for tdop, expected 5, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 100,
                    "incorrect value for tow, expected 100, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 5,
                    "incorrect value for vdop, expected 5, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDops"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
