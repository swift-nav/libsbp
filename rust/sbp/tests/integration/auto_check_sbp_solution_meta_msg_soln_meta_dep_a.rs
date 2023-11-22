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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/soln_meta/test_MsgSolnMetaDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_solution_meta_msg_soln_meta_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 15, 255, 84, 241, 254, 183, 222, 157, 121, 5, 164, 238, 31, 190, 115, 93, 59, 103,
            36, 83, 161, 156, 46, 253, 67, 87, 200, 39, 250, 245, 242, 228, 72, 18, 222, 11, 88,
            207, 218, 231, 13, 226, 224, 22, 196, 21, 242, 12, 89, 71, 219, 182, 85, 145, 204, 146,
            40, 204, 51, 21, 153, 227, 44, 15, 28, 255, 39, 205, 216, 240, 190, 93, 219, 103, 42,
            41, 182, 76, 222, 17, 23, 125, 31, 18, 229, 28, 47, 214, 25, 100, 84, 106, 72, 48, 10,
            222, 232, 235, 73, 109, 163, 51, 152, 133, 235, 87, 70, 2, 108, 91, 101, 200, 55, 24,
            156, 233, 73, 39, 66, 97, 140, 252, 227, 230, 237, 135, 241, 245, 205, 70, 0, 219, 188,
            107, 136, 178, 58, 1, 29, 44, 213, 225, 147, 190, 96, 192, 108, 228, 15, 203, 18, 3,
            222, 180, 68, 101, 229, 223, 203, 243, 164, 92, 165, 220, 159, 174, 121, 112, 167, 240,
            40, 59, 3, 230, 52, 149, 148, 218, 142, 212, 109, 176, 71, 179, 172, 77, 1, 193, 70,
            147, 149, 23, 144, 148, 239, 195, 186, 86, 30, 34, 143, 156, 207, 63, 55, 117, 255,
            222, 222, 219, 145, 224, 191, 210, 109, 86, 153, 21, 32, 226, 10, 60, 63, 106, 236, 93,
            96, 30, 163, 106, 238, 147, 133, 132, 107, 152, 214, 221, 185, 202, 21, 252, 51, 130,
            59, 166, 202, 127, 170, 58, 193, 215, 125, 22, 58, 135, 47, 88, 142, 77, 211,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSolnMetaDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff0f,
                    "Incorrect message type, expected 0xff0f, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf154,
                    "incorrect sender id, expected 0xf154, is {sender_id}"
                );
                assert_eq!(
                    msg.age_corrections, 48671,
                    "incorrect value for age_corrections, expected 48671, is {}",
                    msg.age_corrections
                );
                assert_eq!(
                    msg.alignment_status, 115,
                    "incorrect value for alignment_status, expected 115, is {}",
                    msg.alignment_status
                );
                assert_eq!(
                    msg.hdop, 31133,
                    "incorrect value for hdop, expected 31133, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.last_used_gnss_pos_tow, 610745181,
                    "incorrect value for last_used_gnss_pos_tow, expected 610745181, is {}",
                    msg.last_used_gnss_pos_tow
                );
                assert_eq!(
                    msg.last_used_gnss_vel_tow, 782016851,
                    "incorrect value for last_used_gnss_vel_tow, expected 782016851, is {}",
                    msg.last_used_gnss_vel_tow
                );
                assert_eq!(
                    msg.n_sats, 238,
                    "incorrect value for n_sats, expected 238, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.pdop, 57015,
                    "incorrect value for pdop, expected 57015, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.sol_in[0].flags, 67,
                    "incorrect value for sol_in[0].flags, expected 67, is {}",
                    msg.sol_in[0].flags
                );
                assert_eq!(
                    msg.sol_in[0].sensor_type, 253,
                    "incorrect value for sol_in[0].sensor_type, expected 253, is {}",
                    msg.sol_in[0].sensor_type
                );
                assert_eq!(
                    msg.sol_in[1].flags, 200,
                    "incorrect value for sol_in[1].flags, expected 200, is {}",
                    msg.sol_in[1].flags
                );
                assert_eq!(
                    msg.sol_in[1].sensor_type, 87,
                    "incorrect value for sol_in[1].sensor_type, expected 87, is {}",
                    msg.sol_in[1].sensor_type
                );
                assert_eq!(
                    msg.sol_in[2].flags, 250,
                    "incorrect value for sol_in[2].flags, expected 250, is {}",
                    msg.sol_in[2].flags
                );
                assert_eq!(
                    msg.sol_in[2].sensor_type, 39,
                    "incorrect value for sol_in[2].sensor_type, expected 39, is {}",
                    msg.sol_in[2].sensor_type
                );
                assert_eq!(
                    msg.sol_in[3].flags, 242,
                    "incorrect value for sol_in[3].flags, expected 242, is {}",
                    msg.sol_in[3].flags
                );
                assert_eq!(
                    msg.sol_in[3].sensor_type, 245,
                    "incorrect value for sol_in[3].sensor_type, expected 245, is {}",
                    msg.sol_in[3].sensor_type
                );
                assert_eq!(
                    msg.sol_in[4].flags, 72,
                    "incorrect value for sol_in[4].flags, expected 72, is {}",
                    msg.sol_in[4].flags
                );
                assert_eq!(
                    msg.sol_in[4].sensor_type, 228,
                    "incorrect value for sol_in[4].sensor_type, expected 228, is {}",
                    msg.sol_in[4].sensor_type
                );
                assert_eq!(
                    msg.sol_in[5].flags, 222,
                    "incorrect value for sol_in[5].flags, expected 222, is {}",
                    msg.sol_in[5].flags
                );
                assert_eq!(
                    msg.sol_in[5].sensor_type, 18,
                    "incorrect value for sol_in[5].sensor_type, expected 18, is {}",
                    msg.sol_in[5].sensor_type
                );
                assert_eq!(
                    msg.sol_in[6].flags, 88,
                    "incorrect value for sol_in[6].flags, expected 88, is {}",
                    msg.sol_in[6].flags
                );
                assert_eq!(
                    msg.sol_in[6].sensor_type, 11,
                    "incorrect value for sol_in[6].sensor_type, expected 11, is {}",
                    msg.sol_in[6].sensor_type
                );
                assert_eq!(
                    msg.sol_in[7].flags, 218,
                    "incorrect value for sol_in[7].flags, expected 218, is {}",
                    msg.sol_in[7].flags
                );
                assert_eq!(
                    msg.sol_in[7].sensor_type, 207,
                    "incorrect value for sol_in[7].sensor_type, expected 207, is {}",
                    msg.sol_in[7].sensor_type
                );
                assert_eq!(
                    msg.sol_in[8].flags, 13,
                    "incorrect value for sol_in[8].flags, expected 13, is {}",
                    msg.sol_in[8].flags
                );
                assert_eq!(
                    msg.sol_in[8].sensor_type, 231,
                    "incorrect value for sol_in[8].sensor_type, expected 231, is {}",
                    msg.sol_in[8].sensor_type
                );
                assert_eq!(
                    msg.sol_in[9].flags, 224,
                    "incorrect value for sol_in[9].flags, expected 224, is {}",
                    msg.sol_in[9].flags
                );
                assert_eq!(
                    msg.sol_in[9].sensor_type, 226,
                    "incorrect value for sol_in[9].sensor_type, expected 226, is {}",
                    msg.sol_in[9].sensor_type
                );
                assert_eq!(
                    msg.sol_in[10].flags, 196,
                    "incorrect value for sol_in[10].flags, expected 196, is {}",
                    msg.sol_in[10].flags
                );
                assert_eq!(
                    msg.sol_in[10].sensor_type, 22,
                    "incorrect value for sol_in[10].sensor_type, expected 22, is {}",
                    msg.sol_in[10].sensor_type
                );
                assert_eq!(
                    msg.sol_in[11].flags, 242,
                    "incorrect value for sol_in[11].flags, expected 242, is {}",
                    msg.sol_in[11].flags
                );
                assert_eq!(
                    msg.sol_in[11].sensor_type, 21,
                    "incorrect value for sol_in[11].sensor_type, expected 21, is {}",
                    msg.sol_in[11].sensor_type
                );
                assert_eq!(
                    msg.sol_in[12].flags, 89,
                    "incorrect value for sol_in[12].flags, expected 89, is {}",
                    msg.sol_in[12].flags
                );
                assert_eq!(
                    msg.sol_in[12].sensor_type, 12,
                    "incorrect value for sol_in[12].sensor_type, expected 12, is {}",
                    msg.sol_in[12].sensor_type
                );
                assert_eq!(
                    msg.sol_in[13].flags, 219,
                    "incorrect value for sol_in[13].flags, expected 219, is {}",
                    msg.sol_in[13].flags
                );
                assert_eq!(
                    msg.sol_in[13].sensor_type, 71,
                    "incorrect value for sol_in[13].sensor_type, expected 71, is {}",
                    msg.sol_in[13].sensor_type
                );
                assert_eq!(
                    msg.sol_in[14].flags, 85,
                    "incorrect value for sol_in[14].flags, expected 85, is {}",
                    msg.sol_in[14].flags
                );
                assert_eq!(
                    msg.sol_in[14].sensor_type, 182,
                    "incorrect value for sol_in[14].sensor_type, expected 182, is {}",
                    msg.sol_in[14].sensor_type
                );
                assert_eq!(
                    msg.sol_in[15].flags, 204,
                    "incorrect value for sol_in[15].flags, expected 204, is {}",
                    msg.sol_in[15].flags
                );
                assert_eq!(
                    msg.sol_in[15].sensor_type, 145,
                    "incorrect value for sol_in[15].sensor_type, expected 145, is {}",
                    msg.sol_in[15].sensor_type
                );
                assert_eq!(
                    msg.sol_in[16].flags, 40,
                    "incorrect value for sol_in[16].flags, expected 40, is {}",
                    msg.sol_in[16].flags
                );
                assert_eq!(
                    msg.sol_in[16].sensor_type, 146,
                    "incorrect value for sol_in[16].sensor_type, expected 146, is {}",
                    msg.sol_in[16].sensor_type
                );
                assert_eq!(
                    msg.sol_in[17].flags, 51,
                    "incorrect value for sol_in[17].flags, expected 51, is {}",
                    msg.sol_in[17].flags
                );
                assert_eq!(
                    msg.sol_in[17].sensor_type, 204,
                    "incorrect value for sol_in[17].sensor_type, expected 204, is {}",
                    msg.sol_in[17].sensor_type
                );
                assert_eq!(
                    msg.sol_in[18].flags, 153,
                    "incorrect value for sol_in[18].flags, expected 153, is {}",
                    msg.sol_in[18].flags
                );
                assert_eq!(
                    msg.sol_in[18].sensor_type, 21,
                    "incorrect value for sol_in[18].sensor_type, expected 21, is {}",
                    msg.sol_in[18].sensor_type
                );
                assert_eq!(
                    msg.sol_in[19].flags, 44,
                    "incorrect value for sol_in[19].flags, expected 44, is {}",
                    msg.sol_in[19].flags
                );
                assert_eq!(
                    msg.sol_in[19].sensor_type, 227,
                    "incorrect value for sol_in[19].sensor_type, expected 227, is {}",
                    msg.sol_in[19].sensor_type
                );
                assert_eq!(
                    msg.sol_in[20].flags, 28,
                    "incorrect value for sol_in[20].flags, expected 28, is {}",
                    msg.sol_in[20].flags
                );
                assert_eq!(
                    msg.sol_in[20].sensor_type, 15,
                    "incorrect value for sol_in[20].sensor_type, expected 15, is {}",
                    msg.sol_in[20].sensor_type
                );
                assert_eq!(
                    msg.sol_in[21].flags, 39,
                    "incorrect value for sol_in[21].flags, expected 39, is {}",
                    msg.sol_in[21].flags
                );
                assert_eq!(
                    msg.sol_in[21].sensor_type, 255,
                    "incorrect value for sol_in[21].sensor_type, expected 255, is {}",
                    msg.sol_in[21].sensor_type
                );
                assert_eq!(
                    msg.sol_in[22].flags, 216,
                    "incorrect value for sol_in[22].flags, expected 216, is {}",
                    msg.sol_in[22].flags
                );
                assert_eq!(
                    msg.sol_in[22].sensor_type, 205,
                    "incorrect value for sol_in[22].sensor_type, expected 205, is {}",
                    msg.sol_in[22].sensor_type
                );
                assert_eq!(
                    msg.sol_in[23].flags, 190,
                    "incorrect value for sol_in[23].flags, expected 190, is {}",
                    msg.sol_in[23].flags
                );
                assert_eq!(
                    msg.sol_in[23].sensor_type, 240,
                    "incorrect value for sol_in[23].sensor_type, expected 240, is {}",
                    msg.sol_in[23].sensor_type
                );
                assert_eq!(
                    msg.sol_in[24].flags, 219,
                    "incorrect value for sol_in[24].flags, expected 219, is {}",
                    msg.sol_in[24].flags
                );
                assert_eq!(
                    msg.sol_in[24].sensor_type, 93,
                    "incorrect value for sol_in[24].sensor_type, expected 93, is {}",
                    msg.sol_in[24].sensor_type
                );
                assert_eq!(
                    msg.sol_in[25].flags, 42,
                    "incorrect value for sol_in[25].flags, expected 42, is {}",
                    msg.sol_in[25].flags
                );
                assert_eq!(
                    msg.sol_in[25].sensor_type, 103,
                    "incorrect value for sol_in[25].sensor_type, expected 103, is {}",
                    msg.sol_in[25].sensor_type
                );
                assert_eq!(
                    msg.sol_in[26].flags, 182,
                    "incorrect value for sol_in[26].flags, expected 182, is {}",
                    msg.sol_in[26].flags
                );
                assert_eq!(
                    msg.sol_in[26].sensor_type, 41,
                    "incorrect value for sol_in[26].sensor_type, expected 41, is {}",
                    msg.sol_in[26].sensor_type
                );
                assert_eq!(
                    msg.sol_in[27].flags, 222,
                    "incorrect value for sol_in[27].flags, expected 222, is {}",
                    msg.sol_in[27].flags
                );
                assert_eq!(
                    msg.sol_in[27].sensor_type, 76,
                    "incorrect value for sol_in[27].sensor_type, expected 76, is {}",
                    msg.sol_in[27].sensor_type
                );
                assert_eq!(
                    msg.sol_in[28].flags, 23,
                    "incorrect value for sol_in[28].flags, expected 23, is {}",
                    msg.sol_in[28].flags
                );
                assert_eq!(
                    msg.sol_in[28].sensor_type, 17,
                    "incorrect value for sol_in[28].sensor_type, expected 17, is {}",
                    msg.sol_in[28].sensor_type
                );
                assert_eq!(
                    msg.sol_in[29].flags, 31,
                    "incorrect value for sol_in[29].flags, expected 31, is {}",
                    msg.sol_in[29].flags
                );
                assert_eq!(
                    msg.sol_in[29].sensor_type, 125,
                    "incorrect value for sol_in[29].sensor_type, expected 125, is {}",
                    msg.sol_in[29].sensor_type
                );
                assert_eq!(
                    msg.sol_in[30].flags, 229,
                    "incorrect value for sol_in[30].flags, expected 229, is {}",
                    msg.sol_in[30].flags
                );
                assert_eq!(
                    msg.sol_in[30].sensor_type, 18,
                    "incorrect value for sol_in[30].sensor_type, expected 18, is {}",
                    msg.sol_in[30].sensor_type
                );
                assert_eq!(
                    msg.sol_in[31].flags, 47,
                    "incorrect value for sol_in[31].flags, expected 47, is {}",
                    msg.sol_in[31].flags
                );
                assert_eq!(
                    msg.sol_in[31].sensor_type, 28,
                    "incorrect value for sol_in[31].sensor_type, expected 28, is {}",
                    msg.sol_in[31].sensor_type
                );
                assert_eq!(
                    msg.sol_in[32].flags, 25,
                    "incorrect value for sol_in[32].flags, expected 25, is {}",
                    msg.sol_in[32].flags
                );
                assert_eq!(
                    msg.sol_in[32].sensor_type, 214,
                    "incorrect value for sol_in[32].sensor_type, expected 214, is {}",
                    msg.sol_in[32].sensor_type
                );
                assert_eq!(
                    msg.sol_in[33].flags, 84,
                    "incorrect value for sol_in[33].flags, expected 84, is {}",
                    msg.sol_in[33].flags
                );
                assert_eq!(
                    msg.sol_in[33].sensor_type, 100,
                    "incorrect value for sol_in[33].sensor_type, expected 100, is {}",
                    msg.sol_in[33].sensor_type
                );
                assert_eq!(
                    msg.sol_in[34].flags, 72,
                    "incorrect value for sol_in[34].flags, expected 72, is {}",
                    msg.sol_in[34].flags
                );
                assert_eq!(
                    msg.sol_in[34].sensor_type, 106,
                    "incorrect value for sol_in[34].sensor_type, expected 106, is {}",
                    msg.sol_in[34].sensor_type
                );
                assert_eq!(
                    msg.sol_in[35].flags, 10,
                    "incorrect value for sol_in[35].flags, expected 10, is {}",
                    msg.sol_in[35].flags
                );
                assert_eq!(
                    msg.sol_in[35].sensor_type, 48,
                    "incorrect value for sol_in[35].sensor_type, expected 48, is {}",
                    msg.sol_in[35].sensor_type
                );
                assert_eq!(
                    msg.sol_in[36].flags, 232,
                    "incorrect value for sol_in[36].flags, expected 232, is {}",
                    msg.sol_in[36].flags
                );
                assert_eq!(
                    msg.sol_in[36].sensor_type, 222,
                    "incorrect value for sol_in[36].sensor_type, expected 222, is {}",
                    msg.sol_in[36].sensor_type
                );
                assert_eq!(
                    msg.sol_in[37].flags, 73,
                    "incorrect value for sol_in[37].flags, expected 73, is {}",
                    msg.sol_in[37].flags
                );
                assert_eq!(
                    msg.sol_in[37].sensor_type, 235,
                    "incorrect value for sol_in[37].sensor_type, expected 235, is {}",
                    msg.sol_in[37].sensor_type
                );
                assert_eq!(
                    msg.sol_in[38].flags, 163,
                    "incorrect value for sol_in[38].flags, expected 163, is {}",
                    msg.sol_in[38].flags
                );
                assert_eq!(
                    msg.sol_in[38].sensor_type, 109,
                    "incorrect value for sol_in[38].sensor_type, expected 109, is {}",
                    msg.sol_in[38].sensor_type
                );
                assert_eq!(
                    msg.sol_in[39].flags, 152,
                    "incorrect value for sol_in[39].flags, expected 152, is {}",
                    msg.sol_in[39].flags
                );
                assert_eq!(
                    msg.sol_in[39].sensor_type, 51,
                    "incorrect value for sol_in[39].sensor_type, expected 51, is {}",
                    msg.sol_in[39].sensor_type
                );
                assert_eq!(
                    msg.sol_in[40].flags, 235,
                    "incorrect value for sol_in[40].flags, expected 235, is {}",
                    msg.sol_in[40].flags
                );
                assert_eq!(
                    msg.sol_in[40].sensor_type, 133,
                    "incorrect value for sol_in[40].sensor_type, expected 133, is {}",
                    msg.sol_in[40].sensor_type
                );
                assert_eq!(
                    msg.sol_in[41].flags, 70,
                    "incorrect value for sol_in[41].flags, expected 70, is {}",
                    msg.sol_in[41].flags
                );
                assert_eq!(
                    msg.sol_in[41].sensor_type, 87,
                    "incorrect value for sol_in[41].sensor_type, expected 87, is {}",
                    msg.sol_in[41].sensor_type
                );
                assert_eq!(
                    msg.sol_in[42].flags, 108,
                    "incorrect value for sol_in[42].flags, expected 108, is {}",
                    msg.sol_in[42].flags
                );
                assert_eq!(
                    msg.sol_in[42].sensor_type, 2,
                    "incorrect value for sol_in[42].sensor_type, expected 2, is {}",
                    msg.sol_in[42].sensor_type
                );
                assert_eq!(
                    msg.sol_in[43].flags, 101,
                    "incorrect value for sol_in[43].flags, expected 101, is {}",
                    msg.sol_in[43].flags
                );
                assert_eq!(
                    msg.sol_in[43].sensor_type, 91,
                    "incorrect value for sol_in[43].sensor_type, expected 91, is {}",
                    msg.sol_in[43].sensor_type
                );
                assert_eq!(
                    msg.sol_in[44].flags, 55,
                    "incorrect value for sol_in[44].flags, expected 55, is {}",
                    msg.sol_in[44].flags
                );
                assert_eq!(
                    msg.sol_in[44].sensor_type, 200,
                    "incorrect value for sol_in[44].sensor_type, expected 200, is {}",
                    msg.sol_in[44].sensor_type
                );
                assert_eq!(
                    msg.sol_in[45].flags, 156,
                    "incorrect value for sol_in[45].flags, expected 156, is {}",
                    msg.sol_in[45].flags
                );
                assert_eq!(
                    msg.sol_in[45].sensor_type, 24,
                    "incorrect value for sol_in[45].sensor_type, expected 24, is {}",
                    msg.sol_in[45].sensor_type
                );
                assert_eq!(
                    msg.sol_in[46].flags, 73,
                    "incorrect value for sol_in[46].flags, expected 73, is {}",
                    msg.sol_in[46].flags
                );
                assert_eq!(
                    msg.sol_in[46].sensor_type, 233,
                    "incorrect value for sol_in[46].sensor_type, expected 233, is {}",
                    msg.sol_in[46].sensor_type
                );
                assert_eq!(
                    msg.sol_in[47].flags, 66,
                    "incorrect value for sol_in[47].flags, expected 66, is {}",
                    msg.sol_in[47].flags
                );
                assert_eq!(
                    msg.sol_in[47].sensor_type, 39,
                    "incorrect value for sol_in[47].sensor_type, expected 39, is {}",
                    msg.sol_in[47].sensor_type
                );
                assert_eq!(
                    msg.sol_in[48].flags, 140,
                    "incorrect value for sol_in[48].flags, expected 140, is {}",
                    msg.sol_in[48].flags
                );
                assert_eq!(
                    msg.sol_in[48].sensor_type, 97,
                    "incorrect value for sol_in[48].sensor_type, expected 97, is {}",
                    msg.sol_in[48].sensor_type
                );
                assert_eq!(
                    msg.sol_in[49].flags, 227,
                    "incorrect value for sol_in[49].flags, expected 227, is {}",
                    msg.sol_in[49].flags
                );
                assert_eq!(
                    msg.sol_in[49].sensor_type, 252,
                    "incorrect value for sol_in[49].sensor_type, expected 252, is {}",
                    msg.sol_in[49].sensor_type
                );
                assert_eq!(
                    msg.sol_in[50].flags, 237,
                    "incorrect value for sol_in[50].flags, expected 237, is {}",
                    msg.sol_in[50].flags
                );
                assert_eq!(
                    msg.sol_in[50].sensor_type, 230,
                    "incorrect value for sol_in[50].sensor_type, expected 230, is {}",
                    msg.sol_in[50].sensor_type
                );
                assert_eq!(
                    msg.sol_in[51].flags, 241,
                    "incorrect value for sol_in[51].flags, expected 241, is {}",
                    msg.sol_in[51].flags
                );
                assert_eq!(
                    msg.sol_in[51].sensor_type, 135,
                    "incorrect value for sol_in[51].sensor_type, expected 135, is {}",
                    msg.sol_in[51].sensor_type
                );
                assert_eq!(
                    msg.sol_in[52].flags, 205,
                    "incorrect value for sol_in[52].flags, expected 205, is {}",
                    msg.sol_in[52].flags
                );
                assert_eq!(
                    msg.sol_in[52].sensor_type, 245,
                    "incorrect value for sol_in[52].sensor_type, expected 245, is {}",
                    msg.sol_in[52].sensor_type
                );
                assert_eq!(
                    msg.sol_in[53].flags, 0,
                    "incorrect value for sol_in[53].flags, expected 0, is {}",
                    msg.sol_in[53].flags
                );
                assert_eq!(
                    msg.sol_in[53].sensor_type, 70,
                    "incorrect value for sol_in[53].sensor_type, expected 70, is {}",
                    msg.sol_in[53].sensor_type
                );
                assert_eq!(
                    msg.sol_in[54].flags, 188,
                    "incorrect value for sol_in[54].flags, expected 188, is {}",
                    msg.sol_in[54].flags
                );
                assert_eq!(
                    msg.sol_in[54].sensor_type, 219,
                    "incorrect value for sol_in[54].sensor_type, expected 219, is {}",
                    msg.sol_in[54].sensor_type
                );
                assert_eq!(
                    msg.sol_in[55].flags, 136,
                    "incorrect value for sol_in[55].flags, expected 136, is {}",
                    msg.sol_in[55].flags
                );
                assert_eq!(
                    msg.sol_in[55].sensor_type, 107,
                    "incorrect value for sol_in[55].sensor_type, expected 107, is {}",
                    msg.sol_in[55].sensor_type
                );
                assert_eq!(
                    msg.sol_in[56].flags, 58,
                    "incorrect value for sol_in[56].flags, expected 58, is {}",
                    msg.sol_in[56].flags
                );
                assert_eq!(
                    msg.sol_in[56].sensor_type, 178,
                    "incorrect value for sol_in[56].sensor_type, expected 178, is {}",
                    msg.sol_in[56].sensor_type
                );
                assert_eq!(
                    msg.sol_in[57].flags, 29,
                    "incorrect value for sol_in[57].flags, expected 29, is {}",
                    msg.sol_in[57].flags
                );
                assert_eq!(
                    msg.sol_in[57].sensor_type, 1,
                    "incorrect value for sol_in[57].sensor_type, expected 1, is {}",
                    msg.sol_in[57].sensor_type
                );
                assert_eq!(
                    msg.sol_in[58].flags, 213,
                    "incorrect value for sol_in[58].flags, expected 213, is {}",
                    msg.sol_in[58].flags
                );
                assert_eq!(
                    msg.sol_in[58].sensor_type, 44,
                    "incorrect value for sol_in[58].sensor_type, expected 44, is {}",
                    msg.sol_in[58].sensor_type
                );
                assert_eq!(
                    msg.sol_in[59].flags, 147,
                    "incorrect value for sol_in[59].flags, expected 147, is {}",
                    msg.sol_in[59].flags
                );
                assert_eq!(
                    msg.sol_in[59].sensor_type, 225,
                    "incorrect value for sol_in[59].sensor_type, expected 225, is {}",
                    msg.sol_in[59].sensor_type
                );
                assert_eq!(
                    msg.sol_in[60].flags, 96,
                    "incorrect value for sol_in[60].flags, expected 96, is {}",
                    msg.sol_in[60].flags
                );
                assert_eq!(
                    msg.sol_in[60].sensor_type, 190,
                    "incorrect value for sol_in[60].sensor_type, expected 190, is {}",
                    msg.sol_in[60].sensor_type
                );
                assert_eq!(
                    msg.sol_in[61].flags, 108,
                    "incorrect value for sol_in[61].flags, expected 108, is {}",
                    msg.sol_in[61].flags
                );
                assert_eq!(
                    msg.sol_in[61].sensor_type, 192,
                    "incorrect value for sol_in[61].sensor_type, expected 192, is {}",
                    msg.sol_in[61].sensor_type
                );
                assert_eq!(
                    msg.sol_in[62].flags, 15,
                    "incorrect value for sol_in[62].flags, expected 15, is {}",
                    msg.sol_in[62].flags
                );
                assert_eq!(
                    msg.sol_in[62].sensor_type, 228,
                    "incorrect value for sol_in[62].sensor_type, expected 228, is {}",
                    msg.sol_in[62].sensor_type
                );
                assert_eq!(
                    msg.sol_in[63].flags, 18,
                    "incorrect value for sol_in[63].flags, expected 18, is {}",
                    msg.sol_in[63].flags
                );
                assert_eq!(
                    msg.sol_in[63].sensor_type, 203,
                    "incorrect value for sol_in[63].sensor_type, expected 203, is {}",
                    msg.sol_in[63].sensor_type
                );
                assert_eq!(
                    msg.sol_in[64].flags, 222,
                    "incorrect value for sol_in[64].flags, expected 222, is {}",
                    msg.sol_in[64].flags
                );
                assert_eq!(
                    msg.sol_in[64].sensor_type, 3,
                    "incorrect value for sol_in[64].sensor_type, expected 3, is {}",
                    msg.sol_in[64].sensor_type
                );
                assert_eq!(
                    msg.sol_in[65].flags, 68,
                    "incorrect value for sol_in[65].flags, expected 68, is {}",
                    msg.sol_in[65].flags
                );
                assert_eq!(
                    msg.sol_in[65].sensor_type, 180,
                    "incorrect value for sol_in[65].sensor_type, expected 180, is {}",
                    msg.sol_in[65].sensor_type
                );
                assert_eq!(
                    msg.sol_in[66].flags, 229,
                    "incorrect value for sol_in[66].flags, expected 229, is {}",
                    msg.sol_in[66].flags
                );
                assert_eq!(
                    msg.sol_in[66].sensor_type, 101,
                    "incorrect value for sol_in[66].sensor_type, expected 101, is {}",
                    msg.sol_in[66].sensor_type
                );
                assert_eq!(
                    msg.sol_in[67].flags, 203,
                    "incorrect value for sol_in[67].flags, expected 203, is {}",
                    msg.sol_in[67].flags
                );
                assert_eq!(
                    msg.sol_in[67].sensor_type, 223,
                    "incorrect value for sol_in[67].sensor_type, expected 223, is {}",
                    msg.sol_in[67].sensor_type
                );
                assert_eq!(
                    msg.sol_in[68].flags, 164,
                    "incorrect value for sol_in[68].flags, expected 164, is {}",
                    msg.sol_in[68].flags
                );
                assert_eq!(
                    msg.sol_in[68].sensor_type, 243,
                    "incorrect value for sol_in[68].sensor_type, expected 243, is {}",
                    msg.sol_in[68].sensor_type
                );
                assert_eq!(
                    msg.sol_in[69].flags, 165,
                    "incorrect value for sol_in[69].flags, expected 165, is {}",
                    msg.sol_in[69].flags
                );
                assert_eq!(
                    msg.sol_in[69].sensor_type, 92,
                    "incorrect value for sol_in[69].sensor_type, expected 92, is {}",
                    msg.sol_in[69].sensor_type
                );
                assert_eq!(
                    msg.sol_in[70].flags, 159,
                    "incorrect value for sol_in[70].flags, expected 159, is {}",
                    msg.sol_in[70].flags
                );
                assert_eq!(
                    msg.sol_in[70].sensor_type, 220,
                    "incorrect value for sol_in[70].sensor_type, expected 220, is {}",
                    msg.sol_in[70].sensor_type
                );
                assert_eq!(
                    msg.sol_in[71].flags, 121,
                    "incorrect value for sol_in[71].flags, expected 121, is {}",
                    msg.sol_in[71].flags
                );
                assert_eq!(
                    msg.sol_in[71].sensor_type, 174,
                    "incorrect value for sol_in[71].sensor_type, expected 174, is {}",
                    msg.sol_in[71].sensor_type
                );
                assert_eq!(
                    msg.sol_in[72].flags, 167,
                    "incorrect value for sol_in[72].flags, expected 167, is {}",
                    msg.sol_in[72].flags
                );
                assert_eq!(
                    msg.sol_in[72].sensor_type, 112,
                    "incorrect value for sol_in[72].sensor_type, expected 112, is {}",
                    msg.sol_in[72].sensor_type
                );
                assert_eq!(
                    msg.sol_in[73].flags, 40,
                    "incorrect value for sol_in[73].flags, expected 40, is {}",
                    msg.sol_in[73].flags
                );
                assert_eq!(
                    msg.sol_in[73].sensor_type, 240,
                    "incorrect value for sol_in[73].sensor_type, expected 240, is {}",
                    msg.sol_in[73].sensor_type
                );
                assert_eq!(
                    msg.sol_in[74].flags, 3,
                    "incorrect value for sol_in[74].flags, expected 3, is {}",
                    msg.sol_in[74].flags
                );
                assert_eq!(
                    msg.sol_in[74].sensor_type, 59,
                    "incorrect value for sol_in[74].sensor_type, expected 59, is {}",
                    msg.sol_in[74].sensor_type
                );
                assert_eq!(
                    msg.sol_in[75].flags, 52,
                    "incorrect value for sol_in[75].flags, expected 52, is {}",
                    msg.sol_in[75].flags
                );
                assert_eq!(
                    msg.sol_in[75].sensor_type, 230,
                    "incorrect value for sol_in[75].sensor_type, expected 230, is {}",
                    msg.sol_in[75].sensor_type
                );
                assert_eq!(
                    msg.sol_in[76].flags, 148,
                    "incorrect value for sol_in[76].flags, expected 148, is {}",
                    msg.sol_in[76].flags
                );
                assert_eq!(
                    msg.sol_in[76].sensor_type, 149,
                    "incorrect value for sol_in[76].sensor_type, expected 149, is {}",
                    msg.sol_in[76].sensor_type
                );
                assert_eq!(
                    msg.sol_in[77].flags, 142,
                    "incorrect value for sol_in[77].flags, expected 142, is {}",
                    msg.sol_in[77].flags
                );
                assert_eq!(
                    msg.sol_in[77].sensor_type, 218,
                    "incorrect value for sol_in[77].sensor_type, expected 218, is {}",
                    msg.sol_in[77].sensor_type
                );
                assert_eq!(
                    msg.sol_in[78].flags, 109,
                    "incorrect value for sol_in[78].flags, expected 109, is {}",
                    msg.sol_in[78].flags
                );
                assert_eq!(
                    msg.sol_in[78].sensor_type, 212,
                    "incorrect value for sol_in[78].sensor_type, expected 212, is {}",
                    msg.sol_in[78].sensor_type
                );
                assert_eq!(
                    msg.sol_in[79].flags, 71,
                    "incorrect value for sol_in[79].flags, expected 71, is {}",
                    msg.sol_in[79].flags
                );
                assert_eq!(
                    msg.sol_in[79].sensor_type, 176,
                    "incorrect value for sol_in[79].sensor_type, expected 176, is {}",
                    msg.sol_in[79].sensor_type
                );
                assert_eq!(
                    msg.sol_in[80].flags, 172,
                    "incorrect value for sol_in[80].flags, expected 172, is {}",
                    msg.sol_in[80].flags
                );
                assert_eq!(
                    msg.sol_in[80].sensor_type, 179,
                    "incorrect value for sol_in[80].sensor_type, expected 179, is {}",
                    msg.sol_in[80].sensor_type
                );
                assert_eq!(
                    msg.sol_in[81].flags, 1,
                    "incorrect value for sol_in[81].flags, expected 1, is {}",
                    msg.sol_in[81].flags
                );
                assert_eq!(
                    msg.sol_in[81].sensor_type, 77,
                    "incorrect value for sol_in[81].sensor_type, expected 77, is {}",
                    msg.sol_in[81].sensor_type
                );
                assert_eq!(
                    msg.sol_in[82].flags, 70,
                    "incorrect value for sol_in[82].flags, expected 70, is {}",
                    msg.sol_in[82].flags
                );
                assert_eq!(
                    msg.sol_in[82].sensor_type, 193,
                    "incorrect value for sol_in[82].sensor_type, expected 193, is {}",
                    msg.sol_in[82].sensor_type
                );
                assert_eq!(
                    msg.sol_in[83].flags, 149,
                    "incorrect value for sol_in[83].flags, expected 149, is {}",
                    msg.sol_in[83].flags
                );
                assert_eq!(
                    msg.sol_in[83].sensor_type, 147,
                    "incorrect value for sol_in[83].sensor_type, expected 147, is {}",
                    msg.sol_in[83].sensor_type
                );
                assert_eq!(
                    msg.sol_in[84].flags, 144,
                    "incorrect value for sol_in[84].flags, expected 144, is {}",
                    msg.sol_in[84].flags
                );
                assert_eq!(
                    msg.sol_in[84].sensor_type, 23,
                    "incorrect value for sol_in[84].sensor_type, expected 23, is {}",
                    msg.sol_in[84].sensor_type
                );
                assert_eq!(
                    msg.sol_in[85].flags, 239,
                    "incorrect value for sol_in[85].flags, expected 239, is {}",
                    msg.sol_in[85].flags
                );
                assert_eq!(
                    msg.sol_in[85].sensor_type, 148,
                    "incorrect value for sol_in[85].sensor_type, expected 148, is {}",
                    msg.sol_in[85].sensor_type
                );
                assert_eq!(
                    msg.sol_in[86].flags, 186,
                    "incorrect value for sol_in[86].flags, expected 186, is {}",
                    msg.sol_in[86].flags
                );
                assert_eq!(
                    msg.sol_in[86].sensor_type, 195,
                    "incorrect value for sol_in[86].sensor_type, expected 195, is {}",
                    msg.sol_in[86].sensor_type
                );
                assert_eq!(
                    msg.sol_in[87].flags, 30,
                    "incorrect value for sol_in[87].flags, expected 30, is {}",
                    msg.sol_in[87].flags
                );
                assert_eq!(
                    msg.sol_in[87].sensor_type, 86,
                    "incorrect value for sol_in[87].sensor_type, expected 86, is {}",
                    msg.sol_in[87].sensor_type
                );
                assert_eq!(
                    msg.sol_in[88].flags, 143,
                    "incorrect value for sol_in[88].flags, expected 143, is {}",
                    msg.sol_in[88].flags
                );
                assert_eq!(
                    msg.sol_in[88].sensor_type, 34,
                    "incorrect value for sol_in[88].sensor_type, expected 34, is {}",
                    msg.sol_in[88].sensor_type
                );
                assert_eq!(
                    msg.sol_in[89].flags, 207,
                    "incorrect value for sol_in[89].flags, expected 207, is {}",
                    msg.sol_in[89].flags
                );
                assert_eq!(
                    msg.sol_in[89].sensor_type, 156,
                    "incorrect value for sol_in[89].sensor_type, expected 156, is {}",
                    msg.sol_in[89].sensor_type
                );
                assert_eq!(
                    msg.sol_in[90].flags, 55,
                    "incorrect value for sol_in[90].flags, expected 55, is {}",
                    msg.sol_in[90].flags
                );
                assert_eq!(
                    msg.sol_in[90].sensor_type, 63,
                    "incorrect value for sol_in[90].sensor_type, expected 63, is {}",
                    msg.sol_in[90].sensor_type
                );
                assert_eq!(
                    msg.sol_in[91].flags, 255,
                    "incorrect value for sol_in[91].flags, expected 255, is {}",
                    msg.sol_in[91].flags
                );
                assert_eq!(
                    msg.sol_in[91].sensor_type, 117,
                    "incorrect value for sol_in[91].sensor_type, expected 117, is {}",
                    msg.sol_in[91].sensor_type
                );
                assert_eq!(
                    msg.sol_in[92].flags, 222,
                    "incorrect value for sol_in[92].flags, expected 222, is {}",
                    msg.sol_in[92].flags
                );
                assert_eq!(
                    msg.sol_in[92].sensor_type, 222,
                    "incorrect value for sol_in[92].sensor_type, expected 222, is {}",
                    msg.sol_in[92].sensor_type
                );
                assert_eq!(
                    msg.sol_in[93].flags, 145,
                    "incorrect value for sol_in[93].flags, expected 145, is {}",
                    msg.sol_in[93].flags
                );
                assert_eq!(
                    msg.sol_in[93].sensor_type, 219,
                    "incorrect value for sol_in[93].sensor_type, expected 219, is {}",
                    msg.sol_in[93].sensor_type
                );
                assert_eq!(
                    msg.sol_in[94].flags, 191,
                    "incorrect value for sol_in[94].flags, expected 191, is {}",
                    msg.sol_in[94].flags
                );
                assert_eq!(
                    msg.sol_in[94].sensor_type, 224,
                    "incorrect value for sol_in[94].sensor_type, expected 224, is {}",
                    msg.sol_in[94].sensor_type
                );
                assert_eq!(
                    msg.sol_in[95].flags, 109,
                    "incorrect value for sol_in[95].flags, expected 109, is {}",
                    msg.sol_in[95].flags
                );
                assert_eq!(
                    msg.sol_in[95].sensor_type, 210,
                    "incorrect value for sol_in[95].sensor_type, expected 210, is {}",
                    msg.sol_in[95].sensor_type
                );
                assert_eq!(
                    msg.sol_in[96].flags, 153,
                    "incorrect value for sol_in[96].flags, expected 153, is {}",
                    msg.sol_in[96].flags
                );
                assert_eq!(
                    msg.sol_in[96].sensor_type, 86,
                    "incorrect value for sol_in[96].sensor_type, expected 86, is {}",
                    msg.sol_in[96].sensor_type
                );
                assert_eq!(
                    msg.sol_in[97].flags, 32,
                    "incorrect value for sol_in[97].flags, expected 32, is {}",
                    msg.sol_in[97].flags
                );
                assert_eq!(
                    msg.sol_in[97].sensor_type, 21,
                    "incorrect value for sol_in[97].sensor_type, expected 21, is {}",
                    msg.sol_in[97].sensor_type
                );
                assert_eq!(
                    msg.sol_in[98].flags, 10,
                    "incorrect value for sol_in[98].flags, expected 10, is {}",
                    msg.sol_in[98].flags
                );
                assert_eq!(
                    msg.sol_in[98].sensor_type, 226,
                    "incorrect value for sol_in[98].sensor_type, expected 226, is {}",
                    msg.sol_in[98].sensor_type
                );
                assert_eq!(
                    msg.sol_in[99].flags, 63,
                    "incorrect value for sol_in[99].flags, expected 63, is {}",
                    msg.sol_in[99].flags
                );
                assert_eq!(
                    msg.sol_in[99].sensor_type, 60,
                    "incorrect value for sol_in[99].sensor_type, expected 60, is {}",
                    msg.sol_in[99].sensor_type
                );
                assert_eq!(
                    msg.sol_in[100].flags, 236,
                    "incorrect value for sol_in[100].flags, expected 236, is {}",
                    msg.sol_in[100].flags
                );
                assert_eq!(
                    msg.sol_in[100].sensor_type, 106,
                    "incorrect value for sol_in[100].sensor_type, expected 106, is {}",
                    msg.sol_in[100].sensor_type
                );
                assert_eq!(
                    msg.sol_in[101].flags, 96,
                    "incorrect value for sol_in[101].flags, expected 96, is {}",
                    msg.sol_in[101].flags
                );
                assert_eq!(
                    msg.sol_in[101].sensor_type, 93,
                    "incorrect value for sol_in[101].sensor_type, expected 93, is {}",
                    msg.sol_in[101].sensor_type
                );
                assert_eq!(
                    msg.sol_in[102].flags, 163,
                    "incorrect value for sol_in[102].flags, expected 163, is {}",
                    msg.sol_in[102].flags
                );
                assert_eq!(
                    msg.sol_in[102].sensor_type, 30,
                    "incorrect value for sol_in[102].sensor_type, expected 30, is {}",
                    msg.sol_in[102].sensor_type
                );
                assert_eq!(
                    msg.sol_in[103].flags, 238,
                    "incorrect value for sol_in[103].flags, expected 238, is {}",
                    msg.sol_in[103].flags
                );
                assert_eq!(
                    msg.sol_in[103].sensor_type, 106,
                    "incorrect value for sol_in[103].sensor_type, expected 106, is {}",
                    msg.sol_in[103].sensor_type
                );
                assert_eq!(
                    msg.sol_in[104].flags, 133,
                    "incorrect value for sol_in[104].flags, expected 133, is {}",
                    msg.sol_in[104].flags
                );
                assert_eq!(
                    msg.sol_in[104].sensor_type, 147,
                    "incorrect value for sol_in[104].sensor_type, expected 147, is {}",
                    msg.sol_in[104].sensor_type
                );
                assert_eq!(
                    msg.sol_in[105].flags, 107,
                    "incorrect value for sol_in[105].flags, expected 107, is {}",
                    msg.sol_in[105].flags
                );
                assert_eq!(
                    msg.sol_in[105].sensor_type, 132,
                    "incorrect value for sol_in[105].sensor_type, expected 132, is {}",
                    msg.sol_in[105].sensor_type
                );
                assert_eq!(
                    msg.sol_in[106].flags, 214,
                    "incorrect value for sol_in[106].flags, expected 214, is {}",
                    msg.sol_in[106].flags
                );
                assert_eq!(
                    msg.sol_in[106].sensor_type, 152,
                    "incorrect value for sol_in[106].sensor_type, expected 152, is {}",
                    msg.sol_in[106].sensor_type
                );
                assert_eq!(
                    msg.sol_in[107].flags, 185,
                    "incorrect value for sol_in[107].flags, expected 185, is {}",
                    msg.sol_in[107].flags
                );
                assert_eq!(
                    msg.sol_in[107].sensor_type, 221,
                    "incorrect value for sol_in[107].sensor_type, expected 221, is {}",
                    msg.sol_in[107].sensor_type
                );
                assert_eq!(
                    msg.sol_in[108].flags, 21,
                    "incorrect value for sol_in[108].flags, expected 21, is {}",
                    msg.sol_in[108].flags
                );
                assert_eq!(
                    msg.sol_in[108].sensor_type, 202,
                    "incorrect value for sol_in[108].sensor_type, expected 202, is {}",
                    msg.sol_in[108].sensor_type
                );
                assert_eq!(
                    msg.sol_in[109].flags, 51,
                    "incorrect value for sol_in[109].flags, expected 51, is {}",
                    msg.sol_in[109].flags
                );
                assert_eq!(
                    msg.sol_in[109].sensor_type, 252,
                    "incorrect value for sol_in[109].sensor_type, expected 252, is {}",
                    msg.sol_in[109].sensor_type
                );
                assert_eq!(
                    msg.sol_in[110].flags, 59,
                    "incorrect value for sol_in[110].flags, expected 59, is {}",
                    msg.sol_in[110].flags
                );
                assert_eq!(
                    msg.sol_in[110].sensor_type, 130,
                    "incorrect value for sol_in[110].sensor_type, expected 130, is {}",
                    msg.sol_in[110].sensor_type
                );
                assert_eq!(
                    msg.sol_in[111].flags, 202,
                    "incorrect value for sol_in[111].flags, expected 202, is {}",
                    msg.sol_in[111].flags
                );
                assert_eq!(
                    msg.sol_in[111].sensor_type, 166,
                    "incorrect value for sol_in[111].sensor_type, expected 166, is {}",
                    msg.sol_in[111].sensor_type
                );
                assert_eq!(
                    msg.sol_in[112].flags, 170,
                    "incorrect value for sol_in[112].flags, expected 170, is {}",
                    msg.sol_in[112].flags
                );
                assert_eq!(
                    msg.sol_in[112].sensor_type, 127,
                    "incorrect value for sol_in[112].sensor_type, expected 127, is {}",
                    msg.sol_in[112].sensor_type
                );
                assert_eq!(
                    msg.sol_in[113].flags, 193,
                    "incorrect value for sol_in[113].flags, expected 193, is {}",
                    msg.sol_in[113].flags
                );
                assert_eq!(
                    msg.sol_in[113].sensor_type, 58,
                    "incorrect value for sol_in[113].sensor_type, expected 58, is {}",
                    msg.sol_in[113].sensor_type
                );
                assert_eq!(
                    msg.sol_in[114].flags, 125,
                    "incorrect value for sol_in[114].flags, expected 125, is {}",
                    msg.sol_in[114].flags
                );
                assert_eq!(
                    msg.sol_in[114].sensor_type, 215,
                    "incorrect value for sol_in[114].sensor_type, expected 215, is {}",
                    msg.sol_in[114].sensor_type
                );
                assert_eq!(
                    msg.sol_in[115].flags, 58,
                    "incorrect value for sol_in[115].flags, expected 58, is {}",
                    msg.sol_in[115].flags
                );
                assert_eq!(
                    msg.sol_in[115].sensor_type, 22,
                    "incorrect value for sol_in[115].sensor_type, expected 22, is {}",
                    msg.sol_in[115].sensor_type
                );
                assert_eq!(
                    msg.sol_in[116].flags, 47,
                    "incorrect value for sol_in[116].flags, expected 47, is {}",
                    msg.sol_in[116].flags
                );
                assert_eq!(
                    msg.sol_in[116].sensor_type, 135,
                    "incorrect value for sol_in[116].sensor_type, expected 135, is {}",
                    msg.sol_in[116].sensor_type
                );
                assert_eq!(
                    msg.sol_in[117].flags, 142,
                    "incorrect value for sol_in[117].flags, expected 142, is {}",
                    msg.sol_in[117].flags
                );
                assert_eq!(
                    msg.sol_in[117].sensor_type, 88,
                    "incorrect value for sol_in[117].sensor_type, expected 88, is {}",
                    msg.sol_in[117].sensor_type
                );
                assert_eq!(
                    msg.vdop, 41989,
                    "incorrect value for vdop, expected 41989, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSolnMetaDepA"),
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
fn test_json2sbp_auto_check_sbp_solution_meta_msg_soln_meta_dep_a() {
    {
        let json_input = r#"{"crc":54093,"length":254,"msg_type":65295,"payload":"t96deQWk7h++c107ZyRToZwu/UNXyCf69fLkSBLeC1jP2ucN4uAWxBXyDFlH27ZVkcySKMwzFZnjLA8c/yfN2PC+XdtnKim2TN4RF30fEuUcL9YZZFRqSDAK3ujrSW2jM5iF61dGAmxbZcg3GJzpSSdCYYz84+bth/H1zUYA27xriLI6AR0s1eGTvmDAbOQPyxID3rREZeXfy/OkXKXcn655cKfwKDsD5jSVlNqO1G2wR7OsTQHBRpOVF5CU78O6Vh4ij5zPPzd1/97e25Hgv9JtVpkVIOIKPD9q7F1gHqNq7pOFhGuY1t25yhX8M4I7psp/qjrB130WOocvWI4=","preamble":85,"sender":61780,"pdop":57015,"hdop":31133,"vdop":41989,"n_sats":238,"age_corrections":48671,"alignment_status":115,"last_used_gnss_pos_tow":610745181,"last_used_gnss_vel_tow":782016851,"sol_in":[{"sensor_type":253,"flags":67},{"sensor_type":87,"flags":200},{"sensor_type":39,"flags":250},{"sensor_type":245,"flags":242},{"sensor_type":228,"flags":72},{"sensor_type":18,"flags":222},{"sensor_type":11,"flags":88},{"sensor_type":207,"flags":218},{"sensor_type":231,"flags":13},{"sensor_type":226,"flags":224},{"sensor_type":22,"flags":196},{"sensor_type":21,"flags":242},{"sensor_type":12,"flags":89},{"sensor_type":71,"flags":219},{"sensor_type":182,"flags":85},{"sensor_type":145,"flags":204},{"sensor_type":146,"flags":40},{"sensor_type":204,"flags":51},{"sensor_type":21,"flags":153},{"sensor_type":227,"flags":44},{"sensor_type":15,"flags":28},{"sensor_type":255,"flags":39},{"sensor_type":205,"flags":216},{"sensor_type":240,"flags":190},{"sensor_type":93,"flags":219},{"sensor_type":103,"flags":42},{"sensor_type":41,"flags":182},{"sensor_type":76,"flags":222},{"sensor_type":17,"flags":23},{"sensor_type":125,"flags":31},{"sensor_type":18,"flags":229},{"sensor_type":28,"flags":47},{"sensor_type":214,"flags":25},{"sensor_type":100,"flags":84},{"sensor_type":106,"flags":72},{"sensor_type":48,"flags":10},{"sensor_type":222,"flags":232},{"sensor_type":235,"flags":73},{"sensor_type":109,"flags":163},{"sensor_type":51,"flags":152},{"sensor_type":133,"flags":235},{"sensor_type":87,"flags":70},{"sensor_type":2,"flags":108},{"sensor_type":91,"flags":101},{"sensor_type":200,"flags":55},{"sensor_type":24,"flags":156},{"sensor_type":233,"flags":73},{"sensor_type":39,"flags":66},{"sensor_type":97,"flags":140},{"sensor_type":252,"flags":227},{"sensor_type":230,"flags":237},{"sensor_type":135,"flags":241},{"sensor_type":245,"flags":205},{"sensor_type":70,"flags":0},{"sensor_type":219,"flags":188},{"sensor_type":107,"flags":136},{"sensor_type":178,"flags":58},{"sensor_type":1,"flags":29},{"sensor_type":44,"flags":213},{"sensor_type":225,"flags":147},{"sensor_type":190,"flags":96},{"sensor_type":192,"flags":108},{"sensor_type":228,"flags":15},{"sensor_type":203,"flags":18},{"sensor_type":3,"flags":222},{"sensor_type":180,"flags":68},{"sensor_type":101,"flags":229},{"sensor_type":223,"flags":203},{"sensor_type":243,"flags":164},{"sensor_type":92,"flags":165},{"sensor_type":220,"flags":159},{"sensor_type":174,"flags":121},{"sensor_type":112,"flags":167},{"sensor_type":240,"flags":40},{"sensor_type":59,"flags":3},{"sensor_type":230,"flags":52},{"sensor_type":149,"flags":148},{"sensor_type":218,"flags":142},{"sensor_type":212,"flags":109},{"sensor_type":176,"flags":71},{"sensor_type":179,"flags":172},{"sensor_type":77,"flags":1},{"sensor_type":193,"flags":70},{"sensor_type":147,"flags":149},{"sensor_type":23,"flags":144},{"sensor_type":148,"flags":239},{"sensor_type":195,"flags":186},{"sensor_type":86,"flags":30},{"sensor_type":34,"flags":143},{"sensor_type":156,"flags":207},{"sensor_type":63,"flags":55},{"sensor_type":117,"flags":255},{"sensor_type":222,"flags":222},{"sensor_type":219,"flags":145},{"sensor_type":224,"flags":191},{"sensor_type":210,"flags":109},{"sensor_type":86,"flags":153},{"sensor_type":21,"flags":32},{"sensor_type":226,"flags":10},{"sensor_type":60,"flags":63},{"sensor_type":106,"flags":236},{"sensor_type":93,"flags":96},{"sensor_type":30,"flags":163},{"sensor_type":106,"flags":238},{"sensor_type":147,"flags":133},{"sensor_type":132,"flags":107},{"sensor_type":152,"flags":214},{"sensor_type":221,"flags":185},{"sensor_type":202,"flags":21},{"sensor_type":252,"flags":51},{"sensor_type":130,"flags":59},{"sensor_type":166,"flags":202},{"sensor_type":127,"flags":170},{"sensor_type":58,"flags":193},{"sensor_type":215,"flags":125},{"sensor_type":22,"flags":58},{"sensor_type":135,"flags":47},{"sensor_type":88,"flags":142}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSolnMetaDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff0f,
                    "Incorrect message type, expected 0xff0f, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf154,
                    "incorrect sender id, expected 0xf154, is {sender_id}"
                );
                assert_eq!(
                    msg.age_corrections, 48671,
                    "incorrect value for age_corrections, expected 48671, is {}",
                    msg.age_corrections
                );
                assert_eq!(
                    msg.alignment_status, 115,
                    "incorrect value for alignment_status, expected 115, is {}",
                    msg.alignment_status
                );
                assert_eq!(
                    msg.hdop, 31133,
                    "incorrect value for hdop, expected 31133, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.last_used_gnss_pos_tow, 610745181,
                    "incorrect value for last_used_gnss_pos_tow, expected 610745181, is {}",
                    msg.last_used_gnss_pos_tow
                );
                assert_eq!(
                    msg.last_used_gnss_vel_tow, 782016851,
                    "incorrect value for last_used_gnss_vel_tow, expected 782016851, is {}",
                    msg.last_used_gnss_vel_tow
                );
                assert_eq!(
                    msg.n_sats, 238,
                    "incorrect value for n_sats, expected 238, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.pdop, 57015,
                    "incorrect value for pdop, expected 57015, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.sol_in[0].flags, 67,
                    "incorrect value for sol_in[0].flags, expected 67, is {}",
                    msg.sol_in[0].flags
                );
                assert_eq!(
                    msg.sol_in[0].sensor_type, 253,
                    "incorrect value for sol_in[0].sensor_type, expected 253, is {}",
                    msg.sol_in[0].sensor_type
                );
                assert_eq!(
                    msg.sol_in[1].flags, 200,
                    "incorrect value for sol_in[1].flags, expected 200, is {}",
                    msg.sol_in[1].flags
                );
                assert_eq!(
                    msg.sol_in[1].sensor_type, 87,
                    "incorrect value for sol_in[1].sensor_type, expected 87, is {}",
                    msg.sol_in[1].sensor_type
                );
                assert_eq!(
                    msg.sol_in[2].flags, 250,
                    "incorrect value for sol_in[2].flags, expected 250, is {}",
                    msg.sol_in[2].flags
                );
                assert_eq!(
                    msg.sol_in[2].sensor_type, 39,
                    "incorrect value for sol_in[2].sensor_type, expected 39, is {}",
                    msg.sol_in[2].sensor_type
                );
                assert_eq!(
                    msg.sol_in[3].flags, 242,
                    "incorrect value for sol_in[3].flags, expected 242, is {}",
                    msg.sol_in[3].flags
                );
                assert_eq!(
                    msg.sol_in[3].sensor_type, 245,
                    "incorrect value for sol_in[3].sensor_type, expected 245, is {}",
                    msg.sol_in[3].sensor_type
                );
                assert_eq!(
                    msg.sol_in[4].flags, 72,
                    "incorrect value for sol_in[4].flags, expected 72, is {}",
                    msg.sol_in[4].flags
                );
                assert_eq!(
                    msg.sol_in[4].sensor_type, 228,
                    "incorrect value for sol_in[4].sensor_type, expected 228, is {}",
                    msg.sol_in[4].sensor_type
                );
                assert_eq!(
                    msg.sol_in[5].flags, 222,
                    "incorrect value for sol_in[5].flags, expected 222, is {}",
                    msg.sol_in[5].flags
                );
                assert_eq!(
                    msg.sol_in[5].sensor_type, 18,
                    "incorrect value for sol_in[5].sensor_type, expected 18, is {}",
                    msg.sol_in[5].sensor_type
                );
                assert_eq!(
                    msg.sol_in[6].flags, 88,
                    "incorrect value for sol_in[6].flags, expected 88, is {}",
                    msg.sol_in[6].flags
                );
                assert_eq!(
                    msg.sol_in[6].sensor_type, 11,
                    "incorrect value for sol_in[6].sensor_type, expected 11, is {}",
                    msg.sol_in[6].sensor_type
                );
                assert_eq!(
                    msg.sol_in[7].flags, 218,
                    "incorrect value for sol_in[7].flags, expected 218, is {}",
                    msg.sol_in[7].flags
                );
                assert_eq!(
                    msg.sol_in[7].sensor_type, 207,
                    "incorrect value for sol_in[7].sensor_type, expected 207, is {}",
                    msg.sol_in[7].sensor_type
                );
                assert_eq!(
                    msg.sol_in[8].flags, 13,
                    "incorrect value for sol_in[8].flags, expected 13, is {}",
                    msg.sol_in[8].flags
                );
                assert_eq!(
                    msg.sol_in[8].sensor_type, 231,
                    "incorrect value for sol_in[8].sensor_type, expected 231, is {}",
                    msg.sol_in[8].sensor_type
                );
                assert_eq!(
                    msg.sol_in[9].flags, 224,
                    "incorrect value for sol_in[9].flags, expected 224, is {}",
                    msg.sol_in[9].flags
                );
                assert_eq!(
                    msg.sol_in[9].sensor_type, 226,
                    "incorrect value for sol_in[9].sensor_type, expected 226, is {}",
                    msg.sol_in[9].sensor_type
                );
                assert_eq!(
                    msg.sol_in[10].flags, 196,
                    "incorrect value for sol_in[10].flags, expected 196, is {}",
                    msg.sol_in[10].flags
                );
                assert_eq!(
                    msg.sol_in[10].sensor_type, 22,
                    "incorrect value for sol_in[10].sensor_type, expected 22, is {}",
                    msg.sol_in[10].sensor_type
                );
                assert_eq!(
                    msg.sol_in[11].flags, 242,
                    "incorrect value for sol_in[11].flags, expected 242, is {}",
                    msg.sol_in[11].flags
                );
                assert_eq!(
                    msg.sol_in[11].sensor_type, 21,
                    "incorrect value for sol_in[11].sensor_type, expected 21, is {}",
                    msg.sol_in[11].sensor_type
                );
                assert_eq!(
                    msg.sol_in[12].flags, 89,
                    "incorrect value for sol_in[12].flags, expected 89, is {}",
                    msg.sol_in[12].flags
                );
                assert_eq!(
                    msg.sol_in[12].sensor_type, 12,
                    "incorrect value for sol_in[12].sensor_type, expected 12, is {}",
                    msg.sol_in[12].sensor_type
                );
                assert_eq!(
                    msg.sol_in[13].flags, 219,
                    "incorrect value for sol_in[13].flags, expected 219, is {}",
                    msg.sol_in[13].flags
                );
                assert_eq!(
                    msg.sol_in[13].sensor_type, 71,
                    "incorrect value for sol_in[13].sensor_type, expected 71, is {}",
                    msg.sol_in[13].sensor_type
                );
                assert_eq!(
                    msg.sol_in[14].flags, 85,
                    "incorrect value for sol_in[14].flags, expected 85, is {}",
                    msg.sol_in[14].flags
                );
                assert_eq!(
                    msg.sol_in[14].sensor_type, 182,
                    "incorrect value for sol_in[14].sensor_type, expected 182, is {}",
                    msg.sol_in[14].sensor_type
                );
                assert_eq!(
                    msg.sol_in[15].flags, 204,
                    "incorrect value for sol_in[15].flags, expected 204, is {}",
                    msg.sol_in[15].flags
                );
                assert_eq!(
                    msg.sol_in[15].sensor_type, 145,
                    "incorrect value for sol_in[15].sensor_type, expected 145, is {}",
                    msg.sol_in[15].sensor_type
                );
                assert_eq!(
                    msg.sol_in[16].flags, 40,
                    "incorrect value for sol_in[16].flags, expected 40, is {}",
                    msg.sol_in[16].flags
                );
                assert_eq!(
                    msg.sol_in[16].sensor_type, 146,
                    "incorrect value for sol_in[16].sensor_type, expected 146, is {}",
                    msg.sol_in[16].sensor_type
                );
                assert_eq!(
                    msg.sol_in[17].flags, 51,
                    "incorrect value for sol_in[17].flags, expected 51, is {}",
                    msg.sol_in[17].flags
                );
                assert_eq!(
                    msg.sol_in[17].sensor_type, 204,
                    "incorrect value for sol_in[17].sensor_type, expected 204, is {}",
                    msg.sol_in[17].sensor_type
                );
                assert_eq!(
                    msg.sol_in[18].flags, 153,
                    "incorrect value for sol_in[18].flags, expected 153, is {}",
                    msg.sol_in[18].flags
                );
                assert_eq!(
                    msg.sol_in[18].sensor_type, 21,
                    "incorrect value for sol_in[18].sensor_type, expected 21, is {}",
                    msg.sol_in[18].sensor_type
                );
                assert_eq!(
                    msg.sol_in[19].flags, 44,
                    "incorrect value for sol_in[19].flags, expected 44, is {}",
                    msg.sol_in[19].flags
                );
                assert_eq!(
                    msg.sol_in[19].sensor_type, 227,
                    "incorrect value for sol_in[19].sensor_type, expected 227, is {}",
                    msg.sol_in[19].sensor_type
                );
                assert_eq!(
                    msg.sol_in[20].flags, 28,
                    "incorrect value for sol_in[20].flags, expected 28, is {}",
                    msg.sol_in[20].flags
                );
                assert_eq!(
                    msg.sol_in[20].sensor_type, 15,
                    "incorrect value for sol_in[20].sensor_type, expected 15, is {}",
                    msg.sol_in[20].sensor_type
                );
                assert_eq!(
                    msg.sol_in[21].flags, 39,
                    "incorrect value for sol_in[21].flags, expected 39, is {}",
                    msg.sol_in[21].flags
                );
                assert_eq!(
                    msg.sol_in[21].sensor_type, 255,
                    "incorrect value for sol_in[21].sensor_type, expected 255, is {}",
                    msg.sol_in[21].sensor_type
                );
                assert_eq!(
                    msg.sol_in[22].flags, 216,
                    "incorrect value for sol_in[22].flags, expected 216, is {}",
                    msg.sol_in[22].flags
                );
                assert_eq!(
                    msg.sol_in[22].sensor_type, 205,
                    "incorrect value for sol_in[22].sensor_type, expected 205, is {}",
                    msg.sol_in[22].sensor_type
                );
                assert_eq!(
                    msg.sol_in[23].flags, 190,
                    "incorrect value for sol_in[23].flags, expected 190, is {}",
                    msg.sol_in[23].flags
                );
                assert_eq!(
                    msg.sol_in[23].sensor_type, 240,
                    "incorrect value for sol_in[23].sensor_type, expected 240, is {}",
                    msg.sol_in[23].sensor_type
                );
                assert_eq!(
                    msg.sol_in[24].flags, 219,
                    "incorrect value for sol_in[24].flags, expected 219, is {}",
                    msg.sol_in[24].flags
                );
                assert_eq!(
                    msg.sol_in[24].sensor_type, 93,
                    "incorrect value for sol_in[24].sensor_type, expected 93, is {}",
                    msg.sol_in[24].sensor_type
                );
                assert_eq!(
                    msg.sol_in[25].flags, 42,
                    "incorrect value for sol_in[25].flags, expected 42, is {}",
                    msg.sol_in[25].flags
                );
                assert_eq!(
                    msg.sol_in[25].sensor_type, 103,
                    "incorrect value for sol_in[25].sensor_type, expected 103, is {}",
                    msg.sol_in[25].sensor_type
                );
                assert_eq!(
                    msg.sol_in[26].flags, 182,
                    "incorrect value for sol_in[26].flags, expected 182, is {}",
                    msg.sol_in[26].flags
                );
                assert_eq!(
                    msg.sol_in[26].sensor_type, 41,
                    "incorrect value for sol_in[26].sensor_type, expected 41, is {}",
                    msg.sol_in[26].sensor_type
                );
                assert_eq!(
                    msg.sol_in[27].flags, 222,
                    "incorrect value for sol_in[27].flags, expected 222, is {}",
                    msg.sol_in[27].flags
                );
                assert_eq!(
                    msg.sol_in[27].sensor_type, 76,
                    "incorrect value for sol_in[27].sensor_type, expected 76, is {}",
                    msg.sol_in[27].sensor_type
                );
                assert_eq!(
                    msg.sol_in[28].flags, 23,
                    "incorrect value for sol_in[28].flags, expected 23, is {}",
                    msg.sol_in[28].flags
                );
                assert_eq!(
                    msg.sol_in[28].sensor_type, 17,
                    "incorrect value for sol_in[28].sensor_type, expected 17, is {}",
                    msg.sol_in[28].sensor_type
                );
                assert_eq!(
                    msg.sol_in[29].flags, 31,
                    "incorrect value for sol_in[29].flags, expected 31, is {}",
                    msg.sol_in[29].flags
                );
                assert_eq!(
                    msg.sol_in[29].sensor_type, 125,
                    "incorrect value for sol_in[29].sensor_type, expected 125, is {}",
                    msg.sol_in[29].sensor_type
                );
                assert_eq!(
                    msg.sol_in[30].flags, 229,
                    "incorrect value for sol_in[30].flags, expected 229, is {}",
                    msg.sol_in[30].flags
                );
                assert_eq!(
                    msg.sol_in[30].sensor_type, 18,
                    "incorrect value for sol_in[30].sensor_type, expected 18, is {}",
                    msg.sol_in[30].sensor_type
                );
                assert_eq!(
                    msg.sol_in[31].flags, 47,
                    "incorrect value for sol_in[31].flags, expected 47, is {}",
                    msg.sol_in[31].flags
                );
                assert_eq!(
                    msg.sol_in[31].sensor_type, 28,
                    "incorrect value for sol_in[31].sensor_type, expected 28, is {}",
                    msg.sol_in[31].sensor_type
                );
                assert_eq!(
                    msg.sol_in[32].flags, 25,
                    "incorrect value for sol_in[32].flags, expected 25, is {}",
                    msg.sol_in[32].flags
                );
                assert_eq!(
                    msg.sol_in[32].sensor_type, 214,
                    "incorrect value for sol_in[32].sensor_type, expected 214, is {}",
                    msg.sol_in[32].sensor_type
                );
                assert_eq!(
                    msg.sol_in[33].flags, 84,
                    "incorrect value for sol_in[33].flags, expected 84, is {}",
                    msg.sol_in[33].flags
                );
                assert_eq!(
                    msg.sol_in[33].sensor_type, 100,
                    "incorrect value for sol_in[33].sensor_type, expected 100, is {}",
                    msg.sol_in[33].sensor_type
                );
                assert_eq!(
                    msg.sol_in[34].flags, 72,
                    "incorrect value for sol_in[34].flags, expected 72, is {}",
                    msg.sol_in[34].flags
                );
                assert_eq!(
                    msg.sol_in[34].sensor_type, 106,
                    "incorrect value for sol_in[34].sensor_type, expected 106, is {}",
                    msg.sol_in[34].sensor_type
                );
                assert_eq!(
                    msg.sol_in[35].flags, 10,
                    "incorrect value for sol_in[35].flags, expected 10, is {}",
                    msg.sol_in[35].flags
                );
                assert_eq!(
                    msg.sol_in[35].sensor_type, 48,
                    "incorrect value for sol_in[35].sensor_type, expected 48, is {}",
                    msg.sol_in[35].sensor_type
                );
                assert_eq!(
                    msg.sol_in[36].flags, 232,
                    "incorrect value for sol_in[36].flags, expected 232, is {}",
                    msg.sol_in[36].flags
                );
                assert_eq!(
                    msg.sol_in[36].sensor_type, 222,
                    "incorrect value for sol_in[36].sensor_type, expected 222, is {}",
                    msg.sol_in[36].sensor_type
                );
                assert_eq!(
                    msg.sol_in[37].flags, 73,
                    "incorrect value for sol_in[37].flags, expected 73, is {}",
                    msg.sol_in[37].flags
                );
                assert_eq!(
                    msg.sol_in[37].sensor_type, 235,
                    "incorrect value for sol_in[37].sensor_type, expected 235, is {}",
                    msg.sol_in[37].sensor_type
                );
                assert_eq!(
                    msg.sol_in[38].flags, 163,
                    "incorrect value for sol_in[38].flags, expected 163, is {}",
                    msg.sol_in[38].flags
                );
                assert_eq!(
                    msg.sol_in[38].sensor_type, 109,
                    "incorrect value for sol_in[38].sensor_type, expected 109, is {}",
                    msg.sol_in[38].sensor_type
                );
                assert_eq!(
                    msg.sol_in[39].flags, 152,
                    "incorrect value for sol_in[39].flags, expected 152, is {}",
                    msg.sol_in[39].flags
                );
                assert_eq!(
                    msg.sol_in[39].sensor_type, 51,
                    "incorrect value for sol_in[39].sensor_type, expected 51, is {}",
                    msg.sol_in[39].sensor_type
                );
                assert_eq!(
                    msg.sol_in[40].flags, 235,
                    "incorrect value for sol_in[40].flags, expected 235, is {}",
                    msg.sol_in[40].flags
                );
                assert_eq!(
                    msg.sol_in[40].sensor_type, 133,
                    "incorrect value for sol_in[40].sensor_type, expected 133, is {}",
                    msg.sol_in[40].sensor_type
                );
                assert_eq!(
                    msg.sol_in[41].flags, 70,
                    "incorrect value for sol_in[41].flags, expected 70, is {}",
                    msg.sol_in[41].flags
                );
                assert_eq!(
                    msg.sol_in[41].sensor_type, 87,
                    "incorrect value for sol_in[41].sensor_type, expected 87, is {}",
                    msg.sol_in[41].sensor_type
                );
                assert_eq!(
                    msg.sol_in[42].flags, 108,
                    "incorrect value for sol_in[42].flags, expected 108, is {}",
                    msg.sol_in[42].flags
                );
                assert_eq!(
                    msg.sol_in[42].sensor_type, 2,
                    "incorrect value for sol_in[42].sensor_type, expected 2, is {}",
                    msg.sol_in[42].sensor_type
                );
                assert_eq!(
                    msg.sol_in[43].flags, 101,
                    "incorrect value for sol_in[43].flags, expected 101, is {}",
                    msg.sol_in[43].flags
                );
                assert_eq!(
                    msg.sol_in[43].sensor_type, 91,
                    "incorrect value for sol_in[43].sensor_type, expected 91, is {}",
                    msg.sol_in[43].sensor_type
                );
                assert_eq!(
                    msg.sol_in[44].flags, 55,
                    "incorrect value for sol_in[44].flags, expected 55, is {}",
                    msg.sol_in[44].flags
                );
                assert_eq!(
                    msg.sol_in[44].sensor_type, 200,
                    "incorrect value for sol_in[44].sensor_type, expected 200, is {}",
                    msg.sol_in[44].sensor_type
                );
                assert_eq!(
                    msg.sol_in[45].flags, 156,
                    "incorrect value for sol_in[45].flags, expected 156, is {}",
                    msg.sol_in[45].flags
                );
                assert_eq!(
                    msg.sol_in[45].sensor_type, 24,
                    "incorrect value for sol_in[45].sensor_type, expected 24, is {}",
                    msg.sol_in[45].sensor_type
                );
                assert_eq!(
                    msg.sol_in[46].flags, 73,
                    "incorrect value for sol_in[46].flags, expected 73, is {}",
                    msg.sol_in[46].flags
                );
                assert_eq!(
                    msg.sol_in[46].sensor_type, 233,
                    "incorrect value for sol_in[46].sensor_type, expected 233, is {}",
                    msg.sol_in[46].sensor_type
                );
                assert_eq!(
                    msg.sol_in[47].flags, 66,
                    "incorrect value for sol_in[47].flags, expected 66, is {}",
                    msg.sol_in[47].flags
                );
                assert_eq!(
                    msg.sol_in[47].sensor_type, 39,
                    "incorrect value for sol_in[47].sensor_type, expected 39, is {}",
                    msg.sol_in[47].sensor_type
                );
                assert_eq!(
                    msg.sol_in[48].flags, 140,
                    "incorrect value for sol_in[48].flags, expected 140, is {}",
                    msg.sol_in[48].flags
                );
                assert_eq!(
                    msg.sol_in[48].sensor_type, 97,
                    "incorrect value for sol_in[48].sensor_type, expected 97, is {}",
                    msg.sol_in[48].sensor_type
                );
                assert_eq!(
                    msg.sol_in[49].flags, 227,
                    "incorrect value for sol_in[49].flags, expected 227, is {}",
                    msg.sol_in[49].flags
                );
                assert_eq!(
                    msg.sol_in[49].sensor_type, 252,
                    "incorrect value for sol_in[49].sensor_type, expected 252, is {}",
                    msg.sol_in[49].sensor_type
                );
                assert_eq!(
                    msg.sol_in[50].flags, 237,
                    "incorrect value for sol_in[50].flags, expected 237, is {}",
                    msg.sol_in[50].flags
                );
                assert_eq!(
                    msg.sol_in[50].sensor_type, 230,
                    "incorrect value for sol_in[50].sensor_type, expected 230, is {}",
                    msg.sol_in[50].sensor_type
                );
                assert_eq!(
                    msg.sol_in[51].flags, 241,
                    "incorrect value for sol_in[51].flags, expected 241, is {}",
                    msg.sol_in[51].flags
                );
                assert_eq!(
                    msg.sol_in[51].sensor_type, 135,
                    "incorrect value for sol_in[51].sensor_type, expected 135, is {}",
                    msg.sol_in[51].sensor_type
                );
                assert_eq!(
                    msg.sol_in[52].flags, 205,
                    "incorrect value for sol_in[52].flags, expected 205, is {}",
                    msg.sol_in[52].flags
                );
                assert_eq!(
                    msg.sol_in[52].sensor_type, 245,
                    "incorrect value for sol_in[52].sensor_type, expected 245, is {}",
                    msg.sol_in[52].sensor_type
                );
                assert_eq!(
                    msg.sol_in[53].flags, 0,
                    "incorrect value for sol_in[53].flags, expected 0, is {}",
                    msg.sol_in[53].flags
                );
                assert_eq!(
                    msg.sol_in[53].sensor_type, 70,
                    "incorrect value for sol_in[53].sensor_type, expected 70, is {}",
                    msg.sol_in[53].sensor_type
                );
                assert_eq!(
                    msg.sol_in[54].flags, 188,
                    "incorrect value for sol_in[54].flags, expected 188, is {}",
                    msg.sol_in[54].flags
                );
                assert_eq!(
                    msg.sol_in[54].sensor_type, 219,
                    "incorrect value for sol_in[54].sensor_type, expected 219, is {}",
                    msg.sol_in[54].sensor_type
                );
                assert_eq!(
                    msg.sol_in[55].flags, 136,
                    "incorrect value for sol_in[55].flags, expected 136, is {}",
                    msg.sol_in[55].flags
                );
                assert_eq!(
                    msg.sol_in[55].sensor_type, 107,
                    "incorrect value for sol_in[55].sensor_type, expected 107, is {}",
                    msg.sol_in[55].sensor_type
                );
                assert_eq!(
                    msg.sol_in[56].flags, 58,
                    "incorrect value for sol_in[56].flags, expected 58, is {}",
                    msg.sol_in[56].flags
                );
                assert_eq!(
                    msg.sol_in[56].sensor_type, 178,
                    "incorrect value for sol_in[56].sensor_type, expected 178, is {}",
                    msg.sol_in[56].sensor_type
                );
                assert_eq!(
                    msg.sol_in[57].flags, 29,
                    "incorrect value for sol_in[57].flags, expected 29, is {}",
                    msg.sol_in[57].flags
                );
                assert_eq!(
                    msg.sol_in[57].sensor_type, 1,
                    "incorrect value for sol_in[57].sensor_type, expected 1, is {}",
                    msg.sol_in[57].sensor_type
                );
                assert_eq!(
                    msg.sol_in[58].flags, 213,
                    "incorrect value for sol_in[58].flags, expected 213, is {}",
                    msg.sol_in[58].flags
                );
                assert_eq!(
                    msg.sol_in[58].sensor_type, 44,
                    "incorrect value for sol_in[58].sensor_type, expected 44, is {}",
                    msg.sol_in[58].sensor_type
                );
                assert_eq!(
                    msg.sol_in[59].flags, 147,
                    "incorrect value for sol_in[59].flags, expected 147, is {}",
                    msg.sol_in[59].flags
                );
                assert_eq!(
                    msg.sol_in[59].sensor_type, 225,
                    "incorrect value for sol_in[59].sensor_type, expected 225, is {}",
                    msg.sol_in[59].sensor_type
                );
                assert_eq!(
                    msg.sol_in[60].flags, 96,
                    "incorrect value for sol_in[60].flags, expected 96, is {}",
                    msg.sol_in[60].flags
                );
                assert_eq!(
                    msg.sol_in[60].sensor_type, 190,
                    "incorrect value for sol_in[60].sensor_type, expected 190, is {}",
                    msg.sol_in[60].sensor_type
                );
                assert_eq!(
                    msg.sol_in[61].flags, 108,
                    "incorrect value for sol_in[61].flags, expected 108, is {}",
                    msg.sol_in[61].flags
                );
                assert_eq!(
                    msg.sol_in[61].sensor_type, 192,
                    "incorrect value for sol_in[61].sensor_type, expected 192, is {}",
                    msg.sol_in[61].sensor_type
                );
                assert_eq!(
                    msg.sol_in[62].flags, 15,
                    "incorrect value for sol_in[62].flags, expected 15, is {}",
                    msg.sol_in[62].flags
                );
                assert_eq!(
                    msg.sol_in[62].sensor_type, 228,
                    "incorrect value for sol_in[62].sensor_type, expected 228, is {}",
                    msg.sol_in[62].sensor_type
                );
                assert_eq!(
                    msg.sol_in[63].flags, 18,
                    "incorrect value for sol_in[63].flags, expected 18, is {}",
                    msg.sol_in[63].flags
                );
                assert_eq!(
                    msg.sol_in[63].sensor_type, 203,
                    "incorrect value for sol_in[63].sensor_type, expected 203, is {}",
                    msg.sol_in[63].sensor_type
                );
                assert_eq!(
                    msg.sol_in[64].flags, 222,
                    "incorrect value for sol_in[64].flags, expected 222, is {}",
                    msg.sol_in[64].flags
                );
                assert_eq!(
                    msg.sol_in[64].sensor_type, 3,
                    "incorrect value for sol_in[64].sensor_type, expected 3, is {}",
                    msg.sol_in[64].sensor_type
                );
                assert_eq!(
                    msg.sol_in[65].flags, 68,
                    "incorrect value for sol_in[65].flags, expected 68, is {}",
                    msg.sol_in[65].flags
                );
                assert_eq!(
                    msg.sol_in[65].sensor_type, 180,
                    "incorrect value for sol_in[65].sensor_type, expected 180, is {}",
                    msg.sol_in[65].sensor_type
                );
                assert_eq!(
                    msg.sol_in[66].flags, 229,
                    "incorrect value for sol_in[66].flags, expected 229, is {}",
                    msg.sol_in[66].flags
                );
                assert_eq!(
                    msg.sol_in[66].sensor_type, 101,
                    "incorrect value for sol_in[66].sensor_type, expected 101, is {}",
                    msg.sol_in[66].sensor_type
                );
                assert_eq!(
                    msg.sol_in[67].flags, 203,
                    "incorrect value for sol_in[67].flags, expected 203, is {}",
                    msg.sol_in[67].flags
                );
                assert_eq!(
                    msg.sol_in[67].sensor_type, 223,
                    "incorrect value for sol_in[67].sensor_type, expected 223, is {}",
                    msg.sol_in[67].sensor_type
                );
                assert_eq!(
                    msg.sol_in[68].flags, 164,
                    "incorrect value for sol_in[68].flags, expected 164, is {}",
                    msg.sol_in[68].flags
                );
                assert_eq!(
                    msg.sol_in[68].sensor_type, 243,
                    "incorrect value for sol_in[68].sensor_type, expected 243, is {}",
                    msg.sol_in[68].sensor_type
                );
                assert_eq!(
                    msg.sol_in[69].flags, 165,
                    "incorrect value for sol_in[69].flags, expected 165, is {}",
                    msg.sol_in[69].flags
                );
                assert_eq!(
                    msg.sol_in[69].sensor_type, 92,
                    "incorrect value for sol_in[69].sensor_type, expected 92, is {}",
                    msg.sol_in[69].sensor_type
                );
                assert_eq!(
                    msg.sol_in[70].flags, 159,
                    "incorrect value for sol_in[70].flags, expected 159, is {}",
                    msg.sol_in[70].flags
                );
                assert_eq!(
                    msg.sol_in[70].sensor_type, 220,
                    "incorrect value for sol_in[70].sensor_type, expected 220, is {}",
                    msg.sol_in[70].sensor_type
                );
                assert_eq!(
                    msg.sol_in[71].flags, 121,
                    "incorrect value for sol_in[71].flags, expected 121, is {}",
                    msg.sol_in[71].flags
                );
                assert_eq!(
                    msg.sol_in[71].sensor_type, 174,
                    "incorrect value for sol_in[71].sensor_type, expected 174, is {}",
                    msg.sol_in[71].sensor_type
                );
                assert_eq!(
                    msg.sol_in[72].flags, 167,
                    "incorrect value for sol_in[72].flags, expected 167, is {}",
                    msg.sol_in[72].flags
                );
                assert_eq!(
                    msg.sol_in[72].sensor_type, 112,
                    "incorrect value for sol_in[72].sensor_type, expected 112, is {}",
                    msg.sol_in[72].sensor_type
                );
                assert_eq!(
                    msg.sol_in[73].flags, 40,
                    "incorrect value for sol_in[73].flags, expected 40, is {}",
                    msg.sol_in[73].flags
                );
                assert_eq!(
                    msg.sol_in[73].sensor_type, 240,
                    "incorrect value for sol_in[73].sensor_type, expected 240, is {}",
                    msg.sol_in[73].sensor_type
                );
                assert_eq!(
                    msg.sol_in[74].flags, 3,
                    "incorrect value for sol_in[74].flags, expected 3, is {}",
                    msg.sol_in[74].flags
                );
                assert_eq!(
                    msg.sol_in[74].sensor_type, 59,
                    "incorrect value for sol_in[74].sensor_type, expected 59, is {}",
                    msg.sol_in[74].sensor_type
                );
                assert_eq!(
                    msg.sol_in[75].flags, 52,
                    "incorrect value for sol_in[75].flags, expected 52, is {}",
                    msg.sol_in[75].flags
                );
                assert_eq!(
                    msg.sol_in[75].sensor_type, 230,
                    "incorrect value for sol_in[75].sensor_type, expected 230, is {}",
                    msg.sol_in[75].sensor_type
                );
                assert_eq!(
                    msg.sol_in[76].flags, 148,
                    "incorrect value for sol_in[76].flags, expected 148, is {}",
                    msg.sol_in[76].flags
                );
                assert_eq!(
                    msg.sol_in[76].sensor_type, 149,
                    "incorrect value for sol_in[76].sensor_type, expected 149, is {}",
                    msg.sol_in[76].sensor_type
                );
                assert_eq!(
                    msg.sol_in[77].flags, 142,
                    "incorrect value for sol_in[77].flags, expected 142, is {}",
                    msg.sol_in[77].flags
                );
                assert_eq!(
                    msg.sol_in[77].sensor_type, 218,
                    "incorrect value for sol_in[77].sensor_type, expected 218, is {}",
                    msg.sol_in[77].sensor_type
                );
                assert_eq!(
                    msg.sol_in[78].flags, 109,
                    "incorrect value for sol_in[78].flags, expected 109, is {}",
                    msg.sol_in[78].flags
                );
                assert_eq!(
                    msg.sol_in[78].sensor_type, 212,
                    "incorrect value for sol_in[78].sensor_type, expected 212, is {}",
                    msg.sol_in[78].sensor_type
                );
                assert_eq!(
                    msg.sol_in[79].flags, 71,
                    "incorrect value for sol_in[79].flags, expected 71, is {}",
                    msg.sol_in[79].flags
                );
                assert_eq!(
                    msg.sol_in[79].sensor_type, 176,
                    "incorrect value for sol_in[79].sensor_type, expected 176, is {}",
                    msg.sol_in[79].sensor_type
                );
                assert_eq!(
                    msg.sol_in[80].flags, 172,
                    "incorrect value for sol_in[80].flags, expected 172, is {}",
                    msg.sol_in[80].flags
                );
                assert_eq!(
                    msg.sol_in[80].sensor_type, 179,
                    "incorrect value for sol_in[80].sensor_type, expected 179, is {}",
                    msg.sol_in[80].sensor_type
                );
                assert_eq!(
                    msg.sol_in[81].flags, 1,
                    "incorrect value for sol_in[81].flags, expected 1, is {}",
                    msg.sol_in[81].flags
                );
                assert_eq!(
                    msg.sol_in[81].sensor_type, 77,
                    "incorrect value for sol_in[81].sensor_type, expected 77, is {}",
                    msg.sol_in[81].sensor_type
                );
                assert_eq!(
                    msg.sol_in[82].flags, 70,
                    "incorrect value for sol_in[82].flags, expected 70, is {}",
                    msg.sol_in[82].flags
                );
                assert_eq!(
                    msg.sol_in[82].sensor_type, 193,
                    "incorrect value for sol_in[82].sensor_type, expected 193, is {}",
                    msg.sol_in[82].sensor_type
                );
                assert_eq!(
                    msg.sol_in[83].flags, 149,
                    "incorrect value for sol_in[83].flags, expected 149, is {}",
                    msg.sol_in[83].flags
                );
                assert_eq!(
                    msg.sol_in[83].sensor_type, 147,
                    "incorrect value for sol_in[83].sensor_type, expected 147, is {}",
                    msg.sol_in[83].sensor_type
                );
                assert_eq!(
                    msg.sol_in[84].flags, 144,
                    "incorrect value for sol_in[84].flags, expected 144, is {}",
                    msg.sol_in[84].flags
                );
                assert_eq!(
                    msg.sol_in[84].sensor_type, 23,
                    "incorrect value for sol_in[84].sensor_type, expected 23, is {}",
                    msg.sol_in[84].sensor_type
                );
                assert_eq!(
                    msg.sol_in[85].flags, 239,
                    "incorrect value for sol_in[85].flags, expected 239, is {}",
                    msg.sol_in[85].flags
                );
                assert_eq!(
                    msg.sol_in[85].sensor_type, 148,
                    "incorrect value for sol_in[85].sensor_type, expected 148, is {}",
                    msg.sol_in[85].sensor_type
                );
                assert_eq!(
                    msg.sol_in[86].flags, 186,
                    "incorrect value for sol_in[86].flags, expected 186, is {}",
                    msg.sol_in[86].flags
                );
                assert_eq!(
                    msg.sol_in[86].sensor_type, 195,
                    "incorrect value for sol_in[86].sensor_type, expected 195, is {}",
                    msg.sol_in[86].sensor_type
                );
                assert_eq!(
                    msg.sol_in[87].flags, 30,
                    "incorrect value for sol_in[87].flags, expected 30, is {}",
                    msg.sol_in[87].flags
                );
                assert_eq!(
                    msg.sol_in[87].sensor_type, 86,
                    "incorrect value for sol_in[87].sensor_type, expected 86, is {}",
                    msg.sol_in[87].sensor_type
                );
                assert_eq!(
                    msg.sol_in[88].flags, 143,
                    "incorrect value for sol_in[88].flags, expected 143, is {}",
                    msg.sol_in[88].flags
                );
                assert_eq!(
                    msg.sol_in[88].sensor_type, 34,
                    "incorrect value for sol_in[88].sensor_type, expected 34, is {}",
                    msg.sol_in[88].sensor_type
                );
                assert_eq!(
                    msg.sol_in[89].flags, 207,
                    "incorrect value for sol_in[89].flags, expected 207, is {}",
                    msg.sol_in[89].flags
                );
                assert_eq!(
                    msg.sol_in[89].sensor_type, 156,
                    "incorrect value for sol_in[89].sensor_type, expected 156, is {}",
                    msg.sol_in[89].sensor_type
                );
                assert_eq!(
                    msg.sol_in[90].flags, 55,
                    "incorrect value for sol_in[90].flags, expected 55, is {}",
                    msg.sol_in[90].flags
                );
                assert_eq!(
                    msg.sol_in[90].sensor_type, 63,
                    "incorrect value for sol_in[90].sensor_type, expected 63, is {}",
                    msg.sol_in[90].sensor_type
                );
                assert_eq!(
                    msg.sol_in[91].flags, 255,
                    "incorrect value for sol_in[91].flags, expected 255, is {}",
                    msg.sol_in[91].flags
                );
                assert_eq!(
                    msg.sol_in[91].sensor_type, 117,
                    "incorrect value for sol_in[91].sensor_type, expected 117, is {}",
                    msg.sol_in[91].sensor_type
                );
                assert_eq!(
                    msg.sol_in[92].flags, 222,
                    "incorrect value for sol_in[92].flags, expected 222, is {}",
                    msg.sol_in[92].flags
                );
                assert_eq!(
                    msg.sol_in[92].sensor_type, 222,
                    "incorrect value for sol_in[92].sensor_type, expected 222, is {}",
                    msg.sol_in[92].sensor_type
                );
                assert_eq!(
                    msg.sol_in[93].flags, 145,
                    "incorrect value for sol_in[93].flags, expected 145, is {}",
                    msg.sol_in[93].flags
                );
                assert_eq!(
                    msg.sol_in[93].sensor_type, 219,
                    "incorrect value for sol_in[93].sensor_type, expected 219, is {}",
                    msg.sol_in[93].sensor_type
                );
                assert_eq!(
                    msg.sol_in[94].flags, 191,
                    "incorrect value for sol_in[94].flags, expected 191, is {}",
                    msg.sol_in[94].flags
                );
                assert_eq!(
                    msg.sol_in[94].sensor_type, 224,
                    "incorrect value for sol_in[94].sensor_type, expected 224, is {}",
                    msg.sol_in[94].sensor_type
                );
                assert_eq!(
                    msg.sol_in[95].flags, 109,
                    "incorrect value for sol_in[95].flags, expected 109, is {}",
                    msg.sol_in[95].flags
                );
                assert_eq!(
                    msg.sol_in[95].sensor_type, 210,
                    "incorrect value for sol_in[95].sensor_type, expected 210, is {}",
                    msg.sol_in[95].sensor_type
                );
                assert_eq!(
                    msg.sol_in[96].flags, 153,
                    "incorrect value for sol_in[96].flags, expected 153, is {}",
                    msg.sol_in[96].flags
                );
                assert_eq!(
                    msg.sol_in[96].sensor_type, 86,
                    "incorrect value for sol_in[96].sensor_type, expected 86, is {}",
                    msg.sol_in[96].sensor_type
                );
                assert_eq!(
                    msg.sol_in[97].flags, 32,
                    "incorrect value for sol_in[97].flags, expected 32, is {}",
                    msg.sol_in[97].flags
                );
                assert_eq!(
                    msg.sol_in[97].sensor_type, 21,
                    "incorrect value for sol_in[97].sensor_type, expected 21, is {}",
                    msg.sol_in[97].sensor_type
                );
                assert_eq!(
                    msg.sol_in[98].flags, 10,
                    "incorrect value for sol_in[98].flags, expected 10, is {}",
                    msg.sol_in[98].flags
                );
                assert_eq!(
                    msg.sol_in[98].sensor_type, 226,
                    "incorrect value for sol_in[98].sensor_type, expected 226, is {}",
                    msg.sol_in[98].sensor_type
                );
                assert_eq!(
                    msg.sol_in[99].flags, 63,
                    "incorrect value for sol_in[99].flags, expected 63, is {}",
                    msg.sol_in[99].flags
                );
                assert_eq!(
                    msg.sol_in[99].sensor_type, 60,
                    "incorrect value for sol_in[99].sensor_type, expected 60, is {}",
                    msg.sol_in[99].sensor_type
                );
                assert_eq!(
                    msg.sol_in[100].flags, 236,
                    "incorrect value for sol_in[100].flags, expected 236, is {}",
                    msg.sol_in[100].flags
                );
                assert_eq!(
                    msg.sol_in[100].sensor_type, 106,
                    "incorrect value for sol_in[100].sensor_type, expected 106, is {}",
                    msg.sol_in[100].sensor_type
                );
                assert_eq!(
                    msg.sol_in[101].flags, 96,
                    "incorrect value for sol_in[101].flags, expected 96, is {}",
                    msg.sol_in[101].flags
                );
                assert_eq!(
                    msg.sol_in[101].sensor_type, 93,
                    "incorrect value for sol_in[101].sensor_type, expected 93, is {}",
                    msg.sol_in[101].sensor_type
                );
                assert_eq!(
                    msg.sol_in[102].flags, 163,
                    "incorrect value for sol_in[102].flags, expected 163, is {}",
                    msg.sol_in[102].flags
                );
                assert_eq!(
                    msg.sol_in[102].sensor_type, 30,
                    "incorrect value for sol_in[102].sensor_type, expected 30, is {}",
                    msg.sol_in[102].sensor_type
                );
                assert_eq!(
                    msg.sol_in[103].flags, 238,
                    "incorrect value for sol_in[103].flags, expected 238, is {}",
                    msg.sol_in[103].flags
                );
                assert_eq!(
                    msg.sol_in[103].sensor_type, 106,
                    "incorrect value for sol_in[103].sensor_type, expected 106, is {}",
                    msg.sol_in[103].sensor_type
                );
                assert_eq!(
                    msg.sol_in[104].flags, 133,
                    "incorrect value for sol_in[104].flags, expected 133, is {}",
                    msg.sol_in[104].flags
                );
                assert_eq!(
                    msg.sol_in[104].sensor_type, 147,
                    "incorrect value for sol_in[104].sensor_type, expected 147, is {}",
                    msg.sol_in[104].sensor_type
                );
                assert_eq!(
                    msg.sol_in[105].flags, 107,
                    "incorrect value for sol_in[105].flags, expected 107, is {}",
                    msg.sol_in[105].flags
                );
                assert_eq!(
                    msg.sol_in[105].sensor_type, 132,
                    "incorrect value for sol_in[105].sensor_type, expected 132, is {}",
                    msg.sol_in[105].sensor_type
                );
                assert_eq!(
                    msg.sol_in[106].flags, 214,
                    "incorrect value for sol_in[106].flags, expected 214, is {}",
                    msg.sol_in[106].flags
                );
                assert_eq!(
                    msg.sol_in[106].sensor_type, 152,
                    "incorrect value for sol_in[106].sensor_type, expected 152, is {}",
                    msg.sol_in[106].sensor_type
                );
                assert_eq!(
                    msg.sol_in[107].flags, 185,
                    "incorrect value for sol_in[107].flags, expected 185, is {}",
                    msg.sol_in[107].flags
                );
                assert_eq!(
                    msg.sol_in[107].sensor_type, 221,
                    "incorrect value for sol_in[107].sensor_type, expected 221, is {}",
                    msg.sol_in[107].sensor_type
                );
                assert_eq!(
                    msg.sol_in[108].flags, 21,
                    "incorrect value for sol_in[108].flags, expected 21, is {}",
                    msg.sol_in[108].flags
                );
                assert_eq!(
                    msg.sol_in[108].sensor_type, 202,
                    "incorrect value for sol_in[108].sensor_type, expected 202, is {}",
                    msg.sol_in[108].sensor_type
                );
                assert_eq!(
                    msg.sol_in[109].flags, 51,
                    "incorrect value for sol_in[109].flags, expected 51, is {}",
                    msg.sol_in[109].flags
                );
                assert_eq!(
                    msg.sol_in[109].sensor_type, 252,
                    "incorrect value for sol_in[109].sensor_type, expected 252, is {}",
                    msg.sol_in[109].sensor_type
                );
                assert_eq!(
                    msg.sol_in[110].flags, 59,
                    "incorrect value for sol_in[110].flags, expected 59, is {}",
                    msg.sol_in[110].flags
                );
                assert_eq!(
                    msg.sol_in[110].sensor_type, 130,
                    "incorrect value for sol_in[110].sensor_type, expected 130, is {}",
                    msg.sol_in[110].sensor_type
                );
                assert_eq!(
                    msg.sol_in[111].flags, 202,
                    "incorrect value for sol_in[111].flags, expected 202, is {}",
                    msg.sol_in[111].flags
                );
                assert_eq!(
                    msg.sol_in[111].sensor_type, 166,
                    "incorrect value for sol_in[111].sensor_type, expected 166, is {}",
                    msg.sol_in[111].sensor_type
                );
                assert_eq!(
                    msg.sol_in[112].flags, 170,
                    "incorrect value for sol_in[112].flags, expected 170, is {}",
                    msg.sol_in[112].flags
                );
                assert_eq!(
                    msg.sol_in[112].sensor_type, 127,
                    "incorrect value for sol_in[112].sensor_type, expected 127, is {}",
                    msg.sol_in[112].sensor_type
                );
                assert_eq!(
                    msg.sol_in[113].flags, 193,
                    "incorrect value for sol_in[113].flags, expected 193, is {}",
                    msg.sol_in[113].flags
                );
                assert_eq!(
                    msg.sol_in[113].sensor_type, 58,
                    "incorrect value for sol_in[113].sensor_type, expected 58, is {}",
                    msg.sol_in[113].sensor_type
                );
                assert_eq!(
                    msg.sol_in[114].flags, 125,
                    "incorrect value for sol_in[114].flags, expected 125, is {}",
                    msg.sol_in[114].flags
                );
                assert_eq!(
                    msg.sol_in[114].sensor_type, 215,
                    "incorrect value for sol_in[114].sensor_type, expected 215, is {}",
                    msg.sol_in[114].sensor_type
                );
                assert_eq!(
                    msg.sol_in[115].flags, 58,
                    "incorrect value for sol_in[115].flags, expected 58, is {}",
                    msg.sol_in[115].flags
                );
                assert_eq!(
                    msg.sol_in[115].sensor_type, 22,
                    "incorrect value for sol_in[115].sensor_type, expected 22, is {}",
                    msg.sol_in[115].sensor_type
                );
                assert_eq!(
                    msg.sol_in[116].flags, 47,
                    "incorrect value for sol_in[116].flags, expected 47, is {}",
                    msg.sol_in[116].flags
                );
                assert_eq!(
                    msg.sol_in[116].sensor_type, 135,
                    "incorrect value for sol_in[116].sensor_type, expected 135, is {}",
                    msg.sol_in[116].sensor_type
                );
                assert_eq!(
                    msg.sol_in[117].flags, 142,
                    "incorrect value for sol_in[117].flags, expected 142, is {}",
                    msg.sol_in[117].flags
                );
                assert_eq!(
                    msg.sol_in[117].sensor_type, 88,
                    "incorrect value for sol_in[117].sensor_type, expected 88, is {}",
                    msg.sol_in[117].sensor_type
                );
                assert_eq!(
                    msg.vdop, 41989,
                    "incorrect value for vdop, expected 41989, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSolnMetaDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_solution_meta_msg_soln_meta_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_solution_meta_msg_soln_meta_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 15, 255, 84, 241, 254, 183, 222, 157, 121, 5, 164, 238, 31, 190, 115, 93, 59, 103,
            36, 83, 161, 156, 46, 253, 67, 87, 200, 39, 250, 245, 242, 228, 72, 18, 222, 11, 88,
            207, 218, 231, 13, 226, 224, 22, 196, 21, 242, 12, 89, 71, 219, 182, 85, 145, 204, 146,
            40, 204, 51, 21, 153, 227, 44, 15, 28, 255, 39, 205, 216, 240, 190, 93, 219, 103, 42,
            41, 182, 76, 222, 17, 23, 125, 31, 18, 229, 28, 47, 214, 25, 100, 84, 106, 72, 48, 10,
            222, 232, 235, 73, 109, 163, 51, 152, 133, 235, 87, 70, 2, 108, 91, 101, 200, 55, 24,
            156, 233, 73, 39, 66, 97, 140, 252, 227, 230, 237, 135, 241, 245, 205, 70, 0, 219, 188,
            107, 136, 178, 58, 1, 29, 44, 213, 225, 147, 190, 96, 192, 108, 228, 15, 203, 18, 3,
            222, 180, 68, 101, 229, 223, 203, 243, 164, 92, 165, 220, 159, 174, 121, 112, 167, 240,
            40, 59, 3, 230, 52, 149, 148, 218, 142, 212, 109, 176, 71, 179, 172, 77, 1, 193, 70,
            147, 149, 23, 144, 148, 239, 195, 186, 86, 30, 34, 143, 156, 207, 63, 55, 117, 255,
            222, 222, 219, 145, 224, 191, 210, 109, 86, 153, 21, 32, 226, 10, 60, 63, 106, 236, 93,
            96, 30, 163, 106, 238, 147, 133, 132, 107, 152, 214, 221, 185, 202, 21, 252, 51, 130,
            59, 166, 202, 127, 170, 58, 193, 215, 125, 22, 58, 135, 47, 88, 142, 77, 211,
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
        let sbp_msg = sbp::messages::Sbp::MsgSolnMetaDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSolnMetaDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xff0f,
                    "Incorrect message type, expected 0xff0f, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf154,
                    "incorrect sender id, expected 0xf154, is {sender_id}"
                );
                assert_eq!(
                    msg.age_corrections, 48671,
                    "incorrect value for age_corrections, expected 48671, is {}",
                    msg.age_corrections
                );
                assert_eq!(
                    msg.alignment_status, 115,
                    "incorrect value for alignment_status, expected 115, is {}",
                    msg.alignment_status
                );
                assert_eq!(
                    msg.hdop, 31133,
                    "incorrect value for hdop, expected 31133, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.last_used_gnss_pos_tow, 610745181,
                    "incorrect value for last_used_gnss_pos_tow, expected 610745181, is {}",
                    msg.last_used_gnss_pos_tow
                );
                assert_eq!(
                    msg.last_used_gnss_vel_tow, 782016851,
                    "incorrect value for last_used_gnss_vel_tow, expected 782016851, is {}",
                    msg.last_used_gnss_vel_tow
                );
                assert_eq!(
                    msg.n_sats, 238,
                    "incorrect value for n_sats, expected 238, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.pdop, 57015,
                    "incorrect value for pdop, expected 57015, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.sol_in[0].flags, 67,
                    "incorrect value for sol_in[0].flags, expected 67, is {}",
                    msg.sol_in[0].flags
                );
                assert_eq!(
                    msg.sol_in[0].sensor_type, 253,
                    "incorrect value for sol_in[0].sensor_type, expected 253, is {}",
                    msg.sol_in[0].sensor_type
                );
                assert_eq!(
                    msg.sol_in[1].flags, 200,
                    "incorrect value for sol_in[1].flags, expected 200, is {}",
                    msg.sol_in[1].flags
                );
                assert_eq!(
                    msg.sol_in[1].sensor_type, 87,
                    "incorrect value for sol_in[1].sensor_type, expected 87, is {}",
                    msg.sol_in[1].sensor_type
                );
                assert_eq!(
                    msg.sol_in[2].flags, 250,
                    "incorrect value for sol_in[2].flags, expected 250, is {}",
                    msg.sol_in[2].flags
                );
                assert_eq!(
                    msg.sol_in[2].sensor_type, 39,
                    "incorrect value for sol_in[2].sensor_type, expected 39, is {}",
                    msg.sol_in[2].sensor_type
                );
                assert_eq!(
                    msg.sol_in[3].flags, 242,
                    "incorrect value for sol_in[3].flags, expected 242, is {}",
                    msg.sol_in[3].flags
                );
                assert_eq!(
                    msg.sol_in[3].sensor_type, 245,
                    "incorrect value for sol_in[3].sensor_type, expected 245, is {}",
                    msg.sol_in[3].sensor_type
                );
                assert_eq!(
                    msg.sol_in[4].flags, 72,
                    "incorrect value for sol_in[4].flags, expected 72, is {}",
                    msg.sol_in[4].flags
                );
                assert_eq!(
                    msg.sol_in[4].sensor_type, 228,
                    "incorrect value for sol_in[4].sensor_type, expected 228, is {}",
                    msg.sol_in[4].sensor_type
                );
                assert_eq!(
                    msg.sol_in[5].flags, 222,
                    "incorrect value for sol_in[5].flags, expected 222, is {}",
                    msg.sol_in[5].flags
                );
                assert_eq!(
                    msg.sol_in[5].sensor_type, 18,
                    "incorrect value for sol_in[5].sensor_type, expected 18, is {}",
                    msg.sol_in[5].sensor_type
                );
                assert_eq!(
                    msg.sol_in[6].flags, 88,
                    "incorrect value for sol_in[6].flags, expected 88, is {}",
                    msg.sol_in[6].flags
                );
                assert_eq!(
                    msg.sol_in[6].sensor_type, 11,
                    "incorrect value for sol_in[6].sensor_type, expected 11, is {}",
                    msg.sol_in[6].sensor_type
                );
                assert_eq!(
                    msg.sol_in[7].flags, 218,
                    "incorrect value for sol_in[7].flags, expected 218, is {}",
                    msg.sol_in[7].flags
                );
                assert_eq!(
                    msg.sol_in[7].sensor_type, 207,
                    "incorrect value for sol_in[7].sensor_type, expected 207, is {}",
                    msg.sol_in[7].sensor_type
                );
                assert_eq!(
                    msg.sol_in[8].flags, 13,
                    "incorrect value for sol_in[8].flags, expected 13, is {}",
                    msg.sol_in[8].flags
                );
                assert_eq!(
                    msg.sol_in[8].sensor_type, 231,
                    "incorrect value for sol_in[8].sensor_type, expected 231, is {}",
                    msg.sol_in[8].sensor_type
                );
                assert_eq!(
                    msg.sol_in[9].flags, 224,
                    "incorrect value for sol_in[9].flags, expected 224, is {}",
                    msg.sol_in[9].flags
                );
                assert_eq!(
                    msg.sol_in[9].sensor_type, 226,
                    "incorrect value for sol_in[9].sensor_type, expected 226, is {}",
                    msg.sol_in[9].sensor_type
                );
                assert_eq!(
                    msg.sol_in[10].flags, 196,
                    "incorrect value for sol_in[10].flags, expected 196, is {}",
                    msg.sol_in[10].flags
                );
                assert_eq!(
                    msg.sol_in[10].sensor_type, 22,
                    "incorrect value for sol_in[10].sensor_type, expected 22, is {}",
                    msg.sol_in[10].sensor_type
                );
                assert_eq!(
                    msg.sol_in[11].flags, 242,
                    "incorrect value for sol_in[11].flags, expected 242, is {}",
                    msg.sol_in[11].flags
                );
                assert_eq!(
                    msg.sol_in[11].sensor_type, 21,
                    "incorrect value for sol_in[11].sensor_type, expected 21, is {}",
                    msg.sol_in[11].sensor_type
                );
                assert_eq!(
                    msg.sol_in[12].flags, 89,
                    "incorrect value for sol_in[12].flags, expected 89, is {}",
                    msg.sol_in[12].flags
                );
                assert_eq!(
                    msg.sol_in[12].sensor_type, 12,
                    "incorrect value for sol_in[12].sensor_type, expected 12, is {}",
                    msg.sol_in[12].sensor_type
                );
                assert_eq!(
                    msg.sol_in[13].flags, 219,
                    "incorrect value for sol_in[13].flags, expected 219, is {}",
                    msg.sol_in[13].flags
                );
                assert_eq!(
                    msg.sol_in[13].sensor_type, 71,
                    "incorrect value for sol_in[13].sensor_type, expected 71, is {}",
                    msg.sol_in[13].sensor_type
                );
                assert_eq!(
                    msg.sol_in[14].flags, 85,
                    "incorrect value for sol_in[14].flags, expected 85, is {}",
                    msg.sol_in[14].flags
                );
                assert_eq!(
                    msg.sol_in[14].sensor_type, 182,
                    "incorrect value for sol_in[14].sensor_type, expected 182, is {}",
                    msg.sol_in[14].sensor_type
                );
                assert_eq!(
                    msg.sol_in[15].flags, 204,
                    "incorrect value for sol_in[15].flags, expected 204, is {}",
                    msg.sol_in[15].flags
                );
                assert_eq!(
                    msg.sol_in[15].sensor_type, 145,
                    "incorrect value for sol_in[15].sensor_type, expected 145, is {}",
                    msg.sol_in[15].sensor_type
                );
                assert_eq!(
                    msg.sol_in[16].flags, 40,
                    "incorrect value for sol_in[16].flags, expected 40, is {}",
                    msg.sol_in[16].flags
                );
                assert_eq!(
                    msg.sol_in[16].sensor_type, 146,
                    "incorrect value for sol_in[16].sensor_type, expected 146, is {}",
                    msg.sol_in[16].sensor_type
                );
                assert_eq!(
                    msg.sol_in[17].flags, 51,
                    "incorrect value for sol_in[17].flags, expected 51, is {}",
                    msg.sol_in[17].flags
                );
                assert_eq!(
                    msg.sol_in[17].sensor_type, 204,
                    "incorrect value for sol_in[17].sensor_type, expected 204, is {}",
                    msg.sol_in[17].sensor_type
                );
                assert_eq!(
                    msg.sol_in[18].flags, 153,
                    "incorrect value for sol_in[18].flags, expected 153, is {}",
                    msg.sol_in[18].flags
                );
                assert_eq!(
                    msg.sol_in[18].sensor_type, 21,
                    "incorrect value for sol_in[18].sensor_type, expected 21, is {}",
                    msg.sol_in[18].sensor_type
                );
                assert_eq!(
                    msg.sol_in[19].flags, 44,
                    "incorrect value for sol_in[19].flags, expected 44, is {}",
                    msg.sol_in[19].flags
                );
                assert_eq!(
                    msg.sol_in[19].sensor_type, 227,
                    "incorrect value for sol_in[19].sensor_type, expected 227, is {}",
                    msg.sol_in[19].sensor_type
                );
                assert_eq!(
                    msg.sol_in[20].flags, 28,
                    "incorrect value for sol_in[20].flags, expected 28, is {}",
                    msg.sol_in[20].flags
                );
                assert_eq!(
                    msg.sol_in[20].sensor_type, 15,
                    "incorrect value for sol_in[20].sensor_type, expected 15, is {}",
                    msg.sol_in[20].sensor_type
                );
                assert_eq!(
                    msg.sol_in[21].flags, 39,
                    "incorrect value for sol_in[21].flags, expected 39, is {}",
                    msg.sol_in[21].flags
                );
                assert_eq!(
                    msg.sol_in[21].sensor_type, 255,
                    "incorrect value for sol_in[21].sensor_type, expected 255, is {}",
                    msg.sol_in[21].sensor_type
                );
                assert_eq!(
                    msg.sol_in[22].flags, 216,
                    "incorrect value for sol_in[22].flags, expected 216, is {}",
                    msg.sol_in[22].flags
                );
                assert_eq!(
                    msg.sol_in[22].sensor_type, 205,
                    "incorrect value for sol_in[22].sensor_type, expected 205, is {}",
                    msg.sol_in[22].sensor_type
                );
                assert_eq!(
                    msg.sol_in[23].flags, 190,
                    "incorrect value for sol_in[23].flags, expected 190, is {}",
                    msg.sol_in[23].flags
                );
                assert_eq!(
                    msg.sol_in[23].sensor_type, 240,
                    "incorrect value for sol_in[23].sensor_type, expected 240, is {}",
                    msg.sol_in[23].sensor_type
                );
                assert_eq!(
                    msg.sol_in[24].flags, 219,
                    "incorrect value for sol_in[24].flags, expected 219, is {}",
                    msg.sol_in[24].flags
                );
                assert_eq!(
                    msg.sol_in[24].sensor_type, 93,
                    "incorrect value for sol_in[24].sensor_type, expected 93, is {}",
                    msg.sol_in[24].sensor_type
                );
                assert_eq!(
                    msg.sol_in[25].flags, 42,
                    "incorrect value for sol_in[25].flags, expected 42, is {}",
                    msg.sol_in[25].flags
                );
                assert_eq!(
                    msg.sol_in[25].sensor_type, 103,
                    "incorrect value for sol_in[25].sensor_type, expected 103, is {}",
                    msg.sol_in[25].sensor_type
                );
                assert_eq!(
                    msg.sol_in[26].flags, 182,
                    "incorrect value for sol_in[26].flags, expected 182, is {}",
                    msg.sol_in[26].flags
                );
                assert_eq!(
                    msg.sol_in[26].sensor_type, 41,
                    "incorrect value for sol_in[26].sensor_type, expected 41, is {}",
                    msg.sol_in[26].sensor_type
                );
                assert_eq!(
                    msg.sol_in[27].flags, 222,
                    "incorrect value for sol_in[27].flags, expected 222, is {}",
                    msg.sol_in[27].flags
                );
                assert_eq!(
                    msg.sol_in[27].sensor_type, 76,
                    "incorrect value for sol_in[27].sensor_type, expected 76, is {}",
                    msg.sol_in[27].sensor_type
                );
                assert_eq!(
                    msg.sol_in[28].flags, 23,
                    "incorrect value for sol_in[28].flags, expected 23, is {}",
                    msg.sol_in[28].flags
                );
                assert_eq!(
                    msg.sol_in[28].sensor_type, 17,
                    "incorrect value for sol_in[28].sensor_type, expected 17, is {}",
                    msg.sol_in[28].sensor_type
                );
                assert_eq!(
                    msg.sol_in[29].flags, 31,
                    "incorrect value for sol_in[29].flags, expected 31, is {}",
                    msg.sol_in[29].flags
                );
                assert_eq!(
                    msg.sol_in[29].sensor_type, 125,
                    "incorrect value for sol_in[29].sensor_type, expected 125, is {}",
                    msg.sol_in[29].sensor_type
                );
                assert_eq!(
                    msg.sol_in[30].flags, 229,
                    "incorrect value for sol_in[30].flags, expected 229, is {}",
                    msg.sol_in[30].flags
                );
                assert_eq!(
                    msg.sol_in[30].sensor_type, 18,
                    "incorrect value for sol_in[30].sensor_type, expected 18, is {}",
                    msg.sol_in[30].sensor_type
                );
                assert_eq!(
                    msg.sol_in[31].flags, 47,
                    "incorrect value for sol_in[31].flags, expected 47, is {}",
                    msg.sol_in[31].flags
                );
                assert_eq!(
                    msg.sol_in[31].sensor_type, 28,
                    "incorrect value for sol_in[31].sensor_type, expected 28, is {}",
                    msg.sol_in[31].sensor_type
                );
                assert_eq!(
                    msg.sol_in[32].flags, 25,
                    "incorrect value for sol_in[32].flags, expected 25, is {}",
                    msg.sol_in[32].flags
                );
                assert_eq!(
                    msg.sol_in[32].sensor_type, 214,
                    "incorrect value for sol_in[32].sensor_type, expected 214, is {}",
                    msg.sol_in[32].sensor_type
                );
                assert_eq!(
                    msg.sol_in[33].flags, 84,
                    "incorrect value for sol_in[33].flags, expected 84, is {}",
                    msg.sol_in[33].flags
                );
                assert_eq!(
                    msg.sol_in[33].sensor_type, 100,
                    "incorrect value for sol_in[33].sensor_type, expected 100, is {}",
                    msg.sol_in[33].sensor_type
                );
                assert_eq!(
                    msg.sol_in[34].flags, 72,
                    "incorrect value for sol_in[34].flags, expected 72, is {}",
                    msg.sol_in[34].flags
                );
                assert_eq!(
                    msg.sol_in[34].sensor_type, 106,
                    "incorrect value for sol_in[34].sensor_type, expected 106, is {}",
                    msg.sol_in[34].sensor_type
                );
                assert_eq!(
                    msg.sol_in[35].flags, 10,
                    "incorrect value for sol_in[35].flags, expected 10, is {}",
                    msg.sol_in[35].flags
                );
                assert_eq!(
                    msg.sol_in[35].sensor_type, 48,
                    "incorrect value for sol_in[35].sensor_type, expected 48, is {}",
                    msg.sol_in[35].sensor_type
                );
                assert_eq!(
                    msg.sol_in[36].flags, 232,
                    "incorrect value for sol_in[36].flags, expected 232, is {}",
                    msg.sol_in[36].flags
                );
                assert_eq!(
                    msg.sol_in[36].sensor_type, 222,
                    "incorrect value for sol_in[36].sensor_type, expected 222, is {}",
                    msg.sol_in[36].sensor_type
                );
                assert_eq!(
                    msg.sol_in[37].flags, 73,
                    "incorrect value for sol_in[37].flags, expected 73, is {}",
                    msg.sol_in[37].flags
                );
                assert_eq!(
                    msg.sol_in[37].sensor_type, 235,
                    "incorrect value for sol_in[37].sensor_type, expected 235, is {}",
                    msg.sol_in[37].sensor_type
                );
                assert_eq!(
                    msg.sol_in[38].flags, 163,
                    "incorrect value for sol_in[38].flags, expected 163, is {}",
                    msg.sol_in[38].flags
                );
                assert_eq!(
                    msg.sol_in[38].sensor_type, 109,
                    "incorrect value for sol_in[38].sensor_type, expected 109, is {}",
                    msg.sol_in[38].sensor_type
                );
                assert_eq!(
                    msg.sol_in[39].flags, 152,
                    "incorrect value for sol_in[39].flags, expected 152, is {}",
                    msg.sol_in[39].flags
                );
                assert_eq!(
                    msg.sol_in[39].sensor_type, 51,
                    "incorrect value for sol_in[39].sensor_type, expected 51, is {}",
                    msg.sol_in[39].sensor_type
                );
                assert_eq!(
                    msg.sol_in[40].flags, 235,
                    "incorrect value for sol_in[40].flags, expected 235, is {}",
                    msg.sol_in[40].flags
                );
                assert_eq!(
                    msg.sol_in[40].sensor_type, 133,
                    "incorrect value for sol_in[40].sensor_type, expected 133, is {}",
                    msg.sol_in[40].sensor_type
                );
                assert_eq!(
                    msg.sol_in[41].flags, 70,
                    "incorrect value for sol_in[41].flags, expected 70, is {}",
                    msg.sol_in[41].flags
                );
                assert_eq!(
                    msg.sol_in[41].sensor_type, 87,
                    "incorrect value for sol_in[41].sensor_type, expected 87, is {}",
                    msg.sol_in[41].sensor_type
                );
                assert_eq!(
                    msg.sol_in[42].flags, 108,
                    "incorrect value for sol_in[42].flags, expected 108, is {}",
                    msg.sol_in[42].flags
                );
                assert_eq!(
                    msg.sol_in[42].sensor_type, 2,
                    "incorrect value for sol_in[42].sensor_type, expected 2, is {}",
                    msg.sol_in[42].sensor_type
                );
                assert_eq!(
                    msg.sol_in[43].flags, 101,
                    "incorrect value for sol_in[43].flags, expected 101, is {}",
                    msg.sol_in[43].flags
                );
                assert_eq!(
                    msg.sol_in[43].sensor_type, 91,
                    "incorrect value for sol_in[43].sensor_type, expected 91, is {}",
                    msg.sol_in[43].sensor_type
                );
                assert_eq!(
                    msg.sol_in[44].flags, 55,
                    "incorrect value for sol_in[44].flags, expected 55, is {}",
                    msg.sol_in[44].flags
                );
                assert_eq!(
                    msg.sol_in[44].sensor_type, 200,
                    "incorrect value for sol_in[44].sensor_type, expected 200, is {}",
                    msg.sol_in[44].sensor_type
                );
                assert_eq!(
                    msg.sol_in[45].flags, 156,
                    "incorrect value for sol_in[45].flags, expected 156, is {}",
                    msg.sol_in[45].flags
                );
                assert_eq!(
                    msg.sol_in[45].sensor_type, 24,
                    "incorrect value for sol_in[45].sensor_type, expected 24, is {}",
                    msg.sol_in[45].sensor_type
                );
                assert_eq!(
                    msg.sol_in[46].flags, 73,
                    "incorrect value for sol_in[46].flags, expected 73, is {}",
                    msg.sol_in[46].flags
                );
                assert_eq!(
                    msg.sol_in[46].sensor_type, 233,
                    "incorrect value for sol_in[46].sensor_type, expected 233, is {}",
                    msg.sol_in[46].sensor_type
                );
                assert_eq!(
                    msg.sol_in[47].flags, 66,
                    "incorrect value for sol_in[47].flags, expected 66, is {}",
                    msg.sol_in[47].flags
                );
                assert_eq!(
                    msg.sol_in[47].sensor_type, 39,
                    "incorrect value for sol_in[47].sensor_type, expected 39, is {}",
                    msg.sol_in[47].sensor_type
                );
                assert_eq!(
                    msg.sol_in[48].flags, 140,
                    "incorrect value for sol_in[48].flags, expected 140, is {}",
                    msg.sol_in[48].flags
                );
                assert_eq!(
                    msg.sol_in[48].sensor_type, 97,
                    "incorrect value for sol_in[48].sensor_type, expected 97, is {}",
                    msg.sol_in[48].sensor_type
                );
                assert_eq!(
                    msg.sol_in[49].flags, 227,
                    "incorrect value for sol_in[49].flags, expected 227, is {}",
                    msg.sol_in[49].flags
                );
                assert_eq!(
                    msg.sol_in[49].sensor_type, 252,
                    "incorrect value for sol_in[49].sensor_type, expected 252, is {}",
                    msg.sol_in[49].sensor_type
                );
                assert_eq!(
                    msg.sol_in[50].flags, 237,
                    "incorrect value for sol_in[50].flags, expected 237, is {}",
                    msg.sol_in[50].flags
                );
                assert_eq!(
                    msg.sol_in[50].sensor_type, 230,
                    "incorrect value for sol_in[50].sensor_type, expected 230, is {}",
                    msg.sol_in[50].sensor_type
                );
                assert_eq!(
                    msg.sol_in[51].flags, 241,
                    "incorrect value for sol_in[51].flags, expected 241, is {}",
                    msg.sol_in[51].flags
                );
                assert_eq!(
                    msg.sol_in[51].sensor_type, 135,
                    "incorrect value for sol_in[51].sensor_type, expected 135, is {}",
                    msg.sol_in[51].sensor_type
                );
                assert_eq!(
                    msg.sol_in[52].flags, 205,
                    "incorrect value for sol_in[52].flags, expected 205, is {}",
                    msg.sol_in[52].flags
                );
                assert_eq!(
                    msg.sol_in[52].sensor_type, 245,
                    "incorrect value for sol_in[52].sensor_type, expected 245, is {}",
                    msg.sol_in[52].sensor_type
                );
                assert_eq!(
                    msg.sol_in[53].flags, 0,
                    "incorrect value for sol_in[53].flags, expected 0, is {}",
                    msg.sol_in[53].flags
                );
                assert_eq!(
                    msg.sol_in[53].sensor_type, 70,
                    "incorrect value for sol_in[53].sensor_type, expected 70, is {}",
                    msg.sol_in[53].sensor_type
                );
                assert_eq!(
                    msg.sol_in[54].flags, 188,
                    "incorrect value for sol_in[54].flags, expected 188, is {}",
                    msg.sol_in[54].flags
                );
                assert_eq!(
                    msg.sol_in[54].sensor_type, 219,
                    "incorrect value for sol_in[54].sensor_type, expected 219, is {}",
                    msg.sol_in[54].sensor_type
                );
                assert_eq!(
                    msg.sol_in[55].flags, 136,
                    "incorrect value for sol_in[55].flags, expected 136, is {}",
                    msg.sol_in[55].flags
                );
                assert_eq!(
                    msg.sol_in[55].sensor_type, 107,
                    "incorrect value for sol_in[55].sensor_type, expected 107, is {}",
                    msg.sol_in[55].sensor_type
                );
                assert_eq!(
                    msg.sol_in[56].flags, 58,
                    "incorrect value for sol_in[56].flags, expected 58, is {}",
                    msg.sol_in[56].flags
                );
                assert_eq!(
                    msg.sol_in[56].sensor_type, 178,
                    "incorrect value for sol_in[56].sensor_type, expected 178, is {}",
                    msg.sol_in[56].sensor_type
                );
                assert_eq!(
                    msg.sol_in[57].flags, 29,
                    "incorrect value for sol_in[57].flags, expected 29, is {}",
                    msg.sol_in[57].flags
                );
                assert_eq!(
                    msg.sol_in[57].sensor_type, 1,
                    "incorrect value for sol_in[57].sensor_type, expected 1, is {}",
                    msg.sol_in[57].sensor_type
                );
                assert_eq!(
                    msg.sol_in[58].flags, 213,
                    "incorrect value for sol_in[58].flags, expected 213, is {}",
                    msg.sol_in[58].flags
                );
                assert_eq!(
                    msg.sol_in[58].sensor_type, 44,
                    "incorrect value for sol_in[58].sensor_type, expected 44, is {}",
                    msg.sol_in[58].sensor_type
                );
                assert_eq!(
                    msg.sol_in[59].flags, 147,
                    "incorrect value for sol_in[59].flags, expected 147, is {}",
                    msg.sol_in[59].flags
                );
                assert_eq!(
                    msg.sol_in[59].sensor_type, 225,
                    "incorrect value for sol_in[59].sensor_type, expected 225, is {}",
                    msg.sol_in[59].sensor_type
                );
                assert_eq!(
                    msg.sol_in[60].flags, 96,
                    "incorrect value for sol_in[60].flags, expected 96, is {}",
                    msg.sol_in[60].flags
                );
                assert_eq!(
                    msg.sol_in[60].sensor_type, 190,
                    "incorrect value for sol_in[60].sensor_type, expected 190, is {}",
                    msg.sol_in[60].sensor_type
                );
                assert_eq!(
                    msg.sol_in[61].flags, 108,
                    "incorrect value for sol_in[61].flags, expected 108, is {}",
                    msg.sol_in[61].flags
                );
                assert_eq!(
                    msg.sol_in[61].sensor_type, 192,
                    "incorrect value for sol_in[61].sensor_type, expected 192, is {}",
                    msg.sol_in[61].sensor_type
                );
                assert_eq!(
                    msg.sol_in[62].flags, 15,
                    "incorrect value for sol_in[62].flags, expected 15, is {}",
                    msg.sol_in[62].flags
                );
                assert_eq!(
                    msg.sol_in[62].sensor_type, 228,
                    "incorrect value for sol_in[62].sensor_type, expected 228, is {}",
                    msg.sol_in[62].sensor_type
                );
                assert_eq!(
                    msg.sol_in[63].flags, 18,
                    "incorrect value for sol_in[63].flags, expected 18, is {}",
                    msg.sol_in[63].flags
                );
                assert_eq!(
                    msg.sol_in[63].sensor_type, 203,
                    "incorrect value for sol_in[63].sensor_type, expected 203, is {}",
                    msg.sol_in[63].sensor_type
                );
                assert_eq!(
                    msg.sol_in[64].flags, 222,
                    "incorrect value for sol_in[64].flags, expected 222, is {}",
                    msg.sol_in[64].flags
                );
                assert_eq!(
                    msg.sol_in[64].sensor_type, 3,
                    "incorrect value for sol_in[64].sensor_type, expected 3, is {}",
                    msg.sol_in[64].sensor_type
                );
                assert_eq!(
                    msg.sol_in[65].flags, 68,
                    "incorrect value for sol_in[65].flags, expected 68, is {}",
                    msg.sol_in[65].flags
                );
                assert_eq!(
                    msg.sol_in[65].sensor_type, 180,
                    "incorrect value for sol_in[65].sensor_type, expected 180, is {}",
                    msg.sol_in[65].sensor_type
                );
                assert_eq!(
                    msg.sol_in[66].flags, 229,
                    "incorrect value for sol_in[66].flags, expected 229, is {}",
                    msg.sol_in[66].flags
                );
                assert_eq!(
                    msg.sol_in[66].sensor_type, 101,
                    "incorrect value for sol_in[66].sensor_type, expected 101, is {}",
                    msg.sol_in[66].sensor_type
                );
                assert_eq!(
                    msg.sol_in[67].flags, 203,
                    "incorrect value for sol_in[67].flags, expected 203, is {}",
                    msg.sol_in[67].flags
                );
                assert_eq!(
                    msg.sol_in[67].sensor_type, 223,
                    "incorrect value for sol_in[67].sensor_type, expected 223, is {}",
                    msg.sol_in[67].sensor_type
                );
                assert_eq!(
                    msg.sol_in[68].flags, 164,
                    "incorrect value for sol_in[68].flags, expected 164, is {}",
                    msg.sol_in[68].flags
                );
                assert_eq!(
                    msg.sol_in[68].sensor_type, 243,
                    "incorrect value for sol_in[68].sensor_type, expected 243, is {}",
                    msg.sol_in[68].sensor_type
                );
                assert_eq!(
                    msg.sol_in[69].flags, 165,
                    "incorrect value for sol_in[69].flags, expected 165, is {}",
                    msg.sol_in[69].flags
                );
                assert_eq!(
                    msg.sol_in[69].sensor_type, 92,
                    "incorrect value for sol_in[69].sensor_type, expected 92, is {}",
                    msg.sol_in[69].sensor_type
                );
                assert_eq!(
                    msg.sol_in[70].flags, 159,
                    "incorrect value for sol_in[70].flags, expected 159, is {}",
                    msg.sol_in[70].flags
                );
                assert_eq!(
                    msg.sol_in[70].sensor_type, 220,
                    "incorrect value for sol_in[70].sensor_type, expected 220, is {}",
                    msg.sol_in[70].sensor_type
                );
                assert_eq!(
                    msg.sol_in[71].flags, 121,
                    "incorrect value for sol_in[71].flags, expected 121, is {}",
                    msg.sol_in[71].flags
                );
                assert_eq!(
                    msg.sol_in[71].sensor_type, 174,
                    "incorrect value for sol_in[71].sensor_type, expected 174, is {}",
                    msg.sol_in[71].sensor_type
                );
                assert_eq!(
                    msg.sol_in[72].flags, 167,
                    "incorrect value for sol_in[72].flags, expected 167, is {}",
                    msg.sol_in[72].flags
                );
                assert_eq!(
                    msg.sol_in[72].sensor_type, 112,
                    "incorrect value for sol_in[72].sensor_type, expected 112, is {}",
                    msg.sol_in[72].sensor_type
                );
                assert_eq!(
                    msg.sol_in[73].flags, 40,
                    "incorrect value for sol_in[73].flags, expected 40, is {}",
                    msg.sol_in[73].flags
                );
                assert_eq!(
                    msg.sol_in[73].sensor_type, 240,
                    "incorrect value for sol_in[73].sensor_type, expected 240, is {}",
                    msg.sol_in[73].sensor_type
                );
                assert_eq!(
                    msg.sol_in[74].flags, 3,
                    "incorrect value for sol_in[74].flags, expected 3, is {}",
                    msg.sol_in[74].flags
                );
                assert_eq!(
                    msg.sol_in[74].sensor_type, 59,
                    "incorrect value for sol_in[74].sensor_type, expected 59, is {}",
                    msg.sol_in[74].sensor_type
                );
                assert_eq!(
                    msg.sol_in[75].flags, 52,
                    "incorrect value for sol_in[75].flags, expected 52, is {}",
                    msg.sol_in[75].flags
                );
                assert_eq!(
                    msg.sol_in[75].sensor_type, 230,
                    "incorrect value for sol_in[75].sensor_type, expected 230, is {}",
                    msg.sol_in[75].sensor_type
                );
                assert_eq!(
                    msg.sol_in[76].flags, 148,
                    "incorrect value for sol_in[76].flags, expected 148, is {}",
                    msg.sol_in[76].flags
                );
                assert_eq!(
                    msg.sol_in[76].sensor_type, 149,
                    "incorrect value for sol_in[76].sensor_type, expected 149, is {}",
                    msg.sol_in[76].sensor_type
                );
                assert_eq!(
                    msg.sol_in[77].flags, 142,
                    "incorrect value for sol_in[77].flags, expected 142, is {}",
                    msg.sol_in[77].flags
                );
                assert_eq!(
                    msg.sol_in[77].sensor_type, 218,
                    "incorrect value for sol_in[77].sensor_type, expected 218, is {}",
                    msg.sol_in[77].sensor_type
                );
                assert_eq!(
                    msg.sol_in[78].flags, 109,
                    "incorrect value for sol_in[78].flags, expected 109, is {}",
                    msg.sol_in[78].flags
                );
                assert_eq!(
                    msg.sol_in[78].sensor_type, 212,
                    "incorrect value for sol_in[78].sensor_type, expected 212, is {}",
                    msg.sol_in[78].sensor_type
                );
                assert_eq!(
                    msg.sol_in[79].flags, 71,
                    "incorrect value for sol_in[79].flags, expected 71, is {}",
                    msg.sol_in[79].flags
                );
                assert_eq!(
                    msg.sol_in[79].sensor_type, 176,
                    "incorrect value for sol_in[79].sensor_type, expected 176, is {}",
                    msg.sol_in[79].sensor_type
                );
                assert_eq!(
                    msg.sol_in[80].flags, 172,
                    "incorrect value for sol_in[80].flags, expected 172, is {}",
                    msg.sol_in[80].flags
                );
                assert_eq!(
                    msg.sol_in[80].sensor_type, 179,
                    "incorrect value for sol_in[80].sensor_type, expected 179, is {}",
                    msg.sol_in[80].sensor_type
                );
                assert_eq!(
                    msg.sol_in[81].flags, 1,
                    "incorrect value for sol_in[81].flags, expected 1, is {}",
                    msg.sol_in[81].flags
                );
                assert_eq!(
                    msg.sol_in[81].sensor_type, 77,
                    "incorrect value for sol_in[81].sensor_type, expected 77, is {}",
                    msg.sol_in[81].sensor_type
                );
                assert_eq!(
                    msg.sol_in[82].flags, 70,
                    "incorrect value for sol_in[82].flags, expected 70, is {}",
                    msg.sol_in[82].flags
                );
                assert_eq!(
                    msg.sol_in[82].sensor_type, 193,
                    "incorrect value for sol_in[82].sensor_type, expected 193, is {}",
                    msg.sol_in[82].sensor_type
                );
                assert_eq!(
                    msg.sol_in[83].flags, 149,
                    "incorrect value for sol_in[83].flags, expected 149, is {}",
                    msg.sol_in[83].flags
                );
                assert_eq!(
                    msg.sol_in[83].sensor_type, 147,
                    "incorrect value for sol_in[83].sensor_type, expected 147, is {}",
                    msg.sol_in[83].sensor_type
                );
                assert_eq!(
                    msg.sol_in[84].flags, 144,
                    "incorrect value for sol_in[84].flags, expected 144, is {}",
                    msg.sol_in[84].flags
                );
                assert_eq!(
                    msg.sol_in[84].sensor_type, 23,
                    "incorrect value for sol_in[84].sensor_type, expected 23, is {}",
                    msg.sol_in[84].sensor_type
                );
                assert_eq!(
                    msg.sol_in[85].flags, 239,
                    "incorrect value for sol_in[85].flags, expected 239, is {}",
                    msg.sol_in[85].flags
                );
                assert_eq!(
                    msg.sol_in[85].sensor_type, 148,
                    "incorrect value for sol_in[85].sensor_type, expected 148, is {}",
                    msg.sol_in[85].sensor_type
                );
                assert_eq!(
                    msg.sol_in[86].flags, 186,
                    "incorrect value for sol_in[86].flags, expected 186, is {}",
                    msg.sol_in[86].flags
                );
                assert_eq!(
                    msg.sol_in[86].sensor_type, 195,
                    "incorrect value for sol_in[86].sensor_type, expected 195, is {}",
                    msg.sol_in[86].sensor_type
                );
                assert_eq!(
                    msg.sol_in[87].flags, 30,
                    "incorrect value for sol_in[87].flags, expected 30, is {}",
                    msg.sol_in[87].flags
                );
                assert_eq!(
                    msg.sol_in[87].sensor_type, 86,
                    "incorrect value for sol_in[87].sensor_type, expected 86, is {}",
                    msg.sol_in[87].sensor_type
                );
                assert_eq!(
                    msg.sol_in[88].flags, 143,
                    "incorrect value for sol_in[88].flags, expected 143, is {}",
                    msg.sol_in[88].flags
                );
                assert_eq!(
                    msg.sol_in[88].sensor_type, 34,
                    "incorrect value for sol_in[88].sensor_type, expected 34, is {}",
                    msg.sol_in[88].sensor_type
                );
                assert_eq!(
                    msg.sol_in[89].flags, 207,
                    "incorrect value for sol_in[89].flags, expected 207, is {}",
                    msg.sol_in[89].flags
                );
                assert_eq!(
                    msg.sol_in[89].sensor_type, 156,
                    "incorrect value for sol_in[89].sensor_type, expected 156, is {}",
                    msg.sol_in[89].sensor_type
                );
                assert_eq!(
                    msg.sol_in[90].flags, 55,
                    "incorrect value for sol_in[90].flags, expected 55, is {}",
                    msg.sol_in[90].flags
                );
                assert_eq!(
                    msg.sol_in[90].sensor_type, 63,
                    "incorrect value for sol_in[90].sensor_type, expected 63, is {}",
                    msg.sol_in[90].sensor_type
                );
                assert_eq!(
                    msg.sol_in[91].flags, 255,
                    "incorrect value for sol_in[91].flags, expected 255, is {}",
                    msg.sol_in[91].flags
                );
                assert_eq!(
                    msg.sol_in[91].sensor_type, 117,
                    "incorrect value for sol_in[91].sensor_type, expected 117, is {}",
                    msg.sol_in[91].sensor_type
                );
                assert_eq!(
                    msg.sol_in[92].flags, 222,
                    "incorrect value for sol_in[92].flags, expected 222, is {}",
                    msg.sol_in[92].flags
                );
                assert_eq!(
                    msg.sol_in[92].sensor_type, 222,
                    "incorrect value for sol_in[92].sensor_type, expected 222, is {}",
                    msg.sol_in[92].sensor_type
                );
                assert_eq!(
                    msg.sol_in[93].flags, 145,
                    "incorrect value for sol_in[93].flags, expected 145, is {}",
                    msg.sol_in[93].flags
                );
                assert_eq!(
                    msg.sol_in[93].sensor_type, 219,
                    "incorrect value for sol_in[93].sensor_type, expected 219, is {}",
                    msg.sol_in[93].sensor_type
                );
                assert_eq!(
                    msg.sol_in[94].flags, 191,
                    "incorrect value for sol_in[94].flags, expected 191, is {}",
                    msg.sol_in[94].flags
                );
                assert_eq!(
                    msg.sol_in[94].sensor_type, 224,
                    "incorrect value for sol_in[94].sensor_type, expected 224, is {}",
                    msg.sol_in[94].sensor_type
                );
                assert_eq!(
                    msg.sol_in[95].flags, 109,
                    "incorrect value for sol_in[95].flags, expected 109, is {}",
                    msg.sol_in[95].flags
                );
                assert_eq!(
                    msg.sol_in[95].sensor_type, 210,
                    "incorrect value for sol_in[95].sensor_type, expected 210, is {}",
                    msg.sol_in[95].sensor_type
                );
                assert_eq!(
                    msg.sol_in[96].flags, 153,
                    "incorrect value for sol_in[96].flags, expected 153, is {}",
                    msg.sol_in[96].flags
                );
                assert_eq!(
                    msg.sol_in[96].sensor_type, 86,
                    "incorrect value for sol_in[96].sensor_type, expected 86, is {}",
                    msg.sol_in[96].sensor_type
                );
                assert_eq!(
                    msg.sol_in[97].flags, 32,
                    "incorrect value for sol_in[97].flags, expected 32, is {}",
                    msg.sol_in[97].flags
                );
                assert_eq!(
                    msg.sol_in[97].sensor_type, 21,
                    "incorrect value for sol_in[97].sensor_type, expected 21, is {}",
                    msg.sol_in[97].sensor_type
                );
                assert_eq!(
                    msg.sol_in[98].flags, 10,
                    "incorrect value for sol_in[98].flags, expected 10, is {}",
                    msg.sol_in[98].flags
                );
                assert_eq!(
                    msg.sol_in[98].sensor_type, 226,
                    "incorrect value for sol_in[98].sensor_type, expected 226, is {}",
                    msg.sol_in[98].sensor_type
                );
                assert_eq!(
                    msg.sol_in[99].flags, 63,
                    "incorrect value for sol_in[99].flags, expected 63, is {}",
                    msg.sol_in[99].flags
                );
                assert_eq!(
                    msg.sol_in[99].sensor_type, 60,
                    "incorrect value for sol_in[99].sensor_type, expected 60, is {}",
                    msg.sol_in[99].sensor_type
                );
                assert_eq!(
                    msg.sol_in[100].flags, 236,
                    "incorrect value for sol_in[100].flags, expected 236, is {}",
                    msg.sol_in[100].flags
                );
                assert_eq!(
                    msg.sol_in[100].sensor_type, 106,
                    "incorrect value for sol_in[100].sensor_type, expected 106, is {}",
                    msg.sol_in[100].sensor_type
                );
                assert_eq!(
                    msg.sol_in[101].flags, 96,
                    "incorrect value for sol_in[101].flags, expected 96, is {}",
                    msg.sol_in[101].flags
                );
                assert_eq!(
                    msg.sol_in[101].sensor_type, 93,
                    "incorrect value for sol_in[101].sensor_type, expected 93, is {}",
                    msg.sol_in[101].sensor_type
                );
                assert_eq!(
                    msg.sol_in[102].flags, 163,
                    "incorrect value for sol_in[102].flags, expected 163, is {}",
                    msg.sol_in[102].flags
                );
                assert_eq!(
                    msg.sol_in[102].sensor_type, 30,
                    "incorrect value for sol_in[102].sensor_type, expected 30, is {}",
                    msg.sol_in[102].sensor_type
                );
                assert_eq!(
                    msg.sol_in[103].flags, 238,
                    "incorrect value for sol_in[103].flags, expected 238, is {}",
                    msg.sol_in[103].flags
                );
                assert_eq!(
                    msg.sol_in[103].sensor_type, 106,
                    "incorrect value for sol_in[103].sensor_type, expected 106, is {}",
                    msg.sol_in[103].sensor_type
                );
                assert_eq!(
                    msg.sol_in[104].flags, 133,
                    "incorrect value for sol_in[104].flags, expected 133, is {}",
                    msg.sol_in[104].flags
                );
                assert_eq!(
                    msg.sol_in[104].sensor_type, 147,
                    "incorrect value for sol_in[104].sensor_type, expected 147, is {}",
                    msg.sol_in[104].sensor_type
                );
                assert_eq!(
                    msg.sol_in[105].flags, 107,
                    "incorrect value for sol_in[105].flags, expected 107, is {}",
                    msg.sol_in[105].flags
                );
                assert_eq!(
                    msg.sol_in[105].sensor_type, 132,
                    "incorrect value for sol_in[105].sensor_type, expected 132, is {}",
                    msg.sol_in[105].sensor_type
                );
                assert_eq!(
                    msg.sol_in[106].flags, 214,
                    "incorrect value for sol_in[106].flags, expected 214, is {}",
                    msg.sol_in[106].flags
                );
                assert_eq!(
                    msg.sol_in[106].sensor_type, 152,
                    "incorrect value for sol_in[106].sensor_type, expected 152, is {}",
                    msg.sol_in[106].sensor_type
                );
                assert_eq!(
                    msg.sol_in[107].flags, 185,
                    "incorrect value for sol_in[107].flags, expected 185, is {}",
                    msg.sol_in[107].flags
                );
                assert_eq!(
                    msg.sol_in[107].sensor_type, 221,
                    "incorrect value for sol_in[107].sensor_type, expected 221, is {}",
                    msg.sol_in[107].sensor_type
                );
                assert_eq!(
                    msg.sol_in[108].flags, 21,
                    "incorrect value for sol_in[108].flags, expected 21, is {}",
                    msg.sol_in[108].flags
                );
                assert_eq!(
                    msg.sol_in[108].sensor_type, 202,
                    "incorrect value for sol_in[108].sensor_type, expected 202, is {}",
                    msg.sol_in[108].sensor_type
                );
                assert_eq!(
                    msg.sol_in[109].flags, 51,
                    "incorrect value for sol_in[109].flags, expected 51, is {}",
                    msg.sol_in[109].flags
                );
                assert_eq!(
                    msg.sol_in[109].sensor_type, 252,
                    "incorrect value for sol_in[109].sensor_type, expected 252, is {}",
                    msg.sol_in[109].sensor_type
                );
                assert_eq!(
                    msg.sol_in[110].flags, 59,
                    "incorrect value for sol_in[110].flags, expected 59, is {}",
                    msg.sol_in[110].flags
                );
                assert_eq!(
                    msg.sol_in[110].sensor_type, 130,
                    "incorrect value for sol_in[110].sensor_type, expected 130, is {}",
                    msg.sol_in[110].sensor_type
                );
                assert_eq!(
                    msg.sol_in[111].flags, 202,
                    "incorrect value for sol_in[111].flags, expected 202, is {}",
                    msg.sol_in[111].flags
                );
                assert_eq!(
                    msg.sol_in[111].sensor_type, 166,
                    "incorrect value for sol_in[111].sensor_type, expected 166, is {}",
                    msg.sol_in[111].sensor_type
                );
                assert_eq!(
                    msg.sol_in[112].flags, 170,
                    "incorrect value for sol_in[112].flags, expected 170, is {}",
                    msg.sol_in[112].flags
                );
                assert_eq!(
                    msg.sol_in[112].sensor_type, 127,
                    "incorrect value for sol_in[112].sensor_type, expected 127, is {}",
                    msg.sol_in[112].sensor_type
                );
                assert_eq!(
                    msg.sol_in[113].flags, 193,
                    "incorrect value for sol_in[113].flags, expected 193, is {}",
                    msg.sol_in[113].flags
                );
                assert_eq!(
                    msg.sol_in[113].sensor_type, 58,
                    "incorrect value for sol_in[113].sensor_type, expected 58, is {}",
                    msg.sol_in[113].sensor_type
                );
                assert_eq!(
                    msg.sol_in[114].flags, 125,
                    "incorrect value for sol_in[114].flags, expected 125, is {}",
                    msg.sol_in[114].flags
                );
                assert_eq!(
                    msg.sol_in[114].sensor_type, 215,
                    "incorrect value for sol_in[114].sensor_type, expected 215, is {}",
                    msg.sol_in[114].sensor_type
                );
                assert_eq!(
                    msg.sol_in[115].flags, 58,
                    "incorrect value for sol_in[115].flags, expected 58, is {}",
                    msg.sol_in[115].flags
                );
                assert_eq!(
                    msg.sol_in[115].sensor_type, 22,
                    "incorrect value for sol_in[115].sensor_type, expected 22, is {}",
                    msg.sol_in[115].sensor_type
                );
                assert_eq!(
                    msg.sol_in[116].flags, 47,
                    "incorrect value for sol_in[116].flags, expected 47, is {}",
                    msg.sol_in[116].flags
                );
                assert_eq!(
                    msg.sol_in[116].sensor_type, 135,
                    "incorrect value for sol_in[116].sensor_type, expected 135, is {}",
                    msg.sol_in[116].sensor_type
                );
                assert_eq!(
                    msg.sol_in[117].flags, 142,
                    "incorrect value for sol_in[117].flags, expected 142, is {}",
                    msg.sol_in[117].flags
                );
                assert_eq!(
                    msg.sol_in[117].sensor_type, 88,
                    "incorrect value for sol_in[117].sensor_type, expected 88, is {}",
                    msg.sol_in[117].sensor_type
                );
                assert_eq!(
                    msg.vdop, 41989,
                    "incorrect value for vdop, expected 41989, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSolnMetaDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
