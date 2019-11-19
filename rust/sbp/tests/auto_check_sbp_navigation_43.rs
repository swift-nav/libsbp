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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_navigation.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_43() {
    {
        let payload: Vec<u8> = vec![
            85, 0, 1, 195, 4, 11, 46, 7, 212, 157, 67, 24, 111, 147, 252, 255, 0, 215, 190,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTimeDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                    msg.ns_residual, -224401,
                    "incorrect value for ns_residual, expected -224401, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 407084500,
                    "incorrect value for tow, expected 407084500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1838,
                    "incorrect value for wn, expected 1838, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 1, 195, 4, 11, 46, 7, 56, 158, 67, 24, 109, 103, 3, 0, 0, 134, 89,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTimeDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                    msg.ns_residual, 223085,
                    "incorrect value for ns_residual, expected 223085, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 407084600,
                    "incorrect value for tow, expected 407084600, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1838,
                    "incorrect value for wn, expected 1838, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 1, 195, 4, 11, 46, 7, 156, 158, 67, 24, 233, 152, 252, 255, 0, 206, 241,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTimeDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                    msg.ns_residual, -222999,
                    "incorrect value for ns_residual, expected -222999, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 407084700,
                    "incorrect value for tow, expected 407084700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1838,
                    "incorrect value for wn, expected 1838, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 1, 195, 4, 11, 46, 7, 0, 159, 67, 24, 240, 154, 3, 0, 0, 147, 98,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTimeDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                    msg.ns_residual, 236272,
                    "incorrect value for ns_residual, expected 236272, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 407084800,
                    "incorrect value for tow, expected 407084800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1838,
                    "incorrect value for wn, expected 1838, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 1, 195, 4, 11, 46, 7, 100, 159, 67, 24, 144, 101, 252, 255, 0, 186, 152,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTimeDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                    msg.ns_residual, -236144,
                    "incorrect value for ns_residual, expected -236144, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 407084900,
                    "incorrect value for tow, expected 407084900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1838,
                    "incorrect value for wn, expected 1838, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 1, 195, 4, 11, 46, 7, 46, 162, 68, 24, 205, 230, 250, 255, 0, 11, 225,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTimeDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x100,
                    "Incorrect message type, expected 0x100, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                    msg.ns_residual, -334131,
                    "incorrect value for ns_residual, expected -334131, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 407151150,
                    "incorrect value for tow, expected 407151150, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1838,
                    "incorrect value for wn, expected 1838, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 2, 195, 4, 32, 212, 157, 67, 24, 153, 222, 105, 1, 252, 161, 68, 193, 254, 247,
            52, 112, 74, 67, 80, 193, 164, 207, 47, 146, 44, 163, 77, 65, 0, 0, 8, 0, 145, 4,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 2, 195, 4, 32, 56, 158, 67, 24, 215, 184, 223, 246, 251, 161, 68, 193, 36, 126,
            17, 39, 74, 67, 80, 193, 19, 179, 70, 80, 44, 163, 77, 65, 0, 0, 8, 0, 245, 66,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 2, 195, 4, 32, 156, 158, 67, 24, 73, 74, 214, 148, 251, 161, 68, 193, 213, 151,
            184, 215, 73, 67, 80, 193, 110, 99, 38, 164, 43, 163, 77, 65, 0, 0, 8, 0, 5, 223,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 2, 195, 4, 32, 0, 159, 67, 24, 177, 111, 112, 45, 252, 161, 68, 193, 213, 168,
            198, 253, 73, 67, 80, 193, 245, 12, 228, 12, 44, 163, 77, 65, 0, 0, 8, 0, 143, 212,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 2, 195, 4, 32, 100, 159, 67, 24, 67, 231, 72, 165, 251, 161, 68, 193, 150, 210,
            36, 212, 73, 67, 80, 193, 234, 33, 25, 189, 43, 163, 77, 65, 0, 0, 8, 0, 70, 221,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 2, 195, 4, 32, 46, 162, 68, 24, 224, 72, 131, 215, 251, 161, 68, 193, 180, 123,
            222, 94, 74, 67, 80, 193, 191, 3, 131, 193, 45, 163, 77, 65, 0, 0, 5, 0, 17, 221,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x200,
                    "Incorrect message type, expected 0x200, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 2, 2, 195, 4, 20, 156, 21, 69, 24, 169, 231, 255, 255, 102, 208, 255, 255, 251, 28,
            0, 0, 0, 0, 6, 0, 146, 168,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180700,
                    "incorrect value for tow, expected 407180700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -6231,
                    "incorrect value for x, expected -6231, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -12186,
                    "incorrect value for y, expected -12186, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 7419,
                    "incorrect value for z, expected 7419, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 2, 2, 195, 4, 20, 0, 22, 69, 24, 169, 231, 255, 255, 103, 208, 255, 255, 252, 28,
            0, 0, 0, 0, 6, 0, 34, 116,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180800,
                    "incorrect value for tow, expected 407180800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -6231,
                    "incorrect value for x, expected -6231, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -12185,
                    "incorrect value for y, expected -12185, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 7420,
                    "incorrect value for z, expected 7420, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 2, 2, 195, 4, 20, 100, 22, 69, 24, 30, 224, 255, 255, 192, 183, 255, 255, 239, 53,
            0, 0, 0, 0, 6, 0, 225, 15,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180900,
                    "incorrect value for tow, expected 407180900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -8162,
                    "incorrect value for x, expected -8162, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -18496,
                    "incorrect value for y, expected -18496, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 13807,
                    "incorrect value for z, expected 13807, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 2, 2, 195, 4, 20, 200, 22, 69, 24, 28, 224, 255, 255, 191, 183, 255, 255, 242, 53,
            0, 0, 0, 0, 6, 0, 35, 100,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181000,
                    "incorrect value for tow, expected 407181000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -8164,
                    "incorrect value for x, expected -8164, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -18497,
                    "incorrect value for y, expected -18497, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 13810,
                    "incorrect value for z, expected 13810, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 2, 2, 195, 4, 20, 44, 23, 69, 24, 24, 227, 255, 255, 25, 195, 255, 255, 153, 59, 0,
            0, 0, 0, 6, 0, 66, 66,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181100,
                    "incorrect value for tow, expected 407181100, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -7400,
                    "incorrect value for x, expected -7400, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -15591,
                    "incorrect value for y, expected -15591, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 15257,
                    "incorrect value for z, expected 15257, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 2, 2, 195, 4, 20, 144, 23, 69, 24, 23, 227, 255, 255, 25, 195, 255, 255, 153, 59,
            0, 0, 0, 0, 6, 0, 35, 135,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x202,
                    "Incorrect message type, expected 0x202, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181200,
                    "incorrect value for tow, expected 407181200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -7401,
                    "incorrect value for x, expected -7401, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -15591,
                    "incorrect value for y, expected -15591, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 15257,
                    "incorrect value for z, expected 15257, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 3, 2, 195, 4, 22, 156, 21, 69, 24, 130, 246, 255, 255, 241, 4, 0, 0, 35, 196, 255,
            255, 0, 0, 0, 0, 6, 0, 250, 21,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -15325,
                    "incorrect value for d, expected -15325, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 1265,
                    "incorrect value for e, expected 1265, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -2430,
                    "incorrect value for n, expected -2430, is {}",
                    msg.n
                );
                assert_eq!(
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180700,
                    "incorrect value for tow, expected 407180700, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 3, 2, 195, 4, 22, 0, 22, 69, 24, 130, 246, 255, 255, 241, 4, 0, 0, 35, 196, 255,
            255, 0, 0, 0, 0, 6, 0, 240, 133,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -15325,
                    "incorrect value for d, expected -15325, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 1265,
                    "incorrect value for e, expected 1265, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -2430,
                    "incorrect value for n, expected -2430, is {}",
                    msg.n
                );
                assert_eq!(
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180800,
                    "incorrect value for tow, expected 407180800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 3, 2, 195, 4, 22, 100, 22, 69, 24, 32, 251, 255, 255, 199, 11, 0, 0, 57, 161, 255,
            255, 0, 0, 0, 0, 6, 0, 12, 181,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -24263,
                    "incorrect value for d, expected -24263, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 3015,
                    "incorrect value for e, expected 3015, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -1248,
                    "incorrect value for n, expected -1248, is {}",
                    msg.n
                );
                assert_eq!(
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407180900,
                    "incorrect value for tow, expected 407180900, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 3, 2, 195, 4, 22, 200, 22, 69, 24, 33, 251, 255, 255, 199, 11, 0, 0, 54, 161, 255,
            255, 0, 0, 0, 0, 6, 0, 86, 58,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -24266,
                    "incorrect value for d, expected -24266, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 3015,
                    "incorrect value for e, expected 3015, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -1247,
                    "incorrect value for n, expected -1247, is {}",
                    msg.n
                );
                assert_eq!(
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181000,
                    "incorrect value for tow, expected 407181000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 3, 2, 195, 4, 22, 44, 23, 69, 24, 110, 6, 0, 0, 55, 8, 0, 0, 160, 166, 255, 255, 0,
            0, 0, 0, 6, 0, 51, 249,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -22880,
                    "incorrect value for d, expected -22880, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 2103,
                    "incorrect value for e, expected 2103, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, 1646,
                    "incorrect value for n, expected 1646, is {}",
                    msg.n
                );
                assert_eq!(
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181100,
                    "incorrect value for tow, expected 407181100, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 3, 2, 195, 4, 22, 144, 23, 69, 24, 110, 6, 0, 0, 54, 8, 0, 0, 160, 166, 255, 255,
            0, 0, 0, 0, 6, 0, 206, 22,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x203,
                    "Incorrect message type, expected 0x203, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -22880,
                    "incorrect value for d, expected -22880, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 2102,
                    "incorrect value for e, expected 2102, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, 1646,
                    "incorrect value for n, expected 1646, is {}",
                    msg.n
                );
                assert_eq!(
                    msg.n_sats, 6,
                    "incorrect value for n_sats, expected 6, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 407181200,
                    "incorrect value for tow, expected 407181200, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 4, 2, 195, 4, 20, 212, 157, 67, 24, 24, 0, 0, 0, 245, 255, 255, 255, 219, 255, 255,
            255, 0, 0, 8, 0, 68, 255,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                assert_eq!(
                    msg.x, 24,
                    "incorrect value for x, expected 24, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -11,
                    "incorrect value for y, expected -11, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, -37,
                    "incorrect value for z, expected -37, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 4, 2, 195, 4, 20, 56, 158, 67, 24, 4, 0, 0, 0, 234, 255, 255, 255, 18, 0, 0, 0, 0,
            0, 8, 0, 214, 136,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                assert_eq!(msg.x, 4, "incorrect value for x, expected 4, is {}", msg.x);
                assert_eq!(
                    msg.y, -22,
                    "incorrect value for y, expected -22, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 18,
                    "incorrect value for z, expected 18, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 4, 2, 195, 4, 20, 156, 158, 67, 24, 230, 255, 255, 255, 4, 0, 0, 0, 1, 0, 0, 0, 0,
            0, 8, 0, 122, 159,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                assert_eq!(
                    msg.x, -26,
                    "incorrect value for x, expected -26, is {}",
                    msg.x
                );
                assert_eq!(msg.y, 4, "incorrect value for y, expected 4, is {}", msg.y);
                assert_eq!(msg.z, 1, "incorrect value for z, expected 1, is {}", msg.z);
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 4, 2, 195, 4, 20, 0, 159, 67, 24, 247, 255, 255, 255, 237, 255, 255, 255, 28, 0, 0,
            0, 0, 0, 8, 0, 232, 146,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                assert_eq!(
                    msg.x, -9,
                    "incorrect value for x, expected -9, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -19,
                    "incorrect value for y, expected -19, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 28,
                    "incorrect value for z, expected 28, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 4, 2, 195, 4, 20, 100, 159, 67, 24, 255, 255, 255, 255, 2, 0, 0, 0, 245, 255, 255,
            255, 0, 0, 8, 0, 171, 238,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                assert_eq!(
                    msg.x, -1,
                    "incorrect value for x, expected -1, is {}",
                    msg.x
                );
                assert_eq!(msg.y, 2, "incorrect value for y, expected 2, is {}", msg.y);
                assert_eq!(
                    msg.z, -11,
                    "incorrect value for z, expected -11, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 4, 2, 195, 4, 20, 46, 162, 68, 24, 207, 255, 255, 255, 185, 255, 255, 255, 65, 0,
            0, 0, 0, 0, 5, 0, 82, 154,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelECEFDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x204,
                    "Incorrect message type, expected 0x204, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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
                assert_eq!(
                    msg.x, -49,
                    "incorrect value for x, expected -49, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, -71,
                    "incorrect value for y, expected -71, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 65,
                    "incorrect value for z, expected 65, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelECEFDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 5, 2, 195, 4, 22, 212, 157, 67, 24, 229, 255, 255, 255, 26, 0, 0, 0, 25, 0, 0, 0,
            0, 0, 0, 0, 8, 0, 132, 25,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, 25,
                    "incorrect value for d, expected 25, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 26,
                    "incorrect value for e, expected 26, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -27,
                    "incorrect value for n, expected -27, is {}",
                    msg.n
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
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 5, 2, 195, 4, 22, 56, 158, 67, 24, 4, 0, 0, 0, 15, 0, 0, 0, 232, 255, 255, 255, 0,
            0, 0, 0, 8, 0, 42, 14,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -24,
                    "incorrect value for d, expected -24, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, 15,
                    "incorrect value for e, expected 15, is {}",
                    msg.e
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
                assert_eq!(msg.n, 4, "incorrect value for n, expected 4, is {}", msg.n);
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
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 5, 2, 195, 4, 22, 156, 158, 67, 24, 251, 255, 255, 255, 232, 255, 255, 255, 247,
            255, 255, 255, 0, 0, 0, 0, 8, 0, 218, 148,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -9,
                    "incorrect value for d, expected -9, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, -24,
                    "incorrect value for e, expected -24, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -5,
                    "incorrect value for n, expected -5, is {}",
                    msg.n
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
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 5, 2, 195, 4, 22, 0, 159, 67, 24, 10, 0, 0, 0, 2, 0, 0, 0, 222, 255, 255, 255, 0,
            0, 0, 0, 8, 0, 148, 16,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -34,
                    "incorrect value for d, expected -34, is {}",
                    msg.d
                );
                assert_eq!(msg.e, 2, "incorrect value for e, expected 2, is {}", msg.e);
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
                assert_eq!(
                    msg.n, 10,
                    "incorrect value for n, expected 10, is {}",
                    msg.n
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
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 5, 2, 195, 4, 22, 100, 159, 67, 24, 248, 255, 255, 255, 254, 255, 255, 255, 7, 0,
            0, 0, 0, 0, 0, 0, 8, 0, 255, 236,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(msg.d, 7, "incorrect value for d, expected 7, is {}", msg.d);
                assert_eq!(
                    msg.e, -2,
                    "incorrect value for e, expected -2, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -8,
                    "incorrect value for n, expected -8, is {}",
                    msg.n
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
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 5, 2, 195, 4, 22, 46, 162, 68, 24, 255, 255, 255, 255, 253, 255, 255, 255, 148,
            255, 255, 255, 0, 0, 0, 0, 5, 0, 166, 189,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgVelNEDDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x205,
                    "Incorrect message type, expected 0x205, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, -108,
                    "incorrect value for d, expected -108, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, -3,
                    "incorrect value for e, expected -3, is {}",
                    msg.e
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
                assert_eq!(
                    msg.n, -1,
                    "incorrect value for n, expected -1, is {}",
                    msg.n
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
            _ => panic!("Invalid message type! Expected a MsgVelNEDDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 6, 2, 195, 4, 14, 212, 157, 67, 24, 247, 0, 215, 0, 123, 0, 17, 1, 44, 0, 206, 21,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 247,
                    "incorrect value for gdop, expected 247, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 273,
                    "incorrect value for hdop, expected 273, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 215,
                    "incorrect value for pdop, expected 215, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 123,
                    "incorrect value for tdop, expected 123, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 407084500,
                    "incorrect value for tow, expected 407084500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 44,
                    "incorrect value for vdop, expected 44, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 6, 2, 195, 4, 14, 0, 0, 0, 0, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 146, 12,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 65535,
                    "incorrect value for gdop, expected 65535, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 0,
                    "incorrect value for hdop, expected 0, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 65535,
                    "incorrect value for pdop, expected 65535, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 0,
                    "incorrect value for tdop, expected 0, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 0,
                    "incorrect value for tow, expected 0, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 0,
                    "incorrect value for vdop, expected 0, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 6, 2, 195, 4, 14, 128, 165, 68, 24, 92, 1, 56, 1, 155, 0, 125, 2, 113, 0, 129, 93,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 348,
                    "incorrect value for gdop, expected 348, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 637,
                    "incorrect value for hdop, expected 637, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 312,
                    "incorrect value for pdop, expected 312, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 155,
                    "incorrect value for tdop, expected 155, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 407152000,
                    "incorrect value for tow, expected 407152000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 113,
                    "incorrect value for vdop, expected 113, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 6, 2, 195, 4, 14, 104, 169, 68, 24, 92, 1, 55, 1, 155, 0, 125, 2, 113, 0, 209, 128,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 348,
                    "incorrect value for gdop, expected 348, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 637,
                    "incorrect value for hdop, expected 637, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 311,
                    "incorrect value for pdop, expected 311, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 155,
                    "incorrect value for tdop, expected 155, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 407153000,
                    "incorrect value for tow, expected 407153000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 113,
                    "incorrect value for vdop, expected 113, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 6, 2, 195, 4, 14, 80, 173, 68, 24, 92, 1, 55, 1, 155, 0, 125, 2, 112, 0, 30, 6,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 348,
                    "incorrect value for gdop, expected 348, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 637,
                    "incorrect value for hdop, expected 637, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 311,
                    "incorrect value for pdop, expected 311, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 155,
                    "incorrect value for tdop, expected 155, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 407154000,
                    "incorrect value for tow, expected 407154000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 112,
                    "incorrect value for vdop, expected 112, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 6, 2, 195, 4, 14, 56, 177, 68, 24, 92, 1, 55, 1, 155, 0, 125, 2, 112, 0, 70, 67,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgDopsDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x206,
                    "Incorrect message type, expected 0x206, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.gdop, 348,
                    "incorrect value for gdop, expected 348, is {}",
                    msg.gdop
                );
                assert_eq!(
                    msg.hdop, 637,
                    "incorrect value for hdop, expected 637, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 311,
                    "incorrect value for pdop, expected 311, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.tdop, 155,
                    "incorrect value for tdop, expected 155, is {}",
                    msg.tdop
                );
                assert_eq!(
                    msg.tow, 407155000,
                    "incorrect value for tow, expected 407155000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 112,
                    "incorrect value for vdop, expected 112, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgDopsDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 1, 2, 195, 4, 34, 212, 157, 67, 24, 8, 23, 228, 8, 151, 225, 66, 64, 156, 174, 42,
            194, 230, 152, 94, 192, 153, 23, 72, 47, 196, 40, 16, 64, 0, 0, 0, 0, 8, 0, 237, 169,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosLLHDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 1, 2, 195, 4, 34, 56, 158, 67, 24, 220, 109, 212, 24, 151, 225, 66, 64, 159, 231,
            254, 219, 230, 152, 94, 192, 128, 151, 67, 19, 233, 105, 7, 64, 0, 0, 0, 0, 8, 0, 152,
            11,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosLLHDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 1, 2, 195, 4, 34, 156, 158, 67, 24, 13, 91, 237, 11, 151, 225, 66, 64, 75, 113,
            210, 220, 230, 152, 94, 192, 37, 6, 145, 188, 89, 112, 238, 63, 0, 0, 0, 0, 8, 0, 221,
            155,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosLLHDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 1, 2, 195, 4, 34, 0, 159, 67, 24, 51, 183, 5, 8, 151, 225, 66, 64, 13, 226, 148,
            253, 230, 152, 94, 192, 187, 27, 11, 32, 69, 213, 2, 64, 0, 0, 0, 0, 8, 0, 82, 94,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosLLHDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 1, 2, 195, 4, 34, 100, 159, 67, 24, 22, 77, 146, 22, 151, 225, 66, 64, 64, 134,
            105, 227, 230, 152, 94, 192, 37, 99, 114, 72, 31, 103, 241, 63, 0, 0, 0, 0, 8, 0, 70,
            60,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosLLHDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 1, 2, 195, 4, 34, 46, 162, 68, 24, 124, 245, 46, 169, 151, 225, 66, 64, 135, 149,
            234, 187, 230, 152, 94, 192, 194, 201, 115, 145, 166, 175, 20, 64, 0, 0, 0, 0, 5, 0,
            212, 121,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosLLHDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x201,
                    "Incorrect message type, expected 0x201, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
