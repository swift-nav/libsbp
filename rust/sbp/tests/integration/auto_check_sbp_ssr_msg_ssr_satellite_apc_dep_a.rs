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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApcDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_satellite_apc_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 4, 6, 56, 19, 224, 203, 169, 240, 78, 4, 213, 171, 254, 214, 212, 4, 8, 33, 31, 80,
            21, 4, 105, 225, 39, 139, 124, 149, 48, 15, 214, 197, 141, 32, 33, 135, 150, 148, 123,
            49, 135, 97, 39, 90, 20, 169, 239, 47, 153, 175, 35, 145, 145, 123, 194, 2, 102, 74,
            149, 95, 171, 238, 249, 7, 237, 170, 125, 106, 158, 83, 188, 181, 194, 27, 84, 226,
            142, 123, 77, 217, 248, 67, 215, 129, 114, 138, 25, 240, 10, 56, 76, 61, 161, 216, 22,
            181, 174, 33, 13, 252, 236, 230, 196, 128, 215, 239, 234, 179, 220, 44, 212, 57, 44,
            173, 49, 36, 137, 248, 235, 97, 112, 157, 139, 26, 115, 192, 31, 85, 127, 228, 81, 252,
            219, 249, 110, 147, 8, 161, 215, 212, 180, 25, 83, 144, 247, 12, 27, 199, 173, 74, 23,
            4, 239, 103, 223, 220, 139, 91, 127, 214, 86, 48, 203, 228, 99, 45, 83, 159, 11, 250,
            135, 170, 42, 217, 199, 233, 42, 170, 78, 206, 41, 43, 81, 247, 99, 198, 144, 2, 132,
            2, 224, 220, 148, 58, 85, 138, 210, 200, 158, 7, 158, 67, 46, 200, 132, 118, 241, 13,
            37, 62, 107, 253, 190, 136, 66, 9, 84, 155, 86, 180, 41, 196, 40, 119, 101, 252, 223,
            144, 153, 50, 13,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrSatelliteApcDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x604,
                    "Incorrect message type, expected 0x604, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1338,
                    "incorrect sender id, expected 0x1338, is {sender_id}"
                );
                assert_eq!(
                    msg.apc[0].pco[0], -21547,
                    "incorrect value for apc[0].pco[0], expected -21547, is {}",
                    msg.apc[0].pco[0]
                );
                assert_eq!(
                    msg.apc[0].pco[1], -10498,
                    "incorrect value for apc[0].pco[1], expected -10498, is {}",
                    msg.apc[0].pco[1]
                );
                assert_eq!(
                    msg.apc[0].pco[2], 1236,
                    "incorrect value for apc[0].pco[2], expected 1236, is {}",
                    msg.apc[0].pco[2]
                );
                assert_eq!(
                    msg.apc[0].pcv[0], 8,
                    "incorrect value for apc[0].pcv[0], expected 8, is {}",
                    msg.apc[0].pcv[0]
                );
                assert_eq!(
                    msg.apc[0].pcv[1], 33,
                    "incorrect value for apc[0].pcv[1], expected 33, is {}",
                    msg.apc[0].pcv[1]
                );
                assert_eq!(
                    msg.apc[0].pcv[2], 31,
                    "incorrect value for apc[0].pcv[2], expected 31, is {}",
                    msg.apc[0].pcv[2]
                );
                assert_eq!(
                    msg.apc[0].pcv[3], 80,
                    "incorrect value for apc[0].pcv[3], expected 80, is {}",
                    msg.apc[0].pcv[3]
                );
                assert_eq!(
                    msg.apc[0].pcv[4], 21,
                    "incorrect value for apc[0].pcv[4], expected 21, is {}",
                    msg.apc[0].pcv[4]
                );
                assert_eq!(
                    msg.apc[0].pcv[5], 4,
                    "incorrect value for apc[0].pcv[5], expected 4, is {}",
                    msg.apc[0].pcv[5]
                );
                assert_eq!(
                    msg.apc[0].pcv[6], 105,
                    "incorrect value for apc[0].pcv[6], expected 105, is {}",
                    msg.apc[0].pcv[6]
                );
                assert_eq!(
                    msg.apc[0].pcv[7], -31,
                    "incorrect value for apc[0].pcv[7], expected -31, is {}",
                    msg.apc[0].pcv[7]
                );
                assert_eq!(
                    msg.apc[0].pcv[8], 39,
                    "incorrect value for apc[0].pcv[8], expected 39, is {}",
                    msg.apc[0].pcv[8]
                );
                assert_eq!(
                    msg.apc[0].pcv[9], -117,
                    "incorrect value for apc[0].pcv[9], expected -117, is {}",
                    msg.apc[0].pcv[9]
                );
                assert_eq!(
                    msg.apc[0].pcv[10], 124,
                    "incorrect value for apc[0].pcv[10], expected 124, is {}",
                    msg.apc[0].pcv[10]
                );
                assert_eq!(
                    msg.apc[0].pcv[11], -107,
                    "incorrect value for apc[0].pcv[11], expected -107, is {}",
                    msg.apc[0].pcv[11]
                );
                assert_eq!(
                    msg.apc[0].pcv[12], 48,
                    "incorrect value for apc[0].pcv[12], expected 48, is {}",
                    msg.apc[0].pcv[12]
                );
                assert_eq!(
                    msg.apc[0].pcv[13], 15,
                    "incorrect value for apc[0].pcv[13], expected 15, is {}",
                    msg.apc[0].pcv[13]
                );
                assert_eq!(
                    msg.apc[0].pcv[14], -42,
                    "incorrect value for apc[0].pcv[14], expected -42, is {}",
                    msg.apc[0].pcv[14]
                );
                assert_eq!(
                    msg.apc[0].pcv[15], -59,
                    "incorrect value for apc[0].pcv[15], expected -59, is {}",
                    msg.apc[0].pcv[15]
                );
                assert_eq!(
                    msg.apc[0].pcv[16], -115,
                    "incorrect value for apc[0].pcv[16], expected -115, is {}",
                    msg.apc[0].pcv[16]
                );
                assert_eq!(
                    msg.apc[0].pcv[17], 32,
                    "incorrect value for apc[0].pcv[17], expected 32, is {}",
                    msg.apc[0].pcv[17]
                );
                assert_eq!(
                    msg.apc[0].pcv[18], 33,
                    "incorrect value for apc[0].pcv[18], expected 33, is {}",
                    msg.apc[0].pcv[18]
                );
                assert_eq!(
                    msg.apc[0].pcv[19], -121,
                    "incorrect value for apc[0].pcv[19], expected -121, is {}",
                    msg.apc[0].pcv[19]
                );
                assert_eq!(
                    msg.apc[0].pcv[20], -106,
                    "incorrect value for apc[0].pcv[20], expected -106, is {}",
                    msg.apc[0].pcv[20]
                );
                assert_eq!(
                    msg.apc[0].sat_info, 240,
                    "incorrect value for apc[0].sat_info, expected 240, is {}",
                    msg.apc[0].sat_info
                );
                assert_eq!(
                    msg.apc[0].sid.code, 169,
                    "incorrect value for apc[0].sid.code, expected 169, is {}",
                    msg.apc[0].sid.code
                );
                assert_eq!(
                    msg.apc[0].sid.sat, 203,
                    "incorrect value for apc[0].sid.sat, expected 203, is {}",
                    msg.apc[0].sid.sat
                );
                assert_eq!(
                    msg.apc[0].svn, 1102,
                    "incorrect value for apc[0].svn, expected 1102, is {}",
                    msg.apc[0].svn
                );
                assert_eq!(
                    msg.apc[1].pco[0], 23079,
                    "incorrect value for apc[1].pco[0], expected 23079, is {}",
                    msg.apc[1].pco[0]
                );
                assert_eq!(
                    msg.apc[1].pco[1], -22252,
                    "incorrect value for apc[1].pco[1], expected -22252, is {}",
                    msg.apc[1].pco[1]
                );
                assert_eq!(
                    msg.apc[1].pco[2], 12271,
                    "incorrect value for apc[1].pco[2], expected 12271, is {}",
                    msg.apc[1].pco[2]
                );
                assert_eq!(
                    msg.apc[1].pcv[0], -103,
                    "incorrect value for apc[1].pcv[0], expected -103, is {}",
                    msg.apc[1].pcv[0]
                );
                assert_eq!(
                    msg.apc[1].pcv[1], -81,
                    "incorrect value for apc[1].pcv[1], expected -81, is {}",
                    msg.apc[1].pcv[1]
                );
                assert_eq!(
                    msg.apc[1].pcv[2], 35,
                    "incorrect value for apc[1].pcv[2], expected 35, is {}",
                    msg.apc[1].pcv[2]
                );
                assert_eq!(
                    msg.apc[1].pcv[3], -111,
                    "incorrect value for apc[1].pcv[3], expected -111, is {}",
                    msg.apc[1].pcv[3]
                );
                assert_eq!(
                    msg.apc[1].pcv[4], -111,
                    "incorrect value for apc[1].pcv[4], expected -111, is {}",
                    msg.apc[1].pcv[4]
                );
                assert_eq!(
                    msg.apc[1].pcv[5], 123,
                    "incorrect value for apc[1].pcv[5], expected 123, is {}",
                    msg.apc[1].pcv[5]
                );
                assert_eq!(
                    msg.apc[1].pcv[6], -62,
                    "incorrect value for apc[1].pcv[6], expected -62, is {}",
                    msg.apc[1].pcv[6]
                );
                assert_eq!(
                    msg.apc[1].pcv[7], 2,
                    "incorrect value for apc[1].pcv[7], expected 2, is {}",
                    msg.apc[1].pcv[7]
                );
                assert_eq!(
                    msg.apc[1].pcv[8], 102,
                    "incorrect value for apc[1].pcv[8], expected 102, is {}",
                    msg.apc[1].pcv[8]
                );
                assert_eq!(
                    msg.apc[1].pcv[9], 74,
                    "incorrect value for apc[1].pcv[9], expected 74, is {}",
                    msg.apc[1].pcv[9]
                );
                assert_eq!(
                    msg.apc[1].pcv[10], -107,
                    "incorrect value for apc[1].pcv[10], expected -107, is {}",
                    msg.apc[1].pcv[10]
                );
                assert_eq!(
                    msg.apc[1].pcv[11], 95,
                    "incorrect value for apc[1].pcv[11], expected 95, is {}",
                    msg.apc[1].pcv[11]
                );
                assert_eq!(
                    msg.apc[1].pcv[12], -85,
                    "incorrect value for apc[1].pcv[12], expected -85, is {}",
                    msg.apc[1].pcv[12]
                );
                assert_eq!(
                    msg.apc[1].pcv[13], -18,
                    "incorrect value for apc[1].pcv[13], expected -18, is {}",
                    msg.apc[1].pcv[13]
                );
                assert_eq!(
                    msg.apc[1].pcv[14], -7,
                    "incorrect value for apc[1].pcv[14], expected -7, is {}",
                    msg.apc[1].pcv[14]
                );
                assert_eq!(
                    msg.apc[1].pcv[15], 7,
                    "incorrect value for apc[1].pcv[15], expected 7, is {}",
                    msg.apc[1].pcv[15]
                );
                assert_eq!(
                    msg.apc[1].pcv[16], -19,
                    "incorrect value for apc[1].pcv[16], expected -19, is {}",
                    msg.apc[1].pcv[16]
                );
                assert_eq!(
                    msg.apc[1].pcv[17], -86,
                    "incorrect value for apc[1].pcv[17], expected -86, is {}",
                    msg.apc[1].pcv[17]
                );
                assert_eq!(
                    msg.apc[1].pcv[18], 125,
                    "incorrect value for apc[1].pcv[18], expected 125, is {}",
                    msg.apc[1].pcv[18]
                );
                assert_eq!(
                    msg.apc[1].pcv[19], 106,
                    "incorrect value for apc[1].pcv[19], expected 106, is {}",
                    msg.apc[1].pcv[19]
                );
                assert_eq!(
                    msg.apc[1].pcv[20], -98,
                    "incorrect value for apc[1].pcv[20], expected -98, is {}",
                    msg.apc[1].pcv[20]
                );
                assert_eq!(
                    msg.apc[1].sat_info, 49,
                    "incorrect value for apc[1].sat_info, expected 49, is {}",
                    msg.apc[1].sat_info
                );
                assert_eq!(
                    msg.apc[1].sid.code, 123,
                    "incorrect value for apc[1].sid.code, expected 123, is {}",
                    msg.apc[1].sid.code
                );
                assert_eq!(
                    msg.apc[1].sid.sat, 148,
                    "incorrect value for apc[1].sid.sat, expected 148, is {}",
                    msg.apc[1].sid.sat
                );
                assert_eq!(
                    msg.apc[1].svn, 24967,
                    "incorrect value for apc[1].svn, expected 24967, is {}",
                    msg.apc[1].svn
                );
                assert_eq!(
                    msg.apc[2].pco[0], -7596,
                    "incorrect value for apc[2].pco[0], expected -7596, is {}",
                    msg.apc[2].pco[0]
                );
                assert_eq!(
                    msg.apc[2].pco[1], 31630,
                    "incorrect value for apc[2].pco[1], expected 31630, is {}",
                    msg.apc[2].pco[1]
                );
                assert_eq!(
                    msg.apc[2].pco[2], -9907,
                    "incorrect value for apc[2].pco[2], expected -9907, is {}",
                    msg.apc[2].pco[2]
                );
                assert_eq!(
                    msg.apc[2].pcv[0], -8,
                    "incorrect value for apc[2].pcv[0], expected -8, is {}",
                    msg.apc[2].pcv[0]
                );
                assert_eq!(
                    msg.apc[2].pcv[1], 67,
                    "incorrect value for apc[2].pcv[1], expected 67, is {}",
                    msg.apc[2].pcv[1]
                );
                assert_eq!(
                    msg.apc[2].pcv[2], -41,
                    "incorrect value for apc[2].pcv[2], expected -41, is {}",
                    msg.apc[2].pcv[2]
                );
                assert_eq!(
                    msg.apc[2].pcv[3], -127,
                    "incorrect value for apc[2].pcv[3], expected -127, is {}",
                    msg.apc[2].pcv[3]
                );
                assert_eq!(
                    msg.apc[2].pcv[4], 114,
                    "incorrect value for apc[2].pcv[4], expected 114, is {}",
                    msg.apc[2].pcv[4]
                );
                assert_eq!(
                    msg.apc[2].pcv[5], -118,
                    "incorrect value for apc[2].pcv[5], expected -118, is {}",
                    msg.apc[2].pcv[5]
                );
                assert_eq!(
                    msg.apc[2].pcv[6], 25,
                    "incorrect value for apc[2].pcv[6], expected 25, is {}",
                    msg.apc[2].pcv[6]
                );
                assert_eq!(
                    msg.apc[2].pcv[7], -16,
                    "incorrect value for apc[2].pcv[7], expected -16, is {}",
                    msg.apc[2].pcv[7]
                );
                assert_eq!(
                    msg.apc[2].pcv[8], 10,
                    "incorrect value for apc[2].pcv[8], expected 10, is {}",
                    msg.apc[2].pcv[8]
                );
                assert_eq!(
                    msg.apc[2].pcv[9], 56,
                    "incorrect value for apc[2].pcv[9], expected 56, is {}",
                    msg.apc[2].pcv[9]
                );
                assert_eq!(
                    msg.apc[2].pcv[10], 76,
                    "incorrect value for apc[2].pcv[10], expected 76, is {}",
                    msg.apc[2].pcv[10]
                );
                assert_eq!(
                    msg.apc[2].pcv[11], 61,
                    "incorrect value for apc[2].pcv[11], expected 61, is {}",
                    msg.apc[2].pcv[11]
                );
                assert_eq!(
                    msg.apc[2].pcv[12], -95,
                    "incorrect value for apc[2].pcv[12], expected -95, is {}",
                    msg.apc[2].pcv[12]
                );
                assert_eq!(
                    msg.apc[2].pcv[13], -40,
                    "incorrect value for apc[2].pcv[13], expected -40, is {}",
                    msg.apc[2].pcv[13]
                );
                assert_eq!(
                    msg.apc[2].pcv[14], 22,
                    "incorrect value for apc[2].pcv[14], expected 22, is {}",
                    msg.apc[2].pcv[14]
                );
                assert_eq!(
                    msg.apc[2].pcv[15], -75,
                    "incorrect value for apc[2].pcv[15], expected -75, is {}",
                    msg.apc[2].pcv[15]
                );
                assert_eq!(
                    msg.apc[2].pcv[16], -82,
                    "incorrect value for apc[2].pcv[16], expected -82, is {}",
                    msg.apc[2].pcv[16]
                );
                assert_eq!(
                    msg.apc[2].pcv[17], 33,
                    "incorrect value for apc[2].pcv[17], expected 33, is {}",
                    msg.apc[2].pcv[17]
                );
                assert_eq!(
                    msg.apc[2].pcv[18], 13,
                    "incorrect value for apc[2].pcv[18], expected 13, is {}",
                    msg.apc[2].pcv[18]
                );
                assert_eq!(
                    msg.apc[2].pcv[19], -4,
                    "incorrect value for apc[2].pcv[19], expected -4, is {}",
                    msg.apc[2].pcv[19]
                );
                assert_eq!(
                    msg.apc[2].pcv[20], -20,
                    "incorrect value for apc[2].pcv[20], expected -20, is {}",
                    msg.apc[2].pcv[20]
                );
                assert_eq!(
                    msg.apc[2].sat_info, 181,
                    "incorrect value for apc[2].sat_info, expected 181, is {}",
                    msg.apc[2].sat_info
                );
                assert_eq!(
                    msg.apc[2].sid.code, 188,
                    "incorrect value for apc[2].sid.code, expected 188, is {}",
                    msg.apc[2].sid.code
                );
                assert_eq!(
                    msg.apc[2].sid.sat, 83,
                    "incorrect value for apc[2].sid.sat, expected 83, is {}",
                    msg.apc[2].sid.sat
                );
                assert_eq!(
                    msg.apc[2].svn, 7106,
                    "incorrect value for apc[2].svn, expected 7106, is {}",
                    msg.apc[2].svn
                );
                assert_eq!(
                    msg.apc[3].pco[0], -19478,
                    "incorrect value for apc[3].pco[0], expected -19478, is {}",
                    msg.apc[3].pco[0]
                );
                assert_eq!(
                    msg.apc[3].pco[1], 11484,
                    "incorrect value for apc[3].pco[1], expected 11484, is {}",
                    msg.apc[3].pco[1]
                );
                assert_eq!(
                    msg.apc[3].pco[2], 14804,
                    "incorrect value for apc[3].pco[2], expected 14804, is {}",
                    msg.apc[3].pco[2]
                );
                assert_eq!(
                    msg.apc[3].pcv[0], 44,
                    "incorrect value for apc[3].pcv[0], expected 44, is {}",
                    msg.apc[3].pcv[0]
                );
                assert_eq!(
                    msg.apc[3].pcv[1], -83,
                    "incorrect value for apc[3].pcv[1], expected -83, is {}",
                    msg.apc[3].pcv[1]
                );
                assert_eq!(
                    msg.apc[3].pcv[2], 49,
                    "incorrect value for apc[3].pcv[2], expected 49, is {}",
                    msg.apc[3].pcv[2]
                );
                assert_eq!(
                    msg.apc[3].pcv[3], 36,
                    "incorrect value for apc[3].pcv[3], expected 36, is {}",
                    msg.apc[3].pcv[3]
                );
                assert_eq!(
                    msg.apc[3].pcv[4], -119,
                    "incorrect value for apc[3].pcv[4], expected -119, is {}",
                    msg.apc[3].pcv[4]
                );
                assert_eq!(
                    msg.apc[3].pcv[5], -8,
                    "incorrect value for apc[3].pcv[5], expected -8, is {}",
                    msg.apc[3].pcv[5]
                );
                assert_eq!(
                    msg.apc[3].pcv[6], -21,
                    "incorrect value for apc[3].pcv[6], expected -21, is {}",
                    msg.apc[3].pcv[6]
                );
                assert_eq!(
                    msg.apc[3].pcv[7], 97,
                    "incorrect value for apc[3].pcv[7], expected 97, is {}",
                    msg.apc[3].pcv[7]
                );
                assert_eq!(
                    msg.apc[3].pcv[8], 112,
                    "incorrect value for apc[3].pcv[8], expected 112, is {}",
                    msg.apc[3].pcv[8]
                );
                assert_eq!(
                    msg.apc[3].pcv[9], -99,
                    "incorrect value for apc[3].pcv[9], expected -99, is {}",
                    msg.apc[3].pcv[9]
                );
                assert_eq!(
                    msg.apc[3].pcv[10], -117,
                    "incorrect value for apc[3].pcv[10], expected -117, is {}",
                    msg.apc[3].pcv[10]
                );
                assert_eq!(
                    msg.apc[3].pcv[11], 26,
                    "incorrect value for apc[3].pcv[11], expected 26, is {}",
                    msg.apc[3].pcv[11]
                );
                assert_eq!(
                    msg.apc[3].pcv[12], 115,
                    "incorrect value for apc[3].pcv[12], expected 115, is {}",
                    msg.apc[3].pcv[12]
                );
                assert_eq!(
                    msg.apc[3].pcv[13], -64,
                    "incorrect value for apc[3].pcv[13], expected -64, is {}",
                    msg.apc[3].pcv[13]
                );
                assert_eq!(
                    msg.apc[3].pcv[14], 31,
                    "incorrect value for apc[3].pcv[14], expected 31, is {}",
                    msg.apc[3].pcv[14]
                );
                assert_eq!(
                    msg.apc[3].pcv[15], 85,
                    "incorrect value for apc[3].pcv[15], expected 85, is {}",
                    msg.apc[3].pcv[15]
                );
                assert_eq!(
                    msg.apc[3].pcv[16], 127,
                    "incorrect value for apc[3].pcv[16], expected 127, is {}",
                    msg.apc[3].pcv[16]
                );
                assert_eq!(
                    msg.apc[3].pcv[17], -28,
                    "incorrect value for apc[3].pcv[17], expected -28, is {}",
                    msg.apc[3].pcv[17]
                );
                assert_eq!(
                    msg.apc[3].pcv[18], 81,
                    "incorrect value for apc[3].pcv[18], expected 81, is {}",
                    msg.apc[3].pcv[18]
                );
                assert_eq!(
                    msg.apc[3].pcv[19], -4,
                    "incorrect value for apc[3].pcv[19], expected -4, is {}",
                    msg.apc[3].pcv[19]
                );
                assert_eq!(
                    msg.apc[3].pcv[20], -37,
                    "incorrect value for apc[3].pcv[20], expected -37, is {}",
                    msg.apc[3].pcv[20]
                );
                assert_eq!(
                    msg.apc[3].sat_info, 128,
                    "incorrect value for apc[3].sat_info, expected 128, is {}",
                    msg.apc[3].sat_info
                );
                assert_eq!(
                    msg.apc[3].sid.code, 196,
                    "incorrect value for apc[3].sid.code, expected 196, is {}",
                    msg.apc[3].sid.code
                );
                assert_eq!(
                    msg.apc[3].sid.sat, 230,
                    "incorrect value for apc[3].sid.sat, expected 230, is {}",
                    msg.apc[3].sid.sat
                );
                assert_eq!(
                    msg.apc[3].svn, 61399,
                    "incorrect value for apc[3].svn, expected 61399, is {}",
                    msg.apc[3].svn
                );
                assert_eq!(
                    msg.apc[4].pco[0], -11049,
                    "incorrect value for apc[4].pco[0], expected -11049, is {}",
                    msg.apc[4].pco[0]
                );
                assert_eq!(
                    msg.apc[4].pco[1], 6580,
                    "incorrect value for apc[4].pco[1], expected 6580, is {}",
                    msg.apc[4].pco[1]
                );
                assert_eq!(
                    msg.apc[4].pco[2], -28589,
                    "incorrect value for apc[4].pco[2], expected -28589, is {}",
                    msg.apc[4].pco[2]
                );
                assert_eq!(
                    msg.apc[4].pcv[0], -9,
                    "incorrect value for apc[4].pcv[0], expected -9, is {}",
                    msg.apc[4].pcv[0]
                );
                assert_eq!(
                    msg.apc[4].pcv[1], 12,
                    "incorrect value for apc[4].pcv[1], expected 12, is {}",
                    msg.apc[4].pcv[1]
                );
                assert_eq!(
                    msg.apc[4].pcv[2], 27,
                    "incorrect value for apc[4].pcv[2], expected 27, is {}",
                    msg.apc[4].pcv[2]
                );
                assert_eq!(
                    msg.apc[4].pcv[3], -57,
                    "incorrect value for apc[4].pcv[3], expected -57, is {}",
                    msg.apc[4].pcv[3]
                );
                assert_eq!(
                    msg.apc[4].pcv[4], -83,
                    "incorrect value for apc[4].pcv[4], expected -83, is {}",
                    msg.apc[4].pcv[4]
                );
                assert_eq!(
                    msg.apc[4].pcv[5], 74,
                    "incorrect value for apc[4].pcv[5], expected 74, is {}",
                    msg.apc[4].pcv[5]
                );
                assert_eq!(
                    msg.apc[4].pcv[6], 23,
                    "incorrect value for apc[4].pcv[6], expected 23, is {}",
                    msg.apc[4].pcv[6]
                );
                assert_eq!(
                    msg.apc[4].pcv[7], 4,
                    "incorrect value for apc[4].pcv[7], expected 4, is {}",
                    msg.apc[4].pcv[7]
                );
                assert_eq!(
                    msg.apc[4].pcv[8], -17,
                    "incorrect value for apc[4].pcv[8], expected -17, is {}",
                    msg.apc[4].pcv[8]
                );
                assert_eq!(
                    msg.apc[4].pcv[9], 103,
                    "incorrect value for apc[4].pcv[9], expected 103, is {}",
                    msg.apc[4].pcv[9]
                );
                assert_eq!(
                    msg.apc[4].pcv[10], -33,
                    "incorrect value for apc[4].pcv[10], expected -33, is {}",
                    msg.apc[4].pcv[10]
                );
                assert_eq!(
                    msg.apc[4].pcv[11], -36,
                    "incorrect value for apc[4].pcv[11], expected -36, is {}",
                    msg.apc[4].pcv[11]
                );
                assert_eq!(
                    msg.apc[4].pcv[12], -117,
                    "incorrect value for apc[4].pcv[12], expected -117, is {}",
                    msg.apc[4].pcv[12]
                );
                assert_eq!(
                    msg.apc[4].pcv[13], 91,
                    "incorrect value for apc[4].pcv[13], expected 91, is {}",
                    msg.apc[4].pcv[13]
                );
                assert_eq!(
                    msg.apc[4].pcv[14], 127,
                    "incorrect value for apc[4].pcv[14], expected 127, is {}",
                    msg.apc[4].pcv[14]
                );
                assert_eq!(
                    msg.apc[4].pcv[15], -42,
                    "incorrect value for apc[4].pcv[15], expected -42, is {}",
                    msg.apc[4].pcv[15]
                );
                assert_eq!(
                    msg.apc[4].pcv[16], 86,
                    "incorrect value for apc[4].pcv[16], expected 86, is {}",
                    msg.apc[4].pcv[16]
                );
                assert_eq!(
                    msg.apc[4].pcv[17], 48,
                    "incorrect value for apc[4].pcv[17], expected 48, is {}",
                    msg.apc[4].pcv[17]
                );
                assert_eq!(
                    msg.apc[4].pcv[18], -53,
                    "incorrect value for apc[4].pcv[18], expected -53, is {}",
                    msg.apc[4].pcv[18]
                );
                assert_eq!(
                    msg.apc[4].pcv[19], -28,
                    "incorrect value for apc[4].pcv[19], expected -28, is {}",
                    msg.apc[4].pcv[19]
                );
                assert_eq!(
                    msg.apc[4].pcv[20], 99,
                    "incorrect value for apc[4].pcv[20], expected 99, is {}",
                    msg.apc[4].pcv[20]
                );
                assert_eq!(
                    msg.apc[4].sat_info, 147,
                    "incorrect value for apc[4].sat_info, expected 147, is {}",
                    msg.apc[4].sat_info
                );
                assert_eq!(
                    msg.apc[4].sid.code, 110,
                    "incorrect value for apc[4].sid.code, expected 110, is {}",
                    msg.apc[4].sid.code
                );
                assert_eq!(
                    msg.apc[4].sid.sat, 249,
                    "incorrect value for apc[4].sid.sat, expected 249, is {}",
                    msg.apc[4].sid.sat
                );
                assert_eq!(
                    msg.apc[4].svn, 41224,
                    "incorrect value for apc[4].svn, expected 41224, is {}",
                    msg.apc[4].svn
                );
                assert_eq!(
                    msg.apc[5].pco[0], -21881,
                    "incorrect value for apc[5].pco[0], expected -21881, is {}",
                    msg.apc[5].pco[0]
                );
                assert_eq!(
                    msg.apc[5].pco[1], -9942,
                    "incorrect value for apc[5].pco[1], expected -9942, is {}",
                    msg.apc[5].pco[1]
                );
                assert_eq!(
                    msg.apc[5].pco[2], -5689,
                    "incorrect value for apc[5].pco[2], expected -5689, is {}",
                    msg.apc[5].pco[2]
                );
                assert_eq!(
                    msg.apc[5].pcv[0], 42,
                    "incorrect value for apc[5].pcv[0], expected 42, is {}",
                    msg.apc[5].pcv[0]
                );
                assert_eq!(
                    msg.apc[5].pcv[1], -86,
                    "incorrect value for apc[5].pcv[1], expected -86, is {}",
                    msg.apc[5].pcv[1]
                );
                assert_eq!(
                    msg.apc[5].pcv[2], 78,
                    "incorrect value for apc[5].pcv[2], expected 78, is {}",
                    msg.apc[5].pcv[2]
                );
                assert_eq!(
                    msg.apc[5].pcv[3], -50,
                    "incorrect value for apc[5].pcv[3], expected -50, is {}",
                    msg.apc[5].pcv[3]
                );
                assert_eq!(
                    msg.apc[5].pcv[4], 41,
                    "incorrect value for apc[5].pcv[4], expected 41, is {}",
                    msg.apc[5].pcv[4]
                );
                assert_eq!(
                    msg.apc[5].pcv[5], 43,
                    "incorrect value for apc[5].pcv[5], expected 43, is {}",
                    msg.apc[5].pcv[5]
                );
                assert_eq!(
                    msg.apc[5].pcv[6], 81,
                    "incorrect value for apc[5].pcv[6], expected 81, is {}",
                    msg.apc[5].pcv[6]
                );
                assert_eq!(
                    msg.apc[5].pcv[7], -9,
                    "incorrect value for apc[5].pcv[7], expected -9, is {}",
                    msg.apc[5].pcv[7]
                );
                assert_eq!(
                    msg.apc[5].pcv[8], 99,
                    "incorrect value for apc[5].pcv[8], expected 99, is {}",
                    msg.apc[5].pcv[8]
                );
                assert_eq!(
                    msg.apc[5].pcv[9], -58,
                    "incorrect value for apc[5].pcv[9], expected -58, is {}",
                    msg.apc[5].pcv[9]
                );
                assert_eq!(
                    msg.apc[5].pcv[10], -112,
                    "incorrect value for apc[5].pcv[10], expected -112, is {}",
                    msg.apc[5].pcv[10]
                );
                assert_eq!(
                    msg.apc[5].pcv[11], 2,
                    "incorrect value for apc[5].pcv[11], expected 2, is {}",
                    msg.apc[5].pcv[11]
                );
                assert_eq!(
                    msg.apc[5].pcv[12], -124,
                    "incorrect value for apc[5].pcv[12], expected -124, is {}",
                    msg.apc[5].pcv[12]
                );
                assert_eq!(
                    msg.apc[5].pcv[13], 2,
                    "incorrect value for apc[5].pcv[13], expected 2, is {}",
                    msg.apc[5].pcv[13]
                );
                assert_eq!(
                    msg.apc[5].pcv[14], -32,
                    "incorrect value for apc[5].pcv[14], expected -32, is {}",
                    msg.apc[5].pcv[14]
                );
                assert_eq!(
                    msg.apc[5].pcv[15], -36,
                    "incorrect value for apc[5].pcv[15], expected -36, is {}",
                    msg.apc[5].pcv[15]
                );
                assert_eq!(
                    msg.apc[5].pcv[16], -108,
                    "incorrect value for apc[5].pcv[16], expected -108, is {}",
                    msg.apc[5].pcv[16]
                );
                assert_eq!(
                    msg.apc[5].pcv[17], 58,
                    "incorrect value for apc[5].pcv[17], expected 58, is {}",
                    msg.apc[5].pcv[17]
                );
                assert_eq!(
                    msg.apc[5].pcv[18], 85,
                    "incorrect value for apc[5].pcv[18], expected 85, is {}",
                    msg.apc[5].pcv[18]
                );
                assert_eq!(
                    msg.apc[5].pcv[19], -118,
                    "incorrect value for apc[5].pcv[19], expected -118, is {}",
                    msg.apc[5].pcv[19]
                );
                assert_eq!(
                    msg.apc[5].pcv[20], -46,
                    "incorrect value for apc[5].pcv[20], expected -46, is {}",
                    msg.apc[5].pcv[20]
                );
                assert_eq!(
                    msg.apc[5].sat_info, 159,
                    "incorrect value for apc[5].sat_info, expected 159, is {}",
                    msg.apc[5].sat_info
                );
                assert_eq!(
                    msg.apc[5].sid.code, 83,
                    "incorrect value for apc[5].sid.code, expected 83, is {}",
                    msg.apc[5].sid.code
                );
                assert_eq!(
                    msg.apc[5].sid.sat, 45,
                    "incorrect value for apc[5].sid.sat, expected 45, is {}",
                    msg.apc[5].sid.sat
                );
                assert_eq!(
                    msg.apc[5].svn, 64011,
                    "incorrect value for apc[5].svn, expected 64011, is {}",
                    msg.apc[5].svn
                );
                assert_eq!(
                    msg.apc[6].pco[0], -14290,
                    "incorrect value for apc[6].pco[0], expected -14290, is {}",
                    msg.apc[6].pco[0]
                );
                assert_eq!(
                    msg.apc[6].pco[1], 30340,
                    "incorrect value for apc[6].pco[1], expected 30340, is {}",
                    msg.apc[6].pco[1]
                );
                assert_eq!(
                    msg.apc[6].pco[2], 3569,
                    "incorrect value for apc[6].pco[2], expected 3569, is {}",
                    msg.apc[6].pco[2]
                );
                assert_eq!(
                    msg.apc[6].pcv[0], 37,
                    "incorrect value for apc[6].pcv[0], expected 37, is {}",
                    msg.apc[6].pcv[0]
                );
                assert_eq!(
                    msg.apc[6].pcv[1], 62,
                    "incorrect value for apc[6].pcv[1], expected 62, is {}",
                    msg.apc[6].pcv[1]
                );
                assert_eq!(
                    msg.apc[6].pcv[2], 107,
                    "incorrect value for apc[6].pcv[2], expected 107, is {}",
                    msg.apc[6].pcv[2]
                );
                assert_eq!(
                    msg.apc[6].pcv[3], -3,
                    "incorrect value for apc[6].pcv[3], expected -3, is {}",
                    msg.apc[6].pcv[3]
                );
                assert_eq!(
                    msg.apc[6].pcv[4], -66,
                    "incorrect value for apc[6].pcv[4], expected -66, is {}",
                    msg.apc[6].pcv[4]
                );
                assert_eq!(
                    msg.apc[6].pcv[5], -120,
                    "incorrect value for apc[6].pcv[5], expected -120, is {}",
                    msg.apc[6].pcv[5]
                );
                assert_eq!(
                    msg.apc[6].pcv[6], 66,
                    "incorrect value for apc[6].pcv[6], expected 66, is {}",
                    msg.apc[6].pcv[6]
                );
                assert_eq!(
                    msg.apc[6].pcv[7], 9,
                    "incorrect value for apc[6].pcv[7], expected 9, is {}",
                    msg.apc[6].pcv[7]
                );
                assert_eq!(
                    msg.apc[6].pcv[8], 84,
                    "incorrect value for apc[6].pcv[8], expected 84, is {}",
                    msg.apc[6].pcv[8]
                );
                assert_eq!(
                    msg.apc[6].pcv[9], -101,
                    "incorrect value for apc[6].pcv[9], expected -101, is {}",
                    msg.apc[6].pcv[9]
                );
                assert_eq!(
                    msg.apc[6].pcv[10], 86,
                    "incorrect value for apc[6].pcv[10], expected 86, is {}",
                    msg.apc[6].pcv[10]
                );
                assert_eq!(
                    msg.apc[6].pcv[11], -76,
                    "incorrect value for apc[6].pcv[11], expected -76, is {}",
                    msg.apc[6].pcv[11]
                );
                assert_eq!(
                    msg.apc[6].pcv[12], 41,
                    "incorrect value for apc[6].pcv[12], expected 41, is {}",
                    msg.apc[6].pcv[12]
                );
                assert_eq!(
                    msg.apc[6].pcv[13], -60,
                    "incorrect value for apc[6].pcv[13], expected -60, is {}",
                    msg.apc[6].pcv[13]
                );
                assert_eq!(
                    msg.apc[6].pcv[14], 40,
                    "incorrect value for apc[6].pcv[14], expected 40, is {}",
                    msg.apc[6].pcv[14]
                );
                assert_eq!(
                    msg.apc[6].pcv[15], 119,
                    "incorrect value for apc[6].pcv[15], expected 119, is {}",
                    msg.apc[6].pcv[15]
                );
                assert_eq!(
                    msg.apc[6].pcv[16], 101,
                    "incorrect value for apc[6].pcv[16], expected 101, is {}",
                    msg.apc[6].pcv[16]
                );
                assert_eq!(
                    msg.apc[6].pcv[17], -4,
                    "incorrect value for apc[6].pcv[17], expected -4, is {}",
                    msg.apc[6].pcv[17]
                );
                assert_eq!(
                    msg.apc[6].pcv[18], -33,
                    "incorrect value for apc[6].pcv[18], expected -33, is {}",
                    msg.apc[6].pcv[18]
                );
                assert_eq!(
                    msg.apc[6].pcv[19], -112,
                    "incorrect value for apc[6].pcv[19], expected -112, is {}",
                    msg.apc[6].pcv[19]
                );
                assert_eq!(
                    msg.apc[6].pcv[20], -103,
                    "incorrect value for apc[6].pcv[20], expected -103, is {}",
                    msg.apc[6].pcv[20]
                );
                assert_eq!(
                    msg.apc[6].sat_info, 7,
                    "incorrect value for apc[6].sat_info, expected 7, is {}",
                    msg.apc[6].sat_info
                );
                assert_eq!(
                    msg.apc[6].sid.code, 158,
                    "incorrect value for apc[6].sid.code, expected 158, is {}",
                    msg.apc[6].sid.code
                );
                assert_eq!(
                    msg.apc[6].sid.sat, 200,
                    "incorrect value for apc[6].sid.sat, expected 200, is {}",
                    msg.apc[6].sid.sat
                );
                assert_eq!(
                    msg.apc[6].svn, 17310,
                    "incorrect value for apc[6].svn, expected 17310, is {}",
                    msg.apc[6].svn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrSatelliteApcDep"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_satellite_apc_dep_a() {
    {
        let json_input = r#"{"crc":3378,"length":224,"msg_type":1540,"payload":"y6nwTgTVq/7W1AQIIR9QFQRp4SeLfJUwD9bFjSAhh5aUezGHYSdaFKnvL5mvI5GRe8ICZkqVX6vu+Qftqn1qnlO8tcIbVOKOe03Z+EPXgXKKGfAKOEw9odgWta4hDfzs5sSA1+/qs9ws1DksrTEkifjrYXCdixpzwB9Vf+RR/Nv5bpMIodfUtBlTkPcMG8etShcE72ff3Itbf9ZWMMvkYy1Tnwv6h6oq2cfpKqpOzikrUfdjxpAChALg3JQ6VYrSyJ4HnkMuyIR28Q0lPmv9vohCCVSbVrQpxCh3ZfzfkJk=","preamble":85,"sender":4920,"apc":[{"sid":{"sat":203,"code":169},"sat_info":240,"svn":1102,"pco":[-21547,-10498,1236],"pcv":[8,33,31,80,21,4,105,-31,39,-117,124,-107,48,15,-42,-59,-115,32,33,-121,-106]},{"sid":{"sat":148,"code":123},"sat_info":49,"svn":24967,"pco":[23079,-22252,12271],"pcv":[-103,-81,35,-111,-111,123,-62,2,102,74,-107,95,-85,-18,-7,7,-19,-86,125,106,-98]},{"sid":{"sat":83,"code":188},"sat_info":181,"svn":7106,"pco":[-7596,31630,-9907],"pcv":[-8,67,-41,-127,114,-118,25,-16,10,56,76,61,-95,-40,22,-75,-82,33,13,-4,-20]},{"sid":{"sat":230,"code":196},"sat_info":128,"svn":61399,"pco":[-19478,11484,14804],"pcv":[44,-83,49,36,-119,-8,-21,97,112,-99,-117,26,115,-64,31,85,127,-28,81,-4,-37]},{"sid":{"sat":249,"code":110},"sat_info":147,"svn":41224,"pco":[-11049,6580,-28589],"pcv":[-9,12,27,-57,-83,74,23,4,-17,103,-33,-36,-117,91,127,-42,86,48,-53,-28,99]},{"sid":{"sat":45,"code":83},"sat_info":159,"svn":64011,"pco":[-21881,-9942,-5689],"pcv":[42,-86,78,-50,41,43,81,-9,99,-58,-112,2,-124,2,-32,-36,-108,58,85,-118,-46]},{"sid":{"sat":200,"code":158},"sat_info":7,"svn":17310,"pco":[-14290,30340,3569],"pcv":[37,62,107,-3,-66,-120,66,9,84,-101,86,-76,41,-60,40,119,101,-4,-33,-112,-103]}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrSatelliteApcDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x604,
                    "Incorrect message type, expected 0x604, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1338,
                    "incorrect sender id, expected 0x1338, is {sender_id}"
                );
                assert_eq!(
                    msg.apc[0].pco[0], -21547,
                    "incorrect value for apc[0].pco[0], expected -21547, is {}",
                    msg.apc[0].pco[0]
                );
                assert_eq!(
                    msg.apc[0].pco[1], -10498,
                    "incorrect value for apc[0].pco[1], expected -10498, is {}",
                    msg.apc[0].pco[1]
                );
                assert_eq!(
                    msg.apc[0].pco[2], 1236,
                    "incorrect value for apc[0].pco[2], expected 1236, is {}",
                    msg.apc[0].pco[2]
                );
                assert_eq!(
                    msg.apc[0].pcv[0], 8,
                    "incorrect value for apc[0].pcv[0], expected 8, is {}",
                    msg.apc[0].pcv[0]
                );
                assert_eq!(
                    msg.apc[0].pcv[1], 33,
                    "incorrect value for apc[0].pcv[1], expected 33, is {}",
                    msg.apc[0].pcv[1]
                );
                assert_eq!(
                    msg.apc[0].pcv[2], 31,
                    "incorrect value for apc[0].pcv[2], expected 31, is {}",
                    msg.apc[0].pcv[2]
                );
                assert_eq!(
                    msg.apc[0].pcv[3], 80,
                    "incorrect value for apc[0].pcv[3], expected 80, is {}",
                    msg.apc[0].pcv[3]
                );
                assert_eq!(
                    msg.apc[0].pcv[4], 21,
                    "incorrect value for apc[0].pcv[4], expected 21, is {}",
                    msg.apc[0].pcv[4]
                );
                assert_eq!(
                    msg.apc[0].pcv[5], 4,
                    "incorrect value for apc[0].pcv[5], expected 4, is {}",
                    msg.apc[0].pcv[5]
                );
                assert_eq!(
                    msg.apc[0].pcv[6], 105,
                    "incorrect value for apc[0].pcv[6], expected 105, is {}",
                    msg.apc[0].pcv[6]
                );
                assert_eq!(
                    msg.apc[0].pcv[7], -31,
                    "incorrect value for apc[0].pcv[7], expected -31, is {}",
                    msg.apc[0].pcv[7]
                );
                assert_eq!(
                    msg.apc[0].pcv[8], 39,
                    "incorrect value for apc[0].pcv[8], expected 39, is {}",
                    msg.apc[0].pcv[8]
                );
                assert_eq!(
                    msg.apc[0].pcv[9], -117,
                    "incorrect value for apc[0].pcv[9], expected -117, is {}",
                    msg.apc[0].pcv[9]
                );
                assert_eq!(
                    msg.apc[0].pcv[10], 124,
                    "incorrect value for apc[0].pcv[10], expected 124, is {}",
                    msg.apc[0].pcv[10]
                );
                assert_eq!(
                    msg.apc[0].pcv[11], -107,
                    "incorrect value for apc[0].pcv[11], expected -107, is {}",
                    msg.apc[0].pcv[11]
                );
                assert_eq!(
                    msg.apc[0].pcv[12], 48,
                    "incorrect value for apc[0].pcv[12], expected 48, is {}",
                    msg.apc[0].pcv[12]
                );
                assert_eq!(
                    msg.apc[0].pcv[13], 15,
                    "incorrect value for apc[0].pcv[13], expected 15, is {}",
                    msg.apc[0].pcv[13]
                );
                assert_eq!(
                    msg.apc[0].pcv[14], -42,
                    "incorrect value for apc[0].pcv[14], expected -42, is {}",
                    msg.apc[0].pcv[14]
                );
                assert_eq!(
                    msg.apc[0].pcv[15], -59,
                    "incorrect value for apc[0].pcv[15], expected -59, is {}",
                    msg.apc[0].pcv[15]
                );
                assert_eq!(
                    msg.apc[0].pcv[16], -115,
                    "incorrect value for apc[0].pcv[16], expected -115, is {}",
                    msg.apc[0].pcv[16]
                );
                assert_eq!(
                    msg.apc[0].pcv[17], 32,
                    "incorrect value for apc[0].pcv[17], expected 32, is {}",
                    msg.apc[0].pcv[17]
                );
                assert_eq!(
                    msg.apc[0].pcv[18], 33,
                    "incorrect value for apc[0].pcv[18], expected 33, is {}",
                    msg.apc[0].pcv[18]
                );
                assert_eq!(
                    msg.apc[0].pcv[19], -121,
                    "incorrect value for apc[0].pcv[19], expected -121, is {}",
                    msg.apc[0].pcv[19]
                );
                assert_eq!(
                    msg.apc[0].pcv[20], -106,
                    "incorrect value for apc[0].pcv[20], expected -106, is {}",
                    msg.apc[0].pcv[20]
                );
                assert_eq!(
                    msg.apc[0].sat_info, 240,
                    "incorrect value for apc[0].sat_info, expected 240, is {}",
                    msg.apc[0].sat_info
                );
                assert_eq!(
                    msg.apc[0].sid.code, 169,
                    "incorrect value for apc[0].sid.code, expected 169, is {}",
                    msg.apc[0].sid.code
                );
                assert_eq!(
                    msg.apc[0].sid.sat, 203,
                    "incorrect value for apc[0].sid.sat, expected 203, is {}",
                    msg.apc[0].sid.sat
                );
                assert_eq!(
                    msg.apc[0].svn, 1102,
                    "incorrect value for apc[0].svn, expected 1102, is {}",
                    msg.apc[0].svn
                );
                assert_eq!(
                    msg.apc[1].pco[0], 23079,
                    "incorrect value for apc[1].pco[0], expected 23079, is {}",
                    msg.apc[1].pco[0]
                );
                assert_eq!(
                    msg.apc[1].pco[1], -22252,
                    "incorrect value for apc[1].pco[1], expected -22252, is {}",
                    msg.apc[1].pco[1]
                );
                assert_eq!(
                    msg.apc[1].pco[2], 12271,
                    "incorrect value for apc[1].pco[2], expected 12271, is {}",
                    msg.apc[1].pco[2]
                );
                assert_eq!(
                    msg.apc[1].pcv[0], -103,
                    "incorrect value for apc[1].pcv[0], expected -103, is {}",
                    msg.apc[1].pcv[0]
                );
                assert_eq!(
                    msg.apc[1].pcv[1], -81,
                    "incorrect value for apc[1].pcv[1], expected -81, is {}",
                    msg.apc[1].pcv[1]
                );
                assert_eq!(
                    msg.apc[1].pcv[2], 35,
                    "incorrect value for apc[1].pcv[2], expected 35, is {}",
                    msg.apc[1].pcv[2]
                );
                assert_eq!(
                    msg.apc[1].pcv[3], -111,
                    "incorrect value for apc[1].pcv[3], expected -111, is {}",
                    msg.apc[1].pcv[3]
                );
                assert_eq!(
                    msg.apc[1].pcv[4], -111,
                    "incorrect value for apc[1].pcv[4], expected -111, is {}",
                    msg.apc[1].pcv[4]
                );
                assert_eq!(
                    msg.apc[1].pcv[5], 123,
                    "incorrect value for apc[1].pcv[5], expected 123, is {}",
                    msg.apc[1].pcv[5]
                );
                assert_eq!(
                    msg.apc[1].pcv[6], -62,
                    "incorrect value for apc[1].pcv[6], expected -62, is {}",
                    msg.apc[1].pcv[6]
                );
                assert_eq!(
                    msg.apc[1].pcv[7], 2,
                    "incorrect value for apc[1].pcv[7], expected 2, is {}",
                    msg.apc[1].pcv[7]
                );
                assert_eq!(
                    msg.apc[1].pcv[8], 102,
                    "incorrect value for apc[1].pcv[8], expected 102, is {}",
                    msg.apc[1].pcv[8]
                );
                assert_eq!(
                    msg.apc[1].pcv[9], 74,
                    "incorrect value for apc[1].pcv[9], expected 74, is {}",
                    msg.apc[1].pcv[9]
                );
                assert_eq!(
                    msg.apc[1].pcv[10], -107,
                    "incorrect value for apc[1].pcv[10], expected -107, is {}",
                    msg.apc[1].pcv[10]
                );
                assert_eq!(
                    msg.apc[1].pcv[11], 95,
                    "incorrect value for apc[1].pcv[11], expected 95, is {}",
                    msg.apc[1].pcv[11]
                );
                assert_eq!(
                    msg.apc[1].pcv[12], -85,
                    "incorrect value for apc[1].pcv[12], expected -85, is {}",
                    msg.apc[1].pcv[12]
                );
                assert_eq!(
                    msg.apc[1].pcv[13], -18,
                    "incorrect value for apc[1].pcv[13], expected -18, is {}",
                    msg.apc[1].pcv[13]
                );
                assert_eq!(
                    msg.apc[1].pcv[14], -7,
                    "incorrect value for apc[1].pcv[14], expected -7, is {}",
                    msg.apc[1].pcv[14]
                );
                assert_eq!(
                    msg.apc[1].pcv[15], 7,
                    "incorrect value for apc[1].pcv[15], expected 7, is {}",
                    msg.apc[1].pcv[15]
                );
                assert_eq!(
                    msg.apc[1].pcv[16], -19,
                    "incorrect value for apc[1].pcv[16], expected -19, is {}",
                    msg.apc[1].pcv[16]
                );
                assert_eq!(
                    msg.apc[1].pcv[17], -86,
                    "incorrect value for apc[1].pcv[17], expected -86, is {}",
                    msg.apc[1].pcv[17]
                );
                assert_eq!(
                    msg.apc[1].pcv[18], 125,
                    "incorrect value for apc[1].pcv[18], expected 125, is {}",
                    msg.apc[1].pcv[18]
                );
                assert_eq!(
                    msg.apc[1].pcv[19], 106,
                    "incorrect value for apc[1].pcv[19], expected 106, is {}",
                    msg.apc[1].pcv[19]
                );
                assert_eq!(
                    msg.apc[1].pcv[20], -98,
                    "incorrect value for apc[1].pcv[20], expected -98, is {}",
                    msg.apc[1].pcv[20]
                );
                assert_eq!(
                    msg.apc[1].sat_info, 49,
                    "incorrect value for apc[1].sat_info, expected 49, is {}",
                    msg.apc[1].sat_info
                );
                assert_eq!(
                    msg.apc[1].sid.code, 123,
                    "incorrect value for apc[1].sid.code, expected 123, is {}",
                    msg.apc[1].sid.code
                );
                assert_eq!(
                    msg.apc[1].sid.sat, 148,
                    "incorrect value for apc[1].sid.sat, expected 148, is {}",
                    msg.apc[1].sid.sat
                );
                assert_eq!(
                    msg.apc[1].svn, 24967,
                    "incorrect value for apc[1].svn, expected 24967, is {}",
                    msg.apc[1].svn
                );
                assert_eq!(
                    msg.apc[2].pco[0], -7596,
                    "incorrect value for apc[2].pco[0], expected -7596, is {}",
                    msg.apc[2].pco[0]
                );
                assert_eq!(
                    msg.apc[2].pco[1], 31630,
                    "incorrect value for apc[2].pco[1], expected 31630, is {}",
                    msg.apc[2].pco[1]
                );
                assert_eq!(
                    msg.apc[2].pco[2], -9907,
                    "incorrect value for apc[2].pco[2], expected -9907, is {}",
                    msg.apc[2].pco[2]
                );
                assert_eq!(
                    msg.apc[2].pcv[0], -8,
                    "incorrect value for apc[2].pcv[0], expected -8, is {}",
                    msg.apc[2].pcv[0]
                );
                assert_eq!(
                    msg.apc[2].pcv[1], 67,
                    "incorrect value for apc[2].pcv[1], expected 67, is {}",
                    msg.apc[2].pcv[1]
                );
                assert_eq!(
                    msg.apc[2].pcv[2], -41,
                    "incorrect value for apc[2].pcv[2], expected -41, is {}",
                    msg.apc[2].pcv[2]
                );
                assert_eq!(
                    msg.apc[2].pcv[3], -127,
                    "incorrect value for apc[2].pcv[3], expected -127, is {}",
                    msg.apc[2].pcv[3]
                );
                assert_eq!(
                    msg.apc[2].pcv[4], 114,
                    "incorrect value for apc[2].pcv[4], expected 114, is {}",
                    msg.apc[2].pcv[4]
                );
                assert_eq!(
                    msg.apc[2].pcv[5], -118,
                    "incorrect value for apc[2].pcv[5], expected -118, is {}",
                    msg.apc[2].pcv[5]
                );
                assert_eq!(
                    msg.apc[2].pcv[6], 25,
                    "incorrect value for apc[2].pcv[6], expected 25, is {}",
                    msg.apc[2].pcv[6]
                );
                assert_eq!(
                    msg.apc[2].pcv[7], -16,
                    "incorrect value for apc[2].pcv[7], expected -16, is {}",
                    msg.apc[2].pcv[7]
                );
                assert_eq!(
                    msg.apc[2].pcv[8], 10,
                    "incorrect value for apc[2].pcv[8], expected 10, is {}",
                    msg.apc[2].pcv[8]
                );
                assert_eq!(
                    msg.apc[2].pcv[9], 56,
                    "incorrect value for apc[2].pcv[9], expected 56, is {}",
                    msg.apc[2].pcv[9]
                );
                assert_eq!(
                    msg.apc[2].pcv[10], 76,
                    "incorrect value for apc[2].pcv[10], expected 76, is {}",
                    msg.apc[2].pcv[10]
                );
                assert_eq!(
                    msg.apc[2].pcv[11], 61,
                    "incorrect value for apc[2].pcv[11], expected 61, is {}",
                    msg.apc[2].pcv[11]
                );
                assert_eq!(
                    msg.apc[2].pcv[12], -95,
                    "incorrect value for apc[2].pcv[12], expected -95, is {}",
                    msg.apc[2].pcv[12]
                );
                assert_eq!(
                    msg.apc[2].pcv[13], -40,
                    "incorrect value for apc[2].pcv[13], expected -40, is {}",
                    msg.apc[2].pcv[13]
                );
                assert_eq!(
                    msg.apc[2].pcv[14], 22,
                    "incorrect value for apc[2].pcv[14], expected 22, is {}",
                    msg.apc[2].pcv[14]
                );
                assert_eq!(
                    msg.apc[2].pcv[15], -75,
                    "incorrect value for apc[2].pcv[15], expected -75, is {}",
                    msg.apc[2].pcv[15]
                );
                assert_eq!(
                    msg.apc[2].pcv[16], -82,
                    "incorrect value for apc[2].pcv[16], expected -82, is {}",
                    msg.apc[2].pcv[16]
                );
                assert_eq!(
                    msg.apc[2].pcv[17], 33,
                    "incorrect value for apc[2].pcv[17], expected 33, is {}",
                    msg.apc[2].pcv[17]
                );
                assert_eq!(
                    msg.apc[2].pcv[18], 13,
                    "incorrect value for apc[2].pcv[18], expected 13, is {}",
                    msg.apc[2].pcv[18]
                );
                assert_eq!(
                    msg.apc[2].pcv[19], -4,
                    "incorrect value for apc[2].pcv[19], expected -4, is {}",
                    msg.apc[2].pcv[19]
                );
                assert_eq!(
                    msg.apc[2].pcv[20], -20,
                    "incorrect value for apc[2].pcv[20], expected -20, is {}",
                    msg.apc[2].pcv[20]
                );
                assert_eq!(
                    msg.apc[2].sat_info, 181,
                    "incorrect value for apc[2].sat_info, expected 181, is {}",
                    msg.apc[2].sat_info
                );
                assert_eq!(
                    msg.apc[2].sid.code, 188,
                    "incorrect value for apc[2].sid.code, expected 188, is {}",
                    msg.apc[2].sid.code
                );
                assert_eq!(
                    msg.apc[2].sid.sat, 83,
                    "incorrect value for apc[2].sid.sat, expected 83, is {}",
                    msg.apc[2].sid.sat
                );
                assert_eq!(
                    msg.apc[2].svn, 7106,
                    "incorrect value for apc[2].svn, expected 7106, is {}",
                    msg.apc[2].svn
                );
                assert_eq!(
                    msg.apc[3].pco[0], -19478,
                    "incorrect value for apc[3].pco[0], expected -19478, is {}",
                    msg.apc[3].pco[0]
                );
                assert_eq!(
                    msg.apc[3].pco[1], 11484,
                    "incorrect value for apc[3].pco[1], expected 11484, is {}",
                    msg.apc[3].pco[1]
                );
                assert_eq!(
                    msg.apc[3].pco[2], 14804,
                    "incorrect value for apc[3].pco[2], expected 14804, is {}",
                    msg.apc[3].pco[2]
                );
                assert_eq!(
                    msg.apc[3].pcv[0], 44,
                    "incorrect value for apc[3].pcv[0], expected 44, is {}",
                    msg.apc[3].pcv[0]
                );
                assert_eq!(
                    msg.apc[3].pcv[1], -83,
                    "incorrect value for apc[3].pcv[1], expected -83, is {}",
                    msg.apc[3].pcv[1]
                );
                assert_eq!(
                    msg.apc[3].pcv[2], 49,
                    "incorrect value for apc[3].pcv[2], expected 49, is {}",
                    msg.apc[3].pcv[2]
                );
                assert_eq!(
                    msg.apc[3].pcv[3], 36,
                    "incorrect value for apc[3].pcv[3], expected 36, is {}",
                    msg.apc[3].pcv[3]
                );
                assert_eq!(
                    msg.apc[3].pcv[4], -119,
                    "incorrect value for apc[3].pcv[4], expected -119, is {}",
                    msg.apc[3].pcv[4]
                );
                assert_eq!(
                    msg.apc[3].pcv[5], -8,
                    "incorrect value for apc[3].pcv[5], expected -8, is {}",
                    msg.apc[3].pcv[5]
                );
                assert_eq!(
                    msg.apc[3].pcv[6], -21,
                    "incorrect value for apc[3].pcv[6], expected -21, is {}",
                    msg.apc[3].pcv[6]
                );
                assert_eq!(
                    msg.apc[3].pcv[7], 97,
                    "incorrect value for apc[3].pcv[7], expected 97, is {}",
                    msg.apc[3].pcv[7]
                );
                assert_eq!(
                    msg.apc[3].pcv[8], 112,
                    "incorrect value for apc[3].pcv[8], expected 112, is {}",
                    msg.apc[3].pcv[8]
                );
                assert_eq!(
                    msg.apc[3].pcv[9], -99,
                    "incorrect value for apc[3].pcv[9], expected -99, is {}",
                    msg.apc[3].pcv[9]
                );
                assert_eq!(
                    msg.apc[3].pcv[10], -117,
                    "incorrect value for apc[3].pcv[10], expected -117, is {}",
                    msg.apc[3].pcv[10]
                );
                assert_eq!(
                    msg.apc[3].pcv[11], 26,
                    "incorrect value for apc[3].pcv[11], expected 26, is {}",
                    msg.apc[3].pcv[11]
                );
                assert_eq!(
                    msg.apc[3].pcv[12], 115,
                    "incorrect value for apc[3].pcv[12], expected 115, is {}",
                    msg.apc[3].pcv[12]
                );
                assert_eq!(
                    msg.apc[3].pcv[13], -64,
                    "incorrect value for apc[3].pcv[13], expected -64, is {}",
                    msg.apc[3].pcv[13]
                );
                assert_eq!(
                    msg.apc[3].pcv[14], 31,
                    "incorrect value for apc[3].pcv[14], expected 31, is {}",
                    msg.apc[3].pcv[14]
                );
                assert_eq!(
                    msg.apc[3].pcv[15], 85,
                    "incorrect value for apc[3].pcv[15], expected 85, is {}",
                    msg.apc[3].pcv[15]
                );
                assert_eq!(
                    msg.apc[3].pcv[16], 127,
                    "incorrect value for apc[3].pcv[16], expected 127, is {}",
                    msg.apc[3].pcv[16]
                );
                assert_eq!(
                    msg.apc[3].pcv[17], -28,
                    "incorrect value for apc[3].pcv[17], expected -28, is {}",
                    msg.apc[3].pcv[17]
                );
                assert_eq!(
                    msg.apc[3].pcv[18], 81,
                    "incorrect value for apc[3].pcv[18], expected 81, is {}",
                    msg.apc[3].pcv[18]
                );
                assert_eq!(
                    msg.apc[3].pcv[19], -4,
                    "incorrect value for apc[3].pcv[19], expected -4, is {}",
                    msg.apc[3].pcv[19]
                );
                assert_eq!(
                    msg.apc[3].pcv[20], -37,
                    "incorrect value for apc[3].pcv[20], expected -37, is {}",
                    msg.apc[3].pcv[20]
                );
                assert_eq!(
                    msg.apc[3].sat_info, 128,
                    "incorrect value for apc[3].sat_info, expected 128, is {}",
                    msg.apc[3].sat_info
                );
                assert_eq!(
                    msg.apc[3].sid.code, 196,
                    "incorrect value for apc[3].sid.code, expected 196, is {}",
                    msg.apc[3].sid.code
                );
                assert_eq!(
                    msg.apc[3].sid.sat, 230,
                    "incorrect value for apc[3].sid.sat, expected 230, is {}",
                    msg.apc[3].sid.sat
                );
                assert_eq!(
                    msg.apc[3].svn, 61399,
                    "incorrect value for apc[3].svn, expected 61399, is {}",
                    msg.apc[3].svn
                );
                assert_eq!(
                    msg.apc[4].pco[0], -11049,
                    "incorrect value for apc[4].pco[0], expected -11049, is {}",
                    msg.apc[4].pco[0]
                );
                assert_eq!(
                    msg.apc[4].pco[1], 6580,
                    "incorrect value for apc[4].pco[1], expected 6580, is {}",
                    msg.apc[4].pco[1]
                );
                assert_eq!(
                    msg.apc[4].pco[2], -28589,
                    "incorrect value for apc[4].pco[2], expected -28589, is {}",
                    msg.apc[4].pco[2]
                );
                assert_eq!(
                    msg.apc[4].pcv[0], -9,
                    "incorrect value for apc[4].pcv[0], expected -9, is {}",
                    msg.apc[4].pcv[0]
                );
                assert_eq!(
                    msg.apc[4].pcv[1], 12,
                    "incorrect value for apc[4].pcv[1], expected 12, is {}",
                    msg.apc[4].pcv[1]
                );
                assert_eq!(
                    msg.apc[4].pcv[2], 27,
                    "incorrect value for apc[4].pcv[2], expected 27, is {}",
                    msg.apc[4].pcv[2]
                );
                assert_eq!(
                    msg.apc[4].pcv[3], -57,
                    "incorrect value for apc[4].pcv[3], expected -57, is {}",
                    msg.apc[4].pcv[3]
                );
                assert_eq!(
                    msg.apc[4].pcv[4], -83,
                    "incorrect value for apc[4].pcv[4], expected -83, is {}",
                    msg.apc[4].pcv[4]
                );
                assert_eq!(
                    msg.apc[4].pcv[5], 74,
                    "incorrect value for apc[4].pcv[5], expected 74, is {}",
                    msg.apc[4].pcv[5]
                );
                assert_eq!(
                    msg.apc[4].pcv[6], 23,
                    "incorrect value for apc[4].pcv[6], expected 23, is {}",
                    msg.apc[4].pcv[6]
                );
                assert_eq!(
                    msg.apc[4].pcv[7], 4,
                    "incorrect value for apc[4].pcv[7], expected 4, is {}",
                    msg.apc[4].pcv[7]
                );
                assert_eq!(
                    msg.apc[4].pcv[8], -17,
                    "incorrect value for apc[4].pcv[8], expected -17, is {}",
                    msg.apc[4].pcv[8]
                );
                assert_eq!(
                    msg.apc[4].pcv[9], 103,
                    "incorrect value for apc[4].pcv[9], expected 103, is {}",
                    msg.apc[4].pcv[9]
                );
                assert_eq!(
                    msg.apc[4].pcv[10], -33,
                    "incorrect value for apc[4].pcv[10], expected -33, is {}",
                    msg.apc[4].pcv[10]
                );
                assert_eq!(
                    msg.apc[4].pcv[11], -36,
                    "incorrect value for apc[4].pcv[11], expected -36, is {}",
                    msg.apc[4].pcv[11]
                );
                assert_eq!(
                    msg.apc[4].pcv[12], -117,
                    "incorrect value for apc[4].pcv[12], expected -117, is {}",
                    msg.apc[4].pcv[12]
                );
                assert_eq!(
                    msg.apc[4].pcv[13], 91,
                    "incorrect value for apc[4].pcv[13], expected 91, is {}",
                    msg.apc[4].pcv[13]
                );
                assert_eq!(
                    msg.apc[4].pcv[14], 127,
                    "incorrect value for apc[4].pcv[14], expected 127, is {}",
                    msg.apc[4].pcv[14]
                );
                assert_eq!(
                    msg.apc[4].pcv[15], -42,
                    "incorrect value for apc[4].pcv[15], expected -42, is {}",
                    msg.apc[4].pcv[15]
                );
                assert_eq!(
                    msg.apc[4].pcv[16], 86,
                    "incorrect value for apc[4].pcv[16], expected 86, is {}",
                    msg.apc[4].pcv[16]
                );
                assert_eq!(
                    msg.apc[4].pcv[17], 48,
                    "incorrect value for apc[4].pcv[17], expected 48, is {}",
                    msg.apc[4].pcv[17]
                );
                assert_eq!(
                    msg.apc[4].pcv[18], -53,
                    "incorrect value for apc[4].pcv[18], expected -53, is {}",
                    msg.apc[4].pcv[18]
                );
                assert_eq!(
                    msg.apc[4].pcv[19], -28,
                    "incorrect value for apc[4].pcv[19], expected -28, is {}",
                    msg.apc[4].pcv[19]
                );
                assert_eq!(
                    msg.apc[4].pcv[20], 99,
                    "incorrect value for apc[4].pcv[20], expected 99, is {}",
                    msg.apc[4].pcv[20]
                );
                assert_eq!(
                    msg.apc[4].sat_info, 147,
                    "incorrect value for apc[4].sat_info, expected 147, is {}",
                    msg.apc[4].sat_info
                );
                assert_eq!(
                    msg.apc[4].sid.code, 110,
                    "incorrect value for apc[4].sid.code, expected 110, is {}",
                    msg.apc[4].sid.code
                );
                assert_eq!(
                    msg.apc[4].sid.sat, 249,
                    "incorrect value for apc[4].sid.sat, expected 249, is {}",
                    msg.apc[4].sid.sat
                );
                assert_eq!(
                    msg.apc[4].svn, 41224,
                    "incorrect value for apc[4].svn, expected 41224, is {}",
                    msg.apc[4].svn
                );
                assert_eq!(
                    msg.apc[5].pco[0], -21881,
                    "incorrect value for apc[5].pco[0], expected -21881, is {}",
                    msg.apc[5].pco[0]
                );
                assert_eq!(
                    msg.apc[5].pco[1], -9942,
                    "incorrect value for apc[5].pco[1], expected -9942, is {}",
                    msg.apc[5].pco[1]
                );
                assert_eq!(
                    msg.apc[5].pco[2], -5689,
                    "incorrect value for apc[5].pco[2], expected -5689, is {}",
                    msg.apc[5].pco[2]
                );
                assert_eq!(
                    msg.apc[5].pcv[0], 42,
                    "incorrect value for apc[5].pcv[0], expected 42, is {}",
                    msg.apc[5].pcv[0]
                );
                assert_eq!(
                    msg.apc[5].pcv[1], -86,
                    "incorrect value for apc[5].pcv[1], expected -86, is {}",
                    msg.apc[5].pcv[1]
                );
                assert_eq!(
                    msg.apc[5].pcv[2], 78,
                    "incorrect value for apc[5].pcv[2], expected 78, is {}",
                    msg.apc[5].pcv[2]
                );
                assert_eq!(
                    msg.apc[5].pcv[3], -50,
                    "incorrect value for apc[5].pcv[3], expected -50, is {}",
                    msg.apc[5].pcv[3]
                );
                assert_eq!(
                    msg.apc[5].pcv[4], 41,
                    "incorrect value for apc[5].pcv[4], expected 41, is {}",
                    msg.apc[5].pcv[4]
                );
                assert_eq!(
                    msg.apc[5].pcv[5], 43,
                    "incorrect value for apc[5].pcv[5], expected 43, is {}",
                    msg.apc[5].pcv[5]
                );
                assert_eq!(
                    msg.apc[5].pcv[6], 81,
                    "incorrect value for apc[5].pcv[6], expected 81, is {}",
                    msg.apc[5].pcv[6]
                );
                assert_eq!(
                    msg.apc[5].pcv[7], -9,
                    "incorrect value for apc[5].pcv[7], expected -9, is {}",
                    msg.apc[5].pcv[7]
                );
                assert_eq!(
                    msg.apc[5].pcv[8], 99,
                    "incorrect value for apc[5].pcv[8], expected 99, is {}",
                    msg.apc[5].pcv[8]
                );
                assert_eq!(
                    msg.apc[5].pcv[9], -58,
                    "incorrect value for apc[5].pcv[9], expected -58, is {}",
                    msg.apc[5].pcv[9]
                );
                assert_eq!(
                    msg.apc[5].pcv[10], -112,
                    "incorrect value for apc[5].pcv[10], expected -112, is {}",
                    msg.apc[5].pcv[10]
                );
                assert_eq!(
                    msg.apc[5].pcv[11], 2,
                    "incorrect value for apc[5].pcv[11], expected 2, is {}",
                    msg.apc[5].pcv[11]
                );
                assert_eq!(
                    msg.apc[5].pcv[12], -124,
                    "incorrect value for apc[5].pcv[12], expected -124, is {}",
                    msg.apc[5].pcv[12]
                );
                assert_eq!(
                    msg.apc[5].pcv[13], 2,
                    "incorrect value for apc[5].pcv[13], expected 2, is {}",
                    msg.apc[5].pcv[13]
                );
                assert_eq!(
                    msg.apc[5].pcv[14], -32,
                    "incorrect value for apc[5].pcv[14], expected -32, is {}",
                    msg.apc[5].pcv[14]
                );
                assert_eq!(
                    msg.apc[5].pcv[15], -36,
                    "incorrect value for apc[5].pcv[15], expected -36, is {}",
                    msg.apc[5].pcv[15]
                );
                assert_eq!(
                    msg.apc[5].pcv[16], -108,
                    "incorrect value for apc[5].pcv[16], expected -108, is {}",
                    msg.apc[5].pcv[16]
                );
                assert_eq!(
                    msg.apc[5].pcv[17], 58,
                    "incorrect value for apc[5].pcv[17], expected 58, is {}",
                    msg.apc[5].pcv[17]
                );
                assert_eq!(
                    msg.apc[5].pcv[18], 85,
                    "incorrect value for apc[5].pcv[18], expected 85, is {}",
                    msg.apc[5].pcv[18]
                );
                assert_eq!(
                    msg.apc[5].pcv[19], -118,
                    "incorrect value for apc[5].pcv[19], expected -118, is {}",
                    msg.apc[5].pcv[19]
                );
                assert_eq!(
                    msg.apc[5].pcv[20], -46,
                    "incorrect value for apc[5].pcv[20], expected -46, is {}",
                    msg.apc[5].pcv[20]
                );
                assert_eq!(
                    msg.apc[5].sat_info, 159,
                    "incorrect value for apc[5].sat_info, expected 159, is {}",
                    msg.apc[5].sat_info
                );
                assert_eq!(
                    msg.apc[5].sid.code, 83,
                    "incorrect value for apc[5].sid.code, expected 83, is {}",
                    msg.apc[5].sid.code
                );
                assert_eq!(
                    msg.apc[5].sid.sat, 45,
                    "incorrect value for apc[5].sid.sat, expected 45, is {}",
                    msg.apc[5].sid.sat
                );
                assert_eq!(
                    msg.apc[5].svn, 64011,
                    "incorrect value for apc[5].svn, expected 64011, is {}",
                    msg.apc[5].svn
                );
                assert_eq!(
                    msg.apc[6].pco[0], -14290,
                    "incorrect value for apc[6].pco[0], expected -14290, is {}",
                    msg.apc[6].pco[0]
                );
                assert_eq!(
                    msg.apc[6].pco[1], 30340,
                    "incorrect value for apc[6].pco[1], expected 30340, is {}",
                    msg.apc[6].pco[1]
                );
                assert_eq!(
                    msg.apc[6].pco[2], 3569,
                    "incorrect value for apc[6].pco[2], expected 3569, is {}",
                    msg.apc[6].pco[2]
                );
                assert_eq!(
                    msg.apc[6].pcv[0], 37,
                    "incorrect value for apc[6].pcv[0], expected 37, is {}",
                    msg.apc[6].pcv[0]
                );
                assert_eq!(
                    msg.apc[6].pcv[1], 62,
                    "incorrect value for apc[6].pcv[1], expected 62, is {}",
                    msg.apc[6].pcv[1]
                );
                assert_eq!(
                    msg.apc[6].pcv[2], 107,
                    "incorrect value for apc[6].pcv[2], expected 107, is {}",
                    msg.apc[6].pcv[2]
                );
                assert_eq!(
                    msg.apc[6].pcv[3], -3,
                    "incorrect value for apc[6].pcv[3], expected -3, is {}",
                    msg.apc[6].pcv[3]
                );
                assert_eq!(
                    msg.apc[6].pcv[4], -66,
                    "incorrect value for apc[6].pcv[4], expected -66, is {}",
                    msg.apc[6].pcv[4]
                );
                assert_eq!(
                    msg.apc[6].pcv[5], -120,
                    "incorrect value for apc[6].pcv[5], expected -120, is {}",
                    msg.apc[6].pcv[5]
                );
                assert_eq!(
                    msg.apc[6].pcv[6], 66,
                    "incorrect value for apc[6].pcv[6], expected 66, is {}",
                    msg.apc[6].pcv[6]
                );
                assert_eq!(
                    msg.apc[6].pcv[7], 9,
                    "incorrect value for apc[6].pcv[7], expected 9, is {}",
                    msg.apc[6].pcv[7]
                );
                assert_eq!(
                    msg.apc[6].pcv[8], 84,
                    "incorrect value for apc[6].pcv[8], expected 84, is {}",
                    msg.apc[6].pcv[8]
                );
                assert_eq!(
                    msg.apc[6].pcv[9], -101,
                    "incorrect value for apc[6].pcv[9], expected -101, is {}",
                    msg.apc[6].pcv[9]
                );
                assert_eq!(
                    msg.apc[6].pcv[10], 86,
                    "incorrect value for apc[6].pcv[10], expected 86, is {}",
                    msg.apc[6].pcv[10]
                );
                assert_eq!(
                    msg.apc[6].pcv[11], -76,
                    "incorrect value for apc[6].pcv[11], expected -76, is {}",
                    msg.apc[6].pcv[11]
                );
                assert_eq!(
                    msg.apc[6].pcv[12], 41,
                    "incorrect value for apc[6].pcv[12], expected 41, is {}",
                    msg.apc[6].pcv[12]
                );
                assert_eq!(
                    msg.apc[6].pcv[13], -60,
                    "incorrect value for apc[6].pcv[13], expected -60, is {}",
                    msg.apc[6].pcv[13]
                );
                assert_eq!(
                    msg.apc[6].pcv[14], 40,
                    "incorrect value for apc[6].pcv[14], expected 40, is {}",
                    msg.apc[6].pcv[14]
                );
                assert_eq!(
                    msg.apc[6].pcv[15], 119,
                    "incorrect value for apc[6].pcv[15], expected 119, is {}",
                    msg.apc[6].pcv[15]
                );
                assert_eq!(
                    msg.apc[6].pcv[16], 101,
                    "incorrect value for apc[6].pcv[16], expected 101, is {}",
                    msg.apc[6].pcv[16]
                );
                assert_eq!(
                    msg.apc[6].pcv[17], -4,
                    "incorrect value for apc[6].pcv[17], expected -4, is {}",
                    msg.apc[6].pcv[17]
                );
                assert_eq!(
                    msg.apc[6].pcv[18], -33,
                    "incorrect value for apc[6].pcv[18], expected -33, is {}",
                    msg.apc[6].pcv[18]
                );
                assert_eq!(
                    msg.apc[6].pcv[19], -112,
                    "incorrect value for apc[6].pcv[19], expected -112, is {}",
                    msg.apc[6].pcv[19]
                );
                assert_eq!(
                    msg.apc[6].pcv[20], -103,
                    "incorrect value for apc[6].pcv[20], expected -103, is {}",
                    msg.apc[6].pcv[20]
                );
                assert_eq!(
                    msg.apc[6].sat_info, 7,
                    "incorrect value for apc[6].sat_info, expected 7, is {}",
                    msg.apc[6].sat_info
                );
                assert_eq!(
                    msg.apc[6].sid.code, 158,
                    "incorrect value for apc[6].sid.code, expected 158, is {}",
                    msg.apc[6].sid.code
                );
                assert_eq!(
                    msg.apc[6].sid.sat, 200,
                    "incorrect value for apc[6].sid.sat, expected 200, is {}",
                    msg.apc[6].sid.sat
                );
                assert_eq!(
                    msg.apc[6].svn, 17310,
                    "incorrect value for apc[6].svn, expected 17310, is {}",
                    msg.apc[6].svn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrSatelliteApcDep"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_satellite_apc_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_satellite_apc_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 4, 6, 56, 19, 224, 203, 169, 240, 78, 4, 213, 171, 254, 214, 212, 4, 8, 33, 31, 80,
            21, 4, 105, 225, 39, 139, 124, 149, 48, 15, 214, 197, 141, 32, 33, 135, 150, 148, 123,
            49, 135, 97, 39, 90, 20, 169, 239, 47, 153, 175, 35, 145, 145, 123, 194, 2, 102, 74,
            149, 95, 171, 238, 249, 7, 237, 170, 125, 106, 158, 83, 188, 181, 194, 27, 84, 226,
            142, 123, 77, 217, 248, 67, 215, 129, 114, 138, 25, 240, 10, 56, 76, 61, 161, 216, 22,
            181, 174, 33, 13, 252, 236, 230, 196, 128, 215, 239, 234, 179, 220, 44, 212, 57, 44,
            173, 49, 36, 137, 248, 235, 97, 112, 157, 139, 26, 115, 192, 31, 85, 127, 228, 81, 252,
            219, 249, 110, 147, 8, 161, 215, 212, 180, 25, 83, 144, 247, 12, 27, 199, 173, 74, 23,
            4, 239, 103, 223, 220, 139, 91, 127, 214, 86, 48, 203, 228, 99, 45, 83, 159, 11, 250,
            135, 170, 42, 217, 199, 233, 42, 170, 78, 206, 41, 43, 81, 247, 99, 198, 144, 2, 132,
            2, 224, 220, 148, 58, 85, 138, 210, 200, 158, 7, 158, 67, 46, 200, 132, 118, 241, 13,
            37, 62, 107, 253, 190, 136, 66, 9, 84, 155, 86, 180, 41, 196, 40, 119, 101, 252, 223,
            144, 153, 50, 13,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrSatelliteApcDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrSatelliteApcDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x604,
                    "Incorrect message type, expected 0x604, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1338,
                    "incorrect sender id, expected 0x1338, is {sender_id}"
                );
                assert_eq!(
                    msg.apc[0].pco[0], -21547,
                    "incorrect value for apc[0].pco[0], expected -21547, is {}",
                    msg.apc[0].pco[0]
                );
                assert_eq!(
                    msg.apc[0].pco[1], -10498,
                    "incorrect value for apc[0].pco[1], expected -10498, is {}",
                    msg.apc[0].pco[1]
                );
                assert_eq!(
                    msg.apc[0].pco[2], 1236,
                    "incorrect value for apc[0].pco[2], expected 1236, is {}",
                    msg.apc[0].pco[2]
                );
                assert_eq!(
                    msg.apc[0].pcv[0], 8,
                    "incorrect value for apc[0].pcv[0], expected 8, is {}",
                    msg.apc[0].pcv[0]
                );
                assert_eq!(
                    msg.apc[0].pcv[1], 33,
                    "incorrect value for apc[0].pcv[1], expected 33, is {}",
                    msg.apc[0].pcv[1]
                );
                assert_eq!(
                    msg.apc[0].pcv[2], 31,
                    "incorrect value for apc[0].pcv[2], expected 31, is {}",
                    msg.apc[0].pcv[2]
                );
                assert_eq!(
                    msg.apc[0].pcv[3], 80,
                    "incorrect value for apc[0].pcv[3], expected 80, is {}",
                    msg.apc[0].pcv[3]
                );
                assert_eq!(
                    msg.apc[0].pcv[4], 21,
                    "incorrect value for apc[0].pcv[4], expected 21, is {}",
                    msg.apc[0].pcv[4]
                );
                assert_eq!(
                    msg.apc[0].pcv[5], 4,
                    "incorrect value for apc[0].pcv[5], expected 4, is {}",
                    msg.apc[0].pcv[5]
                );
                assert_eq!(
                    msg.apc[0].pcv[6], 105,
                    "incorrect value for apc[0].pcv[6], expected 105, is {}",
                    msg.apc[0].pcv[6]
                );
                assert_eq!(
                    msg.apc[0].pcv[7], -31,
                    "incorrect value for apc[0].pcv[7], expected -31, is {}",
                    msg.apc[0].pcv[7]
                );
                assert_eq!(
                    msg.apc[0].pcv[8], 39,
                    "incorrect value for apc[0].pcv[8], expected 39, is {}",
                    msg.apc[0].pcv[8]
                );
                assert_eq!(
                    msg.apc[0].pcv[9], -117,
                    "incorrect value for apc[0].pcv[9], expected -117, is {}",
                    msg.apc[0].pcv[9]
                );
                assert_eq!(
                    msg.apc[0].pcv[10], 124,
                    "incorrect value for apc[0].pcv[10], expected 124, is {}",
                    msg.apc[0].pcv[10]
                );
                assert_eq!(
                    msg.apc[0].pcv[11], -107,
                    "incorrect value for apc[0].pcv[11], expected -107, is {}",
                    msg.apc[0].pcv[11]
                );
                assert_eq!(
                    msg.apc[0].pcv[12], 48,
                    "incorrect value for apc[0].pcv[12], expected 48, is {}",
                    msg.apc[0].pcv[12]
                );
                assert_eq!(
                    msg.apc[0].pcv[13], 15,
                    "incorrect value for apc[0].pcv[13], expected 15, is {}",
                    msg.apc[0].pcv[13]
                );
                assert_eq!(
                    msg.apc[0].pcv[14], -42,
                    "incorrect value for apc[0].pcv[14], expected -42, is {}",
                    msg.apc[0].pcv[14]
                );
                assert_eq!(
                    msg.apc[0].pcv[15], -59,
                    "incorrect value for apc[0].pcv[15], expected -59, is {}",
                    msg.apc[0].pcv[15]
                );
                assert_eq!(
                    msg.apc[0].pcv[16], -115,
                    "incorrect value for apc[0].pcv[16], expected -115, is {}",
                    msg.apc[0].pcv[16]
                );
                assert_eq!(
                    msg.apc[0].pcv[17], 32,
                    "incorrect value for apc[0].pcv[17], expected 32, is {}",
                    msg.apc[0].pcv[17]
                );
                assert_eq!(
                    msg.apc[0].pcv[18], 33,
                    "incorrect value for apc[0].pcv[18], expected 33, is {}",
                    msg.apc[0].pcv[18]
                );
                assert_eq!(
                    msg.apc[0].pcv[19], -121,
                    "incorrect value for apc[0].pcv[19], expected -121, is {}",
                    msg.apc[0].pcv[19]
                );
                assert_eq!(
                    msg.apc[0].pcv[20], -106,
                    "incorrect value for apc[0].pcv[20], expected -106, is {}",
                    msg.apc[0].pcv[20]
                );
                assert_eq!(
                    msg.apc[0].sat_info, 240,
                    "incorrect value for apc[0].sat_info, expected 240, is {}",
                    msg.apc[0].sat_info
                );
                assert_eq!(
                    msg.apc[0].sid.code, 169,
                    "incorrect value for apc[0].sid.code, expected 169, is {}",
                    msg.apc[0].sid.code
                );
                assert_eq!(
                    msg.apc[0].sid.sat, 203,
                    "incorrect value for apc[0].sid.sat, expected 203, is {}",
                    msg.apc[0].sid.sat
                );
                assert_eq!(
                    msg.apc[0].svn, 1102,
                    "incorrect value for apc[0].svn, expected 1102, is {}",
                    msg.apc[0].svn
                );
                assert_eq!(
                    msg.apc[1].pco[0], 23079,
                    "incorrect value for apc[1].pco[0], expected 23079, is {}",
                    msg.apc[1].pco[0]
                );
                assert_eq!(
                    msg.apc[1].pco[1], -22252,
                    "incorrect value for apc[1].pco[1], expected -22252, is {}",
                    msg.apc[1].pco[1]
                );
                assert_eq!(
                    msg.apc[1].pco[2], 12271,
                    "incorrect value for apc[1].pco[2], expected 12271, is {}",
                    msg.apc[1].pco[2]
                );
                assert_eq!(
                    msg.apc[1].pcv[0], -103,
                    "incorrect value for apc[1].pcv[0], expected -103, is {}",
                    msg.apc[1].pcv[0]
                );
                assert_eq!(
                    msg.apc[1].pcv[1], -81,
                    "incorrect value for apc[1].pcv[1], expected -81, is {}",
                    msg.apc[1].pcv[1]
                );
                assert_eq!(
                    msg.apc[1].pcv[2], 35,
                    "incorrect value for apc[1].pcv[2], expected 35, is {}",
                    msg.apc[1].pcv[2]
                );
                assert_eq!(
                    msg.apc[1].pcv[3], -111,
                    "incorrect value for apc[1].pcv[3], expected -111, is {}",
                    msg.apc[1].pcv[3]
                );
                assert_eq!(
                    msg.apc[1].pcv[4], -111,
                    "incorrect value for apc[1].pcv[4], expected -111, is {}",
                    msg.apc[1].pcv[4]
                );
                assert_eq!(
                    msg.apc[1].pcv[5], 123,
                    "incorrect value for apc[1].pcv[5], expected 123, is {}",
                    msg.apc[1].pcv[5]
                );
                assert_eq!(
                    msg.apc[1].pcv[6], -62,
                    "incorrect value for apc[1].pcv[6], expected -62, is {}",
                    msg.apc[1].pcv[6]
                );
                assert_eq!(
                    msg.apc[1].pcv[7], 2,
                    "incorrect value for apc[1].pcv[7], expected 2, is {}",
                    msg.apc[1].pcv[7]
                );
                assert_eq!(
                    msg.apc[1].pcv[8], 102,
                    "incorrect value for apc[1].pcv[8], expected 102, is {}",
                    msg.apc[1].pcv[8]
                );
                assert_eq!(
                    msg.apc[1].pcv[9], 74,
                    "incorrect value for apc[1].pcv[9], expected 74, is {}",
                    msg.apc[1].pcv[9]
                );
                assert_eq!(
                    msg.apc[1].pcv[10], -107,
                    "incorrect value for apc[1].pcv[10], expected -107, is {}",
                    msg.apc[1].pcv[10]
                );
                assert_eq!(
                    msg.apc[1].pcv[11], 95,
                    "incorrect value for apc[1].pcv[11], expected 95, is {}",
                    msg.apc[1].pcv[11]
                );
                assert_eq!(
                    msg.apc[1].pcv[12], -85,
                    "incorrect value for apc[1].pcv[12], expected -85, is {}",
                    msg.apc[1].pcv[12]
                );
                assert_eq!(
                    msg.apc[1].pcv[13], -18,
                    "incorrect value for apc[1].pcv[13], expected -18, is {}",
                    msg.apc[1].pcv[13]
                );
                assert_eq!(
                    msg.apc[1].pcv[14], -7,
                    "incorrect value for apc[1].pcv[14], expected -7, is {}",
                    msg.apc[1].pcv[14]
                );
                assert_eq!(
                    msg.apc[1].pcv[15], 7,
                    "incorrect value for apc[1].pcv[15], expected 7, is {}",
                    msg.apc[1].pcv[15]
                );
                assert_eq!(
                    msg.apc[1].pcv[16], -19,
                    "incorrect value for apc[1].pcv[16], expected -19, is {}",
                    msg.apc[1].pcv[16]
                );
                assert_eq!(
                    msg.apc[1].pcv[17], -86,
                    "incorrect value for apc[1].pcv[17], expected -86, is {}",
                    msg.apc[1].pcv[17]
                );
                assert_eq!(
                    msg.apc[1].pcv[18], 125,
                    "incorrect value for apc[1].pcv[18], expected 125, is {}",
                    msg.apc[1].pcv[18]
                );
                assert_eq!(
                    msg.apc[1].pcv[19], 106,
                    "incorrect value for apc[1].pcv[19], expected 106, is {}",
                    msg.apc[1].pcv[19]
                );
                assert_eq!(
                    msg.apc[1].pcv[20], -98,
                    "incorrect value for apc[1].pcv[20], expected -98, is {}",
                    msg.apc[1].pcv[20]
                );
                assert_eq!(
                    msg.apc[1].sat_info, 49,
                    "incorrect value for apc[1].sat_info, expected 49, is {}",
                    msg.apc[1].sat_info
                );
                assert_eq!(
                    msg.apc[1].sid.code, 123,
                    "incorrect value for apc[1].sid.code, expected 123, is {}",
                    msg.apc[1].sid.code
                );
                assert_eq!(
                    msg.apc[1].sid.sat, 148,
                    "incorrect value for apc[1].sid.sat, expected 148, is {}",
                    msg.apc[1].sid.sat
                );
                assert_eq!(
                    msg.apc[1].svn, 24967,
                    "incorrect value for apc[1].svn, expected 24967, is {}",
                    msg.apc[1].svn
                );
                assert_eq!(
                    msg.apc[2].pco[0], -7596,
                    "incorrect value for apc[2].pco[0], expected -7596, is {}",
                    msg.apc[2].pco[0]
                );
                assert_eq!(
                    msg.apc[2].pco[1], 31630,
                    "incorrect value for apc[2].pco[1], expected 31630, is {}",
                    msg.apc[2].pco[1]
                );
                assert_eq!(
                    msg.apc[2].pco[2], -9907,
                    "incorrect value for apc[2].pco[2], expected -9907, is {}",
                    msg.apc[2].pco[2]
                );
                assert_eq!(
                    msg.apc[2].pcv[0], -8,
                    "incorrect value for apc[2].pcv[0], expected -8, is {}",
                    msg.apc[2].pcv[0]
                );
                assert_eq!(
                    msg.apc[2].pcv[1], 67,
                    "incorrect value for apc[2].pcv[1], expected 67, is {}",
                    msg.apc[2].pcv[1]
                );
                assert_eq!(
                    msg.apc[2].pcv[2], -41,
                    "incorrect value for apc[2].pcv[2], expected -41, is {}",
                    msg.apc[2].pcv[2]
                );
                assert_eq!(
                    msg.apc[2].pcv[3], -127,
                    "incorrect value for apc[2].pcv[3], expected -127, is {}",
                    msg.apc[2].pcv[3]
                );
                assert_eq!(
                    msg.apc[2].pcv[4], 114,
                    "incorrect value for apc[2].pcv[4], expected 114, is {}",
                    msg.apc[2].pcv[4]
                );
                assert_eq!(
                    msg.apc[2].pcv[5], -118,
                    "incorrect value for apc[2].pcv[5], expected -118, is {}",
                    msg.apc[2].pcv[5]
                );
                assert_eq!(
                    msg.apc[2].pcv[6], 25,
                    "incorrect value for apc[2].pcv[6], expected 25, is {}",
                    msg.apc[2].pcv[6]
                );
                assert_eq!(
                    msg.apc[2].pcv[7], -16,
                    "incorrect value for apc[2].pcv[7], expected -16, is {}",
                    msg.apc[2].pcv[7]
                );
                assert_eq!(
                    msg.apc[2].pcv[8], 10,
                    "incorrect value for apc[2].pcv[8], expected 10, is {}",
                    msg.apc[2].pcv[8]
                );
                assert_eq!(
                    msg.apc[2].pcv[9], 56,
                    "incorrect value for apc[2].pcv[9], expected 56, is {}",
                    msg.apc[2].pcv[9]
                );
                assert_eq!(
                    msg.apc[2].pcv[10], 76,
                    "incorrect value for apc[2].pcv[10], expected 76, is {}",
                    msg.apc[2].pcv[10]
                );
                assert_eq!(
                    msg.apc[2].pcv[11], 61,
                    "incorrect value for apc[2].pcv[11], expected 61, is {}",
                    msg.apc[2].pcv[11]
                );
                assert_eq!(
                    msg.apc[2].pcv[12], -95,
                    "incorrect value for apc[2].pcv[12], expected -95, is {}",
                    msg.apc[2].pcv[12]
                );
                assert_eq!(
                    msg.apc[2].pcv[13], -40,
                    "incorrect value for apc[2].pcv[13], expected -40, is {}",
                    msg.apc[2].pcv[13]
                );
                assert_eq!(
                    msg.apc[2].pcv[14], 22,
                    "incorrect value for apc[2].pcv[14], expected 22, is {}",
                    msg.apc[2].pcv[14]
                );
                assert_eq!(
                    msg.apc[2].pcv[15], -75,
                    "incorrect value for apc[2].pcv[15], expected -75, is {}",
                    msg.apc[2].pcv[15]
                );
                assert_eq!(
                    msg.apc[2].pcv[16], -82,
                    "incorrect value for apc[2].pcv[16], expected -82, is {}",
                    msg.apc[2].pcv[16]
                );
                assert_eq!(
                    msg.apc[2].pcv[17], 33,
                    "incorrect value for apc[2].pcv[17], expected 33, is {}",
                    msg.apc[2].pcv[17]
                );
                assert_eq!(
                    msg.apc[2].pcv[18], 13,
                    "incorrect value for apc[2].pcv[18], expected 13, is {}",
                    msg.apc[2].pcv[18]
                );
                assert_eq!(
                    msg.apc[2].pcv[19], -4,
                    "incorrect value for apc[2].pcv[19], expected -4, is {}",
                    msg.apc[2].pcv[19]
                );
                assert_eq!(
                    msg.apc[2].pcv[20], -20,
                    "incorrect value for apc[2].pcv[20], expected -20, is {}",
                    msg.apc[2].pcv[20]
                );
                assert_eq!(
                    msg.apc[2].sat_info, 181,
                    "incorrect value for apc[2].sat_info, expected 181, is {}",
                    msg.apc[2].sat_info
                );
                assert_eq!(
                    msg.apc[2].sid.code, 188,
                    "incorrect value for apc[2].sid.code, expected 188, is {}",
                    msg.apc[2].sid.code
                );
                assert_eq!(
                    msg.apc[2].sid.sat, 83,
                    "incorrect value for apc[2].sid.sat, expected 83, is {}",
                    msg.apc[2].sid.sat
                );
                assert_eq!(
                    msg.apc[2].svn, 7106,
                    "incorrect value for apc[2].svn, expected 7106, is {}",
                    msg.apc[2].svn
                );
                assert_eq!(
                    msg.apc[3].pco[0], -19478,
                    "incorrect value for apc[3].pco[0], expected -19478, is {}",
                    msg.apc[3].pco[0]
                );
                assert_eq!(
                    msg.apc[3].pco[1], 11484,
                    "incorrect value for apc[3].pco[1], expected 11484, is {}",
                    msg.apc[3].pco[1]
                );
                assert_eq!(
                    msg.apc[3].pco[2], 14804,
                    "incorrect value for apc[3].pco[2], expected 14804, is {}",
                    msg.apc[3].pco[2]
                );
                assert_eq!(
                    msg.apc[3].pcv[0], 44,
                    "incorrect value for apc[3].pcv[0], expected 44, is {}",
                    msg.apc[3].pcv[0]
                );
                assert_eq!(
                    msg.apc[3].pcv[1], -83,
                    "incorrect value for apc[3].pcv[1], expected -83, is {}",
                    msg.apc[3].pcv[1]
                );
                assert_eq!(
                    msg.apc[3].pcv[2], 49,
                    "incorrect value for apc[3].pcv[2], expected 49, is {}",
                    msg.apc[3].pcv[2]
                );
                assert_eq!(
                    msg.apc[3].pcv[3], 36,
                    "incorrect value for apc[3].pcv[3], expected 36, is {}",
                    msg.apc[3].pcv[3]
                );
                assert_eq!(
                    msg.apc[3].pcv[4], -119,
                    "incorrect value for apc[3].pcv[4], expected -119, is {}",
                    msg.apc[3].pcv[4]
                );
                assert_eq!(
                    msg.apc[3].pcv[5], -8,
                    "incorrect value for apc[3].pcv[5], expected -8, is {}",
                    msg.apc[3].pcv[5]
                );
                assert_eq!(
                    msg.apc[3].pcv[6], -21,
                    "incorrect value for apc[3].pcv[6], expected -21, is {}",
                    msg.apc[3].pcv[6]
                );
                assert_eq!(
                    msg.apc[3].pcv[7], 97,
                    "incorrect value for apc[3].pcv[7], expected 97, is {}",
                    msg.apc[3].pcv[7]
                );
                assert_eq!(
                    msg.apc[3].pcv[8], 112,
                    "incorrect value for apc[3].pcv[8], expected 112, is {}",
                    msg.apc[3].pcv[8]
                );
                assert_eq!(
                    msg.apc[3].pcv[9], -99,
                    "incorrect value for apc[3].pcv[9], expected -99, is {}",
                    msg.apc[3].pcv[9]
                );
                assert_eq!(
                    msg.apc[3].pcv[10], -117,
                    "incorrect value for apc[3].pcv[10], expected -117, is {}",
                    msg.apc[3].pcv[10]
                );
                assert_eq!(
                    msg.apc[3].pcv[11], 26,
                    "incorrect value for apc[3].pcv[11], expected 26, is {}",
                    msg.apc[3].pcv[11]
                );
                assert_eq!(
                    msg.apc[3].pcv[12], 115,
                    "incorrect value for apc[3].pcv[12], expected 115, is {}",
                    msg.apc[3].pcv[12]
                );
                assert_eq!(
                    msg.apc[3].pcv[13], -64,
                    "incorrect value for apc[3].pcv[13], expected -64, is {}",
                    msg.apc[3].pcv[13]
                );
                assert_eq!(
                    msg.apc[3].pcv[14], 31,
                    "incorrect value for apc[3].pcv[14], expected 31, is {}",
                    msg.apc[3].pcv[14]
                );
                assert_eq!(
                    msg.apc[3].pcv[15], 85,
                    "incorrect value for apc[3].pcv[15], expected 85, is {}",
                    msg.apc[3].pcv[15]
                );
                assert_eq!(
                    msg.apc[3].pcv[16], 127,
                    "incorrect value for apc[3].pcv[16], expected 127, is {}",
                    msg.apc[3].pcv[16]
                );
                assert_eq!(
                    msg.apc[3].pcv[17], -28,
                    "incorrect value for apc[3].pcv[17], expected -28, is {}",
                    msg.apc[3].pcv[17]
                );
                assert_eq!(
                    msg.apc[3].pcv[18], 81,
                    "incorrect value for apc[3].pcv[18], expected 81, is {}",
                    msg.apc[3].pcv[18]
                );
                assert_eq!(
                    msg.apc[3].pcv[19], -4,
                    "incorrect value for apc[3].pcv[19], expected -4, is {}",
                    msg.apc[3].pcv[19]
                );
                assert_eq!(
                    msg.apc[3].pcv[20], -37,
                    "incorrect value for apc[3].pcv[20], expected -37, is {}",
                    msg.apc[3].pcv[20]
                );
                assert_eq!(
                    msg.apc[3].sat_info, 128,
                    "incorrect value for apc[3].sat_info, expected 128, is {}",
                    msg.apc[3].sat_info
                );
                assert_eq!(
                    msg.apc[3].sid.code, 196,
                    "incorrect value for apc[3].sid.code, expected 196, is {}",
                    msg.apc[3].sid.code
                );
                assert_eq!(
                    msg.apc[3].sid.sat, 230,
                    "incorrect value for apc[3].sid.sat, expected 230, is {}",
                    msg.apc[3].sid.sat
                );
                assert_eq!(
                    msg.apc[3].svn, 61399,
                    "incorrect value for apc[3].svn, expected 61399, is {}",
                    msg.apc[3].svn
                );
                assert_eq!(
                    msg.apc[4].pco[0], -11049,
                    "incorrect value for apc[4].pco[0], expected -11049, is {}",
                    msg.apc[4].pco[0]
                );
                assert_eq!(
                    msg.apc[4].pco[1], 6580,
                    "incorrect value for apc[4].pco[1], expected 6580, is {}",
                    msg.apc[4].pco[1]
                );
                assert_eq!(
                    msg.apc[4].pco[2], -28589,
                    "incorrect value for apc[4].pco[2], expected -28589, is {}",
                    msg.apc[4].pco[2]
                );
                assert_eq!(
                    msg.apc[4].pcv[0], -9,
                    "incorrect value for apc[4].pcv[0], expected -9, is {}",
                    msg.apc[4].pcv[0]
                );
                assert_eq!(
                    msg.apc[4].pcv[1], 12,
                    "incorrect value for apc[4].pcv[1], expected 12, is {}",
                    msg.apc[4].pcv[1]
                );
                assert_eq!(
                    msg.apc[4].pcv[2], 27,
                    "incorrect value for apc[4].pcv[2], expected 27, is {}",
                    msg.apc[4].pcv[2]
                );
                assert_eq!(
                    msg.apc[4].pcv[3], -57,
                    "incorrect value for apc[4].pcv[3], expected -57, is {}",
                    msg.apc[4].pcv[3]
                );
                assert_eq!(
                    msg.apc[4].pcv[4], -83,
                    "incorrect value for apc[4].pcv[4], expected -83, is {}",
                    msg.apc[4].pcv[4]
                );
                assert_eq!(
                    msg.apc[4].pcv[5], 74,
                    "incorrect value for apc[4].pcv[5], expected 74, is {}",
                    msg.apc[4].pcv[5]
                );
                assert_eq!(
                    msg.apc[4].pcv[6], 23,
                    "incorrect value for apc[4].pcv[6], expected 23, is {}",
                    msg.apc[4].pcv[6]
                );
                assert_eq!(
                    msg.apc[4].pcv[7], 4,
                    "incorrect value for apc[4].pcv[7], expected 4, is {}",
                    msg.apc[4].pcv[7]
                );
                assert_eq!(
                    msg.apc[4].pcv[8], -17,
                    "incorrect value for apc[4].pcv[8], expected -17, is {}",
                    msg.apc[4].pcv[8]
                );
                assert_eq!(
                    msg.apc[4].pcv[9], 103,
                    "incorrect value for apc[4].pcv[9], expected 103, is {}",
                    msg.apc[4].pcv[9]
                );
                assert_eq!(
                    msg.apc[4].pcv[10], -33,
                    "incorrect value for apc[4].pcv[10], expected -33, is {}",
                    msg.apc[4].pcv[10]
                );
                assert_eq!(
                    msg.apc[4].pcv[11], -36,
                    "incorrect value for apc[4].pcv[11], expected -36, is {}",
                    msg.apc[4].pcv[11]
                );
                assert_eq!(
                    msg.apc[4].pcv[12], -117,
                    "incorrect value for apc[4].pcv[12], expected -117, is {}",
                    msg.apc[4].pcv[12]
                );
                assert_eq!(
                    msg.apc[4].pcv[13], 91,
                    "incorrect value for apc[4].pcv[13], expected 91, is {}",
                    msg.apc[4].pcv[13]
                );
                assert_eq!(
                    msg.apc[4].pcv[14], 127,
                    "incorrect value for apc[4].pcv[14], expected 127, is {}",
                    msg.apc[4].pcv[14]
                );
                assert_eq!(
                    msg.apc[4].pcv[15], -42,
                    "incorrect value for apc[4].pcv[15], expected -42, is {}",
                    msg.apc[4].pcv[15]
                );
                assert_eq!(
                    msg.apc[4].pcv[16], 86,
                    "incorrect value for apc[4].pcv[16], expected 86, is {}",
                    msg.apc[4].pcv[16]
                );
                assert_eq!(
                    msg.apc[4].pcv[17], 48,
                    "incorrect value for apc[4].pcv[17], expected 48, is {}",
                    msg.apc[4].pcv[17]
                );
                assert_eq!(
                    msg.apc[4].pcv[18], -53,
                    "incorrect value for apc[4].pcv[18], expected -53, is {}",
                    msg.apc[4].pcv[18]
                );
                assert_eq!(
                    msg.apc[4].pcv[19], -28,
                    "incorrect value for apc[4].pcv[19], expected -28, is {}",
                    msg.apc[4].pcv[19]
                );
                assert_eq!(
                    msg.apc[4].pcv[20], 99,
                    "incorrect value for apc[4].pcv[20], expected 99, is {}",
                    msg.apc[4].pcv[20]
                );
                assert_eq!(
                    msg.apc[4].sat_info, 147,
                    "incorrect value for apc[4].sat_info, expected 147, is {}",
                    msg.apc[4].sat_info
                );
                assert_eq!(
                    msg.apc[4].sid.code, 110,
                    "incorrect value for apc[4].sid.code, expected 110, is {}",
                    msg.apc[4].sid.code
                );
                assert_eq!(
                    msg.apc[4].sid.sat, 249,
                    "incorrect value for apc[4].sid.sat, expected 249, is {}",
                    msg.apc[4].sid.sat
                );
                assert_eq!(
                    msg.apc[4].svn, 41224,
                    "incorrect value for apc[4].svn, expected 41224, is {}",
                    msg.apc[4].svn
                );
                assert_eq!(
                    msg.apc[5].pco[0], -21881,
                    "incorrect value for apc[5].pco[0], expected -21881, is {}",
                    msg.apc[5].pco[0]
                );
                assert_eq!(
                    msg.apc[5].pco[1], -9942,
                    "incorrect value for apc[5].pco[1], expected -9942, is {}",
                    msg.apc[5].pco[1]
                );
                assert_eq!(
                    msg.apc[5].pco[2], -5689,
                    "incorrect value for apc[5].pco[2], expected -5689, is {}",
                    msg.apc[5].pco[2]
                );
                assert_eq!(
                    msg.apc[5].pcv[0], 42,
                    "incorrect value for apc[5].pcv[0], expected 42, is {}",
                    msg.apc[5].pcv[0]
                );
                assert_eq!(
                    msg.apc[5].pcv[1], -86,
                    "incorrect value for apc[5].pcv[1], expected -86, is {}",
                    msg.apc[5].pcv[1]
                );
                assert_eq!(
                    msg.apc[5].pcv[2], 78,
                    "incorrect value for apc[5].pcv[2], expected 78, is {}",
                    msg.apc[5].pcv[2]
                );
                assert_eq!(
                    msg.apc[5].pcv[3], -50,
                    "incorrect value for apc[5].pcv[3], expected -50, is {}",
                    msg.apc[5].pcv[3]
                );
                assert_eq!(
                    msg.apc[5].pcv[4], 41,
                    "incorrect value for apc[5].pcv[4], expected 41, is {}",
                    msg.apc[5].pcv[4]
                );
                assert_eq!(
                    msg.apc[5].pcv[5], 43,
                    "incorrect value for apc[5].pcv[5], expected 43, is {}",
                    msg.apc[5].pcv[5]
                );
                assert_eq!(
                    msg.apc[5].pcv[6], 81,
                    "incorrect value for apc[5].pcv[6], expected 81, is {}",
                    msg.apc[5].pcv[6]
                );
                assert_eq!(
                    msg.apc[5].pcv[7], -9,
                    "incorrect value for apc[5].pcv[7], expected -9, is {}",
                    msg.apc[5].pcv[7]
                );
                assert_eq!(
                    msg.apc[5].pcv[8], 99,
                    "incorrect value for apc[5].pcv[8], expected 99, is {}",
                    msg.apc[5].pcv[8]
                );
                assert_eq!(
                    msg.apc[5].pcv[9], -58,
                    "incorrect value for apc[5].pcv[9], expected -58, is {}",
                    msg.apc[5].pcv[9]
                );
                assert_eq!(
                    msg.apc[5].pcv[10], -112,
                    "incorrect value for apc[5].pcv[10], expected -112, is {}",
                    msg.apc[5].pcv[10]
                );
                assert_eq!(
                    msg.apc[5].pcv[11], 2,
                    "incorrect value for apc[5].pcv[11], expected 2, is {}",
                    msg.apc[5].pcv[11]
                );
                assert_eq!(
                    msg.apc[5].pcv[12], -124,
                    "incorrect value for apc[5].pcv[12], expected -124, is {}",
                    msg.apc[5].pcv[12]
                );
                assert_eq!(
                    msg.apc[5].pcv[13], 2,
                    "incorrect value for apc[5].pcv[13], expected 2, is {}",
                    msg.apc[5].pcv[13]
                );
                assert_eq!(
                    msg.apc[5].pcv[14], -32,
                    "incorrect value for apc[5].pcv[14], expected -32, is {}",
                    msg.apc[5].pcv[14]
                );
                assert_eq!(
                    msg.apc[5].pcv[15], -36,
                    "incorrect value for apc[5].pcv[15], expected -36, is {}",
                    msg.apc[5].pcv[15]
                );
                assert_eq!(
                    msg.apc[5].pcv[16], -108,
                    "incorrect value for apc[5].pcv[16], expected -108, is {}",
                    msg.apc[5].pcv[16]
                );
                assert_eq!(
                    msg.apc[5].pcv[17], 58,
                    "incorrect value for apc[5].pcv[17], expected 58, is {}",
                    msg.apc[5].pcv[17]
                );
                assert_eq!(
                    msg.apc[5].pcv[18], 85,
                    "incorrect value for apc[5].pcv[18], expected 85, is {}",
                    msg.apc[5].pcv[18]
                );
                assert_eq!(
                    msg.apc[5].pcv[19], -118,
                    "incorrect value for apc[5].pcv[19], expected -118, is {}",
                    msg.apc[5].pcv[19]
                );
                assert_eq!(
                    msg.apc[5].pcv[20], -46,
                    "incorrect value for apc[5].pcv[20], expected -46, is {}",
                    msg.apc[5].pcv[20]
                );
                assert_eq!(
                    msg.apc[5].sat_info, 159,
                    "incorrect value for apc[5].sat_info, expected 159, is {}",
                    msg.apc[5].sat_info
                );
                assert_eq!(
                    msg.apc[5].sid.code, 83,
                    "incorrect value for apc[5].sid.code, expected 83, is {}",
                    msg.apc[5].sid.code
                );
                assert_eq!(
                    msg.apc[5].sid.sat, 45,
                    "incorrect value for apc[5].sid.sat, expected 45, is {}",
                    msg.apc[5].sid.sat
                );
                assert_eq!(
                    msg.apc[5].svn, 64011,
                    "incorrect value for apc[5].svn, expected 64011, is {}",
                    msg.apc[5].svn
                );
                assert_eq!(
                    msg.apc[6].pco[0], -14290,
                    "incorrect value for apc[6].pco[0], expected -14290, is {}",
                    msg.apc[6].pco[0]
                );
                assert_eq!(
                    msg.apc[6].pco[1], 30340,
                    "incorrect value for apc[6].pco[1], expected 30340, is {}",
                    msg.apc[6].pco[1]
                );
                assert_eq!(
                    msg.apc[6].pco[2], 3569,
                    "incorrect value for apc[6].pco[2], expected 3569, is {}",
                    msg.apc[6].pco[2]
                );
                assert_eq!(
                    msg.apc[6].pcv[0], 37,
                    "incorrect value for apc[6].pcv[0], expected 37, is {}",
                    msg.apc[6].pcv[0]
                );
                assert_eq!(
                    msg.apc[6].pcv[1], 62,
                    "incorrect value for apc[6].pcv[1], expected 62, is {}",
                    msg.apc[6].pcv[1]
                );
                assert_eq!(
                    msg.apc[6].pcv[2], 107,
                    "incorrect value for apc[6].pcv[2], expected 107, is {}",
                    msg.apc[6].pcv[2]
                );
                assert_eq!(
                    msg.apc[6].pcv[3], -3,
                    "incorrect value for apc[6].pcv[3], expected -3, is {}",
                    msg.apc[6].pcv[3]
                );
                assert_eq!(
                    msg.apc[6].pcv[4], -66,
                    "incorrect value for apc[6].pcv[4], expected -66, is {}",
                    msg.apc[6].pcv[4]
                );
                assert_eq!(
                    msg.apc[6].pcv[5], -120,
                    "incorrect value for apc[6].pcv[5], expected -120, is {}",
                    msg.apc[6].pcv[5]
                );
                assert_eq!(
                    msg.apc[6].pcv[6], 66,
                    "incorrect value for apc[6].pcv[6], expected 66, is {}",
                    msg.apc[6].pcv[6]
                );
                assert_eq!(
                    msg.apc[6].pcv[7], 9,
                    "incorrect value for apc[6].pcv[7], expected 9, is {}",
                    msg.apc[6].pcv[7]
                );
                assert_eq!(
                    msg.apc[6].pcv[8], 84,
                    "incorrect value for apc[6].pcv[8], expected 84, is {}",
                    msg.apc[6].pcv[8]
                );
                assert_eq!(
                    msg.apc[6].pcv[9], -101,
                    "incorrect value for apc[6].pcv[9], expected -101, is {}",
                    msg.apc[6].pcv[9]
                );
                assert_eq!(
                    msg.apc[6].pcv[10], 86,
                    "incorrect value for apc[6].pcv[10], expected 86, is {}",
                    msg.apc[6].pcv[10]
                );
                assert_eq!(
                    msg.apc[6].pcv[11], -76,
                    "incorrect value for apc[6].pcv[11], expected -76, is {}",
                    msg.apc[6].pcv[11]
                );
                assert_eq!(
                    msg.apc[6].pcv[12], 41,
                    "incorrect value for apc[6].pcv[12], expected 41, is {}",
                    msg.apc[6].pcv[12]
                );
                assert_eq!(
                    msg.apc[6].pcv[13], -60,
                    "incorrect value for apc[6].pcv[13], expected -60, is {}",
                    msg.apc[6].pcv[13]
                );
                assert_eq!(
                    msg.apc[6].pcv[14], 40,
                    "incorrect value for apc[6].pcv[14], expected 40, is {}",
                    msg.apc[6].pcv[14]
                );
                assert_eq!(
                    msg.apc[6].pcv[15], 119,
                    "incorrect value for apc[6].pcv[15], expected 119, is {}",
                    msg.apc[6].pcv[15]
                );
                assert_eq!(
                    msg.apc[6].pcv[16], 101,
                    "incorrect value for apc[6].pcv[16], expected 101, is {}",
                    msg.apc[6].pcv[16]
                );
                assert_eq!(
                    msg.apc[6].pcv[17], -4,
                    "incorrect value for apc[6].pcv[17], expected -4, is {}",
                    msg.apc[6].pcv[17]
                );
                assert_eq!(
                    msg.apc[6].pcv[18], -33,
                    "incorrect value for apc[6].pcv[18], expected -33, is {}",
                    msg.apc[6].pcv[18]
                );
                assert_eq!(
                    msg.apc[6].pcv[19], -112,
                    "incorrect value for apc[6].pcv[19], expected -112, is {}",
                    msg.apc[6].pcv[19]
                );
                assert_eq!(
                    msg.apc[6].pcv[20], -103,
                    "incorrect value for apc[6].pcv[20], expected -103, is {}",
                    msg.apc[6].pcv[20]
                );
                assert_eq!(
                    msg.apc[6].sat_info, 7,
                    "incorrect value for apc[6].sat_info, expected 7, is {}",
                    msg.apc[6].sat_info
                );
                assert_eq!(
                    msg.apc[6].sid.code, 158,
                    "incorrect value for apc[6].sid.code, expected 158, is {}",
                    msg.apc[6].sid.code
                );
                assert_eq!(
                    msg.apc[6].sid.sat, 200,
                    "incorrect value for apc[6].sid.sat, expected 200, is {}",
                    msg.apc[6].sid.sat
                );
                assert_eq!(
                    msg.apc[6].svn, 17310,
                    "incorrect value for apc[6].svn, expected 17310, is {}",
                    msg.apc[6].svn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrSatelliteApcDep"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
