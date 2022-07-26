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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagSatellites.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_integrity_msg_ssr_flag_satellites() {
    {
        let mut payload = Cursor::new(vec![
            85, 189, 11, 66, 0, 15, 180, 0, 0, 0, 3, 0, 1, 2, 3, 4, 5, 3, 10, 11, 12, 110, 165,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrFlagSatellites(msg) => {
                assert_eq!(
                    msg.message_type(),
                    3005,
                    "Incorrect message type, expected 3005, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.chain_id, 4,
                    "incorrect value for chain_id, expected 4, is {}",
                    msg.chain_id
                );
                assert_eq!(
                    msg.const_id, 5,
                    "incorrect value for const_id, expected 5, is {}",
                    msg.const_id
                );
                assert_eq!(
                    msg.faulty_sats[0], 10,
                    "incorrect value for faulty_sats[0], expected 10, is {}",
                    msg.faulty_sats[0]
                );
                assert_eq!(
                    msg.faulty_sats[1], 11,
                    "incorrect value for faulty_sats[1], expected 11, is {}",
                    msg.faulty_sats[1]
                );
                assert_eq!(
                    msg.faulty_sats[2], 12,
                    "incorrect value for faulty_sats[2], expected 12, is {}",
                    msg.faulty_sats[2]
                );
                assert_eq!(
                    msg.n_faulty_sats, 3,
                    "incorrect value for n_faulty_sats, expected 3, is {}",
                    msg.n_faulty_sats
                );
                assert_eq!(
                    msg.num_msgs, 1,
                    "incorrect value for num_msgs, expected 1, is {}",
                    msg.num_msgs
                );
                assert_eq!(
                    msg.obs_time.tow, 180,
                    "incorrect value for obs_time.tow, expected 180, is {}",
                    msg.obs_time.tow
                );
                assert_eq!(
                    msg.obs_time.wn, 3,
                    "incorrect value for obs_time.wn, expected 3, is {}",
                    msg.obs_time.wn
                );
                assert_eq!(
                    msg.seq_num, 2,
                    "incorrect value for seq_num, expected 2, is {}",
                    msg.seq_num
                );
                assert_eq!(
                    msg.ssr_sol_id, 3,
                    "incorrect value for ssr_sol_id, expected 3, is {}",
                    msg.ssr_sol_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrFlagSatellites"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}

/// Tests [`sbp::json::iter_messages`] for JSON payload -> SBP message
/// and [`sbp::json::iter_messages_from_fields`] for JSON fields -> SBP message.
///
/// Asserts:
/// -   SBP message constructed via payload is identical to from fields
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_json2sbp_auto_check_sbp_integrity_msg_ssr_flag_satellites() {
    {
        let json_input = r#"{"obs_time": {"tow": 180, "wn": 3}, "num_msgs": 1, "seq_num": 2, "ssr_sol_id": 3, "chain_id": 4, "const_id": 5, "n_faulty_sats": 3, "faulty_sats": [10, 11, 12], "preamble": 85, "msg_type": 3005, "sender": 66, "length": 15, "payload": "tAAAAAMAAQIDBAUDCgsM", "crc": 42350}"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrFlagSatellites(msg) => {
                assert_eq!(
                    msg.message_type(),
                    3005,
                    "Incorrect message type, expected 3005, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.chain_id, 4,
                    "incorrect value for chain_id, expected 4, is {}",
                    msg.chain_id
                );
                assert_eq!(
                    msg.const_id, 5,
                    "incorrect value for const_id, expected 5, is {}",
                    msg.const_id
                );
                assert_eq!(
                    msg.faulty_sats[0], 10,
                    "incorrect value for faulty_sats[0], expected 10, is {}",
                    msg.faulty_sats[0]
                );
                assert_eq!(
                    msg.faulty_sats[1], 11,
                    "incorrect value for faulty_sats[1], expected 11, is {}",
                    msg.faulty_sats[1]
                );
                assert_eq!(
                    msg.faulty_sats[2], 12,
                    "incorrect value for faulty_sats[2], expected 12, is {}",
                    msg.faulty_sats[2]
                );
                assert_eq!(
                    msg.n_faulty_sats, 3,
                    "incorrect value for n_faulty_sats, expected 3, is {}",
                    msg.n_faulty_sats
                );
                assert_eq!(
                    msg.num_msgs, 1,
                    "incorrect value for num_msgs, expected 1, is {}",
                    msg.num_msgs
                );
                assert_eq!(
                    msg.obs_time.tow, 180,
                    "incorrect value for obs_time.tow, expected 180, is {}",
                    msg.obs_time.tow
                );
                assert_eq!(
                    msg.obs_time.wn, 3,
                    "incorrect value for obs_time.wn, expected 3, is {}",
                    msg.obs_time.wn
                );
                assert_eq!(
                    msg.seq_num, 2,
                    "incorrect value for seq_num, expected 2, is {}",
                    msg.seq_num
                );
                assert_eq!(
                    msg.ssr_sol_id, 3,
                    "incorrect value for ssr_sol_id, expected 3, is {}",
                    msg.ssr_sol_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrFlagSatellites"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_integrity_msg_ssr_flag_satellites`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_integrity_msg_ssr_flag_satellites() {
    {
        let mut payload = Cursor::new(vec![
            85, 189, 11, 66, 0, 15, 180, 0, 0, 0, 3, 0, 1, 2, 3, 4, 5, 3, 10, 11, 12, 110, 165,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgSsrFlagSatellites(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrFlagSatellites(msg) => {
                assert_eq!(
                    msg.message_type(),
                    3005,
                    "Incorrect message type, expected 3005, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.chain_id, 4,
                    "incorrect value for chain_id, expected 4, is {}",
                    msg.chain_id
                );
                assert_eq!(
                    msg.const_id, 5,
                    "incorrect value for const_id, expected 5, is {}",
                    msg.const_id
                );
                assert_eq!(
                    msg.faulty_sats[0], 10,
                    "incorrect value for faulty_sats[0], expected 10, is {}",
                    msg.faulty_sats[0]
                );
                assert_eq!(
                    msg.faulty_sats[1], 11,
                    "incorrect value for faulty_sats[1], expected 11, is {}",
                    msg.faulty_sats[1]
                );
                assert_eq!(
                    msg.faulty_sats[2], 12,
                    "incorrect value for faulty_sats[2], expected 12, is {}",
                    msg.faulty_sats[2]
                );
                assert_eq!(
                    msg.n_faulty_sats, 3,
                    "incorrect value for n_faulty_sats, expected 3, is {}",
                    msg.n_faulty_sats
                );
                assert_eq!(
                    msg.num_msgs, 1,
                    "incorrect value for num_msgs, expected 1, is {}",
                    msg.num_msgs
                );
                assert_eq!(
                    msg.obs_time.tow, 180,
                    "incorrect value for obs_time.tow, expected 180, is {}",
                    msg.obs_time.tow
                );
                assert_eq!(
                    msg.obs_time.wn, 3,
                    "incorrect value for obs_time.wn, expected 3, is {}",
                    msg.obs_time.wn
                );
                assert_eq!(
                    msg.seq_num, 2,
                    "incorrect value for seq_num, expected 2, is {}",
                    msg.seq_num
                );
                assert_eq!(
                    msg.ssr_sol_id, 3,
                    "incorrect value for ssr_sol_id, expected 3, is {}",
                    msg.ssr_sol_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrFlagSatellites"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
