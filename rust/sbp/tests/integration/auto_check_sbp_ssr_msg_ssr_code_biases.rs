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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrCodeBiases.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_code_biases() {
    {
        let mut payload = Cursor::new(vec![
            85, 225, 5, 39, 87, 253, 208, 90, 19, 23, 9, 66, 133, 241, 254, 132, 51, 4, 131, 240,
            120, 83, 148, 209, 213, 62, 228, 232, 71, 66, 188, 210, 128, 54, 131, 152, 129, 111,
            139, 242, 177, 145, 44, 9, 245, 207, 241, 202, 150, 141, 50, 159, 220, 139, 37, 187,
            98, 191, 23, 128, 136, 167, 200, 6, 211, 90, 23, 244, 138, 215, 209, 139, 13, 101, 32,
            7, 18, 29, 70, 250, 109, 73, 202, 79, 144, 9, 146, 69, 241, 52, 22, 99, 98, 204, 3,
            171, 230, 180, 75, 62, 145, 86, 130, 31, 30, 155, 37, 18, 55, 210, 39, 127, 242, 66,
            13, 237, 152, 170, 212, 15, 246, 59, 94, 180, 195, 157, 69, 100, 119, 16, 68, 179, 175,
            144, 113, 81, 82, 30, 151, 21, 109, 41, 225, 8, 77, 164, 157, 0, 73, 30, 6, 78, 81,
            143, 116, 240, 151, 55, 185, 169, 254, 51, 39, 74, 175, 247, 34, 97, 74, 97, 176, 48,
            236, 173, 12, 174, 101, 130, 30, 169, 193, 190, 204, 196, 123, 107, 25, 225, 74, 9, 10,
            55, 3, 131, 246, 99, 133, 34, 227, 203, 68, 18, 97, 223, 89, 192, 246, 50, 69, 91, 10,
            151, 74, 118, 110, 36, 168, 247, 160, 77, 179, 141, 178, 99, 191, 120, 77, 192, 91,
            224, 1, 226, 50, 87, 146, 148, 238, 100, 179, 125, 227, 215, 104, 184, 31, 57, 90, 79,
            21, 156, 245, 81, 60, 93, 170, 60, 200, 167, 13, 125, 132,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrCodeBiases(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5e1,
                    "Incorrect message type, expected 0x5e1, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5727,
                    "incorrect sender id, expected 0x5727, is {sender_id}"
                );
                assert_eq!(
                    msg.biases[0].code, 51,
                    "incorrect value for biases[0].code, expected 51, is {}",
                    msg.biases[0].code
                );
                assert_eq!(
                    msg.biases[0].value, -31996,
                    "incorrect value for biases[0].value, expected -31996, is {}",
                    msg.biases[0].value
                );
                assert_eq!(
                    msg.biases[1].code, 240,
                    "incorrect value for biases[1].code, expected 240, is {}",
                    msg.biases[1].code
                );
                assert_eq!(
                    msg.biases[1].value, 21368,
                    "incorrect value for biases[1].value, expected 21368, is {}",
                    msg.biases[1].value
                );
                assert_eq!(
                    msg.biases[2].code, 148,
                    "incorrect value for biases[2].code, expected 148, is {}",
                    msg.biases[2].code
                );
                assert_eq!(
                    msg.biases[2].value, -10799,
                    "incorrect value for biases[2].value, expected -10799, is {}",
                    msg.biases[2].value
                );
                assert_eq!(
                    msg.biases[3].code, 62,
                    "incorrect value for biases[3].code, expected 62, is {}",
                    msg.biases[3].code
                );
                assert_eq!(
                    msg.biases[3].value, -5916,
                    "incorrect value for biases[3].value, expected -5916, is {}",
                    msg.biases[3].value
                );
                assert_eq!(
                    msg.biases[4].code, 71,
                    "incorrect value for biases[4].code, expected 71, is {}",
                    msg.biases[4].code
                );
                assert_eq!(
                    msg.biases[4].value, -17342,
                    "incorrect value for biases[4].value, expected -17342, is {}",
                    msg.biases[4].value
                );
                assert_eq!(
                    msg.biases[5].code, 210,
                    "incorrect value for biases[5].code, expected 210, is {}",
                    msg.biases[5].code
                );
                assert_eq!(
                    msg.biases[5].value, 13952,
                    "incorrect value for biases[5].value, expected 13952, is {}",
                    msg.biases[5].value
                );
                assert_eq!(
                    msg.biases[6].code, 131,
                    "incorrect value for biases[6].code, expected 131, is {}",
                    msg.biases[6].code
                );
                assert_eq!(
                    msg.biases[6].value, -32360,
                    "incorrect value for biases[6].value, expected -32360, is {}",
                    msg.biases[6].value
                );
                assert_eq!(
                    msg.biases[7].code, 111,
                    "incorrect value for biases[7].code, expected 111, is {}",
                    msg.biases[7].code
                );
                assert_eq!(
                    msg.biases[7].value, -3445,
                    "incorrect value for biases[7].value, expected -3445, is {}",
                    msg.biases[7].value
                );
                assert_eq!(
                    msg.biases[8].code, 177,
                    "incorrect value for biases[8].code, expected 177, is {}",
                    msg.biases[8].code
                );
                assert_eq!(
                    msg.biases[8].value, 11409,
                    "incorrect value for biases[8].value, expected 11409, is {}",
                    msg.biases[8].value
                );
                assert_eq!(
                    msg.biases[9].code, 9,
                    "incorrect value for biases[9].code, expected 9, is {}",
                    msg.biases[9].code
                );
                assert_eq!(
                    msg.biases[9].value, -12299,
                    "incorrect value for biases[9].value, expected -12299, is {}",
                    msg.biases[9].value
                );
                assert_eq!(
                    msg.biases[10].code, 241,
                    "incorrect value for biases[10].code, expected 241, is {}",
                    msg.biases[10].code
                );
                assert_eq!(
                    msg.biases[10].value, -26934,
                    "incorrect value for biases[10].value, expected -26934, is {}",
                    msg.biases[10].value
                );
                assert_eq!(
                    msg.biases[11].code, 141,
                    "incorrect value for biases[11].code, expected 141, is {}",
                    msg.biases[11].code
                );
                assert_eq!(
                    msg.biases[11].value, -24782,
                    "incorrect value for biases[11].value, expected -24782, is {}",
                    msg.biases[11].value
                );
                assert_eq!(
                    msg.biases[12].code, 220,
                    "incorrect value for biases[12].code, expected 220, is {}",
                    msg.biases[12].code
                );
                assert_eq!(
                    msg.biases[12].value, 9611,
                    "incorrect value for biases[12].value, expected 9611, is {}",
                    msg.biases[12].value
                );
                assert_eq!(
                    msg.biases[13].code, 187,
                    "incorrect value for biases[13].code, expected 187, is {}",
                    msg.biases[13].code
                );
                assert_eq!(
                    msg.biases[13].value, -16542,
                    "incorrect value for biases[13].value, expected -16542, is {}",
                    msg.biases[13].value
                );
                assert_eq!(
                    msg.biases[14].code, 23,
                    "incorrect value for biases[14].code, expected 23, is {}",
                    msg.biases[14].code
                );
                assert_eq!(
                    msg.biases[14].value, -30592,
                    "incorrect value for biases[14].value, expected -30592, is {}",
                    msg.biases[14].value
                );
                assert_eq!(
                    msg.biases[15].code, 167,
                    "incorrect value for biases[15].code, expected 167, is {}",
                    msg.biases[15].code
                );
                assert_eq!(
                    msg.biases[15].value, 1736,
                    "incorrect value for biases[15].value, expected 1736, is {}",
                    msg.biases[15].value
                );
                assert_eq!(
                    msg.biases[16].code, 211,
                    "incorrect value for biases[16].code, expected 211, is {}",
                    msg.biases[16].code
                );
                assert_eq!(
                    msg.biases[16].value, 5978,
                    "incorrect value for biases[16].value, expected 5978, is {}",
                    msg.biases[16].value
                );
                assert_eq!(
                    msg.biases[17].code, 244,
                    "incorrect value for biases[17].code, expected 244, is {}",
                    msg.biases[17].code
                );
                assert_eq!(
                    msg.biases[17].value, -10358,
                    "incorrect value for biases[17].value, expected -10358, is {}",
                    msg.biases[17].value
                );
                assert_eq!(
                    msg.biases[18].code, 209,
                    "incorrect value for biases[18].code, expected 209, is {}",
                    msg.biases[18].code
                );
                assert_eq!(
                    msg.biases[18].value, 3467,
                    "incorrect value for biases[18].value, expected 3467, is {}",
                    msg.biases[18].value
                );
                assert_eq!(
                    msg.biases[19].code, 101,
                    "incorrect value for biases[19].code, expected 101, is {}",
                    msg.biases[19].code
                );
                assert_eq!(
                    msg.biases[19].value, 1824,
                    "incorrect value for biases[19].value, expected 1824, is {}",
                    msg.biases[19].value
                );
                assert_eq!(
                    msg.biases[20].code, 18,
                    "incorrect value for biases[20].code, expected 18, is {}",
                    msg.biases[20].code
                );
                assert_eq!(
                    msg.biases[20].value, 17949,
                    "incorrect value for biases[20].value, expected 17949, is {}",
                    msg.biases[20].value
                );
                assert_eq!(
                    msg.biases[21].code, 250,
                    "incorrect value for biases[21].code, expected 250, is {}",
                    msg.biases[21].code
                );
                assert_eq!(
                    msg.biases[21].value, 18797,
                    "incorrect value for biases[21].value, expected 18797, is {}",
                    msg.biases[21].value
                );
                assert_eq!(
                    msg.biases[22].code, 202,
                    "incorrect value for biases[22].code, expected 202, is {}",
                    msg.biases[22].code
                );
                assert_eq!(
                    msg.biases[22].value, -28593,
                    "incorrect value for biases[22].value, expected -28593, is {}",
                    msg.biases[22].value
                );
                assert_eq!(
                    msg.biases[23].code, 9,
                    "incorrect value for biases[23].code, expected 9, is {}",
                    msg.biases[23].code
                );
                assert_eq!(
                    msg.biases[23].value, 17810,
                    "incorrect value for biases[23].value, expected 17810, is {}",
                    msg.biases[23].value
                );
                assert_eq!(
                    msg.biases[24].code, 241,
                    "incorrect value for biases[24].code, expected 241, is {}",
                    msg.biases[24].code
                );
                assert_eq!(
                    msg.biases[24].value, 5684,
                    "incorrect value for biases[24].value, expected 5684, is {}",
                    msg.biases[24].value
                );
                assert_eq!(
                    msg.biases[25].code, 99,
                    "incorrect value for biases[25].code, expected 99, is {}",
                    msg.biases[25].code
                );
                assert_eq!(
                    msg.biases[25].value, -13214,
                    "incorrect value for biases[25].value, expected -13214, is {}",
                    msg.biases[25].value
                );
                assert_eq!(
                    msg.biases[26].code, 3,
                    "incorrect value for biases[26].code, expected 3, is {}",
                    msg.biases[26].code
                );
                assert_eq!(
                    msg.biases[26].value, -6485,
                    "incorrect value for biases[26].value, expected -6485, is {}",
                    msg.biases[26].value
                );
                assert_eq!(
                    msg.biases[27].code, 180,
                    "incorrect value for biases[27].code, expected 180, is {}",
                    msg.biases[27].code
                );
                assert_eq!(
                    msg.biases[27].value, 15947,
                    "incorrect value for biases[27].value, expected 15947, is {}",
                    msg.biases[27].value
                );
                assert_eq!(
                    msg.biases[28].code, 145,
                    "incorrect value for biases[28].code, expected 145, is {}",
                    msg.biases[28].code
                );
                assert_eq!(
                    msg.biases[28].value, -32170,
                    "incorrect value for biases[28].value, expected -32170, is {}",
                    msg.biases[28].value
                );
                assert_eq!(
                    msg.biases[29].code, 31,
                    "incorrect value for biases[29].code, expected 31, is {}",
                    msg.biases[29].code
                );
                assert_eq!(
                    msg.biases[29].value, -25826,
                    "incorrect value for biases[29].value, expected -25826, is {}",
                    msg.biases[29].value
                );
                assert_eq!(
                    msg.biases[30].code, 37,
                    "incorrect value for biases[30].code, expected 37, is {}",
                    msg.biases[30].code
                );
                assert_eq!(
                    msg.biases[30].value, 14098,
                    "incorrect value for biases[30].value, expected 14098, is {}",
                    msg.biases[30].value
                );
                assert_eq!(
                    msg.biases[31].code, 210,
                    "incorrect value for biases[31].code, expected 210, is {}",
                    msg.biases[31].code
                );
                assert_eq!(
                    msg.biases[31].value, 32551,
                    "incorrect value for biases[31].value, expected 32551, is {}",
                    msg.biases[31].value
                );
                assert_eq!(
                    msg.biases[32].code, 242,
                    "incorrect value for biases[32].code, expected 242, is {}",
                    msg.biases[32].code
                );
                assert_eq!(
                    msg.biases[32].value, 3394,
                    "incorrect value for biases[32].value, expected 3394, is {}",
                    msg.biases[32].value
                );
                assert_eq!(
                    msg.biases[33].code, 237,
                    "incorrect value for biases[33].code, expected 237, is {}",
                    msg.biases[33].code
                );
                assert_eq!(
                    msg.biases[33].value, -21864,
                    "incorrect value for biases[33].value, expected -21864, is {}",
                    msg.biases[33].value
                );
                assert_eq!(
                    msg.biases[34].code, 212,
                    "incorrect value for biases[34].code, expected 212, is {}",
                    msg.biases[34].code
                );
                assert_eq!(
                    msg.biases[34].value, -2545,
                    "incorrect value for biases[34].value, expected -2545, is {}",
                    msg.biases[34].value
                );
                assert_eq!(
                    msg.biases[35].code, 59,
                    "incorrect value for biases[35].code, expected 59, is {}",
                    msg.biases[35].code
                );
                assert_eq!(
                    msg.biases[35].value, -19362,
                    "incorrect value for biases[35].value, expected -19362, is {}",
                    msg.biases[35].value
                );
                assert_eq!(
                    msg.biases[36].code, 195,
                    "incorrect value for biases[36].code, expected 195, is {}",
                    msg.biases[36].code
                );
                assert_eq!(
                    msg.biases[36].value, 17821,
                    "incorrect value for biases[36].value, expected 17821, is {}",
                    msg.biases[36].value
                );
                assert_eq!(
                    msg.biases[37].code, 100,
                    "incorrect value for biases[37].code, expected 100, is {}",
                    msg.biases[37].code
                );
                assert_eq!(
                    msg.biases[37].value, 4215,
                    "incorrect value for biases[37].value, expected 4215, is {}",
                    msg.biases[37].value
                );
                assert_eq!(
                    msg.biases[38].code, 68,
                    "incorrect value for biases[38].code, expected 68, is {}",
                    msg.biases[38].code
                );
                assert_eq!(
                    msg.biases[38].value, -20557,
                    "incorrect value for biases[38].value, expected -20557, is {}",
                    msg.biases[38].value
                );
                assert_eq!(
                    msg.biases[39].code, 144,
                    "incorrect value for biases[39].code, expected 144, is {}",
                    msg.biases[39].code
                );
                assert_eq!(
                    msg.biases[39].value, 20849,
                    "incorrect value for biases[39].value, expected 20849, is {}",
                    msg.biases[39].value
                );
                assert_eq!(
                    msg.biases[40].code, 82,
                    "incorrect value for biases[40].code, expected 82, is {}",
                    msg.biases[40].code
                );
                assert_eq!(
                    msg.biases[40].value, -26850,
                    "incorrect value for biases[40].value, expected -26850, is {}",
                    msg.biases[40].value
                );
                assert_eq!(
                    msg.biases[41].code, 21,
                    "incorrect value for biases[41].code, expected 21, is {}",
                    msg.biases[41].code
                );
                assert_eq!(
                    msg.biases[41].value, 10605,
                    "incorrect value for biases[41].value, expected 10605, is {}",
                    msg.biases[41].value
                );
                assert_eq!(
                    msg.biases[42].code, 225,
                    "incorrect value for biases[42].code, expected 225, is {}",
                    msg.biases[42].code
                );
                assert_eq!(
                    msg.biases[42].value, 19720,
                    "incorrect value for biases[42].value, expected 19720, is {}",
                    msg.biases[42].value
                );
                assert_eq!(
                    msg.biases[43].code, 164,
                    "incorrect value for biases[43].code, expected 164, is {}",
                    msg.biases[43].code
                );
                assert_eq!(
                    msg.biases[43].value, 157,
                    "incorrect value for biases[43].value, expected 157, is {}",
                    msg.biases[43].value
                );
                assert_eq!(
                    msg.biases[44].code, 73,
                    "incorrect value for biases[44].code, expected 73, is {}",
                    msg.biases[44].code
                );
                assert_eq!(
                    msg.biases[44].value, 1566,
                    "incorrect value for biases[44].value, expected 1566, is {}",
                    msg.biases[44].value
                );
                assert_eq!(
                    msg.biases[45].code, 78,
                    "incorrect value for biases[45].code, expected 78, is {}",
                    msg.biases[45].code
                );
                assert_eq!(
                    msg.biases[45].value, -28847,
                    "incorrect value for biases[45].value, expected -28847, is {}",
                    msg.biases[45].value
                );
                assert_eq!(
                    msg.biases[46].code, 116,
                    "incorrect value for biases[46].code, expected 116, is {}",
                    msg.biases[46].code
                );
                assert_eq!(
                    msg.biases[46].value, -26640,
                    "incorrect value for biases[46].value, expected -26640, is {}",
                    msg.biases[46].value
                );
                assert_eq!(
                    msg.biases[47].code, 55,
                    "incorrect value for biases[47].code, expected 55, is {}",
                    msg.biases[47].code
                );
                assert_eq!(
                    msg.biases[47].value, -22087,
                    "incorrect value for biases[47].value, expected -22087, is {}",
                    msg.biases[47].value
                );
                assert_eq!(
                    msg.biases[48].code, 254,
                    "incorrect value for biases[48].code, expected 254, is {}",
                    msg.biases[48].code
                );
                assert_eq!(
                    msg.biases[48].value, 10035,
                    "incorrect value for biases[48].value, expected 10035, is {}",
                    msg.biases[48].value
                );
                assert_eq!(
                    msg.biases[49].code, 74,
                    "incorrect value for biases[49].code, expected 74, is {}",
                    msg.biases[49].code
                );
                assert_eq!(
                    msg.biases[49].value, -2129,
                    "incorrect value for biases[49].value, expected -2129, is {}",
                    msg.biases[49].value
                );
                assert_eq!(
                    msg.biases[50].code, 34,
                    "incorrect value for biases[50].code, expected 34, is {}",
                    msg.biases[50].code
                );
                assert_eq!(
                    msg.biases[50].value, 19041,
                    "incorrect value for biases[50].value, expected 19041, is {}",
                    msg.biases[50].value
                );
                assert_eq!(
                    msg.biases[51].code, 97,
                    "incorrect value for biases[51].code, expected 97, is {}",
                    msg.biases[51].code
                );
                assert_eq!(
                    msg.biases[51].value, 12464,
                    "incorrect value for biases[51].value, expected 12464, is {}",
                    msg.biases[51].value
                );
                assert_eq!(
                    msg.biases[52].code, 236,
                    "incorrect value for biases[52].code, expected 236, is {}",
                    msg.biases[52].code
                );
                assert_eq!(
                    msg.biases[52].value, 3245,
                    "incorrect value for biases[52].value, expected 3245, is {}",
                    msg.biases[52].value
                );
                assert_eq!(
                    msg.biases[53].code, 174,
                    "incorrect value for biases[53].code, expected 174, is {}",
                    msg.biases[53].code
                );
                assert_eq!(
                    msg.biases[53].value, -32155,
                    "incorrect value for biases[53].value, expected -32155, is {}",
                    msg.biases[53].value
                );
                assert_eq!(
                    msg.biases[54].code, 30,
                    "incorrect value for biases[54].code, expected 30, is {}",
                    msg.biases[54].code
                );
                assert_eq!(
                    msg.biases[54].value, -15959,
                    "incorrect value for biases[54].value, expected -15959, is {}",
                    msg.biases[54].value
                );
                assert_eq!(
                    msg.biases[55].code, 190,
                    "incorrect value for biases[55].code, expected 190, is {}",
                    msg.biases[55].code
                );
                assert_eq!(
                    msg.biases[55].value, -15156,
                    "incorrect value for biases[55].value, expected -15156, is {}",
                    msg.biases[55].value
                );
                assert_eq!(
                    msg.biases[56].code, 123,
                    "incorrect value for biases[56].code, expected 123, is {}",
                    msg.biases[56].code
                );
                assert_eq!(
                    msg.biases[56].value, 6507,
                    "incorrect value for biases[56].value, expected 6507, is {}",
                    msg.biases[56].value
                );
                assert_eq!(
                    msg.biases[57].code, 225,
                    "incorrect value for biases[57].code, expected 225, is {}",
                    msg.biases[57].code
                );
                assert_eq!(
                    msg.biases[57].value, 2378,
                    "incorrect value for biases[57].value, expected 2378, is {}",
                    msg.biases[57].value
                );
                assert_eq!(
                    msg.biases[58].code, 10,
                    "incorrect value for biases[58].code, expected 10, is {}",
                    msg.biases[58].code
                );
                assert_eq!(
                    msg.biases[58].value, 823,
                    "incorrect value for biases[58].value, expected 823, is {}",
                    msg.biases[58].value
                );
                assert_eq!(
                    msg.biases[59].code, 131,
                    "incorrect value for biases[59].code, expected 131, is {}",
                    msg.biases[59].code
                );
                assert_eq!(
                    msg.biases[59].value, 25590,
                    "incorrect value for biases[59].value, expected 25590, is {}",
                    msg.biases[59].value
                );
                assert_eq!(
                    msg.biases[60].code, 133,
                    "incorrect value for biases[60].code, expected 133, is {}",
                    msg.biases[60].code
                );
                assert_eq!(
                    msg.biases[60].value, -7390,
                    "incorrect value for biases[60].value, expected -7390, is {}",
                    msg.biases[60].value
                );
                assert_eq!(
                    msg.biases[61].code, 203,
                    "incorrect value for biases[61].code, expected 203, is {}",
                    msg.biases[61].code
                );
                assert_eq!(
                    msg.biases[61].value, 4676,
                    "incorrect value for biases[61].value, expected 4676, is {}",
                    msg.biases[61].value
                );
                assert_eq!(
                    msg.biases[62].code, 97,
                    "incorrect value for biases[62].code, expected 97, is {}",
                    msg.biases[62].code
                );
                assert_eq!(
                    msg.biases[62].value, 23007,
                    "incorrect value for biases[62].value, expected 23007, is {}",
                    msg.biases[62].value
                );
                assert_eq!(
                    msg.biases[63].code, 192,
                    "incorrect value for biases[63].code, expected 192, is {}",
                    msg.biases[63].code
                );
                assert_eq!(
                    msg.biases[63].value, 13046,
                    "incorrect value for biases[63].value, expected 13046, is {}",
                    msg.biases[63].value
                );
                assert_eq!(
                    msg.biases[64].code, 69,
                    "incorrect value for biases[64].code, expected 69, is {}",
                    msg.biases[64].code
                );
                assert_eq!(
                    msg.biases[64].value, 2651,
                    "incorrect value for biases[64].value, expected 2651, is {}",
                    msg.biases[64].value
                );
                assert_eq!(
                    msg.biases[65].code, 151,
                    "incorrect value for biases[65].code, expected 151, is {}",
                    msg.biases[65].code
                );
                assert_eq!(
                    msg.biases[65].value, 30282,
                    "incorrect value for biases[65].value, expected 30282, is {}",
                    msg.biases[65].value
                );
                assert_eq!(
                    msg.biases[66].code, 110,
                    "incorrect value for biases[66].code, expected 110, is {}",
                    msg.biases[66].code
                );
                assert_eq!(
                    msg.biases[66].value, -22492,
                    "incorrect value for biases[66].value, expected -22492, is {}",
                    msg.biases[66].value
                );
                assert_eq!(
                    msg.biases[67].code, 247,
                    "incorrect value for biases[67].code, expected 247, is {}",
                    msg.biases[67].code
                );
                assert_eq!(
                    msg.biases[67].value, 19872,
                    "incorrect value for biases[67].value, expected 19872, is {}",
                    msg.biases[67].value
                );
                assert_eq!(
                    msg.biases[68].code, 179,
                    "incorrect value for biases[68].code, expected 179, is {}",
                    msg.biases[68].code
                );
                assert_eq!(
                    msg.biases[68].value, -19827,
                    "incorrect value for biases[68].value, expected -19827, is {}",
                    msg.biases[68].value
                );
                assert_eq!(
                    msg.biases[69].code, 99,
                    "incorrect value for biases[69].code, expected 99, is {}",
                    msg.biases[69].code
                );
                assert_eq!(
                    msg.biases[69].value, 30911,
                    "incorrect value for biases[69].value, expected 30911, is {}",
                    msg.biases[69].value
                );
                assert_eq!(
                    msg.biases[70].code, 77,
                    "incorrect value for biases[70].code, expected 77, is {}",
                    msg.biases[70].code
                );
                assert_eq!(
                    msg.biases[70].value, 23488,
                    "incorrect value for biases[70].value, expected 23488, is {}",
                    msg.biases[70].value
                );
                assert_eq!(
                    msg.biases[71].code, 224,
                    "incorrect value for biases[71].code, expected 224, is {}",
                    msg.biases[71].code
                );
                assert_eq!(
                    msg.biases[71].value, -7679,
                    "incorrect value for biases[71].value, expected -7679, is {}",
                    msg.biases[71].value
                );
                assert_eq!(
                    msg.biases[72].code, 50,
                    "incorrect value for biases[72].code, expected 50, is {}",
                    msg.biases[72].code
                );
                assert_eq!(
                    msg.biases[72].value, -28073,
                    "incorrect value for biases[72].value, expected -28073, is {}",
                    msg.biases[72].value
                );
                assert_eq!(
                    msg.biases[73].code, 148,
                    "incorrect value for biases[73].code, expected 148, is {}",
                    msg.biases[73].code
                );
                assert_eq!(
                    msg.biases[73].value, 25838,
                    "incorrect value for biases[73].value, expected 25838, is {}",
                    msg.biases[73].value
                );
                assert_eq!(
                    msg.biases[74].code, 179,
                    "incorrect value for biases[74].code, expected 179, is {}",
                    msg.biases[74].code
                );
                assert_eq!(
                    msg.biases[74].value, -7299,
                    "incorrect value for biases[74].value, expected -7299, is {}",
                    msg.biases[74].value
                );
                assert_eq!(
                    msg.biases[75].code, 215,
                    "incorrect value for biases[75].code, expected 215, is {}",
                    msg.biases[75].code
                );
                assert_eq!(
                    msg.biases[75].value, -18328,
                    "incorrect value for biases[75].value, expected -18328, is {}",
                    msg.biases[75].value
                );
                assert_eq!(
                    msg.biases[76].code, 31,
                    "incorrect value for biases[76].code, expected 31, is {}",
                    msg.biases[76].code
                );
                assert_eq!(
                    msg.biases[76].value, 23097,
                    "incorrect value for biases[76].value, expected 23097, is {}",
                    msg.biases[76].value
                );
                assert_eq!(
                    msg.biases[77].code, 79,
                    "incorrect value for biases[77].code, expected 79, is {}",
                    msg.biases[77].code
                );
                assert_eq!(
                    msg.biases[77].value, -25579,
                    "incorrect value for biases[77].value, expected -25579, is {}",
                    msg.biases[77].value
                );
                assert_eq!(
                    msg.biases[78].code, 245,
                    "incorrect value for biases[78].code, expected 245, is {}",
                    msg.biases[78].code
                );
                assert_eq!(
                    msg.biases[78].value, 15441,
                    "incorrect value for biases[78].value, expected 15441, is {}",
                    msg.biases[78].value
                );
                assert_eq!(
                    msg.biases[79].code, 93,
                    "incorrect value for biases[79].code, expected 93, is {}",
                    msg.biases[79].code
                );
                assert_eq!(
                    msg.biases[79].value, 15530,
                    "incorrect value for biases[79].value, expected 15530, is {}",
                    msg.biases[79].value
                );
                assert_eq!(
                    msg.biases[80].code, 200,
                    "incorrect value for biases[80].code, expected 200, is {}",
                    msg.biases[80].code
                );
                assert_eq!(
                    msg.biases[80].value, 3495,
                    "incorrect value for biases[80].value, expected 3495, is {}",
                    msg.biases[80].value
                );
                assert_eq!(
                    msg.iod_ssr, 132,
                    "incorrect value for iod_ssr, expected 132, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.sid.code, 241,
                    "incorrect value for sid.code, expected 241, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 133,
                    "incorrect value for sid.sat, expected 133, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.time.tow, 387144400,
                    "incorrect value for time.tow, expected 387144400, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 16905,
                    "incorrect value for time.wn, expected 16905, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 254,
                    "incorrect value for update_interval, expected 254, is {}",
                    msg.update_interval
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrCodeBiases"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_code_biases() {
    {
        let json_input = r#"{"crc":33917,"length":253,"msg_type":1505,"payload":"0FoTFwlChfH+hDMEg/B4U5TR1T7k6EdCvNKANoOYgW+L8rGRLAn1z/HKlo0yn9yLJbtivxeAiKfIBtNaF/SK19GLDWUgBxIdRvptScpPkAmSRfE0FmNizAOr5rRLPpFWgh8emyUSN9Inf/JCDe2YqtQP9jtetMOdRWR3EESzr5BxUVIelxVtKeEITaSdAEkeBk5Rj3Twlze5qf4zJ0qv9yJhSmGwMOytDK5lgh6pwb7MxHtrGeFKCQo3A4P2Y4Ui48tEEmHfWcD2MkVbCpdKdm4kqPegTbONsmO/eE3AW+AB4jJXkpTuZLN949douB85Wk8VnPVRPF2qPMinDQ==","preamble":85,"sender":22311,"time":{"tow":387144400,"wn":16905},"sid":{"sat":133,"code":241},"update_interval":254,"iod_ssr":132,"biases":[{"code":51,"value":-31996},{"code":240,"value":21368},{"code":148,"value":-10799},{"code":62,"value":-5916},{"code":71,"value":-17342},{"code":210,"value":13952},{"code":131,"value":-32360},{"code":111,"value":-3445},{"code":177,"value":11409},{"code":9,"value":-12299},{"code":241,"value":-26934},{"code":141,"value":-24782},{"code":220,"value":9611},{"code":187,"value":-16542},{"code":23,"value":-30592},{"code":167,"value":1736},{"code":211,"value":5978},{"code":244,"value":-10358},{"code":209,"value":3467},{"code":101,"value":1824},{"code":18,"value":17949},{"code":250,"value":18797},{"code":202,"value":-28593},{"code":9,"value":17810},{"code":241,"value":5684},{"code":99,"value":-13214},{"code":3,"value":-6485},{"code":180,"value":15947},{"code":145,"value":-32170},{"code":31,"value":-25826},{"code":37,"value":14098},{"code":210,"value":32551},{"code":242,"value":3394},{"code":237,"value":-21864},{"code":212,"value":-2545},{"code":59,"value":-19362},{"code":195,"value":17821},{"code":100,"value":4215},{"code":68,"value":-20557},{"code":144,"value":20849},{"code":82,"value":-26850},{"code":21,"value":10605},{"code":225,"value":19720},{"code":164,"value":157},{"code":73,"value":1566},{"code":78,"value":-28847},{"code":116,"value":-26640},{"code":55,"value":-22087},{"code":254,"value":10035},{"code":74,"value":-2129},{"code":34,"value":19041},{"code":97,"value":12464},{"code":236,"value":3245},{"code":174,"value":-32155},{"code":30,"value":-15959},{"code":190,"value":-15156},{"code":123,"value":6507},{"code":225,"value":2378},{"code":10,"value":823},{"code":131,"value":25590},{"code":133,"value":-7390},{"code":203,"value":4676},{"code":97,"value":23007},{"code":192,"value":13046},{"code":69,"value":2651},{"code":151,"value":30282},{"code":110,"value":-22492},{"code":247,"value":19872},{"code":179,"value":-19827},{"code":99,"value":30911},{"code":77,"value":23488},{"code":224,"value":-7679},{"code":50,"value":-28073},{"code":148,"value":25838},{"code":179,"value":-7299},{"code":215,"value":-18328},{"code":31,"value":23097},{"code":79,"value":-25579},{"code":245,"value":15441},{"code":93,"value":15530},{"code":200,"value":3495}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrCodeBiases(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5e1,
                    "Incorrect message type, expected 0x5e1, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5727,
                    "incorrect sender id, expected 0x5727, is {sender_id}"
                );
                assert_eq!(
                    msg.biases[0].code, 51,
                    "incorrect value for biases[0].code, expected 51, is {}",
                    msg.biases[0].code
                );
                assert_eq!(
                    msg.biases[0].value, -31996,
                    "incorrect value for biases[0].value, expected -31996, is {}",
                    msg.biases[0].value
                );
                assert_eq!(
                    msg.biases[1].code, 240,
                    "incorrect value for biases[1].code, expected 240, is {}",
                    msg.biases[1].code
                );
                assert_eq!(
                    msg.biases[1].value, 21368,
                    "incorrect value for biases[1].value, expected 21368, is {}",
                    msg.biases[1].value
                );
                assert_eq!(
                    msg.biases[2].code, 148,
                    "incorrect value for biases[2].code, expected 148, is {}",
                    msg.biases[2].code
                );
                assert_eq!(
                    msg.biases[2].value, -10799,
                    "incorrect value for biases[2].value, expected -10799, is {}",
                    msg.biases[2].value
                );
                assert_eq!(
                    msg.biases[3].code, 62,
                    "incorrect value for biases[3].code, expected 62, is {}",
                    msg.biases[3].code
                );
                assert_eq!(
                    msg.biases[3].value, -5916,
                    "incorrect value for biases[3].value, expected -5916, is {}",
                    msg.biases[3].value
                );
                assert_eq!(
                    msg.biases[4].code, 71,
                    "incorrect value for biases[4].code, expected 71, is {}",
                    msg.biases[4].code
                );
                assert_eq!(
                    msg.biases[4].value, -17342,
                    "incorrect value for biases[4].value, expected -17342, is {}",
                    msg.biases[4].value
                );
                assert_eq!(
                    msg.biases[5].code, 210,
                    "incorrect value for biases[5].code, expected 210, is {}",
                    msg.biases[5].code
                );
                assert_eq!(
                    msg.biases[5].value, 13952,
                    "incorrect value for biases[5].value, expected 13952, is {}",
                    msg.biases[5].value
                );
                assert_eq!(
                    msg.biases[6].code, 131,
                    "incorrect value for biases[6].code, expected 131, is {}",
                    msg.biases[6].code
                );
                assert_eq!(
                    msg.biases[6].value, -32360,
                    "incorrect value for biases[6].value, expected -32360, is {}",
                    msg.biases[6].value
                );
                assert_eq!(
                    msg.biases[7].code, 111,
                    "incorrect value for biases[7].code, expected 111, is {}",
                    msg.biases[7].code
                );
                assert_eq!(
                    msg.biases[7].value, -3445,
                    "incorrect value for biases[7].value, expected -3445, is {}",
                    msg.biases[7].value
                );
                assert_eq!(
                    msg.biases[8].code, 177,
                    "incorrect value for biases[8].code, expected 177, is {}",
                    msg.biases[8].code
                );
                assert_eq!(
                    msg.biases[8].value, 11409,
                    "incorrect value for biases[8].value, expected 11409, is {}",
                    msg.biases[8].value
                );
                assert_eq!(
                    msg.biases[9].code, 9,
                    "incorrect value for biases[9].code, expected 9, is {}",
                    msg.biases[9].code
                );
                assert_eq!(
                    msg.biases[9].value, -12299,
                    "incorrect value for biases[9].value, expected -12299, is {}",
                    msg.biases[9].value
                );
                assert_eq!(
                    msg.biases[10].code, 241,
                    "incorrect value for biases[10].code, expected 241, is {}",
                    msg.biases[10].code
                );
                assert_eq!(
                    msg.biases[10].value, -26934,
                    "incorrect value for biases[10].value, expected -26934, is {}",
                    msg.biases[10].value
                );
                assert_eq!(
                    msg.biases[11].code, 141,
                    "incorrect value for biases[11].code, expected 141, is {}",
                    msg.biases[11].code
                );
                assert_eq!(
                    msg.biases[11].value, -24782,
                    "incorrect value for biases[11].value, expected -24782, is {}",
                    msg.biases[11].value
                );
                assert_eq!(
                    msg.biases[12].code, 220,
                    "incorrect value for biases[12].code, expected 220, is {}",
                    msg.biases[12].code
                );
                assert_eq!(
                    msg.biases[12].value, 9611,
                    "incorrect value for biases[12].value, expected 9611, is {}",
                    msg.biases[12].value
                );
                assert_eq!(
                    msg.biases[13].code, 187,
                    "incorrect value for biases[13].code, expected 187, is {}",
                    msg.biases[13].code
                );
                assert_eq!(
                    msg.biases[13].value, -16542,
                    "incorrect value for biases[13].value, expected -16542, is {}",
                    msg.biases[13].value
                );
                assert_eq!(
                    msg.biases[14].code, 23,
                    "incorrect value for biases[14].code, expected 23, is {}",
                    msg.biases[14].code
                );
                assert_eq!(
                    msg.biases[14].value, -30592,
                    "incorrect value for biases[14].value, expected -30592, is {}",
                    msg.biases[14].value
                );
                assert_eq!(
                    msg.biases[15].code, 167,
                    "incorrect value for biases[15].code, expected 167, is {}",
                    msg.biases[15].code
                );
                assert_eq!(
                    msg.biases[15].value, 1736,
                    "incorrect value for biases[15].value, expected 1736, is {}",
                    msg.biases[15].value
                );
                assert_eq!(
                    msg.biases[16].code, 211,
                    "incorrect value for biases[16].code, expected 211, is {}",
                    msg.biases[16].code
                );
                assert_eq!(
                    msg.biases[16].value, 5978,
                    "incorrect value for biases[16].value, expected 5978, is {}",
                    msg.biases[16].value
                );
                assert_eq!(
                    msg.biases[17].code, 244,
                    "incorrect value for biases[17].code, expected 244, is {}",
                    msg.biases[17].code
                );
                assert_eq!(
                    msg.biases[17].value, -10358,
                    "incorrect value for biases[17].value, expected -10358, is {}",
                    msg.biases[17].value
                );
                assert_eq!(
                    msg.biases[18].code, 209,
                    "incorrect value for biases[18].code, expected 209, is {}",
                    msg.biases[18].code
                );
                assert_eq!(
                    msg.biases[18].value, 3467,
                    "incorrect value for biases[18].value, expected 3467, is {}",
                    msg.biases[18].value
                );
                assert_eq!(
                    msg.biases[19].code, 101,
                    "incorrect value for biases[19].code, expected 101, is {}",
                    msg.biases[19].code
                );
                assert_eq!(
                    msg.biases[19].value, 1824,
                    "incorrect value for biases[19].value, expected 1824, is {}",
                    msg.biases[19].value
                );
                assert_eq!(
                    msg.biases[20].code, 18,
                    "incorrect value for biases[20].code, expected 18, is {}",
                    msg.biases[20].code
                );
                assert_eq!(
                    msg.biases[20].value, 17949,
                    "incorrect value for biases[20].value, expected 17949, is {}",
                    msg.biases[20].value
                );
                assert_eq!(
                    msg.biases[21].code, 250,
                    "incorrect value for biases[21].code, expected 250, is {}",
                    msg.biases[21].code
                );
                assert_eq!(
                    msg.biases[21].value, 18797,
                    "incorrect value for biases[21].value, expected 18797, is {}",
                    msg.biases[21].value
                );
                assert_eq!(
                    msg.biases[22].code, 202,
                    "incorrect value for biases[22].code, expected 202, is {}",
                    msg.biases[22].code
                );
                assert_eq!(
                    msg.biases[22].value, -28593,
                    "incorrect value for biases[22].value, expected -28593, is {}",
                    msg.biases[22].value
                );
                assert_eq!(
                    msg.biases[23].code, 9,
                    "incorrect value for biases[23].code, expected 9, is {}",
                    msg.biases[23].code
                );
                assert_eq!(
                    msg.biases[23].value, 17810,
                    "incorrect value for biases[23].value, expected 17810, is {}",
                    msg.biases[23].value
                );
                assert_eq!(
                    msg.biases[24].code, 241,
                    "incorrect value for biases[24].code, expected 241, is {}",
                    msg.biases[24].code
                );
                assert_eq!(
                    msg.biases[24].value, 5684,
                    "incorrect value for biases[24].value, expected 5684, is {}",
                    msg.biases[24].value
                );
                assert_eq!(
                    msg.biases[25].code, 99,
                    "incorrect value for biases[25].code, expected 99, is {}",
                    msg.biases[25].code
                );
                assert_eq!(
                    msg.biases[25].value, -13214,
                    "incorrect value for biases[25].value, expected -13214, is {}",
                    msg.biases[25].value
                );
                assert_eq!(
                    msg.biases[26].code, 3,
                    "incorrect value for biases[26].code, expected 3, is {}",
                    msg.biases[26].code
                );
                assert_eq!(
                    msg.biases[26].value, -6485,
                    "incorrect value for biases[26].value, expected -6485, is {}",
                    msg.biases[26].value
                );
                assert_eq!(
                    msg.biases[27].code, 180,
                    "incorrect value for biases[27].code, expected 180, is {}",
                    msg.biases[27].code
                );
                assert_eq!(
                    msg.biases[27].value, 15947,
                    "incorrect value for biases[27].value, expected 15947, is {}",
                    msg.biases[27].value
                );
                assert_eq!(
                    msg.biases[28].code, 145,
                    "incorrect value for biases[28].code, expected 145, is {}",
                    msg.biases[28].code
                );
                assert_eq!(
                    msg.biases[28].value, -32170,
                    "incorrect value for biases[28].value, expected -32170, is {}",
                    msg.biases[28].value
                );
                assert_eq!(
                    msg.biases[29].code, 31,
                    "incorrect value for biases[29].code, expected 31, is {}",
                    msg.biases[29].code
                );
                assert_eq!(
                    msg.biases[29].value, -25826,
                    "incorrect value for biases[29].value, expected -25826, is {}",
                    msg.biases[29].value
                );
                assert_eq!(
                    msg.biases[30].code, 37,
                    "incorrect value for biases[30].code, expected 37, is {}",
                    msg.biases[30].code
                );
                assert_eq!(
                    msg.biases[30].value, 14098,
                    "incorrect value for biases[30].value, expected 14098, is {}",
                    msg.biases[30].value
                );
                assert_eq!(
                    msg.biases[31].code, 210,
                    "incorrect value for biases[31].code, expected 210, is {}",
                    msg.biases[31].code
                );
                assert_eq!(
                    msg.biases[31].value, 32551,
                    "incorrect value for biases[31].value, expected 32551, is {}",
                    msg.biases[31].value
                );
                assert_eq!(
                    msg.biases[32].code, 242,
                    "incorrect value for biases[32].code, expected 242, is {}",
                    msg.biases[32].code
                );
                assert_eq!(
                    msg.biases[32].value, 3394,
                    "incorrect value for biases[32].value, expected 3394, is {}",
                    msg.biases[32].value
                );
                assert_eq!(
                    msg.biases[33].code, 237,
                    "incorrect value for biases[33].code, expected 237, is {}",
                    msg.biases[33].code
                );
                assert_eq!(
                    msg.biases[33].value, -21864,
                    "incorrect value for biases[33].value, expected -21864, is {}",
                    msg.biases[33].value
                );
                assert_eq!(
                    msg.biases[34].code, 212,
                    "incorrect value for biases[34].code, expected 212, is {}",
                    msg.biases[34].code
                );
                assert_eq!(
                    msg.biases[34].value, -2545,
                    "incorrect value for biases[34].value, expected -2545, is {}",
                    msg.biases[34].value
                );
                assert_eq!(
                    msg.biases[35].code, 59,
                    "incorrect value for biases[35].code, expected 59, is {}",
                    msg.biases[35].code
                );
                assert_eq!(
                    msg.biases[35].value, -19362,
                    "incorrect value for biases[35].value, expected -19362, is {}",
                    msg.biases[35].value
                );
                assert_eq!(
                    msg.biases[36].code, 195,
                    "incorrect value for biases[36].code, expected 195, is {}",
                    msg.biases[36].code
                );
                assert_eq!(
                    msg.biases[36].value, 17821,
                    "incorrect value for biases[36].value, expected 17821, is {}",
                    msg.biases[36].value
                );
                assert_eq!(
                    msg.biases[37].code, 100,
                    "incorrect value for biases[37].code, expected 100, is {}",
                    msg.biases[37].code
                );
                assert_eq!(
                    msg.biases[37].value, 4215,
                    "incorrect value for biases[37].value, expected 4215, is {}",
                    msg.biases[37].value
                );
                assert_eq!(
                    msg.biases[38].code, 68,
                    "incorrect value for biases[38].code, expected 68, is {}",
                    msg.biases[38].code
                );
                assert_eq!(
                    msg.biases[38].value, -20557,
                    "incorrect value for biases[38].value, expected -20557, is {}",
                    msg.biases[38].value
                );
                assert_eq!(
                    msg.biases[39].code, 144,
                    "incorrect value for biases[39].code, expected 144, is {}",
                    msg.biases[39].code
                );
                assert_eq!(
                    msg.biases[39].value, 20849,
                    "incorrect value for biases[39].value, expected 20849, is {}",
                    msg.biases[39].value
                );
                assert_eq!(
                    msg.biases[40].code, 82,
                    "incorrect value for biases[40].code, expected 82, is {}",
                    msg.biases[40].code
                );
                assert_eq!(
                    msg.biases[40].value, -26850,
                    "incorrect value for biases[40].value, expected -26850, is {}",
                    msg.biases[40].value
                );
                assert_eq!(
                    msg.biases[41].code, 21,
                    "incorrect value for biases[41].code, expected 21, is {}",
                    msg.biases[41].code
                );
                assert_eq!(
                    msg.biases[41].value, 10605,
                    "incorrect value for biases[41].value, expected 10605, is {}",
                    msg.biases[41].value
                );
                assert_eq!(
                    msg.biases[42].code, 225,
                    "incorrect value for biases[42].code, expected 225, is {}",
                    msg.biases[42].code
                );
                assert_eq!(
                    msg.biases[42].value, 19720,
                    "incorrect value for biases[42].value, expected 19720, is {}",
                    msg.biases[42].value
                );
                assert_eq!(
                    msg.biases[43].code, 164,
                    "incorrect value for biases[43].code, expected 164, is {}",
                    msg.biases[43].code
                );
                assert_eq!(
                    msg.biases[43].value, 157,
                    "incorrect value for biases[43].value, expected 157, is {}",
                    msg.biases[43].value
                );
                assert_eq!(
                    msg.biases[44].code, 73,
                    "incorrect value for biases[44].code, expected 73, is {}",
                    msg.biases[44].code
                );
                assert_eq!(
                    msg.biases[44].value, 1566,
                    "incorrect value for biases[44].value, expected 1566, is {}",
                    msg.biases[44].value
                );
                assert_eq!(
                    msg.biases[45].code, 78,
                    "incorrect value for biases[45].code, expected 78, is {}",
                    msg.biases[45].code
                );
                assert_eq!(
                    msg.biases[45].value, -28847,
                    "incorrect value for biases[45].value, expected -28847, is {}",
                    msg.biases[45].value
                );
                assert_eq!(
                    msg.biases[46].code, 116,
                    "incorrect value for biases[46].code, expected 116, is {}",
                    msg.biases[46].code
                );
                assert_eq!(
                    msg.biases[46].value, -26640,
                    "incorrect value for biases[46].value, expected -26640, is {}",
                    msg.biases[46].value
                );
                assert_eq!(
                    msg.biases[47].code, 55,
                    "incorrect value for biases[47].code, expected 55, is {}",
                    msg.biases[47].code
                );
                assert_eq!(
                    msg.biases[47].value, -22087,
                    "incorrect value for biases[47].value, expected -22087, is {}",
                    msg.biases[47].value
                );
                assert_eq!(
                    msg.biases[48].code, 254,
                    "incorrect value for biases[48].code, expected 254, is {}",
                    msg.biases[48].code
                );
                assert_eq!(
                    msg.biases[48].value, 10035,
                    "incorrect value for biases[48].value, expected 10035, is {}",
                    msg.biases[48].value
                );
                assert_eq!(
                    msg.biases[49].code, 74,
                    "incorrect value for biases[49].code, expected 74, is {}",
                    msg.biases[49].code
                );
                assert_eq!(
                    msg.biases[49].value, -2129,
                    "incorrect value for biases[49].value, expected -2129, is {}",
                    msg.biases[49].value
                );
                assert_eq!(
                    msg.biases[50].code, 34,
                    "incorrect value for biases[50].code, expected 34, is {}",
                    msg.biases[50].code
                );
                assert_eq!(
                    msg.biases[50].value, 19041,
                    "incorrect value for biases[50].value, expected 19041, is {}",
                    msg.biases[50].value
                );
                assert_eq!(
                    msg.biases[51].code, 97,
                    "incorrect value for biases[51].code, expected 97, is {}",
                    msg.biases[51].code
                );
                assert_eq!(
                    msg.biases[51].value, 12464,
                    "incorrect value for biases[51].value, expected 12464, is {}",
                    msg.biases[51].value
                );
                assert_eq!(
                    msg.biases[52].code, 236,
                    "incorrect value for biases[52].code, expected 236, is {}",
                    msg.biases[52].code
                );
                assert_eq!(
                    msg.biases[52].value, 3245,
                    "incorrect value for biases[52].value, expected 3245, is {}",
                    msg.biases[52].value
                );
                assert_eq!(
                    msg.biases[53].code, 174,
                    "incorrect value for biases[53].code, expected 174, is {}",
                    msg.biases[53].code
                );
                assert_eq!(
                    msg.biases[53].value, -32155,
                    "incorrect value for biases[53].value, expected -32155, is {}",
                    msg.biases[53].value
                );
                assert_eq!(
                    msg.biases[54].code, 30,
                    "incorrect value for biases[54].code, expected 30, is {}",
                    msg.biases[54].code
                );
                assert_eq!(
                    msg.biases[54].value, -15959,
                    "incorrect value for biases[54].value, expected -15959, is {}",
                    msg.biases[54].value
                );
                assert_eq!(
                    msg.biases[55].code, 190,
                    "incorrect value for biases[55].code, expected 190, is {}",
                    msg.biases[55].code
                );
                assert_eq!(
                    msg.biases[55].value, -15156,
                    "incorrect value for biases[55].value, expected -15156, is {}",
                    msg.biases[55].value
                );
                assert_eq!(
                    msg.biases[56].code, 123,
                    "incorrect value for biases[56].code, expected 123, is {}",
                    msg.biases[56].code
                );
                assert_eq!(
                    msg.biases[56].value, 6507,
                    "incorrect value for biases[56].value, expected 6507, is {}",
                    msg.biases[56].value
                );
                assert_eq!(
                    msg.biases[57].code, 225,
                    "incorrect value for biases[57].code, expected 225, is {}",
                    msg.biases[57].code
                );
                assert_eq!(
                    msg.biases[57].value, 2378,
                    "incorrect value for biases[57].value, expected 2378, is {}",
                    msg.biases[57].value
                );
                assert_eq!(
                    msg.biases[58].code, 10,
                    "incorrect value for biases[58].code, expected 10, is {}",
                    msg.biases[58].code
                );
                assert_eq!(
                    msg.biases[58].value, 823,
                    "incorrect value for biases[58].value, expected 823, is {}",
                    msg.biases[58].value
                );
                assert_eq!(
                    msg.biases[59].code, 131,
                    "incorrect value for biases[59].code, expected 131, is {}",
                    msg.biases[59].code
                );
                assert_eq!(
                    msg.biases[59].value, 25590,
                    "incorrect value for biases[59].value, expected 25590, is {}",
                    msg.biases[59].value
                );
                assert_eq!(
                    msg.biases[60].code, 133,
                    "incorrect value for biases[60].code, expected 133, is {}",
                    msg.biases[60].code
                );
                assert_eq!(
                    msg.biases[60].value, -7390,
                    "incorrect value for biases[60].value, expected -7390, is {}",
                    msg.biases[60].value
                );
                assert_eq!(
                    msg.biases[61].code, 203,
                    "incorrect value for biases[61].code, expected 203, is {}",
                    msg.biases[61].code
                );
                assert_eq!(
                    msg.biases[61].value, 4676,
                    "incorrect value for biases[61].value, expected 4676, is {}",
                    msg.biases[61].value
                );
                assert_eq!(
                    msg.biases[62].code, 97,
                    "incorrect value for biases[62].code, expected 97, is {}",
                    msg.biases[62].code
                );
                assert_eq!(
                    msg.biases[62].value, 23007,
                    "incorrect value for biases[62].value, expected 23007, is {}",
                    msg.biases[62].value
                );
                assert_eq!(
                    msg.biases[63].code, 192,
                    "incorrect value for biases[63].code, expected 192, is {}",
                    msg.biases[63].code
                );
                assert_eq!(
                    msg.biases[63].value, 13046,
                    "incorrect value for biases[63].value, expected 13046, is {}",
                    msg.biases[63].value
                );
                assert_eq!(
                    msg.biases[64].code, 69,
                    "incorrect value for biases[64].code, expected 69, is {}",
                    msg.biases[64].code
                );
                assert_eq!(
                    msg.biases[64].value, 2651,
                    "incorrect value for biases[64].value, expected 2651, is {}",
                    msg.biases[64].value
                );
                assert_eq!(
                    msg.biases[65].code, 151,
                    "incorrect value for biases[65].code, expected 151, is {}",
                    msg.biases[65].code
                );
                assert_eq!(
                    msg.biases[65].value, 30282,
                    "incorrect value for biases[65].value, expected 30282, is {}",
                    msg.biases[65].value
                );
                assert_eq!(
                    msg.biases[66].code, 110,
                    "incorrect value for biases[66].code, expected 110, is {}",
                    msg.biases[66].code
                );
                assert_eq!(
                    msg.biases[66].value, -22492,
                    "incorrect value for biases[66].value, expected -22492, is {}",
                    msg.biases[66].value
                );
                assert_eq!(
                    msg.biases[67].code, 247,
                    "incorrect value for biases[67].code, expected 247, is {}",
                    msg.biases[67].code
                );
                assert_eq!(
                    msg.biases[67].value, 19872,
                    "incorrect value for biases[67].value, expected 19872, is {}",
                    msg.biases[67].value
                );
                assert_eq!(
                    msg.biases[68].code, 179,
                    "incorrect value for biases[68].code, expected 179, is {}",
                    msg.biases[68].code
                );
                assert_eq!(
                    msg.biases[68].value, -19827,
                    "incorrect value for biases[68].value, expected -19827, is {}",
                    msg.biases[68].value
                );
                assert_eq!(
                    msg.biases[69].code, 99,
                    "incorrect value for biases[69].code, expected 99, is {}",
                    msg.biases[69].code
                );
                assert_eq!(
                    msg.biases[69].value, 30911,
                    "incorrect value for biases[69].value, expected 30911, is {}",
                    msg.biases[69].value
                );
                assert_eq!(
                    msg.biases[70].code, 77,
                    "incorrect value for biases[70].code, expected 77, is {}",
                    msg.biases[70].code
                );
                assert_eq!(
                    msg.biases[70].value, 23488,
                    "incorrect value for biases[70].value, expected 23488, is {}",
                    msg.biases[70].value
                );
                assert_eq!(
                    msg.biases[71].code, 224,
                    "incorrect value for biases[71].code, expected 224, is {}",
                    msg.biases[71].code
                );
                assert_eq!(
                    msg.biases[71].value, -7679,
                    "incorrect value for biases[71].value, expected -7679, is {}",
                    msg.biases[71].value
                );
                assert_eq!(
                    msg.biases[72].code, 50,
                    "incorrect value for biases[72].code, expected 50, is {}",
                    msg.biases[72].code
                );
                assert_eq!(
                    msg.biases[72].value, -28073,
                    "incorrect value for biases[72].value, expected -28073, is {}",
                    msg.biases[72].value
                );
                assert_eq!(
                    msg.biases[73].code, 148,
                    "incorrect value for biases[73].code, expected 148, is {}",
                    msg.biases[73].code
                );
                assert_eq!(
                    msg.biases[73].value, 25838,
                    "incorrect value for biases[73].value, expected 25838, is {}",
                    msg.biases[73].value
                );
                assert_eq!(
                    msg.biases[74].code, 179,
                    "incorrect value for biases[74].code, expected 179, is {}",
                    msg.biases[74].code
                );
                assert_eq!(
                    msg.biases[74].value, -7299,
                    "incorrect value for biases[74].value, expected -7299, is {}",
                    msg.biases[74].value
                );
                assert_eq!(
                    msg.biases[75].code, 215,
                    "incorrect value for biases[75].code, expected 215, is {}",
                    msg.biases[75].code
                );
                assert_eq!(
                    msg.biases[75].value, -18328,
                    "incorrect value for biases[75].value, expected -18328, is {}",
                    msg.biases[75].value
                );
                assert_eq!(
                    msg.biases[76].code, 31,
                    "incorrect value for biases[76].code, expected 31, is {}",
                    msg.biases[76].code
                );
                assert_eq!(
                    msg.biases[76].value, 23097,
                    "incorrect value for biases[76].value, expected 23097, is {}",
                    msg.biases[76].value
                );
                assert_eq!(
                    msg.biases[77].code, 79,
                    "incorrect value for biases[77].code, expected 79, is {}",
                    msg.biases[77].code
                );
                assert_eq!(
                    msg.biases[77].value, -25579,
                    "incorrect value for biases[77].value, expected -25579, is {}",
                    msg.biases[77].value
                );
                assert_eq!(
                    msg.biases[78].code, 245,
                    "incorrect value for biases[78].code, expected 245, is {}",
                    msg.biases[78].code
                );
                assert_eq!(
                    msg.biases[78].value, 15441,
                    "incorrect value for biases[78].value, expected 15441, is {}",
                    msg.biases[78].value
                );
                assert_eq!(
                    msg.biases[79].code, 93,
                    "incorrect value for biases[79].code, expected 93, is {}",
                    msg.biases[79].code
                );
                assert_eq!(
                    msg.biases[79].value, 15530,
                    "incorrect value for biases[79].value, expected 15530, is {}",
                    msg.biases[79].value
                );
                assert_eq!(
                    msg.biases[80].code, 200,
                    "incorrect value for biases[80].code, expected 200, is {}",
                    msg.biases[80].code
                );
                assert_eq!(
                    msg.biases[80].value, 3495,
                    "incorrect value for biases[80].value, expected 3495, is {}",
                    msg.biases[80].value
                );
                assert_eq!(
                    msg.iod_ssr, 132,
                    "incorrect value for iod_ssr, expected 132, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.sid.code, 241,
                    "incorrect value for sid.code, expected 241, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 133,
                    "incorrect value for sid.sat, expected 133, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.time.tow, 387144400,
                    "incorrect value for time.tow, expected 387144400, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 16905,
                    "incorrect value for time.wn, expected 16905, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 254,
                    "incorrect value for update_interval, expected 254, is {}",
                    msg.update_interval
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrCodeBiases"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_code_biases`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_code_biases() {
    {
        let mut payload = Cursor::new(vec![
            85, 225, 5, 39, 87, 253, 208, 90, 19, 23, 9, 66, 133, 241, 254, 132, 51, 4, 131, 240,
            120, 83, 148, 209, 213, 62, 228, 232, 71, 66, 188, 210, 128, 54, 131, 152, 129, 111,
            139, 242, 177, 145, 44, 9, 245, 207, 241, 202, 150, 141, 50, 159, 220, 139, 37, 187,
            98, 191, 23, 128, 136, 167, 200, 6, 211, 90, 23, 244, 138, 215, 209, 139, 13, 101, 32,
            7, 18, 29, 70, 250, 109, 73, 202, 79, 144, 9, 146, 69, 241, 52, 22, 99, 98, 204, 3,
            171, 230, 180, 75, 62, 145, 86, 130, 31, 30, 155, 37, 18, 55, 210, 39, 127, 242, 66,
            13, 237, 152, 170, 212, 15, 246, 59, 94, 180, 195, 157, 69, 100, 119, 16, 68, 179, 175,
            144, 113, 81, 82, 30, 151, 21, 109, 41, 225, 8, 77, 164, 157, 0, 73, 30, 6, 78, 81,
            143, 116, 240, 151, 55, 185, 169, 254, 51, 39, 74, 175, 247, 34, 97, 74, 97, 176, 48,
            236, 173, 12, 174, 101, 130, 30, 169, 193, 190, 204, 196, 123, 107, 25, 225, 74, 9, 10,
            55, 3, 131, 246, 99, 133, 34, 227, 203, 68, 18, 97, 223, 89, 192, 246, 50, 69, 91, 10,
            151, 74, 118, 110, 36, 168, 247, 160, 77, 179, 141, 178, 99, 191, 120, 77, 192, 91,
            224, 1, 226, 50, 87, 146, 148, 238, 100, 179, 125, 227, 215, 104, 184, 31, 57, 90, 79,
            21, 156, 245, 81, 60, 93, 170, 60, 200, 167, 13, 125, 132,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrCodeBiases(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrCodeBiases(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5e1,
                    "Incorrect message type, expected 0x5e1, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5727,
                    "incorrect sender id, expected 0x5727, is {sender_id}"
                );
                assert_eq!(
                    msg.biases[0].code, 51,
                    "incorrect value for biases[0].code, expected 51, is {}",
                    msg.biases[0].code
                );
                assert_eq!(
                    msg.biases[0].value, -31996,
                    "incorrect value for biases[0].value, expected -31996, is {}",
                    msg.biases[0].value
                );
                assert_eq!(
                    msg.biases[1].code, 240,
                    "incorrect value for biases[1].code, expected 240, is {}",
                    msg.biases[1].code
                );
                assert_eq!(
                    msg.biases[1].value, 21368,
                    "incorrect value for biases[1].value, expected 21368, is {}",
                    msg.biases[1].value
                );
                assert_eq!(
                    msg.biases[2].code, 148,
                    "incorrect value for biases[2].code, expected 148, is {}",
                    msg.biases[2].code
                );
                assert_eq!(
                    msg.biases[2].value, -10799,
                    "incorrect value for biases[2].value, expected -10799, is {}",
                    msg.biases[2].value
                );
                assert_eq!(
                    msg.biases[3].code, 62,
                    "incorrect value for biases[3].code, expected 62, is {}",
                    msg.biases[3].code
                );
                assert_eq!(
                    msg.biases[3].value, -5916,
                    "incorrect value for biases[3].value, expected -5916, is {}",
                    msg.biases[3].value
                );
                assert_eq!(
                    msg.biases[4].code, 71,
                    "incorrect value for biases[4].code, expected 71, is {}",
                    msg.biases[4].code
                );
                assert_eq!(
                    msg.biases[4].value, -17342,
                    "incorrect value for biases[4].value, expected -17342, is {}",
                    msg.biases[4].value
                );
                assert_eq!(
                    msg.biases[5].code, 210,
                    "incorrect value for biases[5].code, expected 210, is {}",
                    msg.biases[5].code
                );
                assert_eq!(
                    msg.biases[5].value, 13952,
                    "incorrect value for biases[5].value, expected 13952, is {}",
                    msg.biases[5].value
                );
                assert_eq!(
                    msg.biases[6].code, 131,
                    "incorrect value for biases[6].code, expected 131, is {}",
                    msg.biases[6].code
                );
                assert_eq!(
                    msg.biases[6].value, -32360,
                    "incorrect value for biases[6].value, expected -32360, is {}",
                    msg.biases[6].value
                );
                assert_eq!(
                    msg.biases[7].code, 111,
                    "incorrect value for biases[7].code, expected 111, is {}",
                    msg.biases[7].code
                );
                assert_eq!(
                    msg.biases[7].value, -3445,
                    "incorrect value for biases[7].value, expected -3445, is {}",
                    msg.biases[7].value
                );
                assert_eq!(
                    msg.biases[8].code, 177,
                    "incorrect value for biases[8].code, expected 177, is {}",
                    msg.biases[8].code
                );
                assert_eq!(
                    msg.biases[8].value, 11409,
                    "incorrect value for biases[8].value, expected 11409, is {}",
                    msg.biases[8].value
                );
                assert_eq!(
                    msg.biases[9].code, 9,
                    "incorrect value for biases[9].code, expected 9, is {}",
                    msg.biases[9].code
                );
                assert_eq!(
                    msg.biases[9].value, -12299,
                    "incorrect value for biases[9].value, expected -12299, is {}",
                    msg.biases[9].value
                );
                assert_eq!(
                    msg.biases[10].code, 241,
                    "incorrect value for biases[10].code, expected 241, is {}",
                    msg.biases[10].code
                );
                assert_eq!(
                    msg.biases[10].value, -26934,
                    "incorrect value for biases[10].value, expected -26934, is {}",
                    msg.biases[10].value
                );
                assert_eq!(
                    msg.biases[11].code, 141,
                    "incorrect value for biases[11].code, expected 141, is {}",
                    msg.biases[11].code
                );
                assert_eq!(
                    msg.biases[11].value, -24782,
                    "incorrect value for biases[11].value, expected -24782, is {}",
                    msg.biases[11].value
                );
                assert_eq!(
                    msg.biases[12].code, 220,
                    "incorrect value for biases[12].code, expected 220, is {}",
                    msg.biases[12].code
                );
                assert_eq!(
                    msg.biases[12].value, 9611,
                    "incorrect value for biases[12].value, expected 9611, is {}",
                    msg.biases[12].value
                );
                assert_eq!(
                    msg.biases[13].code, 187,
                    "incorrect value for biases[13].code, expected 187, is {}",
                    msg.biases[13].code
                );
                assert_eq!(
                    msg.biases[13].value, -16542,
                    "incorrect value for biases[13].value, expected -16542, is {}",
                    msg.biases[13].value
                );
                assert_eq!(
                    msg.biases[14].code, 23,
                    "incorrect value for biases[14].code, expected 23, is {}",
                    msg.biases[14].code
                );
                assert_eq!(
                    msg.biases[14].value, -30592,
                    "incorrect value for biases[14].value, expected -30592, is {}",
                    msg.biases[14].value
                );
                assert_eq!(
                    msg.biases[15].code, 167,
                    "incorrect value for biases[15].code, expected 167, is {}",
                    msg.biases[15].code
                );
                assert_eq!(
                    msg.biases[15].value, 1736,
                    "incorrect value for biases[15].value, expected 1736, is {}",
                    msg.biases[15].value
                );
                assert_eq!(
                    msg.biases[16].code, 211,
                    "incorrect value for biases[16].code, expected 211, is {}",
                    msg.biases[16].code
                );
                assert_eq!(
                    msg.biases[16].value, 5978,
                    "incorrect value for biases[16].value, expected 5978, is {}",
                    msg.biases[16].value
                );
                assert_eq!(
                    msg.biases[17].code, 244,
                    "incorrect value for biases[17].code, expected 244, is {}",
                    msg.biases[17].code
                );
                assert_eq!(
                    msg.biases[17].value, -10358,
                    "incorrect value for biases[17].value, expected -10358, is {}",
                    msg.biases[17].value
                );
                assert_eq!(
                    msg.biases[18].code, 209,
                    "incorrect value for biases[18].code, expected 209, is {}",
                    msg.biases[18].code
                );
                assert_eq!(
                    msg.biases[18].value, 3467,
                    "incorrect value for biases[18].value, expected 3467, is {}",
                    msg.biases[18].value
                );
                assert_eq!(
                    msg.biases[19].code, 101,
                    "incorrect value for biases[19].code, expected 101, is {}",
                    msg.biases[19].code
                );
                assert_eq!(
                    msg.biases[19].value, 1824,
                    "incorrect value for biases[19].value, expected 1824, is {}",
                    msg.biases[19].value
                );
                assert_eq!(
                    msg.biases[20].code, 18,
                    "incorrect value for biases[20].code, expected 18, is {}",
                    msg.biases[20].code
                );
                assert_eq!(
                    msg.biases[20].value, 17949,
                    "incorrect value for biases[20].value, expected 17949, is {}",
                    msg.biases[20].value
                );
                assert_eq!(
                    msg.biases[21].code, 250,
                    "incorrect value for biases[21].code, expected 250, is {}",
                    msg.biases[21].code
                );
                assert_eq!(
                    msg.biases[21].value, 18797,
                    "incorrect value for biases[21].value, expected 18797, is {}",
                    msg.biases[21].value
                );
                assert_eq!(
                    msg.biases[22].code, 202,
                    "incorrect value for biases[22].code, expected 202, is {}",
                    msg.biases[22].code
                );
                assert_eq!(
                    msg.biases[22].value, -28593,
                    "incorrect value for biases[22].value, expected -28593, is {}",
                    msg.biases[22].value
                );
                assert_eq!(
                    msg.biases[23].code, 9,
                    "incorrect value for biases[23].code, expected 9, is {}",
                    msg.biases[23].code
                );
                assert_eq!(
                    msg.biases[23].value, 17810,
                    "incorrect value for biases[23].value, expected 17810, is {}",
                    msg.biases[23].value
                );
                assert_eq!(
                    msg.biases[24].code, 241,
                    "incorrect value for biases[24].code, expected 241, is {}",
                    msg.biases[24].code
                );
                assert_eq!(
                    msg.biases[24].value, 5684,
                    "incorrect value for biases[24].value, expected 5684, is {}",
                    msg.biases[24].value
                );
                assert_eq!(
                    msg.biases[25].code, 99,
                    "incorrect value for biases[25].code, expected 99, is {}",
                    msg.biases[25].code
                );
                assert_eq!(
                    msg.biases[25].value, -13214,
                    "incorrect value for biases[25].value, expected -13214, is {}",
                    msg.biases[25].value
                );
                assert_eq!(
                    msg.biases[26].code, 3,
                    "incorrect value for biases[26].code, expected 3, is {}",
                    msg.biases[26].code
                );
                assert_eq!(
                    msg.biases[26].value, -6485,
                    "incorrect value for biases[26].value, expected -6485, is {}",
                    msg.biases[26].value
                );
                assert_eq!(
                    msg.biases[27].code, 180,
                    "incorrect value for biases[27].code, expected 180, is {}",
                    msg.biases[27].code
                );
                assert_eq!(
                    msg.biases[27].value, 15947,
                    "incorrect value for biases[27].value, expected 15947, is {}",
                    msg.biases[27].value
                );
                assert_eq!(
                    msg.biases[28].code, 145,
                    "incorrect value for biases[28].code, expected 145, is {}",
                    msg.biases[28].code
                );
                assert_eq!(
                    msg.biases[28].value, -32170,
                    "incorrect value for biases[28].value, expected -32170, is {}",
                    msg.biases[28].value
                );
                assert_eq!(
                    msg.biases[29].code, 31,
                    "incorrect value for biases[29].code, expected 31, is {}",
                    msg.biases[29].code
                );
                assert_eq!(
                    msg.biases[29].value, -25826,
                    "incorrect value for biases[29].value, expected -25826, is {}",
                    msg.biases[29].value
                );
                assert_eq!(
                    msg.biases[30].code, 37,
                    "incorrect value for biases[30].code, expected 37, is {}",
                    msg.biases[30].code
                );
                assert_eq!(
                    msg.biases[30].value, 14098,
                    "incorrect value for biases[30].value, expected 14098, is {}",
                    msg.biases[30].value
                );
                assert_eq!(
                    msg.biases[31].code, 210,
                    "incorrect value for biases[31].code, expected 210, is {}",
                    msg.biases[31].code
                );
                assert_eq!(
                    msg.biases[31].value, 32551,
                    "incorrect value for biases[31].value, expected 32551, is {}",
                    msg.biases[31].value
                );
                assert_eq!(
                    msg.biases[32].code, 242,
                    "incorrect value for biases[32].code, expected 242, is {}",
                    msg.biases[32].code
                );
                assert_eq!(
                    msg.biases[32].value, 3394,
                    "incorrect value for biases[32].value, expected 3394, is {}",
                    msg.biases[32].value
                );
                assert_eq!(
                    msg.biases[33].code, 237,
                    "incorrect value for biases[33].code, expected 237, is {}",
                    msg.biases[33].code
                );
                assert_eq!(
                    msg.biases[33].value, -21864,
                    "incorrect value for biases[33].value, expected -21864, is {}",
                    msg.biases[33].value
                );
                assert_eq!(
                    msg.biases[34].code, 212,
                    "incorrect value for biases[34].code, expected 212, is {}",
                    msg.biases[34].code
                );
                assert_eq!(
                    msg.biases[34].value, -2545,
                    "incorrect value for biases[34].value, expected -2545, is {}",
                    msg.biases[34].value
                );
                assert_eq!(
                    msg.biases[35].code, 59,
                    "incorrect value for biases[35].code, expected 59, is {}",
                    msg.biases[35].code
                );
                assert_eq!(
                    msg.biases[35].value, -19362,
                    "incorrect value for biases[35].value, expected -19362, is {}",
                    msg.biases[35].value
                );
                assert_eq!(
                    msg.biases[36].code, 195,
                    "incorrect value for biases[36].code, expected 195, is {}",
                    msg.biases[36].code
                );
                assert_eq!(
                    msg.biases[36].value, 17821,
                    "incorrect value for biases[36].value, expected 17821, is {}",
                    msg.biases[36].value
                );
                assert_eq!(
                    msg.biases[37].code, 100,
                    "incorrect value for biases[37].code, expected 100, is {}",
                    msg.biases[37].code
                );
                assert_eq!(
                    msg.biases[37].value, 4215,
                    "incorrect value for biases[37].value, expected 4215, is {}",
                    msg.biases[37].value
                );
                assert_eq!(
                    msg.biases[38].code, 68,
                    "incorrect value for biases[38].code, expected 68, is {}",
                    msg.biases[38].code
                );
                assert_eq!(
                    msg.biases[38].value, -20557,
                    "incorrect value for biases[38].value, expected -20557, is {}",
                    msg.biases[38].value
                );
                assert_eq!(
                    msg.biases[39].code, 144,
                    "incorrect value for biases[39].code, expected 144, is {}",
                    msg.biases[39].code
                );
                assert_eq!(
                    msg.biases[39].value, 20849,
                    "incorrect value for biases[39].value, expected 20849, is {}",
                    msg.biases[39].value
                );
                assert_eq!(
                    msg.biases[40].code, 82,
                    "incorrect value for biases[40].code, expected 82, is {}",
                    msg.biases[40].code
                );
                assert_eq!(
                    msg.biases[40].value, -26850,
                    "incorrect value for biases[40].value, expected -26850, is {}",
                    msg.biases[40].value
                );
                assert_eq!(
                    msg.biases[41].code, 21,
                    "incorrect value for biases[41].code, expected 21, is {}",
                    msg.biases[41].code
                );
                assert_eq!(
                    msg.biases[41].value, 10605,
                    "incorrect value for biases[41].value, expected 10605, is {}",
                    msg.biases[41].value
                );
                assert_eq!(
                    msg.biases[42].code, 225,
                    "incorrect value for biases[42].code, expected 225, is {}",
                    msg.biases[42].code
                );
                assert_eq!(
                    msg.biases[42].value, 19720,
                    "incorrect value for biases[42].value, expected 19720, is {}",
                    msg.biases[42].value
                );
                assert_eq!(
                    msg.biases[43].code, 164,
                    "incorrect value for biases[43].code, expected 164, is {}",
                    msg.biases[43].code
                );
                assert_eq!(
                    msg.biases[43].value, 157,
                    "incorrect value for biases[43].value, expected 157, is {}",
                    msg.biases[43].value
                );
                assert_eq!(
                    msg.biases[44].code, 73,
                    "incorrect value for biases[44].code, expected 73, is {}",
                    msg.biases[44].code
                );
                assert_eq!(
                    msg.biases[44].value, 1566,
                    "incorrect value for biases[44].value, expected 1566, is {}",
                    msg.biases[44].value
                );
                assert_eq!(
                    msg.biases[45].code, 78,
                    "incorrect value for biases[45].code, expected 78, is {}",
                    msg.biases[45].code
                );
                assert_eq!(
                    msg.biases[45].value, -28847,
                    "incorrect value for biases[45].value, expected -28847, is {}",
                    msg.biases[45].value
                );
                assert_eq!(
                    msg.biases[46].code, 116,
                    "incorrect value for biases[46].code, expected 116, is {}",
                    msg.biases[46].code
                );
                assert_eq!(
                    msg.biases[46].value, -26640,
                    "incorrect value for biases[46].value, expected -26640, is {}",
                    msg.biases[46].value
                );
                assert_eq!(
                    msg.biases[47].code, 55,
                    "incorrect value for biases[47].code, expected 55, is {}",
                    msg.biases[47].code
                );
                assert_eq!(
                    msg.biases[47].value, -22087,
                    "incorrect value for biases[47].value, expected -22087, is {}",
                    msg.biases[47].value
                );
                assert_eq!(
                    msg.biases[48].code, 254,
                    "incorrect value for biases[48].code, expected 254, is {}",
                    msg.biases[48].code
                );
                assert_eq!(
                    msg.biases[48].value, 10035,
                    "incorrect value for biases[48].value, expected 10035, is {}",
                    msg.biases[48].value
                );
                assert_eq!(
                    msg.biases[49].code, 74,
                    "incorrect value for biases[49].code, expected 74, is {}",
                    msg.biases[49].code
                );
                assert_eq!(
                    msg.biases[49].value, -2129,
                    "incorrect value for biases[49].value, expected -2129, is {}",
                    msg.biases[49].value
                );
                assert_eq!(
                    msg.biases[50].code, 34,
                    "incorrect value for biases[50].code, expected 34, is {}",
                    msg.biases[50].code
                );
                assert_eq!(
                    msg.biases[50].value, 19041,
                    "incorrect value for biases[50].value, expected 19041, is {}",
                    msg.biases[50].value
                );
                assert_eq!(
                    msg.biases[51].code, 97,
                    "incorrect value for biases[51].code, expected 97, is {}",
                    msg.biases[51].code
                );
                assert_eq!(
                    msg.biases[51].value, 12464,
                    "incorrect value for biases[51].value, expected 12464, is {}",
                    msg.biases[51].value
                );
                assert_eq!(
                    msg.biases[52].code, 236,
                    "incorrect value for biases[52].code, expected 236, is {}",
                    msg.biases[52].code
                );
                assert_eq!(
                    msg.biases[52].value, 3245,
                    "incorrect value for biases[52].value, expected 3245, is {}",
                    msg.biases[52].value
                );
                assert_eq!(
                    msg.biases[53].code, 174,
                    "incorrect value for biases[53].code, expected 174, is {}",
                    msg.biases[53].code
                );
                assert_eq!(
                    msg.biases[53].value, -32155,
                    "incorrect value for biases[53].value, expected -32155, is {}",
                    msg.biases[53].value
                );
                assert_eq!(
                    msg.biases[54].code, 30,
                    "incorrect value for biases[54].code, expected 30, is {}",
                    msg.biases[54].code
                );
                assert_eq!(
                    msg.biases[54].value, -15959,
                    "incorrect value for biases[54].value, expected -15959, is {}",
                    msg.biases[54].value
                );
                assert_eq!(
                    msg.biases[55].code, 190,
                    "incorrect value for biases[55].code, expected 190, is {}",
                    msg.biases[55].code
                );
                assert_eq!(
                    msg.biases[55].value, -15156,
                    "incorrect value for biases[55].value, expected -15156, is {}",
                    msg.biases[55].value
                );
                assert_eq!(
                    msg.biases[56].code, 123,
                    "incorrect value for biases[56].code, expected 123, is {}",
                    msg.biases[56].code
                );
                assert_eq!(
                    msg.biases[56].value, 6507,
                    "incorrect value for biases[56].value, expected 6507, is {}",
                    msg.biases[56].value
                );
                assert_eq!(
                    msg.biases[57].code, 225,
                    "incorrect value for biases[57].code, expected 225, is {}",
                    msg.biases[57].code
                );
                assert_eq!(
                    msg.biases[57].value, 2378,
                    "incorrect value for biases[57].value, expected 2378, is {}",
                    msg.biases[57].value
                );
                assert_eq!(
                    msg.biases[58].code, 10,
                    "incorrect value for biases[58].code, expected 10, is {}",
                    msg.biases[58].code
                );
                assert_eq!(
                    msg.biases[58].value, 823,
                    "incorrect value for biases[58].value, expected 823, is {}",
                    msg.biases[58].value
                );
                assert_eq!(
                    msg.biases[59].code, 131,
                    "incorrect value for biases[59].code, expected 131, is {}",
                    msg.biases[59].code
                );
                assert_eq!(
                    msg.biases[59].value, 25590,
                    "incorrect value for biases[59].value, expected 25590, is {}",
                    msg.biases[59].value
                );
                assert_eq!(
                    msg.biases[60].code, 133,
                    "incorrect value for biases[60].code, expected 133, is {}",
                    msg.biases[60].code
                );
                assert_eq!(
                    msg.biases[60].value, -7390,
                    "incorrect value for biases[60].value, expected -7390, is {}",
                    msg.biases[60].value
                );
                assert_eq!(
                    msg.biases[61].code, 203,
                    "incorrect value for biases[61].code, expected 203, is {}",
                    msg.biases[61].code
                );
                assert_eq!(
                    msg.biases[61].value, 4676,
                    "incorrect value for biases[61].value, expected 4676, is {}",
                    msg.biases[61].value
                );
                assert_eq!(
                    msg.biases[62].code, 97,
                    "incorrect value for biases[62].code, expected 97, is {}",
                    msg.biases[62].code
                );
                assert_eq!(
                    msg.biases[62].value, 23007,
                    "incorrect value for biases[62].value, expected 23007, is {}",
                    msg.biases[62].value
                );
                assert_eq!(
                    msg.biases[63].code, 192,
                    "incorrect value for biases[63].code, expected 192, is {}",
                    msg.biases[63].code
                );
                assert_eq!(
                    msg.biases[63].value, 13046,
                    "incorrect value for biases[63].value, expected 13046, is {}",
                    msg.biases[63].value
                );
                assert_eq!(
                    msg.biases[64].code, 69,
                    "incorrect value for biases[64].code, expected 69, is {}",
                    msg.biases[64].code
                );
                assert_eq!(
                    msg.biases[64].value, 2651,
                    "incorrect value for biases[64].value, expected 2651, is {}",
                    msg.biases[64].value
                );
                assert_eq!(
                    msg.biases[65].code, 151,
                    "incorrect value for biases[65].code, expected 151, is {}",
                    msg.biases[65].code
                );
                assert_eq!(
                    msg.biases[65].value, 30282,
                    "incorrect value for biases[65].value, expected 30282, is {}",
                    msg.biases[65].value
                );
                assert_eq!(
                    msg.biases[66].code, 110,
                    "incorrect value for biases[66].code, expected 110, is {}",
                    msg.biases[66].code
                );
                assert_eq!(
                    msg.biases[66].value, -22492,
                    "incorrect value for biases[66].value, expected -22492, is {}",
                    msg.biases[66].value
                );
                assert_eq!(
                    msg.biases[67].code, 247,
                    "incorrect value for biases[67].code, expected 247, is {}",
                    msg.biases[67].code
                );
                assert_eq!(
                    msg.biases[67].value, 19872,
                    "incorrect value for biases[67].value, expected 19872, is {}",
                    msg.biases[67].value
                );
                assert_eq!(
                    msg.biases[68].code, 179,
                    "incorrect value for biases[68].code, expected 179, is {}",
                    msg.biases[68].code
                );
                assert_eq!(
                    msg.biases[68].value, -19827,
                    "incorrect value for biases[68].value, expected -19827, is {}",
                    msg.biases[68].value
                );
                assert_eq!(
                    msg.biases[69].code, 99,
                    "incorrect value for biases[69].code, expected 99, is {}",
                    msg.biases[69].code
                );
                assert_eq!(
                    msg.biases[69].value, 30911,
                    "incorrect value for biases[69].value, expected 30911, is {}",
                    msg.biases[69].value
                );
                assert_eq!(
                    msg.biases[70].code, 77,
                    "incorrect value for biases[70].code, expected 77, is {}",
                    msg.biases[70].code
                );
                assert_eq!(
                    msg.biases[70].value, 23488,
                    "incorrect value for biases[70].value, expected 23488, is {}",
                    msg.biases[70].value
                );
                assert_eq!(
                    msg.biases[71].code, 224,
                    "incorrect value for biases[71].code, expected 224, is {}",
                    msg.biases[71].code
                );
                assert_eq!(
                    msg.biases[71].value, -7679,
                    "incorrect value for biases[71].value, expected -7679, is {}",
                    msg.biases[71].value
                );
                assert_eq!(
                    msg.biases[72].code, 50,
                    "incorrect value for biases[72].code, expected 50, is {}",
                    msg.biases[72].code
                );
                assert_eq!(
                    msg.biases[72].value, -28073,
                    "incorrect value for biases[72].value, expected -28073, is {}",
                    msg.biases[72].value
                );
                assert_eq!(
                    msg.biases[73].code, 148,
                    "incorrect value for biases[73].code, expected 148, is {}",
                    msg.biases[73].code
                );
                assert_eq!(
                    msg.biases[73].value, 25838,
                    "incorrect value for biases[73].value, expected 25838, is {}",
                    msg.biases[73].value
                );
                assert_eq!(
                    msg.biases[74].code, 179,
                    "incorrect value for biases[74].code, expected 179, is {}",
                    msg.biases[74].code
                );
                assert_eq!(
                    msg.biases[74].value, -7299,
                    "incorrect value for biases[74].value, expected -7299, is {}",
                    msg.biases[74].value
                );
                assert_eq!(
                    msg.biases[75].code, 215,
                    "incorrect value for biases[75].code, expected 215, is {}",
                    msg.biases[75].code
                );
                assert_eq!(
                    msg.biases[75].value, -18328,
                    "incorrect value for biases[75].value, expected -18328, is {}",
                    msg.biases[75].value
                );
                assert_eq!(
                    msg.biases[76].code, 31,
                    "incorrect value for biases[76].code, expected 31, is {}",
                    msg.biases[76].code
                );
                assert_eq!(
                    msg.biases[76].value, 23097,
                    "incorrect value for biases[76].value, expected 23097, is {}",
                    msg.biases[76].value
                );
                assert_eq!(
                    msg.biases[77].code, 79,
                    "incorrect value for biases[77].code, expected 79, is {}",
                    msg.biases[77].code
                );
                assert_eq!(
                    msg.biases[77].value, -25579,
                    "incorrect value for biases[77].value, expected -25579, is {}",
                    msg.biases[77].value
                );
                assert_eq!(
                    msg.biases[78].code, 245,
                    "incorrect value for biases[78].code, expected 245, is {}",
                    msg.biases[78].code
                );
                assert_eq!(
                    msg.biases[78].value, 15441,
                    "incorrect value for biases[78].value, expected 15441, is {}",
                    msg.biases[78].value
                );
                assert_eq!(
                    msg.biases[79].code, 93,
                    "incorrect value for biases[79].code, expected 93, is {}",
                    msg.biases[79].code
                );
                assert_eq!(
                    msg.biases[79].value, 15530,
                    "incorrect value for biases[79].value, expected 15530, is {}",
                    msg.biases[79].value
                );
                assert_eq!(
                    msg.biases[80].code, 200,
                    "incorrect value for biases[80].code, expected 200, is {}",
                    msg.biases[80].code
                );
                assert_eq!(
                    msg.biases[80].value, 3495,
                    "incorrect value for biases[80].value, expected 3495, is {}",
                    msg.biases[80].value
                );
                assert_eq!(
                    msg.iod_ssr, 132,
                    "incorrect value for iod_ssr, expected 132, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.sid.code, 241,
                    "incorrect value for sid.code, expected 241, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 133,
                    "incorrect value for sid.sat, expected 133, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.time.tow, 387144400,
                    "incorrect value for time.tow, expected 387144400, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 16905,
                    "incorrect value for time.wn, expected 16905, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 254,
                    "incorrect value for update_interval, expected 254, is {}",
                    msg.update_interval
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrCodeBiases"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
