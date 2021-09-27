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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadByIndexDone.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_settings_msg_settings_read_by_index_done() {
    {
        let mut payload = Cursor::new(vec![85, 166, 0, 246, 215, 0, 163, 58]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSettingsReadByIndexDone(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xa6,
                    "Incorrect message type, expected 0xa6, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSettingsReadByIndexDone"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
