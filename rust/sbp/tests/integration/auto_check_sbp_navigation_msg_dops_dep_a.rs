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

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_dops_dep_a() {
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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
        let frame = sbp::to_vec(&sbp_msg).unwrap();
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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
        let frame = sbp::to_vec(&sbp_msg).unwrap();
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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
        let frame = sbp::to_vec(&sbp_msg).unwrap();
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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
        let frame = sbp::to_vec(&sbp_msg).unwrap();
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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
        let frame = sbp::to_vec(&sbp_msg).unwrap();
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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
        let frame = sbp::to_vec(&sbp_msg).unwrap();
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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
        let frame = sbp::to_vec(&sbp_msg).unwrap();
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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
        let frame = sbp::to_vec(&sbp_msg).unwrap();
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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
fn test_json2sbp_auto_check_sbp_navigation_msg_dops_dep_a() {
    {
        let json_input = r#"{"gdop": 180, "tdop": 170, "vdop": 150, "sender": 55286, "msg_type": 518, "pdop": 190, "tow": 2568200, "crc": 43641, "length": 14, "preamble": 85, "payload": "CDAnALQAvgCqAKAAlgA=", "hdop": 160}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
    }
    {
        let json_input = r#"{"gdop": 180, "tdop": 170, "vdop": 150, "sender": 55286, "msg_type": 518, "pdop": 190, "tow": 2569200, "crc": 43342, "length": 14, "preamble": 85, "payload": "8DMnALQAvgCqAKAAlgA=", "hdop": 160}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
    }
    {
        let json_input = r#"{"gdop": 180, "tdop": 170, "vdop": 150, "sender": 55286, "msg_type": 518, "pdop": 190, "tow": 2570200, "crc": 55879, "length": 14, "preamble": 85, "payload": "2DcnALQAvgCqAKAAlgA=", "hdop": 160}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
    }
    {
        let json_input = r#"{"gdop": 247, "tdop": 123, "vdop": 44, "sender": 1219, "msg_type": 518, "tow": 407084500, "pdop": 215, "crc": 5582, "length": 14, "preamble": 85, "payload": "1J1DGPcA1wB7ABEBLAA=", "hdop": 273}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
    }
    {
        let json_input = r#"{"gdop": 65535, "tdop": 0, "vdop": 0, "sender": 1219, "msg_type": 518, "tow": 0, "pdop": 65535, "crc": 3218, "length": 14, "preamble": 85, "payload": "AAAAAP////8AAAAAAAA=", "hdop": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
    }
    {
        let json_input = r#"{"gdop": 348, "tdop": 155, "vdop": 113, "sender": 1219, "msg_type": 518, "tow": 407152000, "pdop": 312, "crc": 23937, "length": 14, "preamble": 85, "payload": "gKVEGFwBOAGbAH0CcQA=", "hdop": 637}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
    }
    {
        let json_input = r#"{"gdop": 348, "tdop": 155, "vdop": 113, "sender": 1219, "msg_type": 518, "tow": 407153000, "pdop": 311, "crc": 32977, "length": 14, "preamble": 85, "payload": "aKlEGFwBNwGbAH0CcQA=", "hdop": 637}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
    }
    {
        let json_input = r#"{"gdop": 348, "tdop": 155, "vdop": 112, "sender": 1219, "msg_type": 518, "tow": 407154000, "pdop": 311, "crc": 1566, "length": 14, "preamble": 85, "payload": "UK1EGFwBNwGbAH0CcAA=", "hdop": 637}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
    }
    {
        let json_input = r#"{"gdop": 348, "tdop": 155, "vdop": 112, "sender": 1219, "msg_type": 518, "tow": 407155000, "pdop": 311, "crc": 17222, "length": 14, "preamble": 85, "payload": "OLFEGFwBNwGbAH0CcAA=", "hdop": 637}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_dops_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_dops_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 246, 215, 14, 8, 48, 39, 0, 180, 0, 190, 0, 170, 0, 160, 0, 150, 0, 121, 170,
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
        let sbp_msg = sbp::messages::Sbp::MsgDopsDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 246, 215, 14, 240, 51, 39, 0, 180, 0, 190, 0, 170, 0, 160, 0, 150, 0, 78, 169,
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
        let sbp_msg = sbp::messages::Sbp::MsgDopsDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 246, 215, 14, 216, 55, 39, 0, 180, 0, 190, 0, 170, 0, 160, 0, 150, 0, 71, 218,
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
        let sbp_msg = sbp::messages::Sbp::MsgDopsDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 195, 4, 14, 212, 157, 67, 24, 247, 0, 215, 0, 123, 0, 17, 1, 44, 0, 206, 21,
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
        let sbp_msg = sbp::messages::Sbp::MsgDopsDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 195, 4, 14, 0, 0, 0, 0, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 146, 12,
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
        let sbp_msg = sbp::messages::Sbp::MsgDopsDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 195, 4, 14, 128, 165, 68, 24, 92, 1, 56, 1, 155, 0, 125, 2, 113, 0, 129, 93,
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
        let sbp_msg = sbp::messages::Sbp::MsgDopsDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 195, 4, 14, 104, 169, 68, 24, 92, 1, 55, 1, 155, 0, 125, 2, 113, 0, 209, 128,
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
        let sbp_msg = sbp::messages::Sbp::MsgDopsDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 195, 4, 14, 80, 173, 68, 24, 92, 1, 55, 1, 155, 0, 125, 2, 112, 0, 30, 6,
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
        let sbp_msg = sbp::messages::Sbp::MsgDopsDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 6, 2, 195, 4, 14, 56, 177, 68, 24, 92, 1, 55, 1, 155, 0, 125, 2, 112, 0, 70, 67,
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
        let sbp_msg = sbp::messages::Sbp::MsgDopsDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
