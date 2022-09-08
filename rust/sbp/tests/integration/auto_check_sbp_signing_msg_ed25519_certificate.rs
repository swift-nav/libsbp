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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEd25519Certificate.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_signing_msg_ed25519_certificate() {
    {
        let mut payload = Cursor::new(vec![
            85, 2, 12, 66, 0, 106, 16, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
            112, 113, 114, 115, 116, 117, 118, 119, 0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36,
            39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81, 84, 87, 90, 93, 96, 99,
            102, 105, 108, 111, 114, 117, 120, 123, 126, 129, 132, 135, 138, 141, 144, 147, 150,
            153, 156, 159, 162, 165, 168, 171, 174, 177, 180, 183, 186, 189, 192, 195, 198, 201,
            204, 207, 210, 213, 216, 219, 222, 225, 228, 231, 234, 237, 240, 243, 246, 249, 252,
            218, 148,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgEd25519Certificate(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xC02,
                    "Incorrect message type, expected 0xC02, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.certificate_bytes[0], 0,
                    "incorrect value for certificate_bytes[0], expected 0, is {}",
                    msg.certificate_bytes[0]
                );
                assert_eq!(
                    msg.certificate_bytes[1], 3,
                    "incorrect value for certificate_bytes[1], expected 3, is {}",
                    msg.certificate_bytes[1]
                );
                assert_eq!(
                    msg.certificate_bytes[2], 6,
                    "incorrect value for certificate_bytes[2], expected 6, is {}",
                    msg.certificate_bytes[2]
                );
                assert_eq!(
                    msg.certificate_bytes[3], 9,
                    "incorrect value for certificate_bytes[3], expected 9, is {}",
                    msg.certificate_bytes[3]
                );
                assert_eq!(
                    msg.certificate_bytes[4], 12,
                    "incorrect value for certificate_bytes[4], expected 12, is {}",
                    msg.certificate_bytes[4]
                );
                assert_eq!(
                    msg.certificate_bytes[5], 15,
                    "incorrect value for certificate_bytes[5], expected 15, is {}",
                    msg.certificate_bytes[5]
                );
                assert_eq!(
                    msg.certificate_bytes[6], 18,
                    "incorrect value for certificate_bytes[6], expected 18, is {}",
                    msg.certificate_bytes[6]
                );
                assert_eq!(
                    msg.certificate_bytes[7], 21,
                    "incorrect value for certificate_bytes[7], expected 21, is {}",
                    msg.certificate_bytes[7]
                );
                assert_eq!(
                    msg.certificate_bytes[8], 24,
                    "incorrect value for certificate_bytes[8], expected 24, is {}",
                    msg.certificate_bytes[8]
                );
                assert_eq!(
                    msg.certificate_bytes[9], 27,
                    "incorrect value for certificate_bytes[9], expected 27, is {}",
                    msg.certificate_bytes[9]
                );
                assert_eq!(
                    msg.certificate_bytes[10], 30,
                    "incorrect value for certificate_bytes[10], expected 30, is {}",
                    msg.certificate_bytes[10]
                );
                assert_eq!(
                    msg.certificate_bytes[11], 33,
                    "incorrect value for certificate_bytes[11], expected 33, is {}",
                    msg.certificate_bytes[11]
                );
                assert_eq!(
                    msg.certificate_bytes[12], 36,
                    "incorrect value for certificate_bytes[12], expected 36, is {}",
                    msg.certificate_bytes[12]
                );
                assert_eq!(
                    msg.certificate_bytes[13], 39,
                    "incorrect value for certificate_bytes[13], expected 39, is {}",
                    msg.certificate_bytes[13]
                );
                assert_eq!(
                    msg.certificate_bytes[14], 42,
                    "incorrect value for certificate_bytes[14], expected 42, is {}",
                    msg.certificate_bytes[14]
                );
                assert_eq!(
                    msg.certificate_bytes[15], 45,
                    "incorrect value for certificate_bytes[15], expected 45, is {}",
                    msg.certificate_bytes[15]
                );
                assert_eq!(
                    msg.certificate_bytes[16], 48,
                    "incorrect value for certificate_bytes[16], expected 48, is {}",
                    msg.certificate_bytes[16]
                );
                assert_eq!(
                    msg.certificate_bytes[17], 51,
                    "incorrect value for certificate_bytes[17], expected 51, is {}",
                    msg.certificate_bytes[17]
                );
                assert_eq!(
                    msg.certificate_bytes[18], 54,
                    "incorrect value for certificate_bytes[18], expected 54, is {}",
                    msg.certificate_bytes[18]
                );
                assert_eq!(
                    msg.certificate_bytes[19], 57,
                    "incorrect value for certificate_bytes[19], expected 57, is {}",
                    msg.certificate_bytes[19]
                );
                assert_eq!(
                    msg.certificate_bytes[20], 60,
                    "incorrect value for certificate_bytes[20], expected 60, is {}",
                    msg.certificate_bytes[20]
                );
                assert_eq!(
                    msg.certificate_bytes[21], 63,
                    "incorrect value for certificate_bytes[21], expected 63, is {}",
                    msg.certificate_bytes[21]
                );
                assert_eq!(
                    msg.certificate_bytes[22], 66,
                    "incorrect value for certificate_bytes[22], expected 66, is {}",
                    msg.certificate_bytes[22]
                );
                assert_eq!(
                    msg.certificate_bytes[23], 69,
                    "incorrect value for certificate_bytes[23], expected 69, is {}",
                    msg.certificate_bytes[23]
                );
                assert_eq!(
                    msg.certificate_bytes[24], 72,
                    "incorrect value for certificate_bytes[24], expected 72, is {}",
                    msg.certificate_bytes[24]
                );
                assert_eq!(
                    msg.certificate_bytes[25], 75,
                    "incorrect value for certificate_bytes[25], expected 75, is {}",
                    msg.certificate_bytes[25]
                );
                assert_eq!(
                    msg.certificate_bytes[26], 78,
                    "incorrect value for certificate_bytes[26], expected 78, is {}",
                    msg.certificate_bytes[26]
                );
                assert_eq!(
                    msg.certificate_bytes[27], 81,
                    "incorrect value for certificate_bytes[27], expected 81, is {}",
                    msg.certificate_bytes[27]
                );
                assert_eq!(
                    msg.certificate_bytes[28], 84,
                    "incorrect value for certificate_bytes[28], expected 84, is {}",
                    msg.certificate_bytes[28]
                );
                assert_eq!(
                    msg.certificate_bytes[29], 87,
                    "incorrect value for certificate_bytes[29], expected 87, is {}",
                    msg.certificate_bytes[29]
                );
                assert_eq!(
                    msg.certificate_bytes[30], 90,
                    "incorrect value for certificate_bytes[30], expected 90, is {}",
                    msg.certificate_bytes[30]
                );
                assert_eq!(
                    msg.certificate_bytes[31], 93,
                    "incorrect value for certificate_bytes[31], expected 93, is {}",
                    msg.certificate_bytes[31]
                );
                assert_eq!(
                    msg.certificate_bytes[32], 96,
                    "incorrect value for certificate_bytes[32], expected 96, is {}",
                    msg.certificate_bytes[32]
                );
                assert_eq!(
                    msg.certificate_bytes[33], 99,
                    "incorrect value for certificate_bytes[33], expected 99, is {}",
                    msg.certificate_bytes[33]
                );
                assert_eq!(
                    msg.certificate_bytes[34], 102,
                    "incorrect value for certificate_bytes[34], expected 102, is {}",
                    msg.certificate_bytes[34]
                );
                assert_eq!(
                    msg.certificate_bytes[35], 105,
                    "incorrect value for certificate_bytes[35], expected 105, is {}",
                    msg.certificate_bytes[35]
                );
                assert_eq!(
                    msg.certificate_bytes[36], 108,
                    "incorrect value for certificate_bytes[36], expected 108, is {}",
                    msg.certificate_bytes[36]
                );
                assert_eq!(
                    msg.certificate_bytes[37], 111,
                    "incorrect value for certificate_bytes[37], expected 111, is {}",
                    msg.certificate_bytes[37]
                );
                assert_eq!(
                    msg.certificate_bytes[38], 114,
                    "incorrect value for certificate_bytes[38], expected 114, is {}",
                    msg.certificate_bytes[38]
                );
                assert_eq!(
                    msg.certificate_bytes[39], 117,
                    "incorrect value for certificate_bytes[39], expected 117, is {}",
                    msg.certificate_bytes[39]
                );
                assert_eq!(
                    msg.certificate_bytes[40], 120,
                    "incorrect value for certificate_bytes[40], expected 120, is {}",
                    msg.certificate_bytes[40]
                );
                assert_eq!(
                    msg.certificate_bytes[41], 123,
                    "incorrect value for certificate_bytes[41], expected 123, is {}",
                    msg.certificate_bytes[41]
                );
                assert_eq!(
                    msg.certificate_bytes[42], 126,
                    "incorrect value for certificate_bytes[42], expected 126, is {}",
                    msg.certificate_bytes[42]
                );
                assert_eq!(
                    msg.certificate_bytes[43], 129,
                    "incorrect value for certificate_bytes[43], expected 129, is {}",
                    msg.certificate_bytes[43]
                );
                assert_eq!(
                    msg.certificate_bytes[44], 132,
                    "incorrect value for certificate_bytes[44], expected 132, is {}",
                    msg.certificate_bytes[44]
                );
                assert_eq!(
                    msg.certificate_bytes[45], 135,
                    "incorrect value for certificate_bytes[45], expected 135, is {}",
                    msg.certificate_bytes[45]
                );
                assert_eq!(
                    msg.certificate_bytes[46], 138,
                    "incorrect value for certificate_bytes[46], expected 138, is {}",
                    msg.certificate_bytes[46]
                );
                assert_eq!(
                    msg.certificate_bytes[47], 141,
                    "incorrect value for certificate_bytes[47], expected 141, is {}",
                    msg.certificate_bytes[47]
                );
                assert_eq!(
                    msg.certificate_bytes[48], 144,
                    "incorrect value for certificate_bytes[48], expected 144, is {}",
                    msg.certificate_bytes[48]
                );
                assert_eq!(
                    msg.certificate_bytes[49], 147,
                    "incorrect value for certificate_bytes[49], expected 147, is {}",
                    msg.certificate_bytes[49]
                );
                assert_eq!(
                    msg.certificate_bytes[50], 150,
                    "incorrect value for certificate_bytes[50], expected 150, is {}",
                    msg.certificate_bytes[50]
                );
                assert_eq!(
                    msg.certificate_bytes[51], 153,
                    "incorrect value for certificate_bytes[51], expected 153, is {}",
                    msg.certificate_bytes[51]
                );
                assert_eq!(
                    msg.certificate_bytes[52], 156,
                    "incorrect value for certificate_bytes[52], expected 156, is {}",
                    msg.certificate_bytes[52]
                );
                assert_eq!(
                    msg.certificate_bytes[53], 159,
                    "incorrect value for certificate_bytes[53], expected 159, is {}",
                    msg.certificate_bytes[53]
                );
                assert_eq!(
                    msg.certificate_bytes[54], 162,
                    "incorrect value for certificate_bytes[54], expected 162, is {}",
                    msg.certificate_bytes[54]
                );
                assert_eq!(
                    msg.certificate_bytes[55], 165,
                    "incorrect value for certificate_bytes[55], expected 165, is {}",
                    msg.certificate_bytes[55]
                );
                assert_eq!(
                    msg.certificate_bytes[56], 168,
                    "incorrect value for certificate_bytes[56], expected 168, is {}",
                    msg.certificate_bytes[56]
                );
                assert_eq!(
                    msg.certificate_bytes[57], 171,
                    "incorrect value for certificate_bytes[57], expected 171, is {}",
                    msg.certificate_bytes[57]
                );
                assert_eq!(
                    msg.certificate_bytes[58], 174,
                    "incorrect value for certificate_bytes[58], expected 174, is {}",
                    msg.certificate_bytes[58]
                );
                assert_eq!(
                    msg.certificate_bytes[59], 177,
                    "incorrect value for certificate_bytes[59], expected 177, is {}",
                    msg.certificate_bytes[59]
                );
                assert_eq!(
                    msg.certificate_bytes[60], 180,
                    "incorrect value for certificate_bytes[60], expected 180, is {}",
                    msg.certificate_bytes[60]
                );
                assert_eq!(
                    msg.certificate_bytes[61], 183,
                    "incorrect value for certificate_bytes[61], expected 183, is {}",
                    msg.certificate_bytes[61]
                );
                assert_eq!(
                    msg.certificate_bytes[62], 186,
                    "incorrect value for certificate_bytes[62], expected 186, is {}",
                    msg.certificate_bytes[62]
                );
                assert_eq!(
                    msg.certificate_bytes[63], 189,
                    "incorrect value for certificate_bytes[63], expected 189, is {}",
                    msg.certificate_bytes[63]
                );
                assert_eq!(
                    msg.certificate_bytes[64], 192,
                    "incorrect value for certificate_bytes[64], expected 192, is {}",
                    msg.certificate_bytes[64]
                );
                assert_eq!(
                    msg.certificate_bytes[65], 195,
                    "incorrect value for certificate_bytes[65], expected 195, is {}",
                    msg.certificate_bytes[65]
                );
                assert_eq!(
                    msg.certificate_bytes[66], 198,
                    "incorrect value for certificate_bytes[66], expected 198, is {}",
                    msg.certificate_bytes[66]
                );
                assert_eq!(
                    msg.certificate_bytes[67], 201,
                    "incorrect value for certificate_bytes[67], expected 201, is {}",
                    msg.certificate_bytes[67]
                );
                assert_eq!(
                    msg.certificate_bytes[68], 204,
                    "incorrect value for certificate_bytes[68], expected 204, is {}",
                    msg.certificate_bytes[68]
                );
                assert_eq!(
                    msg.certificate_bytes[69], 207,
                    "incorrect value for certificate_bytes[69], expected 207, is {}",
                    msg.certificate_bytes[69]
                );
                assert_eq!(
                    msg.certificate_bytes[70], 210,
                    "incorrect value for certificate_bytes[70], expected 210, is {}",
                    msg.certificate_bytes[70]
                );
                assert_eq!(
                    msg.certificate_bytes[71], 213,
                    "incorrect value for certificate_bytes[71], expected 213, is {}",
                    msg.certificate_bytes[71]
                );
                assert_eq!(
                    msg.certificate_bytes[72], 216,
                    "incorrect value for certificate_bytes[72], expected 216, is {}",
                    msg.certificate_bytes[72]
                );
                assert_eq!(
                    msg.certificate_bytes[73], 219,
                    "incorrect value for certificate_bytes[73], expected 219, is {}",
                    msg.certificate_bytes[73]
                );
                assert_eq!(
                    msg.certificate_bytes[74], 222,
                    "incorrect value for certificate_bytes[74], expected 222, is {}",
                    msg.certificate_bytes[74]
                );
                assert_eq!(
                    msg.certificate_bytes[75], 225,
                    "incorrect value for certificate_bytes[75], expected 225, is {}",
                    msg.certificate_bytes[75]
                );
                assert_eq!(
                    msg.certificate_bytes[76], 228,
                    "incorrect value for certificate_bytes[76], expected 228, is {}",
                    msg.certificate_bytes[76]
                );
                assert_eq!(
                    msg.certificate_bytes[77], 231,
                    "incorrect value for certificate_bytes[77], expected 231, is {}",
                    msg.certificate_bytes[77]
                );
                assert_eq!(
                    msg.certificate_bytes[78], 234,
                    "incorrect value for certificate_bytes[78], expected 234, is {}",
                    msg.certificate_bytes[78]
                );
                assert_eq!(
                    msg.certificate_bytes[79], 237,
                    "incorrect value for certificate_bytes[79], expected 237, is {}",
                    msg.certificate_bytes[79]
                );
                assert_eq!(
                    msg.certificate_bytes[80], 240,
                    "incorrect value for certificate_bytes[80], expected 240, is {}",
                    msg.certificate_bytes[80]
                );
                assert_eq!(
                    msg.certificate_bytes[81], 243,
                    "incorrect value for certificate_bytes[81], expected 243, is {}",
                    msg.certificate_bytes[81]
                );
                assert_eq!(
                    msg.certificate_bytes[82], 246,
                    "incorrect value for certificate_bytes[82], expected 246, is {}",
                    msg.certificate_bytes[82]
                );
                assert_eq!(
                    msg.certificate_bytes[83], 249,
                    "incorrect value for certificate_bytes[83], expected 249, is {}",
                    msg.certificate_bytes[83]
                );
                assert_eq!(
                    msg.certificate_bytes[84], 252,
                    "incorrect value for certificate_bytes[84], expected 252, is {}",
                    msg.certificate_bytes[84]
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
                    msg.n_msg, 16,
                    "incorrect value for n_msg, expected 16, is {}",
                    msg.n_msg
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEd25519Certificate"),
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
fn test_json2sbp_auto_check_sbp_signing_msg_ed25519_certificate() {
    {
        let json_input = r#"{"preamble": 85, "msg_type": 3074, "sender": 66, "length": 106, "payload": "EGRlZmdoaWprbG1ub3BxcnN0dXZ3AAMGCQwPEhUYGx4hJCcqLTAzNjk8P0JFSEtOUVRXWl1gY2ZpbG9ydXh7foGEh4qNkJOWmZyfoqWoq66xtLe6vcDDxsnMz9LV2Nve4eTn6u3w8/b5/A==", "crc": 38106, "n_msg": 16, "fingerprint": [100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119], "certificate_bytes": [0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81, 84, 87, 90, 93, 96, 99, 102, 105, 108, 111, 114, 117, 120, 123, 126, 129, 132, 135, 138, 141, 144, 147, 150, 153, 156, 159, 162, 165, 168, 171, 174, 177, 180, 183, 186, 189, 192, 195, 198, 201, 204, 207, 210, 213, 216, 219, 222, 225, 228, 231, 234, 237, 240, 243, 246, 249, 252]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgEd25519Certificate(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xC02,
                    "Incorrect message type, expected 0xC02, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.certificate_bytes[0], 0,
                    "incorrect value for certificate_bytes[0], expected 0, is {}",
                    msg.certificate_bytes[0]
                );
                assert_eq!(
                    msg.certificate_bytes[1], 3,
                    "incorrect value for certificate_bytes[1], expected 3, is {}",
                    msg.certificate_bytes[1]
                );
                assert_eq!(
                    msg.certificate_bytes[2], 6,
                    "incorrect value for certificate_bytes[2], expected 6, is {}",
                    msg.certificate_bytes[2]
                );
                assert_eq!(
                    msg.certificate_bytes[3], 9,
                    "incorrect value for certificate_bytes[3], expected 9, is {}",
                    msg.certificate_bytes[3]
                );
                assert_eq!(
                    msg.certificate_bytes[4], 12,
                    "incorrect value for certificate_bytes[4], expected 12, is {}",
                    msg.certificate_bytes[4]
                );
                assert_eq!(
                    msg.certificate_bytes[5], 15,
                    "incorrect value for certificate_bytes[5], expected 15, is {}",
                    msg.certificate_bytes[5]
                );
                assert_eq!(
                    msg.certificate_bytes[6], 18,
                    "incorrect value for certificate_bytes[6], expected 18, is {}",
                    msg.certificate_bytes[6]
                );
                assert_eq!(
                    msg.certificate_bytes[7], 21,
                    "incorrect value for certificate_bytes[7], expected 21, is {}",
                    msg.certificate_bytes[7]
                );
                assert_eq!(
                    msg.certificate_bytes[8], 24,
                    "incorrect value for certificate_bytes[8], expected 24, is {}",
                    msg.certificate_bytes[8]
                );
                assert_eq!(
                    msg.certificate_bytes[9], 27,
                    "incorrect value for certificate_bytes[9], expected 27, is {}",
                    msg.certificate_bytes[9]
                );
                assert_eq!(
                    msg.certificate_bytes[10], 30,
                    "incorrect value for certificate_bytes[10], expected 30, is {}",
                    msg.certificate_bytes[10]
                );
                assert_eq!(
                    msg.certificate_bytes[11], 33,
                    "incorrect value for certificate_bytes[11], expected 33, is {}",
                    msg.certificate_bytes[11]
                );
                assert_eq!(
                    msg.certificate_bytes[12], 36,
                    "incorrect value for certificate_bytes[12], expected 36, is {}",
                    msg.certificate_bytes[12]
                );
                assert_eq!(
                    msg.certificate_bytes[13], 39,
                    "incorrect value for certificate_bytes[13], expected 39, is {}",
                    msg.certificate_bytes[13]
                );
                assert_eq!(
                    msg.certificate_bytes[14], 42,
                    "incorrect value for certificate_bytes[14], expected 42, is {}",
                    msg.certificate_bytes[14]
                );
                assert_eq!(
                    msg.certificate_bytes[15], 45,
                    "incorrect value for certificate_bytes[15], expected 45, is {}",
                    msg.certificate_bytes[15]
                );
                assert_eq!(
                    msg.certificate_bytes[16], 48,
                    "incorrect value for certificate_bytes[16], expected 48, is {}",
                    msg.certificate_bytes[16]
                );
                assert_eq!(
                    msg.certificate_bytes[17], 51,
                    "incorrect value for certificate_bytes[17], expected 51, is {}",
                    msg.certificate_bytes[17]
                );
                assert_eq!(
                    msg.certificate_bytes[18], 54,
                    "incorrect value for certificate_bytes[18], expected 54, is {}",
                    msg.certificate_bytes[18]
                );
                assert_eq!(
                    msg.certificate_bytes[19], 57,
                    "incorrect value for certificate_bytes[19], expected 57, is {}",
                    msg.certificate_bytes[19]
                );
                assert_eq!(
                    msg.certificate_bytes[20], 60,
                    "incorrect value for certificate_bytes[20], expected 60, is {}",
                    msg.certificate_bytes[20]
                );
                assert_eq!(
                    msg.certificate_bytes[21], 63,
                    "incorrect value for certificate_bytes[21], expected 63, is {}",
                    msg.certificate_bytes[21]
                );
                assert_eq!(
                    msg.certificate_bytes[22], 66,
                    "incorrect value for certificate_bytes[22], expected 66, is {}",
                    msg.certificate_bytes[22]
                );
                assert_eq!(
                    msg.certificate_bytes[23], 69,
                    "incorrect value for certificate_bytes[23], expected 69, is {}",
                    msg.certificate_bytes[23]
                );
                assert_eq!(
                    msg.certificate_bytes[24], 72,
                    "incorrect value for certificate_bytes[24], expected 72, is {}",
                    msg.certificate_bytes[24]
                );
                assert_eq!(
                    msg.certificate_bytes[25], 75,
                    "incorrect value for certificate_bytes[25], expected 75, is {}",
                    msg.certificate_bytes[25]
                );
                assert_eq!(
                    msg.certificate_bytes[26], 78,
                    "incorrect value for certificate_bytes[26], expected 78, is {}",
                    msg.certificate_bytes[26]
                );
                assert_eq!(
                    msg.certificate_bytes[27], 81,
                    "incorrect value for certificate_bytes[27], expected 81, is {}",
                    msg.certificate_bytes[27]
                );
                assert_eq!(
                    msg.certificate_bytes[28], 84,
                    "incorrect value for certificate_bytes[28], expected 84, is {}",
                    msg.certificate_bytes[28]
                );
                assert_eq!(
                    msg.certificate_bytes[29], 87,
                    "incorrect value for certificate_bytes[29], expected 87, is {}",
                    msg.certificate_bytes[29]
                );
                assert_eq!(
                    msg.certificate_bytes[30], 90,
                    "incorrect value for certificate_bytes[30], expected 90, is {}",
                    msg.certificate_bytes[30]
                );
                assert_eq!(
                    msg.certificate_bytes[31], 93,
                    "incorrect value for certificate_bytes[31], expected 93, is {}",
                    msg.certificate_bytes[31]
                );
                assert_eq!(
                    msg.certificate_bytes[32], 96,
                    "incorrect value for certificate_bytes[32], expected 96, is {}",
                    msg.certificate_bytes[32]
                );
                assert_eq!(
                    msg.certificate_bytes[33], 99,
                    "incorrect value for certificate_bytes[33], expected 99, is {}",
                    msg.certificate_bytes[33]
                );
                assert_eq!(
                    msg.certificate_bytes[34], 102,
                    "incorrect value for certificate_bytes[34], expected 102, is {}",
                    msg.certificate_bytes[34]
                );
                assert_eq!(
                    msg.certificate_bytes[35], 105,
                    "incorrect value for certificate_bytes[35], expected 105, is {}",
                    msg.certificate_bytes[35]
                );
                assert_eq!(
                    msg.certificate_bytes[36], 108,
                    "incorrect value for certificate_bytes[36], expected 108, is {}",
                    msg.certificate_bytes[36]
                );
                assert_eq!(
                    msg.certificate_bytes[37], 111,
                    "incorrect value for certificate_bytes[37], expected 111, is {}",
                    msg.certificate_bytes[37]
                );
                assert_eq!(
                    msg.certificate_bytes[38], 114,
                    "incorrect value for certificate_bytes[38], expected 114, is {}",
                    msg.certificate_bytes[38]
                );
                assert_eq!(
                    msg.certificate_bytes[39], 117,
                    "incorrect value for certificate_bytes[39], expected 117, is {}",
                    msg.certificate_bytes[39]
                );
                assert_eq!(
                    msg.certificate_bytes[40], 120,
                    "incorrect value for certificate_bytes[40], expected 120, is {}",
                    msg.certificate_bytes[40]
                );
                assert_eq!(
                    msg.certificate_bytes[41], 123,
                    "incorrect value for certificate_bytes[41], expected 123, is {}",
                    msg.certificate_bytes[41]
                );
                assert_eq!(
                    msg.certificate_bytes[42], 126,
                    "incorrect value for certificate_bytes[42], expected 126, is {}",
                    msg.certificate_bytes[42]
                );
                assert_eq!(
                    msg.certificate_bytes[43], 129,
                    "incorrect value for certificate_bytes[43], expected 129, is {}",
                    msg.certificate_bytes[43]
                );
                assert_eq!(
                    msg.certificate_bytes[44], 132,
                    "incorrect value for certificate_bytes[44], expected 132, is {}",
                    msg.certificate_bytes[44]
                );
                assert_eq!(
                    msg.certificate_bytes[45], 135,
                    "incorrect value for certificate_bytes[45], expected 135, is {}",
                    msg.certificate_bytes[45]
                );
                assert_eq!(
                    msg.certificate_bytes[46], 138,
                    "incorrect value for certificate_bytes[46], expected 138, is {}",
                    msg.certificate_bytes[46]
                );
                assert_eq!(
                    msg.certificate_bytes[47], 141,
                    "incorrect value for certificate_bytes[47], expected 141, is {}",
                    msg.certificate_bytes[47]
                );
                assert_eq!(
                    msg.certificate_bytes[48], 144,
                    "incorrect value for certificate_bytes[48], expected 144, is {}",
                    msg.certificate_bytes[48]
                );
                assert_eq!(
                    msg.certificate_bytes[49], 147,
                    "incorrect value for certificate_bytes[49], expected 147, is {}",
                    msg.certificate_bytes[49]
                );
                assert_eq!(
                    msg.certificate_bytes[50], 150,
                    "incorrect value for certificate_bytes[50], expected 150, is {}",
                    msg.certificate_bytes[50]
                );
                assert_eq!(
                    msg.certificate_bytes[51], 153,
                    "incorrect value for certificate_bytes[51], expected 153, is {}",
                    msg.certificate_bytes[51]
                );
                assert_eq!(
                    msg.certificate_bytes[52], 156,
                    "incorrect value for certificate_bytes[52], expected 156, is {}",
                    msg.certificate_bytes[52]
                );
                assert_eq!(
                    msg.certificate_bytes[53], 159,
                    "incorrect value for certificate_bytes[53], expected 159, is {}",
                    msg.certificate_bytes[53]
                );
                assert_eq!(
                    msg.certificate_bytes[54], 162,
                    "incorrect value for certificate_bytes[54], expected 162, is {}",
                    msg.certificate_bytes[54]
                );
                assert_eq!(
                    msg.certificate_bytes[55], 165,
                    "incorrect value for certificate_bytes[55], expected 165, is {}",
                    msg.certificate_bytes[55]
                );
                assert_eq!(
                    msg.certificate_bytes[56], 168,
                    "incorrect value for certificate_bytes[56], expected 168, is {}",
                    msg.certificate_bytes[56]
                );
                assert_eq!(
                    msg.certificate_bytes[57], 171,
                    "incorrect value for certificate_bytes[57], expected 171, is {}",
                    msg.certificate_bytes[57]
                );
                assert_eq!(
                    msg.certificate_bytes[58], 174,
                    "incorrect value for certificate_bytes[58], expected 174, is {}",
                    msg.certificate_bytes[58]
                );
                assert_eq!(
                    msg.certificate_bytes[59], 177,
                    "incorrect value for certificate_bytes[59], expected 177, is {}",
                    msg.certificate_bytes[59]
                );
                assert_eq!(
                    msg.certificate_bytes[60], 180,
                    "incorrect value for certificate_bytes[60], expected 180, is {}",
                    msg.certificate_bytes[60]
                );
                assert_eq!(
                    msg.certificate_bytes[61], 183,
                    "incorrect value for certificate_bytes[61], expected 183, is {}",
                    msg.certificate_bytes[61]
                );
                assert_eq!(
                    msg.certificate_bytes[62], 186,
                    "incorrect value for certificate_bytes[62], expected 186, is {}",
                    msg.certificate_bytes[62]
                );
                assert_eq!(
                    msg.certificate_bytes[63], 189,
                    "incorrect value for certificate_bytes[63], expected 189, is {}",
                    msg.certificate_bytes[63]
                );
                assert_eq!(
                    msg.certificate_bytes[64], 192,
                    "incorrect value for certificate_bytes[64], expected 192, is {}",
                    msg.certificate_bytes[64]
                );
                assert_eq!(
                    msg.certificate_bytes[65], 195,
                    "incorrect value for certificate_bytes[65], expected 195, is {}",
                    msg.certificate_bytes[65]
                );
                assert_eq!(
                    msg.certificate_bytes[66], 198,
                    "incorrect value for certificate_bytes[66], expected 198, is {}",
                    msg.certificate_bytes[66]
                );
                assert_eq!(
                    msg.certificate_bytes[67], 201,
                    "incorrect value for certificate_bytes[67], expected 201, is {}",
                    msg.certificate_bytes[67]
                );
                assert_eq!(
                    msg.certificate_bytes[68], 204,
                    "incorrect value for certificate_bytes[68], expected 204, is {}",
                    msg.certificate_bytes[68]
                );
                assert_eq!(
                    msg.certificate_bytes[69], 207,
                    "incorrect value for certificate_bytes[69], expected 207, is {}",
                    msg.certificate_bytes[69]
                );
                assert_eq!(
                    msg.certificate_bytes[70], 210,
                    "incorrect value for certificate_bytes[70], expected 210, is {}",
                    msg.certificate_bytes[70]
                );
                assert_eq!(
                    msg.certificate_bytes[71], 213,
                    "incorrect value for certificate_bytes[71], expected 213, is {}",
                    msg.certificate_bytes[71]
                );
                assert_eq!(
                    msg.certificate_bytes[72], 216,
                    "incorrect value for certificate_bytes[72], expected 216, is {}",
                    msg.certificate_bytes[72]
                );
                assert_eq!(
                    msg.certificate_bytes[73], 219,
                    "incorrect value for certificate_bytes[73], expected 219, is {}",
                    msg.certificate_bytes[73]
                );
                assert_eq!(
                    msg.certificate_bytes[74], 222,
                    "incorrect value for certificate_bytes[74], expected 222, is {}",
                    msg.certificate_bytes[74]
                );
                assert_eq!(
                    msg.certificate_bytes[75], 225,
                    "incorrect value for certificate_bytes[75], expected 225, is {}",
                    msg.certificate_bytes[75]
                );
                assert_eq!(
                    msg.certificate_bytes[76], 228,
                    "incorrect value for certificate_bytes[76], expected 228, is {}",
                    msg.certificate_bytes[76]
                );
                assert_eq!(
                    msg.certificate_bytes[77], 231,
                    "incorrect value for certificate_bytes[77], expected 231, is {}",
                    msg.certificate_bytes[77]
                );
                assert_eq!(
                    msg.certificate_bytes[78], 234,
                    "incorrect value for certificate_bytes[78], expected 234, is {}",
                    msg.certificate_bytes[78]
                );
                assert_eq!(
                    msg.certificate_bytes[79], 237,
                    "incorrect value for certificate_bytes[79], expected 237, is {}",
                    msg.certificate_bytes[79]
                );
                assert_eq!(
                    msg.certificate_bytes[80], 240,
                    "incorrect value for certificate_bytes[80], expected 240, is {}",
                    msg.certificate_bytes[80]
                );
                assert_eq!(
                    msg.certificate_bytes[81], 243,
                    "incorrect value for certificate_bytes[81], expected 243, is {}",
                    msg.certificate_bytes[81]
                );
                assert_eq!(
                    msg.certificate_bytes[82], 246,
                    "incorrect value for certificate_bytes[82], expected 246, is {}",
                    msg.certificate_bytes[82]
                );
                assert_eq!(
                    msg.certificate_bytes[83], 249,
                    "incorrect value for certificate_bytes[83], expected 249, is {}",
                    msg.certificate_bytes[83]
                );
                assert_eq!(
                    msg.certificate_bytes[84], 252,
                    "incorrect value for certificate_bytes[84], expected 252, is {}",
                    msg.certificate_bytes[84]
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
                    msg.n_msg, 16,
                    "incorrect value for n_msg, expected 16, is {}",
                    msg.n_msg
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEd25519Certificate"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_signing_msg_ed25519_certificate`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_signing_msg_ed25519_certificate() {
    {
        let mut payload = Cursor::new(vec![
            85, 2, 12, 66, 0, 106, 16, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
            112, 113, 114, 115, 116, 117, 118, 119, 0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36,
            39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81, 84, 87, 90, 93, 96, 99,
            102, 105, 108, 111, 114, 117, 120, 123, 126, 129, 132, 135, 138, 141, 144, 147, 150,
            153, 156, 159, 162, 165, 168, 171, 174, 177, 180, 183, 186, 189, 192, 195, 198, 201,
            204, 207, 210, 213, 216, 219, 222, 225, 228, 231, 234, 237, 240, 243, 246, 249, 252,
            218, 148,
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
        let sbp_msg = sbp::messages::Sbp::MsgEd25519Certificate(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgEd25519Certificate(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xC02,
                    "Incorrect message type, expected 0xC02, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.certificate_bytes[0], 0,
                    "incorrect value for certificate_bytes[0], expected 0, is {}",
                    msg.certificate_bytes[0]
                );
                assert_eq!(
                    msg.certificate_bytes[1], 3,
                    "incorrect value for certificate_bytes[1], expected 3, is {}",
                    msg.certificate_bytes[1]
                );
                assert_eq!(
                    msg.certificate_bytes[2], 6,
                    "incorrect value for certificate_bytes[2], expected 6, is {}",
                    msg.certificate_bytes[2]
                );
                assert_eq!(
                    msg.certificate_bytes[3], 9,
                    "incorrect value for certificate_bytes[3], expected 9, is {}",
                    msg.certificate_bytes[3]
                );
                assert_eq!(
                    msg.certificate_bytes[4], 12,
                    "incorrect value for certificate_bytes[4], expected 12, is {}",
                    msg.certificate_bytes[4]
                );
                assert_eq!(
                    msg.certificate_bytes[5], 15,
                    "incorrect value for certificate_bytes[5], expected 15, is {}",
                    msg.certificate_bytes[5]
                );
                assert_eq!(
                    msg.certificate_bytes[6], 18,
                    "incorrect value for certificate_bytes[6], expected 18, is {}",
                    msg.certificate_bytes[6]
                );
                assert_eq!(
                    msg.certificate_bytes[7], 21,
                    "incorrect value for certificate_bytes[7], expected 21, is {}",
                    msg.certificate_bytes[7]
                );
                assert_eq!(
                    msg.certificate_bytes[8], 24,
                    "incorrect value for certificate_bytes[8], expected 24, is {}",
                    msg.certificate_bytes[8]
                );
                assert_eq!(
                    msg.certificate_bytes[9], 27,
                    "incorrect value for certificate_bytes[9], expected 27, is {}",
                    msg.certificate_bytes[9]
                );
                assert_eq!(
                    msg.certificate_bytes[10], 30,
                    "incorrect value for certificate_bytes[10], expected 30, is {}",
                    msg.certificate_bytes[10]
                );
                assert_eq!(
                    msg.certificate_bytes[11], 33,
                    "incorrect value for certificate_bytes[11], expected 33, is {}",
                    msg.certificate_bytes[11]
                );
                assert_eq!(
                    msg.certificate_bytes[12], 36,
                    "incorrect value for certificate_bytes[12], expected 36, is {}",
                    msg.certificate_bytes[12]
                );
                assert_eq!(
                    msg.certificate_bytes[13], 39,
                    "incorrect value for certificate_bytes[13], expected 39, is {}",
                    msg.certificate_bytes[13]
                );
                assert_eq!(
                    msg.certificate_bytes[14], 42,
                    "incorrect value for certificate_bytes[14], expected 42, is {}",
                    msg.certificate_bytes[14]
                );
                assert_eq!(
                    msg.certificate_bytes[15], 45,
                    "incorrect value for certificate_bytes[15], expected 45, is {}",
                    msg.certificate_bytes[15]
                );
                assert_eq!(
                    msg.certificate_bytes[16], 48,
                    "incorrect value for certificate_bytes[16], expected 48, is {}",
                    msg.certificate_bytes[16]
                );
                assert_eq!(
                    msg.certificate_bytes[17], 51,
                    "incorrect value for certificate_bytes[17], expected 51, is {}",
                    msg.certificate_bytes[17]
                );
                assert_eq!(
                    msg.certificate_bytes[18], 54,
                    "incorrect value for certificate_bytes[18], expected 54, is {}",
                    msg.certificate_bytes[18]
                );
                assert_eq!(
                    msg.certificate_bytes[19], 57,
                    "incorrect value for certificate_bytes[19], expected 57, is {}",
                    msg.certificate_bytes[19]
                );
                assert_eq!(
                    msg.certificate_bytes[20], 60,
                    "incorrect value for certificate_bytes[20], expected 60, is {}",
                    msg.certificate_bytes[20]
                );
                assert_eq!(
                    msg.certificate_bytes[21], 63,
                    "incorrect value for certificate_bytes[21], expected 63, is {}",
                    msg.certificate_bytes[21]
                );
                assert_eq!(
                    msg.certificate_bytes[22], 66,
                    "incorrect value for certificate_bytes[22], expected 66, is {}",
                    msg.certificate_bytes[22]
                );
                assert_eq!(
                    msg.certificate_bytes[23], 69,
                    "incorrect value for certificate_bytes[23], expected 69, is {}",
                    msg.certificate_bytes[23]
                );
                assert_eq!(
                    msg.certificate_bytes[24], 72,
                    "incorrect value for certificate_bytes[24], expected 72, is {}",
                    msg.certificate_bytes[24]
                );
                assert_eq!(
                    msg.certificate_bytes[25], 75,
                    "incorrect value for certificate_bytes[25], expected 75, is {}",
                    msg.certificate_bytes[25]
                );
                assert_eq!(
                    msg.certificate_bytes[26], 78,
                    "incorrect value for certificate_bytes[26], expected 78, is {}",
                    msg.certificate_bytes[26]
                );
                assert_eq!(
                    msg.certificate_bytes[27], 81,
                    "incorrect value for certificate_bytes[27], expected 81, is {}",
                    msg.certificate_bytes[27]
                );
                assert_eq!(
                    msg.certificate_bytes[28], 84,
                    "incorrect value for certificate_bytes[28], expected 84, is {}",
                    msg.certificate_bytes[28]
                );
                assert_eq!(
                    msg.certificate_bytes[29], 87,
                    "incorrect value for certificate_bytes[29], expected 87, is {}",
                    msg.certificate_bytes[29]
                );
                assert_eq!(
                    msg.certificate_bytes[30], 90,
                    "incorrect value for certificate_bytes[30], expected 90, is {}",
                    msg.certificate_bytes[30]
                );
                assert_eq!(
                    msg.certificate_bytes[31], 93,
                    "incorrect value for certificate_bytes[31], expected 93, is {}",
                    msg.certificate_bytes[31]
                );
                assert_eq!(
                    msg.certificate_bytes[32], 96,
                    "incorrect value for certificate_bytes[32], expected 96, is {}",
                    msg.certificate_bytes[32]
                );
                assert_eq!(
                    msg.certificate_bytes[33], 99,
                    "incorrect value for certificate_bytes[33], expected 99, is {}",
                    msg.certificate_bytes[33]
                );
                assert_eq!(
                    msg.certificate_bytes[34], 102,
                    "incorrect value for certificate_bytes[34], expected 102, is {}",
                    msg.certificate_bytes[34]
                );
                assert_eq!(
                    msg.certificate_bytes[35], 105,
                    "incorrect value for certificate_bytes[35], expected 105, is {}",
                    msg.certificate_bytes[35]
                );
                assert_eq!(
                    msg.certificate_bytes[36], 108,
                    "incorrect value for certificate_bytes[36], expected 108, is {}",
                    msg.certificate_bytes[36]
                );
                assert_eq!(
                    msg.certificate_bytes[37], 111,
                    "incorrect value for certificate_bytes[37], expected 111, is {}",
                    msg.certificate_bytes[37]
                );
                assert_eq!(
                    msg.certificate_bytes[38], 114,
                    "incorrect value for certificate_bytes[38], expected 114, is {}",
                    msg.certificate_bytes[38]
                );
                assert_eq!(
                    msg.certificate_bytes[39], 117,
                    "incorrect value for certificate_bytes[39], expected 117, is {}",
                    msg.certificate_bytes[39]
                );
                assert_eq!(
                    msg.certificate_bytes[40], 120,
                    "incorrect value for certificate_bytes[40], expected 120, is {}",
                    msg.certificate_bytes[40]
                );
                assert_eq!(
                    msg.certificate_bytes[41], 123,
                    "incorrect value for certificate_bytes[41], expected 123, is {}",
                    msg.certificate_bytes[41]
                );
                assert_eq!(
                    msg.certificate_bytes[42], 126,
                    "incorrect value for certificate_bytes[42], expected 126, is {}",
                    msg.certificate_bytes[42]
                );
                assert_eq!(
                    msg.certificate_bytes[43], 129,
                    "incorrect value for certificate_bytes[43], expected 129, is {}",
                    msg.certificate_bytes[43]
                );
                assert_eq!(
                    msg.certificate_bytes[44], 132,
                    "incorrect value for certificate_bytes[44], expected 132, is {}",
                    msg.certificate_bytes[44]
                );
                assert_eq!(
                    msg.certificate_bytes[45], 135,
                    "incorrect value for certificate_bytes[45], expected 135, is {}",
                    msg.certificate_bytes[45]
                );
                assert_eq!(
                    msg.certificate_bytes[46], 138,
                    "incorrect value for certificate_bytes[46], expected 138, is {}",
                    msg.certificate_bytes[46]
                );
                assert_eq!(
                    msg.certificate_bytes[47], 141,
                    "incorrect value for certificate_bytes[47], expected 141, is {}",
                    msg.certificate_bytes[47]
                );
                assert_eq!(
                    msg.certificate_bytes[48], 144,
                    "incorrect value for certificate_bytes[48], expected 144, is {}",
                    msg.certificate_bytes[48]
                );
                assert_eq!(
                    msg.certificate_bytes[49], 147,
                    "incorrect value for certificate_bytes[49], expected 147, is {}",
                    msg.certificate_bytes[49]
                );
                assert_eq!(
                    msg.certificate_bytes[50], 150,
                    "incorrect value for certificate_bytes[50], expected 150, is {}",
                    msg.certificate_bytes[50]
                );
                assert_eq!(
                    msg.certificate_bytes[51], 153,
                    "incorrect value for certificate_bytes[51], expected 153, is {}",
                    msg.certificate_bytes[51]
                );
                assert_eq!(
                    msg.certificate_bytes[52], 156,
                    "incorrect value for certificate_bytes[52], expected 156, is {}",
                    msg.certificate_bytes[52]
                );
                assert_eq!(
                    msg.certificate_bytes[53], 159,
                    "incorrect value for certificate_bytes[53], expected 159, is {}",
                    msg.certificate_bytes[53]
                );
                assert_eq!(
                    msg.certificate_bytes[54], 162,
                    "incorrect value for certificate_bytes[54], expected 162, is {}",
                    msg.certificate_bytes[54]
                );
                assert_eq!(
                    msg.certificate_bytes[55], 165,
                    "incorrect value for certificate_bytes[55], expected 165, is {}",
                    msg.certificate_bytes[55]
                );
                assert_eq!(
                    msg.certificate_bytes[56], 168,
                    "incorrect value for certificate_bytes[56], expected 168, is {}",
                    msg.certificate_bytes[56]
                );
                assert_eq!(
                    msg.certificate_bytes[57], 171,
                    "incorrect value for certificate_bytes[57], expected 171, is {}",
                    msg.certificate_bytes[57]
                );
                assert_eq!(
                    msg.certificate_bytes[58], 174,
                    "incorrect value for certificate_bytes[58], expected 174, is {}",
                    msg.certificate_bytes[58]
                );
                assert_eq!(
                    msg.certificate_bytes[59], 177,
                    "incorrect value for certificate_bytes[59], expected 177, is {}",
                    msg.certificate_bytes[59]
                );
                assert_eq!(
                    msg.certificate_bytes[60], 180,
                    "incorrect value for certificate_bytes[60], expected 180, is {}",
                    msg.certificate_bytes[60]
                );
                assert_eq!(
                    msg.certificate_bytes[61], 183,
                    "incorrect value for certificate_bytes[61], expected 183, is {}",
                    msg.certificate_bytes[61]
                );
                assert_eq!(
                    msg.certificate_bytes[62], 186,
                    "incorrect value for certificate_bytes[62], expected 186, is {}",
                    msg.certificate_bytes[62]
                );
                assert_eq!(
                    msg.certificate_bytes[63], 189,
                    "incorrect value for certificate_bytes[63], expected 189, is {}",
                    msg.certificate_bytes[63]
                );
                assert_eq!(
                    msg.certificate_bytes[64], 192,
                    "incorrect value for certificate_bytes[64], expected 192, is {}",
                    msg.certificate_bytes[64]
                );
                assert_eq!(
                    msg.certificate_bytes[65], 195,
                    "incorrect value for certificate_bytes[65], expected 195, is {}",
                    msg.certificate_bytes[65]
                );
                assert_eq!(
                    msg.certificate_bytes[66], 198,
                    "incorrect value for certificate_bytes[66], expected 198, is {}",
                    msg.certificate_bytes[66]
                );
                assert_eq!(
                    msg.certificate_bytes[67], 201,
                    "incorrect value for certificate_bytes[67], expected 201, is {}",
                    msg.certificate_bytes[67]
                );
                assert_eq!(
                    msg.certificate_bytes[68], 204,
                    "incorrect value for certificate_bytes[68], expected 204, is {}",
                    msg.certificate_bytes[68]
                );
                assert_eq!(
                    msg.certificate_bytes[69], 207,
                    "incorrect value for certificate_bytes[69], expected 207, is {}",
                    msg.certificate_bytes[69]
                );
                assert_eq!(
                    msg.certificate_bytes[70], 210,
                    "incorrect value for certificate_bytes[70], expected 210, is {}",
                    msg.certificate_bytes[70]
                );
                assert_eq!(
                    msg.certificate_bytes[71], 213,
                    "incorrect value for certificate_bytes[71], expected 213, is {}",
                    msg.certificate_bytes[71]
                );
                assert_eq!(
                    msg.certificate_bytes[72], 216,
                    "incorrect value for certificate_bytes[72], expected 216, is {}",
                    msg.certificate_bytes[72]
                );
                assert_eq!(
                    msg.certificate_bytes[73], 219,
                    "incorrect value for certificate_bytes[73], expected 219, is {}",
                    msg.certificate_bytes[73]
                );
                assert_eq!(
                    msg.certificate_bytes[74], 222,
                    "incorrect value for certificate_bytes[74], expected 222, is {}",
                    msg.certificate_bytes[74]
                );
                assert_eq!(
                    msg.certificate_bytes[75], 225,
                    "incorrect value for certificate_bytes[75], expected 225, is {}",
                    msg.certificate_bytes[75]
                );
                assert_eq!(
                    msg.certificate_bytes[76], 228,
                    "incorrect value for certificate_bytes[76], expected 228, is {}",
                    msg.certificate_bytes[76]
                );
                assert_eq!(
                    msg.certificate_bytes[77], 231,
                    "incorrect value for certificate_bytes[77], expected 231, is {}",
                    msg.certificate_bytes[77]
                );
                assert_eq!(
                    msg.certificate_bytes[78], 234,
                    "incorrect value for certificate_bytes[78], expected 234, is {}",
                    msg.certificate_bytes[78]
                );
                assert_eq!(
                    msg.certificate_bytes[79], 237,
                    "incorrect value for certificate_bytes[79], expected 237, is {}",
                    msg.certificate_bytes[79]
                );
                assert_eq!(
                    msg.certificate_bytes[80], 240,
                    "incorrect value for certificate_bytes[80], expected 240, is {}",
                    msg.certificate_bytes[80]
                );
                assert_eq!(
                    msg.certificate_bytes[81], 243,
                    "incorrect value for certificate_bytes[81], expected 243, is {}",
                    msg.certificate_bytes[81]
                );
                assert_eq!(
                    msg.certificate_bytes[82], 246,
                    "incorrect value for certificate_bytes[82], expected 246, is {}",
                    msg.certificate_bytes[82]
                );
                assert_eq!(
                    msg.certificate_bytes[83], 249,
                    "incorrect value for certificate_bytes[83], expected 249, is {}",
                    msg.certificate_bytes[83]
                );
                assert_eq!(
                    msg.certificate_bytes[84], 252,
                    "incorrect value for certificate_bytes[84], expected 252, is {}",
                    msg.certificate_bytes[84]
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
                    msg.n_msg, 16,
                    "incorrect value for n_msg, expected 16, is {}",
                    msg.n_msg
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEd25519Certificate"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
