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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepC.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_acquisition_2() {
    {
        let payload: Vec<u8> = vec![
            85, 31, 0, 40, 12, 16, 72, 9, 34, 66, 155, 152, 228, 67, 28, 34, 221, 68, 10, 0, 0, 0,
            9, 189,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(1.76906591796875000e+03),
                    "incorrect value for cf, expected 1.76906591796875000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(4.05090637207031250e+01),
                    "incorrect value for cn0, expected 4.05090637207031250e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(4.57192230224609375e+02),
                    "incorrect value for cp, expected 4.57192230224609375e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 10,
                    "incorrect value for sid.sat, expected 10, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 31, 0, 40, 12, 16, 132, 250, 45, 66, 207, 93, 88, 68, 68, 185, 252, 195, 6, 0, 0,
            0, 136, 185,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-5.05447387695312500e+02),
                    "incorrect value for cf, expected -5.05447387695312500e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(4.34946441650390625e+01),
                    "incorrect value for cn0, expected 4.34946441650390625e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(8.65465759277343750e+02),
                    "incorrect value for cp, expected 8.65465759277343750e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 6,
                    "incorrect value for sid.sat, expected 6, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 31, 0, 40, 12, 16, 163, 223, 24, 66, 64, 91, 102, 67, 202, 243, 157, 196, 13, 0, 0,
            0, 150, 161,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-1.26361840820312500e+03),
                    "incorrect value for cf, expected -1.26361840820312500e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(3.82183952331542969e+01),
                    "incorrect value for cn0, expected 3.82183952331542969e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(2.30356445312500000e+02),
                    "incorrect value for cp, expected 2.30356445312500000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 13,
                    "incorrect value for sid.sat, expected 13, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 31, 0, 40, 12, 16, 129, 65, 21, 66, 224, 214, 124, 67, 243, 138, 61, 69, 1, 0, 0,
            0, 109, 209,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(3.03268432617187500e+03),
                    "incorrect value for cf, expected 3.03268432617187500e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(3.73139686584472656e+01),
                    "incorrect value for cn0, expected 3.73139686584472656e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(2.52839355468750000e+02),
                    "incorrect value for cp, expected 2.52839355468750000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 1,
                    "incorrect value for sid.sat, expected 1, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 31, 0, 40, 12, 16, 126, 35, 62, 66, 226, 37, 102, 68, 202, 243, 29, 69, 27, 0, 0,
            0, 91, 67,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(2.52723681640625000e+03),
                    "incorrect value for cf, expected 2.52723681640625000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(4.75346603393554688e+01),
                    "incorrect value for cn0, expected 4.75346603393554688e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(9.20591918945312500e+02),
                    "incorrect value for cp, expected 9.20591918945312500e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 27,
                    "incorrect value for sid.sat, expected 27, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
