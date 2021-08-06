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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgMeasurementState.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_tracking_MsgMeasurementState() {
    {
        let mut payload = Cursor::new(vec![
            85, 97, 0, 207, 121, 237, 29, 0, 162, 0, 0, 0, 0, 0, 0, 27, 0, 201, 20, 0, 168, 32, 0,
            184, 15, 0, 187, 0, 0, 0, 18, 0, 210, 16, 0, 167, 0, 0, 0, 23, 0, 213, 10, 0, 223, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 131, 2, 202, 27, 1, 192, 15, 1, 165, 29, 1, 146, 32,
            1, 170, 18, 1, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 1, 212, 10, 1, 205, 0, 0, 0, 96, 3,
            230, 0, 0, 0, 101, 3, 214, 103, 3, 212, 104, 3, 209, 106, 3, 157, 102, 3, 230, 0, 0, 0,
            0, 0, 0, 101, 4, 189, 96, 4, 207, 106, 4, 164, 104, 4, 193, 0, 0, 0, 102, 4, 208, 0, 0,
            0, 27, 12, 212, 29, 12, 161, 32, 12, 216, 30, 12, 216, 20, 12, 178, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 36, 14, 203, 0, 0, 0, 5, 14, 158, 4, 14, 194, 11, 14, 192, 9, 14, 207, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 9, 20, 218, 5, 20, 176, 36, 20, 217, 11, 20, 200, 4, 20, 205,
            0, 0, 0, 0, 0, 0, 35, 54,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgMeasurementState(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x61,
                    "Incorrect message type, expected 0x61, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x79CF,
                    "incorrect sender id, expected 0x79CF, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.states[0].cn0, 162,
                    "incorrect value for states[0].cn0, expected 162, is {}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].mesid.code, 0,
                    "incorrect value for states[0].mesid.code, expected 0, is {}",
                    msg.states[0].mesid.code
                );
                assert_eq!(
                    msg.states[0].mesid.sat, 29,
                    "incorrect value for states[0].mesid.sat, expected 29, is {}",
                    msg.states[0].mesid.sat
                );
                assert_eq!(
                    msg.states[1].cn0, 0,
                    "incorrect value for states[1].cn0, expected 0, is {}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].mesid.code, 0,
                    "incorrect value for states[1].mesid.code, expected 0, is {}",
                    msg.states[1].mesid.code
                );
                assert_eq!(
                    msg.states[1].mesid.sat, 0,
                    "incorrect value for states[1].mesid.sat, expected 0, is {}",
                    msg.states[1].mesid.sat
                );
                assert_eq!(
                    msg.states[2].cn0, 0,
                    "incorrect value for states[2].cn0, expected 0, is {}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].mesid.code, 0,
                    "incorrect value for states[2].mesid.code, expected 0, is {}",
                    msg.states[2].mesid.code
                );
                assert_eq!(
                    msg.states[2].mesid.sat, 0,
                    "incorrect value for states[2].mesid.sat, expected 0, is {}",
                    msg.states[2].mesid.sat
                );
                assert_eq!(
                    msg.states[3].cn0, 201,
                    "incorrect value for states[3].cn0, expected 201, is {}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].mesid.code, 0,
                    "incorrect value for states[3].mesid.code, expected 0, is {}",
                    msg.states[3].mesid.code
                );
                assert_eq!(
                    msg.states[3].mesid.sat, 27,
                    "incorrect value for states[3].mesid.sat, expected 27, is {}",
                    msg.states[3].mesid.sat
                );
                assert_eq!(
                    msg.states[4].cn0, 168,
                    "incorrect value for states[4].cn0, expected 168, is {}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].mesid.code, 0,
                    "incorrect value for states[4].mesid.code, expected 0, is {}",
                    msg.states[4].mesid.code
                );
                assert_eq!(
                    msg.states[4].mesid.sat, 20,
                    "incorrect value for states[4].mesid.sat, expected 20, is {}",
                    msg.states[4].mesid.sat
                );
                assert_eq!(
                    msg.states[5].cn0, 184,
                    "incorrect value for states[5].cn0, expected 184, is {}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].mesid.code, 0,
                    "incorrect value for states[5].mesid.code, expected 0, is {}",
                    msg.states[5].mesid.code
                );
                assert_eq!(
                    msg.states[5].mesid.sat, 32,
                    "incorrect value for states[5].mesid.sat, expected 32, is {}",
                    msg.states[5].mesid.sat
                );
                assert_eq!(
                    msg.states[6].cn0, 187,
                    "incorrect value for states[6].cn0, expected 187, is {}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].mesid.code, 0,
                    "incorrect value for states[6].mesid.code, expected 0, is {}",
                    msg.states[6].mesid.code
                );
                assert_eq!(
                    msg.states[6].mesid.sat, 15,
                    "incorrect value for states[6].mesid.sat, expected 15, is {}",
                    msg.states[6].mesid.sat
                );
                assert_eq!(
                    msg.states[7].cn0, 0,
                    "incorrect value for states[7].cn0, expected 0, is {}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].mesid.code, 0,
                    "incorrect value for states[7].mesid.code, expected 0, is {}",
                    msg.states[7].mesid.code
                );
                assert_eq!(
                    msg.states[7].mesid.sat, 0,
                    "incorrect value for states[7].mesid.sat, expected 0, is {}",
                    msg.states[7].mesid.sat
                );
                assert_eq!(
                    msg.states[8].cn0, 210,
                    "incorrect value for states[8].cn0, expected 210, is {}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].mesid.code, 0,
                    "incorrect value for states[8].mesid.code, expected 0, is {}",
                    msg.states[8].mesid.code
                );
                assert_eq!(
                    msg.states[8].mesid.sat, 18,
                    "incorrect value for states[8].mesid.sat, expected 18, is {}",
                    msg.states[8].mesid.sat
                );
                assert_eq!(
                    msg.states[9].cn0, 167,
                    "incorrect value for states[9].cn0, expected 167, is {}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].mesid.code, 0,
                    "incorrect value for states[9].mesid.code, expected 0, is {}",
                    msg.states[9].mesid.code
                );
                assert_eq!(
                    msg.states[9].mesid.sat, 16,
                    "incorrect value for states[9].mesid.sat, expected 16, is {}",
                    msg.states[9].mesid.sat
                );
                assert_eq!(
                    msg.states[10].cn0, 0,
                    "incorrect value for states[10].cn0, expected 0, is {}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].mesid.code, 0,
                    "incorrect value for states[10].mesid.code, expected 0, is {}",
                    msg.states[10].mesid.code
                );
                assert_eq!(
                    msg.states[10].mesid.sat, 0,
                    "incorrect value for states[10].mesid.sat, expected 0, is {}",
                    msg.states[10].mesid.sat
                );
                assert_eq!(
                    msg.states[11].cn0, 213,
                    "incorrect value for states[11].cn0, expected 213, is {}",
                    msg.states[11].cn0
                );
                assert_eq!(
                    msg.states[11].mesid.code, 0,
                    "incorrect value for states[11].mesid.code, expected 0, is {}",
                    msg.states[11].mesid.code
                );
                assert_eq!(
                    msg.states[11].mesid.sat, 23,
                    "incorrect value for states[11].mesid.sat, expected 23, is {}",
                    msg.states[11].mesid.sat
                );
                assert_eq!(
                    msg.states[12].cn0, 223,
                    "incorrect value for states[12].cn0, expected 223, is {}",
                    msg.states[12].cn0
                );
                assert_eq!(
                    msg.states[12].mesid.code, 0,
                    "incorrect value for states[12].mesid.code, expected 0, is {}",
                    msg.states[12].mesid.code
                );
                assert_eq!(
                    msg.states[12].mesid.sat, 10,
                    "incorrect value for states[12].mesid.sat, expected 10, is {}",
                    msg.states[12].mesid.sat
                );
                assert_eq!(
                    msg.states[13].cn0, 0,
                    "incorrect value for states[13].cn0, expected 0, is {}",
                    msg.states[13].cn0
                );
                assert_eq!(
                    msg.states[13].mesid.code, 0,
                    "incorrect value for states[13].mesid.code, expected 0, is {}",
                    msg.states[13].mesid.code
                );
                assert_eq!(
                    msg.states[13].mesid.sat, 0,
                    "incorrect value for states[13].mesid.sat, expected 0, is {}",
                    msg.states[13].mesid.sat
                );
                assert_eq!(
                    msg.states[14].cn0, 0,
                    "incorrect value for states[14].cn0, expected 0, is {}",
                    msg.states[14].cn0
                );
                assert_eq!(
                    msg.states[14].mesid.code, 0,
                    "incorrect value for states[14].mesid.code, expected 0, is {}",
                    msg.states[14].mesid.code
                );
                assert_eq!(
                    msg.states[14].mesid.sat, 0,
                    "incorrect value for states[14].mesid.sat, expected 0, is {}",
                    msg.states[14].mesid.sat
                );
                assert_eq!(
                    msg.states[15].cn0, 0,
                    "incorrect value for states[15].cn0, expected 0, is {}",
                    msg.states[15].cn0
                );
                assert_eq!(
                    msg.states[15].mesid.code, 0,
                    "incorrect value for states[15].mesid.code, expected 0, is {}",
                    msg.states[15].mesid.code
                );
                assert_eq!(
                    msg.states[15].mesid.sat, 0,
                    "incorrect value for states[15].mesid.sat, expected 0, is {}",
                    msg.states[15].mesid.sat
                );
                assert_eq!(
                    msg.states[16].cn0, 0,
                    "incorrect value for states[16].cn0, expected 0, is {}",
                    msg.states[16].cn0
                );
                assert_eq!(
                    msg.states[16].mesid.code, 0,
                    "incorrect value for states[16].mesid.code, expected 0, is {}",
                    msg.states[16].mesid.code
                );
                assert_eq!(
                    msg.states[16].mesid.sat, 0,
                    "incorrect value for states[16].mesid.sat, expected 0, is {}",
                    msg.states[16].mesid.sat
                );
                assert_eq!(
                    msg.states[17].cn0, 202,
                    "incorrect value for states[17].cn0, expected 202, is {}",
                    msg.states[17].cn0
                );
                assert_eq!(
                    msg.states[17].mesid.code, 2,
                    "incorrect value for states[17].mesid.code, expected 2, is {}",
                    msg.states[17].mesid.code
                );
                assert_eq!(
                    msg.states[17].mesid.sat, 131,
                    "incorrect value for states[17].mesid.sat, expected 131, is {}",
                    msg.states[17].mesid.sat
                );
                assert_eq!(
                    msg.states[18].cn0, 192,
                    "incorrect value for states[18].cn0, expected 192, is {}",
                    msg.states[18].cn0
                );
                assert_eq!(
                    msg.states[18].mesid.code, 1,
                    "incorrect value for states[18].mesid.code, expected 1, is {}",
                    msg.states[18].mesid.code
                );
                assert_eq!(
                    msg.states[18].mesid.sat, 27,
                    "incorrect value for states[18].mesid.sat, expected 27, is {}",
                    msg.states[18].mesid.sat
                );
                assert_eq!(
                    msg.states[19].cn0, 165,
                    "incorrect value for states[19].cn0, expected 165, is {}",
                    msg.states[19].cn0
                );
                assert_eq!(
                    msg.states[19].mesid.code, 1,
                    "incorrect value for states[19].mesid.code, expected 1, is {}",
                    msg.states[19].mesid.code
                );
                assert_eq!(
                    msg.states[19].mesid.sat, 15,
                    "incorrect value for states[19].mesid.sat, expected 15, is {}",
                    msg.states[19].mesid.sat
                );
                assert_eq!(
                    msg.states[20].cn0, 146,
                    "incorrect value for states[20].cn0, expected 146, is {}",
                    msg.states[20].cn0
                );
                assert_eq!(
                    msg.states[20].mesid.code, 1,
                    "incorrect value for states[20].mesid.code, expected 1, is {}",
                    msg.states[20].mesid.code
                );
                assert_eq!(
                    msg.states[20].mesid.sat, 29,
                    "incorrect value for states[20].mesid.sat, expected 29, is {}",
                    msg.states[20].mesid.sat
                );
                assert_eq!(
                    msg.states[21].cn0, 170,
                    "incorrect value for states[21].cn0, expected 170, is {}",
                    msg.states[21].cn0
                );
                assert_eq!(
                    msg.states[21].mesid.code, 1,
                    "incorrect value for states[21].mesid.code, expected 1, is {}",
                    msg.states[21].mesid.code
                );
                assert_eq!(
                    msg.states[21].mesid.sat, 32,
                    "incorrect value for states[21].mesid.sat, expected 32, is {}",
                    msg.states[21].mesid.sat
                );
                assert_eq!(
                    msg.states[22].cn0, 201,
                    "incorrect value for states[22].cn0, expected 201, is {}",
                    msg.states[22].cn0
                );
                assert_eq!(
                    msg.states[22].mesid.code, 1,
                    "incorrect value for states[22].mesid.code, expected 1, is {}",
                    msg.states[22].mesid.code
                );
                assert_eq!(
                    msg.states[22].mesid.sat, 18,
                    "incorrect value for states[22].mesid.sat, expected 18, is {}",
                    msg.states[22].mesid.sat
                );
                assert_eq!(
                    msg.states[23].cn0, 0,
                    "incorrect value for states[23].cn0, expected 0, is {}",
                    msg.states[23].cn0
                );
                assert_eq!(
                    msg.states[23].mesid.code, 0,
                    "incorrect value for states[23].mesid.code, expected 0, is {}",
                    msg.states[23].mesid.code
                );
                assert_eq!(
                    msg.states[23].mesid.sat, 0,
                    "incorrect value for states[23].mesid.sat, expected 0, is {}",
                    msg.states[23].mesid.sat
                );
                assert_eq!(
                    msg.states[24].cn0, 0,
                    "incorrect value for states[24].cn0, expected 0, is {}",
                    msg.states[24].cn0
                );
                assert_eq!(
                    msg.states[24].mesid.code, 0,
                    "incorrect value for states[24].mesid.code, expected 0, is {}",
                    msg.states[24].mesid.code
                );
                assert_eq!(
                    msg.states[24].mesid.sat, 0,
                    "incorrect value for states[24].mesid.sat, expected 0, is {}",
                    msg.states[24].mesid.sat
                );
                assert_eq!(
                    msg.states[25].cn0, 0,
                    "incorrect value for states[25].cn0, expected 0, is {}",
                    msg.states[25].cn0
                );
                assert_eq!(
                    msg.states[25].mesid.code, 0,
                    "incorrect value for states[25].mesid.code, expected 0, is {}",
                    msg.states[25].mesid.code
                );
                assert_eq!(
                    msg.states[25].mesid.sat, 0,
                    "incorrect value for states[25].mesid.sat, expected 0, is {}",
                    msg.states[25].mesid.sat
                );
                assert_eq!(
                    msg.states[26].cn0, 212,
                    "incorrect value for states[26].cn0, expected 212, is {}",
                    msg.states[26].cn0
                );
                assert_eq!(
                    msg.states[26].mesid.code, 1,
                    "incorrect value for states[26].mesid.code, expected 1, is {}",
                    msg.states[26].mesid.code
                );
                assert_eq!(
                    msg.states[26].mesid.sat, 23,
                    "incorrect value for states[26].mesid.sat, expected 23, is {}",
                    msg.states[26].mesid.sat
                );
                assert_eq!(
                    msg.states[27].cn0, 205,
                    "incorrect value for states[27].cn0, expected 205, is {}",
                    msg.states[27].cn0
                );
                assert_eq!(
                    msg.states[27].mesid.code, 1,
                    "incorrect value for states[27].mesid.code, expected 1, is {}",
                    msg.states[27].mesid.code
                );
                assert_eq!(
                    msg.states[27].mesid.sat, 10,
                    "incorrect value for states[27].mesid.sat, expected 10, is {}",
                    msg.states[27].mesid.sat
                );
                assert_eq!(
                    msg.states[28].cn0, 0,
                    "incorrect value for states[28].cn0, expected 0, is {}",
                    msg.states[28].cn0
                );
                assert_eq!(
                    msg.states[28].mesid.code, 0,
                    "incorrect value for states[28].mesid.code, expected 0, is {}",
                    msg.states[28].mesid.code
                );
                assert_eq!(
                    msg.states[28].mesid.sat, 0,
                    "incorrect value for states[28].mesid.sat, expected 0, is {}",
                    msg.states[28].mesid.sat
                );
                assert_eq!(
                    msg.states[29].cn0, 230,
                    "incorrect value for states[29].cn0, expected 230, is {}",
                    msg.states[29].cn0
                );
                assert_eq!(
                    msg.states[29].mesid.code, 3,
                    "incorrect value for states[29].mesid.code, expected 3, is {}",
                    msg.states[29].mesid.code
                );
                assert_eq!(
                    msg.states[29].mesid.sat, 96,
                    "incorrect value for states[29].mesid.sat, expected 96, is {}",
                    msg.states[29].mesid.sat
                );
                assert_eq!(
                    msg.states[30].cn0, 0,
                    "incorrect value for states[30].cn0, expected 0, is {}",
                    msg.states[30].cn0
                );
                assert_eq!(
                    msg.states[30].mesid.code, 0,
                    "incorrect value for states[30].mesid.code, expected 0, is {}",
                    msg.states[30].mesid.code
                );
                assert_eq!(
                    msg.states[30].mesid.sat, 0,
                    "incorrect value for states[30].mesid.sat, expected 0, is {}",
                    msg.states[30].mesid.sat
                );
                assert_eq!(
                    msg.states[31].cn0, 214,
                    "incorrect value for states[31].cn0, expected 214, is {}",
                    msg.states[31].cn0
                );
                assert_eq!(
                    msg.states[31].mesid.code, 3,
                    "incorrect value for states[31].mesid.code, expected 3, is {}",
                    msg.states[31].mesid.code
                );
                assert_eq!(
                    msg.states[31].mesid.sat, 101,
                    "incorrect value for states[31].mesid.sat, expected 101, is {}",
                    msg.states[31].mesid.sat
                );
                assert_eq!(
                    msg.states[32].cn0, 212,
                    "incorrect value for states[32].cn0, expected 212, is {}",
                    msg.states[32].cn0
                );
                assert_eq!(
                    msg.states[32].mesid.code, 3,
                    "incorrect value for states[32].mesid.code, expected 3, is {}",
                    msg.states[32].mesid.code
                );
                assert_eq!(
                    msg.states[32].mesid.sat, 103,
                    "incorrect value for states[32].mesid.sat, expected 103, is {}",
                    msg.states[32].mesid.sat
                );
                assert_eq!(
                    msg.states[33].cn0, 209,
                    "incorrect value for states[33].cn0, expected 209, is {}",
                    msg.states[33].cn0
                );
                assert_eq!(
                    msg.states[33].mesid.code, 3,
                    "incorrect value for states[33].mesid.code, expected 3, is {}",
                    msg.states[33].mesid.code
                );
                assert_eq!(
                    msg.states[33].mesid.sat, 104,
                    "incorrect value for states[33].mesid.sat, expected 104, is {}",
                    msg.states[33].mesid.sat
                );
                assert_eq!(
                    msg.states[34].cn0, 157,
                    "incorrect value for states[34].cn0, expected 157, is {}",
                    msg.states[34].cn0
                );
                assert_eq!(
                    msg.states[34].mesid.code, 3,
                    "incorrect value for states[34].mesid.code, expected 3, is {}",
                    msg.states[34].mesid.code
                );
                assert_eq!(
                    msg.states[34].mesid.sat, 106,
                    "incorrect value for states[34].mesid.sat, expected 106, is {}",
                    msg.states[34].mesid.sat
                );
                assert_eq!(
                    msg.states[35].cn0, 230,
                    "incorrect value for states[35].cn0, expected 230, is {}",
                    msg.states[35].cn0
                );
                assert_eq!(
                    msg.states[35].mesid.code, 3,
                    "incorrect value for states[35].mesid.code, expected 3, is {}",
                    msg.states[35].mesid.code
                );
                assert_eq!(
                    msg.states[35].mesid.sat, 102,
                    "incorrect value for states[35].mesid.sat, expected 102, is {}",
                    msg.states[35].mesid.sat
                );
                assert_eq!(
                    msg.states[36].cn0, 0,
                    "incorrect value for states[36].cn0, expected 0, is {}",
                    msg.states[36].cn0
                );
                assert_eq!(
                    msg.states[36].mesid.code, 0,
                    "incorrect value for states[36].mesid.code, expected 0, is {}",
                    msg.states[36].mesid.code
                );
                assert_eq!(
                    msg.states[36].mesid.sat, 0,
                    "incorrect value for states[36].mesid.sat, expected 0, is {}",
                    msg.states[36].mesid.sat
                );
                assert_eq!(
                    msg.states[37].cn0, 0,
                    "incorrect value for states[37].cn0, expected 0, is {}",
                    msg.states[37].cn0
                );
                assert_eq!(
                    msg.states[37].mesid.code, 0,
                    "incorrect value for states[37].mesid.code, expected 0, is {}",
                    msg.states[37].mesid.code
                );
                assert_eq!(
                    msg.states[37].mesid.sat, 0,
                    "incorrect value for states[37].mesid.sat, expected 0, is {}",
                    msg.states[37].mesid.sat
                );
                assert_eq!(
                    msg.states[38].cn0, 189,
                    "incorrect value for states[38].cn0, expected 189, is {}",
                    msg.states[38].cn0
                );
                assert_eq!(
                    msg.states[38].mesid.code, 4,
                    "incorrect value for states[38].mesid.code, expected 4, is {}",
                    msg.states[38].mesid.code
                );
                assert_eq!(
                    msg.states[38].mesid.sat, 101,
                    "incorrect value for states[38].mesid.sat, expected 101, is {}",
                    msg.states[38].mesid.sat
                );
                assert_eq!(
                    msg.states[39].cn0, 207,
                    "incorrect value for states[39].cn0, expected 207, is {}",
                    msg.states[39].cn0
                );
                assert_eq!(
                    msg.states[39].mesid.code, 4,
                    "incorrect value for states[39].mesid.code, expected 4, is {}",
                    msg.states[39].mesid.code
                );
                assert_eq!(
                    msg.states[39].mesid.sat, 96,
                    "incorrect value for states[39].mesid.sat, expected 96, is {}",
                    msg.states[39].mesid.sat
                );
                assert_eq!(
                    msg.states[40].cn0, 164,
                    "incorrect value for states[40].cn0, expected 164, is {}",
                    msg.states[40].cn0
                );
                assert_eq!(
                    msg.states[40].mesid.code, 4,
                    "incorrect value for states[40].mesid.code, expected 4, is {}",
                    msg.states[40].mesid.code
                );
                assert_eq!(
                    msg.states[40].mesid.sat, 106,
                    "incorrect value for states[40].mesid.sat, expected 106, is {}",
                    msg.states[40].mesid.sat
                );
                assert_eq!(
                    msg.states[41].cn0, 193,
                    "incorrect value for states[41].cn0, expected 193, is {}",
                    msg.states[41].cn0
                );
                assert_eq!(
                    msg.states[41].mesid.code, 4,
                    "incorrect value for states[41].mesid.code, expected 4, is {}",
                    msg.states[41].mesid.code
                );
                assert_eq!(
                    msg.states[41].mesid.sat, 104,
                    "incorrect value for states[41].mesid.sat, expected 104, is {}",
                    msg.states[41].mesid.sat
                );
                assert_eq!(
                    msg.states[42].cn0, 0,
                    "incorrect value for states[42].cn0, expected 0, is {}",
                    msg.states[42].cn0
                );
                assert_eq!(
                    msg.states[42].mesid.code, 0,
                    "incorrect value for states[42].mesid.code, expected 0, is {}",
                    msg.states[42].mesid.code
                );
                assert_eq!(
                    msg.states[42].mesid.sat, 0,
                    "incorrect value for states[42].mesid.sat, expected 0, is {}",
                    msg.states[42].mesid.sat
                );
                assert_eq!(
                    msg.states[43].cn0, 208,
                    "incorrect value for states[43].cn0, expected 208, is {}",
                    msg.states[43].cn0
                );
                assert_eq!(
                    msg.states[43].mesid.code, 4,
                    "incorrect value for states[43].mesid.code, expected 4, is {}",
                    msg.states[43].mesid.code
                );
                assert_eq!(
                    msg.states[43].mesid.sat, 102,
                    "incorrect value for states[43].mesid.sat, expected 102, is {}",
                    msg.states[43].mesid.sat
                );
                assert_eq!(
                    msg.states[44].cn0, 0,
                    "incorrect value for states[44].cn0, expected 0, is {}",
                    msg.states[44].cn0
                );
                assert_eq!(
                    msg.states[44].mesid.code, 0,
                    "incorrect value for states[44].mesid.code, expected 0, is {}",
                    msg.states[44].mesid.code
                );
                assert_eq!(
                    msg.states[44].mesid.sat, 0,
                    "incorrect value for states[44].mesid.sat, expected 0, is {}",
                    msg.states[44].mesid.sat
                );
                assert_eq!(
                    msg.states[45].cn0, 212,
                    "incorrect value for states[45].cn0, expected 212, is {}",
                    msg.states[45].cn0
                );
                assert_eq!(
                    msg.states[45].mesid.code, 12,
                    "incorrect value for states[45].mesid.code, expected 12, is {}",
                    msg.states[45].mesid.code
                );
                assert_eq!(
                    msg.states[45].mesid.sat, 27,
                    "incorrect value for states[45].mesid.sat, expected 27, is {}",
                    msg.states[45].mesid.sat
                );
                assert_eq!(
                    msg.states[46].cn0, 161,
                    "incorrect value for states[46].cn0, expected 161, is {}",
                    msg.states[46].cn0
                );
                assert_eq!(
                    msg.states[46].mesid.code, 12,
                    "incorrect value for states[46].mesid.code, expected 12, is {}",
                    msg.states[46].mesid.code
                );
                assert_eq!(
                    msg.states[46].mesid.sat, 29,
                    "incorrect value for states[46].mesid.sat, expected 29, is {}",
                    msg.states[46].mesid.sat
                );
                assert_eq!(
                    msg.states[47].cn0, 216,
                    "incorrect value for states[47].cn0, expected 216, is {}",
                    msg.states[47].cn0
                );
                assert_eq!(
                    msg.states[47].mesid.code, 12,
                    "incorrect value for states[47].mesid.code, expected 12, is {}",
                    msg.states[47].mesid.code
                );
                assert_eq!(
                    msg.states[47].mesid.sat, 32,
                    "incorrect value for states[47].mesid.sat, expected 32, is {}",
                    msg.states[47].mesid.sat
                );
                assert_eq!(
                    msg.states[48].cn0, 216,
                    "incorrect value for states[48].cn0, expected 216, is {}",
                    msg.states[48].cn0
                );
                assert_eq!(
                    msg.states[48].mesid.code, 12,
                    "incorrect value for states[48].mesid.code, expected 12, is {}",
                    msg.states[48].mesid.code
                );
                assert_eq!(
                    msg.states[48].mesid.sat, 30,
                    "incorrect value for states[48].mesid.sat, expected 30, is {}",
                    msg.states[48].mesid.sat
                );
                assert_eq!(
                    msg.states[49].cn0, 178,
                    "incorrect value for states[49].cn0, expected 178, is {}",
                    msg.states[49].cn0
                );
                assert_eq!(
                    msg.states[49].mesid.code, 12,
                    "incorrect value for states[49].mesid.code, expected 12, is {}",
                    msg.states[49].mesid.code
                );
                assert_eq!(
                    msg.states[49].mesid.sat, 20,
                    "incorrect value for states[49].mesid.sat, expected 20, is {}",
                    msg.states[49].mesid.sat
                );
                assert_eq!(
                    msg.states[50].cn0, 0,
                    "incorrect value for states[50].cn0, expected 0, is {}",
                    msg.states[50].cn0
                );
                assert_eq!(
                    msg.states[50].mesid.code, 0,
                    "incorrect value for states[50].mesid.code, expected 0, is {}",
                    msg.states[50].mesid.code
                );
                assert_eq!(
                    msg.states[50].mesid.sat, 0,
                    "incorrect value for states[50].mesid.sat, expected 0, is {}",
                    msg.states[50].mesid.sat
                );
                assert_eq!(
                    msg.states[51].cn0, 0,
                    "incorrect value for states[51].cn0, expected 0, is {}",
                    msg.states[51].cn0
                );
                assert_eq!(
                    msg.states[51].mesid.code, 0,
                    "incorrect value for states[51].mesid.code, expected 0, is {}",
                    msg.states[51].mesid.code
                );
                assert_eq!(
                    msg.states[51].mesid.sat, 0,
                    "incorrect value for states[51].mesid.sat, expected 0, is {}",
                    msg.states[51].mesid.sat
                );
                assert_eq!(
                    msg.states[52].cn0, 0,
                    "incorrect value for states[52].cn0, expected 0, is {}",
                    msg.states[52].cn0
                );
                assert_eq!(
                    msg.states[52].mesid.code, 0,
                    "incorrect value for states[52].mesid.code, expected 0, is {}",
                    msg.states[52].mesid.code
                );
                assert_eq!(
                    msg.states[52].mesid.sat, 0,
                    "incorrect value for states[52].mesid.sat, expected 0, is {}",
                    msg.states[52].mesid.sat
                );
                assert_eq!(
                    msg.states[53].cn0, 0,
                    "incorrect value for states[53].cn0, expected 0, is {}",
                    msg.states[53].cn0
                );
                assert_eq!(
                    msg.states[53].mesid.code, 0,
                    "incorrect value for states[53].mesid.code, expected 0, is {}",
                    msg.states[53].mesid.code
                );
                assert_eq!(
                    msg.states[53].mesid.sat, 0,
                    "incorrect value for states[53].mesid.sat, expected 0, is {}",
                    msg.states[53].mesid.sat
                );
                assert_eq!(
                    msg.states[54].cn0, 0,
                    "incorrect value for states[54].cn0, expected 0, is {}",
                    msg.states[54].cn0
                );
                assert_eq!(
                    msg.states[54].mesid.code, 0,
                    "incorrect value for states[54].mesid.code, expected 0, is {}",
                    msg.states[54].mesid.code
                );
                assert_eq!(
                    msg.states[54].mesid.sat, 0,
                    "incorrect value for states[54].mesid.sat, expected 0, is {}",
                    msg.states[54].mesid.sat
                );
                assert_eq!(
                    msg.states[55].cn0, 0,
                    "incorrect value for states[55].cn0, expected 0, is {}",
                    msg.states[55].cn0
                );
                assert_eq!(
                    msg.states[55].mesid.code, 0,
                    "incorrect value for states[55].mesid.code, expected 0, is {}",
                    msg.states[55].mesid.code
                );
                assert_eq!(
                    msg.states[55].mesid.sat, 0,
                    "incorrect value for states[55].mesid.sat, expected 0, is {}",
                    msg.states[55].mesid.sat
                );
                assert_eq!(
                    msg.states[56].cn0, 0,
                    "incorrect value for states[56].cn0, expected 0, is {}",
                    msg.states[56].cn0
                );
                assert_eq!(
                    msg.states[56].mesid.code, 0,
                    "incorrect value for states[56].mesid.code, expected 0, is {}",
                    msg.states[56].mesid.code
                );
                assert_eq!(
                    msg.states[56].mesid.sat, 0,
                    "incorrect value for states[56].mesid.sat, expected 0, is {}",
                    msg.states[56].mesid.sat
                );
                assert_eq!(
                    msg.states[57].cn0, 0,
                    "incorrect value for states[57].cn0, expected 0, is {}",
                    msg.states[57].cn0
                );
                assert_eq!(
                    msg.states[57].mesid.code, 0,
                    "incorrect value for states[57].mesid.code, expected 0, is {}",
                    msg.states[57].mesid.code
                );
                assert_eq!(
                    msg.states[57].mesid.sat, 0,
                    "incorrect value for states[57].mesid.sat, expected 0, is {}",
                    msg.states[57].mesid.sat
                );
                assert_eq!(
                    msg.states[58].cn0, 0,
                    "incorrect value for states[58].cn0, expected 0, is {}",
                    msg.states[58].cn0
                );
                assert_eq!(
                    msg.states[58].mesid.code, 0,
                    "incorrect value for states[58].mesid.code, expected 0, is {}",
                    msg.states[58].mesid.code
                );
                assert_eq!(
                    msg.states[58].mesid.sat, 0,
                    "incorrect value for states[58].mesid.sat, expected 0, is {}",
                    msg.states[58].mesid.sat
                );
                assert_eq!(
                    msg.states[59].cn0, 0,
                    "incorrect value for states[59].cn0, expected 0, is {}",
                    msg.states[59].cn0
                );
                assert_eq!(
                    msg.states[59].mesid.code, 0,
                    "incorrect value for states[59].mesid.code, expected 0, is {}",
                    msg.states[59].mesid.code
                );
                assert_eq!(
                    msg.states[59].mesid.sat, 0,
                    "incorrect value for states[59].mesid.sat, expected 0, is {}",
                    msg.states[59].mesid.sat
                );
                assert_eq!(
                    msg.states[60].cn0, 0,
                    "incorrect value for states[60].cn0, expected 0, is {}",
                    msg.states[60].cn0
                );
                assert_eq!(
                    msg.states[60].mesid.code, 0,
                    "incorrect value for states[60].mesid.code, expected 0, is {}",
                    msg.states[60].mesid.code
                );
                assert_eq!(
                    msg.states[60].mesid.sat, 0,
                    "incorrect value for states[60].mesid.sat, expected 0, is {}",
                    msg.states[60].mesid.sat
                );
                assert_eq!(
                    msg.states[61].cn0, 0,
                    "incorrect value for states[61].cn0, expected 0, is {}",
                    msg.states[61].cn0
                );
                assert_eq!(
                    msg.states[61].mesid.code, 0,
                    "incorrect value for states[61].mesid.code, expected 0, is {}",
                    msg.states[61].mesid.code
                );
                assert_eq!(
                    msg.states[61].mesid.sat, 0,
                    "incorrect value for states[61].mesid.sat, expected 0, is {}",
                    msg.states[61].mesid.sat
                );
                assert_eq!(
                    msg.states[62].cn0, 0,
                    "incorrect value for states[62].cn0, expected 0, is {}",
                    msg.states[62].cn0
                );
                assert_eq!(
                    msg.states[62].mesid.code, 0,
                    "incorrect value for states[62].mesid.code, expected 0, is {}",
                    msg.states[62].mesid.code
                );
                assert_eq!(
                    msg.states[62].mesid.sat, 0,
                    "incorrect value for states[62].mesid.sat, expected 0, is {}",
                    msg.states[62].mesid.sat
                );
                assert_eq!(
                    msg.states[63].cn0, 203,
                    "incorrect value for states[63].cn0, expected 203, is {}",
                    msg.states[63].cn0
                );
                assert_eq!(
                    msg.states[63].mesid.code, 14,
                    "incorrect value for states[63].mesid.code, expected 14, is {}",
                    msg.states[63].mesid.code
                );
                assert_eq!(
                    msg.states[63].mesid.sat, 36,
                    "incorrect value for states[63].mesid.sat, expected 36, is {}",
                    msg.states[63].mesid.sat
                );
                assert_eq!(
                    msg.states[64].cn0, 0,
                    "incorrect value for states[64].cn0, expected 0, is {}",
                    msg.states[64].cn0
                );
                assert_eq!(
                    msg.states[64].mesid.code, 0,
                    "incorrect value for states[64].mesid.code, expected 0, is {}",
                    msg.states[64].mesid.code
                );
                assert_eq!(
                    msg.states[64].mesid.sat, 0,
                    "incorrect value for states[64].mesid.sat, expected 0, is {}",
                    msg.states[64].mesid.sat
                );
                assert_eq!(
                    msg.states[65].cn0, 158,
                    "incorrect value for states[65].cn0, expected 158, is {}",
                    msg.states[65].cn0
                );
                assert_eq!(
                    msg.states[65].mesid.code, 14,
                    "incorrect value for states[65].mesid.code, expected 14, is {}",
                    msg.states[65].mesid.code
                );
                assert_eq!(
                    msg.states[65].mesid.sat, 5,
                    "incorrect value for states[65].mesid.sat, expected 5, is {}",
                    msg.states[65].mesid.sat
                );
                assert_eq!(
                    msg.states[66].cn0, 194,
                    "incorrect value for states[66].cn0, expected 194, is {}",
                    msg.states[66].cn0
                );
                assert_eq!(
                    msg.states[66].mesid.code, 14,
                    "incorrect value for states[66].mesid.code, expected 14, is {}",
                    msg.states[66].mesid.code
                );
                assert_eq!(
                    msg.states[66].mesid.sat, 4,
                    "incorrect value for states[66].mesid.sat, expected 4, is {}",
                    msg.states[66].mesid.sat
                );
                assert_eq!(
                    msg.states[67].cn0, 192,
                    "incorrect value for states[67].cn0, expected 192, is {}",
                    msg.states[67].cn0
                );
                assert_eq!(
                    msg.states[67].mesid.code, 14,
                    "incorrect value for states[67].mesid.code, expected 14, is {}",
                    msg.states[67].mesid.code
                );
                assert_eq!(
                    msg.states[67].mesid.sat, 11,
                    "incorrect value for states[67].mesid.sat, expected 11, is {}",
                    msg.states[67].mesid.sat
                );
                assert_eq!(
                    msg.states[68].cn0, 207,
                    "incorrect value for states[68].cn0, expected 207, is {}",
                    msg.states[68].cn0
                );
                assert_eq!(
                    msg.states[68].mesid.code, 14,
                    "incorrect value for states[68].mesid.code, expected 14, is {}",
                    msg.states[68].mesid.code
                );
                assert_eq!(
                    msg.states[68].mesid.sat, 9,
                    "incorrect value for states[68].mesid.sat, expected 9, is {}",
                    msg.states[68].mesid.sat
                );
                assert_eq!(
                    msg.states[69].cn0, 0,
                    "incorrect value for states[69].cn0, expected 0, is {}",
                    msg.states[69].cn0
                );
                assert_eq!(
                    msg.states[69].mesid.code, 0,
                    "incorrect value for states[69].mesid.code, expected 0, is {}",
                    msg.states[69].mesid.code
                );
                assert_eq!(
                    msg.states[69].mesid.sat, 0,
                    "incorrect value for states[69].mesid.sat, expected 0, is {}",
                    msg.states[69].mesid.sat
                );
                assert_eq!(
                    msg.states[70].cn0, 0,
                    "incorrect value for states[70].cn0, expected 0, is {}",
                    msg.states[70].cn0
                );
                assert_eq!(
                    msg.states[70].mesid.code, 0,
                    "incorrect value for states[70].mesid.code, expected 0, is {}",
                    msg.states[70].mesid.code
                );
                assert_eq!(
                    msg.states[70].mesid.sat, 0,
                    "incorrect value for states[70].mesid.sat, expected 0, is {}",
                    msg.states[70].mesid.sat
                );
                assert_eq!(
                    msg.states[71].cn0, 0,
                    "incorrect value for states[71].cn0, expected 0, is {}",
                    msg.states[71].cn0
                );
                assert_eq!(
                    msg.states[71].mesid.code, 0,
                    "incorrect value for states[71].mesid.code, expected 0, is {}",
                    msg.states[71].mesid.code
                );
                assert_eq!(
                    msg.states[71].mesid.sat, 0,
                    "incorrect value for states[71].mesid.sat, expected 0, is {}",
                    msg.states[71].mesid.sat
                );
                assert_eq!(
                    msg.states[72].cn0, 218,
                    "incorrect value for states[72].cn0, expected 218, is {}",
                    msg.states[72].cn0
                );
                assert_eq!(
                    msg.states[72].mesid.code, 20,
                    "incorrect value for states[72].mesid.code, expected 20, is {}",
                    msg.states[72].mesid.code
                );
                assert_eq!(
                    msg.states[72].mesid.sat, 9,
                    "incorrect value for states[72].mesid.sat, expected 9, is {}",
                    msg.states[72].mesid.sat
                );
                assert_eq!(
                    msg.states[73].cn0, 176,
                    "incorrect value for states[73].cn0, expected 176, is {}",
                    msg.states[73].cn0
                );
                assert_eq!(
                    msg.states[73].mesid.code, 20,
                    "incorrect value for states[73].mesid.code, expected 20, is {}",
                    msg.states[73].mesid.code
                );
                assert_eq!(
                    msg.states[73].mesid.sat, 5,
                    "incorrect value for states[73].mesid.sat, expected 5, is {}",
                    msg.states[73].mesid.sat
                );
                assert_eq!(
                    msg.states[74].cn0, 217,
                    "incorrect value for states[74].cn0, expected 217, is {}",
                    msg.states[74].cn0
                );
                assert_eq!(
                    msg.states[74].mesid.code, 20,
                    "incorrect value for states[74].mesid.code, expected 20, is {}",
                    msg.states[74].mesid.code
                );
                assert_eq!(
                    msg.states[74].mesid.sat, 36,
                    "incorrect value for states[74].mesid.sat, expected 36, is {}",
                    msg.states[74].mesid.sat
                );
                assert_eq!(
                    msg.states[75].cn0, 200,
                    "incorrect value for states[75].cn0, expected 200, is {}",
                    msg.states[75].cn0
                );
                assert_eq!(
                    msg.states[75].mesid.code, 20,
                    "incorrect value for states[75].mesid.code, expected 20, is {}",
                    msg.states[75].mesid.code
                );
                assert_eq!(
                    msg.states[75].mesid.sat, 11,
                    "incorrect value for states[75].mesid.sat, expected 11, is {}",
                    msg.states[75].mesid.sat
                );
                assert_eq!(
                    msg.states[76].cn0, 205,
                    "incorrect value for states[76].cn0, expected 205, is {}",
                    msg.states[76].cn0
                );
                assert_eq!(
                    msg.states[76].mesid.code, 20,
                    "incorrect value for states[76].mesid.code, expected 20, is {}",
                    msg.states[76].mesid.code
                );
                assert_eq!(
                    msg.states[76].mesid.sat, 4,
                    "incorrect value for states[76].mesid.sat, expected 4, is {}",
                    msg.states[76].mesid.sat
                );
                assert_eq!(
                    msg.states[77].cn0, 0,
                    "incorrect value for states[77].cn0, expected 0, is {}",
                    msg.states[77].cn0
                );
                assert_eq!(
                    msg.states[77].mesid.code, 0,
                    "incorrect value for states[77].mesid.code, expected 0, is {}",
                    msg.states[77].mesid.code
                );
                assert_eq!(
                    msg.states[77].mesid.sat, 0,
                    "incorrect value for states[77].mesid.sat, expected 0, is {}",
                    msg.states[77].mesid.sat
                );
                assert_eq!(
                    msg.states[78].cn0, 0,
                    "incorrect value for states[78].cn0, expected 0, is {}",
                    msg.states[78].cn0
                );
                assert_eq!(
                    msg.states[78].mesid.code, 0,
                    "incorrect value for states[78].mesid.code, expected 0, is {}",
                    msg.states[78].mesid.code
                );
                assert_eq!(
                    msg.states[78].mesid.sat, 0,
                    "incorrect value for states[78].mesid.sat, expected 0, is {}",
                    msg.states[78].mesid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgMeasurementState"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
