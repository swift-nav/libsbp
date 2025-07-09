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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadResp.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_file_io_msg_fileio_read_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 163, 0, 195, 4, 255, 67, 183, 115, 15, 73, 231, 227, 179, 18, 76, 68, 229, 216, 21,
            98, 183, 69, 190, 5, 252, 176, 55, 32, 78, 8, 52, 127, 50, 71, 106, 61, 79, 191, 106,
            46, 79, 118, 248, 118, 207, 206, 210, 91, 73, 251, 81, 131, 205, 193, 146, 206, 185,
            140, 249, 163, 231, 65, 67, 94, 250, 109, 152, 95, 123, 77, 224, 124, 238, 205, 65,
            103, 35, 104, 209, 5, 191, 47, 249, 176, 166, 213, 46, 192, 86, 32, 103, 146, 252, 4,
            16, 54, 161, 60, 6, 13, 191, 116, 182, 42, 191, 213, 20, 217, 8, 142, 187, 238, 120,
            184, 250, 31, 151, 37, 51, 177, 130, 190, 155, 71, 68, 56, 238, 92, 130, 37, 137, 146,
            246, 114, 116, 138, 165, 217, 79, 10, 189, 128, 189, 2, 240, 92, 28, 126, 105, 236,
            228, 194, 0, 51, 61, 74, 41, 10, 239, 133, 106, 190, 30, 27, 3, 240, 205, 253, 113, 25,
            28, 187, 81, 101, 216, 121, 41, 179, 120, 152, 18, 116, 53, 212, 100, 2, 114, 198, 200,
            10, 147, 25, 33, 115, 208, 113, 60, 179, 183, 0, 41, 217, 206, 255, 211, 225, 142, 191,
            133, 81, 15, 248, 193, 66, 191, 244, 221, 248, 199, 241, 112, 51, 1, 180, 180, 125, 97,
            145, 25, 72, 210, 215, 208, 15, 126, 56, 38, 65, 4, 64, 19, 74, 223, 111, 109, 52, 43,
            167, 186, 202, 111, 11, 91, 21, 236, 234, 196, 36, 171, 147, 10, 240,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgFileioReadResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa3,
                    "Incorrect message type, expected 0xa3, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.contents[0], 73,
                    "incorrect value for contents[0], expected 73, is {}",
                    msg.contents[0]
                );
                assert_eq!(
                    msg.contents[1], 231,
                    "incorrect value for contents[1], expected 231, is {}",
                    msg.contents[1]
                );
                assert_eq!(
                    msg.contents[2], 227,
                    "incorrect value for contents[2], expected 227, is {}",
                    msg.contents[2]
                );
                assert_eq!(
                    msg.contents[3], 179,
                    "incorrect value for contents[3], expected 179, is {}",
                    msg.contents[3]
                );
                assert_eq!(
                    msg.contents[4], 18,
                    "incorrect value for contents[4], expected 18, is {}",
                    msg.contents[4]
                );
                assert_eq!(
                    msg.contents[5], 76,
                    "incorrect value for contents[5], expected 76, is {}",
                    msg.contents[5]
                );
                assert_eq!(
                    msg.contents[6], 68,
                    "incorrect value for contents[6], expected 68, is {}",
                    msg.contents[6]
                );
                assert_eq!(
                    msg.contents[7], 229,
                    "incorrect value for contents[7], expected 229, is {}",
                    msg.contents[7]
                );
                assert_eq!(
                    msg.contents[8], 216,
                    "incorrect value for contents[8], expected 216, is {}",
                    msg.contents[8]
                );
                assert_eq!(
                    msg.contents[9], 21,
                    "incorrect value for contents[9], expected 21, is {}",
                    msg.contents[9]
                );
                assert_eq!(
                    msg.contents[10], 98,
                    "incorrect value for contents[10], expected 98, is {}",
                    msg.contents[10]
                );
                assert_eq!(
                    msg.contents[11], 183,
                    "incorrect value for contents[11], expected 183, is {}",
                    msg.contents[11]
                );
                assert_eq!(
                    msg.contents[12], 69,
                    "incorrect value for contents[12], expected 69, is {}",
                    msg.contents[12]
                );
                assert_eq!(
                    msg.contents[13], 190,
                    "incorrect value for contents[13], expected 190, is {}",
                    msg.contents[13]
                );
                assert_eq!(
                    msg.contents[14], 5,
                    "incorrect value for contents[14], expected 5, is {}",
                    msg.contents[14]
                );
                assert_eq!(
                    msg.contents[15], 252,
                    "incorrect value for contents[15], expected 252, is {}",
                    msg.contents[15]
                );
                assert_eq!(
                    msg.contents[16], 176,
                    "incorrect value for contents[16], expected 176, is {}",
                    msg.contents[16]
                );
                assert_eq!(
                    msg.contents[17], 55,
                    "incorrect value for contents[17], expected 55, is {}",
                    msg.contents[17]
                );
                assert_eq!(
                    msg.contents[18], 32,
                    "incorrect value for contents[18], expected 32, is {}",
                    msg.contents[18]
                );
                assert_eq!(
                    msg.contents[19], 78,
                    "incorrect value for contents[19], expected 78, is {}",
                    msg.contents[19]
                );
                assert_eq!(
                    msg.contents[20], 8,
                    "incorrect value for contents[20], expected 8, is {}",
                    msg.contents[20]
                );
                assert_eq!(
                    msg.contents[21], 52,
                    "incorrect value for contents[21], expected 52, is {}",
                    msg.contents[21]
                );
                assert_eq!(
                    msg.contents[22], 127,
                    "incorrect value for contents[22], expected 127, is {}",
                    msg.contents[22]
                );
                assert_eq!(
                    msg.contents[23], 50,
                    "incorrect value for contents[23], expected 50, is {}",
                    msg.contents[23]
                );
                assert_eq!(
                    msg.contents[24], 71,
                    "incorrect value for contents[24], expected 71, is {}",
                    msg.contents[24]
                );
                assert_eq!(
                    msg.contents[25], 106,
                    "incorrect value for contents[25], expected 106, is {}",
                    msg.contents[25]
                );
                assert_eq!(
                    msg.contents[26], 61,
                    "incorrect value for contents[26], expected 61, is {}",
                    msg.contents[26]
                );
                assert_eq!(
                    msg.contents[27], 79,
                    "incorrect value for contents[27], expected 79, is {}",
                    msg.contents[27]
                );
                assert_eq!(
                    msg.contents[28], 191,
                    "incorrect value for contents[28], expected 191, is {}",
                    msg.contents[28]
                );
                assert_eq!(
                    msg.contents[29], 106,
                    "incorrect value for contents[29], expected 106, is {}",
                    msg.contents[29]
                );
                assert_eq!(
                    msg.contents[30], 46,
                    "incorrect value for contents[30], expected 46, is {}",
                    msg.contents[30]
                );
                assert_eq!(
                    msg.contents[31], 79,
                    "incorrect value for contents[31], expected 79, is {}",
                    msg.contents[31]
                );
                assert_eq!(
                    msg.contents[32], 118,
                    "incorrect value for contents[32], expected 118, is {}",
                    msg.contents[32]
                );
                assert_eq!(
                    msg.contents[33], 248,
                    "incorrect value for contents[33], expected 248, is {}",
                    msg.contents[33]
                );
                assert_eq!(
                    msg.contents[34], 118,
                    "incorrect value for contents[34], expected 118, is {}",
                    msg.contents[34]
                );
                assert_eq!(
                    msg.contents[35], 207,
                    "incorrect value for contents[35], expected 207, is {}",
                    msg.contents[35]
                );
                assert_eq!(
                    msg.contents[36], 206,
                    "incorrect value for contents[36], expected 206, is {}",
                    msg.contents[36]
                );
                assert_eq!(
                    msg.contents[37], 210,
                    "incorrect value for contents[37], expected 210, is {}",
                    msg.contents[37]
                );
                assert_eq!(
                    msg.contents[38], 91,
                    "incorrect value for contents[38], expected 91, is {}",
                    msg.contents[38]
                );
                assert_eq!(
                    msg.contents[39], 73,
                    "incorrect value for contents[39], expected 73, is {}",
                    msg.contents[39]
                );
                assert_eq!(
                    msg.contents[40], 251,
                    "incorrect value for contents[40], expected 251, is {}",
                    msg.contents[40]
                );
                assert_eq!(
                    msg.contents[41], 81,
                    "incorrect value for contents[41], expected 81, is {}",
                    msg.contents[41]
                );
                assert_eq!(
                    msg.contents[42], 131,
                    "incorrect value for contents[42], expected 131, is {}",
                    msg.contents[42]
                );
                assert_eq!(
                    msg.contents[43], 205,
                    "incorrect value for contents[43], expected 205, is {}",
                    msg.contents[43]
                );
                assert_eq!(
                    msg.contents[44], 193,
                    "incorrect value for contents[44], expected 193, is {}",
                    msg.contents[44]
                );
                assert_eq!(
                    msg.contents[45], 146,
                    "incorrect value for contents[45], expected 146, is {}",
                    msg.contents[45]
                );
                assert_eq!(
                    msg.contents[46], 206,
                    "incorrect value for contents[46], expected 206, is {}",
                    msg.contents[46]
                );
                assert_eq!(
                    msg.contents[47], 185,
                    "incorrect value for contents[47], expected 185, is {}",
                    msg.contents[47]
                );
                assert_eq!(
                    msg.contents[48], 140,
                    "incorrect value for contents[48], expected 140, is {}",
                    msg.contents[48]
                );
                assert_eq!(
                    msg.contents[49], 249,
                    "incorrect value for contents[49], expected 249, is {}",
                    msg.contents[49]
                );
                assert_eq!(
                    msg.contents[50], 163,
                    "incorrect value for contents[50], expected 163, is {}",
                    msg.contents[50]
                );
                assert_eq!(
                    msg.contents[51], 231,
                    "incorrect value for contents[51], expected 231, is {}",
                    msg.contents[51]
                );
                assert_eq!(
                    msg.contents[52], 65,
                    "incorrect value for contents[52], expected 65, is {}",
                    msg.contents[52]
                );
                assert_eq!(
                    msg.contents[53], 67,
                    "incorrect value for contents[53], expected 67, is {}",
                    msg.contents[53]
                );
                assert_eq!(
                    msg.contents[54], 94,
                    "incorrect value for contents[54], expected 94, is {}",
                    msg.contents[54]
                );
                assert_eq!(
                    msg.contents[55], 250,
                    "incorrect value for contents[55], expected 250, is {}",
                    msg.contents[55]
                );
                assert_eq!(
                    msg.contents[56], 109,
                    "incorrect value for contents[56], expected 109, is {}",
                    msg.contents[56]
                );
                assert_eq!(
                    msg.contents[57], 152,
                    "incorrect value for contents[57], expected 152, is {}",
                    msg.contents[57]
                );
                assert_eq!(
                    msg.contents[58], 95,
                    "incorrect value for contents[58], expected 95, is {}",
                    msg.contents[58]
                );
                assert_eq!(
                    msg.contents[59], 123,
                    "incorrect value for contents[59], expected 123, is {}",
                    msg.contents[59]
                );
                assert_eq!(
                    msg.contents[60], 77,
                    "incorrect value for contents[60], expected 77, is {}",
                    msg.contents[60]
                );
                assert_eq!(
                    msg.contents[61], 224,
                    "incorrect value for contents[61], expected 224, is {}",
                    msg.contents[61]
                );
                assert_eq!(
                    msg.contents[62], 124,
                    "incorrect value for contents[62], expected 124, is {}",
                    msg.contents[62]
                );
                assert_eq!(
                    msg.contents[63], 238,
                    "incorrect value for contents[63], expected 238, is {}",
                    msg.contents[63]
                );
                assert_eq!(
                    msg.contents[64], 205,
                    "incorrect value for contents[64], expected 205, is {}",
                    msg.contents[64]
                );
                assert_eq!(
                    msg.contents[65], 65,
                    "incorrect value for contents[65], expected 65, is {}",
                    msg.contents[65]
                );
                assert_eq!(
                    msg.contents[66], 103,
                    "incorrect value for contents[66], expected 103, is {}",
                    msg.contents[66]
                );
                assert_eq!(
                    msg.contents[67], 35,
                    "incorrect value for contents[67], expected 35, is {}",
                    msg.contents[67]
                );
                assert_eq!(
                    msg.contents[68], 104,
                    "incorrect value for contents[68], expected 104, is {}",
                    msg.contents[68]
                );
                assert_eq!(
                    msg.contents[69], 209,
                    "incorrect value for contents[69], expected 209, is {}",
                    msg.contents[69]
                );
                assert_eq!(
                    msg.contents[70], 5,
                    "incorrect value for contents[70], expected 5, is {}",
                    msg.contents[70]
                );
                assert_eq!(
                    msg.contents[71], 191,
                    "incorrect value for contents[71], expected 191, is {}",
                    msg.contents[71]
                );
                assert_eq!(
                    msg.contents[72], 47,
                    "incorrect value for contents[72], expected 47, is {}",
                    msg.contents[72]
                );
                assert_eq!(
                    msg.contents[73], 249,
                    "incorrect value for contents[73], expected 249, is {}",
                    msg.contents[73]
                );
                assert_eq!(
                    msg.contents[74], 176,
                    "incorrect value for contents[74], expected 176, is {}",
                    msg.contents[74]
                );
                assert_eq!(
                    msg.contents[75], 166,
                    "incorrect value for contents[75], expected 166, is {}",
                    msg.contents[75]
                );
                assert_eq!(
                    msg.contents[76], 213,
                    "incorrect value for contents[76], expected 213, is {}",
                    msg.contents[76]
                );
                assert_eq!(
                    msg.contents[77], 46,
                    "incorrect value for contents[77], expected 46, is {}",
                    msg.contents[77]
                );
                assert_eq!(
                    msg.contents[78], 192,
                    "incorrect value for contents[78], expected 192, is {}",
                    msg.contents[78]
                );
                assert_eq!(
                    msg.contents[79], 86,
                    "incorrect value for contents[79], expected 86, is {}",
                    msg.contents[79]
                );
                assert_eq!(
                    msg.contents[80], 32,
                    "incorrect value for contents[80], expected 32, is {}",
                    msg.contents[80]
                );
                assert_eq!(
                    msg.contents[81], 103,
                    "incorrect value for contents[81], expected 103, is {}",
                    msg.contents[81]
                );
                assert_eq!(
                    msg.contents[82], 146,
                    "incorrect value for contents[82], expected 146, is {}",
                    msg.contents[82]
                );
                assert_eq!(
                    msg.contents[83], 252,
                    "incorrect value for contents[83], expected 252, is {}",
                    msg.contents[83]
                );
                assert_eq!(
                    msg.contents[84], 4,
                    "incorrect value for contents[84], expected 4, is {}",
                    msg.contents[84]
                );
                assert_eq!(
                    msg.contents[85], 16,
                    "incorrect value for contents[85], expected 16, is {}",
                    msg.contents[85]
                );
                assert_eq!(
                    msg.contents[86], 54,
                    "incorrect value for contents[86], expected 54, is {}",
                    msg.contents[86]
                );
                assert_eq!(
                    msg.contents[87], 161,
                    "incorrect value for contents[87], expected 161, is {}",
                    msg.contents[87]
                );
                assert_eq!(
                    msg.contents[88], 60,
                    "incorrect value for contents[88], expected 60, is {}",
                    msg.contents[88]
                );
                assert_eq!(
                    msg.contents[89], 6,
                    "incorrect value for contents[89], expected 6, is {}",
                    msg.contents[89]
                );
                assert_eq!(
                    msg.contents[90], 13,
                    "incorrect value for contents[90], expected 13, is {}",
                    msg.contents[90]
                );
                assert_eq!(
                    msg.contents[91], 191,
                    "incorrect value for contents[91], expected 191, is {}",
                    msg.contents[91]
                );
                assert_eq!(
                    msg.contents[92], 116,
                    "incorrect value for contents[92], expected 116, is {}",
                    msg.contents[92]
                );
                assert_eq!(
                    msg.contents[93], 182,
                    "incorrect value for contents[93], expected 182, is {}",
                    msg.contents[93]
                );
                assert_eq!(
                    msg.contents[94], 42,
                    "incorrect value for contents[94], expected 42, is {}",
                    msg.contents[94]
                );
                assert_eq!(
                    msg.contents[95], 191,
                    "incorrect value for contents[95], expected 191, is {}",
                    msg.contents[95]
                );
                assert_eq!(
                    msg.contents[96], 213,
                    "incorrect value for contents[96], expected 213, is {}",
                    msg.contents[96]
                );
                assert_eq!(
                    msg.contents[97], 20,
                    "incorrect value for contents[97], expected 20, is {}",
                    msg.contents[97]
                );
                assert_eq!(
                    msg.contents[98], 217,
                    "incorrect value for contents[98], expected 217, is {}",
                    msg.contents[98]
                );
                assert_eq!(
                    msg.contents[99], 8,
                    "incorrect value for contents[99], expected 8, is {}",
                    msg.contents[99]
                );
                assert_eq!(
                    msg.contents[100], 142,
                    "incorrect value for contents[100], expected 142, is {}",
                    msg.contents[100]
                );
                assert_eq!(
                    msg.contents[101], 187,
                    "incorrect value for contents[101], expected 187, is {}",
                    msg.contents[101]
                );
                assert_eq!(
                    msg.contents[102], 238,
                    "incorrect value for contents[102], expected 238, is {}",
                    msg.contents[102]
                );
                assert_eq!(
                    msg.contents[103], 120,
                    "incorrect value for contents[103], expected 120, is {}",
                    msg.contents[103]
                );
                assert_eq!(
                    msg.contents[104], 184,
                    "incorrect value for contents[104], expected 184, is {}",
                    msg.contents[104]
                );
                assert_eq!(
                    msg.contents[105], 250,
                    "incorrect value for contents[105], expected 250, is {}",
                    msg.contents[105]
                );
                assert_eq!(
                    msg.contents[106], 31,
                    "incorrect value for contents[106], expected 31, is {}",
                    msg.contents[106]
                );
                assert_eq!(
                    msg.contents[107], 151,
                    "incorrect value for contents[107], expected 151, is {}",
                    msg.contents[107]
                );
                assert_eq!(
                    msg.contents[108], 37,
                    "incorrect value for contents[108], expected 37, is {}",
                    msg.contents[108]
                );
                assert_eq!(
                    msg.contents[109], 51,
                    "incorrect value for contents[109], expected 51, is {}",
                    msg.contents[109]
                );
                assert_eq!(
                    msg.contents[110], 177,
                    "incorrect value for contents[110], expected 177, is {}",
                    msg.contents[110]
                );
                assert_eq!(
                    msg.contents[111], 130,
                    "incorrect value for contents[111], expected 130, is {}",
                    msg.contents[111]
                );
                assert_eq!(
                    msg.contents[112], 190,
                    "incorrect value for contents[112], expected 190, is {}",
                    msg.contents[112]
                );
                assert_eq!(
                    msg.contents[113], 155,
                    "incorrect value for contents[113], expected 155, is {}",
                    msg.contents[113]
                );
                assert_eq!(
                    msg.contents[114], 71,
                    "incorrect value for contents[114], expected 71, is {}",
                    msg.contents[114]
                );
                assert_eq!(
                    msg.contents[115], 68,
                    "incorrect value for contents[115], expected 68, is {}",
                    msg.contents[115]
                );
                assert_eq!(
                    msg.contents[116], 56,
                    "incorrect value for contents[116], expected 56, is {}",
                    msg.contents[116]
                );
                assert_eq!(
                    msg.contents[117], 238,
                    "incorrect value for contents[117], expected 238, is {}",
                    msg.contents[117]
                );
                assert_eq!(
                    msg.contents[118], 92,
                    "incorrect value for contents[118], expected 92, is {}",
                    msg.contents[118]
                );
                assert_eq!(
                    msg.contents[119], 130,
                    "incorrect value for contents[119], expected 130, is {}",
                    msg.contents[119]
                );
                assert_eq!(
                    msg.contents[120], 37,
                    "incorrect value for contents[120], expected 37, is {}",
                    msg.contents[120]
                );
                assert_eq!(
                    msg.contents[121], 137,
                    "incorrect value for contents[121], expected 137, is {}",
                    msg.contents[121]
                );
                assert_eq!(
                    msg.contents[122], 146,
                    "incorrect value for contents[122], expected 146, is {}",
                    msg.contents[122]
                );
                assert_eq!(
                    msg.contents[123], 246,
                    "incorrect value for contents[123], expected 246, is {}",
                    msg.contents[123]
                );
                assert_eq!(
                    msg.contents[124], 114,
                    "incorrect value for contents[124], expected 114, is {}",
                    msg.contents[124]
                );
                assert_eq!(
                    msg.contents[125], 116,
                    "incorrect value for contents[125], expected 116, is {}",
                    msg.contents[125]
                );
                assert_eq!(
                    msg.contents[126], 138,
                    "incorrect value for contents[126], expected 138, is {}",
                    msg.contents[126]
                );
                assert_eq!(
                    msg.contents[127], 165,
                    "incorrect value for contents[127], expected 165, is {}",
                    msg.contents[127]
                );
                assert_eq!(
                    msg.contents[128], 217,
                    "incorrect value for contents[128], expected 217, is {}",
                    msg.contents[128]
                );
                assert_eq!(
                    msg.contents[129], 79,
                    "incorrect value for contents[129], expected 79, is {}",
                    msg.contents[129]
                );
                assert_eq!(
                    msg.contents[130], 10,
                    "incorrect value for contents[130], expected 10, is {}",
                    msg.contents[130]
                );
                assert_eq!(
                    msg.contents[131], 189,
                    "incorrect value for contents[131], expected 189, is {}",
                    msg.contents[131]
                );
                assert_eq!(
                    msg.contents[132], 128,
                    "incorrect value for contents[132], expected 128, is {}",
                    msg.contents[132]
                );
                assert_eq!(
                    msg.contents[133], 189,
                    "incorrect value for contents[133], expected 189, is {}",
                    msg.contents[133]
                );
                assert_eq!(
                    msg.contents[134], 2,
                    "incorrect value for contents[134], expected 2, is {}",
                    msg.contents[134]
                );
                assert_eq!(
                    msg.contents[135], 240,
                    "incorrect value for contents[135], expected 240, is {}",
                    msg.contents[135]
                );
                assert_eq!(
                    msg.contents[136], 92,
                    "incorrect value for contents[136], expected 92, is {}",
                    msg.contents[136]
                );
                assert_eq!(
                    msg.contents[137], 28,
                    "incorrect value for contents[137], expected 28, is {}",
                    msg.contents[137]
                );
                assert_eq!(
                    msg.contents[138], 126,
                    "incorrect value for contents[138], expected 126, is {}",
                    msg.contents[138]
                );
                assert_eq!(
                    msg.contents[139], 105,
                    "incorrect value for contents[139], expected 105, is {}",
                    msg.contents[139]
                );
                assert_eq!(
                    msg.contents[140], 236,
                    "incorrect value for contents[140], expected 236, is {}",
                    msg.contents[140]
                );
                assert_eq!(
                    msg.contents[141], 228,
                    "incorrect value for contents[141], expected 228, is {}",
                    msg.contents[141]
                );
                assert_eq!(
                    msg.contents[142], 194,
                    "incorrect value for contents[142], expected 194, is {}",
                    msg.contents[142]
                );
                assert_eq!(
                    msg.contents[143], 0,
                    "incorrect value for contents[143], expected 0, is {}",
                    msg.contents[143]
                );
                assert_eq!(
                    msg.contents[144], 51,
                    "incorrect value for contents[144], expected 51, is {}",
                    msg.contents[144]
                );
                assert_eq!(
                    msg.contents[145], 61,
                    "incorrect value for contents[145], expected 61, is {}",
                    msg.contents[145]
                );
                assert_eq!(
                    msg.contents[146], 74,
                    "incorrect value for contents[146], expected 74, is {}",
                    msg.contents[146]
                );
                assert_eq!(
                    msg.contents[147], 41,
                    "incorrect value for contents[147], expected 41, is {}",
                    msg.contents[147]
                );
                assert_eq!(
                    msg.contents[148], 10,
                    "incorrect value for contents[148], expected 10, is {}",
                    msg.contents[148]
                );
                assert_eq!(
                    msg.contents[149], 239,
                    "incorrect value for contents[149], expected 239, is {}",
                    msg.contents[149]
                );
                assert_eq!(
                    msg.contents[150], 133,
                    "incorrect value for contents[150], expected 133, is {}",
                    msg.contents[150]
                );
                assert_eq!(
                    msg.contents[151], 106,
                    "incorrect value for contents[151], expected 106, is {}",
                    msg.contents[151]
                );
                assert_eq!(
                    msg.contents[152], 190,
                    "incorrect value for contents[152], expected 190, is {}",
                    msg.contents[152]
                );
                assert_eq!(
                    msg.contents[153], 30,
                    "incorrect value for contents[153], expected 30, is {}",
                    msg.contents[153]
                );
                assert_eq!(
                    msg.contents[154], 27,
                    "incorrect value for contents[154], expected 27, is {}",
                    msg.contents[154]
                );
                assert_eq!(
                    msg.contents[155], 3,
                    "incorrect value for contents[155], expected 3, is {}",
                    msg.contents[155]
                );
                assert_eq!(
                    msg.contents[156], 240,
                    "incorrect value for contents[156], expected 240, is {}",
                    msg.contents[156]
                );
                assert_eq!(
                    msg.contents[157], 205,
                    "incorrect value for contents[157], expected 205, is {}",
                    msg.contents[157]
                );
                assert_eq!(
                    msg.contents[158], 253,
                    "incorrect value for contents[158], expected 253, is {}",
                    msg.contents[158]
                );
                assert_eq!(
                    msg.contents[159], 113,
                    "incorrect value for contents[159], expected 113, is {}",
                    msg.contents[159]
                );
                assert_eq!(
                    msg.contents[160], 25,
                    "incorrect value for contents[160], expected 25, is {}",
                    msg.contents[160]
                );
                assert_eq!(
                    msg.contents[161], 28,
                    "incorrect value for contents[161], expected 28, is {}",
                    msg.contents[161]
                );
                assert_eq!(
                    msg.contents[162], 187,
                    "incorrect value for contents[162], expected 187, is {}",
                    msg.contents[162]
                );
                assert_eq!(
                    msg.contents[163], 81,
                    "incorrect value for contents[163], expected 81, is {}",
                    msg.contents[163]
                );
                assert_eq!(
                    msg.contents[164], 101,
                    "incorrect value for contents[164], expected 101, is {}",
                    msg.contents[164]
                );
                assert_eq!(
                    msg.contents[165], 216,
                    "incorrect value for contents[165], expected 216, is {}",
                    msg.contents[165]
                );
                assert_eq!(
                    msg.contents[166], 121,
                    "incorrect value for contents[166], expected 121, is {}",
                    msg.contents[166]
                );
                assert_eq!(
                    msg.contents[167], 41,
                    "incorrect value for contents[167], expected 41, is {}",
                    msg.contents[167]
                );
                assert_eq!(
                    msg.contents[168], 179,
                    "incorrect value for contents[168], expected 179, is {}",
                    msg.contents[168]
                );
                assert_eq!(
                    msg.contents[169], 120,
                    "incorrect value for contents[169], expected 120, is {}",
                    msg.contents[169]
                );
                assert_eq!(
                    msg.contents[170], 152,
                    "incorrect value for contents[170], expected 152, is {}",
                    msg.contents[170]
                );
                assert_eq!(
                    msg.contents[171], 18,
                    "incorrect value for contents[171], expected 18, is {}",
                    msg.contents[171]
                );
                assert_eq!(
                    msg.contents[172], 116,
                    "incorrect value for contents[172], expected 116, is {}",
                    msg.contents[172]
                );
                assert_eq!(
                    msg.contents[173], 53,
                    "incorrect value for contents[173], expected 53, is {}",
                    msg.contents[173]
                );
                assert_eq!(
                    msg.contents[174], 212,
                    "incorrect value for contents[174], expected 212, is {}",
                    msg.contents[174]
                );
                assert_eq!(
                    msg.contents[175], 100,
                    "incorrect value for contents[175], expected 100, is {}",
                    msg.contents[175]
                );
                assert_eq!(
                    msg.contents[176], 2,
                    "incorrect value for contents[176], expected 2, is {}",
                    msg.contents[176]
                );
                assert_eq!(
                    msg.contents[177], 114,
                    "incorrect value for contents[177], expected 114, is {}",
                    msg.contents[177]
                );
                assert_eq!(
                    msg.contents[178], 198,
                    "incorrect value for contents[178], expected 198, is {}",
                    msg.contents[178]
                );
                assert_eq!(
                    msg.contents[179], 200,
                    "incorrect value for contents[179], expected 200, is {}",
                    msg.contents[179]
                );
                assert_eq!(
                    msg.contents[180], 10,
                    "incorrect value for contents[180], expected 10, is {}",
                    msg.contents[180]
                );
                assert_eq!(
                    msg.contents[181], 147,
                    "incorrect value for contents[181], expected 147, is {}",
                    msg.contents[181]
                );
                assert_eq!(
                    msg.contents[182], 25,
                    "incorrect value for contents[182], expected 25, is {}",
                    msg.contents[182]
                );
                assert_eq!(
                    msg.contents[183], 33,
                    "incorrect value for contents[183], expected 33, is {}",
                    msg.contents[183]
                );
                assert_eq!(
                    msg.contents[184], 115,
                    "incorrect value for contents[184], expected 115, is {}",
                    msg.contents[184]
                );
                assert_eq!(
                    msg.contents[185], 208,
                    "incorrect value for contents[185], expected 208, is {}",
                    msg.contents[185]
                );
                assert_eq!(
                    msg.contents[186], 113,
                    "incorrect value for contents[186], expected 113, is {}",
                    msg.contents[186]
                );
                assert_eq!(
                    msg.contents[187], 60,
                    "incorrect value for contents[187], expected 60, is {}",
                    msg.contents[187]
                );
                assert_eq!(
                    msg.contents[188], 179,
                    "incorrect value for contents[188], expected 179, is {}",
                    msg.contents[188]
                );
                assert_eq!(
                    msg.contents[189], 183,
                    "incorrect value for contents[189], expected 183, is {}",
                    msg.contents[189]
                );
                assert_eq!(
                    msg.contents[190], 0,
                    "incorrect value for contents[190], expected 0, is {}",
                    msg.contents[190]
                );
                assert_eq!(
                    msg.contents[191], 41,
                    "incorrect value for contents[191], expected 41, is {}",
                    msg.contents[191]
                );
                assert_eq!(
                    msg.contents[192], 217,
                    "incorrect value for contents[192], expected 217, is {}",
                    msg.contents[192]
                );
                assert_eq!(
                    msg.contents[193], 206,
                    "incorrect value for contents[193], expected 206, is {}",
                    msg.contents[193]
                );
                assert_eq!(
                    msg.contents[194], 255,
                    "incorrect value for contents[194], expected 255, is {}",
                    msg.contents[194]
                );
                assert_eq!(
                    msg.contents[195], 211,
                    "incorrect value for contents[195], expected 211, is {}",
                    msg.contents[195]
                );
                assert_eq!(
                    msg.contents[196], 225,
                    "incorrect value for contents[196], expected 225, is {}",
                    msg.contents[196]
                );
                assert_eq!(
                    msg.contents[197], 142,
                    "incorrect value for contents[197], expected 142, is {}",
                    msg.contents[197]
                );
                assert_eq!(
                    msg.contents[198], 191,
                    "incorrect value for contents[198], expected 191, is {}",
                    msg.contents[198]
                );
                assert_eq!(
                    msg.contents[199], 133,
                    "incorrect value for contents[199], expected 133, is {}",
                    msg.contents[199]
                );
                assert_eq!(
                    msg.contents[200], 81,
                    "incorrect value for contents[200], expected 81, is {}",
                    msg.contents[200]
                );
                assert_eq!(
                    msg.contents[201], 15,
                    "incorrect value for contents[201], expected 15, is {}",
                    msg.contents[201]
                );
                assert_eq!(
                    msg.contents[202], 248,
                    "incorrect value for contents[202], expected 248, is {}",
                    msg.contents[202]
                );
                assert_eq!(
                    msg.contents[203], 193,
                    "incorrect value for contents[203], expected 193, is {}",
                    msg.contents[203]
                );
                assert_eq!(
                    msg.contents[204], 66,
                    "incorrect value for contents[204], expected 66, is {}",
                    msg.contents[204]
                );
                assert_eq!(
                    msg.contents[205], 191,
                    "incorrect value for contents[205], expected 191, is {}",
                    msg.contents[205]
                );
                assert_eq!(
                    msg.contents[206], 244,
                    "incorrect value for contents[206], expected 244, is {}",
                    msg.contents[206]
                );
                assert_eq!(
                    msg.contents[207], 221,
                    "incorrect value for contents[207], expected 221, is {}",
                    msg.contents[207]
                );
                assert_eq!(
                    msg.contents[208], 248,
                    "incorrect value for contents[208], expected 248, is {}",
                    msg.contents[208]
                );
                assert_eq!(
                    msg.contents[209], 199,
                    "incorrect value for contents[209], expected 199, is {}",
                    msg.contents[209]
                );
                assert_eq!(
                    msg.contents[210], 241,
                    "incorrect value for contents[210], expected 241, is {}",
                    msg.contents[210]
                );
                assert_eq!(
                    msg.contents[211], 112,
                    "incorrect value for contents[211], expected 112, is {}",
                    msg.contents[211]
                );
                assert_eq!(
                    msg.contents[212], 51,
                    "incorrect value for contents[212], expected 51, is {}",
                    msg.contents[212]
                );
                assert_eq!(
                    msg.contents[213], 1,
                    "incorrect value for contents[213], expected 1, is {}",
                    msg.contents[213]
                );
                assert_eq!(
                    msg.contents[214], 180,
                    "incorrect value for contents[214], expected 180, is {}",
                    msg.contents[214]
                );
                assert_eq!(
                    msg.contents[215], 180,
                    "incorrect value for contents[215], expected 180, is {}",
                    msg.contents[215]
                );
                assert_eq!(
                    msg.contents[216], 125,
                    "incorrect value for contents[216], expected 125, is {}",
                    msg.contents[216]
                );
                assert_eq!(
                    msg.contents[217], 97,
                    "incorrect value for contents[217], expected 97, is {}",
                    msg.contents[217]
                );
                assert_eq!(
                    msg.contents[218], 145,
                    "incorrect value for contents[218], expected 145, is {}",
                    msg.contents[218]
                );
                assert_eq!(
                    msg.contents[219], 25,
                    "incorrect value for contents[219], expected 25, is {}",
                    msg.contents[219]
                );
                assert_eq!(
                    msg.contents[220], 72,
                    "incorrect value for contents[220], expected 72, is {}",
                    msg.contents[220]
                );
                assert_eq!(
                    msg.contents[221], 210,
                    "incorrect value for contents[221], expected 210, is {}",
                    msg.contents[221]
                );
                assert_eq!(
                    msg.contents[222], 215,
                    "incorrect value for contents[222], expected 215, is {}",
                    msg.contents[222]
                );
                assert_eq!(
                    msg.contents[223], 208,
                    "incorrect value for contents[223], expected 208, is {}",
                    msg.contents[223]
                );
                assert_eq!(
                    msg.contents[224], 15,
                    "incorrect value for contents[224], expected 15, is {}",
                    msg.contents[224]
                );
                assert_eq!(
                    msg.contents[225], 126,
                    "incorrect value for contents[225], expected 126, is {}",
                    msg.contents[225]
                );
                assert_eq!(
                    msg.contents[226], 56,
                    "incorrect value for contents[226], expected 56, is {}",
                    msg.contents[226]
                );
                assert_eq!(
                    msg.contents[227], 38,
                    "incorrect value for contents[227], expected 38, is {}",
                    msg.contents[227]
                );
                assert_eq!(
                    msg.contents[228], 65,
                    "incorrect value for contents[228], expected 65, is {}",
                    msg.contents[228]
                );
                assert_eq!(
                    msg.contents[229], 4,
                    "incorrect value for contents[229], expected 4, is {}",
                    msg.contents[229]
                );
                assert_eq!(
                    msg.contents[230], 64,
                    "incorrect value for contents[230], expected 64, is {}",
                    msg.contents[230]
                );
                assert_eq!(
                    msg.contents[231], 19,
                    "incorrect value for contents[231], expected 19, is {}",
                    msg.contents[231]
                );
                assert_eq!(
                    msg.contents[232], 74,
                    "incorrect value for contents[232], expected 74, is {}",
                    msg.contents[232]
                );
                assert_eq!(
                    msg.contents[233], 223,
                    "incorrect value for contents[233], expected 223, is {}",
                    msg.contents[233]
                );
                assert_eq!(
                    msg.contents[234], 111,
                    "incorrect value for contents[234], expected 111, is {}",
                    msg.contents[234]
                );
                assert_eq!(
                    msg.contents[235], 109,
                    "incorrect value for contents[235], expected 109, is {}",
                    msg.contents[235]
                );
                assert_eq!(
                    msg.contents[236], 52,
                    "incorrect value for contents[236], expected 52, is {}",
                    msg.contents[236]
                );
                assert_eq!(
                    msg.contents[237], 43,
                    "incorrect value for contents[237], expected 43, is {}",
                    msg.contents[237]
                );
                assert_eq!(
                    msg.contents[238], 167,
                    "incorrect value for contents[238], expected 167, is {}",
                    msg.contents[238]
                );
                assert_eq!(
                    msg.contents[239], 186,
                    "incorrect value for contents[239], expected 186, is {}",
                    msg.contents[239]
                );
                assert_eq!(
                    msg.contents[240], 202,
                    "incorrect value for contents[240], expected 202, is {}",
                    msg.contents[240]
                );
                assert_eq!(
                    msg.contents[241], 111,
                    "incorrect value for contents[241], expected 111, is {}",
                    msg.contents[241]
                );
                assert_eq!(
                    msg.contents[242], 11,
                    "incorrect value for contents[242], expected 11, is {}",
                    msg.contents[242]
                );
                assert_eq!(
                    msg.contents[243], 91,
                    "incorrect value for contents[243], expected 91, is {}",
                    msg.contents[243]
                );
                assert_eq!(
                    msg.contents[244], 21,
                    "incorrect value for contents[244], expected 21, is {}",
                    msg.contents[244]
                );
                assert_eq!(
                    msg.contents[245], 236,
                    "incorrect value for contents[245], expected 236, is {}",
                    msg.contents[245]
                );
                assert_eq!(
                    msg.contents[246], 234,
                    "incorrect value for contents[246], expected 234, is {}",
                    msg.contents[246]
                );
                assert_eq!(
                    msg.contents[247], 196,
                    "incorrect value for contents[247], expected 196, is {}",
                    msg.contents[247]
                );
                assert_eq!(
                    msg.contents[248], 36,
                    "incorrect value for contents[248], expected 36, is {}",
                    msg.contents[248]
                );
                assert_eq!(
                    msg.contents[249], 171,
                    "incorrect value for contents[249], expected 171, is {}",
                    msg.contents[249]
                );
                assert_eq!(
                    msg.contents[250], 147,
                    "incorrect value for contents[250], expected 147, is {}",
                    msg.contents[250]
                );
                assert_eq!(
                    msg.sequence, 259241795,
                    "incorrect value for sequence, expected 259241795, is {}",
                    msg.sequence
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFileioReadResp"),
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
fn test_json2sbp_auto_check_sbp_file_io_msg_fileio_read_resp() {
    {
        let json_input = r#"{"crc":61450,"length":255,"msg_type":163,"payload":"Q7dzD0nn47MSTETl2BVit0W+BfywNyBOCDR/MkdqPU+/ai5Pdvh2z87SW0n7UYPNwZLOuYz5o+dBQ176bZhfe03gfO7NQWcjaNEFvy/5sKbVLsBWIGeS/AQQNqE8Bg2/dLYqv9UU2QiOu+54uPoflyUzsYK+m0dEOO5cgiWJkvZydIql2U8KvYC9AvBcHH5p7OTCADM9SikK74Vqvh4bA/DN/XEZHLtRZdh5KbN4mBJ0NdRkAnLGyAqTGSFz0HE8s7cAKdnO/9Phjr+FUQ/4wUK/9N34x/FwMwG0tH1hkRlI0tfQD344JkEEQBNK329tNCunuspvC1sV7OrEJKuT","preamble":85,"sender":1219,"sequence":259241795,"contents":[73,231,227,179,18,76,68,229,216,21,98,183,69,190,5,252,176,55,32,78,8,52,127,50,71,106,61,79,191,106,46,79,118,248,118,207,206,210,91,73,251,81,131,205,193,146,206,185,140,249,163,231,65,67,94,250,109,152,95,123,77,224,124,238,205,65,103,35,104,209,5,191,47,249,176,166,213,46,192,86,32,103,146,252,4,16,54,161,60,6,13,191,116,182,42,191,213,20,217,8,142,187,238,120,184,250,31,151,37,51,177,130,190,155,71,68,56,238,92,130,37,137,146,246,114,116,138,165,217,79,10,189,128,189,2,240,92,28,126,105,236,228,194,0,51,61,74,41,10,239,133,106,190,30,27,3,240,205,253,113,25,28,187,81,101,216,121,41,179,120,152,18,116,53,212,100,2,114,198,200,10,147,25,33,115,208,113,60,179,183,0,41,217,206,255,211,225,142,191,133,81,15,248,193,66,191,244,221,248,199,241,112,51,1,180,180,125,97,145,25,72,210,215,208,15,126,56,38,65,4,64,19,74,223,111,109,52,43,167,186,202,111,11,91,21,236,234,196,36,171,147]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgFileioReadResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa3,
                    "Incorrect message type, expected 0xa3, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.contents[0], 73,
                    "incorrect value for contents[0], expected 73, is {}",
                    msg.contents[0]
                );
                assert_eq!(
                    msg.contents[1], 231,
                    "incorrect value for contents[1], expected 231, is {}",
                    msg.contents[1]
                );
                assert_eq!(
                    msg.contents[2], 227,
                    "incorrect value for contents[2], expected 227, is {}",
                    msg.contents[2]
                );
                assert_eq!(
                    msg.contents[3], 179,
                    "incorrect value for contents[3], expected 179, is {}",
                    msg.contents[3]
                );
                assert_eq!(
                    msg.contents[4], 18,
                    "incorrect value for contents[4], expected 18, is {}",
                    msg.contents[4]
                );
                assert_eq!(
                    msg.contents[5], 76,
                    "incorrect value for contents[5], expected 76, is {}",
                    msg.contents[5]
                );
                assert_eq!(
                    msg.contents[6], 68,
                    "incorrect value for contents[6], expected 68, is {}",
                    msg.contents[6]
                );
                assert_eq!(
                    msg.contents[7], 229,
                    "incorrect value for contents[7], expected 229, is {}",
                    msg.contents[7]
                );
                assert_eq!(
                    msg.contents[8], 216,
                    "incorrect value for contents[8], expected 216, is {}",
                    msg.contents[8]
                );
                assert_eq!(
                    msg.contents[9], 21,
                    "incorrect value for contents[9], expected 21, is {}",
                    msg.contents[9]
                );
                assert_eq!(
                    msg.contents[10], 98,
                    "incorrect value for contents[10], expected 98, is {}",
                    msg.contents[10]
                );
                assert_eq!(
                    msg.contents[11], 183,
                    "incorrect value for contents[11], expected 183, is {}",
                    msg.contents[11]
                );
                assert_eq!(
                    msg.contents[12], 69,
                    "incorrect value for contents[12], expected 69, is {}",
                    msg.contents[12]
                );
                assert_eq!(
                    msg.contents[13], 190,
                    "incorrect value for contents[13], expected 190, is {}",
                    msg.contents[13]
                );
                assert_eq!(
                    msg.contents[14], 5,
                    "incorrect value for contents[14], expected 5, is {}",
                    msg.contents[14]
                );
                assert_eq!(
                    msg.contents[15], 252,
                    "incorrect value for contents[15], expected 252, is {}",
                    msg.contents[15]
                );
                assert_eq!(
                    msg.contents[16], 176,
                    "incorrect value for contents[16], expected 176, is {}",
                    msg.contents[16]
                );
                assert_eq!(
                    msg.contents[17], 55,
                    "incorrect value for contents[17], expected 55, is {}",
                    msg.contents[17]
                );
                assert_eq!(
                    msg.contents[18], 32,
                    "incorrect value for contents[18], expected 32, is {}",
                    msg.contents[18]
                );
                assert_eq!(
                    msg.contents[19], 78,
                    "incorrect value for contents[19], expected 78, is {}",
                    msg.contents[19]
                );
                assert_eq!(
                    msg.contents[20], 8,
                    "incorrect value for contents[20], expected 8, is {}",
                    msg.contents[20]
                );
                assert_eq!(
                    msg.contents[21], 52,
                    "incorrect value for contents[21], expected 52, is {}",
                    msg.contents[21]
                );
                assert_eq!(
                    msg.contents[22], 127,
                    "incorrect value for contents[22], expected 127, is {}",
                    msg.contents[22]
                );
                assert_eq!(
                    msg.contents[23], 50,
                    "incorrect value for contents[23], expected 50, is {}",
                    msg.contents[23]
                );
                assert_eq!(
                    msg.contents[24], 71,
                    "incorrect value for contents[24], expected 71, is {}",
                    msg.contents[24]
                );
                assert_eq!(
                    msg.contents[25], 106,
                    "incorrect value for contents[25], expected 106, is {}",
                    msg.contents[25]
                );
                assert_eq!(
                    msg.contents[26], 61,
                    "incorrect value for contents[26], expected 61, is {}",
                    msg.contents[26]
                );
                assert_eq!(
                    msg.contents[27], 79,
                    "incorrect value for contents[27], expected 79, is {}",
                    msg.contents[27]
                );
                assert_eq!(
                    msg.contents[28], 191,
                    "incorrect value for contents[28], expected 191, is {}",
                    msg.contents[28]
                );
                assert_eq!(
                    msg.contents[29], 106,
                    "incorrect value for contents[29], expected 106, is {}",
                    msg.contents[29]
                );
                assert_eq!(
                    msg.contents[30], 46,
                    "incorrect value for contents[30], expected 46, is {}",
                    msg.contents[30]
                );
                assert_eq!(
                    msg.contents[31], 79,
                    "incorrect value for contents[31], expected 79, is {}",
                    msg.contents[31]
                );
                assert_eq!(
                    msg.contents[32], 118,
                    "incorrect value for contents[32], expected 118, is {}",
                    msg.contents[32]
                );
                assert_eq!(
                    msg.contents[33], 248,
                    "incorrect value for contents[33], expected 248, is {}",
                    msg.contents[33]
                );
                assert_eq!(
                    msg.contents[34], 118,
                    "incorrect value for contents[34], expected 118, is {}",
                    msg.contents[34]
                );
                assert_eq!(
                    msg.contents[35], 207,
                    "incorrect value for contents[35], expected 207, is {}",
                    msg.contents[35]
                );
                assert_eq!(
                    msg.contents[36], 206,
                    "incorrect value for contents[36], expected 206, is {}",
                    msg.contents[36]
                );
                assert_eq!(
                    msg.contents[37], 210,
                    "incorrect value for contents[37], expected 210, is {}",
                    msg.contents[37]
                );
                assert_eq!(
                    msg.contents[38], 91,
                    "incorrect value for contents[38], expected 91, is {}",
                    msg.contents[38]
                );
                assert_eq!(
                    msg.contents[39], 73,
                    "incorrect value for contents[39], expected 73, is {}",
                    msg.contents[39]
                );
                assert_eq!(
                    msg.contents[40], 251,
                    "incorrect value for contents[40], expected 251, is {}",
                    msg.contents[40]
                );
                assert_eq!(
                    msg.contents[41], 81,
                    "incorrect value for contents[41], expected 81, is {}",
                    msg.contents[41]
                );
                assert_eq!(
                    msg.contents[42], 131,
                    "incorrect value for contents[42], expected 131, is {}",
                    msg.contents[42]
                );
                assert_eq!(
                    msg.contents[43], 205,
                    "incorrect value for contents[43], expected 205, is {}",
                    msg.contents[43]
                );
                assert_eq!(
                    msg.contents[44], 193,
                    "incorrect value for contents[44], expected 193, is {}",
                    msg.contents[44]
                );
                assert_eq!(
                    msg.contents[45], 146,
                    "incorrect value for contents[45], expected 146, is {}",
                    msg.contents[45]
                );
                assert_eq!(
                    msg.contents[46], 206,
                    "incorrect value for contents[46], expected 206, is {}",
                    msg.contents[46]
                );
                assert_eq!(
                    msg.contents[47], 185,
                    "incorrect value for contents[47], expected 185, is {}",
                    msg.contents[47]
                );
                assert_eq!(
                    msg.contents[48], 140,
                    "incorrect value for contents[48], expected 140, is {}",
                    msg.contents[48]
                );
                assert_eq!(
                    msg.contents[49], 249,
                    "incorrect value for contents[49], expected 249, is {}",
                    msg.contents[49]
                );
                assert_eq!(
                    msg.contents[50], 163,
                    "incorrect value for contents[50], expected 163, is {}",
                    msg.contents[50]
                );
                assert_eq!(
                    msg.contents[51], 231,
                    "incorrect value for contents[51], expected 231, is {}",
                    msg.contents[51]
                );
                assert_eq!(
                    msg.contents[52], 65,
                    "incorrect value for contents[52], expected 65, is {}",
                    msg.contents[52]
                );
                assert_eq!(
                    msg.contents[53], 67,
                    "incorrect value for contents[53], expected 67, is {}",
                    msg.contents[53]
                );
                assert_eq!(
                    msg.contents[54], 94,
                    "incorrect value for contents[54], expected 94, is {}",
                    msg.contents[54]
                );
                assert_eq!(
                    msg.contents[55], 250,
                    "incorrect value for contents[55], expected 250, is {}",
                    msg.contents[55]
                );
                assert_eq!(
                    msg.contents[56], 109,
                    "incorrect value for contents[56], expected 109, is {}",
                    msg.contents[56]
                );
                assert_eq!(
                    msg.contents[57], 152,
                    "incorrect value for contents[57], expected 152, is {}",
                    msg.contents[57]
                );
                assert_eq!(
                    msg.contents[58], 95,
                    "incorrect value for contents[58], expected 95, is {}",
                    msg.contents[58]
                );
                assert_eq!(
                    msg.contents[59], 123,
                    "incorrect value for contents[59], expected 123, is {}",
                    msg.contents[59]
                );
                assert_eq!(
                    msg.contents[60], 77,
                    "incorrect value for contents[60], expected 77, is {}",
                    msg.contents[60]
                );
                assert_eq!(
                    msg.contents[61], 224,
                    "incorrect value for contents[61], expected 224, is {}",
                    msg.contents[61]
                );
                assert_eq!(
                    msg.contents[62], 124,
                    "incorrect value for contents[62], expected 124, is {}",
                    msg.contents[62]
                );
                assert_eq!(
                    msg.contents[63], 238,
                    "incorrect value for contents[63], expected 238, is {}",
                    msg.contents[63]
                );
                assert_eq!(
                    msg.contents[64], 205,
                    "incorrect value for contents[64], expected 205, is {}",
                    msg.contents[64]
                );
                assert_eq!(
                    msg.contents[65], 65,
                    "incorrect value for contents[65], expected 65, is {}",
                    msg.contents[65]
                );
                assert_eq!(
                    msg.contents[66], 103,
                    "incorrect value for contents[66], expected 103, is {}",
                    msg.contents[66]
                );
                assert_eq!(
                    msg.contents[67], 35,
                    "incorrect value for contents[67], expected 35, is {}",
                    msg.contents[67]
                );
                assert_eq!(
                    msg.contents[68], 104,
                    "incorrect value for contents[68], expected 104, is {}",
                    msg.contents[68]
                );
                assert_eq!(
                    msg.contents[69], 209,
                    "incorrect value for contents[69], expected 209, is {}",
                    msg.contents[69]
                );
                assert_eq!(
                    msg.contents[70], 5,
                    "incorrect value for contents[70], expected 5, is {}",
                    msg.contents[70]
                );
                assert_eq!(
                    msg.contents[71], 191,
                    "incorrect value for contents[71], expected 191, is {}",
                    msg.contents[71]
                );
                assert_eq!(
                    msg.contents[72], 47,
                    "incorrect value for contents[72], expected 47, is {}",
                    msg.contents[72]
                );
                assert_eq!(
                    msg.contents[73], 249,
                    "incorrect value for contents[73], expected 249, is {}",
                    msg.contents[73]
                );
                assert_eq!(
                    msg.contents[74], 176,
                    "incorrect value for contents[74], expected 176, is {}",
                    msg.contents[74]
                );
                assert_eq!(
                    msg.contents[75], 166,
                    "incorrect value for contents[75], expected 166, is {}",
                    msg.contents[75]
                );
                assert_eq!(
                    msg.contents[76], 213,
                    "incorrect value for contents[76], expected 213, is {}",
                    msg.contents[76]
                );
                assert_eq!(
                    msg.contents[77], 46,
                    "incorrect value for contents[77], expected 46, is {}",
                    msg.contents[77]
                );
                assert_eq!(
                    msg.contents[78], 192,
                    "incorrect value for contents[78], expected 192, is {}",
                    msg.contents[78]
                );
                assert_eq!(
                    msg.contents[79], 86,
                    "incorrect value for contents[79], expected 86, is {}",
                    msg.contents[79]
                );
                assert_eq!(
                    msg.contents[80], 32,
                    "incorrect value for contents[80], expected 32, is {}",
                    msg.contents[80]
                );
                assert_eq!(
                    msg.contents[81], 103,
                    "incorrect value for contents[81], expected 103, is {}",
                    msg.contents[81]
                );
                assert_eq!(
                    msg.contents[82], 146,
                    "incorrect value for contents[82], expected 146, is {}",
                    msg.contents[82]
                );
                assert_eq!(
                    msg.contents[83], 252,
                    "incorrect value for contents[83], expected 252, is {}",
                    msg.contents[83]
                );
                assert_eq!(
                    msg.contents[84], 4,
                    "incorrect value for contents[84], expected 4, is {}",
                    msg.contents[84]
                );
                assert_eq!(
                    msg.contents[85], 16,
                    "incorrect value for contents[85], expected 16, is {}",
                    msg.contents[85]
                );
                assert_eq!(
                    msg.contents[86], 54,
                    "incorrect value for contents[86], expected 54, is {}",
                    msg.contents[86]
                );
                assert_eq!(
                    msg.contents[87], 161,
                    "incorrect value for contents[87], expected 161, is {}",
                    msg.contents[87]
                );
                assert_eq!(
                    msg.contents[88], 60,
                    "incorrect value for contents[88], expected 60, is {}",
                    msg.contents[88]
                );
                assert_eq!(
                    msg.contents[89], 6,
                    "incorrect value for contents[89], expected 6, is {}",
                    msg.contents[89]
                );
                assert_eq!(
                    msg.contents[90], 13,
                    "incorrect value for contents[90], expected 13, is {}",
                    msg.contents[90]
                );
                assert_eq!(
                    msg.contents[91], 191,
                    "incorrect value for contents[91], expected 191, is {}",
                    msg.contents[91]
                );
                assert_eq!(
                    msg.contents[92], 116,
                    "incorrect value for contents[92], expected 116, is {}",
                    msg.contents[92]
                );
                assert_eq!(
                    msg.contents[93], 182,
                    "incorrect value for contents[93], expected 182, is {}",
                    msg.contents[93]
                );
                assert_eq!(
                    msg.contents[94], 42,
                    "incorrect value for contents[94], expected 42, is {}",
                    msg.contents[94]
                );
                assert_eq!(
                    msg.contents[95], 191,
                    "incorrect value for contents[95], expected 191, is {}",
                    msg.contents[95]
                );
                assert_eq!(
                    msg.contents[96], 213,
                    "incorrect value for contents[96], expected 213, is {}",
                    msg.contents[96]
                );
                assert_eq!(
                    msg.contents[97], 20,
                    "incorrect value for contents[97], expected 20, is {}",
                    msg.contents[97]
                );
                assert_eq!(
                    msg.contents[98], 217,
                    "incorrect value for contents[98], expected 217, is {}",
                    msg.contents[98]
                );
                assert_eq!(
                    msg.contents[99], 8,
                    "incorrect value for contents[99], expected 8, is {}",
                    msg.contents[99]
                );
                assert_eq!(
                    msg.contents[100], 142,
                    "incorrect value for contents[100], expected 142, is {}",
                    msg.contents[100]
                );
                assert_eq!(
                    msg.contents[101], 187,
                    "incorrect value for contents[101], expected 187, is {}",
                    msg.contents[101]
                );
                assert_eq!(
                    msg.contents[102], 238,
                    "incorrect value for contents[102], expected 238, is {}",
                    msg.contents[102]
                );
                assert_eq!(
                    msg.contents[103], 120,
                    "incorrect value for contents[103], expected 120, is {}",
                    msg.contents[103]
                );
                assert_eq!(
                    msg.contents[104], 184,
                    "incorrect value for contents[104], expected 184, is {}",
                    msg.contents[104]
                );
                assert_eq!(
                    msg.contents[105], 250,
                    "incorrect value for contents[105], expected 250, is {}",
                    msg.contents[105]
                );
                assert_eq!(
                    msg.contents[106], 31,
                    "incorrect value for contents[106], expected 31, is {}",
                    msg.contents[106]
                );
                assert_eq!(
                    msg.contents[107], 151,
                    "incorrect value for contents[107], expected 151, is {}",
                    msg.contents[107]
                );
                assert_eq!(
                    msg.contents[108], 37,
                    "incorrect value for contents[108], expected 37, is {}",
                    msg.contents[108]
                );
                assert_eq!(
                    msg.contents[109], 51,
                    "incorrect value for contents[109], expected 51, is {}",
                    msg.contents[109]
                );
                assert_eq!(
                    msg.contents[110], 177,
                    "incorrect value for contents[110], expected 177, is {}",
                    msg.contents[110]
                );
                assert_eq!(
                    msg.contents[111], 130,
                    "incorrect value for contents[111], expected 130, is {}",
                    msg.contents[111]
                );
                assert_eq!(
                    msg.contents[112], 190,
                    "incorrect value for contents[112], expected 190, is {}",
                    msg.contents[112]
                );
                assert_eq!(
                    msg.contents[113], 155,
                    "incorrect value for contents[113], expected 155, is {}",
                    msg.contents[113]
                );
                assert_eq!(
                    msg.contents[114], 71,
                    "incorrect value for contents[114], expected 71, is {}",
                    msg.contents[114]
                );
                assert_eq!(
                    msg.contents[115], 68,
                    "incorrect value for contents[115], expected 68, is {}",
                    msg.contents[115]
                );
                assert_eq!(
                    msg.contents[116], 56,
                    "incorrect value for contents[116], expected 56, is {}",
                    msg.contents[116]
                );
                assert_eq!(
                    msg.contents[117], 238,
                    "incorrect value for contents[117], expected 238, is {}",
                    msg.contents[117]
                );
                assert_eq!(
                    msg.contents[118], 92,
                    "incorrect value for contents[118], expected 92, is {}",
                    msg.contents[118]
                );
                assert_eq!(
                    msg.contents[119], 130,
                    "incorrect value for contents[119], expected 130, is {}",
                    msg.contents[119]
                );
                assert_eq!(
                    msg.contents[120], 37,
                    "incorrect value for contents[120], expected 37, is {}",
                    msg.contents[120]
                );
                assert_eq!(
                    msg.contents[121], 137,
                    "incorrect value for contents[121], expected 137, is {}",
                    msg.contents[121]
                );
                assert_eq!(
                    msg.contents[122], 146,
                    "incorrect value for contents[122], expected 146, is {}",
                    msg.contents[122]
                );
                assert_eq!(
                    msg.contents[123], 246,
                    "incorrect value for contents[123], expected 246, is {}",
                    msg.contents[123]
                );
                assert_eq!(
                    msg.contents[124], 114,
                    "incorrect value for contents[124], expected 114, is {}",
                    msg.contents[124]
                );
                assert_eq!(
                    msg.contents[125], 116,
                    "incorrect value for contents[125], expected 116, is {}",
                    msg.contents[125]
                );
                assert_eq!(
                    msg.contents[126], 138,
                    "incorrect value for contents[126], expected 138, is {}",
                    msg.contents[126]
                );
                assert_eq!(
                    msg.contents[127], 165,
                    "incorrect value for contents[127], expected 165, is {}",
                    msg.contents[127]
                );
                assert_eq!(
                    msg.contents[128], 217,
                    "incorrect value for contents[128], expected 217, is {}",
                    msg.contents[128]
                );
                assert_eq!(
                    msg.contents[129], 79,
                    "incorrect value for contents[129], expected 79, is {}",
                    msg.contents[129]
                );
                assert_eq!(
                    msg.contents[130], 10,
                    "incorrect value for contents[130], expected 10, is {}",
                    msg.contents[130]
                );
                assert_eq!(
                    msg.contents[131], 189,
                    "incorrect value for contents[131], expected 189, is {}",
                    msg.contents[131]
                );
                assert_eq!(
                    msg.contents[132], 128,
                    "incorrect value for contents[132], expected 128, is {}",
                    msg.contents[132]
                );
                assert_eq!(
                    msg.contents[133], 189,
                    "incorrect value for contents[133], expected 189, is {}",
                    msg.contents[133]
                );
                assert_eq!(
                    msg.contents[134], 2,
                    "incorrect value for contents[134], expected 2, is {}",
                    msg.contents[134]
                );
                assert_eq!(
                    msg.contents[135], 240,
                    "incorrect value for contents[135], expected 240, is {}",
                    msg.contents[135]
                );
                assert_eq!(
                    msg.contents[136], 92,
                    "incorrect value for contents[136], expected 92, is {}",
                    msg.contents[136]
                );
                assert_eq!(
                    msg.contents[137], 28,
                    "incorrect value for contents[137], expected 28, is {}",
                    msg.contents[137]
                );
                assert_eq!(
                    msg.contents[138], 126,
                    "incorrect value for contents[138], expected 126, is {}",
                    msg.contents[138]
                );
                assert_eq!(
                    msg.contents[139], 105,
                    "incorrect value for contents[139], expected 105, is {}",
                    msg.contents[139]
                );
                assert_eq!(
                    msg.contents[140], 236,
                    "incorrect value for contents[140], expected 236, is {}",
                    msg.contents[140]
                );
                assert_eq!(
                    msg.contents[141], 228,
                    "incorrect value for contents[141], expected 228, is {}",
                    msg.contents[141]
                );
                assert_eq!(
                    msg.contents[142], 194,
                    "incorrect value for contents[142], expected 194, is {}",
                    msg.contents[142]
                );
                assert_eq!(
                    msg.contents[143], 0,
                    "incorrect value for contents[143], expected 0, is {}",
                    msg.contents[143]
                );
                assert_eq!(
                    msg.contents[144], 51,
                    "incorrect value for contents[144], expected 51, is {}",
                    msg.contents[144]
                );
                assert_eq!(
                    msg.contents[145], 61,
                    "incorrect value for contents[145], expected 61, is {}",
                    msg.contents[145]
                );
                assert_eq!(
                    msg.contents[146], 74,
                    "incorrect value for contents[146], expected 74, is {}",
                    msg.contents[146]
                );
                assert_eq!(
                    msg.contents[147], 41,
                    "incorrect value for contents[147], expected 41, is {}",
                    msg.contents[147]
                );
                assert_eq!(
                    msg.contents[148], 10,
                    "incorrect value for contents[148], expected 10, is {}",
                    msg.contents[148]
                );
                assert_eq!(
                    msg.contents[149], 239,
                    "incorrect value for contents[149], expected 239, is {}",
                    msg.contents[149]
                );
                assert_eq!(
                    msg.contents[150], 133,
                    "incorrect value for contents[150], expected 133, is {}",
                    msg.contents[150]
                );
                assert_eq!(
                    msg.contents[151], 106,
                    "incorrect value for contents[151], expected 106, is {}",
                    msg.contents[151]
                );
                assert_eq!(
                    msg.contents[152], 190,
                    "incorrect value for contents[152], expected 190, is {}",
                    msg.contents[152]
                );
                assert_eq!(
                    msg.contents[153], 30,
                    "incorrect value for contents[153], expected 30, is {}",
                    msg.contents[153]
                );
                assert_eq!(
                    msg.contents[154], 27,
                    "incorrect value for contents[154], expected 27, is {}",
                    msg.contents[154]
                );
                assert_eq!(
                    msg.contents[155], 3,
                    "incorrect value for contents[155], expected 3, is {}",
                    msg.contents[155]
                );
                assert_eq!(
                    msg.contents[156], 240,
                    "incorrect value for contents[156], expected 240, is {}",
                    msg.contents[156]
                );
                assert_eq!(
                    msg.contents[157], 205,
                    "incorrect value for contents[157], expected 205, is {}",
                    msg.contents[157]
                );
                assert_eq!(
                    msg.contents[158], 253,
                    "incorrect value for contents[158], expected 253, is {}",
                    msg.contents[158]
                );
                assert_eq!(
                    msg.contents[159], 113,
                    "incorrect value for contents[159], expected 113, is {}",
                    msg.contents[159]
                );
                assert_eq!(
                    msg.contents[160], 25,
                    "incorrect value for contents[160], expected 25, is {}",
                    msg.contents[160]
                );
                assert_eq!(
                    msg.contents[161], 28,
                    "incorrect value for contents[161], expected 28, is {}",
                    msg.contents[161]
                );
                assert_eq!(
                    msg.contents[162], 187,
                    "incorrect value for contents[162], expected 187, is {}",
                    msg.contents[162]
                );
                assert_eq!(
                    msg.contents[163], 81,
                    "incorrect value for contents[163], expected 81, is {}",
                    msg.contents[163]
                );
                assert_eq!(
                    msg.contents[164], 101,
                    "incorrect value for contents[164], expected 101, is {}",
                    msg.contents[164]
                );
                assert_eq!(
                    msg.contents[165], 216,
                    "incorrect value for contents[165], expected 216, is {}",
                    msg.contents[165]
                );
                assert_eq!(
                    msg.contents[166], 121,
                    "incorrect value for contents[166], expected 121, is {}",
                    msg.contents[166]
                );
                assert_eq!(
                    msg.contents[167], 41,
                    "incorrect value for contents[167], expected 41, is {}",
                    msg.contents[167]
                );
                assert_eq!(
                    msg.contents[168], 179,
                    "incorrect value for contents[168], expected 179, is {}",
                    msg.contents[168]
                );
                assert_eq!(
                    msg.contents[169], 120,
                    "incorrect value for contents[169], expected 120, is {}",
                    msg.contents[169]
                );
                assert_eq!(
                    msg.contents[170], 152,
                    "incorrect value for contents[170], expected 152, is {}",
                    msg.contents[170]
                );
                assert_eq!(
                    msg.contents[171], 18,
                    "incorrect value for contents[171], expected 18, is {}",
                    msg.contents[171]
                );
                assert_eq!(
                    msg.contents[172], 116,
                    "incorrect value for contents[172], expected 116, is {}",
                    msg.contents[172]
                );
                assert_eq!(
                    msg.contents[173], 53,
                    "incorrect value for contents[173], expected 53, is {}",
                    msg.contents[173]
                );
                assert_eq!(
                    msg.contents[174], 212,
                    "incorrect value for contents[174], expected 212, is {}",
                    msg.contents[174]
                );
                assert_eq!(
                    msg.contents[175], 100,
                    "incorrect value for contents[175], expected 100, is {}",
                    msg.contents[175]
                );
                assert_eq!(
                    msg.contents[176], 2,
                    "incorrect value for contents[176], expected 2, is {}",
                    msg.contents[176]
                );
                assert_eq!(
                    msg.contents[177], 114,
                    "incorrect value for contents[177], expected 114, is {}",
                    msg.contents[177]
                );
                assert_eq!(
                    msg.contents[178], 198,
                    "incorrect value for contents[178], expected 198, is {}",
                    msg.contents[178]
                );
                assert_eq!(
                    msg.contents[179], 200,
                    "incorrect value for contents[179], expected 200, is {}",
                    msg.contents[179]
                );
                assert_eq!(
                    msg.contents[180], 10,
                    "incorrect value for contents[180], expected 10, is {}",
                    msg.contents[180]
                );
                assert_eq!(
                    msg.contents[181], 147,
                    "incorrect value for contents[181], expected 147, is {}",
                    msg.contents[181]
                );
                assert_eq!(
                    msg.contents[182], 25,
                    "incorrect value for contents[182], expected 25, is {}",
                    msg.contents[182]
                );
                assert_eq!(
                    msg.contents[183], 33,
                    "incorrect value for contents[183], expected 33, is {}",
                    msg.contents[183]
                );
                assert_eq!(
                    msg.contents[184], 115,
                    "incorrect value for contents[184], expected 115, is {}",
                    msg.contents[184]
                );
                assert_eq!(
                    msg.contents[185], 208,
                    "incorrect value for contents[185], expected 208, is {}",
                    msg.contents[185]
                );
                assert_eq!(
                    msg.contents[186], 113,
                    "incorrect value for contents[186], expected 113, is {}",
                    msg.contents[186]
                );
                assert_eq!(
                    msg.contents[187], 60,
                    "incorrect value for contents[187], expected 60, is {}",
                    msg.contents[187]
                );
                assert_eq!(
                    msg.contents[188], 179,
                    "incorrect value for contents[188], expected 179, is {}",
                    msg.contents[188]
                );
                assert_eq!(
                    msg.contents[189], 183,
                    "incorrect value for contents[189], expected 183, is {}",
                    msg.contents[189]
                );
                assert_eq!(
                    msg.contents[190], 0,
                    "incorrect value for contents[190], expected 0, is {}",
                    msg.contents[190]
                );
                assert_eq!(
                    msg.contents[191], 41,
                    "incorrect value for contents[191], expected 41, is {}",
                    msg.contents[191]
                );
                assert_eq!(
                    msg.contents[192], 217,
                    "incorrect value for contents[192], expected 217, is {}",
                    msg.contents[192]
                );
                assert_eq!(
                    msg.contents[193], 206,
                    "incorrect value for contents[193], expected 206, is {}",
                    msg.contents[193]
                );
                assert_eq!(
                    msg.contents[194], 255,
                    "incorrect value for contents[194], expected 255, is {}",
                    msg.contents[194]
                );
                assert_eq!(
                    msg.contents[195], 211,
                    "incorrect value for contents[195], expected 211, is {}",
                    msg.contents[195]
                );
                assert_eq!(
                    msg.contents[196], 225,
                    "incorrect value for contents[196], expected 225, is {}",
                    msg.contents[196]
                );
                assert_eq!(
                    msg.contents[197], 142,
                    "incorrect value for contents[197], expected 142, is {}",
                    msg.contents[197]
                );
                assert_eq!(
                    msg.contents[198], 191,
                    "incorrect value for contents[198], expected 191, is {}",
                    msg.contents[198]
                );
                assert_eq!(
                    msg.contents[199], 133,
                    "incorrect value for contents[199], expected 133, is {}",
                    msg.contents[199]
                );
                assert_eq!(
                    msg.contents[200], 81,
                    "incorrect value for contents[200], expected 81, is {}",
                    msg.contents[200]
                );
                assert_eq!(
                    msg.contents[201], 15,
                    "incorrect value for contents[201], expected 15, is {}",
                    msg.contents[201]
                );
                assert_eq!(
                    msg.contents[202], 248,
                    "incorrect value for contents[202], expected 248, is {}",
                    msg.contents[202]
                );
                assert_eq!(
                    msg.contents[203], 193,
                    "incorrect value for contents[203], expected 193, is {}",
                    msg.contents[203]
                );
                assert_eq!(
                    msg.contents[204], 66,
                    "incorrect value for contents[204], expected 66, is {}",
                    msg.contents[204]
                );
                assert_eq!(
                    msg.contents[205], 191,
                    "incorrect value for contents[205], expected 191, is {}",
                    msg.contents[205]
                );
                assert_eq!(
                    msg.contents[206], 244,
                    "incorrect value for contents[206], expected 244, is {}",
                    msg.contents[206]
                );
                assert_eq!(
                    msg.contents[207], 221,
                    "incorrect value for contents[207], expected 221, is {}",
                    msg.contents[207]
                );
                assert_eq!(
                    msg.contents[208], 248,
                    "incorrect value for contents[208], expected 248, is {}",
                    msg.contents[208]
                );
                assert_eq!(
                    msg.contents[209], 199,
                    "incorrect value for contents[209], expected 199, is {}",
                    msg.contents[209]
                );
                assert_eq!(
                    msg.contents[210], 241,
                    "incorrect value for contents[210], expected 241, is {}",
                    msg.contents[210]
                );
                assert_eq!(
                    msg.contents[211], 112,
                    "incorrect value for contents[211], expected 112, is {}",
                    msg.contents[211]
                );
                assert_eq!(
                    msg.contents[212], 51,
                    "incorrect value for contents[212], expected 51, is {}",
                    msg.contents[212]
                );
                assert_eq!(
                    msg.contents[213], 1,
                    "incorrect value for contents[213], expected 1, is {}",
                    msg.contents[213]
                );
                assert_eq!(
                    msg.contents[214], 180,
                    "incorrect value for contents[214], expected 180, is {}",
                    msg.contents[214]
                );
                assert_eq!(
                    msg.contents[215], 180,
                    "incorrect value for contents[215], expected 180, is {}",
                    msg.contents[215]
                );
                assert_eq!(
                    msg.contents[216], 125,
                    "incorrect value for contents[216], expected 125, is {}",
                    msg.contents[216]
                );
                assert_eq!(
                    msg.contents[217], 97,
                    "incorrect value for contents[217], expected 97, is {}",
                    msg.contents[217]
                );
                assert_eq!(
                    msg.contents[218], 145,
                    "incorrect value for contents[218], expected 145, is {}",
                    msg.contents[218]
                );
                assert_eq!(
                    msg.contents[219], 25,
                    "incorrect value for contents[219], expected 25, is {}",
                    msg.contents[219]
                );
                assert_eq!(
                    msg.contents[220], 72,
                    "incorrect value for contents[220], expected 72, is {}",
                    msg.contents[220]
                );
                assert_eq!(
                    msg.contents[221], 210,
                    "incorrect value for contents[221], expected 210, is {}",
                    msg.contents[221]
                );
                assert_eq!(
                    msg.contents[222], 215,
                    "incorrect value for contents[222], expected 215, is {}",
                    msg.contents[222]
                );
                assert_eq!(
                    msg.contents[223], 208,
                    "incorrect value for contents[223], expected 208, is {}",
                    msg.contents[223]
                );
                assert_eq!(
                    msg.contents[224], 15,
                    "incorrect value for contents[224], expected 15, is {}",
                    msg.contents[224]
                );
                assert_eq!(
                    msg.contents[225], 126,
                    "incorrect value for contents[225], expected 126, is {}",
                    msg.contents[225]
                );
                assert_eq!(
                    msg.contents[226], 56,
                    "incorrect value for contents[226], expected 56, is {}",
                    msg.contents[226]
                );
                assert_eq!(
                    msg.contents[227], 38,
                    "incorrect value for contents[227], expected 38, is {}",
                    msg.contents[227]
                );
                assert_eq!(
                    msg.contents[228], 65,
                    "incorrect value for contents[228], expected 65, is {}",
                    msg.contents[228]
                );
                assert_eq!(
                    msg.contents[229], 4,
                    "incorrect value for contents[229], expected 4, is {}",
                    msg.contents[229]
                );
                assert_eq!(
                    msg.contents[230], 64,
                    "incorrect value for contents[230], expected 64, is {}",
                    msg.contents[230]
                );
                assert_eq!(
                    msg.contents[231], 19,
                    "incorrect value for contents[231], expected 19, is {}",
                    msg.contents[231]
                );
                assert_eq!(
                    msg.contents[232], 74,
                    "incorrect value for contents[232], expected 74, is {}",
                    msg.contents[232]
                );
                assert_eq!(
                    msg.contents[233], 223,
                    "incorrect value for contents[233], expected 223, is {}",
                    msg.contents[233]
                );
                assert_eq!(
                    msg.contents[234], 111,
                    "incorrect value for contents[234], expected 111, is {}",
                    msg.contents[234]
                );
                assert_eq!(
                    msg.contents[235], 109,
                    "incorrect value for contents[235], expected 109, is {}",
                    msg.contents[235]
                );
                assert_eq!(
                    msg.contents[236], 52,
                    "incorrect value for contents[236], expected 52, is {}",
                    msg.contents[236]
                );
                assert_eq!(
                    msg.contents[237], 43,
                    "incorrect value for contents[237], expected 43, is {}",
                    msg.contents[237]
                );
                assert_eq!(
                    msg.contents[238], 167,
                    "incorrect value for contents[238], expected 167, is {}",
                    msg.contents[238]
                );
                assert_eq!(
                    msg.contents[239], 186,
                    "incorrect value for contents[239], expected 186, is {}",
                    msg.contents[239]
                );
                assert_eq!(
                    msg.contents[240], 202,
                    "incorrect value for contents[240], expected 202, is {}",
                    msg.contents[240]
                );
                assert_eq!(
                    msg.contents[241], 111,
                    "incorrect value for contents[241], expected 111, is {}",
                    msg.contents[241]
                );
                assert_eq!(
                    msg.contents[242], 11,
                    "incorrect value for contents[242], expected 11, is {}",
                    msg.contents[242]
                );
                assert_eq!(
                    msg.contents[243], 91,
                    "incorrect value for contents[243], expected 91, is {}",
                    msg.contents[243]
                );
                assert_eq!(
                    msg.contents[244], 21,
                    "incorrect value for contents[244], expected 21, is {}",
                    msg.contents[244]
                );
                assert_eq!(
                    msg.contents[245], 236,
                    "incorrect value for contents[245], expected 236, is {}",
                    msg.contents[245]
                );
                assert_eq!(
                    msg.contents[246], 234,
                    "incorrect value for contents[246], expected 234, is {}",
                    msg.contents[246]
                );
                assert_eq!(
                    msg.contents[247], 196,
                    "incorrect value for contents[247], expected 196, is {}",
                    msg.contents[247]
                );
                assert_eq!(
                    msg.contents[248], 36,
                    "incorrect value for contents[248], expected 36, is {}",
                    msg.contents[248]
                );
                assert_eq!(
                    msg.contents[249], 171,
                    "incorrect value for contents[249], expected 171, is {}",
                    msg.contents[249]
                );
                assert_eq!(
                    msg.contents[250], 147,
                    "incorrect value for contents[250], expected 147, is {}",
                    msg.contents[250]
                );
                assert_eq!(
                    msg.sequence, 259241795,
                    "incorrect value for sequence, expected 259241795, is {}",
                    msg.sequence
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFileioReadResp"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_file_io_msg_fileio_read_resp`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_file_io_msg_fileio_read_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 163, 0, 195, 4, 255, 67, 183, 115, 15, 73, 231, 227, 179, 18, 76, 68, 229, 216, 21,
            98, 183, 69, 190, 5, 252, 176, 55, 32, 78, 8, 52, 127, 50, 71, 106, 61, 79, 191, 106,
            46, 79, 118, 248, 118, 207, 206, 210, 91, 73, 251, 81, 131, 205, 193, 146, 206, 185,
            140, 249, 163, 231, 65, 67, 94, 250, 109, 152, 95, 123, 77, 224, 124, 238, 205, 65,
            103, 35, 104, 209, 5, 191, 47, 249, 176, 166, 213, 46, 192, 86, 32, 103, 146, 252, 4,
            16, 54, 161, 60, 6, 13, 191, 116, 182, 42, 191, 213, 20, 217, 8, 142, 187, 238, 120,
            184, 250, 31, 151, 37, 51, 177, 130, 190, 155, 71, 68, 56, 238, 92, 130, 37, 137, 146,
            246, 114, 116, 138, 165, 217, 79, 10, 189, 128, 189, 2, 240, 92, 28, 126, 105, 236,
            228, 194, 0, 51, 61, 74, 41, 10, 239, 133, 106, 190, 30, 27, 3, 240, 205, 253, 113, 25,
            28, 187, 81, 101, 216, 121, 41, 179, 120, 152, 18, 116, 53, 212, 100, 2, 114, 198, 200,
            10, 147, 25, 33, 115, 208, 113, 60, 179, 183, 0, 41, 217, 206, 255, 211, 225, 142, 191,
            133, 81, 15, 248, 193, 66, 191, 244, 221, 248, 199, 241, 112, 51, 1, 180, 180, 125, 97,
            145, 25, 72, 210, 215, 208, 15, 126, 56, 38, 65, 4, 64, 19, 74, 223, 111, 109, 52, 43,
            167, 186, 202, 111, 11, 91, 21, 236, 234, 196, 36, 171, 147, 10, 240,
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
        let sbp_msg = sbp::messages::Sbp::MsgFileioReadResp(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgFileioReadResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xa3,
                    "Incorrect message type, expected 0xa3, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.contents[0], 73,
                    "incorrect value for contents[0], expected 73, is {}",
                    msg.contents[0]
                );
                assert_eq!(
                    msg.contents[1], 231,
                    "incorrect value for contents[1], expected 231, is {}",
                    msg.contents[1]
                );
                assert_eq!(
                    msg.contents[2], 227,
                    "incorrect value for contents[2], expected 227, is {}",
                    msg.contents[2]
                );
                assert_eq!(
                    msg.contents[3], 179,
                    "incorrect value for contents[3], expected 179, is {}",
                    msg.contents[3]
                );
                assert_eq!(
                    msg.contents[4], 18,
                    "incorrect value for contents[4], expected 18, is {}",
                    msg.contents[4]
                );
                assert_eq!(
                    msg.contents[5], 76,
                    "incorrect value for contents[5], expected 76, is {}",
                    msg.contents[5]
                );
                assert_eq!(
                    msg.contents[6], 68,
                    "incorrect value for contents[6], expected 68, is {}",
                    msg.contents[6]
                );
                assert_eq!(
                    msg.contents[7], 229,
                    "incorrect value for contents[7], expected 229, is {}",
                    msg.contents[7]
                );
                assert_eq!(
                    msg.contents[8], 216,
                    "incorrect value for contents[8], expected 216, is {}",
                    msg.contents[8]
                );
                assert_eq!(
                    msg.contents[9], 21,
                    "incorrect value for contents[9], expected 21, is {}",
                    msg.contents[9]
                );
                assert_eq!(
                    msg.contents[10], 98,
                    "incorrect value for contents[10], expected 98, is {}",
                    msg.contents[10]
                );
                assert_eq!(
                    msg.contents[11], 183,
                    "incorrect value for contents[11], expected 183, is {}",
                    msg.contents[11]
                );
                assert_eq!(
                    msg.contents[12], 69,
                    "incorrect value for contents[12], expected 69, is {}",
                    msg.contents[12]
                );
                assert_eq!(
                    msg.contents[13], 190,
                    "incorrect value for contents[13], expected 190, is {}",
                    msg.contents[13]
                );
                assert_eq!(
                    msg.contents[14], 5,
                    "incorrect value for contents[14], expected 5, is {}",
                    msg.contents[14]
                );
                assert_eq!(
                    msg.contents[15], 252,
                    "incorrect value for contents[15], expected 252, is {}",
                    msg.contents[15]
                );
                assert_eq!(
                    msg.contents[16], 176,
                    "incorrect value for contents[16], expected 176, is {}",
                    msg.contents[16]
                );
                assert_eq!(
                    msg.contents[17], 55,
                    "incorrect value for contents[17], expected 55, is {}",
                    msg.contents[17]
                );
                assert_eq!(
                    msg.contents[18], 32,
                    "incorrect value for contents[18], expected 32, is {}",
                    msg.contents[18]
                );
                assert_eq!(
                    msg.contents[19], 78,
                    "incorrect value for contents[19], expected 78, is {}",
                    msg.contents[19]
                );
                assert_eq!(
                    msg.contents[20], 8,
                    "incorrect value for contents[20], expected 8, is {}",
                    msg.contents[20]
                );
                assert_eq!(
                    msg.contents[21], 52,
                    "incorrect value for contents[21], expected 52, is {}",
                    msg.contents[21]
                );
                assert_eq!(
                    msg.contents[22], 127,
                    "incorrect value for contents[22], expected 127, is {}",
                    msg.contents[22]
                );
                assert_eq!(
                    msg.contents[23], 50,
                    "incorrect value for contents[23], expected 50, is {}",
                    msg.contents[23]
                );
                assert_eq!(
                    msg.contents[24], 71,
                    "incorrect value for contents[24], expected 71, is {}",
                    msg.contents[24]
                );
                assert_eq!(
                    msg.contents[25], 106,
                    "incorrect value for contents[25], expected 106, is {}",
                    msg.contents[25]
                );
                assert_eq!(
                    msg.contents[26], 61,
                    "incorrect value for contents[26], expected 61, is {}",
                    msg.contents[26]
                );
                assert_eq!(
                    msg.contents[27], 79,
                    "incorrect value for contents[27], expected 79, is {}",
                    msg.contents[27]
                );
                assert_eq!(
                    msg.contents[28], 191,
                    "incorrect value for contents[28], expected 191, is {}",
                    msg.contents[28]
                );
                assert_eq!(
                    msg.contents[29], 106,
                    "incorrect value for contents[29], expected 106, is {}",
                    msg.contents[29]
                );
                assert_eq!(
                    msg.contents[30], 46,
                    "incorrect value for contents[30], expected 46, is {}",
                    msg.contents[30]
                );
                assert_eq!(
                    msg.contents[31], 79,
                    "incorrect value for contents[31], expected 79, is {}",
                    msg.contents[31]
                );
                assert_eq!(
                    msg.contents[32], 118,
                    "incorrect value for contents[32], expected 118, is {}",
                    msg.contents[32]
                );
                assert_eq!(
                    msg.contents[33], 248,
                    "incorrect value for contents[33], expected 248, is {}",
                    msg.contents[33]
                );
                assert_eq!(
                    msg.contents[34], 118,
                    "incorrect value for contents[34], expected 118, is {}",
                    msg.contents[34]
                );
                assert_eq!(
                    msg.contents[35], 207,
                    "incorrect value for contents[35], expected 207, is {}",
                    msg.contents[35]
                );
                assert_eq!(
                    msg.contents[36], 206,
                    "incorrect value for contents[36], expected 206, is {}",
                    msg.contents[36]
                );
                assert_eq!(
                    msg.contents[37], 210,
                    "incorrect value for contents[37], expected 210, is {}",
                    msg.contents[37]
                );
                assert_eq!(
                    msg.contents[38], 91,
                    "incorrect value for contents[38], expected 91, is {}",
                    msg.contents[38]
                );
                assert_eq!(
                    msg.contents[39], 73,
                    "incorrect value for contents[39], expected 73, is {}",
                    msg.contents[39]
                );
                assert_eq!(
                    msg.contents[40], 251,
                    "incorrect value for contents[40], expected 251, is {}",
                    msg.contents[40]
                );
                assert_eq!(
                    msg.contents[41], 81,
                    "incorrect value for contents[41], expected 81, is {}",
                    msg.contents[41]
                );
                assert_eq!(
                    msg.contents[42], 131,
                    "incorrect value for contents[42], expected 131, is {}",
                    msg.contents[42]
                );
                assert_eq!(
                    msg.contents[43], 205,
                    "incorrect value for contents[43], expected 205, is {}",
                    msg.contents[43]
                );
                assert_eq!(
                    msg.contents[44], 193,
                    "incorrect value for contents[44], expected 193, is {}",
                    msg.contents[44]
                );
                assert_eq!(
                    msg.contents[45], 146,
                    "incorrect value for contents[45], expected 146, is {}",
                    msg.contents[45]
                );
                assert_eq!(
                    msg.contents[46], 206,
                    "incorrect value for contents[46], expected 206, is {}",
                    msg.contents[46]
                );
                assert_eq!(
                    msg.contents[47], 185,
                    "incorrect value for contents[47], expected 185, is {}",
                    msg.contents[47]
                );
                assert_eq!(
                    msg.contents[48], 140,
                    "incorrect value for contents[48], expected 140, is {}",
                    msg.contents[48]
                );
                assert_eq!(
                    msg.contents[49], 249,
                    "incorrect value for contents[49], expected 249, is {}",
                    msg.contents[49]
                );
                assert_eq!(
                    msg.contents[50], 163,
                    "incorrect value for contents[50], expected 163, is {}",
                    msg.contents[50]
                );
                assert_eq!(
                    msg.contents[51], 231,
                    "incorrect value for contents[51], expected 231, is {}",
                    msg.contents[51]
                );
                assert_eq!(
                    msg.contents[52], 65,
                    "incorrect value for contents[52], expected 65, is {}",
                    msg.contents[52]
                );
                assert_eq!(
                    msg.contents[53], 67,
                    "incorrect value for contents[53], expected 67, is {}",
                    msg.contents[53]
                );
                assert_eq!(
                    msg.contents[54], 94,
                    "incorrect value for contents[54], expected 94, is {}",
                    msg.contents[54]
                );
                assert_eq!(
                    msg.contents[55], 250,
                    "incorrect value for contents[55], expected 250, is {}",
                    msg.contents[55]
                );
                assert_eq!(
                    msg.contents[56], 109,
                    "incorrect value for contents[56], expected 109, is {}",
                    msg.contents[56]
                );
                assert_eq!(
                    msg.contents[57], 152,
                    "incorrect value for contents[57], expected 152, is {}",
                    msg.contents[57]
                );
                assert_eq!(
                    msg.contents[58], 95,
                    "incorrect value for contents[58], expected 95, is {}",
                    msg.contents[58]
                );
                assert_eq!(
                    msg.contents[59], 123,
                    "incorrect value for contents[59], expected 123, is {}",
                    msg.contents[59]
                );
                assert_eq!(
                    msg.contents[60], 77,
                    "incorrect value for contents[60], expected 77, is {}",
                    msg.contents[60]
                );
                assert_eq!(
                    msg.contents[61], 224,
                    "incorrect value for contents[61], expected 224, is {}",
                    msg.contents[61]
                );
                assert_eq!(
                    msg.contents[62], 124,
                    "incorrect value for contents[62], expected 124, is {}",
                    msg.contents[62]
                );
                assert_eq!(
                    msg.contents[63], 238,
                    "incorrect value for contents[63], expected 238, is {}",
                    msg.contents[63]
                );
                assert_eq!(
                    msg.contents[64], 205,
                    "incorrect value for contents[64], expected 205, is {}",
                    msg.contents[64]
                );
                assert_eq!(
                    msg.contents[65], 65,
                    "incorrect value for contents[65], expected 65, is {}",
                    msg.contents[65]
                );
                assert_eq!(
                    msg.contents[66], 103,
                    "incorrect value for contents[66], expected 103, is {}",
                    msg.contents[66]
                );
                assert_eq!(
                    msg.contents[67], 35,
                    "incorrect value for contents[67], expected 35, is {}",
                    msg.contents[67]
                );
                assert_eq!(
                    msg.contents[68], 104,
                    "incorrect value for contents[68], expected 104, is {}",
                    msg.contents[68]
                );
                assert_eq!(
                    msg.contents[69], 209,
                    "incorrect value for contents[69], expected 209, is {}",
                    msg.contents[69]
                );
                assert_eq!(
                    msg.contents[70], 5,
                    "incorrect value for contents[70], expected 5, is {}",
                    msg.contents[70]
                );
                assert_eq!(
                    msg.contents[71], 191,
                    "incorrect value for contents[71], expected 191, is {}",
                    msg.contents[71]
                );
                assert_eq!(
                    msg.contents[72], 47,
                    "incorrect value for contents[72], expected 47, is {}",
                    msg.contents[72]
                );
                assert_eq!(
                    msg.contents[73], 249,
                    "incorrect value for contents[73], expected 249, is {}",
                    msg.contents[73]
                );
                assert_eq!(
                    msg.contents[74], 176,
                    "incorrect value for contents[74], expected 176, is {}",
                    msg.contents[74]
                );
                assert_eq!(
                    msg.contents[75], 166,
                    "incorrect value for contents[75], expected 166, is {}",
                    msg.contents[75]
                );
                assert_eq!(
                    msg.contents[76], 213,
                    "incorrect value for contents[76], expected 213, is {}",
                    msg.contents[76]
                );
                assert_eq!(
                    msg.contents[77], 46,
                    "incorrect value for contents[77], expected 46, is {}",
                    msg.contents[77]
                );
                assert_eq!(
                    msg.contents[78], 192,
                    "incorrect value for contents[78], expected 192, is {}",
                    msg.contents[78]
                );
                assert_eq!(
                    msg.contents[79], 86,
                    "incorrect value for contents[79], expected 86, is {}",
                    msg.contents[79]
                );
                assert_eq!(
                    msg.contents[80], 32,
                    "incorrect value for contents[80], expected 32, is {}",
                    msg.contents[80]
                );
                assert_eq!(
                    msg.contents[81], 103,
                    "incorrect value for contents[81], expected 103, is {}",
                    msg.contents[81]
                );
                assert_eq!(
                    msg.contents[82], 146,
                    "incorrect value for contents[82], expected 146, is {}",
                    msg.contents[82]
                );
                assert_eq!(
                    msg.contents[83], 252,
                    "incorrect value for contents[83], expected 252, is {}",
                    msg.contents[83]
                );
                assert_eq!(
                    msg.contents[84], 4,
                    "incorrect value for contents[84], expected 4, is {}",
                    msg.contents[84]
                );
                assert_eq!(
                    msg.contents[85], 16,
                    "incorrect value for contents[85], expected 16, is {}",
                    msg.contents[85]
                );
                assert_eq!(
                    msg.contents[86], 54,
                    "incorrect value for contents[86], expected 54, is {}",
                    msg.contents[86]
                );
                assert_eq!(
                    msg.contents[87], 161,
                    "incorrect value for contents[87], expected 161, is {}",
                    msg.contents[87]
                );
                assert_eq!(
                    msg.contents[88], 60,
                    "incorrect value for contents[88], expected 60, is {}",
                    msg.contents[88]
                );
                assert_eq!(
                    msg.contents[89], 6,
                    "incorrect value for contents[89], expected 6, is {}",
                    msg.contents[89]
                );
                assert_eq!(
                    msg.contents[90], 13,
                    "incorrect value for contents[90], expected 13, is {}",
                    msg.contents[90]
                );
                assert_eq!(
                    msg.contents[91], 191,
                    "incorrect value for contents[91], expected 191, is {}",
                    msg.contents[91]
                );
                assert_eq!(
                    msg.contents[92], 116,
                    "incorrect value for contents[92], expected 116, is {}",
                    msg.contents[92]
                );
                assert_eq!(
                    msg.contents[93], 182,
                    "incorrect value for contents[93], expected 182, is {}",
                    msg.contents[93]
                );
                assert_eq!(
                    msg.contents[94], 42,
                    "incorrect value for contents[94], expected 42, is {}",
                    msg.contents[94]
                );
                assert_eq!(
                    msg.contents[95], 191,
                    "incorrect value for contents[95], expected 191, is {}",
                    msg.contents[95]
                );
                assert_eq!(
                    msg.contents[96], 213,
                    "incorrect value for contents[96], expected 213, is {}",
                    msg.contents[96]
                );
                assert_eq!(
                    msg.contents[97], 20,
                    "incorrect value for contents[97], expected 20, is {}",
                    msg.contents[97]
                );
                assert_eq!(
                    msg.contents[98], 217,
                    "incorrect value for contents[98], expected 217, is {}",
                    msg.contents[98]
                );
                assert_eq!(
                    msg.contents[99], 8,
                    "incorrect value for contents[99], expected 8, is {}",
                    msg.contents[99]
                );
                assert_eq!(
                    msg.contents[100], 142,
                    "incorrect value for contents[100], expected 142, is {}",
                    msg.contents[100]
                );
                assert_eq!(
                    msg.contents[101], 187,
                    "incorrect value for contents[101], expected 187, is {}",
                    msg.contents[101]
                );
                assert_eq!(
                    msg.contents[102], 238,
                    "incorrect value for contents[102], expected 238, is {}",
                    msg.contents[102]
                );
                assert_eq!(
                    msg.contents[103], 120,
                    "incorrect value for contents[103], expected 120, is {}",
                    msg.contents[103]
                );
                assert_eq!(
                    msg.contents[104], 184,
                    "incorrect value for contents[104], expected 184, is {}",
                    msg.contents[104]
                );
                assert_eq!(
                    msg.contents[105], 250,
                    "incorrect value for contents[105], expected 250, is {}",
                    msg.contents[105]
                );
                assert_eq!(
                    msg.contents[106], 31,
                    "incorrect value for contents[106], expected 31, is {}",
                    msg.contents[106]
                );
                assert_eq!(
                    msg.contents[107], 151,
                    "incorrect value for contents[107], expected 151, is {}",
                    msg.contents[107]
                );
                assert_eq!(
                    msg.contents[108], 37,
                    "incorrect value for contents[108], expected 37, is {}",
                    msg.contents[108]
                );
                assert_eq!(
                    msg.contents[109], 51,
                    "incorrect value for contents[109], expected 51, is {}",
                    msg.contents[109]
                );
                assert_eq!(
                    msg.contents[110], 177,
                    "incorrect value for contents[110], expected 177, is {}",
                    msg.contents[110]
                );
                assert_eq!(
                    msg.contents[111], 130,
                    "incorrect value for contents[111], expected 130, is {}",
                    msg.contents[111]
                );
                assert_eq!(
                    msg.contents[112], 190,
                    "incorrect value for contents[112], expected 190, is {}",
                    msg.contents[112]
                );
                assert_eq!(
                    msg.contents[113], 155,
                    "incorrect value for contents[113], expected 155, is {}",
                    msg.contents[113]
                );
                assert_eq!(
                    msg.contents[114], 71,
                    "incorrect value for contents[114], expected 71, is {}",
                    msg.contents[114]
                );
                assert_eq!(
                    msg.contents[115], 68,
                    "incorrect value for contents[115], expected 68, is {}",
                    msg.contents[115]
                );
                assert_eq!(
                    msg.contents[116], 56,
                    "incorrect value for contents[116], expected 56, is {}",
                    msg.contents[116]
                );
                assert_eq!(
                    msg.contents[117], 238,
                    "incorrect value for contents[117], expected 238, is {}",
                    msg.contents[117]
                );
                assert_eq!(
                    msg.contents[118], 92,
                    "incorrect value for contents[118], expected 92, is {}",
                    msg.contents[118]
                );
                assert_eq!(
                    msg.contents[119], 130,
                    "incorrect value for contents[119], expected 130, is {}",
                    msg.contents[119]
                );
                assert_eq!(
                    msg.contents[120], 37,
                    "incorrect value for contents[120], expected 37, is {}",
                    msg.contents[120]
                );
                assert_eq!(
                    msg.contents[121], 137,
                    "incorrect value for contents[121], expected 137, is {}",
                    msg.contents[121]
                );
                assert_eq!(
                    msg.contents[122], 146,
                    "incorrect value for contents[122], expected 146, is {}",
                    msg.contents[122]
                );
                assert_eq!(
                    msg.contents[123], 246,
                    "incorrect value for contents[123], expected 246, is {}",
                    msg.contents[123]
                );
                assert_eq!(
                    msg.contents[124], 114,
                    "incorrect value for contents[124], expected 114, is {}",
                    msg.contents[124]
                );
                assert_eq!(
                    msg.contents[125], 116,
                    "incorrect value for contents[125], expected 116, is {}",
                    msg.contents[125]
                );
                assert_eq!(
                    msg.contents[126], 138,
                    "incorrect value for contents[126], expected 138, is {}",
                    msg.contents[126]
                );
                assert_eq!(
                    msg.contents[127], 165,
                    "incorrect value for contents[127], expected 165, is {}",
                    msg.contents[127]
                );
                assert_eq!(
                    msg.contents[128], 217,
                    "incorrect value for contents[128], expected 217, is {}",
                    msg.contents[128]
                );
                assert_eq!(
                    msg.contents[129], 79,
                    "incorrect value for contents[129], expected 79, is {}",
                    msg.contents[129]
                );
                assert_eq!(
                    msg.contents[130], 10,
                    "incorrect value for contents[130], expected 10, is {}",
                    msg.contents[130]
                );
                assert_eq!(
                    msg.contents[131], 189,
                    "incorrect value for contents[131], expected 189, is {}",
                    msg.contents[131]
                );
                assert_eq!(
                    msg.contents[132], 128,
                    "incorrect value for contents[132], expected 128, is {}",
                    msg.contents[132]
                );
                assert_eq!(
                    msg.contents[133], 189,
                    "incorrect value for contents[133], expected 189, is {}",
                    msg.contents[133]
                );
                assert_eq!(
                    msg.contents[134], 2,
                    "incorrect value for contents[134], expected 2, is {}",
                    msg.contents[134]
                );
                assert_eq!(
                    msg.contents[135], 240,
                    "incorrect value for contents[135], expected 240, is {}",
                    msg.contents[135]
                );
                assert_eq!(
                    msg.contents[136], 92,
                    "incorrect value for contents[136], expected 92, is {}",
                    msg.contents[136]
                );
                assert_eq!(
                    msg.contents[137], 28,
                    "incorrect value for contents[137], expected 28, is {}",
                    msg.contents[137]
                );
                assert_eq!(
                    msg.contents[138], 126,
                    "incorrect value for contents[138], expected 126, is {}",
                    msg.contents[138]
                );
                assert_eq!(
                    msg.contents[139], 105,
                    "incorrect value for contents[139], expected 105, is {}",
                    msg.contents[139]
                );
                assert_eq!(
                    msg.contents[140], 236,
                    "incorrect value for contents[140], expected 236, is {}",
                    msg.contents[140]
                );
                assert_eq!(
                    msg.contents[141], 228,
                    "incorrect value for contents[141], expected 228, is {}",
                    msg.contents[141]
                );
                assert_eq!(
                    msg.contents[142], 194,
                    "incorrect value for contents[142], expected 194, is {}",
                    msg.contents[142]
                );
                assert_eq!(
                    msg.contents[143], 0,
                    "incorrect value for contents[143], expected 0, is {}",
                    msg.contents[143]
                );
                assert_eq!(
                    msg.contents[144], 51,
                    "incorrect value for contents[144], expected 51, is {}",
                    msg.contents[144]
                );
                assert_eq!(
                    msg.contents[145], 61,
                    "incorrect value for contents[145], expected 61, is {}",
                    msg.contents[145]
                );
                assert_eq!(
                    msg.contents[146], 74,
                    "incorrect value for contents[146], expected 74, is {}",
                    msg.contents[146]
                );
                assert_eq!(
                    msg.contents[147], 41,
                    "incorrect value for contents[147], expected 41, is {}",
                    msg.contents[147]
                );
                assert_eq!(
                    msg.contents[148], 10,
                    "incorrect value for contents[148], expected 10, is {}",
                    msg.contents[148]
                );
                assert_eq!(
                    msg.contents[149], 239,
                    "incorrect value for contents[149], expected 239, is {}",
                    msg.contents[149]
                );
                assert_eq!(
                    msg.contents[150], 133,
                    "incorrect value for contents[150], expected 133, is {}",
                    msg.contents[150]
                );
                assert_eq!(
                    msg.contents[151], 106,
                    "incorrect value for contents[151], expected 106, is {}",
                    msg.contents[151]
                );
                assert_eq!(
                    msg.contents[152], 190,
                    "incorrect value for contents[152], expected 190, is {}",
                    msg.contents[152]
                );
                assert_eq!(
                    msg.contents[153], 30,
                    "incorrect value for contents[153], expected 30, is {}",
                    msg.contents[153]
                );
                assert_eq!(
                    msg.contents[154], 27,
                    "incorrect value for contents[154], expected 27, is {}",
                    msg.contents[154]
                );
                assert_eq!(
                    msg.contents[155], 3,
                    "incorrect value for contents[155], expected 3, is {}",
                    msg.contents[155]
                );
                assert_eq!(
                    msg.contents[156], 240,
                    "incorrect value for contents[156], expected 240, is {}",
                    msg.contents[156]
                );
                assert_eq!(
                    msg.contents[157], 205,
                    "incorrect value for contents[157], expected 205, is {}",
                    msg.contents[157]
                );
                assert_eq!(
                    msg.contents[158], 253,
                    "incorrect value for contents[158], expected 253, is {}",
                    msg.contents[158]
                );
                assert_eq!(
                    msg.contents[159], 113,
                    "incorrect value for contents[159], expected 113, is {}",
                    msg.contents[159]
                );
                assert_eq!(
                    msg.contents[160], 25,
                    "incorrect value for contents[160], expected 25, is {}",
                    msg.contents[160]
                );
                assert_eq!(
                    msg.contents[161], 28,
                    "incorrect value for contents[161], expected 28, is {}",
                    msg.contents[161]
                );
                assert_eq!(
                    msg.contents[162], 187,
                    "incorrect value for contents[162], expected 187, is {}",
                    msg.contents[162]
                );
                assert_eq!(
                    msg.contents[163], 81,
                    "incorrect value for contents[163], expected 81, is {}",
                    msg.contents[163]
                );
                assert_eq!(
                    msg.contents[164], 101,
                    "incorrect value for contents[164], expected 101, is {}",
                    msg.contents[164]
                );
                assert_eq!(
                    msg.contents[165], 216,
                    "incorrect value for contents[165], expected 216, is {}",
                    msg.contents[165]
                );
                assert_eq!(
                    msg.contents[166], 121,
                    "incorrect value for contents[166], expected 121, is {}",
                    msg.contents[166]
                );
                assert_eq!(
                    msg.contents[167], 41,
                    "incorrect value for contents[167], expected 41, is {}",
                    msg.contents[167]
                );
                assert_eq!(
                    msg.contents[168], 179,
                    "incorrect value for contents[168], expected 179, is {}",
                    msg.contents[168]
                );
                assert_eq!(
                    msg.contents[169], 120,
                    "incorrect value for contents[169], expected 120, is {}",
                    msg.contents[169]
                );
                assert_eq!(
                    msg.contents[170], 152,
                    "incorrect value for contents[170], expected 152, is {}",
                    msg.contents[170]
                );
                assert_eq!(
                    msg.contents[171], 18,
                    "incorrect value for contents[171], expected 18, is {}",
                    msg.contents[171]
                );
                assert_eq!(
                    msg.contents[172], 116,
                    "incorrect value for contents[172], expected 116, is {}",
                    msg.contents[172]
                );
                assert_eq!(
                    msg.contents[173], 53,
                    "incorrect value for contents[173], expected 53, is {}",
                    msg.contents[173]
                );
                assert_eq!(
                    msg.contents[174], 212,
                    "incorrect value for contents[174], expected 212, is {}",
                    msg.contents[174]
                );
                assert_eq!(
                    msg.contents[175], 100,
                    "incorrect value for contents[175], expected 100, is {}",
                    msg.contents[175]
                );
                assert_eq!(
                    msg.contents[176], 2,
                    "incorrect value for contents[176], expected 2, is {}",
                    msg.contents[176]
                );
                assert_eq!(
                    msg.contents[177], 114,
                    "incorrect value for contents[177], expected 114, is {}",
                    msg.contents[177]
                );
                assert_eq!(
                    msg.contents[178], 198,
                    "incorrect value for contents[178], expected 198, is {}",
                    msg.contents[178]
                );
                assert_eq!(
                    msg.contents[179], 200,
                    "incorrect value for contents[179], expected 200, is {}",
                    msg.contents[179]
                );
                assert_eq!(
                    msg.contents[180], 10,
                    "incorrect value for contents[180], expected 10, is {}",
                    msg.contents[180]
                );
                assert_eq!(
                    msg.contents[181], 147,
                    "incorrect value for contents[181], expected 147, is {}",
                    msg.contents[181]
                );
                assert_eq!(
                    msg.contents[182], 25,
                    "incorrect value for contents[182], expected 25, is {}",
                    msg.contents[182]
                );
                assert_eq!(
                    msg.contents[183], 33,
                    "incorrect value for contents[183], expected 33, is {}",
                    msg.contents[183]
                );
                assert_eq!(
                    msg.contents[184], 115,
                    "incorrect value for contents[184], expected 115, is {}",
                    msg.contents[184]
                );
                assert_eq!(
                    msg.contents[185], 208,
                    "incorrect value for contents[185], expected 208, is {}",
                    msg.contents[185]
                );
                assert_eq!(
                    msg.contents[186], 113,
                    "incorrect value for contents[186], expected 113, is {}",
                    msg.contents[186]
                );
                assert_eq!(
                    msg.contents[187], 60,
                    "incorrect value for contents[187], expected 60, is {}",
                    msg.contents[187]
                );
                assert_eq!(
                    msg.contents[188], 179,
                    "incorrect value for contents[188], expected 179, is {}",
                    msg.contents[188]
                );
                assert_eq!(
                    msg.contents[189], 183,
                    "incorrect value for contents[189], expected 183, is {}",
                    msg.contents[189]
                );
                assert_eq!(
                    msg.contents[190], 0,
                    "incorrect value for contents[190], expected 0, is {}",
                    msg.contents[190]
                );
                assert_eq!(
                    msg.contents[191], 41,
                    "incorrect value for contents[191], expected 41, is {}",
                    msg.contents[191]
                );
                assert_eq!(
                    msg.contents[192], 217,
                    "incorrect value for contents[192], expected 217, is {}",
                    msg.contents[192]
                );
                assert_eq!(
                    msg.contents[193], 206,
                    "incorrect value for contents[193], expected 206, is {}",
                    msg.contents[193]
                );
                assert_eq!(
                    msg.contents[194], 255,
                    "incorrect value for contents[194], expected 255, is {}",
                    msg.contents[194]
                );
                assert_eq!(
                    msg.contents[195], 211,
                    "incorrect value for contents[195], expected 211, is {}",
                    msg.contents[195]
                );
                assert_eq!(
                    msg.contents[196], 225,
                    "incorrect value for contents[196], expected 225, is {}",
                    msg.contents[196]
                );
                assert_eq!(
                    msg.contents[197], 142,
                    "incorrect value for contents[197], expected 142, is {}",
                    msg.contents[197]
                );
                assert_eq!(
                    msg.contents[198], 191,
                    "incorrect value for contents[198], expected 191, is {}",
                    msg.contents[198]
                );
                assert_eq!(
                    msg.contents[199], 133,
                    "incorrect value for contents[199], expected 133, is {}",
                    msg.contents[199]
                );
                assert_eq!(
                    msg.contents[200], 81,
                    "incorrect value for contents[200], expected 81, is {}",
                    msg.contents[200]
                );
                assert_eq!(
                    msg.contents[201], 15,
                    "incorrect value for contents[201], expected 15, is {}",
                    msg.contents[201]
                );
                assert_eq!(
                    msg.contents[202], 248,
                    "incorrect value for contents[202], expected 248, is {}",
                    msg.contents[202]
                );
                assert_eq!(
                    msg.contents[203], 193,
                    "incorrect value for contents[203], expected 193, is {}",
                    msg.contents[203]
                );
                assert_eq!(
                    msg.contents[204], 66,
                    "incorrect value for contents[204], expected 66, is {}",
                    msg.contents[204]
                );
                assert_eq!(
                    msg.contents[205], 191,
                    "incorrect value for contents[205], expected 191, is {}",
                    msg.contents[205]
                );
                assert_eq!(
                    msg.contents[206], 244,
                    "incorrect value for contents[206], expected 244, is {}",
                    msg.contents[206]
                );
                assert_eq!(
                    msg.contents[207], 221,
                    "incorrect value for contents[207], expected 221, is {}",
                    msg.contents[207]
                );
                assert_eq!(
                    msg.contents[208], 248,
                    "incorrect value for contents[208], expected 248, is {}",
                    msg.contents[208]
                );
                assert_eq!(
                    msg.contents[209], 199,
                    "incorrect value for contents[209], expected 199, is {}",
                    msg.contents[209]
                );
                assert_eq!(
                    msg.contents[210], 241,
                    "incorrect value for contents[210], expected 241, is {}",
                    msg.contents[210]
                );
                assert_eq!(
                    msg.contents[211], 112,
                    "incorrect value for contents[211], expected 112, is {}",
                    msg.contents[211]
                );
                assert_eq!(
                    msg.contents[212], 51,
                    "incorrect value for contents[212], expected 51, is {}",
                    msg.contents[212]
                );
                assert_eq!(
                    msg.contents[213], 1,
                    "incorrect value for contents[213], expected 1, is {}",
                    msg.contents[213]
                );
                assert_eq!(
                    msg.contents[214], 180,
                    "incorrect value for contents[214], expected 180, is {}",
                    msg.contents[214]
                );
                assert_eq!(
                    msg.contents[215], 180,
                    "incorrect value for contents[215], expected 180, is {}",
                    msg.contents[215]
                );
                assert_eq!(
                    msg.contents[216], 125,
                    "incorrect value for contents[216], expected 125, is {}",
                    msg.contents[216]
                );
                assert_eq!(
                    msg.contents[217], 97,
                    "incorrect value for contents[217], expected 97, is {}",
                    msg.contents[217]
                );
                assert_eq!(
                    msg.contents[218], 145,
                    "incorrect value for contents[218], expected 145, is {}",
                    msg.contents[218]
                );
                assert_eq!(
                    msg.contents[219], 25,
                    "incorrect value for contents[219], expected 25, is {}",
                    msg.contents[219]
                );
                assert_eq!(
                    msg.contents[220], 72,
                    "incorrect value for contents[220], expected 72, is {}",
                    msg.contents[220]
                );
                assert_eq!(
                    msg.contents[221], 210,
                    "incorrect value for contents[221], expected 210, is {}",
                    msg.contents[221]
                );
                assert_eq!(
                    msg.contents[222], 215,
                    "incorrect value for contents[222], expected 215, is {}",
                    msg.contents[222]
                );
                assert_eq!(
                    msg.contents[223], 208,
                    "incorrect value for contents[223], expected 208, is {}",
                    msg.contents[223]
                );
                assert_eq!(
                    msg.contents[224], 15,
                    "incorrect value for contents[224], expected 15, is {}",
                    msg.contents[224]
                );
                assert_eq!(
                    msg.contents[225], 126,
                    "incorrect value for contents[225], expected 126, is {}",
                    msg.contents[225]
                );
                assert_eq!(
                    msg.contents[226], 56,
                    "incorrect value for contents[226], expected 56, is {}",
                    msg.contents[226]
                );
                assert_eq!(
                    msg.contents[227], 38,
                    "incorrect value for contents[227], expected 38, is {}",
                    msg.contents[227]
                );
                assert_eq!(
                    msg.contents[228], 65,
                    "incorrect value for contents[228], expected 65, is {}",
                    msg.contents[228]
                );
                assert_eq!(
                    msg.contents[229], 4,
                    "incorrect value for contents[229], expected 4, is {}",
                    msg.contents[229]
                );
                assert_eq!(
                    msg.contents[230], 64,
                    "incorrect value for contents[230], expected 64, is {}",
                    msg.contents[230]
                );
                assert_eq!(
                    msg.contents[231], 19,
                    "incorrect value for contents[231], expected 19, is {}",
                    msg.contents[231]
                );
                assert_eq!(
                    msg.contents[232], 74,
                    "incorrect value for contents[232], expected 74, is {}",
                    msg.contents[232]
                );
                assert_eq!(
                    msg.contents[233], 223,
                    "incorrect value for contents[233], expected 223, is {}",
                    msg.contents[233]
                );
                assert_eq!(
                    msg.contents[234], 111,
                    "incorrect value for contents[234], expected 111, is {}",
                    msg.contents[234]
                );
                assert_eq!(
                    msg.contents[235], 109,
                    "incorrect value for contents[235], expected 109, is {}",
                    msg.contents[235]
                );
                assert_eq!(
                    msg.contents[236], 52,
                    "incorrect value for contents[236], expected 52, is {}",
                    msg.contents[236]
                );
                assert_eq!(
                    msg.contents[237], 43,
                    "incorrect value for contents[237], expected 43, is {}",
                    msg.contents[237]
                );
                assert_eq!(
                    msg.contents[238], 167,
                    "incorrect value for contents[238], expected 167, is {}",
                    msg.contents[238]
                );
                assert_eq!(
                    msg.contents[239], 186,
                    "incorrect value for contents[239], expected 186, is {}",
                    msg.contents[239]
                );
                assert_eq!(
                    msg.contents[240], 202,
                    "incorrect value for contents[240], expected 202, is {}",
                    msg.contents[240]
                );
                assert_eq!(
                    msg.contents[241], 111,
                    "incorrect value for contents[241], expected 111, is {}",
                    msg.contents[241]
                );
                assert_eq!(
                    msg.contents[242], 11,
                    "incorrect value for contents[242], expected 11, is {}",
                    msg.contents[242]
                );
                assert_eq!(
                    msg.contents[243], 91,
                    "incorrect value for contents[243], expected 91, is {}",
                    msg.contents[243]
                );
                assert_eq!(
                    msg.contents[244], 21,
                    "incorrect value for contents[244], expected 21, is {}",
                    msg.contents[244]
                );
                assert_eq!(
                    msg.contents[245], 236,
                    "incorrect value for contents[245], expected 236, is {}",
                    msg.contents[245]
                );
                assert_eq!(
                    msg.contents[246], 234,
                    "incorrect value for contents[246], expected 234, is {}",
                    msg.contents[246]
                );
                assert_eq!(
                    msg.contents[247], 196,
                    "incorrect value for contents[247], expected 196, is {}",
                    msg.contents[247]
                );
                assert_eq!(
                    msg.contents[248], 36,
                    "incorrect value for contents[248], expected 36, is {}",
                    msg.contents[248]
                );
                assert_eq!(
                    msg.contents[249], 171,
                    "incorrect value for contents[249], expected 171, is {}",
                    msg.contents[249]
                );
                assert_eq!(
                    msg.contents[250], 147,
                    "incorrect value for contents[250], expected 147, is {}",
                    msg.contents[250]
                );
                assert_eq!(
                    msg.sequence, 259241795,
                    "incorrect value for sequence, expected 259241795, is {}",
                    msg.sequence
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFileioReadResp"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
