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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagHighLevel.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_integrity_msg_ssr_flag_high_level() {
    {
        let mut payload = Cursor::new(vec![
            85, 185, 11, 66, 0, 31, 180, 0, 0, 0, 3, 0, 104, 1, 0, 0, 6, 0, 10, 20, 0, 30, 0, 40,
            1, 2, 3, 0, 0, 0, 0, 0, 0, 4, 5, 6, 7, 102, 67,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrFlagHighLevel(msg) => {
                assert_eq!(
                    msg.message_type(),
                    3001,
                    "Incorrect message type, expected 3001, is {}",
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
                    msg.stub[6], 104,
                    "incorrect value for stub[6], expected 104, is {}",
                    msg.stub[6]
                );
                assert_eq!(
                    msg.stub[7], 1,
                    "incorrect value for stub[7], expected 1, is {}",
                    msg.stub[7]
                );
                assert_eq!(
                    msg.stub[8], 0,
                    "incorrect value for stub[8], expected 0, is {}",
                    msg.stub[8]
                );
                assert_eq!(
                    msg.stub[9], 0,
                    "incorrect value for stub[9], expected 0, is {}",
                    msg.stub[9]
                );
                assert_eq!(
                    msg.stub[10], 6,
                    "incorrect value for stub[10], expected 6, is {}",
                    msg.stub[10]
                );
                assert_eq!(
                    msg.stub[11], 0,
                    "incorrect value for stub[11], expected 0, is {}",
                    msg.stub[11]
                );
                assert_eq!(
                    msg.stub[12], 10,
                    "incorrect value for stub[12], expected 10, is {}",
                    msg.stub[12]
                );
                assert_eq!(
                    msg.stub[13], 20,
                    "incorrect value for stub[13], expected 20, is {}",
                    msg.stub[13]
                );
                assert_eq!(
                    msg.stub[14], 0,
                    "incorrect value for stub[14], expected 0, is {}",
                    msg.stub[14]
                );
                assert_eq!(
                    msg.stub[15], 30,
                    "incorrect value for stub[15], expected 30, is {}",
                    msg.stub[15]
                );
                assert_eq!(
                    msg.stub[16], 0,
                    "incorrect value for stub[16], expected 0, is {}",
                    msg.stub[16]
                );
                assert_eq!(
                    msg.stub[17], 40,
                    "incorrect value for stub[17], expected 40, is {}",
                    msg.stub[17]
                );
                assert_eq!(
                    msg.stub[18], 1,
                    "incorrect value for stub[18], expected 1, is {}",
                    msg.stub[18]
                );
                assert_eq!(
                    msg.stub[19], 2,
                    "incorrect value for stub[19], expected 2, is {}",
                    msg.stub[19]
                );
                assert_eq!(
                    msg.stub[20], 3,
                    "incorrect value for stub[20], expected 3, is {}",
                    msg.stub[20]
                );
                assert_eq!(
                    msg.stub[21], 0,
                    "incorrect value for stub[21], expected 0, is {}",
                    msg.stub[21]
                );
                assert_eq!(
                    msg.stub[22], 0,
                    "incorrect value for stub[22], expected 0, is {}",
                    msg.stub[22]
                );
                assert_eq!(
                    msg.stub[23], 0,
                    "incorrect value for stub[23], expected 0, is {}",
                    msg.stub[23]
                );
                assert_eq!(
                    msg.stub[24], 0,
                    "incorrect value for stub[24], expected 0, is {}",
                    msg.stub[24]
                );
                assert_eq!(
                    msg.stub[25], 0,
                    "incorrect value for stub[25], expected 0, is {}",
                    msg.stub[25]
                );
                assert_eq!(
                    msg.stub[26], 0,
                    "incorrect value for stub[26], expected 0, is {}",
                    msg.stub[26]
                );
                assert_eq!(
                    msg.stub[27], 4,
                    "incorrect value for stub[27], expected 4, is {}",
                    msg.stub[27]
                );
                assert_eq!(
                    msg.stub[28], 5,
                    "incorrect value for stub[28], expected 5, is {}",
                    msg.stub[28]
                );
                assert_eq!(
                    msg.stub[29], 6,
                    "incorrect value for stub[29], expected 6, is {}",
                    msg.stub[29]
                );
                assert_eq!(
                    msg.stub[30], 7,
                    "incorrect value for stub[30], expected 7, is {}",
                    msg.stub[30]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrFlagHighLevel"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}