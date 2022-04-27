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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/sbas/test_MsgSbasRaw.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_sbas_msg_sbas_raw() {
    {
        let mut payload = Cursor::new(vec![
            85, 119, 119, 28, 200, 34, 131, 2, 201, 228, 233, 29, 4, 23, 255, 0, 23, 255, 0, 23,
            255, 127, 240, 2, 255, 192, 3, 127, 247, 255, 127, 247, 255, 229, 229, 238, 170, 175,
            255, 240, 167, 14,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSbasRaw(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x7777,
                    "Incorrect message type, expected 0x7777, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc81c,
                    "incorrect sender id, expected 0xc81c, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.data[0], 23,
                    "incorrect value for data[0], expected 23, is {}",
                    msg.data[0]
                );
                assert_eq!(
                    msg.data[1], 255,
                    "incorrect value for data[1], expected 255, is {}",
                    msg.data[1]
                );
                assert_eq!(
                    msg.data[2], 0,
                    "incorrect value for data[2], expected 0, is {}",
                    msg.data[2]
                );
                assert_eq!(
                    msg.data[3], 23,
                    "incorrect value for data[3], expected 23, is {}",
                    msg.data[3]
                );
                assert_eq!(
                    msg.data[4], 255,
                    "incorrect value for data[4], expected 255, is {}",
                    msg.data[4]
                );
                assert_eq!(
                    msg.data[5], 0,
                    "incorrect value for data[5], expected 0, is {}",
                    msg.data[5]
                );
                assert_eq!(
                    msg.data[6], 23,
                    "incorrect value for data[6], expected 23, is {}",
                    msg.data[6]
                );
                assert_eq!(
                    msg.data[7], 255,
                    "incorrect value for data[7], expected 255, is {}",
                    msg.data[7]
                );
                assert_eq!(
                    msg.data[8], 127,
                    "incorrect value for data[8], expected 127, is {}",
                    msg.data[8]
                );
                assert_eq!(
                    msg.data[9], 240,
                    "incorrect value for data[9], expected 240, is {}",
                    msg.data[9]
                );
                assert_eq!(
                    msg.data[10], 2,
                    "incorrect value for data[10], expected 2, is {}",
                    msg.data[10]
                );
                assert_eq!(
                    msg.data[11], 255,
                    "incorrect value for data[11], expected 255, is {}",
                    msg.data[11]
                );
                assert_eq!(
                    msg.data[12], 192,
                    "incorrect value for data[12], expected 192, is {}",
                    msg.data[12]
                );
                assert_eq!(
                    msg.data[13], 3,
                    "incorrect value for data[13], expected 3, is {}",
                    msg.data[13]
                );
                assert_eq!(
                    msg.data[14], 127,
                    "incorrect value for data[14], expected 127, is {}",
                    msg.data[14]
                );
                assert_eq!(
                    msg.data[15], 247,
                    "incorrect value for data[15], expected 247, is {}",
                    msg.data[15]
                );
                assert_eq!(
                    msg.data[16], 255,
                    "incorrect value for data[16], expected 255, is {}",
                    msg.data[16]
                );
                assert_eq!(
                    msg.data[17], 127,
                    "incorrect value for data[17], expected 127, is {}",
                    msg.data[17]
                );
                assert_eq!(
                    msg.data[18], 247,
                    "incorrect value for data[18], expected 247, is {}",
                    msg.data[18]
                );
                assert_eq!(
                    msg.data[19], 255,
                    "incorrect value for data[19], expected 255, is {}",
                    msg.data[19]
                );
                assert_eq!(
                    msg.data[20], 229,
                    "incorrect value for data[20], expected 229, is {}",
                    msg.data[20]
                );
                assert_eq!(
                    msg.data[21], 229,
                    "incorrect value for data[21], expected 229, is {}",
                    msg.data[21]
                );
                assert_eq!(
                    msg.data[22], 238,
                    "incorrect value for data[22], expected 238, is {}",
                    msg.data[22]
                );
                assert_eq!(
                    msg.data[23], 170,
                    "incorrect value for data[23], expected 170, is {}",
                    msg.data[23]
                );
                assert_eq!(
                    msg.data[24], 175,
                    "incorrect value for data[24], expected 175, is {}",
                    msg.data[24]
                );
                assert_eq!(
                    msg.data[25], 255,
                    "incorrect value for data[25], expected 255, is {}",
                    msg.data[25]
                );
                assert_eq!(
                    msg.data[26], 240,
                    "incorrect value for data[26], expected 240, is {}",
                    msg.data[26]
                );
                assert_eq!(
                    msg.message_type, 4,
                    "incorrect value for message_type, expected 4, is {}",
                    msg.message_type
                );
                assert_eq!(
                    msg.sid.code, 2,
                    "incorrect value for sid.code, expected 2, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 131,
                    "incorrect value for sid.sat, expected 131, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.tow, 501867721,
                    "incorrect value for tow, expected 501867721, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSbasRaw"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
