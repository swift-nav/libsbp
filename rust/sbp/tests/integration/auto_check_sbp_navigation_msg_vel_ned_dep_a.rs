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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNEDDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_vel_ned_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 5, 2, 246, 215, 22, 20, 46, 39, 0, 198, 251, 255, 255, 156, 15, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 9, 0, 161, 92,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
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
                    msg.e, 3996,
                    "incorrect value for e, expected 3996, is {}",
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
                    msg.n, -1082,
                    "incorrect value for n, expected -1082, is {}",
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
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 5, 2, 246, 215, 22, 120, 46, 39, 0, 14, 252, 255, 255, 207, 14, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 9, 0, 125, 160,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
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
                    msg.e, 3791,
                    "incorrect value for e, expected 3791, is {}",
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
                    msg.n, -1010,
                    "incorrect value for n, expected -1010, is {}",
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
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 5, 2, 246, 215, 22, 220, 46, 39, 0, 48, 252, 255, 255, 140, 14, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 9, 0, 179, 135,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
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
                    msg.e, 3724,
                    "incorrect value for e, expected 3724, is {}",
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
                    msg.n, -976,
                    "incorrect value for n, expected -976, is {}",
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
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 5, 2, 246, 215, 22, 64, 47, 39, 0, 32, 252, 255, 255, 8, 15, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 9, 0, 51, 177,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
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
                    msg.e, 3848,
                    "incorrect value for e, expected 3848, is {}",
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
                    msg.n, -992,
                    "incorrect value for n, expected -992, is {}",
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
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 5, 2, 246, 215, 22, 164, 47, 39, 0, 80, 252, 255, 255, 140, 14, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 9, 0, 23, 0,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
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
                    msg.e, 3724,
                    "incorrect value for e, expected 3724, is {}",
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
                    msg.n, -944,
                    "incorrect value for n, expected -944, is {}",
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
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 5, 2, 195, 4, 22, 212, 157, 67, 24, 229, 255, 255, 255, 26, 0, 0, 0, 25, 0, 0, 0,
            0, 0, 0, 0, 8, 0, 132, 25,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, 25,
                    "incorrect value for d, expected 25, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 26,
                    "incorrect value for e, expected 26, is {}",
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
                    msg.n, -27,
                    "incorrect value for n, expected -27, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 5, 2, 195, 4, 22, 56, 158, 67, 24, 4, 0, 0, 0, 15, 0, 0, 0, 232, 255, 255, 255, 0,
            0, 0, 0, 8, 0, 42, 14,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -24,
                    "incorrect value for d, expected -24, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 15,
                    "incorrect value for e, expected 15, is {}",
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
                assert_eq!(msg.n, 4, "incorrect value for n, expected 4, is {}", msg.n);
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
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 5, 2, 195, 4, 22, 156, 158, 67, 24, 251, 255, 255, 255, 232, 255, 255, 255, 247,
            255, 255, 255, 0, 0, 0, 0, 8, 0, 218, 148,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -9,
                    "incorrect value for d, expected -9, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, -24,
                    "incorrect value for e, expected -24, is {}",
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
                    msg.n, -5,
                    "incorrect value for n, expected -5, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 5, 2, 195, 4, 22, 0, 159, 67, 24, 10, 0, 0, 0, 2, 0, 0, 0, 222, 255, 255, 255, 0,
            0, 0, 0, 8, 0, 148, 16,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -34,
                    "incorrect value for d, expected -34, is {}",
                    msg.d
                );
                assert_eq!(msg.e, 2, "incorrect value for e, expected 2, is {}", msg.e);
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
                    msg.n, 10,
                    "incorrect value for n, expected 10, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 5, 2, 195, 4, 22, 100, 159, 67, 24, 248, 255, 255, 255, 254, 255, 255, 255, 7, 0,
            0, 0, 0, 0, 0, 0, 8, 0, 255, 236,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 7, "incorrect value for d, expected 7, is {}", msg.d);
                assert_eq!(
                    msg.e, -2,
                    "incorrect value for e, expected -2, is {}",
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
                    msg.n, -8,
                    "incorrect value for n, expected -8, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 5, 2, 195, 4, 22, 46, 162, 68, 24, 255, 255, 255, 255, 253, 255, 255, 255, 148,
            255, 255, 255, 0, 0, 0, 0, 5, 0, 166, 189,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelNedDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -108,
                    "incorrect value for d, expected -108, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, -3,
                    "incorrect value for e, expected -3, is {}",
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
                    msg.n, -1,
                    "incorrect value for n, expected -1, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
