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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgSpecan.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_piksi_msg_specan() {
    {
        let mut payload = Cursor::new(vec![
            85, 81, 0, 28, 212, 255, 74, 137, 71, 245, 34, 73, 12, 221, 215, 167, 211, 19, 154,
            201, 241, 69, 205, 136, 0, 70, 51, 67, 108, 69, 102, 38, 166, 68, 100, 179, 185, 17,
            175, 49, 193, 228, 228, 47, 33, 24, 141, 177, 18, 99, 246, 121, 61, 40, 91, 145, 223,
            167, 174, 9, 116, 11, 247, 84, 49, 153, 205, 2, 230, 194, 218, 241, 101, 107, 45, 137,
            93, 114, 230, 43, 224, 23, 74, 209, 199, 211, 130, 89, 220, 163, 68, 20, 253, 7, 206,
            50, 129, 116, 194, 23, 31, 226, 217, 157, 205, 221, 5, 224, 92, 82, 109, 223, 195, 233,
            165, 1, 82, 141, 157, 177, 169, 244, 131, 96, 109, 111, 253, 149, 28, 225, 225, 72,
            158, 158, 210, 196, 206, 70, 63, 225, 184, 150, 174, 240, 45, 146, 59, 82, 194, 4, 179,
            148, 66, 254, 115, 77, 30, 46, 4, 204, 37, 200, 121, 18, 17, 171, 102, 163, 175, 50,
            66, 101, 69, 13, 223, 172, 160, 233, 220, 101, 237, 156, 62, 117, 47, 143, 94, 135, 22,
            155, 113, 110, 15, 243, 141, 227, 46, 143, 227, 209, 249, 2, 153, 168, 131, 249, 160,
            88, 38, 117, 129, 57, 40, 109, 209, 177, 38, 47, 12, 15, 16, 9, 175, 69, 70, 182, 239,
            117, 135, 6, 71, 99, 230, 115, 2, 71, 165, 228, 123, 210, 168, 90, 124, 20, 7, 220,
            144, 168, 69, 22, 72, 162, 69, 111, 91, 251, 72, 220, 28, 119, 150, 95, 2,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSpecan(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x51,
                    "Incorrect message type, expected 0x51, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd41c,
                    "incorrect sender id, expected 0xd41c, is {sender_id}"
                );
                assert!(
                    msg.amplitude_ref.almost_eq(3.78019995117187500e+03),
                    "incorrect value for amplitude_ref, expected 3.78019995117187500e+03, is {:e}",
                    msg.amplitude_ref
                );
                assert!(
                    msg.amplitude_unit.almost_eq(1.32919995117187500e+03),
                    "incorrect value for amplitude_unit, expected 1.32919995117187500e+03, is {:e}",
                    msg.amplitude_unit
                );
                assert_eq!(
                    msg.amplitude_value[0], 100,
                    "incorrect value for amplitude_value[0], expected 100, is {}",
                    msg.amplitude_value[0]
                );
                assert_eq!(
                    msg.amplitude_value[1], 179,
                    "incorrect value for amplitude_value[1], expected 179, is {}",
                    msg.amplitude_value[1]
                );
                assert_eq!(
                    msg.amplitude_value[2], 185,
                    "incorrect value for amplitude_value[2], expected 185, is {}",
                    msg.amplitude_value[2]
                );
                assert_eq!(
                    msg.amplitude_value[3], 17,
                    "incorrect value for amplitude_value[3], expected 17, is {}",
                    msg.amplitude_value[3]
                );
                assert_eq!(
                    msg.amplitude_value[4], 175,
                    "incorrect value for amplitude_value[4], expected 175, is {}",
                    msg.amplitude_value[4]
                );
                assert_eq!(
                    msg.amplitude_value[5], 49,
                    "incorrect value for amplitude_value[5], expected 49, is {}",
                    msg.amplitude_value[5]
                );
                assert_eq!(
                    msg.amplitude_value[6], 193,
                    "incorrect value for amplitude_value[6], expected 193, is {}",
                    msg.amplitude_value[6]
                );
                assert_eq!(
                    msg.amplitude_value[7], 228,
                    "incorrect value for amplitude_value[7], expected 228, is {}",
                    msg.amplitude_value[7]
                );
                assert_eq!(
                    msg.amplitude_value[8], 228,
                    "incorrect value for amplitude_value[8], expected 228, is {}",
                    msg.amplitude_value[8]
                );
                assert_eq!(
                    msg.amplitude_value[9], 47,
                    "incorrect value for amplitude_value[9], expected 47, is {}",
                    msg.amplitude_value[9]
                );
                assert_eq!(
                    msg.amplitude_value[10], 33,
                    "incorrect value for amplitude_value[10], expected 33, is {}",
                    msg.amplitude_value[10]
                );
                assert_eq!(
                    msg.amplitude_value[11], 24,
                    "incorrect value for amplitude_value[11], expected 24, is {}",
                    msg.amplitude_value[11]
                );
                assert_eq!(
                    msg.amplitude_value[12], 141,
                    "incorrect value for amplitude_value[12], expected 141, is {}",
                    msg.amplitude_value[12]
                );
                assert_eq!(
                    msg.amplitude_value[13], 177,
                    "incorrect value for amplitude_value[13], expected 177, is {}",
                    msg.amplitude_value[13]
                );
                assert_eq!(
                    msg.amplitude_value[14], 18,
                    "incorrect value for amplitude_value[14], expected 18, is {}",
                    msg.amplitude_value[14]
                );
                assert_eq!(
                    msg.amplitude_value[15], 99,
                    "incorrect value for amplitude_value[15], expected 99, is {}",
                    msg.amplitude_value[15]
                );
                assert_eq!(
                    msg.amplitude_value[16], 246,
                    "incorrect value for amplitude_value[16], expected 246, is {}",
                    msg.amplitude_value[16]
                );
                assert_eq!(
                    msg.amplitude_value[17], 121,
                    "incorrect value for amplitude_value[17], expected 121, is {}",
                    msg.amplitude_value[17]
                );
                assert_eq!(
                    msg.amplitude_value[18], 61,
                    "incorrect value for amplitude_value[18], expected 61, is {}",
                    msg.amplitude_value[18]
                );
                assert_eq!(
                    msg.amplitude_value[19], 40,
                    "incorrect value for amplitude_value[19], expected 40, is {}",
                    msg.amplitude_value[19]
                );
                assert_eq!(
                    msg.amplitude_value[20], 91,
                    "incorrect value for amplitude_value[20], expected 91, is {}",
                    msg.amplitude_value[20]
                );
                assert_eq!(
                    msg.amplitude_value[21], 145,
                    "incorrect value for amplitude_value[21], expected 145, is {}",
                    msg.amplitude_value[21]
                );
                assert_eq!(
                    msg.amplitude_value[22], 223,
                    "incorrect value for amplitude_value[22], expected 223, is {}",
                    msg.amplitude_value[22]
                );
                assert_eq!(
                    msg.amplitude_value[23], 167,
                    "incorrect value for amplitude_value[23], expected 167, is {}",
                    msg.amplitude_value[23]
                );
                assert_eq!(
                    msg.amplitude_value[24], 174,
                    "incorrect value for amplitude_value[24], expected 174, is {}",
                    msg.amplitude_value[24]
                );
                assert_eq!(
                    msg.amplitude_value[25], 9,
                    "incorrect value for amplitude_value[25], expected 9, is {}",
                    msg.amplitude_value[25]
                );
                assert_eq!(
                    msg.amplitude_value[26], 116,
                    "incorrect value for amplitude_value[26], expected 116, is {}",
                    msg.amplitude_value[26]
                );
                assert_eq!(
                    msg.amplitude_value[27], 11,
                    "incorrect value for amplitude_value[27], expected 11, is {}",
                    msg.amplitude_value[27]
                );
                assert_eq!(
                    msg.amplitude_value[28], 247,
                    "incorrect value for amplitude_value[28], expected 247, is {}",
                    msg.amplitude_value[28]
                );
                assert_eq!(
                    msg.amplitude_value[29], 84,
                    "incorrect value for amplitude_value[29], expected 84, is {}",
                    msg.amplitude_value[29]
                );
                assert_eq!(
                    msg.amplitude_value[30], 49,
                    "incorrect value for amplitude_value[30], expected 49, is {}",
                    msg.amplitude_value[30]
                );
                assert_eq!(
                    msg.amplitude_value[31], 153,
                    "incorrect value for amplitude_value[31], expected 153, is {}",
                    msg.amplitude_value[31]
                );
                assert_eq!(
                    msg.amplitude_value[32], 205,
                    "incorrect value for amplitude_value[32], expected 205, is {}",
                    msg.amplitude_value[32]
                );
                assert_eq!(
                    msg.amplitude_value[33], 2,
                    "incorrect value for amplitude_value[33], expected 2, is {}",
                    msg.amplitude_value[33]
                );
                assert_eq!(
                    msg.amplitude_value[34], 230,
                    "incorrect value for amplitude_value[34], expected 230, is {}",
                    msg.amplitude_value[34]
                );
                assert_eq!(
                    msg.amplitude_value[35], 194,
                    "incorrect value for amplitude_value[35], expected 194, is {}",
                    msg.amplitude_value[35]
                );
                assert_eq!(
                    msg.amplitude_value[36], 218,
                    "incorrect value for amplitude_value[36], expected 218, is {}",
                    msg.amplitude_value[36]
                );
                assert_eq!(
                    msg.amplitude_value[37], 241,
                    "incorrect value for amplitude_value[37], expected 241, is {}",
                    msg.amplitude_value[37]
                );
                assert_eq!(
                    msg.amplitude_value[38], 101,
                    "incorrect value for amplitude_value[38], expected 101, is {}",
                    msg.amplitude_value[38]
                );
                assert_eq!(
                    msg.amplitude_value[39], 107,
                    "incorrect value for amplitude_value[39], expected 107, is {}",
                    msg.amplitude_value[39]
                );
                assert_eq!(
                    msg.amplitude_value[40], 45,
                    "incorrect value for amplitude_value[40], expected 45, is {}",
                    msg.amplitude_value[40]
                );
                assert_eq!(
                    msg.amplitude_value[41], 137,
                    "incorrect value for amplitude_value[41], expected 137, is {}",
                    msg.amplitude_value[41]
                );
                assert_eq!(
                    msg.amplitude_value[42], 93,
                    "incorrect value for amplitude_value[42], expected 93, is {}",
                    msg.amplitude_value[42]
                );
                assert_eq!(
                    msg.amplitude_value[43], 114,
                    "incorrect value for amplitude_value[43], expected 114, is {}",
                    msg.amplitude_value[43]
                );
                assert_eq!(
                    msg.amplitude_value[44], 230,
                    "incorrect value for amplitude_value[44], expected 230, is {}",
                    msg.amplitude_value[44]
                );
                assert_eq!(
                    msg.amplitude_value[45], 43,
                    "incorrect value for amplitude_value[45], expected 43, is {}",
                    msg.amplitude_value[45]
                );
                assert_eq!(
                    msg.amplitude_value[46], 224,
                    "incorrect value for amplitude_value[46], expected 224, is {}",
                    msg.amplitude_value[46]
                );
                assert_eq!(
                    msg.amplitude_value[47], 23,
                    "incorrect value for amplitude_value[47], expected 23, is {}",
                    msg.amplitude_value[47]
                );
                assert_eq!(
                    msg.amplitude_value[48], 74,
                    "incorrect value for amplitude_value[48], expected 74, is {}",
                    msg.amplitude_value[48]
                );
                assert_eq!(
                    msg.amplitude_value[49], 209,
                    "incorrect value for amplitude_value[49], expected 209, is {}",
                    msg.amplitude_value[49]
                );
                assert_eq!(
                    msg.amplitude_value[50], 199,
                    "incorrect value for amplitude_value[50], expected 199, is {}",
                    msg.amplitude_value[50]
                );
                assert_eq!(
                    msg.amplitude_value[51], 211,
                    "incorrect value for amplitude_value[51], expected 211, is {}",
                    msg.amplitude_value[51]
                );
                assert_eq!(
                    msg.amplitude_value[52], 130,
                    "incorrect value for amplitude_value[52], expected 130, is {}",
                    msg.amplitude_value[52]
                );
                assert_eq!(
                    msg.amplitude_value[53], 89,
                    "incorrect value for amplitude_value[53], expected 89, is {}",
                    msg.amplitude_value[53]
                );
                assert_eq!(
                    msg.amplitude_value[54], 220,
                    "incorrect value for amplitude_value[54], expected 220, is {}",
                    msg.amplitude_value[54]
                );
                assert_eq!(
                    msg.amplitude_value[55], 163,
                    "incorrect value for amplitude_value[55], expected 163, is {}",
                    msg.amplitude_value[55]
                );
                assert_eq!(
                    msg.amplitude_value[56], 68,
                    "incorrect value for amplitude_value[56], expected 68, is {}",
                    msg.amplitude_value[56]
                );
                assert_eq!(
                    msg.amplitude_value[57], 20,
                    "incorrect value for amplitude_value[57], expected 20, is {}",
                    msg.amplitude_value[57]
                );
                assert_eq!(
                    msg.amplitude_value[58], 253,
                    "incorrect value for amplitude_value[58], expected 253, is {}",
                    msg.amplitude_value[58]
                );
                assert_eq!(
                    msg.amplitude_value[59], 7,
                    "incorrect value for amplitude_value[59], expected 7, is {}",
                    msg.amplitude_value[59]
                );
                assert_eq!(
                    msg.amplitude_value[60], 206,
                    "incorrect value for amplitude_value[60], expected 206, is {}",
                    msg.amplitude_value[60]
                );
                assert_eq!(
                    msg.amplitude_value[61], 50,
                    "incorrect value for amplitude_value[61], expected 50, is {}",
                    msg.amplitude_value[61]
                );
                assert_eq!(
                    msg.amplitude_value[62], 129,
                    "incorrect value for amplitude_value[62], expected 129, is {}",
                    msg.amplitude_value[62]
                );
                assert_eq!(
                    msg.amplitude_value[63], 116,
                    "incorrect value for amplitude_value[63], expected 116, is {}",
                    msg.amplitude_value[63]
                );
                assert_eq!(
                    msg.amplitude_value[64], 194,
                    "incorrect value for amplitude_value[64], expected 194, is {}",
                    msg.amplitude_value[64]
                );
                assert_eq!(
                    msg.amplitude_value[65], 23,
                    "incorrect value for amplitude_value[65], expected 23, is {}",
                    msg.amplitude_value[65]
                );
                assert_eq!(
                    msg.amplitude_value[66], 31,
                    "incorrect value for amplitude_value[66], expected 31, is {}",
                    msg.amplitude_value[66]
                );
                assert_eq!(
                    msg.amplitude_value[67], 226,
                    "incorrect value for amplitude_value[67], expected 226, is {}",
                    msg.amplitude_value[67]
                );
                assert_eq!(
                    msg.amplitude_value[68], 217,
                    "incorrect value for amplitude_value[68], expected 217, is {}",
                    msg.amplitude_value[68]
                );
                assert_eq!(
                    msg.amplitude_value[69], 157,
                    "incorrect value for amplitude_value[69], expected 157, is {}",
                    msg.amplitude_value[69]
                );
                assert_eq!(
                    msg.amplitude_value[70], 205,
                    "incorrect value for amplitude_value[70], expected 205, is {}",
                    msg.amplitude_value[70]
                );
                assert_eq!(
                    msg.amplitude_value[71], 221,
                    "incorrect value for amplitude_value[71], expected 221, is {}",
                    msg.amplitude_value[71]
                );
                assert_eq!(
                    msg.amplitude_value[72], 5,
                    "incorrect value for amplitude_value[72], expected 5, is {}",
                    msg.amplitude_value[72]
                );
                assert_eq!(
                    msg.amplitude_value[73], 224,
                    "incorrect value for amplitude_value[73], expected 224, is {}",
                    msg.amplitude_value[73]
                );
                assert_eq!(
                    msg.amplitude_value[74], 92,
                    "incorrect value for amplitude_value[74], expected 92, is {}",
                    msg.amplitude_value[74]
                );
                assert_eq!(
                    msg.amplitude_value[75], 82,
                    "incorrect value for amplitude_value[75], expected 82, is {}",
                    msg.amplitude_value[75]
                );
                assert_eq!(
                    msg.amplitude_value[76], 109,
                    "incorrect value for amplitude_value[76], expected 109, is {}",
                    msg.amplitude_value[76]
                );
                assert_eq!(
                    msg.amplitude_value[77], 223,
                    "incorrect value for amplitude_value[77], expected 223, is {}",
                    msg.amplitude_value[77]
                );
                assert_eq!(
                    msg.amplitude_value[78], 195,
                    "incorrect value for amplitude_value[78], expected 195, is {}",
                    msg.amplitude_value[78]
                );
                assert_eq!(
                    msg.amplitude_value[79], 233,
                    "incorrect value for amplitude_value[79], expected 233, is {}",
                    msg.amplitude_value[79]
                );
                assert_eq!(
                    msg.amplitude_value[80], 165,
                    "incorrect value for amplitude_value[80], expected 165, is {}",
                    msg.amplitude_value[80]
                );
                assert_eq!(
                    msg.amplitude_value[81], 1,
                    "incorrect value for amplitude_value[81], expected 1, is {}",
                    msg.amplitude_value[81]
                );
                assert_eq!(
                    msg.amplitude_value[82], 82,
                    "incorrect value for amplitude_value[82], expected 82, is {}",
                    msg.amplitude_value[82]
                );
                assert_eq!(
                    msg.amplitude_value[83], 141,
                    "incorrect value for amplitude_value[83], expected 141, is {}",
                    msg.amplitude_value[83]
                );
                assert_eq!(
                    msg.amplitude_value[84], 157,
                    "incorrect value for amplitude_value[84], expected 157, is {}",
                    msg.amplitude_value[84]
                );
                assert_eq!(
                    msg.amplitude_value[85], 177,
                    "incorrect value for amplitude_value[85], expected 177, is {}",
                    msg.amplitude_value[85]
                );
                assert_eq!(
                    msg.amplitude_value[86], 169,
                    "incorrect value for amplitude_value[86], expected 169, is {}",
                    msg.amplitude_value[86]
                );
                assert_eq!(
                    msg.amplitude_value[87], 244,
                    "incorrect value for amplitude_value[87], expected 244, is {}",
                    msg.amplitude_value[87]
                );
                assert_eq!(
                    msg.amplitude_value[88], 131,
                    "incorrect value for amplitude_value[88], expected 131, is {}",
                    msg.amplitude_value[88]
                );
                assert_eq!(
                    msg.amplitude_value[89], 96,
                    "incorrect value for amplitude_value[89], expected 96, is {}",
                    msg.amplitude_value[89]
                );
                assert_eq!(
                    msg.amplitude_value[90], 109,
                    "incorrect value for amplitude_value[90], expected 109, is {}",
                    msg.amplitude_value[90]
                );
                assert_eq!(
                    msg.amplitude_value[91], 111,
                    "incorrect value for amplitude_value[91], expected 111, is {}",
                    msg.amplitude_value[91]
                );
                assert_eq!(
                    msg.amplitude_value[92], 253,
                    "incorrect value for amplitude_value[92], expected 253, is {}",
                    msg.amplitude_value[92]
                );
                assert_eq!(
                    msg.amplitude_value[93], 149,
                    "incorrect value for amplitude_value[93], expected 149, is {}",
                    msg.amplitude_value[93]
                );
                assert_eq!(
                    msg.amplitude_value[94], 28,
                    "incorrect value for amplitude_value[94], expected 28, is {}",
                    msg.amplitude_value[94]
                );
                assert_eq!(
                    msg.amplitude_value[95], 225,
                    "incorrect value for amplitude_value[95], expected 225, is {}",
                    msg.amplitude_value[95]
                );
                assert_eq!(
                    msg.amplitude_value[96], 225,
                    "incorrect value for amplitude_value[96], expected 225, is {}",
                    msg.amplitude_value[96]
                );
                assert_eq!(
                    msg.amplitude_value[97], 72,
                    "incorrect value for amplitude_value[97], expected 72, is {}",
                    msg.amplitude_value[97]
                );
                assert_eq!(
                    msg.amplitude_value[98], 158,
                    "incorrect value for amplitude_value[98], expected 158, is {}",
                    msg.amplitude_value[98]
                );
                assert_eq!(
                    msg.amplitude_value[99], 158,
                    "incorrect value for amplitude_value[99], expected 158, is {}",
                    msg.amplitude_value[99]
                );
                assert_eq!(
                    msg.amplitude_value[100], 210,
                    "incorrect value for amplitude_value[100], expected 210, is {}",
                    msg.amplitude_value[100]
                );
                assert_eq!(
                    msg.amplitude_value[101], 196,
                    "incorrect value for amplitude_value[101], expected 196, is {}",
                    msg.amplitude_value[101]
                );
                assert_eq!(
                    msg.amplitude_value[102], 206,
                    "incorrect value for amplitude_value[102], expected 206, is {}",
                    msg.amplitude_value[102]
                );
                assert_eq!(
                    msg.amplitude_value[103], 70,
                    "incorrect value for amplitude_value[103], expected 70, is {}",
                    msg.amplitude_value[103]
                );
                assert_eq!(
                    msg.amplitude_value[104], 63,
                    "incorrect value for amplitude_value[104], expected 63, is {}",
                    msg.amplitude_value[104]
                );
                assert_eq!(
                    msg.amplitude_value[105], 225,
                    "incorrect value for amplitude_value[105], expected 225, is {}",
                    msg.amplitude_value[105]
                );
                assert_eq!(
                    msg.amplitude_value[106], 184,
                    "incorrect value for amplitude_value[106], expected 184, is {}",
                    msg.amplitude_value[106]
                );
                assert_eq!(
                    msg.amplitude_value[107], 150,
                    "incorrect value for amplitude_value[107], expected 150, is {}",
                    msg.amplitude_value[107]
                );
                assert_eq!(
                    msg.amplitude_value[108], 174,
                    "incorrect value for amplitude_value[108], expected 174, is {}",
                    msg.amplitude_value[108]
                );
                assert_eq!(
                    msg.amplitude_value[109], 240,
                    "incorrect value for amplitude_value[109], expected 240, is {}",
                    msg.amplitude_value[109]
                );
                assert_eq!(
                    msg.amplitude_value[110], 45,
                    "incorrect value for amplitude_value[110], expected 45, is {}",
                    msg.amplitude_value[110]
                );
                assert_eq!(
                    msg.amplitude_value[111], 146,
                    "incorrect value for amplitude_value[111], expected 146, is {}",
                    msg.amplitude_value[111]
                );
                assert_eq!(
                    msg.amplitude_value[112], 59,
                    "incorrect value for amplitude_value[112], expected 59, is {}",
                    msg.amplitude_value[112]
                );
                assert_eq!(
                    msg.amplitude_value[113], 82,
                    "incorrect value for amplitude_value[113], expected 82, is {}",
                    msg.amplitude_value[113]
                );
                assert_eq!(
                    msg.amplitude_value[114], 194,
                    "incorrect value for amplitude_value[114], expected 194, is {}",
                    msg.amplitude_value[114]
                );
                assert_eq!(
                    msg.amplitude_value[115], 4,
                    "incorrect value for amplitude_value[115], expected 4, is {}",
                    msg.amplitude_value[115]
                );
                assert_eq!(
                    msg.amplitude_value[116], 179,
                    "incorrect value for amplitude_value[116], expected 179, is {}",
                    msg.amplitude_value[116]
                );
                assert_eq!(
                    msg.amplitude_value[117], 148,
                    "incorrect value for amplitude_value[117], expected 148, is {}",
                    msg.amplitude_value[117]
                );
                assert_eq!(
                    msg.amplitude_value[118], 66,
                    "incorrect value for amplitude_value[118], expected 66, is {}",
                    msg.amplitude_value[118]
                );
                assert_eq!(
                    msg.amplitude_value[119], 254,
                    "incorrect value for amplitude_value[119], expected 254, is {}",
                    msg.amplitude_value[119]
                );
                assert_eq!(
                    msg.amplitude_value[120], 115,
                    "incorrect value for amplitude_value[120], expected 115, is {}",
                    msg.amplitude_value[120]
                );
                assert_eq!(
                    msg.amplitude_value[121], 77,
                    "incorrect value for amplitude_value[121], expected 77, is {}",
                    msg.amplitude_value[121]
                );
                assert_eq!(
                    msg.amplitude_value[122], 30,
                    "incorrect value for amplitude_value[122], expected 30, is {}",
                    msg.amplitude_value[122]
                );
                assert_eq!(
                    msg.amplitude_value[123], 46,
                    "incorrect value for amplitude_value[123], expected 46, is {}",
                    msg.amplitude_value[123]
                );
                assert_eq!(
                    msg.amplitude_value[124], 4,
                    "incorrect value for amplitude_value[124], expected 4, is {}",
                    msg.amplitude_value[124]
                );
                assert_eq!(
                    msg.amplitude_value[125], 204,
                    "incorrect value for amplitude_value[125], expected 204, is {}",
                    msg.amplitude_value[125]
                );
                assert_eq!(
                    msg.amplitude_value[126], 37,
                    "incorrect value for amplitude_value[126], expected 37, is {}",
                    msg.amplitude_value[126]
                );
                assert_eq!(
                    msg.amplitude_value[127], 200,
                    "incorrect value for amplitude_value[127], expected 200, is {}",
                    msg.amplitude_value[127]
                );
                assert_eq!(
                    msg.amplitude_value[128], 121,
                    "incorrect value for amplitude_value[128], expected 121, is {}",
                    msg.amplitude_value[128]
                );
                assert_eq!(
                    msg.amplitude_value[129], 18,
                    "incorrect value for amplitude_value[129], expected 18, is {}",
                    msg.amplitude_value[129]
                );
                assert_eq!(
                    msg.amplitude_value[130], 17,
                    "incorrect value for amplitude_value[130], expected 17, is {}",
                    msg.amplitude_value[130]
                );
                assert_eq!(
                    msg.amplitude_value[131], 171,
                    "incorrect value for amplitude_value[131], expected 171, is {}",
                    msg.amplitude_value[131]
                );
                assert_eq!(
                    msg.amplitude_value[132], 102,
                    "incorrect value for amplitude_value[132], expected 102, is {}",
                    msg.amplitude_value[132]
                );
                assert_eq!(
                    msg.amplitude_value[133], 163,
                    "incorrect value for amplitude_value[133], expected 163, is {}",
                    msg.amplitude_value[133]
                );
                assert_eq!(
                    msg.amplitude_value[134], 175,
                    "incorrect value for amplitude_value[134], expected 175, is {}",
                    msg.amplitude_value[134]
                );
                assert_eq!(
                    msg.amplitude_value[135], 50,
                    "incorrect value for amplitude_value[135], expected 50, is {}",
                    msg.amplitude_value[135]
                );
                assert_eq!(
                    msg.amplitude_value[136], 66,
                    "incorrect value for amplitude_value[136], expected 66, is {}",
                    msg.amplitude_value[136]
                );
                assert_eq!(
                    msg.amplitude_value[137], 101,
                    "incorrect value for amplitude_value[137], expected 101, is {}",
                    msg.amplitude_value[137]
                );
                assert_eq!(
                    msg.amplitude_value[138], 69,
                    "incorrect value for amplitude_value[138], expected 69, is {}",
                    msg.amplitude_value[138]
                );
                assert_eq!(
                    msg.amplitude_value[139], 13,
                    "incorrect value for amplitude_value[139], expected 13, is {}",
                    msg.amplitude_value[139]
                );
                assert_eq!(
                    msg.amplitude_value[140], 223,
                    "incorrect value for amplitude_value[140], expected 223, is {}",
                    msg.amplitude_value[140]
                );
                assert_eq!(
                    msg.amplitude_value[141], 172,
                    "incorrect value for amplitude_value[141], expected 172, is {}",
                    msg.amplitude_value[141]
                );
                assert_eq!(
                    msg.amplitude_value[142], 160,
                    "incorrect value for amplitude_value[142], expected 160, is {}",
                    msg.amplitude_value[142]
                );
                assert_eq!(
                    msg.amplitude_value[143], 233,
                    "incorrect value for amplitude_value[143], expected 233, is {}",
                    msg.amplitude_value[143]
                );
                assert_eq!(
                    msg.amplitude_value[144], 220,
                    "incorrect value for amplitude_value[144], expected 220, is {}",
                    msg.amplitude_value[144]
                );
                assert_eq!(
                    msg.amplitude_value[145], 101,
                    "incorrect value for amplitude_value[145], expected 101, is {}",
                    msg.amplitude_value[145]
                );
                assert_eq!(
                    msg.amplitude_value[146], 237,
                    "incorrect value for amplitude_value[146], expected 237, is {}",
                    msg.amplitude_value[146]
                );
                assert_eq!(
                    msg.amplitude_value[147], 156,
                    "incorrect value for amplitude_value[147], expected 156, is {}",
                    msg.amplitude_value[147]
                );
                assert_eq!(
                    msg.amplitude_value[148], 62,
                    "incorrect value for amplitude_value[148], expected 62, is {}",
                    msg.amplitude_value[148]
                );
                assert_eq!(
                    msg.amplitude_value[149], 117,
                    "incorrect value for amplitude_value[149], expected 117, is {}",
                    msg.amplitude_value[149]
                );
                assert_eq!(
                    msg.amplitude_value[150], 47,
                    "incorrect value for amplitude_value[150], expected 47, is {}",
                    msg.amplitude_value[150]
                );
                assert_eq!(
                    msg.amplitude_value[151], 143,
                    "incorrect value for amplitude_value[151], expected 143, is {}",
                    msg.amplitude_value[151]
                );
                assert_eq!(
                    msg.amplitude_value[152], 94,
                    "incorrect value for amplitude_value[152], expected 94, is {}",
                    msg.amplitude_value[152]
                );
                assert_eq!(
                    msg.amplitude_value[153], 135,
                    "incorrect value for amplitude_value[153], expected 135, is {}",
                    msg.amplitude_value[153]
                );
                assert_eq!(
                    msg.amplitude_value[154], 22,
                    "incorrect value for amplitude_value[154], expected 22, is {}",
                    msg.amplitude_value[154]
                );
                assert_eq!(
                    msg.amplitude_value[155], 155,
                    "incorrect value for amplitude_value[155], expected 155, is {}",
                    msg.amplitude_value[155]
                );
                assert_eq!(
                    msg.amplitude_value[156], 113,
                    "incorrect value for amplitude_value[156], expected 113, is {}",
                    msg.amplitude_value[156]
                );
                assert_eq!(
                    msg.amplitude_value[157], 110,
                    "incorrect value for amplitude_value[157], expected 110, is {}",
                    msg.amplitude_value[157]
                );
                assert_eq!(
                    msg.amplitude_value[158], 15,
                    "incorrect value for amplitude_value[158], expected 15, is {}",
                    msg.amplitude_value[158]
                );
                assert_eq!(
                    msg.amplitude_value[159], 243,
                    "incorrect value for amplitude_value[159], expected 243, is {}",
                    msg.amplitude_value[159]
                );
                assert_eq!(
                    msg.amplitude_value[160], 141,
                    "incorrect value for amplitude_value[160], expected 141, is {}",
                    msg.amplitude_value[160]
                );
                assert_eq!(
                    msg.amplitude_value[161], 227,
                    "incorrect value for amplitude_value[161], expected 227, is {}",
                    msg.amplitude_value[161]
                );
                assert_eq!(
                    msg.amplitude_value[162], 46,
                    "incorrect value for amplitude_value[162], expected 46, is {}",
                    msg.amplitude_value[162]
                );
                assert_eq!(
                    msg.amplitude_value[163], 143,
                    "incorrect value for amplitude_value[163], expected 143, is {}",
                    msg.amplitude_value[163]
                );
                assert_eq!(
                    msg.amplitude_value[164], 227,
                    "incorrect value for amplitude_value[164], expected 227, is {}",
                    msg.amplitude_value[164]
                );
                assert_eq!(
                    msg.amplitude_value[165], 209,
                    "incorrect value for amplitude_value[165], expected 209, is {}",
                    msg.amplitude_value[165]
                );
                assert_eq!(
                    msg.amplitude_value[166], 249,
                    "incorrect value for amplitude_value[166], expected 249, is {}",
                    msg.amplitude_value[166]
                );
                assert_eq!(
                    msg.amplitude_value[167], 2,
                    "incorrect value for amplitude_value[167], expected 2, is {}",
                    msg.amplitude_value[167]
                );
                assert_eq!(
                    msg.amplitude_value[168], 153,
                    "incorrect value for amplitude_value[168], expected 153, is {}",
                    msg.amplitude_value[168]
                );
                assert_eq!(
                    msg.amplitude_value[169], 168,
                    "incorrect value for amplitude_value[169], expected 168, is {}",
                    msg.amplitude_value[169]
                );
                assert_eq!(
                    msg.amplitude_value[170], 131,
                    "incorrect value for amplitude_value[170], expected 131, is {}",
                    msg.amplitude_value[170]
                );
                assert_eq!(
                    msg.amplitude_value[171], 249,
                    "incorrect value for amplitude_value[171], expected 249, is {}",
                    msg.amplitude_value[171]
                );
                assert_eq!(
                    msg.amplitude_value[172], 160,
                    "incorrect value for amplitude_value[172], expected 160, is {}",
                    msg.amplitude_value[172]
                );
                assert_eq!(
                    msg.amplitude_value[173], 88,
                    "incorrect value for amplitude_value[173], expected 88, is {}",
                    msg.amplitude_value[173]
                );
                assert_eq!(
                    msg.amplitude_value[174], 38,
                    "incorrect value for amplitude_value[174], expected 38, is {}",
                    msg.amplitude_value[174]
                );
                assert_eq!(
                    msg.amplitude_value[175], 117,
                    "incorrect value for amplitude_value[175], expected 117, is {}",
                    msg.amplitude_value[175]
                );
                assert_eq!(
                    msg.amplitude_value[176], 129,
                    "incorrect value for amplitude_value[176], expected 129, is {}",
                    msg.amplitude_value[176]
                );
                assert_eq!(
                    msg.amplitude_value[177], 57,
                    "incorrect value for amplitude_value[177], expected 57, is {}",
                    msg.amplitude_value[177]
                );
                assert_eq!(
                    msg.amplitude_value[178], 40,
                    "incorrect value for amplitude_value[178], expected 40, is {}",
                    msg.amplitude_value[178]
                );
                assert_eq!(
                    msg.amplitude_value[179], 109,
                    "incorrect value for amplitude_value[179], expected 109, is {}",
                    msg.amplitude_value[179]
                );
                assert_eq!(
                    msg.amplitude_value[180], 209,
                    "incorrect value for amplitude_value[180], expected 209, is {}",
                    msg.amplitude_value[180]
                );
                assert_eq!(
                    msg.amplitude_value[181], 177,
                    "incorrect value for amplitude_value[181], expected 177, is {}",
                    msg.amplitude_value[181]
                );
                assert_eq!(
                    msg.amplitude_value[182], 38,
                    "incorrect value for amplitude_value[182], expected 38, is {}",
                    msg.amplitude_value[182]
                );
                assert_eq!(
                    msg.amplitude_value[183], 47,
                    "incorrect value for amplitude_value[183], expected 47, is {}",
                    msg.amplitude_value[183]
                );
                assert_eq!(
                    msg.amplitude_value[184], 12,
                    "incorrect value for amplitude_value[184], expected 12, is {}",
                    msg.amplitude_value[184]
                );
                assert_eq!(
                    msg.amplitude_value[185], 15,
                    "incorrect value for amplitude_value[185], expected 15, is {}",
                    msg.amplitude_value[185]
                );
                assert_eq!(
                    msg.amplitude_value[186], 16,
                    "incorrect value for amplitude_value[186], expected 16, is {}",
                    msg.amplitude_value[186]
                );
                assert_eq!(
                    msg.amplitude_value[187], 9,
                    "incorrect value for amplitude_value[187], expected 9, is {}",
                    msg.amplitude_value[187]
                );
                assert_eq!(
                    msg.amplitude_value[188], 175,
                    "incorrect value for amplitude_value[188], expected 175, is {}",
                    msg.amplitude_value[188]
                );
                assert_eq!(
                    msg.amplitude_value[189], 69,
                    "incorrect value for amplitude_value[189], expected 69, is {}",
                    msg.amplitude_value[189]
                );
                assert_eq!(
                    msg.amplitude_value[190], 70,
                    "incorrect value for amplitude_value[190], expected 70, is {}",
                    msg.amplitude_value[190]
                );
                assert_eq!(
                    msg.amplitude_value[191], 182,
                    "incorrect value for amplitude_value[191], expected 182, is {}",
                    msg.amplitude_value[191]
                );
                assert_eq!(
                    msg.amplitude_value[192], 239,
                    "incorrect value for amplitude_value[192], expected 239, is {}",
                    msg.amplitude_value[192]
                );
                assert_eq!(
                    msg.amplitude_value[193], 117,
                    "incorrect value for amplitude_value[193], expected 117, is {}",
                    msg.amplitude_value[193]
                );
                assert_eq!(
                    msg.amplitude_value[194], 135,
                    "incorrect value for amplitude_value[194], expected 135, is {}",
                    msg.amplitude_value[194]
                );
                assert_eq!(
                    msg.amplitude_value[195], 6,
                    "incorrect value for amplitude_value[195], expected 6, is {}",
                    msg.amplitude_value[195]
                );
                assert_eq!(
                    msg.amplitude_value[196], 71,
                    "incorrect value for amplitude_value[196], expected 71, is {}",
                    msg.amplitude_value[196]
                );
                assert_eq!(
                    msg.amplitude_value[197], 99,
                    "incorrect value for amplitude_value[197], expected 99, is {}",
                    msg.amplitude_value[197]
                );
                assert_eq!(
                    msg.amplitude_value[198], 230,
                    "incorrect value for amplitude_value[198], expected 230, is {}",
                    msg.amplitude_value[198]
                );
                assert_eq!(
                    msg.amplitude_value[199], 115,
                    "incorrect value for amplitude_value[199], expected 115, is {}",
                    msg.amplitude_value[199]
                );
                assert_eq!(
                    msg.amplitude_value[200], 2,
                    "incorrect value for amplitude_value[200], expected 2, is {}",
                    msg.amplitude_value[200]
                );
                assert_eq!(
                    msg.amplitude_value[201], 71,
                    "incorrect value for amplitude_value[201], expected 71, is {}",
                    msg.amplitude_value[201]
                );
                assert_eq!(
                    msg.amplitude_value[202], 165,
                    "incorrect value for amplitude_value[202], expected 165, is {}",
                    msg.amplitude_value[202]
                );
                assert_eq!(
                    msg.amplitude_value[203], 228,
                    "incorrect value for amplitude_value[203], expected 228, is {}",
                    msg.amplitude_value[203]
                );
                assert_eq!(
                    msg.amplitude_value[204], 123,
                    "incorrect value for amplitude_value[204], expected 123, is {}",
                    msg.amplitude_value[204]
                );
                assert_eq!(
                    msg.amplitude_value[205], 210,
                    "incorrect value for amplitude_value[205], expected 210, is {}",
                    msg.amplitude_value[205]
                );
                assert_eq!(
                    msg.amplitude_value[206], 168,
                    "incorrect value for amplitude_value[206], expected 168, is {}",
                    msg.amplitude_value[206]
                );
                assert_eq!(
                    msg.amplitude_value[207], 90,
                    "incorrect value for amplitude_value[207], expected 90, is {}",
                    msg.amplitude_value[207]
                );
                assert_eq!(
                    msg.amplitude_value[208], 124,
                    "incorrect value for amplitude_value[208], expected 124, is {}",
                    msg.amplitude_value[208]
                );
                assert_eq!(
                    msg.amplitude_value[209], 20,
                    "incorrect value for amplitude_value[209], expected 20, is {}",
                    msg.amplitude_value[209]
                );
                assert_eq!(
                    msg.amplitude_value[210], 7,
                    "incorrect value for amplitude_value[210], expected 7, is {}",
                    msg.amplitude_value[210]
                );
                assert_eq!(
                    msg.amplitude_value[211], 220,
                    "incorrect value for amplitude_value[211], expected 220, is {}",
                    msg.amplitude_value[211]
                );
                assert_eq!(
                    msg.amplitude_value[212], 144,
                    "incorrect value for amplitude_value[212], expected 144, is {}",
                    msg.amplitude_value[212]
                );
                assert_eq!(
                    msg.amplitude_value[213], 168,
                    "incorrect value for amplitude_value[213], expected 168, is {}",
                    msg.amplitude_value[213]
                );
                assert_eq!(
                    msg.amplitude_value[214], 69,
                    "incorrect value for amplitude_value[214], expected 69, is {}",
                    msg.amplitude_value[214]
                );
                assert_eq!(
                    msg.amplitude_value[215], 22,
                    "incorrect value for amplitude_value[215], expected 22, is {}",
                    msg.amplitude_value[215]
                );
                assert_eq!(
                    msg.amplitude_value[216], 72,
                    "incorrect value for amplitude_value[216], expected 72, is {}",
                    msg.amplitude_value[216]
                );
                assert_eq!(
                    msg.amplitude_value[217], 162,
                    "incorrect value for amplitude_value[217], expected 162, is {}",
                    msg.amplitude_value[217]
                );
                assert_eq!(
                    msg.amplitude_value[218], 69,
                    "incorrect value for amplitude_value[218], expected 69, is {}",
                    msg.amplitude_value[218]
                );
                assert_eq!(
                    msg.amplitude_value[219], 111,
                    "incorrect value for amplitude_value[219], expected 111, is {}",
                    msg.amplitude_value[219]
                );
                assert_eq!(
                    msg.amplitude_value[220], 91,
                    "incorrect value for amplitude_value[220], expected 91, is {}",
                    msg.amplitude_value[220]
                );
                assert_eq!(
                    msg.amplitude_value[221], 251,
                    "incorrect value for amplitude_value[221], expected 251, is {}",
                    msg.amplitude_value[221]
                );
                assert_eq!(
                    msg.amplitude_value[222], 72,
                    "incorrect value for amplitude_value[222], expected 72, is {}",
                    msg.amplitude_value[222]
                );
                assert_eq!(
                    msg.amplitude_value[223], 220,
                    "incorrect value for amplitude_value[223], expected 220, is {}",
                    msg.amplitude_value[223]
                );
                assert_eq!(
                    msg.amplitude_value[224], 28,
                    "incorrect value for amplitude_value[224], expected 28, is {}",
                    msg.amplitude_value[224]
                );
                assert_eq!(
                    msg.amplitude_value[225], 119,
                    "incorrect value for amplitude_value[225], expected 119, is {}",
                    msg.amplitude_value[225]
                );
                assert_eq!(
                    msg.amplitude_value[226], 150,
                    "incorrect value for amplitude_value[226], expected 150, is {}",
                    msg.amplitude_value[226]
                );
                assert_eq!(
                    msg.channel_tag, 35146,
                    "incorrect value for channel_tag, expected 35146, is {}",
                    msg.channel_tag
                );
                assert!(
                    msg.freq_ref.almost_eq(7.73720019531250000e+03),
                    "incorrect value for freq_ref, expected 7.73720019531250000e+03, is {:e}",
                    msg.freq_ref
                );
                assert!(
                    msg.freq_step.almost_eq(8.22620019531250000e+03),
                    "incorrect value for freq_step, expected 8.22620019531250000e+03, is {:e}",
                    msg.freq_step
                );
                assert_eq!(
                    msg.t.ns_residual, -1479025396,
                    "incorrect value for t.ns_residual, expected -1479025396, is {}",
                    msg.t.ns_residual
                );
                assert_eq!(
                    msg.t.tow, 1227027783,
                    "incorrect value for t.tow, expected 1227027783, is {}",
                    msg.t.tow
                );
                assert_eq!(
                    msg.t.wn, 5075,
                    "incorrect value for t.wn, expected 5075, is {}",
                    msg.t.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSpecan"),
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
fn test_json2sbp_auto_check_sbp_piksi_msg_specan() {
    {
        let json_input = r#"{"preamble":85,"msg_type":81,"sender":54300,"length":255,"payload":"SolH9SJJDN3Xp9MTmsnxRc2IAEYzQ2xFZiamRGSzuRGvMcHk5C8hGI2xEmP2eT0oW5Hfp64JdAv3VDGZzQLmwtrxZWstiV1y5ivgF0rRx9OCWdyjRBT9B84ygXTCFx/i2Z3N3QXgXFJt38PppQFSjZ2xqfSDYG1v/ZUc4eFInp7SxM5GP+G4lq7wLZI7UsIEs5RC/nNNHi4EzCXIeRIRq2ajrzJCZUUN36yg6dxl7Zw+dS+PXocWm3FuD/ON4y6P49H5Apmog/mgWCZ1gTkobdGxJi8MDxAJr0VGtu91hwZHY+ZzAkel5HvSqFp8FAfckKhFFkiiRW9b+0jcHHeW","crc":607,"channel_tag":35146,"t":{"tow":1227027783,"ns_residual":-1479025396,"wn":5075},"freq_ref":7737.2001953125,"freq_step":8226.2001953125,"amplitude_ref":3780.199951171875,"amplitude_unit":1329.199951171875,"amplitude_value":[100,179,185,17,175,49,193,228,228,47,33,24,141,177,18,99,246,121,61,40,91,145,223,167,174,9,116,11,247,84,49,153,205,2,230,194,218,241,101,107,45,137,93,114,230,43,224,23,74,209,199,211,130,89,220,163,68,20,253,7,206,50,129,116,194,23,31,226,217,157,205,221,5,224,92,82,109,223,195,233,165,1,82,141,157,177,169,244,131,96,109,111,253,149,28,225,225,72,158,158,210,196,206,70,63,225,184,150,174,240,45,146,59,82,194,4,179,148,66,254,115,77,30,46,4,204,37,200,121,18,17,171,102,163,175,50,66,101,69,13,223,172,160,233,220,101,237,156,62,117,47,143,94,135,22,155,113,110,15,243,141,227,46,143,227,209,249,2,153,168,131,249,160,88,38,117,129,57,40,109,209,177,38,47,12,15,16,9,175,69,70,182,239,117,135,6,71,99,230,115,2,71,165,228,123,210,168,90,124,20,7,220,144,168,69,22,72,162,69,111,91,251,72,220,28,119,150]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSpecan(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x51,
                    "Incorrect message type, expected 0x51, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd41c,
                    "incorrect sender id, expected 0xd41c, is {sender_id}"
                );
                assert!(
                    msg.amplitude_ref.almost_eq(3.78019995117187500e+03),
                    "incorrect value for amplitude_ref, expected 3.78019995117187500e+03, is {:e}",
                    msg.amplitude_ref
                );
                assert!(
                    msg.amplitude_unit.almost_eq(1.32919995117187500e+03),
                    "incorrect value for amplitude_unit, expected 1.32919995117187500e+03, is {:e}",
                    msg.amplitude_unit
                );
                assert_eq!(
                    msg.amplitude_value[0], 100,
                    "incorrect value for amplitude_value[0], expected 100, is {}",
                    msg.amplitude_value[0]
                );
                assert_eq!(
                    msg.amplitude_value[1], 179,
                    "incorrect value for amplitude_value[1], expected 179, is {}",
                    msg.amplitude_value[1]
                );
                assert_eq!(
                    msg.amplitude_value[2], 185,
                    "incorrect value for amplitude_value[2], expected 185, is {}",
                    msg.amplitude_value[2]
                );
                assert_eq!(
                    msg.amplitude_value[3], 17,
                    "incorrect value for amplitude_value[3], expected 17, is {}",
                    msg.amplitude_value[3]
                );
                assert_eq!(
                    msg.amplitude_value[4], 175,
                    "incorrect value for amplitude_value[4], expected 175, is {}",
                    msg.amplitude_value[4]
                );
                assert_eq!(
                    msg.amplitude_value[5], 49,
                    "incorrect value for amplitude_value[5], expected 49, is {}",
                    msg.amplitude_value[5]
                );
                assert_eq!(
                    msg.amplitude_value[6], 193,
                    "incorrect value for amplitude_value[6], expected 193, is {}",
                    msg.amplitude_value[6]
                );
                assert_eq!(
                    msg.amplitude_value[7], 228,
                    "incorrect value for amplitude_value[7], expected 228, is {}",
                    msg.amplitude_value[7]
                );
                assert_eq!(
                    msg.amplitude_value[8], 228,
                    "incorrect value for amplitude_value[8], expected 228, is {}",
                    msg.amplitude_value[8]
                );
                assert_eq!(
                    msg.amplitude_value[9], 47,
                    "incorrect value for amplitude_value[9], expected 47, is {}",
                    msg.amplitude_value[9]
                );
                assert_eq!(
                    msg.amplitude_value[10], 33,
                    "incorrect value for amplitude_value[10], expected 33, is {}",
                    msg.amplitude_value[10]
                );
                assert_eq!(
                    msg.amplitude_value[11], 24,
                    "incorrect value for amplitude_value[11], expected 24, is {}",
                    msg.amplitude_value[11]
                );
                assert_eq!(
                    msg.amplitude_value[12], 141,
                    "incorrect value for amplitude_value[12], expected 141, is {}",
                    msg.amplitude_value[12]
                );
                assert_eq!(
                    msg.amplitude_value[13], 177,
                    "incorrect value for amplitude_value[13], expected 177, is {}",
                    msg.amplitude_value[13]
                );
                assert_eq!(
                    msg.amplitude_value[14], 18,
                    "incorrect value for amplitude_value[14], expected 18, is {}",
                    msg.amplitude_value[14]
                );
                assert_eq!(
                    msg.amplitude_value[15], 99,
                    "incorrect value for amplitude_value[15], expected 99, is {}",
                    msg.amplitude_value[15]
                );
                assert_eq!(
                    msg.amplitude_value[16], 246,
                    "incorrect value for amplitude_value[16], expected 246, is {}",
                    msg.amplitude_value[16]
                );
                assert_eq!(
                    msg.amplitude_value[17], 121,
                    "incorrect value for amplitude_value[17], expected 121, is {}",
                    msg.amplitude_value[17]
                );
                assert_eq!(
                    msg.amplitude_value[18], 61,
                    "incorrect value for amplitude_value[18], expected 61, is {}",
                    msg.amplitude_value[18]
                );
                assert_eq!(
                    msg.amplitude_value[19], 40,
                    "incorrect value for amplitude_value[19], expected 40, is {}",
                    msg.amplitude_value[19]
                );
                assert_eq!(
                    msg.amplitude_value[20], 91,
                    "incorrect value for amplitude_value[20], expected 91, is {}",
                    msg.amplitude_value[20]
                );
                assert_eq!(
                    msg.amplitude_value[21], 145,
                    "incorrect value for amplitude_value[21], expected 145, is {}",
                    msg.amplitude_value[21]
                );
                assert_eq!(
                    msg.amplitude_value[22], 223,
                    "incorrect value for amplitude_value[22], expected 223, is {}",
                    msg.amplitude_value[22]
                );
                assert_eq!(
                    msg.amplitude_value[23], 167,
                    "incorrect value for amplitude_value[23], expected 167, is {}",
                    msg.amplitude_value[23]
                );
                assert_eq!(
                    msg.amplitude_value[24], 174,
                    "incorrect value for amplitude_value[24], expected 174, is {}",
                    msg.amplitude_value[24]
                );
                assert_eq!(
                    msg.amplitude_value[25], 9,
                    "incorrect value for amplitude_value[25], expected 9, is {}",
                    msg.amplitude_value[25]
                );
                assert_eq!(
                    msg.amplitude_value[26], 116,
                    "incorrect value for amplitude_value[26], expected 116, is {}",
                    msg.amplitude_value[26]
                );
                assert_eq!(
                    msg.amplitude_value[27], 11,
                    "incorrect value for amplitude_value[27], expected 11, is {}",
                    msg.amplitude_value[27]
                );
                assert_eq!(
                    msg.amplitude_value[28], 247,
                    "incorrect value for amplitude_value[28], expected 247, is {}",
                    msg.amplitude_value[28]
                );
                assert_eq!(
                    msg.amplitude_value[29], 84,
                    "incorrect value for amplitude_value[29], expected 84, is {}",
                    msg.amplitude_value[29]
                );
                assert_eq!(
                    msg.amplitude_value[30], 49,
                    "incorrect value for amplitude_value[30], expected 49, is {}",
                    msg.amplitude_value[30]
                );
                assert_eq!(
                    msg.amplitude_value[31], 153,
                    "incorrect value for amplitude_value[31], expected 153, is {}",
                    msg.amplitude_value[31]
                );
                assert_eq!(
                    msg.amplitude_value[32], 205,
                    "incorrect value for amplitude_value[32], expected 205, is {}",
                    msg.amplitude_value[32]
                );
                assert_eq!(
                    msg.amplitude_value[33], 2,
                    "incorrect value for amplitude_value[33], expected 2, is {}",
                    msg.amplitude_value[33]
                );
                assert_eq!(
                    msg.amplitude_value[34], 230,
                    "incorrect value for amplitude_value[34], expected 230, is {}",
                    msg.amplitude_value[34]
                );
                assert_eq!(
                    msg.amplitude_value[35], 194,
                    "incorrect value for amplitude_value[35], expected 194, is {}",
                    msg.amplitude_value[35]
                );
                assert_eq!(
                    msg.amplitude_value[36], 218,
                    "incorrect value for amplitude_value[36], expected 218, is {}",
                    msg.amplitude_value[36]
                );
                assert_eq!(
                    msg.amplitude_value[37], 241,
                    "incorrect value for amplitude_value[37], expected 241, is {}",
                    msg.amplitude_value[37]
                );
                assert_eq!(
                    msg.amplitude_value[38], 101,
                    "incorrect value for amplitude_value[38], expected 101, is {}",
                    msg.amplitude_value[38]
                );
                assert_eq!(
                    msg.amplitude_value[39], 107,
                    "incorrect value for amplitude_value[39], expected 107, is {}",
                    msg.amplitude_value[39]
                );
                assert_eq!(
                    msg.amplitude_value[40], 45,
                    "incorrect value for amplitude_value[40], expected 45, is {}",
                    msg.amplitude_value[40]
                );
                assert_eq!(
                    msg.amplitude_value[41], 137,
                    "incorrect value for amplitude_value[41], expected 137, is {}",
                    msg.amplitude_value[41]
                );
                assert_eq!(
                    msg.amplitude_value[42], 93,
                    "incorrect value for amplitude_value[42], expected 93, is {}",
                    msg.amplitude_value[42]
                );
                assert_eq!(
                    msg.amplitude_value[43], 114,
                    "incorrect value for amplitude_value[43], expected 114, is {}",
                    msg.amplitude_value[43]
                );
                assert_eq!(
                    msg.amplitude_value[44], 230,
                    "incorrect value for amplitude_value[44], expected 230, is {}",
                    msg.amplitude_value[44]
                );
                assert_eq!(
                    msg.amplitude_value[45], 43,
                    "incorrect value for amplitude_value[45], expected 43, is {}",
                    msg.amplitude_value[45]
                );
                assert_eq!(
                    msg.amplitude_value[46], 224,
                    "incorrect value for amplitude_value[46], expected 224, is {}",
                    msg.amplitude_value[46]
                );
                assert_eq!(
                    msg.amplitude_value[47], 23,
                    "incorrect value for amplitude_value[47], expected 23, is {}",
                    msg.amplitude_value[47]
                );
                assert_eq!(
                    msg.amplitude_value[48], 74,
                    "incorrect value for amplitude_value[48], expected 74, is {}",
                    msg.amplitude_value[48]
                );
                assert_eq!(
                    msg.amplitude_value[49], 209,
                    "incorrect value for amplitude_value[49], expected 209, is {}",
                    msg.amplitude_value[49]
                );
                assert_eq!(
                    msg.amplitude_value[50], 199,
                    "incorrect value for amplitude_value[50], expected 199, is {}",
                    msg.amplitude_value[50]
                );
                assert_eq!(
                    msg.amplitude_value[51], 211,
                    "incorrect value for amplitude_value[51], expected 211, is {}",
                    msg.amplitude_value[51]
                );
                assert_eq!(
                    msg.amplitude_value[52], 130,
                    "incorrect value for amplitude_value[52], expected 130, is {}",
                    msg.amplitude_value[52]
                );
                assert_eq!(
                    msg.amplitude_value[53], 89,
                    "incorrect value for amplitude_value[53], expected 89, is {}",
                    msg.amplitude_value[53]
                );
                assert_eq!(
                    msg.amplitude_value[54], 220,
                    "incorrect value for amplitude_value[54], expected 220, is {}",
                    msg.amplitude_value[54]
                );
                assert_eq!(
                    msg.amplitude_value[55], 163,
                    "incorrect value for amplitude_value[55], expected 163, is {}",
                    msg.amplitude_value[55]
                );
                assert_eq!(
                    msg.amplitude_value[56], 68,
                    "incorrect value for amplitude_value[56], expected 68, is {}",
                    msg.amplitude_value[56]
                );
                assert_eq!(
                    msg.amplitude_value[57], 20,
                    "incorrect value for amplitude_value[57], expected 20, is {}",
                    msg.amplitude_value[57]
                );
                assert_eq!(
                    msg.amplitude_value[58], 253,
                    "incorrect value for amplitude_value[58], expected 253, is {}",
                    msg.amplitude_value[58]
                );
                assert_eq!(
                    msg.amplitude_value[59], 7,
                    "incorrect value for amplitude_value[59], expected 7, is {}",
                    msg.amplitude_value[59]
                );
                assert_eq!(
                    msg.amplitude_value[60], 206,
                    "incorrect value for amplitude_value[60], expected 206, is {}",
                    msg.amplitude_value[60]
                );
                assert_eq!(
                    msg.amplitude_value[61], 50,
                    "incorrect value for amplitude_value[61], expected 50, is {}",
                    msg.amplitude_value[61]
                );
                assert_eq!(
                    msg.amplitude_value[62], 129,
                    "incorrect value for amplitude_value[62], expected 129, is {}",
                    msg.amplitude_value[62]
                );
                assert_eq!(
                    msg.amplitude_value[63], 116,
                    "incorrect value for amplitude_value[63], expected 116, is {}",
                    msg.amplitude_value[63]
                );
                assert_eq!(
                    msg.amplitude_value[64], 194,
                    "incorrect value for amplitude_value[64], expected 194, is {}",
                    msg.amplitude_value[64]
                );
                assert_eq!(
                    msg.amplitude_value[65], 23,
                    "incorrect value for amplitude_value[65], expected 23, is {}",
                    msg.amplitude_value[65]
                );
                assert_eq!(
                    msg.amplitude_value[66], 31,
                    "incorrect value for amplitude_value[66], expected 31, is {}",
                    msg.amplitude_value[66]
                );
                assert_eq!(
                    msg.amplitude_value[67], 226,
                    "incorrect value for amplitude_value[67], expected 226, is {}",
                    msg.amplitude_value[67]
                );
                assert_eq!(
                    msg.amplitude_value[68], 217,
                    "incorrect value for amplitude_value[68], expected 217, is {}",
                    msg.amplitude_value[68]
                );
                assert_eq!(
                    msg.amplitude_value[69], 157,
                    "incorrect value for amplitude_value[69], expected 157, is {}",
                    msg.amplitude_value[69]
                );
                assert_eq!(
                    msg.amplitude_value[70], 205,
                    "incorrect value for amplitude_value[70], expected 205, is {}",
                    msg.amplitude_value[70]
                );
                assert_eq!(
                    msg.amplitude_value[71], 221,
                    "incorrect value for amplitude_value[71], expected 221, is {}",
                    msg.amplitude_value[71]
                );
                assert_eq!(
                    msg.amplitude_value[72], 5,
                    "incorrect value for amplitude_value[72], expected 5, is {}",
                    msg.amplitude_value[72]
                );
                assert_eq!(
                    msg.amplitude_value[73], 224,
                    "incorrect value for amplitude_value[73], expected 224, is {}",
                    msg.amplitude_value[73]
                );
                assert_eq!(
                    msg.amplitude_value[74], 92,
                    "incorrect value for amplitude_value[74], expected 92, is {}",
                    msg.amplitude_value[74]
                );
                assert_eq!(
                    msg.amplitude_value[75], 82,
                    "incorrect value for amplitude_value[75], expected 82, is {}",
                    msg.amplitude_value[75]
                );
                assert_eq!(
                    msg.amplitude_value[76], 109,
                    "incorrect value for amplitude_value[76], expected 109, is {}",
                    msg.amplitude_value[76]
                );
                assert_eq!(
                    msg.amplitude_value[77], 223,
                    "incorrect value for amplitude_value[77], expected 223, is {}",
                    msg.amplitude_value[77]
                );
                assert_eq!(
                    msg.amplitude_value[78], 195,
                    "incorrect value for amplitude_value[78], expected 195, is {}",
                    msg.amplitude_value[78]
                );
                assert_eq!(
                    msg.amplitude_value[79], 233,
                    "incorrect value for amplitude_value[79], expected 233, is {}",
                    msg.amplitude_value[79]
                );
                assert_eq!(
                    msg.amplitude_value[80], 165,
                    "incorrect value for amplitude_value[80], expected 165, is {}",
                    msg.amplitude_value[80]
                );
                assert_eq!(
                    msg.amplitude_value[81], 1,
                    "incorrect value for amplitude_value[81], expected 1, is {}",
                    msg.amplitude_value[81]
                );
                assert_eq!(
                    msg.amplitude_value[82], 82,
                    "incorrect value for amplitude_value[82], expected 82, is {}",
                    msg.amplitude_value[82]
                );
                assert_eq!(
                    msg.amplitude_value[83], 141,
                    "incorrect value for amplitude_value[83], expected 141, is {}",
                    msg.amplitude_value[83]
                );
                assert_eq!(
                    msg.amplitude_value[84], 157,
                    "incorrect value for amplitude_value[84], expected 157, is {}",
                    msg.amplitude_value[84]
                );
                assert_eq!(
                    msg.amplitude_value[85], 177,
                    "incorrect value for amplitude_value[85], expected 177, is {}",
                    msg.amplitude_value[85]
                );
                assert_eq!(
                    msg.amplitude_value[86], 169,
                    "incorrect value for amplitude_value[86], expected 169, is {}",
                    msg.amplitude_value[86]
                );
                assert_eq!(
                    msg.amplitude_value[87], 244,
                    "incorrect value for amplitude_value[87], expected 244, is {}",
                    msg.amplitude_value[87]
                );
                assert_eq!(
                    msg.amplitude_value[88], 131,
                    "incorrect value for amplitude_value[88], expected 131, is {}",
                    msg.amplitude_value[88]
                );
                assert_eq!(
                    msg.amplitude_value[89], 96,
                    "incorrect value for amplitude_value[89], expected 96, is {}",
                    msg.amplitude_value[89]
                );
                assert_eq!(
                    msg.amplitude_value[90], 109,
                    "incorrect value for amplitude_value[90], expected 109, is {}",
                    msg.amplitude_value[90]
                );
                assert_eq!(
                    msg.amplitude_value[91], 111,
                    "incorrect value for amplitude_value[91], expected 111, is {}",
                    msg.amplitude_value[91]
                );
                assert_eq!(
                    msg.amplitude_value[92], 253,
                    "incorrect value for amplitude_value[92], expected 253, is {}",
                    msg.amplitude_value[92]
                );
                assert_eq!(
                    msg.amplitude_value[93], 149,
                    "incorrect value for amplitude_value[93], expected 149, is {}",
                    msg.amplitude_value[93]
                );
                assert_eq!(
                    msg.amplitude_value[94], 28,
                    "incorrect value for amplitude_value[94], expected 28, is {}",
                    msg.amplitude_value[94]
                );
                assert_eq!(
                    msg.amplitude_value[95], 225,
                    "incorrect value for amplitude_value[95], expected 225, is {}",
                    msg.amplitude_value[95]
                );
                assert_eq!(
                    msg.amplitude_value[96], 225,
                    "incorrect value for amplitude_value[96], expected 225, is {}",
                    msg.amplitude_value[96]
                );
                assert_eq!(
                    msg.amplitude_value[97], 72,
                    "incorrect value for amplitude_value[97], expected 72, is {}",
                    msg.amplitude_value[97]
                );
                assert_eq!(
                    msg.amplitude_value[98], 158,
                    "incorrect value for amplitude_value[98], expected 158, is {}",
                    msg.amplitude_value[98]
                );
                assert_eq!(
                    msg.amplitude_value[99], 158,
                    "incorrect value for amplitude_value[99], expected 158, is {}",
                    msg.amplitude_value[99]
                );
                assert_eq!(
                    msg.amplitude_value[100], 210,
                    "incorrect value for amplitude_value[100], expected 210, is {}",
                    msg.amplitude_value[100]
                );
                assert_eq!(
                    msg.amplitude_value[101], 196,
                    "incorrect value for amplitude_value[101], expected 196, is {}",
                    msg.amplitude_value[101]
                );
                assert_eq!(
                    msg.amplitude_value[102], 206,
                    "incorrect value for amplitude_value[102], expected 206, is {}",
                    msg.amplitude_value[102]
                );
                assert_eq!(
                    msg.amplitude_value[103], 70,
                    "incorrect value for amplitude_value[103], expected 70, is {}",
                    msg.amplitude_value[103]
                );
                assert_eq!(
                    msg.amplitude_value[104], 63,
                    "incorrect value for amplitude_value[104], expected 63, is {}",
                    msg.amplitude_value[104]
                );
                assert_eq!(
                    msg.amplitude_value[105], 225,
                    "incorrect value for amplitude_value[105], expected 225, is {}",
                    msg.amplitude_value[105]
                );
                assert_eq!(
                    msg.amplitude_value[106], 184,
                    "incorrect value for amplitude_value[106], expected 184, is {}",
                    msg.amplitude_value[106]
                );
                assert_eq!(
                    msg.amplitude_value[107], 150,
                    "incorrect value for amplitude_value[107], expected 150, is {}",
                    msg.amplitude_value[107]
                );
                assert_eq!(
                    msg.amplitude_value[108], 174,
                    "incorrect value for amplitude_value[108], expected 174, is {}",
                    msg.amplitude_value[108]
                );
                assert_eq!(
                    msg.amplitude_value[109], 240,
                    "incorrect value for amplitude_value[109], expected 240, is {}",
                    msg.amplitude_value[109]
                );
                assert_eq!(
                    msg.amplitude_value[110], 45,
                    "incorrect value for amplitude_value[110], expected 45, is {}",
                    msg.amplitude_value[110]
                );
                assert_eq!(
                    msg.amplitude_value[111], 146,
                    "incorrect value for amplitude_value[111], expected 146, is {}",
                    msg.amplitude_value[111]
                );
                assert_eq!(
                    msg.amplitude_value[112], 59,
                    "incorrect value for amplitude_value[112], expected 59, is {}",
                    msg.amplitude_value[112]
                );
                assert_eq!(
                    msg.amplitude_value[113], 82,
                    "incorrect value for amplitude_value[113], expected 82, is {}",
                    msg.amplitude_value[113]
                );
                assert_eq!(
                    msg.amplitude_value[114], 194,
                    "incorrect value for amplitude_value[114], expected 194, is {}",
                    msg.amplitude_value[114]
                );
                assert_eq!(
                    msg.amplitude_value[115], 4,
                    "incorrect value for amplitude_value[115], expected 4, is {}",
                    msg.amplitude_value[115]
                );
                assert_eq!(
                    msg.amplitude_value[116], 179,
                    "incorrect value for amplitude_value[116], expected 179, is {}",
                    msg.amplitude_value[116]
                );
                assert_eq!(
                    msg.amplitude_value[117], 148,
                    "incorrect value for amplitude_value[117], expected 148, is {}",
                    msg.amplitude_value[117]
                );
                assert_eq!(
                    msg.amplitude_value[118], 66,
                    "incorrect value for amplitude_value[118], expected 66, is {}",
                    msg.amplitude_value[118]
                );
                assert_eq!(
                    msg.amplitude_value[119], 254,
                    "incorrect value for amplitude_value[119], expected 254, is {}",
                    msg.amplitude_value[119]
                );
                assert_eq!(
                    msg.amplitude_value[120], 115,
                    "incorrect value for amplitude_value[120], expected 115, is {}",
                    msg.amplitude_value[120]
                );
                assert_eq!(
                    msg.amplitude_value[121], 77,
                    "incorrect value for amplitude_value[121], expected 77, is {}",
                    msg.amplitude_value[121]
                );
                assert_eq!(
                    msg.amplitude_value[122], 30,
                    "incorrect value for amplitude_value[122], expected 30, is {}",
                    msg.amplitude_value[122]
                );
                assert_eq!(
                    msg.amplitude_value[123], 46,
                    "incorrect value for amplitude_value[123], expected 46, is {}",
                    msg.amplitude_value[123]
                );
                assert_eq!(
                    msg.amplitude_value[124], 4,
                    "incorrect value for amplitude_value[124], expected 4, is {}",
                    msg.amplitude_value[124]
                );
                assert_eq!(
                    msg.amplitude_value[125], 204,
                    "incorrect value for amplitude_value[125], expected 204, is {}",
                    msg.amplitude_value[125]
                );
                assert_eq!(
                    msg.amplitude_value[126], 37,
                    "incorrect value for amplitude_value[126], expected 37, is {}",
                    msg.amplitude_value[126]
                );
                assert_eq!(
                    msg.amplitude_value[127], 200,
                    "incorrect value for amplitude_value[127], expected 200, is {}",
                    msg.amplitude_value[127]
                );
                assert_eq!(
                    msg.amplitude_value[128], 121,
                    "incorrect value for amplitude_value[128], expected 121, is {}",
                    msg.amplitude_value[128]
                );
                assert_eq!(
                    msg.amplitude_value[129], 18,
                    "incorrect value for amplitude_value[129], expected 18, is {}",
                    msg.amplitude_value[129]
                );
                assert_eq!(
                    msg.amplitude_value[130], 17,
                    "incorrect value for amplitude_value[130], expected 17, is {}",
                    msg.amplitude_value[130]
                );
                assert_eq!(
                    msg.amplitude_value[131], 171,
                    "incorrect value for amplitude_value[131], expected 171, is {}",
                    msg.amplitude_value[131]
                );
                assert_eq!(
                    msg.amplitude_value[132], 102,
                    "incorrect value for amplitude_value[132], expected 102, is {}",
                    msg.amplitude_value[132]
                );
                assert_eq!(
                    msg.amplitude_value[133], 163,
                    "incorrect value for amplitude_value[133], expected 163, is {}",
                    msg.amplitude_value[133]
                );
                assert_eq!(
                    msg.amplitude_value[134], 175,
                    "incorrect value for amplitude_value[134], expected 175, is {}",
                    msg.amplitude_value[134]
                );
                assert_eq!(
                    msg.amplitude_value[135], 50,
                    "incorrect value for amplitude_value[135], expected 50, is {}",
                    msg.amplitude_value[135]
                );
                assert_eq!(
                    msg.amplitude_value[136], 66,
                    "incorrect value for amplitude_value[136], expected 66, is {}",
                    msg.amplitude_value[136]
                );
                assert_eq!(
                    msg.amplitude_value[137], 101,
                    "incorrect value for amplitude_value[137], expected 101, is {}",
                    msg.amplitude_value[137]
                );
                assert_eq!(
                    msg.amplitude_value[138], 69,
                    "incorrect value for amplitude_value[138], expected 69, is {}",
                    msg.amplitude_value[138]
                );
                assert_eq!(
                    msg.amplitude_value[139], 13,
                    "incorrect value for amplitude_value[139], expected 13, is {}",
                    msg.amplitude_value[139]
                );
                assert_eq!(
                    msg.amplitude_value[140], 223,
                    "incorrect value for amplitude_value[140], expected 223, is {}",
                    msg.amplitude_value[140]
                );
                assert_eq!(
                    msg.amplitude_value[141], 172,
                    "incorrect value for amplitude_value[141], expected 172, is {}",
                    msg.amplitude_value[141]
                );
                assert_eq!(
                    msg.amplitude_value[142], 160,
                    "incorrect value for amplitude_value[142], expected 160, is {}",
                    msg.amplitude_value[142]
                );
                assert_eq!(
                    msg.amplitude_value[143], 233,
                    "incorrect value for amplitude_value[143], expected 233, is {}",
                    msg.amplitude_value[143]
                );
                assert_eq!(
                    msg.amplitude_value[144], 220,
                    "incorrect value for amplitude_value[144], expected 220, is {}",
                    msg.amplitude_value[144]
                );
                assert_eq!(
                    msg.amplitude_value[145], 101,
                    "incorrect value for amplitude_value[145], expected 101, is {}",
                    msg.amplitude_value[145]
                );
                assert_eq!(
                    msg.amplitude_value[146], 237,
                    "incorrect value for amplitude_value[146], expected 237, is {}",
                    msg.amplitude_value[146]
                );
                assert_eq!(
                    msg.amplitude_value[147], 156,
                    "incorrect value for amplitude_value[147], expected 156, is {}",
                    msg.amplitude_value[147]
                );
                assert_eq!(
                    msg.amplitude_value[148], 62,
                    "incorrect value for amplitude_value[148], expected 62, is {}",
                    msg.amplitude_value[148]
                );
                assert_eq!(
                    msg.amplitude_value[149], 117,
                    "incorrect value for amplitude_value[149], expected 117, is {}",
                    msg.amplitude_value[149]
                );
                assert_eq!(
                    msg.amplitude_value[150], 47,
                    "incorrect value for amplitude_value[150], expected 47, is {}",
                    msg.amplitude_value[150]
                );
                assert_eq!(
                    msg.amplitude_value[151], 143,
                    "incorrect value for amplitude_value[151], expected 143, is {}",
                    msg.amplitude_value[151]
                );
                assert_eq!(
                    msg.amplitude_value[152], 94,
                    "incorrect value for amplitude_value[152], expected 94, is {}",
                    msg.amplitude_value[152]
                );
                assert_eq!(
                    msg.amplitude_value[153], 135,
                    "incorrect value for amplitude_value[153], expected 135, is {}",
                    msg.amplitude_value[153]
                );
                assert_eq!(
                    msg.amplitude_value[154], 22,
                    "incorrect value for amplitude_value[154], expected 22, is {}",
                    msg.amplitude_value[154]
                );
                assert_eq!(
                    msg.amplitude_value[155], 155,
                    "incorrect value for amplitude_value[155], expected 155, is {}",
                    msg.amplitude_value[155]
                );
                assert_eq!(
                    msg.amplitude_value[156], 113,
                    "incorrect value for amplitude_value[156], expected 113, is {}",
                    msg.amplitude_value[156]
                );
                assert_eq!(
                    msg.amplitude_value[157], 110,
                    "incorrect value for amplitude_value[157], expected 110, is {}",
                    msg.amplitude_value[157]
                );
                assert_eq!(
                    msg.amplitude_value[158], 15,
                    "incorrect value for amplitude_value[158], expected 15, is {}",
                    msg.amplitude_value[158]
                );
                assert_eq!(
                    msg.amplitude_value[159], 243,
                    "incorrect value for amplitude_value[159], expected 243, is {}",
                    msg.amplitude_value[159]
                );
                assert_eq!(
                    msg.amplitude_value[160], 141,
                    "incorrect value for amplitude_value[160], expected 141, is {}",
                    msg.amplitude_value[160]
                );
                assert_eq!(
                    msg.amplitude_value[161], 227,
                    "incorrect value for amplitude_value[161], expected 227, is {}",
                    msg.amplitude_value[161]
                );
                assert_eq!(
                    msg.amplitude_value[162], 46,
                    "incorrect value for amplitude_value[162], expected 46, is {}",
                    msg.amplitude_value[162]
                );
                assert_eq!(
                    msg.amplitude_value[163], 143,
                    "incorrect value for amplitude_value[163], expected 143, is {}",
                    msg.amplitude_value[163]
                );
                assert_eq!(
                    msg.amplitude_value[164], 227,
                    "incorrect value for amplitude_value[164], expected 227, is {}",
                    msg.amplitude_value[164]
                );
                assert_eq!(
                    msg.amplitude_value[165], 209,
                    "incorrect value for amplitude_value[165], expected 209, is {}",
                    msg.amplitude_value[165]
                );
                assert_eq!(
                    msg.amplitude_value[166], 249,
                    "incorrect value for amplitude_value[166], expected 249, is {}",
                    msg.amplitude_value[166]
                );
                assert_eq!(
                    msg.amplitude_value[167], 2,
                    "incorrect value for amplitude_value[167], expected 2, is {}",
                    msg.amplitude_value[167]
                );
                assert_eq!(
                    msg.amplitude_value[168], 153,
                    "incorrect value for amplitude_value[168], expected 153, is {}",
                    msg.amplitude_value[168]
                );
                assert_eq!(
                    msg.amplitude_value[169], 168,
                    "incorrect value for amplitude_value[169], expected 168, is {}",
                    msg.amplitude_value[169]
                );
                assert_eq!(
                    msg.amplitude_value[170], 131,
                    "incorrect value for amplitude_value[170], expected 131, is {}",
                    msg.amplitude_value[170]
                );
                assert_eq!(
                    msg.amplitude_value[171], 249,
                    "incorrect value for amplitude_value[171], expected 249, is {}",
                    msg.amplitude_value[171]
                );
                assert_eq!(
                    msg.amplitude_value[172], 160,
                    "incorrect value for amplitude_value[172], expected 160, is {}",
                    msg.amplitude_value[172]
                );
                assert_eq!(
                    msg.amplitude_value[173], 88,
                    "incorrect value for amplitude_value[173], expected 88, is {}",
                    msg.amplitude_value[173]
                );
                assert_eq!(
                    msg.amplitude_value[174], 38,
                    "incorrect value for amplitude_value[174], expected 38, is {}",
                    msg.amplitude_value[174]
                );
                assert_eq!(
                    msg.amplitude_value[175], 117,
                    "incorrect value for amplitude_value[175], expected 117, is {}",
                    msg.amplitude_value[175]
                );
                assert_eq!(
                    msg.amplitude_value[176], 129,
                    "incorrect value for amplitude_value[176], expected 129, is {}",
                    msg.amplitude_value[176]
                );
                assert_eq!(
                    msg.amplitude_value[177], 57,
                    "incorrect value for amplitude_value[177], expected 57, is {}",
                    msg.amplitude_value[177]
                );
                assert_eq!(
                    msg.amplitude_value[178], 40,
                    "incorrect value for amplitude_value[178], expected 40, is {}",
                    msg.amplitude_value[178]
                );
                assert_eq!(
                    msg.amplitude_value[179], 109,
                    "incorrect value for amplitude_value[179], expected 109, is {}",
                    msg.amplitude_value[179]
                );
                assert_eq!(
                    msg.amplitude_value[180], 209,
                    "incorrect value for amplitude_value[180], expected 209, is {}",
                    msg.amplitude_value[180]
                );
                assert_eq!(
                    msg.amplitude_value[181], 177,
                    "incorrect value for amplitude_value[181], expected 177, is {}",
                    msg.amplitude_value[181]
                );
                assert_eq!(
                    msg.amplitude_value[182], 38,
                    "incorrect value for amplitude_value[182], expected 38, is {}",
                    msg.amplitude_value[182]
                );
                assert_eq!(
                    msg.amplitude_value[183], 47,
                    "incorrect value for amplitude_value[183], expected 47, is {}",
                    msg.amplitude_value[183]
                );
                assert_eq!(
                    msg.amplitude_value[184], 12,
                    "incorrect value for amplitude_value[184], expected 12, is {}",
                    msg.amplitude_value[184]
                );
                assert_eq!(
                    msg.amplitude_value[185], 15,
                    "incorrect value for amplitude_value[185], expected 15, is {}",
                    msg.amplitude_value[185]
                );
                assert_eq!(
                    msg.amplitude_value[186], 16,
                    "incorrect value for amplitude_value[186], expected 16, is {}",
                    msg.amplitude_value[186]
                );
                assert_eq!(
                    msg.amplitude_value[187], 9,
                    "incorrect value for amplitude_value[187], expected 9, is {}",
                    msg.amplitude_value[187]
                );
                assert_eq!(
                    msg.amplitude_value[188], 175,
                    "incorrect value for amplitude_value[188], expected 175, is {}",
                    msg.amplitude_value[188]
                );
                assert_eq!(
                    msg.amplitude_value[189], 69,
                    "incorrect value for amplitude_value[189], expected 69, is {}",
                    msg.amplitude_value[189]
                );
                assert_eq!(
                    msg.amplitude_value[190], 70,
                    "incorrect value for amplitude_value[190], expected 70, is {}",
                    msg.amplitude_value[190]
                );
                assert_eq!(
                    msg.amplitude_value[191], 182,
                    "incorrect value for amplitude_value[191], expected 182, is {}",
                    msg.amplitude_value[191]
                );
                assert_eq!(
                    msg.amplitude_value[192], 239,
                    "incorrect value for amplitude_value[192], expected 239, is {}",
                    msg.amplitude_value[192]
                );
                assert_eq!(
                    msg.amplitude_value[193], 117,
                    "incorrect value for amplitude_value[193], expected 117, is {}",
                    msg.amplitude_value[193]
                );
                assert_eq!(
                    msg.amplitude_value[194], 135,
                    "incorrect value for amplitude_value[194], expected 135, is {}",
                    msg.amplitude_value[194]
                );
                assert_eq!(
                    msg.amplitude_value[195], 6,
                    "incorrect value for amplitude_value[195], expected 6, is {}",
                    msg.amplitude_value[195]
                );
                assert_eq!(
                    msg.amplitude_value[196], 71,
                    "incorrect value for amplitude_value[196], expected 71, is {}",
                    msg.amplitude_value[196]
                );
                assert_eq!(
                    msg.amplitude_value[197], 99,
                    "incorrect value for amplitude_value[197], expected 99, is {}",
                    msg.amplitude_value[197]
                );
                assert_eq!(
                    msg.amplitude_value[198], 230,
                    "incorrect value for amplitude_value[198], expected 230, is {}",
                    msg.amplitude_value[198]
                );
                assert_eq!(
                    msg.amplitude_value[199], 115,
                    "incorrect value for amplitude_value[199], expected 115, is {}",
                    msg.amplitude_value[199]
                );
                assert_eq!(
                    msg.amplitude_value[200], 2,
                    "incorrect value for amplitude_value[200], expected 2, is {}",
                    msg.amplitude_value[200]
                );
                assert_eq!(
                    msg.amplitude_value[201], 71,
                    "incorrect value for amplitude_value[201], expected 71, is {}",
                    msg.amplitude_value[201]
                );
                assert_eq!(
                    msg.amplitude_value[202], 165,
                    "incorrect value for amplitude_value[202], expected 165, is {}",
                    msg.amplitude_value[202]
                );
                assert_eq!(
                    msg.amplitude_value[203], 228,
                    "incorrect value for amplitude_value[203], expected 228, is {}",
                    msg.amplitude_value[203]
                );
                assert_eq!(
                    msg.amplitude_value[204], 123,
                    "incorrect value for amplitude_value[204], expected 123, is {}",
                    msg.amplitude_value[204]
                );
                assert_eq!(
                    msg.amplitude_value[205], 210,
                    "incorrect value for amplitude_value[205], expected 210, is {}",
                    msg.amplitude_value[205]
                );
                assert_eq!(
                    msg.amplitude_value[206], 168,
                    "incorrect value for amplitude_value[206], expected 168, is {}",
                    msg.amplitude_value[206]
                );
                assert_eq!(
                    msg.amplitude_value[207], 90,
                    "incorrect value for amplitude_value[207], expected 90, is {}",
                    msg.amplitude_value[207]
                );
                assert_eq!(
                    msg.amplitude_value[208], 124,
                    "incorrect value for amplitude_value[208], expected 124, is {}",
                    msg.amplitude_value[208]
                );
                assert_eq!(
                    msg.amplitude_value[209], 20,
                    "incorrect value for amplitude_value[209], expected 20, is {}",
                    msg.amplitude_value[209]
                );
                assert_eq!(
                    msg.amplitude_value[210], 7,
                    "incorrect value for amplitude_value[210], expected 7, is {}",
                    msg.amplitude_value[210]
                );
                assert_eq!(
                    msg.amplitude_value[211], 220,
                    "incorrect value for amplitude_value[211], expected 220, is {}",
                    msg.amplitude_value[211]
                );
                assert_eq!(
                    msg.amplitude_value[212], 144,
                    "incorrect value for amplitude_value[212], expected 144, is {}",
                    msg.amplitude_value[212]
                );
                assert_eq!(
                    msg.amplitude_value[213], 168,
                    "incorrect value for amplitude_value[213], expected 168, is {}",
                    msg.amplitude_value[213]
                );
                assert_eq!(
                    msg.amplitude_value[214], 69,
                    "incorrect value for amplitude_value[214], expected 69, is {}",
                    msg.amplitude_value[214]
                );
                assert_eq!(
                    msg.amplitude_value[215], 22,
                    "incorrect value for amplitude_value[215], expected 22, is {}",
                    msg.amplitude_value[215]
                );
                assert_eq!(
                    msg.amplitude_value[216], 72,
                    "incorrect value for amplitude_value[216], expected 72, is {}",
                    msg.amplitude_value[216]
                );
                assert_eq!(
                    msg.amplitude_value[217], 162,
                    "incorrect value for amplitude_value[217], expected 162, is {}",
                    msg.amplitude_value[217]
                );
                assert_eq!(
                    msg.amplitude_value[218], 69,
                    "incorrect value for amplitude_value[218], expected 69, is {}",
                    msg.amplitude_value[218]
                );
                assert_eq!(
                    msg.amplitude_value[219], 111,
                    "incorrect value for amplitude_value[219], expected 111, is {}",
                    msg.amplitude_value[219]
                );
                assert_eq!(
                    msg.amplitude_value[220], 91,
                    "incorrect value for amplitude_value[220], expected 91, is {}",
                    msg.amplitude_value[220]
                );
                assert_eq!(
                    msg.amplitude_value[221], 251,
                    "incorrect value for amplitude_value[221], expected 251, is {}",
                    msg.amplitude_value[221]
                );
                assert_eq!(
                    msg.amplitude_value[222], 72,
                    "incorrect value for amplitude_value[222], expected 72, is {}",
                    msg.amplitude_value[222]
                );
                assert_eq!(
                    msg.amplitude_value[223], 220,
                    "incorrect value for amplitude_value[223], expected 220, is {}",
                    msg.amplitude_value[223]
                );
                assert_eq!(
                    msg.amplitude_value[224], 28,
                    "incorrect value for amplitude_value[224], expected 28, is {}",
                    msg.amplitude_value[224]
                );
                assert_eq!(
                    msg.amplitude_value[225], 119,
                    "incorrect value for amplitude_value[225], expected 119, is {}",
                    msg.amplitude_value[225]
                );
                assert_eq!(
                    msg.amplitude_value[226], 150,
                    "incorrect value for amplitude_value[226], expected 150, is {}",
                    msg.amplitude_value[226]
                );
                assert_eq!(
                    msg.channel_tag, 35146,
                    "incorrect value for channel_tag, expected 35146, is {}",
                    msg.channel_tag
                );
                assert!(
                    msg.freq_ref.almost_eq(7.73720019531250000e+03),
                    "incorrect value for freq_ref, expected 7.73720019531250000e+03, is {:e}",
                    msg.freq_ref
                );
                assert!(
                    msg.freq_step.almost_eq(8.22620019531250000e+03),
                    "incorrect value for freq_step, expected 8.22620019531250000e+03, is {:e}",
                    msg.freq_step
                );
                assert_eq!(
                    msg.t.ns_residual, -1479025396,
                    "incorrect value for t.ns_residual, expected -1479025396, is {}",
                    msg.t.ns_residual
                );
                assert_eq!(
                    msg.t.tow, 1227027783,
                    "incorrect value for t.tow, expected 1227027783, is {}",
                    msg.t.tow
                );
                assert_eq!(
                    msg.t.wn, 5075,
                    "incorrect value for t.wn, expected 5075, is {}",
                    msg.t.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSpecan"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_piksi_msg_specan`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_piksi_msg_specan() {
    {
        let mut payload = Cursor::new(vec![
            85, 81, 0, 28, 212, 255, 74, 137, 71, 245, 34, 73, 12, 221, 215, 167, 211, 19, 154,
            201, 241, 69, 205, 136, 0, 70, 51, 67, 108, 69, 102, 38, 166, 68, 100, 179, 185, 17,
            175, 49, 193, 228, 228, 47, 33, 24, 141, 177, 18, 99, 246, 121, 61, 40, 91, 145, 223,
            167, 174, 9, 116, 11, 247, 84, 49, 153, 205, 2, 230, 194, 218, 241, 101, 107, 45, 137,
            93, 114, 230, 43, 224, 23, 74, 209, 199, 211, 130, 89, 220, 163, 68, 20, 253, 7, 206,
            50, 129, 116, 194, 23, 31, 226, 217, 157, 205, 221, 5, 224, 92, 82, 109, 223, 195, 233,
            165, 1, 82, 141, 157, 177, 169, 244, 131, 96, 109, 111, 253, 149, 28, 225, 225, 72,
            158, 158, 210, 196, 206, 70, 63, 225, 184, 150, 174, 240, 45, 146, 59, 82, 194, 4, 179,
            148, 66, 254, 115, 77, 30, 46, 4, 204, 37, 200, 121, 18, 17, 171, 102, 163, 175, 50,
            66, 101, 69, 13, 223, 172, 160, 233, 220, 101, 237, 156, 62, 117, 47, 143, 94, 135, 22,
            155, 113, 110, 15, 243, 141, 227, 46, 143, 227, 209, 249, 2, 153, 168, 131, 249, 160,
            88, 38, 117, 129, 57, 40, 109, 209, 177, 38, 47, 12, 15, 16, 9, 175, 69, 70, 182, 239,
            117, 135, 6, 71, 99, 230, 115, 2, 71, 165, 228, 123, 210, 168, 90, 124, 20, 7, 220,
            144, 168, 69, 22, 72, 162, 69, 111, 91, 251, 72, 220, 28, 119, 150, 95, 2,
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
        let sbp_msg = sbp::messages::Sbp::MsgSpecan(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSpecan(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x51,
                    "Incorrect message type, expected 0x51, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd41c,
                    "incorrect sender id, expected 0xd41c, is {sender_id}"
                );
                assert!(
                    msg.amplitude_ref.almost_eq(3.78019995117187500e+03),
                    "incorrect value for amplitude_ref, expected 3.78019995117187500e+03, is {:e}",
                    msg.amplitude_ref
                );
                assert!(
                    msg.amplitude_unit.almost_eq(1.32919995117187500e+03),
                    "incorrect value for amplitude_unit, expected 1.32919995117187500e+03, is {:e}",
                    msg.amplitude_unit
                );
                assert_eq!(
                    msg.amplitude_value[0], 100,
                    "incorrect value for amplitude_value[0], expected 100, is {}",
                    msg.amplitude_value[0]
                );
                assert_eq!(
                    msg.amplitude_value[1], 179,
                    "incorrect value for amplitude_value[1], expected 179, is {}",
                    msg.amplitude_value[1]
                );
                assert_eq!(
                    msg.amplitude_value[2], 185,
                    "incorrect value for amplitude_value[2], expected 185, is {}",
                    msg.amplitude_value[2]
                );
                assert_eq!(
                    msg.amplitude_value[3], 17,
                    "incorrect value for amplitude_value[3], expected 17, is {}",
                    msg.amplitude_value[3]
                );
                assert_eq!(
                    msg.amplitude_value[4], 175,
                    "incorrect value for amplitude_value[4], expected 175, is {}",
                    msg.amplitude_value[4]
                );
                assert_eq!(
                    msg.amplitude_value[5], 49,
                    "incorrect value for amplitude_value[5], expected 49, is {}",
                    msg.amplitude_value[5]
                );
                assert_eq!(
                    msg.amplitude_value[6], 193,
                    "incorrect value for amplitude_value[6], expected 193, is {}",
                    msg.amplitude_value[6]
                );
                assert_eq!(
                    msg.amplitude_value[7], 228,
                    "incorrect value for amplitude_value[7], expected 228, is {}",
                    msg.amplitude_value[7]
                );
                assert_eq!(
                    msg.amplitude_value[8], 228,
                    "incorrect value for amplitude_value[8], expected 228, is {}",
                    msg.amplitude_value[8]
                );
                assert_eq!(
                    msg.amplitude_value[9], 47,
                    "incorrect value for amplitude_value[9], expected 47, is {}",
                    msg.amplitude_value[9]
                );
                assert_eq!(
                    msg.amplitude_value[10], 33,
                    "incorrect value for amplitude_value[10], expected 33, is {}",
                    msg.amplitude_value[10]
                );
                assert_eq!(
                    msg.amplitude_value[11], 24,
                    "incorrect value for amplitude_value[11], expected 24, is {}",
                    msg.amplitude_value[11]
                );
                assert_eq!(
                    msg.amplitude_value[12], 141,
                    "incorrect value for amplitude_value[12], expected 141, is {}",
                    msg.amplitude_value[12]
                );
                assert_eq!(
                    msg.amplitude_value[13], 177,
                    "incorrect value for amplitude_value[13], expected 177, is {}",
                    msg.amplitude_value[13]
                );
                assert_eq!(
                    msg.amplitude_value[14], 18,
                    "incorrect value for amplitude_value[14], expected 18, is {}",
                    msg.amplitude_value[14]
                );
                assert_eq!(
                    msg.amplitude_value[15], 99,
                    "incorrect value for amplitude_value[15], expected 99, is {}",
                    msg.amplitude_value[15]
                );
                assert_eq!(
                    msg.amplitude_value[16], 246,
                    "incorrect value for amplitude_value[16], expected 246, is {}",
                    msg.amplitude_value[16]
                );
                assert_eq!(
                    msg.amplitude_value[17], 121,
                    "incorrect value for amplitude_value[17], expected 121, is {}",
                    msg.amplitude_value[17]
                );
                assert_eq!(
                    msg.amplitude_value[18], 61,
                    "incorrect value for amplitude_value[18], expected 61, is {}",
                    msg.amplitude_value[18]
                );
                assert_eq!(
                    msg.amplitude_value[19], 40,
                    "incorrect value for amplitude_value[19], expected 40, is {}",
                    msg.amplitude_value[19]
                );
                assert_eq!(
                    msg.amplitude_value[20], 91,
                    "incorrect value for amplitude_value[20], expected 91, is {}",
                    msg.amplitude_value[20]
                );
                assert_eq!(
                    msg.amplitude_value[21], 145,
                    "incorrect value for amplitude_value[21], expected 145, is {}",
                    msg.amplitude_value[21]
                );
                assert_eq!(
                    msg.amplitude_value[22], 223,
                    "incorrect value for amplitude_value[22], expected 223, is {}",
                    msg.amplitude_value[22]
                );
                assert_eq!(
                    msg.amplitude_value[23], 167,
                    "incorrect value for amplitude_value[23], expected 167, is {}",
                    msg.amplitude_value[23]
                );
                assert_eq!(
                    msg.amplitude_value[24], 174,
                    "incorrect value for amplitude_value[24], expected 174, is {}",
                    msg.amplitude_value[24]
                );
                assert_eq!(
                    msg.amplitude_value[25], 9,
                    "incorrect value for amplitude_value[25], expected 9, is {}",
                    msg.amplitude_value[25]
                );
                assert_eq!(
                    msg.amplitude_value[26], 116,
                    "incorrect value for amplitude_value[26], expected 116, is {}",
                    msg.amplitude_value[26]
                );
                assert_eq!(
                    msg.amplitude_value[27], 11,
                    "incorrect value for amplitude_value[27], expected 11, is {}",
                    msg.amplitude_value[27]
                );
                assert_eq!(
                    msg.amplitude_value[28], 247,
                    "incorrect value for amplitude_value[28], expected 247, is {}",
                    msg.amplitude_value[28]
                );
                assert_eq!(
                    msg.amplitude_value[29], 84,
                    "incorrect value for amplitude_value[29], expected 84, is {}",
                    msg.amplitude_value[29]
                );
                assert_eq!(
                    msg.amplitude_value[30], 49,
                    "incorrect value for amplitude_value[30], expected 49, is {}",
                    msg.amplitude_value[30]
                );
                assert_eq!(
                    msg.amplitude_value[31], 153,
                    "incorrect value for amplitude_value[31], expected 153, is {}",
                    msg.amplitude_value[31]
                );
                assert_eq!(
                    msg.amplitude_value[32], 205,
                    "incorrect value for amplitude_value[32], expected 205, is {}",
                    msg.amplitude_value[32]
                );
                assert_eq!(
                    msg.amplitude_value[33], 2,
                    "incorrect value for amplitude_value[33], expected 2, is {}",
                    msg.amplitude_value[33]
                );
                assert_eq!(
                    msg.amplitude_value[34], 230,
                    "incorrect value for amplitude_value[34], expected 230, is {}",
                    msg.amplitude_value[34]
                );
                assert_eq!(
                    msg.amplitude_value[35], 194,
                    "incorrect value for amplitude_value[35], expected 194, is {}",
                    msg.amplitude_value[35]
                );
                assert_eq!(
                    msg.amplitude_value[36], 218,
                    "incorrect value for amplitude_value[36], expected 218, is {}",
                    msg.amplitude_value[36]
                );
                assert_eq!(
                    msg.amplitude_value[37], 241,
                    "incorrect value for amplitude_value[37], expected 241, is {}",
                    msg.amplitude_value[37]
                );
                assert_eq!(
                    msg.amplitude_value[38], 101,
                    "incorrect value for amplitude_value[38], expected 101, is {}",
                    msg.amplitude_value[38]
                );
                assert_eq!(
                    msg.amplitude_value[39], 107,
                    "incorrect value for amplitude_value[39], expected 107, is {}",
                    msg.amplitude_value[39]
                );
                assert_eq!(
                    msg.amplitude_value[40], 45,
                    "incorrect value for amplitude_value[40], expected 45, is {}",
                    msg.amplitude_value[40]
                );
                assert_eq!(
                    msg.amplitude_value[41], 137,
                    "incorrect value for amplitude_value[41], expected 137, is {}",
                    msg.amplitude_value[41]
                );
                assert_eq!(
                    msg.amplitude_value[42], 93,
                    "incorrect value for amplitude_value[42], expected 93, is {}",
                    msg.amplitude_value[42]
                );
                assert_eq!(
                    msg.amplitude_value[43], 114,
                    "incorrect value for amplitude_value[43], expected 114, is {}",
                    msg.amplitude_value[43]
                );
                assert_eq!(
                    msg.amplitude_value[44], 230,
                    "incorrect value for amplitude_value[44], expected 230, is {}",
                    msg.amplitude_value[44]
                );
                assert_eq!(
                    msg.amplitude_value[45], 43,
                    "incorrect value for amplitude_value[45], expected 43, is {}",
                    msg.amplitude_value[45]
                );
                assert_eq!(
                    msg.amplitude_value[46], 224,
                    "incorrect value for amplitude_value[46], expected 224, is {}",
                    msg.amplitude_value[46]
                );
                assert_eq!(
                    msg.amplitude_value[47], 23,
                    "incorrect value for amplitude_value[47], expected 23, is {}",
                    msg.amplitude_value[47]
                );
                assert_eq!(
                    msg.amplitude_value[48], 74,
                    "incorrect value for amplitude_value[48], expected 74, is {}",
                    msg.amplitude_value[48]
                );
                assert_eq!(
                    msg.amplitude_value[49], 209,
                    "incorrect value for amplitude_value[49], expected 209, is {}",
                    msg.amplitude_value[49]
                );
                assert_eq!(
                    msg.amplitude_value[50], 199,
                    "incorrect value for amplitude_value[50], expected 199, is {}",
                    msg.amplitude_value[50]
                );
                assert_eq!(
                    msg.amplitude_value[51], 211,
                    "incorrect value for amplitude_value[51], expected 211, is {}",
                    msg.amplitude_value[51]
                );
                assert_eq!(
                    msg.amplitude_value[52], 130,
                    "incorrect value for amplitude_value[52], expected 130, is {}",
                    msg.amplitude_value[52]
                );
                assert_eq!(
                    msg.amplitude_value[53], 89,
                    "incorrect value for amplitude_value[53], expected 89, is {}",
                    msg.amplitude_value[53]
                );
                assert_eq!(
                    msg.amplitude_value[54], 220,
                    "incorrect value for amplitude_value[54], expected 220, is {}",
                    msg.amplitude_value[54]
                );
                assert_eq!(
                    msg.amplitude_value[55], 163,
                    "incorrect value for amplitude_value[55], expected 163, is {}",
                    msg.amplitude_value[55]
                );
                assert_eq!(
                    msg.amplitude_value[56], 68,
                    "incorrect value for amplitude_value[56], expected 68, is {}",
                    msg.amplitude_value[56]
                );
                assert_eq!(
                    msg.amplitude_value[57], 20,
                    "incorrect value for amplitude_value[57], expected 20, is {}",
                    msg.amplitude_value[57]
                );
                assert_eq!(
                    msg.amplitude_value[58], 253,
                    "incorrect value for amplitude_value[58], expected 253, is {}",
                    msg.amplitude_value[58]
                );
                assert_eq!(
                    msg.amplitude_value[59], 7,
                    "incorrect value for amplitude_value[59], expected 7, is {}",
                    msg.amplitude_value[59]
                );
                assert_eq!(
                    msg.amplitude_value[60], 206,
                    "incorrect value for amplitude_value[60], expected 206, is {}",
                    msg.amplitude_value[60]
                );
                assert_eq!(
                    msg.amplitude_value[61], 50,
                    "incorrect value for amplitude_value[61], expected 50, is {}",
                    msg.amplitude_value[61]
                );
                assert_eq!(
                    msg.amplitude_value[62], 129,
                    "incorrect value for amplitude_value[62], expected 129, is {}",
                    msg.amplitude_value[62]
                );
                assert_eq!(
                    msg.amplitude_value[63], 116,
                    "incorrect value for amplitude_value[63], expected 116, is {}",
                    msg.amplitude_value[63]
                );
                assert_eq!(
                    msg.amplitude_value[64], 194,
                    "incorrect value for amplitude_value[64], expected 194, is {}",
                    msg.amplitude_value[64]
                );
                assert_eq!(
                    msg.amplitude_value[65], 23,
                    "incorrect value for amplitude_value[65], expected 23, is {}",
                    msg.amplitude_value[65]
                );
                assert_eq!(
                    msg.amplitude_value[66], 31,
                    "incorrect value for amplitude_value[66], expected 31, is {}",
                    msg.amplitude_value[66]
                );
                assert_eq!(
                    msg.amplitude_value[67], 226,
                    "incorrect value for amplitude_value[67], expected 226, is {}",
                    msg.amplitude_value[67]
                );
                assert_eq!(
                    msg.amplitude_value[68], 217,
                    "incorrect value for amplitude_value[68], expected 217, is {}",
                    msg.amplitude_value[68]
                );
                assert_eq!(
                    msg.amplitude_value[69], 157,
                    "incorrect value for amplitude_value[69], expected 157, is {}",
                    msg.amplitude_value[69]
                );
                assert_eq!(
                    msg.amplitude_value[70], 205,
                    "incorrect value for amplitude_value[70], expected 205, is {}",
                    msg.amplitude_value[70]
                );
                assert_eq!(
                    msg.amplitude_value[71], 221,
                    "incorrect value for amplitude_value[71], expected 221, is {}",
                    msg.amplitude_value[71]
                );
                assert_eq!(
                    msg.amplitude_value[72], 5,
                    "incorrect value for amplitude_value[72], expected 5, is {}",
                    msg.amplitude_value[72]
                );
                assert_eq!(
                    msg.amplitude_value[73], 224,
                    "incorrect value for amplitude_value[73], expected 224, is {}",
                    msg.amplitude_value[73]
                );
                assert_eq!(
                    msg.amplitude_value[74], 92,
                    "incorrect value for amplitude_value[74], expected 92, is {}",
                    msg.amplitude_value[74]
                );
                assert_eq!(
                    msg.amplitude_value[75], 82,
                    "incorrect value for amplitude_value[75], expected 82, is {}",
                    msg.amplitude_value[75]
                );
                assert_eq!(
                    msg.amplitude_value[76], 109,
                    "incorrect value for amplitude_value[76], expected 109, is {}",
                    msg.amplitude_value[76]
                );
                assert_eq!(
                    msg.amplitude_value[77], 223,
                    "incorrect value for amplitude_value[77], expected 223, is {}",
                    msg.amplitude_value[77]
                );
                assert_eq!(
                    msg.amplitude_value[78], 195,
                    "incorrect value for amplitude_value[78], expected 195, is {}",
                    msg.amplitude_value[78]
                );
                assert_eq!(
                    msg.amplitude_value[79], 233,
                    "incorrect value for amplitude_value[79], expected 233, is {}",
                    msg.amplitude_value[79]
                );
                assert_eq!(
                    msg.amplitude_value[80], 165,
                    "incorrect value for amplitude_value[80], expected 165, is {}",
                    msg.amplitude_value[80]
                );
                assert_eq!(
                    msg.amplitude_value[81], 1,
                    "incorrect value for amplitude_value[81], expected 1, is {}",
                    msg.amplitude_value[81]
                );
                assert_eq!(
                    msg.amplitude_value[82], 82,
                    "incorrect value for amplitude_value[82], expected 82, is {}",
                    msg.amplitude_value[82]
                );
                assert_eq!(
                    msg.amplitude_value[83], 141,
                    "incorrect value for amplitude_value[83], expected 141, is {}",
                    msg.amplitude_value[83]
                );
                assert_eq!(
                    msg.amplitude_value[84], 157,
                    "incorrect value for amplitude_value[84], expected 157, is {}",
                    msg.amplitude_value[84]
                );
                assert_eq!(
                    msg.amplitude_value[85], 177,
                    "incorrect value for amplitude_value[85], expected 177, is {}",
                    msg.amplitude_value[85]
                );
                assert_eq!(
                    msg.amplitude_value[86], 169,
                    "incorrect value for amplitude_value[86], expected 169, is {}",
                    msg.amplitude_value[86]
                );
                assert_eq!(
                    msg.amplitude_value[87], 244,
                    "incorrect value for amplitude_value[87], expected 244, is {}",
                    msg.amplitude_value[87]
                );
                assert_eq!(
                    msg.amplitude_value[88], 131,
                    "incorrect value for amplitude_value[88], expected 131, is {}",
                    msg.amplitude_value[88]
                );
                assert_eq!(
                    msg.amplitude_value[89], 96,
                    "incorrect value for amplitude_value[89], expected 96, is {}",
                    msg.amplitude_value[89]
                );
                assert_eq!(
                    msg.amplitude_value[90], 109,
                    "incorrect value for amplitude_value[90], expected 109, is {}",
                    msg.amplitude_value[90]
                );
                assert_eq!(
                    msg.amplitude_value[91], 111,
                    "incorrect value for amplitude_value[91], expected 111, is {}",
                    msg.amplitude_value[91]
                );
                assert_eq!(
                    msg.amplitude_value[92], 253,
                    "incorrect value for amplitude_value[92], expected 253, is {}",
                    msg.amplitude_value[92]
                );
                assert_eq!(
                    msg.amplitude_value[93], 149,
                    "incorrect value for amplitude_value[93], expected 149, is {}",
                    msg.amplitude_value[93]
                );
                assert_eq!(
                    msg.amplitude_value[94], 28,
                    "incorrect value for amplitude_value[94], expected 28, is {}",
                    msg.amplitude_value[94]
                );
                assert_eq!(
                    msg.amplitude_value[95], 225,
                    "incorrect value for amplitude_value[95], expected 225, is {}",
                    msg.amplitude_value[95]
                );
                assert_eq!(
                    msg.amplitude_value[96], 225,
                    "incorrect value for amplitude_value[96], expected 225, is {}",
                    msg.amplitude_value[96]
                );
                assert_eq!(
                    msg.amplitude_value[97], 72,
                    "incorrect value for amplitude_value[97], expected 72, is {}",
                    msg.amplitude_value[97]
                );
                assert_eq!(
                    msg.amplitude_value[98], 158,
                    "incorrect value for amplitude_value[98], expected 158, is {}",
                    msg.amplitude_value[98]
                );
                assert_eq!(
                    msg.amplitude_value[99], 158,
                    "incorrect value for amplitude_value[99], expected 158, is {}",
                    msg.amplitude_value[99]
                );
                assert_eq!(
                    msg.amplitude_value[100], 210,
                    "incorrect value for amplitude_value[100], expected 210, is {}",
                    msg.amplitude_value[100]
                );
                assert_eq!(
                    msg.amplitude_value[101], 196,
                    "incorrect value for amplitude_value[101], expected 196, is {}",
                    msg.amplitude_value[101]
                );
                assert_eq!(
                    msg.amplitude_value[102], 206,
                    "incorrect value for amplitude_value[102], expected 206, is {}",
                    msg.amplitude_value[102]
                );
                assert_eq!(
                    msg.amplitude_value[103], 70,
                    "incorrect value for amplitude_value[103], expected 70, is {}",
                    msg.amplitude_value[103]
                );
                assert_eq!(
                    msg.amplitude_value[104], 63,
                    "incorrect value for amplitude_value[104], expected 63, is {}",
                    msg.amplitude_value[104]
                );
                assert_eq!(
                    msg.amplitude_value[105], 225,
                    "incorrect value for amplitude_value[105], expected 225, is {}",
                    msg.amplitude_value[105]
                );
                assert_eq!(
                    msg.amplitude_value[106], 184,
                    "incorrect value for amplitude_value[106], expected 184, is {}",
                    msg.amplitude_value[106]
                );
                assert_eq!(
                    msg.amplitude_value[107], 150,
                    "incorrect value for amplitude_value[107], expected 150, is {}",
                    msg.amplitude_value[107]
                );
                assert_eq!(
                    msg.amplitude_value[108], 174,
                    "incorrect value for amplitude_value[108], expected 174, is {}",
                    msg.amplitude_value[108]
                );
                assert_eq!(
                    msg.amplitude_value[109], 240,
                    "incorrect value for amplitude_value[109], expected 240, is {}",
                    msg.amplitude_value[109]
                );
                assert_eq!(
                    msg.amplitude_value[110], 45,
                    "incorrect value for amplitude_value[110], expected 45, is {}",
                    msg.amplitude_value[110]
                );
                assert_eq!(
                    msg.amplitude_value[111], 146,
                    "incorrect value for amplitude_value[111], expected 146, is {}",
                    msg.amplitude_value[111]
                );
                assert_eq!(
                    msg.amplitude_value[112], 59,
                    "incorrect value for amplitude_value[112], expected 59, is {}",
                    msg.amplitude_value[112]
                );
                assert_eq!(
                    msg.amplitude_value[113], 82,
                    "incorrect value for amplitude_value[113], expected 82, is {}",
                    msg.amplitude_value[113]
                );
                assert_eq!(
                    msg.amplitude_value[114], 194,
                    "incorrect value for amplitude_value[114], expected 194, is {}",
                    msg.amplitude_value[114]
                );
                assert_eq!(
                    msg.amplitude_value[115], 4,
                    "incorrect value for amplitude_value[115], expected 4, is {}",
                    msg.amplitude_value[115]
                );
                assert_eq!(
                    msg.amplitude_value[116], 179,
                    "incorrect value for amplitude_value[116], expected 179, is {}",
                    msg.amplitude_value[116]
                );
                assert_eq!(
                    msg.amplitude_value[117], 148,
                    "incorrect value for amplitude_value[117], expected 148, is {}",
                    msg.amplitude_value[117]
                );
                assert_eq!(
                    msg.amplitude_value[118], 66,
                    "incorrect value for amplitude_value[118], expected 66, is {}",
                    msg.amplitude_value[118]
                );
                assert_eq!(
                    msg.amplitude_value[119], 254,
                    "incorrect value for amplitude_value[119], expected 254, is {}",
                    msg.amplitude_value[119]
                );
                assert_eq!(
                    msg.amplitude_value[120], 115,
                    "incorrect value for amplitude_value[120], expected 115, is {}",
                    msg.amplitude_value[120]
                );
                assert_eq!(
                    msg.amplitude_value[121], 77,
                    "incorrect value for amplitude_value[121], expected 77, is {}",
                    msg.amplitude_value[121]
                );
                assert_eq!(
                    msg.amplitude_value[122], 30,
                    "incorrect value for amplitude_value[122], expected 30, is {}",
                    msg.amplitude_value[122]
                );
                assert_eq!(
                    msg.amplitude_value[123], 46,
                    "incorrect value for amplitude_value[123], expected 46, is {}",
                    msg.amplitude_value[123]
                );
                assert_eq!(
                    msg.amplitude_value[124], 4,
                    "incorrect value for amplitude_value[124], expected 4, is {}",
                    msg.amplitude_value[124]
                );
                assert_eq!(
                    msg.amplitude_value[125], 204,
                    "incorrect value for amplitude_value[125], expected 204, is {}",
                    msg.amplitude_value[125]
                );
                assert_eq!(
                    msg.amplitude_value[126], 37,
                    "incorrect value for amplitude_value[126], expected 37, is {}",
                    msg.amplitude_value[126]
                );
                assert_eq!(
                    msg.amplitude_value[127], 200,
                    "incorrect value for amplitude_value[127], expected 200, is {}",
                    msg.amplitude_value[127]
                );
                assert_eq!(
                    msg.amplitude_value[128], 121,
                    "incorrect value for amplitude_value[128], expected 121, is {}",
                    msg.amplitude_value[128]
                );
                assert_eq!(
                    msg.amplitude_value[129], 18,
                    "incorrect value for amplitude_value[129], expected 18, is {}",
                    msg.amplitude_value[129]
                );
                assert_eq!(
                    msg.amplitude_value[130], 17,
                    "incorrect value for amplitude_value[130], expected 17, is {}",
                    msg.amplitude_value[130]
                );
                assert_eq!(
                    msg.amplitude_value[131], 171,
                    "incorrect value for amplitude_value[131], expected 171, is {}",
                    msg.amplitude_value[131]
                );
                assert_eq!(
                    msg.amplitude_value[132], 102,
                    "incorrect value for amplitude_value[132], expected 102, is {}",
                    msg.amplitude_value[132]
                );
                assert_eq!(
                    msg.amplitude_value[133], 163,
                    "incorrect value for amplitude_value[133], expected 163, is {}",
                    msg.amplitude_value[133]
                );
                assert_eq!(
                    msg.amplitude_value[134], 175,
                    "incorrect value for amplitude_value[134], expected 175, is {}",
                    msg.amplitude_value[134]
                );
                assert_eq!(
                    msg.amplitude_value[135], 50,
                    "incorrect value for amplitude_value[135], expected 50, is {}",
                    msg.amplitude_value[135]
                );
                assert_eq!(
                    msg.amplitude_value[136], 66,
                    "incorrect value for amplitude_value[136], expected 66, is {}",
                    msg.amplitude_value[136]
                );
                assert_eq!(
                    msg.amplitude_value[137], 101,
                    "incorrect value for amplitude_value[137], expected 101, is {}",
                    msg.amplitude_value[137]
                );
                assert_eq!(
                    msg.amplitude_value[138], 69,
                    "incorrect value for amplitude_value[138], expected 69, is {}",
                    msg.amplitude_value[138]
                );
                assert_eq!(
                    msg.amplitude_value[139], 13,
                    "incorrect value for amplitude_value[139], expected 13, is {}",
                    msg.amplitude_value[139]
                );
                assert_eq!(
                    msg.amplitude_value[140], 223,
                    "incorrect value for amplitude_value[140], expected 223, is {}",
                    msg.amplitude_value[140]
                );
                assert_eq!(
                    msg.amplitude_value[141], 172,
                    "incorrect value for amplitude_value[141], expected 172, is {}",
                    msg.amplitude_value[141]
                );
                assert_eq!(
                    msg.amplitude_value[142], 160,
                    "incorrect value for amplitude_value[142], expected 160, is {}",
                    msg.amplitude_value[142]
                );
                assert_eq!(
                    msg.amplitude_value[143], 233,
                    "incorrect value for amplitude_value[143], expected 233, is {}",
                    msg.amplitude_value[143]
                );
                assert_eq!(
                    msg.amplitude_value[144], 220,
                    "incorrect value for amplitude_value[144], expected 220, is {}",
                    msg.amplitude_value[144]
                );
                assert_eq!(
                    msg.amplitude_value[145], 101,
                    "incorrect value for amplitude_value[145], expected 101, is {}",
                    msg.amplitude_value[145]
                );
                assert_eq!(
                    msg.amplitude_value[146], 237,
                    "incorrect value for amplitude_value[146], expected 237, is {}",
                    msg.amplitude_value[146]
                );
                assert_eq!(
                    msg.amplitude_value[147], 156,
                    "incorrect value for amplitude_value[147], expected 156, is {}",
                    msg.amplitude_value[147]
                );
                assert_eq!(
                    msg.amplitude_value[148], 62,
                    "incorrect value for amplitude_value[148], expected 62, is {}",
                    msg.amplitude_value[148]
                );
                assert_eq!(
                    msg.amplitude_value[149], 117,
                    "incorrect value for amplitude_value[149], expected 117, is {}",
                    msg.amplitude_value[149]
                );
                assert_eq!(
                    msg.amplitude_value[150], 47,
                    "incorrect value for amplitude_value[150], expected 47, is {}",
                    msg.amplitude_value[150]
                );
                assert_eq!(
                    msg.amplitude_value[151], 143,
                    "incorrect value for amplitude_value[151], expected 143, is {}",
                    msg.amplitude_value[151]
                );
                assert_eq!(
                    msg.amplitude_value[152], 94,
                    "incorrect value for amplitude_value[152], expected 94, is {}",
                    msg.amplitude_value[152]
                );
                assert_eq!(
                    msg.amplitude_value[153], 135,
                    "incorrect value for amplitude_value[153], expected 135, is {}",
                    msg.amplitude_value[153]
                );
                assert_eq!(
                    msg.amplitude_value[154], 22,
                    "incorrect value for amplitude_value[154], expected 22, is {}",
                    msg.amplitude_value[154]
                );
                assert_eq!(
                    msg.amplitude_value[155], 155,
                    "incorrect value for amplitude_value[155], expected 155, is {}",
                    msg.amplitude_value[155]
                );
                assert_eq!(
                    msg.amplitude_value[156], 113,
                    "incorrect value for amplitude_value[156], expected 113, is {}",
                    msg.amplitude_value[156]
                );
                assert_eq!(
                    msg.amplitude_value[157], 110,
                    "incorrect value for amplitude_value[157], expected 110, is {}",
                    msg.amplitude_value[157]
                );
                assert_eq!(
                    msg.amplitude_value[158], 15,
                    "incorrect value for amplitude_value[158], expected 15, is {}",
                    msg.amplitude_value[158]
                );
                assert_eq!(
                    msg.amplitude_value[159], 243,
                    "incorrect value for amplitude_value[159], expected 243, is {}",
                    msg.amplitude_value[159]
                );
                assert_eq!(
                    msg.amplitude_value[160], 141,
                    "incorrect value for amplitude_value[160], expected 141, is {}",
                    msg.amplitude_value[160]
                );
                assert_eq!(
                    msg.amplitude_value[161], 227,
                    "incorrect value for amplitude_value[161], expected 227, is {}",
                    msg.amplitude_value[161]
                );
                assert_eq!(
                    msg.amplitude_value[162], 46,
                    "incorrect value for amplitude_value[162], expected 46, is {}",
                    msg.amplitude_value[162]
                );
                assert_eq!(
                    msg.amplitude_value[163], 143,
                    "incorrect value for amplitude_value[163], expected 143, is {}",
                    msg.amplitude_value[163]
                );
                assert_eq!(
                    msg.amplitude_value[164], 227,
                    "incorrect value for amplitude_value[164], expected 227, is {}",
                    msg.amplitude_value[164]
                );
                assert_eq!(
                    msg.amplitude_value[165], 209,
                    "incorrect value for amplitude_value[165], expected 209, is {}",
                    msg.amplitude_value[165]
                );
                assert_eq!(
                    msg.amplitude_value[166], 249,
                    "incorrect value for amplitude_value[166], expected 249, is {}",
                    msg.amplitude_value[166]
                );
                assert_eq!(
                    msg.amplitude_value[167], 2,
                    "incorrect value for amplitude_value[167], expected 2, is {}",
                    msg.amplitude_value[167]
                );
                assert_eq!(
                    msg.amplitude_value[168], 153,
                    "incorrect value for amplitude_value[168], expected 153, is {}",
                    msg.amplitude_value[168]
                );
                assert_eq!(
                    msg.amplitude_value[169], 168,
                    "incorrect value for amplitude_value[169], expected 168, is {}",
                    msg.amplitude_value[169]
                );
                assert_eq!(
                    msg.amplitude_value[170], 131,
                    "incorrect value for amplitude_value[170], expected 131, is {}",
                    msg.amplitude_value[170]
                );
                assert_eq!(
                    msg.amplitude_value[171], 249,
                    "incorrect value for amplitude_value[171], expected 249, is {}",
                    msg.amplitude_value[171]
                );
                assert_eq!(
                    msg.amplitude_value[172], 160,
                    "incorrect value for amplitude_value[172], expected 160, is {}",
                    msg.amplitude_value[172]
                );
                assert_eq!(
                    msg.amplitude_value[173], 88,
                    "incorrect value for amplitude_value[173], expected 88, is {}",
                    msg.amplitude_value[173]
                );
                assert_eq!(
                    msg.amplitude_value[174], 38,
                    "incorrect value for amplitude_value[174], expected 38, is {}",
                    msg.amplitude_value[174]
                );
                assert_eq!(
                    msg.amplitude_value[175], 117,
                    "incorrect value for amplitude_value[175], expected 117, is {}",
                    msg.amplitude_value[175]
                );
                assert_eq!(
                    msg.amplitude_value[176], 129,
                    "incorrect value for amplitude_value[176], expected 129, is {}",
                    msg.amplitude_value[176]
                );
                assert_eq!(
                    msg.amplitude_value[177], 57,
                    "incorrect value for amplitude_value[177], expected 57, is {}",
                    msg.amplitude_value[177]
                );
                assert_eq!(
                    msg.amplitude_value[178], 40,
                    "incorrect value for amplitude_value[178], expected 40, is {}",
                    msg.amplitude_value[178]
                );
                assert_eq!(
                    msg.amplitude_value[179], 109,
                    "incorrect value for amplitude_value[179], expected 109, is {}",
                    msg.amplitude_value[179]
                );
                assert_eq!(
                    msg.amplitude_value[180], 209,
                    "incorrect value for amplitude_value[180], expected 209, is {}",
                    msg.amplitude_value[180]
                );
                assert_eq!(
                    msg.amplitude_value[181], 177,
                    "incorrect value for amplitude_value[181], expected 177, is {}",
                    msg.amplitude_value[181]
                );
                assert_eq!(
                    msg.amplitude_value[182], 38,
                    "incorrect value for amplitude_value[182], expected 38, is {}",
                    msg.amplitude_value[182]
                );
                assert_eq!(
                    msg.amplitude_value[183], 47,
                    "incorrect value for amplitude_value[183], expected 47, is {}",
                    msg.amplitude_value[183]
                );
                assert_eq!(
                    msg.amplitude_value[184], 12,
                    "incorrect value for amplitude_value[184], expected 12, is {}",
                    msg.amplitude_value[184]
                );
                assert_eq!(
                    msg.amplitude_value[185], 15,
                    "incorrect value for amplitude_value[185], expected 15, is {}",
                    msg.amplitude_value[185]
                );
                assert_eq!(
                    msg.amplitude_value[186], 16,
                    "incorrect value for amplitude_value[186], expected 16, is {}",
                    msg.amplitude_value[186]
                );
                assert_eq!(
                    msg.amplitude_value[187], 9,
                    "incorrect value for amplitude_value[187], expected 9, is {}",
                    msg.amplitude_value[187]
                );
                assert_eq!(
                    msg.amplitude_value[188], 175,
                    "incorrect value for amplitude_value[188], expected 175, is {}",
                    msg.amplitude_value[188]
                );
                assert_eq!(
                    msg.amplitude_value[189], 69,
                    "incorrect value for amplitude_value[189], expected 69, is {}",
                    msg.amplitude_value[189]
                );
                assert_eq!(
                    msg.amplitude_value[190], 70,
                    "incorrect value for amplitude_value[190], expected 70, is {}",
                    msg.amplitude_value[190]
                );
                assert_eq!(
                    msg.amplitude_value[191], 182,
                    "incorrect value for amplitude_value[191], expected 182, is {}",
                    msg.amplitude_value[191]
                );
                assert_eq!(
                    msg.amplitude_value[192], 239,
                    "incorrect value for amplitude_value[192], expected 239, is {}",
                    msg.amplitude_value[192]
                );
                assert_eq!(
                    msg.amplitude_value[193], 117,
                    "incorrect value for amplitude_value[193], expected 117, is {}",
                    msg.amplitude_value[193]
                );
                assert_eq!(
                    msg.amplitude_value[194], 135,
                    "incorrect value for amplitude_value[194], expected 135, is {}",
                    msg.amplitude_value[194]
                );
                assert_eq!(
                    msg.amplitude_value[195], 6,
                    "incorrect value for amplitude_value[195], expected 6, is {}",
                    msg.amplitude_value[195]
                );
                assert_eq!(
                    msg.amplitude_value[196], 71,
                    "incorrect value for amplitude_value[196], expected 71, is {}",
                    msg.amplitude_value[196]
                );
                assert_eq!(
                    msg.amplitude_value[197], 99,
                    "incorrect value for amplitude_value[197], expected 99, is {}",
                    msg.amplitude_value[197]
                );
                assert_eq!(
                    msg.amplitude_value[198], 230,
                    "incorrect value for amplitude_value[198], expected 230, is {}",
                    msg.amplitude_value[198]
                );
                assert_eq!(
                    msg.amplitude_value[199], 115,
                    "incorrect value for amplitude_value[199], expected 115, is {}",
                    msg.amplitude_value[199]
                );
                assert_eq!(
                    msg.amplitude_value[200], 2,
                    "incorrect value for amplitude_value[200], expected 2, is {}",
                    msg.amplitude_value[200]
                );
                assert_eq!(
                    msg.amplitude_value[201], 71,
                    "incorrect value for amplitude_value[201], expected 71, is {}",
                    msg.amplitude_value[201]
                );
                assert_eq!(
                    msg.amplitude_value[202], 165,
                    "incorrect value for amplitude_value[202], expected 165, is {}",
                    msg.amplitude_value[202]
                );
                assert_eq!(
                    msg.amplitude_value[203], 228,
                    "incorrect value for amplitude_value[203], expected 228, is {}",
                    msg.amplitude_value[203]
                );
                assert_eq!(
                    msg.amplitude_value[204], 123,
                    "incorrect value for amplitude_value[204], expected 123, is {}",
                    msg.amplitude_value[204]
                );
                assert_eq!(
                    msg.amplitude_value[205], 210,
                    "incorrect value for amplitude_value[205], expected 210, is {}",
                    msg.amplitude_value[205]
                );
                assert_eq!(
                    msg.amplitude_value[206], 168,
                    "incorrect value for amplitude_value[206], expected 168, is {}",
                    msg.amplitude_value[206]
                );
                assert_eq!(
                    msg.amplitude_value[207], 90,
                    "incorrect value for amplitude_value[207], expected 90, is {}",
                    msg.amplitude_value[207]
                );
                assert_eq!(
                    msg.amplitude_value[208], 124,
                    "incorrect value for amplitude_value[208], expected 124, is {}",
                    msg.amplitude_value[208]
                );
                assert_eq!(
                    msg.amplitude_value[209], 20,
                    "incorrect value for amplitude_value[209], expected 20, is {}",
                    msg.amplitude_value[209]
                );
                assert_eq!(
                    msg.amplitude_value[210], 7,
                    "incorrect value for amplitude_value[210], expected 7, is {}",
                    msg.amplitude_value[210]
                );
                assert_eq!(
                    msg.amplitude_value[211], 220,
                    "incorrect value for amplitude_value[211], expected 220, is {}",
                    msg.amplitude_value[211]
                );
                assert_eq!(
                    msg.amplitude_value[212], 144,
                    "incorrect value for amplitude_value[212], expected 144, is {}",
                    msg.amplitude_value[212]
                );
                assert_eq!(
                    msg.amplitude_value[213], 168,
                    "incorrect value for amplitude_value[213], expected 168, is {}",
                    msg.amplitude_value[213]
                );
                assert_eq!(
                    msg.amplitude_value[214], 69,
                    "incorrect value for amplitude_value[214], expected 69, is {}",
                    msg.amplitude_value[214]
                );
                assert_eq!(
                    msg.amplitude_value[215], 22,
                    "incorrect value for amplitude_value[215], expected 22, is {}",
                    msg.amplitude_value[215]
                );
                assert_eq!(
                    msg.amplitude_value[216], 72,
                    "incorrect value for amplitude_value[216], expected 72, is {}",
                    msg.amplitude_value[216]
                );
                assert_eq!(
                    msg.amplitude_value[217], 162,
                    "incorrect value for amplitude_value[217], expected 162, is {}",
                    msg.amplitude_value[217]
                );
                assert_eq!(
                    msg.amplitude_value[218], 69,
                    "incorrect value for amplitude_value[218], expected 69, is {}",
                    msg.amplitude_value[218]
                );
                assert_eq!(
                    msg.amplitude_value[219], 111,
                    "incorrect value for amplitude_value[219], expected 111, is {}",
                    msg.amplitude_value[219]
                );
                assert_eq!(
                    msg.amplitude_value[220], 91,
                    "incorrect value for amplitude_value[220], expected 91, is {}",
                    msg.amplitude_value[220]
                );
                assert_eq!(
                    msg.amplitude_value[221], 251,
                    "incorrect value for amplitude_value[221], expected 251, is {}",
                    msg.amplitude_value[221]
                );
                assert_eq!(
                    msg.amplitude_value[222], 72,
                    "incorrect value for amplitude_value[222], expected 72, is {}",
                    msg.amplitude_value[222]
                );
                assert_eq!(
                    msg.amplitude_value[223], 220,
                    "incorrect value for amplitude_value[223], expected 220, is {}",
                    msg.amplitude_value[223]
                );
                assert_eq!(
                    msg.amplitude_value[224], 28,
                    "incorrect value for amplitude_value[224], expected 28, is {}",
                    msg.amplitude_value[224]
                );
                assert_eq!(
                    msg.amplitude_value[225], 119,
                    "incorrect value for amplitude_value[225], expected 119, is {}",
                    msg.amplitude_value[225]
                );
                assert_eq!(
                    msg.amplitude_value[226], 150,
                    "incorrect value for amplitude_value[226], expected 150, is {}",
                    msg.amplitude_value[226]
                );
                assert_eq!(
                    msg.channel_tag, 35146,
                    "incorrect value for channel_tag, expected 35146, is {}",
                    msg.channel_tag
                );
                assert!(
                    msg.freq_ref.almost_eq(7.73720019531250000e+03),
                    "incorrect value for freq_ref, expected 7.73720019531250000e+03, is {:e}",
                    msg.freq_ref
                );
                assert!(
                    msg.freq_step.almost_eq(8.22620019531250000e+03),
                    "incorrect value for freq_step, expected 8.22620019531250000e+03, is {:e}",
                    msg.freq_step
                );
                assert_eq!(
                    msg.t.ns_residual, -1479025396,
                    "incorrect value for t.ns_residual, expected -1479025396, is {}",
                    msg.t.ns_residual
                );
                assert_eq!(
                    msg.t.tow, 1227027783,
                    "incorrect value for t.tow, expected 1227027783, is {}",
                    msg.t.tow
                );
                assert_eq!(
                    msg.t.wn, 5075,
                    "incorrect value for t.wn, expected 5075, is {}",
                    msg.t.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSpecan"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
