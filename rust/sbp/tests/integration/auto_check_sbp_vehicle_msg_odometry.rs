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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/vehicle/test_MsgOdometry.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_vehicle_msg_odometry() {
    {
        let mut payload = Cursor::new(vec![85, 3, 9, 66, 0, 9, 8, 0, 0, 0, 7, 0, 0, 0, 1, 52, 99]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgOdometry(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x903,
                    "Incorrect message type, expected 0x903, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.tow, 8,
                    "incorrect value for tow, expected 8, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.velocity, 7,
                    "incorrect value for velocity, expected 7, is {}",
                    msg.velocity
                );
            }
            _ => panic!("Invalid message type! Expected a MsgOdometry"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}

#[test]
#[cfg(feature = "json")]
fn test_json2sbp_auto_check_sbp_vehicle_msg_odometry() {
    {
        let json_input = r#"{"sender": 66, "msg_type": 2307, "tow": 8, "crc": 25396, "length": 9, "flags": 1, "velocity": 7, "preamble": 85, "payload": "CAAAAAcAAAAB"}"#.as_bytes();

        let sbp_msg = {
            // Json to Sbp message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // Json to Sbp message from payload
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgOdometry(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x903,
                    "Incorrect message type, expected 0x903, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.tow, 8,
                    "incorrect value for tow, expected 8, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.velocity, 7,
                    "incorrect value for velocity, expected 7, is {}",
                    msg.velocity
                );
            }
            _ => panic!("Invalid message type! Expected a MsgOdometry"),
        };
    }
}
