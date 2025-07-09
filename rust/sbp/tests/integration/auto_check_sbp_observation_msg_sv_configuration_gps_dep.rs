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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgSvConfigurationGpsDep.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_sv_configuration_gps_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 145, 0, 123, 0, 10, 0, 0, 0, 0, 0, 0, 66, 188, 101, 167, 18, 42,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSvConfigurationGpsDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x91,
                    "Incorrect message type, expected 0x91, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert_eq!(
                    msg.l2c_mask, 2808462402,
                    "incorrect value for l2c_mask, expected 2808462402, is {}",
                    msg.l2c_mask
                );
                assert_eq!(
                    msg.t_nmct.tow, 0,
                    "incorrect value for t_nmct.tow, expected 0, is {}",
                    msg.t_nmct.tow
                );
                assert_eq!(
                    msg.t_nmct.wn, 0,
                    "incorrect value for t_nmct.wn, expected 0, is {}",
                    msg.t_nmct.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSvConfigurationGPSDep"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_sv_configuration_gps_dep() {
    {
        let json_input = r#"{"crc":10770,"length":10,"msg_type":145,"payload":"AAAAAAAAQrxlpw==","preamble":85,"sender":123,"t_nmct":{"tow":0,"wn":0},"l2c_mask":2808462402}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSvConfigurationGpsDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x91,
                    "Incorrect message type, expected 0x91, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert_eq!(
                    msg.l2c_mask, 2808462402,
                    "incorrect value for l2c_mask, expected 2808462402, is {}",
                    msg.l2c_mask
                );
                assert_eq!(
                    msg.t_nmct.tow, 0,
                    "incorrect value for t_nmct.tow, expected 0, is {}",
                    msg.t_nmct.tow
                );
                assert_eq!(
                    msg.t_nmct.wn, 0,
                    "incorrect value for t_nmct.wn, expected 0, is {}",
                    msg.t_nmct.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSvConfigurationGPSDep"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_sv_configuration_gps_dep`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_sv_configuration_gps_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 145, 0, 123, 0, 10, 0, 0, 0, 0, 0, 0, 66, 188, 101, 167, 18, 42,
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
        let sbp_msg = sbp::messages::Sbp::MsgSvConfigurationGpsDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSvConfigurationGpsDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x91,
                    "Incorrect message type, expected 0x91, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert_eq!(
                    msg.l2c_mask, 2808462402,
                    "incorrect value for l2c_mask, expected 2808462402, is {}",
                    msg.l2c_mask
                );
                assert_eq!(
                    msg.t_nmct.tow, 0,
                    "incorrect value for t_nmct.tow, expected 0, is {}",
                    msg.t_nmct.tow
                );
                assert_eq!(
                    msg.t_nmct.wn, 0,
                    "incorrect value for t_nmct.wn, expected 0, is {}",
                    msg.t_nmct.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSvConfigurationGPSDep"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
