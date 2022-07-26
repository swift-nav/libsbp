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

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
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

/// Tests [`sbp::json::iter_messages`] for JSON payload -> SBP message
/// and [`sbp::json::iter_messages_from_fields`] for JSON fields -> SBP message.
///
/// Asserts:
/// -   SBP message constructed via payload is identical to from fields
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_json2sbp_auto_check_sbp_navigation_msg_vel_ecef_dep_a() {
    {
        let json_input = r#"{"n_sats": 9, "sender": 55286, "msg_type": 516, "tow": 2567700, "crc": 60496, "length": 20, "flags": 0, "y": -2682, "x": 3034, "z": -861, "preamble": 85, "payload": "FC4nANoLAACG9f//o/z//wAACQA=", "accuracy": 0}"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
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
    }
    {
        let json_input = r#"{"n_sats": 9, "sender": 55286, "msg_type": 516, "tow": 2567800, "crc": 35576, "length": 20, "flags": 0, "y": -2536, "x": 2884, "z": -804, "preamble": 85, "payload": "eC4nAEQLAAAY9v//3Pz//wAACQA=", "accuracy": 0}"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
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
    }
    {
        let json_input = r#"{"n_sats": 9, "sender": 55286, "msg_type": 516, "tow": 2567900, "crc": 44569, "length": 20, "flags": 0, "y": -2483, "x": 2837, "z": -777, "preamble": 85, "payload": "3C4nABULAABN9v//9/z//wAACQA=", "accuracy": 0}"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
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
    }
    {
        let json_input = r#"{"n_sats": 9, "sender": 55286, "msg_type": 516, "tow": 2568000, "crc": 58563, "length": 20, "flags": 0, "y": -2558, "x": 2937, "z": -790, "preamble": 85, "payload": "QC8nAHkLAAAC9v//6vz//wAACQA=", "accuracy": 0}"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
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
    }
    {
        let json_input = r#"{"n_sats": 9, "sender": 55286, "msg_type": 516, "tow": 2568100, "crc": 42203, "length": 20, "flags": 0, "y": -2467, "x": 2847, "z": -752, "preamble": 85, "payload": "pC8nAB8LAABd9v//EP3//wAACQA=", "accuracy": 0}"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
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
    }
    {
        let json_input = r#"{"n_sats": 8, "sender": 1219, "msg_type": 516, "tow": 407084500, "crc": 65348, "length": 20, "flags": 0, "y": -11, "x": 24, "z": -37, "preamble": 85, "payload": "1J1DGBgAAAD1////2////wAACAA=", "accuracy": 0}"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
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
    }
    {
        let json_input = r#"{"n_sats": 8, "sender": 1219, "msg_type": 516, "tow": 407084600, "crc": 35030, "length": 20, "flags": 0, "y": -22, "x": 4, "z": 18, "preamble": 85, "payload": "OJ5DGAQAAADq////EgAAAAAACAA=", "accuracy": 0}"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
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
    }
    {
        let json_input = r#"{"n_sats": 8, "sender": 1219, "msg_type": 516, "tow": 407084700, "crc": 40826, "length": 20, "flags": 0, "y": 4, "x": -26, "z": 1, "preamble": 85, "payload": "nJ5DGOb///8EAAAAAQAAAAAACAA=", "accuracy": 0}"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
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
    }
    {
        let json_input = r#"{"n_sats": 8, "sender": 1219, "msg_type": 516, "tow": 407084800, "crc": 37608, "length": 20, "flags": 0, "y": -19, "x": -9, "z": 28, "preamble": 85, "payload": "AJ9DGPf////t////HAAAAAAACAA=", "accuracy": 0}"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
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
    }
    {
        let json_input = r#"{"n_sats": 8, "sender": 1219, "msg_type": 516, "tow": 407084900, "crc": 61099, "length": 20, "flags": 0, "y": 2, "x": -1, "z": -11, "preamble": 85, "payload": "ZJ9DGP////8CAAAA9f///wAACAA=", "accuracy": 0}"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
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
    }
    {
        let json_input = r#"{"n_sats": 5, "sender": 1219, "msg_type": 516, "tow": 407151150, "crc": 39506, "length": 20, "flags": 0, "y": -71, "x": -49, "z": 65, "preamble": 85, "payload": "LqJEGM////+5////QQAAAAAABQA=", "accuracy": 0}"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
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
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_vel_ecef_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_vel_ecef_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 246, 215, 20, 20, 46, 39, 0, 218, 11, 0, 0, 134, 245, 255, 255, 163, 252,
            255, 255, 0, 0, 9, 0, 80, 236,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 246, 215, 20, 120, 46, 39, 0, 68, 11, 0, 0, 24, 246, 255, 255, 220, 252, 255,
            255, 0, 0, 9, 0, 248, 138,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 246, 215, 20, 220, 46, 39, 0, 21, 11, 0, 0, 77, 246, 255, 255, 247, 252, 255,
            255, 0, 0, 9, 0, 25, 174,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 246, 215, 20, 64, 47, 39, 0, 121, 11, 0, 0, 2, 246, 255, 255, 234, 252, 255,
            255, 0, 0, 9, 0, 195, 228,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 246, 215, 20, 164, 47, 39, 0, 31, 11, 0, 0, 93, 246, 255, 255, 16, 253, 255,
            255, 0, 0, 9, 0, 219, 164,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 195, 4, 20, 212, 157, 67, 24, 24, 0, 0, 0, 245, 255, 255, 255, 219, 255, 255,
            255, 0, 0, 8, 0, 68, 255,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 195, 4, 20, 56, 158, 67, 24, 4, 0, 0, 0, 234, 255, 255, 255, 18, 0, 0, 0, 0,
            0, 8, 0, 214, 136,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 195, 4, 20, 156, 158, 67, 24, 230, 255, 255, 255, 4, 0, 0, 0, 1, 0, 0, 0, 0,
            0, 8, 0, 122, 159,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 195, 4, 20, 0, 159, 67, 24, 247, 255, 255, 255, 237, 255, 255, 255, 28, 0, 0,
            0, 0, 0, 8, 0, 232, 146,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 195, 4, 20, 100, 159, 67, 24, 255, 255, 255, 255, 2, 0, 0, 0, 245, 255, 255,
            255, 0, 0, 8, 0, 171, 238,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 2, 195, 4, 20, 46, 162, 68, 24, 207, 255, 255, 255, 185, 255, 255, 255, 65, 0,
            0, 0, 0, 0, 5, 0, 82, 154,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgVelEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
