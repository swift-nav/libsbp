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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGloBiases.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_observation_msg_glo_biases() {
    {
        let mut payload = Cursor::new(vec![
            85, 117, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77, 211,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGloBiases(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x75,
                    "Incorrect message type, expected 0x75, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0,
                    "incorrect sender id, expected 0, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l1ca_bias, 0,
                    "incorrect value for l1ca_bias, expected 0, is {}",
                    msg.l1ca_bias
                );
                assert_eq!(
                    msg.l1p_bias, 0,
                    "incorrect value for l1p_bias, expected 0, is {}",
                    msg.l1p_bias
                );
                assert_eq!(
                    msg.l2ca_bias, 0,
                    "incorrect value for l2ca_bias, expected 0, is {}",
                    msg.l2ca_bias
                );
                assert_eq!(
                    msg.l2p_bias, 0,
                    "incorrect value for l2p_bias, expected 0, is {}",
                    msg.l2p_bias
                );
                assert_eq!(
                    msg.mask, 0,
                    "incorrect value for mask, expected 0, is {}",
                    msg.mask
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGloBiases"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
