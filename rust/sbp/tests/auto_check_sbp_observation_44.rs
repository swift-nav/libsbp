//
// Copyright (C) 2019 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_observation.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_observation_44() {
    {
        let payload: Vec<u8> = vec![
            85, 69, 0, 195, 4, 98, 56, 158, 67, 24, 46, 7, 32, 56, 235, 249, 121, 244, 114, 255,
            255, 33, 46, 67, 218, 0, 238, 203, 70, 124, 22, 25, 3, 0, 98, 43, 184, 157, 2, 176,
            133, 197, 125, 126, 71, 253, 255, 185, 39, 68, 55, 3, 60, 173, 162, 131, 98, 231, 253,
            255, 139, 30, 33, 16, 10, 128, 178, 248, 136, 42, 113, 253, 255, 40, 20, 42, 71, 13,
            246, 246, 17, 135, 255, 51, 3, 0, 64, 27, 108, 249, 22, 210, 41, 114, 118, 131, 48,
            255, 255, 31, 52, 226, 58, 30, 23, 217,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 69, 0, 195, 4, 20, 56, 158, 67, 24, 46, 7, 33, 84, 52, 164, 117, 102, 32, 0, 0,
            147, 62, 62, 250, 31, 234, 14,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 69, 0, 195, 4, 98, 0, 159, 67, 24, 46, 7, 32, 32, 209, 249, 121, 145, 114, 255,
            255, 141, 45, 67, 218, 0, 177, 128, 70, 124, 79, 27, 3, 0, 159, 44, 184, 157, 2, 59,
            135, 197, 125, 175, 69, 253, 255, 77, 40, 68, 55, 3, 211, 172, 162, 131, 177, 229, 253,
            255, 20, 31, 33, 16, 10, 128, 178, 248, 136, 116, 111, 253, 255, 94, 21, 42, 71, 13,
            182, 173, 17, 135, 37, 54, 3, 0, 214, 27, 108, 249, 22, 91, 20, 114, 118, 240, 47, 255,
            255, 129, 52, 226, 58, 30, 200, 119,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 69, 0, 195, 4, 20, 0, 159, 67, 24, 46, 7, 33, 49, 19, 164, 117, 120, 32, 0, 0, 222,
            63, 62, 250, 31, 11, 231,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 69, 0, 195, 4, 72, 96, 162, 68, 24, 46, 7, 16, 87, 132, 217, 121, 121, 148, 255,
            255, 189, 43, 175, 147, 0, 132, 64, 200, 125, 106, 31, 254, 255, 1, 41, 14, 177, 3,
            128, 178, 248, 136, 70, 68, 254, 255, 166, 18, 184, 133, 13, 24, 127, 178, 134, 6, 25,
            2, 0, 249, 28, 33, 96, 22, 170, 104, 86, 118, 67, 112, 255, 255, 203, 56, 208, 88, 30,
            43, 107,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 69, 0, 195, 4, 72, 40, 163, 68, 24, 46, 7, 16, 132, 107, 217, 121, 14, 148, 255,
            255, 1, 44, 175, 147, 0, 129, 66, 200, 125, 148, 29, 254, 255, 153, 41, 14, 177, 3,
            128, 178, 248, 136, 143, 66, 254, 255, 222, 18, 184, 133, 13, 158, 53, 178, 134, 42,
            27, 2, 0, 237, 30, 33, 96, 22, 38, 83, 86, 118, 168, 111, 255, 255, 45, 56, 208, 88,
            30, 1, 175,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 70, 0, 195, 4, 176, 0, 0, 0, 0, 0, 0, 60, 190, 0, 0, 0, 0, 0, 186, 82, 192, 0, 0,
            0, 0, 0, 76, 109, 64, 0, 0, 0, 0, 0, 132, 208, 190, 0, 0, 0, 0, 0, 254, 220, 62, 0, 0,
            0, 0, 0, 0, 113, 62, 0, 0, 0, 0, 0, 0, 133, 190, 28, 36, 25, 81, 223, 254, 52, 62, 220,
            116, 216, 39, 33, 189, 3, 64, 0, 0, 0, 156, 177, 204, 134, 63, 0, 0, 160, 220, 182, 33,
            180, 64, 152, 225, 192, 44, 254, 76, 238, 191, 41, 150, 24, 2, 148, 156, 65, 190, 252,
            90, 119, 48, 15, 215, 240, 63, 124, 127, 115, 94, 208, 16, 238, 63, 165, 115, 52, 74,
            97, 167, 246, 189, 0, 0, 0, 0, 192, 180, 229, 190, 0, 0, 0, 0, 0, 0, 112, 189, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 12, 25, 65, 46, 7, 0, 0, 0, 0, 128, 12, 25, 65, 46, 7,
            1, 1, 3, 0, 225, 156,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgEphemerisDepB(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x46,
                    "Incorrect message type, expected 0x46, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(-1.03502534329891205e-05),
                    "incorrect value for af0, expected -1.03502534329891205e-05, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(-9.09494701772928238e-13),
                    "incorrect value for af1, expected -9.09494701772928238e-13, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(6.33299350738525391e-08),
                    "incorrect value for c_ic, expected 6.33299350738525391e-08, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(-1.56462192535400391e-07),
                    "incorrect value for c_is, expected -1.56462192535400391e-07, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(2.34375000000000000e+02),
                    "incorrect value for c_rc, expected 2.34375000000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(-7.49062500000000000e+01),
                    "incorrect value for c_rs, expected -7.49062500000000000e+01, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(-3.93763184547424316e-06),
                    "incorrect value for c_uc, expected -3.93763184547424316e-06, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(6.91227614879608154e-06),
                    "incorrect value for c_us, expected 6.91227614879608154e-06, is {:e}",
                    msg.c_us
                );
                assert!(
                    msg.dn.almost_eq(4.88841790794180047e-09),
                    "incorrect value for dn, expected 4.88841790794180047e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(1.11326099140569568e-02),
                    "incorrect value for ecc, expected 1.11326099140569568e-02, is {:e}",
                    msg.ecc
                );
                assert_eq!(
                    msg.healthy, 1,
                    "incorrect value for healthy, expected 1, is {}",
                    msg.healthy
                );
                assert!(
                    msg.inc.almost_eq(9.39552483057908727e-01),
                    "incorrect value for inc, expected 9.39552483057908727e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(-3.29656588662985413e-10),
                    "incorrect value for inc_dot, expected -3.29656588662985413e-10, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iode, 0,
                    "incorrect value for iode, expected 0, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(2.46734839562723884e+00),
                    "incorrect value for m0, expected 2.46734839562723884e+00, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(-9.46898543747965782e-01),
                    "incorrect value for omega0, expected -9.46898543747965782e-01, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-8.20105589261047769e-09),
                    "incorrect value for omegadot, expected -8.20105589261047769e-09, is {:e}",
                    msg.omegadot
                );
                assert_eq!(
                    msg.prn, 3,
                    "incorrect value for prn, expected 3, is {}",
                    msg.prn
                );
                assert!(
                    msg.sqrta.almost_eq(5.15371430397033691e+03),
                    "incorrect value for sqrta, expected 5.15371430397033691e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.tgd.almost_eq(-6.51925802230834961e-09),
                    "incorrect value for tgd, expected -6.51925802230834961e-09, is {:e}",
                    msg.tgd
                );
                assert!(
                    msg.toc_tow.almost_eq(4.10400000000000000e+05),
                    "incorrect value for toc_tow, expected 4.10400000000000000e+05, is {:e}",
                    msg.toc_tow
                );
                assert_eq!(
                    msg.toc_wn, 1838,
                    "incorrect value for toc_wn, expected 1838, is {}",
                    msg.toc_wn
                );
                assert!(
                    msg.toe_tow.almost_eq(4.10400000000000000e+05),
                    "incorrect value for toe_tow, expected 4.10400000000000000e+05, is {:e}",
                    msg.toe_tow
                );
                assert_eq!(
                    msg.toe_wn, 1838,
                    "incorrect value for toe_wn, expected 1838, is {}",
                    msg.toe_wn
                );
                assert_eq!(
                    msg.valid, 1,
                    "incorrect value for valid, expected 1, is {}",
                    msg.valid
                );
                assert!(
                    msg.w.almost_eq(1.05250472004053020e+00),
                    "incorrect value for w, expected 1.05250472004053020e+00, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisDepB"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 70, 0, 195, 4, 176, 0, 0, 0, 0, 0, 0, 68, 190, 0, 0, 0, 0, 0, 72, 66, 64, 0, 0, 0,
            0, 128, 188, 115, 64, 0, 0, 0, 0, 0, 80, 193, 62, 0, 0, 0, 0, 0, 164, 204, 62, 0, 0, 0,
            0, 0, 0, 130, 62, 0, 0, 0, 0, 0, 0, 128, 62, 72, 181, 127, 6, 208, 225, 52, 62, 158,
            174, 129, 91, 27, 105, 249, 191, 0, 0, 0, 96, 204, 57, 128, 63, 0, 0, 160, 35, 146, 33,
            180, 64, 247, 169, 1, 36, 133, 206, 243, 63, 79, 11, 109, 92, 156, 208, 65, 190, 103,
            78, 3, 253, 223, 147, 255, 191, 164, 214, 90, 250, 218, 240, 238, 63, 94, 239, 187, 37,
            36, 10, 242, 61, 0, 0, 0, 0, 176, 91, 19, 63, 0, 0, 0, 0, 0, 0, 137, 189, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 128, 12, 25, 65, 46, 7, 0, 0, 0, 0, 128, 12, 25, 65, 46, 7, 1,
            1, 13, 0, 180, 21,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgEphemerisDepB(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x46,
                    "Incorrect message type, expected 0x46, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(7.38454982638359070e-05),
                    "incorrect value for af0, expected 7.38454982638359070e-05, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(-2.84217094304040074e-12),
                    "incorrect value for af1, expected -2.84217094304040074e-12, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(1.34110450744628906e-07),
                    "incorrect value for c_ic, expected 1.34110450744628906e-07, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(1.19209289550781250e-07),
                    "incorrect value for c_is, expected 1.19209289550781250e-07, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(3.15781250000000000e+02),
                    "incorrect value for c_rc, expected 3.15781250000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(3.65625000000000000e+01),
                    "incorrect value for c_rs, expected 3.65625000000000000e+01, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(2.06381082534790039e-06),
                    "incorrect value for c_uc, expected 2.06381082534790039e-06, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(3.41422855854034424e-06),
                    "incorrect value for c_us, expected 3.41422855854034424e-06, is {:e}",
                    msg.c_us
                );
                assert!(
                    msg.dn.almost_eq(4.86198823561129038e-09),
                    "incorrect value for dn, expected 4.86198823561129038e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(7.92274158447980881e-03),
                    "incorrect value for ecc, expected 7.92274158447980881e-03, is {:e}",
                    msg.ecc
                );
                assert_eq!(
                    msg.healthy, 1,
                    "incorrect value for healthy, expected 1, is {}",
                    msg.healthy
                );
                assert!(
                    msg.inc.almost_eq(9.66901291822712228e-01),
                    "incorrect value for inc, expected 9.66901291822712228e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(2.62510934634121662e-10),
                    "incorrect value for inc_dot, expected 2.62510934634121662e-10, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iode, 0,
                    "incorrect value for iode, expected 0, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(-1.58816085572008303e+00),
                    "incorrect value for m0, expected -1.58816085572008303e+00, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(1.23791994156874607e+00),
                    "incorrect value for omega0, expected 1.23791994156874607e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-8.29570269217244098e-09),
                    "incorrect value for omegadot, expected -8.29570269217244098e-09, is {:e}",
                    msg.omegadot
                );
                assert_eq!(
                    msg.prn, 13,
                    "incorrect value for prn, expected 13, is {}",
                    msg.prn
                );
                assert!(
                    msg.sqrta.almost_eq(5.15357085609436035e+03),
                    "incorrect value for sqrta, expected 5.15357085609436035e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.tgd.almost_eq(-9.31322574615478516e-09),
                    "incorrect value for tgd, expected -9.31322574615478516e-09, is {:e}",
                    msg.tgd
                );
                assert!(
                    msg.toc_tow.almost_eq(4.10400000000000000e+05),
                    "incorrect value for toc_tow, expected 4.10400000000000000e+05, is {:e}",
                    msg.toc_tow
                );
                assert_eq!(
                    msg.toc_wn, 1838,
                    "incorrect value for toc_wn, expected 1838, is {}",
                    msg.toc_wn
                );
                assert!(
                    msg.toe_tow.almost_eq(4.10400000000000000e+05),
                    "incorrect value for toe_tow, expected 4.10400000000000000e+05, is {:e}",
                    msg.toe_tow
                );
                assert_eq!(
                    msg.toe_wn, 1838,
                    "incorrect value for toe_wn, expected 1838, is {}",
                    msg.toe_wn
                );
                assert_eq!(
                    msg.valid, 1,
                    "incorrect value for valid, expected 1, is {}",
                    msg.valid
                );
                assert!(
                    msg.w.almost_eq(-1.97360228379411651e+00),
                    "incorrect value for w, expected -1.97360228379411651e+00, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisDepB"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 70, 0, 195, 4, 176, 0, 0, 0, 0, 0, 0, 56, 62, 0, 0, 0, 0, 0, 40, 81, 192, 0, 0, 0,
            0, 0, 129, 109, 64, 0, 0, 0, 0, 0, 28, 205, 190, 0, 0, 0, 0, 0, 76, 223, 62, 0, 0, 0,
            0, 0, 0, 105, 190, 0, 0, 0, 0, 0, 0, 92, 190, 134, 161, 223, 255, 243, 43, 51, 62, 146,
            176, 113, 142, 234, 164, 5, 64, 0, 0, 0, 56, 175, 140, 112, 63, 0, 0, 192, 90, 171, 33,
            180, 64, 36, 38, 237, 255, 200, 160, 237, 191, 204, 92, 63, 154, 49, 91, 65, 190, 125,
            94, 251, 132, 52, 61, 216, 63, 2, 139, 28, 27, 231, 199, 238, 63, 124, 183, 4, 180,
            194, 30, 247, 189, 0, 0, 0, 0, 0, 104, 222, 190, 0, 0, 0, 0, 0, 0, 96, 61, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 128, 12, 25, 65, 46, 7, 0, 0, 0, 0, 128, 12, 25, 65, 46, 7, 1,
            1, 0, 0, 222, 152,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgEphemerisDepB(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x46,
                    "Incorrect message type, expected 0x46, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(-7.24941492080688477e-06),
                    "incorrect value for af0, expected -7.24941492080688477e-06, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(4.54747350886464119e-13),
                    "incorrect value for af1, expected 4.54747350886464119e-13, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(-4.65661287307739258e-08),
                    "incorrect value for c_ic, expected -4.65661287307739258e-08, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(-2.60770320892333984e-08),
                    "incorrect value for c_is, expected -2.60770320892333984e-08, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(2.36031250000000000e+02),
                    "incorrect value for c_rc, expected 2.36031250000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(-6.86250000000000000e+01),
                    "incorrect value for c_rs, expected -6.86250000000000000e+01, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(-3.47010791301727295e-06),
                    "incorrect value for c_uc, expected -3.47010791301727295e-06, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(7.46175646781921387e-06),
                    "incorrect value for c_us, expected 7.46175646781921387e-06, is {:e}",
                    msg.c_us
                );
                assert!(
                    msg.dn.almost_eq(4.46375736198265652e-09),
                    "incorrect value for dn, expected 4.46375736198265652e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(4.04041714500635862e-03),
                    "incorrect value for ecc, expected 4.04041714500635862e-03, is {:e}",
                    msg.ecc
                );
                assert_eq!(
                    msg.healthy, 1,
                    "incorrect value for healthy, expected 1, is {}",
                    msg.healthy
                );
                assert!(
                    msg.inc.almost_eq(9.61902192070141604e-01),
                    "incorrect value for inc, expected 9.61902192070141604e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(-3.36442585612711049e-10),
                    "incorrect value for inc_dot, expected -3.36442585612711049e-10, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iode, 0,
                    "incorrect value for iode, expected 0, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(2.70552550587132945e+00),
                    "incorrect value for m0, expected 2.70552550587132945e+00, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(-9.25877094131639655e-01),
                    "incorrect value for omega0, expected -9.25877094131639655e-01, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-8.08212236712318227e-09),
                    "incorrect value for omegadot, expected -8.08212236712318227e-09, is {:e}",
                    msg.omegadot
                );
                assert_eq!(
                    msg.prn, 0,
                    "incorrect value for prn, expected 0, is {}",
                    msg.prn
                );
                assert!(
                    msg.sqrta.almost_eq(5.15366935348510742e+03),
                    "incorrect value for sqrta, expected 5.15366935348510742e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.tgd.almost_eq(5.58793544769287109e-09),
                    "incorrect value for tgd, expected 5.58793544769287109e-09, is {:e}",
                    msg.tgd
                );
                assert!(
                    msg.toc_tow.almost_eq(4.10400000000000000e+05),
                    "incorrect value for toc_tow, expected 4.10400000000000000e+05, is {:e}",
                    msg.toc_tow
                );
                assert_eq!(
                    msg.toc_wn, 1838,
                    "incorrect value for toc_wn, expected 1838, is {}",
                    msg.toc_wn
                );
                assert!(
                    msg.toe_tow.almost_eq(4.10400000000000000e+05),
                    "incorrect value for toe_tow, expected 4.10400000000000000e+05, is {:e}",
                    msg.toe_tow
                );
                assert_eq!(
                    msg.toe_wn, 1838,
                    "incorrect value for toe_wn, expected 1838, is {}",
                    msg.toe_wn
                );
                assert_eq!(
                    msg.valid, 1,
                    "incorrect value for valid, expected 1, is {}",
                    msg.valid
                );
                assert!(
                    msg.w.almost_eq(3.78735666146418570e-01),
                    "incorrect value for w, expected 3.78735666146418570e-01, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisDepB"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 70, 0, 195, 4, 176, 0, 0, 0, 0, 0, 0, 68, 190, 0, 0, 0, 0, 0, 72, 66, 64, 0, 0, 0,
            0, 128, 188, 115, 64, 0, 0, 0, 0, 0, 80, 193, 62, 0, 0, 0, 0, 0, 164, 204, 62, 0, 0, 0,
            0, 0, 0, 130, 62, 0, 0, 0, 0, 0, 0, 128, 62, 72, 181, 127, 6, 208, 225, 52, 62, 158,
            174, 129, 91, 27, 105, 249, 191, 0, 0, 0, 96, 204, 57, 128, 63, 0, 0, 160, 35, 146, 33,
            180, 64, 247, 169, 1, 36, 133, 206, 243, 63, 79, 11, 109, 92, 156, 208, 65, 190, 103,
            78, 3, 253, 223, 147, 255, 191, 164, 214, 90, 250, 218, 240, 238, 63, 94, 239, 187, 37,
            36, 10, 242, 61, 0, 0, 0, 0, 176, 91, 19, 63, 0, 0, 0, 0, 0, 0, 137, 189, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 128, 12, 25, 65, 46, 7, 0, 0, 0, 0, 128, 12, 25, 65, 46, 7, 1,
            1, 13, 0, 180, 21,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgEphemerisDepB(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x46,
                    "Incorrect message type, expected 0x46, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(7.38454982638359070e-05),
                    "incorrect value for af0, expected 7.38454982638359070e-05, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(-2.84217094304040074e-12),
                    "incorrect value for af1, expected -2.84217094304040074e-12, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(1.34110450744628906e-07),
                    "incorrect value for c_ic, expected 1.34110450744628906e-07, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(1.19209289550781250e-07),
                    "incorrect value for c_is, expected 1.19209289550781250e-07, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(3.15781250000000000e+02),
                    "incorrect value for c_rc, expected 3.15781250000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(3.65625000000000000e+01),
                    "incorrect value for c_rs, expected 3.65625000000000000e+01, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(2.06381082534790039e-06),
                    "incorrect value for c_uc, expected 2.06381082534790039e-06, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(3.41422855854034424e-06),
                    "incorrect value for c_us, expected 3.41422855854034424e-06, is {:e}",
                    msg.c_us
                );
                assert!(
                    msg.dn.almost_eq(4.86198823561129038e-09),
                    "incorrect value for dn, expected 4.86198823561129038e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(7.92274158447980881e-03),
                    "incorrect value for ecc, expected 7.92274158447980881e-03, is {:e}",
                    msg.ecc
                );
                assert_eq!(
                    msg.healthy, 1,
                    "incorrect value for healthy, expected 1, is {}",
                    msg.healthy
                );
                assert!(
                    msg.inc.almost_eq(9.66901291822712228e-01),
                    "incorrect value for inc, expected 9.66901291822712228e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(2.62510934634121662e-10),
                    "incorrect value for inc_dot, expected 2.62510934634121662e-10, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iode, 0,
                    "incorrect value for iode, expected 0, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(-1.58816085572008303e+00),
                    "incorrect value for m0, expected -1.58816085572008303e+00, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(1.23791994156874607e+00),
                    "incorrect value for omega0, expected 1.23791994156874607e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-8.29570269217244098e-09),
                    "incorrect value for omegadot, expected -8.29570269217244098e-09, is {:e}",
                    msg.omegadot
                );
                assert_eq!(
                    msg.prn, 13,
                    "incorrect value for prn, expected 13, is {}",
                    msg.prn
                );
                assert!(
                    msg.sqrta.almost_eq(5.15357085609436035e+03),
                    "incorrect value for sqrta, expected 5.15357085609436035e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.tgd.almost_eq(-9.31322574615478516e-09),
                    "incorrect value for tgd, expected -9.31322574615478516e-09, is {:e}",
                    msg.tgd
                );
                assert!(
                    msg.toc_tow.almost_eq(4.10400000000000000e+05),
                    "incorrect value for toc_tow, expected 4.10400000000000000e+05, is {:e}",
                    msg.toc_tow
                );
                assert_eq!(
                    msg.toc_wn, 1838,
                    "incorrect value for toc_wn, expected 1838, is {}",
                    msg.toc_wn
                );
                assert!(
                    msg.toe_tow.almost_eq(4.10400000000000000e+05),
                    "incorrect value for toe_tow, expected 4.10400000000000000e+05, is {:e}",
                    msg.toe_tow
                );
                assert_eq!(
                    msg.toe_wn, 1838,
                    "incorrect value for toe_wn, expected 1838, is {}",
                    msg.toe_wn
                );
                assert_eq!(
                    msg.valid, 1,
                    "incorrect value for valid, expected 1, is {}",
                    msg.valid
                );
                assert!(
                    msg.w.almost_eq(-1.97360228379411651e+00),
                    "incorrect value for w, expected -1.97360228379411651e+00, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisDepB"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 70, 0, 195, 4, 176, 0, 0, 0, 0, 0, 128, 85, 190, 0, 0, 0, 0, 0, 156, 69, 64, 0, 0,
            0, 0, 128, 19, 115, 64, 0, 0, 0, 0, 0, 160, 193, 62, 0, 0, 0, 0, 0, 152, 207, 62, 0, 0,
            0, 0, 0, 0, 97, 190, 0, 0, 0, 0, 0, 192, 139, 190, 26, 26, 13, 149, 16, 152, 54, 62,
            104, 7, 46, 214, 75, 84, 5, 192, 0, 0, 0, 128, 230, 82, 132, 63, 0, 0, 160, 252, 162,
            33, 180, 64, 73, 6, 130, 54, 217, 171, 242, 63, 81, 224, 163, 123, 238, 42, 66, 190,
            206, 43, 141, 67, 243, 157, 5, 192, 113, 179, 153, 187, 43, 92, 238, 63, 254, 236, 31,
            43, 224, 157, 244, 61, 0, 0, 0, 0, 232, 4, 26, 191, 0, 0, 0, 0, 0, 0, 134, 189, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 12, 25, 65, 46, 7, 0, 0, 0, 0, 128, 12, 25, 65, 46,
            7, 1, 1, 22, 0, 99, 61,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgEphemerisDepB(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x46,
                    "Incorrect message type, expected 0x46, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(-9.92552377283573151e-05),
                    "incorrect value for af0, expected -9.92552377283573151e-05, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(-2.50111042987555265e-12),
                    "incorrect value for af1, expected -2.50111042987555265e-12, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(-3.16649675369262695e-08),
                    "incorrect value for c_ic, expected -3.16649675369262695e-08, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(-2.06753611564636230e-07),
                    "incorrect value for c_is, expected -2.06753611564636230e-07, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(3.05218750000000000e+02),
                    "incorrect value for c_rc, expected 3.05218750000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(4.32187500000000000e+01),
                    "incorrect value for c_rs, expected 4.32187500000000000e+01, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(2.10106372833251953e-06),
                    "incorrect value for c_uc, expected 2.10106372833251953e-06, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(3.76626849174499512e-06),
                    "incorrect value for c_us, expected 3.76626849174499512e-06, is {:e}",
                    msg.c_us
                );
                assert!(
                    msg.dn.almost_eq(5.26057626697411973e-09),
                    "incorrect value for dn, expected 5.26057626697411973e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(9.92374494671821594e-03),
                    "incorrect value for ecc, expected 9.92374494671821594e-03, is {:e}",
                    msg.ecc
                );
                assert_eq!(
                    msg.healthy, 1,
                    "incorrect value for healthy, expected 1, is {}",
                    msg.healthy
                );
                assert!(
                    msg.inc.almost_eq(9.48751322180767187e-01),
                    "incorrect value for inc, expected 9.48751322180767187e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(3.00012496724710486e-10),
                    "incorrect value for inc_dot, expected 3.00012496724710486e-10, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iode, 0,
                    "incorrect value for iode, expected 0, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(-2.66616027191132687e+00),
                    "incorrect value for m0, expected -2.66616027191132687e+00, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(1.16695519725944252e+00),
                    "incorrect value for omega0, expected 1.16695519725944252e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-8.45999524990263948e-09),
                    "incorrect value for omegadot, expected -8.45999524990263948e-09, is {:e}",
                    msg.omegadot
                );
                assert_eq!(
                    msg.prn, 22,
                    "incorrect value for prn, expected 22, is {}",
                    msg.prn
                );
                assert!(
                    msg.sqrta.almost_eq(5.15363666725158691e+03),
                    "incorrect value for sqrta, expected 5.15363666725158691e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.tgd.almost_eq(-2.00234353542327881e-08),
                    "incorrect value for tgd, expected -2.00234353542327881e-08, is {:e}",
                    msg.tgd
                );
                assert!(
                    msg.toc_tow.almost_eq(4.10400000000000000e+05),
                    "incorrect value for toc_tow, expected 4.10400000000000000e+05, is {:e}",
                    msg.toc_tow
                );
                assert_eq!(
                    msg.toc_wn, 1838,
                    "incorrect value for toc_wn, expected 1838, is {}",
                    msg.toc_wn
                );
                assert!(
                    msg.toe_tow.almost_eq(4.10400000000000000e+05),
                    "incorrect value for toe_tow, expected 4.10400000000000000e+05, is {:e}",
                    msg.toe_tow
                );
                assert_eq!(
                    msg.toe_wn, 1838,
                    "incorrect value for toe_wn, expected 1838, is {}",
                    msg.toe_wn
                );
                assert_eq!(
                    msg.valid, 1,
                    "incorrect value for valid, expected 1, is {}",
                    msg.valid
                );
                assert!(
                    msg.w.almost_eq(-2.70212414526529354e+00),
                    "incorrect value for w, expected -2.70212414526529354e+00, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisDepB"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 70, 0, 195, 4, 176, 0, 0, 0, 0, 0, 0, 77, 190, 0, 0, 0, 0, 0, 122, 83, 192, 0, 0,
            0, 0, 0, 233, 110, 64, 0, 0, 0, 0, 0, 60, 207, 190, 0, 0, 0, 0, 0, 28, 222, 62, 0, 0,
            0, 0, 0, 128, 120, 62, 0, 0, 0, 0, 0, 0, 108, 62, 10, 230, 183, 140, 214, 230, 50, 62,
            54, 86, 196, 164, 252, 10, 255, 63, 0, 0, 0, 36, 247, 191, 128, 63, 0, 0, 160, 5, 193,
            33, 180, 64, 186, 138, 81, 129, 88, 239, 1, 64, 94, 210, 120, 170, 106, 25, 65, 190,
            103, 213, 32, 155, 227, 194, 224, 191, 156, 47, 104, 93, 101, 55, 239, 63, 196, 83,
            100, 254, 51, 54, 4, 190, 0, 0, 0, 0, 50, 242, 52, 63, 0, 0, 0, 0, 0, 0, 114, 189, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 12, 25, 65, 46, 7, 0, 0, 0, 0, 128, 12, 25, 65,
            46, 7, 1, 1, 30, 0, 170, 33,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgEphemerisDepB(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x46,
                    "Incorrect message type, expected 0x46, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.af0.almost_eq(3.19611746817827225e-04),
                    "incorrect value for af0, expected 3.19611746817827225e-04, is {:e}",
                    msg.af0
                );
                assert!(
                    msg.af1.almost_eq(-1.02318153949454427e-12),
                    "incorrect value for af1, expected -1.02318153949454427e-12, is {:e}",
                    msg.af1
                );
                assert!(
                    msg.af2.almost_eq(0.00000000000000000e+00),
                    "incorrect value for af2, expected 0.00000000000000000e+00, is {:e}",
                    msg.af2
                );
                assert!(
                    msg.c_ic.almost_eq(9.12696123123168945e-08),
                    "incorrect value for c_ic, expected 9.12696123123168945e-08, is {:e}",
                    msg.c_ic
                );
                assert!(
                    msg.c_is.almost_eq(5.21540641784667969e-08),
                    "incorrect value for c_is, expected 5.21540641784667969e-08, is {:e}",
                    msg.c_is
                );
                assert!(
                    msg.c_rc.almost_eq(2.47281250000000000e+02),
                    "incorrect value for c_rc, expected 2.47281250000000000e+02, is {:e}",
                    msg.c_rc
                );
                assert!(
                    msg.c_rs.almost_eq(-7.79062500000000000e+01),
                    "incorrect value for c_rs, expected -7.79062500000000000e+01, is {:e}",
                    msg.c_rs
                );
                assert!(
                    msg.c_uc.almost_eq(-3.72342765331268311e-06),
                    "incorrect value for c_uc, expected -3.72342765331268311e-06, is {:e}",
                    msg.c_uc
                );
                assert!(
                    msg.c_us.almost_eq(7.17863440513610840e-06),
                    "incorrect value for c_us, expected 7.17863440513610840e-06, is {:e}",
                    msg.c_us
                );
                assert!(
                    msg.dn.almost_eq(4.40089760076414576e-09),
                    "incorrect value for dn, expected 4.40089760076414576e-09, is {:e}",
                    msg.dn
                );
                assert!(
                    msg.ecc.almost_eq(8.17864493001252413e-03),
                    "incorrect value for ecc, expected 8.17864493001252413e-03, is {:e}",
                    msg.ecc
                );
                assert_eq!(
                    msg.healthy, 1,
                    "incorrect value for healthy, expected 1, is {}",
                    msg.healthy
                );
                assert!(
                    msg.inc.almost_eq(9.75512201724530126e-01),
                    "incorrect value for inc, expected 9.75512201724530126e-01, is {:e}",
                    msg.inc
                );
                assert!(
                    msg.inc_dot.almost_eq(-5.88238788220950205e-10),
                    "incorrect value for inc_dot, expected -5.88238788220950205e-10, is {:e}",
                    msg.inc_dot
                );
                assert_eq!(
                    msg.iode, 0,
                    "incorrect value for iode, expected 0, is {}",
                    msg.iode
                );
                assert!(
                    msg.m0.almost_eq(1.94018234598241923e+00),
                    "incorrect value for m0, expected 1.94018234598241923e+00, is {:e}",
                    msg.m0
                );
                assert!(
                    msg.omega0.almost_eq(2.24186802892776615e+00),
                    "incorrect value for omega0, expected 2.24186802892776615e+00, is {:e}",
                    msg.omega0
                );
                assert!(
                    msg.omegadot.almost_eq(-7.96247452616749420e-09),
                    "incorrect value for omegadot, expected -7.96247452616749420e-09, is {:e}",
                    msg.omegadot
                );
                assert_eq!(
                    msg.prn, 30,
                    "incorrect value for prn, expected 30, is {}",
                    msg.prn
                );
                assert!(
                    msg.sqrta.almost_eq(5.15375399208068848e+03),
                    "incorrect value for sqrta, expected 5.15375399208068848e+03, is {:e}",
                    msg.sqrta
                );
                assert!(
                    msg.tgd.almost_eq(-1.35041773319244385e-08),
                    "incorrect value for tgd, expected -1.35041773319244385e-08, is {:e}",
                    msg.tgd
                );
                assert!(
                    msg.toc_tow.almost_eq(4.10400000000000000e+05),
                    "incorrect value for toc_tow, expected 4.10400000000000000e+05, is {:e}",
                    msg.toc_tow
                );
                assert_eq!(
                    msg.toc_wn, 1838,
                    "incorrect value for toc_wn, expected 1838, is {}",
                    msg.toc_wn
                );
                assert!(
                    msg.toe_tow.almost_eq(4.10400000000000000e+05),
                    "incorrect value for toe_tow, expected 4.10400000000000000e+05, is {:e}",
                    msg.toe_tow
                );
                assert_eq!(
                    msg.toe_wn, 1838,
                    "incorrect value for toe_wn, expected 1838, is {}",
                    msg.toe_wn
                );
                assert_eq!(
                    msg.valid, 1,
                    "incorrect value for valid, expected 1, is {}",
                    msg.valid
                );
                assert!(
                    msg.w.almost_eq(-5.23790171608806143e-01),
                    "incorrect value for w, expected -5.23790171608806143e-01, is {:e}",
                    msg.w
                );
            }
            _ => panic!("Invalid message type! Expected a MsgEphemerisDepB"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
