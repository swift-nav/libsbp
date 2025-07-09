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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgMaskSatellite.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_piksi_msg_mask_satellite() {
    {
        let mut payload = Cursor::new(vec![85, 43, 0, 173, 151, 3, 183, 87, 57, 19, 147]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgMaskSatellite(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2b,
                    "Incorrect message type, expected 0x2b, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x97ad,
                    "incorrect sender id, expected 0x97ad, is {sender_id}"
                );
                assert_eq!(
                    msg.mask, 183,
                    "incorrect value for mask, expected 183, is {}",
                    msg.mask
                );
                assert_eq!(
                    msg.sid.code, 57,
                    "incorrect value for sid.code, expected 57, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 87,
                    "incorrect value for sid.sat, expected 87, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgMaskSatellite"),
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
fn test_json2sbp_auto_check_sbp_piksi_msg_mask_satellite() {
    {
        let json_input = r#"{"crc":37651,"length":3,"msg_type":43,"payload":"t1c5","preamble":85,"sender":38829,"mask":183,"sid":{"sat":87,"code":57}}"#.as_bytes();

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
            sbp::messages::Sbp::MsgMaskSatellite(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2b,
                    "Incorrect message type, expected 0x2b, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x97ad,
                    "incorrect sender id, expected 0x97ad, is {sender_id}"
                );
                assert_eq!(
                    msg.mask, 183,
                    "incorrect value for mask, expected 183, is {}",
                    msg.mask
                );
                assert_eq!(
                    msg.sid.code, 57,
                    "incorrect value for sid.code, expected 57, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 87,
                    "incorrect value for sid.sat, expected 87, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgMaskSatellite"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_piksi_msg_mask_satellite`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_piksi_msg_mask_satellite() {
    {
        let mut payload = Cursor::new(vec![85, 43, 0, 173, 151, 3, 183, 87, 57, 19, 147]);

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
        let sbp_msg = sbp::messages::Sbp::MsgMaskSatellite(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgMaskSatellite(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2b,
                    "Incorrect message type, expected 0x2b, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x97ad,
                    "incorrect sender id, expected 0x97ad, is {sender_id}"
                );
                assert_eq!(
                    msg.mask, 183,
                    "incorrect value for mask, expected 183, is {}",
                    msg.mask
                );
                assert_eq!(
                    msg.sid.code, 57,
                    "incorrect value for sid.code, expected 57, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 87,
                    "incorrect value for sid.sat, expected 87, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgMaskSatellite"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
