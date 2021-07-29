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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFGNSS.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_navigation_MsgPosECEFGNSS() {
    {
        let mut payload = Cursor::new(vec![
            85, 41, 2, 0, 16, 32, 24, 229, 233, 29, 52, 254, 158, 218, 42, 142, 68, 193, 69, 162,
            89, 91, 34, 68, 80, 193, 131, 21, 176, 129, 239, 174, 77, 65, 182, 0, 18, 4, 135, 2,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgPosECEFGnss(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x229,
                    "Incorrect message type, expected 0x229, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 182,
                    "incorrect value for accuracy, expected 182, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 4,
                    "incorrect value for flags, expected 4, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 18,
                    "incorrect value for n_sats, expected 18, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501867800,
                    "incorrect value for tow, expected 501867800, is {}",
                    msg.tow
                );
                assert!(
                    msg.x.almost_eq(-2.69422970797708072e+06),
                    "incorrect value for x, expected -2.69422970797708072e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.26407342734581698e+06),
                    "incorrect value for y, expected -4.26407342734581698e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.89065501318615815e+06),
                    "incorrect value for z, expected 3.89065501318615815e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFGnss"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
