//
// Copyright (C) 2019 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/vehicle/test_MsgOdometry.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_vehicle_50() {
    {
        let payload: Vec<u8> = vec![85, 3, 9, 66, 0, 9, 8, 0, 0, 0, 7, 0, 0, 0, 1, 52, 99];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgOdometry(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x903,
                    "Incorrect message type, expected 0x903, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
