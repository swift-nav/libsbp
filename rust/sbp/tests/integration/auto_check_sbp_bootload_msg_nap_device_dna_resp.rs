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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/bootload/test_MsgNapDeviceDnaResp.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_bootload_msg_nap_device_dna_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 221, 0, 169, 56, 8, 2, 187, 1, 130, 173, 244, 67, 122, 70, 91,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgNapDeviceDnaResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xdd,
                    "Incorrect message type, expected 0xdd, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x38a9,
                    "incorrect sender id, expected 0x38a9, is {sender_id}"
                );
                assert_eq!(
                    msg.dna[0], 2,
                    "incorrect value for dna[0], expected 2, is {}",
                    msg.dna[0]
                );
                assert_eq!(
                    msg.dna[1], 187,
                    "incorrect value for dna[1], expected 187, is {}",
                    msg.dna[1]
                );
                assert_eq!(
                    msg.dna[2], 1,
                    "incorrect value for dna[2], expected 1, is {}",
                    msg.dna[2]
                );
                assert_eq!(
                    msg.dna[3], 130,
                    "incorrect value for dna[3], expected 130, is {}",
                    msg.dna[3]
                );
                assert_eq!(
                    msg.dna[4], 173,
                    "incorrect value for dna[4], expected 173, is {}",
                    msg.dna[4]
                );
                assert_eq!(
                    msg.dna[5], 244,
                    "incorrect value for dna[5], expected 244, is {}",
                    msg.dna[5]
                );
                assert_eq!(
                    msg.dna[6], 67,
                    "incorrect value for dna[6], expected 67, is {}",
                    msg.dna[6]
                );
                assert_eq!(
                    msg.dna[7], 122,
                    "incorrect value for dna[7], expected 122, is {}",
                    msg.dna[7]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgNapDeviceDnaResp"),
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
fn test_json2sbp_auto_check_sbp_bootload_msg_nap_device_dna_resp() {
    {
        let json_input = r#"{"crc":23366,"length":8,"msg_type":221,"payload":"ArsBgq30Q3o=","preamble":85,"sender":14505,"dna":[2,187,1,130,173,244,67,122]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgNapDeviceDnaResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xdd,
                    "Incorrect message type, expected 0xdd, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x38a9,
                    "incorrect sender id, expected 0x38a9, is {sender_id}"
                );
                assert_eq!(
                    msg.dna[0], 2,
                    "incorrect value for dna[0], expected 2, is {}",
                    msg.dna[0]
                );
                assert_eq!(
                    msg.dna[1], 187,
                    "incorrect value for dna[1], expected 187, is {}",
                    msg.dna[1]
                );
                assert_eq!(
                    msg.dna[2], 1,
                    "incorrect value for dna[2], expected 1, is {}",
                    msg.dna[2]
                );
                assert_eq!(
                    msg.dna[3], 130,
                    "incorrect value for dna[3], expected 130, is {}",
                    msg.dna[3]
                );
                assert_eq!(
                    msg.dna[4], 173,
                    "incorrect value for dna[4], expected 173, is {}",
                    msg.dna[4]
                );
                assert_eq!(
                    msg.dna[5], 244,
                    "incorrect value for dna[5], expected 244, is {}",
                    msg.dna[5]
                );
                assert_eq!(
                    msg.dna[6], 67,
                    "incorrect value for dna[6], expected 67, is {}",
                    msg.dna[6]
                );
                assert_eq!(
                    msg.dna[7], 122,
                    "incorrect value for dna[7], expected 122, is {}",
                    msg.dna[7]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgNapDeviceDnaResp"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_bootload_msg_nap_device_dna_resp`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_bootload_msg_nap_device_dna_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 221, 0, 169, 56, 8, 2, 187, 1, 130, 173, 244, 67, 122, 70, 91,
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
        let sbp_msg = sbp::messages::Sbp::MsgNapDeviceDnaResp(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgNapDeviceDnaResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xdd,
                    "Incorrect message type, expected 0xdd, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x38a9,
                    "incorrect sender id, expected 0x38a9, is {sender_id}"
                );
                assert_eq!(
                    msg.dna[0], 2,
                    "incorrect value for dna[0], expected 2, is {}",
                    msg.dna[0]
                );
                assert_eq!(
                    msg.dna[1], 187,
                    "incorrect value for dna[1], expected 187, is {}",
                    msg.dna[1]
                );
                assert_eq!(
                    msg.dna[2], 1,
                    "incorrect value for dna[2], expected 1, is {}",
                    msg.dna[2]
                );
                assert_eq!(
                    msg.dna[3], 130,
                    "incorrect value for dna[3], expected 130, is {}",
                    msg.dna[3]
                );
                assert_eq!(
                    msg.dna[4], 173,
                    "incorrect value for dna[4], expected 173, is {}",
                    msg.dna[4]
                );
                assert_eq!(
                    msg.dna[5], 244,
                    "incorrect value for dna[5], expected 244, is {}",
                    msg.dna[5]
                );
                assert_eq!(
                    msg.dna[6], 67,
                    "incorrect value for dna[6], expected 67, is {}",
                    msg.dna[6]
                );
                assert_eq!(
                    msg.dna[7], 122,
                    "incorrect value for dna[7], expected 122, is {}",
                    msg.dna[7]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgNapDeviceDnaResp"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
