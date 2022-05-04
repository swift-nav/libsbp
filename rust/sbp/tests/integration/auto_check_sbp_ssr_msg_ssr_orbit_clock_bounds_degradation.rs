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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockBoundsDegradation.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_ssr_msg_ssr_orbit_clock_bounds_degradation() {
    {
        let mut payload = Cursor::new(vec![
            85, 223, 5, 66, 0, 28, 180, 0, 0, 0, 3, 0, 1, 2, 3, 48, 15, 1, 10, 0, 0, 0, 0, 0, 0, 0,
            200, 199, 198, 197, 196, 195, 194, 193, 200, 117,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrOrbitClockBoundsDegradation(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1503,
                    "Incorrect message type, expected 1503, is {}",
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
                    msg.stub[12], 10,
                    "incorrect value for stub[12], expected 10, is {}",
                    msg.stub[12]
                );
                assert_eq!(
                    msg.stub[13], 0,
                    "incorrect value for stub[13], expected 0, is {}",
                    msg.stub[13]
                );
                assert_eq!(
                    msg.stub[14], 0,
                    "incorrect value for stub[14], expected 0, is {}",
                    msg.stub[14]
                );
                assert_eq!(
                    msg.stub[15], 0,
                    "incorrect value for stub[15], expected 0, is {}",
                    msg.stub[15]
                );
                assert_eq!(
                    msg.stub[16], 0,
                    "incorrect value for stub[16], expected 0, is {}",
                    msg.stub[16]
                );
                assert_eq!(
                    msg.stub[17], 0,
                    "incorrect value for stub[17], expected 0, is {}",
                    msg.stub[17]
                );
                assert_eq!(
                    msg.stub[18], 0,
                    "incorrect value for stub[18], expected 0, is {}",
                    msg.stub[18]
                );
                assert_eq!(
                    msg.stub[19], 0,
                    "incorrect value for stub[19], expected 0, is {}",
                    msg.stub[19]
                );
                assert_eq!(
                    msg.stub[20], 200,
                    "incorrect value for stub[20], expected 200, is {}",
                    msg.stub[20]
                );
                assert_eq!(
                    msg.stub[21], 199,
                    "incorrect value for stub[21], expected 199, is {}",
                    msg.stub[21]
                );
                assert_eq!(
                    msg.stub[22], 198,
                    "incorrect value for stub[22], expected 198, is {}",
                    msg.stub[22]
                );
                assert_eq!(
                    msg.stub[23], 197,
                    "incorrect value for stub[23], expected 197, is {}",
                    msg.stub[23]
                );
                assert_eq!(
                    msg.stub[24], 196,
                    "incorrect value for stub[24], expected 196, is {}",
                    msg.stub[24]
                );
                assert_eq!(
                    msg.stub[25], 195,
                    "incorrect value for stub[25], expected 195, is {}",
                    msg.stub[25]
                );
                assert_eq!(
                    msg.stub[26], 194,
                    "incorrect value for stub[26], expected 194, is {}",
                    msg.stub[26]
                );
                assert_eq!(
                    msg.stub[27], 193,
                    "incorrect value for stub[27], expected 193, is {}",
                    msg.stub[27]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrOrbitClockBoundsDegradation"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
