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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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
                assert_eq!(
                    msg.message_type(),
                    0x13,
                    "Incorrect message type, expected 0x13, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
