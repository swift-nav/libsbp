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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelCog.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_vel_cog() {
    {
        let mut payload = Cursor::new(vec![
            85, 28, 2, 211, 136, 29, 48, 246, 122, 19, 232, 3, 0, 0, 208, 7, 0, 0, 184, 11, 0, 0,
            160, 15, 0, 0, 136, 19, 0, 0, 112, 23, 0, 0, 62, 170, 74,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelCog(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x21C,
                    "Incorrect message type, expected 0x21C, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88D3,
                    "incorrect sender id, expected 0x88D3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cog, 1000,
                    "incorrect value for cog, expected 1000, is {}",
                    msg.cog
                );
                assert_eq!(
                    msg.cog_accuracy, 4000,
                    "incorrect value for cog_accuracy, expected 4000, is {}",
                    msg.cog_accuracy
                );
                assert_eq!(
                    msg.flags, 62,
                    "incorrect value for flags, expected 62, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.sog, 2000,
                    "incorrect value for sog, expected 2000, is {}",
                    msg.sog
                );
                assert_eq!(
                    msg.sog_accuracy, 5000,
                    "incorrect value for sog_accuracy, expected 5000, is {}",
                    msg.sog_accuracy
                );
                assert_eq!(
                    msg.tow, 326825520,
                    "incorrect value for tow, expected 326825520, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vel_d, 3000,
                    "incorrect value for vel_d, expected 3000, is {}",
                    msg.vel_d
                );
                assert_eq!(
                    msg.vel_d_accuracy, 6000,
                    "incorrect value for vel_d_accuracy, expected 6000, is {}",
                    msg.vel_d_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelCog"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 28, 2, 211, 136, 29, 48, 246, 122, 19, 123, 0, 0, 0, 200, 1, 0, 0, 24, 252, 255,
            255, 0, 149, 186, 10, 100, 0, 0, 0, 100, 0, 0, 0, 0, 240, 0,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelCog(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x21C,
                    "Incorrect message type, expected 0x21C, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88D3,
                    "incorrect sender id, expected 0x88D3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cog, 123,
                    "incorrect value for cog, expected 123, is {}",
                    msg.cog
                );
                assert_eq!(
                    msg.cog_accuracy, 180000000,
                    "incorrect value for cog_accuracy, expected 180000000, is {}",
                    msg.cog_accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.sog, 456,
                    "incorrect value for sog, expected 456, is {}",
                    msg.sog
                );
                assert_eq!(
                    msg.sog_accuracy, 100,
                    "incorrect value for sog_accuracy, expected 100, is {}",
                    msg.sog_accuracy
                );
                assert_eq!(
                    msg.tow, 326825520,
                    "incorrect value for tow, expected 326825520, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vel_d, -1000,
                    "incorrect value for vel_d, expected -1000, is {}",
                    msg.vel_d
                );
                assert_eq!(
                    msg.vel_d_accuracy, 100,
                    "incorrect value for vel_d_accuracy, expected 100, is {}",
                    msg.vel_d_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelCog"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 28, 2, 211, 136, 29, 48, 246, 122, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94, 119,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgVelCog(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x21C,
                    "Incorrect message type, expected 0x21C, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88D3,
                    "incorrect sender id, expected 0x88D3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.cog, 0,
                    "incorrect value for cog, expected 0, is {}",
                    msg.cog
                );
                assert_eq!(
                    msg.cog_accuracy, 0,
                    "incorrect value for cog_accuracy, expected 0, is {}",
                    msg.cog_accuracy
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.sog, 0,
                    "incorrect value for sog, expected 0, is {}",
                    msg.sog
                );
                assert_eq!(
                    msg.sog_accuracy, 0,
                    "incorrect value for sog_accuracy, expected 0, is {}",
                    msg.sog_accuracy
                );
                assert_eq!(
                    msg.tow, 326825520,
                    "incorrect value for tow, expected 326825520, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vel_d, 0,
                    "incorrect value for vel_d, expected 0, is {}",
                    msg.vel_d
                );
                assert_eq!(
                    msg.vel_d_accuracy, 0,
                    "incorrect value for vel_d_accuracy, expected 0, is {}",
                    msg.vel_d_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgVelCog"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
