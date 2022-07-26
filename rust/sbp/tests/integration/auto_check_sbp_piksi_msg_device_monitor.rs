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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgDeviceMonitor.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_piksi_msg_device_monitor() {
    {
        let mut payload = Cursor::new(vec![
            85, 181, 0, 95, 66, 10, 241, 216, 219, 3, 253, 6, 21, 24, 168, 18, 207, 233,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6165,
                    "incorrect value for cpu_temperature, expected 6165, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1789,
                    "incorrect value for cpu_vaux, expected 1789, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 987,
                    "incorrect value for cpu_vint, expected 987, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 181, 0, 95, 66, 10, 241, 216, 219, 3, 254, 6, 24, 24, 168, 18, 169, 30,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6168,
                    "incorrect value for cpu_temperature, expected 6168, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1790,
                    "incorrect value for cpu_vaux, expected 1790, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 987,
                    "incorrect value for cpu_vint, expected 987, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 181, 0, 95, 66, 10, 241, 216, 219, 3, 253, 6, 22, 24, 168, 18, 19, 114,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6166,
                    "incorrect value for cpu_temperature, expected 6166, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1789,
                    "incorrect value for cpu_vaux, expected 1789, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 987,
                    "incorrect value for cpu_vint, expected 987, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 181, 0, 95, 66, 10, 241, 216, 218, 3, 252, 6, 6, 24, 168, 18, 199, 107,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6150,
                    "incorrect value for cpu_temperature, expected 6150, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1788,
                    "incorrect value for cpu_vaux, expected 1788, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 986,
                    "incorrect value for cpu_vint, expected 986, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 181, 0, 95, 66, 10, 241, 216, 220, 3, 253, 6, 235, 23, 168, 18, 241, 63,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6123,
                    "incorrect value for cpu_temperature, expected 6123, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1789,
                    "incorrect value for cpu_vaux, expected 1789, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 988,
                    "incorrect value for cpu_vint, expected 988, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
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
fn test_json2sbp_auto_check_sbp_piksi_msg_device_monitor() {
    {
        let json_input = r#"{"cpu_vint": 987, "sender": 16991, "msg_type": 181, "cpu_vaux": 1789, "fe_temperature": 4776, "dev_vin": -9999, "crc": 59855, "length": 10, "cpu_temperature": 6165, "preamble": 85, "payload": "8djbA/0GFRioEg=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6165,
                    "incorrect value for cpu_temperature, expected 6165, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1789,
                    "incorrect value for cpu_vaux, expected 1789, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 987,
                    "incorrect value for cpu_vint, expected 987, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };
    }
    {
        let json_input = r#"{"cpu_vint": 987, "sender": 16991, "msg_type": 181, "cpu_vaux": 1790, "fe_temperature": 4776, "dev_vin": -9999, "crc": 7849, "length": 10, "cpu_temperature": 6168, "preamble": 85, "payload": "8djbA/4GGBioEg=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6168,
                    "incorrect value for cpu_temperature, expected 6168, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1790,
                    "incorrect value for cpu_vaux, expected 1790, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 987,
                    "incorrect value for cpu_vint, expected 987, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };
    }
    {
        let json_input = r#"{"cpu_vint": 987, "sender": 16991, "msg_type": 181, "cpu_vaux": 1789, "fe_temperature": 4776, "dev_vin": -9999, "crc": 29203, "length": 10, "cpu_temperature": 6166, "preamble": 85, "payload": "8djbA/0GFhioEg=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6166,
                    "incorrect value for cpu_temperature, expected 6166, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1789,
                    "incorrect value for cpu_vaux, expected 1789, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 987,
                    "incorrect value for cpu_vint, expected 987, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };
    }
    {
        let json_input = r#"{"cpu_vint": 986, "sender": 16991, "msg_type": 181, "cpu_vaux": 1788, "fe_temperature": 4776, "dev_vin": -9999, "crc": 27591, "length": 10, "cpu_temperature": 6150, "preamble": 85, "payload": "8djaA/wGBhioEg=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6150,
                    "incorrect value for cpu_temperature, expected 6150, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1788,
                    "incorrect value for cpu_vaux, expected 1788, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 986,
                    "incorrect value for cpu_vint, expected 986, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };
    }
    {
        let json_input = r#"{"cpu_vint": 988, "sender": 16991, "msg_type": 181, "cpu_vaux": 1789, "fe_temperature": 4776, "dev_vin": -9999, "crc": 16369, "length": 10, "cpu_temperature": 6123, "preamble": 85, "payload": "8djcA/0G6xeoEg=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6123,
                    "incorrect value for cpu_temperature, expected 6123, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1789,
                    "incorrect value for cpu_vaux, expected 1789, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 988,
                    "incorrect value for cpu_vint, expected 988, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_piksi_msg_device_monitor`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_piksi_msg_device_monitor() {
    {
        let mut payload = Cursor::new(vec![
            85, 181, 0, 95, 66, 10, 241, 216, 219, 3, 253, 6, 21, 24, 168, 18, 207, 233,
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
        let sbp_msg = sbp::messages::Sbp::MsgDeviceMonitor(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6165,
                    "incorrect value for cpu_temperature, expected 6165, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1789,
                    "incorrect value for cpu_vaux, expected 1789, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 987,
                    "incorrect value for cpu_vint, expected 987, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 181, 0, 95, 66, 10, 241, 216, 219, 3, 254, 6, 24, 24, 168, 18, 169, 30,
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
        let sbp_msg = sbp::messages::Sbp::MsgDeviceMonitor(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6168,
                    "incorrect value for cpu_temperature, expected 6168, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1790,
                    "incorrect value for cpu_vaux, expected 1790, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 987,
                    "incorrect value for cpu_vint, expected 987, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 181, 0, 95, 66, 10, 241, 216, 219, 3, 253, 6, 22, 24, 168, 18, 19, 114,
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
        let sbp_msg = sbp::messages::Sbp::MsgDeviceMonitor(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6166,
                    "incorrect value for cpu_temperature, expected 6166, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1789,
                    "incorrect value for cpu_vaux, expected 1789, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 987,
                    "incorrect value for cpu_vint, expected 987, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 181, 0, 95, 66, 10, 241, 216, 218, 3, 252, 6, 6, 24, 168, 18, 199, 107,
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
        let sbp_msg = sbp::messages::Sbp::MsgDeviceMonitor(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6150,
                    "incorrect value for cpu_temperature, expected 6150, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1788,
                    "incorrect value for cpu_vaux, expected 1788, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 986,
                    "incorrect value for cpu_vint, expected 986, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 181, 0, 95, 66, 10, 241, 216, 220, 3, 253, 6, 235, 23, 168, 18, 241, 63,
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
        let sbp_msg = sbp::messages::Sbp::MsgDeviceMonitor(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgDeviceMonitor(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xb5,
                    "Incorrect message type, expected 0xb5, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x425f,
                    "incorrect sender id, expected 0x425f, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cpu_temperature, 6123,
                    "incorrect value for cpu_temperature, expected 6123, is {}",
                    msg.cpu_temperature
                );
                assert_eq!(
                    msg.cpu_vaux, 1789,
                    "incorrect value for cpu_vaux, expected 1789, is {}",
                    msg.cpu_vaux
                );
                assert_eq!(
                    msg.cpu_vint, 988,
                    "incorrect value for cpu_vint, expected 988, is {}",
                    msg.cpu_vint
                );
                assert_eq!(
                    msg.dev_vin, -9999,
                    "incorrect value for dev_vin, expected -9999, is {}",
                    msg.dev_vin
                );
                assert_eq!(
                    msg.fe_temperature, 4776,
                    "incorrect value for fe_temperature, expected 4776, is {}",
                    msg.fe_temperature
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDeviceMonitor"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
