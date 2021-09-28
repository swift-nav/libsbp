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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgBasePosEcef.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_observation_msg_base_pos_ecef() {
    {
        let mut payload = Cursor::new(vec![
            85, 72, 0, 0, 0, 24, 228, 131, 158, 245, 87, 205, 68, 193, 66, 62, 232, 209, 32, 118,
            80, 193, 213, 231, 106, 251, 63, 20, 77, 65, 194, 125,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBasePosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x48,
                    "Incorrect message type, expected 0x48, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0,
                    "incorrect sender id, expected 0, is {}",
                    sender_id
                );
                assert!(
                    msg.x.almost_eq(-2.72657591889999993e+06),
                    "incorrect value for x, expected -2.72657591889999993e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31526727979999967e+06),
                    "incorrect value for y, expected -4.31526727979999967e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.81145596419999981e+06),
                    "incorrect value for z, expected 3.81145596419999981e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBasePosECEF"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
