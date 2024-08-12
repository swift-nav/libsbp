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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadByIndexResp.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_settings_msg_settings_read_by_index_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 78, 0, 0, 116, 101, 108, 101, 109, 101, 116, 114, 121, 95, 114,
            97, 100, 105, 111, 0, 99, 111, 110, 102, 105, 103, 117, 114, 97, 116, 105, 111, 110,
            95, 115, 116, 114, 105, 110, 103, 0, 65, 84, 38, 70, 44, 65, 84, 83, 49, 61, 49, 49,
            53, 44, 65, 84, 83, 50, 61, 49, 50, 56, 44, 65, 84, 83, 53, 61, 48, 44, 65, 84, 38, 87,
            44, 65, 84, 90, 0, 248, 233,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 0,
                    "incorrect value for index, expected 0, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        116, 101, 108, 101, 109, 101, 116, 114, 121, 95, 114, 97, 100, 105, 111, 0,
                        99, 111, 110, 102, 105, 103, 117, 114, 97, 116, 105, 111, 110, 95, 115,
                        116, 114, 105, 110, 103, 0, 65, 84, 38, 70, 44, 65, 84, 83, 49, 61, 49, 49,
                        53, 44, 65, 84, 83, 50, 61, 49, 50, 56, 44, 65, 84, 83, 53, 61, 48, 44, 65,
                        84, 38, 87, 44, 65, 84, 90, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        116, 101, 108, 101, 109, 101, 116, 114, 121, 95, 114, 97, 100, 105, 111, 0,
                        99, 111, 110, 102, 105, 103, 117, 114, 97, 116, 105, 111, 110, 95, 115,
                        116, 114, 105, 110, 103, 0, 65, 84, 38, 70, 44, 65, 84, 83, 49, 61, 49, 49,
                        53, 44, 65, 84, 83, 50, 61, 49, 50, 56, 44, 65, 84, 83, 53, 61, 48, 44, 65,
                        84, 38, 87, 44, 65, 84, 90, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 35, 1, 0, 117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 109, 111,
            100, 101, 0, 83, 66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0,
            167, 243,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 1,
                    "incorrect value for index, expected 1, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 109, 111, 100, 101, 0, 83,
                        66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 109, 111, 100, 101, 0, 83,
                        66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 35, 2, 0, 117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 115, 98,
            112, 95, 109, 101, 115, 115, 97, 103, 101, 95, 109, 97, 115, 107, 0, 54, 53, 53, 51,
            53, 0, 4, 56,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 2,
                    "incorrect value for index, expected 2, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 115, 98, 112, 95, 109, 101,
                        115, 115, 97, 103, 101, 95, 109, 97, 115, 107, 0, 54, 53, 53, 51, 53, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 115, 98, 112, 95, 109, 101,
                        115, 115, 97, 103, 101, 95, 109, 97, 115, 107, 0, 54, 53, 53, 51, 53, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 29, 3, 0, 117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 98, 97,
            117, 100, 114, 97, 116, 101, 0, 49, 48, 48, 48, 48, 48, 48, 0, 242, 146,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 3,
                    "incorrect value for index, expected 3, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 98, 97, 117, 100, 114, 97,
                        116, 101, 0, 49, 48, 48, 48, 48, 48, 48, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 98, 97, 117, 100, 114, 97,
                        116, 101, 0, 49, 48, 48, 48, 48, 48, 48, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 36, 4, 0, 117, 97, 114, 116, 95, 117, 97, 114, 116, 97, 0, 109,
            111, 100, 101, 0, 83, 66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69,
            65, 0, 22, 4,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 4,
                    "incorrect value for index, expected 4, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        117, 97, 114, 116, 95, 117, 97, 114, 116, 97, 0, 109, 111, 100, 101, 0, 83,
                        66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        117, 97, 114, 116, 95, 117, 97, 114, 116, 97, 0, 109, 111, 100, 101, 0, 83,
                        66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
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
fn test_json2sbp_auto_check_sbp_settings_msg_settings_read_by_index_resp() {
    {
        let json_input = r#"{"index": 0, "sender": 55286, "msg_type": 167, "crc": 59896, "length": 78, "setting": "telemetry_radio\u0000configuration_string\u0000AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ\u0000", "preamble": 85, "payload": "AAB0ZWxlbWV0cnlfcmFkaW8AY29uZmlndXJhdGlvbl9zdHJpbmcAQVQmRixBVFMxPTExNSxBVFMyPTEyOCxBVFM1PTAsQVQmVyxBVFoA"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 0,
                    "incorrect value for index, expected 0, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        116, 101, 108, 101, 109, 101, 116, 114, 121, 95, 114, 97, 100, 105, 111, 0,
                        99, 111, 110, 102, 105, 103, 117, 114, 97, 116, 105, 111, 110, 95, 115,
                        116, 114, 105, 110, 103, 0, 65, 84, 38, 70, 44, 65, 84, 83, 49, 61, 49, 49,
                        53, 44, 65, 84, 83, 50, 61, 49, 50, 56, 44, 65, 84, 83, 53, 61, 48, 44, 65,
                        84, 38, 87, 44, 65, 84, 90, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        116, 101, 108, 101, 109, 101, 116, 114, 121, 95, 114, 97, 100, 105, 111, 0,
                        99, 111, 110, 102, 105, 103, 117, 114, 97, 116, 105, 111, 110, 95, 115,
                        116, 114, 105, 110, 103, 0, 65, 84, 38, 70, 44, 65, 84, 83, 49, 61, 49, 49,
                        53, 44, 65, 84, 83, 50, 61, 49, 50, 56, 44, 65, 84, 83, 53, 61, 48, 44, 65,
                        84, 38, 87, 44, 65, 84, 90, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
    }
    {
        let json_input = r#"{"index": 1, "sender": 55286, "msg_type": 167, "crc": 62375, "length": 35, "setting": "uart_ftdi\u0000mode\u0000SBP\u0000enum:SBP,NMEA\u0000", "preamble": 85, "payload": "AQB1YXJ0X2Z0ZGkAbW9kZQBTQlAAZW51bTpTQlAsTk1FQQA="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 1,
                    "incorrect value for index, expected 1, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 109, 111, 100, 101, 0, 83,
                        66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 109, 111, 100, 101, 0, 83,
                        66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
    }
    {
        let json_input = r#"{"index": 2, "sender": 55286, "msg_type": 167, "crc": 14340, "length": 35, "setting": "uart_ftdi\u0000sbp_message_mask\u000065535\u0000", "preamble": 85, "payload": "AgB1YXJ0X2Z0ZGkAc2JwX21lc3NhZ2VfbWFzawA2NTUzNQA="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 2,
                    "incorrect value for index, expected 2, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 115, 98, 112, 95, 109, 101,
                        115, 115, 97, 103, 101, 95, 109, 97, 115, 107, 0, 54, 53, 53, 51, 53, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 115, 98, 112, 95, 109, 101,
                        115, 115, 97, 103, 101, 95, 109, 97, 115, 107, 0, 54, 53, 53, 51, 53, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
    }
    {
        let json_input = r#"{"index": 3, "sender": 55286, "msg_type": 167, "crc": 37618, "length": 29, "setting": "uart_ftdi\u0000baudrate\u00001000000\u0000", "preamble": 85, "payload": "AwB1YXJ0X2Z0ZGkAYmF1ZHJhdGUAMTAwMDAwMAA="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 3,
                    "incorrect value for index, expected 3, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 98, 97, 117, 100, 114, 97,
                        116, 101, 0, 49, 48, 48, 48, 48, 48, 48, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 98, 97, 117, 100, 114, 97,
                        116, 101, 0, 49, 48, 48, 48, 48, 48, 48, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
    }
    {
        let json_input = r#"{"index": 4, "sender": 55286, "msg_type": 167, "crc": 1046, "length": 36, "setting": "uart_uarta\u0000mode\u0000SBP\u0000enum:SBP,NMEA\u0000", "preamble": 85, "payload": "BAB1YXJ0X3VhcnRhAG1vZGUAU0JQAGVudW06U0JQLE5NRUEA"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 4,
                    "incorrect value for index, expected 4, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        117, 97, 114, 116, 95, 117, 97, 114, 116, 97, 0, 109, 111, 100, 101, 0, 83,
                        66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        117, 97, 114, 116, 95, 117, 97, 114, 116, 97, 0, 109, 111, 100, 101, 0, 83,
                        66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_settings_msg_settings_read_by_index_resp`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_settings_msg_settings_read_by_index_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 78, 0, 0, 116, 101, 108, 101, 109, 101, 116, 114, 121, 95, 114,
            97, 100, 105, 111, 0, 99, 111, 110, 102, 105, 103, 117, 114, 97, 116, 105, 111, 110,
            95, 115, 116, 114, 105, 110, 103, 0, 65, 84, 38, 70, 44, 65, 84, 83, 49, 61, 49, 49,
            53, 44, 65, 84, 83, 50, 61, 49, 50, 56, 44, 65, 84, 83, 53, 61, 48, 44, 65, 84, 38, 87,
            44, 65, 84, 90, 0, 248, 233,
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
        let sbp_msg = sbp::messages::Sbp::MsgSettingsReadByIndexResp(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 0,
                    "incorrect value for index, expected 0, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        116, 101, 108, 101, 109, 101, 116, 114, 121, 95, 114, 97, 100, 105, 111, 0,
                        99, 111, 110, 102, 105, 103, 117, 114, 97, 116, 105, 111, 110, 95, 115,
                        116, 114, 105, 110, 103, 0, 65, 84, 38, 70, 44, 65, 84, 83, 49, 61, 49, 49,
                        53, 44, 65, 84, 83, 50, 61, 49, 50, 56, 44, 65, 84, 83, 53, 61, 48, 44, 65,
                        84, 38, 87, 44, 65, 84, 90, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        116, 101, 108, 101, 109, 101, 116, 114, 121, 95, 114, 97, 100, 105, 111, 0,
                        99, 111, 110, 102, 105, 103, 117, 114, 97, 116, 105, 111, 110, 95, 115,
                        116, 114, 105, 110, 103, 0, 65, 84, 38, 70, 44, 65, 84, 83, 49, 61, 49, 49,
                        53, 44, 65, 84, 83, 50, 61, 49, 50, 56, 44, 65, 84, 83, 53, 61, 48, 44, 65,
                        84, 38, 87, 44, 65, 84, 90, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 35, 1, 0, 117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 109, 111,
            100, 101, 0, 83, 66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0,
            167, 243,
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
        let sbp_msg = sbp::messages::Sbp::MsgSettingsReadByIndexResp(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 1,
                    "incorrect value for index, expected 1, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 109, 111, 100, 101, 0, 83,
                        66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 109, 111, 100, 101, 0, 83,
                        66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 35, 2, 0, 117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 115, 98,
            112, 95, 109, 101, 115, 115, 97, 103, 101, 95, 109, 97, 115, 107, 0, 54, 53, 53, 51,
            53, 0, 4, 56,
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
        let sbp_msg = sbp::messages::Sbp::MsgSettingsReadByIndexResp(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 2,
                    "incorrect value for index, expected 2, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 115, 98, 112, 95, 109, 101,
                        115, 115, 97, 103, 101, 95, 109, 97, 115, 107, 0, 54, 53, 53, 51, 53, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 115, 98, 112, 95, 109, 101,
                        115, 115, 97, 103, 101, 95, 109, 97, 115, 107, 0, 54, 53, 53, 51, 53, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 29, 3, 0, 117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 98, 97,
            117, 100, 114, 97, 116, 101, 0, 49, 48, 48, 48, 48, 48, 48, 0, 242, 146,
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
        let sbp_msg = sbp::messages::Sbp::MsgSettingsReadByIndexResp(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 3,
                    "incorrect value for index, expected 3, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 98, 97, 117, 100, 114, 97,
                        116, 101, 0, 49, 48, 48, 48, 48, 48, 48, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        117, 97, 114, 116, 95, 102, 116, 100, 105, 0, 98, 97, 117, 100, 114, 97,
                        116, 101, 0, 49, 48, 48, 48, 48, 48, 48, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 167, 0, 246, 215, 36, 4, 0, 117, 97, 114, 116, 95, 117, 97, 114, 116, 97, 0, 109,
            111, 100, 101, 0, 83, 66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69,
            65, 0, 22, 4,
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
        let sbp_msg = sbp::messages::Sbp::MsgSettingsReadByIndexResp(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa7,
                    "Incorrect message type, expected 0xa7, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert_eq!(
                    msg.index, 4,
                    "incorrect value for index, expected 4, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.setting.as_bytes(),
                    &[
                        117, 97, 114, 116, 95, 117, 97, 114, 116, 97, 0, 109, 111, 100, 101, 0, 83,
                        66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0
                    ],
                    "incorrect value for msg.setting, expected string '{:?}', is '{:?}'",
                    &[
                        117, 97, 114, 116, 95, 117, 97, 114, 116, 97, 0, 109, 111, 100, 101, 0, 83,
                        66, 80, 0, 101, 110, 117, 109, 58, 83, 66, 80, 44, 78, 77, 69, 65, 0
                    ],
                    msg.setting.as_bytes()
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexResp"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
