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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEFDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 246, 215, 20, 20, 46, 39, 0, 21, 48, 255, 255, 52, 117, 255, 255, 216, 211,
            254, 255, 0, 0, 9, 1, 50, 137,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -53227,
                    "incorrect value for x, expected -53227, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -35532,
                    "incorrect value for y, expected -35532, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -76840,
                    "incorrect value for z, expected -76840, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 246, 215, 20, 120, 46, 39, 0, 58, 49, 255, 255, 49, 116, 255, 255, 134, 211,
            254, 255, 0, 0, 9, 1, 227, 155,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -52934,
                    "incorrect value for x, expected -52934, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -35791,
                    "incorrect value for y, expected -35791, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -76922,
                    "incorrect value for z, expected -76922, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 246, 215, 20, 220, 46, 39, 0, 97, 50, 255, 255, 47, 115, 255, 255, 52, 211,
            254, 255, 0, 0, 9, 1, 61, 126,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -52639,
                    "incorrect value for x, expected -52639, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -36049,
                    "incorrect value for y, expected -36049, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -77004,
                    "incorrect value for z, expected -77004, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 246, 215, 20, 64, 47, 39, 0, 136, 51, 255, 255, 45, 114, 255, 255, 228, 210,
            254, 255, 0, 0, 9, 1, 200, 79,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -52344,
                    "incorrect value for x, expected -52344, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -36307,
                    "incorrect value for y, expected -36307, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -77084,
                    "incorrect value for z, expected -77084, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 246, 215, 20, 164, 47, 39, 0, 176, 52, 255, 255, 44, 113, 255, 255, 149, 210,
            254, 255, 0, 0, 9, 1, 104, 24,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -52048,
                    "incorrect value for x, expected -52048, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -36564,
                    "incorrect value for y, expected -36564, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -77163,
                    "incorrect value for z, expected -77163, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 195, 4, 20, 156, 21, 69, 24, 169, 231, 255, 255, 102, 208, 255, 255, 251, 28,
            0, 0, 0, 0, 6, 0, 146, 168,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180700,
                    "incorrect value for tow, expected 407180700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -6231,
                    "incorrect value for x, expected -6231, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -12186,
                    "incorrect value for y, expected -12186, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 7419,
                    "incorrect value for z, expected 7419, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 195, 4, 20, 0, 22, 69, 24, 169, 231, 255, 255, 103, 208, 255, 255, 252, 28,
            0, 0, 0, 0, 6, 0, 34, 116,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180800,
                    "incorrect value for tow, expected 407180800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -6231,
                    "incorrect value for x, expected -6231, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -12185,
                    "incorrect value for y, expected -12185, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 7420,
                    "incorrect value for z, expected 7420, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 195, 4, 20, 100, 22, 69, 24, 30, 224, 255, 255, 192, 183, 255, 255, 239, 53,
            0, 0, 0, 0, 6, 0, 225, 15,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180900,
                    "incorrect value for tow, expected 407180900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -8162,
                    "incorrect value for x, expected -8162, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -18496,
                    "incorrect value for y, expected -18496, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 13807,
                    "incorrect value for z, expected 13807, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 195, 4, 20, 200, 22, 69, 24, 28, 224, 255, 255, 191, 183, 255, 255, 242, 53,
            0, 0, 0, 0, 6, 0, 35, 100,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181000,
                    "incorrect value for tow, expected 407181000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -8164,
                    "incorrect value for x, expected -8164, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -18497,
                    "incorrect value for y, expected -18497, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 13810,
                    "incorrect value for z, expected 13810, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 195, 4, 20, 44, 23, 69, 24, 24, 227, 255, 255, 25, 195, 255, 255, 153, 59, 0,
            0, 0, 0, 6, 0, 66, 66,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181100,
                    "incorrect value for tow, expected 407181100, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -7400,
                    "incorrect value for x, expected -7400, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -15591,
                    "incorrect value for y, expected -15591, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 15257,
                    "incorrect value for z, expected 15257, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 195, 4, 20, 144, 23, 69, 24, 23, 227, 255, 255, 25, 195, 255, 255, 153, 59,
            0, 0, 0, 0, 6, 0, 35, 135,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181200,
                    "incorrect value for tow, expected 407181200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -7401,
                    "incorrect value for x, expected -7401, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -15591,
                    "incorrect value for y, expected -15591, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 15257,
                    "incorrect value for z, expected 15257, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_baseline_ecef_dep_a() {
    {
        let json_input = r#"{"n_sats": 9, "sender": 55286, "msg_type": 514, "tow": 2567700, "crc": 35122, "length": 20, "flags": 1, "y": -35532, "x": -53227, "z": -76840, "preamble": 85, "payload": "FC4nABUw//80df//2NP+/wAACQE=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -53227,
                    "incorrect value for x, expected -53227, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -35532,
                    "incorrect value for y, expected -35532, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -76840,
                    "incorrect value for z, expected -76840, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
    }
    {
        let json_input = r#"{"n_sats": 9, "sender": 55286, "msg_type": 514, "tow": 2567800, "crc": 39907, "length": 20, "flags": 1, "y": -35791, "x": -52934, "z": -76922, "preamble": 85, "payload": "eC4nADox//8xdP//htP+/wAACQE=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -52934,
                    "incorrect value for x, expected -52934, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -35791,
                    "incorrect value for y, expected -35791, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -76922,
                    "incorrect value for z, expected -76922, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
    }
    {
        let json_input = r#"{"n_sats": 9, "sender": 55286, "msg_type": 514, "tow": 2567900, "crc": 32317, "length": 20, "flags": 1, "y": -36049, "x": -52639, "z": -77004, "preamble": 85, "payload": "3C4nAGEy//8vc///NNP+/wAACQE=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -52639,
                    "incorrect value for x, expected -52639, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -36049,
                    "incorrect value for y, expected -36049, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -77004,
                    "incorrect value for z, expected -77004, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
    }
    {
        let json_input = r#"{"n_sats": 9, "sender": 55286, "msg_type": 514, "tow": 2568000, "crc": 20424, "length": 20, "flags": 1, "y": -36307, "x": -52344, "z": -77084, "preamble": 85, "payload": "QC8nAIgz//8tcv//5NL+/wAACQE=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -52344,
                    "incorrect value for x, expected -52344, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -36307,
                    "incorrect value for y, expected -36307, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -77084,
                    "incorrect value for z, expected -77084, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
    }
    {
        let json_input = r#"{"n_sats": 9, "sender": 55286, "msg_type": 514, "tow": 2568100, "crc": 6248, "length": 20, "flags": 1, "y": -36564, "x": -52048, "z": -77163, "preamble": 85, "payload": "pC8nALA0//8scf//ldL+/wAACQE=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -52048,
                    "incorrect value for x, expected -52048, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -36564,
                    "incorrect value for y, expected -36564, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -77163,
                    "incorrect value for z, expected -77163, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
    }
    {
        let json_input = r#"{"n_sats": 6, "sender": 1219, "msg_type": 514, "tow": 407180700, "crc": 43154, "length": 20, "flags": 0, "y": -12186, "x": -6231, "z": 7419, "preamble": 85, "payload": "nBVFGKnn//9m0P//+xwAAAAABgA=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180700,
                    "incorrect value for tow, expected 407180700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -6231,
                    "incorrect value for x, expected -6231, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -12186,
                    "incorrect value for y, expected -12186, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 7419,
                    "incorrect value for z, expected 7419, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
    }
    {
        let json_input = r#"{"n_sats": 6, "sender": 1219, "msg_type": 514, "tow": 407180800, "crc": 29730, "length": 20, "flags": 0, "y": -12185, "x": -6231, "z": 7420, "preamble": 85, "payload": "ABZFGKnn//9n0P///BwAAAAABgA=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180800,
                    "incorrect value for tow, expected 407180800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -6231,
                    "incorrect value for x, expected -6231, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -12185,
                    "incorrect value for y, expected -12185, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 7420,
                    "incorrect value for z, expected 7420, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
    }
    {
        let json_input = r#"{"n_sats": 6, "sender": 1219, "msg_type": 514, "tow": 407180900, "crc": 4065, "length": 20, "flags": 0, "y": -18496, "x": -8162, "z": 13807, "preamble": 85, "payload": "ZBZFGB7g///At///7zUAAAAABgA=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180900,
                    "incorrect value for tow, expected 407180900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -8162,
                    "incorrect value for x, expected -8162, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -18496,
                    "incorrect value for y, expected -18496, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 13807,
                    "incorrect value for z, expected 13807, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
    }
    {
        let json_input = r#"{"n_sats": 6, "sender": 1219, "msg_type": 514, "tow": 407181000, "crc": 25635, "length": 20, "flags": 0, "y": -18497, "x": -8164, "z": 13810, "preamble": 85, "payload": "yBZFGBzg//+/t///8jUAAAAABgA=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181000,
                    "incorrect value for tow, expected 407181000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -8164,
                    "incorrect value for x, expected -8164, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -18497,
                    "incorrect value for y, expected -18497, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 13810,
                    "incorrect value for z, expected 13810, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
    }
    {
        let json_input = r#"{"n_sats": 6, "sender": 1219, "msg_type": 514, "tow": 407181100, "crc": 16962, "length": 20, "flags": 0, "y": -15591, "x": -7400, "z": 15257, "preamble": 85, "payload": "LBdFGBjj//8Zw///mTsAAAAABgA=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181100,
                    "incorrect value for tow, expected 407181100, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -7400,
                    "incorrect value for x, expected -7400, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -15591,
                    "incorrect value for y, expected -15591, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 15257,
                    "incorrect value for z, expected 15257, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
    }
    {
        let json_input = r#"{"n_sats": 6, "sender": 1219, "msg_type": 514, "tow": 407181200, "crc": 34595, "length": 20, "flags": 0, "y": -15591, "x": -7401, "z": 15257, "preamble": 85, "payload": "kBdFGBfj//8Zw///mTsAAAAABgA=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181200,
                    "incorrect value for tow, expected 407181200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -7401,
                    "incorrect value for x, expected -7401, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -15591,
                    "incorrect value for y, expected -15591, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 15257,
                    "incorrect value for z, expected 15257, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_baseline_ecef_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_baseline_ecef_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 246, 215, 20, 20, 46, 39, 0, 21, 48, 255, 255, 52, 117, 255, 255, 216, 211,
            254, 255, 0, 0, 9, 1, 50, 137,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -53227,
                    "incorrect value for x, expected -53227, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -35532,
                    "incorrect value for y, expected -35532, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -76840,
                    "incorrect value for z, expected -76840, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 246, 215, 20, 120, 46, 39, 0, 58, 49, 255, 255, 49, 116, 255, 255, 134, 211,
            254, 255, 0, 0, 9, 1, 227, 155,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -52934,
                    "incorrect value for x, expected -52934, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -35791,
                    "incorrect value for y, expected -35791, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -76922,
                    "incorrect value for z, expected -76922, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 246, 215, 20, 220, 46, 39, 0, 97, 50, 255, 255, 47, 115, 255, 255, 52, 211,
            254, 255, 0, 0, 9, 1, 61, 126,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -52639,
                    "incorrect value for x, expected -52639, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -36049,
                    "incorrect value for y, expected -36049, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -77004,
                    "incorrect value for z, expected -77004, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 246, 215, 20, 64, 47, 39, 0, 136, 51, 255, 255, 45, 114, 255, 255, 228, 210,
            254, 255, 0, 0, 9, 1, 200, 79,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -52344,
                    "incorrect value for x, expected -52344, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -36307,
                    "incorrect value for y, expected -36307, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -77084,
                    "incorrect value for z, expected -77084, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 246, 215, 20, 164, 47, 39, 0, 176, 52, 255, 255, 44, 113, 255, 255, 149, 210,
            254, 255, 0, 0, 9, 1, 104, 24,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
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
                    msg.x, -52048,
                    "incorrect value for x, expected -52048, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -36564,
                    "incorrect value for y, expected -36564, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -77163,
                    "incorrect value for z, expected -77163, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 195, 4, 20, 156, 21, 69, 24, 169, 231, 255, 255, 102, 208, 255, 255, 251, 28,
            0, 0, 0, 0, 6, 0, 146, 168,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180700,
                    "incorrect value for tow, expected 407180700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -6231,
                    "incorrect value for x, expected -6231, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -12186,
                    "incorrect value for y, expected -12186, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 7419,
                    "incorrect value for z, expected 7419, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 195, 4, 20, 0, 22, 69, 24, 169, 231, 255, 255, 103, 208, 255, 255, 252, 28,
            0, 0, 0, 0, 6, 0, 34, 116,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180800,
                    "incorrect value for tow, expected 407180800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -6231,
                    "incorrect value for x, expected -6231, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -12185,
                    "incorrect value for y, expected -12185, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 7420,
                    "incorrect value for z, expected 7420, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 195, 4, 20, 100, 22, 69, 24, 30, 224, 255, 255, 192, 183, 255, 255, 239, 53,
            0, 0, 0, 0, 6, 0, 225, 15,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180900,
                    "incorrect value for tow, expected 407180900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -8162,
                    "incorrect value for x, expected -8162, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -18496,
                    "incorrect value for y, expected -18496, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 13807,
                    "incorrect value for z, expected 13807, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 195, 4, 20, 200, 22, 69, 24, 28, 224, 255, 255, 191, 183, 255, 255, 242, 53,
            0, 0, 0, 0, 6, 0, 35, 100,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181000,
                    "incorrect value for tow, expected 407181000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -8164,
                    "incorrect value for x, expected -8164, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -18497,
                    "incorrect value for y, expected -18497, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 13810,
                    "incorrect value for z, expected 13810, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 195, 4, 20, 44, 23, 69, 24, 24, 227, 255, 255, 25, 195, 255, 255, 153, 59, 0,
            0, 0, 0, 6, 0, 66, 66,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181100,
                    "incorrect value for tow, expected 407181100, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -7400,
                    "incorrect value for x, expected -7400, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -15591,
                    "incorrect value for y, expected -15591, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 15257,
                    "incorrect value for z, expected 15257, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 2, 2, 195, 4, 20, 144, 23, 69, 24, 23, 227, 255, 255, 25, 195, 255, 255, 153, 59,
            0, 0, 0, 0, 6, 0, 35, 135,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcefDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181200,
                    "incorrect value for tow, expected 407181200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -7401,
                    "incorrect value for x, expected -7401, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -15591,
                    "incorrect value for y, expected -15591, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 15257,
                    "incorrect value for z, expected 15257, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
