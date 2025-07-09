//
// Copyright (C) 2019-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsWriteResp.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_settings_msg_settings_write_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 175, 0, 91, 55, 67, 152, 115, 101, 99, 116, 105, 111, 110, 45, 110, 97, 109, 101,
            0, 115, 101, 116, 116, 105, 110, 103, 45, 110, 97, 109, 101, 0, 115, 101, 116, 116,
            105, 110, 103, 45, 118, 97, 108, 117, 101, 0, 101, 110, 117, 109, 59, 118, 97, 108,
            117, 101, 49, 44, 118, 97, 108, 117, 101, 50, 44, 118, 97, 108, 117, 101, 51, 0, 54, 0,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsWriteResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xaf,
                    "Incorrect message type, expected 0xaf, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x375b,
                    "incorrect sender id, expected 0x375b, is {sender_id}"
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        115, 101, 99, 116, 105, 111, 110, 45, 110, 97, 109, 101, 0, 115, 101, 116,
                        116, 105, 110, 103, 45, 110, 97, 109, 101, 0, 115, 101, 116, 116, 105, 110,
                        103, 45, 118, 97, 108, 117, 101, 0, 101, 110, 117, 109, 59, 118, 97, 108,
                        117, 101, 49, 44, 118, 97, 108, 117, 101, 50, 44, 118, 97, 108, 117, 101,
                        51, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        115, 101, 99, 116, 105, 111, 110, 45, 110, 97, 109, 101, 0, 115, 101, 116,
                        116, 105, 110, 103, 45, 110, 97, 109, 101, 0, 115, 101, 116, 116, 105, 110,
                        103, 45, 118, 97, 108, 117, 101, 0, 101, 110, 117, 109, 59, 118, 97, 108,
                        117, 101, 49, 44, 118, 97, 108, 117, 101, 50, 44, 118, 97, 108, 117, 101,
                        51, 0
                    ],
                    msg.setting.as_bytes()
                );
                assert_eq!(
                    msg.status, 152,
                    "incorrect value for status, expected 152, is {}",
                    msg.status
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsWriteResp"),
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
fn test_json2sbp_auto_check_sbp_settings_msg_settings_write_resp() {
    {
        let json_input = r#"{"crc":54,"length":67,"msg_type":175,"payload":"mHNlY3Rpb24tbmFtZQBzZXR0aW5nLW5hbWUAc2V0dGluZy12YWx1ZQBlbnVtO3ZhbHVlMSx2YWx1ZTIsdmFsdWUzAA==","preamble":85,"sender":14171,"status":152,"setting":"section-name\u0000setting-name\u0000setting-value\u0000enum;value1,value2,value3\u0000"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSettingsWriteResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xaf,
                    "Incorrect message type, expected 0xaf, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x375b,
                    "incorrect sender id, expected 0x375b, is {sender_id}"
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        115, 101, 99, 116, 105, 111, 110, 45, 110, 97, 109, 101, 0, 115, 101, 116,
                        116, 105, 110, 103, 45, 110, 97, 109, 101, 0, 115, 101, 116, 116, 105, 110,
                        103, 45, 118, 97, 108, 117, 101, 0, 101, 110, 117, 109, 59, 118, 97, 108,
                        117, 101, 49, 44, 118, 97, 108, 117, 101, 50, 44, 118, 97, 108, 117, 101,
                        51, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        115, 101, 99, 116, 105, 111, 110, 45, 110, 97, 109, 101, 0, 115, 101, 116,
                        116, 105, 110, 103, 45, 110, 97, 109, 101, 0, 115, 101, 116, 116, 105, 110,
                        103, 45, 118, 97, 108, 117, 101, 0, 101, 110, 117, 109, 59, 118, 97, 108,
                        117, 101, 49, 44, 118, 97, 108, 117, 101, 50, 44, 118, 97, 108, 117, 101,
                        51, 0
                    ],
                    msg.setting.as_bytes()
                );
                assert_eq!(
                    msg.status, 152,
                    "incorrect value for status, expected 152, is {}",
                    msg.status
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsWriteResp"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_settings_msg_settings_write_resp`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_settings_msg_settings_write_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 175, 0, 91, 55, 67, 152, 115, 101, 99, 116, 105, 111, 110, 45, 110, 97, 109, 101,
            0, 115, 101, 116, 116, 105, 110, 103, 45, 110, 97, 109, 101, 0, 115, 101, 116, 116,
            105, 110, 103, 45, 118, 97, 108, 117, 101, 0, 101, 110, 117, 109, 59, 118, 97, 108,
            117, 101, 49, 44, 118, 97, 108, 117, 101, 50, 44, 118, 97, 108, 117, 101, 51, 0, 54, 0,
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
        let sbp_msg = sbp::messages::Sbp::MsgSettingsWriteResp(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsWriteResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xaf,
                    "Incorrect message type, expected 0xaf, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x375b,
                    "incorrect sender id, expected 0x375b, is {sender_id}"
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        115, 101, 99, 116, 105, 111, 110, 45, 110, 97, 109, 101, 0, 115, 101, 116,
                        116, 105, 110, 103, 45, 110, 97, 109, 101, 0, 115, 101, 116, 116, 105, 110,
                        103, 45, 118, 97, 108, 117, 101, 0, 101, 110, 117, 109, 59, 118, 97, 108,
                        117, 101, 49, 44, 118, 97, 108, 117, 101, 50, 44, 118, 97, 108, 117, 101,
                        51, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        115, 101, 99, 116, 105, 111, 110, 45, 110, 97, 109, 101, 0, 115, 101, 116,
                        116, 105, 110, 103, 45, 110, 97, 109, 101, 0, 115, 101, 116, 116, 105, 110,
                        103, 45, 118, 97, 108, 117, 101, 0, 101, 110, 117, 109, 59, 118, 97, 108,
                        117, 101, 49, 44, 118, 97, 108, 117, 101, 50, 44, 118, 97, 108, 117, 101,
                        51, 0
                    ],
                    msg.setting.as_bytes()
                );
                assert_eq!(
                    msg.status, 152,
                    "incorrect value for status, expected 152, is {}",
                    msg.status
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsWriteResp"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
