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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_msgObsDepA.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_observation_msgObsDepA() {
    {
        let mut payload = Cursor::new(vec![
            85, 69, 0, 195, 4, 98, 56, 158, 67, 24, 46, 7, 32, 56, 235, 249, 121, 244, 114, 255,
            255, 33, 46, 67, 218, 0, 238, 203, 70, 124, 22, 25, 3, 0, 98, 43, 184, 157, 2, 176,
            133, 197, 125, 126, 71, 253, 255, 185, 39, 68, 55, 3, 60, 173, 162, 131, 98, 231, 253,
            255, 139, 30, 33, 16, 10, 128, 178, 248, 136, 42, 113, 253, 255, 40, 20, 42, 71, 13,
            246, 246, 17, 135, 255, 51, 3, 0, 64, 27, 108, 249, 22, 210, 41, 114, 118, 131, 48,
            255, 255, 31, 52, 226, 58, 30, 23, 217,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgObsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x45,
                    "Incorrect message type, expected 0x45, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 32,
                    "incorrect value for header.n_obs, expected 32, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 407084600,
                    "incorrect value for header.t.tow, expected 407084600, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1838,
                    "incorrect value for header.t.wn, expected 1838, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].L.f, 33,
                    "incorrect value for obs[0].L.f, expected 33, is {}",
                    msg.obs[0].L.f
                );
                assert_eq!(
                    msg.obs[0].L.i, -36108,
                    "incorrect value for obs[0].L.i, expected -36108, is {}",
                    msg.obs[0].L.i
                );
                assert_eq!(
                    msg.obs[0].P, 2046421816,
                    "incorrect value for obs[0].P, expected 2046421816, is {}",
                    msg.obs[0].P
                );
                assert_eq!(
                    msg.obs[0].cn0, 46,
                    "incorrect value for obs[0].cn0, expected 46, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 55875,
                    "incorrect value for obs[0].lock, expected 55875, is {}",
                    msg.obs[0].lock
                );
                assert_eq!(
                    msg.obs[0].prn, 0,
                    "incorrect value for obs[0].prn, expected 0, is {}",
                    msg.obs[0].prn
                );
                assert_eq!(
                    msg.obs[1].L.f, 98,
                    "incorrect value for obs[1].L.f, expected 98, is {}",
                    msg.obs[1].L.f
                );
                assert_eq!(
                    msg.obs[1].L.i, 203030,
                    "incorrect value for obs[1].L.i, expected 203030, is {}",
                    msg.obs[1].L.i
                );
                assert_eq!(
                    msg.obs[1].P, 2085014510,
                    "incorrect value for obs[1].P, expected 2085014510, is {}",
                    msg.obs[1].P
                );
                assert_eq!(
                    msg.obs[1].cn0, 43,
                    "incorrect value for obs[1].cn0, expected 43, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 40376,
                    "incorrect value for obs[1].lock, expected 40376, is {}",
                    msg.obs[1].lock
                );
                assert_eq!(
                    msg.obs[1].prn, 2,
                    "incorrect value for obs[1].prn, expected 2, is {}",
                    msg.obs[1].prn
                );
                assert_eq!(
                    msg.obs[2].L.f, 185,
                    "incorrect value for obs[2].L.f, expected 185, is {}",
                    msg.obs[2].L.f
                );
                assert_eq!(
                    msg.obs[2].L.i, -178306,
                    "incorrect value for obs[2].L.i, expected -178306, is {}",
                    msg.obs[2].L.i
                );
                assert_eq!(
                    msg.obs[2].P, 2110096816,
                    "incorrect value for obs[2].P, expected 2110096816, is {}",
                    msg.obs[2].P
                );
                assert_eq!(
                    msg.obs[2].cn0, 39,
                    "incorrect value for obs[2].cn0, expected 39, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 14148,
                    "incorrect value for obs[2].lock, expected 14148, is {}",
                    msg.obs[2].lock
                );
                assert_eq!(
                    msg.obs[2].prn, 3,
                    "incorrect value for obs[2].prn, expected 3, is {}",
                    msg.obs[2].prn
                );
                assert_eq!(
                    msg.obs[3].L.f, 139,
                    "incorrect value for obs[3].L.f, expected 139, is {}",
                    msg.obs[3].L.f
                );
                assert_eq!(
                    msg.obs[3].L.i, -137374,
                    "incorrect value for obs[3].L.i, expected -137374, is {}",
                    msg.obs[3].L.i
                );
                assert_eq!(
                    msg.obs[3].P, 2208476476,
                    "incorrect value for obs[3].P, expected 2208476476, is {}",
                    msg.obs[3].P
                );
                assert_eq!(
                    msg.obs[3].cn0, 30,
                    "incorrect value for obs[3].cn0, expected 30, is {}",
                    msg.obs[3].cn0
                );
                assert_eq!(
                    msg.obs[3].lock, 4129,
                    "incorrect value for obs[3].lock, expected 4129, is {}",
                    msg.obs[3].lock
                );
                assert_eq!(
                    msg.obs[3].prn, 10,
                    "incorrect value for obs[3].prn, expected 10, is {}",
                    msg.obs[3].prn
                );
                assert_eq!(
                    msg.obs[4].L.f, 40,
                    "incorrect value for obs[4].L.f, expected 40, is {}",
                    msg.obs[4].L.f
                );
                assert_eq!(
                    msg.obs[4].L.i, -167638,
                    "incorrect value for obs[4].L.i, expected -167638, is {}",
                    msg.obs[4].L.i
                );
                assert_eq!(
                    msg.obs[4].P, 2298000000,
                    "incorrect value for obs[4].P, expected 2298000000, is {}",
                    msg.obs[4].P
                );
                assert_eq!(
                    msg.obs[4].cn0, 20,
                    "incorrect value for obs[4].cn0, expected 20, is {}",
                    msg.obs[4].cn0
                );
                assert_eq!(
                    msg.obs[4].lock, 18218,
                    "incorrect value for obs[4].lock, expected 18218, is {}",
                    msg.obs[4].lock
                );
                assert_eq!(
                    msg.obs[4].prn, 13,
                    "incorrect value for obs[4].prn, expected 13, is {}",
                    msg.obs[4].prn
                );
                assert_eq!(
                    msg.obs[5].L.f, 64,
                    "incorrect value for obs[5].L.f, expected 64, is {}",
                    msg.obs[5].L.f
                );
                assert_eq!(
                    msg.obs[5].L.i, 209919,
                    "incorrect value for obs[5].L.i, expected 209919, is {}",
                    msg.obs[5].L.i
                );
                assert_eq!(
                    msg.obs[5].P, 2266101494,
                    "incorrect value for obs[5].P, expected 2266101494, is {}",
                    msg.obs[5].P
                );
                assert_eq!(
                    msg.obs[5].cn0, 27,
                    "incorrect value for obs[5].cn0, expected 27, is {}",
                    msg.obs[5].cn0
                );
                assert_eq!(
                    msg.obs[5].lock, 63852,
                    "incorrect value for obs[5].lock, expected 63852, is {}",
                    msg.obs[5].lock
                );
                assert_eq!(
                    msg.obs[5].prn, 22,
                    "incorrect value for obs[5].prn, expected 22, is {}",
                    msg.obs[5].prn
                );
                assert_eq!(
                    msg.obs[6].L.f, 31,
                    "incorrect value for obs[6].L.f, expected 31, is {}",
                    msg.obs[6].L.f
                );
                assert_eq!(
                    msg.obs[6].L.i, -53117,
                    "incorrect value for obs[6].L.i, expected -53117, is {}",
                    msg.obs[6].L.i
                );
                assert_eq!(
                    msg.obs[6].P, 1987193298,
                    "incorrect value for obs[6].P, expected 1987193298, is {}",
                    msg.obs[6].P
                );
                assert_eq!(
                    msg.obs[6].cn0, 52,
                    "incorrect value for obs[6].cn0, expected 52, is {}",
                    msg.obs[6].cn0
                );
                assert_eq!(
                    msg.obs[6].lock, 15074,
                    "incorrect value for obs[6].lock, expected 15074, is {}",
                    msg.obs[6].lock
                );
                assert_eq!(
                    msg.obs[6].prn, 30,
                    "incorrect value for obs[6].prn, expected 30, is {}",
                    msg.obs[6].prn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 69, 0, 195, 4, 20, 56, 158, 67, 24, 46, 7, 33, 84, 52, 164, 117, 102, 32, 0, 0,
            147, 62, 62, 250, 31, 234, 14,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgObsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x45,
                    "Incorrect message type, expected 0x45, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 33,
                    "incorrect value for header.n_obs, expected 33, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 407084600,
                    "incorrect value for header.t.tow, expected 407084600, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1838,
                    "incorrect value for header.t.wn, expected 1838, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].L.f, 147,
                    "incorrect value for obs[0].L.f, expected 147, is {}",
                    msg.obs[0].L.f
                );
                assert_eq!(
                    msg.obs[0].L.i, 8294,
                    "incorrect value for obs[0].L.i, expected 8294, is {}",
                    msg.obs[0].L.i
                );
                assert_eq!(
                    msg.obs[0].P, 1973695572,
                    "incorrect value for obs[0].P, expected 1973695572, is {}",
                    msg.obs[0].P
                );
                assert_eq!(
                    msg.obs[0].cn0, 62,
                    "incorrect value for obs[0].cn0, expected 62, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 64062,
                    "incorrect value for obs[0].lock, expected 64062, is {}",
                    msg.obs[0].lock
                );
                assert_eq!(
                    msg.obs[0].prn, 31,
                    "incorrect value for obs[0].prn, expected 31, is {}",
                    msg.obs[0].prn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 69, 0, 195, 4, 98, 0, 159, 67, 24, 46, 7, 32, 32, 209, 249, 121, 145, 114, 255,
            255, 141, 45, 67, 218, 0, 177, 128, 70, 124, 79, 27, 3, 0, 159, 44, 184, 157, 2, 59,
            135, 197, 125, 175, 69, 253, 255, 77, 40, 68, 55, 3, 211, 172, 162, 131, 177, 229, 253,
            255, 20, 31, 33, 16, 10, 128, 178, 248, 136, 116, 111, 253, 255, 94, 21, 42, 71, 13,
            182, 173, 17, 135, 37, 54, 3, 0, 214, 27, 108, 249, 22, 91, 20, 114, 118, 240, 47, 255,
            255, 129, 52, 226, 58, 30, 200, 119,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgObsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x45,
                    "Incorrect message type, expected 0x45, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 32,
                    "incorrect value for header.n_obs, expected 32, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 407084800,
                    "incorrect value for header.t.tow, expected 407084800, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1838,
                    "incorrect value for header.t.wn, expected 1838, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].L.f, 141,
                    "incorrect value for obs[0].L.f, expected 141, is {}",
                    msg.obs[0].L.f
                );
                assert_eq!(
                    msg.obs[0].L.i, -36207,
                    "incorrect value for obs[0].L.i, expected -36207, is {}",
                    msg.obs[0].L.i
                );
                assert_eq!(
                    msg.obs[0].P, 2046415136,
                    "incorrect value for obs[0].P, expected 2046415136, is {}",
                    msg.obs[0].P
                );
                assert_eq!(
                    msg.obs[0].cn0, 45,
                    "incorrect value for obs[0].cn0, expected 45, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 55875,
                    "incorrect value for obs[0].lock, expected 55875, is {}",
                    msg.obs[0].lock
                );
                assert_eq!(
                    msg.obs[0].prn, 0,
                    "incorrect value for obs[0].prn, expected 0, is {}",
                    msg.obs[0].prn
                );
                assert_eq!(
                    msg.obs[1].L.f, 159,
                    "incorrect value for obs[1].L.f, expected 159, is {}",
                    msg.obs[1].L.f
                );
                assert_eq!(
                    msg.obs[1].L.i, 203599,
                    "incorrect value for obs[1].L.i, expected 203599, is {}",
                    msg.obs[1].L.i
                );
                assert_eq!(
                    msg.obs[1].P, 2084995249,
                    "incorrect value for obs[1].P, expected 2084995249, is {}",
                    msg.obs[1].P
                );
                assert_eq!(
                    msg.obs[1].cn0, 44,
                    "incorrect value for obs[1].cn0, expected 44, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 40376,
                    "incorrect value for obs[1].lock, expected 40376, is {}",
                    msg.obs[1].lock
                );
                assert_eq!(
                    msg.obs[1].prn, 2,
                    "incorrect value for obs[1].prn, expected 2, is {}",
                    msg.obs[1].prn
                );
                assert_eq!(
                    msg.obs[2].L.f, 77,
                    "incorrect value for obs[2].L.f, expected 77, is {}",
                    msg.obs[2].L.f
                );
                assert_eq!(
                    msg.obs[2].L.i, -178769,
                    "incorrect value for obs[2].L.i, expected -178769, is {}",
                    msg.obs[2].L.i
                );
                assert_eq!(
                    msg.obs[2].P, 2110097211,
                    "incorrect value for obs[2].P, expected 2110097211, is {}",
                    msg.obs[2].P
                );
                assert_eq!(
                    msg.obs[2].cn0, 40,
                    "incorrect value for obs[2].cn0, expected 40, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 14148,
                    "incorrect value for obs[2].lock, expected 14148, is {}",
                    msg.obs[2].lock
                );
                assert_eq!(
                    msg.obs[2].prn, 3,
                    "incorrect value for obs[2].prn, expected 3, is {}",
                    msg.obs[2].prn
                );
                assert_eq!(
                    msg.obs[3].L.f, 20,
                    "incorrect value for obs[3].L.f, expected 20, is {}",
                    msg.obs[3].L.f
                );
                assert_eq!(
                    msg.obs[3].L.i, -137807,
                    "incorrect value for obs[3].L.i, expected -137807, is {}",
                    msg.obs[3].L.i
                );
                assert_eq!(
                    msg.obs[3].P, 2208476371,
                    "incorrect value for obs[3].P, expected 2208476371, is {}",
                    msg.obs[3].P
                );
                assert_eq!(
                    msg.obs[3].cn0, 31,
                    "incorrect value for obs[3].cn0, expected 31, is {}",
                    msg.obs[3].cn0
                );
                assert_eq!(
                    msg.obs[3].lock, 4129,
                    "incorrect value for obs[3].lock, expected 4129, is {}",
                    msg.obs[3].lock
                );
                assert_eq!(
                    msg.obs[3].prn, 10,
                    "incorrect value for obs[3].prn, expected 10, is {}",
                    msg.obs[3].prn
                );
                assert_eq!(
                    msg.obs[4].L.f, 94,
                    "incorrect value for obs[4].L.f, expected 94, is {}",
                    msg.obs[4].L.f
                );
                assert_eq!(
                    msg.obs[4].L.i, -168076,
                    "incorrect value for obs[4].L.i, expected -168076, is {}",
                    msg.obs[4].L.i
                );
                assert_eq!(
                    msg.obs[4].P, 2298000000,
                    "incorrect value for obs[4].P, expected 2298000000, is {}",
                    msg.obs[4].P
                );
                assert_eq!(
                    msg.obs[4].cn0, 21,
                    "incorrect value for obs[4].cn0, expected 21, is {}",
                    msg.obs[4].cn0
                );
                assert_eq!(
                    msg.obs[4].lock, 18218,
                    "incorrect value for obs[4].lock, expected 18218, is {}",
                    msg.obs[4].lock
                );
                assert_eq!(
                    msg.obs[4].prn, 13,
                    "incorrect value for obs[4].prn, expected 13, is {}",
                    msg.obs[4].prn
                );
                assert_eq!(
                    msg.obs[5].L.f, 214,
                    "incorrect value for obs[5].L.f, expected 214, is {}",
                    msg.obs[5].L.f
                );
                assert_eq!(
                    msg.obs[5].L.i, 210469,
                    "incorrect value for obs[5].L.i, expected 210469, is {}",
                    msg.obs[5].L.i
                );
                assert_eq!(
                    msg.obs[5].P, 2266082742,
                    "incorrect value for obs[5].P, expected 2266082742, is {}",
                    msg.obs[5].P
                );
                assert_eq!(
                    msg.obs[5].cn0, 27,
                    "incorrect value for obs[5].cn0, expected 27, is {}",
                    msg.obs[5].cn0
                );
                assert_eq!(
                    msg.obs[5].lock, 63852,
                    "incorrect value for obs[5].lock, expected 63852, is {}",
                    msg.obs[5].lock
                );
                assert_eq!(
                    msg.obs[5].prn, 22,
                    "incorrect value for obs[5].prn, expected 22, is {}",
                    msg.obs[5].prn
                );
                assert_eq!(
                    msg.obs[6].L.f, 129,
                    "incorrect value for obs[6].L.f, expected 129, is {}",
                    msg.obs[6].L.f
                );
                assert_eq!(
                    msg.obs[6].L.i, -53264,
                    "incorrect value for obs[6].L.i, expected -53264, is {}",
                    msg.obs[6].L.i
                );
                assert_eq!(
                    msg.obs[6].P, 1987187803,
                    "incorrect value for obs[6].P, expected 1987187803, is {}",
                    msg.obs[6].P
                );
                assert_eq!(
                    msg.obs[6].cn0, 52,
                    "incorrect value for obs[6].cn0, expected 52, is {}",
                    msg.obs[6].cn0
                );
                assert_eq!(
                    msg.obs[6].lock, 15074,
                    "incorrect value for obs[6].lock, expected 15074, is {}",
                    msg.obs[6].lock
                );
                assert_eq!(
                    msg.obs[6].prn, 30,
                    "incorrect value for obs[6].prn, expected 30, is {}",
                    msg.obs[6].prn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 69, 0, 195, 4, 20, 0, 159, 67, 24, 46, 7, 33, 49, 19, 164, 117, 120, 32, 0, 0, 222,
            63, 62, 250, 31, 11, 231,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgObsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x45,
                    "Incorrect message type, expected 0x45, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 33,
                    "incorrect value for header.n_obs, expected 33, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 407084800,
                    "incorrect value for header.t.tow, expected 407084800, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1838,
                    "incorrect value for header.t.wn, expected 1838, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].L.f, 222,
                    "incorrect value for obs[0].L.f, expected 222, is {}",
                    msg.obs[0].L.f
                );
                assert_eq!(
                    msg.obs[0].L.i, 8312,
                    "incorrect value for obs[0].L.i, expected 8312, is {}",
                    msg.obs[0].L.i
                );
                assert_eq!(
                    msg.obs[0].P, 1973687089,
                    "incorrect value for obs[0].P, expected 1973687089, is {}",
                    msg.obs[0].P
                );
                assert_eq!(
                    msg.obs[0].cn0, 63,
                    "incorrect value for obs[0].cn0, expected 63, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 64062,
                    "incorrect value for obs[0].lock, expected 64062, is {}",
                    msg.obs[0].lock
                );
                assert_eq!(
                    msg.obs[0].prn, 31,
                    "incorrect value for obs[0].prn, expected 31, is {}",
                    msg.obs[0].prn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 69, 0, 195, 4, 72, 96, 162, 68, 24, 46, 7, 16, 87, 132, 217, 121, 121, 148, 255,
            255, 189, 43, 175, 147, 0, 132, 64, 200, 125, 106, 31, 254, 255, 1, 41, 14, 177, 3,
            128, 178, 248, 136, 70, 68, 254, 255, 166, 18, 184, 133, 13, 24, 127, 178, 134, 6, 25,
            2, 0, 249, 28, 33, 96, 22, 170, 104, 86, 118, 67, 112, 255, 255, 203, 56, 208, 88, 30,
            43, 107,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgObsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x45,
                    "Incorrect message type, expected 0x45, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 16,
                    "incorrect value for header.n_obs, expected 16, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 407151200,
                    "incorrect value for header.t.tow, expected 407151200, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1838,
                    "incorrect value for header.t.wn, expected 1838, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].L.f, 189,
                    "incorrect value for obs[0].L.f, expected 189, is {}",
                    msg.obs[0].L.f
                );
                assert_eq!(
                    msg.obs[0].L.i, -27527,
                    "incorrect value for obs[0].L.i, expected -27527, is {}",
                    msg.obs[0].L.i
                );
                assert_eq!(
                    msg.obs[0].P, 2044298327,
                    "incorrect value for obs[0].P, expected 2044298327, is {}",
                    msg.obs[0].P
                );
                assert_eq!(
                    msg.obs[0].cn0, 43,
                    "incorrect value for obs[0].cn0, expected 43, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 37807,
                    "incorrect value for obs[0].lock, expected 37807, is {}",
                    msg.obs[0].lock
                );
                assert_eq!(
                    msg.obs[0].prn, 0,
                    "incorrect value for obs[0].prn, expected 0, is {}",
                    msg.obs[0].prn
                );
                assert_eq!(
                    msg.obs[1].L.f, 1,
                    "incorrect value for obs[1].L.f, expected 1, is {}",
                    msg.obs[1].L.f
                );
                assert_eq!(
                    msg.obs[1].L.i, -123030,
                    "incorrect value for obs[1].L.i, expected -123030, is {}",
                    msg.obs[1].L.i
                );
                assert_eq!(
                    msg.obs[1].P, 2110275716,
                    "incorrect value for obs[1].P, expected 2110275716, is {}",
                    msg.obs[1].P
                );
                assert_eq!(
                    msg.obs[1].cn0, 41,
                    "incorrect value for obs[1].cn0, expected 41, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 45326,
                    "incorrect value for obs[1].lock, expected 45326, is {}",
                    msg.obs[1].lock
                );
                assert_eq!(
                    msg.obs[1].prn, 3,
                    "incorrect value for obs[1].prn, expected 3, is {}",
                    msg.obs[1].prn
                );
                assert_eq!(
                    msg.obs[2].L.f, 166,
                    "incorrect value for obs[2].L.f, expected 166, is {}",
                    msg.obs[2].L.f
                );
                assert_eq!(
                    msg.obs[2].L.i, -113594,
                    "incorrect value for obs[2].L.i, expected -113594, is {}",
                    msg.obs[2].L.i
                );
                assert_eq!(
                    msg.obs[2].P, 2298000000,
                    "incorrect value for obs[2].P, expected 2298000000, is {}",
                    msg.obs[2].P
                );
                assert_eq!(
                    msg.obs[2].cn0, 18,
                    "incorrect value for obs[2].cn0, expected 18, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 34232,
                    "incorrect value for obs[2].lock, expected 34232, is {}",
                    msg.obs[2].lock
                );
                assert_eq!(
                    msg.obs[2].prn, 13,
                    "incorrect value for obs[2].prn, expected 13, is {}",
                    msg.obs[2].prn
                );
                assert_eq!(
                    msg.obs[3].L.f, 249,
                    "incorrect value for obs[3].L.f, expected 249, is {}",
                    msg.obs[3].L.f
                );
                assert_eq!(
                    msg.obs[3].L.i, 137478,
                    "incorrect value for obs[3].L.i, expected 137478, is {}",
                    msg.obs[3].L.i
                );
                assert_eq!(
                    msg.obs[3].P, 2259844888,
                    "incorrect value for obs[3].P, expected 2259844888, is {}",
                    msg.obs[3].P
                );
                assert_eq!(
                    msg.obs[3].cn0, 28,
                    "incorrect value for obs[3].cn0, expected 28, is {}",
                    msg.obs[3].cn0
                );
                assert_eq!(
                    msg.obs[3].lock, 24609,
                    "incorrect value for obs[3].lock, expected 24609, is {}",
                    msg.obs[3].lock
                );
                assert_eq!(
                    msg.obs[3].prn, 22,
                    "incorrect value for obs[3].prn, expected 22, is {}",
                    msg.obs[3].prn
                );
                assert_eq!(
                    msg.obs[4].L.f, 203,
                    "incorrect value for obs[4].L.f, expected 203, is {}",
                    msg.obs[4].L.f
                );
                assert_eq!(
                    msg.obs[4].L.i, -36797,
                    "incorrect value for obs[4].L.i, expected -36797, is {}",
                    msg.obs[4].L.i
                );
                assert_eq!(
                    msg.obs[4].P, 1985374378,
                    "incorrect value for obs[4].P, expected 1985374378, is {}",
                    msg.obs[4].P
                );
                assert_eq!(
                    msg.obs[4].cn0, 56,
                    "incorrect value for obs[4].cn0, expected 56, is {}",
                    msg.obs[4].cn0
                );
                assert_eq!(
                    msg.obs[4].lock, 22736,
                    "incorrect value for obs[4].lock, expected 22736, is {}",
                    msg.obs[4].lock
                );
                assert_eq!(
                    msg.obs[4].prn, 30,
                    "incorrect value for obs[4].prn, expected 30, is {}",
                    msg.obs[4].prn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 69, 0, 195, 4, 72, 40, 163, 68, 24, 46, 7, 16, 132, 107, 217, 121, 14, 148, 255,
            255, 1, 44, 175, 147, 0, 129, 66, 200, 125, 148, 29, 254, 255, 153, 41, 14, 177, 3,
            128, 178, 248, 136, 143, 66, 254, 255, 222, 18, 184, 133, 13, 158, 53, 178, 134, 42,
            27, 2, 0, 237, 30, 33, 96, 22, 38, 83, 86, 118, 168, 111, 255, 255, 45, 56, 208, 88,
            30, 1, 175,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgObsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x45,
                    "Incorrect message type, expected 0x45, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.header.n_obs, 16,
                    "incorrect value for header.n_obs, expected 16, is {}",
                    msg.header.n_obs
                );
                assert_eq!(
                    msg.header.t.tow, 407151400,
                    "incorrect value for header.t.tow, expected 407151400, is {}",
                    msg.header.t.tow
                );
                assert_eq!(
                    msg.header.t.wn, 1838,
                    "incorrect value for header.t.wn, expected 1838, is {}",
                    msg.header.t.wn
                );
                assert_eq!(
                    msg.obs[0].L.f, 1,
                    "incorrect value for obs[0].L.f, expected 1, is {}",
                    msg.obs[0].L.f
                );
                assert_eq!(
                    msg.obs[0].L.i, -27634,
                    "incorrect value for obs[0].L.i, expected -27634, is {}",
                    msg.obs[0].L.i
                );
                assert_eq!(
                    msg.obs[0].P, 2044291972,
                    "incorrect value for obs[0].P, expected 2044291972, is {}",
                    msg.obs[0].P
                );
                assert_eq!(
                    msg.obs[0].cn0, 44,
                    "incorrect value for obs[0].cn0, expected 44, is {}",
                    msg.obs[0].cn0
                );
                assert_eq!(
                    msg.obs[0].lock, 37807,
                    "incorrect value for obs[0].lock, expected 37807, is {}",
                    msg.obs[0].lock
                );
                assert_eq!(
                    msg.obs[0].prn, 0,
                    "incorrect value for obs[0].prn, expected 0, is {}",
                    msg.obs[0].prn
                );
                assert_eq!(
                    msg.obs[1].L.f, 153,
                    "incorrect value for obs[1].L.f, expected 153, is {}",
                    msg.obs[1].L.f
                );
                assert_eq!(
                    msg.obs[1].L.i, -123500,
                    "incorrect value for obs[1].L.i, expected -123500, is {}",
                    msg.obs[1].L.i
                );
                assert_eq!(
                    msg.obs[1].P, 2110276225,
                    "incorrect value for obs[1].P, expected 2110276225, is {}",
                    msg.obs[1].P
                );
                assert_eq!(
                    msg.obs[1].cn0, 41,
                    "incorrect value for obs[1].cn0, expected 41, is {}",
                    msg.obs[1].cn0
                );
                assert_eq!(
                    msg.obs[1].lock, 45326,
                    "incorrect value for obs[1].lock, expected 45326, is {}",
                    msg.obs[1].lock
                );
                assert_eq!(
                    msg.obs[1].prn, 3,
                    "incorrect value for obs[1].prn, expected 3, is {}",
                    msg.obs[1].prn
                );
                assert_eq!(
                    msg.obs[2].L.f, 222,
                    "incorrect value for obs[2].L.f, expected 222, is {}",
                    msg.obs[2].L.f
                );
                assert_eq!(
                    msg.obs[2].L.i, -114033,
                    "incorrect value for obs[2].L.i, expected -114033, is {}",
                    msg.obs[2].L.i
                );
                assert_eq!(
                    msg.obs[2].P, 2298000000,
                    "incorrect value for obs[2].P, expected 2298000000, is {}",
                    msg.obs[2].P
                );
                assert_eq!(
                    msg.obs[2].cn0, 18,
                    "incorrect value for obs[2].cn0, expected 18, is {}",
                    msg.obs[2].cn0
                );
                assert_eq!(
                    msg.obs[2].lock, 34232,
                    "incorrect value for obs[2].lock, expected 34232, is {}",
                    msg.obs[2].lock
                );
                assert_eq!(
                    msg.obs[2].prn, 13,
                    "incorrect value for obs[2].prn, expected 13, is {}",
                    msg.obs[2].prn
                );
                assert_eq!(
                    msg.obs[3].L.f, 237,
                    "incorrect value for obs[3].L.f, expected 237, is {}",
                    msg.obs[3].L.f
                );
                assert_eq!(
                    msg.obs[3].L.i, 138026,
                    "incorrect value for obs[3].L.i, expected 138026, is {}",
                    msg.obs[3].L.i
                );
                assert_eq!(
                    msg.obs[3].P, 2259826078,
                    "incorrect value for obs[3].P, expected 2259826078, is {}",
                    msg.obs[3].P
                );
                assert_eq!(
                    msg.obs[3].cn0, 30,
                    "incorrect value for obs[3].cn0, expected 30, is {}",
                    msg.obs[3].cn0
                );
                assert_eq!(
                    msg.obs[3].lock, 24609,
                    "incorrect value for obs[3].lock, expected 24609, is {}",
                    msg.obs[3].lock
                );
                assert_eq!(
                    msg.obs[3].prn, 22,
                    "incorrect value for obs[3].prn, expected 22, is {}",
                    msg.obs[3].prn
                );
                assert_eq!(
                    msg.obs[4].L.f, 45,
                    "incorrect value for obs[4].L.f, expected 45, is {}",
                    msg.obs[4].L.f
                );
                assert_eq!(
                    msg.obs[4].L.i, -36952,
                    "incorrect value for obs[4].L.i, expected -36952, is {}",
                    msg.obs[4].L.i
                );
                assert_eq!(
                    msg.obs[4].P, 1985368870,
                    "incorrect value for obs[4].P, expected 1985368870, is {}",
                    msg.obs[4].P
                );
                assert_eq!(
                    msg.obs[4].cn0, 56,
                    "incorrect value for obs[4].cn0, expected 56, is {}",
                    msg.obs[4].cn0
                );
                assert_eq!(
                    msg.obs[4].lock, 22736,
                    "incorrect value for obs[4].lock, expected 22736, is {}",
                    msg.obs[4].lock
                );
                assert_eq!(
                    msg.obs[4].prn, 30,
                    "incorrect value for obs[4].prn, expected 30, is {}",
                    msg.obs[4].prn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgObsDepA"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
