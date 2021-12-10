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
