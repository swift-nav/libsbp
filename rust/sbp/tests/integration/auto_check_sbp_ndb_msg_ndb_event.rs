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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ndb/test_MsgNdbEvent.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ndb_msg_ndb_event() {
    {
        let mut payload = Cursor::new(vec![
            85, 0, 4, 164, 174, 18, 254, 188, 70, 185, 69, 0, 0, 0, 249, 73, 205, 115, 238, 74, 98,
            66, 182, 148, 16, 166,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgNdbEvent(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x400,
                    "Incorrect message type, expected 0x400, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xaea4,
                    "incorrect sender id, expected 0xaea4, is {sender_id}"
                );
                assert_eq!(
                    msg.data_source, 115,
                    "incorrect value for data_source, expected 115, is {}",
                    msg.data_source
                );
                assert_eq!(
                    msg.event, 249,
                    "incorrect value for event, expected 249, is {}",
                    msg.event
                );
                assert_eq!(
                    msg.object_sid.code, 74,
                    "incorrect value for object_sid.code, expected 74, is {}",
                    msg.object_sid.code
                );
                assert_eq!(
                    msg.object_sid.sat, 238,
                    "incorrect value for object_sid.sat, expected 238, is {}",
                    msg.object_sid.sat
                );
                assert_eq!(
                    msg.object_type, 73,
                    "incorrect value for object_type, expected 73, is {}",
                    msg.object_type
                );
                assert_eq!(
                    msg.original_sender, 38070,
                    "incorrect value for original_sender, expected 38070, is {}",
                    msg.original_sender
                );
                assert_eq!(
                    msg.recv_time, 299461164286,
                    "incorrect value for recv_time, expected 299461164286, is {}",
                    msg.recv_time
                );
                assert_eq!(
                    msg.result, 205,
                    "incorrect value for result, expected 205, is {}",
                    msg.result
                );
                assert_eq!(
                    msg.src_sid.code, 66,
                    "incorrect value for src_sid.code, expected 66, is {}",
                    msg.src_sid.code
                );
                assert_eq!(
                    msg.src_sid.sat, 98,
                    "incorrect value for src_sid.sat, expected 98, is {}",
                    msg.src_sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgNdbEvent"),
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
fn test_json2sbp_auto_check_sbp_ndb_msg_ndb_event() {
    {
        let json_input = r#"{"preamble":85,"msg_type":1024,"sender":44708,"length":18,"payload":"/rxGuUUAAAD5Sc1z7kpiQraU","crc":42512,"recv_time":299461164286,"event":249,"object_type":73,"result":205,"data_source":115,"object_sid":{"sat":238,"code":74},"src_sid":{"sat":98,"code":66},"original_sender":38070}"#.as_bytes();

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
            sbp::messages::Sbp::MsgNdbEvent(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x400,
                    "Incorrect message type, expected 0x400, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xaea4,
                    "incorrect sender id, expected 0xaea4, is {sender_id}"
                );
                assert_eq!(
                    msg.data_source, 115,
                    "incorrect value for data_source, expected 115, is {}",
                    msg.data_source
                );
                assert_eq!(
                    msg.event, 249,
                    "incorrect value for event, expected 249, is {}",
                    msg.event
                );
                assert_eq!(
                    msg.object_sid.code, 74,
                    "incorrect value for object_sid.code, expected 74, is {}",
                    msg.object_sid.code
                );
                assert_eq!(
                    msg.object_sid.sat, 238,
                    "incorrect value for object_sid.sat, expected 238, is {}",
                    msg.object_sid.sat
                );
                assert_eq!(
                    msg.object_type, 73,
                    "incorrect value for object_type, expected 73, is {}",
                    msg.object_type
                );
                assert_eq!(
                    msg.original_sender, 38070,
                    "incorrect value for original_sender, expected 38070, is {}",
                    msg.original_sender
                );
                assert_eq!(
                    msg.recv_time, 299461164286,
                    "incorrect value for recv_time, expected 299461164286, is {}",
                    msg.recv_time
                );
                assert_eq!(
                    msg.result, 205,
                    "incorrect value for result, expected 205, is {}",
                    msg.result
                );
                assert_eq!(
                    msg.src_sid.code, 66,
                    "incorrect value for src_sid.code, expected 66, is {}",
                    msg.src_sid.code
                );
                assert_eq!(
                    msg.src_sid.sat, 98,
                    "incorrect value for src_sid.sat, expected 98, is {}",
                    msg.src_sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgNdbEvent"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ndb_msg_ndb_event`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ndb_msg_ndb_event() {
    {
        let mut payload = Cursor::new(vec![
            85, 0, 4, 164, 174, 18, 254, 188, 70, 185, 69, 0, 0, 0, 249, 73, 205, 115, 238, 74, 98,
            66, 182, 148, 16, 166,
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
        let sbp_msg = sbp::messages::Sbp::MsgNdbEvent(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgNdbEvent(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x400,
                    "Incorrect message type, expected 0x400, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xaea4,
                    "incorrect sender id, expected 0xaea4, is {sender_id}"
                );
                assert_eq!(
                    msg.data_source, 115,
                    "incorrect value for data_source, expected 115, is {}",
                    msg.data_source
                );
                assert_eq!(
                    msg.event, 249,
                    "incorrect value for event, expected 249, is {}",
                    msg.event
                );
                assert_eq!(
                    msg.object_sid.code, 74,
                    "incorrect value for object_sid.code, expected 74, is {}",
                    msg.object_sid.code
                );
                assert_eq!(
                    msg.object_sid.sat, 238,
                    "incorrect value for object_sid.sat, expected 238, is {}",
                    msg.object_sid.sat
                );
                assert_eq!(
                    msg.object_type, 73,
                    "incorrect value for object_type, expected 73, is {}",
                    msg.object_type
                );
                assert_eq!(
                    msg.original_sender, 38070,
                    "incorrect value for original_sender, expected 38070, is {}",
                    msg.original_sender
                );
                assert_eq!(
                    msg.recv_time, 299461164286,
                    "incorrect value for recv_time, expected 299461164286, is {}",
                    msg.recv_time
                );
                assert_eq!(
                    msg.result, 205,
                    "incorrect value for result, expected 205, is {}",
                    msg.result
                );
                assert_eq!(
                    msg.src_sid.code, 66,
                    "incorrect value for src_sid.code, expected 66, is {}",
                    msg.src_sid.code
                );
                assert_eq!(
                    msg.src_sid.sat, 98,
                    "incorrect value for src_sid.sat, expected 98, is {}",
                    msg.src_sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgNdbEvent"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
