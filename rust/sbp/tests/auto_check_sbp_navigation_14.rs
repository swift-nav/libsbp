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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFDepA.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_14() {
    {
        let payload: Vec<u8> = vec![
            85, 0, 2, 246, 215, 32, 20, 46, 39, 0, 195, 122, 175, 75, 33, 154, 68, 193, 164, 14,
            230, 176, 231, 95, 80, 193, 78, 220, 22, 253, 254, 105, 77, 65, 0, 0, 9, 0, 13, 86,
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 2, 246, 215, 32, 20, 46, 39, 0, 212, 196, 12, 42, 34, 154, 68, 193, 9, 113, 112,
            123, 231, 95, 80, 193, 54, 97, 38, 192, 254, 105, 77, 65, 0, 0, 9, 1, 75, 143,
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 2, 246, 215, 32, 120, 46, 39, 0, 112, 97, 39, 190, 34, 154, 68, 193, 230, 43,
            119, 115, 231, 95, 80, 193, 50, 199, 76, 66, 254, 105, 77, 65, 0, 0, 9, 0, 204, 113,
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 2, 246, 215, 32, 120, 46, 39, 0, 194, 82, 121, 4, 34, 154, 68, 193, 223, 186, 1,
            140, 231, 95, 80, 193, 176, 152, 147, 181, 254, 105, 77, 65, 0, 0, 9, 1, 97, 71,
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 0, 2, 246, 215, 32, 220, 46, 39, 0, 216, 41, 227, 254, 33, 154, 68, 193, 9, 151,
            154, 124, 231, 95, 80, 193, 1, 183, 214, 139, 255, 105, 77, 65, 0, 0, 9, 0, 7, 98,
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
