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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDepB.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_tracking_msg_tracking_state_dep_b() {
    {
        let mut payload = Cursor::new(vec![
            85, 19, 0, 242, 241, 252, 115, 183, 227, 63, 68, 154, 1, 183, 69, 255, 175, 121, 43,
            222, 51, 67, 35, 69, 78, 240, 5, 53, 20, 51, 211, 54, 69, 153, 130, 237, 66, 155, 51,
            227, 71, 69, 53, 242, 136, 161, 190, 205, 188, 6, 70, 153, 125, 255, 142, 149, 154,
            217, 184, 69, 248, 102, 95, 31, 76, 154, 33, 169, 69, 131, 115, 141, 27, 12, 154, 225,
            200, 69, 208, 44, 147, 39, 23, 51, 3, 66, 69, 237, 159, 251, 49, 203, 51, 99, 102, 69,
            70, 214, 87, 128, 206, 154, 121, 186, 69, 14, 206, 111, 218, 19, 154, 121, 169, 69,
            216, 98, 209, 54, 2, 154, 25, 219, 67, 200, 133, 99, 7, 34, 102, 198, 232, 68, 155, 43,
            85, 135, 46, 154, 177, 170, 69, 155, 3, 83, 171, 201, 154, 241, 232, 69, 121, 43, 197,
            16, 19, 154, 241, 222, 69, 128, 245, 53, 63, 176, 51, 115, 66, 69, 36, 20, 61, 153, 51,
            154, 73, 134, 69, 46, 82, 116, 140, 22, 51, 147, 37, 69, 177, 67, 146, 96, 143, 205,
            76, 107, 68, 220, 51, 160, 201, 251, 102, 102, 192, 68, 168, 194, 2, 161, 220, 102,
            102, 180, 68, 69, 8, 9, 125, 178, 102, 70, 134, 68, 185, 20, 135, 186, 171, 51, 163, 4,
            69, 18, 124, 155, 85, 170, 205, 208, 13, 70, 57, 244, 206, 255, 186, 154, 105, 149, 69,
            165, 199, 93, 181, 175, 51, 67, 64, 69, 6, 28,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepB(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf1f2,
                    "incorrect sender id, expected 0xf1f2, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(5.85620019531250000e+03),
                    "incorrect value for states[0].cn0, expected 5.85620019531250000e+03, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 63,
                    "incorrect value for states[0].sid.code, expected 63, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 68,
                    "incorrect value for states[0].sid.reserved, expected 68, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 58295,
                    "incorrect value for states[0].sid.sat, expected 58295, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 115,
                    "incorrect value for states[0].state, expected 115, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(2.61219995117187500e+03),
                    "incorrect value for states[1].cn0, expected 2.61219995117187500e+03, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 43,
                    "incorrect value for states[1].sid.code, expected 43, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 222,
                    "incorrect value for states[1].sid.reserved, expected 222, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 31151,
                    "incorrect value for states[1].sid.sat, expected 31151, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 255,
                    "incorrect value for states[1].state, expected 255, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(2.92519995117187500e+03),
                    "incorrect value for states[2].cn0, expected 2.92519995117187500e+03, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 53,
                    "incorrect value for states[2].sid.code, expected 53, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 20,
                    "incorrect value for states[2].sid.reserved, expected 20, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 1520,
                    "incorrect value for states[2].sid.sat, expected 1520, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 78,
                    "incorrect value for states[2].state, expected 78, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.19819995117187500e+03),
                    "incorrect value for states[3].cn0, expected 3.19819995117187500e+03, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 66,
                    "incorrect value for states[3].sid.code, expected 66, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 155,
                    "incorrect value for states[3].sid.reserved, expected 155, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 60802,
                    "incorrect value for states[3].sid.sat, expected 60802, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 153,
                    "incorrect value for states[3].state, expected 153, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(8.62320019531250000e+03),
                    "incorrect value for states[4].cn0, expected 8.62320019531250000e+03, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 161,
                    "incorrect value for states[4].sid.code, expected 161, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 190,
                    "incorrect value for states[4].sid.reserved, expected 190, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 35058,
                    "incorrect value for states[4].sid.sat, expected 35058, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 53,
                    "incorrect value for states[4].state, expected 53, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(5.91520019531250000e+03),
                    "incorrect value for states[5].cn0, expected 5.91520019531250000e+03, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 142,
                    "incorrect value for states[5].sid.code, expected 142, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 149,
                    "incorrect value for states[5].sid.reserved, expected 149, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 65405,
                    "incorrect value for states[5].sid.sat, expected 65405, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 153,
                    "incorrect value for states[5].state, expected 153, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(5.41220019531250000e+03),
                    "incorrect value for states[6].cn0, expected 5.41220019531250000e+03, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 31,
                    "incorrect value for states[6].sid.code, expected 31, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 76,
                    "incorrect value for states[6].sid.reserved, expected 76, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 24422,
                    "incorrect value for states[6].sid.sat, expected 24422, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 248,
                    "incorrect value for states[6].state, expected 248, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(6.42820019531250000e+03),
                    "incorrect value for states[7].cn0, expected 6.42820019531250000e+03, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 27,
                    "incorrect value for states[7].sid.code, expected 27, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 12,
                    "incorrect value for states[7].sid.reserved, expected 12, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 36211,
                    "incorrect value for states[7].sid.sat, expected 36211, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 131,
                    "incorrect value for states[7].state, expected 131, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(3.10419995117187500e+03),
                    "incorrect value for states[8].cn0, expected 3.10419995117187500e+03, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 39,
                    "incorrect value for states[8].sid.code, expected 39, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 23,
                    "incorrect value for states[8].sid.reserved, expected 23, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 37676,
                    "incorrect value for states[8].sid.sat, expected 37676, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 208,
                    "incorrect value for states[8].state, expected 208, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(3.68619995117187500e+03),
                    "incorrect value for states[9].cn0, expected 3.68619995117187500e+03, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 49,
                    "incorrect value for states[9].sid.code, expected 49, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 203,
                    "incorrect value for states[9].sid.reserved, expected 203, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 64415,
                    "incorrect value for states[9].sid.sat, expected 64415, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 237,
                    "incorrect value for states[9].state, expected 237, is {}",
                    msg.states[9].state
                );
                assert!(
                    msg.states[10].cn0.almost_eq(5.96720019531250000e+03),
                    "incorrect value for states[10].cn0, expected 5.96720019531250000e+03, is {:e}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].sid.code, 128,
                    "incorrect value for states[10].sid.code, expected 128, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 206,
                    "incorrect value for states[10].sid.reserved, expected 206, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 22486,
                    "incorrect value for states[10].sid.sat, expected 22486, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 70,
                    "incorrect value for states[10].state, expected 70, is {}",
                    msg.states[10].state
                );
                assert!(
                    msg.states[11].cn0.almost_eq(5.42320019531250000e+03),
                    "incorrect value for states[11].cn0, expected 5.42320019531250000e+03, is {:e}",
                    msg.states[11].cn0
                );
                assert_eq!(
                    msg.states[11].sid.code, 218,
                    "incorrect value for states[11].sid.code, expected 218, is {}",
                    msg.states[11].sid.code
                );
                assert_eq!(
                    msg.states[11].sid.reserved, 19,
                    "incorrect value for states[11].sid.reserved, expected 19, is {}",
                    msg.states[11].sid.reserved
                );
                assert_eq!(
                    msg.states[11].sid.sat, 28622,
                    "incorrect value for states[11].sid.sat, expected 28622, is {}",
                    msg.states[11].sid.sat
                );
                assert_eq!(
                    msg.states[11].state, 14,
                    "incorrect value for states[11].state, expected 14, is {}",
                    msg.states[11].state
                );
                assert!(
                    msg.states[12].cn0.almost_eq(4.38200012207031250e+02),
                    "incorrect value for states[12].cn0, expected 4.38200012207031250e+02, is {:e}",
                    msg.states[12].cn0
                );
                assert_eq!(
                    msg.states[12].sid.code, 54,
                    "incorrect value for states[12].sid.code, expected 54, is {}",
                    msg.states[12].sid.code
                );
                assert_eq!(
                    msg.states[12].sid.reserved, 2,
                    "incorrect value for states[12].sid.reserved, expected 2, is {}",
                    msg.states[12].sid.reserved
                );
                assert_eq!(
                    msg.states[12].sid.sat, 53602,
                    "incorrect value for states[12].sid.sat, expected 53602, is {}",
                    msg.states[12].sid.sat
                );
                assert_eq!(
                    msg.states[12].state, 216,
                    "incorrect value for states[12].state, expected 216, is {}",
                    msg.states[12].state
                );
                assert!(
                    msg.states[13].cn0.almost_eq(1.86219995117187500e+03),
                    "incorrect value for states[13].cn0, expected 1.86219995117187500e+03, is {:e}",
                    msg.states[13].cn0
                );
                assert_eq!(
                    msg.states[13].sid.code, 7,
                    "incorrect value for states[13].sid.code, expected 7, is {}",
                    msg.states[13].sid.code
                );
                assert_eq!(
                    msg.states[13].sid.reserved, 34,
                    "incorrect value for states[13].sid.reserved, expected 34, is {}",
                    msg.states[13].sid.reserved
                );
                assert_eq!(
                    msg.states[13].sid.sat, 25477,
                    "incorrect value for states[13].sid.sat, expected 25477, is {}",
                    msg.states[13].sid.sat
                );
                assert_eq!(
                    msg.states[13].state, 200,
                    "incorrect value for states[13].state, expected 200, is {}",
                    msg.states[13].state
                );
                assert!(
                    msg.states[14].cn0.almost_eq(5.46220019531250000e+03),
                    "incorrect value for states[14].cn0, expected 5.46220019531250000e+03, is {:e}",
                    msg.states[14].cn0
                );
                assert_eq!(
                    msg.states[14].sid.code, 135,
                    "incorrect value for states[14].sid.code, expected 135, is {}",
                    msg.states[14].sid.code
                );
                assert_eq!(
                    msg.states[14].sid.reserved, 46,
                    "incorrect value for states[14].sid.reserved, expected 46, is {}",
                    msg.states[14].sid.reserved
                );
                assert_eq!(
                    msg.states[14].sid.sat, 21803,
                    "incorrect value for states[14].sid.sat, expected 21803, is {}",
                    msg.states[14].sid.sat
                );
                assert_eq!(
                    msg.states[14].state, 155,
                    "incorrect value for states[14].state, expected 155, is {}",
                    msg.states[14].state
                );
                assert!(
                    msg.states[15].cn0.almost_eq(7.45420019531250000e+03),
                    "incorrect value for states[15].cn0, expected 7.45420019531250000e+03, is {:e}",
                    msg.states[15].cn0
                );
                assert_eq!(
                    msg.states[15].sid.code, 171,
                    "incorrect value for states[15].sid.code, expected 171, is {}",
                    msg.states[15].sid.code
                );
                assert_eq!(
                    msg.states[15].sid.reserved, 201,
                    "incorrect value for states[15].sid.reserved, expected 201, is {}",
                    msg.states[15].sid.reserved
                );
                assert_eq!(
                    msg.states[15].sid.sat, 21251,
                    "incorrect value for states[15].sid.sat, expected 21251, is {}",
                    msg.states[15].sid.sat
                );
                assert_eq!(
                    msg.states[15].state, 155,
                    "incorrect value for states[15].state, expected 155, is {}",
                    msg.states[15].state
                );
                assert!(
                    msg.states[16].cn0.almost_eq(7.13420019531250000e+03),
                    "incorrect value for states[16].cn0, expected 7.13420019531250000e+03, is {:e}",
                    msg.states[16].cn0
                );
                assert_eq!(
                    msg.states[16].sid.code, 16,
                    "incorrect value for states[16].sid.code, expected 16, is {}",
                    msg.states[16].sid.code
                );
                assert_eq!(
                    msg.states[16].sid.reserved, 19,
                    "incorrect value for states[16].sid.reserved, expected 19, is {}",
                    msg.states[16].sid.reserved
                );
                assert_eq!(
                    msg.states[16].sid.sat, 50475,
                    "incorrect value for states[16].sid.sat, expected 50475, is {}",
                    msg.states[16].sid.sat
                );
                assert_eq!(
                    msg.states[16].state, 121,
                    "incorrect value for states[16].state, expected 121, is {}",
                    msg.states[16].state
                );
                assert!(
                    msg.states[17].cn0.almost_eq(3.11119995117187500e+03),
                    "incorrect value for states[17].cn0, expected 3.11119995117187500e+03, is {:e}",
                    msg.states[17].cn0
                );
                assert_eq!(
                    msg.states[17].sid.code, 63,
                    "incorrect value for states[17].sid.code, expected 63, is {}",
                    msg.states[17].sid.code
                );
                assert_eq!(
                    msg.states[17].sid.reserved, 176,
                    "incorrect value for states[17].sid.reserved, expected 176, is {}",
                    msg.states[17].sid.reserved
                );
                assert_eq!(
                    msg.states[17].sid.sat, 13813,
                    "incorrect value for states[17].sid.sat, expected 13813, is {}",
                    msg.states[17].sid.sat
                );
                assert_eq!(
                    msg.states[17].state, 128,
                    "incorrect value for states[17].state, expected 128, is {}",
                    msg.states[17].state
                );
                assert!(
                    msg.states[18].cn0.almost_eq(4.29720019531250000e+03),
                    "incorrect value for states[18].cn0, expected 4.29720019531250000e+03, is {:e}",
                    msg.states[18].cn0
                );
                assert_eq!(
                    msg.states[18].sid.code, 153,
                    "incorrect value for states[18].sid.code, expected 153, is {}",
                    msg.states[18].sid.code
                );
                assert_eq!(
                    msg.states[18].sid.reserved, 51,
                    "incorrect value for states[18].sid.reserved, expected 51, is {}",
                    msg.states[18].sid.reserved
                );
                assert_eq!(
                    msg.states[18].sid.sat, 15636,
                    "incorrect value for states[18].sid.sat, expected 15636, is {}",
                    msg.states[18].sid.sat
                );
                assert_eq!(
                    msg.states[18].state, 36,
                    "incorrect value for states[18].state, expected 36, is {}",
                    msg.states[18].state
                );
                assert!(
                    msg.states[19].cn0.almost_eq(2.64919995117187500e+03),
                    "incorrect value for states[19].cn0, expected 2.64919995117187500e+03, is {:e}",
                    msg.states[19].cn0
                );
                assert_eq!(
                    msg.states[19].sid.code, 140,
                    "incorrect value for states[19].sid.code, expected 140, is {}",
                    msg.states[19].sid.code
                );
                assert_eq!(
                    msg.states[19].sid.reserved, 22,
                    "incorrect value for states[19].sid.reserved, expected 22, is {}",
                    msg.states[19].sid.reserved
                );
                assert_eq!(
                    msg.states[19].sid.sat, 29778,
                    "incorrect value for states[19].sid.sat, expected 29778, is {}",
                    msg.states[19].sid.sat
                );
                assert_eq!(
                    msg.states[19].state, 46,
                    "incorrect value for states[19].state, expected 46, is {}",
                    msg.states[19].state
                );
                assert!(
                    msg.states[20].cn0.almost_eq(9.41200012207031250e+02),
                    "incorrect value for states[20].cn0, expected 9.41200012207031250e+02, is {:e}",
                    msg.states[20].cn0
                );
                assert_eq!(
                    msg.states[20].sid.code, 96,
                    "incorrect value for states[20].sid.code, expected 96, is {}",
                    msg.states[20].sid.code
                );
                assert_eq!(
                    msg.states[20].sid.reserved, 143,
                    "incorrect value for states[20].sid.reserved, expected 143, is {}",
                    msg.states[20].sid.reserved
                );
                assert_eq!(
                    msg.states[20].sid.sat, 37443,
                    "incorrect value for states[20].sid.sat, expected 37443, is {}",
                    msg.states[20].sid.sat
                );
                assert_eq!(
                    msg.states[20].state, 177,
                    "incorrect value for states[20].state, expected 177, is {}",
                    msg.states[20].state
                );
                assert!(
                    msg.states[21].cn0.almost_eq(1.53919995117187500e+03),
                    "incorrect value for states[21].cn0, expected 1.53919995117187500e+03, is {:e}",
                    msg.states[21].cn0
                );
                assert_eq!(
                    msg.states[21].sid.code, 201,
                    "incorrect value for states[21].sid.code, expected 201, is {}",
                    msg.states[21].sid.code
                );
                assert_eq!(
                    msg.states[21].sid.reserved, 251,
                    "incorrect value for states[21].sid.reserved, expected 251, is {}",
                    msg.states[21].sid.reserved
                );
                assert_eq!(
                    msg.states[21].sid.sat, 41011,
                    "incorrect value for states[21].sid.sat, expected 41011, is {}",
                    msg.states[21].sid.sat
                );
                assert_eq!(
                    msg.states[21].state, 220,
                    "incorrect value for states[21].state, expected 220, is {}",
                    msg.states[21].state
                );
                assert!(
                    msg.states[22].cn0.almost_eq(1.44319995117187500e+03),
                    "incorrect value for states[22].cn0, expected 1.44319995117187500e+03, is {:e}",
                    msg.states[22].cn0
                );
                assert_eq!(
                    msg.states[22].sid.code, 161,
                    "incorrect value for states[22].sid.code, expected 161, is {}",
                    msg.states[22].sid.code
                );
                assert_eq!(
                    msg.states[22].sid.reserved, 220,
                    "incorrect value for states[22].sid.reserved, expected 220, is {}",
                    msg.states[22].sid.reserved
                );
                assert_eq!(
                    msg.states[22].sid.sat, 706,
                    "incorrect value for states[22].sid.sat, expected 706, is {}",
                    msg.states[22].sid.sat
                );
                assert_eq!(
                    msg.states[22].state, 168,
                    "incorrect value for states[22].state, expected 168, is {}",
                    msg.states[22].state
                );
                assert!(
                    msg.states[23].cn0.almost_eq(1.07419995117187500e+03),
                    "incorrect value for states[23].cn0, expected 1.07419995117187500e+03, is {:e}",
                    msg.states[23].cn0
                );
                assert_eq!(
                    msg.states[23].sid.code, 125,
                    "incorrect value for states[23].sid.code, expected 125, is {}",
                    msg.states[23].sid.code
                );
                assert_eq!(
                    msg.states[23].sid.reserved, 178,
                    "incorrect value for states[23].sid.reserved, expected 178, is {}",
                    msg.states[23].sid.reserved
                );
                assert_eq!(
                    msg.states[23].sid.sat, 2312,
                    "incorrect value for states[23].sid.sat, expected 2312, is {}",
                    msg.states[23].sid.sat
                );
                assert_eq!(
                    msg.states[23].state, 69,
                    "incorrect value for states[23].state, expected 69, is {}",
                    msg.states[23].state
                );
                assert!(
                    msg.states[24].cn0.almost_eq(2.12219995117187500e+03),
                    "incorrect value for states[24].cn0, expected 2.12219995117187500e+03, is {:e}",
                    msg.states[24].cn0
                );
                assert_eq!(
                    msg.states[24].sid.code, 186,
                    "incorrect value for states[24].sid.code, expected 186, is {}",
                    msg.states[24].sid.code
                );
                assert_eq!(
                    msg.states[24].sid.reserved, 171,
                    "incorrect value for states[24].sid.reserved, expected 171, is {}",
                    msg.states[24].sid.reserved
                );
                assert_eq!(
                    msg.states[24].sid.sat, 34580,
                    "incorrect value for states[24].sid.sat, expected 34580, is {}",
                    msg.states[24].sid.sat
                );
                assert_eq!(
                    msg.states[24].state, 185,
                    "incorrect value for states[24].state, expected 185, is {}",
                    msg.states[24].state
                );
                assert!(
                    msg.states[25].cn0.almost_eq(9.07620019531250000e+03),
                    "incorrect value for states[25].cn0, expected 9.07620019531250000e+03, is {:e}",
                    msg.states[25].cn0
                );
                assert_eq!(
                    msg.states[25].sid.code, 85,
                    "incorrect value for states[25].sid.code, expected 85, is {}",
                    msg.states[25].sid.code
                );
                assert_eq!(
                    msg.states[25].sid.reserved, 170,
                    "incorrect value for states[25].sid.reserved, expected 170, is {}",
                    msg.states[25].sid.reserved
                );
                assert_eq!(
                    msg.states[25].sid.sat, 39804,
                    "incorrect value for states[25].sid.sat, expected 39804, is {}",
                    msg.states[25].sid.sat
                );
                assert_eq!(
                    msg.states[25].state, 18,
                    "incorrect value for states[25].state, expected 18, is {}",
                    msg.states[25].state
                );
                assert!(
                    msg.states[26].cn0.almost_eq(4.78120019531250000e+03),
                    "incorrect value for states[26].cn0, expected 4.78120019531250000e+03, is {:e}",
                    msg.states[26].cn0
                );
                assert_eq!(
                    msg.states[26].sid.code, 255,
                    "incorrect value for states[26].sid.code, expected 255, is {}",
                    msg.states[26].sid.code
                );
                assert_eq!(
                    msg.states[26].sid.reserved, 186,
                    "incorrect value for states[26].sid.reserved, expected 186, is {}",
                    msg.states[26].sid.reserved
                );
                assert_eq!(
                    msg.states[26].sid.sat, 52980,
                    "incorrect value for states[26].sid.sat, expected 52980, is {}",
                    msg.states[26].sid.sat
                );
                assert_eq!(
                    msg.states[26].state, 57,
                    "incorrect value for states[26].state, expected 57, is {}",
                    msg.states[26].state
                );
                assert!(
                    msg.states[27].cn0.almost_eq(3.07619995117187500e+03),
                    "incorrect value for states[27].cn0, expected 3.07619995117187500e+03, is {:e}",
                    msg.states[27].cn0
                );
                assert_eq!(
                    msg.states[27].sid.code, 181,
                    "incorrect value for states[27].sid.code, expected 181, is {}",
                    msg.states[27].sid.code
                );
                assert_eq!(
                    msg.states[27].sid.reserved, 175,
                    "incorrect value for states[27].sid.reserved, expected 175, is {}",
                    msg.states[27].sid.reserved
                );
                assert_eq!(
                    msg.states[27].sid.sat, 24007,
                    "incorrect value for states[27].sid.sat, expected 24007, is {}",
                    msg.states[27].sid.sat
                );
                assert_eq!(
                    msg.states[27].state, 165,
                    "incorrect value for states[27].state, expected 165, is {}",
                    msg.states[27].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
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
fn test_json2sbp_auto_check_sbp_tracking_msg_tracking_state_dep_b() {
    {
        let json_input = r#"{"preamble":85,"msg_type":19,"sender":61938,"length":252,"payload":"c7fjP0SaAbdF/695K94zQyNFTvAFNRQz0zZFmYLtQpsz40dFNfKIob7NvAZGmX3/jpWa2bhF+GZfH0yaIalFg3ONGwya4chF0CyTJxczA0JF7Z/7McszY2ZFRtZXgM6aebpFDs5v2hOaealF2GLRNgKaGdtDyIVjByJmxuhEmytVhy6asapFmwNTq8ma8ehFeSvFEBOa8d5FgPU1P7Azc0JFJBQ9mTOaSYZFLlJ0jBYzkyVFsUOSYI/NTGtE3DOgyftmZsBEqMICodxmZrRERQgJfbJmRoZEuRSHuqszowRFEnybVarN0A1GOfTO/7qaaZVFpcddta8zQ0BF","crc":7174,"states":[{"state":115,"sid":{"sat":58295,"code":63,"reserved":68},"cn0":5856.2001953125},{"state":255,"sid":{"sat":31151,"code":43,"reserved":222},"cn0":2612.199951171875},{"state":78,"sid":{"sat":1520,"code":53,"reserved":20},"cn0":2925.199951171875},{"state":153,"sid":{"sat":60802,"code":66,"reserved":155},"cn0":3198.199951171875},{"state":53,"sid":{"sat":35058,"code":161,"reserved":190},"cn0":8623.2001953125},{"state":153,"sid":{"sat":65405,"code":142,"reserved":149},"cn0":5915.2001953125},{"state":248,"sid":{"sat":24422,"code":31,"reserved":76},"cn0":5412.2001953125},{"state":131,"sid":{"sat":36211,"code":27,"reserved":12},"cn0":6428.2001953125},{"state":208,"sid":{"sat":37676,"code":39,"reserved":23},"cn0":3104.199951171875},{"state":237,"sid":{"sat":64415,"code":49,"reserved":203},"cn0":3686.199951171875},{"state":70,"sid":{"sat":22486,"code":128,"reserved":206},"cn0":5967.2001953125},{"state":14,"sid":{"sat":28622,"code":218,"reserved":19},"cn0":5423.2001953125},{"state":216,"sid":{"sat":53602,"code":54,"reserved":2},"cn0":438.20001220703125},{"state":200,"sid":{"sat":25477,"code":7,"reserved":34},"cn0":1862.199951171875},{"state":155,"sid":{"sat":21803,"code":135,"reserved":46},"cn0":5462.2001953125},{"state":155,"sid":{"sat":21251,"code":171,"reserved":201},"cn0":7454.2001953125},{"state":121,"sid":{"sat":50475,"code":16,"reserved":19},"cn0":7134.2001953125},{"state":128,"sid":{"sat":13813,"code":63,"reserved":176},"cn0":3111.199951171875},{"state":36,"sid":{"sat":15636,"code":153,"reserved":51},"cn0":4297.2001953125},{"state":46,"sid":{"sat":29778,"code":140,"reserved":22},"cn0":2649.199951171875},{"state":177,"sid":{"sat":37443,"code":96,"reserved":143},"cn0":941.2000122070312},{"state":220,"sid":{"sat":41011,"code":201,"reserved":251},"cn0":1539.199951171875},{"state":168,"sid":{"sat":706,"code":161,"reserved":220},"cn0":1443.199951171875},{"state":69,"sid":{"sat":2312,"code":125,"reserved":178},"cn0":1074.199951171875},{"state":185,"sid":{"sat":34580,"code":186,"reserved":171},"cn0":2122.199951171875},{"state":18,"sid":{"sat":39804,"code":85,"reserved":170},"cn0":9076.2001953125},{"state":57,"sid":{"sat":52980,"code":255,"reserved":186},"cn0":4781.2001953125},{"state":165,"sid":{"sat":24007,"code":181,"reserved":175},"cn0":3076.199951171875}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingStateDepB(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf1f2,
                    "incorrect sender id, expected 0xf1f2, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(5.85620019531250000e+03),
                    "incorrect value for states[0].cn0, expected 5.85620019531250000e+03, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 63,
                    "incorrect value for states[0].sid.code, expected 63, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 68,
                    "incorrect value for states[0].sid.reserved, expected 68, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 58295,
                    "incorrect value for states[0].sid.sat, expected 58295, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 115,
                    "incorrect value for states[0].state, expected 115, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(2.61219995117187500e+03),
                    "incorrect value for states[1].cn0, expected 2.61219995117187500e+03, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 43,
                    "incorrect value for states[1].sid.code, expected 43, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 222,
                    "incorrect value for states[1].sid.reserved, expected 222, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 31151,
                    "incorrect value for states[1].sid.sat, expected 31151, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 255,
                    "incorrect value for states[1].state, expected 255, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(2.92519995117187500e+03),
                    "incorrect value for states[2].cn0, expected 2.92519995117187500e+03, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 53,
                    "incorrect value for states[2].sid.code, expected 53, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 20,
                    "incorrect value for states[2].sid.reserved, expected 20, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 1520,
                    "incorrect value for states[2].sid.sat, expected 1520, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 78,
                    "incorrect value for states[2].state, expected 78, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.19819995117187500e+03),
                    "incorrect value for states[3].cn0, expected 3.19819995117187500e+03, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 66,
                    "incorrect value for states[3].sid.code, expected 66, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 155,
                    "incorrect value for states[3].sid.reserved, expected 155, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 60802,
                    "incorrect value for states[3].sid.sat, expected 60802, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 153,
                    "incorrect value for states[3].state, expected 153, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(8.62320019531250000e+03),
                    "incorrect value for states[4].cn0, expected 8.62320019531250000e+03, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 161,
                    "incorrect value for states[4].sid.code, expected 161, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 190,
                    "incorrect value for states[4].sid.reserved, expected 190, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 35058,
                    "incorrect value for states[4].sid.sat, expected 35058, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 53,
                    "incorrect value for states[4].state, expected 53, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(5.91520019531250000e+03),
                    "incorrect value for states[5].cn0, expected 5.91520019531250000e+03, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 142,
                    "incorrect value for states[5].sid.code, expected 142, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 149,
                    "incorrect value for states[5].sid.reserved, expected 149, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 65405,
                    "incorrect value for states[5].sid.sat, expected 65405, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 153,
                    "incorrect value for states[5].state, expected 153, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(5.41220019531250000e+03),
                    "incorrect value for states[6].cn0, expected 5.41220019531250000e+03, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 31,
                    "incorrect value for states[6].sid.code, expected 31, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 76,
                    "incorrect value for states[6].sid.reserved, expected 76, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 24422,
                    "incorrect value for states[6].sid.sat, expected 24422, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 248,
                    "incorrect value for states[6].state, expected 248, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(6.42820019531250000e+03),
                    "incorrect value for states[7].cn0, expected 6.42820019531250000e+03, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 27,
                    "incorrect value for states[7].sid.code, expected 27, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 12,
                    "incorrect value for states[7].sid.reserved, expected 12, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 36211,
                    "incorrect value for states[7].sid.sat, expected 36211, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 131,
                    "incorrect value for states[7].state, expected 131, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(3.10419995117187500e+03),
                    "incorrect value for states[8].cn0, expected 3.10419995117187500e+03, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 39,
                    "incorrect value for states[8].sid.code, expected 39, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 23,
                    "incorrect value for states[8].sid.reserved, expected 23, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 37676,
                    "incorrect value for states[8].sid.sat, expected 37676, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 208,
                    "incorrect value for states[8].state, expected 208, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(3.68619995117187500e+03),
                    "incorrect value for states[9].cn0, expected 3.68619995117187500e+03, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 49,
                    "incorrect value for states[9].sid.code, expected 49, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 203,
                    "incorrect value for states[9].sid.reserved, expected 203, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 64415,
                    "incorrect value for states[9].sid.sat, expected 64415, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 237,
                    "incorrect value for states[9].state, expected 237, is {}",
                    msg.states[9].state
                );
                assert!(
                    msg.states[10].cn0.almost_eq(5.96720019531250000e+03),
                    "incorrect value for states[10].cn0, expected 5.96720019531250000e+03, is {:e}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].sid.code, 128,
                    "incorrect value for states[10].sid.code, expected 128, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 206,
                    "incorrect value for states[10].sid.reserved, expected 206, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 22486,
                    "incorrect value for states[10].sid.sat, expected 22486, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 70,
                    "incorrect value for states[10].state, expected 70, is {}",
                    msg.states[10].state
                );
                assert!(
                    msg.states[11].cn0.almost_eq(5.42320019531250000e+03),
                    "incorrect value for states[11].cn0, expected 5.42320019531250000e+03, is {:e}",
                    msg.states[11].cn0
                );
                assert_eq!(
                    msg.states[11].sid.code, 218,
                    "incorrect value for states[11].sid.code, expected 218, is {}",
                    msg.states[11].sid.code
                );
                assert_eq!(
                    msg.states[11].sid.reserved, 19,
                    "incorrect value for states[11].sid.reserved, expected 19, is {}",
                    msg.states[11].sid.reserved
                );
                assert_eq!(
                    msg.states[11].sid.sat, 28622,
                    "incorrect value for states[11].sid.sat, expected 28622, is {}",
                    msg.states[11].sid.sat
                );
                assert_eq!(
                    msg.states[11].state, 14,
                    "incorrect value for states[11].state, expected 14, is {}",
                    msg.states[11].state
                );
                assert!(
                    msg.states[12].cn0.almost_eq(4.38200012207031250e+02),
                    "incorrect value for states[12].cn0, expected 4.38200012207031250e+02, is {:e}",
                    msg.states[12].cn0
                );
                assert_eq!(
                    msg.states[12].sid.code, 54,
                    "incorrect value for states[12].sid.code, expected 54, is {}",
                    msg.states[12].sid.code
                );
                assert_eq!(
                    msg.states[12].sid.reserved, 2,
                    "incorrect value for states[12].sid.reserved, expected 2, is {}",
                    msg.states[12].sid.reserved
                );
                assert_eq!(
                    msg.states[12].sid.sat, 53602,
                    "incorrect value for states[12].sid.sat, expected 53602, is {}",
                    msg.states[12].sid.sat
                );
                assert_eq!(
                    msg.states[12].state, 216,
                    "incorrect value for states[12].state, expected 216, is {}",
                    msg.states[12].state
                );
                assert!(
                    msg.states[13].cn0.almost_eq(1.86219995117187500e+03),
                    "incorrect value for states[13].cn0, expected 1.86219995117187500e+03, is {:e}",
                    msg.states[13].cn0
                );
                assert_eq!(
                    msg.states[13].sid.code, 7,
                    "incorrect value for states[13].sid.code, expected 7, is {}",
                    msg.states[13].sid.code
                );
                assert_eq!(
                    msg.states[13].sid.reserved, 34,
                    "incorrect value for states[13].sid.reserved, expected 34, is {}",
                    msg.states[13].sid.reserved
                );
                assert_eq!(
                    msg.states[13].sid.sat, 25477,
                    "incorrect value for states[13].sid.sat, expected 25477, is {}",
                    msg.states[13].sid.sat
                );
                assert_eq!(
                    msg.states[13].state, 200,
                    "incorrect value for states[13].state, expected 200, is {}",
                    msg.states[13].state
                );
                assert!(
                    msg.states[14].cn0.almost_eq(5.46220019531250000e+03),
                    "incorrect value for states[14].cn0, expected 5.46220019531250000e+03, is {:e}",
                    msg.states[14].cn0
                );
                assert_eq!(
                    msg.states[14].sid.code, 135,
                    "incorrect value for states[14].sid.code, expected 135, is {}",
                    msg.states[14].sid.code
                );
                assert_eq!(
                    msg.states[14].sid.reserved, 46,
                    "incorrect value for states[14].sid.reserved, expected 46, is {}",
                    msg.states[14].sid.reserved
                );
                assert_eq!(
                    msg.states[14].sid.sat, 21803,
                    "incorrect value for states[14].sid.sat, expected 21803, is {}",
                    msg.states[14].sid.sat
                );
                assert_eq!(
                    msg.states[14].state, 155,
                    "incorrect value for states[14].state, expected 155, is {}",
                    msg.states[14].state
                );
                assert!(
                    msg.states[15].cn0.almost_eq(7.45420019531250000e+03),
                    "incorrect value for states[15].cn0, expected 7.45420019531250000e+03, is {:e}",
                    msg.states[15].cn0
                );
                assert_eq!(
                    msg.states[15].sid.code, 171,
                    "incorrect value for states[15].sid.code, expected 171, is {}",
                    msg.states[15].sid.code
                );
                assert_eq!(
                    msg.states[15].sid.reserved, 201,
                    "incorrect value for states[15].sid.reserved, expected 201, is {}",
                    msg.states[15].sid.reserved
                );
                assert_eq!(
                    msg.states[15].sid.sat, 21251,
                    "incorrect value for states[15].sid.sat, expected 21251, is {}",
                    msg.states[15].sid.sat
                );
                assert_eq!(
                    msg.states[15].state, 155,
                    "incorrect value for states[15].state, expected 155, is {}",
                    msg.states[15].state
                );
                assert!(
                    msg.states[16].cn0.almost_eq(7.13420019531250000e+03),
                    "incorrect value for states[16].cn0, expected 7.13420019531250000e+03, is {:e}",
                    msg.states[16].cn0
                );
                assert_eq!(
                    msg.states[16].sid.code, 16,
                    "incorrect value for states[16].sid.code, expected 16, is {}",
                    msg.states[16].sid.code
                );
                assert_eq!(
                    msg.states[16].sid.reserved, 19,
                    "incorrect value for states[16].sid.reserved, expected 19, is {}",
                    msg.states[16].sid.reserved
                );
                assert_eq!(
                    msg.states[16].sid.sat, 50475,
                    "incorrect value for states[16].sid.sat, expected 50475, is {}",
                    msg.states[16].sid.sat
                );
                assert_eq!(
                    msg.states[16].state, 121,
                    "incorrect value for states[16].state, expected 121, is {}",
                    msg.states[16].state
                );
                assert!(
                    msg.states[17].cn0.almost_eq(3.11119995117187500e+03),
                    "incorrect value for states[17].cn0, expected 3.11119995117187500e+03, is {:e}",
                    msg.states[17].cn0
                );
                assert_eq!(
                    msg.states[17].sid.code, 63,
                    "incorrect value for states[17].sid.code, expected 63, is {}",
                    msg.states[17].sid.code
                );
                assert_eq!(
                    msg.states[17].sid.reserved, 176,
                    "incorrect value for states[17].sid.reserved, expected 176, is {}",
                    msg.states[17].sid.reserved
                );
                assert_eq!(
                    msg.states[17].sid.sat, 13813,
                    "incorrect value for states[17].sid.sat, expected 13813, is {}",
                    msg.states[17].sid.sat
                );
                assert_eq!(
                    msg.states[17].state, 128,
                    "incorrect value for states[17].state, expected 128, is {}",
                    msg.states[17].state
                );
                assert!(
                    msg.states[18].cn0.almost_eq(4.29720019531250000e+03),
                    "incorrect value for states[18].cn0, expected 4.29720019531250000e+03, is {:e}",
                    msg.states[18].cn0
                );
                assert_eq!(
                    msg.states[18].sid.code, 153,
                    "incorrect value for states[18].sid.code, expected 153, is {}",
                    msg.states[18].sid.code
                );
                assert_eq!(
                    msg.states[18].sid.reserved, 51,
                    "incorrect value for states[18].sid.reserved, expected 51, is {}",
                    msg.states[18].sid.reserved
                );
                assert_eq!(
                    msg.states[18].sid.sat, 15636,
                    "incorrect value for states[18].sid.sat, expected 15636, is {}",
                    msg.states[18].sid.sat
                );
                assert_eq!(
                    msg.states[18].state, 36,
                    "incorrect value for states[18].state, expected 36, is {}",
                    msg.states[18].state
                );
                assert!(
                    msg.states[19].cn0.almost_eq(2.64919995117187500e+03),
                    "incorrect value for states[19].cn0, expected 2.64919995117187500e+03, is {:e}",
                    msg.states[19].cn0
                );
                assert_eq!(
                    msg.states[19].sid.code, 140,
                    "incorrect value for states[19].sid.code, expected 140, is {}",
                    msg.states[19].sid.code
                );
                assert_eq!(
                    msg.states[19].sid.reserved, 22,
                    "incorrect value for states[19].sid.reserved, expected 22, is {}",
                    msg.states[19].sid.reserved
                );
                assert_eq!(
                    msg.states[19].sid.sat, 29778,
                    "incorrect value for states[19].sid.sat, expected 29778, is {}",
                    msg.states[19].sid.sat
                );
                assert_eq!(
                    msg.states[19].state, 46,
                    "incorrect value for states[19].state, expected 46, is {}",
                    msg.states[19].state
                );
                assert!(
                    msg.states[20].cn0.almost_eq(9.41200012207031250e+02),
                    "incorrect value for states[20].cn0, expected 9.41200012207031250e+02, is {:e}",
                    msg.states[20].cn0
                );
                assert_eq!(
                    msg.states[20].sid.code, 96,
                    "incorrect value for states[20].sid.code, expected 96, is {}",
                    msg.states[20].sid.code
                );
                assert_eq!(
                    msg.states[20].sid.reserved, 143,
                    "incorrect value for states[20].sid.reserved, expected 143, is {}",
                    msg.states[20].sid.reserved
                );
                assert_eq!(
                    msg.states[20].sid.sat, 37443,
                    "incorrect value for states[20].sid.sat, expected 37443, is {}",
                    msg.states[20].sid.sat
                );
                assert_eq!(
                    msg.states[20].state, 177,
                    "incorrect value for states[20].state, expected 177, is {}",
                    msg.states[20].state
                );
                assert!(
                    msg.states[21].cn0.almost_eq(1.53919995117187500e+03),
                    "incorrect value for states[21].cn0, expected 1.53919995117187500e+03, is {:e}",
                    msg.states[21].cn0
                );
                assert_eq!(
                    msg.states[21].sid.code, 201,
                    "incorrect value for states[21].sid.code, expected 201, is {}",
                    msg.states[21].sid.code
                );
                assert_eq!(
                    msg.states[21].sid.reserved, 251,
                    "incorrect value for states[21].sid.reserved, expected 251, is {}",
                    msg.states[21].sid.reserved
                );
                assert_eq!(
                    msg.states[21].sid.sat, 41011,
                    "incorrect value for states[21].sid.sat, expected 41011, is {}",
                    msg.states[21].sid.sat
                );
                assert_eq!(
                    msg.states[21].state, 220,
                    "incorrect value for states[21].state, expected 220, is {}",
                    msg.states[21].state
                );
                assert!(
                    msg.states[22].cn0.almost_eq(1.44319995117187500e+03),
                    "incorrect value for states[22].cn0, expected 1.44319995117187500e+03, is {:e}",
                    msg.states[22].cn0
                );
                assert_eq!(
                    msg.states[22].sid.code, 161,
                    "incorrect value for states[22].sid.code, expected 161, is {}",
                    msg.states[22].sid.code
                );
                assert_eq!(
                    msg.states[22].sid.reserved, 220,
                    "incorrect value for states[22].sid.reserved, expected 220, is {}",
                    msg.states[22].sid.reserved
                );
                assert_eq!(
                    msg.states[22].sid.sat, 706,
                    "incorrect value for states[22].sid.sat, expected 706, is {}",
                    msg.states[22].sid.sat
                );
                assert_eq!(
                    msg.states[22].state, 168,
                    "incorrect value for states[22].state, expected 168, is {}",
                    msg.states[22].state
                );
                assert!(
                    msg.states[23].cn0.almost_eq(1.07419995117187500e+03),
                    "incorrect value for states[23].cn0, expected 1.07419995117187500e+03, is {:e}",
                    msg.states[23].cn0
                );
                assert_eq!(
                    msg.states[23].sid.code, 125,
                    "incorrect value for states[23].sid.code, expected 125, is {}",
                    msg.states[23].sid.code
                );
                assert_eq!(
                    msg.states[23].sid.reserved, 178,
                    "incorrect value for states[23].sid.reserved, expected 178, is {}",
                    msg.states[23].sid.reserved
                );
                assert_eq!(
                    msg.states[23].sid.sat, 2312,
                    "incorrect value for states[23].sid.sat, expected 2312, is {}",
                    msg.states[23].sid.sat
                );
                assert_eq!(
                    msg.states[23].state, 69,
                    "incorrect value for states[23].state, expected 69, is {}",
                    msg.states[23].state
                );
                assert!(
                    msg.states[24].cn0.almost_eq(2.12219995117187500e+03),
                    "incorrect value for states[24].cn0, expected 2.12219995117187500e+03, is {:e}",
                    msg.states[24].cn0
                );
                assert_eq!(
                    msg.states[24].sid.code, 186,
                    "incorrect value for states[24].sid.code, expected 186, is {}",
                    msg.states[24].sid.code
                );
                assert_eq!(
                    msg.states[24].sid.reserved, 171,
                    "incorrect value for states[24].sid.reserved, expected 171, is {}",
                    msg.states[24].sid.reserved
                );
                assert_eq!(
                    msg.states[24].sid.sat, 34580,
                    "incorrect value for states[24].sid.sat, expected 34580, is {}",
                    msg.states[24].sid.sat
                );
                assert_eq!(
                    msg.states[24].state, 185,
                    "incorrect value for states[24].state, expected 185, is {}",
                    msg.states[24].state
                );
                assert!(
                    msg.states[25].cn0.almost_eq(9.07620019531250000e+03),
                    "incorrect value for states[25].cn0, expected 9.07620019531250000e+03, is {:e}",
                    msg.states[25].cn0
                );
                assert_eq!(
                    msg.states[25].sid.code, 85,
                    "incorrect value for states[25].sid.code, expected 85, is {}",
                    msg.states[25].sid.code
                );
                assert_eq!(
                    msg.states[25].sid.reserved, 170,
                    "incorrect value for states[25].sid.reserved, expected 170, is {}",
                    msg.states[25].sid.reserved
                );
                assert_eq!(
                    msg.states[25].sid.sat, 39804,
                    "incorrect value for states[25].sid.sat, expected 39804, is {}",
                    msg.states[25].sid.sat
                );
                assert_eq!(
                    msg.states[25].state, 18,
                    "incorrect value for states[25].state, expected 18, is {}",
                    msg.states[25].state
                );
                assert!(
                    msg.states[26].cn0.almost_eq(4.78120019531250000e+03),
                    "incorrect value for states[26].cn0, expected 4.78120019531250000e+03, is {:e}",
                    msg.states[26].cn0
                );
                assert_eq!(
                    msg.states[26].sid.code, 255,
                    "incorrect value for states[26].sid.code, expected 255, is {}",
                    msg.states[26].sid.code
                );
                assert_eq!(
                    msg.states[26].sid.reserved, 186,
                    "incorrect value for states[26].sid.reserved, expected 186, is {}",
                    msg.states[26].sid.reserved
                );
                assert_eq!(
                    msg.states[26].sid.sat, 52980,
                    "incorrect value for states[26].sid.sat, expected 52980, is {}",
                    msg.states[26].sid.sat
                );
                assert_eq!(
                    msg.states[26].state, 57,
                    "incorrect value for states[26].state, expected 57, is {}",
                    msg.states[26].state
                );
                assert!(
                    msg.states[27].cn0.almost_eq(3.07619995117187500e+03),
                    "incorrect value for states[27].cn0, expected 3.07619995117187500e+03, is {:e}",
                    msg.states[27].cn0
                );
                assert_eq!(
                    msg.states[27].sid.code, 181,
                    "incorrect value for states[27].sid.code, expected 181, is {}",
                    msg.states[27].sid.code
                );
                assert_eq!(
                    msg.states[27].sid.reserved, 175,
                    "incorrect value for states[27].sid.reserved, expected 175, is {}",
                    msg.states[27].sid.reserved
                );
                assert_eq!(
                    msg.states[27].sid.sat, 24007,
                    "incorrect value for states[27].sid.sat, expected 24007, is {}",
                    msg.states[27].sid.sat
                );
                assert_eq!(
                    msg.states[27].state, 165,
                    "incorrect value for states[27].state, expected 165, is {}",
                    msg.states[27].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_tracking_msg_tracking_state_dep_b`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_tracking_msg_tracking_state_dep_b() {
    {
        let mut payload = Cursor::new(vec![
            85, 19, 0, 242, 241, 252, 115, 183, 227, 63, 68, 154, 1, 183, 69, 255, 175, 121, 43,
            222, 51, 67, 35, 69, 78, 240, 5, 53, 20, 51, 211, 54, 69, 153, 130, 237, 66, 155, 51,
            227, 71, 69, 53, 242, 136, 161, 190, 205, 188, 6, 70, 153, 125, 255, 142, 149, 154,
            217, 184, 69, 248, 102, 95, 31, 76, 154, 33, 169, 69, 131, 115, 141, 27, 12, 154, 225,
            200, 69, 208, 44, 147, 39, 23, 51, 3, 66, 69, 237, 159, 251, 49, 203, 51, 99, 102, 69,
            70, 214, 87, 128, 206, 154, 121, 186, 69, 14, 206, 111, 218, 19, 154, 121, 169, 69,
            216, 98, 209, 54, 2, 154, 25, 219, 67, 200, 133, 99, 7, 34, 102, 198, 232, 68, 155, 43,
            85, 135, 46, 154, 177, 170, 69, 155, 3, 83, 171, 201, 154, 241, 232, 69, 121, 43, 197,
            16, 19, 154, 241, 222, 69, 128, 245, 53, 63, 176, 51, 115, 66, 69, 36, 20, 61, 153, 51,
            154, 73, 134, 69, 46, 82, 116, 140, 22, 51, 147, 37, 69, 177, 67, 146, 96, 143, 205,
            76, 107, 68, 220, 51, 160, 201, 251, 102, 102, 192, 68, 168, 194, 2, 161, 220, 102,
            102, 180, 68, 69, 8, 9, 125, 178, 102, 70, 134, 68, 185, 20, 135, 186, 171, 51, 163, 4,
            69, 18, 124, 155, 85, 170, 205, 208, 13, 70, 57, 244, 206, 255, 186, 154, 105, 149, 69,
            165, 199, 93, 181, 175, 51, 67, 64, 69, 6, 28,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingStateDepB(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepB(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf1f2,
                    "incorrect sender id, expected 0xf1f2, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(5.85620019531250000e+03),
                    "incorrect value for states[0].cn0, expected 5.85620019531250000e+03, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 63,
                    "incorrect value for states[0].sid.code, expected 63, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 68,
                    "incorrect value for states[0].sid.reserved, expected 68, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 58295,
                    "incorrect value for states[0].sid.sat, expected 58295, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 115,
                    "incorrect value for states[0].state, expected 115, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(2.61219995117187500e+03),
                    "incorrect value for states[1].cn0, expected 2.61219995117187500e+03, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 43,
                    "incorrect value for states[1].sid.code, expected 43, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 222,
                    "incorrect value for states[1].sid.reserved, expected 222, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 31151,
                    "incorrect value for states[1].sid.sat, expected 31151, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 255,
                    "incorrect value for states[1].state, expected 255, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(2.92519995117187500e+03),
                    "incorrect value for states[2].cn0, expected 2.92519995117187500e+03, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 53,
                    "incorrect value for states[2].sid.code, expected 53, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 20,
                    "incorrect value for states[2].sid.reserved, expected 20, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 1520,
                    "incorrect value for states[2].sid.sat, expected 1520, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 78,
                    "incorrect value for states[2].state, expected 78, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.19819995117187500e+03),
                    "incorrect value for states[3].cn0, expected 3.19819995117187500e+03, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 66,
                    "incorrect value for states[3].sid.code, expected 66, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 155,
                    "incorrect value for states[3].sid.reserved, expected 155, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 60802,
                    "incorrect value for states[3].sid.sat, expected 60802, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 153,
                    "incorrect value for states[3].state, expected 153, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(8.62320019531250000e+03),
                    "incorrect value for states[4].cn0, expected 8.62320019531250000e+03, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 161,
                    "incorrect value for states[4].sid.code, expected 161, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 190,
                    "incorrect value for states[4].sid.reserved, expected 190, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 35058,
                    "incorrect value for states[4].sid.sat, expected 35058, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 53,
                    "incorrect value for states[4].state, expected 53, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(5.91520019531250000e+03),
                    "incorrect value for states[5].cn0, expected 5.91520019531250000e+03, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 142,
                    "incorrect value for states[5].sid.code, expected 142, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 149,
                    "incorrect value for states[5].sid.reserved, expected 149, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 65405,
                    "incorrect value for states[5].sid.sat, expected 65405, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 153,
                    "incorrect value for states[5].state, expected 153, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(5.41220019531250000e+03),
                    "incorrect value for states[6].cn0, expected 5.41220019531250000e+03, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 31,
                    "incorrect value for states[6].sid.code, expected 31, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 76,
                    "incorrect value for states[6].sid.reserved, expected 76, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 24422,
                    "incorrect value for states[6].sid.sat, expected 24422, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 248,
                    "incorrect value for states[6].state, expected 248, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(6.42820019531250000e+03),
                    "incorrect value for states[7].cn0, expected 6.42820019531250000e+03, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 27,
                    "incorrect value for states[7].sid.code, expected 27, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 12,
                    "incorrect value for states[7].sid.reserved, expected 12, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 36211,
                    "incorrect value for states[7].sid.sat, expected 36211, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 131,
                    "incorrect value for states[7].state, expected 131, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(3.10419995117187500e+03),
                    "incorrect value for states[8].cn0, expected 3.10419995117187500e+03, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 39,
                    "incorrect value for states[8].sid.code, expected 39, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 23,
                    "incorrect value for states[8].sid.reserved, expected 23, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 37676,
                    "incorrect value for states[8].sid.sat, expected 37676, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 208,
                    "incorrect value for states[8].state, expected 208, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(3.68619995117187500e+03),
                    "incorrect value for states[9].cn0, expected 3.68619995117187500e+03, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 49,
                    "incorrect value for states[9].sid.code, expected 49, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 203,
                    "incorrect value for states[9].sid.reserved, expected 203, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 64415,
                    "incorrect value for states[9].sid.sat, expected 64415, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 237,
                    "incorrect value for states[9].state, expected 237, is {}",
                    msg.states[9].state
                );
                assert!(
                    msg.states[10].cn0.almost_eq(5.96720019531250000e+03),
                    "incorrect value for states[10].cn0, expected 5.96720019531250000e+03, is {:e}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].sid.code, 128,
                    "incorrect value for states[10].sid.code, expected 128, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 206,
                    "incorrect value for states[10].sid.reserved, expected 206, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 22486,
                    "incorrect value for states[10].sid.sat, expected 22486, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 70,
                    "incorrect value for states[10].state, expected 70, is {}",
                    msg.states[10].state
                );
                assert!(
                    msg.states[11].cn0.almost_eq(5.42320019531250000e+03),
                    "incorrect value for states[11].cn0, expected 5.42320019531250000e+03, is {:e}",
                    msg.states[11].cn0
                );
                assert_eq!(
                    msg.states[11].sid.code, 218,
                    "incorrect value for states[11].sid.code, expected 218, is {}",
                    msg.states[11].sid.code
                );
                assert_eq!(
                    msg.states[11].sid.reserved, 19,
                    "incorrect value for states[11].sid.reserved, expected 19, is {}",
                    msg.states[11].sid.reserved
                );
                assert_eq!(
                    msg.states[11].sid.sat, 28622,
                    "incorrect value for states[11].sid.sat, expected 28622, is {}",
                    msg.states[11].sid.sat
                );
                assert_eq!(
                    msg.states[11].state, 14,
                    "incorrect value for states[11].state, expected 14, is {}",
                    msg.states[11].state
                );
                assert!(
                    msg.states[12].cn0.almost_eq(4.38200012207031250e+02),
                    "incorrect value for states[12].cn0, expected 4.38200012207031250e+02, is {:e}",
                    msg.states[12].cn0
                );
                assert_eq!(
                    msg.states[12].sid.code, 54,
                    "incorrect value for states[12].sid.code, expected 54, is {}",
                    msg.states[12].sid.code
                );
                assert_eq!(
                    msg.states[12].sid.reserved, 2,
                    "incorrect value for states[12].sid.reserved, expected 2, is {}",
                    msg.states[12].sid.reserved
                );
                assert_eq!(
                    msg.states[12].sid.sat, 53602,
                    "incorrect value for states[12].sid.sat, expected 53602, is {}",
                    msg.states[12].sid.sat
                );
                assert_eq!(
                    msg.states[12].state, 216,
                    "incorrect value for states[12].state, expected 216, is {}",
                    msg.states[12].state
                );
                assert!(
                    msg.states[13].cn0.almost_eq(1.86219995117187500e+03),
                    "incorrect value for states[13].cn0, expected 1.86219995117187500e+03, is {:e}",
                    msg.states[13].cn0
                );
                assert_eq!(
                    msg.states[13].sid.code, 7,
                    "incorrect value for states[13].sid.code, expected 7, is {}",
                    msg.states[13].sid.code
                );
                assert_eq!(
                    msg.states[13].sid.reserved, 34,
                    "incorrect value for states[13].sid.reserved, expected 34, is {}",
                    msg.states[13].sid.reserved
                );
                assert_eq!(
                    msg.states[13].sid.sat, 25477,
                    "incorrect value for states[13].sid.sat, expected 25477, is {}",
                    msg.states[13].sid.sat
                );
                assert_eq!(
                    msg.states[13].state, 200,
                    "incorrect value for states[13].state, expected 200, is {}",
                    msg.states[13].state
                );
                assert!(
                    msg.states[14].cn0.almost_eq(5.46220019531250000e+03),
                    "incorrect value for states[14].cn0, expected 5.46220019531250000e+03, is {:e}",
                    msg.states[14].cn0
                );
                assert_eq!(
                    msg.states[14].sid.code, 135,
                    "incorrect value for states[14].sid.code, expected 135, is {}",
                    msg.states[14].sid.code
                );
                assert_eq!(
                    msg.states[14].sid.reserved, 46,
                    "incorrect value for states[14].sid.reserved, expected 46, is {}",
                    msg.states[14].sid.reserved
                );
                assert_eq!(
                    msg.states[14].sid.sat, 21803,
                    "incorrect value for states[14].sid.sat, expected 21803, is {}",
                    msg.states[14].sid.sat
                );
                assert_eq!(
                    msg.states[14].state, 155,
                    "incorrect value for states[14].state, expected 155, is {}",
                    msg.states[14].state
                );
                assert!(
                    msg.states[15].cn0.almost_eq(7.45420019531250000e+03),
                    "incorrect value for states[15].cn0, expected 7.45420019531250000e+03, is {:e}",
                    msg.states[15].cn0
                );
                assert_eq!(
                    msg.states[15].sid.code, 171,
                    "incorrect value for states[15].sid.code, expected 171, is {}",
                    msg.states[15].sid.code
                );
                assert_eq!(
                    msg.states[15].sid.reserved, 201,
                    "incorrect value for states[15].sid.reserved, expected 201, is {}",
                    msg.states[15].sid.reserved
                );
                assert_eq!(
                    msg.states[15].sid.sat, 21251,
                    "incorrect value for states[15].sid.sat, expected 21251, is {}",
                    msg.states[15].sid.sat
                );
                assert_eq!(
                    msg.states[15].state, 155,
                    "incorrect value for states[15].state, expected 155, is {}",
                    msg.states[15].state
                );
                assert!(
                    msg.states[16].cn0.almost_eq(7.13420019531250000e+03),
                    "incorrect value for states[16].cn0, expected 7.13420019531250000e+03, is {:e}",
                    msg.states[16].cn0
                );
                assert_eq!(
                    msg.states[16].sid.code, 16,
                    "incorrect value for states[16].sid.code, expected 16, is {}",
                    msg.states[16].sid.code
                );
                assert_eq!(
                    msg.states[16].sid.reserved, 19,
                    "incorrect value for states[16].sid.reserved, expected 19, is {}",
                    msg.states[16].sid.reserved
                );
                assert_eq!(
                    msg.states[16].sid.sat, 50475,
                    "incorrect value for states[16].sid.sat, expected 50475, is {}",
                    msg.states[16].sid.sat
                );
                assert_eq!(
                    msg.states[16].state, 121,
                    "incorrect value for states[16].state, expected 121, is {}",
                    msg.states[16].state
                );
                assert!(
                    msg.states[17].cn0.almost_eq(3.11119995117187500e+03),
                    "incorrect value for states[17].cn0, expected 3.11119995117187500e+03, is {:e}",
                    msg.states[17].cn0
                );
                assert_eq!(
                    msg.states[17].sid.code, 63,
                    "incorrect value for states[17].sid.code, expected 63, is {}",
                    msg.states[17].sid.code
                );
                assert_eq!(
                    msg.states[17].sid.reserved, 176,
                    "incorrect value for states[17].sid.reserved, expected 176, is {}",
                    msg.states[17].sid.reserved
                );
                assert_eq!(
                    msg.states[17].sid.sat, 13813,
                    "incorrect value for states[17].sid.sat, expected 13813, is {}",
                    msg.states[17].sid.sat
                );
                assert_eq!(
                    msg.states[17].state, 128,
                    "incorrect value for states[17].state, expected 128, is {}",
                    msg.states[17].state
                );
                assert!(
                    msg.states[18].cn0.almost_eq(4.29720019531250000e+03),
                    "incorrect value for states[18].cn0, expected 4.29720019531250000e+03, is {:e}",
                    msg.states[18].cn0
                );
                assert_eq!(
                    msg.states[18].sid.code, 153,
                    "incorrect value for states[18].sid.code, expected 153, is {}",
                    msg.states[18].sid.code
                );
                assert_eq!(
                    msg.states[18].sid.reserved, 51,
                    "incorrect value for states[18].sid.reserved, expected 51, is {}",
                    msg.states[18].sid.reserved
                );
                assert_eq!(
                    msg.states[18].sid.sat, 15636,
                    "incorrect value for states[18].sid.sat, expected 15636, is {}",
                    msg.states[18].sid.sat
                );
                assert_eq!(
                    msg.states[18].state, 36,
                    "incorrect value for states[18].state, expected 36, is {}",
                    msg.states[18].state
                );
                assert!(
                    msg.states[19].cn0.almost_eq(2.64919995117187500e+03),
                    "incorrect value for states[19].cn0, expected 2.64919995117187500e+03, is {:e}",
                    msg.states[19].cn0
                );
                assert_eq!(
                    msg.states[19].sid.code, 140,
                    "incorrect value for states[19].sid.code, expected 140, is {}",
                    msg.states[19].sid.code
                );
                assert_eq!(
                    msg.states[19].sid.reserved, 22,
                    "incorrect value for states[19].sid.reserved, expected 22, is {}",
                    msg.states[19].sid.reserved
                );
                assert_eq!(
                    msg.states[19].sid.sat, 29778,
                    "incorrect value for states[19].sid.sat, expected 29778, is {}",
                    msg.states[19].sid.sat
                );
                assert_eq!(
                    msg.states[19].state, 46,
                    "incorrect value for states[19].state, expected 46, is {}",
                    msg.states[19].state
                );
                assert!(
                    msg.states[20].cn0.almost_eq(9.41200012207031250e+02),
                    "incorrect value for states[20].cn0, expected 9.41200012207031250e+02, is {:e}",
                    msg.states[20].cn0
                );
                assert_eq!(
                    msg.states[20].sid.code, 96,
                    "incorrect value for states[20].sid.code, expected 96, is {}",
                    msg.states[20].sid.code
                );
                assert_eq!(
                    msg.states[20].sid.reserved, 143,
                    "incorrect value for states[20].sid.reserved, expected 143, is {}",
                    msg.states[20].sid.reserved
                );
                assert_eq!(
                    msg.states[20].sid.sat, 37443,
                    "incorrect value for states[20].sid.sat, expected 37443, is {}",
                    msg.states[20].sid.sat
                );
                assert_eq!(
                    msg.states[20].state, 177,
                    "incorrect value for states[20].state, expected 177, is {}",
                    msg.states[20].state
                );
                assert!(
                    msg.states[21].cn0.almost_eq(1.53919995117187500e+03),
                    "incorrect value for states[21].cn0, expected 1.53919995117187500e+03, is {:e}",
                    msg.states[21].cn0
                );
                assert_eq!(
                    msg.states[21].sid.code, 201,
                    "incorrect value for states[21].sid.code, expected 201, is {}",
                    msg.states[21].sid.code
                );
                assert_eq!(
                    msg.states[21].sid.reserved, 251,
                    "incorrect value for states[21].sid.reserved, expected 251, is {}",
                    msg.states[21].sid.reserved
                );
                assert_eq!(
                    msg.states[21].sid.sat, 41011,
                    "incorrect value for states[21].sid.sat, expected 41011, is {}",
                    msg.states[21].sid.sat
                );
                assert_eq!(
                    msg.states[21].state, 220,
                    "incorrect value for states[21].state, expected 220, is {}",
                    msg.states[21].state
                );
                assert!(
                    msg.states[22].cn0.almost_eq(1.44319995117187500e+03),
                    "incorrect value for states[22].cn0, expected 1.44319995117187500e+03, is {:e}",
                    msg.states[22].cn0
                );
                assert_eq!(
                    msg.states[22].sid.code, 161,
                    "incorrect value for states[22].sid.code, expected 161, is {}",
                    msg.states[22].sid.code
                );
                assert_eq!(
                    msg.states[22].sid.reserved, 220,
                    "incorrect value for states[22].sid.reserved, expected 220, is {}",
                    msg.states[22].sid.reserved
                );
                assert_eq!(
                    msg.states[22].sid.sat, 706,
                    "incorrect value for states[22].sid.sat, expected 706, is {}",
                    msg.states[22].sid.sat
                );
                assert_eq!(
                    msg.states[22].state, 168,
                    "incorrect value for states[22].state, expected 168, is {}",
                    msg.states[22].state
                );
                assert!(
                    msg.states[23].cn0.almost_eq(1.07419995117187500e+03),
                    "incorrect value for states[23].cn0, expected 1.07419995117187500e+03, is {:e}",
                    msg.states[23].cn0
                );
                assert_eq!(
                    msg.states[23].sid.code, 125,
                    "incorrect value for states[23].sid.code, expected 125, is {}",
                    msg.states[23].sid.code
                );
                assert_eq!(
                    msg.states[23].sid.reserved, 178,
                    "incorrect value for states[23].sid.reserved, expected 178, is {}",
                    msg.states[23].sid.reserved
                );
                assert_eq!(
                    msg.states[23].sid.sat, 2312,
                    "incorrect value for states[23].sid.sat, expected 2312, is {}",
                    msg.states[23].sid.sat
                );
                assert_eq!(
                    msg.states[23].state, 69,
                    "incorrect value for states[23].state, expected 69, is {}",
                    msg.states[23].state
                );
                assert!(
                    msg.states[24].cn0.almost_eq(2.12219995117187500e+03),
                    "incorrect value for states[24].cn0, expected 2.12219995117187500e+03, is {:e}",
                    msg.states[24].cn0
                );
                assert_eq!(
                    msg.states[24].sid.code, 186,
                    "incorrect value for states[24].sid.code, expected 186, is {}",
                    msg.states[24].sid.code
                );
                assert_eq!(
                    msg.states[24].sid.reserved, 171,
                    "incorrect value for states[24].sid.reserved, expected 171, is {}",
                    msg.states[24].sid.reserved
                );
                assert_eq!(
                    msg.states[24].sid.sat, 34580,
                    "incorrect value for states[24].sid.sat, expected 34580, is {}",
                    msg.states[24].sid.sat
                );
                assert_eq!(
                    msg.states[24].state, 185,
                    "incorrect value for states[24].state, expected 185, is {}",
                    msg.states[24].state
                );
                assert!(
                    msg.states[25].cn0.almost_eq(9.07620019531250000e+03),
                    "incorrect value for states[25].cn0, expected 9.07620019531250000e+03, is {:e}",
                    msg.states[25].cn0
                );
                assert_eq!(
                    msg.states[25].sid.code, 85,
                    "incorrect value for states[25].sid.code, expected 85, is {}",
                    msg.states[25].sid.code
                );
                assert_eq!(
                    msg.states[25].sid.reserved, 170,
                    "incorrect value for states[25].sid.reserved, expected 170, is {}",
                    msg.states[25].sid.reserved
                );
                assert_eq!(
                    msg.states[25].sid.sat, 39804,
                    "incorrect value for states[25].sid.sat, expected 39804, is {}",
                    msg.states[25].sid.sat
                );
                assert_eq!(
                    msg.states[25].state, 18,
                    "incorrect value for states[25].state, expected 18, is {}",
                    msg.states[25].state
                );
                assert!(
                    msg.states[26].cn0.almost_eq(4.78120019531250000e+03),
                    "incorrect value for states[26].cn0, expected 4.78120019531250000e+03, is {:e}",
                    msg.states[26].cn0
                );
                assert_eq!(
                    msg.states[26].sid.code, 255,
                    "incorrect value for states[26].sid.code, expected 255, is {}",
                    msg.states[26].sid.code
                );
                assert_eq!(
                    msg.states[26].sid.reserved, 186,
                    "incorrect value for states[26].sid.reserved, expected 186, is {}",
                    msg.states[26].sid.reserved
                );
                assert_eq!(
                    msg.states[26].sid.sat, 52980,
                    "incorrect value for states[26].sid.sat, expected 52980, is {}",
                    msg.states[26].sid.sat
                );
                assert_eq!(
                    msg.states[26].state, 57,
                    "incorrect value for states[26].state, expected 57, is {}",
                    msg.states[26].state
                );
                assert!(
                    msg.states[27].cn0.almost_eq(3.07619995117187500e+03),
                    "incorrect value for states[27].cn0, expected 3.07619995117187500e+03, is {:e}",
                    msg.states[27].cn0
                );
                assert_eq!(
                    msg.states[27].sid.code, 181,
                    "incorrect value for states[27].sid.code, expected 181, is {}",
                    msg.states[27].sid.code
                );
                assert_eq!(
                    msg.states[27].sid.reserved, 175,
                    "incorrect value for states[27].sid.reserved, expected 175, is {}",
                    msg.states[27].sid.reserved
                );
                assert_eq!(
                    msg.states[27].sid.sat, 24007,
                    "incorrect value for states[27].sid.sat, expected 24007, is {}",
                    msg.states[27].sid.sat
                );
                assert_eq!(
                    msg.states[27].state, 165,
                    "incorrect value for states[27].state, expected 165, is {}",
                    msg.states[27].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
