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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_pos_ecef_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 0, 2, 246, 215, 32, 20, 46, 39, 0, 195, 122, 175, 75, 33, 154, 68, 193, 164, 14,
            230, 176, 231, 95, 80, 193, 78, 220, 22, 253, 254, 105, 77, 65, 0, 0, 9, 0, 13, 86,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
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
                assert!(
                    msg.x.almost_eq(-2.70035459129271051e+06),
                    "incorrect value for x, expected -2.70035459129271051e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.29251076404157653e+06),
                    "incorrect value for y, expected -4.29251076404157653e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.85535797726014908e+06),
                    "incorrect value for z, expected 3.85535797726014908e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 2, 246, 215, 32, 20, 46, 39, 0, 212, 196, 12, 42, 34, 154, 68, 193, 9, 113, 112,
            123, 231, 95, 80, 193, 54, 97, 38, 192, 254, 105, 77, 65, 0, 0, 9, 1, 75, 143,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
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
                assert!(
                    msg.x.almost_eq(-2.70035632851467468e+06),
                    "incorrect value for x, expected -2.70035632851467468e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.29250992873788718e+06),
                    "incorrect value for y, expected -4.29250992873788718e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.85535750117125642e+06),
                    "incorrect value for z, expected 3.85535750117125642e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 2, 246, 215, 32, 120, 46, 39, 0, 112, 97, 39, 190, 34, 154, 68, 193, 230, 43,
            119, 115, 231, 95, 80, 193, 50, 199, 76, 66, 254, 105, 77, 65, 0, 0, 9, 0, 204, 113,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
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
                assert!(
                    msg.x.almost_eq(-2.70035748557680100e+06),
                    "incorrect value for x, expected -2.70035748557680100e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.29250980414864980e+06),
                    "incorrect value for y, expected -4.29250980414864980e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.85535651796808187e+06),
                    "incorrect value for z, expected 3.85535651796808187e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 2, 246, 215, 32, 120, 46, 39, 0, 194, 82, 121, 4, 34, 154, 68, 193, 223, 186, 1,
            140, 231, 95, 80, 193, 176, 152, 147, 181, 254, 105, 77, 65, 0, 0, 9, 1, 97, 71,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
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
                assert!(
                    msg.x.almost_eq(-2.70035603495249245e+06),
                    "incorrect value for x, expected -2.70035603495249245e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.29251018760558870e+06),
                    "incorrect value for y, expected -4.29251018760558870e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.85535741856678575e+06),
                    "incorrect value for z, expected 3.85535741856678575e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 2, 246, 215, 32, 220, 46, 39, 0, 216, 41, 227, 254, 33, 154, 68, 193, 9, 151,
            154, 124, 231, 95, 80, 193, 1, 183, 214, 139, 255, 105, 77, 65, 0, 0, 9, 0, 7, 98,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
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
                assert!(
                    msg.x.almost_eq(-2.70035599130747840e+06),
                    "incorrect value for x, expected -2.70035599130747840e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.29250994693542365e+06),
                    "incorrect value for y, expected -4.29250994693542365e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.85535909249007748e+06),
                    "incorrect value for z, expected 3.85535909249007748e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 2, 195, 4, 32, 212, 157, 67, 24, 153, 222, 105, 1, 252, 161, 68, 193, 254, 247,
            52, 112, 74, 67, 80, 193, 164, 207, 47, 146, 44, 163, 77, 65, 0, 0, 8, 0, 145, 4,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
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
                assert!(
                    msg.x.almost_eq(-2.70437601104338141e+06),
                    "incorrect value for x, expected -2.70437601104338141e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.26320975323295407e+06),
                    "incorrect value for y, expected -4.26320975323295407e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.88463314208407886e+06),
                    "incorrect value for z, expected 3.88463314208407886e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 2, 195, 4, 32, 56, 158, 67, 24, 215, 184, 223, 246, 251, 161, 68, 193, 36, 126,
            17, 39, 74, 67, 80, 193, 19, 179, 70, 80, 44, 163, 77, 65, 0, 0, 8, 0, 245, 66,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
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
                assert!(
                    msg.x.almost_eq(-2.70437592870245455e+06),
                    "incorrect value for x, expected -2.70437592870245455e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.26320861044267192e+06),
                    "incorrect value for y, expected -4.26320861044267192e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.88463262715757778e+06),
                    "incorrect value for z, expected 3.88463262715757778e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 2, 195, 4, 32, 156, 158, 67, 24, 73, 74, 214, 148, 251, 161, 68, 193, 213, 151,
            184, 215, 73, 67, 80, 193, 110, 99, 38, 164, 43, 163, 77, 65, 0, 0, 8, 0, 5, 223,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
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
                assert!(
                    msg.x.almost_eq(-2.70437516278961720e+06),
                    "incorrect value for x, expected -2.70437516278961720e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.26320737064166833e+06),
                    "incorrect value for y, expected -4.26320737064166833e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.88463128242152091e+06),
                    "incorrect value for z, expected 3.88463128242152091e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 2, 195, 4, 32, 0, 159, 67, 24, 177, 111, 112, 45, 252, 161, 68, 193, 213, 168,
            198, 253, 73, 67, 80, 193, 245, 12, 228, 12, 44, 163, 77, 65, 0, 0, 8, 0, 143, 212,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
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
                assert!(
                    msg.x.almost_eq(-2.70437635499378340e+06),
                    "incorrect value for x, expected -2.70437635499378340e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.26320796525021363e+06),
                    "incorrect value for y, expected -4.26320796525021363e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.88463210070955241e+06),
                    "incorrect value for z, expected 3.88463210070955241e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 2, 195, 4, 32, 100, 159, 67, 24, 67, 231, 72, 165, 251, 161, 68, 193, 150, 210,
            36, 212, 73, 67, 80, 193, 234, 33, 25, 189, 43, 163, 77, 65, 0, 0, 8, 0, 70, 221,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
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
                assert!(
                    msg.x.almost_eq(-2.70437529128733417e+06),
                    "incorrect value for x, expected -2.70437529128733417e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.26320731474747322e+06),
                    "incorrect value for y, expected -4.26320731474747322e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.88463147732948232e+06),
                    "incorrect value for z, expected 3.88463147732948232e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 0, 2, 195, 4, 32, 46, 162, 68, 24, 224, 72, 131, 215, 251, 161, 68, 193, 180, 123,
            222, 94, 74, 67, 80, 193, 191, 3, 131, 193, 45, 163, 77, 65, 0, 0, 5, 0, 17, 221,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 0,
                    "incorrect value for accuracy, expected 0, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
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
                assert!(
                    msg.x.almost_eq(-2.70437568369399011e+06),
                    "incorrect value for x, expected -2.70437568369399011e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.26320948232929781e+06),
                    "incorrect value for y, expected -4.26320948232929781e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.88463551181074930e+06),
                    "incorrect value for z, expected 3.88463551181074930e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
