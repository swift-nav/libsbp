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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinition.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_ssr_msg_ssr_tile_definition() {
    {
        let mut payload = Cursor::new(vec![
            85, 247, 5, 66, 0, 25, 31, 0, 1, 0, 2, 0, 4, 0, 8, 0, 16, 0, 32, 0, 64, 0, 128, 210, 2,
            150, 73, 0, 0, 0, 0, 214, 71,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrTileDefinition(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1527,
                    "Incorrect message type, expected 1527, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.stub[0], 31,
                    "incorrect value for stub[0], expected 31, is {}",
                    msg.stub[0]
                );
                assert_eq!(
                    msg.stub[1], 0,
                    "incorrect value for stub[1], expected 0, is {}",
                    msg.stub[1]
                );
                assert_eq!(
                    msg.stub[2], 1,
                    "incorrect value for stub[2], expected 1, is {}",
                    msg.stub[2]
                );
                assert_eq!(
                    msg.stub[3], 0,
                    "incorrect value for stub[3], expected 0, is {}",
                    msg.stub[3]
                );
                assert_eq!(
                    msg.stub[4], 2,
                    "incorrect value for stub[4], expected 2, is {}",
                    msg.stub[4]
                );
                assert_eq!(
                    msg.stub[5], 0,
                    "incorrect value for stub[5], expected 0, is {}",
                    msg.stub[5]
                );
                assert_eq!(
                    msg.stub[6], 4,
                    "incorrect value for stub[6], expected 4, is {}",
                    msg.stub[6]
                );
                assert_eq!(
                    msg.stub[7], 0,
                    "incorrect value for stub[7], expected 0, is {}",
                    msg.stub[7]
                );
                assert_eq!(
                    msg.stub[8], 8,
                    "incorrect value for stub[8], expected 8, is {}",
                    msg.stub[8]
                );
                assert_eq!(
                    msg.stub[9], 0,
                    "incorrect value for stub[9], expected 0, is {}",
                    msg.stub[9]
                );
                assert_eq!(
                    msg.stub[10], 16,
                    "incorrect value for stub[10], expected 16, is {}",
                    msg.stub[10]
                );
                assert_eq!(
                    msg.stub[11], 0,
                    "incorrect value for stub[11], expected 0, is {}",
                    msg.stub[11]
                );
                assert_eq!(
                    msg.stub[12], 32,
                    "incorrect value for stub[12], expected 32, is {}",
                    msg.stub[12]
                );
                assert_eq!(
                    msg.stub[13], 0,
                    "incorrect value for stub[13], expected 0, is {}",
                    msg.stub[13]
                );
                assert_eq!(
                    msg.stub[14], 64,
                    "incorrect value for stub[14], expected 64, is {}",
                    msg.stub[14]
                );
                assert_eq!(
                    msg.stub[15], 0,
                    "incorrect value for stub[15], expected 0, is {}",
                    msg.stub[15]
                );
                assert_eq!(
                    msg.stub[16], 128,
                    "incorrect value for stub[16], expected 128, is {}",
                    msg.stub[16]
                );
                assert_eq!(
                    msg.stub[17], 210,
                    "incorrect value for stub[17], expected 210, is {}",
                    msg.stub[17]
                );
                assert_eq!(
                    msg.stub[18], 2,
                    "incorrect value for stub[18], expected 2, is {}",
                    msg.stub[18]
                );
                assert_eq!(
                    msg.stub[19], 150,
                    "incorrect value for stub[19], expected 150, is {}",
                    msg.stub[19]
                );
                assert_eq!(
                    msg.stub[20], 73,
                    "incorrect value for stub[20], expected 73, is {}",
                    msg.stub[20]
                );
                assert_eq!(
                    msg.stub[21], 0,
                    "incorrect value for stub[21], expected 0, is {}",
                    msg.stub[21]
                );
                assert_eq!(
                    msg.stub[22], 0,
                    "incorrect value for stub[22], expected 0, is {}",
                    msg.stub[22]
                );
                assert_eq!(
                    msg.stub[23], 0,
                    "incorrect value for stub[23], expected 0, is {}",
                    msg.stub[23]
                );
                assert_eq!(
                    msg.stub[24], 0,
                    "incorrect value for stub[24], expected 0, is {}",
                    msg.stub[24]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrTileDefinition"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
