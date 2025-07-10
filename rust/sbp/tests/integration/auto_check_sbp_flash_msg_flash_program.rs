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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashProgram.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_flash_msg_flash_program() {
    {
        let mut payload = Cursor::new(vec![
            85, 230, 0, 195, 4, 255, 212, 87, 52, 244, 250, 176, 222, 235, 106, 144, 29, 141, 255,
            3, 16, 192, 237, 172, 254, 213, 4, 220, 98, 34, 222, 230, 214, 6, 217, 172, 122, 46,
            13, 38, 240, 236, 60, 121, 47, 252, 163, 141, 222, 29, 168, 214, 118, 55, 201, 233, 21,
            214, 57, 245, 246, 19, 3, 121, 49, 231, 37, 186, 58, 238, 98, 39, 70, 232, 133, 25, 10,
            134, 129, 69, 228, 134, 9, 88, 183, 133, 171, 255, 166, 100, 152, 231, 92, 9, 196, 106,
            246, 29, 145, 156, 151, 32, 67, 188, 63, 233, 142, 174, 139, 154, 127, 35, 60, 56, 187,
            121, 103, 135, 152, 182, 88, 160, 255, 227, 240, 54, 100, 91, 31, 141, 102, 130, 254,
            54, 227, 229, 62, 53, 225, 143, 88, 139, 126, 235, 235, 35, 54, 134, 163, 92, 57, 87,
            130, 178, 22, 158, 18, 237, 209, 187, 226, 1, 46, 64, 226, 235, 213, 186, 159, 221,
            186, 25, 115, 84, 131, 167, 201, 104, 1, 200, 13, 50, 71, 73, 193, 201, 250, 172, 193,
            13, 20, 238, 130, 243, 68, 4, 72, 46, 194, 113, 255, 238, 15, 230, 64, 178, 127, 217,
            92, 160, 201, 118, 163, 144, 58, 28, 174, 65, 73, 45, 123, 118, 83, 107, 239, 168, 32,
            212, 191, 81, 93, 186, 223, 32, 19, 58, 137, 72, 217, 151, 251, 83, 20, 113, 37, 151,
            34, 37, 71, 95, 105, 235, 144, 164, 83, 197, 254, 183, 223, 91, 19, 45, 227,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgFlashProgram(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xe6,
                    "Incorrect message type, expected 0xe6, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.addr_len, 250,
                    "incorrect value for addr_len, expected 250, is {}",
                    msg.addr_len
                );
                assert_eq!(
                    msg.addr_start[0], 87,
                    "incorrect value for addr_start[0], expected 87, is {}",
                    msg.addr_start[0]
                );
                assert_eq!(
                    msg.addr_start[1], 52,
                    "incorrect value for addr_start[1], expected 52, is {}",
                    msg.addr_start[1]
                );
                assert_eq!(
                    msg.addr_start[2], 244,
                    "incorrect value for addr_start[2], expected 244, is {}",
                    msg.addr_start[2]
                );
                assert_eq!(
                    msg.data[0], 176,
                    "incorrect value for data[0], expected 176, is {}",
                    msg.data[0]
                );
                assert_eq!(
                    msg.data[1], 222,
                    "incorrect value for data[1], expected 222, is {}",
                    msg.data[1]
                );
                assert_eq!(
                    msg.data[2], 235,
                    "incorrect value for data[2], expected 235, is {}",
                    msg.data[2]
                );
                assert_eq!(
                    msg.data[3], 106,
                    "incorrect value for data[3], expected 106, is {}",
                    msg.data[3]
                );
                assert_eq!(
                    msg.data[4], 144,
                    "incorrect value for data[4], expected 144, is {}",
                    msg.data[4]
                );
                assert_eq!(
                    msg.data[5], 29,
                    "incorrect value for data[5], expected 29, is {}",
                    msg.data[5]
                );
                assert_eq!(
                    msg.data[6], 141,
                    "incorrect value for data[6], expected 141, is {}",
                    msg.data[6]
                );
                assert_eq!(
                    msg.data[7], 255,
                    "incorrect value for data[7], expected 255, is {}",
                    msg.data[7]
                );
                assert_eq!(
                    msg.data[8], 3,
                    "incorrect value for data[8], expected 3, is {}",
                    msg.data[8]
                );
                assert_eq!(
                    msg.data[9], 16,
                    "incorrect value for data[9], expected 16, is {}",
                    msg.data[9]
                );
                assert_eq!(
                    msg.data[10], 192,
                    "incorrect value for data[10], expected 192, is {}",
                    msg.data[10]
                );
                assert_eq!(
                    msg.data[11], 237,
                    "incorrect value for data[11], expected 237, is {}",
                    msg.data[11]
                );
                assert_eq!(
                    msg.data[12], 172,
                    "incorrect value for data[12], expected 172, is {}",
                    msg.data[12]
                );
                assert_eq!(
                    msg.data[13], 254,
                    "incorrect value for data[13], expected 254, is {}",
                    msg.data[13]
                );
                assert_eq!(
                    msg.data[14], 213,
                    "incorrect value for data[14], expected 213, is {}",
                    msg.data[14]
                );
                assert_eq!(
                    msg.data[15], 4,
                    "incorrect value for data[15], expected 4, is {}",
                    msg.data[15]
                );
                assert_eq!(
                    msg.data[16], 220,
                    "incorrect value for data[16], expected 220, is {}",
                    msg.data[16]
                );
                assert_eq!(
                    msg.data[17], 98,
                    "incorrect value for data[17], expected 98, is {}",
                    msg.data[17]
                );
                assert_eq!(
                    msg.data[18], 34,
                    "incorrect value for data[18], expected 34, is {}",
                    msg.data[18]
                );
                assert_eq!(
                    msg.data[19], 222,
                    "incorrect value for data[19], expected 222, is {}",
                    msg.data[19]
                );
                assert_eq!(
                    msg.data[20], 230,
                    "incorrect value for data[20], expected 230, is {}",
                    msg.data[20]
                );
                assert_eq!(
                    msg.data[21], 214,
                    "incorrect value for data[21], expected 214, is {}",
                    msg.data[21]
                );
                assert_eq!(
                    msg.data[22], 6,
                    "incorrect value for data[22], expected 6, is {}",
                    msg.data[22]
                );
                assert_eq!(
                    msg.data[23], 217,
                    "incorrect value for data[23], expected 217, is {}",
                    msg.data[23]
                );
                assert_eq!(
                    msg.data[24], 172,
                    "incorrect value for data[24], expected 172, is {}",
                    msg.data[24]
                );
                assert_eq!(
                    msg.data[25], 122,
                    "incorrect value for data[25], expected 122, is {}",
                    msg.data[25]
                );
                assert_eq!(
                    msg.data[26], 46,
                    "incorrect value for data[26], expected 46, is {}",
                    msg.data[26]
                );
                assert_eq!(
                    msg.data[27], 13,
                    "incorrect value for data[27], expected 13, is {}",
                    msg.data[27]
                );
                assert_eq!(
                    msg.data[28], 38,
                    "incorrect value for data[28], expected 38, is {}",
                    msg.data[28]
                );
                assert_eq!(
                    msg.data[29], 240,
                    "incorrect value for data[29], expected 240, is {}",
                    msg.data[29]
                );
                assert_eq!(
                    msg.data[30], 236,
                    "incorrect value for data[30], expected 236, is {}",
                    msg.data[30]
                );
                assert_eq!(
                    msg.data[31], 60,
                    "incorrect value for data[31], expected 60, is {}",
                    msg.data[31]
                );
                assert_eq!(
                    msg.data[32], 121,
                    "incorrect value for data[32], expected 121, is {}",
                    msg.data[32]
                );
                assert_eq!(
                    msg.data[33], 47,
                    "incorrect value for data[33], expected 47, is {}",
                    msg.data[33]
                );
                assert_eq!(
                    msg.data[34], 252,
                    "incorrect value for data[34], expected 252, is {}",
                    msg.data[34]
                );
                assert_eq!(
                    msg.data[35], 163,
                    "incorrect value for data[35], expected 163, is {}",
                    msg.data[35]
                );
                assert_eq!(
                    msg.data[36], 141,
                    "incorrect value for data[36], expected 141, is {}",
                    msg.data[36]
                );
                assert_eq!(
                    msg.data[37], 222,
                    "incorrect value for data[37], expected 222, is {}",
                    msg.data[37]
                );
                assert_eq!(
                    msg.data[38], 29,
                    "incorrect value for data[38], expected 29, is {}",
                    msg.data[38]
                );
                assert_eq!(
                    msg.data[39], 168,
                    "incorrect value for data[39], expected 168, is {}",
                    msg.data[39]
                );
                assert_eq!(
                    msg.data[40], 214,
                    "incorrect value for data[40], expected 214, is {}",
                    msg.data[40]
                );
                assert_eq!(
                    msg.data[41], 118,
                    "incorrect value for data[41], expected 118, is {}",
                    msg.data[41]
                );
                assert_eq!(
                    msg.data[42], 55,
                    "incorrect value for data[42], expected 55, is {}",
                    msg.data[42]
                );
                assert_eq!(
                    msg.data[43], 201,
                    "incorrect value for data[43], expected 201, is {}",
                    msg.data[43]
                );
                assert_eq!(
                    msg.data[44], 233,
                    "incorrect value for data[44], expected 233, is {}",
                    msg.data[44]
                );
                assert_eq!(
                    msg.data[45], 21,
                    "incorrect value for data[45], expected 21, is {}",
                    msg.data[45]
                );
                assert_eq!(
                    msg.data[46], 214,
                    "incorrect value for data[46], expected 214, is {}",
                    msg.data[46]
                );
                assert_eq!(
                    msg.data[47], 57,
                    "incorrect value for data[47], expected 57, is {}",
                    msg.data[47]
                );
                assert_eq!(
                    msg.data[48], 245,
                    "incorrect value for data[48], expected 245, is {}",
                    msg.data[48]
                );
                assert_eq!(
                    msg.data[49], 246,
                    "incorrect value for data[49], expected 246, is {}",
                    msg.data[49]
                );
                assert_eq!(
                    msg.data[50], 19,
                    "incorrect value for data[50], expected 19, is {}",
                    msg.data[50]
                );
                assert_eq!(
                    msg.data[51], 3,
                    "incorrect value for data[51], expected 3, is {}",
                    msg.data[51]
                );
                assert_eq!(
                    msg.data[52], 121,
                    "incorrect value for data[52], expected 121, is {}",
                    msg.data[52]
                );
                assert_eq!(
                    msg.data[53], 49,
                    "incorrect value for data[53], expected 49, is {}",
                    msg.data[53]
                );
                assert_eq!(
                    msg.data[54], 231,
                    "incorrect value for data[54], expected 231, is {}",
                    msg.data[54]
                );
                assert_eq!(
                    msg.data[55], 37,
                    "incorrect value for data[55], expected 37, is {}",
                    msg.data[55]
                );
                assert_eq!(
                    msg.data[56], 186,
                    "incorrect value for data[56], expected 186, is {}",
                    msg.data[56]
                );
                assert_eq!(
                    msg.data[57], 58,
                    "incorrect value for data[57], expected 58, is {}",
                    msg.data[57]
                );
                assert_eq!(
                    msg.data[58], 238,
                    "incorrect value for data[58], expected 238, is {}",
                    msg.data[58]
                );
                assert_eq!(
                    msg.data[59], 98,
                    "incorrect value for data[59], expected 98, is {}",
                    msg.data[59]
                );
                assert_eq!(
                    msg.data[60], 39,
                    "incorrect value for data[60], expected 39, is {}",
                    msg.data[60]
                );
                assert_eq!(
                    msg.data[61], 70,
                    "incorrect value for data[61], expected 70, is {}",
                    msg.data[61]
                );
                assert_eq!(
                    msg.data[62], 232,
                    "incorrect value for data[62], expected 232, is {}",
                    msg.data[62]
                );
                assert_eq!(
                    msg.data[63], 133,
                    "incorrect value for data[63], expected 133, is {}",
                    msg.data[63]
                );
                assert_eq!(
                    msg.data[64], 25,
                    "incorrect value for data[64], expected 25, is {}",
                    msg.data[64]
                );
                assert_eq!(
                    msg.data[65], 10,
                    "incorrect value for data[65], expected 10, is {}",
                    msg.data[65]
                );
                assert_eq!(
                    msg.data[66], 134,
                    "incorrect value for data[66], expected 134, is {}",
                    msg.data[66]
                );
                assert_eq!(
                    msg.data[67], 129,
                    "incorrect value for data[67], expected 129, is {}",
                    msg.data[67]
                );
                assert_eq!(
                    msg.data[68], 69,
                    "incorrect value for data[68], expected 69, is {}",
                    msg.data[68]
                );
                assert_eq!(
                    msg.data[69], 228,
                    "incorrect value for data[69], expected 228, is {}",
                    msg.data[69]
                );
                assert_eq!(
                    msg.data[70], 134,
                    "incorrect value for data[70], expected 134, is {}",
                    msg.data[70]
                );
                assert_eq!(
                    msg.data[71], 9,
                    "incorrect value for data[71], expected 9, is {}",
                    msg.data[71]
                );
                assert_eq!(
                    msg.data[72], 88,
                    "incorrect value for data[72], expected 88, is {}",
                    msg.data[72]
                );
                assert_eq!(
                    msg.data[73], 183,
                    "incorrect value for data[73], expected 183, is {}",
                    msg.data[73]
                );
                assert_eq!(
                    msg.data[74], 133,
                    "incorrect value for data[74], expected 133, is {}",
                    msg.data[74]
                );
                assert_eq!(
                    msg.data[75], 171,
                    "incorrect value for data[75], expected 171, is {}",
                    msg.data[75]
                );
                assert_eq!(
                    msg.data[76], 255,
                    "incorrect value for data[76], expected 255, is {}",
                    msg.data[76]
                );
                assert_eq!(
                    msg.data[77], 166,
                    "incorrect value for data[77], expected 166, is {}",
                    msg.data[77]
                );
                assert_eq!(
                    msg.data[78], 100,
                    "incorrect value for data[78], expected 100, is {}",
                    msg.data[78]
                );
                assert_eq!(
                    msg.data[79], 152,
                    "incorrect value for data[79], expected 152, is {}",
                    msg.data[79]
                );
                assert_eq!(
                    msg.data[80], 231,
                    "incorrect value for data[80], expected 231, is {}",
                    msg.data[80]
                );
                assert_eq!(
                    msg.data[81], 92,
                    "incorrect value for data[81], expected 92, is {}",
                    msg.data[81]
                );
                assert_eq!(
                    msg.data[82], 9,
                    "incorrect value for data[82], expected 9, is {}",
                    msg.data[82]
                );
                assert_eq!(
                    msg.data[83], 196,
                    "incorrect value for data[83], expected 196, is {}",
                    msg.data[83]
                );
                assert_eq!(
                    msg.data[84], 106,
                    "incorrect value for data[84], expected 106, is {}",
                    msg.data[84]
                );
                assert_eq!(
                    msg.data[85], 246,
                    "incorrect value for data[85], expected 246, is {}",
                    msg.data[85]
                );
                assert_eq!(
                    msg.data[86], 29,
                    "incorrect value for data[86], expected 29, is {}",
                    msg.data[86]
                );
                assert_eq!(
                    msg.data[87], 145,
                    "incorrect value for data[87], expected 145, is {}",
                    msg.data[87]
                );
                assert_eq!(
                    msg.data[88], 156,
                    "incorrect value for data[88], expected 156, is {}",
                    msg.data[88]
                );
                assert_eq!(
                    msg.data[89], 151,
                    "incorrect value for data[89], expected 151, is {}",
                    msg.data[89]
                );
                assert_eq!(
                    msg.data[90], 32,
                    "incorrect value for data[90], expected 32, is {}",
                    msg.data[90]
                );
                assert_eq!(
                    msg.data[91], 67,
                    "incorrect value for data[91], expected 67, is {}",
                    msg.data[91]
                );
                assert_eq!(
                    msg.data[92], 188,
                    "incorrect value for data[92], expected 188, is {}",
                    msg.data[92]
                );
                assert_eq!(
                    msg.data[93], 63,
                    "incorrect value for data[93], expected 63, is {}",
                    msg.data[93]
                );
                assert_eq!(
                    msg.data[94], 233,
                    "incorrect value for data[94], expected 233, is {}",
                    msg.data[94]
                );
                assert_eq!(
                    msg.data[95], 142,
                    "incorrect value for data[95], expected 142, is {}",
                    msg.data[95]
                );
                assert_eq!(
                    msg.data[96], 174,
                    "incorrect value for data[96], expected 174, is {}",
                    msg.data[96]
                );
                assert_eq!(
                    msg.data[97], 139,
                    "incorrect value for data[97], expected 139, is {}",
                    msg.data[97]
                );
                assert_eq!(
                    msg.data[98], 154,
                    "incorrect value for data[98], expected 154, is {}",
                    msg.data[98]
                );
                assert_eq!(
                    msg.data[99], 127,
                    "incorrect value for data[99], expected 127, is {}",
                    msg.data[99]
                );
                assert_eq!(
                    msg.data[100], 35,
                    "incorrect value for data[100], expected 35, is {}",
                    msg.data[100]
                );
                assert_eq!(
                    msg.data[101], 60,
                    "incorrect value for data[101], expected 60, is {}",
                    msg.data[101]
                );
                assert_eq!(
                    msg.data[102], 56,
                    "incorrect value for data[102], expected 56, is {}",
                    msg.data[102]
                );
                assert_eq!(
                    msg.data[103], 187,
                    "incorrect value for data[103], expected 187, is {}",
                    msg.data[103]
                );
                assert_eq!(
                    msg.data[104], 121,
                    "incorrect value for data[104], expected 121, is {}",
                    msg.data[104]
                );
                assert_eq!(
                    msg.data[105], 103,
                    "incorrect value for data[105], expected 103, is {}",
                    msg.data[105]
                );
                assert_eq!(
                    msg.data[106], 135,
                    "incorrect value for data[106], expected 135, is {}",
                    msg.data[106]
                );
                assert_eq!(
                    msg.data[107], 152,
                    "incorrect value for data[107], expected 152, is {}",
                    msg.data[107]
                );
                assert_eq!(
                    msg.data[108], 182,
                    "incorrect value for data[108], expected 182, is {}",
                    msg.data[108]
                );
                assert_eq!(
                    msg.data[109], 88,
                    "incorrect value for data[109], expected 88, is {}",
                    msg.data[109]
                );
                assert_eq!(
                    msg.data[110], 160,
                    "incorrect value for data[110], expected 160, is {}",
                    msg.data[110]
                );
                assert_eq!(
                    msg.data[111], 255,
                    "incorrect value for data[111], expected 255, is {}",
                    msg.data[111]
                );
                assert_eq!(
                    msg.data[112], 227,
                    "incorrect value for data[112], expected 227, is {}",
                    msg.data[112]
                );
                assert_eq!(
                    msg.data[113], 240,
                    "incorrect value for data[113], expected 240, is {}",
                    msg.data[113]
                );
                assert_eq!(
                    msg.data[114], 54,
                    "incorrect value for data[114], expected 54, is {}",
                    msg.data[114]
                );
                assert_eq!(
                    msg.data[115], 100,
                    "incorrect value for data[115], expected 100, is {}",
                    msg.data[115]
                );
                assert_eq!(
                    msg.data[116], 91,
                    "incorrect value for data[116], expected 91, is {}",
                    msg.data[116]
                );
                assert_eq!(
                    msg.data[117], 31,
                    "incorrect value for data[117], expected 31, is {}",
                    msg.data[117]
                );
                assert_eq!(
                    msg.data[118], 141,
                    "incorrect value for data[118], expected 141, is {}",
                    msg.data[118]
                );
                assert_eq!(
                    msg.data[119], 102,
                    "incorrect value for data[119], expected 102, is {}",
                    msg.data[119]
                );
                assert_eq!(
                    msg.data[120], 130,
                    "incorrect value for data[120], expected 130, is {}",
                    msg.data[120]
                );
                assert_eq!(
                    msg.data[121], 254,
                    "incorrect value for data[121], expected 254, is {}",
                    msg.data[121]
                );
                assert_eq!(
                    msg.data[122], 54,
                    "incorrect value for data[122], expected 54, is {}",
                    msg.data[122]
                );
                assert_eq!(
                    msg.data[123], 227,
                    "incorrect value for data[123], expected 227, is {}",
                    msg.data[123]
                );
                assert_eq!(
                    msg.data[124], 229,
                    "incorrect value for data[124], expected 229, is {}",
                    msg.data[124]
                );
                assert_eq!(
                    msg.data[125], 62,
                    "incorrect value for data[125], expected 62, is {}",
                    msg.data[125]
                );
                assert_eq!(
                    msg.data[126], 53,
                    "incorrect value for data[126], expected 53, is {}",
                    msg.data[126]
                );
                assert_eq!(
                    msg.data[127], 225,
                    "incorrect value for data[127], expected 225, is {}",
                    msg.data[127]
                );
                assert_eq!(
                    msg.data[128], 143,
                    "incorrect value for data[128], expected 143, is {}",
                    msg.data[128]
                );
                assert_eq!(
                    msg.data[129], 88,
                    "incorrect value for data[129], expected 88, is {}",
                    msg.data[129]
                );
                assert_eq!(
                    msg.data[130], 139,
                    "incorrect value for data[130], expected 139, is {}",
                    msg.data[130]
                );
                assert_eq!(
                    msg.data[131], 126,
                    "incorrect value for data[131], expected 126, is {}",
                    msg.data[131]
                );
                assert_eq!(
                    msg.data[132], 235,
                    "incorrect value for data[132], expected 235, is {}",
                    msg.data[132]
                );
                assert_eq!(
                    msg.data[133], 235,
                    "incorrect value for data[133], expected 235, is {}",
                    msg.data[133]
                );
                assert_eq!(
                    msg.data[134], 35,
                    "incorrect value for data[134], expected 35, is {}",
                    msg.data[134]
                );
                assert_eq!(
                    msg.data[135], 54,
                    "incorrect value for data[135], expected 54, is {}",
                    msg.data[135]
                );
                assert_eq!(
                    msg.data[136], 134,
                    "incorrect value for data[136], expected 134, is {}",
                    msg.data[136]
                );
                assert_eq!(
                    msg.data[137], 163,
                    "incorrect value for data[137], expected 163, is {}",
                    msg.data[137]
                );
                assert_eq!(
                    msg.data[138], 92,
                    "incorrect value for data[138], expected 92, is {}",
                    msg.data[138]
                );
                assert_eq!(
                    msg.data[139], 57,
                    "incorrect value for data[139], expected 57, is {}",
                    msg.data[139]
                );
                assert_eq!(
                    msg.data[140], 87,
                    "incorrect value for data[140], expected 87, is {}",
                    msg.data[140]
                );
                assert_eq!(
                    msg.data[141], 130,
                    "incorrect value for data[141], expected 130, is {}",
                    msg.data[141]
                );
                assert_eq!(
                    msg.data[142], 178,
                    "incorrect value for data[142], expected 178, is {}",
                    msg.data[142]
                );
                assert_eq!(
                    msg.data[143], 22,
                    "incorrect value for data[143], expected 22, is {}",
                    msg.data[143]
                );
                assert_eq!(
                    msg.data[144], 158,
                    "incorrect value for data[144], expected 158, is {}",
                    msg.data[144]
                );
                assert_eq!(
                    msg.data[145], 18,
                    "incorrect value for data[145], expected 18, is {}",
                    msg.data[145]
                );
                assert_eq!(
                    msg.data[146], 237,
                    "incorrect value for data[146], expected 237, is {}",
                    msg.data[146]
                );
                assert_eq!(
                    msg.data[147], 209,
                    "incorrect value for data[147], expected 209, is {}",
                    msg.data[147]
                );
                assert_eq!(
                    msg.data[148], 187,
                    "incorrect value for data[148], expected 187, is {}",
                    msg.data[148]
                );
                assert_eq!(
                    msg.data[149], 226,
                    "incorrect value for data[149], expected 226, is {}",
                    msg.data[149]
                );
                assert_eq!(
                    msg.data[150], 1,
                    "incorrect value for data[150], expected 1, is {}",
                    msg.data[150]
                );
                assert_eq!(
                    msg.data[151], 46,
                    "incorrect value for data[151], expected 46, is {}",
                    msg.data[151]
                );
                assert_eq!(
                    msg.data[152], 64,
                    "incorrect value for data[152], expected 64, is {}",
                    msg.data[152]
                );
                assert_eq!(
                    msg.data[153], 226,
                    "incorrect value for data[153], expected 226, is {}",
                    msg.data[153]
                );
                assert_eq!(
                    msg.data[154], 235,
                    "incorrect value for data[154], expected 235, is {}",
                    msg.data[154]
                );
                assert_eq!(
                    msg.data[155], 213,
                    "incorrect value for data[155], expected 213, is {}",
                    msg.data[155]
                );
                assert_eq!(
                    msg.data[156], 186,
                    "incorrect value for data[156], expected 186, is {}",
                    msg.data[156]
                );
                assert_eq!(
                    msg.data[157], 159,
                    "incorrect value for data[157], expected 159, is {}",
                    msg.data[157]
                );
                assert_eq!(
                    msg.data[158], 221,
                    "incorrect value for data[158], expected 221, is {}",
                    msg.data[158]
                );
                assert_eq!(
                    msg.data[159], 186,
                    "incorrect value for data[159], expected 186, is {}",
                    msg.data[159]
                );
                assert_eq!(
                    msg.data[160], 25,
                    "incorrect value for data[160], expected 25, is {}",
                    msg.data[160]
                );
                assert_eq!(
                    msg.data[161], 115,
                    "incorrect value for data[161], expected 115, is {}",
                    msg.data[161]
                );
                assert_eq!(
                    msg.data[162], 84,
                    "incorrect value for data[162], expected 84, is {}",
                    msg.data[162]
                );
                assert_eq!(
                    msg.data[163], 131,
                    "incorrect value for data[163], expected 131, is {}",
                    msg.data[163]
                );
                assert_eq!(
                    msg.data[164], 167,
                    "incorrect value for data[164], expected 167, is {}",
                    msg.data[164]
                );
                assert_eq!(
                    msg.data[165], 201,
                    "incorrect value for data[165], expected 201, is {}",
                    msg.data[165]
                );
                assert_eq!(
                    msg.data[166], 104,
                    "incorrect value for data[166], expected 104, is {}",
                    msg.data[166]
                );
                assert_eq!(
                    msg.data[167], 1,
                    "incorrect value for data[167], expected 1, is {}",
                    msg.data[167]
                );
                assert_eq!(
                    msg.data[168], 200,
                    "incorrect value for data[168], expected 200, is {}",
                    msg.data[168]
                );
                assert_eq!(
                    msg.data[169], 13,
                    "incorrect value for data[169], expected 13, is {}",
                    msg.data[169]
                );
                assert_eq!(
                    msg.data[170], 50,
                    "incorrect value for data[170], expected 50, is {}",
                    msg.data[170]
                );
                assert_eq!(
                    msg.data[171], 71,
                    "incorrect value for data[171], expected 71, is {}",
                    msg.data[171]
                );
                assert_eq!(
                    msg.data[172], 73,
                    "incorrect value for data[172], expected 73, is {}",
                    msg.data[172]
                );
                assert_eq!(
                    msg.data[173], 193,
                    "incorrect value for data[173], expected 193, is {}",
                    msg.data[173]
                );
                assert_eq!(
                    msg.data[174], 201,
                    "incorrect value for data[174], expected 201, is {}",
                    msg.data[174]
                );
                assert_eq!(
                    msg.data[175], 250,
                    "incorrect value for data[175], expected 250, is {}",
                    msg.data[175]
                );
                assert_eq!(
                    msg.data[176], 172,
                    "incorrect value for data[176], expected 172, is {}",
                    msg.data[176]
                );
                assert_eq!(
                    msg.data[177], 193,
                    "incorrect value for data[177], expected 193, is {}",
                    msg.data[177]
                );
                assert_eq!(
                    msg.data[178], 13,
                    "incorrect value for data[178], expected 13, is {}",
                    msg.data[178]
                );
                assert_eq!(
                    msg.data[179], 20,
                    "incorrect value for data[179], expected 20, is {}",
                    msg.data[179]
                );
                assert_eq!(
                    msg.data[180], 238,
                    "incorrect value for data[180], expected 238, is {}",
                    msg.data[180]
                );
                assert_eq!(
                    msg.data[181], 130,
                    "incorrect value for data[181], expected 130, is {}",
                    msg.data[181]
                );
                assert_eq!(
                    msg.data[182], 243,
                    "incorrect value for data[182], expected 243, is {}",
                    msg.data[182]
                );
                assert_eq!(
                    msg.data[183], 68,
                    "incorrect value for data[183], expected 68, is {}",
                    msg.data[183]
                );
                assert_eq!(
                    msg.data[184], 4,
                    "incorrect value for data[184], expected 4, is {}",
                    msg.data[184]
                );
                assert_eq!(
                    msg.data[185], 72,
                    "incorrect value for data[185], expected 72, is {}",
                    msg.data[185]
                );
                assert_eq!(
                    msg.data[186], 46,
                    "incorrect value for data[186], expected 46, is {}",
                    msg.data[186]
                );
                assert_eq!(
                    msg.data[187], 194,
                    "incorrect value for data[187], expected 194, is {}",
                    msg.data[187]
                );
                assert_eq!(
                    msg.data[188], 113,
                    "incorrect value for data[188], expected 113, is {}",
                    msg.data[188]
                );
                assert_eq!(
                    msg.data[189], 255,
                    "incorrect value for data[189], expected 255, is {}",
                    msg.data[189]
                );
                assert_eq!(
                    msg.data[190], 238,
                    "incorrect value for data[190], expected 238, is {}",
                    msg.data[190]
                );
                assert_eq!(
                    msg.data[191], 15,
                    "incorrect value for data[191], expected 15, is {}",
                    msg.data[191]
                );
                assert_eq!(
                    msg.data[192], 230,
                    "incorrect value for data[192], expected 230, is {}",
                    msg.data[192]
                );
                assert_eq!(
                    msg.data[193], 64,
                    "incorrect value for data[193], expected 64, is {}",
                    msg.data[193]
                );
                assert_eq!(
                    msg.data[194], 178,
                    "incorrect value for data[194], expected 178, is {}",
                    msg.data[194]
                );
                assert_eq!(
                    msg.data[195], 127,
                    "incorrect value for data[195], expected 127, is {}",
                    msg.data[195]
                );
                assert_eq!(
                    msg.data[196], 217,
                    "incorrect value for data[196], expected 217, is {}",
                    msg.data[196]
                );
                assert_eq!(
                    msg.data[197], 92,
                    "incorrect value for data[197], expected 92, is {}",
                    msg.data[197]
                );
                assert_eq!(
                    msg.data[198], 160,
                    "incorrect value for data[198], expected 160, is {}",
                    msg.data[198]
                );
                assert_eq!(
                    msg.data[199], 201,
                    "incorrect value for data[199], expected 201, is {}",
                    msg.data[199]
                );
                assert_eq!(
                    msg.data[200], 118,
                    "incorrect value for data[200], expected 118, is {}",
                    msg.data[200]
                );
                assert_eq!(
                    msg.data[201], 163,
                    "incorrect value for data[201], expected 163, is {}",
                    msg.data[201]
                );
                assert_eq!(
                    msg.data[202], 144,
                    "incorrect value for data[202], expected 144, is {}",
                    msg.data[202]
                );
                assert_eq!(
                    msg.data[203], 58,
                    "incorrect value for data[203], expected 58, is {}",
                    msg.data[203]
                );
                assert_eq!(
                    msg.data[204], 28,
                    "incorrect value for data[204], expected 28, is {}",
                    msg.data[204]
                );
                assert_eq!(
                    msg.data[205], 174,
                    "incorrect value for data[205], expected 174, is {}",
                    msg.data[205]
                );
                assert_eq!(
                    msg.data[206], 65,
                    "incorrect value for data[206], expected 65, is {}",
                    msg.data[206]
                );
                assert_eq!(
                    msg.data[207], 73,
                    "incorrect value for data[207], expected 73, is {}",
                    msg.data[207]
                );
                assert_eq!(
                    msg.data[208], 45,
                    "incorrect value for data[208], expected 45, is {}",
                    msg.data[208]
                );
                assert_eq!(
                    msg.data[209], 123,
                    "incorrect value for data[209], expected 123, is {}",
                    msg.data[209]
                );
                assert_eq!(
                    msg.data[210], 118,
                    "incorrect value for data[210], expected 118, is {}",
                    msg.data[210]
                );
                assert_eq!(
                    msg.data[211], 83,
                    "incorrect value for data[211], expected 83, is {}",
                    msg.data[211]
                );
                assert_eq!(
                    msg.data[212], 107,
                    "incorrect value for data[212], expected 107, is {}",
                    msg.data[212]
                );
                assert_eq!(
                    msg.data[213], 239,
                    "incorrect value for data[213], expected 239, is {}",
                    msg.data[213]
                );
                assert_eq!(
                    msg.data[214], 168,
                    "incorrect value for data[214], expected 168, is {}",
                    msg.data[214]
                );
                assert_eq!(
                    msg.data[215], 32,
                    "incorrect value for data[215], expected 32, is {}",
                    msg.data[215]
                );
                assert_eq!(
                    msg.data[216], 212,
                    "incorrect value for data[216], expected 212, is {}",
                    msg.data[216]
                );
                assert_eq!(
                    msg.data[217], 191,
                    "incorrect value for data[217], expected 191, is {}",
                    msg.data[217]
                );
                assert_eq!(
                    msg.data[218], 81,
                    "incorrect value for data[218], expected 81, is {}",
                    msg.data[218]
                );
                assert_eq!(
                    msg.data[219], 93,
                    "incorrect value for data[219], expected 93, is {}",
                    msg.data[219]
                );
                assert_eq!(
                    msg.data[220], 186,
                    "incorrect value for data[220], expected 186, is {}",
                    msg.data[220]
                );
                assert_eq!(
                    msg.data[221], 223,
                    "incorrect value for data[221], expected 223, is {}",
                    msg.data[221]
                );
                assert_eq!(
                    msg.data[222], 32,
                    "incorrect value for data[222], expected 32, is {}",
                    msg.data[222]
                );
                assert_eq!(
                    msg.data[223], 19,
                    "incorrect value for data[223], expected 19, is {}",
                    msg.data[223]
                );
                assert_eq!(
                    msg.data[224], 58,
                    "incorrect value for data[224], expected 58, is {}",
                    msg.data[224]
                );
                assert_eq!(
                    msg.data[225], 137,
                    "incorrect value for data[225], expected 137, is {}",
                    msg.data[225]
                );
                assert_eq!(
                    msg.data[226], 72,
                    "incorrect value for data[226], expected 72, is {}",
                    msg.data[226]
                );
                assert_eq!(
                    msg.data[227], 217,
                    "incorrect value for data[227], expected 217, is {}",
                    msg.data[227]
                );
                assert_eq!(
                    msg.data[228], 151,
                    "incorrect value for data[228], expected 151, is {}",
                    msg.data[228]
                );
                assert_eq!(
                    msg.data[229], 251,
                    "incorrect value for data[229], expected 251, is {}",
                    msg.data[229]
                );
                assert_eq!(
                    msg.data[230], 83,
                    "incorrect value for data[230], expected 83, is {}",
                    msg.data[230]
                );
                assert_eq!(
                    msg.data[231], 20,
                    "incorrect value for data[231], expected 20, is {}",
                    msg.data[231]
                );
                assert_eq!(
                    msg.data[232], 113,
                    "incorrect value for data[232], expected 113, is {}",
                    msg.data[232]
                );
                assert_eq!(
                    msg.data[233], 37,
                    "incorrect value for data[233], expected 37, is {}",
                    msg.data[233]
                );
                assert_eq!(
                    msg.data[234], 151,
                    "incorrect value for data[234], expected 151, is {}",
                    msg.data[234]
                );
                assert_eq!(
                    msg.data[235], 34,
                    "incorrect value for data[235], expected 34, is {}",
                    msg.data[235]
                );
                assert_eq!(
                    msg.data[236], 37,
                    "incorrect value for data[236], expected 37, is {}",
                    msg.data[236]
                );
                assert_eq!(
                    msg.data[237], 71,
                    "incorrect value for data[237], expected 71, is {}",
                    msg.data[237]
                );
                assert_eq!(
                    msg.data[238], 95,
                    "incorrect value for data[238], expected 95, is {}",
                    msg.data[238]
                );
                assert_eq!(
                    msg.data[239], 105,
                    "incorrect value for data[239], expected 105, is {}",
                    msg.data[239]
                );
                assert_eq!(
                    msg.data[240], 235,
                    "incorrect value for data[240], expected 235, is {}",
                    msg.data[240]
                );
                assert_eq!(
                    msg.data[241], 144,
                    "incorrect value for data[241], expected 144, is {}",
                    msg.data[241]
                );
                assert_eq!(
                    msg.data[242], 164,
                    "incorrect value for data[242], expected 164, is {}",
                    msg.data[242]
                );
                assert_eq!(
                    msg.data[243], 83,
                    "incorrect value for data[243], expected 83, is {}",
                    msg.data[243]
                );
                assert_eq!(
                    msg.data[244], 197,
                    "incorrect value for data[244], expected 197, is {}",
                    msg.data[244]
                );
                assert_eq!(
                    msg.data[245], 254,
                    "incorrect value for data[245], expected 254, is {}",
                    msg.data[245]
                );
                assert_eq!(
                    msg.data[246], 183,
                    "incorrect value for data[246], expected 183, is {}",
                    msg.data[246]
                );
                assert_eq!(
                    msg.data[247], 223,
                    "incorrect value for data[247], expected 223, is {}",
                    msg.data[247]
                );
                assert_eq!(
                    msg.data[248], 91,
                    "incorrect value for data[248], expected 91, is {}",
                    msg.data[248]
                );
                assert_eq!(
                    msg.data[249], 19,
                    "incorrect value for data[249], expected 19, is {}",
                    msg.data[249]
                );
                assert_eq!(
                    msg.target, 212,
                    "incorrect value for target, expected 212, is {}",
                    msg.target
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFlashProgram"),
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
fn test_json2sbp_auto_check_sbp_flash_msg_flash_program() {
    {
        let json_input = r#"{"crc":58157,"length":255,"msg_type":230,"payload":"1Fc09Pqw3utqkB2N/wMQwO2s/tUE3GIi3ubWBtmsei4NJvDsPHkv/KON3h2o1nY3yekV1jn19hMDeTHnJbo67mInRuiFGQqGgUXkhglYt4Wr/6ZkmOdcCcRq9h2RnJcgQ7w/6Y6ui5p/Izw4u3lnh5i2WKD/4/A2ZFsfjWaC/jbj5T414Y9Yi37r6yM2hqNcOVeCshaeEu3Ru+IBLkDi69W6n926GXNUg6fJaAHIDTJHScHJ+qzBDRTugvNEBEguwnH/7g/mQLJ/2VygyXajkDocrkFJLXt2U2vvqCDUv1Fdut8gEzqJSNmX+1MUcSWXIiVHX2nrkKRTxf6331sT","preamble":85,"sender":1219,"target":212,"addr_start":[87,52,244],"addr_len":250,"data":[176,222,235,106,144,29,141,255,3,16,192,237,172,254,213,4,220,98,34,222,230,214,6,217,172,122,46,13,38,240,236,60,121,47,252,163,141,222,29,168,214,118,55,201,233,21,214,57,245,246,19,3,121,49,231,37,186,58,238,98,39,70,232,133,25,10,134,129,69,228,134,9,88,183,133,171,255,166,100,152,231,92,9,196,106,246,29,145,156,151,32,67,188,63,233,142,174,139,154,127,35,60,56,187,121,103,135,152,182,88,160,255,227,240,54,100,91,31,141,102,130,254,54,227,229,62,53,225,143,88,139,126,235,235,35,54,134,163,92,57,87,130,178,22,158,18,237,209,187,226,1,46,64,226,235,213,186,159,221,186,25,115,84,131,167,201,104,1,200,13,50,71,73,193,201,250,172,193,13,20,238,130,243,68,4,72,46,194,113,255,238,15,230,64,178,127,217,92,160,201,118,163,144,58,28,174,65,73,45,123,118,83,107,239,168,32,212,191,81,93,186,223,32,19,58,137,72,217,151,251,83,20,113,37,151,34,37,71,95,105,235,144,164,83,197,254,183,223,91,19]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgFlashProgram(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xe6,
                    "Incorrect message type, expected 0xe6, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.addr_len, 250,
                    "incorrect value for addr_len, expected 250, is {}",
                    msg.addr_len
                );
                assert_eq!(
                    msg.addr_start[0], 87,
                    "incorrect value for addr_start[0], expected 87, is {}",
                    msg.addr_start[0]
                );
                assert_eq!(
                    msg.addr_start[1], 52,
                    "incorrect value for addr_start[1], expected 52, is {}",
                    msg.addr_start[1]
                );
                assert_eq!(
                    msg.addr_start[2], 244,
                    "incorrect value for addr_start[2], expected 244, is {}",
                    msg.addr_start[2]
                );
                assert_eq!(
                    msg.data[0], 176,
                    "incorrect value for data[0], expected 176, is {}",
                    msg.data[0]
                );
                assert_eq!(
                    msg.data[1], 222,
                    "incorrect value for data[1], expected 222, is {}",
                    msg.data[1]
                );
                assert_eq!(
                    msg.data[2], 235,
                    "incorrect value for data[2], expected 235, is {}",
                    msg.data[2]
                );
                assert_eq!(
                    msg.data[3], 106,
                    "incorrect value for data[3], expected 106, is {}",
                    msg.data[3]
                );
                assert_eq!(
                    msg.data[4], 144,
                    "incorrect value for data[4], expected 144, is {}",
                    msg.data[4]
                );
                assert_eq!(
                    msg.data[5], 29,
                    "incorrect value for data[5], expected 29, is {}",
                    msg.data[5]
                );
                assert_eq!(
                    msg.data[6], 141,
                    "incorrect value for data[6], expected 141, is {}",
                    msg.data[6]
                );
                assert_eq!(
                    msg.data[7], 255,
                    "incorrect value for data[7], expected 255, is {}",
                    msg.data[7]
                );
                assert_eq!(
                    msg.data[8], 3,
                    "incorrect value for data[8], expected 3, is {}",
                    msg.data[8]
                );
                assert_eq!(
                    msg.data[9], 16,
                    "incorrect value for data[9], expected 16, is {}",
                    msg.data[9]
                );
                assert_eq!(
                    msg.data[10], 192,
                    "incorrect value for data[10], expected 192, is {}",
                    msg.data[10]
                );
                assert_eq!(
                    msg.data[11], 237,
                    "incorrect value for data[11], expected 237, is {}",
                    msg.data[11]
                );
                assert_eq!(
                    msg.data[12], 172,
                    "incorrect value for data[12], expected 172, is {}",
                    msg.data[12]
                );
                assert_eq!(
                    msg.data[13], 254,
                    "incorrect value for data[13], expected 254, is {}",
                    msg.data[13]
                );
                assert_eq!(
                    msg.data[14], 213,
                    "incorrect value for data[14], expected 213, is {}",
                    msg.data[14]
                );
                assert_eq!(
                    msg.data[15], 4,
                    "incorrect value for data[15], expected 4, is {}",
                    msg.data[15]
                );
                assert_eq!(
                    msg.data[16], 220,
                    "incorrect value for data[16], expected 220, is {}",
                    msg.data[16]
                );
                assert_eq!(
                    msg.data[17], 98,
                    "incorrect value for data[17], expected 98, is {}",
                    msg.data[17]
                );
                assert_eq!(
                    msg.data[18], 34,
                    "incorrect value for data[18], expected 34, is {}",
                    msg.data[18]
                );
                assert_eq!(
                    msg.data[19], 222,
                    "incorrect value for data[19], expected 222, is {}",
                    msg.data[19]
                );
                assert_eq!(
                    msg.data[20], 230,
                    "incorrect value for data[20], expected 230, is {}",
                    msg.data[20]
                );
                assert_eq!(
                    msg.data[21], 214,
                    "incorrect value for data[21], expected 214, is {}",
                    msg.data[21]
                );
                assert_eq!(
                    msg.data[22], 6,
                    "incorrect value for data[22], expected 6, is {}",
                    msg.data[22]
                );
                assert_eq!(
                    msg.data[23], 217,
                    "incorrect value for data[23], expected 217, is {}",
                    msg.data[23]
                );
                assert_eq!(
                    msg.data[24], 172,
                    "incorrect value for data[24], expected 172, is {}",
                    msg.data[24]
                );
                assert_eq!(
                    msg.data[25], 122,
                    "incorrect value for data[25], expected 122, is {}",
                    msg.data[25]
                );
                assert_eq!(
                    msg.data[26], 46,
                    "incorrect value for data[26], expected 46, is {}",
                    msg.data[26]
                );
                assert_eq!(
                    msg.data[27], 13,
                    "incorrect value for data[27], expected 13, is {}",
                    msg.data[27]
                );
                assert_eq!(
                    msg.data[28], 38,
                    "incorrect value for data[28], expected 38, is {}",
                    msg.data[28]
                );
                assert_eq!(
                    msg.data[29], 240,
                    "incorrect value for data[29], expected 240, is {}",
                    msg.data[29]
                );
                assert_eq!(
                    msg.data[30], 236,
                    "incorrect value for data[30], expected 236, is {}",
                    msg.data[30]
                );
                assert_eq!(
                    msg.data[31], 60,
                    "incorrect value for data[31], expected 60, is {}",
                    msg.data[31]
                );
                assert_eq!(
                    msg.data[32], 121,
                    "incorrect value for data[32], expected 121, is {}",
                    msg.data[32]
                );
                assert_eq!(
                    msg.data[33], 47,
                    "incorrect value for data[33], expected 47, is {}",
                    msg.data[33]
                );
                assert_eq!(
                    msg.data[34], 252,
                    "incorrect value for data[34], expected 252, is {}",
                    msg.data[34]
                );
                assert_eq!(
                    msg.data[35], 163,
                    "incorrect value for data[35], expected 163, is {}",
                    msg.data[35]
                );
                assert_eq!(
                    msg.data[36], 141,
                    "incorrect value for data[36], expected 141, is {}",
                    msg.data[36]
                );
                assert_eq!(
                    msg.data[37], 222,
                    "incorrect value for data[37], expected 222, is {}",
                    msg.data[37]
                );
                assert_eq!(
                    msg.data[38], 29,
                    "incorrect value for data[38], expected 29, is {}",
                    msg.data[38]
                );
                assert_eq!(
                    msg.data[39], 168,
                    "incorrect value for data[39], expected 168, is {}",
                    msg.data[39]
                );
                assert_eq!(
                    msg.data[40], 214,
                    "incorrect value for data[40], expected 214, is {}",
                    msg.data[40]
                );
                assert_eq!(
                    msg.data[41], 118,
                    "incorrect value for data[41], expected 118, is {}",
                    msg.data[41]
                );
                assert_eq!(
                    msg.data[42], 55,
                    "incorrect value for data[42], expected 55, is {}",
                    msg.data[42]
                );
                assert_eq!(
                    msg.data[43], 201,
                    "incorrect value for data[43], expected 201, is {}",
                    msg.data[43]
                );
                assert_eq!(
                    msg.data[44], 233,
                    "incorrect value for data[44], expected 233, is {}",
                    msg.data[44]
                );
                assert_eq!(
                    msg.data[45], 21,
                    "incorrect value for data[45], expected 21, is {}",
                    msg.data[45]
                );
                assert_eq!(
                    msg.data[46], 214,
                    "incorrect value for data[46], expected 214, is {}",
                    msg.data[46]
                );
                assert_eq!(
                    msg.data[47], 57,
                    "incorrect value for data[47], expected 57, is {}",
                    msg.data[47]
                );
                assert_eq!(
                    msg.data[48], 245,
                    "incorrect value for data[48], expected 245, is {}",
                    msg.data[48]
                );
                assert_eq!(
                    msg.data[49], 246,
                    "incorrect value for data[49], expected 246, is {}",
                    msg.data[49]
                );
                assert_eq!(
                    msg.data[50], 19,
                    "incorrect value for data[50], expected 19, is {}",
                    msg.data[50]
                );
                assert_eq!(
                    msg.data[51], 3,
                    "incorrect value for data[51], expected 3, is {}",
                    msg.data[51]
                );
                assert_eq!(
                    msg.data[52], 121,
                    "incorrect value for data[52], expected 121, is {}",
                    msg.data[52]
                );
                assert_eq!(
                    msg.data[53], 49,
                    "incorrect value for data[53], expected 49, is {}",
                    msg.data[53]
                );
                assert_eq!(
                    msg.data[54], 231,
                    "incorrect value for data[54], expected 231, is {}",
                    msg.data[54]
                );
                assert_eq!(
                    msg.data[55], 37,
                    "incorrect value for data[55], expected 37, is {}",
                    msg.data[55]
                );
                assert_eq!(
                    msg.data[56], 186,
                    "incorrect value for data[56], expected 186, is {}",
                    msg.data[56]
                );
                assert_eq!(
                    msg.data[57], 58,
                    "incorrect value for data[57], expected 58, is {}",
                    msg.data[57]
                );
                assert_eq!(
                    msg.data[58], 238,
                    "incorrect value for data[58], expected 238, is {}",
                    msg.data[58]
                );
                assert_eq!(
                    msg.data[59], 98,
                    "incorrect value for data[59], expected 98, is {}",
                    msg.data[59]
                );
                assert_eq!(
                    msg.data[60], 39,
                    "incorrect value for data[60], expected 39, is {}",
                    msg.data[60]
                );
                assert_eq!(
                    msg.data[61], 70,
                    "incorrect value for data[61], expected 70, is {}",
                    msg.data[61]
                );
                assert_eq!(
                    msg.data[62], 232,
                    "incorrect value for data[62], expected 232, is {}",
                    msg.data[62]
                );
                assert_eq!(
                    msg.data[63], 133,
                    "incorrect value for data[63], expected 133, is {}",
                    msg.data[63]
                );
                assert_eq!(
                    msg.data[64], 25,
                    "incorrect value for data[64], expected 25, is {}",
                    msg.data[64]
                );
                assert_eq!(
                    msg.data[65], 10,
                    "incorrect value for data[65], expected 10, is {}",
                    msg.data[65]
                );
                assert_eq!(
                    msg.data[66], 134,
                    "incorrect value for data[66], expected 134, is {}",
                    msg.data[66]
                );
                assert_eq!(
                    msg.data[67], 129,
                    "incorrect value for data[67], expected 129, is {}",
                    msg.data[67]
                );
                assert_eq!(
                    msg.data[68], 69,
                    "incorrect value for data[68], expected 69, is {}",
                    msg.data[68]
                );
                assert_eq!(
                    msg.data[69], 228,
                    "incorrect value for data[69], expected 228, is {}",
                    msg.data[69]
                );
                assert_eq!(
                    msg.data[70], 134,
                    "incorrect value for data[70], expected 134, is {}",
                    msg.data[70]
                );
                assert_eq!(
                    msg.data[71], 9,
                    "incorrect value for data[71], expected 9, is {}",
                    msg.data[71]
                );
                assert_eq!(
                    msg.data[72], 88,
                    "incorrect value for data[72], expected 88, is {}",
                    msg.data[72]
                );
                assert_eq!(
                    msg.data[73], 183,
                    "incorrect value for data[73], expected 183, is {}",
                    msg.data[73]
                );
                assert_eq!(
                    msg.data[74], 133,
                    "incorrect value for data[74], expected 133, is {}",
                    msg.data[74]
                );
                assert_eq!(
                    msg.data[75], 171,
                    "incorrect value for data[75], expected 171, is {}",
                    msg.data[75]
                );
                assert_eq!(
                    msg.data[76], 255,
                    "incorrect value for data[76], expected 255, is {}",
                    msg.data[76]
                );
                assert_eq!(
                    msg.data[77], 166,
                    "incorrect value for data[77], expected 166, is {}",
                    msg.data[77]
                );
                assert_eq!(
                    msg.data[78], 100,
                    "incorrect value for data[78], expected 100, is {}",
                    msg.data[78]
                );
                assert_eq!(
                    msg.data[79], 152,
                    "incorrect value for data[79], expected 152, is {}",
                    msg.data[79]
                );
                assert_eq!(
                    msg.data[80], 231,
                    "incorrect value for data[80], expected 231, is {}",
                    msg.data[80]
                );
                assert_eq!(
                    msg.data[81], 92,
                    "incorrect value for data[81], expected 92, is {}",
                    msg.data[81]
                );
                assert_eq!(
                    msg.data[82], 9,
                    "incorrect value for data[82], expected 9, is {}",
                    msg.data[82]
                );
                assert_eq!(
                    msg.data[83], 196,
                    "incorrect value for data[83], expected 196, is {}",
                    msg.data[83]
                );
                assert_eq!(
                    msg.data[84], 106,
                    "incorrect value for data[84], expected 106, is {}",
                    msg.data[84]
                );
                assert_eq!(
                    msg.data[85], 246,
                    "incorrect value for data[85], expected 246, is {}",
                    msg.data[85]
                );
                assert_eq!(
                    msg.data[86], 29,
                    "incorrect value for data[86], expected 29, is {}",
                    msg.data[86]
                );
                assert_eq!(
                    msg.data[87], 145,
                    "incorrect value for data[87], expected 145, is {}",
                    msg.data[87]
                );
                assert_eq!(
                    msg.data[88], 156,
                    "incorrect value for data[88], expected 156, is {}",
                    msg.data[88]
                );
                assert_eq!(
                    msg.data[89], 151,
                    "incorrect value for data[89], expected 151, is {}",
                    msg.data[89]
                );
                assert_eq!(
                    msg.data[90], 32,
                    "incorrect value for data[90], expected 32, is {}",
                    msg.data[90]
                );
                assert_eq!(
                    msg.data[91], 67,
                    "incorrect value for data[91], expected 67, is {}",
                    msg.data[91]
                );
                assert_eq!(
                    msg.data[92], 188,
                    "incorrect value for data[92], expected 188, is {}",
                    msg.data[92]
                );
                assert_eq!(
                    msg.data[93], 63,
                    "incorrect value for data[93], expected 63, is {}",
                    msg.data[93]
                );
                assert_eq!(
                    msg.data[94], 233,
                    "incorrect value for data[94], expected 233, is {}",
                    msg.data[94]
                );
                assert_eq!(
                    msg.data[95], 142,
                    "incorrect value for data[95], expected 142, is {}",
                    msg.data[95]
                );
                assert_eq!(
                    msg.data[96], 174,
                    "incorrect value for data[96], expected 174, is {}",
                    msg.data[96]
                );
                assert_eq!(
                    msg.data[97], 139,
                    "incorrect value for data[97], expected 139, is {}",
                    msg.data[97]
                );
                assert_eq!(
                    msg.data[98], 154,
                    "incorrect value for data[98], expected 154, is {}",
                    msg.data[98]
                );
                assert_eq!(
                    msg.data[99], 127,
                    "incorrect value for data[99], expected 127, is {}",
                    msg.data[99]
                );
                assert_eq!(
                    msg.data[100], 35,
                    "incorrect value for data[100], expected 35, is {}",
                    msg.data[100]
                );
                assert_eq!(
                    msg.data[101], 60,
                    "incorrect value for data[101], expected 60, is {}",
                    msg.data[101]
                );
                assert_eq!(
                    msg.data[102], 56,
                    "incorrect value for data[102], expected 56, is {}",
                    msg.data[102]
                );
                assert_eq!(
                    msg.data[103], 187,
                    "incorrect value for data[103], expected 187, is {}",
                    msg.data[103]
                );
                assert_eq!(
                    msg.data[104], 121,
                    "incorrect value for data[104], expected 121, is {}",
                    msg.data[104]
                );
                assert_eq!(
                    msg.data[105], 103,
                    "incorrect value for data[105], expected 103, is {}",
                    msg.data[105]
                );
                assert_eq!(
                    msg.data[106], 135,
                    "incorrect value for data[106], expected 135, is {}",
                    msg.data[106]
                );
                assert_eq!(
                    msg.data[107], 152,
                    "incorrect value for data[107], expected 152, is {}",
                    msg.data[107]
                );
                assert_eq!(
                    msg.data[108], 182,
                    "incorrect value for data[108], expected 182, is {}",
                    msg.data[108]
                );
                assert_eq!(
                    msg.data[109], 88,
                    "incorrect value for data[109], expected 88, is {}",
                    msg.data[109]
                );
                assert_eq!(
                    msg.data[110], 160,
                    "incorrect value for data[110], expected 160, is {}",
                    msg.data[110]
                );
                assert_eq!(
                    msg.data[111], 255,
                    "incorrect value for data[111], expected 255, is {}",
                    msg.data[111]
                );
                assert_eq!(
                    msg.data[112], 227,
                    "incorrect value for data[112], expected 227, is {}",
                    msg.data[112]
                );
                assert_eq!(
                    msg.data[113], 240,
                    "incorrect value for data[113], expected 240, is {}",
                    msg.data[113]
                );
                assert_eq!(
                    msg.data[114], 54,
                    "incorrect value for data[114], expected 54, is {}",
                    msg.data[114]
                );
                assert_eq!(
                    msg.data[115], 100,
                    "incorrect value for data[115], expected 100, is {}",
                    msg.data[115]
                );
                assert_eq!(
                    msg.data[116], 91,
                    "incorrect value for data[116], expected 91, is {}",
                    msg.data[116]
                );
                assert_eq!(
                    msg.data[117], 31,
                    "incorrect value for data[117], expected 31, is {}",
                    msg.data[117]
                );
                assert_eq!(
                    msg.data[118], 141,
                    "incorrect value for data[118], expected 141, is {}",
                    msg.data[118]
                );
                assert_eq!(
                    msg.data[119], 102,
                    "incorrect value for data[119], expected 102, is {}",
                    msg.data[119]
                );
                assert_eq!(
                    msg.data[120], 130,
                    "incorrect value for data[120], expected 130, is {}",
                    msg.data[120]
                );
                assert_eq!(
                    msg.data[121], 254,
                    "incorrect value for data[121], expected 254, is {}",
                    msg.data[121]
                );
                assert_eq!(
                    msg.data[122], 54,
                    "incorrect value for data[122], expected 54, is {}",
                    msg.data[122]
                );
                assert_eq!(
                    msg.data[123], 227,
                    "incorrect value for data[123], expected 227, is {}",
                    msg.data[123]
                );
                assert_eq!(
                    msg.data[124], 229,
                    "incorrect value for data[124], expected 229, is {}",
                    msg.data[124]
                );
                assert_eq!(
                    msg.data[125], 62,
                    "incorrect value for data[125], expected 62, is {}",
                    msg.data[125]
                );
                assert_eq!(
                    msg.data[126], 53,
                    "incorrect value for data[126], expected 53, is {}",
                    msg.data[126]
                );
                assert_eq!(
                    msg.data[127], 225,
                    "incorrect value for data[127], expected 225, is {}",
                    msg.data[127]
                );
                assert_eq!(
                    msg.data[128], 143,
                    "incorrect value for data[128], expected 143, is {}",
                    msg.data[128]
                );
                assert_eq!(
                    msg.data[129], 88,
                    "incorrect value for data[129], expected 88, is {}",
                    msg.data[129]
                );
                assert_eq!(
                    msg.data[130], 139,
                    "incorrect value for data[130], expected 139, is {}",
                    msg.data[130]
                );
                assert_eq!(
                    msg.data[131], 126,
                    "incorrect value for data[131], expected 126, is {}",
                    msg.data[131]
                );
                assert_eq!(
                    msg.data[132], 235,
                    "incorrect value for data[132], expected 235, is {}",
                    msg.data[132]
                );
                assert_eq!(
                    msg.data[133], 235,
                    "incorrect value for data[133], expected 235, is {}",
                    msg.data[133]
                );
                assert_eq!(
                    msg.data[134], 35,
                    "incorrect value for data[134], expected 35, is {}",
                    msg.data[134]
                );
                assert_eq!(
                    msg.data[135], 54,
                    "incorrect value for data[135], expected 54, is {}",
                    msg.data[135]
                );
                assert_eq!(
                    msg.data[136], 134,
                    "incorrect value for data[136], expected 134, is {}",
                    msg.data[136]
                );
                assert_eq!(
                    msg.data[137], 163,
                    "incorrect value for data[137], expected 163, is {}",
                    msg.data[137]
                );
                assert_eq!(
                    msg.data[138], 92,
                    "incorrect value for data[138], expected 92, is {}",
                    msg.data[138]
                );
                assert_eq!(
                    msg.data[139], 57,
                    "incorrect value for data[139], expected 57, is {}",
                    msg.data[139]
                );
                assert_eq!(
                    msg.data[140], 87,
                    "incorrect value for data[140], expected 87, is {}",
                    msg.data[140]
                );
                assert_eq!(
                    msg.data[141], 130,
                    "incorrect value for data[141], expected 130, is {}",
                    msg.data[141]
                );
                assert_eq!(
                    msg.data[142], 178,
                    "incorrect value for data[142], expected 178, is {}",
                    msg.data[142]
                );
                assert_eq!(
                    msg.data[143], 22,
                    "incorrect value for data[143], expected 22, is {}",
                    msg.data[143]
                );
                assert_eq!(
                    msg.data[144], 158,
                    "incorrect value for data[144], expected 158, is {}",
                    msg.data[144]
                );
                assert_eq!(
                    msg.data[145], 18,
                    "incorrect value for data[145], expected 18, is {}",
                    msg.data[145]
                );
                assert_eq!(
                    msg.data[146], 237,
                    "incorrect value for data[146], expected 237, is {}",
                    msg.data[146]
                );
                assert_eq!(
                    msg.data[147], 209,
                    "incorrect value for data[147], expected 209, is {}",
                    msg.data[147]
                );
                assert_eq!(
                    msg.data[148], 187,
                    "incorrect value for data[148], expected 187, is {}",
                    msg.data[148]
                );
                assert_eq!(
                    msg.data[149], 226,
                    "incorrect value for data[149], expected 226, is {}",
                    msg.data[149]
                );
                assert_eq!(
                    msg.data[150], 1,
                    "incorrect value for data[150], expected 1, is {}",
                    msg.data[150]
                );
                assert_eq!(
                    msg.data[151], 46,
                    "incorrect value for data[151], expected 46, is {}",
                    msg.data[151]
                );
                assert_eq!(
                    msg.data[152], 64,
                    "incorrect value for data[152], expected 64, is {}",
                    msg.data[152]
                );
                assert_eq!(
                    msg.data[153], 226,
                    "incorrect value for data[153], expected 226, is {}",
                    msg.data[153]
                );
                assert_eq!(
                    msg.data[154], 235,
                    "incorrect value for data[154], expected 235, is {}",
                    msg.data[154]
                );
                assert_eq!(
                    msg.data[155], 213,
                    "incorrect value for data[155], expected 213, is {}",
                    msg.data[155]
                );
                assert_eq!(
                    msg.data[156], 186,
                    "incorrect value for data[156], expected 186, is {}",
                    msg.data[156]
                );
                assert_eq!(
                    msg.data[157], 159,
                    "incorrect value for data[157], expected 159, is {}",
                    msg.data[157]
                );
                assert_eq!(
                    msg.data[158], 221,
                    "incorrect value for data[158], expected 221, is {}",
                    msg.data[158]
                );
                assert_eq!(
                    msg.data[159], 186,
                    "incorrect value for data[159], expected 186, is {}",
                    msg.data[159]
                );
                assert_eq!(
                    msg.data[160], 25,
                    "incorrect value for data[160], expected 25, is {}",
                    msg.data[160]
                );
                assert_eq!(
                    msg.data[161], 115,
                    "incorrect value for data[161], expected 115, is {}",
                    msg.data[161]
                );
                assert_eq!(
                    msg.data[162], 84,
                    "incorrect value for data[162], expected 84, is {}",
                    msg.data[162]
                );
                assert_eq!(
                    msg.data[163], 131,
                    "incorrect value for data[163], expected 131, is {}",
                    msg.data[163]
                );
                assert_eq!(
                    msg.data[164], 167,
                    "incorrect value for data[164], expected 167, is {}",
                    msg.data[164]
                );
                assert_eq!(
                    msg.data[165], 201,
                    "incorrect value for data[165], expected 201, is {}",
                    msg.data[165]
                );
                assert_eq!(
                    msg.data[166], 104,
                    "incorrect value for data[166], expected 104, is {}",
                    msg.data[166]
                );
                assert_eq!(
                    msg.data[167], 1,
                    "incorrect value for data[167], expected 1, is {}",
                    msg.data[167]
                );
                assert_eq!(
                    msg.data[168], 200,
                    "incorrect value for data[168], expected 200, is {}",
                    msg.data[168]
                );
                assert_eq!(
                    msg.data[169], 13,
                    "incorrect value for data[169], expected 13, is {}",
                    msg.data[169]
                );
                assert_eq!(
                    msg.data[170], 50,
                    "incorrect value for data[170], expected 50, is {}",
                    msg.data[170]
                );
                assert_eq!(
                    msg.data[171], 71,
                    "incorrect value for data[171], expected 71, is {}",
                    msg.data[171]
                );
                assert_eq!(
                    msg.data[172], 73,
                    "incorrect value for data[172], expected 73, is {}",
                    msg.data[172]
                );
                assert_eq!(
                    msg.data[173], 193,
                    "incorrect value for data[173], expected 193, is {}",
                    msg.data[173]
                );
                assert_eq!(
                    msg.data[174], 201,
                    "incorrect value for data[174], expected 201, is {}",
                    msg.data[174]
                );
                assert_eq!(
                    msg.data[175], 250,
                    "incorrect value for data[175], expected 250, is {}",
                    msg.data[175]
                );
                assert_eq!(
                    msg.data[176], 172,
                    "incorrect value for data[176], expected 172, is {}",
                    msg.data[176]
                );
                assert_eq!(
                    msg.data[177], 193,
                    "incorrect value for data[177], expected 193, is {}",
                    msg.data[177]
                );
                assert_eq!(
                    msg.data[178], 13,
                    "incorrect value for data[178], expected 13, is {}",
                    msg.data[178]
                );
                assert_eq!(
                    msg.data[179], 20,
                    "incorrect value for data[179], expected 20, is {}",
                    msg.data[179]
                );
                assert_eq!(
                    msg.data[180], 238,
                    "incorrect value for data[180], expected 238, is {}",
                    msg.data[180]
                );
                assert_eq!(
                    msg.data[181], 130,
                    "incorrect value for data[181], expected 130, is {}",
                    msg.data[181]
                );
                assert_eq!(
                    msg.data[182], 243,
                    "incorrect value for data[182], expected 243, is {}",
                    msg.data[182]
                );
                assert_eq!(
                    msg.data[183], 68,
                    "incorrect value for data[183], expected 68, is {}",
                    msg.data[183]
                );
                assert_eq!(
                    msg.data[184], 4,
                    "incorrect value for data[184], expected 4, is {}",
                    msg.data[184]
                );
                assert_eq!(
                    msg.data[185], 72,
                    "incorrect value for data[185], expected 72, is {}",
                    msg.data[185]
                );
                assert_eq!(
                    msg.data[186], 46,
                    "incorrect value for data[186], expected 46, is {}",
                    msg.data[186]
                );
                assert_eq!(
                    msg.data[187], 194,
                    "incorrect value for data[187], expected 194, is {}",
                    msg.data[187]
                );
                assert_eq!(
                    msg.data[188], 113,
                    "incorrect value for data[188], expected 113, is {}",
                    msg.data[188]
                );
                assert_eq!(
                    msg.data[189], 255,
                    "incorrect value for data[189], expected 255, is {}",
                    msg.data[189]
                );
                assert_eq!(
                    msg.data[190], 238,
                    "incorrect value for data[190], expected 238, is {}",
                    msg.data[190]
                );
                assert_eq!(
                    msg.data[191], 15,
                    "incorrect value for data[191], expected 15, is {}",
                    msg.data[191]
                );
                assert_eq!(
                    msg.data[192], 230,
                    "incorrect value for data[192], expected 230, is {}",
                    msg.data[192]
                );
                assert_eq!(
                    msg.data[193], 64,
                    "incorrect value for data[193], expected 64, is {}",
                    msg.data[193]
                );
                assert_eq!(
                    msg.data[194], 178,
                    "incorrect value for data[194], expected 178, is {}",
                    msg.data[194]
                );
                assert_eq!(
                    msg.data[195], 127,
                    "incorrect value for data[195], expected 127, is {}",
                    msg.data[195]
                );
                assert_eq!(
                    msg.data[196], 217,
                    "incorrect value for data[196], expected 217, is {}",
                    msg.data[196]
                );
                assert_eq!(
                    msg.data[197], 92,
                    "incorrect value for data[197], expected 92, is {}",
                    msg.data[197]
                );
                assert_eq!(
                    msg.data[198], 160,
                    "incorrect value for data[198], expected 160, is {}",
                    msg.data[198]
                );
                assert_eq!(
                    msg.data[199], 201,
                    "incorrect value for data[199], expected 201, is {}",
                    msg.data[199]
                );
                assert_eq!(
                    msg.data[200], 118,
                    "incorrect value for data[200], expected 118, is {}",
                    msg.data[200]
                );
                assert_eq!(
                    msg.data[201], 163,
                    "incorrect value for data[201], expected 163, is {}",
                    msg.data[201]
                );
                assert_eq!(
                    msg.data[202], 144,
                    "incorrect value for data[202], expected 144, is {}",
                    msg.data[202]
                );
                assert_eq!(
                    msg.data[203], 58,
                    "incorrect value for data[203], expected 58, is {}",
                    msg.data[203]
                );
                assert_eq!(
                    msg.data[204], 28,
                    "incorrect value for data[204], expected 28, is {}",
                    msg.data[204]
                );
                assert_eq!(
                    msg.data[205], 174,
                    "incorrect value for data[205], expected 174, is {}",
                    msg.data[205]
                );
                assert_eq!(
                    msg.data[206], 65,
                    "incorrect value for data[206], expected 65, is {}",
                    msg.data[206]
                );
                assert_eq!(
                    msg.data[207], 73,
                    "incorrect value for data[207], expected 73, is {}",
                    msg.data[207]
                );
                assert_eq!(
                    msg.data[208], 45,
                    "incorrect value for data[208], expected 45, is {}",
                    msg.data[208]
                );
                assert_eq!(
                    msg.data[209], 123,
                    "incorrect value for data[209], expected 123, is {}",
                    msg.data[209]
                );
                assert_eq!(
                    msg.data[210], 118,
                    "incorrect value for data[210], expected 118, is {}",
                    msg.data[210]
                );
                assert_eq!(
                    msg.data[211], 83,
                    "incorrect value for data[211], expected 83, is {}",
                    msg.data[211]
                );
                assert_eq!(
                    msg.data[212], 107,
                    "incorrect value for data[212], expected 107, is {}",
                    msg.data[212]
                );
                assert_eq!(
                    msg.data[213], 239,
                    "incorrect value for data[213], expected 239, is {}",
                    msg.data[213]
                );
                assert_eq!(
                    msg.data[214], 168,
                    "incorrect value for data[214], expected 168, is {}",
                    msg.data[214]
                );
                assert_eq!(
                    msg.data[215], 32,
                    "incorrect value for data[215], expected 32, is {}",
                    msg.data[215]
                );
                assert_eq!(
                    msg.data[216], 212,
                    "incorrect value for data[216], expected 212, is {}",
                    msg.data[216]
                );
                assert_eq!(
                    msg.data[217], 191,
                    "incorrect value for data[217], expected 191, is {}",
                    msg.data[217]
                );
                assert_eq!(
                    msg.data[218], 81,
                    "incorrect value for data[218], expected 81, is {}",
                    msg.data[218]
                );
                assert_eq!(
                    msg.data[219], 93,
                    "incorrect value for data[219], expected 93, is {}",
                    msg.data[219]
                );
                assert_eq!(
                    msg.data[220], 186,
                    "incorrect value for data[220], expected 186, is {}",
                    msg.data[220]
                );
                assert_eq!(
                    msg.data[221], 223,
                    "incorrect value for data[221], expected 223, is {}",
                    msg.data[221]
                );
                assert_eq!(
                    msg.data[222], 32,
                    "incorrect value for data[222], expected 32, is {}",
                    msg.data[222]
                );
                assert_eq!(
                    msg.data[223], 19,
                    "incorrect value for data[223], expected 19, is {}",
                    msg.data[223]
                );
                assert_eq!(
                    msg.data[224], 58,
                    "incorrect value for data[224], expected 58, is {}",
                    msg.data[224]
                );
                assert_eq!(
                    msg.data[225], 137,
                    "incorrect value for data[225], expected 137, is {}",
                    msg.data[225]
                );
                assert_eq!(
                    msg.data[226], 72,
                    "incorrect value for data[226], expected 72, is {}",
                    msg.data[226]
                );
                assert_eq!(
                    msg.data[227], 217,
                    "incorrect value for data[227], expected 217, is {}",
                    msg.data[227]
                );
                assert_eq!(
                    msg.data[228], 151,
                    "incorrect value for data[228], expected 151, is {}",
                    msg.data[228]
                );
                assert_eq!(
                    msg.data[229], 251,
                    "incorrect value for data[229], expected 251, is {}",
                    msg.data[229]
                );
                assert_eq!(
                    msg.data[230], 83,
                    "incorrect value for data[230], expected 83, is {}",
                    msg.data[230]
                );
                assert_eq!(
                    msg.data[231], 20,
                    "incorrect value for data[231], expected 20, is {}",
                    msg.data[231]
                );
                assert_eq!(
                    msg.data[232], 113,
                    "incorrect value for data[232], expected 113, is {}",
                    msg.data[232]
                );
                assert_eq!(
                    msg.data[233], 37,
                    "incorrect value for data[233], expected 37, is {}",
                    msg.data[233]
                );
                assert_eq!(
                    msg.data[234], 151,
                    "incorrect value for data[234], expected 151, is {}",
                    msg.data[234]
                );
                assert_eq!(
                    msg.data[235], 34,
                    "incorrect value for data[235], expected 34, is {}",
                    msg.data[235]
                );
                assert_eq!(
                    msg.data[236], 37,
                    "incorrect value for data[236], expected 37, is {}",
                    msg.data[236]
                );
                assert_eq!(
                    msg.data[237], 71,
                    "incorrect value for data[237], expected 71, is {}",
                    msg.data[237]
                );
                assert_eq!(
                    msg.data[238], 95,
                    "incorrect value for data[238], expected 95, is {}",
                    msg.data[238]
                );
                assert_eq!(
                    msg.data[239], 105,
                    "incorrect value for data[239], expected 105, is {}",
                    msg.data[239]
                );
                assert_eq!(
                    msg.data[240], 235,
                    "incorrect value for data[240], expected 235, is {}",
                    msg.data[240]
                );
                assert_eq!(
                    msg.data[241], 144,
                    "incorrect value for data[241], expected 144, is {}",
                    msg.data[241]
                );
                assert_eq!(
                    msg.data[242], 164,
                    "incorrect value for data[242], expected 164, is {}",
                    msg.data[242]
                );
                assert_eq!(
                    msg.data[243], 83,
                    "incorrect value for data[243], expected 83, is {}",
                    msg.data[243]
                );
                assert_eq!(
                    msg.data[244], 197,
                    "incorrect value for data[244], expected 197, is {}",
                    msg.data[244]
                );
                assert_eq!(
                    msg.data[245], 254,
                    "incorrect value for data[245], expected 254, is {}",
                    msg.data[245]
                );
                assert_eq!(
                    msg.data[246], 183,
                    "incorrect value for data[246], expected 183, is {}",
                    msg.data[246]
                );
                assert_eq!(
                    msg.data[247], 223,
                    "incorrect value for data[247], expected 223, is {}",
                    msg.data[247]
                );
                assert_eq!(
                    msg.data[248], 91,
                    "incorrect value for data[248], expected 91, is {}",
                    msg.data[248]
                );
                assert_eq!(
                    msg.data[249], 19,
                    "incorrect value for data[249], expected 19, is {}",
                    msg.data[249]
                );
                assert_eq!(
                    msg.target, 212,
                    "incorrect value for target, expected 212, is {}",
                    msg.target
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFlashProgram"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_flash_msg_flash_program`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_flash_msg_flash_program() {
    {
        let mut payload = Cursor::new(vec![
            85, 230, 0, 195, 4, 255, 212, 87, 52, 244, 250, 176, 222, 235, 106, 144, 29, 141, 255,
            3, 16, 192, 237, 172, 254, 213, 4, 220, 98, 34, 222, 230, 214, 6, 217, 172, 122, 46,
            13, 38, 240, 236, 60, 121, 47, 252, 163, 141, 222, 29, 168, 214, 118, 55, 201, 233, 21,
            214, 57, 245, 246, 19, 3, 121, 49, 231, 37, 186, 58, 238, 98, 39, 70, 232, 133, 25, 10,
            134, 129, 69, 228, 134, 9, 88, 183, 133, 171, 255, 166, 100, 152, 231, 92, 9, 196, 106,
            246, 29, 145, 156, 151, 32, 67, 188, 63, 233, 142, 174, 139, 154, 127, 35, 60, 56, 187,
            121, 103, 135, 152, 182, 88, 160, 255, 227, 240, 54, 100, 91, 31, 141, 102, 130, 254,
            54, 227, 229, 62, 53, 225, 143, 88, 139, 126, 235, 235, 35, 54, 134, 163, 92, 57, 87,
            130, 178, 22, 158, 18, 237, 209, 187, 226, 1, 46, 64, 226, 235, 213, 186, 159, 221,
            186, 25, 115, 84, 131, 167, 201, 104, 1, 200, 13, 50, 71, 73, 193, 201, 250, 172, 193,
            13, 20, 238, 130, 243, 68, 4, 72, 46, 194, 113, 255, 238, 15, 230, 64, 178, 127, 217,
            92, 160, 201, 118, 163, 144, 58, 28, 174, 65, 73, 45, 123, 118, 83, 107, 239, 168, 32,
            212, 191, 81, 93, 186, 223, 32, 19, 58, 137, 72, 217, 151, 251, 83, 20, 113, 37, 151,
            34, 37, 71, 95, 105, 235, 144, 164, 83, 197, 254, 183, 223, 91, 19, 45, 227,
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
        let sbp_msg = sbp::messages::Sbp::MsgFlashProgram(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgFlashProgram(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xe6,
                    "Incorrect message type, expected 0xe6, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.addr_len, 250,
                    "incorrect value for addr_len, expected 250, is {}",
                    msg.addr_len
                );
                assert_eq!(
                    msg.addr_start[0], 87,
                    "incorrect value for addr_start[0], expected 87, is {}",
                    msg.addr_start[0]
                );
                assert_eq!(
                    msg.addr_start[1], 52,
                    "incorrect value for addr_start[1], expected 52, is {}",
                    msg.addr_start[1]
                );
                assert_eq!(
                    msg.addr_start[2], 244,
                    "incorrect value for addr_start[2], expected 244, is {}",
                    msg.addr_start[2]
                );
                assert_eq!(
                    msg.data[0], 176,
                    "incorrect value for data[0], expected 176, is {}",
                    msg.data[0]
                );
                assert_eq!(
                    msg.data[1], 222,
                    "incorrect value for data[1], expected 222, is {}",
                    msg.data[1]
                );
                assert_eq!(
                    msg.data[2], 235,
                    "incorrect value for data[2], expected 235, is {}",
                    msg.data[2]
                );
                assert_eq!(
                    msg.data[3], 106,
                    "incorrect value for data[3], expected 106, is {}",
                    msg.data[3]
                );
                assert_eq!(
                    msg.data[4], 144,
                    "incorrect value for data[4], expected 144, is {}",
                    msg.data[4]
                );
                assert_eq!(
                    msg.data[5], 29,
                    "incorrect value for data[5], expected 29, is {}",
                    msg.data[5]
                );
                assert_eq!(
                    msg.data[6], 141,
                    "incorrect value for data[6], expected 141, is {}",
                    msg.data[6]
                );
                assert_eq!(
                    msg.data[7], 255,
                    "incorrect value for data[7], expected 255, is {}",
                    msg.data[7]
                );
                assert_eq!(
                    msg.data[8], 3,
                    "incorrect value for data[8], expected 3, is {}",
                    msg.data[8]
                );
                assert_eq!(
                    msg.data[9], 16,
                    "incorrect value for data[9], expected 16, is {}",
                    msg.data[9]
                );
                assert_eq!(
                    msg.data[10], 192,
                    "incorrect value for data[10], expected 192, is {}",
                    msg.data[10]
                );
                assert_eq!(
                    msg.data[11], 237,
                    "incorrect value for data[11], expected 237, is {}",
                    msg.data[11]
                );
                assert_eq!(
                    msg.data[12], 172,
                    "incorrect value for data[12], expected 172, is {}",
                    msg.data[12]
                );
                assert_eq!(
                    msg.data[13], 254,
                    "incorrect value for data[13], expected 254, is {}",
                    msg.data[13]
                );
                assert_eq!(
                    msg.data[14], 213,
                    "incorrect value for data[14], expected 213, is {}",
                    msg.data[14]
                );
                assert_eq!(
                    msg.data[15], 4,
                    "incorrect value for data[15], expected 4, is {}",
                    msg.data[15]
                );
                assert_eq!(
                    msg.data[16], 220,
                    "incorrect value for data[16], expected 220, is {}",
                    msg.data[16]
                );
                assert_eq!(
                    msg.data[17], 98,
                    "incorrect value for data[17], expected 98, is {}",
                    msg.data[17]
                );
                assert_eq!(
                    msg.data[18], 34,
                    "incorrect value for data[18], expected 34, is {}",
                    msg.data[18]
                );
                assert_eq!(
                    msg.data[19], 222,
                    "incorrect value for data[19], expected 222, is {}",
                    msg.data[19]
                );
                assert_eq!(
                    msg.data[20], 230,
                    "incorrect value for data[20], expected 230, is {}",
                    msg.data[20]
                );
                assert_eq!(
                    msg.data[21], 214,
                    "incorrect value for data[21], expected 214, is {}",
                    msg.data[21]
                );
                assert_eq!(
                    msg.data[22], 6,
                    "incorrect value for data[22], expected 6, is {}",
                    msg.data[22]
                );
                assert_eq!(
                    msg.data[23], 217,
                    "incorrect value for data[23], expected 217, is {}",
                    msg.data[23]
                );
                assert_eq!(
                    msg.data[24], 172,
                    "incorrect value for data[24], expected 172, is {}",
                    msg.data[24]
                );
                assert_eq!(
                    msg.data[25], 122,
                    "incorrect value for data[25], expected 122, is {}",
                    msg.data[25]
                );
                assert_eq!(
                    msg.data[26], 46,
                    "incorrect value for data[26], expected 46, is {}",
                    msg.data[26]
                );
                assert_eq!(
                    msg.data[27], 13,
                    "incorrect value for data[27], expected 13, is {}",
                    msg.data[27]
                );
                assert_eq!(
                    msg.data[28], 38,
                    "incorrect value for data[28], expected 38, is {}",
                    msg.data[28]
                );
                assert_eq!(
                    msg.data[29], 240,
                    "incorrect value for data[29], expected 240, is {}",
                    msg.data[29]
                );
                assert_eq!(
                    msg.data[30], 236,
                    "incorrect value for data[30], expected 236, is {}",
                    msg.data[30]
                );
                assert_eq!(
                    msg.data[31], 60,
                    "incorrect value for data[31], expected 60, is {}",
                    msg.data[31]
                );
                assert_eq!(
                    msg.data[32], 121,
                    "incorrect value for data[32], expected 121, is {}",
                    msg.data[32]
                );
                assert_eq!(
                    msg.data[33], 47,
                    "incorrect value for data[33], expected 47, is {}",
                    msg.data[33]
                );
                assert_eq!(
                    msg.data[34], 252,
                    "incorrect value for data[34], expected 252, is {}",
                    msg.data[34]
                );
                assert_eq!(
                    msg.data[35], 163,
                    "incorrect value for data[35], expected 163, is {}",
                    msg.data[35]
                );
                assert_eq!(
                    msg.data[36], 141,
                    "incorrect value for data[36], expected 141, is {}",
                    msg.data[36]
                );
                assert_eq!(
                    msg.data[37], 222,
                    "incorrect value for data[37], expected 222, is {}",
                    msg.data[37]
                );
                assert_eq!(
                    msg.data[38], 29,
                    "incorrect value for data[38], expected 29, is {}",
                    msg.data[38]
                );
                assert_eq!(
                    msg.data[39], 168,
                    "incorrect value for data[39], expected 168, is {}",
                    msg.data[39]
                );
                assert_eq!(
                    msg.data[40], 214,
                    "incorrect value for data[40], expected 214, is {}",
                    msg.data[40]
                );
                assert_eq!(
                    msg.data[41], 118,
                    "incorrect value for data[41], expected 118, is {}",
                    msg.data[41]
                );
                assert_eq!(
                    msg.data[42], 55,
                    "incorrect value for data[42], expected 55, is {}",
                    msg.data[42]
                );
                assert_eq!(
                    msg.data[43], 201,
                    "incorrect value for data[43], expected 201, is {}",
                    msg.data[43]
                );
                assert_eq!(
                    msg.data[44], 233,
                    "incorrect value for data[44], expected 233, is {}",
                    msg.data[44]
                );
                assert_eq!(
                    msg.data[45], 21,
                    "incorrect value for data[45], expected 21, is {}",
                    msg.data[45]
                );
                assert_eq!(
                    msg.data[46], 214,
                    "incorrect value for data[46], expected 214, is {}",
                    msg.data[46]
                );
                assert_eq!(
                    msg.data[47], 57,
                    "incorrect value for data[47], expected 57, is {}",
                    msg.data[47]
                );
                assert_eq!(
                    msg.data[48], 245,
                    "incorrect value for data[48], expected 245, is {}",
                    msg.data[48]
                );
                assert_eq!(
                    msg.data[49], 246,
                    "incorrect value for data[49], expected 246, is {}",
                    msg.data[49]
                );
                assert_eq!(
                    msg.data[50], 19,
                    "incorrect value for data[50], expected 19, is {}",
                    msg.data[50]
                );
                assert_eq!(
                    msg.data[51], 3,
                    "incorrect value for data[51], expected 3, is {}",
                    msg.data[51]
                );
                assert_eq!(
                    msg.data[52], 121,
                    "incorrect value for data[52], expected 121, is {}",
                    msg.data[52]
                );
                assert_eq!(
                    msg.data[53], 49,
                    "incorrect value for data[53], expected 49, is {}",
                    msg.data[53]
                );
                assert_eq!(
                    msg.data[54], 231,
                    "incorrect value for data[54], expected 231, is {}",
                    msg.data[54]
                );
                assert_eq!(
                    msg.data[55], 37,
                    "incorrect value for data[55], expected 37, is {}",
                    msg.data[55]
                );
                assert_eq!(
                    msg.data[56], 186,
                    "incorrect value for data[56], expected 186, is {}",
                    msg.data[56]
                );
                assert_eq!(
                    msg.data[57], 58,
                    "incorrect value for data[57], expected 58, is {}",
                    msg.data[57]
                );
                assert_eq!(
                    msg.data[58], 238,
                    "incorrect value for data[58], expected 238, is {}",
                    msg.data[58]
                );
                assert_eq!(
                    msg.data[59], 98,
                    "incorrect value for data[59], expected 98, is {}",
                    msg.data[59]
                );
                assert_eq!(
                    msg.data[60], 39,
                    "incorrect value for data[60], expected 39, is {}",
                    msg.data[60]
                );
                assert_eq!(
                    msg.data[61], 70,
                    "incorrect value for data[61], expected 70, is {}",
                    msg.data[61]
                );
                assert_eq!(
                    msg.data[62], 232,
                    "incorrect value for data[62], expected 232, is {}",
                    msg.data[62]
                );
                assert_eq!(
                    msg.data[63], 133,
                    "incorrect value for data[63], expected 133, is {}",
                    msg.data[63]
                );
                assert_eq!(
                    msg.data[64], 25,
                    "incorrect value for data[64], expected 25, is {}",
                    msg.data[64]
                );
                assert_eq!(
                    msg.data[65], 10,
                    "incorrect value for data[65], expected 10, is {}",
                    msg.data[65]
                );
                assert_eq!(
                    msg.data[66], 134,
                    "incorrect value for data[66], expected 134, is {}",
                    msg.data[66]
                );
                assert_eq!(
                    msg.data[67], 129,
                    "incorrect value for data[67], expected 129, is {}",
                    msg.data[67]
                );
                assert_eq!(
                    msg.data[68], 69,
                    "incorrect value for data[68], expected 69, is {}",
                    msg.data[68]
                );
                assert_eq!(
                    msg.data[69], 228,
                    "incorrect value for data[69], expected 228, is {}",
                    msg.data[69]
                );
                assert_eq!(
                    msg.data[70], 134,
                    "incorrect value for data[70], expected 134, is {}",
                    msg.data[70]
                );
                assert_eq!(
                    msg.data[71], 9,
                    "incorrect value for data[71], expected 9, is {}",
                    msg.data[71]
                );
                assert_eq!(
                    msg.data[72], 88,
                    "incorrect value for data[72], expected 88, is {}",
                    msg.data[72]
                );
                assert_eq!(
                    msg.data[73], 183,
                    "incorrect value for data[73], expected 183, is {}",
                    msg.data[73]
                );
                assert_eq!(
                    msg.data[74], 133,
                    "incorrect value for data[74], expected 133, is {}",
                    msg.data[74]
                );
                assert_eq!(
                    msg.data[75], 171,
                    "incorrect value for data[75], expected 171, is {}",
                    msg.data[75]
                );
                assert_eq!(
                    msg.data[76], 255,
                    "incorrect value for data[76], expected 255, is {}",
                    msg.data[76]
                );
                assert_eq!(
                    msg.data[77], 166,
                    "incorrect value for data[77], expected 166, is {}",
                    msg.data[77]
                );
                assert_eq!(
                    msg.data[78], 100,
                    "incorrect value for data[78], expected 100, is {}",
                    msg.data[78]
                );
                assert_eq!(
                    msg.data[79], 152,
                    "incorrect value for data[79], expected 152, is {}",
                    msg.data[79]
                );
                assert_eq!(
                    msg.data[80], 231,
                    "incorrect value for data[80], expected 231, is {}",
                    msg.data[80]
                );
                assert_eq!(
                    msg.data[81], 92,
                    "incorrect value for data[81], expected 92, is {}",
                    msg.data[81]
                );
                assert_eq!(
                    msg.data[82], 9,
                    "incorrect value for data[82], expected 9, is {}",
                    msg.data[82]
                );
                assert_eq!(
                    msg.data[83], 196,
                    "incorrect value for data[83], expected 196, is {}",
                    msg.data[83]
                );
                assert_eq!(
                    msg.data[84], 106,
                    "incorrect value for data[84], expected 106, is {}",
                    msg.data[84]
                );
                assert_eq!(
                    msg.data[85], 246,
                    "incorrect value for data[85], expected 246, is {}",
                    msg.data[85]
                );
                assert_eq!(
                    msg.data[86], 29,
                    "incorrect value for data[86], expected 29, is {}",
                    msg.data[86]
                );
                assert_eq!(
                    msg.data[87], 145,
                    "incorrect value for data[87], expected 145, is {}",
                    msg.data[87]
                );
                assert_eq!(
                    msg.data[88], 156,
                    "incorrect value for data[88], expected 156, is {}",
                    msg.data[88]
                );
                assert_eq!(
                    msg.data[89], 151,
                    "incorrect value for data[89], expected 151, is {}",
                    msg.data[89]
                );
                assert_eq!(
                    msg.data[90], 32,
                    "incorrect value for data[90], expected 32, is {}",
                    msg.data[90]
                );
                assert_eq!(
                    msg.data[91], 67,
                    "incorrect value for data[91], expected 67, is {}",
                    msg.data[91]
                );
                assert_eq!(
                    msg.data[92], 188,
                    "incorrect value for data[92], expected 188, is {}",
                    msg.data[92]
                );
                assert_eq!(
                    msg.data[93], 63,
                    "incorrect value for data[93], expected 63, is {}",
                    msg.data[93]
                );
                assert_eq!(
                    msg.data[94], 233,
                    "incorrect value for data[94], expected 233, is {}",
                    msg.data[94]
                );
                assert_eq!(
                    msg.data[95], 142,
                    "incorrect value for data[95], expected 142, is {}",
                    msg.data[95]
                );
                assert_eq!(
                    msg.data[96], 174,
                    "incorrect value for data[96], expected 174, is {}",
                    msg.data[96]
                );
                assert_eq!(
                    msg.data[97], 139,
                    "incorrect value for data[97], expected 139, is {}",
                    msg.data[97]
                );
                assert_eq!(
                    msg.data[98], 154,
                    "incorrect value for data[98], expected 154, is {}",
                    msg.data[98]
                );
                assert_eq!(
                    msg.data[99], 127,
                    "incorrect value for data[99], expected 127, is {}",
                    msg.data[99]
                );
                assert_eq!(
                    msg.data[100], 35,
                    "incorrect value for data[100], expected 35, is {}",
                    msg.data[100]
                );
                assert_eq!(
                    msg.data[101], 60,
                    "incorrect value for data[101], expected 60, is {}",
                    msg.data[101]
                );
                assert_eq!(
                    msg.data[102], 56,
                    "incorrect value for data[102], expected 56, is {}",
                    msg.data[102]
                );
                assert_eq!(
                    msg.data[103], 187,
                    "incorrect value for data[103], expected 187, is {}",
                    msg.data[103]
                );
                assert_eq!(
                    msg.data[104], 121,
                    "incorrect value for data[104], expected 121, is {}",
                    msg.data[104]
                );
                assert_eq!(
                    msg.data[105], 103,
                    "incorrect value for data[105], expected 103, is {}",
                    msg.data[105]
                );
                assert_eq!(
                    msg.data[106], 135,
                    "incorrect value for data[106], expected 135, is {}",
                    msg.data[106]
                );
                assert_eq!(
                    msg.data[107], 152,
                    "incorrect value for data[107], expected 152, is {}",
                    msg.data[107]
                );
                assert_eq!(
                    msg.data[108], 182,
                    "incorrect value for data[108], expected 182, is {}",
                    msg.data[108]
                );
                assert_eq!(
                    msg.data[109], 88,
                    "incorrect value for data[109], expected 88, is {}",
                    msg.data[109]
                );
                assert_eq!(
                    msg.data[110], 160,
                    "incorrect value for data[110], expected 160, is {}",
                    msg.data[110]
                );
                assert_eq!(
                    msg.data[111], 255,
                    "incorrect value for data[111], expected 255, is {}",
                    msg.data[111]
                );
                assert_eq!(
                    msg.data[112], 227,
                    "incorrect value for data[112], expected 227, is {}",
                    msg.data[112]
                );
                assert_eq!(
                    msg.data[113], 240,
                    "incorrect value for data[113], expected 240, is {}",
                    msg.data[113]
                );
                assert_eq!(
                    msg.data[114], 54,
                    "incorrect value for data[114], expected 54, is {}",
                    msg.data[114]
                );
                assert_eq!(
                    msg.data[115], 100,
                    "incorrect value for data[115], expected 100, is {}",
                    msg.data[115]
                );
                assert_eq!(
                    msg.data[116], 91,
                    "incorrect value for data[116], expected 91, is {}",
                    msg.data[116]
                );
                assert_eq!(
                    msg.data[117], 31,
                    "incorrect value for data[117], expected 31, is {}",
                    msg.data[117]
                );
                assert_eq!(
                    msg.data[118], 141,
                    "incorrect value for data[118], expected 141, is {}",
                    msg.data[118]
                );
                assert_eq!(
                    msg.data[119], 102,
                    "incorrect value for data[119], expected 102, is {}",
                    msg.data[119]
                );
                assert_eq!(
                    msg.data[120], 130,
                    "incorrect value for data[120], expected 130, is {}",
                    msg.data[120]
                );
                assert_eq!(
                    msg.data[121], 254,
                    "incorrect value for data[121], expected 254, is {}",
                    msg.data[121]
                );
                assert_eq!(
                    msg.data[122], 54,
                    "incorrect value for data[122], expected 54, is {}",
                    msg.data[122]
                );
                assert_eq!(
                    msg.data[123], 227,
                    "incorrect value for data[123], expected 227, is {}",
                    msg.data[123]
                );
                assert_eq!(
                    msg.data[124], 229,
                    "incorrect value for data[124], expected 229, is {}",
                    msg.data[124]
                );
                assert_eq!(
                    msg.data[125], 62,
                    "incorrect value for data[125], expected 62, is {}",
                    msg.data[125]
                );
                assert_eq!(
                    msg.data[126], 53,
                    "incorrect value for data[126], expected 53, is {}",
                    msg.data[126]
                );
                assert_eq!(
                    msg.data[127], 225,
                    "incorrect value for data[127], expected 225, is {}",
                    msg.data[127]
                );
                assert_eq!(
                    msg.data[128], 143,
                    "incorrect value for data[128], expected 143, is {}",
                    msg.data[128]
                );
                assert_eq!(
                    msg.data[129], 88,
                    "incorrect value for data[129], expected 88, is {}",
                    msg.data[129]
                );
                assert_eq!(
                    msg.data[130], 139,
                    "incorrect value for data[130], expected 139, is {}",
                    msg.data[130]
                );
                assert_eq!(
                    msg.data[131], 126,
                    "incorrect value for data[131], expected 126, is {}",
                    msg.data[131]
                );
                assert_eq!(
                    msg.data[132], 235,
                    "incorrect value for data[132], expected 235, is {}",
                    msg.data[132]
                );
                assert_eq!(
                    msg.data[133], 235,
                    "incorrect value for data[133], expected 235, is {}",
                    msg.data[133]
                );
                assert_eq!(
                    msg.data[134], 35,
                    "incorrect value for data[134], expected 35, is {}",
                    msg.data[134]
                );
                assert_eq!(
                    msg.data[135], 54,
                    "incorrect value for data[135], expected 54, is {}",
                    msg.data[135]
                );
                assert_eq!(
                    msg.data[136], 134,
                    "incorrect value for data[136], expected 134, is {}",
                    msg.data[136]
                );
                assert_eq!(
                    msg.data[137], 163,
                    "incorrect value for data[137], expected 163, is {}",
                    msg.data[137]
                );
                assert_eq!(
                    msg.data[138], 92,
                    "incorrect value for data[138], expected 92, is {}",
                    msg.data[138]
                );
                assert_eq!(
                    msg.data[139], 57,
                    "incorrect value for data[139], expected 57, is {}",
                    msg.data[139]
                );
                assert_eq!(
                    msg.data[140], 87,
                    "incorrect value for data[140], expected 87, is {}",
                    msg.data[140]
                );
                assert_eq!(
                    msg.data[141], 130,
                    "incorrect value for data[141], expected 130, is {}",
                    msg.data[141]
                );
                assert_eq!(
                    msg.data[142], 178,
                    "incorrect value for data[142], expected 178, is {}",
                    msg.data[142]
                );
                assert_eq!(
                    msg.data[143], 22,
                    "incorrect value for data[143], expected 22, is {}",
                    msg.data[143]
                );
                assert_eq!(
                    msg.data[144], 158,
                    "incorrect value for data[144], expected 158, is {}",
                    msg.data[144]
                );
                assert_eq!(
                    msg.data[145], 18,
                    "incorrect value for data[145], expected 18, is {}",
                    msg.data[145]
                );
                assert_eq!(
                    msg.data[146], 237,
                    "incorrect value for data[146], expected 237, is {}",
                    msg.data[146]
                );
                assert_eq!(
                    msg.data[147], 209,
                    "incorrect value for data[147], expected 209, is {}",
                    msg.data[147]
                );
                assert_eq!(
                    msg.data[148], 187,
                    "incorrect value for data[148], expected 187, is {}",
                    msg.data[148]
                );
                assert_eq!(
                    msg.data[149], 226,
                    "incorrect value for data[149], expected 226, is {}",
                    msg.data[149]
                );
                assert_eq!(
                    msg.data[150], 1,
                    "incorrect value for data[150], expected 1, is {}",
                    msg.data[150]
                );
                assert_eq!(
                    msg.data[151], 46,
                    "incorrect value for data[151], expected 46, is {}",
                    msg.data[151]
                );
                assert_eq!(
                    msg.data[152], 64,
                    "incorrect value for data[152], expected 64, is {}",
                    msg.data[152]
                );
                assert_eq!(
                    msg.data[153], 226,
                    "incorrect value for data[153], expected 226, is {}",
                    msg.data[153]
                );
                assert_eq!(
                    msg.data[154], 235,
                    "incorrect value for data[154], expected 235, is {}",
                    msg.data[154]
                );
                assert_eq!(
                    msg.data[155], 213,
                    "incorrect value for data[155], expected 213, is {}",
                    msg.data[155]
                );
                assert_eq!(
                    msg.data[156], 186,
                    "incorrect value for data[156], expected 186, is {}",
                    msg.data[156]
                );
                assert_eq!(
                    msg.data[157], 159,
                    "incorrect value for data[157], expected 159, is {}",
                    msg.data[157]
                );
                assert_eq!(
                    msg.data[158], 221,
                    "incorrect value for data[158], expected 221, is {}",
                    msg.data[158]
                );
                assert_eq!(
                    msg.data[159], 186,
                    "incorrect value for data[159], expected 186, is {}",
                    msg.data[159]
                );
                assert_eq!(
                    msg.data[160], 25,
                    "incorrect value for data[160], expected 25, is {}",
                    msg.data[160]
                );
                assert_eq!(
                    msg.data[161], 115,
                    "incorrect value for data[161], expected 115, is {}",
                    msg.data[161]
                );
                assert_eq!(
                    msg.data[162], 84,
                    "incorrect value for data[162], expected 84, is {}",
                    msg.data[162]
                );
                assert_eq!(
                    msg.data[163], 131,
                    "incorrect value for data[163], expected 131, is {}",
                    msg.data[163]
                );
                assert_eq!(
                    msg.data[164], 167,
                    "incorrect value for data[164], expected 167, is {}",
                    msg.data[164]
                );
                assert_eq!(
                    msg.data[165], 201,
                    "incorrect value for data[165], expected 201, is {}",
                    msg.data[165]
                );
                assert_eq!(
                    msg.data[166], 104,
                    "incorrect value for data[166], expected 104, is {}",
                    msg.data[166]
                );
                assert_eq!(
                    msg.data[167], 1,
                    "incorrect value for data[167], expected 1, is {}",
                    msg.data[167]
                );
                assert_eq!(
                    msg.data[168], 200,
                    "incorrect value for data[168], expected 200, is {}",
                    msg.data[168]
                );
                assert_eq!(
                    msg.data[169], 13,
                    "incorrect value for data[169], expected 13, is {}",
                    msg.data[169]
                );
                assert_eq!(
                    msg.data[170], 50,
                    "incorrect value for data[170], expected 50, is {}",
                    msg.data[170]
                );
                assert_eq!(
                    msg.data[171], 71,
                    "incorrect value for data[171], expected 71, is {}",
                    msg.data[171]
                );
                assert_eq!(
                    msg.data[172], 73,
                    "incorrect value for data[172], expected 73, is {}",
                    msg.data[172]
                );
                assert_eq!(
                    msg.data[173], 193,
                    "incorrect value for data[173], expected 193, is {}",
                    msg.data[173]
                );
                assert_eq!(
                    msg.data[174], 201,
                    "incorrect value for data[174], expected 201, is {}",
                    msg.data[174]
                );
                assert_eq!(
                    msg.data[175], 250,
                    "incorrect value for data[175], expected 250, is {}",
                    msg.data[175]
                );
                assert_eq!(
                    msg.data[176], 172,
                    "incorrect value for data[176], expected 172, is {}",
                    msg.data[176]
                );
                assert_eq!(
                    msg.data[177], 193,
                    "incorrect value for data[177], expected 193, is {}",
                    msg.data[177]
                );
                assert_eq!(
                    msg.data[178], 13,
                    "incorrect value for data[178], expected 13, is {}",
                    msg.data[178]
                );
                assert_eq!(
                    msg.data[179], 20,
                    "incorrect value for data[179], expected 20, is {}",
                    msg.data[179]
                );
                assert_eq!(
                    msg.data[180], 238,
                    "incorrect value for data[180], expected 238, is {}",
                    msg.data[180]
                );
                assert_eq!(
                    msg.data[181], 130,
                    "incorrect value for data[181], expected 130, is {}",
                    msg.data[181]
                );
                assert_eq!(
                    msg.data[182], 243,
                    "incorrect value for data[182], expected 243, is {}",
                    msg.data[182]
                );
                assert_eq!(
                    msg.data[183], 68,
                    "incorrect value for data[183], expected 68, is {}",
                    msg.data[183]
                );
                assert_eq!(
                    msg.data[184], 4,
                    "incorrect value for data[184], expected 4, is {}",
                    msg.data[184]
                );
                assert_eq!(
                    msg.data[185], 72,
                    "incorrect value for data[185], expected 72, is {}",
                    msg.data[185]
                );
                assert_eq!(
                    msg.data[186], 46,
                    "incorrect value for data[186], expected 46, is {}",
                    msg.data[186]
                );
                assert_eq!(
                    msg.data[187], 194,
                    "incorrect value for data[187], expected 194, is {}",
                    msg.data[187]
                );
                assert_eq!(
                    msg.data[188], 113,
                    "incorrect value for data[188], expected 113, is {}",
                    msg.data[188]
                );
                assert_eq!(
                    msg.data[189], 255,
                    "incorrect value for data[189], expected 255, is {}",
                    msg.data[189]
                );
                assert_eq!(
                    msg.data[190], 238,
                    "incorrect value for data[190], expected 238, is {}",
                    msg.data[190]
                );
                assert_eq!(
                    msg.data[191], 15,
                    "incorrect value for data[191], expected 15, is {}",
                    msg.data[191]
                );
                assert_eq!(
                    msg.data[192], 230,
                    "incorrect value for data[192], expected 230, is {}",
                    msg.data[192]
                );
                assert_eq!(
                    msg.data[193], 64,
                    "incorrect value for data[193], expected 64, is {}",
                    msg.data[193]
                );
                assert_eq!(
                    msg.data[194], 178,
                    "incorrect value for data[194], expected 178, is {}",
                    msg.data[194]
                );
                assert_eq!(
                    msg.data[195], 127,
                    "incorrect value for data[195], expected 127, is {}",
                    msg.data[195]
                );
                assert_eq!(
                    msg.data[196], 217,
                    "incorrect value for data[196], expected 217, is {}",
                    msg.data[196]
                );
                assert_eq!(
                    msg.data[197], 92,
                    "incorrect value for data[197], expected 92, is {}",
                    msg.data[197]
                );
                assert_eq!(
                    msg.data[198], 160,
                    "incorrect value for data[198], expected 160, is {}",
                    msg.data[198]
                );
                assert_eq!(
                    msg.data[199], 201,
                    "incorrect value for data[199], expected 201, is {}",
                    msg.data[199]
                );
                assert_eq!(
                    msg.data[200], 118,
                    "incorrect value for data[200], expected 118, is {}",
                    msg.data[200]
                );
                assert_eq!(
                    msg.data[201], 163,
                    "incorrect value for data[201], expected 163, is {}",
                    msg.data[201]
                );
                assert_eq!(
                    msg.data[202], 144,
                    "incorrect value for data[202], expected 144, is {}",
                    msg.data[202]
                );
                assert_eq!(
                    msg.data[203], 58,
                    "incorrect value for data[203], expected 58, is {}",
                    msg.data[203]
                );
                assert_eq!(
                    msg.data[204], 28,
                    "incorrect value for data[204], expected 28, is {}",
                    msg.data[204]
                );
                assert_eq!(
                    msg.data[205], 174,
                    "incorrect value for data[205], expected 174, is {}",
                    msg.data[205]
                );
                assert_eq!(
                    msg.data[206], 65,
                    "incorrect value for data[206], expected 65, is {}",
                    msg.data[206]
                );
                assert_eq!(
                    msg.data[207], 73,
                    "incorrect value for data[207], expected 73, is {}",
                    msg.data[207]
                );
                assert_eq!(
                    msg.data[208], 45,
                    "incorrect value for data[208], expected 45, is {}",
                    msg.data[208]
                );
                assert_eq!(
                    msg.data[209], 123,
                    "incorrect value for data[209], expected 123, is {}",
                    msg.data[209]
                );
                assert_eq!(
                    msg.data[210], 118,
                    "incorrect value for data[210], expected 118, is {}",
                    msg.data[210]
                );
                assert_eq!(
                    msg.data[211], 83,
                    "incorrect value for data[211], expected 83, is {}",
                    msg.data[211]
                );
                assert_eq!(
                    msg.data[212], 107,
                    "incorrect value for data[212], expected 107, is {}",
                    msg.data[212]
                );
                assert_eq!(
                    msg.data[213], 239,
                    "incorrect value for data[213], expected 239, is {}",
                    msg.data[213]
                );
                assert_eq!(
                    msg.data[214], 168,
                    "incorrect value for data[214], expected 168, is {}",
                    msg.data[214]
                );
                assert_eq!(
                    msg.data[215], 32,
                    "incorrect value for data[215], expected 32, is {}",
                    msg.data[215]
                );
                assert_eq!(
                    msg.data[216], 212,
                    "incorrect value for data[216], expected 212, is {}",
                    msg.data[216]
                );
                assert_eq!(
                    msg.data[217], 191,
                    "incorrect value for data[217], expected 191, is {}",
                    msg.data[217]
                );
                assert_eq!(
                    msg.data[218], 81,
                    "incorrect value for data[218], expected 81, is {}",
                    msg.data[218]
                );
                assert_eq!(
                    msg.data[219], 93,
                    "incorrect value for data[219], expected 93, is {}",
                    msg.data[219]
                );
                assert_eq!(
                    msg.data[220], 186,
                    "incorrect value for data[220], expected 186, is {}",
                    msg.data[220]
                );
                assert_eq!(
                    msg.data[221], 223,
                    "incorrect value for data[221], expected 223, is {}",
                    msg.data[221]
                );
                assert_eq!(
                    msg.data[222], 32,
                    "incorrect value for data[222], expected 32, is {}",
                    msg.data[222]
                );
                assert_eq!(
                    msg.data[223], 19,
                    "incorrect value for data[223], expected 19, is {}",
                    msg.data[223]
                );
                assert_eq!(
                    msg.data[224], 58,
                    "incorrect value for data[224], expected 58, is {}",
                    msg.data[224]
                );
                assert_eq!(
                    msg.data[225], 137,
                    "incorrect value for data[225], expected 137, is {}",
                    msg.data[225]
                );
                assert_eq!(
                    msg.data[226], 72,
                    "incorrect value for data[226], expected 72, is {}",
                    msg.data[226]
                );
                assert_eq!(
                    msg.data[227], 217,
                    "incorrect value for data[227], expected 217, is {}",
                    msg.data[227]
                );
                assert_eq!(
                    msg.data[228], 151,
                    "incorrect value for data[228], expected 151, is {}",
                    msg.data[228]
                );
                assert_eq!(
                    msg.data[229], 251,
                    "incorrect value for data[229], expected 251, is {}",
                    msg.data[229]
                );
                assert_eq!(
                    msg.data[230], 83,
                    "incorrect value for data[230], expected 83, is {}",
                    msg.data[230]
                );
                assert_eq!(
                    msg.data[231], 20,
                    "incorrect value for data[231], expected 20, is {}",
                    msg.data[231]
                );
                assert_eq!(
                    msg.data[232], 113,
                    "incorrect value for data[232], expected 113, is {}",
                    msg.data[232]
                );
                assert_eq!(
                    msg.data[233], 37,
                    "incorrect value for data[233], expected 37, is {}",
                    msg.data[233]
                );
                assert_eq!(
                    msg.data[234], 151,
                    "incorrect value for data[234], expected 151, is {}",
                    msg.data[234]
                );
                assert_eq!(
                    msg.data[235], 34,
                    "incorrect value for data[235], expected 34, is {}",
                    msg.data[235]
                );
                assert_eq!(
                    msg.data[236], 37,
                    "incorrect value for data[236], expected 37, is {}",
                    msg.data[236]
                );
                assert_eq!(
                    msg.data[237], 71,
                    "incorrect value for data[237], expected 71, is {}",
                    msg.data[237]
                );
                assert_eq!(
                    msg.data[238], 95,
                    "incorrect value for data[238], expected 95, is {}",
                    msg.data[238]
                );
                assert_eq!(
                    msg.data[239], 105,
                    "incorrect value for data[239], expected 105, is {}",
                    msg.data[239]
                );
                assert_eq!(
                    msg.data[240], 235,
                    "incorrect value for data[240], expected 235, is {}",
                    msg.data[240]
                );
                assert_eq!(
                    msg.data[241], 144,
                    "incorrect value for data[241], expected 144, is {}",
                    msg.data[241]
                );
                assert_eq!(
                    msg.data[242], 164,
                    "incorrect value for data[242], expected 164, is {}",
                    msg.data[242]
                );
                assert_eq!(
                    msg.data[243], 83,
                    "incorrect value for data[243], expected 83, is {}",
                    msg.data[243]
                );
                assert_eq!(
                    msg.data[244], 197,
                    "incorrect value for data[244], expected 197, is {}",
                    msg.data[244]
                );
                assert_eq!(
                    msg.data[245], 254,
                    "incorrect value for data[245], expected 254, is {}",
                    msg.data[245]
                );
                assert_eq!(
                    msg.data[246], 183,
                    "incorrect value for data[246], expected 183, is {}",
                    msg.data[246]
                );
                assert_eq!(
                    msg.data[247], 223,
                    "incorrect value for data[247], expected 223, is {}",
                    msg.data[247]
                );
                assert_eq!(
                    msg.data[248], 91,
                    "incorrect value for data[248], expected 91, is {}",
                    msg.data[248]
                );
                assert_eq!(
                    msg.data[249], 19,
                    "incorrect value for data[249], expected 19, is {}",
                    msg.data[249]
                );
                assert_eq!(
                    msg.target, 212,
                    "incorrect value for target, expected 212, is {}",
                    msg.target
                );
            }
            _ => panic!("Invalid message type! Expected a MsgFlashProgram"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
