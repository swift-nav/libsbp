//
// Copyright (C) 2019-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSocketUsage.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_linux_msg_linux_socket_usage() {
    {
        let mut payload = Cursor::new(vec![
            85, 5, 127, 114, 138, 72, 13, 196, 69, 173, 67, 222, 186, 181, 246, 154, 251, 17, 224,
            179, 26, 169, 177, 90, 149, 213, 214, 6, 126, 64, 120, 185, 84, 131, 200, 111, 32, 141,
            217, 209, 52, 14, 190, 147, 159, 246, 141, 122, 212, 119, 131, 30, 120, 47, 25, 109,
            154, 65, 132, 164, 39, 30, 30, 175, 8, 44, 28, 111, 236, 240, 176, 74, 159, 129, 154,
            153, 162, 229, 130, 154,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxSocketUsage(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f05,
                    "Incorrect message type, expected 0x7f05, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x8a72,
                    "incorrect sender id, expected 0x8a72, is {sender_id}"
                );
                assert_eq!(
                    msg.avg_queue_depth, 2907030541,
                    "incorrect value for avg_queue_depth, expected 2907030541, is {}",
                    msg.avg_queue_depth
                );
                assert_eq!(
                    msg.max_queue_depth, 3048922691,
                    "incorrect value for max_queue_depth, expected 3048922691, is {}",
                    msg.max_queue_depth
                );
                assert_eq!(
                    msg.socket_state_counts[0], 39670,
                    "incorrect value for socket_state_counts[0], expected 39670, is {}",
                    msg.socket_state_counts[0]
                );
                assert_eq!(
                    msg.socket_state_counts[1], 4603,
                    "incorrect value for socket_state_counts[1], expected 4603, is {}",
                    msg.socket_state_counts[1]
                );
                assert_eq!(
                    msg.socket_state_counts[2], 46048,
                    "incorrect value for socket_state_counts[2], expected 46048, is {}",
                    msg.socket_state_counts[2]
                );
                assert_eq!(
                    msg.socket_state_counts[3], 43290,
                    "incorrect value for socket_state_counts[3], expected 43290, is {}",
                    msg.socket_state_counts[3]
                );
                assert_eq!(
                    msg.socket_state_counts[4], 23217,
                    "incorrect value for socket_state_counts[4], expected 23217, is {}",
                    msg.socket_state_counts[4]
                );
                assert_eq!(
                    msg.socket_state_counts[5], 54677,
                    "incorrect value for socket_state_counts[5], expected 54677, is {}",
                    msg.socket_state_counts[5]
                );
                assert_eq!(
                    msg.socket_state_counts[6], 1750,
                    "incorrect value for socket_state_counts[6], expected 1750, is {}",
                    msg.socket_state_counts[6]
                );
                assert_eq!(
                    msg.socket_state_counts[7], 16510,
                    "incorrect value for socket_state_counts[7], expected 16510, is {}",
                    msg.socket_state_counts[7]
                );
                assert_eq!(
                    msg.socket_state_counts[8], 47480,
                    "incorrect value for socket_state_counts[8], expected 47480, is {}",
                    msg.socket_state_counts[8]
                );
                assert_eq!(
                    msg.socket_state_counts[9], 33620,
                    "incorrect value for socket_state_counts[9], expected 33620, is {}",
                    msg.socket_state_counts[9]
                );
                assert_eq!(
                    msg.socket_state_counts[10], 28616,
                    "incorrect value for socket_state_counts[10], expected 28616, is {}",
                    msg.socket_state_counts[10]
                );
                assert_eq!(
                    msg.socket_state_counts[11], 36128,
                    "incorrect value for socket_state_counts[11], expected 36128, is {}",
                    msg.socket_state_counts[11]
                );
                assert_eq!(
                    msg.socket_state_counts[12], 53721,
                    "incorrect value for socket_state_counts[12], expected 53721, is {}",
                    msg.socket_state_counts[12]
                );
                assert_eq!(
                    msg.socket_state_counts[13], 3636,
                    "incorrect value for socket_state_counts[13], expected 3636, is {}",
                    msg.socket_state_counts[13]
                );
                assert_eq!(
                    msg.socket_state_counts[14], 37822,
                    "incorrect value for socket_state_counts[14], expected 37822, is {}",
                    msg.socket_state_counts[14]
                );
                assert_eq!(
                    msg.socket_state_counts[15], 63135,
                    "incorrect value for socket_state_counts[15], expected 63135, is {}",
                    msg.socket_state_counts[15]
                );
                assert_eq!(
                    msg.socket_type_counts[0], 31373,
                    "incorrect value for socket_type_counts[0], expected 31373, is {}",
                    msg.socket_type_counts[0]
                );
                assert_eq!(
                    msg.socket_type_counts[1], 30676,
                    "incorrect value for socket_type_counts[1], expected 30676, is {}",
                    msg.socket_type_counts[1]
                );
                assert_eq!(
                    msg.socket_type_counts[2], 7811,
                    "incorrect value for socket_type_counts[2], expected 7811, is {}",
                    msg.socket_type_counts[2]
                );
                assert_eq!(
                    msg.socket_type_counts[3], 12152,
                    "incorrect value for socket_type_counts[3], expected 12152, is {}",
                    msg.socket_type_counts[3]
                );
                assert_eq!(
                    msg.socket_type_counts[4], 27929,
                    "incorrect value for socket_type_counts[4], expected 27929, is {}",
                    msg.socket_type_counts[4]
                );
                assert_eq!(
                    msg.socket_type_counts[5], 16794,
                    "incorrect value for socket_type_counts[5], expected 16794, is {}",
                    msg.socket_type_counts[5]
                );
                assert_eq!(
                    msg.socket_type_counts[6], 42116,
                    "incorrect value for socket_type_counts[6], expected 42116, is {}",
                    msg.socket_type_counts[6]
                );
                assert_eq!(
                    msg.socket_type_counts[7], 7719,
                    "incorrect value for socket_type_counts[7], expected 7719, is {}",
                    msg.socket_type_counts[7]
                );
                assert_eq!(
                    msg.socket_type_counts[8], 44830,
                    "incorrect value for socket_type_counts[8], expected 44830, is {}",
                    msg.socket_type_counts[8]
                );
                assert_eq!(
                    msg.socket_type_counts[9], 11272,
                    "incorrect value for socket_type_counts[9], expected 11272, is {}",
                    msg.socket_type_counts[9]
                );
                assert_eq!(
                    msg.socket_type_counts[10], 28444,
                    "incorrect value for socket_type_counts[10], expected 28444, is {}",
                    msg.socket_type_counts[10]
                );
                assert_eq!(
                    msg.socket_type_counts[11], 61676,
                    "incorrect value for socket_type_counts[11], expected 61676, is {}",
                    msg.socket_type_counts[11]
                );
                assert_eq!(
                    msg.socket_type_counts[12], 19120,
                    "incorrect value for socket_type_counts[12], expected 19120, is {}",
                    msg.socket_type_counts[12]
                );
                assert_eq!(
                    msg.socket_type_counts[13], 33183,
                    "incorrect value for socket_type_counts[13], expected 33183, is {}",
                    msg.socket_type_counts[13]
                );
                assert_eq!(
                    msg.socket_type_counts[14], 39322,
                    "incorrect value for socket_type_counts[14], expected 39322, is {}",
                    msg.socket_type_counts[14]
                );
                assert_eq!(
                    msg.socket_type_counts[15], 58786,
                    "incorrect value for socket_type_counts[15], expected 58786, is {}",
                    msg.socket_type_counts[15]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxSocketUsage"),
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
fn test_json2sbp_auto_check_sbp_linux_msg_linux_socket_usage() {
    {
        let json_input = r#"{"crc":39554,"length":72,"msg_type":32517,"payload":"DcRFrUPeurX2mvsR4LMaqbFaldXWBn5AeLlUg8hvII3Z0TQOvpOf9o161HeDHngvGW2aQYSkJx4erwgsHG/s8LBKn4GamaLl","preamble":85,"sender":35442,"avg_queue_depth":2907030541,"max_queue_depth":3048922691,"socket_state_counts":[39670,4603,46048,43290,23217,54677,1750,16510,47480,33620,28616,36128,53721,3636,37822,63135],"socket_type_counts":[31373,30676,7811,12152,27929,16794,42116,7719,44830,11272,28444,61676,19120,33183,39322,58786]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgLinuxSocketUsage(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f05,
                    "Incorrect message type, expected 0x7f05, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x8a72,
                    "incorrect sender id, expected 0x8a72, is {sender_id}"
                );
                assert_eq!(
                    msg.avg_queue_depth, 2907030541,
                    "incorrect value for avg_queue_depth, expected 2907030541, is {}",
                    msg.avg_queue_depth
                );
                assert_eq!(
                    msg.max_queue_depth, 3048922691,
                    "incorrect value for max_queue_depth, expected 3048922691, is {}",
                    msg.max_queue_depth
                );
                assert_eq!(
                    msg.socket_state_counts[0], 39670,
                    "incorrect value for socket_state_counts[0], expected 39670, is {}",
                    msg.socket_state_counts[0]
                );
                assert_eq!(
                    msg.socket_state_counts[1], 4603,
                    "incorrect value for socket_state_counts[1], expected 4603, is {}",
                    msg.socket_state_counts[1]
                );
                assert_eq!(
                    msg.socket_state_counts[2], 46048,
                    "incorrect value for socket_state_counts[2], expected 46048, is {}",
                    msg.socket_state_counts[2]
                );
                assert_eq!(
                    msg.socket_state_counts[3], 43290,
                    "incorrect value for socket_state_counts[3], expected 43290, is {}",
                    msg.socket_state_counts[3]
                );
                assert_eq!(
                    msg.socket_state_counts[4], 23217,
                    "incorrect value for socket_state_counts[4], expected 23217, is {}",
                    msg.socket_state_counts[4]
                );
                assert_eq!(
                    msg.socket_state_counts[5], 54677,
                    "incorrect value for socket_state_counts[5], expected 54677, is {}",
                    msg.socket_state_counts[5]
                );
                assert_eq!(
                    msg.socket_state_counts[6], 1750,
                    "incorrect value for socket_state_counts[6], expected 1750, is {}",
                    msg.socket_state_counts[6]
                );
                assert_eq!(
                    msg.socket_state_counts[7], 16510,
                    "incorrect value for socket_state_counts[7], expected 16510, is {}",
                    msg.socket_state_counts[7]
                );
                assert_eq!(
                    msg.socket_state_counts[8], 47480,
                    "incorrect value for socket_state_counts[8], expected 47480, is {}",
                    msg.socket_state_counts[8]
                );
                assert_eq!(
                    msg.socket_state_counts[9], 33620,
                    "incorrect value for socket_state_counts[9], expected 33620, is {}",
                    msg.socket_state_counts[9]
                );
                assert_eq!(
                    msg.socket_state_counts[10], 28616,
                    "incorrect value for socket_state_counts[10], expected 28616, is {}",
                    msg.socket_state_counts[10]
                );
                assert_eq!(
                    msg.socket_state_counts[11], 36128,
                    "incorrect value for socket_state_counts[11], expected 36128, is {}",
                    msg.socket_state_counts[11]
                );
                assert_eq!(
                    msg.socket_state_counts[12], 53721,
                    "incorrect value for socket_state_counts[12], expected 53721, is {}",
                    msg.socket_state_counts[12]
                );
                assert_eq!(
                    msg.socket_state_counts[13], 3636,
                    "incorrect value for socket_state_counts[13], expected 3636, is {}",
                    msg.socket_state_counts[13]
                );
                assert_eq!(
                    msg.socket_state_counts[14], 37822,
                    "incorrect value for socket_state_counts[14], expected 37822, is {}",
                    msg.socket_state_counts[14]
                );
                assert_eq!(
                    msg.socket_state_counts[15], 63135,
                    "incorrect value for socket_state_counts[15], expected 63135, is {}",
                    msg.socket_state_counts[15]
                );
                assert_eq!(
                    msg.socket_type_counts[0], 31373,
                    "incorrect value for socket_type_counts[0], expected 31373, is {}",
                    msg.socket_type_counts[0]
                );
                assert_eq!(
                    msg.socket_type_counts[1], 30676,
                    "incorrect value for socket_type_counts[1], expected 30676, is {}",
                    msg.socket_type_counts[1]
                );
                assert_eq!(
                    msg.socket_type_counts[2], 7811,
                    "incorrect value for socket_type_counts[2], expected 7811, is {}",
                    msg.socket_type_counts[2]
                );
                assert_eq!(
                    msg.socket_type_counts[3], 12152,
                    "incorrect value for socket_type_counts[3], expected 12152, is {}",
                    msg.socket_type_counts[3]
                );
                assert_eq!(
                    msg.socket_type_counts[4], 27929,
                    "incorrect value for socket_type_counts[4], expected 27929, is {}",
                    msg.socket_type_counts[4]
                );
                assert_eq!(
                    msg.socket_type_counts[5], 16794,
                    "incorrect value for socket_type_counts[5], expected 16794, is {}",
                    msg.socket_type_counts[5]
                );
                assert_eq!(
                    msg.socket_type_counts[6], 42116,
                    "incorrect value for socket_type_counts[6], expected 42116, is {}",
                    msg.socket_type_counts[6]
                );
                assert_eq!(
                    msg.socket_type_counts[7], 7719,
                    "incorrect value for socket_type_counts[7], expected 7719, is {}",
                    msg.socket_type_counts[7]
                );
                assert_eq!(
                    msg.socket_type_counts[8], 44830,
                    "incorrect value for socket_type_counts[8], expected 44830, is {}",
                    msg.socket_type_counts[8]
                );
                assert_eq!(
                    msg.socket_type_counts[9], 11272,
                    "incorrect value for socket_type_counts[9], expected 11272, is {}",
                    msg.socket_type_counts[9]
                );
                assert_eq!(
                    msg.socket_type_counts[10], 28444,
                    "incorrect value for socket_type_counts[10], expected 28444, is {}",
                    msg.socket_type_counts[10]
                );
                assert_eq!(
                    msg.socket_type_counts[11], 61676,
                    "incorrect value for socket_type_counts[11], expected 61676, is {}",
                    msg.socket_type_counts[11]
                );
                assert_eq!(
                    msg.socket_type_counts[12], 19120,
                    "incorrect value for socket_type_counts[12], expected 19120, is {}",
                    msg.socket_type_counts[12]
                );
                assert_eq!(
                    msg.socket_type_counts[13], 33183,
                    "incorrect value for socket_type_counts[13], expected 33183, is {}",
                    msg.socket_type_counts[13]
                );
                assert_eq!(
                    msg.socket_type_counts[14], 39322,
                    "incorrect value for socket_type_counts[14], expected 39322, is {}",
                    msg.socket_type_counts[14]
                );
                assert_eq!(
                    msg.socket_type_counts[15], 58786,
                    "incorrect value for socket_type_counts[15], expected 58786, is {}",
                    msg.socket_type_counts[15]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxSocketUsage"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_linux_msg_linux_socket_usage`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_linux_msg_linux_socket_usage() {
    {
        let mut payload = Cursor::new(vec![
            85, 5, 127, 114, 138, 72, 13, 196, 69, 173, 67, 222, 186, 181, 246, 154, 251, 17, 224,
            179, 26, 169, 177, 90, 149, 213, 214, 6, 126, 64, 120, 185, 84, 131, 200, 111, 32, 141,
            217, 209, 52, 14, 190, 147, 159, 246, 141, 122, 212, 119, 131, 30, 120, 47, 25, 109,
            154, 65, 132, 164, 39, 30, 30, 175, 8, 44, 28, 111, 236, 240, 176, 74, 159, 129, 154,
            153, 162, 229, 130, 154,
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
        let sbp_msg = sbp::messages::Sbp::MsgLinuxSocketUsage(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgLinuxSocketUsage(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x7f05,
                    "Incorrect message type, expected 0x7f05, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x8a72,
                    "incorrect sender id, expected 0x8a72, is {sender_id}"
                );
                assert_eq!(
                    msg.avg_queue_depth, 2907030541,
                    "incorrect value for avg_queue_depth, expected 2907030541, is {}",
                    msg.avg_queue_depth
                );
                assert_eq!(
                    msg.max_queue_depth, 3048922691,
                    "incorrect value for max_queue_depth, expected 3048922691, is {}",
                    msg.max_queue_depth
                );
                assert_eq!(
                    msg.socket_state_counts[0], 39670,
                    "incorrect value for socket_state_counts[0], expected 39670, is {}",
                    msg.socket_state_counts[0]
                );
                assert_eq!(
                    msg.socket_state_counts[1], 4603,
                    "incorrect value for socket_state_counts[1], expected 4603, is {}",
                    msg.socket_state_counts[1]
                );
                assert_eq!(
                    msg.socket_state_counts[2], 46048,
                    "incorrect value for socket_state_counts[2], expected 46048, is {}",
                    msg.socket_state_counts[2]
                );
                assert_eq!(
                    msg.socket_state_counts[3], 43290,
                    "incorrect value for socket_state_counts[3], expected 43290, is {}",
                    msg.socket_state_counts[3]
                );
                assert_eq!(
                    msg.socket_state_counts[4], 23217,
                    "incorrect value for socket_state_counts[4], expected 23217, is {}",
                    msg.socket_state_counts[4]
                );
                assert_eq!(
                    msg.socket_state_counts[5], 54677,
                    "incorrect value for socket_state_counts[5], expected 54677, is {}",
                    msg.socket_state_counts[5]
                );
                assert_eq!(
                    msg.socket_state_counts[6], 1750,
                    "incorrect value for socket_state_counts[6], expected 1750, is {}",
                    msg.socket_state_counts[6]
                );
                assert_eq!(
                    msg.socket_state_counts[7], 16510,
                    "incorrect value for socket_state_counts[7], expected 16510, is {}",
                    msg.socket_state_counts[7]
                );
                assert_eq!(
                    msg.socket_state_counts[8], 47480,
                    "incorrect value for socket_state_counts[8], expected 47480, is {}",
                    msg.socket_state_counts[8]
                );
                assert_eq!(
                    msg.socket_state_counts[9], 33620,
                    "incorrect value for socket_state_counts[9], expected 33620, is {}",
                    msg.socket_state_counts[9]
                );
                assert_eq!(
                    msg.socket_state_counts[10], 28616,
                    "incorrect value for socket_state_counts[10], expected 28616, is {}",
                    msg.socket_state_counts[10]
                );
                assert_eq!(
                    msg.socket_state_counts[11], 36128,
                    "incorrect value for socket_state_counts[11], expected 36128, is {}",
                    msg.socket_state_counts[11]
                );
                assert_eq!(
                    msg.socket_state_counts[12], 53721,
                    "incorrect value for socket_state_counts[12], expected 53721, is {}",
                    msg.socket_state_counts[12]
                );
                assert_eq!(
                    msg.socket_state_counts[13], 3636,
                    "incorrect value for socket_state_counts[13], expected 3636, is {}",
                    msg.socket_state_counts[13]
                );
                assert_eq!(
                    msg.socket_state_counts[14], 37822,
                    "incorrect value for socket_state_counts[14], expected 37822, is {}",
                    msg.socket_state_counts[14]
                );
                assert_eq!(
                    msg.socket_state_counts[15], 63135,
                    "incorrect value for socket_state_counts[15], expected 63135, is {}",
                    msg.socket_state_counts[15]
                );
                assert_eq!(
                    msg.socket_type_counts[0], 31373,
                    "incorrect value for socket_type_counts[0], expected 31373, is {}",
                    msg.socket_type_counts[0]
                );
                assert_eq!(
                    msg.socket_type_counts[1], 30676,
                    "incorrect value for socket_type_counts[1], expected 30676, is {}",
                    msg.socket_type_counts[1]
                );
                assert_eq!(
                    msg.socket_type_counts[2], 7811,
                    "incorrect value for socket_type_counts[2], expected 7811, is {}",
                    msg.socket_type_counts[2]
                );
                assert_eq!(
                    msg.socket_type_counts[3], 12152,
                    "incorrect value for socket_type_counts[3], expected 12152, is {}",
                    msg.socket_type_counts[3]
                );
                assert_eq!(
                    msg.socket_type_counts[4], 27929,
                    "incorrect value for socket_type_counts[4], expected 27929, is {}",
                    msg.socket_type_counts[4]
                );
                assert_eq!(
                    msg.socket_type_counts[5], 16794,
                    "incorrect value for socket_type_counts[5], expected 16794, is {}",
                    msg.socket_type_counts[5]
                );
                assert_eq!(
                    msg.socket_type_counts[6], 42116,
                    "incorrect value for socket_type_counts[6], expected 42116, is {}",
                    msg.socket_type_counts[6]
                );
                assert_eq!(
                    msg.socket_type_counts[7], 7719,
                    "incorrect value for socket_type_counts[7], expected 7719, is {}",
                    msg.socket_type_counts[7]
                );
                assert_eq!(
                    msg.socket_type_counts[8], 44830,
                    "incorrect value for socket_type_counts[8], expected 44830, is {}",
                    msg.socket_type_counts[8]
                );
                assert_eq!(
                    msg.socket_type_counts[9], 11272,
                    "incorrect value for socket_type_counts[9], expected 11272, is {}",
                    msg.socket_type_counts[9]
                );
                assert_eq!(
                    msg.socket_type_counts[10], 28444,
                    "incorrect value for socket_type_counts[10], expected 28444, is {}",
                    msg.socket_type_counts[10]
                );
                assert_eq!(
                    msg.socket_type_counts[11], 61676,
                    "incorrect value for socket_type_counts[11], expected 61676, is {}",
                    msg.socket_type_counts[11]
                );
                assert_eq!(
                    msg.socket_type_counts[12], 19120,
                    "incorrect value for socket_type_counts[12], expected 19120, is {}",
                    msg.socket_type_counts[12]
                );
                assert_eq!(
                    msg.socket_type_counts[13], 33183,
                    "incorrect value for socket_type_counts[13], expected 33183, is {}",
                    msg.socket_type_counts[13]
                );
                assert_eq!(
                    msg.socket_type_counts[14], 39322,
                    "incorrect value for socket_type_counts[14], expected 39322, is {}",
                    msg.socket_type_counts[14]
                );
                assert_eq!(
                    msg.socket_type_counts[15], 58786,
                    "incorrect value for socket_type_counts[15], expected 58786, is {}",
                    msg.socket_type_counts[15]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgLinuxSocketUsage"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
