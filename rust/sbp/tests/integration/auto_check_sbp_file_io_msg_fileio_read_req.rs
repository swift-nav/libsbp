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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadReq.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_file_io_msg_fileio_read_req() {
    {
        let mut payload = Cursor::new(vec![
            85, 168, 0, 195, 4, 28, 34, 156, 130, 40, 98, 178, 190, 23, 53, 47, 112, 97, 116, 104,
            47, 116, 111, 47, 115, 111, 109, 101, 47, 102, 105, 108, 101, 0, 86, 100,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgFileioReadReq(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa8,
                    "Incorrect message type, expected 0xa8, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.chunk_size, 53,
                    "incorrect value for chunk_size, expected 53, is {}",
                    msg.chunk_size
                );
                assert_eq!(
                    msg.filename.as_bytes(),
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 115, 111, 109, 101, 47, 102, 105,
                        108, 101, 0
                    ],
                    "incorrect value for msg.filename, expected string '{:?}', is '{:?}'",
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 115, 111, 109, 101, 47, 102, 105,
                        108, 101, 0
                    ],
                    msg.filename.as_bytes()
                );
                assert_eq!(
                    msg.offset, 398373474,
                    "incorrect value for offset, expected 398373474, is {}",
                    msg.offset
                );
                assert_eq!(
                    msg.sequence, 679648290,
                    "incorrect value for sequence, expected 679648290, is {}",
                    msg.sequence
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFileioReadReq"),
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
fn test_json2sbp_auto_check_sbp_file_io_msg_fileio_read_req() {
    {
        let json_input = r#"{"crc":25686,"length":28,"msg_type":168,"payload":"IpyCKGKyvhc1L3BhdGgvdG8vc29tZS9maWxlAA==","preamble":85,"sender":1219,"sequence":679648290,"offset":398373474,"chunk_size":53,"filename":"/path/to/some/file\u0000"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgFileioReadReq(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa8,
                    "Incorrect message type, expected 0xa8, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.chunk_size, 53,
                    "incorrect value for chunk_size, expected 53, is {}",
                    msg.chunk_size
                );
                assert_eq!(
                    msg.filename.as_bytes(),
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 115, 111, 109, 101, 47, 102, 105,
                        108, 101, 0
                    ],
                    "incorrect value for msg.filename, expected string '{:?}', is '{:?}'",
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 115, 111, 109, 101, 47, 102, 105,
                        108, 101, 0
                    ],
                    msg.filename.as_bytes()
                );
                assert_eq!(
                    msg.offset, 398373474,
                    "incorrect value for offset, expected 398373474, is {}",
                    msg.offset
                );
                assert_eq!(
                    msg.sequence, 679648290,
                    "incorrect value for sequence, expected 679648290, is {}",
                    msg.sequence
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFileioReadReq"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_file_io_msg_fileio_read_req`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_file_io_msg_fileio_read_req() {
    {
        let mut payload = Cursor::new(vec![
            85, 168, 0, 195, 4, 28, 34, 156, 130, 40, 98, 178, 190, 23, 53, 47, 112, 97, 116, 104,
            47, 116, 111, 47, 115, 111, 109, 101, 47, 102, 105, 108, 101, 0, 86, 100,
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
        let sbp_msg = sbp::messages::Sbp::MsgFileioReadReq(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgFileioReadReq(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa8,
                    "Incorrect message type, expected 0xa8, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.chunk_size, 53,
                    "incorrect value for chunk_size, expected 53, is {}",
                    msg.chunk_size
                );
                assert_eq!(
                    msg.filename.as_bytes(),
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 115, 111, 109, 101, 47, 102, 105,
                        108, 101, 0
                    ],
                    "incorrect value for msg.filename, expected string '{:?}', is '{:?}'",
                    &[
                        47, 112, 97, 116, 104, 47, 116, 111, 47, 115, 111, 109, 101, 47, 102, 105,
                        108, 101, 0
                    ],
                    msg.filename.as_bytes()
                );
                assert_eq!(
                    msg.offset, 398373474,
                    "incorrect value for offset, expected 398373474, is {}",
                    msg.offset
                );
                assert_eq!(
                    msg.sequence, 679648290,
                    "incorrect value for sequence, expected 679648290, is {}",
                    msg.sequence
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFileioReadReq"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
