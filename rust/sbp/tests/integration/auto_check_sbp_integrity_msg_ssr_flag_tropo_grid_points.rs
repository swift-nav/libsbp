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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagTropoGridPoints.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_integrity_msg_ssr_flag_tropo_grid_points() {
    {
        let mut payload = Cursor::new(vec![
            85, 195, 11, 66, 0, 21, 180, 0, 0, 0, 3, 0, 1, 2, 3, 4, 0, 5, 0, 6, 3, 10, 0, 11, 0,
            12, 0, 243, 150,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrFlagTropoGridPoints(msg) => {
                assert_eq!(
                    msg.message_type(),
                    3011,
                    "Incorrect message type, expected 3011, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.faulty_points[0], 10,
                    "incorrect value for faulty_points[0], expected 10, is {}",
                    msg.faulty_points[0]
                );
                assert_eq!(
                    msg.faulty_points[1], 11,
                    "incorrect value for faulty_points[1], expected 11, is {}",
                    msg.faulty_points[1]
                );
                assert_eq!(
                    msg.faulty_points[2], 12,
                    "incorrect value for faulty_points[2], expected 12, is {}",
                    msg.faulty_points[2]
                );
                assert_eq!(
                    msg.header.chain_id, 6,
                    "incorrect value for header.chain_id, expected 6, is {}",
                    msg.header.chain_id
                );
                assert_eq!(
                    msg.header.num_msgs, 1,
                    "incorrect value for header.num_msgs, expected 1, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.obs_time.tow, 180,
                    "incorrect value for header.obs_time.tow, expected 180, is {}",
                    msg.header.obs_time.tow
                );
                assert_eq!(
                    msg.header.obs_time.wn, 3,
                    "incorrect value for header.obs_time.wn, expected 3, is {}",
                    msg.header.obs_time.wn
                );
                assert_eq!(
                    msg.header.seq_num, 2,
                    "incorrect value for header.seq_num, expected 2, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.ssr_sol_id, 3,
                    "incorrect value for header.ssr_sol_id, expected 3, is {}",
                    msg.header.ssr_sol_id
                );
                assert_eq!(
                    msg.header.tile_id, 5,
                    "incorrect value for header.tile_id, expected 5, is {}",
                    msg.header.tile_id
                );
                assert_eq!(
                    msg.header.tile_set_id, 4,
                    "incorrect value for header.tile_set_id, expected 4, is {}",
                    msg.header.tile_set_id
                );
                assert_eq!(
                    msg.n_faulty_points, 3,
                    "incorrect value for n_faulty_points, expected 3, is {}",
                    msg.n_faulty_points
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrFlagTropoGridPoints"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}

#[test]
#[cfg(feature = "json")]
fn test_json2sbp_auto_check_sbp_integrity_msg_ssr_flag_tropo_grid_points() {
    {
        let json_input = r#"{"header": {"obs_time": {"tow": 180, "wn": 3}, "num_msgs": 1, "seq_num": 2, "ssr_sol_id": 3, "tile_set_id": 4, "tile_id": 5, "chain_id": 6}, "n_faulty_points": 3, "faulty_points": [10, 11, 12], "preamble": 85, "msg_type": 3011, "sender": 66, "length": 21, "payload": "tAAAAAMAAQIDBAAFAAYDCgALAAwA", "crc": 38643}"#.as_bytes();

        let sbp_msg = {
            // Json to Sbp message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // Json to Sbp message from payload
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrFlagTropoGridPoints(msg) => {
                assert_eq!(
                    msg.message_type(),
                    3011,
                    "Incorrect message type, expected 3011, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.faulty_points[0], 10,
                    "incorrect value for faulty_points[0], expected 10, is {}",
                    msg.faulty_points[0]
                );
                assert_eq!(
                    msg.faulty_points[1], 11,
                    "incorrect value for faulty_points[1], expected 11, is {}",
                    msg.faulty_points[1]
                );
                assert_eq!(
                    msg.faulty_points[2], 12,
                    "incorrect value for faulty_points[2], expected 12, is {}",
                    msg.faulty_points[2]
                );
                assert_eq!(
                    msg.header.chain_id, 6,
                    "incorrect value for header.chain_id, expected 6, is {}",
                    msg.header.chain_id
                );
                assert_eq!(
                    msg.header.num_msgs, 1,
                    "incorrect value for header.num_msgs, expected 1, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.obs_time.tow, 180,
                    "incorrect value for header.obs_time.tow, expected 180, is {}",
                    msg.header.obs_time.tow
                );
                assert_eq!(
                    msg.header.obs_time.wn, 3,
                    "incorrect value for header.obs_time.wn, expected 3, is {}",
                    msg.header.obs_time.wn
                );
                assert_eq!(
                    msg.header.seq_num, 2,
                    "incorrect value for header.seq_num, expected 2, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.ssr_sol_id, 3,
                    "incorrect value for header.ssr_sol_id, expected 3, is {}",
                    msg.header.ssr_sol_id
                );
                assert_eq!(
                    msg.header.tile_id, 5,
                    "incorrect value for header.tile_id, expected 5, is {}",
                    msg.header.tile_id
                );
                assert_eq!(
                    msg.header.tile_set_id, 4,
                    "incorrect value for header.tile_set_id, expected 4, is {}",
                    msg.header.tile_set_id
                );
                assert_eq!(
                    msg.n_faulty_points, 3,
                    "incorrect value for n_faulty_points, expected 3, is {}",
                    msg.n_faulty_points
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrFlagTropoGridPoints"),
        };
    }
}
