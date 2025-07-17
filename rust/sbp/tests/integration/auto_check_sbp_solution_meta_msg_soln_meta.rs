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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/soln_meta/test_MsgSolnMeta.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_solution_meta_msg_soln_meta() {
    {
        let mut payload = Cursor::new(vec![
            85, 14, 255, 0, 60, 254, 48, 208, 65, 216, 122, 45, 196, 160, 144, 228, 8, 83, 89, 87,
            3, 213, 95, 109, 86, 131, 71, 70, 84, 73, 131, 26, 82, 247, 140, 97, 115, 110, 118,
            253, 2, 122, 186, 148, 122, 148, 180, 231, 68, 46, 190, 102, 243, 48, 192, 15, 208, 89,
            56, 10, 245, 2, 254, 201, 120, 32, 126, 2, 83, 161, 238, 123, 102, 230, 76, 190, 225,
            182, 207, 228, 7, 218, 117, 89, 29, 191, 56, 248, 185, 255, 46, 18, 72, 142, 82, 113,
            26, 4, 172, 254, 178, 136, 113, 115, 58, 193, 89, 227, 182, 246, 76, 77, 108, 245, 41,
            31, 70, 124, 249, 145, 15, 78, 228, 38, 241, 129, 8, 176, 251, 72, 248, 80, 115, 244,
            231, 145, 191, 190, 178, 168, 89, 233, 69, 176, 174, 140, 182, 141, 81, 82, 92, 79,
            101, 223, 100, 64, 184, 215, 124, 37, 21, 227, 135, 102, 72, 36, 219, 56, 146, 90, 219,
            104, 227, 102, 83, 12, 41, 122, 173, 94, 1, 174, 134, 130, 104, 237, 116, 249, 107,
            230, 130, 123, 25, 162, 57, 223, 193, 174, 146, 193, 239, 44, 246, 197, 214, 80, 83,
            100, 66, 72, 133, 137, 140, 82, 2, 2, 96, 9, 96, 158, 134, 97, 43, 129, 141, 25, 183,
            200, 214, 57, 248, 103, 222, 65, 195, 15, 244, 21, 180, 46, 140, 130, 36, 17, 194, 209,
            65, 254, 115, 103, 152, 129, 234, 235, 194, 234, 170, 201, 210, 154, 150, 247,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSolnMeta(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff0e,
                    "Incorrect message type, expected 0xff0e, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x3c00,
                    "incorrect sender id, expected 0x3c00, is {sender_id}"
                );
                assert_eq!(
                    msg.age_corrections, 21256,
                    "incorrect value for age_corrections, expected 21256, is {}",
                    msg.age_corrections
                );
                assert_eq!(
                    msg.age_gnss, 3573765977,
                    "incorrect value for age_gnss, expected 3573765977, is {}",
                    msg.age_gnss
                );
                assert_eq!(
                    msg.hdop, 41156,
                    "incorrect value for hdop, expected 41156, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 11642,
                    "incorrect value for pdop, expected 11642, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.sol_in[0].flags, 109,
                    "incorrect value for sol_in[0].flags, expected 109, is {}",
                    msg.sol_in[0].flags
                );
                assert_eq!(
                    msg.sol_in[0].sensor_type, 95,
                    "incorrect value for sol_in[0].sensor_type, expected 95, is {}",
                    msg.sol_in[0].sensor_type
                );
                assert_eq!(
                    msg.sol_in[1].flags, 131,
                    "incorrect value for sol_in[1].flags, expected 131, is {}",
                    msg.sol_in[1].flags
                );
                assert_eq!(
                    msg.sol_in[1].sensor_type, 86,
                    "incorrect value for sol_in[1].sensor_type, expected 86, is {}",
                    msg.sol_in[1].sensor_type
                );
                assert_eq!(
                    msg.sol_in[2].flags, 70,
                    "incorrect value for sol_in[2].flags, expected 70, is {}",
                    msg.sol_in[2].flags
                );
                assert_eq!(
                    msg.sol_in[2].sensor_type, 71,
                    "incorrect value for sol_in[2].sensor_type, expected 71, is {}",
                    msg.sol_in[2].sensor_type
                );
                assert_eq!(
                    msg.sol_in[3].flags, 73,
                    "incorrect value for sol_in[3].flags, expected 73, is {}",
                    msg.sol_in[3].flags
                );
                assert_eq!(
                    msg.sol_in[3].sensor_type, 84,
                    "incorrect value for sol_in[3].sensor_type, expected 84, is {}",
                    msg.sol_in[3].sensor_type
                );
                assert_eq!(
                    msg.sol_in[4].flags, 26,
                    "incorrect value for sol_in[4].flags, expected 26, is {}",
                    msg.sol_in[4].flags
                );
                assert_eq!(
                    msg.sol_in[4].sensor_type, 131,
                    "incorrect value for sol_in[4].sensor_type, expected 131, is {}",
                    msg.sol_in[4].sensor_type
                );
                assert_eq!(
                    msg.sol_in[5].flags, 247,
                    "incorrect value for sol_in[5].flags, expected 247, is {}",
                    msg.sol_in[5].flags
                );
                assert_eq!(
                    msg.sol_in[5].sensor_type, 82,
                    "incorrect value for sol_in[5].sensor_type, expected 82, is {}",
                    msg.sol_in[5].sensor_type
                );
                assert_eq!(
                    msg.sol_in[6].flags, 97,
                    "incorrect value for sol_in[6].flags, expected 97, is {}",
                    msg.sol_in[6].flags
                );
                assert_eq!(
                    msg.sol_in[6].sensor_type, 140,
                    "incorrect value for sol_in[6].sensor_type, expected 140, is {}",
                    msg.sol_in[6].sensor_type
                );
                assert_eq!(
                    msg.sol_in[7].flags, 110,
                    "incorrect value for sol_in[7].flags, expected 110, is {}",
                    msg.sol_in[7].flags
                );
                assert_eq!(
                    msg.sol_in[7].sensor_type, 115,
                    "incorrect value for sol_in[7].sensor_type, expected 115, is {}",
                    msg.sol_in[7].sensor_type
                );
                assert_eq!(
                    msg.sol_in[8].flags, 253,
                    "incorrect value for sol_in[8].flags, expected 253, is {}",
                    msg.sol_in[8].flags
                );
                assert_eq!(
                    msg.sol_in[8].sensor_type, 118,
                    "incorrect value for sol_in[8].sensor_type, expected 118, is {}",
                    msg.sol_in[8].sensor_type
                );
                assert_eq!(
                    msg.sol_in[9].flags, 122,
                    "incorrect value for sol_in[9].flags, expected 122, is {}",
                    msg.sol_in[9].flags
                );
                assert_eq!(
                    msg.sol_in[9].sensor_type, 2,
                    "incorrect value for sol_in[9].sensor_type, expected 2, is {}",
                    msg.sol_in[9].sensor_type
                );
                assert_eq!(
                    msg.sol_in[10].flags, 148,
                    "incorrect value for sol_in[10].flags, expected 148, is {}",
                    msg.sol_in[10].flags
                );
                assert_eq!(
                    msg.sol_in[10].sensor_type, 186,
                    "incorrect value for sol_in[10].sensor_type, expected 186, is {}",
                    msg.sol_in[10].sensor_type
                );
                assert_eq!(
                    msg.sol_in[11].flags, 148,
                    "incorrect value for sol_in[11].flags, expected 148, is {}",
                    msg.sol_in[11].flags
                );
                assert_eq!(
                    msg.sol_in[11].sensor_type, 122,
                    "incorrect value for sol_in[11].sensor_type, expected 122, is {}",
                    msg.sol_in[11].sensor_type
                );
                assert_eq!(
                    msg.sol_in[12].flags, 231,
                    "incorrect value for sol_in[12].flags, expected 231, is {}",
                    msg.sol_in[12].flags
                );
                assert_eq!(
                    msg.sol_in[12].sensor_type, 180,
                    "incorrect value for sol_in[12].sensor_type, expected 180, is {}",
                    msg.sol_in[12].sensor_type
                );
                assert_eq!(
                    msg.sol_in[13].flags, 46,
                    "incorrect value for sol_in[13].flags, expected 46, is {}",
                    msg.sol_in[13].flags
                );
                assert_eq!(
                    msg.sol_in[13].sensor_type, 68,
                    "incorrect value for sol_in[13].sensor_type, expected 68, is {}",
                    msg.sol_in[13].sensor_type
                );
                assert_eq!(
                    msg.sol_in[14].flags, 102,
                    "incorrect value for sol_in[14].flags, expected 102, is {}",
                    msg.sol_in[14].flags
                );
                assert_eq!(
                    msg.sol_in[14].sensor_type, 190,
                    "incorrect value for sol_in[14].sensor_type, expected 190, is {}",
                    msg.sol_in[14].sensor_type
                );
                assert_eq!(
                    msg.sol_in[15].flags, 48,
                    "incorrect value for sol_in[15].flags, expected 48, is {}",
                    msg.sol_in[15].flags
                );
                assert_eq!(
                    msg.sol_in[15].sensor_type, 243,
                    "incorrect value for sol_in[15].sensor_type, expected 243, is {}",
                    msg.sol_in[15].sensor_type
                );
                assert_eq!(
                    msg.sol_in[16].flags, 15,
                    "incorrect value for sol_in[16].flags, expected 15, is {}",
                    msg.sol_in[16].flags
                );
                assert_eq!(
                    msg.sol_in[16].sensor_type, 192,
                    "incorrect value for sol_in[16].sensor_type, expected 192, is {}",
                    msg.sol_in[16].sensor_type
                );
                assert_eq!(
                    msg.sol_in[17].flags, 89,
                    "incorrect value for sol_in[17].flags, expected 89, is {}",
                    msg.sol_in[17].flags
                );
                assert_eq!(
                    msg.sol_in[17].sensor_type, 208,
                    "incorrect value for sol_in[17].sensor_type, expected 208, is {}",
                    msg.sol_in[17].sensor_type
                );
                assert_eq!(
                    msg.sol_in[18].flags, 10,
                    "incorrect value for sol_in[18].flags, expected 10, is {}",
                    msg.sol_in[18].flags
                );
                assert_eq!(
                    msg.sol_in[18].sensor_type, 56,
                    "incorrect value for sol_in[18].sensor_type, expected 56, is {}",
                    msg.sol_in[18].sensor_type
                );
                assert_eq!(
                    msg.sol_in[19].flags, 2,
                    "incorrect value for sol_in[19].flags, expected 2, is {}",
                    msg.sol_in[19].flags
                );
                assert_eq!(
                    msg.sol_in[19].sensor_type, 245,
                    "incorrect value for sol_in[19].sensor_type, expected 245, is {}",
                    msg.sol_in[19].sensor_type
                );
                assert_eq!(
                    msg.sol_in[20].flags, 201,
                    "incorrect value for sol_in[20].flags, expected 201, is {}",
                    msg.sol_in[20].flags
                );
                assert_eq!(
                    msg.sol_in[20].sensor_type, 254,
                    "incorrect value for sol_in[20].sensor_type, expected 254, is {}",
                    msg.sol_in[20].sensor_type
                );
                assert_eq!(
                    msg.sol_in[21].flags, 32,
                    "incorrect value for sol_in[21].flags, expected 32, is {}",
                    msg.sol_in[21].flags
                );
                assert_eq!(
                    msg.sol_in[21].sensor_type, 120,
                    "incorrect value for sol_in[21].sensor_type, expected 120, is {}",
                    msg.sol_in[21].sensor_type
                );
                assert_eq!(
                    msg.sol_in[22].flags, 2,
                    "incorrect value for sol_in[22].flags, expected 2, is {}",
                    msg.sol_in[22].flags
                );
                assert_eq!(
                    msg.sol_in[22].sensor_type, 126,
                    "incorrect value for sol_in[22].sensor_type, expected 126, is {}",
                    msg.sol_in[22].sensor_type
                );
                assert_eq!(
                    msg.sol_in[23].flags, 161,
                    "incorrect value for sol_in[23].flags, expected 161, is {}",
                    msg.sol_in[23].flags
                );
                assert_eq!(
                    msg.sol_in[23].sensor_type, 83,
                    "incorrect value for sol_in[23].sensor_type, expected 83, is {}",
                    msg.sol_in[23].sensor_type
                );
                assert_eq!(
                    msg.sol_in[24].flags, 123,
                    "incorrect value for sol_in[24].flags, expected 123, is {}",
                    msg.sol_in[24].flags
                );
                assert_eq!(
                    msg.sol_in[24].sensor_type, 238,
                    "incorrect value for sol_in[24].sensor_type, expected 238, is {}",
                    msg.sol_in[24].sensor_type
                );
                assert_eq!(
                    msg.sol_in[25].flags, 230,
                    "incorrect value for sol_in[25].flags, expected 230, is {}",
                    msg.sol_in[25].flags
                );
                assert_eq!(
                    msg.sol_in[25].sensor_type, 102,
                    "incorrect value for sol_in[25].sensor_type, expected 102, is {}",
                    msg.sol_in[25].sensor_type
                );
                assert_eq!(
                    msg.sol_in[26].flags, 190,
                    "incorrect value for sol_in[26].flags, expected 190, is {}",
                    msg.sol_in[26].flags
                );
                assert_eq!(
                    msg.sol_in[26].sensor_type, 76,
                    "incorrect value for sol_in[26].sensor_type, expected 76, is {}",
                    msg.sol_in[26].sensor_type
                );
                assert_eq!(
                    msg.sol_in[27].flags, 182,
                    "incorrect value for sol_in[27].flags, expected 182, is {}",
                    msg.sol_in[27].flags
                );
                assert_eq!(
                    msg.sol_in[27].sensor_type, 225,
                    "incorrect value for sol_in[27].sensor_type, expected 225, is {}",
                    msg.sol_in[27].sensor_type
                );
                assert_eq!(
                    msg.sol_in[28].flags, 228,
                    "incorrect value for sol_in[28].flags, expected 228, is {}",
                    msg.sol_in[28].flags
                );
                assert_eq!(
                    msg.sol_in[28].sensor_type, 207,
                    "incorrect value for sol_in[28].sensor_type, expected 207, is {}",
                    msg.sol_in[28].sensor_type
                );
                assert_eq!(
                    msg.sol_in[29].flags, 218,
                    "incorrect value for sol_in[29].flags, expected 218, is {}",
                    msg.sol_in[29].flags
                );
                assert_eq!(
                    msg.sol_in[29].sensor_type, 7,
                    "incorrect value for sol_in[29].sensor_type, expected 7, is {}",
                    msg.sol_in[29].sensor_type
                );
                assert_eq!(
                    msg.sol_in[30].flags, 89,
                    "incorrect value for sol_in[30].flags, expected 89, is {}",
                    msg.sol_in[30].flags
                );
                assert_eq!(
                    msg.sol_in[30].sensor_type, 117,
                    "incorrect value for sol_in[30].sensor_type, expected 117, is {}",
                    msg.sol_in[30].sensor_type
                );
                assert_eq!(
                    msg.sol_in[31].flags, 191,
                    "incorrect value for sol_in[31].flags, expected 191, is {}",
                    msg.sol_in[31].flags
                );
                assert_eq!(
                    msg.sol_in[31].sensor_type, 29,
                    "incorrect value for sol_in[31].sensor_type, expected 29, is {}",
                    msg.sol_in[31].sensor_type
                );
                assert_eq!(
                    msg.sol_in[32].flags, 248,
                    "incorrect value for sol_in[32].flags, expected 248, is {}",
                    msg.sol_in[32].flags
                );
                assert_eq!(
                    msg.sol_in[32].sensor_type, 56,
                    "incorrect value for sol_in[32].sensor_type, expected 56, is {}",
                    msg.sol_in[32].sensor_type
                );
                assert_eq!(
                    msg.sol_in[33].flags, 255,
                    "incorrect value for sol_in[33].flags, expected 255, is {}",
                    msg.sol_in[33].flags
                );
                assert_eq!(
                    msg.sol_in[33].sensor_type, 185,
                    "incorrect value for sol_in[33].sensor_type, expected 185, is {}",
                    msg.sol_in[33].sensor_type
                );
                assert_eq!(
                    msg.sol_in[34].flags, 18,
                    "incorrect value for sol_in[34].flags, expected 18, is {}",
                    msg.sol_in[34].flags
                );
                assert_eq!(
                    msg.sol_in[34].sensor_type, 46,
                    "incorrect value for sol_in[34].sensor_type, expected 46, is {}",
                    msg.sol_in[34].sensor_type
                );
                assert_eq!(
                    msg.sol_in[35].flags, 142,
                    "incorrect value for sol_in[35].flags, expected 142, is {}",
                    msg.sol_in[35].flags
                );
                assert_eq!(
                    msg.sol_in[35].sensor_type, 72,
                    "incorrect value for sol_in[35].sensor_type, expected 72, is {}",
                    msg.sol_in[35].sensor_type
                );
                assert_eq!(
                    msg.sol_in[36].flags, 113,
                    "incorrect value for sol_in[36].flags, expected 113, is {}",
                    msg.sol_in[36].flags
                );
                assert_eq!(
                    msg.sol_in[36].sensor_type, 82,
                    "incorrect value for sol_in[36].sensor_type, expected 82, is {}",
                    msg.sol_in[36].sensor_type
                );
                assert_eq!(
                    msg.sol_in[37].flags, 4,
                    "incorrect value for sol_in[37].flags, expected 4, is {}",
                    msg.sol_in[37].flags
                );
                assert_eq!(
                    msg.sol_in[37].sensor_type, 26,
                    "incorrect value for sol_in[37].sensor_type, expected 26, is {}",
                    msg.sol_in[37].sensor_type
                );
                assert_eq!(
                    msg.sol_in[38].flags, 254,
                    "incorrect value for sol_in[38].flags, expected 254, is {}",
                    msg.sol_in[38].flags
                );
                assert_eq!(
                    msg.sol_in[38].sensor_type, 172,
                    "incorrect value for sol_in[38].sensor_type, expected 172, is {}",
                    msg.sol_in[38].sensor_type
                );
                assert_eq!(
                    msg.sol_in[39].flags, 136,
                    "incorrect value for sol_in[39].flags, expected 136, is {}",
                    msg.sol_in[39].flags
                );
                assert_eq!(
                    msg.sol_in[39].sensor_type, 178,
                    "incorrect value for sol_in[39].sensor_type, expected 178, is {}",
                    msg.sol_in[39].sensor_type
                );
                assert_eq!(
                    msg.sol_in[40].flags, 115,
                    "incorrect value for sol_in[40].flags, expected 115, is {}",
                    msg.sol_in[40].flags
                );
                assert_eq!(
                    msg.sol_in[40].sensor_type, 113,
                    "incorrect value for sol_in[40].sensor_type, expected 113, is {}",
                    msg.sol_in[40].sensor_type
                );
                assert_eq!(
                    msg.sol_in[41].flags, 193,
                    "incorrect value for sol_in[41].flags, expected 193, is {}",
                    msg.sol_in[41].flags
                );
                assert_eq!(
                    msg.sol_in[41].sensor_type, 58,
                    "incorrect value for sol_in[41].sensor_type, expected 58, is {}",
                    msg.sol_in[41].sensor_type
                );
                assert_eq!(
                    msg.sol_in[42].flags, 227,
                    "incorrect value for sol_in[42].flags, expected 227, is {}",
                    msg.sol_in[42].flags
                );
                assert_eq!(
                    msg.sol_in[42].sensor_type, 89,
                    "incorrect value for sol_in[42].sensor_type, expected 89, is {}",
                    msg.sol_in[42].sensor_type
                );
                assert_eq!(
                    msg.sol_in[43].flags, 246,
                    "incorrect value for sol_in[43].flags, expected 246, is {}",
                    msg.sol_in[43].flags
                );
                assert_eq!(
                    msg.sol_in[43].sensor_type, 182,
                    "incorrect value for sol_in[43].sensor_type, expected 182, is {}",
                    msg.sol_in[43].sensor_type
                );
                assert_eq!(
                    msg.sol_in[44].flags, 77,
                    "incorrect value for sol_in[44].flags, expected 77, is {}",
                    msg.sol_in[44].flags
                );
                assert_eq!(
                    msg.sol_in[44].sensor_type, 76,
                    "incorrect value for sol_in[44].sensor_type, expected 76, is {}",
                    msg.sol_in[44].sensor_type
                );
                assert_eq!(
                    msg.sol_in[45].flags, 245,
                    "incorrect value for sol_in[45].flags, expected 245, is {}",
                    msg.sol_in[45].flags
                );
                assert_eq!(
                    msg.sol_in[45].sensor_type, 108,
                    "incorrect value for sol_in[45].sensor_type, expected 108, is {}",
                    msg.sol_in[45].sensor_type
                );
                assert_eq!(
                    msg.sol_in[46].flags, 31,
                    "incorrect value for sol_in[46].flags, expected 31, is {}",
                    msg.sol_in[46].flags
                );
                assert_eq!(
                    msg.sol_in[46].sensor_type, 41,
                    "incorrect value for sol_in[46].sensor_type, expected 41, is {}",
                    msg.sol_in[46].sensor_type
                );
                assert_eq!(
                    msg.sol_in[47].flags, 124,
                    "incorrect value for sol_in[47].flags, expected 124, is {}",
                    msg.sol_in[47].flags
                );
                assert_eq!(
                    msg.sol_in[47].sensor_type, 70,
                    "incorrect value for sol_in[47].sensor_type, expected 70, is {}",
                    msg.sol_in[47].sensor_type
                );
                assert_eq!(
                    msg.sol_in[48].flags, 145,
                    "incorrect value for sol_in[48].flags, expected 145, is {}",
                    msg.sol_in[48].flags
                );
                assert_eq!(
                    msg.sol_in[48].sensor_type, 249,
                    "incorrect value for sol_in[48].sensor_type, expected 249, is {}",
                    msg.sol_in[48].sensor_type
                );
                assert_eq!(
                    msg.sol_in[49].flags, 78,
                    "incorrect value for sol_in[49].flags, expected 78, is {}",
                    msg.sol_in[49].flags
                );
                assert_eq!(
                    msg.sol_in[49].sensor_type, 15,
                    "incorrect value for sol_in[49].sensor_type, expected 15, is {}",
                    msg.sol_in[49].sensor_type
                );
                assert_eq!(
                    msg.sol_in[50].flags, 38,
                    "incorrect value for sol_in[50].flags, expected 38, is {}",
                    msg.sol_in[50].flags
                );
                assert_eq!(
                    msg.sol_in[50].sensor_type, 228,
                    "incorrect value for sol_in[50].sensor_type, expected 228, is {}",
                    msg.sol_in[50].sensor_type
                );
                assert_eq!(
                    msg.sol_in[51].flags, 129,
                    "incorrect value for sol_in[51].flags, expected 129, is {}",
                    msg.sol_in[51].flags
                );
                assert_eq!(
                    msg.sol_in[51].sensor_type, 241,
                    "incorrect value for sol_in[51].sensor_type, expected 241, is {}",
                    msg.sol_in[51].sensor_type
                );
                assert_eq!(
                    msg.sol_in[52].flags, 176,
                    "incorrect value for sol_in[52].flags, expected 176, is {}",
                    msg.sol_in[52].flags
                );
                assert_eq!(
                    msg.sol_in[52].sensor_type, 8,
                    "incorrect value for sol_in[52].sensor_type, expected 8, is {}",
                    msg.sol_in[52].sensor_type
                );
                assert_eq!(
                    msg.sol_in[53].flags, 72,
                    "incorrect value for sol_in[53].flags, expected 72, is {}",
                    msg.sol_in[53].flags
                );
                assert_eq!(
                    msg.sol_in[53].sensor_type, 251,
                    "incorrect value for sol_in[53].sensor_type, expected 251, is {}",
                    msg.sol_in[53].sensor_type
                );
                assert_eq!(
                    msg.sol_in[54].flags, 80,
                    "incorrect value for sol_in[54].flags, expected 80, is {}",
                    msg.sol_in[54].flags
                );
                assert_eq!(
                    msg.sol_in[54].sensor_type, 248,
                    "incorrect value for sol_in[54].sensor_type, expected 248, is {}",
                    msg.sol_in[54].sensor_type
                );
                assert_eq!(
                    msg.sol_in[55].flags, 244,
                    "incorrect value for sol_in[55].flags, expected 244, is {}",
                    msg.sol_in[55].flags
                );
                assert_eq!(
                    msg.sol_in[55].sensor_type, 115,
                    "incorrect value for sol_in[55].sensor_type, expected 115, is {}",
                    msg.sol_in[55].sensor_type
                );
                assert_eq!(
                    msg.sol_in[56].flags, 145,
                    "incorrect value for sol_in[56].flags, expected 145, is {}",
                    msg.sol_in[56].flags
                );
                assert_eq!(
                    msg.sol_in[56].sensor_type, 231,
                    "incorrect value for sol_in[56].sensor_type, expected 231, is {}",
                    msg.sol_in[56].sensor_type
                );
                assert_eq!(
                    msg.sol_in[57].flags, 190,
                    "incorrect value for sol_in[57].flags, expected 190, is {}",
                    msg.sol_in[57].flags
                );
                assert_eq!(
                    msg.sol_in[57].sensor_type, 191,
                    "incorrect value for sol_in[57].sensor_type, expected 191, is {}",
                    msg.sol_in[57].sensor_type
                );
                assert_eq!(
                    msg.sol_in[58].flags, 168,
                    "incorrect value for sol_in[58].flags, expected 168, is {}",
                    msg.sol_in[58].flags
                );
                assert_eq!(
                    msg.sol_in[58].sensor_type, 178,
                    "incorrect value for sol_in[58].sensor_type, expected 178, is {}",
                    msg.sol_in[58].sensor_type
                );
                assert_eq!(
                    msg.sol_in[59].flags, 233,
                    "incorrect value for sol_in[59].flags, expected 233, is {}",
                    msg.sol_in[59].flags
                );
                assert_eq!(
                    msg.sol_in[59].sensor_type, 89,
                    "incorrect value for sol_in[59].sensor_type, expected 89, is {}",
                    msg.sol_in[59].sensor_type
                );
                assert_eq!(
                    msg.sol_in[60].flags, 176,
                    "incorrect value for sol_in[60].flags, expected 176, is {}",
                    msg.sol_in[60].flags
                );
                assert_eq!(
                    msg.sol_in[60].sensor_type, 69,
                    "incorrect value for sol_in[60].sensor_type, expected 69, is {}",
                    msg.sol_in[60].sensor_type
                );
                assert_eq!(
                    msg.sol_in[61].flags, 140,
                    "incorrect value for sol_in[61].flags, expected 140, is {}",
                    msg.sol_in[61].flags
                );
                assert_eq!(
                    msg.sol_in[61].sensor_type, 174,
                    "incorrect value for sol_in[61].sensor_type, expected 174, is {}",
                    msg.sol_in[61].sensor_type
                );
                assert_eq!(
                    msg.sol_in[62].flags, 141,
                    "incorrect value for sol_in[62].flags, expected 141, is {}",
                    msg.sol_in[62].flags
                );
                assert_eq!(
                    msg.sol_in[62].sensor_type, 182,
                    "incorrect value for sol_in[62].sensor_type, expected 182, is {}",
                    msg.sol_in[62].sensor_type
                );
                assert_eq!(
                    msg.sol_in[63].flags, 82,
                    "incorrect value for sol_in[63].flags, expected 82, is {}",
                    msg.sol_in[63].flags
                );
                assert_eq!(
                    msg.sol_in[63].sensor_type, 81,
                    "incorrect value for sol_in[63].sensor_type, expected 81, is {}",
                    msg.sol_in[63].sensor_type
                );
                assert_eq!(
                    msg.sol_in[64].flags, 79,
                    "incorrect value for sol_in[64].flags, expected 79, is {}",
                    msg.sol_in[64].flags
                );
                assert_eq!(
                    msg.sol_in[64].sensor_type, 92,
                    "incorrect value for sol_in[64].sensor_type, expected 92, is {}",
                    msg.sol_in[64].sensor_type
                );
                assert_eq!(
                    msg.sol_in[65].flags, 223,
                    "incorrect value for sol_in[65].flags, expected 223, is {}",
                    msg.sol_in[65].flags
                );
                assert_eq!(
                    msg.sol_in[65].sensor_type, 101,
                    "incorrect value for sol_in[65].sensor_type, expected 101, is {}",
                    msg.sol_in[65].sensor_type
                );
                assert_eq!(
                    msg.sol_in[66].flags, 64,
                    "incorrect value for sol_in[66].flags, expected 64, is {}",
                    msg.sol_in[66].flags
                );
                assert_eq!(
                    msg.sol_in[66].sensor_type, 100,
                    "incorrect value for sol_in[66].sensor_type, expected 100, is {}",
                    msg.sol_in[66].sensor_type
                );
                assert_eq!(
                    msg.sol_in[67].flags, 215,
                    "incorrect value for sol_in[67].flags, expected 215, is {}",
                    msg.sol_in[67].flags
                );
                assert_eq!(
                    msg.sol_in[67].sensor_type, 184,
                    "incorrect value for sol_in[67].sensor_type, expected 184, is {}",
                    msg.sol_in[67].sensor_type
                );
                assert_eq!(
                    msg.sol_in[68].flags, 37,
                    "incorrect value for sol_in[68].flags, expected 37, is {}",
                    msg.sol_in[68].flags
                );
                assert_eq!(
                    msg.sol_in[68].sensor_type, 124,
                    "incorrect value for sol_in[68].sensor_type, expected 124, is {}",
                    msg.sol_in[68].sensor_type
                );
                assert_eq!(
                    msg.sol_in[69].flags, 227,
                    "incorrect value for sol_in[69].flags, expected 227, is {}",
                    msg.sol_in[69].flags
                );
                assert_eq!(
                    msg.sol_in[69].sensor_type, 21,
                    "incorrect value for sol_in[69].sensor_type, expected 21, is {}",
                    msg.sol_in[69].sensor_type
                );
                assert_eq!(
                    msg.sol_in[70].flags, 102,
                    "incorrect value for sol_in[70].flags, expected 102, is {}",
                    msg.sol_in[70].flags
                );
                assert_eq!(
                    msg.sol_in[70].sensor_type, 135,
                    "incorrect value for sol_in[70].sensor_type, expected 135, is {}",
                    msg.sol_in[70].sensor_type
                );
                assert_eq!(
                    msg.sol_in[71].flags, 36,
                    "incorrect value for sol_in[71].flags, expected 36, is {}",
                    msg.sol_in[71].flags
                );
                assert_eq!(
                    msg.sol_in[71].sensor_type, 72,
                    "incorrect value for sol_in[71].sensor_type, expected 72, is {}",
                    msg.sol_in[71].sensor_type
                );
                assert_eq!(
                    msg.sol_in[72].flags, 56,
                    "incorrect value for sol_in[72].flags, expected 56, is {}",
                    msg.sol_in[72].flags
                );
                assert_eq!(
                    msg.sol_in[72].sensor_type, 219,
                    "incorrect value for sol_in[72].sensor_type, expected 219, is {}",
                    msg.sol_in[72].sensor_type
                );
                assert_eq!(
                    msg.sol_in[73].flags, 90,
                    "incorrect value for sol_in[73].flags, expected 90, is {}",
                    msg.sol_in[73].flags
                );
                assert_eq!(
                    msg.sol_in[73].sensor_type, 146,
                    "incorrect value for sol_in[73].sensor_type, expected 146, is {}",
                    msg.sol_in[73].sensor_type
                );
                assert_eq!(
                    msg.sol_in[74].flags, 104,
                    "incorrect value for sol_in[74].flags, expected 104, is {}",
                    msg.sol_in[74].flags
                );
                assert_eq!(
                    msg.sol_in[74].sensor_type, 219,
                    "incorrect value for sol_in[74].sensor_type, expected 219, is {}",
                    msg.sol_in[74].sensor_type
                );
                assert_eq!(
                    msg.sol_in[75].flags, 102,
                    "incorrect value for sol_in[75].flags, expected 102, is {}",
                    msg.sol_in[75].flags
                );
                assert_eq!(
                    msg.sol_in[75].sensor_type, 227,
                    "incorrect value for sol_in[75].sensor_type, expected 227, is {}",
                    msg.sol_in[75].sensor_type
                );
                assert_eq!(
                    msg.sol_in[76].flags, 12,
                    "incorrect value for sol_in[76].flags, expected 12, is {}",
                    msg.sol_in[76].flags
                );
                assert_eq!(
                    msg.sol_in[76].sensor_type, 83,
                    "incorrect value for sol_in[76].sensor_type, expected 83, is {}",
                    msg.sol_in[76].sensor_type
                );
                assert_eq!(
                    msg.sol_in[77].flags, 122,
                    "incorrect value for sol_in[77].flags, expected 122, is {}",
                    msg.sol_in[77].flags
                );
                assert_eq!(
                    msg.sol_in[77].sensor_type, 41,
                    "incorrect value for sol_in[77].sensor_type, expected 41, is {}",
                    msg.sol_in[77].sensor_type
                );
                assert_eq!(
                    msg.sol_in[78].flags, 94,
                    "incorrect value for sol_in[78].flags, expected 94, is {}",
                    msg.sol_in[78].flags
                );
                assert_eq!(
                    msg.sol_in[78].sensor_type, 173,
                    "incorrect value for sol_in[78].sensor_type, expected 173, is {}",
                    msg.sol_in[78].sensor_type
                );
                assert_eq!(
                    msg.sol_in[79].flags, 174,
                    "incorrect value for sol_in[79].flags, expected 174, is {}",
                    msg.sol_in[79].flags
                );
                assert_eq!(
                    msg.sol_in[79].sensor_type, 1,
                    "incorrect value for sol_in[79].sensor_type, expected 1, is {}",
                    msg.sol_in[79].sensor_type
                );
                assert_eq!(
                    msg.sol_in[80].flags, 130,
                    "incorrect value for sol_in[80].flags, expected 130, is {}",
                    msg.sol_in[80].flags
                );
                assert_eq!(
                    msg.sol_in[80].sensor_type, 134,
                    "incorrect value for sol_in[80].sensor_type, expected 134, is {}",
                    msg.sol_in[80].sensor_type
                );
                assert_eq!(
                    msg.sol_in[81].flags, 237,
                    "incorrect value for sol_in[81].flags, expected 237, is {}",
                    msg.sol_in[81].flags
                );
                assert_eq!(
                    msg.sol_in[81].sensor_type, 104,
                    "incorrect value for sol_in[81].sensor_type, expected 104, is {}",
                    msg.sol_in[81].sensor_type
                );
                assert_eq!(
                    msg.sol_in[82].flags, 249,
                    "incorrect value for sol_in[82].flags, expected 249, is {}",
                    msg.sol_in[82].flags
                );
                assert_eq!(
                    msg.sol_in[82].sensor_type, 116,
                    "incorrect value for sol_in[82].sensor_type, expected 116, is {}",
                    msg.sol_in[82].sensor_type
                );
                assert_eq!(
                    msg.sol_in[83].flags, 230,
                    "incorrect value for sol_in[83].flags, expected 230, is {}",
                    msg.sol_in[83].flags
                );
                assert_eq!(
                    msg.sol_in[83].sensor_type, 107,
                    "incorrect value for sol_in[83].sensor_type, expected 107, is {}",
                    msg.sol_in[83].sensor_type
                );
                assert_eq!(
                    msg.sol_in[84].flags, 123,
                    "incorrect value for sol_in[84].flags, expected 123, is {}",
                    msg.sol_in[84].flags
                );
                assert_eq!(
                    msg.sol_in[84].sensor_type, 130,
                    "incorrect value for sol_in[84].sensor_type, expected 130, is {}",
                    msg.sol_in[84].sensor_type
                );
                assert_eq!(
                    msg.sol_in[85].flags, 162,
                    "incorrect value for sol_in[85].flags, expected 162, is {}",
                    msg.sol_in[85].flags
                );
                assert_eq!(
                    msg.sol_in[85].sensor_type, 25,
                    "incorrect value for sol_in[85].sensor_type, expected 25, is {}",
                    msg.sol_in[85].sensor_type
                );
                assert_eq!(
                    msg.sol_in[86].flags, 223,
                    "incorrect value for sol_in[86].flags, expected 223, is {}",
                    msg.sol_in[86].flags
                );
                assert_eq!(
                    msg.sol_in[86].sensor_type, 57,
                    "incorrect value for sol_in[86].sensor_type, expected 57, is {}",
                    msg.sol_in[86].sensor_type
                );
                assert_eq!(
                    msg.sol_in[87].flags, 174,
                    "incorrect value for sol_in[87].flags, expected 174, is {}",
                    msg.sol_in[87].flags
                );
                assert_eq!(
                    msg.sol_in[87].sensor_type, 193,
                    "incorrect value for sol_in[87].sensor_type, expected 193, is {}",
                    msg.sol_in[87].sensor_type
                );
                assert_eq!(
                    msg.sol_in[88].flags, 193,
                    "incorrect value for sol_in[88].flags, expected 193, is {}",
                    msg.sol_in[88].flags
                );
                assert_eq!(
                    msg.sol_in[88].sensor_type, 146,
                    "incorrect value for sol_in[88].sensor_type, expected 146, is {}",
                    msg.sol_in[88].sensor_type
                );
                assert_eq!(
                    msg.sol_in[89].flags, 44,
                    "incorrect value for sol_in[89].flags, expected 44, is {}",
                    msg.sol_in[89].flags
                );
                assert_eq!(
                    msg.sol_in[89].sensor_type, 239,
                    "incorrect value for sol_in[89].sensor_type, expected 239, is {}",
                    msg.sol_in[89].sensor_type
                );
                assert_eq!(
                    msg.sol_in[90].flags, 197,
                    "incorrect value for sol_in[90].flags, expected 197, is {}",
                    msg.sol_in[90].flags
                );
                assert_eq!(
                    msg.sol_in[90].sensor_type, 246,
                    "incorrect value for sol_in[90].sensor_type, expected 246, is {}",
                    msg.sol_in[90].sensor_type
                );
                assert_eq!(
                    msg.sol_in[91].flags, 80,
                    "incorrect value for sol_in[91].flags, expected 80, is {}",
                    msg.sol_in[91].flags
                );
                assert_eq!(
                    msg.sol_in[91].sensor_type, 214,
                    "incorrect value for sol_in[91].sensor_type, expected 214, is {}",
                    msg.sol_in[91].sensor_type
                );
                assert_eq!(
                    msg.sol_in[92].flags, 100,
                    "incorrect value for sol_in[92].flags, expected 100, is {}",
                    msg.sol_in[92].flags
                );
                assert_eq!(
                    msg.sol_in[92].sensor_type, 83,
                    "incorrect value for sol_in[92].sensor_type, expected 83, is {}",
                    msg.sol_in[92].sensor_type
                );
                assert_eq!(
                    msg.sol_in[93].flags, 72,
                    "incorrect value for sol_in[93].flags, expected 72, is {}",
                    msg.sol_in[93].flags
                );
                assert_eq!(
                    msg.sol_in[93].sensor_type, 66,
                    "incorrect value for sol_in[93].sensor_type, expected 66, is {}",
                    msg.sol_in[93].sensor_type
                );
                assert_eq!(
                    msg.sol_in[94].flags, 137,
                    "incorrect value for sol_in[94].flags, expected 137, is {}",
                    msg.sol_in[94].flags
                );
                assert_eq!(
                    msg.sol_in[94].sensor_type, 133,
                    "incorrect value for sol_in[94].sensor_type, expected 133, is {}",
                    msg.sol_in[94].sensor_type
                );
                assert_eq!(
                    msg.sol_in[95].flags, 82,
                    "incorrect value for sol_in[95].flags, expected 82, is {}",
                    msg.sol_in[95].flags
                );
                assert_eq!(
                    msg.sol_in[95].sensor_type, 140,
                    "incorrect value for sol_in[95].sensor_type, expected 140, is {}",
                    msg.sol_in[95].sensor_type
                );
                assert_eq!(
                    msg.sol_in[96].flags, 2,
                    "incorrect value for sol_in[96].flags, expected 2, is {}",
                    msg.sol_in[96].flags
                );
                assert_eq!(
                    msg.sol_in[96].sensor_type, 2,
                    "incorrect value for sol_in[96].sensor_type, expected 2, is {}",
                    msg.sol_in[96].sensor_type
                );
                assert_eq!(
                    msg.sol_in[97].flags, 9,
                    "incorrect value for sol_in[97].flags, expected 9, is {}",
                    msg.sol_in[97].flags
                );
                assert_eq!(
                    msg.sol_in[97].sensor_type, 96,
                    "incorrect value for sol_in[97].sensor_type, expected 96, is {}",
                    msg.sol_in[97].sensor_type
                );
                assert_eq!(
                    msg.sol_in[98].flags, 158,
                    "incorrect value for sol_in[98].flags, expected 158, is {}",
                    msg.sol_in[98].flags
                );
                assert_eq!(
                    msg.sol_in[98].sensor_type, 96,
                    "incorrect value for sol_in[98].sensor_type, expected 96, is {}",
                    msg.sol_in[98].sensor_type
                );
                assert_eq!(
                    msg.sol_in[99].flags, 97,
                    "incorrect value for sol_in[99].flags, expected 97, is {}",
                    msg.sol_in[99].flags
                );
                assert_eq!(
                    msg.sol_in[99].sensor_type, 134,
                    "incorrect value for sol_in[99].sensor_type, expected 134, is {}",
                    msg.sol_in[99].sensor_type
                );
                assert_eq!(
                    msg.sol_in[100].flags, 129,
                    "incorrect value for sol_in[100].flags, expected 129, is {}",
                    msg.sol_in[100].flags
                );
                assert_eq!(
                    msg.sol_in[100].sensor_type, 43,
                    "incorrect value for sol_in[100].sensor_type, expected 43, is {}",
                    msg.sol_in[100].sensor_type
                );
                assert_eq!(
                    msg.sol_in[101].flags, 25,
                    "incorrect value for sol_in[101].flags, expected 25, is {}",
                    msg.sol_in[101].flags
                );
                assert_eq!(
                    msg.sol_in[101].sensor_type, 141,
                    "incorrect value for sol_in[101].sensor_type, expected 141, is {}",
                    msg.sol_in[101].sensor_type
                );
                assert_eq!(
                    msg.sol_in[102].flags, 200,
                    "incorrect value for sol_in[102].flags, expected 200, is {}",
                    msg.sol_in[102].flags
                );
                assert_eq!(
                    msg.sol_in[102].sensor_type, 183,
                    "incorrect value for sol_in[102].sensor_type, expected 183, is {}",
                    msg.sol_in[102].sensor_type
                );
                assert_eq!(
                    msg.sol_in[103].flags, 57,
                    "incorrect value for sol_in[103].flags, expected 57, is {}",
                    msg.sol_in[103].flags
                );
                assert_eq!(
                    msg.sol_in[103].sensor_type, 214,
                    "incorrect value for sol_in[103].sensor_type, expected 214, is {}",
                    msg.sol_in[103].sensor_type
                );
                assert_eq!(
                    msg.sol_in[104].flags, 103,
                    "incorrect value for sol_in[104].flags, expected 103, is {}",
                    msg.sol_in[104].flags
                );
                assert_eq!(
                    msg.sol_in[104].sensor_type, 248,
                    "incorrect value for sol_in[104].sensor_type, expected 248, is {}",
                    msg.sol_in[104].sensor_type
                );
                assert_eq!(
                    msg.sol_in[105].flags, 65,
                    "incorrect value for sol_in[105].flags, expected 65, is {}",
                    msg.sol_in[105].flags
                );
                assert_eq!(
                    msg.sol_in[105].sensor_type, 222,
                    "incorrect value for sol_in[105].sensor_type, expected 222, is {}",
                    msg.sol_in[105].sensor_type
                );
                assert_eq!(
                    msg.sol_in[106].flags, 15,
                    "incorrect value for sol_in[106].flags, expected 15, is {}",
                    msg.sol_in[106].flags
                );
                assert_eq!(
                    msg.sol_in[106].sensor_type, 195,
                    "incorrect value for sol_in[106].sensor_type, expected 195, is {}",
                    msg.sol_in[106].sensor_type
                );
                assert_eq!(
                    msg.sol_in[107].flags, 21,
                    "incorrect value for sol_in[107].flags, expected 21, is {}",
                    msg.sol_in[107].flags
                );
                assert_eq!(
                    msg.sol_in[107].sensor_type, 244,
                    "incorrect value for sol_in[107].sensor_type, expected 244, is {}",
                    msg.sol_in[107].sensor_type
                );
                assert_eq!(
                    msg.sol_in[108].flags, 46,
                    "incorrect value for sol_in[108].flags, expected 46, is {}",
                    msg.sol_in[108].flags
                );
                assert_eq!(
                    msg.sol_in[108].sensor_type, 180,
                    "incorrect value for sol_in[108].sensor_type, expected 180, is {}",
                    msg.sol_in[108].sensor_type
                );
                assert_eq!(
                    msg.sol_in[109].flags, 130,
                    "incorrect value for sol_in[109].flags, expected 130, is {}",
                    msg.sol_in[109].flags
                );
                assert_eq!(
                    msg.sol_in[109].sensor_type, 140,
                    "incorrect value for sol_in[109].sensor_type, expected 140, is {}",
                    msg.sol_in[109].sensor_type
                );
                assert_eq!(
                    msg.sol_in[110].flags, 17,
                    "incorrect value for sol_in[110].flags, expected 17, is {}",
                    msg.sol_in[110].flags
                );
                assert_eq!(
                    msg.sol_in[110].sensor_type, 36,
                    "incorrect value for sol_in[110].sensor_type, expected 36, is {}",
                    msg.sol_in[110].sensor_type
                );
                assert_eq!(
                    msg.sol_in[111].flags, 209,
                    "incorrect value for sol_in[111].flags, expected 209, is {}",
                    msg.sol_in[111].flags
                );
                assert_eq!(
                    msg.sol_in[111].sensor_type, 194,
                    "incorrect value for sol_in[111].sensor_type, expected 194, is {}",
                    msg.sol_in[111].sensor_type
                );
                assert_eq!(
                    msg.sol_in[112].flags, 254,
                    "incorrect value for sol_in[112].flags, expected 254, is {}",
                    msg.sol_in[112].flags
                );
                assert_eq!(
                    msg.sol_in[112].sensor_type, 65,
                    "incorrect value for sol_in[112].sensor_type, expected 65, is {}",
                    msg.sol_in[112].sensor_type
                );
                assert_eq!(
                    msg.sol_in[113].flags, 103,
                    "incorrect value for sol_in[113].flags, expected 103, is {}",
                    msg.sol_in[113].flags
                );
                assert_eq!(
                    msg.sol_in[113].sensor_type, 115,
                    "incorrect value for sol_in[113].sensor_type, expected 115, is {}",
                    msg.sol_in[113].sensor_type
                );
                assert_eq!(
                    msg.sol_in[114].flags, 129,
                    "incorrect value for sol_in[114].flags, expected 129, is {}",
                    msg.sol_in[114].flags
                );
                assert_eq!(
                    msg.sol_in[114].sensor_type, 152,
                    "incorrect value for sol_in[114].sensor_type, expected 152, is {}",
                    msg.sol_in[114].sensor_type
                );
                assert_eq!(
                    msg.sol_in[115].flags, 235,
                    "incorrect value for sol_in[115].flags, expected 235, is {}",
                    msg.sol_in[115].flags
                );
                assert_eq!(
                    msg.sol_in[115].sensor_type, 234,
                    "incorrect value for sol_in[115].sensor_type, expected 234, is {}",
                    msg.sol_in[115].sensor_type
                );
                assert_eq!(
                    msg.sol_in[116].flags, 234,
                    "incorrect value for sol_in[116].flags, expected 234, is {}",
                    msg.sol_in[116].flags
                );
                assert_eq!(
                    msg.sol_in[116].sensor_type, 194,
                    "incorrect value for sol_in[116].sensor_type, expected 194, is {}",
                    msg.sol_in[116].sensor_type
                );
                assert_eq!(
                    msg.sol_in[117].flags, 201,
                    "incorrect value for sol_in[117].flags, expected 201, is {}",
                    msg.sol_in[117].flags
                );
                assert_eq!(
                    msg.sol_in[117].sensor_type, 170,
                    "incorrect value for sol_in[117].sensor_type, expected 170, is {}",
                    msg.sol_in[117].sensor_type
                );
                assert_eq!(
                    msg.sol_in[118].flags, 154,
                    "incorrect value for sol_in[118].flags, expected 154, is {}",
                    msg.sol_in[118].flags
                );
                assert_eq!(
                    msg.sol_in[118].sensor_type, 210,
                    "incorrect value for sol_in[118].sensor_type, expected 210, is {}",
                    msg.sol_in[118].sensor_type
                );
                assert_eq!(
                    msg.tow, 3628191792,
                    "incorrect value for tow, expected 3628191792, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 58512,
                    "incorrect value for vdop, expected 58512, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSolnMeta"),
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
fn test_json2sbp_auto_check_sbp_solution_meta_msg_soln_meta() {
    {
        let json_input = r#"{"crc":63382,"length":254,"msg_type":65294,"payload":"MNBB2HotxKCQ5AhTWVcD1V9tVoNHRlRJgxpS94xhc252/QJ6upR6lLTnRC6+ZvMwwA/QWTgK9QL+yXggfgJToe57ZuZMvuG2z+QH2nVZHb84+Ln/LhJIjlJxGgSs/rKIcXM6wVnjtvZMTWz1KR9GfPmRD07kJvGBCLD7SPhQc/Tnkb++sqhZ6UWwroy2jVFSXE9l32RAuNd8JRXjh2ZIJNs4klrbaONmUwwpeq1eAa6GgmjtdPlr5oJ7GaI538GuksHvLPbF1lBTZEJIhYmMUgICYAlgnoZhK4GNGbfI1jn4Z95Bww/0FbQujIIkEcLRQf5zZ5iB6uvC6qrJ0po=","preamble":85,"sender":15360,"tow":3628191792,"pdop":11642,"hdop":41156,"vdop":58512,"age_corrections":21256,"age_gnss":3573765977,"sol_in":[{"sensor_type":95,"flags":109},{"sensor_type":86,"flags":131},{"sensor_type":71,"flags":70},{"sensor_type":84,"flags":73},{"sensor_type":131,"flags":26},{"sensor_type":82,"flags":247},{"sensor_type":140,"flags":97},{"sensor_type":115,"flags":110},{"sensor_type":118,"flags":253},{"sensor_type":2,"flags":122},{"sensor_type":186,"flags":148},{"sensor_type":122,"flags":148},{"sensor_type":180,"flags":231},{"sensor_type":68,"flags":46},{"sensor_type":190,"flags":102},{"sensor_type":243,"flags":48},{"sensor_type":192,"flags":15},{"sensor_type":208,"flags":89},{"sensor_type":56,"flags":10},{"sensor_type":245,"flags":2},{"sensor_type":254,"flags":201},{"sensor_type":120,"flags":32},{"sensor_type":126,"flags":2},{"sensor_type":83,"flags":161},{"sensor_type":238,"flags":123},{"sensor_type":102,"flags":230},{"sensor_type":76,"flags":190},{"sensor_type":225,"flags":182},{"sensor_type":207,"flags":228},{"sensor_type":7,"flags":218},{"sensor_type":117,"flags":89},{"sensor_type":29,"flags":191},{"sensor_type":56,"flags":248},{"sensor_type":185,"flags":255},{"sensor_type":46,"flags":18},{"sensor_type":72,"flags":142},{"sensor_type":82,"flags":113},{"sensor_type":26,"flags":4},{"sensor_type":172,"flags":254},{"sensor_type":178,"flags":136},{"sensor_type":113,"flags":115},{"sensor_type":58,"flags":193},{"sensor_type":89,"flags":227},{"sensor_type":182,"flags":246},{"sensor_type":76,"flags":77},{"sensor_type":108,"flags":245},{"sensor_type":41,"flags":31},{"sensor_type":70,"flags":124},{"sensor_type":249,"flags":145},{"sensor_type":15,"flags":78},{"sensor_type":228,"flags":38},{"sensor_type":241,"flags":129},{"sensor_type":8,"flags":176},{"sensor_type":251,"flags":72},{"sensor_type":248,"flags":80},{"sensor_type":115,"flags":244},{"sensor_type":231,"flags":145},{"sensor_type":191,"flags":190},{"sensor_type":178,"flags":168},{"sensor_type":89,"flags":233},{"sensor_type":69,"flags":176},{"sensor_type":174,"flags":140},{"sensor_type":182,"flags":141},{"sensor_type":81,"flags":82},{"sensor_type":92,"flags":79},{"sensor_type":101,"flags":223},{"sensor_type":100,"flags":64},{"sensor_type":184,"flags":215},{"sensor_type":124,"flags":37},{"sensor_type":21,"flags":227},{"sensor_type":135,"flags":102},{"sensor_type":72,"flags":36},{"sensor_type":219,"flags":56},{"sensor_type":146,"flags":90},{"sensor_type":219,"flags":104},{"sensor_type":227,"flags":102},{"sensor_type":83,"flags":12},{"sensor_type":41,"flags":122},{"sensor_type":173,"flags":94},{"sensor_type":1,"flags":174},{"sensor_type":134,"flags":130},{"sensor_type":104,"flags":237},{"sensor_type":116,"flags":249},{"sensor_type":107,"flags":230},{"sensor_type":130,"flags":123},{"sensor_type":25,"flags":162},{"sensor_type":57,"flags":223},{"sensor_type":193,"flags":174},{"sensor_type":146,"flags":193},{"sensor_type":239,"flags":44},{"sensor_type":246,"flags":197},{"sensor_type":214,"flags":80},{"sensor_type":83,"flags":100},{"sensor_type":66,"flags":72},{"sensor_type":133,"flags":137},{"sensor_type":140,"flags":82},{"sensor_type":2,"flags":2},{"sensor_type":96,"flags":9},{"sensor_type":96,"flags":158},{"sensor_type":134,"flags":97},{"sensor_type":43,"flags":129},{"sensor_type":141,"flags":25},{"sensor_type":183,"flags":200},{"sensor_type":214,"flags":57},{"sensor_type":248,"flags":103},{"sensor_type":222,"flags":65},{"sensor_type":195,"flags":15},{"sensor_type":244,"flags":21},{"sensor_type":180,"flags":46},{"sensor_type":140,"flags":130},{"sensor_type":36,"flags":17},{"sensor_type":194,"flags":209},{"sensor_type":65,"flags":254},{"sensor_type":115,"flags":103},{"sensor_type":152,"flags":129},{"sensor_type":234,"flags":235},{"sensor_type":194,"flags":234},{"sensor_type":170,"flags":201},{"sensor_type":210,"flags":154}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSolnMeta(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff0e,
                    "Incorrect message type, expected 0xff0e, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x3c00,
                    "incorrect sender id, expected 0x3c00, is {sender_id}"
                );
                assert_eq!(
                    msg.age_corrections, 21256,
                    "incorrect value for age_corrections, expected 21256, is {}",
                    msg.age_corrections
                );
                assert_eq!(
                    msg.age_gnss, 3573765977,
                    "incorrect value for age_gnss, expected 3573765977, is {}",
                    msg.age_gnss
                );
                assert_eq!(
                    msg.hdop, 41156,
                    "incorrect value for hdop, expected 41156, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 11642,
                    "incorrect value for pdop, expected 11642, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.sol_in[0].flags, 109,
                    "incorrect value for sol_in[0].flags, expected 109, is {}",
                    msg.sol_in[0].flags
                );
                assert_eq!(
                    msg.sol_in[0].sensor_type, 95,
                    "incorrect value for sol_in[0].sensor_type, expected 95, is {}",
                    msg.sol_in[0].sensor_type
                );
                assert_eq!(
                    msg.sol_in[1].flags, 131,
                    "incorrect value for sol_in[1].flags, expected 131, is {}",
                    msg.sol_in[1].flags
                );
                assert_eq!(
                    msg.sol_in[1].sensor_type, 86,
                    "incorrect value for sol_in[1].sensor_type, expected 86, is {}",
                    msg.sol_in[1].sensor_type
                );
                assert_eq!(
                    msg.sol_in[2].flags, 70,
                    "incorrect value for sol_in[2].flags, expected 70, is {}",
                    msg.sol_in[2].flags
                );
                assert_eq!(
                    msg.sol_in[2].sensor_type, 71,
                    "incorrect value for sol_in[2].sensor_type, expected 71, is {}",
                    msg.sol_in[2].sensor_type
                );
                assert_eq!(
                    msg.sol_in[3].flags, 73,
                    "incorrect value for sol_in[3].flags, expected 73, is {}",
                    msg.sol_in[3].flags
                );
                assert_eq!(
                    msg.sol_in[3].sensor_type, 84,
                    "incorrect value for sol_in[3].sensor_type, expected 84, is {}",
                    msg.sol_in[3].sensor_type
                );
                assert_eq!(
                    msg.sol_in[4].flags, 26,
                    "incorrect value for sol_in[4].flags, expected 26, is {}",
                    msg.sol_in[4].flags
                );
                assert_eq!(
                    msg.sol_in[4].sensor_type, 131,
                    "incorrect value for sol_in[4].sensor_type, expected 131, is {}",
                    msg.sol_in[4].sensor_type
                );
                assert_eq!(
                    msg.sol_in[5].flags, 247,
                    "incorrect value for sol_in[5].flags, expected 247, is {}",
                    msg.sol_in[5].flags
                );
                assert_eq!(
                    msg.sol_in[5].sensor_type, 82,
                    "incorrect value for sol_in[5].sensor_type, expected 82, is {}",
                    msg.sol_in[5].sensor_type
                );
                assert_eq!(
                    msg.sol_in[6].flags, 97,
                    "incorrect value for sol_in[6].flags, expected 97, is {}",
                    msg.sol_in[6].flags
                );
                assert_eq!(
                    msg.sol_in[6].sensor_type, 140,
                    "incorrect value for sol_in[6].sensor_type, expected 140, is {}",
                    msg.sol_in[6].sensor_type
                );
                assert_eq!(
                    msg.sol_in[7].flags, 110,
                    "incorrect value for sol_in[7].flags, expected 110, is {}",
                    msg.sol_in[7].flags
                );
                assert_eq!(
                    msg.sol_in[7].sensor_type, 115,
                    "incorrect value for sol_in[7].sensor_type, expected 115, is {}",
                    msg.sol_in[7].sensor_type
                );
                assert_eq!(
                    msg.sol_in[8].flags, 253,
                    "incorrect value for sol_in[8].flags, expected 253, is {}",
                    msg.sol_in[8].flags
                );
                assert_eq!(
                    msg.sol_in[8].sensor_type, 118,
                    "incorrect value for sol_in[8].sensor_type, expected 118, is {}",
                    msg.sol_in[8].sensor_type
                );
                assert_eq!(
                    msg.sol_in[9].flags, 122,
                    "incorrect value for sol_in[9].flags, expected 122, is {}",
                    msg.sol_in[9].flags
                );
                assert_eq!(
                    msg.sol_in[9].sensor_type, 2,
                    "incorrect value for sol_in[9].sensor_type, expected 2, is {}",
                    msg.sol_in[9].sensor_type
                );
                assert_eq!(
                    msg.sol_in[10].flags, 148,
                    "incorrect value for sol_in[10].flags, expected 148, is {}",
                    msg.sol_in[10].flags
                );
                assert_eq!(
                    msg.sol_in[10].sensor_type, 186,
                    "incorrect value for sol_in[10].sensor_type, expected 186, is {}",
                    msg.sol_in[10].sensor_type
                );
                assert_eq!(
                    msg.sol_in[11].flags, 148,
                    "incorrect value for sol_in[11].flags, expected 148, is {}",
                    msg.sol_in[11].flags
                );
                assert_eq!(
                    msg.sol_in[11].sensor_type, 122,
                    "incorrect value for sol_in[11].sensor_type, expected 122, is {}",
                    msg.sol_in[11].sensor_type
                );
                assert_eq!(
                    msg.sol_in[12].flags, 231,
                    "incorrect value for sol_in[12].flags, expected 231, is {}",
                    msg.sol_in[12].flags
                );
                assert_eq!(
                    msg.sol_in[12].sensor_type, 180,
                    "incorrect value for sol_in[12].sensor_type, expected 180, is {}",
                    msg.sol_in[12].sensor_type
                );
                assert_eq!(
                    msg.sol_in[13].flags, 46,
                    "incorrect value for sol_in[13].flags, expected 46, is {}",
                    msg.sol_in[13].flags
                );
                assert_eq!(
                    msg.sol_in[13].sensor_type, 68,
                    "incorrect value for sol_in[13].sensor_type, expected 68, is {}",
                    msg.sol_in[13].sensor_type
                );
                assert_eq!(
                    msg.sol_in[14].flags, 102,
                    "incorrect value for sol_in[14].flags, expected 102, is {}",
                    msg.sol_in[14].flags
                );
                assert_eq!(
                    msg.sol_in[14].sensor_type, 190,
                    "incorrect value for sol_in[14].sensor_type, expected 190, is {}",
                    msg.sol_in[14].sensor_type
                );
                assert_eq!(
                    msg.sol_in[15].flags, 48,
                    "incorrect value for sol_in[15].flags, expected 48, is {}",
                    msg.sol_in[15].flags
                );
                assert_eq!(
                    msg.sol_in[15].sensor_type, 243,
                    "incorrect value for sol_in[15].sensor_type, expected 243, is {}",
                    msg.sol_in[15].sensor_type
                );
                assert_eq!(
                    msg.sol_in[16].flags, 15,
                    "incorrect value for sol_in[16].flags, expected 15, is {}",
                    msg.sol_in[16].flags
                );
                assert_eq!(
                    msg.sol_in[16].sensor_type, 192,
                    "incorrect value for sol_in[16].sensor_type, expected 192, is {}",
                    msg.sol_in[16].sensor_type
                );
                assert_eq!(
                    msg.sol_in[17].flags, 89,
                    "incorrect value for sol_in[17].flags, expected 89, is {}",
                    msg.sol_in[17].flags
                );
                assert_eq!(
                    msg.sol_in[17].sensor_type, 208,
                    "incorrect value for sol_in[17].sensor_type, expected 208, is {}",
                    msg.sol_in[17].sensor_type
                );
                assert_eq!(
                    msg.sol_in[18].flags, 10,
                    "incorrect value for sol_in[18].flags, expected 10, is {}",
                    msg.sol_in[18].flags
                );
                assert_eq!(
                    msg.sol_in[18].sensor_type, 56,
                    "incorrect value for sol_in[18].sensor_type, expected 56, is {}",
                    msg.sol_in[18].sensor_type
                );
                assert_eq!(
                    msg.sol_in[19].flags, 2,
                    "incorrect value for sol_in[19].flags, expected 2, is {}",
                    msg.sol_in[19].flags
                );
                assert_eq!(
                    msg.sol_in[19].sensor_type, 245,
                    "incorrect value for sol_in[19].sensor_type, expected 245, is {}",
                    msg.sol_in[19].sensor_type
                );
                assert_eq!(
                    msg.sol_in[20].flags, 201,
                    "incorrect value for sol_in[20].flags, expected 201, is {}",
                    msg.sol_in[20].flags
                );
                assert_eq!(
                    msg.sol_in[20].sensor_type, 254,
                    "incorrect value for sol_in[20].sensor_type, expected 254, is {}",
                    msg.sol_in[20].sensor_type
                );
                assert_eq!(
                    msg.sol_in[21].flags, 32,
                    "incorrect value for sol_in[21].flags, expected 32, is {}",
                    msg.sol_in[21].flags
                );
                assert_eq!(
                    msg.sol_in[21].sensor_type, 120,
                    "incorrect value for sol_in[21].sensor_type, expected 120, is {}",
                    msg.sol_in[21].sensor_type
                );
                assert_eq!(
                    msg.sol_in[22].flags, 2,
                    "incorrect value for sol_in[22].flags, expected 2, is {}",
                    msg.sol_in[22].flags
                );
                assert_eq!(
                    msg.sol_in[22].sensor_type, 126,
                    "incorrect value for sol_in[22].sensor_type, expected 126, is {}",
                    msg.sol_in[22].sensor_type
                );
                assert_eq!(
                    msg.sol_in[23].flags, 161,
                    "incorrect value for sol_in[23].flags, expected 161, is {}",
                    msg.sol_in[23].flags
                );
                assert_eq!(
                    msg.sol_in[23].sensor_type, 83,
                    "incorrect value for sol_in[23].sensor_type, expected 83, is {}",
                    msg.sol_in[23].sensor_type
                );
                assert_eq!(
                    msg.sol_in[24].flags, 123,
                    "incorrect value for sol_in[24].flags, expected 123, is {}",
                    msg.sol_in[24].flags
                );
                assert_eq!(
                    msg.sol_in[24].sensor_type, 238,
                    "incorrect value for sol_in[24].sensor_type, expected 238, is {}",
                    msg.sol_in[24].sensor_type
                );
                assert_eq!(
                    msg.sol_in[25].flags, 230,
                    "incorrect value for sol_in[25].flags, expected 230, is {}",
                    msg.sol_in[25].flags
                );
                assert_eq!(
                    msg.sol_in[25].sensor_type, 102,
                    "incorrect value for sol_in[25].sensor_type, expected 102, is {}",
                    msg.sol_in[25].sensor_type
                );
                assert_eq!(
                    msg.sol_in[26].flags, 190,
                    "incorrect value for sol_in[26].flags, expected 190, is {}",
                    msg.sol_in[26].flags
                );
                assert_eq!(
                    msg.sol_in[26].sensor_type, 76,
                    "incorrect value for sol_in[26].sensor_type, expected 76, is {}",
                    msg.sol_in[26].sensor_type
                );
                assert_eq!(
                    msg.sol_in[27].flags, 182,
                    "incorrect value for sol_in[27].flags, expected 182, is {}",
                    msg.sol_in[27].flags
                );
                assert_eq!(
                    msg.sol_in[27].sensor_type, 225,
                    "incorrect value for sol_in[27].sensor_type, expected 225, is {}",
                    msg.sol_in[27].sensor_type
                );
                assert_eq!(
                    msg.sol_in[28].flags, 228,
                    "incorrect value for sol_in[28].flags, expected 228, is {}",
                    msg.sol_in[28].flags
                );
                assert_eq!(
                    msg.sol_in[28].sensor_type, 207,
                    "incorrect value for sol_in[28].sensor_type, expected 207, is {}",
                    msg.sol_in[28].sensor_type
                );
                assert_eq!(
                    msg.sol_in[29].flags, 218,
                    "incorrect value for sol_in[29].flags, expected 218, is {}",
                    msg.sol_in[29].flags
                );
                assert_eq!(
                    msg.sol_in[29].sensor_type, 7,
                    "incorrect value for sol_in[29].sensor_type, expected 7, is {}",
                    msg.sol_in[29].sensor_type
                );
                assert_eq!(
                    msg.sol_in[30].flags, 89,
                    "incorrect value for sol_in[30].flags, expected 89, is {}",
                    msg.sol_in[30].flags
                );
                assert_eq!(
                    msg.sol_in[30].sensor_type, 117,
                    "incorrect value for sol_in[30].sensor_type, expected 117, is {}",
                    msg.sol_in[30].sensor_type
                );
                assert_eq!(
                    msg.sol_in[31].flags, 191,
                    "incorrect value for sol_in[31].flags, expected 191, is {}",
                    msg.sol_in[31].flags
                );
                assert_eq!(
                    msg.sol_in[31].sensor_type, 29,
                    "incorrect value for sol_in[31].sensor_type, expected 29, is {}",
                    msg.sol_in[31].sensor_type
                );
                assert_eq!(
                    msg.sol_in[32].flags, 248,
                    "incorrect value for sol_in[32].flags, expected 248, is {}",
                    msg.sol_in[32].flags
                );
                assert_eq!(
                    msg.sol_in[32].sensor_type, 56,
                    "incorrect value for sol_in[32].sensor_type, expected 56, is {}",
                    msg.sol_in[32].sensor_type
                );
                assert_eq!(
                    msg.sol_in[33].flags, 255,
                    "incorrect value for sol_in[33].flags, expected 255, is {}",
                    msg.sol_in[33].flags
                );
                assert_eq!(
                    msg.sol_in[33].sensor_type, 185,
                    "incorrect value for sol_in[33].sensor_type, expected 185, is {}",
                    msg.sol_in[33].sensor_type
                );
                assert_eq!(
                    msg.sol_in[34].flags, 18,
                    "incorrect value for sol_in[34].flags, expected 18, is {}",
                    msg.sol_in[34].flags
                );
                assert_eq!(
                    msg.sol_in[34].sensor_type, 46,
                    "incorrect value for sol_in[34].sensor_type, expected 46, is {}",
                    msg.sol_in[34].sensor_type
                );
                assert_eq!(
                    msg.sol_in[35].flags, 142,
                    "incorrect value for sol_in[35].flags, expected 142, is {}",
                    msg.sol_in[35].flags
                );
                assert_eq!(
                    msg.sol_in[35].sensor_type, 72,
                    "incorrect value for sol_in[35].sensor_type, expected 72, is {}",
                    msg.sol_in[35].sensor_type
                );
                assert_eq!(
                    msg.sol_in[36].flags, 113,
                    "incorrect value for sol_in[36].flags, expected 113, is {}",
                    msg.sol_in[36].flags
                );
                assert_eq!(
                    msg.sol_in[36].sensor_type, 82,
                    "incorrect value for sol_in[36].sensor_type, expected 82, is {}",
                    msg.sol_in[36].sensor_type
                );
                assert_eq!(
                    msg.sol_in[37].flags, 4,
                    "incorrect value for sol_in[37].flags, expected 4, is {}",
                    msg.sol_in[37].flags
                );
                assert_eq!(
                    msg.sol_in[37].sensor_type, 26,
                    "incorrect value for sol_in[37].sensor_type, expected 26, is {}",
                    msg.sol_in[37].sensor_type
                );
                assert_eq!(
                    msg.sol_in[38].flags, 254,
                    "incorrect value for sol_in[38].flags, expected 254, is {}",
                    msg.sol_in[38].flags
                );
                assert_eq!(
                    msg.sol_in[38].sensor_type, 172,
                    "incorrect value for sol_in[38].sensor_type, expected 172, is {}",
                    msg.sol_in[38].sensor_type
                );
                assert_eq!(
                    msg.sol_in[39].flags, 136,
                    "incorrect value for sol_in[39].flags, expected 136, is {}",
                    msg.sol_in[39].flags
                );
                assert_eq!(
                    msg.sol_in[39].sensor_type, 178,
                    "incorrect value for sol_in[39].sensor_type, expected 178, is {}",
                    msg.sol_in[39].sensor_type
                );
                assert_eq!(
                    msg.sol_in[40].flags, 115,
                    "incorrect value for sol_in[40].flags, expected 115, is {}",
                    msg.sol_in[40].flags
                );
                assert_eq!(
                    msg.sol_in[40].sensor_type, 113,
                    "incorrect value for sol_in[40].sensor_type, expected 113, is {}",
                    msg.sol_in[40].sensor_type
                );
                assert_eq!(
                    msg.sol_in[41].flags, 193,
                    "incorrect value for sol_in[41].flags, expected 193, is {}",
                    msg.sol_in[41].flags
                );
                assert_eq!(
                    msg.sol_in[41].sensor_type, 58,
                    "incorrect value for sol_in[41].sensor_type, expected 58, is {}",
                    msg.sol_in[41].sensor_type
                );
                assert_eq!(
                    msg.sol_in[42].flags, 227,
                    "incorrect value for sol_in[42].flags, expected 227, is {}",
                    msg.sol_in[42].flags
                );
                assert_eq!(
                    msg.sol_in[42].sensor_type, 89,
                    "incorrect value for sol_in[42].sensor_type, expected 89, is {}",
                    msg.sol_in[42].sensor_type
                );
                assert_eq!(
                    msg.sol_in[43].flags, 246,
                    "incorrect value for sol_in[43].flags, expected 246, is {}",
                    msg.sol_in[43].flags
                );
                assert_eq!(
                    msg.sol_in[43].sensor_type, 182,
                    "incorrect value for sol_in[43].sensor_type, expected 182, is {}",
                    msg.sol_in[43].sensor_type
                );
                assert_eq!(
                    msg.sol_in[44].flags, 77,
                    "incorrect value for sol_in[44].flags, expected 77, is {}",
                    msg.sol_in[44].flags
                );
                assert_eq!(
                    msg.sol_in[44].sensor_type, 76,
                    "incorrect value for sol_in[44].sensor_type, expected 76, is {}",
                    msg.sol_in[44].sensor_type
                );
                assert_eq!(
                    msg.sol_in[45].flags, 245,
                    "incorrect value for sol_in[45].flags, expected 245, is {}",
                    msg.sol_in[45].flags
                );
                assert_eq!(
                    msg.sol_in[45].sensor_type, 108,
                    "incorrect value for sol_in[45].sensor_type, expected 108, is {}",
                    msg.sol_in[45].sensor_type
                );
                assert_eq!(
                    msg.sol_in[46].flags, 31,
                    "incorrect value for sol_in[46].flags, expected 31, is {}",
                    msg.sol_in[46].flags
                );
                assert_eq!(
                    msg.sol_in[46].sensor_type, 41,
                    "incorrect value for sol_in[46].sensor_type, expected 41, is {}",
                    msg.sol_in[46].sensor_type
                );
                assert_eq!(
                    msg.sol_in[47].flags, 124,
                    "incorrect value for sol_in[47].flags, expected 124, is {}",
                    msg.sol_in[47].flags
                );
                assert_eq!(
                    msg.sol_in[47].sensor_type, 70,
                    "incorrect value for sol_in[47].sensor_type, expected 70, is {}",
                    msg.sol_in[47].sensor_type
                );
                assert_eq!(
                    msg.sol_in[48].flags, 145,
                    "incorrect value for sol_in[48].flags, expected 145, is {}",
                    msg.sol_in[48].flags
                );
                assert_eq!(
                    msg.sol_in[48].sensor_type, 249,
                    "incorrect value for sol_in[48].sensor_type, expected 249, is {}",
                    msg.sol_in[48].sensor_type
                );
                assert_eq!(
                    msg.sol_in[49].flags, 78,
                    "incorrect value for sol_in[49].flags, expected 78, is {}",
                    msg.sol_in[49].flags
                );
                assert_eq!(
                    msg.sol_in[49].sensor_type, 15,
                    "incorrect value for sol_in[49].sensor_type, expected 15, is {}",
                    msg.sol_in[49].sensor_type
                );
                assert_eq!(
                    msg.sol_in[50].flags, 38,
                    "incorrect value for sol_in[50].flags, expected 38, is {}",
                    msg.sol_in[50].flags
                );
                assert_eq!(
                    msg.sol_in[50].sensor_type, 228,
                    "incorrect value for sol_in[50].sensor_type, expected 228, is {}",
                    msg.sol_in[50].sensor_type
                );
                assert_eq!(
                    msg.sol_in[51].flags, 129,
                    "incorrect value for sol_in[51].flags, expected 129, is {}",
                    msg.sol_in[51].flags
                );
                assert_eq!(
                    msg.sol_in[51].sensor_type, 241,
                    "incorrect value for sol_in[51].sensor_type, expected 241, is {}",
                    msg.sol_in[51].sensor_type
                );
                assert_eq!(
                    msg.sol_in[52].flags, 176,
                    "incorrect value for sol_in[52].flags, expected 176, is {}",
                    msg.sol_in[52].flags
                );
                assert_eq!(
                    msg.sol_in[52].sensor_type, 8,
                    "incorrect value for sol_in[52].sensor_type, expected 8, is {}",
                    msg.sol_in[52].sensor_type
                );
                assert_eq!(
                    msg.sol_in[53].flags, 72,
                    "incorrect value for sol_in[53].flags, expected 72, is {}",
                    msg.sol_in[53].flags
                );
                assert_eq!(
                    msg.sol_in[53].sensor_type, 251,
                    "incorrect value for sol_in[53].sensor_type, expected 251, is {}",
                    msg.sol_in[53].sensor_type
                );
                assert_eq!(
                    msg.sol_in[54].flags, 80,
                    "incorrect value for sol_in[54].flags, expected 80, is {}",
                    msg.sol_in[54].flags
                );
                assert_eq!(
                    msg.sol_in[54].sensor_type, 248,
                    "incorrect value for sol_in[54].sensor_type, expected 248, is {}",
                    msg.sol_in[54].sensor_type
                );
                assert_eq!(
                    msg.sol_in[55].flags, 244,
                    "incorrect value for sol_in[55].flags, expected 244, is {}",
                    msg.sol_in[55].flags
                );
                assert_eq!(
                    msg.sol_in[55].sensor_type, 115,
                    "incorrect value for sol_in[55].sensor_type, expected 115, is {}",
                    msg.sol_in[55].sensor_type
                );
                assert_eq!(
                    msg.sol_in[56].flags, 145,
                    "incorrect value for sol_in[56].flags, expected 145, is {}",
                    msg.sol_in[56].flags
                );
                assert_eq!(
                    msg.sol_in[56].sensor_type, 231,
                    "incorrect value for sol_in[56].sensor_type, expected 231, is {}",
                    msg.sol_in[56].sensor_type
                );
                assert_eq!(
                    msg.sol_in[57].flags, 190,
                    "incorrect value for sol_in[57].flags, expected 190, is {}",
                    msg.sol_in[57].flags
                );
                assert_eq!(
                    msg.sol_in[57].sensor_type, 191,
                    "incorrect value for sol_in[57].sensor_type, expected 191, is {}",
                    msg.sol_in[57].sensor_type
                );
                assert_eq!(
                    msg.sol_in[58].flags, 168,
                    "incorrect value for sol_in[58].flags, expected 168, is {}",
                    msg.sol_in[58].flags
                );
                assert_eq!(
                    msg.sol_in[58].sensor_type, 178,
                    "incorrect value for sol_in[58].sensor_type, expected 178, is {}",
                    msg.sol_in[58].sensor_type
                );
                assert_eq!(
                    msg.sol_in[59].flags, 233,
                    "incorrect value for sol_in[59].flags, expected 233, is {}",
                    msg.sol_in[59].flags
                );
                assert_eq!(
                    msg.sol_in[59].sensor_type, 89,
                    "incorrect value for sol_in[59].sensor_type, expected 89, is {}",
                    msg.sol_in[59].sensor_type
                );
                assert_eq!(
                    msg.sol_in[60].flags, 176,
                    "incorrect value for sol_in[60].flags, expected 176, is {}",
                    msg.sol_in[60].flags
                );
                assert_eq!(
                    msg.sol_in[60].sensor_type, 69,
                    "incorrect value for sol_in[60].sensor_type, expected 69, is {}",
                    msg.sol_in[60].sensor_type
                );
                assert_eq!(
                    msg.sol_in[61].flags, 140,
                    "incorrect value for sol_in[61].flags, expected 140, is {}",
                    msg.sol_in[61].flags
                );
                assert_eq!(
                    msg.sol_in[61].sensor_type, 174,
                    "incorrect value for sol_in[61].sensor_type, expected 174, is {}",
                    msg.sol_in[61].sensor_type
                );
                assert_eq!(
                    msg.sol_in[62].flags, 141,
                    "incorrect value for sol_in[62].flags, expected 141, is {}",
                    msg.sol_in[62].flags
                );
                assert_eq!(
                    msg.sol_in[62].sensor_type, 182,
                    "incorrect value for sol_in[62].sensor_type, expected 182, is {}",
                    msg.sol_in[62].sensor_type
                );
                assert_eq!(
                    msg.sol_in[63].flags, 82,
                    "incorrect value for sol_in[63].flags, expected 82, is {}",
                    msg.sol_in[63].flags
                );
                assert_eq!(
                    msg.sol_in[63].sensor_type, 81,
                    "incorrect value for sol_in[63].sensor_type, expected 81, is {}",
                    msg.sol_in[63].sensor_type
                );
                assert_eq!(
                    msg.sol_in[64].flags, 79,
                    "incorrect value for sol_in[64].flags, expected 79, is {}",
                    msg.sol_in[64].flags
                );
                assert_eq!(
                    msg.sol_in[64].sensor_type, 92,
                    "incorrect value for sol_in[64].sensor_type, expected 92, is {}",
                    msg.sol_in[64].sensor_type
                );
                assert_eq!(
                    msg.sol_in[65].flags, 223,
                    "incorrect value for sol_in[65].flags, expected 223, is {}",
                    msg.sol_in[65].flags
                );
                assert_eq!(
                    msg.sol_in[65].sensor_type, 101,
                    "incorrect value for sol_in[65].sensor_type, expected 101, is {}",
                    msg.sol_in[65].sensor_type
                );
                assert_eq!(
                    msg.sol_in[66].flags, 64,
                    "incorrect value for sol_in[66].flags, expected 64, is {}",
                    msg.sol_in[66].flags
                );
                assert_eq!(
                    msg.sol_in[66].sensor_type, 100,
                    "incorrect value for sol_in[66].sensor_type, expected 100, is {}",
                    msg.sol_in[66].sensor_type
                );
                assert_eq!(
                    msg.sol_in[67].flags, 215,
                    "incorrect value for sol_in[67].flags, expected 215, is {}",
                    msg.sol_in[67].flags
                );
                assert_eq!(
                    msg.sol_in[67].sensor_type, 184,
                    "incorrect value for sol_in[67].sensor_type, expected 184, is {}",
                    msg.sol_in[67].sensor_type
                );
                assert_eq!(
                    msg.sol_in[68].flags, 37,
                    "incorrect value for sol_in[68].flags, expected 37, is {}",
                    msg.sol_in[68].flags
                );
                assert_eq!(
                    msg.sol_in[68].sensor_type, 124,
                    "incorrect value for sol_in[68].sensor_type, expected 124, is {}",
                    msg.sol_in[68].sensor_type
                );
                assert_eq!(
                    msg.sol_in[69].flags, 227,
                    "incorrect value for sol_in[69].flags, expected 227, is {}",
                    msg.sol_in[69].flags
                );
                assert_eq!(
                    msg.sol_in[69].sensor_type, 21,
                    "incorrect value for sol_in[69].sensor_type, expected 21, is {}",
                    msg.sol_in[69].sensor_type
                );
                assert_eq!(
                    msg.sol_in[70].flags, 102,
                    "incorrect value for sol_in[70].flags, expected 102, is {}",
                    msg.sol_in[70].flags
                );
                assert_eq!(
                    msg.sol_in[70].sensor_type, 135,
                    "incorrect value for sol_in[70].sensor_type, expected 135, is {}",
                    msg.sol_in[70].sensor_type
                );
                assert_eq!(
                    msg.sol_in[71].flags, 36,
                    "incorrect value for sol_in[71].flags, expected 36, is {}",
                    msg.sol_in[71].flags
                );
                assert_eq!(
                    msg.sol_in[71].sensor_type, 72,
                    "incorrect value for sol_in[71].sensor_type, expected 72, is {}",
                    msg.sol_in[71].sensor_type
                );
                assert_eq!(
                    msg.sol_in[72].flags, 56,
                    "incorrect value for sol_in[72].flags, expected 56, is {}",
                    msg.sol_in[72].flags
                );
                assert_eq!(
                    msg.sol_in[72].sensor_type, 219,
                    "incorrect value for sol_in[72].sensor_type, expected 219, is {}",
                    msg.sol_in[72].sensor_type
                );
                assert_eq!(
                    msg.sol_in[73].flags, 90,
                    "incorrect value for sol_in[73].flags, expected 90, is {}",
                    msg.sol_in[73].flags
                );
                assert_eq!(
                    msg.sol_in[73].sensor_type, 146,
                    "incorrect value for sol_in[73].sensor_type, expected 146, is {}",
                    msg.sol_in[73].sensor_type
                );
                assert_eq!(
                    msg.sol_in[74].flags, 104,
                    "incorrect value for sol_in[74].flags, expected 104, is {}",
                    msg.sol_in[74].flags
                );
                assert_eq!(
                    msg.sol_in[74].sensor_type, 219,
                    "incorrect value for sol_in[74].sensor_type, expected 219, is {}",
                    msg.sol_in[74].sensor_type
                );
                assert_eq!(
                    msg.sol_in[75].flags, 102,
                    "incorrect value for sol_in[75].flags, expected 102, is {}",
                    msg.sol_in[75].flags
                );
                assert_eq!(
                    msg.sol_in[75].sensor_type, 227,
                    "incorrect value for sol_in[75].sensor_type, expected 227, is {}",
                    msg.sol_in[75].sensor_type
                );
                assert_eq!(
                    msg.sol_in[76].flags, 12,
                    "incorrect value for sol_in[76].flags, expected 12, is {}",
                    msg.sol_in[76].flags
                );
                assert_eq!(
                    msg.sol_in[76].sensor_type, 83,
                    "incorrect value for sol_in[76].sensor_type, expected 83, is {}",
                    msg.sol_in[76].sensor_type
                );
                assert_eq!(
                    msg.sol_in[77].flags, 122,
                    "incorrect value for sol_in[77].flags, expected 122, is {}",
                    msg.sol_in[77].flags
                );
                assert_eq!(
                    msg.sol_in[77].sensor_type, 41,
                    "incorrect value for sol_in[77].sensor_type, expected 41, is {}",
                    msg.sol_in[77].sensor_type
                );
                assert_eq!(
                    msg.sol_in[78].flags, 94,
                    "incorrect value for sol_in[78].flags, expected 94, is {}",
                    msg.sol_in[78].flags
                );
                assert_eq!(
                    msg.sol_in[78].sensor_type, 173,
                    "incorrect value for sol_in[78].sensor_type, expected 173, is {}",
                    msg.sol_in[78].sensor_type
                );
                assert_eq!(
                    msg.sol_in[79].flags, 174,
                    "incorrect value for sol_in[79].flags, expected 174, is {}",
                    msg.sol_in[79].flags
                );
                assert_eq!(
                    msg.sol_in[79].sensor_type, 1,
                    "incorrect value for sol_in[79].sensor_type, expected 1, is {}",
                    msg.sol_in[79].sensor_type
                );
                assert_eq!(
                    msg.sol_in[80].flags, 130,
                    "incorrect value for sol_in[80].flags, expected 130, is {}",
                    msg.sol_in[80].flags
                );
                assert_eq!(
                    msg.sol_in[80].sensor_type, 134,
                    "incorrect value for sol_in[80].sensor_type, expected 134, is {}",
                    msg.sol_in[80].sensor_type
                );
                assert_eq!(
                    msg.sol_in[81].flags, 237,
                    "incorrect value for sol_in[81].flags, expected 237, is {}",
                    msg.sol_in[81].flags
                );
                assert_eq!(
                    msg.sol_in[81].sensor_type, 104,
                    "incorrect value for sol_in[81].sensor_type, expected 104, is {}",
                    msg.sol_in[81].sensor_type
                );
                assert_eq!(
                    msg.sol_in[82].flags, 249,
                    "incorrect value for sol_in[82].flags, expected 249, is {}",
                    msg.sol_in[82].flags
                );
                assert_eq!(
                    msg.sol_in[82].sensor_type, 116,
                    "incorrect value for sol_in[82].sensor_type, expected 116, is {}",
                    msg.sol_in[82].sensor_type
                );
                assert_eq!(
                    msg.sol_in[83].flags, 230,
                    "incorrect value for sol_in[83].flags, expected 230, is {}",
                    msg.sol_in[83].flags
                );
                assert_eq!(
                    msg.sol_in[83].sensor_type, 107,
                    "incorrect value for sol_in[83].sensor_type, expected 107, is {}",
                    msg.sol_in[83].sensor_type
                );
                assert_eq!(
                    msg.sol_in[84].flags, 123,
                    "incorrect value for sol_in[84].flags, expected 123, is {}",
                    msg.sol_in[84].flags
                );
                assert_eq!(
                    msg.sol_in[84].sensor_type, 130,
                    "incorrect value for sol_in[84].sensor_type, expected 130, is {}",
                    msg.sol_in[84].sensor_type
                );
                assert_eq!(
                    msg.sol_in[85].flags, 162,
                    "incorrect value for sol_in[85].flags, expected 162, is {}",
                    msg.sol_in[85].flags
                );
                assert_eq!(
                    msg.sol_in[85].sensor_type, 25,
                    "incorrect value for sol_in[85].sensor_type, expected 25, is {}",
                    msg.sol_in[85].sensor_type
                );
                assert_eq!(
                    msg.sol_in[86].flags, 223,
                    "incorrect value for sol_in[86].flags, expected 223, is {}",
                    msg.sol_in[86].flags
                );
                assert_eq!(
                    msg.sol_in[86].sensor_type, 57,
                    "incorrect value for sol_in[86].sensor_type, expected 57, is {}",
                    msg.sol_in[86].sensor_type
                );
                assert_eq!(
                    msg.sol_in[87].flags, 174,
                    "incorrect value for sol_in[87].flags, expected 174, is {}",
                    msg.sol_in[87].flags
                );
                assert_eq!(
                    msg.sol_in[87].sensor_type, 193,
                    "incorrect value for sol_in[87].sensor_type, expected 193, is {}",
                    msg.sol_in[87].sensor_type
                );
                assert_eq!(
                    msg.sol_in[88].flags, 193,
                    "incorrect value for sol_in[88].flags, expected 193, is {}",
                    msg.sol_in[88].flags
                );
                assert_eq!(
                    msg.sol_in[88].sensor_type, 146,
                    "incorrect value for sol_in[88].sensor_type, expected 146, is {}",
                    msg.sol_in[88].sensor_type
                );
                assert_eq!(
                    msg.sol_in[89].flags, 44,
                    "incorrect value for sol_in[89].flags, expected 44, is {}",
                    msg.sol_in[89].flags
                );
                assert_eq!(
                    msg.sol_in[89].sensor_type, 239,
                    "incorrect value for sol_in[89].sensor_type, expected 239, is {}",
                    msg.sol_in[89].sensor_type
                );
                assert_eq!(
                    msg.sol_in[90].flags, 197,
                    "incorrect value for sol_in[90].flags, expected 197, is {}",
                    msg.sol_in[90].flags
                );
                assert_eq!(
                    msg.sol_in[90].sensor_type, 246,
                    "incorrect value for sol_in[90].sensor_type, expected 246, is {}",
                    msg.sol_in[90].sensor_type
                );
                assert_eq!(
                    msg.sol_in[91].flags, 80,
                    "incorrect value for sol_in[91].flags, expected 80, is {}",
                    msg.sol_in[91].flags
                );
                assert_eq!(
                    msg.sol_in[91].sensor_type, 214,
                    "incorrect value for sol_in[91].sensor_type, expected 214, is {}",
                    msg.sol_in[91].sensor_type
                );
                assert_eq!(
                    msg.sol_in[92].flags, 100,
                    "incorrect value for sol_in[92].flags, expected 100, is {}",
                    msg.sol_in[92].flags
                );
                assert_eq!(
                    msg.sol_in[92].sensor_type, 83,
                    "incorrect value for sol_in[92].sensor_type, expected 83, is {}",
                    msg.sol_in[92].sensor_type
                );
                assert_eq!(
                    msg.sol_in[93].flags, 72,
                    "incorrect value for sol_in[93].flags, expected 72, is {}",
                    msg.sol_in[93].flags
                );
                assert_eq!(
                    msg.sol_in[93].sensor_type, 66,
                    "incorrect value for sol_in[93].sensor_type, expected 66, is {}",
                    msg.sol_in[93].sensor_type
                );
                assert_eq!(
                    msg.sol_in[94].flags, 137,
                    "incorrect value for sol_in[94].flags, expected 137, is {}",
                    msg.sol_in[94].flags
                );
                assert_eq!(
                    msg.sol_in[94].sensor_type, 133,
                    "incorrect value for sol_in[94].sensor_type, expected 133, is {}",
                    msg.sol_in[94].sensor_type
                );
                assert_eq!(
                    msg.sol_in[95].flags, 82,
                    "incorrect value for sol_in[95].flags, expected 82, is {}",
                    msg.sol_in[95].flags
                );
                assert_eq!(
                    msg.sol_in[95].sensor_type, 140,
                    "incorrect value for sol_in[95].sensor_type, expected 140, is {}",
                    msg.sol_in[95].sensor_type
                );
                assert_eq!(
                    msg.sol_in[96].flags, 2,
                    "incorrect value for sol_in[96].flags, expected 2, is {}",
                    msg.sol_in[96].flags
                );
                assert_eq!(
                    msg.sol_in[96].sensor_type, 2,
                    "incorrect value for sol_in[96].sensor_type, expected 2, is {}",
                    msg.sol_in[96].sensor_type
                );
                assert_eq!(
                    msg.sol_in[97].flags, 9,
                    "incorrect value for sol_in[97].flags, expected 9, is {}",
                    msg.sol_in[97].flags
                );
                assert_eq!(
                    msg.sol_in[97].sensor_type, 96,
                    "incorrect value for sol_in[97].sensor_type, expected 96, is {}",
                    msg.sol_in[97].sensor_type
                );
                assert_eq!(
                    msg.sol_in[98].flags, 158,
                    "incorrect value for sol_in[98].flags, expected 158, is {}",
                    msg.sol_in[98].flags
                );
                assert_eq!(
                    msg.sol_in[98].sensor_type, 96,
                    "incorrect value for sol_in[98].sensor_type, expected 96, is {}",
                    msg.sol_in[98].sensor_type
                );
                assert_eq!(
                    msg.sol_in[99].flags, 97,
                    "incorrect value for sol_in[99].flags, expected 97, is {}",
                    msg.sol_in[99].flags
                );
                assert_eq!(
                    msg.sol_in[99].sensor_type, 134,
                    "incorrect value for sol_in[99].sensor_type, expected 134, is {}",
                    msg.sol_in[99].sensor_type
                );
                assert_eq!(
                    msg.sol_in[100].flags, 129,
                    "incorrect value for sol_in[100].flags, expected 129, is {}",
                    msg.sol_in[100].flags
                );
                assert_eq!(
                    msg.sol_in[100].sensor_type, 43,
                    "incorrect value for sol_in[100].sensor_type, expected 43, is {}",
                    msg.sol_in[100].sensor_type
                );
                assert_eq!(
                    msg.sol_in[101].flags, 25,
                    "incorrect value for sol_in[101].flags, expected 25, is {}",
                    msg.sol_in[101].flags
                );
                assert_eq!(
                    msg.sol_in[101].sensor_type, 141,
                    "incorrect value for sol_in[101].sensor_type, expected 141, is {}",
                    msg.sol_in[101].sensor_type
                );
                assert_eq!(
                    msg.sol_in[102].flags, 200,
                    "incorrect value for sol_in[102].flags, expected 200, is {}",
                    msg.sol_in[102].flags
                );
                assert_eq!(
                    msg.sol_in[102].sensor_type, 183,
                    "incorrect value for sol_in[102].sensor_type, expected 183, is {}",
                    msg.sol_in[102].sensor_type
                );
                assert_eq!(
                    msg.sol_in[103].flags, 57,
                    "incorrect value for sol_in[103].flags, expected 57, is {}",
                    msg.sol_in[103].flags
                );
                assert_eq!(
                    msg.sol_in[103].sensor_type, 214,
                    "incorrect value for sol_in[103].sensor_type, expected 214, is {}",
                    msg.sol_in[103].sensor_type
                );
                assert_eq!(
                    msg.sol_in[104].flags, 103,
                    "incorrect value for sol_in[104].flags, expected 103, is {}",
                    msg.sol_in[104].flags
                );
                assert_eq!(
                    msg.sol_in[104].sensor_type, 248,
                    "incorrect value for sol_in[104].sensor_type, expected 248, is {}",
                    msg.sol_in[104].sensor_type
                );
                assert_eq!(
                    msg.sol_in[105].flags, 65,
                    "incorrect value for sol_in[105].flags, expected 65, is {}",
                    msg.sol_in[105].flags
                );
                assert_eq!(
                    msg.sol_in[105].sensor_type, 222,
                    "incorrect value for sol_in[105].sensor_type, expected 222, is {}",
                    msg.sol_in[105].sensor_type
                );
                assert_eq!(
                    msg.sol_in[106].flags, 15,
                    "incorrect value for sol_in[106].flags, expected 15, is {}",
                    msg.sol_in[106].flags
                );
                assert_eq!(
                    msg.sol_in[106].sensor_type, 195,
                    "incorrect value for sol_in[106].sensor_type, expected 195, is {}",
                    msg.sol_in[106].sensor_type
                );
                assert_eq!(
                    msg.sol_in[107].flags, 21,
                    "incorrect value for sol_in[107].flags, expected 21, is {}",
                    msg.sol_in[107].flags
                );
                assert_eq!(
                    msg.sol_in[107].sensor_type, 244,
                    "incorrect value for sol_in[107].sensor_type, expected 244, is {}",
                    msg.sol_in[107].sensor_type
                );
                assert_eq!(
                    msg.sol_in[108].flags, 46,
                    "incorrect value for sol_in[108].flags, expected 46, is {}",
                    msg.sol_in[108].flags
                );
                assert_eq!(
                    msg.sol_in[108].sensor_type, 180,
                    "incorrect value for sol_in[108].sensor_type, expected 180, is {}",
                    msg.sol_in[108].sensor_type
                );
                assert_eq!(
                    msg.sol_in[109].flags, 130,
                    "incorrect value for sol_in[109].flags, expected 130, is {}",
                    msg.sol_in[109].flags
                );
                assert_eq!(
                    msg.sol_in[109].sensor_type, 140,
                    "incorrect value for sol_in[109].sensor_type, expected 140, is {}",
                    msg.sol_in[109].sensor_type
                );
                assert_eq!(
                    msg.sol_in[110].flags, 17,
                    "incorrect value for sol_in[110].flags, expected 17, is {}",
                    msg.sol_in[110].flags
                );
                assert_eq!(
                    msg.sol_in[110].sensor_type, 36,
                    "incorrect value for sol_in[110].sensor_type, expected 36, is {}",
                    msg.sol_in[110].sensor_type
                );
                assert_eq!(
                    msg.sol_in[111].flags, 209,
                    "incorrect value for sol_in[111].flags, expected 209, is {}",
                    msg.sol_in[111].flags
                );
                assert_eq!(
                    msg.sol_in[111].sensor_type, 194,
                    "incorrect value for sol_in[111].sensor_type, expected 194, is {}",
                    msg.sol_in[111].sensor_type
                );
                assert_eq!(
                    msg.sol_in[112].flags, 254,
                    "incorrect value for sol_in[112].flags, expected 254, is {}",
                    msg.sol_in[112].flags
                );
                assert_eq!(
                    msg.sol_in[112].sensor_type, 65,
                    "incorrect value for sol_in[112].sensor_type, expected 65, is {}",
                    msg.sol_in[112].sensor_type
                );
                assert_eq!(
                    msg.sol_in[113].flags, 103,
                    "incorrect value for sol_in[113].flags, expected 103, is {}",
                    msg.sol_in[113].flags
                );
                assert_eq!(
                    msg.sol_in[113].sensor_type, 115,
                    "incorrect value for sol_in[113].sensor_type, expected 115, is {}",
                    msg.sol_in[113].sensor_type
                );
                assert_eq!(
                    msg.sol_in[114].flags, 129,
                    "incorrect value for sol_in[114].flags, expected 129, is {}",
                    msg.sol_in[114].flags
                );
                assert_eq!(
                    msg.sol_in[114].sensor_type, 152,
                    "incorrect value for sol_in[114].sensor_type, expected 152, is {}",
                    msg.sol_in[114].sensor_type
                );
                assert_eq!(
                    msg.sol_in[115].flags, 235,
                    "incorrect value for sol_in[115].flags, expected 235, is {}",
                    msg.sol_in[115].flags
                );
                assert_eq!(
                    msg.sol_in[115].sensor_type, 234,
                    "incorrect value for sol_in[115].sensor_type, expected 234, is {}",
                    msg.sol_in[115].sensor_type
                );
                assert_eq!(
                    msg.sol_in[116].flags, 234,
                    "incorrect value for sol_in[116].flags, expected 234, is {}",
                    msg.sol_in[116].flags
                );
                assert_eq!(
                    msg.sol_in[116].sensor_type, 194,
                    "incorrect value for sol_in[116].sensor_type, expected 194, is {}",
                    msg.sol_in[116].sensor_type
                );
                assert_eq!(
                    msg.sol_in[117].flags, 201,
                    "incorrect value for sol_in[117].flags, expected 201, is {}",
                    msg.sol_in[117].flags
                );
                assert_eq!(
                    msg.sol_in[117].sensor_type, 170,
                    "incorrect value for sol_in[117].sensor_type, expected 170, is {}",
                    msg.sol_in[117].sensor_type
                );
                assert_eq!(
                    msg.sol_in[118].flags, 154,
                    "incorrect value for sol_in[118].flags, expected 154, is {}",
                    msg.sol_in[118].flags
                );
                assert_eq!(
                    msg.sol_in[118].sensor_type, 210,
                    "incorrect value for sol_in[118].sensor_type, expected 210, is {}",
                    msg.sol_in[118].sensor_type
                );
                assert_eq!(
                    msg.tow, 3628191792,
                    "incorrect value for tow, expected 3628191792, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 58512,
                    "incorrect value for vdop, expected 58512, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSolnMeta"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_solution_meta_msg_soln_meta`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_solution_meta_msg_soln_meta() {
    {
        let mut payload = Cursor::new(vec![
            85, 14, 255, 0, 60, 254, 48, 208, 65, 216, 122, 45, 196, 160, 144, 228, 8, 83, 89, 87,
            3, 213, 95, 109, 86, 131, 71, 70, 84, 73, 131, 26, 82, 247, 140, 97, 115, 110, 118,
            253, 2, 122, 186, 148, 122, 148, 180, 231, 68, 46, 190, 102, 243, 48, 192, 15, 208, 89,
            56, 10, 245, 2, 254, 201, 120, 32, 126, 2, 83, 161, 238, 123, 102, 230, 76, 190, 225,
            182, 207, 228, 7, 218, 117, 89, 29, 191, 56, 248, 185, 255, 46, 18, 72, 142, 82, 113,
            26, 4, 172, 254, 178, 136, 113, 115, 58, 193, 89, 227, 182, 246, 76, 77, 108, 245, 41,
            31, 70, 124, 249, 145, 15, 78, 228, 38, 241, 129, 8, 176, 251, 72, 248, 80, 115, 244,
            231, 145, 191, 190, 178, 168, 89, 233, 69, 176, 174, 140, 182, 141, 81, 82, 92, 79,
            101, 223, 100, 64, 184, 215, 124, 37, 21, 227, 135, 102, 72, 36, 219, 56, 146, 90, 219,
            104, 227, 102, 83, 12, 41, 122, 173, 94, 1, 174, 134, 130, 104, 237, 116, 249, 107,
            230, 130, 123, 25, 162, 57, 223, 193, 174, 146, 193, 239, 44, 246, 197, 214, 80, 83,
            100, 66, 72, 133, 137, 140, 82, 2, 2, 96, 9, 96, 158, 134, 97, 43, 129, 141, 25, 183,
            200, 214, 57, 248, 103, 222, 65, 195, 15, 244, 21, 180, 46, 140, 130, 36, 17, 194, 209,
            65, 254, 115, 103, 152, 129, 234, 235, 194, 234, 170, 201, 210, 154, 150, 247,
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
        let sbp_msg = sbp::messages::Sbp::MsgSolnMeta(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSolnMeta(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff0e,
                    "Incorrect message type, expected 0xff0e, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x3c00,
                    "incorrect sender id, expected 0x3c00, is {sender_id}"
                );
                assert_eq!(
                    msg.age_corrections, 21256,
                    "incorrect value for age_corrections, expected 21256, is {}",
                    msg.age_corrections
                );
                assert_eq!(
                    msg.age_gnss, 3573765977,
                    "incorrect value for age_gnss, expected 3573765977, is {}",
                    msg.age_gnss
                );
                assert_eq!(
                    msg.hdop, 41156,
                    "incorrect value for hdop, expected 41156, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 11642,
                    "incorrect value for pdop, expected 11642, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.sol_in[0].flags, 109,
                    "incorrect value for sol_in[0].flags, expected 109, is {}",
                    msg.sol_in[0].flags
                );
                assert_eq!(
                    msg.sol_in[0].sensor_type, 95,
                    "incorrect value for sol_in[0].sensor_type, expected 95, is {}",
                    msg.sol_in[0].sensor_type
                );
                assert_eq!(
                    msg.sol_in[1].flags, 131,
                    "incorrect value for sol_in[1].flags, expected 131, is {}",
                    msg.sol_in[1].flags
                );
                assert_eq!(
                    msg.sol_in[1].sensor_type, 86,
                    "incorrect value for sol_in[1].sensor_type, expected 86, is {}",
                    msg.sol_in[1].sensor_type
                );
                assert_eq!(
                    msg.sol_in[2].flags, 70,
                    "incorrect value for sol_in[2].flags, expected 70, is {}",
                    msg.sol_in[2].flags
                );
                assert_eq!(
                    msg.sol_in[2].sensor_type, 71,
                    "incorrect value for sol_in[2].sensor_type, expected 71, is {}",
                    msg.sol_in[2].sensor_type
                );
                assert_eq!(
                    msg.sol_in[3].flags, 73,
                    "incorrect value for sol_in[3].flags, expected 73, is {}",
                    msg.sol_in[3].flags
                );
                assert_eq!(
                    msg.sol_in[3].sensor_type, 84,
                    "incorrect value for sol_in[3].sensor_type, expected 84, is {}",
                    msg.sol_in[3].sensor_type
                );
                assert_eq!(
                    msg.sol_in[4].flags, 26,
                    "incorrect value for sol_in[4].flags, expected 26, is {}",
                    msg.sol_in[4].flags
                );
                assert_eq!(
                    msg.sol_in[4].sensor_type, 131,
                    "incorrect value for sol_in[4].sensor_type, expected 131, is {}",
                    msg.sol_in[4].sensor_type
                );
                assert_eq!(
                    msg.sol_in[5].flags, 247,
                    "incorrect value for sol_in[5].flags, expected 247, is {}",
                    msg.sol_in[5].flags
                );
                assert_eq!(
                    msg.sol_in[5].sensor_type, 82,
                    "incorrect value for sol_in[5].sensor_type, expected 82, is {}",
                    msg.sol_in[5].sensor_type
                );
                assert_eq!(
                    msg.sol_in[6].flags, 97,
                    "incorrect value for sol_in[6].flags, expected 97, is {}",
                    msg.sol_in[6].flags
                );
                assert_eq!(
                    msg.sol_in[6].sensor_type, 140,
                    "incorrect value for sol_in[6].sensor_type, expected 140, is {}",
                    msg.sol_in[6].sensor_type
                );
                assert_eq!(
                    msg.sol_in[7].flags, 110,
                    "incorrect value for sol_in[7].flags, expected 110, is {}",
                    msg.sol_in[7].flags
                );
                assert_eq!(
                    msg.sol_in[7].sensor_type, 115,
                    "incorrect value for sol_in[7].sensor_type, expected 115, is {}",
                    msg.sol_in[7].sensor_type
                );
                assert_eq!(
                    msg.sol_in[8].flags, 253,
                    "incorrect value for sol_in[8].flags, expected 253, is {}",
                    msg.sol_in[8].flags
                );
                assert_eq!(
                    msg.sol_in[8].sensor_type, 118,
                    "incorrect value for sol_in[8].sensor_type, expected 118, is {}",
                    msg.sol_in[8].sensor_type
                );
                assert_eq!(
                    msg.sol_in[9].flags, 122,
                    "incorrect value for sol_in[9].flags, expected 122, is {}",
                    msg.sol_in[9].flags
                );
                assert_eq!(
                    msg.sol_in[9].sensor_type, 2,
                    "incorrect value for sol_in[9].sensor_type, expected 2, is {}",
                    msg.sol_in[9].sensor_type
                );
                assert_eq!(
                    msg.sol_in[10].flags, 148,
                    "incorrect value for sol_in[10].flags, expected 148, is {}",
                    msg.sol_in[10].flags
                );
                assert_eq!(
                    msg.sol_in[10].sensor_type, 186,
                    "incorrect value for sol_in[10].sensor_type, expected 186, is {}",
                    msg.sol_in[10].sensor_type
                );
                assert_eq!(
                    msg.sol_in[11].flags, 148,
                    "incorrect value for sol_in[11].flags, expected 148, is {}",
                    msg.sol_in[11].flags
                );
                assert_eq!(
                    msg.sol_in[11].sensor_type, 122,
                    "incorrect value for sol_in[11].sensor_type, expected 122, is {}",
                    msg.sol_in[11].sensor_type
                );
                assert_eq!(
                    msg.sol_in[12].flags, 231,
                    "incorrect value for sol_in[12].flags, expected 231, is {}",
                    msg.sol_in[12].flags
                );
                assert_eq!(
                    msg.sol_in[12].sensor_type, 180,
                    "incorrect value for sol_in[12].sensor_type, expected 180, is {}",
                    msg.sol_in[12].sensor_type
                );
                assert_eq!(
                    msg.sol_in[13].flags, 46,
                    "incorrect value for sol_in[13].flags, expected 46, is {}",
                    msg.sol_in[13].flags
                );
                assert_eq!(
                    msg.sol_in[13].sensor_type, 68,
                    "incorrect value for sol_in[13].sensor_type, expected 68, is {}",
                    msg.sol_in[13].sensor_type
                );
                assert_eq!(
                    msg.sol_in[14].flags, 102,
                    "incorrect value for sol_in[14].flags, expected 102, is {}",
                    msg.sol_in[14].flags
                );
                assert_eq!(
                    msg.sol_in[14].sensor_type, 190,
                    "incorrect value for sol_in[14].sensor_type, expected 190, is {}",
                    msg.sol_in[14].sensor_type
                );
                assert_eq!(
                    msg.sol_in[15].flags, 48,
                    "incorrect value for sol_in[15].flags, expected 48, is {}",
                    msg.sol_in[15].flags
                );
                assert_eq!(
                    msg.sol_in[15].sensor_type, 243,
                    "incorrect value for sol_in[15].sensor_type, expected 243, is {}",
                    msg.sol_in[15].sensor_type
                );
                assert_eq!(
                    msg.sol_in[16].flags, 15,
                    "incorrect value for sol_in[16].flags, expected 15, is {}",
                    msg.sol_in[16].flags
                );
                assert_eq!(
                    msg.sol_in[16].sensor_type, 192,
                    "incorrect value for sol_in[16].sensor_type, expected 192, is {}",
                    msg.sol_in[16].sensor_type
                );
                assert_eq!(
                    msg.sol_in[17].flags, 89,
                    "incorrect value for sol_in[17].flags, expected 89, is {}",
                    msg.sol_in[17].flags
                );
                assert_eq!(
                    msg.sol_in[17].sensor_type, 208,
                    "incorrect value for sol_in[17].sensor_type, expected 208, is {}",
                    msg.sol_in[17].sensor_type
                );
                assert_eq!(
                    msg.sol_in[18].flags, 10,
                    "incorrect value for sol_in[18].flags, expected 10, is {}",
                    msg.sol_in[18].flags
                );
                assert_eq!(
                    msg.sol_in[18].sensor_type, 56,
                    "incorrect value for sol_in[18].sensor_type, expected 56, is {}",
                    msg.sol_in[18].sensor_type
                );
                assert_eq!(
                    msg.sol_in[19].flags, 2,
                    "incorrect value for sol_in[19].flags, expected 2, is {}",
                    msg.sol_in[19].flags
                );
                assert_eq!(
                    msg.sol_in[19].sensor_type, 245,
                    "incorrect value for sol_in[19].sensor_type, expected 245, is {}",
                    msg.sol_in[19].sensor_type
                );
                assert_eq!(
                    msg.sol_in[20].flags, 201,
                    "incorrect value for sol_in[20].flags, expected 201, is {}",
                    msg.sol_in[20].flags
                );
                assert_eq!(
                    msg.sol_in[20].sensor_type, 254,
                    "incorrect value for sol_in[20].sensor_type, expected 254, is {}",
                    msg.sol_in[20].sensor_type
                );
                assert_eq!(
                    msg.sol_in[21].flags, 32,
                    "incorrect value for sol_in[21].flags, expected 32, is {}",
                    msg.sol_in[21].flags
                );
                assert_eq!(
                    msg.sol_in[21].sensor_type, 120,
                    "incorrect value for sol_in[21].sensor_type, expected 120, is {}",
                    msg.sol_in[21].sensor_type
                );
                assert_eq!(
                    msg.sol_in[22].flags, 2,
                    "incorrect value for sol_in[22].flags, expected 2, is {}",
                    msg.sol_in[22].flags
                );
                assert_eq!(
                    msg.sol_in[22].sensor_type, 126,
                    "incorrect value for sol_in[22].sensor_type, expected 126, is {}",
                    msg.sol_in[22].sensor_type
                );
                assert_eq!(
                    msg.sol_in[23].flags, 161,
                    "incorrect value for sol_in[23].flags, expected 161, is {}",
                    msg.sol_in[23].flags
                );
                assert_eq!(
                    msg.sol_in[23].sensor_type, 83,
                    "incorrect value for sol_in[23].sensor_type, expected 83, is {}",
                    msg.sol_in[23].sensor_type
                );
                assert_eq!(
                    msg.sol_in[24].flags, 123,
                    "incorrect value for sol_in[24].flags, expected 123, is {}",
                    msg.sol_in[24].flags
                );
                assert_eq!(
                    msg.sol_in[24].sensor_type, 238,
                    "incorrect value for sol_in[24].sensor_type, expected 238, is {}",
                    msg.sol_in[24].sensor_type
                );
                assert_eq!(
                    msg.sol_in[25].flags, 230,
                    "incorrect value for sol_in[25].flags, expected 230, is {}",
                    msg.sol_in[25].flags
                );
                assert_eq!(
                    msg.sol_in[25].sensor_type, 102,
                    "incorrect value for sol_in[25].sensor_type, expected 102, is {}",
                    msg.sol_in[25].sensor_type
                );
                assert_eq!(
                    msg.sol_in[26].flags, 190,
                    "incorrect value for sol_in[26].flags, expected 190, is {}",
                    msg.sol_in[26].flags
                );
                assert_eq!(
                    msg.sol_in[26].sensor_type, 76,
                    "incorrect value for sol_in[26].sensor_type, expected 76, is {}",
                    msg.sol_in[26].sensor_type
                );
                assert_eq!(
                    msg.sol_in[27].flags, 182,
                    "incorrect value for sol_in[27].flags, expected 182, is {}",
                    msg.sol_in[27].flags
                );
                assert_eq!(
                    msg.sol_in[27].sensor_type, 225,
                    "incorrect value for sol_in[27].sensor_type, expected 225, is {}",
                    msg.sol_in[27].sensor_type
                );
                assert_eq!(
                    msg.sol_in[28].flags, 228,
                    "incorrect value for sol_in[28].flags, expected 228, is {}",
                    msg.sol_in[28].flags
                );
                assert_eq!(
                    msg.sol_in[28].sensor_type, 207,
                    "incorrect value for sol_in[28].sensor_type, expected 207, is {}",
                    msg.sol_in[28].sensor_type
                );
                assert_eq!(
                    msg.sol_in[29].flags, 218,
                    "incorrect value for sol_in[29].flags, expected 218, is {}",
                    msg.sol_in[29].flags
                );
                assert_eq!(
                    msg.sol_in[29].sensor_type, 7,
                    "incorrect value for sol_in[29].sensor_type, expected 7, is {}",
                    msg.sol_in[29].sensor_type
                );
                assert_eq!(
                    msg.sol_in[30].flags, 89,
                    "incorrect value for sol_in[30].flags, expected 89, is {}",
                    msg.sol_in[30].flags
                );
                assert_eq!(
                    msg.sol_in[30].sensor_type, 117,
                    "incorrect value for sol_in[30].sensor_type, expected 117, is {}",
                    msg.sol_in[30].sensor_type
                );
                assert_eq!(
                    msg.sol_in[31].flags, 191,
                    "incorrect value for sol_in[31].flags, expected 191, is {}",
                    msg.sol_in[31].flags
                );
                assert_eq!(
                    msg.sol_in[31].sensor_type, 29,
                    "incorrect value for sol_in[31].sensor_type, expected 29, is {}",
                    msg.sol_in[31].sensor_type
                );
                assert_eq!(
                    msg.sol_in[32].flags, 248,
                    "incorrect value for sol_in[32].flags, expected 248, is {}",
                    msg.sol_in[32].flags
                );
                assert_eq!(
                    msg.sol_in[32].sensor_type, 56,
                    "incorrect value for sol_in[32].sensor_type, expected 56, is {}",
                    msg.sol_in[32].sensor_type
                );
                assert_eq!(
                    msg.sol_in[33].flags, 255,
                    "incorrect value for sol_in[33].flags, expected 255, is {}",
                    msg.sol_in[33].flags
                );
                assert_eq!(
                    msg.sol_in[33].sensor_type, 185,
                    "incorrect value for sol_in[33].sensor_type, expected 185, is {}",
                    msg.sol_in[33].sensor_type
                );
                assert_eq!(
                    msg.sol_in[34].flags, 18,
                    "incorrect value for sol_in[34].flags, expected 18, is {}",
                    msg.sol_in[34].flags
                );
                assert_eq!(
                    msg.sol_in[34].sensor_type, 46,
                    "incorrect value for sol_in[34].sensor_type, expected 46, is {}",
                    msg.sol_in[34].sensor_type
                );
                assert_eq!(
                    msg.sol_in[35].flags, 142,
                    "incorrect value for sol_in[35].flags, expected 142, is {}",
                    msg.sol_in[35].flags
                );
                assert_eq!(
                    msg.sol_in[35].sensor_type, 72,
                    "incorrect value for sol_in[35].sensor_type, expected 72, is {}",
                    msg.sol_in[35].sensor_type
                );
                assert_eq!(
                    msg.sol_in[36].flags, 113,
                    "incorrect value for sol_in[36].flags, expected 113, is {}",
                    msg.sol_in[36].flags
                );
                assert_eq!(
                    msg.sol_in[36].sensor_type, 82,
                    "incorrect value for sol_in[36].sensor_type, expected 82, is {}",
                    msg.sol_in[36].sensor_type
                );
                assert_eq!(
                    msg.sol_in[37].flags, 4,
                    "incorrect value for sol_in[37].flags, expected 4, is {}",
                    msg.sol_in[37].flags
                );
                assert_eq!(
                    msg.sol_in[37].sensor_type, 26,
                    "incorrect value for sol_in[37].sensor_type, expected 26, is {}",
                    msg.sol_in[37].sensor_type
                );
                assert_eq!(
                    msg.sol_in[38].flags, 254,
                    "incorrect value for sol_in[38].flags, expected 254, is {}",
                    msg.sol_in[38].flags
                );
                assert_eq!(
                    msg.sol_in[38].sensor_type, 172,
                    "incorrect value for sol_in[38].sensor_type, expected 172, is {}",
                    msg.sol_in[38].sensor_type
                );
                assert_eq!(
                    msg.sol_in[39].flags, 136,
                    "incorrect value for sol_in[39].flags, expected 136, is {}",
                    msg.sol_in[39].flags
                );
                assert_eq!(
                    msg.sol_in[39].sensor_type, 178,
                    "incorrect value for sol_in[39].sensor_type, expected 178, is {}",
                    msg.sol_in[39].sensor_type
                );
                assert_eq!(
                    msg.sol_in[40].flags, 115,
                    "incorrect value for sol_in[40].flags, expected 115, is {}",
                    msg.sol_in[40].flags
                );
                assert_eq!(
                    msg.sol_in[40].sensor_type, 113,
                    "incorrect value for sol_in[40].sensor_type, expected 113, is {}",
                    msg.sol_in[40].sensor_type
                );
                assert_eq!(
                    msg.sol_in[41].flags, 193,
                    "incorrect value for sol_in[41].flags, expected 193, is {}",
                    msg.sol_in[41].flags
                );
                assert_eq!(
                    msg.sol_in[41].sensor_type, 58,
                    "incorrect value for sol_in[41].sensor_type, expected 58, is {}",
                    msg.sol_in[41].sensor_type
                );
                assert_eq!(
                    msg.sol_in[42].flags, 227,
                    "incorrect value for sol_in[42].flags, expected 227, is {}",
                    msg.sol_in[42].flags
                );
                assert_eq!(
                    msg.sol_in[42].sensor_type, 89,
                    "incorrect value for sol_in[42].sensor_type, expected 89, is {}",
                    msg.sol_in[42].sensor_type
                );
                assert_eq!(
                    msg.sol_in[43].flags, 246,
                    "incorrect value for sol_in[43].flags, expected 246, is {}",
                    msg.sol_in[43].flags
                );
                assert_eq!(
                    msg.sol_in[43].sensor_type, 182,
                    "incorrect value for sol_in[43].sensor_type, expected 182, is {}",
                    msg.sol_in[43].sensor_type
                );
                assert_eq!(
                    msg.sol_in[44].flags, 77,
                    "incorrect value for sol_in[44].flags, expected 77, is {}",
                    msg.sol_in[44].flags
                );
                assert_eq!(
                    msg.sol_in[44].sensor_type, 76,
                    "incorrect value for sol_in[44].sensor_type, expected 76, is {}",
                    msg.sol_in[44].sensor_type
                );
                assert_eq!(
                    msg.sol_in[45].flags, 245,
                    "incorrect value for sol_in[45].flags, expected 245, is {}",
                    msg.sol_in[45].flags
                );
                assert_eq!(
                    msg.sol_in[45].sensor_type, 108,
                    "incorrect value for sol_in[45].sensor_type, expected 108, is {}",
                    msg.sol_in[45].sensor_type
                );
                assert_eq!(
                    msg.sol_in[46].flags, 31,
                    "incorrect value for sol_in[46].flags, expected 31, is {}",
                    msg.sol_in[46].flags
                );
                assert_eq!(
                    msg.sol_in[46].sensor_type, 41,
                    "incorrect value for sol_in[46].sensor_type, expected 41, is {}",
                    msg.sol_in[46].sensor_type
                );
                assert_eq!(
                    msg.sol_in[47].flags, 124,
                    "incorrect value for sol_in[47].flags, expected 124, is {}",
                    msg.sol_in[47].flags
                );
                assert_eq!(
                    msg.sol_in[47].sensor_type, 70,
                    "incorrect value for sol_in[47].sensor_type, expected 70, is {}",
                    msg.sol_in[47].sensor_type
                );
                assert_eq!(
                    msg.sol_in[48].flags, 145,
                    "incorrect value for sol_in[48].flags, expected 145, is {}",
                    msg.sol_in[48].flags
                );
                assert_eq!(
                    msg.sol_in[48].sensor_type, 249,
                    "incorrect value for sol_in[48].sensor_type, expected 249, is {}",
                    msg.sol_in[48].sensor_type
                );
                assert_eq!(
                    msg.sol_in[49].flags, 78,
                    "incorrect value for sol_in[49].flags, expected 78, is {}",
                    msg.sol_in[49].flags
                );
                assert_eq!(
                    msg.sol_in[49].sensor_type, 15,
                    "incorrect value for sol_in[49].sensor_type, expected 15, is {}",
                    msg.sol_in[49].sensor_type
                );
                assert_eq!(
                    msg.sol_in[50].flags, 38,
                    "incorrect value for sol_in[50].flags, expected 38, is {}",
                    msg.sol_in[50].flags
                );
                assert_eq!(
                    msg.sol_in[50].sensor_type, 228,
                    "incorrect value for sol_in[50].sensor_type, expected 228, is {}",
                    msg.sol_in[50].sensor_type
                );
                assert_eq!(
                    msg.sol_in[51].flags, 129,
                    "incorrect value for sol_in[51].flags, expected 129, is {}",
                    msg.sol_in[51].flags
                );
                assert_eq!(
                    msg.sol_in[51].sensor_type, 241,
                    "incorrect value for sol_in[51].sensor_type, expected 241, is {}",
                    msg.sol_in[51].sensor_type
                );
                assert_eq!(
                    msg.sol_in[52].flags, 176,
                    "incorrect value for sol_in[52].flags, expected 176, is {}",
                    msg.sol_in[52].flags
                );
                assert_eq!(
                    msg.sol_in[52].sensor_type, 8,
                    "incorrect value for sol_in[52].sensor_type, expected 8, is {}",
                    msg.sol_in[52].sensor_type
                );
                assert_eq!(
                    msg.sol_in[53].flags, 72,
                    "incorrect value for sol_in[53].flags, expected 72, is {}",
                    msg.sol_in[53].flags
                );
                assert_eq!(
                    msg.sol_in[53].sensor_type, 251,
                    "incorrect value for sol_in[53].sensor_type, expected 251, is {}",
                    msg.sol_in[53].sensor_type
                );
                assert_eq!(
                    msg.sol_in[54].flags, 80,
                    "incorrect value for sol_in[54].flags, expected 80, is {}",
                    msg.sol_in[54].flags
                );
                assert_eq!(
                    msg.sol_in[54].sensor_type, 248,
                    "incorrect value for sol_in[54].sensor_type, expected 248, is {}",
                    msg.sol_in[54].sensor_type
                );
                assert_eq!(
                    msg.sol_in[55].flags, 244,
                    "incorrect value for sol_in[55].flags, expected 244, is {}",
                    msg.sol_in[55].flags
                );
                assert_eq!(
                    msg.sol_in[55].sensor_type, 115,
                    "incorrect value for sol_in[55].sensor_type, expected 115, is {}",
                    msg.sol_in[55].sensor_type
                );
                assert_eq!(
                    msg.sol_in[56].flags, 145,
                    "incorrect value for sol_in[56].flags, expected 145, is {}",
                    msg.sol_in[56].flags
                );
                assert_eq!(
                    msg.sol_in[56].sensor_type, 231,
                    "incorrect value for sol_in[56].sensor_type, expected 231, is {}",
                    msg.sol_in[56].sensor_type
                );
                assert_eq!(
                    msg.sol_in[57].flags, 190,
                    "incorrect value for sol_in[57].flags, expected 190, is {}",
                    msg.sol_in[57].flags
                );
                assert_eq!(
                    msg.sol_in[57].sensor_type, 191,
                    "incorrect value for sol_in[57].sensor_type, expected 191, is {}",
                    msg.sol_in[57].sensor_type
                );
                assert_eq!(
                    msg.sol_in[58].flags, 168,
                    "incorrect value for sol_in[58].flags, expected 168, is {}",
                    msg.sol_in[58].flags
                );
                assert_eq!(
                    msg.sol_in[58].sensor_type, 178,
                    "incorrect value for sol_in[58].sensor_type, expected 178, is {}",
                    msg.sol_in[58].sensor_type
                );
                assert_eq!(
                    msg.sol_in[59].flags, 233,
                    "incorrect value for sol_in[59].flags, expected 233, is {}",
                    msg.sol_in[59].flags
                );
                assert_eq!(
                    msg.sol_in[59].sensor_type, 89,
                    "incorrect value for sol_in[59].sensor_type, expected 89, is {}",
                    msg.sol_in[59].sensor_type
                );
                assert_eq!(
                    msg.sol_in[60].flags, 176,
                    "incorrect value for sol_in[60].flags, expected 176, is {}",
                    msg.sol_in[60].flags
                );
                assert_eq!(
                    msg.sol_in[60].sensor_type, 69,
                    "incorrect value for sol_in[60].sensor_type, expected 69, is {}",
                    msg.sol_in[60].sensor_type
                );
                assert_eq!(
                    msg.sol_in[61].flags, 140,
                    "incorrect value for sol_in[61].flags, expected 140, is {}",
                    msg.sol_in[61].flags
                );
                assert_eq!(
                    msg.sol_in[61].sensor_type, 174,
                    "incorrect value for sol_in[61].sensor_type, expected 174, is {}",
                    msg.sol_in[61].sensor_type
                );
                assert_eq!(
                    msg.sol_in[62].flags, 141,
                    "incorrect value for sol_in[62].flags, expected 141, is {}",
                    msg.sol_in[62].flags
                );
                assert_eq!(
                    msg.sol_in[62].sensor_type, 182,
                    "incorrect value for sol_in[62].sensor_type, expected 182, is {}",
                    msg.sol_in[62].sensor_type
                );
                assert_eq!(
                    msg.sol_in[63].flags, 82,
                    "incorrect value for sol_in[63].flags, expected 82, is {}",
                    msg.sol_in[63].flags
                );
                assert_eq!(
                    msg.sol_in[63].sensor_type, 81,
                    "incorrect value for sol_in[63].sensor_type, expected 81, is {}",
                    msg.sol_in[63].sensor_type
                );
                assert_eq!(
                    msg.sol_in[64].flags, 79,
                    "incorrect value for sol_in[64].flags, expected 79, is {}",
                    msg.sol_in[64].flags
                );
                assert_eq!(
                    msg.sol_in[64].sensor_type, 92,
                    "incorrect value for sol_in[64].sensor_type, expected 92, is {}",
                    msg.sol_in[64].sensor_type
                );
                assert_eq!(
                    msg.sol_in[65].flags, 223,
                    "incorrect value for sol_in[65].flags, expected 223, is {}",
                    msg.sol_in[65].flags
                );
                assert_eq!(
                    msg.sol_in[65].sensor_type, 101,
                    "incorrect value for sol_in[65].sensor_type, expected 101, is {}",
                    msg.sol_in[65].sensor_type
                );
                assert_eq!(
                    msg.sol_in[66].flags, 64,
                    "incorrect value for sol_in[66].flags, expected 64, is {}",
                    msg.sol_in[66].flags
                );
                assert_eq!(
                    msg.sol_in[66].sensor_type, 100,
                    "incorrect value for sol_in[66].sensor_type, expected 100, is {}",
                    msg.sol_in[66].sensor_type
                );
                assert_eq!(
                    msg.sol_in[67].flags, 215,
                    "incorrect value for sol_in[67].flags, expected 215, is {}",
                    msg.sol_in[67].flags
                );
                assert_eq!(
                    msg.sol_in[67].sensor_type, 184,
                    "incorrect value for sol_in[67].sensor_type, expected 184, is {}",
                    msg.sol_in[67].sensor_type
                );
                assert_eq!(
                    msg.sol_in[68].flags, 37,
                    "incorrect value for sol_in[68].flags, expected 37, is {}",
                    msg.sol_in[68].flags
                );
                assert_eq!(
                    msg.sol_in[68].sensor_type, 124,
                    "incorrect value for sol_in[68].sensor_type, expected 124, is {}",
                    msg.sol_in[68].sensor_type
                );
                assert_eq!(
                    msg.sol_in[69].flags, 227,
                    "incorrect value for sol_in[69].flags, expected 227, is {}",
                    msg.sol_in[69].flags
                );
                assert_eq!(
                    msg.sol_in[69].sensor_type, 21,
                    "incorrect value for sol_in[69].sensor_type, expected 21, is {}",
                    msg.sol_in[69].sensor_type
                );
                assert_eq!(
                    msg.sol_in[70].flags, 102,
                    "incorrect value for sol_in[70].flags, expected 102, is {}",
                    msg.sol_in[70].flags
                );
                assert_eq!(
                    msg.sol_in[70].sensor_type, 135,
                    "incorrect value for sol_in[70].sensor_type, expected 135, is {}",
                    msg.sol_in[70].sensor_type
                );
                assert_eq!(
                    msg.sol_in[71].flags, 36,
                    "incorrect value for sol_in[71].flags, expected 36, is {}",
                    msg.sol_in[71].flags
                );
                assert_eq!(
                    msg.sol_in[71].sensor_type, 72,
                    "incorrect value for sol_in[71].sensor_type, expected 72, is {}",
                    msg.sol_in[71].sensor_type
                );
                assert_eq!(
                    msg.sol_in[72].flags, 56,
                    "incorrect value for sol_in[72].flags, expected 56, is {}",
                    msg.sol_in[72].flags
                );
                assert_eq!(
                    msg.sol_in[72].sensor_type, 219,
                    "incorrect value for sol_in[72].sensor_type, expected 219, is {}",
                    msg.sol_in[72].sensor_type
                );
                assert_eq!(
                    msg.sol_in[73].flags, 90,
                    "incorrect value for sol_in[73].flags, expected 90, is {}",
                    msg.sol_in[73].flags
                );
                assert_eq!(
                    msg.sol_in[73].sensor_type, 146,
                    "incorrect value for sol_in[73].sensor_type, expected 146, is {}",
                    msg.sol_in[73].sensor_type
                );
                assert_eq!(
                    msg.sol_in[74].flags, 104,
                    "incorrect value for sol_in[74].flags, expected 104, is {}",
                    msg.sol_in[74].flags
                );
                assert_eq!(
                    msg.sol_in[74].sensor_type, 219,
                    "incorrect value for sol_in[74].sensor_type, expected 219, is {}",
                    msg.sol_in[74].sensor_type
                );
                assert_eq!(
                    msg.sol_in[75].flags, 102,
                    "incorrect value for sol_in[75].flags, expected 102, is {}",
                    msg.sol_in[75].flags
                );
                assert_eq!(
                    msg.sol_in[75].sensor_type, 227,
                    "incorrect value for sol_in[75].sensor_type, expected 227, is {}",
                    msg.sol_in[75].sensor_type
                );
                assert_eq!(
                    msg.sol_in[76].flags, 12,
                    "incorrect value for sol_in[76].flags, expected 12, is {}",
                    msg.sol_in[76].flags
                );
                assert_eq!(
                    msg.sol_in[76].sensor_type, 83,
                    "incorrect value for sol_in[76].sensor_type, expected 83, is {}",
                    msg.sol_in[76].sensor_type
                );
                assert_eq!(
                    msg.sol_in[77].flags, 122,
                    "incorrect value for sol_in[77].flags, expected 122, is {}",
                    msg.sol_in[77].flags
                );
                assert_eq!(
                    msg.sol_in[77].sensor_type, 41,
                    "incorrect value for sol_in[77].sensor_type, expected 41, is {}",
                    msg.sol_in[77].sensor_type
                );
                assert_eq!(
                    msg.sol_in[78].flags, 94,
                    "incorrect value for sol_in[78].flags, expected 94, is {}",
                    msg.sol_in[78].flags
                );
                assert_eq!(
                    msg.sol_in[78].sensor_type, 173,
                    "incorrect value for sol_in[78].sensor_type, expected 173, is {}",
                    msg.sol_in[78].sensor_type
                );
                assert_eq!(
                    msg.sol_in[79].flags, 174,
                    "incorrect value for sol_in[79].flags, expected 174, is {}",
                    msg.sol_in[79].flags
                );
                assert_eq!(
                    msg.sol_in[79].sensor_type, 1,
                    "incorrect value for sol_in[79].sensor_type, expected 1, is {}",
                    msg.sol_in[79].sensor_type
                );
                assert_eq!(
                    msg.sol_in[80].flags, 130,
                    "incorrect value for sol_in[80].flags, expected 130, is {}",
                    msg.sol_in[80].flags
                );
                assert_eq!(
                    msg.sol_in[80].sensor_type, 134,
                    "incorrect value for sol_in[80].sensor_type, expected 134, is {}",
                    msg.sol_in[80].sensor_type
                );
                assert_eq!(
                    msg.sol_in[81].flags, 237,
                    "incorrect value for sol_in[81].flags, expected 237, is {}",
                    msg.sol_in[81].flags
                );
                assert_eq!(
                    msg.sol_in[81].sensor_type, 104,
                    "incorrect value for sol_in[81].sensor_type, expected 104, is {}",
                    msg.sol_in[81].sensor_type
                );
                assert_eq!(
                    msg.sol_in[82].flags, 249,
                    "incorrect value for sol_in[82].flags, expected 249, is {}",
                    msg.sol_in[82].flags
                );
                assert_eq!(
                    msg.sol_in[82].sensor_type, 116,
                    "incorrect value for sol_in[82].sensor_type, expected 116, is {}",
                    msg.sol_in[82].sensor_type
                );
                assert_eq!(
                    msg.sol_in[83].flags, 230,
                    "incorrect value for sol_in[83].flags, expected 230, is {}",
                    msg.sol_in[83].flags
                );
                assert_eq!(
                    msg.sol_in[83].sensor_type, 107,
                    "incorrect value for sol_in[83].sensor_type, expected 107, is {}",
                    msg.sol_in[83].sensor_type
                );
                assert_eq!(
                    msg.sol_in[84].flags, 123,
                    "incorrect value for sol_in[84].flags, expected 123, is {}",
                    msg.sol_in[84].flags
                );
                assert_eq!(
                    msg.sol_in[84].sensor_type, 130,
                    "incorrect value for sol_in[84].sensor_type, expected 130, is {}",
                    msg.sol_in[84].sensor_type
                );
                assert_eq!(
                    msg.sol_in[85].flags, 162,
                    "incorrect value for sol_in[85].flags, expected 162, is {}",
                    msg.sol_in[85].flags
                );
                assert_eq!(
                    msg.sol_in[85].sensor_type, 25,
                    "incorrect value for sol_in[85].sensor_type, expected 25, is {}",
                    msg.sol_in[85].sensor_type
                );
                assert_eq!(
                    msg.sol_in[86].flags, 223,
                    "incorrect value for sol_in[86].flags, expected 223, is {}",
                    msg.sol_in[86].flags
                );
                assert_eq!(
                    msg.sol_in[86].sensor_type, 57,
                    "incorrect value for sol_in[86].sensor_type, expected 57, is {}",
                    msg.sol_in[86].sensor_type
                );
                assert_eq!(
                    msg.sol_in[87].flags, 174,
                    "incorrect value for sol_in[87].flags, expected 174, is {}",
                    msg.sol_in[87].flags
                );
                assert_eq!(
                    msg.sol_in[87].sensor_type, 193,
                    "incorrect value for sol_in[87].sensor_type, expected 193, is {}",
                    msg.sol_in[87].sensor_type
                );
                assert_eq!(
                    msg.sol_in[88].flags, 193,
                    "incorrect value for sol_in[88].flags, expected 193, is {}",
                    msg.sol_in[88].flags
                );
                assert_eq!(
                    msg.sol_in[88].sensor_type, 146,
                    "incorrect value for sol_in[88].sensor_type, expected 146, is {}",
                    msg.sol_in[88].sensor_type
                );
                assert_eq!(
                    msg.sol_in[89].flags, 44,
                    "incorrect value for sol_in[89].flags, expected 44, is {}",
                    msg.sol_in[89].flags
                );
                assert_eq!(
                    msg.sol_in[89].sensor_type, 239,
                    "incorrect value for sol_in[89].sensor_type, expected 239, is {}",
                    msg.sol_in[89].sensor_type
                );
                assert_eq!(
                    msg.sol_in[90].flags, 197,
                    "incorrect value for sol_in[90].flags, expected 197, is {}",
                    msg.sol_in[90].flags
                );
                assert_eq!(
                    msg.sol_in[90].sensor_type, 246,
                    "incorrect value for sol_in[90].sensor_type, expected 246, is {}",
                    msg.sol_in[90].sensor_type
                );
                assert_eq!(
                    msg.sol_in[91].flags, 80,
                    "incorrect value for sol_in[91].flags, expected 80, is {}",
                    msg.sol_in[91].flags
                );
                assert_eq!(
                    msg.sol_in[91].sensor_type, 214,
                    "incorrect value for sol_in[91].sensor_type, expected 214, is {}",
                    msg.sol_in[91].sensor_type
                );
                assert_eq!(
                    msg.sol_in[92].flags, 100,
                    "incorrect value for sol_in[92].flags, expected 100, is {}",
                    msg.sol_in[92].flags
                );
                assert_eq!(
                    msg.sol_in[92].sensor_type, 83,
                    "incorrect value for sol_in[92].sensor_type, expected 83, is {}",
                    msg.sol_in[92].sensor_type
                );
                assert_eq!(
                    msg.sol_in[93].flags, 72,
                    "incorrect value for sol_in[93].flags, expected 72, is {}",
                    msg.sol_in[93].flags
                );
                assert_eq!(
                    msg.sol_in[93].sensor_type, 66,
                    "incorrect value for sol_in[93].sensor_type, expected 66, is {}",
                    msg.sol_in[93].sensor_type
                );
                assert_eq!(
                    msg.sol_in[94].flags, 137,
                    "incorrect value for sol_in[94].flags, expected 137, is {}",
                    msg.sol_in[94].flags
                );
                assert_eq!(
                    msg.sol_in[94].sensor_type, 133,
                    "incorrect value for sol_in[94].sensor_type, expected 133, is {}",
                    msg.sol_in[94].sensor_type
                );
                assert_eq!(
                    msg.sol_in[95].flags, 82,
                    "incorrect value for sol_in[95].flags, expected 82, is {}",
                    msg.sol_in[95].flags
                );
                assert_eq!(
                    msg.sol_in[95].sensor_type, 140,
                    "incorrect value for sol_in[95].sensor_type, expected 140, is {}",
                    msg.sol_in[95].sensor_type
                );
                assert_eq!(
                    msg.sol_in[96].flags, 2,
                    "incorrect value for sol_in[96].flags, expected 2, is {}",
                    msg.sol_in[96].flags
                );
                assert_eq!(
                    msg.sol_in[96].sensor_type, 2,
                    "incorrect value for sol_in[96].sensor_type, expected 2, is {}",
                    msg.sol_in[96].sensor_type
                );
                assert_eq!(
                    msg.sol_in[97].flags, 9,
                    "incorrect value for sol_in[97].flags, expected 9, is {}",
                    msg.sol_in[97].flags
                );
                assert_eq!(
                    msg.sol_in[97].sensor_type, 96,
                    "incorrect value for sol_in[97].sensor_type, expected 96, is {}",
                    msg.sol_in[97].sensor_type
                );
                assert_eq!(
                    msg.sol_in[98].flags, 158,
                    "incorrect value for sol_in[98].flags, expected 158, is {}",
                    msg.sol_in[98].flags
                );
                assert_eq!(
                    msg.sol_in[98].sensor_type, 96,
                    "incorrect value for sol_in[98].sensor_type, expected 96, is {}",
                    msg.sol_in[98].sensor_type
                );
                assert_eq!(
                    msg.sol_in[99].flags, 97,
                    "incorrect value for sol_in[99].flags, expected 97, is {}",
                    msg.sol_in[99].flags
                );
                assert_eq!(
                    msg.sol_in[99].sensor_type, 134,
                    "incorrect value for sol_in[99].sensor_type, expected 134, is {}",
                    msg.sol_in[99].sensor_type
                );
                assert_eq!(
                    msg.sol_in[100].flags, 129,
                    "incorrect value for sol_in[100].flags, expected 129, is {}",
                    msg.sol_in[100].flags
                );
                assert_eq!(
                    msg.sol_in[100].sensor_type, 43,
                    "incorrect value for sol_in[100].sensor_type, expected 43, is {}",
                    msg.sol_in[100].sensor_type
                );
                assert_eq!(
                    msg.sol_in[101].flags, 25,
                    "incorrect value for sol_in[101].flags, expected 25, is {}",
                    msg.sol_in[101].flags
                );
                assert_eq!(
                    msg.sol_in[101].sensor_type, 141,
                    "incorrect value for sol_in[101].sensor_type, expected 141, is {}",
                    msg.sol_in[101].sensor_type
                );
                assert_eq!(
                    msg.sol_in[102].flags, 200,
                    "incorrect value for sol_in[102].flags, expected 200, is {}",
                    msg.sol_in[102].flags
                );
                assert_eq!(
                    msg.sol_in[102].sensor_type, 183,
                    "incorrect value for sol_in[102].sensor_type, expected 183, is {}",
                    msg.sol_in[102].sensor_type
                );
                assert_eq!(
                    msg.sol_in[103].flags, 57,
                    "incorrect value for sol_in[103].flags, expected 57, is {}",
                    msg.sol_in[103].flags
                );
                assert_eq!(
                    msg.sol_in[103].sensor_type, 214,
                    "incorrect value for sol_in[103].sensor_type, expected 214, is {}",
                    msg.sol_in[103].sensor_type
                );
                assert_eq!(
                    msg.sol_in[104].flags, 103,
                    "incorrect value for sol_in[104].flags, expected 103, is {}",
                    msg.sol_in[104].flags
                );
                assert_eq!(
                    msg.sol_in[104].sensor_type, 248,
                    "incorrect value for sol_in[104].sensor_type, expected 248, is {}",
                    msg.sol_in[104].sensor_type
                );
                assert_eq!(
                    msg.sol_in[105].flags, 65,
                    "incorrect value for sol_in[105].flags, expected 65, is {}",
                    msg.sol_in[105].flags
                );
                assert_eq!(
                    msg.sol_in[105].sensor_type, 222,
                    "incorrect value for sol_in[105].sensor_type, expected 222, is {}",
                    msg.sol_in[105].sensor_type
                );
                assert_eq!(
                    msg.sol_in[106].flags, 15,
                    "incorrect value for sol_in[106].flags, expected 15, is {}",
                    msg.sol_in[106].flags
                );
                assert_eq!(
                    msg.sol_in[106].sensor_type, 195,
                    "incorrect value for sol_in[106].sensor_type, expected 195, is {}",
                    msg.sol_in[106].sensor_type
                );
                assert_eq!(
                    msg.sol_in[107].flags, 21,
                    "incorrect value for sol_in[107].flags, expected 21, is {}",
                    msg.sol_in[107].flags
                );
                assert_eq!(
                    msg.sol_in[107].sensor_type, 244,
                    "incorrect value for sol_in[107].sensor_type, expected 244, is {}",
                    msg.sol_in[107].sensor_type
                );
                assert_eq!(
                    msg.sol_in[108].flags, 46,
                    "incorrect value for sol_in[108].flags, expected 46, is {}",
                    msg.sol_in[108].flags
                );
                assert_eq!(
                    msg.sol_in[108].sensor_type, 180,
                    "incorrect value for sol_in[108].sensor_type, expected 180, is {}",
                    msg.sol_in[108].sensor_type
                );
                assert_eq!(
                    msg.sol_in[109].flags, 130,
                    "incorrect value for sol_in[109].flags, expected 130, is {}",
                    msg.sol_in[109].flags
                );
                assert_eq!(
                    msg.sol_in[109].sensor_type, 140,
                    "incorrect value for sol_in[109].sensor_type, expected 140, is {}",
                    msg.sol_in[109].sensor_type
                );
                assert_eq!(
                    msg.sol_in[110].flags, 17,
                    "incorrect value for sol_in[110].flags, expected 17, is {}",
                    msg.sol_in[110].flags
                );
                assert_eq!(
                    msg.sol_in[110].sensor_type, 36,
                    "incorrect value for sol_in[110].sensor_type, expected 36, is {}",
                    msg.sol_in[110].sensor_type
                );
                assert_eq!(
                    msg.sol_in[111].flags, 209,
                    "incorrect value for sol_in[111].flags, expected 209, is {}",
                    msg.sol_in[111].flags
                );
                assert_eq!(
                    msg.sol_in[111].sensor_type, 194,
                    "incorrect value for sol_in[111].sensor_type, expected 194, is {}",
                    msg.sol_in[111].sensor_type
                );
                assert_eq!(
                    msg.sol_in[112].flags, 254,
                    "incorrect value for sol_in[112].flags, expected 254, is {}",
                    msg.sol_in[112].flags
                );
                assert_eq!(
                    msg.sol_in[112].sensor_type, 65,
                    "incorrect value for sol_in[112].sensor_type, expected 65, is {}",
                    msg.sol_in[112].sensor_type
                );
                assert_eq!(
                    msg.sol_in[113].flags, 103,
                    "incorrect value for sol_in[113].flags, expected 103, is {}",
                    msg.sol_in[113].flags
                );
                assert_eq!(
                    msg.sol_in[113].sensor_type, 115,
                    "incorrect value for sol_in[113].sensor_type, expected 115, is {}",
                    msg.sol_in[113].sensor_type
                );
                assert_eq!(
                    msg.sol_in[114].flags, 129,
                    "incorrect value for sol_in[114].flags, expected 129, is {}",
                    msg.sol_in[114].flags
                );
                assert_eq!(
                    msg.sol_in[114].sensor_type, 152,
                    "incorrect value for sol_in[114].sensor_type, expected 152, is {}",
                    msg.sol_in[114].sensor_type
                );
                assert_eq!(
                    msg.sol_in[115].flags, 235,
                    "incorrect value for sol_in[115].flags, expected 235, is {}",
                    msg.sol_in[115].flags
                );
                assert_eq!(
                    msg.sol_in[115].sensor_type, 234,
                    "incorrect value for sol_in[115].sensor_type, expected 234, is {}",
                    msg.sol_in[115].sensor_type
                );
                assert_eq!(
                    msg.sol_in[116].flags, 234,
                    "incorrect value for sol_in[116].flags, expected 234, is {}",
                    msg.sol_in[116].flags
                );
                assert_eq!(
                    msg.sol_in[116].sensor_type, 194,
                    "incorrect value for sol_in[116].sensor_type, expected 194, is {}",
                    msg.sol_in[116].sensor_type
                );
                assert_eq!(
                    msg.sol_in[117].flags, 201,
                    "incorrect value for sol_in[117].flags, expected 201, is {}",
                    msg.sol_in[117].flags
                );
                assert_eq!(
                    msg.sol_in[117].sensor_type, 170,
                    "incorrect value for sol_in[117].sensor_type, expected 170, is {}",
                    msg.sol_in[117].sensor_type
                );
                assert_eq!(
                    msg.sol_in[118].flags, 154,
                    "incorrect value for sol_in[118].flags, expected 154, is {}",
                    msg.sol_in[118].flags
                );
                assert_eq!(
                    msg.sol_in[118].sensor_type, 210,
                    "incorrect value for sol_in[118].sensor_type, expected 210, is {}",
                    msg.sol_in[118].sensor_type
                );
                assert_eq!(
                    msg.tow, 3628191792,
                    "incorrect value for tow, expected 3628191792, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 58512,
                    "incorrect value for vdop, expected 58512, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSolnMeta"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
