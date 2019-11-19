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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_logging.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_logging_41() {
    {
        let payload: Vec<u8> = vec![
            85, 16, 0, 34, 34, 43, 73, 78, 70, 79, 58, 32, 97, 99, 113, 58, 32, 80, 82, 78, 32, 49,
            53, 32, 102, 111, 117, 110, 100, 32, 64, 32, 45, 50, 52, 57, 55, 32, 72, 122, 44, 32,
            50, 48, 32, 83, 78, 82, 10, 116, 103,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text,
                    "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 16, 0, 34, 34, 42, 73, 78, 70, 79, 58, 32, 97, 99, 113, 58, 32, 80, 82, 78, 32, 51,
            49, 32, 102, 111, 117, 110, 100, 32, 64, 32, 52, 50, 52, 53, 32, 72, 122, 44, 32, 50,
            49, 32, 83, 78, 82, 10, 140, 43,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text,
                    "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 16, 0, 34, 34, 35, 73, 78, 70, 79, 58, 32, 68, 105, 115, 97, 98, 108, 105, 110,
            103, 32, 99, 104, 97, 110, 110, 101, 108, 32, 48, 32, 40, 80, 82, 78, 32, 49, 49, 41,
            10, 23, 143,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text,
                    "INFO: Disabling channel 0 (PRN 11)
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: Disabling channel 0 (PRN 11)
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 16, 0, 34, 34, 41, 73, 78, 70, 79, 58, 32, 97, 99, 113, 58, 32, 80, 82, 78, 32, 50,
            32, 102, 111, 117, 110, 100, 32, 64, 32, 51, 57, 57, 54, 32, 72, 122, 44, 32, 50, 48,
            32, 83, 78, 82, 10, 239, 48,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text,
                    "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 16, 0, 34, 34, 42, 73, 78, 70, 79, 58, 32, 97, 99, 113, 58, 32, 80, 82, 78, 32, 52,
            32, 102, 111, 117, 110, 100, 32, 64, 32, 45, 55, 52, 57, 50, 32, 72, 122, 44, 32, 50,
            48, 32, 83, 78, 82, 10, 47, 248,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text,
                    "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 16, 0, 34, 34, 35, 73, 78, 70, 79, 58, 32, 68, 105, 115, 97, 98, 108, 105, 110,
            103, 32, 99, 104, 97, 110, 110, 101, 108, 32, 49, 32, 40, 80, 82, 78, 32, 49, 53, 41,
            10, 158, 139,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgPrintDep(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x10,
                    "Incorrect message type, expected 0x10, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x2222,
                    "incorrect sender id, expected 0x2222, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.text,
                    "INFO: Disabling channel 1 (PRN 15)
"
                    .to_string(),
                    "incorrect value for msg.text, expected string '{}', is '{}'",
                    "INFO: Disabling channel 1 (PRN 15)
"
                    .to_string(),
                    msg.text
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPrintDep"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
