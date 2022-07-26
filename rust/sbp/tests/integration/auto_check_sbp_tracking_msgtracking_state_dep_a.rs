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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgtrackingStateDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_tracking_msgtracking_state_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 22, 0, 195, 4, 66, 1, 0, 204, 177, 51, 65, 1, 2, 198, 4, 39, 65, 1, 3, 219, 182,
            27, 65, 1, 7, 132, 120, 101, 65, 1, 10, 91, 91, 251, 64, 1, 13, 42, 37, 163, 64, 1, 22,
            130, 184, 215, 64, 1, 30, 115, 53, 75, 65, 1, 31, 16, 74, 126, 65, 1, 25, 132, 196,
            135, 64, 1, 6, 100, 59, 223, 64, 17, 225,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(1.12309074401855469e+01),
                    "incorrect value for states[0].cn0, expected 1.12309074401855469e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(1.04386653900146484e+01),
                    "incorrect value for states[1].cn0, expected 1.04386653900146484e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(9.73214244842529297e+00),
                    "incorrect value for states[2].cn0, expected 9.73214244842529297e+00, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(1.43419227600097656e+01),
                    "incorrect value for states[3].cn0, expected 1.43419227600097656e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 7,
                    "incorrect value for states[3].prn, expected 7, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(7.85490179061889648e+00),
                    "incorrect value for states[4].cn0, expected 7.85490179061889648e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 10,
                    "incorrect value for states[4].prn, expected 10, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(5.09828662872314453e+00),
                    "incorrect value for states[5].cn0, expected 5.09828662872314453e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 13,
                    "incorrect value for states[5].prn, expected 13, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(6.74127292633056641e+00),
                    "incorrect value for states[6].cn0, expected 6.74127292633056641e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 22,
                    "incorrect value for states[6].prn, expected 22, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(1.27005491256713867e+01),
                    "incorrect value for states[7].cn0, expected 1.27005491256713867e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 30,
                    "incorrect value for states[7].prn, expected 30, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(1.58930816650390625e+01),
                    "incorrect value for states[8].cn0, expected 1.58930816650390625e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 31,
                    "incorrect value for states[8].prn, expected 31, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(4.24273872375488281e+00),
                    "incorrect value for states[9].cn0, expected 4.24273872375488281e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 25,
                    "incorrect value for states[9].prn, expected 25, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 1,
                    "incorrect value for states[9].state, expected 1, is {}",
                    msg.states[9].state
                );
                assert!(
                    msg.states[10].cn0.almost_eq(6.97599983215332031e+00),
                    "incorrect value for states[10].cn0, expected 6.97599983215332031e+00, is {:e}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].prn, 6,
                    "incorrect value for states[10].prn, expected 6, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 1,
                    "incorrect value for states[10].state, expected 1, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 22, 0, 195, 4, 66, 1, 0, 216, 57, 48, 65, 1, 2, 145, 41, 46, 65, 1, 3, 4, 26, 34,
            65, 1, 7, 177, 67, 109, 65, 1, 10, 61, 80, 249, 64, 1, 13, 250, 199, 155, 64, 1, 22,
            55, 19, 215, 64, 1, 30, 138, 138, 79, 65, 1, 31, 214, 179, 119, 65, 1, 25, 53, 138,
            120, 64, 1, 6, 183, 247, 129, 64, 168, 173,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(1.10141220092773438e+01),
                    "incorrect value for states[0].cn0, expected 1.10141220092773438e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(1.08851480484008789e+01),
                    "incorrect value for states[1].cn0, expected 1.08851480484008789e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(1.01313514709472656e+01),
                    "incorrect value for states[2].cn0, expected 1.01313514709472656e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(1.48290262222290039e+01),
                    "incorrect value for states[3].cn0, expected 1.48290262222290039e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 7,
                    "incorrect value for states[3].prn, expected 7, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(7.79104471206665039e+00),
                    "incorrect value for states[4].cn0, expected 7.79104471206665039e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 10,
                    "incorrect value for states[4].prn, expected 10, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(4.86816120147705078e+00),
                    "incorrect value for states[5].cn0, expected 4.86816120147705078e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 13,
                    "incorrect value for states[5].prn, expected 13, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(6.72109556198120117e+00),
                    "incorrect value for states[6].cn0, expected 6.72109556198120117e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 22,
                    "incorrect value for states[6].prn, expected 22, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(1.29713230133056641e+01),
                    "incorrect value for states[7].cn0, expected 1.29713230133056641e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 30,
                    "incorrect value for states[7].prn, expected 30, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(1.54814052581787109e+01),
                    "incorrect value for states[8].cn0, expected 1.54814052581787109e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 31,
                    "incorrect value for states[8].prn, expected 31, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(3.88343548774719238e+00),
                    "incorrect value for states[9].cn0, expected 3.88343548774719238e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 25,
                    "incorrect value for states[9].prn, expected 25, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 1,
                    "incorrect value for states[9].state, expected 1, is {}",
                    msg.states[9].state
                );
                assert!(
                    msg.states[10].cn0.almost_eq(4.06148862838745117e+00),
                    "incorrect value for states[10].cn0, expected 4.06148862838745117e+00, is {:e}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].prn, 6,
                    "incorrect value for states[10].prn, expected 6, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 1,
                    "incorrect value for states[10].state, expected 1, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 22, 0, 195, 4, 66, 1, 0, 141, 76, 60, 65, 1, 2, 69, 139, 46, 65, 1, 3, 146, 27, 30,
            65, 1, 7, 235, 56, 97, 65, 1, 10, 141, 213, 243, 64, 1, 13, 250, 170, 166, 64, 1, 22,
            17, 101, 201, 64, 1, 30, 172, 183, 83, 65, 1, 31, 238, 193, 120, 65, 1, 25, 220, 48,
            132, 64, 1, 6, 49, 214, 54, 64, 110, 179,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(1.17686891555786133e+01),
                    "incorrect value for states[0].cn0, expected 1.17686891555786133e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(1.09090013504028320e+01),
                    "incorrect value for states[1].cn0, expected 1.09090013504028320e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(9.88173103332519531e+00),
                    "incorrect value for states[2].cn0, expected 9.88173103332519531e+00, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(1.40763959884643555e+01),
                    "incorrect value for states[3].cn0, expected 1.40763959884643555e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 7,
                    "incorrect value for states[3].prn, expected 7, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(7.61981821060180664e+00),
                    "incorrect value for states[4].cn0, expected 7.61981821060180664e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 10,
                    "incorrect value for states[4].prn, expected 10, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(5.20837116241455078e+00),
                    "incorrect value for states[5].cn0, expected 5.20837116241455078e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 13,
                    "incorrect value for states[5].prn, expected 13, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(6.29358720779418945e+00),
                    "incorrect value for states[6].cn0, expected 6.29358720779418945e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 22,
                    "incorrect value for states[6].prn, expected 22, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(1.32323417663574219e+01),
                    "incorrect value for states[7].cn0, expected 1.32323417663574219e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 30,
                    "incorrect value for states[7].prn, expected 30, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(1.55473461151123047e+01),
                    "incorrect value for states[8].cn0, expected 1.55473461151123047e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 31,
                    "incorrect value for states[8].prn, expected 31, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(4.13096427917480469e+00),
                    "incorrect value for states[9].cn0, expected 4.13096427917480469e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 25,
                    "incorrect value for states[9].prn, expected 25, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 1,
                    "incorrect value for states[9].state, expected 1, is {}",
                    msg.states[9].state
                );
                assert!(
                    msg.states[10].cn0.almost_eq(2.85682320594787598e+00),
                    "incorrect value for states[10].cn0, expected 2.85682320594787598e+00, is {:e}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].prn, 6,
                    "incorrect value for states[10].prn, expected 6, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 1,
                    "incorrect value for states[10].state, expected 1, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 22, 0, 195, 4, 66, 1, 0, 55, 143, 120, 66, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 248, 89,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(6.21398582458496094e+01),
                    "incorrect value for states[0].cn0, expected 6.21398582458496094e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[1].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 0,
                    "incorrect value for states[1].prn, expected 0, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 0,
                    "incorrect value for states[1].state, expected 0, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[2].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 0,
                    "incorrect value for states[2].prn, expected 0, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 0,
                    "incorrect value for states[2].state, expected 0, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[3].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 0,
                    "incorrect value for states[3].prn, expected 0, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 0,
                    "incorrect value for states[3].state, expected 0, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[4].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 0,
                    "incorrect value for states[4].prn, expected 0, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 0,
                    "incorrect value for states[4].state, expected 0, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[5].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 0,
                    "incorrect value for states[5].prn, expected 0, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 0,
                    "incorrect value for states[5].state, expected 0, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[6].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 0,
                    "incorrect value for states[6].prn, expected 0, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 0,
                    "incorrect value for states[6].state, expected 0, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[7].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 0,
                    "incorrect value for states[7].prn, expected 0, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 0,
                    "incorrect value for states[7].state, expected 0, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[8].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 0,
                    "incorrect value for states[8].prn, expected 0, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 0,
                    "incorrect value for states[8].state, expected 0, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 0,
                    "incorrect value for states[9].prn, expected 0, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].prn, 0,
                    "incorrect value for states[10].prn, expected 0, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 22, 0, 195, 4, 66, 1, 0, 218, 14, 19, 66, 1, 2, 210, 3, 21, 65, 1, 3, 234, 214,
            134, 65, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0,
            128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0,
            128, 191, 84, 101,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.67645034790039062e+01),
                    "incorrect value for states[0].cn0, expected 3.67645034790039062e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(9.31343269348144531e+00),
                    "incorrect value for states[1].cn0, expected 9.31343269348144531e+00, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(1.68549385070800781e+01),
                    "incorrect value for states[2].cn0, expected 1.68549385070800781e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[3].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 0,
                    "incorrect value for states[3].prn, expected 0, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 0,
                    "incorrect value for states[3].state, expected 0, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[4].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 0,
                    "incorrect value for states[4].prn, expected 0, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 0,
                    "incorrect value for states[4].state, expected 0, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[5].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 0,
                    "incorrect value for states[5].prn, expected 0, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 0,
                    "incorrect value for states[5].state, expected 0, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[6].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 0,
                    "incorrect value for states[6].prn, expected 0, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 0,
                    "incorrect value for states[6].state, expected 0, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[7].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 0,
                    "incorrect value for states[7].prn, expected 0, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 0,
                    "incorrect value for states[7].state, expected 0, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[8].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 0,
                    "incorrect value for states[8].prn, expected 0, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 0,
                    "incorrect value for states[8].state, expected 0, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 0,
                    "incorrect value for states[9].prn, expected 0, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].prn, 0,
                    "incorrect value for states[10].prn, expected 0, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 22, 0, 195, 4, 66, 1, 0, 98, 39, 219, 65, 1, 2, 0, 0, 56, 64, 1, 3, 121, 123, 7,
            65, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 37, 123,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(2.73942298889160156e+01),
                    "incorrect value for states[0].cn0, expected 2.73942298889160156e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(2.87500000000000000e+00),
                    "incorrect value for states[1].cn0, expected 2.87500000000000000e+00, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(8.46764469146728516e+00),
                    "incorrect value for states[2].cn0, expected 8.46764469146728516e+00, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[3].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 0,
                    "incorrect value for states[3].prn, expected 0, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 0,
                    "incorrect value for states[3].state, expected 0, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[4].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 0,
                    "incorrect value for states[4].prn, expected 0, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 0,
                    "incorrect value for states[4].state, expected 0, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[5].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 0,
                    "incorrect value for states[5].prn, expected 0, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 0,
                    "incorrect value for states[5].state, expected 0, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[6].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 0,
                    "incorrect value for states[6].prn, expected 0, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 0,
                    "incorrect value for states[6].state, expected 0, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[7].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 0,
                    "incorrect value for states[7].prn, expected 0, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 0,
                    "incorrect value for states[7].state, expected 0, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[8].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 0,
                    "incorrect value for states[8].prn, expected 0, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 0,
                    "incorrect value for states[8].state, expected 0, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 0,
                    "incorrect value for states[9].prn, expected 0, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].prn, 0,
                    "incorrect value for states[10].prn, expected 0, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
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
fn test_json2sbp_auto_check_sbp_tracking_msgtracking_state_dep_a() {
    {
        let json_input = r#"{"sender": 1219, "msg_type": 22, "states": [{"state": 1, "prn": 0, "cn0": 11.230907440185547}, {"state": 1, "prn": 2, "cn0": 10.438665390014648}, {"state": 1, "prn": 3, "cn0": 9.732142448425293}, {"state": 1, "prn": 7, "cn0": 14.341922760009766}, {"state": 1, "prn": 10, "cn0": 7.8549017906188965}, {"state": 1, "prn": 13, "cn0": 5.0982866287231445}, {"state": 1, "prn": 22, "cn0": 6.741272926330566}, {"state": 1, "prn": 30, "cn0": 12.700549125671387}, {"state": 1, "prn": 31, "cn0": 15.893081665039062}, {"state": 1, "prn": 25, "cn0": 4.242738723754883}, {"state": 1, "prn": 6, "cn0": 6.97599983215332}], "crc": 57617, "length": 66, "preamble": 85, "payload": "AQDMsTNBAQLGBCdBAQPbthtBAQeEeGVBAQpbW/tAAQ0qJaNAARaCuNdAAR5zNUtBAR8QSn5BARmExIdAAQZkO99A"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(1.12309074401855469e+01),
                    "incorrect value for states[0].cn0, expected 1.12309074401855469e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(1.04386653900146484e+01),
                    "incorrect value for states[1].cn0, expected 1.04386653900146484e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(9.73214244842529297e+00),
                    "incorrect value for states[2].cn0, expected 9.73214244842529297e+00, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(1.43419227600097656e+01),
                    "incorrect value for states[3].cn0, expected 1.43419227600097656e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 7,
                    "incorrect value for states[3].prn, expected 7, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(7.85490179061889648e+00),
                    "incorrect value for states[4].cn0, expected 7.85490179061889648e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 10,
                    "incorrect value for states[4].prn, expected 10, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(5.09828662872314453e+00),
                    "incorrect value for states[5].cn0, expected 5.09828662872314453e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 13,
                    "incorrect value for states[5].prn, expected 13, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(6.74127292633056641e+00),
                    "incorrect value for states[6].cn0, expected 6.74127292633056641e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 22,
                    "incorrect value for states[6].prn, expected 22, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(1.27005491256713867e+01),
                    "incorrect value for states[7].cn0, expected 1.27005491256713867e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 30,
                    "incorrect value for states[7].prn, expected 30, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(1.58930816650390625e+01),
                    "incorrect value for states[8].cn0, expected 1.58930816650390625e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 31,
                    "incorrect value for states[8].prn, expected 31, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(4.24273872375488281e+00),
                    "incorrect value for states[9].cn0, expected 4.24273872375488281e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 25,
                    "incorrect value for states[9].prn, expected 25, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 1,
                    "incorrect value for states[9].state, expected 1, is {}",
                    msg.states[9].state
                );
                assert!(
                    msg.states[10].cn0.almost_eq(6.97599983215332031e+00),
                    "incorrect value for states[10].cn0, expected 6.97599983215332031e+00, is {:e}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].prn, 6,
                    "incorrect value for states[10].prn, expected 6, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 1,
                    "incorrect value for states[10].state, expected 1, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };
    }
    {
        let json_input = r#"{"sender": 1219, "msg_type": 22, "states": [{"state": 1, "prn": 0, "cn0": 11.014122009277344}, {"state": 1, "prn": 2, "cn0": 10.885148048400879}, {"state": 1, "prn": 3, "cn0": 10.131351470947266}, {"state": 1, "prn": 7, "cn0": 14.829026222229004}, {"state": 1, "prn": 10, "cn0": 7.79104471206665}, {"state": 1, "prn": 13, "cn0": 4.868161201477051}, {"state": 1, "prn": 22, "cn0": 6.721095561981201}, {"state": 1, "prn": 30, "cn0": 12.971323013305664}, {"state": 1, "prn": 31, "cn0": 15.481405258178711}, {"state": 1, "prn": 25, "cn0": 3.8834354877471924}, {"state": 1, "prn": 6, "cn0": 4.061488628387451}], "crc": 44456, "length": 66, "preamble": 85, "payload": "AQDYOTBBAQKRKS5BAQMEGiJBAQexQ21BAQo9UPlAAQ36x5tAARY3E9dAAR6Kik9BAR/Ws3dBARk1inhAAQa394FA"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(1.10141220092773438e+01),
                    "incorrect value for states[0].cn0, expected 1.10141220092773438e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(1.08851480484008789e+01),
                    "incorrect value for states[1].cn0, expected 1.08851480484008789e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(1.01313514709472656e+01),
                    "incorrect value for states[2].cn0, expected 1.01313514709472656e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(1.48290262222290039e+01),
                    "incorrect value for states[3].cn0, expected 1.48290262222290039e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 7,
                    "incorrect value for states[3].prn, expected 7, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(7.79104471206665039e+00),
                    "incorrect value for states[4].cn0, expected 7.79104471206665039e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 10,
                    "incorrect value for states[4].prn, expected 10, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(4.86816120147705078e+00),
                    "incorrect value for states[5].cn0, expected 4.86816120147705078e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 13,
                    "incorrect value for states[5].prn, expected 13, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(6.72109556198120117e+00),
                    "incorrect value for states[6].cn0, expected 6.72109556198120117e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 22,
                    "incorrect value for states[6].prn, expected 22, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(1.29713230133056641e+01),
                    "incorrect value for states[7].cn0, expected 1.29713230133056641e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 30,
                    "incorrect value for states[7].prn, expected 30, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(1.54814052581787109e+01),
                    "incorrect value for states[8].cn0, expected 1.54814052581787109e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 31,
                    "incorrect value for states[8].prn, expected 31, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(3.88343548774719238e+00),
                    "incorrect value for states[9].cn0, expected 3.88343548774719238e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 25,
                    "incorrect value for states[9].prn, expected 25, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 1,
                    "incorrect value for states[9].state, expected 1, is {}",
                    msg.states[9].state
                );
                assert!(
                    msg.states[10].cn0.almost_eq(4.06148862838745117e+00),
                    "incorrect value for states[10].cn0, expected 4.06148862838745117e+00, is {:e}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].prn, 6,
                    "incorrect value for states[10].prn, expected 6, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 1,
                    "incorrect value for states[10].state, expected 1, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };
    }
    {
        let json_input = r#"{"sender": 1219, "msg_type": 22, "states": [{"state": 1, "prn": 0, "cn0": 11.768689155578613}, {"state": 1, "prn": 2, "cn0": 10.909001350402832}, {"state": 1, "prn": 3, "cn0": 9.881731033325195}, {"state": 1, "prn": 7, "cn0": 14.076395988464355}, {"state": 1, "prn": 10, "cn0": 7.619818210601807}, {"state": 1, "prn": 13, "cn0": 5.208371162414551}, {"state": 1, "prn": 22, "cn0": 6.2935872077941895}, {"state": 1, "prn": 30, "cn0": 13.232341766357422}, {"state": 1, "prn": 31, "cn0": 15.547346115112305}, {"state": 1, "prn": 25, "cn0": 4.130964279174805}, {"state": 1, "prn": 6, "cn0": 2.856823205947876}], "crc": 45934, "length": 66, "preamble": 85, "payload": "AQCNTDxBAQJFiy5BAQOSGx5BAQfrOGFBAQqN1fNAAQ36qqZAARYRZclAAR6st1NBAR/uwXhBARncMIRAAQYx1jZA"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(1.17686891555786133e+01),
                    "incorrect value for states[0].cn0, expected 1.17686891555786133e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(1.09090013504028320e+01),
                    "incorrect value for states[1].cn0, expected 1.09090013504028320e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(9.88173103332519531e+00),
                    "incorrect value for states[2].cn0, expected 9.88173103332519531e+00, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(1.40763959884643555e+01),
                    "incorrect value for states[3].cn0, expected 1.40763959884643555e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 7,
                    "incorrect value for states[3].prn, expected 7, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(7.61981821060180664e+00),
                    "incorrect value for states[4].cn0, expected 7.61981821060180664e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 10,
                    "incorrect value for states[4].prn, expected 10, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(5.20837116241455078e+00),
                    "incorrect value for states[5].cn0, expected 5.20837116241455078e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 13,
                    "incorrect value for states[5].prn, expected 13, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(6.29358720779418945e+00),
                    "incorrect value for states[6].cn0, expected 6.29358720779418945e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 22,
                    "incorrect value for states[6].prn, expected 22, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(1.32323417663574219e+01),
                    "incorrect value for states[7].cn0, expected 1.32323417663574219e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 30,
                    "incorrect value for states[7].prn, expected 30, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(1.55473461151123047e+01),
                    "incorrect value for states[8].cn0, expected 1.55473461151123047e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 31,
                    "incorrect value for states[8].prn, expected 31, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(4.13096427917480469e+00),
                    "incorrect value for states[9].cn0, expected 4.13096427917480469e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 25,
                    "incorrect value for states[9].prn, expected 25, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 1,
                    "incorrect value for states[9].state, expected 1, is {}",
                    msg.states[9].state
                );
                assert!(
                    msg.states[10].cn0.almost_eq(2.85682320594787598e+00),
                    "incorrect value for states[10].cn0, expected 2.85682320594787598e+00, is {:e}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].prn, 6,
                    "incorrect value for states[10].prn, expected 6, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 1,
                    "incorrect value for states[10].state, expected 1, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };
    }
    {
        let json_input = r#"{"sender": 1219, "msg_type": 22, "states": [{"state": 1, "prn": 0, "cn0": 62.13985824584961}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}], "crc": 23032, "length": 66, "preamble": 85, "payload": "AQA3j3hCAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(6.21398582458496094e+01),
                    "incorrect value for states[0].cn0, expected 6.21398582458496094e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[1].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 0,
                    "incorrect value for states[1].prn, expected 0, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 0,
                    "incorrect value for states[1].state, expected 0, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[2].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 0,
                    "incorrect value for states[2].prn, expected 0, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 0,
                    "incorrect value for states[2].state, expected 0, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[3].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 0,
                    "incorrect value for states[3].prn, expected 0, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 0,
                    "incorrect value for states[3].state, expected 0, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[4].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 0,
                    "incorrect value for states[4].prn, expected 0, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 0,
                    "incorrect value for states[4].state, expected 0, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[5].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 0,
                    "incorrect value for states[5].prn, expected 0, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 0,
                    "incorrect value for states[5].state, expected 0, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[6].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 0,
                    "incorrect value for states[6].prn, expected 0, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 0,
                    "incorrect value for states[6].state, expected 0, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[7].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 0,
                    "incorrect value for states[7].prn, expected 0, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 0,
                    "incorrect value for states[7].state, expected 0, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[8].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 0,
                    "incorrect value for states[8].prn, expected 0, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 0,
                    "incorrect value for states[8].state, expected 0, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 0,
                    "incorrect value for states[9].prn, expected 0, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].prn, 0,
                    "incorrect value for states[10].prn, expected 0, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };
    }
    {
        let json_input = r#"{"sender": 1219, "msg_type": 22, "states": [{"state": 1, "prn": 0, "cn0": 36.764503479003906}, {"state": 1, "prn": 2, "cn0": 9.313432693481445}, {"state": 1, "prn": 3, "cn0": 16.854938507080078}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}], "crc": 25940, "length": 66, "preamble": 85, "payload": "AQDaDhNCAQLSAxVBAQPq1oZBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.67645034790039062e+01),
                    "incorrect value for states[0].cn0, expected 3.67645034790039062e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(9.31343269348144531e+00),
                    "incorrect value for states[1].cn0, expected 9.31343269348144531e+00, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(1.68549385070800781e+01),
                    "incorrect value for states[2].cn0, expected 1.68549385070800781e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[3].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 0,
                    "incorrect value for states[3].prn, expected 0, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 0,
                    "incorrect value for states[3].state, expected 0, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[4].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 0,
                    "incorrect value for states[4].prn, expected 0, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 0,
                    "incorrect value for states[4].state, expected 0, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[5].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 0,
                    "incorrect value for states[5].prn, expected 0, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 0,
                    "incorrect value for states[5].state, expected 0, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[6].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 0,
                    "incorrect value for states[6].prn, expected 0, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 0,
                    "incorrect value for states[6].state, expected 0, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[7].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 0,
                    "incorrect value for states[7].prn, expected 0, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 0,
                    "incorrect value for states[7].state, expected 0, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[8].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 0,
                    "incorrect value for states[8].prn, expected 0, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 0,
                    "incorrect value for states[8].state, expected 0, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 0,
                    "incorrect value for states[9].prn, expected 0, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].prn, 0,
                    "incorrect value for states[10].prn, expected 0, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };
    }
    {
        let json_input = r#"{"sender": 1219, "msg_type": 22, "states": [{"state": 1, "prn": 0, "cn0": 27.394229888916016}, {"state": 1, "prn": 2, "cn0": 2.875}, {"state": 1, "prn": 3, "cn0": 8.467644691467285}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}, {"state": 0, "prn": 0, "cn0": -1.0}], "crc": 31525, "length": 66, "preamble": 85, "payload": "AQBiJ9tBAQIAADhAAQN5ewdBAAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/AAAAAIC/"}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(2.73942298889160156e+01),
                    "incorrect value for states[0].cn0, expected 2.73942298889160156e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(2.87500000000000000e+00),
                    "incorrect value for states[1].cn0, expected 2.87500000000000000e+00, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(8.46764469146728516e+00),
                    "incorrect value for states[2].cn0, expected 8.46764469146728516e+00, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[3].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 0,
                    "incorrect value for states[3].prn, expected 0, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 0,
                    "incorrect value for states[3].state, expected 0, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[4].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 0,
                    "incorrect value for states[4].prn, expected 0, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 0,
                    "incorrect value for states[4].state, expected 0, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[5].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 0,
                    "incorrect value for states[5].prn, expected 0, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 0,
                    "incorrect value for states[5].state, expected 0, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[6].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 0,
                    "incorrect value for states[6].prn, expected 0, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 0,
                    "incorrect value for states[6].state, expected 0, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[7].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 0,
                    "incorrect value for states[7].prn, expected 0, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 0,
                    "incorrect value for states[7].state, expected 0, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[8].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 0,
                    "incorrect value for states[8].prn, expected 0, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 0,
                    "incorrect value for states[8].state, expected 0, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 0,
                    "incorrect value for states[9].prn, expected 0, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].prn, 0,
                    "incorrect value for states[10].prn, expected 0, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_tracking_msgtracking_state_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_tracking_msgtracking_state_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 22, 0, 195, 4, 66, 1, 0, 204, 177, 51, 65, 1, 2, 198, 4, 39, 65, 1, 3, 219, 182,
            27, 65, 1, 7, 132, 120, 101, 65, 1, 10, 91, 91, 251, 64, 1, 13, 42, 37, 163, 64, 1, 22,
            130, 184, 215, 64, 1, 30, 115, 53, 75, 65, 1, 31, 16, 74, 126, 65, 1, 25, 132, 196,
            135, 64, 1, 6, 100, 59, 223, 64, 17, 225,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingStateDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(1.12309074401855469e+01),
                    "incorrect value for states[0].cn0, expected 1.12309074401855469e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(1.04386653900146484e+01),
                    "incorrect value for states[1].cn0, expected 1.04386653900146484e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(9.73214244842529297e+00),
                    "incorrect value for states[2].cn0, expected 9.73214244842529297e+00, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(1.43419227600097656e+01),
                    "incorrect value for states[3].cn0, expected 1.43419227600097656e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 7,
                    "incorrect value for states[3].prn, expected 7, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(7.85490179061889648e+00),
                    "incorrect value for states[4].cn0, expected 7.85490179061889648e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 10,
                    "incorrect value for states[4].prn, expected 10, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(5.09828662872314453e+00),
                    "incorrect value for states[5].cn0, expected 5.09828662872314453e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 13,
                    "incorrect value for states[5].prn, expected 13, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(6.74127292633056641e+00),
                    "incorrect value for states[6].cn0, expected 6.74127292633056641e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 22,
                    "incorrect value for states[6].prn, expected 22, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(1.27005491256713867e+01),
                    "incorrect value for states[7].cn0, expected 1.27005491256713867e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 30,
                    "incorrect value for states[7].prn, expected 30, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(1.58930816650390625e+01),
                    "incorrect value for states[8].cn0, expected 1.58930816650390625e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 31,
                    "incorrect value for states[8].prn, expected 31, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(4.24273872375488281e+00),
                    "incorrect value for states[9].cn0, expected 4.24273872375488281e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 25,
                    "incorrect value for states[9].prn, expected 25, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 1,
                    "incorrect value for states[9].state, expected 1, is {}",
                    msg.states[9].state
                );
                assert!(
                    msg.states[10].cn0.almost_eq(6.97599983215332031e+00),
                    "incorrect value for states[10].cn0, expected 6.97599983215332031e+00, is {:e}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].prn, 6,
                    "incorrect value for states[10].prn, expected 6, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 1,
                    "incorrect value for states[10].state, expected 1, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 22, 0, 195, 4, 66, 1, 0, 216, 57, 48, 65, 1, 2, 145, 41, 46, 65, 1, 3, 4, 26, 34,
            65, 1, 7, 177, 67, 109, 65, 1, 10, 61, 80, 249, 64, 1, 13, 250, 199, 155, 64, 1, 22,
            55, 19, 215, 64, 1, 30, 138, 138, 79, 65, 1, 31, 214, 179, 119, 65, 1, 25, 53, 138,
            120, 64, 1, 6, 183, 247, 129, 64, 168, 173,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingStateDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(1.10141220092773438e+01),
                    "incorrect value for states[0].cn0, expected 1.10141220092773438e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(1.08851480484008789e+01),
                    "incorrect value for states[1].cn0, expected 1.08851480484008789e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(1.01313514709472656e+01),
                    "incorrect value for states[2].cn0, expected 1.01313514709472656e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(1.48290262222290039e+01),
                    "incorrect value for states[3].cn0, expected 1.48290262222290039e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 7,
                    "incorrect value for states[3].prn, expected 7, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(7.79104471206665039e+00),
                    "incorrect value for states[4].cn0, expected 7.79104471206665039e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 10,
                    "incorrect value for states[4].prn, expected 10, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(4.86816120147705078e+00),
                    "incorrect value for states[5].cn0, expected 4.86816120147705078e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 13,
                    "incorrect value for states[5].prn, expected 13, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(6.72109556198120117e+00),
                    "incorrect value for states[6].cn0, expected 6.72109556198120117e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 22,
                    "incorrect value for states[6].prn, expected 22, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(1.29713230133056641e+01),
                    "incorrect value for states[7].cn0, expected 1.29713230133056641e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 30,
                    "incorrect value for states[7].prn, expected 30, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(1.54814052581787109e+01),
                    "incorrect value for states[8].cn0, expected 1.54814052581787109e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 31,
                    "incorrect value for states[8].prn, expected 31, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(3.88343548774719238e+00),
                    "incorrect value for states[9].cn0, expected 3.88343548774719238e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 25,
                    "incorrect value for states[9].prn, expected 25, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 1,
                    "incorrect value for states[9].state, expected 1, is {}",
                    msg.states[9].state
                );
                assert!(
                    msg.states[10].cn0.almost_eq(4.06148862838745117e+00),
                    "incorrect value for states[10].cn0, expected 4.06148862838745117e+00, is {:e}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].prn, 6,
                    "incorrect value for states[10].prn, expected 6, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 1,
                    "incorrect value for states[10].state, expected 1, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 22, 0, 195, 4, 66, 1, 0, 141, 76, 60, 65, 1, 2, 69, 139, 46, 65, 1, 3, 146, 27, 30,
            65, 1, 7, 235, 56, 97, 65, 1, 10, 141, 213, 243, 64, 1, 13, 250, 170, 166, 64, 1, 22,
            17, 101, 201, 64, 1, 30, 172, 183, 83, 65, 1, 31, 238, 193, 120, 65, 1, 25, 220, 48,
            132, 64, 1, 6, 49, 214, 54, 64, 110, 179,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingStateDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(1.17686891555786133e+01),
                    "incorrect value for states[0].cn0, expected 1.17686891555786133e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(1.09090013504028320e+01),
                    "incorrect value for states[1].cn0, expected 1.09090013504028320e+01, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(9.88173103332519531e+00),
                    "incorrect value for states[2].cn0, expected 9.88173103332519531e+00, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(1.40763959884643555e+01),
                    "incorrect value for states[3].cn0, expected 1.40763959884643555e+01, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 7,
                    "incorrect value for states[3].prn, expected 7, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 1,
                    "incorrect value for states[3].state, expected 1, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(7.61981821060180664e+00),
                    "incorrect value for states[4].cn0, expected 7.61981821060180664e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 10,
                    "incorrect value for states[4].prn, expected 10, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 1,
                    "incorrect value for states[4].state, expected 1, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(5.20837116241455078e+00),
                    "incorrect value for states[5].cn0, expected 5.20837116241455078e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 13,
                    "incorrect value for states[5].prn, expected 13, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 1,
                    "incorrect value for states[5].state, expected 1, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(6.29358720779418945e+00),
                    "incorrect value for states[6].cn0, expected 6.29358720779418945e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 22,
                    "incorrect value for states[6].prn, expected 22, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 1,
                    "incorrect value for states[6].state, expected 1, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(1.32323417663574219e+01),
                    "incorrect value for states[7].cn0, expected 1.32323417663574219e+01, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 30,
                    "incorrect value for states[7].prn, expected 30, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 1,
                    "incorrect value for states[7].state, expected 1, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(1.55473461151123047e+01),
                    "incorrect value for states[8].cn0, expected 1.55473461151123047e+01, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 31,
                    "incorrect value for states[8].prn, expected 31, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 1,
                    "incorrect value for states[8].state, expected 1, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(4.13096427917480469e+00),
                    "incorrect value for states[9].cn0, expected 4.13096427917480469e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 25,
                    "incorrect value for states[9].prn, expected 25, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 1,
                    "incorrect value for states[9].state, expected 1, is {}",
                    msg.states[9].state
                );
                assert!(
                    msg.states[10].cn0.almost_eq(2.85682320594787598e+00),
                    "incorrect value for states[10].cn0, expected 2.85682320594787598e+00, is {:e}",
                    msg.states[10].cn0
                );
                assert_eq!(
                    msg.states[10].prn, 6,
                    "incorrect value for states[10].prn, expected 6, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 1,
                    "incorrect value for states[10].state, expected 1, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 22, 0, 195, 4, 66, 1, 0, 55, 143, 120, 66, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 248, 89,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingStateDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(6.21398582458496094e+01),
                    "incorrect value for states[0].cn0, expected 6.21398582458496094e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[1].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 0,
                    "incorrect value for states[1].prn, expected 0, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 0,
                    "incorrect value for states[1].state, expected 0, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[2].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 0,
                    "incorrect value for states[2].prn, expected 0, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 0,
                    "incorrect value for states[2].state, expected 0, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[3].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 0,
                    "incorrect value for states[3].prn, expected 0, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 0,
                    "incorrect value for states[3].state, expected 0, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[4].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 0,
                    "incorrect value for states[4].prn, expected 0, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 0,
                    "incorrect value for states[4].state, expected 0, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[5].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 0,
                    "incorrect value for states[5].prn, expected 0, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 0,
                    "incorrect value for states[5].state, expected 0, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[6].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 0,
                    "incorrect value for states[6].prn, expected 0, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 0,
                    "incorrect value for states[6].state, expected 0, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[7].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 0,
                    "incorrect value for states[7].prn, expected 0, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 0,
                    "incorrect value for states[7].state, expected 0, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[8].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 0,
                    "incorrect value for states[8].prn, expected 0, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 0,
                    "incorrect value for states[8].state, expected 0, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 0,
                    "incorrect value for states[9].prn, expected 0, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].prn, 0,
                    "incorrect value for states[10].prn, expected 0, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 22, 0, 195, 4, 66, 1, 0, 218, 14, 19, 66, 1, 2, 210, 3, 21, 65, 1, 3, 234, 214,
            134, 65, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0,
            128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0,
            128, 191, 84, 101,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingStateDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(3.67645034790039062e+01),
                    "incorrect value for states[0].cn0, expected 3.67645034790039062e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(9.31343269348144531e+00),
                    "incorrect value for states[1].cn0, expected 9.31343269348144531e+00, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(1.68549385070800781e+01),
                    "incorrect value for states[2].cn0, expected 1.68549385070800781e+01, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[3].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 0,
                    "incorrect value for states[3].prn, expected 0, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 0,
                    "incorrect value for states[3].state, expected 0, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[4].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 0,
                    "incorrect value for states[4].prn, expected 0, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 0,
                    "incorrect value for states[4].state, expected 0, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[5].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 0,
                    "incorrect value for states[5].prn, expected 0, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 0,
                    "incorrect value for states[5].state, expected 0, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[6].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 0,
                    "incorrect value for states[6].prn, expected 0, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 0,
                    "incorrect value for states[6].state, expected 0, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[7].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 0,
                    "incorrect value for states[7].prn, expected 0, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 0,
                    "incorrect value for states[7].state, expected 0, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[8].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 0,
                    "incorrect value for states[8].prn, expected 0, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 0,
                    "incorrect value for states[8].state, expected 0, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 0,
                    "incorrect value for states[9].prn, expected 0, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].prn, 0,
                    "incorrect value for states[10].prn, expected 0, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 22, 0, 195, 4, 66, 1, 0, 98, 39, 219, 65, 1, 2, 0, 0, 56, 64, 1, 3, 121, 123, 7,
            65, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 37, 123,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingStateDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.states[0].cn0.almost_eq(2.73942298889160156e+01),
                    "incorrect value for states[0].cn0, expected 2.73942298889160156e+01, is {:e}",
                    msg.states[0].cn0
                );
                assert_eq!(
                    msg.states[0].prn, 0,
                    "incorrect value for states[0].prn, expected 0, is {}",
                    msg.states[0].prn
                );
                assert_eq!(
                    msg.states[0].state, 1,
                    "incorrect value for states[0].state, expected 1, is {}",
                    msg.states[0].state
                );
                assert!(
                    msg.states[1].cn0.almost_eq(2.87500000000000000e+00),
                    "incorrect value for states[1].cn0, expected 2.87500000000000000e+00, is {:e}",
                    msg.states[1].cn0
                );
                assert_eq!(
                    msg.states[1].prn, 2,
                    "incorrect value for states[1].prn, expected 2, is {}",
                    msg.states[1].prn
                );
                assert_eq!(
                    msg.states[1].state, 1,
                    "incorrect value for states[1].state, expected 1, is {}",
                    msg.states[1].state
                );
                assert!(
                    msg.states[2].cn0.almost_eq(8.46764469146728516e+00),
                    "incorrect value for states[2].cn0, expected 8.46764469146728516e+00, is {:e}",
                    msg.states[2].cn0
                );
                assert_eq!(
                    msg.states[2].prn, 3,
                    "incorrect value for states[2].prn, expected 3, is {}",
                    msg.states[2].prn
                );
                assert_eq!(
                    msg.states[2].state, 1,
                    "incorrect value for states[2].state, expected 1, is {}",
                    msg.states[2].state
                );
                assert!(
                    msg.states[3].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[3].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[3].cn0
                );
                assert_eq!(
                    msg.states[3].prn, 0,
                    "incorrect value for states[3].prn, expected 0, is {}",
                    msg.states[3].prn
                );
                assert_eq!(
                    msg.states[3].state, 0,
                    "incorrect value for states[3].state, expected 0, is {}",
                    msg.states[3].state
                );
                assert!(
                    msg.states[4].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[4].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[4].cn0
                );
                assert_eq!(
                    msg.states[4].prn, 0,
                    "incorrect value for states[4].prn, expected 0, is {}",
                    msg.states[4].prn
                );
                assert_eq!(
                    msg.states[4].state, 0,
                    "incorrect value for states[4].state, expected 0, is {}",
                    msg.states[4].state
                );
                assert!(
                    msg.states[5].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[5].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[5].cn0
                );
                assert_eq!(
                    msg.states[5].prn, 0,
                    "incorrect value for states[5].prn, expected 0, is {}",
                    msg.states[5].prn
                );
                assert_eq!(
                    msg.states[5].state, 0,
                    "incorrect value for states[5].state, expected 0, is {}",
                    msg.states[5].state
                );
                assert!(
                    msg.states[6].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[6].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[6].cn0
                );
                assert_eq!(
                    msg.states[6].prn, 0,
                    "incorrect value for states[6].prn, expected 0, is {}",
                    msg.states[6].prn
                );
                assert_eq!(
                    msg.states[6].state, 0,
                    "incorrect value for states[6].state, expected 0, is {}",
                    msg.states[6].state
                );
                assert!(
                    msg.states[7].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[7].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[7].cn0
                );
                assert_eq!(
                    msg.states[7].prn, 0,
                    "incorrect value for states[7].prn, expected 0, is {}",
                    msg.states[7].prn
                );
                assert_eq!(
                    msg.states[7].state, 0,
                    "incorrect value for states[7].state, expected 0, is {}",
                    msg.states[7].state
                );
                assert!(
                    msg.states[8].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[8].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[8].cn0
                );
                assert_eq!(
                    msg.states[8].prn, 0,
                    "incorrect value for states[8].prn, expected 0, is {}",
                    msg.states[8].prn
                );
                assert_eq!(
                    msg.states[8].state, 0,
                    "incorrect value for states[8].state, expected 0, is {}",
                    msg.states[8].state
                );
                assert!(
                    msg.states[9].cn0.almost_eq(-1.00000000000000000e+00),
                    "incorrect value for states[9].cn0, expected -1.00000000000000000e+00, is {:e}",
                    msg.states[9].cn0
                );
                assert_eq!(
                    msg.states[9].prn, 0,
                    "incorrect value for states[9].prn, expected 0, is {}",
                    msg.states[9].prn
                );
                assert_eq!(
                    msg.states[9].state, 0,
                    "incorrect value for states[9].state, expected 0, is {}",
                    msg.states[9].state
                );
                assert!(msg.states[10].cn0.almost_eq( -1.00000000000000000e+00 ), "incorrect value for states[10].cn0, expected -1.00000000000000000e+00, is {:e}", msg.states[10].cn0);
                assert_eq!(
                    msg.states[10].prn, 0,
                    "incorrect value for states[10].prn, expected 0, is {}",
                    msg.states[10].prn
                );
                assert_eq!(
                    msg.states[10].state, 0,
                    "incorrect value for states[10].state, expected 0, is {}",
                    msg.states[10].state
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
