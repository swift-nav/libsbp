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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrectionDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_stec_correction_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 235, 5, 39, 7, 252, 70, 81, 196, 232, 185, 43, 147, 123, 39, 4, 126, 19, 111, 97,
            248, 130, 217, 217, 106, 58, 12, 65, 230, 171, 81, 95, 86, 16, 39, 84, 228, 208, 201,
            81, 219, 99, 203, 61, 182, 66, 125, 203, 3, 193, 44, 100, 220, 125, 60, 21, 93, 218,
            247, 158, 207, 93, 129, 134, 14, 209, 48, 14, 215, 153, 148, 147, 72, 225, 180, 236,
            205, 201, 33, 3, 246, 204, 19, 3, 98, 4, 194, 191, 246, 76, 219, 31, 191, 113, 79, 177,
            15, 251, 33, 19, 96, 54, 58, 146, 210, 100, 249, 72, 21, 161, 211, 198, 21, 238, 111,
            107, 36, 227, 225, 213, 3, 71, 243, 63, 65, 236, 92, 77, 0, 169, 15, 182, 5, 240, 180,
            9, 122, 86, 232, 6, 103, 104, 254, 189, 81, 110, 2, 49, 202, 84, 216, 55, 50, 181, 5,
            123, 80, 49, 244, 224, 188, 125, 164, 230, 56, 66, 124, 168, 59, 139, 106, 118, 51,
            187, 216, 191, 158, 77, 92, 58, 253, 132, 150, 165, 9, 154, 189, 218, 61, 209, 1, 82,
            181, 196, 23, 53, 182, 112, 192, 206, 167, 157, 244, 35, 1, 189, 217, 61, 88, 97, 201,
            201, 74, 251, 217, 14, 104, 184, 54, 52, 74, 238, 10, 129, 22, 178, 226, 109, 88, 157,
            30, 196, 175, 26, 76, 34, 116, 220, 154, 232, 12, 179, 244, 15, 155, 196, 202, 72, 70,
            115, 10, 214, 114, 39, 245, 28, 237, 68, 136, 155,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrStecCorrectionDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5eb,
                    "Incorrect message type, expected 0x5eb, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0727,
                    "incorrect sender id, expected 0x0727, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 4,
                    "incorrect value for header.iod_atmo, expected 4, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 147,
                    "incorrect value for header.num_msgs, expected 147, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 123,
                    "incorrect value for header.seq_num, expected 123, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.time.tow, 3905179974,
                    "incorrect value for header.time.tow, expected 3905179974, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 11193,
                    "incorrect value for header.time.wn, expected 11193, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.update_interval, 39,
                    "incorrect value for header.update_interval, expected 39, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[0], -1951,
                    "incorrect value for stec_sat_list[0].stec_coeff[0], expected -1951, is {}",
                    msg.stec_sat_list[0].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[1], -9854,
                    "incorrect value for stec_sat_list[0].stec_coeff[1], expected -9854, is {}",
                    msg.stec_sat_list[0].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[2], 27353,
                    "incorrect value for stec_sat_list[0].stec_coeff[2], expected 27353, is {}",
                    msg.stec_sat_list[0].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[3], 3130,
                    "incorrect value for stec_sat_list[0].stec_coeff[3], expected 3130, is {}",
                    msg.stec_sat_list[0].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[0].stec_quality_indicator, 111, "incorrect value for stec_sat_list[0].stec_quality_indicator, expected 111, is {}", msg.stec_sat_list[0].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.constellation, 19,
                    "incorrect value for stec_sat_list[0].sv_id.constellation, expected 19, is {}",
                    msg.stec_sat_list[0].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.sat_id, 126,
                    "incorrect value for stec_sat_list[0].sv_id.sat_id, expected 126, is {}",
                    msg.stec_sat_list[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[0], 24401,
                    "incorrect value for stec_sat_list[1].stec_coeff[0], expected 24401, is {}",
                    msg.stec_sat_list[1].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[1], 4182,
                    "incorrect value for stec_sat_list[1].stec_coeff[1], expected 4182, is {}",
                    msg.stec_sat_list[1].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[2], 21543,
                    "incorrect value for stec_sat_list[1].stec_coeff[2], expected 21543, is {}",
                    msg.stec_sat_list[1].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[3], -12060,
                    "incorrect value for stec_sat_list[1].stec_coeff[3], expected -12060, is {}",
                    msg.stec_sat_list[1].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[1].stec_quality_indicator, 171, "incorrect value for stec_sat_list[1].stec_quality_indicator, expected 171, is {}", msg.stec_sat_list[1].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.constellation, 230,
                    "incorrect value for stec_sat_list[1].sv_id.constellation, expected 230, is {}",
                    msg.stec_sat_list[1].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.sat_id, 65,
                    "incorrect value for stec_sat_list[1].sv_id.sat_id, expected 65, is {}",
                    msg.stec_sat_list[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[0], -13469,
                    "incorrect value for stec_sat_list[2].stec_coeff[0], expected -13469, is {}",
                    msg.stec_sat_list[2].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[1], -18883,
                    "incorrect value for stec_sat_list[2].stec_coeff[1], expected -18883, is {}",
                    msg.stec_sat_list[2].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[2], 32066,
                    "incorrect value for stec_sat_list[2].stec_coeff[2], expected 32066, is {}",
                    msg.stec_sat_list[2].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[3], 971,
                    "incorrect value for stec_sat_list[2].stec_coeff[3], expected 971, is {}",
                    msg.stec_sat_list[2].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[2].stec_quality_indicator, 219, "incorrect value for stec_sat_list[2].stec_quality_indicator, expected 219, is {}", msg.stec_sat_list[2].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[2].sv_id.constellation, 81,
                    "incorrect value for stec_sat_list[2].sv_id.constellation, expected 81, is {}",
                    msg.stec_sat_list[2].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[2].sv_id.sat_id, 201,
                    "incorrect value for stec_sat_list[2].sv_id.sat_id, expected 201, is {}",
                    msg.stec_sat_list[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[0], 32220,
                    "incorrect value for stec_sat_list[3].stec_coeff[0], expected 32220, is {}",
                    msg.stec_sat_list[3].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[1], 5436,
                    "incorrect value for stec_sat_list[3].stec_coeff[1], expected 5436, is {}",
                    msg.stec_sat_list[3].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[2], -9635,
                    "incorrect value for stec_sat_list[3].stec_coeff[2], expected -9635, is {}",
                    msg.stec_sat_list[3].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[3], -24841,
                    "incorrect value for stec_sat_list[3].stec_coeff[3], expected -24841, is {}",
                    msg.stec_sat_list[3].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[3].stec_quality_indicator, 100, "incorrect value for stec_sat_list[3].stec_quality_indicator, expected 100, is {}", msg.stec_sat_list[3].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[3].sv_id.constellation, 44,
                    "incorrect value for stec_sat_list[3].sv_id.constellation, expected 44, is {}",
                    msg.stec_sat_list[3].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[3].sv_id.sat_id, 193,
                    "incorrect value for stec_sat_list[3].sv_id.sat_id, expected 193, is {}",
                    msg.stec_sat_list[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[0], 3718,
                    "incorrect value for stec_sat_list[4].stec_coeff[0], expected 3718, is {}",
                    msg.stec_sat_list[4].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[1], 12497,
                    "incorrect value for stec_sat_list[4].stec_coeff[1], expected 12497, is {}",
                    msg.stec_sat_list[4].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[2], -10482,
                    "incorrect value for stec_sat_list[4].stec_coeff[2], expected -10482, is {}",
                    msg.stec_sat_list[4].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[3], -27495,
                    "incorrect value for stec_sat_list[4].stec_coeff[3], expected -27495, is {}",
                    msg.stec_sat_list[4].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[4].stec_quality_indicator, 129, "incorrect value for stec_sat_list[4].stec_quality_indicator, expected 129, is {}", msg.stec_sat_list[4].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[4].sv_id.constellation, 93,
                    "incorrect value for stec_sat_list[4].sv_id.constellation, expected 93, is {}",
                    msg.stec_sat_list[4].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[4].sv_id.sat_id, 207,
                    "incorrect value for stec_sat_list[4].sv_id.sat_id, expected 207, is {}",
                    msg.stec_sat_list[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[0], -4940,
                    "incorrect value for stec_sat_list[5].stec_coeff[0], expected -4940, is {}",
                    msg.stec_sat_list[5].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[1], -13875,
                    "incorrect value for stec_sat_list[5].stec_coeff[1], expected -13875, is {}",
                    msg.stec_sat_list[5].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[2], 801,
                    "incorrect value for stec_sat_list[5].stec_coeff[2], expected 801, is {}",
                    msg.stec_sat_list[5].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[3], -13066,
                    "incorrect value for stec_sat_list[5].stec_coeff[3], expected -13066, is {}",
                    msg.stec_sat_list[5].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[5].stec_quality_indicator, 225, "incorrect value for stec_sat_list[5].stec_quality_indicator, expected 225, is {}", msg.stec_sat_list[5].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[5].sv_id.constellation, 72,
                    "incorrect value for stec_sat_list[5].sv_id.constellation, expected 72, is {}",
                    msg.stec_sat_list[5].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[5].sv_id.sat_id, 147,
                    "incorrect value for stec_sat_list[5].sv_id.sat_id, expected 147, is {}",
                    msg.stec_sat_list[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[0], -15868,
                    "incorrect value for stec_sat_list[6].stec_coeff[0], expected -15868, is {}",
                    msg.stec_sat_list[6].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[1], -2369,
                    "incorrect value for stec_sat_list[6].stec_coeff[1], expected -2369, is {}",
                    msg.stec_sat_list[6].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[2], -9396,
                    "incorrect value for stec_sat_list[6].stec_coeff[2], expected -9396, is {}",
                    msg.stec_sat_list[6].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[3], -16609,
                    "incorrect value for stec_sat_list[6].stec_coeff[3], expected -16609, is {}",
                    msg.stec_sat_list[6].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[6].stec_quality_indicator, 98, "incorrect value for stec_sat_list[6].stec_quality_indicator, expected 98, is {}", msg.stec_sat_list[6].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[6].sv_id.constellation, 3,
                    "incorrect value for stec_sat_list[6].sv_id.constellation, expected 3, is {}",
                    msg.stec_sat_list[6].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[6].sv_id.sat_id, 19,
                    "incorrect value for stec_sat_list[6].sv_id.sat_id, expected 19, is {}",
                    msg.stec_sat_list[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[0], -1265,
                    "incorrect value for stec_sat_list[7].stec_coeff[0], expected -1265, is {}",
                    msg.stec_sat_list[7].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[1], 4897,
                    "incorrect value for stec_sat_list[7].stec_coeff[1], expected 4897, is {}",
                    msg.stec_sat_list[7].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[2], 13920,
                    "incorrect value for stec_sat_list[7].stec_coeff[2], expected 13920, is {}",
                    msg.stec_sat_list[7].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[3], -28102,
                    "incorrect value for stec_sat_list[7].stec_coeff[3], expected -28102, is {}",
                    msg.stec_sat_list[7].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[7].stec_quality_indicator, 177, "incorrect value for stec_sat_list[7].stec_quality_indicator, expected 177, is {}", msg.stec_sat_list[7].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[7].sv_id.constellation, 79,
                    "incorrect value for stec_sat_list[7].sv_id.constellation, expected 79, is {}",
                    msg.stec_sat_list[7].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[7].sv_id.sat_id, 113,
                    "incorrect value for stec_sat_list[7].sv_id.sat_id, expected 113, is {}",
                    msg.stec_sat_list[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[0], 5448,
                    "incorrect value for stec_sat_list[8].stec_coeff[0], expected 5448, is {}",
                    msg.stec_sat_list[8].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[1], -11359,
                    "incorrect value for stec_sat_list[8].stec_coeff[1], expected -11359, is {}",
                    msg.stec_sat_list[8].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[2], 5574,
                    "incorrect value for stec_sat_list[8].stec_coeff[2], expected 5574, is {}",
                    msg.stec_sat_list[8].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[3], 28654,
                    "incorrect value for stec_sat_list[8].stec_coeff[3], expected 28654, is {}",
                    msg.stec_sat_list[8].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[8].stec_quality_indicator, 249, "incorrect value for stec_sat_list[8].stec_quality_indicator, expected 249, is {}", msg.stec_sat_list[8].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[8].sv_id.constellation, 100,
                    "incorrect value for stec_sat_list[8].sv_id.constellation, expected 100, is {}",
                    msg.stec_sat_list[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[8].sv_id.sat_id, 210,
                    "incorrect value for stec_sat_list[8].sv_id.sat_id, expected 210, is {}",
                    msg.stec_sat_list[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[0], -10783,
                    "incorrect value for stec_sat_list[9].stec_coeff[0], expected -10783, is {}",
                    msg.stec_sat_list[9].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[1], 18179,
                    "incorrect value for stec_sat_list[9].stec_coeff[1], expected 18179, is {}",
                    msg.stec_sat_list[9].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[2], 16371,
                    "incorrect value for stec_sat_list[9].stec_coeff[2], expected 16371, is {}",
                    msg.stec_sat_list[9].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[3], -5055,
                    "incorrect value for stec_sat_list[9].stec_coeff[3], expected -5055, is {}",
                    msg.stec_sat_list[9].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[9].stec_quality_indicator, 227, "incorrect value for stec_sat_list[9].stec_quality_indicator, expected 227, is {}", msg.stec_sat_list[9].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[9].sv_id.constellation, 36,
                    "incorrect value for stec_sat_list[9].sv_id.constellation, expected 36, is {}",
                    msg.stec_sat_list[9].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[9].sv_id.sat_id, 107,
                    "incorrect value for stec_sat_list[9].sv_id.sat_id, expected 107, is {}",
                    msg.stec_sat_list[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[0], 4009,
                    "incorrect value for stec_sat_list[10].stec_coeff[0], expected 4009, is {}",
                    msg.stec_sat_list[10].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[1], 1462,
                    "incorrect value for stec_sat_list[10].stec_coeff[1], expected 1462, is {}",
                    msg.stec_sat_list[10].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[2], -19216,
                    "incorrect value for stec_sat_list[10].stec_coeff[2], expected -19216, is {}",
                    msg.stec_sat_list[10].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[3], 31241,
                    "incorrect value for stec_sat_list[10].stec_coeff[3], expected 31241, is {}",
                    msg.stec_sat_list[10].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[10].stec_quality_indicator, 0, "incorrect value for stec_sat_list[10].stec_quality_indicator, expected 0, is {}", msg.stec_sat_list[10].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[10].sv_id.constellation, 77,
                    "incorrect value for stec_sat_list[10].sv_id.constellation, expected 77, is {}",
                    msg.stec_sat_list[10].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[10].sv_id.sat_id, 92,
                    "incorrect value for stec_sat_list[10].sv_id.sat_id, expected 92, is {}",
                    msg.stec_sat_list[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[0], 26727,
                    "incorrect value for stec_sat_list[11].stec_coeff[0], expected 26727, is {}",
                    msg.stec_sat_list[11].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[1], -16898,
                    "incorrect value for stec_sat_list[11].stec_coeff[1], expected -16898, is {}",
                    msg.stec_sat_list[11].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[2], 28241,
                    "incorrect value for stec_sat_list[11].stec_coeff[2], expected 28241, is {}",
                    msg.stec_sat_list[11].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[3], 12546,
                    "incorrect value for stec_sat_list[11].stec_coeff[3], expected 12546, is {}",
                    msg.stec_sat_list[11].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[11].stec_quality_indicator, 6, "incorrect value for stec_sat_list[11].stec_quality_indicator, expected 6, is {}", msg.stec_sat_list[11].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[11].sv_id.constellation, 232, "incorrect value for stec_sat_list[11].sv_id.constellation, expected 232, is {}", msg.stec_sat_list[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[11].sv_id.sat_id, 86,
                    "incorrect value for stec_sat_list[11].sv_id.sat_id, expected 86, is {}",
                    msg.stec_sat_list[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[0], 12855,
                    "incorrect value for stec_sat_list[12].stec_coeff[0], expected 12855, is {}",
                    msg.stec_sat_list[12].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[1], 1461,
                    "incorrect value for stec_sat_list[12].stec_coeff[1], expected 1461, is {}",
                    msg.stec_sat_list[12].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[2], 20603,
                    "incorrect value for stec_sat_list[12].stec_coeff[2], expected 20603, is {}",
                    msg.stec_sat_list[12].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[3], -3023,
                    "incorrect value for stec_sat_list[12].stec_coeff[3], expected -3023, is {}",
                    msg.stec_sat_list[12].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[12].stec_quality_indicator, 216, "incorrect value for stec_sat_list[12].stec_quality_indicator, expected 216, is {}", msg.stec_sat_list[12].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[12].sv_id.constellation, 84,
                    "incorrect value for stec_sat_list[12].sv_id.constellation, expected 84, is {}",
                    msg.stec_sat_list[12].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[12].sv_id.sat_id, 202,
                    "incorrect value for stec_sat_list[12].sv_id.sat_id, expected 202, is {}",
                    msg.stec_sat_list[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[0], -6492,
                    "incorrect value for stec_sat_list[13].stec_coeff[0], expected -6492, is {}",
                    msg.stec_sat_list[13].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[1], 16952,
                    "incorrect value for stec_sat_list[13].stec_coeff[1], expected 16952, is {}",
                    msg.stec_sat_list[13].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[2], -22404,
                    "incorrect value for stec_sat_list[13].stec_coeff[2], expected -22404, is {}",
                    msg.stec_sat_list[13].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[3], -29893,
                    "incorrect value for stec_sat_list[13].stec_coeff[3], expected -29893, is {}",
                    msg.stec_sat_list[13].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[13].stec_quality_indicator, 125, "incorrect value for stec_sat_list[13].stec_quality_indicator, expected 125, is {}", msg.stec_sat_list[13].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[13].sv_id.constellation, 188, "incorrect value for stec_sat_list[13].sv_id.constellation, expected 188, is {}", msg.stec_sat_list[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[13].sv_id.sat_id, 224,
                    "incorrect value for stec_sat_list[13].sv_id.sat_id, expected 224, is {}",
                    msg.stec_sat_list[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[0], -10053,
                    "incorrect value for stec_sat_list[14].stec_coeff[0], expected -10053, is {}",
                    msg.stec_sat_list[14].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[1], -24897,
                    "incorrect value for stec_sat_list[14].stec_coeff[1], expected -24897, is {}",
                    msg.stec_sat_list[14].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[2], 23629,
                    "incorrect value for stec_sat_list[14].stec_coeff[2], expected 23629, is {}",
                    msg.stec_sat_list[14].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[3], -710,
                    "incorrect value for stec_sat_list[14].stec_coeff[3], expected -710, is {}",
                    msg.stec_sat_list[14].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[14].stec_quality_indicator, 51, "incorrect value for stec_sat_list[14].stec_quality_indicator, expected 51, is {}", msg.stec_sat_list[14].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[14].sv_id.constellation, 118, "incorrect value for stec_sat_list[14].sv_id.constellation, expected 118, is {}", msg.stec_sat_list[14].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[14].sv_id.sat_id, 106,
                    "incorrect value for stec_sat_list[14].sv_id.sat_id, expected 106, is {}",
                    msg.stec_sat_list[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[0], -26103,
                    "incorrect value for stec_sat_list[15].stec_coeff[0], expected -26103, is {}",
                    msg.stec_sat_list[15].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[1], -9539,
                    "incorrect value for stec_sat_list[15].stec_coeff[1], expected -9539, is {}",
                    msg.stec_sat_list[15].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[2], -11971,
                    "incorrect value for stec_sat_list[15].stec_coeff[2], expected -11971, is {}",
                    msg.stec_sat_list[15].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[3], 20993,
                    "incorrect value for stec_sat_list[15].stec_coeff[3], expected 20993, is {}",
                    msg.stec_sat_list[15].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[15].stec_quality_indicator, 165, "incorrect value for stec_sat_list[15].stec_quality_indicator, expected 165, is {}", msg.stec_sat_list[15].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[15].sv_id.constellation, 150, "incorrect value for stec_sat_list[15].sv_id.constellation, expected 150, is {}", msg.stec_sat_list[15].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[15].sv_id.sat_id, 132,
                    "incorrect value for stec_sat_list[15].sv_id.sat_id, expected 132, is {}",
                    msg.stec_sat_list[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[0], -18891,
                    "incorrect value for stec_sat_list[16].stec_coeff[0], expected -18891, is {}",
                    msg.stec_sat_list[16].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[1], -16272,
                    "incorrect value for stec_sat_list[16].stec_coeff[1], expected -16272, is {}",
                    msg.stec_sat_list[16].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[2], -22578,
                    "incorrect value for stec_sat_list[16].stec_coeff[2], expected -22578, is {}",
                    msg.stec_sat_list[16].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[3], -2915,
                    "incorrect value for stec_sat_list[16].stec_coeff[3], expected -2915, is {}",
                    msg.stec_sat_list[16].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[16].stec_quality_indicator, 23, "incorrect value for stec_sat_list[16].stec_quality_indicator, expected 23, is {}", msg.stec_sat_list[16].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[16].sv_id.constellation, 196, "incorrect value for stec_sat_list[16].sv_id.constellation, expected 196, is {}", msg.stec_sat_list[16].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[16].sv_id.sat_id, 181,
                    "incorrect value for stec_sat_list[16].sv_id.sat_id, expected 181, is {}",
                    msg.stec_sat_list[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[0], 15833,
                    "incorrect value for stec_sat_list[17].stec_coeff[0], expected 15833, is {}",
                    msg.stec_sat_list[17].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[1], 24920,
                    "incorrect value for stec_sat_list[17].stec_coeff[1], expected 24920, is {}",
                    msg.stec_sat_list[17].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[2], -13879,
                    "incorrect value for stec_sat_list[17].stec_coeff[2], expected -13879, is {}",
                    msg.stec_sat_list[17].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[3], -1206,
                    "incorrect value for stec_sat_list[17].stec_coeff[3], expected -1206, is {}",
                    msg.stec_sat_list[17].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[17].stec_quality_indicator, 189, "incorrect value for stec_sat_list[17].stec_quality_indicator, expected 189, is {}", msg.stec_sat_list[17].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[17].sv_id.constellation, 1,
                    "incorrect value for stec_sat_list[17].sv_id.constellation, expected 1, is {}",
                    msg.stec_sat_list[17].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[17].sv_id.sat_id, 35,
                    "incorrect value for stec_sat_list[17].sv_id.sat_id, expected 35, is {}",
                    msg.stec_sat_list[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[0], 14008,
                    "incorrect value for stec_sat_list[18].stec_coeff[0], expected 14008, is {}",
                    msg.stec_sat_list[18].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[1], 18996,
                    "incorrect value for stec_sat_list[18].stec_coeff[1], expected 18996, is {}",
                    msg.stec_sat_list[18].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[2], 2798,
                    "incorrect value for stec_sat_list[18].stec_coeff[2], expected 2798, is {}",
                    msg.stec_sat_list[18].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[3], 5761,
                    "incorrect value for stec_sat_list[18].stec_coeff[3], expected 5761, is {}",
                    msg.stec_sat_list[18].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[18].stec_quality_indicator, 104, "incorrect value for stec_sat_list[18].stec_quality_indicator, expected 104, is {}", msg.stec_sat_list[18].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[18].sv_id.constellation, 14,
                    "incorrect value for stec_sat_list[18].sv_id.constellation, expected 14, is {}",
                    msg.stec_sat_list[18].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[18].sv_id.sat_id, 217,
                    "incorrect value for stec_sat_list[18].sv_id.sat_id, expected 217, is {}",
                    msg.stec_sat_list[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[0], -25256,
                    "incorrect value for stec_sat_list[19].stec_coeff[0], expected -25256, is {}",
                    msg.stec_sat_list[19].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[1], -15330,
                    "incorrect value for stec_sat_list[19].stec_coeff[1], expected -15330, is {}",
                    msg.stec_sat_list[19].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[2], 6831,
                    "incorrect value for stec_sat_list[19].stec_coeff[2], expected 6831, is {}",
                    msg.stec_sat_list[19].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[3], 8780,
                    "incorrect value for stec_sat_list[19].stec_coeff[3], expected 8780, is {}",
                    msg.stec_sat_list[19].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[19].stec_quality_indicator, 109, "incorrect value for stec_sat_list[19].stec_quality_indicator, expected 109, is {}", msg.stec_sat_list[19].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[19].sv_id.constellation, 226, "incorrect value for stec_sat_list[19].sv_id.constellation, expected 226, is {}", msg.stec_sat_list[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[19].sv_id.sat_id, 178,
                    "incorrect value for stec_sat_list[19].sv_id.sat_id, expected 178, is {}",
                    msg.stec_sat_list[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[0], 3304,
                    "incorrect value for stec_sat_list[20].stec_coeff[0], expected 3304, is {}",
                    msg.stec_sat_list[20].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[1], -2893,
                    "incorrect value for stec_sat_list[20].stec_coeff[1], expected -2893, is {}",
                    msg.stec_sat_list[20].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[2], -25841,
                    "incorrect value for stec_sat_list[20].stec_coeff[2], expected -25841, is {}",
                    msg.stec_sat_list[20].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[3], -13628,
                    "incorrect value for stec_sat_list[20].stec_coeff[3], expected -13628, is {}",
                    msg.stec_sat_list[20].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[20].stec_quality_indicator, 154, "incorrect value for stec_sat_list[20].stec_quality_indicator, expected 154, is {}", msg.stec_sat_list[20].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[20].sv_id.constellation, 220, "incorrect value for stec_sat_list[20].sv_id.constellation, expected 220, is {}", msg.stec_sat_list[20].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[20].sv_id.sat_id, 116,
                    "incorrect value for stec_sat_list[20].sv_id.sat_id, expected 116, is {}",
                    msg.stec_sat_list[20].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[21].stec_coeff[0], -10742,
                    "incorrect value for stec_sat_list[21].stec_coeff[0], expected -10742, is {}",
                    msg.stec_sat_list[21].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[21].stec_coeff[1], 10098,
                    "incorrect value for stec_sat_list[21].stec_coeff[1], expected 10098, is {}",
                    msg.stec_sat_list[21].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[21].stec_coeff[2], 7413,
                    "incorrect value for stec_sat_list[21].stec_coeff[2], expected 7413, is {}",
                    msg.stec_sat_list[21].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[21].stec_coeff[3], 17645,
                    "incorrect value for stec_sat_list[21].stec_coeff[3], expected 17645, is {}",
                    msg.stec_sat_list[21].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[21].stec_quality_indicator, 115, "incorrect value for stec_sat_list[21].stec_quality_indicator, expected 115, is {}", msg.stec_sat_list[21].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[21].sv_id.constellation, 70,
                    "incorrect value for stec_sat_list[21].sv_id.constellation, expected 70, is {}",
                    msg.stec_sat_list[21].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[21].sv_id.sat_id, 72,
                    "incorrect value for stec_sat_list[21].sv_id.sat_id, expected 72, is {}",
                    msg.stec_sat_list[21].sv_id.sat_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrStecCorrectionDepA"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_stec_correction_dep_a() {
    {
        let json_input = r#"{"crc":39816,"length":252,"msg_type":1515,"payload":"RlHE6Lkrk3snBH4Tb2H4gtnZajoMQearUV9WECdU5NDJUdtjyz22Qn3LA8EsZNx9PBVd2veez12Bhg7RMA7XmZSTSOG07M3JIQP2zBMDYgTCv/ZM2x+/cU+xD/shE2A2OpLSZPlIFaHTxhXub2sk4+HVA0fzP0HsXE0AqQ+2BfC0CXpW6AZnaP69UW4CMcpU2DcytQV7UDH04Lx9pOY4QnyoO4tqdjO72L+eTVw6/YSWpQmavdo90QFStcQXNbZwwM6nnfQjAb3ZPVhhyclK+9kOaLg2NEruCoEWsuJtWJ0exK8aTCJ03JroDLP0D5vEykhGcwrWcif1HO1E","preamble":85,"sender":1831,"header":{"time":{"tow":3905179974,"wn":11193},"num_msgs":147,"seq_num":123,"update_interval":39,"iod_atmo":4},"stec_sat_list":[{"sv_id":{"satId":126,"constellation":19},"stec_quality_indicator":111,"stec_coeff":[-1951,-9854,27353,3130]},{"sv_id":{"satId":65,"constellation":230},"stec_quality_indicator":171,"stec_coeff":[24401,4182,21543,-12060]},{"sv_id":{"satId":201,"constellation":81},"stec_quality_indicator":219,"stec_coeff":[-13469,-18883,32066,971]},{"sv_id":{"satId":193,"constellation":44},"stec_quality_indicator":100,"stec_coeff":[32220,5436,-9635,-24841]},{"sv_id":{"satId":207,"constellation":93},"stec_quality_indicator":129,"stec_coeff":[3718,12497,-10482,-27495]},{"sv_id":{"satId":147,"constellation":72},"stec_quality_indicator":225,"stec_coeff":[-4940,-13875,801,-13066]},{"sv_id":{"satId":19,"constellation":3},"stec_quality_indicator":98,"stec_coeff":[-15868,-2369,-9396,-16609]},{"sv_id":{"satId":113,"constellation":79},"stec_quality_indicator":177,"stec_coeff":[-1265,4897,13920,-28102]},{"sv_id":{"satId":210,"constellation":100},"stec_quality_indicator":249,"stec_coeff":[5448,-11359,5574,28654]},{"sv_id":{"satId":107,"constellation":36},"stec_quality_indicator":227,"stec_coeff":[-10783,18179,16371,-5055]},{"sv_id":{"satId":92,"constellation":77},"stec_quality_indicator":0,"stec_coeff":[4009,1462,-19216,31241]},{"sv_id":{"satId":86,"constellation":232},"stec_quality_indicator":6,"stec_coeff":[26727,-16898,28241,12546]},{"sv_id":{"satId":202,"constellation":84},"stec_quality_indicator":216,"stec_coeff":[12855,1461,20603,-3023]},{"sv_id":{"satId":224,"constellation":188},"stec_quality_indicator":125,"stec_coeff":[-6492,16952,-22404,-29893]},{"sv_id":{"satId":106,"constellation":118},"stec_quality_indicator":51,"stec_coeff":[-10053,-24897,23629,-710]},{"sv_id":{"satId":132,"constellation":150},"stec_quality_indicator":165,"stec_coeff":[-26103,-9539,-11971,20993]},{"sv_id":{"satId":181,"constellation":196},"stec_quality_indicator":23,"stec_coeff":[-18891,-16272,-22578,-2915]},{"sv_id":{"satId":35,"constellation":1},"stec_quality_indicator":189,"stec_coeff":[15833,24920,-13879,-1206]},{"sv_id":{"satId":217,"constellation":14},"stec_quality_indicator":104,"stec_coeff":[14008,18996,2798,5761]},{"sv_id":{"satId":178,"constellation":226},"stec_quality_indicator":109,"stec_coeff":[-25256,-15330,6831,8780]},{"sv_id":{"satId":116,"constellation":220},"stec_quality_indicator":154,"stec_coeff":[3304,-2893,-25841,-13628]},{"sv_id":{"satId":72,"constellation":70},"stec_quality_indicator":115,"stec_coeff":[-10742,10098,7413,17645]}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrStecCorrectionDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5eb,
                    "Incorrect message type, expected 0x5eb, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0727,
                    "incorrect sender id, expected 0x0727, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 4,
                    "incorrect value for header.iod_atmo, expected 4, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 147,
                    "incorrect value for header.num_msgs, expected 147, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 123,
                    "incorrect value for header.seq_num, expected 123, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.time.tow, 3905179974,
                    "incorrect value for header.time.tow, expected 3905179974, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 11193,
                    "incorrect value for header.time.wn, expected 11193, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.update_interval, 39,
                    "incorrect value for header.update_interval, expected 39, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[0], -1951,
                    "incorrect value for stec_sat_list[0].stec_coeff[0], expected -1951, is {}",
                    msg.stec_sat_list[0].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[1], -9854,
                    "incorrect value for stec_sat_list[0].stec_coeff[1], expected -9854, is {}",
                    msg.stec_sat_list[0].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[2], 27353,
                    "incorrect value for stec_sat_list[0].stec_coeff[2], expected 27353, is {}",
                    msg.stec_sat_list[0].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[3], 3130,
                    "incorrect value for stec_sat_list[0].stec_coeff[3], expected 3130, is {}",
                    msg.stec_sat_list[0].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[0].stec_quality_indicator, 111, "incorrect value for stec_sat_list[0].stec_quality_indicator, expected 111, is {}", msg.stec_sat_list[0].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.constellation, 19,
                    "incorrect value for stec_sat_list[0].sv_id.constellation, expected 19, is {}",
                    msg.stec_sat_list[0].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.sat_id, 126,
                    "incorrect value for stec_sat_list[0].sv_id.sat_id, expected 126, is {}",
                    msg.stec_sat_list[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[0], 24401,
                    "incorrect value for stec_sat_list[1].stec_coeff[0], expected 24401, is {}",
                    msg.stec_sat_list[1].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[1], 4182,
                    "incorrect value for stec_sat_list[1].stec_coeff[1], expected 4182, is {}",
                    msg.stec_sat_list[1].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[2], 21543,
                    "incorrect value for stec_sat_list[1].stec_coeff[2], expected 21543, is {}",
                    msg.stec_sat_list[1].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[3], -12060,
                    "incorrect value for stec_sat_list[1].stec_coeff[3], expected -12060, is {}",
                    msg.stec_sat_list[1].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[1].stec_quality_indicator, 171, "incorrect value for stec_sat_list[1].stec_quality_indicator, expected 171, is {}", msg.stec_sat_list[1].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.constellation, 230,
                    "incorrect value for stec_sat_list[1].sv_id.constellation, expected 230, is {}",
                    msg.stec_sat_list[1].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.sat_id, 65,
                    "incorrect value for stec_sat_list[1].sv_id.sat_id, expected 65, is {}",
                    msg.stec_sat_list[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[0], -13469,
                    "incorrect value for stec_sat_list[2].stec_coeff[0], expected -13469, is {}",
                    msg.stec_sat_list[2].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[1], -18883,
                    "incorrect value for stec_sat_list[2].stec_coeff[1], expected -18883, is {}",
                    msg.stec_sat_list[2].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[2], 32066,
                    "incorrect value for stec_sat_list[2].stec_coeff[2], expected 32066, is {}",
                    msg.stec_sat_list[2].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[3], 971,
                    "incorrect value for stec_sat_list[2].stec_coeff[3], expected 971, is {}",
                    msg.stec_sat_list[2].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[2].stec_quality_indicator, 219, "incorrect value for stec_sat_list[2].stec_quality_indicator, expected 219, is {}", msg.stec_sat_list[2].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[2].sv_id.constellation, 81,
                    "incorrect value for stec_sat_list[2].sv_id.constellation, expected 81, is {}",
                    msg.stec_sat_list[2].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[2].sv_id.sat_id, 201,
                    "incorrect value for stec_sat_list[2].sv_id.sat_id, expected 201, is {}",
                    msg.stec_sat_list[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[0], 32220,
                    "incorrect value for stec_sat_list[3].stec_coeff[0], expected 32220, is {}",
                    msg.stec_sat_list[3].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[1], 5436,
                    "incorrect value for stec_sat_list[3].stec_coeff[1], expected 5436, is {}",
                    msg.stec_sat_list[3].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[2], -9635,
                    "incorrect value for stec_sat_list[3].stec_coeff[2], expected -9635, is {}",
                    msg.stec_sat_list[3].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[3], -24841,
                    "incorrect value for stec_sat_list[3].stec_coeff[3], expected -24841, is {}",
                    msg.stec_sat_list[3].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[3].stec_quality_indicator, 100, "incorrect value for stec_sat_list[3].stec_quality_indicator, expected 100, is {}", msg.stec_sat_list[3].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[3].sv_id.constellation, 44,
                    "incorrect value for stec_sat_list[3].sv_id.constellation, expected 44, is {}",
                    msg.stec_sat_list[3].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[3].sv_id.sat_id, 193,
                    "incorrect value for stec_sat_list[3].sv_id.sat_id, expected 193, is {}",
                    msg.stec_sat_list[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[0], 3718,
                    "incorrect value for stec_sat_list[4].stec_coeff[0], expected 3718, is {}",
                    msg.stec_sat_list[4].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[1], 12497,
                    "incorrect value for stec_sat_list[4].stec_coeff[1], expected 12497, is {}",
                    msg.stec_sat_list[4].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[2], -10482,
                    "incorrect value for stec_sat_list[4].stec_coeff[2], expected -10482, is {}",
                    msg.stec_sat_list[4].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[3], -27495,
                    "incorrect value for stec_sat_list[4].stec_coeff[3], expected -27495, is {}",
                    msg.stec_sat_list[4].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[4].stec_quality_indicator, 129, "incorrect value for stec_sat_list[4].stec_quality_indicator, expected 129, is {}", msg.stec_sat_list[4].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[4].sv_id.constellation, 93,
                    "incorrect value for stec_sat_list[4].sv_id.constellation, expected 93, is {}",
                    msg.stec_sat_list[4].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[4].sv_id.sat_id, 207,
                    "incorrect value for stec_sat_list[4].sv_id.sat_id, expected 207, is {}",
                    msg.stec_sat_list[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[0], -4940,
                    "incorrect value for stec_sat_list[5].stec_coeff[0], expected -4940, is {}",
                    msg.stec_sat_list[5].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[1], -13875,
                    "incorrect value for stec_sat_list[5].stec_coeff[1], expected -13875, is {}",
                    msg.stec_sat_list[5].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[2], 801,
                    "incorrect value for stec_sat_list[5].stec_coeff[2], expected 801, is {}",
                    msg.stec_sat_list[5].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[3], -13066,
                    "incorrect value for stec_sat_list[5].stec_coeff[3], expected -13066, is {}",
                    msg.stec_sat_list[5].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[5].stec_quality_indicator, 225, "incorrect value for stec_sat_list[5].stec_quality_indicator, expected 225, is {}", msg.stec_sat_list[5].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[5].sv_id.constellation, 72,
                    "incorrect value for stec_sat_list[5].sv_id.constellation, expected 72, is {}",
                    msg.stec_sat_list[5].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[5].sv_id.sat_id, 147,
                    "incorrect value for stec_sat_list[5].sv_id.sat_id, expected 147, is {}",
                    msg.stec_sat_list[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[0], -15868,
                    "incorrect value for stec_sat_list[6].stec_coeff[0], expected -15868, is {}",
                    msg.stec_sat_list[6].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[1], -2369,
                    "incorrect value for stec_sat_list[6].stec_coeff[1], expected -2369, is {}",
                    msg.stec_sat_list[6].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[2], -9396,
                    "incorrect value for stec_sat_list[6].stec_coeff[2], expected -9396, is {}",
                    msg.stec_sat_list[6].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[3], -16609,
                    "incorrect value for stec_sat_list[6].stec_coeff[3], expected -16609, is {}",
                    msg.stec_sat_list[6].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[6].stec_quality_indicator, 98, "incorrect value for stec_sat_list[6].stec_quality_indicator, expected 98, is {}", msg.stec_sat_list[6].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[6].sv_id.constellation, 3,
                    "incorrect value for stec_sat_list[6].sv_id.constellation, expected 3, is {}",
                    msg.stec_sat_list[6].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[6].sv_id.sat_id, 19,
                    "incorrect value for stec_sat_list[6].sv_id.sat_id, expected 19, is {}",
                    msg.stec_sat_list[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[0], -1265,
                    "incorrect value for stec_sat_list[7].stec_coeff[0], expected -1265, is {}",
                    msg.stec_sat_list[7].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[1], 4897,
                    "incorrect value for stec_sat_list[7].stec_coeff[1], expected 4897, is {}",
                    msg.stec_sat_list[7].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[2], 13920,
                    "incorrect value for stec_sat_list[7].stec_coeff[2], expected 13920, is {}",
                    msg.stec_sat_list[7].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[3], -28102,
                    "incorrect value for stec_sat_list[7].stec_coeff[3], expected -28102, is {}",
                    msg.stec_sat_list[7].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[7].stec_quality_indicator, 177, "incorrect value for stec_sat_list[7].stec_quality_indicator, expected 177, is {}", msg.stec_sat_list[7].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[7].sv_id.constellation, 79,
                    "incorrect value for stec_sat_list[7].sv_id.constellation, expected 79, is {}",
                    msg.stec_sat_list[7].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[7].sv_id.sat_id, 113,
                    "incorrect value for stec_sat_list[7].sv_id.sat_id, expected 113, is {}",
                    msg.stec_sat_list[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[0], 5448,
                    "incorrect value for stec_sat_list[8].stec_coeff[0], expected 5448, is {}",
                    msg.stec_sat_list[8].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[1], -11359,
                    "incorrect value for stec_sat_list[8].stec_coeff[1], expected -11359, is {}",
                    msg.stec_sat_list[8].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[2], 5574,
                    "incorrect value for stec_sat_list[8].stec_coeff[2], expected 5574, is {}",
                    msg.stec_sat_list[8].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[3], 28654,
                    "incorrect value for stec_sat_list[8].stec_coeff[3], expected 28654, is {}",
                    msg.stec_sat_list[8].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[8].stec_quality_indicator, 249, "incorrect value for stec_sat_list[8].stec_quality_indicator, expected 249, is {}", msg.stec_sat_list[8].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[8].sv_id.constellation, 100,
                    "incorrect value for stec_sat_list[8].sv_id.constellation, expected 100, is {}",
                    msg.stec_sat_list[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[8].sv_id.sat_id, 210,
                    "incorrect value for stec_sat_list[8].sv_id.sat_id, expected 210, is {}",
                    msg.stec_sat_list[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[0], -10783,
                    "incorrect value for stec_sat_list[9].stec_coeff[0], expected -10783, is {}",
                    msg.stec_sat_list[9].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[1], 18179,
                    "incorrect value for stec_sat_list[9].stec_coeff[1], expected 18179, is {}",
                    msg.stec_sat_list[9].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[2], 16371,
                    "incorrect value for stec_sat_list[9].stec_coeff[2], expected 16371, is {}",
                    msg.stec_sat_list[9].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[3], -5055,
                    "incorrect value for stec_sat_list[9].stec_coeff[3], expected -5055, is {}",
                    msg.stec_sat_list[9].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[9].stec_quality_indicator, 227, "incorrect value for stec_sat_list[9].stec_quality_indicator, expected 227, is {}", msg.stec_sat_list[9].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[9].sv_id.constellation, 36,
                    "incorrect value for stec_sat_list[9].sv_id.constellation, expected 36, is {}",
                    msg.stec_sat_list[9].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[9].sv_id.sat_id, 107,
                    "incorrect value for stec_sat_list[9].sv_id.sat_id, expected 107, is {}",
                    msg.stec_sat_list[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[0], 4009,
                    "incorrect value for stec_sat_list[10].stec_coeff[0], expected 4009, is {}",
                    msg.stec_sat_list[10].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[1], 1462,
                    "incorrect value for stec_sat_list[10].stec_coeff[1], expected 1462, is {}",
                    msg.stec_sat_list[10].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[2], -19216,
                    "incorrect value for stec_sat_list[10].stec_coeff[2], expected -19216, is {}",
                    msg.stec_sat_list[10].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[3], 31241,
                    "incorrect value for stec_sat_list[10].stec_coeff[3], expected 31241, is {}",
                    msg.stec_sat_list[10].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[10].stec_quality_indicator, 0, "incorrect value for stec_sat_list[10].stec_quality_indicator, expected 0, is {}", msg.stec_sat_list[10].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[10].sv_id.constellation, 77,
                    "incorrect value for stec_sat_list[10].sv_id.constellation, expected 77, is {}",
                    msg.stec_sat_list[10].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[10].sv_id.sat_id, 92,
                    "incorrect value for stec_sat_list[10].sv_id.sat_id, expected 92, is {}",
                    msg.stec_sat_list[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[0], 26727,
                    "incorrect value for stec_sat_list[11].stec_coeff[0], expected 26727, is {}",
                    msg.stec_sat_list[11].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[1], -16898,
                    "incorrect value for stec_sat_list[11].stec_coeff[1], expected -16898, is {}",
                    msg.stec_sat_list[11].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[2], 28241,
                    "incorrect value for stec_sat_list[11].stec_coeff[2], expected 28241, is {}",
                    msg.stec_sat_list[11].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[3], 12546,
                    "incorrect value for stec_sat_list[11].stec_coeff[3], expected 12546, is {}",
                    msg.stec_sat_list[11].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[11].stec_quality_indicator, 6, "incorrect value for stec_sat_list[11].stec_quality_indicator, expected 6, is {}", msg.stec_sat_list[11].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[11].sv_id.constellation, 232, "incorrect value for stec_sat_list[11].sv_id.constellation, expected 232, is {}", msg.stec_sat_list[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[11].sv_id.sat_id, 86,
                    "incorrect value for stec_sat_list[11].sv_id.sat_id, expected 86, is {}",
                    msg.stec_sat_list[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[0], 12855,
                    "incorrect value for stec_sat_list[12].stec_coeff[0], expected 12855, is {}",
                    msg.stec_sat_list[12].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[1], 1461,
                    "incorrect value for stec_sat_list[12].stec_coeff[1], expected 1461, is {}",
                    msg.stec_sat_list[12].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[2], 20603,
                    "incorrect value for stec_sat_list[12].stec_coeff[2], expected 20603, is {}",
                    msg.stec_sat_list[12].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[3], -3023,
                    "incorrect value for stec_sat_list[12].stec_coeff[3], expected -3023, is {}",
                    msg.stec_sat_list[12].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[12].stec_quality_indicator, 216, "incorrect value for stec_sat_list[12].stec_quality_indicator, expected 216, is {}", msg.stec_sat_list[12].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[12].sv_id.constellation, 84,
                    "incorrect value for stec_sat_list[12].sv_id.constellation, expected 84, is {}",
                    msg.stec_sat_list[12].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[12].sv_id.sat_id, 202,
                    "incorrect value for stec_sat_list[12].sv_id.sat_id, expected 202, is {}",
                    msg.stec_sat_list[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[0], -6492,
                    "incorrect value for stec_sat_list[13].stec_coeff[0], expected -6492, is {}",
                    msg.stec_sat_list[13].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[1], 16952,
                    "incorrect value for stec_sat_list[13].stec_coeff[1], expected 16952, is {}",
                    msg.stec_sat_list[13].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[2], -22404,
                    "incorrect value for stec_sat_list[13].stec_coeff[2], expected -22404, is {}",
                    msg.stec_sat_list[13].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[3], -29893,
                    "incorrect value for stec_sat_list[13].stec_coeff[3], expected -29893, is {}",
                    msg.stec_sat_list[13].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[13].stec_quality_indicator, 125, "incorrect value for stec_sat_list[13].stec_quality_indicator, expected 125, is {}", msg.stec_sat_list[13].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[13].sv_id.constellation, 188, "incorrect value for stec_sat_list[13].sv_id.constellation, expected 188, is {}", msg.stec_sat_list[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[13].sv_id.sat_id, 224,
                    "incorrect value for stec_sat_list[13].sv_id.sat_id, expected 224, is {}",
                    msg.stec_sat_list[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[0], -10053,
                    "incorrect value for stec_sat_list[14].stec_coeff[0], expected -10053, is {}",
                    msg.stec_sat_list[14].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[1], -24897,
                    "incorrect value for stec_sat_list[14].stec_coeff[1], expected -24897, is {}",
                    msg.stec_sat_list[14].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[2], 23629,
                    "incorrect value for stec_sat_list[14].stec_coeff[2], expected 23629, is {}",
                    msg.stec_sat_list[14].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[3], -710,
                    "incorrect value for stec_sat_list[14].stec_coeff[3], expected -710, is {}",
                    msg.stec_sat_list[14].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[14].stec_quality_indicator, 51, "incorrect value for stec_sat_list[14].stec_quality_indicator, expected 51, is {}", msg.stec_sat_list[14].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[14].sv_id.constellation, 118, "incorrect value for stec_sat_list[14].sv_id.constellation, expected 118, is {}", msg.stec_sat_list[14].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[14].sv_id.sat_id, 106,
                    "incorrect value for stec_sat_list[14].sv_id.sat_id, expected 106, is {}",
                    msg.stec_sat_list[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[0], -26103,
                    "incorrect value for stec_sat_list[15].stec_coeff[0], expected -26103, is {}",
                    msg.stec_sat_list[15].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[1], -9539,
                    "incorrect value for stec_sat_list[15].stec_coeff[1], expected -9539, is {}",
                    msg.stec_sat_list[15].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[2], -11971,
                    "incorrect value for stec_sat_list[15].stec_coeff[2], expected -11971, is {}",
                    msg.stec_sat_list[15].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[3], 20993,
                    "incorrect value for stec_sat_list[15].stec_coeff[3], expected 20993, is {}",
                    msg.stec_sat_list[15].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[15].stec_quality_indicator, 165, "incorrect value for stec_sat_list[15].stec_quality_indicator, expected 165, is {}", msg.stec_sat_list[15].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[15].sv_id.constellation, 150, "incorrect value for stec_sat_list[15].sv_id.constellation, expected 150, is {}", msg.stec_sat_list[15].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[15].sv_id.sat_id, 132,
                    "incorrect value for stec_sat_list[15].sv_id.sat_id, expected 132, is {}",
                    msg.stec_sat_list[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[0], -18891,
                    "incorrect value for stec_sat_list[16].stec_coeff[0], expected -18891, is {}",
                    msg.stec_sat_list[16].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[1], -16272,
                    "incorrect value for stec_sat_list[16].stec_coeff[1], expected -16272, is {}",
                    msg.stec_sat_list[16].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[2], -22578,
                    "incorrect value for stec_sat_list[16].stec_coeff[2], expected -22578, is {}",
                    msg.stec_sat_list[16].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[3], -2915,
                    "incorrect value for stec_sat_list[16].stec_coeff[3], expected -2915, is {}",
                    msg.stec_sat_list[16].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[16].stec_quality_indicator, 23, "incorrect value for stec_sat_list[16].stec_quality_indicator, expected 23, is {}", msg.stec_sat_list[16].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[16].sv_id.constellation, 196, "incorrect value for stec_sat_list[16].sv_id.constellation, expected 196, is {}", msg.stec_sat_list[16].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[16].sv_id.sat_id, 181,
                    "incorrect value for stec_sat_list[16].sv_id.sat_id, expected 181, is {}",
                    msg.stec_sat_list[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[0], 15833,
                    "incorrect value for stec_sat_list[17].stec_coeff[0], expected 15833, is {}",
                    msg.stec_sat_list[17].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[1], 24920,
                    "incorrect value for stec_sat_list[17].stec_coeff[1], expected 24920, is {}",
                    msg.stec_sat_list[17].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[2], -13879,
                    "incorrect value for stec_sat_list[17].stec_coeff[2], expected -13879, is {}",
                    msg.stec_sat_list[17].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[3], -1206,
                    "incorrect value for stec_sat_list[17].stec_coeff[3], expected -1206, is {}",
                    msg.stec_sat_list[17].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[17].stec_quality_indicator, 189, "incorrect value for stec_sat_list[17].stec_quality_indicator, expected 189, is {}", msg.stec_sat_list[17].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[17].sv_id.constellation, 1,
                    "incorrect value for stec_sat_list[17].sv_id.constellation, expected 1, is {}",
                    msg.stec_sat_list[17].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[17].sv_id.sat_id, 35,
                    "incorrect value for stec_sat_list[17].sv_id.sat_id, expected 35, is {}",
                    msg.stec_sat_list[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[0], 14008,
                    "incorrect value for stec_sat_list[18].stec_coeff[0], expected 14008, is {}",
                    msg.stec_sat_list[18].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[1], 18996,
                    "incorrect value for stec_sat_list[18].stec_coeff[1], expected 18996, is {}",
                    msg.stec_sat_list[18].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[2], 2798,
                    "incorrect value for stec_sat_list[18].stec_coeff[2], expected 2798, is {}",
                    msg.stec_sat_list[18].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[3], 5761,
                    "incorrect value for stec_sat_list[18].stec_coeff[3], expected 5761, is {}",
                    msg.stec_sat_list[18].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[18].stec_quality_indicator, 104, "incorrect value for stec_sat_list[18].stec_quality_indicator, expected 104, is {}", msg.stec_sat_list[18].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[18].sv_id.constellation, 14,
                    "incorrect value for stec_sat_list[18].sv_id.constellation, expected 14, is {}",
                    msg.stec_sat_list[18].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[18].sv_id.sat_id, 217,
                    "incorrect value for stec_sat_list[18].sv_id.sat_id, expected 217, is {}",
                    msg.stec_sat_list[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[0], -25256,
                    "incorrect value for stec_sat_list[19].stec_coeff[0], expected -25256, is {}",
                    msg.stec_sat_list[19].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[1], -15330,
                    "incorrect value for stec_sat_list[19].stec_coeff[1], expected -15330, is {}",
                    msg.stec_sat_list[19].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[2], 6831,
                    "incorrect value for stec_sat_list[19].stec_coeff[2], expected 6831, is {}",
                    msg.stec_sat_list[19].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[3], 8780,
                    "incorrect value for stec_sat_list[19].stec_coeff[3], expected 8780, is {}",
                    msg.stec_sat_list[19].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[19].stec_quality_indicator, 109, "incorrect value for stec_sat_list[19].stec_quality_indicator, expected 109, is {}", msg.stec_sat_list[19].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[19].sv_id.constellation, 226, "incorrect value for stec_sat_list[19].sv_id.constellation, expected 226, is {}", msg.stec_sat_list[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[19].sv_id.sat_id, 178,
                    "incorrect value for stec_sat_list[19].sv_id.sat_id, expected 178, is {}",
                    msg.stec_sat_list[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[0], 3304,
                    "incorrect value for stec_sat_list[20].stec_coeff[0], expected 3304, is {}",
                    msg.stec_sat_list[20].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[1], -2893,
                    "incorrect value for stec_sat_list[20].stec_coeff[1], expected -2893, is {}",
                    msg.stec_sat_list[20].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[2], -25841,
                    "incorrect value for stec_sat_list[20].stec_coeff[2], expected -25841, is {}",
                    msg.stec_sat_list[20].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[3], -13628,
                    "incorrect value for stec_sat_list[20].stec_coeff[3], expected -13628, is {}",
                    msg.stec_sat_list[20].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[20].stec_quality_indicator, 154, "incorrect value for stec_sat_list[20].stec_quality_indicator, expected 154, is {}", msg.stec_sat_list[20].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[20].sv_id.constellation, 220, "incorrect value for stec_sat_list[20].sv_id.constellation, expected 220, is {}", msg.stec_sat_list[20].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[20].sv_id.sat_id, 116,
                    "incorrect value for stec_sat_list[20].sv_id.sat_id, expected 116, is {}",
                    msg.stec_sat_list[20].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[21].stec_coeff[0], -10742,
                    "incorrect value for stec_sat_list[21].stec_coeff[0], expected -10742, is {}",
                    msg.stec_sat_list[21].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[21].stec_coeff[1], 10098,
                    "incorrect value for stec_sat_list[21].stec_coeff[1], expected 10098, is {}",
                    msg.stec_sat_list[21].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[21].stec_coeff[2], 7413,
                    "incorrect value for stec_sat_list[21].stec_coeff[2], expected 7413, is {}",
                    msg.stec_sat_list[21].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[21].stec_coeff[3], 17645,
                    "incorrect value for stec_sat_list[21].stec_coeff[3], expected 17645, is {}",
                    msg.stec_sat_list[21].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[21].stec_quality_indicator, 115, "incorrect value for stec_sat_list[21].stec_quality_indicator, expected 115, is {}", msg.stec_sat_list[21].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[21].sv_id.constellation, 70,
                    "incorrect value for stec_sat_list[21].sv_id.constellation, expected 70, is {}",
                    msg.stec_sat_list[21].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[21].sv_id.sat_id, 72,
                    "incorrect value for stec_sat_list[21].sv_id.sat_id, expected 72, is {}",
                    msg.stec_sat_list[21].sv_id.sat_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrStecCorrectionDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_stec_correction_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_stec_correction_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 235, 5, 39, 7, 252, 70, 81, 196, 232, 185, 43, 147, 123, 39, 4, 126, 19, 111, 97,
            248, 130, 217, 217, 106, 58, 12, 65, 230, 171, 81, 95, 86, 16, 39, 84, 228, 208, 201,
            81, 219, 99, 203, 61, 182, 66, 125, 203, 3, 193, 44, 100, 220, 125, 60, 21, 93, 218,
            247, 158, 207, 93, 129, 134, 14, 209, 48, 14, 215, 153, 148, 147, 72, 225, 180, 236,
            205, 201, 33, 3, 246, 204, 19, 3, 98, 4, 194, 191, 246, 76, 219, 31, 191, 113, 79, 177,
            15, 251, 33, 19, 96, 54, 58, 146, 210, 100, 249, 72, 21, 161, 211, 198, 21, 238, 111,
            107, 36, 227, 225, 213, 3, 71, 243, 63, 65, 236, 92, 77, 0, 169, 15, 182, 5, 240, 180,
            9, 122, 86, 232, 6, 103, 104, 254, 189, 81, 110, 2, 49, 202, 84, 216, 55, 50, 181, 5,
            123, 80, 49, 244, 224, 188, 125, 164, 230, 56, 66, 124, 168, 59, 139, 106, 118, 51,
            187, 216, 191, 158, 77, 92, 58, 253, 132, 150, 165, 9, 154, 189, 218, 61, 209, 1, 82,
            181, 196, 23, 53, 182, 112, 192, 206, 167, 157, 244, 35, 1, 189, 217, 61, 88, 97, 201,
            201, 74, 251, 217, 14, 104, 184, 54, 52, 74, 238, 10, 129, 22, 178, 226, 109, 88, 157,
            30, 196, 175, 26, 76, 34, 116, 220, 154, 232, 12, 179, 244, 15, 155, 196, 202, 72, 70,
            115, 10, 214, 114, 39, 245, 28, 237, 68, 136, 155,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrStecCorrectionDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrStecCorrectionDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5eb,
                    "Incorrect message type, expected 0x5eb, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0727,
                    "incorrect sender id, expected 0x0727, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 4,
                    "incorrect value for header.iod_atmo, expected 4, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 147,
                    "incorrect value for header.num_msgs, expected 147, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 123,
                    "incorrect value for header.seq_num, expected 123, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.time.tow, 3905179974,
                    "incorrect value for header.time.tow, expected 3905179974, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 11193,
                    "incorrect value for header.time.wn, expected 11193, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.update_interval, 39,
                    "incorrect value for header.update_interval, expected 39, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[0], -1951,
                    "incorrect value for stec_sat_list[0].stec_coeff[0], expected -1951, is {}",
                    msg.stec_sat_list[0].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[1], -9854,
                    "incorrect value for stec_sat_list[0].stec_coeff[1], expected -9854, is {}",
                    msg.stec_sat_list[0].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[2], 27353,
                    "incorrect value for stec_sat_list[0].stec_coeff[2], expected 27353, is {}",
                    msg.stec_sat_list[0].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[3], 3130,
                    "incorrect value for stec_sat_list[0].stec_coeff[3], expected 3130, is {}",
                    msg.stec_sat_list[0].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[0].stec_quality_indicator, 111, "incorrect value for stec_sat_list[0].stec_quality_indicator, expected 111, is {}", msg.stec_sat_list[0].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.constellation, 19,
                    "incorrect value for stec_sat_list[0].sv_id.constellation, expected 19, is {}",
                    msg.stec_sat_list[0].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.sat_id, 126,
                    "incorrect value for stec_sat_list[0].sv_id.sat_id, expected 126, is {}",
                    msg.stec_sat_list[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[0], 24401,
                    "incorrect value for stec_sat_list[1].stec_coeff[0], expected 24401, is {}",
                    msg.stec_sat_list[1].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[1], 4182,
                    "incorrect value for stec_sat_list[1].stec_coeff[1], expected 4182, is {}",
                    msg.stec_sat_list[1].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[2], 21543,
                    "incorrect value for stec_sat_list[1].stec_coeff[2], expected 21543, is {}",
                    msg.stec_sat_list[1].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[3], -12060,
                    "incorrect value for stec_sat_list[1].stec_coeff[3], expected -12060, is {}",
                    msg.stec_sat_list[1].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[1].stec_quality_indicator, 171, "incorrect value for stec_sat_list[1].stec_quality_indicator, expected 171, is {}", msg.stec_sat_list[1].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.constellation, 230,
                    "incorrect value for stec_sat_list[1].sv_id.constellation, expected 230, is {}",
                    msg.stec_sat_list[1].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.sat_id, 65,
                    "incorrect value for stec_sat_list[1].sv_id.sat_id, expected 65, is {}",
                    msg.stec_sat_list[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[0], -13469,
                    "incorrect value for stec_sat_list[2].stec_coeff[0], expected -13469, is {}",
                    msg.stec_sat_list[2].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[1], -18883,
                    "incorrect value for stec_sat_list[2].stec_coeff[1], expected -18883, is {}",
                    msg.stec_sat_list[2].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[2], 32066,
                    "incorrect value for stec_sat_list[2].stec_coeff[2], expected 32066, is {}",
                    msg.stec_sat_list[2].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[3], 971,
                    "incorrect value for stec_sat_list[2].stec_coeff[3], expected 971, is {}",
                    msg.stec_sat_list[2].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[2].stec_quality_indicator, 219, "incorrect value for stec_sat_list[2].stec_quality_indicator, expected 219, is {}", msg.stec_sat_list[2].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[2].sv_id.constellation, 81,
                    "incorrect value for stec_sat_list[2].sv_id.constellation, expected 81, is {}",
                    msg.stec_sat_list[2].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[2].sv_id.sat_id, 201,
                    "incorrect value for stec_sat_list[2].sv_id.sat_id, expected 201, is {}",
                    msg.stec_sat_list[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[0], 32220,
                    "incorrect value for stec_sat_list[3].stec_coeff[0], expected 32220, is {}",
                    msg.stec_sat_list[3].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[1], 5436,
                    "incorrect value for stec_sat_list[3].stec_coeff[1], expected 5436, is {}",
                    msg.stec_sat_list[3].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[2], -9635,
                    "incorrect value for stec_sat_list[3].stec_coeff[2], expected -9635, is {}",
                    msg.stec_sat_list[3].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[3], -24841,
                    "incorrect value for stec_sat_list[3].stec_coeff[3], expected -24841, is {}",
                    msg.stec_sat_list[3].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[3].stec_quality_indicator, 100, "incorrect value for stec_sat_list[3].stec_quality_indicator, expected 100, is {}", msg.stec_sat_list[3].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[3].sv_id.constellation, 44,
                    "incorrect value for stec_sat_list[3].sv_id.constellation, expected 44, is {}",
                    msg.stec_sat_list[3].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[3].sv_id.sat_id, 193,
                    "incorrect value for stec_sat_list[3].sv_id.sat_id, expected 193, is {}",
                    msg.stec_sat_list[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[0], 3718,
                    "incorrect value for stec_sat_list[4].stec_coeff[0], expected 3718, is {}",
                    msg.stec_sat_list[4].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[1], 12497,
                    "incorrect value for stec_sat_list[4].stec_coeff[1], expected 12497, is {}",
                    msg.stec_sat_list[4].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[2], -10482,
                    "incorrect value for stec_sat_list[4].stec_coeff[2], expected -10482, is {}",
                    msg.stec_sat_list[4].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[3], -27495,
                    "incorrect value for stec_sat_list[4].stec_coeff[3], expected -27495, is {}",
                    msg.stec_sat_list[4].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[4].stec_quality_indicator, 129, "incorrect value for stec_sat_list[4].stec_quality_indicator, expected 129, is {}", msg.stec_sat_list[4].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[4].sv_id.constellation, 93,
                    "incorrect value for stec_sat_list[4].sv_id.constellation, expected 93, is {}",
                    msg.stec_sat_list[4].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[4].sv_id.sat_id, 207,
                    "incorrect value for stec_sat_list[4].sv_id.sat_id, expected 207, is {}",
                    msg.stec_sat_list[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[0], -4940,
                    "incorrect value for stec_sat_list[5].stec_coeff[0], expected -4940, is {}",
                    msg.stec_sat_list[5].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[1], -13875,
                    "incorrect value for stec_sat_list[5].stec_coeff[1], expected -13875, is {}",
                    msg.stec_sat_list[5].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[2], 801,
                    "incorrect value for stec_sat_list[5].stec_coeff[2], expected 801, is {}",
                    msg.stec_sat_list[5].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[3], -13066,
                    "incorrect value for stec_sat_list[5].stec_coeff[3], expected -13066, is {}",
                    msg.stec_sat_list[5].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[5].stec_quality_indicator, 225, "incorrect value for stec_sat_list[5].stec_quality_indicator, expected 225, is {}", msg.stec_sat_list[5].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[5].sv_id.constellation, 72,
                    "incorrect value for stec_sat_list[5].sv_id.constellation, expected 72, is {}",
                    msg.stec_sat_list[5].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[5].sv_id.sat_id, 147,
                    "incorrect value for stec_sat_list[5].sv_id.sat_id, expected 147, is {}",
                    msg.stec_sat_list[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[0], -15868,
                    "incorrect value for stec_sat_list[6].stec_coeff[0], expected -15868, is {}",
                    msg.stec_sat_list[6].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[1], -2369,
                    "incorrect value for stec_sat_list[6].stec_coeff[1], expected -2369, is {}",
                    msg.stec_sat_list[6].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[2], -9396,
                    "incorrect value for stec_sat_list[6].stec_coeff[2], expected -9396, is {}",
                    msg.stec_sat_list[6].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[3], -16609,
                    "incorrect value for stec_sat_list[6].stec_coeff[3], expected -16609, is {}",
                    msg.stec_sat_list[6].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[6].stec_quality_indicator, 98, "incorrect value for stec_sat_list[6].stec_quality_indicator, expected 98, is {}", msg.stec_sat_list[6].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[6].sv_id.constellation, 3,
                    "incorrect value for stec_sat_list[6].sv_id.constellation, expected 3, is {}",
                    msg.stec_sat_list[6].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[6].sv_id.sat_id, 19,
                    "incorrect value for stec_sat_list[6].sv_id.sat_id, expected 19, is {}",
                    msg.stec_sat_list[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[0], -1265,
                    "incorrect value for stec_sat_list[7].stec_coeff[0], expected -1265, is {}",
                    msg.stec_sat_list[7].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[1], 4897,
                    "incorrect value for stec_sat_list[7].stec_coeff[1], expected 4897, is {}",
                    msg.stec_sat_list[7].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[2], 13920,
                    "incorrect value for stec_sat_list[7].stec_coeff[2], expected 13920, is {}",
                    msg.stec_sat_list[7].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[3], -28102,
                    "incorrect value for stec_sat_list[7].stec_coeff[3], expected -28102, is {}",
                    msg.stec_sat_list[7].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[7].stec_quality_indicator, 177, "incorrect value for stec_sat_list[7].stec_quality_indicator, expected 177, is {}", msg.stec_sat_list[7].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[7].sv_id.constellation, 79,
                    "incorrect value for stec_sat_list[7].sv_id.constellation, expected 79, is {}",
                    msg.stec_sat_list[7].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[7].sv_id.sat_id, 113,
                    "incorrect value for stec_sat_list[7].sv_id.sat_id, expected 113, is {}",
                    msg.stec_sat_list[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[0], 5448,
                    "incorrect value for stec_sat_list[8].stec_coeff[0], expected 5448, is {}",
                    msg.stec_sat_list[8].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[1], -11359,
                    "incorrect value for stec_sat_list[8].stec_coeff[1], expected -11359, is {}",
                    msg.stec_sat_list[8].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[2], 5574,
                    "incorrect value for stec_sat_list[8].stec_coeff[2], expected 5574, is {}",
                    msg.stec_sat_list[8].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[3], 28654,
                    "incorrect value for stec_sat_list[8].stec_coeff[3], expected 28654, is {}",
                    msg.stec_sat_list[8].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[8].stec_quality_indicator, 249, "incorrect value for stec_sat_list[8].stec_quality_indicator, expected 249, is {}", msg.stec_sat_list[8].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[8].sv_id.constellation, 100,
                    "incorrect value for stec_sat_list[8].sv_id.constellation, expected 100, is {}",
                    msg.stec_sat_list[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[8].sv_id.sat_id, 210,
                    "incorrect value for stec_sat_list[8].sv_id.sat_id, expected 210, is {}",
                    msg.stec_sat_list[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[0], -10783,
                    "incorrect value for stec_sat_list[9].stec_coeff[0], expected -10783, is {}",
                    msg.stec_sat_list[9].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[1], 18179,
                    "incorrect value for stec_sat_list[9].stec_coeff[1], expected 18179, is {}",
                    msg.stec_sat_list[9].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[2], 16371,
                    "incorrect value for stec_sat_list[9].stec_coeff[2], expected 16371, is {}",
                    msg.stec_sat_list[9].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[3], -5055,
                    "incorrect value for stec_sat_list[9].stec_coeff[3], expected -5055, is {}",
                    msg.stec_sat_list[9].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[9].stec_quality_indicator, 227, "incorrect value for stec_sat_list[9].stec_quality_indicator, expected 227, is {}", msg.stec_sat_list[9].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[9].sv_id.constellation, 36,
                    "incorrect value for stec_sat_list[9].sv_id.constellation, expected 36, is {}",
                    msg.stec_sat_list[9].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[9].sv_id.sat_id, 107,
                    "incorrect value for stec_sat_list[9].sv_id.sat_id, expected 107, is {}",
                    msg.stec_sat_list[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[0], 4009,
                    "incorrect value for stec_sat_list[10].stec_coeff[0], expected 4009, is {}",
                    msg.stec_sat_list[10].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[1], 1462,
                    "incorrect value for stec_sat_list[10].stec_coeff[1], expected 1462, is {}",
                    msg.stec_sat_list[10].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[2], -19216,
                    "incorrect value for stec_sat_list[10].stec_coeff[2], expected -19216, is {}",
                    msg.stec_sat_list[10].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[3], 31241,
                    "incorrect value for stec_sat_list[10].stec_coeff[3], expected 31241, is {}",
                    msg.stec_sat_list[10].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[10].stec_quality_indicator, 0, "incorrect value for stec_sat_list[10].stec_quality_indicator, expected 0, is {}", msg.stec_sat_list[10].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[10].sv_id.constellation, 77,
                    "incorrect value for stec_sat_list[10].sv_id.constellation, expected 77, is {}",
                    msg.stec_sat_list[10].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[10].sv_id.sat_id, 92,
                    "incorrect value for stec_sat_list[10].sv_id.sat_id, expected 92, is {}",
                    msg.stec_sat_list[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[0], 26727,
                    "incorrect value for stec_sat_list[11].stec_coeff[0], expected 26727, is {}",
                    msg.stec_sat_list[11].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[1], -16898,
                    "incorrect value for stec_sat_list[11].stec_coeff[1], expected -16898, is {}",
                    msg.stec_sat_list[11].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[2], 28241,
                    "incorrect value for stec_sat_list[11].stec_coeff[2], expected 28241, is {}",
                    msg.stec_sat_list[11].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[3], 12546,
                    "incorrect value for stec_sat_list[11].stec_coeff[3], expected 12546, is {}",
                    msg.stec_sat_list[11].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[11].stec_quality_indicator, 6, "incorrect value for stec_sat_list[11].stec_quality_indicator, expected 6, is {}", msg.stec_sat_list[11].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[11].sv_id.constellation, 232, "incorrect value for stec_sat_list[11].sv_id.constellation, expected 232, is {}", msg.stec_sat_list[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[11].sv_id.sat_id, 86,
                    "incorrect value for stec_sat_list[11].sv_id.sat_id, expected 86, is {}",
                    msg.stec_sat_list[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[0], 12855,
                    "incorrect value for stec_sat_list[12].stec_coeff[0], expected 12855, is {}",
                    msg.stec_sat_list[12].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[1], 1461,
                    "incorrect value for stec_sat_list[12].stec_coeff[1], expected 1461, is {}",
                    msg.stec_sat_list[12].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[2], 20603,
                    "incorrect value for stec_sat_list[12].stec_coeff[2], expected 20603, is {}",
                    msg.stec_sat_list[12].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[3], -3023,
                    "incorrect value for stec_sat_list[12].stec_coeff[3], expected -3023, is {}",
                    msg.stec_sat_list[12].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[12].stec_quality_indicator, 216, "incorrect value for stec_sat_list[12].stec_quality_indicator, expected 216, is {}", msg.stec_sat_list[12].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[12].sv_id.constellation, 84,
                    "incorrect value for stec_sat_list[12].sv_id.constellation, expected 84, is {}",
                    msg.stec_sat_list[12].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[12].sv_id.sat_id, 202,
                    "incorrect value for stec_sat_list[12].sv_id.sat_id, expected 202, is {}",
                    msg.stec_sat_list[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[0], -6492,
                    "incorrect value for stec_sat_list[13].stec_coeff[0], expected -6492, is {}",
                    msg.stec_sat_list[13].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[1], 16952,
                    "incorrect value for stec_sat_list[13].stec_coeff[1], expected 16952, is {}",
                    msg.stec_sat_list[13].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[2], -22404,
                    "incorrect value for stec_sat_list[13].stec_coeff[2], expected -22404, is {}",
                    msg.stec_sat_list[13].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[3], -29893,
                    "incorrect value for stec_sat_list[13].stec_coeff[3], expected -29893, is {}",
                    msg.stec_sat_list[13].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[13].stec_quality_indicator, 125, "incorrect value for stec_sat_list[13].stec_quality_indicator, expected 125, is {}", msg.stec_sat_list[13].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[13].sv_id.constellation, 188, "incorrect value for stec_sat_list[13].sv_id.constellation, expected 188, is {}", msg.stec_sat_list[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[13].sv_id.sat_id, 224,
                    "incorrect value for stec_sat_list[13].sv_id.sat_id, expected 224, is {}",
                    msg.stec_sat_list[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[0], -10053,
                    "incorrect value for stec_sat_list[14].stec_coeff[0], expected -10053, is {}",
                    msg.stec_sat_list[14].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[1], -24897,
                    "incorrect value for stec_sat_list[14].stec_coeff[1], expected -24897, is {}",
                    msg.stec_sat_list[14].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[2], 23629,
                    "incorrect value for stec_sat_list[14].stec_coeff[2], expected 23629, is {}",
                    msg.stec_sat_list[14].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[3], -710,
                    "incorrect value for stec_sat_list[14].stec_coeff[3], expected -710, is {}",
                    msg.stec_sat_list[14].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[14].stec_quality_indicator, 51, "incorrect value for stec_sat_list[14].stec_quality_indicator, expected 51, is {}", msg.stec_sat_list[14].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[14].sv_id.constellation, 118, "incorrect value for stec_sat_list[14].sv_id.constellation, expected 118, is {}", msg.stec_sat_list[14].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[14].sv_id.sat_id, 106,
                    "incorrect value for stec_sat_list[14].sv_id.sat_id, expected 106, is {}",
                    msg.stec_sat_list[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[0], -26103,
                    "incorrect value for stec_sat_list[15].stec_coeff[0], expected -26103, is {}",
                    msg.stec_sat_list[15].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[1], -9539,
                    "incorrect value for stec_sat_list[15].stec_coeff[1], expected -9539, is {}",
                    msg.stec_sat_list[15].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[2], -11971,
                    "incorrect value for stec_sat_list[15].stec_coeff[2], expected -11971, is {}",
                    msg.stec_sat_list[15].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[3], 20993,
                    "incorrect value for stec_sat_list[15].stec_coeff[3], expected 20993, is {}",
                    msg.stec_sat_list[15].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[15].stec_quality_indicator, 165, "incorrect value for stec_sat_list[15].stec_quality_indicator, expected 165, is {}", msg.stec_sat_list[15].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[15].sv_id.constellation, 150, "incorrect value for stec_sat_list[15].sv_id.constellation, expected 150, is {}", msg.stec_sat_list[15].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[15].sv_id.sat_id, 132,
                    "incorrect value for stec_sat_list[15].sv_id.sat_id, expected 132, is {}",
                    msg.stec_sat_list[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[0], -18891,
                    "incorrect value for stec_sat_list[16].stec_coeff[0], expected -18891, is {}",
                    msg.stec_sat_list[16].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[1], -16272,
                    "incorrect value for stec_sat_list[16].stec_coeff[1], expected -16272, is {}",
                    msg.stec_sat_list[16].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[2], -22578,
                    "incorrect value for stec_sat_list[16].stec_coeff[2], expected -22578, is {}",
                    msg.stec_sat_list[16].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[3], -2915,
                    "incorrect value for stec_sat_list[16].stec_coeff[3], expected -2915, is {}",
                    msg.stec_sat_list[16].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[16].stec_quality_indicator, 23, "incorrect value for stec_sat_list[16].stec_quality_indicator, expected 23, is {}", msg.stec_sat_list[16].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[16].sv_id.constellation, 196, "incorrect value for stec_sat_list[16].sv_id.constellation, expected 196, is {}", msg.stec_sat_list[16].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[16].sv_id.sat_id, 181,
                    "incorrect value for stec_sat_list[16].sv_id.sat_id, expected 181, is {}",
                    msg.stec_sat_list[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[0], 15833,
                    "incorrect value for stec_sat_list[17].stec_coeff[0], expected 15833, is {}",
                    msg.stec_sat_list[17].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[1], 24920,
                    "incorrect value for stec_sat_list[17].stec_coeff[1], expected 24920, is {}",
                    msg.stec_sat_list[17].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[2], -13879,
                    "incorrect value for stec_sat_list[17].stec_coeff[2], expected -13879, is {}",
                    msg.stec_sat_list[17].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[3], -1206,
                    "incorrect value for stec_sat_list[17].stec_coeff[3], expected -1206, is {}",
                    msg.stec_sat_list[17].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[17].stec_quality_indicator, 189, "incorrect value for stec_sat_list[17].stec_quality_indicator, expected 189, is {}", msg.stec_sat_list[17].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[17].sv_id.constellation, 1,
                    "incorrect value for stec_sat_list[17].sv_id.constellation, expected 1, is {}",
                    msg.stec_sat_list[17].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[17].sv_id.sat_id, 35,
                    "incorrect value for stec_sat_list[17].sv_id.sat_id, expected 35, is {}",
                    msg.stec_sat_list[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[0], 14008,
                    "incorrect value for stec_sat_list[18].stec_coeff[0], expected 14008, is {}",
                    msg.stec_sat_list[18].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[1], 18996,
                    "incorrect value for stec_sat_list[18].stec_coeff[1], expected 18996, is {}",
                    msg.stec_sat_list[18].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[2], 2798,
                    "incorrect value for stec_sat_list[18].stec_coeff[2], expected 2798, is {}",
                    msg.stec_sat_list[18].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[3], 5761,
                    "incorrect value for stec_sat_list[18].stec_coeff[3], expected 5761, is {}",
                    msg.stec_sat_list[18].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[18].stec_quality_indicator, 104, "incorrect value for stec_sat_list[18].stec_quality_indicator, expected 104, is {}", msg.stec_sat_list[18].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[18].sv_id.constellation, 14,
                    "incorrect value for stec_sat_list[18].sv_id.constellation, expected 14, is {}",
                    msg.stec_sat_list[18].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[18].sv_id.sat_id, 217,
                    "incorrect value for stec_sat_list[18].sv_id.sat_id, expected 217, is {}",
                    msg.stec_sat_list[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[0], -25256,
                    "incorrect value for stec_sat_list[19].stec_coeff[0], expected -25256, is {}",
                    msg.stec_sat_list[19].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[1], -15330,
                    "incorrect value for stec_sat_list[19].stec_coeff[1], expected -15330, is {}",
                    msg.stec_sat_list[19].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[2], 6831,
                    "incorrect value for stec_sat_list[19].stec_coeff[2], expected 6831, is {}",
                    msg.stec_sat_list[19].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[3], 8780,
                    "incorrect value for stec_sat_list[19].stec_coeff[3], expected 8780, is {}",
                    msg.stec_sat_list[19].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[19].stec_quality_indicator, 109, "incorrect value for stec_sat_list[19].stec_quality_indicator, expected 109, is {}", msg.stec_sat_list[19].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[19].sv_id.constellation, 226, "incorrect value for stec_sat_list[19].sv_id.constellation, expected 226, is {}", msg.stec_sat_list[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[19].sv_id.sat_id, 178,
                    "incorrect value for stec_sat_list[19].sv_id.sat_id, expected 178, is {}",
                    msg.stec_sat_list[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[0], 3304,
                    "incorrect value for stec_sat_list[20].stec_coeff[0], expected 3304, is {}",
                    msg.stec_sat_list[20].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[1], -2893,
                    "incorrect value for stec_sat_list[20].stec_coeff[1], expected -2893, is {}",
                    msg.stec_sat_list[20].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[2], -25841,
                    "incorrect value for stec_sat_list[20].stec_coeff[2], expected -25841, is {}",
                    msg.stec_sat_list[20].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[3], -13628,
                    "incorrect value for stec_sat_list[20].stec_coeff[3], expected -13628, is {}",
                    msg.stec_sat_list[20].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[20].stec_quality_indicator, 154, "incorrect value for stec_sat_list[20].stec_quality_indicator, expected 154, is {}", msg.stec_sat_list[20].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[20].sv_id.constellation, 220, "incorrect value for stec_sat_list[20].sv_id.constellation, expected 220, is {}", msg.stec_sat_list[20].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[20].sv_id.sat_id, 116,
                    "incorrect value for stec_sat_list[20].sv_id.sat_id, expected 116, is {}",
                    msg.stec_sat_list[20].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[21].stec_coeff[0], -10742,
                    "incorrect value for stec_sat_list[21].stec_coeff[0], expected -10742, is {}",
                    msg.stec_sat_list[21].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[21].stec_coeff[1], 10098,
                    "incorrect value for stec_sat_list[21].stec_coeff[1], expected 10098, is {}",
                    msg.stec_sat_list[21].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[21].stec_coeff[2], 7413,
                    "incorrect value for stec_sat_list[21].stec_coeff[2], expected 7413, is {}",
                    msg.stec_sat_list[21].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[21].stec_coeff[3], 17645,
                    "incorrect value for stec_sat_list[21].stec_coeff[3], expected 17645, is {}",
                    msg.stec_sat_list[21].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[21].stec_quality_indicator, 115, "incorrect value for stec_sat_list[21].stec_quality_indicator, expected 115, is {}", msg.stec_sat_list[21].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[21].sv_id.constellation, 70,
                    "incorrect value for stec_sat_list[21].sv_id.constellation, expected 70, is {}",
                    msg.stec_sat_list[21].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[21].sv_id.sat_id, 72,
                    "incorrect value for stec_sat_list[21].sv_id.sat_id, expected 72, is {}",
                    msg.stec_sat_list[21].sv_id.sat_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrStecCorrectionDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
