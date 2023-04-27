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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignatureDepB.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_signing_msg_ecdsa_signature_dep_b() {
    {
        let mut payload = Cursor::new(vec![
            85, 7, 12, 66, 0, 83, 0, 1, 2, 1, 2, 3, 4, 72, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
            12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
            34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55,
            56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 10, 21, 23, 254, 159,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgEcdsaSignatureDepB(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xC07,
                    "Incorrect message type, expected 0xC07, is {}",
                    msg.message_type()
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
                    msg.n_signature_bytes, 72,
                    "incorrect value for n_signature_bytes, expected 72, is {}",
                    msg.n_signature_bytes
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
                    msg.signature[16], 16,
                    "incorrect value for signature[16], expected 16, is {}",
                    msg.signature[16]
                );
                assert_eq!(
                    msg.signature[17], 17,
                    "incorrect value for signature[17], expected 17, is {}",
                    msg.signature[17]
                );
                assert_eq!(
                    msg.signature[18], 18,
                    "incorrect value for signature[18], expected 18, is {}",
                    msg.signature[18]
                );
                assert_eq!(
                    msg.signature[19], 19,
                    "incorrect value for signature[19], expected 19, is {}",
                    msg.signature[19]
                );
                assert_eq!(
                    msg.signature[20], 20,
                    "incorrect value for signature[20], expected 20, is {}",
                    msg.signature[20]
                );
                assert_eq!(
                    msg.signature[21], 21,
                    "incorrect value for signature[21], expected 21, is {}",
                    msg.signature[21]
                );
                assert_eq!(
                    msg.signature[22], 22,
                    "incorrect value for signature[22], expected 22, is {}",
                    msg.signature[22]
                );
                assert_eq!(
                    msg.signature[23], 23,
                    "incorrect value for signature[23], expected 23, is {}",
                    msg.signature[23]
                );
                assert_eq!(
                    msg.signature[24], 24,
                    "incorrect value for signature[24], expected 24, is {}",
                    msg.signature[24]
                );
                assert_eq!(
                    msg.signature[25], 25,
                    "incorrect value for signature[25], expected 25, is {}",
                    msg.signature[25]
                );
                assert_eq!(
                    msg.signature[26], 26,
                    "incorrect value for signature[26], expected 26, is {}",
                    msg.signature[26]
                );
                assert_eq!(
                    msg.signature[27], 27,
                    "incorrect value for signature[27], expected 27, is {}",
                    msg.signature[27]
                );
                assert_eq!(
                    msg.signature[28], 28,
                    "incorrect value for signature[28], expected 28, is {}",
                    msg.signature[28]
                );
                assert_eq!(
                    msg.signature[29], 29,
                    "incorrect value for signature[29], expected 29, is {}",
                    msg.signature[29]
                );
                assert_eq!(
                    msg.signature[30], 30,
                    "incorrect value for signature[30], expected 30, is {}",
                    msg.signature[30]
                );
                assert_eq!(
                    msg.signature[31], 31,
                    "incorrect value for signature[31], expected 31, is {}",
                    msg.signature[31]
                );
                assert_eq!(
                    msg.signature[32], 32,
                    "incorrect value for signature[32], expected 32, is {}",
                    msg.signature[32]
                );
                assert_eq!(
                    msg.signature[33], 33,
                    "incorrect value for signature[33], expected 33, is {}",
                    msg.signature[33]
                );
                assert_eq!(
                    msg.signature[34], 34,
                    "incorrect value for signature[34], expected 34, is {}",
                    msg.signature[34]
                );
                assert_eq!(
                    msg.signature[35], 35,
                    "incorrect value for signature[35], expected 35, is {}",
                    msg.signature[35]
                );
                assert_eq!(
                    msg.signature[36], 36,
                    "incorrect value for signature[36], expected 36, is {}",
                    msg.signature[36]
                );
                assert_eq!(
                    msg.signature[37], 37,
                    "incorrect value for signature[37], expected 37, is {}",
                    msg.signature[37]
                );
                assert_eq!(
                    msg.signature[38], 38,
                    "incorrect value for signature[38], expected 38, is {}",
                    msg.signature[38]
                );
                assert_eq!(
                    msg.signature[39], 39,
                    "incorrect value for signature[39], expected 39, is {}",
                    msg.signature[39]
                );
                assert_eq!(
                    msg.signature[40], 40,
                    "incorrect value for signature[40], expected 40, is {}",
                    msg.signature[40]
                );
                assert_eq!(
                    msg.signature[41], 41,
                    "incorrect value for signature[41], expected 41, is {}",
                    msg.signature[41]
                );
                assert_eq!(
                    msg.signature[42], 42,
                    "incorrect value for signature[42], expected 42, is {}",
                    msg.signature[42]
                );
                assert_eq!(
                    msg.signature[43], 43,
                    "incorrect value for signature[43], expected 43, is {}",
                    msg.signature[43]
                );
                assert_eq!(
                    msg.signature[44], 44,
                    "incorrect value for signature[44], expected 44, is {}",
                    msg.signature[44]
                );
                assert_eq!(
                    msg.signature[45], 45,
                    "incorrect value for signature[45], expected 45, is {}",
                    msg.signature[45]
                );
                assert_eq!(
                    msg.signature[46], 46,
                    "incorrect value for signature[46], expected 46, is {}",
                    msg.signature[46]
                );
                assert_eq!(
                    msg.signature[47], 47,
                    "incorrect value for signature[47], expected 47, is {}",
                    msg.signature[47]
                );
                assert_eq!(
                    msg.signature[48], 48,
                    "incorrect value for signature[48], expected 48, is {}",
                    msg.signature[48]
                );
                assert_eq!(
                    msg.signature[49], 49,
                    "incorrect value for signature[49], expected 49, is {}",
                    msg.signature[49]
                );
                assert_eq!(
                    msg.signature[50], 50,
                    "incorrect value for signature[50], expected 50, is {}",
                    msg.signature[50]
                );
                assert_eq!(
                    msg.signature[51], 51,
                    "incorrect value for signature[51], expected 51, is {}",
                    msg.signature[51]
                );
                assert_eq!(
                    msg.signature[52], 52,
                    "incorrect value for signature[52], expected 52, is {}",
                    msg.signature[52]
                );
                assert_eq!(
                    msg.signature[53], 53,
                    "incorrect value for signature[53], expected 53, is {}",
                    msg.signature[53]
                );
                assert_eq!(
                    msg.signature[54], 54,
                    "incorrect value for signature[54], expected 54, is {}",
                    msg.signature[54]
                );
                assert_eq!(
                    msg.signature[55], 55,
                    "incorrect value for signature[55], expected 55, is {}",
                    msg.signature[55]
                );
                assert_eq!(
                    msg.signature[56], 56,
                    "incorrect value for signature[56], expected 56, is {}",
                    msg.signature[56]
                );
                assert_eq!(
                    msg.signature[57], 57,
                    "incorrect value for signature[57], expected 57, is {}",
                    msg.signature[57]
                );
                assert_eq!(
                    msg.signature[58], 58,
                    "incorrect value for signature[58], expected 58, is {}",
                    msg.signature[58]
                );
                assert_eq!(
                    msg.signature[59], 59,
                    "incorrect value for signature[59], expected 59, is {}",
                    msg.signature[59]
                );
                assert_eq!(
                    msg.signature[60], 60,
                    "incorrect value for signature[60], expected 60, is {}",
                    msg.signature[60]
                );
                assert_eq!(
                    msg.signature[61], 61,
                    "incorrect value for signature[61], expected 61, is {}",
                    msg.signature[61]
                );
                assert_eq!(
                    msg.signature[62], 62,
                    "incorrect value for signature[62], expected 62, is {}",
                    msg.signature[62]
                );
                assert_eq!(
                    msg.signature[63], 63,
                    "incorrect value for signature[63], expected 63, is {}",
                    msg.signature[63]
                );
                assert_eq!(
                    msg.signature[64], 64,
                    "incorrect value for signature[64], expected 64, is {}",
                    msg.signature[64]
                );
                assert_eq!(
                    msg.signature[65], 65,
                    "incorrect value for signature[65], expected 65, is {}",
                    msg.signature[65]
                );
                assert_eq!(
                    msg.signature[66], 66,
                    "incorrect value for signature[66], expected 66, is {}",
                    msg.signature[66]
                );
                assert_eq!(
                    msg.signature[67], 67,
                    "incorrect value for signature[67], expected 67, is {}",
                    msg.signature[67]
                );
                assert_eq!(
                    msg.signature[68], 68,
                    "incorrect value for signature[68], expected 68, is {}",
                    msg.signature[68]
                );
                assert_eq!(
                    msg.signature[69], 69,
                    "incorrect value for signature[69], expected 69, is {}",
                    msg.signature[69]
                );
                assert_eq!(
                    msg.signature[70], 70,
                    "incorrect value for signature[70], expected 70, is {}",
                    msg.signature[70]
                );
                assert_eq!(
                    msg.signature[71], 71,
                    "incorrect value for signature[71], expected 71, is {}",
                    msg.signature[71]
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
            _ => panic!("Invalid message type! Expected a MsgEcdsaSignatureDepB"),
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
fn test_json2sbp_auto_check_sbp_signing_msg_ecdsa_signature_dep_b() {
    {
        let json_input = r#"{"preamble": 85, "msg_type": 3079, "sender": 66, "length": 83, "payload": "AAECAQIDBEgAAQIDBAUGBwgJCgsMDQ4PEBESExQVFhcYGRobHB0eHyAhIiMkJSYnKCkqKywtLi8wMTIzNDU2Nzg5Ojs8PT4/QEFCQ0RFRkcKFRc=", "crc": 40958, "flags": 0, "stream_counter": 1, "on_demand_counter": 2, "certificate_id": [1, 2, 3, 4], "n_signature_bytes": 72, "signature": [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71], "signed_messages": [10, 21, 23]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgEcdsaSignatureDepB(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xC07,
                    "Incorrect message type, expected 0xC07, is {}",
                    msg.message_type()
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
                    msg.n_signature_bytes, 72,
                    "incorrect value for n_signature_bytes, expected 72, is {}",
                    msg.n_signature_bytes
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
                    msg.signature[16], 16,
                    "incorrect value for signature[16], expected 16, is {}",
                    msg.signature[16]
                );
                assert_eq!(
                    msg.signature[17], 17,
                    "incorrect value for signature[17], expected 17, is {}",
                    msg.signature[17]
                );
                assert_eq!(
                    msg.signature[18], 18,
                    "incorrect value for signature[18], expected 18, is {}",
                    msg.signature[18]
                );
                assert_eq!(
                    msg.signature[19], 19,
                    "incorrect value for signature[19], expected 19, is {}",
                    msg.signature[19]
                );
                assert_eq!(
                    msg.signature[20], 20,
                    "incorrect value for signature[20], expected 20, is {}",
                    msg.signature[20]
                );
                assert_eq!(
                    msg.signature[21], 21,
                    "incorrect value for signature[21], expected 21, is {}",
                    msg.signature[21]
                );
                assert_eq!(
                    msg.signature[22], 22,
                    "incorrect value for signature[22], expected 22, is {}",
                    msg.signature[22]
                );
                assert_eq!(
                    msg.signature[23], 23,
                    "incorrect value for signature[23], expected 23, is {}",
                    msg.signature[23]
                );
                assert_eq!(
                    msg.signature[24], 24,
                    "incorrect value for signature[24], expected 24, is {}",
                    msg.signature[24]
                );
                assert_eq!(
                    msg.signature[25], 25,
                    "incorrect value for signature[25], expected 25, is {}",
                    msg.signature[25]
                );
                assert_eq!(
                    msg.signature[26], 26,
                    "incorrect value for signature[26], expected 26, is {}",
                    msg.signature[26]
                );
                assert_eq!(
                    msg.signature[27], 27,
                    "incorrect value for signature[27], expected 27, is {}",
                    msg.signature[27]
                );
                assert_eq!(
                    msg.signature[28], 28,
                    "incorrect value for signature[28], expected 28, is {}",
                    msg.signature[28]
                );
                assert_eq!(
                    msg.signature[29], 29,
                    "incorrect value for signature[29], expected 29, is {}",
                    msg.signature[29]
                );
                assert_eq!(
                    msg.signature[30], 30,
                    "incorrect value for signature[30], expected 30, is {}",
                    msg.signature[30]
                );
                assert_eq!(
                    msg.signature[31], 31,
                    "incorrect value for signature[31], expected 31, is {}",
                    msg.signature[31]
                );
                assert_eq!(
                    msg.signature[32], 32,
                    "incorrect value for signature[32], expected 32, is {}",
                    msg.signature[32]
                );
                assert_eq!(
                    msg.signature[33], 33,
                    "incorrect value for signature[33], expected 33, is {}",
                    msg.signature[33]
                );
                assert_eq!(
                    msg.signature[34], 34,
                    "incorrect value for signature[34], expected 34, is {}",
                    msg.signature[34]
                );
                assert_eq!(
                    msg.signature[35], 35,
                    "incorrect value for signature[35], expected 35, is {}",
                    msg.signature[35]
                );
                assert_eq!(
                    msg.signature[36], 36,
                    "incorrect value for signature[36], expected 36, is {}",
                    msg.signature[36]
                );
                assert_eq!(
                    msg.signature[37], 37,
                    "incorrect value for signature[37], expected 37, is {}",
                    msg.signature[37]
                );
                assert_eq!(
                    msg.signature[38], 38,
                    "incorrect value for signature[38], expected 38, is {}",
                    msg.signature[38]
                );
                assert_eq!(
                    msg.signature[39], 39,
                    "incorrect value for signature[39], expected 39, is {}",
                    msg.signature[39]
                );
                assert_eq!(
                    msg.signature[40], 40,
                    "incorrect value for signature[40], expected 40, is {}",
                    msg.signature[40]
                );
                assert_eq!(
                    msg.signature[41], 41,
                    "incorrect value for signature[41], expected 41, is {}",
                    msg.signature[41]
                );
                assert_eq!(
                    msg.signature[42], 42,
                    "incorrect value for signature[42], expected 42, is {}",
                    msg.signature[42]
                );
                assert_eq!(
                    msg.signature[43], 43,
                    "incorrect value for signature[43], expected 43, is {}",
                    msg.signature[43]
                );
                assert_eq!(
                    msg.signature[44], 44,
                    "incorrect value for signature[44], expected 44, is {}",
                    msg.signature[44]
                );
                assert_eq!(
                    msg.signature[45], 45,
                    "incorrect value for signature[45], expected 45, is {}",
                    msg.signature[45]
                );
                assert_eq!(
                    msg.signature[46], 46,
                    "incorrect value for signature[46], expected 46, is {}",
                    msg.signature[46]
                );
                assert_eq!(
                    msg.signature[47], 47,
                    "incorrect value for signature[47], expected 47, is {}",
                    msg.signature[47]
                );
                assert_eq!(
                    msg.signature[48], 48,
                    "incorrect value for signature[48], expected 48, is {}",
                    msg.signature[48]
                );
                assert_eq!(
                    msg.signature[49], 49,
                    "incorrect value for signature[49], expected 49, is {}",
                    msg.signature[49]
                );
                assert_eq!(
                    msg.signature[50], 50,
                    "incorrect value for signature[50], expected 50, is {}",
                    msg.signature[50]
                );
                assert_eq!(
                    msg.signature[51], 51,
                    "incorrect value for signature[51], expected 51, is {}",
                    msg.signature[51]
                );
                assert_eq!(
                    msg.signature[52], 52,
                    "incorrect value for signature[52], expected 52, is {}",
                    msg.signature[52]
                );
                assert_eq!(
                    msg.signature[53], 53,
                    "incorrect value for signature[53], expected 53, is {}",
                    msg.signature[53]
                );
                assert_eq!(
                    msg.signature[54], 54,
                    "incorrect value for signature[54], expected 54, is {}",
                    msg.signature[54]
                );
                assert_eq!(
                    msg.signature[55], 55,
                    "incorrect value for signature[55], expected 55, is {}",
                    msg.signature[55]
                );
                assert_eq!(
                    msg.signature[56], 56,
                    "incorrect value for signature[56], expected 56, is {}",
                    msg.signature[56]
                );
                assert_eq!(
                    msg.signature[57], 57,
                    "incorrect value for signature[57], expected 57, is {}",
                    msg.signature[57]
                );
                assert_eq!(
                    msg.signature[58], 58,
                    "incorrect value for signature[58], expected 58, is {}",
                    msg.signature[58]
                );
                assert_eq!(
                    msg.signature[59], 59,
                    "incorrect value for signature[59], expected 59, is {}",
                    msg.signature[59]
                );
                assert_eq!(
                    msg.signature[60], 60,
                    "incorrect value for signature[60], expected 60, is {}",
                    msg.signature[60]
                );
                assert_eq!(
                    msg.signature[61], 61,
                    "incorrect value for signature[61], expected 61, is {}",
                    msg.signature[61]
                );
                assert_eq!(
                    msg.signature[62], 62,
                    "incorrect value for signature[62], expected 62, is {}",
                    msg.signature[62]
                );
                assert_eq!(
                    msg.signature[63], 63,
                    "incorrect value for signature[63], expected 63, is {}",
                    msg.signature[63]
                );
                assert_eq!(
                    msg.signature[64], 64,
                    "incorrect value for signature[64], expected 64, is {}",
                    msg.signature[64]
                );
                assert_eq!(
                    msg.signature[65], 65,
                    "incorrect value for signature[65], expected 65, is {}",
                    msg.signature[65]
                );
                assert_eq!(
                    msg.signature[66], 66,
                    "incorrect value for signature[66], expected 66, is {}",
                    msg.signature[66]
                );
                assert_eq!(
                    msg.signature[67], 67,
                    "incorrect value for signature[67], expected 67, is {}",
                    msg.signature[67]
                );
                assert_eq!(
                    msg.signature[68], 68,
                    "incorrect value for signature[68], expected 68, is {}",
                    msg.signature[68]
                );
                assert_eq!(
                    msg.signature[69], 69,
                    "incorrect value for signature[69], expected 69, is {}",
                    msg.signature[69]
                );
                assert_eq!(
                    msg.signature[70], 70,
                    "incorrect value for signature[70], expected 70, is {}",
                    msg.signature[70]
                );
                assert_eq!(
                    msg.signature[71], 71,
                    "incorrect value for signature[71], expected 71, is {}",
                    msg.signature[71]
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
            _ => panic!("Invalid message type! Expected a MsgEcdsaSignatureDepB"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_signing_msg_ecdsa_signature_dep_b`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_signing_msg_ecdsa_signature_dep_b() {
    {
        let mut payload = Cursor::new(vec![
            85, 7, 12, 66, 0, 83, 0, 1, 2, 1, 2, 3, 4, 72, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
            12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
            34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55,
            56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 10, 21, 23, 254, 159,
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
        let sbp_msg = sbp::messages::Sbp::MsgEcdsaSignatureDepB(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgEcdsaSignatureDepB(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xC07,
                    "Incorrect message type, expected 0xC07, is {}",
                    msg.message_type()
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
                    msg.n_signature_bytes, 72,
                    "incorrect value for n_signature_bytes, expected 72, is {}",
                    msg.n_signature_bytes
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
                    msg.signature[16], 16,
                    "incorrect value for signature[16], expected 16, is {}",
                    msg.signature[16]
                );
                assert_eq!(
                    msg.signature[17], 17,
                    "incorrect value for signature[17], expected 17, is {}",
                    msg.signature[17]
                );
                assert_eq!(
                    msg.signature[18], 18,
                    "incorrect value for signature[18], expected 18, is {}",
                    msg.signature[18]
                );
                assert_eq!(
                    msg.signature[19], 19,
                    "incorrect value for signature[19], expected 19, is {}",
                    msg.signature[19]
                );
                assert_eq!(
                    msg.signature[20], 20,
                    "incorrect value for signature[20], expected 20, is {}",
                    msg.signature[20]
                );
                assert_eq!(
                    msg.signature[21], 21,
                    "incorrect value for signature[21], expected 21, is {}",
                    msg.signature[21]
                );
                assert_eq!(
                    msg.signature[22], 22,
                    "incorrect value for signature[22], expected 22, is {}",
                    msg.signature[22]
                );
                assert_eq!(
                    msg.signature[23], 23,
                    "incorrect value for signature[23], expected 23, is {}",
                    msg.signature[23]
                );
                assert_eq!(
                    msg.signature[24], 24,
                    "incorrect value for signature[24], expected 24, is {}",
                    msg.signature[24]
                );
                assert_eq!(
                    msg.signature[25], 25,
                    "incorrect value for signature[25], expected 25, is {}",
                    msg.signature[25]
                );
                assert_eq!(
                    msg.signature[26], 26,
                    "incorrect value for signature[26], expected 26, is {}",
                    msg.signature[26]
                );
                assert_eq!(
                    msg.signature[27], 27,
                    "incorrect value for signature[27], expected 27, is {}",
                    msg.signature[27]
                );
                assert_eq!(
                    msg.signature[28], 28,
                    "incorrect value for signature[28], expected 28, is {}",
                    msg.signature[28]
                );
                assert_eq!(
                    msg.signature[29], 29,
                    "incorrect value for signature[29], expected 29, is {}",
                    msg.signature[29]
                );
                assert_eq!(
                    msg.signature[30], 30,
                    "incorrect value for signature[30], expected 30, is {}",
                    msg.signature[30]
                );
                assert_eq!(
                    msg.signature[31], 31,
                    "incorrect value for signature[31], expected 31, is {}",
                    msg.signature[31]
                );
                assert_eq!(
                    msg.signature[32], 32,
                    "incorrect value for signature[32], expected 32, is {}",
                    msg.signature[32]
                );
                assert_eq!(
                    msg.signature[33], 33,
                    "incorrect value for signature[33], expected 33, is {}",
                    msg.signature[33]
                );
                assert_eq!(
                    msg.signature[34], 34,
                    "incorrect value for signature[34], expected 34, is {}",
                    msg.signature[34]
                );
                assert_eq!(
                    msg.signature[35], 35,
                    "incorrect value for signature[35], expected 35, is {}",
                    msg.signature[35]
                );
                assert_eq!(
                    msg.signature[36], 36,
                    "incorrect value for signature[36], expected 36, is {}",
                    msg.signature[36]
                );
                assert_eq!(
                    msg.signature[37], 37,
                    "incorrect value for signature[37], expected 37, is {}",
                    msg.signature[37]
                );
                assert_eq!(
                    msg.signature[38], 38,
                    "incorrect value for signature[38], expected 38, is {}",
                    msg.signature[38]
                );
                assert_eq!(
                    msg.signature[39], 39,
                    "incorrect value for signature[39], expected 39, is {}",
                    msg.signature[39]
                );
                assert_eq!(
                    msg.signature[40], 40,
                    "incorrect value for signature[40], expected 40, is {}",
                    msg.signature[40]
                );
                assert_eq!(
                    msg.signature[41], 41,
                    "incorrect value for signature[41], expected 41, is {}",
                    msg.signature[41]
                );
                assert_eq!(
                    msg.signature[42], 42,
                    "incorrect value for signature[42], expected 42, is {}",
                    msg.signature[42]
                );
                assert_eq!(
                    msg.signature[43], 43,
                    "incorrect value for signature[43], expected 43, is {}",
                    msg.signature[43]
                );
                assert_eq!(
                    msg.signature[44], 44,
                    "incorrect value for signature[44], expected 44, is {}",
                    msg.signature[44]
                );
                assert_eq!(
                    msg.signature[45], 45,
                    "incorrect value for signature[45], expected 45, is {}",
                    msg.signature[45]
                );
                assert_eq!(
                    msg.signature[46], 46,
                    "incorrect value for signature[46], expected 46, is {}",
                    msg.signature[46]
                );
                assert_eq!(
                    msg.signature[47], 47,
                    "incorrect value for signature[47], expected 47, is {}",
                    msg.signature[47]
                );
                assert_eq!(
                    msg.signature[48], 48,
                    "incorrect value for signature[48], expected 48, is {}",
                    msg.signature[48]
                );
                assert_eq!(
                    msg.signature[49], 49,
                    "incorrect value for signature[49], expected 49, is {}",
                    msg.signature[49]
                );
                assert_eq!(
                    msg.signature[50], 50,
                    "incorrect value for signature[50], expected 50, is {}",
                    msg.signature[50]
                );
                assert_eq!(
                    msg.signature[51], 51,
                    "incorrect value for signature[51], expected 51, is {}",
                    msg.signature[51]
                );
                assert_eq!(
                    msg.signature[52], 52,
                    "incorrect value for signature[52], expected 52, is {}",
                    msg.signature[52]
                );
                assert_eq!(
                    msg.signature[53], 53,
                    "incorrect value for signature[53], expected 53, is {}",
                    msg.signature[53]
                );
                assert_eq!(
                    msg.signature[54], 54,
                    "incorrect value for signature[54], expected 54, is {}",
                    msg.signature[54]
                );
                assert_eq!(
                    msg.signature[55], 55,
                    "incorrect value for signature[55], expected 55, is {}",
                    msg.signature[55]
                );
                assert_eq!(
                    msg.signature[56], 56,
                    "incorrect value for signature[56], expected 56, is {}",
                    msg.signature[56]
                );
                assert_eq!(
                    msg.signature[57], 57,
                    "incorrect value for signature[57], expected 57, is {}",
                    msg.signature[57]
                );
                assert_eq!(
                    msg.signature[58], 58,
                    "incorrect value for signature[58], expected 58, is {}",
                    msg.signature[58]
                );
                assert_eq!(
                    msg.signature[59], 59,
                    "incorrect value for signature[59], expected 59, is {}",
                    msg.signature[59]
                );
                assert_eq!(
                    msg.signature[60], 60,
                    "incorrect value for signature[60], expected 60, is {}",
                    msg.signature[60]
                );
                assert_eq!(
                    msg.signature[61], 61,
                    "incorrect value for signature[61], expected 61, is {}",
                    msg.signature[61]
                );
                assert_eq!(
                    msg.signature[62], 62,
                    "incorrect value for signature[62], expected 62, is {}",
                    msg.signature[62]
                );
                assert_eq!(
                    msg.signature[63], 63,
                    "incorrect value for signature[63], expected 63, is {}",
                    msg.signature[63]
                );
                assert_eq!(
                    msg.signature[64], 64,
                    "incorrect value for signature[64], expected 64, is {}",
                    msg.signature[64]
                );
                assert_eq!(
                    msg.signature[65], 65,
                    "incorrect value for signature[65], expected 65, is {}",
                    msg.signature[65]
                );
                assert_eq!(
                    msg.signature[66], 66,
                    "incorrect value for signature[66], expected 66, is {}",
                    msg.signature[66]
                );
                assert_eq!(
                    msg.signature[67], 67,
                    "incorrect value for signature[67], expected 67, is {}",
                    msg.signature[67]
                );
                assert_eq!(
                    msg.signature[68], 68,
                    "incorrect value for signature[68], expected 68, is {}",
                    msg.signature[68]
                );
                assert_eq!(
                    msg.signature[69], 69,
                    "incorrect value for signature[69], expected 69, is {}",
                    msg.signature[69]
                );
                assert_eq!(
                    msg.signature[70], 70,
                    "incorrect value for signature[70], expected 70, is {}",
                    msg.signature[70]
                );
                assert_eq!(
                    msg.signature[71], 71,
                    "incorrect value for signature[71], expected 71, is {}",
                    msg.signature[71]
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
            _ => panic!("Invalid message type! Expected a MsgEcdsaSignatureDepB"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
