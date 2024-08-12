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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionNoStdDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_gridded_correction_no_std_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 240, 5, 102, 28, 254, 179, 240, 33, 169, 236, 34, 117, 245, 67, 248, 233, 236, 230,
            230, 103, 122, 63, 101, 231, 157, 115, 162, 197, 146, 35, 107, 222, 109, 52, 41, 86,
            12, 237, 184, 65, 204, 137, 148, 171, 183, 11, 0, 180, 203, 172, 53, 196, 85, 186, 115,
            203, 92, 166, 30, 42, 13, 200, 71, 98, 137, 219, 160, 95, 216, 95, 250, 99, 196, 92,
            214, 159, 253, 195, 222, 233, 146, 233, 63, 76, 24, 106, 40, 253, 65, 9, 183, 40, 215,
            188, 59, 117, 69, 97, 115, 60, 56, 0, 141, 207, 171, 54, 161, 23, 61, 0, 87, 230, 123,
            87, 36, 184, 255, 14, 163, 187, 224, 43, 151, 151, 104, 39, 57, 5, 54, 48, 224, 181,
            129, 60, 92, 171, 114, 109, 109, 12, 23, 118, 8, 64, 159, 54, 216, 33, 20, 24, 68, 160,
            36, 38, 222, 145, 190, 92, 99, 108, 159, 232, 240, 227, 221, 253, 15, 62, 23, 121, 185,
            168, 116, 4, 147, 123, 72, 223, 119, 226, 242, 161, 204, 180, 202, 137, 166, 58, 24,
            124, 19, 181, 188, 16, 107, 66, 231, 63, 1, 64, 252, 115, 62, 233, 97, 250, 86, 156,
            221, 49, 178, 32, 73, 198, 67, 249, 253, 74, 56, 38, 165, 119, 92, 99, 44, 95, 131, 89,
            192, 225, 55, 95, 171, 88, 205, 21, 116, 231, 83, 71, 71, 100, 110, 217, 254, 152, 212,
            18, 8, 40, 157, 244, 54, 72, 240, 231, 189, 111, 195, 205, 81,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5f0,
                    "Incorrect message type, expected 0x5f0, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1c66,
                    "incorrect sender id, expected 0x1c66, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 236,
                    "incorrect value for header.iod_atmo, expected 236, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 62837,
                    "incorrect value for header.num_msgs, expected 62837, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 63555,
                    "incorrect value for header.seq_num, expected 63555, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.time.tow, 2837573811,
                    "incorrect value for header.time.tow, expected 2837573811, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 8940,
                    "incorrect value for header.time.wn, expected 8940, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.tropo_quality_indicator, 230,
                    "incorrect value for header.tropo_quality_indicator, expected 230, is {}",
                    msg.header.tropo_quality_indicator
                );
                assert_eq!(
                    msg.header.update_interval, 233,
                    "incorrect value for header.update_interval, expected 233, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.index, 26598,
                    "incorrect value for index, expected 26598, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.stec_residuals[0].residual, -23949,
                    "incorrect value for stec_residuals[0].residual, expected -23949, is {}",
                    msg.stec_residuals[0].residual
                );
                assert_eq!(msg.stec_residuals[0].sv_id.constellation, 157, "incorrect value for stec_residuals[0].sv_id.constellation, expected 157, is {}", msg.stec_residuals[0].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[0].sv_id.sat_id, 231,
                    "incorrect value for stec_residuals[0].sv_id.sat_id, expected 231, is {}",
                    msg.stec_residuals[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[1].residual, 27427,
                    "incorrect value for stec_residuals[1].residual, expected 27427, is {}",
                    msg.stec_residuals[1].residual
                );
                assert_eq!(msg.stec_residuals[1].sv_id.constellation, 146, "incorrect value for stec_residuals[1].sv_id.constellation, expected 146, is {}", msg.stec_residuals[1].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[1].sv_id.sat_id, 197,
                    "incorrect value for stec_residuals[1].sv_id.sat_id, expected 197, is {}",
                    msg.stec_residuals[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[2].residual, 10548,
                    "incorrect value for stec_residuals[2].residual, expected 10548, is {}",
                    msg.stec_residuals[2].residual
                );
                assert_eq!(msg.stec_residuals[2].sv_id.constellation, 109, "incorrect value for stec_residuals[2].sv_id.constellation, expected 109, is {}", msg.stec_residuals[2].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[2].sv_id.sat_id, 222,
                    "incorrect value for stec_residuals[2].sv_id.sat_id, expected 222, is {}",
                    msg.stec_residuals[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[3].residual, -18195,
                    "incorrect value for stec_residuals[3].residual, expected -18195, is {}",
                    msg.stec_residuals[3].residual
                );
                assert_eq!(
                    msg.stec_residuals[3].sv_id.constellation, 12,
                    "incorrect value for stec_residuals[3].sv_id.constellation, expected 12, is {}",
                    msg.stec_residuals[3].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[3].sv_id.sat_id, 86,
                    "incorrect value for stec_residuals[3].sv_id.sat_id, expected 86, is {}",
                    msg.stec_residuals[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[4].residual, -27511,
                    "incorrect value for stec_residuals[4].residual, expected -27511, is {}",
                    msg.stec_residuals[4].residual
                );
                assert_eq!(msg.stec_residuals[4].sv_id.constellation, 204, "incorrect value for stec_residuals[4].sv_id.constellation, expected 204, is {}", msg.stec_residuals[4].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[4].sv_id.sat_id, 65,
                    "incorrect value for stec_residuals[4].sv_id.sat_id, expected 65, is {}",
                    msg.stec_residuals[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[5].residual, 11,
                    "incorrect value for stec_residuals[5].residual, expected 11, is {}",
                    msg.stec_residuals[5].residual
                );
                assert_eq!(msg.stec_residuals[5].sv_id.constellation, 183, "incorrect value for stec_residuals[5].sv_id.constellation, expected 183, is {}", msg.stec_residuals[5].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[5].sv_id.sat_id, 171,
                    "incorrect value for stec_residuals[5].sv_id.sat_id, expected 171, is {}",
                    msg.stec_residuals[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[6].residual, 13740,
                    "incorrect value for stec_residuals[6].residual, expected 13740, is {}",
                    msg.stec_residuals[6].residual
                );
                assert_eq!(msg.stec_residuals[6].sv_id.constellation, 203, "incorrect value for stec_residuals[6].sv_id.constellation, expected 203, is {}", msg.stec_residuals[6].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[6].sv_id.sat_id, 180,
                    "incorrect value for stec_residuals[6].sv_id.sat_id, expected 180, is {}",
                    msg.stec_residuals[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[7].residual, 29626,
                    "incorrect value for stec_residuals[7].residual, expected 29626, is {}",
                    msg.stec_residuals[7].residual
                );
                assert_eq!(
                    msg.stec_residuals[7].sv_id.constellation, 85,
                    "incorrect value for stec_residuals[7].sv_id.constellation, expected 85, is {}",
                    msg.stec_residuals[7].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[7].sv_id.sat_id, 196,
                    "incorrect value for stec_residuals[7].sv_id.sat_id, expected 196, is {}",
                    msg.stec_residuals[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[8].residual, 7846,
                    "incorrect value for stec_residuals[8].residual, expected 7846, is {}",
                    msg.stec_residuals[8].residual
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.constellation, 92,
                    "incorrect value for stec_residuals[8].sv_id.constellation, expected 92, is {}",
                    msg.stec_residuals[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.sat_id, 203,
                    "incorrect value for stec_residuals[8].sv_id.sat_id, expected 203, is {}",
                    msg.stec_residuals[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[9].residual, 18376,
                    "incorrect value for stec_residuals[9].residual, expected 18376, is {}",
                    msg.stec_residuals[9].residual
                );
                assert_eq!(
                    msg.stec_residuals[9].sv_id.constellation, 13,
                    "incorrect value for stec_residuals[9].sv_id.constellation, expected 13, is {}",
                    msg.stec_residuals[9].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[9].sv_id.sat_id, 42,
                    "incorrect value for stec_residuals[9].sv_id.sat_id, expected 42, is {}",
                    msg.stec_residuals[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[10].residual, -24357,
                    "incorrect value for stec_residuals[10].residual, expected -24357, is {}",
                    msg.stec_residuals[10].residual
                );
                assert_eq!(msg.stec_residuals[10].sv_id.constellation, 137, "incorrect value for stec_residuals[10].sv_id.constellation, expected 137, is {}", msg.stec_residuals[10].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[10].sv_id.sat_id, 98,
                    "incorrect value for stec_residuals[10].sv_id.sat_id, expected 98, is {}",
                    msg.stec_residuals[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[11].residual, -1441,
                    "incorrect value for stec_residuals[11].residual, expected -1441, is {}",
                    msg.stec_residuals[11].residual
                );
                assert_eq!(msg.stec_residuals[11].sv_id.constellation, 216, "incorrect value for stec_residuals[11].sv_id.constellation, expected 216, is {}", msg.stec_residuals[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[11].sv_id.sat_id, 95,
                    "incorrect value for stec_residuals[11].sv_id.sat_id, expected 95, is {}",
                    msg.stec_residuals[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[12].residual, -10660,
                    "incorrect value for stec_residuals[12].residual, expected -10660, is {}",
                    msg.stec_residuals[12].residual
                );
                assert_eq!(msg.stec_residuals[12].sv_id.constellation, 196, "incorrect value for stec_residuals[12].sv_id.constellation, expected 196, is {}", msg.stec_residuals[12].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[12].sv_id.sat_id, 99,
                    "incorrect value for stec_residuals[12].sv_id.sat_id, expected 99, is {}",
                    msg.stec_residuals[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[13].residual, -8509,
                    "incorrect value for stec_residuals[13].residual, expected -8509, is {}",
                    msg.stec_residuals[13].residual
                );
                assert_eq!(msg.stec_residuals[13].sv_id.constellation, 253, "incorrect value for stec_residuals[13].sv_id.constellation, expected 253, is {}", msg.stec_residuals[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[13].sv_id.sat_id, 159,
                    "incorrect value for stec_residuals[13].sv_id.sat_id, expected 159, is {}",
                    msg.stec_residuals[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[14].residual, 16361,
                    "incorrect value for stec_residuals[14].residual, expected 16361, is {}",
                    msg.stec_residuals[14].residual
                );
                assert_eq!(msg.stec_residuals[14].sv_id.constellation, 146, "incorrect value for stec_residuals[14].sv_id.constellation, expected 146, is {}", msg.stec_residuals[14].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[14].sv_id.sat_id, 233,
                    "incorrect value for stec_residuals[14].sv_id.sat_id, expected 233, is {}",
                    msg.stec_residuals[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[15].residual, 10346,
                    "incorrect value for stec_residuals[15].residual, expected 10346, is {}",
                    msg.stec_residuals[15].residual
                );
                assert_eq!(msg.stec_residuals[15].sv_id.constellation, 24, "incorrect value for stec_residuals[15].sv_id.constellation, expected 24, is {}", msg.stec_residuals[15].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[15].sv_id.sat_id, 76,
                    "incorrect value for stec_residuals[15].sv_id.sat_id, expected 76, is {}",
                    msg.stec_residuals[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[16].residual, -18679,
                    "incorrect value for stec_residuals[16].residual, expected -18679, is {}",
                    msg.stec_residuals[16].residual
                );
                assert_eq!(msg.stec_residuals[16].sv_id.constellation, 65, "incorrect value for stec_residuals[16].sv_id.constellation, expected 65, is {}", msg.stec_residuals[16].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[16].sv_id.sat_id, 253,
                    "incorrect value for stec_residuals[16].sv_id.sat_id, expected 253, is {}",
                    msg.stec_residuals[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[17].residual, 15292,
                    "incorrect value for stec_residuals[17].residual, expected 15292, is {}",
                    msg.stec_residuals[17].residual
                );
                assert_eq!(msg.stec_residuals[17].sv_id.constellation, 215, "incorrect value for stec_residuals[17].sv_id.constellation, expected 215, is {}", msg.stec_residuals[17].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[17].sv_id.sat_id, 40,
                    "incorrect value for stec_residuals[17].sv_id.sat_id, expected 40, is {}",
                    msg.stec_residuals[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[18].residual, 29537,
                    "incorrect value for stec_residuals[18].residual, expected 29537, is {}",
                    msg.stec_residuals[18].residual
                );
                assert_eq!(msg.stec_residuals[18].sv_id.constellation, 69, "incorrect value for stec_residuals[18].sv_id.constellation, expected 69, is {}", msg.stec_residuals[18].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[18].sv_id.sat_id, 117,
                    "incorrect value for stec_residuals[18].sv_id.sat_id, expected 117, is {}",
                    msg.stec_residuals[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[19].residual, -29440,
                    "incorrect value for stec_residuals[19].residual, expected -29440, is {}",
                    msg.stec_residuals[19].residual
                );
                assert_eq!(msg.stec_residuals[19].sv_id.constellation, 56, "incorrect value for stec_residuals[19].sv_id.constellation, expected 56, is {}", msg.stec_residuals[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[19].sv_id.sat_id, 60,
                    "incorrect value for stec_residuals[19].sv_id.sat_id, expected 60, is {}",
                    msg.stec_residuals[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[20].residual, -24266,
                    "incorrect value for stec_residuals[20].residual, expected -24266, is {}",
                    msg.stec_residuals[20].residual
                );
                assert_eq!(msg.stec_residuals[20].sv_id.constellation, 171, "incorrect value for stec_residuals[20].sv_id.constellation, expected 171, is {}", msg.stec_residuals[20].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[20].sv_id.sat_id, 207,
                    "incorrect value for stec_residuals[20].sv_id.sat_id, expected 207, is {}",
                    msg.stec_residuals[20].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[21].residual, 22272,
                    "incorrect value for stec_residuals[21].residual, expected 22272, is {}",
                    msg.stec_residuals[21].residual
                );
                assert_eq!(msg.stec_residuals[21].sv_id.constellation, 61, "incorrect value for stec_residuals[21].sv_id.constellation, expected 61, is {}", msg.stec_residuals[21].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[21].sv_id.sat_id, 23,
                    "incorrect value for stec_residuals[21].sv_id.sat_id, expected 23, is {}",
                    msg.stec_residuals[21].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[22].residual, 9303,
                    "incorrect value for stec_residuals[22].residual, expected 9303, is {}",
                    msg.stec_residuals[22].residual
                );
                assert_eq!(msg.stec_residuals[22].sv_id.constellation, 123, "incorrect value for stec_residuals[22].sv_id.constellation, expected 123, is {}", msg.stec_residuals[22].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[22].sv_id.sat_id, 230,
                    "incorrect value for stec_residuals[22].sv_id.sat_id, expected 230, is {}",
                    msg.stec_residuals[22].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[23].residual, -23794,
                    "incorrect value for stec_residuals[23].residual, expected -23794, is {}",
                    msg.stec_residuals[23].residual
                );
                assert_eq!(msg.stec_residuals[23].sv_id.constellation, 255, "incorrect value for stec_residuals[23].sv_id.constellation, expected 255, is {}", msg.stec_residuals[23].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[23].sv_id.sat_id, 184,
                    "incorrect value for stec_residuals[23].sv_id.sat_id, expected 184, is {}",
                    msg.stec_residuals[23].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[24].residual, -26837,
                    "incorrect value for stec_residuals[24].residual, expected -26837, is {}",
                    msg.stec_residuals[24].residual
                );
                assert_eq!(msg.stec_residuals[24].sv_id.constellation, 224, "incorrect value for stec_residuals[24].sv_id.constellation, expected 224, is {}", msg.stec_residuals[24].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[24].sv_id.sat_id, 187,
                    "incorrect value for stec_residuals[24].sv_id.sat_id, expected 187, is {}",
                    msg.stec_residuals[24].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[25].residual, 14631,
                    "incorrect value for stec_residuals[25].residual, expected 14631, is {}",
                    msg.stec_residuals[25].residual
                );
                assert_eq!(msg.stec_residuals[25].sv_id.constellation, 104, "incorrect value for stec_residuals[25].sv_id.constellation, expected 104, is {}", msg.stec_residuals[25].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[25].sv_id.sat_id, 151,
                    "incorrect value for stec_residuals[25].sv_id.sat_id, expected 151, is {}",
                    msg.stec_residuals[25].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[26].residual, -8144,
                    "incorrect value for stec_residuals[26].residual, expected -8144, is {}",
                    msg.stec_residuals[26].residual
                );
                assert_eq!(msg.stec_residuals[26].sv_id.constellation, 54, "incorrect value for stec_residuals[26].sv_id.constellation, expected 54, is {}", msg.stec_residuals[26].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[26].sv_id.sat_id, 5,
                    "incorrect value for stec_residuals[26].sv_id.sat_id, expected 5, is {}",
                    msg.stec_residuals[26].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[27].residual, 23612,
                    "incorrect value for stec_residuals[27].residual, expected 23612, is {}",
                    msg.stec_residuals[27].residual
                );
                assert_eq!(msg.stec_residuals[27].sv_id.constellation, 129, "incorrect value for stec_residuals[27].sv_id.constellation, expected 129, is {}", msg.stec_residuals[27].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[27].sv_id.sat_id, 181,
                    "incorrect value for stec_residuals[27].sv_id.sat_id, expected 181, is {}",
                    msg.stec_residuals[27].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[28].residual, 28013,
                    "incorrect value for stec_residuals[28].residual, expected 28013, is {}",
                    msg.stec_residuals[28].residual
                );
                assert_eq!(msg.stec_residuals[28].sv_id.constellation, 114, "incorrect value for stec_residuals[28].sv_id.constellation, expected 114, is {}", msg.stec_residuals[28].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[28].sv_id.sat_id, 171,
                    "incorrect value for stec_residuals[28].sv_id.sat_id, expected 171, is {}",
                    msg.stec_residuals[28].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[29].residual, 2166,
                    "incorrect value for stec_residuals[29].residual, expected 2166, is {}",
                    msg.stec_residuals[29].residual
                );
                assert_eq!(msg.stec_residuals[29].sv_id.constellation, 23, "incorrect value for stec_residuals[29].sv_id.constellation, expected 23, is {}", msg.stec_residuals[29].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[29].sv_id.sat_id, 12,
                    "incorrect value for stec_residuals[29].sv_id.sat_id, expected 12, is {}",
                    msg.stec_residuals[29].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[30].residual, -10186,
                    "incorrect value for stec_residuals[30].residual, expected -10186, is {}",
                    msg.stec_residuals[30].residual
                );
                assert_eq!(msg.stec_residuals[30].sv_id.constellation, 159, "incorrect value for stec_residuals[30].sv_id.constellation, expected 159, is {}", msg.stec_residuals[30].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[30].sv_id.sat_id, 64,
                    "incorrect value for stec_residuals[30].sv_id.sat_id, expected 64, is {}",
                    msg.stec_residuals[30].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[31].residual, 17432,
                    "incorrect value for stec_residuals[31].residual, expected 17432, is {}",
                    msg.stec_residuals[31].residual
                );
                assert_eq!(msg.stec_residuals[31].sv_id.constellation, 20, "incorrect value for stec_residuals[31].sv_id.constellation, expected 20, is {}", msg.stec_residuals[31].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[31].sv_id.sat_id, 33,
                    "incorrect value for stec_residuals[31].sv_id.sat_id, expected 33, is {}",
                    msg.stec_residuals[31].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[32].residual, -8666,
                    "incorrect value for stec_residuals[32].residual, expected -8666, is {}",
                    msg.stec_residuals[32].residual
                );
                assert_eq!(msg.stec_residuals[32].sv_id.constellation, 36, "incorrect value for stec_residuals[32].sv_id.constellation, expected 36, is {}", msg.stec_residuals[32].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[32].sv_id.sat_id, 160,
                    "incorrect value for stec_residuals[32].sv_id.sat_id, expected 160, is {}",
                    msg.stec_residuals[32].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[33].residual, 25436,
                    "incorrect value for stec_residuals[33].residual, expected 25436, is {}",
                    msg.stec_residuals[33].residual
                );
                assert_eq!(msg.stec_residuals[33].sv_id.constellation, 190, "incorrect value for stec_residuals[33].sv_id.constellation, expected 190, is {}", msg.stec_residuals[33].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[33].sv_id.sat_id, 145,
                    "incorrect value for stec_residuals[33].sv_id.sat_id, expected 145, is {}",
                    msg.stec_residuals[33].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[34].residual, -3864,
                    "incorrect value for stec_residuals[34].residual, expected -3864, is {}",
                    msg.stec_residuals[34].residual
                );
                assert_eq!(msg.stec_residuals[34].sv_id.constellation, 159, "incorrect value for stec_residuals[34].sv_id.constellation, expected 159, is {}", msg.stec_residuals[34].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[34].sv_id.sat_id, 108,
                    "incorrect value for stec_residuals[34].sv_id.sat_id, expected 108, is {}",
                    msg.stec_residuals[34].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[35].residual, 4093,
                    "incorrect value for stec_residuals[35].residual, expected 4093, is {}",
                    msg.stec_residuals[35].residual
                );
                assert_eq!(msg.stec_residuals[35].sv_id.constellation, 221, "incorrect value for stec_residuals[35].sv_id.constellation, expected 221, is {}", msg.stec_residuals[35].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[35].sv_id.sat_id, 227,
                    "incorrect value for stec_residuals[35].sv_id.sat_id, expected 227, is {}",
                    msg.stec_residuals[35].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[36].residual, -18055,
                    "incorrect value for stec_residuals[36].residual, expected -18055, is {}",
                    msg.stec_residuals[36].residual
                );
                assert_eq!(msg.stec_residuals[36].sv_id.constellation, 23, "incorrect value for stec_residuals[36].sv_id.constellation, expected 23, is {}", msg.stec_residuals[36].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[36].sv_id.sat_id, 62,
                    "incorrect value for stec_residuals[36].sv_id.sat_id, expected 62, is {}",
                    msg.stec_residuals[36].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[37].residual, -27900,
                    "incorrect value for stec_residuals[37].residual, expected -27900, is {}",
                    msg.stec_residuals[37].residual
                );
                assert_eq!(msg.stec_residuals[37].sv_id.constellation, 116, "incorrect value for stec_residuals[37].sv_id.constellation, expected 116, is {}", msg.stec_residuals[37].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[37].sv_id.sat_id, 168,
                    "incorrect value for stec_residuals[37].sv_id.sat_id, expected 168, is {}",
                    msg.stec_residuals[37].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[38].residual, 30687,
                    "incorrect value for stec_residuals[38].residual, expected 30687, is {}",
                    msg.stec_residuals[38].residual
                );
                assert_eq!(msg.stec_residuals[38].sv_id.constellation, 72, "incorrect value for stec_residuals[38].sv_id.constellation, expected 72, is {}", msg.stec_residuals[38].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[38].sv_id.sat_id, 123,
                    "incorrect value for stec_residuals[38].sv_id.sat_id, expected 123, is {}",
                    msg.stec_residuals[38].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[39].residual, -13151,
                    "incorrect value for stec_residuals[39].residual, expected -13151, is {}",
                    msg.stec_residuals[39].residual
                );
                assert_eq!(msg.stec_residuals[39].sv_id.constellation, 242, "incorrect value for stec_residuals[39].sv_id.constellation, expected 242, is {}", msg.stec_residuals[39].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[39].sv_id.sat_id, 226,
                    "incorrect value for stec_residuals[39].sv_id.sat_id, expected 226, is {}",
                    msg.stec_residuals[39].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[40].residual, -22903,
                    "incorrect value for stec_residuals[40].residual, expected -22903, is {}",
                    msg.stec_residuals[40].residual
                );
                assert_eq!(msg.stec_residuals[40].sv_id.constellation, 202, "incorrect value for stec_residuals[40].sv_id.constellation, expected 202, is {}", msg.stec_residuals[40].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[40].sv_id.sat_id, 180,
                    "incorrect value for stec_residuals[40].sv_id.sat_id, expected 180, is {}",
                    msg.stec_residuals[40].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[41].residual, 4988,
                    "incorrect value for stec_residuals[41].residual, expected 4988, is {}",
                    msg.stec_residuals[41].residual
                );
                assert_eq!(msg.stec_residuals[41].sv_id.constellation, 24, "incorrect value for stec_residuals[41].sv_id.constellation, expected 24, is {}", msg.stec_residuals[41].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[41].sv_id.sat_id, 58,
                    "incorrect value for stec_residuals[41].sv_id.sat_id, expected 58, is {}",
                    msg.stec_residuals[41].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[42].residual, 27408,
                    "incorrect value for stec_residuals[42].residual, expected 27408, is {}",
                    msg.stec_residuals[42].residual
                );
                assert_eq!(msg.stec_residuals[42].sv_id.constellation, 188, "incorrect value for stec_residuals[42].sv_id.constellation, expected 188, is {}", msg.stec_residuals[42].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[42].sv_id.sat_id, 181,
                    "incorrect value for stec_residuals[42].sv_id.sat_id, expected 181, is {}",
                    msg.stec_residuals[42].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[43].residual, 319,
                    "incorrect value for stec_residuals[43].residual, expected 319, is {}",
                    msg.stec_residuals[43].residual
                );
                assert_eq!(msg.stec_residuals[43].sv_id.constellation, 231, "incorrect value for stec_residuals[43].sv_id.constellation, expected 231, is {}", msg.stec_residuals[43].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[43].sv_id.sat_id, 66,
                    "incorrect value for stec_residuals[43].sv_id.sat_id, expected 66, is {}",
                    msg.stec_residuals[43].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[44].residual, 15987,
                    "incorrect value for stec_residuals[44].residual, expected 15987, is {}",
                    msg.stec_residuals[44].residual
                );
                assert_eq!(msg.stec_residuals[44].sv_id.constellation, 252, "incorrect value for stec_residuals[44].sv_id.constellation, expected 252, is {}", msg.stec_residuals[44].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[44].sv_id.sat_id, 64,
                    "incorrect value for stec_residuals[44].sv_id.sat_id, expected 64, is {}",
                    msg.stec_residuals[44].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[45].residual, 22266,
                    "incorrect value for stec_residuals[45].residual, expected 22266, is {}",
                    msg.stec_residuals[45].residual
                );
                assert_eq!(msg.stec_residuals[45].sv_id.constellation, 97, "incorrect value for stec_residuals[45].sv_id.constellation, expected 97, is {}", msg.stec_residuals[45].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[45].sv_id.sat_id, 233,
                    "incorrect value for stec_residuals[45].sv_id.sat_id, expected 233, is {}",
                    msg.stec_residuals[45].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[46].residual, -19919,
                    "incorrect value for stec_residuals[46].residual, expected -19919, is {}",
                    msg.stec_residuals[46].residual
                );
                assert_eq!(msg.stec_residuals[46].sv_id.constellation, 221, "incorrect value for stec_residuals[46].sv_id.constellation, expected 221, is {}", msg.stec_residuals[46].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[46].sv_id.sat_id, 156,
                    "incorrect value for stec_residuals[46].sv_id.sat_id, expected 156, is {}",
                    msg.stec_residuals[46].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[47].residual, 17350,
                    "incorrect value for stec_residuals[47].residual, expected 17350, is {}",
                    msg.stec_residuals[47].residual
                );
                assert_eq!(msg.stec_residuals[47].sv_id.constellation, 73, "incorrect value for stec_residuals[47].sv_id.constellation, expected 73, is {}", msg.stec_residuals[47].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[47].sv_id.sat_id, 32,
                    "incorrect value for stec_residuals[47].sv_id.sat_id, expected 32, is {}",
                    msg.stec_residuals[47].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[48].residual, 14410,
                    "incorrect value for stec_residuals[48].residual, expected 14410, is {}",
                    msg.stec_residuals[48].residual
                );
                assert_eq!(msg.stec_residuals[48].sv_id.constellation, 253, "incorrect value for stec_residuals[48].sv_id.constellation, expected 253, is {}", msg.stec_residuals[48].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[48].sv_id.sat_id, 249,
                    "incorrect value for stec_residuals[48].sv_id.sat_id, expected 249, is {}",
                    msg.stec_residuals[48].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[49].residual, 23671,
                    "incorrect value for stec_residuals[49].residual, expected 23671, is {}",
                    msg.stec_residuals[49].residual
                );
                assert_eq!(msg.stec_residuals[49].sv_id.constellation, 165, "incorrect value for stec_residuals[49].sv_id.constellation, expected 165, is {}", msg.stec_residuals[49].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[49].sv_id.sat_id, 38,
                    "incorrect value for stec_residuals[49].sv_id.sat_id, expected 38, is {}",
                    msg.stec_residuals[49].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[50].residual, -31905,
                    "incorrect value for stec_residuals[50].residual, expected -31905, is {}",
                    msg.stec_residuals[50].residual
                );
                assert_eq!(msg.stec_residuals[50].sv_id.constellation, 44, "incorrect value for stec_residuals[50].sv_id.constellation, expected 44, is {}", msg.stec_residuals[50].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[50].sv_id.sat_id, 99,
                    "incorrect value for stec_residuals[50].sv_id.sat_id, expected 99, is {}",
                    msg.stec_residuals[50].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[51].residual, 14305,
                    "incorrect value for stec_residuals[51].residual, expected 14305, is {}",
                    msg.stec_residuals[51].residual
                );
                assert_eq!(msg.stec_residuals[51].sv_id.constellation, 192, "incorrect value for stec_residuals[51].sv_id.constellation, expected 192, is {}", msg.stec_residuals[51].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[51].sv_id.sat_id, 89,
                    "incorrect value for stec_residuals[51].sv_id.sat_id, expected 89, is {}",
                    msg.stec_residuals[51].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[52].residual, -12968,
                    "incorrect value for stec_residuals[52].residual, expected -12968, is {}",
                    msg.stec_residuals[52].residual
                );
                assert_eq!(msg.stec_residuals[52].sv_id.constellation, 171, "incorrect value for stec_residuals[52].sv_id.constellation, expected 171, is {}", msg.stec_residuals[52].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[52].sv_id.sat_id, 95,
                    "incorrect value for stec_residuals[52].sv_id.sat_id, expected 95, is {}",
                    msg.stec_residuals[52].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[53].residual, 21479,
                    "incorrect value for stec_residuals[53].residual, expected 21479, is {}",
                    msg.stec_residuals[53].residual
                );
                assert_eq!(msg.stec_residuals[53].sv_id.constellation, 116, "incorrect value for stec_residuals[53].sv_id.constellation, expected 116, is {}", msg.stec_residuals[53].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[53].sv_id.sat_id, 21,
                    "incorrect value for stec_residuals[53].sv_id.sat_id, expected 21, is {}",
                    msg.stec_residuals[53].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[54].residual, 28260,
                    "incorrect value for stec_residuals[54].residual, expected 28260, is {}",
                    msg.stec_residuals[54].residual
                );
                assert_eq!(msg.stec_residuals[54].sv_id.constellation, 71, "incorrect value for stec_residuals[54].sv_id.constellation, expected 71, is {}", msg.stec_residuals[54].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[54].sv_id.sat_id, 71,
                    "incorrect value for stec_residuals[54].sv_id.sat_id, expected 71, is {}",
                    msg.stec_residuals[54].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[55].residual, -11112,
                    "incorrect value for stec_residuals[55].residual, expected -11112, is {}",
                    msg.stec_residuals[55].residual
                );
                assert_eq!(msg.stec_residuals[55].sv_id.constellation, 254, "incorrect value for stec_residuals[55].sv_id.constellation, expected 254, is {}", msg.stec_residuals[55].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[55].sv_id.sat_id, 217,
                    "incorrect value for stec_residuals[55].sv_id.sat_id, expected 217, is {}",
                    msg.stec_residuals[55].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[56].residual, -25304,
                    "incorrect value for stec_residuals[56].residual, expected -25304, is {}",
                    msg.stec_residuals[56].residual
                );
                assert_eq!(
                    msg.stec_residuals[56].sv_id.constellation, 8,
                    "incorrect value for stec_residuals[56].sv_id.constellation, expected 8, is {}",
                    msg.stec_residuals[56].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[56].sv_id.sat_id, 18,
                    "incorrect value for stec_residuals[56].sv_id.sat_id, expected 18, is {}",
                    msg.stec_residuals[56].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[57].residual, -4024,
                    "incorrect value for stec_residuals[57].residual, expected -4024, is {}",
                    msg.stec_residuals[57].residual
                );
                assert_eq!(msg.stec_residuals[57].sv_id.constellation, 54, "incorrect value for stec_residuals[57].sv_id.constellation, expected 54, is {}", msg.stec_residuals[57].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[57].sv_id.sat_id, 244,
                    "incorrect value for stec_residuals[57].sv_id.sat_id, expected 244, is {}",
                    msg.stec_residuals[57].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[58].residual, -15505,
                    "incorrect value for stec_residuals[58].residual, expected -15505, is {}",
                    msg.stec_residuals[58].residual
                );
                assert_eq!(msg.stec_residuals[58].sv_id.constellation, 189, "incorrect value for stec_residuals[58].sv_id.constellation, expected 189, is {}", msg.stec_residuals[58].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[58].sv_id.sat_id, 231,
                    "incorrect value for stec_residuals[58].sv_id.sat_id, expected 231, is {}",
                    msg.stec_residuals[58].sv_id.sat_id
                );
                assert_eq!(
                    msg.tropo_delay_correction.hydro, 16250,
                    "incorrect value for tropo_delay_correction.hydro, expected 16250, is {}",
                    msg.tropo_delay_correction.hydro
                );
                assert_eq!(
                    msg.tropo_delay_correction.wet, 101,
                    "incorrect value for tropo_delay_correction.wet, expected 101, is {}",
                    msg.tropo_delay_correction.wet
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGriddedCorrectionNoStdDepA"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_gridded_correction_no_std_dep_a() {
    {
        let json_input = r#"{"crc":20941,"length":254,"msg_type":1520,"payload":"s/AhqewidfVD+Ons5uZnej9l551zosWSI2vebTQpVgztuEHMiZSrtwsAtMusNcRVunPLXKYeKg3IR2KJ26Bf2F/6Y8Rc1p/9w97pkuk/TBhqKP1BCbco17w7dUVhczw4AI3PqzahFz0AV+Z7VyS4/w6ju+Arl5doJzkFNjDgtYE8XKtybW0MF3YIQJ822CEUGESgJCbekb5cY2yf6PDj3f0PPhd5uah0BJN7SN934vKhzLTKiaY6GHwTtbwQa0LnPwFA/HM+6WH6VpzdMbIgScZD+f1KOCald1xjLF+DWcDhN1+rWM0VdOdTR0dkbtn+mNQSCCid9DZI8Oe9b8M=","preamble":85,"sender":7270,"header":{"time":{"tow":2837573811,"wn":8940},"num_msgs":62837,"seq_num":63555,"update_interval":233,"iod_atmo":236,"tropo_quality_indicator":230},"index":26598,"tropo_delay_correction":{"hydro":16250,"wet":101},"stec_residuals":[{"sv_id":{"satId":231,"constellation":157},"residual":-23949},{"sv_id":{"satId":197,"constellation":146},"residual":27427},{"sv_id":{"satId":222,"constellation":109},"residual":10548},{"sv_id":{"satId":86,"constellation":12},"residual":-18195},{"sv_id":{"satId":65,"constellation":204},"residual":-27511},{"sv_id":{"satId":171,"constellation":183},"residual":11},{"sv_id":{"satId":180,"constellation":203},"residual":13740},{"sv_id":{"satId":196,"constellation":85},"residual":29626},{"sv_id":{"satId":203,"constellation":92},"residual":7846},{"sv_id":{"satId":42,"constellation":13},"residual":18376},{"sv_id":{"satId":98,"constellation":137},"residual":-24357},{"sv_id":{"satId":95,"constellation":216},"residual":-1441},{"sv_id":{"satId":99,"constellation":196},"residual":-10660},{"sv_id":{"satId":159,"constellation":253},"residual":-8509},{"sv_id":{"satId":233,"constellation":146},"residual":16361},{"sv_id":{"satId":76,"constellation":24},"residual":10346},{"sv_id":{"satId":253,"constellation":65},"residual":-18679},{"sv_id":{"satId":40,"constellation":215},"residual":15292},{"sv_id":{"satId":117,"constellation":69},"residual":29537},{"sv_id":{"satId":60,"constellation":56},"residual":-29440},{"sv_id":{"satId":207,"constellation":171},"residual":-24266},{"sv_id":{"satId":23,"constellation":61},"residual":22272},{"sv_id":{"satId":230,"constellation":123},"residual":9303},{"sv_id":{"satId":184,"constellation":255},"residual":-23794},{"sv_id":{"satId":187,"constellation":224},"residual":-26837},{"sv_id":{"satId":151,"constellation":104},"residual":14631},{"sv_id":{"satId":5,"constellation":54},"residual":-8144},{"sv_id":{"satId":181,"constellation":129},"residual":23612},{"sv_id":{"satId":171,"constellation":114},"residual":28013},{"sv_id":{"satId":12,"constellation":23},"residual":2166},{"sv_id":{"satId":64,"constellation":159},"residual":-10186},{"sv_id":{"satId":33,"constellation":20},"residual":17432},{"sv_id":{"satId":160,"constellation":36},"residual":-8666},{"sv_id":{"satId":145,"constellation":190},"residual":25436},{"sv_id":{"satId":108,"constellation":159},"residual":-3864},{"sv_id":{"satId":227,"constellation":221},"residual":4093},{"sv_id":{"satId":62,"constellation":23},"residual":-18055},{"sv_id":{"satId":168,"constellation":116},"residual":-27900},{"sv_id":{"satId":123,"constellation":72},"residual":30687},{"sv_id":{"satId":226,"constellation":242},"residual":-13151},{"sv_id":{"satId":180,"constellation":202},"residual":-22903},{"sv_id":{"satId":58,"constellation":24},"residual":4988},{"sv_id":{"satId":181,"constellation":188},"residual":27408},{"sv_id":{"satId":66,"constellation":231},"residual":319},{"sv_id":{"satId":64,"constellation":252},"residual":15987},{"sv_id":{"satId":233,"constellation":97},"residual":22266},{"sv_id":{"satId":156,"constellation":221},"residual":-19919},{"sv_id":{"satId":32,"constellation":73},"residual":17350},{"sv_id":{"satId":249,"constellation":253},"residual":14410},{"sv_id":{"satId":38,"constellation":165},"residual":23671},{"sv_id":{"satId":99,"constellation":44},"residual":-31905},{"sv_id":{"satId":89,"constellation":192},"residual":14305},{"sv_id":{"satId":95,"constellation":171},"residual":-12968},{"sv_id":{"satId":21,"constellation":116},"residual":21479},{"sv_id":{"satId":71,"constellation":71},"residual":28260},{"sv_id":{"satId":217,"constellation":254},"residual":-11112},{"sv_id":{"satId":18,"constellation":8},"residual":-25304},{"sv_id":{"satId":244,"constellation":54},"residual":-4024},{"sv_id":{"satId":231,"constellation":189},"residual":-15505}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5f0,
                    "Incorrect message type, expected 0x5f0, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1c66,
                    "incorrect sender id, expected 0x1c66, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 236,
                    "incorrect value for header.iod_atmo, expected 236, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 62837,
                    "incorrect value for header.num_msgs, expected 62837, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 63555,
                    "incorrect value for header.seq_num, expected 63555, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.time.tow, 2837573811,
                    "incorrect value for header.time.tow, expected 2837573811, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 8940,
                    "incorrect value for header.time.wn, expected 8940, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.tropo_quality_indicator, 230,
                    "incorrect value for header.tropo_quality_indicator, expected 230, is {}",
                    msg.header.tropo_quality_indicator
                );
                assert_eq!(
                    msg.header.update_interval, 233,
                    "incorrect value for header.update_interval, expected 233, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.index, 26598,
                    "incorrect value for index, expected 26598, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.stec_residuals[0].residual, -23949,
                    "incorrect value for stec_residuals[0].residual, expected -23949, is {}",
                    msg.stec_residuals[0].residual
                );
                assert_eq!(msg.stec_residuals[0].sv_id.constellation, 157, "incorrect value for stec_residuals[0].sv_id.constellation, expected 157, is {}", msg.stec_residuals[0].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[0].sv_id.sat_id, 231,
                    "incorrect value for stec_residuals[0].sv_id.sat_id, expected 231, is {}",
                    msg.stec_residuals[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[1].residual, 27427,
                    "incorrect value for stec_residuals[1].residual, expected 27427, is {}",
                    msg.stec_residuals[1].residual
                );
                assert_eq!(msg.stec_residuals[1].sv_id.constellation, 146, "incorrect value for stec_residuals[1].sv_id.constellation, expected 146, is {}", msg.stec_residuals[1].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[1].sv_id.sat_id, 197,
                    "incorrect value for stec_residuals[1].sv_id.sat_id, expected 197, is {}",
                    msg.stec_residuals[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[2].residual, 10548,
                    "incorrect value for stec_residuals[2].residual, expected 10548, is {}",
                    msg.stec_residuals[2].residual
                );
                assert_eq!(msg.stec_residuals[2].sv_id.constellation, 109, "incorrect value for stec_residuals[2].sv_id.constellation, expected 109, is {}", msg.stec_residuals[2].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[2].sv_id.sat_id, 222,
                    "incorrect value for stec_residuals[2].sv_id.sat_id, expected 222, is {}",
                    msg.stec_residuals[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[3].residual, -18195,
                    "incorrect value for stec_residuals[3].residual, expected -18195, is {}",
                    msg.stec_residuals[3].residual
                );
                assert_eq!(
                    msg.stec_residuals[3].sv_id.constellation, 12,
                    "incorrect value for stec_residuals[3].sv_id.constellation, expected 12, is {}",
                    msg.stec_residuals[3].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[3].sv_id.sat_id, 86,
                    "incorrect value for stec_residuals[3].sv_id.sat_id, expected 86, is {}",
                    msg.stec_residuals[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[4].residual, -27511,
                    "incorrect value for stec_residuals[4].residual, expected -27511, is {}",
                    msg.stec_residuals[4].residual
                );
                assert_eq!(msg.stec_residuals[4].sv_id.constellation, 204, "incorrect value for stec_residuals[4].sv_id.constellation, expected 204, is {}", msg.stec_residuals[4].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[4].sv_id.sat_id, 65,
                    "incorrect value for stec_residuals[4].sv_id.sat_id, expected 65, is {}",
                    msg.stec_residuals[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[5].residual, 11,
                    "incorrect value for stec_residuals[5].residual, expected 11, is {}",
                    msg.stec_residuals[5].residual
                );
                assert_eq!(msg.stec_residuals[5].sv_id.constellation, 183, "incorrect value for stec_residuals[5].sv_id.constellation, expected 183, is {}", msg.stec_residuals[5].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[5].sv_id.sat_id, 171,
                    "incorrect value for stec_residuals[5].sv_id.sat_id, expected 171, is {}",
                    msg.stec_residuals[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[6].residual, 13740,
                    "incorrect value for stec_residuals[6].residual, expected 13740, is {}",
                    msg.stec_residuals[6].residual
                );
                assert_eq!(msg.stec_residuals[6].sv_id.constellation, 203, "incorrect value for stec_residuals[6].sv_id.constellation, expected 203, is {}", msg.stec_residuals[6].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[6].sv_id.sat_id, 180,
                    "incorrect value for stec_residuals[6].sv_id.sat_id, expected 180, is {}",
                    msg.stec_residuals[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[7].residual, 29626,
                    "incorrect value for stec_residuals[7].residual, expected 29626, is {}",
                    msg.stec_residuals[7].residual
                );
                assert_eq!(
                    msg.stec_residuals[7].sv_id.constellation, 85,
                    "incorrect value for stec_residuals[7].sv_id.constellation, expected 85, is {}",
                    msg.stec_residuals[7].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[7].sv_id.sat_id, 196,
                    "incorrect value for stec_residuals[7].sv_id.sat_id, expected 196, is {}",
                    msg.stec_residuals[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[8].residual, 7846,
                    "incorrect value for stec_residuals[8].residual, expected 7846, is {}",
                    msg.stec_residuals[8].residual
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.constellation, 92,
                    "incorrect value for stec_residuals[8].sv_id.constellation, expected 92, is {}",
                    msg.stec_residuals[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.sat_id, 203,
                    "incorrect value for stec_residuals[8].sv_id.sat_id, expected 203, is {}",
                    msg.stec_residuals[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[9].residual, 18376,
                    "incorrect value for stec_residuals[9].residual, expected 18376, is {}",
                    msg.stec_residuals[9].residual
                );
                assert_eq!(
                    msg.stec_residuals[9].sv_id.constellation, 13,
                    "incorrect value for stec_residuals[9].sv_id.constellation, expected 13, is {}",
                    msg.stec_residuals[9].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[9].sv_id.sat_id, 42,
                    "incorrect value for stec_residuals[9].sv_id.sat_id, expected 42, is {}",
                    msg.stec_residuals[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[10].residual, -24357,
                    "incorrect value for stec_residuals[10].residual, expected -24357, is {}",
                    msg.stec_residuals[10].residual
                );
                assert_eq!(msg.stec_residuals[10].sv_id.constellation, 137, "incorrect value for stec_residuals[10].sv_id.constellation, expected 137, is {}", msg.stec_residuals[10].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[10].sv_id.sat_id, 98,
                    "incorrect value for stec_residuals[10].sv_id.sat_id, expected 98, is {}",
                    msg.stec_residuals[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[11].residual, -1441,
                    "incorrect value for stec_residuals[11].residual, expected -1441, is {}",
                    msg.stec_residuals[11].residual
                );
                assert_eq!(msg.stec_residuals[11].sv_id.constellation, 216, "incorrect value for stec_residuals[11].sv_id.constellation, expected 216, is {}", msg.stec_residuals[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[11].sv_id.sat_id, 95,
                    "incorrect value for stec_residuals[11].sv_id.sat_id, expected 95, is {}",
                    msg.stec_residuals[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[12].residual, -10660,
                    "incorrect value for stec_residuals[12].residual, expected -10660, is {}",
                    msg.stec_residuals[12].residual
                );
                assert_eq!(msg.stec_residuals[12].sv_id.constellation, 196, "incorrect value for stec_residuals[12].sv_id.constellation, expected 196, is {}", msg.stec_residuals[12].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[12].sv_id.sat_id, 99,
                    "incorrect value for stec_residuals[12].sv_id.sat_id, expected 99, is {}",
                    msg.stec_residuals[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[13].residual, -8509,
                    "incorrect value for stec_residuals[13].residual, expected -8509, is {}",
                    msg.stec_residuals[13].residual
                );
                assert_eq!(msg.stec_residuals[13].sv_id.constellation, 253, "incorrect value for stec_residuals[13].sv_id.constellation, expected 253, is {}", msg.stec_residuals[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[13].sv_id.sat_id, 159,
                    "incorrect value for stec_residuals[13].sv_id.sat_id, expected 159, is {}",
                    msg.stec_residuals[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[14].residual, 16361,
                    "incorrect value for stec_residuals[14].residual, expected 16361, is {}",
                    msg.stec_residuals[14].residual
                );
                assert_eq!(msg.stec_residuals[14].sv_id.constellation, 146, "incorrect value for stec_residuals[14].sv_id.constellation, expected 146, is {}", msg.stec_residuals[14].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[14].sv_id.sat_id, 233,
                    "incorrect value for stec_residuals[14].sv_id.sat_id, expected 233, is {}",
                    msg.stec_residuals[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[15].residual, 10346,
                    "incorrect value for stec_residuals[15].residual, expected 10346, is {}",
                    msg.stec_residuals[15].residual
                );
                assert_eq!(msg.stec_residuals[15].sv_id.constellation, 24, "incorrect value for stec_residuals[15].sv_id.constellation, expected 24, is {}", msg.stec_residuals[15].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[15].sv_id.sat_id, 76,
                    "incorrect value for stec_residuals[15].sv_id.sat_id, expected 76, is {}",
                    msg.stec_residuals[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[16].residual, -18679,
                    "incorrect value for stec_residuals[16].residual, expected -18679, is {}",
                    msg.stec_residuals[16].residual
                );
                assert_eq!(msg.stec_residuals[16].sv_id.constellation, 65, "incorrect value for stec_residuals[16].sv_id.constellation, expected 65, is {}", msg.stec_residuals[16].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[16].sv_id.sat_id, 253,
                    "incorrect value for stec_residuals[16].sv_id.sat_id, expected 253, is {}",
                    msg.stec_residuals[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[17].residual, 15292,
                    "incorrect value for stec_residuals[17].residual, expected 15292, is {}",
                    msg.stec_residuals[17].residual
                );
                assert_eq!(msg.stec_residuals[17].sv_id.constellation, 215, "incorrect value for stec_residuals[17].sv_id.constellation, expected 215, is {}", msg.stec_residuals[17].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[17].sv_id.sat_id, 40,
                    "incorrect value for stec_residuals[17].sv_id.sat_id, expected 40, is {}",
                    msg.stec_residuals[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[18].residual, 29537,
                    "incorrect value for stec_residuals[18].residual, expected 29537, is {}",
                    msg.stec_residuals[18].residual
                );
                assert_eq!(msg.stec_residuals[18].sv_id.constellation, 69, "incorrect value for stec_residuals[18].sv_id.constellation, expected 69, is {}", msg.stec_residuals[18].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[18].sv_id.sat_id, 117,
                    "incorrect value for stec_residuals[18].sv_id.sat_id, expected 117, is {}",
                    msg.stec_residuals[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[19].residual, -29440,
                    "incorrect value for stec_residuals[19].residual, expected -29440, is {}",
                    msg.stec_residuals[19].residual
                );
                assert_eq!(msg.stec_residuals[19].sv_id.constellation, 56, "incorrect value for stec_residuals[19].sv_id.constellation, expected 56, is {}", msg.stec_residuals[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[19].sv_id.sat_id, 60,
                    "incorrect value for stec_residuals[19].sv_id.sat_id, expected 60, is {}",
                    msg.stec_residuals[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[20].residual, -24266,
                    "incorrect value for stec_residuals[20].residual, expected -24266, is {}",
                    msg.stec_residuals[20].residual
                );
                assert_eq!(msg.stec_residuals[20].sv_id.constellation, 171, "incorrect value for stec_residuals[20].sv_id.constellation, expected 171, is {}", msg.stec_residuals[20].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[20].sv_id.sat_id, 207,
                    "incorrect value for stec_residuals[20].sv_id.sat_id, expected 207, is {}",
                    msg.stec_residuals[20].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[21].residual, 22272,
                    "incorrect value for stec_residuals[21].residual, expected 22272, is {}",
                    msg.stec_residuals[21].residual
                );
                assert_eq!(msg.stec_residuals[21].sv_id.constellation, 61, "incorrect value for stec_residuals[21].sv_id.constellation, expected 61, is {}", msg.stec_residuals[21].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[21].sv_id.sat_id, 23,
                    "incorrect value for stec_residuals[21].sv_id.sat_id, expected 23, is {}",
                    msg.stec_residuals[21].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[22].residual, 9303,
                    "incorrect value for stec_residuals[22].residual, expected 9303, is {}",
                    msg.stec_residuals[22].residual
                );
                assert_eq!(msg.stec_residuals[22].sv_id.constellation, 123, "incorrect value for stec_residuals[22].sv_id.constellation, expected 123, is {}", msg.stec_residuals[22].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[22].sv_id.sat_id, 230,
                    "incorrect value for stec_residuals[22].sv_id.sat_id, expected 230, is {}",
                    msg.stec_residuals[22].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[23].residual, -23794,
                    "incorrect value for stec_residuals[23].residual, expected -23794, is {}",
                    msg.stec_residuals[23].residual
                );
                assert_eq!(msg.stec_residuals[23].sv_id.constellation, 255, "incorrect value for stec_residuals[23].sv_id.constellation, expected 255, is {}", msg.stec_residuals[23].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[23].sv_id.sat_id, 184,
                    "incorrect value for stec_residuals[23].sv_id.sat_id, expected 184, is {}",
                    msg.stec_residuals[23].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[24].residual, -26837,
                    "incorrect value for stec_residuals[24].residual, expected -26837, is {}",
                    msg.stec_residuals[24].residual
                );
                assert_eq!(msg.stec_residuals[24].sv_id.constellation, 224, "incorrect value for stec_residuals[24].sv_id.constellation, expected 224, is {}", msg.stec_residuals[24].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[24].sv_id.sat_id, 187,
                    "incorrect value for stec_residuals[24].sv_id.sat_id, expected 187, is {}",
                    msg.stec_residuals[24].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[25].residual, 14631,
                    "incorrect value for stec_residuals[25].residual, expected 14631, is {}",
                    msg.stec_residuals[25].residual
                );
                assert_eq!(msg.stec_residuals[25].sv_id.constellation, 104, "incorrect value for stec_residuals[25].sv_id.constellation, expected 104, is {}", msg.stec_residuals[25].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[25].sv_id.sat_id, 151,
                    "incorrect value for stec_residuals[25].sv_id.sat_id, expected 151, is {}",
                    msg.stec_residuals[25].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[26].residual, -8144,
                    "incorrect value for stec_residuals[26].residual, expected -8144, is {}",
                    msg.stec_residuals[26].residual
                );
                assert_eq!(msg.stec_residuals[26].sv_id.constellation, 54, "incorrect value for stec_residuals[26].sv_id.constellation, expected 54, is {}", msg.stec_residuals[26].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[26].sv_id.sat_id, 5,
                    "incorrect value for stec_residuals[26].sv_id.sat_id, expected 5, is {}",
                    msg.stec_residuals[26].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[27].residual, 23612,
                    "incorrect value for stec_residuals[27].residual, expected 23612, is {}",
                    msg.stec_residuals[27].residual
                );
                assert_eq!(msg.stec_residuals[27].sv_id.constellation, 129, "incorrect value for stec_residuals[27].sv_id.constellation, expected 129, is {}", msg.stec_residuals[27].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[27].sv_id.sat_id, 181,
                    "incorrect value for stec_residuals[27].sv_id.sat_id, expected 181, is {}",
                    msg.stec_residuals[27].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[28].residual, 28013,
                    "incorrect value for stec_residuals[28].residual, expected 28013, is {}",
                    msg.stec_residuals[28].residual
                );
                assert_eq!(msg.stec_residuals[28].sv_id.constellation, 114, "incorrect value for stec_residuals[28].sv_id.constellation, expected 114, is {}", msg.stec_residuals[28].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[28].sv_id.sat_id, 171,
                    "incorrect value for stec_residuals[28].sv_id.sat_id, expected 171, is {}",
                    msg.stec_residuals[28].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[29].residual, 2166,
                    "incorrect value for stec_residuals[29].residual, expected 2166, is {}",
                    msg.stec_residuals[29].residual
                );
                assert_eq!(msg.stec_residuals[29].sv_id.constellation, 23, "incorrect value for stec_residuals[29].sv_id.constellation, expected 23, is {}", msg.stec_residuals[29].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[29].sv_id.sat_id, 12,
                    "incorrect value for stec_residuals[29].sv_id.sat_id, expected 12, is {}",
                    msg.stec_residuals[29].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[30].residual, -10186,
                    "incorrect value for stec_residuals[30].residual, expected -10186, is {}",
                    msg.stec_residuals[30].residual
                );
                assert_eq!(msg.stec_residuals[30].sv_id.constellation, 159, "incorrect value for stec_residuals[30].sv_id.constellation, expected 159, is {}", msg.stec_residuals[30].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[30].sv_id.sat_id, 64,
                    "incorrect value for stec_residuals[30].sv_id.sat_id, expected 64, is {}",
                    msg.stec_residuals[30].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[31].residual, 17432,
                    "incorrect value for stec_residuals[31].residual, expected 17432, is {}",
                    msg.stec_residuals[31].residual
                );
                assert_eq!(msg.stec_residuals[31].sv_id.constellation, 20, "incorrect value for stec_residuals[31].sv_id.constellation, expected 20, is {}", msg.stec_residuals[31].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[31].sv_id.sat_id, 33,
                    "incorrect value for stec_residuals[31].sv_id.sat_id, expected 33, is {}",
                    msg.stec_residuals[31].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[32].residual, -8666,
                    "incorrect value for stec_residuals[32].residual, expected -8666, is {}",
                    msg.stec_residuals[32].residual
                );
                assert_eq!(msg.stec_residuals[32].sv_id.constellation, 36, "incorrect value for stec_residuals[32].sv_id.constellation, expected 36, is {}", msg.stec_residuals[32].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[32].sv_id.sat_id, 160,
                    "incorrect value for stec_residuals[32].sv_id.sat_id, expected 160, is {}",
                    msg.stec_residuals[32].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[33].residual, 25436,
                    "incorrect value for stec_residuals[33].residual, expected 25436, is {}",
                    msg.stec_residuals[33].residual
                );
                assert_eq!(msg.stec_residuals[33].sv_id.constellation, 190, "incorrect value for stec_residuals[33].sv_id.constellation, expected 190, is {}", msg.stec_residuals[33].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[33].sv_id.sat_id, 145,
                    "incorrect value for stec_residuals[33].sv_id.sat_id, expected 145, is {}",
                    msg.stec_residuals[33].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[34].residual, -3864,
                    "incorrect value for stec_residuals[34].residual, expected -3864, is {}",
                    msg.stec_residuals[34].residual
                );
                assert_eq!(msg.stec_residuals[34].sv_id.constellation, 159, "incorrect value for stec_residuals[34].sv_id.constellation, expected 159, is {}", msg.stec_residuals[34].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[34].sv_id.sat_id, 108,
                    "incorrect value for stec_residuals[34].sv_id.sat_id, expected 108, is {}",
                    msg.stec_residuals[34].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[35].residual, 4093,
                    "incorrect value for stec_residuals[35].residual, expected 4093, is {}",
                    msg.stec_residuals[35].residual
                );
                assert_eq!(msg.stec_residuals[35].sv_id.constellation, 221, "incorrect value for stec_residuals[35].sv_id.constellation, expected 221, is {}", msg.stec_residuals[35].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[35].sv_id.sat_id, 227,
                    "incorrect value for stec_residuals[35].sv_id.sat_id, expected 227, is {}",
                    msg.stec_residuals[35].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[36].residual, -18055,
                    "incorrect value for stec_residuals[36].residual, expected -18055, is {}",
                    msg.stec_residuals[36].residual
                );
                assert_eq!(msg.stec_residuals[36].sv_id.constellation, 23, "incorrect value for stec_residuals[36].sv_id.constellation, expected 23, is {}", msg.stec_residuals[36].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[36].sv_id.sat_id, 62,
                    "incorrect value for stec_residuals[36].sv_id.sat_id, expected 62, is {}",
                    msg.stec_residuals[36].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[37].residual, -27900,
                    "incorrect value for stec_residuals[37].residual, expected -27900, is {}",
                    msg.stec_residuals[37].residual
                );
                assert_eq!(msg.stec_residuals[37].sv_id.constellation, 116, "incorrect value for stec_residuals[37].sv_id.constellation, expected 116, is {}", msg.stec_residuals[37].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[37].sv_id.sat_id, 168,
                    "incorrect value for stec_residuals[37].sv_id.sat_id, expected 168, is {}",
                    msg.stec_residuals[37].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[38].residual, 30687,
                    "incorrect value for stec_residuals[38].residual, expected 30687, is {}",
                    msg.stec_residuals[38].residual
                );
                assert_eq!(msg.stec_residuals[38].sv_id.constellation, 72, "incorrect value for stec_residuals[38].sv_id.constellation, expected 72, is {}", msg.stec_residuals[38].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[38].sv_id.sat_id, 123,
                    "incorrect value for stec_residuals[38].sv_id.sat_id, expected 123, is {}",
                    msg.stec_residuals[38].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[39].residual, -13151,
                    "incorrect value for stec_residuals[39].residual, expected -13151, is {}",
                    msg.stec_residuals[39].residual
                );
                assert_eq!(msg.stec_residuals[39].sv_id.constellation, 242, "incorrect value for stec_residuals[39].sv_id.constellation, expected 242, is {}", msg.stec_residuals[39].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[39].sv_id.sat_id, 226,
                    "incorrect value for stec_residuals[39].sv_id.sat_id, expected 226, is {}",
                    msg.stec_residuals[39].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[40].residual, -22903,
                    "incorrect value for stec_residuals[40].residual, expected -22903, is {}",
                    msg.stec_residuals[40].residual
                );
                assert_eq!(msg.stec_residuals[40].sv_id.constellation, 202, "incorrect value for stec_residuals[40].sv_id.constellation, expected 202, is {}", msg.stec_residuals[40].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[40].sv_id.sat_id, 180,
                    "incorrect value for stec_residuals[40].sv_id.sat_id, expected 180, is {}",
                    msg.stec_residuals[40].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[41].residual, 4988,
                    "incorrect value for stec_residuals[41].residual, expected 4988, is {}",
                    msg.stec_residuals[41].residual
                );
                assert_eq!(msg.stec_residuals[41].sv_id.constellation, 24, "incorrect value for stec_residuals[41].sv_id.constellation, expected 24, is {}", msg.stec_residuals[41].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[41].sv_id.sat_id, 58,
                    "incorrect value for stec_residuals[41].sv_id.sat_id, expected 58, is {}",
                    msg.stec_residuals[41].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[42].residual, 27408,
                    "incorrect value for stec_residuals[42].residual, expected 27408, is {}",
                    msg.stec_residuals[42].residual
                );
                assert_eq!(msg.stec_residuals[42].sv_id.constellation, 188, "incorrect value for stec_residuals[42].sv_id.constellation, expected 188, is {}", msg.stec_residuals[42].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[42].sv_id.sat_id, 181,
                    "incorrect value for stec_residuals[42].sv_id.sat_id, expected 181, is {}",
                    msg.stec_residuals[42].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[43].residual, 319,
                    "incorrect value for stec_residuals[43].residual, expected 319, is {}",
                    msg.stec_residuals[43].residual
                );
                assert_eq!(msg.stec_residuals[43].sv_id.constellation, 231, "incorrect value for stec_residuals[43].sv_id.constellation, expected 231, is {}", msg.stec_residuals[43].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[43].sv_id.sat_id, 66,
                    "incorrect value for stec_residuals[43].sv_id.sat_id, expected 66, is {}",
                    msg.stec_residuals[43].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[44].residual, 15987,
                    "incorrect value for stec_residuals[44].residual, expected 15987, is {}",
                    msg.stec_residuals[44].residual
                );
                assert_eq!(msg.stec_residuals[44].sv_id.constellation, 252, "incorrect value for stec_residuals[44].sv_id.constellation, expected 252, is {}", msg.stec_residuals[44].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[44].sv_id.sat_id, 64,
                    "incorrect value for stec_residuals[44].sv_id.sat_id, expected 64, is {}",
                    msg.stec_residuals[44].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[45].residual, 22266,
                    "incorrect value for stec_residuals[45].residual, expected 22266, is {}",
                    msg.stec_residuals[45].residual
                );
                assert_eq!(msg.stec_residuals[45].sv_id.constellation, 97, "incorrect value for stec_residuals[45].sv_id.constellation, expected 97, is {}", msg.stec_residuals[45].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[45].sv_id.sat_id, 233,
                    "incorrect value for stec_residuals[45].sv_id.sat_id, expected 233, is {}",
                    msg.stec_residuals[45].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[46].residual, -19919,
                    "incorrect value for stec_residuals[46].residual, expected -19919, is {}",
                    msg.stec_residuals[46].residual
                );
                assert_eq!(msg.stec_residuals[46].sv_id.constellation, 221, "incorrect value for stec_residuals[46].sv_id.constellation, expected 221, is {}", msg.stec_residuals[46].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[46].sv_id.sat_id, 156,
                    "incorrect value for stec_residuals[46].sv_id.sat_id, expected 156, is {}",
                    msg.stec_residuals[46].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[47].residual, 17350,
                    "incorrect value for stec_residuals[47].residual, expected 17350, is {}",
                    msg.stec_residuals[47].residual
                );
                assert_eq!(msg.stec_residuals[47].sv_id.constellation, 73, "incorrect value for stec_residuals[47].sv_id.constellation, expected 73, is {}", msg.stec_residuals[47].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[47].sv_id.sat_id, 32,
                    "incorrect value for stec_residuals[47].sv_id.sat_id, expected 32, is {}",
                    msg.stec_residuals[47].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[48].residual, 14410,
                    "incorrect value for stec_residuals[48].residual, expected 14410, is {}",
                    msg.stec_residuals[48].residual
                );
                assert_eq!(msg.stec_residuals[48].sv_id.constellation, 253, "incorrect value for stec_residuals[48].sv_id.constellation, expected 253, is {}", msg.stec_residuals[48].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[48].sv_id.sat_id, 249,
                    "incorrect value for stec_residuals[48].sv_id.sat_id, expected 249, is {}",
                    msg.stec_residuals[48].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[49].residual, 23671,
                    "incorrect value for stec_residuals[49].residual, expected 23671, is {}",
                    msg.stec_residuals[49].residual
                );
                assert_eq!(msg.stec_residuals[49].sv_id.constellation, 165, "incorrect value for stec_residuals[49].sv_id.constellation, expected 165, is {}", msg.stec_residuals[49].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[49].sv_id.sat_id, 38,
                    "incorrect value for stec_residuals[49].sv_id.sat_id, expected 38, is {}",
                    msg.stec_residuals[49].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[50].residual, -31905,
                    "incorrect value for stec_residuals[50].residual, expected -31905, is {}",
                    msg.stec_residuals[50].residual
                );
                assert_eq!(msg.stec_residuals[50].sv_id.constellation, 44, "incorrect value for stec_residuals[50].sv_id.constellation, expected 44, is {}", msg.stec_residuals[50].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[50].sv_id.sat_id, 99,
                    "incorrect value for stec_residuals[50].sv_id.sat_id, expected 99, is {}",
                    msg.stec_residuals[50].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[51].residual, 14305,
                    "incorrect value for stec_residuals[51].residual, expected 14305, is {}",
                    msg.stec_residuals[51].residual
                );
                assert_eq!(msg.stec_residuals[51].sv_id.constellation, 192, "incorrect value for stec_residuals[51].sv_id.constellation, expected 192, is {}", msg.stec_residuals[51].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[51].sv_id.sat_id, 89,
                    "incorrect value for stec_residuals[51].sv_id.sat_id, expected 89, is {}",
                    msg.stec_residuals[51].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[52].residual, -12968,
                    "incorrect value for stec_residuals[52].residual, expected -12968, is {}",
                    msg.stec_residuals[52].residual
                );
                assert_eq!(msg.stec_residuals[52].sv_id.constellation, 171, "incorrect value for stec_residuals[52].sv_id.constellation, expected 171, is {}", msg.stec_residuals[52].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[52].sv_id.sat_id, 95,
                    "incorrect value for stec_residuals[52].sv_id.sat_id, expected 95, is {}",
                    msg.stec_residuals[52].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[53].residual, 21479,
                    "incorrect value for stec_residuals[53].residual, expected 21479, is {}",
                    msg.stec_residuals[53].residual
                );
                assert_eq!(msg.stec_residuals[53].sv_id.constellation, 116, "incorrect value for stec_residuals[53].sv_id.constellation, expected 116, is {}", msg.stec_residuals[53].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[53].sv_id.sat_id, 21,
                    "incorrect value for stec_residuals[53].sv_id.sat_id, expected 21, is {}",
                    msg.stec_residuals[53].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[54].residual, 28260,
                    "incorrect value for stec_residuals[54].residual, expected 28260, is {}",
                    msg.stec_residuals[54].residual
                );
                assert_eq!(msg.stec_residuals[54].sv_id.constellation, 71, "incorrect value for stec_residuals[54].sv_id.constellation, expected 71, is {}", msg.stec_residuals[54].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[54].sv_id.sat_id, 71,
                    "incorrect value for stec_residuals[54].sv_id.sat_id, expected 71, is {}",
                    msg.stec_residuals[54].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[55].residual, -11112,
                    "incorrect value for stec_residuals[55].residual, expected -11112, is {}",
                    msg.stec_residuals[55].residual
                );
                assert_eq!(msg.stec_residuals[55].sv_id.constellation, 254, "incorrect value for stec_residuals[55].sv_id.constellation, expected 254, is {}", msg.stec_residuals[55].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[55].sv_id.sat_id, 217,
                    "incorrect value for stec_residuals[55].sv_id.sat_id, expected 217, is {}",
                    msg.stec_residuals[55].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[56].residual, -25304,
                    "incorrect value for stec_residuals[56].residual, expected -25304, is {}",
                    msg.stec_residuals[56].residual
                );
                assert_eq!(
                    msg.stec_residuals[56].sv_id.constellation, 8,
                    "incorrect value for stec_residuals[56].sv_id.constellation, expected 8, is {}",
                    msg.stec_residuals[56].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[56].sv_id.sat_id, 18,
                    "incorrect value for stec_residuals[56].sv_id.sat_id, expected 18, is {}",
                    msg.stec_residuals[56].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[57].residual, -4024,
                    "incorrect value for stec_residuals[57].residual, expected -4024, is {}",
                    msg.stec_residuals[57].residual
                );
                assert_eq!(msg.stec_residuals[57].sv_id.constellation, 54, "incorrect value for stec_residuals[57].sv_id.constellation, expected 54, is {}", msg.stec_residuals[57].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[57].sv_id.sat_id, 244,
                    "incorrect value for stec_residuals[57].sv_id.sat_id, expected 244, is {}",
                    msg.stec_residuals[57].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[58].residual, -15505,
                    "incorrect value for stec_residuals[58].residual, expected -15505, is {}",
                    msg.stec_residuals[58].residual
                );
                assert_eq!(msg.stec_residuals[58].sv_id.constellation, 189, "incorrect value for stec_residuals[58].sv_id.constellation, expected 189, is {}", msg.stec_residuals[58].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[58].sv_id.sat_id, 231,
                    "incorrect value for stec_residuals[58].sv_id.sat_id, expected 231, is {}",
                    msg.stec_residuals[58].sv_id.sat_id
                );
                assert_eq!(
                    msg.tropo_delay_correction.hydro, 16250,
                    "incorrect value for tropo_delay_correction.hydro, expected 16250, is {}",
                    msg.tropo_delay_correction.hydro
                );
                assert_eq!(
                    msg.tropo_delay_correction.wet, 101,
                    "incorrect value for tropo_delay_correction.wet, expected 101, is {}",
                    msg.tropo_delay_correction.wet
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGriddedCorrectionNoStdDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_gridded_correction_no_std_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_gridded_correction_no_std_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 240, 5, 102, 28, 254, 179, 240, 33, 169, 236, 34, 117, 245, 67, 248, 233, 236, 230,
            230, 103, 122, 63, 101, 231, 157, 115, 162, 197, 146, 35, 107, 222, 109, 52, 41, 86,
            12, 237, 184, 65, 204, 137, 148, 171, 183, 11, 0, 180, 203, 172, 53, 196, 85, 186, 115,
            203, 92, 166, 30, 42, 13, 200, 71, 98, 137, 219, 160, 95, 216, 95, 250, 99, 196, 92,
            214, 159, 253, 195, 222, 233, 146, 233, 63, 76, 24, 106, 40, 253, 65, 9, 183, 40, 215,
            188, 59, 117, 69, 97, 115, 60, 56, 0, 141, 207, 171, 54, 161, 23, 61, 0, 87, 230, 123,
            87, 36, 184, 255, 14, 163, 187, 224, 43, 151, 151, 104, 39, 57, 5, 54, 48, 224, 181,
            129, 60, 92, 171, 114, 109, 109, 12, 23, 118, 8, 64, 159, 54, 216, 33, 20, 24, 68, 160,
            36, 38, 222, 145, 190, 92, 99, 108, 159, 232, 240, 227, 221, 253, 15, 62, 23, 121, 185,
            168, 116, 4, 147, 123, 72, 223, 119, 226, 242, 161, 204, 180, 202, 137, 166, 58, 24,
            124, 19, 181, 188, 16, 107, 66, 231, 63, 1, 64, 252, 115, 62, 233, 97, 250, 86, 156,
            221, 49, 178, 32, 73, 198, 67, 249, 253, 74, 56, 38, 165, 119, 92, 99, 44, 95, 131, 89,
            192, 225, 55, 95, 171, 88, 205, 21, 116, 231, 83, 71, 71, 100, 110, 217, 254, 152, 212,
            18, 8, 40, 157, 244, 54, 72, 240, 231, 189, 111, 195, 205, 81,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrGriddedCorrectionNoStdDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrGriddedCorrectionNoStdDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5f0,
                    "Incorrect message type, expected 0x5f0, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1c66,
                    "incorrect sender id, expected 0x1c66, is {sender_id}"
                );
                assert_eq!(
                    msg.header.iod_atmo, 236,
                    "incorrect value for header.iod_atmo, expected 236, is {}",
                    msg.header.iod_atmo
                );
                assert_eq!(
                    msg.header.num_msgs, 62837,
                    "incorrect value for header.num_msgs, expected 62837, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 63555,
                    "incorrect value for header.seq_num, expected 63555, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.time.tow, 2837573811,
                    "incorrect value for header.time.tow, expected 2837573811, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 8940,
                    "incorrect value for header.time.wn, expected 8940, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.tropo_quality_indicator, 230,
                    "incorrect value for header.tropo_quality_indicator, expected 230, is {}",
                    msg.header.tropo_quality_indicator
                );
                assert_eq!(
                    msg.header.update_interval, 233,
                    "incorrect value for header.update_interval, expected 233, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.index, 26598,
                    "incorrect value for index, expected 26598, is {}",
                    msg.index
                );
                assert_eq!(
                    msg.stec_residuals[0].residual, -23949,
                    "incorrect value for stec_residuals[0].residual, expected -23949, is {}",
                    msg.stec_residuals[0].residual
                );
                assert_eq!(msg.stec_residuals[0].sv_id.constellation, 157, "incorrect value for stec_residuals[0].sv_id.constellation, expected 157, is {}", msg.stec_residuals[0].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[0].sv_id.sat_id, 231,
                    "incorrect value for stec_residuals[0].sv_id.sat_id, expected 231, is {}",
                    msg.stec_residuals[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[1].residual, 27427,
                    "incorrect value for stec_residuals[1].residual, expected 27427, is {}",
                    msg.stec_residuals[1].residual
                );
                assert_eq!(msg.stec_residuals[1].sv_id.constellation, 146, "incorrect value for stec_residuals[1].sv_id.constellation, expected 146, is {}", msg.stec_residuals[1].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[1].sv_id.sat_id, 197,
                    "incorrect value for stec_residuals[1].sv_id.sat_id, expected 197, is {}",
                    msg.stec_residuals[1].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[2].residual, 10548,
                    "incorrect value for stec_residuals[2].residual, expected 10548, is {}",
                    msg.stec_residuals[2].residual
                );
                assert_eq!(msg.stec_residuals[2].sv_id.constellation, 109, "incorrect value for stec_residuals[2].sv_id.constellation, expected 109, is {}", msg.stec_residuals[2].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[2].sv_id.sat_id, 222,
                    "incorrect value for stec_residuals[2].sv_id.sat_id, expected 222, is {}",
                    msg.stec_residuals[2].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[3].residual, -18195,
                    "incorrect value for stec_residuals[3].residual, expected -18195, is {}",
                    msg.stec_residuals[3].residual
                );
                assert_eq!(
                    msg.stec_residuals[3].sv_id.constellation, 12,
                    "incorrect value for stec_residuals[3].sv_id.constellation, expected 12, is {}",
                    msg.stec_residuals[3].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[3].sv_id.sat_id, 86,
                    "incorrect value for stec_residuals[3].sv_id.sat_id, expected 86, is {}",
                    msg.stec_residuals[3].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[4].residual, -27511,
                    "incorrect value for stec_residuals[4].residual, expected -27511, is {}",
                    msg.stec_residuals[4].residual
                );
                assert_eq!(msg.stec_residuals[4].sv_id.constellation, 204, "incorrect value for stec_residuals[4].sv_id.constellation, expected 204, is {}", msg.stec_residuals[4].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[4].sv_id.sat_id, 65,
                    "incorrect value for stec_residuals[4].sv_id.sat_id, expected 65, is {}",
                    msg.stec_residuals[4].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[5].residual, 11,
                    "incorrect value for stec_residuals[5].residual, expected 11, is {}",
                    msg.stec_residuals[5].residual
                );
                assert_eq!(msg.stec_residuals[5].sv_id.constellation, 183, "incorrect value for stec_residuals[5].sv_id.constellation, expected 183, is {}", msg.stec_residuals[5].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[5].sv_id.sat_id, 171,
                    "incorrect value for stec_residuals[5].sv_id.sat_id, expected 171, is {}",
                    msg.stec_residuals[5].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[6].residual, 13740,
                    "incorrect value for stec_residuals[6].residual, expected 13740, is {}",
                    msg.stec_residuals[6].residual
                );
                assert_eq!(msg.stec_residuals[6].sv_id.constellation, 203, "incorrect value for stec_residuals[6].sv_id.constellation, expected 203, is {}", msg.stec_residuals[6].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[6].sv_id.sat_id, 180,
                    "incorrect value for stec_residuals[6].sv_id.sat_id, expected 180, is {}",
                    msg.stec_residuals[6].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[7].residual, 29626,
                    "incorrect value for stec_residuals[7].residual, expected 29626, is {}",
                    msg.stec_residuals[7].residual
                );
                assert_eq!(
                    msg.stec_residuals[7].sv_id.constellation, 85,
                    "incorrect value for stec_residuals[7].sv_id.constellation, expected 85, is {}",
                    msg.stec_residuals[7].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[7].sv_id.sat_id, 196,
                    "incorrect value for stec_residuals[7].sv_id.sat_id, expected 196, is {}",
                    msg.stec_residuals[7].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[8].residual, 7846,
                    "incorrect value for stec_residuals[8].residual, expected 7846, is {}",
                    msg.stec_residuals[8].residual
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.constellation, 92,
                    "incorrect value for stec_residuals[8].sv_id.constellation, expected 92, is {}",
                    msg.stec_residuals[8].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[8].sv_id.sat_id, 203,
                    "incorrect value for stec_residuals[8].sv_id.sat_id, expected 203, is {}",
                    msg.stec_residuals[8].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[9].residual, 18376,
                    "incorrect value for stec_residuals[9].residual, expected 18376, is {}",
                    msg.stec_residuals[9].residual
                );
                assert_eq!(
                    msg.stec_residuals[9].sv_id.constellation, 13,
                    "incorrect value for stec_residuals[9].sv_id.constellation, expected 13, is {}",
                    msg.stec_residuals[9].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[9].sv_id.sat_id, 42,
                    "incorrect value for stec_residuals[9].sv_id.sat_id, expected 42, is {}",
                    msg.stec_residuals[9].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[10].residual, -24357,
                    "incorrect value for stec_residuals[10].residual, expected -24357, is {}",
                    msg.stec_residuals[10].residual
                );
                assert_eq!(msg.stec_residuals[10].sv_id.constellation, 137, "incorrect value for stec_residuals[10].sv_id.constellation, expected 137, is {}", msg.stec_residuals[10].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[10].sv_id.sat_id, 98,
                    "incorrect value for stec_residuals[10].sv_id.sat_id, expected 98, is {}",
                    msg.stec_residuals[10].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[11].residual, -1441,
                    "incorrect value for stec_residuals[11].residual, expected -1441, is {}",
                    msg.stec_residuals[11].residual
                );
                assert_eq!(msg.stec_residuals[11].sv_id.constellation, 216, "incorrect value for stec_residuals[11].sv_id.constellation, expected 216, is {}", msg.stec_residuals[11].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[11].sv_id.sat_id, 95,
                    "incorrect value for stec_residuals[11].sv_id.sat_id, expected 95, is {}",
                    msg.stec_residuals[11].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[12].residual, -10660,
                    "incorrect value for stec_residuals[12].residual, expected -10660, is {}",
                    msg.stec_residuals[12].residual
                );
                assert_eq!(msg.stec_residuals[12].sv_id.constellation, 196, "incorrect value for stec_residuals[12].sv_id.constellation, expected 196, is {}", msg.stec_residuals[12].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[12].sv_id.sat_id, 99,
                    "incorrect value for stec_residuals[12].sv_id.sat_id, expected 99, is {}",
                    msg.stec_residuals[12].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[13].residual, -8509,
                    "incorrect value for stec_residuals[13].residual, expected -8509, is {}",
                    msg.stec_residuals[13].residual
                );
                assert_eq!(msg.stec_residuals[13].sv_id.constellation, 253, "incorrect value for stec_residuals[13].sv_id.constellation, expected 253, is {}", msg.stec_residuals[13].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[13].sv_id.sat_id, 159,
                    "incorrect value for stec_residuals[13].sv_id.sat_id, expected 159, is {}",
                    msg.stec_residuals[13].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[14].residual, 16361,
                    "incorrect value for stec_residuals[14].residual, expected 16361, is {}",
                    msg.stec_residuals[14].residual
                );
                assert_eq!(msg.stec_residuals[14].sv_id.constellation, 146, "incorrect value for stec_residuals[14].sv_id.constellation, expected 146, is {}", msg.stec_residuals[14].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[14].sv_id.sat_id, 233,
                    "incorrect value for stec_residuals[14].sv_id.sat_id, expected 233, is {}",
                    msg.stec_residuals[14].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[15].residual, 10346,
                    "incorrect value for stec_residuals[15].residual, expected 10346, is {}",
                    msg.stec_residuals[15].residual
                );
                assert_eq!(msg.stec_residuals[15].sv_id.constellation, 24, "incorrect value for stec_residuals[15].sv_id.constellation, expected 24, is {}", msg.stec_residuals[15].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[15].sv_id.sat_id, 76,
                    "incorrect value for stec_residuals[15].sv_id.sat_id, expected 76, is {}",
                    msg.stec_residuals[15].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[16].residual, -18679,
                    "incorrect value for stec_residuals[16].residual, expected -18679, is {}",
                    msg.stec_residuals[16].residual
                );
                assert_eq!(msg.stec_residuals[16].sv_id.constellation, 65, "incorrect value for stec_residuals[16].sv_id.constellation, expected 65, is {}", msg.stec_residuals[16].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[16].sv_id.sat_id, 253,
                    "incorrect value for stec_residuals[16].sv_id.sat_id, expected 253, is {}",
                    msg.stec_residuals[16].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[17].residual, 15292,
                    "incorrect value for stec_residuals[17].residual, expected 15292, is {}",
                    msg.stec_residuals[17].residual
                );
                assert_eq!(msg.stec_residuals[17].sv_id.constellation, 215, "incorrect value for stec_residuals[17].sv_id.constellation, expected 215, is {}", msg.stec_residuals[17].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[17].sv_id.sat_id, 40,
                    "incorrect value for stec_residuals[17].sv_id.sat_id, expected 40, is {}",
                    msg.stec_residuals[17].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[18].residual, 29537,
                    "incorrect value for stec_residuals[18].residual, expected 29537, is {}",
                    msg.stec_residuals[18].residual
                );
                assert_eq!(msg.stec_residuals[18].sv_id.constellation, 69, "incorrect value for stec_residuals[18].sv_id.constellation, expected 69, is {}", msg.stec_residuals[18].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[18].sv_id.sat_id, 117,
                    "incorrect value for stec_residuals[18].sv_id.sat_id, expected 117, is {}",
                    msg.stec_residuals[18].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[19].residual, -29440,
                    "incorrect value for stec_residuals[19].residual, expected -29440, is {}",
                    msg.stec_residuals[19].residual
                );
                assert_eq!(msg.stec_residuals[19].sv_id.constellation, 56, "incorrect value for stec_residuals[19].sv_id.constellation, expected 56, is {}", msg.stec_residuals[19].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[19].sv_id.sat_id, 60,
                    "incorrect value for stec_residuals[19].sv_id.sat_id, expected 60, is {}",
                    msg.stec_residuals[19].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[20].residual, -24266,
                    "incorrect value for stec_residuals[20].residual, expected -24266, is {}",
                    msg.stec_residuals[20].residual
                );
                assert_eq!(msg.stec_residuals[20].sv_id.constellation, 171, "incorrect value for stec_residuals[20].sv_id.constellation, expected 171, is {}", msg.stec_residuals[20].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[20].sv_id.sat_id, 207,
                    "incorrect value for stec_residuals[20].sv_id.sat_id, expected 207, is {}",
                    msg.stec_residuals[20].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[21].residual, 22272,
                    "incorrect value for stec_residuals[21].residual, expected 22272, is {}",
                    msg.stec_residuals[21].residual
                );
                assert_eq!(msg.stec_residuals[21].sv_id.constellation, 61, "incorrect value for stec_residuals[21].sv_id.constellation, expected 61, is {}", msg.stec_residuals[21].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[21].sv_id.sat_id, 23,
                    "incorrect value for stec_residuals[21].sv_id.sat_id, expected 23, is {}",
                    msg.stec_residuals[21].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[22].residual, 9303,
                    "incorrect value for stec_residuals[22].residual, expected 9303, is {}",
                    msg.stec_residuals[22].residual
                );
                assert_eq!(msg.stec_residuals[22].sv_id.constellation, 123, "incorrect value for stec_residuals[22].sv_id.constellation, expected 123, is {}", msg.stec_residuals[22].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[22].sv_id.sat_id, 230,
                    "incorrect value for stec_residuals[22].sv_id.sat_id, expected 230, is {}",
                    msg.stec_residuals[22].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[23].residual, -23794,
                    "incorrect value for stec_residuals[23].residual, expected -23794, is {}",
                    msg.stec_residuals[23].residual
                );
                assert_eq!(msg.stec_residuals[23].sv_id.constellation, 255, "incorrect value for stec_residuals[23].sv_id.constellation, expected 255, is {}", msg.stec_residuals[23].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[23].sv_id.sat_id, 184,
                    "incorrect value for stec_residuals[23].sv_id.sat_id, expected 184, is {}",
                    msg.stec_residuals[23].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[24].residual, -26837,
                    "incorrect value for stec_residuals[24].residual, expected -26837, is {}",
                    msg.stec_residuals[24].residual
                );
                assert_eq!(msg.stec_residuals[24].sv_id.constellation, 224, "incorrect value for stec_residuals[24].sv_id.constellation, expected 224, is {}", msg.stec_residuals[24].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[24].sv_id.sat_id, 187,
                    "incorrect value for stec_residuals[24].sv_id.sat_id, expected 187, is {}",
                    msg.stec_residuals[24].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[25].residual, 14631,
                    "incorrect value for stec_residuals[25].residual, expected 14631, is {}",
                    msg.stec_residuals[25].residual
                );
                assert_eq!(msg.stec_residuals[25].sv_id.constellation, 104, "incorrect value for stec_residuals[25].sv_id.constellation, expected 104, is {}", msg.stec_residuals[25].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[25].sv_id.sat_id, 151,
                    "incorrect value for stec_residuals[25].sv_id.sat_id, expected 151, is {}",
                    msg.stec_residuals[25].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[26].residual, -8144,
                    "incorrect value for stec_residuals[26].residual, expected -8144, is {}",
                    msg.stec_residuals[26].residual
                );
                assert_eq!(msg.stec_residuals[26].sv_id.constellation, 54, "incorrect value for stec_residuals[26].sv_id.constellation, expected 54, is {}", msg.stec_residuals[26].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[26].sv_id.sat_id, 5,
                    "incorrect value for stec_residuals[26].sv_id.sat_id, expected 5, is {}",
                    msg.stec_residuals[26].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[27].residual, 23612,
                    "incorrect value for stec_residuals[27].residual, expected 23612, is {}",
                    msg.stec_residuals[27].residual
                );
                assert_eq!(msg.stec_residuals[27].sv_id.constellation, 129, "incorrect value for stec_residuals[27].sv_id.constellation, expected 129, is {}", msg.stec_residuals[27].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[27].sv_id.sat_id, 181,
                    "incorrect value for stec_residuals[27].sv_id.sat_id, expected 181, is {}",
                    msg.stec_residuals[27].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[28].residual, 28013,
                    "incorrect value for stec_residuals[28].residual, expected 28013, is {}",
                    msg.stec_residuals[28].residual
                );
                assert_eq!(msg.stec_residuals[28].sv_id.constellation, 114, "incorrect value for stec_residuals[28].sv_id.constellation, expected 114, is {}", msg.stec_residuals[28].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[28].sv_id.sat_id, 171,
                    "incorrect value for stec_residuals[28].sv_id.sat_id, expected 171, is {}",
                    msg.stec_residuals[28].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[29].residual, 2166,
                    "incorrect value for stec_residuals[29].residual, expected 2166, is {}",
                    msg.stec_residuals[29].residual
                );
                assert_eq!(msg.stec_residuals[29].sv_id.constellation, 23, "incorrect value for stec_residuals[29].sv_id.constellation, expected 23, is {}", msg.stec_residuals[29].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[29].sv_id.sat_id, 12,
                    "incorrect value for stec_residuals[29].sv_id.sat_id, expected 12, is {}",
                    msg.stec_residuals[29].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[30].residual, -10186,
                    "incorrect value for stec_residuals[30].residual, expected -10186, is {}",
                    msg.stec_residuals[30].residual
                );
                assert_eq!(msg.stec_residuals[30].sv_id.constellation, 159, "incorrect value for stec_residuals[30].sv_id.constellation, expected 159, is {}", msg.stec_residuals[30].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[30].sv_id.sat_id, 64,
                    "incorrect value for stec_residuals[30].sv_id.sat_id, expected 64, is {}",
                    msg.stec_residuals[30].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[31].residual, 17432,
                    "incorrect value for stec_residuals[31].residual, expected 17432, is {}",
                    msg.stec_residuals[31].residual
                );
                assert_eq!(msg.stec_residuals[31].sv_id.constellation, 20, "incorrect value for stec_residuals[31].sv_id.constellation, expected 20, is {}", msg.stec_residuals[31].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[31].sv_id.sat_id, 33,
                    "incorrect value for stec_residuals[31].sv_id.sat_id, expected 33, is {}",
                    msg.stec_residuals[31].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[32].residual, -8666,
                    "incorrect value for stec_residuals[32].residual, expected -8666, is {}",
                    msg.stec_residuals[32].residual
                );
                assert_eq!(msg.stec_residuals[32].sv_id.constellation, 36, "incorrect value for stec_residuals[32].sv_id.constellation, expected 36, is {}", msg.stec_residuals[32].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[32].sv_id.sat_id, 160,
                    "incorrect value for stec_residuals[32].sv_id.sat_id, expected 160, is {}",
                    msg.stec_residuals[32].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[33].residual, 25436,
                    "incorrect value for stec_residuals[33].residual, expected 25436, is {}",
                    msg.stec_residuals[33].residual
                );
                assert_eq!(msg.stec_residuals[33].sv_id.constellation, 190, "incorrect value for stec_residuals[33].sv_id.constellation, expected 190, is {}", msg.stec_residuals[33].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[33].sv_id.sat_id, 145,
                    "incorrect value for stec_residuals[33].sv_id.sat_id, expected 145, is {}",
                    msg.stec_residuals[33].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[34].residual, -3864,
                    "incorrect value for stec_residuals[34].residual, expected -3864, is {}",
                    msg.stec_residuals[34].residual
                );
                assert_eq!(msg.stec_residuals[34].sv_id.constellation, 159, "incorrect value for stec_residuals[34].sv_id.constellation, expected 159, is {}", msg.stec_residuals[34].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[34].sv_id.sat_id, 108,
                    "incorrect value for stec_residuals[34].sv_id.sat_id, expected 108, is {}",
                    msg.stec_residuals[34].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[35].residual, 4093,
                    "incorrect value for stec_residuals[35].residual, expected 4093, is {}",
                    msg.stec_residuals[35].residual
                );
                assert_eq!(msg.stec_residuals[35].sv_id.constellation, 221, "incorrect value for stec_residuals[35].sv_id.constellation, expected 221, is {}", msg.stec_residuals[35].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[35].sv_id.sat_id, 227,
                    "incorrect value for stec_residuals[35].sv_id.sat_id, expected 227, is {}",
                    msg.stec_residuals[35].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[36].residual, -18055,
                    "incorrect value for stec_residuals[36].residual, expected -18055, is {}",
                    msg.stec_residuals[36].residual
                );
                assert_eq!(msg.stec_residuals[36].sv_id.constellation, 23, "incorrect value for stec_residuals[36].sv_id.constellation, expected 23, is {}", msg.stec_residuals[36].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[36].sv_id.sat_id, 62,
                    "incorrect value for stec_residuals[36].sv_id.sat_id, expected 62, is {}",
                    msg.stec_residuals[36].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[37].residual, -27900,
                    "incorrect value for stec_residuals[37].residual, expected -27900, is {}",
                    msg.stec_residuals[37].residual
                );
                assert_eq!(msg.stec_residuals[37].sv_id.constellation, 116, "incorrect value for stec_residuals[37].sv_id.constellation, expected 116, is {}", msg.stec_residuals[37].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[37].sv_id.sat_id, 168,
                    "incorrect value for stec_residuals[37].sv_id.sat_id, expected 168, is {}",
                    msg.stec_residuals[37].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[38].residual, 30687,
                    "incorrect value for stec_residuals[38].residual, expected 30687, is {}",
                    msg.stec_residuals[38].residual
                );
                assert_eq!(msg.stec_residuals[38].sv_id.constellation, 72, "incorrect value for stec_residuals[38].sv_id.constellation, expected 72, is {}", msg.stec_residuals[38].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[38].sv_id.sat_id, 123,
                    "incorrect value for stec_residuals[38].sv_id.sat_id, expected 123, is {}",
                    msg.stec_residuals[38].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[39].residual, -13151,
                    "incorrect value for stec_residuals[39].residual, expected -13151, is {}",
                    msg.stec_residuals[39].residual
                );
                assert_eq!(msg.stec_residuals[39].sv_id.constellation, 242, "incorrect value for stec_residuals[39].sv_id.constellation, expected 242, is {}", msg.stec_residuals[39].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[39].sv_id.sat_id, 226,
                    "incorrect value for stec_residuals[39].sv_id.sat_id, expected 226, is {}",
                    msg.stec_residuals[39].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[40].residual, -22903,
                    "incorrect value for stec_residuals[40].residual, expected -22903, is {}",
                    msg.stec_residuals[40].residual
                );
                assert_eq!(msg.stec_residuals[40].sv_id.constellation, 202, "incorrect value for stec_residuals[40].sv_id.constellation, expected 202, is {}", msg.stec_residuals[40].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[40].sv_id.sat_id, 180,
                    "incorrect value for stec_residuals[40].sv_id.sat_id, expected 180, is {}",
                    msg.stec_residuals[40].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[41].residual, 4988,
                    "incorrect value for stec_residuals[41].residual, expected 4988, is {}",
                    msg.stec_residuals[41].residual
                );
                assert_eq!(msg.stec_residuals[41].sv_id.constellation, 24, "incorrect value for stec_residuals[41].sv_id.constellation, expected 24, is {}", msg.stec_residuals[41].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[41].sv_id.sat_id, 58,
                    "incorrect value for stec_residuals[41].sv_id.sat_id, expected 58, is {}",
                    msg.stec_residuals[41].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[42].residual, 27408,
                    "incorrect value for stec_residuals[42].residual, expected 27408, is {}",
                    msg.stec_residuals[42].residual
                );
                assert_eq!(msg.stec_residuals[42].sv_id.constellation, 188, "incorrect value for stec_residuals[42].sv_id.constellation, expected 188, is {}", msg.stec_residuals[42].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[42].sv_id.sat_id, 181,
                    "incorrect value for stec_residuals[42].sv_id.sat_id, expected 181, is {}",
                    msg.stec_residuals[42].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[43].residual, 319,
                    "incorrect value for stec_residuals[43].residual, expected 319, is {}",
                    msg.stec_residuals[43].residual
                );
                assert_eq!(msg.stec_residuals[43].sv_id.constellation, 231, "incorrect value for stec_residuals[43].sv_id.constellation, expected 231, is {}", msg.stec_residuals[43].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[43].sv_id.sat_id, 66,
                    "incorrect value for stec_residuals[43].sv_id.sat_id, expected 66, is {}",
                    msg.stec_residuals[43].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[44].residual, 15987,
                    "incorrect value for stec_residuals[44].residual, expected 15987, is {}",
                    msg.stec_residuals[44].residual
                );
                assert_eq!(msg.stec_residuals[44].sv_id.constellation, 252, "incorrect value for stec_residuals[44].sv_id.constellation, expected 252, is {}", msg.stec_residuals[44].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[44].sv_id.sat_id, 64,
                    "incorrect value for stec_residuals[44].sv_id.sat_id, expected 64, is {}",
                    msg.stec_residuals[44].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[45].residual, 22266,
                    "incorrect value for stec_residuals[45].residual, expected 22266, is {}",
                    msg.stec_residuals[45].residual
                );
                assert_eq!(msg.stec_residuals[45].sv_id.constellation, 97, "incorrect value for stec_residuals[45].sv_id.constellation, expected 97, is {}", msg.stec_residuals[45].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[45].sv_id.sat_id, 233,
                    "incorrect value for stec_residuals[45].sv_id.sat_id, expected 233, is {}",
                    msg.stec_residuals[45].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[46].residual, -19919,
                    "incorrect value for stec_residuals[46].residual, expected -19919, is {}",
                    msg.stec_residuals[46].residual
                );
                assert_eq!(msg.stec_residuals[46].sv_id.constellation, 221, "incorrect value for stec_residuals[46].sv_id.constellation, expected 221, is {}", msg.stec_residuals[46].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[46].sv_id.sat_id, 156,
                    "incorrect value for stec_residuals[46].sv_id.sat_id, expected 156, is {}",
                    msg.stec_residuals[46].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[47].residual, 17350,
                    "incorrect value for stec_residuals[47].residual, expected 17350, is {}",
                    msg.stec_residuals[47].residual
                );
                assert_eq!(msg.stec_residuals[47].sv_id.constellation, 73, "incorrect value for stec_residuals[47].sv_id.constellation, expected 73, is {}", msg.stec_residuals[47].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[47].sv_id.sat_id, 32,
                    "incorrect value for stec_residuals[47].sv_id.sat_id, expected 32, is {}",
                    msg.stec_residuals[47].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[48].residual, 14410,
                    "incorrect value for stec_residuals[48].residual, expected 14410, is {}",
                    msg.stec_residuals[48].residual
                );
                assert_eq!(msg.stec_residuals[48].sv_id.constellation, 253, "incorrect value for stec_residuals[48].sv_id.constellation, expected 253, is {}", msg.stec_residuals[48].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[48].sv_id.sat_id, 249,
                    "incorrect value for stec_residuals[48].sv_id.sat_id, expected 249, is {}",
                    msg.stec_residuals[48].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[49].residual, 23671,
                    "incorrect value for stec_residuals[49].residual, expected 23671, is {}",
                    msg.stec_residuals[49].residual
                );
                assert_eq!(msg.stec_residuals[49].sv_id.constellation, 165, "incorrect value for stec_residuals[49].sv_id.constellation, expected 165, is {}", msg.stec_residuals[49].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[49].sv_id.sat_id, 38,
                    "incorrect value for stec_residuals[49].sv_id.sat_id, expected 38, is {}",
                    msg.stec_residuals[49].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[50].residual, -31905,
                    "incorrect value for stec_residuals[50].residual, expected -31905, is {}",
                    msg.stec_residuals[50].residual
                );
                assert_eq!(msg.stec_residuals[50].sv_id.constellation, 44, "incorrect value for stec_residuals[50].sv_id.constellation, expected 44, is {}", msg.stec_residuals[50].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[50].sv_id.sat_id, 99,
                    "incorrect value for stec_residuals[50].sv_id.sat_id, expected 99, is {}",
                    msg.stec_residuals[50].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[51].residual, 14305,
                    "incorrect value for stec_residuals[51].residual, expected 14305, is {}",
                    msg.stec_residuals[51].residual
                );
                assert_eq!(msg.stec_residuals[51].sv_id.constellation, 192, "incorrect value for stec_residuals[51].sv_id.constellation, expected 192, is {}", msg.stec_residuals[51].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[51].sv_id.sat_id, 89,
                    "incorrect value for stec_residuals[51].sv_id.sat_id, expected 89, is {}",
                    msg.stec_residuals[51].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[52].residual, -12968,
                    "incorrect value for stec_residuals[52].residual, expected -12968, is {}",
                    msg.stec_residuals[52].residual
                );
                assert_eq!(msg.stec_residuals[52].sv_id.constellation, 171, "incorrect value for stec_residuals[52].sv_id.constellation, expected 171, is {}", msg.stec_residuals[52].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[52].sv_id.sat_id, 95,
                    "incorrect value for stec_residuals[52].sv_id.sat_id, expected 95, is {}",
                    msg.stec_residuals[52].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[53].residual, 21479,
                    "incorrect value for stec_residuals[53].residual, expected 21479, is {}",
                    msg.stec_residuals[53].residual
                );
                assert_eq!(msg.stec_residuals[53].sv_id.constellation, 116, "incorrect value for stec_residuals[53].sv_id.constellation, expected 116, is {}", msg.stec_residuals[53].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[53].sv_id.sat_id, 21,
                    "incorrect value for stec_residuals[53].sv_id.sat_id, expected 21, is {}",
                    msg.stec_residuals[53].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[54].residual, 28260,
                    "incorrect value for stec_residuals[54].residual, expected 28260, is {}",
                    msg.stec_residuals[54].residual
                );
                assert_eq!(msg.stec_residuals[54].sv_id.constellation, 71, "incorrect value for stec_residuals[54].sv_id.constellation, expected 71, is {}", msg.stec_residuals[54].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[54].sv_id.sat_id, 71,
                    "incorrect value for stec_residuals[54].sv_id.sat_id, expected 71, is {}",
                    msg.stec_residuals[54].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[55].residual, -11112,
                    "incorrect value for stec_residuals[55].residual, expected -11112, is {}",
                    msg.stec_residuals[55].residual
                );
                assert_eq!(msg.stec_residuals[55].sv_id.constellation, 254, "incorrect value for stec_residuals[55].sv_id.constellation, expected 254, is {}", msg.stec_residuals[55].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[55].sv_id.sat_id, 217,
                    "incorrect value for stec_residuals[55].sv_id.sat_id, expected 217, is {}",
                    msg.stec_residuals[55].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[56].residual, -25304,
                    "incorrect value for stec_residuals[56].residual, expected -25304, is {}",
                    msg.stec_residuals[56].residual
                );
                assert_eq!(
                    msg.stec_residuals[56].sv_id.constellation, 8,
                    "incorrect value for stec_residuals[56].sv_id.constellation, expected 8, is {}",
                    msg.stec_residuals[56].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_residuals[56].sv_id.sat_id, 18,
                    "incorrect value for stec_residuals[56].sv_id.sat_id, expected 18, is {}",
                    msg.stec_residuals[56].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[57].residual, -4024,
                    "incorrect value for stec_residuals[57].residual, expected -4024, is {}",
                    msg.stec_residuals[57].residual
                );
                assert_eq!(msg.stec_residuals[57].sv_id.constellation, 54, "incorrect value for stec_residuals[57].sv_id.constellation, expected 54, is {}", msg.stec_residuals[57].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[57].sv_id.sat_id, 244,
                    "incorrect value for stec_residuals[57].sv_id.sat_id, expected 244, is {}",
                    msg.stec_residuals[57].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_residuals[58].residual, -15505,
                    "incorrect value for stec_residuals[58].residual, expected -15505, is {}",
                    msg.stec_residuals[58].residual
                );
                assert_eq!(msg.stec_residuals[58].sv_id.constellation, 189, "incorrect value for stec_residuals[58].sv_id.constellation, expected 189, is {}", msg.stec_residuals[58].sv_id.constellation);
                assert_eq!(
                    msg.stec_residuals[58].sv_id.sat_id, 231,
                    "incorrect value for stec_residuals[58].sv_id.sat_id, expected 231, is {}",
                    msg.stec_residuals[58].sv_id.sat_id
                );
                assert_eq!(
                    msg.tropo_delay_correction.hydro, 16250,
                    "incorrect value for tropo_delay_correction.hydro, expected 16250, is {}",
                    msg.tropo_delay_correction.hydro
                );
                assert_eq!(
                    msg.tropo_delay_correction.wet, 101,
                    "incorrect value for tropo_delay_correction.wet, expected 101, is {}",
                    msg.tropo_delay_correction.wet
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGriddedCorrectionNoStdDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
