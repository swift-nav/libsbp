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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgPrintDep.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_logging_msg_print_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 16, 0, 34, 34, 43, 73, 78, 70, 79, 58, 32, 97, 99, 113, 58, 32, 80, 82, 78, 32, 49,
            53, 32, 102, 111, 117, 110, 100, 32, 64, 32, 45, 50, 52, 57, 55, 32, 72, 122, 44, 32,
            50, 48, 32, 83, 78, 82, 10, 116, 103,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 16, 0, 34, 34, 42, 73, 78, 70, 79, 58, 32, 97, 99, 113, 58, 32, 80, 82, 78, 32, 51,
            49, 32, 102, 111, 117, 110, 100, 32, 64, 32, 52, 50, 52, 53, 32, 72, 122, 44, 32, 50,
            49, 32, 83, 78, 82, 10, 140, 43,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 16, 0, 34, 34, 35, 73, 78, 70, 79, 58, 32, 68, 105, 115, 97, 98, 108, 105, 110,
            103, 32, 99, 104, 97, 110, 110, 101, 108, 32, 48, 32, 40, 80, 82, 78, 32, 49, 49, 41,
            10, 23, 143,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: Disabling channel 0 (PRN 11)
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: Disabling channel 0 (PRN 11)
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 16, 0, 34, 34, 41, 73, 78, 70, 79, 58, 32, 97, 99, 113, 58, 32, 80, 82, 78, 32, 50,
            32, 102, 111, 117, 110, 100, 32, 64, 32, 51, 57, 57, 54, 32, 72, 122, 44, 32, 50, 48,
            32, 83, 78, 82, 10, 239, 48,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 16, 0, 34, 34, 42, 73, 78, 70, 79, 58, 32, 97, 99, 113, 58, 32, 80, 82, 78, 32, 52,
            32, 102, 111, 117, 110, 100, 32, 64, 32, 45, 55, 52, 57, 50, 32, 72, 122, 44, 32, 50,
            48, 32, 83, 78, 82, 10, 47, 248,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 16, 0, 34, 34, 35, 73, 78, 70, 79, 58, 32, 68, 105, 115, 97, 98, 108, 105, 110,
            103, 32, 99, 104, 97, 110, 110, 101, 108, 32, 49, 32, 40, 80, 82, 78, 32, 49, 53, 41,
            10, 158, 139,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: Disabling channel 1 (PRN 15)
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: Disabling channel 1 (PRN 15)
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
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
fn test_json2sbp_auto_check_sbp_logging_msg_print_dep() {
    {
        let json_input = r#"{"sender": 8738, "msg_type": 16, "text": "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n", "crc": 26484, "length": 43, "preamble": 85, "payload": "SU5GTzogYWNxOiBQUk4gMTUgZm91bmQgQCAtMjQ5NyBIeiwgMjAgU05SCg=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };
    }
    {
        let json_input = r#"{"sender": 8738, "msg_type": 16, "text": "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n", "crc": 11148, "length": 42, "preamble": 85, "payload": "SU5GTzogYWNxOiBQUk4gMzEgZm91bmQgQCA0MjQ1IEh6LCAyMSBTTlIK"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };
    }
    {
        let json_input = r#"{"sender": 8738, "msg_type": 16, "text": "INFO: Disabling channel 0 (PRN 11)\n", "crc": 36631, "length": 35, "preamble": 85, "payload": "SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMCAoUFJOIDExKQo="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: Disabling channel 0 (PRN 11)
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: Disabling channel 0 (PRN 11)
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };
    }
    {
        let json_input = r#"{"sender": 8738, "msg_type": 16, "text": "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n", "crc": 12527, "length": 41, "preamble": 85, "payload": "SU5GTzogYWNxOiBQUk4gMiBmb3VuZCBAIDM5OTYgSHosIDIwIFNOUgo="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };
    }
    {
        let json_input = r#"{"sender": 8738, "msg_type": 16, "text": "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n", "crc": 63535, "length": 42, "preamble": 85, "payload": "SU5GTzogYWNxOiBQUk4gNCBmb3VuZCBAIC03NDkyIEh6LCAyMCBTTlIK"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };
    }
    {
        let json_input = r#"{"sender": 8738, "msg_type": 16, "text": "INFO: Disabling channel 1 (PRN 15)\n", "crc": 35742, "length": 35, "preamble": 85, "payload": "SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMSAoUFJOIDE1KQo="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: Disabling channel 1 (PRN 15)
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: Disabling channel 1 (PRN 15)
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_logging_msg_print_dep`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_logging_msg_print_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 16, 0, 34, 34, 43, 73, 78, 70, 79, 58, 32, 97, 99, 113, 58, 32, 80, 82, 78, 32, 49,
            53, 32, 102, 111, 117, 110, 100, 32, 64, 32, 45, 50, 52, 57, 55, 32, 72, 122, 44, 32,
            50, 48, 32, 83, 78, 82, 10, 116, 103,
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
        let sbp_msg = sbp::messages::Sbp::MsgPrintDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 16, 0, 34, 34, 42, 73, 78, 70, 79, 58, 32, 97, 99, 113, 58, 32, 80, 82, 78, 32, 51,
            49, 32, 102, 111, 117, 110, 100, 32, 64, 32, 52, 50, 52, 53, 32, 72, 122, 44, 32, 50,
            49, 32, 83, 78, 82, 10, 140, 43,
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
        let sbp_msg = sbp::messages::Sbp::MsgPrintDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 16, 0, 34, 34, 35, 73, 78, 70, 79, 58, 32, 68, 105, 115, 97, 98, 108, 105, 110,
            103, 32, 99, 104, 97, 110, 110, 101, 108, 32, 48, 32, 40, 80, 82, 78, 32, 49, 49, 41,
            10, 23, 143,
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
        let sbp_msg = sbp::messages::Sbp::MsgPrintDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: Disabling channel 0 (PRN 11)
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: Disabling channel 0 (PRN 11)
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 16, 0, 34, 34, 41, 73, 78, 70, 79, 58, 32, 97, 99, 113, 58, 32, 80, 82, 78, 32, 50,
            32, 102, 111, 117, 110, 100, 32, 64, 32, 51, 57, 57, 54, 32, 72, 122, 44, 32, 50, 48,
            32, 83, 78, 82, 10, 239, 48,
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
        let sbp_msg = sbp::messages::Sbp::MsgPrintDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 16, 0, 34, 34, 42, 73, 78, 70, 79, 58, 32, 97, 99, 113, 58, 32, 80, 82, 78, 32, 52,
            32, 102, 111, 117, 110, 100, 32, 64, 32, 45, 55, 52, 57, 50, 32, 72, 122, 44, 32, 50,
            48, 32, 83, 78, 82, 10, 47, 248,
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
        let sbp_msg = sbp::messages::Sbp::MsgPrintDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 16, 0, 34, 34, 35, 73, 78, 70, 79, 58, 32, 68, 105, 115, 97, 98, 108, 105, 110,
            103, 32, 99, 104, 97, 110, 110, 101, 108, 32, 49, 32, 40, 80, 82, 78, 32, 49, 53, 41,
            10, 158, 139,
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
        let sbp_msg = sbp::messages::Sbp::MsgPrintDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text.to_string(),
                    "INFO: Disabling channel 1 (PRN 15)
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: Disabling channel 1 (PRN 15)
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
