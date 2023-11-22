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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgSpecanDep.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_piksi_msg_specan_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 80, 0, 112, 217, 255, 246, 22, 221, 56, 37, 59, 45, 27, 154, 97, 198, 69, 154, 1,
            144, 69, 205, 20, 18, 70, 51, 211, 89, 69, 240, 14, 179, 186, 227, 244, 173, 240, 182,
            71, 166, 117, 196, 13, 44, 27, 33, 28, 67, 254, 3, 249, 92, 44, 122, 169, 77, 186, 68,
            135, 63, 168, 162, 89, 36, 186, 99, 63, 105, 116, 216, 44, 67, 212, 156, 75, 81, 53,
            250, 225, 23, 205, 26, 34, 119, 50, 101, 64, 7, 231, 124, 183, 203, 102, 234, 84, 83,
            208, 23, 68, 54, 179, 98, 96, 116, 244, 246, 94, 104, 94, 13, 56, 210, 18, 191, 22,
            133, 81, 153, 159, 161, 219, 59, 21, 164, 121, 145, 203, 171, 132, 57, 180, 102, 101,
            11, 229, 175, 145, 73, 72, 124, 4, 184, 228, 61, 234, 218, 62, 226, 217, 193, 7, 109,
            44, 83, 201, 20, 101, 9, 140, 186, 162, 81, 91, 30, 231, 161, 81, 216, 114, 60, 231,
            163, 163, 49, 237, 244, 185, 240, 89, 143, 174, 165, 211, 241, 13, 16, 61, 141, 101,
            89, 37, 117, 189, 86, 118, 176, 228, 12, 14, 119, 135, 129, 243, 50, 29, 207, 198, 117,
            100, 225, 6, 139, 110, 39, 210, 68, 199, 43, 132, 64, 17, 51, 173, 181, 12, 140, 16,
            247, 84, 183, 105, 39, 157, 77, 30, 205, 194, 59, 64, 241, 183, 238, 105, 181, 170, 45,
            8, 166, 164, 238, 83, 148, 173, 108, 228, 67, 89, 189, 67, 26, 39, 216,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSpecanDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x50,
                    "Incorrect message type, expected 0x50, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd970,
                    "incorrect sender id, expected 0xd970, is {sender_id}"
                );
                assert!(
                    msg.amplitude_ref.almost_eq(9.34920019531250000e+03),
                    "incorrect value for amplitude_ref, expected 9.34920019531250000e+03, is {:e}",
                    msg.amplitude_ref
                );
                assert!(
                    msg.amplitude_unit.almost_eq(3.48519995117187500e+03),
                    "incorrect value for amplitude_unit, expected 3.48519995117187500e+03, is {:e}",
                    msg.amplitude_unit
                );
                assert_eq!(
                    msg.amplitude_value[0], 240,
                    "incorrect value for amplitude_value[0], expected 240, is {}",
                    msg.amplitude_value[0]
                );
                assert_eq!(
                    msg.amplitude_value[1], 14,
                    "incorrect value for amplitude_value[1], expected 14, is {}",
                    msg.amplitude_value[1]
                );
                assert_eq!(
                    msg.amplitude_value[2], 179,
                    "incorrect value for amplitude_value[2], expected 179, is {}",
                    msg.amplitude_value[2]
                );
                assert_eq!(
                    msg.amplitude_value[3], 186,
                    "incorrect value for amplitude_value[3], expected 186, is {}",
                    msg.amplitude_value[3]
                );
                assert_eq!(
                    msg.amplitude_value[4], 227,
                    "incorrect value for amplitude_value[4], expected 227, is {}",
                    msg.amplitude_value[4]
                );
                assert_eq!(
                    msg.amplitude_value[5], 244,
                    "incorrect value for amplitude_value[5], expected 244, is {}",
                    msg.amplitude_value[5]
                );
                assert_eq!(
                    msg.amplitude_value[6], 173,
                    "incorrect value for amplitude_value[6], expected 173, is {}",
                    msg.amplitude_value[6]
                );
                assert_eq!(
                    msg.amplitude_value[7], 240,
                    "incorrect value for amplitude_value[7], expected 240, is {}",
                    msg.amplitude_value[7]
                );
                assert_eq!(
                    msg.amplitude_value[8], 182,
                    "incorrect value for amplitude_value[8], expected 182, is {}",
                    msg.amplitude_value[8]
                );
                assert_eq!(
                    msg.amplitude_value[9], 71,
                    "incorrect value for amplitude_value[9], expected 71, is {}",
                    msg.amplitude_value[9]
                );
                assert_eq!(
                    msg.amplitude_value[10], 166,
                    "incorrect value for amplitude_value[10], expected 166, is {}",
                    msg.amplitude_value[10]
                );
                assert_eq!(
                    msg.amplitude_value[11], 117,
                    "incorrect value for amplitude_value[11], expected 117, is {}",
                    msg.amplitude_value[11]
                );
                assert_eq!(
                    msg.amplitude_value[12], 196,
                    "incorrect value for amplitude_value[12], expected 196, is {}",
                    msg.amplitude_value[12]
                );
                assert_eq!(
                    msg.amplitude_value[13], 13,
                    "incorrect value for amplitude_value[13], expected 13, is {}",
                    msg.amplitude_value[13]
                );
                assert_eq!(
                    msg.amplitude_value[14], 44,
                    "incorrect value for amplitude_value[14], expected 44, is {}",
                    msg.amplitude_value[14]
                );
                assert_eq!(
                    msg.amplitude_value[15], 27,
                    "incorrect value for amplitude_value[15], expected 27, is {}",
                    msg.amplitude_value[15]
                );
                assert_eq!(
                    msg.amplitude_value[16], 33,
                    "incorrect value for amplitude_value[16], expected 33, is {}",
                    msg.amplitude_value[16]
                );
                assert_eq!(
                    msg.amplitude_value[17], 28,
                    "incorrect value for amplitude_value[17], expected 28, is {}",
                    msg.amplitude_value[17]
                );
                assert_eq!(
                    msg.amplitude_value[18], 67,
                    "incorrect value for amplitude_value[18], expected 67, is {}",
                    msg.amplitude_value[18]
                );
                assert_eq!(
                    msg.amplitude_value[19], 254,
                    "incorrect value for amplitude_value[19], expected 254, is {}",
                    msg.amplitude_value[19]
                );
                assert_eq!(
                    msg.amplitude_value[20], 3,
                    "incorrect value for amplitude_value[20], expected 3, is {}",
                    msg.amplitude_value[20]
                );
                assert_eq!(
                    msg.amplitude_value[21], 249,
                    "incorrect value for amplitude_value[21], expected 249, is {}",
                    msg.amplitude_value[21]
                );
                assert_eq!(
                    msg.amplitude_value[22], 92,
                    "incorrect value for amplitude_value[22], expected 92, is {}",
                    msg.amplitude_value[22]
                );
                assert_eq!(
                    msg.amplitude_value[23], 44,
                    "incorrect value for amplitude_value[23], expected 44, is {}",
                    msg.amplitude_value[23]
                );
                assert_eq!(
                    msg.amplitude_value[24], 122,
                    "incorrect value for amplitude_value[24], expected 122, is {}",
                    msg.amplitude_value[24]
                );
                assert_eq!(
                    msg.amplitude_value[25], 169,
                    "incorrect value for amplitude_value[25], expected 169, is {}",
                    msg.amplitude_value[25]
                );
                assert_eq!(
                    msg.amplitude_value[26], 77,
                    "incorrect value for amplitude_value[26], expected 77, is {}",
                    msg.amplitude_value[26]
                );
                assert_eq!(
                    msg.amplitude_value[27], 186,
                    "incorrect value for amplitude_value[27], expected 186, is {}",
                    msg.amplitude_value[27]
                );
                assert_eq!(
                    msg.amplitude_value[28], 68,
                    "incorrect value for amplitude_value[28], expected 68, is {}",
                    msg.amplitude_value[28]
                );
                assert_eq!(
                    msg.amplitude_value[29], 135,
                    "incorrect value for amplitude_value[29], expected 135, is {}",
                    msg.amplitude_value[29]
                );
                assert_eq!(
                    msg.amplitude_value[30], 63,
                    "incorrect value for amplitude_value[30], expected 63, is {}",
                    msg.amplitude_value[30]
                );
                assert_eq!(
                    msg.amplitude_value[31], 168,
                    "incorrect value for amplitude_value[31], expected 168, is {}",
                    msg.amplitude_value[31]
                );
                assert_eq!(
                    msg.amplitude_value[32], 162,
                    "incorrect value for amplitude_value[32], expected 162, is {}",
                    msg.amplitude_value[32]
                );
                assert_eq!(
                    msg.amplitude_value[33], 89,
                    "incorrect value for amplitude_value[33], expected 89, is {}",
                    msg.amplitude_value[33]
                );
                assert_eq!(
                    msg.amplitude_value[34], 36,
                    "incorrect value for amplitude_value[34], expected 36, is {}",
                    msg.amplitude_value[34]
                );
                assert_eq!(
                    msg.amplitude_value[35], 186,
                    "incorrect value for amplitude_value[35], expected 186, is {}",
                    msg.amplitude_value[35]
                );
                assert_eq!(
                    msg.amplitude_value[36], 99,
                    "incorrect value for amplitude_value[36], expected 99, is {}",
                    msg.amplitude_value[36]
                );
                assert_eq!(
                    msg.amplitude_value[37], 63,
                    "incorrect value for amplitude_value[37], expected 63, is {}",
                    msg.amplitude_value[37]
                );
                assert_eq!(
                    msg.amplitude_value[38], 105,
                    "incorrect value for amplitude_value[38], expected 105, is {}",
                    msg.amplitude_value[38]
                );
                assert_eq!(
                    msg.amplitude_value[39], 116,
                    "incorrect value for amplitude_value[39], expected 116, is {}",
                    msg.amplitude_value[39]
                );
                assert_eq!(
                    msg.amplitude_value[40], 216,
                    "incorrect value for amplitude_value[40], expected 216, is {}",
                    msg.amplitude_value[40]
                );
                assert_eq!(
                    msg.amplitude_value[41], 44,
                    "incorrect value for amplitude_value[41], expected 44, is {}",
                    msg.amplitude_value[41]
                );
                assert_eq!(
                    msg.amplitude_value[42], 67,
                    "incorrect value for amplitude_value[42], expected 67, is {}",
                    msg.amplitude_value[42]
                );
                assert_eq!(
                    msg.amplitude_value[43], 212,
                    "incorrect value for amplitude_value[43], expected 212, is {}",
                    msg.amplitude_value[43]
                );
                assert_eq!(
                    msg.amplitude_value[44], 156,
                    "incorrect value for amplitude_value[44], expected 156, is {}",
                    msg.amplitude_value[44]
                );
                assert_eq!(
                    msg.amplitude_value[45], 75,
                    "incorrect value for amplitude_value[45], expected 75, is {}",
                    msg.amplitude_value[45]
                );
                assert_eq!(
                    msg.amplitude_value[46], 81,
                    "incorrect value for amplitude_value[46], expected 81, is {}",
                    msg.amplitude_value[46]
                );
                assert_eq!(
                    msg.amplitude_value[47], 53,
                    "incorrect value for amplitude_value[47], expected 53, is {}",
                    msg.amplitude_value[47]
                );
                assert_eq!(
                    msg.amplitude_value[48], 250,
                    "incorrect value for amplitude_value[48], expected 250, is {}",
                    msg.amplitude_value[48]
                );
                assert_eq!(
                    msg.amplitude_value[49], 225,
                    "incorrect value for amplitude_value[49], expected 225, is {}",
                    msg.amplitude_value[49]
                );
                assert_eq!(
                    msg.amplitude_value[50], 23,
                    "incorrect value for amplitude_value[50], expected 23, is {}",
                    msg.amplitude_value[50]
                );
                assert_eq!(
                    msg.amplitude_value[51], 205,
                    "incorrect value for amplitude_value[51], expected 205, is {}",
                    msg.amplitude_value[51]
                );
                assert_eq!(
                    msg.amplitude_value[52], 26,
                    "incorrect value for amplitude_value[52], expected 26, is {}",
                    msg.amplitude_value[52]
                );
                assert_eq!(
                    msg.amplitude_value[53], 34,
                    "incorrect value for amplitude_value[53], expected 34, is {}",
                    msg.amplitude_value[53]
                );
                assert_eq!(
                    msg.amplitude_value[54], 119,
                    "incorrect value for amplitude_value[54], expected 119, is {}",
                    msg.amplitude_value[54]
                );
                assert_eq!(
                    msg.amplitude_value[55], 50,
                    "incorrect value for amplitude_value[55], expected 50, is {}",
                    msg.amplitude_value[55]
                );
                assert_eq!(
                    msg.amplitude_value[56], 101,
                    "incorrect value for amplitude_value[56], expected 101, is {}",
                    msg.amplitude_value[56]
                );
                assert_eq!(
                    msg.amplitude_value[57], 64,
                    "incorrect value for amplitude_value[57], expected 64, is {}",
                    msg.amplitude_value[57]
                );
                assert_eq!(
                    msg.amplitude_value[58], 7,
                    "incorrect value for amplitude_value[58], expected 7, is {}",
                    msg.amplitude_value[58]
                );
                assert_eq!(
                    msg.amplitude_value[59], 231,
                    "incorrect value for amplitude_value[59], expected 231, is {}",
                    msg.amplitude_value[59]
                );
                assert_eq!(
                    msg.amplitude_value[60], 124,
                    "incorrect value for amplitude_value[60], expected 124, is {}",
                    msg.amplitude_value[60]
                );
                assert_eq!(
                    msg.amplitude_value[61], 183,
                    "incorrect value for amplitude_value[61], expected 183, is {}",
                    msg.amplitude_value[61]
                );
                assert_eq!(
                    msg.amplitude_value[62], 203,
                    "incorrect value for amplitude_value[62], expected 203, is {}",
                    msg.amplitude_value[62]
                );
                assert_eq!(
                    msg.amplitude_value[63], 102,
                    "incorrect value for amplitude_value[63], expected 102, is {}",
                    msg.amplitude_value[63]
                );
                assert_eq!(
                    msg.amplitude_value[64], 234,
                    "incorrect value for amplitude_value[64], expected 234, is {}",
                    msg.amplitude_value[64]
                );
                assert_eq!(
                    msg.amplitude_value[65], 84,
                    "incorrect value for amplitude_value[65], expected 84, is {}",
                    msg.amplitude_value[65]
                );
                assert_eq!(
                    msg.amplitude_value[66], 83,
                    "incorrect value for amplitude_value[66], expected 83, is {}",
                    msg.amplitude_value[66]
                );
                assert_eq!(
                    msg.amplitude_value[67], 208,
                    "incorrect value for amplitude_value[67], expected 208, is {}",
                    msg.amplitude_value[67]
                );
                assert_eq!(
                    msg.amplitude_value[68], 23,
                    "incorrect value for amplitude_value[68], expected 23, is {}",
                    msg.amplitude_value[68]
                );
                assert_eq!(
                    msg.amplitude_value[69], 68,
                    "incorrect value for amplitude_value[69], expected 68, is {}",
                    msg.amplitude_value[69]
                );
                assert_eq!(
                    msg.amplitude_value[70], 54,
                    "incorrect value for amplitude_value[70], expected 54, is {}",
                    msg.amplitude_value[70]
                );
                assert_eq!(
                    msg.amplitude_value[71], 179,
                    "incorrect value for amplitude_value[71], expected 179, is {}",
                    msg.amplitude_value[71]
                );
                assert_eq!(
                    msg.amplitude_value[72], 98,
                    "incorrect value for amplitude_value[72], expected 98, is {}",
                    msg.amplitude_value[72]
                );
                assert_eq!(
                    msg.amplitude_value[73], 96,
                    "incorrect value for amplitude_value[73], expected 96, is {}",
                    msg.amplitude_value[73]
                );
                assert_eq!(
                    msg.amplitude_value[74], 116,
                    "incorrect value for amplitude_value[74], expected 116, is {}",
                    msg.amplitude_value[74]
                );
                assert_eq!(
                    msg.amplitude_value[75], 244,
                    "incorrect value for amplitude_value[75], expected 244, is {}",
                    msg.amplitude_value[75]
                );
                assert_eq!(
                    msg.amplitude_value[76], 246,
                    "incorrect value for amplitude_value[76], expected 246, is {}",
                    msg.amplitude_value[76]
                );
                assert_eq!(
                    msg.amplitude_value[77], 94,
                    "incorrect value for amplitude_value[77], expected 94, is {}",
                    msg.amplitude_value[77]
                );
                assert_eq!(
                    msg.amplitude_value[78], 104,
                    "incorrect value for amplitude_value[78], expected 104, is {}",
                    msg.amplitude_value[78]
                );
                assert_eq!(
                    msg.amplitude_value[79], 94,
                    "incorrect value for amplitude_value[79], expected 94, is {}",
                    msg.amplitude_value[79]
                );
                assert_eq!(
                    msg.amplitude_value[80], 13,
                    "incorrect value for amplitude_value[80], expected 13, is {}",
                    msg.amplitude_value[80]
                );
                assert_eq!(
                    msg.amplitude_value[81], 56,
                    "incorrect value for amplitude_value[81], expected 56, is {}",
                    msg.amplitude_value[81]
                );
                assert_eq!(
                    msg.amplitude_value[82], 210,
                    "incorrect value for amplitude_value[82], expected 210, is {}",
                    msg.amplitude_value[82]
                );
                assert_eq!(
                    msg.amplitude_value[83], 18,
                    "incorrect value for amplitude_value[83], expected 18, is {}",
                    msg.amplitude_value[83]
                );
                assert_eq!(
                    msg.amplitude_value[84], 191,
                    "incorrect value for amplitude_value[84], expected 191, is {}",
                    msg.amplitude_value[84]
                );
                assert_eq!(
                    msg.amplitude_value[85], 22,
                    "incorrect value for amplitude_value[85], expected 22, is {}",
                    msg.amplitude_value[85]
                );
                assert_eq!(
                    msg.amplitude_value[86], 133,
                    "incorrect value for amplitude_value[86], expected 133, is {}",
                    msg.amplitude_value[86]
                );
                assert_eq!(
                    msg.amplitude_value[87], 81,
                    "incorrect value for amplitude_value[87], expected 81, is {}",
                    msg.amplitude_value[87]
                );
                assert_eq!(
                    msg.amplitude_value[88], 153,
                    "incorrect value for amplitude_value[88], expected 153, is {}",
                    msg.amplitude_value[88]
                );
                assert_eq!(
                    msg.amplitude_value[89], 159,
                    "incorrect value for amplitude_value[89], expected 159, is {}",
                    msg.amplitude_value[89]
                );
                assert_eq!(
                    msg.amplitude_value[90], 161,
                    "incorrect value for amplitude_value[90], expected 161, is {}",
                    msg.amplitude_value[90]
                );
                assert_eq!(
                    msg.amplitude_value[91], 219,
                    "incorrect value for amplitude_value[91], expected 219, is {}",
                    msg.amplitude_value[91]
                );
                assert_eq!(
                    msg.amplitude_value[92], 59,
                    "incorrect value for amplitude_value[92], expected 59, is {}",
                    msg.amplitude_value[92]
                );
                assert_eq!(
                    msg.amplitude_value[93], 21,
                    "incorrect value for amplitude_value[93], expected 21, is {}",
                    msg.amplitude_value[93]
                );
                assert_eq!(
                    msg.amplitude_value[94], 164,
                    "incorrect value for amplitude_value[94], expected 164, is {}",
                    msg.amplitude_value[94]
                );
                assert_eq!(
                    msg.amplitude_value[95], 121,
                    "incorrect value for amplitude_value[95], expected 121, is {}",
                    msg.amplitude_value[95]
                );
                assert_eq!(
                    msg.amplitude_value[96], 145,
                    "incorrect value for amplitude_value[96], expected 145, is {}",
                    msg.amplitude_value[96]
                );
                assert_eq!(
                    msg.amplitude_value[97], 203,
                    "incorrect value for amplitude_value[97], expected 203, is {}",
                    msg.amplitude_value[97]
                );
                assert_eq!(
                    msg.amplitude_value[98], 171,
                    "incorrect value for amplitude_value[98], expected 171, is {}",
                    msg.amplitude_value[98]
                );
                assert_eq!(
                    msg.amplitude_value[99], 132,
                    "incorrect value for amplitude_value[99], expected 132, is {}",
                    msg.amplitude_value[99]
                );
                assert_eq!(
                    msg.amplitude_value[100], 57,
                    "incorrect value for amplitude_value[100], expected 57, is {}",
                    msg.amplitude_value[100]
                );
                assert_eq!(
                    msg.amplitude_value[101], 180,
                    "incorrect value for amplitude_value[101], expected 180, is {}",
                    msg.amplitude_value[101]
                );
                assert_eq!(
                    msg.amplitude_value[102], 102,
                    "incorrect value for amplitude_value[102], expected 102, is {}",
                    msg.amplitude_value[102]
                );
                assert_eq!(
                    msg.amplitude_value[103], 101,
                    "incorrect value for amplitude_value[103], expected 101, is {}",
                    msg.amplitude_value[103]
                );
                assert_eq!(
                    msg.amplitude_value[104], 11,
                    "incorrect value for amplitude_value[104], expected 11, is {}",
                    msg.amplitude_value[104]
                );
                assert_eq!(
                    msg.amplitude_value[105], 229,
                    "incorrect value for amplitude_value[105], expected 229, is {}",
                    msg.amplitude_value[105]
                );
                assert_eq!(
                    msg.amplitude_value[106], 175,
                    "incorrect value for amplitude_value[106], expected 175, is {}",
                    msg.amplitude_value[106]
                );
                assert_eq!(
                    msg.amplitude_value[107], 145,
                    "incorrect value for amplitude_value[107], expected 145, is {}",
                    msg.amplitude_value[107]
                );
                assert_eq!(
                    msg.amplitude_value[108], 73,
                    "incorrect value for amplitude_value[108], expected 73, is {}",
                    msg.amplitude_value[108]
                );
                assert_eq!(
                    msg.amplitude_value[109], 72,
                    "incorrect value for amplitude_value[109], expected 72, is {}",
                    msg.amplitude_value[109]
                );
                assert_eq!(
                    msg.amplitude_value[110], 124,
                    "incorrect value for amplitude_value[110], expected 124, is {}",
                    msg.amplitude_value[110]
                );
                assert_eq!(
                    msg.amplitude_value[111], 4,
                    "incorrect value for amplitude_value[111], expected 4, is {}",
                    msg.amplitude_value[111]
                );
                assert_eq!(
                    msg.amplitude_value[112], 184,
                    "incorrect value for amplitude_value[112], expected 184, is {}",
                    msg.amplitude_value[112]
                );
                assert_eq!(
                    msg.amplitude_value[113], 228,
                    "incorrect value for amplitude_value[113], expected 228, is {}",
                    msg.amplitude_value[113]
                );
                assert_eq!(
                    msg.amplitude_value[114], 61,
                    "incorrect value for amplitude_value[114], expected 61, is {}",
                    msg.amplitude_value[114]
                );
                assert_eq!(
                    msg.amplitude_value[115], 234,
                    "incorrect value for amplitude_value[115], expected 234, is {}",
                    msg.amplitude_value[115]
                );
                assert_eq!(
                    msg.amplitude_value[116], 218,
                    "incorrect value for amplitude_value[116], expected 218, is {}",
                    msg.amplitude_value[116]
                );
                assert_eq!(
                    msg.amplitude_value[117], 62,
                    "incorrect value for amplitude_value[117], expected 62, is {}",
                    msg.amplitude_value[117]
                );
                assert_eq!(
                    msg.amplitude_value[118], 226,
                    "incorrect value for amplitude_value[118], expected 226, is {}",
                    msg.amplitude_value[118]
                );
                assert_eq!(
                    msg.amplitude_value[119], 217,
                    "incorrect value for amplitude_value[119], expected 217, is {}",
                    msg.amplitude_value[119]
                );
                assert_eq!(
                    msg.amplitude_value[120], 193,
                    "incorrect value for amplitude_value[120], expected 193, is {}",
                    msg.amplitude_value[120]
                );
                assert_eq!(
                    msg.amplitude_value[121], 7,
                    "incorrect value for amplitude_value[121], expected 7, is {}",
                    msg.amplitude_value[121]
                );
                assert_eq!(
                    msg.amplitude_value[122], 109,
                    "incorrect value for amplitude_value[122], expected 109, is {}",
                    msg.amplitude_value[122]
                );
                assert_eq!(
                    msg.amplitude_value[123], 44,
                    "incorrect value for amplitude_value[123], expected 44, is {}",
                    msg.amplitude_value[123]
                );
                assert_eq!(
                    msg.amplitude_value[124], 83,
                    "incorrect value for amplitude_value[124], expected 83, is {}",
                    msg.amplitude_value[124]
                );
                assert_eq!(
                    msg.amplitude_value[125], 201,
                    "incorrect value for amplitude_value[125], expected 201, is {}",
                    msg.amplitude_value[125]
                );
                assert_eq!(
                    msg.amplitude_value[126], 20,
                    "incorrect value for amplitude_value[126], expected 20, is {}",
                    msg.amplitude_value[126]
                );
                assert_eq!(
                    msg.amplitude_value[127], 101,
                    "incorrect value for amplitude_value[127], expected 101, is {}",
                    msg.amplitude_value[127]
                );
                assert_eq!(
                    msg.amplitude_value[128], 9,
                    "incorrect value for amplitude_value[128], expected 9, is {}",
                    msg.amplitude_value[128]
                );
                assert_eq!(
                    msg.amplitude_value[129], 140,
                    "incorrect value for amplitude_value[129], expected 140, is {}",
                    msg.amplitude_value[129]
                );
                assert_eq!(
                    msg.amplitude_value[130], 186,
                    "incorrect value for amplitude_value[130], expected 186, is {}",
                    msg.amplitude_value[130]
                );
                assert_eq!(
                    msg.amplitude_value[131], 162,
                    "incorrect value for amplitude_value[131], expected 162, is {}",
                    msg.amplitude_value[131]
                );
                assert_eq!(
                    msg.amplitude_value[132], 81,
                    "incorrect value for amplitude_value[132], expected 81, is {}",
                    msg.amplitude_value[132]
                );
                assert_eq!(
                    msg.amplitude_value[133], 91,
                    "incorrect value for amplitude_value[133], expected 91, is {}",
                    msg.amplitude_value[133]
                );
                assert_eq!(
                    msg.amplitude_value[134], 30,
                    "incorrect value for amplitude_value[134], expected 30, is {}",
                    msg.amplitude_value[134]
                );
                assert_eq!(
                    msg.amplitude_value[135], 231,
                    "incorrect value for amplitude_value[135], expected 231, is {}",
                    msg.amplitude_value[135]
                );
                assert_eq!(
                    msg.amplitude_value[136], 161,
                    "incorrect value for amplitude_value[136], expected 161, is {}",
                    msg.amplitude_value[136]
                );
                assert_eq!(
                    msg.amplitude_value[137], 81,
                    "incorrect value for amplitude_value[137], expected 81, is {}",
                    msg.amplitude_value[137]
                );
                assert_eq!(
                    msg.amplitude_value[138], 216,
                    "incorrect value for amplitude_value[138], expected 216, is {}",
                    msg.amplitude_value[138]
                );
                assert_eq!(
                    msg.amplitude_value[139], 114,
                    "incorrect value for amplitude_value[139], expected 114, is {}",
                    msg.amplitude_value[139]
                );
                assert_eq!(
                    msg.amplitude_value[140], 60,
                    "incorrect value for amplitude_value[140], expected 60, is {}",
                    msg.amplitude_value[140]
                );
                assert_eq!(
                    msg.amplitude_value[141], 231,
                    "incorrect value for amplitude_value[141], expected 231, is {}",
                    msg.amplitude_value[141]
                );
                assert_eq!(
                    msg.amplitude_value[142], 163,
                    "incorrect value for amplitude_value[142], expected 163, is {}",
                    msg.amplitude_value[142]
                );
                assert_eq!(
                    msg.amplitude_value[143], 163,
                    "incorrect value for amplitude_value[143], expected 163, is {}",
                    msg.amplitude_value[143]
                );
                assert_eq!(
                    msg.amplitude_value[144], 49,
                    "incorrect value for amplitude_value[144], expected 49, is {}",
                    msg.amplitude_value[144]
                );
                assert_eq!(
                    msg.amplitude_value[145], 237,
                    "incorrect value for amplitude_value[145], expected 237, is {}",
                    msg.amplitude_value[145]
                );
                assert_eq!(
                    msg.amplitude_value[146], 244,
                    "incorrect value for amplitude_value[146], expected 244, is {}",
                    msg.amplitude_value[146]
                );
                assert_eq!(
                    msg.amplitude_value[147], 185,
                    "incorrect value for amplitude_value[147], expected 185, is {}",
                    msg.amplitude_value[147]
                );
                assert_eq!(
                    msg.amplitude_value[148], 240,
                    "incorrect value for amplitude_value[148], expected 240, is {}",
                    msg.amplitude_value[148]
                );
                assert_eq!(
                    msg.amplitude_value[149], 89,
                    "incorrect value for amplitude_value[149], expected 89, is {}",
                    msg.amplitude_value[149]
                );
                assert_eq!(
                    msg.amplitude_value[150], 143,
                    "incorrect value for amplitude_value[150], expected 143, is {}",
                    msg.amplitude_value[150]
                );
                assert_eq!(
                    msg.amplitude_value[151], 174,
                    "incorrect value for amplitude_value[151], expected 174, is {}",
                    msg.amplitude_value[151]
                );
                assert_eq!(
                    msg.amplitude_value[152], 165,
                    "incorrect value for amplitude_value[152], expected 165, is {}",
                    msg.amplitude_value[152]
                );
                assert_eq!(
                    msg.amplitude_value[153], 211,
                    "incorrect value for amplitude_value[153], expected 211, is {}",
                    msg.amplitude_value[153]
                );
                assert_eq!(
                    msg.amplitude_value[154], 241,
                    "incorrect value for amplitude_value[154], expected 241, is {}",
                    msg.amplitude_value[154]
                );
                assert_eq!(
                    msg.amplitude_value[155], 13,
                    "incorrect value for amplitude_value[155], expected 13, is {}",
                    msg.amplitude_value[155]
                );
                assert_eq!(
                    msg.amplitude_value[156], 16,
                    "incorrect value for amplitude_value[156], expected 16, is {}",
                    msg.amplitude_value[156]
                );
                assert_eq!(
                    msg.amplitude_value[157], 61,
                    "incorrect value for amplitude_value[157], expected 61, is {}",
                    msg.amplitude_value[157]
                );
                assert_eq!(
                    msg.amplitude_value[158], 141,
                    "incorrect value for amplitude_value[158], expected 141, is {}",
                    msg.amplitude_value[158]
                );
                assert_eq!(
                    msg.amplitude_value[159], 101,
                    "incorrect value for amplitude_value[159], expected 101, is {}",
                    msg.amplitude_value[159]
                );
                assert_eq!(
                    msg.amplitude_value[160], 89,
                    "incorrect value for amplitude_value[160], expected 89, is {}",
                    msg.amplitude_value[160]
                );
                assert_eq!(
                    msg.amplitude_value[161], 37,
                    "incorrect value for amplitude_value[161], expected 37, is {}",
                    msg.amplitude_value[161]
                );
                assert_eq!(
                    msg.amplitude_value[162], 117,
                    "incorrect value for amplitude_value[162], expected 117, is {}",
                    msg.amplitude_value[162]
                );
                assert_eq!(
                    msg.amplitude_value[163], 189,
                    "incorrect value for amplitude_value[163], expected 189, is {}",
                    msg.amplitude_value[163]
                );
                assert_eq!(
                    msg.amplitude_value[164], 86,
                    "incorrect value for amplitude_value[164], expected 86, is {}",
                    msg.amplitude_value[164]
                );
                assert_eq!(
                    msg.amplitude_value[165], 118,
                    "incorrect value for amplitude_value[165], expected 118, is {}",
                    msg.amplitude_value[165]
                );
                assert_eq!(
                    msg.amplitude_value[166], 176,
                    "incorrect value for amplitude_value[166], expected 176, is {}",
                    msg.amplitude_value[166]
                );
                assert_eq!(
                    msg.amplitude_value[167], 228,
                    "incorrect value for amplitude_value[167], expected 228, is {}",
                    msg.amplitude_value[167]
                );
                assert_eq!(
                    msg.amplitude_value[168], 12,
                    "incorrect value for amplitude_value[168], expected 12, is {}",
                    msg.amplitude_value[168]
                );
                assert_eq!(
                    msg.amplitude_value[169], 14,
                    "incorrect value for amplitude_value[169], expected 14, is {}",
                    msg.amplitude_value[169]
                );
                assert_eq!(
                    msg.amplitude_value[170], 119,
                    "incorrect value for amplitude_value[170], expected 119, is {}",
                    msg.amplitude_value[170]
                );
                assert_eq!(
                    msg.amplitude_value[171], 135,
                    "incorrect value for amplitude_value[171], expected 135, is {}",
                    msg.amplitude_value[171]
                );
                assert_eq!(
                    msg.amplitude_value[172], 129,
                    "incorrect value for amplitude_value[172], expected 129, is {}",
                    msg.amplitude_value[172]
                );
                assert_eq!(
                    msg.amplitude_value[173], 243,
                    "incorrect value for amplitude_value[173], expected 243, is {}",
                    msg.amplitude_value[173]
                );
                assert_eq!(
                    msg.amplitude_value[174], 50,
                    "incorrect value for amplitude_value[174], expected 50, is {}",
                    msg.amplitude_value[174]
                );
                assert_eq!(
                    msg.amplitude_value[175], 29,
                    "incorrect value for amplitude_value[175], expected 29, is {}",
                    msg.amplitude_value[175]
                );
                assert_eq!(
                    msg.amplitude_value[176], 207,
                    "incorrect value for amplitude_value[176], expected 207, is {}",
                    msg.amplitude_value[176]
                );
                assert_eq!(
                    msg.amplitude_value[177], 198,
                    "incorrect value for amplitude_value[177], expected 198, is {}",
                    msg.amplitude_value[177]
                );
                assert_eq!(
                    msg.amplitude_value[178], 117,
                    "incorrect value for amplitude_value[178], expected 117, is {}",
                    msg.amplitude_value[178]
                );
                assert_eq!(
                    msg.amplitude_value[179], 100,
                    "incorrect value for amplitude_value[179], expected 100, is {}",
                    msg.amplitude_value[179]
                );
                assert_eq!(
                    msg.amplitude_value[180], 225,
                    "incorrect value for amplitude_value[180], expected 225, is {}",
                    msg.amplitude_value[180]
                );
                assert_eq!(
                    msg.amplitude_value[181], 6,
                    "incorrect value for amplitude_value[181], expected 6, is {}",
                    msg.amplitude_value[181]
                );
                assert_eq!(
                    msg.amplitude_value[182], 139,
                    "incorrect value for amplitude_value[182], expected 139, is {}",
                    msg.amplitude_value[182]
                );
                assert_eq!(
                    msg.amplitude_value[183], 110,
                    "incorrect value for amplitude_value[183], expected 110, is {}",
                    msg.amplitude_value[183]
                );
                assert_eq!(
                    msg.amplitude_value[184], 39,
                    "incorrect value for amplitude_value[184], expected 39, is {}",
                    msg.amplitude_value[184]
                );
                assert_eq!(
                    msg.amplitude_value[185], 210,
                    "incorrect value for amplitude_value[185], expected 210, is {}",
                    msg.amplitude_value[185]
                );
                assert_eq!(
                    msg.amplitude_value[186], 68,
                    "incorrect value for amplitude_value[186], expected 68, is {}",
                    msg.amplitude_value[186]
                );
                assert_eq!(
                    msg.amplitude_value[187], 199,
                    "incorrect value for amplitude_value[187], expected 199, is {}",
                    msg.amplitude_value[187]
                );
                assert_eq!(
                    msg.amplitude_value[188], 43,
                    "incorrect value for amplitude_value[188], expected 43, is {}",
                    msg.amplitude_value[188]
                );
                assert_eq!(
                    msg.amplitude_value[189], 132,
                    "incorrect value for amplitude_value[189], expected 132, is {}",
                    msg.amplitude_value[189]
                );
                assert_eq!(
                    msg.amplitude_value[190], 64,
                    "incorrect value for amplitude_value[190], expected 64, is {}",
                    msg.amplitude_value[190]
                );
                assert_eq!(
                    msg.amplitude_value[191], 17,
                    "incorrect value for amplitude_value[191], expected 17, is {}",
                    msg.amplitude_value[191]
                );
                assert_eq!(
                    msg.amplitude_value[192], 51,
                    "incorrect value for amplitude_value[192], expected 51, is {}",
                    msg.amplitude_value[192]
                );
                assert_eq!(
                    msg.amplitude_value[193], 173,
                    "incorrect value for amplitude_value[193], expected 173, is {}",
                    msg.amplitude_value[193]
                );
                assert_eq!(
                    msg.amplitude_value[194], 181,
                    "incorrect value for amplitude_value[194], expected 181, is {}",
                    msg.amplitude_value[194]
                );
                assert_eq!(
                    msg.amplitude_value[195], 12,
                    "incorrect value for amplitude_value[195], expected 12, is {}",
                    msg.amplitude_value[195]
                );
                assert_eq!(
                    msg.amplitude_value[196], 140,
                    "incorrect value for amplitude_value[196], expected 140, is {}",
                    msg.amplitude_value[196]
                );
                assert_eq!(
                    msg.amplitude_value[197], 16,
                    "incorrect value for amplitude_value[197], expected 16, is {}",
                    msg.amplitude_value[197]
                );
                assert_eq!(
                    msg.amplitude_value[198], 247,
                    "incorrect value for amplitude_value[198], expected 247, is {}",
                    msg.amplitude_value[198]
                );
                assert_eq!(
                    msg.amplitude_value[199], 84,
                    "incorrect value for amplitude_value[199], expected 84, is {}",
                    msg.amplitude_value[199]
                );
                assert_eq!(
                    msg.amplitude_value[200], 183,
                    "incorrect value for amplitude_value[200], expected 183, is {}",
                    msg.amplitude_value[200]
                );
                assert_eq!(
                    msg.amplitude_value[201], 105,
                    "incorrect value for amplitude_value[201], expected 105, is {}",
                    msg.amplitude_value[201]
                );
                assert_eq!(
                    msg.amplitude_value[202], 39,
                    "incorrect value for amplitude_value[202], expected 39, is {}",
                    msg.amplitude_value[202]
                );
                assert_eq!(
                    msg.amplitude_value[203], 157,
                    "incorrect value for amplitude_value[203], expected 157, is {}",
                    msg.amplitude_value[203]
                );
                assert_eq!(
                    msg.amplitude_value[204], 77,
                    "incorrect value for amplitude_value[204], expected 77, is {}",
                    msg.amplitude_value[204]
                );
                assert_eq!(
                    msg.amplitude_value[205], 30,
                    "incorrect value for amplitude_value[205], expected 30, is {}",
                    msg.amplitude_value[205]
                );
                assert_eq!(
                    msg.amplitude_value[206], 205,
                    "incorrect value for amplitude_value[206], expected 205, is {}",
                    msg.amplitude_value[206]
                );
                assert_eq!(
                    msg.amplitude_value[207], 194,
                    "incorrect value for amplitude_value[207], expected 194, is {}",
                    msg.amplitude_value[207]
                );
                assert_eq!(
                    msg.amplitude_value[208], 59,
                    "incorrect value for amplitude_value[208], expected 59, is {}",
                    msg.amplitude_value[208]
                );
                assert_eq!(
                    msg.amplitude_value[209], 64,
                    "incorrect value for amplitude_value[209], expected 64, is {}",
                    msg.amplitude_value[209]
                );
                assert_eq!(
                    msg.amplitude_value[210], 241,
                    "incorrect value for amplitude_value[210], expected 241, is {}",
                    msg.amplitude_value[210]
                );
                assert_eq!(
                    msg.amplitude_value[211], 183,
                    "incorrect value for amplitude_value[211], expected 183, is {}",
                    msg.amplitude_value[211]
                );
                assert_eq!(
                    msg.amplitude_value[212], 238,
                    "incorrect value for amplitude_value[212], expected 238, is {}",
                    msg.amplitude_value[212]
                );
                assert_eq!(
                    msg.amplitude_value[213], 105,
                    "incorrect value for amplitude_value[213], expected 105, is {}",
                    msg.amplitude_value[213]
                );
                assert_eq!(
                    msg.amplitude_value[214], 181,
                    "incorrect value for amplitude_value[214], expected 181, is {}",
                    msg.amplitude_value[214]
                );
                assert_eq!(
                    msg.amplitude_value[215], 170,
                    "incorrect value for amplitude_value[215], expected 170, is {}",
                    msg.amplitude_value[215]
                );
                assert_eq!(
                    msg.amplitude_value[216], 45,
                    "incorrect value for amplitude_value[216], expected 45, is {}",
                    msg.amplitude_value[216]
                );
                assert_eq!(
                    msg.amplitude_value[217], 8,
                    "incorrect value for amplitude_value[217], expected 8, is {}",
                    msg.amplitude_value[217]
                );
                assert_eq!(
                    msg.amplitude_value[218], 166,
                    "incorrect value for amplitude_value[218], expected 166, is {}",
                    msg.amplitude_value[218]
                );
                assert_eq!(
                    msg.amplitude_value[219], 164,
                    "incorrect value for amplitude_value[219], expected 164, is {}",
                    msg.amplitude_value[219]
                );
                assert_eq!(
                    msg.amplitude_value[220], 238,
                    "incorrect value for amplitude_value[220], expected 238, is {}",
                    msg.amplitude_value[220]
                );
                assert_eq!(
                    msg.amplitude_value[221], 83,
                    "incorrect value for amplitude_value[221], expected 83, is {}",
                    msg.amplitude_value[221]
                );
                assert_eq!(
                    msg.amplitude_value[222], 148,
                    "incorrect value for amplitude_value[222], expected 148, is {}",
                    msg.amplitude_value[222]
                );
                assert_eq!(
                    msg.amplitude_value[223], 173,
                    "incorrect value for amplitude_value[223], expected 173, is {}",
                    msg.amplitude_value[223]
                );
                assert_eq!(
                    msg.amplitude_value[224], 108,
                    "incorrect value for amplitude_value[224], expected 108, is {}",
                    msg.amplitude_value[224]
                );
                assert_eq!(
                    msg.amplitude_value[225], 228,
                    "incorrect value for amplitude_value[225], expected 228, is {}",
                    msg.amplitude_value[225]
                );
                assert_eq!(
                    msg.amplitude_value[226], 67,
                    "incorrect value for amplitude_value[226], expected 67, is {}",
                    msg.amplitude_value[226]
                );
                assert_eq!(
                    msg.amplitude_value[227], 89,
                    "incorrect value for amplitude_value[227], expected 89, is {}",
                    msg.amplitude_value[227]
                );
                assert_eq!(
                    msg.amplitude_value[228], 189,
                    "incorrect value for amplitude_value[228], expected 189, is {}",
                    msg.amplitude_value[228]
                );
                assert_eq!(
                    msg.amplitude_value[229], 67,
                    "incorrect value for amplitude_value[229], expected 67, is {}",
                    msg.amplitude_value[229]
                );
                assert_eq!(
                    msg.amplitude_value[230], 26,
                    "incorrect value for amplitude_value[230], expected 26, is {}",
                    msg.amplitude_value[230]
                );
                assert_eq!(
                    msg.channel_tag, 5878,
                    "incorrect value for channel_tag, expected 5878, is {}",
                    msg.channel_tag
                );
                assert!(
                    msg.freq_ref.almost_eq(6.34820019531250000e+03),
                    "incorrect value for freq_ref, expected 6.34820019531250000e+03, is {:e}",
                    msg.freq_ref
                );
                assert!(
                    msg.freq_step.almost_eq(4.60820019531250000e+03),
                    "incorrect value for freq_step, expected 4.60820019531250000e+03, is {:e}",
                    msg.freq_step
                );
                assert_eq!(
                    msg.t.tow, 992295133,
                    "incorrect value for t.tow, expected 992295133, is {}",
                    msg.t.tow
                );
                assert_eq!(
                    msg.t.wn, 6957,
                    "incorrect value for t.wn, expected 6957, is {}",
                    msg.t.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSpecanDep"),
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
fn test_json2sbp_auto_check_sbp_piksi_msg_specan_dep() {
    {
        let json_input = r#"{"preamble":85,"msg_type":80,"sender":55664,"length":255,"payload":"9hbdOCU7LRuaYcZFmgGQRc0UEkYz01lF8A6zuuP0rfC2R6Z1xA0sGyEcQ/4D+VwseqlNukSHP6iiWSS6Yz9pdNgsQ9ScS1E1+uEXzRoidzJlQAfnfLfLZupUU9AXRDazYmB09PZeaF4NONISvxaFUZmfods7FaR5kcurhDm0ZmUL5a+RSUh8BLjkPeraPuLZwQdtLFPJFGUJjLqiUVse56FR2HI856OjMe30ufBZj66l0/ENED2NZVkldb1WdrDkDA53h4HzMh3PxnVk4QaLbifSRMcrhEARM621DIwQ91S3aSedTR7NwjtA8bfuabWqLQimpO5TlK1s5ENZvUMa","crc":55335,"channel_tag":5878,"t":{"tow":992295133,"wn":6957},"freq_ref":6348.2001953125,"freq_step":4608.2001953125,"amplitude_ref":9349.2001953125,"amplitude_unit":3485.199951171875,"amplitude_value":[240,14,179,186,227,244,173,240,182,71,166,117,196,13,44,27,33,28,67,254,3,249,92,44,122,169,77,186,68,135,63,168,162,89,36,186,99,63,105,116,216,44,67,212,156,75,81,53,250,225,23,205,26,34,119,50,101,64,7,231,124,183,203,102,234,84,83,208,23,68,54,179,98,96,116,244,246,94,104,94,13,56,210,18,191,22,133,81,153,159,161,219,59,21,164,121,145,203,171,132,57,180,102,101,11,229,175,145,73,72,124,4,184,228,61,234,218,62,226,217,193,7,109,44,83,201,20,101,9,140,186,162,81,91,30,231,161,81,216,114,60,231,163,163,49,237,244,185,240,89,143,174,165,211,241,13,16,61,141,101,89,37,117,189,86,118,176,228,12,14,119,135,129,243,50,29,207,198,117,100,225,6,139,110,39,210,68,199,43,132,64,17,51,173,181,12,140,16,247,84,183,105,39,157,77,30,205,194,59,64,241,183,238,105,181,170,45,8,166,164,238,83,148,173,108,228,67,89,189,67,26]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSpecanDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x50,
                    "Incorrect message type, expected 0x50, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd970,
                    "incorrect sender id, expected 0xd970, is {sender_id}"
                );
                assert!(
                    msg.amplitude_ref.almost_eq(9.34920019531250000e+03),
                    "incorrect value for amplitude_ref, expected 9.34920019531250000e+03, is {:e}",
                    msg.amplitude_ref
                );
                assert!(
                    msg.amplitude_unit.almost_eq(3.48519995117187500e+03),
                    "incorrect value for amplitude_unit, expected 3.48519995117187500e+03, is {:e}",
                    msg.amplitude_unit
                );
                assert_eq!(
                    msg.amplitude_value[0], 240,
                    "incorrect value for amplitude_value[0], expected 240, is {}",
                    msg.amplitude_value[0]
                );
                assert_eq!(
                    msg.amplitude_value[1], 14,
                    "incorrect value for amplitude_value[1], expected 14, is {}",
                    msg.amplitude_value[1]
                );
                assert_eq!(
                    msg.amplitude_value[2], 179,
                    "incorrect value for amplitude_value[2], expected 179, is {}",
                    msg.amplitude_value[2]
                );
                assert_eq!(
                    msg.amplitude_value[3], 186,
                    "incorrect value for amplitude_value[3], expected 186, is {}",
                    msg.amplitude_value[3]
                );
                assert_eq!(
                    msg.amplitude_value[4], 227,
                    "incorrect value for amplitude_value[4], expected 227, is {}",
                    msg.amplitude_value[4]
                );
                assert_eq!(
                    msg.amplitude_value[5], 244,
                    "incorrect value for amplitude_value[5], expected 244, is {}",
                    msg.amplitude_value[5]
                );
                assert_eq!(
                    msg.amplitude_value[6], 173,
                    "incorrect value for amplitude_value[6], expected 173, is {}",
                    msg.amplitude_value[6]
                );
                assert_eq!(
                    msg.amplitude_value[7], 240,
                    "incorrect value for amplitude_value[7], expected 240, is {}",
                    msg.amplitude_value[7]
                );
                assert_eq!(
                    msg.amplitude_value[8], 182,
                    "incorrect value for amplitude_value[8], expected 182, is {}",
                    msg.amplitude_value[8]
                );
                assert_eq!(
                    msg.amplitude_value[9], 71,
                    "incorrect value for amplitude_value[9], expected 71, is {}",
                    msg.amplitude_value[9]
                );
                assert_eq!(
                    msg.amplitude_value[10], 166,
                    "incorrect value for amplitude_value[10], expected 166, is {}",
                    msg.amplitude_value[10]
                );
                assert_eq!(
                    msg.amplitude_value[11], 117,
                    "incorrect value for amplitude_value[11], expected 117, is {}",
                    msg.amplitude_value[11]
                );
                assert_eq!(
                    msg.amplitude_value[12], 196,
                    "incorrect value for amplitude_value[12], expected 196, is {}",
                    msg.amplitude_value[12]
                );
                assert_eq!(
                    msg.amplitude_value[13], 13,
                    "incorrect value for amplitude_value[13], expected 13, is {}",
                    msg.amplitude_value[13]
                );
                assert_eq!(
                    msg.amplitude_value[14], 44,
                    "incorrect value for amplitude_value[14], expected 44, is {}",
                    msg.amplitude_value[14]
                );
                assert_eq!(
                    msg.amplitude_value[15], 27,
                    "incorrect value for amplitude_value[15], expected 27, is {}",
                    msg.amplitude_value[15]
                );
                assert_eq!(
                    msg.amplitude_value[16], 33,
                    "incorrect value for amplitude_value[16], expected 33, is {}",
                    msg.amplitude_value[16]
                );
                assert_eq!(
                    msg.amplitude_value[17], 28,
                    "incorrect value for amplitude_value[17], expected 28, is {}",
                    msg.amplitude_value[17]
                );
                assert_eq!(
                    msg.amplitude_value[18], 67,
                    "incorrect value for amplitude_value[18], expected 67, is {}",
                    msg.amplitude_value[18]
                );
                assert_eq!(
                    msg.amplitude_value[19], 254,
                    "incorrect value for amplitude_value[19], expected 254, is {}",
                    msg.amplitude_value[19]
                );
                assert_eq!(
                    msg.amplitude_value[20], 3,
                    "incorrect value for amplitude_value[20], expected 3, is {}",
                    msg.amplitude_value[20]
                );
                assert_eq!(
                    msg.amplitude_value[21], 249,
                    "incorrect value for amplitude_value[21], expected 249, is {}",
                    msg.amplitude_value[21]
                );
                assert_eq!(
                    msg.amplitude_value[22], 92,
                    "incorrect value for amplitude_value[22], expected 92, is {}",
                    msg.amplitude_value[22]
                );
                assert_eq!(
                    msg.amplitude_value[23], 44,
                    "incorrect value for amplitude_value[23], expected 44, is {}",
                    msg.amplitude_value[23]
                );
                assert_eq!(
                    msg.amplitude_value[24], 122,
                    "incorrect value for amplitude_value[24], expected 122, is {}",
                    msg.amplitude_value[24]
                );
                assert_eq!(
                    msg.amplitude_value[25], 169,
                    "incorrect value for amplitude_value[25], expected 169, is {}",
                    msg.amplitude_value[25]
                );
                assert_eq!(
                    msg.amplitude_value[26], 77,
                    "incorrect value for amplitude_value[26], expected 77, is {}",
                    msg.amplitude_value[26]
                );
                assert_eq!(
                    msg.amplitude_value[27], 186,
                    "incorrect value for amplitude_value[27], expected 186, is {}",
                    msg.amplitude_value[27]
                );
                assert_eq!(
                    msg.amplitude_value[28], 68,
                    "incorrect value for amplitude_value[28], expected 68, is {}",
                    msg.amplitude_value[28]
                );
                assert_eq!(
                    msg.amplitude_value[29], 135,
                    "incorrect value for amplitude_value[29], expected 135, is {}",
                    msg.amplitude_value[29]
                );
                assert_eq!(
                    msg.amplitude_value[30], 63,
                    "incorrect value for amplitude_value[30], expected 63, is {}",
                    msg.amplitude_value[30]
                );
                assert_eq!(
                    msg.amplitude_value[31], 168,
                    "incorrect value for amplitude_value[31], expected 168, is {}",
                    msg.amplitude_value[31]
                );
                assert_eq!(
                    msg.amplitude_value[32], 162,
                    "incorrect value for amplitude_value[32], expected 162, is {}",
                    msg.amplitude_value[32]
                );
                assert_eq!(
                    msg.amplitude_value[33], 89,
                    "incorrect value for amplitude_value[33], expected 89, is {}",
                    msg.amplitude_value[33]
                );
                assert_eq!(
                    msg.amplitude_value[34], 36,
                    "incorrect value for amplitude_value[34], expected 36, is {}",
                    msg.amplitude_value[34]
                );
                assert_eq!(
                    msg.amplitude_value[35], 186,
                    "incorrect value for amplitude_value[35], expected 186, is {}",
                    msg.amplitude_value[35]
                );
                assert_eq!(
                    msg.amplitude_value[36], 99,
                    "incorrect value for amplitude_value[36], expected 99, is {}",
                    msg.amplitude_value[36]
                );
                assert_eq!(
                    msg.amplitude_value[37], 63,
                    "incorrect value for amplitude_value[37], expected 63, is {}",
                    msg.amplitude_value[37]
                );
                assert_eq!(
                    msg.amplitude_value[38], 105,
                    "incorrect value for amplitude_value[38], expected 105, is {}",
                    msg.amplitude_value[38]
                );
                assert_eq!(
                    msg.amplitude_value[39], 116,
                    "incorrect value for amplitude_value[39], expected 116, is {}",
                    msg.amplitude_value[39]
                );
                assert_eq!(
                    msg.amplitude_value[40], 216,
                    "incorrect value for amplitude_value[40], expected 216, is {}",
                    msg.amplitude_value[40]
                );
                assert_eq!(
                    msg.amplitude_value[41], 44,
                    "incorrect value for amplitude_value[41], expected 44, is {}",
                    msg.amplitude_value[41]
                );
                assert_eq!(
                    msg.amplitude_value[42], 67,
                    "incorrect value for amplitude_value[42], expected 67, is {}",
                    msg.amplitude_value[42]
                );
                assert_eq!(
                    msg.amplitude_value[43], 212,
                    "incorrect value for amplitude_value[43], expected 212, is {}",
                    msg.amplitude_value[43]
                );
                assert_eq!(
                    msg.amplitude_value[44], 156,
                    "incorrect value for amplitude_value[44], expected 156, is {}",
                    msg.amplitude_value[44]
                );
                assert_eq!(
                    msg.amplitude_value[45], 75,
                    "incorrect value for amplitude_value[45], expected 75, is {}",
                    msg.amplitude_value[45]
                );
                assert_eq!(
                    msg.amplitude_value[46], 81,
                    "incorrect value for amplitude_value[46], expected 81, is {}",
                    msg.amplitude_value[46]
                );
                assert_eq!(
                    msg.amplitude_value[47], 53,
                    "incorrect value for amplitude_value[47], expected 53, is {}",
                    msg.amplitude_value[47]
                );
                assert_eq!(
                    msg.amplitude_value[48], 250,
                    "incorrect value for amplitude_value[48], expected 250, is {}",
                    msg.amplitude_value[48]
                );
                assert_eq!(
                    msg.amplitude_value[49], 225,
                    "incorrect value for amplitude_value[49], expected 225, is {}",
                    msg.amplitude_value[49]
                );
                assert_eq!(
                    msg.amplitude_value[50], 23,
                    "incorrect value for amplitude_value[50], expected 23, is {}",
                    msg.amplitude_value[50]
                );
                assert_eq!(
                    msg.amplitude_value[51], 205,
                    "incorrect value for amplitude_value[51], expected 205, is {}",
                    msg.amplitude_value[51]
                );
                assert_eq!(
                    msg.amplitude_value[52], 26,
                    "incorrect value for amplitude_value[52], expected 26, is {}",
                    msg.amplitude_value[52]
                );
                assert_eq!(
                    msg.amplitude_value[53], 34,
                    "incorrect value for amplitude_value[53], expected 34, is {}",
                    msg.amplitude_value[53]
                );
                assert_eq!(
                    msg.amplitude_value[54], 119,
                    "incorrect value for amplitude_value[54], expected 119, is {}",
                    msg.amplitude_value[54]
                );
                assert_eq!(
                    msg.amplitude_value[55], 50,
                    "incorrect value for amplitude_value[55], expected 50, is {}",
                    msg.amplitude_value[55]
                );
                assert_eq!(
                    msg.amplitude_value[56], 101,
                    "incorrect value for amplitude_value[56], expected 101, is {}",
                    msg.amplitude_value[56]
                );
                assert_eq!(
                    msg.amplitude_value[57], 64,
                    "incorrect value for amplitude_value[57], expected 64, is {}",
                    msg.amplitude_value[57]
                );
                assert_eq!(
                    msg.amplitude_value[58], 7,
                    "incorrect value for amplitude_value[58], expected 7, is {}",
                    msg.amplitude_value[58]
                );
                assert_eq!(
                    msg.amplitude_value[59], 231,
                    "incorrect value for amplitude_value[59], expected 231, is {}",
                    msg.amplitude_value[59]
                );
                assert_eq!(
                    msg.amplitude_value[60], 124,
                    "incorrect value for amplitude_value[60], expected 124, is {}",
                    msg.amplitude_value[60]
                );
                assert_eq!(
                    msg.amplitude_value[61], 183,
                    "incorrect value for amplitude_value[61], expected 183, is {}",
                    msg.amplitude_value[61]
                );
                assert_eq!(
                    msg.amplitude_value[62], 203,
                    "incorrect value for amplitude_value[62], expected 203, is {}",
                    msg.amplitude_value[62]
                );
                assert_eq!(
                    msg.amplitude_value[63], 102,
                    "incorrect value for amplitude_value[63], expected 102, is {}",
                    msg.amplitude_value[63]
                );
                assert_eq!(
                    msg.amplitude_value[64], 234,
                    "incorrect value for amplitude_value[64], expected 234, is {}",
                    msg.amplitude_value[64]
                );
                assert_eq!(
                    msg.amplitude_value[65], 84,
                    "incorrect value for amplitude_value[65], expected 84, is {}",
                    msg.amplitude_value[65]
                );
                assert_eq!(
                    msg.amplitude_value[66], 83,
                    "incorrect value for amplitude_value[66], expected 83, is {}",
                    msg.amplitude_value[66]
                );
                assert_eq!(
                    msg.amplitude_value[67], 208,
                    "incorrect value for amplitude_value[67], expected 208, is {}",
                    msg.amplitude_value[67]
                );
                assert_eq!(
                    msg.amplitude_value[68], 23,
                    "incorrect value for amplitude_value[68], expected 23, is {}",
                    msg.amplitude_value[68]
                );
                assert_eq!(
                    msg.amplitude_value[69], 68,
                    "incorrect value for amplitude_value[69], expected 68, is {}",
                    msg.amplitude_value[69]
                );
                assert_eq!(
                    msg.amplitude_value[70], 54,
                    "incorrect value for amplitude_value[70], expected 54, is {}",
                    msg.amplitude_value[70]
                );
                assert_eq!(
                    msg.amplitude_value[71], 179,
                    "incorrect value for amplitude_value[71], expected 179, is {}",
                    msg.amplitude_value[71]
                );
                assert_eq!(
                    msg.amplitude_value[72], 98,
                    "incorrect value for amplitude_value[72], expected 98, is {}",
                    msg.amplitude_value[72]
                );
                assert_eq!(
                    msg.amplitude_value[73], 96,
                    "incorrect value for amplitude_value[73], expected 96, is {}",
                    msg.amplitude_value[73]
                );
                assert_eq!(
                    msg.amplitude_value[74], 116,
                    "incorrect value for amplitude_value[74], expected 116, is {}",
                    msg.amplitude_value[74]
                );
                assert_eq!(
                    msg.amplitude_value[75], 244,
                    "incorrect value for amplitude_value[75], expected 244, is {}",
                    msg.amplitude_value[75]
                );
                assert_eq!(
                    msg.amplitude_value[76], 246,
                    "incorrect value for amplitude_value[76], expected 246, is {}",
                    msg.amplitude_value[76]
                );
                assert_eq!(
                    msg.amplitude_value[77], 94,
                    "incorrect value for amplitude_value[77], expected 94, is {}",
                    msg.amplitude_value[77]
                );
                assert_eq!(
                    msg.amplitude_value[78], 104,
                    "incorrect value for amplitude_value[78], expected 104, is {}",
                    msg.amplitude_value[78]
                );
                assert_eq!(
                    msg.amplitude_value[79], 94,
                    "incorrect value for amplitude_value[79], expected 94, is {}",
                    msg.amplitude_value[79]
                );
                assert_eq!(
                    msg.amplitude_value[80], 13,
                    "incorrect value for amplitude_value[80], expected 13, is {}",
                    msg.amplitude_value[80]
                );
                assert_eq!(
                    msg.amplitude_value[81], 56,
                    "incorrect value for amplitude_value[81], expected 56, is {}",
                    msg.amplitude_value[81]
                );
                assert_eq!(
                    msg.amplitude_value[82], 210,
                    "incorrect value for amplitude_value[82], expected 210, is {}",
                    msg.amplitude_value[82]
                );
                assert_eq!(
                    msg.amplitude_value[83], 18,
                    "incorrect value for amplitude_value[83], expected 18, is {}",
                    msg.amplitude_value[83]
                );
                assert_eq!(
                    msg.amplitude_value[84], 191,
                    "incorrect value for amplitude_value[84], expected 191, is {}",
                    msg.amplitude_value[84]
                );
                assert_eq!(
                    msg.amplitude_value[85], 22,
                    "incorrect value for amplitude_value[85], expected 22, is {}",
                    msg.amplitude_value[85]
                );
                assert_eq!(
                    msg.amplitude_value[86], 133,
                    "incorrect value for amplitude_value[86], expected 133, is {}",
                    msg.amplitude_value[86]
                );
                assert_eq!(
                    msg.amplitude_value[87], 81,
                    "incorrect value for amplitude_value[87], expected 81, is {}",
                    msg.amplitude_value[87]
                );
                assert_eq!(
                    msg.amplitude_value[88], 153,
                    "incorrect value for amplitude_value[88], expected 153, is {}",
                    msg.amplitude_value[88]
                );
                assert_eq!(
                    msg.amplitude_value[89], 159,
                    "incorrect value for amplitude_value[89], expected 159, is {}",
                    msg.amplitude_value[89]
                );
                assert_eq!(
                    msg.amplitude_value[90], 161,
                    "incorrect value for amplitude_value[90], expected 161, is {}",
                    msg.amplitude_value[90]
                );
                assert_eq!(
                    msg.amplitude_value[91], 219,
                    "incorrect value for amplitude_value[91], expected 219, is {}",
                    msg.amplitude_value[91]
                );
                assert_eq!(
                    msg.amplitude_value[92], 59,
                    "incorrect value for amplitude_value[92], expected 59, is {}",
                    msg.amplitude_value[92]
                );
                assert_eq!(
                    msg.amplitude_value[93], 21,
                    "incorrect value for amplitude_value[93], expected 21, is {}",
                    msg.amplitude_value[93]
                );
                assert_eq!(
                    msg.amplitude_value[94], 164,
                    "incorrect value for amplitude_value[94], expected 164, is {}",
                    msg.amplitude_value[94]
                );
                assert_eq!(
                    msg.amplitude_value[95], 121,
                    "incorrect value for amplitude_value[95], expected 121, is {}",
                    msg.amplitude_value[95]
                );
                assert_eq!(
                    msg.amplitude_value[96], 145,
                    "incorrect value for amplitude_value[96], expected 145, is {}",
                    msg.amplitude_value[96]
                );
                assert_eq!(
                    msg.amplitude_value[97], 203,
                    "incorrect value for amplitude_value[97], expected 203, is {}",
                    msg.amplitude_value[97]
                );
                assert_eq!(
                    msg.amplitude_value[98], 171,
                    "incorrect value for amplitude_value[98], expected 171, is {}",
                    msg.amplitude_value[98]
                );
                assert_eq!(
                    msg.amplitude_value[99], 132,
                    "incorrect value for amplitude_value[99], expected 132, is {}",
                    msg.amplitude_value[99]
                );
                assert_eq!(
                    msg.amplitude_value[100], 57,
                    "incorrect value for amplitude_value[100], expected 57, is {}",
                    msg.amplitude_value[100]
                );
                assert_eq!(
                    msg.amplitude_value[101], 180,
                    "incorrect value for amplitude_value[101], expected 180, is {}",
                    msg.amplitude_value[101]
                );
                assert_eq!(
                    msg.amplitude_value[102], 102,
                    "incorrect value for amplitude_value[102], expected 102, is {}",
                    msg.amplitude_value[102]
                );
                assert_eq!(
                    msg.amplitude_value[103], 101,
                    "incorrect value for amplitude_value[103], expected 101, is {}",
                    msg.amplitude_value[103]
                );
                assert_eq!(
                    msg.amplitude_value[104], 11,
                    "incorrect value for amplitude_value[104], expected 11, is {}",
                    msg.amplitude_value[104]
                );
                assert_eq!(
                    msg.amplitude_value[105], 229,
                    "incorrect value for amplitude_value[105], expected 229, is {}",
                    msg.amplitude_value[105]
                );
                assert_eq!(
                    msg.amplitude_value[106], 175,
                    "incorrect value for amplitude_value[106], expected 175, is {}",
                    msg.amplitude_value[106]
                );
                assert_eq!(
                    msg.amplitude_value[107], 145,
                    "incorrect value for amplitude_value[107], expected 145, is {}",
                    msg.amplitude_value[107]
                );
                assert_eq!(
                    msg.amplitude_value[108], 73,
                    "incorrect value for amplitude_value[108], expected 73, is {}",
                    msg.amplitude_value[108]
                );
                assert_eq!(
                    msg.amplitude_value[109], 72,
                    "incorrect value for amplitude_value[109], expected 72, is {}",
                    msg.amplitude_value[109]
                );
                assert_eq!(
                    msg.amplitude_value[110], 124,
                    "incorrect value for amplitude_value[110], expected 124, is {}",
                    msg.amplitude_value[110]
                );
                assert_eq!(
                    msg.amplitude_value[111], 4,
                    "incorrect value for amplitude_value[111], expected 4, is {}",
                    msg.amplitude_value[111]
                );
                assert_eq!(
                    msg.amplitude_value[112], 184,
                    "incorrect value for amplitude_value[112], expected 184, is {}",
                    msg.amplitude_value[112]
                );
                assert_eq!(
                    msg.amplitude_value[113], 228,
                    "incorrect value for amplitude_value[113], expected 228, is {}",
                    msg.amplitude_value[113]
                );
                assert_eq!(
                    msg.amplitude_value[114], 61,
                    "incorrect value for amplitude_value[114], expected 61, is {}",
                    msg.amplitude_value[114]
                );
                assert_eq!(
                    msg.amplitude_value[115], 234,
                    "incorrect value for amplitude_value[115], expected 234, is {}",
                    msg.amplitude_value[115]
                );
                assert_eq!(
                    msg.amplitude_value[116], 218,
                    "incorrect value for amplitude_value[116], expected 218, is {}",
                    msg.amplitude_value[116]
                );
                assert_eq!(
                    msg.amplitude_value[117], 62,
                    "incorrect value for amplitude_value[117], expected 62, is {}",
                    msg.amplitude_value[117]
                );
                assert_eq!(
                    msg.amplitude_value[118], 226,
                    "incorrect value for amplitude_value[118], expected 226, is {}",
                    msg.amplitude_value[118]
                );
                assert_eq!(
                    msg.amplitude_value[119], 217,
                    "incorrect value for amplitude_value[119], expected 217, is {}",
                    msg.amplitude_value[119]
                );
                assert_eq!(
                    msg.amplitude_value[120], 193,
                    "incorrect value for amplitude_value[120], expected 193, is {}",
                    msg.amplitude_value[120]
                );
                assert_eq!(
                    msg.amplitude_value[121], 7,
                    "incorrect value for amplitude_value[121], expected 7, is {}",
                    msg.amplitude_value[121]
                );
                assert_eq!(
                    msg.amplitude_value[122], 109,
                    "incorrect value for amplitude_value[122], expected 109, is {}",
                    msg.amplitude_value[122]
                );
                assert_eq!(
                    msg.amplitude_value[123], 44,
                    "incorrect value for amplitude_value[123], expected 44, is {}",
                    msg.amplitude_value[123]
                );
                assert_eq!(
                    msg.amplitude_value[124], 83,
                    "incorrect value for amplitude_value[124], expected 83, is {}",
                    msg.amplitude_value[124]
                );
                assert_eq!(
                    msg.amplitude_value[125], 201,
                    "incorrect value for amplitude_value[125], expected 201, is {}",
                    msg.amplitude_value[125]
                );
                assert_eq!(
                    msg.amplitude_value[126], 20,
                    "incorrect value for amplitude_value[126], expected 20, is {}",
                    msg.amplitude_value[126]
                );
                assert_eq!(
                    msg.amplitude_value[127], 101,
                    "incorrect value for amplitude_value[127], expected 101, is {}",
                    msg.amplitude_value[127]
                );
                assert_eq!(
                    msg.amplitude_value[128], 9,
                    "incorrect value for amplitude_value[128], expected 9, is {}",
                    msg.amplitude_value[128]
                );
                assert_eq!(
                    msg.amplitude_value[129], 140,
                    "incorrect value for amplitude_value[129], expected 140, is {}",
                    msg.amplitude_value[129]
                );
                assert_eq!(
                    msg.amplitude_value[130], 186,
                    "incorrect value for amplitude_value[130], expected 186, is {}",
                    msg.amplitude_value[130]
                );
                assert_eq!(
                    msg.amplitude_value[131], 162,
                    "incorrect value for amplitude_value[131], expected 162, is {}",
                    msg.amplitude_value[131]
                );
                assert_eq!(
                    msg.amplitude_value[132], 81,
                    "incorrect value for amplitude_value[132], expected 81, is {}",
                    msg.amplitude_value[132]
                );
                assert_eq!(
                    msg.amplitude_value[133], 91,
                    "incorrect value for amplitude_value[133], expected 91, is {}",
                    msg.amplitude_value[133]
                );
                assert_eq!(
                    msg.amplitude_value[134], 30,
                    "incorrect value for amplitude_value[134], expected 30, is {}",
                    msg.amplitude_value[134]
                );
                assert_eq!(
                    msg.amplitude_value[135], 231,
                    "incorrect value for amplitude_value[135], expected 231, is {}",
                    msg.amplitude_value[135]
                );
                assert_eq!(
                    msg.amplitude_value[136], 161,
                    "incorrect value for amplitude_value[136], expected 161, is {}",
                    msg.amplitude_value[136]
                );
                assert_eq!(
                    msg.amplitude_value[137], 81,
                    "incorrect value for amplitude_value[137], expected 81, is {}",
                    msg.amplitude_value[137]
                );
                assert_eq!(
                    msg.amplitude_value[138], 216,
                    "incorrect value for amplitude_value[138], expected 216, is {}",
                    msg.amplitude_value[138]
                );
                assert_eq!(
                    msg.amplitude_value[139], 114,
                    "incorrect value for amplitude_value[139], expected 114, is {}",
                    msg.amplitude_value[139]
                );
                assert_eq!(
                    msg.amplitude_value[140], 60,
                    "incorrect value for amplitude_value[140], expected 60, is {}",
                    msg.amplitude_value[140]
                );
                assert_eq!(
                    msg.amplitude_value[141], 231,
                    "incorrect value for amplitude_value[141], expected 231, is {}",
                    msg.amplitude_value[141]
                );
                assert_eq!(
                    msg.amplitude_value[142], 163,
                    "incorrect value for amplitude_value[142], expected 163, is {}",
                    msg.amplitude_value[142]
                );
                assert_eq!(
                    msg.amplitude_value[143], 163,
                    "incorrect value for amplitude_value[143], expected 163, is {}",
                    msg.amplitude_value[143]
                );
                assert_eq!(
                    msg.amplitude_value[144], 49,
                    "incorrect value for amplitude_value[144], expected 49, is {}",
                    msg.amplitude_value[144]
                );
                assert_eq!(
                    msg.amplitude_value[145], 237,
                    "incorrect value for amplitude_value[145], expected 237, is {}",
                    msg.amplitude_value[145]
                );
                assert_eq!(
                    msg.amplitude_value[146], 244,
                    "incorrect value for amplitude_value[146], expected 244, is {}",
                    msg.amplitude_value[146]
                );
                assert_eq!(
                    msg.amplitude_value[147], 185,
                    "incorrect value for amplitude_value[147], expected 185, is {}",
                    msg.amplitude_value[147]
                );
                assert_eq!(
                    msg.amplitude_value[148], 240,
                    "incorrect value for amplitude_value[148], expected 240, is {}",
                    msg.amplitude_value[148]
                );
                assert_eq!(
                    msg.amplitude_value[149], 89,
                    "incorrect value for amplitude_value[149], expected 89, is {}",
                    msg.amplitude_value[149]
                );
                assert_eq!(
                    msg.amplitude_value[150], 143,
                    "incorrect value for amplitude_value[150], expected 143, is {}",
                    msg.amplitude_value[150]
                );
                assert_eq!(
                    msg.amplitude_value[151], 174,
                    "incorrect value for amplitude_value[151], expected 174, is {}",
                    msg.amplitude_value[151]
                );
                assert_eq!(
                    msg.amplitude_value[152], 165,
                    "incorrect value for amplitude_value[152], expected 165, is {}",
                    msg.amplitude_value[152]
                );
                assert_eq!(
                    msg.amplitude_value[153], 211,
                    "incorrect value for amplitude_value[153], expected 211, is {}",
                    msg.amplitude_value[153]
                );
                assert_eq!(
                    msg.amplitude_value[154], 241,
                    "incorrect value for amplitude_value[154], expected 241, is {}",
                    msg.amplitude_value[154]
                );
                assert_eq!(
                    msg.amplitude_value[155], 13,
                    "incorrect value for amplitude_value[155], expected 13, is {}",
                    msg.amplitude_value[155]
                );
                assert_eq!(
                    msg.amplitude_value[156], 16,
                    "incorrect value for amplitude_value[156], expected 16, is {}",
                    msg.amplitude_value[156]
                );
                assert_eq!(
                    msg.amplitude_value[157], 61,
                    "incorrect value for amplitude_value[157], expected 61, is {}",
                    msg.amplitude_value[157]
                );
                assert_eq!(
                    msg.amplitude_value[158], 141,
                    "incorrect value for amplitude_value[158], expected 141, is {}",
                    msg.amplitude_value[158]
                );
                assert_eq!(
                    msg.amplitude_value[159], 101,
                    "incorrect value for amplitude_value[159], expected 101, is {}",
                    msg.amplitude_value[159]
                );
                assert_eq!(
                    msg.amplitude_value[160], 89,
                    "incorrect value for amplitude_value[160], expected 89, is {}",
                    msg.amplitude_value[160]
                );
                assert_eq!(
                    msg.amplitude_value[161], 37,
                    "incorrect value for amplitude_value[161], expected 37, is {}",
                    msg.amplitude_value[161]
                );
                assert_eq!(
                    msg.amplitude_value[162], 117,
                    "incorrect value for amplitude_value[162], expected 117, is {}",
                    msg.amplitude_value[162]
                );
                assert_eq!(
                    msg.amplitude_value[163], 189,
                    "incorrect value for amplitude_value[163], expected 189, is {}",
                    msg.amplitude_value[163]
                );
                assert_eq!(
                    msg.amplitude_value[164], 86,
                    "incorrect value for amplitude_value[164], expected 86, is {}",
                    msg.amplitude_value[164]
                );
                assert_eq!(
                    msg.amplitude_value[165], 118,
                    "incorrect value for amplitude_value[165], expected 118, is {}",
                    msg.amplitude_value[165]
                );
                assert_eq!(
                    msg.amplitude_value[166], 176,
                    "incorrect value for amplitude_value[166], expected 176, is {}",
                    msg.amplitude_value[166]
                );
                assert_eq!(
                    msg.amplitude_value[167], 228,
                    "incorrect value for amplitude_value[167], expected 228, is {}",
                    msg.amplitude_value[167]
                );
                assert_eq!(
                    msg.amplitude_value[168], 12,
                    "incorrect value for amplitude_value[168], expected 12, is {}",
                    msg.amplitude_value[168]
                );
                assert_eq!(
                    msg.amplitude_value[169], 14,
                    "incorrect value for amplitude_value[169], expected 14, is {}",
                    msg.amplitude_value[169]
                );
                assert_eq!(
                    msg.amplitude_value[170], 119,
                    "incorrect value for amplitude_value[170], expected 119, is {}",
                    msg.amplitude_value[170]
                );
                assert_eq!(
                    msg.amplitude_value[171], 135,
                    "incorrect value for amplitude_value[171], expected 135, is {}",
                    msg.amplitude_value[171]
                );
                assert_eq!(
                    msg.amplitude_value[172], 129,
                    "incorrect value for amplitude_value[172], expected 129, is {}",
                    msg.amplitude_value[172]
                );
                assert_eq!(
                    msg.amplitude_value[173], 243,
                    "incorrect value for amplitude_value[173], expected 243, is {}",
                    msg.amplitude_value[173]
                );
                assert_eq!(
                    msg.amplitude_value[174], 50,
                    "incorrect value for amplitude_value[174], expected 50, is {}",
                    msg.amplitude_value[174]
                );
                assert_eq!(
                    msg.amplitude_value[175], 29,
                    "incorrect value for amplitude_value[175], expected 29, is {}",
                    msg.amplitude_value[175]
                );
                assert_eq!(
                    msg.amplitude_value[176], 207,
                    "incorrect value for amplitude_value[176], expected 207, is {}",
                    msg.amplitude_value[176]
                );
                assert_eq!(
                    msg.amplitude_value[177], 198,
                    "incorrect value for amplitude_value[177], expected 198, is {}",
                    msg.amplitude_value[177]
                );
                assert_eq!(
                    msg.amplitude_value[178], 117,
                    "incorrect value for amplitude_value[178], expected 117, is {}",
                    msg.amplitude_value[178]
                );
                assert_eq!(
                    msg.amplitude_value[179], 100,
                    "incorrect value for amplitude_value[179], expected 100, is {}",
                    msg.amplitude_value[179]
                );
                assert_eq!(
                    msg.amplitude_value[180], 225,
                    "incorrect value for amplitude_value[180], expected 225, is {}",
                    msg.amplitude_value[180]
                );
                assert_eq!(
                    msg.amplitude_value[181], 6,
                    "incorrect value for amplitude_value[181], expected 6, is {}",
                    msg.amplitude_value[181]
                );
                assert_eq!(
                    msg.amplitude_value[182], 139,
                    "incorrect value for amplitude_value[182], expected 139, is {}",
                    msg.amplitude_value[182]
                );
                assert_eq!(
                    msg.amplitude_value[183], 110,
                    "incorrect value for amplitude_value[183], expected 110, is {}",
                    msg.amplitude_value[183]
                );
                assert_eq!(
                    msg.amplitude_value[184], 39,
                    "incorrect value for amplitude_value[184], expected 39, is {}",
                    msg.amplitude_value[184]
                );
                assert_eq!(
                    msg.amplitude_value[185], 210,
                    "incorrect value for amplitude_value[185], expected 210, is {}",
                    msg.amplitude_value[185]
                );
                assert_eq!(
                    msg.amplitude_value[186], 68,
                    "incorrect value for amplitude_value[186], expected 68, is {}",
                    msg.amplitude_value[186]
                );
                assert_eq!(
                    msg.amplitude_value[187], 199,
                    "incorrect value for amplitude_value[187], expected 199, is {}",
                    msg.amplitude_value[187]
                );
                assert_eq!(
                    msg.amplitude_value[188], 43,
                    "incorrect value for amplitude_value[188], expected 43, is {}",
                    msg.amplitude_value[188]
                );
                assert_eq!(
                    msg.amplitude_value[189], 132,
                    "incorrect value for amplitude_value[189], expected 132, is {}",
                    msg.amplitude_value[189]
                );
                assert_eq!(
                    msg.amplitude_value[190], 64,
                    "incorrect value for amplitude_value[190], expected 64, is {}",
                    msg.amplitude_value[190]
                );
                assert_eq!(
                    msg.amplitude_value[191], 17,
                    "incorrect value for amplitude_value[191], expected 17, is {}",
                    msg.amplitude_value[191]
                );
                assert_eq!(
                    msg.amplitude_value[192], 51,
                    "incorrect value for amplitude_value[192], expected 51, is {}",
                    msg.amplitude_value[192]
                );
                assert_eq!(
                    msg.amplitude_value[193], 173,
                    "incorrect value for amplitude_value[193], expected 173, is {}",
                    msg.amplitude_value[193]
                );
                assert_eq!(
                    msg.amplitude_value[194], 181,
                    "incorrect value for amplitude_value[194], expected 181, is {}",
                    msg.amplitude_value[194]
                );
                assert_eq!(
                    msg.amplitude_value[195], 12,
                    "incorrect value for amplitude_value[195], expected 12, is {}",
                    msg.amplitude_value[195]
                );
                assert_eq!(
                    msg.amplitude_value[196], 140,
                    "incorrect value for amplitude_value[196], expected 140, is {}",
                    msg.amplitude_value[196]
                );
                assert_eq!(
                    msg.amplitude_value[197], 16,
                    "incorrect value for amplitude_value[197], expected 16, is {}",
                    msg.amplitude_value[197]
                );
                assert_eq!(
                    msg.amplitude_value[198], 247,
                    "incorrect value for amplitude_value[198], expected 247, is {}",
                    msg.amplitude_value[198]
                );
                assert_eq!(
                    msg.amplitude_value[199], 84,
                    "incorrect value for amplitude_value[199], expected 84, is {}",
                    msg.amplitude_value[199]
                );
                assert_eq!(
                    msg.amplitude_value[200], 183,
                    "incorrect value for amplitude_value[200], expected 183, is {}",
                    msg.amplitude_value[200]
                );
                assert_eq!(
                    msg.amplitude_value[201], 105,
                    "incorrect value for amplitude_value[201], expected 105, is {}",
                    msg.amplitude_value[201]
                );
                assert_eq!(
                    msg.amplitude_value[202], 39,
                    "incorrect value for amplitude_value[202], expected 39, is {}",
                    msg.amplitude_value[202]
                );
                assert_eq!(
                    msg.amplitude_value[203], 157,
                    "incorrect value for amplitude_value[203], expected 157, is {}",
                    msg.amplitude_value[203]
                );
                assert_eq!(
                    msg.amplitude_value[204], 77,
                    "incorrect value for amplitude_value[204], expected 77, is {}",
                    msg.amplitude_value[204]
                );
                assert_eq!(
                    msg.amplitude_value[205], 30,
                    "incorrect value for amplitude_value[205], expected 30, is {}",
                    msg.amplitude_value[205]
                );
                assert_eq!(
                    msg.amplitude_value[206], 205,
                    "incorrect value for amplitude_value[206], expected 205, is {}",
                    msg.amplitude_value[206]
                );
                assert_eq!(
                    msg.amplitude_value[207], 194,
                    "incorrect value for amplitude_value[207], expected 194, is {}",
                    msg.amplitude_value[207]
                );
                assert_eq!(
                    msg.amplitude_value[208], 59,
                    "incorrect value for amplitude_value[208], expected 59, is {}",
                    msg.amplitude_value[208]
                );
                assert_eq!(
                    msg.amplitude_value[209], 64,
                    "incorrect value for amplitude_value[209], expected 64, is {}",
                    msg.amplitude_value[209]
                );
                assert_eq!(
                    msg.amplitude_value[210], 241,
                    "incorrect value for amplitude_value[210], expected 241, is {}",
                    msg.amplitude_value[210]
                );
                assert_eq!(
                    msg.amplitude_value[211], 183,
                    "incorrect value for amplitude_value[211], expected 183, is {}",
                    msg.amplitude_value[211]
                );
                assert_eq!(
                    msg.amplitude_value[212], 238,
                    "incorrect value for amplitude_value[212], expected 238, is {}",
                    msg.amplitude_value[212]
                );
                assert_eq!(
                    msg.amplitude_value[213], 105,
                    "incorrect value for amplitude_value[213], expected 105, is {}",
                    msg.amplitude_value[213]
                );
                assert_eq!(
                    msg.amplitude_value[214], 181,
                    "incorrect value for amplitude_value[214], expected 181, is {}",
                    msg.amplitude_value[214]
                );
                assert_eq!(
                    msg.amplitude_value[215], 170,
                    "incorrect value for amplitude_value[215], expected 170, is {}",
                    msg.amplitude_value[215]
                );
                assert_eq!(
                    msg.amplitude_value[216], 45,
                    "incorrect value for amplitude_value[216], expected 45, is {}",
                    msg.amplitude_value[216]
                );
                assert_eq!(
                    msg.amplitude_value[217], 8,
                    "incorrect value for amplitude_value[217], expected 8, is {}",
                    msg.amplitude_value[217]
                );
                assert_eq!(
                    msg.amplitude_value[218], 166,
                    "incorrect value for amplitude_value[218], expected 166, is {}",
                    msg.amplitude_value[218]
                );
                assert_eq!(
                    msg.amplitude_value[219], 164,
                    "incorrect value for amplitude_value[219], expected 164, is {}",
                    msg.amplitude_value[219]
                );
                assert_eq!(
                    msg.amplitude_value[220], 238,
                    "incorrect value for amplitude_value[220], expected 238, is {}",
                    msg.amplitude_value[220]
                );
                assert_eq!(
                    msg.amplitude_value[221], 83,
                    "incorrect value for amplitude_value[221], expected 83, is {}",
                    msg.amplitude_value[221]
                );
                assert_eq!(
                    msg.amplitude_value[222], 148,
                    "incorrect value for amplitude_value[222], expected 148, is {}",
                    msg.amplitude_value[222]
                );
                assert_eq!(
                    msg.amplitude_value[223], 173,
                    "incorrect value for amplitude_value[223], expected 173, is {}",
                    msg.amplitude_value[223]
                );
                assert_eq!(
                    msg.amplitude_value[224], 108,
                    "incorrect value for amplitude_value[224], expected 108, is {}",
                    msg.amplitude_value[224]
                );
                assert_eq!(
                    msg.amplitude_value[225], 228,
                    "incorrect value for amplitude_value[225], expected 228, is {}",
                    msg.amplitude_value[225]
                );
                assert_eq!(
                    msg.amplitude_value[226], 67,
                    "incorrect value for amplitude_value[226], expected 67, is {}",
                    msg.amplitude_value[226]
                );
                assert_eq!(
                    msg.amplitude_value[227], 89,
                    "incorrect value for amplitude_value[227], expected 89, is {}",
                    msg.amplitude_value[227]
                );
                assert_eq!(
                    msg.amplitude_value[228], 189,
                    "incorrect value for amplitude_value[228], expected 189, is {}",
                    msg.amplitude_value[228]
                );
                assert_eq!(
                    msg.amplitude_value[229], 67,
                    "incorrect value for amplitude_value[229], expected 67, is {}",
                    msg.amplitude_value[229]
                );
                assert_eq!(
                    msg.amplitude_value[230], 26,
                    "incorrect value for amplitude_value[230], expected 26, is {}",
                    msg.amplitude_value[230]
                );
                assert_eq!(
                    msg.channel_tag, 5878,
                    "incorrect value for channel_tag, expected 5878, is {}",
                    msg.channel_tag
                );
                assert!(
                    msg.freq_ref.almost_eq(6.34820019531250000e+03),
                    "incorrect value for freq_ref, expected 6.34820019531250000e+03, is {:e}",
                    msg.freq_ref
                );
                assert!(
                    msg.freq_step.almost_eq(4.60820019531250000e+03),
                    "incorrect value for freq_step, expected 4.60820019531250000e+03, is {:e}",
                    msg.freq_step
                );
                assert_eq!(
                    msg.t.tow, 992295133,
                    "incorrect value for t.tow, expected 992295133, is {}",
                    msg.t.tow
                );
                assert_eq!(
                    msg.t.wn, 6957,
                    "incorrect value for t.wn, expected 6957, is {}",
                    msg.t.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSpecanDep"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_piksi_msg_specan_dep`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_piksi_msg_specan_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 80, 0, 112, 217, 255, 246, 22, 221, 56, 37, 59, 45, 27, 154, 97, 198, 69, 154, 1,
            144, 69, 205, 20, 18, 70, 51, 211, 89, 69, 240, 14, 179, 186, 227, 244, 173, 240, 182,
            71, 166, 117, 196, 13, 44, 27, 33, 28, 67, 254, 3, 249, 92, 44, 122, 169, 77, 186, 68,
            135, 63, 168, 162, 89, 36, 186, 99, 63, 105, 116, 216, 44, 67, 212, 156, 75, 81, 53,
            250, 225, 23, 205, 26, 34, 119, 50, 101, 64, 7, 231, 124, 183, 203, 102, 234, 84, 83,
            208, 23, 68, 54, 179, 98, 96, 116, 244, 246, 94, 104, 94, 13, 56, 210, 18, 191, 22,
            133, 81, 153, 159, 161, 219, 59, 21, 164, 121, 145, 203, 171, 132, 57, 180, 102, 101,
            11, 229, 175, 145, 73, 72, 124, 4, 184, 228, 61, 234, 218, 62, 226, 217, 193, 7, 109,
            44, 83, 201, 20, 101, 9, 140, 186, 162, 81, 91, 30, 231, 161, 81, 216, 114, 60, 231,
            163, 163, 49, 237, 244, 185, 240, 89, 143, 174, 165, 211, 241, 13, 16, 61, 141, 101,
            89, 37, 117, 189, 86, 118, 176, 228, 12, 14, 119, 135, 129, 243, 50, 29, 207, 198, 117,
            100, 225, 6, 139, 110, 39, 210, 68, 199, 43, 132, 64, 17, 51, 173, 181, 12, 140, 16,
            247, 84, 183, 105, 39, 157, 77, 30, 205, 194, 59, 64, 241, 183, 238, 105, 181, 170, 45,
            8, 166, 164, 238, 83, 148, 173, 108, 228, 67, 89, 189, 67, 26, 39, 216,
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
        let sbp_msg = sbp::messages::Sbp::MsgSpecanDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSpecanDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x50,
                    "Incorrect message type, expected 0x50, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd970,
                    "incorrect sender id, expected 0xd970, is {sender_id}"
                );
                assert!(
                    msg.amplitude_ref.almost_eq(9.34920019531250000e+03),
                    "incorrect value for amplitude_ref, expected 9.34920019531250000e+03, is {:e}",
                    msg.amplitude_ref
                );
                assert!(
                    msg.amplitude_unit.almost_eq(3.48519995117187500e+03),
                    "incorrect value for amplitude_unit, expected 3.48519995117187500e+03, is {:e}",
                    msg.amplitude_unit
                );
                assert_eq!(
                    msg.amplitude_value[0], 240,
                    "incorrect value for amplitude_value[0], expected 240, is {}",
                    msg.amplitude_value[0]
                );
                assert_eq!(
                    msg.amplitude_value[1], 14,
                    "incorrect value for amplitude_value[1], expected 14, is {}",
                    msg.amplitude_value[1]
                );
                assert_eq!(
                    msg.amplitude_value[2], 179,
                    "incorrect value for amplitude_value[2], expected 179, is {}",
                    msg.amplitude_value[2]
                );
                assert_eq!(
                    msg.amplitude_value[3], 186,
                    "incorrect value for amplitude_value[3], expected 186, is {}",
                    msg.amplitude_value[3]
                );
                assert_eq!(
                    msg.amplitude_value[4], 227,
                    "incorrect value for amplitude_value[4], expected 227, is {}",
                    msg.amplitude_value[4]
                );
                assert_eq!(
                    msg.amplitude_value[5], 244,
                    "incorrect value for amplitude_value[5], expected 244, is {}",
                    msg.amplitude_value[5]
                );
                assert_eq!(
                    msg.amplitude_value[6], 173,
                    "incorrect value for amplitude_value[6], expected 173, is {}",
                    msg.amplitude_value[6]
                );
                assert_eq!(
                    msg.amplitude_value[7], 240,
                    "incorrect value for amplitude_value[7], expected 240, is {}",
                    msg.amplitude_value[7]
                );
                assert_eq!(
                    msg.amplitude_value[8], 182,
                    "incorrect value for amplitude_value[8], expected 182, is {}",
                    msg.amplitude_value[8]
                );
                assert_eq!(
                    msg.amplitude_value[9], 71,
                    "incorrect value for amplitude_value[9], expected 71, is {}",
                    msg.amplitude_value[9]
                );
                assert_eq!(
                    msg.amplitude_value[10], 166,
                    "incorrect value for amplitude_value[10], expected 166, is {}",
                    msg.amplitude_value[10]
                );
                assert_eq!(
                    msg.amplitude_value[11], 117,
                    "incorrect value for amplitude_value[11], expected 117, is {}",
                    msg.amplitude_value[11]
                );
                assert_eq!(
                    msg.amplitude_value[12], 196,
                    "incorrect value for amplitude_value[12], expected 196, is {}",
                    msg.amplitude_value[12]
                );
                assert_eq!(
                    msg.amplitude_value[13], 13,
                    "incorrect value for amplitude_value[13], expected 13, is {}",
                    msg.amplitude_value[13]
                );
                assert_eq!(
                    msg.amplitude_value[14], 44,
                    "incorrect value for amplitude_value[14], expected 44, is {}",
                    msg.amplitude_value[14]
                );
                assert_eq!(
                    msg.amplitude_value[15], 27,
                    "incorrect value for amplitude_value[15], expected 27, is {}",
                    msg.amplitude_value[15]
                );
                assert_eq!(
                    msg.amplitude_value[16], 33,
                    "incorrect value for amplitude_value[16], expected 33, is {}",
                    msg.amplitude_value[16]
                );
                assert_eq!(
                    msg.amplitude_value[17], 28,
                    "incorrect value for amplitude_value[17], expected 28, is {}",
                    msg.amplitude_value[17]
                );
                assert_eq!(
                    msg.amplitude_value[18], 67,
                    "incorrect value for amplitude_value[18], expected 67, is {}",
                    msg.amplitude_value[18]
                );
                assert_eq!(
                    msg.amplitude_value[19], 254,
                    "incorrect value for amplitude_value[19], expected 254, is {}",
                    msg.amplitude_value[19]
                );
                assert_eq!(
                    msg.amplitude_value[20], 3,
                    "incorrect value for amplitude_value[20], expected 3, is {}",
                    msg.amplitude_value[20]
                );
                assert_eq!(
                    msg.amplitude_value[21], 249,
                    "incorrect value for amplitude_value[21], expected 249, is {}",
                    msg.amplitude_value[21]
                );
                assert_eq!(
                    msg.amplitude_value[22], 92,
                    "incorrect value for amplitude_value[22], expected 92, is {}",
                    msg.amplitude_value[22]
                );
                assert_eq!(
                    msg.amplitude_value[23], 44,
                    "incorrect value for amplitude_value[23], expected 44, is {}",
                    msg.amplitude_value[23]
                );
                assert_eq!(
                    msg.amplitude_value[24], 122,
                    "incorrect value for amplitude_value[24], expected 122, is {}",
                    msg.amplitude_value[24]
                );
                assert_eq!(
                    msg.amplitude_value[25], 169,
                    "incorrect value for amplitude_value[25], expected 169, is {}",
                    msg.amplitude_value[25]
                );
                assert_eq!(
                    msg.amplitude_value[26], 77,
                    "incorrect value for amplitude_value[26], expected 77, is {}",
                    msg.amplitude_value[26]
                );
                assert_eq!(
                    msg.amplitude_value[27], 186,
                    "incorrect value for amplitude_value[27], expected 186, is {}",
                    msg.amplitude_value[27]
                );
                assert_eq!(
                    msg.amplitude_value[28], 68,
                    "incorrect value for amplitude_value[28], expected 68, is {}",
                    msg.amplitude_value[28]
                );
                assert_eq!(
                    msg.amplitude_value[29], 135,
                    "incorrect value for amplitude_value[29], expected 135, is {}",
                    msg.amplitude_value[29]
                );
                assert_eq!(
                    msg.amplitude_value[30], 63,
                    "incorrect value for amplitude_value[30], expected 63, is {}",
                    msg.amplitude_value[30]
                );
                assert_eq!(
                    msg.amplitude_value[31], 168,
                    "incorrect value for amplitude_value[31], expected 168, is {}",
                    msg.amplitude_value[31]
                );
                assert_eq!(
                    msg.amplitude_value[32], 162,
                    "incorrect value for amplitude_value[32], expected 162, is {}",
                    msg.amplitude_value[32]
                );
                assert_eq!(
                    msg.amplitude_value[33], 89,
                    "incorrect value for amplitude_value[33], expected 89, is {}",
                    msg.amplitude_value[33]
                );
                assert_eq!(
                    msg.amplitude_value[34], 36,
                    "incorrect value for amplitude_value[34], expected 36, is {}",
                    msg.amplitude_value[34]
                );
                assert_eq!(
                    msg.amplitude_value[35], 186,
                    "incorrect value for amplitude_value[35], expected 186, is {}",
                    msg.amplitude_value[35]
                );
                assert_eq!(
                    msg.amplitude_value[36], 99,
                    "incorrect value for amplitude_value[36], expected 99, is {}",
                    msg.amplitude_value[36]
                );
                assert_eq!(
                    msg.amplitude_value[37], 63,
                    "incorrect value for amplitude_value[37], expected 63, is {}",
                    msg.amplitude_value[37]
                );
                assert_eq!(
                    msg.amplitude_value[38], 105,
                    "incorrect value for amplitude_value[38], expected 105, is {}",
                    msg.amplitude_value[38]
                );
                assert_eq!(
                    msg.amplitude_value[39], 116,
                    "incorrect value for amplitude_value[39], expected 116, is {}",
                    msg.amplitude_value[39]
                );
                assert_eq!(
                    msg.amplitude_value[40], 216,
                    "incorrect value for amplitude_value[40], expected 216, is {}",
                    msg.amplitude_value[40]
                );
                assert_eq!(
                    msg.amplitude_value[41], 44,
                    "incorrect value for amplitude_value[41], expected 44, is {}",
                    msg.amplitude_value[41]
                );
                assert_eq!(
                    msg.amplitude_value[42], 67,
                    "incorrect value for amplitude_value[42], expected 67, is {}",
                    msg.amplitude_value[42]
                );
                assert_eq!(
                    msg.amplitude_value[43], 212,
                    "incorrect value for amplitude_value[43], expected 212, is {}",
                    msg.amplitude_value[43]
                );
                assert_eq!(
                    msg.amplitude_value[44], 156,
                    "incorrect value for amplitude_value[44], expected 156, is {}",
                    msg.amplitude_value[44]
                );
                assert_eq!(
                    msg.amplitude_value[45], 75,
                    "incorrect value for amplitude_value[45], expected 75, is {}",
                    msg.amplitude_value[45]
                );
                assert_eq!(
                    msg.amplitude_value[46], 81,
                    "incorrect value for amplitude_value[46], expected 81, is {}",
                    msg.amplitude_value[46]
                );
                assert_eq!(
                    msg.amplitude_value[47], 53,
                    "incorrect value for amplitude_value[47], expected 53, is {}",
                    msg.amplitude_value[47]
                );
                assert_eq!(
                    msg.amplitude_value[48], 250,
                    "incorrect value for amplitude_value[48], expected 250, is {}",
                    msg.amplitude_value[48]
                );
                assert_eq!(
                    msg.amplitude_value[49], 225,
                    "incorrect value for amplitude_value[49], expected 225, is {}",
                    msg.amplitude_value[49]
                );
                assert_eq!(
                    msg.amplitude_value[50], 23,
                    "incorrect value for amplitude_value[50], expected 23, is {}",
                    msg.amplitude_value[50]
                );
                assert_eq!(
                    msg.amplitude_value[51], 205,
                    "incorrect value for amplitude_value[51], expected 205, is {}",
                    msg.amplitude_value[51]
                );
                assert_eq!(
                    msg.amplitude_value[52], 26,
                    "incorrect value for amplitude_value[52], expected 26, is {}",
                    msg.amplitude_value[52]
                );
                assert_eq!(
                    msg.amplitude_value[53], 34,
                    "incorrect value for amplitude_value[53], expected 34, is {}",
                    msg.amplitude_value[53]
                );
                assert_eq!(
                    msg.amplitude_value[54], 119,
                    "incorrect value for amplitude_value[54], expected 119, is {}",
                    msg.amplitude_value[54]
                );
                assert_eq!(
                    msg.amplitude_value[55], 50,
                    "incorrect value for amplitude_value[55], expected 50, is {}",
                    msg.amplitude_value[55]
                );
                assert_eq!(
                    msg.amplitude_value[56], 101,
                    "incorrect value for amplitude_value[56], expected 101, is {}",
                    msg.amplitude_value[56]
                );
                assert_eq!(
                    msg.amplitude_value[57], 64,
                    "incorrect value for amplitude_value[57], expected 64, is {}",
                    msg.amplitude_value[57]
                );
                assert_eq!(
                    msg.amplitude_value[58], 7,
                    "incorrect value for amplitude_value[58], expected 7, is {}",
                    msg.amplitude_value[58]
                );
                assert_eq!(
                    msg.amplitude_value[59], 231,
                    "incorrect value for amplitude_value[59], expected 231, is {}",
                    msg.amplitude_value[59]
                );
                assert_eq!(
                    msg.amplitude_value[60], 124,
                    "incorrect value for amplitude_value[60], expected 124, is {}",
                    msg.amplitude_value[60]
                );
                assert_eq!(
                    msg.amplitude_value[61], 183,
                    "incorrect value for amplitude_value[61], expected 183, is {}",
                    msg.amplitude_value[61]
                );
                assert_eq!(
                    msg.amplitude_value[62], 203,
                    "incorrect value for amplitude_value[62], expected 203, is {}",
                    msg.amplitude_value[62]
                );
                assert_eq!(
                    msg.amplitude_value[63], 102,
                    "incorrect value for amplitude_value[63], expected 102, is {}",
                    msg.amplitude_value[63]
                );
                assert_eq!(
                    msg.amplitude_value[64], 234,
                    "incorrect value for amplitude_value[64], expected 234, is {}",
                    msg.amplitude_value[64]
                );
                assert_eq!(
                    msg.amplitude_value[65], 84,
                    "incorrect value for amplitude_value[65], expected 84, is {}",
                    msg.amplitude_value[65]
                );
                assert_eq!(
                    msg.amplitude_value[66], 83,
                    "incorrect value for amplitude_value[66], expected 83, is {}",
                    msg.amplitude_value[66]
                );
                assert_eq!(
                    msg.amplitude_value[67], 208,
                    "incorrect value for amplitude_value[67], expected 208, is {}",
                    msg.amplitude_value[67]
                );
                assert_eq!(
                    msg.amplitude_value[68], 23,
                    "incorrect value for amplitude_value[68], expected 23, is {}",
                    msg.amplitude_value[68]
                );
                assert_eq!(
                    msg.amplitude_value[69], 68,
                    "incorrect value for amplitude_value[69], expected 68, is {}",
                    msg.amplitude_value[69]
                );
                assert_eq!(
                    msg.amplitude_value[70], 54,
                    "incorrect value for amplitude_value[70], expected 54, is {}",
                    msg.amplitude_value[70]
                );
                assert_eq!(
                    msg.amplitude_value[71], 179,
                    "incorrect value for amplitude_value[71], expected 179, is {}",
                    msg.amplitude_value[71]
                );
                assert_eq!(
                    msg.amplitude_value[72], 98,
                    "incorrect value for amplitude_value[72], expected 98, is {}",
                    msg.amplitude_value[72]
                );
                assert_eq!(
                    msg.amplitude_value[73], 96,
                    "incorrect value for amplitude_value[73], expected 96, is {}",
                    msg.amplitude_value[73]
                );
                assert_eq!(
                    msg.amplitude_value[74], 116,
                    "incorrect value for amplitude_value[74], expected 116, is {}",
                    msg.amplitude_value[74]
                );
                assert_eq!(
                    msg.amplitude_value[75], 244,
                    "incorrect value for amplitude_value[75], expected 244, is {}",
                    msg.amplitude_value[75]
                );
                assert_eq!(
                    msg.amplitude_value[76], 246,
                    "incorrect value for amplitude_value[76], expected 246, is {}",
                    msg.amplitude_value[76]
                );
                assert_eq!(
                    msg.amplitude_value[77], 94,
                    "incorrect value for amplitude_value[77], expected 94, is {}",
                    msg.amplitude_value[77]
                );
                assert_eq!(
                    msg.amplitude_value[78], 104,
                    "incorrect value for amplitude_value[78], expected 104, is {}",
                    msg.amplitude_value[78]
                );
                assert_eq!(
                    msg.amplitude_value[79], 94,
                    "incorrect value for amplitude_value[79], expected 94, is {}",
                    msg.amplitude_value[79]
                );
                assert_eq!(
                    msg.amplitude_value[80], 13,
                    "incorrect value for amplitude_value[80], expected 13, is {}",
                    msg.amplitude_value[80]
                );
                assert_eq!(
                    msg.amplitude_value[81], 56,
                    "incorrect value for amplitude_value[81], expected 56, is {}",
                    msg.amplitude_value[81]
                );
                assert_eq!(
                    msg.amplitude_value[82], 210,
                    "incorrect value for amplitude_value[82], expected 210, is {}",
                    msg.amplitude_value[82]
                );
                assert_eq!(
                    msg.amplitude_value[83], 18,
                    "incorrect value for amplitude_value[83], expected 18, is {}",
                    msg.amplitude_value[83]
                );
                assert_eq!(
                    msg.amplitude_value[84], 191,
                    "incorrect value for amplitude_value[84], expected 191, is {}",
                    msg.amplitude_value[84]
                );
                assert_eq!(
                    msg.amplitude_value[85], 22,
                    "incorrect value for amplitude_value[85], expected 22, is {}",
                    msg.amplitude_value[85]
                );
                assert_eq!(
                    msg.amplitude_value[86], 133,
                    "incorrect value for amplitude_value[86], expected 133, is {}",
                    msg.amplitude_value[86]
                );
                assert_eq!(
                    msg.amplitude_value[87], 81,
                    "incorrect value for amplitude_value[87], expected 81, is {}",
                    msg.amplitude_value[87]
                );
                assert_eq!(
                    msg.amplitude_value[88], 153,
                    "incorrect value for amplitude_value[88], expected 153, is {}",
                    msg.amplitude_value[88]
                );
                assert_eq!(
                    msg.amplitude_value[89], 159,
                    "incorrect value for amplitude_value[89], expected 159, is {}",
                    msg.amplitude_value[89]
                );
                assert_eq!(
                    msg.amplitude_value[90], 161,
                    "incorrect value for amplitude_value[90], expected 161, is {}",
                    msg.amplitude_value[90]
                );
                assert_eq!(
                    msg.amplitude_value[91], 219,
                    "incorrect value for amplitude_value[91], expected 219, is {}",
                    msg.amplitude_value[91]
                );
                assert_eq!(
                    msg.amplitude_value[92], 59,
                    "incorrect value for amplitude_value[92], expected 59, is {}",
                    msg.amplitude_value[92]
                );
                assert_eq!(
                    msg.amplitude_value[93], 21,
                    "incorrect value for amplitude_value[93], expected 21, is {}",
                    msg.amplitude_value[93]
                );
                assert_eq!(
                    msg.amplitude_value[94], 164,
                    "incorrect value for amplitude_value[94], expected 164, is {}",
                    msg.amplitude_value[94]
                );
                assert_eq!(
                    msg.amplitude_value[95], 121,
                    "incorrect value for amplitude_value[95], expected 121, is {}",
                    msg.amplitude_value[95]
                );
                assert_eq!(
                    msg.amplitude_value[96], 145,
                    "incorrect value for amplitude_value[96], expected 145, is {}",
                    msg.amplitude_value[96]
                );
                assert_eq!(
                    msg.amplitude_value[97], 203,
                    "incorrect value for amplitude_value[97], expected 203, is {}",
                    msg.amplitude_value[97]
                );
                assert_eq!(
                    msg.amplitude_value[98], 171,
                    "incorrect value for amplitude_value[98], expected 171, is {}",
                    msg.amplitude_value[98]
                );
                assert_eq!(
                    msg.amplitude_value[99], 132,
                    "incorrect value for amplitude_value[99], expected 132, is {}",
                    msg.amplitude_value[99]
                );
                assert_eq!(
                    msg.amplitude_value[100], 57,
                    "incorrect value for amplitude_value[100], expected 57, is {}",
                    msg.amplitude_value[100]
                );
                assert_eq!(
                    msg.amplitude_value[101], 180,
                    "incorrect value for amplitude_value[101], expected 180, is {}",
                    msg.amplitude_value[101]
                );
                assert_eq!(
                    msg.amplitude_value[102], 102,
                    "incorrect value for amplitude_value[102], expected 102, is {}",
                    msg.amplitude_value[102]
                );
                assert_eq!(
                    msg.amplitude_value[103], 101,
                    "incorrect value for amplitude_value[103], expected 101, is {}",
                    msg.amplitude_value[103]
                );
                assert_eq!(
                    msg.amplitude_value[104], 11,
                    "incorrect value for amplitude_value[104], expected 11, is {}",
                    msg.amplitude_value[104]
                );
                assert_eq!(
                    msg.amplitude_value[105], 229,
                    "incorrect value for amplitude_value[105], expected 229, is {}",
                    msg.amplitude_value[105]
                );
                assert_eq!(
                    msg.amplitude_value[106], 175,
                    "incorrect value for amplitude_value[106], expected 175, is {}",
                    msg.amplitude_value[106]
                );
                assert_eq!(
                    msg.amplitude_value[107], 145,
                    "incorrect value for amplitude_value[107], expected 145, is {}",
                    msg.amplitude_value[107]
                );
                assert_eq!(
                    msg.amplitude_value[108], 73,
                    "incorrect value for amplitude_value[108], expected 73, is {}",
                    msg.amplitude_value[108]
                );
                assert_eq!(
                    msg.amplitude_value[109], 72,
                    "incorrect value for amplitude_value[109], expected 72, is {}",
                    msg.amplitude_value[109]
                );
                assert_eq!(
                    msg.amplitude_value[110], 124,
                    "incorrect value for amplitude_value[110], expected 124, is {}",
                    msg.amplitude_value[110]
                );
                assert_eq!(
                    msg.amplitude_value[111], 4,
                    "incorrect value for amplitude_value[111], expected 4, is {}",
                    msg.amplitude_value[111]
                );
                assert_eq!(
                    msg.amplitude_value[112], 184,
                    "incorrect value for amplitude_value[112], expected 184, is {}",
                    msg.amplitude_value[112]
                );
                assert_eq!(
                    msg.amplitude_value[113], 228,
                    "incorrect value for amplitude_value[113], expected 228, is {}",
                    msg.amplitude_value[113]
                );
                assert_eq!(
                    msg.amplitude_value[114], 61,
                    "incorrect value for amplitude_value[114], expected 61, is {}",
                    msg.amplitude_value[114]
                );
                assert_eq!(
                    msg.amplitude_value[115], 234,
                    "incorrect value for amplitude_value[115], expected 234, is {}",
                    msg.amplitude_value[115]
                );
                assert_eq!(
                    msg.amplitude_value[116], 218,
                    "incorrect value for amplitude_value[116], expected 218, is {}",
                    msg.amplitude_value[116]
                );
                assert_eq!(
                    msg.amplitude_value[117], 62,
                    "incorrect value for amplitude_value[117], expected 62, is {}",
                    msg.amplitude_value[117]
                );
                assert_eq!(
                    msg.amplitude_value[118], 226,
                    "incorrect value for amplitude_value[118], expected 226, is {}",
                    msg.amplitude_value[118]
                );
                assert_eq!(
                    msg.amplitude_value[119], 217,
                    "incorrect value for amplitude_value[119], expected 217, is {}",
                    msg.amplitude_value[119]
                );
                assert_eq!(
                    msg.amplitude_value[120], 193,
                    "incorrect value for amplitude_value[120], expected 193, is {}",
                    msg.amplitude_value[120]
                );
                assert_eq!(
                    msg.amplitude_value[121], 7,
                    "incorrect value for amplitude_value[121], expected 7, is {}",
                    msg.amplitude_value[121]
                );
                assert_eq!(
                    msg.amplitude_value[122], 109,
                    "incorrect value for amplitude_value[122], expected 109, is {}",
                    msg.amplitude_value[122]
                );
                assert_eq!(
                    msg.amplitude_value[123], 44,
                    "incorrect value for amplitude_value[123], expected 44, is {}",
                    msg.amplitude_value[123]
                );
                assert_eq!(
                    msg.amplitude_value[124], 83,
                    "incorrect value for amplitude_value[124], expected 83, is {}",
                    msg.amplitude_value[124]
                );
                assert_eq!(
                    msg.amplitude_value[125], 201,
                    "incorrect value for amplitude_value[125], expected 201, is {}",
                    msg.amplitude_value[125]
                );
                assert_eq!(
                    msg.amplitude_value[126], 20,
                    "incorrect value for amplitude_value[126], expected 20, is {}",
                    msg.amplitude_value[126]
                );
                assert_eq!(
                    msg.amplitude_value[127], 101,
                    "incorrect value for amplitude_value[127], expected 101, is {}",
                    msg.amplitude_value[127]
                );
                assert_eq!(
                    msg.amplitude_value[128], 9,
                    "incorrect value for amplitude_value[128], expected 9, is {}",
                    msg.amplitude_value[128]
                );
                assert_eq!(
                    msg.amplitude_value[129], 140,
                    "incorrect value for amplitude_value[129], expected 140, is {}",
                    msg.amplitude_value[129]
                );
                assert_eq!(
                    msg.amplitude_value[130], 186,
                    "incorrect value for amplitude_value[130], expected 186, is {}",
                    msg.amplitude_value[130]
                );
                assert_eq!(
                    msg.amplitude_value[131], 162,
                    "incorrect value for amplitude_value[131], expected 162, is {}",
                    msg.amplitude_value[131]
                );
                assert_eq!(
                    msg.amplitude_value[132], 81,
                    "incorrect value for amplitude_value[132], expected 81, is {}",
                    msg.amplitude_value[132]
                );
                assert_eq!(
                    msg.amplitude_value[133], 91,
                    "incorrect value for amplitude_value[133], expected 91, is {}",
                    msg.amplitude_value[133]
                );
                assert_eq!(
                    msg.amplitude_value[134], 30,
                    "incorrect value for amplitude_value[134], expected 30, is {}",
                    msg.amplitude_value[134]
                );
                assert_eq!(
                    msg.amplitude_value[135], 231,
                    "incorrect value for amplitude_value[135], expected 231, is {}",
                    msg.amplitude_value[135]
                );
                assert_eq!(
                    msg.amplitude_value[136], 161,
                    "incorrect value for amplitude_value[136], expected 161, is {}",
                    msg.amplitude_value[136]
                );
                assert_eq!(
                    msg.amplitude_value[137], 81,
                    "incorrect value for amplitude_value[137], expected 81, is {}",
                    msg.amplitude_value[137]
                );
                assert_eq!(
                    msg.amplitude_value[138], 216,
                    "incorrect value for amplitude_value[138], expected 216, is {}",
                    msg.amplitude_value[138]
                );
                assert_eq!(
                    msg.amplitude_value[139], 114,
                    "incorrect value for amplitude_value[139], expected 114, is {}",
                    msg.amplitude_value[139]
                );
                assert_eq!(
                    msg.amplitude_value[140], 60,
                    "incorrect value for amplitude_value[140], expected 60, is {}",
                    msg.amplitude_value[140]
                );
                assert_eq!(
                    msg.amplitude_value[141], 231,
                    "incorrect value for amplitude_value[141], expected 231, is {}",
                    msg.amplitude_value[141]
                );
                assert_eq!(
                    msg.amplitude_value[142], 163,
                    "incorrect value for amplitude_value[142], expected 163, is {}",
                    msg.amplitude_value[142]
                );
                assert_eq!(
                    msg.amplitude_value[143], 163,
                    "incorrect value for amplitude_value[143], expected 163, is {}",
                    msg.amplitude_value[143]
                );
                assert_eq!(
                    msg.amplitude_value[144], 49,
                    "incorrect value for amplitude_value[144], expected 49, is {}",
                    msg.amplitude_value[144]
                );
                assert_eq!(
                    msg.amplitude_value[145], 237,
                    "incorrect value for amplitude_value[145], expected 237, is {}",
                    msg.amplitude_value[145]
                );
                assert_eq!(
                    msg.amplitude_value[146], 244,
                    "incorrect value for amplitude_value[146], expected 244, is {}",
                    msg.amplitude_value[146]
                );
                assert_eq!(
                    msg.amplitude_value[147], 185,
                    "incorrect value for amplitude_value[147], expected 185, is {}",
                    msg.amplitude_value[147]
                );
                assert_eq!(
                    msg.amplitude_value[148], 240,
                    "incorrect value for amplitude_value[148], expected 240, is {}",
                    msg.amplitude_value[148]
                );
                assert_eq!(
                    msg.amplitude_value[149], 89,
                    "incorrect value for amplitude_value[149], expected 89, is {}",
                    msg.amplitude_value[149]
                );
                assert_eq!(
                    msg.amplitude_value[150], 143,
                    "incorrect value for amplitude_value[150], expected 143, is {}",
                    msg.amplitude_value[150]
                );
                assert_eq!(
                    msg.amplitude_value[151], 174,
                    "incorrect value for amplitude_value[151], expected 174, is {}",
                    msg.amplitude_value[151]
                );
                assert_eq!(
                    msg.amplitude_value[152], 165,
                    "incorrect value for amplitude_value[152], expected 165, is {}",
                    msg.amplitude_value[152]
                );
                assert_eq!(
                    msg.amplitude_value[153], 211,
                    "incorrect value for amplitude_value[153], expected 211, is {}",
                    msg.amplitude_value[153]
                );
                assert_eq!(
                    msg.amplitude_value[154], 241,
                    "incorrect value for amplitude_value[154], expected 241, is {}",
                    msg.amplitude_value[154]
                );
                assert_eq!(
                    msg.amplitude_value[155], 13,
                    "incorrect value for amplitude_value[155], expected 13, is {}",
                    msg.amplitude_value[155]
                );
                assert_eq!(
                    msg.amplitude_value[156], 16,
                    "incorrect value for amplitude_value[156], expected 16, is {}",
                    msg.amplitude_value[156]
                );
                assert_eq!(
                    msg.amplitude_value[157], 61,
                    "incorrect value for amplitude_value[157], expected 61, is {}",
                    msg.amplitude_value[157]
                );
                assert_eq!(
                    msg.amplitude_value[158], 141,
                    "incorrect value for amplitude_value[158], expected 141, is {}",
                    msg.amplitude_value[158]
                );
                assert_eq!(
                    msg.amplitude_value[159], 101,
                    "incorrect value for amplitude_value[159], expected 101, is {}",
                    msg.amplitude_value[159]
                );
                assert_eq!(
                    msg.amplitude_value[160], 89,
                    "incorrect value for amplitude_value[160], expected 89, is {}",
                    msg.amplitude_value[160]
                );
                assert_eq!(
                    msg.amplitude_value[161], 37,
                    "incorrect value for amplitude_value[161], expected 37, is {}",
                    msg.amplitude_value[161]
                );
                assert_eq!(
                    msg.amplitude_value[162], 117,
                    "incorrect value for amplitude_value[162], expected 117, is {}",
                    msg.amplitude_value[162]
                );
                assert_eq!(
                    msg.amplitude_value[163], 189,
                    "incorrect value for amplitude_value[163], expected 189, is {}",
                    msg.amplitude_value[163]
                );
                assert_eq!(
                    msg.amplitude_value[164], 86,
                    "incorrect value for amplitude_value[164], expected 86, is {}",
                    msg.amplitude_value[164]
                );
                assert_eq!(
                    msg.amplitude_value[165], 118,
                    "incorrect value for amplitude_value[165], expected 118, is {}",
                    msg.amplitude_value[165]
                );
                assert_eq!(
                    msg.amplitude_value[166], 176,
                    "incorrect value for amplitude_value[166], expected 176, is {}",
                    msg.amplitude_value[166]
                );
                assert_eq!(
                    msg.amplitude_value[167], 228,
                    "incorrect value for amplitude_value[167], expected 228, is {}",
                    msg.amplitude_value[167]
                );
                assert_eq!(
                    msg.amplitude_value[168], 12,
                    "incorrect value for amplitude_value[168], expected 12, is {}",
                    msg.amplitude_value[168]
                );
                assert_eq!(
                    msg.amplitude_value[169], 14,
                    "incorrect value for amplitude_value[169], expected 14, is {}",
                    msg.amplitude_value[169]
                );
                assert_eq!(
                    msg.amplitude_value[170], 119,
                    "incorrect value for amplitude_value[170], expected 119, is {}",
                    msg.amplitude_value[170]
                );
                assert_eq!(
                    msg.amplitude_value[171], 135,
                    "incorrect value for amplitude_value[171], expected 135, is {}",
                    msg.amplitude_value[171]
                );
                assert_eq!(
                    msg.amplitude_value[172], 129,
                    "incorrect value for amplitude_value[172], expected 129, is {}",
                    msg.amplitude_value[172]
                );
                assert_eq!(
                    msg.amplitude_value[173], 243,
                    "incorrect value for amplitude_value[173], expected 243, is {}",
                    msg.amplitude_value[173]
                );
                assert_eq!(
                    msg.amplitude_value[174], 50,
                    "incorrect value for amplitude_value[174], expected 50, is {}",
                    msg.amplitude_value[174]
                );
                assert_eq!(
                    msg.amplitude_value[175], 29,
                    "incorrect value for amplitude_value[175], expected 29, is {}",
                    msg.amplitude_value[175]
                );
                assert_eq!(
                    msg.amplitude_value[176], 207,
                    "incorrect value for amplitude_value[176], expected 207, is {}",
                    msg.amplitude_value[176]
                );
                assert_eq!(
                    msg.amplitude_value[177], 198,
                    "incorrect value for amplitude_value[177], expected 198, is {}",
                    msg.amplitude_value[177]
                );
                assert_eq!(
                    msg.amplitude_value[178], 117,
                    "incorrect value for amplitude_value[178], expected 117, is {}",
                    msg.amplitude_value[178]
                );
                assert_eq!(
                    msg.amplitude_value[179], 100,
                    "incorrect value for amplitude_value[179], expected 100, is {}",
                    msg.amplitude_value[179]
                );
                assert_eq!(
                    msg.amplitude_value[180], 225,
                    "incorrect value for amplitude_value[180], expected 225, is {}",
                    msg.amplitude_value[180]
                );
                assert_eq!(
                    msg.amplitude_value[181], 6,
                    "incorrect value for amplitude_value[181], expected 6, is {}",
                    msg.amplitude_value[181]
                );
                assert_eq!(
                    msg.amplitude_value[182], 139,
                    "incorrect value for amplitude_value[182], expected 139, is {}",
                    msg.amplitude_value[182]
                );
                assert_eq!(
                    msg.amplitude_value[183], 110,
                    "incorrect value for amplitude_value[183], expected 110, is {}",
                    msg.amplitude_value[183]
                );
                assert_eq!(
                    msg.amplitude_value[184], 39,
                    "incorrect value for amplitude_value[184], expected 39, is {}",
                    msg.amplitude_value[184]
                );
                assert_eq!(
                    msg.amplitude_value[185], 210,
                    "incorrect value for amplitude_value[185], expected 210, is {}",
                    msg.amplitude_value[185]
                );
                assert_eq!(
                    msg.amplitude_value[186], 68,
                    "incorrect value for amplitude_value[186], expected 68, is {}",
                    msg.amplitude_value[186]
                );
                assert_eq!(
                    msg.amplitude_value[187], 199,
                    "incorrect value for amplitude_value[187], expected 199, is {}",
                    msg.amplitude_value[187]
                );
                assert_eq!(
                    msg.amplitude_value[188], 43,
                    "incorrect value for amplitude_value[188], expected 43, is {}",
                    msg.amplitude_value[188]
                );
                assert_eq!(
                    msg.amplitude_value[189], 132,
                    "incorrect value for amplitude_value[189], expected 132, is {}",
                    msg.amplitude_value[189]
                );
                assert_eq!(
                    msg.amplitude_value[190], 64,
                    "incorrect value for amplitude_value[190], expected 64, is {}",
                    msg.amplitude_value[190]
                );
                assert_eq!(
                    msg.amplitude_value[191], 17,
                    "incorrect value for amplitude_value[191], expected 17, is {}",
                    msg.amplitude_value[191]
                );
                assert_eq!(
                    msg.amplitude_value[192], 51,
                    "incorrect value for amplitude_value[192], expected 51, is {}",
                    msg.amplitude_value[192]
                );
                assert_eq!(
                    msg.amplitude_value[193], 173,
                    "incorrect value for amplitude_value[193], expected 173, is {}",
                    msg.amplitude_value[193]
                );
                assert_eq!(
                    msg.amplitude_value[194], 181,
                    "incorrect value for amplitude_value[194], expected 181, is {}",
                    msg.amplitude_value[194]
                );
                assert_eq!(
                    msg.amplitude_value[195], 12,
                    "incorrect value for amplitude_value[195], expected 12, is {}",
                    msg.amplitude_value[195]
                );
                assert_eq!(
                    msg.amplitude_value[196], 140,
                    "incorrect value for amplitude_value[196], expected 140, is {}",
                    msg.amplitude_value[196]
                );
                assert_eq!(
                    msg.amplitude_value[197], 16,
                    "incorrect value for amplitude_value[197], expected 16, is {}",
                    msg.amplitude_value[197]
                );
                assert_eq!(
                    msg.amplitude_value[198], 247,
                    "incorrect value for amplitude_value[198], expected 247, is {}",
                    msg.amplitude_value[198]
                );
                assert_eq!(
                    msg.amplitude_value[199], 84,
                    "incorrect value for amplitude_value[199], expected 84, is {}",
                    msg.amplitude_value[199]
                );
                assert_eq!(
                    msg.amplitude_value[200], 183,
                    "incorrect value for amplitude_value[200], expected 183, is {}",
                    msg.amplitude_value[200]
                );
                assert_eq!(
                    msg.amplitude_value[201], 105,
                    "incorrect value for amplitude_value[201], expected 105, is {}",
                    msg.amplitude_value[201]
                );
                assert_eq!(
                    msg.amplitude_value[202], 39,
                    "incorrect value for amplitude_value[202], expected 39, is {}",
                    msg.amplitude_value[202]
                );
                assert_eq!(
                    msg.amplitude_value[203], 157,
                    "incorrect value for amplitude_value[203], expected 157, is {}",
                    msg.amplitude_value[203]
                );
                assert_eq!(
                    msg.amplitude_value[204], 77,
                    "incorrect value for amplitude_value[204], expected 77, is {}",
                    msg.amplitude_value[204]
                );
                assert_eq!(
                    msg.amplitude_value[205], 30,
                    "incorrect value for amplitude_value[205], expected 30, is {}",
                    msg.amplitude_value[205]
                );
                assert_eq!(
                    msg.amplitude_value[206], 205,
                    "incorrect value for amplitude_value[206], expected 205, is {}",
                    msg.amplitude_value[206]
                );
                assert_eq!(
                    msg.amplitude_value[207], 194,
                    "incorrect value for amplitude_value[207], expected 194, is {}",
                    msg.amplitude_value[207]
                );
                assert_eq!(
                    msg.amplitude_value[208], 59,
                    "incorrect value for amplitude_value[208], expected 59, is {}",
                    msg.amplitude_value[208]
                );
                assert_eq!(
                    msg.amplitude_value[209], 64,
                    "incorrect value for amplitude_value[209], expected 64, is {}",
                    msg.amplitude_value[209]
                );
                assert_eq!(
                    msg.amplitude_value[210], 241,
                    "incorrect value for amplitude_value[210], expected 241, is {}",
                    msg.amplitude_value[210]
                );
                assert_eq!(
                    msg.amplitude_value[211], 183,
                    "incorrect value for amplitude_value[211], expected 183, is {}",
                    msg.amplitude_value[211]
                );
                assert_eq!(
                    msg.amplitude_value[212], 238,
                    "incorrect value for amplitude_value[212], expected 238, is {}",
                    msg.amplitude_value[212]
                );
                assert_eq!(
                    msg.amplitude_value[213], 105,
                    "incorrect value for amplitude_value[213], expected 105, is {}",
                    msg.amplitude_value[213]
                );
                assert_eq!(
                    msg.amplitude_value[214], 181,
                    "incorrect value for amplitude_value[214], expected 181, is {}",
                    msg.amplitude_value[214]
                );
                assert_eq!(
                    msg.amplitude_value[215], 170,
                    "incorrect value for amplitude_value[215], expected 170, is {}",
                    msg.amplitude_value[215]
                );
                assert_eq!(
                    msg.amplitude_value[216], 45,
                    "incorrect value for amplitude_value[216], expected 45, is {}",
                    msg.amplitude_value[216]
                );
                assert_eq!(
                    msg.amplitude_value[217], 8,
                    "incorrect value for amplitude_value[217], expected 8, is {}",
                    msg.amplitude_value[217]
                );
                assert_eq!(
                    msg.amplitude_value[218], 166,
                    "incorrect value for amplitude_value[218], expected 166, is {}",
                    msg.amplitude_value[218]
                );
                assert_eq!(
                    msg.amplitude_value[219], 164,
                    "incorrect value for amplitude_value[219], expected 164, is {}",
                    msg.amplitude_value[219]
                );
                assert_eq!(
                    msg.amplitude_value[220], 238,
                    "incorrect value for amplitude_value[220], expected 238, is {}",
                    msg.amplitude_value[220]
                );
                assert_eq!(
                    msg.amplitude_value[221], 83,
                    "incorrect value for amplitude_value[221], expected 83, is {}",
                    msg.amplitude_value[221]
                );
                assert_eq!(
                    msg.amplitude_value[222], 148,
                    "incorrect value for amplitude_value[222], expected 148, is {}",
                    msg.amplitude_value[222]
                );
                assert_eq!(
                    msg.amplitude_value[223], 173,
                    "incorrect value for amplitude_value[223], expected 173, is {}",
                    msg.amplitude_value[223]
                );
                assert_eq!(
                    msg.amplitude_value[224], 108,
                    "incorrect value for amplitude_value[224], expected 108, is {}",
                    msg.amplitude_value[224]
                );
                assert_eq!(
                    msg.amplitude_value[225], 228,
                    "incorrect value for amplitude_value[225], expected 228, is {}",
                    msg.amplitude_value[225]
                );
                assert_eq!(
                    msg.amplitude_value[226], 67,
                    "incorrect value for amplitude_value[226], expected 67, is {}",
                    msg.amplitude_value[226]
                );
                assert_eq!(
                    msg.amplitude_value[227], 89,
                    "incorrect value for amplitude_value[227], expected 89, is {}",
                    msg.amplitude_value[227]
                );
                assert_eq!(
                    msg.amplitude_value[228], 189,
                    "incorrect value for amplitude_value[228], expected 189, is {}",
                    msg.amplitude_value[228]
                );
                assert_eq!(
                    msg.amplitude_value[229], 67,
                    "incorrect value for amplitude_value[229], expected 67, is {}",
                    msg.amplitude_value[229]
                );
                assert_eq!(
                    msg.amplitude_value[230], 26,
                    "incorrect value for amplitude_value[230], expected 26, is {}",
                    msg.amplitude_value[230]
                );
                assert_eq!(
                    msg.channel_tag, 5878,
                    "incorrect value for channel_tag, expected 5878, is {}",
                    msg.channel_tag
                );
                assert!(
                    msg.freq_ref.almost_eq(6.34820019531250000e+03),
                    "incorrect value for freq_ref, expected 6.34820019531250000e+03, is {:e}",
                    msg.freq_ref
                );
                assert!(
                    msg.freq_step.almost_eq(4.60820019531250000e+03),
                    "incorrect value for freq_step, expected 4.60820019531250000e+03, is {:e}",
                    msg.freq_step
                );
                assert_eq!(
                    msg.t.tow, 992295133,
                    "incorrect value for t.tow, expected 992295133, is {}",
                    msg.t.tow
                );
                assert_eq!(
                    msg.t.wn, 6957,
                    "incorrect value for t.wn, expected 6957, is {}",
                    msg.t.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSpecanDep"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
