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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResult.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_acquisition_msg_acq_result() {
    {
        let mut payload = Cursor::new(vec![
            85, 47, 0, 195, 4, 14, 0, 0, 104, 65, 102, 102, 144, 66, 205, 196, 0, 70, 8, 0, 207,
            189,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResult(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2f,
                    "Incorrect message type, expected 0x2f, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert!(
                    msg.cf.almost_eq(8.24120019531250000e+03),
                    "incorrect value for cf, expected 8.24120019531250000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(1.45000000000000000e+01),
                    "incorrect value for cn0, expected 1.45000000000000000e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(7.21999969482421875e+01),
                    "incorrect value for cp, expected 7.21999969482421875e+01, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 8,
                    "incorrect value for sid.sat, expected 8, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResult"),
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
fn test_json2sbp_auto_check_sbp_acquisition_msg_acq_result() {
    {
        let json_input = r#"{"preamble":85,"msg_type":47,"sender":1219,"length":14,"payload":"AABoQWZmkELNxABGCAA=","crc":48591,"cn0":14.5,"cp":72.19999694824219,"cf":8241.2001953125,"sid":{"sat":8,"code":0}}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqResult(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2f,
                    "Incorrect message type, expected 0x2f, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert!(
                    msg.cf.almost_eq(8.24120019531250000e+03),
                    "incorrect value for cf, expected 8.24120019531250000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(1.45000000000000000e+01),
                    "incorrect value for cn0, expected 1.45000000000000000e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(7.21999969482421875e+01),
                    "incorrect value for cp, expected 7.21999969482421875e+01, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 8,
                    "incorrect value for sid.sat, expected 8, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResult"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_acquisition_msg_acq_result`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_acquisition_msg_acq_result() {
    {
        let mut payload = Cursor::new(vec![
            85, 47, 0, 195, 4, 14, 0, 0, 104, 65, 102, 102, 144, 66, 205, 196, 0, 70, 8, 0, 207,
            189,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqResult(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResult(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2f,
                    "Incorrect message type, expected 0x2f, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert!(
                    msg.cf.almost_eq(8.24120019531250000e+03),
                    "incorrect value for cf, expected 8.24120019531250000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(1.45000000000000000e+01),
                    "incorrect value for cn0, expected 1.45000000000000000e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(7.21999969482421875e+01),
                    "incorrect value for cp, expected 7.21999969482421875e+01, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 8,
                    "incorrect value for sid.sat, expected 8, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResult"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
