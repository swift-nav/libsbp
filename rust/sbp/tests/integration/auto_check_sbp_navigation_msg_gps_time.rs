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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTime.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_gps_time() {
    {
        let mut payload = Cursor::new(vec![
            85, 2, 1, 211, 136, 11, 128, 7, 40, 244, 122, 19, 244, 139, 2, 0, 0, 34, 152,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTime(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x102,
                    "Incorrect message type, expected 0x102, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 166900,
                    "incorrect value for ns_residual, expected 166900, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326825000,
                    "incorrect value for tow, expected 326825000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTime"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 1, 211, 136, 11, 128, 7, 28, 246, 122, 19, 126, 234, 3, 0, 0, 65, 3,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTime(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x102,
                    "Incorrect message type, expected 0x102, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 256638,
                    "incorrect value for ns_residual, expected 256638, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326825500,
                    "incorrect value for tow, expected 326825500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTime"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 1, 211, 136, 11, 128, 7, 16, 248, 122, 19, 129, 12, 4, 0, 0, 12, 84,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTime(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x102,
                    "Incorrect message type, expected 0x102, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 265345,
                    "incorrect value for ns_residual, expected 265345, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326826000,
                    "incorrect value for tow, expected 326826000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTime"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 1, 211, 136, 11, 128, 7, 4, 250, 122, 19, 137, 204, 4, 0, 0, 50, 165,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTime(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x102,
                    "Incorrect message type, expected 0x102, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 314505,
                    "incorrect value for ns_residual, expected 314505, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326826500,
                    "incorrect value for tow, expected 326826500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTime"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 1, 211, 136, 11, 128, 7, 248, 251, 122, 19, 181, 137, 5, 0, 0, 180, 33,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTime(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x102,
                    "Incorrect message type, expected 0x102, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 362933,
                    "incorrect value for ns_residual, expected 362933, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326827000,
                    "incorrect value for tow, expected 326827000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTime"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
