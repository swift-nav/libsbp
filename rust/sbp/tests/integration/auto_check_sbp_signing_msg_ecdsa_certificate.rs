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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaCertificate.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_signing_msg_ecdsa_certificate() {
    {
        let mut payload = Cursor::new(vec![
            85, 4, 12, 66, 0, 253, 48, 10, 11, 12, 13, 2, 180, 160, 116, 77, 243, 28, 173, 36, 86,
            33, 8, 31, 120, 73, 64, 169, 148, 224, 57, 95, 17, 40, 213, 92, 195, 146, 235, 228,
            177, 101, 82, 182, 25, 172, 170, 250, 236, 7, 119, 4, 201, 10, 14, 208, 47, 126, 49,
            210, 174, 75, 221, 203, 24, 66, 52, 35, 26, 30, 140, 111, 246, 39, 226, 205, 198, 178,
            196, 5, 81, 9, 44, 164, 163, 214, 138, 123, 76, 74, 237, 121, 13, 137, 186, 97, 193,
            189, 200, 124, 69, 115, 230, 159, 185, 158, 51, 12, 225, 65, 192, 105, 56, 41, 85, 133,
            19, 217, 166, 48, 139, 131, 96, 216, 98, 147, 132, 234, 167, 248, 247, 32, 239, 194,
            188, 254, 114, 117, 83, 25, 251, 191, 104, 240, 118, 68, 42, 93, 18, 16, 37, 232, 99,
            179, 23, 90, 94, 136, 6, 125, 91, 255, 15, 71, 43, 46, 25, 252, 229, 80, 143, 58, 241,
            11, 62, 181, 155, 53, 153, 149, 152, 227, 150, 87, 112, 165, 2, 128, 231, 25, 157, 244,
            204, 108, 253, 127, 122, 145, 113, 162, 197, 171, 199, 54, 184, 222, 206, 67, 144, 78,
            187, 207, 60, 211, 141, 135, 106, 220, 79, 183, 245, 21, 161, 168, 34, 129, 50, 176, 1,
            218, 20, 130, 59, 249, 109, 219, 0, 100, 103, 55, 29, 242, 110, 154, 190, 233, 142, 45,
            61, 215, 202, 238, 88, 209, 70, 63, 151, 27, 102, 219, 30,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgEcdsaCertificate(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xC04,
                    "Incorrect message type, expected 0xC04, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {sender_id}"
                );
                assert_eq!(
                    msg.certificate_bytes[0], 180,
                    "incorrect value for certificate_bytes[0], expected 180, is {}",
                    msg.certificate_bytes[0]
                );
                assert_eq!(
                    msg.certificate_bytes[1], 160,
                    "incorrect value for certificate_bytes[1], expected 160, is {}",
                    msg.certificate_bytes[1]
                );
                assert_eq!(
                    msg.certificate_bytes[2], 116,
                    "incorrect value for certificate_bytes[2], expected 116, is {}",
                    msg.certificate_bytes[2]
                );
                assert_eq!(
                    msg.certificate_bytes[3], 77,
                    "incorrect value for certificate_bytes[3], expected 77, is {}",
                    msg.certificate_bytes[3]
                );
                assert_eq!(
                    msg.certificate_bytes[4], 243,
                    "incorrect value for certificate_bytes[4], expected 243, is {}",
                    msg.certificate_bytes[4]
                );
                assert_eq!(
                    msg.certificate_bytes[5], 28,
                    "incorrect value for certificate_bytes[5], expected 28, is {}",
                    msg.certificate_bytes[5]
                );
                assert_eq!(
                    msg.certificate_bytes[6], 173,
                    "incorrect value for certificate_bytes[6], expected 173, is {}",
                    msg.certificate_bytes[6]
                );
                assert_eq!(
                    msg.certificate_bytes[7], 36,
                    "incorrect value for certificate_bytes[7], expected 36, is {}",
                    msg.certificate_bytes[7]
                );
                assert_eq!(
                    msg.certificate_bytes[8], 86,
                    "incorrect value for certificate_bytes[8], expected 86, is {}",
                    msg.certificate_bytes[8]
                );
                assert_eq!(
                    msg.certificate_bytes[9], 33,
                    "incorrect value for certificate_bytes[9], expected 33, is {}",
                    msg.certificate_bytes[9]
                );
                assert_eq!(
                    msg.certificate_bytes[10], 8,
                    "incorrect value for certificate_bytes[10], expected 8, is {}",
                    msg.certificate_bytes[10]
                );
                assert_eq!(
                    msg.certificate_bytes[11], 31,
                    "incorrect value for certificate_bytes[11], expected 31, is {}",
                    msg.certificate_bytes[11]
                );
                assert_eq!(
                    msg.certificate_bytes[12], 120,
                    "incorrect value for certificate_bytes[12], expected 120, is {}",
                    msg.certificate_bytes[12]
                );
                assert_eq!(
                    msg.certificate_bytes[13], 73,
                    "incorrect value for certificate_bytes[13], expected 73, is {}",
                    msg.certificate_bytes[13]
                );
                assert_eq!(
                    msg.certificate_bytes[14], 64,
                    "incorrect value for certificate_bytes[14], expected 64, is {}",
                    msg.certificate_bytes[14]
                );
                assert_eq!(
                    msg.certificate_bytes[15], 169,
                    "incorrect value for certificate_bytes[15], expected 169, is {}",
                    msg.certificate_bytes[15]
                );
                assert_eq!(
                    msg.certificate_bytes[16], 148,
                    "incorrect value for certificate_bytes[16], expected 148, is {}",
                    msg.certificate_bytes[16]
                );
                assert_eq!(
                    msg.certificate_bytes[17], 224,
                    "incorrect value for certificate_bytes[17], expected 224, is {}",
                    msg.certificate_bytes[17]
                );
                assert_eq!(
                    msg.certificate_bytes[18], 57,
                    "incorrect value for certificate_bytes[18], expected 57, is {}",
                    msg.certificate_bytes[18]
                );
                assert_eq!(
                    msg.certificate_bytes[19], 95,
                    "incorrect value for certificate_bytes[19], expected 95, is {}",
                    msg.certificate_bytes[19]
                );
                assert_eq!(
                    msg.certificate_bytes[20], 17,
                    "incorrect value for certificate_bytes[20], expected 17, is {}",
                    msg.certificate_bytes[20]
                );
                assert_eq!(
                    msg.certificate_bytes[21], 40,
                    "incorrect value for certificate_bytes[21], expected 40, is {}",
                    msg.certificate_bytes[21]
                );
                assert_eq!(
                    msg.certificate_bytes[22], 213,
                    "incorrect value for certificate_bytes[22], expected 213, is {}",
                    msg.certificate_bytes[22]
                );
                assert_eq!(
                    msg.certificate_bytes[23], 92,
                    "incorrect value for certificate_bytes[23], expected 92, is {}",
                    msg.certificate_bytes[23]
                );
                assert_eq!(
                    msg.certificate_bytes[24], 195,
                    "incorrect value for certificate_bytes[24], expected 195, is {}",
                    msg.certificate_bytes[24]
                );
                assert_eq!(
                    msg.certificate_bytes[25], 146,
                    "incorrect value for certificate_bytes[25], expected 146, is {}",
                    msg.certificate_bytes[25]
                );
                assert_eq!(
                    msg.certificate_bytes[26], 235,
                    "incorrect value for certificate_bytes[26], expected 235, is {}",
                    msg.certificate_bytes[26]
                );
                assert_eq!(
                    msg.certificate_bytes[27], 228,
                    "incorrect value for certificate_bytes[27], expected 228, is {}",
                    msg.certificate_bytes[27]
                );
                assert_eq!(
                    msg.certificate_bytes[28], 177,
                    "incorrect value for certificate_bytes[28], expected 177, is {}",
                    msg.certificate_bytes[28]
                );
                assert_eq!(
                    msg.certificate_bytes[29], 101,
                    "incorrect value for certificate_bytes[29], expected 101, is {}",
                    msg.certificate_bytes[29]
                );
                assert_eq!(
                    msg.certificate_bytes[30], 82,
                    "incorrect value for certificate_bytes[30], expected 82, is {}",
                    msg.certificate_bytes[30]
                );
                assert_eq!(
                    msg.certificate_bytes[31], 182,
                    "incorrect value for certificate_bytes[31], expected 182, is {}",
                    msg.certificate_bytes[31]
                );
                assert_eq!(
                    msg.certificate_bytes[32], 25,
                    "incorrect value for certificate_bytes[32], expected 25, is {}",
                    msg.certificate_bytes[32]
                );
                assert_eq!(
                    msg.certificate_bytes[33], 172,
                    "incorrect value for certificate_bytes[33], expected 172, is {}",
                    msg.certificate_bytes[33]
                );
                assert_eq!(
                    msg.certificate_bytes[34], 170,
                    "incorrect value for certificate_bytes[34], expected 170, is {}",
                    msg.certificate_bytes[34]
                );
                assert_eq!(
                    msg.certificate_bytes[35], 250,
                    "incorrect value for certificate_bytes[35], expected 250, is {}",
                    msg.certificate_bytes[35]
                );
                assert_eq!(
                    msg.certificate_bytes[36], 236,
                    "incorrect value for certificate_bytes[36], expected 236, is {}",
                    msg.certificate_bytes[36]
                );
                assert_eq!(
                    msg.certificate_bytes[37], 7,
                    "incorrect value for certificate_bytes[37], expected 7, is {}",
                    msg.certificate_bytes[37]
                );
                assert_eq!(
                    msg.certificate_bytes[38], 119,
                    "incorrect value for certificate_bytes[38], expected 119, is {}",
                    msg.certificate_bytes[38]
                );
                assert_eq!(
                    msg.certificate_bytes[39], 4,
                    "incorrect value for certificate_bytes[39], expected 4, is {}",
                    msg.certificate_bytes[39]
                );
                assert_eq!(
                    msg.certificate_bytes[40], 201,
                    "incorrect value for certificate_bytes[40], expected 201, is {}",
                    msg.certificate_bytes[40]
                );
                assert_eq!(
                    msg.certificate_bytes[41], 10,
                    "incorrect value for certificate_bytes[41], expected 10, is {}",
                    msg.certificate_bytes[41]
                );
                assert_eq!(
                    msg.certificate_bytes[42], 14,
                    "incorrect value for certificate_bytes[42], expected 14, is {}",
                    msg.certificate_bytes[42]
                );
                assert_eq!(
                    msg.certificate_bytes[43], 208,
                    "incorrect value for certificate_bytes[43], expected 208, is {}",
                    msg.certificate_bytes[43]
                );
                assert_eq!(
                    msg.certificate_bytes[44], 47,
                    "incorrect value for certificate_bytes[44], expected 47, is {}",
                    msg.certificate_bytes[44]
                );
                assert_eq!(
                    msg.certificate_bytes[45], 126,
                    "incorrect value for certificate_bytes[45], expected 126, is {}",
                    msg.certificate_bytes[45]
                );
                assert_eq!(
                    msg.certificate_bytes[46], 49,
                    "incorrect value for certificate_bytes[46], expected 49, is {}",
                    msg.certificate_bytes[46]
                );
                assert_eq!(
                    msg.certificate_bytes[47], 210,
                    "incorrect value for certificate_bytes[47], expected 210, is {}",
                    msg.certificate_bytes[47]
                );
                assert_eq!(
                    msg.certificate_bytes[48], 174,
                    "incorrect value for certificate_bytes[48], expected 174, is {}",
                    msg.certificate_bytes[48]
                );
                assert_eq!(
                    msg.certificate_bytes[49], 75,
                    "incorrect value for certificate_bytes[49], expected 75, is {}",
                    msg.certificate_bytes[49]
                );
                assert_eq!(
                    msg.certificate_bytes[50], 221,
                    "incorrect value for certificate_bytes[50], expected 221, is {}",
                    msg.certificate_bytes[50]
                );
                assert_eq!(
                    msg.certificate_bytes[51], 203,
                    "incorrect value for certificate_bytes[51], expected 203, is {}",
                    msg.certificate_bytes[51]
                );
                assert_eq!(
                    msg.certificate_bytes[52], 24,
                    "incorrect value for certificate_bytes[52], expected 24, is {}",
                    msg.certificate_bytes[52]
                );
                assert_eq!(
                    msg.certificate_bytes[53], 66,
                    "incorrect value for certificate_bytes[53], expected 66, is {}",
                    msg.certificate_bytes[53]
                );
                assert_eq!(
                    msg.certificate_bytes[54], 52,
                    "incorrect value for certificate_bytes[54], expected 52, is {}",
                    msg.certificate_bytes[54]
                );
                assert_eq!(
                    msg.certificate_bytes[55], 35,
                    "incorrect value for certificate_bytes[55], expected 35, is {}",
                    msg.certificate_bytes[55]
                );
                assert_eq!(
                    msg.certificate_bytes[56], 26,
                    "incorrect value for certificate_bytes[56], expected 26, is {}",
                    msg.certificate_bytes[56]
                );
                assert_eq!(
                    msg.certificate_bytes[57], 30,
                    "incorrect value for certificate_bytes[57], expected 30, is {}",
                    msg.certificate_bytes[57]
                );
                assert_eq!(
                    msg.certificate_bytes[58], 140,
                    "incorrect value for certificate_bytes[58], expected 140, is {}",
                    msg.certificate_bytes[58]
                );
                assert_eq!(
                    msg.certificate_bytes[59], 111,
                    "incorrect value for certificate_bytes[59], expected 111, is {}",
                    msg.certificate_bytes[59]
                );
                assert_eq!(
                    msg.certificate_bytes[60], 246,
                    "incorrect value for certificate_bytes[60], expected 246, is {}",
                    msg.certificate_bytes[60]
                );
                assert_eq!(
                    msg.certificate_bytes[61], 39,
                    "incorrect value for certificate_bytes[61], expected 39, is {}",
                    msg.certificate_bytes[61]
                );
                assert_eq!(
                    msg.certificate_bytes[62], 226,
                    "incorrect value for certificate_bytes[62], expected 226, is {}",
                    msg.certificate_bytes[62]
                );
                assert_eq!(
                    msg.certificate_bytes[63], 205,
                    "incorrect value for certificate_bytes[63], expected 205, is {}",
                    msg.certificate_bytes[63]
                );
                assert_eq!(
                    msg.certificate_bytes[64], 198,
                    "incorrect value for certificate_bytes[64], expected 198, is {}",
                    msg.certificate_bytes[64]
                );
                assert_eq!(
                    msg.certificate_bytes[65], 178,
                    "incorrect value for certificate_bytes[65], expected 178, is {}",
                    msg.certificate_bytes[65]
                );
                assert_eq!(
                    msg.certificate_bytes[66], 196,
                    "incorrect value for certificate_bytes[66], expected 196, is {}",
                    msg.certificate_bytes[66]
                );
                assert_eq!(
                    msg.certificate_bytes[67], 5,
                    "incorrect value for certificate_bytes[67], expected 5, is {}",
                    msg.certificate_bytes[67]
                );
                assert_eq!(
                    msg.certificate_bytes[68], 81,
                    "incorrect value for certificate_bytes[68], expected 81, is {}",
                    msg.certificate_bytes[68]
                );
                assert_eq!(
                    msg.certificate_bytes[69], 9,
                    "incorrect value for certificate_bytes[69], expected 9, is {}",
                    msg.certificate_bytes[69]
                );
                assert_eq!(
                    msg.certificate_bytes[70], 44,
                    "incorrect value for certificate_bytes[70], expected 44, is {}",
                    msg.certificate_bytes[70]
                );
                assert_eq!(
                    msg.certificate_bytes[71], 164,
                    "incorrect value for certificate_bytes[71], expected 164, is {}",
                    msg.certificate_bytes[71]
                );
                assert_eq!(
                    msg.certificate_bytes[72], 163,
                    "incorrect value for certificate_bytes[72], expected 163, is {}",
                    msg.certificate_bytes[72]
                );
                assert_eq!(
                    msg.certificate_bytes[73], 214,
                    "incorrect value for certificate_bytes[73], expected 214, is {}",
                    msg.certificate_bytes[73]
                );
                assert_eq!(
                    msg.certificate_bytes[74], 138,
                    "incorrect value for certificate_bytes[74], expected 138, is {}",
                    msg.certificate_bytes[74]
                );
                assert_eq!(
                    msg.certificate_bytes[75], 123,
                    "incorrect value for certificate_bytes[75], expected 123, is {}",
                    msg.certificate_bytes[75]
                );
                assert_eq!(
                    msg.certificate_bytes[76], 76,
                    "incorrect value for certificate_bytes[76], expected 76, is {}",
                    msg.certificate_bytes[76]
                );
                assert_eq!(
                    msg.certificate_bytes[77], 74,
                    "incorrect value for certificate_bytes[77], expected 74, is {}",
                    msg.certificate_bytes[77]
                );
                assert_eq!(
                    msg.certificate_bytes[78], 237,
                    "incorrect value for certificate_bytes[78], expected 237, is {}",
                    msg.certificate_bytes[78]
                );
                assert_eq!(
                    msg.certificate_bytes[79], 121,
                    "incorrect value for certificate_bytes[79], expected 121, is {}",
                    msg.certificate_bytes[79]
                );
                assert_eq!(
                    msg.certificate_bytes[80], 13,
                    "incorrect value for certificate_bytes[80], expected 13, is {}",
                    msg.certificate_bytes[80]
                );
                assert_eq!(
                    msg.certificate_bytes[81], 137,
                    "incorrect value for certificate_bytes[81], expected 137, is {}",
                    msg.certificate_bytes[81]
                );
                assert_eq!(
                    msg.certificate_bytes[82], 186,
                    "incorrect value for certificate_bytes[82], expected 186, is {}",
                    msg.certificate_bytes[82]
                );
                assert_eq!(
                    msg.certificate_bytes[83], 97,
                    "incorrect value for certificate_bytes[83], expected 97, is {}",
                    msg.certificate_bytes[83]
                );
                assert_eq!(
                    msg.certificate_bytes[84], 193,
                    "incorrect value for certificate_bytes[84], expected 193, is {}",
                    msg.certificate_bytes[84]
                );
                assert_eq!(
                    msg.certificate_bytes[85], 189,
                    "incorrect value for certificate_bytes[85], expected 189, is {}",
                    msg.certificate_bytes[85]
                );
                assert_eq!(
                    msg.certificate_bytes[86], 200,
                    "incorrect value for certificate_bytes[86], expected 200, is {}",
                    msg.certificate_bytes[86]
                );
                assert_eq!(
                    msg.certificate_bytes[87], 124,
                    "incorrect value for certificate_bytes[87], expected 124, is {}",
                    msg.certificate_bytes[87]
                );
                assert_eq!(
                    msg.certificate_bytes[88], 69,
                    "incorrect value for certificate_bytes[88], expected 69, is {}",
                    msg.certificate_bytes[88]
                );
                assert_eq!(
                    msg.certificate_bytes[89], 115,
                    "incorrect value for certificate_bytes[89], expected 115, is {}",
                    msg.certificate_bytes[89]
                );
                assert_eq!(
                    msg.certificate_bytes[90], 230,
                    "incorrect value for certificate_bytes[90], expected 230, is {}",
                    msg.certificate_bytes[90]
                );
                assert_eq!(
                    msg.certificate_bytes[91], 159,
                    "incorrect value for certificate_bytes[91], expected 159, is {}",
                    msg.certificate_bytes[91]
                );
                assert_eq!(
                    msg.certificate_bytes[92], 185,
                    "incorrect value for certificate_bytes[92], expected 185, is {}",
                    msg.certificate_bytes[92]
                );
                assert_eq!(
                    msg.certificate_bytes[93], 158,
                    "incorrect value for certificate_bytes[93], expected 158, is {}",
                    msg.certificate_bytes[93]
                );
                assert_eq!(
                    msg.certificate_bytes[94], 51,
                    "incorrect value for certificate_bytes[94], expected 51, is {}",
                    msg.certificate_bytes[94]
                );
                assert_eq!(
                    msg.certificate_bytes[95], 12,
                    "incorrect value for certificate_bytes[95], expected 12, is {}",
                    msg.certificate_bytes[95]
                );
                assert_eq!(
                    msg.certificate_bytes[96], 225,
                    "incorrect value for certificate_bytes[96], expected 225, is {}",
                    msg.certificate_bytes[96]
                );
                assert_eq!(
                    msg.certificate_bytes[97], 65,
                    "incorrect value for certificate_bytes[97], expected 65, is {}",
                    msg.certificate_bytes[97]
                );
                assert_eq!(
                    msg.certificate_bytes[98], 192,
                    "incorrect value for certificate_bytes[98], expected 192, is {}",
                    msg.certificate_bytes[98]
                );
                assert_eq!(
                    msg.certificate_bytes[99], 105,
                    "incorrect value for certificate_bytes[99], expected 105, is {}",
                    msg.certificate_bytes[99]
                );
                assert_eq!(
                    msg.certificate_bytes[100], 56,
                    "incorrect value for certificate_bytes[100], expected 56, is {}",
                    msg.certificate_bytes[100]
                );
                assert_eq!(
                    msg.certificate_bytes[101], 41,
                    "incorrect value for certificate_bytes[101], expected 41, is {}",
                    msg.certificate_bytes[101]
                );
                assert_eq!(
                    msg.certificate_bytes[102], 85,
                    "incorrect value for certificate_bytes[102], expected 85, is {}",
                    msg.certificate_bytes[102]
                );
                assert_eq!(
                    msg.certificate_bytes[103], 133,
                    "incorrect value for certificate_bytes[103], expected 133, is {}",
                    msg.certificate_bytes[103]
                );
                assert_eq!(
                    msg.certificate_bytes[104], 19,
                    "incorrect value for certificate_bytes[104], expected 19, is {}",
                    msg.certificate_bytes[104]
                );
                assert_eq!(
                    msg.certificate_bytes[105], 217,
                    "incorrect value for certificate_bytes[105], expected 217, is {}",
                    msg.certificate_bytes[105]
                );
                assert_eq!(
                    msg.certificate_bytes[106], 166,
                    "incorrect value for certificate_bytes[106], expected 166, is {}",
                    msg.certificate_bytes[106]
                );
                assert_eq!(
                    msg.certificate_bytes[107], 48,
                    "incorrect value for certificate_bytes[107], expected 48, is {}",
                    msg.certificate_bytes[107]
                );
                assert_eq!(
                    msg.certificate_bytes[108], 139,
                    "incorrect value for certificate_bytes[108], expected 139, is {}",
                    msg.certificate_bytes[108]
                );
                assert_eq!(
                    msg.certificate_bytes[109], 131,
                    "incorrect value for certificate_bytes[109], expected 131, is {}",
                    msg.certificate_bytes[109]
                );
                assert_eq!(
                    msg.certificate_bytes[110], 96,
                    "incorrect value for certificate_bytes[110], expected 96, is {}",
                    msg.certificate_bytes[110]
                );
                assert_eq!(
                    msg.certificate_bytes[111], 216,
                    "incorrect value for certificate_bytes[111], expected 216, is {}",
                    msg.certificate_bytes[111]
                );
                assert_eq!(
                    msg.certificate_bytes[112], 98,
                    "incorrect value for certificate_bytes[112], expected 98, is {}",
                    msg.certificate_bytes[112]
                );
                assert_eq!(
                    msg.certificate_bytes[113], 147,
                    "incorrect value for certificate_bytes[113], expected 147, is {}",
                    msg.certificate_bytes[113]
                );
                assert_eq!(
                    msg.certificate_bytes[114], 132,
                    "incorrect value for certificate_bytes[114], expected 132, is {}",
                    msg.certificate_bytes[114]
                );
                assert_eq!(
                    msg.certificate_bytes[115], 234,
                    "incorrect value for certificate_bytes[115], expected 234, is {}",
                    msg.certificate_bytes[115]
                );
                assert_eq!(
                    msg.certificate_bytes[116], 167,
                    "incorrect value for certificate_bytes[116], expected 167, is {}",
                    msg.certificate_bytes[116]
                );
                assert_eq!(
                    msg.certificate_bytes[117], 248,
                    "incorrect value for certificate_bytes[117], expected 248, is {}",
                    msg.certificate_bytes[117]
                );
                assert_eq!(
                    msg.certificate_bytes[118], 247,
                    "incorrect value for certificate_bytes[118], expected 247, is {}",
                    msg.certificate_bytes[118]
                );
                assert_eq!(
                    msg.certificate_bytes[119], 32,
                    "incorrect value for certificate_bytes[119], expected 32, is {}",
                    msg.certificate_bytes[119]
                );
                assert_eq!(
                    msg.certificate_bytes[120], 239,
                    "incorrect value for certificate_bytes[120], expected 239, is {}",
                    msg.certificate_bytes[120]
                );
                assert_eq!(
                    msg.certificate_bytes[121], 194,
                    "incorrect value for certificate_bytes[121], expected 194, is {}",
                    msg.certificate_bytes[121]
                );
                assert_eq!(
                    msg.certificate_bytes[122], 188,
                    "incorrect value for certificate_bytes[122], expected 188, is {}",
                    msg.certificate_bytes[122]
                );
                assert_eq!(
                    msg.certificate_bytes[123], 254,
                    "incorrect value for certificate_bytes[123], expected 254, is {}",
                    msg.certificate_bytes[123]
                );
                assert_eq!(
                    msg.certificate_bytes[124], 114,
                    "incorrect value for certificate_bytes[124], expected 114, is {}",
                    msg.certificate_bytes[124]
                );
                assert_eq!(
                    msg.certificate_bytes[125], 117,
                    "incorrect value for certificate_bytes[125], expected 117, is {}",
                    msg.certificate_bytes[125]
                );
                assert_eq!(
                    msg.certificate_bytes[126], 83,
                    "incorrect value for certificate_bytes[126], expected 83, is {}",
                    msg.certificate_bytes[126]
                );
                assert_eq!(
                    msg.certificate_bytes[127], 25,
                    "incorrect value for certificate_bytes[127], expected 25, is {}",
                    msg.certificate_bytes[127]
                );
                assert_eq!(
                    msg.certificate_bytes[128], 251,
                    "incorrect value for certificate_bytes[128], expected 251, is {}",
                    msg.certificate_bytes[128]
                );
                assert_eq!(
                    msg.certificate_bytes[129], 191,
                    "incorrect value for certificate_bytes[129], expected 191, is {}",
                    msg.certificate_bytes[129]
                );
                assert_eq!(
                    msg.certificate_bytes[130], 104,
                    "incorrect value for certificate_bytes[130], expected 104, is {}",
                    msg.certificate_bytes[130]
                );
                assert_eq!(
                    msg.certificate_bytes[131], 240,
                    "incorrect value for certificate_bytes[131], expected 240, is {}",
                    msg.certificate_bytes[131]
                );
                assert_eq!(
                    msg.certificate_bytes[132], 118,
                    "incorrect value for certificate_bytes[132], expected 118, is {}",
                    msg.certificate_bytes[132]
                );
                assert_eq!(
                    msg.certificate_bytes[133], 68,
                    "incorrect value for certificate_bytes[133], expected 68, is {}",
                    msg.certificate_bytes[133]
                );
                assert_eq!(
                    msg.certificate_bytes[134], 42,
                    "incorrect value for certificate_bytes[134], expected 42, is {}",
                    msg.certificate_bytes[134]
                );
                assert_eq!(
                    msg.certificate_bytes[135], 93,
                    "incorrect value for certificate_bytes[135], expected 93, is {}",
                    msg.certificate_bytes[135]
                );
                assert_eq!(
                    msg.certificate_bytes[136], 18,
                    "incorrect value for certificate_bytes[136], expected 18, is {}",
                    msg.certificate_bytes[136]
                );
                assert_eq!(
                    msg.certificate_bytes[137], 16,
                    "incorrect value for certificate_bytes[137], expected 16, is {}",
                    msg.certificate_bytes[137]
                );
                assert_eq!(
                    msg.certificate_bytes[138], 37,
                    "incorrect value for certificate_bytes[138], expected 37, is {}",
                    msg.certificate_bytes[138]
                );
                assert_eq!(
                    msg.certificate_bytes[139], 232,
                    "incorrect value for certificate_bytes[139], expected 232, is {}",
                    msg.certificate_bytes[139]
                );
                assert_eq!(
                    msg.certificate_bytes[140], 99,
                    "incorrect value for certificate_bytes[140], expected 99, is {}",
                    msg.certificate_bytes[140]
                );
                assert_eq!(
                    msg.certificate_bytes[141], 179,
                    "incorrect value for certificate_bytes[141], expected 179, is {}",
                    msg.certificate_bytes[141]
                );
                assert_eq!(
                    msg.certificate_bytes[142], 23,
                    "incorrect value for certificate_bytes[142], expected 23, is {}",
                    msg.certificate_bytes[142]
                );
                assert_eq!(
                    msg.certificate_bytes[143], 90,
                    "incorrect value for certificate_bytes[143], expected 90, is {}",
                    msg.certificate_bytes[143]
                );
                assert_eq!(
                    msg.certificate_bytes[144], 94,
                    "incorrect value for certificate_bytes[144], expected 94, is {}",
                    msg.certificate_bytes[144]
                );
                assert_eq!(
                    msg.certificate_bytes[145], 136,
                    "incorrect value for certificate_bytes[145], expected 136, is {}",
                    msg.certificate_bytes[145]
                );
                assert_eq!(
                    msg.certificate_bytes[146], 6,
                    "incorrect value for certificate_bytes[146], expected 6, is {}",
                    msg.certificate_bytes[146]
                );
                assert_eq!(
                    msg.certificate_bytes[147], 125,
                    "incorrect value for certificate_bytes[147], expected 125, is {}",
                    msg.certificate_bytes[147]
                );
                assert_eq!(
                    msg.certificate_bytes[148], 91,
                    "incorrect value for certificate_bytes[148], expected 91, is {}",
                    msg.certificate_bytes[148]
                );
                assert_eq!(
                    msg.certificate_bytes[149], 255,
                    "incorrect value for certificate_bytes[149], expected 255, is {}",
                    msg.certificate_bytes[149]
                );
                assert_eq!(
                    msg.certificate_bytes[150], 15,
                    "incorrect value for certificate_bytes[150], expected 15, is {}",
                    msg.certificate_bytes[150]
                );
                assert_eq!(
                    msg.certificate_bytes[151], 71,
                    "incorrect value for certificate_bytes[151], expected 71, is {}",
                    msg.certificate_bytes[151]
                );
                assert_eq!(
                    msg.certificate_bytes[152], 43,
                    "incorrect value for certificate_bytes[152], expected 43, is {}",
                    msg.certificate_bytes[152]
                );
                assert_eq!(
                    msg.certificate_bytes[153], 46,
                    "incorrect value for certificate_bytes[153], expected 46, is {}",
                    msg.certificate_bytes[153]
                );
                assert_eq!(
                    msg.certificate_bytes[154], 25,
                    "incorrect value for certificate_bytes[154], expected 25, is {}",
                    msg.certificate_bytes[154]
                );
                assert_eq!(
                    msg.certificate_bytes[155], 252,
                    "incorrect value for certificate_bytes[155], expected 252, is {}",
                    msg.certificate_bytes[155]
                );
                assert_eq!(
                    msg.certificate_bytes[156], 229,
                    "incorrect value for certificate_bytes[156], expected 229, is {}",
                    msg.certificate_bytes[156]
                );
                assert_eq!(
                    msg.certificate_bytes[157], 80,
                    "incorrect value for certificate_bytes[157], expected 80, is {}",
                    msg.certificate_bytes[157]
                );
                assert_eq!(
                    msg.certificate_bytes[158], 143,
                    "incorrect value for certificate_bytes[158], expected 143, is {}",
                    msg.certificate_bytes[158]
                );
                assert_eq!(
                    msg.certificate_bytes[159], 58,
                    "incorrect value for certificate_bytes[159], expected 58, is {}",
                    msg.certificate_bytes[159]
                );
                assert_eq!(
                    msg.certificate_bytes[160], 241,
                    "incorrect value for certificate_bytes[160], expected 241, is {}",
                    msg.certificate_bytes[160]
                );
                assert_eq!(
                    msg.certificate_bytes[161], 11,
                    "incorrect value for certificate_bytes[161], expected 11, is {}",
                    msg.certificate_bytes[161]
                );
                assert_eq!(
                    msg.certificate_bytes[162], 62,
                    "incorrect value for certificate_bytes[162], expected 62, is {}",
                    msg.certificate_bytes[162]
                );
                assert_eq!(
                    msg.certificate_bytes[163], 181,
                    "incorrect value for certificate_bytes[163], expected 181, is {}",
                    msg.certificate_bytes[163]
                );
                assert_eq!(
                    msg.certificate_bytes[164], 155,
                    "incorrect value for certificate_bytes[164], expected 155, is {}",
                    msg.certificate_bytes[164]
                );
                assert_eq!(
                    msg.certificate_bytes[165], 53,
                    "incorrect value for certificate_bytes[165], expected 53, is {}",
                    msg.certificate_bytes[165]
                );
                assert_eq!(
                    msg.certificate_bytes[166], 153,
                    "incorrect value for certificate_bytes[166], expected 153, is {}",
                    msg.certificate_bytes[166]
                );
                assert_eq!(
                    msg.certificate_bytes[167], 149,
                    "incorrect value for certificate_bytes[167], expected 149, is {}",
                    msg.certificate_bytes[167]
                );
                assert_eq!(
                    msg.certificate_bytes[168], 152,
                    "incorrect value for certificate_bytes[168], expected 152, is {}",
                    msg.certificate_bytes[168]
                );
                assert_eq!(
                    msg.certificate_bytes[169], 227,
                    "incorrect value for certificate_bytes[169], expected 227, is {}",
                    msg.certificate_bytes[169]
                );
                assert_eq!(
                    msg.certificate_bytes[170], 150,
                    "incorrect value for certificate_bytes[170], expected 150, is {}",
                    msg.certificate_bytes[170]
                );
                assert_eq!(
                    msg.certificate_bytes[171], 87,
                    "incorrect value for certificate_bytes[171], expected 87, is {}",
                    msg.certificate_bytes[171]
                );
                assert_eq!(
                    msg.certificate_bytes[172], 112,
                    "incorrect value for certificate_bytes[172], expected 112, is {}",
                    msg.certificate_bytes[172]
                );
                assert_eq!(
                    msg.certificate_bytes[173], 165,
                    "incorrect value for certificate_bytes[173], expected 165, is {}",
                    msg.certificate_bytes[173]
                );
                assert_eq!(
                    msg.certificate_bytes[174], 2,
                    "incorrect value for certificate_bytes[174], expected 2, is {}",
                    msg.certificate_bytes[174]
                );
                assert_eq!(
                    msg.certificate_bytes[175], 128,
                    "incorrect value for certificate_bytes[175], expected 128, is {}",
                    msg.certificate_bytes[175]
                );
                assert_eq!(
                    msg.certificate_bytes[176], 231,
                    "incorrect value for certificate_bytes[176], expected 231, is {}",
                    msg.certificate_bytes[176]
                );
                assert_eq!(
                    msg.certificate_bytes[177], 25,
                    "incorrect value for certificate_bytes[177], expected 25, is {}",
                    msg.certificate_bytes[177]
                );
                assert_eq!(
                    msg.certificate_bytes[178], 157,
                    "incorrect value for certificate_bytes[178], expected 157, is {}",
                    msg.certificate_bytes[178]
                );
                assert_eq!(
                    msg.certificate_bytes[179], 244,
                    "incorrect value for certificate_bytes[179], expected 244, is {}",
                    msg.certificate_bytes[179]
                );
                assert_eq!(
                    msg.certificate_bytes[180], 204,
                    "incorrect value for certificate_bytes[180], expected 204, is {}",
                    msg.certificate_bytes[180]
                );
                assert_eq!(
                    msg.certificate_bytes[181], 108,
                    "incorrect value for certificate_bytes[181], expected 108, is {}",
                    msg.certificate_bytes[181]
                );
                assert_eq!(
                    msg.certificate_bytes[182], 253,
                    "incorrect value for certificate_bytes[182], expected 253, is {}",
                    msg.certificate_bytes[182]
                );
                assert_eq!(
                    msg.certificate_bytes[183], 127,
                    "incorrect value for certificate_bytes[183], expected 127, is {}",
                    msg.certificate_bytes[183]
                );
                assert_eq!(
                    msg.certificate_bytes[184], 122,
                    "incorrect value for certificate_bytes[184], expected 122, is {}",
                    msg.certificate_bytes[184]
                );
                assert_eq!(
                    msg.certificate_bytes[185], 145,
                    "incorrect value for certificate_bytes[185], expected 145, is {}",
                    msg.certificate_bytes[185]
                );
                assert_eq!(
                    msg.certificate_bytes[186], 113,
                    "incorrect value for certificate_bytes[186], expected 113, is {}",
                    msg.certificate_bytes[186]
                );
                assert_eq!(
                    msg.certificate_bytes[187], 162,
                    "incorrect value for certificate_bytes[187], expected 162, is {}",
                    msg.certificate_bytes[187]
                );
                assert_eq!(
                    msg.certificate_bytes[188], 197,
                    "incorrect value for certificate_bytes[188], expected 197, is {}",
                    msg.certificate_bytes[188]
                );
                assert_eq!(
                    msg.certificate_bytes[189], 171,
                    "incorrect value for certificate_bytes[189], expected 171, is {}",
                    msg.certificate_bytes[189]
                );
                assert_eq!(
                    msg.certificate_bytes[190], 199,
                    "incorrect value for certificate_bytes[190], expected 199, is {}",
                    msg.certificate_bytes[190]
                );
                assert_eq!(
                    msg.certificate_bytes[191], 54,
                    "incorrect value for certificate_bytes[191], expected 54, is {}",
                    msg.certificate_bytes[191]
                );
                assert_eq!(
                    msg.certificate_bytes[192], 184,
                    "incorrect value for certificate_bytes[192], expected 184, is {}",
                    msg.certificate_bytes[192]
                );
                assert_eq!(
                    msg.certificate_bytes[193], 222,
                    "incorrect value for certificate_bytes[193], expected 222, is {}",
                    msg.certificate_bytes[193]
                );
                assert_eq!(
                    msg.certificate_bytes[194], 206,
                    "incorrect value for certificate_bytes[194], expected 206, is {}",
                    msg.certificate_bytes[194]
                );
                assert_eq!(
                    msg.certificate_bytes[195], 67,
                    "incorrect value for certificate_bytes[195], expected 67, is {}",
                    msg.certificate_bytes[195]
                );
                assert_eq!(
                    msg.certificate_bytes[196], 144,
                    "incorrect value for certificate_bytes[196], expected 144, is {}",
                    msg.certificate_bytes[196]
                );
                assert_eq!(
                    msg.certificate_bytes[197], 78,
                    "incorrect value for certificate_bytes[197], expected 78, is {}",
                    msg.certificate_bytes[197]
                );
                assert_eq!(
                    msg.certificate_bytes[198], 187,
                    "incorrect value for certificate_bytes[198], expected 187, is {}",
                    msg.certificate_bytes[198]
                );
                assert_eq!(
                    msg.certificate_bytes[199], 207,
                    "incorrect value for certificate_bytes[199], expected 207, is {}",
                    msg.certificate_bytes[199]
                );
                assert_eq!(
                    msg.certificate_bytes[200], 60,
                    "incorrect value for certificate_bytes[200], expected 60, is {}",
                    msg.certificate_bytes[200]
                );
                assert_eq!(
                    msg.certificate_bytes[201], 211,
                    "incorrect value for certificate_bytes[201], expected 211, is {}",
                    msg.certificate_bytes[201]
                );
                assert_eq!(
                    msg.certificate_bytes[202], 141,
                    "incorrect value for certificate_bytes[202], expected 141, is {}",
                    msg.certificate_bytes[202]
                );
                assert_eq!(
                    msg.certificate_bytes[203], 135,
                    "incorrect value for certificate_bytes[203], expected 135, is {}",
                    msg.certificate_bytes[203]
                );
                assert_eq!(
                    msg.certificate_bytes[204], 106,
                    "incorrect value for certificate_bytes[204], expected 106, is {}",
                    msg.certificate_bytes[204]
                );
                assert_eq!(
                    msg.certificate_bytes[205], 220,
                    "incorrect value for certificate_bytes[205], expected 220, is {}",
                    msg.certificate_bytes[205]
                );
                assert_eq!(
                    msg.certificate_bytes[206], 79,
                    "incorrect value for certificate_bytes[206], expected 79, is {}",
                    msg.certificate_bytes[206]
                );
                assert_eq!(
                    msg.certificate_bytes[207], 183,
                    "incorrect value for certificate_bytes[207], expected 183, is {}",
                    msg.certificate_bytes[207]
                );
                assert_eq!(
                    msg.certificate_bytes[208], 245,
                    "incorrect value for certificate_bytes[208], expected 245, is {}",
                    msg.certificate_bytes[208]
                );
                assert_eq!(
                    msg.certificate_bytes[209], 21,
                    "incorrect value for certificate_bytes[209], expected 21, is {}",
                    msg.certificate_bytes[209]
                );
                assert_eq!(
                    msg.certificate_bytes[210], 161,
                    "incorrect value for certificate_bytes[210], expected 161, is {}",
                    msg.certificate_bytes[210]
                );
                assert_eq!(
                    msg.certificate_bytes[211], 168,
                    "incorrect value for certificate_bytes[211], expected 168, is {}",
                    msg.certificate_bytes[211]
                );
                assert_eq!(
                    msg.certificate_bytes[212], 34,
                    "incorrect value for certificate_bytes[212], expected 34, is {}",
                    msg.certificate_bytes[212]
                );
                assert_eq!(
                    msg.certificate_bytes[213], 129,
                    "incorrect value for certificate_bytes[213], expected 129, is {}",
                    msg.certificate_bytes[213]
                );
                assert_eq!(
                    msg.certificate_bytes[214], 50,
                    "incorrect value for certificate_bytes[214], expected 50, is {}",
                    msg.certificate_bytes[214]
                );
                assert_eq!(
                    msg.certificate_bytes[215], 176,
                    "incorrect value for certificate_bytes[215], expected 176, is {}",
                    msg.certificate_bytes[215]
                );
                assert_eq!(
                    msg.certificate_bytes[216], 1,
                    "incorrect value for certificate_bytes[216], expected 1, is {}",
                    msg.certificate_bytes[216]
                );
                assert_eq!(
                    msg.certificate_bytes[217], 218,
                    "incorrect value for certificate_bytes[217], expected 218, is {}",
                    msg.certificate_bytes[217]
                );
                assert_eq!(
                    msg.certificate_bytes[218], 20,
                    "incorrect value for certificate_bytes[218], expected 20, is {}",
                    msg.certificate_bytes[218]
                );
                assert_eq!(
                    msg.certificate_bytes[219], 130,
                    "incorrect value for certificate_bytes[219], expected 130, is {}",
                    msg.certificate_bytes[219]
                );
                assert_eq!(
                    msg.certificate_bytes[220], 59,
                    "incorrect value for certificate_bytes[220], expected 59, is {}",
                    msg.certificate_bytes[220]
                );
                assert_eq!(
                    msg.certificate_bytes[221], 249,
                    "incorrect value for certificate_bytes[221], expected 249, is {}",
                    msg.certificate_bytes[221]
                );
                assert_eq!(
                    msg.certificate_bytes[222], 109,
                    "incorrect value for certificate_bytes[222], expected 109, is {}",
                    msg.certificate_bytes[222]
                );
                assert_eq!(
                    msg.certificate_bytes[223], 219,
                    "incorrect value for certificate_bytes[223], expected 219, is {}",
                    msg.certificate_bytes[223]
                );
                assert_eq!(
                    msg.certificate_bytes[224], 0,
                    "incorrect value for certificate_bytes[224], expected 0, is {}",
                    msg.certificate_bytes[224]
                );
                assert_eq!(
                    msg.certificate_bytes[225], 100,
                    "incorrect value for certificate_bytes[225], expected 100, is {}",
                    msg.certificate_bytes[225]
                );
                assert_eq!(
                    msg.certificate_bytes[226], 103,
                    "incorrect value for certificate_bytes[226], expected 103, is {}",
                    msg.certificate_bytes[226]
                );
                assert_eq!(
                    msg.certificate_bytes[227], 55,
                    "incorrect value for certificate_bytes[227], expected 55, is {}",
                    msg.certificate_bytes[227]
                );
                assert_eq!(
                    msg.certificate_bytes[228], 29,
                    "incorrect value for certificate_bytes[228], expected 29, is {}",
                    msg.certificate_bytes[228]
                );
                assert_eq!(
                    msg.certificate_bytes[229], 242,
                    "incorrect value for certificate_bytes[229], expected 242, is {}",
                    msg.certificate_bytes[229]
                );
                assert_eq!(
                    msg.certificate_bytes[230], 110,
                    "incorrect value for certificate_bytes[230], expected 110, is {}",
                    msg.certificate_bytes[230]
                );
                assert_eq!(
                    msg.certificate_bytes[231], 154,
                    "incorrect value for certificate_bytes[231], expected 154, is {}",
                    msg.certificate_bytes[231]
                );
                assert_eq!(
                    msg.certificate_bytes[232], 190,
                    "incorrect value for certificate_bytes[232], expected 190, is {}",
                    msg.certificate_bytes[232]
                );
                assert_eq!(
                    msg.certificate_bytes[233], 233,
                    "incorrect value for certificate_bytes[233], expected 233, is {}",
                    msg.certificate_bytes[233]
                );
                assert_eq!(
                    msg.certificate_bytes[234], 142,
                    "incorrect value for certificate_bytes[234], expected 142, is {}",
                    msg.certificate_bytes[234]
                );
                assert_eq!(
                    msg.certificate_bytes[235], 45,
                    "incorrect value for certificate_bytes[235], expected 45, is {}",
                    msg.certificate_bytes[235]
                );
                assert_eq!(
                    msg.certificate_bytes[236], 61,
                    "incorrect value for certificate_bytes[236], expected 61, is {}",
                    msg.certificate_bytes[236]
                );
                assert_eq!(
                    msg.certificate_bytes[237], 215,
                    "incorrect value for certificate_bytes[237], expected 215, is {}",
                    msg.certificate_bytes[237]
                );
                assert_eq!(
                    msg.certificate_bytes[238], 202,
                    "incorrect value for certificate_bytes[238], expected 202, is {}",
                    msg.certificate_bytes[238]
                );
                assert_eq!(
                    msg.certificate_bytes[239], 238,
                    "incorrect value for certificate_bytes[239], expected 238, is {}",
                    msg.certificate_bytes[239]
                );
                assert_eq!(
                    msg.certificate_bytes[240], 88,
                    "incorrect value for certificate_bytes[240], expected 88, is {}",
                    msg.certificate_bytes[240]
                );
                assert_eq!(
                    msg.certificate_bytes[241], 209,
                    "incorrect value for certificate_bytes[241], expected 209, is {}",
                    msg.certificate_bytes[241]
                );
                assert_eq!(
                    msg.certificate_bytes[242], 70,
                    "incorrect value for certificate_bytes[242], expected 70, is {}",
                    msg.certificate_bytes[242]
                );
                assert_eq!(
                    msg.certificate_bytes[243], 63,
                    "incorrect value for certificate_bytes[243], expected 63, is {}",
                    msg.certificate_bytes[243]
                );
                assert_eq!(
                    msg.certificate_bytes[244], 151,
                    "incorrect value for certificate_bytes[244], expected 151, is {}",
                    msg.certificate_bytes[244]
                );
                assert_eq!(
                    msg.certificate_bytes[245], 27,
                    "incorrect value for certificate_bytes[245], expected 27, is {}",
                    msg.certificate_bytes[245]
                );
                assert_eq!(
                    msg.certificate_bytes[246], 102,
                    "incorrect value for certificate_bytes[246], expected 102, is {}",
                    msg.certificate_bytes[246]
                );
                assert_eq!(
                    msg.certificate_id[0], 10,
                    "incorrect value for certificate_id[0], expected 10, is {}",
                    msg.certificate_id[0]
                );
                assert_eq!(
                    msg.certificate_id[1], 11,
                    "incorrect value for certificate_id[1], expected 11, is {}",
                    msg.certificate_id[1]
                );
                assert_eq!(
                    msg.certificate_id[2], 12,
                    "incorrect value for certificate_id[2], expected 12, is {}",
                    msg.certificate_id[2]
                );
                assert_eq!(
                    msg.certificate_id[3], 13,
                    "incorrect value for certificate_id[3], expected 13, is {}",
                    msg.certificate_id[3]
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_msg, 48,
                    "incorrect value for n_msg, expected 48, is {}",
                    msg.n_msg
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEcdsaCertificate"),
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
fn test_json2sbp_auto_check_sbp_signing_msg_ecdsa_certificate() {
    {
        let json_input = r#"{"preamble": 85, "msg_type": 3076, "sender": 66, "length": 253, "payload": "MAoLDA0CtKB0TfMcrSRWIQgfeElAqZTgOV8RKNVcw5Lr5LFlUrYZrKr67Ad3BMkKDtAvfjHSrkvdyxhCNCMaHoxv9ifizcayxAVRCSyko9aKe0xK7XkNibphwb3IfEVz5p+5njMM4UHAaTgpVYUT2aYwi4Ng2GKThOqn+Pcg78K8/nJ1Uxn7v2jwdkQqXRIQJehjsxdaXogGfVv/D0crLhn85VCPOvELPrWbNZmVmOOWV3ClAoDnGZ30zGz9f3qRcaLFq8c2uN7OQ5BOu888042HatxPt/UVoagigTKwAdoUgjv5bdsAZGc3HfJumr7pji0918ruWNFGP5cbZg==", "crc": 7899, "n_msg": 48, "certificate_id": [10, 11, 12, 13], "flags": 2, "certificate_bytes": [180, 160, 116, 77, 243, 28, 173, 36, 86, 33, 8, 31, 120, 73, 64, 169, 148, 224, 57, 95, 17, 40, 213, 92, 195, 146, 235, 228, 177, 101, 82, 182, 25, 172, 170, 250, 236, 7, 119, 4, 201, 10, 14, 208, 47, 126, 49, 210, 174, 75, 221, 203, 24, 66, 52, 35, 26, 30, 140, 111, 246, 39, 226, 205, 198, 178, 196, 5, 81, 9, 44, 164, 163, 214, 138, 123, 76, 74, 237, 121, 13, 137, 186, 97, 193, 189, 200, 124, 69, 115, 230, 159, 185, 158, 51, 12, 225, 65, 192, 105, 56, 41, 85, 133, 19, 217, 166, 48, 139, 131, 96, 216, 98, 147, 132, 234, 167, 248, 247, 32, 239, 194, 188, 254, 114, 117, 83, 25, 251, 191, 104, 240, 118, 68, 42, 93, 18, 16, 37, 232, 99, 179, 23, 90, 94, 136, 6, 125, 91, 255, 15, 71, 43, 46, 25, 252, 229, 80, 143, 58, 241, 11, 62, 181, 155, 53, 153, 149, 152, 227, 150, 87, 112, 165, 2, 128, 231, 25, 157, 244, 204, 108, 253, 127, 122, 145, 113, 162, 197, 171, 199, 54, 184, 222, 206, 67, 144, 78, 187, 207, 60, 211, 141, 135, 106, 220, 79, 183, 245, 21, 161, 168, 34, 129, 50, 176, 1, 218, 20, 130, 59, 249, 109, 219, 0, 100, 103, 55, 29, 242, 110, 154, 190, 233, 142, 45, 61, 215, 202, 238, 88, 209, 70, 63, 151, 27, 102]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgEcdsaCertificate(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xC04,
                    "Incorrect message type, expected 0xC04, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {sender_id}"
                );
                assert_eq!(
                    msg.certificate_bytes[0], 180,
                    "incorrect value for certificate_bytes[0], expected 180, is {}",
                    msg.certificate_bytes[0]
                );
                assert_eq!(
                    msg.certificate_bytes[1], 160,
                    "incorrect value for certificate_bytes[1], expected 160, is {}",
                    msg.certificate_bytes[1]
                );
                assert_eq!(
                    msg.certificate_bytes[2], 116,
                    "incorrect value for certificate_bytes[2], expected 116, is {}",
                    msg.certificate_bytes[2]
                );
                assert_eq!(
                    msg.certificate_bytes[3], 77,
                    "incorrect value for certificate_bytes[3], expected 77, is {}",
                    msg.certificate_bytes[3]
                );
                assert_eq!(
                    msg.certificate_bytes[4], 243,
                    "incorrect value for certificate_bytes[4], expected 243, is {}",
                    msg.certificate_bytes[4]
                );
                assert_eq!(
                    msg.certificate_bytes[5], 28,
                    "incorrect value for certificate_bytes[5], expected 28, is {}",
                    msg.certificate_bytes[5]
                );
                assert_eq!(
                    msg.certificate_bytes[6], 173,
                    "incorrect value for certificate_bytes[6], expected 173, is {}",
                    msg.certificate_bytes[6]
                );
                assert_eq!(
                    msg.certificate_bytes[7], 36,
                    "incorrect value for certificate_bytes[7], expected 36, is {}",
                    msg.certificate_bytes[7]
                );
                assert_eq!(
                    msg.certificate_bytes[8], 86,
                    "incorrect value for certificate_bytes[8], expected 86, is {}",
                    msg.certificate_bytes[8]
                );
                assert_eq!(
                    msg.certificate_bytes[9], 33,
                    "incorrect value for certificate_bytes[9], expected 33, is {}",
                    msg.certificate_bytes[9]
                );
                assert_eq!(
                    msg.certificate_bytes[10], 8,
                    "incorrect value for certificate_bytes[10], expected 8, is {}",
                    msg.certificate_bytes[10]
                );
                assert_eq!(
                    msg.certificate_bytes[11], 31,
                    "incorrect value for certificate_bytes[11], expected 31, is {}",
                    msg.certificate_bytes[11]
                );
                assert_eq!(
                    msg.certificate_bytes[12], 120,
                    "incorrect value for certificate_bytes[12], expected 120, is {}",
                    msg.certificate_bytes[12]
                );
                assert_eq!(
                    msg.certificate_bytes[13], 73,
                    "incorrect value for certificate_bytes[13], expected 73, is {}",
                    msg.certificate_bytes[13]
                );
                assert_eq!(
                    msg.certificate_bytes[14], 64,
                    "incorrect value for certificate_bytes[14], expected 64, is {}",
                    msg.certificate_bytes[14]
                );
                assert_eq!(
                    msg.certificate_bytes[15], 169,
                    "incorrect value for certificate_bytes[15], expected 169, is {}",
                    msg.certificate_bytes[15]
                );
                assert_eq!(
                    msg.certificate_bytes[16], 148,
                    "incorrect value for certificate_bytes[16], expected 148, is {}",
                    msg.certificate_bytes[16]
                );
                assert_eq!(
                    msg.certificate_bytes[17], 224,
                    "incorrect value for certificate_bytes[17], expected 224, is {}",
                    msg.certificate_bytes[17]
                );
                assert_eq!(
                    msg.certificate_bytes[18], 57,
                    "incorrect value for certificate_bytes[18], expected 57, is {}",
                    msg.certificate_bytes[18]
                );
                assert_eq!(
                    msg.certificate_bytes[19], 95,
                    "incorrect value for certificate_bytes[19], expected 95, is {}",
                    msg.certificate_bytes[19]
                );
                assert_eq!(
                    msg.certificate_bytes[20], 17,
                    "incorrect value for certificate_bytes[20], expected 17, is {}",
                    msg.certificate_bytes[20]
                );
                assert_eq!(
                    msg.certificate_bytes[21], 40,
                    "incorrect value for certificate_bytes[21], expected 40, is {}",
                    msg.certificate_bytes[21]
                );
                assert_eq!(
                    msg.certificate_bytes[22], 213,
                    "incorrect value for certificate_bytes[22], expected 213, is {}",
                    msg.certificate_bytes[22]
                );
                assert_eq!(
                    msg.certificate_bytes[23], 92,
                    "incorrect value for certificate_bytes[23], expected 92, is {}",
                    msg.certificate_bytes[23]
                );
                assert_eq!(
                    msg.certificate_bytes[24], 195,
                    "incorrect value for certificate_bytes[24], expected 195, is {}",
                    msg.certificate_bytes[24]
                );
                assert_eq!(
                    msg.certificate_bytes[25], 146,
                    "incorrect value for certificate_bytes[25], expected 146, is {}",
                    msg.certificate_bytes[25]
                );
                assert_eq!(
                    msg.certificate_bytes[26], 235,
                    "incorrect value for certificate_bytes[26], expected 235, is {}",
                    msg.certificate_bytes[26]
                );
                assert_eq!(
                    msg.certificate_bytes[27], 228,
                    "incorrect value for certificate_bytes[27], expected 228, is {}",
                    msg.certificate_bytes[27]
                );
                assert_eq!(
                    msg.certificate_bytes[28], 177,
                    "incorrect value for certificate_bytes[28], expected 177, is {}",
                    msg.certificate_bytes[28]
                );
                assert_eq!(
                    msg.certificate_bytes[29], 101,
                    "incorrect value for certificate_bytes[29], expected 101, is {}",
                    msg.certificate_bytes[29]
                );
                assert_eq!(
                    msg.certificate_bytes[30], 82,
                    "incorrect value for certificate_bytes[30], expected 82, is {}",
                    msg.certificate_bytes[30]
                );
                assert_eq!(
                    msg.certificate_bytes[31], 182,
                    "incorrect value for certificate_bytes[31], expected 182, is {}",
                    msg.certificate_bytes[31]
                );
                assert_eq!(
                    msg.certificate_bytes[32], 25,
                    "incorrect value for certificate_bytes[32], expected 25, is {}",
                    msg.certificate_bytes[32]
                );
                assert_eq!(
                    msg.certificate_bytes[33], 172,
                    "incorrect value for certificate_bytes[33], expected 172, is {}",
                    msg.certificate_bytes[33]
                );
                assert_eq!(
                    msg.certificate_bytes[34], 170,
                    "incorrect value for certificate_bytes[34], expected 170, is {}",
                    msg.certificate_bytes[34]
                );
                assert_eq!(
                    msg.certificate_bytes[35], 250,
                    "incorrect value for certificate_bytes[35], expected 250, is {}",
                    msg.certificate_bytes[35]
                );
                assert_eq!(
                    msg.certificate_bytes[36], 236,
                    "incorrect value for certificate_bytes[36], expected 236, is {}",
                    msg.certificate_bytes[36]
                );
                assert_eq!(
                    msg.certificate_bytes[37], 7,
                    "incorrect value for certificate_bytes[37], expected 7, is {}",
                    msg.certificate_bytes[37]
                );
                assert_eq!(
                    msg.certificate_bytes[38], 119,
                    "incorrect value for certificate_bytes[38], expected 119, is {}",
                    msg.certificate_bytes[38]
                );
                assert_eq!(
                    msg.certificate_bytes[39], 4,
                    "incorrect value for certificate_bytes[39], expected 4, is {}",
                    msg.certificate_bytes[39]
                );
                assert_eq!(
                    msg.certificate_bytes[40], 201,
                    "incorrect value for certificate_bytes[40], expected 201, is {}",
                    msg.certificate_bytes[40]
                );
                assert_eq!(
                    msg.certificate_bytes[41], 10,
                    "incorrect value for certificate_bytes[41], expected 10, is {}",
                    msg.certificate_bytes[41]
                );
                assert_eq!(
                    msg.certificate_bytes[42], 14,
                    "incorrect value for certificate_bytes[42], expected 14, is {}",
                    msg.certificate_bytes[42]
                );
                assert_eq!(
                    msg.certificate_bytes[43], 208,
                    "incorrect value for certificate_bytes[43], expected 208, is {}",
                    msg.certificate_bytes[43]
                );
                assert_eq!(
                    msg.certificate_bytes[44], 47,
                    "incorrect value for certificate_bytes[44], expected 47, is {}",
                    msg.certificate_bytes[44]
                );
                assert_eq!(
                    msg.certificate_bytes[45], 126,
                    "incorrect value for certificate_bytes[45], expected 126, is {}",
                    msg.certificate_bytes[45]
                );
                assert_eq!(
                    msg.certificate_bytes[46], 49,
                    "incorrect value for certificate_bytes[46], expected 49, is {}",
                    msg.certificate_bytes[46]
                );
                assert_eq!(
                    msg.certificate_bytes[47], 210,
                    "incorrect value for certificate_bytes[47], expected 210, is {}",
                    msg.certificate_bytes[47]
                );
                assert_eq!(
                    msg.certificate_bytes[48], 174,
                    "incorrect value for certificate_bytes[48], expected 174, is {}",
                    msg.certificate_bytes[48]
                );
                assert_eq!(
                    msg.certificate_bytes[49], 75,
                    "incorrect value for certificate_bytes[49], expected 75, is {}",
                    msg.certificate_bytes[49]
                );
                assert_eq!(
                    msg.certificate_bytes[50], 221,
                    "incorrect value for certificate_bytes[50], expected 221, is {}",
                    msg.certificate_bytes[50]
                );
                assert_eq!(
                    msg.certificate_bytes[51], 203,
                    "incorrect value for certificate_bytes[51], expected 203, is {}",
                    msg.certificate_bytes[51]
                );
                assert_eq!(
                    msg.certificate_bytes[52], 24,
                    "incorrect value for certificate_bytes[52], expected 24, is {}",
                    msg.certificate_bytes[52]
                );
                assert_eq!(
                    msg.certificate_bytes[53], 66,
                    "incorrect value for certificate_bytes[53], expected 66, is {}",
                    msg.certificate_bytes[53]
                );
                assert_eq!(
                    msg.certificate_bytes[54], 52,
                    "incorrect value for certificate_bytes[54], expected 52, is {}",
                    msg.certificate_bytes[54]
                );
                assert_eq!(
                    msg.certificate_bytes[55], 35,
                    "incorrect value for certificate_bytes[55], expected 35, is {}",
                    msg.certificate_bytes[55]
                );
                assert_eq!(
                    msg.certificate_bytes[56], 26,
                    "incorrect value for certificate_bytes[56], expected 26, is {}",
                    msg.certificate_bytes[56]
                );
                assert_eq!(
                    msg.certificate_bytes[57], 30,
                    "incorrect value for certificate_bytes[57], expected 30, is {}",
                    msg.certificate_bytes[57]
                );
                assert_eq!(
                    msg.certificate_bytes[58], 140,
                    "incorrect value for certificate_bytes[58], expected 140, is {}",
                    msg.certificate_bytes[58]
                );
                assert_eq!(
                    msg.certificate_bytes[59], 111,
                    "incorrect value for certificate_bytes[59], expected 111, is {}",
                    msg.certificate_bytes[59]
                );
                assert_eq!(
                    msg.certificate_bytes[60], 246,
                    "incorrect value for certificate_bytes[60], expected 246, is {}",
                    msg.certificate_bytes[60]
                );
                assert_eq!(
                    msg.certificate_bytes[61], 39,
                    "incorrect value for certificate_bytes[61], expected 39, is {}",
                    msg.certificate_bytes[61]
                );
                assert_eq!(
                    msg.certificate_bytes[62], 226,
                    "incorrect value for certificate_bytes[62], expected 226, is {}",
                    msg.certificate_bytes[62]
                );
                assert_eq!(
                    msg.certificate_bytes[63], 205,
                    "incorrect value for certificate_bytes[63], expected 205, is {}",
                    msg.certificate_bytes[63]
                );
                assert_eq!(
                    msg.certificate_bytes[64], 198,
                    "incorrect value for certificate_bytes[64], expected 198, is {}",
                    msg.certificate_bytes[64]
                );
                assert_eq!(
                    msg.certificate_bytes[65], 178,
                    "incorrect value for certificate_bytes[65], expected 178, is {}",
                    msg.certificate_bytes[65]
                );
                assert_eq!(
                    msg.certificate_bytes[66], 196,
                    "incorrect value for certificate_bytes[66], expected 196, is {}",
                    msg.certificate_bytes[66]
                );
                assert_eq!(
                    msg.certificate_bytes[67], 5,
                    "incorrect value for certificate_bytes[67], expected 5, is {}",
                    msg.certificate_bytes[67]
                );
                assert_eq!(
                    msg.certificate_bytes[68], 81,
                    "incorrect value for certificate_bytes[68], expected 81, is {}",
                    msg.certificate_bytes[68]
                );
                assert_eq!(
                    msg.certificate_bytes[69], 9,
                    "incorrect value for certificate_bytes[69], expected 9, is {}",
                    msg.certificate_bytes[69]
                );
                assert_eq!(
                    msg.certificate_bytes[70], 44,
                    "incorrect value for certificate_bytes[70], expected 44, is {}",
                    msg.certificate_bytes[70]
                );
                assert_eq!(
                    msg.certificate_bytes[71], 164,
                    "incorrect value for certificate_bytes[71], expected 164, is {}",
                    msg.certificate_bytes[71]
                );
                assert_eq!(
                    msg.certificate_bytes[72], 163,
                    "incorrect value for certificate_bytes[72], expected 163, is {}",
                    msg.certificate_bytes[72]
                );
                assert_eq!(
                    msg.certificate_bytes[73], 214,
                    "incorrect value for certificate_bytes[73], expected 214, is {}",
                    msg.certificate_bytes[73]
                );
                assert_eq!(
                    msg.certificate_bytes[74], 138,
                    "incorrect value for certificate_bytes[74], expected 138, is {}",
                    msg.certificate_bytes[74]
                );
                assert_eq!(
                    msg.certificate_bytes[75], 123,
                    "incorrect value for certificate_bytes[75], expected 123, is {}",
                    msg.certificate_bytes[75]
                );
                assert_eq!(
                    msg.certificate_bytes[76], 76,
                    "incorrect value for certificate_bytes[76], expected 76, is {}",
                    msg.certificate_bytes[76]
                );
                assert_eq!(
                    msg.certificate_bytes[77], 74,
                    "incorrect value for certificate_bytes[77], expected 74, is {}",
                    msg.certificate_bytes[77]
                );
                assert_eq!(
                    msg.certificate_bytes[78], 237,
                    "incorrect value for certificate_bytes[78], expected 237, is {}",
                    msg.certificate_bytes[78]
                );
                assert_eq!(
                    msg.certificate_bytes[79], 121,
                    "incorrect value for certificate_bytes[79], expected 121, is {}",
                    msg.certificate_bytes[79]
                );
                assert_eq!(
                    msg.certificate_bytes[80], 13,
                    "incorrect value for certificate_bytes[80], expected 13, is {}",
                    msg.certificate_bytes[80]
                );
                assert_eq!(
                    msg.certificate_bytes[81], 137,
                    "incorrect value for certificate_bytes[81], expected 137, is {}",
                    msg.certificate_bytes[81]
                );
                assert_eq!(
                    msg.certificate_bytes[82], 186,
                    "incorrect value for certificate_bytes[82], expected 186, is {}",
                    msg.certificate_bytes[82]
                );
                assert_eq!(
                    msg.certificate_bytes[83], 97,
                    "incorrect value for certificate_bytes[83], expected 97, is {}",
                    msg.certificate_bytes[83]
                );
                assert_eq!(
                    msg.certificate_bytes[84], 193,
                    "incorrect value for certificate_bytes[84], expected 193, is {}",
                    msg.certificate_bytes[84]
                );
                assert_eq!(
                    msg.certificate_bytes[85], 189,
                    "incorrect value for certificate_bytes[85], expected 189, is {}",
                    msg.certificate_bytes[85]
                );
                assert_eq!(
                    msg.certificate_bytes[86], 200,
                    "incorrect value for certificate_bytes[86], expected 200, is {}",
                    msg.certificate_bytes[86]
                );
                assert_eq!(
                    msg.certificate_bytes[87], 124,
                    "incorrect value for certificate_bytes[87], expected 124, is {}",
                    msg.certificate_bytes[87]
                );
                assert_eq!(
                    msg.certificate_bytes[88], 69,
                    "incorrect value for certificate_bytes[88], expected 69, is {}",
                    msg.certificate_bytes[88]
                );
                assert_eq!(
                    msg.certificate_bytes[89], 115,
                    "incorrect value for certificate_bytes[89], expected 115, is {}",
                    msg.certificate_bytes[89]
                );
                assert_eq!(
                    msg.certificate_bytes[90], 230,
                    "incorrect value for certificate_bytes[90], expected 230, is {}",
                    msg.certificate_bytes[90]
                );
                assert_eq!(
                    msg.certificate_bytes[91], 159,
                    "incorrect value for certificate_bytes[91], expected 159, is {}",
                    msg.certificate_bytes[91]
                );
                assert_eq!(
                    msg.certificate_bytes[92], 185,
                    "incorrect value for certificate_bytes[92], expected 185, is {}",
                    msg.certificate_bytes[92]
                );
                assert_eq!(
                    msg.certificate_bytes[93], 158,
                    "incorrect value for certificate_bytes[93], expected 158, is {}",
                    msg.certificate_bytes[93]
                );
                assert_eq!(
                    msg.certificate_bytes[94], 51,
                    "incorrect value for certificate_bytes[94], expected 51, is {}",
                    msg.certificate_bytes[94]
                );
                assert_eq!(
                    msg.certificate_bytes[95], 12,
                    "incorrect value for certificate_bytes[95], expected 12, is {}",
                    msg.certificate_bytes[95]
                );
                assert_eq!(
                    msg.certificate_bytes[96], 225,
                    "incorrect value for certificate_bytes[96], expected 225, is {}",
                    msg.certificate_bytes[96]
                );
                assert_eq!(
                    msg.certificate_bytes[97], 65,
                    "incorrect value for certificate_bytes[97], expected 65, is {}",
                    msg.certificate_bytes[97]
                );
                assert_eq!(
                    msg.certificate_bytes[98], 192,
                    "incorrect value for certificate_bytes[98], expected 192, is {}",
                    msg.certificate_bytes[98]
                );
                assert_eq!(
                    msg.certificate_bytes[99], 105,
                    "incorrect value for certificate_bytes[99], expected 105, is {}",
                    msg.certificate_bytes[99]
                );
                assert_eq!(
                    msg.certificate_bytes[100], 56,
                    "incorrect value for certificate_bytes[100], expected 56, is {}",
                    msg.certificate_bytes[100]
                );
                assert_eq!(
                    msg.certificate_bytes[101], 41,
                    "incorrect value for certificate_bytes[101], expected 41, is {}",
                    msg.certificate_bytes[101]
                );
                assert_eq!(
                    msg.certificate_bytes[102], 85,
                    "incorrect value for certificate_bytes[102], expected 85, is {}",
                    msg.certificate_bytes[102]
                );
                assert_eq!(
                    msg.certificate_bytes[103], 133,
                    "incorrect value for certificate_bytes[103], expected 133, is {}",
                    msg.certificate_bytes[103]
                );
                assert_eq!(
                    msg.certificate_bytes[104], 19,
                    "incorrect value for certificate_bytes[104], expected 19, is {}",
                    msg.certificate_bytes[104]
                );
                assert_eq!(
                    msg.certificate_bytes[105], 217,
                    "incorrect value for certificate_bytes[105], expected 217, is {}",
                    msg.certificate_bytes[105]
                );
                assert_eq!(
                    msg.certificate_bytes[106], 166,
                    "incorrect value for certificate_bytes[106], expected 166, is {}",
                    msg.certificate_bytes[106]
                );
                assert_eq!(
                    msg.certificate_bytes[107], 48,
                    "incorrect value for certificate_bytes[107], expected 48, is {}",
                    msg.certificate_bytes[107]
                );
                assert_eq!(
                    msg.certificate_bytes[108], 139,
                    "incorrect value for certificate_bytes[108], expected 139, is {}",
                    msg.certificate_bytes[108]
                );
                assert_eq!(
                    msg.certificate_bytes[109], 131,
                    "incorrect value for certificate_bytes[109], expected 131, is {}",
                    msg.certificate_bytes[109]
                );
                assert_eq!(
                    msg.certificate_bytes[110], 96,
                    "incorrect value for certificate_bytes[110], expected 96, is {}",
                    msg.certificate_bytes[110]
                );
                assert_eq!(
                    msg.certificate_bytes[111], 216,
                    "incorrect value for certificate_bytes[111], expected 216, is {}",
                    msg.certificate_bytes[111]
                );
                assert_eq!(
                    msg.certificate_bytes[112], 98,
                    "incorrect value for certificate_bytes[112], expected 98, is {}",
                    msg.certificate_bytes[112]
                );
                assert_eq!(
                    msg.certificate_bytes[113], 147,
                    "incorrect value for certificate_bytes[113], expected 147, is {}",
                    msg.certificate_bytes[113]
                );
                assert_eq!(
                    msg.certificate_bytes[114], 132,
                    "incorrect value for certificate_bytes[114], expected 132, is {}",
                    msg.certificate_bytes[114]
                );
                assert_eq!(
                    msg.certificate_bytes[115], 234,
                    "incorrect value for certificate_bytes[115], expected 234, is {}",
                    msg.certificate_bytes[115]
                );
                assert_eq!(
                    msg.certificate_bytes[116], 167,
                    "incorrect value for certificate_bytes[116], expected 167, is {}",
                    msg.certificate_bytes[116]
                );
                assert_eq!(
                    msg.certificate_bytes[117], 248,
                    "incorrect value for certificate_bytes[117], expected 248, is {}",
                    msg.certificate_bytes[117]
                );
                assert_eq!(
                    msg.certificate_bytes[118], 247,
                    "incorrect value for certificate_bytes[118], expected 247, is {}",
                    msg.certificate_bytes[118]
                );
                assert_eq!(
                    msg.certificate_bytes[119], 32,
                    "incorrect value for certificate_bytes[119], expected 32, is {}",
                    msg.certificate_bytes[119]
                );
                assert_eq!(
                    msg.certificate_bytes[120], 239,
                    "incorrect value for certificate_bytes[120], expected 239, is {}",
                    msg.certificate_bytes[120]
                );
                assert_eq!(
                    msg.certificate_bytes[121], 194,
                    "incorrect value for certificate_bytes[121], expected 194, is {}",
                    msg.certificate_bytes[121]
                );
                assert_eq!(
                    msg.certificate_bytes[122], 188,
                    "incorrect value for certificate_bytes[122], expected 188, is {}",
                    msg.certificate_bytes[122]
                );
                assert_eq!(
                    msg.certificate_bytes[123], 254,
                    "incorrect value for certificate_bytes[123], expected 254, is {}",
                    msg.certificate_bytes[123]
                );
                assert_eq!(
                    msg.certificate_bytes[124], 114,
                    "incorrect value for certificate_bytes[124], expected 114, is {}",
                    msg.certificate_bytes[124]
                );
                assert_eq!(
                    msg.certificate_bytes[125], 117,
                    "incorrect value for certificate_bytes[125], expected 117, is {}",
                    msg.certificate_bytes[125]
                );
                assert_eq!(
                    msg.certificate_bytes[126], 83,
                    "incorrect value for certificate_bytes[126], expected 83, is {}",
                    msg.certificate_bytes[126]
                );
                assert_eq!(
                    msg.certificate_bytes[127], 25,
                    "incorrect value for certificate_bytes[127], expected 25, is {}",
                    msg.certificate_bytes[127]
                );
                assert_eq!(
                    msg.certificate_bytes[128], 251,
                    "incorrect value for certificate_bytes[128], expected 251, is {}",
                    msg.certificate_bytes[128]
                );
                assert_eq!(
                    msg.certificate_bytes[129], 191,
                    "incorrect value for certificate_bytes[129], expected 191, is {}",
                    msg.certificate_bytes[129]
                );
                assert_eq!(
                    msg.certificate_bytes[130], 104,
                    "incorrect value for certificate_bytes[130], expected 104, is {}",
                    msg.certificate_bytes[130]
                );
                assert_eq!(
                    msg.certificate_bytes[131], 240,
                    "incorrect value for certificate_bytes[131], expected 240, is {}",
                    msg.certificate_bytes[131]
                );
                assert_eq!(
                    msg.certificate_bytes[132], 118,
                    "incorrect value for certificate_bytes[132], expected 118, is {}",
                    msg.certificate_bytes[132]
                );
                assert_eq!(
                    msg.certificate_bytes[133], 68,
                    "incorrect value for certificate_bytes[133], expected 68, is {}",
                    msg.certificate_bytes[133]
                );
                assert_eq!(
                    msg.certificate_bytes[134], 42,
                    "incorrect value for certificate_bytes[134], expected 42, is {}",
                    msg.certificate_bytes[134]
                );
                assert_eq!(
                    msg.certificate_bytes[135], 93,
                    "incorrect value for certificate_bytes[135], expected 93, is {}",
                    msg.certificate_bytes[135]
                );
                assert_eq!(
                    msg.certificate_bytes[136], 18,
                    "incorrect value for certificate_bytes[136], expected 18, is {}",
                    msg.certificate_bytes[136]
                );
                assert_eq!(
                    msg.certificate_bytes[137], 16,
                    "incorrect value for certificate_bytes[137], expected 16, is {}",
                    msg.certificate_bytes[137]
                );
                assert_eq!(
                    msg.certificate_bytes[138], 37,
                    "incorrect value for certificate_bytes[138], expected 37, is {}",
                    msg.certificate_bytes[138]
                );
                assert_eq!(
                    msg.certificate_bytes[139], 232,
                    "incorrect value for certificate_bytes[139], expected 232, is {}",
                    msg.certificate_bytes[139]
                );
                assert_eq!(
                    msg.certificate_bytes[140], 99,
                    "incorrect value for certificate_bytes[140], expected 99, is {}",
                    msg.certificate_bytes[140]
                );
                assert_eq!(
                    msg.certificate_bytes[141], 179,
                    "incorrect value for certificate_bytes[141], expected 179, is {}",
                    msg.certificate_bytes[141]
                );
                assert_eq!(
                    msg.certificate_bytes[142], 23,
                    "incorrect value for certificate_bytes[142], expected 23, is {}",
                    msg.certificate_bytes[142]
                );
                assert_eq!(
                    msg.certificate_bytes[143], 90,
                    "incorrect value for certificate_bytes[143], expected 90, is {}",
                    msg.certificate_bytes[143]
                );
                assert_eq!(
                    msg.certificate_bytes[144], 94,
                    "incorrect value for certificate_bytes[144], expected 94, is {}",
                    msg.certificate_bytes[144]
                );
                assert_eq!(
                    msg.certificate_bytes[145], 136,
                    "incorrect value for certificate_bytes[145], expected 136, is {}",
                    msg.certificate_bytes[145]
                );
                assert_eq!(
                    msg.certificate_bytes[146], 6,
                    "incorrect value for certificate_bytes[146], expected 6, is {}",
                    msg.certificate_bytes[146]
                );
                assert_eq!(
                    msg.certificate_bytes[147], 125,
                    "incorrect value for certificate_bytes[147], expected 125, is {}",
                    msg.certificate_bytes[147]
                );
                assert_eq!(
                    msg.certificate_bytes[148], 91,
                    "incorrect value for certificate_bytes[148], expected 91, is {}",
                    msg.certificate_bytes[148]
                );
                assert_eq!(
                    msg.certificate_bytes[149], 255,
                    "incorrect value for certificate_bytes[149], expected 255, is {}",
                    msg.certificate_bytes[149]
                );
                assert_eq!(
                    msg.certificate_bytes[150], 15,
                    "incorrect value for certificate_bytes[150], expected 15, is {}",
                    msg.certificate_bytes[150]
                );
                assert_eq!(
                    msg.certificate_bytes[151], 71,
                    "incorrect value for certificate_bytes[151], expected 71, is {}",
                    msg.certificate_bytes[151]
                );
                assert_eq!(
                    msg.certificate_bytes[152], 43,
                    "incorrect value for certificate_bytes[152], expected 43, is {}",
                    msg.certificate_bytes[152]
                );
                assert_eq!(
                    msg.certificate_bytes[153], 46,
                    "incorrect value for certificate_bytes[153], expected 46, is {}",
                    msg.certificate_bytes[153]
                );
                assert_eq!(
                    msg.certificate_bytes[154], 25,
                    "incorrect value for certificate_bytes[154], expected 25, is {}",
                    msg.certificate_bytes[154]
                );
                assert_eq!(
                    msg.certificate_bytes[155], 252,
                    "incorrect value for certificate_bytes[155], expected 252, is {}",
                    msg.certificate_bytes[155]
                );
                assert_eq!(
                    msg.certificate_bytes[156], 229,
                    "incorrect value for certificate_bytes[156], expected 229, is {}",
                    msg.certificate_bytes[156]
                );
                assert_eq!(
                    msg.certificate_bytes[157], 80,
                    "incorrect value for certificate_bytes[157], expected 80, is {}",
                    msg.certificate_bytes[157]
                );
                assert_eq!(
                    msg.certificate_bytes[158], 143,
                    "incorrect value for certificate_bytes[158], expected 143, is {}",
                    msg.certificate_bytes[158]
                );
                assert_eq!(
                    msg.certificate_bytes[159], 58,
                    "incorrect value for certificate_bytes[159], expected 58, is {}",
                    msg.certificate_bytes[159]
                );
                assert_eq!(
                    msg.certificate_bytes[160], 241,
                    "incorrect value for certificate_bytes[160], expected 241, is {}",
                    msg.certificate_bytes[160]
                );
                assert_eq!(
                    msg.certificate_bytes[161], 11,
                    "incorrect value for certificate_bytes[161], expected 11, is {}",
                    msg.certificate_bytes[161]
                );
                assert_eq!(
                    msg.certificate_bytes[162], 62,
                    "incorrect value for certificate_bytes[162], expected 62, is {}",
                    msg.certificate_bytes[162]
                );
                assert_eq!(
                    msg.certificate_bytes[163], 181,
                    "incorrect value for certificate_bytes[163], expected 181, is {}",
                    msg.certificate_bytes[163]
                );
                assert_eq!(
                    msg.certificate_bytes[164], 155,
                    "incorrect value for certificate_bytes[164], expected 155, is {}",
                    msg.certificate_bytes[164]
                );
                assert_eq!(
                    msg.certificate_bytes[165], 53,
                    "incorrect value for certificate_bytes[165], expected 53, is {}",
                    msg.certificate_bytes[165]
                );
                assert_eq!(
                    msg.certificate_bytes[166], 153,
                    "incorrect value for certificate_bytes[166], expected 153, is {}",
                    msg.certificate_bytes[166]
                );
                assert_eq!(
                    msg.certificate_bytes[167], 149,
                    "incorrect value for certificate_bytes[167], expected 149, is {}",
                    msg.certificate_bytes[167]
                );
                assert_eq!(
                    msg.certificate_bytes[168], 152,
                    "incorrect value for certificate_bytes[168], expected 152, is {}",
                    msg.certificate_bytes[168]
                );
                assert_eq!(
                    msg.certificate_bytes[169], 227,
                    "incorrect value for certificate_bytes[169], expected 227, is {}",
                    msg.certificate_bytes[169]
                );
                assert_eq!(
                    msg.certificate_bytes[170], 150,
                    "incorrect value for certificate_bytes[170], expected 150, is {}",
                    msg.certificate_bytes[170]
                );
                assert_eq!(
                    msg.certificate_bytes[171], 87,
                    "incorrect value for certificate_bytes[171], expected 87, is {}",
                    msg.certificate_bytes[171]
                );
                assert_eq!(
                    msg.certificate_bytes[172], 112,
                    "incorrect value for certificate_bytes[172], expected 112, is {}",
                    msg.certificate_bytes[172]
                );
                assert_eq!(
                    msg.certificate_bytes[173], 165,
                    "incorrect value for certificate_bytes[173], expected 165, is {}",
                    msg.certificate_bytes[173]
                );
                assert_eq!(
                    msg.certificate_bytes[174], 2,
                    "incorrect value for certificate_bytes[174], expected 2, is {}",
                    msg.certificate_bytes[174]
                );
                assert_eq!(
                    msg.certificate_bytes[175], 128,
                    "incorrect value for certificate_bytes[175], expected 128, is {}",
                    msg.certificate_bytes[175]
                );
                assert_eq!(
                    msg.certificate_bytes[176], 231,
                    "incorrect value for certificate_bytes[176], expected 231, is {}",
                    msg.certificate_bytes[176]
                );
                assert_eq!(
                    msg.certificate_bytes[177], 25,
                    "incorrect value for certificate_bytes[177], expected 25, is {}",
                    msg.certificate_bytes[177]
                );
                assert_eq!(
                    msg.certificate_bytes[178], 157,
                    "incorrect value for certificate_bytes[178], expected 157, is {}",
                    msg.certificate_bytes[178]
                );
                assert_eq!(
                    msg.certificate_bytes[179], 244,
                    "incorrect value for certificate_bytes[179], expected 244, is {}",
                    msg.certificate_bytes[179]
                );
                assert_eq!(
                    msg.certificate_bytes[180], 204,
                    "incorrect value for certificate_bytes[180], expected 204, is {}",
                    msg.certificate_bytes[180]
                );
                assert_eq!(
                    msg.certificate_bytes[181], 108,
                    "incorrect value for certificate_bytes[181], expected 108, is {}",
                    msg.certificate_bytes[181]
                );
                assert_eq!(
                    msg.certificate_bytes[182], 253,
                    "incorrect value for certificate_bytes[182], expected 253, is {}",
                    msg.certificate_bytes[182]
                );
                assert_eq!(
                    msg.certificate_bytes[183], 127,
                    "incorrect value for certificate_bytes[183], expected 127, is {}",
                    msg.certificate_bytes[183]
                );
                assert_eq!(
                    msg.certificate_bytes[184], 122,
                    "incorrect value for certificate_bytes[184], expected 122, is {}",
                    msg.certificate_bytes[184]
                );
                assert_eq!(
                    msg.certificate_bytes[185], 145,
                    "incorrect value for certificate_bytes[185], expected 145, is {}",
                    msg.certificate_bytes[185]
                );
                assert_eq!(
                    msg.certificate_bytes[186], 113,
                    "incorrect value for certificate_bytes[186], expected 113, is {}",
                    msg.certificate_bytes[186]
                );
                assert_eq!(
                    msg.certificate_bytes[187], 162,
                    "incorrect value for certificate_bytes[187], expected 162, is {}",
                    msg.certificate_bytes[187]
                );
                assert_eq!(
                    msg.certificate_bytes[188], 197,
                    "incorrect value for certificate_bytes[188], expected 197, is {}",
                    msg.certificate_bytes[188]
                );
                assert_eq!(
                    msg.certificate_bytes[189], 171,
                    "incorrect value for certificate_bytes[189], expected 171, is {}",
                    msg.certificate_bytes[189]
                );
                assert_eq!(
                    msg.certificate_bytes[190], 199,
                    "incorrect value for certificate_bytes[190], expected 199, is {}",
                    msg.certificate_bytes[190]
                );
                assert_eq!(
                    msg.certificate_bytes[191], 54,
                    "incorrect value for certificate_bytes[191], expected 54, is {}",
                    msg.certificate_bytes[191]
                );
                assert_eq!(
                    msg.certificate_bytes[192], 184,
                    "incorrect value for certificate_bytes[192], expected 184, is {}",
                    msg.certificate_bytes[192]
                );
                assert_eq!(
                    msg.certificate_bytes[193], 222,
                    "incorrect value for certificate_bytes[193], expected 222, is {}",
                    msg.certificate_bytes[193]
                );
                assert_eq!(
                    msg.certificate_bytes[194], 206,
                    "incorrect value for certificate_bytes[194], expected 206, is {}",
                    msg.certificate_bytes[194]
                );
                assert_eq!(
                    msg.certificate_bytes[195], 67,
                    "incorrect value for certificate_bytes[195], expected 67, is {}",
                    msg.certificate_bytes[195]
                );
                assert_eq!(
                    msg.certificate_bytes[196], 144,
                    "incorrect value for certificate_bytes[196], expected 144, is {}",
                    msg.certificate_bytes[196]
                );
                assert_eq!(
                    msg.certificate_bytes[197], 78,
                    "incorrect value for certificate_bytes[197], expected 78, is {}",
                    msg.certificate_bytes[197]
                );
                assert_eq!(
                    msg.certificate_bytes[198], 187,
                    "incorrect value for certificate_bytes[198], expected 187, is {}",
                    msg.certificate_bytes[198]
                );
                assert_eq!(
                    msg.certificate_bytes[199], 207,
                    "incorrect value for certificate_bytes[199], expected 207, is {}",
                    msg.certificate_bytes[199]
                );
                assert_eq!(
                    msg.certificate_bytes[200], 60,
                    "incorrect value for certificate_bytes[200], expected 60, is {}",
                    msg.certificate_bytes[200]
                );
                assert_eq!(
                    msg.certificate_bytes[201], 211,
                    "incorrect value for certificate_bytes[201], expected 211, is {}",
                    msg.certificate_bytes[201]
                );
                assert_eq!(
                    msg.certificate_bytes[202], 141,
                    "incorrect value for certificate_bytes[202], expected 141, is {}",
                    msg.certificate_bytes[202]
                );
                assert_eq!(
                    msg.certificate_bytes[203], 135,
                    "incorrect value for certificate_bytes[203], expected 135, is {}",
                    msg.certificate_bytes[203]
                );
                assert_eq!(
                    msg.certificate_bytes[204], 106,
                    "incorrect value for certificate_bytes[204], expected 106, is {}",
                    msg.certificate_bytes[204]
                );
                assert_eq!(
                    msg.certificate_bytes[205], 220,
                    "incorrect value for certificate_bytes[205], expected 220, is {}",
                    msg.certificate_bytes[205]
                );
                assert_eq!(
                    msg.certificate_bytes[206], 79,
                    "incorrect value for certificate_bytes[206], expected 79, is {}",
                    msg.certificate_bytes[206]
                );
                assert_eq!(
                    msg.certificate_bytes[207], 183,
                    "incorrect value for certificate_bytes[207], expected 183, is {}",
                    msg.certificate_bytes[207]
                );
                assert_eq!(
                    msg.certificate_bytes[208], 245,
                    "incorrect value for certificate_bytes[208], expected 245, is {}",
                    msg.certificate_bytes[208]
                );
                assert_eq!(
                    msg.certificate_bytes[209], 21,
                    "incorrect value for certificate_bytes[209], expected 21, is {}",
                    msg.certificate_bytes[209]
                );
                assert_eq!(
                    msg.certificate_bytes[210], 161,
                    "incorrect value for certificate_bytes[210], expected 161, is {}",
                    msg.certificate_bytes[210]
                );
                assert_eq!(
                    msg.certificate_bytes[211], 168,
                    "incorrect value for certificate_bytes[211], expected 168, is {}",
                    msg.certificate_bytes[211]
                );
                assert_eq!(
                    msg.certificate_bytes[212], 34,
                    "incorrect value for certificate_bytes[212], expected 34, is {}",
                    msg.certificate_bytes[212]
                );
                assert_eq!(
                    msg.certificate_bytes[213], 129,
                    "incorrect value for certificate_bytes[213], expected 129, is {}",
                    msg.certificate_bytes[213]
                );
                assert_eq!(
                    msg.certificate_bytes[214], 50,
                    "incorrect value for certificate_bytes[214], expected 50, is {}",
                    msg.certificate_bytes[214]
                );
                assert_eq!(
                    msg.certificate_bytes[215], 176,
                    "incorrect value for certificate_bytes[215], expected 176, is {}",
                    msg.certificate_bytes[215]
                );
                assert_eq!(
                    msg.certificate_bytes[216], 1,
                    "incorrect value for certificate_bytes[216], expected 1, is {}",
                    msg.certificate_bytes[216]
                );
                assert_eq!(
                    msg.certificate_bytes[217], 218,
                    "incorrect value for certificate_bytes[217], expected 218, is {}",
                    msg.certificate_bytes[217]
                );
                assert_eq!(
                    msg.certificate_bytes[218], 20,
                    "incorrect value for certificate_bytes[218], expected 20, is {}",
                    msg.certificate_bytes[218]
                );
                assert_eq!(
                    msg.certificate_bytes[219], 130,
                    "incorrect value for certificate_bytes[219], expected 130, is {}",
                    msg.certificate_bytes[219]
                );
                assert_eq!(
                    msg.certificate_bytes[220], 59,
                    "incorrect value for certificate_bytes[220], expected 59, is {}",
                    msg.certificate_bytes[220]
                );
                assert_eq!(
                    msg.certificate_bytes[221], 249,
                    "incorrect value for certificate_bytes[221], expected 249, is {}",
                    msg.certificate_bytes[221]
                );
                assert_eq!(
                    msg.certificate_bytes[222], 109,
                    "incorrect value for certificate_bytes[222], expected 109, is {}",
                    msg.certificate_bytes[222]
                );
                assert_eq!(
                    msg.certificate_bytes[223], 219,
                    "incorrect value for certificate_bytes[223], expected 219, is {}",
                    msg.certificate_bytes[223]
                );
                assert_eq!(
                    msg.certificate_bytes[224], 0,
                    "incorrect value for certificate_bytes[224], expected 0, is {}",
                    msg.certificate_bytes[224]
                );
                assert_eq!(
                    msg.certificate_bytes[225], 100,
                    "incorrect value for certificate_bytes[225], expected 100, is {}",
                    msg.certificate_bytes[225]
                );
                assert_eq!(
                    msg.certificate_bytes[226], 103,
                    "incorrect value for certificate_bytes[226], expected 103, is {}",
                    msg.certificate_bytes[226]
                );
                assert_eq!(
                    msg.certificate_bytes[227], 55,
                    "incorrect value for certificate_bytes[227], expected 55, is {}",
                    msg.certificate_bytes[227]
                );
                assert_eq!(
                    msg.certificate_bytes[228], 29,
                    "incorrect value for certificate_bytes[228], expected 29, is {}",
                    msg.certificate_bytes[228]
                );
                assert_eq!(
                    msg.certificate_bytes[229], 242,
                    "incorrect value for certificate_bytes[229], expected 242, is {}",
                    msg.certificate_bytes[229]
                );
                assert_eq!(
                    msg.certificate_bytes[230], 110,
                    "incorrect value for certificate_bytes[230], expected 110, is {}",
                    msg.certificate_bytes[230]
                );
                assert_eq!(
                    msg.certificate_bytes[231], 154,
                    "incorrect value for certificate_bytes[231], expected 154, is {}",
                    msg.certificate_bytes[231]
                );
                assert_eq!(
                    msg.certificate_bytes[232], 190,
                    "incorrect value for certificate_bytes[232], expected 190, is {}",
                    msg.certificate_bytes[232]
                );
                assert_eq!(
                    msg.certificate_bytes[233], 233,
                    "incorrect value for certificate_bytes[233], expected 233, is {}",
                    msg.certificate_bytes[233]
                );
                assert_eq!(
                    msg.certificate_bytes[234], 142,
                    "incorrect value for certificate_bytes[234], expected 142, is {}",
                    msg.certificate_bytes[234]
                );
                assert_eq!(
                    msg.certificate_bytes[235], 45,
                    "incorrect value for certificate_bytes[235], expected 45, is {}",
                    msg.certificate_bytes[235]
                );
                assert_eq!(
                    msg.certificate_bytes[236], 61,
                    "incorrect value for certificate_bytes[236], expected 61, is {}",
                    msg.certificate_bytes[236]
                );
                assert_eq!(
                    msg.certificate_bytes[237], 215,
                    "incorrect value for certificate_bytes[237], expected 215, is {}",
                    msg.certificate_bytes[237]
                );
                assert_eq!(
                    msg.certificate_bytes[238], 202,
                    "incorrect value for certificate_bytes[238], expected 202, is {}",
                    msg.certificate_bytes[238]
                );
                assert_eq!(
                    msg.certificate_bytes[239], 238,
                    "incorrect value for certificate_bytes[239], expected 238, is {}",
                    msg.certificate_bytes[239]
                );
                assert_eq!(
                    msg.certificate_bytes[240], 88,
                    "incorrect value for certificate_bytes[240], expected 88, is {}",
                    msg.certificate_bytes[240]
                );
                assert_eq!(
                    msg.certificate_bytes[241], 209,
                    "incorrect value for certificate_bytes[241], expected 209, is {}",
                    msg.certificate_bytes[241]
                );
                assert_eq!(
                    msg.certificate_bytes[242], 70,
                    "incorrect value for certificate_bytes[242], expected 70, is {}",
                    msg.certificate_bytes[242]
                );
                assert_eq!(
                    msg.certificate_bytes[243], 63,
                    "incorrect value for certificate_bytes[243], expected 63, is {}",
                    msg.certificate_bytes[243]
                );
                assert_eq!(
                    msg.certificate_bytes[244], 151,
                    "incorrect value for certificate_bytes[244], expected 151, is {}",
                    msg.certificate_bytes[244]
                );
                assert_eq!(
                    msg.certificate_bytes[245], 27,
                    "incorrect value for certificate_bytes[245], expected 27, is {}",
                    msg.certificate_bytes[245]
                );
                assert_eq!(
                    msg.certificate_bytes[246], 102,
                    "incorrect value for certificate_bytes[246], expected 102, is {}",
                    msg.certificate_bytes[246]
                );
                assert_eq!(
                    msg.certificate_id[0], 10,
                    "incorrect value for certificate_id[0], expected 10, is {}",
                    msg.certificate_id[0]
                );
                assert_eq!(
                    msg.certificate_id[1], 11,
                    "incorrect value for certificate_id[1], expected 11, is {}",
                    msg.certificate_id[1]
                );
                assert_eq!(
                    msg.certificate_id[2], 12,
                    "incorrect value for certificate_id[2], expected 12, is {}",
                    msg.certificate_id[2]
                );
                assert_eq!(
                    msg.certificate_id[3], 13,
                    "incorrect value for certificate_id[3], expected 13, is {}",
                    msg.certificate_id[3]
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_msg, 48,
                    "incorrect value for n_msg, expected 48, is {}",
                    msg.n_msg
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEcdsaCertificate"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_signing_msg_ecdsa_certificate`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_signing_msg_ecdsa_certificate() {
    {
        let mut payload = Cursor::new(vec![
            85, 4, 12, 66, 0, 253, 48, 10, 11, 12, 13, 2, 180, 160, 116, 77, 243, 28, 173, 36, 86,
            33, 8, 31, 120, 73, 64, 169, 148, 224, 57, 95, 17, 40, 213, 92, 195, 146, 235, 228,
            177, 101, 82, 182, 25, 172, 170, 250, 236, 7, 119, 4, 201, 10, 14, 208, 47, 126, 49,
            210, 174, 75, 221, 203, 24, 66, 52, 35, 26, 30, 140, 111, 246, 39, 226, 205, 198, 178,
            196, 5, 81, 9, 44, 164, 163, 214, 138, 123, 76, 74, 237, 121, 13, 137, 186, 97, 193,
            189, 200, 124, 69, 115, 230, 159, 185, 158, 51, 12, 225, 65, 192, 105, 56, 41, 85, 133,
            19, 217, 166, 48, 139, 131, 96, 216, 98, 147, 132, 234, 167, 248, 247, 32, 239, 194,
            188, 254, 114, 117, 83, 25, 251, 191, 104, 240, 118, 68, 42, 93, 18, 16, 37, 232, 99,
            179, 23, 90, 94, 136, 6, 125, 91, 255, 15, 71, 43, 46, 25, 252, 229, 80, 143, 58, 241,
            11, 62, 181, 155, 53, 153, 149, 152, 227, 150, 87, 112, 165, 2, 128, 231, 25, 157, 244,
            204, 108, 253, 127, 122, 145, 113, 162, 197, 171, 199, 54, 184, 222, 206, 67, 144, 78,
            187, 207, 60, 211, 141, 135, 106, 220, 79, 183, 245, 21, 161, 168, 34, 129, 50, 176, 1,
            218, 20, 130, 59, 249, 109, 219, 0, 100, 103, 55, 29, 242, 110, 154, 190, 233, 142, 45,
            61, 215, 202, 238, 88, 209, 70, 63, 151, 27, 102, 219, 30,
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
        let sbp_msg = sbp::messages::Sbp::MsgEcdsaCertificate(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgEcdsaCertificate(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xC04,
                    "Incorrect message type, expected 0xC04, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {sender_id}"
                );
                assert_eq!(
                    msg.certificate_bytes[0], 180,
                    "incorrect value for certificate_bytes[0], expected 180, is {}",
                    msg.certificate_bytes[0]
                );
                assert_eq!(
                    msg.certificate_bytes[1], 160,
                    "incorrect value for certificate_bytes[1], expected 160, is {}",
                    msg.certificate_bytes[1]
                );
                assert_eq!(
                    msg.certificate_bytes[2], 116,
                    "incorrect value for certificate_bytes[2], expected 116, is {}",
                    msg.certificate_bytes[2]
                );
                assert_eq!(
                    msg.certificate_bytes[3], 77,
                    "incorrect value for certificate_bytes[3], expected 77, is {}",
                    msg.certificate_bytes[3]
                );
                assert_eq!(
                    msg.certificate_bytes[4], 243,
                    "incorrect value for certificate_bytes[4], expected 243, is {}",
                    msg.certificate_bytes[4]
                );
                assert_eq!(
                    msg.certificate_bytes[5], 28,
                    "incorrect value for certificate_bytes[5], expected 28, is {}",
                    msg.certificate_bytes[5]
                );
                assert_eq!(
                    msg.certificate_bytes[6], 173,
                    "incorrect value for certificate_bytes[6], expected 173, is {}",
                    msg.certificate_bytes[6]
                );
                assert_eq!(
                    msg.certificate_bytes[7], 36,
                    "incorrect value for certificate_bytes[7], expected 36, is {}",
                    msg.certificate_bytes[7]
                );
                assert_eq!(
                    msg.certificate_bytes[8], 86,
                    "incorrect value for certificate_bytes[8], expected 86, is {}",
                    msg.certificate_bytes[8]
                );
                assert_eq!(
                    msg.certificate_bytes[9], 33,
                    "incorrect value for certificate_bytes[9], expected 33, is {}",
                    msg.certificate_bytes[9]
                );
                assert_eq!(
                    msg.certificate_bytes[10], 8,
                    "incorrect value for certificate_bytes[10], expected 8, is {}",
                    msg.certificate_bytes[10]
                );
                assert_eq!(
                    msg.certificate_bytes[11], 31,
                    "incorrect value for certificate_bytes[11], expected 31, is {}",
                    msg.certificate_bytes[11]
                );
                assert_eq!(
                    msg.certificate_bytes[12], 120,
                    "incorrect value for certificate_bytes[12], expected 120, is {}",
                    msg.certificate_bytes[12]
                );
                assert_eq!(
                    msg.certificate_bytes[13], 73,
                    "incorrect value for certificate_bytes[13], expected 73, is {}",
                    msg.certificate_bytes[13]
                );
                assert_eq!(
                    msg.certificate_bytes[14], 64,
                    "incorrect value for certificate_bytes[14], expected 64, is {}",
                    msg.certificate_bytes[14]
                );
                assert_eq!(
                    msg.certificate_bytes[15], 169,
                    "incorrect value for certificate_bytes[15], expected 169, is {}",
                    msg.certificate_bytes[15]
                );
                assert_eq!(
                    msg.certificate_bytes[16], 148,
                    "incorrect value for certificate_bytes[16], expected 148, is {}",
                    msg.certificate_bytes[16]
                );
                assert_eq!(
                    msg.certificate_bytes[17], 224,
                    "incorrect value for certificate_bytes[17], expected 224, is {}",
                    msg.certificate_bytes[17]
                );
                assert_eq!(
                    msg.certificate_bytes[18], 57,
                    "incorrect value for certificate_bytes[18], expected 57, is {}",
                    msg.certificate_bytes[18]
                );
                assert_eq!(
                    msg.certificate_bytes[19], 95,
                    "incorrect value for certificate_bytes[19], expected 95, is {}",
                    msg.certificate_bytes[19]
                );
                assert_eq!(
                    msg.certificate_bytes[20], 17,
                    "incorrect value for certificate_bytes[20], expected 17, is {}",
                    msg.certificate_bytes[20]
                );
                assert_eq!(
                    msg.certificate_bytes[21], 40,
                    "incorrect value for certificate_bytes[21], expected 40, is {}",
                    msg.certificate_bytes[21]
                );
                assert_eq!(
                    msg.certificate_bytes[22], 213,
                    "incorrect value for certificate_bytes[22], expected 213, is {}",
                    msg.certificate_bytes[22]
                );
                assert_eq!(
                    msg.certificate_bytes[23], 92,
                    "incorrect value for certificate_bytes[23], expected 92, is {}",
                    msg.certificate_bytes[23]
                );
                assert_eq!(
                    msg.certificate_bytes[24], 195,
                    "incorrect value for certificate_bytes[24], expected 195, is {}",
                    msg.certificate_bytes[24]
                );
                assert_eq!(
                    msg.certificate_bytes[25], 146,
                    "incorrect value for certificate_bytes[25], expected 146, is {}",
                    msg.certificate_bytes[25]
                );
                assert_eq!(
                    msg.certificate_bytes[26], 235,
                    "incorrect value for certificate_bytes[26], expected 235, is {}",
                    msg.certificate_bytes[26]
                );
                assert_eq!(
                    msg.certificate_bytes[27], 228,
                    "incorrect value for certificate_bytes[27], expected 228, is {}",
                    msg.certificate_bytes[27]
                );
                assert_eq!(
                    msg.certificate_bytes[28], 177,
                    "incorrect value for certificate_bytes[28], expected 177, is {}",
                    msg.certificate_bytes[28]
                );
                assert_eq!(
                    msg.certificate_bytes[29], 101,
                    "incorrect value for certificate_bytes[29], expected 101, is {}",
                    msg.certificate_bytes[29]
                );
                assert_eq!(
                    msg.certificate_bytes[30], 82,
                    "incorrect value for certificate_bytes[30], expected 82, is {}",
                    msg.certificate_bytes[30]
                );
                assert_eq!(
                    msg.certificate_bytes[31], 182,
                    "incorrect value for certificate_bytes[31], expected 182, is {}",
                    msg.certificate_bytes[31]
                );
                assert_eq!(
                    msg.certificate_bytes[32], 25,
                    "incorrect value for certificate_bytes[32], expected 25, is {}",
                    msg.certificate_bytes[32]
                );
                assert_eq!(
                    msg.certificate_bytes[33], 172,
                    "incorrect value for certificate_bytes[33], expected 172, is {}",
                    msg.certificate_bytes[33]
                );
                assert_eq!(
                    msg.certificate_bytes[34], 170,
                    "incorrect value for certificate_bytes[34], expected 170, is {}",
                    msg.certificate_bytes[34]
                );
                assert_eq!(
                    msg.certificate_bytes[35], 250,
                    "incorrect value for certificate_bytes[35], expected 250, is {}",
                    msg.certificate_bytes[35]
                );
                assert_eq!(
                    msg.certificate_bytes[36], 236,
                    "incorrect value for certificate_bytes[36], expected 236, is {}",
                    msg.certificate_bytes[36]
                );
                assert_eq!(
                    msg.certificate_bytes[37], 7,
                    "incorrect value for certificate_bytes[37], expected 7, is {}",
                    msg.certificate_bytes[37]
                );
                assert_eq!(
                    msg.certificate_bytes[38], 119,
                    "incorrect value for certificate_bytes[38], expected 119, is {}",
                    msg.certificate_bytes[38]
                );
                assert_eq!(
                    msg.certificate_bytes[39], 4,
                    "incorrect value for certificate_bytes[39], expected 4, is {}",
                    msg.certificate_bytes[39]
                );
                assert_eq!(
                    msg.certificate_bytes[40], 201,
                    "incorrect value for certificate_bytes[40], expected 201, is {}",
                    msg.certificate_bytes[40]
                );
                assert_eq!(
                    msg.certificate_bytes[41], 10,
                    "incorrect value for certificate_bytes[41], expected 10, is {}",
                    msg.certificate_bytes[41]
                );
                assert_eq!(
                    msg.certificate_bytes[42], 14,
                    "incorrect value for certificate_bytes[42], expected 14, is {}",
                    msg.certificate_bytes[42]
                );
                assert_eq!(
                    msg.certificate_bytes[43], 208,
                    "incorrect value for certificate_bytes[43], expected 208, is {}",
                    msg.certificate_bytes[43]
                );
                assert_eq!(
                    msg.certificate_bytes[44], 47,
                    "incorrect value for certificate_bytes[44], expected 47, is {}",
                    msg.certificate_bytes[44]
                );
                assert_eq!(
                    msg.certificate_bytes[45], 126,
                    "incorrect value for certificate_bytes[45], expected 126, is {}",
                    msg.certificate_bytes[45]
                );
                assert_eq!(
                    msg.certificate_bytes[46], 49,
                    "incorrect value for certificate_bytes[46], expected 49, is {}",
                    msg.certificate_bytes[46]
                );
                assert_eq!(
                    msg.certificate_bytes[47], 210,
                    "incorrect value for certificate_bytes[47], expected 210, is {}",
                    msg.certificate_bytes[47]
                );
                assert_eq!(
                    msg.certificate_bytes[48], 174,
                    "incorrect value for certificate_bytes[48], expected 174, is {}",
                    msg.certificate_bytes[48]
                );
                assert_eq!(
                    msg.certificate_bytes[49], 75,
                    "incorrect value for certificate_bytes[49], expected 75, is {}",
                    msg.certificate_bytes[49]
                );
                assert_eq!(
                    msg.certificate_bytes[50], 221,
                    "incorrect value for certificate_bytes[50], expected 221, is {}",
                    msg.certificate_bytes[50]
                );
                assert_eq!(
                    msg.certificate_bytes[51], 203,
                    "incorrect value for certificate_bytes[51], expected 203, is {}",
                    msg.certificate_bytes[51]
                );
                assert_eq!(
                    msg.certificate_bytes[52], 24,
                    "incorrect value for certificate_bytes[52], expected 24, is {}",
                    msg.certificate_bytes[52]
                );
                assert_eq!(
                    msg.certificate_bytes[53], 66,
                    "incorrect value for certificate_bytes[53], expected 66, is {}",
                    msg.certificate_bytes[53]
                );
                assert_eq!(
                    msg.certificate_bytes[54], 52,
                    "incorrect value for certificate_bytes[54], expected 52, is {}",
                    msg.certificate_bytes[54]
                );
                assert_eq!(
                    msg.certificate_bytes[55], 35,
                    "incorrect value for certificate_bytes[55], expected 35, is {}",
                    msg.certificate_bytes[55]
                );
                assert_eq!(
                    msg.certificate_bytes[56], 26,
                    "incorrect value for certificate_bytes[56], expected 26, is {}",
                    msg.certificate_bytes[56]
                );
                assert_eq!(
                    msg.certificate_bytes[57], 30,
                    "incorrect value for certificate_bytes[57], expected 30, is {}",
                    msg.certificate_bytes[57]
                );
                assert_eq!(
                    msg.certificate_bytes[58], 140,
                    "incorrect value for certificate_bytes[58], expected 140, is {}",
                    msg.certificate_bytes[58]
                );
                assert_eq!(
                    msg.certificate_bytes[59], 111,
                    "incorrect value for certificate_bytes[59], expected 111, is {}",
                    msg.certificate_bytes[59]
                );
                assert_eq!(
                    msg.certificate_bytes[60], 246,
                    "incorrect value for certificate_bytes[60], expected 246, is {}",
                    msg.certificate_bytes[60]
                );
                assert_eq!(
                    msg.certificate_bytes[61], 39,
                    "incorrect value for certificate_bytes[61], expected 39, is {}",
                    msg.certificate_bytes[61]
                );
                assert_eq!(
                    msg.certificate_bytes[62], 226,
                    "incorrect value for certificate_bytes[62], expected 226, is {}",
                    msg.certificate_bytes[62]
                );
                assert_eq!(
                    msg.certificate_bytes[63], 205,
                    "incorrect value for certificate_bytes[63], expected 205, is {}",
                    msg.certificate_bytes[63]
                );
                assert_eq!(
                    msg.certificate_bytes[64], 198,
                    "incorrect value for certificate_bytes[64], expected 198, is {}",
                    msg.certificate_bytes[64]
                );
                assert_eq!(
                    msg.certificate_bytes[65], 178,
                    "incorrect value for certificate_bytes[65], expected 178, is {}",
                    msg.certificate_bytes[65]
                );
                assert_eq!(
                    msg.certificate_bytes[66], 196,
                    "incorrect value for certificate_bytes[66], expected 196, is {}",
                    msg.certificate_bytes[66]
                );
                assert_eq!(
                    msg.certificate_bytes[67], 5,
                    "incorrect value for certificate_bytes[67], expected 5, is {}",
                    msg.certificate_bytes[67]
                );
                assert_eq!(
                    msg.certificate_bytes[68], 81,
                    "incorrect value for certificate_bytes[68], expected 81, is {}",
                    msg.certificate_bytes[68]
                );
                assert_eq!(
                    msg.certificate_bytes[69], 9,
                    "incorrect value for certificate_bytes[69], expected 9, is {}",
                    msg.certificate_bytes[69]
                );
                assert_eq!(
                    msg.certificate_bytes[70], 44,
                    "incorrect value for certificate_bytes[70], expected 44, is {}",
                    msg.certificate_bytes[70]
                );
                assert_eq!(
                    msg.certificate_bytes[71], 164,
                    "incorrect value for certificate_bytes[71], expected 164, is {}",
                    msg.certificate_bytes[71]
                );
                assert_eq!(
                    msg.certificate_bytes[72], 163,
                    "incorrect value for certificate_bytes[72], expected 163, is {}",
                    msg.certificate_bytes[72]
                );
                assert_eq!(
                    msg.certificate_bytes[73], 214,
                    "incorrect value for certificate_bytes[73], expected 214, is {}",
                    msg.certificate_bytes[73]
                );
                assert_eq!(
                    msg.certificate_bytes[74], 138,
                    "incorrect value for certificate_bytes[74], expected 138, is {}",
                    msg.certificate_bytes[74]
                );
                assert_eq!(
                    msg.certificate_bytes[75], 123,
                    "incorrect value for certificate_bytes[75], expected 123, is {}",
                    msg.certificate_bytes[75]
                );
                assert_eq!(
                    msg.certificate_bytes[76], 76,
                    "incorrect value for certificate_bytes[76], expected 76, is {}",
                    msg.certificate_bytes[76]
                );
                assert_eq!(
                    msg.certificate_bytes[77], 74,
                    "incorrect value for certificate_bytes[77], expected 74, is {}",
                    msg.certificate_bytes[77]
                );
                assert_eq!(
                    msg.certificate_bytes[78], 237,
                    "incorrect value for certificate_bytes[78], expected 237, is {}",
                    msg.certificate_bytes[78]
                );
                assert_eq!(
                    msg.certificate_bytes[79], 121,
                    "incorrect value for certificate_bytes[79], expected 121, is {}",
                    msg.certificate_bytes[79]
                );
                assert_eq!(
                    msg.certificate_bytes[80], 13,
                    "incorrect value for certificate_bytes[80], expected 13, is {}",
                    msg.certificate_bytes[80]
                );
                assert_eq!(
                    msg.certificate_bytes[81], 137,
                    "incorrect value for certificate_bytes[81], expected 137, is {}",
                    msg.certificate_bytes[81]
                );
                assert_eq!(
                    msg.certificate_bytes[82], 186,
                    "incorrect value for certificate_bytes[82], expected 186, is {}",
                    msg.certificate_bytes[82]
                );
                assert_eq!(
                    msg.certificate_bytes[83], 97,
                    "incorrect value for certificate_bytes[83], expected 97, is {}",
                    msg.certificate_bytes[83]
                );
                assert_eq!(
                    msg.certificate_bytes[84], 193,
                    "incorrect value for certificate_bytes[84], expected 193, is {}",
                    msg.certificate_bytes[84]
                );
                assert_eq!(
                    msg.certificate_bytes[85], 189,
                    "incorrect value for certificate_bytes[85], expected 189, is {}",
                    msg.certificate_bytes[85]
                );
                assert_eq!(
                    msg.certificate_bytes[86], 200,
                    "incorrect value for certificate_bytes[86], expected 200, is {}",
                    msg.certificate_bytes[86]
                );
                assert_eq!(
                    msg.certificate_bytes[87], 124,
                    "incorrect value for certificate_bytes[87], expected 124, is {}",
                    msg.certificate_bytes[87]
                );
                assert_eq!(
                    msg.certificate_bytes[88], 69,
                    "incorrect value for certificate_bytes[88], expected 69, is {}",
                    msg.certificate_bytes[88]
                );
                assert_eq!(
                    msg.certificate_bytes[89], 115,
                    "incorrect value for certificate_bytes[89], expected 115, is {}",
                    msg.certificate_bytes[89]
                );
                assert_eq!(
                    msg.certificate_bytes[90], 230,
                    "incorrect value for certificate_bytes[90], expected 230, is {}",
                    msg.certificate_bytes[90]
                );
                assert_eq!(
                    msg.certificate_bytes[91], 159,
                    "incorrect value for certificate_bytes[91], expected 159, is {}",
                    msg.certificate_bytes[91]
                );
                assert_eq!(
                    msg.certificate_bytes[92], 185,
                    "incorrect value for certificate_bytes[92], expected 185, is {}",
                    msg.certificate_bytes[92]
                );
                assert_eq!(
                    msg.certificate_bytes[93], 158,
                    "incorrect value for certificate_bytes[93], expected 158, is {}",
                    msg.certificate_bytes[93]
                );
                assert_eq!(
                    msg.certificate_bytes[94], 51,
                    "incorrect value for certificate_bytes[94], expected 51, is {}",
                    msg.certificate_bytes[94]
                );
                assert_eq!(
                    msg.certificate_bytes[95], 12,
                    "incorrect value for certificate_bytes[95], expected 12, is {}",
                    msg.certificate_bytes[95]
                );
                assert_eq!(
                    msg.certificate_bytes[96], 225,
                    "incorrect value for certificate_bytes[96], expected 225, is {}",
                    msg.certificate_bytes[96]
                );
                assert_eq!(
                    msg.certificate_bytes[97], 65,
                    "incorrect value for certificate_bytes[97], expected 65, is {}",
                    msg.certificate_bytes[97]
                );
                assert_eq!(
                    msg.certificate_bytes[98], 192,
                    "incorrect value for certificate_bytes[98], expected 192, is {}",
                    msg.certificate_bytes[98]
                );
                assert_eq!(
                    msg.certificate_bytes[99], 105,
                    "incorrect value for certificate_bytes[99], expected 105, is {}",
                    msg.certificate_bytes[99]
                );
                assert_eq!(
                    msg.certificate_bytes[100], 56,
                    "incorrect value for certificate_bytes[100], expected 56, is {}",
                    msg.certificate_bytes[100]
                );
                assert_eq!(
                    msg.certificate_bytes[101], 41,
                    "incorrect value for certificate_bytes[101], expected 41, is {}",
                    msg.certificate_bytes[101]
                );
                assert_eq!(
                    msg.certificate_bytes[102], 85,
                    "incorrect value for certificate_bytes[102], expected 85, is {}",
                    msg.certificate_bytes[102]
                );
                assert_eq!(
                    msg.certificate_bytes[103], 133,
                    "incorrect value for certificate_bytes[103], expected 133, is {}",
                    msg.certificate_bytes[103]
                );
                assert_eq!(
                    msg.certificate_bytes[104], 19,
                    "incorrect value for certificate_bytes[104], expected 19, is {}",
                    msg.certificate_bytes[104]
                );
                assert_eq!(
                    msg.certificate_bytes[105], 217,
                    "incorrect value for certificate_bytes[105], expected 217, is {}",
                    msg.certificate_bytes[105]
                );
                assert_eq!(
                    msg.certificate_bytes[106], 166,
                    "incorrect value for certificate_bytes[106], expected 166, is {}",
                    msg.certificate_bytes[106]
                );
                assert_eq!(
                    msg.certificate_bytes[107], 48,
                    "incorrect value for certificate_bytes[107], expected 48, is {}",
                    msg.certificate_bytes[107]
                );
                assert_eq!(
                    msg.certificate_bytes[108], 139,
                    "incorrect value for certificate_bytes[108], expected 139, is {}",
                    msg.certificate_bytes[108]
                );
                assert_eq!(
                    msg.certificate_bytes[109], 131,
                    "incorrect value for certificate_bytes[109], expected 131, is {}",
                    msg.certificate_bytes[109]
                );
                assert_eq!(
                    msg.certificate_bytes[110], 96,
                    "incorrect value for certificate_bytes[110], expected 96, is {}",
                    msg.certificate_bytes[110]
                );
                assert_eq!(
                    msg.certificate_bytes[111], 216,
                    "incorrect value for certificate_bytes[111], expected 216, is {}",
                    msg.certificate_bytes[111]
                );
                assert_eq!(
                    msg.certificate_bytes[112], 98,
                    "incorrect value for certificate_bytes[112], expected 98, is {}",
                    msg.certificate_bytes[112]
                );
                assert_eq!(
                    msg.certificate_bytes[113], 147,
                    "incorrect value for certificate_bytes[113], expected 147, is {}",
                    msg.certificate_bytes[113]
                );
                assert_eq!(
                    msg.certificate_bytes[114], 132,
                    "incorrect value for certificate_bytes[114], expected 132, is {}",
                    msg.certificate_bytes[114]
                );
                assert_eq!(
                    msg.certificate_bytes[115], 234,
                    "incorrect value for certificate_bytes[115], expected 234, is {}",
                    msg.certificate_bytes[115]
                );
                assert_eq!(
                    msg.certificate_bytes[116], 167,
                    "incorrect value for certificate_bytes[116], expected 167, is {}",
                    msg.certificate_bytes[116]
                );
                assert_eq!(
                    msg.certificate_bytes[117], 248,
                    "incorrect value for certificate_bytes[117], expected 248, is {}",
                    msg.certificate_bytes[117]
                );
                assert_eq!(
                    msg.certificate_bytes[118], 247,
                    "incorrect value for certificate_bytes[118], expected 247, is {}",
                    msg.certificate_bytes[118]
                );
                assert_eq!(
                    msg.certificate_bytes[119], 32,
                    "incorrect value for certificate_bytes[119], expected 32, is {}",
                    msg.certificate_bytes[119]
                );
                assert_eq!(
                    msg.certificate_bytes[120], 239,
                    "incorrect value for certificate_bytes[120], expected 239, is {}",
                    msg.certificate_bytes[120]
                );
                assert_eq!(
                    msg.certificate_bytes[121], 194,
                    "incorrect value for certificate_bytes[121], expected 194, is {}",
                    msg.certificate_bytes[121]
                );
                assert_eq!(
                    msg.certificate_bytes[122], 188,
                    "incorrect value for certificate_bytes[122], expected 188, is {}",
                    msg.certificate_bytes[122]
                );
                assert_eq!(
                    msg.certificate_bytes[123], 254,
                    "incorrect value for certificate_bytes[123], expected 254, is {}",
                    msg.certificate_bytes[123]
                );
                assert_eq!(
                    msg.certificate_bytes[124], 114,
                    "incorrect value for certificate_bytes[124], expected 114, is {}",
                    msg.certificate_bytes[124]
                );
                assert_eq!(
                    msg.certificate_bytes[125], 117,
                    "incorrect value for certificate_bytes[125], expected 117, is {}",
                    msg.certificate_bytes[125]
                );
                assert_eq!(
                    msg.certificate_bytes[126], 83,
                    "incorrect value for certificate_bytes[126], expected 83, is {}",
                    msg.certificate_bytes[126]
                );
                assert_eq!(
                    msg.certificate_bytes[127], 25,
                    "incorrect value for certificate_bytes[127], expected 25, is {}",
                    msg.certificate_bytes[127]
                );
                assert_eq!(
                    msg.certificate_bytes[128], 251,
                    "incorrect value for certificate_bytes[128], expected 251, is {}",
                    msg.certificate_bytes[128]
                );
                assert_eq!(
                    msg.certificate_bytes[129], 191,
                    "incorrect value for certificate_bytes[129], expected 191, is {}",
                    msg.certificate_bytes[129]
                );
                assert_eq!(
                    msg.certificate_bytes[130], 104,
                    "incorrect value for certificate_bytes[130], expected 104, is {}",
                    msg.certificate_bytes[130]
                );
                assert_eq!(
                    msg.certificate_bytes[131], 240,
                    "incorrect value for certificate_bytes[131], expected 240, is {}",
                    msg.certificate_bytes[131]
                );
                assert_eq!(
                    msg.certificate_bytes[132], 118,
                    "incorrect value for certificate_bytes[132], expected 118, is {}",
                    msg.certificate_bytes[132]
                );
                assert_eq!(
                    msg.certificate_bytes[133], 68,
                    "incorrect value for certificate_bytes[133], expected 68, is {}",
                    msg.certificate_bytes[133]
                );
                assert_eq!(
                    msg.certificate_bytes[134], 42,
                    "incorrect value for certificate_bytes[134], expected 42, is {}",
                    msg.certificate_bytes[134]
                );
                assert_eq!(
                    msg.certificate_bytes[135], 93,
                    "incorrect value for certificate_bytes[135], expected 93, is {}",
                    msg.certificate_bytes[135]
                );
                assert_eq!(
                    msg.certificate_bytes[136], 18,
                    "incorrect value for certificate_bytes[136], expected 18, is {}",
                    msg.certificate_bytes[136]
                );
                assert_eq!(
                    msg.certificate_bytes[137], 16,
                    "incorrect value for certificate_bytes[137], expected 16, is {}",
                    msg.certificate_bytes[137]
                );
                assert_eq!(
                    msg.certificate_bytes[138], 37,
                    "incorrect value for certificate_bytes[138], expected 37, is {}",
                    msg.certificate_bytes[138]
                );
                assert_eq!(
                    msg.certificate_bytes[139], 232,
                    "incorrect value for certificate_bytes[139], expected 232, is {}",
                    msg.certificate_bytes[139]
                );
                assert_eq!(
                    msg.certificate_bytes[140], 99,
                    "incorrect value for certificate_bytes[140], expected 99, is {}",
                    msg.certificate_bytes[140]
                );
                assert_eq!(
                    msg.certificate_bytes[141], 179,
                    "incorrect value for certificate_bytes[141], expected 179, is {}",
                    msg.certificate_bytes[141]
                );
                assert_eq!(
                    msg.certificate_bytes[142], 23,
                    "incorrect value for certificate_bytes[142], expected 23, is {}",
                    msg.certificate_bytes[142]
                );
                assert_eq!(
                    msg.certificate_bytes[143], 90,
                    "incorrect value for certificate_bytes[143], expected 90, is {}",
                    msg.certificate_bytes[143]
                );
                assert_eq!(
                    msg.certificate_bytes[144], 94,
                    "incorrect value for certificate_bytes[144], expected 94, is {}",
                    msg.certificate_bytes[144]
                );
                assert_eq!(
                    msg.certificate_bytes[145], 136,
                    "incorrect value for certificate_bytes[145], expected 136, is {}",
                    msg.certificate_bytes[145]
                );
                assert_eq!(
                    msg.certificate_bytes[146], 6,
                    "incorrect value for certificate_bytes[146], expected 6, is {}",
                    msg.certificate_bytes[146]
                );
                assert_eq!(
                    msg.certificate_bytes[147], 125,
                    "incorrect value for certificate_bytes[147], expected 125, is {}",
                    msg.certificate_bytes[147]
                );
                assert_eq!(
                    msg.certificate_bytes[148], 91,
                    "incorrect value for certificate_bytes[148], expected 91, is {}",
                    msg.certificate_bytes[148]
                );
                assert_eq!(
                    msg.certificate_bytes[149], 255,
                    "incorrect value for certificate_bytes[149], expected 255, is {}",
                    msg.certificate_bytes[149]
                );
                assert_eq!(
                    msg.certificate_bytes[150], 15,
                    "incorrect value for certificate_bytes[150], expected 15, is {}",
                    msg.certificate_bytes[150]
                );
                assert_eq!(
                    msg.certificate_bytes[151], 71,
                    "incorrect value for certificate_bytes[151], expected 71, is {}",
                    msg.certificate_bytes[151]
                );
                assert_eq!(
                    msg.certificate_bytes[152], 43,
                    "incorrect value for certificate_bytes[152], expected 43, is {}",
                    msg.certificate_bytes[152]
                );
                assert_eq!(
                    msg.certificate_bytes[153], 46,
                    "incorrect value for certificate_bytes[153], expected 46, is {}",
                    msg.certificate_bytes[153]
                );
                assert_eq!(
                    msg.certificate_bytes[154], 25,
                    "incorrect value for certificate_bytes[154], expected 25, is {}",
                    msg.certificate_bytes[154]
                );
                assert_eq!(
                    msg.certificate_bytes[155], 252,
                    "incorrect value for certificate_bytes[155], expected 252, is {}",
                    msg.certificate_bytes[155]
                );
                assert_eq!(
                    msg.certificate_bytes[156], 229,
                    "incorrect value for certificate_bytes[156], expected 229, is {}",
                    msg.certificate_bytes[156]
                );
                assert_eq!(
                    msg.certificate_bytes[157], 80,
                    "incorrect value for certificate_bytes[157], expected 80, is {}",
                    msg.certificate_bytes[157]
                );
                assert_eq!(
                    msg.certificate_bytes[158], 143,
                    "incorrect value for certificate_bytes[158], expected 143, is {}",
                    msg.certificate_bytes[158]
                );
                assert_eq!(
                    msg.certificate_bytes[159], 58,
                    "incorrect value for certificate_bytes[159], expected 58, is {}",
                    msg.certificate_bytes[159]
                );
                assert_eq!(
                    msg.certificate_bytes[160], 241,
                    "incorrect value for certificate_bytes[160], expected 241, is {}",
                    msg.certificate_bytes[160]
                );
                assert_eq!(
                    msg.certificate_bytes[161], 11,
                    "incorrect value for certificate_bytes[161], expected 11, is {}",
                    msg.certificate_bytes[161]
                );
                assert_eq!(
                    msg.certificate_bytes[162], 62,
                    "incorrect value for certificate_bytes[162], expected 62, is {}",
                    msg.certificate_bytes[162]
                );
                assert_eq!(
                    msg.certificate_bytes[163], 181,
                    "incorrect value for certificate_bytes[163], expected 181, is {}",
                    msg.certificate_bytes[163]
                );
                assert_eq!(
                    msg.certificate_bytes[164], 155,
                    "incorrect value for certificate_bytes[164], expected 155, is {}",
                    msg.certificate_bytes[164]
                );
                assert_eq!(
                    msg.certificate_bytes[165], 53,
                    "incorrect value for certificate_bytes[165], expected 53, is {}",
                    msg.certificate_bytes[165]
                );
                assert_eq!(
                    msg.certificate_bytes[166], 153,
                    "incorrect value for certificate_bytes[166], expected 153, is {}",
                    msg.certificate_bytes[166]
                );
                assert_eq!(
                    msg.certificate_bytes[167], 149,
                    "incorrect value for certificate_bytes[167], expected 149, is {}",
                    msg.certificate_bytes[167]
                );
                assert_eq!(
                    msg.certificate_bytes[168], 152,
                    "incorrect value for certificate_bytes[168], expected 152, is {}",
                    msg.certificate_bytes[168]
                );
                assert_eq!(
                    msg.certificate_bytes[169], 227,
                    "incorrect value for certificate_bytes[169], expected 227, is {}",
                    msg.certificate_bytes[169]
                );
                assert_eq!(
                    msg.certificate_bytes[170], 150,
                    "incorrect value for certificate_bytes[170], expected 150, is {}",
                    msg.certificate_bytes[170]
                );
                assert_eq!(
                    msg.certificate_bytes[171], 87,
                    "incorrect value for certificate_bytes[171], expected 87, is {}",
                    msg.certificate_bytes[171]
                );
                assert_eq!(
                    msg.certificate_bytes[172], 112,
                    "incorrect value for certificate_bytes[172], expected 112, is {}",
                    msg.certificate_bytes[172]
                );
                assert_eq!(
                    msg.certificate_bytes[173], 165,
                    "incorrect value for certificate_bytes[173], expected 165, is {}",
                    msg.certificate_bytes[173]
                );
                assert_eq!(
                    msg.certificate_bytes[174], 2,
                    "incorrect value for certificate_bytes[174], expected 2, is {}",
                    msg.certificate_bytes[174]
                );
                assert_eq!(
                    msg.certificate_bytes[175], 128,
                    "incorrect value for certificate_bytes[175], expected 128, is {}",
                    msg.certificate_bytes[175]
                );
                assert_eq!(
                    msg.certificate_bytes[176], 231,
                    "incorrect value for certificate_bytes[176], expected 231, is {}",
                    msg.certificate_bytes[176]
                );
                assert_eq!(
                    msg.certificate_bytes[177], 25,
                    "incorrect value for certificate_bytes[177], expected 25, is {}",
                    msg.certificate_bytes[177]
                );
                assert_eq!(
                    msg.certificate_bytes[178], 157,
                    "incorrect value for certificate_bytes[178], expected 157, is {}",
                    msg.certificate_bytes[178]
                );
                assert_eq!(
                    msg.certificate_bytes[179], 244,
                    "incorrect value for certificate_bytes[179], expected 244, is {}",
                    msg.certificate_bytes[179]
                );
                assert_eq!(
                    msg.certificate_bytes[180], 204,
                    "incorrect value for certificate_bytes[180], expected 204, is {}",
                    msg.certificate_bytes[180]
                );
                assert_eq!(
                    msg.certificate_bytes[181], 108,
                    "incorrect value for certificate_bytes[181], expected 108, is {}",
                    msg.certificate_bytes[181]
                );
                assert_eq!(
                    msg.certificate_bytes[182], 253,
                    "incorrect value for certificate_bytes[182], expected 253, is {}",
                    msg.certificate_bytes[182]
                );
                assert_eq!(
                    msg.certificate_bytes[183], 127,
                    "incorrect value for certificate_bytes[183], expected 127, is {}",
                    msg.certificate_bytes[183]
                );
                assert_eq!(
                    msg.certificate_bytes[184], 122,
                    "incorrect value for certificate_bytes[184], expected 122, is {}",
                    msg.certificate_bytes[184]
                );
                assert_eq!(
                    msg.certificate_bytes[185], 145,
                    "incorrect value for certificate_bytes[185], expected 145, is {}",
                    msg.certificate_bytes[185]
                );
                assert_eq!(
                    msg.certificate_bytes[186], 113,
                    "incorrect value for certificate_bytes[186], expected 113, is {}",
                    msg.certificate_bytes[186]
                );
                assert_eq!(
                    msg.certificate_bytes[187], 162,
                    "incorrect value for certificate_bytes[187], expected 162, is {}",
                    msg.certificate_bytes[187]
                );
                assert_eq!(
                    msg.certificate_bytes[188], 197,
                    "incorrect value for certificate_bytes[188], expected 197, is {}",
                    msg.certificate_bytes[188]
                );
                assert_eq!(
                    msg.certificate_bytes[189], 171,
                    "incorrect value for certificate_bytes[189], expected 171, is {}",
                    msg.certificate_bytes[189]
                );
                assert_eq!(
                    msg.certificate_bytes[190], 199,
                    "incorrect value for certificate_bytes[190], expected 199, is {}",
                    msg.certificate_bytes[190]
                );
                assert_eq!(
                    msg.certificate_bytes[191], 54,
                    "incorrect value for certificate_bytes[191], expected 54, is {}",
                    msg.certificate_bytes[191]
                );
                assert_eq!(
                    msg.certificate_bytes[192], 184,
                    "incorrect value for certificate_bytes[192], expected 184, is {}",
                    msg.certificate_bytes[192]
                );
                assert_eq!(
                    msg.certificate_bytes[193], 222,
                    "incorrect value for certificate_bytes[193], expected 222, is {}",
                    msg.certificate_bytes[193]
                );
                assert_eq!(
                    msg.certificate_bytes[194], 206,
                    "incorrect value for certificate_bytes[194], expected 206, is {}",
                    msg.certificate_bytes[194]
                );
                assert_eq!(
                    msg.certificate_bytes[195], 67,
                    "incorrect value for certificate_bytes[195], expected 67, is {}",
                    msg.certificate_bytes[195]
                );
                assert_eq!(
                    msg.certificate_bytes[196], 144,
                    "incorrect value for certificate_bytes[196], expected 144, is {}",
                    msg.certificate_bytes[196]
                );
                assert_eq!(
                    msg.certificate_bytes[197], 78,
                    "incorrect value for certificate_bytes[197], expected 78, is {}",
                    msg.certificate_bytes[197]
                );
                assert_eq!(
                    msg.certificate_bytes[198], 187,
                    "incorrect value for certificate_bytes[198], expected 187, is {}",
                    msg.certificate_bytes[198]
                );
                assert_eq!(
                    msg.certificate_bytes[199], 207,
                    "incorrect value for certificate_bytes[199], expected 207, is {}",
                    msg.certificate_bytes[199]
                );
                assert_eq!(
                    msg.certificate_bytes[200], 60,
                    "incorrect value for certificate_bytes[200], expected 60, is {}",
                    msg.certificate_bytes[200]
                );
                assert_eq!(
                    msg.certificate_bytes[201], 211,
                    "incorrect value for certificate_bytes[201], expected 211, is {}",
                    msg.certificate_bytes[201]
                );
                assert_eq!(
                    msg.certificate_bytes[202], 141,
                    "incorrect value for certificate_bytes[202], expected 141, is {}",
                    msg.certificate_bytes[202]
                );
                assert_eq!(
                    msg.certificate_bytes[203], 135,
                    "incorrect value for certificate_bytes[203], expected 135, is {}",
                    msg.certificate_bytes[203]
                );
                assert_eq!(
                    msg.certificate_bytes[204], 106,
                    "incorrect value for certificate_bytes[204], expected 106, is {}",
                    msg.certificate_bytes[204]
                );
                assert_eq!(
                    msg.certificate_bytes[205], 220,
                    "incorrect value for certificate_bytes[205], expected 220, is {}",
                    msg.certificate_bytes[205]
                );
                assert_eq!(
                    msg.certificate_bytes[206], 79,
                    "incorrect value for certificate_bytes[206], expected 79, is {}",
                    msg.certificate_bytes[206]
                );
                assert_eq!(
                    msg.certificate_bytes[207], 183,
                    "incorrect value for certificate_bytes[207], expected 183, is {}",
                    msg.certificate_bytes[207]
                );
                assert_eq!(
                    msg.certificate_bytes[208], 245,
                    "incorrect value for certificate_bytes[208], expected 245, is {}",
                    msg.certificate_bytes[208]
                );
                assert_eq!(
                    msg.certificate_bytes[209], 21,
                    "incorrect value for certificate_bytes[209], expected 21, is {}",
                    msg.certificate_bytes[209]
                );
                assert_eq!(
                    msg.certificate_bytes[210], 161,
                    "incorrect value for certificate_bytes[210], expected 161, is {}",
                    msg.certificate_bytes[210]
                );
                assert_eq!(
                    msg.certificate_bytes[211], 168,
                    "incorrect value for certificate_bytes[211], expected 168, is {}",
                    msg.certificate_bytes[211]
                );
                assert_eq!(
                    msg.certificate_bytes[212], 34,
                    "incorrect value for certificate_bytes[212], expected 34, is {}",
                    msg.certificate_bytes[212]
                );
                assert_eq!(
                    msg.certificate_bytes[213], 129,
                    "incorrect value for certificate_bytes[213], expected 129, is {}",
                    msg.certificate_bytes[213]
                );
                assert_eq!(
                    msg.certificate_bytes[214], 50,
                    "incorrect value for certificate_bytes[214], expected 50, is {}",
                    msg.certificate_bytes[214]
                );
                assert_eq!(
                    msg.certificate_bytes[215], 176,
                    "incorrect value for certificate_bytes[215], expected 176, is {}",
                    msg.certificate_bytes[215]
                );
                assert_eq!(
                    msg.certificate_bytes[216], 1,
                    "incorrect value for certificate_bytes[216], expected 1, is {}",
                    msg.certificate_bytes[216]
                );
                assert_eq!(
                    msg.certificate_bytes[217], 218,
                    "incorrect value for certificate_bytes[217], expected 218, is {}",
                    msg.certificate_bytes[217]
                );
                assert_eq!(
                    msg.certificate_bytes[218], 20,
                    "incorrect value for certificate_bytes[218], expected 20, is {}",
                    msg.certificate_bytes[218]
                );
                assert_eq!(
                    msg.certificate_bytes[219], 130,
                    "incorrect value for certificate_bytes[219], expected 130, is {}",
                    msg.certificate_bytes[219]
                );
                assert_eq!(
                    msg.certificate_bytes[220], 59,
                    "incorrect value for certificate_bytes[220], expected 59, is {}",
                    msg.certificate_bytes[220]
                );
                assert_eq!(
                    msg.certificate_bytes[221], 249,
                    "incorrect value for certificate_bytes[221], expected 249, is {}",
                    msg.certificate_bytes[221]
                );
                assert_eq!(
                    msg.certificate_bytes[222], 109,
                    "incorrect value for certificate_bytes[222], expected 109, is {}",
                    msg.certificate_bytes[222]
                );
                assert_eq!(
                    msg.certificate_bytes[223], 219,
                    "incorrect value for certificate_bytes[223], expected 219, is {}",
                    msg.certificate_bytes[223]
                );
                assert_eq!(
                    msg.certificate_bytes[224], 0,
                    "incorrect value for certificate_bytes[224], expected 0, is {}",
                    msg.certificate_bytes[224]
                );
                assert_eq!(
                    msg.certificate_bytes[225], 100,
                    "incorrect value for certificate_bytes[225], expected 100, is {}",
                    msg.certificate_bytes[225]
                );
                assert_eq!(
                    msg.certificate_bytes[226], 103,
                    "incorrect value for certificate_bytes[226], expected 103, is {}",
                    msg.certificate_bytes[226]
                );
                assert_eq!(
                    msg.certificate_bytes[227], 55,
                    "incorrect value for certificate_bytes[227], expected 55, is {}",
                    msg.certificate_bytes[227]
                );
                assert_eq!(
                    msg.certificate_bytes[228], 29,
                    "incorrect value for certificate_bytes[228], expected 29, is {}",
                    msg.certificate_bytes[228]
                );
                assert_eq!(
                    msg.certificate_bytes[229], 242,
                    "incorrect value for certificate_bytes[229], expected 242, is {}",
                    msg.certificate_bytes[229]
                );
                assert_eq!(
                    msg.certificate_bytes[230], 110,
                    "incorrect value for certificate_bytes[230], expected 110, is {}",
                    msg.certificate_bytes[230]
                );
                assert_eq!(
                    msg.certificate_bytes[231], 154,
                    "incorrect value for certificate_bytes[231], expected 154, is {}",
                    msg.certificate_bytes[231]
                );
                assert_eq!(
                    msg.certificate_bytes[232], 190,
                    "incorrect value for certificate_bytes[232], expected 190, is {}",
                    msg.certificate_bytes[232]
                );
                assert_eq!(
                    msg.certificate_bytes[233], 233,
                    "incorrect value for certificate_bytes[233], expected 233, is {}",
                    msg.certificate_bytes[233]
                );
                assert_eq!(
                    msg.certificate_bytes[234], 142,
                    "incorrect value for certificate_bytes[234], expected 142, is {}",
                    msg.certificate_bytes[234]
                );
                assert_eq!(
                    msg.certificate_bytes[235], 45,
                    "incorrect value for certificate_bytes[235], expected 45, is {}",
                    msg.certificate_bytes[235]
                );
                assert_eq!(
                    msg.certificate_bytes[236], 61,
                    "incorrect value for certificate_bytes[236], expected 61, is {}",
                    msg.certificate_bytes[236]
                );
                assert_eq!(
                    msg.certificate_bytes[237], 215,
                    "incorrect value for certificate_bytes[237], expected 215, is {}",
                    msg.certificate_bytes[237]
                );
                assert_eq!(
                    msg.certificate_bytes[238], 202,
                    "incorrect value for certificate_bytes[238], expected 202, is {}",
                    msg.certificate_bytes[238]
                );
                assert_eq!(
                    msg.certificate_bytes[239], 238,
                    "incorrect value for certificate_bytes[239], expected 238, is {}",
                    msg.certificate_bytes[239]
                );
                assert_eq!(
                    msg.certificate_bytes[240], 88,
                    "incorrect value for certificate_bytes[240], expected 88, is {}",
                    msg.certificate_bytes[240]
                );
                assert_eq!(
                    msg.certificate_bytes[241], 209,
                    "incorrect value for certificate_bytes[241], expected 209, is {}",
                    msg.certificate_bytes[241]
                );
                assert_eq!(
                    msg.certificate_bytes[242], 70,
                    "incorrect value for certificate_bytes[242], expected 70, is {}",
                    msg.certificate_bytes[242]
                );
                assert_eq!(
                    msg.certificate_bytes[243], 63,
                    "incorrect value for certificate_bytes[243], expected 63, is {}",
                    msg.certificate_bytes[243]
                );
                assert_eq!(
                    msg.certificate_bytes[244], 151,
                    "incorrect value for certificate_bytes[244], expected 151, is {}",
                    msg.certificate_bytes[244]
                );
                assert_eq!(
                    msg.certificate_bytes[245], 27,
                    "incorrect value for certificate_bytes[245], expected 27, is {}",
                    msg.certificate_bytes[245]
                );
                assert_eq!(
                    msg.certificate_bytes[246], 102,
                    "incorrect value for certificate_bytes[246], expected 102, is {}",
                    msg.certificate_bytes[246]
                );
                assert_eq!(
                    msg.certificate_id[0], 10,
                    "incorrect value for certificate_id[0], expected 10, is {}",
                    msg.certificate_id[0]
                );
                assert_eq!(
                    msg.certificate_id[1], 11,
                    "incorrect value for certificate_id[1], expected 11, is {}",
                    msg.certificate_id[1]
                );
                assert_eq!(
                    msg.certificate_id[2], 12,
                    "incorrect value for certificate_id[2], expected 12, is {}",
                    msg.certificate_id[2]
                );
                assert_eq!(
                    msg.certificate_id[3], 13,
                    "incorrect value for certificate_id[3], expected 13, is {}",
                    msg.certificate_id[3]
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_msg, 48,
                    "incorrect value for n_msg, expected 48, is {}",
                    msg.n_msg
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEcdsaCertificate"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
