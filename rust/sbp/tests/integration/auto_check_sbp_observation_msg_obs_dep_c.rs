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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObsDepC.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_observation_msg_obs_dep_c() {
    {
        let mut payload = Cursor::new(vec![
            85, 73, 0, 70, 152, 87, 8, 95, 183, 24, 106, 7, 32, 126, 250, 73, 80, 113, 94, 247,
            255, 231, 163, 229, 229, 4, 0, 0, 0, 60, 220, 96, 70, 81, 147, 250, 255, 196, 208, 20,
            28, 6, 0, 0, 0, 248, 61, 62, 77, 28, 60, 242, 255, 110, 171, 180, 178, 7, 0, 0, 0, 237,
            84, 190, 77, 172, 37, 13, 0, 41, 170, 233, 164, 10, 0, 0, 0, 36, 85, 9, 75, 240, 188,
            21, 0, 19, 182, 196, 209, 12, 0, 0, 0, 190, 175,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgObsDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x49,
                    "Incorrect message type, expected 0x49, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x9846,
                    "incorrect sender id, expected 0x9846, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 32,
                    "incorrect value for header.n_obs, expected 32, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 414670600,
                    "incorrect value for header.t.tow, expected 414670600, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1898,
                    "incorrect value for header.t.wn, expected 1898, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].l.f, 231,
                    "incorrect value for obs[0].l.f, expected 231, is {}",
                    msg.obs[0].l.f
                );
                assert_eq!(
                    msg.obs[0].l.i, -565647,
                    "incorrect value for obs[0].l.i, expected -565647, is {}",
                    msg.obs[0].l.i
                );
                assert_eq!(
                    msg.obs[0].p, 1347025534,
                    "incorrect value for obs[0].p, expected 1347025534, is {}",
                    msg.obs[0].p
                );
                assert_eq!(
                    msg.obs[0].cn0, 163,
                    "incorrect value for obs[0].cn0, expected 163, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 58853,
                    "incorrect value for obs[0].lock, expected 58853, is {}",
                    msg.obs[0].lock
                );
                assert_eq!(
                    msg.obs[0].sid.code, 0,
                    "incorrect value for obs[0].sid.code, expected 0, is {}",
                    msg.obs[0].sid.code
                );
                assert_eq!(
                    msg.obs[0].sid.reserved, 0,
                    "incorrect value for obs[0].sid.reserved, expected 0, is {}",
                    msg.obs[0].sid.reserved
                );
                assert_eq!(
                    msg.obs[0].sid.sat, 4,
                    "incorrect value for obs[0].sid.sat, expected 4, is {}",
                    msg.obs[0].sid.sat
                );
                assert_eq!(
                    msg.obs[1].l.f, 196,
                    "incorrect value for obs[1].l.f, expected 196, is {}",
                    msg.obs[1].l.f
                );
                assert_eq!(
                    msg.obs[1].l.i, -355503,
                    "incorrect value for obs[1].l.i, expected -355503, is {}",
                    msg.obs[1].l.i
                );
                assert_eq!(
                    msg.obs[1].p, 1180752956,
                    "incorrect value for obs[1].p, expected 1180752956, is {}",
                    msg.obs[1].p
                );
                assert_eq!(
                    msg.obs[1].cn0, 208,
                    "incorrect value for obs[1].cn0, expected 208, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 7188,
                    "incorrect value for obs[1].lock, expected 7188, is {}",
                    msg.obs[1].lock
                );
                assert_eq!(
                    msg.obs[1].sid.code, 0,
                    "incorrect value for obs[1].sid.code, expected 0, is {}",
                    msg.obs[1].sid.code
                );
                assert_eq!(
                    msg.obs[1].sid.reserved, 0,
                    "incorrect value for obs[1].sid.reserved, expected 0, is {}",
                    msg.obs[1].sid.reserved
                );
                assert_eq!(
                    msg.obs[1].sid.sat, 6,
                    "incorrect value for obs[1].sid.sat, expected 6, is {}",
                    msg.obs[1].sid.sat
                );
                assert_eq!(
                    msg.obs[2].l.f, 110,
                    "incorrect value for obs[2].l.f, expected 110, is {}",
                    msg.obs[2].l.f
                );
                assert_eq!(
                    msg.obs[2].l.i, -902116,
                    "incorrect value for obs[2].l.i, expected -902116, is {}",
                    msg.obs[2].l.i
                );
                assert_eq!(
                    msg.obs[2].p, 1295924728,
                    "incorrect value for obs[2].p, expected 1295924728, is {}",
                    msg.obs[2].p
                );
                assert_eq!(
                    msg.obs[2].cn0, 171,
                    "incorrect value for obs[2].cn0, expected 171, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 45748,
                    "incorrect value for obs[2].lock, expected 45748, is {}",
                    msg.obs[2].lock
                );
                assert_eq!(
                    msg.obs[2].sid.code, 0,
                    "incorrect value for obs[2].sid.code, expected 0, is {}",
                    msg.obs[2].sid.code
                );
                assert_eq!(
                    msg.obs[2].sid.reserved, 0,
                    "incorrect value for obs[2].sid.reserved, expected 0, is {}",
                    msg.obs[2].sid.reserved
                );
                assert_eq!(
                    msg.obs[2].sid.sat, 7,
                    "incorrect value for obs[2].sid.sat, expected 7, is {}",
                    msg.obs[2].sid.sat
                );
                assert_eq!(
                    msg.obs[3].l.f, 41,
                    "incorrect value for obs[3].l.f, expected 41, is {}",
                    msg.obs[3].l.f
                );
                assert_eq!(
                    msg.obs[3].l.i, 861612,
                    "incorrect value for obs[3].l.i, expected 861612, is {}",
                    msg.obs[3].l.i
                );
                assert_eq!(
                    msg.obs[3].p, 1304319213,
                    "incorrect value for obs[3].p, expected 1304319213, is {}",
                    msg.obs[3].p
                );
                assert_eq!(
                    msg.obs[3].cn0, 170,
                    "incorrect value for obs[3].cn0, expected 170, is {}",
                    msg.obs[3].cn0
                );
                assert_eq!(
                    msg.obs[3].lock, 42217,
                    "incorrect value for obs[3].lock, expected 42217, is {}",
                    msg.obs[3].lock
                );
                assert_eq!(
                    msg.obs[3].sid.code, 0,
                    "incorrect value for obs[3].sid.code, expected 0, is {}",
                    msg.obs[3].sid.code
                );
                assert_eq!(
                    msg.obs[3].sid.reserved, 0,
                    "incorrect value for obs[3].sid.reserved, expected 0, is {}",
                    msg.obs[3].sid.reserved
                );
                assert_eq!(
                    msg.obs[3].sid.sat, 10,
                    "incorrect value for obs[3].sid.sat, expected 10, is {}",
                    msg.obs[3].sid.sat
                );
                assert_eq!(
                    msg.obs[4].l.f, 19,
                    "incorrect value for obs[4].l.f, expected 19, is {}",
                    msg.obs[4].l.f
                );
                assert_eq!(
                    msg.obs[4].l.i, 1424624,
                    "incorrect value for obs[4].l.i, expected 1424624, is {}",
                    msg.obs[4].l.i
                );
                assert_eq!(
                    msg.obs[4].p, 1258902820,
                    "incorrect value for obs[4].p, expected 1258902820, is {}",
                    msg.obs[4].p
                );
                assert_eq!(
                    msg.obs[4].cn0, 182,
                    "incorrect value for obs[4].cn0, expected 182, is {}",
                    msg.obs[4].cn0
                );
                assert_eq!(
                    msg.obs[4].lock, 53700,
                    "incorrect value for obs[4].lock, expected 53700, is {}",
                    msg.obs[4].lock
                );
                assert_eq!(
                    msg.obs[4].sid.code, 0,
                    "incorrect value for obs[4].sid.code, expected 0, is {}",
                    msg.obs[4].sid.code
                );
                assert_eq!(
                    msg.obs[4].sid.reserved, 0,
                    "incorrect value for obs[4].sid.reserved, expected 0, is {}",
                    msg.obs[4].sid.reserved
                );
                assert_eq!(
                    msg.obs[4].sid.sat, 12,
                    "incorrect value for obs[4].sid.sat, expected 12, is {}",
                    msg.obs[4].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepC"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 73, 0, 70, 152, 55, 8, 95, 183, 24, 106, 7, 33, 68, 166, 75, 77, 186, 230, 24, 0,
            101, 186, 162, 102, 16, 0, 0, 0, 87, 255, 155, 69, 74, 158, 5, 0, 26, 190, 206, 30, 27,
            0, 0, 0, 64, 89, 124, 68, 26, 22, 3, 0, 114, 217, 225, 73, 29, 0, 0, 0, 37, 179,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgObsDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x49,
                    "Incorrect message type, expected 0x49, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x9846,
                    "incorrect sender id, expected 0x9846, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 33,
                    "incorrect value for header.n_obs, expected 33, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 414670600,
                    "incorrect value for header.t.tow, expected 414670600, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1898,
                    "incorrect value for header.t.wn, expected 1898, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].l.f, 101,
                    "incorrect value for obs[0].l.f, expected 101, is {}",
                    msg.obs[0].l.f
                );
                assert_eq!(
                    msg.obs[0].l.i, 1631930,
                    "incorrect value for obs[0].l.i, expected 1631930, is {}",
                    msg.obs[0].l.i
                );
                assert_eq!(
                    msg.obs[0].p, 1296803396,
                    "incorrect value for obs[0].p, expected 1296803396, is {}",
                    msg.obs[0].p
                );
                assert_eq!(
                    msg.obs[0].cn0, 186,
                    "incorrect value for obs[0].cn0, expected 186, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 26274,
                    "incorrect value for obs[0].lock, expected 26274, is {}",
                    msg.obs[0].lock
                );
                assert_eq!(
                    msg.obs[0].sid.code, 0,
                    "incorrect value for obs[0].sid.code, expected 0, is {}",
                    msg.obs[0].sid.code
                );
                assert_eq!(
                    msg.obs[0].sid.reserved, 0,
                    "incorrect value for obs[0].sid.reserved, expected 0, is {}",
                    msg.obs[0].sid.reserved
                );
                assert_eq!(
                    msg.obs[0].sid.sat, 16,
                    "incorrect value for obs[0].sid.sat, expected 16, is {}",
                    msg.obs[0].sid.sat
                );
                assert_eq!(
                    msg.obs[1].l.f, 26,
                    "incorrect value for obs[1].l.f, expected 26, is {}",
                    msg.obs[1].l.f
                );
                assert_eq!(
                    msg.obs[1].l.i, 368202,
                    "incorrect value for obs[1].l.i, expected 368202, is {}",
                    msg.obs[1].l.i
                );
                assert_eq!(
                    msg.obs[1].p, 1167851351,
                    "incorrect value for obs[1].p, expected 1167851351, is {}",
                    msg.obs[1].p
                );
                assert_eq!(
                    msg.obs[1].cn0, 190,
                    "incorrect value for obs[1].cn0, expected 190, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 7886,
                    "incorrect value for obs[1].lock, expected 7886, is {}",
                    msg.obs[1].lock
                );
                assert_eq!(
                    msg.obs[1].sid.code, 0,
                    "incorrect value for obs[1].sid.code, expected 0, is {}",
                    msg.obs[1].sid.code
                );
                assert_eq!(
                    msg.obs[1].sid.reserved, 0,
                    "incorrect value for obs[1].sid.reserved, expected 0, is {}",
                    msg.obs[1].sid.reserved
                );
                assert_eq!(
                    msg.obs[1].sid.sat, 27,
                    "incorrect value for obs[1].sid.sat, expected 27, is {}",
                    msg.obs[1].sid.sat
                );
                assert_eq!(
                    msg.obs[2].l.f, 114,
                    "incorrect value for obs[2].l.f, expected 114, is {}",
                    msg.obs[2].l.f
                );
                assert_eq!(
                    msg.obs[2].l.i, 202266,
                    "incorrect value for obs[2].l.i, expected 202266, is {}",
                    msg.obs[2].l.i
                );
                assert_eq!(
                    msg.obs[2].p, 1149000000,
                    "incorrect value for obs[2].p, expected 1149000000, is {}",
                    msg.obs[2].p
                );
                assert_eq!(
                    msg.obs[2].cn0, 217,
                    "incorrect value for obs[2].cn0, expected 217, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 18913,
                    "incorrect value for obs[2].lock, expected 18913, is {}",
                    msg.obs[2].lock
                );
                assert_eq!(
                    msg.obs[2].sid.code, 0,
                    "incorrect value for obs[2].sid.code, expected 0, is {}",
                    msg.obs[2].sid.code
                );
                assert_eq!(
                    msg.obs[2].sid.reserved, 0,
                    "incorrect value for obs[2].sid.reserved, expected 0, is {}",
                    msg.obs[2].sid.reserved
                );
                assert_eq!(
                    msg.obs[2].sid.sat, 29,
                    "incorrect value for obs[2].sid.sat, expected 29, is {}",
                    msg.obs[2].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepC"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 73, 0, 0, 0, 87, 8, 95, 183, 24, 106, 7, 32, 217, 251, 73, 80, 9, 72, 248, 255, 30,
            168, 113, 81, 4, 0, 0, 0, 211, 220, 96, 70, 198, 107, 251, 255, 115, 195, 53, 144, 6,
            0, 0, 0, 77, 61, 62, 77, 40, 161, 243, 255, 130, 176, 93, 142, 7, 0, 0, 0, 1, 86, 190,
            77, 88, 77, 12, 0, 116, 199, 229, 213, 10, 0, 0, 0, 93, 85, 9, 75, 64, 139, 20, 0, 120,
            177, 196, 194, 12, 0, 0, 0, 141, 161,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgObsDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x49,
                    "Incorrect message type, expected 0x49, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0,
                    "incorrect sender id, expected 0x0, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 32,
                    "incorrect value for header.n_obs, expected 32, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 414670600,
                    "incorrect value for header.t.tow, expected 414670600, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1898,
                    "incorrect value for header.t.wn, expected 1898, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].l.f, 30,
                    "incorrect value for obs[0].l.f, expected 30, is {}",
                    msg.obs[0].l.f
                );
                assert_eq!(
                    msg.obs[0].l.i, -505847,
                    "incorrect value for obs[0].l.i, expected -505847, is {}",
                    msg.obs[0].l.i
                );
                assert_eq!(
                    msg.obs[0].p, 1347025881,
                    "incorrect value for obs[0].p, expected 1347025881, is {}",
                    msg.obs[0].p
                );
                assert_eq!(
                    msg.obs[0].cn0, 168,
                    "incorrect value for obs[0].cn0, expected 168, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 20849,
                    "incorrect value for obs[0].lock, expected 20849, is {}",
                    msg.obs[0].lock
                );
                assert_eq!(
                    msg.obs[0].sid.code, 0,
                    "incorrect value for obs[0].sid.code, expected 0, is {}",
                    msg.obs[0].sid.code
                );
                assert_eq!(
                    msg.obs[0].sid.reserved, 0,
                    "incorrect value for obs[0].sid.reserved, expected 0, is {}",
                    msg.obs[0].sid.reserved
                );
                assert_eq!(
                    msg.obs[0].sid.sat, 4,
                    "incorrect value for obs[0].sid.sat, expected 4, is {}",
                    msg.obs[0].sid.sat
                );
                assert_eq!(
                    msg.obs[1].l.f, 115,
                    "incorrect value for obs[1].l.f, expected 115, is {}",
                    msg.obs[1].l.f
                );
                assert_eq!(
                    msg.obs[1].l.i, -300090,
                    "incorrect value for obs[1].l.i, expected -300090, is {}",
                    msg.obs[1].l.i
                );
                assert_eq!(
                    msg.obs[1].p, 1180753107,
                    "incorrect value for obs[1].p, expected 1180753107, is {}",
                    msg.obs[1].p
                );
                assert_eq!(
                    msg.obs[1].cn0, 195,
                    "incorrect value for obs[1].cn0, expected 195, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 36917,
                    "incorrect value for obs[1].lock, expected 36917, is {}",
                    msg.obs[1].lock
                );
                assert_eq!(
                    msg.obs[1].sid.code, 0,
                    "incorrect value for obs[1].sid.code, expected 0, is {}",
                    msg.obs[1].sid.code
                );
                assert_eq!(
                    msg.obs[1].sid.reserved, 0,
                    "incorrect value for obs[1].sid.reserved, expected 0, is {}",
                    msg.obs[1].sid.reserved
                );
                assert_eq!(
                    msg.obs[1].sid.sat, 6,
                    "incorrect value for obs[1].sid.sat, expected 6, is {}",
                    msg.obs[1].sid.sat
                );
                assert_eq!(
                    msg.obs[2].l.f, 130,
                    "incorrect value for obs[2].l.f, expected 130, is {}",
                    msg.obs[2].l.f
                );
                assert_eq!(
                    msg.obs[2].l.i, -810712,
                    "incorrect value for obs[2].l.i, expected -810712, is {}",
                    msg.obs[2].l.i
                );
                assert_eq!(
                    msg.obs[2].p, 1295924557,
                    "incorrect value for obs[2].p, expected 1295924557, is {}",
                    msg.obs[2].p
                );
                assert_eq!(
                    msg.obs[2].cn0, 176,
                    "incorrect value for obs[2].cn0, expected 176, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 36445,
                    "incorrect value for obs[2].lock, expected 36445, is {}",
                    msg.obs[2].lock
                );
                assert_eq!(
                    msg.obs[2].sid.code, 0,
                    "incorrect value for obs[2].sid.code, expected 0, is {}",
                    msg.obs[2].sid.code
                );
                assert_eq!(
                    msg.obs[2].sid.reserved, 0,
                    "incorrect value for obs[2].sid.reserved, expected 0, is {}",
                    msg.obs[2].sid.reserved
                );
                assert_eq!(
                    msg.obs[2].sid.sat, 7,
                    "incorrect value for obs[2].sid.sat, expected 7, is {}",
                    msg.obs[2].sid.sat
                );
                assert_eq!(
                    msg.obs[3].l.f, 116,
                    "incorrect value for obs[3].l.f, expected 116, is {}",
                    msg.obs[3].l.f
                );
                assert_eq!(
                    msg.obs[3].l.i, 806232,
                    "incorrect value for obs[3].l.i, expected 806232, is {}",
                    msg.obs[3].l.i
                );
                assert_eq!(
                    msg.obs[3].p, 1304319489,
                    "incorrect value for obs[3].p, expected 1304319489, is {}",
                    msg.obs[3].p
                );
                assert_eq!(
                    msg.obs[3].cn0, 199,
                    "incorrect value for obs[3].cn0, expected 199, is {}",
                    msg.obs[3].cn0
                );
                assert_eq!(
                    msg.obs[3].lock, 54757,
                    "incorrect value for obs[3].lock, expected 54757, is {}",
                    msg.obs[3].lock
                );
                assert_eq!(
                    msg.obs[3].sid.code, 0,
                    "incorrect value for obs[3].sid.code, expected 0, is {}",
                    msg.obs[3].sid.code
                );
                assert_eq!(
                    msg.obs[3].sid.reserved, 0,
                    "incorrect value for obs[3].sid.reserved, expected 0, is {}",
                    msg.obs[3].sid.reserved
                );
                assert_eq!(
                    msg.obs[3].sid.sat, 10,
                    "incorrect value for obs[3].sid.sat, expected 10, is {}",
                    msg.obs[3].sid.sat
                );
                assert_eq!(
                    msg.obs[4].l.f, 120,
                    "incorrect value for obs[4].l.f, expected 120, is {}",
                    msg.obs[4].l.f
                );
                assert_eq!(
                    msg.obs[4].l.i, 1346368,
                    "incorrect value for obs[4].l.i, expected 1346368, is {}",
                    msg.obs[4].l.i
                );
                assert_eq!(
                    msg.obs[4].p, 1258902877,
                    "incorrect value for obs[4].p, expected 1258902877, is {}",
                    msg.obs[4].p
                );
                assert_eq!(
                    msg.obs[4].cn0, 177,
                    "incorrect value for obs[4].cn0, expected 177, is {}",
                    msg.obs[4].cn0
                );
                assert_eq!(
                    msg.obs[4].lock, 49860,
                    "incorrect value for obs[4].lock, expected 49860, is {}",
                    msg.obs[4].lock
                );
                assert_eq!(
                    msg.obs[4].sid.code, 0,
                    "incorrect value for obs[4].sid.code, expected 0, is {}",
                    msg.obs[4].sid.code
                );
                assert_eq!(
                    msg.obs[4].sid.reserved, 0,
                    "incorrect value for obs[4].sid.reserved, expected 0, is {}",
                    msg.obs[4].sid.reserved
                );
                assert_eq!(
                    msg.obs[4].sid.sat, 12,
                    "incorrect value for obs[4].sid.sat, expected 12, is {}",
                    msg.obs[4].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepC"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 73, 0, 0, 0, 55, 8, 95, 183, 24, 106, 7, 33, 70, 167, 75, 77, 140, 136, 23, 0, 90,
            187, 158, 129, 16, 0, 0, 0, 232, 255, 155, 69, 45, 175, 5, 0, 17, 208, 175, 56, 27, 0,
            0, 0, 64, 89, 124, 68, 45, 96, 3, 0, 75, 185, 73, 206, 29, 0, 0, 0, 220, 158,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgObsDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x49,
                    "Incorrect message type, expected 0x49, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0,
                    "incorrect sender id, expected 0x0, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 33,
                    "incorrect value for header.n_obs, expected 33, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 414670600,
                    "incorrect value for header.t.tow, expected 414670600, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1898,
                    "incorrect value for header.t.wn, expected 1898, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].l.f, 90,
                    "incorrect value for obs[0].l.f, expected 90, is {}",
                    msg.obs[0].l.f
                );
                assert_eq!(
                    msg.obs[0].l.i, 1542284,
                    "incorrect value for obs[0].l.i, expected 1542284, is {}",
                    msg.obs[0].l.i
                );
                assert_eq!(
                    msg.obs[0].p, 1296803654,
                    "incorrect value for obs[0].p, expected 1296803654, is {}",
                    msg.obs[0].p
                );
                assert_eq!(
                    msg.obs[0].cn0, 187,
                    "incorrect value for obs[0].cn0, expected 187, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 33182,
                    "incorrect value for obs[0].lock, expected 33182, is {}",
                    msg.obs[0].lock
                );
                assert_eq!(
                    msg.obs[0].sid.code, 0,
                    "incorrect value for obs[0].sid.code, expected 0, is {}",
                    msg.obs[0].sid.code
                );
                assert_eq!(
                    msg.obs[0].sid.reserved, 0,
                    "incorrect value for obs[0].sid.reserved, expected 0, is {}",
                    msg.obs[0].sid.reserved
                );
                assert_eq!(
                    msg.obs[0].sid.sat, 16,
                    "incorrect value for obs[0].sid.sat, expected 16, is {}",
                    msg.obs[0].sid.sat
                );
                assert_eq!(
                    msg.obs[1].l.f, 17,
                    "incorrect value for obs[1].l.f, expected 17, is {}",
                    msg.obs[1].l.f
                );
                assert_eq!(
                    msg.obs[1].l.i, 372525,
                    "incorrect value for obs[1].l.i, expected 372525, is {}",
                    msg.obs[1].l.i
                );
                assert_eq!(
                    msg.obs[1].p, 1167851496,
                    "incorrect value for obs[1].p, expected 1167851496, is {}",
                    msg.obs[1].p
                );
                assert_eq!(
                    msg.obs[1].cn0, 208,
                    "incorrect value for obs[1].cn0, expected 208, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 14511,
                    "incorrect value for obs[1].lock, expected 14511, is {}",
                    msg.obs[1].lock
                );
                assert_eq!(
                    msg.obs[1].sid.code, 0,
                    "incorrect value for obs[1].sid.code, expected 0, is {}",
                    msg.obs[1].sid.code
                );
                assert_eq!(
                    msg.obs[1].sid.reserved, 0,
                    "incorrect value for obs[1].sid.reserved, expected 0, is {}",
                    msg.obs[1].sid.reserved
                );
                assert_eq!(
                    msg.obs[1].sid.sat, 27,
                    "incorrect value for obs[1].sid.sat, expected 27, is {}",
                    msg.obs[1].sid.sat
                );
                assert_eq!(
                    msg.obs[2].l.f, 75,
                    "incorrect value for obs[2].l.f, expected 75, is {}",
                    msg.obs[2].l.f
                );
                assert_eq!(
                    msg.obs[2].l.i, 221229,
                    "incorrect value for obs[2].l.i, expected 221229, is {}",
                    msg.obs[2].l.i
                );
                assert_eq!(
                    msg.obs[2].p, 1149000000,
                    "incorrect value for obs[2].p, expected 1149000000, is {}",
                    msg.obs[2].p
                );
                assert_eq!(
                    msg.obs[2].cn0, 185,
                    "incorrect value for obs[2].cn0, expected 185, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 52809,
                    "incorrect value for obs[2].lock, expected 52809, is {}",
                    msg.obs[2].lock
                );
                assert_eq!(
                    msg.obs[2].sid.code, 0,
                    "incorrect value for obs[2].sid.code, expected 0, is {}",
                    msg.obs[2].sid.code
                );
                assert_eq!(
                    msg.obs[2].sid.reserved, 0,
                    "incorrect value for obs[2].sid.reserved, expected 0, is {}",
                    msg.obs[2].sid.reserved
                );
                assert_eq!(
                    msg.obs[2].sid.sat, 29,
                    "incorrect value for obs[2].sid.sat, expected 29, is {}",
                    msg.obs[2].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepC"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 73, 0, 70, 152, 87, 208, 95, 183, 24, 106, 7, 32, 44, 8, 74, 80, 86, 93, 247, 255,
            57, 158, 229, 229, 4, 0, 0, 0, 224, 229, 96, 70, 156, 146, 250, 255, 221, 200, 20, 28,
            6, 0, 0, 0, 60, 82, 62, 77, 93, 58, 242, 255, 39, 164, 180, 178, 7, 0, 0, 0, 222, 73,
            190, 77, 46, 39, 13, 0, 202, 181, 233, 164, 10, 0, 0, 0, 149, 64, 9, 75, 114, 191, 21,
            0, 249, 182, 196, 209, 12, 0, 0, 0, 112, 8,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgObsDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x49,
                    "Incorrect message type, expected 0x49, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x9846,
                    "incorrect sender id, expected 0x9846, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 32,
                    "incorrect value for header.n_obs, expected 32, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 414670800,
                    "incorrect value for header.t.tow, expected 414670800, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1898,
                    "incorrect value for header.t.wn, expected 1898, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].l.f, 57,
                    "incorrect value for obs[0].l.f, expected 57, is {}",
                    msg.obs[0].l.f
                );
                assert_eq!(
                    msg.obs[0].l.i, -565930,
                    "incorrect value for obs[0].l.i, expected -565930, is {}",
                    msg.obs[0].l.i
                );
                assert_eq!(
                    msg.obs[0].p, 1347029036,
                    "incorrect value for obs[0].p, expected 1347029036, is {}",
                    msg.obs[0].p
                );
                assert_eq!(
                    msg.obs[0].cn0, 158,
                    "incorrect value for obs[0].cn0, expected 158, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 58853,
                    "incorrect value for obs[0].lock, expected 58853, is {}",
                    msg.obs[0].lock
                );
                assert_eq!(
                    msg.obs[0].sid.code, 0,
                    "incorrect value for obs[0].sid.code, expected 0, is {}",
                    msg.obs[0].sid.code
                );
                assert_eq!(
                    msg.obs[0].sid.reserved, 0,
                    "incorrect value for obs[0].sid.reserved, expected 0, is {}",
                    msg.obs[0].sid.reserved
                );
                assert_eq!(
                    msg.obs[0].sid.sat, 4,
                    "incorrect value for obs[0].sid.sat, expected 4, is {}",
                    msg.obs[0].sid.sat
                );
                assert_eq!(
                    msg.obs[1].l.f, 221,
                    "incorrect value for obs[1].l.f, expected 221, is {}",
                    msg.obs[1].l.f
                );
                assert_eq!(
                    msg.obs[1].l.i, -355684,
                    "incorrect value for obs[1].l.i, expected -355684, is {}",
                    msg.obs[1].l.i
                );
                assert_eq!(
                    msg.obs[1].p, 1180755424,
                    "incorrect value for obs[1].p, expected 1180755424, is {}",
                    msg.obs[1].p
                );
                assert_eq!(
                    msg.obs[1].cn0, 200,
                    "incorrect value for obs[1].cn0, expected 200, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 7188,
                    "incorrect value for obs[1].lock, expected 7188, is {}",
                    msg.obs[1].lock
                );
                assert_eq!(
                    msg.obs[1].sid.code, 0,
                    "incorrect value for obs[1].sid.code, expected 0, is {}",
                    msg.obs[1].sid.code
                );
                assert_eq!(
                    msg.obs[1].sid.reserved, 0,
                    "incorrect value for obs[1].sid.reserved, expected 0, is {}",
                    msg.obs[1].sid.reserved
                );
                assert_eq!(
                    msg.obs[1].sid.sat, 6,
                    "incorrect value for obs[1].sid.sat, expected 6, is {}",
                    msg.obs[1].sid.sat
                );
                assert_eq!(
                    msg.obs[2].l.f, 39,
                    "incorrect value for obs[2].l.f, expected 39, is {}",
                    msg.obs[2].l.f
                );
                assert_eq!(
                    msg.obs[2].l.i, -902563,
                    "incorrect value for obs[2].l.i, expected -902563, is {}",
                    msg.obs[2].l.i
                );
                assert_eq!(
                    msg.obs[2].p, 1295929916,
                    "incorrect value for obs[2].p, expected 1295929916, is {}",
                    msg.obs[2].p
                );
                assert_eq!(
                    msg.obs[2].cn0, 164,
                    "incorrect value for obs[2].cn0, expected 164, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 45748,
                    "incorrect value for obs[2].lock, expected 45748, is {}",
                    msg.obs[2].lock
                );
                assert_eq!(
                    msg.obs[2].sid.code, 0,
                    "incorrect value for obs[2].sid.code, expected 0, is {}",
                    msg.obs[2].sid.code
                );
                assert_eq!(
                    msg.obs[2].sid.reserved, 0,
                    "incorrect value for obs[2].sid.reserved, expected 0, is {}",
                    msg.obs[2].sid.reserved
                );
                assert_eq!(
                    msg.obs[2].sid.sat, 7,
                    "incorrect value for obs[2].sid.sat, expected 7, is {}",
                    msg.obs[2].sid.sat
                );
                assert_eq!(
                    msg.obs[3].l.f, 202,
                    "incorrect value for obs[3].l.f, expected 202, is {}",
                    msg.obs[3].l.f
                );
                assert_eq!(
                    msg.obs[3].l.i, 861998,
                    "incorrect value for obs[3].l.i, expected 861998, is {}",
                    msg.obs[3].l.i
                );
                assert_eq!(
                    msg.obs[3].p, 1304316382,
                    "incorrect value for obs[3].p, expected 1304316382, is {}",
                    msg.obs[3].p
                );
                assert_eq!(
                    msg.obs[3].cn0, 181,
                    "incorrect value for obs[3].cn0, expected 181, is {}",
                    msg.obs[3].cn0
                );
                assert_eq!(
                    msg.obs[3].lock, 42217,
                    "incorrect value for obs[3].lock, expected 42217, is {}",
                    msg.obs[3].lock
                );
                assert_eq!(
                    msg.obs[3].sid.code, 0,
                    "incorrect value for obs[3].sid.code, expected 0, is {}",
                    msg.obs[3].sid.code
                );
                assert_eq!(
                    msg.obs[3].sid.reserved, 0,
                    "incorrect value for obs[3].sid.reserved, expected 0, is {}",
                    msg.obs[3].sid.reserved
                );
                assert_eq!(
                    msg.obs[3].sid.sat, 10,
                    "incorrect value for obs[3].sid.sat, expected 10, is {}",
                    msg.obs[3].sid.sat
                );
                assert_eq!(
                    msg.obs[4].l.f, 249,
                    "incorrect value for obs[4].l.f, expected 249, is {}",
                    msg.obs[4].l.f
                );
                assert_eq!(
                    msg.obs[4].l.i, 1425266,
                    "incorrect value for obs[4].l.i, expected 1425266, is {}",
                    msg.obs[4].l.i
                );
                assert_eq!(
                    msg.obs[4].p, 1258897557,
                    "incorrect value for obs[4].p, expected 1258897557, is {}",
                    msg.obs[4].p
                );
                assert_eq!(
                    msg.obs[4].cn0, 182,
                    "incorrect value for obs[4].cn0, expected 182, is {}",
                    msg.obs[4].cn0
                );
                assert_eq!(
                    msg.obs[4].lock, 53700,
                    "incorrect value for obs[4].lock, expected 53700, is {}",
                    msg.obs[4].lock
                );
                assert_eq!(
                    msg.obs[4].sid.code, 0,
                    "incorrect value for obs[4].sid.code, expected 0, is {}",
                    msg.obs[4].sid.code
                );
                assert_eq!(
                    msg.obs[4].sid.reserved, 0,
                    "incorrect value for obs[4].sid.reserved, expected 0, is {}",
                    msg.obs[4].sid.reserved
                );
                assert_eq!(
                    msg.obs[4].sid.sat, 12,
                    "incorrect value for obs[4].sid.sat, expected 12, is {}",
                    msg.obs[4].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepC"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
