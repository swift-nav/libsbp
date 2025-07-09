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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrectionDep.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_stec_correction_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 251, 5, 204, 151, 245, 158, 228, 114, 117, 50, 158, 156, 42, 119, 156, 157, 112,
            47, 60, 132, 40, 70, 87, 235, 83, 177, 198, 3, 14, 8, 70, 12, 44, 53, 181, 90, 174,
            247, 150, 58, 172, 247, 179, 119, 176, 125, 4, 177, 229, 113, 14, 77, 153, 185, 23, 53,
            222, 187, 146, 250, 91, 212, 215, 14, 107, 250, 94, 107, 33, 91, 234, 0, 213, 139, 95,
            179, 50, 21, 74, 174, 169, 61, 86, 91, 142, 51, 108, 9, 38, 225, 146, 101, 73, 139, 56,
            117, 82, 37, 213, 108, 205, 93, 18, 19, 195, 33, 202, 87, 206, 178, 125, 188, 119, 56,
            69, 150, 150, 76, 3, 131, 18, 73, 208, 72, 232, 8, 250, 203, 178, 170, 163, 252, 86,
            49, 247, 178, 166, 56, 31, 10, 119, 213, 241, 212, 164, 1, 162, 42, 18, 124, 169, 121,
            158, 26, 56, 23, 142, 125, 40, 120, 67, 45, 126, 235, 110, 23, 12, 241, 88, 69, 239,
            252, 57, 93, 44, 201, 216, 173, 242, 178, 17, 5, 223, 169, 192, 3, 77, 107, 2, 144,
            233, 14, 88, 32, 209, 1, 17, 123, 155, 41, 183, 244, 158, 82, 53, 103, 14, 202, 185,
            35, 181, 21, 118, 254, 250, 50, 184, 50, 31, 45, 56, 163, 177, 126, 217, 79, 171, 239,
            237, 188, 238, 112, 201, 118, 141, 18, 163, 103, 35, 63, 21, 82, 129, 18, 117, 85, 190,
            79, 210, 215, 227, 177,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrStecCorrectionDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5fb,
                    "Incorrect message type, expected 0x5fb, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x97cc,
                    "incorrect sender id, expected 0x97cc, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 60,
                    "incorrect value for header.iod_atmo, expected 60, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 157,
                    "incorrect value for header.num_msgs, expected 157, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 112,
                    "incorrect value for header.seq_num, expected 112, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.tile_id, 30066,
                    "incorrect value for header.tile_id, expected 30066, is {}",
                    msg.header.tile_id
                );
                assert_eq!(
                    msg.header.tile_set_id, 58526,
                    "incorrect value for header.tile_set_id, expected 58526, is {}",
                    msg.header.tile_set_id
                );
                assert_eq!(
                    msg.header.time.tow, 714907186,
                    "incorrect value for header.time.tow, expected 714907186, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 40055,
                    "incorrect value for header.time.wn, expected 40055, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.update_interval, 47,
                    "incorrect value for header.update_interval, expected 47, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[0], -5289,
                    "incorrect value for stec_sat_list[0].stec_coeff[0], expected -5289, is {}",
                    msg.stec_sat_list[0].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[1], -20141,
                    "incorrect value for stec_sat_list[0].stec_coeff[1], expected -20141, is {}",
                    msg.stec_sat_list[0].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[2], 966,
                    "incorrect value for stec_sat_list[0].stec_coeff[2], expected 966, is {}",
                    msg.stec_sat_list[0].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[3], 2062,
                    "incorrect value for stec_sat_list[0].stec_coeff[3], expected 2062, is {}",
                    msg.stec_sat_list[0].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[0].stec_quality_indicator, 70, "incorrect value for stec_sat_list[0].stec_quality_indicator, expected 70, is {}", msg.stec_sat_list[0].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.constellation, 40,
                    "incorrect value for stec_sat_list[0].sv_id.constellation, expected 40, is {}",
                    msg.stec_sat_list[0].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.sat_id, 132,
                    "incorrect value for stec_sat_list[0].sv_id.sat_id, expected 132, is {}",
                    msg.stec_sat_list[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[0], -19147,
                    "incorrect value for stec_sat_list[1].stec_coeff[0], expected -19147, is {}",
                    msg.stec_sat_list[1].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[1], -20902,
                    "incorrect value for stec_sat_list[1].stec_coeff[1], expected -20902, is {}",
                    msg.stec_sat_list[1].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[2], -26889,
                    "incorrect value for stec_sat_list[1].stec_coeff[2], expected -26889, is {}",
                    msg.stec_sat_list[1].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[3], -21446,
                    "incorrect value for stec_sat_list[1].stec_coeff[3], expected -21446, is {}",
                    msg.stec_sat_list[1].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[1].stec_quality_indicator, 44, "incorrect value for stec_sat_list[1].stec_quality_indicator, expected 44, is {}", msg.stec_sat_list[1].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.constellation, 12,
                    "incorrect value for stec_sat_list[1].sv_id.constellation, expected 12, is {}",
                    msg.stec_sat_list[1].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.sat_id, 70,
                    "incorrect value for stec_sat_list[1].sv_id.sat_id, expected 70, is {}",
                    msg.stec_sat_list[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[0], 32176,
                    "incorrect value for stec_sat_list[2].stec_coeff[0], expected 32176, is {}",
                    msg.stec_sat_list[2].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[1], -20220,
                    "incorrect value for stec_sat_list[2].stec_coeff[1], expected -20220, is {}",
                    msg.stec_sat_list[2].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[2], 29157,
                    "incorrect value for stec_sat_list[2].stec_coeff[2], expected 29157, is {}",
                    msg.stec_sat_list[2].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[3], 19726,
                    "incorrect value for stec_sat_list[2].stec_coeff[3], expected 19726, is {}",
                    msg.stec_sat_list[2].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[2].stec_quality_indicator, 119, "incorrect value for stec_sat_list[2].stec_quality_indicator, expected 119, is {}", msg.stec_sat_list[2].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[2].sv_id.constellation, 179,
                    "incorrect value for stec_sat_list[2].sv_id.constellation, expected 179, is {}",
                    msg.stec_sat_list[2].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[2].sv_id.sat_id, 247,
                    "incorrect value for stec_sat_list[2].sv_id.sat_id, expected 247, is {}",
                    msg.stec_sat_list[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[0], -8651,
                    "incorrect value for stec_sat_list[3].stec_coeff[0], expected -8651, is {}",
                    msg.stec_sat_list[3].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[1], -27973,
                    "incorrect value for stec_sat_list[3].stec_coeff[1], expected -27973, is {}",
                    msg.stec_sat_list[3].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[2], 23546,
                    "incorrect value for stec_sat_list[3].stec_coeff[2], expected 23546, is {}",
                    msg.stec_sat_list[3].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[3], -10284,
                    "incorrect value for stec_sat_list[3].stec_coeff[3], expected -10284, is {}",
                    msg.stec_sat_list[3].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[3].stec_quality_indicator, 23, "incorrect value for stec_sat_list[3].stec_quality_indicator, expected 23, is {}", msg.stec_sat_list[3].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[3].sv_id.constellation, 185,
                    "incorrect value for stec_sat_list[3].sv_id.constellation, expected 185, is {}",
                    msg.stec_sat_list[3].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[3].sv_id.sat_id, 153,
                    "incorrect value for stec_sat_list[3].sv_id.sat_id, expected 153, is {}",
                    msg.stec_sat_list[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[0], 27486,
                    "incorrect value for stec_sat_list[4].stec_coeff[0], expected 27486, is {}",
                    msg.stec_sat_list[4].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[1], 23329,
                    "incorrect value for stec_sat_list[4].stec_coeff[1], expected 23329, is {}",
                    msg.stec_sat_list[4].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[2], 234,
                    "incorrect value for stec_sat_list[4].stec_coeff[2], expected 234, is {}",
                    msg.stec_sat_list[4].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[3], -29739,
                    "incorrect value for stec_sat_list[4].stec_coeff[3], expected -29739, is {}",
                    msg.stec_sat_list[4].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[4].stec_quality_indicator, 250, "incorrect value for stec_sat_list[4].stec_quality_indicator, expected 250, is {}", msg.stec_sat_list[4].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[4].sv_id.constellation, 107,
                    "incorrect value for stec_sat_list[4].sv_id.constellation, expected 107, is {}",
                    msg.stec_sat_list[4].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[4].sv_id.sat_id, 14,
                    "incorrect value for stec_sat_list[4].sv_id.sat_id, expected 14, is {}",
                    msg.stec_sat_list[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[0], 18965,
                    "incorrect value for stec_sat_list[5].stec_coeff[0], expected 18965, is {}",
                    msg.stec_sat_list[5].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[1], -22098,
                    "incorrect value for stec_sat_list[5].stec_coeff[1], expected -22098, is {}",
                    msg.stec_sat_list[5].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[2], 22077,
                    "incorrect value for stec_sat_list[5].stec_coeff[2], expected 22077, is {}",
                    msg.stec_sat_list[5].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[3], -29093,
                    "incorrect value for stec_sat_list[5].stec_coeff[3], expected -29093, is {}",
                    msg.stec_sat_list[5].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[5].stec_quality_indicator, 50, "incorrect value for stec_sat_list[5].stec_quality_indicator, expected 50, is {}", msg.stec_sat_list[5].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[5].sv_id.constellation, 179,
                    "incorrect value for stec_sat_list[5].sv_id.constellation, expected 179, is {}",
                    msg.stec_sat_list[5].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[5].sv_id.sat_id, 95,
                    "incorrect value for stec_sat_list[5].sv_id.sat_id, expected 95, is {}",
                    msg.stec_sat_list[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[0], -7898,
                    "incorrect value for stec_sat_list[6].stec_coeff[0], expected -7898, is {}",
                    msg.stec_sat_list[6].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[1], 26002,
                    "incorrect value for stec_sat_list[6].stec_coeff[1], expected 26002, is {}",
                    msg.stec_sat_list[6].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[2], -29879,
                    "incorrect value for stec_sat_list[6].stec_coeff[2], expected -29879, is {}",
                    msg.stec_sat_list[6].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[3], 30008,
                    "incorrect value for stec_sat_list[6].stec_coeff[3], expected 30008, is {}",
                    msg.stec_sat_list[6].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[6].stec_quality_indicator, 9, "incorrect value for stec_sat_list[6].stec_quality_indicator, expected 9, is {}", msg.stec_sat_list[6].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[6].sv_id.constellation, 108,
                    "incorrect value for stec_sat_list[6].sv_id.constellation, expected 108, is {}",
                    msg.stec_sat_list[6].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[6].sv_id.sat_id, 51,
                    "incorrect value for stec_sat_list[6].sv_id.sat_id, expected 51, is {}",
                    msg.stec_sat_list[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[0], -12948,
                    "incorrect value for stec_sat_list[7].stec_coeff[0], expected -12948, is {}",
                    msg.stec_sat_list[7].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[1], 4701,
                    "incorrect value for stec_sat_list[7].stec_coeff[1], expected 4701, is {}",
                    msg.stec_sat_list[7].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[2], -15597,
                    "incorrect value for stec_sat_list[7].stec_coeff[2], expected -15597, is {}",
                    msg.stec_sat_list[7].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[3], -13791,
                    "incorrect value for stec_sat_list[7].stec_coeff[3], expected -13791, is {}",
                    msg.stec_sat_list[7].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[7].stec_quality_indicator, 213, "incorrect value for stec_sat_list[7].stec_quality_indicator, expected 213, is {}", msg.stec_sat_list[7].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[7].sv_id.constellation, 37,
                    "incorrect value for stec_sat_list[7].sv_id.constellation, expected 37, is {}",
                    msg.stec_sat_list[7].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[7].sv_id.sat_id, 82,
                    "incorrect value for stec_sat_list[7].sv_id.sat_id, expected 82, is {}",
                    msg.stec_sat_list[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[0], -17283,
                    "incorrect value for stec_sat_list[8].stec_coeff[0], expected -17283, is {}",
                    msg.stec_sat_list[8].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[1], 14455,
                    "incorrect value for stec_sat_list[8].stec_coeff[1], expected 14455, is {}",
                    msg.stec_sat_list[8].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[2], -27067,
                    "incorrect value for stec_sat_list[8].stec_coeff[2], expected -27067, is {}",
                    msg.stec_sat_list[8].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[3], 19606,
                    "incorrect value for stec_sat_list[8].stec_coeff[3], expected 19606, is {}",
                    msg.stec_sat_list[8].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[8].stec_quality_indicator, 178, "incorrect value for stec_sat_list[8].stec_quality_indicator, expected 178, is {}", msg.stec_sat_list[8].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[8].sv_id.constellation, 206,
                    "incorrect value for stec_sat_list[8].sv_id.constellation, expected 206, is {}",
                    msg.stec_sat_list[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[8].sv_id.sat_id, 87,
                    "incorrect value for stec_sat_list[8].sv_id.sat_id, expected 87, is {}",
                    msg.stec_sat_list[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[0], -12215,
                    "incorrect value for stec_sat_list[9].stec_coeff[0], expected -12215, is {}",
                    msg.stec_sat_list[9].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[1], -6072,
                    "incorrect value for stec_sat_list[9].stec_coeff[1], expected -6072, is {}",
                    msg.stec_sat_list[9].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[2], -1528,
                    "incorrect value for stec_sat_list[9].stec_coeff[2], expected -1528, is {}",
                    msg.stec_sat_list[9].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[3], -19765,
                    "incorrect value for stec_sat_list[9].stec_coeff[3], expected -19765, is {}",
                    msg.stec_sat_list[9].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[9].stec_quality_indicator, 18, "incorrect value for stec_sat_list[9].stec_quality_indicator, expected 18, is {}", msg.stec_sat_list[9].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[9].sv_id.constellation, 131,
                    "incorrect value for stec_sat_list[9].sv_id.constellation, expected 131, is {}",
                    msg.stec_sat_list[9].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[9].sv_id.sat_id, 3,
                    "incorrect value for stec_sat_list[9].sv_id.sat_id, expected 3, is {}",
                    msg.stec_sat_list[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[0], 12630,
                    "incorrect value for stec_sat_list[10].stec_coeff[0], expected 12630, is {}",
                    msg.stec_sat_list[10].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[1], -19721,
                    "incorrect value for stec_sat_list[10].stec_coeff[1], expected -19721, is {}",
                    msg.stec_sat_list[10].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[2], 14502,
                    "incorrect value for stec_sat_list[10].stec_coeff[2], expected 14502, is {}",
                    msg.stec_sat_list[10].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[3], 2591,
                    "incorrect value for stec_sat_list[10].stec_coeff[3], expected 2591, is {}",
                    msg.stec_sat_list[10].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[10].stec_quality_indicator, 252, "incorrect value for stec_sat_list[10].stec_quality_indicator, expected 252, is {}", msg.stec_sat_list[10].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[10].sv_id.constellation, 163, "incorrect value for stec_sat_list[10].sv_id.constellation, expected 163, is {}", msg.stec_sat_list[10].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[10].sv_id.sat_id, 170,
                    "incorrect value for stec_sat_list[10].sv_id.sat_id, expected 170, is {}",
                    msg.stec_sat_list[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[0], -23340,
                    "incorrect value for stec_sat_list[11].stec_coeff[0], expected -23340, is {}",
                    msg.stec_sat_list[11].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[1], -24063,
                    "incorrect value for stec_sat_list[11].stec_coeff[1], expected -24063, is {}",
                    msg.stec_sat_list[11].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[2], 4650,
                    "incorrect value for stec_sat_list[11].stec_coeff[2], expected 4650, is {}",
                    msg.stec_sat_list[11].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[3], -22148,
                    "incorrect value for stec_sat_list[11].stec_coeff[3], expected -22148, is {}",
                    msg.stec_sat_list[11].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[11].stec_quality_indicator, 241, "incorrect value for stec_sat_list[11].stec_quality_indicator, expected 241, is {}", msg.stec_sat_list[11].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[11].sv_id.constellation, 213, "incorrect value for stec_sat_list[11].sv_id.constellation, expected 213, is {}", msg.stec_sat_list[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[11].sv_id.sat_id, 119,
                    "incorrect value for stec_sat_list[11].sv_id.sat_id, expected 119, is {}",
                    msg.stec_sat_list[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[0], 5944,
                    "incorrect value for stec_sat_list[12].stec_coeff[0], expected 5944, is {}",
                    msg.stec_sat_list[12].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[1], 32142,
                    "incorrect value for stec_sat_list[12].stec_coeff[1], expected 32142, is {}",
                    msg.stec_sat_list[12].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[2], 30760,
                    "incorrect value for stec_sat_list[12].stec_coeff[2], expected 30760, is {}",
                    msg.stec_sat_list[12].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[3], 11587,
                    "incorrect value for stec_sat_list[12].stec_coeff[3], expected 11587, is {}",
                    msg.stec_sat_list[12].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[12].stec_quality_indicator, 26, "incorrect value for stec_sat_list[12].stec_quality_indicator, expected 26, is {}", msg.stec_sat_list[12].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[12].sv_id.constellation, 158, "incorrect value for stec_sat_list[12].sv_id.constellation, expected 158, is {}", msg.stec_sat_list[12].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[12].sv_id.sat_id, 121,
                    "incorrect value for stec_sat_list[12].sv_id.sat_id, expected 121, is {}",
                    msg.stec_sat_list[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[0], 3095,
                    "incorrect value for stec_sat_list[13].stec_coeff[0], expected 3095, is {}",
                    msg.stec_sat_list[13].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[1], 22769,
                    "incorrect value for stec_sat_list[13].stec_coeff[1], expected 22769, is {}",
                    msg.stec_sat_list[13].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[2], -4283,
                    "incorrect value for stec_sat_list[13].stec_coeff[2], expected -4283, is {}",
                    msg.stec_sat_list[13].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[3], 14844,
                    "incorrect value for stec_sat_list[13].stec_coeff[3], expected 14844, is {}",
                    msg.stec_sat_list[13].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[13].stec_quality_indicator, 110, "incorrect value for stec_sat_list[13].stec_quality_indicator, expected 110, is {}", msg.stec_sat_list[13].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[13].sv_id.constellation, 235, "incorrect value for stec_sat_list[13].sv_id.constellation, expected 235, is {}", msg.stec_sat_list[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[13].sv_id.sat_id, 126,
                    "incorrect value for stec_sat_list[13].sv_id.sat_id, expected 126, is {}",
                    msg.stec_sat_list[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[0], -21032,
                    "incorrect value for stec_sat_list[14].stec_coeff[0], expected -21032, is {}",
                    msg.stec_sat_list[14].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[1], -19726,
                    "incorrect value for stec_sat_list[14].stec_coeff[1], expected -19726, is {}",
                    msg.stec_sat_list[14].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[2], 1297,
                    "incorrect value for stec_sat_list[14].stec_coeff[2], expected 1297, is {}",
                    msg.stec_sat_list[14].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[3], -22049,
                    "incorrect value for stec_sat_list[14].stec_coeff[3], expected -22049, is {}",
                    msg.stec_sat_list[14].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[14].stec_quality_indicator, 201, "incorrect value for stec_sat_list[14].stec_quality_indicator, expected 201, is {}", msg.stec_sat_list[14].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[14].sv_id.constellation, 44,
                    "incorrect value for stec_sat_list[14].sv_id.constellation, expected 44, is {}",
                    msg.stec_sat_list[14].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[14].sv_id.sat_id, 93,
                    "incorrect value for stec_sat_list[14].sv_id.sat_id, expected 93, is {}",
                    msg.stec_sat_list[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[0], 619,
                    "incorrect value for stec_sat_list[15].stec_coeff[0], expected 619, is {}",
                    msg.stec_sat_list[15].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[1], -5744,
                    "incorrect value for stec_sat_list[15].stec_coeff[1], expected -5744, is {}",
                    msg.stec_sat_list[15].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[2], 22542,
                    "incorrect value for stec_sat_list[15].stec_coeff[2], expected 22542, is {}",
                    msg.stec_sat_list[15].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[3], -12000,
                    "incorrect value for stec_sat_list[15].stec_coeff[3], expected -12000, is {}",
                    msg.stec_sat_list[15].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[15].stec_quality_indicator, 77, "incorrect value for stec_sat_list[15].stec_quality_indicator, expected 77, is {}", msg.stec_sat_list[15].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[15].sv_id.constellation, 3,
                    "incorrect value for stec_sat_list[15].sv_id.constellation, expected 3, is {}",
                    msg.stec_sat_list[15].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[15].sv_id.sat_id, 192,
                    "incorrect value for stec_sat_list[15].sv_id.sat_id, expected 192, is {}",
                    msg.stec_sat_list[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[0], 10651,
                    "incorrect value for stec_sat_list[16].stec_coeff[0], expected 10651, is {}",
                    msg.stec_sat_list[16].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[1], -2889,
                    "incorrect value for stec_sat_list[16].stec_coeff[1], expected -2889, is {}",
                    msg.stec_sat_list[16].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[2], 21150,
                    "incorrect value for stec_sat_list[16].stec_coeff[2], expected 21150, is {}",
                    msg.stec_sat_list[16].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[3], 26421,
                    "incorrect value for stec_sat_list[16].stec_coeff[3], expected 26421, is {}",
                    msg.stec_sat_list[16].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[16].stec_quality_indicator, 123, "incorrect value for stec_sat_list[16].stec_quality_indicator, expected 123, is {}", msg.stec_sat_list[16].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[16].sv_id.constellation, 17,
                    "incorrect value for stec_sat_list[16].sv_id.constellation, expected 17, is {}",
                    msg.stec_sat_list[16].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[16].sv_id.sat_id, 1,
                    "incorrect value for stec_sat_list[16].sv_id.sat_id, expected 1, is {}",
                    msg.stec_sat_list[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[0], -19165,
                    "incorrect value for stec_sat_list[17].stec_coeff[0], expected -19165, is {}",
                    msg.stec_sat_list[17].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[1], 30229,
                    "incorrect value for stec_sat_list[17].stec_coeff[1], expected 30229, is {}",
                    msg.stec_sat_list[17].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[2], -1282,
                    "incorrect value for stec_sat_list[17].stec_coeff[2], expected -1282, is {}",
                    msg.stec_sat_list[17].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[3], -18382,
                    "incorrect value for stec_sat_list[17].stec_coeff[3], expected -18382, is {}",
                    msg.stec_sat_list[17].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[17].stec_quality_indicator, 185, "incorrect value for stec_sat_list[17].stec_quality_indicator, expected 185, is {}", msg.stec_sat_list[17].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[17].sv_id.constellation, 202, "incorrect value for stec_sat_list[17].sv_id.constellation, expected 202, is {}", msg.stec_sat_list[17].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[17].sv_id.sat_id, 14,
                    "incorrect value for stec_sat_list[17].sv_id.sat_id, expected 14, is {}",
                    msg.stec_sat_list[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[0], -23752,
                    "incorrect value for stec_sat_list[18].stec_coeff[0], expected -23752, is {}",
                    msg.stec_sat_list[18].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[1], 32433,
                    "incorrect value for stec_sat_list[18].stec_coeff[1], expected 32433, is {}",
                    msg.stec_sat_list[18].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[2], 20441,
                    "incorrect value for stec_sat_list[18].stec_coeff[2], expected 20441, is {}",
                    msg.stec_sat_list[18].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[3], -4181,
                    "incorrect value for stec_sat_list[18].stec_coeff[3], expected -4181, is {}",
                    msg.stec_sat_list[18].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[18].stec_quality_indicator, 45, "incorrect value for stec_sat_list[18].stec_quality_indicator, expected 45, is {}", msg.stec_sat_list[18].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[18].sv_id.constellation, 31,
                    "incorrect value for stec_sat_list[18].sv_id.constellation, expected 31, is {}",
                    msg.stec_sat_list[18].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[18].sv_id.sat_id, 50,
                    "incorrect value for stec_sat_list[18].sv_id.sat_id, expected 50, is {}",
                    msg.stec_sat_list[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[0], -13968,
                    "incorrect value for stec_sat_list[19].stec_coeff[0], expected -13968, is {}",
                    msg.stec_sat_list[19].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[1], -29322,
                    "incorrect value for stec_sat_list[19].stec_coeff[1], expected -29322, is {}",
                    msg.stec_sat_list[19].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[2], -23790,
                    "incorrect value for stec_sat_list[19].stec_coeff[2], expected -23790, is {}",
                    msg.stec_sat_list[19].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[3], 9063,
                    "incorrect value for stec_sat_list[19].stec_coeff[3], expected 9063, is {}",
                    msg.stec_sat_list[19].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[19].stec_quality_indicator, 238, "incorrect value for stec_sat_list[19].stec_quality_indicator, expected 238, is {}", msg.stec_sat_list[19].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[19].sv_id.constellation, 188, "incorrect value for stec_sat_list[19].sv_id.constellation, expected 188, is {}", msg.stec_sat_list[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[19].sv_id.sat_id, 237,
                    "incorrect value for stec_sat_list[19].sv_id.sat_id, expected 237, is {}",
                    msg.stec_sat_list[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[0], 4737,
                    "incorrect value for stec_sat_list[20].stec_coeff[0], expected 4737, is {}",
                    msg.stec_sat_list[20].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[1], 21877,
                    "incorrect value for stec_sat_list[20].stec_coeff[1], expected 21877, is {}",
                    msg.stec_sat_list[20].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[2], 20414,
                    "incorrect value for stec_sat_list[20].stec_coeff[2], expected 20414, is {}",
                    msg.stec_sat_list[20].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[3], -10286,
                    "incorrect value for stec_sat_list[20].stec_coeff[3], expected -10286, is {}",
                    msg.stec_sat_list[20].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[20].stec_quality_indicator, 82, "incorrect value for stec_sat_list[20].stec_quality_indicator, expected 82, is {}", msg.stec_sat_list[20].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[20].sv_id.constellation, 21,
                    "incorrect value for stec_sat_list[20].sv_id.constellation, expected 21, is {}",
                    msg.stec_sat_list[20].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[20].sv_id.sat_id, 63,
                    "incorrect value for stec_sat_list[20].sv_id.sat_id, expected 63, is {}",
                    msg.stec_sat_list[20].sv_id.sat_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrStecCorrectionDep"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_stec_correction_dep() {
    {
        let json_input = r#"{"crc":45539,"length":245,"msg_type":1531,"payload":"nuRydTKenCp3nJ1wLzyEKEZX61OxxgMOCEYMLDW1Wq73ljqs97N3sH0EseVxDk2ZuRc13ruS+lvU1w5r+l5rIVvqANWLX7MyFUquqT1WW44zbAkm4ZJlSYs4dVIl1WzNXRITwyHKV86yfbx3OEWWlkwDgxJJ0EjoCPrLsqqj/FYx97KmOB8Kd9Xx1KQBoioSfKl5nho4F459KHhDLX7rbhcM8VhF7/w5XSzJ2K3yshEF36nAA01rApDpDlgg0QERe5spt/SeUjVnDsq5I7UVdv76MrgyHy04o7F+2U+r7+287nDJdo0So2cjPxVSgRJ1Vb5P0tc=","preamble":85,"sender":38860,"header":{"tile_set_id":58526,"tile_id":30066,"time":{"tow":714907186,"wn":40055},"num_msgs":157,"seq_num":112,"update_interval":47,"iod_atmo":60},"stec_sat_list":[{"sv_id":{"satId":132,"constellation":40},"stec_quality_indicator":70,"stec_coeff":[-5289,-20141,966,2062]},{"sv_id":{"satId":70,"constellation":12},"stec_quality_indicator":44,"stec_coeff":[-19147,-20902,-26889,-21446]},{"sv_id":{"satId":247,"constellation":179},"stec_quality_indicator":119,"stec_coeff":[32176,-20220,29157,19726]},{"sv_id":{"satId":153,"constellation":185},"stec_quality_indicator":23,"stec_coeff":[-8651,-27973,23546,-10284]},{"sv_id":{"satId":14,"constellation":107},"stec_quality_indicator":250,"stec_coeff":[27486,23329,234,-29739]},{"sv_id":{"satId":95,"constellation":179},"stec_quality_indicator":50,"stec_coeff":[18965,-22098,22077,-29093]},{"sv_id":{"satId":51,"constellation":108},"stec_quality_indicator":9,"stec_coeff":[-7898,26002,-29879,30008]},{"sv_id":{"satId":82,"constellation":37},"stec_quality_indicator":213,"stec_coeff":[-12948,4701,-15597,-13791]},{"sv_id":{"satId":87,"constellation":206},"stec_quality_indicator":178,"stec_coeff":[-17283,14455,-27067,19606]},{"sv_id":{"satId":3,"constellation":131},"stec_quality_indicator":18,"stec_coeff":[-12215,-6072,-1528,-19765]},{"sv_id":{"satId":170,"constellation":163},"stec_quality_indicator":252,"stec_coeff":[12630,-19721,14502,2591]},{"sv_id":{"satId":119,"constellation":213},"stec_quality_indicator":241,"stec_coeff":[-23340,-24063,4650,-22148]},{"sv_id":{"satId":121,"constellation":158},"stec_quality_indicator":26,"stec_coeff":[5944,32142,30760,11587]},{"sv_id":{"satId":126,"constellation":235},"stec_quality_indicator":110,"stec_coeff":[3095,22769,-4283,14844]},{"sv_id":{"satId":93,"constellation":44},"stec_quality_indicator":201,"stec_coeff":[-21032,-19726,1297,-22049]},{"sv_id":{"satId":192,"constellation":3},"stec_quality_indicator":77,"stec_coeff":[619,-5744,22542,-12000]},{"sv_id":{"satId":1,"constellation":17},"stec_quality_indicator":123,"stec_coeff":[10651,-2889,21150,26421]},{"sv_id":{"satId":14,"constellation":202},"stec_quality_indicator":185,"stec_coeff":[-19165,30229,-1282,-18382]},{"sv_id":{"satId":50,"constellation":31},"stec_quality_indicator":45,"stec_coeff":[-23752,32433,20441,-4181]},{"sv_id":{"satId":237,"constellation":188},"stec_quality_indicator":238,"stec_coeff":[-13968,-29322,-23790,9063]},{"sv_id":{"satId":63,"constellation":21},"stec_quality_indicator":82,"stec_coeff":[4737,21877,20414,-10286]}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrStecCorrectionDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5fb,
                    "Incorrect message type, expected 0x5fb, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x97cc,
                    "incorrect sender id, expected 0x97cc, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 60,
                    "incorrect value for header.iod_atmo, expected 60, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 157,
                    "incorrect value for header.num_msgs, expected 157, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 112,
                    "incorrect value for header.seq_num, expected 112, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.tile_id, 30066,
                    "incorrect value for header.tile_id, expected 30066, is {}",
                    msg.header.tile_id
                );
                assert_eq!(
                    msg.header.tile_set_id, 58526,
                    "incorrect value for header.tile_set_id, expected 58526, is {}",
                    msg.header.tile_set_id
                );
                assert_eq!(
                    msg.header.time.tow, 714907186,
                    "incorrect value for header.time.tow, expected 714907186, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 40055,
                    "incorrect value for header.time.wn, expected 40055, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.update_interval, 47,
                    "incorrect value for header.update_interval, expected 47, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[0], -5289,
                    "incorrect value for stec_sat_list[0].stec_coeff[0], expected -5289, is {}",
                    msg.stec_sat_list[0].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[1], -20141,
                    "incorrect value for stec_sat_list[0].stec_coeff[1], expected -20141, is {}",
                    msg.stec_sat_list[0].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[2], 966,
                    "incorrect value for stec_sat_list[0].stec_coeff[2], expected 966, is {}",
                    msg.stec_sat_list[0].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[3], 2062,
                    "incorrect value for stec_sat_list[0].stec_coeff[3], expected 2062, is {}",
                    msg.stec_sat_list[0].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[0].stec_quality_indicator, 70, "incorrect value for stec_sat_list[0].stec_quality_indicator, expected 70, is {}", msg.stec_sat_list[0].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.constellation, 40,
                    "incorrect value for stec_sat_list[0].sv_id.constellation, expected 40, is {}",
                    msg.stec_sat_list[0].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.sat_id, 132,
                    "incorrect value for stec_sat_list[0].sv_id.sat_id, expected 132, is {}",
                    msg.stec_sat_list[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[0], -19147,
                    "incorrect value for stec_sat_list[1].stec_coeff[0], expected -19147, is {}",
                    msg.stec_sat_list[1].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[1], -20902,
                    "incorrect value for stec_sat_list[1].stec_coeff[1], expected -20902, is {}",
                    msg.stec_sat_list[1].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[2], -26889,
                    "incorrect value for stec_sat_list[1].stec_coeff[2], expected -26889, is {}",
                    msg.stec_sat_list[1].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[3], -21446,
                    "incorrect value for stec_sat_list[1].stec_coeff[3], expected -21446, is {}",
                    msg.stec_sat_list[1].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[1].stec_quality_indicator, 44, "incorrect value for stec_sat_list[1].stec_quality_indicator, expected 44, is {}", msg.stec_sat_list[1].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.constellation, 12,
                    "incorrect value for stec_sat_list[1].sv_id.constellation, expected 12, is {}",
                    msg.stec_sat_list[1].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.sat_id, 70,
                    "incorrect value for stec_sat_list[1].sv_id.sat_id, expected 70, is {}",
                    msg.stec_sat_list[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[0], 32176,
                    "incorrect value for stec_sat_list[2].stec_coeff[0], expected 32176, is {}",
                    msg.stec_sat_list[2].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[1], -20220,
                    "incorrect value for stec_sat_list[2].stec_coeff[1], expected -20220, is {}",
                    msg.stec_sat_list[2].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[2], 29157,
                    "incorrect value for stec_sat_list[2].stec_coeff[2], expected 29157, is {}",
                    msg.stec_sat_list[2].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[3], 19726,
                    "incorrect value for stec_sat_list[2].stec_coeff[3], expected 19726, is {}",
                    msg.stec_sat_list[2].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[2].stec_quality_indicator, 119, "incorrect value for stec_sat_list[2].stec_quality_indicator, expected 119, is {}", msg.stec_sat_list[2].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[2].sv_id.constellation, 179,
                    "incorrect value for stec_sat_list[2].sv_id.constellation, expected 179, is {}",
                    msg.stec_sat_list[2].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[2].sv_id.sat_id, 247,
                    "incorrect value for stec_sat_list[2].sv_id.sat_id, expected 247, is {}",
                    msg.stec_sat_list[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[0], -8651,
                    "incorrect value for stec_sat_list[3].stec_coeff[0], expected -8651, is {}",
                    msg.stec_sat_list[3].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[1], -27973,
                    "incorrect value for stec_sat_list[3].stec_coeff[1], expected -27973, is {}",
                    msg.stec_sat_list[3].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[2], 23546,
                    "incorrect value for stec_sat_list[3].stec_coeff[2], expected 23546, is {}",
                    msg.stec_sat_list[3].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[3], -10284,
                    "incorrect value for stec_sat_list[3].stec_coeff[3], expected -10284, is {}",
                    msg.stec_sat_list[3].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[3].stec_quality_indicator, 23, "incorrect value for stec_sat_list[3].stec_quality_indicator, expected 23, is {}", msg.stec_sat_list[3].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[3].sv_id.constellation, 185,
                    "incorrect value for stec_sat_list[3].sv_id.constellation, expected 185, is {}",
                    msg.stec_sat_list[3].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[3].sv_id.sat_id, 153,
                    "incorrect value for stec_sat_list[3].sv_id.sat_id, expected 153, is {}",
                    msg.stec_sat_list[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[0], 27486,
                    "incorrect value for stec_sat_list[4].stec_coeff[0], expected 27486, is {}",
                    msg.stec_sat_list[4].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[1], 23329,
                    "incorrect value for stec_sat_list[4].stec_coeff[1], expected 23329, is {}",
                    msg.stec_sat_list[4].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[2], 234,
                    "incorrect value for stec_sat_list[4].stec_coeff[2], expected 234, is {}",
                    msg.stec_sat_list[4].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[3], -29739,
                    "incorrect value for stec_sat_list[4].stec_coeff[3], expected -29739, is {}",
                    msg.stec_sat_list[4].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[4].stec_quality_indicator, 250, "incorrect value for stec_sat_list[4].stec_quality_indicator, expected 250, is {}", msg.stec_sat_list[4].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[4].sv_id.constellation, 107,
                    "incorrect value for stec_sat_list[4].sv_id.constellation, expected 107, is {}",
                    msg.stec_sat_list[4].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[4].sv_id.sat_id, 14,
                    "incorrect value for stec_sat_list[4].sv_id.sat_id, expected 14, is {}",
                    msg.stec_sat_list[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[0], 18965,
                    "incorrect value for stec_sat_list[5].stec_coeff[0], expected 18965, is {}",
                    msg.stec_sat_list[5].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[1], -22098,
                    "incorrect value for stec_sat_list[5].stec_coeff[1], expected -22098, is {}",
                    msg.stec_sat_list[5].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[2], 22077,
                    "incorrect value for stec_sat_list[5].stec_coeff[2], expected 22077, is {}",
                    msg.stec_sat_list[5].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[3], -29093,
                    "incorrect value for stec_sat_list[5].stec_coeff[3], expected -29093, is {}",
                    msg.stec_sat_list[5].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[5].stec_quality_indicator, 50, "incorrect value for stec_sat_list[5].stec_quality_indicator, expected 50, is {}", msg.stec_sat_list[5].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[5].sv_id.constellation, 179,
                    "incorrect value for stec_sat_list[5].sv_id.constellation, expected 179, is {}",
                    msg.stec_sat_list[5].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[5].sv_id.sat_id, 95,
                    "incorrect value for stec_sat_list[5].sv_id.sat_id, expected 95, is {}",
                    msg.stec_sat_list[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[0], -7898,
                    "incorrect value for stec_sat_list[6].stec_coeff[0], expected -7898, is {}",
                    msg.stec_sat_list[6].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[1], 26002,
                    "incorrect value for stec_sat_list[6].stec_coeff[1], expected 26002, is {}",
                    msg.stec_sat_list[6].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[2], -29879,
                    "incorrect value for stec_sat_list[6].stec_coeff[2], expected -29879, is {}",
                    msg.stec_sat_list[6].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[3], 30008,
                    "incorrect value for stec_sat_list[6].stec_coeff[3], expected 30008, is {}",
                    msg.stec_sat_list[6].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[6].stec_quality_indicator, 9, "incorrect value for stec_sat_list[6].stec_quality_indicator, expected 9, is {}", msg.stec_sat_list[6].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[6].sv_id.constellation, 108,
                    "incorrect value for stec_sat_list[6].sv_id.constellation, expected 108, is {}",
                    msg.stec_sat_list[6].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[6].sv_id.sat_id, 51,
                    "incorrect value for stec_sat_list[6].sv_id.sat_id, expected 51, is {}",
                    msg.stec_sat_list[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[0], -12948,
                    "incorrect value for stec_sat_list[7].stec_coeff[0], expected -12948, is {}",
                    msg.stec_sat_list[7].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[1], 4701,
                    "incorrect value for stec_sat_list[7].stec_coeff[1], expected 4701, is {}",
                    msg.stec_sat_list[7].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[2], -15597,
                    "incorrect value for stec_sat_list[7].stec_coeff[2], expected -15597, is {}",
                    msg.stec_sat_list[7].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[3], -13791,
                    "incorrect value for stec_sat_list[7].stec_coeff[3], expected -13791, is {}",
                    msg.stec_sat_list[7].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[7].stec_quality_indicator, 213, "incorrect value for stec_sat_list[7].stec_quality_indicator, expected 213, is {}", msg.stec_sat_list[7].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[7].sv_id.constellation, 37,
                    "incorrect value for stec_sat_list[7].sv_id.constellation, expected 37, is {}",
                    msg.stec_sat_list[7].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[7].sv_id.sat_id, 82,
                    "incorrect value for stec_sat_list[7].sv_id.sat_id, expected 82, is {}",
                    msg.stec_sat_list[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[0], -17283,
                    "incorrect value for stec_sat_list[8].stec_coeff[0], expected -17283, is {}",
                    msg.stec_sat_list[8].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[1], 14455,
                    "incorrect value for stec_sat_list[8].stec_coeff[1], expected 14455, is {}",
                    msg.stec_sat_list[8].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[2], -27067,
                    "incorrect value for stec_sat_list[8].stec_coeff[2], expected -27067, is {}",
                    msg.stec_sat_list[8].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[3], 19606,
                    "incorrect value for stec_sat_list[8].stec_coeff[3], expected 19606, is {}",
                    msg.stec_sat_list[8].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[8].stec_quality_indicator, 178, "incorrect value for stec_sat_list[8].stec_quality_indicator, expected 178, is {}", msg.stec_sat_list[8].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[8].sv_id.constellation, 206,
                    "incorrect value for stec_sat_list[8].sv_id.constellation, expected 206, is {}",
                    msg.stec_sat_list[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[8].sv_id.sat_id, 87,
                    "incorrect value for stec_sat_list[8].sv_id.sat_id, expected 87, is {}",
                    msg.stec_sat_list[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[0], -12215,
                    "incorrect value for stec_sat_list[9].stec_coeff[0], expected -12215, is {}",
                    msg.stec_sat_list[9].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[1], -6072,
                    "incorrect value for stec_sat_list[9].stec_coeff[1], expected -6072, is {}",
                    msg.stec_sat_list[9].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[2], -1528,
                    "incorrect value for stec_sat_list[9].stec_coeff[2], expected -1528, is {}",
                    msg.stec_sat_list[9].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[3], -19765,
                    "incorrect value for stec_sat_list[9].stec_coeff[3], expected -19765, is {}",
                    msg.stec_sat_list[9].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[9].stec_quality_indicator, 18, "incorrect value for stec_sat_list[9].stec_quality_indicator, expected 18, is {}", msg.stec_sat_list[9].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[9].sv_id.constellation, 131,
                    "incorrect value for stec_sat_list[9].sv_id.constellation, expected 131, is {}",
                    msg.stec_sat_list[9].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[9].sv_id.sat_id, 3,
                    "incorrect value for stec_sat_list[9].sv_id.sat_id, expected 3, is {}",
                    msg.stec_sat_list[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[0], 12630,
                    "incorrect value for stec_sat_list[10].stec_coeff[0], expected 12630, is {}",
                    msg.stec_sat_list[10].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[1], -19721,
                    "incorrect value for stec_sat_list[10].stec_coeff[1], expected -19721, is {}",
                    msg.stec_sat_list[10].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[2], 14502,
                    "incorrect value for stec_sat_list[10].stec_coeff[2], expected 14502, is {}",
                    msg.stec_sat_list[10].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[3], 2591,
                    "incorrect value for stec_sat_list[10].stec_coeff[3], expected 2591, is {}",
                    msg.stec_sat_list[10].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[10].stec_quality_indicator, 252, "incorrect value for stec_sat_list[10].stec_quality_indicator, expected 252, is {}", msg.stec_sat_list[10].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[10].sv_id.constellation, 163, "incorrect value for stec_sat_list[10].sv_id.constellation, expected 163, is {}", msg.stec_sat_list[10].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[10].sv_id.sat_id, 170,
                    "incorrect value for stec_sat_list[10].sv_id.sat_id, expected 170, is {}",
                    msg.stec_sat_list[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[0], -23340,
                    "incorrect value for stec_sat_list[11].stec_coeff[0], expected -23340, is {}",
                    msg.stec_sat_list[11].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[1], -24063,
                    "incorrect value for stec_sat_list[11].stec_coeff[1], expected -24063, is {}",
                    msg.stec_sat_list[11].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[2], 4650,
                    "incorrect value for stec_sat_list[11].stec_coeff[2], expected 4650, is {}",
                    msg.stec_sat_list[11].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[3], -22148,
                    "incorrect value for stec_sat_list[11].stec_coeff[3], expected -22148, is {}",
                    msg.stec_sat_list[11].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[11].stec_quality_indicator, 241, "incorrect value for stec_sat_list[11].stec_quality_indicator, expected 241, is {}", msg.stec_sat_list[11].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[11].sv_id.constellation, 213, "incorrect value for stec_sat_list[11].sv_id.constellation, expected 213, is {}", msg.stec_sat_list[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[11].sv_id.sat_id, 119,
                    "incorrect value for stec_sat_list[11].sv_id.sat_id, expected 119, is {}",
                    msg.stec_sat_list[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[0], 5944,
                    "incorrect value for stec_sat_list[12].stec_coeff[0], expected 5944, is {}",
                    msg.stec_sat_list[12].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[1], 32142,
                    "incorrect value for stec_sat_list[12].stec_coeff[1], expected 32142, is {}",
                    msg.stec_sat_list[12].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[2], 30760,
                    "incorrect value for stec_sat_list[12].stec_coeff[2], expected 30760, is {}",
                    msg.stec_sat_list[12].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[3], 11587,
                    "incorrect value for stec_sat_list[12].stec_coeff[3], expected 11587, is {}",
                    msg.stec_sat_list[12].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[12].stec_quality_indicator, 26, "incorrect value for stec_sat_list[12].stec_quality_indicator, expected 26, is {}", msg.stec_sat_list[12].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[12].sv_id.constellation, 158, "incorrect value for stec_sat_list[12].sv_id.constellation, expected 158, is {}", msg.stec_sat_list[12].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[12].sv_id.sat_id, 121,
                    "incorrect value for stec_sat_list[12].sv_id.sat_id, expected 121, is {}",
                    msg.stec_sat_list[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[0], 3095,
                    "incorrect value for stec_sat_list[13].stec_coeff[0], expected 3095, is {}",
                    msg.stec_sat_list[13].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[1], 22769,
                    "incorrect value for stec_sat_list[13].stec_coeff[1], expected 22769, is {}",
                    msg.stec_sat_list[13].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[2], -4283,
                    "incorrect value for stec_sat_list[13].stec_coeff[2], expected -4283, is {}",
                    msg.stec_sat_list[13].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[3], 14844,
                    "incorrect value for stec_sat_list[13].stec_coeff[3], expected 14844, is {}",
                    msg.stec_sat_list[13].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[13].stec_quality_indicator, 110, "incorrect value for stec_sat_list[13].stec_quality_indicator, expected 110, is {}", msg.stec_sat_list[13].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[13].sv_id.constellation, 235, "incorrect value for stec_sat_list[13].sv_id.constellation, expected 235, is {}", msg.stec_sat_list[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[13].sv_id.sat_id, 126,
                    "incorrect value for stec_sat_list[13].sv_id.sat_id, expected 126, is {}",
                    msg.stec_sat_list[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[0], -21032,
                    "incorrect value for stec_sat_list[14].stec_coeff[0], expected -21032, is {}",
                    msg.stec_sat_list[14].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[1], -19726,
                    "incorrect value for stec_sat_list[14].stec_coeff[1], expected -19726, is {}",
                    msg.stec_sat_list[14].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[2], 1297,
                    "incorrect value for stec_sat_list[14].stec_coeff[2], expected 1297, is {}",
                    msg.stec_sat_list[14].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[3], -22049,
                    "incorrect value for stec_sat_list[14].stec_coeff[3], expected -22049, is {}",
                    msg.stec_sat_list[14].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[14].stec_quality_indicator, 201, "incorrect value for stec_sat_list[14].stec_quality_indicator, expected 201, is {}", msg.stec_sat_list[14].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[14].sv_id.constellation, 44,
                    "incorrect value for stec_sat_list[14].sv_id.constellation, expected 44, is {}",
                    msg.stec_sat_list[14].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[14].sv_id.sat_id, 93,
                    "incorrect value for stec_sat_list[14].sv_id.sat_id, expected 93, is {}",
                    msg.stec_sat_list[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[0], 619,
                    "incorrect value for stec_sat_list[15].stec_coeff[0], expected 619, is {}",
                    msg.stec_sat_list[15].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[1], -5744,
                    "incorrect value for stec_sat_list[15].stec_coeff[1], expected -5744, is {}",
                    msg.stec_sat_list[15].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[2], 22542,
                    "incorrect value for stec_sat_list[15].stec_coeff[2], expected 22542, is {}",
                    msg.stec_sat_list[15].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[3], -12000,
                    "incorrect value for stec_sat_list[15].stec_coeff[3], expected -12000, is {}",
                    msg.stec_sat_list[15].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[15].stec_quality_indicator, 77, "incorrect value for stec_sat_list[15].stec_quality_indicator, expected 77, is {}", msg.stec_sat_list[15].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[15].sv_id.constellation, 3,
                    "incorrect value for stec_sat_list[15].sv_id.constellation, expected 3, is {}",
                    msg.stec_sat_list[15].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[15].sv_id.sat_id, 192,
                    "incorrect value for stec_sat_list[15].sv_id.sat_id, expected 192, is {}",
                    msg.stec_sat_list[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[0], 10651,
                    "incorrect value for stec_sat_list[16].stec_coeff[0], expected 10651, is {}",
                    msg.stec_sat_list[16].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[1], -2889,
                    "incorrect value for stec_sat_list[16].stec_coeff[1], expected -2889, is {}",
                    msg.stec_sat_list[16].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[2], 21150,
                    "incorrect value for stec_sat_list[16].stec_coeff[2], expected 21150, is {}",
                    msg.stec_sat_list[16].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[3], 26421,
                    "incorrect value for stec_sat_list[16].stec_coeff[3], expected 26421, is {}",
                    msg.stec_sat_list[16].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[16].stec_quality_indicator, 123, "incorrect value for stec_sat_list[16].stec_quality_indicator, expected 123, is {}", msg.stec_sat_list[16].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[16].sv_id.constellation, 17,
                    "incorrect value for stec_sat_list[16].sv_id.constellation, expected 17, is {}",
                    msg.stec_sat_list[16].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[16].sv_id.sat_id, 1,
                    "incorrect value for stec_sat_list[16].sv_id.sat_id, expected 1, is {}",
                    msg.stec_sat_list[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[0], -19165,
                    "incorrect value for stec_sat_list[17].stec_coeff[0], expected -19165, is {}",
                    msg.stec_sat_list[17].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[1], 30229,
                    "incorrect value for stec_sat_list[17].stec_coeff[1], expected 30229, is {}",
                    msg.stec_sat_list[17].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[2], -1282,
                    "incorrect value for stec_sat_list[17].stec_coeff[2], expected -1282, is {}",
                    msg.stec_sat_list[17].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[3], -18382,
                    "incorrect value for stec_sat_list[17].stec_coeff[3], expected -18382, is {}",
                    msg.stec_sat_list[17].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[17].stec_quality_indicator, 185, "incorrect value for stec_sat_list[17].stec_quality_indicator, expected 185, is {}", msg.stec_sat_list[17].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[17].sv_id.constellation, 202, "incorrect value for stec_sat_list[17].sv_id.constellation, expected 202, is {}", msg.stec_sat_list[17].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[17].sv_id.sat_id, 14,
                    "incorrect value for stec_sat_list[17].sv_id.sat_id, expected 14, is {}",
                    msg.stec_sat_list[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[0], -23752,
                    "incorrect value for stec_sat_list[18].stec_coeff[0], expected -23752, is {}",
                    msg.stec_sat_list[18].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[1], 32433,
                    "incorrect value for stec_sat_list[18].stec_coeff[1], expected 32433, is {}",
                    msg.stec_sat_list[18].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[2], 20441,
                    "incorrect value for stec_sat_list[18].stec_coeff[2], expected 20441, is {}",
                    msg.stec_sat_list[18].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[3], -4181,
                    "incorrect value for stec_sat_list[18].stec_coeff[3], expected -4181, is {}",
                    msg.stec_sat_list[18].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[18].stec_quality_indicator, 45, "incorrect value for stec_sat_list[18].stec_quality_indicator, expected 45, is {}", msg.stec_sat_list[18].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[18].sv_id.constellation, 31,
                    "incorrect value for stec_sat_list[18].sv_id.constellation, expected 31, is {}",
                    msg.stec_sat_list[18].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[18].sv_id.sat_id, 50,
                    "incorrect value for stec_sat_list[18].sv_id.sat_id, expected 50, is {}",
                    msg.stec_sat_list[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[0], -13968,
                    "incorrect value for stec_sat_list[19].stec_coeff[0], expected -13968, is {}",
                    msg.stec_sat_list[19].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[1], -29322,
                    "incorrect value for stec_sat_list[19].stec_coeff[1], expected -29322, is {}",
                    msg.stec_sat_list[19].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[2], -23790,
                    "incorrect value for stec_sat_list[19].stec_coeff[2], expected -23790, is {}",
                    msg.stec_sat_list[19].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[3], 9063,
                    "incorrect value for stec_sat_list[19].stec_coeff[3], expected 9063, is {}",
                    msg.stec_sat_list[19].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[19].stec_quality_indicator, 238, "incorrect value for stec_sat_list[19].stec_quality_indicator, expected 238, is {}", msg.stec_sat_list[19].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[19].sv_id.constellation, 188, "incorrect value for stec_sat_list[19].sv_id.constellation, expected 188, is {}", msg.stec_sat_list[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[19].sv_id.sat_id, 237,
                    "incorrect value for stec_sat_list[19].sv_id.sat_id, expected 237, is {}",
                    msg.stec_sat_list[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[0], 4737,
                    "incorrect value for stec_sat_list[20].stec_coeff[0], expected 4737, is {}",
                    msg.stec_sat_list[20].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[1], 21877,
                    "incorrect value for stec_sat_list[20].stec_coeff[1], expected 21877, is {}",
                    msg.stec_sat_list[20].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[2], 20414,
                    "incorrect value for stec_sat_list[20].stec_coeff[2], expected 20414, is {}",
                    msg.stec_sat_list[20].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[3], -10286,
                    "incorrect value for stec_sat_list[20].stec_coeff[3], expected -10286, is {}",
                    msg.stec_sat_list[20].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[20].stec_quality_indicator, 82, "incorrect value for stec_sat_list[20].stec_quality_indicator, expected 82, is {}", msg.stec_sat_list[20].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[20].sv_id.constellation, 21,
                    "incorrect value for stec_sat_list[20].sv_id.constellation, expected 21, is {}",
                    msg.stec_sat_list[20].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[20].sv_id.sat_id, 63,
                    "incorrect value for stec_sat_list[20].sv_id.sat_id, expected 63, is {}",
                    msg.stec_sat_list[20].sv_id.sat_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrStecCorrectionDep"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_stec_correction_dep`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_stec_correction_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 251, 5, 204, 151, 245, 158, 228, 114, 117, 50, 158, 156, 42, 119, 156, 157, 112,
            47, 60, 132, 40, 70, 87, 235, 83, 177, 198, 3, 14, 8, 70, 12, 44, 53, 181, 90, 174,
            247, 150, 58, 172, 247, 179, 119, 176, 125, 4, 177, 229, 113, 14, 77, 153, 185, 23, 53,
            222, 187, 146, 250, 91, 212, 215, 14, 107, 250, 94, 107, 33, 91, 234, 0, 213, 139, 95,
            179, 50, 21, 74, 174, 169, 61, 86, 91, 142, 51, 108, 9, 38, 225, 146, 101, 73, 139, 56,
            117, 82, 37, 213, 108, 205, 93, 18, 19, 195, 33, 202, 87, 206, 178, 125, 188, 119, 56,
            69, 150, 150, 76, 3, 131, 18, 73, 208, 72, 232, 8, 250, 203, 178, 170, 163, 252, 86,
            49, 247, 178, 166, 56, 31, 10, 119, 213, 241, 212, 164, 1, 162, 42, 18, 124, 169, 121,
            158, 26, 56, 23, 142, 125, 40, 120, 67, 45, 126, 235, 110, 23, 12, 241, 88, 69, 239,
            252, 57, 93, 44, 201, 216, 173, 242, 178, 17, 5, 223, 169, 192, 3, 77, 107, 2, 144,
            233, 14, 88, 32, 209, 1, 17, 123, 155, 41, 183, 244, 158, 82, 53, 103, 14, 202, 185,
            35, 181, 21, 118, 254, 250, 50, 184, 50, 31, 45, 56, 163, 177, 126, 217, 79, 171, 239,
            237, 188, 238, 112, 201, 118, 141, 18, 163, 103, 35, 63, 21, 82, 129, 18, 117, 85, 190,
            79, 210, 215, 227, 177,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrStecCorrectionDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrStecCorrectionDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5fb,
                    "Incorrect message type, expected 0x5fb, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x97cc,
                    "incorrect sender id, expected 0x97cc, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 60,
                    "incorrect value for header.iod_atmo, expected 60, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 157,
                    "incorrect value for header.num_msgs, expected 157, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 112,
                    "incorrect value for header.seq_num, expected 112, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.tile_id, 30066,
                    "incorrect value for header.tile_id, expected 30066, is {}",
                    msg.header.tile_id
                );
                assert_eq!(
                    msg.header.tile_set_id, 58526,
                    "incorrect value for header.tile_set_id, expected 58526, is {}",
                    msg.header.tile_set_id
                );
                assert_eq!(
                    msg.header.time.tow, 714907186,
                    "incorrect value for header.time.tow, expected 714907186, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 40055,
                    "incorrect value for header.time.wn, expected 40055, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.update_interval, 47,
                    "incorrect value for header.update_interval, expected 47, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[0], -5289,
                    "incorrect value for stec_sat_list[0].stec_coeff[0], expected -5289, is {}",
                    msg.stec_sat_list[0].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[1], -20141,
                    "incorrect value for stec_sat_list[0].stec_coeff[1], expected -20141, is {}",
                    msg.stec_sat_list[0].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[2], 966,
                    "incorrect value for stec_sat_list[0].stec_coeff[2], expected 966, is {}",
                    msg.stec_sat_list[0].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[3], 2062,
                    "incorrect value for stec_sat_list[0].stec_coeff[3], expected 2062, is {}",
                    msg.stec_sat_list[0].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[0].stec_quality_indicator, 70, "incorrect value for stec_sat_list[0].stec_quality_indicator, expected 70, is {}", msg.stec_sat_list[0].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.constellation, 40,
                    "incorrect value for stec_sat_list[0].sv_id.constellation, expected 40, is {}",
                    msg.stec_sat_list[0].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.sat_id, 132,
                    "incorrect value for stec_sat_list[0].sv_id.sat_id, expected 132, is {}",
                    msg.stec_sat_list[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[0], -19147,
                    "incorrect value for stec_sat_list[1].stec_coeff[0], expected -19147, is {}",
                    msg.stec_sat_list[1].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[1], -20902,
                    "incorrect value for stec_sat_list[1].stec_coeff[1], expected -20902, is {}",
                    msg.stec_sat_list[1].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[2], -26889,
                    "incorrect value for stec_sat_list[1].stec_coeff[2], expected -26889, is {}",
                    msg.stec_sat_list[1].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[3], -21446,
                    "incorrect value for stec_sat_list[1].stec_coeff[3], expected -21446, is {}",
                    msg.stec_sat_list[1].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[1].stec_quality_indicator, 44, "incorrect value for stec_sat_list[1].stec_quality_indicator, expected 44, is {}", msg.stec_sat_list[1].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.constellation, 12,
                    "incorrect value for stec_sat_list[1].sv_id.constellation, expected 12, is {}",
                    msg.stec_sat_list[1].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.sat_id, 70,
                    "incorrect value for stec_sat_list[1].sv_id.sat_id, expected 70, is {}",
                    msg.stec_sat_list[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[0], 32176,
                    "incorrect value for stec_sat_list[2].stec_coeff[0], expected 32176, is {}",
                    msg.stec_sat_list[2].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[1], -20220,
                    "incorrect value for stec_sat_list[2].stec_coeff[1], expected -20220, is {}",
                    msg.stec_sat_list[2].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[2], 29157,
                    "incorrect value for stec_sat_list[2].stec_coeff[2], expected 29157, is {}",
                    msg.stec_sat_list[2].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[2].stec_coeff[3], 19726,
                    "incorrect value for stec_sat_list[2].stec_coeff[3], expected 19726, is {}",
                    msg.stec_sat_list[2].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[2].stec_quality_indicator, 119, "incorrect value for stec_sat_list[2].stec_quality_indicator, expected 119, is {}", msg.stec_sat_list[2].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[2].sv_id.constellation, 179,
                    "incorrect value for stec_sat_list[2].sv_id.constellation, expected 179, is {}",
                    msg.stec_sat_list[2].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[2].sv_id.sat_id, 247,
                    "incorrect value for stec_sat_list[2].sv_id.sat_id, expected 247, is {}",
                    msg.stec_sat_list[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[0], -8651,
                    "incorrect value for stec_sat_list[3].stec_coeff[0], expected -8651, is {}",
                    msg.stec_sat_list[3].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[1], -27973,
                    "incorrect value for stec_sat_list[3].stec_coeff[1], expected -27973, is {}",
                    msg.stec_sat_list[3].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[2], 23546,
                    "incorrect value for stec_sat_list[3].stec_coeff[2], expected 23546, is {}",
                    msg.stec_sat_list[3].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[3].stec_coeff[3], -10284,
                    "incorrect value for stec_sat_list[3].stec_coeff[3], expected -10284, is {}",
                    msg.stec_sat_list[3].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[3].stec_quality_indicator, 23, "incorrect value for stec_sat_list[3].stec_quality_indicator, expected 23, is {}", msg.stec_sat_list[3].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[3].sv_id.constellation, 185,
                    "incorrect value for stec_sat_list[3].sv_id.constellation, expected 185, is {}",
                    msg.stec_sat_list[3].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[3].sv_id.sat_id, 153,
                    "incorrect value for stec_sat_list[3].sv_id.sat_id, expected 153, is {}",
                    msg.stec_sat_list[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[0], 27486,
                    "incorrect value for stec_sat_list[4].stec_coeff[0], expected 27486, is {}",
                    msg.stec_sat_list[4].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[1], 23329,
                    "incorrect value for stec_sat_list[4].stec_coeff[1], expected 23329, is {}",
                    msg.stec_sat_list[4].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[2], 234,
                    "incorrect value for stec_sat_list[4].stec_coeff[2], expected 234, is {}",
                    msg.stec_sat_list[4].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[4].stec_coeff[3], -29739,
                    "incorrect value for stec_sat_list[4].stec_coeff[3], expected -29739, is {}",
                    msg.stec_sat_list[4].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[4].stec_quality_indicator, 250, "incorrect value for stec_sat_list[4].stec_quality_indicator, expected 250, is {}", msg.stec_sat_list[4].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[4].sv_id.constellation, 107,
                    "incorrect value for stec_sat_list[4].sv_id.constellation, expected 107, is {}",
                    msg.stec_sat_list[4].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[4].sv_id.sat_id, 14,
                    "incorrect value for stec_sat_list[4].sv_id.sat_id, expected 14, is {}",
                    msg.stec_sat_list[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[0], 18965,
                    "incorrect value for stec_sat_list[5].stec_coeff[0], expected 18965, is {}",
                    msg.stec_sat_list[5].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[1], -22098,
                    "incorrect value for stec_sat_list[5].stec_coeff[1], expected -22098, is {}",
                    msg.stec_sat_list[5].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[2], 22077,
                    "incorrect value for stec_sat_list[5].stec_coeff[2], expected 22077, is {}",
                    msg.stec_sat_list[5].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[5].stec_coeff[3], -29093,
                    "incorrect value for stec_sat_list[5].stec_coeff[3], expected -29093, is {}",
                    msg.stec_sat_list[5].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[5].stec_quality_indicator, 50, "incorrect value for stec_sat_list[5].stec_quality_indicator, expected 50, is {}", msg.stec_sat_list[5].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[5].sv_id.constellation, 179,
                    "incorrect value for stec_sat_list[5].sv_id.constellation, expected 179, is {}",
                    msg.stec_sat_list[5].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[5].sv_id.sat_id, 95,
                    "incorrect value for stec_sat_list[5].sv_id.sat_id, expected 95, is {}",
                    msg.stec_sat_list[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[0], -7898,
                    "incorrect value for stec_sat_list[6].stec_coeff[0], expected -7898, is {}",
                    msg.stec_sat_list[6].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[1], 26002,
                    "incorrect value for stec_sat_list[6].stec_coeff[1], expected 26002, is {}",
                    msg.stec_sat_list[6].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[2], -29879,
                    "incorrect value for stec_sat_list[6].stec_coeff[2], expected -29879, is {}",
                    msg.stec_sat_list[6].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[6].stec_coeff[3], 30008,
                    "incorrect value for stec_sat_list[6].stec_coeff[3], expected 30008, is {}",
                    msg.stec_sat_list[6].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[6].stec_quality_indicator, 9, "incorrect value for stec_sat_list[6].stec_quality_indicator, expected 9, is {}", msg.stec_sat_list[6].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[6].sv_id.constellation, 108,
                    "incorrect value for stec_sat_list[6].sv_id.constellation, expected 108, is {}",
                    msg.stec_sat_list[6].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[6].sv_id.sat_id, 51,
                    "incorrect value for stec_sat_list[6].sv_id.sat_id, expected 51, is {}",
                    msg.stec_sat_list[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[0], -12948,
                    "incorrect value for stec_sat_list[7].stec_coeff[0], expected -12948, is {}",
                    msg.stec_sat_list[7].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[1], 4701,
                    "incorrect value for stec_sat_list[7].stec_coeff[1], expected 4701, is {}",
                    msg.stec_sat_list[7].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[2], -15597,
                    "incorrect value for stec_sat_list[7].stec_coeff[2], expected -15597, is {}",
                    msg.stec_sat_list[7].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[7].stec_coeff[3], -13791,
                    "incorrect value for stec_sat_list[7].stec_coeff[3], expected -13791, is {}",
                    msg.stec_sat_list[7].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[7].stec_quality_indicator, 213, "incorrect value for stec_sat_list[7].stec_quality_indicator, expected 213, is {}", msg.stec_sat_list[7].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[7].sv_id.constellation, 37,
                    "incorrect value for stec_sat_list[7].sv_id.constellation, expected 37, is {}",
                    msg.stec_sat_list[7].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[7].sv_id.sat_id, 82,
                    "incorrect value for stec_sat_list[7].sv_id.sat_id, expected 82, is {}",
                    msg.stec_sat_list[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[0], -17283,
                    "incorrect value for stec_sat_list[8].stec_coeff[0], expected -17283, is {}",
                    msg.stec_sat_list[8].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[1], 14455,
                    "incorrect value for stec_sat_list[8].stec_coeff[1], expected 14455, is {}",
                    msg.stec_sat_list[8].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[2], -27067,
                    "incorrect value for stec_sat_list[8].stec_coeff[2], expected -27067, is {}",
                    msg.stec_sat_list[8].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[8].stec_coeff[3], 19606,
                    "incorrect value for stec_sat_list[8].stec_coeff[3], expected 19606, is {}",
                    msg.stec_sat_list[8].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[8].stec_quality_indicator, 178, "incorrect value for stec_sat_list[8].stec_quality_indicator, expected 178, is {}", msg.stec_sat_list[8].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[8].sv_id.constellation, 206,
                    "incorrect value for stec_sat_list[8].sv_id.constellation, expected 206, is {}",
                    msg.stec_sat_list[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[8].sv_id.sat_id, 87,
                    "incorrect value for stec_sat_list[8].sv_id.sat_id, expected 87, is {}",
                    msg.stec_sat_list[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[0], -12215,
                    "incorrect value for stec_sat_list[9].stec_coeff[0], expected -12215, is {}",
                    msg.stec_sat_list[9].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[1], -6072,
                    "incorrect value for stec_sat_list[9].stec_coeff[1], expected -6072, is {}",
                    msg.stec_sat_list[9].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[2], -1528,
                    "incorrect value for stec_sat_list[9].stec_coeff[2], expected -1528, is {}",
                    msg.stec_sat_list[9].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[9].stec_coeff[3], -19765,
                    "incorrect value for stec_sat_list[9].stec_coeff[3], expected -19765, is {}",
                    msg.stec_sat_list[9].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[9].stec_quality_indicator, 18, "incorrect value for stec_sat_list[9].stec_quality_indicator, expected 18, is {}", msg.stec_sat_list[9].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[9].sv_id.constellation, 131,
                    "incorrect value for stec_sat_list[9].sv_id.constellation, expected 131, is {}",
                    msg.stec_sat_list[9].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[9].sv_id.sat_id, 3,
                    "incorrect value for stec_sat_list[9].sv_id.sat_id, expected 3, is {}",
                    msg.stec_sat_list[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[0], 12630,
                    "incorrect value for stec_sat_list[10].stec_coeff[0], expected 12630, is {}",
                    msg.stec_sat_list[10].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[1], -19721,
                    "incorrect value for stec_sat_list[10].stec_coeff[1], expected -19721, is {}",
                    msg.stec_sat_list[10].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[2], 14502,
                    "incorrect value for stec_sat_list[10].stec_coeff[2], expected 14502, is {}",
                    msg.stec_sat_list[10].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[10].stec_coeff[3], 2591,
                    "incorrect value for stec_sat_list[10].stec_coeff[3], expected 2591, is {}",
                    msg.stec_sat_list[10].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[10].stec_quality_indicator, 252, "incorrect value for stec_sat_list[10].stec_quality_indicator, expected 252, is {}", msg.stec_sat_list[10].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[10].sv_id.constellation, 163, "incorrect value for stec_sat_list[10].sv_id.constellation, expected 163, is {}", msg.stec_sat_list[10].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[10].sv_id.sat_id, 170,
                    "incorrect value for stec_sat_list[10].sv_id.sat_id, expected 170, is {}",
                    msg.stec_sat_list[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[0], -23340,
                    "incorrect value for stec_sat_list[11].stec_coeff[0], expected -23340, is {}",
                    msg.stec_sat_list[11].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[1], -24063,
                    "incorrect value for stec_sat_list[11].stec_coeff[1], expected -24063, is {}",
                    msg.stec_sat_list[11].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[2], 4650,
                    "incorrect value for stec_sat_list[11].stec_coeff[2], expected 4650, is {}",
                    msg.stec_sat_list[11].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[11].stec_coeff[3], -22148,
                    "incorrect value for stec_sat_list[11].stec_coeff[3], expected -22148, is {}",
                    msg.stec_sat_list[11].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[11].stec_quality_indicator, 241, "incorrect value for stec_sat_list[11].stec_quality_indicator, expected 241, is {}", msg.stec_sat_list[11].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[11].sv_id.constellation, 213, "incorrect value for stec_sat_list[11].sv_id.constellation, expected 213, is {}", msg.stec_sat_list[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[11].sv_id.sat_id, 119,
                    "incorrect value for stec_sat_list[11].sv_id.sat_id, expected 119, is {}",
                    msg.stec_sat_list[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[0], 5944,
                    "incorrect value for stec_sat_list[12].stec_coeff[0], expected 5944, is {}",
                    msg.stec_sat_list[12].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[1], 32142,
                    "incorrect value for stec_sat_list[12].stec_coeff[1], expected 32142, is {}",
                    msg.stec_sat_list[12].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[2], 30760,
                    "incorrect value for stec_sat_list[12].stec_coeff[2], expected 30760, is {}",
                    msg.stec_sat_list[12].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[12].stec_coeff[3], 11587,
                    "incorrect value for stec_sat_list[12].stec_coeff[3], expected 11587, is {}",
                    msg.stec_sat_list[12].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[12].stec_quality_indicator, 26, "incorrect value for stec_sat_list[12].stec_quality_indicator, expected 26, is {}", msg.stec_sat_list[12].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[12].sv_id.constellation, 158, "incorrect value for stec_sat_list[12].sv_id.constellation, expected 158, is {}", msg.stec_sat_list[12].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[12].sv_id.sat_id, 121,
                    "incorrect value for stec_sat_list[12].sv_id.sat_id, expected 121, is {}",
                    msg.stec_sat_list[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[0], 3095,
                    "incorrect value for stec_sat_list[13].stec_coeff[0], expected 3095, is {}",
                    msg.stec_sat_list[13].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[1], 22769,
                    "incorrect value for stec_sat_list[13].stec_coeff[1], expected 22769, is {}",
                    msg.stec_sat_list[13].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[2], -4283,
                    "incorrect value for stec_sat_list[13].stec_coeff[2], expected -4283, is {}",
                    msg.stec_sat_list[13].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[13].stec_coeff[3], 14844,
                    "incorrect value for stec_sat_list[13].stec_coeff[3], expected 14844, is {}",
                    msg.stec_sat_list[13].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[13].stec_quality_indicator, 110, "incorrect value for stec_sat_list[13].stec_quality_indicator, expected 110, is {}", msg.stec_sat_list[13].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[13].sv_id.constellation, 235, "incorrect value for stec_sat_list[13].sv_id.constellation, expected 235, is {}", msg.stec_sat_list[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[13].sv_id.sat_id, 126,
                    "incorrect value for stec_sat_list[13].sv_id.sat_id, expected 126, is {}",
                    msg.stec_sat_list[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[0], -21032,
                    "incorrect value for stec_sat_list[14].stec_coeff[0], expected -21032, is {}",
                    msg.stec_sat_list[14].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[1], -19726,
                    "incorrect value for stec_sat_list[14].stec_coeff[1], expected -19726, is {}",
                    msg.stec_sat_list[14].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[2], 1297,
                    "incorrect value for stec_sat_list[14].stec_coeff[2], expected 1297, is {}",
                    msg.stec_sat_list[14].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[14].stec_coeff[3], -22049,
                    "incorrect value for stec_sat_list[14].stec_coeff[3], expected -22049, is {}",
                    msg.stec_sat_list[14].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[14].stec_quality_indicator, 201, "incorrect value for stec_sat_list[14].stec_quality_indicator, expected 201, is {}", msg.stec_sat_list[14].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[14].sv_id.constellation, 44,
                    "incorrect value for stec_sat_list[14].sv_id.constellation, expected 44, is {}",
                    msg.stec_sat_list[14].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[14].sv_id.sat_id, 93,
                    "incorrect value for stec_sat_list[14].sv_id.sat_id, expected 93, is {}",
                    msg.stec_sat_list[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[0], 619,
                    "incorrect value for stec_sat_list[15].stec_coeff[0], expected 619, is {}",
                    msg.stec_sat_list[15].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[1], -5744,
                    "incorrect value for stec_sat_list[15].stec_coeff[1], expected -5744, is {}",
                    msg.stec_sat_list[15].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[2], 22542,
                    "incorrect value for stec_sat_list[15].stec_coeff[2], expected 22542, is {}",
                    msg.stec_sat_list[15].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[15].stec_coeff[3], -12000,
                    "incorrect value for stec_sat_list[15].stec_coeff[3], expected -12000, is {}",
                    msg.stec_sat_list[15].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[15].stec_quality_indicator, 77, "incorrect value for stec_sat_list[15].stec_quality_indicator, expected 77, is {}", msg.stec_sat_list[15].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[15].sv_id.constellation, 3,
                    "incorrect value for stec_sat_list[15].sv_id.constellation, expected 3, is {}",
                    msg.stec_sat_list[15].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[15].sv_id.sat_id, 192,
                    "incorrect value for stec_sat_list[15].sv_id.sat_id, expected 192, is {}",
                    msg.stec_sat_list[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[0], 10651,
                    "incorrect value for stec_sat_list[16].stec_coeff[0], expected 10651, is {}",
                    msg.stec_sat_list[16].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[1], -2889,
                    "incorrect value for stec_sat_list[16].stec_coeff[1], expected -2889, is {}",
                    msg.stec_sat_list[16].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[2], 21150,
                    "incorrect value for stec_sat_list[16].stec_coeff[2], expected 21150, is {}",
                    msg.stec_sat_list[16].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[16].stec_coeff[3], 26421,
                    "incorrect value for stec_sat_list[16].stec_coeff[3], expected 26421, is {}",
                    msg.stec_sat_list[16].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[16].stec_quality_indicator, 123, "incorrect value for stec_sat_list[16].stec_quality_indicator, expected 123, is {}", msg.stec_sat_list[16].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[16].sv_id.constellation, 17,
                    "incorrect value for stec_sat_list[16].sv_id.constellation, expected 17, is {}",
                    msg.stec_sat_list[16].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[16].sv_id.sat_id, 1,
                    "incorrect value for stec_sat_list[16].sv_id.sat_id, expected 1, is {}",
                    msg.stec_sat_list[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[0], -19165,
                    "incorrect value for stec_sat_list[17].stec_coeff[0], expected -19165, is {}",
                    msg.stec_sat_list[17].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[1], 30229,
                    "incorrect value for stec_sat_list[17].stec_coeff[1], expected 30229, is {}",
                    msg.stec_sat_list[17].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[2], -1282,
                    "incorrect value for stec_sat_list[17].stec_coeff[2], expected -1282, is {}",
                    msg.stec_sat_list[17].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[17].stec_coeff[3], -18382,
                    "incorrect value for stec_sat_list[17].stec_coeff[3], expected -18382, is {}",
                    msg.stec_sat_list[17].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[17].stec_quality_indicator, 185, "incorrect value for stec_sat_list[17].stec_quality_indicator, expected 185, is {}", msg.stec_sat_list[17].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[17].sv_id.constellation, 202, "incorrect value for stec_sat_list[17].sv_id.constellation, expected 202, is {}", msg.stec_sat_list[17].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[17].sv_id.sat_id, 14,
                    "incorrect value for stec_sat_list[17].sv_id.sat_id, expected 14, is {}",
                    msg.stec_sat_list[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[0], -23752,
                    "incorrect value for stec_sat_list[18].stec_coeff[0], expected -23752, is {}",
                    msg.stec_sat_list[18].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[1], 32433,
                    "incorrect value for stec_sat_list[18].stec_coeff[1], expected 32433, is {}",
                    msg.stec_sat_list[18].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[2], 20441,
                    "incorrect value for stec_sat_list[18].stec_coeff[2], expected 20441, is {}",
                    msg.stec_sat_list[18].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[18].stec_coeff[3], -4181,
                    "incorrect value for stec_sat_list[18].stec_coeff[3], expected -4181, is {}",
                    msg.stec_sat_list[18].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[18].stec_quality_indicator, 45, "incorrect value for stec_sat_list[18].stec_quality_indicator, expected 45, is {}", msg.stec_sat_list[18].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[18].sv_id.constellation, 31,
                    "incorrect value for stec_sat_list[18].sv_id.constellation, expected 31, is {}",
                    msg.stec_sat_list[18].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[18].sv_id.sat_id, 50,
                    "incorrect value for stec_sat_list[18].sv_id.sat_id, expected 50, is {}",
                    msg.stec_sat_list[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[0], -13968,
                    "incorrect value for stec_sat_list[19].stec_coeff[0], expected -13968, is {}",
                    msg.stec_sat_list[19].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[1], -29322,
                    "incorrect value for stec_sat_list[19].stec_coeff[1], expected -29322, is {}",
                    msg.stec_sat_list[19].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[2], -23790,
                    "incorrect value for stec_sat_list[19].stec_coeff[2], expected -23790, is {}",
                    msg.stec_sat_list[19].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[19].stec_coeff[3], 9063,
                    "incorrect value for stec_sat_list[19].stec_coeff[3], expected 9063, is {}",
                    msg.stec_sat_list[19].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[19].stec_quality_indicator, 238, "incorrect value for stec_sat_list[19].stec_quality_indicator, expected 238, is {}", msg.stec_sat_list[19].stec_quality_indicator);
                assert_eq!(msg.stec_sat_list[19].sv_id.constellation, 188, "incorrect value for stec_sat_list[19].sv_id.constellation, expected 188, is {}", msg.stec_sat_list[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_sat_list[19].sv_id.sat_id, 237,
                    "incorrect value for stec_sat_list[19].sv_id.sat_id, expected 237, is {}",
                    msg.stec_sat_list[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[0], 4737,
                    "incorrect value for stec_sat_list[20].stec_coeff[0], expected 4737, is {}",
                    msg.stec_sat_list[20].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[1], 21877,
                    "incorrect value for stec_sat_list[20].stec_coeff[1], expected 21877, is {}",
                    msg.stec_sat_list[20].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[2], 20414,
                    "incorrect value for stec_sat_list[20].stec_coeff[2], expected 20414, is {}",
                    msg.stec_sat_list[20].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[20].stec_coeff[3], -10286,
                    "incorrect value for stec_sat_list[20].stec_coeff[3], expected -10286, is {}",
                    msg.stec_sat_list[20].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[20].stec_quality_indicator, 82, "incorrect value for stec_sat_list[20].stec_quality_indicator, expected 82, is {}", msg.stec_sat_list[20].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[20].sv_id.constellation, 21,
                    "incorrect value for stec_sat_list[20].sv_id.constellation, expected 21, is {}",
                    msg.stec_sat_list[20].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[20].sv_id.sat_id, 63,
                    "incorrect value for stec_sat_list[20].sv_id.sat_id, expected 63, is {}",
                    msg.stec_sat_list[20].sv_id.sat_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrStecCorrectionDep"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
