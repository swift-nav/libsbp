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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrPhaseBiases.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_phase_biases() {
    {
        let mut payload = Cursor::new(vec![
            85, 230, 5, 219, 206, 255, 209, 154, 144, 12, 213, 164, 169, 82, 177, 230, 98, 209,
            249, 22, 17, 29, 250, 245, 193, 219, 30, 212, 177, 207, 187, 33, 146, 58, 204, 164, 65,
            114, 49, 248, 52, 8, 161, 44, 252, 166, 168, 232, 124, 134, 86, 173, 241, 174, 44, 142,
            155, 129, 143, 184, 161, 211, 15, 36, 189, 208, 194, 221, 152, 16, 203, 87, 34, 188,
            141, 104, 189, 102, 156, 252, 22, 251, 136, 49, 188, 157, 222, 245, 49, 132, 16, 34,
            142, 228, 85, 139, 221, 197, 235, 98, 74, 107, 70, 36, 38, 239, 251, 112, 188, 124,
            246, 141, 164, 150, 104, 7, 213, 44, 21, 244, 192, 4, 143, 24, 42, 21, 84, 136, 7, 42,
            118, 45, 23, 174, 175, 129, 54, 169, 14, 213, 2, 197, 98, 60, 13, 207, 105, 100, 129,
            72, 136, 240, 140, 129, 9, 114, 172, 151, 150, 17, 210, 127, 115, 151, 3, 242, 254,
            215, 14, 5, 34, 126, 2, 215, 65, 38, 176, 23, 210, 201, 97, 36, 207, 92, 224, 26, 116,
            155, 211, 165, 47, 102, 38, 67, 199, 55, 117, 36, 169, 33, 1, 230, 201, 183, 21, 42,
            62, 147, 173, 173, 155, 98, 146, 231, 167, 138, 82, 167, 127, 229, 1, 2, 127, 237, 207,
            116, 90, 115, 159, 3, 42, 66, 145, 250, 201, 7, 251, 2, 75, 230, 26, 213, 181, 56, 64,
            97, 88, 255, 6, 147, 16, 89, 203, 27, 68, 243, 230, 55, 242, 167, 169, 219, 240,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrPhaseBiases(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5e6,
                    "Incorrect message type, expected 0x5e6, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xcedb,
                    "incorrect sender id, expected 0xcedb, is {sender_id}"
                );
                assert_eq!(
                    msg.biases[0].bias, -1311498533,
                    "incorrect value for biases[0].bias, expected -1311498533, is {}",
                    msg.biases[0].bias
                );
                assert_eq!(
                    msg.biases[0].code, 29,
                    "incorrect value for biases[0].code, expected 29, is {}",
                    msg.biases[0].code
                );
                assert_eq!(
                    msg.biases[0].discontinuity_counter, 193,
                    "incorrect value for biases[0].discontinuity_counter, expected 193, is {}",
                    msg.biases[0].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[0].integer_indicator, 250,
                    "incorrect value for biases[0].integer_indicator, expected 250, is {}",
                    msg.biases[0].integer_indicator
                );
                assert_eq!(
                    msg.biases[0].widelane_integer_indicator, 245,
                    "incorrect value for biases[0].widelane_integer_indicator, expected 245, is {}",
                    msg.biases[0].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[1].bias, 1101319226,
                    "incorrect value for biases[1].bias, expected 1101319226, is {}",
                    msg.biases[1].bias
                );
                assert_eq!(
                    msg.biases[1].code, 207,
                    "incorrect value for biases[1].code, expected 207, is {}",
                    msg.biases[1].code
                );
                assert_eq!(
                    msg.biases[1].discontinuity_counter, 146,
                    "incorrect value for biases[1].discontinuity_counter, expected 146, is {}",
                    msg.biases[1].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[1].integer_indicator, 187,
                    "incorrect value for biases[1].integer_indicator, expected 187, is {}",
                    msg.biases[1].integer_indicator
                );
                assert_eq!(
                    msg.biases[1].widelane_integer_indicator, 33,
                    "incorrect value for biases[1].widelane_integer_indicator, expected 33, is {}",
                    msg.biases[1].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[2].bias, -64184056,
                    "incorrect value for biases[2].bias, expected -64184056, is {}",
                    msg.biases[2].bias
                );
                assert_eq!(
                    msg.biases[2].code, 114,
                    "incorrect value for biases[2].code, expected 114, is {}",
                    msg.biases[2].code
                );
                assert_eq!(
                    msg.biases[2].discontinuity_counter, 52,
                    "incorrect value for biases[2].discontinuity_counter, expected 52, is {}",
                    msg.biases[2].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[2].integer_indicator, 49,
                    "incorrect value for biases[2].integer_indicator, expected 49, is {}",
                    msg.biases[2].integer_indicator
                );
                assert_eq!(
                    msg.biases[2].widelane_integer_indicator, 248,
                    "incorrect value for biases[2].widelane_integer_indicator, expected 248, is {}",
                    msg.biases[2].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[3].bias, -240298362,
                    "incorrect value for biases[3].bias, expected -240298362, is {}",
                    msg.biases[3].bias
                );
                assert_eq!(
                    msg.biases[3].code, 166,
                    "incorrect value for biases[3].code, expected 166, is {}",
                    msg.biases[3].code
                );
                assert_eq!(
                    msg.biases[3].discontinuity_counter, 124,
                    "incorrect value for biases[3].discontinuity_counter, expected 124, is {}",
                    msg.biases[3].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[3].integer_indicator, 168,
                    "incorrect value for biases[3].integer_indicator, expected 168, is {}",
                    msg.biases[3].integer_indicator
                );
                assert_eq!(
                    msg.biases[3].widelane_integer_indicator, 232,
                    "incorrect value for biases[3].widelane_integer_indicator, expected 232, is {}",
                    msg.biases[3].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[4].bias, -1581740159,
                    "incorrect value for biases[4].bias, expected -1581740159, is {}",
                    msg.biases[4].bias
                );
                assert_eq!(
                    msg.biases[4].code, 174,
                    "incorrect value for biases[4].code, expected 174, is {}",
                    msg.biases[4].code
                );
                assert_eq!(
                    msg.biases[4].discontinuity_counter, 155,
                    "incorrect value for biases[4].discontinuity_counter, expected 155, is {}",
                    msg.biases[4].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[4].integer_indicator, 44,
                    "incorrect value for biases[4].integer_indicator, expected 44, is {}",
                    msg.biases[4].integer_indicator
                );
                assert_eq!(
                    msg.biases[4].widelane_integer_indicator, 142,
                    "incorrect value for biases[4].widelane_integer_indicator, expected 142, is {}",
                    msg.biases[4].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[5].bias, -1730297136,
                    "incorrect value for biases[5].bias, expected -1730297136, is {}",
                    msg.biases[5].bias
                );
                assert_eq!(
                    msg.biases[5].code, 211,
                    "incorrect value for biases[5].code, expected 211, is {}",
                    msg.biases[5].code
                );
                assert_eq!(
                    msg.biases[5].discontinuity_counter, 189,
                    "incorrect value for biases[5].discontinuity_counter, expected 189, is {}",
                    msg.biases[5].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[5].integer_indicator, 15,
                    "incorrect value for biases[5].integer_indicator, expected 15, is {}",
                    msg.biases[5].integer_indicator
                );
                assert_eq!(
                    msg.biases[5].widelane_integer_indicator, 36,
                    "incorrect value for biases[5].widelane_integer_indicator, expected 36, is {}",
                    msg.biases[5].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[6].bias, -1117221444,
                    "incorrect value for biases[6].bias, expected -1117221444, is {}",
                    msg.biases[6].bias
                );
                assert_eq!(
                    msg.biases[6].code, 16,
                    "incorrect value for biases[6].code, expected 16, is {}",
                    msg.biases[6].code
                );
                assert_eq!(
                    msg.biases[6].discontinuity_counter, 34,
                    "incorrect value for biases[6].discontinuity_counter, expected 34, is {}",
                    msg.biases[6].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[6].integer_indicator, 203,
                    "incorrect value for biases[6].integer_indicator, expected 203, is {}",
                    msg.biases[6].integer_indicator
                );
                assert_eq!(
                    msg.biases[6].widelane_integer_indicator, 87,
                    "incorrect value for biases[6].widelane_integer_indicator, expected 87, is {}",
                    msg.biases[6].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[7].bias, -1137604357,
                    "incorrect value for biases[7].bias, expected -1137604357, is {}",
                    msg.biases[7].bias
                );
                assert_eq!(
                    msg.biases[7].code, 102,
                    "incorrect value for biases[7].code, expected 102, is {}",
                    msg.biases[7].code
                );
                assert_eq!(
                    msg.biases[7].discontinuity_counter, 22,
                    "incorrect value for biases[7].discontinuity_counter, expected 22, is {}",
                    msg.biases[7].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[7].integer_indicator, 156,
                    "incorrect value for biases[7].integer_indicator, expected 156, is {}",
                    msg.biases[7].integer_indicator
                );
                assert_eq!(
                    msg.biases[7].widelane_integer_indicator, 252,
                    "incorrect value for biases[7].widelane_integer_indicator, expected 252, is {}",
                    msg.biases[7].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[8].bias, -1910370172,
                    "incorrect value for biases[8].bias, expected -1910370172, is {}",
                    msg.biases[8].bias
                );
                assert_eq!(
                    msg.biases[8].code, 157,
                    "incorrect value for biases[8].code, expected 157, is {}",
                    msg.biases[8].code
                );
                assert_eq!(
                    msg.biases[8].discontinuity_counter, 49,
                    "incorrect value for biases[8].discontinuity_counter, expected 49, is {}",
                    msg.biases[8].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[8].integer_indicator, 222,
                    "incorrect value for biases[8].integer_indicator, expected 222, is {}",
                    msg.biases[8].integer_indicator
                );
                assert_eq!(
                    msg.biases[8].widelane_integer_indicator, 245,
                    "incorrect value for biases[8].widelane_integer_indicator, expected 245, is {}",
                    msg.biases[8].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[9].bias, 1247996869,
                    "incorrect value for biases[9].bias, expected 1247996869, is {}",
                    msg.biases[9].bias
                );
                assert_eq!(
                    msg.biases[9].code, 228,
                    "incorrect value for biases[9].code, expected 228, is {}",
                    msg.biases[9].code
                );
                assert_eq!(
                    msg.biases[9].discontinuity_counter, 221,
                    "incorrect value for biases[9].discontinuity_counter, expected 221, is {}",
                    msg.biases[9].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[9].integer_indicator, 85,
                    "incorrect value for biases[9].integer_indicator, expected 85, is {}",
                    msg.biases[9].integer_indicator
                );
                assert_eq!(
                    msg.biases[9].widelane_integer_indicator, 139,
                    "incorrect value for biases[9].widelane_integer_indicator, expected 139, is {}",
                    msg.biases[9].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[10].bias, -1133446161,
                    "incorrect value for biases[10].bias, expected -1133446161, is {}",
                    msg.biases[10].bias
                );
                assert_eq!(
                    msg.biases[10].code, 107,
                    "incorrect value for biases[10].code, expected 107, is {}",
                    msg.biases[10].code
                );
                assert_eq!(
                    msg.biases[10].discontinuity_counter, 38,
                    "incorrect value for biases[10].discontinuity_counter, expected 38, is {}",
                    msg.biases[10].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[10].integer_indicator, 70,
                    "incorrect value for biases[10].integer_indicator, expected 70, is {}",
                    msg.biases[10].integer_indicator
                );
                assert_eq!(
                    msg.biases[10].widelane_integer_indicator, 36,
                    "incorrect value for biases[10].widelane_integer_indicator, expected 36, is {}",
                    msg.biases[10].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[11].bias, -720934762,
                    "incorrect value for biases[11].bias, expected -720934762, is {}",
                    msg.biases[11].bias
                );
                assert_eq!(
                    msg.biases[11].code, 124,
                    "incorrect value for biases[11].code, expected 124, is {}",
                    msg.biases[11].code
                );
                assert_eq!(
                    msg.biases[11].discontinuity_counter, 164,
                    "incorrect value for biases[11].discontinuity_counter, expected 164, is {}",
                    msg.biases[11].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[11].integer_indicator, 246,
                    "incorrect value for biases[11].integer_indicator, expected 246, is {}",
                    msg.biases[11].integer_indicator
                );
                assert_eq!(msg.biases[11].widelane_integer_indicator, 141, "incorrect value for biases[11].widelane_integer_indicator, expected 141, is {}", msg.biases[11].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[12].bias, 706252548,
                    "incorrect value for biases[12].bias, expected 706252548, is {}",
                    msg.biases[12].bias
                );
                assert_eq!(
                    msg.biases[12].code, 44,
                    "incorrect value for biases[12].code, expected 44, is {}",
                    msg.biases[12].code
                );
                assert_eq!(
                    msg.biases[12].discontinuity_counter, 192,
                    "incorrect value for biases[12].discontinuity_counter, expected 192, is {}",
                    msg.biases[12].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[12].integer_indicator, 21,
                    "incorrect value for biases[12].integer_indicator, expected 21, is {}",
                    msg.biases[12].integer_indicator
                );
                assert_eq!(msg.biases[12].widelane_integer_indicator, 244, "incorrect value for biases[12].widelane_integer_indicator, expected 244, is {}", msg.biases[12].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[13].bias, 388855338,
                    "incorrect value for biases[13].bias, expected 388855338, is {}",
                    msg.biases[13].bias
                );
                assert_eq!(
                    msg.biases[13].code, 21,
                    "incorrect value for biases[13].code, expected 21, is {}",
                    msg.biases[13].code
                );
                assert_eq!(
                    msg.biases[13].discontinuity_counter, 7,
                    "incorrect value for biases[13].discontinuity_counter, expected 7, is {}",
                    msg.biases[13].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[13].integer_indicator, 84,
                    "incorrect value for biases[13].integer_indicator, expected 84, is {}",
                    msg.biases[13].integer_indicator
                );
                assert_eq!(msg.biases[13].widelane_integer_indicator, 136, "incorrect value for biases[13].widelane_integer_indicator, expected 136, is {}", msg.biases[13].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[14].bias, 47517353,
                    "incorrect value for biases[14].bias, expected 47517353, is {}",
                    msg.biases[14].bias
                );
                assert_eq!(
                    msg.biases[14].code, 174,
                    "incorrect value for biases[14].code, expected 174, is {}",
                    msg.biases[14].code
                );
                assert_eq!(
                    msg.biases[14].discontinuity_counter, 54,
                    "incorrect value for biases[14].discontinuity_counter, expected 54, is {}",
                    msg.biases[14].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[14].integer_indicator, 175,
                    "incorrect value for biases[14].integer_indicator, expected 175, is {}",
                    msg.biases[14].integer_indicator
                );
                assert_eq!(msg.biases[14].widelane_integer_indicator, 129, "incorrect value for biases[14].widelane_integer_indicator, expected 129, is {}", msg.biases[14].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[15].bias, -2124125745,
                    "incorrect value for biases[15].bias, expected -2124125745, is {}",
                    msg.biases[15].bias
                );
                assert_eq!(
                    msg.biases[15].code, 197,
                    "incorrect value for biases[15].code, expected 197, is {}",
                    msg.biases[15].code
                );
                assert_eq!(
                    msg.biases[15].discontinuity_counter, 13,
                    "incorrect value for biases[15].discontinuity_counter, expected 13, is {}",
                    msg.biases[15].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[15].integer_indicator, 98,
                    "incorrect value for biases[15].integer_indicator, expected 98, is {}",
                    msg.biases[15].integer_indicator
                );
                assert_eq!(
                    msg.biases[15].widelane_integer_indicator, 60,
                    "incorrect value for biases[15].widelane_integer_indicator, expected 60, is {}",
                    msg.biases[15].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[16].bias, -1401812607,
                    "incorrect value for biases[16].bias, expected -1401812607, is {}",
                    msg.biases[16].bias
                );
                assert_eq!(
                    msg.biases[16].code, 72,
                    "incorrect value for biases[16].code, expected 72, is {}",
                    msg.biases[16].code
                );
                assert_eq!(
                    msg.biases[16].discontinuity_counter, 140,
                    "incorrect value for biases[16].discontinuity_counter, expected 140, is {}",
                    msg.biases[16].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[16].integer_indicator, 136,
                    "incorrect value for biases[16].integer_indicator, expected 136, is {}",
                    msg.biases[16].integer_indicator
                );
                assert_eq!(msg.biases[16].widelane_integer_indicator, 240, "incorrect value for biases[16].widelane_integer_indicator, expected 240, is {}", msg.biases[16].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[17].bias, 60257151,
                    "incorrect value for biases[17].bias, expected 60257151, is {}",
                    msg.biases[17].bias
                );
                assert_eq!(
                    msg.biases[17].code, 151,
                    "incorrect value for biases[17].code, expected 151, is {}",
                    msg.biases[17].code
                );
                assert_eq!(
                    msg.biases[17].discontinuity_counter, 210,
                    "incorrect value for biases[17].discontinuity_counter, expected 210, is {}",
                    msg.biases[17].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[17].integer_indicator, 150,
                    "incorrect value for biases[17].integer_indicator, expected 150, is {}",
                    msg.biases[17].integer_indicator
                );
                assert_eq!(
                    msg.biases[17].widelane_integer_indicator, 17,
                    "incorrect value for biases[17].widelane_integer_indicator, expected 17, is {}",
                    msg.biases[17].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[18].bias, 41820677,
                    "incorrect value for biases[18].bias, expected 41820677, is {}",
                    msg.biases[18].bias
                );
                assert_eq!(
                    msg.biases[18].code, 242,
                    "incorrect value for biases[18].code, expected 242, is {}",
                    msg.biases[18].code
                );
                assert_eq!(
                    msg.biases[18].discontinuity_counter, 14,
                    "incorrect value for biases[18].discontinuity_counter, expected 14, is {}",
                    msg.biases[18].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[18].integer_indicator, 254,
                    "incorrect value for biases[18].integer_indicator, expected 254, is {}",
                    msg.biases[18].integer_indicator
                );
                assert_eq!(msg.biases[18].widelane_integer_indicator, 215, "incorrect value for biases[18].widelane_integer_indicator, expected 215, is {}", msg.biases[18].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[19].bias, 1640616471,
                    "incorrect value for biases[19].bias, expected 1640616471, is {}",
                    msg.biases[19].bias
                );
                assert_eq!(
                    msg.biases[19].code, 215,
                    "incorrect value for biases[19].code, expected 215, is {}",
                    msg.biases[19].code
                );
                assert_eq!(
                    msg.biases[19].discontinuity_counter, 176,
                    "incorrect value for biases[19].discontinuity_counter, expected 176, is {}",
                    msg.biases[19].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[19].integer_indicator, 65,
                    "incorrect value for biases[19].integer_indicator, expected 65, is {}",
                    msg.biases[19].integer_indicator
                );
                assert_eq!(
                    msg.biases[19].widelane_integer_indicator, 38,
                    "incorrect value for biases[19].widelane_integer_indicator, expected 38, is {}",
                    msg.biases[19].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[20].bias, -744786918,
                    "incorrect value for biases[20].bias, expected -744786918, is {}",
                    msg.biases[20].bias
                );
                assert_eq!(
                    msg.biases[20].code, 36,
                    "incorrect value for biases[20].code, expected 36, is {}",
                    msg.biases[20].code
                );
                assert_eq!(
                    msg.biases[20].discontinuity_counter, 224,
                    "incorrect value for biases[20].discontinuity_counter, expected 224, is {}",
                    msg.biases[20].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[20].integer_indicator, 207,
                    "incorrect value for biases[20].integer_indicator, expected 207, is {}",
                    msg.biases[20].integer_indicator
                );
                assert_eq!(
                    msg.biases[20].widelane_integer_indicator, 92,
                    "incorrect value for biases[20].widelane_integer_indicator, expected 92, is {}",
                    msg.biases[20].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[21].bias, 1966589763,
                    "incorrect value for biases[21].bias, expected 1966589763, is {}",
                    msg.biases[21].bias
                );
                assert_eq!(
                    msg.biases[21].code, 165,
                    "incorrect value for biases[21].code, expected 165, is {}",
                    msg.biases[21].code
                );
                assert_eq!(
                    msg.biases[21].discontinuity_counter, 38,
                    "incorrect value for biases[21].discontinuity_counter, expected 38, is {}",
                    msg.biases[21].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[21].integer_indicator, 47,
                    "incorrect value for biases[21].integer_indicator, expected 47, is {}",
                    msg.biases[21].integer_indicator
                );
                assert_eq!(msg.biases[21].widelane_integer_indicator, 102, "incorrect value for biases[21].widelane_integer_indicator, expected 102, is {}", msg.biases[21].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[22].bias, 364366310,
                    "incorrect value for biases[22].bias, expected 364366310, is {}",
                    msg.biases[22].bias
                );
                assert_eq!(
                    msg.biases[22].code, 36,
                    "incorrect value for biases[22].code, expected 36, is {}",
                    msg.biases[22].code
                );
                assert_eq!(
                    msg.biases[22].discontinuity_counter, 1,
                    "incorrect value for biases[22].discontinuity_counter, expected 1, is {}",
                    msg.biases[22].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[22].integer_indicator, 169,
                    "incorrect value for biases[22].integer_indicator, expected 169, is {}",
                    msg.biases[22].integer_indicator
                );
                assert_eq!(
                    msg.biases[22].widelane_integer_indicator, 33,
                    "incorrect value for biases[22].widelane_integer_indicator, expected 33, is {}",
                    msg.biases[22].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[23].bias, -1839031379,
                    "incorrect value for biases[23].bias, expected -1839031379, is {}",
                    msg.biases[23].bias
                );
                assert_eq!(
                    msg.biases[23].code, 42,
                    "incorrect value for biases[23].code, expected 42, is {}",
                    msg.biases[23].code
                );
                assert_eq!(
                    msg.biases[23].discontinuity_counter, 173,
                    "incorrect value for biases[23].discontinuity_counter, expected 173, is {}",
                    msg.biases[23].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[23].integer_indicator, 62,
                    "incorrect value for biases[23].integer_indicator, expected 62, is {}",
                    msg.biases[23].integer_indicator
                );
                assert_eq!(msg.biases[23].widelane_integer_indicator, 147, "incorrect value for biases[23].widelane_integer_indicator, expected 147, is {}", msg.biases[23].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[24].bias, 31817639,
                    "incorrect value for biases[24].bias, expected 31817639, is {}",
                    msg.biases[24].bias
                );
                assert_eq!(
                    msg.biases[24].code, 231,
                    "incorrect value for biases[24].code, expected 231, is {}",
                    msg.biases[24].code
                );
                assert_eq!(
                    msg.biases[24].discontinuity_counter, 82,
                    "incorrect value for biases[24].discontinuity_counter, expected 82, is {}",
                    msg.biases[24].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[24].integer_indicator, 167,
                    "incorrect value for biases[24].integer_indicator, expected 167, is {}",
                    msg.biases[24].integer_indicator
                );
                assert_eq!(msg.biases[24].widelane_integer_indicator, 138, "incorrect value for biases[24].widelane_integer_indicator, expected 138, is {}", msg.biases[24].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[25].bias, -1619830156,
                    "incorrect value for biases[25].bias, expected -1619830156, is {}",
                    msg.biases[25].bias
                );
                assert_eq!(
                    msg.biases[25].code, 2,
                    "incorrect value for biases[25].code, expected 2, is {}",
                    msg.biases[25].code
                );
                assert_eq!(
                    msg.biases[25].discontinuity_counter, 207,
                    "incorrect value for biases[25].discontinuity_counter, expected 207, is {}",
                    msg.biases[25].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[25].integer_indicator, 127,
                    "incorrect value for biases[25].integer_indicator, expected 127, is {}",
                    msg.biases[25].integer_indicator
                );
                assert_eq!(msg.biases[25].widelane_integer_indicator, 237, "incorrect value for biases[25].widelane_integer_indicator, expected 237, is {}", msg.biases[25].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[26].bias, -83375622,
                    "incorrect value for biases[26].bias, expected -83375622, is {}",
                    msg.biases[26].bias
                );
                assert_eq!(
                    msg.biases[26].code, 3,
                    "incorrect value for biases[26].code, expected 3, is {}",
                    msg.biases[26].code
                );
                assert_eq!(
                    msg.biases[26].discontinuity_counter, 145,
                    "incorrect value for biases[26].discontinuity_counter, expected 145, is {}",
                    msg.biases[26].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[26].integer_indicator, 42,
                    "incorrect value for biases[26].integer_indicator, expected 42, is {}",
                    msg.biases[26].integer_indicator
                );
                assert_eq!(
                    msg.biases[26].widelane_integer_indicator, 66,
                    "incorrect value for biases[26].widelane_integer_indicator, expected 66, is {}",
                    msg.biases[26].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[27].bias, 1077458389,
                    "incorrect value for biases[27].bias, expected 1077458389, is {}",
                    msg.biases[27].bias
                );
                assert_eq!(
                    msg.biases[27].code, 2,
                    "incorrect value for biases[27].code, expected 2, is {}",
                    msg.biases[27].code
                );
                assert_eq!(
                    msg.biases[27].discontinuity_counter, 26,
                    "incorrect value for biases[27].discontinuity_counter, expected 26, is {}",
                    msg.biases[27].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[27].integer_indicator, 75,
                    "incorrect value for biases[27].integer_indicator, expected 75, is {}",
                    msg.biases[27].integer_indicator
                );
                assert_eq!(msg.biases[27].widelane_integer_indicator, 230, "incorrect value for biases[27].widelane_integer_indicator, expected 230, is {}", msg.biases[27].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[28].bias, -883355501,
                    "incorrect value for biases[28].bias, expected -883355501, is {}",
                    msg.biases[28].bias
                );
                assert_eq!(
                    msg.biases[28].code, 97,
                    "incorrect value for biases[28].code, expected 97, is {}",
                    msg.biases[28].code
                );
                assert_eq!(
                    msg.biases[28].discontinuity_counter, 6,
                    "incorrect value for biases[28].discontinuity_counter, expected 6, is {}",
                    msg.biases[28].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[28].integer_indicator, 88,
                    "incorrect value for biases[28].integer_indicator, expected 88, is {}",
                    msg.biases[28].integer_indicator
                );
                assert_eq!(msg.biases[28].widelane_integer_indicator, 255, "incorrect value for biases[28].widelane_integer_indicator, expected 255, is {}", msg.biases[28].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[29].bias, -1448611273,
                    "incorrect value for biases[29].bias, expected -1448611273, is {}",
                    msg.biases[29].bias
                );
                assert_eq!(
                    msg.biases[29].code, 27,
                    "incorrect value for biases[29].code, expected 27, is {}",
                    msg.biases[29].code
                );
                assert_eq!(
                    msg.biases[29].discontinuity_counter, 230,
                    "incorrect value for biases[29].discontinuity_counter, expected 230, is {}",
                    msg.biases[29].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[29].integer_indicator, 68,
                    "incorrect value for biases[29].integer_indicator, expected 68, is {}",
                    msg.biases[29].integer_indicator
                );
                assert_eq!(msg.biases[29].widelane_integer_indicator, 243, "incorrect value for biases[29].widelane_integer_indicator, expected 243, is {}", msg.biases[29].widelane_integer_indicator);
                assert_eq!(
                    msg.dispersive_bias, 98,
                    "incorrect value for dispersive_bias, expected 98, is {}",
                    msg.dispersive_bias
                );
                assert_eq!(
                    msg.iod_ssr, 230,
                    "incorrect value for iod_ssr, expected 230, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.mw_consistency, 209,
                    "incorrect value for mw_consistency, expected 209, is {}",
                    msg.mw_consistency
                );
                assert_eq!(
                    msg.sid.code, 82,
                    "incorrect value for sid.code, expected 82, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 169,
                    "incorrect value for sid.sat, expected 169, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.time.tow, 210803409,
                    "incorrect value for time.tow, expected 210803409, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 42197,
                    "incorrect value for time.wn, expected 42197, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 177,
                    "incorrect value for update_interval, expected 177, is {}",
                    msg.update_interval
                );
                assert_eq!(
                    msg.yaw, 5881,
                    "incorrect value for yaw, expected 5881, is {}",
                    msg.yaw
                );
                assert_eq!(
                    msg.yaw_rate, 17,
                    "incorrect value for yaw_rate, expected 17, is {}",
                    msg.yaw_rate
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrPhaseBiases"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_phase_biases() {
    {
        let json_input = r#"{"crc":61659,"length":255,"msg_type":1510,"payload":"0ZqQDNWkqVKx5mLR+RYRHfr1wdse1LHPuyGSOsykQXIx+DQIoSz8pqjofIZWrfGuLI6bgY+4odMPJL3Qwt2YEMtXIryNaL1mnPwW+4gxvJ3e9TGEECKO5FWL3cXrYkprRiQm7/twvHz2jaSWaAfVLBX0wASPGCoVVIgHKnYtF66vgTapDtUCxWI8Dc9pZIFIiPCMgQlyrJeWEdJ/c5cD8v7XDgUifgLXQSawF9LJYSTPXOAadJvTpS9mJkPHN3UkqSEB5sm3FSo+k62tm2KS56eKUqd/5QECf+3PdFpznwMqQpH6yQf7AkvmGtW1OEBhWP8GkxBZyxtE8+Y38qep","preamble":85,"sender":52955,"time":{"tow":210803409,"wn":42197},"sid":{"sat":169,"code":82},"update_interval":177,"iod_ssr":230,"dispersive_bias":98,"mw_consistency":209,"yaw":5881,"yaw_rate":17,"biases":[{"code":29,"integer_indicator":250,"widelane_integer_indicator":245,"discontinuity_counter":193,"bias":-1311498533},{"code":207,"integer_indicator":187,"widelane_integer_indicator":33,"discontinuity_counter":146,"bias":1101319226},{"code":114,"integer_indicator":49,"widelane_integer_indicator":248,"discontinuity_counter":52,"bias":-64184056},{"code":166,"integer_indicator":168,"widelane_integer_indicator":232,"discontinuity_counter":124,"bias":-240298362},{"code":174,"integer_indicator":44,"widelane_integer_indicator":142,"discontinuity_counter":155,"bias":-1581740159},{"code":211,"integer_indicator":15,"widelane_integer_indicator":36,"discontinuity_counter":189,"bias":-1730297136},{"code":16,"integer_indicator":203,"widelane_integer_indicator":87,"discontinuity_counter":34,"bias":-1117221444},{"code":102,"integer_indicator":156,"widelane_integer_indicator":252,"discontinuity_counter":22,"bias":-1137604357},{"code":157,"integer_indicator":222,"widelane_integer_indicator":245,"discontinuity_counter":49,"bias":-1910370172},{"code":228,"integer_indicator":85,"widelane_integer_indicator":139,"discontinuity_counter":221,"bias":1247996869},{"code":107,"integer_indicator":70,"widelane_integer_indicator":36,"discontinuity_counter":38,"bias":-1133446161},{"code":124,"integer_indicator":246,"widelane_integer_indicator":141,"discontinuity_counter":164,"bias":-720934762},{"code":44,"integer_indicator":21,"widelane_integer_indicator":244,"discontinuity_counter":192,"bias":706252548},{"code":21,"integer_indicator":84,"widelane_integer_indicator":136,"discontinuity_counter":7,"bias":388855338},{"code":174,"integer_indicator":175,"widelane_integer_indicator":129,"discontinuity_counter":54,"bias":47517353},{"code":197,"integer_indicator":98,"widelane_integer_indicator":60,"discontinuity_counter":13,"bias":-2124125745},{"code":72,"integer_indicator":136,"widelane_integer_indicator":240,"discontinuity_counter":140,"bias":-1401812607},{"code":151,"integer_indicator":150,"widelane_integer_indicator":17,"discontinuity_counter":210,"bias":60257151},{"code":242,"integer_indicator":254,"widelane_integer_indicator":215,"discontinuity_counter":14,"bias":41820677},{"code":215,"integer_indicator":65,"widelane_integer_indicator":38,"discontinuity_counter":176,"bias":1640616471},{"code":36,"integer_indicator":207,"widelane_integer_indicator":92,"discontinuity_counter":224,"bias":-744786918},{"code":165,"integer_indicator":47,"widelane_integer_indicator":102,"discontinuity_counter":38,"bias":1966589763},{"code":36,"integer_indicator":169,"widelane_integer_indicator":33,"discontinuity_counter":1,"bias":364366310},{"code":42,"integer_indicator":62,"widelane_integer_indicator":147,"discontinuity_counter":173,"bias":-1839031379},{"code":231,"integer_indicator":167,"widelane_integer_indicator":138,"discontinuity_counter":82,"bias":31817639},{"code":2,"integer_indicator":127,"widelane_integer_indicator":237,"discontinuity_counter":207,"bias":-1619830156},{"code":3,"integer_indicator":42,"widelane_integer_indicator":66,"discontinuity_counter":145,"bias":-83375622},{"code":2,"integer_indicator":75,"widelane_integer_indicator":230,"discontinuity_counter":26,"bias":1077458389},{"code":97,"integer_indicator":88,"widelane_integer_indicator":255,"discontinuity_counter":6,"bias":-883355501},{"code":27,"integer_indicator":68,"widelane_integer_indicator":243,"discontinuity_counter":230,"bias":-1448611273}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrPhaseBiases(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5e6,
                    "Incorrect message type, expected 0x5e6, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xcedb,
                    "incorrect sender id, expected 0xcedb, is {sender_id}"
                );
                assert_eq!(
                    msg.biases[0].bias, -1311498533,
                    "incorrect value for biases[0].bias, expected -1311498533, is {}",
                    msg.biases[0].bias
                );
                assert_eq!(
                    msg.biases[0].code, 29,
                    "incorrect value for biases[0].code, expected 29, is {}",
                    msg.biases[0].code
                );
                assert_eq!(
                    msg.biases[0].discontinuity_counter, 193,
                    "incorrect value for biases[0].discontinuity_counter, expected 193, is {}",
                    msg.biases[0].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[0].integer_indicator, 250,
                    "incorrect value for biases[0].integer_indicator, expected 250, is {}",
                    msg.biases[0].integer_indicator
                );
                assert_eq!(
                    msg.biases[0].widelane_integer_indicator, 245,
                    "incorrect value for biases[0].widelane_integer_indicator, expected 245, is {}",
                    msg.biases[0].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[1].bias, 1101319226,
                    "incorrect value for biases[1].bias, expected 1101319226, is {}",
                    msg.biases[1].bias
                );
                assert_eq!(
                    msg.biases[1].code, 207,
                    "incorrect value for biases[1].code, expected 207, is {}",
                    msg.biases[1].code
                );
                assert_eq!(
                    msg.biases[1].discontinuity_counter, 146,
                    "incorrect value for biases[1].discontinuity_counter, expected 146, is {}",
                    msg.biases[1].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[1].integer_indicator, 187,
                    "incorrect value for biases[1].integer_indicator, expected 187, is {}",
                    msg.biases[1].integer_indicator
                );
                assert_eq!(
                    msg.biases[1].widelane_integer_indicator, 33,
                    "incorrect value for biases[1].widelane_integer_indicator, expected 33, is {}",
                    msg.biases[1].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[2].bias, -64184056,
                    "incorrect value for biases[2].bias, expected -64184056, is {}",
                    msg.biases[2].bias
                );
                assert_eq!(
                    msg.biases[2].code, 114,
                    "incorrect value for biases[2].code, expected 114, is {}",
                    msg.biases[2].code
                );
                assert_eq!(
                    msg.biases[2].discontinuity_counter, 52,
                    "incorrect value for biases[2].discontinuity_counter, expected 52, is {}",
                    msg.biases[2].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[2].integer_indicator, 49,
                    "incorrect value for biases[2].integer_indicator, expected 49, is {}",
                    msg.biases[2].integer_indicator
                );
                assert_eq!(
                    msg.biases[2].widelane_integer_indicator, 248,
                    "incorrect value for biases[2].widelane_integer_indicator, expected 248, is {}",
                    msg.biases[2].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[3].bias, -240298362,
                    "incorrect value for biases[3].bias, expected -240298362, is {}",
                    msg.biases[3].bias
                );
                assert_eq!(
                    msg.biases[3].code, 166,
                    "incorrect value for biases[3].code, expected 166, is {}",
                    msg.biases[3].code
                );
                assert_eq!(
                    msg.biases[3].discontinuity_counter, 124,
                    "incorrect value for biases[3].discontinuity_counter, expected 124, is {}",
                    msg.biases[3].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[3].integer_indicator, 168,
                    "incorrect value for biases[3].integer_indicator, expected 168, is {}",
                    msg.biases[3].integer_indicator
                );
                assert_eq!(
                    msg.biases[3].widelane_integer_indicator, 232,
                    "incorrect value for biases[3].widelane_integer_indicator, expected 232, is {}",
                    msg.biases[3].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[4].bias, -1581740159,
                    "incorrect value for biases[4].bias, expected -1581740159, is {}",
                    msg.biases[4].bias
                );
                assert_eq!(
                    msg.biases[4].code, 174,
                    "incorrect value for biases[4].code, expected 174, is {}",
                    msg.biases[4].code
                );
                assert_eq!(
                    msg.biases[4].discontinuity_counter, 155,
                    "incorrect value for biases[4].discontinuity_counter, expected 155, is {}",
                    msg.biases[4].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[4].integer_indicator, 44,
                    "incorrect value for biases[4].integer_indicator, expected 44, is {}",
                    msg.biases[4].integer_indicator
                );
                assert_eq!(
                    msg.biases[4].widelane_integer_indicator, 142,
                    "incorrect value for biases[4].widelane_integer_indicator, expected 142, is {}",
                    msg.biases[4].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[5].bias, -1730297136,
                    "incorrect value for biases[5].bias, expected -1730297136, is {}",
                    msg.biases[5].bias
                );
                assert_eq!(
                    msg.biases[5].code, 211,
                    "incorrect value for biases[5].code, expected 211, is {}",
                    msg.biases[5].code
                );
                assert_eq!(
                    msg.biases[5].discontinuity_counter, 189,
                    "incorrect value for biases[5].discontinuity_counter, expected 189, is {}",
                    msg.biases[5].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[5].integer_indicator, 15,
                    "incorrect value for biases[5].integer_indicator, expected 15, is {}",
                    msg.biases[5].integer_indicator
                );
                assert_eq!(
                    msg.biases[5].widelane_integer_indicator, 36,
                    "incorrect value for biases[5].widelane_integer_indicator, expected 36, is {}",
                    msg.biases[5].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[6].bias, -1117221444,
                    "incorrect value for biases[6].bias, expected -1117221444, is {}",
                    msg.biases[6].bias
                );
                assert_eq!(
                    msg.biases[6].code, 16,
                    "incorrect value for biases[6].code, expected 16, is {}",
                    msg.biases[6].code
                );
                assert_eq!(
                    msg.biases[6].discontinuity_counter, 34,
                    "incorrect value for biases[6].discontinuity_counter, expected 34, is {}",
                    msg.biases[6].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[6].integer_indicator, 203,
                    "incorrect value for biases[6].integer_indicator, expected 203, is {}",
                    msg.biases[6].integer_indicator
                );
                assert_eq!(
                    msg.biases[6].widelane_integer_indicator, 87,
                    "incorrect value for biases[6].widelane_integer_indicator, expected 87, is {}",
                    msg.biases[6].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[7].bias, -1137604357,
                    "incorrect value for biases[7].bias, expected -1137604357, is {}",
                    msg.biases[7].bias
                );
                assert_eq!(
                    msg.biases[7].code, 102,
                    "incorrect value for biases[7].code, expected 102, is {}",
                    msg.biases[7].code
                );
                assert_eq!(
                    msg.biases[7].discontinuity_counter, 22,
                    "incorrect value for biases[7].discontinuity_counter, expected 22, is {}",
                    msg.biases[7].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[7].integer_indicator, 156,
                    "incorrect value for biases[7].integer_indicator, expected 156, is {}",
                    msg.biases[7].integer_indicator
                );
                assert_eq!(
                    msg.biases[7].widelane_integer_indicator, 252,
                    "incorrect value for biases[7].widelane_integer_indicator, expected 252, is {}",
                    msg.biases[7].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[8].bias, -1910370172,
                    "incorrect value for biases[8].bias, expected -1910370172, is {}",
                    msg.biases[8].bias
                );
                assert_eq!(
                    msg.biases[8].code, 157,
                    "incorrect value for biases[8].code, expected 157, is {}",
                    msg.biases[8].code
                );
                assert_eq!(
                    msg.biases[8].discontinuity_counter, 49,
                    "incorrect value for biases[8].discontinuity_counter, expected 49, is {}",
                    msg.biases[8].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[8].integer_indicator, 222,
                    "incorrect value for biases[8].integer_indicator, expected 222, is {}",
                    msg.biases[8].integer_indicator
                );
                assert_eq!(
                    msg.biases[8].widelane_integer_indicator, 245,
                    "incorrect value for biases[8].widelane_integer_indicator, expected 245, is {}",
                    msg.biases[8].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[9].bias, 1247996869,
                    "incorrect value for biases[9].bias, expected 1247996869, is {}",
                    msg.biases[9].bias
                );
                assert_eq!(
                    msg.biases[9].code, 228,
                    "incorrect value for biases[9].code, expected 228, is {}",
                    msg.biases[9].code
                );
                assert_eq!(
                    msg.biases[9].discontinuity_counter, 221,
                    "incorrect value for biases[9].discontinuity_counter, expected 221, is {}",
                    msg.biases[9].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[9].integer_indicator, 85,
                    "incorrect value for biases[9].integer_indicator, expected 85, is {}",
                    msg.biases[9].integer_indicator
                );
                assert_eq!(
                    msg.biases[9].widelane_integer_indicator, 139,
                    "incorrect value for biases[9].widelane_integer_indicator, expected 139, is {}",
                    msg.biases[9].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[10].bias, -1133446161,
                    "incorrect value for biases[10].bias, expected -1133446161, is {}",
                    msg.biases[10].bias
                );
                assert_eq!(
                    msg.biases[10].code, 107,
                    "incorrect value for biases[10].code, expected 107, is {}",
                    msg.biases[10].code
                );
                assert_eq!(
                    msg.biases[10].discontinuity_counter, 38,
                    "incorrect value for biases[10].discontinuity_counter, expected 38, is {}",
                    msg.biases[10].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[10].integer_indicator, 70,
                    "incorrect value for biases[10].integer_indicator, expected 70, is {}",
                    msg.biases[10].integer_indicator
                );
                assert_eq!(
                    msg.biases[10].widelane_integer_indicator, 36,
                    "incorrect value for biases[10].widelane_integer_indicator, expected 36, is {}",
                    msg.biases[10].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[11].bias, -720934762,
                    "incorrect value for biases[11].bias, expected -720934762, is {}",
                    msg.biases[11].bias
                );
                assert_eq!(
                    msg.biases[11].code, 124,
                    "incorrect value for biases[11].code, expected 124, is {}",
                    msg.biases[11].code
                );
                assert_eq!(
                    msg.biases[11].discontinuity_counter, 164,
                    "incorrect value for biases[11].discontinuity_counter, expected 164, is {}",
                    msg.biases[11].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[11].integer_indicator, 246,
                    "incorrect value for biases[11].integer_indicator, expected 246, is {}",
                    msg.biases[11].integer_indicator
                );
                assert_eq!(msg.biases[11].widelane_integer_indicator, 141, "incorrect value for biases[11].widelane_integer_indicator, expected 141, is {}", msg.biases[11].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[12].bias, 706252548,
                    "incorrect value for biases[12].bias, expected 706252548, is {}",
                    msg.biases[12].bias
                );
                assert_eq!(
                    msg.biases[12].code, 44,
                    "incorrect value for biases[12].code, expected 44, is {}",
                    msg.biases[12].code
                );
                assert_eq!(
                    msg.biases[12].discontinuity_counter, 192,
                    "incorrect value for biases[12].discontinuity_counter, expected 192, is {}",
                    msg.biases[12].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[12].integer_indicator, 21,
                    "incorrect value for biases[12].integer_indicator, expected 21, is {}",
                    msg.biases[12].integer_indicator
                );
                assert_eq!(msg.biases[12].widelane_integer_indicator, 244, "incorrect value for biases[12].widelane_integer_indicator, expected 244, is {}", msg.biases[12].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[13].bias, 388855338,
                    "incorrect value for biases[13].bias, expected 388855338, is {}",
                    msg.biases[13].bias
                );
                assert_eq!(
                    msg.biases[13].code, 21,
                    "incorrect value for biases[13].code, expected 21, is {}",
                    msg.biases[13].code
                );
                assert_eq!(
                    msg.biases[13].discontinuity_counter, 7,
                    "incorrect value for biases[13].discontinuity_counter, expected 7, is {}",
                    msg.biases[13].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[13].integer_indicator, 84,
                    "incorrect value for biases[13].integer_indicator, expected 84, is {}",
                    msg.biases[13].integer_indicator
                );
                assert_eq!(msg.biases[13].widelane_integer_indicator, 136, "incorrect value for biases[13].widelane_integer_indicator, expected 136, is {}", msg.biases[13].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[14].bias, 47517353,
                    "incorrect value for biases[14].bias, expected 47517353, is {}",
                    msg.biases[14].bias
                );
                assert_eq!(
                    msg.biases[14].code, 174,
                    "incorrect value for biases[14].code, expected 174, is {}",
                    msg.biases[14].code
                );
                assert_eq!(
                    msg.biases[14].discontinuity_counter, 54,
                    "incorrect value for biases[14].discontinuity_counter, expected 54, is {}",
                    msg.biases[14].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[14].integer_indicator, 175,
                    "incorrect value for biases[14].integer_indicator, expected 175, is {}",
                    msg.biases[14].integer_indicator
                );
                assert_eq!(msg.biases[14].widelane_integer_indicator, 129, "incorrect value for biases[14].widelane_integer_indicator, expected 129, is {}", msg.biases[14].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[15].bias, -2124125745,
                    "incorrect value for biases[15].bias, expected -2124125745, is {}",
                    msg.biases[15].bias
                );
                assert_eq!(
                    msg.biases[15].code, 197,
                    "incorrect value for biases[15].code, expected 197, is {}",
                    msg.biases[15].code
                );
                assert_eq!(
                    msg.biases[15].discontinuity_counter, 13,
                    "incorrect value for biases[15].discontinuity_counter, expected 13, is {}",
                    msg.biases[15].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[15].integer_indicator, 98,
                    "incorrect value for biases[15].integer_indicator, expected 98, is {}",
                    msg.biases[15].integer_indicator
                );
                assert_eq!(
                    msg.biases[15].widelane_integer_indicator, 60,
                    "incorrect value for biases[15].widelane_integer_indicator, expected 60, is {}",
                    msg.biases[15].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[16].bias, -1401812607,
                    "incorrect value for biases[16].bias, expected -1401812607, is {}",
                    msg.biases[16].bias
                );
                assert_eq!(
                    msg.biases[16].code, 72,
                    "incorrect value for biases[16].code, expected 72, is {}",
                    msg.biases[16].code
                );
                assert_eq!(
                    msg.biases[16].discontinuity_counter, 140,
                    "incorrect value for biases[16].discontinuity_counter, expected 140, is {}",
                    msg.biases[16].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[16].integer_indicator, 136,
                    "incorrect value for biases[16].integer_indicator, expected 136, is {}",
                    msg.biases[16].integer_indicator
                );
                assert_eq!(msg.biases[16].widelane_integer_indicator, 240, "incorrect value for biases[16].widelane_integer_indicator, expected 240, is {}", msg.biases[16].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[17].bias, 60257151,
                    "incorrect value for biases[17].bias, expected 60257151, is {}",
                    msg.biases[17].bias
                );
                assert_eq!(
                    msg.biases[17].code, 151,
                    "incorrect value for biases[17].code, expected 151, is {}",
                    msg.biases[17].code
                );
                assert_eq!(
                    msg.biases[17].discontinuity_counter, 210,
                    "incorrect value for biases[17].discontinuity_counter, expected 210, is {}",
                    msg.biases[17].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[17].integer_indicator, 150,
                    "incorrect value for biases[17].integer_indicator, expected 150, is {}",
                    msg.biases[17].integer_indicator
                );
                assert_eq!(
                    msg.biases[17].widelane_integer_indicator, 17,
                    "incorrect value for biases[17].widelane_integer_indicator, expected 17, is {}",
                    msg.biases[17].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[18].bias, 41820677,
                    "incorrect value for biases[18].bias, expected 41820677, is {}",
                    msg.biases[18].bias
                );
                assert_eq!(
                    msg.biases[18].code, 242,
                    "incorrect value for biases[18].code, expected 242, is {}",
                    msg.biases[18].code
                );
                assert_eq!(
                    msg.biases[18].discontinuity_counter, 14,
                    "incorrect value for biases[18].discontinuity_counter, expected 14, is {}",
                    msg.biases[18].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[18].integer_indicator, 254,
                    "incorrect value for biases[18].integer_indicator, expected 254, is {}",
                    msg.biases[18].integer_indicator
                );
                assert_eq!(msg.biases[18].widelane_integer_indicator, 215, "incorrect value for biases[18].widelane_integer_indicator, expected 215, is {}", msg.biases[18].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[19].bias, 1640616471,
                    "incorrect value for biases[19].bias, expected 1640616471, is {}",
                    msg.biases[19].bias
                );
                assert_eq!(
                    msg.biases[19].code, 215,
                    "incorrect value for biases[19].code, expected 215, is {}",
                    msg.biases[19].code
                );
                assert_eq!(
                    msg.biases[19].discontinuity_counter, 176,
                    "incorrect value for biases[19].discontinuity_counter, expected 176, is {}",
                    msg.biases[19].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[19].integer_indicator, 65,
                    "incorrect value for biases[19].integer_indicator, expected 65, is {}",
                    msg.biases[19].integer_indicator
                );
                assert_eq!(
                    msg.biases[19].widelane_integer_indicator, 38,
                    "incorrect value for biases[19].widelane_integer_indicator, expected 38, is {}",
                    msg.biases[19].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[20].bias, -744786918,
                    "incorrect value for biases[20].bias, expected -744786918, is {}",
                    msg.biases[20].bias
                );
                assert_eq!(
                    msg.biases[20].code, 36,
                    "incorrect value for biases[20].code, expected 36, is {}",
                    msg.biases[20].code
                );
                assert_eq!(
                    msg.biases[20].discontinuity_counter, 224,
                    "incorrect value for biases[20].discontinuity_counter, expected 224, is {}",
                    msg.biases[20].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[20].integer_indicator, 207,
                    "incorrect value for biases[20].integer_indicator, expected 207, is {}",
                    msg.biases[20].integer_indicator
                );
                assert_eq!(
                    msg.biases[20].widelane_integer_indicator, 92,
                    "incorrect value for biases[20].widelane_integer_indicator, expected 92, is {}",
                    msg.biases[20].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[21].bias, 1966589763,
                    "incorrect value for biases[21].bias, expected 1966589763, is {}",
                    msg.biases[21].bias
                );
                assert_eq!(
                    msg.biases[21].code, 165,
                    "incorrect value for biases[21].code, expected 165, is {}",
                    msg.biases[21].code
                );
                assert_eq!(
                    msg.biases[21].discontinuity_counter, 38,
                    "incorrect value for biases[21].discontinuity_counter, expected 38, is {}",
                    msg.biases[21].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[21].integer_indicator, 47,
                    "incorrect value for biases[21].integer_indicator, expected 47, is {}",
                    msg.biases[21].integer_indicator
                );
                assert_eq!(msg.biases[21].widelane_integer_indicator, 102, "incorrect value for biases[21].widelane_integer_indicator, expected 102, is {}", msg.biases[21].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[22].bias, 364366310,
                    "incorrect value for biases[22].bias, expected 364366310, is {}",
                    msg.biases[22].bias
                );
                assert_eq!(
                    msg.biases[22].code, 36,
                    "incorrect value for biases[22].code, expected 36, is {}",
                    msg.biases[22].code
                );
                assert_eq!(
                    msg.biases[22].discontinuity_counter, 1,
                    "incorrect value for biases[22].discontinuity_counter, expected 1, is {}",
                    msg.biases[22].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[22].integer_indicator, 169,
                    "incorrect value for biases[22].integer_indicator, expected 169, is {}",
                    msg.biases[22].integer_indicator
                );
                assert_eq!(
                    msg.biases[22].widelane_integer_indicator, 33,
                    "incorrect value for biases[22].widelane_integer_indicator, expected 33, is {}",
                    msg.biases[22].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[23].bias, -1839031379,
                    "incorrect value for biases[23].bias, expected -1839031379, is {}",
                    msg.biases[23].bias
                );
                assert_eq!(
                    msg.biases[23].code, 42,
                    "incorrect value for biases[23].code, expected 42, is {}",
                    msg.biases[23].code
                );
                assert_eq!(
                    msg.biases[23].discontinuity_counter, 173,
                    "incorrect value for biases[23].discontinuity_counter, expected 173, is {}",
                    msg.biases[23].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[23].integer_indicator, 62,
                    "incorrect value for biases[23].integer_indicator, expected 62, is {}",
                    msg.biases[23].integer_indicator
                );
                assert_eq!(msg.biases[23].widelane_integer_indicator, 147, "incorrect value for biases[23].widelane_integer_indicator, expected 147, is {}", msg.biases[23].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[24].bias, 31817639,
                    "incorrect value for biases[24].bias, expected 31817639, is {}",
                    msg.biases[24].bias
                );
                assert_eq!(
                    msg.biases[24].code, 231,
                    "incorrect value for biases[24].code, expected 231, is {}",
                    msg.biases[24].code
                );
                assert_eq!(
                    msg.biases[24].discontinuity_counter, 82,
                    "incorrect value for biases[24].discontinuity_counter, expected 82, is {}",
                    msg.biases[24].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[24].integer_indicator, 167,
                    "incorrect value for biases[24].integer_indicator, expected 167, is {}",
                    msg.biases[24].integer_indicator
                );
                assert_eq!(msg.biases[24].widelane_integer_indicator, 138, "incorrect value for biases[24].widelane_integer_indicator, expected 138, is {}", msg.biases[24].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[25].bias, -1619830156,
                    "incorrect value for biases[25].bias, expected -1619830156, is {}",
                    msg.biases[25].bias
                );
                assert_eq!(
                    msg.biases[25].code, 2,
                    "incorrect value for biases[25].code, expected 2, is {}",
                    msg.biases[25].code
                );
                assert_eq!(
                    msg.biases[25].discontinuity_counter, 207,
                    "incorrect value for biases[25].discontinuity_counter, expected 207, is {}",
                    msg.biases[25].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[25].integer_indicator, 127,
                    "incorrect value for biases[25].integer_indicator, expected 127, is {}",
                    msg.biases[25].integer_indicator
                );
                assert_eq!(msg.biases[25].widelane_integer_indicator, 237, "incorrect value for biases[25].widelane_integer_indicator, expected 237, is {}", msg.biases[25].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[26].bias, -83375622,
                    "incorrect value for biases[26].bias, expected -83375622, is {}",
                    msg.biases[26].bias
                );
                assert_eq!(
                    msg.biases[26].code, 3,
                    "incorrect value for biases[26].code, expected 3, is {}",
                    msg.biases[26].code
                );
                assert_eq!(
                    msg.biases[26].discontinuity_counter, 145,
                    "incorrect value for biases[26].discontinuity_counter, expected 145, is {}",
                    msg.biases[26].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[26].integer_indicator, 42,
                    "incorrect value for biases[26].integer_indicator, expected 42, is {}",
                    msg.biases[26].integer_indicator
                );
                assert_eq!(
                    msg.biases[26].widelane_integer_indicator, 66,
                    "incorrect value for biases[26].widelane_integer_indicator, expected 66, is {}",
                    msg.biases[26].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[27].bias, 1077458389,
                    "incorrect value for biases[27].bias, expected 1077458389, is {}",
                    msg.biases[27].bias
                );
                assert_eq!(
                    msg.biases[27].code, 2,
                    "incorrect value for biases[27].code, expected 2, is {}",
                    msg.biases[27].code
                );
                assert_eq!(
                    msg.biases[27].discontinuity_counter, 26,
                    "incorrect value for biases[27].discontinuity_counter, expected 26, is {}",
                    msg.biases[27].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[27].integer_indicator, 75,
                    "incorrect value for biases[27].integer_indicator, expected 75, is {}",
                    msg.biases[27].integer_indicator
                );
                assert_eq!(msg.biases[27].widelane_integer_indicator, 230, "incorrect value for biases[27].widelane_integer_indicator, expected 230, is {}", msg.biases[27].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[28].bias, -883355501,
                    "incorrect value for biases[28].bias, expected -883355501, is {}",
                    msg.biases[28].bias
                );
                assert_eq!(
                    msg.biases[28].code, 97,
                    "incorrect value for biases[28].code, expected 97, is {}",
                    msg.biases[28].code
                );
                assert_eq!(
                    msg.biases[28].discontinuity_counter, 6,
                    "incorrect value for biases[28].discontinuity_counter, expected 6, is {}",
                    msg.biases[28].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[28].integer_indicator, 88,
                    "incorrect value for biases[28].integer_indicator, expected 88, is {}",
                    msg.biases[28].integer_indicator
                );
                assert_eq!(msg.biases[28].widelane_integer_indicator, 255, "incorrect value for biases[28].widelane_integer_indicator, expected 255, is {}", msg.biases[28].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[29].bias, -1448611273,
                    "incorrect value for biases[29].bias, expected -1448611273, is {}",
                    msg.biases[29].bias
                );
                assert_eq!(
                    msg.biases[29].code, 27,
                    "incorrect value for biases[29].code, expected 27, is {}",
                    msg.biases[29].code
                );
                assert_eq!(
                    msg.biases[29].discontinuity_counter, 230,
                    "incorrect value for biases[29].discontinuity_counter, expected 230, is {}",
                    msg.biases[29].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[29].integer_indicator, 68,
                    "incorrect value for biases[29].integer_indicator, expected 68, is {}",
                    msg.biases[29].integer_indicator
                );
                assert_eq!(msg.biases[29].widelane_integer_indicator, 243, "incorrect value for biases[29].widelane_integer_indicator, expected 243, is {}", msg.biases[29].widelane_integer_indicator);
                assert_eq!(
                    msg.dispersive_bias, 98,
                    "incorrect value for dispersive_bias, expected 98, is {}",
                    msg.dispersive_bias
                );
                assert_eq!(
                    msg.iod_ssr, 230,
                    "incorrect value for iod_ssr, expected 230, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.mw_consistency, 209,
                    "incorrect value for mw_consistency, expected 209, is {}",
                    msg.mw_consistency
                );
                assert_eq!(
                    msg.sid.code, 82,
                    "incorrect value for sid.code, expected 82, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 169,
                    "incorrect value for sid.sat, expected 169, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.time.tow, 210803409,
                    "incorrect value for time.tow, expected 210803409, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 42197,
                    "incorrect value for time.wn, expected 42197, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 177,
                    "incorrect value for update_interval, expected 177, is {}",
                    msg.update_interval
                );
                assert_eq!(
                    msg.yaw, 5881,
                    "incorrect value for yaw, expected 5881, is {}",
                    msg.yaw
                );
                assert_eq!(
                    msg.yaw_rate, 17,
                    "incorrect value for yaw_rate, expected 17, is {}",
                    msg.yaw_rate
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrPhaseBiases"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_phase_biases`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_phase_biases() {
    {
        let mut payload = Cursor::new(vec![
            85, 230, 5, 219, 206, 255, 209, 154, 144, 12, 213, 164, 169, 82, 177, 230, 98, 209,
            249, 22, 17, 29, 250, 245, 193, 219, 30, 212, 177, 207, 187, 33, 146, 58, 204, 164, 65,
            114, 49, 248, 52, 8, 161, 44, 252, 166, 168, 232, 124, 134, 86, 173, 241, 174, 44, 142,
            155, 129, 143, 184, 161, 211, 15, 36, 189, 208, 194, 221, 152, 16, 203, 87, 34, 188,
            141, 104, 189, 102, 156, 252, 22, 251, 136, 49, 188, 157, 222, 245, 49, 132, 16, 34,
            142, 228, 85, 139, 221, 197, 235, 98, 74, 107, 70, 36, 38, 239, 251, 112, 188, 124,
            246, 141, 164, 150, 104, 7, 213, 44, 21, 244, 192, 4, 143, 24, 42, 21, 84, 136, 7, 42,
            118, 45, 23, 174, 175, 129, 54, 169, 14, 213, 2, 197, 98, 60, 13, 207, 105, 100, 129,
            72, 136, 240, 140, 129, 9, 114, 172, 151, 150, 17, 210, 127, 115, 151, 3, 242, 254,
            215, 14, 5, 34, 126, 2, 215, 65, 38, 176, 23, 210, 201, 97, 36, 207, 92, 224, 26, 116,
            155, 211, 165, 47, 102, 38, 67, 199, 55, 117, 36, 169, 33, 1, 230, 201, 183, 21, 42,
            62, 147, 173, 173, 155, 98, 146, 231, 167, 138, 82, 167, 127, 229, 1, 2, 127, 237, 207,
            116, 90, 115, 159, 3, 42, 66, 145, 250, 201, 7, 251, 2, 75, 230, 26, 213, 181, 56, 64,
            97, 88, 255, 6, 147, 16, 89, 203, 27, 68, 243, 230, 55, 242, 167, 169, 219, 240,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrPhaseBiases(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrPhaseBiases(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5e6,
                    "Incorrect message type, expected 0x5e6, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xcedb,
                    "incorrect sender id, expected 0xcedb, is {sender_id}"
                );
                assert_eq!(
                    msg.biases[0].bias, -1311498533,
                    "incorrect value for biases[0].bias, expected -1311498533, is {}",
                    msg.biases[0].bias
                );
                assert_eq!(
                    msg.biases[0].code, 29,
                    "incorrect value for biases[0].code, expected 29, is {}",
                    msg.biases[0].code
                );
                assert_eq!(
                    msg.biases[0].discontinuity_counter, 193,
                    "incorrect value for biases[0].discontinuity_counter, expected 193, is {}",
                    msg.biases[0].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[0].integer_indicator, 250,
                    "incorrect value for biases[0].integer_indicator, expected 250, is {}",
                    msg.biases[0].integer_indicator
                );
                assert_eq!(
                    msg.biases[0].widelane_integer_indicator, 245,
                    "incorrect value for biases[0].widelane_integer_indicator, expected 245, is {}",
                    msg.biases[0].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[1].bias, 1101319226,
                    "incorrect value for biases[1].bias, expected 1101319226, is {}",
                    msg.biases[1].bias
                );
                assert_eq!(
                    msg.biases[1].code, 207,
                    "incorrect value for biases[1].code, expected 207, is {}",
                    msg.biases[1].code
                );
                assert_eq!(
                    msg.biases[1].discontinuity_counter, 146,
                    "incorrect value for biases[1].discontinuity_counter, expected 146, is {}",
                    msg.biases[1].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[1].integer_indicator, 187,
                    "incorrect value for biases[1].integer_indicator, expected 187, is {}",
                    msg.biases[1].integer_indicator
                );
                assert_eq!(
                    msg.biases[1].widelane_integer_indicator, 33,
                    "incorrect value for biases[1].widelane_integer_indicator, expected 33, is {}",
                    msg.biases[1].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[2].bias, -64184056,
                    "incorrect value for biases[2].bias, expected -64184056, is {}",
                    msg.biases[2].bias
                );
                assert_eq!(
                    msg.biases[2].code, 114,
                    "incorrect value for biases[2].code, expected 114, is {}",
                    msg.biases[2].code
                );
                assert_eq!(
                    msg.biases[2].discontinuity_counter, 52,
                    "incorrect value for biases[2].discontinuity_counter, expected 52, is {}",
                    msg.biases[2].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[2].integer_indicator, 49,
                    "incorrect value for biases[2].integer_indicator, expected 49, is {}",
                    msg.biases[2].integer_indicator
                );
                assert_eq!(
                    msg.biases[2].widelane_integer_indicator, 248,
                    "incorrect value for biases[2].widelane_integer_indicator, expected 248, is {}",
                    msg.biases[2].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[3].bias, -240298362,
                    "incorrect value for biases[3].bias, expected -240298362, is {}",
                    msg.biases[3].bias
                );
                assert_eq!(
                    msg.biases[3].code, 166,
                    "incorrect value for biases[3].code, expected 166, is {}",
                    msg.biases[3].code
                );
                assert_eq!(
                    msg.biases[3].discontinuity_counter, 124,
                    "incorrect value for biases[3].discontinuity_counter, expected 124, is {}",
                    msg.biases[3].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[3].integer_indicator, 168,
                    "incorrect value for biases[3].integer_indicator, expected 168, is {}",
                    msg.biases[3].integer_indicator
                );
                assert_eq!(
                    msg.biases[3].widelane_integer_indicator, 232,
                    "incorrect value for biases[3].widelane_integer_indicator, expected 232, is {}",
                    msg.biases[3].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[4].bias, -1581740159,
                    "incorrect value for biases[4].bias, expected -1581740159, is {}",
                    msg.biases[4].bias
                );
                assert_eq!(
                    msg.biases[4].code, 174,
                    "incorrect value for biases[4].code, expected 174, is {}",
                    msg.biases[4].code
                );
                assert_eq!(
                    msg.biases[4].discontinuity_counter, 155,
                    "incorrect value for biases[4].discontinuity_counter, expected 155, is {}",
                    msg.biases[4].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[4].integer_indicator, 44,
                    "incorrect value for biases[4].integer_indicator, expected 44, is {}",
                    msg.biases[4].integer_indicator
                );
                assert_eq!(
                    msg.biases[4].widelane_integer_indicator, 142,
                    "incorrect value for biases[4].widelane_integer_indicator, expected 142, is {}",
                    msg.biases[4].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[5].bias, -1730297136,
                    "incorrect value for biases[5].bias, expected -1730297136, is {}",
                    msg.biases[5].bias
                );
                assert_eq!(
                    msg.biases[5].code, 211,
                    "incorrect value for biases[5].code, expected 211, is {}",
                    msg.biases[5].code
                );
                assert_eq!(
                    msg.biases[5].discontinuity_counter, 189,
                    "incorrect value for biases[5].discontinuity_counter, expected 189, is {}",
                    msg.biases[5].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[5].integer_indicator, 15,
                    "incorrect value for biases[5].integer_indicator, expected 15, is {}",
                    msg.biases[5].integer_indicator
                );
                assert_eq!(
                    msg.biases[5].widelane_integer_indicator, 36,
                    "incorrect value for biases[5].widelane_integer_indicator, expected 36, is {}",
                    msg.biases[5].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[6].bias, -1117221444,
                    "incorrect value for biases[6].bias, expected -1117221444, is {}",
                    msg.biases[6].bias
                );
                assert_eq!(
                    msg.biases[6].code, 16,
                    "incorrect value for biases[6].code, expected 16, is {}",
                    msg.biases[6].code
                );
                assert_eq!(
                    msg.biases[6].discontinuity_counter, 34,
                    "incorrect value for biases[6].discontinuity_counter, expected 34, is {}",
                    msg.biases[6].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[6].integer_indicator, 203,
                    "incorrect value for biases[6].integer_indicator, expected 203, is {}",
                    msg.biases[6].integer_indicator
                );
                assert_eq!(
                    msg.biases[6].widelane_integer_indicator, 87,
                    "incorrect value for biases[6].widelane_integer_indicator, expected 87, is {}",
                    msg.biases[6].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[7].bias, -1137604357,
                    "incorrect value for biases[7].bias, expected -1137604357, is {}",
                    msg.biases[7].bias
                );
                assert_eq!(
                    msg.biases[7].code, 102,
                    "incorrect value for biases[7].code, expected 102, is {}",
                    msg.biases[7].code
                );
                assert_eq!(
                    msg.biases[7].discontinuity_counter, 22,
                    "incorrect value for biases[7].discontinuity_counter, expected 22, is {}",
                    msg.biases[7].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[7].integer_indicator, 156,
                    "incorrect value for biases[7].integer_indicator, expected 156, is {}",
                    msg.biases[7].integer_indicator
                );
                assert_eq!(
                    msg.biases[7].widelane_integer_indicator, 252,
                    "incorrect value for biases[7].widelane_integer_indicator, expected 252, is {}",
                    msg.biases[7].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[8].bias, -1910370172,
                    "incorrect value for biases[8].bias, expected -1910370172, is {}",
                    msg.biases[8].bias
                );
                assert_eq!(
                    msg.biases[8].code, 157,
                    "incorrect value for biases[8].code, expected 157, is {}",
                    msg.biases[8].code
                );
                assert_eq!(
                    msg.biases[8].discontinuity_counter, 49,
                    "incorrect value for biases[8].discontinuity_counter, expected 49, is {}",
                    msg.biases[8].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[8].integer_indicator, 222,
                    "incorrect value for biases[8].integer_indicator, expected 222, is {}",
                    msg.biases[8].integer_indicator
                );
                assert_eq!(
                    msg.biases[8].widelane_integer_indicator, 245,
                    "incorrect value for biases[8].widelane_integer_indicator, expected 245, is {}",
                    msg.biases[8].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[9].bias, 1247996869,
                    "incorrect value for biases[9].bias, expected 1247996869, is {}",
                    msg.biases[9].bias
                );
                assert_eq!(
                    msg.biases[9].code, 228,
                    "incorrect value for biases[9].code, expected 228, is {}",
                    msg.biases[9].code
                );
                assert_eq!(
                    msg.biases[9].discontinuity_counter, 221,
                    "incorrect value for biases[9].discontinuity_counter, expected 221, is {}",
                    msg.biases[9].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[9].integer_indicator, 85,
                    "incorrect value for biases[9].integer_indicator, expected 85, is {}",
                    msg.biases[9].integer_indicator
                );
                assert_eq!(
                    msg.biases[9].widelane_integer_indicator, 139,
                    "incorrect value for biases[9].widelane_integer_indicator, expected 139, is {}",
                    msg.biases[9].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[10].bias, -1133446161,
                    "incorrect value for biases[10].bias, expected -1133446161, is {}",
                    msg.biases[10].bias
                );
                assert_eq!(
                    msg.biases[10].code, 107,
                    "incorrect value for biases[10].code, expected 107, is {}",
                    msg.biases[10].code
                );
                assert_eq!(
                    msg.biases[10].discontinuity_counter, 38,
                    "incorrect value for biases[10].discontinuity_counter, expected 38, is {}",
                    msg.biases[10].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[10].integer_indicator, 70,
                    "incorrect value for biases[10].integer_indicator, expected 70, is {}",
                    msg.biases[10].integer_indicator
                );
                assert_eq!(
                    msg.biases[10].widelane_integer_indicator, 36,
                    "incorrect value for biases[10].widelane_integer_indicator, expected 36, is {}",
                    msg.biases[10].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[11].bias, -720934762,
                    "incorrect value for biases[11].bias, expected -720934762, is {}",
                    msg.biases[11].bias
                );
                assert_eq!(
                    msg.biases[11].code, 124,
                    "incorrect value for biases[11].code, expected 124, is {}",
                    msg.biases[11].code
                );
                assert_eq!(
                    msg.biases[11].discontinuity_counter, 164,
                    "incorrect value for biases[11].discontinuity_counter, expected 164, is {}",
                    msg.biases[11].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[11].integer_indicator, 246,
                    "incorrect value for biases[11].integer_indicator, expected 246, is {}",
                    msg.biases[11].integer_indicator
                );
                assert_eq!(msg.biases[11].widelane_integer_indicator, 141, "incorrect value for biases[11].widelane_integer_indicator, expected 141, is {}", msg.biases[11].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[12].bias, 706252548,
                    "incorrect value for biases[12].bias, expected 706252548, is {}",
                    msg.biases[12].bias
                );
                assert_eq!(
                    msg.biases[12].code, 44,
                    "incorrect value for biases[12].code, expected 44, is {}",
                    msg.biases[12].code
                );
                assert_eq!(
                    msg.biases[12].discontinuity_counter, 192,
                    "incorrect value for biases[12].discontinuity_counter, expected 192, is {}",
                    msg.biases[12].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[12].integer_indicator, 21,
                    "incorrect value for biases[12].integer_indicator, expected 21, is {}",
                    msg.biases[12].integer_indicator
                );
                assert_eq!(msg.biases[12].widelane_integer_indicator, 244, "incorrect value for biases[12].widelane_integer_indicator, expected 244, is {}", msg.biases[12].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[13].bias, 388855338,
                    "incorrect value for biases[13].bias, expected 388855338, is {}",
                    msg.biases[13].bias
                );
                assert_eq!(
                    msg.biases[13].code, 21,
                    "incorrect value for biases[13].code, expected 21, is {}",
                    msg.biases[13].code
                );
                assert_eq!(
                    msg.biases[13].discontinuity_counter, 7,
                    "incorrect value for biases[13].discontinuity_counter, expected 7, is {}",
                    msg.biases[13].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[13].integer_indicator, 84,
                    "incorrect value for biases[13].integer_indicator, expected 84, is {}",
                    msg.biases[13].integer_indicator
                );
                assert_eq!(msg.biases[13].widelane_integer_indicator, 136, "incorrect value for biases[13].widelane_integer_indicator, expected 136, is {}", msg.biases[13].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[14].bias, 47517353,
                    "incorrect value for biases[14].bias, expected 47517353, is {}",
                    msg.biases[14].bias
                );
                assert_eq!(
                    msg.biases[14].code, 174,
                    "incorrect value for biases[14].code, expected 174, is {}",
                    msg.biases[14].code
                );
                assert_eq!(
                    msg.biases[14].discontinuity_counter, 54,
                    "incorrect value for biases[14].discontinuity_counter, expected 54, is {}",
                    msg.biases[14].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[14].integer_indicator, 175,
                    "incorrect value for biases[14].integer_indicator, expected 175, is {}",
                    msg.biases[14].integer_indicator
                );
                assert_eq!(msg.biases[14].widelane_integer_indicator, 129, "incorrect value for biases[14].widelane_integer_indicator, expected 129, is {}", msg.biases[14].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[15].bias, -2124125745,
                    "incorrect value for biases[15].bias, expected -2124125745, is {}",
                    msg.biases[15].bias
                );
                assert_eq!(
                    msg.biases[15].code, 197,
                    "incorrect value for biases[15].code, expected 197, is {}",
                    msg.biases[15].code
                );
                assert_eq!(
                    msg.biases[15].discontinuity_counter, 13,
                    "incorrect value for biases[15].discontinuity_counter, expected 13, is {}",
                    msg.biases[15].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[15].integer_indicator, 98,
                    "incorrect value for biases[15].integer_indicator, expected 98, is {}",
                    msg.biases[15].integer_indicator
                );
                assert_eq!(
                    msg.biases[15].widelane_integer_indicator, 60,
                    "incorrect value for biases[15].widelane_integer_indicator, expected 60, is {}",
                    msg.biases[15].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[16].bias, -1401812607,
                    "incorrect value for biases[16].bias, expected -1401812607, is {}",
                    msg.biases[16].bias
                );
                assert_eq!(
                    msg.biases[16].code, 72,
                    "incorrect value for biases[16].code, expected 72, is {}",
                    msg.biases[16].code
                );
                assert_eq!(
                    msg.biases[16].discontinuity_counter, 140,
                    "incorrect value for biases[16].discontinuity_counter, expected 140, is {}",
                    msg.biases[16].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[16].integer_indicator, 136,
                    "incorrect value for biases[16].integer_indicator, expected 136, is {}",
                    msg.biases[16].integer_indicator
                );
                assert_eq!(msg.biases[16].widelane_integer_indicator, 240, "incorrect value for biases[16].widelane_integer_indicator, expected 240, is {}", msg.biases[16].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[17].bias, 60257151,
                    "incorrect value for biases[17].bias, expected 60257151, is {}",
                    msg.biases[17].bias
                );
                assert_eq!(
                    msg.biases[17].code, 151,
                    "incorrect value for biases[17].code, expected 151, is {}",
                    msg.biases[17].code
                );
                assert_eq!(
                    msg.biases[17].discontinuity_counter, 210,
                    "incorrect value for biases[17].discontinuity_counter, expected 210, is {}",
                    msg.biases[17].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[17].integer_indicator, 150,
                    "incorrect value for biases[17].integer_indicator, expected 150, is {}",
                    msg.biases[17].integer_indicator
                );
                assert_eq!(
                    msg.biases[17].widelane_integer_indicator, 17,
                    "incorrect value for biases[17].widelane_integer_indicator, expected 17, is {}",
                    msg.biases[17].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[18].bias, 41820677,
                    "incorrect value for biases[18].bias, expected 41820677, is {}",
                    msg.biases[18].bias
                );
                assert_eq!(
                    msg.biases[18].code, 242,
                    "incorrect value for biases[18].code, expected 242, is {}",
                    msg.biases[18].code
                );
                assert_eq!(
                    msg.biases[18].discontinuity_counter, 14,
                    "incorrect value for biases[18].discontinuity_counter, expected 14, is {}",
                    msg.biases[18].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[18].integer_indicator, 254,
                    "incorrect value for biases[18].integer_indicator, expected 254, is {}",
                    msg.biases[18].integer_indicator
                );
                assert_eq!(msg.biases[18].widelane_integer_indicator, 215, "incorrect value for biases[18].widelane_integer_indicator, expected 215, is {}", msg.biases[18].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[19].bias, 1640616471,
                    "incorrect value for biases[19].bias, expected 1640616471, is {}",
                    msg.biases[19].bias
                );
                assert_eq!(
                    msg.biases[19].code, 215,
                    "incorrect value for biases[19].code, expected 215, is {}",
                    msg.biases[19].code
                );
                assert_eq!(
                    msg.biases[19].discontinuity_counter, 176,
                    "incorrect value for biases[19].discontinuity_counter, expected 176, is {}",
                    msg.biases[19].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[19].integer_indicator, 65,
                    "incorrect value for biases[19].integer_indicator, expected 65, is {}",
                    msg.biases[19].integer_indicator
                );
                assert_eq!(
                    msg.biases[19].widelane_integer_indicator, 38,
                    "incorrect value for biases[19].widelane_integer_indicator, expected 38, is {}",
                    msg.biases[19].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[20].bias, -744786918,
                    "incorrect value for biases[20].bias, expected -744786918, is {}",
                    msg.biases[20].bias
                );
                assert_eq!(
                    msg.biases[20].code, 36,
                    "incorrect value for biases[20].code, expected 36, is {}",
                    msg.biases[20].code
                );
                assert_eq!(
                    msg.biases[20].discontinuity_counter, 224,
                    "incorrect value for biases[20].discontinuity_counter, expected 224, is {}",
                    msg.biases[20].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[20].integer_indicator, 207,
                    "incorrect value for biases[20].integer_indicator, expected 207, is {}",
                    msg.biases[20].integer_indicator
                );
                assert_eq!(
                    msg.biases[20].widelane_integer_indicator, 92,
                    "incorrect value for biases[20].widelane_integer_indicator, expected 92, is {}",
                    msg.biases[20].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[21].bias, 1966589763,
                    "incorrect value for biases[21].bias, expected 1966589763, is {}",
                    msg.biases[21].bias
                );
                assert_eq!(
                    msg.biases[21].code, 165,
                    "incorrect value for biases[21].code, expected 165, is {}",
                    msg.biases[21].code
                );
                assert_eq!(
                    msg.biases[21].discontinuity_counter, 38,
                    "incorrect value for biases[21].discontinuity_counter, expected 38, is {}",
                    msg.biases[21].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[21].integer_indicator, 47,
                    "incorrect value for biases[21].integer_indicator, expected 47, is {}",
                    msg.biases[21].integer_indicator
                );
                assert_eq!(msg.biases[21].widelane_integer_indicator, 102, "incorrect value for biases[21].widelane_integer_indicator, expected 102, is {}", msg.biases[21].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[22].bias, 364366310,
                    "incorrect value for biases[22].bias, expected 364366310, is {}",
                    msg.biases[22].bias
                );
                assert_eq!(
                    msg.biases[22].code, 36,
                    "incorrect value for biases[22].code, expected 36, is {}",
                    msg.biases[22].code
                );
                assert_eq!(
                    msg.biases[22].discontinuity_counter, 1,
                    "incorrect value for biases[22].discontinuity_counter, expected 1, is {}",
                    msg.biases[22].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[22].integer_indicator, 169,
                    "incorrect value for biases[22].integer_indicator, expected 169, is {}",
                    msg.biases[22].integer_indicator
                );
                assert_eq!(
                    msg.biases[22].widelane_integer_indicator, 33,
                    "incorrect value for biases[22].widelane_integer_indicator, expected 33, is {}",
                    msg.biases[22].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[23].bias, -1839031379,
                    "incorrect value for biases[23].bias, expected -1839031379, is {}",
                    msg.biases[23].bias
                );
                assert_eq!(
                    msg.biases[23].code, 42,
                    "incorrect value for biases[23].code, expected 42, is {}",
                    msg.biases[23].code
                );
                assert_eq!(
                    msg.biases[23].discontinuity_counter, 173,
                    "incorrect value for biases[23].discontinuity_counter, expected 173, is {}",
                    msg.biases[23].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[23].integer_indicator, 62,
                    "incorrect value for biases[23].integer_indicator, expected 62, is {}",
                    msg.biases[23].integer_indicator
                );
                assert_eq!(msg.biases[23].widelane_integer_indicator, 147, "incorrect value for biases[23].widelane_integer_indicator, expected 147, is {}", msg.biases[23].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[24].bias, 31817639,
                    "incorrect value for biases[24].bias, expected 31817639, is {}",
                    msg.biases[24].bias
                );
                assert_eq!(
                    msg.biases[24].code, 231,
                    "incorrect value for biases[24].code, expected 231, is {}",
                    msg.biases[24].code
                );
                assert_eq!(
                    msg.biases[24].discontinuity_counter, 82,
                    "incorrect value for biases[24].discontinuity_counter, expected 82, is {}",
                    msg.biases[24].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[24].integer_indicator, 167,
                    "incorrect value for biases[24].integer_indicator, expected 167, is {}",
                    msg.biases[24].integer_indicator
                );
                assert_eq!(msg.biases[24].widelane_integer_indicator, 138, "incorrect value for biases[24].widelane_integer_indicator, expected 138, is {}", msg.biases[24].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[25].bias, -1619830156,
                    "incorrect value for biases[25].bias, expected -1619830156, is {}",
                    msg.biases[25].bias
                );
                assert_eq!(
                    msg.biases[25].code, 2,
                    "incorrect value for biases[25].code, expected 2, is {}",
                    msg.biases[25].code
                );
                assert_eq!(
                    msg.biases[25].discontinuity_counter, 207,
                    "incorrect value for biases[25].discontinuity_counter, expected 207, is {}",
                    msg.biases[25].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[25].integer_indicator, 127,
                    "incorrect value for biases[25].integer_indicator, expected 127, is {}",
                    msg.biases[25].integer_indicator
                );
                assert_eq!(msg.biases[25].widelane_integer_indicator, 237, "incorrect value for biases[25].widelane_integer_indicator, expected 237, is {}", msg.biases[25].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[26].bias, -83375622,
                    "incorrect value for biases[26].bias, expected -83375622, is {}",
                    msg.biases[26].bias
                );
                assert_eq!(
                    msg.biases[26].code, 3,
                    "incorrect value for biases[26].code, expected 3, is {}",
                    msg.biases[26].code
                );
                assert_eq!(
                    msg.biases[26].discontinuity_counter, 145,
                    "incorrect value for biases[26].discontinuity_counter, expected 145, is {}",
                    msg.biases[26].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[26].integer_indicator, 42,
                    "incorrect value for biases[26].integer_indicator, expected 42, is {}",
                    msg.biases[26].integer_indicator
                );
                assert_eq!(
                    msg.biases[26].widelane_integer_indicator, 66,
                    "incorrect value for biases[26].widelane_integer_indicator, expected 66, is {}",
                    msg.biases[26].widelane_integer_indicator
                );
                assert_eq!(
                    msg.biases[27].bias, 1077458389,
                    "incorrect value for biases[27].bias, expected 1077458389, is {}",
                    msg.biases[27].bias
                );
                assert_eq!(
                    msg.biases[27].code, 2,
                    "incorrect value for biases[27].code, expected 2, is {}",
                    msg.biases[27].code
                );
                assert_eq!(
                    msg.biases[27].discontinuity_counter, 26,
                    "incorrect value for biases[27].discontinuity_counter, expected 26, is {}",
                    msg.biases[27].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[27].integer_indicator, 75,
                    "incorrect value for biases[27].integer_indicator, expected 75, is {}",
                    msg.biases[27].integer_indicator
                );
                assert_eq!(msg.biases[27].widelane_integer_indicator, 230, "incorrect value for biases[27].widelane_integer_indicator, expected 230, is {}", msg.biases[27].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[28].bias, -883355501,
                    "incorrect value for biases[28].bias, expected -883355501, is {}",
                    msg.biases[28].bias
                );
                assert_eq!(
                    msg.biases[28].code, 97,
                    "incorrect value for biases[28].code, expected 97, is {}",
                    msg.biases[28].code
                );
                assert_eq!(
                    msg.biases[28].discontinuity_counter, 6,
                    "incorrect value for biases[28].discontinuity_counter, expected 6, is {}",
                    msg.biases[28].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[28].integer_indicator, 88,
                    "incorrect value for biases[28].integer_indicator, expected 88, is {}",
                    msg.biases[28].integer_indicator
                );
                assert_eq!(msg.biases[28].widelane_integer_indicator, 255, "incorrect value for biases[28].widelane_integer_indicator, expected 255, is {}", msg.biases[28].widelane_integer_indicator);
                assert_eq!(
                    msg.biases[29].bias, -1448611273,
                    "incorrect value for biases[29].bias, expected -1448611273, is {}",
                    msg.biases[29].bias
                );
                assert_eq!(
                    msg.biases[29].code, 27,
                    "incorrect value for biases[29].code, expected 27, is {}",
                    msg.biases[29].code
                );
                assert_eq!(
                    msg.biases[29].discontinuity_counter, 230,
                    "incorrect value for biases[29].discontinuity_counter, expected 230, is {}",
                    msg.biases[29].discontinuity_counter
                );
                assert_eq!(
                    msg.biases[29].integer_indicator, 68,
                    "incorrect value for biases[29].integer_indicator, expected 68, is {}",
                    msg.biases[29].integer_indicator
                );
                assert_eq!(msg.biases[29].widelane_integer_indicator, 243, "incorrect value for biases[29].widelane_integer_indicator, expected 243, is {}", msg.biases[29].widelane_integer_indicator);
                assert_eq!(
                    msg.dispersive_bias, 98,
                    "incorrect value for dispersive_bias, expected 98, is {}",
                    msg.dispersive_bias
                );
                assert_eq!(
                    msg.iod_ssr, 230,
                    "incorrect value for iod_ssr, expected 230, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.mw_consistency, 209,
                    "incorrect value for mw_consistency, expected 209, is {}",
                    msg.mw_consistency
                );
                assert_eq!(
                    msg.sid.code, 82,
                    "incorrect value for sid.code, expected 82, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 169,
                    "incorrect value for sid.sat, expected 169, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.time.tow, 210803409,
                    "incorrect value for time.tow, expected 210803409, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 42197,
                    "incorrect value for time.wn, expected 42197, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 177,
                    "incorrect value for update_interval, expected 177, is {}",
                    msg.update_interval
                );
                assert_eq!(
                    msg.yaw, 5881,
                    "incorrect value for yaw, expected 5881, is {}",
                    msg.yaw
                );
                assert_eq!(
                    msg.yaw_rate, 17,
                    "incorrect value for yaw_rate, expected 17, is {}",
                    msg.yaw_rate
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrPhaseBiases"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
