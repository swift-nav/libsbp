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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingState.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_tracking_48() {
    {
        let payload: Vec<u8> = vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 197, 253, 28, 66, 1, 203, 0, 0, 0, 231, 99,
            16, 66, 1, 208, 0, 0, 0, 212, 129, 22, 66, 1, 212, 0, 0, 0, 58, 21, 28, 66, 1, 217, 0,
            0, 0, 178, 33, 40, 66, 1, 218, 0, 0, 0, 235, 189, 21, 66, 1, 220, 0, 0, 0, 29, 177, 25,
            66, 1, 222, 0, 0, 0, 43, 169, 27, 66, 1, 225, 0, 0, 0, 137, 125, 42, 66, 0, 0, 0, 0, 0,
            0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 222, 97,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDepB(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 250, 249, 27, 66, 1, 203, 0, 0, 0, 40, 143,
            11, 66, 1, 208, 0, 0, 0, 190, 200, 21, 66, 1, 212, 0, 0, 0, 251, 233, 26, 66, 1, 217,
            0, 0, 0, 209, 238, 39, 66, 1, 218, 0, 0, 0, 162, 219, 21, 66, 1, 220, 0, 0, 0, 162,
            197, 25, 66, 1, 222, 0, 0, 0, 14, 35, 28, 66, 1, 225, 0, 0, 0, 9, 153, 43, 66, 0, 0, 0,
            0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 20, 31,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDepB(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 123, 209, 27, 66, 1, 203, 0, 0, 0, 214, 64,
            15, 66, 1, 208, 0, 0, 0, 56, 55, 22, 66, 1, 212, 0, 0, 0, 91, 142, 27, 66, 1, 217, 0,
            0, 0, 253, 154, 41, 66, 1, 218, 0, 0, 0, 128, 142, 22, 66, 1, 220, 0, 0, 0, 17, 174,
            23, 66, 1, 222, 0, 0, 0, 155, 2, 29, 66, 1, 225, 0, 0, 0, 162, 100, 42, 66, 0, 0, 0, 0,
            0, 0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 233, 71,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDepB(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 120, 122, 29, 66, 1, 203, 0, 0, 0, 66, 22,
            18, 66, 1, 208, 0, 0, 0, 153, 163, 24, 66, 1, 212, 0, 0, 0, 178, 204, 28, 66, 1, 217,
            0, 0, 0, 220, 59, 38, 66, 1, 218, 0, 0, 0, 161, 27, 20, 66, 1, 220, 0, 0, 0, 125, 107,
            24, 66, 1, 222, 0, 0, 0, 242, 46, 28, 66, 1, 225, 0, 0, 0, 231, 130, 41, 66, 0, 0, 0,
            0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 73, 193,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDepB(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 19, 0, 246, 215, 99, 1, 202, 0, 0, 0, 103, 208, 30, 66, 1, 203, 0, 0, 0, 117, 24,
            18, 66, 1, 208, 0, 0, 0, 200, 173, 20, 66, 1, 212, 0, 0, 0, 137, 68, 27, 66, 1, 217, 0,
            0, 0, 243, 51, 40, 66, 1, 218, 0, 0, 0, 225, 58, 23, 66, 1, 220, 0, 0, 0, 132, 221, 22,
            66, 1, 222, 0, 0, 0, 157, 29, 26, 66, 1, 225, 0, 0, 0, 133, 21, 41, 66, 0, 0, 0, 0, 0,
            0, 0, 128, 191, 0, 0, 0, 0, 0, 0, 0, 128, 191, 126, 47,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDepB(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
