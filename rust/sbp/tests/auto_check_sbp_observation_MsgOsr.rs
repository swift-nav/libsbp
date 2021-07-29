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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgOsr.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_observation_MsgOsr() {
    {
        let mut payload = Cursor::new(vec![
            85, 64, 6, 0, 0, 239, 248, 225, 233, 29, 0, 0, 0, 0, 104, 8, 64, 75, 143, 241, 68, 230,
            250, 62, 7, 66, 15, 3, 1, 0, 13, 0, 7, 0, 7, 0, 206, 232, 105, 63, 236, 49, 170, 6, 75,
            15, 3, 13, 0, 13, 0, 3, 0, 3, 0, 45, 145, 198, 62, 33, 7, 153, 6, 128, 15, 3, 14, 0,
            13, 0, 3, 0, 3, 0, 89, 132, 204, 67, 143, 46, 32, 7, 127, 15, 3, 15, 0, 13, 0, 5, 0, 5,
            0, 244, 254, 164, 60, 22, 176, 95, 6, 55, 15, 3, 17, 0, 0, 0, 2, 0, 2, 0, 106, 157,
            101, 62, 151, 214, 142, 6, 108, 15, 3, 19, 0, 13, 0, 3, 0, 3, 0, 81, 237, 60, 63, 181,
            119, 165, 6, 206, 15, 3, 28, 0, 13, 0, 3, 0, 3, 0, 134, 228, 110, 64, 183, 159, 197, 6,
            200, 15, 3, 30, 0, 13, 0, 3, 0, 3, 0, 53, 144, 241, 68, 78, 112, 165, 5, 170, 15, 3, 1,
            6, 21, 0, 7, 0, 7, 0, 251, 232, 105, 63, 163, 128, 49, 5, 129, 15, 3, 13, 6, 21, 0, 3,
            0, 3, 0, 112, 145, 198, 62, 37, 32, 36, 5, 46, 15, 3, 14, 6, 21, 0, 3, 0, 3, 0, 166,
            132, 204, 67, 184, 112, 141, 5, 95, 15, 3, 15, 6, 21, 0, 5, 0, 5, 0, 121, 227,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgOsr(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x640,
                    "Incorrect message type, expected 0x640, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0,
                    "incorrect sender id, expected 0, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 64,
                    "incorrect value for header.n_obs, expected 64, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.ns_residual, 0,
                    "incorrect value for header.t.ns_residual, expected 0, is {}",
                    msg.header.t.ns_residual
                );
                assert_eq!(
                    msg.header.t.tow, 501867000,
                    "incorrect value for header.t.tow, expected 501867000, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 2152,
                    "incorrect value for header.t.wn, expected 2152, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].L.f, 66,
                    "incorrect value for obs[0].L.f, expected 66, is {}",
                    msg.obs[0].L.f
                );
                assert_eq!(
                    msg.obs[0].L.i, 121567974,
                    "incorrect value for obs[0].L.i, expected 121567974, is {}",
                    msg.obs[0].L.i
                );
                assert_eq!(
                    msg.obs[0].P, 1156681547,
                    "incorrect value for obs[0].P, expected 1156681547, is {}",
                    msg.obs[0].P
                );
                assert_eq!(
                    msg.obs[0].flags, 3,
                    "incorrect value for obs[0].flags, expected 3, is {}",
                    msg.obs[0].flags
                );
                assert_eq!(
                    msg.obs[0].iono_std, 13,
                    "incorrect value for obs[0].iono_std, expected 13, is {}",
                    msg.obs[0].iono_std
                );
                assert_eq!(
                    msg.obs[0].lock, 15,
                    "incorrect value for obs[0].lock, expected 15, is {}",
                    msg.obs[0].lock
                );
                assert_eq!(
                    msg.obs[0].range_std, 7,
                    "incorrect value for obs[0].range_std, expected 7, is {}",
                    msg.obs[0].range_std
                );
                assert_eq!(
                    msg.obs[0].sid.code, 0,
                    "incorrect value for obs[0].sid.code, expected 0, is {}",
                    msg.obs[0].sid.code
                );
                assert_eq!(
                    msg.obs[0].sid.sat, 1,
                    "incorrect value for obs[0].sid.sat, expected 1, is {}",
                    msg.obs[0].sid.sat
                );
                assert_eq!(
                    msg.obs[0].tropo_std, 7,
                    "incorrect value for obs[0].tropo_std, expected 7, is {}",
                    msg.obs[0].tropo_std
                );
                assert_eq!(
                    msg.obs[1].L.f, 75,
                    "incorrect value for obs[1].L.f, expected 75, is {}",
                    msg.obs[1].L.f
                );
                assert_eq!(
                    msg.obs[1].L.i, 111817196,
                    "incorrect value for obs[1].L.i, expected 111817196, is {}",
                    msg.obs[1].L.i
                );
                assert_eq!(
                    msg.obs[1].P, 1063905486,
                    "incorrect value for obs[1].P, expected 1063905486, is {}",
                    msg.obs[1].P
                );
                assert_eq!(
                    msg.obs[1].flags, 3,
                    "incorrect value for obs[1].flags, expected 3, is {}",
                    msg.obs[1].flags
                );
                assert_eq!(
                    msg.obs[1].iono_std, 13,
                    "incorrect value for obs[1].iono_std, expected 13, is {}",
                    msg.obs[1].iono_std
                );
                assert_eq!(
                    msg.obs[1].lock, 15,
                    "incorrect value for obs[1].lock, expected 15, is {}",
                    msg.obs[1].lock
                );
                assert_eq!(
                    msg.obs[1].range_std, 3,
                    "incorrect value for obs[1].range_std, expected 3, is {}",
                    msg.obs[1].range_std
                );
                assert_eq!(
                    msg.obs[1].sid.code, 0,
                    "incorrect value for obs[1].sid.code, expected 0, is {}",
                    msg.obs[1].sid.code
                );
                assert_eq!(
                    msg.obs[1].sid.sat, 13,
                    "incorrect value for obs[1].sid.sat, expected 13, is {}",
                    msg.obs[1].sid.sat
                );
                assert_eq!(
                    msg.obs[1].tropo_std, 3,
                    "incorrect value for obs[1].tropo_std, expected 3, is {}",
                    msg.obs[1].tropo_std
                );
                assert_eq!(
                    msg.obs[2].L.f, 128,
                    "incorrect value for obs[2].L.f, expected 128, is {}",
                    msg.obs[2].L.f
                );
                assert_eq!(
                    msg.obs[2].L.i, 110692129,
                    "incorrect value for obs[2].L.i, expected 110692129, is {}",
                    msg.obs[2].L.i
                );
                assert_eq!(
                    msg.obs[2].P, 1053200685,
                    "incorrect value for obs[2].P, expected 1053200685, is {}",
                    msg.obs[2].P
                );
                assert_eq!(
                    msg.obs[2].flags, 3,
                    "incorrect value for obs[2].flags, expected 3, is {}",
                    msg.obs[2].flags
                );
                assert_eq!(
                    msg.obs[2].iono_std, 13,
                    "incorrect value for obs[2].iono_std, expected 13, is {}",
                    msg.obs[2].iono_std
                );
                assert_eq!(
                    msg.obs[2].lock, 15,
                    "incorrect value for obs[2].lock, expected 15, is {}",
                    msg.obs[2].lock
                );
                assert_eq!(
                    msg.obs[2].range_std, 3,
                    "incorrect value for obs[2].range_std, expected 3, is {}",
                    msg.obs[2].range_std
                );
                assert_eq!(
                    msg.obs[2].sid.code, 0,
                    "incorrect value for obs[2].sid.code, expected 0, is {}",
                    msg.obs[2].sid.code
                );
                assert_eq!(
                    msg.obs[2].sid.sat, 14,
                    "incorrect value for obs[2].sid.sat, expected 14, is {}",
                    msg.obs[2].sid.sat
                );
                assert_eq!(
                    msg.obs[2].tropo_std, 3,
                    "incorrect value for obs[2].tropo_std, expected 3, is {}",
                    msg.obs[2].tropo_std
                );
                assert_eq!(
                    msg.obs[3].L.f, 127,
                    "incorrect value for obs[3].L.f, expected 127, is {}",
                    msg.obs[3].L.f
                );
                assert_eq!(
                    msg.obs[3].L.i, 119549583,
                    "incorrect value for obs[3].L.i, expected 119549583, is {}",
                    msg.obs[3].L.i
                );
                assert_eq!(
                    msg.obs[3].P, 1137476697,
                    "incorrect value for obs[3].P, expected 1137476697, is {}",
                    msg.obs[3].P
                );
                assert_eq!(
                    msg.obs[3].flags, 3,
                    "incorrect value for obs[3].flags, expected 3, is {}",
                    msg.obs[3].flags
                );
                assert_eq!(
                    msg.obs[3].iono_std, 13,
                    "incorrect value for obs[3].iono_std, expected 13, is {}",
                    msg.obs[3].iono_std
                );
                assert_eq!(
                    msg.obs[3].lock, 15,
                    "incorrect value for obs[3].lock, expected 15, is {}",
                    msg.obs[3].lock
                );
                assert_eq!(
                    msg.obs[3].range_std, 5,
                    "incorrect value for obs[3].range_std, expected 5, is {}",
                    msg.obs[3].range_std
                );
                assert_eq!(
                    msg.obs[3].sid.code, 0,
                    "incorrect value for obs[3].sid.code, expected 0, is {}",
                    msg.obs[3].sid.code
                );
                assert_eq!(
                    msg.obs[3].sid.sat, 15,
                    "incorrect value for obs[3].sid.sat, expected 15, is {}",
                    msg.obs[3].sid.sat
                );
                assert_eq!(
                    msg.obs[3].tropo_std, 5,
                    "incorrect value for obs[3].tropo_std, expected 5, is {}",
                    msg.obs[3].tropo_std
                );
                assert_eq!(
                    msg.obs[4].L.f, 55,
                    "incorrect value for obs[4].L.f, expected 55, is {}",
                    msg.obs[4].L.f
                );
                assert_eq!(
                    msg.obs[4].L.i, 106934294,
                    "incorrect value for obs[4].L.i, expected 106934294, is {}",
                    msg.obs[4].L.i
                );
                assert_eq!(
                    msg.obs[4].P, 1017446132,
                    "incorrect value for obs[4].P, expected 1017446132, is {}",
                    msg.obs[4].P
                );
                assert_eq!(
                    msg.obs[4].flags, 3,
                    "incorrect value for obs[4].flags, expected 3, is {}",
                    msg.obs[4].flags
                );
                assert_eq!(
                    msg.obs[4].iono_std, 0,
                    "incorrect value for obs[4].iono_std, expected 0, is {}",
                    msg.obs[4].iono_std
                );
                assert_eq!(
                    msg.obs[4].lock, 15,
                    "incorrect value for obs[4].lock, expected 15, is {}",
                    msg.obs[4].lock
                );
                assert_eq!(
                    msg.obs[4].range_std, 2,
                    "incorrect value for obs[4].range_std, expected 2, is {}",
                    msg.obs[4].range_std
                );
                assert_eq!(
                    msg.obs[4].sid.code, 0,
                    "incorrect value for obs[4].sid.code, expected 0, is {}",
                    msg.obs[4].sid.code
                );
                assert_eq!(
                    msg.obs[4].sid.sat, 17,
                    "incorrect value for obs[4].sid.sat, expected 17, is {}",
                    msg.obs[4].sid.sat
                );
                assert_eq!(
                    msg.obs[4].tropo_std, 2,
                    "incorrect value for obs[4].tropo_std, expected 2, is {}",
                    msg.obs[4].tropo_std
                );
                assert_eq!(
                    msg.obs[5].L.f, 108,
                    "incorrect value for obs[5].L.f, expected 108, is {}",
                    msg.obs[5].L.f
                );
                assert_eq!(
                    msg.obs[5].L.i, 110024343,
                    "incorrect value for obs[5].L.i, expected 110024343, is {}",
                    msg.obs[5].L.i
                );
                assert_eq!(
                    msg.obs[5].P, 1046846826,
                    "incorrect value for obs[5].P, expected 1046846826, is {}",
                    msg.obs[5].P
                );
                assert_eq!(
                    msg.obs[5].flags, 3,
                    "incorrect value for obs[5].flags, expected 3, is {}",
                    msg.obs[5].flags
                );
                assert_eq!(
                    msg.obs[5].iono_std, 13,
                    "incorrect value for obs[5].iono_std, expected 13, is {}",
                    msg.obs[5].iono_std
                );
                assert_eq!(
                    msg.obs[5].lock, 15,
                    "incorrect value for obs[5].lock, expected 15, is {}",
                    msg.obs[5].lock
                );
                assert_eq!(
                    msg.obs[5].range_std, 3,
                    "incorrect value for obs[5].range_std, expected 3, is {}",
                    msg.obs[5].range_std
                );
                assert_eq!(
                    msg.obs[5].sid.code, 0,
                    "incorrect value for obs[5].sid.code, expected 0, is {}",
                    msg.obs[5].sid.code
                );
                assert_eq!(
                    msg.obs[5].sid.sat, 19,
                    "incorrect value for obs[5].sid.sat, expected 19, is {}",
                    msg.obs[5].sid.sat
                );
                assert_eq!(
                    msg.obs[5].tropo_std, 3,
                    "incorrect value for obs[5].tropo_std, expected 3, is {}",
                    msg.obs[5].tropo_std
                );
                assert_eq!(
                    msg.obs[6].L.f, 206,
                    "incorrect value for obs[6].L.f, expected 206, is {}",
                    msg.obs[6].L.f
                );
                assert_eq!(
                    msg.obs[6].L.i, 111507381,
                    "incorrect value for obs[6].L.i, expected 111507381, is {}",
                    msg.obs[6].L.i
                );
                assert_eq!(
                    msg.obs[6].P, 1060957521,
                    "incorrect value for obs[6].P, expected 1060957521, is {}",
                    msg.obs[6].P
                );
                assert_eq!(
                    msg.obs[6].flags, 3,
                    "incorrect value for obs[6].flags, expected 3, is {}",
                    msg.obs[6].flags
                );
                assert_eq!(
                    msg.obs[6].iono_std, 13,
                    "incorrect value for obs[6].iono_std, expected 13, is {}",
                    msg.obs[6].iono_std
                );
                assert_eq!(
                    msg.obs[6].lock, 15,
                    "incorrect value for obs[6].lock, expected 15, is {}",
                    msg.obs[6].lock
                );
                assert_eq!(
                    msg.obs[6].range_std, 3,
                    "incorrect value for obs[6].range_std, expected 3, is {}",
                    msg.obs[6].range_std
                );
                assert_eq!(
                    msg.obs[6].sid.code, 0,
                    "incorrect value for obs[6].sid.code, expected 0, is {}",
                    msg.obs[6].sid.code
                );
                assert_eq!(
                    msg.obs[6].sid.sat, 28,
                    "incorrect value for obs[6].sid.sat, expected 28, is {}",
                    msg.obs[6].sid.sat
                );
                assert_eq!(
                    msg.obs[6].tropo_std, 3,
                    "incorrect value for obs[6].tropo_std, expected 3, is {}",
                    msg.obs[6].tropo_std
                );
                assert_eq!(
                    msg.obs[7].L.f, 200,
                    "incorrect value for obs[7].L.f, expected 200, is {}",
                    msg.obs[7].L.f
                );
                assert_eq!(
                    msg.obs[7].L.i, 113614775,
                    "incorrect value for obs[7].L.i, expected 113614775, is {}",
                    msg.obs[7].L.i
                );
                assert_eq!(
                    msg.obs[7].P, 1081009286,
                    "incorrect value for obs[7].P, expected 1081009286, is {}",
                    msg.obs[7].P
                );
                assert_eq!(
                    msg.obs[7].flags, 3,
                    "incorrect value for obs[7].flags, expected 3, is {}",
                    msg.obs[7].flags
                );
                assert_eq!(
                    msg.obs[7].iono_std, 13,
                    "incorrect value for obs[7].iono_std, expected 13, is {}",
                    msg.obs[7].iono_std
                );
                assert_eq!(
                    msg.obs[7].lock, 15,
                    "incorrect value for obs[7].lock, expected 15, is {}",
                    msg.obs[7].lock
                );
                assert_eq!(
                    msg.obs[7].range_std, 3,
                    "incorrect value for obs[7].range_std, expected 3, is {}",
                    msg.obs[7].range_std
                );
                assert_eq!(
                    msg.obs[7].sid.code, 0,
                    "incorrect value for obs[7].sid.code, expected 0, is {}",
                    msg.obs[7].sid.code
                );
                assert_eq!(
                    msg.obs[7].sid.sat, 30,
                    "incorrect value for obs[7].sid.sat, expected 30, is {}",
                    msg.obs[7].sid.sat
                );
                assert_eq!(
                    msg.obs[7].tropo_std, 3,
                    "incorrect value for obs[7].tropo_std, expected 3, is {}",
                    msg.obs[7].tropo_std
                );
                assert_eq!(
                    msg.obs[8].L.f, 170,
                    "incorrect value for obs[8].L.f, expected 170, is {}",
                    msg.obs[8].L.f
                );
                assert_eq!(
                    msg.obs[8].L.i, 94728270,
                    "incorrect value for obs[8].L.i, expected 94728270, is {}",
                    msg.obs[8].L.i
                );
                assert_eq!(
                    msg.obs[8].P, 1156681781,
                    "incorrect value for obs[8].P, expected 1156681781, is {}",
                    msg.obs[8].P
                );
                assert_eq!(
                    msg.obs[8].flags, 3,
                    "incorrect value for obs[8].flags, expected 3, is {}",
                    msg.obs[8].flags
                );
                assert_eq!(
                    msg.obs[8].iono_std, 21,
                    "incorrect value for obs[8].iono_std, expected 21, is {}",
                    msg.obs[8].iono_std
                );
                assert_eq!(
                    msg.obs[8].lock, 15,
                    "incorrect value for obs[8].lock, expected 15, is {}",
                    msg.obs[8].lock
                );
                assert_eq!(
                    msg.obs[8].range_std, 7,
                    "incorrect value for obs[8].range_std, expected 7, is {}",
                    msg.obs[8].range_std
                );
                assert_eq!(
                    msg.obs[8].sid.code, 6,
                    "incorrect value for obs[8].sid.code, expected 6, is {}",
                    msg.obs[8].sid.code
                );
                assert_eq!(
                    msg.obs[8].sid.sat, 1,
                    "incorrect value for obs[8].sid.sat, expected 1, is {}",
                    msg.obs[8].sid.sat
                );
                assert_eq!(
                    msg.obs[8].tropo_std, 7,
                    "incorrect value for obs[8].tropo_std, expected 7, is {}",
                    msg.obs[8].tropo_std
                );
                assert_eq!(
                    msg.obs[9].L.f, 129,
                    "incorrect value for obs[9].L.f, expected 129, is {}",
                    msg.obs[9].L.f
                );
                assert_eq!(
                    msg.obs[9].L.i, 87130275,
                    "incorrect value for obs[9].L.i, expected 87130275, is {}",
                    msg.obs[9].L.i
                );
                assert_eq!(
                    msg.obs[9].P, 1063905531,
                    "incorrect value for obs[9].P, expected 1063905531, is {}",
                    msg.obs[9].P
                );
                assert_eq!(
                    msg.obs[9].flags, 3,
                    "incorrect value for obs[9].flags, expected 3, is {}",
                    msg.obs[9].flags
                );
                assert_eq!(
                    msg.obs[9].iono_std, 21,
                    "incorrect value for obs[9].iono_std, expected 21, is {}",
                    msg.obs[9].iono_std
                );
                assert_eq!(
                    msg.obs[9].lock, 15,
                    "incorrect value for obs[9].lock, expected 15, is {}",
                    msg.obs[9].lock
                );
                assert_eq!(
                    msg.obs[9].range_std, 3,
                    "incorrect value for obs[9].range_std, expected 3, is {}",
                    msg.obs[9].range_std
                );
                assert_eq!(
                    msg.obs[9].sid.code, 6,
                    "incorrect value for obs[9].sid.code, expected 6, is {}",
                    msg.obs[9].sid.code
                );
                assert_eq!(
                    msg.obs[9].sid.sat, 13,
                    "incorrect value for obs[9].sid.sat, expected 13, is {}",
                    msg.obs[9].sid.sat
                );
                assert_eq!(
                    msg.obs[9].tropo_std, 3,
                    "incorrect value for obs[9].tropo_std, expected 3, is {}",
                    msg.obs[9].tropo_std
                );
                assert_eq!(
                    msg.obs[10].L.f, 46,
                    "incorrect value for obs[10].L.f, expected 46, is {}",
                    msg.obs[10].L.f
                );
                assert_eq!(
                    msg.obs[10].L.i, 86253605,
                    "incorrect value for obs[10].L.i, expected 86253605, is {}",
                    msg.obs[10].L.i
                );
                assert_eq!(
                    msg.obs[10].P, 1053200752,
                    "incorrect value for obs[10].P, expected 1053200752, is {}",
                    msg.obs[10].P
                );
                assert_eq!(
                    msg.obs[10].flags, 3,
                    "incorrect value for obs[10].flags, expected 3, is {}",
                    msg.obs[10].flags
                );
                assert_eq!(
                    msg.obs[10].iono_std, 21,
                    "incorrect value for obs[10].iono_std, expected 21, is {}",
                    msg.obs[10].iono_std
                );
                assert_eq!(
                    msg.obs[10].lock, 15,
                    "incorrect value for obs[10].lock, expected 15, is {}",
                    msg.obs[10].lock
                );
                assert_eq!(
                    msg.obs[10].range_std, 3,
                    "incorrect value for obs[10].range_std, expected 3, is {}",
                    msg.obs[10].range_std
                );
                assert_eq!(
                    msg.obs[10].sid.code, 6,
                    "incorrect value for obs[10].sid.code, expected 6, is {}",
                    msg.obs[10].sid.code
                );
                assert_eq!(
                    msg.obs[10].sid.sat, 14,
                    "incorrect value for obs[10].sid.sat, expected 14, is {}",
                    msg.obs[10].sid.sat
                );
                assert_eq!(
                    msg.obs[10].tropo_std, 3,
                    "incorrect value for obs[10].tropo_std, expected 3, is {}",
                    msg.obs[10].tropo_std
                );
                assert_eq!(
                    msg.obs[11].L.f, 95,
                    "incorrect value for obs[11].L.f, expected 95, is {}",
                    msg.obs[11].L.f
                );
                assert_eq!(
                    msg.obs[11].L.i, 93155512,
                    "incorrect value for obs[11].L.i, expected 93155512, is {}",
                    msg.obs[11].L.i
                );
                assert_eq!(
                    msg.obs[11].P, 1137476774,
                    "incorrect value for obs[11].P, expected 1137476774, is {}",
                    msg.obs[11].P
                );
                assert_eq!(
                    msg.obs[11].flags, 3,
                    "incorrect value for obs[11].flags, expected 3, is {}",
                    msg.obs[11].flags
                );
                assert_eq!(
                    msg.obs[11].iono_std, 21,
                    "incorrect value for obs[11].iono_std, expected 21, is {}",
                    msg.obs[11].iono_std
                );
                assert_eq!(
                    msg.obs[11].lock, 15,
                    "incorrect value for obs[11].lock, expected 15, is {}",
                    msg.obs[11].lock
                );
                assert_eq!(
                    msg.obs[11].range_std, 5,
                    "incorrect value for obs[11].range_std, expected 5, is {}",
                    msg.obs[11].range_std
                );
                assert_eq!(
                    msg.obs[11].sid.code, 6,
                    "incorrect value for obs[11].sid.code, expected 6, is {}",
                    msg.obs[11].sid.code
                );
                assert_eq!(
                    msg.obs[11].sid.sat, 15,
                    "incorrect value for obs[11].sid.sat, expected 15, is {}",
                    msg.obs[11].sid.sat
                );
                assert_eq!(
                    msg.obs[11].tropo_std, 5,
                    "incorrect value for obs[11].tropo_std, expected 5, is {}",
                    msg.obs[11].tropo_std
                );
            }
            _ => panic!("Invalid message type! Expected a MsgOsr"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
