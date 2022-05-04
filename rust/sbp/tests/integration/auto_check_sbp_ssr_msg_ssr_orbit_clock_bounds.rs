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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockBounds.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_ssr_msg_ssr_orbit_clock_bounds() {
    {
        let mut payload = Cursor::new(vec![
            85, 222, 5, 66, 0, 31, 180, 0, 0, 0, 3, 0, 1, 2, 3, 48, 15, 1, 2, 24, 39, 38, 37, 1, 2,
            3, 39, 1, 3, 39, 38, 37, 1, 2, 3, 39, 1, 21, 85,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrOrbitClockBounds(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1502,
                    "Incorrect message type, expected 1502, is {}",
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
                    msg.stub[9], 48,
                    "incorrect value for stub[9], expected 48, is {}",
                    msg.stub[9]
                );
                assert_eq!(
                    msg.stub[10], 15,
                    "incorrect value for stub[10], expected 15, is {}",
                    msg.stub[10]
                );
                assert_eq!(
                    msg.stub[11], 1,
                    "incorrect value for stub[11], expected 1, is {}",
                    msg.stub[11]
                );
                assert_eq!(
                    msg.stub[12], 2,
                    "incorrect value for stub[12], expected 2, is {}",
                    msg.stub[12]
                );
                assert_eq!(
                    msg.stub[13], 24,
                    "incorrect value for stub[13], expected 24, is {}",
                    msg.stub[13]
                );
                assert_eq!(
                    msg.stub[14], 39,
                    "incorrect value for stub[14], expected 39, is {}",
                    msg.stub[14]
                );
                assert_eq!(
                    msg.stub[15], 38,
                    "incorrect value for stub[15], expected 38, is {}",
                    msg.stub[15]
                );
                assert_eq!(
                    msg.stub[16], 37,
                    "incorrect value for stub[16], expected 37, is {}",
                    msg.stub[16]
                );
                assert_eq!(
                    msg.stub[17], 1,
                    "incorrect value for stub[17], expected 1, is {}",
                    msg.stub[17]
                );
                assert_eq!(
                    msg.stub[18], 2,
                    "incorrect value for stub[18], expected 2, is {}",
                    msg.stub[18]
                );
                assert_eq!(
                    msg.stub[19], 3,
                    "incorrect value for stub[19], expected 3, is {}",
                    msg.stub[19]
                );
                assert_eq!(
                    msg.stub[20], 39,
                    "incorrect value for stub[20], expected 39, is {}",
                    msg.stub[20]
                );
                assert_eq!(
                    msg.stub[21], 1,
                    "incorrect value for stub[21], expected 1, is {}",
                    msg.stub[21]
                );
                assert_eq!(
                    msg.stub[22], 3,
                    "incorrect value for stub[22], expected 3, is {}",
                    msg.stub[22]
                );
                assert_eq!(
                    msg.stub[23], 39,
                    "incorrect value for stub[23], expected 39, is {}",
                    msg.stub[23]
                );
                assert_eq!(
                    msg.stub[24], 38,
                    "incorrect value for stub[24], expected 38, is {}",
                    msg.stub[24]
                );
                assert_eq!(
                    msg.stub[25], 37,
                    "incorrect value for stub[25], expected 37, is {}",
                    msg.stub[25]
                );
                assert_eq!(
                    msg.stub[26], 1,
                    "incorrect value for stub[26], expected 1, is {}",
                    msg.stub[26]
                );
                assert_eq!(
                    msg.stub[27], 2,
                    "incorrect value for stub[27], expected 2, is {}",
                    msg.stub[27]
                );
                assert_eq!(
                    msg.stub[28], 3,
                    "incorrect value for stub[28], expected 3, is {}",
                    msg.stub[28]
                );
                assert_eq!(
                    msg.stub[29], 39,
                    "incorrect value for stub[29], expected 39, is {}",
                    msg.stub[29]
                );
                assert_eq!(
                    msg.stub[30], 1,
                    "incorrect value for stub[30], expected 1, is {}",
                    msg.stub[30]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrOrbitClockBounds"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
