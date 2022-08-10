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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEF.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_baseline_ecef() {
    {
        let mut payload = Cursor::new(vec![
            85, 11, 2, 211, 136, 20, 40, 244, 122, 19, 150, 98, 238, 255, 190, 64, 20, 0, 246, 163,
            9, 0, 0, 0, 14, 0, 219, 191,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 14,
                    "incorrect value for n_sats, expected 14, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326825000,
                    "incorrect value for tow, expected 326825000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154410,
                    "incorrect value for x, expected -1154410, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327294,
                    "incorrect value for y, expected 1327294, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 631798,
                    "incorrect value for z, expected 631798, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 11, 2, 211, 136, 20, 16, 248, 122, 19, 72, 99, 238, 255, 191, 65, 20, 0, 138, 162,
            9, 0, 0, 0, 15, 0, 240, 78,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326826000,
                    "incorrect value for tow, expected 326826000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154232,
                    "incorrect value for x, expected -1154232, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327551,
                    "incorrect value for y, expected 1327551, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 631434,
                    "incorrect value for z, expected 631434, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 11, 2, 211, 136, 20, 248, 251, 122, 19, 41, 99, 238, 255, 181, 65, 20, 0, 148, 161,
            9, 0, 0, 0, 15, 0, 4, 132,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326827000,
                    "incorrect value for tow, expected 326827000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154263,
                    "incorrect value for x, expected -1154263, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327541,
                    "incorrect value for y, expected 1327541, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 631188,
                    "incorrect value for z, expected 631188, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 11, 2, 211, 136, 20, 224, 255, 122, 19, 188, 97, 238, 255, 81, 64, 20, 0, 65, 160,
            9, 0, 0, 0, 15, 0, 67, 94,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326828000,
                    "incorrect value for tow, expected 326828000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154628,
                    "incorrect value for x, expected -1154628, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327185,
                    "incorrect value for y, expected 1327185, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 630849,
                    "incorrect value for z, expected 630849, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 11, 2, 211, 136, 20, 200, 3, 123, 19, 189, 96, 238, 255, 93, 63, 20, 0, 98, 159, 9,
            0, 0, 0, 15, 0, 106, 94,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326829000,
                    "incorrect value for tow, expected 326829000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154883,
                    "incorrect value for x, expected -1154883, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1326941,
                    "incorrect value for y, expected 1326941, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 630626,
                    "incorrect value for z, expected 630626, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_baseline_ecef() {
    {
        let json_input = r#"{"n_sats": 14, "sender": 35027, "msg_type": 523, "tow": 326825000, "crc": 49115, "length": 20, "flags": 0, "y": 1327294, "x": -1154410, "z": 631798, "preamble": 85, "payload": "KPR6E5Zi7v++QBQA9qMJAAAADgA=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 14,
                    "incorrect value for n_sats, expected 14, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326825000,
                    "incorrect value for tow, expected 326825000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154410,
                    "incorrect value for x, expected -1154410, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327294,
                    "incorrect value for y, expected 1327294, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 631798,
                    "incorrect value for z, expected 631798, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };
    }
    {
        let json_input = r#"{"n_sats": 15, "sender": 35027, "msg_type": 523, "tow": 326826000, "crc": 20208, "length": 20, "flags": 0, "y": 1327551, "x": -1154232, "z": 631434, "preamble": 85, "payload": "EPh6E0hj7v+/QRQAiqIJAAAADwA=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326826000,
                    "incorrect value for tow, expected 326826000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154232,
                    "incorrect value for x, expected -1154232, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327551,
                    "incorrect value for y, expected 1327551, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 631434,
                    "incorrect value for z, expected 631434, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };
    }
    {
        let json_input = r#"{"n_sats": 15, "sender": 35027, "msg_type": 523, "tow": 326827000, "crc": 33796, "length": 20, "flags": 0, "y": 1327541, "x": -1154263, "z": 631188, "preamble": 85, "payload": "+Pt6Eylj7v+1QRQAlKEJAAAADwA=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326827000,
                    "incorrect value for tow, expected 326827000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154263,
                    "incorrect value for x, expected -1154263, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327541,
                    "incorrect value for y, expected 1327541, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 631188,
                    "incorrect value for z, expected 631188, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };
    }
    {
        let json_input = r#"{"n_sats": 15, "sender": 35027, "msg_type": 523, "tow": 326828000, "crc": 24131, "length": 20, "flags": 0, "y": 1327185, "x": -1154628, "z": 630849, "preamble": 85, "payload": "4P96E7xh7v9RQBQAQaAJAAAADwA=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326828000,
                    "incorrect value for tow, expected 326828000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154628,
                    "incorrect value for x, expected -1154628, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327185,
                    "incorrect value for y, expected 1327185, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 630849,
                    "incorrect value for z, expected 630849, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };
    }
    {
        let json_input = r#"{"n_sats": 15, "sender": 35027, "msg_type": 523, "tow": 326829000, "crc": 24170, "length": 20, "flags": 0, "y": 1326941, "x": -1154883, "z": 630626, "preamble": 85, "payload": "yAN7E71g7v9dPxQAYp8JAAAADwA=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326829000,
                    "incorrect value for tow, expected 326829000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154883,
                    "incorrect value for x, expected -1154883, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1326941,
                    "incorrect value for y, expected 1326941, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 630626,
                    "incorrect value for z, expected 630626, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_baseline_ecef`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_baseline_ecef() {
    {
        let mut payload = Cursor::new(vec![
            85, 11, 2, 211, 136, 20, 40, 244, 122, 19, 150, 98, 238, 255, 190, 64, 20, 0, 246, 163,
            9, 0, 0, 0, 14, 0, 219, 191,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcef(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 14,
                    "incorrect value for n_sats, expected 14, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326825000,
                    "incorrect value for tow, expected 326825000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154410,
                    "incorrect value for x, expected -1154410, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327294,
                    "incorrect value for y, expected 1327294, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 631798,
                    "incorrect value for z, expected 631798, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 11, 2, 211, 136, 20, 16, 248, 122, 19, 72, 99, 238, 255, 191, 65, 20, 0, 138, 162,
            9, 0, 0, 0, 15, 0, 240, 78,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcef(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326826000,
                    "incorrect value for tow, expected 326826000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154232,
                    "incorrect value for x, expected -1154232, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327551,
                    "incorrect value for y, expected 1327551, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 631434,
                    "incorrect value for z, expected 631434, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 11, 2, 211, 136, 20, 248, 251, 122, 19, 41, 99, 238, 255, 181, 65, 20, 0, 148, 161,
            9, 0, 0, 0, 15, 0, 4, 132,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcef(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326827000,
                    "incorrect value for tow, expected 326827000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154263,
                    "incorrect value for x, expected -1154263, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327541,
                    "incorrect value for y, expected 1327541, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 631188,
                    "incorrect value for z, expected 631188, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 11, 2, 211, 136, 20, 224, 255, 122, 19, 188, 97, 238, 255, 81, 64, 20, 0, 65, 160,
            9, 0, 0, 0, 15, 0, 67, 94,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcef(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326828000,
                    "incorrect value for tow, expected 326828000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154628,
                    "incorrect value for x, expected -1154628, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327185,
                    "incorrect value for y, expected 1327185, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 630849,
                    "incorrect value for z, expected 630849, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 11, 2, 211, 136, 20, 200, 3, 123, 19, 189, 96, 238, 255, 93, 63, 20, 0, 98, 159, 9,
            0, 0, 0, 15, 0, 106, 94,
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
        let sbp_msg = sbp::messages::Sbp::MsgBaselineEcef(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgBaselineEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326829000,
                    "incorrect value for tow, expected 326829000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154883,
                    "incorrect value for x, expected -1154883, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1326941,
                    "incorrect value for y, expected 1326941, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 630626,
                    "incorrect value for z, expected 630626, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
