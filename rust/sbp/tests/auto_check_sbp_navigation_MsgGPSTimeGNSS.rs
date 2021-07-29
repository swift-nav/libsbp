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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTimeGNSS.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_navigation_MsgGPSTimeGNSS() {
    {
        let mut payload = Cursor::new(vec![
            85, 4, 1, 211, 136, 11, 128, 7, 40, 244, 122, 19, 244, 139, 2, 0, 0, 153, 88,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTimeGnss(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x104,
                    "Incorrect message type, expected 0x104, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 166900,
                    "incorrect value for ns_residual, expected 166900, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326825000,
                    "incorrect value for tow, expected 326825000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeGnss"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 1, 211, 136, 11, 128, 7, 28, 246, 122, 19, 126, 234, 3, 0, 0, 250, 195,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTimeGnss(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x104,
                    "Incorrect message type, expected 0x104, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 256638,
                    "incorrect value for ns_residual, expected 256638, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326825500,
                    "incorrect value for tow, expected 326825500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeGnss"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 1, 211, 136, 11, 128, 7, 16, 248, 122, 19, 129, 12, 4, 0, 0, 183, 148,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTimeGnss(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x104,
                    "Incorrect message type, expected 0x104, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 265345,
                    "incorrect value for ns_residual, expected 265345, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326826000,
                    "incorrect value for tow, expected 326826000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeGnss"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 1, 211, 136, 11, 128, 7, 4, 250, 122, 19, 137, 204, 4, 0, 0, 137, 101,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTimeGnss(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x104,
                    "Incorrect message type, expected 0x104, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 314505,
                    "incorrect value for ns_residual, expected 314505, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326826500,
                    "incorrect value for tow, expected 326826500, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeGnss"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 4, 1, 211, 136, 11, 128, 7, 248, 251, 122, 19, 181, 137, 5, 0, 0, 15, 225,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgGPSTimeGnss(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x104,
                    "Incorrect message type, expected 0x104, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.ns_residual, 362933,
                    "incorrect value for ns_residual, expected 362933, is {}",
                    msg.ns_residual
                );
                assert_eq!(
                    msg.tow, 326827000,
                    "incorrect value for tow, expected 326827000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.wn, 1920,
                    "incorrect value for wn, expected 1920, is {}",
                    msg.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGPSTimeGnss"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
