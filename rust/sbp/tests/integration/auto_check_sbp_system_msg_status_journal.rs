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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusJournal.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_system_msg_status_journal() {
    {
        let mut payload = Cursor::new(vec![
            85, 253, 255, 211, 136, 33, 1, 0, 1, 4, 100, 0, 0, 0, 16, 146, 16, 0, 0, 6, 0, 1, 13,
            186, 19, 0, 0, 6, 0, 1, 14, 184, 34, 0, 0, 6, 0, 1, 15, 113, 119,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgStatusJournal(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xFFFD,
                    "Incorrect message type, expected 0xFFFD, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88D3,
                    "incorrect sender id, expected 0x88D3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.journal[0].report.component, 6,
                    "incorrect value for journal[0].report.component, expected 6, is {}",
                    msg.journal[0].report.component
                );
                assert_eq!(
                    msg.journal[0].report.generic, 1,
                    "incorrect value for journal[0].report.generic, expected 1, is {}",
                    msg.journal[0].report.generic
                );
                assert_eq!(
                    msg.journal[0].report.specific, 13,
                    "incorrect value for journal[0].report.specific, expected 13, is {}",
                    msg.journal[0].report.specific
                );
                assert_eq!(
                    msg.journal[0].uptime, 4242,
                    "incorrect value for journal[0].uptime, expected 4242, is {}",
                    msg.journal[0].uptime
                );
                assert_eq!(
                    msg.journal[1].report.component, 6,
                    "incorrect value for journal[1].report.component, expected 6, is {}",
                    msg.journal[1].report.component
                );
                assert_eq!(
                    msg.journal[1].report.generic, 1,
                    "incorrect value for journal[1].report.generic, expected 1, is {}",
                    msg.journal[1].report.generic
                );
                assert_eq!(
                    msg.journal[1].report.specific, 14,
                    "incorrect value for journal[1].report.specific, expected 14, is {}",
                    msg.journal[1].report.specific
                );
                assert_eq!(
                    msg.journal[1].uptime, 5050,
                    "incorrect value for journal[1].uptime, expected 5050, is {}",
                    msg.journal[1].uptime
                );
                assert_eq!(
                    msg.journal[2].report.component, 6,
                    "incorrect value for journal[2].report.component, expected 6, is {}",
                    msg.journal[2].report.component
                );
                assert_eq!(
                    msg.journal[2].report.generic, 1,
                    "incorrect value for journal[2].report.generic, expected 1, is {}",
                    msg.journal[2].report.generic
                );
                assert_eq!(
                    msg.journal[2].report.specific, 15,
                    "incorrect value for journal[2].report.specific, expected 15, is {}",
                    msg.journal[2].report.specific
                );
                assert_eq!(
                    msg.journal[2].uptime, 8888,
                    "incorrect value for journal[2].uptime, expected 8888, is {}",
                    msg.journal[2].uptime
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
                assert_eq!(
                    msg.sequence_descriptor, 16,
                    "incorrect value for sequence_descriptor, expected 16, is {}",
                    msg.sequence_descriptor
                );
                assert_eq!(
                    msg.total_status_reports, 100,
                    "incorrect value for total_status_reports, expected 100, is {}",
                    msg.total_status_reports
                );
            }
            _ => panic!("Invalid message type! Expected a MsgStatusJournal"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 253, 255, 211, 136, 17, 1, 0, 1, 4, 100, 0, 0, 0, 16, 146, 16, 0, 0, 6, 0, 1, 13,
            144, 121,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgStatusJournal(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xFFFD,
                    "Incorrect message type, expected 0xFFFD, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88D3,
                    "incorrect sender id, expected 0x88D3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.journal[0].report.component, 6,
                    "incorrect value for journal[0].report.component, expected 6, is {}",
                    msg.journal[0].report.component
                );
                assert_eq!(
                    msg.journal[0].report.generic, 1,
                    "incorrect value for journal[0].report.generic, expected 1, is {}",
                    msg.journal[0].report.generic
                );
                assert_eq!(
                    msg.journal[0].report.specific, 13,
                    "incorrect value for journal[0].report.specific, expected 13, is {}",
                    msg.journal[0].report.specific
                );
                assert_eq!(
                    msg.journal[0].uptime, 4242,
                    "incorrect value for journal[0].uptime, expected 4242, is {}",
                    msg.journal[0].uptime
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
                assert_eq!(
                    msg.sequence_descriptor, 16,
                    "incorrect value for sequence_descriptor, expected 16, is {}",
                    msg.sequence_descriptor
                );
                assert_eq!(
                    msg.total_status_reports, 100,
                    "incorrect value for total_status_reports, expected 100, is {}",
                    msg.total_status_reports
                );
            }
            _ => panic!("Invalid message type! Expected a MsgStatusJournal"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}