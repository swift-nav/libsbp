//
// Copyright (C) 2019 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_msgFwd.yaml by
// generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_logging_43() {
    {
        let mut payload = Cursor::new(vec![
            85, 2, 4, 66, 0, 18, 0, 0, 86, 81, 68, 47, 81, 103, 65, 69, 65, 65, 65, 65, 65, 69, 97,
            103, 125, 95,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgFwd(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x402,
                    "Incorrect message type, expected 0x402, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    Into::<String>::into(msg.fwd_payload.clone()),
                    "VQD/QgAEAAAAAEag".to_string(),
                    "incorrect value for msg.fwd_payload, expected string '{}', is '{}'",
                    "VQD/QgAEAAAAAEag".to_string(),
                    msg.fwd_payload
                );
                assert_eq!(
                    msg.protocol, 0,
                    "incorrect value for protocol, expected 0, is {}",
                    msg.protocol
                );
                assert_eq!(
                    msg.source, 0,
                    "incorrect value for source, expected 0, is {}",
                    msg.source
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFwd"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
