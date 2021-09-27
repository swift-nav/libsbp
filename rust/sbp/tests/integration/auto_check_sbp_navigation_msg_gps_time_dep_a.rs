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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTimeDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_gps_time_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 0, 1, 246, 215, 11, 251, 6, 120, 46, 39, 0, 0, 0, 0, 0, 0, 133, 36,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTimeDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 0,
                    "incorrect value for ns_residual, expected 0, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 2567800,
                    "incorrect value for tow, expected 2567800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1787,
                    "incorrect value for wn, expected 1787, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 1, 246, 215, 11, 251, 6, 220, 46, 39, 0, 0, 0, 0, 0, 0, 36, 160,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTimeDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 0,
                    "incorrect value for ns_residual, expected 0, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 2567900,
                    "incorrect value for tow, expected 2567900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1787,
                    "incorrect value for wn, expected 1787, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 1, 246, 215, 11, 251, 6, 64, 47, 39, 0, 0, 0, 0, 0, 0, 171, 190,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTimeDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 0,
                    "incorrect value for ns_residual, expected 0, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 2568000,
                    "incorrect value for tow, expected 2568000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1787,
                    "incorrect value for wn, expected 1787, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 1, 246, 215, 11, 251, 6, 164, 47, 39, 0, 0, 0, 0, 0, 0, 211, 101,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTimeDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 0,
                    "incorrect value for ns_residual, expected 0, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 2568100,
                    "incorrect value for tow, expected 2568100, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1787,
                    "incorrect value for wn, expected 1787, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 1, 246, 215, 11, 251, 6, 8, 48, 39, 0, 0, 0, 0, 0, 0, 251, 44,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTimeDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 0,
                    "incorrect value for ns_residual, expected 0, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 2568200,
                    "incorrect value for tow, expected 2568200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1787,
                    "incorrect value for wn, expected 1787, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 1, 195, 4, 11, 46, 7, 212, 157, 67, 24, 111, 147, 252, 255, 0, 215, 190,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTimeDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, -224401,
                    "incorrect value for ns_residual, expected -224401, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 407084500,
                    "incorrect value for tow, expected 407084500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1838,
                    "incorrect value for wn, expected 1838, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 1, 195, 4, 11, 46, 7, 56, 158, 67, 24, 109, 103, 3, 0, 0, 134, 89,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTimeDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 223085,
                    "incorrect value for ns_residual, expected 223085, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 407084600,
                    "incorrect value for tow, expected 407084600, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1838,
                    "incorrect value for wn, expected 1838, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 1, 195, 4, 11, 46, 7, 156, 158, 67, 24, 233, 152, 252, 255, 0, 206, 241,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTimeDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, -222999,
                    "incorrect value for ns_residual, expected -222999, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 407084700,
                    "incorrect value for tow, expected 407084700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1838,
                    "incorrect value for wn, expected 1838, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 1, 195, 4, 11, 46, 7, 0, 159, 67, 24, 240, 154, 3, 0, 0, 147, 98,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTimeDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 236272,
                    "incorrect value for ns_residual, expected 236272, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 407084800,
                    "incorrect value for tow, expected 407084800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1838,
                    "incorrect value for wn, expected 1838, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 1, 195, 4, 11, 46, 7, 100, 159, 67, 24, 144, 101, 252, 255, 0, 186, 152,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTimeDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, -236144,
                    "incorrect value for ns_residual, expected -236144, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 407084900,
                    "incorrect value for tow, expected 407084900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1838,
                    "incorrect value for wn, expected 1838, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 1, 195, 4, 11, 46, 7, 46, 162, 68, 24, 205, 230, 250, 255, 0, 11, 225,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGpsTimeDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, -334131,
                    "incorrect value for ns_residual, expected -334131, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 407151150,
                    "incorrect value for tow, expected 407151150, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1838,
                    "incorrect value for wn, expected 1838, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
