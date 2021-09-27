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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgFwd.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_logging_msg_fwd() {
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
            sbp::messages::Sbp::MsgFwd(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x402,
                    "Incorrect message type, expected 0x402, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.fwd_payload[0], 86,
                    "incorrect value for fwd_payload[0], expected 86, is {}",
                    msg.fwd_payload[0]
                );
                assert_eq!(
                    msg.fwd_payload[1], 81,
                    "incorrect value for fwd_payload[1], expected 81, is {}",
                    msg.fwd_payload[1]
                );
                assert_eq!(
                    msg.fwd_payload[2], 68,
                    "incorrect value for fwd_payload[2], expected 68, is {}",
                    msg.fwd_payload[2]
                );
                assert_eq!(
                    msg.fwd_payload[3], 47,
                    "incorrect value for fwd_payload[3], expected 47, is {}",
                    msg.fwd_payload[3]
                );
                assert_eq!(
                    msg.fwd_payload[4], 81,
                    "incorrect value for fwd_payload[4], expected 81, is {}",
                    msg.fwd_payload[4]
                );
                assert_eq!(
                    msg.fwd_payload[5], 103,
                    "incorrect value for fwd_payload[5], expected 103, is {}",
                    msg.fwd_payload[5]
                );
                assert_eq!(
                    msg.fwd_payload[6], 65,
                    "incorrect value for fwd_payload[6], expected 65, is {}",
                    msg.fwd_payload[6]
                );
                assert_eq!(
                    msg.fwd_payload[7], 69,
                    "incorrect value for fwd_payload[7], expected 69, is {}",
                    msg.fwd_payload[7]
                );
                assert_eq!(
                    msg.fwd_payload[8], 65,
                    "incorrect value for fwd_payload[8], expected 65, is {}",
                    msg.fwd_payload[8]
                );
                assert_eq!(
                    msg.fwd_payload[9], 65,
                    "incorrect value for fwd_payload[9], expected 65, is {}",
                    msg.fwd_payload[9]
                );
                assert_eq!(
                    msg.fwd_payload[10], 65,
                    "incorrect value for fwd_payload[10], expected 65, is {}",
                    msg.fwd_payload[10]
                );
                assert_eq!(
                    msg.fwd_payload[11], 65,
                    "incorrect value for fwd_payload[11], expected 65, is {}",
                    msg.fwd_payload[11]
                );
                assert_eq!(
                    msg.fwd_payload[12], 65,
                    "incorrect value for fwd_payload[12], expected 65, is {}",
                    msg.fwd_payload[12]
                );
                assert_eq!(
                    msg.fwd_payload[13], 69,
                    "incorrect value for fwd_payload[13], expected 69, is {}",
                    msg.fwd_payload[13]
                );
                assert_eq!(
                    msg.fwd_payload[14], 97,
                    "incorrect value for fwd_payload[14], expected 97, is {}",
                    msg.fwd_payload[14]
                );
                assert_eq!(
                    msg.fwd_payload[15], 103,
                    "incorrect value for fwd_payload[15], expected 103, is {}",
                    msg.fwd_payload[15]
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
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
