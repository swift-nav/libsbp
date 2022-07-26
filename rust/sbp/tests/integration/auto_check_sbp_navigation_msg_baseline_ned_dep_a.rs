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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNEDDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_baseline_ned_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 246, 215, 22, 20, 46, 39, 0, 243, 134, 254, 255, 234, 153, 255, 255, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 1, 93, 193,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -26134,
                    "incorrect value for e, expected -26134, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96525,
                    "incorrect value for n, expected -96525, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 246, 215, 22, 120, 46, 39, 0, 139, 134, 254, 255, 109, 155, 255, 255, 0, 0,
            0, 0, 0, 0, 0, 0, 9, 1, 38, 39,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -25747,
                    "incorrect value for e, expected -25747, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96629,
                    "incorrect value for n, expected -96629, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 246, 215, 22, 220, 46, 39, 0, 37, 134, 254, 255, 240, 156, 255, 255, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 1, 58, 133,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -25360,
                    "incorrect value for e, expected -25360, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96731,
                    "incorrect value for n, expected -96731, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 246, 215, 22, 64, 47, 39, 0, 193, 133, 254, 255, 115, 158, 255, 255, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 1, 56, 214,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -24973,
                    "incorrect value for e, expected -24973, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96831,
                    "incorrect value for n, expected -96831, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 246, 215, 22, 164, 47, 39, 0, 93, 133, 254, 255, 246, 159, 255, 255, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 1, 234, 244,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -24586,
                    "incorrect value for e, expected -24586, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96931,
                    "incorrect value for n, expected -96931, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 195, 4, 22, 156, 21, 69, 24, 130, 246, 255, 255, 241, 4, 0, 0, 35, 196, 255,
            255, 0, 0, 0, 0, 6, 0, 250, 21,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -15325,
                    "incorrect value for d, expected -15325, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 1265,
                    "incorrect value for e, expected 1265, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -2430,
                    "incorrect value for n, expected -2430, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 195, 4, 22, 0, 22, 69, 24, 130, 246, 255, 255, 241, 4, 0, 0, 35, 196, 255,
            255, 0, 0, 0, 0, 6, 0, 240, 133,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -15325,
                    "incorrect value for d, expected -15325, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 1265,
                    "incorrect value for e, expected 1265, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -2430,
                    "incorrect value for n, expected -2430, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 195, 4, 22, 100, 22, 69, 24, 32, 251, 255, 255, 199, 11, 0, 0, 57, 161, 255,
            255, 0, 0, 0, 0, 6, 0, 12, 181,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -24263,
                    "incorrect value for d, expected -24263, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 3015,
                    "incorrect value for e, expected 3015, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -1248,
                    "incorrect value for n, expected -1248, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 195, 4, 22, 200, 22, 69, 24, 33, 251, 255, 255, 199, 11, 0, 0, 54, 161, 255,
            255, 0, 0, 0, 0, 6, 0, 86, 58,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -24266,
                    "incorrect value for d, expected -24266, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 3015,
                    "incorrect value for e, expected 3015, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -1247,
                    "incorrect value for n, expected -1247, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 195, 4, 22, 44, 23, 69, 24, 110, 6, 0, 0, 55, 8, 0, 0, 160, 166, 255, 255, 0,
            0, 0, 0, 6, 0, 51, 249,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -22880,
                    "incorrect value for d, expected -22880, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 2103,
                    "incorrect value for e, expected 2103, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, 1646,
                    "incorrect value for n, expected 1646, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 195, 4, 22, 144, 23, 69, 24, 110, 6, 0, 0, 54, 8, 0, 0, 160, 166, 255, 255,
            0, 0, 0, 0, 6, 0, 206, 22,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -22880,
                    "incorrect value for d, expected -22880, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 2102,
                    "incorrect value for e, expected 2102, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, 1646,
                    "incorrect value for n, expected 1646, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_baseline_ned_dep_a() {
    {
        let json_input = r#"{"v_accuracy": 0, "e": -26134, "sender": 55286, "msg_type": 515, "tow": 2567700, "n": -96525, "crc": 49501, "length": 22, "flags": 1, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "FC4nAPOG/v/qmf//AAAAAAAAAAAJAQ==", "d": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -26134,
                    "incorrect value for e, expected -26134, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96525,
                    "incorrect value for n, expected -96525, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "e": -25747, "sender": 55286, "msg_type": 515, "tow": 2567800, "n": -96629, "crc": 10022, "length": 22, "flags": 1, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "eC4nAIuG/v9tm///AAAAAAAAAAAJAQ==", "d": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -25747,
                    "incorrect value for e, expected -25747, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96629,
                    "incorrect value for n, expected -96629, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "e": -25360, "sender": 55286, "msg_type": 515, "tow": 2567900, "n": -96731, "crc": 34106, "length": 22, "flags": 1, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "3C4nACWG/v/wnP//AAAAAAAAAAAJAQ==", "d": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -25360,
                    "incorrect value for e, expected -25360, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96731,
                    "incorrect value for n, expected -96731, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "e": -24973, "sender": 55286, "msg_type": 515, "tow": 2568000, "n": -96831, "crc": 54840, "length": 22, "flags": 1, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "QC8nAMGF/v9znv//AAAAAAAAAAAJAQ==", "d": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -24973,
                    "incorrect value for e, expected -24973, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96831,
                    "incorrect value for n, expected -96831, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "e": -24586, "sender": 55286, "msg_type": 515, "tow": 2568100, "n": -96931, "crc": 62698, "length": 22, "flags": 1, "h_accuracy": 0, "n_sats": 9, "preamble": 85, "payload": "pC8nAF2F/v/2n///AAAAAAAAAAAJAQ==", "d": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -24586,
                    "incorrect value for e, expected -24586, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96931,
                    "incorrect value for n, expected -96931, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "e": 1265, "sender": 1219, "msg_type": 515, "tow": 407180700, "n": -2430, "crc": 5626, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 6, "preamble": 85, "payload": "nBVFGIL2///xBAAAI8T//wAAAAAGAA==", "d": -15325}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -15325,
                    "incorrect value for d, expected -15325, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 1265,
                    "incorrect value for e, expected 1265, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -2430,
                    "incorrect value for n, expected -2430, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "e": 1265, "sender": 1219, "msg_type": 515, "tow": 407180800, "n": -2430, "crc": 34288, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 6, "preamble": 85, "payload": "ABZFGIL2///xBAAAI8T//wAAAAAGAA==", "d": -15325}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -15325,
                    "incorrect value for d, expected -15325, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 1265,
                    "incorrect value for e, expected 1265, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -2430,
                    "incorrect value for n, expected -2430, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "e": 3015, "sender": 1219, "msg_type": 515, "tow": 407180900, "n": -1248, "crc": 46348, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 6, "preamble": 85, "payload": "ZBZFGCD7///HCwAAOaH//wAAAAAGAA==", "d": -24263}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -24263,
                    "incorrect value for d, expected -24263, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 3015,
                    "incorrect value for e, expected 3015, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -1248,
                    "incorrect value for n, expected -1248, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "e": 3015, "sender": 1219, "msg_type": 515, "tow": 407181000, "n": -1247, "crc": 14934, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 6, "preamble": 85, "payload": "yBZFGCH7///HCwAANqH//wAAAAAGAA==", "d": -24266}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -24266,
                    "incorrect value for d, expected -24266, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 3015,
                    "incorrect value for e, expected 3015, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -1247,
                    "incorrect value for n, expected -1247, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "e": 2103, "sender": 1219, "msg_type": 515, "tow": 407181100, "n": 1646, "crc": 63795, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 6, "preamble": 85, "payload": "LBdFGG4GAAA3CAAAoKb//wAAAAAGAA==", "d": -22880}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -22880,
                    "incorrect value for d, expected -22880, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 2103,
                    "incorrect value for e, expected 2103, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, 1646,
                    "incorrect value for n, expected 1646, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "e": 2102, "sender": 1219, "msg_type": 515, "tow": 407181200, "n": 1646, "crc": 5838, "length": 22, "flags": 0, "h_accuracy": 0, "n_sats": 6, "preamble": 85, "payload": "kBdFGG4GAAA2CAAAoKb//wAAAAAGAA==", "d": -22880}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -22880,
                    "incorrect value for d, expected -22880, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 2102,
                    "incorrect value for e, expected 2102, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, 1646,
                    "incorrect value for n, expected 1646, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_baseline_ned_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_baseline_ned_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 246, 215, 22, 20, 46, 39, 0, 243, 134, 254, 255, 234, 153, 255, 255, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 1, 93, 193,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineNedDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -26134,
                    "incorrect value for e, expected -26134, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96525,
                    "incorrect value for n, expected -96525, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 246, 215, 22, 120, 46, 39, 0, 139, 134, 254, 255, 109, 155, 255, 255, 0, 0,
            0, 0, 0, 0, 0, 0, 9, 1, 38, 39,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineNedDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -25747,
                    "incorrect value for e, expected -25747, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96629,
                    "incorrect value for n, expected -96629, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 246, 215, 22, 220, 46, 39, 0, 37, 134, 254, 255, 240, 156, 255, 255, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 1, 58, 133,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineNedDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -25360,
                    "incorrect value for e, expected -25360, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96731,
                    "incorrect value for n, expected -96731, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 246, 215, 22, 64, 47, 39, 0, 193, 133, 254, 255, 115, 158, 255, 255, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 1, 56, 214,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineNedDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -24973,
                    "incorrect value for e, expected -24973, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96831,
                    "incorrect value for n, expected -96831, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 246, 215, 22, 164, 47, 39, 0, 93, 133, 254, 255, 246, 159, 255, 255, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 1, 234, 244,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineNedDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 0, "incorrect value for d, expected 0, is {}", msg.d);
                assert_eq!(
                    msg.e, -24586,
                    "incorrect value for e, expected -24586, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -96931,
                    "incorrect value for n, expected -96931, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 195, 4, 22, 156, 21, 69, 24, 130, 246, 255, 255, 241, 4, 0, 0, 35, 196, 255,
            255, 0, 0, 0, 0, 6, 0, 250, 21,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineNedDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -15325,
                    "incorrect value for d, expected -15325, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 1265,
                    "incorrect value for e, expected 1265, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -2430,
                    "incorrect value for n, expected -2430, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 195, 4, 22, 0, 22, 69, 24, 130, 246, 255, 255, 241, 4, 0, 0, 35, 196, 255,
            255, 0, 0, 0, 0, 6, 0, 240, 133,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineNedDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -15325,
                    "incorrect value for d, expected -15325, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 1265,
                    "incorrect value for e, expected 1265, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -2430,
                    "incorrect value for n, expected -2430, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 195, 4, 22, 100, 22, 69, 24, 32, 251, 255, 255, 199, 11, 0, 0, 57, 161, 255,
            255, 0, 0, 0, 0, 6, 0, 12, 181,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineNedDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -24263,
                    "incorrect value for d, expected -24263, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 3015,
                    "incorrect value for e, expected 3015, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -1248,
                    "incorrect value for n, expected -1248, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 195, 4, 22, 200, 22, 69, 24, 33, 251, 255, 255, 199, 11, 0, 0, 54, 161, 255,
            255, 0, 0, 0, 0, 6, 0, 86, 58,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineNedDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -24266,
                    "incorrect value for d, expected -24266, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 3015,
                    "incorrect value for e, expected 3015, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, -1247,
                    "incorrect value for n, expected -1247, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 195, 4, 22, 44, 23, 69, 24, 110, 6, 0, 0, 55, 8, 0, 0, 160, 166, 255, 255, 0,
            0, 0, 0, 6, 0, 51, 249,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineNedDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -22880,
                    "incorrect value for d, expected -22880, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 2103,
                    "incorrect value for e, expected 2103, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, 1646,
                    "incorrect value for n, expected 1646, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 3, 2, 195, 4, 22, 144, 23, 69, 24, 110, 6, 0, 0, 54, 8, 0, 0, 160, 166, 255, 255,
            0, 0, 0, 0, 6, 0, 206, 22,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineNedDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -22880,
                    "incorrect value for d, expected -22880, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 2102,
                    "incorrect value for e, expected 2102, is {}",
                    msg.e
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert_eq!(
                    msg.n, 1646,
                    "incorrect value for n, expected 1646, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
