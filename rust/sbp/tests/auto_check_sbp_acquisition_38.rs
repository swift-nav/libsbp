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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_acquisition.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_acquisition_38() {
    {
        let payload: Vec<u8> = vec![
            85, 21, 0, 195, 4, 13, 0, 0, 104, 65, 0, 192, 53, 68, 198, 199, 0, 70, 8, 2, 68,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(8.24194335937500000e+03),
                    "incorrect value for cf, expected 8.24194335937500000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(7.27000000000000000e+02),
                    "incorrect value for cp, expected 7.27000000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 8,
                    "incorrect value for prn, expected 8, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.45000000000000000e+01),
                    "incorrect value for snr, expected 1.45000000000000000e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 21, 0, 195, 4, 13, 205, 204, 116, 65, 0, 192, 179, 67, 33, 81, 59, 68, 9, 219, 27,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(7.49267639160156250e+02),
                    "incorrect value for cf, expected 7.49267639160156250e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(3.59500000000000000e+02),
                    "incorrect value for cp, expected 3.59500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 9,
                    "incorrect value for prn, expected 9, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.53000001907348633e+01),
                    "incorrect value for snr, expected 1.53000001907348633e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 21, 0, 195, 4, 13, 205, 204, 144, 65, 0, 0, 34, 66, 57, 237, 202, 197, 11, 150, 35,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-6.49365283203125000e+03),
                    "incorrect value for cf, expected -6.49365283203125000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(4.05000000000000000e+01),
                    "incorrect value for cp, expected 4.05000000000000000e+01, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 11,
                    "incorrect value for prn, expected 11, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.81000003814697266e+01),
                    "incorrect value for snr, expected 1.81000003814697266e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 21, 0, 195, 4, 13, 205, 204, 116, 65, 0, 32, 9, 68, 129, 193, 121, 196, 12, 146,
            118,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-9.99023498535156250e+02),
                    "incorrect value for cf, expected -9.99023498535156250e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(5.48500000000000000e+02),
                    "incorrect value for cp, expected 5.48500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 12,
                    "incorrect value for prn, expected 12, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.53000001907348633e+01),
                    "incorrect value for snr, expected 1.53000001907348633e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 21, 0, 195, 4, 13, 205, 204, 116, 65, 0, 32, 67, 68, 228, 74, 148, 69, 14, 23, 75,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(4.74536132812500000e+03),
                    "incorrect value for cf, expected 4.74536132812500000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(7.80500000000000000e+02),
                    "incorrect value for cp, expected 7.80500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 14,
                    "incorrect value for prn, expected 14, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.53000001907348633e+01),
                    "incorrect value for snr, expected 1.53000001907348633e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 21, 0, 195, 4, 13, 228, 56, 35, 67, 0, 32, 18, 68, 129, 193, 249, 195, 0, 204, 207,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-4.99511749267578125e+02),
                    "incorrect value for cf, expected -4.99511749267578125e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(5.84500000000000000e+02),
                    "incorrect value for cp, expected 5.84500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 0,
                    "incorrect value for prn, expected 0, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.63222229003906250e+02),
                    "incorrect value for snr, expected 1.63222229003906250e+02, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
