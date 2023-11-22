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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioConfigResp.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_file_io_msg_fileio_config_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 2, 16, 195, 4, 16, 170, 76, 52, 91, 149, 186, 44, 3, 216, 151, 255, 61, 12, 97, 66,
            144, 239, 115,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgFileioConfigResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x1002,
                    "Incorrect message type, expected 0x1002, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.batch_size, 1040160728,
                    "incorrect value for batch_size, expected 1040160728, is {}",
                    msg.batch_size
                );
                assert_eq!(
                    msg.fileio_version, 2420269324,
                    "incorrect value for fileio_version, expected 2420269324, is {}",
                    msg.fileio_version
                );
                assert_eq!(
                    msg.sequence, 1530154154,
                    "incorrect value for sequence, expected 1530154154, is {}",
                    msg.sequence
                );
                assert_eq!(
                    msg.window_size, 53262997,
                    "incorrect value for window_size, expected 53262997, is {}",
                    msg.window_size
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFileioConfigResp"),
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
fn test_json2sbp_auto_check_sbp_file_io_msg_fileio_config_resp() {
    {
        let json_input = r#"{"preamble":85,"msg_type":4098,"sender":1219,"length":16,"payload":"qkw0W5W6LAPYl/89DGFCkA==","crc":29679,"sequence":1530154154,"window_size":53262997,"batch_size":1040160728,"fileio_version":2420269324}"#.as_bytes();

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
            sbp::messages::Sbp::MsgFileioConfigResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x1002,
                    "Incorrect message type, expected 0x1002, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.batch_size, 1040160728,
                    "incorrect value for batch_size, expected 1040160728, is {}",
                    msg.batch_size
                );
                assert_eq!(
                    msg.fileio_version, 2420269324,
                    "incorrect value for fileio_version, expected 2420269324, is {}",
                    msg.fileio_version
                );
                assert_eq!(
                    msg.sequence, 1530154154,
                    "incorrect value for sequence, expected 1530154154, is {}",
                    msg.sequence
                );
                assert_eq!(
                    msg.window_size, 53262997,
                    "incorrect value for window_size, expected 53262997, is {}",
                    msg.window_size
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFileioConfigResp"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_file_io_msg_fileio_config_resp`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_file_io_msg_fileio_config_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 2, 16, 195, 4, 16, 170, 76, 52, 91, 149, 186, 44, 3, 216, 151, 255, 61, 12, 97, 66,
            144, 239, 115,
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
        let sbp_msg = sbp::messages::Sbp::MsgFileioConfigResp(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgFileioConfigResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x1002,
                    "Incorrect message type, expected 0x1002, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.batch_size, 1040160728,
                    "incorrect value for batch_size, expected 1040160728, is {}",
                    msg.batch_size
                );
                assert_eq!(
                    msg.fileio_version, 2420269324,
                    "incorrect value for fileio_version, expected 2420269324, is {}",
                    msg.fileio_version
                );
                assert_eq!(
                    msg.sequence, 1530154154,
                    "incorrect value for sequence, expected 1530154154, is {}",
                    msg.sequence
                );
                assert_eq!(
                    msg.window_size, 53262997,
                    "incorrect value for window_size, expected 53262997, is {}",
                    msg.window_size
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFileioConfigResp"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
