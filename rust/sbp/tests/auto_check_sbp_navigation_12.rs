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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEF.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_navigation_12() {
    {
        let payload: Vec<u8> = vec![
            85, 9, 2, 211, 136, 32, 16, 248, 122, 19, 73, 29, 46, 132, 182, 122, 68, 193, 219, 192,
            29, 176, 121, 119, 80, 193, 83, 11, 210, 90, 79, 75, 77, 65, 0, 0, 15, 2, 84, 6,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426903265729966e+06),
                    "incorrect value for x, expected -2.68426903265729966e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664675181599986e+06),
                    "incorrect value for y, expected -4.31664675181599986e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964670953504136e+06),
                    "incorrect value for z, expected 3.83964670953504136e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 9, 2, 211, 136, 32, 248, 251, 122, 19, 103, 106, 57, 136, 182, 122, 68, 193, 176,
            242, 200, 176, 121, 119, 80, 193, 244, 135, 97, 59, 79, 75, 77, 65, 0, 0, 15, 2, 147,
            216,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426906425218610e+06),
                    "incorrect value for x, expected -2.68426906425218610e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664676226489246e+06),
                    "incorrect value for y, expected -4.31664676226489246e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964646391391195e+06),
                    "incorrect value for z, expected 3.83964646391391195e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 9, 2, 211, 136, 32, 224, 255, 122, 19, 101, 179, 242, 182, 182, 122, 68, 193, 130,
            196, 145, 199, 121, 119, 80, 193, 212, 10, 253, 15, 79, 75, 77, 65, 0, 0, 15, 2, 40,
            201,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426942928163940e+06),
                    "incorrect value for x, expected -2.68426942928163940e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664711827194877e+06),
                    "incorrect value for y, expected -4.31664711827194877e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964612490973808e+06),
                    "incorrect value for z, expected 3.83964612490973808e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 9, 2, 211, 136, 32, 200, 3, 123, 19, 146, 214, 132, 215, 182, 122, 68, 193, 213,
            68, 49, 215, 121, 119, 80, 193, 71, 34, 110, 243, 78, 75, 77, 65, 0, 0, 15, 2, 187, 86,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPosECEF(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x209,
                    "Incorrect message type, expected 0x209, is {}",
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
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
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
                assert!(
                    msg.x.almost_eq(-2.68426968374139909e+06),
                    "incorrect value for x, expected -2.68426968374139909e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.31664736238213349e+06),
                    "incorrect value for y, expected -4.31664736238213349e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.83964590179851977e+06),
                    "incorrect value for z, expected 3.83964590179851977e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEF"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
