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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgSensorAidEvent.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_system_msg_sensor_aid_event() {
    {
        let mut payload = Cursor::new(vec![
            85, 9, 255, 211, 136, 15, 48, 246, 122, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 236,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSensorAidEvent(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xFF09,
                    "Incorrect message type, expected 0xFF09, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88D3,
                    "incorrect sender id, expected 0x88D3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_accepted_meas, 0,
                    "incorrect value for n_accepted_meas, expected 0, is {}",
                    msg.n_accepted_meas
                );
                assert_eq!(
                    msg.n_attempted_meas, 0,
                    "incorrect value for n_attempted_meas, expected 0, is {}",
                    msg.n_attempted_meas
                );
                assert_eq!(
                    msg.n_available_meas, 0,
                    "incorrect value for n_available_meas, expected 0, is {}",
                    msg.n_available_meas
                );
                assert_eq!(
                    msg.sensor_id, 0,
                    "incorrect value for sensor_id, expected 0, is {}",
                    msg.sensor_id
                );
                assert_eq!(
                    msg.sensor_state, 0,
                    "incorrect value for sensor_state, expected 0, is {}",
                    msg.sensor_state
                );
                assert_eq!(
                    msg.sensor_type, 0,
                    "incorrect value for sensor_type, expected 0, is {}",
                    msg.sensor_type
                );
                assert_eq!(
                    msg.time, 326825520,
                    "incorrect value for time, expected 326825520, is {}",
                    msg.time
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSensorAidEvent"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}