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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionBounds.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_ssr_msg_ssr_gridded_correction_bounds() {
    {
        let mut payload = Cursor::new(vec![
            85, 254, 5, 66, 0, 43, 180, 0, 0, 0, 3, 0, 1, 1, 10, 0, 15, 1, 0, 10, 0, 39, 232, 3,
            244, 1, 100, 200, 150, 100, 2, 5, 10, 16, 0, 17, 18, 19, 20, 21, 6, 10, 22, 0, 23, 24,
            25, 26, 27, 112, 145,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrGriddedCorrectionBounds(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1534,
                    "Incorrect message type, expected 1534, is {}",
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
                    msg.stub[7], 1,
                    "incorrect value for stub[7], expected 1, is {}",
                    msg.stub[7]
                );
                assert_eq!(
                    msg.stub[8], 10,
                    "incorrect value for stub[8], expected 10, is {}",
                    msg.stub[8]
                );
                assert_eq!(
                    msg.stub[9], 0,
                    "incorrect value for stub[9], expected 0, is {}",
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
                    msg.stub[12], 0,
                    "incorrect value for stub[12], expected 0, is {}",
                    msg.stub[12]
                );
                assert_eq!(
                    msg.stub[13], 10,
                    "incorrect value for stub[13], expected 10, is {}",
                    msg.stub[13]
                );
                assert_eq!(
                    msg.stub[14], 0,
                    "incorrect value for stub[14], expected 0, is {}",
                    msg.stub[14]
                );
                assert_eq!(
                    msg.stub[15], 39,
                    "incorrect value for stub[15], expected 39, is {}",
                    msg.stub[15]
                );
                assert_eq!(
                    msg.stub[16], 232,
                    "incorrect value for stub[16], expected 232, is {}",
                    msg.stub[16]
                );
                assert_eq!(
                    msg.stub[17], 3,
                    "incorrect value for stub[17], expected 3, is {}",
                    msg.stub[17]
                );
                assert_eq!(
                    msg.stub[18], 244,
                    "incorrect value for stub[18], expected 244, is {}",
                    msg.stub[18]
                );
                assert_eq!(
                    msg.stub[19], 1,
                    "incorrect value for stub[19], expected 1, is {}",
                    msg.stub[19]
                );
                assert_eq!(
                    msg.stub[20], 100,
                    "incorrect value for stub[20], expected 100, is {}",
                    msg.stub[20]
                );
                assert_eq!(
                    msg.stub[21], 200,
                    "incorrect value for stub[21], expected 200, is {}",
                    msg.stub[21]
                );
                assert_eq!(
                    msg.stub[22], 150,
                    "incorrect value for stub[22], expected 150, is {}",
                    msg.stub[22]
                );
                assert_eq!(
                    msg.stub[23], 100,
                    "incorrect value for stub[23], expected 100, is {}",
                    msg.stub[23]
                );
                assert_eq!(
                    msg.stub[24], 2,
                    "incorrect value for stub[24], expected 2, is {}",
                    msg.stub[24]
                );
                assert_eq!(
                    msg.stub[25], 5,
                    "incorrect value for stub[25], expected 5, is {}",
                    msg.stub[25]
                );
                assert_eq!(
                    msg.stub[26], 10,
                    "incorrect value for stub[26], expected 10, is {}",
                    msg.stub[26]
                );
                assert_eq!(
                    msg.stub[27], 16,
                    "incorrect value for stub[27], expected 16, is {}",
                    msg.stub[27]
                );
                assert_eq!(
                    msg.stub[28], 0,
                    "incorrect value for stub[28], expected 0, is {}",
                    msg.stub[28]
                );
                assert_eq!(
                    msg.stub[29], 17,
                    "incorrect value for stub[29], expected 17, is {}",
                    msg.stub[29]
                );
                assert_eq!(
                    msg.stub[30], 18,
                    "incorrect value for stub[30], expected 18, is {}",
                    msg.stub[30]
                );
                assert_eq!(
                    msg.stub[31], 19,
                    "incorrect value for stub[31], expected 19, is {}",
                    msg.stub[31]
                );
                assert_eq!(
                    msg.stub[32], 20,
                    "incorrect value for stub[32], expected 20, is {}",
                    msg.stub[32]
                );
                assert_eq!(
                    msg.stub[33], 21,
                    "incorrect value for stub[33], expected 21, is {}",
                    msg.stub[33]
                );
                assert_eq!(
                    msg.stub[34], 6,
                    "incorrect value for stub[34], expected 6, is {}",
                    msg.stub[34]
                );
                assert_eq!(
                    msg.stub[35], 10,
                    "incorrect value for stub[35], expected 10, is {}",
                    msg.stub[35]
                );
                assert_eq!(
                    msg.stub[36], 22,
                    "incorrect value for stub[36], expected 22, is {}",
                    msg.stub[36]
                );
                assert_eq!(
                    msg.stub[37], 0,
                    "incorrect value for stub[37], expected 0, is {}",
                    msg.stub[37]
                );
                assert_eq!(
                    msg.stub[38], 23,
                    "incorrect value for stub[38], expected 23, is {}",
                    msg.stub[38]
                );
                assert_eq!(
                    msg.stub[39], 24,
                    "incorrect value for stub[39], expected 24, is {}",
                    msg.stub[39]
                );
                assert_eq!(
                    msg.stub[40], 25,
                    "incorrect value for stub[40], expected 25, is {}",
                    msg.stub[40]
                );
                assert_eq!(
                    msg.stub[41], 26,
                    "incorrect value for stub[41], expected 26, is {}",
                    msg.stub[41]
                );
                assert_eq!(
                    msg.stub[42], 27,
                    "incorrect value for stub[42], expected 27, is {}",
                    msg.stub[42]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGriddedCorrectionBounds"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
