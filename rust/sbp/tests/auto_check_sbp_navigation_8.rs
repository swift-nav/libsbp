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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDops.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_8() {
    {
        let payload: Vec<u8> = vec![
            85, 8, 2, 66, 0, 15, 100, 0, 0, 0, 2, 0, 6, 0, 5, 0, 5, 0, 5, 0, 0, 244, 4,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgDops(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x208,
                    "Incorrect message type, expected 0x208, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.gdop, 2,
                    "incorrect value for gdop, expected 2, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 5,
                    "incorrect value for hdop, expected 5, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 6,
                    "incorrect value for pdop, expected 6, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 5,
                    "incorrect value for tdop, expected 5, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 100,
                    "incorrect value for tow, expected 100, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 5,
                    "incorrect value for vdop, expected 5, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDops"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
