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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignatureDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_signing_msg_ecdsa_signature_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 6, 12, 66, 0, 255, 0, 1, 2, 1, 2, 3, 4, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5,
            6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2,
            3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 10, 21, 23, 63, 140, 37,
            130, 106, 28, 40, 165, 179, 73, 178, 60, 126, 114, 78, 113, 27, 95, 3, 62, 104, 145,
            96, 19, 92, 123, 14, 90, 153, 183, 9, 72, 81, 118, 112, 124, 16, 182, 76, 146, 115, 58,
            144, 17, 105, 66, 31, 135, 54, 100, 84, 181, 103, 11, 88, 133, 155, 167, 173, 143, 86,
            158, 20, 168, 132, 141, 102, 50, 48, 71, 147, 53, 87, 1, 108, 138, 36, 134, 139, 163,
            82, 43, 52, 150, 12, 30, 110, 156, 107, 120, 91, 122, 69, 164, 170, 116, 25, 94, 5, 22,
            24, 162, 175, 38, 157, 98, 44, 160, 47, 97, 142, 8, 74, 13, 177, 15, 128, 26, 131, 154,
            65, 169, 55, 136, 125, 171, 161, 29, 129, 151, 68, 166, 51, 70, 45, 56, 79, 149, 99,
            42, 101, 152, 39, 89, 180, 64, 49, 6, 80, 172, 32, 109, 2, 119, 93, 176, 0, 33, 57, 34,
            18, 85, 121, 137, 83, 111, 59, 7, 77, 4, 117, 159, 148, 35, 61, 41, 67, 46, 127, 75,
            174, 97, 172,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgEcdsaSignatureDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC06,
                    "Incorrect message type, expected 0xC06, is {}",
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
                    msg.signature[8], 0,
                    "incorrect value for signature[8], expected 0, is {}",
                    msg.signature[8]
                );
                assert_eq!(
                    msg.signature[9], 1,
                    "incorrect value for signature[9], expected 1, is {}",
                    msg.signature[9]
                );
                assert_eq!(
                    msg.signature[10], 2,
                    "incorrect value for signature[10], expected 2, is {}",
                    msg.signature[10]
                );
                assert_eq!(
                    msg.signature[11], 3,
                    "incorrect value for signature[11], expected 3, is {}",
                    msg.signature[11]
                );
                assert_eq!(
                    msg.signature[12], 4,
                    "incorrect value for signature[12], expected 4, is {}",
                    msg.signature[12]
                );
                assert_eq!(
                    msg.signature[13], 5,
                    "incorrect value for signature[13], expected 5, is {}",
                    msg.signature[13]
                );
                assert_eq!(
                    msg.signature[14], 6,
                    "incorrect value for signature[14], expected 6, is {}",
                    msg.signature[14]
                );
                assert_eq!(
                    msg.signature[15], 7,
                    "incorrect value for signature[15], expected 7, is {}",
                    msg.signature[15]
                );
                assert_eq!(
                    msg.signature[16], 0,
                    "incorrect value for signature[16], expected 0, is {}",
                    msg.signature[16]
                );
                assert_eq!(
                    msg.signature[17], 1,
                    "incorrect value for signature[17], expected 1, is {}",
                    msg.signature[17]
                );
                assert_eq!(
                    msg.signature[18], 2,
                    "incorrect value for signature[18], expected 2, is {}",
                    msg.signature[18]
                );
                assert_eq!(
                    msg.signature[19], 3,
                    "incorrect value for signature[19], expected 3, is {}",
                    msg.signature[19]
                );
                assert_eq!(
                    msg.signature[20], 4,
                    "incorrect value for signature[20], expected 4, is {}",
                    msg.signature[20]
                );
                assert_eq!(
                    msg.signature[21], 5,
                    "incorrect value for signature[21], expected 5, is {}",
                    msg.signature[21]
                );
                assert_eq!(
                    msg.signature[22], 6,
                    "incorrect value for signature[22], expected 6, is {}",
                    msg.signature[22]
                );
                assert_eq!(
                    msg.signature[23], 7,
                    "incorrect value for signature[23], expected 7, is {}",
                    msg.signature[23]
                );
                assert_eq!(
                    msg.signature[24], 0,
                    "incorrect value for signature[24], expected 0, is {}",
                    msg.signature[24]
                );
                assert_eq!(
                    msg.signature[25], 1,
                    "incorrect value for signature[25], expected 1, is {}",
                    msg.signature[25]
                );
                assert_eq!(
                    msg.signature[26], 2,
                    "incorrect value for signature[26], expected 2, is {}",
                    msg.signature[26]
                );
                assert_eq!(
                    msg.signature[27], 3,
                    "incorrect value for signature[27], expected 3, is {}",
                    msg.signature[27]
                );
                assert_eq!(
                    msg.signature[28], 4,
                    "incorrect value for signature[28], expected 4, is {}",
                    msg.signature[28]
                );
                assert_eq!(
                    msg.signature[29], 5,
                    "incorrect value for signature[29], expected 5, is {}",
                    msg.signature[29]
                );
                assert_eq!(
                    msg.signature[30], 6,
                    "incorrect value for signature[30], expected 6, is {}",
                    msg.signature[30]
                );
                assert_eq!(
                    msg.signature[31], 7,
                    "incorrect value for signature[31], expected 7, is {}",
                    msg.signature[31]
                );
                assert_eq!(
                    msg.signature[32], 0,
                    "incorrect value for signature[32], expected 0, is {}",
                    msg.signature[32]
                );
                assert_eq!(
                    msg.signature[33], 1,
                    "incorrect value for signature[33], expected 1, is {}",
                    msg.signature[33]
                );
                assert_eq!(
                    msg.signature[34], 2,
                    "incorrect value for signature[34], expected 2, is {}",
                    msg.signature[34]
                );
                assert_eq!(
                    msg.signature[35], 3,
                    "incorrect value for signature[35], expected 3, is {}",
                    msg.signature[35]
                );
                assert_eq!(
                    msg.signature[36], 4,
                    "incorrect value for signature[36], expected 4, is {}",
                    msg.signature[36]
                );
                assert_eq!(
                    msg.signature[37], 5,
                    "incorrect value for signature[37], expected 5, is {}",
                    msg.signature[37]
                );
                assert_eq!(
                    msg.signature[38], 6,
                    "incorrect value for signature[38], expected 6, is {}",
                    msg.signature[38]
                );
                assert_eq!(
                    msg.signature[39], 7,
                    "incorrect value for signature[39], expected 7, is {}",
                    msg.signature[39]
                );
                assert_eq!(
                    msg.signature[40], 0,
                    "incorrect value for signature[40], expected 0, is {}",
                    msg.signature[40]
                );
                assert_eq!(
                    msg.signature[41], 1,
                    "incorrect value for signature[41], expected 1, is {}",
                    msg.signature[41]
                );
                assert_eq!(
                    msg.signature[42], 2,
                    "incorrect value for signature[42], expected 2, is {}",
                    msg.signature[42]
                );
                assert_eq!(
                    msg.signature[43], 3,
                    "incorrect value for signature[43], expected 3, is {}",
                    msg.signature[43]
                );
                assert_eq!(
                    msg.signature[44], 4,
                    "incorrect value for signature[44], expected 4, is {}",
                    msg.signature[44]
                );
                assert_eq!(
                    msg.signature[45], 5,
                    "incorrect value for signature[45], expected 5, is {}",
                    msg.signature[45]
                );
                assert_eq!(
                    msg.signature[46], 6,
                    "incorrect value for signature[46], expected 6, is {}",
                    msg.signature[46]
                );
                assert_eq!(
                    msg.signature[47], 7,
                    "incorrect value for signature[47], expected 7, is {}",
                    msg.signature[47]
                );
                assert_eq!(
                    msg.signature[48], 0,
                    "incorrect value for signature[48], expected 0, is {}",
                    msg.signature[48]
                );
                assert_eq!(
                    msg.signature[49], 1,
                    "incorrect value for signature[49], expected 1, is {}",
                    msg.signature[49]
                );
                assert_eq!(
                    msg.signature[50], 2,
                    "incorrect value for signature[50], expected 2, is {}",
                    msg.signature[50]
                );
                assert_eq!(
                    msg.signature[51], 3,
                    "incorrect value for signature[51], expected 3, is {}",
                    msg.signature[51]
                );
                assert_eq!(
                    msg.signature[52], 4,
                    "incorrect value for signature[52], expected 4, is {}",
                    msg.signature[52]
                );
                assert_eq!(
                    msg.signature[53], 5,
                    "incorrect value for signature[53], expected 5, is {}",
                    msg.signature[53]
                );
                assert_eq!(
                    msg.signature[54], 6,
                    "incorrect value for signature[54], expected 6, is {}",
                    msg.signature[54]
                );
                assert_eq!(
                    msg.signature[55], 7,
                    "incorrect value for signature[55], expected 7, is {}",
                    msg.signature[55]
                );
                assert_eq!(
                    msg.signature[56], 0,
                    "incorrect value for signature[56], expected 0, is {}",
                    msg.signature[56]
                );
                assert_eq!(
                    msg.signature[57], 1,
                    "incorrect value for signature[57], expected 1, is {}",
                    msg.signature[57]
                );
                assert_eq!(
                    msg.signature[58], 2,
                    "incorrect value for signature[58], expected 2, is {}",
                    msg.signature[58]
                );
                assert_eq!(
                    msg.signature[59], 3,
                    "incorrect value for signature[59], expected 3, is {}",
                    msg.signature[59]
                );
                assert_eq!(
                    msg.signature[60], 4,
                    "incorrect value for signature[60], expected 4, is {}",
                    msg.signature[60]
                );
                assert_eq!(
                    msg.signature[61], 5,
                    "incorrect value for signature[61], expected 5, is {}",
                    msg.signature[61]
                );
                assert_eq!(
                    msg.signature[62], 6,
                    "incorrect value for signature[62], expected 6, is {}",
                    msg.signature[62]
                );
                assert_eq!(
                    msg.signature[63], 7,
                    "incorrect value for signature[63], expected 7, is {}",
                    msg.signature[63]
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
                    msg.signed_messages[3], 63,
                    "incorrect value for signed_messages[3], expected 63, is {}",
                    msg.signed_messages[3]
                );
                assert_eq!(
                    msg.signed_messages[4], 140,
                    "incorrect value for signed_messages[4], expected 140, is {}",
                    msg.signed_messages[4]
                );
                assert_eq!(
                    msg.signed_messages[5], 37,
                    "incorrect value for signed_messages[5], expected 37, is {}",
                    msg.signed_messages[5]
                );
                assert_eq!(
                    msg.signed_messages[6], 130,
                    "incorrect value for signed_messages[6], expected 130, is {}",
                    msg.signed_messages[6]
                );
                assert_eq!(
                    msg.signed_messages[7], 106,
                    "incorrect value for signed_messages[7], expected 106, is {}",
                    msg.signed_messages[7]
                );
                assert_eq!(
                    msg.signed_messages[8], 28,
                    "incorrect value for signed_messages[8], expected 28, is {}",
                    msg.signed_messages[8]
                );
                assert_eq!(
                    msg.signed_messages[9], 40,
                    "incorrect value for signed_messages[9], expected 40, is {}",
                    msg.signed_messages[9]
                );
                assert_eq!(
                    msg.signed_messages[10], 165,
                    "incorrect value for signed_messages[10], expected 165, is {}",
                    msg.signed_messages[10]
                );
                assert_eq!(
                    msg.signed_messages[11], 179,
                    "incorrect value for signed_messages[11], expected 179, is {}",
                    msg.signed_messages[11]
                );
                assert_eq!(
                    msg.signed_messages[12], 73,
                    "incorrect value for signed_messages[12], expected 73, is {}",
                    msg.signed_messages[12]
                );
                assert_eq!(
                    msg.signed_messages[13], 178,
                    "incorrect value for signed_messages[13], expected 178, is {}",
                    msg.signed_messages[13]
                );
                assert_eq!(
                    msg.signed_messages[14], 60,
                    "incorrect value for signed_messages[14], expected 60, is {}",
                    msg.signed_messages[14]
                );
                assert_eq!(
                    msg.signed_messages[15], 126,
                    "incorrect value for signed_messages[15], expected 126, is {}",
                    msg.signed_messages[15]
                );
                assert_eq!(
                    msg.signed_messages[16], 114,
                    "incorrect value for signed_messages[16], expected 114, is {}",
                    msg.signed_messages[16]
                );
                assert_eq!(
                    msg.signed_messages[17], 78,
                    "incorrect value for signed_messages[17], expected 78, is {}",
                    msg.signed_messages[17]
                );
                assert_eq!(
                    msg.signed_messages[18], 113,
                    "incorrect value for signed_messages[18], expected 113, is {}",
                    msg.signed_messages[18]
                );
                assert_eq!(
                    msg.signed_messages[19], 27,
                    "incorrect value for signed_messages[19], expected 27, is {}",
                    msg.signed_messages[19]
                );
                assert_eq!(
                    msg.signed_messages[20], 95,
                    "incorrect value for signed_messages[20], expected 95, is {}",
                    msg.signed_messages[20]
                );
                assert_eq!(
                    msg.signed_messages[21], 3,
                    "incorrect value for signed_messages[21], expected 3, is {}",
                    msg.signed_messages[21]
                );
                assert_eq!(
                    msg.signed_messages[22], 62,
                    "incorrect value for signed_messages[22], expected 62, is {}",
                    msg.signed_messages[22]
                );
                assert_eq!(
                    msg.signed_messages[23], 104,
                    "incorrect value for signed_messages[23], expected 104, is {}",
                    msg.signed_messages[23]
                );
                assert_eq!(
                    msg.signed_messages[24], 145,
                    "incorrect value for signed_messages[24], expected 145, is {}",
                    msg.signed_messages[24]
                );
                assert_eq!(
                    msg.signed_messages[25], 96,
                    "incorrect value for signed_messages[25], expected 96, is {}",
                    msg.signed_messages[25]
                );
                assert_eq!(
                    msg.signed_messages[26], 19,
                    "incorrect value for signed_messages[26], expected 19, is {}",
                    msg.signed_messages[26]
                );
                assert_eq!(
                    msg.signed_messages[27], 92,
                    "incorrect value for signed_messages[27], expected 92, is {}",
                    msg.signed_messages[27]
                );
                assert_eq!(
                    msg.signed_messages[28], 123,
                    "incorrect value for signed_messages[28], expected 123, is {}",
                    msg.signed_messages[28]
                );
                assert_eq!(
                    msg.signed_messages[29], 14,
                    "incorrect value for signed_messages[29], expected 14, is {}",
                    msg.signed_messages[29]
                );
                assert_eq!(
                    msg.signed_messages[30], 90,
                    "incorrect value for signed_messages[30], expected 90, is {}",
                    msg.signed_messages[30]
                );
                assert_eq!(
                    msg.signed_messages[31], 153,
                    "incorrect value for signed_messages[31], expected 153, is {}",
                    msg.signed_messages[31]
                );
                assert_eq!(
                    msg.signed_messages[32], 183,
                    "incorrect value for signed_messages[32], expected 183, is {}",
                    msg.signed_messages[32]
                );
                assert_eq!(
                    msg.signed_messages[33], 9,
                    "incorrect value for signed_messages[33], expected 9, is {}",
                    msg.signed_messages[33]
                );
                assert_eq!(
                    msg.signed_messages[34], 72,
                    "incorrect value for signed_messages[34], expected 72, is {}",
                    msg.signed_messages[34]
                );
                assert_eq!(
                    msg.signed_messages[35], 81,
                    "incorrect value for signed_messages[35], expected 81, is {}",
                    msg.signed_messages[35]
                );
                assert_eq!(
                    msg.signed_messages[36], 118,
                    "incorrect value for signed_messages[36], expected 118, is {}",
                    msg.signed_messages[36]
                );
                assert_eq!(
                    msg.signed_messages[37], 112,
                    "incorrect value for signed_messages[37], expected 112, is {}",
                    msg.signed_messages[37]
                );
                assert_eq!(
                    msg.signed_messages[38], 124,
                    "incorrect value for signed_messages[38], expected 124, is {}",
                    msg.signed_messages[38]
                );
                assert_eq!(
                    msg.signed_messages[39], 16,
                    "incorrect value for signed_messages[39], expected 16, is {}",
                    msg.signed_messages[39]
                );
                assert_eq!(
                    msg.signed_messages[40], 182,
                    "incorrect value for signed_messages[40], expected 182, is {}",
                    msg.signed_messages[40]
                );
                assert_eq!(
                    msg.signed_messages[41], 76,
                    "incorrect value for signed_messages[41], expected 76, is {}",
                    msg.signed_messages[41]
                );
                assert_eq!(
                    msg.signed_messages[42], 146,
                    "incorrect value for signed_messages[42], expected 146, is {}",
                    msg.signed_messages[42]
                );
                assert_eq!(
                    msg.signed_messages[43], 115,
                    "incorrect value for signed_messages[43], expected 115, is {}",
                    msg.signed_messages[43]
                );
                assert_eq!(
                    msg.signed_messages[44], 58,
                    "incorrect value for signed_messages[44], expected 58, is {}",
                    msg.signed_messages[44]
                );
                assert_eq!(
                    msg.signed_messages[45], 144,
                    "incorrect value for signed_messages[45], expected 144, is {}",
                    msg.signed_messages[45]
                );
                assert_eq!(
                    msg.signed_messages[46], 17,
                    "incorrect value for signed_messages[46], expected 17, is {}",
                    msg.signed_messages[46]
                );
                assert_eq!(
                    msg.signed_messages[47], 105,
                    "incorrect value for signed_messages[47], expected 105, is {}",
                    msg.signed_messages[47]
                );
                assert_eq!(
                    msg.signed_messages[48], 66,
                    "incorrect value for signed_messages[48], expected 66, is {}",
                    msg.signed_messages[48]
                );
                assert_eq!(
                    msg.signed_messages[49], 31,
                    "incorrect value for signed_messages[49], expected 31, is {}",
                    msg.signed_messages[49]
                );
                assert_eq!(
                    msg.signed_messages[50], 135,
                    "incorrect value for signed_messages[50], expected 135, is {}",
                    msg.signed_messages[50]
                );
                assert_eq!(
                    msg.signed_messages[51], 54,
                    "incorrect value for signed_messages[51], expected 54, is {}",
                    msg.signed_messages[51]
                );
                assert_eq!(
                    msg.signed_messages[52], 100,
                    "incorrect value for signed_messages[52], expected 100, is {}",
                    msg.signed_messages[52]
                );
                assert_eq!(
                    msg.signed_messages[53], 84,
                    "incorrect value for signed_messages[53], expected 84, is {}",
                    msg.signed_messages[53]
                );
                assert_eq!(
                    msg.signed_messages[54], 181,
                    "incorrect value for signed_messages[54], expected 181, is {}",
                    msg.signed_messages[54]
                );
                assert_eq!(
                    msg.signed_messages[55], 103,
                    "incorrect value for signed_messages[55], expected 103, is {}",
                    msg.signed_messages[55]
                );
                assert_eq!(
                    msg.signed_messages[56], 11,
                    "incorrect value for signed_messages[56], expected 11, is {}",
                    msg.signed_messages[56]
                );
                assert_eq!(
                    msg.signed_messages[57], 88,
                    "incorrect value for signed_messages[57], expected 88, is {}",
                    msg.signed_messages[57]
                );
                assert_eq!(
                    msg.signed_messages[58], 133,
                    "incorrect value for signed_messages[58], expected 133, is {}",
                    msg.signed_messages[58]
                );
                assert_eq!(
                    msg.signed_messages[59], 155,
                    "incorrect value for signed_messages[59], expected 155, is {}",
                    msg.signed_messages[59]
                );
                assert_eq!(
                    msg.signed_messages[60], 167,
                    "incorrect value for signed_messages[60], expected 167, is {}",
                    msg.signed_messages[60]
                );
                assert_eq!(
                    msg.signed_messages[61], 173,
                    "incorrect value for signed_messages[61], expected 173, is {}",
                    msg.signed_messages[61]
                );
                assert_eq!(
                    msg.signed_messages[62], 143,
                    "incorrect value for signed_messages[62], expected 143, is {}",
                    msg.signed_messages[62]
                );
                assert_eq!(
                    msg.signed_messages[63], 86,
                    "incorrect value for signed_messages[63], expected 86, is {}",
                    msg.signed_messages[63]
                );
                assert_eq!(
                    msg.signed_messages[64], 158,
                    "incorrect value for signed_messages[64], expected 158, is {}",
                    msg.signed_messages[64]
                );
                assert_eq!(
                    msg.signed_messages[65], 20,
                    "incorrect value for signed_messages[65], expected 20, is {}",
                    msg.signed_messages[65]
                );
                assert_eq!(
                    msg.signed_messages[66], 168,
                    "incorrect value for signed_messages[66], expected 168, is {}",
                    msg.signed_messages[66]
                );
                assert_eq!(
                    msg.signed_messages[67], 132,
                    "incorrect value for signed_messages[67], expected 132, is {}",
                    msg.signed_messages[67]
                );
                assert_eq!(
                    msg.signed_messages[68], 141,
                    "incorrect value for signed_messages[68], expected 141, is {}",
                    msg.signed_messages[68]
                );
                assert_eq!(
                    msg.signed_messages[69], 102,
                    "incorrect value for signed_messages[69], expected 102, is {}",
                    msg.signed_messages[69]
                );
                assert_eq!(
                    msg.signed_messages[70], 50,
                    "incorrect value for signed_messages[70], expected 50, is {}",
                    msg.signed_messages[70]
                );
                assert_eq!(
                    msg.signed_messages[71], 48,
                    "incorrect value for signed_messages[71], expected 48, is {}",
                    msg.signed_messages[71]
                );
                assert_eq!(
                    msg.signed_messages[72], 71,
                    "incorrect value for signed_messages[72], expected 71, is {}",
                    msg.signed_messages[72]
                );
                assert_eq!(
                    msg.signed_messages[73], 147,
                    "incorrect value for signed_messages[73], expected 147, is {}",
                    msg.signed_messages[73]
                );
                assert_eq!(
                    msg.signed_messages[74], 53,
                    "incorrect value for signed_messages[74], expected 53, is {}",
                    msg.signed_messages[74]
                );
                assert_eq!(
                    msg.signed_messages[75], 87,
                    "incorrect value for signed_messages[75], expected 87, is {}",
                    msg.signed_messages[75]
                );
                assert_eq!(
                    msg.signed_messages[76], 1,
                    "incorrect value for signed_messages[76], expected 1, is {}",
                    msg.signed_messages[76]
                );
                assert_eq!(
                    msg.signed_messages[77], 108,
                    "incorrect value for signed_messages[77], expected 108, is {}",
                    msg.signed_messages[77]
                );
                assert_eq!(
                    msg.signed_messages[78], 138,
                    "incorrect value for signed_messages[78], expected 138, is {}",
                    msg.signed_messages[78]
                );
                assert_eq!(
                    msg.signed_messages[79], 36,
                    "incorrect value for signed_messages[79], expected 36, is {}",
                    msg.signed_messages[79]
                );
                assert_eq!(
                    msg.signed_messages[80], 134,
                    "incorrect value for signed_messages[80], expected 134, is {}",
                    msg.signed_messages[80]
                );
                assert_eq!(
                    msg.signed_messages[81], 139,
                    "incorrect value for signed_messages[81], expected 139, is {}",
                    msg.signed_messages[81]
                );
                assert_eq!(
                    msg.signed_messages[82], 163,
                    "incorrect value for signed_messages[82], expected 163, is {}",
                    msg.signed_messages[82]
                );
                assert_eq!(
                    msg.signed_messages[83], 82,
                    "incorrect value for signed_messages[83], expected 82, is {}",
                    msg.signed_messages[83]
                );
                assert_eq!(
                    msg.signed_messages[84], 43,
                    "incorrect value for signed_messages[84], expected 43, is {}",
                    msg.signed_messages[84]
                );
                assert_eq!(
                    msg.signed_messages[85], 52,
                    "incorrect value for signed_messages[85], expected 52, is {}",
                    msg.signed_messages[85]
                );
                assert_eq!(
                    msg.signed_messages[86], 150,
                    "incorrect value for signed_messages[86], expected 150, is {}",
                    msg.signed_messages[86]
                );
                assert_eq!(
                    msg.signed_messages[87], 12,
                    "incorrect value for signed_messages[87], expected 12, is {}",
                    msg.signed_messages[87]
                );
                assert_eq!(
                    msg.signed_messages[88], 30,
                    "incorrect value for signed_messages[88], expected 30, is {}",
                    msg.signed_messages[88]
                );
                assert_eq!(
                    msg.signed_messages[89], 110,
                    "incorrect value for signed_messages[89], expected 110, is {}",
                    msg.signed_messages[89]
                );
                assert_eq!(
                    msg.signed_messages[90], 156,
                    "incorrect value for signed_messages[90], expected 156, is {}",
                    msg.signed_messages[90]
                );
                assert_eq!(
                    msg.signed_messages[91], 107,
                    "incorrect value for signed_messages[91], expected 107, is {}",
                    msg.signed_messages[91]
                );
                assert_eq!(
                    msg.signed_messages[92], 120,
                    "incorrect value for signed_messages[92], expected 120, is {}",
                    msg.signed_messages[92]
                );
                assert_eq!(
                    msg.signed_messages[93], 91,
                    "incorrect value for signed_messages[93], expected 91, is {}",
                    msg.signed_messages[93]
                );
                assert_eq!(
                    msg.signed_messages[94], 122,
                    "incorrect value for signed_messages[94], expected 122, is {}",
                    msg.signed_messages[94]
                );
                assert_eq!(
                    msg.signed_messages[95], 69,
                    "incorrect value for signed_messages[95], expected 69, is {}",
                    msg.signed_messages[95]
                );
                assert_eq!(
                    msg.signed_messages[96], 164,
                    "incorrect value for signed_messages[96], expected 164, is {}",
                    msg.signed_messages[96]
                );
                assert_eq!(
                    msg.signed_messages[97], 170,
                    "incorrect value for signed_messages[97], expected 170, is {}",
                    msg.signed_messages[97]
                );
                assert_eq!(
                    msg.signed_messages[98], 116,
                    "incorrect value for signed_messages[98], expected 116, is {}",
                    msg.signed_messages[98]
                );
                assert_eq!(
                    msg.signed_messages[99], 25,
                    "incorrect value for signed_messages[99], expected 25, is {}",
                    msg.signed_messages[99]
                );
                assert_eq!(
                    msg.signed_messages[100], 94,
                    "incorrect value for signed_messages[100], expected 94, is {}",
                    msg.signed_messages[100]
                );
                assert_eq!(
                    msg.signed_messages[101], 5,
                    "incorrect value for signed_messages[101], expected 5, is {}",
                    msg.signed_messages[101]
                );
                assert_eq!(
                    msg.signed_messages[102], 22,
                    "incorrect value for signed_messages[102], expected 22, is {}",
                    msg.signed_messages[102]
                );
                assert_eq!(
                    msg.signed_messages[103], 24,
                    "incorrect value for signed_messages[103], expected 24, is {}",
                    msg.signed_messages[103]
                );
                assert_eq!(
                    msg.signed_messages[104], 162,
                    "incorrect value for signed_messages[104], expected 162, is {}",
                    msg.signed_messages[104]
                );
                assert_eq!(
                    msg.signed_messages[105], 175,
                    "incorrect value for signed_messages[105], expected 175, is {}",
                    msg.signed_messages[105]
                );
                assert_eq!(
                    msg.signed_messages[106], 38,
                    "incorrect value for signed_messages[106], expected 38, is {}",
                    msg.signed_messages[106]
                );
                assert_eq!(
                    msg.signed_messages[107], 157,
                    "incorrect value for signed_messages[107], expected 157, is {}",
                    msg.signed_messages[107]
                );
                assert_eq!(
                    msg.signed_messages[108], 98,
                    "incorrect value for signed_messages[108], expected 98, is {}",
                    msg.signed_messages[108]
                );
                assert_eq!(
                    msg.signed_messages[109], 44,
                    "incorrect value for signed_messages[109], expected 44, is {}",
                    msg.signed_messages[109]
                );
                assert_eq!(
                    msg.signed_messages[110], 160,
                    "incorrect value for signed_messages[110], expected 160, is {}",
                    msg.signed_messages[110]
                );
                assert_eq!(
                    msg.signed_messages[111], 47,
                    "incorrect value for signed_messages[111], expected 47, is {}",
                    msg.signed_messages[111]
                );
                assert_eq!(
                    msg.signed_messages[112], 97,
                    "incorrect value for signed_messages[112], expected 97, is {}",
                    msg.signed_messages[112]
                );
                assert_eq!(
                    msg.signed_messages[113], 142,
                    "incorrect value for signed_messages[113], expected 142, is {}",
                    msg.signed_messages[113]
                );
                assert_eq!(
                    msg.signed_messages[114], 8,
                    "incorrect value for signed_messages[114], expected 8, is {}",
                    msg.signed_messages[114]
                );
                assert_eq!(
                    msg.signed_messages[115], 74,
                    "incorrect value for signed_messages[115], expected 74, is {}",
                    msg.signed_messages[115]
                );
                assert_eq!(
                    msg.signed_messages[116], 13,
                    "incorrect value for signed_messages[116], expected 13, is {}",
                    msg.signed_messages[116]
                );
                assert_eq!(
                    msg.signed_messages[117], 177,
                    "incorrect value for signed_messages[117], expected 177, is {}",
                    msg.signed_messages[117]
                );
                assert_eq!(
                    msg.signed_messages[118], 15,
                    "incorrect value for signed_messages[118], expected 15, is {}",
                    msg.signed_messages[118]
                );
                assert_eq!(
                    msg.signed_messages[119], 128,
                    "incorrect value for signed_messages[119], expected 128, is {}",
                    msg.signed_messages[119]
                );
                assert_eq!(
                    msg.signed_messages[120], 26,
                    "incorrect value for signed_messages[120], expected 26, is {}",
                    msg.signed_messages[120]
                );
                assert_eq!(
                    msg.signed_messages[121], 131,
                    "incorrect value for signed_messages[121], expected 131, is {}",
                    msg.signed_messages[121]
                );
                assert_eq!(
                    msg.signed_messages[122], 154,
                    "incorrect value for signed_messages[122], expected 154, is {}",
                    msg.signed_messages[122]
                );
                assert_eq!(
                    msg.signed_messages[123], 65,
                    "incorrect value for signed_messages[123], expected 65, is {}",
                    msg.signed_messages[123]
                );
                assert_eq!(
                    msg.signed_messages[124], 169,
                    "incorrect value for signed_messages[124], expected 169, is {}",
                    msg.signed_messages[124]
                );
                assert_eq!(
                    msg.signed_messages[125], 55,
                    "incorrect value for signed_messages[125], expected 55, is {}",
                    msg.signed_messages[125]
                );
                assert_eq!(
                    msg.signed_messages[126], 136,
                    "incorrect value for signed_messages[126], expected 136, is {}",
                    msg.signed_messages[126]
                );
                assert_eq!(
                    msg.signed_messages[127], 125,
                    "incorrect value for signed_messages[127], expected 125, is {}",
                    msg.signed_messages[127]
                );
                assert_eq!(
                    msg.signed_messages[128], 171,
                    "incorrect value for signed_messages[128], expected 171, is {}",
                    msg.signed_messages[128]
                );
                assert_eq!(
                    msg.signed_messages[129], 161,
                    "incorrect value for signed_messages[129], expected 161, is {}",
                    msg.signed_messages[129]
                );
                assert_eq!(
                    msg.signed_messages[130], 29,
                    "incorrect value for signed_messages[130], expected 29, is {}",
                    msg.signed_messages[130]
                );
                assert_eq!(
                    msg.signed_messages[131], 129,
                    "incorrect value for signed_messages[131], expected 129, is {}",
                    msg.signed_messages[131]
                );
                assert_eq!(
                    msg.signed_messages[132], 151,
                    "incorrect value for signed_messages[132], expected 151, is {}",
                    msg.signed_messages[132]
                );
                assert_eq!(
                    msg.signed_messages[133], 68,
                    "incorrect value for signed_messages[133], expected 68, is {}",
                    msg.signed_messages[133]
                );
                assert_eq!(
                    msg.signed_messages[134], 166,
                    "incorrect value for signed_messages[134], expected 166, is {}",
                    msg.signed_messages[134]
                );
                assert_eq!(
                    msg.signed_messages[135], 51,
                    "incorrect value for signed_messages[135], expected 51, is {}",
                    msg.signed_messages[135]
                );
                assert_eq!(
                    msg.signed_messages[136], 70,
                    "incorrect value for signed_messages[136], expected 70, is {}",
                    msg.signed_messages[136]
                );
                assert_eq!(
                    msg.signed_messages[137], 45,
                    "incorrect value for signed_messages[137], expected 45, is {}",
                    msg.signed_messages[137]
                );
                assert_eq!(
                    msg.signed_messages[138], 56,
                    "incorrect value for signed_messages[138], expected 56, is {}",
                    msg.signed_messages[138]
                );
                assert_eq!(
                    msg.signed_messages[139], 79,
                    "incorrect value for signed_messages[139], expected 79, is {}",
                    msg.signed_messages[139]
                );
                assert_eq!(
                    msg.signed_messages[140], 149,
                    "incorrect value for signed_messages[140], expected 149, is {}",
                    msg.signed_messages[140]
                );
                assert_eq!(
                    msg.signed_messages[141], 99,
                    "incorrect value for signed_messages[141], expected 99, is {}",
                    msg.signed_messages[141]
                );
                assert_eq!(
                    msg.signed_messages[142], 42,
                    "incorrect value for signed_messages[142], expected 42, is {}",
                    msg.signed_messages[142]
                );
                assert_eq!(
                    msg.signed_messages[143], 101,
                    "incorrect value for signed_messages[143], expected 101, is {}",
                    msg.signed_messages[143]
                );
                assert_eq!(
                    msg.signed_messages[144], 152,
                    "incorrect value for signed_messages[144], expected 152, is {}",
                    msg.signed_messages[144]
                );
                assert_eq!(
                    msg.signed_messages[145], 39,
                    "incorrect value for signed_messages[145], expected 39, is {}",
                    msg.signed_messages[145]
                );
                assert_eq!(
                    msg.signed_messages[146], 89,
                    "incorrect value for signed_messages[146], expected 89, is {}",
                    msg.signed_messages[146]
                );
                assert_eq!(
                    msg.signed_messages[147], 180,
                    "incorrect value for signed_messages[147], expected 180, is {}",
                    msg.signed_messages[147]
                );
                assert_eq!(
                    msg.signed_messages[148], 64,
                    "incorrect value for signed_messages[148], expected 64, is {}",
                    msg.signed_messages[148]
                );
                assert_eq!(
                    msg.signed_messages[149], 49,
                    "incorrect value for signed_messages[149], expected 49, is {}",
                    msg.signed_messages[149]
                );
                assert_eq!(
                    msg.signed_messages[150], 6,
                    "incorrect value for signed_messages[150], expected 6, is {}",
                    msg.signed_messages[150]
                );
                assert_eq!(
                    msg.signed_messages[151], 80,
                    "incorrect value for signed_messages[151], expected 80, is {}",
                    msg.signed_messages[151]
                );
                assert_eq!(
                    msg.signed_messages[152], 172,
                    "incorrect value for signed_messages[152], expected 172, is {}",
                    msg.signed_messages[152]
                );
                assert_eq!(
                    msg.signed_messages[153], 32,
                    "incorrect value for signed_messages[153], expected 32, is {}",
                    msg.signed_messages[153]
                );
                assert_eq!(
                    msg.signed_messages[154], 109,
                    "incorrect value for signed_messages[154], expected 109, is {}",
                    msg.signed_messages[154]
                );
                assert_eq!(
                    msg.signed_messages[155], 2,
                    "incorrect value for signed_messages[155], expected 2, is {}",
                    msg.signed_messages[155]
                );
                assert_eq!(
                    msg.signed_messages[156], 119,
                    "incorrect value for signed_messages[156], expected 119, is {}",
                    msg.signed_messages[156]
                );
                assert_eq!(
                    msg.signed_messages[157], 93,
                    "incorrect value for signed_messages[157], expected 93, is {}",
                    msg.signed_messages[157]
                );
                assert_eq!(
                    msg.signed_messages[158], 176,
                    "incorrect value for signed_messages[158], expected 176, is {}",
                    msg.signed_messages[158]
                );
                assert_eq!(
                    msg.signed_messages[159], 0,
                    "incorrect value for signed_messages[159], expected 0, is {}",
                    msg.signed_messages[159]
                );
                assert_eq!(
                    msg.signed_messages[160], 33,
                    "incorrect value for signed_messages[160], expected 33, is {}",
                    msg.signed_messages[160]
                );
                assert_eq!(
                    msg.signed_messages[161], 57,
                    "incorrect value for signed_messages[161], expected 57, is {}",
                    msg.signed_messages[161]
                );
                assert_eq!(
                    msg.signed_messages[162], 34,
                    "incorrect value for signed_messages[162], expected 34, is {}",
                    msg.signed_messages[162]
                );
                assert_eq!(
                    msg.signed_messages[163], 18,
                    "incorrect value for signed_messages[163], expected 18, is {}",
                    msg.signed_messages[163]
                );
                assert_eq!(
                    msg.signed_messages[164], 85,
                    "incorrect value for signed_messages[164], expected 85, is {}",
                    msg.signed_messages[164]
                );
                assert_eq!(
                    msg.signed_messages[165], 121,
                    "incorrect value for signed_messages[165], expected 121, is {}",
                    msg.signed_messages[165]
                );
                assert_eq!(
                    msg.signed_messages[166], 137,
                    "incorrect value for signed_messages[166], expected 137, is {}",
                    msg.signed_messages[166]
                );
                assert_eq!(
                    msg.signed_messages[167], 83,
                    "incorrect value for signed_messages[167], expected 83, is {}",
                    msg.signed_messages[167]
                );
                assert_eq!(
                    msg.signed_messages[168], 111,
                    "incorrect value for signed_messages[168], expected 111, is {}",
                    msg.signed_messages[168]
                );
                assert_eq!(
                    msg.signed_messages[169], 59,
                    "incorrect value for signed_messages[169], expected 59, is {}",
                    msg.signed_messages[169]
                );
                assert_eq!(
                    msg.signed_messages[170], 7,
                    "incorrect value for signed_messages[170], expected 7, is {}",
                    msg.signed_messages[170]
                );
                assert_eq!(
                    msg.signed_messages[171], 77,
                    "incorrect value for signed_messages[171], expected 77, is {}",
                    msg.signed_messages[171]
                );
                assert_eq!(
                    msg.signed_messages[172], 4,
                    "incorrect value for signed_messages[172], expected 4, is {}",
                    msg.signed_messages[172]
                );
                assert_eq!(
                    msg.signed_messages[173], 117,
                    "incorrect value for signed_messages[173], expected 117, is {}",
                    msg.signed_messages[173]
                );
                assert_eq!(
                    msg.signed_messages[174], 159,
                    "incorrect value for signed_messages[174], expected 159, is {}",
                    msg.signed_messages[174]
                );
                assert_eq!(
                    msg.signed_messages[175], 148,
                    "incorrect value for signed_messages[175], expected 148, is {}",
                    msg.signed_messages[175]
                );
                assert_eq!(
                    msg.signed_messages[176], 35,
                    "incorrect value for signed_messages[176], expected 35, is {}",
                    msg.signed_messages[176]
                );
                assert_eq!(
                    msg.signed_messages[177], 61,
                    "incorrect value for signed_messages[177], expected 61, is {}",
                    msg.signed_messages[177]
                );
                assert_eq!(
                    msg.signed_messages[178], 41,
                    "incorrect value for signed_messages[178], expected 41, is {}",
                    msg.signed_messages[178]
                );
                assert_eq!(
                    msg.signed_messages[179], 67,
                    "incorrect value for signed_messages[179], expected 67, is {}",
                    msg.signed_messages[179]
                );
                assert_eq!(
                    msg.signed_messages[180], 46,
                    "incorrect value for signed_messages[180], expected 46, is {}",
                    msg.signed_messages[180]
                );
                assert_eq!(
                    msg.signed_messages[181], 127,
                    "incorrect value for signed_messages[181], expected 127, is {}",
                    msg.signed_messages[181]
                );
                assert_eq!(
                    msg.signed_messages[182], 75,
                    "incorrect value for signed_messages[182], expected 75, is {}",
                    msg.signed_messages[182]
                );
                assert_eq!(
                    msg.signed_messages[183], 174,
                    "incorrect value for signed_messages[183], expected 174, is {}",
                    msg.signed_messages[183]
                );
                assert_eq!(
                    msg.stream_counter, 1,
                    "incorrect value for stream_counter, expected 1, is {}",
                    msg.stream_counter
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEcdsaSignatureDepA"),
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
fn test_json2sbp_auto_check_sbp_signing_msg_ecdsa_signature_dep_a() {
    {
        let json_input = r#"{"preamble": 85, "msg_type": 3078, "sender": 66, "length": 255, "payload": "AAECAQIDBAABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcKFRc/jCWCahwopbNJsjx+ck5xG18DPmiRYBNcew5ambcJSFF2cHwQtkySczqQEWlCH4c2ZFS1ZwtYhZunrY9WnhSohI1mMjBHkzVXAWyKJIaLo1IrNJYMHm6ca3hbekWkqnQZXgUWGKKvJp1iLKAvYY4ISg2xD4Aag5pBqTeIfauhHYGXRKYzRi04T5VjKmWYJ1m0QDEGUKwgbQJ3XbAAITkiElV5iVNvOwdNBHWflCM9KUMuf0uu", "crc": 44129, "flags": 0, "stream_counter": 1, "on_demand_counter": 2, "certificate_id": [1, 2, 3, 4], "signature": [0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7], "signed_messages": [10, 21, 23, 63, 140, 37, 130, 106, 28, 40, 165, 179, 73, 178, 60, 126, 114, 78, 113, 27, 95, 3, 62, 104, 145, 96, 19, 92, 123, 14, 90, 153, 183, 9, 72, 81, 118, 112, 124, 16, 182, 76, 146, 115, 58, 144, 17, 105, 66, 31, 135, 54, 100, 84, 181, 103, 11, 88, 133, 155, 167, 173, 143, 86, 158, 20, 168, 132, 141, 102, 50, 48, 71, 147, 53, 87, 1, 108, 138, 36, 134, 139, 163, 82, 43, 52, 150, 12, 30, 110, 156, 107, 120, 91, 122, 69, 164, 170, 116, 25, 94, 5, 22, 24, 162, 175, 38, 157, 98, 44, 160, 47, 97, 142, 8, 74, 13, 177, 15, 128, 26, 131, 154, 65, 169, 55, 136, 125, 171, 161, 29, 129, 151, 68, 166, 51, 70, 45, 56, 79, 149, 99, 42, 101, 152, 39, 89, 180, 64, 49, 6, 80, 172, 32, 109, 2, 119, 93, 176, 0, 33, 57, 34, 18, 85, 121, 137, 83, 111, 59, 7, 77, 4, 117, 159, 148, 35, 61, 41, 67, 46, 127, 75, 174]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgEcdsaSignatureDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC06,
                    "Incorrect message type, expected 0xC06, is {}",
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
                    msg.signature[8], 0,
                    "incorrect value for signature[8], expected 0, is {}",
                    msg.signature[8]
                );
                assert_eq!(
                    msg.signature[9], 1,
                    "incorrect value for signature[9], expected 1, is {}",
                    msg.signature[9]
                );
                assert_eq!(
                    msg.signature[10], 2,
                    "incorrect value for signature[10], expected 2, is {}",
                    msg.signature[10]
                );
                assert_eq!(
                    msg.signature[11], 3,
                    "incorrect value for signature[11], expected 3, is {}",
                    msg.signature[11]
                );
                assert_eq!(
                    msg.signature[12], 4,
                    "incorrect value for signature[12], expected 4, is {}",
                    msg.signature[12]
                );
                assert_eq!(
                    msg.signature[13], 5,
                    "incorrect value for signature[13], expected 5, is {}",
                    msg.signature[13]
                );
                assert_eq!(
                    msg.signature[14], 6,
                    "incorrect value for signature[14], expected 6, is {}",
                    msg.signature[14]
                );
                assert_eq!(
                    msg.signature[15], 7,
                    "incorrect value for signature[15], expected 7, is {}",
                    msg.signature[15]
                );
                assert_eq!(
                    msg.signature[16], 0,
                    "incorrect value for signature[16], expected 0, is {}",
                    msg.signature[16]
                );
                assert_eq!(
                    msg.signature[17], 1,
                    "incorrect value for signature[17], expected 1, is {}",
                    msg.signature[17]
                );
                assert_eq!(
                    msg.signature[18], 2,
                    "incorrect value for signature[18], expected 2, is {}",
                    msg.signature[18]
                );
                assert_eq!(
                    msg.signature[19], 3,
                    "incorrect value for signature[19], expected 3, is {}",
                    msg.signature[19]
                );
                assert_eq!(
                    msg.signature[20], 4,
                    "incorrect value for signature[20], expected 4, is {}",
                    msg.signature[20]
                );
                assert_eq!(
                    msg.signature[21], 5,
                    "incorrect value for signature[21], expected 5, is {}",
                    msg.signature[21]
                );
                assert_eq!(
                    msg.signature[22], 6,
                    "incorrect value for signature[22], expected 6, is {}",
                    msg.signature[22]
                );
                assert_eq!(
                    msg.signature[23], 7,
                    "incorrect value for signature[23], expected 7, is {}",
                    msg.signature[23]
                );
                assert_eq!(
                    msg.signature[24], 0,
                    "incorrect value for signature[24], expected 0, is {}",
                    msg.signature[24]
                );
                assert_eq!(
                    msg.signature[25], 1,
                    "incorrect value for signature[25], expected 1, is {}",
                    msg.signature[25]
                );
                assert_eq!(
                    msg.signature[26], 2,
                    "incorrect value for signature[26], expected 2, is {}",
                    msg.signature[26]
                );
                assert_eq!(
                    msg.signature[27], 3,
                    "incorrect value for signature[27], expected 3, is {}",
                    msg.signature[27]
                );
                assert_eq!(
                    msg.signature[28], 4,
                    "incorrect value for signature[28], expected 4, is {}",
                    msg.signature[28]
                );
                assert_eq!(
                    msg.signature[29], 5,
                    "incorrect value for signature[29], expected 5, is {}",
                    msg.signature[29]
                );
                assert_eq!(
                    msg.signature[30], 6,
                    "incorrect value for signature[30], expected 6, is {}",
                    msg.signature[30]
                );
                assert_eq!(
                    msg.signature[31], 7,
                    "incorrect value for signature[31], expected 7, is {}",
                    msg.signature[31]
                );
                assert_eq!(
                    msg.signature[32], 0,
                    "incorrect value for signature[32], expected 0, is {}",
                    msg.signature[32]
                );
                assert_eq!(
                    msg.signature[33], 1,
                    "incorrect value for signature[33], expected 1, is {}",
                    msg.signature[33]
                );
                assert_eq!(
                    msg.signature[34], 2,
                    "incorrect value for signature[34], expected 2, is {}",
                    msg.signature[34]
                );
                assert_eq!(
                    msg.signature[35], 3,
                    "incorrect value for signature[35], expected 3, is {}",
                    msg.signature[35]
                );
                assert_eq!(
                    msg.signature[36], 4,
                    "incorrect value for signature[36], expected 4, is {}",
                    msg.signature[36]
                );
                assert_eq!(
                    msg.signature[37], 5,
                    "incorrect value for signature[37], expected 5, is {}",
                    msg.signature[37]
                );
                assert_eq!(
                    msg.signature[38], 6,
                    "incorrect value for signature[38], expected 6, is {}",
                    msg.signature[38]
                );
                assert_eq!(
                    msg.signature[39], 7,
                    "incorrect value for signature[39], expected 7, is {}",
                    msg.signature[39]
                );
                assert_eq!(
                    msg.signature[40], 0,
                    "incorrect value for signature[40], expected 0, is {}",
                    msg.signature[40]
                );
                assert_eq!(
                    msg.signature[41], 1,
                    "incorrect value for signature[41], expected 1, is {}",
                    msg.signature[41]
                );
                assert_eq!(
                    msg.signature[42], 2,
                    "incorrect value for signature[42], expected 2, is {}",
                    msg.signature[42]
                );
                assert_eq!(
                    msg.signature[43], 3,
                    "incorrect value for signature[43], expected 3, is {}",
                    msg.signature[43]
                );
                assert_eq!(
                    msg.signature[44], 4,
                    "incorrect value for signature[44], expected 4, is {}",
                    msg.signature[44]
                );
                assert_eq!(
                    msg.signature[45], 5,
                    "incorrect value for signature[45], expected 5, is {}",
                    msg.signature[45]
                );
                assert_eq!(
                    msg.signature[46], 6,
                    "incorrect value for signature[46], expected 6, is {}",
                    msg.signature[46]
                );
                assert_eq!(
                    msg.signature[47], 7,
                    "incorrect value for signature[47], expected 7, is {}",
                    msg.signature[47]
                );
                assert_eq!(
                    msg.signature[48], 0,
                    "incorrect value for signature[48], expected 0, is {}",
                    msg.signature[48]
                );
                assert_eq!(
                    msg.signature[49], 1,
                    "incorrect value for signature[49], expected 1, is {}",
                    msg.signature[49]
                );
                assert_eq!(
                    msg.signature[50], 2,
                    "incorrect value for signature[50], expected 2, is {}",
                    msg.signature[50]
                );
                assert_eq!(
                    msg.signature[51], 3,
                    "incorrect value for signature[51], expected 3, is {}",
                    msg.signature[51]
                );
                assert_eq!(
                    msg.signature[52], 4,
                    "incorrect value for signature[52], expected 4, is {}",
                    msg.signature[52]
                );
                assert_eq!(
                    msg.signature[53], 5,
                    "incorrect value for signature[53], expected 5, is {}",
                    msg.signature[53]
                );
                assert_eq!(
                    msg.signature[54], 6,
                    "incorrect value for signature[54], expected 6, is {}",
                    msg.signature[54]
                );
                assert_eq!(
                    msg.signature[55], 7,
                    "incorrect value for signature[55], expected 7, is {}",
                    msg.signature[55]
                );
                assert_eq!(
                    msg.signature[56], 0,
                    "incorrect value for signature[56], expected 0, is {}",
                    msg.signature[56]
                );
                assert_eq!(
                    msg.signature[57], 1,
                    "incorrect value for signature[57], expected 1, is {}",
                    msg.signature[57]
                );
                assert_eq!(
                    msg.signature[58], 2,
                    "incorrect value for signature[58], expected 2, is {}",
                    msg.signature[58]
                );
                assert_eq!(
                    msg.signature[59], 3,
                    "incorrect value for signature[59], expected 3, is {}",
                    msg.signature[59]
                );
                assert_eq!(
                    msg.signature[60], 4,
                    "incorrect value for signature[60], expected 4, is {}",
                    msg.signature[60]
                );
                assert_eq!(
                    msg.signature[61], 5,
                    "incorrect value for signature[61], expected 5, is {}",
                    msg.signature[61]
                );
                assert_eq!(
                    msg.signature[62], 6,
                    "incorrect value for signature[62], expected 6, is {}",
                    msg.signature[62]
                );
                assert_eq!(
                    msg.signature[63], 7,
                    "incorrect value for signature[63], expected 7, is {}",
                    msg.signature[63]
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
                    msg.signed_messages[3], 63,
                    "incorrect value for signed_messages[3], expected 63, is {}",
                    msg.signed_messages[3]
                );
                assert_eq!(
                    msg.signed_messages[4], 140,
                    "incorrect value for signed_messages[4], expected 140, is {}",
                    msg.signed_messages[4]
                );
                assert_eq!(
                    msg.signed_messages[5], 37,
                    "incorrect value for signed_messages[5], expected 37, is {}",
                    msg.signed_messages[5]
                );
                assert_eq!(
                    msg.signed_messages[6], 130,
                    "incorrect value for signed_messages[6], expected 130, is {}",
                    msg.signed_messages[6]
                );
                assert_eq!(
                    msg.signed_messages[7], 106,
                    "incorrect value for signed_messages[7], expected 106, is {}",
                    msg.signed_messages[7]
                );
                assert_eq!(
                    msg.signed_messages[8], 28,
                    "incorrect value for signed_messages[8], expected 28, is {}",
                    msg.signed_messages[8]
                );
                assert_eq!(
                    msg.signed_messages[9], 40,
                    "incorrect value for signed_messages[9], expected 40, is {}",
                    msg.signed_messages[9]
                );
                assert_eq!(
                    msg.signed_messages[10], 165,
                    "incorrect value for signed_messages[10], expected 165, is {}",
                    msg.signed_messages[10]
                );
                assert_eq!(
                    msg.signed_messages[11], 179,
                    "incorrect value for signed_messages[11], expected 179, is {}",
                    msg.signed_messages[11]
                );
                assert_eq!(
                    msg.signed_messages[12], 73,
                    "incorrect value for signed_messages[12], expected 73, is {}",
                    msg.signed_messages[12]
                );
                assert_eq!(
                    msg.signed_messages[13], 178,
                    "incorrect value for signed_messages[13], expected 178, is {}",
                    msg.signed_messages[13]
                );
                assert_eq!(
                    msg.signed_messages[14], 60,
                    "incorrect value for signed_messages[14], expected 60, is {}",
                    msg.signed_messages[14]
                );
                assert_eq!(
                    msg.signed_messages[15], 126,
                    "incorrect value for signed_messages[15], expected 126, is {}",
                    msg.signed_messages[15]
                );
                assert_eq!(
                    msg.signed_messages[16], 114,
                    "incorrect value for signed_messages[16], expected 114, is {}",
                    msg.signed_messages[16]
                );
                assert_eq!(
                    msg.signed_messages[17], 78,
                    "incorrect value for signed_messages[17], expected 78, is {}",
                    msg.signed_messages[17]
                );
                assert_eq!(
                    msg.signed_messages[18], 113,
                    "incorrect value for signed_messages[18], expected 113, is {}",
                    msg.signed_messages[18]
                );
                assert_eq!(
                    msg.signed_messages[19], 27,
                    "incorrect value for signed_messages[19], expected 27, is {}",
                    msg.signed_messages[19]
                );
                assert_eq!(
                    msg.signed_messages[20], 95,
                    "incorrect value for signed_messages[20], expected 95, is {}",
                    msg.signed_messages[20]
                );
                assert_eq!(
                    msg.signed_messages[21], 3,
                    "incorrect value for signed_messages[21], expected 3, is {}",
                    msg.signed_messages[21]
                );
                assert_eq!(
                    msg.signed_messages[22], 62,
                    "incorrect value for signed_messages[22], expected 62, is {}",
                    msg.signed_messages[22]
                );
                assert_eq!(
                    msg.signed_messages[23], 104,
                    "incorrect value for signed_messages[23], expected 104, is {}",
                    msg.signed_messages[23]
                );
                assert_eq!(
                    msg.signed_messages[24], 145,
                    "incorrect value for signed_messages[24], expected 145, is {}",
                    msg.signed_messages[24]
                );
                assert_eq!(
                    msg.signed_messages[25], 96,
                    "incorrect value for signed_messages[25], expected 96, is {}",
                    msg.signed_messages[25]
                );
                assert_eq!(
                    msg.signed_messages[26], 19,
                    "incorrect value for signed_messages[26], expected 19, is {}",
                    msg.signed_messages[26]
                );
                assert_eq!(
                    msg.signed_messages[27], 92,
                    "incorrect value for signed_messages[27], expected 92, is {}",
                    msg.signed_messages[27]
                );
                assert_eq!(
                    msg.signed_messages[28], 123,
                    "incorrect value for signed_messages[28], expected 123, is {}",
                    msg.signed_messages[28]
                );
                assert_eq!(
                    msg.signed_messages[29], 14,
                    "incorrect value for signed_messages[29], expected 14, is {}",
                    msg.signed_messages[29]
                );
                assert_eq!(
                    msg.signed_messages[30], 90,
                    "incorrect value for signed_messages[30], expected 90, is {}",
                    msg.signed_messages[30]
                );
                assert_eq!(
                    msg.signed_messages[31], 153,
                    "incorrect value for signed_messages[31], expected 153, is {}",
                    msg.signed_messages[31]
                );
                assert_eq!(
                    msg.signed_messages[32], 183,
                    "incorrect value for signed_messages[32], expected 183, is {}",
                    msg.signed_messages[32]
                );
                assert_eq!(
                    msg.signed_messages[33], 9,
                    "incorrect value for signed_messages[33], expected 9, is {}",
                    msg.signed_messages[33]
                );
                assert_eq!(
                    msg.signed_messages[34], 72,
                    "incorrect value for signed_messages[34], expected 72, is {}",
                    msg.signed_messages[34]
                );
                assert_eq!(
                    msg.signed_messages[35], 81,
                    "incorrect value for signed_messages[35], expected 81, is {}",
                    msg.signed_messages[35]
                );
                assert_eq!(
                    msg.signed_messages[36], 118,
                    "incorrect value for signed_messages[36], expected 118, is {}",
                    msg.signed_messages[36]
                );
                assert_eq!(
                    msg.signed_messages[37], 112,
                    "incorrect value for signed_messages[37], expected 112, is {}",
                    msg.signed_messages[37]
                );
                assert_eq!(
                    msg.signed_messages[38], 124,
                    "incorrect value for signed_messages[38], expected 124, is {}",
                    msg.signed_messages[38]
                );
                assert_eq!(
                    msg.signed_messages[39], 16,
                    "incorrect value for signed_messages[39], expected 16, is {}",
                    msg.signed_messages[39]
                );
                assert_eq!(
                    msg.signed_messages[40], 182,
                    "incorrect value for signed_messages[40], expected 182, is {}",
                    msg.signed_messages[40]
                );
                assert_eq!(
                    msg.signed_messages[41], 76,
                    "incorrect value for signed_messages[41], expected 76, is {}",
                    msg.signed_messages[41]
                );
                assert_eq!(
                    msg.signed_messages[42], 146,
                    "incorrect value for signed_messages[42], expected 146, is {}",
                    msg.signed_messages[42]
                );
                assert_eq!(
                    msg.signed_messages[43], 115,
                    "incorrect value for signed_messages[43], expected 115, is {}",
                    msg.signed_messages[43]
                );
                assert_eq!(
                    msg.signed_messages[44], 58,
                    "incorrect value for signed_messages[44], expected 58, is {}",
                    msg.signed_messages[44]
                );
                assert_eq!(
                    msg.signed_messages[45], 144,
                    "incorrect value for signed_messages[45], expected 144, is {}",
                    msg.signed_messages[45]
                );
                assert_eq!(
                    msg.signed_messages[46], 17,
                    "incorrect value for signed_messages[46], expected 17, is {}",
                    msg.signed_messages[46]
                );
                assert_eq!(
                    msg.signed_messages[47], 105,
                    "incorrect value for signed_messages[47], expected 105, is {}",
                    msg.signed_messages[47]
                );
                assert_eq!(
                    msg.signed_messages[48], 66,
                    "incorrect value for signed_messages[48], expected 66, is {}",
                    msg.signed_messages[48]
                );
                assert_eq!(
                    msg.signed_messages[49], 31,
                    "incorrect value for signed_messages[49], expected 31, is {}",
                    msg.signed_messages[49]
                );
                assert_eq!(
                    msg.signed_messages[50], 135,
                    "incorrect value for signed_messages[50], expected 135, is {}",
                    msg.signed_messages[50]
                );
                assert_eq!(
                    msg.signed_messages[51], 54,
                    "incorrect value for signed_messages[51], expected 54, is {}",
                    msg.signed_messages[51]
                );
                assert_eq!(
                    msg.signed_messages[52], 100,
                    "incorrect value for signed_messages[52], expected 100, is {}",
                    msg.signed_messages[52]
                );
                assert_eq!(
                    msg.signed_messages[53], 84,
                    "incorrect value for signed_messages[53], expected 84, is {}",
                    msg.signed_messages[53]
                );
                assert_eq!(
                    msg.signed_messages[54], 181,
                    "incorrect value for signed_messages[54], expected 181, is {}",
                    msg.signed_messages[54]
                );
                assert_eq!(
                    msg.signed_messages[55], 103,
                    "incorrect value for signed_messages[55], expected 103, is {}",
                    msg.signed_messages[55]
                );
                assert_eq!(
                    msg.signed_messages[56], 11,
                    "incorrect value for signed_messages[56], expected 11, is {}",
                    msg.signed_messages[56]
                );
                assert_eq!(
                    msg.signed_messages[57], 88,
                    "incorrect value for signed_messages[57], expected 88, is {}",
                    msg.signed_messages[57]
                );
                assert_eq!(
                    msg.signed_messages[58], 133,
                    "incorrect value for signed_messages[58], expected 133, is {}",
                    msg.signed_messages[58]
                );
                assert_eq!(
                    msg.signed_messages[59], 155,
                    "incorrect value for signed_messages[59], expected 155, is {}",
                    msg.signed_messages[59]
                );
                assert_eq!(
                    msg.signed_messages[60], 167,
                    "incorrect value for signed_messages[60], expected 167, is {}",
                    msg.signed_messages[60]
                );
                assert_eq!(
                    msg.signed_messages[61], 173,
                    "incorrect value for signed_messages[61], expected 173, is {}",
                    msg.signed_messages[61]
                );
                assert_eq!(
                    msg.signed_messages[62], 143,
                    "incorrect value for signed_messages[62], expected 143, is {}",
                    msg.signed_messages[62]
                );
                assert_eq!(
                    msg.signed_messages[63], 86,
                    "incorrect value for signed_messages[63], expected 86, is {}",
                    msg.signed_messages[63]
                );
                assert_eq!(
                    msg.signed_messages[64], 158,
                    "incorrect value for signed_messages[64], expected 158, is {}",
                    msg.signed_messages[64]
                );
                assert_eq!(
                    msg.signed_messages[65], 20,
                    "incorrect value for signed_messages[65], expected 20, is {}",
                    msg.signed_messages[65]
                );
                assert_eq!(
                    msg.signed_messages[66], 168,
                    "incorrect value for signed_messages[66], expected 168, is {}",
                    msg.signed_messages[66]
                );
                assert_eq!(
                    msg.signed_messages[67], 132,
                    "incorrect value for signed_messages[67], expected 132, is {}",
                    msg.signed_messages[67]
                );
                assert_eq!(
                    msg.signed_messages[68], 141,
                    "incorrect value for signed_messages[68], expected 141, is {}",
                    msg.signed_messages[68]
                );
                assert_eq!(
                    msg.signed_messages[69], 102,
                    "incorrect value for signed_messages[69], expected 102, is {}",
                    msg.signed_messages[69]
                );
                assert_eq!(
                    msg.signed_messages[70], 50,
                    "incorrect value for signed_messages[70], expected 50, is {}",
                    msg.signed_messages[70]
                );
                assert_eq!(
                    msg.signed_messages[71], 48,
                    "incorrect value for signed_messages[71], expected 48, is {}",
                    msg.signed_messages[71]
                );
                assert_eq!(
                    msg.signed_messages[72], 71,
                    "incorrect value for signed_messages[72], expected 71, is {}",
                    msg.signed_messages[72]
                );
                assert_eq!(
                    msg.signed_messages[73], 147,
                    "incorrect value for signed_messages[73], expected 147, is {}",
                    msg.signed_messages[73]
                );
                assert_eq!(
                    msg.signed_messages[74], 53,
                    "incorrect value for signed_messages[74], expected 53, is {}",
                    msg.signed_messages[74]
                );
                assert_eq!(
                    msg.signed_messages[75], 87,
                    "incorrect value for signed_messages[75], expected 87, is {}",
                    msg.signed_messages[75]
                );
                assert_eq!(
                    msg.signed_messages[76], 1,
                    "incorrect value for signed_messages[76], expected 1, is {}",
                    msg.signed_messages[76]
                );
                assert_eq!(
                    msg.signed_messages[77], 108,
                    "incorrect value for signed_messages[77], expected 108, is {}",
                    msg.signed_messages[77]
                );
                assert_eq!(
                    msg.signed_messages[78], 138,
                    "incorrect value for signed_messages[78], expected 138, is {}",
                    msg.signed_messages[78]
                );
                assert_eq!(
                    msg.signed_messages[79], 36,
                    "incorrect value for signed_messages[79], expected 36, is {}",
                    msg.signed_messages[79]
                );
                assert_eq!(
                    msg.signed_messages[80], 134,
                    "incorrect value for signed_messages[80], expected 134, is {}",
                    msg.signed_messages[80]
                );
                assert_eq!(
                    msg.signed_messages[81], 139,
                    "incorrect value for signed_messages[81], expected 139, is {}",
                    msg.signed_messages[81]
                );
                assert_eq!(
                    msg.signed_messages[82], 163,
                    "incorrect value for signed_messages[82], expected 163, is {}",
                    msg.signed_messages[82]
                );
                assert_eq!(
                    msg.signed_messages[83], 82,
                    "incorrect value for signed_messages[83], expected 82, is {}",
                    msg.signed_messages[83]
                );
                assert_eq!(
                    msg.signed_messages[84], 43,
                    "incorrect value for signed_messages[84], expected 43, is {}",
                    msg.signed_messages[84]
                );
                assert_eq!(
                    msg.signed_messages[85], 52,
                    "incorrect value for signed_messages[85], expected 52, is {}",
                    msg.signed_messages[85]
                );
                assert_eq!(
                    msg.signed_messages[86], 150,
                    "incorrect value for signed_messages[86], expected 150, is {}",
                    msg.signed_messages[86]
                );
                assert_eq!(
                    msg.signed_messages[87], 12,
                    "incorrect value for signed_messages[87], expected 12, is {}",
                    msg.signed_messages[87]
                );
                assert_eq!(
                    msg.signed_messages[88], 30,
                    "incorrect value for signed_messages[88], expected 30, is {}",
                    msg.signed_messages[88]
                );
                assert_eq!(
                    msg.signed_messages[89], 110,
                    "incorrect value for signed_messages[89], expected 110, is {}",
                    msg.signed_messages[89]
                );
                assert_eq!(
                    msg.signed_messages[90], 156,
                    "incorrect value for signed_messages[90], expected 156, is {}",
                    msg.signed_messages[90]
                );
                assert_eq!(
                    msg.signed_messages[91], 107,
                    "incorrect value for signed_messages[91], expected 107, is {}",
                    msg.signed_messages[91]
                );
                assert_eq!(
                    msg.signed_messages[92], 120,
                    "incorrect value for signed_messages[92], expected 120, is {}",
                    msg.signed_messages[92]
                );
                assert_eq!(
                    msg.signed_messages[93], 91,
                    "incorrect value for signed_messages[93], expected 91, is {}",
                    msg.signed_messages[93]
                );
                assert_eq!(
                    msg.signed_messages[94], 122,
                    "incorrect value for signed_messages[94], expected 122, is {}",
                    msg.signed_messages[94]
                );
                assert_eq!(
                    msg.signed_messages[95], 69,
                    "incorrect value for signed_messages[95], expected 69, is {}",
                    msg.signed_messages[95]
                );
                assert_eq!(
                    msg.signed_messages[96], 164,
                    "incorrect value for signed_messages[96], expected 164, is {}",
                    msg.signed_messages[96]
                );
                assert_eq!(
                    msg.signed_messages[97], 170,
                    "incorrect value for signed_messages[97], expected 170, is {}",
                    msg.signed_messages[97]
                );
                assert_eq!(
                    msg.signed_messages[98], 116,
                    "incorrect value for signed_messages[98], expected 116, is {}",
                    msg.signed_messages[98]
                );
                assert_eq!(
                    msg.signed_messages[99], 25,
                    "incorrect value for signed_messages[99], expected 25, is {}",
                    msg.signed_messages[99]
                );
                assert_eq!(
                    msg.signed_messages[100], 94,
                    "incorrect value for signed_messages[100], expected 94, is {}",
                    msg.signed_messages[100]
                );
                assert_eq!(
                    msg.signed_messages[101], 5,
                    "incorrect value for signed_messages[101], expected 5, is {}",
                    msg.signed_messages[101]
                );
                assert_eq!(
                    msg.signed_messages[102], 22,
                    "incorrect value for signed_messages[102], expected 22, is {}",
                    msg.signed_messages[102]
                );
                assert_eq!(
                    msg.signed_messages[103], 24,
                    "incorrect value for signed_messages[103], expected 24, is {}",
                    msg.signed_messages[103]
                );
                assert_eq!(
                    msg.signed_messages[104], 162,
                    "incorrect value for signed_messages[104], expected 162, is {}",
                    msg.signed_messages[104]
                );
                assert_eq!(
                    msg.signed_messages[105], 175,
                    "incorrect value for signed_messages[105], expected 175, is {}",
                    msg.signed_messages[105]
                );
                assert_eq!(
                    msg.signed_messages[106], 38,
                    "incorrect value for signed_messages[106], expected 38, is {}",
                    msg.signed_messages[106]
                );
                assert_eq!(
                    msg.signed_messages[107], 157,
                    "incorrect value for signed_messages[107], expected 157, is {}",
                    msg.signed_messages[107]
                );
                assert_eq!(
                    msg.signed_messages[108], 98,
                    "incorrect value for signed_messages[108], expected 98, is {}",
                    msg.signed_messages[108]
                );
                assert_eq!(
                    msg.signed_messages[109], 44,
                    "incorrect value for signed_messages[109], expected 44, is {}",
                    msg.signed_messages[109]
                );
                assert_eq!(
                    msg.signed_messages[110], 160,
                    "incorrect value for signed_messages[110], expected 160, is {}",
                    msg.signed_messages[110]
                );
                assert_eq!(
                    msg.signed_messages[111], 47,
                    "incorrect value for signed_messages[111], expected 47, is {}",
                    msg.signed_messages[111]
                );
                assert_eq!(
                    msg.signed_messages[112], 97,
                    "incorrect value for signed_messages[112], expected 97, is {}",
                    msg.signed_messages[112]
                );
                assert_eq!(
                    msg.signed_messages[113], 142,
                    "incorrect value for signed_messages[113], expected 142, is {}",
                    msg.signed_messages[113]
                );
                assert_eq!(
                    msg.signed_messages[114], 8,
                    "incorrect value for signed_messages[114], expected 8, is {}",
                    msg.signed_messages[114]
                );
                assert_eq!(
                    msg.signed_messages[115], 74,
                    "incorrect value for signed_messages[115], expected 74, is {}",
                    msg.signed_messages[115]
                );
                assert_eq!(
                    msg.signed_messages[116], 13,
                    "incorrect value for signed_messages[116], expected 13, is {}",
                    msg.signed_messages[116]
                );
                assert_eq!(
                    msg.signed_messages[117], 177,
                    "incorrect value for signed_messages[117], expected 177, is {}",
                    msg.signed_messages[117]
                );
                assert_eq!(
                    msg.signed_messages[118], 15,
                    "incorrect value for signed_messages[118], expected 15, is {}",
                    msg.signed_messages[118]
                );
                assert_eq!(
                    msg.signed_messages[119], 128,
                    "incorrect value for signed_messages[119], expected 128, is {}",
                    msg.signed_messages[119]
                );
                assert_eq!(
                    msg.signed_messages[120], 26,
                    "incorrect value for signed_messages[120], expected 26, is {}",
                    msg.signed_messages[120]
                );
                assert_eq!(
                    msg.signed_messages[121], 131,
                    "incorrect value for signed_messages[121], expected 131, is {}",
                    msg.signed_messages[121]
                );
                assert_eq!(
                    msg.signed_messages[122], 154,
                    "incorrect value for signed_messages[122], expected 154, is {}",
                    msg.signed_messages[122]
                );
                assert_eq!(
                    msg.signed_messages[123], 65,
                    "incorrect value for signed_messages[123], expected 65, is {}",
                    msg.signed_messages[123]
                );
                assert_eq!(
                    msg.signed_messages[124], 169,
                    "incorrect value for signed_messages[124], expected 169, is {}",
                    msg.signed_messages[124]
                );
                assert_eq!(
                    msg.signed_messages[125], 55,
                    "incorrect value for signed_messages[125], expected 55, is {}",
                    msg.signed_messages[125]
                );
                assert_eq!(
                    msg.signed_messages[126], 136,
                    "incorrect value for signed_messages[126], expected 136, is {}",
                    msg.signed_messages[126]
                );
                assert_eq!(
                    msg.signed_messages[127], 125,
                    "incorrect value for signed_messages[127], expected 125, is {}",
                    msg.signed_messages[127]
                );
                assert_eq!(
                    msg.signed_messages[128], 171,
                    "incorrect value for signed_messages[128], expected 171, is {}",
                    msg.signed_messages[128]
                );
                assert_eq!(
                    msg.signed_messages[129], 161,
                    "incorrect value for signed_messages[129], expected 161, is {}",
                    msg.signed_messages[129]
                );
                assert_eq!(
                    msg.signed_messages[130], 29,
                    "incorrect value for signed_messages[130], expected 29, is {}",
                    msg.signed_messages[130]
                );
                assert_eq!(
                    msg.signed_messages[131], 129,
                    "incorrect value for signed_messages[131], expected 129, is {}",
                    msg.signed_messages[131]
                );
                assert_eq!(
                    msg.signed_messages[132], 151,
                    "incorrect value for signed_messages[132], expected 151, is {}",
                    msg.signed_messages[132]
                );
                assert_eq!(
                    msg.signed_messages[133], 68,
                    "incorrect value for signed_messages[133], expected 68, is {}",
                    msg.signed_messages[133]
                );
                assert_eq!(
                    msg.signed_messages[134], 166,
                    "incorrect value for signed_messages[134], expected 166, is {}",
                    msg.signed_messages[134]
                );
                assert_eq!(
                    msg.signed_messages[135], 51,
                    "incorrect value for signed_messages[135], expected 51, is {}",
                    msg.signed_messages[135]
                );
                assert_eq!(
                    msg.signed_messages[136], 70,
                    "incorrect value for signed_messages[136], expected 70, is {}",
                    msg.signed_messages[136]
                );
                assert_eq!(
                    msg.signed_messages[137], 45,
                    "incorrect value for signed_messages[137], expected 45, is {}",
                    msg.signed_messages[137]
                );
                assert_eq!(
                    msg.signed_messages[138], 56,
                    "incorrect value for signed_messages[138], expected 56, is {}",
                    msg.signed_messages[138]
                );
                assert_eq!(
                    msg.signed_messages[139], 79,
                    "incorrect value for signed_messages[139], expected 79, is {}",
                    msg.signed_messages[139]
                );
                assert_eq!(
                    msg.signed_messages[140], 149,
                    "incorrect value for signed_messages[140], expected 149, is {}",
                    msg.signed_messages[140]
                );
                assert_eq!(
                    msg.signed_messages[141], 99,
                    "incorrect value for signed_messages[141], expected 99, is {}",
                    msg.signed_messages[141]
                );
                assert_eq!(
                    msg.signed_messages[142], 42,
                    "incorrect value for signed_messages[142], expected 42, is {}",
                    msg.signed_messages[142]
                );
                assert_eq!(
                    msg.signed_messages[143], 101,
                    "incorrect value for signed_messages[143], expected 101, is {}",
                    msg.signed_messages[143]
                );
                assert_eq!(
                    msg.signed_messages[144], 152,
                    "incorrect value for signed_messages[144], expected 152, is {}",
                    msg.signed_messages[144]
                );
                assert_eq!(
                    msg.signed_messages[145], 39,
                    "incorrect value for signed_messages[145], expected 39, is {}",
                    msg.signed_messages[145]
                );
                assert_eq!(
                    msg.signed_messages[146], 89,
                    "incorrect value for signed_messages[146], expected 89, is {}",
                    msg.signed_messages[146]
                );
                assert_eq!(
                    msg.signed_messages[147], 180,
                    "incorrect value for signed_messages[147], expected 180, is {}",
                    msg.signed_messages[147]
                );
                assert_eq!(
                    msg.signed_messages[148], 64,
                    "incorrect value for signed_messages[148], expected 64, is {}",
                    msg.signed_messages[148]
                );
                assert_eq!(
                    msg.signed_messages[149], 49,
                    "incorrect value for signed_messages[149], expected 49, is {}",
                    msg.signed_messages[149]
                );
                assert_eq!(
                    msg.signed_messages[150], 6,
                    "incorrect value for signed_messages[150], expected 6, is {}",
                    msg.signed_messages[150]
                );
                assert_eq!(
                    msg.signed_messages[151], 80,
                    "incorrect value for signed_messages[151], expected 80, is {}",
                    msg.signed_messages[151]
                );
                assert_eq!(
                    msg.signed_messages[152], 172,
                    "incorrect value for signed_messages[152], expected 172, is {}",
                    msg.signed_messages[152]
                );
                assert_eq!(
                    msg.signed_messages[153], 32,
                    "incorrect value for signed_messages[153], expected 32, is {}",
                    msg.signed_messages[153]
                );
                assert_eq!(
                    msg.signed_messages[154], 109,
                    "incorrect value for signed_messages[154], expected 109, is {}",
                    msg.signed_messages[154]
                );
                assert_eq!(
                    msg.signed_messages[155], 2,
                    "incorrect value for signed_messages[155], expected 2, is {}",
                    msg.signed_messages[155]
                );
                assert_eq!(
                    msg.signed_messages[156], 119,
                    "incorrect value for signed_messages[156], expected 119, is {}",
                    msg.signed_messages[156]
                );
                assert_eq!(
                    msg.signed_messages[157], 93,
                    "incorrect value for signed_messages[157], expected 93, is {}",
                    msg.signed_messages[157]
                );
                assert_eq!(
                    msg.signed_messages[158], 176,
                    "incorrect value for signed_messages[158], expected 176, is {}",
                    msg.signed_messages[158]
                );
                assert_eq!(
                    msg.signed_messages[159], 0,
                    "incorrect value for signed_messages[159], expected 0, is {}",
                    msg.signed_messages[159]
                );
                assert_eq!(
                    msg.signed_messages[160], 33,
                    "incorrect value for signed_messages[160], expected 33, is {}",
                    msg.signed_messages[160]
                );
                assert_eq!(
                    msg.signed_messages[161], 57,
                    "incorrect value for signed_messages[161], expected 57, is {}",
                    msg.signed_messages[161]
                );
                assert_eq!(
                    msg.signed_messages[162], 34,
                    "incorrect value for signed_messages[162], expected 34, is {}",
                    msg.signed_messages[162]
                );
                assert_eq!(
                    msg.signed_messages[163], 18,
                    "incorrect value for signed_messages[163], expected 18, is {}",
                    msg.signed_messages[163]
                );
                assert_eq!(
                    msg.signed_messages[164], 85,
                    "incorrect value for signed_messages[164], expected 85, is {}",
                    msg.signed_messages[164]
                );
                assert_eq!(
                    msg.signed_messages[165], 121,
                    "incorrect value for signed_messages[165], expected 121, is {}",
                    msg.signed_messages[165]
                );
                assert_eq!(
                    msg.signed_messages[166], 137,
                    "incorrect value for signed_messages[166], expected 137, is {}",
                    msg.signed_messages[166]
                );
                assert_eq!(
                    msg.signed_messages[167], 83,
                    "incorrect value for signed_messages[167], expected 83, is {}",
                    msg.signed_messages[167]
                );
                assert_eq!(
                    msg.signed_messages[168], 111,
                    "incorrect value for signed_messages[168], expected 111, is {}",
                    msg.signed_messages[168]
                );
                assert_eq!(
                    msg.signed_messages[169], 59,
                    "incorrect value for signed_messages[169], expected 59, is {}",
                    msg.signed_messages[169]
                );
                assert_eq!(
                    msg.signed_messages[170], 7,
                    "incorrect value for signed_messages[170], expected 7, is {}",
                    msg.signed_messages[170]
                );
                assert_eq!(
                    msg.signed_messages[171], 77,
                    "incorrect value for signed_messages[171], expected 77, is {}",
                    msg.signed_messages[171]
                );
                assert_eq!(
                    msg.signed_messages[172], 4,
                    "incorrect value for signed_messages[172], expected 4, is {}",
                    msg.signed_messages[172]
                );
                assert_eq!(
                    msg.signed_messages[173], 117,
                    "incorrect value for signed_messages[173], expected 117, is {}",
                    msg.signed_messages[173]
                );
                assert_eq!(
                    msg.signed_messages[174], 159,
                    "incorrect value for signed_messages[174], expected 159, is {}",
                    msg.signed_messages[174]
                );
                assert_eq!(
                    msg.signed_messages[175], 148,
                    "incorrect value for signed_messages[175], expected 148, is {}",
                    msg.signed_messages[175]
                );
                assert_eq!(
                    msg.signed_messages[176], 35,
                    "incorrect value for signed_messages[176], expected 35, is {}",
                    msg.signed_messages[176]
                );
                assert_eq!(
                    msg.signed_messages[177], 61,
                    "incorrect value for signed_messages[177], expected 61, is {}",
                    msg.signed_messages[177]
                );
                assert_eq!(
                    msg.signed_messages[178], 41,
                    "incorrect value for signed_messages[178], expected 41, is {}",
                    msg.signed_messages[178]
                );
                assert_eq!(
                    msg.signed_messages[179], 67,
                    "incorrect value for signed_messages[179], expected 67, is {}",
                    msg.signed_messages[179]
                );
                assert_eq!(
                    msg.signed_messages[180], 46,
                    "incorrect value for signed_messages[180], expected 46, is {}",
                    msg.signed_messages[180]
                );
                assert_eq!(
                    msg.signed_messages[181], 127,
                    "incorrect value for signed_messages[181], expected 127, is {}",
                    msg.signed_messages[181]
                );
                assert_eq!(
                    msg.signed_messages[182], 75,
                    "incorrect value for signed_messages[182], expected 75, is {}",
                    msg.signed_messages[182]
                );
                assert_eq!(
                    msg.signed_messages[183], 174,
                    "incorrect value for signed_messages[183], expected 174, is {}",
                    msg.signed_messages[183]
                );
                assert_eq!(
                    msg.stream_counter, 1,
                    "incorrect value for stream_counter, expected 1, is {}",
                    msg.stream_counter
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEcdsaSignatureDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_signing_msg_ecdsa_signature_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_signing_msg_ecdsa_signature_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 6, 12, 66, 0, 255, 0, 1, 2, 1, 2, 3, 4, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5,
            6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2,
            3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 10, 21, 23, 63, 140, 37,
            130, 106, 28, 40, 165, 179, 73, 178, 60, 126, 114, 78, 113, 27, 95, 3, 62, 104, 145,
            96, 19, 92, 123, 14, 90, 153, 183, 9, 72, 81, 118, 112, 124, 16, 182, 76, 146, 115, 58,
            144, 17, 105, 66, 31, 135, 54, 100, 84, 181, 103, 11, 88, 133, 155, 167, 173, 143, 86,
            158, 20, 168, 132, 141, 102, 50, 48, 71, 147, 53, 87, 1, 108, 138, 36, 134, 139, 163,
            82, 43, 52, 150, 12, 30, 110, 156, 107, 120, 91, 122, 69, 164, 170, 116, 25, 94, 5, 22,
            24, 162, 175, 38, 157, 98, 44, 160, 47, 97, 142, 8, 74, 13, 177, 15, 128, 26, 131, 154,
            65, 169, 55, 136, 125, 171, 161, 29, 129, 151, 68, 166, 51, 70, 45, 56, 79, 149, 99,
            42, 101, 152, 39, 89, 180, 64, 49, 6, 80, 172, 32, 109, 2, 119, 93, 176, 0, 33, 57, 34,
            18, 85, 121, 137, 83, 111, 59, 7, 77, 4, 117, 159, 148, 35, 61, 41, 67, 46, 127, 75,
            174, 97, 172,
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
        let sbp_msg = sbp::messages::Sbp::MsgEcdsaSignatureDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgEcdsaSignatureDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC06,
                    "Incorrect message type, expected 0xC06, is {}",
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
                    msg.signature[8], 0,
                    "incorrect value for signature[8], expected 0, is {}",
                    msg.signature[8]
                );
                assert_eq!(
                    msg.signature[9], 1,
                    "incorrect value for signature[9], expected 1, is {}",
                    msg.signature[9]
                );
                assert_eq!(
                    msg.signature[10], 2,
                    "incorrect value for signature[10], expected 2, is {}",
                    msg.signature[10]
                );
                assert_eq!(
                    msg.signature[11], 3,
                    "incorrect value for signature[11], expected 3, is {}",
                    msg.signature[11]
                );
                assert_eq!(
                    msg.signature[12], 4,
                    "incorrect value for signature[12], expected 4, is {}",
                    msg.signature[12]
                );
                assert_eq!(
                    msg.signature[13], 5,
                    "incorrect value for signature[13], expected 5, is {}",
                    msg.signature[13]
                );
                assert_eq!(
                    msg.signature[14], 6,
                    "incorrect value for signature[14], expected 6, is {}",
                    msg.signature[14]
                );
                assert_eq!(
                    msg.signature[15], 7,
                    "incorrect value for signature[15], expected 7, is {}",
                    msg.signature[15]
                );
                assert_eq!(
                    msg.signature[16], 0,
                    "incorrect value for signature[16], expected 0, is {}",
                    msg.signature[16]
                );
                assert_eq!(
                    msg.signature[17], 1,
                    "incorrect value for signature[17], expected 1, is {}",
                    msg.signature[17]
                );
                assert_eq!(
                    msg.signature[18], 2,
                    "incorrect value for signature[18], expected 2, is {}",
                    msg.signature[18]
                );
                assert_eq!(
                    msg.signature[19], 3,
                    "incorrect value for signature[19], expected 3, is {}",
                    msg.signature[19]
                );
                assert_eq!(
                    msg.signature[20], 4,
                    "incorrect value for signature[20], expected 4, is {}",
                    msg.signature[20]
                );
                assert_eq!(
                    msg.signature[21], 5,
                    "incorrect value for signature[21], expected 5, is {}",
                    msg.signature[21]
                );
                assert_eq!(
                    msg.signature[22], 6,
                    "incorrect value for signature[22], expected 6, is {}",
                    msg.signature[22]
                );
                assert_eq!(
                    msg.signature[23], 7,
                    "incorrect value for signature[23], expected 7, is {}",
                    msg.signature[23]
                );
                assert_eq!(
                    msg.signature[24], 0,
                    "incorrect value for signature[24], expected 0, is {}",
                    msg.signature[24]
                );
                assert_eq!(
                    msg.signature[25], 1,
                    "incorrect value for signature[25], expected 1, is {}",
                    msg.signature[25]
                );
                assert_eq!(
                    msg.signature[26], 2,
                    "incorrect value for signature[26], expected 2, is {}",
                    msg.signature[26]
                );
                assert_eq!(
                    msg.signature[27], 3,
                    "incorrect value for signature[27], expected 3, is {}",
                    msg.signature[27]
                );
                assert_eq!(
                    msg.signature[28], 4,
                    "incorrect value for signature[28], expected 4, is {}",
                    msg.signature[28]
                );
                assert_eq!(
                    msg.signature[29], 5,
                    "incorrect value for signature[29], expected 5, is {}",
                    msg.signature[29]
                );
                assert_eq!(
                    msg.signature[30], 6,
                    "incorrect value for signature[30], expected 6, is {}",
                    msg.signature[30]
                );
                assert_eq!(
                    msg.signature[31], 7,
                    "incorrect value for signature[31], expected 7, is {}",
                    msg.signature[31]
                );
                assert_eq!(
                    msg.signature[32], 0,
                    "incorrect value for signature[32], expected 0, is {}",
                    msg.signature[32]
                );
                assert_eq!(
                    msg.signature[33], 1,
                    "incorrect value for signature[33], expected 1, is {}",
                    msg.signature[33]
                );
                assert_eq!(
                    msg.signature[34], 2,
                    "incorrect value for signature[34], expected 2, is {}",
                    msg.signature[34]
                );
                assert_eq!(
                    msg.signature[35], 3,
                    "incorrect value for signature[35], expected 3, is {}",
                    msg.signature[35]
                );
                assert_eq!(
                    msg.signature[36], 4,
                    "incorrect value for signature[36], expected 4, is {}",
                    msg.signature[36]
                );
                assert_eq!(
                    msg.signature[37], 5,
                    "incorrect value for signature[37], expected 5, is {}",
                    msg.signature[37]
                );
                assert_eq!(
                    msg.signature[38], 6,
                    "incorrect value for signature[38], expected 6, is {}",
                    msg.signature[38]
                );
                assert_eq!(
                    msg.signature[39], 7,
                    "incorrect value for signature[39], expected 7, is {}",
                    msg.signature[39]
                );
                assert_eq!(
                    msg.signature[40], 0,
                    "incorrect value for signature[40], expected 0, is {}",
                    msg.signature[40]
                );
                assert_eq!(
                    msg.signature[41], 1,
                    "incorrect value for signature[41], expected 1, is {}",
                    msg.signature[41]
                );
                assert_eq!(
                    msg.signature[42], 2,
                    "incorrect value for signature[42], expected 2, is {}",
                    msg.signature[42]
                );
                assert_eq!(
                    msg.signature[43], 3,
                    "incorrect value for signature[43], expected 3, is {}",
                    msg.signature[43]
                );
                assert_eq!(
                    msg.signature[44], 4,
                    "incorrect value for signature[44], expected 4, is {}",
                    msg.signature[44]
                );
                assert_eq!(
                    msg.signature[45], 5,
                    "incorrect value for signature[45], expected 5, is {}",
                    msg.signature[45]
                );
                assert_eq!(
                    msg.signature[46], 6,
                    "incorrect value for signature[46], expected 6, is {}",
                    msg.signature[46]
                );
                assert_eq!(
                    msg.signature[47], 7,
                    "incorrect value for signature[47], expected 7, is {}",
                    msg.signature[47]
                );
                assert_eq!(
                    msg.signature[48], 0,
                    "incorrect value for signature[48], expected 0, is {}",
                    msg.signature[48]
                );
                assert_eq!(
                    msg.signature[49], 1,
                    "incorrect value for signature[49], expected 1, is {}",
                    msg.signature[49]
                );
                assert_eq!(
                    msg.signature[50], 2,
                    "incorrect value for signature[50], expected 2, is {}",
                    msg.signature[50]
                );
                assert_eq!(
                    msg.signature[51], 3,
                    "incorrect value for signature[51], expected 3, is {}",
                    msg.signature[51]
                );
                assert_eq!(
                    msg.signature[52], 4,
                    "incorrect value for signature[52], expected 4, is {}",
                    msg.signature[52]
                );
                assert_eq!(
                    msg.signature[53], 5,
                    "incorrect value for signature[53], expected 5, is {}",
                    msg.signature[53]
                );
                assert_eq!(
                    msg.signature[54], 6,
                    "incorrect value for signature[54], expected 6, is {}",
                    msg.signature[54]
                );
                assert_eq!(
                    msg.signature[55], 7,
                    "incorrect value for signature[55], expected 7, is {}",
                    msg.signature[55]
                );
                assert_eq!(
                    msg.signature[56], 0,
                    "incorrect value for signature[56], expected 0, is {}",
                    msg.signature[56]
                );
                assert_eq!(
                    msg.signature[57], 1,
                    "incorrect value for signature[57], expected 1, is {}",
                    msg.signature[57]
                );
                assert_eq!(
                    msg.signature[58], 2,
                    "incorrect value for signature[58], expected 2, is {}",
                    msg.signature[58]
                );
                assert_eq!(
                    msg.signature[59], 3,
                    "incorrect value for signature[59], expected 3, is {}",
                    msg.signature[59]
                );
                assert_eq!(
                    msg.signature[60], 4,
                    "incorrect value for signature[60], expected 4, is {}",
                    msg.signature[60]
                );
                assert_eq!(
                    msg.signature[61], 5,
                    "incorrect value for signature[61], expected 5, is {}",
                    msg.signature[61]
                );
                assert_eq!(
                    msg.signature[62], 6,
                    "incorrect value for signature[62], expected 6, is {}",
                    msg.signature[62]
                );
                assert_eq!(
                    msg.signature[63], 7,
                    "incorrect value for signature[63], expected 7, is {}",
                    msg.signature[63]
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
                    msg.signed_messages[3], 63,
                    "incorrect value for signed_messages[3], expected 63, is {}",
                    msg.signed_messages[3]
                );
                assert_eq!(
                    msg.signed_messages[4], 140,
                    "incorrect value for signed_messages[4], expected 140, is {}",
                    msg.signed_messages[4]
                );
                assert_eq!(
                    msg.signed_messages[5], 37,
                    "incorrect value for signed_messages[5], expected 37, is {}",
                    msg.signed_messages[5]
                );
                assert_eq!(
                    msg.signed_messages[6], 130,
                    "incorrect value for signed_messages[6], expected 130, is {}",
                    msg.signed_messages[6]
                );
                assert_eq!(
                    msg.signed_messages[7], 106,
                    "incorrect value for signed_messages[7], expected 106, is {}",
                    msg.signed_messages[7]
                );
                assert_eq!(
                    msg.signed_messages[8], 28,
                    "incorrect value for signed_messages[8], expected 28, is {}",
                    msg.signed_messages[8]
                );
                assert_eq!(
                    msg.signed_messages[9], 40,
                    "incorrect value for signed_messages[9], expected 40, is {}",
                    msg.signed_messages[9]
                );
                assert_eq!(
                    msg.signed_messages[10], 165,
                    "incorrect value for signed_messages[10], expected 165, is {}",
                    msg.signed_messages[10]
                );
                assert_eq!(
                    msg.signed_messages[11], 179,
                    "incorrect value for signed_messages[11], expected 179, is {}",
                    msg.signed_messages[11]
                );
                assert_eq!(
                    msg.signed_messages[12], 73,
                    "incorrect value for signed_messages[12], expected 73, is {}",
                    msg.signed_messages[12]
                );
                assert_eq!(
                    msg.signed_messages[13], 178,
                    "incorrect value for signed_messages[13], expected 178, is {}",
                    msg.signed_messages[13]
                );
                assert_eq!(
                    msg.signed_messages[14], 60,
                    "incorrect value for signed_messages[14], expected 60, is {}",
                    msg.signed_messages[14]
                );
                assert_eq!(
                    msg.signed_messages[15], 126,
                    "incorrect value for signed_messages[15], expected 126, is {}",
                    msg.signed_messages[15]
                );
                assert_eq!(
                    msg.signed_messages[16], 114,
                    "incorrect value for signed_messages[16], expected 114, is {}",
                    msg.signed_messages[16]
                );
                assert_eq!(
                    msg.signed_messages[17], 78,
                    "incorrect value for signed_messages[17], expected 78, is {}",
                    msg.signed_messages[17]
                );
                assert_eq!(
                    msg.signed_messages[18], 113,
                    "incorrect value for signed_messages[18], expected 113, is {}",
                    msg.signed_messages[18]
                );
                assert_eq!(
                    msg.signed_messages[19], 27,
                    "incorrect value for signed_messages[19], expected 27, is {}",
                    msg.signed_messages[19]
                );
                assert_eq!(
                    msg.signed_messages[20], 95,
                    "incorrect value for signed_messages[20], expected 95, is {}",
                    msg.signed_messages[20]
                );
                assert_eq!(
                    msg.signed_messages[21], 3,
                    "incorrect value for signed_messages[21], expected 3, is {}",
                    msg.signed_messages[21]
                );
                assert_eq!(
                    msg.signed_messages[22], 62,
                    "incorrect value for signed_messages[22], expected 62, is {}",
                    msg.signed_messages[22]
                );
                assert_eq!(
                    msg.signed_messages[23], 104,
                    "incorrect value for signed_messages[23], expected 104, is {}",
                    msg.signed_messages[23]
                );
                assert_eq!(
                    msg.signed_messages[24], 145,
                    "incorrect value for signed_messages[24], expected 145, is {}",
                    msg.signed_messages[24]
                );
                assert_eq!(
                    msg.signed_messages[25], 96,
                    "incorrect value for signed_messages[25], expected 96, is {}",
                    msg.signed_messages[25]
                );
                assert_eq!(
                    msg.signed_messages[26], 19,
                    "incorrect value for signed_messages[26], expected 19, is {}",
                    msg.signed_messages[26]
                );
                assert_eq!(
                    msg.signed_messages[27], 92,
                    "incorrect value for signed_messages[27], expected 92, is {}",
                    msg.signed_messages[27]
                );
                assert_eq!(
                    msg.signed_messages[28], 123,
                    "incorrect value for signed_messages[28], expected 123, is {}",
                    msg.signed_messages[28]
                );
                assert_eq!(
                    msg.signed_messages[29], 14,
                    "incorrect value for signed_messages[29], expected 14, is {}",
                    msg.signed_messages[29]
                );
                assert_eq!(
                    msg.signed_messages[30], 90,
                    "incorrect value for signed_messages[30], expected 90, is {}",
                    msg.signed_messages[30]
                );
                assert_eq!(
                    msg.signed_messages[31], 153,
                    "incorrect value for signed_messages[31], expected 153, is {}",
                    msg.signed_messages[31]
                );
                assert_eq!(
                    msg.signed_messages[32], 183,
                    "incorrect value for signed_messages[32], expected 183, is {}",
                    msg.signed_messages[32]
                );
                assert_eq!(
                    msg.signed_messages[33], 9,
                    "incorrect value for signed_messages[33], expected 9, is {}",
                    msg.signed_messages[33]
                );
                assert_eq!(
                    msg.signed_messages[34], 72,
                    "incorrect value for signed_messages[34], expected 72, is {}",
                    msg.signed_messages[34]
                );
                assert_eq!(
                    msg.signed_messages[35], 81,
                    "incorrect value for signed_messages[35], expected 81, is {}",
                    msg.signed_messages[35]
                );
                assert_eq!(
                    msg.signed_messages[36], 118,
                    "incorrect value for signed_messages[36], expected 118, is {}",
                    msg.signed_messages[36]
                );
                assert_eq!(
                    msg.signed_messages[37], 112,
                    "incorrect value for signed_messages[37], expected 112, is {}",
                    msg.signed_messages[37]
                );
                assert_eq!(
                    msg.signed_messages[38], 124,
                    "incorrect value for signed_messages[38], expected 124, is {}",
                    msg.signed_messages[38]
                );
                assert_eq!(
                    msg.signed_messages[39], 16,
                    "incorrect value for signed_messages[39], expected 16, is {}",
                    msg.signed_messages[39]
                );
                assert_eq!(
                    msg.signed_messages[40], 182,
                    "incorrect value for signed_messages[40], expected 182, is {}",
                    msg.signed_messages[40]
                );
                assert_eq!(
                    msg.signed_messages[41], 76,
                    "incorrect value for signed_messages[41], expected 76, is {}",
                    msg.signed_messages[41]
                );
                assert_eq!(
                    msg.signed_messages[42], 146,
                    "incorrect value for signed_messages[42], expected 146, is {}",
                    msg.signed_messages[42]
                );
                assert_eq!(
                    msg.signed_messages[43], 115,
                    "incorrect value for signed_messages[43], expected 115, is {}",
                    msg.signed_messages[43]
                );
                assert_eq!(
                    msg.signed_messages[44], 58,
                    "incorrect value for signed_messages[44], expected 58, is {}",
                    msg.signed_messages[44]
                );
                assert_eq!(
                    msg.signed_messages[45], 144,
                    "incorrect value for signed_messages[45], expected 144, is {}",
                    msg.signed_messages[45]
                );
                assert_eq!(
                    msg.signed_messages[46], 17,
                    "incorrect value for signed_messages[46], expected 17, is {}",
                    msg.signed_messages[46]
                );
                assert_eq!(
                    msg.signed_messages[47], 105,
                    "incorrect value for signed_messages[47], expected 105, is {}",
                    msg.signed_messages[47]
                );
                assert_eq!(
                    msg.signed_messages[48], 66,
                    "incorrect value for signed_messages[48], expected 66, is {}",
                    msg.signed_messages[48]
                );
                assert_eq!(
                    msg.signed_messages[49], 31,
                    "incorrect value for signed_messages[49], expected 31, is {}",
                    msg.signed_messages[49]
                );
                assert_eq!(
                    msg.signed_messages[50], 135,
                    "incorrect value for signed_messages[50], expected 135, is {}",
                    msg.signed_messages[50]
                );
                assert_eq!(
                    msg.signed_messages[51], 54,
                    "incorrect value for signed_messages[51], expected 54, is {}",
                    msg.signed_messages[51]
                );
                assert_eq!(
                    msg.signed_messages[52], 100,
                    "incorrect value for signed_messages[52], expected 100, is {}",
                    msg.signed_messages[52]
                );
                assert_eq!(
                    msg.signed_messages[53], 84,
                    "incorrect value for signed_messages[53], expected 84, is {}",
                    msg.signed_messages[53]
                );
                assert_eq!(
                    msg.signed_messages[54], 181,
                    "incorrect value for signed_messages[54], expected 181, is {}",
                    msg.signed_messages[54]
                );
                assert_eq!(
                    msg.signed_messages[55], 103,
                    "incorrect value for signed_messages[55], expected 103, is {}",
                    msg.signed_messages[55]
                );
                assert_eq!(
                    msg.signed_messages[56], 11,
                    "incorrect value for signed_messages[56], expected 11, is {}",
                    msg.signed_messages[56]
                );
                assert_eq!(
                    msg.signed_messages[57], 88,
                    "incorrect value for signed_messages[57], expected 88, is {}",
                    msg.signed_messages[57]
                );
                assert_eq!(
                    msg.signed_messages[58], 133,
                    "incorrect value for signed_messages[58], expected 133, is {}",
                    msg.signed_messages[58]
                );
                assert_eq!(
                    msg.signed_messages[59], 155,
                    "incorrect value for signed_messages[59], expected 155, is {}",
                    msg.signed_messages[59]
                );
                assert_eq!(
                    msg.signed_messages[60], 167,
                    "incorrect value for signed_messages[60], expected 167, is {}",
                    msg.signed_messages[60]
                );
                assert_eq!(
                    msg.signed_messages[61], 173,
                    "incorrect value for signed_messages[61], expected 173, is {}",
                    msg.signed_messages[61]
                );
                assert_eq!(
                    msg.signed_messages[62], 143,
                    "incorrect value for signed_messages[62], expected 143, is {}",
                    msg.signed_messages[62]
                );
                assert_eq!(
                    msg.signed_messages[63], 86,
                    "incorrect value for signed_messages[63], expected 86, is {}",
                    msg.signed_messages[63]
                );
                assert_eq!(
                    msg.signed_messages[64], 158,
                    "incorrect value for signed_messages[64], expected 158, is {}",
                    msg.signed_messages[64]
                );
                assert_eq!(
                    msg.signed_messages[65], 20,
                    "incorrect value for signed_messages[65], expected 20, is {}",
                    msg.signed_messages[65]
                );
                assert_eq!(
                    msg.signed_messages[66], 168,
                    "incorrect value for signed_messages[66], expected 168, is {}",
                    msg.signed_messages[66]
                );
                assert_eq!(
                    msg.signed_messages[67], 132,
                    "incorrect value for signed_messages[67], expected 132, is {}",
                    msg.signed_messages[67]
                );
                assert_eq!(
                    msg.signed_messages[68], 141,
                    "incorrect value for signed_messages[68], expected 141, is {}",
                    msg.signed_messages[68]
                );
                assert_eq!(
                    msg.signed_messages[69], 102,
                    "incorrect value for signed_messages[69], expected 102, is {}",
                    msg.signed_messages[69]
                );
                assert_eq!(
                    msg.signed_messages[70], 50,
                    "incorrect value for signed_messages[70], expected 50, is {}",
                    msg.signed_messages[70]
                );
                assert_eq!(
                    msg.signed_messages[71], 48,
                    "incorrect value for signed_messages[71], expected 48, is {}",
                    msg.signed_messages[71]
                );
                assert_eq!(
                    msg.signed_messages[72], 71,
                    "incorrect value for signed_messages[72], expected 71, is {}",
                    msg.signed_messages[72]
                );
                assert_eq!(
                    msg.signed_messages[73], 147,
                    "incorrect value for signed_messages[73], expected 147, is {}",
                    msg.signed_messages[73]
                );
                assert_eq!(
                    msg.signed_messages[74], 53,
                    "incorrect value for signed_messages[74], expected 53, is {}",
                    msg.signed_messages[74]
                );
                assert_eq!(
                    msg.signed_messages[75], 87,
                    "incorrect value for signed_messages[75], expected 87, is {}",
                    msg.signed_messages[75]
                );
                assert_eq!(
                    msg.signed_messages[76], 1,
                    "incorrect value for signed_messages[76], expected 1, is {}",
                    msg.signed_messages[76]
                );
                assert_eq!(
                    msg.signed_messages[77], 108,
                    "incorrect value for signed_messages[77], expected 108, is {}",
                    msg.signed_messages[77]
                );
                assert_eq!(
                    msg.signed_messages[78], 138,
                    "incorrect value for signed_messages[78], expected 138, is {}",
                    msg.signed_messages[78]
                );
                assert_eq!(
                    msg.signed_messages[79], 36,
                    "incorrect value for signed_messages[79], expected 36, is {}",
                    msg.signed_messages[79]
                );
                assert_eq!(
                    msg.signed_messages[80], 134,
                    "incorrect value for signed_messages[80], expected 134, is {}",
                    msg.signed_messages[80]
                );
                assert_eq!(
                    msg.signed_messages[81], 139,
                    "incorrect value for signed_messages[81], expected 139, is {}",
                    msg.signed_messages[81]
                );
                assert_eq!(
                    msg.signed_messages[82], 163,
                    "incorrect value for signed_messages[82], expected 163, is {}",
                    msg.signed_messages[82]
                );
                assert_eq!(
                    msg.signed_messages[83], 82,
                    "incorrect value for signed_messages[83], expected 82, is {}",
                    msg.signed_messages[83]
                );
                assert_eq!(
                    msg.signed_messages[84], 43,
                    "incorrect value for signed_messages[84], expected 43, is {}",
                    msg.signed_messages[84]
                );
                assert_eq!(
                    msg.signed_messages[85], 52,
                    "incorrect value for signed_messages[85], expected 52, is {}",
                    msg.signed_messages[85]
                );
                assert_eq!(
                    msg.signed_messages[86], 150,
                    "incorrect value for signed_messages[86], expected 150, is {}",
                    msg.signed_messages[86]
                );
                assert_eq!(
                    msg.signed_messages[87], 12,
                    "incorrect value for signed_messages[87], expected 12, is {}",
                    msg.signed_messages[87]
                );
                assert_eq!(
                    msg.signed_messages[88], 30,
                    "incorrect value for signed_messages[88], expected 30, is {}",
                    msg.signed_messages[88]
                );
                assert_eq!(
                    msg.signed_messages[89], 110,
                    "incorrect value for signed_messages[89], expected 110, is {}",
                    msg.signed_messages[89]
                );
                assert_eq!(
                    msg.signed_messages[90], 156,
                    "incorrect value for signed_messages[90], expected 156, is {}",
                    msg.signed_messages[90]
                );
                assert_eq!(
                    msg.signed_messages[91], 107,
                    "incorrect value for signed_messages[91], expected 107, is {}",
                    msg.signed_messages[91]
                );
                assert_eq!(
                    msg.signed_messages[92], 120,
                    "incorrect value for signed_messages[92], expected 120, is {}",
                    msg.signed_messages[92]
                );
                assert_eq!(
                    msg.signed_messages[93], 91,
                    "incorrect value for signed_messages[93], expected 91, is {}",
                    msg.signed_messages[93]
                );
                assert_eq!(
                    msg.signed_messages[94], 122,
                    "incorrect value for signed_messages[94], expected 122, is {}",
                    msg.signed_messages[94]
                );
                assert_eq!(
                    msg.signed_messages[95], 69,
                    "incorrect value for signed_messages[95], expected 69, is {}",
                    msg.signed_messages[95]
                );
                assert_eq!(
                    msg.signed_messages[96], 164,
                    "incorrect value for signed_messages[96], expected 164, is {}",
                    msg.signed_messages[96]
                );
                assert_eq!(
                    msg.signed_messages[97], 170,
                    "incorrect value for signed_messages[97], expected 170, is {}",
                    msg.signed_messages[97]
                );
                assert_eq!(
                    msg.signed_messages[98], 116,
                    "incorrect value for signed_messages[98], expected 116, is {}",
                    msg.signed_messages[98]
                );
                assert_eq!(
                    msg.signed_messages[99], 25,
                    "incorrect value for signed_messages[99], expected 25, is {}",
                    msg.signed_messages[99]
                );
                assert_eq!(
                    msg.signed_messages[100], 94,
                    "incorrect value for signed_messages[100], expected 94, is {}",
                    msg.signed_messages[100]
                );
                assert_eq!(
                    msg.signed_messages[101], 5,
                    "incorrect value for signed_messages[101], expected 5, is {}",
                    msg.signed_messages[101]
                );
                assert_eq!(
                    msg.signed_messages[102], 22,
                    "incorrect value for signed_messages[102], expected 22, is {}",
                    msg.signed_messages[102]
                );
                assert_eq!(
                    msg.signed_messages[103], 24,
                    "incorrect value for signed_messages[103], expected 24, is {}",
                    msg.signed_messages[103]
                );
                assert_eq!(
                    msg.signed_messages[104], 162,
                    "incorrect value for signed_messages[104], expected 162, is {}",
                    msg.signed_messages[104]
                );
                assert_eq!(
                    msg.signed_messages[105], 175,
                    "incorrect value for signed_messages[105], expected 175, is {}",
                    msg.signed_messages[105]
                );
                assert_eq!(
                    msg.signed_messages[106], 38,
                    "incorrect value for signed_messages[106], expected 38, is {}",
                    msg.signed_messages[106]
                );
                assert_eq!(
                    msg.signed_messages[107], 157,
                    "incorrect value for signed_messages[107], expected 157, is {}",
                    msg.signed_messages[107]
                );
                assert_eq!(
                    msg.signed_messages[108], 98,
                    "incorrect value for signed_messages[108], expected 98, is {}",
                    msg.signed_messages[108]
                );
                assert_eq!(
                    msg.signed_messages[109], 44,
                    "incorrect value for signed_messages[109], expected 44, is {}",
                    msg.signed_messages[109]
                );
                assert_eq!(
                    msg.signed_messages[110], 160,
                    "incorrect value for signed_messages[110], expected 160, is {}",
                    msg.signed_messages[110]
                );
                assert_eq!(
                    msg.signed_messages[111], 47,
                    "incorrect value for signed_messages[111], expected 47, is {}",
                    msg.signed_messages[111]
                );
                assert_eq!(
                    msg.signed_messages[112], 97,
                    "incorrect value for signed_messages[112], expected 97, is {}",
                    msg.signed_messages[112]
                );
                assert_eq!(
                    msg.signed_messages[113], 142,
                    "incorrect value for signed_messages[113], expected 142, is {}",
                    msg.signed_messages[113]
                );
                assert_eq!(
                    msg.signed_messages[114], 8,
                    "incorrect value for signed_messages[114], expected 8, is {}",
                    msg.signed_messages[114]
                );
                assert_eq!(
                    msg.signed_messages[115], 74,
                    "incorrect value for signed_messages[115], expected 74, is {}",
                    msg.signed_messages[115]
                );
                assert_eq!(
                    msg.signed_messages[116], 13,
                    "incorrect value for signed_messages[116], expected 13, is {}",
                    msg.signed_messages[116]
                );
                assert_eq!(
                    msg.signed_messages[117], 177,
                    "incorrect value for signed_messages[117], expected 177, is {}",
                    msg.signed_messages[117]
                );
                assert_eq!(
                    msg.signed_messages[118], 15,
                    "incorrect value for signed_messages[118], expected 15, is {}",
                    msg.signed_messages[118]
                );
                assert_eq!(
                    msg.signed_messages[119], 128,
                    "incorrect value for signed_messages[119], expected 128, is {}",
                    msg.signed_messages[119]
                );
                assert_eq!(
                    msg.signed_messages[120], 26,
                    "incorrect value for signed_messages[120], expected 26, is {}",
                    msg.signed_messages[120]
                );
                assert_eq!(
                    msg.signed_messages[121], 131,
                    "incorrect value for signed_messages[121], expected 131, is {}",
                    msg.signed_messages[121]
                );
                assert_eq!(
                    msg.signed_messages[122], 154,
                    "incorrect value for signed_messages[122], expected 154, is {}",
                    msg.signed_messages[122]
                );
                assert_eq!(
                    msg.signed_messages[123], 65,
                    "incorrect value for signed_messages[123], expected 65, is {}",
                    msg.signed_messages[123]
                );
                assert_eq!(
                    msg.signed_messages[124], 169,
                    "incorrect value for signed_messages[124], expected 169, is {}",
                    msg.signed_messages[124]
                );
                assert_eq!(
                    msg.signed_messages[125], 55,
                    "incorrect value for signed_messages[125], expected 55, is {}",
                    msg.signed_messages[125]
                );
                assert_eq!(
                    msg.signed_messages[126], 136,
                    "incorrect value for signed_messages[126], expected 136, is {}",
                    msg.signed_messages[126]
                );
                assert_eq!(
                    msg.signed_messages[127], 125,
                    "incorrect value for signed_messages[127], expected 125, is {}",
                    msg.signed_messages[127]
                );
                assert_eq!(
                    msg.signed_messages[128], 171,
                    "incorrect value for signed_messages[128], expected 171, is {}",
                    msg.signed_messages[128]
                );
                assert_eq!(
                    msg.signed_messages[129], 161,
                    "incorrect value for signed_messages[129], expected 161, is {}",
                    msg.signed_messages[129]
                );
                assert_eq!(
                    msg.signed_messages[130], 29,
                    "incorrect value for signed_messages[130], expected 29, is {}",
                    msg.signed_messages[130]
                );
                assert_eq!(
                    msg.signed_messages[131], 129,
                    "incorrect value for signed_messages[131], expected 129, is {}",
                    msg.signed_messages[131]
                );
                assert_eq!(
                    msg.signed_messages[132], 151,
                    "incorrect value for signed_messages[132], expected 151, is {}",
                    msg.signed_messages[132]
                );
                assert_eq!(
                    msg.signed_messages[133], 68,
                    "incorrect value for signed_messages[133], expected 68, is {}",
                    msg.signed_messages[133]
                );
                assert_eq!(
                    msg.signed_messages[134], 166,
                    "incorrect value for signed_messages[134], expected 166, is {}",
                    msg.signed_messages[134]
                );
                assert_eq!(
                    msg.signed_messages[135], 51,
                    "incorrect value for signed_messages[135], expected 51, is {}",
                    msg.signed_messages[135]
                );
                assert_eq!(
                    msg.signed_messages[136], 70,
                    "incorrect value for signed_messages[136], expected 70, is {}",
                    msg.signed_messages[136]
                );
                assert_eq!(
                    msg.signed_messages[137], 45,
                    "incorrect value for signed_messages[137], expected 45, is {}",
                    msg.signed_messages[137]
                );
                assert_eq!(
                    msg.signed_messages[138], 56,
                    "incorrect value for signed_messages[138], expected 56, is {}",
                    msg.signed_messages[138]
                );
                assert_eq!(
                    msg.signed_messages[139], 79,
                    "incorrect value for signed_messages[139], expected 79, is {}",
                    msg.signed_messages[139]
                );
                assert_eq!(
                    msg.signed_messages[140], 149,
                    "incorrect value for signed_messages[140], expected 149, is {}",
                    msg.signed_messages[140]
                );
                assert_eq!(
                    msg.signed_messages[141], 99,
                    "incorrect value for signed_messages[141], expected 99, is {}",
                    msg.signed_messages[141]
                );
                assert_eq!(
                    msg.signed_messages[142], 42,
                    "incorrect value for signed_messages[142], expected 42, is {}",
                    msg.signed_messages[142]
                );
                assert_eq!(
                    msg.signed_messages[143], 101,
                    "incorrect value for signed_messages[143], expected 101, is {}",
                    msg.signed_messages[143]
                );
                assert_eq!(
                    msg.signed_messages[144], 152,
                    "incorrect value for signed_messages[144], expected 152, is {}",
                    msg.signed_messages[144]
                );
                assert_eq!(
                    msg.signed_messages[145], 39,
                    "incorrect value for signed_messages[145], expected 39, is {}",
                    msg.signed_messages[145]
                );
                assert_eq!(
                    msg.signed_messages[146], 89,
                    "incorrect value for signed_messages[146], expected 89, is {}",
                    msg.signed_messages[146]
                );
                assert_eq!(
                    msg.signed_messages[147], 180,
                    "incorrect value for signed_messages[147], expected 180, is {}",
                    msg.signed_messages[147]
                );
                assert_eq!(
                    msg.signed_messages[148], 64,
                    "incorrect value for signed_messages[148], expected 64, is {}",
                    msg.signed_messages[148]
                );
                assert_eq!(
                    msg.signed_messages[149], 49,
                    "incorrect value for signed_messages[149], expected 49, is {}",
                    msg.signed_messages[149]
                );
                assert_eq!(
                    msg.signed_messages[150], 6,
                    "incorrect value for signed_messages[150], expected 6, is {}",
                    msg.signed_messages[150]
                );
                assert_eq!(
                    msg.signed_messages[151], 80,
                    "incorrect value for signed_messages[151], expected 80, is {}",
                    msg.signed_messages[151]
                );
                assert_eq!(
                    msg.signed_messages[152], 172,
                    "incorrect value for signed_messages[152], expected 172, is {}",
                    msg.signed_messages[152]
                );
                assert_eq!(
                    msg.signed_messages[153], 32,
                    "incorrect value for signed_messages[153], expected 32, is {}",
                    msg.signed_messages[153]
                );
                assert_eq!(
                    msg.signed_messages[154], 109,
                    "incorrect value for signed_messages[154], expected 109, is {}",
                    msg.signed_messages[154]
                );
                assert_eq!(
                    msg.signed_messages[155], 2,
                    "incorrect value for signed_messages[155], expected 2, is {}",
                    msg.signed_messages[155]
                );
                assert_eq!(
                    msg.signed_messages[156], 119,
                    "incorrect value for signed_messages[156], expected 119, is {}",
                    msg.signed_messages[156]
                );
                assert_eq!(
                    msg.signed_messages[157], 93,
                    "incorrect value for signed_messages[157], expected 93, is {}",
                    msg.signed_messages[157]
                );
                assert_eq!(
                    msg.signed_messages[158], 176,
                    "incorrect value for signed_messages[158], expected 176, is {}",
                    msg.signed_messages[158]
                );
                assert_eq!(
                    msg.signed_messages[159], 0,
                    "incorrect value for signed_messages[159], expected 0, is {}",
                    msg.signed_messages[159]
                );
                assert_eq!(
                    msg.signed_messages[160], 33,
                    "incorrect value for signed_messages[160], expected 33, is {}",
                    msg.signed_messages[160]
                );
                assert_eq!(
                    msg.signed_messages[161], 57,
                    "incorrect value for signed_messages[161], expected 57, is {}",
                    msg.signed_messages[161]
                );
                assert_eq!(
                    msg.signed_messages[162], 34,
                    "incorrect value for signed_messages[162], expected 34, is {}",
                    msg.signed_messages[162]
                );
                assert_eq!(
                    msg.signed_messages[163], 18,
                    "incorrect value for signed_messages[163], expected 18, is {}",
                    msg.signed_messages[163]
                );
                assert_eq!(
                    msg.signed_messages[164], 85,
                    "incorrect value for signed_messages[164], expected 85, is {}",
                    msg.signed_messages[164]
                );
                assert_eq!(
                    msg.signed_messages[165], 121,
                    "incorrect value for signed_messages[165], expected 121, is {}",
                    msg.signed_messages[165]
                );
                assert_eq!(
                    msg.signed_messages[166], 137,
                    "incorrect value for signed_messages[166], expected 137, is {}",
                    msg.signed_messages[166]
                );
                assert_eq!(
                    msg.signed_messages[167], 83,
                    "incorrect value for signed_messages[167], expected 83, is {}",
                    msg.signed_messages[167]
                );
                assert_eq!(
                    msg.signed_messages[168], 111,
                    "incorrect value for signed_messages[168], expected 111, is {}",
                    msg.signed_messages[168]
                );
                assert_eq!(
                    msg.signed_messages[169], 59,
                    "incorrect value for signed_messages[169], expected 59, is {}",
                    msg.signed_messages[169]
                );
                assert_eq!(
                    msg.signed_messages[170], 7,
                    "incorrect value for signed_messages[170], expected 7, is {}",
                    msg.signed_messages[170]
                );
                assert_eq!(
                    msg.signed_messages[171], 77,
                    "incorrect value for signed_messages[171], expected 77, is {}",
                    msg.signed_messages[171]
                );
                assert_eq!(
                    msg.signed_messages[172], 4,
                    "incorrect value for signed_messages[172], expected 4, is {}",
                    msg.signed_messages[172]
                );
                assert_eq!(
                    msg.signed_messages[173], 117,
                    "incorrect value for signed_messages[173], expected 117, is {}",
                    msg.signed_messages[173]
                );
                assert_eq!(
                    msg.signed_messages[174], 159,
                    "incorrect value for signed_messages[174], expected 159, is {}",
                    msg.signed_messages[174]
                );
                assert_eq!(
                    msg.signed_messages[175], 148,
                    "incorrect value for signed_messages[175], expected 148, is {}",
                    msg.signed_messages[175]
                );
                assert_eq!(
                    msg.signed_messages[176], 35,
                    "incorrect value for signed_messages[176], expected 35, is {}",
                    msg.signed_messages[176]
                );
                assert_eq!(
                    msg.signed_messages[177], 61,
                    "incorrect value for signed_messages[177], expected 61, is {}",
                    msg.signed_messages[177]
                );
                assert_eq!(
                    msg.signed_messages[178], 41,
                    "incorrect value for signed_messages[178], expected 41, is {}",
                    msg.signed_messages[178]
                );
                assert_eq!(
                    msg.signed_messages[179], 67,
                    "incorrect value for signed_messages[179], expected 67, is {}",
                    msg.signed_messages[179]
                );
                assert_eq!(
                    msg.signed_messages[180], 46,
                    "incorrect value for signed_messages[180], expected 46, is {}",
                    msg.signed_messages[180]
                );
                assert_eq!(
                    msg.signed_messages[181], 127,
                    "incorrect value for signed_messages[181], expected 127, is {}",
                    msg.signed_messages[181]
                );
                assert_eq!(
                    msg.signed_messages[182], 75,
                    "incorrect value for signed_messages[182], expected 75, is {}",
                    msg.signed_messages[182]
                );
                assert_eq!(
                    msg.signed_messages[183], 174,
                    "incorrect value for signed_messages[183], expected 174, is {}",
                    msg.signed_messages[183]
                );
                assert_eq!(
                    msg.stream_counter, 1,
                    "incorrect value for stream_counter, expected 1, is {}",
                    msg.stream_counter
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEcdsaSignatureDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
