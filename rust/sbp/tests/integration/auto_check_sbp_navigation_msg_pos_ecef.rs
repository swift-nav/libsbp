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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEF.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_pos_ecef() {
    {
        let mut payload = Cursor::new(vec![
            85, 9, 2, 211, 136, 32, 16, 248, 122, 19, 73, 29, 46, 132, 182, 122, 68, 193, 219, 192,
            29, 176, 121, 119, 80, 193, 83, 11, 210, 90, 79, 75, 77, 65, 0, 0, 15, 2, 84, 6,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426903265729966e+06),
                    "incorrect value for x, expected -2.68426903265729966e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664675181599986e+06),
                    "incorrect value for y, expected -4.31664675181599986e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964670953504136e+06),
                    "incorrect value for z, expected 3.83964670953504136e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 9, 2, 211, 136, 32, 248, 251, 122, 19, 103, 106, 57, 136, 182, 122, 68, 193, 176,
            242, 200, 176, 121, 119, 80, 193, 244, 135, 97, 59, 79, 75, 77, 65, 0, 0, 15, 2, 147,
            216,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426906425218610e+06),
                    "incorrect value for x, expected -2.68426906425218610e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664676226489246e+06),
                    "incorrect value for y, expected -4.31664676226489246e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964646391391195e+06),
                    "incorrect value for z, expected 3.83964646391391195e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 9, 2, 211, 136, 32, 224, 255, 122, 19, 101, 179, 242, 182, 182, 122, 68, 193, 130,
            196, 145, 199, 121, 119, 80, 193, 212, 10, 253, 15, 79, 75, 77, 65, 0, 0, 15, 2, 40,
            201,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426942928163940e+06),
                    "incorrect value for x, expected -2.68426942928163940e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664711827194877e+06),
                    "incorrect value for y, expected -4.31664711827194877e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964612490973808e+06),
                    "incorrect value for z, expected 3.83964612490973808e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 9, 2, 211, 136, 32, 200, 3, 123, 19, 146, 214, 132, 215, 182, 122, 68, 193, 213,
            68, 49, 215, 121, 119, 80, 193, 71, 34, 110, 243, 78, 75, 77, 65, 0, 0, 15, 2, 187, 86,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426968374139909e+06),
                    "incorrect value for x, expected -2.68426968374139909e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664736238213349e+06),
                    "incorrect value for y, expected -4.31664736238213349e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964590179851977e+06),
                    "incorrect value for z, expected 3.83964590179851977e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_pos_ecef() {
    {
        let json_input = r#"{"n_sats": 15, "sender": 35027, "msg_type": 521, "tow": 326826000, "crc": 1620, "length": 32, "flags": 2, "y": -4316646.751816, "x": -2684269.0326572997, "z": 3839646.7095350414, "preamble": 85, "payload": "EPh6E0kdLoS2ekTB28AdsHl3UMFTC9JaT0tNQQAADwI=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426903265729966e+06),
                    "incorrect value for x, expected -2.68426903265729966e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664675181599986e+06),
                    "incorrect value for y, expected -4.31664675181599986e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964670953504136e+06),
                    "incorrect value for z, expected 3.83964670953504136e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };
    }
    {
        let json_input = r#"{"n_sats": 15, "sender": 35027, "msg_type": 521, "tow": 326827000, "crc": 55443, "length": 32, "flags": 2, "y": -4316646.762264892, "x": -2684269.064252186, "z": 3839646.463913912, "preamble": 85, "payload": "+Pt6E2dqOYi2ekTBsPLIsHl3UMH0h2E7T0tNQQAADwI=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426906425218610e+06),
                    "incorrect value for x, expected -2.68426906425218610e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664676226489246e+06),
                    "incorrect value for y, expected -4.31664676226489246e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964646391391195e+06),
                    "incorrect value for z, expected 3.83964646391391195e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };
    }
    {
        let json_input = r#"{"n_sats": 15, "sender": 35027, "msg_type": 521, "tow": 326828000, "crc": 51496, "length": 32, "flags": 2, "y": -4316647.118271949, "x": -2684269.4292816394, "z": 3839646.124909738, "preamble": 85, "payload": "4P96E2Wz8ra2ekTBgsSRx3l3UMHUCv0PT0tNQQAADwI=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426942928163940e+06),
                    "incorrect value for x, expected -2.68426942928163940e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664711827194877e+06),
                    "incorrect value for y, expected -4.31664711827194877e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964612490973808e+06),
                    "incorrect value for z, expected 3.83964612490973808e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };
    }
    {
        let json_input = r#"{"n_sats": 15, "sender": 35027, "msg_type": 521, "tow": 326829000, "crc": 22203, "length": 32, "flags": 2, "y": -4316647.3623821335, "x": -2684269.683741399, "z": 3839645.90179852, "preamble": 85, "payload": "yAN7E5LWhNe2ekTB1UQx13l3UMFHIm7zTktNQQAADwI=", "accuracy": 0}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426968374139909e+06),
                    "incorrect value for x, expected -2.68426968374139909e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664736238213349e+06),
                    "incorrect value for y, expected -4.31664736238213349e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964590179851977e+06),
                    "incorrect value for z, expected 3.83964590179851977e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_pos_ecef`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_pos_ecef() {
    {
        let mut payload = Cursor::new(vec![
            85, 9, 2, 211, 136, 32, 16, 248, 122, 19, 73, 29, 46, 132, 182, 122, 68, 193, 219, 192,
            29, 176, 121, 119, 80, 193, 83, 11, 210, 90, 79, 75, 77, 65, 0, 0, 15, 2, 84, 6,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosEcef(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426903265729966e+06),
                    "incorrect value for x, expected -2.68426903265729966e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664675181599986e+06),
                    "incorrect value for y, expected -4.31664675181599986e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964670953504136e+06),
                    "incorrect value for z, expected 3.83964670953504136e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 9, 2, 211, 136, 32, 248, 251, 122, 19, 103, 106, 57, 136, 182, 122, 68, 193, 176,
            242, 200, 176, 121, 119, 80, 193, 244, 135, 97, 59, 79, 75, 77, 65, 0, 0, 15, 2, 147,
            216,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosEcef(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426906425218610e+06),
                    "incorrect value for x, expected -2.68426906425218610e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664676226489246e+06),
                    "incorrect value for y, expected -4.31664676226489246e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964646391391195e+06),
                    "incorrect value for z, expected 3.83964646391391195e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 9, 2, 211, 136, 32, 224, 255, 122, 19, 101, 179, 242, 182, 182, 122, 68, 193, 130,
            196, 145, 199, 121, 119, 80, 193, 212, 10, 253, 15, 79, 75, 77, 65, 0, 0, 15, 2, 40,
            201,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosEcef(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426942928163940e+06),
                    "incorrect value for x, expected -2.68426942928163940e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664711827194877e+06),
                    "incorrect value for y, expected -4.31664711827194877e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964612490973808e+06),
                    "incorrect value for z, expected 3.83964612490973808e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 9, 2, 211, 136, 32, 200, 3, 123, 19, 146, 214, 132, 215, 182, 122, 68, 193, 213,
            68, 49, 215, 121, 119, 80, 193, 71, 34, 110, 243, 78, 75, 77, 65, 0, 0, 15, 2, 187, 86,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosEcef(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcef(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426968374139909e+06),
                    "incorrect value for x, expected -2.68426968374139909e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664736238213349e+06),
                    "incorrect value for y, expected -4.31664736238213349e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964590179851977e+06),
                    "incorrect value for z, expected 3.83964590179851977e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
