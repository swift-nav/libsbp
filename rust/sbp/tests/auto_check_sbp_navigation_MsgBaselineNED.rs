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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNED.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_navigation_MsgBaselineNED() {
    {
        let mut payload = Cursor::new(vec![
            85, 12, 2, 211, 136, 22, 40, 244, 122, 19, 201, 115, 12, 0, 179, 88, 230, 255, 153,
            125, 0, 0, 0, 0, 0, 0, 14, 0, 226, 70,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNED(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20c,
                    "Incorrect message type, expected 0x20c, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, 32153,
                    "incorrect value for d, expected 32153, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, -1681229,
                    "incorrect value for e, expected -1681229, is {}",
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
                    msg.n, 816073,
                    "incorrect value for n, expected 816073, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNED"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 12, 2, 211, 136, 22, 16, 248, 122, 19, 98, 115, 12, 0, 194, 88, 230, 255, 110, 127,
            0, 0, 0, 0, 0, 0, 15, 0, 69, 93,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNED(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20c,
                    "Incorrect message type, expected 0x20c, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, 32622,
                    "incorrect value for d, expected 32622, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, -1681214,
                    "incorrect value for e, expected -1681214, is {}",
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
                    msg.n, 815970,
                    "incorrect value for n, expected 815970, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNED"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 12, 2, 211, 136, 22, 248, 251, 122, 19, 143, 114, 12, 0, 173, 88, 230, 255, 238,
            127, 0, 0, 0, 0, 0, 0, 15, 0, 210, 169,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNED(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20c,
                    "Incorrect message type, expected 0x20c, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, 32750,
                    "incorrect value for d, expected 32750, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, -1681235,
                    "incorrect value for e, expected -1681235, is {}",
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
                    msg.n, 815759,
                    "incorrect value for n, expected 815759, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNED"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 12, 2, 211, 136, 22, 224, 255, 122, 19, 86, 112, 12, 0, 51, 88, 230, 255, 47, 127,
            0, 0, 0, 0, 0, 0, 15, 0, 135, 107,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNED(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20c,
                    "Incorrect message type, expected 0x20c, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, 32559,
                    "incorrect value for d, expected 32559, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, -1681357,
                    "incorrect value for e, expected -1681357, is {}",
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
                    msg.n, 815190,
                    "incorrect value for n, expected 815190, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNED"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 12, 2, 211, 136, 22, 200, 3, 123, 19, 214, 110, 12, 0, 220, 87, 230, 255, 165, 126,
            0, 0, 0, 0, 0, 0, 15, 0, 190, 80,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgBaselineNED(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x20c,
                    "Incorrect message type, expected 0x20c, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.d, 32421,
                    "incorrect value for d, expected 32421, is {}",
                    msg.d
                );
                assert_eq!(
                    msg.e, -1681444,
                    "incorrect value for e, expected -1681444, is {}",
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
                    msg.n, 814806,
                    "incorrect value for n, expected 814806, is {}",
                    msg.n
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
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgBaselineNED"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
