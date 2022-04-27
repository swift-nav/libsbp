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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObsDepB.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_observation_msg_obs_dep_b() {
    {
        let mut payload = Cursor::new(vec![
            85, 67, 0, 246, 215, 103, 120, 46, 39, 0, 251, 6, 32, 180, 175, 187, 133, 223, 53, 7,
            7, 27, 157, 0, 0, 202, 0, 0, 0, 58, 140, 85, 147, 88, 28, 190, 7, 175, 144, 0, 0, 203,
            0, 0, 0, 220, 140, 248, 138, 208, 172, 77, 7, 135, 151, 0, 0, 208, 0, 0, 0, 173, 194,
            72, 135, 115, 18, 28, 7, 242, 156, 0, 0, 212, 0, 0, 0, 164, 144, 105, 124, 18, 196,
            137, 6, 120, 168, 0, 0, 217, 0, 0, 0, 30, 232, 228, 139, 210, 7, 90, 7, 87, 150, 0, 0,
            218, 0, 0, 0, 169, 85,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgObsDepB(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x43,
                    "Incorrect message type, expected 0x43, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 32,
                    "incorrect value for header.n_obs, expected 32, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 2567800,
                    "incorrect value for header.t.tow, expected 2567800, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1787,
                    "incorrect value for header.t.wn, expected 1787, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].l.f, 27,
                    "incorrect value for obs[0].l.f, expected 27, is {}",
                    msg.obs[0].l.f
                );
                assert_eq!(
                    msg.obs[0].l.i, 117913055,
                    "incorrect value for obs[0].l.i, expected 117913055, is {}",
                    msg.obs[0].l.i
                );
                assert_eq!(
                    msg.obs[0].p, 2243669940,
                    "incorrect value for obs[0].p, expected 2243669940, is {}",
                    msg.obs[0].p
                );
                assert_eq!(
                    msg.obs[0].cn0, 157,
                    "incorrect value for obs[0].cn0, expected 157, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 0,
                    "incorrect value for obs[0].lock, expected 0, is {}",
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
                    msg.obs[0].sid.sat, 202,
                    "incorrect value for obs[0].sid.sat, expected 202, is {}",
                    msg.obs[0].sid.sat
                );
                assert_eq!(
                    msg.obs[1].l.f, 175,
                    "incorrect value for obs[1].l.f, expected 175, is {}",
                    msg.obs[1].l.f
                );
                assert_eq!(
                    msg.obs[1].l.i, 129899608,
                    "incorrect value for obs[1].l.i, expected 129899608, is {}",
                    msg.obs[1].l.i
                );
                assert_eq!(
                    msg.obs[1].p, 2471857210,
                    "incorrect value for obs[1].p, expected 2471857210, is {}",
                    msg.obs[1].p
                );
                assert_eq!(
                    msg.obs[1].cn0, 144,
                    "incorrect value for obs[1].cn0, expected 144, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 0,
                    "incorrect value for obs[1].lock, expected 0, is {}",
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
                    msg.obs[1].sid.sat, 203,
                    "incorrect value for obs[1].sid.sat, expected 203, is {}",
                    msg.obs[1].sid.sat
                );
                assert_eq!(
                    msg.obs[2].l.f, 135,
                    "incorrect value for obs[2].l.f, expected 135, is {}",
                    msg.obs[2].l.f
                );
                assert_eq!(
                    msg.obs[2].l.i, 122531024,
                    "incorrect value for obs[2].l.i, expected 122531024, is {}",
                    msg.obs[2].l.i
                );
                assert_eq!(
                    msg.obs[2].p, 2331544796,
                    "incorrect value for obs[2].p, expected 2331544796, is {}",
                    msg.obs[2].p
                );
                assert_eq!(
                    msg.obs[2].cn0, 151,
                    "incorrect value for obs[2].cn0, expected 151, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 0,
                    "incorrect value for obs[2].lock, expected 0, is {}",
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
                    msg.obs[2].sid.sat, 208,
                    "incorrect value for obs[2].sid.sat, expected 208, is {}",
                    msg.obs[2].sid.sat
                );
                assert_eq!(
                    msg.obs[3].l.f, 242,
                    "incorrect value for obs[3].l.f, expected 242, is {}",
                    msg.obs[3].l.f
                );
                assert_eq!(
                    msg.obs[3].l.i, 119280243,
                    "incorrect value for obs[3].l.i, expected 119280243, is {}",
                    msg.obs[3].l.i
                );
                assert_eq!(
                    msg.obs[3].p, 2269692589,
                    "incorrect value for obs[3].p, expected 2269692589, is {}",
                    msg.obs[3].p
                );
                assert_eq!(
                    msg.obs[3].cn0, 156,
                    "incorrect value for obs[3].cn0, expected 156, is {}",
                    msg.obs[3].cn0
                );
                assert_eq!(
                    msg.obs[3].lock, 0,
                    "incorrect value for obs[3].lock, expected 0, is {}",
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
                    msg.obs[3].sid.sat, 212,
                    "incorrect value for obs[3].sid.sat, expected 212, is {}",
                    msg.obs[3].sid.sat
                );
                assert_eq!(
                    msg.obs[4].l.f, 120,
                    "incorrect value for obs[4].l.f, expected 120, is {}",
                    msg.obs[4].l.f
                );
                assert_eq!(
                    msg.obs[4].l.i, 109691922,
                    "incorrect value for obs[4].l.i, expected 109691922, is {}",
                    msg.obs[4].l.i
                );
                assert_eq!(
                    msg.obs[4].p, 2087293092,
                    "incorrect value for obs[4].p, expected 2087293092, is {}",
                    msg.obs[4].p
                );
                assert_eq!(
                    msg.obs[4].cn0, 168,
                    "incorrect value for obs[4].cn0, expected 168, is {}",
                    msg.obs[4].cn0
                );
                assert_eq!(
                    msg.obs[4].lock, 0,
                    "incorrect value for obs[4].lock, expected 0, is {}",
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
                    msg.obs[4].sid.sat, 217,
                    "incorrect value for obs[4].sid.sat, expected 217, is {}",
                    msg.obs[4].sid.sat
                );
                assert_eq!(
                    msg.obs[5].l.f, 87,
                    "incorrect value for obs[5].l.f, expected 87, is {}",
                    msg.obs[5].l.f
                );
                assert_eq!(
                    msg.obs[5].l.i, 123340754,
                    "incorrect value for obs[5].l.i, expected 123340754, is {}",
                    msg.obs[5].l.i
                );
                assert_eq!(
                    msg.obs[5].p, 2347034654,
                    "incorrect value for obs[5].p, expected 2347034654, is {}",
                    msg.obs[5].p
                );
                assert_eq!(
                    msg.obs[5].cn0, 150,
                    "incorrect value for obs[5].cn0, expected 150, is {}",
                    msg.obs[5].cn0
                );
                assert_eq!(
                    msg.obs[5].lock, 0,
                    "incorrect value for obs[5].lock, expected 0, is {}",
                    msg.obs[5].lock
                );
                assert_eq!(
                    msg.obs[5].sid.code, 0,
                    "incorrect value for obs[5].sid.code, expected 0, is {}",
                    msg.obs[5].sid.code
                );
                assert_eq!(
                    msg.obs[5].sid.reserved, 0,
                    "incorrect value for obs[5].sid.reserved, expected 0, is {}",
                    msg.obs[5].sid.reserved
                );
                assert_eq!(
                    msg.obs[5].sid.sat, 218,
                    "incorrect value for obs[5].sid.sat, expected 218, is {}",
                    msg.obs[5].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 67, 0, 246, 215, 55, 120, 46, 39, 0, 251, 6, 33, 68, 199, 101, 136, 133, 247, 42,
            7, 219, 154, 0, 0, 220, 0, 0, 0, 219, 14, 123, 133, 96, 215, 3, 7, 235, 156, 0, 0, 222,
            0, 0, 0, 87, 166, 81, 122, 5, 173, 109, 6, 174, 170, 0, 0, 225, 0, 0, 0, 11, 233,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgObsDepB(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x43,
                    "Incorrect message type, expected 0x43, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 33,
                    "incorrect value for header.n_obs, expected 33, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 2567800,
                    "incorrect value for header.t.tow, expected 2567800, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1787,
                    "incorrect value for header.t.wn, expected 1787, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].l.f, 219,
                    "incorrect value for obs[0].l.f, expected 219, is {}",
                    msg.obs[0].l.f
                );
                assert_eq!(
                    msg.obs[0].l.i, 120256389,
                    "incorrect value for obs[0].l.i, expected 120256389, is {}",
                    msg.obs[0].l.i
                );
                assert_eq!(
                    msg.obs[0].p, 2288371524,
                    "incorrect value for obs[0].p, expected 2288371524, is {}",
                    msg.obs[0].p
                );
                assert_eq!(
                    msg.obs[0].cn0, 154,
                    "incorrect value for obs[0].cn0, expected 154, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 0,
                    "incorrect value for obs[0].lock, expected 0, is {}",
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
                    msg.obs[0].sid.sat, 220,
                    "incorrect value for obs[0].sid.sat, expected 220, is {}",
                    msg.obs[0].sid.sat
                );
                assert_eq!(
                    msg.obs[1].l.f, 235,
                    "incorrect value for obs[1].l.f, expected 235, is {}",
                    msg.obs[1].l.f
                );
                assert_eq!(
                    msg.obs[1].l.i, 117692256,
                    "incorrect value for obs[1].l.i, expected 117692256, is {}",
                    msg.obs[1].l.i
                );
                assert_eq!(
                    msg.obs[1].p, 2239434459,
                    "incorrect value for obs[1].p, expected 2239434459, is {}",
                    msg.obs[1].p
                );
                assert_eq!(
                    msg.obs[1].cn0, 156,
                    "incorrect value for obs[1].cn0, expected 156, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 0,
                    "incorrect value for obs[1].lock, expected 0, is {}",
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
                    msg.obs[1].sid.sat, 222,
                    "incorrect value for obs[1].sid.sat, expected 222, is {}",
                    msg.obs[1].sid.sat
                );
                assert_eq!(
                    msg.obs[2].l.f, 174,
                    "incorrect value for obs[2].l.f, expected 174, is {}",
                    msg.obs[2].l.f
                );
                assert_eq!(
                    msg.obs[2].l.i, 107851013,
                    "incorrect value for obs[2].l.i, expected 107851013, is {}",
                    msg.obs[2].l.i
                );
                assert_eq!(
                    msg.obs[2].p, 2052171351,
                    "incorrect value for obs[2].p, expected 2052171351, is {}",
                    msg.obs[2].p
                );
                assert_eq!(
                    msg.obs[2].cn0, 170,
                    "incorrect value for obs[2].cn0, expected 170, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 0,
                    "incorrect value for obs[2].lock, expected 0, is {}",
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
                    msg.obs[2].sid.sat, 225,
                    "incorrect value for obs[2].sid.sat, expected 225, is {}",
                    msg.obs[2].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 67, 0, 246, 215, 103, 64, 47, 39, 0, 251, 6, 32, 100, 132, 187, 133, 236, 51, 7, 7,
            94, 156, 0, 0, 202, 0, 0, 0, 97, 184, 85, 147, 178, 30, 190, 7, 40, 140, 0, 0, 203, 0,
            0, 0, 135, 111, 248, 138, 90, 171, 77, 7, 2, 150, 0, 0, 208, 0, 0, 0, 180, 238, 72,
            135, 190, 20, 28, 7, 241, 155, 0, 0, 212, 0, 0, 0, 15, 153, 105, 124, 92, 196, 137, 6,
            153, 168, 0, 0, 217, 0, 0, 0, 49, 185, 228, 139, 144, 5, 90, 7, 41, 150, 0, 0, 218, 0,
            0, 0, 241, 98,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgObsDepB(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x43,
                    "Incorrect message type, expected 0x43, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 32,
                    "incorrect value for header.n_obs, expected 32, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 2568000,
                    "incorrect value for header.t.tow, expected 2568000, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1787,
                    "incorrect value for header.t.wn, expected 1787, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].l.f, 94,
                    "incorrect value for obs[0].l.f, expected 94, is {}",
                    msg.obs[0].l.f
                );
                assert_eq!(
                    msg.obs[0].l.i, 117912556,
                    "incorrect value for obs[0].l.i, expected 117912556, is {}",
                    msg.obs[0].l.i
                );
                assert_eq!(
                    msg.obs[0].p, 2243658852,
                    "incorrect value for obs[0].p, expected 2243658852, is {}",
                    msg.obs[0].p
                );
                assert_eq!(
                    msg.obs[0].cn0, 156,
                    "incorrect value for obs[0].cn0, expected 156, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 0,
                    "incorrect value for obs[0].lock, expected 0, is {}",
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
                    msg.obs[0].sid.sat, 202,
                    "incorrect value for obs[0].sid.sat, expected 202, is {}",
                    msg.obs[0].sid.sat
                );
                assert_eq!(
                    msg.obs[1].l.f, 40,
                    "incorrect value for obs[1].l.f, expected 40, is {}",
                    msg.obs[1].l.f
                );
                assert_eq!(
                    msg.obs[1].l.i, 129900210,
                    "incorrect value for obs[1].l.i, expected 129900210, is {}",
                    msg.obs[1].l.i
                );
                assert_eq!(
                    msg.obs[1].p, 2471868513,
                    "incorrect value for obs[1].p, expected 2471868513, is {}",
                    msg.obs[1].p
                );
                assert_eq!(
                    msg.obs[1].cn0, 140,
                    "incorrect value for obs[1].cn0, expected 140, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 0,
                    "incorrect value for obs[1].lock, expected 0, is {}",
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
                    msg.obs[1].sid.sat, 203,
                    "incorrect value for obs[1].sid.sat, expected 203, is {}",
                    msg.obs[1].sid.sat
                );
                assert_eq!(
                    msg.obs[2].l.f, 2,
                    "incorrect value for obs[2].l.f, expected 2, is {}",
                    msg.obs[2].l.f
                );
                assert_eq!(
                    msg.obs[2].l.i, 122530650,
                    "incorrect value for obs[2].l.i, expected 122530650, is {}",
                    msg.obs[2].l.i
                );
                assert_eq!(
                    msg.obs[2].p, 2331537287,
                    "incorrect value for obs[2].p, expected 2331537287, is {}",
                    msg.obs[2].p
                );
                assert_eq!(
                    msg.obs[2].cn0, 150,
                    "incorrect value for obs[2].cn0, expected 150, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 0,
                    "incorrect value for obs[2].lock, expected 0, is {}",
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
                    msg.obs[2].sid.sat, 208,
                    "incorrect value for obs[2].sid.sat, expected 208, is {}",
                    msg.obs[2].sid.sat
                );
                assert_eq!(
                    msg.obs[3].l.f, 241,
                    "incorrect value for obs[3].l.f, expected 241, is {}",
                    msg.obs[3].l.f
                );
                assert_eq!(
                    msg.obs[3].l.i, 119280830,
                    "incorrect value for obs[3].l.i, expected 119280830, is {}",
                    msg.obs[3].l.i
                );
                assert_eq!(
                    msg.obs[3].p, 2269703860,
                    "incorrect value for obs[3].p, expected 2269703860, is {}",
                    msg.obs[3].p
                );
                assert_eq!(
                    msg.obs[3].cn0, 155,
                    "incorrect value for obs[3].cn0, expected 155, is {}",
                    msg.obs[3].cn0
                );
                assert_eq!(
                    msg.obs[3].lock, 0,
                    "incorrect value for obs[3].lock, expected 0, is {}",
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
                    msg.obs[3].sid.sat, 212,
                    "incorrect value for obs[3].sid.sat, expected 212, is {}",
                    msg.obs[3].sid.sat
                );
                assert_eq!(
                    msg.obs[4].l.f, 153,
                    "incorrect value for obs[4].l.f, expected 153, is {}",
                    msg.obs[4].l.f
                );
                assert_eq!(
                    msg.obs[4].l.i, 109691996,
                    "incorrect value for obs[4].l.i, expected 109691996, is {}",
                    msg.obs[4].l.i
                );
                assert_eq!(
                    msg.obs[4].p, 2087295247,
                    "incorrect value for obs[4].p, expected 2087295247, is {}",
                    msg.obs[4].p
                );
                assert_eq!(
                    msg.obs[4].cn0, 168,
                    "incorrect value for obs[4].cn0, expected 168, is {}",
                    msg.obs[4].cn0
                );
                assert_eq!(
                    msg.obs[4].lock, 0,
                    "incorrect value for obs[4].lock, expected 0, is {}",
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
                    msg.obs[4].sid.sat, 217,
                    "incorrect value for obs[4].sid.sat, expected 217, is {}",
                    msg.obs[4].sid.sat
                );
                assert_eq!(
                    msg.obs[5].l.f, 41,
                    "incorrect value for obs[5].l.f, expected 41, is {}",
                    msg.obs[5].l.f
                );
                assert_eq!(
                    msg.obs[5].l.i, 123340176,
                    "incorrect value for obs[5].l.i, expected 123340176, is {}",
                    msg.obs[5].l.i
                );
                assert_eq!(
                    msg.obs[5].p, 2347022641,
                    "incorrect value for obs[5].p, expected 2347022641, is {}",
                    msg.obs[5].p
                );
                assert_eq!(
                    msg.obs[5].cn0, 150,
                    "incorrect value for obs[5].cn0, expected 150, is {}",
                    msg.obs[5].cn0
                );
                assert_eq!(
                    msg.obs[5].lock, 0,
                    "incorrect value for obs[5].lock, expected 0, is {}",
                    msg.obs[5].lock
                );
                assert_eq!(
                    msg.obs[5].sid.code, 0,
                    "incorrect value for obs[5].sid.code, expected 0, is {}",
                    msg.obs[5].sid.code
                );
                assert_eq!(
                    msg.obs[5].sid.reserved, 0,
                    "incorrect value for obs[5].sid.reserved, expected 0, is {}",
                    msg.obs[5].sid.reserved
                );
                assert_eq!(
                    msg.obs[5].sid.sat, 218,
                    "incorrect value for obs[5].sid.sat, expected 218, is {}",
                    msg.obs[5].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 67, 0, 246, 215, 55, 64, 47, 39, 0, 251, 6, 33, 234, 148, 101, 136, 15, 245, 42, 7,
            20, 154, 0, 0, 220, 0, 0, 0, 208, 247, 122, 133, 16, 214, 3, 7, 38, 156, 0, 0, 222, 0,
            0, 0, 15, 150, 81, 122, 22, 172, 109, 6, 7, 172, 0, 0, 225, 0, 0, 0, 201, 13,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgObsDepB(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x43,
                    "Incorrect message type, expected 0x43, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 33,
                    "incorrect value for header.n_obs, expected 33, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 2568000,
                    "incorrect value for header.t.tow, expected 2568000, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1787,
                    "incorrect value for header.t.wn, expected 1787, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].l.f, 20,
                    "incorrect value for obs[0].l.f, expected 20, is {}",
                    msg.obs[0].l.f
                );
                assert_eq!(
                    msg.obs[0].l.i, 120255759,
                    "incorrect value for obs[0].l.i, expected 120255759, is {}",
                    msg.obs[0].l.i
                );
                assert_eq!(
                    msg.obs[0].p, 2288358634,
                    "incorrect value for obs[0].p, expected 2288358634, is {}",
                    msg.obs[0].p
                );
                assert_eq!(
                    msg.obs[0].cn0, 154,
                    "incorrect value for obs[0].cn0, expected 154, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 0,
                    "incorrect value for obs[0].lock, expected 0, is {}",
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
                    msg.obs[0].sid.sat, 220,
                    "incorrect value for obs[0].sid.sat, expected 220, is {}",
                    msg.obs[0].sid.sat
                );
                assert_eq!(
                    msg.obs[1].l.f, 38,
                    "incorrect value for obs[1].l.f, expected 38, is {}",
                    msg.obs[1].l.f
                );
                assert_eq!(
                    msg.obs[1].l.i, 117691920,
                    "incorrect value for obs[1].l.i, expected 117691920, is {}",
                    msg.obs[1].l.i
                );
                assert_eq!(
                    msg.obs[1].p, 2239428560,
                    "incorrect value for obs[1].p, expected 2239428560, is {}",
                    msg.obs[1].p
                );
                assert_eq!(
                    msg.obs[1].cn0, 156,
                    "incorrect value for obs[1].cn0, expected 156, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 0,
                    "incorrect value for obs[1].lock, expected 0, is {}",
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
                    msg.obs[1].sid.sat, 222,
                    "incorrect value for obs[1].sid.sat, expected 222, is {}",
                    msg.obs[1].sid.sat
                );
                assert_eq!(
                    msg.obs[2].l.f, 7,
                    "incorrect value for obs[2].l.f, expected 7, is {}",
                    msg.obs[2].l.f
                );
                assert_eq!(
                    msg.obs[2].l.i, 107850774,
                    "incorrect value for obs[2].l.i, expected 107850774, is {}",
                    msg.obs[2].l.i
                );
                assert_eq!(
                    msg.obs[2].p, 2052167183,
                    "incorrect value for obs[2].p, expected 2052167183, is {}",
                    msg.obs[2].p
                );
                assert_eq!(
                    msg.obs[2].cn0, 172,
                    "incorrect value for obs[2].cn0, expected 172, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 0,
                    "incorrect value for obs[2].lock, expected 0, is {}",
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
                    msg.obs[2].sid.sat, 225,
                    "incorrect value for obs[2].sid.sat, expected 225, is {}",
                    msg.obs[2].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 67, 0, 246, 215, 103, 8, 48, 39, 0, 251, 6, 32, 254, 96, 187, 133, 249, 49, 7, 7,
            165, 156, 0, 0, 202, 0, 0, 0, 113, 229, 85, 147, 11, 33, 190, 7, 106, 143, 0, 0, 203,
            0, 0, 0, 182, 85, 248, 138, 227, 169, 77, 7, 159, 150, 0, 0, 208, 0, 0, 0, 17, 24, 73,
            135, 10, 23, 28, 7, 7, 156, 0, 0, 212, 0, 0, 0, 108, 155, 105, 124, 166, 196, 137, 6,
            186, 170, 0, 0, 217, 0, 0, 0, 214, 142, 228, 139, 77, 3, 90, 7, 236, 151, 0, 0, 218, 0,
            0, 0, 59, 118,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgObsDepB(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x43,
                    "Incorrect message type, expected 0x43, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 32,
                    "incorrect value for header.n_obs, expected 32, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 2568200,
                    "incorrect value for header.t.tow, expected 2568200, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1787,
                    "incorrect value for header.t.wn, expected 1787, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].l.f, 165,
                    "incorrect value for obs[0].l.f, expected 165, is {}",
                    msg.obs[0].l.f
                );
                assert_eq!(
                    msg.obs[0].l.i, 117912057,
                    "incorrect value for obs[0].l.i, expected 117912057, is {}",
                    msg.obs[0].l.i
                );
                assert_eq!(
                    msg.obs[0].p, 2243649790,
                    "incorrect value for obs[0].p, expected 2243649790, is {}",
                    msg.obs[0].p
                );
                assert_eq!(
                    msg.obs[0].cn0, 156,
                    "incorrect value for obs[0].cn0, expected 156, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 0,
                    "incorrect value for obs[0].lock, expected 0, is {}",
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
                    msg.obs[0].sid.sat, 202,
                    "incorrect value for obs[0].sid.sat, expected 202, is {}",
                    msg.obs[0].sid.sat
                );
                assert_eq!(
                    msg.obs[1].l.f, 106,
                    "incorrect value for obs[1].l.f, expected 106, is {}",
                    msg.obs[1].l.f
                );
                assert_eq!(
                    msg.obs[1].l.i, 129900811,
                    "incorrect value for obs[1].l.i, expected 129900811, is {}",
                    msg.obs[1].l.i
                );
                assert_eq!(
                    msg.obs[1].p, 2471880049,
                    "incorrect value for obs[1].p, expected 2471880049, is {}",
                    msg.obs[1].p
                );
                assert_eq!(
                    msg.obs[1].cn0, 143,
                    "incorrect value for obs[1].cn0, expected 143, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 0,
                    "incorrect value for obs[1].lock, expected 0, is {}",
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
                    msg.obs[1].sid.sat, 203,
                    "incorrect value for obs[1].sid.sat, expected 203, is {}",
                    msg.obs[1].sid.sat
                );
                assert_eq!(
                    msg.obs[2].l.f, 159,
                    "incorrect value for obs[2].l.f, expected 159, is {}",
                    msg.obs[2].l.f
                );
                assert_eq!(
                    msg.obs[2].l.i, 122530275,
                    "incorrect value for obs[2].l.i, expected 122530275, is {}",
                    msg.obs[2].l.i
                );
                assert_eq!(
                    msg.obs[2].p, 2331530678,
                    "incorrect value for obs[2].p, expected 2331530678, is {}",
                    msg.obs[2].p
                );
                assert_eq!(
                    msg.obs[2].cn0, 150,
                    "incorrect value for obs[2].cn0, expected 150, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 0,
                    "incorrect value for obs[2].lock, expected 0, is {}",
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
                    msg.obs[2].sid.sat, 208,
                    "incorrect value for obs[2].sid.sat, expected 208, is {}",
                    msg.obs[2].sid.sat
                );
                assert_eq!(
                    msg.obs[3].l.f, 7,
                    "incorrect value for obs[3].l.f, expected 7, is {}",
                    msg.obs[3].l.f
                );
                assert_eq!(
                    msg.obs[3].l.i, 119281418,
                    "incorrect value for obs[3].l.i, expected 119281418, is {}",
                    msg.obs[3].l.i
                );
                assert_eq!(
                    msg.obs[3].p, 2269714449,
                    "incorrect value for obs[3].p, expected 2269714449, is {}",
                    msg.obs[3].p
                );
                assert_eq!(
                    msg.obs[3].cn0, 156,
                    "incorrect value for obs[3].cn0, expected 156, is {}",
                    msg.obs[3].cn0
                );
                assert_eq!(
                    msg.obs[3].lock, 0,
                    "incorrect value for obs[3].lock, expected 0, is {}",
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
                    msg.obs[3].sid.sat, 212,
                    "incorrect value for obs[3].sid.sat, expected 212, is {}",
                    msg.obs[3].sid.sat
                );
                assert_eq!(
                    msg.obs[4].l.f, 186,
                    "incorrect value for obs[4].l.f, expected 186, is {}",
                    msg.obs[4].l.f
                );
                assert_eq!(
                    msg.obs[4].l.i, 109692070,
                    "incorrect value for obs[4].l.i, expected 109692070, is {}",
                    msg.obs[4].l.i
                );
                assert_eq!(
                    msg.obs[4].p, 2087295852,
                    "incorrect value for obs[4].p, expected 2087295852, is {}",
                    msg.obs[4].p
                );
                assert_eq!(
                    msg.obs[4].cn0, 170,
                    "incorrect value for obs[4].cn0, expected 170, is {}",
                    msg.obs[4].cn0
                );
                assert_eq!(
                    msg.obs[4].lock, 0,
                    "incorrect value for obs[4].lock, expected 0, is {}",
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
                    msg.obs[4].sid.sat, 217,
                    "incorrect value for obs[4].sid.sat, expected 217, is {}",
                    msg.obs[4].sid.sat
                );
                assert_eq!(
                    msg.obs[5].l.f, 236,
                    "incorrect value for obs[5].l.f, expected 236, is {}",
                    msg.obs[5].l.f
                );
                assert_eq!(
                    msg.obs[5].l.i, 123339597,
                    "incorrect value for obs[5].l.i, expected 123339597, is {}",
                    msg.obs[5].l.i
                );
                assert_eq!(
                    msg.obs[5].p, 2347011798,
                    "incorrect value for obs[5].p, expected 2347011798, is {}",
                    msg.obs[5].p
                );
                assert_eq!(
                    msg.obs[5].cn0, 151,
                    "incorrect value for obs[5].cn0, expected 151, is {}",
                    msg.obs[5].cn0
                );
                assert_eq!(
                    msg.obs[5].lock, 0,
                    "incorrect value for obs[5].lock, expected 0, is {}",
                    msg.obs[5].lock
                );
                assert_eq!(
                    msg.obs[5].sid.code, 0,
                    "incorrect value for obs[5].sid.code, expected 0, is {}",
                    msg.obs[5].sid.code
                );
                assert_eq!(
                    msg.obs[5].sid.reserved, 0,
                    "incorrect value for obs[5].sid.reserved, expected 0, is {}",
                    msg.obs[5].sid.reserved
                );
                assert_eq!(
                    msg.obs[5].sid.sat, 218,
                    "incorrect value for obs[5].sid.sat, expected 218, is {}",
                    msg.obs[5].sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
