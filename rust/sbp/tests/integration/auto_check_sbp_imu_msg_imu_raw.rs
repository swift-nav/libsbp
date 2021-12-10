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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuRaw.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_imu_msg_imu_raw() {
    {
        let mut payload = Cursor::new(vec![
            85, 0, 9, 52, 18, 17, 26, 1, 0, 192, 206, 96, 0, 223, 255, 44, 16, 60, 0, 208, 254,
            238, 255, 70, 135,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgImuRaw(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x900,
                    "Incorrect message type, expected 0x900, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1234,
                    "incorrect sender id, expected 0x1234, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.acc_x, 96,
                    "incorrect value for acc_x, expected 96, is {}",
                    msg.acc_x
                );
                assert_eq!(
                    msg.acc_y, -33,
                    "incorrect value for acc_y, expected -33, is {}",
                    msg.acc_y
                );
                assert_eq!(
                    msg.acc_z, 4140,
                    "incorrect value for acc_z, expected 4140, is {}",
                    msg.acc_z
                );
                assert_eq!(
                    msg.gyr_x, 60,
                    "incorrect value for gyr_x, expected 60, is {}",
                    msg.gyr_x
                );
                assert_eq!(
                    msg.gyr_y, -304,
                    "incorrect value for gyr_y, expected -304, is {}",
                    msg.gyr_y
                );
                assert_eq!(
                    msg.gyr_z, -18,
                    "incorrect value for gyr_z, expected -18, is {}",
                    msg.gyr_z
                );
                assert_eq!(
                    msg.tow, 3221225754,
                    "incorrect value for tow, expected 3221225754, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.tow_f, 206,
                    "incorrect value for tow_f, expected 206, is {}",
                    msg.tow_f
                );
            }
            _ => panic!("Invalid message type! Expected a MsgImuRaw"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
