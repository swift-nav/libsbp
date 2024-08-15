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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgAesCmacSignature.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_signing_msg_aes_cmac_signature() {
    {
        let mut payload = Cursor::new(vec![
            85, 16, 12, 66, 0, 26, 1, 2, 1, 2, 3, 4, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
            14, 15, 0, 11, 22, 33, 192, 21,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAesCmacSignature(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC10,
                    "Incorrect message type, expected 0xC10, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {sender_id}"
                );
                assert_eq!(
                    msg.certificate_id[0], 1,
                    "incorrect value for certificate_id[0], expected 1, is {}",
                    msg.certificate_id[0]
                );
                assert_eq!(
                    msg.certificate_id[1], 2,
                    "incorrect value for certificate_id[1], expected 2, is {}",
                    msg.certificate_id[1]
                );
                assert_eq!(
                    msg.certificate_id[2], 3,
                    "incorrect value for certificate_id[2], expected 3, is {}",
                    msg.certificate_id[2]
                );
                assert_eq!(
                    msg.certificate_id[3], 4,
                    "incorrect value for certificate_id[3], expected 4, is {}",
                    msg.certificate_id[3]
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.on_demand_counter, 2,
                    "incorrect value for on_demand_counter, expected 2, is {}",
                    msg.on_demand_counter
                );
                assert_eq!(
                    msg.signature[0], 0,
                    "incorrect value for signature[0], expected 0, is {}",
                    msg.signature[0]
                );
                assert_eq!(
                    msg.signature[1], 1,
                    "incorrect value for signature[1], expected 1, is {}",
                    msg.signature[1]
                );
                assert_eq!(
                    msg.signature[2], 2,
                    "incorrect value for signature[2], expected 2, is {}",
                    msg.signature[2]
                );
                assert_eq!(
                    msg.signature[3], 3,
                    "incorrect value for signature[3], expected 3, is {}",
                    msg.signature[3]
                );
                assert_eq!(
                    msg.signature[4], 4,
                    "incorrect value for signature[4], expected 4, is {}",
                    msg.signature[4]
                );
                assert_eq!(
                    msg.signature[5], 5,
                    "incorrect value for signature[5], expected 5, is {}",
                    msg.signature[5]
                );
                assert_eq!(
                    msg.signature[6], 6,
                    "incorrect value for signature[6], expected 6, is {}",
                    msg.signature[6]
                );
                assert_eq!(
                    msg.signature[7], 7,
                    "incorrect value for signature[7], expected 7, is {}",
                    msg.signature[7]
                );
                assert_eq!(
                    msg.signature[8], 8,
                    "incorrect value for signature[8], expected 8, is {}",
                    msg.signature[8]
                );
                assert_eq!(
                    msg.signature[9], 9,
                    "incorrect value for signature[9], expected 9, is {}",
                    msg.signature[9]
                );
                assert_eq!(
                    msg.signature[10], 10,
                    "incorrect value for signature[10], expected 10, is {}",
                    msg.signature[10]
                );
                assert_eq!(
                    msg.signature[11], 11,
                    "incorrect value for signature[11], expected 11, is {}",
                    msg.signature[11]
                );
                assert_eq!(
                    msg.signature[12], 12,
                    "incorrect value for signature[12], expected 12, is {}",
                    msg.signature[12]
                );
                assert_eq!(
                    msg.signature[13], 13,
                    "incorrect value for signature[13], expected 13, is {}",
                    msg.signature[13]
                );
                assert_eq!(
                    msg.signature[14], 14,
                    "incorrect value for signature[14], expected 14, is {}",
                    msg.signature[14]
                );
                assert_eq!(
                    msg.signature[15], 15,
                    "incorrect value for signature[15], expected 15, is {}",
                    msg.signature[15]
                );
                assert_eq!(
                    msg.signed_messages[0], 11,
                    "incorrect value for signed_messages[0], expected 11, is {}",
                    msg.signed_messages[0]
                );
                assert_eq!(
                    msg.signed_messages[1], 22,
                    "incorrect value for signed_messages[1], expected 22, is {}",
                    msg.signed_messages[1]
                );
                assert_eq!(
                    msg.signed_messages[2], 33,
                    "incorrect value for signed_messages[2], expected 33, is {}",
                    msg.signed_messages[2]
                );
                assert_eq!(
                    msg.stream_counter, 1,
                    "incorrect value for stream_counter, expected 1, is {}",
                    msg.stream_counter
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAesCmacSignature"),
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
fn test_json2sbp_auto_check_sbp_signing_msg_aes_cmac_signature() {
    {
        let json_input = r#"{"crc":5568,"length":26,"msg_type":3088,"payload":"AQIBAgMEAAECAwQFBgcICQoLDA0ODwALFiE=","preamble":85,"sender":66,"stream_counter":1,"on_demand_counter":2,"certificate_id":[1,2,3,4],"signature":[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15],"flags":0,"signed_messages":[11,22,33]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAesCmacSignature(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC10,
                    "Incorrect message type, expected 0xC10, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {sender_id}"
                );
                assert_eq!(
                    msg.certificate_id[0], 1,
                    "incorrect value for certificate_id[0], expected 1, is {}",
                    msg.certificate_id[0]
                );
                assert_eq!(
                    msg.certificate_id[1], 2,
                    "incorrect value for certificate_id[1], expected 2, is {}",
                    msg.certificate_id[1]
                );
                assert_eq!(
                    msg.certificate_id[2], 3,
                    "incorrect value for certificate_id[2], expected 3, is {}",
                    msg.certificate_id[2]
                );
                assert_eq!(
                    msg.certificate_id[3], 4,
                    "incorrect value for certificate_id[3], expected 4, is {}",
                    msg.certificate_id[3]
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.on_demand_counter, 2,
                    "incorrect value for on_demand_counter, expected 2, is {}",
                    msg.on_demand_counter
                );
                assert_eq!(
                    msg.signature[0], 0,
                    "incorrect value for signature[0], expected 0, is {}",
                    msg.signature[0]
                );
                assert_eq!(
                    msg.signature[1], 1,
                    "incorrect value for signature[1], expected 1, is {}",
                    msg.signature[1]
                );
                assert_eq!(
                    msg.signature[2], 2,
                    "incorrect value for signature[2], expected 2, is {}",
                    msg.signature[2]
                );
                assert_eq!(
                    msg.signature[3], 3,
                    "incorrect value for signature[3], expected 3, is {}",
                    msg.signature[3]
                );
                assert_eq!(
                    msg.signature[4], 4,
                    "incorrect value for signature[4], expected 4, is {}",
                    msg.signature[4]
                );
                assert_eq!(
                    msg.signature[5], 5,
                    "incorrect value for signature[5], expected 5, is {}",
                    msg.signature[5]
                );
                assert_eq!(
                    msg.signature[6], 6,
                    "incorrect value for signature[6], expected 6, is {}",
                    msg.signature[6]
                );
                assert_eq!(
                    msg.signature[7], 7,
                    "incorrect value for signature[7], expected 7, is {}",
                    msg.signature[7]
                );
                assert_eq!(
                    msg.signature[8], 8,
                    "incorrect value for signature[8], expected 8, is {}",
                    msg.signature[8]
                );
                assert_eq!(
                    msg.signature[9], 9,
                    "incorrect value for signature[9], expected 9, is {}",
                    msg.signature[9]
                );
                assert_eq!(
                    msg.signature[10], 10,
                    "incorrect value for signature[10], expected 10, is {}",
                    msg.signature[10]
                );
                assert_eq!(
                    msg.signature[11], 11,
                    "incorrect value for signature[11], expected 11, is {}",
                    msg.signature[11]
                );
                assert_eq!(
                    msg.signature[12], 12,
                    "incorrect value for signature[12], expected 12, is {}",
                    msg.signature[12]
                );
                assert_eq!(
                    msg.signature[13], 13,
                    "incorrect value for signature[13], expected 13, is {}",
                    msg.signature[13]
                );
                assert_eq!(
                    msg.signature[14], 14,
                    "incorrect value for signature[14], expected 14, is {}",
                    msg.signature[14]
                );
                assert_eq!(
                    msg.signature[15], 15,
                    "incorrect value for signature[15], expected 15, is {}",
                    msg.signature[15]
                );
                assert_eq!(
                    msg.signed_messages[0], 11,
                    "incorrect value for signed_messages[0], expected 11, is {}",
                    msg.signed_messages[0]
                );
                assert_eq!(
                    msg.signed_messages[1], 22,
                    "incorrect value for signed_messages[1], expected 22, is {}",
                    msg.signed_messages[1]
                );
                assert_eq!(
                    msg.signed_messages[2], 33,
                    "incorrect value for signed_messages[2], expected 33, is {}",
                    msg.signed_messages[2]
                );
                assert_eq!(
                    msg.stream_counter, 1,
                    "incorrect value for stream_counter, expected 1, is {}",
                    msg.stream_counter
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAesCmacSignature"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_signing_msg_aes_cmac_signature`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_signing_msg_aes_cmac_signature() {
    {
        let mut payload = Cursor::new(vec![
            85, 16, 12, 66, 0, 26, 1, 2, 1, 2, 3, 4, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
            14, 15, 0, 11, 22, 33, 192, 21,
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
        let sbp_msg = sbp::messages::Sbp::MsgAesCmacSignature(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAesCmacSignature(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC10,
                    "Incorrect message type, expected 0xC10, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {sender_id}"
                );
                assert_eq!(
                    msg.certificate_id[0], 1,
                    "incorrect value for certificate_id[0], expected 1, is {}",
                    msg.certificate_id[0]
                );
                assert_eq!(
                    msg.certificate_id[1], 2,
                    "incorrect value for certificate_id[1], expected 2, is {}",
                    msg.certificate_id[1]
                );
                assert_eq!(
                    msg.certificate_id[2], 3,
                    "incorrect value for certificate_id[2], expected 3, is {}",
                    msg.certificate_id[2]
                );
                assert_eq!(
                    msg.certificate_id[3], 4,
                    "incorrect value for certificate_id[3], expected 4, is {}",
                    msg.certificate_id[3]
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.on_demand_counter, 2,
                    "incorrect value for on_demand_counter, expected 2, is {}",
                    msg.on_demand_counter
                );
                assert_eq!(
                    msg.signature[0], 0,
                    "incorrect value for signature[0], expected 0, is {}",
                    msg.signature[0]
                );
                assert_eq!(
                    msg.signature[1], 1,
                    "incorrect value for signature[1], expected 1, is {}",
                    msg.signature[1]
                );
                assert_eq!(
                    msg.signature[2], 2,
                    "incorrect value for signature[2], expected 2, is {}",
                    msg.signature[2]
                );
                assert_eq!(
                    msg.signature[3], 3,
                    "incorrect value for signature[3], expected 3, is {}",
                    msg.signature[3]
                );
                assert_eq!(
                    msg.signature[4], 4,
                    "incorrect value for signature[4], expected 4, is {}",
                    msg.signature[4]
                );
                assert_eq!(
                    msg.signature[5], 5,
                    "incorrect value for signature[5], expected 5, is {}",
                    msg.signature[5]
                );
                assert_eq!(
                    msg.signature[6], 6,
                    "incorrect value for signature[6], expected 6, is {}",
                    msg.signature[6]
                );
                assert_eq!(
                    msg.signature[7], 7,
                    "incorrect value for signature[7], expected 7, is {}",
                    msg.signature[7]
                );
                assert_eq!(
                    msg.signature[8], 8,
                    "incorrect value for signature[8], expected 8, is {}",
                    msg.signature[8]
                );
                assert_eq!(
                    msg.signature[9], 9,
                    "incorrect value for signature[9], expected 9, is {}",
                    msg.signature[9]
                );
                assert_eq!(
                    msg.signature[10], 10,
                    "incorrect value for signature[10], expected 10, is {}",
                    msg.signature[10]
                );
                assert_eq!(
                    msg.signature[11], 11,
                    "incorrect value for signature[11], expected 11, is {}",
                    msg.signature[11]
                );
                assert_eq!(
                    msg.signature[12], 12,
                    "incorrect value for signature[12], expected 12, is {}",
                    msg.signature[12]
                );
                assert_eq!(
                    msg.signature[13], 13,
                    "incorrect value for signature[13], expected 13, is {}",
                    msg.signature[13]
                );
                assert_eq!(
                    msg.signature[14], 14,
                    "incorrect value for signature[14], expected 14, is {}",
                    msg.signature[14]
                );
                assert_eq!(
                    msg.signature[15], 15,
                    "incorrect value for signature[15], expected 15, is {}",
                    msg.signature[15]
                );
                assert_eq!(
                    msg.signed_messages[0], 11,
                    "incorrect value for signed_messages[0], expected 11, is {}",
                    msg.signed_messages[0]
                );
                assert_eq!(
                    msg.signed_messages[1], 22,
                    "incorrect value for signed_messages[1], expected 22, is {}",
                    msg.signed_messages[1]
                );
                assert_eq!(
                    msg.signed_messages[2], 33,
                    "incorrect value for signed_messages[2], expected 33, is {}",
                    msg.signed_messages[2]
                );
                assert_eq!(
                    msg.stream_counter, 1,
                    "incorrect value for stream_counter, expected 1, is {}",
                    msg.stream_counter
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAesCmacSignature"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
