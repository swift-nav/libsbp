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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCellModemStatus.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_piksi_msg_cell_modem_status() {
    {
        let mut payload = Cursor::new(vec![
            85, 190, 0, 19, 27, 255, 103, 205, 48, 6, 70, 123, 242, 46, 52, 64, 176, 154, 98, 43,
            132, 196, 89, 253, 161, 250, 174, 204, 110, 47, 38, 187, 63, 102, 177, 162, 49, 80,
            194, 37, 107, 60, 225, 52, 101, 178, 142, 246, 21, 17, 93, 75, 169, 86, 16, 209, 80,
            243, 30, 206, 220, 206, 115, 47, 154, 91, 227, 88, 11, 1, 85, 146, 100, 190, 232, 207,
            61, 61, 201, 220, 31, 78, 34, 57, 82, 59, 104, 65, 221, 0, 43, 210, 9, 32, 122, 29,
            237, 11, 151, 223, 18, 81, 204, 172, 234, 127, 3, 82, 133, 169, 12, 176, 193, 0, 24,
            121, 85, 55, 214, 198, 75, 234, 179, 214, 85, 94, 115, 21, 73, 121, 75, 46, 158, 63,
            100, 122, 213, 20, 85, 212, 131, 50, 224, 218, 215, 215, 149, 2, 19, 129, 39, 164, 5,
            175, 6, 62, 51, 78, 66, 248, 116, 88, 90, 128, 226, 177, 0, 47, 140, 33, 126, 221, 110,
            144, 97, 74, 250, 181, 199, 27, 176, 65, 185, 110, 92, 34, 44, 131, 96, 178, 40, 176,
            4, 90, 36, 7, 180, 244, 244, 23, 108, 171, 204, 196, 61, 51, 179, 242, 156, 81, 83, 16,
            15, 134, 40, 245, 253, 150, 94, 150, 144, 197, 113, 5, 141, 232, 33, 101, 231, 38, 75,
            178, 243, 119, 1, 248, 218, 86, 7, 88, 197, 148, 240, 227, 2, 65, 173, 122, 143, 251,
            156, 217, 67, 239, 219, 31, 224, 176, 129, 81, 80, 40, 230,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgCellModemStatus(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xbe,
                    "Incorrect message type, expected 0xbe, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1b13,
                    "incorrect sender id, expected 0x1b13, is {sender_id}"
                );
                assert_eq!(
                    msg.reserved[0], 123,
                    "incorrect value for reserved[0], expected 123, is {}",
                    msg.reserved[0]
                );
                assert_eq!(
                    msg.reserved[1], 242,
                    "incorrect value for reserved[1], expected 242, is {}",
                    msg.reserved[1]
                );
                assert_eq!(
                    msg.reserved[2], 46,
                    "incorrect value for reserved[2], expected 46, is {}",
                    msg.reserved[2]
                );
                assert_eq!(
                    msg.reserved[3], 52,
                    "incorrect value for reserved[3], expected 52, is {}",
                    msg.reserved[3]
                );
                assert_eq!(
                    msg.reserved[4], 64,
                    "incorrect value for reserved[4], expected 64, is {}",
                    msg.reserved[4]
                );
                assert_eq!(
                    msg.reserved[5], 176,
                    "incorrect value for reserved[5], expected 176, is {}",
                    msg.reserved[5]
                );
                assert_eq!(
                    msg.reserved[6], 154,
                    "incorrect value for reserved[6], expected 154, is {}",
                    msg.reserved[6]
                );
                assert_eq!(
                    msg.reserved[7], 98,
                    "incorrect value for reserved[7], expected 98, is {}",
                    msg.reserved[7]
                );
                assert_eq!(
                    msg.reserved[8], 43,
                    "incorrect value for reserved[8], expected 43, is {}",
                    msg.reserved[8]
                );
                assert_eq!(
                    msg.reserved[9], 132,
                    "incorrect value for reserved[9], expected 132, is {}",
                    msg.reserved[9]
                );
                assert_eq!(
                    msg.reserved[10], 196,
                    "incorrect value for reserved[10], expected 196, is {}",
                    msg.reserved[10]
                );
                assert_eq!(
                    msg.reserved[11], 89,
                    "incorrect value for reserved[11], expected 89, is {}",
                    msg.reserved[11]
                );
                assert_eq!(
                    msg.reserved[12], 253,
                    "incorrect value for reserved[12], expected 253, is {}",
                    msg.reserved[12]
                );
                assert_eq!(
                    msg.reserved[13], 161,
                    "incorrect value for reserved[13], expected 161, is {}",
                    msg.reserved[13]
                );
                assert_eq!(
                    msg.reserved[14], 250,
                    "incorrect value for reserved[14], expected 250, is {}",
                    msg.reserved[14]
                );
                assert_eq!(
                    msg.reserved[15], 174,
                    "incorrect value for reserved[15], expected 174, is {}",
                    msg.reserved[15]
                );
                assert_eq!(
                    msg.reserved[16], 204,
                    "incorrect value for reserved[16], expected 204, is {}",
                    msg.reserved[16]
                );
                assert_eq!(
                    msg.reserved[17], 110,
                    "incorrect value for reserved[17], expected 110, is {}",
                    msg.reserved[17]
                );
                assert_eq!(
                    msg.reserved[18], 47,
                    "incorrect value for reserved[18], expected 47, is {}",
                    msg.reserved[18]
                );
                assert_eq!(
                    msg.reserved[19], 38,
                    "incorrect value for reserved[19], expected 38, is {}",
                    msg.reserved[19]
                );
                assert_eq!(
                    msg.reserved[20], 187,
                    "incorrect value for reserved[20], expected 187, is {}",
                    msg.reserved[20]
                );
                assert_eq!(
                    msg.reserved[21], 63,
                    "incorrect value for reserved[21], expected 63, is {}",
                    msg.reserved[21]
                );
                assert_eq!(
                    msg.reserved[22], 102,
                    "incorrect value for reserved[22], expected 102, is {}",
                    msg.reserved[22]
                );
                assert_eq!(
                    msg.reserved[23], 177,
                    "incorrect value for reserved[23], expected 177, is {}",
                    msg.reserved[23]
                );
                assert_eq!(
                    msg.reserved[24], 162,
                    "incorrect value for reserved[24], expected 162, is {}",
                    msg.reserved[24]
                );
                assert_eq!(
                    msg.reserved[25], 49,
                    "incorrect value for reserved[25], expected 49, is {}",
                    msg.reserved[25]
                );
                assert_eq!(
                    msg.reserved[26], 80,
                    "incorrect value for reserved[26], expected 80, is {}",
                    msg.reserved[26]
                );
                assert_eq!(
                    msg.reserved[27], 194,
                    "incorrect value for reserved[27], expected 194, is {}",
                    msg.reserved[27]
                );
                assert_eq!(
                    msg.reserved[28], 37,
                    "incorrect value for reserved[28], expected 37, is {}",
                    msg.reserved[28]
                );
                assert_eq!(
                    msg.reserved[29], 107,
                    "incorrect value for reserved[29], expected 107, is {}",
                    msg.reserved[29]
                );
                assert_eq!(
                    msg.reserved[30], 60,
                    "incorrect value for reserved[30], expected 60, is {}",
                    msg.reserved[30]
                );
                assert_eq!(
                    msg.reserved[31], 225,
                    "incorrect value for reserved[31], expected 225, is {}",
                    msg.reserved[31]
                );
                assert_eq!(
                    msg.reserved[32], 52,
                    "incorrect value for reserved[32], expected 52, is {}",
                    msg.reserved[32]
                );
                assert_eq!(
                    msg.reserved[33], 101,
                    "incorrect value for reserved[33], expected 101, is {}",
                    msg.reserved[33]
                );
                assert_eq!(
                    msg.reserved[34], 178,
                    "incorrect value for reserved[34], expected 178, is {}",
                    msg.reserved[34]
                );
                assert_eq!(
                    msg.reserved[35], 142,
                    "incorrect value for reserved[35], expected 142, is {}",
                    msg.reserved[35]
                );
                assert_eq!(
                    msg.reserved[36], 246,
                    "incorrect value for reserved[36], expected 246, is {}",
                    msg.reserved[36]
                );
                assert_eq!(
                    msg.reserved[37], 21,
                    "incorrect value for reserved[37], expected 21, is {}",
                    msg.reserved[37]
                );
                assert_eq!(
                    msg.reserved[38], 17,
                    "incorrect value for reserved[38], expected 17, is {}",
                    msg.reserved[38]
                );
                assert_eq!(
                    msg.reserved[39], 93,
                    "incorrect value for reserved[39], expected 93, is {}",
                    msg.reserved[39]
                );
                assert_eq!(
                    msg.reserved[40], 75,
                    "incorrect value for reserved[40], expected 75, is {}",
                    msg.reserved[40]
                );
                assert_eq!(
                    msg.reserved[41], 169,
                    "incorrect value for reserved[41], expected 169, is {}",
                    msg.reserved[41]
                );
                assert_eq!(
                    msg.reserved[42], 86,
                    "incorrect value for reserved[42], expected 86, is {}",
                    msg.reserved[42]
                );
                assert_eq!(
                    msg.reserved[43], 16,
                    "incorrect value for reserved[43], expected 16, is {}",
                    msg.reserved[43]
                );
                assert_eq!(
                    msg.reserved[44], 209,
                    "incorrect value for reserved[44], expected 209, is {}",
                    msg.reserved[44]
                );
                assert_eq!(
                    msg.reserved[45], 80,
                    "incorrect value for reserved[45], expected 80, is {}",
                    msg.reserved[45]
                );
                assert_eq!(
                    msg.reserved[46], 243,
                    "incorrect value for reserved[46], expected 243, is {}",
                    msg.reserved[46]
                );
                assert_eq!(
                    msg.reserved[47], 30,
                    "incorrect value for reserved[47], expected 30, is {}",
                    msg.reserved[47]
                );
                assert_eq!(
                    msg.reserved[48], 206,
                    "incorrect value for reserved[48], expected 206, is {}",
                    msg.reserved[48]
                );
                assert_eq!(
                    msg.reserved[49], 220,
                    "incorrect value for reserved[49], expected 220, is {}",
                    msg.reserved[49]
                );
                assert_eq!(
                    msg.reserved[50], 206,
                    "incorrect value for reserved[50], expected 206, is {}",
                    msg.reserved[50]
                );
                assert_eq!(
                    msg.reserved[51], 115,
                    "incorrect value for reserved[51], expected 115, is {}",
                    msg.reserved[51]
                );
                assert_eq!(
                    msg.reserved[52], 47,
                    "incorrect value for reserved[52], expected 47, is {}",
                    msg.reserved[52]
                );
                assert_eq!(
                    msg.reserved[53], 154,
                    "incorrect value for reserved[53], expected 154, is {}",
                    msg.reserved[53]
                );
                assert_eq!(
                    msg.reserved[54], 91,
                    "incorrect value for reserved[54], expected 91, is {}",
                    msg.reserved[54]
                );
                assert_eq!(
                    msg.reserved[55], 227,
                    "incorrect value for reserved[55], expected 227, is {}",
                    msg.reserved[55]
                );
                assert_eq!(
                    msg.reserved[56], 88,
                    "incorrect value for reserved[56], expected 88, is {}",
                    msg.reserved[56]
                );
                assert_eq!(
                    msg.reserved[57], 11,
                    "incorrect value for reserved[57], expected 11, is {}",
                    msg.reserved[57]
                );
                assert_eq!(
                    msg.reserved[58], 1,
                    "incorrect value for reserved[58], expected 1, is {}",
                    msg.reserved[58]
                );
                assert_eq!(
                    msg.reserved[59], 85,
                    "incorrect value for reserved[59], expected 85, is {}",
                    msg.reserved[59]
                );
                assert_eq!(
                    msg.reserved[60], 146,
                    "incorrect value for reserved[60], expected 146, is {}",
                    msg.reserved[60]
                );
                assert_eq!(
                    msg.reserved[61], 100,
                    "incorrect value for reserved[61], expected 100, is {}",
                    msg.reserved[61]
                );
                assert_eq!(
                    msg.reserved[62], 190,
                    "incorrect value for reserved[62], expected 190, is {}",
                    msg.reserved[62]
                );
                assert_eq!(
                    msg.reserved[63], 232,
                    "incorrect value for reserved[63], expected 232, is {}",
                    msg.reserved[63]
                );
                assert_eq!(
                    msg.reserved[64], 207,
                    "incorrect value for reserved[64], expected 207, is {}",
                    msg.reserved[64]
                );
                assert_eq!(
                    msg.reserved[65], 61,
                    "incorrect value for reserved[65], expected 61, is {}",
                    msg.reserved[65]
                );
                assert_eq!(
                    msg.reserved[66], 61,
                    "incorrect value for reserved[66], expected 61, is {}",
                    msg.reserved[66]
                );
                assert_eq!(
                    msg.reserved[67], 201,
                    "incorrect value for reserved[67], expected 201, is {}",
                    msg.reserved[67]
                );
                assert_eq!(
                    msg.reserved[68], 220,
                    "incorrect value for reserved[68], expected 220, is {}",
                    msg.reserved[68]
                );
                assert_eq!(
                    msg.reserved[69], 31,
                    "incorrect value for reserved[69], expected 31, is {}",
                    msg.reserved[69]
                );
                assert_eq!(
                    msg.reserved[70], 78,
                    "incorrect value for reserved[70], expected 78, is {}",
                    msg.reserved[70]
                );
                assert_eq!(
                    msg.reserved[71], 34,
                    "incorrect value for reserved[71], expected 34, is {}",
                    msg.reserved[71]
                );
                assert_eq!(
                    msg.reserved[72], 57,
                    "incorrect value for reserved[72], expected 57, is {}",
                    msg.reserved[72]
                );
                assert_eq!(
                    msg.reserved[73], 82,
                    "incorrect value for reserved[73], expected 82, is {}",
                    msg.reserved[73]
                );
                assert_eq!(
                    msg.reserved[74], 59,
                    "incorrect value for reserved[74], expected 59, is {}",
                    msg.reserved[74]
                );
                assert_eq!(
                    msg.reserved[75], 104,
                    "incorrect value for reserved[75], expected 104, is {}",
                    msg.reserved[75]
                );
                assert_eq!(
                    msg.reserved[76], 65,
                    "incorrect value for reserved[76], expected 65, is {}",
                    msg.reserved[76]
                );
                assert_eq!(
                    msg.reserved[77], 221,
                    "incorrect value for reserved[77], expected 221, is {}",
                    msg.reserved[77]
                );
                assert_eq!(
                    msg.reserved[78], 0,
                    "incorrect value for reserved[78], expected 0, is {}",
                    msg.reserved[78]
                );
                assert_eq!(
                    msg.reserved[79], 43,
                    "incorrect value for reserved[79], expected 43, is {}",
                    msg.reserved[79]
                );
                assert_eq!(
                    msg.reserved[80], 210,
                    "incorrect value for reserved[80], expected 210, is {}",
                    msg.reserved[80]
                );
                assert_eq!(
                    msg.reserved[81], 9,
                    "incorrect value for reserved[81], expected 9, is {}",
                    msg.reserved[81]
                );
                assert_eq!(
                    msg.reserved[82], 32,
                    "incorrect value for reserved[82], expected 32, is {}",
                    msg.reserved[82]
                );
                assert_eq!(
                    msg.reserved[83], 122,
                    "incorrect value for reserved[83], expected 122, is {}",
                    msg.reserved[83]
                );
                assert_eq!(
                    msg.reserved[84], 29,
                    "incorrect value for reserved[84], expected 29, is {}",
                    msg.reserved[84]
                );
                assert_eq!(
                    msg.reserved[85], 237,
                    "incorrect value for reserved[85], expected 237, is {}",
                    msg.reserved[85]
                );
                assert_eq!(
                    msg.reserved[86], 11,
                    "incorrect value for reserved[86], expected 11, is {}",
                    msg.reserved[86]
                );
                assert_eq!(
                    msg.reserved[87], 151,
                    "incorrect value for reserved[87], expected 151, is {}",
                    msg.reserved[87]
                );
                assert_eq!(
                    msg.reserved[88], 223,
                    "incorrect value for reserved[88], expected 223, is {}",
                    msg.reserved[88]
                );
                assert_eq!(
                    msg.reserved[89], 18,
                    "incorrect value for reserved[89], expected 18, is {}",
                    msg.reserved[89]
                );
                assert_eq!(
                    msg.reserved[90], 81,
                    "incorrect value for reserved[90], expected 81, is {}",
                    msg.reserved[90]
                );
                assert_eq!(
                    msg.reserved[91], 204,
                    "incorrect value for reserved[91], expected 204, is {}",
                    msg.reserved[91]
                );
                assert_eq!(
                    msg.reserved[92], 172,
                    "incorrect value for reserved[92], expected 172, is {}",
                    msg.reserved[92]
                );
                assert_eq!(
                    msg.reserved[93], 234,
                    "incorrect value for reserved[93], expected 234, is {}",
                    msg.reserved[93]
                );
                assert_eq!(
                    msg.reserved[94], 127,
                    "incorrect value for reserved[94], expected 127, is {}",
                    msg.reserved[94]
                );
                assert_eq!(
                    msg.reserved[95], 3,
                    "incorrect value for reserved[95], expected 3, is {}",
                    msg.reserved[95]
                );
                assert_eq!(
                    msg.reserved[96], 82,
                    "incorrect value for reserved[96], expected 82, is {}",
                    msg.reserved[96]
                );
                assert_eq!(
                    msg.reserved[97], 133,
                    "incorrect value for reserved[97], expected 133, is {}",
                    msg.reserved[97]
                );
                assert_eq!(
                    msg.reserved[98], 169,
                    "incorrect value for reserved[98], expected 169, is {}",
                    msg.reserved[98]
                );
                assert_eq!(
                    msg.reserved[99], 12,
                    "incorrect value for reserved[99], expected 12, is {}",
                    msg.reserved[99]
                );
                assert_eq!(
                    msg.reserved[100], 176,
                    "incorrect value for reserved[100], expected 176, is {}",
                    msg.reserved[100]
                );
                assert_eq!(
                    msg.reserved[101], 193,
                    "incorrect value for reserved[101], expected 193, is {}",
                    msg.reserved[101]
                );
                assert_eq!(
                    msg.reserved[102], 0,
                    "incorrect value for reserved[102], expected 0, is {}",
                    msg.reserved[102]
                );
                assert_eq!(
                    msg.reserved[103], 24,
                    "incorrect value for reserved[103], expected 24, is {}",
                    msg.reserved[103]
                );
                assert_eq!(
                    msg.reserved[104], 121,
                    "incorrect value for reserved[104], expected 121, is {}",
                    msg.reserved[104]
                );
                assert_eq!(
                    msg.reserved[105], 85,
                    "incorrect value for reserved[105], expected 85, is {}",
                    msg.reserved[105]
                );
                assert_eq!(
                    msg.reserved[106], 55,
                    "incorrect value for reserved[106], expected 55, is {}",
                    msg.reserved[106]
                );
                assert_eq!(
                    msg.reserved[107], 214,
                    "incorrect value for reserved[107], expected 214, is {}",
                    msg.reserved[107]
                );
                assert_eq!(
                    msg.reserved[108], 198,
                    "incorrect value for reserved[108], expected 198, is {}",
                    msg.reserved[108]
                );
                assert_eq!(
                    msg.reserved[109], 75,
                    "incorrect value for reserved[109], expected 75, is {}",
                    msg.reserved[109]
                );
                assert_eq!(
                    msg.reserved[110], 234,
                    "incorrect value for reserved[110], expected 234, is {}",
                    msg.reserved[110]
                );
                assert_eq!(
                    msg.reserved[111], 179,
                    "incorrect value for reserved[111], expected 179, is {}",
                    msg.reserved[111]
                );
                assert_eq!(
                    msg.reserved[112], 214,
                    "incorrect value for reserved[112], expected 214, is {}",
                    msg.reserved[112]
                );
                assert_eq!(
                    msg.reserved[113], 85,
                    "incorrect value for reserved[113], expected 85, is {}",
                    msg.reserved[113]
                );
                assert_eq!(
                    msg.reserved[114], 94,
                    "incorrect value for reserved[114], expected 94, is {}",
                    msg.reserved[114]
                );
                assert_eq!(
                    msg.reserved[115], 115,
                    "incorrect value for reserved[115], expected 115, is {}",
                    msg.reserved[115]
                );
                assert_eq!(
                    msg.reserved[116], 21,
                    "incorrect value for reserved[116], expected 21, is {}",
                    msg.reserved[116]
                );
                assert_eq!(
                    msg.reserved[117], 73,
                    "incorrect value for reserved[117], expected 73, is {}",
                    msg.reserved[117]
                );
                assert_eq!(
                    msg.reserved[118], 121,
                    "incorrect value for reserved[118], expected 121, is {}",
                    msg.reserved[118]
                );
                assert_eq!(
                    msg.reserved[119], 75,
                    "incorrect value for reserved[119], expected 75, is {}",
                    msg.reserved[119]
                );
                assert_eq!(
                    msg.reserved[120], 46,
                    "incorrect value for reserved[120], expected 46, is {}",
                    msg.reserved[120]
                );
                assert_eq!(
                    msg.reserved[121], 158,
                    "incorrect value for reserved[121], expected 158, is {}",
                    msg.reserved[121]
                );
                assert_eq!(
                    msg.reserved[122], 63,
                    "incorrect value for reserved[122], expected 63, is {}",
                    msg.reserved[122]
                );
                assert_eq!(
                    msg.reserved[123], 100,
                    "incorrect value for reserved[123], expected 100, is {}",
                    msg.reserved[123]
                );
                assert_eq!(
                    msg.reserved[124], 122,
                    "incorrect value for reserved[124], expected 122, is {}",
                    msg.reserved[124]
                );
                assert_eq!(
                    msg.reserved[125], 213,
                    "incorrect value for reserved[125], expected 213, is {}",
                    msg.reserved[125]
                );
                assert_eq!(
                    msg.reserved[126], 20,
                    "incorrect value for reserved[126], expected 20, is {}",
                    msg.reserved[126]
                );
                assert_eq!(
                    msg.reserved[127], 85,
                    "incorrect value for reserved[127], expected 85, is {}",
                    msg.reserved[127]
                );
                assert_eq!(
                    msg.reserved[128], 212,
                    "incorrect value for reserved[128], expected 212, is {}",
                    msg.reserved[128]
                );
                assert_eq!(
                    msg.reserved[129], 131,
                    "incorrect value for reserved[129], expected 131, is {}",
                    msg.reserved[129]
                );
                assert_eq!(
                    msg.reserved[130], 50,
                    "incorrect value for reserved[130], expected 50, is {}",
                    msg.reserved[130]
                );
                assert_eq!(
                    msg.reserved[131], 224,
                    "incorrect value for reserved[131], expected 224, is {}",
                    msg.reserved[131]
                );
                assert_eq!(
                    msg.reserved[132], 218,
                    "incorrect value for reserved[132], expected 218, is {}",
                    msg.reserved[132]
                );
                assert_eq!(
                    msg.reserved[133], 215,
                    "incorrect value for reserved[133], expected 215, is {}",
                    msg.reserved[133]
                );
                assert_eq!(
                    msg.reserved[134], 215,
                    "incorrect value for reserved[134], expected 215, is {}",
                    msg.reserved[134]
                );
                assert_eq!(
                    msg.reserved[135], 149,
                    "incorrect value for reserved[135], expected 149, is {}",
                    msg.reserved[135]
                );
                assert_eq!(
                    msg.reserved[136], 2,
                    "incorrect value for reserved[136], expected 2, is {}",
                    msg.reserved[136]
                );
                assert_eq!(
                    msg.reserved[137], 19,
                    "incorrect value for reserved[137], expected 19, is {}",
                    msg.reserved[137]
                );
                assert_eq!(
                    msg.reserved[138], 129,
                    "incorrect value for reserved[138], expected 129, is {}",
                    msg.reserved[138]
                );
                assert_eq!(
                    msg.reserved[139], 39,
                    "incorrect value for reserved[139], expected 39, is {}",
                    msg.reserved[139]
                );
                assert_eq!(
                    msg.reserved[140], 164,
                    "incorrect value for reserved[140], expected 164, is {}",
                    msg.reserved[140]
                );
                assert_eq!(
                    msg.reserved[141], 5,
                    "incorrect value for reserved[141], expected 5, is {}",
                    msg.reserved[141]
                );
                assert_eq!(
                    msg.reserved[142], 175,
                    "incorrect value for reserved[142], expected 175, is {}",
                    msg.reserved[142]
                );
                assert_eq!(
                    msg.reserved[143], 6,
                    "incorrect value for reserved[143], expected 6, is {}",
                    msg.reserved[143]
                );
                assert_eq!(
                    msg.reserved[144], 62,
                    "incorrect value for reserved[144], expected 62, is {}",
                    msg.reserved[144]
                );
                assert_eq!(
                    msg.reserved[145], 51,
                    "incorrect value for reserved[145], expected 51, is {}",
                    msg.reserved[145]
                );
                assert_eq!(
                    msg.reserved[146], 78,
                    "incorrect value for reserved[146], expected 78, is {}",
                    msg.reserved[146]
                );
                assert_eq!(
                    msg.reserved[147], 66,
                    "incorrect value for reserved[147], expected 66, is {}",
                    msg.reserved[147]
                );
                assert_eq!(
                    msg.reserved[148], 248,
                    "incorrect value for reserved[148], expected 248, is {}",
                    msg.reserved[148]
                );
                assert_eq!(
                    msg.reserved[149], 116,
                    "incorrect value for reserved[149], expected 116, is {}",
                    msg.reserved[149]
                );
                assert_eq!(
                    msg.reserved[150], 88,
                    "incorrect value for reserved[150], expected 88, is {}",
                    msg.reserved[150]
                );
                assert_eq!(
                    msg.reserved[151], 90,
                    "incorrect value for reserved[151], expected 90, is {}",
                    msg.reserved[151]
                );
                assert_eq!(
                    msg.reserved[152], 128,
                    "incorrect value for reserved[152], expected 128, is {}",
                    msg.reserved[152]
                );
                assert_eq!(
                    msg.reserved[153], 226,
                    "incorrect value for reserved[153], expected 226, is {}",
                    msg.reserved[153]
                );
                assert_eq!(
                    msg.reserved[154], 177,
                    "incorrect value for reserved[154], expected 177, is {}",
                    msg.reserved[154]
                );
                assert_eq!(
                    msg.reserved[155], 0,
                    "incorrect value for reserved[155], expected 0, is {}",
                    msg.reserved[155]
                );
                assert_eq!(
                    msg.reserved[156], 47,
                    "incorrect value for reserved[156], expected 47, is {}",
                    msg.reserved[156]
                );
                assert_eq!(
                    msg.reserved[157], 140,
                    "incorrect value for reserved[157], expected 140, is {}",
                    msg.reserved[157]
                );
                assert_eq!(
                    msg.reserved[158], 33,
                    "incorrect value for reserved[158], expected 33, is {}",
                    msg.reserved[158]
                );
                assert_eq!(
                    msg.reserved[159], 126,
                    "incorrect value for reserved[159], expected 126, is {}",
                    msg.reserved[159]
                );
                assert_eq!(
                    msg.reserved[160], 221,
                    "incorrect value for reserved[160], expected 221, is {}",
                    msg.reserved[160]
                );
                assert_eq!(
                    msg.reserved[161], 110,
                    "incorrect value for reserved[161], expected 110, is {}",
                    msg.reserved[161]
                );
                assert_eq!(
                    msg.reserved[162], 144,
                    "incorrect value for reserved[162], expected 144, is {}",
                    msg.reserved[162]
                );
                assert_eq!(
                    msg.reserved[163], 97,
                    "incorrect value for reserved[163], expected 97, is {}",
                    msg.reserved[163]
                );
                assert_eq!(
                    msg.reserved[164], 74,
                    "incorrect value for reserved[164], expected 74, is {}",
                    msg.reserved[164]
                );
                assert_eq!(
                    msg.reserved[165], 250,
                    "incorrect value for reserved[165], expected 250, is {}",
                    msg.reserved[165]
                );
                assert_eq!(
                    msg.reserved[166], 181,
                    "incorrect value for reserved[166], expected 181, is {}",
                    msg.reserved[166]
                );
                assert_eq!(
                    msg.reserved[167], 199,
                    "incorrect value for reserved[167], expected 199, is {}",
                    msg.reserved[167]
                );
                assert_eq!(
                    msg.reserved[168], 27,
                    "incorrect value for reserved[168], expected 27, is {}",
                    msg.reserved[168]
                );
                assert_eq!(
                    msg.reserved[169], 176,
                    "incorrect value for reserved[169], expected 176, is {}",
                    msg.reserved[169]
                );
                assert_eq!(
                    msg.reserved[170], 65,
                    "incorrect value for reserved[170], expected 65, is {}",
                    msg.reserved[170]
                );
                assert_eq!(
                    msg.reserved[171], 185,
                    "incorrect value for reserved[171], expected 185, is {}",
                    msg.reserved[171]
                );
                assert_eq!(
                    msg.reserved[172], 110,
                    "incorrect value for reserved[172], expected 110, is {}",
                    msg.reserved[172]
                );
                assert_eq!(
                    msg.reserved[173], 92,
                    "incorrect value for reserved[173], expected 92, is {}",
                    msg.reserved[173]
                );
                assert_eq!(
                    msg.reserved[174], 34,
                    "incorrect value for reserved[174], expected 34, is {}",
                    msg.reserved[174]
                );
                assert_eq!(
                    msg.reserved[175], 44,
                    "incorrect value for reserved[175], expected 44, is {}",
                    msg.reserved[175]
                );
                assert_eq!(
                    msg.reserved[176], 131,
                    "incorrect value for reserved[176], expected 131, is {}",
                    msg.reserved[176]
                );
                assert_eq!(
                    msg.reserved[177], 96,
                    "incorrect value for reserved[177], expected 96, is {}",
                    msg.reserved[177]
                );
                assert_eq!(
                    msg.reserved[178], 178,
                    "incorrect value for reserved[178], expected 178, is {}",
                    msg.reserved[178]
                );
                assert_eq!(
                    msg.reserved[179], 40,
                    "incorrect value for reserved[179], expected 40, is {}",
                    msg.reserved[179]
                );
                assert_eq!(
                    msg.reserved[180], 176,
                    "incorrect value for reserved[180], expected 176, is {}",
                    msg.reserved[180]
                );
                assert_eq!(
                    msg.reserved[181], 4,
                    "incorrect value for reserved[181], expected 4, is {}",
                    msg.reserved[181]
                );
                assert_eq!(
                    msg.reserved[182], 90,
                    "incorrect value for reserved[182], expected 90, is {}",
                    msg.reserved[182]
                );
                assert_eq!(
                    msg.reserved[183], 36,
                    "incorrect value for reserved[183], expected 36, is {}",
                    msg.reserved[183]
                );
                assert_eq!(
                    msg.reserved[184], 7,
                    "incorrect value for reserved[184], expected 7, is {}",
                    msg.reserved[184]
                );
                assert_eq!(
                    msg.reserved[185], 180,
                    "incorrect value for reserved[185], expected 180, is {}",
                    msg.reserved[185]
                );
                assert_eq!(
                    msg.reserved[186], 244,
                    "incorrect value for reserved[186], expected 244, is {}",
                    msg.reserved[186]
                );
                assert_eq!(
                    msg.reserved[187], 244,
                    "incorrect value for reserved[187], expected 244, is {}",
                    msg.reserved[187]
                );
                assert_eq!(
                    msg.reserved[188], 23,
                    "incorrect value for reserved[188], expected 23, is {}",
                    msg.reserved[188]
                );
                assert_eq!(
                    msg.reserved[189], 108,
                    "incorrect value for reserved[189], expected 108, is {}",
                    msg.reserved[189]
                );
                assert_eq!(
                    msg.reserved[190], 171,
                    "incorrect value for reserved[190], expected 171, is {}",
                    msg.reserved[190]
                );
                assert_eq!(
                    msg.reserved[191], 204,
                    "incorrect value for reserved[191], expected 204, is {}",
                    msg.reserved[191]
                );
                assert_eq!(
                    msg.reserved[192], 196,
                    "incorrect value for reserved[192], expected 196, is {}",
                    msg.reserved[192]
                );
                assert_eq!(
                    msg.reserved[193], 61,
                    "incorrect value for reserved[193], expected 61, is {}",
                    msg.reserved[193]
                );
                assert_eq!(
                    msg.reserved[194], 51,
                    "incorrect value for reserved[194], expected 51, is {}",
                    msg.reserved[194]
                );
                assert_eq!(
                    msg.reserved[195], 179,
                    "incorrect value for reserved[195], expected 179, is {}",
                    msg.reserved[195]
                );
                assert_eq!(
                    msg.reserved[196], 242,
                    "incorrect value for reserved[196], expected 242, is {}",
                    msg.reserved[196]
                );
                assert_eq!(
                    msg.reserved[197], 156,
                    "incorrect value for reserved[197], expected 156, is {}",
                    msg.reserved[197]
                );
                assert_eq!(
                    msg.reserved[198], 81,
                    "incorrect value for reserved[198], expected 81, is {}",
                    msg.reserved[198]
                );
                assert_eq!(
                    msg.reserved[199], 83,
                    "incorrect value for reserved[199], expected 83, is {}",
                    msg.reserved[199]
                );
                assert_eq!(
                    msg.reserved[200], 16,
                    "incorrect value for reserved[200], expected 16, is {}",
                    msg.reserved[200]
                );
                assert_eq!(
                    msg.reserved[201], 15,
                    "incorrect value for reserved[201], expected 15, is {}",
                    msg.reserved[201]
                );
                assert_eq!(
                    msg.reserved[202], 134,
                    "incorrect value for reserved[202], expected 134, is {}",
                    msg.reserved[202]
                );
                assert_eq!(
                    msg.reserved[203], 40,
                    "incorrect value for reserved[203], expected 40, is {}",
                    msg.reserved[203]
                );
                assert_eq!(
                    msg.reserved[204], 245,
                    "incorrect value for reserved[204], expected 245, is {}",
                    msg.reserved[204]
                );
                assert_eq!(
                    msg.reserved[205], 253,
                    "incorrect value for reserved[205], expected 253, is {}",
                    msg.reserved[205]
                );
                assert_eq!(
                    msg.reserved[206], 150,
                    "incorrect value for reserved[206], expected 150, is {}",
                    msg.reserved[206]
                );
                assert_eq!(
                    msg.reserved[207], 94,
                    "incorrect value for reserved[207], expected 94, is {}",
                    msg.reserved[207]
                );
                assert_eq!(
                    msg.reserved[208], 150,
                    "incorrect value for reserved[208], expected 150, is {}",
                    msg.reserved[208]
                );
                assert_eq!(
                    msg.reserved[209], 144,
                    "incorrect value for reserved[209], expected 144, is {}",
                    msg.reserved[209]
                );
                assert_eq!(
                    msg.reserved[210], 197,
                    "incorrect value for reserved[210], expected 197, is {}",
                    msg.reserved[210]
                );
                assert_eq!(
                    msg.reserved[211], 113,
                    "incorrect value for reserved[211], expected 113, is {}",
                    msg.reserved[211]
                );
                assert_eq!(
                    msg.reserved[212], 5,
                    "incorrect value for reserved[212], expected 5, is {}",
                    msg.reserved[212]
                );
                assert_eq!(
                    msg.reserved[213], 141,
                    "incorrect value for reserved[213], expected 141, is {}",
                    msg.reserved[213]
                );
                assert_eq!(
                    msg.reserved[214], 232,
                    "incorrect value for reserved[214], expected 232, is {}",
                    msg.reserved[214]
                );
                assert_eq!(
                    msg.reserved[215], 33,
                    "incorrect value for reserved[215], expected 33, is {}",
                    msg.reserved[215]
                );
                assert_eq!(
                    msg.reserved[216], 101,
                    "incorrect value for reserved[216], expected 101, is {}",
                    msg.reserved[216]
                );
                assert_eq!(
                    msg.reserved[217], 231,
                    "incorrect value for reserved[217], expected 231, is {}",
                    msg.reserved[217]
                );
                assert_eq!(
                    msg.reserved[218], 38,
                    "incorrect value for reserved[218], expected 38, is {}",
                    msg.reserved[218]
                );
                assert_eq!(
                    msg.reserved[219], 75,
                    "incorrect value for reserved[219], expected 75, is {}",
                    msg.reserved[219]
                );
                assert_eq!(
                    msg.reserved[220], 178,
                    "incorrect value for reserved[220], expected 178, is {}",
                    msg.reserved[220]
                );
                assert_eq!(
                    msg.reserved[221], 243,
                    "incorrect value for reserved[221], expected 243, is {}",
                    msg.reserved[221]
                );
                assert_eq!(
                    msg.reserved[222], 119,
                    "incorrect value for reserved[222], expected 119, is {}",
                    msg.reserved[222]
                );
                assert_eq!(
                    msg.reserved[223], 1,
                    "incorrect value for reserved[223], expected 1, is {}",
                    msg.reserved[223]
                );
                assert_eq!(
                    msg.reserved[224], 248,
                    "incorrect value for reserved[224], expected 248, is {}",
                    msg.reserved[224]
                );
                assert_eq!(
                    msg.reserved[225], 218,
                    "incorrect value for reserved[225], expected 218, is {}",
                    msg.reserved[225]
                );
                assert_eq!(
                    msg.reserved[226], 86,
                    "incorrect value for reserved[226], expected 86, is {}",
                    msg.reserved[226]
                );
                assert_eq!(
                    msg.reserved[227], 7,
                    "incorrect value for reserved[227], expected 7, is {}",
                    msg.reserved[227]
                );
                assert_eq!(
                    msg.reserved[228], 88,
                    "incorrect value for reserved[228], expected 88, is {}",
                    msg.reserved[228]
                );
                assert_eq!(
                    msg.reserved[229], 197,
                    "incorrect value for reserved[229], expected 197, is {}",
                    msg.reserved[229]
                );
                assert_eq!(
                    msg.reserved[230], 148,
                    "incorrect value for reserved[230], expected 148, is {}",
                    msg.reserved[230]
                );
                assert_eq!(
                    msg.reserved[231], 240,
                    "incorrect value for reserved[231], expected 240, is {}",
                    msg.reserved[231]
                );
                assert_eq!(
                    msg.reserved[232], 227,
                    "incorrect value for reserved[232], expected 227, is {}",
                    msg.reserved[232]
                );
                assert_eq!(
                    msg.reserved[233], 2,
                    "incorrect value for reserved[233], expected 2, is {}",
                    msg.reserved[233]
                );
                assert_eq!(
                    msg.reserved[234], 65,
                    "incorrect value for reserved[234], expected 65, is {}",
                    msg.reserved[234]
                );
                assert_eq!(
                    msg.reserved[235], 173,
                    "incorrect value for reserved[235], expected 173, is {}",
                    msg.reserved[235]
                );
                assert_eq!(
                    msg.reserved[236], 122,
                    "incorrect value for reserved[236], expected 122, is {}",
                    msg.reserved[236]
                );
                assert_eq!(
                    msg.reserved[237], 143,
                    "incorrect value for reserved[237], expected 143, is {}",
                    msg.reserved[237]
                );
                assert_eq!(
                    msg.reserved[238], 251,
                    "incorrect value for reserved[238], expected 251, is {}",
                    msg.reserved[238]
                );
                assert_eq!(
                    msg.reserved[239], 156,
                    "incorrect value for reserved[239], expected 156, is {}",
                    msg.reserved[239]
                );
                assert_eq!(
                    msg.reserved[240], 217,
                    "incorrect value for reserved[240], expected 217, is {}",
                    msg.reserved[240]
                );
                assert_eq!(
                    msg.reserved[241], 67,
                    "incorrect value for reserved[241], expected 67, is {}",
                    msg.reserved[241]
                );
                assert_eq!(
                    msg.reserved[242], 239,
                    "incorrect value for reserved[242], expected 239, is {}",
                    msg.reserved[242]
                );
                assert_eq!(
                    msg.reserved[243], 219,
                    "incorrect value for reserved[243], expected 219, is {}",
                    msg.reserved[243]
                );
                assert_eq!(
                    msg.reserved[244], 31,
                    "incorrect value for reserved[244], expected 31, is {}",
                    msg.reserved[244]
                );
                assert_eq!(
                    msg.reserved[245], 224,
                    "incorrect value for reserved[245], expected 224, is {}",
                    msg.reserved[245]
                );
                assert_eq!(
                    msg.reserved[246], 176,
                    "incorrect value for reserved[246], expected 176, is {}",
                    msg.reserved[246]
                );
                assert_eq!(
                    msg.reserved[247], 129,
                    "incorrect value for reserved[247], expected 129, is {}",
                    msg.reserved[247]
                );
                assert_eq!(
                    msg.reserved[248], 81,
                    "incorrect value for reserved[248], expected 81, is {}",
                    msg.reserved[248]
                );
                assert_eq!(
                    msg.reserved[249], 80,
                    "incorrect value for reserved[249], expected 80, is {}",
                    msg.reserved[249]
                );
                assert!(msg.signal_error_rate.almost_eq( 8.58820019531250000e+03 ), "incorrect value for signal_error_rate, expected 8.58820019531250000e+03, is {:e}", msg.signal_error_rate);
                assert_eq!(
                    msg.signal_strength, 103,
                    "incorrect value for signal_strength, expected 103, is {}",
                    msg.signal_strength
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCellModemStatus"),
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
fn test_json2sbp_auto_check_sbp_piksi_msg_cell_modem_status() {
    {
        let json_input = r#"{"preamble":85,"msg_type":190,"sender":6931,"length":255,"payload":"Z80wBkZ78i40QLCaYiuExFn9ofquzG4vJrs/ZrGiMVDCJWs84TRlso72FRFdS6lWENFQ8x7O3M5zL5pb41gLAVWSZL7ozz09ydwfTiI5UjtoQd0AK9IJIHod7QuX3xJRzKzqfwNShakMsMEAGHlVN9bGS+qz1lVecxVJeUsunj9ketUUVdSDMuDa19eVAhOBJ6QFrwY+M05C+HRYWoDisQAvjCF+3W6QYUr6tccbsEG5blwiLINgsiiwBFokB7T09Bdsq8zEPTOz8pxRUxAPhij1/ZZelpDFcQWN6CFl5yZLsvN3AfjaVgdYxZTw4wJBrXqP+5zZQ+/bH+CwgVFQ","crc":58920,"signal_strength":103,"signal_error_rate":8588.2001953125,"reserved":[123,242,46,52,64,176,154,98,43,132,196,89,253,161,250,174,204,110,47,38,187,63,102,177,162,49,80,194,37,107,60,225,52,101,178,142,246,21,17,93,75,169,86,16,209,80,243,30,206,220,206,115,47,154,91,227,88,11,1,85,146,100,190,232,207,61,61,201,220,31,78,34,57,82,59,104,65,221,0,43,210,9,32,122,29,237,11,151,223,18,81,204,172,234,127,3,82,133,169,12,176,193,0,24,121,85,55,214,198,75,234,179,214,85,94,115,21,73,121,75,46,158,63,100,122,213,20,85,212,131,50,224,218,215,215,149,2,19,129,39,164,5,175,6,62,51,78,66,248,116,88,90,128,226,177,0,47,140,33,126,221,110,144,97,74,250,181,199,27,176,65,185,110,92,34,44,131,96,178,40,176,4,90,36,7,180,244,244,23,108,171,204,196,61,51,179,242,156,81,83,16,15,134,40,245,253,150,94,150,144,197,113,5,141,232,33,101,231,38,75,178,243,119,1,248,218,86,7,88,197,148,240,227,2,65,173,122,143,251,156,217,67,239,219,31,224,176,129,81,80]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgCellModemStatus(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xbe,
                    "Incorrect message type, expected 0xbe, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1b13,
                    "incorrect sender id, expected 0x1b13, is {sender_id}"
                );
                assert_eq!(
                    msg.reserved[0], 123,
                    "incorrect value for reserved[0], expected 123, is {}",
                    msg.reserved[0]
                );
                assert_eq!(
                    msg.reserved[1], 242,
                    "incorrect value for reserved[1], expected 242, is {}",
                    msg.reserved[1]
                );
                assert_eq!(
                    msg.reserved[2], 46,
                    "incorrect value for reserved[2], expected 46, is {}",
                    msg.reserved[2]
                );
                assert_eq!(
                    msg.reserved[3], 52,
                    "incorrect value for reserved[3], expected 52, is {}",
                    msg.reserved[3]
                );
                assert_eq!(
                    msg.reserved[4], 64,
                    "incorrect value for reserved[4], expected 64, is {}",
                    msg.reserved[4]
                );
                assert_eq!(
                    msg.reserved[5], 176,
                    "incorrect value for reserved[5], expected 176, is {}",
                    msg.reserved[5]
                );
                assert_eq!(
                    msg.reserved[6], 154,
                    "incorrect value for reserved[6], expected 154, is {}",
                    msg.reserved[6]
                );
                assert_eq!(
                    msg.reserved[7], 98,
                    "incorrect value for reserved[7], expected 98, is {}",
                    msg.reserved[7]
                );
                assert_eq!(
                    msg.reserved[8], 43,
                    "incorrect value for reserved[8], expected 43, is {}",
                    msg.reserved[8]
                );
                assert_eq!(
                    msg.reserved[9], 132,
                    "incorrect value for reserved[9], expected 132, is {}",
                    msg.reserved[9]
                );
                assert_eq!(
                    msg.reserved[10], 196,
                    "incorrect value for reserved[10], expected 196, is {}",
                    msg.reserved[10]
                );
                assert_eq!(
                    msg.reserved[11], 89,
                    "incorrect value for reserved[11], expected 89, is {}",
                    msg.reserved[11]
                );
                assert_eq!(
                    msg.reserved[12], 253,
                    "incorrect value for reserved[12], expected 253, is {}",
                    msg.reserved[12]
                );
                assert_eq!(
                    msg.reserved[13], 161,
                    "incorrect value for reserved[13], expected 161, is {}",
                    msg.reserved[13]
                );
                assert_eq!(
                    msg.reserved[14], 250,
                    "incorrect value for reserved[14], expected 250, is {}",
                    msg.reserved[14]
                );
                assert_eq!(
                    msg.reserved[15], 174,
                    "incorrect value for reserved[15], expected 174, is {}",
                    msg.reserved[15]
                );
                assert_eq!(
                    msg.reserved[16], 204,
                    "incorrect value for reserved[16], expected 204, is {}",
                    msg.reserved[16]
                );
                assert_eq!(
                    msg.reserved[17], 110,
                    "incorrect value for reserved[17], expected 110, is {}",
                    msg.reserved[17]
                );
                assert_eq!(
                    msg.reserved[18], 47,
                    "incorrect value for reserved[18], expected 47, is {}",
                    msg.reserved[18]
                );
                assert_eq!(
                    msg.reserved[19], 38,
                    "incorrect value for reserved[19], expected 38, is {}",
                    msg.reserved[19]
                );
                assert_eq!(
                    msg.reserved[20], 187,
                    "incorrect value for reserved[20], expected 187, is {}",
                    msg.reserved[20]
                );
                assert_eq!(
                    msg.reserved[21], 63,
                    "incorrect value for reserved[21], expected 63, is {}",
                    msg.reserved[21]
                );
                assert_eq!(
                    msg.reserved[22], 102,
                    "incorrect value for reserved[22], expected 102, is {}",
                    msg.reserved[22]
                );
                assert_eq!(
                    msg.reserved[23], 177,
                    "incorrect value for reserved[23], expected 177, is {}",
                    msg.reserved[23]
                );
                assert_eq!(
                    msg.reserved[24], 162,
                    "incorrect value for reserved[24], expected 162, is {}",
                    msg.reserved[24]
                );
                assert_eq!(
                    msg.reserved[25], 49,
                    "incorrect value for reserved[25], expected 49, is {}",
                    msg.reserved[25]
                );
                assert_eq!(
                    msg.reserved[26], 80,
                    "incorrect value for reserved[26], expected 80, is {}",
                    msg.reserved[26]
                );
                assert_eq!(
                    msg.reserved[27], 194,
                    "incorrect value for reserved[27], expected 194, is {}",
                    msg.reserved[27]
                );
                assert_eq!(
                    msg.reserved[28], 37,
                    "incorrect value for reserved[28], expected 37, is {}",
                    msg.reserved[28]
                );
                assert_eq!(
                    msg.reserved[29], 107,
                    "incorrect value for reserved[29], expected 107, is {}",
                    msg.reserved[29]
                );
                assert_eq!(
                    msg.reserved[30], 60,
                    "incorrect value for reserved[30], expected 60, is {}",
                    msg.reserved[30]
                );
                assert_eq!(
                    msg.reserved[31], 225,
                    "incorrect value for reserved[31], expected 225, is {}",
                    msg.reserved[31]
                );
                assert_eq!(
                    msg.reserved[32], 52,
                    "incorrect value for reserved[32], expected 52, is {}",
                    msg.reserved[32]
                );
                assert_eq!(
                    msg.reserved[33], 101,
                    "incorrect value for reserved[33], expected 101, is {}",
                    msg.reserved[33]
                );
                assert_eq!(
                    msg.reserved[34], 178,
                    "incorrect value for reserved[34], expected 178, is {}",
                    msg.reserved[34]
                );
                assert_eq!(
                    msg.reserved[35], 142,
                    "incorrect value for reserved[35], expected 142, is {}",
                    msg.reserved[35]
                );
                assert_eq!(
                    msg.reserved[36], 246,
                    "incorrect value for reserved[36], expected 246, is {}",
                    msg.reserved[36]
                );
                assert_eq!(
                    msg.reserved[37], 21,
                    "incorrect value for reserved[37], expected 21, is {}",
                    msg.reserved[37]
                );
                assert_eq!(
                    msg.reserved[38], 17,
                    "incorrect value for reserved[38], expected 17, is {}",
                    msg.reserved[38]
                );
                assert_eq!(
                    msg.reserved[39], 93,
                    "incorrect value for reserved[39], expected 93, is {}",
                    msg.reserved[39]
                );
                assert_eq!(
                    msg.reserved[40], 75,
                    "incorrect value for reserved[40], expected 75, is {}",
                    msg.reserved[40]
                );
                assert_eq!(
                    msg.reserved[41], 169,
                    "incorrect value for reserved[41], expected 169, is {}",
                    msg.reserved[41]
                );
                assert_eq!(
                    msg.reserved[42], 86,
                    "incorrect value for reserved[42], expected 86, is {}",
                    msg.reserved[42]
                );
                assert_eq!(
                    msg.reserved[43], 16,
                    "incorrect value for reserved[43], expected 16, is {}",
                    msg.reserved[43]
                );
                assert_eq!(
                    msg.reserved[44], 209,
                    "incorrect value for reserved[44], expected 209, is {}",
                    msg.reserved[44]
                );
                assert_eq!(
                    msg.reserved[45], 80,
                    "incorrect value for reserved[45], expected 80, is {}",
                    msg.reserved[45]
                );
                assert_eq!(
                    msg.reserved[46], 243,
                    "incorrect value for reserved[46], expected 243, is {}",
                    msg.reserved[46]
                );
                assert_eq!(
                    msg.reserved[47], 30,
                    "incorrect value for reserved[47], expected 30, is {}",
                    msg.reserved[47]
                );
                assert_eq!(
                    msg.reserved[48], 206,
                    "incorrect value for reserved[48], expected 206, is {}",
                    msg.reserved[48]
                );
                assert_eq!(
                    msg.reserved[49], 220,
                    "incorrect value for reserved[49], expected 220, is {}",
                    msg.reserved[49]
                );
                assert_eq!(
                    msg.reserved[50], 206,
                    "incorrect value for reserved[50], expected 206, is {}",
                    msg.reserved[50]
                );
                assert_eq!(
                    msg.reserved[51], 115,
                    "incorrect value for reserved[51], expected 115, is {}",
                    msg.reserved[51]
                );
                assert_eq!(
                    msg.reserved[52], 47,
                    "incorrect value for reserved[52], expected 47, is {}",
                    msg.reserved[52]
                );
                assert_eq!(
                    msg.reserved[53], 154,
                    "incorrect value for reserved[53], expected 154, is {}",
                    msg.reserved[53]
                );
                assert_eq!(
                    msg.reserved[54], 91,
                    "incorrect value for reserved[54], expected 91, is {}",
                    msg.reserved[54]
                );
                assert_eq!(
                    msg.reserved[55], 227,
                    "incorrect value for reserved[55], expected 227, is {}",
                    msg.reserved[55]
                );
                assert_eq!(
                    msg.reserved[56], 88,
                    "incorrect value for reserved[56], expected 88, is {}",
                    msg.reserved[56]
                );
                assert_eq!(
                    msg.reserved[57], 11,
                    "incorrect value for reserved[57], expected 11, is {}",
                    msg.reserved[57]
                );
                assert_eq!(
                    msg.reserved[58], 1,
                    "incorrect value for reserved[58], expected 1, is {}",
                    msg.reserved[58]
                );
                assert_eq!(
                    msg.reserved[59], 85,
                    "incorrect value for reserved[59], expected 85, is {}",
                    msg.reserved[59]
                );
                assert_eq!(
                    msg.reserved[60], 146,
                    "incorrect value for reserved[60], expected 146, is {}",
                    msg.reserved[60]
                );
                assert_eq!(
                    msg.reserved[61], 100,
                    "incorrect value for reserved[61], expected 100, is {}",
                    msg.reserved[61]
                );
                assert_eq!(
                    msg.reserved[62], 190,
                    "incorrect value for reserved[62], expected 190, is {}",
                    msg.reserved[62]
                );
                assert_eq!(
                    msg.reserved[63], 232,
                    "incorrect value for reserved[63], expected 232, is {}",
                    msg.reserved[63]
                );
                assert_eq!(
                    msg.reserved[64], 207,
                    "incorrect value for reserved[64], expected 207, is {}",
                    msg.reserved[64]
                );
                assert_eq!(
                    msg.reserved[65], 61,
                    "incorrect value for reserved[65], expected 61, is {}",
                    msg.reserved[65]
                );
                assert_eq!(
                    msg.reserved[66], 61,
                    "incorrect value for reserved[66], expected 61, is {}",
                    msg.reserved[66]
                );
                assert_eq!(
                    msg.reserved[67], 201,
                    "incorrect value for reserved[67], expected 201, is {}",
                    msg.reserved[67]
                );
                assert_eq!(
                    msg.reserved[68], 220,
                    "incorrect value for reserved[68], expected 220, is {}",
                    msg.reserved[68]
                );
                assert_eq!(
                    msg.reserved[69], 31,
                    "incorrect value for reserved[69], expected 31, is {}",
                    msg.reserved[69]
                );
                assert_eq!(
                    msg.reserved[70], 78,
                    "incorrect value for reserved[70], expected 78, is {}",
                    msg.reserved[70]
                );
                assert_eq!(
                    msg.reserved[71], 34,
                    "incorrect value for reserved[71], expected 34, is {}",
                    msg.reserved[71]
                );
                assert_eq!(
                    msg.reserved[72], 57,
                    "incorrect value for reserved[72], expected 57, is {}",
                    msg.reserved[72]
                );
                assert_eq!(
                    msg.reserved[73], 82,
                    "incorrect value for reserved[73], expected 82, is {}",
                    msg.reserved[73]
                );
                assert_eq!(
                    msg.reserved[74], 59,
                    "incorrect value for reserved[74], expected 59, is {}",
                    msg.reserved[74]
                );
                assert_eq!(
                    msg.reserved[75], 104,
                    "incorrect value for reserved[75], expected 104, is {}",
                    msg.reserved[75]
                );
                assert_eq!(
                    msg.reserved[76], 65,
                    "incorrect value for reserved[76], expected 65, is {}",
                    msg.reserved[76]
                );
                assert_eq!(
                    msg.reserved[77], 221,
                    "incorrect value for reserved[77], expected 221, is {}",
                    msg.reserved[77]
                );
                assert_eq!(
                    msg.reserved[78], 0,
                    "incorrect value for reserved[78], expected 0, is {}",
                    msg.reserved[78]
                );
                assert_eq!(
                    msg.reserved[79], 43,
                    "incorrect value for reserved[79], expected 43, is {}",
                    msg.reserved[79]
                );
                assert_eq!(
                    msg.reserved[80], 210,
                    "incorrect value for reserved[80], expected 210, is {}",
                    msg.reserved[80]
                );
                assert_eq!(
                    msg.reserved[81], 9,
                    "incorrect value for reserved[81], expected 9, is {}",
                    msg.reserved[81]
                );
                assert_eq!(
                    msg.reserved[82], 32,
                    "incorrect value for reserved[82], expected 32, is {}",
                    msg.reserved[82]
                );
                assert_eq!(
                    msg.reserved[83], 122,
                    "incorrect value for reserved[83], expected 122, is {}",
                    msg.reserved[83]
                );
                assert_eq!(
                    msg.reserved[84], 29,
                    "incorrect value for reserved[84], expected 29, is {}",
                    msg.reserved[84]
                );
                assert_eq!(
                    msg.reserved[85], 237,
                    "incorrect value for reserved[85], expected 237, is {}",
                    msg.reserved[85]
                );
                assert_eq!(
                    msg.reserved[86], 11,
                    "incorrect value for reserved[86], expected 11, is {}",
                    msg.reserved[86]
                );
                assert_eq!(
                    msg.reserved[87], 151,
                    "incorrect value for reserved[87], expected 151, is {}",
                    msg.reserved[87]
                );
                assert_eq!(
                    msg.reserved[88], 223,
                    "incorrect value for reserved[88], expected 223, is {}",
                    msg.reserved[88]
                );
                assert_eq!(
                    msg.reserved[89], 18,
                    "incorrect value for reserved[89], expected 18, is {}",
                    msg.reserved[89]
                );
                assert_eq!(
                    msg.reserved[90], 81,
                    "incorrect value for reserved[90], expected 81, is {}",
                    msg.reserved[90]
                );
                assert_eq!(
                    msg.reserved[91], 204,
                    "incorrect value for reserved[91], expected 204, is {}",
                    msg.reserved[91]
                );
                assert_eq!(
                    msg.reserved[92], 172,
                    "incorrect value for reserved[92], expected 172, is {}",
                    msg.reserved[92]
                );
                assert_eq!(
                    msg.reserved[93], 234,
                    "incorrect value for reserved[93], expected 234, is {}",
                    msg.reserved[93]
                );
                assert_eq!(
                    msg.reserved[94], 127,
                    "incorrect value for reserved[94], expected 127, is {}",
                    msg.reserved[94]
                );
                assert_eq!(
                    msg.reserved[95], 3,
                    "incorrect value for reserved[95], expected 3, is {}",
                    msg.reserved[95]
                );
                assert_eq!(
                    msg.reserved[96], 82,
                    "incorrect value for reserved[96], expected 82, is {}",
                    msg.reserved[96]
                );
                assert_eq!(
                    msg.reserved[97], 133,
                    "incorrect value for reserved[97], expected 133, is {}",
                    msg.reserved[97]
                );
                assert_eq!(
                    msg.reserved[98], 169,
                    "incorrect value for reserved[98], expected 169, is {}",
                    msg.reserved[98]
                );
                assert_eq!(
                    msg.reserved[99], 12,
                    "incorrect value for reserved[99], expected 12, is {}",
                    msg.reserved[99]
                );
                assert_eq!(
                    msg.reserved[100], 176,
                    "incorrect value for reserved[100], expected 176, is {}",
                    msg.reserved[100]
                );
                assert_eq!(
                    msg.reserved[101], 193,
                    "incorrect value for reserved[101], expected 193, is {}",
                    msg.reserved[101]
                );
                assert_eq!(
                    msg.reserved[102], 0,
                    "incorrect value for reserved[102], expected 0, is {}",
                    msg.reserved[102]
                );
                assert_eq!(
                    msg.reserved[103], 24,
                    "incorrect value for reserved[103], expected 24, is {}",
                    msg.reserved[103]
                );
                assert_eq!(
                    msg.reserved[104], 121,
                    "incorrect value for reserved[104], expected 121, is {}",
                    msg.reserved[104]
                );
                assert_eq!(
                    msg.reserved[105], 85,
                    "incorrect value for reserved[105], expected 85, is {}",
                    msg.reserved[105]
                );
                assert_eq!(
                    msg.reserved[106], 55,
                    "incorrect value for reserved[106], expected 55, is {}",
                    msg.reserved[106]
                );
                assert_eq!(
                    msg.reserved[107], 214,
                    "incorrect value for reserved[107], expected 214, is {}",
                    msg.reserved[107]
                );
                assert_eq!(
                    msg.reserved[108], 198,
                    "incorrect value for reserved[108], expected 198, is {}",
                    msg.reserved[108]
                );
                assert_eq!(
                    msg.reserved[109], 75,
                    "incorrect value for reserved[109], expected 75, is {}",
                    msg.reserved[109]
                );
                assert_eq!(
                    msg.reserved[110], 234,
                    "incorrect value for reserved[110], expected 234, is {}",
                    msg.reserved[110]
                );
                assert_eq!(
                    msg.reserved[111], 179,
                    "incorrect value for reserved[111], expected 179, is {}",
                    msg.reserved[111]
                );
                assert_eq!(
                    msg.reserved[112], 214,
                    "incorrect value for reserved[112], expected 214, is {}",
                    msg.reserved[112]
                );
                assert_eq!(
                    msg.reserved[113], 85,
                    "incorrect value for reserved[113], expected 85, is {}",
                    msg.reserved[113]
                );
                assert_eq!(
                    msg.reserved[114], 94,
                    "incorrect value for reserved[114], expected 94, is {}",
                    msg.reserved[114]
                );
                assert_eq!(
                    msg.reserved[115], 115,
                    "incorrect value for reserved[115], expected 115, is {}",
                    msg.reserved[115]
                );
                assert_eq!(
                    msg.reserved[116], 21,
                    "incorrect value for reserved[116], expected 21, is {}",
                    msg.reserved[116]
                );
                assert_eq!(
                    msg.reserved[117], 73,
                    "incorrect value for reserved[117], expected 73, is {}",
                    msg.reserved[117]
                );
                assert_eq!(
                    msg.reserved[118], 121,
                    "incorrect value for reserved[118], expected 121, is {}",
                    msg.reserved[118]
                );
                assert_eq!(
                    msg.reserved[119], 75,
                    "incorrect value for reserved[119], expected 75, is {}",
                    msg.reserved[119]
                );
                assert_eq!(
                    msg.reserved[120], 46,
                    "incorrect value for reserved[120], expected 46, is {}",
                    msg.reserved[120]
                );
                assert_eq!(
                    msg.reserved[121], 158,
                    "incorrect value for reserved[121], expected 158, is {}",
                    msg.reserved[121]
                );
                assert_eq!(
                    msg.reserved[122], 63,
                    "incorrect value for reserved[122], expected 63, is {}",
                    msg.reserved[122]
                );
                assert_eq!(
                    msg.reserved[123], 100,
                    "incorrect value for reserved[123], expected 100, is {}",
                    msg.reserved[123]
                );
                assert_eq!(
                    msg.reserved[124], 122,
                    "incorrect value for reserved[124], expected 122, is {}",
                    msg.reserved[124]
                );
                assert_eq!(
                    msg.reserved[125], 213,
                    "incorrect value for reserved[125], expected 213, is {}",
                    msg.reserved[125]
                );
                assert_eq!(
                    msg.reserved[126], 20,
                    "incorrect value for reserved[126], expected 20, is {}",
                    msg.reserved[126]
                );
                assert_eq!(
                    msg.reserved[127], 85,
                    "incorrect value for reserved[127], expected 85, is {}",
                    msg.reserved[127]
                );
                assert_eq!(
                    msg.reserved[128], 212,
                    "incorrect value for reserved[128], expected 212, is {}",
                    msg.reserved[128]
                );
                assert_eq!(
                    msg.reserved[129], 131,
                    "incorrect value for reserved[129], expected 131, is {}",
                    msg.reserved[129]
                );
                assert_eq!(
                    msg.reserved[130], 50,
                    "incorrect value for reserved[130], expected 50, is {}",
                    msg.reserved[130]
                );
                assert_eq!(
                    msg.reserved[131], 224,
                    "incorrect value for reserved[131], expected 224, is {}",
                    msg.reserved[131]
                );
                assert_eq!(
                    msg.reserved[132], 218,
                    "incorrect value for reserved[132], expected 218, is {}",
                    msg.reserved[132]
                );
                assert_eq!(
                    msg.reserved[133], 215,
                    "incorrect value for reserved[133], expected 215, is {}",
                    msg.reserved[133]
                );
                assert_eq!(
                    msg.reserved[134], 215,
                    "incorrect value for reserved[134], expected 215, is {}",
                    msg.reserved[134]
                );
                assert_eq!(
                    msg.reserved[135], 149,
                    "incorrect value for reserved[135], expected 149, is {}",
                    msg.reserved[135]
                );
                assert_eq!(
                    msg.reserved[136], 2,
                    "incorrect value for reserved[136], expected 2, is {}",
                    msg.reserved[136]
                );
                assert_eq!(
                    msg.reserved[137], 19,
                    "incorrect value for reserved[137], expected 19, is {}",
                    msg.reserved[137]
                );
                assert_eq!(
                    msg.reserved[138], 129,
                    "incorrect value for reserved[138], expected 129, is {}",
                    msg.reserved[138]
                );
                assert_eq!(
                    msg.reserved[139], 39,
                    "incorrect value for reserved[139], expected 39, is {}",
                    msg.reserved[139]
                );
                assert_eq!(
                    msg.reserved[140], 164,
                    "incorrect value for reserved[140], expected 164, is {}",
                    msg.reserved[140]
                );
                assert_eq!(
                    msg.reserved[141], 5,
                    "incorrect value for reserved[141], expected 5, is {}",
                    msg.reserved[141]
                );
                assert_eq!(
                    msg.reserved[142], 175,
                    "incorrect value for reserved[142], expected 175, is {}",
                    msg.reserved[142]
                );
                assert_eq!(
                    msg.reserved[143], 6,
                    "incorrect value for reserved[143], expected 6, is {}",
                    msg.reserved[143]
                );
                assert_eq!(
                    msg.reserved[144], 62,
                    "incorrect value for reserved[144], expected 62, is {}",
                    msg.reserved[144]
                );
                assert_eq!(
                    msg.reserved[145], 51,
                    "incorrect value for reserved[145], expected 51, is {}",
                    msg.reserved[145]
                );
                assert_eq!(
                    msg.reserved[146], 78,
                    "incorrect value for reserved[146], expected 78, is {}",
                    msg.reserved[146]
                );
                assert_eq!(
                    msg.reserved[147], 66,
                    "incorrect value for reserved[147], expected 66, is {}",
                    msg.reserved[147]
                );
                assert_eq!(
                    msg.reserved[148], 248,
                    "incorrect value for reserved[148], expected 248, is {}",
                    msg.reserved[148]
                );
                assert_eq!(
                    msg.reserved[149], 116,
                    "incorrect value for reserved[149], expected 116, is {}",
                    msg.reserved[149]
                );
                assert_eq!(
                    msg.reserved[150], 88,
                    "incorrect value for reserved[150], expected 88, is {}",
                    msg.reserved[150]
                );
                assert_eq!(
                    msg.reserved[151], 90,
                    "incorrect value for reserved[151], expected 90, is {}",
                    msg.reserved[151]
                );
                assert_eq!(
                    msg.reserved[152], 128,
                    "incorrect value for reserved[152], expected 128, is {}",
                    msg.reserved[152]
                );
                assert_eq!(
                    msg.reserved[153], 226,
                    "incorrect value for reserved[153], expected 226, is {}",
                    msg.reserved[153]
                );
                assert_eq!(
                    msg.reserved[154], 177,
                    "incorrect value for reserved[154], expected 177, is {}",
                    msg.reserved[154]
                );
                assert_eq!(
                    msg.reserved[155], 0,
                    "incorrect value for reserved[155], expected 0, is {}",
                    msg.reserved[155]
                );
                assert_eq!(
                    msg.reserved[156], 47,
                    "incorrect value for reserved[156], expected 47, is {}",
                    msg.reserved[156]
                );
                assert_eq!(
                    msg.reserved[157], 140,
                    "incorrect value for reserved[157], expected 140, is {}",
                    msg.reserved[157]
                );
                assert_eq!(
                    msg.reserved[158], 33,
                    "incorrect value for reserved[158], expected 33, is {}",
                    msg.reserved[158]
                );
                assert_eq!(
                    msg.reserved[159], 126,
                    "incorrect value for reserved[159], expected 126, is {}",
                    msg.reserved[159]
                );
                assert_eq!(
                    msg.reserved[160], 221,
                    "incorrect value for reserved[160], expected 221, is {}",
                    msg.reserved[160]
                );
                assert_eq!(
                    msg.reserved[161], 110,
                    "incorrect value for reserved[161], expected 110, is {}",
                    msg.reserved[161]
                );
                assert_eq!(
                    msg.reserved[162], 144,
                    "incorrect value for reserved[162], expected 144, is {}",
                    msg.reserved[162]
                );
                assert_eq!(
                    msg.reserved[163], 97,
                    "incorrect value for reserved[163], expected 97, is {}",
                    msg.reserved[163]
                );
                assert_eq!(
                    msg.reserved[164], 74,
                    "incorrect value for reserved[164], expected 74, is {}",
                    msg.reserved[164]
                );
                assert_eq!(
                    msg.reserved[165], 250,
                    "incorrect value for reserved[165], expected 250, is {}",
                    msg.reserved[165]
                );
                assert_eq!(
                    msg.reserved[166], 181,
                    "incorrect value for reserved[166], expected 181, is {}",
                    msg.reserved[166]
                );
                assert_eq!(
                    msg.reserved[167], 199,
                    "incorrect value for reserved[167], expected 199, is {}",
                    msg.reserved[167]
                );
                assert_eq!(
                    msg.reserved[168], 27,
                    "incorrect value for reserved[168], expected 27, is {}",
                    msg.reserved[168]
                );
                assert_eq!(
                    msg.reserved[169], 176,
                    "incorrect value for reserved[169], expected 176, is {}",
                    msg.reserved[169]
                );
                assert_eq!(
                    msg.reserved[170], 65,
                    "incorrect value for reserved[170], expected 65, is {}",
                    msg.reserved[170]
                );
                assert_eq!(
                    msg.reserved[171], 185,
                    "incorrect value for reserved[171], expected 185, is {}",
                    msg.reserved[171]
                );
                assert_eq!(
                    msg.reserved[172], 110,
                    "incorrect value for reserved[172], expected 110, is {}",
                    msg.reserved[172]
                );
                assert_eq!(
                    msg.reserved[173], 92,
                    "incorrect value for reserved[173], expected 92, is {}",
                    msg.reserved[173]
                );
                assert_eq!(
                    msg.reserved[174], 34,
                    "incorrect value for reserved[174], expected 34, is {}",
                    msg.reserved[174]
                );
                assert_eq!(
                    msg.reserved[175], 44,
                    "incorrect value for reserved[175], expected 44, is {}",
                    msg.reserved[175]
                );
                assert_eq!(
                    msg.reserved[176], 131,
                    "incorrect value for reserved[176], expected 131, is {}",
                    msg.reserved[176]
                );
                assert_eq!(
                    msg.reserved[177], 96,
                    "incorrect value for reserved[177], expected 96, is {}",
                    msg.reserved[177]
                );
                assert_eq!(
                    msg.reserved[178], 178,
                    "incorrect value for reserved[178], expected 178, is {}",
                    msg.reserved[178]
                );
                assert_eq!(
                    msg.reserved[179], 40,
                    "incorrect value for reserved[179], expected 40, is {}",
                    msg.reserved[179]
                );
                assert_eq!(
                    msg.reserved[180], 176,
                    "incorrect value for reserved[180], expected 176, is {}",
                    msg.reserved[180]
                );
                assert_eq!(
                    msg.reserved[181], 4,
                    "incorrect value for reserved[181], expected 4, is {}",
                    msg.reserved[181]
                );
                assert_eq!(
                    msg.reserved[182], 90,
                    "incorrect value for reserved[182], expected 90, is {}",
                    msg.reserved[182]
                );
                assert_eq!(
                    msg.reserved[183], 36,
                    "incorrect value for reserved[183], expected 36, is {}",
                    msg.reserved[183]
                );
                assert_eq!(
                    msg.reserved[184], 7,
                    "incorrect value for reserved[184], expected 7, is {}",
                    msg.reserved[184]
                );
                assert_eq!(
                    msg.reserved[185], 180,
                    "incorrect value for reserved[185], expected 180, is {}",
                    msg.reserved[185]
                );
                assert_eq!(
                    msg.reserved[186], 244,
                    "incorrect value for reserved[186], expected 244, is {}",
                    msg.reserved[186]
                );
                assert_eq!(
                    msg.reserved[187], 244,
                    "incorrect value for reserved[187], expected 244, is {}",
                    msg.reserved[187]
                );
                assert_eq!(
                    msg.reserved[188], 23,
                    "incorrect value for reserved[188], expected 23, is {}",
                    msg.reserved[188]
                );
                assert_eq!(
                    msg.reserved[189], 108,
                    "incorrect value for reserved[189], expected 108, is {}",
                    msg.reserved[189]
                );
                assert_eq!(
                    msg.reserved[190], 171,
                    "incorrect value for reserved[190], expected 171, is {}",
                    msg.reserved[190]
                );
                assert_eq!(
                    msg.reserved[191], 204,
                    "incorrect value for reserved[191], expected 204, is {}",
                    msg.reserved[191]
                );
                assert_eq!(
                    msg.reserved[192], 196,
                    "incorrect value for reserved[192], expected 196, is {}",
                    msg.reserved[192]
                );
                assert_eq!(
                    msg.reserved[193], 61,
                    "incorrect value for reserved[193], expected 61, is {}",
                    msg.reserved[193]
                );
                assert_eq!(
                    msg.reserved[194], 51,
                    "incorrect value for reserved[194], expected 51, is {}",
                    msg.reserved[194]
                );
                assert_eq!(
                    msg.reserved[195], 179,
                    "incorrect value for reserved[195], expected 179, is {}",
                    msg.reserved[195]
                );
                assert_eq!(
                    msg.reserved[196], 242,
                    "incorrect value for reserved[196], expected 242, is {}",
                    msg.reserved[196]
                );
                assert_eq!(
                    msg.reserved[197], 156,
                    "incorrect value for reserved[197], expected 156, is {}",
                    msg.reserved[197]
                );
                assert_eq!(
                    msg.reserved[198], 81,
                    "incorrect value for reserved[198], expected 81, is {}",
                    msg.reserved[198]
                );
                assert_eq!(
                    msg.reserved[199], 83,
                    "incorrect value for reserved[199], expected 83, is {}",
                    msg.reserved[199]
                );
                assert_eq!(
                    msg.reserved[200], 16,
                    "incorrect value for reserved[200], expected 16, is {}",
                    msg.reserved[200]
                );
                assert_eq!(
                    msg.reserved[201], 15,
                    "incorrect value for reserved[201], expected 15, is {}",
                    msg.reserved[201]
                );
                assert_eq!(
                    msg.reserved[202], 134,
                    "incorrect value for reserved[202], expected 134, is {}",
                    msg.reserved[202]
                );
                assert_eq!(
                    msg.reserved[203], 40,
                    "incorrect value for reserved[203], expected 40, is {}",
                    msg.reserved[203]
                );
                assert_eq!(
                    msg.reserved[204], 245,
                    "incorrect value for reserved[204], expected 245, is {}",
                    msg.reserved[204]
                );
                assert_eq!(
                    msg.reserved[205], 253,
                    "incorrect value for reserved[205], expected 253, is {}",
                    msg.reserved[205]
                );
                assert_eq!(
                    msg.reserved[206], 150,
                    "incorrect value for reserved[206], expected 150, is {}",
                    msg.reserved[206]
                );
                assert_eq!(
                    msg.reserved[207], 94,
                    "incorrect value for reserved[207], expected 94, is {}",
                    msg.reserved[207]
                );
                assert_eq!(
                    msg.reserved[208], 150,
                    "incorrect value for reserved[208], expected 150, is {}",
                    msg.reserved[208]
                );
                assert_eq!(
                    msg.reserved[209], 144,
                    "incorrect value for reserved[209], expected 144, is {}",
                    msg.reserved[209]
                );
                assert_eq!(
                    msg.reserved[210], 197,
                    "incorrect value for reserved[210], expected 197, is {}",
                    msg.reserved[210]
                );
                assert_eq!(
                    msg.reserved[211], 113,
                    "incorrect value for reserved[211], expected 113, is {}",
                    msg.reserved[211]
                );
                assert_eq!(
                    msg.reserved[212], 5,
                    "incorrect value for reserved[212], expected 5, is {}",
                    msg.reserved[212]
                );
                assert_eq!(
                    msg.reserved[213], 141,
                    "incorrect value for reserved[213], expected 141, is {}",
                    msg.reserved[213]
                );
                assert_eq!(
                    msg.reserved[214], 232,
                    "incorrect value for reserved[214], expected 232, is {}",
                    msg.reserved[214]
                );
                assert_eq!(
                    msg.reserved[215], 33,
                    "incorrect value for reserved[215], expected 33, is {}",
                    msg.reserved[215]
                );
                assert_eq!(
                    msg.reserved[216], 101,
                    "incorrect value for reserved[216], expected 101, is {}",
                    msg.reserved[216]
                );
                assert_eq!(
                    msg.reserved[217], 231,
                    "incorrect value for reserved[217], expected 231, is {}",
                    msg.reserved[217]
                );
                assert_eq!(
                    msg.reserved[218], 38,
                    "incorrect value for reserved[218], expected 38, is {}",
                    msg.reserved[218]
                );
                assert_eq!(
                    msg.reserved[219], 75,
                    "incorrect value for reserved[219], expected 75, is {}",
                    msg.reserved[219]
                );
                assert_eq!(
                    msg.reserved[220], 178,
                    "incorrect value for reserved[220], expected 178, is {}",
                    msg.reserved[220]
                );
                assert_eq!(
                    msg.reserved[221], 243,
                    "incorrect value for reserved[221], expected 243, is {}",
                    msg.reserved[221]
                );
                assert_eq!(
                    msg.reserved[222], 119,
                    "incorrect value for reserved[222], expected 119, is {}",
                    msg.reserved[222]
                );
                assert_eq!(
                    msg.reserved[223], 1,
                    "incorrect value for reserved[223], expected 1, is {}",
                    msg.reserved[223]
                );
                assert_eq!(
                    msg.reserved[224], 248,
                    "incorrect value for reserved[224], expected 248, is {}",
                    msg.reserved[224]
                );
                assert_eq!(
                    msg.reserved[225], 218,
                    "incorrect value for reserved[225], expected 218, is {}",
                    msg.reserved[225]
                );
                assert_eq!(
                    msg.reserved[226], 86,
                    "incorrect value for reserved[226], expected 86, is {}",
                    msg.reserved[226]
                );
                assert_eq!(
                    msg.reserved[227], 7,
                    "incorrect value for reserved[227], expected 7, is {}",
                    msg.reserved[227]
                );
                assert_eq!(
                    msg.reserved[228], 88,
                    "incorrect value for reserved[228], expected 88, is {}",
                    msg.reserved[228]
                );
                assert_eq!(
                    msg.reserved[229], 197,
                    "incorrect value for reserved[229], expected 197, is {}",
                    msg.reserved[229]
                );
                assert_eq!(
                    msg.reserved[230], 148,
                    "incorrect value for reserved[230], expected 148, is {}",
                    msg.reserved[230]
                );
                assert_eq!(
                    msg.reserved[231], 240,
                    "incorrect value for reserved[231], expected 240, is {}",
                    msg.reserved[231]
                );
                assert_eq!(
                    msg.reserved[232], 227,
                    "incorrect value for reserved[232], expected 227, is {}",
                    msg.reserved[232]
                );
                assert_eq!(
                    msg.reserved[233], 2,
                    "incorrect value for reserved[233], expected 2, is {}",
                    msg.reserved[233]
                );
                assert_eq!(
                    msg.reserved[234], 65,
                    "incorrect value for reserved[234], expected 65, is {}",
                    msg.reserved[234]
                );
                assert_eq!(
                    msg.reserved[235], 173,
                    "incorrect value for reserved[235], expected 173, is {}",
                    msg.reserved[235]
                );
                assert_eq!(
                    msg.reserved[236], 122,
                    "incorrect value for reserved[236], expected 122, is {}",
                    msg.reserved[236]
                );
                assert_eq!(
                    msg.reserved[237], 143,
                    "incorrect value for reserved[237], expected 143, is {}",
                    msg.reserved[237]
                );
                assert_eq!(
                    msg.reserved[238], 251,
                    "incorrect value for reserved[238], expected 251, is {}",
                    msg.reserved[238]
                );
                assert_eq!(
                    msg.reserved[239], 156,
                    "incorrect value for reserved[239], expected 156, is {}",
                    msg.reserved[239]
                );
                assert_eq!(
                    msg.reserved[240], 217,
                    "incorrect value for reserved[240], expected 217, is {}",
                    msg.reserved[240]
                );
                assert_eq!(
                    msg.reserved[241], 67,
                    "incorrect value for reserved[241], expected 67, is {}",
                    msg.reserved[241]
                );
                assert_eq!(
                    msg.reserved[242], 239,
                    "incorrect value for reserved[242], expected 239, is {}",
                    msg.reserved[242]
                );
                assert_eq!(
                    msg.reserved[243], 219,
                    "incorrect value for reserved[243], expected 219, is {}",
                    msg.reserved[243]
                );
                assert_eq!(
                    msg.reserved[244], 31,
                    "incorrect value for reserved[244], expected 31, is {}",
                    msg.reserved[244]
                );
                assert_eq!(
                    msg.reserved[245], 224,
                    "incorrect value for reserved[245], expected 224, is {}",
                    msg.reserved[245]
                );
                assert_eq!(
                    msg.reserved[246], 176,
                    "incorrect value for reserved[246], expected 176, is {}",
                    msg.reserved[246]
                );
                assert_eq!(
                    msg.reserved[247], 129,
                    "incorrect value for reserved[247], expected 129, is {}",
                    msg.reserved[247]
                );
                assert_eq!(
                    msg.reserved[248], 81,
                    "incorrect value for reserved[248], expected 81, is {}",
                    msg.reserved[248]
                );
                assert_eq!(
                    msg.reserved[249], 80,
                    "incorrect value for reserved[249], expected 80, is {}",
                    msg.reserved[249]
                );
                assert!(msg.signal_error_rate.almost_eq( 8.58820019531250000e+03 ), "incorrect value for signal_error_rate, expected 8.58820019531250000e+03, is {:e}", msg.signal_error_rate);
                assert_eq!(
                    msg.signal_strength, 103,
                    "incorrect value for signal_strength, expected 103, is {}",
                    msg.signal_strength
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCellModemStatus"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_piksi_msg_cell_modem_status`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_piksi_msg_cell_modem_status() {
    {
        let mut payload = Cursor::new(vec![
            85, 190, 0, 19, 27, 255, 103, 205, 48, 6, 70, 123, 242, 46, 52, 64, 176, 154, 98, 43,
            132, 196, 89, 253, 161, 250, 174, 204, 110, 47, 38, 187, 63, 102, 177, 162, 49, 80,
            194, 37, 107, 60, 225, 52, 101, 178, 142, 246, 21, 17, 93, 75, 169, 86, 16, 209, 80,
            243, 30, 206, 220, 206, 115, 47, 154, 91, 227, 88, 11, 1, 85, 146, 100, 190, 232, 207,
            61, 61, 201, 220, 31, 78, 34, 57, 82, 59, 104, 65, 221, 0, 43, 210, 9, 32, 122, 29,
            237, 11, 151, 223, 18, 81, 204, 172, 234, 127, 3, 82, 133, 169, 12, 176, 193, 0, 24,
            121, 85, 55, 214, 198, 75, 234, 179, 214, 85, 94, 115, 21, 73, 121, 75, 46, 158, 63,
            100, 122, 213, 20, 85, 212, 131, 50, 224, 218, 215, 215, 149, 2, 19, 129, 39, 164, 5,
            175, 6, 62, 51, 78, 66, 248, 116, 88, 90, 128, 226, 177, 0, 47, 140, 33, 126, 221, 110,
            144, 97, 74, 250, 181, 199, 27, 176, 65, 185, 110, 92, 34, 44, 131, 96, 178, 40, 176,
            4, 90, 36, 7, 180, 244, 244, 23, 108, 171, 204, 196, 61, 51, 179, 242, 156, 81, 83, 16,
            15, 134, 40, 245, 253, 150, 94, 150, 144, 197, 113, 5, 141, 232, 33, 101, 231, 38, 75,
            178, 243, 119, 1, 248, 218, 86, 7, 88, 197, 148, 240, 227, 2, 65, 173, 122, 143, 251,
            156, 217, 67, 239, 219, 31, 224, 176, 129, 81, 80, 40, 230,
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
        let sbp_msg = sbp::messages::Sbp::MsgCellModemStatus(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgCellModemStatus(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xbe,
                    "Incorrect message type, expected 0xbe, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1b13,
                    "incorrect sender id, expected 0x1b13, is {sender_id}"
                );
                assert_eq!(
                    msg.reserved[0], 123,
                    "incorrect value for reserved[0], expected 123, is {}",
                    msg.reserved[0]
                );
                assert_eq!(
                    msg.reserved[1], 242,
                    "incorrect value for reserved[1], expected 242, is {}",
                    msg.reserved[1]
                );
                assert_eq!(
                    msg.reserved[2], 46,
                    "incorrect value for reserved[2], expected 46, is {}",
                    msg.reserved[2]
                );
                assert_eq!(
                    msg.reserved[3], 52,
                    "incorrect value for reserved[3], expected 52, is {}",
                    msg.reserved[3]
                );
                assert_eq!(
                    msg.reserved[4], 64,
                    "incorrect value for reserved[4], expected 64, is {}",
                    msg.reserved[4]
                );
                assert_eq!(
                    msg.reserved[5], 176,
                    "incorrect value for reserved[5], expected 176, is {}",
                    msg.reserved[5]
                );
                assert_eq!(
                    msg.reserved[6], 154,
                    "incorrect value for reserved[6], expected 154, is {}",
                    msg.reserved[6]
                );
                assert_eq!(
                    msg.reserved[7], 98,
                    "incorrect value for reserved[7], expected 98, is {}",
                    msg.reserved[7]
                );
                assert_eq!(
                    msg.reserved[8], 43,
                    "incorrect value for reserved[8], expected 43, is {}",
                    msg.reserved[8]
                );
                assert_eq!(
                    msg.reserved[9], 132,
                    "incorrect value for reserved[9], expected 132, is {}",
                    msg.reserved[9]
                );
                assert_eq!(
                    msg.reserved[10], 196,
                    "incorrect value for reserved[10], expected 196, is {}",
                    msg.reserved[10]
                );
                assert_eq!(
                    msg.reserved[11], 89,
                    "incorrect value for reserved[11], expected 89, is {}",
                    msg.reserved[11]
                );
                assert_eq!(
                    msg.reserved[12], 253,
                    "incorrect value for reserved[12], expected 253, is {}",
                    msg.reserved[12]
                );
                assert_eq!(
                    msg.reserved[13], 161,
                    "incorrect value for reserved[13], expected 161, is {}",
                    msg.reserved[13]
                );
                assert_eq!(
                    msg.reserved[14], 250,
                    "incorrect value for reserved[14], expected 250, is {}",
                    msg.reserved[14]
                );
                assert_eq!(
                    msg.reserved[15], 174,
                    "incorrect value for reserved[15], expected 174, is {}",
                    msg.reserved[15]
                );
                assert_eq!(
                    msg.reserved[16], 204,
                    "incorrect value for reserved[16], expected 204, is {}",
                    msg.reserved[16]
                );
                assert_eq!(
                    msg.reserved[17], 110,
                    "incorrect value for reserved[17], expected 110, is {}",
                    msg.reserved[17]
                );
                assert_eq!(
                    msg.reserved[18], 47,
                    "incorrect value for reserved[18], expected 47, is {}",
                    msg.reserved[18]
                );
                assert_eq!(
                    msg.reserved[19], 38,
                    "incorrect value for reserved[19], expected 38, is {}",
                    msg.reserved[19]
                );
                assert_eq!(
                    msg.reserved[20], 187,
                    "incorrect value for reserved[20], expected 187, is {}",
                    msg.reserved[20]
                );
                assert_eq!(
                    msg.reserved[21], 63,
                    "incorrect value for reserved[21], expected 63, is {}",
                    msg.reserved[21]
                );
                assert_eq!(
                    msg.reserved[22], 102,
                    "incorrect value for reserved[22], expected 102, is {}",
                    msg.reserved[22]
                );
                assert_eq!(
                    msg.reserved[23], 177,
                    "incorrect value for reserved[23], expected 177, is {}",
                    msg.reserved[23]
                );
                assert_eq!(
                    msg.reserved[24], 162,
                    "incorrect value for reserved[24], expected 162, is {}",
                    msg.reserved[24]
                );
                assert_eq!(
                    msg.reserved[25], 49,
                    "incorrect value for reserved[25], expected 49, is {}",
                    msg.reserved[25]
                );
                assert_eq!(
                    msg.reserved[26], 80,
                    "incorrect value for reserved[26], expected 80, is {}",
                    msg.reserved[26]
                );
                assert_eq!(
                    msg.reserved[27], 194,
                    "incorrect value for reserved[27], expected 194, is {}",
                    msg.reserved[27]
                );
                assert_eq!(
                    msg.reserved[28], 37,
                    "incorrect value for reserved[28], expected 37, is {}",
                    msg.reserved[28]
                );
                assert_eq!(
                    msg.reserved[29], 107,
                    "incorrect value for reserved[29], expected 107, is {}",
                    msg.reserved[29]
                );
                assert_eq!(
                    msg.reserved[30], 60,
                    "incorrect value for reserved[30], expected 60, is {}",
                    msg.reserved[30]
                );
                assert_eq!(
                    msg.reserved[31], 225,
                    "incorrect value for reserved[31], expected 225, is {}",
                    msg.reserved[31]
                );
                assert_eq!(
                    msg.reserved[32], 52,
                    "incorrect value for reserved[32], expected 52, is {}",
                    msg.reserved[32]
                );
                assert_eq!(
                    msg.reserved[33], 101,
                    "incorrect value for reserved[33], expected 101, is {}",
                    msg.reserved[33]
                );
                assert_eq!(
                    msg.reserved[34], 178,
                    "incorrect value for reserved[34], expected 178, is {}",
                    msg.reserved[34]
                );
                assert_eq!(
                    msg.reserved[35], 142,
                    "incorrect value for reserved[35], expected 142, is {}",
                    msg.reserved[35]
                );
                assert_eq!(
                    msg.reserved[36], 246,
                    "incorrect value for reserved[36], expected 246, is {}",
                    msg.reserved[36]
                );
                assert_eq!(
                    msg.reserved[37], 21,
                    "incorrect value for reserved[37], expected 21, is {}",
                    msg.reserved[37]
                );
                assert_eq!(
                    msg.reserved[38], 17,
                    "incorrect value for reserved[38], expected 17, is {}",
                    msg.reserved[38]
                );
                assert_eq!(
                    msg.reserved[39], 93,
                    "incorrect value for reserved[39], expected 93, is {}",
                    msg.reserved[39]
                );
                assert_eq!(
                    msg.reserved[40], 75,
                    "incorrect value for reserved[40], expected 75, is {}",
                    msg.reserved[40]
                );
                assert_eq!(
                    msg.reserved[41], 169,
                    "incorrect value for reserved[41], expected 169, is {}",
                    msg.reserved[41]
                );
                assert_eq!(
                    msg.reserved[42], 86,
                    "incorrect value for reserved[42], expected 86, is {}",
                    msg.reserved[42]
                );
                assert_eq!(
                    msg.reserved[43], 16,
                    "incorrect value for reserved[43], expected 16, is {}",
                    msg.reserved[43]
                );
                assert_eq!(
                    msg.reserved[44], 209,
                    "incorrect value for reserved[44], expected 209, is {}",
                    msg.reserved[44]
                );
                assert_eq!(
                    msg.reserved[45], 80,
                    "incorrect value for reserved[45], expected 80, is {}",
                    msg.reserved[45]
                );
                assert_eq!(
                    msg.reserved[46], 243,
                    "incorrect value for reserved[46], expected 243, is {}",
                    msg.reserved[46]
                );
                assert_eq!(
                    msg.reserved[47], 30,
                    "incorrect value for reserved[47], expected 30, is {}",
                    msg.reserved[47]
                );
                assert_eq!(
                    msg.reserved[48], 206,
                    "incorrect value for reserved[48], expected 206, is {}",
                    msg.reserved[48]
                );
                assert_eq!(
                    msg.reserved[49], 220,
                    "incorrect value for reserved[49], expected 220, is {}",
                    msg.reserved[49]
                );
                assert_eq!(
                    msg.reserved[50], 206,
                    "incorrect value for reserved[50], expected 206, is {}",
                    msg.reserved[50]
                );
                assert_eq!(
                    msg.reserved[51], 115,
                    "incorrect value for reserved[51], expected 115, is {}",
                    msg.reserved[51]
                );
                assert_eq!(
                    msg.reserved[52], 47,
                    "incorrect value for reserved[52], expected 47, is {}",
                    msg.reserved[52]
                );
                assert_eq!(
                    msg.reserved[53], 154,
                    "incorrect value for reserved[53], expected 154, is {}",
                    msg.reserved[53]
                );
                assert_eq!(
                    msg.reserved[54], 91,
                    "incorrect value for reserved[54], expected 91, is {}",
                    msg.reserved[54]
                );
                assert_eq!(
                    msg.reserved[55], 227,
                    "incorrect value for reserved[55], expected 227, is {}",
                    msg.reserved[55]
                );
                assert_eq!(
                    msg.reserved[56], 88,
                    "incorrect value for reserved[56], expected 88, is {}",
                    msg.reserved[56]
                );
                assert_eq!(
                    msg.reserved[57], 11,
                    "incorrect value for reserved[57], expected 11, is {}",
                    msg.reserved[57]
                );
                assert_eq!(
                    msg.reserved[58], 1,
                    "incorrect value for reserved[58], expected 1, is {}",
                    msg.reserved[58]
                );
                assert_eq!(
                    msg.reserved[59], 85,
                    "incorrect value for reserved[59], expected 85, is {}",
                    msg.reserved[59]
                );
                assert_eq!(
                    msg.reserved[60], 146,
                    "incorrect value for reserved[60], expected 146, is {}",
                    msg.reserved[60]
                );
                assert_eq!(
                    msg.reserved[61], 100,
                    "incorrect value for reserved[61], expected 100, is {}",
                    msg.reserved[61]
                );
                assert_eq!(
                    msg.reserved[62], 190,
                    "incorrect value for reserved[62], expected 190, is {}",
                    msg.reserved[62]
                );
                assert_eq!(
                    msg.reserved[63], 232,
                    "incorrect value for reserved[63], expected 232, is {}",
                    msg.reserved[63]
                );
                assert_eq!(
                    msg.reserved[64], 207,
                    "incorrect value for reserved[64], expected 207, is {}",
                    msg.reserved[64]
                );
                assert_eq!(
                    msg.reserved[65], 61,
                    "incorrect value for reserved[65], expected 61, is {}",
                    msg.reserved[65]
                );
                assert_eq!(
                    msg.reserved[66], 61,
                    "incorrect value for reserved[66], expected 61, is {}",
                    msg.reserved[66]
                );
                assert_eq!(
                    msg.reserved[67], 201,
                    "incorrect value for reserved[67], expected 201, is {}",
                    msg.reserved[67]
                );
                assert_eq!(
                    msg.reserved[68], 220,
                    "incorrect value for reserved[68], expected 220, is {}",
                    msg.reserved[68]
                );
                assert_eq!(
                    msg.reserved[69], 31,
                    "incorrect value for reserved[69], expected 31, is {}",
                    msg.reserved[69]
                );
                assert_eq!(
                    msg.reserved[70], 78,
                    "incorrect value for reserved[70], expected 78, is {}",
                    msg.reserved[70]
                );
                assert_eq!(
                    msg.reserved[71], 34,
                    "incorrect value for reserved[71], expected 34, is {}",
                    msg.reserved[71]
                );
                assert_eq!(
                    msg.reserved[72], 57,
                    "incorrect value for reserved[72], expected 57, is {}",
                    msg.reserved[72]
                );
                assert_eq!(
                    msg.reserved[73], 82,
                    "incorrect value for reserved[73], expected 82, is {}",
                    msg.reserved[73]
                );
                assert_eq!(
                    msg.reserved[74], 59,
                    "incorrect value for reserved[74], expected 59, is {}",
                    msg.reserved[74]
                );
                assert_eq!(
                    msg.reserved[75], 104,
                    "incorrect value for reserved[75], expected 104, is {}",
                    msg.reserved[75]
                );
                assert_eq!(
                    msg.reserved[76], 65,
                    "incorrect value for reserved[76], expected 65, is {}",
                    msg.reserved[76]
                );
                assert_eq!(
                    msg.reserved[77], 221,
                    "incorrect value for reserved[77], expected 221, is {}",
                    msg.reserved[77]
                );
                assert_eq!(
                    msg.reserved[78], 0,
                    "incorrect value for reserved[78], expected 0, is {}",
                    msg.reserved[78]
                );
                assert_eq!(
                    msg.reserved[79], 43,
                    "incorrect value for reserved[79], expected 43, is {}",
                    msg.reserved[79]
                );
                assert_eq!(
                    msg.reserved[80], 210,
                    "incorrect value for reserved[80], expected 210, is {}",
                    msg.reserved[80]
                );
                assert_eq!(
                    msg.reserved[81], 9,
                    "incorrect value for reserved[81], expected 9, is {}",
                    msg.reserved[81]
                );
                assert_eq!(
                    msg.reserved[82], 32,
                    "incorrect value for reserved[82], expected 32, is {}",
                    msg.reserved[82]
                );
                assert_eq!(
                    msg.reserved[83], 122,
                    "incorrect value for reserved[83], expected 122, is {}",
                    msg.reserved[83]
                );
                assert_eq!(
                    msg.reserved[84], 29,
                    "incorrect value for reserved[84], expected 29, is {}",
                    msg.reserved[84]
                );
                assert_eq!(
                    msg.reserved[85], 237,
                    "incorrect value for reserved[85], expected 237, is {}",
                    msg.reserved[85]
                );
                assert_eq!(
                    msg.reserved[86], 11,
                    "incorrect value for reserved[86], expected 11, is {}",
                    msg.reserved[86]
                );
                assert_eq!(
                    msg.reserved[87], 151,
                    "incorrect value for reserved[87], expected 151, is {}",
                    msg.reserved[87]
                );
                assert_eq!(
                    msg.reserved[88], 223,
                    "incorrect value for reserved[88], expected 223, is {}",
                    msg.reserved[88]
                );
                assert_eq!(
                    msg.reserved[89], 18,
                    "incorrect value for reserved[89], expected 18, is {}",
                    msg.reserved[89]
                );
                assert_eq!(
                    msg.reserved[90], 81,
                    "incorrect value for reserved[90], expected 81, is {}",
                    msg.reserved[90]
                );
                assert_eq!(
                    msg.reserved[91], 204,
                    "incorrect value for reserved[91], expected 204, is {}",
                    msg.reserved[91]
                );
                assert_eq!(
                    msg.reserved[92], 172,
                    "incorrect value for reserved[92], expected 172, is {}",
                    msg.reserved[92]
                );
                assert_eq!(
                    msg.reserved[93], 234,
                    "incorrect value for reserved[93], expected 234, is {}",
                    msg.reserved[93]
                );
                assert_eq!(
                    msg.reserved[94], 127,
                    "incorrect value for reserved[94], expected 127, is {}",
                    msg.reserved[94]
                );
                assert_eq!(
                    msg.reserved[95], 3,
                    "incorrect value for reserved[95], expected 3, is {}",
                    msg.reserved[95]
                );
                assert_eq!(
                    msg.reserved[96], 82,
                    "incorrect value for reserved[96], expected 82, is {}",
                    msg.reserved[96]
                );
                assert_eq!(
                    msg.reserved[97], 133,
                    "incorrect value for reserved[97], expected 133, is {}",
                    msg.reserved[97]
                );
                assert_eq!(
                    msg.reserved[98], 169,
                    "incorrect value for reserved[98], expected 169, is {}",
                    msg.reserved[98]
                );
                assert_eq!(
                    msg.reserved[99], 12,
                    "incorrect value for reserved[99], expected 12, is {}",
                    msg.reserved[99]
                );
                assert_eq!(
                    msg.reserved[100], 176,
                    "incorrect value for reserved[100], expected 176, is {}",
                    msg.reserved[100]
                );
                assert_eq!(
                    msg.reserved[101], 193,
                    "incorrect value for reserved[101], expected 193, is {}",
                    msg.reserved[101]
                );
                assert_eq!(
                    msg.reserved[102], 0,
                    "incorrect value for reserved[102], expected 0, is {}",
                    msg.reserved[102]
                );
                assert_eq!(
                    msg.reserved[103], 24,
                    "incorrect value for reserved[103], expected 24, is {}",
                    msg.reserved[103]
                );
                assert_eq!(
                    msg.reserved[104], 121,
                    "incorrect value for reserved[104], expected 121, is {}",
                    msg.reserved[104]
                );
                assert_eq!(
                    msg.reserved[105], 85,
                    "incorrect value for reserved[105], expected 85, is {}",
                    msg.reserved[105]
                );
                assert_eq!(
                    msg.reserved[106], 55,
                    "incorrect value for reserved[106], expected 55, is {}",
                    msg.reserved[106]
                );
                assert_eq!(
                    msg.reserved[107], 214,
                    "incorrect value for reserved[107], expected 214, is {}",
                    msg.reserved[107]
                );
                assert_eq!(
                    msg.reserved[108], 198,
                    "incorrect value for reserved[108], expected 198, is {}",
                    msg.reserved[108]
                );
                assert_eq!(
                    msg.reserved[109], 75,
                    "incorrect value for reserved[109], expected 75, is {}",
                    msg.reserved[109]
                );
                assert_eq!(
                    msg.reserved[110], 234,
                    "incorrect value for reserved[110], expected 234, is {}",
                    msg.reserved[110]
                );
                assert_eq!(
                    msg.reserved[111], 179,
                    "incorrect value for reserved[111], expected 179, is {}",
                    msg.reserved[111]
                );
                assert_eq!(
                    msg.reserved[112], 214,
                    "incorrect value for reserved[112], expected 214, is {}",
                    msg.reserved[112]
                );
                assert_eq!(
                    msg.reserved[113], 85,
                    "incorrect value for reserved[113], expected 85, is {}",
                    msg.reserved[113]
                );
                assert_eq!(
                    msg.reserved[114], 94,
                    "incorrect value for reserved[114], expected 94, is {}",
                    msg.reserved[114]
                );
                assert_eq!(
                    msg.reserved[115], 115,
                    "incorrect value for reserved[115], expected 115, is {}",
                    msg.reserved[115]
                );
                assert_eq!(
                    msg.reserved[116], 21,
                    "incorrect value for reserved[116], expected 21, is {}",
                    msg.reserved[116]
                );
                assert_eq!(
                    msg.reserved[117], 73,
                    "incorrect value for reserved[117], expected 73, is {}",
                    msg.reserved[117]
                );
                assert_eq!(
                    msg.reserved[118], 121,
                    "incorrect value for reserved[118], expected 121, is {}",
                    msg.reserved[118]
                );
                assert_eq!(
                    msg.reserved[119], 75,
                    "incorrect value for reserved[119], expected 75, is {}",
                    msg.reserved[119]
                );
                assert_eq!(
                    msg.reserved[120], 46,
                    "incorrect value for reserved[120], expected 46, is {}",
                    msg.reserved[120]
                );
                assert_eq!(
                    msg.reserved[121], 158,
                    "incorrect value for reserved[121], expected 158, is {}",
                    msg.reserved[121]
                );
                assert_eq!(
                    msg.reserved[122], 63,
                    "incorrect value for reserved[122], expected 63, is {}",
                    msg.reserved[122]
                );
                assert_eq!(
                    msg.reserved[123], 100,
                    "incorrect value for reserved[123], expected 100, is {}",
                    msg.reserved[123]
                );
                assert_eq!(
                    msg.reserved[124], 122,
                    "incorrect value for reserved[124], expected 122, is {}",
                    msg.reserved[124]
                );
                assert_eq!(
                    msg.reserved[125], 213,
                    "incorrect value for reserved[125], expected 213, is {}",
                    msg.reserved[125]
                );
                assert_eq!(
                    msg.reserved[126], 20,
                    "incorrect value for reserved[126], expected 20, is {}",
                    msg.reserved[126]
                );
                assert_eq!(
                    msg.reserved[127], 85,
                    "incorrect value for reserved[127], expected 85, is {}",
                    msg.reserved[127]
                );
                assert_eq!(
                    msg.reserved[128], 212,
                    "incorrect value for reserved[128], expected 212, is {}",
                    msg.reserved[128]
                );
                assert_eq!(
                    msg.reserved[129], 131,
                    "incorrect value for reserved[129], expected 131, is {}",
                    msg.reserved[129]
                );
                assert_eq!(
                    msg.reserved[130], 50,
                    "incorrect value for reserved[130], expected 50, is {}",
                    msg.reserved[130]
                );
                assert_eq!(
                    msg.reserved[131], 224,
                    "incorrect value for reserved[131], expected 224, is {}",
                    msg.reserved[131]
                );
                assert_eq!(
                    msg.reserved[132], 218,
                    "incorrect value for reserved[132], expected 218, is {}",
                    msg.reserved[132]
                );
                assert_eq!(
                    msg.reserved[133], 215,
                    "incorrect value for reserved[133], expected 215, is {}",
                    msg.reserved[133]
                );
                assert_eq!(
                    msg.reserved[134], 215,
                    "incorrect value for reserved[134], expected 215, is {}",
                    msg.reserved[134]
                );
                assert_eq!(
                    msg.reserved[135], 149,
                    "incorrect value for reserved[135], expected 149, is {}",
                    msg.reserved[135]
                );
                assert_eq!(
                    msg.reserved[136], 2,
                    "incorrect value for reserved[136], expected 2, is {}",
                    msg.reserved[136]
                );
                assert_eq!(
                    msg.reserved[137], 19,
                    "incorrect value for reserved[137], expected 19, is {}",
                    msg.reserved[137]
                );
                assert_eq!(
                    msg.reserved[138], 129,
                    "incorrect value for reserved[138], expected 129, is {}",
                    msg.reserved[138]
                );
                assert_eq!(
                    msg.reserved[139], 39,
                    "incorrect value for reserved[139], expected 39, is {}",
                    msg.reserved[139]
                );
                assert_eq!(
                    msg.reserved[140], 164,
                    "incorrect value for reserved[140], expected 164, is {}",
                    msg.reserved[140]
                );
                assert_eq!(
                    msg.reserved[141], 5,
                    "incorrect value for reserved[141], expected 5, is {}",
                    msg.reserved[141]
                );
                assert_eq!(
                    msg.reserved[142], 175,
                    "incorrect value for reserved[142], expected 175, is {}",
                    msg.reserved[142]
                );
                assert_eq!(
                    msg.reserved[143], 6,
                    "incorrect value for reserved[143], expected 6, is {}",
                    msg.reserved[143]
                );
                assert_eq!(
                    msg.reserved[144], 62,
                    "incorrect value for reserved[144], expected 62, is {}",
                    msg.reserved[144]
                );
                assert_eq!(
                    msg.reserved[145], 51,
                    "incorrect value for reserved[145], expected 51, is {}",
                    msg.reserved[145]
                );
                assert_eq!(
                    msg.reserved[146], 78,
                    "incorrect value for reserved[146], expected 78, is {}",
                    msg.reserved[146]
                );
                assert_eq!(
                    msg.reserved[147], 66,
                    "incorrect value for reserved[147], expected 66, is {}",
                    msg.reserved[147]
                );
                assert_eq!(
                    msg.reserved[148], 248,
                    "incorrect value for reserved[148], expected 248, is {}",
                    msg.reserved[148]
                );
                assert_eq!(
                    msg.reserved[149], 116,
                    "incorrect value for reserved[149], expected 116, is {}",
                    msg.reserved[149]
                );
                assert_eq!(
                    msg.reserved[150], 88,
                    "incorrect value for reserved[150], expected 88, is {}",
                    msg.reserved[150]
                );
                assert_eq!(
                    msg.reserved[151], 90,
                    "incorrect value for reserved[151], expected 90, is {}",
                    msg.reserved[151]
                );
                assert_eq!(
                    msg.reserved[152], 128,
                    "incorrect value for reserved[152], expected 128, is {}",
                    msg.reserved[152]
                );
                assert_eq!(
                    msg.reserved[153], 226,
                    "incorrect value for reserved[153], expected 226, is {}",
                    msg.reserved[153]
                );
                assert_eq!(
                    msg.reserved[154], 177,
                    "incorrect value for reserved[154], expected 177, is {}",
                    msg.reserved[154]
                );
                assert_eq!(
                    msg.reserved[155], 0,
                    "incorrect value for reserved[155], expected 0, is {}",
                    msg.reserved[155]
                );
                assert_eq!(
                    msg.reserved[156], 47,
                    "incorrect value for reserved[156], expected 47, is {}",
                    msg.reserved[156]
                );
                assert_eq!(
                    msg.reserved[157], 140,
                    "incorrect value for reserved[157], expected 140, is {}",
                    msg.reserved[157]
                );
                assert_eq!(
                    msg.reserved[158], 33,
                    "incorrect value for reserved[158], expected 33, is {}",
                    msg.reserved[158]
                );
                assert_eq!(
                    msg.reserved[159], 126,
                    "incorrect value for reserved[159], expected 126, is {}",
                    msg.reserved[159]
                );
                assert_eq!(
                    msg.reserved[160], 221,
                    "incorrect value for reserved[160], expected 221, is {}",
                    msg.reserved[160]
                );
                assert_eq!(
                    msg.reserved[161], 110,
                    "incorrect value for reserved[161], expected 110, is {}",
                    msg.reserved[161]
                );
                assert_eq!(
                    msg.reserved[162], 144,
                    "incorrect value for reserved[162], expected 144, is {}",
                    msg.reserved[162]
                );
                assert_eq!(
                    msg.reserved[163], 97,
                    "incorrect value for reserved[163], expected 97, is {}",
                    msg.reserved[163]
                );
                assert_eq!(
                    msg.reserved[164], 74,
                    "incorrect value for reserved[164], expected 74, is {}",
                    msg.reserved[164]
                );
                assert_eq!(
                    msg.reserved[165], 250,
                    "incorrect value for reserved[165], expected 250, is {}",
                    msg.reserved[165]
                );
                assert_eq!(
                    msg.reserved[166], 181,
                    "incorrect value for reserved[166], expected 181, is {}",
                    msg.reserved[166]
                );
                assert_eq!(
                    msg.reserved[167], 199,
                    "incorrect value for reserved[167], expected 199, is {}",
                    msg.reserved[167]
                );
                assert_eq!(
                    msg.reserved[168], 27,
                    "incorrect value for reserved[168], expected 27, is {}",
                    msg.reserved[168]
                );
                assert_eq!(
                    msg.reserved[169], 176,
                    "incorrect value for reserved[169], expected 176, is {}",
                    msg.reserved[169]
                );
                assert_eq!(
                    msg.reserved[170], 65,
                    "incorrect value for reserved[170], expected 65, is {}",
                    msg.reserved[170]
                );
                assert_eq!(
                    msg.reserved[171], 185,
                    "incorrect value for reserved[171], expected 185, is {}",
                    msg.reserved[171]
                );
                assert_eq!(
                    msg.reserved[172], 110,
                    "incorrect value for reserved[172], expected 110, is {}",
                    msg.reserved[172]
                );
                assert_eq!(
                    msg.reserved[173], 92,
                    "incorrect value for reserved[173], expected 92, is {}",
                    msg.reserved[173]
                );
                assert_eq!(
                    msg.reserved[174], 34,
                    "incorrect value for reserved[174], expected 34, is {}",
                    msg.reserved[174]
                );
                assert_eq!(
                    msg.reserved[175], 44,
                    "incorrect value for reserved[175], expected 44, is {}",
                    msg.reserved[175]
                );
                assert_eq!(
                    msg.reserved[176], 131,
                    "incorrect value for reserved[176], expected 131, is {}",
                    msg.reserved[176]
                );
                assert_eq!(
                    msg.reserved[177], 96,
                    "incorrect value for reserved[177], expected 96, is {}",
                    msg.reserved[177]
                );
                assert_eq!(
                    msg.reserved[178], 178,
                    "incorrect value for reserved[178], expected 178, is {}",
                    msg.reserved[178]
                );
                assert_eq!(
                    msg.reserved[179], 40,
                    "incorrect value for reserved[179], expected 40, is {}",
                    msg.reserved[179]
                );
                assert_eq!(
                    msg.reserved[180], 176,
                    "incorrect value for reserved[180], expected 176, is {}",
                    msg.reserved[180]
                );
                assert_eq!(
                    msg.reserved[181], 4,
                    "incorrect value for reserved[181], expected 4, is {}",
                    msg.reserved[181]
                );
                assert_eq!(
                    msg.reserved[182], 90,
                    "incorrect value for reserved[182], expected 90, is {}",
                    msg.reserved[182]
                );
                assert_eq!(
                    msg.reserved[183], 36,
                    "incorrect value for reserved[183], expected 36, is {}",
                    msg.reserved[183]
                );
                assert_eq!(
                    msg.reserved[184], 7,
                    "incorrect value for reserved[184], expected 7, is {}",
                    msg.reserved[184]
                );
                assert_eq!(
                    msg.reserved[185], 180,
                    "incorrect value for reserved[185], expected 180, is {}",
                    msg.reserved[185]
                );
                assert_eq!(
                    msg.reserved[186], 244,
                    "incorrect value for reserved[186], expected 244, is {}",
                    msg.reserved[186]
                );
                assert_eq!(
                    msg.reserved[187], 244,
                    "incorrect value for reserved[187], expected 244, is {}",
                    msg.reserved[187]
                );
                assert_eq!(
                    msg.reserved[188], 23,
                    "incorrect value for reserved[188], expected 23, is {}",
                    msg.reserved[188]
                );
                assert_eq!(
                    msg.reserved[189], 108,
                    "incorrect value for reserved[189], expected 108, is {}",
                    msg.reserved[189]
                );
                assert_eq!(
                    msg.reserved[190], 171,
                    "incorrect value for reserved[190], expected 171, is {}",
                    msg.reserved[190]
                );
                assert_eq!(
                    msg.reserved[191], 204,
                    "incorrect value for reserved[191], expected 204, is {}",
                    msg.reserved[191]
                );
                assert_eq!(
                    msg.reserved[192], 196,
                    "incorrect value for reserved[192], expected 196, is {}",
                    msg.reserved[192]
                );
                assert_eq!(
                    msg.reserved[193], 61,
                    "incorrect value for reserved[193], expected 61, is {}",
                    msg.reserved[193]
                );
                assert_eq!(
                    msg.reserved[194], 51,
                    "incorrect value for reserved[194], expected 51, is {}",
                    msg.reserved[194]
                );
                assert_eq!(
                    msg.reserved[195], 179,
                    "incorrect value for reserved[195], expected 179, is {}",
                    msg.reserved[195]
                );
                assert_eq!(
                    msg.reserved[196], 242,
                    "incorrect value for reserved[196], expected 242, is {}",
                    msg.reserved[196]
                );
                assert_eq!(
                    msg.reserved[197], 156,
                    "incorrect value for reserved[197], expected 156, is {}",
                    msg.reserved[197]
                );
                assert_eq!(
                    msg.reserved[198], 81,
                    "incorrect value for reserved[198], expected 81, is {}",
                    msg.reserved[198]
                );
                assert_eq!(
                    msg.reserved[199], 83,
                    "incorrect value for reserved[199], expected 83, is {}",
                    msg.reserved[199]
                );
                assert_eq!(
                    msg.reserved[200], 16,
                    "incorrect value for reserved[200], expected 16, is {}",
                    msg.reserved[200]
                );
                assert_eq!(
                    msg.reserved[201], 15,
                    "incorrect value for reserved[201], expected 15, is {}",
                    msg.reserved[201]
                );
                assert_eq!(
                    msg.reserved[202], 134,
                    "incorrect value for reserved[202], expected 134, is {}",
                    msg.reserved[202]
                );
                assert_eq!(
                    msg.reserved[203], 40,
                    "incorrect value for reserved[203], expected 40, is {}",
                    msg.reserved[203]
                );
                assert_eq!(
                    msg.reserved[204], 245,
                    "incorrect value for reserved[204], expected 245, is {}",
                    msg.reserved[204]
                );
                assert_eq!(
                    msg.reserved[205], 253,
                    "incorrect value for reserved[205], expected 253, is {}",
                    msg.reserved[205]
                );
                assert_eq!(
                    msg.reserved[206], 150,
                    "incorrect value for reserved[206], expected 150, is {}",
                    msg.reserved[206]
                );
                assert_eq!(
                    msg.reserved[207], 94,
                    "incorrect value for reserved[207], expected 94, is {}",
                    msg.reserved[207]
                );
                assert_eq!(
                    msg.reserved[208], 150,
                    "incorrect value for reserved[208], expected 150, is {}",
                    msg.reserved[208]
                );
                assert_eq!(
                    msg.reserved[209], 144,
                    "incorrect value for reserved[209], expected 144, is {}",
                    msg.reserved[209]
                );
                assert_eq!(
                    msg.reserved[210], 197,
                    "incorrect value for reserved[210], expected 197, is {}",
                    msg.reserved[210]
                );
                assert_eq!(
                    msg.reserved[211], 113,
                    "incorrect value for reserved[211], expected 113, is {}",
                    msg.reserved[211]
                );
                assert_eq!(
                    msg.reserved[212], 5,
                    "incorrect value for reserved[212], expected 5, is {}",
                    msg.reserved[212]
                );
                assert_eq!(
                    msg.reserved[213], 141,
                    "incorrect value for reserved[213], expected 141, is {}",
                    msg.reserved[213]
                );
                assert_eq!(
                    msg.reserved[214], 232,
                    "incorrect value for reserved[214], expected 232, is {}",
                    msg.reserved[214]
                );
                assert_eq!(
                    msg.reserved[215], 33,
                    "incorrect value for reserved[215], expected 33, is {}",
                    msg.reserved[215]
                );
                assert_eq!(
                    msg.reserved[216], 101,
                    "incorrect value for reserved[216], expected 101, is {}",
                    msg.reserved[216]
                );
                assert_eq!(
                    msg.reserved[217], 231,
                    "incorrect value for reserved[217], expected 231, is {}",
                    msg.reserved[217]
                );
                assert_eq!(
                    msg.reserved[218], 38,
                    "incorrect value for reserved[218], expected 38, is {}",
                    msg.reserved[218]
                );
                assert_eq!(
                    msg.reserved[219], 75,
                    "incorrect value for reserved[219], expected 75, is {}",
                    msg.reserved[219]
                );
                assert_eq!(
                    msg.reserved[220], 178,
                    "incorrect value for reserved[220], expected 178, is {}",
                    msg.reserved[220]
                );
                assert_eq!(
                    msg.reserved[221], 243,
                    "incorrect value for reserved[221], expected 243, is {}",
                    msg.reserved[221]
                );
                assert_eq!(
                    msg.reserved[222], 119,
                    "incorrect value for reserved[222], expected 119, is {}",
                    msg.reserved[222]
                );
                assert_eq!(
                    msg.reserved[223], 1,
                    "incorrect value for reserved[223], expected 1, is {}",
                    msg.reserved[223]
                );
                assert_eq!(
                    msg.reserved[224], 248,
                    "incorrect value for reserved[224], expected 248, is {}",
                    msg.reserved[224]
                );
                assert_eq!(
                    msg.reserved[225], 218,
                    "incorrect value for reserved[225], expected 218, is {}",
                    msg.reserved[225]
                );
                assert_eq!(
                    msg.reserved[226], 86,
                    "incorrect value for reserved[226], expected 86, is {}",
                    msg.reserved[226]
                );
                assert_eq!(
                    msg.reserved[227], 7,
                    "incorrect value for reserved[227], expected 7, is {}",
                    msg.reserved[227]
                );
                assert_eq!(
                    msg.reserved[228], 88,
                    "incorrect value for reserved[228], expected 88, is {}",
                    msg.reserved[228]
                );
                assert_eq!(
                    msg.reserved[229], 197,
                    "incorrect value for reserved[229], expected 197, is {}",
                    msg.reserved[229]
                );
                assert_eq!(
                    msg.reserved[230], 148,
                    "incorrect value for reserved[230], expected 148, is {}",
                    msg.reserved[230]
                );
                assert_eq!(
                    msg.reserved[231], 240,
                    "incorrect value for reserved[231], expected 240, is {}",
                    msg.reserved[231]
                );
                assert_eq!(
                    msg.reserved[232], 227,
                    "incorrect value for reserved[232], expected 227, is {}",
                    msg.reserved[232]
                );
                assert_eq!(
                    msg.reserved[233], 2,
                    "incorrect value for reserved[233], expected 2, is {}",
                    msg.reserved[233]
                );
                assert_eq!(
                    msg.reserved[234], 65,
                    "incorrect value for reserved[234], expected 65, is {}",
                    msg.reserved[234]
                );
                assert_eq!(
                    msg.reserved[235], 173,
                    "incorrect value for reserved[235], expected 173, is {}",
                    msg.reserved[235]
                );
                assert_eq!(
                    msg.reserved[236], 122,
                    "incorrect value for reserved[236], expected 122, is {}",
                    msg.reserved[236]
                );
                assert_eq!(
                    msg.reserved[237], 143,
                    "incorrect value for reserved[237], expected 143, is {}",
                    msg.reserved[237]
                );
                assert_eq!(
                    msg.reserved[238], 251,
                    "incorrect value for reserved[238], expected 251, is {}",
                    msg.reserved[238]
                );
                assert_eq!(
                    msg.reserved[239], 156,
                    "incorrect value for reserved[239], expected 156, is {}",
                    msg.reserved[239]
                );
                assert_eq!(
                    msg.reserved[240], 217,
                    "incorrect value for reserved[240], expected 217, is {}",
                    msg.reserved[240]
                );
                assert_eq!(
                    msg.reserved[241], 67,
                    "incorrect value for reserved[241], expected 67, is {}",
                    msg.reserved[241]
                );
                assert_eq!(
                    msg.reserved[242], 239,
                    "incorrect value for reserved[242], expected 239, is {}",
                    msg.reserved[242]
                );
                assert_eq!(
                    msg.reserved[243], 219,
                    "incorrect value for reserved[243], expected 219, is {}",
                    msg.reserved[243]
                );
                assert_eq!(
                    msg.reserved[244], 31,
                    "incorrect value for reserved[244], expected 31, is {}",
                    msg.reserved[244]
                );
                assert_eq!(
                    msg.reserved[245], 224,
                    "incorrect value for reserved[245], expected 224, is {}",
                    msg.reserved[245]
                );
                assert_eq!(
                    msg.reserved[246], 176,
                    "incorrect value for reserved[246], expected 176, is {}",
                    msg.reserved[246]
                );
                assert_eq!(
                    msg.reserved[247], 129,
                    "incorrect value for reserved[247], expected 129, is {}",
                    msg.reserved[247]
                );
                assert_eq!(
                    msg.reserved[248], 81,
                    "incorrect value for reserved[248], expected 81, is {}",
                    msg.reserved[248]
                );
                assert_eq!(
                    msg.reserved[249], 80,
                    "incorrect value for reserved[249], expected 80, is {}",
                    msg.reserved[249]
                );
                assert!(msg.signal_error_rate.almost_eq( 8.58820019531250000e+03 ), "incorrect value for signal_error_rate, expected 8.58820019531250000e+03, is {:e}", msg.signal_error_rate);
                assert_eq!(
                    msg.signal_strength, 103,
                    "incorrect value for signal_strength, expected 103, is {}",
                    msg.signal_strength
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCellModemStatus"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
