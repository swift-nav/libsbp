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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagSatellites.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_integrity_msg_ssr_flag_satellites() {
    {
        let mut payload = Cursor::new(vec![
            85, 189, 11, 66, 0, 15, 180, 0, 0, 0, 3, 0, 1, 2, 3, 4, 5, 3, 10, 11, 12, 110, 165,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrFlagSatellites(msg) => {
                assert_eq!(
                    msg.message_type(),
                    3005,
                    "Incorrect message type, expected 3005, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.stub[0], 180,
                    "incorrect value for stub[0], expected 180, is {}",
                    msg.stub[0]
                );
                assert_eq!(
                    msg.stub[1], 0,
                    "incorrect value for stub[1], expected 0, is {}",
                    msg.stub[1]
                );
                assert_eq!(
                    msg.stub[2], 0,
                    "incorrect value for stub[2], expected 0, is {}",
                    msg.stub[2]
                );
                assert_eq!(
                    msg.stub[3], 0,
                    "incorrect value for stub[3], expected 0, is {}",
                    msg.stub[3]
                );
                assert_eq!(
                    msg.stub[4], 3,
                    "incorrect value for stub[4], expected 3, is {}",
                    msg.stub[4]
                );
                assert_eq!(
                    msg.stub[5], 0,
                    "incorrect value for stub[5], expected 0, is {}",
                    msg.stub[5]
                );
                assert_eq!(
                    msg.stub[6], 1,
                    "incorrect value for stub[6], expected 1, is {}",
                    msg.stub[6]
                );
                assert_eq!(
                    msg.stub[7], 2,
                    "incorrect value for stub[7], expected 2, is {}",
                    msg.stub[7]
                );
                assert_eq!(
                    msg.stub[8], 3,
                    "incorrect value for stub[8], expected 3, is {}",
                    msg.stub[8]
                );
                assert_eq!(
                    msg.stub[9], 4,
                    "incorrect value for stub[9], expected 4, is {}",
                    msg.stub[9]
                );
                assert_eq!(
                    msg.stub[10], 5,
                    "incorrect value for stub[10], expected 5, is {}",
                    msg.stub[10]
                );
                assert_eq!(
                    msg.stub[11], 3,
                    "incorrect value for stub[11], expected 3, is {}",
                    msg.stub[11]
                );
                assert_eq!(
                    msg.stub[12], 10,
                    "incorrect value for stub[12], expected 10, is {}",
                    msg.stub[12]
                );
                assert_eq!(
                    msg.stub[13], 11,
                    "incorrect value for stub[13], expected 11, is {}",
                    msg.stub[13]
                );
                assert_eq!(
                    msg.stub[14], 12,
                    "incorrect value for stub[14], expected 12, is {}",
                    msg.stub[14]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrFlagSatellites"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
