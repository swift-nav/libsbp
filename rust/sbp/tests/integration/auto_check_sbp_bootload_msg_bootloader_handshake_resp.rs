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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/bootload/test_MsgBootloaderHandshakeResp.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_bootload_msg_bootloader_handshake_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 180, 0, 0, 0, 9, 0, 0, 0, 0, 118, 49, 46, 50, 10, 201, 1,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBootloaderHandshakeResp(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb4,
                    "Incorrect message type, expected 0xb4, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0,
                    "incorrect sender id, expected 0x0, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.version.to_string(),
                    "v1.2
"
                    .to_string(),
                    "incorrect value for msg.version, expected string '{}', is '{}'",
                    "v1.2
"
                    .to_string(),
                    msg.version
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBootloaderHandshakeResp"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![85, 176, 0, 195, 4, 4, 118, 49, 46, 50, 1, 206]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBootloaderHandshakeDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb0,
                    "Incorrect message type, expected 0xb0, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.handshake[0], 118,
                    "incorrect value for handshake[0], expected 118, is {}",
                    msg.handshake[0]
                );
                assert_eq!(
                    msg.handshake[1], 49,
                    "incorrect value for handshake[1], expected 49, is {}",
                    msg.handshake[1]
                );
                assert_eq!(
                    msg.handshake[2], 46,
                    "incorrect value for handshake[2], expected 46, is {}",
                    msg.handshake[2]
                );
                assert_eq!(
                    msg.handshake[3], 50,
                    "incorrect value for handshake[3], expected 50, is {}",
                    msg.handshake[3]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBootloaderHandshakeDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
