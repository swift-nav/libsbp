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

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_observation_MsgObs() {
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
            sbp::messages::SBP::MsgObs(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x4a,
                    "Incorrect message type, expected 0x4a, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                    msg.obs[0].D.f, 172,
                    "incorrect value for obs[0].D.f, expected 172, is {}",
                    msg.obs[0].D.f
                );
                assert_eq!(
                    msg.obs[0].D.i, -1536,
                    "incorrect value for obs[0].D.i, expected -1536, is {}",
                    msg.obs[0].D.i
                );
                assert_eq!(
                    msg.obs[0].L.f, 146,
                    "incorrect value for obs[0].L.f, expected 146, is {}",
                    msg.obs[0].L.f
                );
                assert_eq!(
                    msg.obs[0].L.i, 111080057,
                    "incorrect value for obs[0].L.i, expected 111080057, is {}",
                    msg.obs[0].L.i
                );
                assert_eq!(
                    msg.obs[0].P, 1056891697,
                    "incorrect value for obs[0].P, expected 1056891697, is {}",
                    msg.obs[0].P
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
                    msg.obs[1].D.f, 172,
                    "incorrect value for obs[1].D.f, expected 172, is {}",
                    msg.obs[1].D.f
                );
                assert_eq!(
                    msg.obs[1].D.i, -1197,
                    "incorrect value for obs[1].D.i, expected -1197, is {}",
                    msg.obs[1].D.i
                );
                assert_eq!(
                    msg.obs[1].L.f, 59,
                    "incorrect value for obs[1].L.f, expected 59, is {}",
                    msg.obs[1].L.f
                );
                assert_eq!(
                    msg.obs[1].L.i, 86555916,
                    "incorrect value for obs[1].L.i, expected 86555916, is {}",
                    msg.obs[1].L.i
                );
                assert_eq!(
                    msg.obs[1].P, 1056891934,
                    "incorrect value for obs[1].P, expected 1056891934, is {}",
                    msg.obs[1].P
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
                    msg.obs[2].D.f, 119,
                    "incorrect value for obs[2].D.f, expected 119, is {}",
                    msg.obs[2].D.f
                );
                assert_eq!(
                    msg.obs[2].D.i, -3219,
                    "incorrect value for obs[2].D.i, expected -3219, is {}",
                    msg.obs[2].D.i
                );
                assert_eq!(
                    msg.obs[2].L.f, 243,
                    "incorrect value for obs[2].L.f, expected 243, is {}",
                    msg.obs[2].L.f
                );
                assert_eq!(
                    msg.obs[2].L.i, 127954794,
                    "incorrect value for obs[2].L.i, expected 127954794, is {}",
                    msg.obs[2].L.i
                );
                assert_eq!(
                    msg.obs[2].P, 1217449431,
                    "incorrect value for obs[2].P, expected 1217449431, is {}",
                    msg.obs[2].P
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
                    msg.obs[3].D.f, 27,
                    "incorrect value for obs[3].D.f, expected 27, is {}",
                    msg.obs[3].D.f
                );
                assert_eq!(
                    msg.obs[3].D.i, -2508,
                    "incorrect value for obs[3].D.i, expected -2508, is {}",
                    msg.obs[3].D.i
                );
                assert_eq!(
                    msg.obs[3].L.f, 12,
                    "incorrect value for obs[3].L.f, expected 12, is {}",
                    msg.obs[3].L.f
                );
                assert_eq!(
                    msg.obs[3].L.i, 99705055,
                    "incorrect value for obs[3].L.i, expected 99705055, is {}",
                    msg.obs[3].L.i
                );
                assert_eq!(
                    msg.obs[3].P, 1217449753,
                    "incorrect value for obs[3].P, expected 1217449753, is {}",
                    msg.obs[3].P
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
                    msg.obs[4].D.f, 245,
                    "incorrect value for obs[4].D.f, expected 245, is {}",
                    msg.obs[4].D.f
                );
                assert_eq!(
                    msg.obs[4].D.i, 2829,
                    "incorrect value for obs[4].D.i, expected 2829, is {}",
                    msg.obs[4].D.i
                );
                assert_eq!(
                    msg.obs[4].L.f, 53,
                    "incorrect value for obs[4].L.f, expected 53, is {}",
                    msg.obs[4].L.f
                );
                assert_eq!(
                    msg.obs[4].L.i, 132024982,
                    "incorrect value for obs[4].L.i, expected 132024982, is {}",
                    msg.obs[4].L.i
                );
                assert_eq!(
                    msg.obs[4].P, 1256175650,
                    "incorrect value for obs[4].P, expected 1256175650, is {}",
                    msg.obs[4].P
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
                    msg.obs[5].D.f, 246,
                    "incorrect value for obs[5].D.f, expected 246, is {}",
                    msg.obs[5].D.f
                );
                assert_eq!(
                    msg.obs[5].D.i, -2433,
                    "incorrect value for obs[5].D.i, expected -2433, is {}",
                    msg.obs[5].D.i
                );
                assert_eq!(
                    msg.obs[5].L.f, 70,
                    "incorrect value for obs[5].L.f, expected 70, is {}",
                    msg.obs[5].L.f
                );
                assert_eq!(
                    msg.obs[5].L.i, 121711010,
                    "incorrect value for obs[5].L.i, expected 121711010, is {}",
                    msg.obs[5].L.i
                );
                assert_eq!(
                    msg.obs[5].P, 1158041713,
                    "incorrect value for obs[5].P, expected 1158041713, is {}",
                    msg.obs[5].P
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
                    msg.obs[6].D.f, 231,
                    "incorrect value for obs[6].D.f, expected 231, is {}",
                    msg.obs[6].D.f
                );
                assert_eq!(
                    msg.obs[6].D.i, -1896,
                    "incorrect value for obs[6].D.i, expected -1896, is {}",
                    msg.obs[6].D.i
                );
                assert_eq!(
                    msg.obs[6].L.f, 221,
                    "incorrect value for obs[6].L.f, expected 221, is {}",
                    msg.obs[6].L.f
                );
                assert_eq!(
                    msg.obs[6].L.i, 94839765,
                    "incorrect value for obs[6].L.i, expected 94839765, is {}",
                    msg.obs[6].L.i
                );
                assert_eq!(
                    msg.obs[6].P, 1158041847,
                    "incorrect value for obs[6].P, expected 1158041847, is {}",
                    msg.obs[6].P
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
                    msg.obs[7].D.f, 67,
                    "incorrect value for obs[7].D.f, expected 67, is {}",
                    msg.obs[7].D.f
                );
                assert_eq!(
                    msg.obs[7].D.i, -1997,
                    "incorrect value for obs[7].D.i, expected -1997, is {}",
                    msg.obs[7].D.i
                );
                assert_eq!(
                    msg.obs[7].L.f, 114,
                    "incorrect value for obs[7].L.f, expected 114, is {}",
                    msg.obs[7].L.f
                );
                assert_eq!(
                    msg.obs[7].L.i, 113998348,
                    "incorrect value for obs[7].L.i, expected 113998348, is {}",
                    msg.obs[7].L.i
                );
                assert_eq!(
                    msg.obs[7].P, 1084658184,
                    "incorrect value for obs[7].P, expected 1084658184, is {}",
                    msg.obs[7].P
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
                    msg.obs[8].D.f, 237,
                    "incorrect value for obs[8].D.f, expected 237, is {}",
                    msg.obs[8].D.f
                );
                assert_eq!(
                    msg.obs[8].D.i, 3041,
                    "incorrect value for obs[8].D.i, expected 3041, is {}",
                    msg.obs[8].D.i
                );
                assert_eq!(
                    msg.obs[8].L.f, 232,
                    "incorrect value for obs[8].L.f, expected 232, is {}",
                    msg.obs[8].L.f
                );
                assert_eq!(
                    msg.obs[8].L.i, 133443545,
                    "incorrect value for obs[8].L.i, expected 133443545, is {}",
                    msg.obs[8].L.i
                );
                assert_eq!(
                    msg.obs[8].P, 1269673181,
                    "incorrect value for obs[8].P, expected 1269673181, is {}",
                    msg.obs[8].P
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
                    msg.obs[9].D.f, 62,
                    "incorrect value for obs[9].D.f, expected 62, is {}",
                    msg.obs[9].D.f
                );
                assert_eq!(
                    msg.obs[9].D.i, 2374,
                    "incorrect value for obs[9].D.i, expected 2374, is {}",
                    msg.obs[9].D.i
                );
                assert_eq!(
                    msg.obs[9].L.f, 40,
                    "incorrect value for obs[9].L.f, expected 40, is {}",
                    msg.obs[9].L.f
                );
                assert_eq!(
                    msg.obs[9].L.i, 103982040,
                    "incorrect value for obs[9].L.i, expected 103982040, is {}",
                    msg.obs[9].L.i
                );
                assert_eq!(
                    msg.obs[9].P, 1269673722,
                    "incorrect value for obs[9].P, expected 1269673722, is {}",
                    msg.obs[9].P
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
                    msg.obs[10].D.f, 96,
                    "incorrect value for obs[10].D.f, expected 96, is {}",
                    msg.obs[10].D.f
                );
                assert_eq!(
                    msg.obs[10].D.i, -3446,
                    "incorrect value for obs[10].D.i, expected -3446, is {}",
                    msg.obs[10].D.i
                );
                assert_eq!(
                    msg.obs[10].L.f, 7,
                    "incorrect value for obs[10].L.f, expected 7, is {}",
                    msg.obs[10].L.f
                );
                assert_eq!(
                    msg.obs[10].L.i, 118217315,
                    "incorrect value for obs[10].L.i, expected 118217315, is {}",
                    msg.obs[10].L.i
                );
                assert_eq!(
                    msg.obs[10].P, 1107693703,
                    "incorrect value for obs[10].P, expected 1107693703, is {}",
                    msg.obs[10].P
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
                    msg.obs[11].D.f, 96,
                    "incorrect value for obs[11].D.f, expected 96, is {}",
                    msg.obs[11].D.f
                );
                assert_eq!(
                    msg.obs[11].D.i, -1003,
                    "incorrect value for obs[11].D.i, expected -1003, is {}",
                    msg.obs[11].D.i
                );
                assert_eq!(
                    msg.obs[11].L.f, 203,
                    "incorrect value for obs[11].L.f, expected 203, is {}",
                    msg.obs[11].L.f
                );
                assert_eq!(
                    msg.obs[11].L.i, 104224985,
                    "incorrect value for obs[11].L.i, expected 104224985, is {}",
                    msg.obs[11].L.i
                );
                assert_eq!(
                    msg.obs[11].P, 973505172,
                    "incorrect value for obs[11].P, expected 973505172, is {}",
                    msg.obs[11].P
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
                    msg.obs[12].D.f, 219,
                    "incorrect value for obs[12].D.f, expected 219, is {}",
                    msg.obs[12].D.f
                );
                assert_eq!(
                    msg.obs[12].D.i, -3836,
                    "incorrect value for obs[12].D.i, expected -3836, is {}",
                    msg.obs[12].D.i
                );
                assert_eq!(
                    msg.obs[12].L.f, 80,
                    "incorrect value for obs[12].L.f, expected 80, is {}",
                    msg.obs[12].L.f
                );
                assert_eq!(
                    msg.obs[12].L.i, 114505343,
                    "incorrect value for obs[12].L.i, expected 114505343, is {}",
                    msg.obs[12].L.i
                );
                assert_eq!(
                    msg.obs[12].P, 1069903034,
                    "incorrect value for obs[12].P, expected 1069903034, is {}",
                    msg.obs[12].P
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
                    msg.obs[13].D.f, 182,
                    "incorrect value for obs[13].D.f, expected 182, is {}",
                    msg.obs[13].D.f
                );
                assert_eq!(
                    msg.obs[13].D.i, -461,
                    "incorrect value for obs[13].D.i, expected -461, is {}",
                    msg.obs[13].D.i
                );
                assert_eq!(
                    msg.obs[13].L.f, 105,
                    "incorrect value for obs[13].L.f, expected 105, is {}",
                    msg.obs[13].L.f
                );
                assert_eq!(
                    msg.obs[13].L.i, 102157331,
                    "incorrect value for obs[13].L.i, expected 102157331, is {}",
                    msg.obs[13].L.i
                );
                assert_eq!(
                    msg.obs[13].P, 956875687,
                    "incorrect value for obs[13].P, expected 956875687, is {}",
                    msg.obs[13].P
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
        let frame = sbp_msg.to_frame().unwrap();
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
            sbp::messages::SBP::MsgObs(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x4a,
                    "Incorrect message type, expected 0x4a, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
