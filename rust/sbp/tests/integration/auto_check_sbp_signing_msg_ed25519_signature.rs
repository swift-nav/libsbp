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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEd25519Signature.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_signing_msg_ed25519_signature() {
    {
        let mut payload = Cursor::new(vec![
            85, 1, 12, 148, 38, 184, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
            18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
            40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,
            62, 63, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115,
            116, 117, 118, 119, 136, 19, 0, 0, 114, 20, 0, 0, 92, 21, 0, 0, 70, 22, 0, 0, 48, 23,
            0, 0, 26, 24, 0, 0, 4, 25, 0, 0, 238, 25, 0, 0, 216, 26, 0, 0, 194, 27, 0, 0, 172, 28,
            0, 0, 150, 29, 0, 0, 128, 30, 0, 0, 106, 31, 0, 0, 84, 32, 0, 0, 62, 33, 0, 0, 40, 34,
            0, 0, 18, 35, 0, 0, 252, 35, 0, 0, 230, 36, 0, 0, 208, 37, 0, 0, 186, 38, 0, 0, 164,
            39, 0, 0, 142, 40, 0, 0, 120, 41, 0, 0, 188, 56,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgEd25519Signature(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xC01,
                    "Incorrect message type, expected 0xC01, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2694,
                    "incorrect sender id, expected 0x2694, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.fingerprint[0], 100,
                    "incorrect value for fingerprint[0], expected 100, is {}",
                    msg.fingerprint[0]
                );
                assert_eq!(
                    msg.fingerprint[1], 101,
                    "incorrect value for fingerprint[1], expected 101, is {}",
                    msg.fingerprint[1]
                );
                assert_eq!(
                    msg.fingerprint[2], 102,
                    "incorrect value for fingerprint[2], expected 102, is {}",
                    msg.fingerprint[2]
                );
                assert_eq!(
                    msg.fingerprint[3], 103,
                    "incorrect value for fingerprint[3], expected 103, is {}",
                    msg.fingerprint[3]
                );
                assert_eq!(
                    msg.fingerprint[4], 104,
                    "incorrect value for fingerprint[4], expected 104, is {}",
                    msg.fingerprint[4]
                );
                assert_eq!(
                    msg.fingerprint[5], 105,
                    "incorrect value for fingerprint[5], expected 105, is {}",
                    msg.fingerprint[5]
                );
                assert_eq!(
                    msg.fingerprint[6], 106,
                    "incorrect value for fingerprint[6], expected 106, is {}",
                    msg.fingerprint[6]
                );
                assert_eq!(
                    msg.fingerprint[7], 107,
                    "incorrect value for fingerprint[7], expected 107, is {}",
                    msg.fingerprint[7]
                );
                assert_eq!(
                    msg.fingerprint[8], 108,
                    "incorrect value for fingerprint[8], expected 108, is {}",
                    msg.fingerprint[8]
                );
                assert_eq!(
                    msg.fingerprint[9], 109,
                    "incorrect value for fingerprint[9], expected 109, is {}",
                    msg.fingerprint[9]
                );
                assert_eq!(
                    msg.fingerprint[10], 110,
                    "incorrect value for fingerprint[10], expected 110, is {}",
                    msg.fingerprint[10]
                );
                assert_eq!(
                    msg.fingerprint[11], 111,
                    "incorrect value for fingerprint[11], expected 111, is {}",
                    msg.fingerprint[11]
                );
                assert_eq!(
                    msg.fingerprint[12], 112,
                    "incorrect value for fingerprint[12], expected 112, is {}",
                    msg.fingerprint[12]
                );
                assert_eq!(
                    msg.fingerprint[13], 113,
                    "incorrect value for fingerprint[13], expected 113, is {}",
                    msg.fingerprint[13]
                );
                assert_eq!(
                    msg.fingerprint[14], 114,
                    "incorrect value for fingerprint[14], expected 114, is {}",
                    msg.fingerprint[14]
                );
                assert_eq!(
                    msg.fingerprint[15], 115,
                    "incorrect value for fingerprint[15], expected 115, is {}",
                    msg.fingerprint[15]
                );
                assert_eq!(
                    msg.fingerprint[16], 116,
                    "incorrect value for fingerprint[16], expected 116, is {}",
                    msg.fingerprint[16]
                );
                assert_eq!(
                    msg.fingerprint[17], 117,
                    "incorrect value for fingerprint[17], expected 117, is {}",
                    msg.fingerprint[17]
                );
                assert_eq!(
                    msg.fingerprint[18], 118,
                    "incorrect value for fingerprint[18], expected 118, is {}",
                    msg.fingerprint[18]
                );
                assert_eq!(
                    msg.fingerprint[19], 119,
                    "incorrect value for fingerprint[19], expected 119, is {}",
                    msg.fingerprint[19]
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
                    msg.signed_messages[0], 5000,
                    "incorrect value for signed_messages[0], expected 5000, is {}",
                    msg.signed_messages[0]
                );
                assert_eq!(
                    msg.signed_messages[1], 5234,
                    "incorrect value for signed_messages[1], expected 5234, is {}",
                    msg.signed_messages[1]
                );
                assert_eq!(
                    msg.signed_messages[2], 5468,
                    "incorrect value for signed_messages[2], expected 5468, is {}",
                    msg.signed_messages[2]
                );
                assert_eq!(
                    msg.signed_messages[3], 5702,
                    "incorrect value for signed_messages[3], expected 5702, is {}",
                    msg.signed_messages[3]
                );
                assert_eq!(
                    msg.signed_messages[4], 5936,
                    "incorrect value for signed_messages[4], expected 5936, is {}",
                    msg.signed_messages[4]
                );
                assert_eq!(
                    msg.signed_messages[5], 6170,
                    "incorrect value for signed_messages[5], expected 6170, is {}",
                    msg.signed_messages[5]
                );
                assert_eq!(
                    msg.signed_messages[6], 6404,
                    "incorrect value for signed_messages[6], expected 6404, is {}",
                    msg.signed_messages[6]
                );
                assert_eq!(
                    msg.signed_messages[7], 6638,
                    "incorrect value for signed_messages[7], expected 6638, is {}",
                    msg.signed_messages[7]
                );
                assert_eq!(
                    msg.signed_messages[8], 6872,
                    "incorrect value for signed_messages[8], expected 6872, is {}",
                    msg.signed_messages[8]
                );
                assert_eq!(
                    msg.signed_messages[9], 7106,
                    "incorrect value for signed_messages[9], expected 7106, is {}",
                    msg.signed_messages[9]
                );
                assert_eq!(
                    msg.signed_messages[10], 7340,
                    "incorrect value for signed_messages[10], expected 7340, is {}",
                    msg.signed_messages[10]
                );
                assert_eq!(
                    msg.signed_messages[11], 7574,
                    "incorrect value for signed_messages[11], expected 7574, is {}",
                    msg.signed_messages[11]
                );
                assert_eq!(
                    msg.signed_messages[12], 7808,
                    "incorrect value for signed_messages[12], expected 7808, is {}",
                    msg.signed_messages[12]
                );
                assert_eq!(
                    msg.signed_messages[13], 8042,
                    "incorrect value for signed_messages[13], expected 8042, is {}",
                    msg.signed_messages[13]
                );
                assert_eq!(
                    msg.signed_messages[14], 8276,
                    "incorrect value for signed_messages[14], expected 8276, is {}",
                    msg.signed_messages[14]
                );
                assert_eq!(
                    msg.signed_messages[15], 8510,
                    "incorrect value for signed_messages[15], expected 8510, is {}",
                    msg.signed_messages[15]
                );
                assert_eq!(
                    msg.signed_messages[16], 8744,
                    "incorrect value for signed_messages[16], expected 8744, is {}",
                    msg.signed_messages[16]
                );
                assert_eq!(
                    msg.signed_messages[17], 8978,
                    "incorrect value for signed_messages[17], expected 8978, is {}",
                    msg.signed_messages[17]
                );
                assert_eq!(
                    msg.signed_messages[18], 9212,
                    "incorrect value for signed_messages[18], expected 9212, is {}",
                    msg.signed_messages[18]
                );
                assert_eq!(
                    msg.signed_messages[19], 9446,
                    "incorrect value for signed_messages[19], expected 9446, is {}",
                    msg.signed_messages[19]
                );
                assert_eq!(
                    msg.signed_messages[20], 9680,
                    "incorrect value for signed_messages[20], expected 9680, is {}",
                    msg.signed_messages[20]
                );
                assert_eq!(
                    msg.signed_messages[21], 9914,
                    "incorrect value for signed_messages[21], expected 9914, is {}",
                    msg.signed_messages[21]
                );
                assert_eq!(
                    msg.signed_messages[22], 10148,
                    "incorrect value for signed_messages[22], expected 10148, is {}",
                    msg.signed_messages[22]
                );
                assert_eq!(
                    msg.signed_messages[23], 10382,
                    "incorrect value for signed_messages[23], expected 10382, is {}",
                    msg.signed_messages[23]
                );
                assert_eq!(
                    msg.signed_messages[24], 10616,
                    "incorrect value for signed_messages[24], expected 10616, is {}",
                    msg.signed_messages[24]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEd25519Signature"),
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
fn test_json2sbp_auto_check_sbp_signing_msg_ed25519_signature() {
    {
        let json_input = r#"{"preamble": 85, "msg_type": 3073, "sender": 9876, "length": 184, "payload": "AAECAwQFBgcICQoLDA0ODxAREhMUFRYXGBkaGxwdHh8gISIjJCUmJygpKissLS4vMDEyMzQ1Njc4OTo7PD0+P2RlZmdoaWprbG1ub3BxcnN0dXZ3iBMAAHIUAABcFQAARhYAADAXAAAaGAAABBkAAO4ZAADYGgAAwhsAAKwcAACWHQAAgB4AAGofAABUIAAAPiEAACgiAAASIwAA/CMAAOYkAADQJQAAuiYAAKQnAACOKAAAeCkAAA==", "crc": 14524, "signature": [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63], "fingerprint": [100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119], "signed_messages": [5000, 5234, 5468, 5702, 5936, 6170, 6404, 6638, 6872, 7106, 7340, 7574, 7808, 8042, 8276, 8510, 8744, 8978, 9212, 9446, 9680, 9914, 10148, 10382, 10616]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgEd25519Signature(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xC01,
                    "Incorrect message type, expected 0xC01, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2694,
                    "incorrect sender id, expected 0x2694, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.fingerprint[0], 100,
                    "incorrect value for fingerprint[0], expected 100, is {}",
                    msg.fingerprint[0]
                );
                assert_eq!(
                    msg.fingerprint[1], 101,
                    "incorrect value for fingerprint[1], expected 101, is {}",
                    msg.fingerprint[1]
                );
                assert_eq!(
                    msg.fingerprint[2], 102,
                    "incorrect value for fingerprint[2], expected 102, is {}",
                    msg.fingerprint[2]
                );
                assert_eq!(
                    msg.fingerprint[3], 103,
                    "incorrect value for fingerprint[3], expected 103, is {}",
                    msg.fingerprint[3]
                );
                assert_eq!(
                    msg.fingerprint[4], 104,
                    "incorrect value for fingerprint[4], expected 104, is {}",
                    msg.fingerprint[4]
                );
                assert_eq!(
                    msg.fingerprint[5], 105,
                    "incorrect value for fingerprint[5], expected 105, is {}",
                    msg.fingerprint[5]
                );
                assert_eq!(
                    msg.fingerprint[6], 106,
                    "incorrect value for fingerprint[6], expected 106, is {}",
                    msg.fingerprint[6]
                );
                assert_eq!(
                    msg.fingerprint[7], 107,
                    "incorrect value for fingerprint[7], expected 107, is {}",
                    msg.fingerprint[7]
                );
                assert_eq!(
                    msg.fingerprint[8], 108,
                    "incorrect value for fingerprint[8], expected 108, is {}",
                    msg.fingerprint[8]
                );
                assert_eq!(
                    msg.fingerprint[9], 109,
                    "incorrect value for fingerprint[9], expected 109, is {}",
                    msg.fingerprint[9]
                );
                assert_eq!(
                    msg.fingerprint[10], 110,
                    "incorrect value for fingerprint[10], expected 110, is {}",
                    msg.fingerprint[10]
                );
                assert_eq!(
                    msg.fingerprint[11], 111,
                    "incorrect value for fingerprint[11], expected 111, is {}",
                    msg.fingerprint[11]
                );
                assert_eq!(
                    msg.fingerprint[12], 112,
                    "incorrect value for fingerprint[12], expected 112, is {}",
                    msg.fingerprint[12]
                );
                assert_eq!(
                    msg.fingerprint[13], 113,
                    "incorrect value for fingerprint[13], expected 113, is {}",
                    msg.fingerprint[13]
                );
                assert_eq!(
                    msg.fingerprint[14], 114,
                    "incorrect value for fingerprint[14], expected 114, is {}",
                    msg.fingerprint[14]
                );
                assert_eq!(
                    msg.fingerprint[15], 115,
                    "incorrect value for fingerprint[15], expected 115, is {}",
                    msg.fingerprint[15]
                );
                assert_eq!(
                    msg.fingerprint[16], 116,
                    "incorrect value for fingerprint[16], expected 116, is {}",
                    msg.fingerprint[16]
                );
                assert_eq!(
                    msg.fingerprint[17], 117,
                    "incorrect value for fingerprint[17], expected 117, is {}",
                    msg.fingerprint[17]
                );
                assert_eq!(
                    msg.fingerprint[18], 118,
                    "incorrect value for fingerprint[18], expected 118, is {}",
                    msg.fingerprint[18]
                );
                assert_eq!(
                    msg.fingerprint[19], 119,
                    "incorrect value for fingerprint[19], expected 119, is {}",
                    msg.fingerprint[19]
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
                    msg.signed_messages[0], 5000,
                    "incorrect value for signed_messages[0], expected 5000, is {}",
                    msg.signed_messages[0]
                );
                assert_eq!(
                    msg.signed_messages[1], 5234,
                    "incorrect value for signed_messages[1], expected 5234, is {}",
                    msg.signed_messages[1]
                );
                assert_eq!(
                    msg.signed_messages[2], 5468,
                    "incorrect value for signed_messages[2], expected 5468, is {}",
                    msg.signed_messages[2]
                );
                assert_eq!(
                    msg.signed_messages[3], 5702,
                    "incorrect value for signed_messages[3], expected 5702, is {}",
                    msg.signed_messages[3]
                );
                assert_eq!(
                    msg.signed_messages[4], 5936,
                    "incorrect value for signed_messages[4], expected 5936, is {}",
                    msg.signed_messages[4]
                );
                assert_eq!(
                    msg.signed_messages[5], 6170,
                    "incorrect value for signed_messages[5], expected 6170, is {}",
                    msg.signed_messages[5]
                );
                assert_eq!(
                    msg.signed_messages[6], 6404,
                    "incorrect value for signed_messages[6], expected 6404, is {}",
                    msg.signed_messages[6]
                );
                assert_eq!(
                    msg.signed_messages[7], 6638,
                    "incorrect value for signed_messages[7], expected 6638, is {}",
                    msg.signed_messages[7]
                );
                assert_eq!(
                    msg.signed_messages[8], 6872,
                    "incorrect value for signed_messages[8], expected 6872, is {}",
                    msg.signed_messages[8]
                );
                assert_eq!(
                    msg.signed_messages[9], 7106,
                    "incorrect value for signed_messages[9], expected 7106, is {}",
                    msg.signed_messages[9]
                );
                assert_eq!(
                    msg.signed_messages[10], 7340,
                    "incorrect value for signed_messages[10], expected 7340, is {}",
                    msg.signed_messages[10]
                );
                assert_eq!(
                    msg.signed_messages[11], 7574,
                    "incorrect value for signed_messages[11], expected 7574, is {}",
                    msg.signed_messages[11]
                );
                assert_eq!(
                    msg.signed_messages[12], 7808,
                    "incorrect value for signed_messages[12], expected 7808, is {}",
                    msg.signed_messages[12]
                );
                assert_eq!(
                    msg.signed_messages[13], 8042,
                    "incorrect value for signed_messages[13], expected 8042, is {}",
                    msg.signed_messages[13]
                );
                assert_eq!(
                    msg.signed_messages[14], 8276,
                    "incorrect value for signed_messages[14], expected 8276, is {}",
                    msg.signed_messages[14]
                );
                assert_eq!(
                    msg.signed_messages[15], 8510,
                    "incorrect value for signed_messages[15], expected 8510, is {}",
                    msg.signed_messages[15]
                );
                assert_eq!(
                    msg.signed_messages[16], 8744,
                    "incorrect value for signed_messages[16], expected 8744, is {}",
                    msg.signed_messages[16]
                );
                assert_eq!(
                    msg.signed_messages[17], 8978,
                    "incorrect value for signed_messages[17], expected 8978, is {}",
                    msg.signed_messages[17]
                );
                assert_eq!(
                    msg.signed_messages[18], 9212,
                    "incorrect value for signed_messages[18], expected 9212, is {}",
                    msg.signed_messages[18]
                );
                assert_eq!(
                    msg.signed_messages[19], 9446,
                    "incorrect value for signed_messages[19], expected 9446, is {}",
                    msg.signed_messages[19]
                );
                assert_eq!(
                    msg.signed_messages[20], 9680,
                    "incorrect value for signed_messages[20], expected 9680, is {}",
                    msg.signed_messages[20]
                );
                assert_eq!(
                    msg.signed_messages[21], 9914,
                    "incorrect value for signed_messages[21], expected 9914, is {}",
                    msg.signed_messages[21]
                );
                assert_eq!(
                    msg.signed_messages[22], 10148,
                    "incorrect value for signed_messages[22], expected 10148, is {}",
                    msg.signed_messages[22]
                );
                assert_eq!(
                    msg.signed_messages[23], 10382,
                    "incorrect value for signed_messages[23], expected 10382, is {}",
                    msg.signed_messages[23]
                );
                assert_eq!(
                    msg.signed_messages[24], 10616,
                    "incorrect value for signed_messages[24], expected 10616, is {}",
                    msg.signed_messages[24]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEd25519Signature"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_signing_msg_ed25519_signature`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_signing_msg_ed25519_signature() {
    {
        let mut payload = Cursor::new(vec![
            85, 1, 12, 148, 38, 184, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
            18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
            40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,
            62, 63, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115,
            116, 117, 118, 119, 136, 19, 0, 0, 114, 20, 0, 0, 92, 21, 0, 0, 70, 22, 0, 0, 48, 23,
            0, 0, 26, 24, 0, 0, 4, 25, 0, 0, 238, 25, 0, 0, 216, 26, 0, 0, 194, 27, 0, 0, 172, 28,
            0, 0, 150, 29, 0, 0, 128, 30, 0, 0, 106, 31, 0, 0, 84, 32, 0, 0, 62, 33, 0, 0, 40, 34,
            0, 0, 18, 35, 0, 0, 252, 35, 0, 0, 230, 36, 0, 0, 208, 37, 0, 0, 186, 38, 0, 0, 164,
            39, 0, 0, 142, 40, 0, 0, 120, 41, 0, 0, 188, 56,
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
        let sbp_msg = sbp::messages::Sbp::MsgEd25519Signature(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgEd25519Signature(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xC01,
                    "Incorrect message type, expected 0xC01, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2694,
                    "incorrect sender id, expected 0x2694, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.fingerprint[0], 100,
                    "incorrect value for fingerprint[0], expected 100, is {}",
                    msg.fingerprint[0]
                );
                assert_eq!(
                    msg.fingerprint[1], 101,
                    "incorrect value for fingerprint[1], expected 101, is {}",
                    msg.fingerprint[1]
                );
                assert_eq!(
                    msg.fingerprint[2], 102,
                    "incorrect value for fingerprint[2], expected 102, is {}",
                    msg.fingerprint[2]
                );
                assert_eq!(
                    msg.fingerprint[3], 103,
                    "incorrect value for fingerprint[3], expected 103, is {}",
                    msg.fingerprint[3]
                );
                assert_eq!(
                    msg.fingerprint[4], 104,
                    "incorrect value for fingerprint[4], expected 104, is {}",
                    msg.fingerprint[4]
                );
                assert_eq!(
                    msg.fingerprint[5], 105,
                    "incorrect value for fingerprint[5], expected 105, is {}",
                    msg.fingerprint[5]
                );
                assert_eq!(
                    msg.fingerprint[6], 106,
                    "incorrect value for fingerprint[6], expected 106, is {}",
                    msg.fingerprint[6]
                );
                assert_eq!(
                    msg.fingerprint[7], 107,
                    "incorrect value for fingerprint[7], expected 107, is {}",
                    msg.fingerprint[7]
                );
                assert_eq!(
                    msg.fingerprint[8], 108,
                    "incorrect value for fingerprint[8], expected 108, is {}",
                    msg.fingerprint[8]
                );
                assert_eq!(
                    msg.fingerprint[9], 109,
                    "incorrect value for fingerprint[9], expected 109, is {}",
                    msg.fingerprint[9]
                );
                assert_eq!(
                    msg.fingerprint[10], 110,
                    "incorrect value for fingerprint[10], expected 110, is {}",
                    msg.fingerprint[10]
                );
                assert_eq!(
                    msg.fingerprint[11], 111,
                    "incorrect value for fingerprint[11], expected 111, is {}",
                    msg.fingerprint[11]
                );
                assert_eq!(
                    msg.fingerprint[12], 112,
                    "incorrect value for fingerprint[12], expected 112, is {}",
                    msg.fingerprint[12]
                );
                assert_eq!(
                    msg.fingerprint[13], 113,
                    "incorrect value for fingerprint[13], expected 113, is {}",
                    msg.fingerprint[13]
                );
                assert_eq!(
                    msg.fingerprint[14], 114,
                    "incorrect value for fingerprint[14], expected 114, is {}",
                    msg.fingerprint[14]
                );
                assert_eq!(
                    msg.fingerprint[15], 115,
                    "incorrect value for fingerprint[15], expected 115, is {}",
                    msg.fingerprint[15]
                );
                assert_eq!(
                    msg.fingerprint[16], 116,
                    "incorrect value for fingerprint[16], expected 116, is {}",
                    msg.fingerprint[16]
                );
                assert_eq!(
                    msg.fingerprint[17], 117,
                    "incorrect value for fingerprint[17], expected 117, is {}",
                    msg.fingerprint[17]
                );
                assert_eq!(
                    msg.fingerprint[18], 118,
                    "incorrect value for fingerprint[18], expected 118, is {}",
                    msg.fingerprint[18]
                );
                assert_eq!(
                    msg.fingerprint[19], 119,
                    "incorrect value for fingerprint[19], expected 119, is {}",
                    msg.fingerprint[19]
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
                    msg.signed_messages[0], 5000,
                    "incorrect value for signed_messages[0], expected 5000, is {}",
                    msg.signed_messages[0]
                );
                assert_eq!(
                    msg.signed_messages[1], 5234,
                    "incorrect value for signed_messages[1], expected 5234, is {}",
                    msg.signed_messages[1]
                );
                assert_eq!(
                    msg.signed_messages[2], 5468,
                    "incorrect value for signed_messages[2], expected 5468, is {}",
                    msg.signed_messages[2]
                );
                assert_eq!(
                    msg.signed_messages[3], 5702,
                    "incorrect value for signed_messages[3], expected 5702, is {}",
                    msg.signed_messages[3]
                );
                assert_eq!(
                    msg.signed_messages[4], 5936,
                    "incorrect value for signed_messages[4], expected 5936, is {}",
                    msg.signed_messages[4]
                );
                assert_eq!(
                    msg.signed_messages[5], 6170,
                    "incorrect value for signed_messages[5], expected 6170, is {}",
                    msg.signed_messages[5]
                );
                assert_eq!(
                    msg.signed_messages[6], 6404,
                    "incorrect value for signed_messages[6], expected 6404, is {}",
                    msg.signed_messages[6]
                );
                assert_eq!(
                    msg.signed_messages[7], 6638,
                    "incorrect value for signed_messages[7], expected 6638, is {}",
                    msg.signed_messages[7]
                );
                assert_eq!(
                    msg.signed_messages[8], 6872,
                    "incorrect value for signed_messages[8], expected 6872, is {}",
                    msg.signed_messages[8]
                );
                assert_eq!(
                    msg.signed_messages[9], 7106,
                    "incorrect value for signed_messages[9], expected 7106, is {}",
                    msg.signed_messages[9]
                );
                assert_eq!(
                    msg.signed_messages[10], 7340,
                    "incorrect value for signed_messages[10], expected 7340, is {}",
                    msg.signed_messages[10]
                );
                assert_eq!(
                    msg.signed_messages[11], 7574,
                    "incorrect value for signed_messages[11], expected 7574, is {}",
                    msg.signed_messages[11]
                );
                assert_eq!(
                    msg.signed_messages[12], 7808,
                    "incorrect value for signed_messages[12], expected 7808, is {}",
                    msg.signed_messages[12]
                );
                assert_eq!(
                    msg.signed_messages[13], 8042,
                    "incorrect value for signed_messages[13], expected 8042, is {}",
                    msg.signed_messages[13]
                );
                assert_eq!(
                    msg.signed_messages[14], 8276,
                    "incorrect value for signed_messages[14], expected 8276, is {}",
                    msg.signed_messages[14]
                );
                assert_eq!(
                    msg.signed_messages[15], 8510,
                    "incorrect value for signed_messages[15], expected 8510, is {}",
                    msg.signed_messages[15]
                );
                assert_eq!(
                    msg.signed_messages[16], 8744,
                    "incorrect value for signed_messages[16], expected 8744, is {}",
                    msg.signed_messages[16]
                );
                assert_eq!(
                    msg.signed_messages[17], 8978,
                    "incorrect value for signed_messages[17], expected 8978, is {}",
                    msg.signed_messages[17]
                );
                assert_eq!(
                    msg.signed_messages[18], 9212,
                    "incorrect value for signed_messages[18], expected 9212, is {}",
                    msg.signed_messages[18]
                );
                assert_eq!(
                    msg.signed_messages[19], 9446,
                    "incorrect value for signed_messages[19], expected 9446, is {}",
                    msg.signed_messages[19]
                );
                assert_eq!(
                    msg.signed_messages[20], 9680,
                    "incorrect value for signed_messages[20], expected 9680, is {}",
                    msg.signed_messages[20]
                );
                assert_eq!(
                    msg.signed_messages[21], 9914,
                    "incorrect value for signed_messages[21], expected 9914, is {}",
                    msg.signed_messages[21]
                );
                assert_eq!(
                    msg.signed_messages[22], 10148,
                    "incorrect value for signed_messages[22], expected 10148, is {}",
                    msg.signed_messages[22]
                );
                assert_eq!(
                    msg.signed_messages[23], 10382,
                    "incorrect value for signed_messages[23], expected 10382, is {}",
                    msg.signed_messages[23]
                );
                assert_eq!(
                    msg.signed_messages[24], 10616,
                    "incorrect value for signed_messages[24], expected 10616, is {}",
                    msg.signed_messages[24]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEd25519Signature"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
