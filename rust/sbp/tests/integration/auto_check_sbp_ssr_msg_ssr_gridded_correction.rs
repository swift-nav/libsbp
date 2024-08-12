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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrection.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_gridded_correction() {
    {
        let mut payload = Cursor::new(vec![
            85, 252, 5, 196, 249, 253, 21, 14, 151, 50, 120, 133, 29, 151, 174, 229, 151, 189, 204,
            196, 105, 170, 120, 149, 169, 37, 244, 78, 72, 140, 101, 2, 173, 88, 70, 180, 54, 152,
            115, 78, 201, 161, 23, 135, 152, 98, 61, 75, 178, 120, 229, 146, 55, 58, 169, 234, 230,
            69, 172, 191, 127, 146, 89, 150, 91, 111, 225, 41, 17, 119, 52, 166, 166, 120, 57, 221,
            12, 3, 156, 70, 156, 35, 127, 8, 127, 58, 128, 55, 115, 80, 157, 122, 153, 124, 27,
            128, 98, 103, 204, 75, 238, 128, 226, 148, 248, 61, 216, 208, 149, 167, 224, 40, 144,
            186, 157, 227, 72, 240, 100, 35, 12, 212, 7, 59, 176, 81, 86, 27, 24, 155, 67, 43, 132,
            45, 203, 44, 6, 112, 183, 231, 176, 79, 194, 253, 247, 103, 91, 226, 116, 148, 23, 62,
            227, 240, 29, 219, 205, 18, 242, 207, 72, 71, 79, 37, 42, 176, 201, 202, 91, 105, 115,
            146, 59, 110, 44, 109, 128, 183, 185, 67, 31, 165, 92, 79, 189, 180, 94, 7, 162, 121,
            156, 210, 47, 7, 7, 205, 174, 41, 241, 129, 210, 43, 101, 186, 208, 195, 226, 247, 187,
            219, 160, 120, 192, 102, 166, 42, 246, 173, 94, 102, 156, 222, 30, 35, 247, 64, 189,
            137, 204, 220, 32, 71, 222, 222, 201, 246, 3, 25, 45, 251, 239, 115, 88, 218, 10, 209,
            120, 65, 175, 131, 194, 41, 174, 137, 17, 68, 28, 253, 42, 178, 35,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrGriddedCorrection(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5fc,
                    "Incorrect message type, expected 0x5fc, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf9c4,
                    "incorrect sender id, expected 0xf9c4, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 170,
                    "incorrect value for header.iod_atmo, expected 170, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 48535,
                    "incorrect value for header.num_msgs, expected 48535, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 50380,
                    "incorrect value for header.seq_num, expected 50380, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.tile_id, 12951,
                    "incorrect value for header.tile_id, expected 12951, is {}",
                    msg.header.tile_id
                );
                assert_eq!(
                    msg.header.tile_set_id, 3605,
                    "incorrect value for header.tile_set_id, expected 3605, is {}",
                    msg.header.tile_set_id
                );
                assert_eq!(
                    msg.header.time.tow, 2535294328,
                    "incorrect value for header.time.tow, expected 2535294328, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 58798,
                    "incorrect value for header.time.wn, expected 58798, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.tropo_quality_indicator, 120,
                    "incorrect value for header.tropo_quality_indicator, expected 120, is {}",
                    msg.header.tropo_quality_indicator
                );
                assert_eq!(
                    msg.header.update_interval, 105,
                    "incorrect value for header.update_interval, expected 105, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.index, 43413,
                    "incorrect value for index, expected 43413, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.stec_residuals[0].residual, -21246,
                    "incorrect value for stec_residuals[0].residual, expected -21246, is {}",
                    msg.stec_residuals[0].residual
                );
                assert_eq!(
                    msg.stec_residuals[0].stddev, 88,
                    "incorrect value for stec_residuals[0].stddev, expected 88, is {}",
                    msg.stec_residuals[0].stddev
                );
                assert_eq!(msg.stec_residuals[0].sv_id.constellation, 101, "incorrect value for stec_residuals[0].sv_id.constellation, expected 101, is {}", msg.stec_residuals[0].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[0].sv_id.sat_id, 140,
                    "incorrect value for stec_residuals[0].sv_id.sat_id, expected 140, is {}",
                    msg.stec_residuals[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[1].residual, -26570,
                    "incorrect value for stec_residuals[1].residual, expected -26570, is {}",
                    msg.stec_residuals[1].residual
                );
                assert_eq!(
                    msg.stec_residuals[1].stddev, 115,
                    "incorrect value for stec_residuals[1].stddev, expected 115, is {}",
                    msg.stec_residuals[1].stddev
                );
                assert_eq!(msg.stec_residuals[1].sv_id.constellation, 180, "incorrect value for stec_residuals[1].sv_id.constellation, expected 180, is {}", msg.stec_residuals[1].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[1].sv_id.sat_id, 70,
                    "incorrect value for stec_residuals[1].sv_id.sat_id, expected 70, is {}",
                    msg.stec_residuals[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[2].residual, 6049,
                    "incorrect value for stec_residuals[2].residual, expected 6049, is {}",
                    msg.stec_residuals[2].residual
                );
                assert_eq!(
                    msg.stec_residuals[2].stddev, 135,
                    "incorrect value for stec_residuals[2].stddev, expected 135, is {}",
                    msg.stec_residuals[2].stddev
                );
                assert_eq!(msg.stec_residuals[2].sv_id.constellation, 201, "incorrect value for stec_residuals[2].sv_id.constellation, expected 201, is {}", msg.stec_residuals[2].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[2].sv_id.sat_id, 78,
                    "incorrect value for stec_residuals[2].sv_id.sat_id, expected 78, is {}",
                    msg.stec_residuals[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[3].residual, 19261,
                    "incorrect value for stec_residuals[3].residual, expected 19261, is {}",
                    msg.stec_residuals[3].residual
                );
                assert_eq!(
                    msg.stec_residuals[3].stddev, 178,
                    "incorrect value for stec_residuals[3].stddev, expected 178, is {}",
                    msg.stec_residuals[3].stddev
                );
                assert_eq!(
                    msg.stec_residuals[3].sv_id.constellation, 98,
                    "incorrect value for stec_residuals[3].sv_id.constellation, expected 98, is {}",
                    msg.stec_residuals[3].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[3].sv_id.sat_id, 152,
                    "incorrect value for stec_residuals[3].sv_id.sat_id, expected 152, is {}",
                    msg.stec_residuals[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[4].residual, 14226,
                    "incorrect value for stec_residuals[4].residual, expected 14226, is {}",
                    msg.stec_residuals[4].residual
                );
                assert_eq!(
                    msg.stec_residuals[4].stddev, 58,
                    "incorrect value for stec_residuals[4].stddev, expected 58, is {}",
                    msg.stec_residuals[4].stddev
                );
                assert_eq!(msg.stec_residuals[4].sv_id.constellation, 229, "incorrect value for stec_residuals[4].sv_id.constellation, expected 229, is {}", msg.stec_residuals[4].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[4].sv_id.sat_id, 120,
                    "incorrect value for stec_residuals[4].sv_id.sat_id, expected 120, is {}",
                    msg.stec_residuals[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[5].residual, 17894,
                    "incorrect value for stec_residuals[5].residual, expected 17894, is {}",
                    msg.stec_residuals[5].residual
                );
                assert_eq!(
                    msg.stec_residuals[5].stddev, 172,
                    "incorrect value for stec_residuals[5].stddev, expected 172, is {}",
                    msg.stec_residuals[5].stddev
                );
                assert_eq!(msg.stec_residuals[5].sv_id.constellation, 234, "incorrect value for stec_residuals[5].sv_id.constellation, expected 234, is {}", msg.stec_residuals[5].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[5].sv_id.sat_id, 169,
                    "incorrect value for stec_residuals[5].sv_id.sat_id, expected 169, is {}",
                    msg.stec_residuals[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[6].residual, 22930,
                    "incorrect value for stec_residuals[6].residual, expected 22930, is {}",
                    msg.stec_residuals[6].residual
                );
                assert_eq!(
                    msg.stec_residuals[6].stddev, 150,
                    "incorrect value for stec_residuals[6].stddev, expected 150, is {}",
                    msg.stec_residuals[6].stddev
                );
                assert_eq!(msg.stec_residuals[6].sv_id.constellation, 127, "incorrect value for stec_residuals[6].sv_id.constellation, expected 127, is {}", msg.stec_residuals[6].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[6].sv_id.sat_id, 191,
                    "incorrect value for stec_residuals[6].sv_id.sat_id, expected 191, is {}",
                    msg.stec_residuals[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[7].residual, 10721,
                    "incorrect value for stec_residuals[7].residual, expected 10721, is {}",
                    msg.stec_residuals[7].residual
                );
                assert_eq!(
                    msg.stec_residuals[7].stddev, 17,
                    "incorrect value for stec_residuals[7].stddev, expected 17, is {}",
                    msg.stec_residuals[7].stddev
                );
                assert_eq!(msg.stec_residuals[7].sv_id.constellation, 111, "incorrect value for stec_residuals[7].sv_id.constellation, expected 111, is {}", msg.stec_residuals[7].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[7].sv_id.sat_id, 91,
                    "incorrect value for stec_residuals[7].sv_id.sat_id, expected 91, is {}",
                    msg.stec_residuals[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[8].residual, -22874,
                    "incorrect value for stec_residuals[8].residual, expected -22874, is {}",
                    msg.stec_residuals[8].residual
                );
                assert_eq!(
                    msg.stec_residuals[8].stddev, 120,
                    "incorrect value for stec_residuals[8].stddev, expected 120, is {}",
                    msg.stec_residuals[8].stddev
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.constellation, 52,
                    "incorrect value for stec_residuals[8].sv_id.constellation, expected 52, is {}",
                    msg.stec_residuals[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.sat_id, 119,
                    "incorrect value for stec_residuals[8].sv_id.sat_id, expected 119, is {}",
                    msg.stec_residuals[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[9].residual, 780,
                    "incorrect value for stec_residuals[9].residual, expected 780, is {}",
                    msg.stec_residuals[9].residual
                );
                assert_eq!(
                    msg.stec_residuals[9].stddev, 156,
                    "incorrect value for stec_residuals[9].stddev, expected 156, is {}",
                    msg.stec_residuals[9].stddev
                );
                assert_eq!(msg.stec_residuals[9].sv_id.constellation, 221, "incorrect value for stec_residuals[9].sv_id.constellation, expected 221, is {}", msg.stec_residuals[9].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[9].sv_id.sat_id, 57,
                    "incorrect value for stec_residuals[9].sv_id.sat_id, expected 57, is {}",
                    msg.stec_residuals[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[10].residual, 32547,
                    "incorrect value for stec_residuals[10].residual, expected 32547, is {}",
                    msg.stec_residuals[10].residual
                );
                assert_eq!(
                    msg.stec_residuals[10].stddev, 8,
                    "incorrect value for stec_residuals[10].stddev, expected 8, is {}",
                    msg.stec_residuals[10].stddev
                );
                assert_eq!(msg.stec_residuals[10].sv_id.constellation, 156, "incorrect value for stec_residuals[10].sv_id.constellation, expected 156, is {}", msg.stec_residuals[10].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[10].sv_id.sat_id, 70,
                    "incorrect value for stec_residuals[10].sv_id.sat_id, expected 70, is {}",
                    msg.stec_residuals[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[11].residual, 14208,
                    "incorrect value for stec_residuals[11].residual, expected 14208, is {}",
                    msg.stec_residuals[11].residual
                );
                assert_eq!(
                    msg.stec_residuals[11].stddev, 115,
                    "incorrect value for stec_residuals[11].stddev, expected 115, is {}",
                    msg.stec_residuals[11].stddev
                );
                assert_eq!(msg.stec_residuals[11].sv_id.constellation, 58, "incorrect value for stec_residuals[11].sv_id.constellation, expected 58, is {}", msg.stec_residuals[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[11].sv_id.sat_id, 127,
                    "incorrect value for stec_residuals[11].sv_id.sat_id, expected 127, is {}",
                    msg.stec_residuals[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[12].residual, -26246,
                    "incorrect value for stec_residuals[12].residual, expected -26246, is {}",
                    msg.stec_residuals[12].residual
                );
                assert_eq!(
                    msg.stec_residuals[12].stddev, 124,
                    "incorrect value for stec_residuals[12].stddev, expected 124, is {}",
                    msg.stec_residuals[12].stddev
                );
                assert_eq!(msg.stec_residuals[12].sv_id.constellation, 157, "incorrect value for stec_residuals[12].sv_id.constellation, expected 157, is {}", msg.stec_residuals[12].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[12].sv_id.sat_id, 80,
                    "incorrect value for stec_residuals[12].sv_id.sat_id, expected 80, is {}",
                    msg.stec_residuals[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[13].residual, 26466,
                    "incorrect value for stec_residuals[13].residual, expected 26466, is {}",
                    msg.stec_residuals[13].residual
                );
                assert_eq!(
                    msg.stec_residuals[13].stddev, 204,
                    "incorrect value for stec_residuals[13].stddev, expected 204, is {}",
                    msg.stec_residuals[13].stddev
                );
                assert_eq!(msg.stec_residuals[13].sv_id.constellation, 128, "incorrect value for stec_residuals[13].sv_id.constellation, expected 128, is {}", msg.stec_residuals[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[13].sv_id.sat_id, 27,
                    "incorrect value for stec_residuals[13].sv_id.sat_id, expected 27, is {}",
                    msg.stec_residuals[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[14].residual, -7552,
                    "incorrect value for stec_residuals[14].residual, expected -7552, is {}",
                    msg.stec_residuals[14].residual
                );
                assert_eq!(
                    msg.stec_residuals[14].stddev, 148,
                    "incorrect value for stec_residuals[14].stddev, expected 148, is {}",
                    msg.stec_residuals[14].stddev
                );
                assert_eq!(msg.stec_residuals[14].sv_id.constellation, 238, "incorrect value for stec_residuals[14].sv_id.constellation, expected 238, is {}", msg.stec_residuals[14].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[14].sv_id.sat_id, 75,
                    "incorrect value for stec_residuals[14].sv_id.sat_id, expected 75, is {}",
                    msg.stec_residuals[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[15].residual, -12072,
                    "incorrect value for stec_residuals[15].residual, expected -12072, is {}",
                    msg.stec_residuals[15].residual
                );
                assert_eq!(
                    msg.stec_residuals[15].stddev, 149,
                    "incorrect value for stec_residuals[15].stddev, expected 149, is {}",
                    msg.stec_residuals[15].stddev
                );
                assert_eq!(msg.stec_residuals[15].sv_id.constellation, 61, "incorrect value for stec_residuals[15].sv_id.constellation, expected 61, is {}", msg.stec_residuals[15].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[15].sv_id.sat_id, 248,
                    "incorrect value for stec_residuals[15].sv_id.sat_id, expected 248, is {}",
                    msg.stec_residuals[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[16].residual, -28632,
                    "incorrect value for stec_residuals[16].residual, expected -28632, is {}",
                    msg.stec_residuals[16].residual
                );
                assert_eq!(
                    msg.stec_residuals[16].stddev, 186,
                    "incorrect value for stec_residuals[16].stddev, expected 186, is {}",
                    msg.stec_residuals[16].stddev
                );
                assert_eq!(msg.stec_residuals[16].sv_id.constellation, 224, "incorrect value for stec_residuals[16].sv_id.constellation, expected 224, is {}", msg.stec_residuals[16].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[16].sv_id.sat_id, 167,
                    "incorrect value for stec_residuals[16].sv_id.sat_id, expected 167, is {}",
                    msg.stec_residuals[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[17].residual, -4024,
                    "incorrect value for stec_residuals[17].residual, expected -4024, is {}",
                    msg.stec_residuals[17].residual
                );
                assert_eq!(
                    msg.stec_residuals[17].stddev, 100,
                    "incorrect value for stec_residuals[17].stddev, expected 100, is {}",
                    msg.stec_residuals[17].stddev
                );
                assert_eq!(msg.stec_residuals[17].sv_id.constellation, 227, "incorrect value for stec_residuals[17].sv_id.constellation, expected 227, is {}", msg.stec_residuals[17].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[17].sv_id.sat_id, 157,
                    "incorrect value for stec_residuals[17].sv_id.sat_id, expected 157, is {}",
                    msg.stec_residuals[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[18].residual, 2004,
                    "incorrect value for stec_residuals[18].residual, expected 2004, is {}",
                    msg.stec_residuals[18].residual
                );
                assert_eq!(
                    msg.stec_residuals[18].stddev, 59,
                    "incorrect value for stec_residuals[18].stddev, expected 59, is {}",
                    msg.stec_residuals[18].stddev
                );
                assert_eq!(msg.stec_residuals[18].sv_id.constellation, 12, "incorrect value for stec_residuals[18].sv_id.constellation, expected 12, is {}", msg.stec_residuals[18].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[18].sv_id.sat_id, 35,
                    "incorrect value for stec_residuals[18].sv_id.sat_id, expected 35, is {}",
                    msg.stec_residuals[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[19].residual, 6998,
                    "incorrect value for stec_residuals[19].residual, expected 6998, is {}",
                    msg.stec_residuals[19].residual
                );
                assert_eq!(
                    msg.stec_residuals[19].stddev, 24,
                    "incorrect value for stec_residuals[19].stddev, expected 24, is {}",
                    msg.stec_residuals[19].stddev
                );
                assert_eq!(msg.stec_residuals[19].sv_id.constellation, 81, "incorrect value for stec_residuals[19].sv_id.constellation, expected 81, is {}", msg.stec_residuals[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[19].sv_id.sat_id, 176,
                    "incorrect value for stec_residuals[19].sv_id.sat_id, expected 176, is {}",
                    msg.stec_residuals[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[20].residual, -31701,
                    "incorrect value for stec_residuals[20].residual, expected -31701, is {}",
                    msg.stec_residuals[20].residual
                );
                assert_eq!(
                    msg.stec_residuals[20].stddev, 45,
                    "incorrect value for stec_residuals[20].stddev, expected 45, is {}",
                    msg.stec_residuals[20].stddev
                );
                assert_eq!(msg.stec_residuals[20].sv_id.constellation, 67, "incorrect value for stec_residuals[20].sv_id.constellation, expected 67, is {}", msg.stec_residuals[20].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[20].sv_id.sat_id, 155,
                    "incorrect value for stec_residuals[20].sv_id.sat_id, expected 155, is {}",
                    msg.stec_residuals[20].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[21].residual, 28678,
                    "incorrect value for stec_residuals[21].residual, expected 28678, is {}",
                    msg.stec_residuals[21].residual
                );
                assert_eq!(
                    msg.stec_residuals[21].stddev, 183,
                    "incorrect value for stec_residuals[21].stddev, expected 183, is {}",
                    msg.stec_residuals[21].stddev
                );
                assert_eq!(msg.stec_residuals[21].sv_id.constellation, 44, "incorrect value for stec_residuals[21].sv_id.constellation, expected 44, is {}", msg.stec_residuals[21].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[21].sv_id.sat_id, 203,
                    "incorrect value for stec_residuals[21].sv_id.sat_id, expected 203, is {}",
                    msg.stec_residuals[21].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[22].residual, -15793,
                    "incorrect value for stec_residuals[22].residual, expected -15793, is {}",
                    msg.stec_residuals[22].residual
                );
                assert_eq!(
                    msg.stec_residuals[22].stddev, 253,
                    "incorrect value for stec_residuals[22].stddev, expected 253, is {}",
                    msg.stec_residuals[22].stddev
                );
                assert_eq!(msg.stec_residuals[22].sv_id.constellation, 176, "incorrect value for stec_residuals[22].sv_id.constellation, expected 176, is {}", msg.stec_residuals[22].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[22].sv_id.sat_id, 231,
                    "incorrect value for stec_residuals[22].sv_id.sat_id, expected 231, is {}",
                    msg.stec_residuals[22].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[23].residual, -7589,
                    "incorrect value for stec_residuals[23].residual, expected -7589, is {}",
                    msg.stec_residuals[23].residual
                );
                assert_eq!(
                    msg.stec_residuals[23].stddev, 116,
                    "incorrect value for stec_residuals[23].stddev, expected 116, is {}",
                    msg.stec_residuals[23].stddev
                );
                assert_eq!(msg.stec_residuals[23].sv_id.constellation, 103, "incorrect value for stec_residuals[23].sv_id.constellation, expected 103, is {}", msg.stec_residuals[23].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[23].sv_id.sat_id, 247,
                    "incorrect value for stec_residuals[23].sv_id.sat_id, expected 247, is {}",
                    msg.stec_residuals[23].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[24].residual, -7362,
                    "incorrect value for stec_residuals[24].residual, expected -7362, is {}",
                    msg.stec_residuals[24].residual
                );
                assert_eq!(
                    msg.stec_residuals[24].stddev, 240,
                    "incorrect value for stec_residuals[24].stddev, expected 240, is {}",
                    msg.stec_residuals[24].stddev
                );
                assert_eq!(msg.stec_residuals[24].sv_id.constellation, 23, "incorrect value for stec_residuals[24].sv_id.constellation, expected 23, is {}", msg.stec_residuals[24].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[24].sv_id.sat_id, 148,
                    "incorrect value for stec_residuals[24].sv_id.sat_id, expected 148, is {}",
                    msg.stec_residuals[24].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[25].residual, 4813,
                    "incorrect value for stec_residuals[25].residual, expected 4813, is {}",
                    msg.stec_residuals[25].residual
                );
                assert_eq!(
                    msg.stec_residuals[25].stddev, 242,
                    "incorrect value for stec_residuals[25].stddev, expected 242, is {}",
                    msg.stec_residuals[25].stddev
                );
                assert_eq!(msg.stec_residuals[25].sv_id.constellation, 219, "incorrect value for stec_residuals[25].sv_id.constellation, expected 219, is {}", msg.stec_residuals[25].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[25].sv_id.sat_id, 29,
                    "incorrect value for stec_residuals[25].sv_id.sat_id, expected 29, is {}",
                    msg.stec_residuals[25].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[26].residual, 20295,
                    "incorrect value for stec_residuals[26].residual, expected 20295, is {}",
                    msg.stec_residuals[26].residual
                );
                assert_eq!(
                    msg.stec_residuals[26].stddev, 37,
                    "incorrect value for stec_residuals[26].stddev, expected 37, is {}",
                    msg.stec_residuals[26].stddev
                );
                assert_eq!(msg.stec_residuals[26].sv_id.constellation, 72, "incorrect value for stec_residuals[26].sv_id.constellation, expected 72, is {}", msg.stec_residuals[26].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[26].sv_id.sat_id, 207,
                    "incorrect value for stec_residuals[26].sv_id.sat_id, expected 207, is {}",
                    msg.stec_residuals[26].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[27].residual, -13623,
                    "incorrect value for stec_residuals[27].residual, expected -13623, is {}",
                    msg.stec_residuals[27].residual
                );
                assert_eq!(
                    msg.stec_residuals[27].stddev, 91,
                    "incorrect value for stec_residuals[27].stddev, expected 91, is {}",
                    msg.stec_residuals[27].stddev
                );
                assert_eq!(msg.stec_residuals[27].sv_id.constellation, 176, "incorrect value for stec_residuals[27].sv_id.constellation, expected 176, is {}", msg.stec_residuals[27].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[27].sv_id.sat_id, 42,
                    "incorrect value for stec_residuals[27].sv_id.sat_id, expected 42, is {}",
                    msg.stec_residuals[27].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[28].residual, 15250,
                    "incorrect value for stec_residuals[28].residual, expected 15250, is {}",
                    msg.stec_residuals[28].residual
                );
                assert_eq!(
                    msg.stec_residuals[28].stddev, 110,
                    "incorrect value for stec_residuals[28].stddev, expected 110, is {}",
                    msg.stec_residuals[28].stddev
                );
                assert_eq!(msg.stec_residuals[28].sv_id.constellation, 115, "incorrect value for stec_residuals[28].sv_id.constellation, expected 115, is {}", msg.stec_residuals[28].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[28].sv_id.sat_id, 105,
                    "incorrect value for stec_residuals[28].sv_id.sat_id, expected 105, is {}",
                    msg.stec_residuals[28].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[29].residual, -18560,
                    "incorrect value for stec_residuals[29].residual, expected -18560, is {}",
                    msg.stec_residuals[29].residual
                );
                assert_eq!(
                    msg.stec_residuals[29].stddev, 185,
                    "incorrect value for stec_residuals[29].stddev, expected 185, is {}",
                    msg.stec_residuals[29].stddev
                );
                assert_eq!(msg.stec_residuals[29].sv_id.constellation, 109, "incorrect value for stec_residuals[29].sv_id.constellation, expected 109, is {}", msg.stec_residuals[29].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[29].sv_id.sat_id, 44,
                    "incorrect value for stec_residuals[29].sv_id.sat_id, expected 44, is {}",
                    msg.stec_residuals[29].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[30].residual, 23717,
                    "incorrect value for stec_residuals[30].residual, expected 23717, is {}",
                    msg.stec_residuals[30].residual
                );
                assert_eq!(
                    msg.stec_residuals[30].stddev, 79,
                    "incorrect value for stec_residuals[30].stddev, expected 79, is {}",
                    msg.stec_residuals[30].stddev
                );
                assert_eq!(msg.stec_residuals[30].sv_id.constellation, 31, "incorrect value for stec_residuals[30].sv_id.constellation, expected 31, is {}", msg.stec_residuals[30].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[30].sv_id.sat_id, 67,
                    "incorrect value for stec_residuals[30].sv_id.sat_id, expected 67, is {}",
                    msg.stec_residuals[30].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[31].residual, 1886,
                    "incorrect value for stec_residuals[31].residual, expected 1886, is {}",
                    msg.stec_residuals[31].residual
                );
                assert_eq!(
                    msg.stec_residuals[31].stddev, 162,
                    "incorrect value for stec_residuals[31].stddev, expected 162, is {}",
                    msg.stec_residuals[31].stddev
                );
                assert_eq!(msg.stec_residuals[31].sv_id.constellation, 180, "incorrect value for stec_residuals[31].sv_id.constellation, expected 180, is {}", msg.stec_residuals[31].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[31].sv_id.sat_id, 189,
                    "incorrect value for stec_residuals[31].sv_id.sat_id, expected 189, is {}",
                    msg.stec_residuals[31].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[32].residual, 12242,
                    "incorrect value for stec_residuals[32].residual, expected 12242, is {}",
                    msg.stec_residuals[32].residual
                );
                assert_eq!(
                    msg.stec_residuals[32].stddev, 7,
                    "incorrect value for stec_residuals[32].stddev, expected 7, is {}",
                    msg.stec_residuals[32].stddev
                );
                assert_eq!(msg.stec_residuals[32].sv_id.constellation, 156, "incorrect value for stec_residuals[32].sv_id.constellation, expected 156, is {}", msg.stec_residuals[32].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[32].sv_id.sat_id, 121,
                    "incorrect value for stec_residuals[32].sv_id.sat_id, expected 121, is {}",
                    msg.stec_residuals[32].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[33].residual, 10670,
                    "incorrect value for stec_residuals[33].residual, expected 10670, is {}",
                    msg.stec_residuals[33].residual
                );
                assert_eq!(
                    msg.stec_residuals[33].stddev, 241,
                    "incorrect value for stec_residuals[33].stddev, expected 241, is {}",
                    msg.stec_residuals[33].stddev
                );
                assert_eq!(msg.stec_residuals[33].sv_id.constellation, 205, "incorrect value for stec_residuals[33].sv_id.constellation, expected 205, is {}", msg.stec_residuals[33].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[33].sv_id.sat_id, 7,
                    "incorrect value for stec_residuals[33].sv_id.sat_id, expected 7, is {}",
                    msg.stec_residuals[33].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[34].residual, 25899,
                    "incorrect value for stec_residuals[34].residual, expected 25899, is {}",
                    msg.stec_residuals[34].residual
                );
                assert_eq!(
                    msg.stec_residuals[34].stddev, 186,
                    "incorrect value for stec_residuals[34].stddev, expected 186, is {}",
                    msg.stec_residuals[34].stddev
                );
                assert_eq!(msg.stec_residuals[34].sv_id.constellation, 210, "incorrect value for stec_residuals[34].sv_id.constellation, expected 210, is {}", msg.stec_residuals[34].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[34].sv_id.sat_id, 129,
                    "incorrect value for stec_residuals[34].sv_id.sat_id, expected 129, is {}",
                    msg.stec_residuals[34].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[35].residual, -2078,
                    "incorrect value for stec_residuals[35].residual, expected -2078, is {}",
                    msg.stec_residuals[35].residual
                );
                assert_eq!(
                    msg.stec_residuals[35].stddev, 187,
                    "incorrect value for stec_residuals[35].stddev, expected 187, is {}",
                    msg.stec_residuals[35].stddev
                );
                assert_eq!(msg.stec_residuals[35].sv_id.constellation, 195, "incorrect value for stec_residuals[35].sv_id.constellation, expected 195, is {}", msg.stec_residuals[35].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[35].sv_id.sat_id, 208,
                    "incorrect value for stec_residuals[35].sv_id.sat_id, expected 208, is {}",
                    msg.stec_residuals[35].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[36].residual, -16264,
                    "incorrect value for stec_residuals[36].residual, expected -16264, is {}",
                    msg.stec_residuals[36].residual
                );
                assert_eq!(
                    msg.stec_residuals[36].stddev, 102,
                    "incorrect value for stec_residuals[36].stddev, expected 102, is {}",
                    msg.stec_residuals[36].stddev
                );
                assert_eq!(msg.stec_residuals[36].sv_id.constellation, 160, "incorrect value for stec_residuals[36].sv_id.constellation, expected 160, is {}", msg.stec_residuals[36].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[36].sv_id.sat_id, 219,
                    "incorrect value for stec_residuals[36].sv_id.sat_id, expected 219, is {}",
                    msg.stec_residuals[36].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[37].residual, -21002,
                    "incorrect value for stec_residuals[37].residual, expected -21002, is {}",
                    msg.stec_residuals[37].residual
                );
                assert_eq!(
                    msg.stec_residuals[37].stddev, 94,
                    "incorrect value for stec_residuals[37].stddev, expected 94, is {}",
                    msg.stec_residuals[37].stddev
                );
                assert_eq!(msg.stec_residuals[37].sv_id.constellation, 42, "incorrect value for stec_residuals[37].sv_id.constellation, expected 42, is {}", msg.stec_residuals[37].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[37].sv_id.sat_id, 166,
                    "incorrect value for stec_residuals[37].sv_id.sat_id, expected 166, is {}",
                    msg.stec_residuals[37].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[38].residual, 7902,
                    "incorrect value for stec_residuals[38].residual, expected 7902, is {}",
                    msg.stec_residuals[38].residual
                );
                assert_eq!(
                    msg.stec_residuals[38].stddev, 35,
                    "incorrect value for stec_residuals[38].stddev, expected 35, is {}",
                    msg.stec_residuals[38].stddev
                );
                assert_eq!(msg.stec_residuals[38].sv_id.constellation, 156, "incorrect value for stec_residuals[38].sv_id.constellation, expected 156, is {}", msg.stec_residuals[38].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[38].sv_id.sat_id, 102,
                    "incorrect value for stec_residuals[38].sv_id.sat_id, expected 102, is {}",
                    msg.stec_residuals[38].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[39].residual, -30275,
                    "incorrect value for stec_residuals[39].residual, expected -30275, is {}",
                    msg.stec_residuals[39].residual
                );
                assert_eq!(
                    msg.stec_residuals[39].stddev, 204,
                    "incorrect value for stec_residuals[39].stddev, expected 204, is {}",
                    msg.stec_residuals[39].stddev
                );
                assert_eq!(msg.stec_residuals[39].sv_id.constellation, 64, "incorrect value for stec_residuals[39].sv_id.constellation, expected 64, is {}", msg.stec_residuals[39].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[39].sv_id.sat_id, 247,
                    "incorrect value for stec_residuals[39].sv_id.sat_id, expected 247, is {}",
                    msg.stec_residuals[39].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[40].residual, -8633,
                    "incorrect value for stec_residuals[40].residual, expected -8633, is {}",
                    msg.stec_residuals[40].residual
                );
                assert_eq!(
                    msg.stec_residuals[40].stddev, 222,
                    "incorrect value for stec_residuals[40].stddev, expected 222, is {}",
                    msg.stec_residuals[40].stddev
                );
                assert_eq!(msg.stec_residuals[40].sv_id.constellation, 32, "incorrect value for stec_residuals[40].sv_id.constellation, expected 32, is {}", msg.stec_residuals[40].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[40].sv_id.sat_id, 220,
                    "incorrect value for stec_residuals[40].sv_id.sat_id, expected 220, is {}",
                    msg.stec_residuals[40].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[41].residual, 6403,
                    "incorrect value for stec_residuals[41].residual, expected 6403, is {}",
                    msg.stec_residuals[41].residual
                );
                assert_eq!(
                    msg.stec_residuals[41].stddev, 45,
                    "incorrect value for stec_residuals[41].stddev, expected 45, is {}",
                    msg.stec_residuals[41].stddev
                );
                assert_eq!(msg.stec_residuals[41].sv_id.constellation, 246, "incorrect value for stec_residuals[41].sv_id.constellation, expected 246, is {}", msg.stec_residuals[41].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[41].sv_id.sat_id, 201,
                    "incorrect value for stec_residuals[41].sv_id.sat_id, expected 201, is {}",
                    msg.stec_residuals[41].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[42].residual, 22643,
                    "incorrect value for stec_residuals[42].residual, expected 22643, is {}",
                    msg.stec_residuals[42].residual
                );
                assert_eq!(
                    msg.stec_residuals[42].stddev, 218,
                    "incorrect value for stec_residuals[42].stddev, expected 218, is {}",
                    msg.stec_residuals[42].stddev
                );
                assert_eq!(msg.stec_residuals[42].sv_id.constellation, 239, "incorrect value for stec_residuals[42].sv_id.constellation, expected 239, is {}", msg.stec_residuals[42].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[42].sv_id.sat_id, 251,
                    "incorrect value for stec_residuals[42].sv_id.sat_id, expected 251, is {}",
                    msg.stec_residuals[42].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[43].residual, 16760,
                    "incorrect value for stec_residuals[43].residual, expected 16760, is {}",
                    msg.stec_residuals[43].residual
                );
                assert_eq!(
                    msg.stec_residuals[43].stddev, 175,
                    "incorrect value for stec_residuals[43].stddev, expected 175, is {}",
                    msg.stec_residuals[43].stddev
                );
                assert_eq!(msg.stec_residuals[43].sv_id.constellation, 209, "incorrect value for stec_residuals[43].sv_id.constellation, expected 209, is {}", msg.stec_residuals[43].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[43].sv_id.sat_id, 10,
                    "incorrect value for stec_residuals[43].sv_id.sat_id, expected 10, is {}",
                    msg.stec_residuals[43].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[44].residual, -20951,
                    "incorrect value for stec_residuals[44].residual, expected -20951, is {}",
                    msg.stec_residuals[44].residual
                );
                assert_eq!(
                    msg.stec_residuals[44].stddev, 137,
                    "incorrect value for stec_residuals[44].stddev, expected 137, is {}",
                    msg.stec_residuals[44].stddev
                );
                assert_eq!(msg.stec_residuals[44].sv_id.constellation, 194, "incorrect value for stec_residuals[44].sv_id.constellation, expected 194, is {}", msg.stec_residuals[44].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[44].sv_id.sat_id, 131,
                    "incorrect value for stec_residuals[44].sv_id.sat_id, expected 131, is {}",
                    msg.stec_residuals[44].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[45].residual, -740,
                    "incorrect value for stec_residuals[45].residual, expected -740, is {}",
                    msg.stec_residuals[45].residual
                );
                assert_eq!(
                    msg.stec_residuals[45].stddev, 42,
                    "incorrect value for stec_residuals[45].stddev, expected 42, is {}",
                    msg.stec_residuals[45].stddev
                );
                assert_eq!(msg.stec_residuals[45].sv_id.constellation, 68, "incorrect value for stec_residuals[45].sv_id.constellation, expected 68, is {}", msg.stec_residuals[45].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[45].sv_id.sat_id, 17,
                    "incorrect value for stec_residuals[45].sv_id.sat_id, expected 17, is {}",
                    msg.stec_residuals[45].sv_id.sat_id
                );
                assert_eq!(
                    msg.tropo_delay_correction.hydro, -3035,
                    "incorrect value for tropo_delay_correction.hydro, expected -3035, is {}",
                    msg.tropo_delay_correction.hydro
                );
                assert_eq!(
                    msg.tropo_delay_correction.stddev, 72,
                    "incorrect value for tropo_delay_correction.stddev, expected 72, is {}",
                    msg.tropo_delay_correction.stddev
                );
                assert_eq!(
                    msg.tropo_delay_correction.wet, 78,
                    "incorrect value for tropo_delay_correction.wet, expected 78, is {}",
                    msg.tropo_delay_correction.wet
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGriddedCorrection"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_gridded_correction() {
    {
        let json_input = r#"{"crc":9138,"length":253,"msg_type":1532,"payload":"FQ6XMniFHZeu5Ze9zMRpqniVqSX0TkiMZQKtWEa0NphzTsmhF4eYYj1Lsnjlkjc6qermRay/f5JZlltv4SkRdzSmpng53QwDnEacI38IfzqAN3NQnXqZfBuAYmfMS+6A4pT4PdjQlafgKJC6neNI8GQjDNQHO7BRVhsYm0MrhC3LLAZwt+ewT8L992db4nSUFz7j8B3bzRLyz0hHTyUqsMnKW2lzkjtuLG2At7lDH6VcT720XgeieZzSLwcHza4p8YHSK2W60MPi97vboHjAZqYq9q1eZpzeHiP3QL2JzNwgR97eyfYDGS3773NY2grReEGvg8IprokRRBz9Kg==","preamble":85,"sender":63940,"header":{"tile_set_id":3605,"tile_id":12951,"time":{"tow":2535294328,"wn":58798},"num_msgs":48535,"seq_num":50380,"update_interval":105,"iod_atmo":170,"tropo_quality_indicator":120},"index":43413,"tropo_delay_correction":{"hydro":-3035,"wet":78,"stddev":72},"stec_residuals":[{"sv_id":{"satId":140,"constellation":101},"residual":-21246,"stddev":88},{"sv_id":{"satId":70,"constellation":180},"residual":-26570,"stddev":115},{"sv_id":{"satId":78,"constellation":201},"residual":6049,"stddev":135},{"sv_id":{"satId":152,"constellation":98},"residual":19261,"stddev":178},{"sv_id":{"satId":120,"constellation":229},"residual":14226,"stddev":58},{"sv_id":{"satId":169,"constellation":234},"residual":17894,"stddev":172},{"sv_id":{"satId":191,"constellation":127},"residual":22930,"stddev":150},{"sv_id":{"satId":91,"constellation":111},"residual":10721,"stddev":17},{"sv_id":{"satId":119,"constellation":52},"residual":-22874,"stddev":120},{"sv_id":{"satId":57,"constellation":221},"residual":780,"stddev":156},{"sv_id":{"satId":70,"constellation":156},"residual":32547,"stddev":8},{"sv_id":{"satId":127,"constellation":58},"residual":14208,"stddev":115},{"sv_id":{"satId":80,"constellation":157},"residual":-26246,"stddev":124},{"sv_id":{"satId":27,"constellation":128},"residual":26466,"stddev":204},{"sv_id":{"satId":75,"constellation":238},"residual":-7552,"stddev":148},{"sv_id":{"satId":248,"constellation":61},"residual":-12072,"stddev":149},{"sv_id":{"satId":167,"constellation":224},"residual":-28632,"stddev":186},{"sv_id":{"satId":157,"constellation":227},"residual":-4024,"stddev":100},{"sv_id":{"satId":35,"constellation":12},"residual":2004,"stddev":59},{"sv_id":{"satId":176,"constellation":81},"residual":6998,"stddev":24},{"sv_id":{"satId":155,"constellation":67},"residual":-31701,"stddev":45},{"sv_id":{"satId":203,"constellation":44},"residual":28678,"stddev":183},{"sv_id":{"satId":231,"constellation":176},"residual":-15793,"stddev":253},{"sv_id":{"satId":247,"constellation":103},"residual":-7589,"stddev":116},{"sv_id":{"satId":148,"constellation":23},"residual":-7362,"stddev":240},{"sv_id":{"satId":29,"constellation":219},"residual":4813,"stddev":242},{"sv_id":{"satId":207,"constellation":72},"residual":20295,"stddev":37},{"sv_id":{"satId":42,"constellation":176},"residual":-13623,"stddev":91},{"sv_id":{"satId":105,"constellation":115},"residual":15250,"stddev":110},{"sv_id":{"satId":44,"constellation":109},"residual":-18560,"stddev":185},{"sv_id":{"satId":67,"constellation":31},"residual":23717,"stddev":79},{"sv_id":{"satId":189,"constellation":180},"residual":1886,"stddev":162},{"sv_id":{"satId":121,"constellation":156},"residual":12242,"stddev":7},{"sv_id":{"satId":7,"constellation":205},"residual":10670,"stddev":241},{"sv_id":{"satId":129,"constellation":210},"residual":25899,"stddev":186},{"sv_id":{"satId":208,"constellation":195},"residual":-2078,"stddev":187},{"sv_id":{"satId":219,"constellation":160},"residual":-16264,"stddev":102},{"sv_id":{"satId":166,"constellation":42},"residual":-21002,"stddev":94},{"sv_id":{"satId":102,"constellation":156},"residual":7902,"stddev":35},{"sv_id":{"satId":247,"constellation":64},"residual":-30275,"stddev":204},{"sv_id":{"satId":220,"constellation":32},"residual":-8633,"stddev":222},{"sv_id":{"satId":201,"constellation":246},"residual":6403,"stddev":45},{"sv_id":{"satId":251,"constellation":239},"residual":22643,"stddev":218},{"sv_id":{"satId":10,"constellation":209},"residual":16760,"stddev":175},{"sv_id":{"satId":131,"constellation":194},"residual":-20951,"stddev":137},{"sv_id":{"satId":17,"constellation":68},"residual":-740,"stddev":42}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrGriddedCorrection(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5fc,
                    "Incorrect message type, expected 0x5fc, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf9c4,
                    "incorrect sender id, expected 0xf9c4, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 170,
                    "incorrect value for header.iod_atmo, expected 170, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 48535,
                    "incorrect value for header.num_msgs, expected 48535, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 50380,
                    "incorrect value for header.seq_num, expected 50380, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.tile_id, 12951,
                    "incorrect value for header.tile_id, expected 12951, is {}",
                    msg.header.tile_id
                );
                assert_eq!(
                    msg.header.tile_set_id, 3605,
                    "incorrect value for header.tile_set_id, expected 3605, is {}",
                    msg.header.tile_set_id
                );
                assert_eq!(
                    msg.header.time.tow, 2535294328,
                    "incorrect value for header.time.tow, expected 2535294328, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 58798,
                    "incorrect value for header.time.wn, expected 58798, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.tropo_quality_indicator, 120,
                    "incorrect value for header.tropo_quality_indicator, expected 120, is {}",
                    msg.header.tropo_quality_indicator
                );
                assert_eq!(
                    msg.header.update_interval, 105,
                    "incorrect value for header.update_interval, expected 105, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.index, 43413,
                    "incorrect value for index, expected 43413, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.stec_residuals[0].residual, -21246,
                    "incorrect value for stec_residuals[0].residual, expected -21246, is {}",
                    msg.stec_residuals[0].residual
                );
                assert_eq!(
                    msg.stec_residuals[0].stddev, 88,
                    "incorrect value for stec_residuals[0].stddev, expected 88, is {}",
                    msg.stec_residuals[0].stddev
                );
                assert_eq!(msg.stec_residuals[0].sv_id.constellation, 101, "incorrect value for stec_residuals[0].sv_id.constellation, expected 101, is {}", msg.stec_residuals[0].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[0].sv_id.sat_id, 140,
                    "incorrect value for stec_residuals[0].sv_id.sat_id, expected 140, is {}",
                    msg.stec_residuals[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[1].residual, -26570,
                    "incorrect value for stec_residuals[1].residual, expected -26570, is {}",
                    msg.stec_residuals[1].residual
                );
                assert_eq!(
                    msg.stec_residuals[1].stddev, 115,
                    "incorrect value for stec_residuals[1].stddev, expected 115, is {}",
                    msg.stec_residuals[1].stddev
                );
                assert_eq!(msg.stec_residuals[1].sv_id.constellation, 180, "incorrect value for stec_residuals[1].sv_id.constellation, expected 180, is {}", msg.stec_residuals[1].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[1].sv_id.sat_id, 70,
                    "incorrect value for stec_residuals[1].sv_id.sat_id, expected 70, is {}",
                    msg.stec_residuals[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[2].residual, 6049,
                    "incorrect value for stec_residuals[2].residual, expected 6049, is {}",
                    msg.stec_residuals[2].residual
                );
                assert_eq!(
                    msg.stec_residuals[2].stddev, 135,
                    "incorrect value for stec_residuals[2].stddev, expected 135, is {}",
                    msg.stec_residuals[2].stddev
                );
                assert_eq!(msg.stec_residuals[2].sv_id.constellation, 201, "incorrect value for stec_residuals[2].sv_id.constellation, expected 201, is {}", msg.stec_residuals[2].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[2].sv_id.sat_id, 78,
                    "incorrect value for stec_residuals[2].sv_id.sat_id, expected 78, is {}",
                    msg.stec_residuals[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[3].residual, 19261,
                    "incorrect value for stec_residuals[3].residual, expected 19261, is {}",
                    msg.stec_residuals[3].residual
                );
                assert_eq!(
                    msg.stec_residuals[3].stddev, 178,
                    "incorrect value for stec_residuals[3].stddev, expected 178, is {}",
                    msg.stec_residuals[3].stddev
                );
                assert_eq!(
                    msg.stec_residuals[3].sv_id.constellation, 98,
                    "incorrect value for stec_residuals[3].sv_id.constellation, expected 98, is {}",
                    msg.stec_residuals[3].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[3].sv_id.sat_id, 152,
                    "incorrect value for stec_residuals[3].sv_id.sat_id, expected 152, is {}",
                    msg.stec_residuals[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[4].residual, 14226,
                    "incorrect value for stec_residuals[4].residual, expected 14226, is {}",
                    msg.stec_residuals[4].residual
                );
                assert_eq!(
                    msg.stec_residuals[4].stddev, 58,
                    "incorrect value for stec_residuals[4].stddev, expected 58, is {}",
                    msg.stec_residuals[4].stddev
                );
                assert_eq!(msg.stec_residuals[4].sv_id.constellation, 229, "incorrect value for stec_residuals[4].sv_id.constellation, expected 229, is {}", msg.stec_residuals[4].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[4].sv_id.sat_id, 120,
                    "incorrect value for stec_residuals[4].sv_id.sat_id, expected 120, is {}",
                    msg.stec_residuals[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[5].residual, 17894,
                    "incorrect value for stec_residuals[5].residual, expected 17894, is {}",
                    msg.stec_residuals[5].residual
                );
                assert_eq!(
                    msg.stec_residuals[5].stddev, 172,
                    "incorrect value for stec_residuals[5].stddev, expected 172, is {}",
                    msg.stec_residuals[5].stddev
                );
                assert_eq!(msg.stec_residuals[5].sv_id.constellation, 234, "incorrect value for stec_residuals[5].sv_id.constellation, expected 234, is {}", msg.stec_residuals[5].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[5].sv_id.sat_id, 169,
                    "incorrect value for stec_residuals[5].sv_id.sat_id, expected 169, is {}",
                    msg.stec_residuals[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[6].residual, 22930,
                    "incorrect value for stec_residuals[6].residual, expected 22930, is {}",
                    msg.stec_residuals[6].residual
                );
                assert_eq!(
                    msg.stec_residuals[6].stddev, 150,
                    "incorrect value for stec_residuals[6].stddev, expected 150, is {}",
                    msg.stec_residuals[6].stddev
                );
                assert_eq!(msg.stec_residuals[6].sv_id.constellation, 127, "incorrect value for stec_residuals[6].sv_id.constellation, expected 127, is {}", msg.stec_residuals[6].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[6].sv_id.sat_id, 191,
                    "incorrect value for stec_residuals[6].sv_id.sat_id, expected 191, is {}",
                    msg.stec_residuals[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[7].residual, 10721,
                    "incorrect value for stec_residuals[7].residual, expected 10721, is {}",
                    msg.stec_residuals[7].residual
                );
                assert_eq!(
                    msg.stec_residuals[7].stddev, 17,
                    "incorrect value for stec_residuals[7].stddev, expected 17, is {}",
                    msg.stec_residuals[7].stddev
                );
                assert_eq!(msg.stec_residuals[7].sv_id.constellation, 111, "incorrect value for stec_residuals[7].sv_id.constellation, expected 111, is {}", msg.stec_residuals[7].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[7].sv_id.sat_id, 91,
                    "incorrect value for stec_residuals[7].sv_id.sat_id, expected 91, is {}",
                    msg.stec_residuals[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[8].residual, -22874,
                    "incorrect value for stec_residuals[8].residual, expected -22874, is {}",
                    msg.stec_residuals[8].residual
                );
                assert_eq!(
                    msg.stec_residuals[8].stddev, 120,
                    "incorrect value for stec_residuals[8].stddev, expected 120, is {}",
                    msg.stec_residuals[8].stddev
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.constellation, 52,
                    "incorrect value for stec_residuals[8].sv_id.constellation, expected 52, is {}",
                    msg.stec_residuals[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.sat_id, 119,
                    "incorrect value for stec_residuals[8].sv_id.sat_id, expected 119, is {}",
                    msg.stec_residuals[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[9].residual, 780,
                    "incorrect value for stec_residuals[9].residual, expected 780, is {}",
                    msg.stec_residuals[9].residual
                );
                assert_eq!(
                    msg.stec_residuals[9].stddev, 156,
                    "incorrect value for stec_residuals[9].stddev, expected 156, is {}",
                    msg.stec_residuals[9].stddev
                );
                assert_eq!(msg.stec_residuals[9].sv_id.constellation, 221, "incorrect value for stec_residuals[9].sv_id.constellation, expected 221, is {}", msg.stec_residuals[9].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[9].sv_id.sat_id, 57,
                    "incorrect value for stec_residuals[9].sv_id.sat_id, expected 57, is {}",
                    msg.stec_residuals[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[10].residual, 32547,
                    "incorrect value for stec_residuals[10].residual, expected 32547, is {}",
                    msg.stec_residuals[10].residual
                );
                assert_eq!(
                    msg.stec_residuals[10].stddev, 8,
                    "incorrect value for stec_residuals[10].stddev, expected 8, is {}",
                    msg.stec_residuals[10].stddev
                );
                assert_eq!(msg.stec_residuals[10].sv_id.constellation, 156, "incorrect value for stec_residuals[10].sv_id.constellation, expected 156, is {}", msg.stec_residuals[10].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[10].sv_id.sat_id, 70,
                    "incorrect value for stec_residuals[10].sv_id.sat_id, expected 70, is {}",
                    msg.stec_residuals[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[11].residual, 14208,
                    "incorrect value for stec_residuals[11].residual, expected 14208, is {}",
                    msg.stec_residuals[11].residual
                );
                assert_eq!(
                    msg.stec_residuals[11].stddev, 115,
                    "incorrect value for stec_residuals[11].stddev, expected 115, is {}",
                    msg.stec_residuals[11].stddev
                );
                assert_eq!(msg.stec_residuals[11].sv_id.constellation, 58, "incorrect value for stec_residuals[11].sv_id.constellation, expected 58, is {}", msg.stec_residuals[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[11].sv_id.sat_id, 127,
                    "incorrect value for stec_residuals[11].sv_id.sat_id, expected 127, is {}",
                    msg.stec_residuals[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[12].residual, -26246,
                    "incorrect value for stec_residuals[12].residual, expected -26246, is {}",
                    msg.stec_residuals[12].residual
                );
                assert_eq!(
                    msg.stec_residuals[12].stddev, 124,
                    "incorrect value for stec_residuals[12].stddev, expected 124, is {}",
                    msg.stec_residuals[12].stddev
                );
                assert_eq!(msg.stec_residuals[12].sv_id.constellation, 157, "incorrect value for stec_residuals[12].sv_id.constellation, expected 157, is {}", msg.stec_residuals[12].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[12].sv_id.sat_id, 80,
                    "incorrect value for stec_residuals[12].sv_id.sat_id, expected 80, is {}",
                    msg.stec_residuals[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[13].residual, 26466,
                    "incorrect value for stec_residuals[13].residual, expected 26466, is {}",
                    msg.stec_residuals[13].residual
                );
                assert_eq!(
                    msg.stec_residuals[13].stddev, 204,
                    "incorrect value for stec_residuals[13].stddev, expected 204, is {}",
                    msg.stec_residuals[13].stddev
                );
                assert_eq!(msg.stec_residuals[13].sv_id.constellation, 128, "incorrect value for stec_residuals[13].sv_id.constellation, expected 128, is {}", msg.stec_residuals[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[13].sv_id.sat_id, 27,
                    "incorrect value for stec_residuals[13].sv_id.sat_id, expected 27, is {}",
                    msg.stec_residuals[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[14].residual, -7552,
                    "incorrect value for stec_residuals[14].residual, expected -7552, is {}",
                    msg.stec_residuals[14].residual
                );
                assert_eq!(
                    msg.stec_residuals[14].stddev, 148,
                    "incorrect value for stec_residuals[14].stddev, expected 148, is {}",
                    msg.stec_residuals[14].stddev
                );
                assert_eq!(msg.stec_residuals[14].sv_id.constellation, 238, "incorrect value for stec_residuals[14].sv_id.constellation, expected 238, is {}", msg.stec_residuals[14].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[14].sv_id.sat_id, 75,
                    "incorrect value for stec_residuals[14].sv_id.sat_id, expected 75, is {}",
                    msg.stec_residuals[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[15].residual, -12072,
                    "incorrect value for stec_residuals[15].residual, expected -12072, is {}",
                    msg.stec_residuals[15].residual
                );
                assert_eq!(
                    msg.stec_residuals[15].stddev, 149,
                    "incorrect value for stec_residuals[15].stddev, expected 149, is {}",
                    msg.stec_residuals[15].stddev
                );
                assert_eq!(msg.stec_residuals[15].sv_id.constellation, 61, "incorrect value for stec_residuals[15].sv_id.constellation, expected 61, is {}", msg.stec_residuals[15].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[15].sv_id.sat_id, 248,
                    "incorrect value for stec_residuals[15].sv_id.sat_id, expected 248, is {}",
                    msg.stec_residuals[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[16].residual, -28632,
                    "incorrect value for stec_residuals[16].residual, expected -28632, is {}",
                    msg.stec_residuals[16].residual
                );
                assert_eq!(
                    msg.stec_residuals[16].stddev, 186,
                    "incorrect value for stec_residuals[16].stddev, expected 186, is {}",
                    msg.stec_residuals[16].stddev
                );
                assert_eq!(msg.stec_residuals[16].sv_id.constellation, 224, "incorrect value for stec_residuals[16].sv_id.constellation, expected 224, is {}", msg.stec_residuals[16].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[16].sv_id.sat_id, 167,
                    "incorrect value for stec_residuals[16].sv_id.sat_id, expected 167, is {}",
                    msg.stec_residuals[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[17].residual, -4024,
                    "incorrect value for stec_residuals[17].residual, expected -4024, is {}",
                    msg.stec_residuals[17].residual
                );
                assert_eq!(
                    msg.stec_residuals[17].stddev, 100,
                    "incorrect value for stec_residuals[17].stddev, expected 100, is {}",
                    msg.stec_residuals[17].stddev
                );
                assert_eq!(msg.stec_residuals[17].sv_id.constellation, 227, "incorrect value for stec_residuals[17].sv_id.constellation, expected 227, is {}", msg.stec_residuals[17].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[17].sv_id.sat_id, 157,
                    "incorrect value for stec_residuals[17].sv_id.sat_id, expected 157, is {}",
                    msg.stec_residuals[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[18].residual, 2004,
                    "incorrect value for stec_residuals[18].residual, expected 2004, is {}",
                    msg.stec_residuals[18].residual
                );
                assert_eq!(
                    msg.stec_residuals[18].stddev, 59,
                    "incorrect value for stec_residuals[18].stddev, expected 59, is {}",
                    msg.stec_residuals[18].stddev
                );
                assert_eq!(msg.stec_residuals[18].sv_id.constellation, 12, "incorrect value for stec_residuals[18].sv_id.constellation, expected 12, is {}", msg.stec_residuals[18].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[18].sv_id.sat_id, 35,
                    "incorrect value for stec_residuals[18].sv_id.sat_id, expected 35, is {}",
                    msg.stec_residuals[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[19].residual, 6998,
                    "incorrect value for stec_residuals[19].residual, expected 6998, is {}",
                    msg.stec_residuals[19].residual
                );
                assert_eq!(
                    msg.stec_residuals[19].stddev, 24,
                    "incorrect value for stec_residuals[19].stddev, expected 24, is {}",
                    msg.stec_residuals[19].stddev
                );
                assert_eq!(msg.stec_residuals[19].sv_id.constellation, 81, "incorrect value for stec_residuals[19].sv_id.constellation, expected 81, is {}", msg.stec_residuals[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[19].sv_id.sat_id, 176,
                    "incorrect value for stec_residuals[19].sv_id.sat_id, expected 176, is {}",
                    msg.stec_residuals[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[20].residual, -31701,
                    "incorrect value for stec_residuals[20].residual, expected -31701, is {}",
                    msg.stec_residuals[20].residual
                );
                assert_eq!(
                    msg.stec_residuals[20].stddev, 45,
                    "incorrect value for stec_residuals[20].stddev, expected 45, is {}",
                    msg.stec_residuals[20].stddev
                );
                assert_eq!(msg.stec_residuals[20].sv_id.constellation, 67, "incorrect value for stec_residuals[20].sv_id.constellation, expected 67, is {}", msg.stec_residuals[20].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[20].sv_id.sat_id, 155,
                    "incorrect value for stec_residuals[20].sv_id.sat_id, expected 155, is {}",
                    msg.stec_residuals[20].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[21].residual, 28678,
                    "incorrect value for stec_residuals[21].residual, expected 28678, is {}",
                    msg.stec_residuals[21].residual
                );
                assert_eq!(
                    msg.stec_residuals[21].stddev, 183,
                    "incorrect value for stec_residuals[21].stddev, expected 183, is {}",
                    msg.stec_residuals[21].stddev
                );
                assert_eq!(msg.stec_residuals[21].sv_id.constellation, 44, "incorrect value for stec_residuals[21].sv_id.constellation, expected 44, is {}", msg.stec_residuals[21].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[21].sv_id.sat_id, 203,
                    "incorrect value for stec_residuals[21].sv_id.sat_id, expected 203, is {}",
                    msg.stec_residuals[21].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[22].residual, -15793,
                    "incorrect value for stec_residuals[22].residual, expected -15793, is {}",
                    msg.stec_residuals[22].residual
                );
                assert_eq!(
                    msg.stec_residuals[22].stddev, 253,
                    "incorrect value for stec_residuals[22].stddev, expected 253, is {}",
                    msg.stec_residuals[22].stddev
                );
                assert_eq!(msg.stec_residuals[22].sv_id.constellation, 176, "incorrect value for stec_residuals[22].sv_id.constellation, expected 176, is {}", msg.stec_residuals[22].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[22].sv_id.sat_id, 231,
                    "incorrect value for stec_residuals[22].sv_id.sat_id, expected 231, is {}",
                    msg.stec_residuals[22].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[23].residual, -7589,
                    "incorrect value for stec_residuals[23].residual, expected -7589, is {}",
                    msg.stec_residuals[23].residual
                );
                assert_eq!(
                    msg.stec_residuals[23].stddev, 116,
                    "incorrect value for stec_residuals[23].stddev, expected 116, is {}",
                    msg.stec_residuals[23].stddev
                );
                assert_eq!(msg.stec_residuals[23].sv_id.constellation, 103, "incorrect value for stec_residuals[23].sv_id.constellation, expected 103, is {}", msg.stec_residuals[23].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[23].sv_id.sat_id, 247,
                    "incorrect value for stec_residuals[23].sv_id.sat_id, expected 247, is {}",
                    msg.stec_residuals[23].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[24].residual, -7362,
                    "incorrect value for stec_residuals[24].residual, expected -7362, is {}",
                    msg.stec_residuals[24].residual
                );
                assert_eq!(
                    msg.stec_residuals[24].stddev, 240,
                    "incorrect value for stec_residuals[24].stddev, expected 240, is {}",
                    msg.stec_residuals[24].stddev
                );
                assert_eq!(msg.stec_residuals[24].sv_id.constellation, 23, "incorrect value for stec_residuals[24].sv_id.constellation, expected 23, is {}", msg.stec_residuals[24].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[24].sv_id.sat_id, 148,
                    "incorrect value for stec_residuals[24].sv_id.sat_id, expected 148, is {}",
                    msg.stec_residuals[24].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[25].residual, 4813,
                    "incorrect value for stec_residuals[25].residual, expected 4813, is {}",
                    msg.stec_residuals[25].residual
                );
                assert_eq!(
                    msg.stec_residuals[25].stddev, 242,
                    "incorrect value for stec_residuals[25].stddev, expected 242, is {}",
                    msg.stec_residuals[25].stddev
                );
                assert_eq!(msg.stec_residuals[25].sv_id.constellation, 219, "incorrect value for stec_residuals[25].sv_id.constellation, expected 219, is {}", msg.stec_residuals[25].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[25].sv_id.sat_id, 29,
                    "incorrect value for stec_residuals[25].sv_id.sat_id, expected 29, is {}",
                    msg.stec_residuals[25].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[26].residual, 20295,
                    "incorrect value for stec_residuals[26].residual, expected 20295, is {}",
                    msg.stec_residuals[26].residual
                );
                assert_eq!(
                    msg.stec_residuals[26].stddev, 37,
                    "incorrect value for stec_residuals[26].stddev, expected 37, is {}",
                    msg.stec_residuals[26].stddev
                );
                assert_eq!(msg.stec_residuals[26].sv_id.constellation, 72, "incorrect value for stec_residuals[26].sv_id.constellation, expected 72, is {}", msg.stec_residuals[26].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[26].sv_id.sat_id, 207,
                    "incorrect value for stec_residuals[26].sv_id.sat_id, expected 207, is {}",
                    msg.stec_residuals[26].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[27].residual, -13623,
                    "incorrect value for stec_residuals[27].residual, expected -13623, is {}",
                    msg.stec_residuals[27].residual
                );
                assert_eq!(
                    msg.stec_residuals[27].stddev, 91,
                    "incorrect value for stec_residuals[27].stddev, expected 91, is {}",
                    msg.stec_residuals[27].stddev
                );
                assert_eq!(msg.stec_residuals[27].sv_id.constellation, 176, "incorrect value for stec_residuals[27].sv_id.constellation, expected 176, is {}", msg.stec_residuals[27].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[27].sv_id.sat_id, 42,
                    "incorrect value for stec_residuals[27].sv_id.sat_id, expected 42, is {}",
                    msg.stec_residuals[27].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[28].residual, 15250,
                    "incorrect value for stec_residuals[28].residual, expected 15250, is {}",
                    msg.stec_residuals[28].residual
                );
                assert_eq!(
                    msg.stec_residuals[28].stddev, 110,
                    "incorrect value for stec_residuals[28].stddev, expected 110, is {}",
                    msg.stec_residuals[28].stddev
                );
                assert_eq!(msg.stec_residuals[28].sv_id.constellation, 115, "incorrect value for stec_residuals[28].sv_id.constellation, expected 115, is {}", msg.stec_residuals[28].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[28].sv_id.sat_id, 105,
                    "incorrect value for stec_residuals[28].sv_id.sat_id, expected 105, is {}",
                    msg.stec_residuals[28].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[29].residual, -18560,
                    "incorrect value for stec_residuals[29].residual, expected -18560, is {}",
                    msg.stec_residuals[29].residual
                );
                assert_eq!(
                    msg.stec_residuals[29].stddev, 185,
                    "incorrect value for stec_residuals[29].stddev, expected 185, is {}",
                    msg.stec_residuals[29].stddev
                );
                assert_eq!(msg.stec_residuals[29].sv_id.constellation, 109, "incorrect value for stec_residuals[29].sv_id.constellation, expected 109, is {}", msg.stec_residuals[29].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[29].sv_id.sat_id, 44,
                    "incorrect value for stec_residuals[29].sv_id.sat_id, expected 44, is {}",
                    msg.stec_residuals[29].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[30].residual, 23717,
                    "incorrect value for stec_residuals[30].residual, expected 23717, is {}",
                    msg.stec_residuals[30].residual
                );
                assert_eq!(
                    msg.stec_residuals[30].stddev, 79,
                    "incorrect value for stec_residuals[30].stddev, expected 79, is {}",
                    msg.stec_residuals[30].stddev
                );
                assert_eq!(msg.stec_residuals[30].sv_id.constellation, 31, "incorrect value for stec_residuals[30].sv_id.constellation, expected 31, is {}", msg.stec_residuals[30].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[30].sv_id.sat_id, 67,
                    "incorrect value for stec_residuals[30].sv_id.sat_id, expected 67, is {}",
                    msg.stec_residuals[30].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[31].residual, 1886,
                    "incorrect value for stec_residuals[31].residual, expected 1886, is {}",
                    msg.stec_residuals[31].residual
                );
                assert_eq!(
                    msg.stec_residuals[31].stddev, 162,
                    "incorrect value for stec_residuals[31].stddev, expected 162, is {}",
                    msg.stec_residuals[31].stddev
                );
                assert_eq!(msg.stec_residuals[31].sv_id.constellation, 180, "incorrect value for stec_residuals[31].sv_id.constellation, expected 180, is {}", msg.stec_residuals[31].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[31].sv_id.sat_id, 189,
                    "incorrect value for stec_residuals[31].sv_id.sat_id, expected 189, is {}",
                    msg.stec_residuals[31].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[32].residual, 12242,
                    "incorrect value for stec_residuals[32].residual, expected 12242, is {}",
                    msg.stec_residuals[32].residual
                );
                assert_eq!(
                    msg.stec_residuals[32].stddev, 7,
                    "incorrect value for stec_residuals[32].stddev, expected 7, is {}",
                    msg.stec_residuals[32].stddev
                );
                assert_eq!(msg.stec_residuals[32].sv_id.constellation, 156, "incorrect value for stec_residuals[32].sv_id.constellation, expected 156, is {}", msg.stec_residuals[32].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[32].sv_id.sat_id, 121,
                    "incorrect value for stec_residuals[32].sv_id.sat_id, expected 121, is {}",
                    msg.stec_residuals[32].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[33].residual, 10670,
                    "incorrect value for stec_residuals[33].residual, expected 10670, is {}",
                    msg.stec_residuals[33].residual
                );
                assert_eq!(
                    msg.stec_residuals[33].stddev, 241,
                    "incorrect value for stec_residuals[33].stddev, expected 241, is {}",
                    msg.stec_residuals[33].stddev
                );
                assert_eq!(msg.stec_residuals[33].sv_id.constellation, 205, "incorrect value for stec_residuals[33].sv_id.constellation, expected 205, is {}", msg.stec_residuals[33].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[33].sv_id.sat_id, 7,
                    "incorrect value for stec_residuals[33].sv_id.sat_id, expected 7, is {}",
                    msg.stec_residuals[33].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[34].residual, 25899,
                    "incorrect value for stec_residuals[34].residual, expected 25899, is {}",
                    msg.stec_residuals[34].residual
                );
                assert_eq!(
                    msg.stec_residuals[34].stddev, 186,
                    "incorrect value for stec_residuals[34].stddev, expected 186, is {}",
                    msg.stec_residuals[34].stddev
                );
                assert_eq!(msg.stec_residuals[34].sv_id.constellation, 210, "incorrect value for stec_residuals[34].sv_id.constellation, expected 210, is {}", msg.stec_residuals[34].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[34].sv_id.sat_id, 129,
                    "incorrect value for stec_residuals[34].sv_id.sat_id, expected 129, is {}",
                    msg.stec_residuals[34].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[35].residual, -2078,
                    "incorrect value for stec_residuals[35].residual, expected -2078, is {}",
                    msg.stec_residuals[35].residual
                );
                assert_eq!(
                    msg.stec_residuals[35].stddev, 187,
                    "incorrect value for stec_residuals[35].stddev, expected 187, is {}",
                    msg.stec_residuals[35].stddev
                );
                assert_eq!(msg.stec_residuals[35].sv_id.constellation, 195, "incorrect value for stec_residuals[35].sv_id.constellation, expected 195, is {}", msg.stec_residuals[35].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[35].sv_id.sat_id, 208,
                    "incorrect value for stec_residuals[35].sv_id.sat_id, expected 208, is {}",
                    msg.stec_residuals[35].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[36].residual, -16264,
                    "incorrect value for stec_residuals[36].residual, expected -16264, is {}",
                    msg.stec_residuals[36].residual
                );
                assert_eq!(
                    msg.stec_residuals[36].stddev, 102,
                    "incorrect value for stec_residuals[36].stddev, expected 102, is {}",
                    msg.stec_residuals[36].stddev
                );
                assert_eq!(msg.stec_residuals[36].sv_id.constellation, 160, "incorrect value for stec_residuals[36].sv_id.constellation, expected 160, is {}", msg.stec_residuals[36].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[36].sv_id.sat_id, 219,
                    "incorrect value for stec_residuals[36].sv_id.sat_id, expected 219, is {}",
                    msg.stec_residuals[36].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[37].residual, -21002,
                    "incorrect value for stec_residuals[37].residual, expected -21002, is {}",
                    msg.stec_residuals[37].residual
                );
                assert_eq!(
                    msg.stec_residuals[37].stddev, 94,
                    "incorrect value for stec_residuals[37].stddev, expected 94, is {}",
                    msg.stec_residuals[37].stddev
                );
                assert_eq!(msg.stec_residuals[37].sv_id.constellation, 42, "incorrect value for stec_residuals[37].sv_id.constellation, expected 42, is {}", msg.stec_residuals[37].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[37].sv_id.sat_id, 166,
                    "incorrect value for stec_residuals[37].sv_id.sat_id, expected 166, is {}",
                    msg.stec_residuals[37].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[38].residual, 7902,
                    "incorrect value for stec_residuals[38].residual, expected 7902, is {}",
                    msg.stec_residuals[38].residual
                );
                assert_eq!(
                    msg.stec_residuals[38].stddev, 35,
                    "incorrect value for stec_residuals[38].stddev, expected 35, is {}",
                    msg.stec_residuals[38].stddev
                );
                assert_eq!(msg.stec_residuals[38].sv_id.constellation, 156, "incorrect value for stec_residuals[38].sv_id.constellation, expected 156, is {}", msg.stec_residuals[38].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[38].sv_id.sat_id, 102,
                    "incorrect value for stec_residuals[38].sv_id.sat_id, expected 102, is {}",
                    msg.stec_residuals[38].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[39].residual, -30275,
                    "incorrect value for stec_residuals[39].residual, expected -30275, is {}",
                    msg.stec_residuals[39].residual
                );
                assert_eq!(
                    msg.stec_residuals[39].stddev, 204,
                    "incorrect value for stec_residuals[39].stddev, expected 204, is {}",
                    msg.stec_residuals[39].stddev
                );
                assert_eq!(msg.stec_residuals[39].sv_id.constellation, 64, "incorrect value for stec_residuals[39].sv_id.constellation, expected 64, is {}", msg.stec_residuals[39].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[39].sv_id.sat_id, 247,
                    "incorrect value for stec_residuals[39].sv_id.sat_id, expected 247, is {}",
                    msg.stec_residuals[39].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[40].residual, -8633,
                    "incorrect value for stec_residuals[40].residual, expected -8633, is {}",
                    msg.stec_residuals[40].residual
                );
                assert_eq!(
                    msg.stec_residuals[40].stddev, 222,
                    "incorrect value for stec_residuals[40].stddev, expected 222, is {}",
                    msg.stec_residuals[40].stddev
                );
                assert_eq!(msg.stec_residuals[40].sv_id.constellation, 32, "incorrect value for stec_residuals[40].sv_id.constellation, expected 32, is {}", msg.stec_residuals[40].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[40].sv_id.sat_id, 220,
                    "incorrect value for stec_residuals[40].sv_id.sat_id, expected 220, is {}",
                    msg.stec_residuals[40].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[41].residual, 6403,
                    "incorrect value for stec_residuals[41].residual, expected 6403, is {}",
                    msg.stec_residuals[41].residual
                );
                assert_eq!(
                    msg.stec_residuals[41].stddev, 45,
                    "incorrect value for stec_residuals[41].stddev, expected 45, is {}",
                    msg.stec_residuals[41].stddev
                );
                assert_eq!(msg.stec_residuals[41].sv_id.constellation, 246, "incorrect value for stec_residuals[41].sv_id.constellation, expected 246, is {}", msg.stec_residuals[41].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[41].sv_id.sat_id, 201,
                    "incorrect value for stec_residuals[41].sv_id.sat_id, expected 201, is {}",
                    msg.stec_residuals[41].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[42].residual, 22643,
                    "incorrect value for stec_residuals[42].residual, expected 22643, is {}",
                    msg.stec_residuals[42].residual
                );
                assert_eq!(
                    msg.stec_residuals[42].stddev, 218,
                    "incorrect value for stec_residuals[42].stddev, expected 218, is {}",
                    msg.stec_residuals[42].stddev
                );
                assert_eq!(msg.stec_residuals[42].sv_id.constellation, 239, "incorrect value for stec_residuals[42].sv_id.constellation, expected 239, is {}", msg.stec_residuals[42].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[42].sv_id.sat_id, 251,
                    "incorrect value for stec_residuals[42].sv_id.sat_id, expected 251, is {}",
                    msg.stec_residuals[42].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[43].residual, 16760,
                    "incorrect value for stec_residuals[43].residual, expected 16760, is {}",
                    msg.stec_residuals[43].residual
                );
                assert_eq!(
                    msg.stec_residuals[43].stddev, 175,
                    "incorrect value for stec_residuals[43].stddev, expected 175, is {}",
                    msg.stec_residuals[43].stddev
                );
                assert_eq!(msg.stec_residuals[43].sv_id.constellation, 209, "incorrect value for stec_residuals[43].sv_id.constellation, expected 209, is {}", msg.stec_residuals[43].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[43].sv_id.sat_id, 10,
                    "incorrect value for stec_residuals[43].sv_id.sat_id, expected 10, is {}",
                    msg.stec_residuals[43].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[44].residual, -20951,
                    "incorrect value for stec_residuals[44].residual, expected -20951, is {}",
                    msg.stec_residuals[44].residual
                );
                assert_eq!(
                    msg.stec_residuals[44].stddev, 137,
                    "incorrect value for stec_residuals[44].stddev, expected 137, is {}",
                    msg.stec_residuals[44].stddev
                );
                assert_eq!(msg.stec_residuals[44].sv_id.constellation, 194, "incorrect value for stec_residuals[44].sv_id.constellation, expected 194, is {}", msg.stec_residuals[44].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[44].sv_id.sat_id, 131,
                    "incorrect value for stec_residuals[44].sv_id.sat_id, expected 131, is {}",
                    msg.stec_residuals[44].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[45].residual, -740,
                    "incorrect value for stec_residuals[45].residual, expected -740, is {}",
                    msg.stec_residuals[45].residual
                );
                assert_eq!(
                    msg.stec_residuals[45].stddev, 42,
                    "incorrect value for stec_residuals[45].stddev, expected 42, is {}",
                    msg.stec_residuals[45].stddev
                );
                assert_eq!(msg.stec_residuals[45].sv_id.constellation, 68, "incorrect value for stec_residuals[45].sv_id.constellation, expected 68, is {}", msg.stec_residuals[45].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[45].sv_id.sat_id, 17,
                    "incorrect value for stec_residuals[45].sv_id.sat_id, expected 17, is {}",
                    msg.stec_residuals[45].sv_id.sat_id
                );
                assert_eq!(
                    msg.tropo_delay_correction.hydro, -3035,
                    "incorrect value for tropo_delay_correction.hydro, expected -3035, is {}",
                    msg.tropo_delay_correction.hydro
                );
                assert_eq!(
                    msg.tropo_delay_correction.stddev, 72,
                    "incorrect value for tropo_delay_correction.stddev, expected 72, is {}",
                    msg.tropo_delay_correction.stddev
                );
                assert_eq!(
                    msg.tropo_delay_correction.wet, 78,
                    "incorrect value for tropo_delay_correction.wet, expected 78, is {}",
                    msg.tropo_delay_correction.wet
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGriddedCorrection"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_gridded_correction`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_gridded_correction() {
    {
        let mut payload = Cursor::new(vec![
            85, 252, 5, 196, 249, 253, 21, 14, 151, 50, 120, 133, 29, 151, 174, 229, 151, 189, 204,
            196, 105, 170, 120, 149, 169, 37, 244, 78, 72, 140, 101, 2, 173, 88, 70, 180, 54, 152,
            115, 78, 201, 161, 23, 135, 152, 98, 61, 75, 178, 120, 229, 146, 55, 58, 169, 234, 230,
            69, 172, 191, 127, 146, 89, 150, 91, 111, 225, 41, 17, 119, 52, 166, 166, 120, 57, 221,
            12, 3, 156, 70, 156, 35, 127, 8, 127, 58, 128, 55, 115, 80, 157, 122, 153, 124, 27,
            128, 98, 103, 204, 75, 238, 128, 226, 148, 248, 61, 216, 208, 149, 167, 224, 40, 144,
            186, 157, 227, 72, 240, 100, 35, 12, 212, 7, 59, 176, 81, 86, 27, 24, 155, 67, 43, 132,
            45, 203, 44, 6, 112, 183, 231, 176, 79, 194, 253, 247, 103, 91, 226, 116, 148, 23, 62,
            227, 240, 29, 219, 205, 18, 242, 207, 72, 71, 79, 37, 42, 176, 201, 202, 91, 105, 115,
            146, 59, 110, 44, 109, 128, 183, 185, 67, 31, 165, 92, 79, 189, 180, 94, 7, 162, 121,
            156, 210, 47, 7, 7, 205, 174, 41, 241, 129, 210, 43, 101, 186, 208, 195, 226, 247, 187,
            219, 160, 120, 192, 102, 166, 42, 246, 173, 94, 102, 156, 222, 30, 35, 247, 64, 189,
            137, 204, 220, 32, 71, 222, 222, 201, 246, 3, 25, 45, 251, 239, 115, 88, 218, 10, 209,
            120, 65, 175, 131, 194, 41, 174, 137, 17, 68, 28, 253, 42, 178, 35,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrGriddedCorrection(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrGriddedCorrection(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5fc,
                    "Incorrect message type, expected 0x5fc, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf9c4,
                    "incorrect sender id, expected 0xf9c4, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 170,
                    "incorrect value for header.iod_atmo, expected 170, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 48535,
                    "incorrect value for header.num_msgs, expected 48535, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 50380,
                    "incorrect value for header.seq_num, expected 50380, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.tile_id, 12951,
                    "incorrect value for header.tile_id, expected 12951, is {}",
                    msg.header.tile_id
                );
                assert_eq!(
                    msg.header.tile_set_id, 3605,
                    "incorrect value for header.tile_set_id, expected 3605, is {}",
                    msg.header.tile_set_id
                );
                assert_eq!(
                    msg.header.time.tow, 2535294328,
                    "incorrect value for header.time.tow, expected 2535294328, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 58798,
                    "incorrect value for header.time.wn, expected 58798, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.tropo_quality_indicator, 120,
                    "incorrect value for header.tropo_quality_indicator, expected 120, is {}",
                    msg.header.tropo_quality_indicator
                );
                assert_eq!(
                    msg.header.update_interval, 105,
                    "incorrect value for header.update_interval, expected 105, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.index, 43413,
                    "incorrect value for index, expected 43413, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.stec_residuals[0].residual, -21246,
                    "incorrect value for stec_residuals[0].residual, expected -21246, is {}",
                    msg.stec_residuals[0].residual
                );
                assert_eq!(
                    msg.stec_residuals[0].stddev, 88,
                    "incorrect value for stec_residuals[0].stddev, expected 88, is {}",
                    msg.stec_residuals[0].stddev
                );
                assert_eq!(msg.stec_residuals[0].sv_id.constellation, 101, "incorrect value for stec_residuals[0].sv_id.constellation, expected 101, is {}", msg.stec_residuals[0].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[0].sv_id.sat_id, 140,
                    "incorrect value for stec_residuals[0].sv_id.sat_id, expected 140, is {}",
                    msg.stec_residuals[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[1].residual, -26570,
                    "incorrect value for stec_residuals[1].residual, expected -26570, is {}",
                    msg.stec_residuals[1].residual
                );
                assert_eq!(
                    msg.stec_residuals[1].stddev, 115,
                    "incorrect value for stec_residuals[1].stddev, expected 115, is {}",
                    msg.stec_residuals[1].stddev
                );
                assert_eq!(msg.stec_residuals[1].sv_id.constellation, 180, "incorrect value for stec_residuals[1].sv_id.constellation, expected 180, is {}", msg.stec_residuals[1].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[1].sv_id.sat_id, 70,
                    "incorrect value for stec_residuals[1].sv_id.sat_id, expected 70, is {}",
                    msg.stec_residuals[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[2].residual, 6049,
                    "incorrect value for stec_residuals[2].residual, expected 6049, is {}",
                    msg.stec_residuals[2].residual
                );
                assert_eq!(
                    msg.stec_residuals[2].stddev, 135,
                    "incorrect value for stec_residuals[2].stddev, expected 135, is {}",
                    msg.stec_residuals[2].stddev
                );
                assert_eq!(msg.stec_residuals[2].sv_id.constellation, 201, "incorrect value for stec_residuals[2].sv_id.constellation, expected 201, is {}", msg.stec_residuals[2].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[2].sv_id.sat_id, 78,
                    "incorrect value for stec_residuals[2].sv_id.sat_id, expected 78, is {}",
                    msg.stec_residuals[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[3].residual, 19261,
                    "incorrect value for stec_residuals[3].residual, expected 19261, is {}",
                    msg.stec_residuals[3].residual
                );
                assert_eq!(
                    msg.stec_residuals[3].stddev, 178,
                    "incorrect value for stec_residuals[3].stddev, expected 178, is {}",
                    msg.stec_residuals[3].stddev
                );
                assert_eq!(
                    msg.stec_residuals[3].sv_id.constellation, 98,
                    "incorrect value for stec_residuals[3].sv_id.constellation, expected 98, is {}",
                    msg.stec_residuals[3].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[3].sv_id.sat_id, 152,
                    "incorrect value for stec_residuals[3].sv_id.sat_id, expected 152, is {}",
                    msg.stec_residuals[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[4].residual, 14226,
                    "incorrect value for stec_residuals[4].residual, expected 14226, is {}",
                    msg.stec_residuals[4].residual
                );
                assert_eq!(
                    msg.stec_residuals[4].stddev, 58,
                    "incorrect value for stec_residuals[4].stddev, expected 58, is {}",
                    msg.stec_residuals[4].stddev
                );
                assert_eq!(msg.stec_residuals[4].sv_id.constellation, 229, "incorrect value for stec_residuals[4].sv_id.constellation, expected 229, is {}", msg.stec_residuals[4].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[4].sv_id.sat_id, 120,
                    "incorrect value for stec_residuals[4].sv_id.sat_id, expected 120, is {}",
                    msg.stec_residuals[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[5].residual, 17894,
                    "incorrect value for stec_residuals[5].residual, expected 17894, is {}",
                    msg.stec_residuals[5].residual
                );
                assert_eq!(
                    msg.stec_residuals[5].stddev, 172,
                    "incorrect value for stec_residuals[5].stddev, expected 172, is {}",
                    msg.stec_residuals[5].stddev
                );
                assert_eq!(msg.stec_residuals[5].sv_id.constellation, 234, "incorrect value for stec_residuals[5].sv_id.constellation, expected 234, is {}", msg.stec_residuals[5].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[5].sv_id.sat_id, 169,
                    "incorrect value for stec_residuals[5].sv_id.sat_id, expected 169, is {}",
                    msg.stec_residuals[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[6].residual, 22930,
                    "incorrect value for stec_residuals[6].residual, expected 22930, is {}",
                    msg.stec_residuals[6].residual
                );
                assert_eq!(
                    msg.stec_residuals[6].stddev, 150,
                    "incorrect value for stec_residuals[6].stddev, expected 150, is {}",
                    msg.stec_residuals[6].stddev
                );
                assert_eq!(msg.stec_residuals[6].sv_id.constellation, 127, "incorrect value for stec_residuals[6].sv_id.constellation, expected 127, is {}", msg.stec_residuals[6].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[6].sv_id.sat_id, 191,
                    "incorrect value for stec_residuals[6].sv_id.sat_id, expected 191, is {}",
                    msg.stec_residuals[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[7].residual, 10721,
                    "incorrect value for stec_residuals[7].residual, expected 10721, is {}",
                    msg.stec_residuals[7].residual
                );
                assert_eq!(
                    msg.stec_residuals[7].stddev, 17,
                    "incorrect value for stec_residuals[7].stddev, expected 17, is {}",
                    msg.stec_residuals[7].stddev
                );
                assert_eq!(msg.stec_residuals[7].sv_id.constellation, 111, "incorrect value for stec_residuals[7].sv_id.constellation, expected 111, is {}", msg.stec_residuals[7].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[7].sv_id.sat_id, 91,
                    "incorrect value for stec_residuals[7].sv_id.sat_id, expected 91, is {}",
                    msg.stec_residuals[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[8].residual, -22874,
                    "incorrect value for stec_residuals[8].residual, expected -22874, is {}",
                    msg.stec_residuals[8].residual
                );
                assert_eq!(
                    msg.stec_residuals[8].stddev, 120,
                    "incorrect value for stec_residuals[8].stddev, expected 120, is {}",
                    msg.stec_residuals[8].stddev
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.constellation, 52,
                    "incorrect value for stec_residuals[8].sv_id.constellation, expected 52, is {}",
                    msg.stec_residuals[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.sat_id, 119,
                    "incorrect value for stec_residuals[8].sv_id.sat_id, expected 119, is {}",
                    msg.stec_residuals[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[9].residual, 780,
                    "incorrect value for stec_residuals[9].residual, expected 780, is {}",
                    msg.stec_residuals[9].residual
                );
                assert_eq!(
                    msg.stec_residuals[9].stddev, 156,
                    "incorrect value for stec_residuals[9].stddev, expected 156, is {}",
                    msg.stec_residuals[9].stddev
                );
                assert_eq!(msg.stec_residuals[9].sv_id.constellation, 221, "incorrect value for stec_residuals[9].sv_id.constellation, expected 221, is {}", msg.stec_residuals[9].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[9].sv_id.sat_id, 57,
                    "incorrect value for stec_residuals[9].sv_id.sat_id, expected 57, is {}",
                    msg.stec_residuals[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[10].residual, 32547,
                    "incorrect value for stec_residuals[10].residual, expected 32547, is {}",
                    msg.stec_residuals[10].residual
                );
                assert_eq!(
                    msg.stec_residuals[10].stddev, 8,
                    "incorrect value for stec_residuals[10].stddev, expected 8, is {}",
                    msg.stec_residuals[10].stddev
                );
                assert_eq!(msg.stec_residuals[10].sv_id.constellation, 156, "incorrect value for stec_residuals[10].sv_id.constellation, expected 156, is {}", msg.stec_residuals[10].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[10].sv_id.sat_id, 70,
                    "incorrect value for stec_residuals[10].sv_id.sat_id, expected 70, is {}",
                    msg.stec_residuals[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[11].residual, 14208,
                    "incorrect value for stec_residuals[11].residual, expected 14208, is {}",
                    msg.stec_residuals[11].residual
                );
                assert_eq!(
                    msg.stec_residuals[11].stddev, 115,
                    "incorrect value for stec_residuals[11].stddev, expected 115, is {}",
                    msg.stec_residuals[11].stddev
                );
                assert_eq!(msg.stec_residuals[11].sv_id.constellation, 58, "incorrect value for stec_residuals[11].sv_id.constellation, expected 58, is {}", msg.stec_residuals[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[11].sv_id.sat_id, 127,
                    "incorrect value for stec_residuals[11].sv_id.sat_id, expected 127, is {}",
                    msg.stec_residuals[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[12].residual, -26246,
                    "incorrect value for stec_residuals[12].residual, expected -26246, is {}",
                    msg.stec_residuals[12].residual
                );
                assert_eq!(
                    msg.stec_residuals[12].stddev, 124,
                    "incorrect value for stec_residuals[12].stddev, expected 124, is {}",
                    msg.stec_residuals[12].stddev
                );
                assert_eq!(msg.stec_residuals[12].sv_id.constellation, 157, "incorrect value for stec_residuals[12].sv_id.constellation, expected 157, is {}", msg.stec_residuals[12].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[12].sv_id.sat_id, 80,
                    "incorrect value for stec_residuals[12].sv_id.sat_id, expected 80, is {}",
                    msg.stec_residuals[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[13].residual, 26466,
                    "incorrect value for stec_residuals[13].residual, expected 26466, is {}",
                    msg.stec_residuals[13].residual
                );
                assert_eq!(
                    msg.stec_residuals[13].stddev, 204,
                    "incorrect value for stec_residuals[13].stddev, expected 204, is {}",
                    msg.stec_residuals[13].stddev
                );
                assert_eq!(msg.stec_residuals[13].sv_id.constellation, 128, "incorrect value for stec_residuals[13].sv_id.constellation, expected 128, is {}", msg.stec_residuals[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[13].sv_id.sat_id, 27,
                    "incorrect value for stec_residuals[13].sv_id.sat_id, expected 27, is {}",
                    msg.stec_residuals[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[14].residual, -7552,
                    "incorrect value for stec_residuals[14].residual, expected -7552, is {}",
                    msg.stec_residuals[14].residual
                );
                assert_eq!(
                    msg.stec_residuals[14].stddev, 148,
                    "incorrect value for stec_residuals[14].stddev, expected 148, is {}",
                    msg.stec_residuals[14].stddev
                );
                assert_eq!(msg.stec_residuals[14].sv_id.constellation, 238, "incorrect value for stec_residuals[14].sv_id.constellation, expected 238, is {}", msg.stec_residuals[14].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[14].sv_id.sat_id, 75,
                    "incorrect value for stec_residuals[14].sv_id.sat_id, expected 75, is {}",
                    msg.stec_residuals[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[15].residual, -12072,
                    "incorrect value for stec_residuals[15].residual, expected -12072, is {}",
                    msg.stec_residuals[15].residual
                );
                assert_eq!(
                    msg.stec_residuals[15].stddev, 149,
                    "incorrect value for stec_residuals[15].stddev, expected 149, is {}",
                    msg.stec_residuals[15].stddev
                );
                assert_eq!(msg.stec_residuals[15].sv_id.constellation, 61, "incorrect value for stec_residuals[15].sv_id.constellation, expected 61, is {}", msg.stec_residuals[15].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[15].sv_id.sat_id, 248,
                    "incorrect value for stec_residuals[15].sv_id.sat_id, expected 248, is {}",
                    msg.stec_residuals[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[16].residual, -28632,
                    "incorrect value for stec_residuals[16].residual, expected -28632, is {}",
                    msg.stec_residuals[16].residual
                );
                assert_eq!(
                    msg.stec_residuals[16].stddev, 186,
                    "incorrect value for stec_residuals[16].stddev, expected 186, is {}",
                    msg.stec_residuals[16].stddev
                );
                assert_eq!(msg.stec_residuals[16].sv_id.constellation, 224, "incorrect value for stec_residuals[16].sv_id.constellation, expected 224, is {}", msg.stec_residuals[16].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[16].sv_id.sat_id, 167,
                    "incorrect value for stec_residuals[16].sv_id.sat_id, expected 167, is {}",
                    msg.stec_residuals[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[17].residual, -4024,
                    "incorrect value for stec_residuals[17].residual, expected -4024, is {}",
                    msg.stec_residuals[17].residual
                );
                assert_eq!(
                    msg.stec_residuals[17].stddev, 100,
                    "incorrect value for stec_residuals[17].stddev, expected 100, is {}",
                    msg.stec_residuals[17].stddev
                );
                assert_eq!(msg.stec_residuals[17].sv_id.constellation, 227, "incorrect value for stec_residuals[17].sv_id.constellation, expected 227, is {}", msg.stec_residuals[17].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[17].sv_id.sat_id, 157,
                    "incorrect value for stec_residuals[17].sv_id.sat_id, expected 157, is {}",
                    msg.stec_residuals[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[18].residual, 2004,
                    "incorrect value for stec_residuals[18].residual, expected 2004, is {}",
                    msg.stec_residuals[18].residual
                );
                assert_eq!(
                    msg.stec_residuals[18].stddev, 59,
                    "incorrect value for stec_residuals[18].stddev, expected 59, is {}",
                    msg.stec_residuals[18].stddev
                );
                assert_eq!(msg.stec_residuals[18].sv_id.constellation, 12, "incorrect value for stec_residuals[18].sv_id.constellation, expected 12, is {}", msg.stec_residuals[18].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[18].sv_id.sat_id, 35,
                    "incorrect value for stec_residuals[18].sv_id.sat_id, expected 35, is {}",
                    msg.stec_residuals[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[19].residual, 6998,
                    "incorrect value for stec_residuals[19].residual, expected 6998, is {}",
                    msg.stec_residuals[19].residual
                );
                assert_eq!(
                    msg.stec_residuals[19].stddev, 24,
                    "incorrect value for stec_residuals[19].stddev, expected 24, is {}",
                    msg.stec_residuals[19].stddev
                );
                assert_eq!(msg.stec_residuals[19].sv_id.constellation, 81, "incorrect value for stec_residuals[19].sv_id.constellation, expected 81, is {}", msg.stec_residuals[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[19].sv_id.sat_id, 176,
                    "incorrect value for stec_residuals[19].sv_id.sat_id, expected 176, is {}",
                    msg.stec_residuals[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[20].residual, -31701,
                    "incorrect value for stec_residuals[20].residual, expected -31701, is {}",
                    msg.stec_residuals[20].residual
                );
                assert_eq!(
                    msg.stec_residuals[20].stddev, 45,
                    "incorrect value for stec_residuals[20].stddev, expected 45, is {}",
                    msg.stec_residuals[20].stddev
                );
                assert_eq!(msg.stec_residuals[20].sv_id.constellation, 67, "incorrect value for stec_residuals[20].sv_id.constellation, expected 67, is {}", msg.stec_residuals[20].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[20].sv_id.sat_id, 155,
                    "incorrect value for stec_residuals[20].sv_id.sat_id, expected 155, is {}",
                    msg.stec_residuals[20].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[21].residual, 28678,
                    "incorrect value for stec_residuals[21].residual, expected 28678, is {}",
                    msg.stec_residuals[21].residual
                );
                assert_eq!(
                    msg.stec_residuals[21].stddev, 183,
                    "incorrect value for stec_residuals[21].stddev, expected 183, is {}",
                    msg.stec_residuals[21].stddev
                );
                assert_eq!(msg.stec_residuals[21].sv_id.constellation, 44, "incorrect value for stec_residuals[21].sv_id.constellation, expected 44, is {}", msg.stec_residuals[21].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[21].sv_id.sat_id, 203,
                    "incorrect value for stec_residuals[21].sv_id.sat_id, expected 203, is {}",
                    msg.stec_residuals[21].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[22].residual, -15793,
                    "incorrect value for stec_residuals[22].residual, expected -15793, is {}",
                    msg.stec_residuals[22].residual
                );
                assert_eq!(
                    msg.stec_residuals[22].stddev, 253,
                    "incorrect value for stec_residuals[22].stddev, expected 253, is {}",
                    msg.stec_residuals[22].stddev
                );
                assert_eq!(msg.stec_residuals[22].sv_id.constellation, 176, "incorrect value for stec_residuals[22].sv_id.constellation, expected 176, is {}", msg.stec_residuals[22].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[22].sv_id.sat_id, 231,
                    "incorrect value for stec_residuals[22].sv_id.sat_id, expected 231, is {}",
                    msg.stec_residuals[22].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[23].residual, -7589,
                    "incorrect value for stec_residuals[23].residual, expected -7589, is {}",
                    msg.stec_residuals[23].residual
                );
                assert_eq!(
                    msg.stec_residuals[23].stddev, 116,
                    "incorrect value for stec_residuals[23].stddev, expected 116, is {}",
                    msg.stec_residuals[23].stddev
                );
                assert_eq!(msg.stec_residuals[23].sv_id.constellation, 103, "incorrect value for stec_residuals[23].sv_id.constellation, expected 103, is {}", msg.stec_residuals[23].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[23].sv_id.sat_id, 247,
                    "incorrect value for stec_residuals[23].sv_id.sat_id, expected 247, is {}",
                    msg.stec_residuals[23].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[24].residual, -7362,
                    "incorrect value for stec_residuals[24].residual, expected -7362, is {}",
                    msg.stec_residuals[24].residual
                );
                assert_eq!(
                    msg.stec_residuals[24].stddev, 240,
                    "incorrect value for stec_residuals[24].stddev, expected 240, is {}",
                    msg.stec_residuals[24].stddev
                );
                assert_eq!(msg.stec_residuals[24].sv_id.constellation, 23, "incorrect value for stec_residuals[24].sv_id.constellation, expected 23, is {}", msg.stec_residuals[24].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[24].sv_id.sat_id, 148,
                    "incorrect value for stec_residuals[24].sv_id.sat_id, expected 148, is {}",
                    msg.stec_residuals[24].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[25].residual, 4813,
                    "incorrect value for stec_residuals[25].residual, expected 4813, is {}",
                    msg.stec_residuals[25].residual
                );
                assert_eq!(
                    msg.stec_residuals[25].stddev, 242,
                    "incorrect value for stec_residuals[25].stddev, expected 242, is {}",
                    msg.stec_residuals[25].stddev
                );
                assert_eq!(msg.stec_residuals[25].sv_id.constellation, 219, "incorrect value for stec_residuals[25].sv_id.constellation, expected 219, is {}", msg.stec_residuals[25].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[25].sv_id.sat_id, 29,
                    "incorrect value for stec_residuals[25].sv_id.sat_id, expected 29, is {}",
                    msg.stec_residuals[25].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[26].residual, 20295,
                    "incorrect value for stec_residuals[26].residual, expected 20295, is {}",
                    msg.stec_residuals[26].residual
                );
                assert_eq!(
                    msg.stec_residuals[26].stddev, 37,
                    "incorrect value for stec_residuals[26].stddev, expected 37, is {}",
                    msg.stec_residuals[26].stddev
                );
                assert_eq!(msg.stec_residuals[26].sv_id.constellation, 72, "incorrect value for stec_residuals[26].sv_id.constellation, expected 72, is {}", msg.stec_residuals[26].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[26].sv_id.sat_id, 207,
                    "incorrect value for stec_residuals[26].sv_id.sat_id, expected 207, is {}",
                    msg.stec_residuals[26].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[27].residual, -13623,
                    "incorrect value for stec_residuals[27].residual, expected -13623, is {}",
                    msg.stec_residuals[27].residual
                );
                assert_eq!(
                    msg.stec_residuals[27].stddev, 91,
                    "incorrect value for stec_residuals[27].stddev, expected 91, is {}",
                    msg.stec_residuals[27].stddev
                );
                assert_eq!(msg.stec_residuals[27].sv_id.constellation, 176, "incorrect value for stec_residuals[27].sv_id.constellation, expected 176, is {}", msg.stec_residuals[27].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[27].sv_id.sat_id, 42,
                    "incorrect value for stec_residuals[27].sv_id.sat_id, expected 42, is {}",
                    msg.stec_residuals[27].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[28].residual, 15250,
                    "incorrect value for stec_residuals[28].residual, expected 15250, is {}",
                    msg.stec_residuals[28].residual
                );
                assert_eq!(
                    msg.stec_residuals[28].stddev, 110,
                    "incorrect value for stec_residuals[28].stddev, expected 110, is {}",
                    msg.stec_residuals[28].stddev
                );
                assert_eq!(msg.stec_residuals[28].sv_id.constellation, 115, "incorrect value for stec_residuals[28].sv_id.constellation, expected 115, is {}", msg.stec_residuals[28].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[28].sv_id.sat_id, 105,
                    "incorrect value for stec_residuals[28].sv_id.sat_id, expected 105, is {}",
                    msg.stec_residuals[28].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[29].residual, -18560,
                    "incorrect value for stec_residuals[29].residual, expected -18560, is {}",
                    msg.stec_residuals[29].residual
                );
                assert_eq!(
                    msg.stec_residuals[29].stddev, 185,
                    "incorrect value for stec_residuals[29].stddev, expected 185, is {}",
                    msg.stec_residuals[29].stddev
                );
                assert_eq!(msg.stec_residuals[29].sv_id.constellation, 109, "incorrect value for stec_residuals[29].sv_id.constellation, expected 109, is {}", msg.stec_residuals[29].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[29].sv_id.sat_id, 44,
                    "incorrect value for stec_residuals[29].sv_id.sat_id, expected 44, is {}",
                    msg.stec_residuals[29].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[30].residual, 23717,
                    "incorrect value for stec_residuals[30].residual, expected 23717, is {}",
                    msg.stec_residuals[30].residual
                );
                assert_eq!(
                    msg.stec_residuals[30].stddev, 79,
                    "incorrect value for stec_residuals[30].stddev, expected 79, is {}",
                    msg.stec_residuals[30].stddev
                );
                assert_eq!(msg.stec_residuals[30].sv_id.constellation, 31, "incorrect value for stec_residuals[30].sv_id.constellation, expected 31, is {}", msg.stec_residuals[30].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[30].sv_id.sat_id, 67,
                    "incorrect value for stec_residuals[30].sv_id.sat_id, expected 67, is {}",
                    msg.stec_residuals[30].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[31].residual, 1886,
                    "incorrect value for stec_residuals[31].residual, expected 1886, is {}",
                    msg.stec_residuals[31].residual
                );
                assert_eq!(
                    msg.stec_residuals[31].stddev, 162,
                    "incorrect value for stec_residuals[31].stddev, expected 162, is {}",
                    msg.stec_residuals[31].stddev
                );
                assert_eq!(msg.stec_residuals[31].sv_id.constellation, 180, "incorrect value for stec_residuals[31].sv_id.constellation, expected 180, is {}", msg.stec_residuals[31].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[31].sv_id.sat_id, 189,
                    "incorrect value for stec_residuals[31].sv_id.sat_id, expected 189, is {}",
                    msg.stec_residuals[31].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[32].residual, 12242,
                    "incorrect value for stec_residuals[32].residual, expected 12242, is {}",
                    msg.stec_residuals[32].residual
                );
                assert_eq!(
                    msg.stec_residuals[32].stddev, 7,
                    "incorrect value for stec_residuals[32].stddev, expected 7, is {}",
                    msg.stec_residuals[32].stddev
                );
                assert_eq!(msg.stec_residuals[32].sv_id.constellation, 156, "incorrect value for stec_residuals[32].sv_id.constellation, expected 156, is {}", msg.stec_residuals[32].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[32].sv_id.sat_id, 121,
                    "incorrect value for stec_residuals[32].sv_id.sat_id, expected 121, is {}",
                    msg.stec_residuals[32].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[33].residual, 10670,
                    "incorrect value for stec_residuals[33].residual, expected 10670, is {}",
                    msg.stec_residuals[33].residual
                );
                assert_eq!(
                    msg.stec_residuals[33].stddev, 241,
                    "incorrect value for stec_residuals[33].stddev, expected 241, is {}",
                    msg.stec_residuals[33].stddev
                );
                assert_eq!(msg.stec_residuals[33].sv_id.constellation, 205, "incorrect value for stec_residuals[33].sv_id.constellation, expected 205, is {}", msg.stec_residuals[33].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[33].sv_id.sat_id, 7,
                    "incorrect value for stec_residuals[33].sv_id.sat_id, expected 7, is {}",
                    msg.stec_residuals[33].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[34].residual, 25899,
                    "incorrect value for stec_residuals[34].residual, expected 25899, is {}",
                    msg.stec_residuals[34].residual
                );
                assert_eq!(
                    msg.stec_residuals[34].stddev, 186,
                    "incorrect value for stec_residuals[34].stddev, expected 186, is {}",
                    msg.stec_residuals[34].stddev
                );
                assert_eq!(msg.stec_residuals[34].sv_id.constellation, 210, "incorrect value for stec_residuals[34].sv_id.constellation, expected 210, is {}", msg.stec_residuals[34].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[34].sv_id.sat_id, 129,
                    "incorrect value for stec_residuals[34].sv_id.sat_id, expected 129, is {}",
                    msg.stec_residuals[34].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[35].residual, -2078,
                    "incorrect value for stec_residuals[35].residual, expected -2078, is {}",
                    msg.stec_residuals[35].residual
                );
                assert_eq!(
                    msg.stec_residuals[35].stddev, 187,
                    "incorrect value for stec_residuals[35].stddev, expected 187, is {}",
                    msg.stec_residuals[35].stddev
                );
                assert_eq!(msg.stec_residuals[35].sv_id.constellation, 195, "incorrect value for stec_residuals[35].sv_id.constellation, expected 195, is {}", msg.stec_residuals[35].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[35].sv_id.sat_id, 208,
                    "incorrect value for stec_residuals[35].sv_id.sat_id, expected 208, is {}",
                    msg.stec_residuals[35].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[36].residual, -16264,
                    "incorrect value for stec_residuals[36].residual, expected -16264, is {}",
                    msg.stec_residuals[36].residual
                );
                assert_eq!(
                    msg.stec_residuals[36].stddev, 102,
                    "incorrect value for stec_residuals[36].stddev, expected 102, is {}",
                    msg.stec_residuals[36].stddev
                );
                assert_eq!(msg.stec_residuals[36].sv_id.constellation, 160, "incorrect value for stec_residuals[36].sv_id.constellation, expected 160, is {}", msg.stec_residuals[36].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[36].sv_id.sat_id, 219,
                    "incorrect value for stec_residuals[36].sv_id.sat_id, expected 219, is {}",
                    msg.stec_residuals[36].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[37].residual, -21002,
                    "incorrect value for stec_residuals[37].residual, expected -21002, is {}",
                    msg.stec_residuals[37].residual
                );
                assert_eq!(
                    msg.stec_residuals[37].stddev, 94,
                    "incorrect value for stec_residuals[37].stddev, expected 94, is {}",
                    msg.stec_residuals[37].stddev
                );
                assert_eq!(msg.stec_residuals[37].sv_id.constellation, 42, "incorrect value for stec_residuals[37].sv_id.constellation, expected 42, is {}", msg.stec_residuals[37].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[37].sv_id.sat_id, 166,
                    "incorrect value for stec_residuals[37].sv_id.sat_id, expected 166, is {}",
                    msg.stec_residuals[37].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[38].residual, 7902,
                    "incorrect value for stec_residuals[38].residual, expected 7902, is {}",
                    msg.stec_residuals[38].residual
                );
                assert_eq!(
                    msg.stec_residuals[38].stddev, 35,
                    "incorrect value for stec_residuals[38].stddev, expected 35, is {}",
                    msg.stec_residuals[38].stddev
                );
                assert_eq!(msg.stec_residuals[38].sv_id.constellation, 156, "incorrect value for stec_residuals[38].sv_id.constellation, expected 156, is {}", msg.stec_residuals[38].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[38].sv_id.sat_id, 102,
                    "incorrect value for stec_residuals[38].sv_id.sat_id, expected 102, is {}",
                    msg.stec_residuals[38].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[39].residual, -30275,
                    "incorrect value for stec_residuals[39].residual, expected -30275, is {}",
                    msg.stec_residuals[39].residual
                );
                assert_eq!(
                    msg.stec_residuals[39].stddev, 204,
                    "incorrect value for stec_residuals[39].stddev, expected 204, is {}",
                    msg.stec_residuals[39].stddev
                );
                assert_eq!(msg.stec_residuals[39].sv_id.constellation, 64, "incorrect value for stec_residuals[39].sv_id.constellation, expected 64, is {}", msg.stec_residuals[39].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[39].sv_id.sat_id, 247,
                    "incorrect value for stec_residuals[39].sv_id.sat_id, expected 247, is {}",
                    msg.stec_residuals[39].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[40].residual, -8633,
                    "incorrect value for stec_residuals[40].residual, expected -8633, is {}",
                    msg.stec_residuals[40].residual
                );
                assert_eq!(
                    msg.stec_residuals[40].stddev, 222,
                    "incorrect value for stec_residuals[40].stddev, expected 222, is {}",
                    msg.stec_residuals[40].stddev
                );
                assert_eq!(msg.stec_residuals[40].sv_id.constellation, 32, "incorrect value for stec_residuals[40].sv_id.constellation, expected 32, is {}", msg.stec_residuals[40].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[40].sv_id.sat_id, 220,
                    "incorrect value for stec_residuals[40].sv_id.sat_id, expected 220, is {}",
                    msg.stec_residuals[40].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[41].residual, 6403,
                    "incorrect value for stec_residuals[41].residual, expected 6403, is {}",
                    msg.stec_residuals[41].residual
                );
                assert_eq!(
                    msg.stec_residuals[41].stddev, 45,
                    "incorrect value for stec_residuals[41].stddev, expected 45, is {}",
                    msg.stec_residuals[41].stddev
                );
                assert_eq!(msg.stec_residuals[41].sv_id.constellation, 246, "incorrect value for stec_residuals[41].sv_id.constellation, expected 246, is {}", msg.stec_residuals[41].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[41].sv_id.sat_id, 201,
                    "incorrect value for stec_residuals[41].sv_id.sat_id, expected 201, is {}",
                    msg.stec_residuals[41].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[42].residual, 22643,
                    "incorrect value for stec_residuals[42].residual, expected 22643, is {}",
                    msg.stec_residuals[42].residual
                );
                assert_eq!(
                    msg.stec_residuals[42].stddev, 218,
                    "incorrect value for stec_residuals[42].stddev, expected 218, is {}",
                    msg.stec_residuals[42].stddev
                );
                assert_eq!(msg.stec_residuals[42].sv_id.constellation, 239, "incorrect value for stec_residuals[42].sv_id.constellation, expected 239, is {}", msg.stec_residuals[42].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[42].sv_id.sat_id, 251,
                    "incorrect value for stec_residuals[42].sv_id.sat_id, expected 251, is {}",
                    msg.stec_residuals[42].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[43].residual, 16760,
                    "incorrect value for stec_residuals[43].residual, expected 16760, is {}",
                    msg.stec_residuals[43].residual
                );
                assert_eq!(
                    msg.stec_residuals[43].stddev, 175,
                    "incorrect value for stec_residuals[43].stddev, expected 175, is {}",
                    msg.stec_residuals[43].stddev
                );
                assert_eq!(msg.stec_residuals[43].sv_id.constellation, 209, "incorrect value for stec_residuals[43].sv_id.constellation, expected 209, is {}", msg.stec_residuals[43].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[43].sv_id.sat_id, 10,
                    "incorrect value for stec_residuals[43].sv_id.sat_id, expected 10, is {}",
                    msg.stec_residuals[43].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[44].residual, -20951,
                    "incorrect value for stec_residuals[44].residual, expected -20951, is {}",
                    msg.stec_residuals[44].residual
                );
                assert_eq!(
                    msg.stec_residuals[44].stddev, 137,
                    "incorrect value for stec_residuals[44].stddev, expected 137, is {}",
                    msg.stec_residuals[44].stddev
                );
                assert_eq!(msg.stec_residuals[44].sv_id.constellation, 194, "incorrect value for stec_residuals[44].sv_id.constellation, expected 194, is {}", msg.stec_residuals[44].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[44].sv_id.sat_id, 131,
                    "incorrect value for stec_residuals[44].sv_id.sat_id, expected 131, is {}",
                    msg.stec_residuals[44].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[45].residual, -740,
                    "incorrect value for stec_residuals[45].residual, expected -740, is {}",
                    msg.stec_residuals[45].residual
                );
                assert_eq!(
                    msg.stec_residuals[45].stddev, 42,
                    "incorrect value for stec_residuals[45].stddev, expected 42, is {}",
                    msg.stec_residuals[45].stddev
                );
                assert_eq!(msg.stec_residuals[45].sv_id.constellation, 68, "incorrect value for stec_residuals[45].sv_id.constellation, expected 68, is {}", msg.stec_residuals[45].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[45].sv_id.sat_id, 17,
                    "incorrect value for stec_residuals[45].sv_id.sat_id, expected 17, is {}",
                    msg.stec_residuals[45].sv_id.sat_id
                );
                assert_eq!(
                    msg.tropo_delay_correction.hydro, -3035,
                    "incorrect value for tropo_delay_correction.hydro, expected -3035, is {}",
                    msg.tropo_delay_correction.hydro
                );
                assert_eq!(
                    msg.tropo_delay_correction.stddev, 72,
                    "incorrect value for tropo_delay_correction.stddev, expected 72, is {}",
                    msg.tropo_delay_correction.stddev
                );
                assert_eq!(
                    msg.tropo_delay_correction.wet, 78,
                    "incorrect value for tropo_delay_correction.wet, expected 78, is {}",
                    msg.tropo_delay_correction.wet
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGriddedCorrection"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
