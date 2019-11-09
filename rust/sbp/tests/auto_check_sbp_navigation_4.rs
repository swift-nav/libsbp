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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEF.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_4() {
    {
        let payload: Vec<u8> = vec![
            85, 11, 2, 211, 136, 20, 40, 244, 122, 19, 150, 98, 238, 255, 190, 64, 20, 0, 246, 163,
            9, 0, 0, 0, 14, 0, 219, 191,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 14,
                    "incorrect value for n_sats, expected 14, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326825000,
                    "incorrect value for tow, expected 326825000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154410,
                    "incorrect value for x, expected -1154410, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327294,
                    "incorrect value for y, expected 1327294, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 631798,
                    "incorrect value for z, expected 631798, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 11, 2, 211, 136, 20, 16, 248, 122, 19, 72, 99, 238, 255, 191, 65, 20, 0, 138, 162,
            9, 0, 0, 0, 15, 0, 240, 78,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326826000,
                    "incorrect value for tow, expected 326826000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154232,
                    "incorrect value for x, expected -1154232, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327551,
                    "incorrect value for y, expected 1327551, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 631434,
                    "incorrect value for z, expected 631434, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 11, 2, 211, 136, 20, 248, 251, 122, 19, 41, 99, 238, 255, 181, 65, 20, 0, 148, 161,
            9, 0, 0, 0, 15, 0, 4, 132,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326827000,
                    "incorrect value for tow, expected 326827000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154263,
                    "incorrect value for x, expected -1154263, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327541,
                    "incorrect value for y, expected 1327541, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 631188,
                    "incorrect value for z, expected 631188, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 11, 2, 211, 136, 20, 224, 255, 122, 19, 188, 97, 238, 255, 81, 64, 20, 0, 65, 160,
            9, 0, 0, 0, 15, 0, 67, 94,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326828000,
                    "incorrect value for tow, expected 326828000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154628,
                    "incorrect value for x, expected -1154628, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1327185,
                    "incorrect value for y, expected 1327185, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 630849,
                    "incorrect value for z, expected 630849, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 11, 2, 211, 136, 20, 200, 3, 123, 19, 189, 96, 238, 255, 93, 63, 20, 0, 98, 159, 9,
            0, 0, 0, 15, 0, 106, 94,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20b,
                    "Incorrect message type, expected 0x20b, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
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
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326829000,
                    "incorrect value for tow, expected 326829000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.x, -1154883,
                    "incorrect value for x, expected -1154883, is {}",
                    msg.x
                );
                assert_eq!(
                    msg.y, 1326941,
                    "incorrect value for y, expected 1326941, is {}",
                    msg.y
                );
                assert_eq!(
                    msg.z, 630626,
                    "incorrect value for z, expected 630626, is {}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
