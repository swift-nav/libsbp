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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_gridded_correction_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 250, 5, 108, 106, 254, 164, 217, 44, 53, 98, 93, 63, 147, 104, 252, 133, 245, 28,
            95, 100, 147, 41, 33, 92, 87, 25, 142, 151, 74, 151, 95, 94, 7, 146, 237, 45, 167, 86,
            42, 116, 224, 169, 234, 220, 23, 176, 18, 13, 178, 79, 160, 160, 110, 15, 53, 206, 151,
            158, 22, 117, 184, 48, 170, 82, 40, 53, 122, 69, 180, 110, 38, 65, 104, 244, 19, 238,
            227, 88, 169, 164, 146, 63, 37, 183, 85, 71, 235, 168, 114, 211, 105, 221, 156, 60, 18,
            230, 2, 142, 172, 16, 39, 33, 126, 106, 99, 188, 234, 41, 162, 197, 138, 227, 80, 12,
            54, 67, 238, 5, 93, 1, 207, 129, 13, 46, 115, 49, 58, 185, 127, 156, 200, 96, 217, 202,
            15, 245, 55, 198, 81, 218, 132, 70, 73, 82, 147, 26, 255, 14, 134, 96, 138, 55, 214,
            83, 156, 170, 163, 79, 173, 228, 115, 51, 241, 107, 245, 112, 168, 210, 10, 5, 117, 1,
            57, 108, 248, 212, 145, 119, 226, 165, 5, 141, 202, 106, 0, 60, 36, 61, 243, 203, 216,
            215, 12, 137, 16, 28, 247, 115, 152, 181, 119, 208, 228, 203, 236, 34, 167, 196, 32,
            109, 1, 17, 101, 200, 25, 94, 125, 168, 137, 157, 4, 164, 29, 31, 48, 132, 72, 229,
            126, 186, 68, 76, 133, 21, 0, 180, 139, 164, 148, 119, 149, 214, 120, 177, 201, 80, 80,
            105, 10, 136, 118, 77, 46, 233, 233, 227, 11, 158, 103, 167, 216,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrGriddedCorrectionDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5fa,
                    "Incorrect message type, expected 0x5fa, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6a6c,
                    "incorrect sender id, expected 0x6a6c, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 245,
                    "incorrect value for header.iod_atmo, expected 245, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 37695,
                    "incorrect value for header.num_msgs, expected 37695, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 64616,
                    "incorrect value for header.seq_num, expected 64616, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.time.tow, 892131748,
                    "incorrect value for header.time.tow, expected 892131748, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 23906,
                    "incorrect value for header.time.wn, expected 23906, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.tropo_quality_indicator, 28,
                    "incorrect value for header.tropo_quality_indicator, expected 28, is {}",
                    msg.header.tropo_quality_indicator
                );
                assert_eq!(
                    msg.header.update_interval, 133,
                    "incorrect value for header.update_interval, expected 133, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.index, 25695,
                    "incorrect value for index, expected 25695, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.stec_residuals[0].residual, -26738,
                    "incorrect value for stec_residuals[0].residual, expected -26738, is {}",
                    msg.stec_residuals[0].residual
                );
                assert_eq!(
                    msg.stec_residuals[0].stddev, 74,
                    "incorrect value for stec_residuals[0].stddev, expected 74, is {}",
                    msg.stec_residuals[0].stddev
                );
                assert_eq!(
                    msg.stec_residuals[0].sv_id.constellation, 25,
                    "incorrect value for stec_residuals[0].sv_id.constellation, expected 25, is {}",
                    msg.stec_residuals[0].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[0].sv_id.sat_id, 87,
                    "incorrect value for stec_residuals[0].sv_id.sat_id, expected 87, is {}",
                    msg.stec_residuals[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[1].residual, 1886,
                    "incorrect value for stec_residuals[1].residual, expected 1886, is {}",
                    msg.stec_residuals[1].residual
                );
                assert_eq!(
                    msg.stec_residuals[1].stddev, 146,
                    "incorrect value for stec_residuals[1].stddev, expected 146, is {}",
                    msg.stec_residuals[1].stddev
                );
                assert_eq!(
                    msg.stec_residuals[1].sv_id.constellation, 95,
                    "incorrect value for stec_residuals[1].sv_id.constellation, expected 95, is {}",
                    msg.stec_residuals[1].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[1].sv_id.sat_id, 151,
                    "incorrect value for stec_residuals[1].sv_id.sat_id, expected 151, is {}",
                    msg.stec_residuals[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[2].residual, 22183,
                    "incorrect value for stec_residuals[2].residual, expected 22183, is {}",
                    msg.stec_residuals[2].residual
                );
                assert_eq!(
                    msg.stec_residuals[2].stddev, 42,
                    "incorrect value for stec_residuals[2].stddev, expected 42, is {}",
                    msg.stec_residuals[2].stddev
                );
                assert_eq!(
                    msg.stec_residuals[2].sv_id.constellation, 45,
                    "incorrect value for stec_residuals[2].sv_id.constellation, expected 45, is {}",
                    msg.stec_residuals[2].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[2].sv_id.sat_id, 237,
                    "incorrect value for stec_residuals[2].sv_id.sat_id, expected 237, is {}",
                    msg.stec_residuals[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[3].residual, -5463,
                    "incorrect value for stec_residuals[3].residual, expected -5463, is {}",
                    msg.stec_residuals[3].residual
                );
                assert_eq!(
                    msg.stec_residuals[3].stddev, 220,
                    "incorrect value for stec_residuals[3].stddev, expected 220, is {}",
                    msg.stec_residuals[3].stddev
                );
                assert_eq!(msg.stec_residuals[3].sv_id.constellation, 224, "incorrect value for stec_residuals[3].sv_id.constellation, expected 224, is {}", msg.stec_residuals[3].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[3].sv_id.sat_id, 116,
                    "incorrect value for stec_residuals[3].sv_id.sat_id, expected 116, is {}",
                    msg.stec_residuals[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[4].residual, 3346,
                    "incorrect value for stec_residuals[4].residual, expected 3346, is {}",
                    msg.stec_residuals[4].residual
                );
                assert_eq!(
                    msg.stec_residuals[4].stddev, 178,
                    "incorrect value for stec_residuals[4].stddev, expected 178, is {}",
                    msg.stec_residuals[4].stddev
                );
                assert_eq!(msg.stec_residuals[4].sv_id.constellation, 176, "incorrect value for stec_residuals[4].sv_id.constellation, expected 176, is {}", msg.stec_residuals[4].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[4].sv_id.sat_id, 23,
                    "incorrect value for stec_residuals[4].sv_id.sat_id, expected 23, is {}",
                    msg.stec_residuals[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[5].residual, 28320,
                    "incorrect value for stec_residuals[5].residual, expected 28320, is {}",
                    msg.stec_residuals[5].residual
                );
                assert_eq!(
                    msg.stec_residuals[5].stddev, 15,
                    "incorrect value for stec_residuals[5].stddev, expected 15, is {}",
                    msg.stec_residuals[5].stddev
                );
                assert_eq!(msg.stec_residuals[5].sv_id.constellation, 160, "incorrect value for stec_residuals[5].sv_id.constellation, expected 160, is {}", msg.stec_residuals[5].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[5].sv_id.sat_id, 79,
                    "incorrect value for stec_residuals[5].sv_id.sat_id, expected 79, is {}",
                    msg.stec_residuals[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[6].residual, -24937,
                    "incorrect value for stec_residuals[6].residual, expected -24937, is {}",
                    msg.stec_residuals[6].residual
                );
                assert_eq!(
                    msg.stec_residuals[6].stddev, 22,
                    "incorrect value for stec_residuals[6].stddev, expected 22, is {}",
                    msg.stec_residuals[6].stddev
                );
                assert_eq!(msg.stec_residuals[6].sv_id.constellation, 206, "incorrect value for stec_residuals[6].sv_id.constellation, expected 206, is {}", msg.stec_residuals[6].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[6].sv_id.sat_id, 53,
                    "incorrect value for stec_residuals[6].sv_id.sat_id, expected 53, is {}",
                    msg.stec_residuals[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[7].residual, -21968,
                    "incorrect value for stec_residuals[7].residual, expected -21968, is {}",
                    msg.stec_residuals[7].residual
                );
                assert_eq!(
                    msg.stec_residuals[7].stddev, 82,
                    "incorrect value for stec_residuals[7].stddev, expected 82, is {}",
                    msg.stec_residuals[7].stddev
                );
                assert_eq!(msg.stec_residuals[7].sv_id.constellation, 184, "incorrect value for stec_residuals[7].sv_id.constellation, expected 184, is {}", msg.stec_residuals[7].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[7].sv_id.sat_id, 117,
                    "incorrect value for stec_residuals[7].sv_id.sat_id, expected 117, is {}",
                    msg.stec_residuals[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[8].residual, 17786,
                    "incorrect value for stec_residuals[8].residual, expected 17786, is {}",
                    msg.stec_residuals[8].residual
                );
                assert_eq!(
                    msg.stec_residuals[8].stddev, 180,
                    "incorrect value for stec_residuals[8].stddev, expected 180, is {}",
                    msg.stec_residuals[8].stddev
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.constellation, 53,
                    "incorrect value for stec_residuals[8].sv_id.constellation, expected 53, is {}",
                    msg.stec_residuals[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.sat_id, 40,
                    "incorrect value for stec_residuals[8].sv_id.sat_id, expected 40, is {}",
                    msg.stec_residuals[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[9].residual, 26689,
                    "incorrect value for stec_residuals[9].residual, expected 26689, is {}",
                    msg.stec_residuals[9].residual
                );
                assert_eq!(
                    msg.stec_residuals[9].stddev, 244,
                    "incorrect value for stec_residuals[9].stddev, expected 244, is {}",
                    msg.stec_residuals[9].stddev
                );
                assert_eq!(
                    msg.stec_residuals[9].sv_id.constellation, 38,
                    "incorrect value for stec_residuals[9].sv_id.constellation, expected 38, is {}",
                    msg.stec_residuals[9].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[9].sv_id.sat_id, 110,
                    "incorrect value for stec_residuals[9].sv_id.sat_id, expected 110, is {}",
                    msg.stec_residuals[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[10].residual, 22755,
                    "incorrect value for stec_residuals[10].residual, expected 22755, is {}",
                    msg.stec_residuals[10].residual
                );
                assert_eq!(
                    msg.stec_residuals[10].stddev, 169,
                    "incorrect value for stec_residuals[10].stddev, expected 169, is {}",
                    msg.stec_residuals[10].stddev
                );
                assert_eq!(msg.stec_residuals[10].sv_id.constellation, 238, "incorrect value for stec_residuals[10].sv_id.constellation, expected 238, is {}", msg.stec_residuals[10].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[10].sv_id.sat_id, 19,
                    "incorrect value for stec_residuals[10].sv_id.sat_id, expected 19, is {}",
                    msg.stec_residuals[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[11].residual, 9535,
                    "incorrect value for stec_residuals[11].residual, expected 9535, is {}",
                    msg.stec_residuals[11].residual
                );
                assert_eq!(
                    msg.stec_residuals[11].stddev, 183,
                    "incorrect value for stec_residuals[11].stddev, expected 183, is {}",
                    msg.stec_residuals[11].stddev
                );
                assert_eq!(msg.stec_residuals[11].sv_id.constellation, 146, "incorrect value for stec_residuals[11].sv_id.constellation, expected 146, is {}", msg.stec_residuals[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[11].sv_id.sat_id, 164,
                    "incorrect value for stec_residuals[11].sv_id.sat_id, expected 164, is {}",
                    msg.stec_residuals[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[12].residual, -22293,
                    "incorrect value for stec_residuals[12].residual, expected -22293, is {}",
                    msg.stec_residuals[12].residual
                );
                assert_eq!(
                    msg.stec_residuals[12].stddev, 114,
                    "incorrect value for stec_residuals[12].stddev, expected 114, is {}",
                    msg.stec_residuals[12].stddev
                );
                assert_eq!(msg.stec_residuals[12].sv_id.constellation, 71, "incorrect value for stec_residuals[12].sv_id.constellation, expected 71, is {}", msg.stec_residuals[12].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[12].sv_id.sat_id, 85,
                    "incorrect value for stec_residuals[12].sv_id.sat_id, expected 85, is {}",
                    msg.stec_residuals[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[13].residual, -25379,
                    "incorrect value for stec_residuals[13].residual, expected -25379, is {}",
                    msg.stec_residuals[13].residual
                );
                assert_eq!(
                    msg.stec_residuals[13].stddev, 60,
                    "incorrect value for stec_residuals[13].stddev, expected 60, is {}",
                    msg.stec_residuals[13].stddev
                );
                assert_eq!(msg.stec_residuals[13].sv_id.constellation, 105, "incorrect value for stec_residuals[13].sv_id.constellation, expected 105, is {}", msg.stec_residuals[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[13].sv_id.sat_id, 211,
                    "incorrect value for stec_residuals[13].sv_id.sat_id, expected 211, is {}",
                    msg.stec_residuals[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[14].residual, -29182,
                    "incorrect value for stec_residuals[14].residual, expected -29182, is {}",
                    msg.stec_residuals[14].residual
                );
                assert_eq!(
                    msg.stec_residuals[14].stddev, 172,
                    "incorrect value for stec_residuals[14].stddev, expected 172, is {}",
                    msg.stec_residuals[14].stddev
                );
                assert_eq!(msg.stec_residuals[14].sv_id.constellation, 230, "incorrect value for stec_residuals[14].sv_id.constellation, expected 230, is {}", msg.stec_residuals[14].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[14].sv_id.sat_id, 18,
                    "incorrect value for stec_residuals[14].sv_id.sat_id, expected 18, is {}",
                    msg.stec_residuals[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[15].residual, 32289,
                    "incorrect value for stec_residuals[15].residual, expected 32289, is {}",
                    msg.stec_residuals[15].residual
                );
                assert_eq!(
                    msg.stec_residuals[15].stddev, 106,
                    "incorrect value for stec_residuals[15].stddev, expected 106, is {}",
                    msg.stec_residuals[15].stddev
                );
                assert_eq!(msg.stec_residuals[15].sv_id.constellation, 39, "incorrect value for stec_residuals[15].sv_id.constellation, expected 39, is {}", msg.stec_residuals[15].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[15].sv_id.sat_id, 16,
                    "incorrect value for stec_residuals[15].sv_id.sat_id, expected 16, is {}",
                    msg.stec_residuals[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[16].residual, 10730,
                    "incorrect value for stec_residuals[16].residual, expected 10730, is {}",
                    msg.stec_residuals[16].residual
                );
                assert_eq!(
                    msg.stec_residuals[16].stddev, 162,
                    "incorrect value for stec_residuals[16].stddev, expected 162, is {}",
                    msg.stec_residuals[16].stddev
                );
                assert_eq!(msg.stec_residuals[16].sv_id.constellation, 188, "incorrect value for stec_residuals[16].sv_id.constellation, expected 188, is {}", msg.stec_residuals[16].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[16].sv_id.sat_id, 99,
                    "incorrect value for stec_residuals[16].sv_id.sat_id, expected 99, is {}",
                    msg.stec_residuals[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[17].residual, 20707,
                    "incorrect value for stec_residuals[17].residual, expected 20707, is {}",
                    msg.stec_residuals[17].residual
                );
                assert_eq!(
                    msg.stec_residuals[17].stddev, 12,
                    "incorrect value for stec_residuals[17].stddev, expected 12, is {}",
                    msg.stec_residuals[17].stddev
                );
                assert_eq!(msg.stec_residuals[17].sv_id.constellation, 138, "incorrect value for stec_residuals[17].sv_id.constellation, expected 138, is {}", msg.stec_residuals[17].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[17].sv_id.sat_id, 197,
                    "incorrect value for stec_residuals[17].sv_id.sat_id, expected 197, is {}",
                    msg.stec_residuals[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[18].residual, 1518,
                    "incorrect value for stec_residuals[18].residual, expected 1518, is {}",
                    msg.stec_residuals[18].residual
                );
                assert_eq!(
                    msg.stec_residuals[18].stddev, 93,
                    "incorrect value for stec_residuals[18].stddev, expected 93, is {}",
                    msg.stec_residuals[18].stddev
                );
                assert_eq!(msg.stec_residuals[18].sv_id.constellation, 67, "incorrect value for stec_residuals[18].sv_id.constellation, expected 67, is {}", msg.stec_residuals[18].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[18].sv_id.sat_id, 54,
                    "incorrect value for stec_residuals[18].sv_id.sat_id, expected 54, is {}",
                    msg.stec_residuals[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[19].residual, 3457,
                    "incorrect value for stec_residuals[19].residual, expected 3457, is {}",
                    msg.stec_residuals[19].residual
                );
                assert_eq!(
                    msg.stec_residuals[19].stddev, 46,
                    "incorrect value for stec_residuals[19].stddev, expected 46, is {}",
                    msg.stec_residuals[19].stddev
                );
                assert_eq!(msg.stec_residuals[19].sv_id.constellation, 207, "incorrect value for stec_residuals[19].sv_id.constellation, expected 207, is {}", msg.stec_residuals[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[19].sv_id.sat_id, 1,
                    "incorrect value for stec_residuals[19].sv_id.sat_id, expected 1, is {}",
                    msg.stec_residuals[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[20].residual, -18118,
                    "incorrect value for stec_residuals[20].residual, expected -18118, is {}",
                    msg.stec_residuals[20].residual
                );
                assert_eq!(
                    msg.stec_residuals[20].stddev, 127,
                    "incorrect value for stec_residuals[20].stddev, expected 127, is {}",
                    msg.stec_residuals[20].stddev
                );
                assert_eq!(msg.stec_residuals[20].sv_id.constellation, 49, "incorrect value for stec_residuals[20].sv_id.constellation, expected 49, is {}", msg.stec_residuals[20].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[20].sv_id.sat_id, 115,
                    "incorrect value for stec_residuals[20].sv_id.sat_id, expected 115, is {}",
                    msg.stec_residuals[20].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[21].residual, -9888,
                    "incorrect value for stec_residuals[21].residual, expected -9888, is {}",
                    msg.stec_residuals[21].residual
                );
                assert_eq!(
                    msg.stec_residuals[21].stddev, 202,
                    "incorrect value for stec_residuals[21].stddev, expected 202, is {}",
                    msg.stec_residuals[21].stddev
                );
                assert_eq!(msg.stec_residuals[21].sv_id.constellation, 200, "incorrect value for stec_residuals[21].sv_id.constellation, expected 200, is {}", msg.stec_residuals[21].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[21].sv_id.sat_id, 156,
                    "incorrect value for stec_residuals[21].sv_id.sat_id, expected 156, is {}",
                    msg.stec_residuals[21].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[22].residual, -14793,
                    "incorrect value for stec_residuals[22].residual, expected -14793, is {}",
                    msg.stec_residuals[22].residual
                );
                assert_eq!(
                    msg.stec_residuals[22].stddev, 81,
                    "incorrect value for stec_residuals[22].stddev, expected 81, is {}",
                    msg.stec_residuals[22].stddev
                );
                assert_eq!(msg.stec_residuals[22].sv_id.constellation, 245, "incorrect value for stec_residuals[22].sv_id.constellation, expected 245, is {}", msg.stec_residuals[22].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[22].sv_id.sat_id, 15,
                    "incorrect value for stec_residuals[22].sv_id.sat_id, expected 15, is {}",
                    msg.stec_residuals[22].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[23].residual, 18758,
                    "incorrect value for stec_residuals[23].residual, expected 18758, is {}",
                    msg.stec_residuals[23].residual
                );
                assert_eq!(
                    msg.stec_residuals[23].stddev, 82,
                    "incorrect value for stec_residuals[23].stddev, expected 82, is {}",
                    msg.stec_residuals[23].stddev
                );
                assert_eq!(msg.stec_residuals[23].sv_id.constellation, 132, "incorrect value for stec_residuals[23].sv_id.constellation, expected 132, is {}", msg.stec_residuals[23].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[23].sv_id.sat_id, 218,
                    "incorrect value for stec_residuals[23].sv_id.sat_id, expected 218, is {}",
                    msg.stec_residuals[23].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[24].residual, 3839,
                    "incorrect value for stec_residuals[24].residual, expected 3839, is {}",
                    msg.stec_residuals[24].residual
                );
                assert_eq!(
                    msg.stec_residuals[24].stddev, 134,
                    "incorrect value for stec_residuals[24].stddev, expected 134, is {}",
                    msg.stec_residuals[24].stddev
                );
                assert_eq!(msg.stec_residuals[24].sv_id.constellation, 26, "incorrect value for stec_residuals[24].sv_id.constellation, expected 26, is {}", msg.stec_residuals[24].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[24].sv_id.sat_id, 147,
                    "incorrect value for stec_residuals[24].sv_id.sat_id, expected 147, is {}",
                    msg.stec_residuals[24].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[25].residual, -10697,
                    "incorrect value for stec_residuals[25].residual, expected -10697, is {}",
                    msg.stec_residuals[25].residual
                );
                assert_eq!(
                    msg.stec_residuals[25].stddev, 83,
                    "incorrect value for stec_residuals[25].stddev, expected 83, is {}",
                    msg.stec_residuals[25].stddev
                );
                assert_eq!(msg.stec_residuals[25].sv_id.constellation, 138, "incorrect value for stec_residuals[25].sv_id.constellation, expected 138, is {}", msg.stec_residuals[25].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[25].sv_id.sat_id, 96,
                    "incorrect value for stec_residuals[25].sv_id.sat_id, expected 96, is {}",
                    msg.stec_residuals[25].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[26].residual, 20387,
                    "incorrect value for stec_residuals[26].residual, expected 20387, is {}",
                    msg.stec_residuals[26].residual
                );
                assert_eq!(
                    msg.stec_residuals[26].stddev, 173,
                    "incorrect value for stec_residuals[26].stddev, expected 173, is {}",
                    msg.stec_residuals[26].stddev
                );
                assert_eq!(msg.stec_residuals[26].sv_id.constellation, 170, "incorrect value for stec_residuals[26].sv_id.constellation, expected 170, is {}", msg.stec_residuals[26].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[26].sv_id.sat_id, 156,
                    "incorrect value for stec_residuals[26].sv_id.sat_id, expected 156, is {}",
                    msg.stec_residuals[26].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[27].residual, -3789,
                    "incorrect value for stec_residuals[27].residual, expected -3789, is {}",
                    msg.stec_residuals[27].residual
                );
                assert_eq!(
                    msg.stec_residuals[27].stddev, 107,
                    "incorrect value for stec_residuals[27].stddev, expected 107, is {}",
                    msg.stec_residuals[27].stddev
                );
                assert_eq!(msg.stec_residuals[27].sv_id.constellation, 115, "incorrect value for stec_residuals[27].sv_id.constellation, expected 115, is {}", msg.stec_residuals[27].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[27].sv_id.sat_id, 228,
                    "incorrect value for stec_residuals[27].sv_id.sat_id, expected 228, is {}",
                    msg.stec_residuals[27].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[28].residual, -11608,
                    "incorrect value for stec_residuals[28].residual, expected -11608, is {}",
                    msg.stec_residuals[28].residual
                );
                assert_eq!(
                    msg.stec_residuals[28].stddev, 10,
                    "incorrect value for stec_residuals[28].stddev, expected 10, is {}",
                    msg.stec_residuals[28].stddev
                );
                assert_eq!(msg.stec_residuals[28].sv_id.constellation, 112, "incorrect value for stec_residuals[28].sv_id.constellation, expected 112, is {}", msg.stec_residuals[28].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[28].sv_id.sat_id, 245,
                    "incorrect value for stec_residuals[28].sv_id.sat_id, expected 245, is {}",
                    msg.stec_residuals[28].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[29].residual, 14593,
                    "incorrect value for stec_residuals[29].residual, expected 14593, is {}",
                    msg.stec_residuals[29].residual
                );
                assert_eq!(
                    msg.stec_residuals[29].stddev, 108,
                    "incorrect value for stec_residuals[29].stddev, expected 108, is {}",
                    msg.stec_residuals[29].stddev
                );
                assert_eq!(msg.stec_residuals[29].sv_id.constellation, 117, "incorrect value for stec_residuals[29].sv_id.constellation, expected 117, is {}", msg.stec_residuals[29].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[29].sv_id.sat_id, 5,
                    "incorrect value for stec_residuals[29].sv_id.sat_id, expected 5, is {}",
                    msg.stec_residuals[29].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[30].residual, 30609,
                    "incorrect value for stec_residuals[30].residual, expected 30609, is {}",
                    msg.stec_residuals[30].residual
                );
                assert_eq!(
                    msg.stec_residuals[30].stddev, 226,
                    "incorrect value for stec_residuals[30].stddev, expected 226, is {}",
                    msg.stec_residuals[30].stddev
                );
                assert_eq!(msg.stec_residuals[30].sv_id.constellation, 212, "incorrect value for stec_residuals[30].sv_id.constellation, expected 212, is {}", msg.stec_residuals[30].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[30].sv_id.sat_id, 248,
                    "incorrect value for stec_residuals[30].sv_id.sat_id, expected 248, is {}",
                    msg.stec_residuals[30].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[31].residual, -13683,
                    "incorrect value for stec_residuals[31].residual, expected -13683, is {}",
                    msg.stec_residuals[31].residual
                );
                assert_eq!(
                    msg.stec_residuals[31].stddev, 106,
                    "incorrect value for stec_residuals[31].stddev, expected 106, is {}",
                    msg.stec_residuals[31].stddev
                );
                assert_eq!(
                    msg.stec_residuals[31].sv_id.constellation, 5,
                    "incorrect value for stec_residuals[31].sv_id.constellation, expected 5, is {}",
                    msg.stec_residuals[31].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[31].sv_id.sat_id, 165,
                    "incorrect value for stec_residuals[31].sv_id.sat_id, expected 165, is {}",
                    msg.stec_residuals[31].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[32].residual, 15652,
                    "incorrect value for stec_residuals[32].residual, expected 15652, is {}",
                    msg.stec_residuals[32].residual
                );
                assert_eq!(
                    msg.stec_residuals[32].stddev, 243,
                    "incorrect value for stec_residuals[32].stddev, expected 243, is {}",
                    msg.stec_residuals[32].stddev
                );
                assert_eq!(msg.stec_residuals[32].sv_id.constellation, 60, "incorrect value for stec_residuals[32].sv_id.constellation, expected 60, is {}", msg.stec_residuals[32].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[32].sv_id.sat_id, 0,
                    "incorrect value for stec_residuals[32].sv_id.sat_id, expected 0, is {}",
                    msg.stec_residuals[32].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[33].residual, 3287,
                    "incorrect value for stec_residuals[33].residual, expected 3287, is {}",
                    msg.stec_residuals[33].residual
                );
                assert_eq!(
                    msg.stec_residuals[33].stddev, 137,
                    "incorrect value for stec_residuals[33].stddev, expected 137, is {}",
                    msg.stec_residuals[33].stddev
                );
                assert_eq!(msg.stec_residuals[33].sv_id.constellation, 216, "incorrect value for stec_residuals[33].sv_id.constellation, expected 216, is {}", msg.stec_residuals[33].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[33].sv_id.sat_id, 203,
                    "incorrect value for stec_residuals[33].sv_id.sat_id, expected 203, is {}",
                    msg.stec_residuals[33].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[34].residual, 29687,
                    "incorrect value for stec_residuals[34].residual, expected 29687, is {}",
                    msg.stec_residuals[34].residual
                );
                assert_eq!(
                    msg.stec_residuals[34].stddev, 152,
                    "incorrect value for stec_residuals[34].stddev, expected 152, is {}",
                    msg.stec_residuals[34].stddev
                );
                assert_eq!(msg.stec_residuals[34].sv_id.constellation, 28, "incorrect value for stec_residuals[34].sv_id.constellation, expected 28, is {}", msg.stec_residuals[34].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[34].sv_id.sat_id, 16,
                    "incorrect value for stec_residuals[34].sv_id.sat_id, expected 16, is {}",
                    msg.stec_residuals[34].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[35].residual, -6960,
                    "incorrect value for stec_residuals[35].residual, expected -6960, is {}",
                    msg.stec_residuals[35].residual
                );
                assert_eq!(
                    msg.stec_residuals[35].stddev, 203,
                    "incorrect value for stec_residuals[35].stddev, expected 203, is {}",
                    msg.stec_residuals[35].stddev
                );
                assert_eq!(msg.stec_residuals[35].sv_id.constellation, 119, "incorrect value for stec_residuals[35].sv_id.constellation, expected 119, is {}", msg.stec_residuals[35].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[35].sv_id.sat_id, 181,
                    "incorrect value for stec_residuals[35].sv_id.sat_id, expected 181, is {}",
                    msg.stec_residuals[35].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[36].residual, -15193,
                    "incorrect value for stec_residuals[36].residual, expected -15193, is {}",
                    msg.stec_residuals[36].residual
                );
                assert_eq!(
                    msg.stec_residuals[36].stddev, 32,
                    "incorrect value for stec_residuals[36].stddev, expected 32, is {}",
                    msg.stec_residuals[36].stddev
                );
                assert_eq!(msg.stec_residuals[36].sv_id.constellation, 34, "incorrect value for stec_residuals[36].sv_id.constellation, expected 34, is {}", msg.stec_residuals[36].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[36].sv_id.sat_id, 236,
                    "incorrect value for stec_residuals[36].sv_id.sat_id, expected 236, is {}",
                    msg.stec_residuals[36].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[37].residual, 25873,
                    "incorrect value for stec_residuals[37].residual, expected 25873, is {}",
                    msg.stec_residuals[37].residual
                );
                assert_eq!(
                    msg.stec_residuals[37].stddev, 200,
                    "incorrect value for stec_residuals[37].stddev, expected 200, is {}",
                    msg.stec_residuals[37].stddev
                );
                assert_eq!(
                    msg.stec_residuals[37].sv_id.constellation, 1,
                    "incorrect value for stec_residuals[37].sv_id.constellation, expected 1, is {}",
                    msg.stec_residuals[37].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[37].sv_id.sat_id, 109,
                    "incorrect value for stec_residuals[37].sv_id.sat_id, expected 109, is {}",
                    msg.stec_residuals[37].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[38].residual, -22403,
                    "incorrect value for stec_residuals[38].residual, expected -22403, is {}",
                    msg.stec_residuals[38].residual
                );
                assert_eq!(
                    msg.stec_residuals[38].stddev, 137,
                    "incorrect value for stec_residuals[38].stddev, expected 137, is {}",
                    msg.stec_residuals[38].stddev
                );
                assert_eq!(msg.stec_residuals[38].sv_id.constellation, 94, "incorrect value for stec_residuals[38].sv_id.constellation, expected 94, is {}", msg.stec_residuals[38].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[38].sv_id.sat_id, 25,
                    "incorrect value for stec_residuals[38].sv_id.sat_id, expected 25, is {}",
                    msg.stec_residuals[38].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[39].residual, 7588,
                    "incorrect value for stec_residuals[39].residual, expected 7588, is {}",
                    msg.stec_residuals[39].residual
                );
                assert_eq!(
                    msg.stec_residuals[39].stddev, 31,
                    "incorrect value for stec_residuals[39].stddev, expected 31, is {}",
                    msg.stec_residuals[39].stddev
                );
                assert_eq!(
                    msg.stec_residuals[39].sv_id.constellation, 4,
                    "incorrect value for stec_residuals[39].sv_id.constellation, expected 4, is {}",
                    msg.stec_residuals[39].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[39].sv_id.sat_id, 157,
                    "incorrect value for stec_residuals[39].sv_id.sat_id, expected 157, is {}",
                    msg.stec_residuals[39].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[40].residual, -6840,
                    "incorrect value for stec_residuals[40].residual, expected -6840, is {}",
                    msg.stec_residuals[40].residual
                );
                assert_eq!(
                    msg.stec_residuals[40].stddev, 126,
                    "incorrect value for stec_residuals[40].stddev, expected 126, is {}",
                    msg.stec_residuals[40].stddev
                );
                assert_eq!(msg.stec_residuals[40].sv_id.constellation, 132, "incorrect value for stec_residuals[40].sv_id.constellation, expected 132, is {}", msg.stec_residuals[40].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[40].sv_id.sat_id, 48,
                    "incorrect value for stec_residuals[40].sv_id.sat_id, expected 48, is {}",
                    msg.stec_residuals[40].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[41].residual, -31412,
                    "incorrect value for stec_residuals[41].residual, expected -31412, is {}",
                    msg.stec_residuals[41].residual
                );
                assert_eq!(
                    msg.stec_residuals[41].stddev, 21,
                    "incorrect value for stec_residuals[41].stddev, expected 21, is {}",
                    msg.stec_residuals[41].stddev
                );
                assert_eq!(msg.stec_residuals[41].sv_id.constellation, 68, "incorrect value for stec_residuals[41].sv_id.constellation, expected 68, is {}", msg.stec_residuals[41].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[41].sv_id.sat_id, 186,
                    "incorrect value for stec_residuals[41].sv_id.sat_id, expected 186, is {}",
                    msg.stec_residuals[41].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[42].residual, -23413,
                    "incorrect value for stec_residuals[42].residual, expected -23413, is {}",
                    msg.stec_residuals[42].residual
                );
                assert_eq!(
                    msg.stec_residuals[42].stddev, 148,
                    "incorrect value for stec_residuals[42].stddev, expected 148, is {}",
                    msg.stec_residuals[42].stddev
                );
                assert_eq!(msg.stec_residuals[42].sv_id.constellation, 180, "incorrect value for stec_residuals[42].sv_id.constellation, expected 180, is {}", msg.stec_residuals[42].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[42].sv_id.sat_id, 0,
                    "incorrect value for stec_residuals[42].sv_id.sat_id, expected 0, is {}",
                    msg.stec_residuals[42].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[43].residual, 30934,
                    "incorrect value for stec_residuals[43].residual, expected 30934, is {}",
                    msg.stec_residuals[43].residual
                );
                assert_eq!(
                    msg.stec_residuals[43].stddev, 177,
                    "incorrect value for stec_residuals[43].stddev, expected 177, is {}",
                    msg.stec_residuals[43].stddev
                );
                assert_eq!(msg.stec_residuals[43].sv_id.constellation, 149, "incorrect value for stec_residuals[43].sv_id.constellation, expected 149, is {}", msg.stec_residuals[43].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[43].sv_id.sat_id, 119,
                    "incorrect value for stec_residuals[43].sv_id.sat_id, expected 119, is {}",
                    msg.stec_residuals[43].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[44].residual, 26960,
                    "incorrect value for stec_residuals[44].residual, expected 26960, is {}",
                    msg.stec_residuals[44].residual
                );
                assert_eq!(
                    msg.stec_residuals[44].stddev, 10,
                    "incorrect value for stec_residuals[44].stddev, expected 10, is {}",
                    msg.stec_residuals[44].stddev
                );
                assert_eq!(msg.stec_residuals[44].sv_id.constellation, 80, "incorrect value for stec_residuals[44].sv_id.constellation, expected 80, is {}", msg.stec_residuals[44].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[44].sv_id.sat_id, 201,
                    "incorrect value for stec_residuals[44].sv_id.sat_id, expected 201, is {}",
                    msg.stec_residuals[44].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[45].residual, 11853,
                    "incorrect value for stec_residuals[45].residual, expected 11853, is {}",
                    msg.stec_residuals[45].residual
                );
                assert_eq!(
                    msg.stec_residuals[45].stddev, 233,
                    "incorrect value for stec_residuals[45].stddev, expected 233, is {}",
                    msg.stec_residuals[45].stddev
                );
                assert_eq!(msg.stec_residuals[45].sv_id.constellation, 118, "incorrect value for stec_residuals[45].sv_id.constellation, expected 118, is {}", msg.stec_residuals[45].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[45].sv_id.sat_id, 136,
                    "incorrect value for stec_residuals[45].sv_id.sat_id, expected 136, is {}",
                    msg.stec_residuals[45].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[46].residual, -25077,
                    "incorrect value for stec_residuals[46].residual, expected -25077, is {}",
                    msg.stec_residuals[46].residual
                );
                assert_eq!(
                    msg.stec_residuals[46].stddev, 103,
                    "incorrect value for stec_residuals[46].stddev, expected 103, is {}",
                    msg.stec_residuals[46].stddev
                );
                assert_eq!(msg.stec_residuals[46].sv_id.constellation, 227, "incorrect value for stec_residuals[46].sv_id.constellation, expected 227, is {}", msg.stec_residuals[46].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[46].sv_id.sat_id, 233,
                    "incorrect value for stec_residuals[46].sv_id.sat_id, expected 233, is {}",
                    msg.stec_residuals[46].sv_id.sat_id
                );
                assert_eq!(
                    msg.tropo_delay_correction.hydro, 10643,
                    "incorrect value for tropo_delay_correction.hydro, expected 10643, is {}",
                    msg.tropo_delay_correction.hydro
                );
                assert_eq!(
                    msg.tropo_delay_correction.stddev, 92,
                    "incorrect value for tropo_delay_correction.stddev, expected 92, is {}",
                    msg.tropo_delay_correction.stddev
                );
                assert_eq!(
                    msg.tropo_delay_correction.wet, 33,
                    "incorrect value for tropo_delay_correction.wet, expected 33, is {}",
                    msg.tropo_delay_correction.wet
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGriddedCorrectionDepA"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_gridded_correction_dep_a() {
    {
        let json_input = r#"{"crc":55463,"length":254,"msg_type":1530,"payload":"pNksNWJdP5No/IX1HF9kkykhXFcZjpdKl19eB5LtLadWKnTgqercF7ASDbJPoKBuDzXOl54WdbgwqlIoNXpFtG4mQWj0E+7jWKmkkj8lt1VH66hy02ndnDwS5gKOrBAnIX5qY7zqKaLFiuNQDDZD7gVdAc+BDS5zMTq5f5zIYNnKD/U3xlHahEZJUpMa/w6GYIo31lOcqqNPreRzM/Fr9XCo0goFdQE5bPjUkXfipQWNymoAPCQ988vY1wyJEBz3c5i1d9Dky+wip8QgbQERZcgZXn2oiZ0EpB0fMIRI5X66REyFFQC0i6SUd5XWeLHJUFBpCoh2TS7p6eMLnmc=","preamble":85,"sender":27244,"header":{"time":{"tow":892131748,"wn":23906},"num_msgs":37695,"seq_num":64616,"update_interval":133,"iod_atmo":245,"tropo_quality_indicator":28},"index":25695,"tropo_delay_correction":{"hydro":10643,"wet":33,"stddev":92},"stec_residuals":[{"sv_id":{"satId":87,"constellation":25},"residual":-26738,"stddev":74},{"sv_id":{"satId":151,"constellation":95},"residual":1886,"stddev":146},{"sv_id":{"satId":237,"constellation":45},"residual":22183,"stddev":42},{"sv_id":{"satId":116,"constellation":224},"residual":-5463,"stddev":220},{"sv_id":{"satId":23,"constellation":176},"residual":3346,"stddev":178},{"sv_id":{"satId":79,"constellation":160},"residual":28320,"stddev":15},{"sv_id":{"satId":53,"constellation":206},"residual":-24937,"stddev":22},{"sv_id":{"satId":117,"constellation":184},"residual":-21968,"stddev":82},{"sv_id":{"satId":40,"constellation":53},"residual":17786,"stddev":180},{"sv_id":{"satId":110,"constellation":38},"residual":26689,"stddev":244},{"sv_id":{"satId":19,"constellation":238},"residual":22755,"stddev":169},{"sv_id":{"satId":164,"constellation":146},"residual":9535,"stddev":183},{"sv_id":{"satId":85,"constellation":71},"residual":-22293,"stddev":114},{"sv_id":{"satId":211,"constellation":105},"residual":-25379,"stddev":60},{"sv_id":{"satId":18,"constellation":230},"residual":-29182,"stddev":172},{"sv_id":{"satId":16,"constellation":39},"residual":32289,"stddev":106},{"sv_id":{"satId":99,"constellation":188},"residual":10730,"stddev":162},{"sv_id":{"satId":197,"constellation":138},"residual":20707,"stddev":12},{"sv_id":{"satId":54,"constellation":67},"residual":1518,"stddev":93},{"sv_id":{"satId":1,"constellation":207},"residual":3457,"stddev":46},{"sv_id":{"satId":115,"constellation":49},"residual":-18118,"stddev":127},{"sv_id":{"satId":156,"constellation":200},"residual":-9888,"stddev":202},{"sv_id":{"satId":15,"constellation":245},"residual":-14793,"stddev":81},{"sv_id":{"satId":218,"constellation":132},"residual":18758,"stddev":82},{"sv_id":{"satId":147,"constellation":26},"residual":3839,"stddev":134},{"sv_id":{"satId":96,"constellation":138},"residual":-10697,"stddev":83},{"sv_id":{"satId":156,"constellation":170},"residual":20387,"stddev":173},{"sv_id":{"satId":228,"constellation":115},"residual":-3789,"stddev":107},{"sv_id":{"satId":245,"constellation":112},"residual":-11608,"stddev":10},{"sv_id":{"satId":5,"constellation":117},"residual":14593,"stddev":108},{"sv_id":{"satId":248,"constellation":212},"residual":30609,"stddev":226},{"sv_id":{"satId":165,"constellation":5},"residual":-13683,"stddev":106},{"sv_id":{"satId":0,"constellation":60},"residual":15652,"stddev":243},{"sv_id":{"satId":203,"constellation":216},"residual":3287,"stddev":137},{"sv_id":{"satId":16,"constellation":28},"residual":29687,"stddev":152},{"sv_id":{"satId":181,"constellation":119},"residual":-6960,"stddev":203},{"sv_id":{"satId":236,"constellation":34},"residual":-15193,"stddev":32},{"sv_id":{"satId":109,"constellation":1},"residual":25873,"stddev":200},{"sv_id":{"satId":25,"constellation":94},"residual":-22403,"stddev":137},{"sv_id":{"satId":157,"constellation":4},"residual":7588,"stddev":31},{"sv_id":{"satId":48,"constellation":132},"residual":-6840,"stddev":126},{"sv_id":{"satId":186,"constellation":68},"residual":-31412,"stddev":21},{"sv_id":{"satId":0,"constellation":180},"residual":-23413,"stddev":148},{"sv_id":{"satId":119,"constellation":149},"residual":30934,"stddev":177},{"sv_id":{"satId":201,"constellation":80},"residual":26960,"stddev":10},{"sv_id":{"satId":136,"constellation":118},"residual":11853,"stddev":233},{"sv_id":{"satId":233,"constellation":227},"residual":-25077,"stddev":103}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrGriddedCorrectionDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5fa,
                    "Incorrect message type, expected 0x5fa, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6a6c,
                    "incorrect sender id, expected 0x6a6c, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 245,
                    "incorrect value for header.iod_atmo, expected 245, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 37695,
                    "incorrect value for header.num_msgs, expected 37695, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 64616,
                    "incorrect value for header.seq_num, expected 64616, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.time.tow, 892131748,
                    "incorrect value for header.time.tow, expected 892131748, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 23906,
                    "incorrect value for header.time.wn, expected 23906, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.tropo_quality_indicator, 28,
                    "incorrect value for header.tropo_quality_indicator, expected 28, is {}",
                    msg.header.tropo_quality_indicator
                );
                assert_eq!(
                    msg.header.update_interval, 133,
                    "incorrect value for header.update_interval, expected 133, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.index, 25695,
                    "incorrect value for index, expected 25695, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.stec_residuals[0].residual, -26738,
                    "incorrect value for stec_residuals[0].residual, expected -26738, is {}",
                    msg.stec_residuals[0].residual
                );
                assert_eq!(
                    msg.stec_residuals[0].stddev, 74,
                    "incorrect value for stec_residuals[0].stddev, expected 74, is {}",
                    msg.stec_residuals[0].stddev
                );
                assert_eq!(
                    msg.stec_residuals[0].sv_id.constellation, 25,
                    "incorrect value for stec_residuals[0].sv_id.constellation, expected 25, is {}",
                    msg.stec_residuals[0].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[0].sv_id.sat_id, 87,
                    "incorrect value for stec_residuals[0].sv_id.sat_id, expected 87, is {}",
                    msg.stec_residuals[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[1].residual, 1886,
                    "incorrect value for stec_residuals[1].residual, expected 1886, is {}",
                    msg.stec_residuals[1].residual
                );
                assert_eq!(
                    msg.stec_residuals[1].stddev, 146,
                    "incorrect value for stec_residuals[1].stddev, expected 146, is {}",
                    msg.stec_residuals[1].stddev
                );
                assert_eq!(
                    msg.stec_residuals[1].sv_id.constellation, 95,
                    "incorrect value for stec_residuals[1].sv_id.constellation, expected 95, is {}",
                    msg.stec_residuals[1].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[1].sv_id.sat_id, 151,
                    "incorrect value for stec_residuals[1].sv_id.sat_id, expected 151, is {}",
                    msg.stec_residuals[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[2].residual, 22183,
                    "incorrect value for stec_residuals[2].residual, expected 22183, is {}",
                    msg.stec_residuals[2].residual
                );
                assert_eq!(
                    msg.stec_residuals[2].stddev, 42,
                    "incorrect value for stec_residuals[2].stddev, expected 42, is {}",
                    msg.stec_residuals[2].stddev
                );
                assert_eq!(
                    msg.stec_residuals[2].sv_id.constellation, 45,
                    "incorrect value for stec_residuals[2].sv_id.constellation, expected 45, is {}",
                    msg.stec_residuals[2].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[2].sv_id.sat_id, 237,
                    "incorrect value for stec_residuals[2].sv_id.sat_id, expected 237, is {}",
                    msg.stec_residuals[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[3].residual, -5463,
                    "incorrect value for stec_residuals[3].residual, expected -5463, is {}",
                    msg.stec_residuals[3].residual
                );
                assert_eq!(
                    msg.stec_residuals[3].stddev, 220,
                    "incorrect value for stec_residuals[3].stddev, expected 220, is {}",
                    msg.stec_residuals[3].stddev
                );
                assert_eq!(msg.stec_residuals[3].sv_id.constellation, 224, "incorrect value for stec_residuals[3].sv_id.constellation, expected 224, is {}", msg.stec_residuals[3].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[3].sv_id.sat_id, 116,
                    "incorrect value for stec_residuals[3].sv_id.sat_id, expected 116, is {}",
                    msg.stec_residuals[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[4].residual, 3346,
                    "incorrect value for stec_residuals[4].residual, expected 3346, is {}",
                    msg.stec_residuals[4].residual
                );
                assert_eq!(
                    msg.stec_residuals[4].stddev, 178,
                    "incorrect value for stec_residuals[4].stddev, expected 178, is {}",
                    msg.stec_residuals[4].stddev
                );
                assert_eq!(msg.stec_residuals[4].sv_id.constellation, 176, "incorrect value for stec_residuals[4].sv_id.constellation, expected 176, is {}", msg.stec_residuals[4].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[4].sv_id.sat_id, 23,
                    "incorrect value for stec_residuals[4].sv_id.sat_id, expected 23, is {}",
                    msg.stec_residuals[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[5].residual, 28320,
                    "incorrect value for stec_residuals[5].residual, expected 28320, is {}",
                    msg.stec_residuals[5].residual
                );
                assert_eq!(
                    msg.stec_residuals[5].stddev, 15,
                    "incorrect value for stec_residuals[5].stddev, expected 15, is {}",
                    msg.stec_residuals[5].stddev
                );
                assert_eq!(msg.stec_residuals[5].sv_id.constellation, 160, "incorrect value for stec_residuals[5].sv_id.constellation, expected 160, is {}", msg.stec_residuals[5].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[5].sv_id.sat_id, 79,
                    "incorrect value for stec_residuals[5].sv_id.sat_id, expected 79, is {}",
                    msg.stec_residuals[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[6].residual, -24937,
                    "incorrect value for stec_residuals[6].residual, expected -24937, is {}",
                    msg.stec_residuals[6].residual
                );
                assert_eq!(
                    msg.stec_residuals[6].stddev, 22,
                    "incorrect value for stec_residuals[6].stddev, expected 22, is {}",
                    msg.stec_residuals[6].stddev
                );
                assert_eq!(msg.stec_residuals[6].sv_id.constellation, 206, "incorrect value for stec_residuals[6].sv_id.constellation, expected 206, is {}", msg.stec_residuals[6].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[6].sv_id.sat_id, 53,
                    "incorrect value for stec_residuals[6].sv_id.sat_id, expected 53, is {}",
                    msg.stec_residuals[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[7].residual, -21968,
                    "incorrect value for stec_residuals[7].residual, expected -21968, is {}",
                    msg.stec_residuals[7].residual
                );
                assert_eq!(
                    msg.stec_residuals[7].stddev, 82,
                    "incorrect value for stec_residuals[7].stddev, expected 82, is {}",
                    msg.stec_residuals[7].stddev
                );
                assert_eq!(msg.stec_residuals[7].sv_id.constellation, 184, "incorrect value for stec_residuals[7].sv_id.constellation, expected 184, is {}", msg.stec_residuals[7].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[7].sv_id.sat_id, 117,
                    "incorrect value for stec_residuals[7].sv_id.sat_id, expected 117, is {}",
                    msg.stec_residuals[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[8].residual, 17786,
                    "incorrect value for stec_residuals[8].residual, expected 17786, is {}",
                    msg.stec_residuals[8].residual
                );
                assert_eq!(
                    msg.stec_residuals[8].stddev, 180,
                    "incorrect value for stec_residuals[8].stddev, expected 180, is {}",
                    msg.stec_residuals[8].stddev
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.constellation, 53,
                    "incorrect value for stec_residuals[8].sv_id.constellation, expected 53, is {}",
                    msg.stec_residuals[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.sat_id, 40,
                    "incorrect value for stec_residuals[8].sv_id.sat_id, expected 40, is {}",
                    msg.stec_residuals[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[9].residual, 26689,
                    "incorrect value for stec_residuals[9].residual, expected 26689, is {}",
                    msg.stec_residuals[9].residual
                );
                assert_eq!(
                    msg.stec_residuals[9].stddev, 244,
                    "incorrect value for stec_residuals[9].stddev, expected 244, is {}",
                    msg.stec_residuals[9].stddev
                );
                assert_eq!(
                    msg.stec_residuals[9].sv_id.constellation, 38,
                    "incorrect value for stec_residuals[9].sv_id.constellation, expected 38, is {}",
                    msg.stec_residuals[9].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[9].sv_id.sat_id, 110,
                    "incorrect value for stec_residuals[9].sv_id.sat_id, expected 110, is {}",
                    msg.stec_residuals[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[10].residual, 22755,
                    "incorrect value for stec_residuals[10].residual, expected 22755, is {}",
                    msg.stec_residuals[10].residual
                );
                assert_eq!(
                    msg.stec_residuals[10].stddev, 169,
                    "incorrect value for stec_residuals[10].stddev, expected 169, is {}",
                    msg.stec_residuals[10].stddev
                );
                assert_eq!(msg.stec_residuals[10].sv_id.constellation, 238, "incorrect value for stec_residuals[10].sv_id.constellation, expected 238, is {}", msg.stec_residuals[10].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[10].sv_id.sat_id, 19,
                    "incorrect value for stec_residuals[10].sv_id.sat_id, expected 19, is {}",
                    msg.stec_residuals[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[11].residual, 9535,
                    "incorrect value for stec_residuals[11].residual, expected 9535, is {}",
                    msg.stec_residuals[11].residual
                );
                assert_eq!(
                    msg.stec_residuals[11].stddev, 183,
                    "incorrect value for stec_residuals[11].stddev, expected 183, is {}",
                    msg.stec_residuals[11].stddev
                );
                assert_eq!(msg.stec_residuals[11].sv_id.constellation, 146, "incorrect value for stec_residuals[11].sv_id.constellation, expected 146, is {}", msg.stec_residuals[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[11].sv_id.sat_id, 164,
                    "incorrect value for stec_residuals[11].sv_id.sat_id, expected 164, is {}",
                    msg.stec_residuals[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[12].residual, -22293,
                    "incorrect value for stec_residuals[12].residual, expected -22293, is {}",
                    msg.stec_residuals[12].residual
                );
                assert_eq!(
                    msg.stec_residuals[12].stddev, 114,
                    "incorrect value for stec_residuals[12].stddev, expected 114, is {}",
                    msg.stec_residuals[12].stddev
                );
                assert_eq!(msg.stec_residuals[12].sv_id.constellation, 71, "incorrect value for stec_residuals[12].sv_id.constellation, expected 71, is {}", msg.stec_residuals[12].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[12].sv_id.sat_id, 85,
                    "incorrect value for stec_residuals[12].sv_id.sat_id, expected 85, is {}",
                    msg.stec_residuals[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[13].residual, -25379,
                    "incorrect value for stec_residuals[13].residual, expected -25379, is {}",
                    msg.stec_residuals[13].residual
                );
                assert_eq!(
                    msg.stec_residuals[13].stddev, 60,
                    "incorrect value for stec_residuals[13].stddev, expected 60, is {}",
                    msg.stec_residuals[13].stddev
                );
                assert_eq!(msg.stec_residuals[13].sv_id.constellation, 105, "incorrect value for stec_residuals[13].sv_id.constellation, expected 105, is {}", msg.stec_residuals[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[13].sv_id.sat_id, 211,
                    "incorrect value for stec_residuals[13].sv_id.sat_id, expected 211, is {}",
                    msg.stec_residuals[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[14].residual, -29182,
                    "incorrect value for stec_residuals[14].residual, expected -29182, is {}",
                    msg.stec_residuals[14].residual
                );
                assert_eq!(
                    msg.stec_residuals[14].stddev, 172,
                    "incorrect value for stec_residuals[14].stddev, expected 172, is {}",
                    msg.stec_residuals[14].stddev
                );
                assert_eq!(msg.stec_residuals[14].sv_id.constellation, 230, "incorrect value for stec_residuals[14].sv_id.constellation, expected 230, is {}", msg.stec_residuals[14].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[14].sv_id.sat_id, 18,
                    "incorrect value for stec_residuals[14].sv_id.sat_id, expected 18, is {}",
                    msg.stec_residuals[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[15].residual, 32289,
                    "incorrect value for stec_residuals[15].residual, expected 32289, is {}",
                    msg.stec_residuals[15].residual
                );
                assert_eq!(
                    msg.stec_residuals[15].stddev, 106,
                    "incorrect value for stec_residuals[15].stddev, expected 106, is {}",
                    msg.stec_residuals[15].stddev
                );
                assert_eq!(msg.stec_residuals[15].sv_id.constellation, 39, "incorrect value for stec_residuals[15].sv_id.constellation, expected 39, is {}", msg.stec_residuals[15].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[15].sv_id.sat_id, 16,
                    "incorrect value for stec_residuals[15].sv_id.sat_id, expected 16, is {}",
                    msg.stec_residuals[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[16].residual, 10730,
                    "incorrect value for stec_residuals[16].residual, expected 10730, is {}",
                    msg.stec_residuals[16].residual
                );
                assert_eq!(
                    msg.stec_residuals[16].stddev, 162,
                    "incorrect value for stec_residuals[16].stddev, expected 162, is {}",
                    msg.stec_residuals[16].stddev
                );
                assert_eq!(msg.stec_residuals[16].sv_id.constellation, 188, "incorrect value for stec_residuals[16].sv_id.constellation, expected 188, is {}", msg.stec_residuals[16].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[16].sv_id.sat_id, 99,
                    "incorrect value for stec_residuals[16].sv_id.sat_id, expected 99, is {}",
                    msg.stec_residuals[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[17].residual, 20707,
                    "incorrect value for stec_residuals[17].residual, expected 20707, is {}",
                    msg.stec_residuals[17].residual
                );
                assert_eq!(
                    msg.stec_residuals[17].stddev, 12,
                    "incorrect value for stec_residuals[17].stddev, expected 12, is {}",
                    msg.stec_residuals[17].stddev
                );
                assert_eq!(msg.stec_residuals[17].sv_id.constellation, 138, "incorrect value for stec_residuals[17].sv_id.constellation, expected 138, is {}", msg.stec_residuals[17].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[17].sv_id.sat_id, 197,
                    "incorrect value for stec_residuals[17].sv_id.sat_id, expected 197, is {}",
                    msg.stec_residuals[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[18].residual, 1518,
                    "incorrect value for stec_residuals[18].residual, expected 1518, is {}",
                    msg.stec_residuals[18].residual
                );
                assert_eq!(
                    msg.stec_residuals[18].stddev, 93,
                    "incorrect value for stec_residuals[18].stddev, expected 93, is {}",
                    msg.stec_residuals[18].stddev
                );
                assert_eq!(msg.stec_residuals[18].sv_id.constellation, 67, "incorrect value for stec_residuals[18].sv_id.constellation, expected 67, is {}", msg.stec_residuals[18].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[18].sv_id.sat_id, 54,
                    "incorrect value for stec_residuals[18].sv_id.sat_id, expected 54, is {}",
                    msg.stec_residuals[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[19].residual, 3457,
                    "incorrect value for stec_residuals[19].residual, expected 3457, is {}",
                    msg.stec_residuals[19].residual
                );
                assert_eq!(
                    msg.stec_residuals[19].stddev, 46,
                    "incorrect value for stec_residuals[19].stddev, expected 46, is {}",
                    msg.stec_residuals[19].stddev
                );
                assert_eq!(msg.stec_residuals[19].sv_id.constellation, 207, "incorrect value for stec_residuals[19].sv_id.constellation, expected 207, is {}", msg.stec_residuals[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[19].sv_id.sat_id, 1,
                    "incorrect value for stec_residuals[19].sv_id.sat_id, expected 1, is {}",
                    msg.stec_residuals[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[20].residual, -18118,
                    "incorrect value for stec_residuals[20].residual, expected -18118, is {}",
                    msg.stec_residuals[20].residual
                );
                assert_eq!(
                    msg.stec_residuals[20].stddev, 127,
                    "incorrect value for stec_residuals[20].stddev, expected 127, is {}",
                    msg.stec_residuals[20].stddev
                );
                assert_eq!(msg.stec_residuals[20].sv_id.constellation, 49, "incorrect value for stec_residuals[20].sv_id.constellation, expected 49, is {}", msg.stec_residuals[20].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[20].sv_id.sat_id, 115,
                    "incorrect value for stec_residuals[20].sv_id.sat_id, expected 115, is {}",
                    msg.stec_residuals[20].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[21].residual, -9888,
                    "incorrect value for stec_residuals[21].residual, expected -9888, is {}",
                    msg.stec_residuals[21].residual
                );
                assert_eq!(
                    msg.stec_residuals[21].stddev, 202,
                    "incorrect value for stec_residuals[21].stddev, expected 202, is {}",
                    msg.stec_residuals[21].stddev
                );
                assert_eq!(msg.stec_residuals[21].sv_id.constellation, 200, "incorrect value for stec_residuals[21].sv_id.constellation, expected 200, is {}", msg.stec_residuals[21].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[21].sv_id.sat_id, 156,
                    "incorrect value for stec_residuals[21].sv_id.sat_id, expected 156, is {}",
                    msg.stec_residuals[21].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[22].residual, -14793,
                    "incorrect value for stec_residuals[22].residual, expected -14793, is {}",
                    msg.stec_residuals[22].residual
                );
                assert_eq!(
                    msg.stec_residuals[22].stddev, 81,
                    "incorrect value for stec_residuals[22].stddev, expected 81, is {}",
                    msg.stec_residuals[22].stddev
                );
                assert_eq!(msg.stec_residuals[22].sv_id.constellation, 245, "incorrect value for stec_residuals[22].sv_id.constellation, expected 245, is {}", msg.stec_residuals[22].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[22].sv_id.sat_id, 15,
                    "incorrect value for stec_residuals[22].sv_id.sat_id, expected 15, is {}",
                    msg.stec_residuals[22].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[23].residual, 18758,
                    "incorrect value for stec_residuals[23].residual, expected 18758, is {}",
                    msg.stec_residuals[23].residual
                );
                assert_eq!(
                    msg.stec_residuals[23].stddev, 82,
                    "incorrect value for stec_residuals[23].stddev, expected 82, is {}",
                    msg.stec_residuals[23].stddev
                );
                assert_eq!(msg.stec_residuals[23].sv_id.constellation, 132, "incorrect value for stec_residuals[23].sv_id.constellation, expected 132, is {}", msg.stec_residuals[23].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[23].sv_id.sat_id, 218,
                    "incorrect value for stec_residuals[23].sv_id.sat_id, expected 218, is {}",
                    msg.stec_residuals[23].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[24].residual, 3839,
                    "incorrect value for stec_residuals[24].residual, expected 3839, is {}",
                    msg.stec_residuals[24].residual
                );
                assert_eq!(
                    msg.stec_residuals[24].stddev, 134,
                    "incorrect value for stec_residuals[24].stddev, expected 134, is {}",
                    msg.stec_residuals[24].stddev
                );
                assert_eq!(msg.stec_residuals[24].sv_id.constellation, 26, "incorrect value for stec_residuals[24].sv_id.constellation, expected 26, is {}", msg.stec_residuals[24].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[24].sv_id.sat_id, 147,
                    "incorrect value for stec_residuals[24].sv_id.sat_id, expected 147, is {}",
                    msg.stec_residuals[24].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[25].residual, -10697,
                    "incorrect value for stec_residuals[25].residual, expected -10697, is {}",
                    msg.stec_residuals[25].residual
                );
                assert_eq!(
                    msg.stec_residuals[25].stddev, 83,
                    "incorrect value for stec_residuals[25].stddev, expected 83, is {}",
                    msg.stec_residuals[25].stddev
                );
                assert_eq!(msg.stec_residuals[25].sv_id.constellation, 138, "incorrect value for stec_residuals[25].sv_id.constellation, expected 138, is {}", msg.stec_residuals[25].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[25].sv_id.sat_id, 96,
                    "incorrect value for stec_residuals[25].sv_id.sat_id, expected 96, is {}",
                    msg.stec_residuals[25].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[26].residual, 20387,
                    "incorrect value for stec_residuals[26].residual, expected 20387, is {}",
                    msg.stec_residuals[26].residual
                );
                assert_eq!(
                    msg.stec_residuals[26].stddev, 173,
                    "incorrect value for stec_residuals[26].stddev, expected 173, is {}",
                    msg.stec_residuals[26].stddev
                );
                assert_eq!(msg.stec_residuals[26].sv_id.constellation, 170, "incorrect value for stec_residuals[26].sv_id.constellation, expected 170, is {}", msg.stec_residuals[26].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[26].sv_id.sat_id, 156,
                    "incorrect value for stec_residuals[26].sv_id.sat_id, expected 156, is {}",
                    msg.stec_residuals[26].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[27].residual, -3789,
                    "incorrect value for stec_residuals[27].residual, expected -3789, is {}",
                    msg.stec_residuals[27].residual
                );
                assert_eq!(
                    msg.stec_residuals[27].stddev, 107,
                    "incorrect value for stec_residuals[27].stddev, expected 107, is {}",
                    msg.stec_residuals[27].stddev
                );
                assert_eq!(msg.stec_residuals[27].sv_id.constellation, 115, "incorrect value for stec_residuals[27].sv_id.constellation, expected 115, is {}", msg.stec_residuals[27].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[27].sv_id.sat_id, 228,
                    "incorrect value for stec_residuals[27].sv_id.sat_id, expected 228, is {}",
                    msg.stec_residuals[27].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[28].residual, -11608,
                    "incorrect value for stec_residuals[28].residual, expected -11608, is {}",
                    msg.stec_residuals[28].residual
                );
                assert_eq!(
                    msg.stec_residuals[28].stddev, 10,
                    "incorrect value for stec_residuals[28].stddev, expected 10, is {}",
                    msg.stec_residuals[28].stddev
                );
                assert_eq!(msg.stec_residuals[28].sv_id.constellation, 112, "incorrect value for stec_residuals[28].sv_id.constellation, expected 112, is {}", msg.stec_residuals[28].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[28].sv_id.sat_id, 245,
                    "incorrect value for stec_residuals[28].sv_id.sat_id, expected 245, is {}",
                    msg.stec_residuals[28].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[29].residual, 14593,
                    "incorrect value for stec_residuals[29].residual, expected 14593, is {}",
                    msg.stec_residuals[29].residual
                );
                assert_eq!(
                    msg.stec_residuals[29].stddev, 108,
                    "incorrect value for stec_residuals[29].stddev, expected 108, is {}",
                    msg.stec_residuals[29].stddev
                );
                assert_eq!(msg.stec_residuals[29].sv_id.constellation, 117, "incorrect value for stec_residuals[29].sv_id.constellation, expected 117, is {}", msg.stec_residuals[29].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[29].sv_id.sat_id, 5,
                    "incorrect value for stec_residuals[29].sv_id.sat_id, expected 5, is {}",
                    msg.stec_residuals[29].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[30].residual, 30609,
                    "incorrect value for stec_residuals[30].residual, expected 30609, is {}",
                    msg.stec_residuals[30].residual
                );
                assert_eq!(
                    msg.stec_residuals[30].stddev, 226,
                    "incorrect value for stec_residuals[30].stddev, expected 226, is {}",
                    msg.stec_residuals[30].stddev
                );
                assert_eq!(msg.stec_residuals[30].sv_id.constellation, 212, "incorrect value for stec_residuals[30].sv_id.constellation, expected 212, is {}", msg.stec_residuals[30].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[30].sv_id.sat_id, 248,
                    "incorrect value for stec_residuals[30].sv_id.sat_id, expected 248, is {}",
                    msg.stec_residuals[30].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[31].residual, -13683,
                    "incorrect value for stec_residuals[31].residual, expected -13683, is {}",
                    msg.stec_residuals[31].residual
                );
                assert_eq!(
                    msg.stec_residuals[31].stddev, 106,
                    "incorrect value for stec_residuals[31].stddev, expected 106, is {}",
                    msg.stec_residuals[31].stddev
                );
                assert_eq!(
                    msg.stec_residuals[31].sv_id.constellation, 5,
                    "incorrect value for stec_residuals[31].sv_id.constellation, expected 5, is {}",
                    msg.stec_residuals[31].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[31].sv_id.sat_id, 165,
                    "incorrect value for stec_residuals[31].sv_id.sat_id, expected 165, is {}",
                    msg.stec_residuals[31].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[32].residual, 15652,
                    "incorrect value for stec_residuals[32].residual, expected 15652, is {}",
                    msg.stec_residuals[32].residual
                );
                assert_eq!(
                    msg.stec_residuals[32].stddev, 243,
                    "incorrect value for stec_residuals[32].stddev, expected 243, is {}",
                    msg.stec_residuals[32].stddev
                );
                assert_eq!(msg.stec_residuals[32].sv_id.constellation, 60, "incorrect value for stec_residuals[32].sv_id.constellation, expected 60, is {}", msg.stec_residuals[32].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[32].sv_id.sat_id, 0,
                    "incorrect value for stec_residuals[32].sv_id.sat_id, expected 0, is {}",
                    msg.stec_residuals[32].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[33].residual, 3287,
                    "incorrect value for stec_residuals[33].residual, expected 3287, is {}",
                    msg.stec_residuals[33].residual
                );
                assert_eq!(
                    msg.stec_residuals[33].stddev, 137,
                    "incorrect value for stec_residuals[33].stddev, expected 137, is {}",
                    msg.stec_residuals[33].stddev
                );
                assert_eq!(msg.stec_residuals[33].sv_id.constellation, 216, "incorrect value for stec_residuals[33].sv_id.constellation, expected 216, is {}", msg.stec_residuals[33].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[33].sv_id.sat_id, 203,
                    "incorrect value for stec_residuals[33].sv_id.sat_id, expected 203, is {}",
                    msg.stec_residuals[33].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[34].residual, 29687,
                    "incorrect value for stec_residuals[34].residual, expected 29687, is {}",
                    msg.stec_residuals[34].residual
                );
                assert_eq!(
                    msg.stec_residuals[34].stddev, 152,
                    "incorrect value for stec_residuals[34].stddev, expected 152, is {}",
                    msg.stec_residuals[34].stddev
                );
                assert_eq!(msg.stec_residuals[34].sv_id.constellation, 28, "incorrect value for stec_residuals[34].sv_id.constellation, expected 28, is {}", msg.stec_residuals[34].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[34].sv_id.sat_id, 16,
                    "incorrect value for stec_residuals[34].sv_id.sat_id, expected 16, is {}",
                    msg.stec_residuals[34].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[35].residual, -6960,
                    "incorrect value for stec_residuals[35].residual, expected -6960, is {}",
                    msg.stec_residuals[35].residual
                );
                assert_eq!(
                    msg.stec_residuals[35].stddev, 203,
                    "incorrect value for stec_residuals[35].stddev, expected 203, is {}",
                    msg.stec_residuals[35].stddev
                );
                assert_eq!(msg.stec_residuals[35].sv_id.constellation, 119, "incorrect value for stec_residuals[35].sv_id.constellation, expected 119, is {}", msg.stec_residuals[35].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[35].sv_id.sat_id, 181,
                    "incorrect value for stec_residuals[35].sv_id.sat_id, expected 181, is {}",
                    msg.stec_residuals[35].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[36].residual, -15193,
                    "incorrect value for stec_residuals[36].residual, expected -15193, is {}",
                    msg.stec_residuals[36].residual
                );
                assert_eq!(
                    msg.stec_residuals[36].stddev, 32,
                    "incorrect value for stec_residuals[36].stddev, expected 32, is {}",
                    msg.stec_residuals[36].stddev
                );
                assert_eq!(msg.stec_residuals[36].sv_id.constellation, 34, "incorrect value for stec_residuals[36].sv_id.constellation, expected 34, is {}", msg.stec_residuals[36].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[36].sv_id.sat_id, 236,
                    "incorrect value for stec_residuals[36].sv_id.sat_id, expected 236, is {}",
                    msg.stec_residuals[36].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[37].residual, 25873,
                    "incorrect value for stec_residuals[37].residual, expected 25873, is {}",
                    msg.stec_residuals[37].residual
                );
                assert_eq!(
                    msg.stec_residuals[37].stddev, 200,
                    "incorrect value for stec_residuals[37].stddev, expected 200, is {}",
                    msg.stec_residuals[37].stddev
                );
                assert_eq!(
                    msg.stec_residuals[37].sv_id.constellation, 1,
                    "incorrect value for stec_residuals[37].sv_id.constellation, expected 1, is {}",
                    msg.stec_residuals[37].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[37].sv_id.sat_id, 109,
                    "incorrect value for stec_residuals[37].sv_id.sat_id, expected 109, is {}",
                    msg.stec_residuals[37].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[38].residual, -22403,
                    "incorrect value for stec_residuals[38].residual, expected -22403, is {}",
                    msg.stec_residuals[38].residual
                );
                assert_eq!(
                    msg.stec_residuals[38].stddev, 137,
                    "incorrect value for stec_residuals[38].stddev, expected 137, is {}",
                    msg.stec_residuals[38].stddev
                );
                assert_eq!(msg.stec_residuals[38].sv_id.constellation, 94, "incorrect value for stec_residuals[38].sv_id.constellation, expected 94, is {}", msg.stec_residuals[38].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[38].sv_id.sat_id, 25,
                    "incorrect value for stec_residuals[38].sv_id.sat_id, expected 25, is {}",
                    msg.stec_residuals[38].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[39].residual, 7588,
                    "incorrect value for stec_residuals[39].residual, expected 7588, is {}",
                    msg.stec_residuals[39].residual
                );
                assert_eq!(
                    msg.stec_residuals[39].stddev, 31,
                    "incorrect value for stec_residuals[39].stddev, expected 31, is {}",
                    msg.stec_residuals[39].stddev
                );
                assert_eq!(
                    msg.stec_residuals[39].sv_id.constellation, 4,
                    "incorrect value for stec_residuals[39].sv_id.constellation, expected 4, is {}",
                    msg.stec_residuals[39].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[39].sv_id.sat_id, 157,
                    "incorrect value for stec_residuals[39].sv_id.sat_id, expected 157, is {}",
                    msg.stec_residuals[39].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[40].residual, -6840,
                    "incorrect value for stec_residuals[40].residual, expected -6840, is {}",
                    msg.stec_residuals[40].residual
                );
                assert_eq!(
                    msg.stec_residuals[40].stddev, 126,
                    "incorrect value for stec_residuals[40].stddev, expected 126, is {}",
                    msg.stec_residuals[40].stddev
                );
                assert_eq!(msg.stec_residuals[40].sv_id.constellation, 132, "incorrect value for stec_residuals[40].sv_id.constellation, expected 132, is {}", msg.stec_residuals[40].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[40].sv_id.sat_id, 48,
                    "incorrect value for stec_residuals[40].sv_id.sat_id, expected 48, is {}",
                    msg.stec_residuals[40].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[41].residual, -31412,
                    "incorrect value for stec_residuals[41].residual, expected -31412, is {}",
                    msg.stec_residuals[41].residual
                );
                assert_eq!(
                    msg.stec_residuals[41].stddev, 21,
                    "incorrect value for stec_residuals[41].stddev, expected 21, is {}",
                    msg.stec_residuals[41].stddev
                );
                assert_eq!(msg.stec_residuals[41].sv_id.constellation, 68, "incorrect value for stec_residuals[41].sv_id.constellation, expected 68, is {}", msg.stec_residuals[41].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[41].sv_id.sat_id, 186,
                    "incorrect value for stec_residuals[41].sv_id.sat_id, expected 186, is {}",
                    msg.stec_residuals[41].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[42].residual, -23413,
                    "incorrect value for stec_residuals[42].residual, expected -23413, is {}",
                    msg.stec_residuals[42].residual
                );
                assert_eq!(
                    msg.stec_residuals[42].stddev, 148,
                    "incorrect value for stec_residuals[42].stddev, expected 148, is {}",
                    msg.stec_residuals[42].stddev
                );
                assert_eq!(msg.stec_residuals[42].sv_id.constellation, 180, "incorrect value for stec_residuals[42].sv_id.constellation, expected 180, is {}", msg.stec_residuals[42].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[42].sv_id.sat_id, 0,
                    "incorrect value for stec_residuals[42].sv_id.sat_id, expected 0, is {}",
                    msg.stec_residuals[42].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[43].residual, 30934,
                    "incorrect value for stec_residuals[43].residual, expected 30934, is {}",
                    msg.stec_residuals[43].residual
                );
                assert_eq!(
                    msg.stec_residuals[43].stddev, 177,
                    "incorrect value for stec_residuals[43].stddev, expected 177, is {}",
                    msg.stec_residuals[43].stddev
                );
                assert_eq!(msg.stec_residuals[43].sv_id.constellation, 149, "incorrect value for stec_residuals[43].sv_id.constellation, expected 149, is {}", msg.stec_residuals[43].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[43].sv_id.sat_id, 119,
                    "incorrect value for stec_residuals[43].sv_id.sat_id, expected 119, is {}",
                    msg.stec_residuals[43].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[44].residual, 26960,
                    "incorrect value for stec_residuals[44].residual, expected 26960, is {}",
                    msg.stec_residuals[44].residual
                );
                assert_eq!(
                    msg.stec_residuals[44].stddev, 10,
                    "incorrect value for stec_residuals[44].stddev, expected 10, is {}",
                    msg.stec_residuals[44].stddev
                );
                assert_eq!(msg.stec_residuals[44].sv_id.constellation, 80, "incorrect value for stec_residuals[44].sv_id.constellation, expected 80, is {}", msg.stec_residuals[44].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[44].sv_id.sat_id, 201,
                    "incorrect value for stec_residuals[44].sv_id.sat_id, expected 201, is {}",
                    msg.stec_residuals[44].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[45].residual, 11853,
                    "incorrect value for stec_residuals[45].residual, expected 11853, is {}",
                    msg.stec_residuals[45].residual
                );
                assert_eq!(
                    msg.stec_residuals[45].stddev, 233,
                    "incorrect value for stec_residuals[45].stddev, expected 233, is {}",
                    msg.stec_residuals[45].stddev
                );
                assert_eq!(msg.stec_residuals[45].sv_id.constellation, 118, "incorrect value for stec_residuals[45].sv_id.constellation, expected 118, is {}", msg.stec_residuals[45].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[45].sv_id.sat_id, 136,
                    "incorrect value for stec_residuals[45].sv_id.sat_id, expected 136, is {}",
                    msg.stec_residuals[45].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[46].residual, -25077,
                    "incorrect value for stec_residuals[46].residual, expected -25077, is {}",
                    msg.stec_residuals[46].residual
                );
                assert_eq!(
                    msg.stec_residuals[46].stddev, 103,
                    "incorrect value for stec_residuals[46].stddev, expected 103, is {}",
                    msg.stec_residuals[46].stddev
                );
                assert_eq!(msg.stec_residuals[46].sv_id.constellation, 227, "incorrect value for stec_residuals[46].sv_id.constellation, expected 227, is {}", msg.stec_residuals[46].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[46].sv_id.sat_id, 233,
                    "incorrect value for stec_residuals[46].sv_id.sat_id, expected 233, is {}",
                    msg.stec_residuals[46].sv_id.sat_id
                );
                assert_eq!(
                    msg.tropo_delay_correction.hydro, 10643,
                    "incorrect value for tropo_delay_correction.hydro, expected 10643, is {}",
                    msg.tropo_delay_correction.hydro
                );
                assert_eq!(
                    msg.tropo_delay_correction.stddev, 92,
                    "incorrect value for tropo_delay_correction.stddev, expected 92, is {}",
                    msg.tropo_delay_correction.stddev
                );
                assert_eq!(
                    msg.tropo_delay_correction.wet, 33,
                    "incorrect value for tropo_delay_correction.wet, expected 33, is {}",
                    msg.tropo_delay_correction.wet
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGriddedCorrectionDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_gridded_correction_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_gridded_correction_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 250, 5, 108, 106, 254, 164, 217, 44, 53, 98, 93, 63, 147, 104, 252, 133, 245, 28,
            95, 100, 147, 41, 33, 92, 87, 25, 142, 151, 74, 151, 95, 94, 7, 146, 237, 45, 167, 86,
            42, 116, 224, 169, 234, 220, 23, 176, 18, 13, 178, 79, 160, 160, 110, 15, 53, 206, 151,
            158, 22, 117, 184, 48, 170, 82, 40, 53, 122, 69, 180, 110, 38, 65, 104, 244, 19, 238,
            227, 88, 169, 164, 146, 63, 37, 183, 85, 71, 235, 168, 114, 211, 105, 221, 156, 60, 18,
            230, 2, 142, 172, 16, 39, 33, 126, 106, 99, 188, 234, 41, 162, 197, 138, 227, 80, 12,
            54, 67, 238, 5, 93, 1, 207, 129, 13, 46, 115, 49, 58, 185, 127, 156, 200, 96, 217, 202,
            15, 245, 55, 198, 81, 218, 132, 70, 73, 82, 147, 26, 255, 14, 134, 96, 138, 55, 214,
            83, 156, 170, 163, 79, 173, 228, 115, 51, 241, 107, 245, 112, 168, 210, 10, 5, 117, 1,
            57, 108, 248, 212, 145, 119, 226, 165, 5, 141, 202, 106, 0, 60, 36, 61, 243, 203, 216,
            215, 12, 137, 16, 28, 247, 115, 152, 181, 119, 208, 228, 203, 236, 34, 167, 196, 32,
            109, 1, 17, 101, 200, 25, 94, 125, 168, 137, 157, 4, 164, 29, 31, 48, 132, 72, 229,
            126, 186, 68, 76, 133, 21, 0, 180, 139, 164, 148, 119, 149, 214, 120, 177, 201, 80, 80,
            105, 10, 136, 118, 77, 46, 233, 233, 227, 11, 158, 103, 167, 216,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrGriddedCorrectionDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrGriddedCorrectionDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5fa,
                    "Incorrect message type, expected 0x5fa, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6a6c,
                    "incorrect sender id, expected 0x6a6c, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 245,
                    "incorrect value for header.iod_atmo, expected 245, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 37695,
                    "incorrect value for header.num_msgs, expected 37695, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 64616,
                    "incorrect value for header.seq_num, expected 64616, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.time.tow, 892131748,
                    "incorrect value for header.time.tow, expected 892131748, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 23906,
                    "incorrect value for header.time.wn, expected 23906, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.tropo_quality_indicator, 28,
                    "incorrect value for header.tropo_quality_indicator, expected 28, is {}",
                    msg.header.tropo_quality_indicator
                );
                assert_eq!(
                    msg.header.update_interval, 133,
                    "incorrect value for header.update_interval, expected 133, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.index, 25695,
                    "incorrect value for index, expected 25695, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.stec_residuals[0].residual, -26738,
                    "incorrect value for stec_residuals[0].residual, expected -26738, is {}",
                    msg.stec_residuals[0].residual
                );
                assert_eq!(
                    msg.stec_residuals[0].stddev, 74,
                    "incorrect value for stec_residuals[0].stddev, expected 74, is {}",
                    msg.stec_residuals[0].stddev
                );
                assert_eq!(
                    msg.stec_residuals[0].sv_id.constellation, 25,
                    "incorrect value for stec_residuals[0].sv_id.constellation, expected 25, is {}",
                    msg.stec_residuals[0].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[0].sv_id.sat_id, 87,
                    "incorrect value for stec_residuals[0].sv_id.sat_id, expected 87, is {}",
                    msg.stec_residuals[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[1].residual, 1886,
                    "incorrect value for stec_residuals[1].residual, expected 1886, is {}",
                    msg.stec_residuals[1].residual
                );
                assert_eq!(
                    msg.stec_residuals[1].stddev, 146,
                    "incorrect value for stec_residuals[1].stddev, expected 146, is {}",
                    msg.stec_residuals[1].stddev
                );
                assert_eq!(
                    msg.stec_residuals[1].sv_id.constellation, 95,
                    "incorrect value for stec_residuals[1].sv_id.constellation, expected 95, is {}",
                    msg.stec_residuals[1].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[1].sv_id.sat_id, 151,
                    "incorrect value for stec_residuals[1].sv_id.sat_id, expected 151, is {}",
                    msg.stec_residuals[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[2].residual, 22183,
                    "incorrect value for stec_residuals[2].residual, expected 22183, is {}",
                    msg.stec_residuals[2].residual
                );
                assert_eq!(
                    msg.stec_residuals[2].stddev, 42,
                    "incorrect value for stec_residuals[2].stddev, expected 42, is {}",
                    msg.stec_residuals[2].stddev
                );
                assert_eq!(
                    msg.stec_residuals[2].sv_id.constellation, 45,
                    "incorrect value for stec_residuals[2].sv_id.constellation, expected 45, is {}",
                    msg.stec_residuals[2].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[2].sv_id.sat_id, 237,
                    "incorrect value for stec_residuals[2].sv_id.sat_id, expected 237, is {}",
                    msg.stec_residuals[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[3].residual, -5463,
                    "incorrect value for stec_residuals[3].residual, expected -5463, is {}",
                    msg.stec_residuals[3].residual
                );
                assert_eq!(
                    msg.stec_residuals[3].stddev, 220,
                    "incorrect value for stec_residuals[3].stddev, expected 220, is {}",
                    msg.stec_residuals[3].stddev
                );
                assert_eq!(msg.stec_residuals[3].sv_id.constellation, 224, "incorrect value for stec_residuals[3].sv_id.constellation, expected 224, is {}", msg.stec_residuals[3].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[3].sv_id.sat_id, 116,
                    "incorrect value for stec_residuals[3].sv_id.sat_id, expected 116, is {}",
                    msg.stec_residuals[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[4].residual, 3346,
                    "incorrect value for stec_residuals[4].residual, expected 3346, is {}",
                    msg.stec_residuals[4].residual
                );
                assert_eq!(
                    msg.stec_residuals[4].stddev, 178,
                    "incorrect value for stec_residuals[4].stddev, expected 178, is {}",
                    msg.stec_residuals[4].stddev
                );
                assert_eq!(msg.stec_residuals[4].sv_id.constellation, 176, "incorrect value for stec_residuals[4].sv_id.constellation, expected 176, is {}", msg.stec_residuals[4].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[4].sv_id.sat_id, 23,
                    "incorrect value for stec_residuals[4].sv_id.sat_id, expected 23, is {}",
                    msg.stec_residuals[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[5].residual, 28320,
                    "incorrect value for stec_residuals[5].residual, expected 28320, is {}",
                    msg.stec_residuals[5].residual
                );
                assert_eq!(
                    msg.stec_residuals[5].stddev, 15,
                    "incorrect value for stec_residuals[5].stddev, expected 15, is {}",
                    msg.stec_residuals[5].stddev
                );
                assert_eq!(msg.stec_residuals[5].sv_id.constellation, 160, "incorrect value for stec_residuals[5].sv_id.constellation, expected 160, is {}", msg.stec_residuals[5].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[5].sv_id.sat_id, 79,
                    "incorrect value for stec_residuals[5].sv_id.sat_id, expected 79, is {}",
                    msg.stec_residuals[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[6].residual, -24937,
                    "incorrect value for stec_residuals[6].residual, expected -24937, is {}",
                    msg.stec_residuals[6].residual
                );
                assert_eq!(
                    msg.stec_residuals[6].stddev, 22,
                    "incorrect value for stec_residuals[6].stddev, expected 22, is {}",
                    msg.stec_residuals[6].stddev
                );
                assert_eq!(msg.stec_residuals[6].sv_id.constellation, 206, "incorrect value for stec_residuals[6].sv_id.constellation, expected 206, is {}", msg.stec_residuals[6].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[6].sv_id.sat_id, 53,
                    "incorrect value for stec_residuals[6].sv_id.sat_id, expected 53, is {}",
                    msg.stec_residuals[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[7].residual, -21968,
                    "incorrect value for stec_residuals[7].residual, expected -21968, is {}",
                    msg.stec_residuals[7].residual
                );
                assert_eq!(
                    msg.stec_residuals[7].stddev, 82,
                    "incorrect value for stec_residuals[7].stddev, expected 82, is {}",
                    msg.stec_residuals[7].stddev
                );
                assert_eq!(msg.stec_residuals[7].sv_id.constellation, 184, "incorrect value for stec_residuals[7].sv_id.constellation, expected 184, is {}", msg.stec_residuals[7].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[7].sv_id.sat_id, 117,
                    "incorrect value for stec_residuals[7].sv_id.sat_id, expected 117, is {}",
                    msg.stec_residuals[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[8].residual, 17786,
                    "incorrect value for stec_residuals[8].residual, expected 17786, is {}",
                    msg.stec_residuals[8].residual
                );
                assert_eq!(
                    msg.stec_residuals[8].stddev, 180,
                    "incorrect value for stec_residuals[8].stddev, expected 180, is {}",
                    msg.stec_residuals[8].stddev
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.constellation, 53,
                    "incorrect value for stec_residuals[8].sv_id.constellation, expected 53, is {}",
                    msg.stec_residuals[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.sat_id, 40,
                    "incorrect value for stec_residuals[8].sv_id.sat_id, expected 40, is {}",
                    msg.stec_residuals[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[9].residual, 26689,
                    "incorrect value for stec_residuals[9].residual, expected 26689, is {}",
                    msg.stec_residuals[9].residual
                );
                assert_eq!(
                    msg.stec_residuals[9].stddev, 244,
                    "incorrect value for stec_residuals[9].stddev, expected 244, is {}",
                    msg.stec_residuals[9].stddev
                );
                assert_eq!(
                    msg.stec_residuals[9].sv_id.constellation, 38,
                    "incorrect value for stec_residuals[9].sv_id.constellation, expected 38, is {}",
                    msg.stec_residuals[9].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[9].sv_id.sat_id, 110,
                    "incorrect value for stec_residuals[9].sv_id.sat_id, expected 110, is {}",
                    msg.stec_residuals[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[10].residual, 22755,
                    "incorrect value for stec_residuals[10].residual, expected 22755, is {}",
                    msg.stec_residuals[10].residual
                );
                assert_eq!(
                    msg.stec_residuals[10].stddev, 169,
                    "incorrect value for stec_residuals[10].stddev, expected 169, is {}",
                    msg.stec_residuals[10].stddev
                );
                assert_eq!(msg.stec_residuals[10].sv_id.constellation, 238, "incorrect value for stec_residuals[10].sv_id.constellation, expected 238, is {}", msg.stec_residuals[10].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[10].sv_id.sat_id, 19,
                    "incorrect value for stec_residuals[10].sv_id.sat_id, expected 19, is {}",
                    msg.stec_residuals[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[11].residual, 9535,
                    "incorrect value for stec_residuals[11].residual, expected 9535, is {}",
                    msg.stec_residuals[11].residual
                );
                assert_eq!(
                    msg.stec_residuals[11].stddev, 183,
                    "incorrect value for stec_residuals[11].stddev, expected 183, is {}",
                    msg.stec_residuals[11].stddev
                );
                assert_eq!(msg.stec_residuals[11].sv_id.constellation, 146, "incorrect value for stec_residuals[11].sv_id.constellation, expected 146, is {}", msg.stec_residuals[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[11].sv_id.sat_id, 164,
                    "incorrect value for stec_residuals[11].sv_id.sat_id, expected 164, is {}",
                    msg.stec_residuals[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[12].residual, -22293,
                    "incorrect value for stec_residuals[12].residual, expected -22293, is {}",
                    msg.stec_residuals[12].residual
                );
                assert_eq!(
                    msg.stec_residuals[12].stddev, 114,
                    "incorrect value for stec_residuals[12].stddev, expected 114, is {}",
                    msg.stec_residuals[12].stddev
                );
                assert_eq!(msg.stec_residuals[12].sv_id.constellation, 71, "incorrect value for stec_residuals[12].sv_id.constellation, expected 71, is {}", msg.stec_residuals[12].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[12].sv_id.sat_id, 85,
                    "incorrect value for stec_residuals[12].sv_id.sat_id, expected 85, is {}",
                    msg.stec_residuals[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[13].residual, -25379,
                    "incorrect value for stec_residuals[13].residual, expected -25379, is {}",
                    msg.stec_residuals[13].residual
                );
                assert_eq!(
                    msg.stec_residuals[13].stddev, 60,
                    "incorrect value for stec_residuals[13].stddev, expected 60, is {}",
                    msg.stec_residuals[13].stddev
                );
                assert_eq!(msg.stec_residuals[13].sv_id.constellation, 105, "incorrect value for stec_residuals[13].sv_id.constellation, expected 105, is {}", msg.stec_residuals[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[13].sv_id.sat_id, 211,
                    "incorrect value for stec_residuals[13].sv_id.sat_id, expected 211, is {}",
                    msg.stec_residuals[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[14].residual, -29182,
                    "incorrect value for stec_residuals[14].residual, expected -29182, is {}",
                    msg.stec_residuals[14].residual
                );
                assert_eq!(
                    msg.stec_residuals[14].stddev, 172,
                    "incorrect value for stec_residuals[14].stddev, expected 172, is {}",
                    msg.stec_residuals[14].stddev
                );
                assert_eq!(msg.stec_residuals[14].sv_id.constellation, 230, "incorrect value for stec_residuals[14].sv_id.constellation, expected 230, is {}", msg.stec_residuals[14].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[14].sv_id.sat_id, 18,
                    "incorrect value for stec_residuals[14].sv_id.sat_id, expected 18, is {}",
                    msg.stec_residuals[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[15].residual, 32289,
                    "incorrect value for stec_residuals[15].residual, expected 32289, is {}",
                    msg.stec_residuals[15].residual
                );
                assert_eq!(
                    msg.stec_residuals[15].stddev, 106,
                    "incorrect value for stec_residuals[15].stddev, expected 106, is {}",
                    msg.stec_residuals[15].stddev
                );
                assert_eq!(msg.stec_residuals[15].sv_id.constellation, 39, "incorrect value for stec_residuals[15].sv_id.constellation, expected 39, is {}", msg.stec_residuals[15].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[15].sv_id.sat_id, 16,
                    "incorrect value for stec_residuals[15].sv_id.sat_id, expected 16, is {}",
                    msg.stec_residuals[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[16].residual, 10730,
                    "incorrect value for stec_residuals[16].residual, expected 10730, is {}",
                    msg.stec_residuals[16].residual
                );
                assert_eq!(
                    msg.stec_residuals[16].stddev, 162,
                    "incorrect value for stec_residuals[16].stddev, expected 162, is {}",
                    msg.stec_residuals[16].stddev
                );
                assert_eq!(msg.stec_residuals[16].sv_id.constellation, 188, "incorrect value for stec_residuals[16].sv_id.constellation, expected 188, is {}", msg.stec_residuals[16].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[16].sv_id.sat_id, 99,
                    "incorrect value for stec_residuals[16].sv_id.sat_id, expected 99, is {}",
                    msg.stec_residuals[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[17].residual, 20707,
                    "incorrect value for stec_residuals[17].residual, expected 20707, is {}",
                    msg.stec_residuals[17].residual
                );
                assert_eq!(
                    msg.stec_residuals[17].stddev, 12,
                    "incorrect value for stec_residuals[17].stddev, expected 12, is {}",
                    msg.stec_residuals[17].stddev
                );
                assert_eq!(msg.stec_residuals[17].sv_id.constellation, 138, "incorrect value for stec_residuals[17].sv_id.constellation, expected 138, is {}", msg.stec_residuals[17].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[17].sv_id.sat_id, 197,
                    "incorrect value for stec_residuals[17].sv_id.sat_id, expected 197, is {}",
                    msg.stec_residuals[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[18].residual, 1518,
                    "incorrect value for stec_residuals[18].residual, expected 1518, is {}",
                    msg.stec_residuals[18].residual
                );
                assert_eq!(
                    msg.stec_residuals[18].stddev, 93,
                    "incorrect value for stec_residuals[18].stddev, expected 93, is {}",
                    msg.stec_residuals[18].stddev
                );
                assert_eq!(msg.stec_residuals[18].sv_id.constellation, 67, "incorrect value for stec_residuals[18].sv_id.constellation, expected 67, is {}", msg.stec_residuals[18].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[18].sv_id.sat_id, 54,
                    "incorrect value for stec_residuals[18].sv_id.sat_id, expected 54, is {}",
                    msg.stec_residuals[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[19].residual, 3457,
                    "incorrect value for stec_residuals[19].residual, expected 3457, is {}",
                    msg.stec_residuals[19].residual
                );
                assert_eq!(
                    msg.stec_residuals[19].stddev, 46,
                    "incorrect value for stec_residuals[19].stddev, expected 46, is {}",
                    msg.stec_residuals[19].stddev
                );
                assert_eq!(msg.stec_residuals[19].sv_id.constellation, 207, "incorrect value for stec_residuals[19].sv_id.constellation, expected 207, is {}", msg.stec_residuals[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[19].sv_id.sat_id, 1,
                    "incorrect value for stec_residuals[19].sv_id.sat_id, expected 1, is {}",
                    msg.stec_residuals[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[20].residual, -18118,
                    "incorrect value for stec_residuals[20].residual, expected -18118, is {}",
                    msg.stec_residuals[20].residual
                );
                assert_eq!(
                    msg.stec_residuals[20].stddev, 127,
                    "incorrect value for stec_residuals[20].stddev, expected 127, is {}",
                    msg.stec_residuals[20].stddev
                );
                assert_eq!(msg.stec_residuals[20].sv_id.constellation, 49, "incorrect value for stec_residuals[20].sv_id.constellation, expected 49, is {}", msg.stec_residuals[20].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[20].sv_id.sat_id, 115,
                    "incorrect value for stec_residuals[20].sv_id.sat_id, expected 115, is {}",
                    msg.stec_residuals[20].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[21].residual, -9888,
                    "incorrect value for stec_residuals[21].residual, expected -9888, is {}",
                    msg.stec_residuals[21].residual
                );
                assert_eq!(
                    msg.stec_residuals[21].stddev, 202,
                    "incorrect value for stec_residuals[21].stddev, expected 202, is {}",
                    msg.stec_residuals[21].stddev
                );
                assert_eq!(msg.stec_residuals[21].sv_id.constellation, 200, "incorrect value for stec_residuals[21].sv_id.constellation, expected 200, is {}", msg.stec_residuals[21].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[21].sv_id.sat_id, 156,
                    "incorrect value for stec_residuals[21].sv_id.sat_id, expected 156, is {}",
                    msg.stec_residuals[21].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[22].residual, -14793,
                    "incorrect value for stec_residuals[22].residual, expected -14793, is {}",
                    msg.stec_residuals[22].residual
                );
                assert_eq!(
                    msg.stec_residuals[22].stddev, 81,
                    "incorrect value for stec_residuals[22].stddev, expected 81, is {}",
                    msg.stec_residuals[22].stddev
                );
                assert_eq!(msg.stec_residuals[22].sv_id.constellation, 245, "incorrect value for stec_residuals[22].sv_id.constellation, expected 245, is {}", msg.stec_residuals[22].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[22].sv_id.sat_id, 15,
                    "incorrect value for stec_residuals[22].sv_id.sat_id, expected 15, is {}",
                    msg.stec_residuals[22].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[23].residual, 18758,
                    "incorrect value for stec_residuals[23].residual, expected 18758, is {}",
                    msg.stec_residuals[23].residual
                );
                assert_eq!(
                    msg.stec_residuals[23].stddev, 82,
                    "incorrect value for stec_residuals[23].stddev, expected 82, is {}",
                    msg.stec_residuals[23].stddev
                );
                assert_eq!(msg.stec_residuals[23].sv_id.constellation, 132, "incorrect value for stec_residuals[23].sv_id.constellation, expected 132, is {}", msg.stec_residuals[23].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[23].sv_id.sat_id, 218,
                    "incorrect value for stec_residuals[23].sv_id.sat_id, expected 218, is {}",
                    msg.stec_residuals[23].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[24].residual, 3839,
                    "incorrect value for stec_residuals[24].residual, expected 3839, is {}",
                    msg.stec_residuals[24].residual
                );
                assert_eq!(
                    msg.stec_residuals[24].stddev, 134,
                    "incorrect value for stec_residuals[24].stddev, expected 134, is {}",
                    msg.stec_residuals[24].stddev
                );
                assert_eq!(msg.stec_residuals[24].sv_id.constellation, 26, "incorrect value for stec_residuals[24].sv_id.constellation, expected 26, is {}", msg.stec_residuals[24].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[24].sv_id.sat_id, 147,
                    "incorrect value for stec_residuals[24].sv_id.sat_id, expected 147, is {}",
                    msg.stec_residuals[24].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[25].residual, -10697,
                    "incorrect value for stec_residuals[25].residual, expected -10697, is {}",
                    msg.stec_residuals[25].residual
                );
                assert_eq!(
                    msg.stec_residuals[25].stddev, 83,
                    "incorrect value for stec_residuals[25].stddev, expected 83, is {}",
                    msg.stec_residuals[25].stddev
                );
                assert_eq!(msg.stec_residuals[25].sv_id.constellation, 138, "incorrect value for stec_residuals[25].sv_id.constellation, expected 138, is {}", msg.stec_residuals[25].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[25].sv_id.sat_id, 96,
                    "incorrect value for stec_residuals[25].sv_id.sat_id, expected 96, is {}",
                    msg.stec_residuals[25].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[26].residual, 20387,
                    "incorrect value for stec_residuals[26].residual, expected 20387, is {}",
                    msg.stec_residuals[26].residual
                );
                assert_eq!(
                    msg.stec_residuals[26].stddev, 173,
                    "incorrect value for stec_residuals[26].stddev, expected 173, is {}",
                    msg.stec_residuals[26].stddev
                );
                assert_eq!(msg.stec_residuals[26].sv_id.constellation, 170, "incorrect value for stec_residuals[26].sv_id.constellation, expected 170, is {}", msg.stec_residuals[26].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[26].sv_id.sat_id, 156,
                    "incorrect value for stec_residuals[26].sv_id.sat_id, expected 156, is {}",
                    msg.stec_residuals[26].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[27].residual, -3789,
                    "incorrect value for stec_residuals[27].residual, expected -3789, is {}",
                    msg.stec_residuals[27].residual
                );
                assert_eq!(
                    msg.stec_residuals[27].stddev, 107,
                    "incorrect value for stec_residuals[27].stddev, expected 107, is {}",
                    msg.stec_residuals[27].stddev
                );
                assert_eq!(msg.stec_residuals[27].sv_id.constellation, 115, "incorrect value for stec_residuals[27].sv_id.constellation, expected 115, is {}", msg.stec_residuals[27].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[27].sv_id.sat_id, 228,
                    "incorrect value for stec_residuals[27].sv_id.sat_id, expected 228, is {}",
                    msg.stec_residuals[27].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[28].residual, -11608,
                    "incorrect value for stec_residuals[28].residual, expected -11608, is {}",
                    msg.stec_residuals[28].residual
                );
                assert_eq!(
                    msg.stec_residuals[28].stddev, 10,
                    "incorrect value for stec_residuals[28].stddev, expected 10, is {}",
                    msg.stec_residuals[28].stddev
                );
                assert_eq!(msg.stec_residuals[28].sv_id.constellation, 112, "incorrect value for stec_residuals[28].sv_id.constellation, expected 112, is {}", msg.stec_residuals[28].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[28].sv_id.sat_id, 245,
                    "incorrect value for stec_residuals[28].sv_id.sat_id, expected 245, is {}",
                    msg.stec_residuals[28].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[29].residual, 14593,
                    "incorrect value for stec_residuals[29].residual, expected 14593, is {}",
                    msg.stec_residuals[29].residual
                );
                assert_eq!(
                    msg.stec_residuals[29].stddev, 108,
                    "incorrect value for stec_residuals[29].stddev, expected 108, is {}",
                    msg.stec_residuals[29].stddev
                );
                assert_eq!(msg.stec_residuals[29].sv_id.constellation, 117, "incorrect value for stec_residuals[29].sv_id.constellation, expected 117, is {}", msg.stec_residuals[29].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[29].sv_id.sat_id, 5,
                    "incorrect value for stec_residuals[29].sv_id.sat_id, expected 5, is {}",
                    msg.stec_residuals[29].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[30].residual, 30609,
                    "incorrect value for stec_residuals[30].residual, expected 30609, is {}",
                    msg.stec_residuals[30].residual
                );
                assert_eq!(
                    msg.stec_residuals[30].stddev, 226,
                    "incorrect value for stec_residuals[30].stddev, expected 226, is {}",
                    msg.stec_residuals[30].stddev
                );
                assert_eq!(msg.stec_residuals[30].sv_id.constellation, 212, "incorrect value for stec_residuals[30].sv_id.constellation, expected 212, is {}", msg.stec_residuals[30].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[30].sv_id.sat_id, 248,
                    "incorrect value for stec_residuals[30].sv_id.sat_id, expected 248, is {}",
                    msg.stec_residuals[30].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[31].residual, -13683,
                    "incorrect value for stec_residuals[31].residual, expected -13683, is {}",
                    msg.stec_residuals[31].residual
                );
                assert_eq!(
                    msg.stec_residuals[31].stddev, 106,
                    "incorrect value for stec_residuals[31].stddev, expected 106, is {}",
                    msg.stec_residuals[31].stddev
                );
                assert_eq!(
                    msg.stec_residuals[31].sv_id.constellation, 5,
                    "incorrect value for stec_residuals[31].sv_id.constellation, expected 5, is {}",
                    msg.stec_residuals[31].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[31].sv_id.sat_id, 165,
                    "incorrect value for stec_residuals[31].sv_id.sat_id, expected 165, is {}",
                    msg.stec_residuals[31].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[32].residual, 15652,
                    "incorrect value for stec_residuals[32].residual, expected 15652, is {}",
                    msg.stec_residuals[32].residual
                );
                assert_eq!(
                    msg.stec_residuals[32].stddev, 243,
                    "incorrect value for stec_residuals[32].stddev, expected 243, is {}",
                    msg.stec_residuals[32].stddev
                );
                assert_eq!(msg.stec_residuals[32].sv_id.constellation, 60, "incorrect value for stec_residuals[32].sv_id.constellation, expected 60, is {}", msg.stec_residuals[32].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[32].sv_id.sat_id, 0,
                    "incorrect value for stec_residuals[32].sv_id.sat_id, expected 0, is {}",
                    msg.stec_residuals[32].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[33].residual, 3287,
                    "incorrect value for stec_residuals[33].residual, expected 3287, is {}",
                    msg.stec_residuals[33].residual
                );
                assert_eq!(
                    msg.stec_residuals[33].stddev, 137,
                    "incorrect value for stec_residuals[33].stddev, expected 137, is {}",
                    msg.stec_residuals[33].stddev
                );
                assert_eq!(msg.stec_residuals[33].sv_id.constellation, 216, "incorrect value for stec_residuals[33].sv_id.constellation, expected 216, is {}", msg.stec_residuals[33].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[33].sv_id.sat_id, 203,
                    "incorrect value for stec_residuals[33].sv_id.sat_id, expected 203, is {}",
                    msg.stec_residuals[33].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[34].residual, 29687,
                    "incorrect value for stec_residuals[34].residual, expected 29687, is {}",
                    msg.stec_residuals[34].residual
                );
                assert_eq!(
                    msg.stec_residuals[34].stddev, 152,
                    "incorrect value for stec_residuals[34].stddev, expected 152, is {}",
                    msg.stec_residuals[34].stddev
                );
                assert_eq!(msg.stec_residuals[34].sv_id.constellation, 28, "incorrect value for stec_residuals[34].sv_id.constellation, expected 28, is {}", msg.stec_residuals[34].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[34].sv_id.sat_id, 16,
                    "incorrect value for stec_residuals[34].sv_id.sat_id, expected 16, is {}",
                    msg.stec_residuals[34].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[35].residual, -6960,
                    "incorrect value for stec_residuals[35].residual, expected -6960, is {}",
                    msg.stec_residuals[35].residual
                );
                assert_eq!(
                    msg.stec_residuals[35].stddev, 203,
                    "incorrect value for stec_residuals[35].stddev, expected 203, is {}",
                    msg.stec_residuals[35].stddev
                );
                assert_eq!(msg.stec_residuals[35].sv_id.constellation, 119, "incorrect value for stec_residuals[35].sv_id.constellation, expected 119, is {}", msg.stec_residuals[35].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[35].sv_id.sat_id, 181,
                    "incorrect value for stec_residuals[35].sv_id.sat_id, expected 181, is {}",
                    msg.stec_residuals[35].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[36].residual, -15193,
                    "incorrect value for stec_residuals[36].residual, expected -15193, is {}",
                    msg.stec_residuals[36].residual
                );
                assert_eq!(
                    msg.stec_residuals[36].stddev, 32,
                    "incorrect value for stec_residuals[36].stddev, expected 32, is {}",
                    msg.stec_residuals[36].stddev
                );
                assert_eq!(msg.stec_residuals[36].sv_id.constellation, 34, "incorrect value for stec_residuals[36].sv_id.constellation, expected 34, is {}", msg.stec_residuals[36].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[36].sv_id.sat_id, 236,
                    "incorrect value for stec_residuals[36].sv_id.sat_id, expected 236, is {}",
                    msg.stec_residuals[36].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[37].residual, 25873,
                    "incorrect value for stec_residuals[37].residual, expected 25873, is {}",
                    msg.stec_residuals[37].residual
                );
                assert_eq!(
                    msg.stec_residuals[37].stddev, 200,
                    "incorrect value for stec_residuals[37].stddev, expected 200, is {}",
                    msg.stec_residuals[37].stddev
                );
                assert_eq!(
                    msg.stec_residuals[37].sv_id.constellation, 1,
                    "incorrect value for stec_residuals[37].sv_id.constellation, expected 1, is {}",
                    msg.stec_residuals[37].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[37].sv_id.sat_id, 109,
                    "incorrect value for stec_residuals[37].sv_id.sat_id, expected 109, is {}",
                    msg.stec_residuals[37].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[38].residual, -22403,
                    "incorrect value for stec_residuals[38].residual, expected -22403, is {}",
                    msg.stec_residuals[38].residual
                );
                assert_eq!(
                    msg.stec_residuals[38].stddev, 137,
                    "incorrect value for stec_residuals[38].stddev, expected 137, is {}",
                    msg.stec_residuals[38].stddev
                );
                assert_eq!(msg.stec_residuals[38].sv_id.constellation, 94, "incorrect value for stec_residuals[38].sv_id.constellation, expected 94, is {}", msg.stec_residuals[38].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[38].sv_id.sat_id, 25,
                    "incorrect value for stec_residuals[38].sv_id.sat_id, expected 25, is {}",
                    msg.stec_residuals[38].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[39].residual, 7588,
                    "incorrect value for stec_residuals[39].residual, expected 7588, is {}",
                    msg.stec_residuals[39].residual
                );
                assert_eq!(
                    msg.stec_residuals[39].stddev, 31,
                    "incorrect value for stec_residuals[39].stddev, expected 31, is {}",
                    msg.stec_residuals[39].stddev
                );
                assert_eq!(
                    msg.stec_residuals[39].sv_id.constellation, 4,
                    "incorrect value for stec_residuals[39].sv_id.constellation, expected 4, is {}",
                    msg.stec_residuals[39].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[39].sv_id.sat_id, 157,
                    "incorrect value for stec_residuals[39].sv_id.sat_id, expected 157, is {}",
                    msg.stec_residuals[39].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[40].residual, -6840,
                    "incorrect value for stec_residuals[40].residual, expected -6840, is {}",
                    msg.stec_residuals[40].residual
                );
                assert_eq!(
                    msg.stec_residuals[40].stddev, 126,
                    "incorrect value for stec_residuals[40].stddev, expected 126, is {}",
                    msg.stec_residuals[40].stddev
                );
                assert_eq!(msg.stec_residuals[40].sv_id.constellation, 132, "incorrect value for stec_residuals[40].sv_id.constellation, expected 132, is {}", msg.stec_residuals[40].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[40].sv_id.sat_id, 48,
                    "incorrect value for stec_residuals[40].sv_id.sat_id, expected 48, is {}",
                    msg.stec_residuals[40].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[41].residual, -31412,
                    "incorrect value for stec_residuals[41].residual, expected -31412, is {}",
                    msg.stec_residuals[41].residual
                );
                assert_eq!(
                    msg.stec_residuals[41].stddev, 21,
                    "incorrect value for stec_residuals[41].stddev, expected 21, is {}",
                    msg.stec_residuals[41].stddev
                );
                assert_eq!(msg.stec_residuals[41].sv_id.constellation, 68, "incorrect value for stec_residuals[41].sv_id.constellation, expected 68, is {}", msg.stec_residuals[41].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[41].sv_id.sat_id, 186,
                    "incorrect value for stec_residuals[41].sv_id.sat_id, expected 186, is {}",
                    msg.stec_residuals[41].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[42].residual, -23413,
                    "incorrect value for stec_residuals[42].residual, expected -23413, is {}",
                    msg.stec_residuals[42].residual
                );
                assert_eq!(
                    msg.stec_residuals[42].stddev, 148,
                    "incorrect value for stec_residuals[42].stddev, expected 148, is {}",
                    msg.stec_residuals[42].stddev
                );
                assert_eq!(msg.stec_residuals[42].sv_id.constellation, 180, "incorrect value for stec_residuals[42].sv_id.constellation, expected 180, is {}", msg.stec_residuals[42].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[42].sv_id.sat_id, 0,
                    "incorrect value for stec_residuals[42].sv_id.sat_id, expected 0, is {}",
                    msg.stec_residuals[42].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[43].residual, 30934,
                    "incorrect value for stec_residuals[43].residual, expected 30934, is {}",
                    msg.stec_residuals[43].residual
                );
                assert_eq!(
                    msg.stec_residuals[43].stddev, 177,
                    "incorrect value for stec_residuals[43].stddev, expected 177, is {}",
                    msg.stec_residuals[43].stddev
                );
                assert_eq!(msg.stec_residuals[43].sv_id.constellation, 149, "incorrect value for stec_residuals[43].sv_id.constellation, expected 149, is {}", msg.stec_residuals[43].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[43].sv_id.sat_id, 119,
                    "incorrect value for stec_residuals[43].sv_id.sat_id, expected 119, is {}",
                    msg.stec_residuals[43].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[44].residual, 26960,
                    "incorrect value for stec_residuals[44].residual, expected 26960, is {}",
                    msg.stec_residuals[44].residual
                );
                assert_eq!(
                    msg.stec_residuals[44].stddev, 10,
                    "incorrect value for stec_residuals[44].stddev, expected 10, is {}",
                    msg.stec_residuals[44].stddev
                );
                assert_eq!(msg.stec_residuals[44].sv_id.constellation, 80, "incorrect value for stec_residuals[44].sv_id.constellation, expected 80, is {}", msg.stec_residuals[44].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[44].sv_id.sat_id, 201,
                    "incorrect value for stec_residuals[44].sv_id.sat_id, expected 201, is {}",
                    msg.stec_residuals[44].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[45].residual, 11853,
                    "incorrect value for stec_residuals[45].residual, expected 11853, is {}",
                    msg.stec_residuals[45].residual
                );
                assert_eq!(
                    msg.stec_residuals[45].stddev, 233,
                    "incorrect value for stec_residuals[45].stddev, expected 233, is {}",
                    msg.stec_residuals[45].stddev
                );
                assert_eq!(msg.stec_residuals[45].sv_id.constellation, 118, "incorrect value for stec_residuals[45].sv_id.constellation, expected 118, is {}", msg.stec_residuals[45].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[45].sv_id.sat_id, 136,
                    "incorrect value for stec_residuals[45].sv_id.sat_id, expected 136, is {}",
                    msg.stec_residuals[45].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[46].residual, -25077,
                    "incorrect value for stec_residuals[46].residual, expected -25077, is {}",
                    msg.stec_residuals[46].residual
                );
                assert_eq!(
                    msg.stec_residuals[46].stddev, 103,
                    "incorrect value for stec_residuals[46].stddev, expected 103, is {}",
                    msg.stec_residuals[46].stddev
                );
                assert_eq!(msg.stec_residuals[46].sv_id.constellation, 227, "incorrect value for stec_residuals[46].sv_id.constellation, expected 227, is {}", msg.stec_residuals[46].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[46].sv_id.sat_id, 233,
                    "incorrect value for stec_residuals[46].sv_id.sat_id, expected 233, is {}",
                    msg.stec_residuals[46].sv_id.sat_id
                );
                assert_eq!(
                    msg.tropo_delay_correction.hydro, 10643,
                    "incorrect value for tropo_delay_correction.hydro, expected 10643, is {}",
                    msg.tropo_delay_correction.hydro
                );
                assert_eq!(
                    msg.tropo_delay_correction.stddev, 92,
                    "incorrect value for tropo_delay_correction.stddev, expected 92, is {}",
                    msg.tropo_delay_correction.stddev
                );
                assert_eq!(
                    msg.tropo_delay_correction.wet, 33,
                    "incorrect value for tropo_delay_correction.wet, expected 33, is {}",
                    msg.tropo_delay_correction.wet
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGriddedCorrectionDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
