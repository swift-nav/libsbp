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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusReport.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_system_msg_status_report() {
    {
        let mut payload = Cursor::new(vec![
            85, 254, 255, 6, 84, 252, 82, 253, 177, 95, 3, 60, 143, 90, 233, 21, 208, 98, 247, 203,
            221, 198, 156, 207, 217, 238, 162, 136, 154, 11, 114, 236, 134, 235, 12, 133, 9, 30,
            175, 145, 26, 114, 215, 20, 146, 249, 54, 54, 133, 193, 106, 186, 210, 183, 0, 129, 5,
            248, 225, 149, 135, 127, 2, 26, 88, 92, 10, 103, 73, 3, 103, 68, 76, 184, 33, 206, 194,
            163, 123, 30, 151, 176, 149, 172, 184, 231, 118, 230, 200, 168, 100, 109, 10, 233, 4,
            60, 247, 82, 215, 166, 28, 138, 110, 45, 98, 218, 244, 179, 126, 107, 92, 124, 94, 157,
            42, 187, 124, 6, 97, 247, 160, 188, 110, 120, 254, 214, 110, 51, 240, 164, 147, 18, 74,
            178, 67, 4, 27, 73, 190, 64, 179, 146, 125, 153, 192, 46, 202, 66, 248, 46, 40, 161,
            173, 242, 214, 3, 11, 1, 118, 70, 162, 61, 178, 27, 156, 40, 191, 113, 230, 200, 72, 8,
            215, 245, 78, 59, 222, 250, 115, 32, 33, 30, 211, 170, 145, 92, 157, 75, 24, 169, 6,
            55, 62, 8, 107, 82, 140, 49, 179, 122, 90, 71, 28, 88, 103, 51, 177, 72, 93, 39, 148,
            11, 202, 42, 34, 92, 204, 102, 29, 98, 249, 91, 134, 95, 23, 248, 192, 20, 83, 195, 95,
            180, 54, 36, 186, 75, 64, 20, 157, 133, 12, 149, 28, 14, 185, 129, 101, 239, 74, 248,
            245, 30, 228, 88, 142, 212, 53, 224, 158, 166,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgStatusReport(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xfffe,
                    "Incorrect message type, expected 0xfffe, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5406,
                    "incorrect sender id, expected 0x5406, is {sender_id}"
                );
                assert_eq!(
                    msg.reporting_system, 64850,
                    "incorrect value for reporting_system, expected 64850, is {}",
                    msg.reporting_system
                );
                assert_eq!(
                    msg.sbp_version, 24497,
                    "incorrect value for sbp_version, expected 24497, is {}",
                    msg.sbp_version
                );
                assert_eq!(
                    msg.sequence, 1519336451,
                    "incorrect value for sequence, expected 1519336451, is {}",
                    msg.sequence
                );
                assert_eq!(
                    msg.status[0].component, 52215,
                    "incorrect value for status[0].component, expected 52215, is {}",
                    msg.status[0].component
                );
                assert_eq!(
                    msg.status[0].generic, 221,
                    "incorrect value for status[0].generic, expected 221, is {}",
                    msg.status[0].generic
                );
                assert_eq!(
                    msg.status[0].specific, 198,
                    "incorrect value for status[0].specific, expected 198, is {}",
                    msg.status[0].specific
                );
                assert_eq!(
                    msg.status[1].component, 53148,
                    "incorrect value for status[1].component, expected 53148, is {}",
                    msg.status[1].component
                );
                assert_eq!(
                    msg.status[1].generic, 217,
                    "incorrect value for status[1].generic, expected 217, is {}",
                    msg.status[1].generic
                );
                assert_eq!(
                    msg.status[1].specific, 238,
                    "incorrect value for status[1].specific, expected 238, is {}",
                    msg.status[1].specific
                );
                assert_eq!(
                    msg.status[2].component, 34978,
                    "incorrect value for status[2].component, expected 34978, is {}",
                    msg.status[2].component
                );
                assert_eq!(
                    msg.status[2].generic, 154,
                    "incorrect value for status[2].generic, expected 154, is {}",
                    msg.status[2].generic
                );
                assert_eq!(
                    msg.status[2].specific, 11,
                    "incorrect value for status[2].specific, expected 11, is {}",
                    msg.status[2].specific
                );
                assert_eq!(
                    msg.status[3].component, 60530,
                    "incorrect value for status[3].component, expected 60530, is {}",
                    msg.status[3].component
                );
                assert_eq!(
                    msg.status[3].generic, 134,
                    "incorrect value for status[3].generic, expected 134, is {}",
                    msg.status[3].generic
                );
                assert_eq!(
                    msg.status[3].specific, 235,
                    "incorrect value for status[3].specific, expected 235, is {}",
                    msg.status[3].specific
                );
                assert_eq!(
                    msg.status[4].component, 34060,
                    "incorrect value for status[4].component, expected 34060, is {}",
                    msg.status[4].component
                );
                assert_eq!(
                    msg.status[4].generic, 9,
                    "incorrect value for status[4].generic, expected 9, is {}",
                    msg.status[4].generic
                );
                assert_eq!(
                    msg.status[4].specific, 30,
                    "incorrect value for status[4].specific, expected 30, is {}",
                    msg.status[4].specific
                );
                assert_eq!(
                    msg.status[5].component, 37295,
                    "incorrect value for status[5].component, expected 37295, is {}",
                    msg.status[5].component
                );
                assert_eq!(
                    msg.status[5].generic, 26,
                    "incorrect value for status[5].generic, expected 26, is {}",
                    msg.status[5].generic
                );
                assert_eq!(
                    msg.status[5].specific, 114,
                    "incorrect value for status[5].specific, expected 114, is {}",
                    msg.status[5].specific
                );
                assert_eq!(
                    msg.status[6].component, 5335,
                    "incorrect value for status[6].component, expected 5335, is {}",
                    msg.status[6].component
                );
                assert_eq!(
                    msg.status[6].generic, 146,
                    "incorrect value for status[6].generic, expected 146, is {}",
                    msg.status[6].generic
                );
                assert_eq!(
                    msg.status[6].specific, 249,
                    "incorrect value for status[6].specific, expected 249, is {}",
                    msg.status[6].specific
                );
                assert_eq!(
                    msg.status[7].component, 13878,
                    "incorrect value for status[7].component, expected 13878, is {}",
                    msg.status[7].component
                );
                assert_eq!(
                    msg.status[7].generic, 133,
                    "incorrect value for status[7].generic, expected 133, is {}",
                    msg.status[7].generic
                );
                assert_eq!(
                    msg.status[7].specific, 193,
                    "incorrect value for status[7].specific, expected 193, is {}",
                    msg.status[7].specific
                );
                assert_eq!(
                    msg.status[8].component, 47722,
                    "incorrect value for status[8].component, expected 47722, is {}",
                    msg.status[8].component
                );
                assert_eq!(
                    msg.status[8].generic, 210,
                    "incorrect value for status[8].generic, expected 210, is {}",
                    msg.status[8].generic
                );
                assert_eq!(
                    msg.status[8].specific, 183,
                    "incorrect value for status[8].specific, expected 183, is {}",
                    msg.status[8].specific
                );
                assert_eq!(
                    msg.status[9].component, 33024,
                    "incorrect value for status[9].component, expected 33024, is {}",
                    msg.status[9].component
                );
                assert_eq!(
                    msg.status[9].generic, 5,
                    "incorrect value for status[9].generic, expected 5, is {}",
                    msg.status[9].generic
                );
                assert_eq!(
                    msg.status[9].specific, 248,
                    "incorrect value for status[9].specific, expected 248, is {}",
                    msg.status[9].specific
                );
                assert_eq!(
                    msg.status[10].component, 38369,
                    "incorrect value for status[10].component, expected 38369, is {}",
                    msg.status[10].component
                );
                assert_eq!(
                    msg.status[10].generic, 135,
                    "incorrect value for status[10].generic, expected 135, is {}",
                    msg.status[10].generic
                );
                assert_eq!(
                    msg.status[10].specific, 127,
                    "incorrect value for status[10].specific, expected 127, is {}",
                    msg.status[10].specific
                );
                assert_eq!(
                    msg.status[11].component, 6658,
                    "incorrect value for status[11].component, expected 6658, is {}",
                    msg.status[11].component
                );
                assert_eq!(
                    msg.status[11].generic, 88,
                    "incorrect value for status[11].generic, expected 88, is {}",
                    msg.status[11].generic
                );
                assert_eq!(
                    msg.status[11].specific, 92,
                    "incorrect value for status[11].specific, expected 92, is {}",
                    msg.status[11].specific
                );
                assert_eq!(
                    msg.status[12].component, 26378,
                    "incorrect value for status[12].component, expected 26378, is {}",
                    msg.status[12].component
                );
                assert_eq!(
                    msg.status[12].generic, 73,
                    "incorrect value for status[12].generic, expected 73, is {}",
                    msg.status[12].generic
                );
                assert_eq!(
                    msg.status[12].specific, 3,
                    "incorrect value for status[12].specific, expected 3, is {}",
                    msg.status[12].specific
                );
                assert_eq!(
                    msg.status[13].component, 17511,
                    "incorrect value for status[13].component, expected 17511, is {}",
                    msg.status[13].component
                );
                assert_eq!(
                    msg.status[13].generic, 76,
                    "incorrect value for status[13].generic, expected 76, is {}",
                    msg.status[13].generic
                );
                assert_eq!(
                    msg.status[13].specific, 184,
                    "incorrect value for status[13].specific, expected 184, is {}",
                    msg.status[13].specific
                );
                assert_eq!(
                    msg.status[14].component, 52769,
                    "incorrect value for status[14].component, expected 52769, is {}",
                    msg.status[14].component
                );
                assert_eq!(
                    msg.status[14].generic, 194,
                    "incorrect value for status[14].generic, expected 194, is {}",
                    msg.status[14].generic
                );
                assert_eq!(
                    msg.status[14].specific, 163,
                    "incorrect value for status[14].specific, expected 163, is {}",
                    msg.status[14].specific
                );
                assert_eq!(
                    msg.status[15].component, 7803,
                    "incorrect value for status[15].component, expected 7803, is {}",
                    msg.status[15].component
                );
                assert_eq!(
                    msg.status[15].generic, 151,
                    "incorrect value for status[15].generic, expected 151, is {}",
                    msg.status[15].generic
                );
                assert_eq!(
                    msg.status[15].specific, 176,
                    "incorrect value for status[15].specific, expected 176, is {}",
                    msg.status[15].specific
                );
                assert_eq!(
                    msg.status[16].component, 44181,
                    "incorrect value for status[16].component, expected 44181, is {}",
                    msg.status[16].component
                );
                assert_eq!(
                    msg.status[16].generic, 184,
                    "incorrect value for status[16].generic, expected 184, is {}",
                    msg.status[16].generic
                );
                assert_eq!(
                    msg.status[16].specific, 231,
                    "incorrect value for status[16].specific, expected 231, is {}",
                    msg.status[16].specific
                );
                assert_eq!(
                    msg.status[17].component, 58998,
                    "incorrect value for status[17].component, expected 58998, is {}",
                    msg.status[17].component
                );
                assert_eq!(
                    msg.status[17].generic, 200,
                    "incorrect value for status[17].generic, expected 200, is {}",
                    msg.status[17].generic
                );
                assert_eq!(
                    msg.status[17].specific, 168,
                    "incorrect value for status[17].specific, expected 168, is {}",
                    msg.status[17].specific
                );
                assert_eq!(
                    msg.status[18].component, 28004,
                    "incorrect value for status[18].component, expected 28004, is {}",
                    msg.status[18].component
                );
                assert_eq!(
                    msg.status[18].generic, 10,
                    "incorrect value for status[18].generic, expected 10, is {}",
                    msg.status[18].generic
                );
                assert_eq!(
                    msg.status[18].specific, 233,
                    "incorrect value for status[18].specific, expected 233, is {}",
                    msg.status[18].specific
                );
                assert_eq!(
                    msg.status[19].component, 15364,
                    "incorrect value for status[19].component, expected 15364, is {}",
                    msg.status[19].component
                );
                assert_eq!(
                    msg.status[19].generic, 247,
                    "incorrect value for status[19].generic, expected 247, is {}",
                    msg.status[19].generic
                );
                assert_eq!(
                    msg.status[19].specific, 82,
                    "incorrect value for status[19].specific, expected 82, is {}",
                    msg.status[19].specific
                );
                assert_eq!(
                    msg.status[20].component, 42711,
                    "incorrect value for status[20].component, expected 42711, is {}",
                    msg.status[20].component
                );
                assert_eq!(
                    msg.status[20].generic, 28,
                    "incorrect value for status[20].generic, expected 28, is {}",
                    msg.status[20].generic
                );
                assert_eq!(
                    msg.status[20].specific, 138,
                    "incorrect value for status[20].specific, expected 138, is {}",
                    msg.status[20].specific
                );
                assert_eq!(
                    msg.status[21].component, 11630,
                    "incorrect value for status[21].component, expected 11630, is {}",
                    msg.status[21].component
                );
                assert_eq!(
                    msg.status[21].generic, 98,
                    "incorrect value for status[21].generic, expected 98, is {}",
                    msg.status[21].generic
                );
                assert_eq!(
                    msg.status[21].specific, 218,
                    "incorrect value for status[21].specific, expected 218, is {}",
                    msg.status[21].specific
                );
                assert_eq!(
                    msg.status[22].component, 46068,
                    "incorrect value for status[22].component, expected 46068, is {}",
                    msg.status[22].component
                );
                assert_eq!(
                    msg.status[22].generic, 126,
                    "incorrect value for status[22].generic, expected 126, is {}",
                    msg.status[22].generic
                );
                assert_eq!(
                    msg.status[22].specific, 107,
                    "incorrect value for status[22].specific, expected 107, is {}",
                    msg.status[22].specific
                );
                assert_eq!(
                    msg.status[23].component, 31836,
                    "incorrect value for status[23].component, expected 31836, is {}",
                    msg.status[23].component
                );
                assert_eq!(
                    msg.status[23].generic, 94,
                    "incorrect value for status[23].generic, expected 94, is {}",
                    msg.status[23].generic
                );
                assert_eq!(
                    msg.status[23].specific, 157,
                    "incorrect value for status[23].specific, expected 157, is {}",
                    msg.status[23].specific
                );
                assert_eq!(
                    msg.status[24].component, 47914,
                    "incorrect value for status[24].component, expected 47914, is {}",
                    msg.status[24].component
                );
                assert_eq!(
                    msg.status[24].generic, 124,
                    "incorrect value for status[24].generic, expected 124, is {}",
                    msg.status[24].generic
                );
                assert_eq!(
                    msg.status[24].specific, 6,
                    "incorrect value for status[24].specific, expected 6, is {}",
                    msg.status[24].specific
                );
                assert_eq!(
                    msg.status[25].component, 63329,
                    "incorrect value for status[25].component, expected 63329, is {}",
                    msg.status[25].component
                );
                assert_eq!(
                    msg.status[25].generic, 160,
                    "incorrect value for status[25].generic, expected 160, is {}",
                    msg.status[25].generic
                );
                assert_eq!(
                    msg.status[25].specific, 188,
                    "incorrect value for status[25].specific, expected 188, is {}",
                    msg.status[25].specific
                );
                assert_eq!(
                    msg.status[26].component, 30830,
                    "incorrect value for status[26].component, expected 30830, is {}",
                    msg.status[26].component
                );
                assert_eq!(
                    msg.status[26].generic, 254,
                    "incorrect value for status[26].generic, expected 254, is {}",
                    msg.status[26].generic
                );
                assert_eq!(
                    msg.status[26].specific, 214,
                    "incorrect value for status[26].specific, expected 214, is {}",
                    msg.status[26].specific
                );
                assert_eq!(
                    msg.status[27].component, 13166,
                    "incorrect value for status[27].component, expected 13166, is {}",
                    msg.status[27].component
                );
                assert_eq!(
                    msg.status[27].generic, 240,
                    "incorrect value for status[27].generic, expected 240, is {}",
                    msg.status[27].generic
                );
                assert_eq!(
                    msg.status[27].specific, 164,
                    "incorrect value for status[27].specific, expected 164, is {}",
                    msg.status[27].specific
                );
                assert_eq!(
                    msg.status[28].component, 4755,
                    "incorrect value for status[28].component, expected 4755, is {}",
                    msg.status[28].component
                );
                assert_eq!(
                    msg.status[28].generic, 74,
                    "incorrect value for status[28].generic, expected 74, is {}",
                    msg.status[28].generic
                );
                assert_eq!(
                    msg.status[28].specific, 178,
                    "incorrect value for status[28].specific, expected 178, is {}",
                    msg.status[28].specific
                );
                assert_eq!(
                    msg.status[29].component, 1091,
                    "incorrect value for status[29].component, expected 1091, is {}",
                    msg.status[29].component
                );
                assert_eq!(
                    msg.status[29].generic, 27,
                    "incorrect value for status[29].generic, expected 27, is {}",
                    msg.status[29].generic
                );
                assert_eq!(
                    msg.status[29].specific, 73,
                    "incorrect value for status[29].specific, expected 73, is {}",
                    msg.status[29].specific
                );
                assert_eq!(
                    msg.status[30].component, 16574,
                    "incorrect value for status[30].component, expected 16574, is {}",
                    msg.status[30].component
                );
                assert_eq!(
                    msg.status[30].generic, 179,
                    "incorrect value for status[30].generic, expected 179, is {}",
                    msg.status[30].generic
                );
                assert_eq!(
                    msg.status[30].specific, 146,
                    "incorrect value for status[30].specific, expected 146, is {}",
                    msg.status[30].specific
                );
                assert_eq!(
                    msg.status[31].component, 39293,
                    "incorrect value for status[31].component, expected 39293, is {}",
                    msg.status[31].component
                );
                assert_eq!(
                    msg.status[31].generic, 192,
                    "incorrect value for status[31].generic, expected 192, is {}",
                    msg.status[31].generic
                );
                assert_eq!(
                    msg.status[31].specific, 46,
                    "incorrect value for status[31].specific, expected 46, is {}",
                    msg.status[31].specific
                );
                assert_eq!(
                    msg.status[32].component, 17098,
                    "incorrect value for status[32].component, expected 17098, is {}",
                    msg.status[32].component
                );
                assert_eq!(
                    msg.status[32].generic, 248,
                    "incorrect value for status[32].generic, expected 248, is {}",
                    msg.status[32].generic
                );
                assert_eq!(
                    msg.status[32].specific, 46,
                    "incorrect value for status[32].specific, expected 46, is {}",
                    msg.status[32].specific
                );
                assert_eq!(
                    msg.status[33].component, 41256,
                    "incorrect value for status[33].component, expected 41256, is {}",
                    msg.status[33].component
                );
                assert_eq!(
                    msg.status[33].generic, 173,
                    "incorrect value for status[33].generic, expected 173, is {}",
                    msg.status[33].generic
                );
                assert_eq!(
                    msg.status[33].specific, 242,
                    "incorrect value for status[33].specific, expected 242, is {}",
                    msg.status[33].specific
                );
                assert_eq!(
                    msg.status[34].component, 982,
                    "incorrect value for status[34].component, expected 982, is {}",
                    msg.status[34].component
                );
                assert_eq!(
                    msg.status[34].generic, 11,
                    "incorrect value for status[34].generic, expected 11, is {}",
                    msg.status[34].generic
                );
                assert_eq!(
                    msg.status[34].specific, 1,
                    "incorrect value for status[34].specific, expected 1, is {}",
                    msg.status[34].specific
                );
                assert_eq!(
                    msg.status[35].component, 18038,
                    "incorrect value for status[35].component, expected 18038, is {}",
                    msg.status[35].component
                );
                assert_eq!(
                    msg.status[35].generic, 162,
                    "incorrect value for status[35].generic, expected 162, is {}",
                    msg.status[35].generic
                );
                assert_eq!(
                    msg.status[35].specific, 61,
                    "incorrect value for status[35].specific, expected 61, is {}",
                    msg.status[35].specific
                );
                assert_eq!(
                    msg.status[36].component, 7090,
                    "incorrect value for status[36].component, expected 7090, is {}",
                    msg.status[36].component
                );
                assert_eq!(
                    msg.status[36].generic, 156,
                    "incorrect value for status[36].generic, expected 156, is {}",
                    msg.status[36].generic
                );
                assert_eq!(
                    msg.status[36].specific, 40,
                    "incorrect value for status[36].specific, expected 40, is {}",
                    msg.status[36].specific
                );
                assert_eq!(
                    msg.status[37].component, 29119,
                    "incorrect value for status[37].component, expected 29119, is {}",
                    msg.status[37].component
                );
                assert_eq!(
                    msg.status[37].generic, 230,
                    "incorrect value for status[37].generic, expected 230, is {}",
                    msg.status[37].generic
                );
                assert_eq!(
                    msg.status[37].specific, 200,
                    "incorrect value for status[37].specific, expected 200, is {}",
                    msg.status[37].specific
                );
                assert_eq!(
                    msg.status[38].component, 2120,
                    "incorrect value for status[38].component, expected 2120, is {}",
                    msg.status[38].component
                );
                assert_eq!(
                    msg.status[38].generic, 215,
                    "incorrect value for status[38].generic, expected 215, is {}",
                    msg.status[38].generic
                );
                assert_eq!(
                    msg.status[38].specific, 245,
                    "incorrect value for status[38].specific, expected 245, is {}",
                    msg.status[38].specific
                );
                assert_eq!(
                    msg.status[39].component, 15182,
                    "incorrect value for status[39].component, expected 15182, is {}",
                    msg.status[39].component
                );
                assert_eq!(
                    msg.status[39].generic, 222,
                    "incorrect value for status[39].generic, expected 222, is {}",
                    msg.status[39].generic
                );
                assert_eq!(
                    msg.status[39].specific, 250,
                    "incorrect value for status[39].specific, expected 250, is {}",
                    msg.status[39].specific
                );
                assert_eq!(
                    msg.status[40].component, 8307,
                    "incorrect value for status[40].component, expected 8307, is {}",
                    msg.status[40].component
                );
                assert_eq!(
                    msg.status[40].generic, 33,
                    "incorrect value for status[40].generic, expected 33, is {}",
                    msg.status[40].generic
                );
                assert_eq!(
                    msg.status[40].specific, 30,
                    "incorrect value for status[40].specific, expected 30, is {}",
                    msg.status[40].specific
                );
                assert_eq!(
                    msg.status[41].component, 43731,
                    "incorrect value for status[41].component, expected 43731, is {}",
                    msg.status[41].component
                );
                assert_eq!(
                    msg.status[41].generic, 145,
                    "incorrect value for status[41].generic, expected 145, is {}",
                    msg.status[41].generic
                );
                assert_eq!(
                    msg.status[41].specific, 92,
                    "incorrect value for status[41].specific, expected 92, is {}",
                    msg.status[41].specific
                );
                assert_eq!(
                    msg.status[42].component, 19357,
                    "incorrect value for status[42].component, expected 19357, is {}",
                    msg.status[42].component
                );
                assert_eq!(
                    msg.status[42].generic, 24,
                    "incorrect value for status[42].generic, expected 24, is {}",
                    msg.status[42].generic
                );
                assert_eq!(
                    msg.status[42].specific, 169,
                    "incorrect value for status[42].specific, expected 169, is {}",
                    msg.status[42].specific
                );
                assert_eq!(
                    msg.status[43].component, 14086,
                    "incorrect value for status[43].component, expected 14086, is {}",
                    msg.status[43].component
                );
                assert_eq!(
                    msg.status[43].generic, 62,
                    "incorrect value for status[43].generic, expected 62, is {}",
                    msg.status[43].generic
                );
                assert_eq!(
                    msg.status[43].specific, 8,
                    "incorrect value for status[43].specific, expected 8, is {}",
                    msg.status[43].specific
                );
                assert_eq!(
                    msg.status[44].component, 21099,
                    "incorrect value for status[44].component, expected 21099, is {}",
                    msg.status[44].component
                );
                assert_eq!(
                    msg.status[44].generic, 140,
                    "incorrect value for status[44].generic, expected 140, is {}",
                    msg.status[44].generic
                );
                assert_eq!(
                    msg.status[44].specific, 49,
                    "incorrect value for status[44].specific, expected 49, is {}",
                    msg.status[44].specific
                );
                assert_eq!(
                    msg.status[45].component, 31411,
                    "incorrect value for status[45].component, expected 31411, is {}",
                    msg.status[45].component
                );
                assert_eq!(
                    msg.status[45].generic, 90,
                    "incorrect value for status[45].generic, expected 90, is {}",
                    msg.status[45].generic
                );
                assert_eq!(
                    msg.status[45].specific, 71,
                    "incorrect value for status[45].specific, expected 71, is {}",
                    msg.status[45].specific
                );
                assert_eq!(
                    msg.status[46].component, 22556,
                    "incorrect value for status[46].component, expected 22556, is {}",
                    msg.status[46].component
                );
                assert_eq!(
                    msg.status[46].generic, 103,
                    "incorrect value for status[46].generic, expected 103, is {}",
                    msg.status[46].generic
                );
                assert_eq!(
                    msg.status[46].specific, 51,
                    "incorrect value for status[46].specific, expected 51, is {}",
                    msg.status[46].specific
                );
                assert_eq!(
                    msg.status[47].component, 18609,
                    "incorrect value for status[47].component, expected 18609, is {}",
                    msg.status[47].component
                );
                assert_eq!(
                    msg.status[47].generic, 93,
                    "incorrect value for status[47].generic, expected 93, is {}",
                    msg.status[47].generic
                );
                assert_eq!(
                    msg.status[47].specific, 39,
                    "incorrect value for status[47].specific, expected 39, is {}",
                    msg.status[47].specific
                );
                assert_eq!(
                    msg.status[48].component, 2964,
                    "incorrect value for status[48].component, expected 2964, is {}",
                    msg.status[48].component
                );
                assert_eq!(
                    msg.status[48].generic, 202,
                    "incorrect value for status[48].generic, expected 202, is {}",
                    msg.status[48].generic
                );
                assert_eq!(
                    msg.status[48].specific, 42,
                    "incorrect value for status[48].specific, expected 42, is {}",
                    msg.status[48].specific
                );
                assert_eq!(
                    msg.status[49].component, 23586,
                    "incorrect value for status[49].component, expected 23586, is {}",
                    msg.status[49].component
                );
                assert_eq!(
                    msg.status[49].generic, 204,
                    "incorrect value for status[49].generic, expected 204, is {}",
                    msg.status[49].generic
                );
                assert_eq!(
                    msg.status[49].specific, 102,
                    "incorrect value for status[49].specific, expected 102, is {}",
                    msg.status[49].specific
                );
                assert_eq!(
                    msg.status[50].component, 25117,
                    "incorrect value for status[50].component, expected 25117, is {}",
                    msg.status[50].component
                );
                assert_eq!(
                    msg.status[50].generic, 249,
                    "incorrect value for status[50].generic, expected 249, is {}",
                    msg.status[50].generic
                );
                assert_eq!(
                    msg.status[50].specific, 91,
                    "incorrect value for status[50].specific, expected 91, is {}",
                    msg.status[50].specific
                );
                assert_eq!(
                    msg.status[51].component, 24454,
                    "incorrect value for status[51].component, expected 24454, is {}",
                    msg.status[51].component
                );
                assert_eq!(
                    msg.status[51].generic, 23,
                    "incorrect value for status[51].generic, expected 23, is {}",
                    msg.status[51].generic
                );
                assert_eq!(
                    msg.status[51].specific, 248,
                    "incorrect value for status[51].specific, expected 248, is {}",
                    msg.status[51].specific
                );
                assert_eq!(
                    msg.status[52].component, 5312,
                    "incorrect value for status[52].component, expected 5312, is {}",
                    msg.status[52].component
                );
                assert_eq!(
                    msg.status[52].generic, 83,
                    "incorrect value for status[52].generic, expected 83, is {}",
                    msg.status[52].generic
                );
                assert_eq!(
                    msg.status[52].specific, 195,
                    "incorrect value for status[52].specific, expected 195, is {}",
                    msg.status[52].specific
                );
                assert_eq!(
                    msg.status[53].component, 46175,
                    "incorrect value for status[53].component, expected 46175, is {}",
                    msg.status[53].component
                );
                assert_eq!(
                    msg.status[53].generic, 54,
                    "incorrect value for status[53].generic, expected 54, is {}",
                    msg.status[53].generic
                );
                assert_eq!(
                    msg.status[53].specific, 36,
                    "incorrect value for status[53].specific, expected 36, is {}",
                    msg.status[53].specific
                );
                assert_eq!(
                    msg.status[54].component, 19386,
                    "incorrect value for status[54].component, expected 19386, is {}",
                    msg.status[54].component
                );
                assert_eq!(
                    msg.status[54].generic, 64,
                    "incorrect value for status[54].generic, expected 64, is {}",
                    msg.status[54].generic
                );
                assert_eq!(
                    msg.status[54].specific, 20,
                    "incorrect value for status[54].specific, expected 20, is {}",
                    msg.status[54].specific
                );
                assert_eq!(
                    msg.status[55].component, 34205,
                    "incorrect value for status[55].component, expected 34205, is {}",
                    msg.status[55].component
                );
                assert_eq!(
                    msg.status[55].generic, 12,
                    "incorrect value for status[55].generic, expected 12, is {}",
                    msg.status[55].generic
                );
                assert_eq!(
                    msg.status[55].specific, 149,
                    "incorrect value for status[55].specific, expected 149, is {}",
                    msg.status[55].specific
                );
                assert_eq!(
                    msg.status[56].component, 3612,
                    "incorrect value for status[56].component, expected 3612, is {}",
                    msg.status[56].component
                );
                assert_eq!(
                    msg.status[56].generic, 185,
                    "incorrect value for status[56].generic, expected 185, is {}",
                    msg.status[56].generic
                );
                assert_eq!(
                    msg.status[56].specific, 129,
                    "incorrect value for status[56].specific, expected 129, is {}",
                    msg.status[56].specific
                );
                assert_eq!(
                    msg.status[57].component, 61285,
                    "incorrect value for status[57].component, expected 61285, is {}",
                    msg.status[57].component
                );
                assert_eq!(
                    msg.status[57].generic, 74,
                    "incorrect value for status[57].generic, expected 74, is {}",
                    msg.status[57].generic
                );
                assert_eq!(
                    msg.status[57].specific, 248,
                    "incorrect value for status[57].specific, expected 248, is {}",
                    msg.status[57].specific
                );
                assert_eq!(
                    msg.status[58].component, 7925,
                    "incorrect value for status[58].component, expected 7925, is {}",
                    msg.status[58].component
                );
                assert_eq!(
                    msg.status[58].generic, 228,
                    "incorrect value for status[58].generic, expected 228, is {}",
                    msg.status[58].generic
                );
                assert_eq!(
                    msg.status[58].specific, 88,
                    "incorrect value for status[58].specific, expected 88, is {}",
                    msg.status[58].specific
                );
                assert_eq!(
                    msg.status[59].component, 54414,
                    "incorrect value for status[59].component, expected 54414, is {}",
                    msg.status[59].component
                );
                assert_eq!(
                    msg.status[59].generic, 53,
                    "incorrect value for status[59].generic, expected 53, is {}",
                    msg.status[59].generic
                );
                assert_eq!(
                    msg.status[59].specific, 224,
                    "incorrect value for status[59].specific, expected 224, is {}",
                    msg.status[59].specific
                );
                assert_eq!(
                    msg.uptime, 1657804265,
                    "incorrect value for uptime, expected 1657804265, is {}",
                    msg.uptime
                );
            }
            _ => panic!("Invalid message type! Expected a MsgStatusReport"),
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
fn test_json2sbp_auto_check_sbp_system_msg_status_report() {
    {
        let json_input = r#"{"preamble":85,"msg_type":65534,"sender":21510,"length":252,"payload":"Uv2xXwM8j1rpFdBi98vdxpzP2e6iiJoLcuyG6wyFCR6vkRpy1xSS+TY2hcFqutK3AIEF+OGVh38CGlhcCmdJA2dETLghzsKjex6XsJWsuOd25sioZG0K6QQ891LXphyKbi1i2vSzfmtcfF6dKrt8BmH3oLxueP7WbjPwpJMSSrJDBBtJvkCzkn2ZwC7KQvguKKGt8tYDCwF2RqI9shucKL9x5shICNf1Tjve+nMgIR7TqpFcnUsYqQY3PghrUowxs3paRxxYZzOxSF0nlAvKKiJczGYdYvlbhl8X+MAUU8NftDYkuktAFJ2FDJUcDrmBZe9K+PUe5FiO1DXg","crc":42654,"reporting_system":64850,"sbp_version":24497,"sequence":1519336451,"uptime":1657804265,"status":[{"component":52215,"generic":221,"specific":198},{"component":53148,"generic":217,"specific":238},{"component":34978,"generic":154,"specific":11},{"component":60530,"generic":134,"specific":235},{"component":34060,"generic":9,"specific":30},{"component":37295,"generic":26,"specific":114},{"component":5335,"generic":146,"specific":249},{"component":13878,"generic":133,"specific":193},{"component":47722,"generic":210,"specific":183},{"component":33024,"generic":5,"specific":248},{"component":38369,"generic":135,"specific":127},{"component":6658,"generic":88,"specific":92},{"component":26378,"generic":73,"specific":3},{"component":17511,"generic":76,"specific":184},{"component":52769,"generic":194,"specific":163},{"component":7803,"generic":151,"specific":176},{"component":44181,"generic":184,"specific":231},{"component":58998,"generic":200,"specific":168},{"component":28004,"generic":10,"specific":233},{"component":15364,"generic":247,"specific":82},{"component":42711,"generic":28,"specific":138},{"component":11630,"generic":98,"specific":218},{"component":46068,"generic":126,"specific":107},{"component":31836,"generic":94,"specific":157},{"component":47914,"generic":124,"specific":6},{"component":63329,"generic":160,"specific":188},{"component":30830,"generic":254,"specific":214},{"component":13166,"generic":240,"specific":164},{"component":4755,"generic":74,"specific":178},{"component":1091,"generic":27,"specific":73},{"component":16574,"generic":179,"specific":146},{"component":39293,"generic":192,"specific":46},{"component":17098,"generic":248,"specific":46},{"component":41256,"generic":173,"specific":242},{"component":982,"generic":11,"specific":1},{"component":18038,"generic":162,"specific":61},{"component":7090,"generic":156,"specific":40},{"component":29119,"generic":230,"specific":200},{"component":2120,"generic":215,"specific":245},{"component":15182,"generic":222,"specific":250},{"component":8307,"generic":33,"specific":30},{"component":43731,"generic":145,"specific":92},{"component":19357,"generic":24,"specific":169},{"component":14086,"generic":62,"specific":8},{"component":21099,"generic":140,"specific":49},{"component":31411,"generic":90,"specific":71},{"component":22556,"generic":103,"specific":51},{"component":18609,"generic":93,"specific":39},{"component":2964,"generic":202,"specific":42},{"component":23586,"generic":204,"specific":102},{"component":25117,"generic":249,"specific":91},{"component":24454,"generic":23,"specific":248},{"component":5312,"generic":83,"specific":195},{"component":46175,"generic":54,"specific":36},{"component":19386,"generic":64,"specific":20},{"component":34205,"generic":12,"specific":149},{"component":3612,"generic":185,"specific":129},{"component":61285,"generic":74,"specific":248},{"component":7925,"generic":228,"specific":88},{"component":54414,"generic":53,"specific":224}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgStatusReport(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xfffe,
                    "Incorrect message type, expected 0xfffe, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5406,
                    "incorrect sender id, expected 0x5406, is {sender_id}"
                );
                assert_eq!(
                    msg.reporting_system, 64850,
                    "incorrect value for reporting_system, expected 64850, is {}",
                    msg.reporting_system
                );
                assert_eq!(
                    msg.sbp_version, 24497,
                    "incorrect value for sbp_version, expected 24497, is {}",
                    msg.sbp_version
                );
                assert_eq!(
                    msg.sequence, 1519336451,
                    "incorrect value for sequence, expected 1519336451, is {}",
                    msg.sequence
                );
                assert_eq!(
                    msg.status[0].component, 52215,
                    "incorrect value for status[0].component, expected 52215, is {}",
                    msg.status[0].component
                );
                assert_eq!(
                    msg.status[0].generic, 221,
                    "incorrect value for status[0].generic, expected 221, is {}",
                    msg.status[0].generic
                );
                assert_eq!(
                    msg.status[0].specific, 198,
                    "incorrect value for status[0].specific, expected 198, is {}",
                    msg.status[0].specific
                );
                assert_eq!(
                    msg.status[1].component, 53148,
                    "incorrect value for status[1].component, expected 53148, is {}",
                    msg.status[1].component
                );
                assert_eq!(
                    msg.status[1].generic, 217,
                    "incorrect value for status[1].generic, expected 217, is {}",
                    msg.status[1].generic
                );
                assert_eq!(
                    msg.status[1].specific, 238,
                    "incorrect value for status[1].specific, expected 238, is {}",
                    msg.status[1].specific
                );
                assert_eq!(
                    msg.status[2].component, 34978,
                    "incorrect value for status[2].component, expected 34978, is {}",
                    msg.status[2].component
                );
                assert_eq!(
                    msg.status[2].generic, 154,
                    "incorrect value for status[2].generic, expected 154, is {}",
                    msg.status[2].generic
                );
                assert_eq!(
                    msg.status[2].specific, 11,
                    "incorrect value for status[2].specific, expected 11, is {}",
                    msg.status[2].specific
                );
                assert_eq!(
                    msg.status[3].component, 60530,
                    "incorrect value for status[3].component, expected 60530, is {}",
                    msg.status[3].component
                );
                assert_eq!(
                    msg.status[3].generic, 134,
                    "incorrect value for status[3].generic, expected 134, is {}",
                    msg.status[3].generic
                );
                assert_eq!(
                    msg.status[3].specific, 235,
                    "incorrect value for status[3].specific, expected 235, is {}",
                    msg.status[3].specific
                );
                assert_eq!(
                    msg.status[4].component, 34060,
                    "incorrect value for status[4].component, expected 34060, is {}",
                    msg.status[4].component
                );
                assert_eq!(
                    msg.status[4].generic, 9,
                    "incorrect value for status[4].generic, expected 9, is {}",
                    msg.status[4].generic
                );
                assert_eq!(
                    msg.status[4].specific, 30,
                    "incorrect value for status[4].specific, expected 30, is {}",
                    msg.status[4].specific
                );
                assert_eq!(
                    msg.status[5].component, 37295,
                    "incorrect value for status[5].component, expected 37295, is {}",
                    msg.status[5].component
                );
                assert_eq!(
                    msg.status[5].generic, 26,
                    "incorrect value for status[5].generic, expected 26, is {}",
                    msg.status[5].generic
                );
                assert_eq!(
                    msg.status[5].specific, 114,
                    "incorrect value for status[5].specific, expected 114, is {}",
                    msg.status[5].specific
                );
                assert_eq!(
                    msg.status[6].component, 5335,
                    "incorrect value for status[6].component, expected 5335, is {}",
                    msg.status[6].component
                );
                assert_eq!(
                    msg.status[6].generic, 146,
                    "incorrect value for status[6].generic, expected 146, is {}",
                    msg.status[6].generic
                );
                assert_eq!(
                    msg.status[6].specific, 249,
                    "incorrect value for status[6].specific, expected 249, is {}",
                    msg.status[6].specific
                );
                assert_eq!(
                    msg.status[7].component, 13878,
                    "incorrect value for status[7].component, expected 13878, is {}",
                    msg.status[7].component
                );
                assert_eq!(
                    msg.status[7].generic, 133,
                    "incorrect value for status[7].generic, expected 133, is {}",
                    msg.status[7].generic
                );
                assert_eq!(
                    msg.status[7].specific, 193,
                    "incorrect value for status[7].specific, expected 193, is {}",
                    msg.status[7].specific
                );
                assert_eq!(
                    msg.status[8].component, 47722,
                    "incorrect value for status[8].component, expected 47722, is {}",
                    msg.status[8].component
                );
                assert_eq!(
                    msg.status[8].generic, 210,
                    "incorrect value for status[8].generic, expected 210, is {}",
                    msg.status[8].generic
                );
                assert_eq!(
                    msg.status[8].specific, 183,
                    "incorrect value for status[8].specific, expected 183, is {}",
                    msg.status[8].specific
                );
                assert_eq!(
                    msg.status[9].component, 33024,
                    "incorrect value for status[9].component, expected 33024, is {}",
                    msg.status[9].component
                );
                assert_eq!(
                    msg.status[9].generic, 5,
                    "incorrect value for status[9].generic, expected 5, is {}",
                    msg.status[9].generic
                );
                assert_eq!(
                    msg.status[9].specific, 248,
                    "incorrect value for status[9].specific, expected 248, is {}",
                    msg.status[9].specific
                );
                assert_eq!(
                    msg.status[10].component, 38369,
                    "incorrect value for status[10].component, expected 38369, is {}",
                    msg.status[10].component
                );
                assert_eq!(
                    msg.status[10].generic, 135,
                    "incorrect value for status[10].generic, expected 135, is {}",
                    msg.status[10].generic
                );
                assert_eq!(
                    msg.status[10].specific, 127,
                    "incorrect value for status[10].specific, expected 127, is {}",
                    msg.status[10].specific
                );
                assert_eq!(
                    msg.status[11].component, 6658,
                    "incorrect value for status[11].component, expected 6658, is {}",
                    msg.status[11].component
                );
                assert_eq!(
                    msg.status[11].generic, 88,
                    "incorrect value for status[11].generic, expected 88, is {}",
                    msg.status[11].generic
                );
                assert_eq!(
                    msg.status[11].specific, 92,
                    "incorrect value for status[11].specific, expected 92, is {}",
                    msg.status[11].specific
                );
                assert_eq!(
                    msg.status[12].component, 26378,
                    "incorrect value for status[12].component, expected 26378, is {}",
                    msg.status[12].component
                );
                assert_eq!(
                    msg.status[12].generic, 73,
                    "incorrect value for status[12].generic, expected 73, is {}",
                    msg.status[12].generic
                );
                assert_eq!(
                    msg.status[12].specific, 3,
                    "incorrect value for status[12].specific, expected 3, is {}",
                    msg.status[12].specific
                );
                assert_eq!(
                    msg.status[13].component, 17511,
                    "incorrect value for status[13].component, expected 17511, is {}",
                    msg.status[13].component
                );
                assert_eq!(
                    msg.status[13].generic, 76,
                    "incorrect value for status[13].generic, expected 76, is {}",
                    msg.status[13].generic
                );
                assert_eq!(
                    msg.status[13].specific, 184,
                    "incorrect value for status[13].specific, expected 184, is {}",
                    msg.status[13].specific
                );
                assert_eq!(
                    msg.status[14].component, 52769,
                    "incorrect value for status[14].component, expected 52769, is {}",
                    msg.status[14].component
                );
                assert_eq!(
                    msg.status[14].generic, 194,
                    "incorrect value for status[14].generic, expected 194, is {}",
                    msg.status[14].generic
                );
                assert_eq!(
                    msg.status[14].specific, 163,
                    "incorrect value for status[14].specific, expected 163, is {}",
                    msg.status[14].specific
                );
                assert_eq!(
                    msg.status[15].component, 7803,
                    "incorrect value for status[15].component, expected 7803, is {}",
                    msg.status[15].component
                );
                assert_eq!(
                    msg.status[15].generic, 151,
                    "incorrect value for status[15].generic, expected 151, is {}",
                    msg.status[15].generic
                );
                assert_eq!(
                    msg.status[15].specific, 176,
                    "incorrect value for status[15].specific, expected 176, is {}",
                    msg.status[15].specific
                );
                assert_eq!(
                    msg.status[16].component, 44181,
                    "incorrect value for status[16].component, expected 44181, is {}",
                    msg.status[16].component
                );
                assert_eq!(
                    msg.status[16].generic, 184,
                    "incorrect value for status[16].generic, expected 184, is {}",
                    msg.status[16].generic
                );
                assert_eq!(
                    msg.status[16].specific, 231,
                    "incorrect value for status[16].specific, expected 231, is {}",
                    msg.status[16].specific
                );
                assert_eq!(
                    msg.status[17].component, 58998,
                    "incorrect value for status[17].component, expected 58998, is {}",
                    msg.status[17].component
                );
                assert_eq!(
                    msg.status[17].generic, 200,
                    "incorrect value for status[17].generic, expected 200, is {}",
                    msg.status[17].generic
                );
                assert_eq!(
                    msg.status[17].specific, 168,
                    "incorrect value for status[17].specific, expected 168, is {}",
                    msg.status[17].specific
                );
                assert_eq!(
                    msg.status[18].component, 28004,
                    "incorrect value for status[18].component, expected 28004, is {}",
                    msg.status[18].component
                );
                assert_eq!(
                    msg.status[18].generic, 10,
                    "incorrect value for status[18].generic, expected 10, is {}",
                    msg.status[18].generic
                );
                assert_eq!(
                    msg.status[18].specific, 233,
                    "incorrect value for status[18].specific, expected 233, is {}",
                    msg.status[18].specific
                );
                assert_eq!(
                    msg.status[19].component, 15364,
                    "incorrect value for status[19].component, expected 15364, is {}",
                    msg.status[19].component
                );
                assert_eq!(
                    msg.status[19].generic, 247,
                    "incorrect value for status[19].generic, expected 247, is {}",
                    msg.status[19].generic
                );
                assert_eq!(
                    msg.status[19].specific, 82,
                    "incorrect value for status[19].specific, expected 82, is {}",
                    msg.status[19].specific
                );
                assert_eq!(
                    msg.status[20].component, 42711,
                    "incorrect value for status[20].component, expected 42711, is {}",
                    msg.status[20].component
                );
                assert_eq!(
                    msg.status[20].generic, 28,
                    "incorrect value for status[20].generic, expected 28, is {}",
                    msg.status[20].generic
                );
                assert_eq!(
                    msg.status[20].specific, 138,
                    "incorrect value for status[20].specific, expected 138, is {}",
                    msg.status[20].specific
                );
                assert_eq!(
                    msg.status[21].component, 11630,
                    "incorrect value for status[21].component, expected 11630, is {}",
                    msg.status[21].component
                );
                assert_eq!(
                    msg.status[21].generic, 98,
                    "incorrect value for status[21].generic, expected 98, is {}",
                    msg.status[21].generic
                );
                assert_eq!(
                    msg.status[21].specific, 218,
                    "incorrect value for status[21].specific, expected 218, is {}",
                    msg.status[21].specific
                );
                assert_eq!(
                    msg.status[22].component, 46068,
                    "incorrect value for status[22].component, expected 46068, is {}",
                    msg.status[22].component
                );
                assert_eq!(
                    msg.status[22].generic, 126,
                    "incorrect value for status[22].generic, expected 126, is {}",
                    msg.status[22].generic
                );
                assert_eq!(
                    msg.status[22].specific, 107,
                    "incorrect value for status[22].specific, expected 107, is {}",
                    msg.status[22].specific
                );
                assert_eq!(
                    msg.status[23].component, 31836,
                    "incorrect value for status[23].component, expected 31836, is {}",
                    msg.status[23].component
                );
                assert_eq!(
                    msg.status[23].generic, 94,
                    "incorrect value for status[23].generic, expected 94, is {}",
                    msg.status[23].generic
                );
                assert_eq!(
                    msg.status[23].specific, 157,
                    "incorrect value for status[23].specific, expected 157, is {}",
                    msg.status[23].specific
                );
                assert_eq!(
                    msg.status[24].component, 47914,
                    "incorrect value for status[24].component, expected 47914, is {}",
                    msg.status[24].component
                );
                assert_eq!(
                    msg.status[24].generic, 124,
                    "incorrect value for status[24].generic, expected 124, is {}",
                    msg.status[24].generic
                );
                assert_eq!(
                    msg.status[24].specific, 6,
                    "incorrect value for status[24].specific, expected 6, is {}",
                    msg.status[24].specific
                );
                assert_eq!(
                    msg.status[25].component, 63329,
                    "incorrect value for status[25].component, expected 63329, is {}",
                    msg.status[25].component
                );
                assert_eq!(
                    msg.status[25].generic, 160,
                    "incorrect value for status[25].generic, expected 160, is {}",
                    msg.status[25].generic
                );
                assert_eq!(
                    msg.status[25].specific, 188,
                    "incorrect value for status[25].specific, expected 188, is {}",
                    msg.status[25].specific
                );
                assert_eq!(
                    msg.status[26].component, 30830,
                    "incorrect value for status[26].component, expected 30830, is {}",
                    msg.status[26].component
                );
                assert_eq!(
                    msg.status[26].generic, 254,
                    "incorrect value for status[26].generic, expected 254, is {}",
                    msg.status[26].generic
                );
                assert_eq!(
                    msg.status[26].specific, 214,
                    "incorrect value for status[26].specific, expected 214, is {}",
                    msg.status[26].specific
                );
                assert_eq!(
                    msg.status[27].component, 13166,
                    "incorrect value for status[27].component, expected 13166, is {}",
                    msg.status[27].component
                );
                assert_eq!(
                    msg.status[27].generic, 240,
                    "incorrect value for status[27].generic, expected 240, is {}",
                    msg.status[27].generic
                );
                assert_eq!(
                    msg.status[27].specific, 164,
                    "incorrect value for status[27].specific, expected 164, is {}",
                    msg.status[27].specific
                );
                assert_eq!(
                    msg.status[28].component, 4755,
                    "incorrect value for status[28].component, expected 4755, is {}",
                    msg.status[28].component
                );
                assert_eq!(
                    msg.status[28].generic, 74,
                    "incorrect value for status[28].generic, expected 74, is {}",
                    msg.status[28].generic
                );
                assert_eq!(
                    msg.status[28].specific, 178,
                    "incorrect value for status[28].specific, expected 178, is {}",
                    msg.status[28].specific
                );
                assert_eq!(
                    msg.status[29].component, 1091,
                    "incorrect value for status[29].component, expected 1091, is {}",
                    msg.status[29].component
                );
                assert_eq!(
                    msg.status[29].generic, 27,
                    "incorrect value for status[29].generic, expected 27, is {}",
                    msg.status[29].generic
                );
                assert_eq!(
                    msg.status[29].specific, 73,
                    "incorrect value for status[29].specific, expected 73, is {}",
                    msg.status[29].specific
                );
                assert_eq!(
                    msg.status[30].component, 16574,
                    "incorrect value for status[30].component, expected 16574, is {}",
                    msg.status[30].component
                );
                assert_eq!(
                    msg.status[30].generic, 179,
                    "incorrect value for status[30].generic, expected 179, is {}",
                    msg.status[30].generic
                );
                assert_eq!(
                    msg.status[30].specific, 146,
                    "incorrect value for status[30].specific, expected 146, is {}",
                    msg.status[30].specific
                );
                assert_eq!(
                    msg.status[31].component, 39293,
                    "incorrect value for status[31].component, expected 39293, is {}",
                    msg.status[31].component
                );
                assert_eq!(
                    msg.status[31].generic, 192,
                    "incorrect value for status[31].generic, expected 192, is {}",
                    msg.status[31].generic
                );
                assert_eq!(
                    msg.status[31].specific, 46,
                    "incorrect value for status[31].specific, expected 46, is {}",
                    msg.status[31].specific
                );
                assert_eq!(
                    msg.status[32].component, 17098,
                    "incorrect value for status[32].component, expected 17098, is {}",
                    msg.status[32].component
                );
                assert_eq!(
                    msg.status[32].generic, 248,
                    "incorrect value for status[32].generic, expected 248, is {}",
                    msg.status[32].generic
                );
                assert_eq!(
                    msg.status[32].specific, 46,
                    "incorrect value for status[32].specific, expected 46, is {}",
                    msg.status[32].specific
                );
                assert_eq!(
                    msg.status[33].component, 41256,
                    "incorrect value for status[33].component, expected 41256, is {}",
                    msg.status[33].component
                );
                assert_eq!(
                    msg.status[33].generic, 173,
                    "incorrect value for status[33].generic, expected 173, is {}",
                    msg.status[33].generic
                );
                assert_eq!(
                    msg.status[33].specific, 242,
                    "incorrect value for status[33].specific, expected 242, is {}",
                    msg.status[33].specific
                );
                assert_eq!(
                    msg.status[34].component, 982,
                    "incorrect value for status[34].component, expected 982, is {}",
                    msg.status[34].component
                );
                assert_eq!(
                    msg.status[34].generic, 11,
                    "incorrect value for status[34].generic, expected 11, is {}",
                    msg.status[34].generic
                );
                assert_eq!(
                    msg.status[34].specific, 1,
                    "incorrect value for status[34].specific, expected 1, is {}",
                    msg.status[34].specific
                );
                assert_eq!(
                    msg.status[35].component, 18038,
                    "incorrect value for status[35].component, expected 18038, is {}",
                    msg.status[35].component
                );
                assert_eq!(
                    msg.status[35].generic, 162,
                    "incorrect value for status[35].generic, expected 162, is {}",
                    msg.status[35].generic
                );
                assert_eq!(
                    msg.status[35].specific, 61,
                    "incorrect value for status[35].specific, expected 61, is {}",
                    msg.status[35].specific
                );
                assert_eq!(
                    msg.status[36].component, 7090,
                    "incorrect value for status[36].component, expected 7090, is {}",
                    msg.status[36].component
                );
                assert_eq!(
                    msg.status[36].generic, 156,
                    "incorrect value for status[36].generic, expected 156, is {}",
                    msg.status[36].generic
                );
                assert_eq!(
                    msg.status[36].specific, 40,
                    "incorrect value for status[36].specific, expected 40, is {}",
                    msg.status[36].specific
                );
                assert_eq!(
                    msg.status[37].component, 29119,
                    "incorrect value for status[37].component, expected 29119, is {}",
                    msg.status[37].component
                );
                assert_eq!(
                    msg.status[37].generic, 230,
                    "incorrect value for status[37].generic, expected 230, is {}",
                    msg.status[37].generic
                );
                assert_eq!(
                    msg.status[37].specific, 200,
                    "incorrect value for status[37].specific, expected 200, is {}",
                    msg.status[37].specific
                );
                assert_eq!(
                    msg.status[38].component, 2120,
                    "incorrect value for status[38].component, expected 2120, is {}",
                    msg.status[38].component
                );
                assert_eq!(
                    msg.status[38].generic, 215,
                    "incorrect value for status[38].generic, expected 215, is {}",
                    msg.status[38].generic
                );
                assert_eq!(
                    msg.status[38].specific, 245,
                    "incorrect value for status[38].specific, expected 245, is {}",
                    msg.status[38].specific
                );
                assert_eq!(
                    msg.status[39].component, 15182,
                    "incorrect value for status[39].component, expected 15182, is {}",
                    msg.status[39].component
                );
                assert_eq!(
                    msg.status[39].generic, 222,
                    "incorrect value for status[39].generic, expected 222, is {}",
                    msg.status[39].generic
                );
                assert_eq!(
                    msg.status[39].specific, 250,
                    "incorrect value for status[39].specific, expected 250, is {}",
                    msg.status[39].specific
                );
                assert_eq!(
                    msg.status[40].component, 8307,
                    "incorrect value for status[40].component, expected 8307, is {}",
                    msg.status[40].component
                );
                assert_eq!(
                    msg.status[40].generic, 33,
                    "incorrect value for status[40].generic, expected 33, is {}",
                    msg.status[40].generic
                );
                assert_eq!(
                    msg.status[40].specific, 30,
                    "incorrect value for status[40].specific, expected 30, is {}",
                    msg.status[40].specific
                );
                assert_eq!(
                    msg.status[41].component, 43731,
                    "incorrect value for status[41].component, expected 43731, is {}",
                    msg.status[41].component
                );
                assert_eq!(
                    msg.status[41].generic, 145,
                    "incorrect value for status[41].generic, expected 145, is {}",
                    msg.status[41].generic
                );
                assert_eq!(
                    msg.status[41].specific, 92,
                    "incorrect value for status[41].specific, expected 92, is {}",
                    msg.status[41].specific
                );
                assert_eq!(
                    msg.status[42].component, 19357,
                    "incorrect value for status[42].component, expected 19357, is {}",
                    msg.status[42].component
                );
                assert_eq!(
                    msg.status[42].generic, 24,
                    "incorrect value for status[42].generic, expected 24, is {}",
                    msg.status[42].generic
                );
                assert_eq!(
                    msg.status[42].specific, 169,
                    "incorrect value for status[42].specific, expected 169, is {}",
                    msg.status[42].specific
                );
                assert_eq!(
                    msg.status[43].component, 14086,
                    "incorrect value for status[43].component, expected 14086, is {}",
                    msg.status[43].component
                );
                assert_eq!(
                    msg.status[43].generic, 62,
                    "incorrect value for status[43].generic, expected 62, is {}",
                    msg.status[43].generic
                );
                assert_eq!(
                    msg.status[43].specific, 8,
                    "incorrect value for status[43].specific, expected 8, is {}",
                    msg.status[43].specific
                );
                assert_eq!(
                    msg.status[44].component, 21099,
                    "incorrect value for status[44].component, expected 21099, is {}",
                    msg.status[44].component
                );
                assert_eq!(
                    msg.status[44].generic, 140,
                    "incorrect value for status[44].generic, expected 140, is {}",
                    msg.status[44].generic
                );
                assert_eq!(
                    msg.status[44].specific, 49,
                    "incorrect value for status[44].specific, expected 49, is {}",
                    msg.status[44].specific
                );
                assert_eq!(
                    msg.status[45].component, 31411,
                    "incorrect value for status[45].component, expected 31411, is {}",
                    msg.status[45].component
                );
                assert_eq!(
                    msg.status[45].generic, 90,
                    "incorrect value for status[45].generic, expected 90, is {}",
                    msg.status[45].generic
                );
                assert_eq!(
                    msg.status[45].specific, 71,
                    "incorrect value for status[45].specific, expected 71, is {}",
                    msg.status[45].specific
                );
                assert_eq!(
                    msg.status[46].component, 22556,
                    "incorrect value for status[46].component, expected 22556, is {}",
                    msg.status[46].component
                );
                assert_eq!(
                    msg.status[46].generic, 103,
                    "incorrect value for status[46].generic, expected 103, is {}",
                    msg.status[46].generic
                );
                assert_eq!(
                    msg.status[46].specific, 51,
                    "incorrect value for status[46].specific, expected 51, is {}",
                    msg.status[46].specific
                );
                assert_eq!(
                    msg.status[47].component, 18609,
                    "incorrect value for status[47].component, expected 18609, is {}",
                    msg.status[47].component
                );
                assert_eq!(
                    msg.status[47].generic, 93,
                    "incorrect value for status[47].generic, expected 93, is {}",
                    msg.status[47].generic
                );
                assert_eq!(
                    msg.status[47].specific, 39,
                    "incorrect value for status[47].specific, expected 39, is {}",
                    msg.status[47].specific
                );
                assert_eq!(
                    msg.status[48].component, 2964,
                    "incorrect value for status[48].component, expected 2964, is {}",
                    msg.status[48].component
                );
                assert_eq!(
                    msg.status[48].generic, 202,
                    "incorrect value for status[48].generic, expected 202, is {}",
                    msg.status[48].generic
                );
                assert_eq!(
                    msg.status[48].specific, 42,
                    "incorrect value for status[48].specific, expected 42, is {}",
                    msg.status[48].specific
                );
                assert_eq!(
                    msg.status[49].component, 23586,
                    "incorrect value for status[49].component, expected 23586, is {}",
                    msg.status[49].component
                );
                assert_eq!(
                    msg.status[49].generic, 204,
                    "incorrect value for status[49].generic, expected 204, is {}",
                    msg.status[49].generic
                );
                assert_eq!(
                    msg.status[49].specific, 102,
                    "incorrect value for status[49].specific, expected 102, is {}",
                    msg.status[49].specific
                );
                assert_eq!(
                    msg.status[50].component, 25117,
                    "incorrect value for status[50].component, expected 25117, is {}",
                    msg.status[50].component
                );
                assert_eq!(
                    msg.status[50].generic, 249,
                    "incorrect value for status[50].generic, expected 249, is {}",
                    msg.status[50].generic
                );
                assert_eq!(
                    msg.status[50].specific, 91,
                    "incorrect value for status[50].specific, expected 91, is {}",
                    msg.status[50].specific
                );
                assert_eq!(
                    msg.status[51].component, 24454,
                    "incorrect value for status[51].component, expected 24454, is {}",
                    msg.status[51].component
                );
                assert_eq!(
                    msg.status[51].generic, 23,
                    "incorrect value for status[51].generic, expected 23, is {}",
                    msg.status[51].generic
                );
                assert_eq!(
                    msg.status[51].specific, 248,
                    "incorrect value for status[51].specific, expected 248, is {}",
                    msg.status[51].specific
                );
                assert_eq!(
                    msg.status[52].component, 5312,
                    "incorrect value for status[52].component, expected 5312, is {}",
                    msg.status[52].component
                );
                assert_eq!(
                    msg.status[52].generic, 83,
                    "incorrect value for status[52].generic, expected 83, is {}",
                    msg.status[52].generic
                );
                assert_eq!(
                    msg.status[52].specific, 195,
                    "incorrect value for status[52].specific, expected 195, is {}",
                    msg.status[52].specific
                );
                assert_eq!(
                    msg.status[53].component, 46175,
                    "incorrect value for status[53].component, expected 46175, is {}",
                    msg.status[53].component
                );
                assert_eq!(
                    msg.status[53].generic, 54,
                    "incorrect value for status[53].generic, expected 54, is {}",
                    msg.status[53].generic
                );
                assert_eq!(
                    msg.status[53].specific, 36,
                    "incorrect value for status[53].specific, expected 36, is {}",
                    msg.status[53].specific
                );
                assert_eq!(
                    msg.status[54].component, 19386,
                    "incorrect value for status[54].component, expected 19386, is {}",
                    msg.status[54].component
                );
                assert_eq!(
                    msg.status[54].generic, 64,
                    "incorrect value for status[54].generic, expected 64, is {}",
                    msg.status[54].generic
                );
                assert_eq!(
                    msg.status[54].specific, 20,
                    "incorrect value for status[54].specific, expected 20, is {}",
                    msg.status[54].specific
                );
                assert_eq!(
                    msg.status[55].component, 34205,
                    "incorrect value for status[55].component, expected 34205, is {}",
                    msg.status[55].component
                );
                assert_eq!(
                    msg.status[55].generic, 12,
                    "incorrect value for status[55].generic, expected 12, is {}",
                    msg.status[55].generic
                );
                assert_eq!(
                    msg.status[55].specific, 149,
                    "incorrect value for status[55].specific, expected 149, is {}",
                    msg.status[55].specific
                );
                assert_eq!(
                    msg.status[56].component, 3612,
                    "incorrect value for status[56].component, expected 3612, is {}",
                    msg.status[56].component
                );
                assert_eq!(
                    msg.status[56].generic, 185,
                    "incorrect value for status[56].generic, expected 185, is {}",
                    msg.status[56].generic
                );
                assert_eq!(
                    msg.status[56].specific, 129,
                    "incorrect value for status[56].specific, expected 129, is {}",
                    msg.status[56].specific
                );
                assert_eq!(
                    msg.status[57].component, 61285,
                    "incorrect value for status[57].component, expected 61285, is {}",
                    msg.status[57].component
                );
                assert_eq!(
                    msg.status[57].generic, 74,
                    "incorrect value for status[57].generic, expected 74, is {}",
                    msg.status[57].generic
                );
                assert_eq!(
                    msg.status[57].specific, 248,
                    "incorrect value for status[57].specific, expected 248, is {}",
                    msg.status[57].specific
                );
                assert_eq!(
                    msg.status[58].component, 7925,
                    "incorrect value for status[58].component, expected 7925, is {}",
                    msg.status[58].component
                );
                assert_eq!(
                    msg.status[58].generic, 228,
                    "incorrect value for status[58].generic, expected 228, is {}",
                    msg.status[58].generic
                );
                assert_eq!(
                    msg.status[58].specific, 88,
                    "incorrect value for status[58].specific, expected 88, is {}",
                    msg.status[58].specific
                );
                assert_eq!(
                    msg.status[59].component, 54414,
                    "incorrect value for status[59].component, expected 54414, is {}",
                    msg.status[59].component
                );
                assert_eq!(
                    msg.status[59].generic, 53,
                    "incorrect value for status[59].generic, expected 53, is {}",
                    msg.status[59].generic
                );
                assert_eq!(
                    msg.status[59].specific, 224,
                    "incorrect value for status[59].specific, expected 224, is {}",
                    msg.status[59].specific
                );
                assert_eq!(
                    msg.uptime, 1657804265,
                    "incorrect value for uptime, expected 1657804265, is {}",
                    msg.uptime
                );
            }
            _ => panic!("Invalid message type! Expected a MsgStatusReport"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_system_msg_status_report`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_system_msg_status_report() {
    {
        let mut payload = Cursor::new(vec![
            85, 254, 255, 6, 84, 252, 82, 253, 177, 95, 3, 60, 143, 90, 233, 21, 208, 98, 247, 203,
            221, 198, 156, 207, 217, 238, 162, 136, 154, 11, 114, 236, 134, 235, 12, 133, 9, 30,
            175, 145, 26, 114, 215, 20, 146, 249, 54, 54, 133, 193, 106, 186, 210, 183, 0, 129, 5,
            248, 225, 149, 135, 127, 2, 26, 88, 92, 10, 103, 73, 3, 103, 68, 76, 184, 33, 206, 194,
            163, 123, 30, 151, 176, 149, 172, 184, 231, 118, 230, 200, 168, 100, 109, 10, 233, 4,
            60, 247, 82, 215, 166, 28, 138, 110, 45, 98, 218, 244, 179, 126, 107, 92, 124, 94, 157,
            42, 187, 124, 6, 97, 247, 160, 188, 110, 120, 254, 214, 110, 51, 240, 164, 147, 18, 74,
            178, 67, 4, 27, 73, 190, 64, 179, 146, 125, 153, 192, 46, 202, 66, 248, 46, 40, 161,
            173, 242, 214, 3, 11, 1, 118, 70, 162, 61, 178, 27, 156, 40, 191, 113, 230, 200, 72, 8,
            215, 245, 78, 59, 222, 250, 115, 32, 33, 30, 211, 170, 145, 92, 157, 75, 24, 169, 6,
            55, 62, 8, 107, 82, 140, 49, 179, 122, 90, 71, 28, 88, 103, 51, 177, 72, 93, 39, 148,
            11, 202, 42, 34, 92, 204, 102, 29, 98, 249, 91, 134, 95, 23, 248, 192, 20, 83, 195, 95,
            180, 54, 36, 186, 75, 64, 20, 157, 133, 12, 149, 28, 14, 185, 129, 101, 239, 74, 248,
            245, 30, 228, 88, 142, 212, 53, 224, 158, 166,
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
        let sbp_msg = sbp::messages::Sbp::MsgStatusReport(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgStatusReport(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xfffe,
                    "Incorrect message type, expected 0xfffe, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x5406,
                    "incorrect sender id, expected 0x5406, is {sender_id}"
                );
                assert_eq!(
                    msg.reporting_system, 64850,
                    "incorrect value for reporting_system, expected 64850, is {}",
                    msg.reporting_system
                );
                assert_eq!(
                    msg.sbp_version, 24497,
                    "incorrect value for sbp_version, expected 24497, is {}",
                    msg.sbp_version
                );
                assert_eq!(
                    msg.sequence, 1519336451,
                    "incorrect value for sequence, expected 1519336451, is {}",
                    msg.sequence
                );
                assert_eq!(
                    msg.status[0].component, 52215,
                    "incorrect value for status[0].component, expected 52215, is {}",
                    msg.status[0].component
                );
                assert_eq!(
                    msg.status[0].generic, 221,
                    "incorrect value for status[0].generic, expected 221, is {}",
                    msg.status[0].generic
                );
                assert_eq!(
                    msg.status[0].specific, 198,
                    "incorrect value for status[0].specific, expected 198, is {}",
                    msg.status[0].specific
                );
                assert_eq!(
                    msg.status[1].component, 53148,
                    "incorrect value for status[1].component, expected 53148, is {}",
                    msg.status[1].component
                );
                assert_eq!(
                    msg.status[1].generic, 217,
                    "incorrect value for status[1].generic, expected 217, is {}",
                    msg.status[1].generic
                );
                assert_eq!(
                    msg.status[1].specific, 238,
                    "incorrect value for status[1].specific, expected 238, is {}",
                    msg.status[1].specific
                );
                assert_eq!(
                    msg.status[2].component, 34978,
                    "incorrect value for status[2].component, expected 34978, is {}",
                    msg.status[2].component
                );
                assert_eq!(
                    msg.status[2].generic, 154,
                    "incorrect value for status[2].generic, expected 154, is {}",
                    msg.status[2].generic
                );
                assert_eq!(
                    msg.status[2].specific, 11,
                    "incorrect value for status[2].specific, expected 11, is {}",
                    msg.status[2].specific
                );
                assert_eq!(
                    msg.status[3].component, 60530,
                    "incorrect value for status[3].component, expected 60530, is {}",
                    msg.status[3].component
                );
                assert_eq!(
                    msg.status[3].generic, 134,
                    "incorrect value for status[3].generic, expected 134, is {}",
                    msg.status[3].generic
                );
                assert_eq!(
                    msg.status[3].specific, 235,
                    "incorrect value for status[3].specific, expected 235, is {}",
                    msg.status[3].specific
                );
                assert_eq!(
                    msg.status[4].component, 34060,
                    "incorrect value for status[4].component, expected 34060, is {}",
                    msg.status[4].component
                );
                assert_eq!(
                    msg.status[4].generic, 9,
                    "incorrect value for status[4].generic, expected 9, is {}",
                    msg.status[4].generic
                );
                assert_eq!(
                    msg.status[4].specific, 30,
                    "incorrect value for status[4].specific, expected 30, is {}",
                    msg.status[4].specific
                );
                assert_eq!(
                    msg.status[5].component, 37295,
                    "incorrect value for status[5].component, expected 37295, is {}",
                    msg.status[5].component
                );
                assert_eq!(
                    msg.status[5].generic, 26,
                    "incorrect value for status[5].generic, expected 26, is {}",
                    msg.status[5].generic
                );
                assert_eq!(
                    msg.status[5].specific, 114,
                    "incorrect value for status[5].specific, expected 114, is {}",
                    msg.status[5].specific
                );
                assert_eq!(
                    msg.status[6].component, 5335,
                    "incorrect value for status[6].component, expected 5335, is {}",
                    msg.status[6].component
                );
                assert_eq!(
                    msg.status[6].generic, 146,
                    "incorrect value for status[6].generic, expected 146, is {}",
                    msg.status[6].generic
                );
                assert_eq!(
                    msg.status[6].specific, 249,
                    "incorrect value for status[6].specific, expected 249, is {}",
                    msg.status[6].specific
                );
                assert_eq!(
                    msg.status[7].component, 13878,
                    "incorrect value for status[7].component, expected 13878, is {}",
                    msg.status[7].component
                );
                assert_eq!(
                    msg.status[7].generic, 133,
                    "incorrect value for status[7].generic, expected 133, is {}",
                    msg.status[7].generic
                );
                assert_eq!(
                    msg.status[7].specific, 193,
                    "incorrect value for status[7].specific, expected 193, is {}",
                    msg.status[7].specific
                );
                assert_eq!(
                    msg.status[8].component, 47722,
                    "incorrect value for status[8].component, expected 47722, is {}",
                    msg.status[8].component
                );
                assert_eq!(
                    msg.status[8].generic, 210,
                    "incorrect value for status[8].generic, expected 210, is {}",
                    msg.status[8].generic
                );
                assert_eq!(
                    msg.status[8].specific, 183,
                    "incorrect value for status[8].specific, expected 183, is {}",
                    msg.status[8].specific
                );
                assert_eq!(
                    msg.status[9].component, 33024,
                    "incorrect value for status[9].component, expected 33024, is {}",
                    msg.status[9].component
                );
                assert_eq!(
                    msg.status[9].generic, 5,
                    "incorrect value for status[9].generic, expected 5, is {}",
                    msg.status[9].generic
                );
                assert_eq!(
                    msg.status[9].specific, 248,
                    "incorrect value for status[9].specific, expected 248, is {}",
                    msg.status[9].specific
                );
                assert_eq!(
                    msg.status[10].component, 38369,
                    "incorrect value for status[10].component, expected 38369, is {}",
                    msg.status[10].component
                );
                assert_eq!(
                    msg.status[10].generic, 135,
                    "incorrect value for status[10].generic, expected 135, is {}",
                    msg.status[10].generic
                );
                assert_eq!(
                    msg.status[10].specific, 127,
                    "incorrect value for status[10].specific, expected 127, is {}",
                    msg.status[10].specific
                );
                assert_eq!(
                    msg.status[11].component, 6658,
                    "incorrect value for status[11].component, expected 6658, is {}",
                    msg.status[11].component
                );
                assert_eq!(
                    msg.status[11].generic, 88,
                    "incorrect value for status[11].generic, expected 88, is {}",
                    msg.status[11].generic
                );
                assert_eq!(
                    msg.status[11].specific, 92,
                    "incorrect value for status[11].specific, expected 92, is {}",
                    msg.status[11].specific
                );
                assert_eq!(
                    msg.status[12].component, 26378,
                    "incorrect value for status[12].component, expected 26378, is {}",
                    msg.status[12].component
                );
                assert_eq!(
                    msg.status[12].generic, 73,
                    "incorrect value for status[12].generic, expected 73, is {}",
                    msg.status[12].generic
                );
                assert_eq!(
                    msg.status[12].specific, 3,
                    "incorrect value for status[12].specific, expected 3, is {}",
                    msg.status[12].specific
                );
                assert_eq!(
                    msg.status[13].component, 17511,
                    "incorrect value for status[13].component, expected 17511, is {}",
                    msg.status[13].component
                );
                assert_eq!(
                    msg.status[13].generic, 76,
                    "incorrect value for status[13].generic, expected 76, is {}",
                    msg.status[13].generic
                );
                assert_eq!(
                    msg.status[13].specific, 184,
                    "incorrect value for status[13].specific, expected 184, is {}",
                    msg.status[13].specific
                );
                assert_eq!(
                    msg.status[14].component, 52769,
                    "incorrect value for status[14].component, expected 52769, is {}",
                    msg.status[14].component
                );
                assert_eq!(
                    msg.status[14].generic, 194,
                    "incorrect value for status[14].generic, expected 194, is {}",
                    msg.status[14].generic
                );
                assert_eq!(
                    msg.status[14].specific, 163,
                    "incorrect value for status[14].specific, expected 163, is {}",
                    msg.status[14].specific
                );
                assert_eq!(
                    msg.status[15].component, 7803,
                    "incorrect value for status[15].component, expected 7803, is {}",
                    msg.status[15].component
                );
                assert_eq!(
                    msg.status[15].generic, 151,
                    "incorrect value for status[15].generic, expected 151, is {}",
                    msg.status[15].generic
                );
                assert_eq!(
                    msg.status[15].specific, 176,
                    "incorrect value for status[15].specific, expected 176, is {}",
                    msg.status[15].specific
                );
                assert_eq!(
                    msg.status[16].component, 44181,
                    "incorrect value for status[16].component, expected 44181, is {}",
                    msg.status[16].component
                );
                assert_eq!(
                    msg.status[16].generic, 184,
                    "incorrect value for status[16].generic, expected 184, is {}",
                    msg.status[16].generic
                );
                assert_eq!(
                    msg.status[16].specific, 231,
                    "incorrect value for status[16].specific, expected 231, is {}",
                    msg.status[16].specific
                );
                assert_eq!(
                    msg.status[17].component, 58998,
                    "incorrect value for status[17].component, expected 58998, is {}",
                    msg.status[17].component
                );
                assert_eq!(
                    msg.status[17].generic, 200,
                    "incorrect value for status[17].generic, expected 200, is {}",
                    msg.status[17].generic
                );
                assert_eq!(
                    msg.status[17].specific, 168,
                    "incorrect value for status[17].specific, expected 168, is {}",
                    msg.status[17].specific
                );
                assert_eq!(
                    msg.status[18].component, 28004,
                    "incorrect value for status[18].component, expected 28004, is {}",
                    msg.status[18].component
                );
                assert_eq!(
                    msg.status[18].generic, 10,
                    "incorrect value for status[18].generic, expected 10, is {}",
                    msg.status[18].generic
                );
                assert_eq!(
                    msg.status[18].specific, 233,
                    "incorrect value for status[18].specific, expected 233, is {}",
                    msg.status[18].specific
                );
                assert_eq!(
                    msg.status[19].component, 15364,
                    "incorrect value for status[19].component, expected 15364, is {}",
                    msg.status[19].component
                );
                assert_eq!(
                    msg.status[19].generic, 247,
                    "incorrect value for status[19].generic, expected 247, is {}",
                    msg.status[19].generic
                );
                assert_eq!(
                    msg.status[19].specific, 82,
                    "incorrect value for status[19].specific, expected 82, is {}",
                    msg.status[19].specific
                );
                assert_eq!(
                    msg.status[20].component, 42711,
                    "incorrect value for status[20].component, expected 42711, is {}",
                    msg.status[20].component
                );
                assert_eq!(
                    msg.status[20].generic, 28,
                    "incorrect value for status[20].generic, expected 28, is {}",
                    msg.status[20].generic
                );
                assert_eq!(
                    msg.status[20].specific, 138,
                    "incorrect value for status[20].specific, expected 138, is {}",
                    msg.status[20].specific
                );
                assert_eq!(
                    msg.status[21].component, 11630,
                    "incorrect value for status[21].component, expected 11630, is {}",
                    msg.status[21].component
                );
                assert_eq!(
                    msg.status[21].generic, 98,
                    "incorrect value for status[21].generic, expected 98, is {}",
                    msg.status[21].generic
                );
                assert_eq!(
                    msg.status[21].specific, 218,
                    "incorrect value for status[21].specific, expected 218, is {}",
                    msg.status[21].specific
                );
                assert_eq!(
                    msg.status[22].component, 46068,
                    "incorrect value for status[22].component, expected 46068, is {}",
                    msg.status[22].component
                );
                assert_eq!(
                    msg.status[22].generic, 126,
                    "incorrect value for status[22].generic, expected 126, is {}",
                    msg.status[22].generic
                );
                assert_eq!(
                    msg.status[22].specific, 107,
                    "incorrect value for status[22].specific, expected 107, is {}",
                    msg.status[22].specific
                );
                assert_eq!(
                    msg.status[23].component, 31836,
                    "incorrect value for status[23].component, expected 31836, is {}",
                    msg.status[23].component
                );
                assert_eq!(
                    msg.status[23].generic, 94,
                    "incorrect value for status[23].generic, expected 94, is {}",
                    msg.status[23].generic
                );
                assert_eq!(
                    msg.status[23].specific, 157,
                    "incorrect value for status[23].specific, expected 157, is {}",
                    msg.status[23].specific
                );
                assert_eq!(
                    msg.status[24].component, 47914,
                    "incorrect value for status[24].component, expected 47914, is {}",
                    msg.status[24].component
                );
                assert_eq!(
                    msg.status[24].generic, 124,
                    "incorrect value for status[24].generic, expected 124, is {}",
                    msg.status[24].generic
                );
                assert_eq!(
                    msg.status[24].specific, 6,
                    "incorrect value for status[24].specific, expected 6, is {}",
                    msg.status[24].specific
                );
                assert_eq!(
                    msg.status[25].component, 63329,
                    "incorrect value for status[25].component, expected 63329, is {}",
                    msg.status[25].component
                );
                assert_eq!(
                    msg.status[25].generic, 160,
                    "incorrect value for status[25].generic, expected 160, is {}",
                    msg.status[25].generic
                );
                assert_eq!(
                    msg.status[25].specific, 188,
                    "incorrect value for status[25].specific, expected 188, is {}",
                    msg.status[25].specific
                );
                assert_eq!(
                    msg.status[26].component, 30830,
                    "incorrect value for status[26].component, expected 30830, is {}",
                    msg.status[26].component
                );
                assert_eq!(
                    msg.status[26].generic, 254,
                    "incorrect value for status[26].generic, expected 254, is {}",
                    msg.status[26].generic
                );
                assert_eq!(
                    msg.status[26].specific, 214,
                    "incorrect value for status[26].specific, expected 214, is {}",
                    msg.status[26].specific
                );
                assert_eq!(
                    msg.status[27].component, 13166,
                    "incorrect value for status[27].component, expected 13166, is {}",
                    msg.status[27].component
                );
                assert_eq!(
                    msg.status[27].generic, 240,
                    "incorrect value for status[27].generic, expected 240, is {}",
                    msg.status[27].generic
                );
                assert_eq!(
                    msg.status[27].specific, 164,
                    "incorrect value for status[27].specific, expected 164, is {}",
                    msg.status[27].specific
                );
                assert_eq!(
                    msg.status[28].component, 4755,
                    "incorrect value for status[28].component, expected 4755, is {}",
                    msg.status[28].component
                );
                assert_eq!(
                    msg.status[28].generic, 74,
                    "incorrect value for status[28].generic, expected 74, is {}",
                    msg.status[28].generic
                );
                assert_eq!(
                    msg.status[28].specific, 178,
                    "incorrect value for status[28].specific, expected 178, is {}",
                    msg.status[28].specific
                );
                assert_eq!(
                    msg.status[29].component, 1091,
                    "incorrect value for status[29].component, expected 1091, is {}",
                    msg.status[29].component
                );
                assert_eq!(
                    msg.status[29].generic, 27,
                    "incorrect value for status[29].generic, expected 27, is {}",
                    msg.status[29].generic
                );
                assert_eq!(
                    msg.status[29].specific, 73,
                    "incorrect value for status[29].specific, expected 73, is {}",
                    msg.status[29].specific
                );
                assert_eq!(
                    msg.status[30].component, 16574,
                    "incorrect value for status[30].component, expected 16574, is {}",
                    msg.status[30].component
                );
                assert_eq!(
                    msg.status[30].generic, 179,
                    "incorrect value for status[30].generic, expected 179, is {}",
                    msg.status[30].generic
                );
                assert_eq!(
                    msg.status[30].specific, 146,
                    "incorrect value for status[30].specific, expected 146, is {}",
                    msg.status[30].specific
                );
                assert_eq!(
                    msg.status[31].component, 39293,
                    "incorrect value for status[31].component, expected 39293, is {}",
                    msg.status[31].component
                );
                assert_eq!(
                    msg.status[31].generic, 192,
                    "incorrect value for status[31].generic, expected 192, is {}",
                    msg.status[31].generic
                );
                assert_eq!(
                    msg.status[31].specific, 46,
                    "incorrect value for status[31].specific, expected 46, is {}",
                    msg.status[31].specific
                );
                assert_eq!(
                    msg.status[32].component, 17098,
                    "incorrect value for status[32].component, expected 17098, is {}",
                    msg.status[32].component
                );
                assert_eq!(
                    msg.status[32].generic, 248,
                    "incorrect value for status[32].generic, expected 248, is {}",
                    msg.status[32].generic
                );
                assert_eq!(
                    msg.status[32].specific, 46,
                    "incorrect value for status[32].specific, expected 46, is {}",
                    msg.status[32].specific
                );
                assert_eq!(
                    msg.status[33].component, 41256,
                    "incorrect value for status[33].component, expected 41256, is {}",
                    msg.status[33].component
                );
                assert_eq!(
                    msg.status[33].generic, 173,
                    "incorrect value for status[33].generic, expected 173, is {}",
                    msg.status[33].generic
                );
                assert_eq!(
                    msg.status[33].specific, 242,
                    "incorrect value for status[33].specific, expected 242, is {}",
                    msg.status[33].specific
                );
                assert_eq!(
                    msg.status[34].component, 982,
                    "incorrect value for status[34].component, expected 982, is {}",
                    msg.status[34].component
                );
                assert_eq!(
                    msg.status[34].generic, 11,
                    "incorrect value for status[34].generic, expected 11, is {}",
                    msg.status[34].generic
                );
                assert_eq!(
                    msg.status[34].specific, 1,
                    "incorrect value for status[34].specific, expected 1, is {}",
                    msg.status[34].specific
                );
                assert_eq!(
                    msg.status[35].component, 18038,
                    "incorrect value for status[35].component, expected 18038, is {}",
                    msg.status[35].component
                );
                assert_eq!(
                    msg.status[35].generic, 162,
                    "incorrect value for status[35].generic, expected 162, is {}",
                    msg.status[35].generic
                );
                assert_eq!(
                    msg.status[35].specific, 61,
                    "incorrect value for status[35].specific, expected 61, is {}",
                    msg.status[35].specific
                );
                assert_eq!(
                    msg.status[36].component, 7090,
                    "incorrect value for status[36].component, expected 7090, is {}",
                    msg.status[36].component
                );
                assert_eq!(
                    msg.status[36].generic, 156,
                    "incorrect value for status[36].generic, expected 156, is {}",
                    msg.status[36].generic
                );
                assert_eq!(
                    msg.status[36].specific, 40,
                    "incorrect value for status[36].specific, expected 40, is {}",
                    msg.status[36].specific
                );
                assert_eq!(
                    msg.status[37].component, 29119,
                    "incorrect value for status[37].component, expected 29119, is {}",
                    msg.status[37].component
                );
                assert_eq!(
                    msg.status[37].generic, 230,
                    "incorrect value for status[37].generic, expected 230, is {}",
                    msg.status[37].generic
                );
                assert_eq!(
                    msg.status[37].specific, 200,
                    "incorrect value for status[37].specific, expected 200, is {}",
                    msg.status[37].specific
                );
                assert_eq!(
                    msg.status[38].component, 2120,
                    "incorrect value for status[38].component, expected 2120, is {}",
                    msg.status[38].component
                );
                assert_eq!(
                    msg.status[38].generic, 215,
                    "incorrect value for status[38].generic, expected 215, is {}",
                    msg.status[38].generic
                );
                assert_eq!(
                    msg.status[38].specific, 245,
                    "incorrect value for status[38].specific, expected 245, is {}",
                    msg.status[38].specific
                );
                assert_eq!(
                    msg.status[39].component, 15182,
                    "incorrect value for status[39].component, expected 15182, is {}",
                    msg.status[39].component
                );
                assert_eq!(
                    msg.status[39].generic, 222,
                    "incorrect value for status[39].generic, expected 222, is {}",
                    msg.status[39].generic
                );
                assert_eq!(
                    msg.status[39].specific, 250,
                    "incorrect value for status[39].specific, expected 250, is {}",
                    msg.status[39].specific
                );
                assert_eq!(
                    msg.status[40].component, 8307,
                    "incorrect value for status[40].component, expected 8307, is {}",
                    msg.status[40].component
                );
                assert_eq!(
                    msg.status[40].generic, 33,
                    "incorrect value for status[40].generic, expected 33, is {}",
                    msg.status[40].generic
                );
                assert_eq!(
                    msg.status[40].specific, 30,
                    "incorrect value for status[40].specific, expected 30, is {}",
                    msg.status[40].specific
                );
                assert_eq!(
                    msg.status[41].component, 43731,
                    "incorrect value for status[41].component, expected 43731, is {}",
                    msg.status[41].component
                );
                assert_eq!(
                    msg.status[41].generic, 145,
                    "incorrect value for status[41].generic, expected 145, is {}",
                    msg.status[41].generic
                );
                assert_eq!(
                    msg.status[41].specific, 92,
                    "incorrect value for status[41].specific, expected 92, is {}",
                    msg.status[41].specific
                );
                assert_eq!(
                    msg.status[42].component, 19357,
                    "incorrect value for status[42].component, expected 19357, is {}",
                    msg.status[42].component
                );
                assert_eq!(
                    msg.status[42].generic, 24,
                    "incorrect value for status[42].generic, expected 24, is {}",
                    msg.status[42].generic
                );
                assert_eq!(
                    msg.status[42].specific, 169,
                    "incorrect value for status[42].specific, expected 169, is {}",
                    msg.status[42].specific
                );
                assert_eq!(
                    msg.status[43].component, 14086,
                    "incorrect value for status[43].component, expected 14086, is {}",
                    msg.status[43].component
                );
                assert_eq!(
                    msg.status[43].generic, 62,
                    "incorrect value for status[43].generic, expected 62, is {}",
                    msg.status[43].generic
                );
                assert_eq!(
                    msg.status[43].specific, 8,
                    "incorrect value for status[43].specific, expected 8, is {}",
                    msg.status[43].specific
                );
                assert_eq!(
                    msg.status[44].component, 21099,
                    "incorrect value for status[44].component, expected 21099, is {}",
                    msg.status[44].component
                );
                assert_eq!(
                    msg.status[44].generic, 140,
                    "incorrect value for status[44].generic, expected 140, is {}",
                    msg.status[44].generic
                );
                assert_eq!(
                    msg.status[44].specific, 49,
                    "incorrect value for status[44].specific, expected 49, is {}",
                    msg.status[44].specific
                );
                assert_eq!(
                    msg.status[45].component, 31411,
                    "incorrect value for status[45].component, expected 31411, is {}",
                    msg.status[45].component
                );
                assert_eq!(
                    msg.status[45].generic, 90,
                    "incorrect value for status[45].generic, expected 90, is {}",
                    msg.status[45].generic
                );
                assert_eq!(
                    msg.status[45].specific, 71,
                    "incorrect value for status[45].specific, expected 71, is {}",
                    msg.status[45].specific
                );
                assert_eq!(
                    msg.status[46].component, 22556,
                    "incorrect value for status[46].component, expected 22556, is {}",
                    msg.status[46].component
                );
                assert_eq!(
                    msg.status[46].generic, 103,
                    "incorrect value for status[46].generic, expected 103, is {}",
                    msg.status[46].generic
                );
                assert_eq!(
                    msg.status[46].specific, 51,
                    "incorrect value for status[46].specific, expected 51, is {}",
                    msg.status[46].specific
                );
                assert_eq!(
                    msg.status[47].component, 18609,
                    "incorrect value for status[47].component, expected 18609, is {}",
                    msg.status[47].component
                );
                assert_eq!(
                    msg.status[47].generic, 93,
                    "incorrect value for status[47].generic, expected 93, is {}",
                    msg.status[47].generic
                );
                assert_eq!(
                    msg.status[47].specific, 39,
                    "incorrect value for status[47].specific, expected 39, is {}",
                    msg.status[47].specific
                );
                assert_eq!(
                    msg.status[48].component, 2964,
                    "incorrect value for status[48].component, expected 2964, is {}",
                    msg.status[48].component
                );
                assert_eq!(
                    msg.status[48].generic, 202,
                    "incorrect value for status[48].generic, expected 202, is {}",
                    msg.status[48].generic
                );
                assert_eq!(
                    msg.status[48].specific, 42,
                    "incorrect value for status[48].specific, expected 42, is {}",
                    msg.status[48].specific
                );
                assert_eq!(
                    msg.status[49].component, 23586,
                    "incorrect value for status[49].component, expected 23586, is {}",
                    msg.status[49].component
                );
                assert_eq!(
                    msg.status[49].generic, 204,
                    "incorrect value for status[49].generic, expected 204, is {}",
                    msg.status[49].generic
                );
                assert_eq!(
                    msg.status[49].specific, 102,
                    "incorrect value for status[49].specific, expected 102, is {}",
                    msg.status[49].specific
                );
                assert_eq!(
                    msg.status[50].component, 25117,
                    "incorrect value for status[50].component, expected 25117, is {}",
                    msg.status[50].component
                );
                assert_eq!(
                    msg.status[50].generic, 249,
                    "incorrect value for status[50].generic, expected 249, is {}",
                    msg.status[50].generic
                );
                assert_eq!(
                    msg.status[50].specific, 91,
                    "incorrect value for status[50].specific, expected 91, is {}",
                    msg.status[50].specific
                );
                assert_eq!(
                    msg.status[51].component, 24454,
                    "incorrect value for status[51].component, expected 24454, is {}",
                    msg.status[51].component
                );
                assert_eq!(
                    msg.status[51].generic, 23,
                    "incorrect value for status[51].generic, expected 23, is {}",
                    msg.status[51].generic
                );
                assert_eq!(
                    msg.status[51].specific, 248,
                    "incorrect value for status[51].specific, expected 248, is {}",
                    msg.status[51].specific
                );
                assert_eq!(
                    msg.status[52].component, 5312,
                    "incorrect value for status[52].component, expected 5312, is {}",
                    msg.status[52].component
                );
                assert_eq!(
                    msg.status[52].generic, 83,
                    "incorrect value for status[52].generic, expected 83, is {}",
                    msg.status[52].generic
                );
                assert_eq!(
                    msg.status[52].specific, 195,
                    "incorrect value for status[52].specific, expected 195, is {}",
                    msg.status[52].specific
                );
                assert_eq!(
                    msg.status[53].component, 46175,
                    "incorrect value for status[53].component, expected 46175, is {}",
                    msg.status[53].component
                );
                assert_eq!(
                    msg.status[53].generic, 54,
                    "incorrect value for status[53].generic, expected 54, is {}",
                    msg.status[53].generic
                );
                assert_eq!(
                    msg.status[53].specific, 36,
                    "incorrect value for status[53].specific, expected 36, is {}",
                    msg.status[53].specific
                );
                assert_eq!(
                    msg.status[54].component, 19386,
                    "incorrect value for status[54].component, expected 19386, is {}",
                    msg.status[54].component
                );
                assert_eq!(
                    msg.status[54].generic, 64,
                    "incorrect value for status[54].generic, expected 64, is {}",
                    msg.status[54].generic
                );
                assert_eq!(
                    msg.status[54].specific, 20,
                    "incorrect value for status[54].specific, expected 20, is {}",
                    msg.status[54].specific
                );
                assert_eq!(
                    msg.status[55].component, 34205,
                    "incorrect value for status[55].component, expected 34205, is {}",
                    msg.status[55].component
                );
                assert_eq!(
                    msg.status[55].generic, 12,
                    "incorrect value for status[55].generic, expected 12, is {}",
                    msg.status[55].generic
                );
                assert_eq!(
                    msg.status[55].specific, 149,
                    "incorrect value for status[55].specific, expected 149, is {}",
                    msg.status[55].specific
                );
                assert_eq!(
                    msg.status[56].component, 3612,
                    "incorrect value for status[56].component, expected 3612, is {}",
                    msg.status[56].component
                );
                assert_eq!(
                    msg.status[56].generic, 185,
                    "incorrect value for status[56].generic, expected 185, is {}",
                    msg.status[56].generic
                );
                assert_eq!(
                    msg.status[56].specific, 129,
                    "incorrect value for status[56].specific, expected 129, is {}",
                    msg.status[56].specific
                );
                assert_eq!(
                    msg.status[57].component, 61285,
                    "incorrect value for status[57].component, expected 61285, is {}",
                    msg.status[57].component
                );
                assert_eq!(
                    msg.status[57].generic, 74,
                    "incorrect value for status[57].generic, expected 74, is {}",
                    msg.status[57].generic
                );
                assert_eq!(
                    msg.status[57].specific, 248,
                    "incorrect value for status[57].specific, expected 248, is {}",
                    msg.status[57].specific
                );
                assert_eq!(
                    msg.status[58].component, 7925,
                    "incorrect value for status[58].component, expected 7925, is {}",
                    msg.status[58].component
                );
                assert_eq!(
                    msg.status[58].generic, 228,
                    "incorrect value for status[58].generic, expected 228, is {}",
                    msg.status[58].generic
                );
                assert_eq!(
                    msg.status[58].specific, 88,
                    "incorrect value for status[58].specific, expected 88, is {}",
                    msg.status[58].specific
                );
                assert_eq!(
                    msg.status[59].component, 54414,
                    "incorrect value for status[59].component, expected 54414, is {}",
                    msg.status[59].component
                );
                assert_eq!(
                    msg.status[59].generic, 53,
                    "incorrect value for status[59].generic, expected 53, is {}",
                    msg.status[59].generic
                );
                assert_eq!(
                    msg.status[59].specific, 224,
                    "incorrect value for status[59].specific, expected 224, is {}",
                    msg.status[59].specific
                );
                assert_eq!(
                    msg.uptime, 1657804265,
                    "incorrect value for uptime, expected 1657804265, is {}",
                    msg.uptime
                );
            }
            _ => panic!("Invalid message type! Expected a MsgStatusReport"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
