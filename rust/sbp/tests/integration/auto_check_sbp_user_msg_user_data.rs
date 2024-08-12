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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/user/test_MsgUserData.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_user_msg_user_data() {
    {
        let mut payload = Cursor::new(vec![
            85, 0, 8, 126, 33, 255, 53, 5, 172, 138, 50, 49, 206, 234, 149, 204, 113, 31, 108, 188,
            179, 154, 156, 167, 145, 139, 42, 207, 126, 242, 193, 9, 58, 75, 8, 135, 11, 92, 131,
            245, 24, 90, 255, 30, 58, 31, 109, 148, 56, 178, 140, 30, 159, 70, 17, 170, 50, 148, 1,
            99, 112, 88, 217, 36, 84, 34, 234, 82, 144, 144, 97, 96, 75, 174, 58, 219, 180, 148,
            247, 59, 2, 116, 214, 114, 55, 134, 54, 119, 108, 128, 73, 181, 20, 233, 23, 23, 73,
            119, 136, 231, 189, 26, 174, 128, 93, 30, 76, 45, 109, 134, 81, 0, 116, 158, 127, 40,
            133, 208, 134, 127, 140, 232, 183, 184, 108, 6, 228, 54, 238, 59, 220, 30, 228, 212,
            50, 182, 97, 20, 41, 76, 227, 88, 12, 95, 112, 209, 183, 127, 4, 165, 189, 44, 239,
            232, 132, 9, 114, 184, 249, 208, 246, 194, 250, 2, 97, 173, 157, 202, 172, 180, 150,
            213, 193, 177, 209, 156, 20, 174, 18, 73, 132, 215, 115, 128, 175, 169, 116, 132, 100,
            72, 45, 25, 14, 205, 213, 145, 68, 137, 249, 54, 40, 174, 215, 148, 166, 190, 63, 118,
            6, 165, 212, 74, 68, 200, 38, 139, 212, 112, 45, 167, 236, 255, 106, 92, 132, 59, 61,
            233, 3, 246, 158, 83, 134, 246, 154, 17, 0, 6, 56, 216, 19, 216, 70, 71, 161, 184, 5,
            177, 45, 37, 98, 56, 149, 0, 73, 221, 105, 239, 168, 205, 85, 81, 245,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgUserData(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x800,
                    "Incorrect message type, expected 0x800, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x217e,
                    "incorrect sender id, expected 0x217e, is {sender_id}"
                );
                assert_eq!(
                    msg.contents[0], 53,
                    "incorrect value for contents[0], expected 53, is {}",
                    msg.contents[0]
                );
                assert_eq!(
                    msg.contents[1], 5,
                    "incorrect value for contents[1], expected 5, is {}",
                    msg.contents[1]
                );
                assert_eq!(
                    msg.contents[2], 172,
                    "incorrect value for contents[2], expected 172, is {}",
                    msg.contents[2]
                );
                assert_eq!(
                    msg.contents[3], 138,
                    "incorrect value for contents[3], expected 138, is {}",
                    msg.contents[3]
                );
                assert_eq!(
                    msg.contents[4], 50,
                    "incorrect value for contents[4], expected 50, is {}",
                    msg.contents[4]
                );
                assert_eq!(
                    msg.contents[5], 49,
                    "incorrect value for contents[5], expected 49, is {}",
                    msg.contents[5]
                );
                assert_eq!(
                    msg.contents[6], 206,
                    "incorrect value for contents[6], expected 206, is {}",
                    msg.contents[6]
                );
                assert_eq!(
                    msg.contents[7], 234,
                    "incorrect value for contents[7], expected 234, is {}",
                    msg.contents[7]
                );
                assert_eq!(
                    msg.contents[8], 149,
                    "incorrect value for contents[8], expected 149, is {}",
                    msg.contents[8]
                );
                assert_eq!(
                    msg.contents[9], 204,
                    "incorrect value for contents[9], expected 204, is {}",
                    msg.contents[9]
                );
                assert_eq!(
                    msg.contents[10], 113,
                    "incorrect value for contents[10], expected 113, is {}",
                    msg.contents[10]
                );
                assert_eq!(
                    msg.contents[11], 31,
                    "incorrect value for contents[11], expected 31, is {}",
                    msg.contents[11]
                );
                assert_eq!(
                    msg.contents[12], 108,
                    "incorrect value for contents[12], expected 108, is {}",
                    msg.contents[12]
                );
                assert_eq!(
                    msg.contents[13], 188,
                    "incorrect value for contents[13], expected 188, is {}",
                    msg.contents[13]
                );
                assert_eq!(
                    msg.contents[14], 179,
                    "incorrect value for contents[14], expected 179, is {}",
                    msg.contents[14]
                );
                assert_eq!(
                    msg.contents[15], 154,
                    "incorrect value for contents[15], expected 154, is {}",
                    msg.contents[15]
                );
                assert_eq!(
                    msg.contents[16], 156,
                    "incorrect value for contents[16], expected 156, is {}",
                    msg.contents[16]
                );
                assert_eq!(
                    msg.contents[17], 167,
                    "incorrect value for contents[17], expected 167, is {}",
                    msg.contents[17]
                );
                assert_eq!(
                    msg.contents[18], 145,
                    "incorrect value for contents[18], expected 145, is {}",
                    msg.contents[18]
                );
                assert_eq!(
                    msg.contents[19], 139,
                    "incorrect value for contents[19], expected 139, is {}",
                    msg.contents[19]
                );
                assert_eq!(
                    msg.contents[20], 42,
                    "incorrect value for contents[20], expected 42, is {}",
                    msg.contents[20]
                );
                assert_eq!(
                    msg.contents[21], 207,
                    "incorrect value for contents[21], expected 207, is {}",
                    msg.contents[21]
                );
                assert_eq!(
                    msg.contents[22], 126,
                    "incorrect value for contents[22], expected 126, is {}",
                    msg.contents[22]
                );
                assert_eq!(
                    msg.contents[23], 242,
                    "incorrect value for contents[23], expected 242, is {}",
                    msg.contents[23]
                );
                assert_eq!(
                    msg.contents[24], 193,
                    "incorrect value for contents[24], expected 193, is {}",
                    msg.contents[24]
                );
                assert_eq!(
                    msg.contents[25], 9,
                    "incorrect value for contents[25], expected 9, is {}",
                    msg.contents[25]
                );
                assert_eq!(
                    msg.contents[26], 58,
                    "incorrect value for contents[26], expected 58, is {}",
                    msg.contents[26]
                );
                assert_eq!(
                    msg.contents[27], 75,
                    "incorrect value for contents[27], expected 75, is {}",
                    msg.contents[27]
                );
                assert_eq!(
                    msg.contents[28], 8,
                    "incorrect value for contents[28], expected 8, is {}",
                    msg.contents[28]
                );
                assert_eq!(
                    msg.contents[29], 135,
                    "incorrect value for contents[29], expected 135, is {}",
                    msg.contents[29]
                );
                assert_eq!(
                    msg.contents[30], 11,
                    "incorrect value for contents[30], expected 11, is {}",
                    msg.contents[30]
                );
                assert_eq!(
                    msg.contents[31], 92,
                    "incorrect value for contents[31], expected 92, is {}",
                    msg.contents[31]
                );
                assert_eq!(
                    msg.contents[32], 131,
                    "incorrect value for contents[32], expected 131, is {}",
                    msg.contents[32]
                );
                assert_eq!(
                    msg.contents[33], 245,
                    "incorrect value for contents[33], expected 245, is {}",
                    msg.contents[33]
                );
                assert_eq!(
                    msg.contents[34], 24,
                    "incorrect value for contents[34], expected 24, is {}",
                    msg.contents[34]
                );
                assert_eq!(
                    msg.contents[35], 90,
                    "incorrect value for contents[35], expected 90, is {}",
                    msg.contents[35]
                );
                assert_eq!(
                    msg.contents[36], 255,
                    "incorrect value for contents[36], expected 255, is {}",
                    msg.contents[36]
                );
                assert_eq!(
                    msg.contents[37], 30,
                    "incorrect value for contents[37], expected 30, is {}",
                    msg.contents[37]
                );
                assert_eq!(
                    msg.contents[38], 58,
                    "incorrect value for contents[38], expected 58, is {}",
                    msg.contents[38]
                );
                assert_eq!(
                    msg.contents[39], 31,
                    "incorrect value for contents[39], expected 31, is {}",
                    msg.contents[39]
                );
                assert_eq!(
                    msg.contents[40], 109,
                    "incorrect value for contents[40], expected 109, is {}",
                    msg.contents[40]
                );
                assert_eq!(
                    msg.contents[41], 148,
                    "incorrect value for contents[41], expected 148, is {}",
                    msg.contents[41]
                );
                assert_eq!(
                    msg.contents[42], 56,
                    "incorrect value for contents[42], expected 56, is {}",
                    msg.contents[42]
                );
                assert_eq!(
                    msg.contents[43], 178,
                    "incorrect value for contents[43], expected 178, is {}",
                    msg.contents[43]
                );
                assert_eq!(
                    msg.contents[44], 140,
                    "incorrect value for contents[44], expected 140, is {}",
                    msg.contents[44]
                );
                assert_eq!(
                    msg.contents[45], 30,
                    "incorrect value for contents[45], expected 30, is {}",
                    msg.contents[45]
                );
                assert_eq!(
                    msg.contents[46], 159,
                    "incorrect value for contents[46], expected 159, is {}",
                    msg.contents[46]
                );
                assert_eq!(
                    msg.contents[47], 70,
                    "incorrect value for contents[47], expected 70, is {}",
                    msg.contents[47]
                );
                assert_eq!(
                    msg.contents[48], 17,
                    "incorrect value for contents[48], expected 17, is {}",
                    msg.contents[48]
                );
                assert_eq!(
                    msg.contents[49], 170,
                    "incorrect value for contents[49], expected 170, is {}",
                    msg.contents[49]
                );
                assert_eq!(
                    msg.contents[50], 50,
                    "incorrect value for contents[50], expected 50, is {}",
                    msg.contents[50]
                );
                assert_eq!(
                    msg.contents[51], 148,
                    "incorrect value for contents[51], expected 148, is {}",
                    msg.contents[51]
                );
                assert_eq!(
                    msg.contents[52], 1,
                    "incorrect value for contents[52], expected 1, is {}",
                    msg.contents[52]
                );
                assert_eq!(
                    msg.contents[53], 99,
                    "incorrect value for contents[53], expected 99, is {}",
                    msg.contents[53]
                );
                assert_eq!(
                    msg.contents[54], 112,
                    "incorrect value for contents[54], expected 112, is {}",
                    msg.contents[54]
                );
                assert_eq!(
                    msg.contents[55], 88,
                    "incorrect value for contents[55], expected 88, is {}",
                    msg.contents[55]
                );
                assert_eq!(
                    msg.contents[56], 217,
                    "incorrect value for contents[56], expected 217, is {}",
                    msg.contents[56]
                );
                assert_eq!(
                    msg.contents[57], 36,
                    "incorrect value for contents[57], expected 36, is {}",
                    msg.contents[57]
                );
                assert_eq!(
                    msg.contents[58], 84,
                    "incorrect value for contents[58], expected 84, is {}",
                    msg.contents[58]
                );
                assert_eq!(
                    msg.contents[59], 34,
                    "incorrect value for contents[59], expected 34, is {}",
                    msg.contents[59]
                );
                assert_eq!(
                    msg.contents[60], 234,
                    "incorrect value for contents[60], expected 234, is {}",
                    msg.contents[60]
                );
                assert_eq!(
                    msg.contents[61], 82,
                    "incorrect value for contents[61], expected 82, is {}",
                    msg.contents[61]
                );
                assert_eq!(
                    msg.contents[62], 144,
                    "incorrect value for contents[62], expected 144, is {}",
                    msg.contents[62]
                );
                assert_eq!(
                    msg.contents[63], 144,
                    "incorrect value for contents[63], expected 144, is {}",
                    msg.contents[63]
                );
                assert_eq!(
                    msg.contents[64], 97,
                    "incorrect value for contents[64], expected 97, is {}",
                    msg.contents[64]
                );
                assert_eq!(
                    msg.contents[65], 96,
                    "incorrect value for contents[65], expected 96, is {}",
                    msg.contents[65]
                );
                assert_eq!(
                    msg.contents[66], 75,
                    "incorrect value for contents[66], expected 75, is {}",
                    msg.contents[66]
                );
                assert_eq!(
                    msg.contents[67], 174,
                    "incorrect value for contents[67], expected 174, is {}",
                    msg.contents[67]
                );
                assert_eq!(
                    msg.contents[68], 58,
                    "incorrect value for contents[68], expected 58, is {}",
                    msg.contents[68]
                );
                assert_eq!(
                    msg.contents[69], 219,
                    "incorrect value for contents[69], expected 219, is {}",
                    msg.contents[69]
                );
                assert_eq!(
                    msg.contents[70], 180,
                    "incorrect value for contents[70], expected 180, is {}",
                    msg.contents[70]
                );
                assert_eq!(
                    msg.contents[71], 148,
                    "incorrect value for contents[71], expected 148, is {}",
                    msg.contents[71]
                );
                assert_eq!(
                    msg.contents[72], 247,
                    "incorrect value for contents[72], expected 247, is {}",
                    msg.contents[72]
                );
                assert_eq!(
                    msg.contents[73], 59,
                    "incorrect value for contents[73], expected 59, is {}",
                    msg.contents[73]
                );
                assert_eq!(
                    msg.contents[74], 2,
                    "incorrect value for contents[74], expected 2, is {}",
                    msg.contents[74]
                );
                assert_eq!(
                    msg.contents[75], 116,
                    "incorrect value for contents[75], expected 116, is {}",
                    msg.contents[75]
                );
                assert_eq!(
                    msg.contents[76], 214,
                    "incorrect value for contents[76], expected 214, is {}",
                    msg.contents[76]
                );
                assert_eq!(
                    msg.contents[77], 114,
                    "incorrect value for contents[77], expected 114, is {}",
                    msg.contents[77]
                );
                assert_eq!(
                    msg.contents[78], 55,
                    "incorrect value for contents[78], expected 55, is {}",
                    msg.contents[78]
                );
                assert_eq!(
                    msg.contents[79], 134,
                    "incorrect value for contents[79], expected 134, is {}",
                    msg.contents[79]
                );
                assert_eq!(
                    msg.contents[80], 54,
                    "incorrect value for contents[80], expected 54, is {}",
                    msg.contents[80]
                );
                assert_eq!(
                    msg.contents[81], 119,
                    "incorrect value for contents[81], expected 119, is {}",
                    msg.contents[81]
                );
                assert_eq!(
                    msg.contents[82], 108,
                    "incorrect value for contents[82], expected 108, is {}",
                    msg.contents[82]
                );
                assert_eq!(
                    msg.contents[83], 128,
                    "incorrect value for contents[83], expected 128, is {}",
                    msg.contents[83]
                );
                assert_eq!(
                    msg.contents[84], 73,
                    "incorrect value for contents[84], expected 73, is {}",
                    msg.contents[84]
                );
                assert_eq!(
                    msg.contents[85], 181,
                    "incorrect value for contents[85], expected 181, is {}",
                    msg.contents[85]
                );
                assert_eq!(
                    msg.contents[86], 20,
                    "incorrect value for contents[86], expected 20, is {}",
                    msg.contents[86]
                );
                assert_eq!(
                    msg.contents[87], 233,
                    "incorrect value for contents[87], expected 233, is {}",
                    msg.contents[87]
                );
                assert_eq!(
                    msg.contents[88], 23,
                    "incorrect value for contents[88], expected 23, is {}",
                    msg.contents[88]
                );
                assert_eq!(
                    msg.contents[89], 23,
                    "incorrect value for contents[89], expected 23, is {}",
                    msg.contents[89]
                );
                assert_eq!(
                    msg.contents[90], 73,
                    "incorrect value for contents[90], expected 73, is {}",
                    msg.contents[90]
                );
                assert_eq!(
                    msg.contents[91], 119,
                    "incorrect value for contents[91], expected 119, is {}",
                    msg.contents[91]
                );
                assert_eq!(
                    msg.contents[92], 136,
                    "incorrect value for contents[92], expected 136, is {}",
                    msg.contents[92]
                );
                assert_eq!(
                    msg.contents[93], 231,
                    "incorrect value for contents[93], expected 231, is {}",
                    msg.contents[93]
                );
                assert_eq!(
                    msg.contents[94], 189,
                    "incorrect value for contents[94], expected 189, is {}",
                    msg.contents[94]
                );
                assert_eq!(
                    msg.contents[95], 26,
                    "incorrect value for contents[95], expected 26, is {}",
                    msg.contents[95]
                );
                assert_eq!(
                    msg.contents[96], 174,
                    "incorrect value for contents[96], expected 174, is {}",
                    msg.contents[96]
                );
                assert_eq!(
                    msg.contents[97], 128,
                    "incorrect value for contents[97], expected 128, is {}",
                    msg.contents[97]
                );
                assert_eq!(
                    msg.contents[98], 93,
                    "incorrect value for contents[98], expected 93, is {}",
                    msg.contents[98]
                );
                assert_eq!(
                    msg.contents[99], 30,
                    "incorrect value for contents[99], expected 30, is {}",
                    msg.contents[99]
                );
                assert_eq!(
                    msg.contents[100], 76,
                    "incorrect value for contents[100], expected 76, is {}",
                    msg.contents[100]
                );
                assert_eq!(
                    msg.contents[101], 45,
                    "incorrect value for contents[101], expected 45, is {}",
                    msg.contents[101]
                );
                assert_eq!(
                    msg.contents[102], 109,
                    "incorrect value for contents[102], expected 109, is {}",
                    msg.contents[102]
                );
                assert_eq!(
                    msg.contents[103], 134,
                    "incorrect value for contents[103], expected 134, is {}",
                    msg.contents[103]
                );
                assert_eq!(
                    msg.contents[104], 81,
                    "incorrect value for contents[104], expected 81, is {}",
                    msg.contents[104]
                );
                assert_eq!(
                    msg.contents[105], 0,
                    "incorrect value for contents[105], expected 0, is {}",
                    msg.contents[105]
                );
                assert_eq!(
                    msg.contents[106], 116,
                    "incorrect value for contents[106], expected 116, is {}",
                    msg.contents[106]
                );
                assert_eq!(
                    msg.contents[107], 158,
                    "incorrect value for contents[107], expected 158, is {}",
                    msg.contents[107]
                );
                assert_eq!(
                    msg.contents[108], 127,
                    "incorrect value for contents[108], expected 127, is {}",
                    msg.contents[108]
                );
                assert_eq!(
                    msg.contents[109], 40,
                    "incorrect value for contents[109], expected 40, is {}",
                    msg.contents[109]
                );
                assert_eq!(
                    msg.contents[110], 133,
                    "incorrect value for contents[110], expected 133, is {}",
                    msg.contents[110]
                );
                assert_eq!(
                    msg.contents[111], 208,
                    "incorrect value for contents[111], expected 208, is {}",
                    msg.contents[111]
                );
                assert_eq!(
                    msg.contents[112], 134,
                    "incorrect value for contents[112], expected 134, is {}",
                    msg.contents[112]
                );
                assert_eq!(
                    msg.contents[113], 127,
                    "incorrect value for contents[113], expected 127, is {}",
                    msg.contents[113]
                );
                assert_eq!(
                    msg.contents[114], 140,
                    "incorrect value for contents[114], expected 140, is {}",
                    msg.contents[114]
                );
                assert_eq!(
                    msg.contents[115], 232,
                    "incorrect value for contents[115], expected 232, is {}",
                    msg.contents[115]
                );
                assert_eq!(
                    msg.contents[116], 183,
                    "incorrect value for contents[116], expected 183, is {}",
                    msg.contents[116]
                );
                assert_eq!(
                    msg.contents[117], 184,
                    "incorrect value for contents[117], expected 184, is {}",
                    msg.contents[117]
                );
                assert_eq!(
                    msg.contents[118], 108,
                    "incorrect value for contents[118], expected 108, is {}",
                    msg.contents[118]
                );
                assert_eq!(
                    msg.contents[119], 6,
                    "incorrect value for contents[119], expected 6, is {}",
                    msg.contents[119]
                );
                assert_eq!(
                    msg.contents[120], 228,
                    "incorrect value for contents[120], expected 228, is {}",
                    msg.contents[120]
                );
                assert_eq!(
                    msg.contents[121], 54,
                    "incorrect value for contents[121], expected 54, is {}",
                    msg.contents[121]
                );
                assert_eq!(
                    msg.contents[122], 238,
                    "incorrect value for contents[122], expected 238, is {}",
                    msg.contents[122]
                );
                assert_eq!(
                    msg.contents[123], 59,
                    "incorrect value for contents[123], expected 59, is {}",
                    msg.contents[123]
                );
                assert_eq!(
                    msg.contents[124], 220,
                    "incorrect value for contents[124], expected 220, is {}",
                    msg.contents[124]
                );
                assert_eq!(
                    msg.contents[125], 30,
                    "incorrect value for contents[125], expected 30, is {}",
                    msg.contents[125]
                );
                assert_eq!(
                    msg.contents[126], 228,
                    "incorrect value for contents[126], expected 228, is {}",
                    msg.contents[126]
                );
                assert_eq!(
                    msg.contents[127], 212,
                    "incorrect value for contents[127], expected 212, is {}",
                    msg.contents[127]
                );
                assert_eq!(
                    msg.contents[128], 50,
                    "incorrect value for contents[128], expected 50, is {}",
                    msg.contents[128]
                );
                assert_eq!(
                    msg.contents[129], 182,
                    "incorrect value for contents[129], expected 182, is {}",
                    msg.contents[129]
                );
                assert_eq!(
                    msg.contents[130], 97,
                    "incorrect value for contents[130], expected 97, is {}",
                    msg.contents[130]
                );
                assert_eq!(
                    msg.contents[131], 20,
                    "incorrect value for contents[131], expected 20, is {}",
                    msg.contents[131]
                );
                assert_eq!(
                    msg.contents[132], 41,
                    "incorrect value for contents[132], expected 41, is {}",
                    msg.contents[132]
                );
                assert_eq!(
                    msg.contents[133], 76,
                    "incorrect value for contents[133], expected 76, is {}",
                    msg.contents[133]
                );
                assert_eq!(
                    msg.contents[134], 227,
                    "incorrect value for contents[134], expected 227, is {}",
                    msg.contents[134]
                );
                assert_eq!(
                    msg.contents[135], 88,
                    "incorrect value for contents[135], expected 88, is {}",
                    msg.contents[135]
                );
                assert_eq!(
                    msg.contents[136], 12,
                    "incorrect value for contents[136], expected 12, is {}",
                    msg.contents[136]
                );
                assert_eq!(
                    msg.contents[137], 95,
                    "incorrect value for contents[137], expected 95, is {}",
                    msg.contents[137]
                );
                assert_eq!(
                    msg.contents[138], 112,
                    "incorrect value for contents[138], expected 112, is {}",
                    msg.contents[138]
                );
                assert_eq!(
                    msg.contents[139], 209,
                    "incorrect value for contents[139], expected 209, is {}",
                    msg.contents[139]
                );
                assert_eq!(
                    msg.contents[140], 183,
                    "incorrect value for contents[140], expected 183, is {}",
                    msg.contents[140]
                );
                assert_eq!(
                    msg.contents[141], 127,
                    "incorrect value for contents[141], expected 127, is {}",
                    msg.contents[141]
                );
                assert_eq!(
                    msg.contents[142], 4,
                    "incorrect value for contents[142], expected 4, is {}",
                    msg.contents[142]
                );
                assert_eq!(
                    msg.contents[143], 165,
                    "incorrect value for contents[143], expected 165, is {}",
                    msg.contents[143]
                );
                assert_eq!(
                    msg.contents[144], 189,
                    "incorrect value for contents[144], expected 189, is {}",
                    msg.contents[144]
                );
                assert_eq!(
                    msg.contents[145], 44,
                    "incorrect value for contents[145], expected 44, is {}",
                    msg.contents[145]
                );
                assert_eq!(
                    msg.contents[146], 239,
                    "incorrect value for contents[146], expected 239, is {}",
                    msg.contents[146]
                );
                assert_eq!(
                    msg.contents[147], 232,
                    "incorrect value for contents[147], expected 232, is {}",
                    msg.contents[147]
                );
                assert_eq!(
                    msg.contents[148], 132,
                    "incorrect value for contents[148], expected 132, is {}",
                    msg.contents[148]
                );
                assert_eq!(
                    msg.contents[149], 9,
                    "incorrect value for contents[149], expected 9, is {}",
                    msg.contents[149]
                );
                assert_eq!(
                    msg.contents[150], 114,
                    "incorrect value for contents[150], expected 114, is {}",
                    msg.contents[150]
                );
                assert_eq!(
                    msg.contents[151], 184,
                    "incorrect value for contents[151], expected 184, is {}",
                    msg.contents[151]
                );
                assert_eq!(
                    msg.contents[152], 249,
                    "incorrect value for contents[152], expected 249, is {}",
                    msg.contents[152]
                );
                assert_eq!(
                    msg.contents[153], 208,
                    "incorrect value for contents[153], expected 208, is {}",
                    msg.contents[153]
                );
                assert_eq!(
                    msg.contents[154], 246,
                    "incorrect value for contents[154], expected 246, is {}",
                    msg.contents[154]
                );
                assert_eq!(
                    msg.contents[155], 194,
                    "incorrect value for contents[155], expected 194, is {}",
                    msg.contents[155]
                );
                assert_eq!(
                    msg.contents[156], 250,
                    "incorrect value for contents[156], expected 250, is {}",
                    msg.contents[156]
                );
                assert_eq!(
                    msg.contents[157], 2,
                    "incorrect value for contents[157], expected 2, is {}",
                    msg.contents[157]
                );
                assert_eq!(
                    msg.contents[158], 97,
                    "incorrect value for contents[158], expected 97, is {}",
                    msg.contents[158]
                );
                assert_eq!(
                    msg.contents[159], 173,
                    "incorrect value for contents[159], expected 173, is {}",
                    msg.contents[159]
                );
                assert_eq!(
                    msg.contents[160], 157,
                    "incorrect value for contents[160], expected 157, is {}",
                    msg.contents[160]
                );
                assert_eq!(
                    msg.contents[161], 202,
                    "incorrect value for contents[161], expected 202, is {}",
                    msg.contents[161]
                );
                assert_eq!(
                    msg.contents[162], 172,
                    "incorrect value for contents[162], expected 172, is {}",
                    msg.contents[162]
                );
                assert_eq!(
                    msg.contents[163], 180,
                    "incorrect value for contents[163], expected 180, is {}",
                    msg.contents[163]
                );
                assert_eq!(
                    msg.contents[164], 150,
                    "incorrect value for contents[164], expected 150, is {}",
                    msg.contents[164]
                );
                assert_eq!(
                    msg.contents[165], 213,
                    "incorrect value for contents[165], expected 213, is {}",
                    msg.contents[165]
                );
                assert_eq!(
                    msg.contents[166], 193,
                    "incorrect value for contents[166], expected 193, is {}",
                    msg.contents[166]
                );
                assert_eq!(
                    msg.contents[167], 177,
                    "incorrect value for contents[167], expected 177, is {}",
                    msg.contents[167]
                );
                assert_eq!(
                    msg.contents[168], 209,
                    "incorrect value for contents[168], expected 209, is {}",
                    msg.contents[168]
                );
                assert_eq!(
                    msg.contents[169], 156,
                    "incorrect value for contents[169], expected 156, is {}",
                    msg.contents[169]
                );
                assert_eq!(
                    msg.contents[170], 20,
                    "incorrect value for contents[170], expected 20, is {}",
                    msg.contents[170]
                );
                assert_eq!(
                    msg.contents[171], 174,
                    "incorrect value for contents[171], expected 174, is {}",
                    msg.contents[171]
                );
                assert_eq!(
                    msg.contents[172], 18,
                    "incorrect value for contents[172], expected 18, is {}",
                    msg.contents[172]
                );
                assert_eq!(
                    msg.contents[173], 73,
                    "incorrect value for contents[173], expected 73, is {}",
                    msg.contents[173]
                );
                assert_eq!(
                    msg.contents[174], 132,
                    "incorrect value for contents[174], expected 132, is {}",
                    msg.contents[174]
                );
                assert_eq!(
                    msg.contents[175], 215,
                    "incorrect value for contents[175], expected 215, is {}",
                    msg.contents[175]
                );
                assert_eq!(
                    msg.contents[176], 115,
                    "incorrect value for contents[176], expected 115, is {}",
                    msg.contents[176]
                );
                assert_eq!(
                    msg.contents[177], 128,
                    "incorrect value for contents[177], expected 128, is {}",
                    msg.contents[177]
                );
                assert_eq!(
                    msg.contents[178], 175,
                    "incorrect value for contents[178], expected 175, is {}",
                    msg.contents[178]
                );
                assert_eq!(
                    msg.contents[179], 169,
                    "incorrect value for contents[179], expected 169, is {}",
                    msg.contents[179]
                );
                assert_eq!(
                    msg.contents[180], 116,
                    "incorrect value for contents[180], expected 116, is {}",
                    msg.contents[180]
                );
                assert_eq!(
                    msg.contents[181], 132,
                    "incorrect value for contents[181], expected 132, is {}",
                    msg.contents[181]
                );
                assert_eq!(
                    msg.contents[182], 100,
                    "incorrect value for contents[182], expected 100, is {}",
                    msg.contents[182]
                );
                assert_eq!(
                    msg.contents[183], 72,
                    "incorrect value for contents[183], expected 72, is {}",
                    msg.contents[183]
                );
                assert_eq!(
                    msg.contents[184], 45,
                    "incorrect value for contents[184], expected 45, is {}",
                    msg.contents[184]
                );
                assert_eq!(
                    msg.contents[185], 25,
                    "incorrect value for contents[185], expected 25, is {}",
                    msg.contents[185]
                );
                assert_eq!(
                    msg.contents[186], 14,
                    "incorrect value for contents[186], expected 14, is {}",
                    msg.contents[186]
                );
                assert_eq!(
                    msg.contents[187], 205,
                    "incorrect value for contents[187], expected 205, is {}",
                    msg.contents[187]
                );
                assert_eq!(
                    msg.contents[188], 213,
                    "incorrect value for contents[188], expected 213, is {}",
                    msg.contents[188]
                );
                assert_eq!(
                    msg.contents[189], 145,
                    "incorrect value for contents[189], expected 145, is {}",
                    msg.contents[189]
                );
                assert_eq!(
                    msg.contents[190], 68,
                    "incorrect value for contents[190], expected 68, is {}",
                    msg.contents[190]
                );
                assert_eq!(
                    msg.contents[191], 137,
                    "incorrect value for contents[191], expected 137, is {}",
                    msg.contents[191]
                );
                assert_eq!(
                    msg.contents[192], 249,
                    "incorrect value for contents[192], expected 249, is {}",
                    msg.contents[192]
                );
                assert_eq!(
                    msg.contents[193], 54,
                    "incorrect value for contents[193], expected 54, is {}",
                    msg.contents[193]
                );
                assert_eq!(
                    msg.contents[194], 40,
                    "incorrect value for contents[194], expected 40, is {}",
                    msg.contents[194]
                );
                assert_eq!(
                    msg.contents[195], 174,
                    "incorrect value for contents[195], expected 174, is {}",
                    msg.contents[195]
                );
                assert_eq!(
                    msg.contents[196], 215,
                    "incorrect value for contents[196], expected 215, is {}",
                    msg.contents[196]
                );
                assert_eq!(
                    msg.contents[197], 148,
                    "incorrect value for contents[197], expected 148, is {}",
                    msg.contents[197]
                );
                assert_eq!(
                    msg.contents[198], 166,
                    "incorrect value for contents[198], expected 166, is {}",
                    msg.contents[198]
                );
                assert_eq!(
                    msg.contents[199], 190,
                    "incorrect value for contents[199], expected 190, is {}",
                    msg.contents[199]
                );
                assert_eq!(
                    msg.contents[200], 63,
                    "incorrect value for contents[200], expected 63, is {}",
                    msg.contents[200]
                );
                assert_eq!(
                    msg.contents[201], 118,
                    "incorrect value for contents[201], expected 118, is {}",
                    msg.contents[201]
                );
                assert_eq!(
                    msg.contents[202], 6,
                    "incorrect value for contents[202], expected 6, is {}",
                    msg.contents[202]
                );
                assert_eq!(
                    msg.contents[203], 165,
                    "incorrect value for contents[203], expected 165, is {}",
                    msg.contents[203]
                );
                assert_eq!(
                    msg.contents[204], 212,
                    "incorrect value for contents[204], expected 212, is {}",
                    msg.contents[204]
                );
                assert_eq!(
                    msg.contents[205], 74,
                    "incorrect value for contents[205], expected 74, is {}",
                    msg.contents[205]
                );
                assert_eq!(
                    msg.contents[206], 68,
                    "incorrect value for contents[206], expected 68, is {}",
                    msg.contents[206]
                );
                assert_eq!(
                    msg.contents[207], 200,
                    "incorrect value for contents[207], expected 200, is {}",
                    msg.contents[207]
                );
                assert_eq!(
                    msg.contents[208], 38,
                    "incorrect value for contents[208], expected 38, is {}",
                    msg.contents[208]
                );
                assert_eq!(
                    msg.contents[209], 139,
                    "incorrect value for contents[209], expected 139, is {}",
                    msg.contents[209]
                );
                assert_eq!(
                    msg.contents[210], 212,
                    "incorrect value for contents[210], expected 212, is {}",
                    msg.contents[210]
                );
                assert_eq!(
                    msg.contents[211], 112,
                    "incorrect value for contents[211], expected 112, is {}",
                    msg.contents[211]
                );
                assert_eq!(
                    msg.contents[212], 45,
                    "incorrect value for contents[212], expected 45, is {}",
                    msg.contents[212]
                );
                assert_eq!(
                    msg.contents[213], 167,
                    "incorrect value for contents[213], expected 167, is {}",
                    msg.contents[213]
                );
                assert_eq!(
                    msg.contents[214], 236,
                    "incorrect value for contents[214], expected 236, is {}",
                    msg.contents[214]
                );
                assert_eq!(
                    msg.contents[215], 255,
                    "incorrect value for contents[215], expected 255, is {}",
                    msg.contents[215]
                );
                assert_eq!(
                    msg.contents[216], 106,
                    "incorrect value for contents[216], expected 106, is {}",
                    msg.contents[216]
                );
                assert_eq!(
                    msg.contents[217], 92,
                    "incorrect value for contents[217], expected 92, is {}",
                    msg.contents[217]
                );
                assert_eq!(
                    msg.contents[218], 132,
                    "incorrect value for contents[218], expected 132, is {}",
                    msg.contents[218]
                );
                assert_eq!(
                    msg.contents[219], 59,
                    "incorrect value for contents[219], expected 59, is {}",
                    msg.contents[219]
                );
                assert_eq!(
                    msg.contents[220], 61,
                    "incorrect value for contents[220], expected 61, is {}",
                    msg.contents[220]
                );
                assert_eq!(
                    msg.contents[221], 233,
                    "incorrect value for contents[221], expected 233, is {}",
                    msg.contents[221]
                );
                assert_eq!(
                    msg.contents[222], 3,
                    "incorrect value for contents[222], expected 3, is {}",
                    msg.contents[222]
                );
                assert_eq!(
                    msg.contents[223], 246,
                    "incorrect value for contents[223], expected 246, is {}",
                    msg.contents[223]
                );
                assert_eq!(
                    msg.contents[224], 158,
                    "incorrect value for contents[224], expected 158, is {}",
                    msg.contents[224]
                );
                assert_eq!(
                    msg.contents[225], 83,
                    "incorrect value for contents[225], expected 83, is {}",
                    msg.contents[225]
                );
                assert_eq!(
                    msg.contents[226], 134,
                    "incorrect value for contents[226], expected 134, is {}",
                    msg.contents[226]
                );
                assert_eq!(
                    msg.contents[227], 246,
                    "incorrect value for contents[227], expected 246, is {}",
                    msg.contents[227]
                );
                assert_eq!(
                    msg.contents[228], 154,
                    "incorrect value for contents[228], expected 154, is {}",
                    msg.contents[228]
                );
                assert_eq!(
                    msg.contents[229], 17,
                    "incorrect value for contents[229], expected 17, is {}",
                    msg.contents[229]
                );
                assert_eq!(
                    msg.contents[230], 0,
                    "incorrect value for contents[230], expected 0, is {}",
                    msg.contents[230]
                );
                assert_eq!(
                    msg.contents[231], 6,
                    "incorrect value for contents[231], expected 6, is {}",
                    msg.contents[231]
                );
                assert_eq!(
                    msg.contents[232], 56,
                    "incorrect value for contents[232], expected 56, is {}",
                    msg.contents[232]
                );
                assert_eq!(
                    msg.contents[233], 216,
                    "incorrect value for contents[233], expected 216, is {}",
                    msg.contents[233]
                );
                assert_eq!(
                    msg.contents[234], 19,
                    "incorrect value for contents[234], expected 19, is {}",
                    msg.contents[234]
                );
                assert_eq!(
                    msg.contents[235], 216,
                    "incorrect value for contents[235], expected 216, is {}",
                    msg.contents[235]
                );
                assert_eq!(
                    msg.contents[236], 70,
                    "incorrect value for contents[236], expected 70, is {}",
                    msg.contents[236]
                );
                assert_eq!(
                    msg.contents[237], 71,
                    "incorrect value for contents[237], expected 71, is {}",
                    msg.contents[237]
                );
                assert_eq!(
                    msg.contents[238], 161,
                    "incorrect value for contents[238], expected 161, is {}",
                    msg.contents[238]
                );
                assert_eq!(
                    msg.contents[239], 184,
                    "incorrect value for contents[239], expected 184, is {}",
                    msg.contents[239]
                );
                assert_eq!(
                    msg.contents[240], 5,
                    "incorrect value for contents[240], expected 5, is {}",
                    msg.contents[240]
                );
                assert_eq!(
                    msg.contents[241], 177,
                    "incorrect value for contents[241], expected 177, is {}",
                    msg.contents[241]
                );
                assert_eq!(
                    msg.contents[242], 45,
                    "incorrect value for contents[242], expected 45, is {}",
                    msg.contents[242]
                );
                assert_eq!(
                    msg.contents[243], 37,
                    "incorrect value for contents[243], expected 37, is {}",
                    msg.contents[243]
                );
                assert_eq!(
                    msg.contents[244], 98,
                    "incorrect value for contents[244], expected 98, is {}",
                    msg.contents[244]
                );
                assert_eq!(
                    msg.contents[245], 56,
                    "incorrect value for contents[245], expected 56, is {}",
                    msg.contents[245]
                );
                assert_eq!(
                    msg.contents[246], 149,
                    "incorrect value for contents[246], expected 149, is {}",
                    msg.contents[246]
                );
                assert_eq!(
                    msg.contents[247], 0,
                    "incorrect value for contents[247], expected 0, is {}",
                    msg.contents[247]
                );
                assert_eq!(
                    msg.contents[248], 73,
                    "incorrect value for contents[248], expected 73, is {}",
                    msg.contents[248]
                );
                assert_eq!(
                    msg.contents[249], 221,
                    "incorrect value for contents[249], expected 221, is {}",
                    msg.contents[249]
                );
                assert_eq!(
                    msg.contents[250], 105,
                    "incorrect value for contents[250], expected 105, is {}",
                    msg.contents[250]
                );
                assert_eq!(
                    msg.contents[251], 239,
                    "incorrect value for contents[251], expected 239, is {}",
                    msg.contents[251]
                );
                assert_eq!(
                    msg.contents[252], 168,
                    "incorrect value for contents[252], expected 168, is {}",
                    msg.contents[252]
                );
                assert_eq!(
                    msg.contents[253], 205,
                    "incorrect value for contents[253], expected 205, is {}",
                    msg.contents[253]
                );
                assert_eq!(
                    msg.contents[254], 85,
                    "incorrect value for contents[254], expected 85, is {}",
                    msg.contents[254]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgUserData"),
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
fn test_json2sbp_auto_check_sbp_user_msg_user_data() {
    {
        let json_input = r#"{"crc":62801,"length":255,"msg_type":2048,"payload":"NQWsijIxzuqVzHEfbLyzmpynkYsqz37ywQk6SwiHC1yD9Rha/x46H22UOLKMHp9GEaoylAFjcFjZJFQi6lKQkGFgS64627SU9zsCdNZyN4Y2d2yASbUU6RcXSXeI570aroBdHkwtbYZRAHSefyiF0IZ/jOi3uGwG5DbuO9we5NQytmEUKUzjWAxfcNG3fwSlvSzv6IQJcrj50PbC+gJhrZ3KrLSW1cGx0ZwUrhJJhNdzgK+pdIRkSC0ZDs3VkUSJ+TYorteUpr4/dgal1EpEyCaL1HAtp+z/alyEOz3pA/aeU4b2mhEABjjYE9hGR6G4BbEtJWI4lQBJ3WnvqM1V","preamble":85,"sender":8574,"contents":[53,5,172,138,50,49,206,234,149,204,113,31,108,188,179,154,156,167,145,139,42,207,126,242,193,9,58,75,8,135,11,92,131,245,24,90,255,30,58,31,109,148,56,178,140,30,159,70,17,170,50,148,1,99,112,88,217,36,84,34,234,82,144,144,97,96,75,174,58,219,180,148,247,59,2,116,214,114,55,134,54,119,108,128,73,181,20,233,23,23,73,119,136,231,189,26,174,128,93,30,76,45,109,134,81,0,116,158,127,40,133,208,134,127,140,232,183,184,108,6,228,54,238,59,220,30,228,212,50,182,97,20,41,76,227,88,12,95,112,209,183,127,4,165,189,44,239,232,132,9,114,184,249,208,246,194,250,2,97,173,157,202,172,180,150,213,193,177,209,156,20,174,18,73,132,215,115,128,175,169,116,132,100,72,45,25,14,205,213,145,68,137,249,54,40,174,215,148,166,190,63,118,6,165,212,74,68,200,38,139,212,112,45,167,236,255,106,92,132,59,61,233,3,246,158,83,134,246,154,17,0,6,56,216,19,216,70,71,161,184,5,177,45,37,98,56,149,0,73,221,105,239,168,205,85]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgUserData(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x800,
                    "Incorrect message type, expected 0x800, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x217e,
                    "incorrect sender id, expected 0x217e, is {sender_id}"
                );
                assert_eq!(
                    msg.contents[0], 53,
                    "incorrect value for contents[0], expected 53, is {}",
                    msg.contents[0]
                );
                assert_eq!(
                    msg.contents[1], 5,
                    "incorrect value for contents[1], expected 5, is {}",
                    msg.contents[1]
                );
                assert_eq!(
                    msg.contents[2], 172,
                    "incorrect value for contents[2], expected 172, is {}",
                    msg.contents[2]
                );
                assert_eq!(
                    msg.contents[3], 138,
                    "incorrect value for contents[3], expected 138, is {}",
                    msg.contents[3]
                );
                assert_eq!(
                    msg.contents[4], 50,
                    "incorrect value for contents[4], expected 50, is {}",
                    msg.contents[4]
                );
                assert_eq!(
                    msg.contents[5], 49,
                    "incorrect value for contents[5], expected 49, is {}",
                    msg.contents[5]
                );
                assert_eq!(
                    msg.contents[6], 206,
                    "incorrect value for contents[6], expected 206, is {}",
                    msg.contents[6]
                );
                assert_eq!(
                    msg.contents[7], 234,
                    "incorrect value for contents[7], expected 234, is {}",
                    msg.contents[7]
                );
                assert_eq!(
                    msg.contents[8], 149,
                    "incorrect value for contents[8], expected 149, is {}",
                    msg.contents[8]
                );
                assert_eq!(
                    msg.contents[9], 204,
                    "incorrect value for contents[9], expected 204, is {}",
                    msg.contents[9]
                );
                assert_eq!(
                    msg.contents[10], 113,
                    "incorrect value for contents[10], expected 113, is {}",
                    msg.contents[10]
                );
                assert_eq!(
                    msg.contents[11], 31,
                    "incorrect value for contents[11], expected 31, is {}",
                    msg.contents[11]
                );
                assert_eq!(
                    msg.contents[12], 108,
                    "incorrect value for contents[12], expected 108, is {}",
                    msg.contents[12]
                );
                assert_eq!(
                    msg.contents[13], 188,
                    "incorrect value for contents[13], expected 188, is {}",
                    msg.contents[13]
                );
                assert_eq!(
                    msg.contents[14], 179,
                    "incorrect value for contents[14], expected 179, is {}",
                    msg.contents[14]
                );
                assert_eq!(
                    msg.contents[15], 154,
                    "incorrect value for contents[15], expected 154, is {}",
                    msg.contents[15]
                );
                assert_eq!(
                    msg.contents[16], 156,
                    "incorrect value for contents[16], expected 156, is {}",
                    msg.contents[16]
                );
                assert_eq!(
                    msg.contents[17], 167,
                    "incorrect value for contents[17], expected 167, is {}",
                    msg.contents[17]
                );
                assert_eq!(
                    msg.contents[18], 145,
                    "incorrect value for contents[18], expected 145, is {}",
                    msg.contents[18]
                );
                assert_eq!(
                    msg.contents[19], 139,
                    "incorrect value for contents[19], expected 139, is {}",
                    msg.contents[19]
                );
                assert_eq!(
                    msg.contents[20], 42,
                    "incorrect value for contents[20], expected 42, is {}",
                    msg.contents[20]
                );
                assert_eq!(
                    msg.contents[21], 207,
                    "incorrect value for contents[21], expected 207, is {}",
                    msg.contents[21]
                );
                assert_eq!(
                    msg.contents[22], 126,
                    "incorrect value for contents[22], expected 126, is {}",
                    msg.contents[22]
                );
                assert_eq!(
                    msg.contents[23], 242,
                    "incorrect value for contents[23], expected 242, is {}",
                    msg.contents[23]
                );
                assert_eq!(
                    msg.contents[24], 193,
                    "incorrect value for contents[24], expected 193, is {}",
                    msg.contents[24]
                );
                assert_eq!(
                    msg.contents[25], 9,
                    "incorrect value for contents[25], expected 9, is {}",
                    msg.contents[25]
                );
                assert_eq!(
                    msg.contents[26], 58,
                    "incorrect value for contents[26], expected 58, is {}",
                    msg.contents[26]
                );
                assert_eq!(
                    msg.contents[27], 75,
                    "incorrect value for contents[27], expected 75, is {}",
                    msg.contents[27]
                );
                assert_eq!(
                    msg.contents[28], 8,
                    "incorrect value for contents[28], expected 8, is {}",
                    msg.contents[28]
                );
                assert_eq!(
                    msg.contents[29], 135,
                    "incorrect value for contents[29], expected 135, is {}",
                    msg.contents[29]
                );
                assert_eq!(
                    msg.contents[30], 11,
                    "incorrect value for contents[30], expected 11, is {}",
                    msg.contents[30]
                );
                assert_eq!(
                    msg.contents[31], 92,
                    "incorrect value for contents[31], expected 92, is {}",
                    msg.contents[31]
                );
                assert_eq!(
                    msg.contents[32], 131,
                    "incorrect value for contents[32], expected 131, is {}",
                    msg.contents[32]
                );
                assert_eq!(
                    msg.contents[33], 245,
                    "incorrect value for contents[33], expected 245, is {}",
                    msg.contents[33]
                );
                assert_eq!(
                    msg.contents[34], 24,
                    "incorrect value for contents[34], expected 24, is {}",
                    msg.contents[34]
                );
                assert_eq!(
                    msg.contents[35], 90,
                    "incorrect value for contents[35], expected 90, is {}",
                    msg.contents[35]
                );
                assert_eq!(
                    msg.contents[36], 255,
                    "incorrect value for contents[36], expected 255, is {}",
                    msg.contents[36]
                );
                assert_eq!(
                    msg.contents[37], 30,
                    "incorrect value for contents[37], expected 30, is {}",
                    msg.contents[37]
                );
                assert_eq!(
                    msg.contents[38], 58,
                    "incorrect value for contents[38], expected 58, is {}",
                    msg.contents[38]
                );
                assert_eq!(
                    msg.contents[39], 31,
                    "incorrect value for contents[39], expected 31, is {}",
                    msg.contents[39]
                );
                assert_eq!(
                    msg.contents[40], 109,
                    "incorrect value for contents[40], expected 109, is {}",
                    msg.contents[40]
                );
                assert_eq!(
                    msg.contents[41], 148,
                    "incorrect value for contents[41], expected 148, is {}",
                    msg.contents[41]
                );
                assert_eq!(
                    msg.contents[42], 56,
                    "incorrect value for contents[42], expected 56, is {}",
                    msg.contents[42]
                );
                assert_eq!(
                    msg.contents[43], 178,
                    "incorrect value for contents[43], expected 178, is {}",
                    msg.contents[43]
                );
                assert_eq!(
                    msg.contents[44], 140,
                    "incorrect value for contents[44], expected 140, is {}",
                    msg.contents[44]
                );
                assert_eq!(
                    msg.contents[45], 30,
                    "incorrect value for contents[45], expected 30, is {}",
                    msg.contents[45]
                );
                assert_eq!(
                    msg.contents[46], 159,
                    "incorrect value for contents[46], expected 159, is {}",
                    msg.contents[46]
                );
                assert_eq!(
                    msg.contents[47], 70,
                    "incorrect value for contents[47], expected 70, is {}",
                    msg.contents[47]
                );
                assert_eq!(
                    msg.contents[48], 17,
                    "incorrect value for contents[48], expected 17, is {}",
                    msg.contents[48]
                );
                assert_eq!(
                    msg.contents[49], 170,
                    "incorrect value for contents[49], expected 170, is {}",
                    msg.contents[49]
                );
                assert_eq!(
                    msg.contents[50], 50,
                    "incorrect value for contents[50], expected 50, is {}",
                    msg.contents[50]
                );
                assert_eq!(
                    msg.contents[51], 148,
                    "incorrect value for contents[51], expected 148, is {}",
                    msg.contents[51]
                );
                assert_eq!(
                    msg.contents[52], 1,
                    "incorrect value for contents[52], expected 1, is {}",
                    msg.contents[52]
                );
                assert_eq!(
                    msg.contents[53], 99,
                    "incorrect value for contents[53], expected 99, is {}",
                    msg.contents[53]
                );
                assert_eq!(
                    msg.contents[54], 112,
                    "incorrect value for contents[54], expected 112, is {}",
                    msg.contents[54]
                );
                assert_eq!(
                    msg.contents[55], 88,
                    "incorrect value for contents[55], expected 88, is {}",
                    msg.contents[55]
                );
                assert_eq!(
                    msg.contents[56], 217,
                    "incorrect value for contents[56], expected 217, is {}",
                    msg.contents[56]
                );
                assert_eq!(
                    msg.contents[57], 36,
                    "incorrect value for contents[57], expected 36, is {}",
                    msg.contents[57]
                );
                assert_eq!(
                    msg.contents[58], 84,
                    "incorrect value for contents[58], expected 84, is {}",
                    msg.contents[58]
                );
                assert_eq!(
                    msg.contents[59], 34,
                    "incorrect value for contents[59], expected 34, is {}",
                    msg.contents[59]
                );
                assert_eq!(
                    msg.contents[60], 234,
                    "incorrect value for contents[60], expected 234, is {}",
                    msg.contents[60]
                );
                assert_eq!(
                    msg.contents[61], 82,
                    "incorrect value for contents[61], expected 82, is {}",
                    msg.contents[61]
                );
                assert_eq!(
                    msg.contents[62], 144,
                    "incorrect value for contents[62], expected 144, is {}",
                    msg.contents[62]
                );
                assert_eq!(
                    msg.contents[63], 144,
                    "incorrect value for contents[63], expected 144, is {}",
                    msg.contents[63]
                );
                assert_eq!(
                    msg.contents[64], 97,
                    "incorrect value for contents[64], expected 97, is {}",
                    msg.contents[64]
                );
                assert_eq!(
                    msg.contents[65], 96,
                    "incorrect value for contents[65], expected 96, is {}",
                    msg.contents[65]
                );
                assert_eq!(
                    msg.contents[66], 75,
                    "incorrect value for contents[66], expected 75, is {}",
                    msg.contents[66]
                );
                assert_eq!(
                    msg.contents[67], 174,
                    "incorrect value for contents[67], expected 174, is {}",
                    msg.contents[67]
                );
                assert_eq!(
                    msg.contents[68], 58,
                    "incorrect value for contents[68], expected 58, is {}",
                    msg.contents[68]
                );
                assert_eq!(
                    msg.contents[69], 219,
                    "incorrect value for contents[69], expected 219, is {}",
                    msg.contents[69]
                );
                assert_eq!(
                    msg.contents[70], 180,
                    "incorrect value for contents[70], expected 180, is {}",
                    msg.contents[70]
                );
                assert_eq!(
                    msg.contents[71], 148,
                    "incorrect value for contents[71], expected 148, is {}",
                    msg.contents[71]
                );
                assert_eq!(
                    msg.contents[72], 247,
                    "incorrect value for contents[72], expected 247, is {}",
                    msg.contents[72]
                );
                assert_eq!(
                    msg.contents[73], 59,
                    "incorrect value for contents[73], expected 59, is {}",
                    msg.contents[73]
                );
                assert_eq!(
                    msg.contents[74], 2,
                    "incorrect value for contents[74], expected 2, is {}",
                    msg.contents[74]
                );
                assert_eq!(
                    msg.contents[75], 116,
                    "incorrect value for contents[75], expected 116, is {}",
                    msg.contents[75]
                );
                assert_eq!(
                    msg.contents[76], 214,
                    "incorrect value for contents[76], expected 214, is {}",
                    msg.contents[76]
                );
                assert_eq!(
                    msg.contents[77], 114,
                    "incorrect value for contents[77], expected 114, is {}",
                    msg.contents[77]
                );
                assert_eq!(
                    msg.contents[78], 55,
                    "incorrect value for contents[78], expected 55, is {}",
                    msg.contents[78]
                );
                assert_eq!(
                    msg.contents[79], 134,
                    "incorrect value for contents[79], expected 134, is {}",
                    msg.contents[79]
                );
                assert_eq!(
                    msg.contents[80], 54,
                    "incorrect value for contents[80], expected 54, is {}",
                    msg.contents[80]
                );
                assert_eq!(
                    msg.contents[81], 119,
                    "incorrect value for contents[81], expected 119, is {}",
                    msg.contents[81]
                );
                assert_eq!(
                    msg.contents[82], 108,
                    "incorrect value for contents[82], expected 108, is {}",
                    msg.contents[82]
                );
                assert_eq!(
                    msg.contents[83], 128,
                    "incorrect value for contents[83], expected 128, is {}",
                    msg.contents[83]
                );
                assert_eq!(
                    msg.contents[84], 73,
                    "incorrect value for contents[84], expected 73, is {}",
                    msg.contents[84]
                );
                assert_eq!(
                    msg.contents[85], 181,
                    "incorrect value for contents[85], expected 181, is {}",
                    msg.contents[85]
                );
                assert_eq!(
                    msg.contents[86], 20,
                    "incorrect value for contents[86], expected 20, is {}",
                    msg.contents[86]
                );
                assert_eq!(
                    msg.contents[87], 233,
                    "incorrect value for contents[87], expected 233, is {}",
                    msg.contents[87]
                );
                assert_eq!(
                    msg.contents[88], 23,
                    "incorrect value for contents[88], expected 23, is {}",
                    msg.contents[88]
                );
                assert_eq!(
                    msg.contents[89], 23,
                    "incorrect value for contents[89], expected 23, is {}",
                    msg.contents[89]
                );
                assert_eq!(
                    msg.contents[90], 73,
                    "incorrect value for contents[90], expected 73, is {}",
                    msg.contents[90]
                );
                assert_eq!(
                    msg.contents[91], 119,
                    "incorrect value for contents[91], expected 119, is {}",
                    msg.contents[91]
                );
                assert_eq!(
                    msg.contents[92], 136,
                    "incorrect value for contents[92], expected 136, is {}",
                    msg.contents[92]
                );
                assert_eq!(
                    msg.contents[93], 231,
                    "incorrect value for contents[93], expected 231, is {}",
                    msg.contents[93]
                );
                assert_eq!(
                    msg.contents[94], 189,
                    "incorrect value for contents[94], expected 189, is {}",
                    msg.contents[94]
                );
                assert_eq!(
                    msg.contents[95], 26,
                    "incorrect value for contents[95], expected 26, is {}",
                    msg.contents[95]
                );
                assert_eq!(
                    msg.contents[96], 174,
                    "incorrect value for contents[96], expected 174, is {}",
                    msg.contents[96]
                );
                assert_eq!(
                    msg.contents[97], 128,
                    "incorrect value for contents[97], expected 128, is {}",
                    msg.contents[97]
                );
                assert_eq!(
                    msg.contents[98], 93,
                    "incorrect value for contents[98], expected 93, is {}",
                    msg.contents[98]
                );
                assert_eq!(
                    msg.contents[99], 30,
                    "incorrect value for contents[99], expected 30, is {}",
                    msg.contents[99]
                );
                assert_eq!(
                    msg.contents[100], 76,
                    "incorrect value for contents[100], expected 76, is {}",
                    msg.contents[100]
                );
                assert_eq!(
                    msg.contents[101], 45,
                    "incorrect value for contents[101], expected 45, is {}",
                    msg.contents[101]
                );
                assert_eq!(
                    msg.contents[102], 109,
                    "incorrect value for contents[102], expected 109, is {}",
                    msg.contents[102]
                );
                assert_eq!(
                    msg.contents[103], 134,
                    "incorrect value for contents[103], expected 134, is {}",
                    msg.contents[103]
                );
                assert_eq!(
                    msg.contents[104], 81,
                    "incorrect value for contents[104], expected 81, is {}",
                    msg.contents[104]
                );
                assert_eq!(
                    msg.contents[105], 0,
                    "incorrect value for contents[105], expected 0, is {}",
                    msg.contents[105]
                );
                assert_eq!(
                    msg.contents[106], 116,
                    "incorrect value for contents[106], expected 116, is {}",
                    msg.contents[106]
                );
                assert_eq!(
                    msg.contents[107], 158,
                    "incorrect value for contents[107], expected 158, is {}",
                    msg.contents[107]
                );
                assert_eq!(
                    msg.contents[108], 127,
                    "incorrect value for contents[108], expected 127, is {}",
                    msg.contents[108]
                );
                assert_eq!(
                    msg.contents[109], 40,
                    "incorrect value for contents[109], expected 40, is {}",
                    msg.contents[109]
                );
                assert_eq!(
                    msg.contents[110], 133,
                    "incorrect value for contents[110], expected 133, is {}",
                    msg.contents[110]
                );
                assert_eq!(
                    msg.contents[111], 208,
                    "incorrect value for contents[111], expected 208, is {}",
                    msg.contents[111]
                );
                assert_eq!(
                    msg.contents[112], 134,
                    "incorrect value for contents[112], expected 134, is {}",
                    msg.contents[112]
                );
                assert_eq!(
                    msg.contents[113], 127,
                    "incorrect value for contents[113], expected 127, is {}",
                    msg.contents[113]
                );
                assert_eq!(
                    msg.contents[114], 140,
                    "incorrect value for contents[114], expected 140, is {}",
                    msg.contents[114]
                );
                assert_eq!(
                    msg.contents[115], 232,
                    "incorrect value for contents[115], expected 232, is {}",
                    msg.contents[115]
                );
                assert_eq!(
                    msg.contents[116], 183,
                    "incorrect value for contents[116], expected 183, is {}",
                    msg.contents[116]
                );
                assert_eq!(
                    msg.contents[117], 184,
                    "incorrect value for contents[117], expected 184, is {}",
                    msg.contents[117]
                );
                assert_eq!(
                    msg.contents[118], 108,
                    "incorrect value for contents[118], expected 108, is {}",
                    msg.contents[118]
                );
                assert_eq!(
                    msg.contents[119], 6,
                    "incorrect value for contents[119], expected 6, is {}",
                    msg.contents[119]
                );
                assert_eq!(
                    msg.contents[120], 228,
                    "incorrect value for contents[120], expected 228, is {}",
                    msg.contents[120]
                );
                assert_eq!(
                    msg.contents[121], 54,
                    "incorrect value for contents[121], expected 54, is {}",
                    msg.contents[121]
                );
                assert_eq!(
                    msg.contents[122], 238,
                    "incorrect value for contents[122], expected 238, is {}",
                    msg.contents[122]
                );
                assert_eq!(
                    msg.contents[123], 59,
                    "incorrect value for contents[123], expected 59, is {}",
                    msg.contents[123]
                );
                assert_eq!(
                    msg.contents[124], 220,
                    "incorrect value for contents[124], expected 220, is {}",
                    msg.contents[124]
                );
                assert_eq!(
                    msg.contents[125], 30,
                    "incorrect value for contents[125], expected 30, is {}",
                    msg.contents[125]
                );
                assert_eq!(
                    msg.contents[126], 228,
                    "incorrect value for contents[126], expected 228, is {}",
                    msg.contents[126]
                );
                assert_eq!(
                    msg.contents[127], 212,
                    "incorrect value for contents[127], expected 212, is {}",
                    msg.contents[127]
                );
                assert_eq!(
                    msg.contents[128], 50,
                    "incorrect value for contents[128], expected 50, is {}",
                    msg.contents[128]
                );
                assert_eq!(
                    msg.contents[129], 182,
                    "incorrect value for contents[129], expected 182, is {}",
                    msg.contents[129]
                );
                assert_eq!(
                    msg.contents[130], 97,
                    "incorrect value for contents[130], expected 97, is {}",
                    msg.contents[130]
                );
                assert_eq!(
                    msg.contents[131], 20,
                    "incorrect value for contents[131], expected 20, is {}",
                    msg.contents[131]
                );
                assert_eq!(
                    msg.contents[132], 41,
                    "incorrect value for contents[132], expected 41, is {}",
                    msg.contents[132]
                );
                assert_eq!(
                    msg.contents[133], 76,
                    "incorrect value for contents[133], expected 76, is {}",
                    msg.contents[133]
                );
                assert_eq!(
                    msg.contents[134], 227,
                    "incorrect value for contents[134], expected 227, is {}",
                    msg.contents[134]
                );
                assert_eq!(
                    msg.contents[135], 88,
                    "incorrect value for contents[135], expected 88, is {}",
                    msg.contents[135]
                );
                assert_eq!(
                    msg.contents[136], 12,
                    "incorrect value for contents[136], expected 12, is {}",
                    msg.contents[136]
                );
                assert_eq!(
                    msg.contents[137], 95,
                    "incorrect value for contents[137], expected 95, is {}",
                    msg.contents[137]
                );
                assert_eq!(
                    msg.contents[138], 112,
                    "incorrect value for contents[138], expected 112, is {}",
                    msg.contents[138]
                );
                assert_eq!(
                    msg.contents[139], 209,
                    "incorrect value for contents[139], expected 209, is {}",
                    msg.contents[139]
                );
                assert_eq!(
                    msg.contents[140], 183,
                    "incorrect value for contents[140], expected 183, is {}",
                    msg.contents[140]
                );
                assert_eq!(
                    msg.contents[141], 127,
                    "incorrect value for contents[141], expected 127, is {}",
                    msg.contents[141]
                );
                assert_eq!(
                    msg.contents[142], 4,
                    "incorrect value for contents[142], expected 4, is {}",
                    msg.contents[142]
                );
                assert_eq!(
                    msg.contents[143], 165,
                    "incorrect value for contents[143], expected 165, is {}",
                    msg.contents[143]
                );
                assert_eq!(
                    msg.contents[144], 189,
                    "incorrect value for contents[144], expected 189, is {}",
                    msg.contents[144]
                );
                assert_eq!(
                    msg.contents[145], 44,
                    "incorrect value for contents[145], expected 44, is {}",
                    msg.contents[145]
                );
                assert_eq!(
                    msg.contents[146], 239,
                    "incorrect value for contents[146], expected 239, is {}",
                    msg.contents[146]
                );
                assert_eq!(
                    msg.contents[147], 232,
                    "incorrect value for contents[147], expected 232, is {}",
                    msg.contents[147]
                );
                assert_eq!(
                    msg.contents[148], 132,
                    "incorrect value for contents[148], expected 132, is {}",
                    msg.contents[148]
                );
                assert_eq!(
                    msg.contents[149], 9,
                    "incorrect value for contents[149], expected 9, is {}",
                    msg.contents[149]
                );
                assert_eq!(
                    msg.contents[150], 114,
                    "incorrect value for contents[150], expected 114, is {}",
                    msg.contents[150]
                );
                assert_eq!(
                    msg.contents[151], 184,
                    "incorrect value for contents[151], expected 184, is {}",
                    msg.contents[151]
                );
                assert_eq!(
                    msg.contents[152], 249,
                    "incorrect value for contents[152], expected 249, is {}",
                    msg.contents[152]
                );
                assert_eq!(
                    msg.contents[153], 208,
                    "incorrect value for contents[153], expected 208, is {}",
                    msg.contents[153]
                );
                assert_eq!(
                    msg.contents[154], 246,
                    "incorrect value for contents[154], expected 246, is {}",
                    msg.contents[154]
                );
                assert_eq!(
                    msg.contents[155], 194,
                    "incorrect value for contents[155], expected 194, is {}",
                    msg.contents[155]
                );
                assert_eq!(
                    msg.contents[156], 250,
                    "incorrect value for contents[156], expected 250, is {}",
                    msg.contents[156]
                );
                assert_eq!(
                    msg.contents[157], 2,
                    "incorrect value for contents[157], expected 2, is {}",
                    msg.contents[157]
                );
                assert_eq!(
                    msg.contents[158], 97,
                    "incorrect value for contents[158], expected 97, is {}",
                    msg.contents[158]
                );
                assert_eq!(
                    msg.contents[159], 173,
                    "incorrect value for contents[159], expected 173, is {}",
                    msg.contents[159]
                );
                assert_eq!(
                    msg.contents[160], 157,
                    "incorrect value for contents[160], expected 157, is {}",
                    msg.contents[160]
                );
                assert_eq!(
                    msg.contents[161], 202,
                    "incorrect value for contents[161], expected 202, is {}",
                    msg.contents[161]
                );
                assert_eq!(
                    msg.contents[162], 172,
                    "incorrect value for contents[162], expected 172, is {}",
                    msg.contents[162]
                );
                assert_eq!(
                    msg.contents[163], 180,
                    "incorrect value for contents[163], expected 180, is {}",
                    msg.contents[163]
                );
                assert_eq!(
                    msg.contents[164], 150,
                    "incorrect value for contents[164], expected 150, is {}",
                    msg.contents[164]
                );
                assert_eq!(
                    msg.contents[165], 213,
                    "incorrect value for contents[165], expected 213, is {}",
                    msg.contents[165]
                );
                assert_eq!(
                    msg.contents[166], 193,
                    "incorrect value for contents[166], expected 193, is {}",
                    msg.contents[166]
                );
                assert_eq!(
                    msg.contents[167], 177,
                    "incorrect value for contents[167], expected 177, is {}",
                    msg.contents[167]
                );
                assert_eq!(
                    msg.contents[168], 209,
                    "incorrect value for contents[168], expected 209, is {}",
                    msg.contents[168]
                );
                assert_eq!(
                    msg.contents[169], 156,
                    "incorrect value for contents[169], expected 156, is {}",
                    msg.contents[169]
                );
                assert_eq!(
                    msg.contents[170], 20,
                    "incorrect value for contents[170], expected 20, is {}",
                    msg.contents[170]
                );
                assert_eq!(
                    msg.contents[171], 174,
                    "incorrect value for contents[171], expected 174, is {}",
                    msg.contents[171]
                );
                assert_eq!(
                    msg.contents[172], 18,
                    "incorrect value for contents[172], expected 18, is {}",
                    msg.contents[172]
                );
                assert_eq!(
                    msg.contents[173], 73,
                    "incorrect value for contents[173], expected 73, is {}",
                    msg.contents[173]
                );
                assert_eq!(
                    msg.contents[174], 132,
                    "incorrect value for contents[174], expected 132, is {}",
                    msg.contents[174]
                );
                assert_eq!(
                    msg.contents[175], 215,
                    "incorrect value for contents[175], expected 215, is {}",
                    msg.contents[175]
                );
                assert_eq!(
                    msg.contents[176], 115,
                    "incorrect value for contents[176], expected 115, is {}",
                    msg.contents[176]
                );
                assert_eq!(
                    msg.contents[177], 128,
                    "incorrect value for contents[177], expected 128, is {}",
                    msg.contents[177]
                );
                assert_eq!(
                    msg.contents[178], 175,
                    "incorrect value for contents[178], expected 175, is {}",
                    msg.contents[178]
                );
                assert_eq!(
                    msg.contents[179], 169,
                    "incorrect value for contents[179], expected 169, is {}",
                    msg.contents[179]
                );
                assert_eq!(
                    msg.contents[180], 116,
                    "incorrect value for contents[180], expected 116, is {}",
                    msg.contents[180]
                );
                assert_eq!(
                    msg.contents[181], 132,
                    "incorrect value for contents[181], expected 132, is {}",
                    msg.contents[181]
                );
                assert_eq!(
                    msg.contents[182], 100,
                    "incorrect value for contents[182], expected 100, is {}",
                    msg.contents[182]
                );
                assert_eq!(
                    msg.contents[183], 72,
                    "incorrect value for contents[183], expected 72, is {}",
                    msg.contents[183]
                );
                assert_eq!(
                    msg.contents[184], 45,
                    "incorrect value for contents[184], expected 45, is {}",
                    msg.contents[184]
                );
                assert_eq!(
                    msg.contents[185], 25,
                    "incorrect value for contents[185], expected 25, is {}",
                    msg.contents[185]
                );
                assert_eq!(
                    msg.contents[186], 14,
                    "incorrect value for contents[186], expected 14, is {}",
                    msg.contents[186]
                );
                assert_eq!(
                    msg.contents[187], 205,
                    "incorrect value for contents[187], expected 205, is {}",
                    msg.contents[187]
                );
                assert_eq!(
                    msg.contents[188], 213,
                    "incorrect value for contents[188], expected 213, is {}",
                    msg.contents[188]
                );
                assert_eq!(
                    msg.contents[189], 145,
                    "incorrect value for contents[189], expected 145, is {}",
                    msg.contents[189]
                );
                assert_eq!(
                    msg.contents[190], 68,
                    "incorrect value for contents[190], expected 68, is {}",
                    msg.contents[190]
                );
                assert_eq!(
                    msg.contents[191], 137,
                    "incorrect value for contents[191], expected 137, is {}",
                    msg.contents[191]
                );
                assert_eq!(
                    msg.contents[192], 249,
                    "incorrect value for contents[192], expected 249, is {}",
                    msg.contents[192]
                );
                assert_eq!(
                    msg.contents[193], 54,
                    "incorrect value for contents[193], expected 54, is {}",
                    msg.contents[193]
                );
                assert_eq!(
                    msg.contents[194], 40,
                    "incorrect value for contents[194], expected 40, is {}",
                    msg.contents[194]
                );
                assert_eq!(
                    msg.contents[195], 174,
                    "incorrect value for contents[195], expected 174, is {}",
                    msg.contents[195]
                );
                assert_eq!(
                    msg.contents[196], 215,
                    "incorrect value for contents[196], expected 215, is {}",
                    msg.contents[196]
                );
                assert_eq!(
                    msg.contents[197], 148,
                    "incorrect value for contents[197], expected 148, is {}",
                    msg.contents[197]
                );
                assert_eq!(
                    msg.contents[198], 166,
                    "incorrect value for contents[198], expected 166, is {}",
                    msg.contents[198]
                );
                assert_eq!(
                    msg.contents[199], 190,
                    "incorrect value for contents[199], expected 190, is {}",
                    msg.contents[199]
                );
                assert_eq!(
                    msg.contents[200], 63,
                    "incorrect value for contents[200], expected 63, is {}",
                    msg.contents[200]
                );
                assert_eq!(
                    msg.contents[201], 118,
                    "incorrect value for contents[201], expected 118, is {}",
                    msg.contents[201]
                );
                assert_eq!(
                    msg.contents[202], 6,
                    "incorrect value for contents[202], expected 6, is {}",
                    msg.contents[202]
                );
                assert_eq!(
                    msg.contents[203], 165,
                    "incorrect value for contents[203], expected 165, is {}",
                    msg.contents[203]
                );
                assert_eq!(
                    msg.contents[204], 212,
                    "incorrect value for contents[204], expected 212, is {}",
                    msg.contents[204]
                );
                assert_eq!(
                    msg.contents[205], 74,
                    "incorrect value for contents[205], expected 74, is {}",
                    msg.contents[205]
                );
                assert_eq!(
                    msg.contents[206], 68,
                    "incorrect value for contents[206], expected 68, is {}",
                    msg.contents[206]
                );
                assert_eq!(
                    msg.contents[207], 200,
                    "incorrect value for contents[207], expected 200, is {}",
                    msg.contents[207]
                );
                assert_eq!(
                    msg.contents[208], 38,
                    "incorrect value for contents[208], expected 38, is {}",
                    msg.contents[208]
                );
                assert_eq!(
                    msg.contents[209], 139,
                    "incorrect value for contents[209], expected 139, is {}",
                    msg.contents[209]
                );
                assert_eq!(
                    msg.contents[210], 212,
                    "incorrect value for contents[210], expected 212, is {}",
                    msg.contents[210]
                );
                assert_eq!(
                    msg.contents[211], 112,
                    "incorrect value for contents[211], expected 112, is {}",
                    msg.contents[211]
                );
                assert_eq!(
                    msg.contents[212], 45,
                    "incorrect value for contents[212], expected 45, is {}",
                    msg.contents[212]
                );
                assert_eq!(
                    msg.contents[213], 167,
                    "incorrect value for contents[213], expected 167, is {}",
                    msg.contents[213]
                );
                assert_eq!(
                    msg.contents[214], 236,
                    "incorrect value for contents[214], expected 236, is {}",
                    msg.contents[214]
                );
                assert_eq!(
                    msg.contents[215], 255,
                    "incorrect value for contents[215], expected 255, is {}",
                    msg.contents[215]
                );
                assert_eq!(
                    msg.contents[216], 106,
                    "incorrect value for contents[216], expected 106, is {}",
                    msg.contents[216]
                );
                assert_eq!(
                    msg.contents[217], 92,
                    "incorrect value for contents[217], expected 92, is {}",
                    msg.contents[217]
                );
                assert_eq!(
                    msg.contents[218], 132,
                    "incorrect value for contents[218], expected 132, is {}",
                    msg.contents[218]
                );
                assert_eq!(
                    msg.contents[219], 59,
                    "incorrect value for contents[219], expected 59, is {}",
                    msg.contents[219]
                );
                assert_eq!(
                    msg.contents[220], 61,
                    "incorrect value for contents[220], expected 61, is {}",
                    msg.contents[220]
                );
                assert_eq!(
                    msg.contents[221], 233,
                    "incorrect value for contents[221], expected 233, is {}",
                    msg.contents[221]
                );
                assert_eq!(
                    msg.contents[222], 3,
                    "incorrect value for contents[222], expected 3, is {}",
                    msg.contents[222]
                );
                assert_eq!(
                    msg.contents[223], 246,
                    "incorrect value for contents[223], expected 246, is {}",
                    msg.contents[223]
                );
                assert_eq!(
                    msg.contents[224], 158,
                    "incorrect value for contents[224], expected 158, is {}",
                    msg.contents[224]
                );
                assert_eq!(
                    msg.contents[225], 83,
                    "incorrect value for contents[225], expected 83, is {}",
                    msg.contents[225]
                );
                assert_eq!(
                    msg.contents[226], 134,
                    "incorrect value for contents[226], expected 134, is {}",
                    msg.contents[226]
                );
                assert_eq!(
                    msg.contents[227], 246,
                    "incorrect value for contents[227], expected 246, is {}",
                    msg.contents[227]
                );
                assert_eq!(
                    msg.contents[228], 154,
                    "incorrect value for contents[228], expected 154, is {}",
                    msg.contents[228]
                );
                assert_eq!(
                    msg.contents[229], 17,
                    "incorrect value for contents[229], expected 17, is {}",
                    msg.contents[229]
                );
                assert_eq!(
                    msg.contents[230], 0,
                    "incorrect value for contents[230], expected 0, is {}",
                    msg.contents[230]
                );
                assert_eq!(
                    msg.contents[231], 6,
                    "incorrect value for contents[231], expected 6, is {}",
                    msg.contents[231]
                );
                assert_eq!(
                    msg.contents[232], 56,
                    "incorrect value for contents[232], expected 56, is {}",
                    msg.contents[232]
                );
                assert_eq!(
                    msg.contents[233], 216,
                    "incorrect value for contents[233], expected 216, is {}",
                    msg.contents[233]
                );
                assert_eq!(
                    msg.contents[234], 19,
                    "incorrect value for contents[234], expected 19, is {}",
                    msg.contents[234]
                );
                assert_eq!(
                    msg.contents[235], 216,
                    "incorrect value for contents[235], expected 216, is {}",
                    msg.contents[235]
                );
                assert_eq!(
                    msg.contents[236], 70,
                    "incorrect value for contents[236], expected 70, is {}",
                    msg.contents[236]
                );
                assert_eq!(
                    msg.contents[237], 71,
                    "incorrect value for contents[237], expected 71, is {}",
                    msg.contents[237]
                );
                assert_eq!(
                    msg.contents[238], 161,
                    "incorrect value for contents[238], expected 161, is {}",
                    msg.contents[238]
                );
                assert_eq!(
                    msg.contents[239], 184,
                    "incorrect value for contents[239], expected 184, is {}",
                    msg.contents[239]
                );
                assert_eq!(
                    msg.contents[240], 5,
                    "incorrect value for contents[240], expected 5, is {}",
                    msg.contents[240]
                );
                assert_eq!(
                    msg.contents[241], 177,
                    "incorrect value for contents[241], expected 177, is {}",
                    msg.contents[241]
                );
                assert_eq!(
                    msg.contents[242], 45,
                    "incorrect value for contents[242], expected 45, is {}",
                    msg.contents[242]
                );
                assert_eq!(
                    msg.contents[243], 37,
                    "incorrect value for contents[243], expected 37, is {}",
                    msg.contents[243]
                );
                assert_eq!(
                    msg.contents[244], 98,
                    "incorrect value for contents[244], expected 98, is {}",
                    msg.contents[244]
                );
                assert_eq!(
                    msg.contents[245], 56,
                    "incorrect value for contents[245], expected 56, is {}",
                    msg.contents[245]
                );
                assert_eq!(
                    msg.contents[246], 149,
                    "incorrect value for contents[246], expected 149, is {}",
                    msg.contents[246]
                );
                assert_eq!(
                    msg.contents[247], 0,
                    "incorrect value for contents[247], expected 0, is {}",
                    msg.contents[247]
                );
                assert_eq!(
                    msg.contents[248], 73,
                    "incorrect value for contents[248], expected 73, is {}",
                    msg.contents[248]
                );
                assert_eq!(
                    msg.contents[249], 221,
                    "incorrect value for contents[249], expected 221, is {}",
                    msg.contents[249]
                );
                assert_eq!(
                    msg.contents[250], 105,
                    "incorrect value for contents[250], expected 105, is {}",
                    msg.contents[250]
                );
                assert_eq!(
                    msg.contents[251], 239,
                    "incorrect value for contents[251], expected 239, is {}",
                    msg.contents[251]
                );
                assert_eq!(
                    msg.contents[252], 168,
                    "incorrect value for contents[252], expected 168, is {}",
                    msg.contents[252]
                );
                assert_eq!(
                    msg.contents[253], 205,
                    "incorrect value for contents[253], expected 205, is {}",
                    msg.contents[253]
                );
                assert_eq!(
                    msg.contents[254], 85,
                    "incorrect value for contents[254], expected 85, is {}",
                    msg.contents[254]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgUserData"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_user_msg_user_data`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_user_msg_user_data() {
    {
        let mut payload = Cursor::new(vec![
            85, 0, 8, 126, 33, 255, 53, 5, 172, 138, 50, 49, 206, 234, 149, 204, 113, 31, 108, 188,
            179, 154, 156, 167, 145, 139, 42, 207, 126, 242, 193, 9, 58, 75, 8, 135, 11, 92, 131,
            245, 24, 90, 255, 30, 58, 31, 109, 148, 56, 178, 140, 30, 159, 70, 17, 170, 50, 148, 1,
            99, 112, 88, 217, 36, 84, 34, 234, 82, 144, 144, 97, 96, 75, 174, 58, 219, 180, 148,
            247, 59, 2, 116, 214, 114, 55, 134, 54, 119, 108, 128, 73, 181, 20, 233, 23, 23, 73,
            119, 136, 231, 189, 26, 174, 128, 93, 30, 76, 45, 109, 134, 81, 0, 116, 158, 127, 40,
            133, 208, 134, 127, 140, 232, 183, 184, 108, 6, 228, 54, 238, 59, 220, 30, 228, 212,
            50, 182, 97, 20, 41, 76, 227, 88, 12, 95, 112, 209, 183, 127, 4, 165, 189, 44, 239,
            232, 132, 9, 114, 184, 249, 208, 246, 194, 250, 2, 97, 173, 157, 202, 172, 180, 150,
            213, 193, 177, 209, 156, 20, 174, 18, 73, 132, 215, 115, 128, 175, 169, 116, 132, 100,
            72, 45, 25, 14, 205, 213, 145, 68, 137, 249, 54, 40, 174, 215, 148, 166, 190, 63, 118,
            6, 165, 212, 74, 68, 200, 38, 139, 212, 112, 45, 167, 236, 255, 106, 92, 132, 59, 61,
            233, 3, 246, 158, 83, 134, 246, 154, 17, 0, 6, 56, 216, 19, 216, 70, 71, 161, 184, 5,
            177, 45, 37, 98, 56, 149, 0, 73, 221, 105, 239, 168, 205, 85, 81, 245,
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
        let sbp_msg = sbp::messages::Sbp::MsgUserData(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgUserData(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x800,
                    "Incorrect message type, expected 0x800, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x217e,
                    "incorrect sender id, expected 0x217e, is {sender_id}"
                );
                assert_eq!(
                    msg.contents[0], 53,
                    "incorrect value for contents[0], expected 53, is {}",
                    msg.contents[0]
                );
                assert_eq!(
                    msg.contents[1], 5,
                    "incorrect value for contents[1], expected 5, is {}",
                    msg.contents[1]
                );
                assert_eq!(
                    msg.contents[2], 172,
                    "incorrect value for contents[2], expected 172, is {}",
                    msg.contents[2]
                );
                assert_eq!(
                    msg.contents[3], 138,
                    "incorrect value for contents[3], expected 138, is {}",
                    msg.contents[3]
                );
                assert_eq!(
                    msg.contents[4], 50,
                    "incorrect value for contents[4], expected 50, is {}",
                    msg.contents[4]
                );
                assert_eq!(
                    msg.contents[5], 49,
                    "incorrect value for contents[5], expected 49, is {}",
                    msg.contents[5]
                );
                assert_eq!(
                    msg.contents[6], 206,
                    "incorrect value for contents[6], expected 206, is {}",
                    msg.contents[6]
                );
                assert_eq!(
                    msg.contents[7], 234,
                    "incorrect value for contents[7], expected 234, is {}",
                    msg.contents[7]
                );
                assert_eq!(
                    msg.contents[8], 149,
                    "incorrect value for contents[8], expected 149, is {}",
                    msg.contents[8]
                );
                assert_eq!(
                    msg.contents[9], 204,
                    "incorrect value for contents[9], expected 204, is {}",
                    msg.contents[9]
                );
                assert_eq!(
                    msg.contents[10], 113,
                    "incorrect value for contents[10], expected 113, is {}",
                    msg.contents[10]
                );
                assert_eq!(
                    msg.contents[11], 31,
                    "incorrect value for contents[11], expected 31, is {}",
                    msg.contents[11]
                );
                assert_eq!(
                    msg.contents[12], 108,
                    "incorrect value for contents[12], expected 108, is {}",
                    msg.contents[12]
                );
                assert_eq!(
                    msg.contents[13], 188,
                    "incorrect value for contents[13], expected 188, is {}",
                    msg.contents[13]
                );
                assert_eq!(
                    msg.contents[14], 179,
                    "incorrect value for contents[14], expected 179, is {}",
                    msg.contents[14]
                );
                assert_eq!(
                    msg.contents[15], 154,
                    "incorrect value for contents[15], expected 154, is {}",
                    msg.contents[15]
                );
                assert_eq!(
                    msg.contents[16], 156,
                    "incorrect value for contents[16], expected 156, is {}",
                    msg.contents[16]
                );
                assert_eq!(
                    msg.contents[17], 167,
                    "incorrect value for contents[17], expected 167, is {}",
                    msg.contents[17]
                );
                assert_eq!(
                    msg.contents[18], 145,
                    "incorrect value for contents[18], expected 145, is {}",
                    msg.contents[18]
                );
                assert_eq!(
                    msg.contents[19], 139,
                    "incorrect value for contents[19], expected 139, is {}",
                    msg.contents[19]
                );
                assert_eq!(
                    msg.contents[20], 42,
                    "incorrect value for contents[20], expected 42, is {}",
                    msg.contents[20]
                );
                assert_eq!(
                    msg.contents[21], 207,
                    "incorrect value for contents[21], expected 207, is {}",
                    msg.contents[21]
                );
                assert_eq!(
                    msg.contents[22], 126,
                    "incorrect value for contents[22], expected 126, is {}",
                    msg.contents[22]
                );
                assert_eq!(
                    msg.contents[23], 242,
                    "incorrect value for contents[23], expected 242, is {}",
                    msg.contents[23]
                );
                assert_eq!(
                    msg.contents[24], 193,
                    "incorrect value for contents[24], expected 193, is {}",
                    msg.contents[24]
                );
                assert_eq!(
                    msg.contents[25], 9,
                    "incorrect value for contents[25], expected 9, is {}",
                    msg.contents[25]
                );
                assert_eq!(
                    msg.contents[26], 58,
                    "incorrect value for contents[26], expected 58, is {}",
                    msg.contents[26]
                );
                assert_eq!(
                    msg.contents[27], 75,
                    "incorrect value for contents[27], expected 75, is {}",
                    msg.contents[27]
                );
                assert_eq!(
                    msg.contents[28], 8,
                    "incorrect value for contents[28], expected 8, is {}",
                    msg.contents[28]
                );
                assert_eq!(
                    msg.contents[29], 135,
                    "incorrect value for contents[29], expected 135, is {}",
                    msg.contents[29]
                );
                assert_eq!(
                    msg.contents[30], 11,
                    "incorrect value for contents[30], expected 11, is {}",
                    msg.contents[30]
                );
                assert_eq!(
                    msg.contents[31], 92,
                    "incorrect value for contents[31], expected 92, is {}",
                    msg.contents[31]
                );
                assert_eq!(
                    msg.contents[32], 131,
                    "incorrect value for contents[32], expected 131, is {}",
                    msg.contents[32]
                );
                assert_eq!(
                    msg.contents[33], 245,
                    "incorrect value for contents[33], expected 245, is {}",
                    msg.contents[33]
                );
                assert_eq!(
                    msg.contents[34], 24,
                    "incorrect value for contents[34], expected 24, is {}",
                    msg.contents[34]
                );
                assert_eq!(
                    msg.contents[35], 90,
                    "incorrect value for contents[35], expected 90, is {}",
                    msg.contents[35]
                );
                assert_eq!(
                    msg.contents[36], 255,
                    "incorrect value for contents[36], expected 255, is {}",
                    msg.contents[36]
                );
                assert_eq!(
                    msg.contents[37], 30,
                    "incorrect value for contents[37], expected 30, is {}",
                    msg.contents[37]
                );
                assert_eq!(
                    msg.contents[38], 58,
                    "incorrect value for contents[38], expected 58, is {}",
                    msg.contents[38]
                );
                assert_eq!(
                    msg.contents[39], 31,
                    "incorrect value for contents[39], expected 31, is {}",
                    msg.contents[39]
                );
                assert_eq!(
                    msg.contents[40], 109,
                    "incorrect value for contents[40], expected 109, is {}",
                    msg.contents[40]
                );
                assert_eq!(
                    msg.contents[41], 148,
                    "incorrect value for contents[41], expected 148, is {}",
                    msg.contents[41]
                );
                assert_eq!(
                    msg.contents[42], 56,
                    "incorrect value for contents[42], expected 56, is {}",
                    msg.contents[42]
                );
                assert_eq!(
                    msg.contents[43], 178,
                    "incorrect value for contents[43], expected 178, is {}",
                    msg.contents[43]
                );
                assert_eq!(
                    msg.contents[44], 140,
                    "incorrect value for contents[44], expected 140, is {}",
                    msg.contents[44]
                );
                assert_eq!(
                    msg.contents[45], 30,
                    "incorrect value for contents[45], expected 30, is {}",
                    msg.contents[45]
                );
                assert_eq!(
                    msg.contents[46], 159,
                    "incorrect value for contents[46], expected 159, is {}",
                    msg.contents[46]
                );
                assert_eq!(
                    msg.contents[47], 70,
                    "incorrect value for contents[47], expected 70, is {}",
                    msg.contents[47]
                );
                assert_eq!(
                    msg.contents[48], 17,
                    "incorrect value for contents[48], expected 17, is {}",
                    msg.contents[48]
                );
                assert_eq!(
                    msg.contents[49], 170,
                    "incorrect value for contents[49], expected 170, is {}",
                    msg.contents[49]
                );
                assert_eq!(
                    msg.contents[50], 50,
                    "incorrect value for contents[50], expected 50, is {}",
                    msg.contents[50]
                );
                assert_eq!(
                    msg.contents[51], 148,
                    "incorrect value for contents[51], expected 148, is {}",
                    msg.contents[51]
                );
                assert_eq!(
                    msg.contents[52], 1,
                    "incorrect value for contents[52], expected 1, is {}",
                    msg.contents[52]
                );
                assert_eq!(
                    msg.contents[53], 99,
                    "incorrect value for contents[53], expected 99, is {}",
                    msg.contents[53]
                );
                assert_eq!(
                    msg.contents[54], 112,
                    "incorrect value for contents[54], expected 112, is {}",
                    msg.contents[54]
                );
                assert_eq!(
                    msg.contents[55], 88,
                    "incorrect value for contents[55], expected 88, is {}",
                    msg.contents[55]
                );
                assert_eq!(
                    msg.contents[56], 217,
                    "incorrect value for contents[56], expected 217, is {}",
                    msg.contents[56]
                );
                assert_eq!(
                    msg.contents[57], 36,
                    "incorrect value for contents[57], expected 36, is {}",
                    msg.contents[57]
                );
                assert_eq!(
                    msg.contents[58], 84,
                    "incorrect value for contents[58], expected 84, is {}",
                    msg.contents[58]
                );
                assert_eq!(
                    msg.contents[59], 34,
                    "incorrect value for contents[59], expected 34, is {}",
                    msg.contents[59]
                );
                assert_eq!(
                    msg.contents[60], 234,
                    "incorrect value for contents[60], expected 234, is {}",
                    msg.contents[60]
                );
                assert_eq!(
                    msg.contents[61], 82,
                    "incorrect value for contents[61], expected 82, is {}",
                    msg.contents[61]
                );
                assert_eq!(
                    msg.contents[62], 144,
                    "incorrect value for contents[62], expected 144, is {}",
                    msg.contents[62]
                );
                assert_eq!(
                    msg.contents[63], 144,
                    "incorrect value for contents[63], expected 144, is {}",
                    msg.contents[63]
                );
                assert_eq!(
                    msg.contents[64], 97,
                    "incorrect value for contents[64], expected 97, is {}",
                    msg.contents[64]
                );
                assert_eq!(
                    msg.contents[65], 96,
                    "incorrect value for contents[65], expected 96, is {}",
                    msg.contents[65]
                );
                assert_eq!(
                    msg.contents[66], 75,
                    "incorrect value for contents[66], expected 75, is {}",
                    msg.contents[66]
                );
                assert_eq!(
                    msg.contents[67], 174,
                    "incorrect value for contents[67], expected 174, is {}",
                    msg.contents[67]
                );
                assert_eq!(
                    msg.contents[68], 58,
                    "incorrect value for contents[68], expected 58, is {}",
                    msg.contents[68]
                );
                assert_eq!(
                    msg.contents[69], 219,
                    "incorrect value for contents[69], expected 219, is {}",
                    msg.contents[69]
                );
                assert_eq!(
                    msg.contents[70], 180,
                    "incorrect value for contents[70], expected 180, is {}",
                    msg.contents[70]
                );
                assert_eq!(
                    msg.contents[71], 148,
                    "incorrect value for contents[71], expected 148, is {}",
                    msg.contents[71]
                );
                assert_eq!(
                    msg.contents[72], 247,
                    "incorrect value for contents[72], expected 247, is {}",
                    msg.contents[72]
                );
                assert_eq!(
                    msg.contents[73], 59,
                    "incorrect value for contents[73], expected 59, is {}",
                    msg.contents[73]
                );
                assert_eq!(
                    msg.contents[74], 2,
                    "incorrect value for contents[74], expected 2, is {}",
                    msg.contents[74]
                );
                assert_eq!(
                    msg.contents[75], 116,
                    "incorrect value for contents[75], expected 116, is {}",
                    msg.contents[75]
                );
                assert_eq!(
                    msg.contents[76], 214,
                    "incorrect value for contents[76], expected 214, is {}",
                    msg.contents[76]
                );
                assert_eq!(
                    msg.contents[77], 114,
                    "incorrect value for contents[77], expected 114, is {}",
                    msg.contents[77]
                );
                assert_eq!(
                    msg.contents[78], 55,
                    "incorrect value for contents[78], expected 55, is {}",
                    msg.contents[78]
                );
                assert_eq!(
                    msg.contents[79], 134,
                    "incorrect value for contents[79], expected 134, is {}",
                    msg.contents[79]
                );
                assert_eq!(
                    msg.contents[80], 54,
                    "incorrect value for contents[80], expected 54, is {}",
                    msg.contents[80]
                );
                assert_eq!(
                    msg.contents[81], 119,
                    "incorrect value for contents[81], expected 119, is {}",
                    msg.contents[81]
                );
                assert_eq!(
                    msg.contents[82], 108,
                    "incorrect value for contents[82], expected 108, is {}",
                    msg.contents[82]
                );
                assert_eq!(
                    msg.contents[83], 128,
                    "incorrect value for contents[83], expected 128, is {}",
                    msg.contents[83]
                );
                assert_eq!(
                    msg.contents[84], 73,
                    "incorrect value for contents[84], expected 73, is {}",
                    msg.contents[84]
                );
                assert_eq!(
                    msg.contents[85], 181,
                    "incorrect value for contents[85], expected 181, is {}",
                    msg.contents[85]
                );
                assert_eq!(
                    msg.contents[86], 20,
                    "incorrect value for contents[86], expected 20, is {}",
                    msg.contents[86]
                );
                assert_eq!(
                    msg.contents[87], 233,
                    "incorrect value for contents[87], expected 233, is {}",
                    msg.contents[87]
                );
                assert_eq!(
                    msg.contents[88], 23,
                    "incorrect value for contents[88], expected 23, is {}",
                    msg.contents[88]
                );
                assert_eq!(
                    msg.contents[89], 23,
                    "incorrect value for contents[89], expected 23, is {}",
                    msg.contents[89]
                );
                assert_eq!(
                    msg.contents[90], 73,
                    "incorrect value for contents[90], expected 73, is {}",
                    msg.contents[90]
                );
                assert_eq!(
                    msg.contents[91], 119,
                    "incorrect value for contents[91], expected 119, is {}",
                    msg.contents[91]
                );
                assert_eq!(
                    msg.contents[92], 136,
                    "incorrect value for contents[92], expected 136, is {}",
                    msg.contents[92]
                );
                assert_eq!(
                    msg.contents[93], 231,
                    "incorrect value for contents[93], expected 231, is {}",
                    msg.contents[93]
                );
                assert_eq!(
                    msg.contents[94], 189,
                    "incorrect value for contents[94], expected 189, is {}",
                    msg.contents[94]
                );
                assert_eq!(
                    msg.contents[95], 26,
                    "incorrect value for contents[95], expected 26, is {}",
                    msg.contents[95]
                );
                assert_eq!(
                    msg.contents[96], 174,
                    "incorrect value for contents[96], expected 174, is {}",
                    msg.contents[96]
                );
                assert_eq!(
                    msg.contents[97], 128,
                    "incorrect value for contents[97], expected 128, is {}",
                    msg.contents[97]
                );
                assert_eq!(
                    msg.contents[98], 93,
                    "incorrect value for contents[98], expected 93, is {}",
                    msg.contents[98]
                );
                assert_eq!(
                    msg.contents[99], 30,
                    "incorrect value for contents[99], expected 30, is {}",
                    msg.contents[99]
                );
                assert_eq!(
                    msg.contents[100], 76,
                    "incorrect value for contents[100], expected 76, is {}",
                    msg.contents[100]
                );
                assert_eq!(
                    msg.contents[101], 45,
                    "incorrect value for contents[101], expected 45, is {}",
                    msg.contents[101]
                );
                assert_eq!(
                    msg.contents[102], 109,
                    "incorrect value for contents[102], expected 109, is {}",
                    msg.contents[102]
                );
                assert_eq!(
                    msg.contents[103], 134,
                    "incorrect value for contents[103], expected 134, is {}",
                    msg.contents[103]
                );
                assert_eq!(
                    msg.contents[104], 81,
                    "incorrect value for contents[104], expected 81, is {}",
                    msg.contents[104]
                );
                assert_eq!(
                    msg.contents[105], 0,
                    "incorrect value for contents[105], expected 0, is {}",
                    msg.contents[105]
                );
                assert_eq!(
                    msg.contents[106], 116,
                    "incorrect value for contents[106], expected 116, is {}",
                    msg.contents[106]
                );
                assert_eq!(
                    msg.contents[107], 158,
                    "incorrect value for contents[107], expected 158, is {}",
                    msg.contents[107]
                );
                assert_eq!(
                    msg.contents[108], 127,
                    "incorrect value for contents[108], expected 127, is {}",
                    msg.contents[108]
                );
                assert_eq!(
                    msg.contents[109], 40,
                    "incorrect value for contents[109], expected 40, is {}",
                    msg.contents[109]
                );
                assert_eq!(
                    msg.contents[110], 133,
                    "incorrect value for contents[110], expected 133, is {}",
                    msg.contents[110]
                );
                assert_eq!(
                    msg.contents[111], 208,
                    "incorrect value for contents[111], expected 208, is {}",
                    msg.contents[111]
                );
                assert_eq!(
                    msg.contents[112], 134,
                    "incorrect value for contents[112], expected 134, is {}",
                    msg.contents[112]
                );
                assert_eq!(
                    msg.contents[113], 127,
                    "incorrect value for contents[113], expected 127, is {}",
                    msg.contents[113]
                );
                assert_eq!(
                    msg.contents[114], 140,
                    "incorrect value for contents[114], expected 140, is {}",
                    msg.contents[114]
                );
                assert_eq!(
                    msg.contents[115], 232,
                    "incorrect value for contents[115], expected 232, is {}",
                    msg.contents[115]
                );
                assert_eq!(
                    msg.contents[116], 183,
                    "incorrect value for contents[116], expected 183, is {}",
                    msg.contents[116]
                );
                assert_eq!(
                    msg.contents[117], 184,
                    "incorrect value for contents[117], expected 184, is {}",
                    msg.contents[117]
                );
                assert_eq!(
                    msg.contents[118], 108,
                    "incorrect value for contents[118], expected 108, is {}",
                    msg.contents[118]
                );
                assert_eq!(
                    msg.contents[119], 6,
                    "incorrect value for contents[119], expected 6, is {}",
                    msg.contents[119]
                );
                assert_eq!(
                    msg.contents[120], 228,
                    "incorrect value for contents[120], expected 228, is {}",
                    msg.contents[120]
                );
                assert_eq!(
                    msg.contents[121], 54,
                    "incorrect value for contents[121], expected 54, is {}",
                    msg.contents[121]
                );
                assert_eq!(
                    msg.contents[122], 238,
                    "incorrect value for contents[122], expected 238, is {}",
                    msg.contents[122]
                );
                assert_eq!(
                    msg.contents[123], 59,
                    "incorrect value for contents[123], expected 59, is {}",
                    msg.contents[123]
                );
                assert_eq!(
                    msg.contents[124], 220,
                    "incorrect value for contents[124], expected 220, is {}",
                    msg.contents[124]
                );
                assert_eq!(
                    msg.contents[125], 30,
                    "incorrect value for contents[125], expected 30, is {}",
                    msg.contents[125]
                );
                assert_eq!(
                    msg.contents[126], 228,
                    "incorrect value for contents[126], expected 228, is {}",
                    msg.contents[126]
                );
                assert_eq!(
                    msg.contents[127], 212,
                    "incorrect value for contents[127], expected 212, is {}",
                    msg.contents[127]
                );
                assert_eq!(
                    msg.contents[128], 50,
                    "incorrect value for contents[128], expected 50, is {}",
                    msg.contents[128]
                );
                assert_eq!(
                    msg.contents[129], 182,
                    "incorrect value for contents[129], expected 182, is {}",
                    msg.contents[129]
                );
                assert_eq!(
                    msg.contents[130], 97,
                    "incorrect value for contents[130], expected 97, is {}",
                    msg.contents[130]
                );
                assert_eq!(
                    msg.contents[131], 20,
                    "incorrect value for contents[131], expected 20, is {}",
                    msg.contents[131]
                );
                assert_eq!(
                    msg.contents[132], 41,
                    "incorrect value for contents[132], expected 41, is {}",
                    msg.contents[132]
                );
                assert_eq!(
                    msg.contents[133], 76,
                    "incorrect value for contents[133], expected 76, is {}",
                    msg.contents[133]
                );
                assert_eq!(
                    msg.contents[134], 227,
                    "incorrect value for contents[134], expected 227, is {}",
                    msg.contents[134]
                );
                assert_eq!(
                    msg.contents[135], 88,
                    "incorrect value for contents[135], expected 88, is {}",
                    msg.contents[135]
                );
                assert_eq!(
                    msg.contents[136], 12,
                    "incorrect value for contents[136], expected 12, is {}",
                    msg.contents[136]
                );
                assert_eq!(
                    msg.contents[137], 95,
                    "incorrect value for contents[137], expected 95, is {}",
                    msg.contents[137]
                );
                assert_eq!(
                    msg.contents[138], 112,
                    "incorrect value for contents[138], expected 112, is {}",
                    msg.contents[138]
                );
                assert_eq!(
                    msg.contents[139], 209,
                    "incorrect value for contents[139], expected 209, is {}",
                    msg.contents[139]
                );
                assert_eq!(
                    msg.contents[140], 183,
                    "incorrect value for contents[140], expected 183, is {}",
                    msg.contents[140]
                );
                assert_eq!(
                    msg.contents[141], 127,
                    "incorrect value for contents[141], expected 127, is {}",
                    msg.contents[141]
                );
                assert_eq!(
                    msg.contents[142], 4,
                    "incorrect value for contents[142], expected 4, is {}",
                    msg.contents[142]
                );
                assert_eq!(
                    msg.contents[143], 165,
                    "incorrect value for contents[143], expected 165, is {}",
                    msg.contents[143]
                );
                assert_eq!(
                    msg.contents[144], 189,
                    "incorrect value for contents[144], expected 189, is {}",
                    msg.contents[144]
                );
                assert_eq!(
                    msg.contents[145], 44,
                    "incorrect value for contents[145], expected 44, is {}",
                    msg.contents[145]
                );
                assert_eq!(
                    msg.contents[146], 239,
                    "incorrect value for contents[146], expected 239, is {}",
                    msg.contents[146]
                );
                assert_eq!(
                    msg.contents[147], 232,
                    "incorrect value for contents[147], expected 232, is {}",
                    msg.contents[147]
                );
                assert_eq!(
                    msg.contents[148], 132,
                    "incorrect value for contents[148], expected 132, is {}",
                    msg.contents[148]
                );
                assert_eq!(
                    msg.contents[149], 9,
                    "incorrect value for contents[149], expected 9, is {}",
                    msg.contents[149]
                );
                assert_eq!(
                    msg.contents[150], 114,
                    "incorrect value for contents[150], expected 114, is {}",
                    msg.contents[150]
                );
                assert_eq!(
                    msg.contents[151], 184,
                    "incorrect value for contents[151], expected 184, is {}",
                    msg.contents[151]
                );
                assert_eq!(
                    msg.contents[152], 249,
                    "incorrect value for contents[152], expected 249, is {}",
                    msg.contents[152]
                );
                assert_eq!(
                    msg.contents[153], 208,
                    "incorrect value for contents[153], expected 208, is {}",
                    msg.contents[153]
                );
                assert_eq!(
                    msg.contents[154], 246,
                    "incorrect value for contents[154], expected 246, is {}",
                    msg.contents[154]
                );
                assert_eq!(
                    msg.contents[155], 194,
                    "incorrect value for contents[155], expected 194, is {}",
                    msg.contents[155]
                );
                assert_eq!(
                    msg.contents[156], 250,
                    "incorrect value for contents[156], expected 250, is {}",
                    msg.contents[156]
                );
                assert_eq!(
                    msg.contents[157], 2,
                    "incorrect value for contents[157], expected 2, is {}",
                    msg.contents[157]
                );
                assert_eq!(
                    msg.contents[158], 97,
                    "incorrect value for contents[158], expected 97, is {}",
                    msg.contents[158]
                );
                assert_eq!(
                    msg.contents[159], 173,
                    "incorrect value for contents[159], expected 173, is {}",
                    msg.contents[159]
                );
                assert_eq!(
                    msg.contents[160], 157,
                    "incorrect value for contents[160], expected 157, is {}",
                    msg.contents[160]
                );
                assert_eq!(
                    msg.contents[161], 202,
                    "incorrect value for contents[161], expected 202, is {}",
                    msg.contents[161]
                );
                assert_eq!(
                    msg.contents[162], 172,
                    "incorrect value for contents[162], expected 172, is {}",
                    msg.contents[162]
                );
                assert_eq!(
                    msg.contents[163], 180,
                    "incorrect value for contents[163], expected 180, is {}",
                    msg.contents[163]
                );
                assert_eq!(
                    msg.contents[164], 150,
                    "incorrect value for contents[164], expected 150, is {}",
                    msg.contents[164]
                );
                assert_eq!(
                    msg.contents[165], 213,
                    "incorrect value for contents[165], expected 213, is {}",
                    msg.contents[165]
                );
                assert_eq!(
                    msg.contents[166], 193,
                    "incorrect value for contents[166], expected 193, is {}",
                    msg.contents[166]
                );
                assert_eq!(
                    msg.contents[167], 177,
                    "incorrect value for contents[167], expected 177, is {}",
                    msg.contents[167]
                );
                assert_eq!(
                    msg.contents[168], 209,
                    "incorrect value for contents[168], expected 209, is {}",
                    msg.contents[168]
                );
                assert_eq!(
                    msg.contents[169], 156,
                    "incorrect value for contents[169], expected 156, is {}",
                    msg.contents[169]
                );
                assert_eq!(
                    msg.contents[170], 20,
                    "incorrect value for contents[170], expected 20, is {}",
                    msg.contents[170]
                );
                assert_eq!(
                    msg.contents[171], 174,
                    "incorrect value for contents[171], expected 174, is {}",
                    msg.contents[171]
                );
                assert_eq!(
                    msg.contents[172], 18,
                    "incorrect value for contents[172], expected 18, is {}",
                    msg.contents[172]
                );
                assert_eq!(
                    msg.contents[173], 73,
                    "incorrect value for contents[173], expected 73, is {}",
                    msg.contents[173]
                );
                assert_eq!(
                    msg.contents[174], 132,
                    "incorrect value for contents[174], expected 132, is {}",
                    msg.contents[174]
                );
                assert_eq!(
                    msg.contents[175], 215,
                    "incorrect value for contents[175], expected 215, is {}",
                    msg.contents[175]
                );
                assert_eq!(
                    msg.contents[176], 115,
                    "incorrect value for contents[176], expected 115, is {}",
                    msg.contents[176]
                );
                assert_eq!(
                    msg.contents[177], 128,
                    "incorrect value for contents[177], expected 128, is {}",
                    msg.contents[177]
                );
                assert_eq!(
                    msg.contents[178], 175,
                    "incorrect value for contents[178], expected 175, is {}",
                    msg.contents[178]
                );
                assert_eq!(
                    msg.contents[179], 169,
                    "incorrect value for contents[179], expected 169, is {}",
                    msg.contents[179]
                );
                assert_eq!(
                    msg.contents[180], 116,
                    "incorrect value for contents[180], expected 116, is {}",
                    msg.contents[180]
                );
                assert_eq!(
                    msg.contents[181], 132,
                    "incorrect value for contents[181], expected 132, is {}",
                    msg.contents[181]
                );
                assert_eq!(
                    msg.contents[182], 100,
                    "incorrect value for contents[182], expected 100, is {}",
                    msg.contents[182]
                );
                assert_eq!(
                    msg.contents[183], 72,
                    "incorrect value for contents[183], expected 72, is {}",
                    msg.contents[183]
                );
                assert_eq!(
                    msg.contents[184], 45,
                    "incorrect value for contents[184], expected 45, is {}",
                    msg.contents[184]
                );
                assert_eq!(
                    msg.contents[185], 25,
                    "incorrect value for contents[185], expected 25, is {}",
                    msg.contents[185]
                );
                assert_eq!(
                    msg.contents[186], 14,
                    "incorrect value for contents[186], expected 14, is {}",
                    msg.contents[186]
                );
                assert_eq!(
                    msg.contents[187], 205,
                    "incorrect value for contents[187], expected 205, is {}",
                    msg.contents[187]
                );
                assert_eq!(
                    msg.contents[188], 213,
                    "incorrect value for contents[188], expected 213, is {}",
                    msg.contents[188]
                );
                assert_eq!(
                    msg.contents[189], 145,
                    "incorrect value for contents[189], expected 145, is {}",
                    msg.contents[189]
                );
                assert_eq!(
                    msg.contents[190], 68,
                    "incorrect value for contents[190], expected 68, is {}",
                    msg.contents[190]
                );
                assert_eq!(
                    msg.contents[191], 137,
                    "incorrect value for contents[191], expected 137, is {}",
                    msg.contents[191]
                );
                assert_eq!(
                    msg.contents[192], 249,
                    "incorrect value for contents[192], expected 249, is {}",
                    msg.contents[192]
                );
                assert_eq!(
                    msg.contents[193], 54,
                    "incorrect value for contents[193], expected 54, is {}",
                    msg.contents[193]
                );
                assert_eq!(
                    msg.contents[194], 40,
                    "incorrect value for contents[194], expected 40, is {}",
                    msg.contents[194]
                );
                assert_eq!(
                    msg.contents[195], 174,
                    "incorrect value for contents[195], expected 174, is {}",
                    msg.contents[195]
                );
                assert_eq!(
                    msg.contents[196], 215,
                    "incorrect value for contents[196], expected 215, is {}",
                    msg.contents[196]
                );
                assert_eq!(
                    msg.contents[197], 148,
                    "incorrect value for contents[197], expected 148, is {}",
                    msg.contents[197]
                );
                assert_eq!(
                    msg.contents[198], 166,
                    "incorrect value for contents[198], expected 166, is {}",
                    msg.contents[198]
                );
                assert_eq!(
                    msg.contents[199], 190,
                    "incorrect value for contents[199], expected 190, is {}",
                    msg.contents[199]
                );
                assert_eq!(
                    msg.contents[200], 63,
                    "incorrect value for contents[200], expected 63, is {}",
                    msg.contents[200]
                );
                assert_eq!(
                    msg.contents[201], 118,
                    "incorrect value for contents[201], expected 118, is {}",
                    msg.contents[201]
                );
                assert_eq!(
                    msg.contents[202], 6,
                    "incorrect value for contents[202], expected 6, is {}",
                    msg.contents[202]
                );
                assert_eq!(
                    msg.contents[203], 165,
                    "incorrect value for contents[203], expected 165, is {}",
                    msg.contents[203]
                );
                assert_eq!(
                    msg.contents[204], 212,
                    "incorrect value for contents[204], expected 212, is {}",
                    msg.contents[204]
                );
                assert_eq!(
                    msg.contents[205], 74,
                    "incorrect value for contents[205], expected 74, is {}",
                    msg.contents[205]
                );
                assert_eq!(
                    msg.contents[206], 68,
                    "incorrect value for contents[206], expected 68, is {}",
                    msg.contents[206]
                );
                assert_eq!(
                    msg.contents[207], 200,
                    "incorrect value for contents[207], expected 200, is {}",
                    msg.contents[207]
                );
                assert_eq!(
                    msg.contents[208], 38,
                    "incorrect value for contents[208], expected 38, is {}",
                    msg.contents[208]
                );
                assert_eq!(
                    msg.contents[209], 139,
                    "incorrect value for contents[209], expected 139, is {}",
                    msg.contents[209]
                );
                assert_eq!(
                    msg.contents[210], 212,
                    "incorrect value for contents[210], expected 212, is {}",
                    msg.contents[210]
                );
                assert_eq!(
                    msg.contents[211], 112,
                    "incorrect value for contents[211], expected 112, is {}",
                    msg.contents[211]
                );
                assert_eq!(
                    msg.contents[212], 45,
                    "incorrect value for contents[212], expected 45, is {}",
                    msg.contents[212]
                );
                assert_eq!(
                    msg.contents[213], 167,
                    "incorrect value for contents[213], expected 167, is {}",
                    msg.contents[213]
                );
                assert_eq!(
                    msg.contents[214], 236,
                    "incorrect value for contents[214], expected 236, is {}",
                    msg.contents[214]
                );
                assert_eq!(
                    msg.contents[215], 255,
                    "incorrect value for contents[215], expected 255, is {}",
                    msg.contents[215]
                );
                assert_eq!(
                    msg.contents[216], 106,
                    "incorrect value for contents[216], expected 106, is {}",
                    msg.contents[216]
                );
                assert_eq!(
                    msg.contents[217], 92,
                    "incorrect value for contents[217], expected 92, is {}",
                    msg.contents[217]
                );
                assert_eq!(
                    msg.contents[218], 132,
                    "incorrect value for contents[218], expected 132, is {}",
                    msg.contents[218]
                );
                assert_eq!(
                    msg.contents[219], 59,
                    "incorrect value for contents[219], expected 59, is {}",
                    msg.contents[219]
                );
                assert_eq!(
                    msg.contents[220], 61,
                    "incorrect value for contents[220], expected 61, is {}",
                    msg.contents[220]
                );
                assert_eq!(
                    msg.contents[221], 233,
                    "incorrect value for contents[221], expected 233, is {}",
                    msg.contents[221]
                );
                assert_eq!(
                    msg.contents[222], 3,
                    "incorrect value for contents[222], expected 3, is {}",
                    msg.contents[222]
                );
                assert_eq!(
                    msg.contents[223], 246,
                    "incorrect value for contents[223], expected 246, is {}",
                    msg.contents[223]
                );
                assert_eq!(
                    msg.contents[224], 158,
                    "incorrect value for contents[224], expected 158, is {}",
                    msg.contents[224]
                );
                assert_eq!(
                    msg.contents[225], 83,
                    "incorrect value for contents[225], expected 83, is {}",
                    msg.contents[225]
                );
                assert_eq!(
                    msg.contents[226], 134,
                    "incorrect value for contents[226], expected 134, is {}",
                    msg.contents[226]
                );
                assert_eq!(
                    msg.contents[227], 246,
                    "incorrect value for contents[227], expected 246, is {}",
                    msg.contents[227]
                );
                assert_eq!(
                    msg.contents[228], 154,
                    "incorrect value for contents[228], expected 154, is {}",
                    msg.contents[228]
                );
                assert_eq!(
                    msg.contents[229], 17,
                    "incorrect value for contents[229], expected 17, is {}",
                    msg.contents[229]
                );
                assert_eq!(
                    msg.contents[230], 0,
                    "incorrect value for contents[230], expected 0, is {}",
                    msg.contents[230]
                );
                assert_eq!(
                    msg.contents[231], 6,
                    "incorrect value for contents[231], expected 6, is {}",
                    msg.contents[231]
                );
                assert_eq!(
                    msg.contents[232], 56,
                    "incorrect value for contents[232], expected 56, is {}",
                    msg.contents[232]
                );
                assert_eq!(
                    msg.contents[233], 216,
                    "incorrect value for contents[233], expected 216, is {}",
                    msg.contents[233]
                );
                assert_eq!(
                    msg.contents[234], 19,
                    "incorrect value for contents[234], expected 19, is {}",
                    msg.contents[234]
                );
                assert_eq!(
                    msg.contents[235], 216,
                    "incorrect value for contents[235], expected 216, is {}",
                    msg.contents[235]
                );
                assert_eq!(
                    msg.contents[236], 70,
                    "incorrect value for contents[236], expected 70, is {}",
                    msg.contents[236]
                );
                assert_eq!(
                    msg.contents[237], 71,
                    "incorrect value for contents[237], expected 71, is {}",
                    msg.contents[237]
                );
                assert_eq!(
                    msg.contents[238], 161,
                    "incorrect value for contents[238], expected 161, is {}",
                    msg.contents[238]
                );
                assert_eq!(
                    msg.contents[239], 184,
                    "incorrect value for contents[239], expected 184, is {}",
                    msg.contents[239]
                );
                assert_eq!(
                    msg.contents[240], 5,
                    "incorrect value for contents[240], expected 5, is {}",
                    msg.contents[240]
                );
                assert_eq!(
                    msg.contents[241], 177,
                    "incorrect value for contents[241], expected 177, is {}",
                    msg.contents[241]
                );
                assert_eq!(
                    msg.contents[242], 45,
                    "incorrect value for contents[242], expected 45, is {}",
                    msg.contents[242]
                );
                assert_eq!(
                    msg.contents[243], 37,
                    "incorrect value for contents[243], expected 37, is {}",
                    msg.contents[243]
                );
                assert_eq!(
                    msg.contents[244], 98,
                    "incorrect value for contents[244], expected 98, is {}",
                    msg.contents[244]
                );
                assert_eq!(
                    msg.contents[245], 56,
                    "incorrect value for contents[245], expected 56, is {}",
                    msg.contents[245]
                );
                assert_eq!(
                    msg.contents[246], 149,
                    "incorrect value for contents[246], expected 149, is {}",
                    msg.contents[246]
                );
                assert_eq!(
                    msg.contents[247], 0,
                    "incorrect value for contents[247], expected 0, is {}",
                    msg.contents[247]
                );
                assert_eq!(
                    msg.contents[248], 73,
                    "incorrect value for contents[248], expected 73, is {}",
                    msg.contents[248]
                );
                assert_eq!(
                    msg.contents[249], 221,
                    "incorrect value for contents[249], expected 221, is {}",
                    msg.contents[249]
                );
                assert_eq!(
                    msg.contents[250], 105,
                    "incorrect value for contents[250], expected 105, is {}",
                    msg.contents[250]
                );
                assert_eq!(
                    msg.contents[251], 239,
                    "incorrect value for contents[251], expected 239, is {}",
                    msg.contents[251]
                );
                assert_eq!(
                    msg.contents[252], 168,
                    "incorrect value for contents[252], expected 168, is {}",
                    msg.contents[252]
                );
                assert_eq!(
                    msg.contents[253], 205,
                    "incorrect value for contents[253], expected 205, is {}",
                    msg.contents[253]
                );
                assert_eq!(
                    msg.contents[254], 85,
                    "incorrect value for contents[254], expected 85, is {}",
                    msg.contents[254]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgUserData"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
