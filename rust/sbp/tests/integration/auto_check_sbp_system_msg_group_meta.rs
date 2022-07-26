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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgGroupMeta.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_system_msg_group_meta() {
    {
        let mut payload = Cursor::new(vec![
            85, 10, 255, 238, 238, 9, 1, 2, 3, 10, 255, 10, 2, 2, 255, 2, 14,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGroupMeta(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xFF0A,
                    "Incorrect message type, expected 0xFF0A, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xEEEE,
                    "incorrect sender id, expected 0xEEEE, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.group_id, 1,
                    "incorrect value for group_id, expected 1, is {}",
                    msg.group_id
                );
                assert_eq!(
                    msg.group_msgs[0], 65290,
                    "incorrect value for group_msgs[0], expected 65290, is {}",
                    msg.group_msgs[0]
                );
                assert_eq!(
                    msg.group_msgs[1], 522,
                    "incorrect value for group_msgs[1], expected 522, is {}",
                    msg.group_msgs[1]
                );
                assert_eq!(
                    msg.group_msgs[2], 65282,
                    "incorrect value for group_msgs[2], expected 65282, is {}",
                    msg.group_msgs[2]
                );
                assert_eq!(
                    msg.n_group_msgs, 3,
                    "incorrect value for n_group_msgs, expected 3, is {}",
                    msg.n_group_msgs
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGroupMeta"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 10, 255, 21, 3, 31, 1, 1, 14, 2, 1, 3, 1, 10, 2, 17, 2, 9, 2, 20, 2, 14, 2, 18, 2,
            13, 2, 21, 2, 33, 2, 3, 255, 6, 255, 14, 255, 82, 154,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGroupMeta(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xFF0A,
                    "Incorrect message type, expected 0xFF0A, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x315,
                    "incorrect sender id, expected 0x315, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.group_id, 1,
                    "incorrect value for group_id, expected 1, is {}",
                    msg.group_id
                );
                assert_eq!(
                    msg.group_msgs[0], 258,
                    "incorrect value for group_msgs[0], expected 258, is {}",
                    msg.group_msgs[0]
                );
                assert_eq!(
                    msg.group_msgs[1], 259,
                    "incorrect value for group_msgs[1], expected 259, is {}",
                    msg.group_msgs[1]
                );
                assert_eq!(
                    msg.group_msgs[2], 522,
                    "incorrect value for group_msgs[2], expected 522, is {}",
                    msg.group_msgs[2]
                );
                assert_eq!(
                    msg.group_msgs[3], 529,
                    "incorrect value for group_msgs[3], expected 529, is {}",
                    msg.group_msgs[3]
                );
                assert_eq!(
                    msg.group_msgs[4], 521,
                    "incorrect value for group_msgs[4], expected 521, is {}",
                    msg.group_msgs[4]
                );
                assert_eq!(
                    msg.group_msgs[5], 532,
                    "incorrect value for group_msgs[5], expected 532, is {}",
                    msg.group_msgs[5]
                );
                assert_eq!(
                    msg.group_msgs[6], 526,
                    "incorrect value for group_msgs[6], expected 526, is {}",
                    msg.group_msgs[6]
                );
                assert_eq!(
                    msg.group_msgs[7], 530,
                    "incorrect value for group_msgs[7], expected 530, is {}",
                    msg.group_msgs[7]
                );
                assert_eq!(
                    msg.group_msgs[8], 525,
                    "incorrect value for group_msgs[8], expected 525, is {}",
                    msg.group_msgs[8]
                );
                assert_eq!(
                    msg.group_msgs[9], 533,
                    "incorrect value for group_msgs[9], expected 533, is {}",
                    msg.group_msgs[9]
                );
                assert_eq!(
                    msg.group_msgs[10], 545,
                    "incorrect value for group_msgs[10], expected 545, is {}",
                    msg.group_msgs[10]
                );
                assert_eq!(
                    msg.group_msgs[11], 65283,
                    "incorrect value for group_msgs[11], expected 65283, is {}",
                    msg.group_msgs[11]
                );
                assert_eq!(
                    msg.group_msgs[12], 65286,
                    "incorrect value for group_msgs[12], expected 65286, is {}",
                    msg.group_msgs[12]
                );
                assert_eq!(
                    msg.group_msgs[13], 65294,
                    "incorrect value for group_msgs[13], expected 65294, is {}",
                    msg.group_msgs[13]
                );
                assert_eq!(
                    msg.n_group_msgs, 14,
                    "incorrect value for n_group_msgs, expected 14, is {}",
                    msg.n_group_msgs
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGroupMeta"),
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
fn test_json2sbp_auto_check_sbp_system_msg_group_meta() {
    {
        let json_input = r#"{"crc": 3586, "flags": 2, "group_id": 1, "sender": 61166, "msg_type": 65290, "length": 9, "n_group_msgs": 3 ,"group_msgs": [65290, 522, 65282], "preamble": 85, "payload": "AQIDCv8KAgL/"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgGroupMeta(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xFF0A,
                    "Incorrect message type, expected 0xFF0A, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xEEEE,
                    "incorrect sender id, expected 0xEEEE, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.group_id, 1,
                    "incorrect value for group_id, expected 1, is {}",
                    msg.group_id
                );
                assert_eq!(
                    msg.group_msgs[0], 65290,
                    "incorrect value for group_msgs[0], expected 65290, is {}",
                    msg.group_msgs[0]
                );
                assert_eq!(
                    msg.group_msgs[1], 522,
                    "incorrect value for group_msgs[1], expected 522, is {}",
                    msg.group_msgs[1]
                );
                assert_eq!(
                    msg.group_msgs[2], 65282,
                    "incorrect value for group_msgs[2], expected 65282, is {}",
                    msg.group_msgs[2]
                );
                assert_eq!(
                    msg.n_group_msgs, 3,
                    "incorrect value for n_group_msgs, expected 3, is {}",
                    msg.n_group_msgs
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGroupMeta"),
        };
    }
    {
        let json_input = r#"{"group_id":1,"flags":1,"n_group_msgs":14,"group_msgs":[258,259,522,529,521,532,526,530,525,533,545,65283,65286,65294],"preamble":85,"msg_type":65290,"sender":789,"payload":"AQEOAgEDAQoCEQIJAhQCDgISAg0CFQIhAgP/Bv8O/w==","crc":39506,"length":31}"#.as_bytes();

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
            sbp::messages::Sbp::MsgGroupMeta(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xFF0A,
                    "Incorrect message type, expected 0xFF0A, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x315,
                    "incorrect sender id, expected 0x315, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.group_id, 1,
                    "incorrect value for group_id, expected 1, is {}",
                    msg.group_id
                );
                assert_eq!(
                    msg.group_msgs[0], 258,
                    "incorrect value for group_msgs[0], expected 258, is {}",
                    msg.group_msgs[0]
                );
                assert_eq!(
                    msg.group_msgs[1], 259,
                    "incorrect value for group_msgs[1], expected 259, is {}",
                    msg.group_msgs[1]
                );
                assert_eq!(
                    msg.group_msgs[2], 522,
                    "incorrect value for group_msgs[2], expected 522, is {}",
                    msg.group_msgs[2]
                );
                assert_eq!(
                    msg.group_msgs[3], 529,
                    "incorrect value for group_msgs[3], expected 529, is {}",
                    msg.group_msgs[3]
                );
                assert_eq!(
                    msg.group_msgs[4], 521,
                    "incorrect value for group_msgs[4], expected 521, is {}",
                    msg.group_msgs[4]
                );
                assert_eq!(
                    msg.group_msgs[5], 532,
                    "incorrect value for group_msgs[5], expected 532, is {}",
                    msg.group_msgs[5]
                );
                assert_eq!(
                    msg.group_msgs[6], 526,
                    "incorrect value for group_msgs[6], expected 526, is {}",
                    msg.group_msgs[6]
                );
                assert_eq!(
                    msg.group_msgs[7], 530,
                    "incorrect value for group_msgs[7], expected 530, is {}",
                    msg.group_msgs[7]
                );
                assert_eq!(
                    msg.group_msgs[8], 525,
                    "incorrect value for group_msgs[8], expected 525, is {}",
                    msg.group_msgs[8]
                );
                assert_eq!(
                    msg.group_msgs[9], 533,
                    "incorrect value for group_msgs[9], expected 533, is {}",
                    msg.group_msgs[9]
                );
                assert_eq!(
                    msg.group_msgs[10], 545,
                    "incorrect value for group_msgs[10], expected 545, is {}",
                    msg.group_msgs[10]
                );
                assert_eq!(
                    msg.group_msgs[11], 65283,
                    "incorrect value for group_msgs[11], expected 65283, is {}",
                    msg.group_msgs[11]
                );
                assert_eq!(
                    msg.group_msgs[12], 65286,
                    "incorrect value for group_msgs[12], expected 65286, is {}",
                    msg.group_msgs[12]
                );
                assert_eq!(
                    msg.group_msgs[13], 65294,
                    "incorrect value for group_msgs[13], expected 65294, is {}",
                    msg.group_msgs[13]
                );
                assert_eq!(
                    msg.n_group_msgs, 14,
                    "incorrect value for n_group_msgs, expected 14, is {}",
                    msg.n_group_msgs
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGroupMeta"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_system_msg_group_meta`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_system_msg_group_meta() {
    {
        let mut payload = Cursor::new(vec![
            85, 10, 255, 238, 238, 9, 1, 2, 3, 10, 255, 10, 2, 2, 255, 2, 14,
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
        let sbp_msg = sbp::messages::Sbp::MsgGroupMeta(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgGroupMeta(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xFF0A,
                    "Incorrect message type, expected 0xFF0A, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xEEEE,
                    "incorrect sender id, expected 0xEEEE, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.group_id, 1,
                    "incorrect value for group_id, expected 1, is {}",
                    msg.group_id
                );
                assert_eq!(
                    msg.group_msgs[0], 65290,
                    "incorrect value for group_msgs[0], expected 65290, is {}",
                    msg.group_msgs[0]
                );
                assert_eq!(
                    msg.group_msgs[1], 522,
                    "incorrect value for group_msgs[1], expected 522, is {}",
                    msg.group_msgs[1]
                );
                assert_eq!(
                    msg.group_msgs[2], 65282,
                    "incorrect value for group_msgs[2], expected 65282, is {}",
                    msg.group_msgs[2]
                );
                assert_eq!(
                    msg.n_group_msgs, 3,
                    "incorrect value for n_group_msgs, expected 3, is {}",
                    msg.n_group_msgs
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGroupMeta"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 10, 255, 21, 3, 31, 1, 1, 14, 2, 1, 3, 1, 10, 2, 17, 2, 9, 2, 20, 2, 14, 2, 18, 2,
            13, 2, 21, 2, 33, 2, 3, 255, 6, 255, 14, 255, 82, 154,
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
        let sbp_msg = sbp::messages::Sbp::MsgGroupMeta(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgGroupMeta(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xFF0A,
                    "Incorrect message type, expected 0xFF0A, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x315,
                    "incorrect sender id, expected 0x315, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.group_id, 1,
                    "incorrect value for group_id, expected 1, is {}",
                    msg.group_id
                );
                assert_eq!(
                    msg.group_msgs[0], 258,
                    "incorrect value for group_msgs[0], expected 258, is {}",
                    msg.group_msgs[0]
                );
                assert_eq!(
                    msg.group_msgs[1], 259,
                    "incorrect value for group_msgs[1], expected 259, is {}",
                    msg.group_msgs[1]
                );
                assert_eq!(
                    msg.group_msgs[2], 522,
                    "incorrect value for group_msgs[2], expected 522, is {}",
                    msg.group_msgs[2]
                );
                assert_eq!(
                    msg.group_msgs[3], 529,
                    "incorrect value for group_msgs[3], expected 529, is {}",
                    msg.group_msgs[3]
                );
                assert_eq!(
                    msg.group_msgs[4], 521,
                    "incorrect value for group_msgs[4], expected 521, is {}",
                    msg.group_msgs[4]
                );
                assert_eq!(
                    msg.group_msgs[5], 532,
                    "incorrect value for group_msgs[5], expected 532, is {}",
                    msg.group_msgs[5]
                );
                assert_eq!(
                    msg.group_msgs[6], 526,
                    "incorrect value for group_msgs[6], expected 526, is {}",
                    msg.group_msgs[6]
                );
                assert_eq!(
                    msg.group_msgs[7], 530,
                    "incorrect value for group_msgs[7], expected 530, is {}",
                    msg.group_msgs[7]
                );
                assert_eq!(
                    msg.group_msgs[8], 525,
                    "incorrect value for group_msgs[8], expected 525, is {}",
                    msg.group_msgs[8]
                );
                assert_eq!(
                    msg.group_msgs[9], 533,
                    "incorrect value for group_msgs[9], expected 533, is {}",
                    msg.group_msgs[9]
                );
                assert_eq!(
                    msg.group_msgs[10], 545,
                    "incorrect value for group_msgs[10], expected 545, is {}",
                    msg.group_msgs[10]
                );
                assert_eq!(
                    msg.group_msgs[11], 65283,
                    "incorrect value for group_msgs[11], expected 65283, is {}",
                    msg.group_msgs[11]
                );
                assert_eq!(
                    msg.group_msgs[12], 65286,
                    "incorrect value for group_msgs[12], expected 65286, is {}",
                    msg.group_msgs[12]
                );
                assert_eq!(
                    msg.group_msgs[13], 65294,
                    "incorrect value for group_msgs[13], expected 65294, is {}",
                    msg.group_msgs[13]
                );
                assert_eq!(
                    msg.n_group_msgs, 14,
                    "incorrect value for n_group_msgs, expected 14, is {}",
                    msg.n_group_msgs
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGroupMeta"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
