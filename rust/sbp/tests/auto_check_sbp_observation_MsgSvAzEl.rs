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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgSvAzEl.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_observation_MsgSvAzEl() {
    {
        let mut payload = Cursor::new(vec![
            85, 151, 0, 207, 121, 132, 8, 0, 160, 12, 10, 0, 139, 66, 13, 0, 16, 1, 15, 0, 24, 25,
            16, 0, 127, 18, 18, 0, 42, 53, 20, 0, 31, 16, 23, 0, 12, 67, 24, 0, 47, 10, 26, 0, 116,
            8, 27, 0, 153, 43, 29, 0, 77, 10, 32, 0, 94, 26, 1, 3, 16, 58, 2, 3, 108, 53, 8, 3, 17,
            13, 17, 3, 165, 40, 23, 3, 63, 35, 24, 3, 41, 73, 20, 12, 114, 26, 27, 12, 72, 54, 28,
            12, 69, 3, 29, 12, 158, 14, 30, 12, 152, 68, 32, 12, 120, 82, 2, 14, 131, 6, 4, 14, 27,
            44, 5, 14, 101, 21, 9, 14, 81, 65, 11, 14, 49, 56, 12, 14, 59, 6, 30, 14, 154, 4, 36,
            14, 165, 62, 168, 36,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgSvAzEl(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x97,
                    "Incorrect message type, expected 0x97, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x79CF,
                    "incorrect sender id, expected 0x79CF, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.azel[0].az, 160,
                    "incorrect value for azel[0].az, expected 160, is {}",
                    msg.azel[0].az
                );
                assert_eq!(
                    msg.azel[0].el, 12,
                    "incorrect value for azel[0].el, expected 12, is {}",
                    msg.azel[0].el
                );
                assert_eq!(
                    msg.azel[0].sid.code, 0,
                    "incorrect value for azel[0].sid.code, expected 0, is {}",
                    msg.azel[0].sid.code
                );
                assert_eq!(
                    msg.azel[0].sid.sat, 8,
                    "incorrect value for azel[0].sid.sat, expected 8, is {}",
                    msg.azel[0].sid.sat
                );
                assert_eq!(
                    msg.azel[1].az, 139,
                    "incorrect value for azel[1].az, expected 139, is {}",
                    msg.azel[1].az
                );
                assert_eq!(
                    msg.azel[1].el, 66,
                    "incorrect value for azel[1].el, expected 66, is {}",
                    msg.azel[1].el
                );
                assert_eq!(
                    msg.azel[1].sid.code, 0,
                    "incorrect value for azel[1].sid.code, expected 0, is {}",
                    msg.azel[1].sid.code
                );
                assert_eq!(
                    msg.azel[1].sid.sat, 10,
                    "incorrect value for azel[1].sid.sat, expected 10, is {}",
                    msg.azel[1].sid.sat
                );
                assert_eq!(
                    msg.azel[2].az, 16,
                    "incorrect value for azel[2].az, expected 16, is {}",
                    msg.azel[2].az
                );
                assert_eq!(
                    msg.azel[2].el, 1,
                    "incorrect value for azel[2].el, expected 1, is {}",
                    msg.azel[2].el
                );
                assert_eq!(
                    msg.azel[2].sid.code, 0,
                    "incorrect value for azel[2].sid.code, expected 0, is {}",
                    msg.azel[2].sid.code
                );
                assert_eq!(
                    msg.azel[2].sid.sat, 13,
                    "incorrect value for azel[2].sid.sat, expected 13, is {}",
                    msg.azel[2].sid.sat
                );
                assert_eq!(
                    msg.azel[3].az, 24,
                    "incorrect value for azel[3].az, expected 24, is {}",
                    msg.azel[3].az
                );
                assert_eq!(
                    msg.azel[3].el, 25,
                    "incorrect value for azel[3].el, expected 25, is {}",
                    msg.azel[3].el
                );
                assert_eq!(
                    msg.azel[3].sid.code, 0,
                    "incorrect value for azel[3].sid.code, expected 0, is {}",
                    msg.azel[3].sid.code
                );
                assert_eq!(
                    msg.azel[3].sid.sat, 15,
                    "incorrect value for azel[3].sid.sat, expected 15, is {}",
                    msg.azel[3].sid.sat
                );
                assert_eq!(
                    msg.azel[4].az, 127,
                    "incorrect value for azel[4].az, expected 127, is {}",
                    msg.azel[4].az
                );
                assert_eq!(
                    msg.azel[4].el, 18,
                    "incorrect value for azel[4].el, expected 18, is {}",
                    msg.azel[4].el
                );
                assert_eq!(
                    msg.azel[4].sid.code, 0,
                    "incorrect value for azel[4].sid.code, expected 0, is {}",
                    msg.azel[4].sid.code
                );
                assert_eq!(
                    msg.azel[4].sid.sat, 16,
                    "incorrect value for azel[4].sid.sat, expected 16, is {}",
                    msg.azel[4].sid.sat
                );
                assert_eq!(
                    msg.azel[5].az, 42,
                    "incorrect value for azel[5].az, expected 42, is {}",
                    msg.azel[5].az
                );
                assert_eq!(
                    msg.azel[5].el, 53,
                    "incorrect value for azel[5].el, expected 53, is {}",
                    msg.azel[5].el
                );
                assert_eq!(
                    msg.azel[5].sid.code, 0,
                    "incorrect value for azel[5].sid.code, expected 0, is {}",
                    msg.azel[5].sid.code
                );
                assert_eq!(
                    msg.azel[5].sid.sat, 18,
                    "incorrect value for azel[5].sid.sat, expected 18, is {}",
                    msg.azel[5].sid.sat
                );
                assert_eq!(
                    msg.azel[6].az, 31,
                    "incorrect value for azel[6].az, expected 31, is {}",
                    msg.azel[6].az
                );
                assert_eq!(
                    msg.azel[6].el, 16,
                    "incorrect value for azel[6].el, expected 16, is {}",
                    msg.azel[6].el
                );
                assert_eq!(
                    msg.azel[6].sid.code, 0,
                    "incorrect value for azel[6].sid.code, expected 0, is {}",
                    msg.azel[6].sid.code
                );
                assert_eq!(
                    msg.azel[6].sid.sat, 20,
                    "incorrect value for azel[6].sid.sat, expected 20, is {}",
                    msg.azel[6].sid.sat
                );
                assert_eq!(
                    msg.azel[7].az, 12,
                    "incorrect value for azel[7].az, expected 12, is {}",
                    msg.azel[7].az
                );
                assert_eq!(
                    msg.azel[7].el, 67,
                    "incorrect value for azel[7].el, expected 67, is {}",
                    msg.azel[7].el
                );
                assert_eq!(
                    msg.azel[7].sid.code, 0,
                    "incorrect value for azel[7].sid.code, expected 0, is {}",
                    msg.azel[7].sid.code
                );
                assert_eq!(
                    msg.azel[7].sid.sat, 23,
                    "incorrect value for azel[7].sid.sat, expected 23, is {}",
                    msg.azel[7].sid.sat
                );
                assert_eq!(
                    msg.azel[8].az, 47,
                    "incorrect value for azel[8].az, expected 47, is {}",
                    msg.azel[8].az
                );
                assert_eq!(
                    msg.azel[8].el, 10,
                    "incorrect value for azel[8].el, expected 10, is {}",
                    msg.azel[8].el
                );
                assert_eq!(
                    msg.azel[8].sid.code, 0,
                    "incorrect value for azel[8].sid.code, expected 0, is {}",
                    msg.azel[8].sid.code
                );
                assert_eq!(
                    msg.azel[8].sid.sat, 24,
                    "incorrect value for azel[8].sid.sat, expected 24, is {}",
                    msg.azel[8].sid.sat
                );
                assert_eq!(
                    msg.azel[9].az, 116,
                    "incorrect value for azel[9].az, expected 116, is {}",
                    msg.azel[9].az
                );
                assert_eq!(
                    msg.azel[9].el, 8,
                    "incorrect value for azel[9].el, expected 8, is {}",
                    msg.azel[9].el
                );
                assert_eq!(
                    msg.azel[9].sid.code, 0,
                    "incorrect value for azel[9].sid.code, expected 0, is {}",
                    msg.azel[9].sid.code
                );
                assert_eq!(
                    msg.azel[9].sid.sat, 26,
                    "incorrect value for azel[9].sid.sat, expected 26, is {}",
                    msg.azel[9].sid.sat
                );
                assert_eq!(
                    msg.azel[10].az, 153,
                    "incorrect value for azel[10].az, expected 153, is {}",
                    msg.azel[10].az
                );
                assert_eq!(
                    msg.azel[10].el, 43,
                    "incorrect value for azel[10].el, expected 43, is {}",
                    msg.azel[10].el
                );
                assert_eq!(
                    msg.azel[10].sid.code, 0,
                    "incorrect value for azel[10].sid.code, expected 0, is {}",
                    msg.azel[10].sid.code
                );
                assert_eq!(
                    msg.azel[10].sid.sat, 27,
                    "incorrect value for azel[10].sid.sat, expected 27, is {}",
                    msg.azel[10].sid.sat
                );
                assert_eq!(
                    msg.azel[11].az, 77,
                    "incorrect value for azel[11].az, expected 77, is {}",
                    msg.azel[11].az
                );
                assert_eq!(
                    msg.azel[11].el, 10,
                    "incorrect value for azel[11].el, expected 10, is {}",
                    msg.azel[11].el
                );
                assert_eq!(
                    msg.azel[11].sid.code, 0,
                    "incorrect value for azel[11].sid.code, expected 0, is {}",
                    msg.azel[11].sid.code
                );
                assert_eq!(
                    msg.azel[11].sid.sat, 29,
                    "incorrect value for azel[11].sid.sat, expected 29, is {}",
                    msg.azel[11].sid.sat
                );
                assert_eq!(
                    msg.azel[12].az, 94,
                    "incorrect value for azel[12].az, expected 94, is {}",
                    msg.azel[12].az
                );
                assert_eq!(
                    msg.azel[12].el, 26,
                    "incorrect value for azel[12].el, expected 26, is {}",
                    msg.azel[12].el
                );
                assert_eq!(
                    msg.azel[12].sid.code, 0,
                    "incorrect value for azel[12].sid.code, expected 0, is {}",
                    msg.azel[12].sid.code
                );
                assert_eq!(
                    msg.azel[12].sid.sat, 32,
                    "incorrect value for azel[12].sid.sat, expected 32, is {}",
                    msg.azel[12].sid.sat
                );
                assert_eq!(
                    msg.azel[13].az, 16,
                    "incorrect value for azel[13].az, expected 16, is {}",
                    msg.azel[13].az
                );
                assert_eq!(
                    msg.azel[13].el, 58,
                    "incorrect value for azel[13].el, expected 58, is {}",
                    msg.azel[13].el
                );
                assert_eq!(
                    msg.azel[13].sid.code, 3,
                    "incorrect value for azel[13].sid.code, expected 3, is {}",
                    msg.azel[13].sid.code
                );
                assert_eq!(
                    msg.azel[13].sid.sat, 1,
                    "incorrect value for azel[13].sid.sat, expected 1, is {}",
                    msg.azel[13].sid.sat
                );
                assert_eq!(
                    msg.azel[14].az, 108,
                    "incorrect value for azel[14].az, expected 108, is {}",
                    msg.azel[14].az
                );
                assert_eq!(
                    msg.azel[14].el, 53,
                    "incorrect value for azel[14].el, expected 53, is {}",
                    msg.azel[14].el
                );
                assert_eq!(
                    msg.azel[14].sid.code, 3,
                    "incorrect value for azel[14].sid.code, expected 3, is {}",
                    msg.azel[14].sid.code
                );
                assert_eq!(
                    msg.azel[14].sid.sat, 2,
                    "incorrect value for azel[14].sid.sat, expected 2, is {}",
                    msg.azel[14].sid.sat
                );
                assert_eq!(
                    msg.azel[15].az, 17,
                    "incorrect value for azel[15].az, expected 17, is {}",
                    msg.azel[15].az
                );
                assert_eq!(
                    msg.azel[15].el, 13,
                    "incorrect value for azel[15].el, expected 13, is {}",
                    msg.azel[15].el
                );
                assert_eq!(
                    msg.azel[15].sid.code, 3,
                    "incorrect value for azel[15].sid.code, expected 3, is {}",
                    msg.azel[15].sid.code
                );
                assert_eq!(
                    msg.azel[15].sid.sat, 8,
                    "incorrect value for azel[15].sid.sat, expected 8, is {}",
                    msg.azel[15].sid.sat
                );
                assert_eq!(
                    msg.azel[16].az, 165,
                    "incorrect value for azel[16].az, expected 165, is {}",
                    msg.azel[16].az
                );
                assert_eq!(
                    msg.azel[16].el, 40,
                    "incorrect value for azel[16].el, expected 40, is {}",
                    msg.azel[16].el
                );
                assert_eq!(
                    msg.azel[16].sid.code, 3,
                    "incorrect value for azel[16].sid.code, expected 3, is {}",
                    msg.azel[16].sid.code
                );
                assert_eq!(
                    msg.azel[16].sid.sat, 17,
                    "incorrect value for azel[16].sid.sat, expected 17, is {}",
                    msg.azel[16].sid.sat
                );
                assert_eq!(
                    msg.azel[17].az, 63,
                    "incorrect value for azel[17].az, expected 63, is {}",
                    msg.azel[17].az
                );
                assert_eq!(
                    msg.azel[17].el, 35,
                    "incorrect value for azel[17].el, expected 35, is {}",
                    msg.azel[17].el
                );
                assert_eq!(
                    msg.azel[17].sid.code, 3,
                    "incorrect value for azel[17].sid.code, expected 3, is {}",
                    msg.azel[17].sid.code
                );
                assert_eq!(
                    msg.azel[17].sid.sat, 23,
                    "incorrect value for azel[17].sid.sat, expected 23, is {}",
                    msg.azel[17].sid.sat
                );
                assert_eq!(
                    msg.azel[18].az, 41,
                    "incorrect value for azel[18].az, expected 41, is {}",
                    msg.azel[18].az
                );
                assert_eq!(
                    msg.azel[18].el, 73,
                    "incorrect value for azel[18].el, expected 73, is {}",
                    msg.azel[18].el
                );
                assert_eq!(
                    msg.azel[18].sid.code, 3,
                    "incorrect value for azel[18].sid.code, expected 3, is {}",
                    msg.azel[18].sid.code
                );
                assert_eq!(
                    msg.azel[18].sid.sat, 24,
                    "incorrect value for azel[18].sid.sat, expected 24, is {}",
                    msg.azel[18].sid.sat
                );
                assert_eq!(
                    msg.azel[19].az, 114,
                    "incorrect value for azel[19].az, expected 114, is {}",
                    msg.azel[19].az
                );
                assert_eq!(
                    msg.azel[19].el, 26,
                    "incorrect value for azel[19].el, expected 26, is {}",
                    msg.azel[19].el
                );
                assert_eq!(
                    msg.azel[19].sid.code, 12,
                    "incorrect value for azel[19].sid.code, expected 12, is {}",
                    msg.azel[19].sid.code
                );
                assert_eq!(
                    msg.azel[19].sid.sat, 20,
                    "incorrect value for azel[19].sid.sat, expected 20, is {}",
                    msg.azel[19].sid.sat
                );
                assert_eq!(
                    msg.azel[20].az, 72,
                    "incorrect value for azel[20].az, expected 72, is {}",
                    msg.azel[20].az
                );
                assert_eq!(
                    msg.azel[20].el, 54,
                    "incorrect value for azel[20].el, expected 54, is {}",
                    msg.azel[20].el
                );
                assert_eq!(
                    msg.azel[20].sid.code, 12,
                    "incorrect value for azel[20].sid.code, expected 12, is {}",
                    msg.azel[20].sid.code
                );
                assert_eq!(
                    msg.azel[20].sid.sat, 27,
                    "incorrect value for azel[20].sid.sat, expected 27, is {}",
                    msg.azel[20].sid.sat
                );
                assert_eq!(
                    msg.azel[21].az, 69,
                    "incorrect value for azel[21].az, expected 69, is {}",
                    msg.azel[21].az
                );
                assert_eq!(
                    msg.azel[21].el, 3,
                    "incorrect value for azel[21].el, expected 3, is {}",
                    msg.azel[21].el
                );
                assert_eq!(
                    msg.azel[21].sid.code, 12,
                    "incorrect value for azel[21].sid.code, expected 12, is {}",
                    msg.azel[21].sid.code
                );
                assert_eq!(
                    msg.azel[21].sid.sat, 28,
                    "incorrect value for azel[21].sid.sat, expected 28, is {}",
                    msg.azel[21].sid.sat
                );
                assert_eq!(
                    msg.azel[22].az, 158,
                    "incorrect value for azel[22].az, expected 158, is {}",
                    msg.azel[22].az
                );
                assert_eq!(
                    msg.azel[22].el, 14,
                    "incorrect value for azel[22].el, expected 14, is {}",
                    msg.azel[22].el
                );
                assert_eq!(
                    msg.azel[22].sid.code, 12,
                    "incorrect value for azel[22].sid.code, expected 12, is {}",
                    msg.azel[22].sid.code
                );
                assert_eq!(
                    msg.azel[22].sid.sat, 29,
                    "incorrect value for azel[22].sid.sat, expected 29, is {}",
                    msg.azel[22].sid.sat
                );
                assert_eq!(
                    msg.azel[23].az, 152,
                    "incorrect value for azel[23].az, expected 152, is {}",
                    msg.azel[23].az
                );
                assert_eq!(
                    msg.azel[23].el, 68,
                    "incorrect value for azel[23].el, expected 68, is {}",
                    msg.azel[23].el
                );
                assert_eq!(
                    msg.azel[23].sid.code, 12,
                    "incorrect value for azel[23].sid.code, expected 12, is {}",
                    msg.azel[23].sid.code
                );
                assert_eq!(
                    msg.azel[23].sid.sat, 30,
                    "incorrect value for azel[23].sid.sat, expected 30, is {}",
                    msg.azel[23].sid.sat
                );
                assert_eq!(
                    msg.azel[24].az, 120,
                    "incorrect value for azel[24].az, expected 120, is {}",
                    msg.azel[24].az
                );
                assert_eq!(
                    msg.azel[24].el, 82,
                    "incorrect value for azel[24].el, expected 82, is {}",
                    msg.azel[24].el
                );
                assert_eq!(
                    msg.azel[24].sid.code, 12,
                    "incorrect value for azel[24].sid.code, expected 12, is {}",
                    msg.azel[24].sid.code
                );
                assert_eq!(
                    msg.azel[24].sid.sat, 32,
                    "incorrect value for azel[24].sid.sat, expected 32, is {}",
                    msg.azel[24].sid.sat
                );
                assert_eq!(
                    msg.azel[25].az, 131,
                    "incorrect value for azel[25].az, expected 131, is {}",
                    msg.azel[25].az
                );
                assert_eq!(
                    msg.azel[25].el, 6,
                    "incorrect value for azel[25].el, expected 6, is {}",
                    msg.azel[25].el
                );
                assert_eq!(
                    msg.azel[25].sid.code, 14,
                    "incorrect value for azel[25].sid.code, expected 14, is {}",
                    msg.azel[25].sid.code
                );
                assert_eq!(
                    msg.azel[25].sid.sat, 2,
                    "incorrect value for azel[25].sid.sat, expected 2, is {}",
                    msg.azel[25].sid.sat
                );
                assert_eq!(
                    msg.azel[26].az, 27,
                    "incorrect value for azel[26].az, expected 27, is {}",
                    msg.azel[26].az
                );
                assert_eq!(
                    msg.azel[26].el, 44,
                    "incorrect value for azel[26].el, expected 44, is {}",
                    msg.azel[26].el
                );
                assert_eq!(
                    msg.azel[26].sid.code, 14,
                    "incorrect value for azel[26].sid.code, expected 14, is {}",
                    msg.azel[26].sid.code
                );
                assert_eq!(
                    msg.azel[26].sid.sat, 4,
                    "incorrect value for azel[26].sid.sat, expected 4, is {}",
                    msg.azel[26].sid.sat
                );
                assert_eq!(
                    msg.azel[27].az, 101,
                    "incorrect value for azel[27].az, expected 101, is {}",
                    msg.azel[27].az
                );
                assert_eq!(
                    msg.azel[27].el, 21,
                    "incorrect value for azel[27].el, expected 21, is {}",
                    msg.azel[27].el
                );
                assert_eq!(
                    msg.azel[27].sid.code, 14,
                    "incorrect value for azel[27].sid.code, expected 14, is {}",
                    msg.azel[27].sid.code
                );
                assert_eq!(
                    msg.azel[27].sid.sat, 5,
                    "incorrect value for azel[27].sid.sat, expected 5, is {}",
                    msg.azel[27].sid.sat
                );
                assert_eq!(
                    msg.azel[28].az, 81,
                    "incorrect value for azel[28].az, expected 81, is {}",
                    msg.azel[28].az
                );
                assert_eq!(
                    msg.azel[28].el, 65,
                    "incorrect value for azel[28].el, expected 65, is {}",
                    msg.azel[28].el
                );
                assert_eq!(
                    msg.azel[28].sid.code, 14,
                    "incorrect value for azel[28].sid.code, expected 14, is {}",
                    msg.azel[28].sid.code
                );
                assert_eq!(
                    msg.azel[28].sid.sat, 9,
                    "incorrect value for azel[28].sid.sat, expected 9, is {}",
                    msg.azel[28].sid.sat
                );
                assert_eq!(
                    msg.azel[29].az, 49,
                    "incorrect value for azel[29].az, expected 49, is {}",
                    msg.azel[29].az
                );
                assert_eq!(
                    msg.azel[29].el, 56,
                    "incorrect value for azel[29].el, expected 56, is {}",
                    msg.azel[29].el
                );
                assert_eq!(
                    msg.azel[29].sid.code, 14,
                    "incorrect value for azel[29].sid.code, expected 14, is {}",
                    msg.azel[29].sid.code
                );
                assert_eq!(
                    msg.azel[29].sid.sat, 11,
                    "incorrect value for azel[29].sid.sat, expected 11, is {}",
                    msg.azel[29].sid.sat
                );
                assert_eq!(
                    msg.azel[30].az, 59,
                    "incorrect value for azel[30].az, expected 59, is {}",
                    msg.azel[30].az
                );
                assert_eq!(
                    msg.azel[30].el, 6,
                    "incorrect value for azel[30].el, expected 6, is {}",
                    msg.azel[30].el
                );
                assert_eq!(
                    msg.azel[30].sid.code, 14,
                    "incorrect value for azel[30].sid.code, expected 14, is {}",
                    msg.azel[30].sid.code
                );
                assert_eq!(
                    msg.azel[30].sid.sat, 12,
                    "incorrect value for azel[30].sid.sat, expected 12, is {}",
                    msg.azel[30].sid.sat
                );
                assert_eq!(
                    msg.azel[31].az, 154,
                    "incorrect value for azel[31].az, expected 154, is {}",
                    msg.azel[31].az
                );
                assert_eq!(
                    msg.azel[31].el, 4,
                    "incorrect value for azel[31].el, expected 4, is {}",
                    msg.azel[31].el
                );
                assert_eq!(
                    msg.azel[31].sid.code, 14,
                    "incorrect value for azel[31].sid.code, expected 14, is {}",
                    msg.azel[31].sid.code
                );
                assert_eq!(
                    msg.azel[31].sid.sat, 30,
                    "incorrect value for azel[31].sid.sat, expected 30, is {}",
                    msg.azel[31].sid.sat
                );
                assert_eq!(
                    msg.azel[32].az, 165,
                    "incorrect value for azel[32].az, expected 165, is {}",
                    msg.azel[32].az
                );
                assert_eq!(
                    msg.azel[32].el, 62,
                    "incorrect value for azel[32].el, expected 62, is {}",
                    msg.azel[32].el
                );
                assert_eq!(
                    msg.azel[32].sid.code, 14,
                    "incorrect value for azel[32].sid.code, expected 14, is {}",
                    msg.azel[32].sid.code
                );
                assert_eq!(
                    msg.azel[32].sid.sat, 36,
                    "incorrect value for azel[32].sid.sat, expected 36, is {}",
                    msg.azel[32].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSvAzEl"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
