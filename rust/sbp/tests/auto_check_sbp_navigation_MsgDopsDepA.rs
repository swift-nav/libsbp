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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDopsDepA.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_navigation_MsgDopsDepA() {
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 246, 215, 14, 8, 48, 39, 0, 180, 0, 190, 0, 170, 0, 160, 0, 150, 0, 121, 170,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 180,
                    "incorrect value for gdop, expected 180, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 160,
                    "incorrect value for hdop, expected 160, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 190,
                    "incorrect value for pdop, expected 190, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 170,
                    "incorrect value for tdop, expected 170, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 2568200,
                    "incorrect value for tow, expected 2568200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 150,
                    "incorrect value for vdop, expected 150, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 246, 215, 14, 240, 51, 39, 0, 180, 0, 190, 0, 170, 0, 160, 0, 150, 0, 78, 169,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 180,
                    "incorrect value for gdop, expected 180, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 160,
                    "incorrect value for hdop, expected 160, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 190,
                    "incorrect value for pdop, expected 190, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 170,
                    "incorrect value for tdop, expected 170, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 2569200,
                    "incorrect value for tow, expected 2569200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 150,
                    "incorrect value for vdop, expected 150, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 246, 215, 14, 216, 55, 39, 0, 180, 0, 190, 0, 170, 0, 160, 0, 150, 0, 71, 218,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 180,
                    "incorrect value for gdop, expected 180, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 160,
                    "incorrect value for hdop, expected 160, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 190,
                    "incorrect value for pdop, expected 190, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 170,
                    "incorrect value for tdop, expected 170, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 2570200,
                    "incorrect value for tow, expected 2570200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 150,
                    "incorrect value for vdop, expected 150, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 195, 4, 14, 212, 157, 67, 24, 247, 0, 215, 0, 123, 0, 17, 1, 44, 0, 206, 21,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 247,
                    "incorrect value for gdop, expected 247, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 273,
                    "incorrect value for hdop, expected 273, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 215,
                    "incorrect value for pdop, expected 215, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 123,
                    "incorrect value for tdop, expected 123, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 407084500,
                    "incorrect value for tow, expected 407084500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 44,
                    "incorrect value for vdop, expected 44, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 195, 4, 14, 0, 0, 0, 0, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 146, 12,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 65535,
                    "incorrect value for gdop, expected 65535, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 0,
                    "incorrect value for hdop, expected 0, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 65535,
                    "incorrect value for pdop, expected 65535, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 0,
                    "incorrect value for tdop, expected 0, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 0,
                    "incorrect value for tow, expected 0, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 0,
                    "incorrect value for vdop, expected 0, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 195, 4, 14, 128, 165, 68, 24, 92, 1, 56, 1, 155, 0, 125, 2, 113, 0, 129, 93,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 348,
                    "incorrect value for gdop, expected 348, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 637,
                    "incorrect value for hdop, expected 637, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 312,
                    "incorrect value for pdop, expected 312, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 155,
                    "incorrect value for tdop, expected 155, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 407152000,
                    "incorrect value for tow, expected 407152000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 113,
                    "incorrect value for vdop, expected 113, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 195, 4, 14, 104, 169, 68, 24, 92, 1, 55, 1, 155, 0, 125, 2, 113, 0, 209, 128,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 348,
                    "incorrect value for gdop, expected 348, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 637,
                    "incorrect value for hdop, expected 637, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 311,
                    "incorrect value for pdop, expected 311, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 155,
                    "incorrect value for tdop, expected 155, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 407153000,
                    "incorrect value for tow, expected 407153000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 113,
                    "incorrect value for vdop, expected 113, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 195, 4, 14, 80, 173, 68, 24, 92, 1, 55, 1, 155, 0, 125, 2, 112, 0, 30, 6,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 348,
                    "incorrect value for gdop, expected 348, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 637,
                    "incorrect value for hdop, expected 637, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 311,
                    "incorrect value for pdop, expected 311, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 155,
                    "incorrect value for tdop, expected 155, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 407154000,
                    "incorrect value for tow, expected 407154000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 112,
                    "incorrect value for vdop, expected 112, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 195, 4, 14, 56, 177, 68, 24, 92, 1, 55, 1, 155, 0, 125, 2, 112, 0, 70, 67,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 348,
                    "incorrect value for gdop, expected 348, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 637,
                    "incorrect value for hdop, expected 637, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 311,
                    "incorrect value for pdop, expected 311, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 155,
                    "incorrect value for tdop, expected 155, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 407155000,
                    "incorrect value for tow, expected 407155000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 112,
                    "incorrect value for vdop, expected 112, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
