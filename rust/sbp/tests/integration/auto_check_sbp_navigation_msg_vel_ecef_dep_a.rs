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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEFDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_vel_ecef_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 246, 215, 20, 20, 46, 39, 0, 218, 11, 0, 0, 134, 245, 255, 255, 163, 252,
            255, 255, 0, 0, 9, 0, 80, 236,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567700,
                    "incorrect value for tow, expected 2567700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, 3034,
                    "incorrect value for x, expected 3034, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -2682,
                    "incorrect value for y, expected -2682, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -861,
                    "incorrect value for z, expected -861, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 246, 215, 20, 120, 46, 39, 0, 68, 11, 0, 0, 24, 246, 255, 255, 220, 252, 255,
            255, 0, 0, 9, 0, 248, 138,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567800,
                    "incorrect value for tow, expected 2567800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, 2884,
                    "incorrect value for x, expected 2884, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -2536,
                    "incorrect value for y, expected -2536, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -804,
                    "incorrect value for z, expected -804, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 246, 215, 20, 220, 46, 39, 0, 21, 11, 0, 0, 77, 246, 255, 255, 247, 252, 255,
            255, 0, 0, 9, 0, 25, 174,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567900,
                    "incorrect value for tow, expected 2567900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, 2837,
                    "incorrect value for x, expected 2837, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -2483,
                    "incorrect value for y, expected -2483, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -777,
                    "incorrect value for z, expected -777, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 246, 215, 20, 64, 47, 39, 0, 121, 11, 0, 0, 2, 246, 255, 255, 234, 252, 255,
            255, 0, 0, 9, 0, 195, 228,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2568000,
                    "incorrect value for tow, expected 2568000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, 2937,
                    "incorrect value for x, expected 2937, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -2558,
                    "incorrect value for y, expected -2558, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -790,
                    "incorrect value for z, expected -790, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 246, 215, 20, 164, 47, 39, 0, 31, 11, 0, 0, 93, 246, 255, 255, 16, 253, 255,
            255, 0, 0, 9, 0, 219, 164,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2568100,
                    "incorrect value for tow, expected 2568100, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, 2847,
                    "incorrect value for x, expected 2847, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -2467,
                    "incorrect value for y, expected -2467, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -752,
                    "incorrect value for z, expected -752, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 195, 4, 20, 212, 157, 67, 24, 24, 0, 0, 0, 245, 255, 255, 255, 219, 255, 255,
            255, 0, 0, 8, 0, 68, 255,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084500,
                    "incorrect value for tow, expected 407084500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, 24,
                    "incorrect value for x, expected 24, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -11,
                    "incorrect value for y, expected -11, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -37,
                    "incorrect value for z, expected -37, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 195, 4, 20, 56, 158, 67, 24, 4, 0, 0, 0, 234, 255, 255, 255, 18, 0, 0, 0, 0,
            0, 8, 0, 214, 136,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084600,
                    "incorrect value for tow, expected 407084600, is {}",
                    msg.tow
                );
                assert_eq!(msg.x, 4, "incorrect value for x, expected 4, is {}", msg.x);
                assert_eq!(
                    msg.y, -22,
                    "incorrect value for y, expected -22, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 18,
                    "incorrect value for z, expected 18, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 195, 4, 20, 156, 158, 67, 24, 230, 255, 255, 255, 4, 0, 0, 0, 1, 0, 0, 0, 0,
            0, 8, 0, 122, 159,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084700,
                    "incorrect value for tow, expected 407084700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -26,
                    "incorrect value for x, expected -26, is {}",
                    msg.x
                );
                assert_eq!(msg.y, 4, "incorrect value for y, expected 4, is {}", msg.y);
                assert_eq!(msg.z, 1, "incorrect value for z, expected 1, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 195, 4, 20, 0, 159, 67, 24, 247, 255, 255, 255, 237, 255, 255, 255, 28, 0, 0,
            0, 0, 0, 8, 0, 232, 146,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084800,
                    "incorrect value for tow, expected 407084800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -9,
                    "incorrect value for x, expected -9, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -19,
                    "incorrect value for y, expected -19, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 28,
                    "incorrect value for z, expected 28, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 195, 4, 20, 100, 159, 67, 24, 255, 255, 255, 255, 2, 0, 0, 0, 245, 255, 255,
            255, 0, 0, 8, 0, 171, 238,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084900,
                    "incorrect value for tow, expected 407084900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1,
                    "incorrect value for x, expected -1, is {}",
                    msg.x
                );
                assert_eq!(msg.y, 2, "incorrect value for y, expected 2, is {}", msg.y);
                assert_eq!(
                    msg.z, -11,
                    "incorrect value for z, expected -11, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 195, 4, 20, 46, 162, 68, 24, 207, 255, 255, 255, 185, 255, 255, 255, 65, 0,
            0, 0, 0, 0, 5, 0, 82, 154,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 5,
                    "incorrect value for n_sats, expected 5, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407151150,
                    "incorrect value for tow, expected 407151150, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -49,
                    "incorrect value for x, expected -49, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -71,
                    "incorrect value for y, expected -71, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 65,
                    "incorrect value for z, expected 65, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
