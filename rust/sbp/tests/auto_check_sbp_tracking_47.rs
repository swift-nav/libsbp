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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_tracking.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_tracking_47() {
    {
        let payload: Vec<u8> = vec![
            85, 22, 0, 195, 4, 66, 1, 0, 204, 177, 51, 65, 1, 2, 198, 4, 39, 65, 1, 3, 219, 182,
            27, 65, 1, 7, 132, 120, 101, 65, 1, 10, 91, 91, 251, 64, 1, 13, 42, 37, 163, 64, 1, 22,
            130, 184, 215, 64, 1, 30, 115, 53, 75, 65, 1, 31, 16, 74, 126, 65, 1, 25, 132, 196,
            135, 64, 1, 6, 100, 59, 223, 64, 17, 225,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 22, 0, 195, 4, 66, 1, 0, 216, 57, 48, 65, 1, 2, 145, 41, 46, 65, 1, 3, 4, 26, 34,
            65, 1, 7, 177, 67, 109, 65, 1, 10, 61, 80, 249, 64, 1, 13, 250, 199, 155, 64, 1, 22,
            55, 19, 215, 64, 1, 30, 138, 138, 79, 65, 1, 31, 214, 179, 119, 65, 1, 25, 53, 138,
            120, 64, 1, 6, 183, 247, 129, 64, 168, 173,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 22, 0, 195, 4, 66, 1, 0, 141, 76, 60, 65, 1, 2, 69, 139, 46, 65, 1, 3, 146, 27, 30,
            65, 1, 7, 235, 56, 97, 65, 1, 10, 141, 213, 243, 64, 1, 13, 250, 170, 166, 64, 1, 22,
            17, 101, 201, 64, 1, 30, 172, 183, 83, 65, 1, 31, 238, 193, 120, 65, 1, 25, 220, 48,
            132, 64, 1, 6, 49, 214, 54, 64, 110, 179,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 22, 0, 195, 4, 66, 1, 0, 55, 143, 120, 66, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 248, 89,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 22, 0, 195, 4, 66, 1, 0, 218, 14, 19, 66, 1, 2, 210, 3, 21, 65, 1, 3, 234, 214,
            134, 65, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0,
            128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0,
            128, 191, 84, 101,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 22, 0, 195, 4, 66, 1, 0, 98, 39, 219, 65, 1, 2, 0, 0, 56, 64, 1, 3, 121, 123, 7,
            65, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128,
            191, 37, 123,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x16,
                    "Incorrect message type, expected 0x16, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
