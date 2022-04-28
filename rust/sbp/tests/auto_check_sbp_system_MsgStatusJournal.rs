//
// Copyright (C) 2019 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusJournal.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_system_MsgStatusJournal() {
    {
        let mut payload = Cursor::new(vec![
            85, 253, 255, 211, 136, 34, 1, 0, 1, 4, 100, 0, 0, 0, 7, 3, 146, 16, 0, 0, 6, 0, 1, 13,
            186, 19, 0, 0, 6, 0, 1, 14, 184, 34, 0, 0, 6, 0, 1, 15, 11, 55,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgStatusJournal(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0xFFFD,
                    "Incorrect message type, expected 0xFFFD, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88D3,
                    "incorrect sender id, expected 0x88D3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.journal[0].component, 6,
                    "incorrect value for journal[0].component, expected 6, is {}",
                    msg.journal[0].component
                );
                assert_eq!(
                    msg.journal[0].generic, 1,
                    "incorrect value for journal[0].generic, expected 1, is {}",
                    msg.journal[0].generic
                );
                assert_eq!(
                    msg.journal[0].specific, 13,
                    "incorrect value for journal[0].specific, expected 13, is {}",
                    msg.journal[0].specific
                );
                assert_eq!(
                    msg.journal[0].uptime, 4242,
                    "incorrect value for journal[0].uptime, expected 4242, is {}",
                    msg.journal[0].uptime
                );
                assert_eq!(
                    msg.journal[1].component, 6,
                    "incorrect value for journal[1].component, expected 6, is {}",
                    msg.journal[1].component
                );
                assert_eq!(
                    msg.journal[1].generic, 1,
                    "incorrect value for journal[1].generic, expected 1, is {}",
                    msg.journal[1].generic
                );
                assert_eq!(
                    msg.journal[1].specific, 14,
                    "incorrect value for journal[1].specific, expected 14, is {}",
                    msg.journal[1].specific
                );
                assert_eq!(
                    msg.journal[1].uptime, 5050,
                    "incorrect value for journal[1].uptime, expected 5050, is {}",
                    msg.journal[1].uptime
                );
                assert_eq!(
                    msg.journal[2].component, 6,
                    "incorrect value for journal[2].component, expected 6, is {}",
                    msg.journal[2].component
                );
                assert_eq!(
                    msg.journal[2].generic, 1,
                    "incorrect value for journal[2].generic, expected 1, is {}",
                    msg.journal[2].generic
                );
                assert_eq!(
                    msg.journal[2].specific, 15,
                    "incorrect value for journal[2].specific, expected 15, is {}",
                    msg.journal[2].specific
                );
                assert_eq!(
                    msg.journal[2].uptime, 8888,
                    "incorrect value for journal[2].uptime, expected 8888, is {}",
                    msg.journal[2].uptime
                );
                assert_eq!(
                    msg.n_packets, 3,
                    "incorrect value for n_packets, expected 3, is {}",
                    msg.n_packets
                );
                assert_eq!(
                    msg.n_status_reports, 100,
                    "incorrect value for n_status_reports, expected 100, is {}",
                    msg.n_status_reports
                );
                assert_eq!(
                    msg.packet_index, 7,
                    "incorrect value for packet_index, expected 7, is {}",
                    msg.packet_index
                );
                assert_eq!(
                    msg.reporting_system, 1,
                    "incorrect value for reporting_system, expected 1, is {}",
                    msg.reporting_system
                );
                assert_eq!(
                    msg.sbp_version, 1025,
                    "incorrect value for sbp_version, expected 1025, is {}",
                    msg.sbp_version
                );
            }
            _ => panic!("Invalid message type! Expected a MsgStatusJournal"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 253, 255, 211, 136, 18, 1, 0, 1, 4, 100, 0, 0, 0, 7, 1, 146, 16, 0, 0, 6, 0, 1, 13,
            106, 72,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgStatusJournal(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0xFFFD,
                    "Incorrect message type, expected 0xFFFD, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88D3,
                    "incorrect sender id, expected 0x88D3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.journal[0].component, 6,
                    "incorrect value for journal[0].component, expected 6, is {}",
                    msg.journal[0].component
                );
                assert_eq!(
                    msg.journal[0].generic, 1,
                    "incorrect value for journal[0].generic, expected 1, is {}",
                    msg.journal[0].generic
                );
                assert_eq!(
                    msg.journal[0].specific, 13,
                    "incorrect value for journal[0].specific, expected 13, is {}",
                    msg.journal[0].specific
                );
                assert_eq!(
                    msg.journal[0].uptime, 4242,
                    "incorrect value for journal[0].uptime, expected 4242, is {}",
                    msg.journal[0].uptime
                );
                assert_eq!(
                    msg.n_packets, 1,
                    "incorrect value for n_packets, expected 1, is {}",
                    msg.n_packets
                );
                assert_eq!(
                    msg.n_status_reports, 100,
                    "incorrect value for n_status_reports, expected 100, is {}",
                    msg.n_status_reports
                );
                assert_eq!(
                    msg.packet_index, 7,
                    "incorrect value for packet_index, expected 7, is {}",
                    msg.packet_index
                );
                assert_eq!(
                    msg.reporting_system, 1,
                    "incorrect value for reporting_system, expected 1, is {}",
                    msg.reporting_system
                );
                assert_eq!(
                    msg.sbp_version, 1025,
                    "incorrect value for sbp_version, expected 1025, is {}",
                    msg.sbp_version
                );
            }
            _ => panic!("Invalid message type! Expected a MsgStatusJournal"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
