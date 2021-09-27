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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObs.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_observation_msg_obs() {
    {
        let mut payload = Cursor::new(vec![
            85, 74, 0, 129, 240, 249, 152, 202, 226, 25, 0, 0, 0, 0, 106, 8, 32, 49, 227, 254, 62,
            121, 242, 158, 6, 146, 0, 250, 172, 182, 10, 15, 10, 0, 30, 228, 254, 62, 12, 189, 40,
            5, 59, 83, 251, 172, 178, 10, 15, 10, 1, 215, 205, 144, 72, 106, 111, 160, 7, 243, 109,
            243, 119, 158, 10, 15, 18, 0, 25, 207, 144, 72, 223, 96, 241, 5, 12, 52, 246, 27, 125,
            9, 11, 18, 1, 34, 184, 223, 74, 150, 138, 222, 7, 53, 13, 11, 245, 114, 9, 15, 22, 0,
            113, 80, 6, 69, 162, 41, 65, 7, 70, 127, 246, 246, 189, 9, 15, 23, 0, 247, 80, 6, 69,
            213, 35, 167, 5, 221, 152, 248, 231, 158, 9, 11, 23, 1, 8, 146, 166, 64, 12, 122, 203,
            6, 114, 51, 248, 67, 93, 3, 11, 27, 0, 221, 172, 173, 75, 217, 47, 244, 7, 232, 225,
            11, 237, 123, 5, 15, 31, 0, 250, 174, 173, 75, 216, 163, 50, 6, 40, 70, 9, 62, 120, 3,
            11, 31, 1, 135, 16, 6, 66, 99, 218, 11, 7, 7, 138, 242, 96, 176, 10, 15, 2, 3, 148,
            130, 6, 58, 217, 88, 54, 6, 203, 21, 252, 96, 170, 10, 15, 3, 3, 186, 108, 197, 63,
            127, 54, 211, 6, 80, 4, 241, 219, 200, 10, 15, 17, 3, 167, 195, 8, 57, 19, 204, 22, 6,
            105, 51, 254, 182, 152, 10, 15, 18, 3, 237, 248,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgObs(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x4a,
                    "Incorrect message type, expected 0x4a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf081,
                    "incorrect sender id, expected 0xf081, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 32,
                    "incorrect value for header.n_obs, expected 32, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.ns_residual, 0,
                    "incorrect value for header.t.ns_residual, expected 0, is {}",
                    msg.header.t.ns_residual
                );
                assert_eq!(
                    msg.header.t.tow, 434293400,
                    "incorrect value for header.t.tow, expected 434293400, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 2154,
                    "incorrect value for header.t.wn, expected 2154, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].d.f, 172,
                    "incorrect value for obs[0].d.f, expected 172, is {}",
                    msg.obs[0].d.f
                );
                assert_eq!(
                    msg.obs[0].d.i, -1536,
                    "incorrect value for obs[0].d.i, expected -1536, is {}",
                    msg.obs[0].d.i
                );
                assert_eq!(
                    msg.obs[0].l.f, 146,
                    "incorrect value for obs[0].l.f, expected 146, is {}",
                    msg.obs[0].l.f
                );
                assert_eq!(
                    msg.obs[0].l.i, 111080057,
                    "incorrect value for obs[0].l.i, expected 111080057, is {}",
                    msg.obs[0].l.i
                );
                assert_eq!(
                    msg.obs[0].p, 1056891697,
                    "incorrect value for obs[0].p, expected 1056891697, is {}",
                    msg.obs[0].p
                );
                assert_eq!(
                    msg.obs[0].cn0, 182,
                    "incorrect value for obs[0].cn0, expected 182, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].flags, 15,
                    "incorrect value for obs[0].flags, expected 15, is {}",
                    msg.obs[0].flags
                );
                assert_eq!(
                    msg.obs[0].lock, 10,
                    "incorrect value for obs[0].lock, expected 10, is {}",
                    msg.obs[0].lock
                );
                assert_eq!(
                    msg.obs[0].sid.code, 0,
                    "incorrect value for obs[0].sid.code, expected 0, is {}",
                    msg.obs[0].sid.code
                );
                assert_eq!(
                    msg.obs[0].sid.sat, 10,
                    "incorrect value for obs[0].sid.sat, expected 10, is {}",
                    msg.obs[0].sid.sat
                );
                assert_eq!(
                    msg.obs[1].d.f, 172,
                    "incorrect value for obs[1].d.f, expected 172, is {}",
                    msg.obs[1].d.f
                );
                assert_eq!(
                    msg.obs[1].d.i, -1197,
                    "incorrect value for obs[1].d.i, expected -1197, is {}",
                    msg.obs[1].d.i
                );
                assert_eq!(
                    msg.obs[1].l.f, 59,
                    "incorrect value for obs[1].l.f, expected 59, is {}",
                    msg.obs[1].l.f
                );
                assert_eq!(
                    msg.obs[1].l.i, 86555916,
                    "incorrect value for obs[1].l.i, expected 86555916, is {}",
                    msg.obs[1].l.i
                );
                assert_eq!(
                    msg.obs[1].p, 1056891934,
                    "incorrect value for obs[1].p, expected 1056891934, is {}",
                    msg.obs[1].p
                );
                assert_eq!(
                    msg.obs[1].cn0, 178,
                    "incorrect value for obs[1].cn0, expected 178, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].flags, 15,
                    "incorrect value for obs[1].flags, expected 15, is {}",
                    msg.obs[1].flags
                );
                assert_eq!(
                    msg.obs[1].lock, 10,
                    "incorrect value for obs[1].lock, expected 10, is {}",
                    msg.obs[1].lock
                );
                assert_eq!(
                    msg.obs[1].sid.code, 1,
                    "incorrect value for obs[1].sid.code, expected 1, is {}",
                    msg.obs[1].sid.code
                );
                assert_eq!(
                    msg.obs[1].sid.sat, 10,
                    "incorrect value for obs[1].sid.sat, expected 10, is {}",
                    msg.obs[1].sid.sat
                );
                assert_eq!(
                    msg.obs[2].d.f, 119,
                    "incorrect value for obs[2].d.f, expected 119, is {}",
                    msg.obs[2].d.f
                );
                assert_eq!(
                    msg.obs[2].d.i, -3219,
                    "incorrect value for obs[2].d.i, expected -3219, is {}",
                    msg.obs[2].d.i
                );
                assert_eq!(
                    msg.obs[2].l.f, 243,
                    "incorrect value for obs[2].l.f, expected 243, is {}",
                    msg.obs[2].l.f
                );
                assert_eq!(
                    msg.obs[2].l.i, 127954794,
                    "incorrect value for obs[2].l.i, expected 127954794, is {}",
                    msg.obs[2].l.i
                );
                assert_eq!(
                    msg.obs[2].p, 1217449431,
                    "incorrect value for obs[2].p, expected 1217449431, is {}",
                    msg.obs[2].p
                );
                assert_eq!(
                    msg.obs[2].cn0, 158,
                    "incorrect value for obs[2].cn0, expected 158, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].flags, 15,
                    "incorrect value for obs[2].flags, expected 15, is {}",
                    msg.obs[2].flags
                );
                assert_eq!(
                    msg.obs[2].lock, 10,
                    "incorrect value for obs[2].lock, expected 10, is {}",
                    msg.obs[2].lock
                );
                assert_eq!(
                    msg.obs[2].sid.code, 0,
                    "incorrect value for obs[2].sid.code, expected 0, is {}",
                    msg.obs[2].sid.code
                );
                assert_eq!(
                    msg.obs[2].sid.sat, 18,
                    "incorrect value for obs[2].sid.sat, expected 18, is {}",
                    msg.obs[2].sid.sat
                );
                assert_eq!(
                    msg.obs[3].d.f, 27,
                    "incorrect value for obs[3].d.f, expected 27, is {}",
                    msg.obs[3].d.f
                );
                assert_eq!(
                    msg.obs[3].d.i, -2508,
                    "incorrect value for obs[3].d.i, expected -2508, is {}",
                    msg.obs[3].d.i
                );
                assert_eq!(
                    msg.obs[3].l.f, 12,
                    "incorrect value for obs[3].l.f, expected 12, is {}",
                    msg.obs[3].l.f
                );
                assert_eq!(
                    msg.obs[3].l.i, 99705055,
                    "incorrect value for obs[3].l.i, expected 99705055, is {}",
                    msg.obs[3].l.i
                );
                assert_eq!(
                    msg.obs[3].p, 1217449753,
                    "incorrect value for obs[3].p, expected 1217449753, is {}",
                    msg.obs[3].p
                );
                assert_eq!(
                    msg.obs[3].cn0, 125,
                    "incorrect value for obs[3].cn0, expected 125, is {}",
                    msg.obs[3].cn0
                );
                assert_eq!(
                    msg.obs[3].flags, 11,
                    "incorrect value for obs[3].flags, expected 11, is {}",
                    msg.obs[3].flags
                );
                assert_eq!(
                    msg.obs[3].lock, 9,
                    "incorrect value for obs[3].lock, expected 9, is {}",
                    msg.obs[3].lock
                );
                assert_eq!(
                    msg.obs[3].sid.code, 1,
                    "incorrect value for obs[3].sid.code, expected 1, is {}",
                    msg.obs[3].sid.code
                );
                assert_eq!(
                    msg.obs[3].sid.sat, 18,
                    "incorrect value for obs[3].sid.sat, expected 18, is {}",
                    msg.obs[3].sid.sat
                );
                assert_eq!(
                    msg.obs[4].d.f, 245,
                    "incorrect value for obs[4].d.f, expected 245, is {}",
                    msg.obs[4].d.f
                );
                assert_eq!(
                    msg.obs[4].d.i, 2829,
                    "incorrect value for obs[4].d.i, expected 2829, is {}",
                    msg.obs[4].d.i
                );
                assert_eq!(
                    msg.obs[4].l.f, 53,
                    "incorrect value for obs[4].l.f, expected 53, is {}",
                    msg.obs[4].l.f
                );
                assert_eq!(
                    msg.obs[4].l.i, 132024982,
                    "incorrect value for obs[4].l.i, expected 132024982, is {}",
                    msg.obs[4].l.i
                );
                assert_eq!(
                    msg.obs[4].p, 1256175650,
                    "incorrect value for obs[4].p, expected 1256175650, is {}",
                    msg.obs[4].p
                );
                assert_eq!(
                    msg.obs[4].cn0, 114,
                    "incorrect value for obs[4].cn0, expected 114, is {}",
                    msg.obs[4].cn0
                );
                assert_eq!(
                    msg.obs[4].flags, 15,
                    "incorrect value for obs[4].flags, expected 15, is {}",
                    msg.obs[4].flags
                );
                assert_eq!(
                    msg.obs[4].lock, 9,
                    "incorrect value for obs[4].lock, expected 9, is {}",
                    msg.obs[4].lock
                );
                assert_eq!(
                    msg.obs[4].sid.code, 0,
                    "incorrect value for obs[4].sid.code, expected 0, is {}",
                    msg.obs[4].sid.code
                );
                assert_eq!(
                    msg.obs[4].sid.sat, 22,
                    "incorrect value for obs[4].sid.sat, expected 22, is {}",
                    msg.obs[4].sid.sat
                );
                assert_eq!(
                    msg.obs[5].d.f, 246,
                    "incorrect value for obs[5].d.f, expected 246, is {}",
                    msg.obs[5].d.f
                );
                assert_eq!(
                    msg.obs[5].d.i, -2433,
                    "incorrect value for obs[5].d.i, expected -2433, is {}",
                    msg.obs[5].d.i
                );
                assert_eq!(
                    msg.obs[5].l.f, 70,
                    "incorrect value for obs[5].l.f, expected 70, is {}",
                    msg.obs[5].l.f
                );
                assert_eq!(
                    msg.obs[5].l.i, 121711010,
                    "incorrect value for obs[5].l.i, expected 121711010, is {}",
                    msg.obs[5].l.i
                );
                assert_eq!(
                    msg.obs[5].p, 1158041713,
                    "incorrect value for obs[5].p, expected 1158041713, is {}",
                    msg.obs[5].p
                );
                assert_eq!(
                    msg.obs[5].cn0, 189,
                    "incorrect value for obs[5].cn0, expected 189, is {}",
                    msg.obs[5].cn0
                );
                assert_eq!(
                    msg.obs[5].flags, 15,
                    "incorrect value for obs[5].flags, expected 15, is {}",
                    msg.obs[5].flags
                );
                assert_eq!(
                    msg.obs[5].lock, 9,
                    "incorrect value for obs[5].lock, expected 9, is {}",
                    msg.obs[5].lock
                );
                assert_eq!(
                    msg.obs[5].sid.code, 0,
                    "incorrect value for obs[5].sid.code, expected 0, is {}",
                    msg.obs[5].sid.code
                );
                assert_eq!(
                    msg.obs[5].sid.sat, 23,
                    "incorrect value for obs[5].sid.sat, expected 23, is {}",
                    msg.obs[5].sid.sat
                );
                assert_eq!(
                    msg.obs[6].d.f, 231,
                    "incorrect value for obs[6].d.f, expected 231, is {}",
                    msg.obs[6].d.f
                );
                assert_eq!(
                    msg.obs[6].d.i, -1896,
                    "incorrect value for obs[6].d.i, expected -1896, is {}",
                    msg.obs[6].d.i
                );
                assert_eq!(
                    msg.obs[6].l.f, 221,
                    "incorrect value for obs[6].l.f, expected 221, is {}",
                    msg.obs[6].l.f
                );
                assert_eq!(
                    msg.obs[6].l.i, 94839765,
                    "incorrect value for obs[6].l.i, expected 94839765, is {}",
                    msg.obs[6].l.i
                );
                assert_eq!(
                    msg.obs[6].p, 1158041847,
                    "incorrect value for obs[6].p, expected 1158041847, is {}",
                    msg.obs[6].p
                );
                assert_eq!(
                    msg.obs[6].cn0, 158,
                    "incorrect value for obs[6].cn0, expected 158, is {}",
                    msg.obs[6].cn0
                );
                assert_eq!(
                    msg.obs[6].flags, 11,
                    "incorrect value for obs[6].flags, expected 11, is {}",
                    msg.obs[6].flags
                );
                assert_eq!(
                    msg.obs[6].lock, 9,
                    "incorrect value for obs[6].lock, expected 9, is {}",
                    msg.obs[6].lock
                );
                assert_eq!(
                    msg.obs[6].sid.code, 1,
                    "incorrect value for obs[6].sid.code, expected 1, is {}",
                    msg.obs[6].sid.code
                );
                assert_eq!(
                    msg.obs[6].sid.sat, 23,
                    "incorrect value for obs[6].sid.sat, expected 23, is {}",
                    msg.obs[6].sid.sat
                );
                assert_eq!(
                    msg.obs[7].d.f, 67,
                    "incorrect value for obs[7].d.f, expected 67, is {}",
                    msg.obs[7].d.f
                );
                assert_eq!(
                    msg.obs[7].d.i, -1997,
                    "incorrect value for obs[7].d.i, expected -1997, is {}",
                    msg.obs[7].d.i
                );
                assert_eq!(
                    msg.obs[7].l.f, 114,
                    "incorrect value for obs[7].l.f, expected 114, is {}",
                    msg.obs[7].l.f
                );
                assert_eq!(
                    msg.obs[7].l.i, 113998348,
                    "incorrect value for obs[7].l.i, expected 113998348, is {}",
                    msg.obs[7].l.i
                );
                assert_eq!(
                    msg.obs[7].p, 1084658184,
                    "incorrect value for obs[7].p, expected 1084658184, is {}",
                    msg.obs[7].p
                );
                assert_eq!(
                    msg.obs[7].cn0, 93,
                    "incorrect value for obs[7].cn0, expected 93, is {}",
                    msg.obs[7].cn0
                );
                assert_eq!(
                    msg.obs[7].flags, 11,
                    "incorrect value for obs[7].flags, expected 11, is {}",
                    msg.obs[7].flags
                );
                assert_eq!(
                    msg.obs[7].lock, 3,
                    "incorrect value for obs[7].lock, expected 3, is {}",
                    msg.obs[7].lock
                );
                assert_eq!(
                    msg.obs[7].sid.code, 0,
                    "incorrect value for obs[7].sid.code, expected 0, is {}",
                    msg.obs[7].sid.code
                );
                assert_eq!(
                    msg.obs[7].sid.sat, 27,
                    "incorrect value for obs[7].sid.sat, expected 27, is {}",
                    msg.obs[7].sid.sat
                );
                assert_eq!(
                    msg.obs[8].d.f, 237,
                    "incorrect value for obs[8].d.f, expected 237, is {}",
                    msg.obs[8].d.f
                );
                assert_eq!(
                    msg.obs[8].d.i, 3041,
                    "incorrect value for obs[8].d.i, expected 3041, is {}",
                    msg.obs[8].d.i
                );
                assert_eq!(
                    msg.obs[8].l.f, 232,
                    "incorrect value for obs[8].l.f, expected 232, is {}",
                    msg.obs[8].l.f
                );
                assert_eq!(
                    msg.obs[8].l.i, 133443545,
                    "incorrect value for obs[8].l.i, expected 133443545, is {}",
                    msg.obs[8].l.i
                );
                assert_eq!(
                    msg.obs[8].p, 1269673181,
                    "incorrect value for obs[8].p, expected 1269673181, is {}",
                    msg.obs[8].p
                );
                assert_eq!(
                    msg.obs[8].cn0, 123,
                    "incorrect value for obs[8].cn0, expected 123, is {}",
                    msg.obs[8].cn0
                );
                assert_eq!(
                    msg.obs[8].flags, 15,
                    "incorrect value for obs[8].flags, expected 15, is {}",
                    msg.obs[8].flags
                );
                assert_eq!(
                    msg.obs[8].lock, 5,
                    "incorrect value for obs[8].lock, expected 5, is {}",
                    msg.obs[8].lock
                );
                assert_eq!(
                    msg.obs[8].sid.code, 0,
                    "incorrect value for obs[8].sid.code, expected 0, is {}",
                    msg.obs[8].sid.code
                );
                assert_eq!(
                    msg.obs[8].sid.sat, 31,
                    "incorrect value for obs[8].sid.sat, expected 31, is {}",
                    msg.obs[8].sid.sat
                );
                assert_eq!(
                    msg.obs[9].d.f, 62,
                    "incorrect value for obs[9].d.f, expected 62, is {}",
                    msg.obs[9].d.f
                );
                assert_eq!(
                    msg.obs[9].d.i, 2374,
                    "incorrect value for obs[9].d.i, expected 2374, is {}",
                    msg.obs[9].d.i
                );
                assert_eq!(
                    msg.obs[9].l.f, 40,
                    "incorrect value for obs[9].l.f, expected 40, is {}",
                    msg.obs[9].l.f
                );
                assert_eq!(
                    msg.obs[9].l.i, 103982040,
                    "incorrect value for obs[9].l.i, expected 103982040, is {}",
                    msg.obs[9].l.i
                );
                assert_eq!(
                    msg.obs[9].p, 1269673722,
                    "incorrect value for obs[9].p, expected 1269673722, is {}",
                    msg.obs[9].p
                );
                assert_eq!(
                    msg.obs[9].cn0, 120,
                    "incorrect value for obs[9].cn0, expected 120, is {}",
                    msg.obs[9].cn0
                );
                assert_eq!(
                    msg.obs[9].flags, 11,
                    "incorrect value for obs[9].flags, expected 11, is {}",
                    msg.obs[9].flags
                );
                assert_eq!(
                    msg.obs[9].lock, 3,
                    "incorrect value for obs[9].lock, expected 3, is {}",
                    msg.obs[9].lock
                );
                assert_eq!(
                    msg.obs[9].sid.code, 1,
                    "incorrect value for obs[9].sid.code, expected 1, is {}",
                    msg.obs[9].sid.code
                );
                assert_eq!(
                    msg.obs[9].sid.sat, 31,
                    "incorrect value for obs[9].sid.sat, expected 31, is {}",
                    msg.obs[9].sid.sat
                );
                assert_eq!(
                    msg.obs[10].d.f, 96,
                    "incorrect value for obs[10].d.f, expected 96, is {}",
                    msg.obs[10].d.f
                );
                assert_eq!(
                    msg.obs[10].d.i, -3446,
                    "incorrect value for obs[10].d.i, expected -3446, is {}",
                    msg.obs[10].d.i
                );
                assert_eq!(
                    msg.obs[10].l.f, 7,
                    "incorrect value for obs[10].l.f, expected 7, is {}",
                    msg.obs[10].l.f
                );
                assert_eq!(
                    msg.obs[10].l.i, 118217315,
                    "incorrect value for obs[10].l.i, expected 118217315, is {}",
                    msg.obs[10].l.i
                );
                assert_eq!(
                    msg.obs[10].p, 1107693703,
                    "incorrect value for obs[10].p, expected 1107693703, is {}",
                    msg.obs[10].p
                );
                assert_eq!(
                    msg.obs[10].cn0, 176,
                    "incorrect value for obs[10].cn0, expected 176, is {}",
                    msg.obs[10].cn0
                );
                assert_eq!(
                    msg.obs[10].flags, 15,
                    "incorrect value for obs[10].flags, expected 15, is {}",
                    msg.obs[10].flags
                );
                assert_eq!(
                    msg.obs[10].lock, 10,
                    "incorrect value for obs[10].lock, expected 10, is {}",
                    msg.obs[10].lock
                );
                assert_eq!(
                    msg.obs[10].sid.code, 3,
                    "incorrect value for obs[10].sid.code, expected 3, is {}",
                    msg.obs[10].sid.code
                );
                assert_eq!(
                    msg.obs[10].sid.sat, 2,
                    "incorrect value for obs[10].sid.sat, expected 2, is {}",
                    msg.obs[10].sid.sat
                );
                assert_eq!(
                    msg.obs[11].d.f, 96,
                    "incorrect value for obs[11].d.f, expected 96, is {}",
                    msg.obs[11].d.f
                );
                assert_eq!(
                    msg.obs[11].d.i, -1003,
                    "incorrect value for obs[11].d.i, expected -1003, is {}",
                    msg.obs[11].d.i
                );
                assert_eq!(
                    msg.obs[11].l.f, 203,
                    "incorrect value for obs[11].l.f, expected 203, is {}",
                    msg.obs[11].l.f
                );
                assert_eq!(
                    msg.obs[11].l.i, 104224985,
                    "incorrect value for obs[11].l.i, expected 104224985, is {}",
                    msg.obs[11].l.i
                );
                assert_eq!(
                    msg.obs[11].p, 973505172,
                    "incorrect value for obs[11].p, expected 973505172, is {}",
                    msg.obs[11].p
                );
                assert_eq!(
                    msg.obs[11].cn0, 170,
                    "incorrect value for obs[11].cn0, expected 170, is {}",
                    msg.obs[11].cn0
                );
                assert_eq!(
                    msg.obs[11].flags, 15,
                    "incorrect value for obs[11].flags, expected 15, is {}",
                    msg.obs[11].flags
                );
                assert_eq!(
                    msg.obs[11].lock, 10,
                    "incorrect value for obs[11].lock, expected 10, is {}",
                    msg.obs[11].lock
                );
                assert_eq!(
                    msg.obs[11].sid.code, 3,
                    "incorrect value for obs[11].sid.code, expected 3, is {}",
                    msg.obs[11].sid.code
                );
                assert_eq!(
                    msg.obs[11].sid.sat, 3,
                    "incorrect value for obs[11].sid.sat, expected 3, is {}",
                    msg.obs[11].sid.sat
                );
                assert_eq!(
                    msg.obs[12].d.f, 219,
                    "incorrect value for obs[12].d.f, expected 219, is {}",
                    msg.obs[12].d.f
                );
                assert_eq!(
                    msg.obs[12].d.i, -3836,
                    "incorrect value for obs[12].d.i, expected -3836, is {}",
                    msg.obs[12].d.i
                );
                assert_eq!(
                    msg.obs[12].l.f, 80,
                    "incorrect value for obs[12].l.f, expected 80, is {}",
                    msg.obs[12].l.f
                );
                assert_eq!(
                    msg.obs[12].l.i, 114505343,
                    "incorrect value for obs[12].l.i, expected 114505343, is {}",
                    msg.obs[12].l.i
                );
                assert_eq!(
                    msg.obs[12].p, 1069903034,
                    "incorrect value for obs[12].p, expected 1069903034, is {}",
                    msg.obs[12].p
                );
                assert_eq!(
                    msg.obs[12].cn0, 200,
                    "incorrect value for obs[12].cn0, expected 200, is {}",
                    msg.obs[12].cn0
                );
                assert_eq!(
                    msg.obs[12].flags, 15,
                    "incorrect value for obs[12].flags, expected 15, is {}",
                    msg.obs[12].flags
                );
                assert_eq!(
                    msg.obs[12].lock, 10,
                    "incorrect value for obs[12].lock, expected 10, is {}",
                    msg.obs[12].lock
                );
                assert_eq!(
                    msg.obs[12].sid.code, 3,
                    "incorrect value for obs[12].sid.code, expected 3, is {}",
                    msg.obs[12].sid.code
                );
                assert_eq!(
                    msg.obs[12].sid.sat, 17,
                    "incorrect value for obs[12].sid.sat, expected 17, is {}",
                    msg.obs[12].sid.sat
                );
                assert_eq!(
                    msg.obs[13].d.f, 182,
                    "incorrect value for obs[13].d.f, expected 182, is {}",
                    msg.obs[13].d.f
                );
                assert_eq!(
                    msg.obs[13].d.i, -461,
                    "incorrect value for obs[13].d.i, expected -461, is {}",
                    msg.obs[13].d.i
                );
                assert_eq!(
                    msg.obs[13].l.f, 105,
                    "incorrect value for obs[13].l.f, expected 105, is {}",
                    msg.obs[13].l.f
                );
                assert_eq!(
                    msg.obs[13].l.i, 102157331,
                    "incorrect value for obs[13].l.i, expected 102157331, is {}",
                    msg.obs[13].l.i
                );
                assert_eq!(
                    msg.obs[13].p, 956875687,
                    "incorrect value for obs[13].p, expected 956875687, is {}",
                    msg.obs[13].p
                );
                assert_eq!(
                    msg.obs[13].cn0, 152,
                    "incorrect value for obs[13].cn0, expected 152, is {}",
                    msg.obs[13].cn0
                );
                assert_eq!(
                    msg.obs[13].flags, 15,
                    "incorrect value for obs[13].flags, expected 15, is {}",
                    msg.obs[13].flags
                );
                assert_eq!(
                    msg.obs[13].lock, 10,
                    "incorrect value for obs[13].lock, expected 10, is {}",
                    msg.obs[13].lock
                );
                assert_eq!(
                    msg.obs[13].sid.code, 3,
                    "incorrect value for obs[13].sid.code, expected 3, is {}",
                    msg.obs[13].sid.code
                );
                assert_eq!(
                    msg.obs[13].sid.sat, 18,
                    "incorrect value for obs[13].sid.sat, expected 18, is {}",
                    msg.obs[13].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObs"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 74, 0, 129, 240, 11, 152, 202, 226, 25, 0, 0, 0, 0, 106, 8, 16, 201, 101,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgObs(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x4a,
                    "Incorrect message type, expected 0x4a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xf081,
                    "incorrect sender id, expected 0xf081, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 16,
                    "incorrect value for header.n_obs, expected 16, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.ns_residual, 0,
                    "incorrect value for header.t.ns_residual, expected 0, is {}",
                    msg.header.t.ns_residual
                );
                assert_eq!(
                    msg.header.t.tow, 434293400,
                    "incorrect value for header.t.tow, expected 434293400, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 2154,
                    "incorrect value for header.t.wn, expected 2154, is {}",
                    msg.header.t.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObs"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
