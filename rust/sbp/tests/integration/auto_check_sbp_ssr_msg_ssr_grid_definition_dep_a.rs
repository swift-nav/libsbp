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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGridDefinitionDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_grid_definition_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 245, 5, 181, 247, 255, 11, 84, 171, 229, 132, 143, 46, 204, 52, 92, 104, 25, 204,
            182, 22, 98, 203, 123, 211, 38, 13, 253, 129, 173, 171, 235, 253, 26, 203, 3, 120, 126,
            42, 44, 39, 87, 69, 154, 13, 28, 179, 32, 47, 36, 195, 39, 198, 134, 235, 134, 57, 120,
            243, 151, 35, 17, 201, 211, 125, 117, 164, 142, 101, 239, 144, 158, 239, 90, 56, 71,
            120, 67, 221, 114, 10, 190, 4, 230, 164, 171, 78, 185, 90, 46, 177, 82, 228, 123, 222,
            227, 145, 195, 219, 27, 56, 227, 246, 215, 144, 158, 31, 214, 241, 254, 200, 86, 142,
            89, 12, 121, 29, 124, 9, 19, 153, 44, 35, 126, 14, 217, 65, 116, 26, 139, 122, 114, 90,
            124, 81, 0, 186, 246, 46, 98, 179, 243, 198, 217, 36, 30, 202, 12, 135, 61, 42, 150,
            221, 102, 83, 179, 43, 252, 81, 62, 126, 204, 195, 238, 18, 128, 193, 53, 94, 99, 63,
            182, 2, 186, 220, 77, 186, 224, 220, 13, 212, 182, 88, 15, 151, 5, 93, 251, 164, 18,
            228, 168, 226, 195, 44, 170, 145, 36, 58, 96, 107, 144, 11, 228, 12, 163, 238, 247,
            159, 189, 1, 115, 65, 202, 121, 47, 193, 11, 96, 93, 72, 81, 207, 121, 19, 151, 136,
            233, 51, 133, 195, 77, 44, 147, 206, 120, 252, 77, 212, 68, 60, 206, 106, 207, 243,
            158, 94, 6, 3, 205, 92, 84, 2, 220, 50, 61, 38, 141, 117, 108, 101, 76, 139,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrGridDefinitionDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5f5,
                    "Incorrect message type, expected 0x5f5, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf7b5,
                    "incorrect sender id, expected 0xf7b5, is {sender_id}"
                );
                assert_eq!(
                    msg.header.area_width, 43860,
                    "incorrect value for header.area_width, expected 43860, is {}",
                    msg.header.area_width
                );
                assert_eq!(
                    msg.header.lat_nw_corner_enc, 34021,
                    "incorrect value for header.lat_nw_corner_enc, expected 34021, is {}",
                    msg.header.lat_nw_corner_enc
                );
                assert_eq!(
                    msg.header.lon_nw_corner_enc, 11919,
                    "incorrect value for header.lon_nw_corner_enc, expected 11919, is {}",
                    msg.header.lon_nw_corner_enc
                );
                assert_eq!(
                    msg.header.num_msgs, 204,
                    "incorrect value for header.num_msgs, expected 204, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.region_size_inverse, 11,
                    "incorrect value for header.region_size_inverse, expected 11, is {}",
                    msg.header.region_size_inverse
                );
                assert_eq!(
                    msg.header.seq_num, 52,
                    "incorrect value for header.seq_num, expected 52, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.rle_list[0], 92,
                    "incorrect value for rle_list[0], expected 92, is {}",
                    msg.rle_list[0]
                );
                assert_eq!(
                    msg.rle_list[1], 104,
                    "incorrect value for rle_list[1], expected 104, is {}",
                    msg.rle_list[1]
                );
                assert_eq!(
                    msg.rle_list[2], 25,
                    "incorrect value for rle_list[2], expected 25, is {}",
                    msg.rle_list[2]
                );
                assert_eq!(
                    msg.rle_list[3], 204,
                    "incorrect value for rle_list[3], expected 204, is {}",
                    msg.rle_list[3]
                );
                assert_eq!(
                    msg.rle_list[4], 182,
                    "incorrect value for rle_list[4], expected 182, is {}",
                    msg.rle_list[4]
                );
                assert_eq!(
                    msg.rle_list[5], 22,
                    "incorrect value for rle_list[5], expected 22, is {}",
                    msg.rle_list[5]
                );
                assert_eq!(
                    msg.rle_list[6], 98,
                    "incorrect value for rle_list[6], expected 98, is {}",
                    msg.rle_list[6]
                );
                assert_eq!(
                    msg.rle_list[7], 203,
                    "incorrect value for rle_list[7], expected 203, is {}",
                    msg.rle_list[7]
                );
                assert_eq!(
                    msg.rle_list[8], 123,
                    "incorrect value for rle_list[8], expected 123, is {}",
                    msg.rle_list[8]
                );
                assert_eq!(
                    msg.rle_list[9], 211,
                    "incorrect value for rle_list[9], expected 211, is {}",
                    msg.rle_list[9]
                );
                assert_eq!(
                    msg.rle_list[10], 38,
                    "incorrect value for rle_list[10], expected 38, is {}",
                    msg.rle_list[10]
                );
                assert_eq!(
                    msg.rle_list[11], 13,
                    "incorrect value for rle_list[11], expected 13, is {}",
                    msg.rle_list[11]
                );
                assert_eq!(
                    msg.rle_list[12], 253,
                    "incorrect value for rle_list[12], expected 253, is {}",
                    msg.rle_list[12]
                );
                assert_eq!(
                    msg.rle_list[13], 129,
                    "incorrect value for rle_list[13], expected 129, is {}",
                    msg.rle_list[13]
                );
                assert_eq!(
                    msg.rle_list[14], 173,
                    "incorrect value for rle_list[14], expected 173, is {}",
                    msg.rle_list[14]
                );
                assert_eq!(
                    msg.rle_list[15], 171,
                    "incorrect value for rle_list[15], expected 171, is {}",
                    msg.rle_list[15]
                );
                assert_eq!(
                    msg.rle_list[16], 235,
                    "incorrect value for rle_list[16], expected 235, is {}",
                    msg.rle_list[16]
                );
                assert_eq!(
                    msg.rle_list[17], 253,
                    "incorrect value for rle_list[17], expected 253, is {}",
                    msg.rle_list[17]
                );
                assert_eq!(
                    msg.rle_list[18], 26,
                    "incorrect value for rle_list[18], expected 26, is {}",
                    msg.rle_list[18]
                );
                assert_eq!(
                    msg.rle_list[19], 203,
                    "incorrect value for rle_list[19], expected 203, is {}",
                    msg.rle_list[19]
                );
                assert_eq!(
                    msg.rle_list[20], 3,
                    "incorrect value for rle_list[20], expected 3, is {}",
                    msg.rle_list[20]
                );
                assert_eq!(
                    msg.rle_list[21], 120,
                    "incorrect value for rle_list[21], expected 120, is {}",
                    msg.rle_list[21]
                );
                assert_eq!(
                    msg.rle_list[22], 126,
                    "incorrect value for rle_list[22], expected 126, is {}",
                    msg.rle_list[22]
                );
                assert_eq!(
                    msg.rle_list[23], 42,
                    "incorrect value for rle_list[23], expected 42, is {}",
                    msg.rle_list[23]
                );
                assert_eq!(
                    msg.rle_list[24], 44,
                    "incorrect value for rle_list[24], expected 44, is {}",
                    msg.rle_list[24]
                );
                assert_eq!(
                    msg.rle_list[25], 39,
                    "incorrect value for rle_list[25], expected 39, is {}",
                    msg.rle_list[25]
                );
                assert_eq!(
                    msg.rle_list[26], 87,
                    "incorrect value for rle_list[26], expected 87, is {}",
                    msg.rle_list[26]
                );
                assert_eq!(
                    msg.rle_list[27], 69,
                    "incorrect value for rle_list[27], expected 69, is {}",
                    msg.rle_list[27]
                );
                assert_eq!(
                    msg.rle_list[28], 154,
                    "incorrect value for rle_list[28], expected 154, is {}",
                    msg.rle_list[28]
                );
                assert_eq!(
                    msg.rle_list[29], 13,
                    "incorrect value for rle_list[29], expected 13, is {}",
                    msg.rle_list[29]
                );
                assert_eq!(
                    msg.rle_list[30], 28,
                    "incorrect value for rle_list[30], expected 28, is {}",
                    msg.rle_list[30]
                );
                assert_eq!(
                    msg.rle_list[31], 179,
                    "incorrect value for rle_list[31], expected 179, is {}",
                    msg.rle_list[31]
                );
                assert_eq!(
                    msg.rle_list[32], 32,
                    "incorrect value for rle_list[32], expected 32, is {}",
                    msg.rle_list[32]
                );
                assert_eq!(
                    msg.rle_list[33], 47,
                    "incorrect value for rle_list[33], expected 47, is {}",
                    msg.rle_list[33]
                );
                assert_eq!(
                    msg.rle_list[34], 36,
                    "incorrect value for rle_list[34], expected 36, is {}",
                    msg.rle_list[34]
                );
                assert_eq!(
                    msg.rle_list[35], 195,
                    "incorrect value for rle_list[35], expected 195, is {}",
                    msg.rle_list[35]
                );
                assert_eq!(
                    msg.rle_list[36], 39,
                    "incorrect value for rle_list[36], expected 39, is {}",
                    msg.rle_list[36]
                );
                assert_eq!(
                    msg.rle_list[37], 198,
                    "incorrect value for rle_list[37], expected 198, is {}",
                    msg.rle_list[37]
                );
                assert_eq!(
                    msg.rle_list[38], 134,
                    "incorrect value for rle_list[38], expected 134, is {}",
                    msg.rle_list[38]
                );
                assert_eq!(
                    msg.rle_list[39], 235,
                    "incorrect value for rle_list[39], expected 235, is {}",
                    msg.rle_list[39]
                );
                assert_eq!(
                    msg.rle_list[40], 134,
                    "incorrect value for rle_list[40], expected 134, is {}",
                    msg.rle_list[40]
                );
                assert_eq!(
                    msg.rle_list[41], 57,
                    "incorrect value for rle_list[41], expected 57, is {}",
                    msg.rle_list[41]
                );
                assert_eq!(
                    msg.rle_list[42], 120,
                    "incorrect value for rle_list[42], expected 120, is {}",
                    msg.rle_list[42]
                );
                assert_eq!(
                    msg.rle_list[43], 243,
                    "incorrect value for rle_list[43], expected 243, is {}",
                    msg.rle_list[43]
                );
                assert_eq!(
                    msg.rle_list[44], 151,
                    "incorrect value for rle_list[44], expected 151, is {}",
                    msg.rle_list[44]
                );
                assert_eq!(
                    msg.rle_list[45], 35,
                    "incorrect value for rle_list[45], expected 35, is {}",
                    msg.rle_list[45]
                );
                assert_eq!(
                    msg.rle_list[46], 17,
                    "incorrect value for rle_list[46], expected 17, is {}",
                    msg.rle_list[46]
                );
                assert_eq!(
                    msg.rle_list[47], 201,
                    "incorrect value for rle_list[47], expected 201, is {}",
                    msg.rle_list[47]
                );
                assert_eq!(
                    msg.rle_list[48], 211,
                    "incorrect value for rle_list[48], expected 211, is {}",
                    msg.rle_list[48]
                );
                assert_eq!(
                    msg.rle_list[49], 125,
                    "incorrect value for rle_list[49], expected 125, is {}",
                    msg.rle_list[49]
                );
                assert_eq!(
                    msg.rle_list[50], 117,
                    "incorrect value for rle_list[50], expected 117, is {}",
                    msg.rle_list[50]
                );
                assert_eq!(
                    msg.rle_list[51], 164,
                    "incorrect value for rle_list[51], expected 164, is {}",
                    msg.rle_list[51]
                );
                assert_eq!(
                    msg.rle_list[52], 142,
                    "incorrect value for rle_list[52], expected 142, is {}",
                    msg.rle_list[52]
                );
                assert_eq!(
                    msg.rle_list[53], 101,
                    "incorrect value for rle_list[53], expected 101, is {}",
                    msg.rle_list[53]
                );
                assert_eq!(
                    msg.rle_list[54], 239,
                    "incorrect value for rle_list[54], expected 239, is {}",
                    msg.rle_list[54]
                );
                assert_eq!(
                    msg.rle_list[55], 144,
                    "incorrect value for rle_list[55], expected 144, is {}",
                    msg.rle_list[55]
                );
                assert_eq!(
                    msg.rle_list[56], 158,
                    "incorrect value for rle_list[56], expected 158, is {}",
                    msg.rle_list[56]
                );
                assert_eq!(
                    msg.rle_list[57], 239,
                    "incorrect value for rle_list[57], expected 239, is {}",
                    msg.rle_list[57]
                );
                assert_eq!(
                    msg.rle_list[58], 90,
                    "incorrect value for rle_list[58], expected 90, is {}",
                    msg.rle_list[58]
                );
                assert_eq!(
                    msg.rle_list[59], 56,
                    "incorrect value for rle_list[59], expected 56, is {}",
                    msg.rle_list[59]
                );
                assert_eq!(
                    msg.rle_list[60], 71,
                    "incorrect value for rle_list[60], expected 71, is {}",
                    msg.rle_list[60]
                );
                assert_eq!(
                    msg.rle_list[61], 120,
                    "incorrect value for rle_list[61], expected 120, is {}",
                    msg.rle_list[61]
                );
                assert_eq!(
                    msg.rle_list[62], 67,
                    "incorrect value for rle_list[62], expected 67, is {}",
                    msg.rle_list[62]
                );
                assert_eq!(
                    msg.rle_list[63], 221,
                    "incorrect value for rle_list[63], expected 221, is {}",
                    msg.rle_list[63]
                );
                assert_eq!(
                    msg.rle_list[64], 114,
                    "incorrect value for rle_list[64], expected 114, is {}",
                    msg.rle_list[64]
                );
                assert_eq!(
                    msg.rle_list[65], 10,
                    "incorrect value for rle_list[65], expected 10, is {}",
                    msg.rle_list[65]
                );
                assert_eq!(
                    msg.rle_list[66], 190,
                    "incorrect value for rle_list[66], expected 190, is {}",
                    msg.rle_list[66]
                );
                assert_eq!(
                    msg.rle_list[67], 4,
                    "incorrect value for rle_list[67], expected 4, is {}",
                    msg.rle_list[67]
                );
                assert_eq!(
                    msg.rle_list[68], 230,
                    "incorrect value for rle_list[68], expected 230, is {}",
                    msg.rle_list[68]
                );
                assert_eq!(
                    msg.rle_list[69], 164,
                    "incorrect value for rle_list[69], expected 164, is {}",
                    msg.rle_list[69]
                );
                assert_eq!(
                    msg.rle_list[70], 171,
                    "incorrect value for rle_list[70], expected 171, is {}",
                    msg.rle_list[70]
                );
                assert_eq!(
                    msg.rle_list[71], 78,
                    "incorrect value for rle_list[71], expected 78, is {}",
                    msg.rle_list[71]
                );
                assert_eq!(
                    msg.rle_list[72], 185,
                    "incorrect value for rle_list[72], expected 185, is {}",
                    msg.rle_list[72]
                );
                assert_eq!(
                    msg.rle_list[73], 90,
                    "incorrect value for rle_list[73], expected 90, is {}",
                    msg.rle_list[73]
                );
                assert_eq!(
                    msg.rle_list[74], 46,
                    "incorrect value for rle_list[74], expected 46, is {}",
                    msg.rle_list[74]
                );
                assert_eq!(
                    msg.rle_list[75], 177,
                    "incorrect value for rle_list[75], expected 177, is {}",
                    msg.rle_list[75]
                );
                assert_eq!(
                    msg.rle_list[76], 82,
                    "incorrect value for rle_list[76], expected 82, is {}",
                    msg.rle_list[76]
                );
                assert_eq!(
                    msg.rle_list[77], 228,
                    "incorrect value for rle_list[77], expected 228, is {}",
                    msg.rle_list[77]
                );
                assert_eq!(
                    msg.rle_list[78], 123,
                    "incorrect value for rle_list[78], expected 123, is {}",
                    msg.rle_list[78]
                );
                assert_eq!(
                    msg.rle_list[79], 222,
                    "incorrect value for rle_list[79], expected 222, is {}",
                    msg.rle_list[79]
                );
                assert_eq!(
                    msg.rle_list[80], 227,
                    "incorrect value for rle_list[80], expected 227, is {}",
                    msg.rle_list[80]
                );
                assert_eq!(
                    msg.rle_list[81], 145,
                    "incorrect value for rle_list[81], expected 145, is {}",
                    msg.rle_list[81]
                );
                assert_eq!(
                    msg.rle_list[82], 195,
                    "incorrect value for rle_list[82], expected 195, is {}",
                    msg.rle_list[82]
                );
                assert_eq!(
                    msg.rle_list[83], 219,
                    "incorrect value for rle_list[83], expected 219, is {}",
                    msg.rle_list[83]
                );
                assert_eq!(
                    msg.rle_list[84], 27,
                    "incorrect value for rle_list[84], expected 27, is {}",
                    msg.rle_list[84]
                );
                assert_eq!(
                    msg.rle_list[85], 56,
                    "incorrect value for rle_list[85], expected 56, is {}",
                    msg.rle_list[85]
                );
                assert_eq!(
                    msg.rle_list[86], 227,
                    "incorrect value for rle_list[86], expected 227, is {}",
                    msg.rle_list[86]
                );
                assert_eq!(
                    msg.rle_list[87], 246,
                    "incorrect value for rle_list[87], expected 246, is {}",
                    msg.rle_list[87]
                );
                assert_eq!(
                    msg.rle_list[88], 215,
                    "incorrect value for rle_list[88], expected 215, is {}",
                    msg.rle_list[88]
                );
                assert_eq!(
                    msg.rle_list[89], 144,
                    "incorrect value for rle_list[89], expected 144, is {}",
                    msg.rle_list[89]
                );
                assert_eq!(
                    msg.rle_list[90], 158,
                    "incorrect value for rle_list[90], expected 158, is {}",
                    msg.rle_list[90]
                );
                assert_eq!(
                    msg.rle_list[91], 31,
                    "incorrect value for rle_list[91], expected 31, is {}",
                    msg.rle_list[91]
                );
                assert_eq!(
                    msg.rle_list[92], 214,
                    "incorrect value for rle_list[92], expected 214, is {}",
                    msg.rle_list[92]
                );
                assert_eq!(
                    msg.rle_list[93], 241,
                    "incorrect value for rle_list[93], expected 241, is {}",
                    msg.rle_list[93]
                );
                assert_eq!(
                    msg.rle_list[94], 254,
                    "incorrect value for rle_list[94], expected 254, is {}",
                    msg.rle_list[94]
                );
                assert_eq!(
                    msg.rle_list[95], 200,
                    "incorrect value for rle_list[95], expected 200, is {}",
                    msg.rle_list[95]
                );
                assert_eq!(
                    msg.rle_list[96], 86,
                    "incorrect value for rle_list[96], expected 86, is {}",
                    msg.rle_list[96]
                );
                assert_eq!(
                    msg.rle_list[97], 142,
                    "incorrect value for rle_list[97], expected 142, is {}",
                    msg.rle_list[97]
                );
                assert_eq!(
                    msg.rle_list[98], 89,
                    "incorrect value for rle_list[98], expected 89, is {}",
                    msg.rle_list[98]
                );
                assert_eq!(
                    msg.rle_list[99], 12,
                    "incorrect value for rle_list[99], expected 12, is {}",
                    msg.rle_list[99]
                );
                assert_eq!(
                    msg.rle_list[100], 121,
                    "incorrect value for rle_list[100], expected 121, is {}",
                    msg.rle_list[100]
                );
                assert_eq!(
                    msg.rle_list[101], 29,
                    "incorrect value for rle_list[101], expected 29, is {}",
                    msg.rle_list[101]
                );
                assert_eq!(
                    msg.rle_list[102], 124,
                    "incorrect value for rle_list[102], expected 124, is {}",
                    msg.rle_list[102]
                );
                assert_eq!(
                    msg.rle_list[103], 9,
                    "incorrect value for rle_list[103], expected 9, is {}",
                    msg.rle_list[103]
                );
                assert_eq!(
                    msg.rle_list[104], 19,
                    "incorrect value for rle_list[104], expected 19, is {}",
                    msg.rle_list[104]
                );
                assert_eq!(
                    msg.rle_list[105], 153,
                    "incorrect value for rle_list[105], expected 153, is {}",
                    msg.rle_list[105]
                );
                assert_eq!(
                    msg.rle_list[106], 44,
                    "incorrect value for rle_list[106], expected 44, is {}",
                    msg.rle_list[106]
                );
                assert_eq!(
                    msg.rle_list[107], 35,
                    "incorrect value for rle_list[107], expected 35, is {}",
                    msg.rle_list[107]
                );
                assert_eq!(
                    msg.rle_list[108], 126,
                    "incorrect value for rle_list[108], expected 126, is {}",
                    msg.rle_list[108]
                );
                assert_eq!(
                    msg.rle_list[109], 14,
                    "incorrect value for rle_list[109], expected 14, is {}",
                    msg.rle_list[109]
                );
                assert_eq!(
                    msg.rle_list[110], 217,
                    "incorrect value for rle_list[110], expected 217, is {}",
                    msg.rle_list[110]
                );
                assert_eq!(
                    msg.rle_list[111], 65,
                    "incorrect value for rle_list[111], expected 65, is {}",
                    msg.rle_list[111]
                );
                assert_eq!(
                    msg.rle_list[112], 116,
                    "incorrect value for rle_list[112], expected 116, is {}",
                    msg.rle_list[112]
                );
                assert_eq!(
                    msg.rle_list[113], 26,
                    "incorrect value for rle_list[113], expected 26, is {}",
                    msg.rle_list[113]
                );
                assert_eq!(
                    msg.rle_list[114], 139,
                    "incorrect value for rle_list[114], expected 139, is {}",
                    msg.rle_list[114]
                );
                assert_eq!(
                    msg.rle_list[115], 122,
                    "incorrect value for rle_list[115], expected 122, is {}",
                    msg.rle_list[115]
                );
                assert_eq!(
                    msg.rle_list[116], 114,
                    "incorrect value for rle_list[116], expected 114, is {}",
                    msg.rle_list[116]
                );
                assert_eq!(
                    msg.rle_list[117], 90,
                    "incorrect value for rle_list[117], expected 90, is {}",
                    msg.rle_list[117]
                );
                assert_eq!(
                    msg.rle_list[118], 124,
                    "incorrect value for rle_list[118], expected 124, is {}",
                    msg.rle_list[118]
                );
                assert_eq!(
                    msg.rle_list[119], 81,
                    "incorrect value for rle_list[119], expected 81, is {}",
                    msg.rle_list[119]
                );
                assert_eq!(
                    msg.rle_list[120], 0,
                    "incorrect value for rle_list[120], expected 0, is {}",
                    msg.rle_list[120]
                );
                assert_eq!(
                    msg.rle_list[121], 186,
                    "incorrect value for rle_list[121], expected 186, is {}",
                    msg.rle_list[121]
                );
                assert_eq!(
                    msg.rle_list[122], 246,
                    "incorrect value for rle_list[122], expected 246, is {}",
                    msg.rle_list[122]
                );
                assert_eq!(
                    msg.rle_list[123], 46,
                    "incorrect value for rle_list[123], expected 46, is {}",
                    msg.rle_list[123]
                );
                assert_eq!(
                    msg.rle_list[124], 98,
                    "incorrect value for rle_list[124], expected 98, is {}",
                    msg.rle_list[124]
                );
                assert_eq!(
                    msg.rle_list[125], 179,
                    "incorrect value for rle_list[125], expected 179, is {}",
                    msg.rle_list[125]
                );
                assert_eq!(
                    msg.rle_list[126], 243,
                    "incorrect value for rle_list[126], expected 243, is {}",
                    msg.rle_list[126]
                );
                assert_eq!(
                    msg.rle_list[127], 198,
                    "incorrect value for rle_list[127], expected 198, is {}",
                    msg.rle_list[127]
                );
                assert_eq!(
                    msg.rle_list[128], 217,
                    "incorrect value for rle_list[128], expected 217, is {}",
                    msg.rle_list[128]
                );
                assert_eq!(
                    msg.rle_list[129], 36,
                    "incorrect value for rle_list[129], expected 36, is {}",
                    msg.rle_list[129]
                );
                assert_eq!(
                    msg.rle_list[130], 30,
                    "incorrect value for rle_list[130], expected 30, is {}",
                    msg.rle_list[130]
                );
                assert_eq!(
                    msg.rle_list[131], 202,
                    "incorrect value for rle_list[131], expected 202, is {}",
                    msg.rle_list[131]
                );
                assert_eq!(
                    msg.rle_list[132], 12,
                    "incorrect value for rle_list[132], expected 12, is {}",
                    msg.rle_list[132]
                );
                assert_eq!(
                    msg.rle_list[133], 135,
                    "incorrect value for rle_list[133], expected 135, is {}",
                    msg.rle_list[133]
                );
                assert_eq!(
                    msg.rle_list[134], 61,
                    "incorrect value for rle_list[134], expected 61, is {}",
                    msg.rle_list[134]
                );
                assert_eq!(
                    msg.rle_list[135], 42,
                    "incorrect value for rle_list[135], expected 42, is {}",
                    msg.rle_list[135]
                );
                assert_eq!(
                    msg.rle_list[136], 150,
                    "incorrect value for rle_list[136], expected 150, is {}",
                    msg.rle_list[136]
                );
                assert_eq!(
                    msg.rle_list[137], 221,
                    "incorrect value for rle_list[137], expected 221, is {}",
                    msg.rle_list[137]
                );
                assert_eq!(
                    msg.rle_list[138], 102,
                    "incorrect value for rle_list[138], expected 102, is {}",
                    msg.rle_list[138]
                );
                assert_eq!(
                    msg.rle_list[139], 83,
                    "incorrect value for rle_list[139], expected 83, is {}",
                    msg.rle_list[139]
                );
                assert_eq!(
                    msg.rle_list[140], 179,
                    "incorrect value for rle_list[140], expected 179, is {}",
                    msg.rle_list[140]
                );
                assert_eq!(
                    msg.rle_list[141], 43,
                    "incorrect value for rle_list[141], expected 43, is {}",
                    msg.rle_list[141]
                );
                assert_eq!(
                    msg.rle_list[142], 252,
                    "incorrect value for rle_list[142], expected 252, is {}",
                    msg.rle_list[142]
                );
                assert_eq!(
                    msg.rle_list[143], 81,
                    "incorrect value for rle_list[143], expected 81, is {}",
                    msg.rle_list[143]
                );
                assert_eq!(
                    msg.rle_list[144], 62,
                    "incorrect value for rle_list[144], expected 62, is {}",
                    msg.rle_list[144]
                );
                assert_eq!(
                    msg.rle_list[145], 126,
                    "incorrect value for rle_list[145], expected 126, is {}",
                    msg.rle_list[145]
                );
                assert_eq!(
                    msg.rle_list[146], 204,
                    "incorrect value for rle_list[146], expected 204, is {}",
                    msg.rle_list[146]
                );
                assert_eq!(
                    msg.rle_list[147], 195,
                    "incorrect value for rle_list[147], expected 195, is {}",
                    msg.rle_list[147]
                );
                assert_eq!(
                    msg.rle_list[148], 238,
                    "incorrect value for rle_list[148], expected 238, is {}",
                    msg.rle_list[148]
                );
                assert_eq!(
                    msg.rle_list[149], 18,
                    "incorrect value for rle_list[149], expected 18, is {}",
                    msg.rle_list[149]
                );
                assert_eq!(
                    msg.rle_list[150], 128,
                    "incorrect value for rle_list[150], expected 128, is {}",
                    msg.rle_list[150]
                );
                assert_eq!(
                    msg.rle_list[151], 193,
                    "incorrect value for rle_list[151], expected 193, is {}",
                    msg.rle_list[151]
                );
                assert_eq!(
                    msg.rle_list[152], 53,
                    "incorrect value for rle_list[152], expected 53, is {}",
                    msg.rle_list[152]
                );
                assert_eq!(
                    msg.rle_list[153], 94,
                    "incorrect value for rle_list[153], expected 94, is {}",
                    msg.rle_list[153]
                );
                assert_eq!(
                    msg.rle_list[154], 99,
                    "incorrect value for rle_list[154], expected 99, is {}",
                    msg.rle_list[154]
                );
                assert_eq!(
                    msg.rle_list[155], 63,
                    "incorrect value for rle_list[155], expected 63, is {}",
                    msg.rle_list[155]
                );
                assert_eq!(
                    msg.rle_list[156], 182,
                    "incorrect value for rle_list[156], expected 182, is {}",
                    msg.rle_list[156]
                );
                assert_eq!(
                    msg.rle_list[157], 2,
                    "incorrect value for rle_list[157], expected 2, is {}",
                    msg.rle_list[157]
                );
                assert_eq!(
                    msg.rle_list[158], 186,
                    "incorrect value for rle_list[158], expected 186, is {}",
                    msg.rle_list[158]
                );
                assert_eq!(
                    msg.rle_list[159], 220,
                    "incorrect value for rle_list[159], expected 220, is {}",
                    msg.rle_list[159]
                );
                assert_eq!(
                    msg.rle_list[160], 77,
                    "incorrect value for rle_list[160], expected 77, is {}",
                    msg.rle_list[160]
                );
                assert_eq!(
                    msg.rle_list[161], 186,
                    "incorrect value for rle_list[161], expected 186, is {}",
                    msg.rle_list[161]
                );
                assert_eq!(
                    msg.rle_list[162], 224,
                    "incorrect value for rle_list[162], expected 224, is {}",
                    msg.rle_list[162]
                );
                assert_eq!(
                    msg.rle_list[163], 220,
                    "incorrect value for rle_list[163], expected 220, is {}",
                    msg.rle_list[163]
                );
                assert_eq!(
                    msg.rle_list[164], 13,
                    "incorrect value for rle_list[164], expected 13, is {}",
                    msg.rle_list[164]
                );
                assert_eq!(
                    msg.rle_list[165], 212,
                    "incorrect value for rle_list[165], expected 212, is {}",
                    msg.rle_list[165]
                );
                assert_eq!(
                    msg.rle_list[166], 182,
                    "incorrect value for rle_list[166], expected 182, is {}",
                    msg.rle_list[166]
                );
                assert_eq!(
                    msg.rle_list[167], 88,
                    "incorrect value for rle_list[167], expected 88, is {}",
                    msg.rle_list[167]
                );
                assert_eq!(
                    msg.rle_list[168], 15,
                    "incorrect value for rle_list[168], expected 15, is {}",
                    msg.rle_list[168]
                );
                assert_eq!(
                    msg.rle_list[169], 151,
                    "incorrect value for rle_list[169], expected 151, is {}",
                    msg.rle_list[169]
                );
                assert_eq!(
                    msg.rle_list[170], 5,
                    "incorrect value for rle_list[170], expected 5, is {}",
                    msg.rle_list[170]
                );
                assert_eq!(
                    msg.rle_list[171], 93,
                    "incorrect value for rle_list[171], expected 93, is {}",
                    msg.rle_list[171]
                );
                assert_eq!(
                    msg.rle_list[172], 251,
                    "incorrect value for rle_list[172], expected 251, is {}",
                    msg.rle_list[172]
                );
                assert_eq!(
                    msg.rle_list[173], 164,
                    "incorrect value for rle_list[173], expected 164, is {}",
                    msg.rle_list[173]
                );
                assert_eq!(
                    msg.rle_list[174], 18,
                    "incorrect value for rle_list[174], expected 18, is {}",
                    msg.rle_list[174]
                );
                assert_eq!(
                    msg.rle_list[175], 228,
                    "incorrect value for rle_list[175], expected 228, is {}",
                    msg.rle_list[175]
                );
                assert_eq!(
                    msg.rle_list[176], 168,
                    "incorrect value for rle_list[176], expected 168, is {}",
                    msg.rle_list[176]
                );
                assert_eq!(
                    msg.rle_list[177], 226,
                    "incorrect value for rle_list[177], expected 226, is {}",
                    msg.rle_list[177]
                );
                assert_eq!(
                    msg.rle_list[178], 195,
                    "incorrect value for rle_list[178], expected 195, is {}",
                    msg.rle_list[178]
                );
                assert_eq!(
                    msg.rle_list[179], 44,
                    "incorrect value for rle_list[179], expected 44, is {}",
                    msg.rle_list[179]
                );
                assert_eq!(
                    msg.rle_list[180], 170,
                    "incorrect value for rle_list[180], expected 170, is {}",
                    msg.rle_list[180]
                );
                assert_eq!(
                    msg.rle_list[181], 145,
                    "incorrect value for rle_list[181], expected 145, is {}",
                    msg.rle_list[181]
                );
                assert_eq!(
                    msg.rle_list[182], 36,
                    "incorrect value for rle_list[182], expected 36, is {}",
                    msg.rle_list[182]
                );
                assert_eq!(
                    msg.rle_list[183], 58,
                    "incorrect value for rle_list[183], expected 58, is {}",
                    msg.rle_list[183]
                );
                assert_eq!(
                    msg.rle_list[184], 96,
                    "incorrect value for rle_list[184], expected 96, is {}",
                    msg.rle_list[184]
                );
                assert_eq!(
                    msg.rle_list[185], 107,
                    "incorrect value for rle_list[185], expected 107, is {}",
                    msg.rle_list[185]
                );
                assert_eq!(
                    msg.rle_list[186], 144,
                    "incorrect value for rle_list[186], expected 144, is {}",
                    msg.rle_list[186]
                );
                assert_eq!(
                    msg.rle_list[187], 11,
                    "incorrect value for rle_list[187], expected 11, is {}",
                    msg.rle_list[187]
                );
                assert_eq!(
                    msg.rle_list[188], 228,
                    "incorrect value for rle_list[188], expected 228, is {}",
                    msg.rle_list[188]
                );
                assert_eq!(
                    msg.rle_list[189], 12,
                    "incorrect value for rle_list[189], expected 12, is {}",
                    msg.rle_list[189]
                );
                assert_eq!(
                    msg.rle_list[190], 163,
                    "incorrect value for rle_list[190], expected 163, is {}",
                    msg.rle_list[190]
                );
                assert_eq!(
                    msg.rle_list[191], 238,
                    "incorrect value for rle_list[191], expected 238, is {}",
                    msg.rle_list[191]
                );
                assert_eq!(
                    msg.rle_list[192], 247,
                    "incorrect value for rle_list[192], expected 247, is {}",
                    msg.rle_list[192]
                );
                assert_eq!(
                    msg.rle_list[193], 159,
                    "incorrect value for rle_list[193], expected 159, is {}",
                    msg.rle_list[193]
                );
                assert_eq!(
                    msg.rle_list[194], 189,
                    "incorrect value for rle_list[194], expected 189, is {}",
                    msg.rle_list[194]
                );
                assert_eq!(
                    msg.rle_list[195], 1,
                    "incorrect value for rle_list[195], expected 1, is {}",
                    msg.rle_list[195]
                );
                assert_eq!(
                    msg.rle_list[196], 115,
                    "incorrect value for rle_list[196], expected 115, is {}",
                    msg.rle_list[196]
                );
                assert_eq!(
                    msg.rle_list[197], 65,
                    "incorrect value for rle_list[197], expected 65, is {}",
                    msg.rle_list[197]
                );
                assert_eq!(
                    msg.rle_list[198], 202,
                    "incorrect value for rle_list[198], expected 202, is {}",
                    msg.rle_list[198]
                );
                assert_eq!(
                    msg.rle_list[199], 121,
                    "incorrect value for rle_list[199], expected 121, is {}",
                    msg.rle_list[199]
                );
                assert_eq!(
                    msg.rle_list[200], 47,
                    "incorrect value for rle_list[200], expected 47, is {}",
                    msg.rle_list[200]
                );
                assert_eq!(
                    msg.rle_list[201], 193,
                    "incorrect value for rle_list[201], expected 193, is {}",
                    msg.rle_list[201]
                );
                assert_eq!(
                    msg.rle_list[202], 11,
                    "incorrect value for rle_list[202], expected 11, is {}",
                    msg.rle_list[202]
                );
                assert_eq!(
                    msg.rle_list[203], 96,
                    "incorrect value for rle_list[203], expected 96, is {}",
                    msg.rle_list[203]
                );
                assert_eq!(
                    msg.rle_list[204], 93,
                    "incorrect value for rle_list[204], expected 93, is {}",
                    msg.rle_list[204]
                );
                assert_eq!(
                    msg.rle_list[205], 72,
                    "incorrect value for rle_list[205], expected 72, is {}",
                    msg.rle_list[205]
                );
                assert_eq!(
                    msg.rle_list[206], 81,
                    "incorrect value for rle_list[206], expected 81, is {}",
                    msg.rle_list[206]
                );
                assert_eq!(
                    msg.rle_list[207], 207,
                    "incorrect value for rle_list[207], expected 207, is {}",
                    msg.rle_list[207]
                );
                assert_eq!(
                    msg.rle_list[208], 121,
                    "incorrect value for rle_list[208], expected 121, is {}",
                    msg.rle_list[208]
                );
                assert_eq!(
                    msg.rle_list[209], 19,
                    "incorrect value for rle_list[209], expected 19, is {}",
                    msg.rle_list[209]
                );
                assert_eq!(
                    msg.rle_list[210], 151,
                    "incorrect value for rle_list[210], expected 151, is {}",
                    msg.rle_list[210]
                );
                assert_eq!(
                    msg.rle_list[211], 136,
                    "incorrect value for rle_list[211], expected 136, is {}",
                    msg.rle_list[211]
                );
                assert_eq!(
                    msg.rle_list[212], 233,
                    "incorrect value for rle_list[212], expected 233, is {}",
                    msg.rle_list[212]
                );
                assert_eq!(
                    msg.rle_list[213], 51,
                    "incorrect value for rle_list[213], expected 51, is {}",
                    msg.rle_list[213]
                );
                assert_eq!(
                    msg.rle_list[214], 133,
                    "incorrect value for rle_list[214], expected 133, is {}",
                    msg.rle_list[214]
                );
                assert_eq!(
                    msg.rle_list[215], 195,
                    "incorrect value for rle_list[215], expected 195, is {}",
                    msg.rle_list[215]
                );
                assert_eq!(
                    msg.rle_list[216], 77,
                    "incorrect value for rle_list[216], expected 77, is {}",
                    msg.rle_list[216]
                );
                assert_eq!(
                    msg.rle_list[217], 44,
                    "incorrect value for rle_list[217], expected 44, is {}",
                    msg.rle_list[217]
                );
                assert_eq!(
                    msg.rle_list[218], 147,
                    "incorrect value for rle_list[218], expected 147, is {}",
                    msg.rle_list[218]
                );
                assert_eq!(
                    msg.rle_list[219], 206,
                    "incorrect value for rle_list[219], expected 206, is {}",
                    msg.rle_list[219]
                );
                assert_eq!(
                    msg.rle_list[220], 120,
                    "incorrect value for rle_list[220], expected 120, is {}",
                    msg.rle_list[220]
                );
                assert_eq!(
                    msg.rle_list[221], 252,
                    "incorrect value for rle_list[221], expected 252, is {}",
                    msg.rle_list[221]
                );
                assert_eq!(
                    msg.rle_list[222], 77,
                    "incorrect value for rle_list[222], expected 77, is {}",
                    msg.rle_list[222]
                );
                assert_eq!(
                    msg.rle_list[223], 212,
                    "incorrect value for rle_list[223], expected 212, is {}",
                    msg.rle_list[223]
                );
                assert_eq!(
                    msg.rle_list[224], 68,
                    "incorrect value for rle_list[224], expected 68, is {}",
                    msg.rle_list[224]
                );
                assert_eq!(
                    msg.rle_list[225], 60,
                    "incorrect value for rle_list[225], expected 60, is {}",
                    msg.rle_list[225]
                );
                assert_eq!(
                    msg.rle_list[226], 206,
                    "incorrect value for rle_list[226], expected 206, is {}",
                    msg.rle_list[226]
                );
                assert_eq!(
                    msg.rle_list[227], 106,
                    "incorrect value for rle_list[227], expected 106, is {}",
                    msg.rle_list[227]
                );
                assert_eq!(
                    msg.rle_list[228], 207,
                    "incorrect value for rle_list[228], expected 207, is {}",
                    msg.rle_list[228]
                );
                assert_eq!(
                    msg.rle_list[229], 243,
                    "incorrect value for rle_list[229], expected 243, is {}",
                    msg.rle_list[229]
                );
                assert_eq!(
                    msg.rle_list[230], 158,
                    "incorrect value for rle_list[230], expected 158, is {}",
                    msg.rle_list[230]
                );
                assert_eq!(
                    msg.rle_list[231], 94,
                    "incorrect value for rle_list[231], expected 94, is {}",
                    msg.rle_list[231]
                );
                assert_eq!(
                    msg.rle_list[232], 6,
                    "incorrect value for rle_list[232], expected 6, is {}",
                    msg.rle_list[232]
                );
                assert_eq!(
                    msg.rle_list[233], 3,
                    "incorrect value for rle_list[233], expected 3, is {}",
                    msg.rle_list[233]
                );
                assert_eq!(
                    msg.rle_list[234], 205,
                    "incorrect value for rle_list[234], expected 205, is {}",
                    msg.rle_list[234]
                );
                assert_eq!(
                    msg.rle_list[235], 92,
                    "incorrect value for rle_list[235], expected 92, is {}",
                    msg.rle_list[235]
                );
                assert_eq!(
                    msg.rle_list[236], 84,
                    "incorrect value for rle_list[236], expected 84, is {}",
                    msg.rle_list[236]
                );
                assert_eq!(
                    msg.rle_list[237], 2,
                    "incorrect value for rle_list[237], expected 2, is {}",
                    msg.rle_list[237]
                );
                assert_eq!(
                    msg.rle_list[238], 220,
                    "incorrect value for rle_list[238], expected 220, is {}",
                    msg.rle_list[238]
                );
                assert_eq!(
                    msg.rle_list[239], 50,
                    "incorrect value for rle_list[239], expected 50, is {}",
                    msg.rle_list[239]
                );
                assert_eq!(
                    msg.rle_list[240], 61,
                    "incorrect value for rle_list[240], expected 61, is {}",
                    msg.rle_list[240]
                );
                assert_eq!(
                    msg.rle_list[241], 38,
                    "incorrect value for rle_list[241], expected 38, is {}",
                    msg.rle_list[241]
                );
                assert_eq!(
                    msg.rle_list[242], 141,
                    "incorrect value for rle_list[242], expected 141, is {}",
                    msg.rle_list[242]
                );
                assert_eq!(
                    msg.rle_list[243], 117,
                    "incorrect value for rle_list[243], expected 117, is {}",
                    msg.rle_list[243]
                );
                assert_eq!(
                    msg.rle_list[244], 108,
                    "incorrect value for rle_list[244], expected 108, is {}",
                    msg.rle_list[244]
                );
                assert_eq!(
                    msg.rle_list[245], 101,
                    "incorrect value for rle_list[245], expected 101, is {}",
                    msg.rle_list[245]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGridDefinitionDepA"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_grid_definition_dep_a() {
    {
        let json_input = r#"{"crc":35660,"length":255,"msg_type":1525,"payload":"C1Sr5YSPLsw0XGgZzLYWYst70yYN/YGtq+v9GssDeH4qLCdXRZoNHLMgLyTDJ8aG64Y5ePOXIxHJ0311pI5l75Ce71o4R3hD3XIKvgTmpKtOuVousVLke97jkcPbGzjj9teQnh/W8f7IVo5ZDHkdfAkTmSwjfg7ZQXQai3pyWnxRALr2LmKz88bZJB7KDIc9KpbdZlOzK/xRPn7Mw+4SgME1XmM/tgK63E264NwN1LZYD5cFXfukEuSo4sMsqpEkOmBrkAvkDKPu95+9AXNBynkvwQtgXUhRz3kTl4jpM4XDTSyTznj8TdREPM5qz/OeXgYDzVxUAtwyPSaNdWxl","preamble":85,"sender":63413,"header":{"region_size_inverse":11,"area_width":43860,"lat_nw_corner_enc":34021,"lon_nw_corner_enc":11919,"num_msgs":204,"seq_num":52},"rle_list":[92,104,25,204,182,22,98,203,123,211,38,13,253,129,173,171,235,253,26,203,3,120,126,42,44,39,87,69,154,13,28,179,32,47,36,195,39,198,134,235,134,57,120,243,151,35,17,201,211,125,117,164,142,101,239,144,158,239,90,56,71,120,67,221,114,10,190,4,230,164,171,78,185,90,46,177,82,228,123,222,227,145,195,219,27,56,227,246,215,144,158,31,214,241,254,200,86,142,89,12,121,29,124,9,19,153,44,35,126,14,217,65,116,26,139,122,114,90,124,81,0,186,246,46,98,179,243,198,217,36,30,202,12,135,61,42,150,221,102,83,179,43,252,81,62,126,204,195,238,18,128,193,53,94,99,63,182,2,186,220,77,186,224,220,13,212,182,88,15,151,5,93,251,164,18,228,168,226,195,44,170,145,36,58,96,107,144,11,228,12,163,238,247,159,189,1,115,65,202,121,47,193,11,96,93,72,81,207,121,19,151,136,233,51,133,195,77,44,147,206,120,252,77,212,68,60,206,106,207,243,158,94,6,3,205,92,84,2,220,50,61,38,141,117,108,101]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrGridDefinitionDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5f5,
                    "Incorrect message type, expected 0x5f5, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf7b5,
                    "incorrect sender id, expected 0xf7b5, is {sender_id}"
                );
                assert_eq!(
                    msg.header.area_width, 43860,
                    "incorrect value for header.area_width, expected 43860, is {}",
                    msg.header.area_width
                );
                assert_eq!(
                    msg.header.lat_nw_corner_enc, 34021,
                    "incorrect value for header.lat_nw_corner_enc, expected 34021, is {}",
                    msg.header.lat_nw_corner_enc
                );
                assert_eq!(
                    msg.header.lon_nw_corner_enc, 11919,
                    "incorrect value for header.lon_nw_corner_enc, expected 11919, is {}",
                    msg.header.lon_nw_corner_enc
                );
                assert_eq!(
                    msg.header.num_msgs, 204,
                    "incorrect value for header.num_msgs, expected 204, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.region_size_inverse, 11,
                    "incorrect value for header.region_size_inverse, expected 11, is {}",
                    msg.header.region_size_inverse
                );
                assert_eq!(
                    msg.header.seq_num, 52,
                    "incorrect value for header.seq_num, expected 52, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.rle_list[0], 92,
                    "incorrect value for rle_list[0], expected 92, is {}",
                    msg.rle_list[0]
                );
                assert_eq!(
                    msg.rle_list[1], 104,
                    "incorrect value for rle_list[1], expected 104, is {}",
                    msg.rle_list[1]
                );
                assert_eq!(
                    msg.rle_list[2], 25,
                    "incorrect value for rle_list[2], expected 25, is {}",
                    msg.rle_list[2]
                );
                assert_eq!(
                    msg.rle_list[3], 204,
                    "incorrect value for rle_list[3], expected 204, is {}",
                    msg.rle_list[3]
                );
                assert_eq!(
                    msg.rle_list[4], 182,
                    "incorrect value for rle_list[4], expected 182, is {}",
                    msg.rle_list[4]
                );
                assert_eq!(
                    msg.rle_list[5], 22,
                    "incorrect value for rle_list[5], expected 22, is {}",
                    msg.rle_list[5]
                );
                assert_eq!(
                    msg.rle_list[6], 98,
                    "incorrect value for rle_list[6], expected 98, is {}",
                    msg.rle_list[6]
                );
                assert_eq!(
                    msg.rle_list[7], 203,
                    "incorrect value for rle_list[7], expected 203, is {}",
                    msg.rle_list[7]
                );
                assert_eq!(
                    msg.rle_list[8], 123,
                    "incorrect value for rle_list[8], expected 123, is {}",
                    msg.rle_list[8]
                );
                assert_eq!(
                    msg.rle_list[9], 211,
                    "incorrect value for rle_list[9], expected 211, is {}",
                    msg.rle_list[9]
                );
                assert_eq!(
                    msg.rle_list[10], 38,
                    "incorrect value for rle_list[10], expected 38, is {}",
                    msg.rle_list[10]
                );
                assert_eq!(
                    msg.rle_list[11], 13,
                    "incorrect value for rle_list[11], expected 13, is {}",
                    msg.rle_list[11]
                );
                assert_eq!(
                    msg.rle_list[12], 253,
                    "incorrect value for rle_list[12], expected 253, is {}",
                    msg.rle_list[12]
                );
                assert_eq!(
                    msg.rle_list[13], 129,
                    "incorrect value for rle_list[13], expected 129, is {}",
                    msg.rle_list[13]
                );
                assert_eq!(
                    msg.rle_list[14], 173,
                    "incorrect value for rle_list[14], expected 173, is {}",
                    msg.rle_list[14]
                );
                assert_eq!(
                    msg.rle_list[15], 171,
                    "incorrect value for rle_list[15], expected 171, is {}",
                    msg.rle_list[15]
                );
                assert_eq!(
                    msg.rle_list[16], 235,
                    "incorrect value for rle_list[16], expected 235, is {}",
                    msg.rle_list[16]
                );
                assert_eq!(
                    msg.rle_list[17], 253,
                    "incorrect value for rle_list[17], expected 253, is {}",
                    msg.rle_list[17]
                );
                assert_eq!(
                    msg.rle_list[18], 26,
                    "incorrect value for rle_list[18], expected 26, is {}",
                    msg.rle_list[18]
                );
                assert_eq!(
                    msg.rle_list[19], 203,
                    "incorrect value for rle_list[19], expected 203, is {}",
                    msg.rle_list[19]
                );
                assert_eq!(
                    msg.rle_list[20], 3,
                    "incorrect value for rle_list[20], expected 3, is {}",
                    msg.rle_list[20]
                );
                assert_eq!(
                    msg.rle_list[21], 120,
                    "incorrect value for rle_list[21], expected 120, is {}",
                    msg.rle_list[21]
                );
                assert_eq!(
                    msg.rle_list[22], 126,
                    "incorrect value for rle_list[22], expected 126, is {}",
                    msg.rle_list[22]
                );
                assert_eq!(
                    msg.rle_list[23], 42,
                    "incorrect value for rle_list[23], expected 42, is {}",
                    msg.rle_list[23]
                );
                assert_eq!(
                    msg.rle_list[24], 44,
                    "incorrect value for rle_list[24], expected 44, is {}",
                    msg.rle_list[24]
                );
                assert_eq!(
                    msg.rle_list[25], 39,
                    "incorrect value for rle_list[25], expected 39, is {}",
                    msg.rle_list[25]
                );
                assert_eq!(
                    msg.rle_list[26], 87,
                    "incorrect value for rle_list[26], expected 87, is {}",
                    msg.rle_list[26]
                );
                assert_eq!(
                    msg.rle_list[27], 69,
                    "incorrect value for rle_list[27], expected 69, is {}",
                    msg.rle_list[27]
                );
                assert_eq!(
                    msg.rle_list[28], 154,
                    "incorrect value for rle_list[28], expected 154, is {}",
                    msg.rle_list[28]
                );
                assert_eq!(
                    msg.rle_list[29], 13,
                    "incorrect value for rle_list[29], expected 13, is {}",
                    msg.rle_list[29]
                );
                assert_eq!(
                    msg.rle_list[30], 28,
                    "incorrect value for rle_list[30], expected 28, is {}",
                    msg.rle_list[30]
                );
                assert_eq!(
                    msg.rle_list[31], 179,
                    "incorrect value for rle_list[31], expected 179, is {}",
                    msg.rle_list[31]
                );
                assert_eq!(
                    msg.rle_list[32], 32,
                    "incorrect value for rle_list[32], expected 32, is {}",
                    msg.rle_list[32]
                );
                assert_eq!(
                    msg.rle_list[33], 47,
                    "incorrect value for rle_list[33], expected 47, is {}",
                    msg.rle_list[33]
                );
                assert_eq!(
                    msg.rle_list[34], 36,
                    "incorrect value for rle_list[34], expected 36, is {}",
                    msg.rle_list[34]
                );
                assert_eq!(
                    msg.rle_list[35], 195,
                    "incorrect value for rle_list[35], expected 195, is {}",
                    msg.rle_list[35]
                );
                assert_eq!(
                    msg.rle_list[36], 39,
                    "incorrect value for rle_list[36], expected 39, is {}",
                    msg.rle_list[36]
                );
                assert_eq!(
                    msg.rle_list[37], 198,
                    "incorrect value for rle_list[37], expected 198, is {}",
                    msg.rle_list[37]
                );
                assert_eq!(
                    msg.rle_list[38], 134,
                    "incorrect value for rle_list[38], expected 134, is {}",
                    msg.rle_list[38]
                );
                assert_eq!(
                    msg.rle_list[39], 235,
                    "incorrect value for rle_list[39], expected 235, is {}",
                    msg.rle_list[39]
                );
                assert_eq!(
                    msg.rle_list[40], 134,
                    "incorrect value for rle_list[40], expected 134, is {}",
                    msg.rle_list[40]
                );
                assert_eq!(
                    msg.rle_list[41], 57,
                    "incorrect value for rle_list[41], expected 57, is {}",
                    msg.rle_list[41]
                );
                assert_eq!(
                    msg.rle_list[42], 120,
                    "incorrect value for rle_list[42], expected 120, is {}",
                    msg.rle_list[42]
                );
                assert_eq!(
                    msg.rle_list[43], 243,
                    "incorrect value for rle_list[43], expected 243, is {}",
                    msg.rle_list[43]
                );
                assert_eq!(
                    msg.rle_list[44], 151,
                    "incorrect value for rle_list[44], expected 151, is {}",
                    msg.rle_list[44]
                );
                assert_eq!(
                    msg.rle_list[45], 35,
                    "incorrect value for rle_list[45], expected 35, is {}",
                    msg.rle_list[45]
                );
                assert_eq!(
                    msg.rle_list[46], 17,
                    "incorrect value for rle_list[46], expected 17, is {}",
                    msg.rle_list[46]
                );
                assert_eq!(
                    msg.rle_list[47], 201,
                    "incorrect value for rle_list[47], expected 201, is {}",
                    msg.rle_list[47]
                );
                assert_eq!(
                    msg.rle_list[48], 211,
                    "incorrect value for rle_list[48], expected 211, is {}",
                    msg.rle_list[48]
                );
                assert_eq!(
                    msg.rle_list[49], 125,
                    "incorrect value for rle_list[49], expected 125, is {}",
                    msg.rle_list[49]
                );
                assert_eq!(
                    msg.rle_list[50], 117,
                    "incorrect value for rle_list[50], expected 117, is {}",
                    msg.rle_list[50]
                );
                assert_eq!(
                    msg.rle_list[51], 164,
                    "incorrect value for rle_list[51], expected 164, is {}",
                    msg.rle_list[51]
                );
                assert_eq!(
                    msg.rle_list[52], 142,
                    "incorrect value for rle_list[52], expected 142, is {}",
                    msg.rle_list[52]
                );
                assert_eq!(
                    msg.rle_list[53], 101,
                    "incorrect value for rle_list[53], expected 101, is {}",
                    msg.rle_list[53]
                );
                assert_eq!(
                    msg.rle_list[54], 239,
                    "incorrect value for rle_list[54], expected 239, is {}",
                    msg.rle_list[54]
                );
                assert_eq!(
                    msg.rle_list[55], 144,
                    "incorrect value for rle_list[55], expected 144, is {}",
                    msg.rle_list[55]
                );
                assert_eq!(
                    msg.rle_list[56], 158,
                    "incorrect value for rle_list[56], expected 158, is {}",
                    msg.rle_list[56]
                );
                assert_eq!(
                    msg.rle_list[57], 239,
                    "incorrect value for rle_list[57], expected 239, is {}",
                    msg.rle_list[57]
                );
                assert_eq!(
                    msg.rle_list[58], 90,
                    "incorrect value for rle_list[58], expected 90, is {}",
                    msg.rle_list[58]
                );
                assert_eq!(
                    msg.rle_list[59], 56,
                    "incorrect value for rle_list[59], expected 56, is {}",
                    msg.rle_list[59]
                );
                assert_eq!(
                    msg.rle_list[60], 71,
                    "incorrect value for rle_list[60], expected 71, is {}",
                    msg.rle_list[60]
                );
                assert_eq!(
                    msg.rle_list[61], 120,
                    "incorrect value for rle_list[61], expected 120, is {}",
                    msg.rle_list[61]
                );
                assert_eq!(
                    msg.rle_list[62], 67,
                    "incorrect value for rle_list[62], expected 67, is {}",
                    msg.rle_list[62]
                );
                assert_eq!(
                    msg.rle_list[63], 221,
                    "incorrect value for rle_list[63], expected 221, is {}",
                    msg.rle_list[63]
                );
                assert_eq!(
                    msg.rle_list[64], 114,
                    "incorrect value for rle_list[64], expected 114, is {}",
                    msg.rle_list[64]
                );
                assert_eq!(
                    msg.rle_list[65], 10,
                    "incorrect value for rle_list[65], expected 10, is {}",
                    msg.rle_list[65]
                );
                assert_eq!(
                    msg.rle_list[66], 190,
                    "incorrect value for rle_list[66], expected 190, is {}",
                    msg.rle_list[66]
                );
                assert_eq!(
                    msg.rle_list[67], 4,
                    "incorrect value for rle_list[67], expected 4, is {}",
                    msg.rle_list[67]
                );
                assert_eq!(
                    msg.rle_list[68], 230,
                    "incorrect value for rle_list[68], expected 230, is {}",
                    msg.rle_list[68]
                );
                assert_eq!(
                    msg.rle_list[69], 164,
                    "incorrect value for rle_list[69], expected 164, is {}",
                    msg.rle_list[69]
                );
                assert_eq!(
                    msg.rle_list[70], 171,
                    "incorrect value for rle_list[70], expected 171, is {}",
                    msg.rle_list[70]
                );
                assert_eq!(
                    msg.rle_list[71], 78,
                    "incorrect value for rle_list[71], expected 78, is {}",
                    msg.rle_list[71]
                );
                assert_eq!(
                    msg.rle_list[72], 185,
                    "incorrect value for rle_list[72], expected 185, is {}",
                    msg.rle_list[72]
                );
                assert_eq!(
                    msg.rle_list[73], 90,
                    "incorrect value for rle_list[73], expected 90, is {}",
                    msg.rle_list[73]
                );
                assert_eq!(
                    msg.rle_list[74], 46,
                    "incorrect value for rle_list[74], expected 46, is {}",
                    msg.rle_list[74]
                );
                assert_eq!(
                    msg.rle_list[75], 177,
                    "incorrect value for rle_list[75], expected 177, is {}",
                    msg.rle_list[75]
                );
                assert_eq!(
                    msg.rle_list[76], 82,
                    "incorrect value for rle_list[76], expected 82, is {}",
                    msg.rle_list[76]
                );
                assert_eq!(
                    msg.rle_list[77], 228,
                    "incorrect value for rle_list[77], expected 228, is {}",
                    msg.rle_list[77]
                );
                assert_eq!(
                    msg.rle_list[78], 123,
                    "incorrect value for rle_list[78], expected 123, is {}",
                    msg.rle_list[78]
                );
                assert_eq!(
                    msg.rle_list[79], 222,
                    "incorrect value for rle_list[79], expected 222, is {}",
                    msg.rle_list[79]
                );
                assert_eq!(
                    msg.rle_list[80], 227,
                    "incorrect value for rle_list[80], expected 227, is {}",
                    msg.rle_list[80]
                );
                assert_eq!(
                    msg.rle_list[81], 145,
                    "incorrect value for rle_list[81], expected 145, is {}",
                    msg.rle_list[81]
                );
                assert_eq!(
                    msg.rle_list[82], 195,
                    "incorrect value for rle_list[82], expected 195, is {}",
                    msg.rle_list[82]
                );
                assert_eq!(
                    msg.rle_list[83], 219,
                    "incorrect value for rle_list[83], expected 219, is {}",
                    msg.rle_list[83]
                );
                assert_eq!(
                    msg.rle_list[84], 27,
                    "incorrect value for rle_list[84], expected 27, is {}",
                    msg.rle_list[84]
                );
                assert_eq!(
                    msg.rle_list[85], 56,
                    "incorrect value for rle_list[85], expected 56, is {}",
                    msg.rle_list[85]
                );
                assert_eq!(
                    msg.rle_list[86], 227,
                    "incorrect value for rle_list[86], expected 227, is {}",
                    msg.rle_list[86]
                );
                assert_eq!(
                    msg.rle_list[87], 246,
                    "incorrect value for rle_list[87], expected 246, is {}",
                    msg.rle_list[87]
                );
                assert_eq!(
                    msg.rle_list[88], 215,
                    "incorrect value for rle_list[88], expected 215, is {}",
                    msg.rle_list[88]
                );
                assert_eq!(
                    msg.rle_list[89], 144,
                    "incorrect value for rle_list[89], expected 144, is {}",
                    msg.rle_list[89]
                );
                assert_eq!(
                    msg.rle_list[90], 158,
                    "incorrect value for rle_list[90], expected 158, is {}",
                    msg.rle_list[90]
                );
                assert_eq!(
                    msg.rle_list[91], 31,
                    "incorrect value for rle_list[91], expected 31, is {}",
                    msg.rle_list[91]
                );
                assert_eq!(
                    msg.rle_list[92], 214,
                    "incorrect value for rle_list[92], expected 214, is {}",
                    msg.rle_list[92]
                );
                assert_eq!(
                    msg.rle_list[93], 241,
                    "incorrect value for rle_list[93], expected 241, is {}",
                    msg.rle_list[93]
                );
                assert_eq!(
                    msg.rle_list[94], 254,
                    "incorrect value for rle_list[94], expected 254, is {}",
                    msg.rle_list[94]
                );
                assert_eq!(
                    msg.rle_list[95], 200,
                    "incorrect value for rle_list[95], expected 200, is {}",
                    msg.rle_list[95]
                );
                assert_eq!(
                    msg.rle_list[96], 86,
                    "incorrect value for rle_list[96], expected 86, is {}",
                    msg.rle_list[96]
                );
                assert_eq!(
                    msg.rle_list[97], 142,
                    "incorrect value for rle_list[97], expected 142, is {}",
                    msg.rle_list[97]
                );
                assert_eq!(
                    msg.rle_list[98], 89,
                    "incorrect value for rle_list[98], expected 89, is {}",
                    msg.rle_list[98]
                );
                assert_eq!(
                    msg.rle_list[99], 12,
                    "incorrect value for rle_list[99], expected 12, is {}",
                    msg.rle_list[99]
                );
                assert_eq!(
                    msg.rle_list[100], 121,
                    "incorrect value for rle_list[100], expected 121, is {}",
                    msg.rle_list[100]
                );
                assert_eq!(
                    msg.rle_list[101], 29,
                    "incorrect value for rle_list[101], expected 29, is {}",
                    msg.rle_list[101]
                );
                assert_eq!(
                    msg.rle_list[102], 124,
                    "incorrect value for rle_list[102], expected 124, is {}",
                    msg.rle_list[102]
                );
                assert_eq!(
                    msg.rle_list[103], 9,
                    "incorrect value for rle_list[103], expected 9, is {}",
                    msg.rle_list[103]
                );
                assert_eq!(
                    msg.rle_list[104], 19,
                    "incorrect value for rle_list[104], expected 19, is {}",
                    msg.rle_list[104]
                );
                assert_eq!(
                    msg.rle_list[105], 153,
                    "incorrect value for rle_list[105], expected 153, is {}",
                    msg.rle_list[105]
                );
                assert_eq!(
                    msg.rle_list[106], 44,
                    "incorrect value for rle_list[106], expected 44, is {}",
                    msg.rle_list[106]
                );
                assert_eq!(
                    msg.rle_list[107], 35,
                    "incorrect value for rle_list[107], expected 35, is {}",
                    msg.rle_list[107]
                );
                assert_eq!(
                    msg.rle_list[108], 126,
                    "incorrect value for rle_list[108], expected 126, is {}",
                    msg.rle_list[108]
                );
                assert_eq!(
                    msg.rle_list[109], 14,
                    "incorrect value for rle_list[109], expected 14, is {}",
                    msg.rle_list[109]
                );
                assert_eq!(
                    msg.rle_list[110], 217,
                    "incorrect value for rle_list[110], expected 217, is {}",
                    msg.rle_list[110]
                );
                assert_eq!(
                    msg.rle_list[111], 65,
                    "incorrect value for rle_list[111], expected 65, is {}",
                    msg.rle_list[111]
                );
                assert_eq!(
                    msg.rle_list[112], 116,
                    "incorrect value for rle_list[112], expected 116, is {}",
                    msg.rle_list[112]
                );
                assert_eq!(
                    msg.rle_list[113], 26,
                    "incorrect value for rle_list[113], expected 26, is {}",
                    msg.rle_list[113]
                );
                assert_eq!(
                    msg.rle_list[114], 139,
                    "incorrect value for rle_list[114], expected 139, is {}",
                    msg.rle_list[114]
                );
                assert_eq!(
                    msg.rle_list[115], 122,
                    "incorrect value for rle_list[115], expected 122, is {}",
                    msg.rle_list[115]
                );
                assert_eq!(
                    msg.rle_list[116], 114,
                    "incorrect value for rle_list[116], expected 114, is {}",
                    msg.rle_list[116]
                );
                assert_eq!(
                    msg.rle_list[117], 90,
                    "incorrect value for rle_list[117], expected 90, is {}",
                    msg.rle_list[117]
                );
                assert_eq!(
                    msg.rle_list[118], 124,
                    "incorrect value for rle_list[118], expected 124, is {}",
                    msg.rle_list[118]
                );
                assert_eq!(
                    msg.rle_list[119], 81,
                    "incorrect value for rle_list[119], expected 81, is {}",
                    msg.rle_list[119]
                );
                assert_eq!(
                    msg.rle_list[120], 0,
                    "incorrect value for rle_list[120], expected 0, is {}",
                    msg.rle_list[120]
                );
                assert_eq!(
                    msg.rle_list[121], 186,
                    "incorrect value for rle_list[121], expected 186, is {}",
                    msg.rle_list[121]
                );
                assert_eq!(
                    msg.rle_list[122], 246,
                    "incorrect value for rle_list[122], expected 246, is {}",
                    msg.rle_list[122]
                );
                assert_eq!(
                    msg.rle_list[123], 46,
                    "incorrect value for rle_list[123], expected 46, is {}",
                    msg.rle_list[123]
                );
                assert_eq!(
                    msg.rle_list[124], 98,
                    "incorrect value for rle_list[124], expected 98, is {}",
                    msg.rle_list[124]
                );
                assert_eq!(
                    msg.rle_list[125], 179,
                    "incorrect value for rle_list[125], expected 179, is {}",
                    msg.rle_list[125]
                );
                assert_eq!(
                    msg.rle_list[126], 243,
                    "incorrect value for rle_list[126], expected 243, is {}",
                    msg.rle_list[126]
                );
                assert_eq!(
                    msg.rle_list[127], 198,
                    "incorrect value for rle_list[127], expected 198, is {}",
                    msg.rle_list[127]
                );
                assert_eq!(
                    msg.rle_list[128], 217,
                    "incorrect value for rle_list[128], expected 217, is {}",
                    msg.rle_list[128]
                );
                assert_eq!(
                    msg.rle_list[129], 36,
                    "incorrect value for rle_list[129], expected 36, is {}",
                    msg.rle_list[129]
                );
                assert_eq!(
                    msg.rle_list[130], 30,
                    "incorrect value for rle_list[130], expected 30, is {}",
                    msg.rle_list[130]
                );
                assert_eq!(
                    msg.rle_list[131], 202,
                    "incorrect value for rle_list[131], expected 202, is {}",
                    msg.rle_list[131]
                );
                assert_eq!(
                    msg.rle_list[132], 12,
                    "incorrect value for rle_list[132], expected 12, is {}",
                    msg.rle_list[132]
                );
                assert_eq!(
                    msg.rle_list[133], 135,
                    "incorrect value for rle_list[133], expected 135, is {}",
                    msg.rle_list[133]
                );
                assert_eq!(
                    msg.rle_list[134], 61,
                    "incorrect value for rle_list[134], expected 61, is {}",
                    msg.rle_list[134]
                );
                assert_eq!(
                    msg.rle_list[135], 42,
                    "incorrect value for rle_list[135], expected 42, is {}",
                    msg.rle_list[135]
                );
                assert_eq!(
                    msg.rle_list[136], 150,
                    "incorrect value for rle_list[136], expected 150, is {}",
                    msg.rle_list[136]
                );
                assert_eq!(
                    msg.rle_list[137], 221,
                    "incorrect value for rle_list[137], expected 221, is {}",
                    msg.rle_list[137]
                );
                assert_eq!(
                    msg.rle_list[138], 102,
                    "incorrect value for rle_list[138], expected 102, is {}",
                    msg.rle_list[138]
                );
                assert_eq!(
                    msg.rle_list[139], 83,
                    "incorrect value for rle_list[139], expected 83, is {}",
                    msg.rle_list[139]
                );
                assert_eq!(
                    msg.rle_list[140], 179,
                    "incorrect value for rle_list[140], expected 179, is {}",
                    msg.rle_list[140]
                );
                assert_eq!(
                    msg.rle_list[141], 43,
                    "incorrect value for rle_list[141], expected 43, is {}",
                    msg.rle_list[141]
                );
                assert_eq!(
                    msg.rle_list[142], 252,
                    "incorrect value for rle_list[142], expected 252, is {}",
                    msg.rle_list[142]
                );
                assert_eq!(
                    msg.rle_list[143], 81,
                    "incorrect value for rle_list[143], expected 81, is {}",
                    msg.rle_list[143]
                );
                assert_eq!(
                    msg.rle_list[144], 62,
                    "incorrect value for rle_list[144], expected 62, is {}",
                    msg.rle_list[144]
                );
                assert_eq!(
                    msg.rle_list[145], 126,
                    "incorrect value for rle_list[145], expected 126, is {}",
                    msg.rle_list[145]
                );
                assert_eq!(
                    msg.rle_list[146], 204,
                    "incorrect value for rle_list[146], expected 204, is {}",
                    msg.rle_list[146]
                );
                assert_eq!(
                    msg.rle_list[147], 195,
                    "incorrect value for rle_list[147], expected 195, is {}",
                    msg.rle_list[147]
                );
                assert_eq!(
                    msg.rle_list[148], 238,
                    "incorrect value for rle_list[148], expected 238, is {}",
                    msg.rle_list[148]
                );
                assert_eq!(
                    msg.rle_list[149], 18,
                    "incorrect value for rle_list[149], expected 18, is {}",
                    msg.rle_list[149]
                );
                assert_eq!(
                    msg.rle_list[150], 128,
                    "incorrect value for rle_list[150], expected 128, is {}",
                    msg.rle_list[150]
                );
                assert_eq!(
                    msg.rle_list[151], 193,
                    "incorrect value for rle_list[151], expected 193, is {}",
                    msg.rle_list[151]
                );
                assert_eq!(
                    msg.rle_list[152], 53,
                    "incorrect value for rle_list[152], expected 53, is {}",
                    msg.rle_list[152]
                );
                assert_eq!(
                    msg.rle_list[153], 94,
                    "incorrect value for rle_list[153], expected 94, is {}",
                    msg.rle_list[153]
                );
                assert_eq!(
                    msg.rle_list[154], 99,
                    "incorrect value for rle_list[154], expected 99, is {}",
                    msg.rle_list[154]
                );
                assert_eq!(
                    msg.rle_list[155], 63,
                    "incorrect value for rle_list[155], expected 63, is {}",
                    msg.rle_list[155]
                );
                assert_eq!(
                    msg.rle_list[156], 182,
                    "incorrect value for rle_list[156], expected 182, is {}",
                    msg.rle_list[156]
                );
                assert_eq!(
                    msg.rle_list[157], 2,
                    "incorrect value for rle_list[157], expected 2, is {}",
                    msg.rle_list[157]
                );
                assert_eq!(
                    msg.rle_list[158], 186,
                    "incorrect value for rle_list[158], expected 186, is {}",
                    msg.rle_list[158]
                );
                assert_eq!(
                    msg.rle_list[159], 220,
                    "incorrect value for rle_list[159], expected 220, is {}",
                    msg.rle_list[159]
                );
                assert_eq!(
                    msg.rle_list[160], 77,
                    "incorrect value for rle_list[160], expected 77, is {}",
                    msg.rle_list[160]
                );
                assert_eq!(
                    msg.rle_list[161], 186,
                    "incorrect value for rle_list[161], expected 186, is {}",
                    msg.rle_list[161]
                );
                assert_eq!(
                    msg.rle_list[162], 224,
                    "incorrect value for rle_list[162], expected 224, is {}",
                    msg.rle_list[162]
                );
                assert_eq!(
                    msg.rle_list[163], 220,
                    "incorrect value for rle_list[163], expected 220, is {}",
                    msg.rle_list[163]
                );
                assert_eq!(
                    msg.rle_list[164], 13,
                    "incorrect value for rle_list[164], expected 13, is {}",
                    msg.rle_list[164]
                );
                assert_eq!(
                    msg.rle_list[165], 212,
                    "incorrect value for rle_list[165], expected 212, is {}",
                    msg.rle_list[165]
                );
                assert_eq!(
                    msg.rle_list[166], 182,
                    "incorrect value for rle_list[166], expected 182, is {}",
                    msg.rle_list[166]
                );
                assert_eq!(
                    msg.rle_list[167], 88,
                    "incorrect value for rle_list[167], expected 88, is {}",
                    msg.rle_list[167]
                );
                assert_eq!(
                    msg.rle_list[168], 15,
                    "incorrect value for rle_list[168], expected 15, is {}",
                    msg.rle_list[168]
                );
                assert_eq!(
                    msg.rle_list[169], 151,
                    "incorrect value for rle_list[169], expected 151, is {}",
                    msg.rle_list[169]
                );
                assert_eq!(
                    msg.rle_list[170], 5,
                    "incorrect value for rle_list[170], expected 5, is {}",
                    msg.rle_list[170]
                );
                assert_eq!(
                    msg.rle_list[171], 93,
                    "incorrect value for rle_list[171], expected 93, is {}",
                    msg.rle_list[171]
                );
                assert_eq!(
                    msg.rle_list[172], 251,
                    "incorrect value for rle_list[172], expected 251, is {}",
                    msg.rle_list[172]
                );
                assert_eq!(
                    msg.rle_list[173], 164,
                    "incorrect value for rle_list[173], expected 164, is {}",
                    msg.rle_list[173]
                );
                assert_eq!(
                    msg.rle_list[174], 18,
                    "incorrect value for rle_list[174], expected 18, is {}",
                    msg.rle_list[174]
                );
                assert_eq!(
                    msg.rle_list[175], 228,
                    "incorrect value for rle_list[175], expected 228, is {}",
                    msg.rle_list[175]
                );
                assert_eq!(
                    msg.rle_list[176], 168,
                    "incorrect value for rle_list[176], expected 168, is {}",
                    msg.rle_list[176]
                );
                assert_eq!(
                    msg.rle_list[177], 226,
                    "incorrect value for rle_list[177], expected 226, is {}",
                    msg.rle_list[177]
                );
                assert_eq!(
                    msg.rle_list[178], 195,
                    "incorrect value for rle_list[178], expected 195, is {}",
                    msg.rle_list[178]
                );
                assert_eq!(
                    msg.rle_list[179], 44,
                    "incorrect value for rle_list[179], expected 44, is {}",
                    msg.rle_list[179]
                );
                assert_eq!(
                    msg.rle_list[180], 170,
                    "incorrect value for rle_list[180], expected 170, is {}",
                    msg.rle_list[180]
                );
                assert_eq!(
                    msg.rle_list[181], 145,
                    "incorrect value for rle_list[181], expected 145, is {}",
                    msg.rle_list[181]
                );
                assert_eq!(
                    msg.rle_list[182], 36,
                    "incorrect value for rle_list[182], expected 36, is {}",
                    msg.rle_list[182]
                );
                assert_eq!(
                    msg.rle_list[183], 58,
                    "incorrect value for rle_list[183], expected 58, is {}",
                    msg.rle_list[183]
                );
                assert_eq!(
                    msg.rle_list[184], 96,
                    "incorrect value for rle_list[184], expected 96, is {}",
                    msg.rle_list[184]
                );
                assert_eq!(
                    msg.rle_list[185], 107,
                    "incorrect value for rle_list[185], expected 107, is {}",
                    msg.rle_list[185]
                );
                assert_eq!(
                    msg.rle_list[186], 144,
                    "incorrect value for rle_list[186], expected 144, is {}",
                    msg.rle_list[186]
                );
                assert_eq!(
                    msg.rle_list[187], 11,
                    "incorrect value for rle_list[187], expected 11, is {}",
                    msg.rle_list[187]
                );
                assert_eq!(
                    msg.rle_list[188], 228,
                    "incorrect value for rle_list[188], expected 228, is {}",
                    msg.rle_list[188]
                );
                assert_eq!(
                    msg.rle_list[189], 12,
                    "incorrect value for rle_list[189], expected 12, is {}",
                    msg.rle_list[189]
                );
                assert_eq!(
                    msg.rle_list[190], 163,
                    "incorrect value for rle_list[190], expected 163, is {}",
                    msg.rle_list[190]
                );
                assert_eq!(
                    msg.rle_list[191], 238,
                    "incorrect value for rle_list[191], expected 238, is {}",
                    msg.rle_list[191]
                );
                assert_eq!(
                    msg.rle_list[192], 247,
                    "incorrect value for rle_list[192], expected 247, is {}",
                    msg.rle_list[192]
                );
                assert_eq!(
                    msg.rle_list[193], 159,
                    "incorrect value for rle_list[193], expected 159, is {}",
                    msg.rle_list[193]
                );
                assert_eq!(
                    msg.rle_list[194], 189,
                    "incorrect value for rle_list[194], expected 189, is {}",
                    msg.rle_list[194]
                );
                assert_eq!(
                    msg.rle_list[195], 1,
                    "incorrect value for rle_list[195], expected 1, is {}",
                    msg.rle_list[195]
                );
                assert_eq!(
                    msg.rle_list[196], 115,
                    "incorrect value for rle_list[196], expected 115, is {}",
                    msg.rle_list[196]
                );
                assert_eq!(
                    msg.rle_list[197], 65,
                    "incorrect value for rle_list[197], expected 65, is {}",
                    msg.rle_list[197]
                );
                assert_eq!(
                    msg.rle_list[198], 202,
                    "incorrect value for rle_list[198], expected 202, is {}",
                    msg.rle_list[198]
                );
                assert_eq!(
                    msg.rle_list[199], 121,
                    "incorrect value for rle_list[199], expected 121, is {}",
                    msg.rle_list[199]
                );
                assert_eq!(
                    msg.rle_list[200], 47,
                    "incorrect value for rle_list[200], expected 47, is {}",
                    msg.rle_list[200]
                );
                assert_eq!(
                    msg.rle_list[201], 193,
                    "incorrect value for rle_list[201], expected 193, is {}",
                    msg.rle_list[201]
                );
                assert_eq!(
                    msg.rle_list[202], 11,
                    "incorrect value for rle_list[202], expected 11, is {}",
                    msg.rle_list[202]
                );
                assert_eq!(
                    msg.rle_list[203], 96,
                    "incorrect value for rle_list[203], expected 96, is {}",
                    msg.rle_list[203]
                );
                assert_eq!(
                    msg.rle_list[204], 93,
                    "incorrect value for rle_list[204], expected 93, is {}",
                    msg.rle_list[204]
                );
                assert_eq!(
                    msg.rle_list[205], 72,
                    "incorrect value for rle_list[205], expected 72, is {}",
                    msg.rle_list[205]
                );
                assert_eq!(
                    msg.rle_list[206], 81,
                    "incorrect value for rle_list[206], expected 81, is {}",
                    msg.rle_list[206]
                );
                assert_eq!(
                    msg.rle_list[207], 207,
                    "incorrect value for rle_list[207], expected 207, is {}",
                    msg.rle_list[207]
                );
                assert_eq!(
                    msg.rle_list[208], 121,
                    "incorrect value for rle_list[208], expected 121, is {}",
                    msg.rle_list[208]
                );
                assert_eq!(
                    msg.rle_list[209], 19,
                    "incorrect value for rle_list[209], expected 19, is {}",
                    msg.rle_list[209]
                );
                assert_eq!(
                    msg.rle_list[210], 151,
                    "incorrect value for rle_list[210], expected 151, is {}",
                    msg.rle_list[210]
                );
                assert_eq!(
                    msg.rle_list[211], 136,
                    "incorrect value for rle_list[211], expected 136, is {}",
                    msg.rle_list[211]
                );
                assert_eq!(
                    msg.rle_list[212], 233,
                    "incorrect value for rle_list[212], expected 233, is {}",
                    msg.rle_list[212]
                );
                assert_eq!(
                    msg.rle_list[213], 51,
                    "incorrect value for rle_list[213], expected 51, is {}",
                    msg.rle_list[213]
                );
                assert_eq!(
                    msg.rle_list[214], 133,
                    "incorrect value for rle_list[214], expected 133, is {}",
                    msg.rle_list[214]
                );
                assert_eq!(
                    msg.rle_list[215], 195,
                    "incorrect value for rle_list[215], expected 195, is {}",
                    msg.rle_list[215]
                );
                assert_eq!(
                    msg.rle_list[216], 77,
                    "incorrect value for rle_list[216], expected 77, is {}",
                    msg.rle_list[216]
                );
                assert_eq!(
                    msg.rle_list[217], 44,
                    "incorrect value for rle_list[217], expected 44, is {}",
                    msg.rle_list[217]
                );
                assert_eq!(
                    msg.rle_list[218], 147,
                    "incorrect value for rle_list[218], expected 147, is {}",
                    msg.rle_list[218]
                );
                assert_eq!(
                    msg.rle_list[219], 206,
                    "incorrect value for rle_list[219], expected 206, is {}",
                    msg.rle_list[219]
                );
                assert_eq!(
                    msg.rle_list[220], 120,
                    "incorrect value for rle_list[220], expected 120, is {}",
                    msg.rle_list[220]
                );
                assert_eq!(
                    msg.rle_list[221], 252,
                    "incorrect value for rle_list[221], expected 252, is {}",
                    msg.rle_list[221]
                );
                assert_eq!(
                    msg.rle_list[222], 77,
                    "incorrect value for rle_list[222], expected 77, is {}",
                    msg.rle_list[222]
                );
                assert_eq!(
                    msg.rle_list[223], 212,
                    "incorrect value for rle_list[223], expected 212, is {}",
                    msg.rle_list[223]
                );
                assert_eq!(
                    msg.rle_list[224], 68,
                    "incorrect value for rle_list[224], expected 68, is {}",
                    msg.rle_list[224]
                );
                assert_eq!(
                    msg.rle_list[225], 60,
                    "incorrect value for rle_list[225], expected 60, is {}",
                    msg.rle_list[225]
                );
                assert_eq!(
                    msg.rle_list[226], 206,
                    "incorrect value for rle_list[226], expected 206, is {}",
                    msg.rle_list[226]
                );
                assert_eq!(
                    msg.rle_list[227], 106,
                    "incorrect value for rle_list[227], expected 106, is {}",
                    msg.rle_list[227]
                );
                assert_eq!(
                    msg.rle_list[228], 207,
                    "incorrect value for rle_list[228], expected 207, is {}",
                    msg.rle_list[228]
                );
                assert_eq!(
                    msg.rle_list[229], 243,
                    "incorrect value for rle_list[229], expected 243, is {}",
                    msg.rle_list[229]
                );
                assert_eq!(
                    msg.rle_list[230], 158,
                    "incorrect value for rle_list[230], expected 158, is {}",
                    msg.rle_list[230]
                );
                assert_eq!(
                    msg.rle_list[231], 94,
                    "incorrect value for rle_list[231], expected 94, is {}",
                    msg.rle_list[231]
                );
                assert_eq!(
                    msg.rle_list[232], 6,
                    "incorrect value for rle_list[232], expected 6, is {}",
                    msg.rle_list[232]
                );
                assert_eq!(
                    msg.rle_list[233], 3,
                    "incorrect value for rle_list[233], expected 3, is {}",
                    msg.rle_list[233]
                );
                assert_eq!(
                    msg.rle_list[234], 205,
                    "incorrect value for rle_list[234], expected 205, is {}",
                    msg.rle_list[234]
                );
                assert_eq!(
                    msg.rle_list[235], 92,
                    "incorrect value for rle_list[235], expected 92, is {}",
                    msg.rle_list[235]
                );
                assert_eq!(
                    msg.rle_list[236], 84,
                    "incorrect value for rle_list[236], expected 84, is {}",
                    msg.rle_list[236]
                );
                assert_eq!(
                    msg.rle_list[237], 2,
                    "incorrect value for rle_list[237], expected 2, is {}",
                    msg.rle_list[237]
                );
                assert_eq!(
                    msg.rle_list[238], 220,
                    "incorrect value for rle_list[238], expected 220, is {}",
                    msg.rle_list[238]
                );
                assert_eq!(
                    msg.rle_list[239], 50,
                    "incorrect value for rle_list[239], expected 50, is {}",
                    msg.rle_list[239]
                );
                assert_eq!(
                    msg.rle_list[240], 61,
                    "incorrect value for rle_list[240], expected 61, is {}",
                    msg.rle_list[240]
                );
                assert_eq!(
                    msg.rle_list[241], 38,
                    "incorrect value for rle_list[241], expected 38, is {}",
                    msg.rle_list[241]
                );
                assert_eq!(
                    msg.rle_list[242], 141,
                    "incorrect value for rle_list[242], expected 141, is {}",
                    msg.rle_list[242]
                );
                assert_eq!(
                    msg.rle_list[243], 117,
                    "incorrect value for rle_list[243], expected 117, is {}",
                    msg.rle_list[243]
                );
                assert_eq!(
                    msg.rle_list[244], 108,
                    "incorrect value for rle_list[244], expected 108, is {}",
                    msg.rle_list[244]
                );
                assert_eq!(
                    msg.rle_list[245], 101,
                    "incorrect value for rle_list[245], expected 101, is {}",
                    msg.rle_list[245]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGridDefinitionDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_grid_definition_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_grid_definition_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 245, 5, 181, 247, 255, 11, 84, 171, 229, 132, 143, 46, 204, 52, 92, 104, 25, 204,
            182, 22, 98, 203, 123, 211, 38, 13, 253, 129, 173, 171, 235, 253, 26, 203, 3, 120, 126,
            42, 44, 39, 87, 69, 154, 13, 28, 179, 32, 47, 36, 195, 39, 198, 134, 235, 134, 57, 120,
            243, 151, 35, 17, 201, 211, 125, 117, 164, 142, 101, 239, 144, 158, 239, 90, 56, 71,
            120, 67, 221, 114, 10, 190, 4, 230, 164, 171, 78, 185, 90, 46, 177, 82, 228, 123, 222,
            227, 145, 195, 219, 27, 56, 227, 246, 215, 144, 158, 31, 214, 241, 254, 200, 86, 142,
            89, 12, 121, 29, 124, 9, 19, 153, 44, 35, 126, 14, 217, 65, 116, 26, 139, 122, 114, 90,
            124, 81, 0, 186, 246, 46, 98, 179, 243, 198, 217, 36, 30, 202, 12, 135, 61, 42, 150,
            221, 102, 83, 179, 43, 252, 81, 62, 126, 204, 195, 238, 18, 128, 193, 53, 94, 99, 63,
            182, 2, 186, 220, 77, 186, 224, 220, 13, 212, 182, 88, 15, 151, 5, 93, 251, 164, 18,
            228, 168, 226, 195, 44, 170, 145, 36, 58, 96, 107, 144, 11, 228, 12, 163, 238, 247,
            159, 189, 1, 115, 65, 202, 121, 47, 193, 11, 96, 93, 72, 81, 207, 121, 19, 151, 136,
            233, 51, 133, 195, 77, 44, 147, 206, 120, 252, 77, 212, 68, 60, 206, 106, 207, 243,
            158, 94, 6, 3, 205, 92, 84, 2, 220, 50, 61, 38, 141, 117, 108, 101, 76, 139,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrGridDefinitionDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrGridDefinitionDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5f5,
                    "Incorrect message type, expected 0x5f5, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf7b5,
                    "incorrect sender id, expected 0xf7b5, is {sender_id}"
                );
                assert_eq!(
                    msg.header.area_width, 43860,
                    "incorrect value for header.area_width, expected 43860, is {}",
                    msg.header.area_width
                );
                assert_eq!(
                    msg.header.lat_nw_corner_enc, 34021,
                    "incorrect value for header.lat_nw_corner_enc, expected 34021, is {}",
                    msg.header.lat_nw_corner_enc
                );
                assert_eq!(
                    msg.header.lon_nw_corner_enc, 11919,
                    "incorrect value for header.lon_nw_corner_enc, expected 11919, is {}",
                    msg.header.lon_nw_corner_enc
                );
                assert_eq!(
                    msg.header.num_msgs, 204,
                    "incorrect value for header.num_msgs, expected 204, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.region_size_inverse, 11,
                    "incorrect value for header.region_size_inverse, expected 11, is {}",
                    msg.header.region_size_inverse
                );
                assert_eq!(
                    msg.header.seq_num, 52,
                    "incorrect value for header.seq_num, expected 52, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.rle_list[0], 92,
                    "incorrect value for rle_list[0], expected 92, is {}",
                    msg.rle_list[0]
                );
                assert_eq!(
                    msg.rle_list[1], 104,
                    "incorrect value for rle_list[1], expected 104, is {}",
                    msg.rle_list[1]
                );
                assert_eq!(
                    msg.rle_list[2], 25,
                    "incorrect value for rle_list[2], expected 25, is {}",
                    msg.rle_list[2]
                );
                assert_eq!(
                    msg.rle_list[3], 204,
                    "incorrect value for rle_list[3], expected 204, is {}",
                    msg.rle_list[3]
                );
                assert_eq!(
                    msg.rle_list[4], 182,
                    "incorrect value for rle_list[4], expected 182, is {}",
                    msg.rle_list[4]
                );
                assert_eq!(
                    msg.rle_list[5], 22,
                    "incorrect value for rle_list[5], expected 22, is {}",
                    msg.rle_list[5]
                );
                assert_eq!(
                    msg.rle_list[6], 98,
                    "incorrect value for rle_list[6], expected 98, is {}",
                    msg.rle_list[6]
                );
                assert_eq!(
                    msg.rle_list[7], 203,
                    "incorrect value for rle_list[7], expected 203, is {}",
                    msg.rle_list[7]
                );
                assert_eq!(
                    msg.rle_list[8], 123,
                    "incorrect value for rle_list[8], expected 123, is {}",
                    msg.rle_list[8]
                );
                assert_eq!(
                    msg.rle_list[9], 211,
                    "incorrect value for rle_list[9], expected 211, is {}",
                    msg.rle_list[9]
                );
                assert_eq!(
                    msg.rle_list[10], 38,
                    "incorrect value for rle_list[10], expected 38, is {}",
                    msg.rle_list[10]
                );
                assert_eq!(
                    msg.rle_list[11], 13,
                    "incorrect value for rle_list[11], expected 13, is {}",
                    msg.rle_list[11]
                );
                assert_eq!(
                    msg.rle_list[12], 253,
                    "incorrect value for rle_list[12], expected 253, is {}",
                    msg.rle_list[12]
                );
                assert_eq!(
                    msg.rle_list[13], 129,
                    "incorrect value for rle_list[13], expected 129, is {}",
                    msg.rle_list[13]
                );
                assert_eq!(
                    msg.rle_list[14], 173,
                    "incorrect value for rle_list[14], expected 173, is {}",
                    msg.rle_list[14]
                );
                assert_eq!(
                    msg.rle_list[15], 171,
                    "incorrect value for rle_list[15], expected 171, is {}",
                    msg.rle_list[15]
                );
                assert_eq!(
                    msg.rle_list[16], 235,
                    "incorrect value for rle_list[16], expected 235, is {}",
                    msg.rle_list[16]
                );
                assert_eq!(
                    msg.rle_list[17], 253,
                    "incorrect value for rle_list[17], expected 253, is {}",
                    msg.rle_list[17]
                );
                assert_eq!(
                    msg.rle_list[18], 26,
                    "incorrect value for rle_list[18], expected 26, is {}",
                    msg.rle_list[18]
                );
                assert_eq!(
                    msg.rle_list[19], 203,
                    "incorrect value for rle_list[19], expected 203, is {}",
                    msg.rle_list[19]
                );
                assert_eq!(
                    msg.rle_list[20], 3,
                    "incorrect value for rle_list[20], expected 3, is {}",
                    msg.rle_list[20]
                );
                assert_eq!(
                    msg.rle_list[21], 120,
                    "incorrect value for rle_list[21], expected 120, is {}",
                    msg.rle_list[21]
                );
                assert_eq!(
                    msg.rle_list[22], 126,
                    "incorrect value for rle_list[22], expected 126, is {}",
                    msg.rle_list[22]
                );
                assert_eq!(
                    msg.rle_list[23], 42,
                    "incorrect value for rle_list[23], expected 42, is {}",
                    msg.rle_list[23]
                );
                assert_eq!(
                    msg.rle_list[24], 44,
                    "incorrect value for rle_list[24], expected 44, is {}",
                    msg.rle_list[24]
                );
                assert_eq!(
                    msg.rle_list[25], 39,
                    "incorrect value for rle_list[25], expected 39, is {}",
                    msg.rle_list[25]
                );
                assert_eq!(
                    msg.rle_list[26], 87,
                    "incorrect value for rle_list[26], expected 87, is {}",
                    msg.rle_list[26]
                );
                assert_eq!(
                    msg.rle_list[27], 69,
                    "incorrect value for rle_list[27], expected 69, is {}",
                    msg.rle_list[27]
                );
                assert_eq!(
                    msg.rle_list[28], 154,
                    "incorrect value for rle_list[28], expected 154, is {}",
                    msg.rle_list[28]
                );
                assert_eq!(
                    msg.rle_list[29], 13,
                    "incorrect value for rle_list[29], expected 13, is {}",
                    msg.rle_list[29]
                );
                assert_eq!(
                    msg.rle_list[30], 28,
                    "incorrect value for rle_list[30], expected 28, is {}",
                    msg.rle_list[30]
                );
                assert_eq!(
                    msg.rle_list[31], 179,
                    "incorrect value for rle_list[31], expected 179, is {}",
                    msg.rle_list[31]
                );
                assert_eq!(
                    msg.rle_list[32], 32,
                    "incorrect value for rle_list[32], expected 32, is {}",
                    msg.rle_list[32]
                );
                assert_eq!(
                    msg.rle_list[33], 47,
                    "incorrect value for rle_list[33], expected 47, is {}",
                    msg.rle_list[33]
                );
                assert_eq!(
                    msg.rle_list[34], 36,
                    "incorrect value for rle_list[34], expected 36, is {}",
                    msg.rle_list[34]
                );
                assert_eq!(
                    msg.rle_list[35], 195,
                    "incorrect value for rle_list[35], expected 195, is {}",
                    msg.rle_list[35]
                );
                assert_eq!(
                    msg.rle_list[36], 39,
                    "incorrect value for rle_list[36], expected 39, is {}",
                    msg.rle_list[36]
                );
                assert_eq!(
                    msg.rle_list[37], 198,
                    "incorrect value for rle_list[37], expected 198, is {}",
                    msg.rle_list[37]
                );
                assert_eq!(
                    msg.rle_list[38], 134,
                    "incorrect value for rle_list[38], expected 134, is {}",
                    msg.rle_list[38]
                );
                assert_eq!(
                    msg.rle_list[39], 235,
                    "incorrect value for rle_list[39], expected 235, is {}",
                    msg.rle_list[39]
                );
                assert_eq!(
                    msg.rle_list[40], 134,
                    "incorrect value for rle_list[40], expected 134, is {}",
                    msg.rle_list[40]
                );
                assert_eq!(
                    msg.rle_list[41], 57,
                    "incorrect value for rle_list[41], expected 57, is {}",
                    msg.rle_list[41]
                );
                assert_eq!(
                    msg.rle_list[42], 120,
                    "incorrect value for rle_list[42], expected 120, is {}",
                    msg.rle_list[42]
                );
                assert_eq!(
                    msg.rle_list[43], 243,
                    "incorrect value for rle_list[43], expected 243, is {}",
                    msg.rle_list[43]
                );
                assert_eq!(
                    msg.rle_list[44], 151,
                    "incorrect value for rle_list[44], expected 151, is {}",
                    msg.rle_list[44]
                );
                assert_eq!(
                    msg.rle_list[45], 35,
                    "incorrect value for rle_list[45], expected 35, is {}",
                    msg.rle_list[45]
                );
                assert_eq!(
                    msg.rle_list[46], 17,
                    "incorrect value for rle_list[46], expected 17, is {}",
                    msg.rle_list[46]
                );
                assert_eq!(
                    msg.rle_list[47], 201,
                    "incorrect value for rle_list[47], expected 201, is {}",
                    msg.rle_list[47]
                );
                assert_eq!(
                    msg.rle_list[48], 211,
                    "incorrect value for rle_list[48], expected 211, is {}",
                    msg.rle_list[48]
                );
                assert_eq!(
                    msg.rle_list[49], 125,
                    "incorrect value for rle_list[49], expected 125, is {}",
                    msg.rle_list[49]
                );
                assert_eq!(
                    msg.rle_list[50], 117,
                    "incorrect value for rle_list[50], expected 117, is {}",
                    msg.rle_list[50]
                );
                assert_eq!(
                    msg.rle_list[51], 164,
                    "incorrect value for rle_list[51], expected 164, is {}",
                    msg.rle_list[51]
                );
                assert_eq!(
                    msg.rle_list[52], 142,
                    "incorrect value for rle_list[52], expected 142, is {}",
                    msg.rle_list[52]
                );
                assert_eq!(
                    msg.rle_list[53], 101,
                    "incorrect value for rle_list[53], expected 101, is {}",
                    msg.rle_list[53]
                );
                assert_eq!(
                    msg.rle_list[54], 239,
                    "incorrect value for rle_list[54], expected 239, is {}",
                    msg.rle_list[54]
                );
                assert_eq!(
                    msg.rle_list[55], 144,
                    "incorrect value for rle_list[55], expected 144, is {}",
                    msg.rle_list[55]
                );
                assert_eq!(
                    msg.rle_list[56], 158,
                    "incorrect value for rle_list[56], expected 158, is {}",
                    msg.rle_list[56]
                );
                assert_eq!(
                    msg.rle_list[57], 239,
                    "incorrect value for rle_list[57], expected 239, is {}",
                    msg.rle_list[57]
                );
                assert_eq!(
                    msg.rle_list[58], 90,
                    "incorrect value for rle_list[58], expected 90, is {}",
                    msg.rle_list[58]
                );
                assert_eq!(
                    msg.rle_list[59], 56,
                    "incorrect value for rle_list[59], expected 56, is {}",
                    msg.rle_list[59]
                );
                assert_eq!(
                    msg.rle_list[60], 71,
                    "incorrect value for rle_list[60], expected 71, is {}",
                    msg.rle_list[60]
                );
                assert_eq!(
                    msg.rle_list[61], 120,
                    "incorrect value for rle_list[61], expected 120, is {}",
                    msg.rle_list[61]
                );
                assert_eq!(
                    msg.rle_list[62], 67,
                    "incorrect value for rle_list[62], expected 67, is {}",
                    msg.rle_list[62]
                );
                assert_eq!(
                    msg.rle_list[63], 221,
                    "incorrect value for rle_list[63], expected 221, is {}",
                    msg.rle_list[63]
                );
                assert_eq!(
                    msg.rle_list[64], 114,
                    "incorrect value for rle_list[64], expected 114, is {}",
                    msg.rle_list[64]
                );
                assert_eq!(
                    msg.rle_list[65], 10,
                    "incorrect value for rle_list[65], expected 10, is {}",
                    msg.rle_list[65]
                );
                assert_eq!(
                    msg.rle_list[66], 190,
                    "incorrect value for rle_list[66], expected 190, is {}",
                    msg.rle_list[66]
                );
                assert_eq!(
                    msg.rle_list[67], 4,
                    "incorrect value for rle_list[67], expected 4, is {}",
                    msg.rle_list[67]
                );
                assert_eq!(
                    msg.rle_list[68], 230,
                    "incorrect value for rle_list[68], expected 230, is {}",
                    msg.rle_list[68]
                );
                assert_eq!(
                    msg.rle_list[69], 164,
                    "incorrect value for rle_list[69], expected 164, is {}",
                    msg.rle_list[69]
                );
                assert_eq!(
                    msg.rle_list[70], 171,
                    "incorrect value for rle_list[70], expected 171, is {}",
                    msg.rle_list[70]
                );
                assert_eq!(
                    msg.rle_list[71], 78,
                    "incorrect value for rle_list[71], expected 78, is {}",
                    msg.rle_list[71]
                );
                assert_eq!(
                    msg.rle_list[72], 185,
                    "incorrect value for rle_list[72], expected 185, is {}",
                    msg.rle_list[72]
                );
                assert_eq!(
                    msg.rle_list[73], 90,
                    "incorrect value for rle_list[73], expected 90, is {}",
                    msg.rle_list[73]
                );
                assert_eq!(
                    msg.rle_list[74], 46,
                    "incorrect value for rle_list[74], expected 46, is {}",
                    msg.rle_list[74]
                );
                assert_eq!(
                    msg.rle_list[75], 177,
                    "incorrect value for rle_list[75], expected 177, is {}",
                    msg.rle_list[75]
                );
                assert_eq!(
                    msg.rle_list[76], 82,
                    "incorrect value for rle_list[76], expected 82, is {}",
                    msg.rle_list[76]
                );
                assert_eq!(
                    msg.rle_list[77], 228,
                    "incorrect value for rle_list[77], expected 228, is {}",
                    msg.rle_list[77]
                );
                assert_eq!(
                    msg.rle_list[78], 123,
                    "incorrect value for rle_list[78], expected 123, is {}",
                    msg.rle_list[78]
                );
                assert_eq!(
                    msg.rle_list[79], 222,
                    "incorrect value for rle_list[79], expected 222, is {}",
                    msg.rle_list[79]
                );
                assert_eq!(
                    msg.rle_list[80], 227,
                    "incorrect value for rle_list[80], expected 227, is {}",
                    msg.rle_list[80]
                );
                assert_eq!(
                    msg.rle_list[81], 145,
                    "incorrect value for rle_list[81], expected 145, is {}",
                    msg.rle_list[81]
                );
                assert_eq!(
                    msg.rle_list[82], 195,
                    "incorrect value for rle_list[82], expected 195, is {}",
                    msg.rle_list[82]
                );
                assert_eq!(
                    msg.rle_list[83], 219,
                    "incorrect value for rle_list[83], expected 219, is {}",
                    msg.rle_list[83]
                );
                assert_eq!(
                    msg.rle_list[84], 27,
                    "incorrect value for rle_list[84], expected 27, is {}",
                    msg.rle_list[84]
                );
                assert_eq!(
                    msg.rle_list[85], 56,
                    "incorrect value for rle_list[85], expected 56, is {}",
                    msg.rle_list[85]
                );
                assert_eq!(
                    msg.rle_list[86], 227,
                    "incorrect value for rle_list[86], expected 227, is {}",
                    msg.rle_list[86]
                );
                assert_eq!(
                    msg.rle_list[87], 246,
                    "incorrect value for rle_list[87], expected 246, is {}",
                    msg.rle_list[87]
                );
                assert_eq!(
                    msg.rle_list[88], 215,
                    "incorrect value for rle_list[88], expected 215, is {}",
                    msg.rle_list[88]
                );
                assert_eq!(
                    msg.rle_list[89], 144,
                    "incorrect value for rle_list[89], expected 144, is {}",
                    msg.rle_list[89]
                );
                assert_eq!(
                    msg.rle_list[90], 158,
                    "incorrect value for rle_list[90], expected 158, is {}",
                    msg.rle_list[90]
                );
                assert_eq!(
                    msg.rle_list[91], 31,
                    "incorrect value for rle_list[91], expected 31, is {}",
                    msg.rle_list[91]
                );
                assert_eq!(
                    msg.rle_list[92], 214,
                    "incorrect value for rle_list[92], expected 214, is {}",
                    msg.rle_list[92]
                );
                assert_eq!(
                    msg.rle_list[93], 241,
                    "incorrect value for rle_list[93], expected 241, is {}",
                    msg.rle_list[93]
                );
                assert_eq!(
                    msg.rle_list[94], 254,
                    "incorrect value for rle_list[94], expected 254, is {}",
                    msg.rle_list[94]
                );
                assert_eq!(
                    msg.rle_list[95], 200,
                    "incorrect value for rle_list[95], expected 200, is {}",
                    msg.rle_list[95]
                );
                assert_eq!(
                    msg.rle_list[96], 86,
                    "incorrect value for rle_list[96], expected 86, is {}",
                    msg.rle_list[96]
                );
                assert_eq!(
                    msg.rle_list[97], 142,
                    "incorrect value for rle_list[97], expected 142, is {}",
                    msg.rle_list[97]
                );
                assert_eq!(
                    msg.rle_list[98], 89,
                    "incorrect value for rle_list[98], expected 89, is {}",
                    msg.rle_list[98]
                );
                assert_eq!(
                    msg.rle_list[99], 12,
                    "incorrect value for rle_list[99], expected 12, is {}",
                    msg.rle_list[99]
                );
                assert_eq!(
                    msg.rle_list[100], 121,
                    "incorrect value for rle_list[100], expected 121, is {}",
                    msg.rle_list[100]
                );
                assert_eq!(
                    msg.rle_list[101], 29,
                    "incorrect value for rle_list[101], expected 29, is {}",
                    msg.rle_list[101]
                );
                assert_eq!(
                    msg.rle_list[102], 124,
                    "incorrect value for rle_list[102], expected 124, is {}",
                    msg.rle_list[102]
                );
                assert_eq!(
                    msg.rle_list[103], 9,
                    "incorrect value for rle_list[103], expected 9, is {}",
                    msg.rle_list[103]
                );
                assert_eq!(
                    msg.rle_list[104], 19,
                    "incorrect value for rle_list[104], expected 19, is {}",
                    msg.rle_list[104]
                );
                assert_eq!(
                    msg.rle_list[105], 153,
                    "incorrect value for rle_list[105], expected 153, is {}",
                    msg.rle_list[105]
                );
                assert_eq!(
                    msg.rle_list[106], 44,
                    "incorrect value for rle_list[106], expected 44, is {}",
                    msg.rle_list[106]
                );
                assert_eq!(
                    msg.rle_list[107], 35,
                    "incorrect value for rle_list[107], expected 35, is {}",
                    msg.rle_list[107]
                );
                assert_eq!(
                    msg.rle_list[108], 126,
                    "incorrect value for rle_list[108], expected 126, is {}",
                    msg.rle_list[108]
                );
                assert_eq!(
                    msg.rle_list[109], 14,
                    "incorrect value for rle_list[109], expected 14, is {}",
                    msg.rle_list[109]
                );
                assert_eq!(
                    msg.rle_list[110], 217,
                    "incorrect value for rle_list[110], expected 217, is {}",
                    msg.rle_list[110]
                );
                assert_eq!(
                    msg.rle_list[111], 65,
                    "incorrect value for rle_list[111], expected 65, is {}",
                    msg.rle_list[111]
                );
                assert_eq!(
                    msg.rle_list[112], 116,
                    "incorrect value for rle_list[112], expected 116, is {}",
                    msg.rle_list[112]
                );
                assert_eq!(
                    msg.rle_list[113], 26,
                    "incorrect value for rle_list[113], expected 26, is {}",
                    msg.rle_list[113]
                );
                assert_eq!(
                    msg.rle_list[114], 139,
                    "incorrect value for rle_list[114], expected 139, is {}",
                    msg.rle_list[114]
                );
                assert_eq!(
                    msg.rle_list[115], 122,
                    "incorrect value for rle_list[115], expected 122, is {}",
                    msg.rle_list[115]
                );
                assert_eq!(
                    msg.rle_list[116], 114,
                    "incorrect value for rle_list[116], expected 114, is {}",
                    msg.rle_list[116]
                );
                assert_eq!(
                    msg.rle_list[117], 90,
                    "incorrect value for rle_list[117], expected 90, is {}",
                    msg.rle_list[117]
                );
                assert_eq!(
                    msg.rle_list[118], 124,
                    "incorrect value for rle_list[118], expected 124, is {}",
                    msg.rle_list[118]
                );
                assert_eq!(
                    msg.rle_list[119], 81,
                    "incorrect value for rle_list[119], expected 81, is {}",
                    msg.rle_list[119]
                );
                assert_eq!(
                    msg.rle_list[120], 0,
                    "incorrect value for rle_list[120], expected 0, is {}",
                    msg.rle_list[120]
                );
                assert_eq!(
                    msg.rle_list[121], 186,
                    "incorrect value for rle_list[121], expected 186, is {}",
                    msg.rle_list[121]
                );
                assert_eq!(
                    msg.rle_list[122], 246,
                    "incorrect value for rle_list[122], expected 246, is {}",
                    msg.rle_list[122]
                );
                assert_eq!(
                    msg.rle_list[123], 46,
                    "incorrect value for rle_list[123], expected 46, is {}",
                    msg.rle_list[123]
                );
                assert_eq!(
                    msg.rle_list[124], 98,
                    "incorrect value for rle_list[124], expected 98, is {}",
                    msg.rle_list[124]
                );
                assert_eq!(
                    msg.rle_list[125], 179,
                    "incorrect value for rle_list[125], expected 179, is {}",
                    msg.rle_list[125]
                );
                assert_eq!(
                    msg.rle_list[126], 243,
                    "incorrect value for rle_list[126], expected 243, is {}",
                    msg.rle_list[126]
                );
                assert_eq!(
                    msg.rle_list[127], 198,
                    "incorrect value for rle_list[127], expected 198, is {}",
                    msg.rle_list[127]
                );
                assert_eq!(
                    msg.rle_list[128], 217,
                    "incorrect value for rle_list[128], expected 217, is {}",
                    msg.rle_list[128]
                );
                assert_eq!(
                    msg.rle_list[129], 36,
                    "incorrect value for rle_list[129], expected 36, is {}",
                    msg.rle_list[129]
                );
                assert_eq!(
                    msg.rle_list[130], 30,
                    "incorrect value for rle_list[130], expected 30, is {}",
                    msg.rle_list[130]
                );
                assert_eq!(
                    msg.rle_list[131], 202,
                    "incorrect value for rle_list[131], expected 202, is {}",
                    msg.rle_list[131]
                );
                assert_eq!(
                    msg.rle_list[132], 12,
                    "incorrect value for rle_list[132], expected 12, is {}",
                    msg.rle_list[132]
                );
                assert_eq!(
                    msg.rle_list[133], 135,
                    "incorrect value for rle_list[133], expected 135, is {}",
                    msg.rle_list[133]
                );
                assert_eq!(
                    msg.rle_list[134], 61,
                    "incorrect value for rle_list[134], expected 61, is {}",
                    msg.rle_list[134]
                );
                assert_eq!(
                    msg.rle_list[135], 42,
                    "incorrect value for rle_list[135], expected 42, is {}",
                    msg.rle_list[135]
                );
                assert_eq!(
                    msg.rle_list[136], 150,
                    "incorrect value for rle_list[136], expected 150, is {}",
                    msg.rle_list[136]
                );
                assert_eq!(
                    msg.rle_list[137], 221,
                    "incorrect value for rle_list[137], expected 221, is {}",
                    msg.rle_list[137]
                );
                assert_eq!(
                    msg.rle_list[138], 102,
                    "incorrect value for rle_list[138], expected 102, is {}",
                    msg.rle_list[138]
                );
                assert_eq!(
                    msg.rle_list[139], 83,
                    "incorrect value for rle_list[139], expected 83, is {}",
                    msg.rle_list[139]
                );
                assert_eq!(
                    msg.rle_list[140], 179,
                    "incorrect value for rle_list[140], expected 179, is {}",
                    msg.rle_list[140]
                );
                assert_eq!(
                    msg.rle_list[141], 43,
                    "incorrect value for rle_list[141], expected 43, is {}",
                    msg.rle_list[141]
                );
                assert_eq!(
                    msg.rle_list[142], 252,
                    "incorrect value for rle_list[142], expected 252, is {}",
                    msg.rle_list[142]
                );
                assert_eq!(
                    msg.rle_list[143], 81,
                    "incorrect value for rle_list[143], expected 81, is {}",
                    msg.rle_list[143]
                );
                assert_eq!(
                    msg.rle_list[144], 62,
                    "incorrect value for rle_list[144], expected 62, is {}",
                    msg.rle_list[144]
                );
                assert_eq!(
                    msg.rle_list[145], 126,
                    "incorrect value for rle_list[145], expected 126, is {}",
                    msg.rle_list[145]
                );
                assert_eq!(
                    msg.rle_list[146], 204,
                    "incorrect value for rle_list[146], expected 204, is {}",
                    msg.rle_list[146]
                );
                assert_eq!(
                    msg.rle_list[147], 195,
                    "incorrect value for rle_list[147], expected 195, is {}",
                    msg.rle_list[147]
                );
                assert_eq!(
                    msg.rle_list[148], 238,
                    "incorrect value for rle_list[148], expected 238, is {}",
                    msg.rle_list[148]
                );
                assert_eq!(
                    msg.rle_list[149], 18,
                    "incorrect value for rle_list[149], expected 18, is {}",
                    msg.rle_list[149]
                );
                assert_eq!(
                    msg.rle_list[150], 128,
                    "incorrect value for rle_list[150], expected 128, is {}",
                    msg.rle_list[150]
                );
                assert_eq!(
                    msg.rle_list[151], 193,
                    "incorrect value for rle_list[151], expected 193, is {}",
                    msg.rle_list[151]
                );
                assert_eq!(
                    msg.rle_list[152], 53,
                    "incorrect value for rle_list[152], expected 53, is {}",
                    msg.rle_list[152]
                );
                assert_eq!(
                    msg.rle_list[153], 94,
                    "incorrect value for rle_list[153], expected 94, is {}",
                    msg.rle_list[153]
                );
                assert_eq!(
                    msg.rle_list[154], 99,
                    "incorrect value for rle_list[154], expected 99, is {}",
                    msg.rle_list[154]
                );
                assert_eq!(
                    msg.rle_list[155], 63,
                    "incorrect value for rle_list[155], expected 63, is {}",
                    msg.rle_list[155]
                );
                assert_eq!(
                    msg.rle_list[156], 182,
                    "incorrect value for rle_list[156], expected 182, is {}",
                    msg.rle_list[156]
                );
                assert_eq!(
                    msg.rle_list[157], 2,
                    "incorrect value for rle_list[157], expected 2, is {}",
                    msg.rle_list[157]
                );
                assert_eq!(
                    msg.rle_list[158], 186,
                    "incorrect value for rle_list[158], expected 186, is {}",
                    msg.rle_list[158]
                );
                assert_eq!(
                    msg.rle_list[159], 220,
                    "incorrect value for rle_list[159], expected 220, is {}",
                    msg.rle_list[159]
                );
                assert_eq!(
                    msg.rle_list[160], 77,
                    "incorrect value for rle_list[160], expected 77, is {}",
                    msg.rle_list[160]
                );
                assert_eq!(
                    msg.rle_list[161], 186,
                    "incorrect value for rle_list[161], expected 186, is {}",
                    msg.rle_list[161]
                );
                assert_eq!(
                    msg.rle_list[162], 224,
                    "incorrect value for rle_list[162], expected 224, is {}",
                    msg.rle_list[162]
                );
                assert_eq!(
                    msg.rle_list[163], 220,
                    "incorrect value for rle_list[163], expected 220, is {}",
                    msg.rle_list[163]
                );
                assert_eq!(
                    msg.rle_list[164], 13,
                    "incorrect value for rle_list[164], expected 13, is {}",
                    msg.rle_list[164]
                );
                assert_eq!(
                    msg.rle_list[165], 212,
                    "incorrect value for rle_list[165], expected 212, is {}",
                    msg.rle_list[165]
                );
                assert_eq!(
                    msg.rle_list[166], 182,
                    "incorrect value for rle_list[166], expected 182, is {}",
                    msg.rle_list[166]
                );
                assert_eq!(
                    msg.rle_list[167], 88,
                    "incorrect value for rle_list[167], expected 88, is {}",
                    msg.rle_list[167]
                );
                assert_eq!(
                    msg.rle_list[168], 15,
                    "incorrect value for rle_list[168], expected 15, is {}",
                    msg.rle_list[168]
                );
                assert_eq!(
                    msg.rle_list[169], 151,
                    "incorrect value for rle_list[169], expected 151, is {}",
                    msg.rle_list[169]
                );
                assert_eq!(
                    msg.rle_list[170], 5,
                    "incorrect value for rle_list[170], expected 5, is {}",
                    msg.rle_list[170]
                );
                assert_eq!(
                    msg.rle_list[171], 93,
                    "incorrect value for rle_list[171], expected 93, is {}",
                    msg.rle_list[171]
                );
                assert_eq!(
                    msg.rle_list[172], 251,
                    "incorrect value for rle_list[172], expected 251, is {}",
                    msg.rle_list[172]
                );
                assert_eq!(
                    msg.rle_list[173], 164,
                    "incorrect value for rle_list[173], expected 164, is {}",
                    msg.rle_list[173]
                );
                assert_eq!(
                    msg.rle_list[174], 18,
                    "incorrect value for rle_list[174], expected 18, is {}",
                    msg.rle_list[174]
                );
                assert_eq!(
                    msg.rle_list[175], 228,
                    "incorrect value for rle_list[175], expected 228, is {}",
                    msg.rle_list[175]
                );
                assert_eq!(
                    msg.rle_list[176], 168,
                    "incorrect value for rle_list[176], expected 168, is {}",
                    msg.rle_list[176]
                );
                assert_eq!(
                    msg.rle_list[177], 226,
                    "incorrect value for rle_list[177], expected 226, is {}",
                    msg.rle_list[177]
                );
                assert_eq!(
                    msg.rle_list[178], 195,
                    "incorrect value for rle_list[178], expected 195, is {}",
                    msg.rle_list[178]
                );
                assert_eq!(
                    msg.rle_list[179], 44,
                    "incorrect value for rle_list[179], expected 44, is {}",
                    msg.rle_list[179]
                );
                assert_eq!(
                    msg.rle_list[180], 170,
                    "incorrect value for rle_list[180], expected 170, is {}",
                    msg.rle_list[180]
                );
                assert_eq!(
                    msg.rle_list[181], 145,
                    "incorrect value for rle_list[181], expected 145, is {}",
                    msg.rle_list[181]
                );
                assert_eq!(
                    msg.rle_list[182], 36,
                    "incorrect value for rle_list[182], expected 36, is {}",
                    msg.rle_list[182]
                );
                assert_eq!(
                    msg.rle_list[183], 58,
                    "incorrect value for rle_list[183], expected 58, is {}",
                    msg.rle_list[183]
                );
                assert_eq!(
                    msg.rle_list[184], 96,
                    "incorrect value for rle_list[184], expected 96, is {}",
                    msg.rle_list[184]
                );
                assert_eq!(
                    msg.rle_list[185], 107,
                    "incorrect value for rle_list[185], expected 107, is {}",
                    msg.rle_list[185]
                );
                assert_eq!(
                    msg.rle_list[186], 144,
                    "incorrect value for rle_list[186], expected 144, is {}",
                    msg.rle_list[186]
                );
                assert_eq!(
                    msg.rle_list[187], 11,
                    "incorrect value for rle_list[187], expected 11, is {}",
                    msg.rle_list[187]
                );
                assert_eq!(
                    msg.rle_list[188], 228,
                    "incorrect value for rle_list[188], expected 228, is {}",
                    msg.rle_list[188]
                );
                assert_eq!(
                    msg.rle_list[189], 12,
                    "incorrect value for rle_list[189], expected 12, is {}",
                    msg.rle_list[189]
                );
                assert_eq!(
                    msg.rle_list[190], 163,
                    "incorrect value for rle_list[190], expected 163, is {}",
                    msg.rle_list[190]
                );
                assert_eq!(
                    msg.rle_list[191], 238,
                    "incorrect value for rle_list[191], expected 238, is {}",
                    msg.rle_list[191]
                );
                assert_eq!(
                    msg.rle_list[192], 247,
                    "incorrect value for rle_list[192], expected 247, is {}",
                    msg.rle_list[192]
                );
                assert_eq!(
                    msg.rle_list[193], 159,
                    "incorrect value for rle_list[193], expected 159, is {}",
                    msg.rle_list[193]
                );
                assert_eq!(
                    msg.rle_list[194], 189,
                    "incorrect value for rle_list[194], expected 189, is {}",
                    msg.rle_list[194]
                );
                assert_eq!(
                    msg.rle_list[195], 1,
                    "incorrect value for rle_list[195], expected 1, is {}",
                    msg.rle_list[195]
                );
                assert_eq!(
                    msg.rle_list[196], 115,
                    "incorrect value for rle_list[196], expected 115, is {}",
                    msg.rle_list[196]
                );
                assert_eq!(
                    msg.rle_list[197], 65,
                    "incorrect value for rle_list[197], expected 65, is {}",
                    msg.rle_list[197]
                );
                assert_eq!(
                    msg.rle_list[198], 202,
                    "incorrect value for rle_list[198], expected 202, is {}",
                    msg.rle_list[198]
                );
                assert_eq!(
                    msg.rle_list[199], 121,
                    "incorrect value for rle_list[199], expected 121, is {}",
                    msg.rle_list[199]
                );
                assert_eq!(
                    msg.rle_list[200], 47,
                    "incorrect value for rle_list[200], expected 47, is {}",
                    msg.rle_list[200]
                );
                assert_eq!(
                    msg.rle_list[201], 193,
                    "incorrect value for rle_list[201], expected 193, is {}",
                    msg.rle_list[201]
                );
                assert_eq!(
                    msg.rle_list[202], 11,
                    "incorrect value for rle_list[202], expected 11, is {}",
                    msg.rle_list[202]
                );
                assert_eq!(
                    msg.rle_list[203], 96,
                    "incorrect value for rle_list[203], expected 96, is {}",
                    msg.rle_list[203]
                );
                assert_eq!(
                    msg.rle_list[204], 93,
                    "incorrect value for rle_list[204], expected 93, is {}",
                    msg.rle_list[204]
                );
                assert_eq!(
                    msg.rle_list[205], 72,
                    "incorrect value for rle_list[205], expected 72, is {}",
                    msg.rle_list[205]
                );
                assert_eq!(
                    msg.rle_list[206], 81,
                    "incorrect value for rle_list[206], expected 81, is {}",
                    msg.rle_list[206]
                );
                assert_eq!(
                    msg.rle_list[207], 207,
                    "incorrect value for rle_list[207], expected 207, is {}",
                    msg.rle_list[207]
                );
                assert_eq!(
                    msg.rle_list[208], 121,
                    "incorrect value for rle_list[208], expected 121, is {}",
                    msg.rle_list[208]
                );
                assert_eq!(
                    msg.rle_list[209], 19,
                    "incorrect value for rle_list[209], expected 19, is {}",
                    msg.rle_list[209]
                );
                assert_eq!(
                    msg.rle_list[210], 151,
                    "incorrect value for rle_list[210], expected 151, is {}",
                    msg.rle_list[210]
                );
                assert_eq!(
                    msg.rle_list[211], 136,
                    "incorrect value for rle_list[211], expected 136, is {}",
                    msg.rle_list[211]
                );
                assert_eq!(
                    msg.rle_list[212], 233,
                    "incorrect value for rle_list[212], expected 233, is {}",
                    msg.rle_list[212]
                );
                assert_eq!(
                    msg.rle_list[213], 51,
                    "incorrect value for rle_list[213], expected 51, is {}",
                    msg.rle_list[213]
                );
                assert_eq!(
                    msg.rle_list[214], 133,
                    "incorrect value for rle_list[214], expected 133, is {}",
                    msg.rle_list[214]
                );
                assert_eq!(
                    msg.rle_list[215], 195,
                    "incorrect value for rle_list[215], expected 195, is {}",
                    msg.rle_list[215]
                );
                assert_eq!(
                    msg.rle_list[216], 77,
                    "incorrect value for rle_list[216], expected 77, is {}",
                    msg.rle_list[216]
                );
                assert_eq!(
                    msg.rle_list[217], 44,
                    "incorrect value for rle_list[217], expected 44, is {}",
                    msg.rle_list[217]
                );
                assert_eq!(
                    msg.rle_list[218], 147,
                    "incorrect value for rle_list[218], expected 147, is {}",
                    msg.rle_list[218]
                );
                assert_eq!(
                    msg.rle_list[219], 206,
                    "incorrect value for rle_list[219], expected 206, is {}",
                    msg.rle_list[219]
                );
                assert_eq!(
                    msg.rle_list[220], 120,
                    "incorrect value for rle_list[220], expected 120, is {}",
                    msg.rle_list[220]
                );
                assert_eq!(
                    msg.rle_list[221], 252,
                    "incorrect value for rle_list[221], expected 252, is {}",
                    msg.rle_list[221]
                );
                assert_eq!(
                    msg.rle_list[222], 77,
                    "incorrect value for rle_list[222], expected 77, is {}",
                    msg.rle_list[222]
                );
                assert_eq!(
                    msg.rle_list[223], 212,
                    "incorrect value for rle_list[223], expected 212, is {}",
                    msg.rle_list[223]
                );
                assert_eq!(
                    msg.rle_list[224], 68,
                    "incorrect value for rle_list[224], expected 68, is {}",
                    msg.rle_list[224]
                );
                assert_eq!(
                    msg.rle_list[225], 60,
                    "incorrect value for rle_list[225], expected 60, is {}",
                    msg.rle_list[225]
                );
                assert_eq!(
                    msg.rle_list[226], 206,
                    "incorrect value for rle_list[226], expected 206, is {}",
                    msg.rle_list[226]
                );
                assert_eq!(
                    msg.rle_list[227], 106,
                    "incorrect value for rle_list[227], expected 106, is {}",
                    msg.rle_list[227]
                );
                assert_eq!(
                    msg.rle_list[228], 207,
                    "incorrect value for rle_list[228], expected 207, is {}",
                    msg.rle_list[228]
                );
                assert_eq!(
                    msg.rle_list[229], 243,
                    "incorrect value for rle_list[229], expected 243, is {}",
                    msg.rle_list[229]
                );
                assert_eq!(
                    msg.rle_list[230], 158,
                    "incorrect value for rle_list[230], expected 158, is {}",
                    msg.rle_list[230]
                );
                assert_eq!(
                    msg.rle_list[231], 94,
                    "incorrect value for rle_list[231], expected 94, is {}",
                    msg.rle_list[231]
                );
                assert_eq!(
                    msg.rle_list[232], 6,
                    "incorrect value for rle_list[232], expected 6, is {}",
                    msg.rle_list[232]
                );
                assert_eq!(
                    msg.rle_list[233], 3,
                    "incorrect value for rle_list[233], expected 3, is {}",
                    msg.rle_list[233]
                );
                assert_eq!(
                    msg.rle_list[234], 205,
                    "incorrect value for rle_list[234], expected 205, is {}",
                    msg.rle_list[234]
                );
                assert_eq!(
                    msg.rle_list[235], 92,
                    "incorrect value for rle_list[235], expected 92, is {}",
                    msg.rle_list[235]
                );
                assert_eq!(
                    msg.rle_list[236], 84,
                    "incorrect value for rle_list[236], expected 84, is {}",
                    msg.rle_list[236]
                );
                assert_eq!(
                    msg.rle_list[237], 2,
                    "incorrect value for rle_list[237], expected 2, is {}",
                    msg.rle_list[237]
                );
                assert_eq!(
                    msg.rle_list[238], 220,
                    "incorrect value for rle_list[238], expected 220, is {}",
                    msg.rle_list[238]
                );
                assert_eq!(
                    msg.rle_list[239], 50,
                    "incorrect value for rle_list[239], expected 50, is {}",
                    msg.rle_list[239]
                );
                assert_eq!(
                    msg.rle_list[240], 61,
                    "incorrect value for rle_list[240], expected 61, is {}",
                    msg.rle_list[240]
                );
                assert_eq!(
                    msg.rle_list[241], 38,
                    "incorrect value for rle_list[241], expected 38, is {}",
                    msg.rle_list[241]
                );
                assert_eq!(
                    msg.rle_list[242], 141,
                    "incorrect value for rle_list[242], expected 141, is {}",
                    msg.rle_list[242]
                );
                assert_eq!(
                    msg.rle_list[243], 117,
                    "incorrect value for rle_list[243], expected 117, is {}",
                    msg.rle_list[243]
                );
                assert_eq!(
                    msg.rle_list[244], 108,
                    "incorrect value for rle_list[244], expected 108, is {}",
                    msg.rle_list[244]
                );
                assert_eq!(
                    msg.rle_list[245], 101,
                    "incorrect value for rle_list[245], expected 101, is {}",
                    msg.rle_list[245]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGridDefinitionDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
