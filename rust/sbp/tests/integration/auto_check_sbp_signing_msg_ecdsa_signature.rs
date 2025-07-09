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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignature.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_signing_msg_ecdsa_signature() {
    {
        let mut payload = Cursor::new(vec![
            85, 8, 12, 66, 0, 83, 0, 1, 2, 1, 2, 3, 4, 72, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
            12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
            34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55,
            56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 10, 21, 23, 232, 131,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgEcdsaSignature(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC08,
                    "Incorrect message type, expected 0xC08, is {msg_type}"
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
                    msg.signature.data[0], 0,
                    "incorrect value for signature.data[0], expected 0, is {}",
                    msg.signature.data[0]
                );
                assert_eq!(
                    msg.signature.data[1], 1,
                    "incorrect value for signature.data[1], expected 1, is {}",
                    msg.signature.data[1]
                );
                assert_eq!(
                    msg.signature.data[2], 2,
                    "incorrect value for signature.data[2], expected 2, is {}",
                    msg.signature.data[2]
                );
                assert_eq!(
                    msg.signature.data[3], 3,
                    "incorrect value for signature.data[3], expected 3, is {}",
                    msg.signature.data[3]
                );
                assert_eq!(
                    msg.signature.data[4], 4,
                    "incorrect value for signature.data[4], expected 4, is {}",
                    msg.signature.data[4]
                );
                assert_eq!(
                    msg.signature.data[5], 5,
                    "incorrect value for signature.data[5], expected 5, is {}",
                    msg.signature.data[5]
                );
                assert_eq!(
                    msg.signature.data[6], 6,
                    "incorrect value for signature.data[6], expected 6, is {}",
                    msg.signature.data[6]
                );
                assert_eq!(
                    msg.signature.data[7], 7,
                    "incorrect value for signature.data[7], expected 7, is {}",
                    msg.signature.data[7]
                );
                assert_eq!(
                    msg.signature.data[8], 8,
                    "incorrect value for signature.data[8], expected 8, is {}",
                    msg.signature.data[8]
                );
                assert_eq!(
                    msg.signature.data[9], 9,
                    "incorrect value for signature.data[9], expected 9, is {}",
                    msg.signature.data[9]
                );
                assert_eq!(
                    msg.signature.data[10], 10,
                    "incorrect value for signature.data[10], expected 10, is {}",
                    msg.signature.data[10]
                );
                assert_eq!(
                    msg.signature.data[11], 11,
                    "incorrect value for signature.data[11], expected 11, is {}",
                    msg.signature.data[11]
                );
                assert_eq!(
                    msg.signature.data[12], 12,
                    "incorrect value for signature.data[12], expected 12, is {}",
                    msg.signature.data[12]
                );
                assert_eq!(
                    msg.signature.data[13], 13,
                    "incorrect value for signature.data[13], expected 13, is {}",
                    msg.signature.data[13]
                );
                assert_eq!(
                    msg.signature.data[14], 14,
                    "incorrect value for signature.data[14], expected 14, is {}",
                    msg.signature.data[14]
                );
                assert_eq!(
                    msg.signature.data[15], 15,
                    "incorrect value for signature.data[15], expected 15, is {}",
                    msg.signature.data[15]
                );
                assert_eq!(
                    msg.signature.data[16], 16,
                    "incorrect value for signature.data[16], expected 16, is {}",
                    msg.signature.data[16]
                );
                assert_eq!(
                    msg.signature.data[17], 17,
                    "incorrect value for signature.data[17], expected 17, is {}",
                    msg.signature.data[17]
                );
                assert_eq!(
                    msg.signature.data[18], 18,
                    "incorrect value for signature.data[18], expected 18, is {}",
                    msg.signature.data[18]
                );
                assert_eq!(
                    msg.signature.data[19], 19,
                    "incorrect value for signature.data[19], expected 19, is {}",
                    msg.signature.data[19]
                );
                assert_eq!(
                    msg.signature.data[20], 20,
                    "incorrect value for signature.data[20], expected 20, is {}",
                    msg.signature.data[20]
                );
                assert_eq!(
                    msg.signature.data[21], 21,
                    "incorrect value for signature.data[21], expected 21, is {}",
                    msg.signature.data[21]
                );
                assert_eq!(
                    msg.signature.data[22], 22,
                    "incorrect value for signature.data[22], expected 22, is {}",
                    msg.signature.data[22]
                );
                assert_eq!(
                    msg.signature.data[23], 23,
                    "incorrect value for signature.data[23], expected 23, is {}",
                    msg.signature.data[23]
                );
                assert_eq!(
                    msg.signature.data[24], 24,
                    "incorrect value for signature.data[24], expected 24, is {}",
                    msg.signature.data[24]
                );
                assert_eq!(
                    msg.signature.data[25], 25,
                    "incorrect value for signature.data[25], expected 25, is {}",
                    msg.signature.data[25]
                );
                assert_eq!(
                    msg.signature.data[26], 26,
                    "incorrect value for signature.data[26], expected 26, is {}",
                    msg.signature.data[26]
                );
                assert_eq!(
                    msg.signature.data[27], 27,
                    "incorrect value for signature.data[27], expected 27, is {}",
                    msg.signature.data[27]
                );
                assert_eq!(
                    msg.signature.data[28], 28,
                    "incorrect value for signature.data[28], expected 28, is {}",
                    msg.signature.data[28]
                );
                assert_eq!(
                    msg.signature.data[29], 29,
                    "incorrect value for signature.data[29], expected 29, is {}",
                    msg.signature.data[29]
                );
                assert_eq!(
                    msg.signature.data[30], 30,
                    "incorrect value for signature.data[30], expected 30, is {}",
                    msg.signature.data[30]
                );
                assert_eq!(
                    msg.signature.data[31], 31,
                    "incorrect value for signature.data[31], expected 31, is {}",
                    msg.signature.data[31]
                );
                assert_eq!(
                    msg.signature.data[32], 32,
                    "incorrect value for signature.data[32], expected 32, is {}",
                    msg.signature.data[32]
                );
                assert_eq!(
                    msg.signature.data[33], 33,
                    "incorrect value for signature.data[33], expected 33, is {}",
                    msg.signature.data[33]
                );
                assert_eq!(
                    msg.signature.data[34], 34,
                    "incorrect value for signature.data[34], expected 34, is {}",
                    msg.signature.data[34]
                );
                assert_eq!(
                    msg.signature.data[35], 35,
                    "incorrect value for signature.data[35], expected 35, is {}",
                    msg.signature.data[35]
                );
                assert_eq!(
                    msg.signature.data[36], 36,
                    "incorrect value for signature.data[36], expected 36, is {}",
                    msg.signature.data[36]
                );
                assert_eq!(
                    msg.signature.data[37], 37,
                    "incorrect value for signature.data[37], expected 37, is {}",
                    msg.signature.data[37]
                );
                assert_eq!(
                    msg.signature.data[38], 38,
                    "incorrect value for signature.data[38], expected 38, is {}",
                    msg.signature.data[38]
                );
                assert_eq!(
                    msg.signature.data[39], 39,
                    "incorrect value for signature.data[39], expected 39, is {}",
                    msg.signature.data[39]
                );
                assert_eq!(
                    msg.signature.data[40], 40,
                    "incorrect value for signature.data[40], expected 40, is {}",
                    msg.signature.data[40]
                );
                assert_eq!(
                    msg.signature.data[41], 41,
                    "incorrect value for signature.data[41], expected 41, is {}",
                    msg.signature.data[41]
                );
                assert_eq!(
                    msg.signature.data[42], 42,
                    "incorrect value for signature.data[42], expected 42, is {}",
                    msg.signature.data[42]
                );
                assert_eq!(
                    msg.signature.data[43], 43,
                    "incorrect value for signature.data[43], expected 43, is {}",
                    msg.signature.data[43]
                );
                assert_eq!(
                    msg.signature.data[44], 44,
                    "incorrect value for signature.data[44], expected 44, is {}",
                    msg.signature.data[44]
                );
                assert_eq!(
                    msg.signature.data[45], 45,
                    "incorrect value for signature.data[45], expected 45, is {}",
                    msg.signature.data[45]
                );
                assert_eq!(
                    msg.signature.data[46], 46,
                    "incorrect value for signature.data[46], expected 46, is {}",
                    msg.signature.data[46]
                );
                assert_eq!(
                    msg.signature.data[47], 47,
                    "incorrect value for signature.data[47], expected 47, is {}",
                    msg.signature.data[47]
                );
                assert_eq!(
                    msg.signature.data[48], 48,
                    "incorrect value for signature.data[48], expected 48, is {}",
                    msg.signature.data[48]
                );
                assert_eq!(
                    msg.signature.data[49], 49,
                    "incorrect value for signature.data[49], expected 49, is {}",
                    msg.signature.data[49]
                );
                assert_eq!(
                    msg.signature.data[50], 50,
                    "incorrect value for signature.data[50], expected 50, is {}",
                    msg.signature.data[50]
                );
                assert_eq!(
                    msg.signature.data[51], 51,
                    "incorrect value for signature.data[51], expected 51, is {}",
                    msg.signature.data[51]
                );
                assert_eq!(
                    msg.signature.data[52], 52,
                    "incorrect value for signature.data[52], expected 52, is {}",
                    msg.signature.data[52]
                );
                assert_eq!(
                    msg.signature.data[53], 53,
                    "incorrect value for signature.data[53], expected 53, is {}",
                    msg.signature.data[53]
                );
                assert_eq!(
                    msg.signature.data[54], 54,
                    "incorrect value for signature.data[54], expected 54, is {}",
                    msg.signature.data[54]
                );
                assert_eq!(
                    msg.signature.data[55], 55,
                    "incorrect value for signature.data[55], expected 55, is {}",
                    msg.signature.data[55]
                );
                assert_eq!(
                    msg.signature.data[56], 56,
                    "incorrect value for signature.data[56], expected 56, is {}",
                    msg.signature.data[56]
                );
                assert_eq!(
                    msg.signature.data[57], 57,
                    "incorrect value for signature.data[57], expected 57, is {}",
                    msg.signature.data[57]
                );
                assert_eq!(
                    msg.signature.data[58], 58,
                    "incorrect value for signature.data[58], expected 58, is {}",
                    msg.signature.data[58]
                );
                assert_eq!(
                    msg.signature.data[59], 59,
                    "incorrect value for signature.data[59], expected 59, is {}",
                    msg.signature.data[59]
                );
                assert_eq!(
                    msg.signature.data[60], 60,
                    "incorrect value for signature.data[60], expected 60, is {}",
                    msg.signature.data[60]
                );
                assert_eq!(
                    msg.signature.data[61], 61,
                    "incorrect value for signature.data[61], expected 61, is {}",
                    msg.signature.data[61]
                );
                assert_eq!(
                    msg.signature.data[62], 62,
                    "incorrect value for signature.data[62], expected 62, is {}",
                    msg.signature.data[62]
                );
                assert_eq!(
                    msg.signature.data[63], 63,
                    "incorrect value for signature.data[63], expected 63, is {}",
                    msg.signature.data[63]
                );
                assert_eq!(
                    msg.signature.data[64], 64,
                    "incorrect value for signature.data[64], expected 64, is {}",
                    msg.signature.data[64]
                );
                assert_eq!(
                    msg.signature.data[65], 65,
                    "incorrect value for signature.data[65], expected 65, is {}",
                    msg.signature.data[65]
                );
                assert_eq!(
                    msg.signature.data[66], 66,
                    "incorrect value for signature.data[66], expected 66, is {}",
                    msg.signature.data[66]
                );
                assert_eq!(
                    msg.signature.data[67], 67,
                    "incorrect value for signature.data[67], expected 67, is {}",
                    msg.signature.data[67]
                );
                assert_eq!(
                    msg.signature.data[68], 68,
                    "incorrect value for signature.data[68], expected 68, is {}",
                    msg.signature.data[68]
                );
                assert_eq!(
                    msg.signature.data[69], 69,
                    "incorrect value for signature.data[69], expected 69, is {}",
                    msg.signature.data[69]
                );
                assert_eq!(
                    msg.signature.data[70], 70,
                    "incorrect value for signature.data[70], expected 70, is {}",
                    msg.signature.data[70]
                );
                assert_eq!(
                    msg.signature.data[71], 71,
                    "incorrect value for signature.data[71], expected 71, is {}",
                    msg.signature.data[71]
                );
                assert_eq!(
                    msg.signature.len, 72,
                    "incorrect value for signature.len, expected 72, is {}",
                    msg.signature.len
                );
                assert_eq!(
                    msg.signed_messages[0], 10,
                    "incorrect value for signed_messages[0], expected 10, is {}",
                    msg.signed_messages[0]
                );
                assert_eq!(
                    msg.signed_messages[1], 21,
                    "incorrect value for signed_messages[1], expected 21, is {}",
                    msg.signed_messages[1]
                );
                assert_eq!(
                    msg.signed_messages[2], 23,
                    "incorrect value for signed_messages[2], expected 23, is {}",
                    msg.signed_messages[2]
                );
                assert_eq!(
                    msg.stream_counter, 1,
                    "incorrect value for stream_counter, expected 1, is {}",
                    msg.stream_counter
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEcdsaSignature"),
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
fn test_json2sbp_auto_check_sbp_signing_msg_ecdsa_signature() {
    {
        let json_input = r#"{"preamble": 85, "msg_type": 3080, "sender": 66, "length": 83, "payload": "AAECAQIDBEgAAQIDBAUGBwgJCgsMDQ4PEBESExQVFhcYGRobHB0eHyAhIiMkJSYnKCkqKywtLi8wMTIzNDU2Nzg5Ojs8PT4/QEFCQ0RFRkcKFRc=", "crc": 33768, "flags": 0, "stream_counter": 1, "on_demand_counter": 2, "certificate_id": [1, 2, 3, 4], "signature": {"len": 72, "data": [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71]}, "signed_messages": [10, 21, 23]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgEcdsaSignature(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC08,
                    "Incorrect message type, expected 0xC08, is {}",
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
                    msg.signature.data[0], 0,
                    "incorrect value for signature.data[0], expected 0, is {}",
                    msg.signature.data[0]
                );
                assert_eq!(
                    msg.signature.data[1], 1,
                    "incorrect value for signature.data[1], expected 1, is {}",
                    msg.signature.data[1]
                );
                assert_eq!(
                    msg.signature.data[2], 2,
                    "incorrect value for signature.data[2], expected 2, is {}",
                    msg.signature.data[2]
                );
                assert_eq!(
                    msg.signature.data[3], 3,
                    "incorrect value for signature.data[3], expected 3, is {}",
                    msg.signature.data[3]
                );
                assert_eq!(
                    msg.signature.data[4], 4,
                    "incorrect value for signature.data[4], expected 4, is {}",
                    msg.signature.data[4]
                );
                assert_eq!(
                    msg.signature.data[5], 5,
                    "incorrect value for signature.data[5], expected 5, is {}",
                    msg.signature.data[5]
                );
                assert_eq!(
                    msg.signature.data[6], 6,
                    "incorrect value for signature.data[6], expected 6, is {}",
                    msg.signature.data[6]
                );
                assert_eq!(
                    msg.signature.data[7], 7,
                    "incorrect value for signature.data[7], expected 7, is {}",
                    msg.signature.data[7]
                );
                assert_eq!(
                    msg.signature.data[8], 8,
                    "incorrect value for signature.data[8], expected 8, is {}",
                    msg.signature.data[8]
                );
                assert_eq!(
                    msg.signature.data[9], 9,
                    "incorrect value for signature.data[9], expected 9, is {}",
                    msg.signature.data[9]
                );
                assert_eq!(
                    msg.signature.data[10], 10,
                    "incorrect value for signature.data[10], expected 10, is {}",
                    msg.signature.data[10]
                );
                assert_eq!(
                    msg.signature.data[11], 11,
                    "incorrect value for signature.data[11], expected 11, is {}",
                    msg.signature.data[11]
                );
                assert_eq!(
                    msg.signature.data[12], 12,
                    "incorrect value for signature.data[12], expected 12, is {}",
                    msg.signature.data[12]
                );
                assert_eq!(
                    msg.signature.data[13], 13,
                    "incorrect value for signature.data[13], expected 13, is {}",
                    msg.signature.data[13]
                );
                assert_eq!(
                    msg.signature.data[14], 14,
                    "incorrect value for signature.data[14], expected 14, is {}",
                    msg.signature.data[14]
                );
                assert_eq!(
                    msg.signature.data[15], 15,
                    "incorrect value for signature.data[15], expected 15, is {}",
                    msg.signature.data[15]
                );
                assert_eq!(
                    msg.signature.data[16], 16,
                    "incorrect value for signature.data[16], expected 16, is {}",
                    msg.signature.data[16]
                );
                assert_eq!(
                    msg.signature.data[17], 17,
                    "incorrect value for signature.data[17], expected 17, is {}",
                    msg.signature.data[17]
                );
                assert_eq!(
                    msg.signature.data[18], 18,
                    "incorrect value for signature.data[18], expected 18, is {}",
                    msg.signature.data[18]
                );
                assert_eq!(
                    msg.signature.data[19], 19,
                    "incorrect value for signature.data[19], expected 19, is {}",
                    msg.signature.data[19]
                );
                assert_eq!(
                    msg.signature.data[20], 20,
                    "incorrect value for signature.data[20], expected 20, is {}",
                    msg.signature.data[20]
                );
                assert_eq!(
                    msg.signature.data[21], 21,
                    "incorrect value for signature.data[21], expected 21, is {}",
                    msg.signature.data[21]
                );
                assert_eq!(
                    msg.signature.data[22], 22,
                    "incorrect value for signature.data[22], expected 22, is {}",
                    msg.signature.data[22]
                );
                assert_eq!(
                    msg.signature.data[23], 23,
                    "incorrect value for signature.data[23], expected 23, is {}",
                    msg.signature.data[23]
                );
                assert_eq!(
                    msg.signature.data[24], 24,
                    "incorrect value for signature.data[24], expected 24, is {}",
                    msg.signature.data[24]
                );
                assert_eq!(
                    msg.signature.data[25], 25,
                    "incorrect value for signature.data[25], expected 25, is {}",
                    msg.signature.data[25]
                );
                assert_eq!(
                    msg.signature.data[26], 26,
                    "incorrect value for signature.data[26], expected 26, is {}",
                    msg.signature.data[26]
                );
                assert_eq!(
                    msg.signature.data[27], 27,
                    "incorrect value for signature.data[27], expected 27, is {}",
                    msg.signature.data[27]
                );
                assert_eq!(
                    msg.signature.data[28], 28,
                    "incorrect value for signature.data[28], expected 28, is {}",
                    msg.signature.data[28]
                );
                assert_eq!(
                    msg.signature.data[29], 29,
                    "incorrect value for signature.data[29], expected 29, is {}",
                    msg.signature.data[29]
                );
                assert_eq!(
                    msg.signature.data[30], 30,
                    "incorrect value for signature.data[30], expected 30, is {}",
                    msg.signature.data[30]
                );
                assert_eq!(
                    msg.signature.data[31], 31,
                    "incorrect value for signature.data[31], expected 31, is {}",
                    msg.signature.data[31]
                );
                assert_eq!(
                    msg.signature.data[32], 32,
                    "incorrect value for signature.data[32], expected 32, is {}",
                    msg.signature.data[32]
                );
                assert_eq!(
                    msg.signature.data[33], 33,
                    "incorrect value for signature.data[33], expected 33, is {}",
                    msg.signature.data[33]
                );
                assert_eq!(
                    msg.signature.data[34], 34,
                    "incorrect value for signature.data[34], expected 34, is {}",
                    msg.signature.data[34]
                );
                assert_eq!(
                    msg.signature.data[35], 35,
                    "incorrect value for signature.data[35], expected 35, is {}",
                    msg.signature.data[35]
                );
                assert_eq!(
                    msg.signature.data[36], 36,
                    "incorrect value for signature.data[36], expected 36, is {}",
                    msg.signature.data[36]
                );
                assert_eq!(
                    msg.signature.data[37], 37,
                    "incorrect value for signature.data[37], expected 37, is {}",
                    msg.signature.data[37]
                );
                assert_eq!(
                    msg.signature.data[38], 38,
                    "incorrect value for signature.data[38], expected 38, is {}",
                    msg.signature.data[38]
                );
                assert_eq!(
                    msg.signature.data[39], 39,
                    "incorrect value for signature.data[39], expected 39, is {}",
                    msg.signature.data[39]
                );
                assert_eq!(
                    msg.signature.data[40], 40,
                    "incorrect value for signature.data[40], expected 40, is {}",
                    msg.signature.data[40]
                );
                assert_eq!(
                    msg.signature.data[41], 41,
                    "incorrect value for signature.data[41], expected 41, is {}",
                    msg.signature.data[41]
                );
                assert_eq!(
                    msg.signature.data[42], 42,
                    "incorrect value for signature.data[42], expected 42, is {}",
                    msg.signature.data[42]
                );
                assert_eq!(
                    msg.signature.data[43], 43,
                    "incorrect value for signature.data[43], expected 43, is {}",
                    msg.signature.data[43]
                );
                assert_eq!(
                    msg.signature.data[44], 44,
                    "incorrect value for signature.data[44], expected 44, is {}",
                    msg.signature.data[44]
                );
                assert_eq!(
                    msg.signature.data[45], 45,
                    "incorrect value for signature.data[45], expected 45, is {}",
                    msg.signature.data[45]
                );
                assert_eq!(
                    msg.signature.data[46], 46,
                    "incorrect value for signature.data[46], expected 46, is {}",
                    msg.signature.data[46]
                );
                assert_eq!(
                    msg.signature.data[47], 47,
                    "incorrect value for signature.data[47], expected 47, is {}",
                    msg.signature.data[47]
                );
                assert_eq!(
                    msg.signature.data[48], 48,
                    "incorrect value for signature.data[48], expected 48, is {}",
                    msg.signature.data[48]
                );
                assert_eq!(
                    msg.signature.data[49], 49,
                    "incorrect value for signature.data[49], expected 49, is {}",
                    msg.signature.data[49]
                );
                assert_eq!(
                    msg.signature.data[50], 50,
                    "incorrect value for signature.data[50], expected 50, is {}",
                    msg.signature.data[50]
                );
                assert_eq!(
                    msg.signature.data[51], 51,
                    "incorrect value for signature.data[51], expected 51, is {}",
                    msg.signature.data[51]
                );
                assert_eq!(
                    msg.signature.data[52], 52,
                    "incorrect value for signature.data[52], expected 52, is {}",
                    msg.signature.data[52]
                );
                assert_eq!(
                    msg.signature.data[53], 53,
                    "incorrect value for signature.data[53], expected 53, is {}",
                    msg.signature.data[53]
                );
                assert_eq!(
                    msg.signature.data[54], 54,
                    "incorrect value for signature.data[54], expected 54, is {}",
                    msg.signature.data[54]
                );
                assert_eq!(
                    msg.signature.data[55], 55,
                    "incorrect value for signature.data[55], expected 55, is {}",
                    msg.signature.data[55]
                );
                assert_eq!(
                    msg.signature.data[56], 56,
                    "incorrect value for signature.data[56], expected 56, is {}",
                    msg.signature.data[56]
                );
                assert_eq!(
                    msg.signature.data[57], 57,
                    "incorrect value for signature.data[57], expected 57, is {}",
                    msg.signature.data[57]
                );
                assert_eq!(
                    msg.signature.data[58], 58,
                    "incorrect value for signature.data[58], expected 58, is {}",
                    msg.signature.data[58]
                );
                assert_eq!(
                    msg.signature.data[59], 59,
                    "incorrect value for signature.data[59], expected 59, is {}",
                    msg.signature.data[59]
                );
                assert_eq!(
                    msg.signature.data[60], 60,
                    "incorrect value for signature.data[60], expected 60, is {}",
                    msg.signature.data[60]
                );
                assert_eq!(
                    msg.signature.data[61], 61,
                    "incorrect value for signature.data[61], expected 61, is {}",
                    msg.signature.data[61]
                );
                assert_eq!(
                    msg.signature.data[62], 62,
                    "incorrect value for signature.data[62], expected 62, is {}",
                    msg.signature.data[62]
                );
                assert_eq!(
                    msg.signature.data[63], 63,
                    "incorrect value for signature.data[63], expected 63, is {}",
                    msg.signature.data[63]
                );
                assert_eq!(
                    msg.signature.data[64], 64,
                    "incorrect value for signature.data[64], expected 64, is {}",
                    msg.signature.data[64]
                );
                assert_eq!(
                    msg.signature.data[65], 65,
                    "incorrect value for signature.data[65], expected 65, is {}",
                    msg.signature.data[65]
                );
                assert_eq!(
                    msg.signature.data[66], 66,
                    "incorrect value for signature.data[66], expected 66, is {}",
                    msg.signature.data[66]
                );
                assert_eq!(
                    msg.signature.data[67], 67,
                    "incorrect value for signature.data[67], expected 67, is {}",
                    msg.signature.data[67]
                );
                assert_eq!(
                    msg.signature.data[68], 68,
                    "incorrect value for signature.data[68], expected 68, is {}",
                    msg.signature.data[68]
                );
                assert_eq!(
                    msg.signature.data[69], 69,
                    "incorrect value for signature.data[69], expected 69, is {}",
                    msg.signature.data[69]
                );
                assert_eq!(
                    msg.signature.data[70], 70,
                    "incorrect value for signature.data[70], expected 70, is {}",
                    msg.signature.data[70]
                );
                assert_eq!(
                    msg.signature.data[71], 71,
                    "incorrect value for signature.data[71], expected 71, is {}",
                    msg.signature.data[71]
                );
                assert_eq!(
                    msg.signature.len, 72,
                    "incorrect value for signature.len, expected 72, is {}",
                    msg.signature.len
                );
                assert_eq!(
                    msg.signed_messages[0], 10,
                    "incorrect value for signed_messages[0], expected 10, is {}",
                    msg.signed_messages[0]
                );
                assert_eq!(
                    msg.signed_messages[1], 21,
                    "incorrect value for signed_messages[1], expected 21, is {}",
                    msg.signed_messages[1]
                );
                assert_eq!(
                    msg.signed_messages[2], 23,
                    "incorrect value for signed_messages[2], expected 23, is {}",
                    msg.signed_messages[2]
                );
                assert_eq!(
                    msg.stream_counter, 1,
                    "incorrect value for stream_counter, expected 1, is {}",
                    msg.stream_counter
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEcdsaSignature"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_signing_msg_ecdsa_signature`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_signing_msg_ecdsa_signature() {
    {
        let mut payload = Cursor::new(vec![
            85, 8, 12, 66, 0, 83, 0, 1, 2, 1, 2, 3, 4, 72, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
            12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
            34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55,
            56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 10, 21, 23, 232, 131,
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
        let sbp_msg = sbp::messages::Sbp::MsgEcdsaSignature(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgEcdsaSignature(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC08,
                    "Incorrect message type, expected 0xC08, is {}",
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
                    msg.signature.data[0], 0,
                    "incorrect value for signature.data[0], expected 0, is {}",
                    msg.signature.data[0]
                );
                assert_eq!(
                    msg.signature.data[1], 1,
                    "incorrect value for signature.data[1], expected 1, is {}",
                    msg.signature.data[1]
                );
                assert_eq!(
                    msg.signature.data[2], 2,
                    "incorrect value for signature.data[2], expected 2, is {}",
                    msg.signature.data[2]
                );
                assert_eq!(
                    msg.signature.data[3], 3,
                    "incorrect value for signature.data[3], expected 3, is {}",
                    msg.signature.data[3]
                );
                assert_eq!(
                    msg.signature.data[4], 4,
                    "incorrect value for signature.data[4], expected 4, is {}",
                    msg.signature.data[4]
                );
                assert_eq!(
                    msg.signature.data[5], 5,
                    "incorrect value for signature.data[5], expected 5, is {}",
                    msg.signature.data[5]
                );
                assert_eq!(
                    msg.signature.data[6], 6,
                    "incorrect value for signature.data[6], expected 6, is {}",
                    msg.signature.data[6]
                );
                assert_eq!(
                    msg.signature.data[7], 7,
                    "incorrect value for signature.data[7], expected 7, is {}",
                    msg.signature.data[7]
                );
                assert_eq!(
                    msg.signature.data[8], 8,
                    "incorrect value for signature.data[8], expected 8, is {}",
                    msg.signature.data[8]
                );
                assert_eq!(
                    msg.signature.data[9], 9,
                    "incorrect value for signature.data[9], expected 9, is {}",
                    msg.signature.data[9]
                );
                assert_eq!(
                    msg.signature.data[10], 10,
                    "incorrect value for signature.data[10], expected 10, is {}",
                    msg.signature.data[10]
                );
                assert_eq!(
                    msg.signature.data[11], 11,
                    "incorrect value for signature.data[11], expected 11, is {}",
                    msg.signature.data[11]
                );
                assert_eq!(
                    msg.signature.data[12], 12,
                    "incorrect value for signature.data[12], expected 12, is {}",
                    msg.signature.data[12]
                );
                assert_eq!(
                    msg.signature.data[13], 13,
                    "incorrect value for signature.data[13], expected 13, is {}",
                    msg.signature.data[13]
                );
                assert_eq!(
                    msg.signature.data[14], 14,
                    "incorrect value for signature.data[14], expected 14, is {}",
                    msg.signature.data[14]
                );
                assert_eq!(
                    msg.signature.data[15], 15,
                    "incorrect value for signature.data[15], expected 15, is {}",
                    msg.signature.data[15]
                );
                assert_eq!(
                    msg.signature.data[16], 16,
                    "incorrect value for signature.data[16], expected 16, is {}",
                    msg.signature.data[16]
                );
                assert_eq!(
                    msg.signature.data[17], 17,
                    "incorrect value for signature.data[17], expected 17, is {}",
                    msg.signature.data[17]
                );
                assert_eq!(
                    msg.signature.data[18], 18,
                    "incorrect value for signature.data[18], expected 18, is {}",
                    msg.signature.data[18]
                );
                assert_eq!(
                    msg.signature.data[19], 19,
                    "incorrect value for signature.data[19], expected 19, is {}",
                    msg.signature.data[19]
                );
                assert_eq!(
                    msg.signature.data[20], 20,
                    "incorrect value for signature.data[20], expected 20, is {}",
                    msg.signature.data[20]
                );
                assert_eq!(
                    msg.signature.data[21], 21,
                    "incorrect value for signature.data[21], expected 21, is {}",
                    msg.signature.data[21]
                );
                assert_eq!(
                    msg.signature.data[22], 22,
                    "incorrect value for signature.data[22], expected 22, is {}",
                    msg.signature.data[22]
                );
                assert_eq!(
                    msg.signature.data[23], 23,
                    "incorrect value for signature.data[23], expected 23, is {}",
                    msg.signature.data[23]
                );
                assert_eq!(
                    msg.signature.data[24], 24,
                    "incorrect value for signature.data[24], expected 24, is {}",
                    msg.signature.data[24]
                );
                assert_eq!(
                    msg.signature.data[25], 25,
                    "incorrect value for signature.data[25], expected 25, is {}",
                    msg.signature.data[25]
                );
                assert_eq!(
                    msg.signature.data[26], 26,
                    "incorrect value for signature.data[26], expected 26, is {}",
                    msg.signature.data[26]
                );
                assert_eq!(
                    msg.signature.data[27], 27,
                    "incorrect value for signature.data[27], expected 27, is {}",
                    msg.signature.data[27]
                );
                assert_eq!(
                    msg.signature.data[28], 28,
                    "incorrect value for signature.data[28], expected 28, is {}",
                    msg.signature.data[28]
                );
                assert_eq!(
                    msg.signature.data[29], 29,
                    "incorrect value for signature.data[29], expected 29, is {}",
                    msg.signature.data[29]
                );
                assert_eq!(
                    msg.signature.data[30], 30,
                    "incorrect value for signature.data[30], expected 30, is {}",
                    msg.signature.data[30]
                );
                assert_eq!(
                    msg.signature.data[31], 31,
                    "incorrect value for signature.data[31], expected 31, is {}",
                    msg.signature.data[31]
                );
                assert_eq!(
                    msg.signature.data[32], 32,
                    "incorrect value for signature.data[32], expected 32, is {}",
                    msg.signature.data[32]
                );
                assert_eq!(
                    msg.signature.data[33], 33,
                    "incorrect value for signature.data[33], expected 33, is {}",
                    msg.signature.data[33]
                );
                assert_eq!(
                    msg.signature.data[34], 34,
                    "incorrect value for signature.data[34], expected 34, is {}",
                    msg.signature.data[34]
                );
                assert_eq!(
                    msg.signature.data[35], 35,
                    "incorrect value for signature.data[35], expected 35, is {}",
                    msg.signature.data[35]
                );
                assert_eq!(
                    msg.signature.data[36], 36,
                    "incorrect value for signature.data[36], expected 36, is {}",
                    msg.signature.data[36]
                );
                assert_eq!(
                    msg.signature.data[37], 37,
                    "incorrect value for signature.data[37], expected 37, is {}",
                    msg.signature.data[37]
                );
                assert_eq!(
                    msg.signature.data[38], 38,
                    "incorrect value for signature.data[38], expected 38, is {}",
                    msg.signature.data[38]
                );
                assert_eq!(
                    msg.signature.data[39], 39,
                    "incorrect value for signature.data[39], expected 39, is {}",
                    msg.signature.data[39]
                );
                assert_eq!(
                    msg.signature.data[40], 40,
                    "incorrect value for signature.data[40], expected 40, is {}",
                    msg.signature.data[40]
                );
                assert_eq!(
                    msg.signature.data[41], 41,
                    "incorrect value for signature.data[41], expected 41, is {}",
                    msg.signature.data[41]
                );
                assert_eq!(
                    msg.signature.data[42], 42,
                    "incorrect value for signature.data[42], expected 42, is {}",
                    msg.signature.data[42]
                );
                assert_eq!(
                    msg.signature.data[43], 43,
                    "incorrect value for signature.data[43], expected 43, is {}",
                    msg.signature.data[43]
                );
                assert_eq!(
                    msg.signature.data[44], 44,
                    "incorrect value for signature.data[44], expected 44, is {}",
                    msg.signature.data[44]
                );
                assert_eq!(
                    msg.signature.data[45], 45,
                    "incorrect value for signature.data[45], expected 45, is {}",
                    msg.signature.data[45]
                );
                assert_eq!(
                    msg.signature.data[46], 46,
                    "incorrect value for signature.data[46], expected 46, is {}",
                    msg.signature.data[46]
                );
                assert_eq!(
                    msg.signature.data[47], 47,
                    "incorrect value for signature.data[47], expected 47, is {}",
                    msg.signature.data[47]
                );
                assert_eq!(
                    msg.signature.data[48], 48,
                    "incorrect value for signature.data[48], expected 48, is {}",
                    msg.signature.data[48]
                );
                assert_eq!(
                    msg.signature.data[49], 49,
                    "incorrect value for signature.data[49], expected 49, is {}",
                    msg.signature.data[49]
                );
                assert_eq!(
                    msg.signature.data[50], 50,
                    "incorrect value for signature.data[50], expected 50, is {}",
                    msg.signature.data[50]
                );
                assert_eq!(
                    msg.signature.data[51], 51,
                    "incorrect value for signature.data[51], expected 51, is {}",
                    msg.signature.data[51]
                );
                assert_eq!(
                    msg.signature.data[52], 52,
                    "incorrect value for signature.data[52], expected 52, is {}",
                    msg.signature.data[52]
                );
                assert_eq!(
                    msg.signature.data[53], 53,
                    "incorrect value for signature.data[53], expected 53, is {}",
                    msg.signature.data[53]
                );
                assert_eq!(
                    msg.signature.data[54], 54,
                    "incorrect value for signature.data[54], expected 54, is {}",
                    msg.signature.data[54]
                );
                assert_eq!(
                    msg.signature.data[55], 55,
                    "incorrect value for signature.data[55], expected 55, is {}",
                    msg.signature.data[55]
                );
                assert_eq!(
                    msg.signature.data[56], 56,
                    "incorrect value for signature.data[56], expected 56, is {}",
                    msg.signature.data[56]
                );
                assert_eq!(
                    msg.signature.data[57], 57,
                    "incorrect value for signature.data[57], expected 57, is {}",
                    msg.signature.data[57]
                );
                assert_eq!(
                    msg.signature.data[58], 58,
                    "incorrect value for signature.data[58], expected 58, is {}",
                    msg.signature.data[58]
                );
                assert_eq!(
                    msg.signature.data[59], 59,
                    "incorrect value for signature.data[59], expected 59, is {}",
                    msg.signature.data[59]
                );
                assert_eq!(
                    msg.signature.data[60], 60,
                    "incorrect value for signature.data[60], expected 60, is {}",
                    msg.signature.data[60]
                );
                assert_eq!(
                    msg.signature.data[61], 61,
                    "incorrect value for signature.data[61], expected 61, is {}",
                    msg.signature.data[61]
                );
                assert_eq!(
                    msg.signature.data[62], 62,
                    "incorrect value for signature.data[62], expected 62, is {}",
                    msg.signature.data[62]
                );
                assert_eq!(
                    msg.signature.data[63], 63,
                    "incorrect value for signature.data[63], expected 63, is {}",
                    msg.signature.data[63]
                );
                assert_eq!(
                    msg.signature.data[64], 64,
                    "incorrect value for signature.data[64], expected 64, is {}",
                    msg.signature.data[64]
                );
                assert_eq!(
                    msg.signature.data[65], 65,
                    "incorrect value for signature.data[65], expected 65, is {}",
                    msg.signature.data[65]
                );
                assert_eq!(
                    msg.signature.data[66], 66,
                    "incorrect value for signature.data[66], expected 66, is {}",
                    msg.signature.data[66]
                );
                assert_eq!(
                    msg.signature.data[67], 67,
                    "incorrect value for signature.data[67], expected 67, is {}",
                    msg.signature.data[67]
                );
                assert_eq!(
                    msg.signature.data[68], 68,
                    "incorrect value for signature.data[68], expected 68, is {}",
                    msg.signature.data[68]
                );
                assert_eq!(
                    msg.signature.data[69], 69,
                    "incorrect value for signature.data[69], expected 69, is {}",
                    msg.signature.data[69]
                );
                assert_eq!(
                    msg.signature.data[70], 70,
                    "incorrect value for signature.data[70], expected 70, is {}",
                    msg.signature.data[70]
                );
                assert_eq!(
                    msg.signature.data[71], 71,
                    "incorrect value for signature.data[71], expected 71, is {}",
                    msg.signature.data[71]
                );
                assert_eq!(
                    msg.signature.len, 72,
                    "incorrect value for signature.len, expected 72, is {}",
                    msg.signature.len
                );
                assert_eq!(
                    msg.signed_messages[0], 10,
                    "incorrect value for signed_messages[0], expected 10, is {}",
                    msg.signed_messages[0]
                );
                assert_eq!(
                    msg.signed_messages[1], 21,
                    "incorrect value for signed_messages[1], expected 21, is {}",
                    msg.signed_messages[1]
                );
                assert_eq!(
                    msg.signed_messages[2], 23,
                    "incorrect value for signed_messages[2], expected 23, is {}",
                    msg.signed_messages[2]
                );
                assert_eq!(
                    msg.stream_counter, 1,
                    "incorrect value for stream_counter, expected 1, is {}",
                    msg.stream_counter
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEcdsaSignature"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
