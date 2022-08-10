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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLHDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_pos_llh_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 246, 215, 34, 20, 46, 39, 0, 250, 29, 226, 186, 235, 182, 66, 64, 19, 203,
            51, 196, 24, 139, 94, 192, 31, 157, 160, 232, 122, 115, 81, 64, 0, 0, 0, 0, 9, 0, 236,
            139,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.98043767517560667e+01),
                    "incorrect value for height, expected 6.98043767517560667e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290689090812094e+01),
                    "incorrect value for lat, expected 3.74290689090812094e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173386622027735e+02),
                    "incorrect value for lon, expected -1.22173386622027735e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567700,
                    "incorrect value for tow, expected 2567700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 246, 215, 34, 20, 46, 39, 0, 161, 51, 75, 148, 235, 182, 66, 64, 36, 41, 246,
            30, 25, 139, 94, 192, 254, 218, 49, 127, 10, 108, 81, 64, 0, 0, 0, 0, 9, 1, 25, 117,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.96881406771535410e+01),
                    "incorrect value for height, expected 6.96881406771535410e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290643088527375e+01),
                    "incorrect value for lat, expected 3.74290643088527375e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173408260718645e+02),
                    "incorrect value for lon, expected -1.22173408260718645e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567700,
                    "incorrect value for tow, expected 2567700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 246, 215, 34, 120, 46, 39, 0, 56, 214, 210, 65, 235, 182, 66, 64, 13, 46,
            132, 80, 25, 139, 94, 192, 22, 143, 46, 234, 191, 95, 81, 64, 0, 0, 0, 0, 9, 0, 174,
            105,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.94960885481526418e+01),
                    "incorrect value for height, expected 6.94960885481526418e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290544776417278e+01),
                    "incorrect value for lat, expected 3.74290544776417278e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173420075494690e+02),
                    "incorrect value for lon, expected -1.22173420075494690e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567800,
                    "incorrect value for tow, expected 2567800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 246, 215, 34, 120, 46, 39, 0, 251, 117, 115, 140, 235, 182, 66, 64, 152, 134,
            167, 12, 25, 139, 94, 192, 160, 22, 137, 253, 4, 108, 81, 64, 0, 0, 0, 0, 9, 1, 122,
            127,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.96878045881990147e+01),
                    "incorrect value for height, expected 6.96878045881990147e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290633739255654e+01),
                    "incorrect value for lat, expected 3.74290633739255654e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173403895949718e+02),
                    "incorrect value for lon, expected -1.22173403895949718e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567800,
                    "incorrect value for tow, expected 2567800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 246, 215, 34, 220, 46, 39, 0, 51, 124, 88, 251, 235, 182, 66, 64, 153, 5,
            250, 16, 25, 139, 94, 192, 146, 60, 187, 219, 152, 161, 81, 64, 0, 0, 0, 0, 9, 0, 194,
            158,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(7.05249547317964982e+01),
                    "incorrect value for height, expected 7.05249547317964982e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290765935951626e+01),
                    "incorrect value for lat, expected 3.74290765935951626e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173404926454523e+02),
                    "incorrect value for lon, expected -1.22173404926454523e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567900,
                    "incorrect value for tow, expected 2567900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 195, 4, 34, 212, 157, 67, 24, 8, 23, 228, 8, 151, 225, 66, 64, 156, 174, 42,
            194, 230, 152, 94, 192, 153, 23, 72, 47, 196, 40, 16, 64, 0, 0, 0, 0, 8, 0, 237, 169,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(4.03981088521495568e+00),
                    "incorrect value for height, expected 4.03981088521495568e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624217141838585e+01),
                    "incorrect value for lat, expected 3.77624217141838585e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389084378892619e+02),
                    "incorrect value for lon, expected -1.22389084378892619e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084500,
                    "incorrect value for tow, expected 407084500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 195, 4, 34, 56, 158, 67, 24, 220, 109, 212, 24, 151, 225, 66, 64, 159, 231,
            254, 219, 230, 152, 94, 192, 128, 151, 67, 19, 233, 105, 7, 64, 0, 0, 0, 0, 8, 0, 152,
            11,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.92671408700965685e+00),
                    "incorrect value for height, expected 2.92671408700965685e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624236142398502e+01),
                    "incorrect value for lat, expected 3.77624236142398502e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389090537004890e+02),
                    "incorrect value for lon, expected -1.22389090537004890e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084600,
                    "incorrect value for tow, expected 407084600, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 195, 4, 34, 156, 158, 67, 24, 13, 91, 237, 11, 151, 225, 66, 64, 75, 113,
            210, 220, 230, 152, 94, 192, 37, 6, 145, 188, 89, 112, 238, 63, 0, 0, 0, 0, 8, 0, 221,
            155,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(9.51214664739556626e-01),
                    "incorrect value for height, expected 9.51214664739556626e-01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624220761264056e+01),
                    "incorrect value for lat, expected 3.77624220761264056e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389090734014800e+02),
                    "incorrect value for lon, expected -1.22389090734014800e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084700,
                    "incorrect value for tow, expected 407084700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 195, 4, 34, 0, 159, 67, 24, 51, 183, 5, 8, 151, 225, 66, 64, 13, 226, 148,
            253, 230, 152, 94, 192, 187, 27, 11, 32, 69, 213, 2, 64, 0, 0, 0, 0, 8, 0, 82, 94,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.35413575204753789e+00),
                    "incorrect value for height, expected 2.35413575204753789e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624216106327353e+01),
                    "incorrect value for lat, expected 3.77624216106327353e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389098544496122e+02),
                    "incorrect value for lon, expected -1.22389098544496122e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084800,
                    "incorrect value for tow, expected 407084800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 195, 4, 34, 100, 159, 67, 24, 22, 77, 146, 22, 151, 225, 66, 64, 64, 134,
            105, 227, 230, 152, 94, 192, 37, 99, 114, 72, 31, 103, 241, 63, 0, 0, 0, 0, 8, 0, 70,
            60,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(1.08767631816426413e+00),
                    "incorrect value for height, expected 1.08767631816426413e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624233450280116e+01),
                    "incorrect value for lat, expected 3.77624233450280116e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389092305232225e+02),
                    "incorrect value for lon, expected -1.22389092305232225e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084900,
                    "incorrect value for tow, expected 407084900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 195, 4, 34, 46, 162, 68, 24, 124, 245, 46, 169, 151, 225, 66, 64, 135, 149,
            234, 187, 230, 152, 94, 192, 194, 201, 115, 145, 166, 175, 20, 64, 0, 0, 0, 0, 5, 0,
            212, 121,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(5.17153384465422228e+00),
                    "incorrect value for height, expected 5.17153384465422228e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624408225337618e+01),
                    "incorrect value for lat, expected 3.77624408225337618e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389082888685252e+02),
                    "incorrect value for lon, expected -1.22389082888685252e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 5,
                    "incorrect value for n_sats, expected 5, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407151150,
                    "incorrect value for tow, expected 407151150, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_pos_llh_dep_a() {
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 9, "sender": 55286, "msg_type": 513, "lon": -122.17338662202773, "tow": 2567700, "height": 69.80437675175607, "crc": 35820, "length": 34, "flags": 0, "h_accuracy": 0, "lat": 37.42906890908121, "preamble": 85, "payload": "FC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.98043767517560667e+01),
                    "incorrect value for height, expected 6.98043767517560667e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290689090812094e+01),
                    "incorrect value for lat, expected 3.74290689090812094e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173386622027735e+02),
                    "incorrect value for lon, expected -1.22173386622027735e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567700,
                    "incorrect value for tow, expected 2567700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 9, "sender": 55286, "msg_type": 513, "lon": -122.17340826071865, "tow": 2567700, "height": 69.68814067715354, "crc": 29977, "length": 34, "flags": 1, "h_accuracy": 0, "lat": 37.42906430885274, "preamble": 85, "payload": "FC4nAKEzS5TrtkJAJCn2HhmLXsD+2jF/CmxRQAAAAAAJAQ=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.96881406771535410e+01),
                    "incorrect value for height, expected 6.96881406771535410e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290643088527375e+01),
                    "incorrect value for lat, expected 3.74290643088527375e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173408260718645e+02),
                    "incorrect value for lon, expected -1.22173408260718645e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567700,
                    "incorrect value for tow, expected 2567700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 9, "sender": 55286, "msg_type": 513, "lon": -122.17342007549469, "tow": 2567800, "height": 69.49608854815264, "crc": 27054, "length": 34, "flags": 0, "h_accuracy": 0, "lat": 37.42905447764173, "preamble": 85, "payload": "eC4nADjW0kHrtkJADS6EUBmLXsAWjy7qv19RQAAAAAAJAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.94960885481526418e+01),
                    "incorrect value for height, expected 6.94960885481526418e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290544776417278e+01),
                    "incorrect value for lat, expected 3.74290544776417278e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173420075494690e+02),
                    "incorrect value for lon, expected -1.22173420075494690e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567800,
                    "incorrect value for tow, expected 2567800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 9, "sender": 55286, "msg_type": 513, "lon": -122.17340389594972, "tow": 2567800, "height": 69.68780458819901, "crc": 32634, "length": 34, "flags": 1, "h_accuracy": 0, "lat": 37.429063373925565, "preamble": 85, "payload": "eC4nAPt1c4zrtkJAmIanDBmLXsCgFon9BGxRQAAAAAAJAQ=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.96878045881990147e+01),
                    "incorrect value for height, expected 6.96878045881990147e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290633739255654e+01),
                    "incorrect value for lat, expected 3.74290633739255654e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173403895949718e+02),
                    "incorrect value for lon, expected -1.22173403895949718e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567800,
                    "incorrect value for tow, expected 2567800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 9, "sender": 55286, "msg_type": 513, "lon": -122.17340492645452, "tow": 2567900, "height": 70.5249547317965, "crc": 40642, "length": 34, "flags": 0, "h_accuracy": 0, "lat": 37.42907659359516, "preamble": 85, "payload": "3C4nADN8WPvrtkJAmQX6EBmLXsCSPLvbmKFRQAAAAAAJAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(7.05249547317964982e+01),
                    "incorrect value for height, expected 7.05249547317964982e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290765935951626e+01),
                    "incorrect value for lat, expected 3.74290765935951626e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173404926454523e+02),
                    "incorrect value for lon, expected -1.22173404926454523e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567900,
                    "incorrect value for tow, expected 2567900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 8, "sender": 1219, "msg_type": 513, "lon": -122.38908437889262, "tow": 407084500, "height": 4.039810885214956, "crc": 43501, "length": 34, "flags": 0, "h_accuracy": 0, "lat": 37.76242171418386, "preamble": 85, "payload": "1J1DGAgX5AiX4UJAnK4qwuaYXsCZF0gvxCgQQAAAAAAIAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(4.03981088521495568e+00),
                    "incorrect value for height, expected 4.03981088521495568e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624217141838585e+01),
                    "incorrect value for lat, expected 3.77624217141838585e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389084378892619e+02),
                    "incorrect value for lon, expected -1.22389084378892619e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084500,
                    "incorrect value for tow, expected 407084500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 8, "sender": 1219, "msg_type": 513, "lon": -122.38909053700489, "tow": 407084600, "height": 2.926714087009657, "crc": 2968, "length": 34, "flags": 0, "h_accuracy": 0, "lat": 37.76242361423985, "preamble": 85, "payload": "OJ5DGNxt1BiX4UJAn+f+2+aYXsCAl0MT6WkHQAAAAAAIAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.92671408700965685e+00),
                    "incorrect value for height, expected 2.92671408700965685e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624236142398502e+01),
                    "incorrect value for lat, expected 3.77624236142398502e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389090537004890e+02),
                    "incorrect value for lon, expected -1.22389090537004890e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084600,
                    "incorrect value for tow, expected 407084600, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 8, "sender": 1219, "msg_type": 513, "lon": -122.3890907340148, "tow": 407084700, "height": 0.9512146647395566, "crc": 39901, "length": 34, "flags": 0, "h_accuracy": 0, "lat": 37.762422076126406, "preamble": 85, "payload": "nJ5DGA1b7QuX4UJAS3HS3OaYXsAlBpG8WXDuPwAAAAAIAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(9.51214664739556626e-01),
                    "incorrect value for height, expected 9.51214664739556626e-01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624220761264056e+01),
                    "incorrect value for lat, expected 3.77624220761264056e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389090734014800e+02),
                    "incorrect value for lon, expected -1.22389090734014800e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084700,
                    "incorrect value for tow, expected 407084700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 8, "sender": 1219, "msg_type": 513, "lon": -122.38909854449612, "tow": 407084800, "height": 2.354135752047538, "crc": 24146, "length": 34, "flags": 0, "h_accuracy": 0, "lat": 37.762421610632735, "preamble": 85, "payload": "AJ9DGDO3BQiX4UJADeKU/eaYXsC7GwsgRdUCQAAAAAAIAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.35413575204753789e+00),
                    "incorrect value for height, expected 2.35413575204753789e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624216106327353e+01),
                    "incorrect value for lat, expected 3.77624216106327353e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389098544496122e+02),
                    "incorrect value for lon, expected -1.22389098544496122e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084800,
                    "incorrect value for tow, expected 407084800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 8, "sender": 1219, "msg_type": 513, "lon": -122.38909230523223, "tow": 407084900, "height": 1.0876763181642641, "crc": 15430, "length": 34, "flags": 0, "h_accuracy": 0, "lat": 37.76242334502801, "preamble": 85, "payload": "ZJ9DGBZNkhaX4UJAQIZp4+aYXsAlY3JIH2fxPwAAAAAIAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(1.08767631816426413e+00),
                    "incorrect value for height, expected 1.08767631816426413e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624233450280116e+01),
                    "incorrect value for lat, expected 3.77624233450280116e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389092305232225e+02),
                    "incorrect value for lon, expected -1.22389092305232225e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084900,
                    "incorrect value for tow, expected 407084900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 5, "sender": 1219, "msg_type": 513, "lon": -122.38908288868525, "tow": 407151150, "height": 5.171533844654222, "crc": 31188, "length": 34, "flags": 0, "h_accuracy": 0, "lat": 37.76244082253376, "preamble": 85, "payload": "LqJEGHz1LqmX4UJAh5Xqu+aYXsDCyXORpq8UQAAAAAAFAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(5.17153384465422228e+00),
                    "incorrect value for height, expected 5.17153384465422228e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624408225337618e+01),
                    "incorrect value for lat, expected 3.77624408225337618e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389082888685252e+02),
                    "incorrect value for lon, expected -1.22389082888685252e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 5,
                    "incorrect value for n_sats, expected 5, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407151150,
                    "incorrect value for tow, expected 407151150, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_pos_llh_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_pos_llh_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 246, 215, 34, 20, 46, 39, 0, 250, 29, 226, 186, 235, 182, 66, 64, 19, 203,
            51, 196, 24, 139, 94, 192, 31, 157, 160, 232, 122, 115, 81, 64, 0, 0, 0, 0, 9, 0, 236,
            139,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlhDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.98043767517560667e+01),
                    "incorrect value for height, expected 6.98043767517560667e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290689090812094e+01),
                    "incorrect value for lat, expected 3.74290689090812094e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173386622027735e+02),
                    "incorrect value for lon, expected -1.22173386622027735e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567700,
                    "incorrect value for tow, expected 2567700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 246, 215, 34, 20, 46, 39, 0, 161, 51, 75, 148, 235, 182, 66, 64, 36, 41, 246,
            30, 25, 139, 94, 192, 254, 218, 49, 127, 10, 108, 81, 64, 0, 0, 0, 0, 9, 1, 25, 117,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlhDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.96881406771535410e+01),
                    "incorrect value for height, expected 6.96881406771535410e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290643088527375e+01),
                    "incorrect value for lat, expected 3.74290643088527375e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173408260718645e+02),
                    "incorrect value for lon, expected -1.22173408260718645e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567700,
                    "incorrect value for tow, expected 2567700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 246, 215, 34, 120, 46, 39, 0, 56, 214, 210, 65, 235, 182, 66, 64, 13, 46,
            132, 80, 25, 139, 94, 192, 22, 143, 46, 234, 191, 95, 81, 64, 0, 0, 0, 0, 9, 0, 174,
            105,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlhDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.94960885481526418e+01),
                    "incorrect value for height, expected 6.94960885481526418e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290544776417278e+01),
                    "incorrect value for lat, expected 3.74290544776417278e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173420075494690e+02),
                    "incorrect value for lon, expected -1.22173420075494690e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567800,
                    "incorrect value for tow, expected 2567800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 246, 215, 34, 120, 46, 39, 0, 251, 117, 115, 140, 235, 182, 66, 64, 152, 134,
            167, 12, 25, 139, 94, 192, 160, 22, 137, 253, 4, 108, 81, 64, 0, 0, 0, 0, 9, 1, 122,
            127,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlhDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(6.96878045881990147e+01),
                    "incorrect value for height, expected 6.96878045881990147e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290633739255654e+01),
                    "incorrect value for lat, expected 3.74290633739255654e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173403895949718e+02),
                    "incorrect value for lon, expected -1.22173403895949718e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567800,
                    "incorrect value for tow, expected 2567800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 246, 215, 34, 220, 46, 39, 0, 51, 124, 88, 251, 235, 182, 66, 64, 153, 5,
            250, 16, 25, 139, 94, 192, 146, 60, 187, 219, 152, 161, 81, 64, 0, 0, 0, 0, 9, 0, 194,
            158,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlhDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(7.05249547317964982e+01),
                    "incorrect value for height, expected 7.05249547317964982e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.74290765935951626e+01),
                    "incorrect value for lat, expected 3.74290765935951626e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22173404926454523e+02),
                    "incorrect value for lon, expected -1.22173404926454523e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 9,
                    "incorrect value for n_sats, expected 9, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 2567900,
                    "incorrect value for tow, expected 2567900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 195, 4, 34, 212, 157, 67, 24, 8, 23, 228, 8, 151, 225, 66, 64, 156, 174, 42,
            194, 230, 152, 94, 192, 153, 23, 72, 47, 196, 40, 16, 64, 0, 0, 0, 0, 8, 0, 237, 169,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlhDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(4.03981088521495568e+00),
                    "incorrect value for height, expected 4.03981088521495568e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624217141838585e+01),
                    "incorrect value for lat, expected 3.77624217141838585e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389084378892619e+02),
                    "incorrect value for lon, expected -1.22389084378892619e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084500,
                    "incorrect value for tow, expected 407084500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 195, 4, 34, 56, 158, 67, 24, 220, 109, 212, 24, 151, 225, 66, 64, 159, 231,
            254, 219, 230, 152, 94, 192, 128, 151, 67, 19, 233, 105, 7, 64, 0, 0, 0, 0, 8, 0, 152,
            11,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlhDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.92671408700965685e+00),
                    "incorrect value for height, expected 2.92671408700965685e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624236142398502e+01),
                    "incorrect value for lat, expected 3.77624236142398502e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389090537004890e+02),
                    "incorrect value for lon, expected -1.22389090537004890e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084600,
                    "incorrect value for tow, expected 407084600, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 195, 4, 34, 156, 158, 67, 24, 13, 91, 237, 11, 151, 225, 66, 64, 75, 113,
            210, 220, 230, 152, 94, 192, 37, 6, 145, 188, 89, 112, 238, 63, 0, 0, 0, 0, 8, 0, 221,
            155,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlhDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(9.51214664739556626e-01),
                    "incorrect value for height, expected 9.51214664739556626e-01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624220761264056e+01),
                    "incorrect value for lat, expected 3.77624220761264056e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389090734014800e+02),
                    "incorrect value for lon, expected -1.22389090734014800e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084700,
                    "incorrect value for tow, expected 407084700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 195, 4, 34, 0, 159, 67, 24, 51, 183, 5, 8, 151, 225, 66, 64, 13, 226, 148,
            253, 230, 152, 94, 192, 187, 27, 11, 32, 69, 213, 2, 64, 0, 0, 0, 0, 8, 0, 82, 94,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlhDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.35413575204753789e+00),
                    "incorrect value for height, expected 2.35413575204753789e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624216106327353e+01),
                    "incorrect value for lat, expected 3.77624216106327353e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389098544496122e+02),
                    "incorrect value for lon, expected -1.22389098544496122e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084800,
                    "incorrect value for tow, expected 407084800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 195, 4, 34, 100, 159, 67, 24, 22, 77, 146, 22, 151, 225, 66, 64, 64, 134,
            105, 227, 230, 152, 94, 192, 37, 99, 114, 72, 31, 103, 241, 63, 0, 0, 0, 0, 8, 0, 70,
            60,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlhDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(1.08767631816426413e+00),
                    "incorrect value for height, expected 1.08767631816426413e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624233450280116e+01),
                    "incorrect value for lat, expected 3.77624233450280116e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389092305232225e+02),
                    "incorrect value for lon, expected -1.22389092305232225e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 8,
                    "incorrect value for n_sats, expected 8, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407084900,
                    "incorrect value for tow, expected 407084900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 1, 2, 195, 4, 34, 46, 162, 68, 24, 124, 245, 46, 169, 151, 225, 66, 64, 135, 149,
            234, 187, 230, 152, 94, 192, 194, 201, 115, 145, 166, 175, 20, 64, 0, 0, 0, 0, 5, 0,
            212, 121,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlhDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(5.17153384465422228e+00),
                    "incorrect value for height, expected 5.17153384465422228e+00, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.77624408225337618e+01),
                    "incorrect value for lat, expected 3.77624408225337618e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22389082888685252e+02),
                    "incorrect value for lon, expected -1.22389082888685252e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 5,
                    "incorrect value for n_sats, expected 5, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407151150,
                    "incorrect value for tow, expected 407151150, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
