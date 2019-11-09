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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgDgnssStatus.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_system_35() {
    {
        let payload: Vec<u8> = vec![
            85, 2, 255, 66, 0, 11, 0, 50, 0, 12, 83, 107, 121, 108, 97, 114, 107, 202, 1,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgDgnssStatus(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0xff02,
                    "Incorrect message type, expected 0xff02, is {}",
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
                    msg.latency, 50,
                    "incorrect value for latency, expected 50, is {}",
                    msg.latency
                );
                assert_eq!(
                    msg.num_signals, 12,
                    "incorrect value for num_signals, expected 12, is {}",
                    msg.num_signals
                );
                assert_eq!(
                    msg.source,
                    "Skylark".to_string(),
                    "incorrect value for msg.source, expected string '{}', is '{}'",
                    "Skylark".to_string(),
                    msg.source
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDgnssStatus"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
