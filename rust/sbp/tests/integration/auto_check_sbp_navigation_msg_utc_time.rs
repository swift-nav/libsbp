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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgUTCTime.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_utc_time() {
    {
        let mut payload = Cursor::new(vec![
            85, 3, 1, 21, 3, 16, 1, 24, 229, 233, 29, 229, 7, 4, 9, 19, 24, 9, 0, 8, 175, 47, 199,
            253,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgUtcTime(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x103,
                    "Incorrect message type, expected 0x103, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x315,
                    "incorrect sender id, expected 0x315, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.day, 9,
                    "incorrect value for day, expected 9, is {}",
                    msg.day
                );
                assert_eq!(
                    msg.flags, 1,
                    "incorrect value for flags, expected 1, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.hours, 19,
                    "incorrect value for hours, expected 19, is {}",
                    msg.hours
                );
                assert_eq!(
                    msg.minutes, 24,
                    "incorrect value for minutes, expected 24, is {}",
                    msg.minutes
                );
                assert_eq!(
                    msg.month, 4,
                    "incorrect value for month, expected 4, is {}",
                    msg.month
                );
                assert_eq!(
                    msg.ns, 800000000,
                    "incorrect value for ns, expected 800000000, is {}",
                    msg.ns
                );
                assert_eq!(
                    msg.seconds, 9,
                    "incorrect value for seconds, expected 9, is {}",
                    msg.seconds
                );
                assert_eq!(
                    msg.tow, 501867800,
                    "incorrect value for tow, expected 501867800, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.year, 2021,
                    "incorrect value for year, expected 2021, is {}",
                    msg.year
                );
            }
            _ => panic!("Invalid message type! Expected a MsgUtcTime"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
