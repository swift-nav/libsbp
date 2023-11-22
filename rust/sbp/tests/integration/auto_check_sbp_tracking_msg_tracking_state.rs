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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingState.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_tracking_msg_tracking_state() {
    {
        let mut payload = Cursor::new(vec![
            85, 65, 0, 55, 129, 252, 117, 184, 3, 102, 38, 106, 140, 141, 25, 4, 90, 195, 246, 108,
            75, 82, 137, 127, 45, 163, 32, 46, 187, 93, 153, 60, 201, 147, 23, 29, 5, 208, 181, 30,
            219, 69, 254, 136, 3, 121, 33, 98, 144, 215, 133, 182, 14, 56, 169, 77, 218, 62, 242,
            84, 171, 249, 152, 137, 131, 130, 193, 21, 42, 68, 253, 227, 216, 227, 24, 26, 210,
            179, 19, 15, 227, 255, 122, 75, 187, 200, 217, 48, 218, 122, 187, 238, 142, 149, 238,
            55, 251, 212, 128, 160, 194, 104, 113, 255, 141, 62, 43, 69, 245, 39, 100, 230, 108,
            56, 247, 68, 149, 143, 137, 101, 233, 70, 49, 165, 38, 110, 218, 230, 80, 213, 196,
            179, 139, 128, 15, 178, 196, 171, 8, 212, 97, 194, 83, 233, 79, 99, 55, 90, 31, 180, 5,
            25, 105, 186, 22, 224, 80, 111, 8, 48, 106, 166, 4, 48, 156, 49, 86, 19, 142, 146, 91,
            124, 115, 64, 28, 230, 115, 178, 190, 131, 16, 242, 105, 59, 182, 113, 192, 180, 48,
            179, 166, 31, 172, 211, 77, 228, 140, 49, 128, 77, 240, 194, 134, 194, 41, 58, 18, 53,
            129, 55, 91, 72, 134, 92, 33, 224, 157, 56, 186, 54, 224, 174, 82, 84, 148, 190, 236,
            54, 62, 67, 52, 215, 57, 254, 16, 133, 36, 174, 219, 172, 145, 17, 192, 179, 111, 97,
            207, 56, 208, 134, 180, 17, 43, 226, 255, 182, 140, 113, 141, 111,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingState(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x41,
                    "Incorrect message type, expected 0x41, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x8137,
                    "incorrect sender id, expected 0x8137, is {sender_id}"
                );
                assert_eq!(
                    msg.states[0].cn0, 102,
                    "incorrect value for states[0].cn0, expected 102, is {}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].fcn, 3,
                    "incorrect value for states[0].fcn, expected 3, is {}",
                    msg.states[0].fcn
                );
                assert_eq!(
                    msg.states[0].sid.code, 184,
                    "incorrect value for states[0].sid.code, expected 184, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.sat, 117,
                    "incorrect value for states[0].sid.sat, expected 117, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[1].cn0, 141,
                    "incorrect value for states[1].cn0, expected 141, is {}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].fcn, 140,
                    "incorrect value for states[1].fcn, expected 140, is {}",
                    msg.states[1].fcn
                );
                assert_eq!(
                    msg.states[1].sid.code, 106,
                    "incorrect value for states[1].sid.code, expected 106, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.sat, 38,
                    "incorrect value for states[1].sid.sat, expected 38, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[2].cn0, 195,
                    "incorrect value for states[2].cn0, expected 195, is {}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].fcn, 90,
                    "incorrect value for states[2].fcn, expected 90, is {}",
                    msg.states[2].fcn
                );
                assert_eq!(
                    msg.states[2].sid.code, 4,
                    "incorrect value for states[2].sid.code, expected 4, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.sat, 25,
                    "incorrect value for states[2].sid.sat, expected 25, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[3].cn0, 82,
                    "incorrect value for states[3].cn0, expected 82, is {}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].fcn, 75,
                    "incorrect value for states[3].fcn, expected 75, is {}",
                    msg.states[3].fcn
                );
                assert_eq!(
                    msg.states[3].sid.code, 108,
                    "incorrect value for states[3].sid.code, expected 108, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.sat, 246,
                    "incorrect value for states[3].sid.sat, expected 246, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[4].cn0, 163,
                    "incorrect value for states[4].cn0, expected 163, is {}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].fcn, 45,
                    "incorrect value for states[4].fcn, expected 45, is {}",
                    msg.states[4].fcn
                );
                assert_eq!(
                    msg.states[4].sid.code, 127,
                    "incorrect value for states[4].sid.code, expected 127, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.sat, 137,
                    "incorrect value for states[4].sid.sat, expected 137, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[5].cn0, 93,
                    "incorrect value for states[5].cn0, expected 93, is {}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].fcn, 187,
                    "incorrect value for states[5].fcn, expected 187, is {}",
                    msg.states[5].fcn
                );
                assert_eq!(
                    msg.states[5].sid.code, 46,
                    "incorrect value for states[5].sid.code, expected 46, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.sat, 32,
                    "incorrect value for states[5].sid.sat, expected 32, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[6].cn0, 147,
                    "incorrect value for states[6].cn0, expected 147, is {}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].fcn, 201,
                    "incorrect value for states[6].fcn, expected 201, is {}",
                    msg.states[6].fcn
                );
                assert_eq!(
                    msg.states[6].sid.code, 60,
                    "incorrect value for states[6].sid.code, expected 60, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.sat, 153,
                    "incorrect value for states[6].sid.sat, expected 153, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[7].cn0, 208,
                    "incorrect value for states[7].cn0, expected 208, is {}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].fcn, 5,
                    "incorrect value for states[7].fcn, expected 5, is {}",
                    msg.states[7].fcn
                );
                assert_eq!(
                    msg.states[7].sid.code, 29,
                    "incorrect value for states[7].sid.code, expected 29, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.sat, 23,
                    "incorrect value for states[7].sid.sat, expected 23, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[8].cn0, 69,
                    "incorrect value for states[8].cn0, expected 69, is {}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].fcn, 219,
                    "incorrect value for states[8].fcn, expected 219, is {}",
                    msg.states[8].fcn
                );
                assert_eq!(
                    msg.states[8].sid.code, 30,
                    "incorrect value for states[8].sid.code, expected 30, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.sat, 181,
                    "incorrect value for states[8].sid.sat, expected 181, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[9].cn0, 121,
                    "incorrect value for states[9].cn0, expected 121, is {}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].fcn, 3,
                    "incorrect value for states[9].fcn, expected 3, is {}",
                    msg.states[9].fcn
                );
                assert_eq!(
                    msg.states[9].sid.code, 136,
                    "incorrect value for states[9].sid.code, expected 136, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.sat, 254,
                    "incorrect value for states[9].sid.sat, expected 254, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[10].cn0, 215,
                    "incorrect value for states[10].cn0, expected 215, is {}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].fcn, 144,
                    "incorrect value for states[10].fcn, expected 144, is {}",
                    msg.states[10].fcn
                );
                assert_eq!(
                    msg.states[10].sid.code, 98,
                    "incorrect value for states[10].sid.code, expected 98, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.sat, 33,
                    "incorrect value for states[10].sid.sat, expected 33, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[11].cn0, 56,
                    "incorrect value for states[11].cn0, expected 56, is {}",
                    msg.states[11].cn0
                );
                assert_eq!(
                    msg.states[11].fcn, 14,
                    "incorrect value for states[11].fcn, expected 14, is {}",
                    msg.states[11].fcn
                );
                assert_eq!(
                    msg.states[11].sid.code, 182,
                    "incorrect value for states[11].sid.code, expected 182, is {}",
                    msg.states[11].sid.code
                );
                assert_eq!(
                    msg.states[11].sid.sat, 133,
                    "incorrect value for states[11].sid.sat, expected 133, is {}",
                    msg.states[11].sid.sat
                );
                assert_eq!(
                    msg.states[12].cn0, 62,
                    "incorrect value for states[12].cn0, expected 62, is {}",
                    msg.states[12].cn0
                );
                assert_eq!(
                    msg.states[12].fcn, 218,
                    "incorrect value for states[12].fcn, expected 218, is {}",
                    msg.states[12].fcn
                );
                assert_eq!(
                    msg.states[12].sid.code, 77,
                    "incorrect value for states[12].sid.code, expected 77, is {}",
                    msg.states[12].sid.code
                );
                assert_eq!(
                    msg.states[12].sid.sat, 169,
                    "incorrect value for states[12].sid.sat, expected 169, is {}",
                    msg.states[12].sid.sat
                );
                assert_eq!(
                    msg.states[13].cn0, 249,
                    "incorrect value for states[13].cn0, expected 249, is {}",
                    msg.states[13].cn0
                );
                assert_eq!(
                    msg.states[13].fcn, 171,
                    "incorrect value for states[13].fcn, expected 171, is {}",
                    msg.states[13].fcn
                );
                assert_eq!(
                    msg.states[13].sid.code, 84,
                    "incorrect value for states[13].sid.code, expected 84, is {}",
                    msg.states[13].sid.code
                );
                assert_eq!(
                    msg.states[13].sid.sat, 242,
                    "incorrect value for states[13].sid.sat, expected 242, is {}",
                    msg.states[13].sid.sat
                );
                assert_eq!(
                    msg.states[14].cn0, 130,
                    "incorrect value for states[14].cn0, expected 130, is {}",
                    msg.states[14].cn0
                );
                assert_eq!(
                    msg.states[14].fcn, 131,
                    "incorrect value for states[14].fcn, expected 131, is {}",
                    msg.states[14].fcn
                );
                assert_eq!(
                    msg.states[14].sid.code, 137,
                    "incorrect value for states[14].sid.code, expected 137, is {}",
                    msg.states[14].sid.code
                );
                assert_eq!(
                    msg.states[14].sid.sat, 152,
                    "incorrect value for states[14].sid.sat, expected 152, is {}",
                    msg.states[14].sid.sat
                );
                assert_eq!(
                    msg.states[15].cn0, 68,
                    "incorrect value for states[15].cn0, expected 68, is {}",
                    msg.states[15].cn0
                );
                assert_eq!(
                    msg.states[15].fcn, 42,
                    "incorrect value for states[15].fcn, expected 42, is {}",
                    msg.states[15].fcn
                );
                assert_eq!(
                    msg.states[15].sid.code, 21,
                    "incorrect value for states[15].sid.code, expected 21, is {}",
                    msg.states[15].sid.code
                );
                assert_eq!(
                    msg.states[15].sid.sat, 193,
                    "incorrect value for states[15].sid.sat, expected 193, is {}",
                    msg.states[15].sid.sat
                );
                assert_eq!(
                    msg.states[16].cn0, 227,
                    "incorrect value for states[16].cn0, expected 227, is {}",
                    msg.states[16].cn0
                );
                assert_eq!(
                    msg.states[16].fcn, 216,
                    "incorrect value for states[16].fcn, expected 216, is {}",
                    msg.states[16].fcn
                );
                assert_eq!(
                    msg.states[16].sid.code, 227,
                    "incorrect value for states[16].sid.code, expected 227, is {}",
                    msg.states[16].sid.code
                );
                assert_eq!(
                    msg.states[16].sid.sat, 253,
                    "incorrect value for states[16].sid.sat, expected 253, is {}",
                    msg.states[16].sid.sat
                );
                assert_eq!(
                    msg.states[17].cn0, 179,
                    "incorrect value for states[17].cn0, expected 179, is {}",
                    msg.states[17].cn0
                );
                assert_eq!(
                    msg.states[17].fcn, 210,
                    "incorrect value for states[17].fcn, expected 210, is {}",
                    msg.states[17].fcn
                );
                assert_eq!(
                    msg.states[17].sid.code, 26,
                    "incorrect value for states[17].sid.code, expected 26, is {}",
                    msg.states[17].sid.code
                );
                assert_eq!(
                    msg.states[17].sid.sat, 24,
                    "incorrect value for states[17].sid.sat, expected 24, is {}",
                    msg.states[17].sid.sat
                );
                assert_eq!(
                    msg.states[18].cn0, 255,
                    "incorrect value for states[18].cn0, expected 255, is {}",
                    msg.states[18].cn0
                );
                assert_eq!(
                    msg.states[18].fcn, 227,
                    "incorrect value for states[18].fcn, expected 227, is {}",
                    msg.states[18].fcn
                );
                assert_eq!(
                    msg.states[18].sid.code, 15,
                    "incorrect value for states[18].sid.code, expected 15, is {}",
                    msg.states[18].sid.code
                );
                assert_eq!(
                    msg.states[18].sid.sat, 19,
                    "incorrect value for states[18].sid.sat, expected 19, is {}",
                    msg.states[18].sid.sat
                );
                assert_eq!(
                    msg.states[19].cn0, 200,
                    "incorrect value for states[19].cn0, expected 200, is {}",
                    msg.states[19].cn0
                );
                assert_eq!(
                    msg.states[19].fcn, 187,
                    "incorrect value for states[19].fcn, expected 187, is {}",
                    msg.states[19].fcn
                );
                assert_eq!(
                    msg.states[19].sid.code, 75,
                    "incorrect value for states[19].sid.code, expected 75, is {}",
                    msg.states[19].sid.code
                );
                assert_eq!(
                    msg.states[19].sid.sat, 122,
                    "incorrect value for states[19].sid.sat, expected 122, is {}",
                    msg.states[19].sid.sat
                );
                assert_eq!(
                    msg.states[20].cn0, 122,
                    "incorrect value for states[20].cn0, expected 122, is {}",
                    msg.states[20].cn0
                );
                assert_eq!(
                    msg.states[20].fcn, 218,
                    "incorrect value for states[20].fcn, expected 218, is {}",
                    msg.states[20].fcn
                );
                assert_eq!(
                    msg.states[20].sid.code, 48,
                    "incorrect value for states[20].sid.code, expected 48, is {}",
                    msg.states[20].sid.code
                );
                assert_eq!(
                    msg.states[20].sid.sat, 217,
                    "incorrect value for states[20].sid.sat, expected 217, is {}",
                    msg.states[20].sid.sat
                );
                assert_eq!(
                    msg.states[21].cn0, 149,
                    "incorrect value for states[21].cn0, expected 149, is {}",
                    msg.states[21].cn0
                );
                assert_eq!(
                    msg.states[21].fcn, 142,
                    "incorrect value for states[21].fcn, expected 142, is {}",
                    msg.states[21].fcn
                );
                assert_eq!(
                    msg.states[21].sid.code, 238,
                    "incorrect value for states[21].sid.code, expected 238, is {}",
                    msg.states[21].sid.code
                );
                assert_eq!(
                    msg.states[21].sid.sat, 187,
                    "incorrect value for states[21].sid.sat, expected 187, is {}",
                    msg.states[21].sid.sat
                );
                assert_eq!(
                    msg.states[22].cn0, 212,
                    "incorrect value for states[22].cn0, expected 212, is {}",
                    msg.states[22].cn0
                );
                assert_eq!(
                    msg.states[22].fcn, 251,
                    "incorrect value for states[22].fcn, expected 251, is {}",
                    msg.states[22].fcn
                );
                assert_eq!(
                    msg.states[22].sid.code, 55,
                    "incorrect value for states[22].sid.code, expected 55, is {}",
                    msg.states[22].sid.code
                );
                assert_eq!(
                    msg.states[22].sid.sat, 238,
                    "incorrect value for states[22].sid.sat, expected 238, is {}",
                    msg.states[22].sid.sat
                );
                assert_eq!(
                    msg.states[23].cn0, 104,
                    "incorrect value for states[23].cn0, expected 104, is {}",
                    msg.states[23].cn0
                );
                assert_eq!(
                    msg.states[23].fcn, 194,
                    "incorrect value for states[23].fcn, expected 194, is {}",
                    msg.states[23].fcn
                );
                assert_eq!(
                    msg.states[23].sid.code, 160,
                    "incorrect value for states[23].sid.code, expected 160, is {}",
                    msg.states[23].sid.code
                );
                assert_eq!(
                    msg.states[23].sid.sat, 128,
                    "incorrect value for states[23].sid.sat, expected 128, is {}",
                    msg.states[23].sid.sat
                );
                assert_eq!(
                    msg.states[24].cn0, 62,
                    "incorrect value for states[24].cn0, expected 62, is {}",
                    msg.states[24].cn0
                );
                assert_eq!(
                    msg.states[24].fcn, 141,
                    "incorrect value for states[24].fcn, expected 141, is {}",
                    msg.states[24].fcn
                );
                assert_eq!(
                    msg.states[24].sid.code, 255,
                    "incorrect value for states[24].sid.code, expected 255, is {}",
                    msg.states[24].sid.code
                );
                assert_eq!(
                    msg.states[24].sid.sat, 113,
                    "incorrect value for states[24].sid.sat, expected 113, is {}",
                    msg.states[24].sid.sat
                );
                assert_eq!(
                    msg.states[25].cn0, 39,
                    "incorrect value for states[25].cn0, expected 39, is {}",
                    msg.states[25].cn0
                );
                assert_eq!(
                    msg.states[25].fcn, 245,
                    "incorrect value for states[25].fcn, expected 245, is {}",
                    msg.states[25].fcn
                );
                assert_eq!(
                    msg.states[25].sid.code, 69,
                    "incorrect value for states[25].sid.code, expected 69, is {}",
                    msg.states[25].sid.code
                );
                assert_eq!(
                    msg.states[25].sid.sat, 43,
                    "incorrect value for states[25].sid.sat, expected 43, is {}",
                    msg.states[25].sid.sat
                );
                assert_eq!(
                    msg.states[26].cn0, 56,
                    "incorrect value for states[26].cn0, expected 56, is {}",
                    msg.states[26].cn0
                );
                assert_eq!(
                    msg.states[26].fcn, 108,
                    "incorrect value for states[26].fcn, expected 108, is {}",
                    msg.states[26].fcn
                );
                assert_eq!(
                    msg.states[26].sid.code, 230,
                    "incorrect value for states[26].sid.code, expected 230, is {}",
                    msg.states[26].sid.code
                );
                assert_eq!(
                    msg.states[26].sid.sat, 100,
                    "incorrect value for states[26].sid.sat, expected 100, is {}",
                    msg.states[26].sid.sat
                );
                assert_eq!(
                    msg.states[27].cn0, 143,
                    "incorrect value for states[27].cn0, expected 143, is {}",
                    msg.states[27].cn0
                );
                assert_eq!(
                    msg.states[27].fcn, 149,
                    "incorrect value for states[27].fcn, expected 149, is {}",
                    msg.states[27].fcn
                );
                assert_eq!(
                    msg.states[27].sid.code, 68,
                    "incorrect value for states[27].sid.code, expected 68, is {}",
                    msg.states[27].sid.code
                );
                assert_eq!(
                    msg.states[27].sid.sat, 247,
                    "incorrect value for states[27].sid.sat, expected 247, is {}",
                    msg.states[27].sid.sat
                );
                assert_eq!(
                    msg.states[28].cn0, 70,
                    "incorrect value for states[28].cn0, expected 70, is {}",
                    msg.states[28].cn0
                );
                assert_eq!(
                    msg.states[28].fcn, 233,
                    "incorrect value for states[28].fcn, expected 233, is {}",
                    msg.states[28].fcn
                );
                assert_eq!(
                    msg.states[28].sid.code, 101,
                    "incorrect value for states[28].sid.code, expected 101, is {}",
                    msg.states[28].sid.code
                );
                assert_eq!(
                    msg.states[28].sid.sat, 137,
                    "incorrect value for states[28].sid.sat, expected 137, is {}",
                    msg.states[28].sid.sat
                );
                assert_eq!(
                    msg.states[29].cn0, 110,
                    "incorrect value for states[29].cn0, expected 110, is {}",
                    msg.states[29].cn0
                );
                assert_eq!(
                    msg.states[29].fcn, 38,
                    "incorrect value for states[29].fcn, expected 38, is {}",
                    msg.states[29].fcn
                );
                assert_eq!(
                    msg.states[29].sid.code, 165,
                    "incorrect value for states[29].sid.code, expected 165, is {}",
                    msg.states[29].sid.code
                );
                assert_eq!(
                    msg.states[29].sid.sat, 49,
                    "incorrect value for states[29].sid.sat, expected 49, is {}",
                    msg.states[29].sid.sat
                );
                assert_eq!(
                    msg.states[30].cn0, 213,
                    "incorrect value for states[30].cn0, expected 213, is {}",
                    msg.states[30].cn0
                );
                assert_eq!(
                    msg.states[30].fcn, 80,
                    "incorrect value for states[30].fcn, expected 80, is {}",
                    msg.states[30].fcn
                );
                assert_eq!(
                    msg.states[30].sid.code, 230,
                    "incorrect value for states[30].sid.code, expected 230, is {}",
                    msg.states[30].sid.code
                );
                assert_eq!(
                    msg.states[30].sid.sat, 218,
                    "incorrect value for states[30].sid.sat, expected 218, is {}",
                    msg.states[30].sid.sat
                );
                assert_eq!(
                    msg.states[31].cn0, 128,
                    "incorrect value for states[31].cn0, expected 128, is {}",
                    msg.states[31].cn0
                );
                assert_eq!(
                    msg.states[31].fcn, 139,
                    "incorrect value for states[31].fcn, expected 139, is {}",
                    msg.states[31].fcn
                );
                assert_eq!(
                    msg.states[31].sid.code, 179,
                    "incorrect value for states[31].sid.code, expected 179, is {}",
                    msg.states[31].sid.code
                );
                assert_eq!(
                    msg.states[31].sid.sat, 196,
                    "incorrect value for states[31].sid.sat, expected 196, is {}",
                    msg.states[31].sid.sat
                );
                assert_eq!(
                    msg.states[32].cn0, 171,
                    "incorrect value for states[32].cn0, expected 171, is {}",
                    msg.states[32].cn0
                );
                assert_eq!(
                    msg.states[32].fcn, 196,
                    "incorrect value for states[32].fcn, expected 196, is {}",
                    msg.states[32].fcn
                );
                assert_eq!(
                    msg.states[32].sid.code, 178,
                    "incorrect value for states[32].sid.code, expected 178, is {}",
                    msg.states[32].sid.code
                );
                assert_eq!(
                    msg.states[32].sid.sat, 15,
                    "incorrect value for states[32].sid.sat, expected 15, is {}",
                    msg.states[32].sid.sat
                );
                assert_eq!(
                    msg.states[33].cn0, 194,
                    "incorrect value for states[33].cn0, expected 194, is {}",
                    msg.states[33].cn0
                );
                assert_eq!(
                    msg.states[33].fcn, 97,
                    "incorrect value for states[33].fcn, expected 97, is {}",
                    msg.states[33].fcn
                );
                assert_eq!(
                    msg.states[33].sid.code, 212,
                    "incorrect value for states[33].sid.code, expected 212, is {}",
                    msg.states[33].sid.code
                );
                assert_eq!(
                    msg.states[33].sid.sat, 8,
                    "incorrect value for states[33].sid.sat, expected 8, is {}",
                    msg.states[33].sid.sat
                );
                assert_eq!(
                    msg.states[34].cn0, 99,
                    "incorrect value for states[34].cn0, expected 99, is {}",
                    msg.states[34].cn0
                );
                assert_eq!(
                    msg.states[34].fcn, 79,
                    "incorrect value for states[34].fcn, expected 79, is {}",
                    msg.states[34].fcn
                );
                assert_eq!(
                    msg.states[34].sid.code, 233,
                    "incorrect value for states[34].sid.code, expected 233, is {}",
                    msg.states[34].sid.code
                );
                assert_eq!(
                    msg.states[34].sid.sat, 83,
                    "incorrect value for states[34].sid.sat, expected 83, is {}",
                    msg.states[34].sid.sat
                );
                assert_eq!(
                    msg.states[35].cn0, 180,
                    "incorrect value for states[35].cn0, expected 180, is {}",
                    msg.states[35].cn0
                );
                assert_eq!(
                    msg.states[35].fcn, 31,
                    "incorrect value for states[35].fcn, expected 31, is {}",
                    msg.states[35].fcn
                );
                assert_eq!(
                    msg.states[35].sid.code, 90,
                    "incorrect value for states[35].sid.code, expected 90, is {}",
                    msg.states[35].sid.code
                );
                assert_eq!(
                    msg.states[35].sid.sat, 55,
                    "incorrect value for states[35].sid.sat, expected 55, is {}",
                    msg.states[35].sid.sat
                );
                assert_eq!(
                    msg.states[36].cn0, 186,
                    "incorrect value for states[36].cn0, expected 186, is {}",
                    msg.states[36].cn0
                );
                assert_eq!(
                    msg.states[36].fcn, 105,
                    "incorrect value for states[36].fcn, expected 105, is {}",
                    msg.states[36].fcn
                );
                assert_eq!(
                    msg.states[36].sid.code, 25,
                    "incorrect value for states[36].sid.code, expected 25, is {}",
                    msg.states[36].sid.code
                );
                assert_eq!(
                    msg.states[36].sid.sat, 5,
                    "incorrect value for states[36].sid.sat, expected 5, is {}",
                    msg.states[36].sid.sat
                );
                assert_eq!(
                    msg.states[37].cn0, 111,
                    "incorrect value for states[37].cn0, expected 111, is {}",
                    msg.states[37].cn0
                );
                assert_eq!(
                    msg.states[37].fcn, 80,
                    "incorrect value for states[37].fcn, expected 80, is {}",
                    msg.states[37].fcn
                );
                assert_eq!(
                    msg.states[37].sid.code, 224,
                    "incorrect value for states[37].sid.code, expected 224, is {}",
                    msg.states[37].sid.code
                );
                assert_eq!(
                    msg.states[37].sid.sat, 22,
                    "incorrect value for states[37].sid.sat, expected 22, is {}",
                    msg.states[37].sid.sat
                );
                assert_eq!(
                    msg.states[38].cn0, 166,
                    "incorrect value for states[38].cn0, expected 166, is {}",
                    msg.states[38].cn0
                );
                assert_eq!(
                    msg.states[38].fcn, 106,
                    "incorrect value for states[38].fcn, expected 106, is {}",
                    msg.states[38].fcn
                );
                assert_eq!(
                    msg.states[38].sid.code, 48,
                    "incorrect value for states[38].sid.code, expected 48, is {}",
                    msg.states[38].sid.code
                );
                assert_eq!(
                    msg.states[38].sid.sat, 8,
                    "incorrect value for states[38].sid.sat, expected 8, is {}",
                    msg.states[38].sid.sat
                );
                assert_eq!(
                    msg.states[39].cn0, 49,
                    "incorrect value for states[39].cn0, expected 49, is {}",
                    msg.states[39].cn0
                );
                assert_eq!(
                    msg.states[39].fcn, 156,
                    "incorrect value for states[39].fcn, expected 156, is {}",
                    msg.states[39].fcn
                );
                assert_eq!(
                    msg.states[39].sid.code, 48,
                    "incorrect value for states[39].sid.code, expected 48, is {}",
                    msg.states[39].sid.code
                );
                assert_eq!(
                    msg.states[39].sid.sat, 4,
                    "incorrect value for states[39].sid.sat, expected 4, is {}",
                    msg.states[39].sid.sat
                );
                assert_eq!(
                    msg.states[40].cn0, 146,
                    "incorrect value for states[40].cn0, expected 146, is {}",
                    msg.states[40].cn0
                );
                assert_eq!(
                    msg.states[40].fcn, 142,
                    "incorrect value for states[40].fcn, expected 142, is {}",
                    msg.states[40].fcn
                );
                assert_eq!(
                    msg.states[40].sid.code, 19,
                    "incorrect value for states[40].sid.code, expected 19, is {}",
                    msg.states[40].sid.code
                );
                assert_eq!(
                    msg.states[40].sid.sat, 86,
                    "incorrect value for states[40].sid.sat, expected 86, is {}",
                    msg.states[40].sid.sat
                );
                assert_eq!(
                    msg.states[41].cn0, 64,
                    "incorrect value for states[41].cn0, expected 64, is {}",
                    msg.states[41].cn0
                );
                assert_eq!(
                    msg.states[41].fcn, 115,
                    "incorrect value for states[41].fcn, expected 115, is {}",
                    msg.states[41].fcn
                );
                assert_eq!(
                    msg.states[41].sid.code, 124,
                    "incorrect value for states[41].sid.code, expected 124, is {}",
                    msg.states[41].sid.code
                );
                assert_eq!(
                    msg.states[41].sid.sat, 91,
                    "incorrect value for states[41].sid.sat, expected 91, is {}",
                    msg.states[41].sid.sat
                );
                assert_eq!(
                    msg.states[42].cn0, 178,
                    "incorrect value for states[42].cn0, expected 178, is {}",
                    msg.states[42].cn0
                );
                assert_eq!(
                    msg.states[42].fcn, 115,
                    "incorrect value for states[42].fcn, expected 115, is {}",
                    msg.states[42].fcn
                );
                assert_eq!(
                    msg.states[42].sid.code, 230,
                    "incorrect value for states[42].sid.code, expected 230, is {}",
                    msg.states[42].sid.code
                );
                assert_eq!(
                    msg.states[42].sid.sat, 28,
                    "incorrect value for states[42].sid.sat, expected 28, is {}",
                    msg.states[42].sid.sat
                );
                assert_eq!(
                    msg.states[43].cn0, 242,
                    "incorrect value for states[43].cn0, expected 242, is {}",
                    msg.states[43].cn0
                );
                assert_eq!(
                    msg.states[43].fcn, 16,
                    "incorrect value for states[43].fcn, expected 16, is {}",
                    msg.states[43].fcn
                );
                assert_eq!(
                    msg.states[43].sid.code, 131,
                    "incorrect value for states[43].sid.code, expected 131, is {}",
                    msg.states[43].sid.code
                );
                assert_eq!(
                    msg.states[43].sid.sat, 190,
                    "incorrect value for states[43].sid.sat, expected 190, is {}",
                    msg.states[43].sid.sat
                );
                assert_eq!(
                    msg.states[44].cn0, 113,
                    "incorrect value for states[44].cn0, expected 113, is {}",
                    msg.states[44].cn0
                );
                assert_eq!(
                    msg.states[44].fcn, 182,
                    "incorrect value for states[44].fcn, expected 182, is {}",
                    msg.states[44].fcn
                );
                assert_eq!(
                    msg.states[44].sid.code, 59,
                    "incorrect value for states[44].sid.code, expected 59, is {}",
                    msg.states[44].sid.code
                );
                assert_eq!(
                    msg.states[44].sid.sat, 105,
                    "incorrect value for states[44].sid.sat, expected 105, is {}",
                    msg.states[44].sid.sat
                );
                assert_eq!(
                    msg.states[45].cn0, 179,
                    "incorrect value for states[45].cn0, expected 179, is {}",
                    msg.states[45].cn0
                );
                assert_eq!(
                    msg.states[45].fcn, 48,
                    "incorrect value for states[45].fcn, expected 48, is {}",
                    msg.states[45].fcn
                );
                assert_eq!(
                    msg.states[45].sid.code, 180,
                    "incorrect value for states[45].sid.code, expected 180, is {}",
                    msg.states[45].sid.code
                );
                assert_eq!(
                    msg.states[45].sid.sat, 192,
                    "incorrect value for states[45].sid.sat, expected 192, is {}",
                    msg.states[45].sid.sat
                );
                assert_eq!(
                    msg.states[46].cn0, 211,
                    "incorrect value for states[46].cn0, expected 211, is {}",
                    msg.states[46].cn0
                );
                assert_eq!(
                    msg.states[46].fcn, 172,
                    "incorrect value for states[46].fcn, expected 172, is {}",
                    msg.states[46].fcn
                );
                assert_eq!(
                    msg.states[46].sid.code, 31,
                    "incorrect value for states[46].sid.code, expected 31, is {}",
                    msg.states[46].sid.code
                );
                assert_eq!(
                    msg.states[46].sid.sat, 166,
                    "incorrect value for states[46].sid.sat, expected 166, is {}",
                    msg.states[46].sid.sat
                );
                assert_eq!(
                    msg.states[47].cn0, 49,
                    "incorrect value for states[47].cn0, expected 49, is {}",
                    msg.states[47].cn0
                );
                assert_eq!(
                    msg.states[47].fcn, 140,
                    "incorrect value for states[47].fcn, expected 140, is {}",
                    msg.states[47].fcn
                );
                assert_eq!(
                    msg.states[47].sid.code, 228,
                    "incorrect value for states[47].sid.code, expected 228, is {}",
                    msg.states[47].sid.code
                );
                assert_eq!(
                    msg.states[47].sid.sat, 77,
                    "incorrect value for states[47].sid.sat, expected 77, is {}",
                    msg.states[47].sid.sat
                );
                assert_eq!(
                    msg.states[48].cn0, 194,
                    "incorrect value for states[48].cn0, expected 194, is {}",
                    msg.states[48].cn0
                );
                assert_eq!(
                    msg.states[48].fcn, 240,
                    "incorrect value for states[48].fcn, expected 240, is {}",
                    msg.states[48].fcn
                );
                assert_eq!(
                    msg.states[48].sid.code, 77,
                    "incorrect value for states[48].sid.code, expected 77, is {}",
                    msg.states[48].sid.code
                );
                assert_eq!(
                    msg.states[48].sid.sat, 128,
                    "incorrect value for states[48].sid.sat, expected 128, is {}",
                    msg.states[48].sid.sat
                );
                assert_eq!(
                    msg.states[49].cn0, 58,
                    "incorrect value for states[49].cn0, expected 58, is {}",
                    msg.states[49].cn0
                );
                assert_eq!(
                    msg.states[49].fcn, 41,
                    "incorrect value for states[49].fcn, expected 41, is {}",
                    msg.states[49].fcn
                );
                assert_eq!(
                    msg.states[49].sid.code, 194,
                    "incorrect value for states[49].sid.code, expected 194, is {}",
                    msg.states[49].sid.code
                );
                assert_eq!(
                    msg.states[49].sid.sat, 134,
                    "incorrect value for states[49].sid.sat, expected 134, is {}",
                    msg.states[49].sid.sat
                );
                assert_eq!(
                    msg.states[50].cn0, 55,
                    "incorrect value for states[50].cn0, expected 55, is {}",
                    msg.states[50].cn0
                );
                assert_eq!(
                    msg.states[50].fcn, 129,
                    "incorrect value for states[50].fcn, expected 129, is {}",
                    msg.states[50].fcn
                );
                assert_eq!(
                    msg.states[50].sid.code, 53,
                    "incorrect value for states[50].sid.code, expected 53, is {}",
                    msg.states[50].sid.code
                );
                assert_eq!(
                    msg.states[50].sid.sat, 18,
                    "incorrect value for states[50].sid.sat, expected 18, is {}",
                    msg.states[50].sid.sat
                );
                assert_eq!(
                    msg.states[51].cn0, 92,
                    "incorrect value for states[51].cn0, expected 92, is {}",
                    msg.states[51].cn0
                );
                assert_eq!(
                    msg.states[51].fcn, 134,
                    "incorrect value for states[51].fcn, expected 134, is {}",
                    msg.states[51].fcn
                );
                assert_eq!(
                    msg.states[51].sid.code, 72,
                    "incorrect value for states[51].sid.code, expected 72, is {}",
                    msg.states[51].sid.code
                );
                assert_eq!(
                    msg.states[51].sid.sat, 91,
                    "incorrect value for states[51].sid.sat, expected 91, is {}",
                    msg.states[51].sid.sat
                );
                assert_eq!(
                    msg.states[52].cn0, 56,
                    "incorrect value for states[52].cn0, expected 56, is {}",
                    msg.states[52].cn0
                );
                assert_eq!(
                    msg.states[52].fcn, 157,
                    "incorrect value for states[52].fcn, expected 157, is {}",
                    msg.states[52].fcn
                );
                assert_eq!(
                    msg.states[52].sid.code, 224,
                    "incorrect value for states[52].sid.code, expected 224, is {}",
                    msg.states[52].sid.code
                );
                assert_eq!(
                    msg.states[52].sid.sat, 33,
                    "incorrect value for states[52].sid.sat, expected 33, is {}",
                    msg.states[52].sid.sat
                );
                assert_eq!(
                    msg.states[53].cn0, 174,
                    "incorrect value for states[53].cn0, expected 174, is {}",
                    msg.states[53].cn0
                );
                assert_eq!(
                    msg.states[53].fcn, 224,
                    "incorrect value for states[53].fcn, expected 224, is {}",
                    msg.states[53].fcn
                );
                assert_eq!(
                    msg.states[53].sid.code, 54,
                    "incorrect value for states[53].sid.code, expected 54, is {}",
                    msg.states[53].sid.code
                );
                assert_eq!(
                    msg.states[53].sid.sat, 186,
                    "incorrect value for states[53].sid.sat, expected 186, is {}",
                    msg.states[53].sid.sat
                );
                assert_eq!(
                    msg.states[54].cn0, 190,
                    "incorrect value for states[54].cn0, expected 190, is {}",
                    msg.states[54].cn0
                );
                assert_eq!(
                    msg.states[54].fcn, 148,
                    "incorrect value for states[54].fcn, expected 148, is {}",
                    msg.states[54].fcn
                );
                assert_eq!(
                    msg.states[54].sid.code, 84,
                    "incorrect value for states[54].sid.code, expected 84, is {}",
                    msg.states[54].sid.code
                );
                assert_eq!(
                    msg.states[54].sid.sat, 82,
                    "incorrect value for states[54].sid.sat, expected 82, is {}",
                    msg.states[54].sid.sat
                );
                assert_eq!(
                    msg.states[55].cn0, 67,
                    "incorrect value for states[55].cn0, expected 67, is {}",
                    msg.states[55].cn0
                );
                assert_eq!(
                    msg.states[55].fcn, 62,
                    "incorrect value for states[55].fcn, expected 62, is {}",
                    msg.states[55].fcn
                );
                assert_eq!(
                    msg.states[55].sid.code, 54,
                    "incorrect value for states[55].sid.code, expected 54, is {}",
                    msg.states[55].sid.code
                );
                assert_eq!(
                    msg.states[55].sid.sat, 236,
                    "incorrect value for states[55].sid.sat, expected 236, is {}",
                    msg.states[55].sid.sat
                );
                assert_eq!(
                    msg.states[56].cn0, 254,
                    "incorrect value for states[56].cn0, expected 254, is {}",
                    msg.states[56].cn0
                );
                assert_eq!(
                    msg.states[56].fcn, 57,
                    "incorrect value for states[56].fcn, expected 57, is {}",
                    msg.states[56].fcn
                );
                assert_eq!(
                    msg.states[56].sid.code, 215,
                    "incorrect value for states[56].sid.code, expected 215, is {}",
                    msg.states[56].sid.code
                );
                assert_eq!(
                    msg.states[56].sid.sat, 52,
                    "incorrect value for states[56].sid.sat, expected 52, is {}",
                    msg.states[56].sid.sat
                );
                assert_eq!(
                    msg.states[57].cn0, 174,
                    "incorrect value for states[57].cn0, expected 174, is {}",
                    msg.states[57].cn0
                );
                assert_eq!(
                    msg.states[57].fcn, 36,
                    "incorrect value for states[57].fcn, expected 36, is {}",
                    msg.states[57].fcn
                );
                assert_eq!(
                    msg.states[57].sid.code, 133,
                    "incorrect value for states[57].sid.code, expected 133, is {}",
                    msg.states[57].sid.code
                );
                assert_eq!(
                    msg.states[57].sid.sat, 16,
                    "incorrect value for states[57].sid.sat, expected 16, is {}",
                    msg.states[57].sid.sat
                );
                assert_eq!(
                    msg.states[58].cn0, 17,
                    "incorrect value for states[58].cn0, expected 17, is {}",
                    msg.states[58].cn0
                );
                assert_eq!(
                    msg.states[58].fcn, 145,
                    "incorrect value for states[58].fcn, expected 145, is {}",
                    msg.states[58].fcn
                );
                assert_eq!(
                    msg.states[58].sid.code, 172,
                    "incorrect value for states[58].sid.code, expected 172, is {}",
                    msg.states[58].sid.code
                );
                assert_eq!(
                    msg.states[58].sid.sat, 219,
                    "incorrect value for states[58].sid.sat, expected 219, is {}",
                    msg.states[58].sid.sat
                );
                assert_eq!(
                    msg.states[59].cn0, 97,
                    "incorrect value for states[59].cn0, expected 97, is {}",
                    msg.states[59].cn0
                );
                assert_eq!(
                    msg.states[59].fcn, 111,
                    "incorrect value for states[59].fcn, expected 111, is {}",
                    msg.states[59].fcn
                );
                assert_eq!(
                    msg.states[59].sid.code, 179,
                    "incorrect value for states[59].sid.code, expected 179, is {}",
                    msg.states[59].sid.code
                );
                assert_eq!(
                    msg.states[59].sid.sat, 192,
                    "incorrect value for states[59].sid.sat, expected 192, is {}",
                    msg.states[59].sid.sat
                );
                assert_eq!(
                    msg.states[60].cn0, 134,
                    "incorrect value for states[60].cn0, expected 134, is {}",
                    msg.states[60].cn0
                );
                assert_eq!(
                    msg.states[60].fcn, 208,
                    "incorrect value for states[60].fcn, expected 208, is {}",
                    msg.states[60].fcn
                );
                assert_eq!(
                    msg.states[60].sid.code, 56,
                    "incorrect value for states[60].sid.code, expected 56, is {}",
                    msg.states[60].sid.code
                );
                assert_eq!(
                    msg.states[60].sid.sat, 207,
                    "incorrect value for states[60].sid.sat, expected 207, is {}",
                    msg.states[60].sid.sat
                );
                assert_eq!(
                    msg.states[61].cn0, 226,
                    "incorrect value for states[61].cn0, expected 226, is {}",
                    msg.states[61].cn0
                );
                assert_eq!(
                    msg.states[61].fcn, 43,
                    "incorrect value for states[61].fcn, expected 43, is {}",
                    msg.states[61].fcn
                );
                assert_eq!(
                    msg.states[61].sid.code, 17,
                    "incorrect value for states[61].sid.code, expected 17, is {}",
                    msg.states[61].sid.code
                );
                assert_eq!(
                    msg.states[61].sid.sat, 180,
                    "incorrect value for states[61].sid.sat, expected 180, is {}",
                    msg.states[61].sid.sat
                );
                assert_eq!(
                    msg.states[62].cn0, 113,
                    "incorrect value for states[62].cn0, expected 113, is {}",
                    msg.states[62].cn0
                );
                assert_eq!(
                    msg.states[62].fcn, 140,
                    "incorrect value for states[62].fcn, expected 140, is {}",
                    msg.states[62].fcn
                );
                assert_eq!(
                    msg.states[62].sid.code, 182,
                    "incorrect value for states[62].sid.code, expected 182, is {}",
                    msg.states[62].sid.code
                );
                assert_eq!(
                    msg.states[62].sid.sat, 255,
                    "incorrect value for states[62].sid.sat, expected 255, is {}",
                    msg.states[62].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingState"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 197, 253, 28, 66, 1, 203, 0, 0, 0, 231, 99,
            16, 66, 1, 208, 0, 0, 0, 212, 129, 22, 66, 1, 212, 0, 0, 0, 58, 21, 28, 66, 1, 217, 0,
            0, 0, 178, 33, 40, 66, 1, 218, 0, 0, 0, 235, 189, 21, 66, 1, 220, 0, 0, 0, 29, 177, 25,
            66, 1, 222, 0, 0, 0, 43, 169, 27, 66, 1, 225, 0, 0, 0, 137, 125, 42, 66, 0, 0, 0, 0, 0,
            0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 222, 97,
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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.92478218078613281e+01),
                    "incorrect value for states[0].cn0, expected 3.92478218078613281e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.60975608825683594e+01),
                    "incorrect value for states[1].cn0, expected 3.60975608825683594e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.76267852783203125e+01),
                    "incorrect value for states[2].cn0, expected 3.76267852783203125e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.90207290649414062e+01),
                    "incorrect value for states[3].cn0, expected 3.90207290649414062e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.20329055786132812e+01),
                    "incorrect value for states[4].cn0, expected 4.20329055786132812e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.74354667663574219e+01),
                    "incorrect value for states[5].cn0, expected 3.74354667663574219e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.84229621887207031e+01),
                    "incorrect value for states[6].cn0, expected 3.84229621887207031e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.89152030944824219e+01),
                    "incorrect value for states[7].cn0, expected 3.89152030944824219e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.26225929260253906e+01),
                    "incorrect value for states[8].cn0, expected 4.26225929260253906e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 250, 249, 27, 66, 1, 203, 0, 0, 0, 40, 143,
            11, 66, 1, 208, 0, 0, 0, 190, 200, 21, 66, 1, 212, 0, 0, 0, 251, 233, 26, 66, 1, 217,
            0, 0, 0, 209, 238, 39, 66, 1, 218, 0, 0, 0, 162, 219, 21, 66, 1, 220, 0, 0, 0, 162,
            197, 25, 66, 1, 222, 0, 0, 0, 14, 35, 28, 66, 1, 225, 0, 0, 0, 9, 153, 43, 66, 0, 0, 0,
            0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 20, 31,
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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.89941177368164062e+01),
                    "incorrect value for states[0].cn0, expected 3.89941177368164062e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.48898010253906250e+01),
                    "incorrect value for states[1].cn0, expected 3.48898010253906250e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.74460372924804688e+01),
                    "incorrect value for states[2].cn0, expected 3.74460372924804688e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.87284965515136719e+01),
                    "incorrect value for states[3].cn0, expected 3.87284965515136719e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.19832191467285156e+01),
                    "incorrect value for states[4].cn0, expected 4.19832191467285156e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.74644851684570312e+01),
                    "incorrect value for states[5].cn0, expected 3.74644851684570312e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.84430007934570312e+01),
                    "incorrect value for states[6].cn0, expected 3.84430007934570312e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.90342330932617188e+01),
                    "incorrect value for states[7].cn0, expected 3.90342330932617188e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.28994483947753906e+01),
                    "incorrect value for states[8].cn0, expected 4.28994483947753906e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 123, 209, 27, 66, 1, 203, 0, 0, 0, 214, 64,
            15, 66, 1, 208, 0, 0, 0, 56, 55, 22, 66, 1, 212, 0, 0, 0, 91, 142, 27, 66, 1, 217, 0,
            0, 0, 253, 154, 41, 66, 1, 218, 0, 0, 0, 128, 142, 22, 66, 1, 220, 0, 0, 0, 17, 174,
            23, 66, 1, 222, 0, 0, 0, 155, 2, 29, 66, 1, 225, 0, 0, 0, 162, 100, 42, 66, 0, 0, 0, 0,
            0, 0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 233, 71,
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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.89545707702636719e+01),
                    "incorrect value for states[0].cn0, expected 3.89545707702636719e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.58133163452148438e+01),
                    "incorrect value for states[1].cn0, expected 3.58133163452148438e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.75539245605468750e+01),
                    "incorrect value for states[2].cn0, expected 3.75539245605468750e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.88890190124511719e+01),
                    "incorrect value for states[3].cn0, expected 3.88890190124511719e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.24013557434082031e+01),
                    "incorrect value for states[4].cn0, expected 4.24013557434082031e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.76391601562500000e+01),
                    "incorrect value for states[5].cn0, expected 3.76391601562500000e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.79199867248535156e+01),
                    "incorrect value for states[6].cn0, expected 3.79199867248535156e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.92525444030761719e+01),
                    "incorrect value for states[7].cn0, expected 3.92525444030761719e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.25982742309570312e+01),
                    "incorrect value for states[8].cn0, expected 4.25982742309570312e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 120, 122, 29, 66, 1, 203, 0, 0, 0, 66, 22,
            18, 66, 1, 208, 0, 0, 0, 153, 163, 24, 66, 1, 212, 0, 0, 0, 178, 204, 28, 66, 1, 217,
            0, 0, 0, 220, 59, 38, 66, 1, 218, 0, 0, 0, 161, 27, 20, 66, 1, 220, 0, 0, 0, 125, 107,
            24, 66, 1, 222, 0, 0, 0, 242, 46, 28, 66, 1, 225, 0, 0, 0, 231, 130, 41, 66, 0, 0, 0,
            0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 73, 193,
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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.93695983886718750e+01),
                    "incorrect value for states[0].cn0, expected 3.93695983886718750e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.65217361450195312e+01),
                    "incorrect value for states[1].cn0, expected 3.65217361450195312e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.81597633361816406e+01),
                    "incorrect value for states[2].cn0, expected 3.81597633361816406e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.91998977661132812e+01),
                    "incorrect value for states[3].cn0, expected 3.91998977661132812e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.15584564208984375e+01),
                    "incorrect value for states[4].cn0, expected 4.15584564208984375e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.70269813537597656e+01),
                    "incorrect value for states[5].cn0, expected 3.70269813537597656e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.81049690246582031e+01),
                    "incorrect value for states[6].cn0, expected 3.81049690246582031e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.90458450317382812e+01),
                    "incorrect value for states[7].cn0, expected 3.90458450317382812e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.23778343200683594e+01),
                    "incorrect value for states[8].cn0, expected 4.23778343200683594e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 103, 208, 30, 66, 1, 203, 0, 0, 0, 117, 24,
            18, 66, 1, 208, 0, 0, 0, 200, 173, 20, 66, 1, 212, 0, 0, 0, 137, 68, 27, 66, 1, 217, 0,
            0, 0, 243, 51, 40, 66, 1, 218, 0, 0, 0, 225, 58, 23, 66, 1, 220, 0, 0, 0, 132, 221, 22,
            66, 1, 222, 0, 0, 0, 157, 29, 26, 66, 1, 225, 0, 0, 0, 133, 21, 41, 66, 0, 0, 0, 0, 0,
            0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 126, 47,
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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.97035179138183594e+01),
                    "incorrect value for states[0].cn0, expected 3.97035179138183594e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.65238838195800781e+01),
                    "incorrect value for states[1].cn0, expected 3.65238838195800781e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.71697082519531250e+01),
                    "incorrect value for states[2].cn0, expected 3.71697082519531250e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.88169288635253906e+01),
                    "incorrect value for states[3].cn0, expected 3.88169288635253906e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.20507316589355469e+01),
                    "incorrect value for states[4].cn0, expected 4.20507316589355469e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.78074989318847656e+01),
                    "incorrect value for states[5].cn0, expected 3.78074989318847656e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.77163238525390625e+01),
                    "incorrect value for states[6].cn0, expected 3.77163238525390625e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.85289192199707031e+01),
                    "incorrect value for states[7].cn0, expected 3.85289192199707031e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.22710151672363281e+01),
                    "incorrect value for states[8].cn0, expected 4.22710151672363281e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
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
fn test_json2sbp_auto_check_sbp_tracking_msg_tracking_state() {
    {
        let json_input = r#"{"crc":28557,"length":252,"msg_type":65,"payload":"dbgDZiZqjI0ZBFrD9mxLUol/LaMgLrtdmTzJkxcdBdC1HttF/ogDeSFikNeFtg44qU3aPvJUq/mYiYOCwRUqRP3j2OMYGtKzEw/j/3pLu8jZMNp6u+6Ole43+9SAoMJocf+NPitF9Sdk5mw490SVj4ll6UYxpSZu2uZQ1cSzi4APssSrCNRhwlPpT2M3Wh+0BRlpuhbgUG8IMGqmBDCcMVYTjpJbfHNAHOZzsr6DEPJpO7ZxwLQws6YfrNNN5IwxgE3wwobCKToSNYE3W0iGXCHgnTi6NuCuUlSUvuw2PkM01zn+EIUkrtuskRHAs29hzzjQhrQRK+L/toxx","preamble":85,"sender":33079,"states":[{"sid":{"sat":117,"code":184},"fcn":3,"cn0":102},{"sid":{"sat":38,"code":106},"fcn":140,"cn0":141},{"sid":{"sat":25,"code":4},"fcn":90,"cn0":195},{"sid":{"sat":246,"code":108},"fcn":75,"cn0":82},{"sid":{"sat":137,"code":127},"fcn":45,"cn0":163},{"sid":{"sat":32,"code":46},"fcn":187,"cn0":93},{"sid":{"sat":153,"code":60},"fcn":201,"cn0":147},{"sid":{"sat":23,"code":29},"fcn":5,"cn0":208},{"sid":{"sat":181,"code":30},"fcn":219,"cn0":69},{"sid":{"sat":254,"code":136},"fcn":3,"cn0":121},{"sid":{"sat":33,"code":98},"fcn":144,"cn0":215},{"sid":{"sat":133,"code":182},"fcn":14,"cn0":56},{"sid":{"sat":169,"code":77},"fcn":218,"cn0":62},{"sid":{"sat":242,"code":84},"fcn":171,"cn0":249},{"sid":{"sat":152,"code":137},"fcn":131,"cn0":130},{"sid":{"sat":193,"code":21},"fcn":42,"cn0":68},{"sid":{"sat":253,"code":227},"fcn":216,"cn0":227},{"sid":{"sat":24,"code":26},"fcn":210,"cn0":179},{"sid":{"sat":19,"code":15},"fcn":227,"cn0":255},{"sid":{"sat":122,"code":75},"fcn":187,"cn0":200},{"sid":{"sat":217,"code":48},"fcn":218,"cn0":122},{"sid":{"sat":187,"code":238},"fcn":142,"cn0":149},{"sid":{"sat":238,"code":55},"fcn":251,"cn0":212},{"sid":{"sat":128,"code":160},"fcn":194,"cn0":104},{"sid":{"sat":113,"code":255},"fcn":141,"cn0":62},{"sid":{"sat":43,"code":69},"fcn":245,"cn0":39},{"sid":{"sat":100,"code":230},"fcn":108,"cn0":56},{"sid":{"sat":247,"code":68},"fcn":149,"cn0":143},{"sid":{"sat":137,"code":101},"fcn":233,"cn0":70},{"sid":{"sat":49,"code":165},"fcn":38,"cn0":110},{"sid":{"sat":218,"code":230},"fcn":80,"cn0":213},{"sid":{"sat":196,"code":179},"fcn":139,"cn0":128},{"sid":{"sat":15,"code":178},"fcn":196,"cn0":171},{"sid":{"sat":8,"code":212},"fcn":97,"cn0":194},{"sid":{"sat":83,"code":233},"fcn":79,"cn0":99},{"sid":{"sat":55,"code":90},"fcn":31,"cn0":180},{"sid":{"sat":5,"code":25},"fcn":105,"cn0":186},{"sid":{"sat":22,"code":224},"fcn":80,"cn0":111},{"sid":{"sat":8,"code":48},"fcn":106,"cn0":166},{"sid":{"sat":4,"code":48},"fcn":156,"cn0":49},{"sid":{"sat":86,"code":19},"fcn":142,"cn0":146},{"sid":{"sat":91,"code":124},"fcn":115,"cn0":64},{"sid":{"sat":28,"code":230},"fcn":115,"cn0":178},{"sid":{"sat":190,"code":131},"fcn":16,"cn0":242},{"sid":{"sat":105,"code":59},"fcn":182,"cn0":113},{"sid":{"sat":192,"code":180},"fcn":48,"cn0":179},{"sid":{"sat":166,"code":31},"fcn":172,"cn0":211},{"sid":{"sat":77,"code":228},"fcn":140,"cn0":49},{"sid":{"sat":128,"code":77},"fcn":240,"cn0":194},{"sid":{"sat":134,"code":194},"fcn":41,"cn0":58},{"sid":{"sat":18,"code":53},"fcn":129,"cn0":55},{"sid":{"sat":91,"code":72},"fcn":134,"cn0":92},{"sid":{"sat":33,"code":224},"fcn":157,"cn0":56},{"sid":{"sat":186,"code":54},"fcn":224,"cn0":174},{"sid":{"sat":82,"code":84},"fcn":148,"cn0":190},{"sid":{"sat":236,"code":54},"fcn":62,"cn0":67},{"sid":{"sat":52,"code":215},"fcn":57,"cn0":254},{"sid":{"sat":16,"code":133},"fcn":36,"cn0":174},{"sid":{"sat":219,"code":172},"fcn":145,"cn0":17},{"sid":{"sat":192,"code":179},"fcn":111,"cn0":97},{"sid":{"sat":207,"code":56},"fcn":208,"cn0":134},{"sid":{"sat":180,"code":17},"fcn":43,"cn0":226},{"sid":{"sat":255,"code":182},"fcn":140,"cn0":113}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingState(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x41,
                    "Incorrect message type, expected 0x41, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x8137,
                    "incorrect sender id, expected 0x8137, is {sender_id}"
                );
                assert_eq!(
                    msg.states[0].cn0, 102,
                    "incorrect value for states[0].cn0, expected 102, is {}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].fcn, 3,
                    "incorrect value for states[0].fcn, expected 3, is {}",
                    msg.states[0].fcn
                );
                assert_eq!(
                    msg.states[0].sid.code, 184,
                    "incorrect value for states[0].sid.code, expected 184, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.sat, 117,
                    "incorrect value for states[0].sid.sat, expected 117, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[1].cn0, 141,
                    "incorrect value for states[1].cn0, expected 141, is {}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].fcn, 140,
                    "incorrect value for states[1].fcn, expected 140, is {}",
                    msg.states[1].fcn
                );
                assert_eq!(
                    msg.states[1].sid.code, 106,
                    "incorrect value for states[1].sid.code, expected 106, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.sat, 38,
                    "incorrect value for states[1].sid.sat, expected 38, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[2].cn0, 195,
                    "incorrect value for states[2].cn0, expected 195, is {}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].fcn, 90,
                    "incorrect value for states[2].fcn, expected 90, is {}",
                    msg.states[2].fcn
                );
                assert_eq!(
                    msg.states[2].sid.code, 4,
                    "incorrect value for states[2].sid.code, expected 4, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.sat, 25,
                    "incorrect value for states[2].sid.sat, expected 25, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[3].cn0, 82,
                    "incorrect value for states[3].cn0, expected 82, is {}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].fcn, 75,
                    "incorrect value for states[3].fcn, expected 75, is {}",
                    msg.states[3].fcn
                );
                assert_eq!(
                    msg.states[3].sid.code, 108,
                    "incorrect value for states[3].sid.code, expected 108, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.sat, 246,
                    "incorrect value for states[3].sid.sat, expected 246, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[4].cn0, 163,
                    "incorrect value for states[4].cn0, expected 163, is {}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].fcn, 45,
                    "incorrect value for states[4].fcn, expected 45, is {}",
                    msg.states[4].fcn
                );
                assert_eq!(
                    msg.states[4].sid.code, 127,
                    "incorrect value for states[4].sid.code, expected 127, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.sat, 137,
                    "incorrect value for states[4].sid.sat, expected 137, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[5].cn0, 93,
                    "incorrect value for states[5].cn0, expected 93, is {}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].fcn, 187,
                    "incorrect value for states[5].fcn, expected 187, is {}",
                    msg.states[5].fcn
                );
                assert_eq!(
                    msg.states[5].sid.code, 46,
                    "incorrect value for states[5].sid.code, expected 46, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.sat, 32,
                    "incorrect value for states[5].sid.sat, expected 32, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[6].cn0, 147,
                    "incorrect value for states[6].cn0, expected 147, is {}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].fcn, 201,
                    "incorrect value for states[6].fcn, expected 201, is {}",
                    msg.states[6].fcn
                );
                assert_eq!(
                    msg.states[6].sid.code, 60,
                    "incorrect value for states[6].sid.code, expected 60, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.sat, 153,
                    "incorrect value for states[6].sid.sat, expected 153, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[7].cn0, 208,
                    "incorrect value for states[7].cn0, expected 208, is {}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].fcn, 5,
                    "incorrect value for states[7].fcn, expected 5, is {}",
                    msg.states[7].fcn
                );
                assert_eq!(
                    msg.states[7].sid.code, 29,
                    "incorrect value for states[7].sid.code, expected 29, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.sat, 23,
                    "incorrect value for states[7].sid.sat, expected 23, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[8].cn0, 69,
                    "incorrect value for states[8].cn0, expected 69, is {}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].fcn, 219,
                    "incorrect value for states[8].fcn, expected 219, is {}",
                    msg.states[8].fcn
                );
                assert_eq!(
                    msg.states[8].sid.code, 30,
                    "incorrect value for states[8].sid.code, expected 30, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.sat, 181,
                    "incorrect value for states[8].sid.sat, expected 181, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[9].cn0, 121,
                    "incorrect value for states[9].cn0, expected 121, is {}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].fcn, 3,
                    "incorrect value for states[9].fcn, expected 3, is {}",
                    msg.states[9].fcn
                );
                assert_eq!(
                    msg.states[9].sid.code, 136,
                    "incorrect value for states[9].sid.code, expected 136, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.sat, 254,
                    "incorrect value for states[9].sid.sat, expected 254, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[10].cn0, 215,
                    "incorrect value for states[10].cn0, expected 215, is {}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].fcn, 144,
                    "incorrect value for states[10].fcn, expected 144, is {}",
                    msg.states[10].fcn
                );
                assert_eq!(
                    msg.states[10].sid.code, 98,
                    "incorrect value for states[10].sid.code, expected 98, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.sat, 33,
                    "incorrect value for states[10].sid.sat, expected 33, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[11].cn0, 56,
                    "incorrect value for states[11].cn0, expected 56, is {}",
                    msg.states[11].cn0
                );
                assert_eq!(
                    msg.states[11].fcn, 14,
                    "incorrect value for states[11].fcn, expected 14, is {}",
                    msg.states[11].fcn
                );
                assert_eq!(
                    msg.states[11].sid.code, 182,
                    "incorrect value for states[11].sid.code, expected 182, is {}",
                    msg.states[11].sid.code
                );
                assert_eq!(
                    msg.states[11].sid.sat, 133,
                    "incorrect value for states[11].sid.sat, expected 133, is {}",
                    msg.states[11].sid.sat
                );
                assert_eq!(
                    msg.states[12].cn0, 62,
                    "incorrect value for states[12].cn0, expected 62, is {}",
                    msg.states[12].cn0
                );
                assert_eq!(
                    msg.states[12].fcn, 218,
                    "incorrect value for states[12].fcn, expected 218, is {}",
                    msg.states[12].fcn
                );
                assert_eq!(
                    msg.states[12].sid.code, 77,
                    "incorrect value for states[12].sid.code, expected 77, is {}",
                    msg.states[12].sid.code
                );
                assert_eq!(
                    msg.states[12].sid.sat, 169,
                    "incorrect value for states[12].sid.sat, expected 169, is {}",
                    msg.states[12].sid.sat
                );
                assert_eq!(
                    msg.states[13].cn0, 249,
                    "incorrect value for states[13].cn0, expected 249, is {}",
                    msg.states[13].cn0
                );
                assert_eq!(
                    msg.states[13].fcn, 171,
                    "incorrect value for states[13].fcn, expected 171, is {}",
                    msg.states[13].fcn
                );
                assert_eq!(
                    msg.states[13].sid.code, 84,
                    "incorrect value for states[13].sid.code, expected 84, is {}",
                    msg.states[13].sid.code
                );
                assert_eq!(
                    msg.states[13].sid.sat, 242,
                    "incorrect value for states[13].sid.sat, expected 242, is {}",
                    msg.states[13].sid.sat
                );
                assert_eq!(
                    msg.states[14].cn0, 130,
                    "incorrect value for states[14].cn0, expected 130, is {}",
                    msg.states[14].cn0
                );
                assert_eq!(
                    msg.states[14].fcn, 131,
                    "incorrect value for states[14].fcn, expected 131, is {}",
                    msg.states[14].fcn
                );
                assert_eq!(
                    msg.states[14].sid.code, 137,
                    "incorrect value for states[14].sid.code, expected 137, is {}",
                    msg.states[14].sid.code
                );
                assert_eq!(
                    msg.states[14].sid.sat, 152,
                    "incorrect value for states[14].sid.sat, expected 152, is {}",
                    msg.states[14].sid.sat
                );
                assert_eq!(
                    msg.states[15].cn0, 68,
                    "incorrect value for states[15].cn0, expected 68, is {}",
                    msg.states[15].cn0
                );
                assert_eq!(
                    msg.states[15].fcn, 42,
                    "incorrect value for states[15].fcn, expected 42, is {}",
                    msg.states[15].fcn
                );
                assert_eq!(
                    msg.states[15].sid.code, 21,
                    "incorrect value for states[15].sid.code, expected 21, is {}",
                    msg.states[15].sid.code
                );
                assert_eq!(
                    msg.states[15].sid.sat, 193,
                    "incorrect value for states[15].sid.sat, expected 193, is {}",
                    msg.states[15].sid.sat
                );
                assert_eq!(
                    msg.states[16].cn0, 227,
                    "incorrect value for states[16].cn0, expected 227, is {}",
                    msg.states[16].cn0
                );
                assert_eq!(
                    msg.states[16].fcn, 216,
                    "incorrect value for states[16].fcn, expected 216, is {}",
                    msg.states[16].fcn
                );
                assert_eq!(
                    msg.states[16].sid.code, 227,
                    "incorrect value for states[16].sid.code, expected 227, is {}",
                    msg.states[16].sid.code
                );
                assert_eq!(
                    msg.states[16].sid.sat, 253,
                    "incorrect value for states[16].sid.sat, expected 253, is {}",
                    msg.states[16].sid.sat
                );
                assert_eq!(
                    msg.states[17].cn0, 179,
                    "incorrect value for states[17].cn0, expected 179, is {}",
                    msg.states[17].cn0
                );
                assert_eq!(
                    msg.states[17].fcn, 210,
                    "incorrect value for states[17].fcn, expected 210, is {}",
                    msg.states[17].fcn
                );
                assert_eq!(
                    msg.states[17].sid.code, 26,
                    "incorrect value for states[17].sid.code, expected 26, is {}",
                    msg.states[17].sid.code
                );
                assert_eq!(
                    msg.states[17].sid.sat, 24,
                    "incorrect value for states[17].sid.sat, expected 24, is {}",
                    msg.states[17].sid.sat
                );
                assert_eq!(
                    msg.states[18].cn0, 255,
                    "incorrect value for states[18].cn0, expected 255, is {}",
                    msg.states[18].cn0
                );
                assert_eq!(
                    msg.states[18].fcn, 227,
                    "incorrect value for states[18].fcn, expected 227, is {}",
                    msg.states[18].fcn
                );
                assert_eq!(
                    msg.states[18].sid.code, 15,
                    "incorrect value for states[18].sid.code, expected 15, is {}",
                    msg.states[18].sid.code
                );
                assert_eq!(
                    msg.states[18].sid.sat, 19,
                    "incorrect value for states[18].sid.sat, expected 19, is {}",
                    msg.states[18].sid.sat
                );
                assert_eq!(
                    msg.states[19].cn0, 200,
                    "incorrect value for states[19].cn0, expected 200, is {}",
                    msg.states[19].cn0
                );
                assert_eq!(
                    msg.states[19].fcn, 187,
                    "incorrect value for states[19].fcn, expected 187, is {}",
                    msg.states[19].fcn
                );
                assert_eq!(
                    msg.states[19].sid.code, 75,
                    "incorrect value for states[19].sid.code, expected 75, is {}",
                    msg.states[19].sid.code
                );
                assert_eq!(
                    msg.states[19].sid.sat, 122,
                    "incorrect value for states[19].sid.sat, expected 122, is {}",
                    msg.states[19].sid.sat
                );
                assert_eq!(
                    msg.states[20].cn0, 122,
                    "incorrect value for states[20].cn0, expected 122, is {}",
                    msg.states[20].cn0
                );
                assert_eq!(
                    msg.states[20].fcn, 218,
                    "incorrect value for states[20].fcn, expected 218, is {}",
                    msg.states[20].fcn
                );
                assert_eq!(
                    msg.states[20].sid.code, 48,
                    "incorrect value for states[20].sid.code, expected 48, is {}",
                    msg.states[20].sid.code
                );
                assert_eq!(
                    msg.states[20].sid.sat, 217,
                    "incorrect value for states[20].sid.sat, expected 217, is {}",
                    msg.states[20].sid.sat
                );
                assert_eq!(
                    msg.states[21].cn0, 149,
                    "incorrect value for states[21].cn0, expected 149, is {}",
                    msg.states[21].cn0
                );
                assert_eq!(
                    msg.states[21].fcn, 142,
                    "incorrect value for states[21].fcn, expected 142, is {}",
                    msg.states[21].fcn
                );
                assert_eq!(
                    msg.states[21].sid.code, 238,
                    "incorrect value for states[21].sid.code, expected 238, is {}",
                    msg.states[21].sid.code
                );
                assert_eq!(
                    msg.states[21].sid.sat, 187,
                    "incorrect value for states[21].sid.sat, expected 187, is {}",
                    msg.states[21].sid.sat
                );
                assert_eq!(
                    msg.states[22].cn0, 212,
                    "incorrect value for states[22].cn0, expected 212, is {}",
                    msg.states[22].cn0
                );
                assert_eq!(
                    msg.states[22].fcn, 251,
                    "incorrect value for states[22].fcn, expected 251, is {}",
                    msg.states[22].fcn
                );
                assert_eq!(
                    msg.states[22].sid.code, 55,
                    "incorrect value for states[22].sid.code, expected 55, is {}",
                    msg.states[22].sid.code
                );
                assert_eq!(
                    msg.states[22].sid.sat, 238,
                    "incorrect value for states[22].sid.sat, expected 238, is {}",
                    msg.states[22].sid.sat
                );
                assert_eq!(
                    msg.states[23].cn0, 104,
                    "incorrect value for states[23].cn0, expected 104, is {}",
                    msg.states[23].cn0
                );
                assert_eq!(
                    msg.states[23].fcn, 194,
                    "incorrect value for states[23].fcn, expected 194, is {}",
                    msg.states[23].fcn
                );
                assert_eq!(
                    msg.states[23].sid.code, 160,
                    "incorrect value for states[23].sid.code, expected 160, is {}",
                    msg.states[23].sid.code
                );
                assert_eq!(
                    msg.states[23].sid.sat, 128,
                    "incorrect value for states[23].sid.sat, expected 128, is {}",
                    msg.states[23].sid.sat
                );
                assert_eq!(
                    msg.states[24].cn0, 62,
                    "incorrect value for states[24].cn0, expected 62, is {}",
                    msg.states[24].cn0
                );
                assert_eq!(
                    msg.states[24].fcn, 141,
                    "incorrect value for states[24].fcn, expected 141, is {}",
                    msg.states[24].fcn
                );
                assert_eq!(
                    msg.states[24].sid.code, 255,
                    "incorrect value for states[24].sid.code, expected 255, is {}",
                    msg.states[24].sid.code
                );
                assert_eq!(
                    msg.states[24].sid.sat, 113,
                    "incorrect value for states[24].sid.sat, expected 113, is {}",
                    msg.states[24].sid.sat
                );
                assert_eq!(
                    msg.states[25].cn0, 39,
                    "incorrect value for states[25].cn0, expected 39, is {}",
                    msg.states[25].cn0
                );
                assert_eq!(
                    msg.states[25].fcn, 245,
                    "incorrect value for states[25].fcn, expected 245, is {}",
                    msg.states[25].fcn
                );
                assert_eq!(
                    msg.states[25].sid.code, 69,
                    "incorrect value for states[25].sid.code, expected 69, is {}",
                    msg.states[25].sid.code
                );
                assert_eq!(
                    msg.states[25].sid.sat, 43,
                    "incorrect value for states[25].sid.sat, expected 43, is {}",
                    msg.states[25].sid.sat
                );
                assert_eq!(
                    msg.states[26].cn0, 56,
                    "incorrect value for states[26].cn0, expected 56, is {}",
                    msg.states[26].cn0
                );
                assert_eq!(
                    msg.states[26].fcn, 108,
                    "incorrect value for states[26].fcn, expected 108, is {}",
                    msg.states[26].fcn
                );
                assert_eq!(
                    msg.states[26].sid.code, 230,
                    "incorrect value for states[26].sid.code, expected 230, is {}",
                    msg.states[26].sid.code
                );
                assert_eq!(
                    msg.states[26].sid.sat, 100,
                    "incorrect value for states[26].sid.sat, expected 100, is {}",
                    msg.states[26].sid.sat
                );
                assert_eq!(
                    msg.states[27].cn0, 143,
                    "incorrect value for states[27].cn0, expected 143, is {}",
                    msg.states[27].cn0
                );
                assert_eq!(
                    msg.states[27].fcn, 149,
                    "incorrect value for states[27].fcn, expected 149, is {}",
                    msg.states[27].fcn
                );
                assert_eq!(
                    msg.states[27].sid.code, 68,
                    "incorrect value for states[27].sid.code, expected 68, is {}",
                    msg.states[27].sid.code
                );
                assert_eq!(
                    msg.states[27].sid.sat, 247,
                    "incorrect value for states[27].sid.sat, expected 247, is {}",
                    msg.states[27].sid.sat
                );
                assert_eq!(
                    msg.states[28].cn0, 70,
                    "incorrect value for states[28].cn0, expected 70, is {}",
                    msg.states[28].cn0
                );
                assert_eq!(
                    msg.states[28].fcn, 233,
                    "incorrect value for states[28].fcn, expected 233, is {}",
                    msg.states[28].fcn
                );
                assert_eq!(
                    msg.states[28].sid.code, 101,
                    "incorrect value for states[28].sid.code, expected 101, is {}",
                    msg.states[28].sid.code
                );
                assert_eq!(
                    msg.states[28].sid.sat, 137,
                    "incorrect value for states[28].sid.sat, expected 137, is {}",
                    msg.states[28].sid.sat
                );
                assert_eq!(
                    msg.states[29].cn0, 110,
                    "incorrect value for states[29].cn0, expected 110, is {}",
                    msg.states[29].cn0
                );
                assert_eq!(
                    msg.states[29].fcn, 38,
                    "incorrect value for states[29].fcn, expected 38, is {}",
                    msg.states[29].fcn
                );
                assert_eq!(
                    msg.states[29].sid.code, 165,
                    "incorrect value for states[29].sid.code, expected 165, is {}",
                    msg.states[29].sid.code
                );
                assert_eq!(
                    msg.states[29].sid.sat, 49,
                    "incorrect value for states[29].sid.sat, expected 49, is {}",
                    msg.states[29].sid.sat
                );
                assert_eq!(
                    msg.states[30].cn0, 213,
                    "incorrect value for states[30].cn0, expected 213, is {}",
                    msg.states[30].cn0
                );
                assert_eq!(
                    msg.states[30].fcn, 80,
                    "incorrect value for states[30].fcn, expected 80, is {}",
                    msg.states[30].fcn
                );
                assert_eq!(
                    msg.states[30].sid.code, 230,
                    "incorrect value for states[30].sid.code, expected 230, is {}",
                    msg.states[30].sid.code
                );
                assert_eq!(
                    msg.states[30].sid.sat, 218,
                    "incorrect value for states[30].sid.sat, expected 218, is {}",
                    msg.states[30].sid.sat
                );
                assert_eq!(
                    msg.states[31].cn0, 128,
                    "incorrect value for states[31].cn0, expected 128, is {}",
                    msg.states[31].cn0
                );
                assert_eq!(
                    msg.states[31].fcn, 139,
                    "incorrect value for states[31].fcn, expected 139, is {}",
                    msg.states[31].fcn
                );
                assert_eq!(
                    msg.states[31].sid.code, 179,
                    "incorrect value for states[31].sid.code, expected 179, is {}",
                    msg.states[31].sid.code
                );
                assert_eq!(
                    msg.states[31].sid.sat, 196,
                    "incorrect value for states[31].sid.sat, expected 196, is {}",
                    msg.states[31].sid.sat
                );
                assert_eq!(
                    msg.states[32].cn0, 171,
                    "incorrect value for states[32].cn0, expected 171, is {}",
                    msg.states[32].cn0
                );
                assert_eq!(
                    msg.states[32].fcn, 196,
                    "incorrect value for states[32].fcn, expected 196, is {}",
                    msg.states[32].fcn
                );
                assert_eq!(
                    msg.states[32].sid.code, 178,
                    "incorrect value for states[32].sid.code, expected 178, is {}",
                    msg.states[32].sid.code
                );
                assert_eq!(
                    msg.states[32].sid.sat, 15,
                    "incorrect value for states[32].sid.sat, expected 15, is {}",
                    msg.states[32].sid.sat
                );
                assert_eq!(
                    msg.states[33].cn0, 194,
                    "incorrect value for states[33].cn0, expected 194, is {}",
                    msg.states[33].cn0
                );
                assert_eq!(
                    msg.states[33].fcn, 97,
                    "incorrect value for states[33].fcn, expected 97, is {}",
                    msg.states[33].fcn
                );
                assert_eq!(
                    msg.states[33].sid.code, 212,
                    "incorrect value for states[33].sid.code, expected 212, is {}",
                    msg.states[33].sid.code
                );
                assert_eq!(
                    msg.states[33].sid.sat, 8,
                    "incorrect value for states[33].sid.sat, expected 8, is {}",
                    msg.states[33].sid.sat
                );
                assert_eq!(
                    msg.states[34].cn0, 99,
                    "incorrect value for states[34].cn0, expected 99, is {}",
                    msg.states[34].cn0
                );
                assert_eq!(
                    msg.states[34].fcn, 79,
                    "incorrect value for states[34].fcn, expected 79, is {}",
                    msg.states[34].fcn
                );
                assert_eq!(
                    msg.states[34].sid.code, 233,
                    "incorrect value for states[34].sid.code, expected 233, is {}",
                    msg.states[34].sid.code
                );
                assert_eq!(
                    msg.states[34].sid.sat, 83,
                    "incorrect value for states[34].sid.sat, expected 83, is {}",
                    msg.states[34].sid.sat
                );
                assert_eq!(
                    msg.states[35].cn0, 180,
                    "incorrect value for states[35].cn0, expected 180, is {}",
                    msg.states[35].cn0
                );
                assert_eq!(
                    msg.states[35].fcn, 31,
                    "incorrect value for states[35].fcn, expected 31, is {}",
                    msg.states[35].fcn
                );
                assert_eq!(
                    msg.states[35].sid.code, 90,
                    "incorrect value for states[35].sid.code, expected 90, is {}",
                    msg.states[35].sid.code
                );
                assert_eq!(
                    msg.states[35].sid.sat, 55,
                    "incorrect value for states[35].sid.sat, expected 55, is {}",
                    msg.states[35].sid.sat
                );
                assert_eq!(
                    msg.states[36].cn0, 186,
                    "incorrect value for states[36].cn0, expected 186, is {}",
                    msg.states[36].cn0
                );
                assert_eq!(
                    msg.states[36].fcn, 105,
                    "incorrect value for states[36].fcn, expected 105, is {}",
                    msg.states[36].fcn
                );
                assert_eq!(
                    msg.states[36].sid.code, 25,
                    "incorrect value for states[36].sid.code, expected 25, is {}",
                    msg.states[36].sid.code
                );
                assert_eq!(
                    msg.states[36].sid.sat, 5,
                    "incorrect value for states[36].sid.sat, expected 5, is {}",
                    msg.states[36].sid.sat
                );
                assert_eq!(
                    msg.states[37].cn0, 111,
                    "incorrect value for states[37].cn0, expected 111, is {}",
                    msg.states[37].cn0
                );
                assert_eq!(
                    msg.states[37].fcn, 80,
                    "incorrect value for states[37].fcn, expected 80, is {}",
                    msg.states[37].fcn
                );
                assert_eq!(
                    msg.states[37].sid.code, 224,
                    "incorrect value for states[37].sid.code, expected 224, is {}",
                    msg.states[37].sid.code
                );
                assert_eq!(
                    msg.states[37].sid.sat, 22,
                    "incorrect value for states[37].sid.sat, expected 22, is {}",
                    msg.states[37].sid.sat
                );
                assert_eq!(
                    msg.states[38].cn0, 166,
                    "incorrect value for states[38].cn0, expected 166, is {}",
                    msg.states[38].cn0
                );
                assert_eq!(
                    msg.states[38].fcn, 106,
                    "incorrect value for states[38].fcn, expected 106, is {}",
                    msg.states[38].fcn
                );
                assert_eq!(
                    msg.states[38].sid.code, 48,
                    "incorrect value for states[38].sid.code, expected 48, is {}",
                    msg.states[38].sid.code
                );
                assert_eq!(
                    msg.states[38].sid.sat, 8,
                    "incorrect value for states[38].sid.sat, expected 8, is {}",
                    msg.states[38].sid.sat
                );
                assert_eq!(
                    msg.states[39].cn0, 49,
                    "incorrect value for states[39].cn0, expected 49, is {}",
                    msg.states[39].cn0
                );
                assert_eq!(
                    msg.states[39].fcn, 156,
                    "incorrect value for states[39].fcn, expected 156, is {}",
                    msg.states[39].fcn
                );
                assert_eq!(
                    msg.states[39].sid.code, 48,
                    "incorrect value for states[39].sid.code, expected 48, is {}",
                    msg.states[39].sid.code
                );
                assert_eq!(
                    msg.states[39].sid.sat, 4,
                    "incorrect value for states[39].sid.sat, expected 4, is {}",
                    msg.states[39].sid.sat
                );
                assert_eq!(
                    msg.states[40].cn0, 146,
                    "incorrect value for states[40].cn0, expected 146, is {}",
                    msg.states[40].cn0
                );
                assert_eq!(
                    msg.states[40].fcn, 142,
                    "incorrect value for states[40].fcn, expected 142, is {}",
                    msg.states[40].fcn
                );
                assert_eq!(
                    msg.states[40].sid.code, 19,
                    "incorrect value for states[40].sid.code, expected 19, is {}",
                    msg.states[40].sid.code
                );
                assert_eq!(
                    msg.states[40].sid.sat, 86,
                    "incorrect value for states[40].sid.sat, expected 86, is {}",
                    msg.states[40].sid.sat
                );
                assert_eq!(
                    msg.states[41].cn0, 64,
                    "incorrect value for states[41].cn0, expected 64, is {}",
                    msg.states[41].cn0
                );
                assert_eq!(
                    msg.states[41].fcn, 115,
                    "incorrect value for states[41].fcn, expected 115, is {}",
                    msg.states[41].fcn
                );
                assert_eq!(
                    msg.states[41].sid.code, 124,
                    "incorrect value for states[41].sid.code, expected 124, is {}",
                    msg.states[41].sid.code
                );
                assert_eq!(
                    msg.states[41].sid.sat, 91,
                    "incorrect value for states[41].sid.sat, expected 91, is {}",
                    msg.states[41].sid.sat
                );
                assert_eq!(
                    msg.states[42].cn0, 178,
                    "incorrect value for states[42].cn0, expected 178, is {}",
                    msg.states[42].cn0
                );
                assert_eq!(
                    msg.states[42].fcn, 115,
                    "incorrect value for states[42].fcn, expected 115, is {}",
                    msg.states[42].fcn
                );
                assert_eq!(
                    msg.states[42].sid.code, 230,
                    "incorrect value for states[42].sid.code, expected 230, is {}",
                    msg.states[42].sid.code
                );
                assert_eq!(
                    msg.states[42].sid.sat, 28,
                    "incorrect value for states[42].sid.sat, expected 28, is {}",
                    msg.states[42].sid.sat
                );
                assert_eq!(
                    msg.states[43].cn0, 242,
                    "incorrect value for states[43].cn0, expected 242, is {}",
                    msg.states[43].cn0
                );
                assert_eq!(
                    msg.states[43].fcn, 16,
                    "incorrect value for states[43].fcn, expected 16, is {}",
                    msg.states[43].fcn
                );
                assert_eq!(
                    msg.states[43].sid.code, 131,
                    "incorrect value for states[43].sid.code, expected 131, is {}",
                    msg.states[43].sid.code
                );
                assert_eq!(
                    msg.states[43].sid.sat, 190,
                    "incorrect value for states[43].sid.sat, expected 190, is {}",
                    msg.states[43].sid.sat
                );
                assert_eq!(
                    msg.states[44].cn0, 113,
                    "incorrect value for states[44].cn0, expected 113, is {}",
                    msg.states[44].cn0
                );
                assert_eq!(
                    msg.states[44].fcn, 182,
                    "incorrect value for states[44].fcn, expected 182, is {}",
                    msg.states[44].fcn
                );
                assert_eq!(
                    msg.states[44].sid.code, 59,
                    "incorrect value for states[44].sid.code, expected 59, is {}",
                    msg.states[44].sid.code
                );
                assert_eq!(
                    msg.states[44].sid.sat, 105,
                    "incorrect value for states[44].sid.sat, expected 105, is {}",
                    msg.states[44].sid.sat
                );
                assert_eq!(
                    msg.states[45].cn0, 179,
                    "incorrect value for states[45].cn0, expected 179, is {}",
                    msg.states[45].cn0
                );
                assert_eq!(
                    msg.states[45].fcn, 48,
                    "incorrect value for states[45].fcn, expected 48, is {}",
                    msg.states[45].fcn
                );
                assert_eq!(
                    msg.states[45].sid.code, 180,
                    "incorrect value for states[45].sid.code, expected 180, is {}",
                    msg.states[45].sid.code
                );
                assert_eq!(
                    msg.states[45].sid.sat, 192,
                    "incorrect value for states[45].sid.sat, expected 192, is {}",
                    msg.states[45].sid.sat
                );
                assert_eq!(
                    msg.states[46].cn0, 211,
                    "incorrect value for states[46].cn0, expected 211, is {}",
                    msg.states[46].cn0
                );
                assert_eq!(
                    msg.states[46].fcn, 172,
                    "incorrect value for states[46].fcn, expected 172, is {}",
                    msg.states[46].fcn
                );
                assert_eq!(
                    msg.states[46].sid.code, 31,
                    "incorrect value for states[46].sid.code, expected 31, is {}",
                    msg.states[46].sid.code
                );
                assert_eq!(
                    msg.states[46].sid.sat, 166,
                    "incorrect value for states[46].sid.sat, expected 166, is {}",
                    msg.states[46].sid.sat
                );
                assert_eq!(
                    msg.states[47].cn0, 49,
                    "incorrect value for states[47].cn0, expected 49, is {}",
                    msg.states[47].cn0
                );
                assert_eq!(
                    msg.states[47].fcn, 140,
                    "incorrect value for states[47].fcn, expected 140, is {}",
                    msg.states[47].fcn
                );
                assert_eq!(
                    msg.states[47].sid.code, 228,
                    "incorrect value for states[47].sid.code, expected 228, is {}",
                    msg.states[47].sid.code
                );
                assert_eq!(
                    msg.states[47].sid.sat, 77,
                    "incorrect value for states[47].sid.sat, expected 77, is {}",
                    msg.states[47].sid.sat
                );
                assert_eq!(
                    msg.states[48].cn0, 194,
                    "incorrect value for states[48].cn0, expected 194, is {}",
                    msg.states[48].cn0
                );
                assert_eq!(
                    msg.states[48].fcn, 240,
                    "incorrect value for states[48].fcn, expected 240, is {}",
                    msg.states[48].fcn
                );
                assert_eq!(
                    msg.states[48].sid.code, 77,
                    "incorrect value for states[48].sid.code, expected 77, is {}",
                    msg.states[48].sid.code
                );
                assert_eq!(
                    msg.states[48].sid.sat, 128,
                    "incorrect value for states[48].sid.sat, expected 128, is {}",
                    msg.states[48].sid.sat
                );
                assert_eq!(
                    msg.states[49].cn0, 58,
                    "incorrect value for states[49].cn0, expected 58, is {}",
                    msg.states[49].cn0
                );
                assert_eq!(
                    msg.states[49].fcn, 41,
                    "incorrect value for states[49].fcn, expected 41, is {}",
                    msg.states[49].fcn
                );
                assert_eq!(
                    msg.states[49].sid.code, 194,
                    "incorrect value for states[49].sid.code, expected 194, is {}",
                    msg.states[49].sid.code
                );
                assert_eq!(
                    msg.states[49].sid.sat, 134,
                    "incorrect value for states[49].sid.sat, expected 134, is {}",
                    msg.states[49].sid.sat
                );
                assert_eq!(
                    msg.states[50].cn0, 55,
                    "incorrect value for states[50].cn0, expected 55, is {}",
                    msg.states[50].cn0
                );
                assert_eq!(
                    msg.states[50].fcn, 129,
                    "incorrect value for states[50].fcn, expected 129, is {}",
                    msg.states[50].fcn
                );
                assert_eq!(
                    msg.states[50].sid.code, 53,
                    "incorrect value for states[50].sid.code, expected 53, is {}",
                    msg.states[50].sid.code
                );
                assert_eq!(
                    msg.states[50].sid.sat, 18,
                    "incorrect value for states[50].sid.sat, expected 18, is {}",
                    msg.states[50].sid.sat
                );
                assert_eq!(
                    msg.states[51].cn0, 92,
                    "incorrect value for states[51].cn0, expected 92, is {}",
                    msg.states[51].cn0
                );
                assert_eq!(
                    msg.states[51].fcn, 134,
                    "incorrect value for states[51].fcn, expected 134, is {}",
                    msg.states[51].fcn
                );
                assert_eq!(
                    msg.states[51].sid.code, 72,
                    "incorrect value for states[51].sid.code, expected 72, is {}",
                    msg.states[51].sid.code
                );
                assert_eq!(
                    msg.states[51].sid.sat, 91,
                    "incorrect value for states[51].sid.sat, expected 91, is {}",
                    msg.states[51].sid.sat
                );
                assert_eq!(
                    msg.states[52].cn0, 56,
                    "incorrect value for states[52].cn0, expected 56, is {}",
                    msg.states[52].cn0
                );
                assert_eq!(
                    msg.states[52].fcn, 157,
                    "incorrect value for states[52].fcn, expected 157, is {}",
                    msg.states[52].fcn
                );
                assert_eq!(
                    msg.states[52].sid.code, 224,
                    "incorrect value for states[52].sid.code, expected 224, is {}",
                    msg.states[52].sid.code
                );
                assert_eq!(
                    msg.states[52].sid.sat, 33,
                    "incorrect value for states[52].sid.sat, expected 33, is {}",
                    msg.states[52].sid.sat
                );
                assert_eq!(
                    msg.states[53].cn0, 174,
                    "incorrect value for states[53].cn0, expected 174, is {}",
                    msg.states[53].cn0
                );
                assert_eq!(
                    msg.states[53].fcn, 224,
                    "incorrect value for states[53].fcn, expected 224, is {}",
                    msg.states[53].fcn
                );
                assert_eq!(
                    msg.states[53].sid.code, 54,
                    "incorrect value for states[53].sid.code, expected 54, is {}",
                    msg.states[53].sid.code
                );
                assert_eq!(
                    msg.states[53].sid.sat, 186,
                    "incorrect value for states[53].sid.sat, expected 186, is {}",
                    msg.states[53].sid.sat
                );
                assert_eq!(
                    msg.states[54].cn0, 190,
                    "incorrect value for states[54].cn0, expected 190, is {}",
                    msg.states[54].cn0
                );
                assert_eq!(
                    msg.states[54].fcn, 148,
                    "incorrect value for states[54].fcn, expected 148, is {}",
                    msg.states[54].fcn
                );
                assert_eq!(
                    msg.states[54].sid.code, 84,
                    "incorrect value for states[54].sid.code, expected 84, is {}",
                    msg.states[54].sid.code
                );
                assert_eq!(
                    msg.states[54].sid.sat, 82,
                    "incorrect value for states[54].sid.sat, expected 82, is {}",
                    msg.states[54].sid.sat
                );
                assert_eq!(
                    msg.states[55].cn0, 67,
                    "incorrect value for states[55].cn0, expected 67, is {}",
                    msg.states[55].cn0
                );
                assert_eq!(
                    msg.states[55].fcn, 62,
                    "incorrect value for states[55].fcn, expected 62, is {}",
                    msg.states[55].fcn
                );
                assert_eq!(
                    msg.states[55].sid.code, 54,
                    "incorrect value for states[55].sid.code, expected 54, is {}",
                    msg.states[55].sid.code
                );
                assert_eq!(
                    msg.states[55].sid.sat, 236,
                    "incorrect value for states[55].sid.sat, expected 236, is {}",
                    msg.states[55].sid.sat
                );
                assert_eq!(
                    msg.states[56].cn0, 254,
                    "incorrect value for states[56].cn0, expected 254, is {}",
                    msg.states[56].cn0
                );
                assert_eq!(
                    msg.states[56].fcn, 57,
                    "incorrect value for states[56].fcn, expected 57, is {}",
                    msg.states[56].fcn
                );
                assert_eq!(
                    msg.states[56].sid.code, 215,
                    "incorrect value for states[56].sid.code, expected 215, is {}",
                    msg.states[56].sid.code
                );
                assert_eq!(
                    msg.states[56].sid.sat, 52,
                    "incorrect value for states[56].sid.sat, expected 52, is {}",
                    msg.states[56].sid.sat
                );
                assert_eq!(
                    msg.states[57].cn0, 174,
                    "incorrect value for states[57].cn0, expected 174, is {}",
                    msg.states[57].cn0
                );
                assert_eq!(
                    msg.states[57].fcn, 36,
                    "incorrect value for states[57].fcn, expected 36, is {}",
                    msg.states[57].fcn
                );
                assert_eq!(
                    msg.states[57].sid.code, 133,
                    "incorrect value for states[57].sid.code, expected 133, is {}",
                    msg.states[57].sid.code
                );
                assert_eq!(
                    msg.states[57].sid.sat, 16,
                    "incorrect value for states[57].sid.sat, expected 16, is {}",
                    msg.states[57].sid.sat
                );
                assert_eq!(
                    msg.states[58].cn0, 17,
                    "incorrect value for states[58].cn0, expected 17, is {}",
                    msg.states[58].cn0
                );
                assert_eq!(
                    msg.states[58].fcn, 145,
                    "incorrect value for states[58].fcn, expected 145, is {}",
                    msg.states[58].fcn
                );
                assert_eq!(
                    msg.states[58].sid.code, 172,
                    "incorrect value for states[58].sid.code, expected 172, is {}",
                    msg.states[58].sid.code
                );
                assert_eq!(
                    msg.states[58].sid.sat, 219,
                    "incorrect value for states[58].sid.sat, expected 219, is {}",
                    msg.states[58].sid.sat
                );
                assert_eq!(
                    msg.states[59].cn0, 97,
                    "incorrect value for states[59].cn0, expected 97, is {}",
                    msg.states[59].cn0
                );
                assert_eq!(
                    msg.states[59].fcn, 111,
                    "incorrect value for states[59].fcn, expected 111, is {}",
                    msg.states[59].fcn
                );
                assert_eq!(
                    msg.states[59].sid.code, 179,
                    "incorrect value for states[59].sid.code, expected 179, is {}",
                    msg.states[59].sid.code
                );
                assert_eq!(
                    msg.states[59].sid.sat, 192,
                    "incorrect value for states[59].sid.sat, expected 192, is {}",
                    msg.states[59].sid.sat
                );
                assert_eq!(
                    msg.states[60].cn0, 134,
                    "incorrect value for states[60].cn0, expected 134, is {}",
                    msg.states[60].cn0
                );
                assert_eq!(
                    msg.states[60].fcn, 208,
                    "incorrect value for states[60].fcn, expected 208, is {}",
                    msg.states[60].fcn
                );
                assert_eq!(
                    msg.states[60].sid.code, 56,
                    "incorrect value for states[60].sid.code, expected 56, is {}",
                    msg.states[60].sid.code
                );
                assert_eq!(
                    msg.states[60].sid.sat, 207,
                    "incorrect value for states[60].sid.sat, expected 207, is {}",
                    msg.states[60].sid.sat
                );
                assert_eq!(
                    msg.states[61].cn0, 226,
                    "incorrect value for states[61].cn0, expected 226, is {}",
                    msg.states[61].cn0
                );
                assert_eq!(
                    msg.states[61].fcn, 43,
                    "incorrect value for states[61].fcn, expected 43, is {}",
                    msg.states[61].fcn
                );
                assert_eq!(
                    msg.states[61].sid.code, 17,
                    "incorrect value for states[61].sid.code, expected 17, is {}",
                    msg.states[61].sid.code
                );
                assert_eq!(
                    msg.states[61].sid.sat, 180,
                    "incorrect value for states[61].sid.sat, expected 180, is {}",
                    msg.states[61].sid.sat
                );
                assert_eq!(
                    msg.states[62].cn0, 113,
                    "incorrect value for states[62].cn0, expected 113, is {}",
                    msg.states[62].cn0
                );
                assert_eq!(
                    msg.states[62].fcn, 140,
                    "incorrect value for states[62].fcn, expected 140, is {}",
                    msg.states[62].fcn
                );
                assert_eq!(
                    msg.states[62].sid.code, 182,
                    "incorrect value for states[62].sid.code, expected 182, is {}",
                    msg.states[62].sid.code
                );
                assert_eq!(
                    msg.states[62].sid.sat, 255,
                    "incorrect value for states[62].sid.sat, expected 255, is {}",
                    msg.states[62].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingState"),
        };
    }
    {
        let json_input = r#"{"sender": 55286, "msg_type": 19, "states": [{"state": 1, "cn0": 39.24782180786133, "sid": {"code": 0, "reserved": 0, "sat": 202}}, {"state": 1, "cn0": 36.09756088256836, "sid": {"code": 0, "reserved": 0, "sat": 203}}, {"state": 1, "cn0": 37.62678527832031, "sid": {"code": 0, "reserved": 0, "sat": 208}}, {"state": 1, "cn0": 39.020729064941406, "sid": {"code": 0, "reserved": 0, "sat": 212}}, {"state": 1, "cn0": 42.03290557861328, "sid": {"code": 0, "reserved": 0, "sat": 217}}, {"state": 1, "cn0": 37.43546676635742, "sid": {"code": 0, "reserved": 0, "sat": 218}}, {"state": 1, "cn0": 38.4229621887207, "sid": {"code": 0, "reserved": 0, "sat": 220}}, {"state": 1, "cn0": 38.91520309448242, "sid": {"code": 0, "reserved": 0, "sat": 222}}, {"state": 1, "cn0": 42.62259292602539, "sid": {"code": 0, "reserved": 0, "sat": 225}}, {"state": 0, "cn0": -1.0, "sid": {"code": 0, "reserved": 0, "sat": 0}}, {"state": 0, "cn0": -1.0, "sid": {"code": 0, "reserved": 0, "sat": 0}}], "crc": 25054, "length": 99, "preamble": 85, "payload": "AcoAAADF/RxCAcsAAADnYxBCAdAAAADUgRZCAdQAAAA6FRxCAdkAAACyIShCAdoAAADrvRVCAdwAAAAdsRlCAd4AAAArqRtCAeEAAACJfSpCAAAAAAAAAIC/AAAAAAAAAIC/"}"#.as_bytes();

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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.92478218078613281e+01),
                    "incorrect value for states[0].cn0, expected 3.92478218078613281e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.60975608825683594e+01),
                    "incorrect value for states[1].cn0, expected 3.60975608825683594e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.76267852783203125e+01),
                    "incorrect value for states[2].cn0, expected 3.76267852783203125e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.90207290649414062e+01),
                    "incorrect value for states[3].cn0, expected 3.90207290649414062e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.20329055786132812e+01),
                    "incorrect value for states[4].cn0, expected 4.20329055786132812e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.74354667663574219e+01),
                    "incorrect value for states[5].cn0, expected 3.74354667663574219e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.84229621887207031e+01),
                    "incorrect value for states[6].cn0, expected 3.84229621887207031e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.89152030944824219e+01),
                    "incorrect value for states[7].cn0, expected 3.89152030944824219e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.26225929260253906e+01),
                    "incorrect value for states[8].cn0, expected 4.26225929260253906e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };
    }
    {
        let json_input = r#"{"sender": 55286, "msg_type": 19, "states": [{"state": 1, "cn0": 38.994117736816406, "sid": {"code": 0, "reserved": 0, "sat": 202}}, {"state": 1, "cn0": 34.889801025390625, "sid": {"code": 0, "reserved": 0, "sat": 203}}, {"state": 1, "cn0": 37.44603729248047, "sid": {"code": 0, "reserved": 0, "sat": 208}}, {"state": 1, "cn0": 38.72849655151367, "sid": {"code": 0, "reserved": 0, "sat": 212}}, {"state": 1, "cn0": 41.983219146728516, "sid": {"code": 0, "reserved": 0, "sat": 217}}, {"state": 1, "cn0": 37.46448516845703, "sid": {"code": 0, "reserved": 0, "sat": 218}}, {"state": 1, "cn0": 38.44300079345703, "sid": {"code": 0, "reserved": 0, "sat": 220}}, {"state": 1, "cn0": 39.03423309326172, "sid": {"code": 0, "reserved": 0, "sat": 222}}, {"state": 1, "cn0": 42.89944839477539, "sid": {"code": 0, "reserved": 0, "sat": 225}}, {"state": 0, "cn0": -1.0, "sid": {"code": 0, "reserved": 0, "sat": 0}}, {"state": 0, "cn0": -1.0, "sid": {"code": 0, "reserved": 0, "sat": 0}}], "crc": 7956, "length": 99, "preamble": 85, "payload": "AcoAAAD6+RtCAcsAAAAojwtCAdAAAAC+yBVCAdQAAAD76RpCAdkAAADR7idCAdoAAACi2xVCAdwAAACixRlCAd4AAAAOIxxCAeEAAAAJmStCAAAAAAAAAIC/AAAAAAAAAIC/"}"#.as_bytes();

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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.89941177368164062e+01),
                    "incorrect value for states[0].cn0, expected 3.89941177368164062e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.48898010253906250e+01),
                    "incorrect value for states[1].cn0, expected 3.48898010253906250e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.74460372924804688e+01),
                    "incorrect value for states[2].cn0, expected 3.74460372924804688e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.87284965515136719e+01),
                    "incorrect value for states[3].cn0, expected 3.87284965515136719e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.19832191467285156e+01),
                    "incorrect value for states[4].cn0, expected 4.19832191467285156e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.74644851684570312e+01),
                    "incorrect value for states[5].cn0, expected 3.74644851684570312e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.84430007934570312e+01),
                    "incorrect value for states[6].cn0, expected 3.84430007934570312e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.90342330932617188e+01),
                    "incorrect value for states[7].cn0, expected 3.90342330932617188e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.28994483947753906e+01),
                    "incorrect value for states[8].cn0, expected 4.28994483947753906e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };
    }
    {
        let json_input = r#"{"sender": 55286, "msg_type": 19, "states": [{"state": 1, "cn0": 38.95457077026367, "sid": {"code": 0, "reserved": 0, "sat": 202}}, {"state": 1, "cn0": 35.813316345214844, "sid": {"code": 0, "reserved": 0, "sat": 203}}, {"state": 1, "cn0": 37.553924560546875, "sid": {"code": 0, "reserved": 0, "sat": 208}}, {"state": 1, "cn0": 38.88901901245117, "sid": {"code": 0, "reserved": 0, "sat": 212}}, {"state": 1, "cn0": 42.4013557434082, "sid": {"code": 0, "reserved": 0, "sat": 217}}, {"state": 1, "cn0": 37.63916015625, "sid": {"code": 0, "reserved": 0, "sat": 218}}, {"state": 1, "cn0": 37.919986724853516, "sid": {"code": 0, "reserved": 0, "sat": 220}}, {"state": 1, "cn0": 39.25254440307617, "sid": {"code": 0, "reserved": 0, "sat": 222}}, {"state": 1, "cn0": 42.59827423095703, "sid": {"code": 0, "reserved": 0, "sat": 225}}, {"state": 0, "cn0": -1.0, "sid": {"code": 0, "reserved": 0, "sat": 0}}, {"state": 0, "cn0": -1.0, "sid": {"code": 0, "reserved": 0, "sat": 0}}], "crc": 18409, "length": 99, "preamble": 85, "payload": "AcoAAAB70RtCAcsAAADWQA9CAdAAAAA4NxZCAdQAAABbjhtCAdkAAAD9milCAdoAAACAjhZCAdwAAAARrhdCAd4AAACbAh1CAeEAAACiZCpCAAAAAAAAAIC/AAAAAAAAAIC/"}"#.as_bytes();

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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.89545707702636719e+01),
                    "incorrect value for states[0].cn0, expected 3.89545707702636719e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.58133163452148438e+01),
                    "incorrect value for states[1].cn0, expected 3.58133163452148438e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.75539245605468750e+01),
                    "incorrect value for states[2].cn0, expected 3.75539245605468750e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.88890190124511719e+01),
                    "incorrect value for states[3].cn0, expected 3.88890190124511719e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.24013557434082031e+01),
                    "incorrect value for states[4].cn0, expected 4.24013557434082031e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.76391601562500000e+01),
                    "incorrect value for states[5].cn0, expected 3.76391601562500000e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.79199867248535156e+01),
                    "incorrect value for states[6].cn0, expected 3.79199867248535156e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.92525444030761719e+01),
                    "incorrect value for states[7].cn0, expected 3.92525444030761719e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.25982742309570312e+01),
                    "incorrect value for states[8].cn0, expected 4.25982742309570312e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };
    }
    {
        let json_input = r#"{"sender": 55286, "msg_type": 19, "states": [{"state": 1, "cn0": 39.369598388671875, "sid": {"code": 0, "reserved": 0, "sat": 202}}, {"state": 1, "cn0": 36.52173614501953, "sid": {"code": 0, "reserved": 0, "sat": 203}}, {"state": 1, "cn0": 38.15976333618164, "sid": {"code": 0, "reserved": 0, "sat": 208}}, {"state": 1, "cn0": 39.19989776611328, "sid": {"code": 0, "reserved": 0, "sat": 212}}, {"state": 1, "cn0": 41.55845642089844, "sid": {"code": 0, "reserved": 0, "sat": 217}}, {"state": 1, "cn0": 37.026981353759766, "sid": {"code": 0, "reserved": 0, "sat": 218}}, {"state": 1, "cn0": 38.1049690246582, "sid": {"code": 0, "reserved": 0, "sat": 220}}, {"state": 1, "cn0": 39.04584503173828, "sid": {"code": 0, "reserved": 0, "sat": 222}}, {"state": 1, "cn0": 42.37783432006836, "sid": {"code": 0, "reserved": 0, "sat": 225}}, {"state": 0, "cn0": -1.0, "sid": {"code": 0, "reserved": 0, "sat": 0}}, {"state": 0, "cn0": -1.0, "sid": {"code": 0, "reserved": 0, "sat": 0}}], "crc": 49481, "length": 99, "preamble": 85, "payload": "AcoAAAB4eh1CAcsAAABCFhJCAdAAAACZoxhCAdQAAACyzBxCAdkAAADcOyZCAdoAAAChGxRCAdwAAAB9axhCAd4AAADyLhxCAeEAAADngilCAAAAAAAAAIC/AAAAAAAAAIC/"}"#.as_bytes();

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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.93695983886718750e+01),
                    "incorrect value for states[0].cn0, expected 3.93695983886718750e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.65217361450195312e+01),
                    "incorrect value for states[1].cn0, expected 3.65217361450195312e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.81597633361816406e+01),
                    "incorrect value for states[2].cn0, expected 3.81597633361816406e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.91998977661132812e+01),
                    "incorrect value for states[3].cn0, expected 3.91998977661132812e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.15584564208984375e+01),
                    "incorrect value for states[4].cn0, expected 4.15584564208984375e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.70269813537597656e+01),
                    "incorrect value for states[5].cn0, expected 3.70269813537597656e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.81049690246582031e+01),
                    "incorrect value for states[6].cn0, expected 3.81049690246582031e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.90458450317382812e+01),
                    "incorrect value for states[7].cn0, expected 3.90458450317382812e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.23778343200683594e+01),
                    "incorrect value for states[8].cn0, expected 4.23778343200683594e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };
    }
    {
        let json_input = r#"{"sender": 55286, "msg_type": 19, "states": [{"state": 1, "cn0": 39.70351791381836, "sid": {"code": 0, "reserved": 0, "sat": 202}}, {"state": 1, "cn0": 36.52388381958008, "sid": {"code": 0, "reserved": 0, "sat": 203}}, {"state": 1, "cn0": 37.169708251953125, "sid": {"code": 0, "reserved": 0, "sat": 208}}, {"state": 1, "cn0": 38.81692886352539, "sid": {"code": 0, "reserved": 0, "sat": 212}}, {"state": 1, "cn0": 42.05073165893555, "sid": {"code": 0, "reserved": 0, "sat": 217}}, {"state": 1, "cn0": 37.807498931884766, "sid": {"code": 0, "reserved": 0, "sat": 218}}, {"state": 1, "cn0": 37.71632385253906, "sid": {"code": 0, "reserved": 0, "sat": 220}}, {"state": 1, "cn0": 38.5289192199707, "sid": {"code": 0, "reserved": 0, "sat": 222}}, {"state": 1, "cn0": 42.27101516723633, "sid": {"code": 0, "reserved": 0, "sat": 225}}, {"state": 0, "cn0": -1.0, "sid": {"code": 0, "reserved": 0, "sat": 0}}, {"state": 0, "cn0": -1.0, "sid": {"code": 0, "reserved": 0, "sat": 0}}], "crc": 12158, "length": 99, "preamble": 85, "payload": "AcoAAABn0B5CAcsAAAB1GBJCAdAAAADIrRRCAdQAAACJRBtCAdkAAADzMyhCAdoAAADhOhdCAdwAAACE3RZCAd4AAACdHRpCAeEAAACFFSlCAAAAAAAAAIC/AAAAAAAAAIC/"}"#.as_bytes();

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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.97035179138183594e+01),
                    "incorrect value for states[0].cn0, expected 3.97035179138183594e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.65238838195800781e+01),
                    "incorrect value for states[1].cn0, expected 3.65238838195800781e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.71697082519531250e+01),
                    "incorrect value for states[2].cn0, expected 3.71697082519531250e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.88169288635253906e+01),
                    "incorrect value for states[3].cn0, expected 3.88169288635253906e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.20507316589355469e+01),
                    "incorrect value for states[4].cn0, expected 4.20507316589355469e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.78074989318847656e+01),
                    "incorrect value for states[5].cn0, expected 3.78074989318847656e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.77163238525390625e+01),
                    "incorrect value for states[6].cn0, expected 3.77163238525390625e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.85289192199707031e+01),
                    "incorrect value for states[7].cn0, expected 3.85289192199707031e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.22710151672363281e+01),
                    "incorrect value for states[8].cn0, expected 4.22710151672363281e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_tracking_msg_tracking_state`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_tracking_msg_tracking_state() {
    {
        let mut payload = Cursor::new(vec![
            85, 65, 0, 55, 129, 252, 117, 184, 3, 102, 38, 106, 140, 141, 25, 4, 90, 195, 246, 108,
            75, 82, 137, 127, 45, 163, 32, 46, 187, 93, 153, 60, 201, 147, 23, 29, 5, 208, 181, 30,
            219, 69, 254, 136, 3, 121, 33, 98, 144, 215, 133, 182, 14, 56, 169, 77, 218, 62, 242,
            84, 171, 249, 152, 137, 131, 130, 193, 21, 42, 68, 253, 227, 216, 227, 24, 26, 210,
            179, 19, 15, 227, 255, 122, 75, 187, 200, 217, 48, 218, 122, 187, 238, 142, 149, 238,
            55, 251, 212, 128, 160, 194, 104, 113, 255, 141, 62, 43, 69, 245, 39, 100, 230, 108,
            56, 247, 68, 149, 143, 137, 101, 233, 70, 49, 165, 38, 110, 218, 230, 80, 213, 196,
            179, 139, 128, 15, 178, 196, 171, 8, 212, 97, 194, 83, 233, 79, 99, 55, 90, 31, 180, 5,
            25, 105, 186, 22, 224, 80, 111, 8, 48, 106, 166, 4, 48, 156, 49, 86, 19, 142, 146, 91,
            124, 115, 64, 28, 230, 115, 178, 190, 131, 16, 242, 105, 59, 182, 113, 192, 180, 48,
            179, 166, 31, 172, 211, 77, 228, 140, 49, 128, 77, 240, 194, 134, 194, 41, 58, 18, 53,
            129, 55, 91, 72, 134, 92, 33, 224, 157, 56, 186, 54, 224, 174, 82, 84, 148, 190, 236,
            54, 62, 67, 52, 215, 57, 254, 16, 133, 36, 174, 219, 172, 145, 17, 192, 179, 111, 97,
            207, 56, 208, 134, 180, 17, 43, 226, 255, 182, 140, 113, 141, 111,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingState(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingState(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x41,
                    "Incorrect message type, expected 0x41, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x8137,
                    "incorrect sender id, expected 0x8137, is {sender_id}"
                );
                assert_eq!(
                    msg.states[0].cn0, 102,
                    "incorrect value for states[0].cn0, expected 102, is {}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].fcn, 3,
                    "incorrect value for states[0].fcn, expected 3, is {}",
                    msg.states[0].fcn
                );
                assert_eq!(
                    msg.states[0].sid.code, 184,
                    "incorrect value for states[0].sid.code, expected 184, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.sat, 117,
                    "incorrect value for states[0].sid.sat, expected 117, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[1].cn0, 141,
                    "incorrect value for states[1].cn0, expected 141, is {}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].fcn, 140,
                    "incorrect value for states[1].fcn, expected 140, is {}",
                    msg.states[1].fcn
                );
                assert_eq!(
                    msg.states[1].sid.code, 106,
                    "incorrect value for states[1].sid.code, expected 106, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.sat, 38,
                    "incorrect value for states[1].sid.sat, expected 38, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[2].cn0, 195,
                    "incorrect value for states[2].cn0, expected 195, is {}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].fcn, 90,
                    "incorrect value for states[2].fcn, expected 90, is {}",
                    msg.states[2].fcn
                );
                assert_eq!(
                    msg.states[2].sid.code, 4,
                    "incorrect value for states[2].sid.code, expected 4, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.sat, 25,
                    "incorrect value for states[2].sid.sat, expected 25, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[3].cn0, 82,
                    "incorrect value for states[3].cn0, expected 82, is {}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].fcn, 75,
                    "incorrect value for states[3].fcn, expected 75, is {}",
                    msg.states[3].fcn
                );
                assert_eq!(
                    msg.states[3].sid.code, 108,
                    "incorrect value for states[3].sid.code, expected 108, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.sat, 246,
                    "incorrect value for states[3].sid.sat, expected 246, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[4].cn0, 163,
                    "incorrect value for states[4].cn0, expected 163, is {}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].fcn, 45,
                    "incorrect value for states[4].fcn, expected 45, is {}",
                    msg.states[4].fcn
                );
                assert_eq!(
                    msg.states[4].sid.code, 127,
                    "incorrect value for states[4].sid.code, expected 127, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.sat, 137,
                    "incorrect value for states[4].sid.sat, expected 137, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[5].cn0, 93,
                    "incorrect value for states[5].cn0, expected 93, is {}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].fcn, 187,
                    "incorrect value for states[5].fcn, expected 187, is {}",
                    msg.states[5].fcn
                );
                assert_eq!(
                    msg.states[5].sid.code, 46,
                    "incorrect value for states[5].sid.code, expected 46, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.sat, 32,
                    "incorrect value for states[5].sid.sat, expected 32, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[6].cn0, 147,
                    "incorrect value for states[6].cn0, expected 147, is {}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].fcn, 201,
                    "incorrect value for states[6].fcn, expected 201, is {}",
                    msg.states[6].fcn
                );
                assert_eq!(
                    msg.states[6].sid.code, 60,
                    "incorrect value for states[6].sid.code, expected 60, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.sat, 153,
                    "incorrect value for states[6].sid.sat, expected 153, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[7].cn0, 208,
                    "incorrect value for states[7].cn0, expected 208, is {}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].fcn, 5,
                    "incorrect value for states[7].fcn, expected 5, is {}",
                    msg.states[7].fcn
                );
                assert_eq!(
                    msg.states[7].sid.code, 29,
                    "incorrect value for states[7].sid.code, expected 29, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.sat, 23,
                    "incorrect value for states[7].sid.sat, expected 23, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[8].cn0, 69,
                    "incorrect value for states[8].cn0, expected 69, is {}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].fcn, 219,
                    "incorrect value for states[8].fcn, expected 219, is {}",
                    msg.states[8].fcn
                );
                assert_eq!(
                    msg.states[8].sid.code, 30,
                    "incorrect value for states[8].sid.code, expected 30, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.sat, 181,
                    "incorrect value for states[8].sid.sat, expected 181, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[9].cn0, 121,
                    "incorrect value for states[9].cn0, expected 121, is {}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].fcn, 3,
                    "incorrect value for states[9].fcn, expected 3, is {}",
                    msg.states[9].fcn
                );
                assert_eq!(
                    msg.states[9].sid.code, 136,
                    "incorrect value for states[9].sid.code, expected 136, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.sat, 254,
                    "incorrect value for states[9].sid.sat, expected 254, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[10].cn0, 215,
                    "incorrect value for states[10].cn0, expected 215, is {}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].fcn, 144,
                    "incorrect value for states[10].fcn, expected 144, is {}",
                    msg.states[10].fcn
                );
                assert_eq!(
                    msg.states[10].sid.code, 98,
                    "incorrect value for states[10].sid.code, expected 98, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.sat, 33,
                    "incorrect value for states[10].sid.sat, expected 33, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[11].cn0, 56,
                    "incorrect value for states[11].cn0, expected 56, is {}",
                    msg.states[11].cn0
                );
                assert_eq!(
                    msg.states[11].fcn, 14,
                    "incorrect value for states[11].fcn, expected 14, is {}",
                    msg.states[11].fcn
                );
                assert_eq!(
                    msg.states[11].sid.code, 182,
                    "incorrect value for states[11].sid.code, expected 182, is {}",
                    msg.states[11].sid.code
                );
                assert_eq!(
                    msg.states[11].sid.sat, 133,
                    "incorrect value for states[11].sid.sat, expected 133, is {}",
                    msg.states[11].sid.sat
                );
                assert_eq!(
                    msg.states[12].cn0, 62,
                    "incorrect value for states[12].cn0, expected 62, is {}",
                    msg.states[12].cn0
                );
                assert_eq!(
                    msg.states[12].fcn, 218,
                    "incorrect value for states[12].fcn, expected 218, is {}",
                    msg.states[12].fcn
                );
                assert_eq!(
                    msg.states[12].sid.code, 77,
                    "incorrect value for states[12].sid.code, expected 77, is {}",
                    msg.states[12].sid.code
                );
                assert_eq!(
                    msg.states[12].sid.sat, 169,
                    "incorrect value for states[12].sid.sat, expected 169, is {}",
                    msg.states[12].sid.sat
                );
                assert_eq!(
                    msg.states[13].cn0, 249,
                    "incorrect value for states[13].cn0, expected 249, is {}",
                    msg.states[13].cn0
                );
                assert_eq!(
                    msg.states[13].fcn, 171,
                    "incorrect value for states[13].fcn, expected 171, is {}",
                    msg.states[13].fcn
                );
                assert_eq!(
                    msg.states[13].sid.code, 84,
                    "incorrect value for states[13].sid.code, expected 84, is {}",
                    msg.states[13].sid.code
                );
                assert_eq!(
                    msg.states[13].sid.sat, 242,
                    "incorrect value for states[13].sid.sat, expected 242, is {}",
                    msg.states[13].sid.sat
                );
                assert_eq!(
                    msg.states[14].cn0, 130,
                    "incorrect value for states[14].cn0, expected 130, is {}",
                    msg.states[14].cn0
                );
                assert_eq!(
                    msg.states[14].fcn, 131,
                    "incorrect value for states[14].fcn, expected 131, is {}",
                    msg.states[14].fcn
                );
                assert_eq!(
                    msg.states[14].sid.code, 137,
                    "incorrect value for states[14].sid.code, expected 137, is {}",
                    msg.states[14].sid.code
                );
                assert_eq!(
                    msg.states[14].sid.sat, 152,
                    "incorrect value for states[14].sid.sat, expected 152, is {}",
                    msg.states[14].sid.sat
                );
                assert_eq!(
                    msg.states[15].cn0, 68,
                    "incorrect value for states[15].cn0, expected 68, is {}",
                    msg.states[15].cn0
                );
                assert_eq!(
                    msg.states[15].fcn, 42,
                    "incorrect value for states[15].fcn, expected 42, is {}",
                    msg.states[15].fcn
                );
                assert_eq!(
                    msg.states[15].sid.code, 21,
                    "incorrect value for states[15].sid.code, expected 21, is {}",
                    msg.states[15].sid.code
                );
                assert_eq!(
                    msg.states[15].sid.sat, 193,
                    "incorrect value for states[15].sid.sat, expected 193, is {}",
                    msg.states[15].sid.sat
                );
                assert_eq!(
                    msg.states[16].cn0, 227,
                    "incorrect value for states[16].cn0, expected 227, is {}",
                    msg.states[16].cn0
                );
                assert_eq!(
                    msg.states[16].fcn, 216,
                    "incorrect value for states[16].fcn, expected 216, is {}",
                    msg.states[16].fcn
                );
                assert_eq!(
                    msg.states[16].sid.code, 227,
                    "incorrect value for states[16].sid.code, expected 227, is {}",
                    msg.states[16].sid.code
                );
                assert_eq!(
                    msg.states[16].sid.sat, 253,
                    "incorrect value for states[16].sid.sat, expected 253, is {}",
                    msg.states[16].sid.sat
                );
                assert_eq!(
                    msg.states[17].cn0, 179,
                    "incorrect value for states[17].cn0, expected 179, is {}",
                    msg.states[17].cn0
                );
                assert_eq!(
                    msg.states[17].fcn, 210,
                    "incorrect value for states[17].fcn, expected 210, is {}",
                    msg.states[17].fcn
                );
                assert_eq!(
                    msg.states[17].sid.code, 26,
                    "incorrect value for states[17].sid.code, expected 26, is {}",
                    msg.states[17].sid.code
                );
                assert_eq!(
                    msg.states[17].sid.sat, 24,
                    "incorrect value for states[17].sid.sat, expected 24, is {}",
                    msg.states[17].sid.sat
                );
                assert_eq!(
                    msg.states[18].cn0, 255,
                    "incorrect value for states[18].cn0, expected 255, is {}",
                    msg.states[18].cn0
                );
                assert_eq!(
                    msg.states[18].fcn, 227,
                    "incorrect value for states[18].fcn, expected 227, is {}",
                    msg.states[18].fcn
                );
                assert_eq!(
                    msg.states[18].sid.code, 15,
                    "incorrect value for states[18].sid.code, expected 15, is {}",
                    msg.states[18].sid.code
                );
                assert_eq!(
                    msg.states[18].sid.sat, 19,
                    "incorrect value for states[18].sid.sat, expected 19, is {}",
                    msg.states[18].sid.sat
                );
                assert_eq!(
                    msg.states[19].cn0, 200,
                    "incorrect value for states[19].cn0, expected 200, is {}",
                    msg.states[19].cn0
                );
                assert_eq!(
                    msg.states[19].fcn, 187,
                    "incorrect value for states[19].fcn, expected 187, is {}",
                    msg.states[19].fcn
                );
                assert_eq!(
                    msg.states[19].sid.code, 75,
                    "incorrect value for states[19].sid.code, expected 75, is {}",
                    msg.states[19].sid.code
                );
                assert_eq!(
                    msg.states[19].sid.sat, 122,
                    "incorrect value for states[19].sid.sat, expected 122, is {}",
                    msg.states[19].sid.sat
                );
                assert_eq!(
                    msg.states[20].cn0, 122,
                    "incorrect value for states[20].cn0, expected 122, is {}",
                    msg.states[20].cn0
                );
                assert_eq!(
                    msg.states[20].fcn, 218,
                    "incorrect value for states[20].fcn, expected 218, is {}",
                    msg.states[20].fcn
                );
                assert_eq!(
                    msg.states[20].sid.code, 48,
                    "incorrect value for states[20].sid.code, expected 48, is {}",
                    msg.states[20].sid.code
                );
                assert_eq!(
                    msg.states[20].sid.sat, 217,
                    "incorrect value for states[20].sid.sat, expected 217, is {}",
                    msg.states[20].sid.sat
                );
                assert_eq!(
                    msg.states[21].cn0, 149,
                    "incorrect value for states[21].cn0, expected 149, is {}",
                    msg.states[21].cn0
                );
                assert_eq!(
                    msg.states[21].fcn, 142,
                    "incorrect value for states[21].fcn, expected 142, is {}",
                    msg.states[21].fcn
                );
                assert_eq!(
                    msg.states[21].sid.code, 238,
                    "incorrect value for states[21].sid.code, expected 238, is {}",
                    msg.states[21].sid.code
                );
                assert_eq!(
                    msg.states[21].sid.sat, 187,
                    "incorrect value for states[21].sid.sat, expected 187, is {}",
                    msg.states[21].sid.sat
                );
                assert_eq!(
                    msg.states[22].cn0, 212,
                    "incorrect value for states[22].cn0, expected 212, is {}",
                    msg.states[22].cn0
                );
                assert_eq!(
                    msg.states[22].fcn, 251,
                    "incorrect value for states[22].fcn, expected 251, is {}",
                    msg.states[22].fcn
                );
                assert_eq!(
                    msg.states[22].sid.code, 55,
                    "incorrect value for states[22].sid.code, expected 55, is {}",
                    msg.states[22].sid.code
                );
                assert_eq!(
                    msg.states[22].sid.sat, 238,
                    "incorrect value for states[22].sid.sat, expected 238, is {}",
                    msg.states[22].sid.sat
                );
                assert_eq!(
                    msg.states[23].cn0, 104,
                    "incorrect value for states[23].cn0, expected 104, is {}",
                    msg.states[23].cn0
                );
                assert_eq!(
                    msg.states[23].fcn, 194,
                    "incorrect value for states[23].fcn, expected 194, is {}",
                    msg.states[23].fcn
                );
                assert_eq!(
                    msg.states[23].sid.code, 160,
                    "incorrect value for states[23].sid.code, expected 160, is {}",
                    msg.states[23].sid.code
                );
                assert_eq!(
                    msg.states[23].sid.sat, 128,
                    "incorrect value for states[23].sid.sat, expected 128, is {}",
                    msg.states[23].sid.sat
                );
                assert_eq!(
                    msg.states[24].cn0, 62,
                    "incorrect value for states[24].cn0, expected 62, is {}",
                    msg.states[24].cn0
                );
                assert_eq!(
                    msg.states[24].fcn, 141,
                    "incorrect value for states[24].fcn, expected 141, is {}",
                    msg.states[24].fcn
                );
                assert_eq!(
                    msg.states[24].sid.code, 255,
                    "incorrect value for states[24].sid.code, expected 255, is {}",
                    msg.states[24].sid.code
                );
                assert_eq!(
                    msg.states[24].sid.sat, 113,
                    "incorrect value for states[24].sid.sat, expected 113, is {}",
                    msg.states[24].sid.sat
                );
                assert_eq!(
                    msg.states[25].cn0, 39,
                    "incorrect value for states[25].cn0, expected 39, is {}",
                    msg.states[25].cn0
                );
                assert_eq!(
                    msg.states[25].fcn, 245,
                    "incorrect value for states[25].fcn, expected 245, is {}",
                    msg.states[25].fcn
                );
                assert_eq!(
                    msg.states[25].sid.code, 69,
                    "incorrect value for states[25].sid.code, expected 69, is {}",
                    msg.states[25].sid.code
                );
                assert_eq!(
                    msg.states[25].sid.sat, 43,
                    "incorrect value for states[25].sid.sat, expected 43, is {}",
                    msg.states[25].sid.sat
                );
                assert_eq!(
                    msg.states[26].cn0, 56,
                    "incorrect value for states[26].cn0, expected 56, is {}",
                    msg.states[26].cn0
                );
                assert_eq!(
                    msg.states[26].fcn, 108,
                    "incorrect value for states[26].fcn, expected 108, is {}",
                    msg.states[26].fcn
                );
                assert_eq!(
                    msg.states[26].sid.code, 230,
                    "incorrect value for states[26].sid.code, expected 230, is {}",
                    msg.states[26].sid.code
                );
                assert_eq!(
                    msg.states[26].sid.sat, 100,
                    "incorrect value for states[26].sid.sat, expected 100, is {}",
                    msg.states[26].sid.sat
                );
                assert_eq!(
                    msg.states[27].cn0, 143,
                    "incorrect value for states[27].cn0, expected 143, is {}",
                    msg.states[27].cn0
                );
                assert_eq!(
                    msg.states[27].fcn, 149,
                    "incorrect value for states[27].fcn, expected 149, is {}",
                    msg.states[27].fcn
                );
                assert_eq!(
                    msg.states[27].sid.code, 68,
                    "incorrect value for states[27].sid.code, expected 68, is {}",
                    msg.states[27].sid.code
                );
                assert_eq!(
                    msg.states[27].sid.sat, 247,
                    "incorrect value for states[27].sid.sat, expected 247, is {}",
                    msg.states[27].sid.sat
                );
                assert_eq!(
                    msg.states[28].cn0, 70,
                    "incorrect value for states[28].cn0, expected 70, is {}",
                    msg.states[28].cn0
                );
                assert_eq!(
                    msg.states[28].fcn, 233,
                    "incorrect value for states[28].fcn, expected 233, is {}",
                    msg.states[28].fcn
                );
                assert_eq!(
                    msg.states[28].sid.code, 101,
                    "incorrect value for states[28].sid.code, expected 101, is {}",
                    msg.states[28].sid.code
                );
                assert_eq!(
                    msg.states[28].sid.sat, 137,
                    "incorrect value for states[28].sid.sat, expected 137, is {}",
                    msg.states[28].sid.sat
                );
                assert_eq!(
                    msg.states[29].cn0, 110,
                    "incorrect value for states[29].cn0, expected 110, is {}",
                    msg.states[29].cn0
                );
                assert_eq!(
                    msg.states[29].fcn, 38,
                    "incorrect value for states[29].fcn, expected 38, is {}",
                    msg.states[29].fcn
                );
                assert_eq!(
                    msg.states[29].sid.code, 165,
                    "incorrect value for states[29].sid.code, expected 165, is {}",
                    msg.states[29].sid.code
                );
                assert_eq!(
                    msg.states[29].sid.sat, 49,
                    "incorrect value for states[29].sid.sat, expected 49, is {}",
                    msg.states[29].sid.sat
                );
                assert_eq!(
                    msg.states[30].cn0, 213,
                    "incorrect value for states[30].cn0, expected 213, is {}",
                    msg.states[30].cn0
                );
                assert_eq!(
                    msg.states[30].fcn, 80,
                    "incorrect value for states[30].fcn, expected 80, is {}",
                    msg.states[30].fcn
                );
                assert_eq!(
                    msg.states[30].sid.code, 230,
                    "incorrect value for states[30].sid.code, expected 230, is {}",
                    msg.states[30].sid.code
                );
                assert_eq!(
                    msg.states[30].sid.sat, 218,
                    "incorrect value for states[30].sid.sat, expected 218, is {}",
                    msg.states[30].sid.sat
                );
                assert_eq!(
                    msg.states[31].cn0, 128,
                    "incorrect value for states[31].cn0, expected 128, is {}",
                    msg.states[31].cn0
                );
                assert_eq!(
                    msg.states[31].fcn, 139,
                    "incorrect value for states[31].fcn, expected 139, is {}",
                    msg.states[31].fcn
                );
                assert_eq!(
                    msg.states[31].sid.code, 179,
                    "incorrect value for states[31].sid.code, expected 179, is {}",
                    msg.states[31].sid.code
                );
                assert_eq!(
                    msg.states[31].sid.sat, 196,
                    "incorrect value for states[31].sid.sat, expected 196, is {}",
                    msg.states[31].sid.sat
                );
                assert_eq!(
                    msg.states[32].cn0, 171,
                    "incorrect value for states[32].cn0, expected 171, is {}",
                    msg.states[32].cn0
                );
                assert_eq!(
                    msg.states[32].fcn, 196,
                    "incorrect value for states[32].fcn, expected 196, is {}",
                    msg.states[32].fcn
                );
                assert_eq!(
                    msg.states[32].sid.code, 178,
                    "incorrect value for states[32].sid.code, expected 178, is {}",
                    msg.states[32].sid.code
                );
                assert_eq!(
                    msg.states[32].sid.sat, 15,
                    "incorrect value for states[32].sid.sat, expected 15, is {}",
                    msg.states[32].sid.sat
                );
                assert_eq!(
                    msg.states[33].cn0, 194,
                    "incorrect value for states[33].cn0, expected 194, is {}",
                    msg.states[33].cn0
                );
                assert_eq!(
                    msg.states[33].fcn, 97,
                    "incorrect value for states[33].fcn, expected 97, is {}",
                    msg.states[33].fcn
                );
                assert_eq!(
                    msg.states[33].sid.code, 212,
                    "incorrect value for states[33].sid.code, expected 212, is {}",
                    msg.states[33].sid.code
                );
                assert_eq!(
                    msg.states[33].sid.sat, 8,
                    "incorrect value for states[33].sid.sat, expected 8, is {}",
                    msg.states[33].sid.sat
                );
                assert_eq!(
                    msg.states[34].cn0, 99,
                    "incorrect value for states[34].cn0, expected 99, is {}",
                    msg.states[34].cn0
                );
                assert_eq!(
                    msg.states[34].fcn, 79,
                    "incorrect value for states[34].fcn, expected 79, is {}",
                    msg.states[34].fcn
                );
                assert_eq!(
                    msg.states[34].sid.code, 233,
                    "incorrect value for states[34].sid.code, expected 233, is {}",
                    msg.states[34].sid.code
                );
                assert_eq!(
                    msg.states[34].sid.sat, 83,
                    "incorrect value for states[34].sid.sat, expected 83, is {}",
                    msg.states[34].sid.sat
                );
                assert_eq!(
                    msg.states[35].cn0, 180,
                    "incorrect value for states[35].cn0, expected 180, is {}",
                    msg.states[35].cn0
                );
                assert_eq!(
                    msg.states[35].fcn, 31,
                    "incorrect value for states[35].fcn, expected 31, is {}",
                    msg.states[35].fcn
                );
                assert_eq!(
                    msg.states[35].sid.code, 90,
                    "incorrect value for states[35].sid.code, expected 90, is {}",
                    msg.states[35].sid.code
                );
                assert_eq!(
                    msg.states[35].sid.sat, 55,
                    "incorrect value for states[35].sid.sat, expected 55, is {}",
                    msg.states[35].sid.sat
                );
                assert_eq!(
                    msg.states[36].cn0, 186,
                    "incorrect value for states[36].cn0, expected 186, is {}",
                    msg.states[36].cn0
                );
                assert_eq!(
                    msg.states[36].fcn, 105,
                    "incorrect value for states[36].fcn, expected 105, is {}",
                    msg.states[36].fcn
                );
                assert_eq!(
                    msg.states[36].sid.code, 25,
                    "incorrect value for states[36].sid.code, expected 25, is {}",
                    msg.states[36].sid.code
                );
                assert_eq!(
                    msg.states[36].sid.sat, 5,
                    "incorrect value for states[36].sid.sat, expected 5, is {}",
                    msg.states[36].sid.sat
                );
                assert_eq!(
                    msg.states[37].cn0, 111,
                    "incorrect value for states[37].cn0, expected 111, is {}",
                    msg.states[37].cn0
                );
                assert_eq!(
                    msg.states[37].fcn, 80,
                    "incorrect value for states[37].fcn, expected 80, is {}",
                    msg.states[37].fcn
                );
                assert_eq!(
                    msg.states[37].sid.code, 224,
                    "incorrect value for states[37].sid.code, expected 224, is {}",
                    msg.states[37].sid.code
                );
                assert_eq!(
                    msg.states[37].sid.sat, 22,
                    "incorrect value for states[37].sid.sat, expected 22, is {}",
                    msg.states[37].sid.sat
                );
                assert_eq!(
                    msg.states[38].cn0, 166,
                    "incorrect value for states[38].cn0, expected 166, is {}",
                    msg.states[38].cn0
                );
                assert_eq!(
                    msg.states[38].fcn, 106,
                    "incorrect value for states[38].fcn, expected 106, is {}",
                    msg.states[38].fcn
                );
                assert_eq!(
                    msg.states[38].sid.code, 48,
                    "incorrect value for states[38].sid.code, expected 48, is {}",
                    msg.states[38].sid.code
                );
                assert_eq!(
                    msg.states[38].sid.sat, 8,
                    "incorrect value for states[38].sid.sat, expected 8, is {}",
                    msg.states[38].sid.sat
                );
                assert_eq!(
                    msg.states[39].cn0, 49,
                    "incorrect value for states[39].cn0, expected 49, is {}",
                    msg.states[39].cn0
                );
                assert_eq!(
                    msg.states[39].fcn, 156,
                    "incorrect value for states[39].fcn, expected 156, is {}",
                    msg.states[39].fcn
                );
                assert_eq!(
                    msg.states[39].sid.code, 48,
                    "incorrect value for states[39].sid.code, expected 48, is {}",
                    msg.states[39].sid.code
                );
                assert_eq!(
                    msg.states[39].sid.sat, 4,
                    "incorrect value for states[39].sid.sat, expected 4, is {}",
                    msg.states[39].sid.sat
                );
                assert_eq!(
                    msg.states[40].cn0, 146,
                    "incorrect value for states[40].cn0, expected 146, is {}",
                    msg.states[40].cn0
                );
                assert_eq!(
                    msg.states[40].fcn, 142,
                    "incorrect value for states[40].fcn, expected 142, is {}",
                    msg.states[40].fcn
                );
                assert_eq!(
                    msg.states[40].sid.code, 19,
                    "incorrect value for states[40].sid.code, expected 19, is {}",
                    msg.states[40].sid.code
                );
                assert_eq!(
                    msg.states[40].sid.sat, 86,
                    "incorrect value for states[40].sid.sat, expected 86, is {}",
                    msg.states[40].sid.sat
                );
                assert_eq!(
                    msg.states[41].cn0, 64,
                    "incorrect value for states[41].cn0, expected 64, is {}",
                    msg.states[41].cn0
                );
                assert_eq!(
                    msg.states[41].fcn, 115,
                    "incorrect value for states[41].fcn, expected 115, is {}",
                    msg.states[41].fcn
                );
                assert_eq!(
                    msg.states[41].sid.code, 124,
                    "incorrect value for states[41].sid.code, expected 124, is {}",
                    msg.states[41].sid.code
                );
                assert_eq!(
                    msg.states[41].sid.sat, 91,
                    "incorrect value for states[41].sid.sat, expected 91, is {}",
                    msg.states[41].sid.sat
                );
                assert_eq!(
                    msg.states[42].cn0, 178,
                    "incorrect value for states[42].cn0, expected 178, is {}",
                    msg.states[42].cn0
                );
                assert_eq!(
                    msg.states[42].fcn, 115,
                    "incorrect value for states[42].fcn, expected 115, is {}",
                    msg.states[42].fcn
                );
                assert_eq!(
                    msg.states[42].sid.code, 230,
                    "incorrect value for states[42].sid.code, expected 230, is {}",
                    msg.states[42].sid.code
                );
                assert_eq!(
                    msg.states[42].sid.sat, 28,
                    "incorrect value for states[42].sid.sat, expected 28, is {}",
                    msg.states[42].sid.sat
                );
                assert_eq!(
                    msg.states[43].cn0, 242,
                    "incorrect value for states[43].cn0, expected 242, is {}",
                    msg.states[43].cn0
                );
                assert_eq!(
                    msg.states[43].fcn, 16,
                    "incorrect value for states[43].fcn, expected 16, is {}",
                    msg.states[43].fcn
                );
                assert_eq!(
                    msg.states[43].sid.code, 131,
                    "incorrect value for states[43].sid.code, expected 131, is {}",
                    msg.states[43].sid.code
                );
                assert_eq!(
                    msg.states[43].sid.sat, 190,
                    "incorrect value for states[43].sid.sat, expected 190, is {}",
                    msg.states[43].sid.sat
                );
                assert_eq!(
                    msg.states[44].cn0, 113,
                    "incorrect value for states[44].cn0, expected 113, is {}",
                    msg.states[44].cn0
                );
                assert_eq!(
                    msg.states[44].fcn, 182,
                    "incorrect value for states[44].fcn, expected 182, is {}",
                    msg.states[44].fcn
                );
                assert_eq!(
                    msg.states[44].sid.code, 59,
                    "incorrect value for states[44].sid.code, expected 59, is {}",
                    msg.states[44].sid.code
                );
                assert_eq!(
                    msg.states[44].sid.sat, 105,
                    "incorrect value for states[44].sid.sat, expected 105, is {}",
                    msg.states[44].sid.sat
                );
                assert_eq!(
                    msg.states[45].cn0, 179,
                    "incorrect value for states[45].cn0, expected 179, is {}",
                    msg.states[45].cn0
                );
                assert_eq!(
                    msg.states[45].fcn, 48,
                    "incorrect value for states[45].fcn, expected 48, is {}",
                    msg.states[45].fcn
                );
                assert_eq!(
                    msg.states[45].sid.code, 180,
                    "incorrect value for states[45].sid.code, expected 180, is {}",
                    msg.states[45].sid.code
                );
                assert_eq!(
                    msg.states[45].sid.sat, 192,
                    "incorrect value for states[45].sid.sat, expected 192, is {}",
                    msg.states[45].sid.sat
                );
                assert_eq!(
                    msg.states[46].cn0, 211,
                    "incorrect value for states[46].cn0, expected 211, is {}",
                    msg.states[46].cn0
                );
                assert_eq!(
                    msg.states[46].fcn, 172,
                    "incorrect value for states[46].fcn, expected 172, is {}",
                    msg.states[46].fcn
                );
                assert_eq!(
                    msg.states[46].sid.code, 31,
                    "incorrect value for states[46].sid.code, expected 31, is {}",
                    msg.states[46].sid.code
                );
                assert_eq!(
                    msg.states[46].sid.sat, 166,
                    "incorrect value for states[46].sid.sat, expected 166, is {}",
                    msg.states[46].sid.sat
                );
                assert_eq!(
                    msg.states[47].cn0, 49,
                    "incorrect value for states[47].cn0, expected 49, is {}",
                    msg.states[47].cn0
                );
                assert_eq!(
                    msg.states[47].fcn, 140,
                    "incorrect value for states[47].fcn, expected 140, is {}",
                    msg.states[47].fcn
                );
                assert_eq!(
                    msg.states[47].sid.code, 228,
                    "incorrect value for states[47].sid.code, expected 228, is {}",
                    msg.states[47].sid.code
                );
                assert_eq!(
                    msg.states[47].sid.sat, 77,
                    "incorrect value for states[47].sid.sat, expected 77, is {}",
                    msg.states[47].sid.sat
                );
                assert_eq!(
                    msg.states[48].cn0, 194,
                    "incorrect value for states[48].cn0, expected 194, is {}",
                    msg.states[48].cn0
                );
                assert_eq!(
                    msg.states[48].fcn, 240,
                    "incorrect value for states[48].fcn, expected 240, is {}",
                    msg.states[48].fcn
                );
                assert_eq!(
                    msg.states[48].sid.code, 77,
                    "incorrect value for states[48].sid.code, expected 77, is {}",
                    msg.states[48].sid.code
                );
                assert_eq!(
                    msg.states[48].sid.sat, 128,
                    "incorrect value for states[48].sid.sat, expected 128, is {}",
                    msg.states[48].sid.sat
                );
                assert_eq!(
                    msg.states[49].cn0, 58,
                    "incorrect value for states[49].cn0, expected 58, is {}",
                    msg.states[49].cn0
                );
                assert_eq!(
                    msg.states[49].fcn, 41,
                    "incorrect value for states[49].fcn, expected 41, is {}",
                    msg.states[49].fcn
                );
                assert_eq!(
                    msg.states[49].sid.code, 194,
                    "incorrect value for states[49].sid.code, expected 194, is {}",
                    msg.states[49].sid.code
                );
                assert_eq!(
                    msg.states[49].sid.sat, 134,
                    "incorrect value for states[49].sid.sat, expected 134, is {}",
                    msg.states[49].sid.sat
                );
                assert_eq!(
                    msg.states[50].cn0, 55,
                    "incorrect value for states[50].cn0, expected 55, is {}",
                    msg.states[50].cn0
                );
                assert_eq!(
                    msg.states[50].fcn, 129,
                    "incorrect value for states[50].fcn, expected 129, is {}",
                    msg.states[50].fcn
                );
                assert_eq!(
                    msg.states[50].sid.code, 53,
                    "incorrect value for states[50].sid.code, expected 53, is {}",
                    msg.states[50].sid.code
                );
                assert_eq!(
                    msg.states[50].sid.sat, 18,
                    "incorrect value for states[50].sid.sat, expected 18, is {}",
                    msg.states[50].sid.sat
                );
                assert_eq!(
                    msg.states[51].cn0, 92,
                    "incorrect value for states[51].cn0, expected 92, is {}",
                    msg.states[51].cn0
                );
                assert_eq!(
                    msg.states[51].fcn, 134,
                    "incorrect value for states[51].fcn, expected 134, is {}",
                    msg.states[51].fcn
                );
                assert_eq!(
                    msg.states[51].sid.code, 72,
                    "incorrect value for states[51].sid.code, expected 72, is {}",
                    msg.states[51].sid.code
                );
                assert_eq!(
                    msg.states[51].sid.sat, 91,
                    "incorrect value for states[51].sid.sat, expected 91, is {}",
                    msg.states[51].sid.sat
                );
                assert_eq!(
                    msg.states[52].cn0, 56,
                    "incorrect value for states[52].cn0, expected 56, is {}",
                    msg.states[52].cn0
                );
                assert_eq!(
                    msg.states[52].fcn, 157,
                    "incorrect value for states[52].fcn, expected 157, is {}",
                    msg.states[52].fcn
                );
                assert_eq!(
                    msg.states[52].sid.code, 224,
                    "incorrect value for states[52].sid.code, expected 224, is {}",
                    msg.states[52].sid.code
                );
                assert_eq!(
                    msg.states[52].sid.sat, 33,
                    "incorrect value for states[52].sid.sat, expected 33, is {}",
                    msg.states[52].sid.sat
                );
                assert_eq!(
                    msg.states[53].cn0, 174,
                    "incorrect value for states[53].cn0, expected 174, is {}",
                    msg.states[53].cn0
                );
                assert_eq!(
                    msg.states[53].fcn, 224,
                    "incorrect value for states[53].fcn, expected 224, is {}",
                    msg.states[53].fcn
                );
                assert_eq!(
                    msg.states[53].sid.code, 54,
                    "incorrect value for states[53].sid.code, expected 54, is {}",
                    msg.states[53].sid.code
                );
                assert_eq!(
                    msg.states[53].sid.sat, 186,
                    "incorrect value for states[53].sid.sat, expected 186, is {}",
                    msg.states[53].sid.sat
                );
                assert_eq!(
                    msg.states[54].cn0, 190,
                    "incorrect value for states[54].cn0, expected 190, is {}",
                    msg.states[54].cn0
                );
                assert_eq!(
                    msg.states[54].fcn, 148,
                    "incorrect value for states[54].fcn, expected 148, is {}",
                    msg.states[54].fcn
                );
                assert_eq!(
                    msg.states[54].sid.code, 84,
                    "incorrect value for states[54].sid.code, expected 84, is {}",
                    msg.states[54].sid.code
                );
                assert_eq!(
                    msg.states[54].sid.sat, 82,
                    "incorrect value for states[54].sid.sat, expected 82, is {}",
                    msg.states[54].sid.sat
                );
                assert_eq!(
                    msg.states[55].cn0, 67,
                    "incorrect value for states[55].cn0, expected 67, is {}",
                    msg.states[55].cn0
                );
                assert_eq!(
                    msg.states[55].fcn, 62,
                    "incorrect value for states[55].fcn, expected 62, is {}",
                    msg.states[55].fcn
                );
                assert_eq!(
                    msg.states[55].sid.code, 54,
                    "incorrect value for states[55].sid.code, expected 54, is {}",
                    msg.states[55].sid.code
                );
                assert_eq!(
                    msg.states[55].sid.sat, 236,
                    "incorrect value for states[55].sid.sat, expected 236, is {}",
                    msg.states[55].sid.sat
                );
                assert_eq!(
                    msg.states[56].cn0, 254,
                    "incorrect value for states[56].cn0, expected 254, is {}",
                    msg.states[56].cn0
                );
                assert_eq!(
                    msg.states[56].fcn, 57,
                    "incorrect value for states[56].fcn, expected 57, is {}",
                    msg.states[56].fcn
                );
                assert_eq!(
                    msg.states[56].sid.code, 215,
                    "incorrect value for states[56].sid.code, expected 215, is {}",
                    msg.states[56].sid.code
                );
                assert_eq!(
                    msg.states[56].sid.sat, 52,
                    "incorrect value for states[56].sid.sat, expected 52, is {}",
                    msg.states[56].sid.sat
                );
                assert_eq!(
                    msg.states[57].cn0, 174,
                    "incorrect value for states[57].cn0, expected 174, is {}",
                    msg.states[57].cn0
                );
                assert_eq!(
                    msg.states[57].fcn, 36,
                    "incorrect value for states[57].fcn, expected 36, is {}",
                    msg.states[57].fcn
                );
                assert_eq!(
                    msg.states[57].sid.code, 133,
                    "incorrect value for states[57].sid.code, expected 133, is {}",
                    msg.states[57].sid.code
                );
                assert_eq!(
                    msg.states[57].sid.sat, 16,
                    "incorrect value for states[57].sid.sat, expected 16, is {}",
                    msg.states[57].sid.sat
                );
                assert_eq!(
                    msg.states[58].cn0, 17,
                    "incorrect value for states[58].cn0, expected 17, is {}",
                    msg.states[58].cn0
                );
                assert_eq!(
                    msg.states[58].fcn, 145,
                    "incorrect value for states[58].fcn, expected 145, is {}",
                    msg.states[58].fcn
                );
                assert_eq!(
                    msg.states[58].sid.code, 172,
                    "incorrect value for states[58].sid.code, expected 172, is {}",
                    msg.states[58].sid.code
                );
                assert_eq!(
                    msg.states[58].sid.sat, 219,
                    "incorrect value for states[58].sid.sat, expected 219, is {}",
                    msg.states[58].sid.sat
                );
                assert_eq!(
                    msg.states[59].cn0, 97,
                    "incorrect value for states[59].cn0, expected 97, is {}",
                    msg.states[59].cn0
                );
                assert_eq!(
                    msg.states[59].fcn, 111,
                    "incorrect value for states[59].fcn, expected 111, is {}",
                    msg.states[59].fcn
                );
                assert_eq!(
                    msg.states[59].sid.code, 179,
                    "incorrect value for states[59].sid.code, expected 179, is {}",
                    msg.states[59].sid.code
                );
                assert_eq!(
                    msg.states[59].sid.sat, 192,
                    "incorrect value for states[59].sid.sat, expected 192, is {}",
                    msg.states[59].sid.sat
                );
                assert_eq!(
                    msg.states[60].cn0, 134,
                    "incorrect value for states[60].cn0, expected 134, is {}",
                    msg.states[60].cn0
                );
                assert_eq!(
                    msg.states[60].fcn, 208,
                    "incorrect value for states[60].fcn, expected 208, is {}",
                    msg.states[60].fcn
                );
                assert_eq!(
                    msg.states[60].sid.code, 56,
                    "incorrect value for states[60].sid.code, expected 56, is {}",
                    msg.states[60].sid.code
                );
                assert_eq!(
                    msg.states[60].sid.sat, 207,
                    "incorrect value for states[60].sid.sat, expected 207, is {}",
                    msg.states[60].sid.sat
                );
                assert_eq!(
                    msg.states[61].cn0, 226,
                    "incorrect value for states[61].cn0, expected 226, is {}",
                    msg.states[61].cn0
                );
                assert_eq!(
                    msg.states[61].fcn, 43,
                    "incorrect value for states[61].fcn, expected 43, is {}",
                    msg.states[61].fcn
                );
                assert_eq!(
                    msg.states[61].sid.code, 17,
                    "incorrect value for states[61].sid.code, expected 17, is {}",
                    msg.states[61].sid.code
                );
                assert_eq!(
                    msg.states[61].sid.sat, 180,
                    "incorrect value for states[61].sid.sat, expected 180, is {}",
                    msg.states[61].sid.sat
                );
                assert_eq!(
                    msg.states[62].cn0, 113,
                    "incorrect value for states[62].cn0, expected 113, is {}",
                    msg.states[62].cn0
                );
                assert_eq!(
                    msg.states[62].fcn, 140,
                    "incorrect value for states[62].fcn, expected 140, is {}",
                    msg.states[62].fcn
                );
                assert_eq!(
                    msg.states[62].sid.code, 182,
                    "incorrect value for states[62].sid.code, expected 182, is {}",
                    msg.states[62].sid.code
                );
                assert_eq!(
                    msg.states[62].sid.sat, 255,
                    "incorrect value for states[62].sid.sat, expected 255, is {}",
                    msg.states[62].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingState"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 197, 253, 28, 66, 1, 203, 0, 0, 0, 231, 99,
            16, 66, 1, 208, 0, 0, 0, 212, 129, 22, 66, 1, 212, 0, 0, 0, 58, 21, 28, 66, 1, 217, 0,
            0, 0, 178, 33, 40, 66, 1, 218, 0, 0, 0, 235, 189, 21, 66, 1, 220, 0, 0, 0, 29, 177, 25,
            66, 1, 222, 0, 0, 0, 43, 169, 27, 66, 1, 225, 0, 0, 0, 137, 125, 42, 66, 0, 0, 0, 0, 0,
            0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 222, 97,
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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.92478218078613281e+01),
                    "incorrect value for states[0].cn0, expected 3.92478218078613281e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.60975608825683594e+01),
                    "incorrect value for states[1].cn0, expected 3.60975608825683594e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.76267852783203125e+01),
                    "incorrect value for states[2].cn0, expected 3.76267852783203125e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.90207290649414062e+01),
                    "incorrect value for states[3].cn0, expected 3.90207290649414062e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.20329055786132812e+01),
                    "incorrect value for states[4].cn0, expected 4.20329055786132812e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.74354667663574219e+01),
                    "incorrect value for states[5].cn0, expected 3.74354667663574219e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.84229621887207031e+01),
                    "incorrect value for states[6].cn0, expected 3.84229621887207031e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.89152030944824219e+01),
                    "incorrect value for states[7].cn0, expected 3.89152030944824219e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.26225929260253906e+01),
                    "incorrect value for states[8].cn0, expected 4.26225929260253906e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 250, 249, 27, 66, 1, 203, 0, 0, 0, 40, 143,
            11, 66, 1, 208, 0, 0, 0, 190, 200, 21, 66, 1, 212, 0, 0, 0, 251, 233, 26, 66, 1, 217,
            0, 0, 0, 209, 238, 39, 66, 1, 218, 0, 0, 0, 162, 219, 21, 66, 1, 220, 0, 0, 0, 162,
            197, 25, 66, 1, 222, 0, 0, 0, 14, 35, 28, 66, 1, 225, 0, 0, 0, 9, 153, 43, 66, 0, 0, 0,
            0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 20, 31,
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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.89941177368164062e+01),
                    "incorrect value for states[0].cn0, expected 3.89941177368164062e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.48898010253906250e+01),
                    "incorrect value for states[1].cn0, expected 3.48898010253906250e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.74460372924804688e+01),
                    "incorrect value for states[2].cn0, expected 3.74460372924804688e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.87284965515136719e+01),
                    "incorrect value for states[3].cn0, expected 3.87284965515136719e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.19832191467285156e+01),
                    "incorrect value for states[4].cn0, expected 4.19832191467285156e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.74644851684570312e+01),
                    "incorrect value for states[5].cn0, expected 3.74644851684570312e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.84430007934570312e+01),
                    "incorrect value for states[6].cn0, expected 3.84430007934570312e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.90342330932617188e+01),
                    "incorrect value for states[7].cn0, expected 3.90342330932617188e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.28994483947753906e+01),
                    "incorrect value for states[8].cn0, expected 4.28994483947753906e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 123, 209, 27, 66, 1, 203, 0, 0, 0, 214, 64,
            15, 66, 1, 208, 0, 0, 0, 56, 55, 22, 66, 1, 212, 0, 0, 0, 91, 142, 27, 66, 1, 217, 0,
            0, 0, 253, 154, 41, 66, 1, 218, 0, 0, 0, 128, 142, 22, 66, 1, 220, 0, 0, 0, 17, 174,
            23, 66, 1, 222, 0, 0, 0, 155, 2, 29, 66, 1, 225, 0, 0, 0, 162, 100, 42, 66, 0, 0, 0, 0,
            0, 0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 233, 71,
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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.89545707702636719e+01),
                    "incorrect value for states[0].cn0, expected 3.89545707702636719e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.58133163452148438e+01),
                    "incorrect value for states[1].cn0, expected 3.58133163452148438e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.75539245605468750e+01),
                    "incorrect value for states[2].cn0, expected 3.75539245605468750e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.88890190124511719e+01),
                    "incorrect value for states[3].cn0, expected 3.88890190124511719e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.24013557434082031e+01),
                    "incorrect value for states[4].cn0, expected 4.24013557434082031e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.76391601562500000e+01),
                    "incorrect value for states[5].cn0, expected 3.76391601562500000e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.79199867248535156e+01),
                    "incorrect value for states[6].cn0, expected 3.79199867248535156e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.92525444030761719e+01),
                    "incorrect value for states[7].cn0, expected 3.92525444030761719e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.25982742309570312e+01),
                    "incorrect value for states[8].cn0, expected 4.25982742309570312e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 120, 122, 29, 66, 1, 203, 0, 0, 0, 66, 22,
            18, 66, 1, 208, 0, 0, 0, 153, 163, 24, 66, 1, 212, 0, 0, 0, 178, 204, 28, 66, 1, 217,
            0, 0, 0, 220, 59, 38, 66, 1, 218, 0, 0, 0, 161, 27, 20, 66, 1, 220, 0, 0, 0, 125, 107,
            24, 66, 1, 222, 0, 0, 0, 242, 46, 28, 66, 1, 225, 0, 0, 0, 231, 130, 41, 66, 0, 0, 0,
            0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 73, 193,
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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.93695983886718750e+01),
                    "incorrect value for states[0].cn0, expected 3.93695983886718750e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.65217361450195312e+01),
                    "incorrect value for states[1].cn0, expected 3.65217361450195312e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.81597633361816406e+01),
                    "incorrect value for states[2].cn0, expected 3.81597633361816406e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.91998977661132812e+01),
                    "incorrect value for states[3].cn0, expected 3.91998977661132812e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.15584564208984375e+01),
                    "incorrect value for states[4].cn0, expected 4.15584564208984375e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.70269813537597656e+01),
                    "incorrect value for states[5].cn0, expected 3.70269813537597656e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.81049690246582031e+01),
                    "incorrect value for states[6].cn0, expected 3.81049690246582031e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.90458450317382812e+01),
                    "incorrect value for states[7].cn0, expected 3.90458450317382812e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.23778343200683594e+01),
                    "incorrect value for states[8].cn0, expected 4.23778343200683594e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 103, 208, 30, 66, 1, 203, 0, 0, 0, 117, 24,
            18, 66, 1, 208, 0, 0, 0, 200, 173, 20, 66, 1, 212, 0, 0, 0, 137, 68, 27, 66, 1, 217, 0,
            0, 0, 243, 51, 40, 66, 1, 218, 0, 0, 0, 225, 58, 23, 66, 1, 220, 0, 0, 0, 132, 221, 22,
            66, 1, 222, 0, 0, 0, 157, 29, 26, 66, 1, 225, 0, 0, 0, 133, 21, 41, 66, 0, 0, 0, 0, 0,
            0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 126, 47,
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
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.97035179138183594e+01),
                    "incorrect value for states[0].cn0, expected 3.97035179138183594e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].sid.code, 0,
                    "incorrect value for states[0].sid.code, expected 0, is {}",
                    msg.states[0].sid.code
                );
                assert_eq!(
                    msg.states[0].sid.reserved, 0,
                    "incorrect value for states[0].sid.reserved, expected 0, is {}",
                    msg.states[0].sid.reserved
                );
                assert_eq!(
                    msg.states[0].sid.sat, 202,
                    "incorrect value for states[0].sid.sat, expected 202, is {}",
                    msg.states[0].sid.sat
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(3.65238838195800781e+01),
                    "incorrect value for states[1].cn0, expected 3.65238838195800781e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].sid.code, 0,
                    "incorrect value for states[1].sid.code, expected 0, is {}",
                    msg.states[1].sid.code
                );
                assert_eq!(
                    msg.states[1].sid.reserved, 0,
                    "incorrect value for states[1].sid.reserved, expected 0, is {}",
                    msg.states[1].sid.reserved
                );
                assert_eq!(
                    msg.states[1].sid.sat, 203,
                    "incorrect value for states[1].sid.sat, expected 203, is {}",
                    msg.states[1].sid.sat
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(3.71697082519531250e+01),
                    "incorrect value for states[2].cn0, expected 3.71697082519531250e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].sid.code, 0,
                    "incorrect value for states[2].sid.code, expected 0, is {}",
                    msg.states[2].sid.code
                );
                assert_eq!(
                    msg.states[2].sid.reserved, 0,
                    "incorrect value for states[2].sid.reserved, expected 0, is {}",
                    msg.states[2].sid.reserved
                );
                assert_eq!(
                    msg.states[2].sid.sat, 208,
                    "incorrect value for states[2].sid.sat, expected 208, is {}",
                    msg.states[2].sid.sat
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(3.88169288635253906e+01),
                    "incorrect value for states[3].cn0, expected 3.88169288635253906e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].sid.code, 0,
                    "incorrect value for states[3].sid.code, expected 0, is {}",
                    msg.states[3].sid.code
                );
                assert_eq!(
                    msg.states[3].sid.reserved, 0,
                    "incorrect value for states[3].sid.reserved, expected 0, is {}",
                    msg.states[3].sid.reserved
                );
                assert_eq!(
                    msg.states[3].sid.sat, 212,
                    "incorrect value for states[3].sid.sat, expected 212, is {}",
                    msg.states[3].sid.sat
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(4.20507316589355469e+01),
                    "incorrect value for states[4].cn0, expected 4.20507316589355469e+01, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].sid.code, 0,
                    "incorrect value for states[4].sid.code, expected 0, is {}",
                    msg.states[4].sid.code
                );
                assert_eq!(
                    msg.states[4].sid.reserved, 0,
                    "incorrect value for states[4].sid.reserved, expected 0, is {}",
                    msg.states[4].sid.reserved
                );
                assert_eq!(
                    msg.states[4].sid.sat, 217,
                    "incorrect value for states[4].sid.sat, expected 217, is {}",
                    msg.states[4].sid.sat
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(3.78074989318847656e+01),
                    "incorrect value for states[5].cn0, expected 3.78074989318847656e+01, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].sid.code, 0,
                    "incorrect value for states[5].sid.code, expected 0, is {}",
                    msg.states[5].sid.code
                );
                assert_eq!(
                    msg.states[5].sid.reserved, 0,
                    "incorrect value for states[5].sid.reserved, expected 0, is {}",
                    msg.states[5].sid.reserved
                );
                assert_eq!(
                    msg.states[5].sid.sat, 218,
                    "incorrect value for states[5].sid.sat, expected 218, is {}",
                    msg.states[5].sid.sat
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(3.77163238525390625e+01),
                    "incorrect value for states[6].cn0, expected 3.77163238525390625e+01, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].sid.code, 0,
                    "incorrect value for states[6].sid.code, expected 0, is {}",
                    msg.states[6].sid.code
                );
                assert_eq!(
                    msg.states[6].sid.reserved, 0,
                    "incorrect value for states[6].sid.reserved, expected 0, is {}",
                    msg.states[6].sid.reserved
                );
                assert_eq!(
                    msg.states[6].sid.sat, 220,
                    "incorrect value for states[6].sid.sat, expected 220, is {}",
                    msg.states[6].sid.sat
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(3.85289192199707031e+01),
                    "incorrect value for states[7].cn0, expected 3.85289192199707031e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].sid.code, 0,
                    "incorrect value for states[7].sid.code, expected 0, is {}",
                    msg.states[7].sid.code
                );
                assert_eq!(
                    msg.states[7].sid.reserved, 0,
                    "incorrect value for states[7].sid.reserved, expected 0, is {}",
                    msg.states[7].sid.reserved
                );
                assert_eq!(
                    msg.states[7].sid.sat, 222,
                    "incorrect value for states[7].sid.sat, expected 222, is {}",
                    msg.states[7].sid.sat
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(4.22710151672363281e+01),
                    "incorrect value for states[8].cn0, expected 4.22710151672363281e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].sid.code, 0,
                    "incorrect value for states[8].sid.code, expected 0, is {}",
                    msg.states[8].sid.code
                );
                assert_eq!(
                    msg.states[8].sid.reserved, 0,
                    "incorrect value for states[8].sid.reserved, expected 0, is {}",
                    msg.states[8].sid.reserved
                );
                assert_eq!(
                    msg.states[8].sid.sat, 225,
                    "incorrect value for states[8].sid.sat, expected 225, is {}",
                    msg.states[8].sid.sat
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].sid.code, 0,
                    "incorrect value for states[9].sid.code, expected 0, is {}",
                    msg.states[9].sid.code
                );
                assert_eq!(
                    msg.states[9].sid.reserved, 0,
                    "incorrect value for states[9].sid.reserved, expected 0, is {}",
                    msg.states[9].sid.reserved
                );
                assert_eq!(
                    msg.states[9].sid.sat, 0,
                    "incorrect value for states[9].sid.sat, expected 0, is {}",
                    msg.states[9].sid.sat
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].sid.code, 0,
                    "incorrect value for states[10].sid.code, expected 0, is {}",
                    msg.states[10].sid.code
                );
                assert_eq!(
                    msg.states[10].sid.reserved, 0,
                    "incorrect value for states[10].sid.reserved, expected 0, is {}",
                    msg.states[10].sid.reserved
                );
                assert_eq!(
                    msg.states[10].sid.sat, 0,
                    "incorrect value for states[10].sid.sat, expected 0, is {}",
                    msg.states[10].sid.sat
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepB"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
