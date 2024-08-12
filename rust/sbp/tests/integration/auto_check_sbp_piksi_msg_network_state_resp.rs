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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgNetworkStateResp.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_piksi_msg_network_state_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 187, 0, 40, 15, 50, 143, 241, 84, 180, 152, 194, 137, 32, 44, 114, 147, 68, 222,
            92, 192, 78, 235, 63, 208, 114, 53, 183, 24, 244, 231, 26, 105, 25, 136, 3, 105, 102,
            48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 195, 229, 80, 147, 118, 193,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgNetworkStateResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xbb,
                    "Incorrect message type, expected 0xbb, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0f28,
                    "incorrect sender id, expected 0x0f28, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 2471552451,
                    "incorrect value for flags, expected 2471552451, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.interface_name.as_bytes(),
                    &[105, 102, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.interface_name, expected string '{:?}', is '{:?}'",
                    &[105, 102, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.interface_name.as_bytes()
                );
                assert_eq!(
                    msg.ipv4_address[0], 143,
                    "incorrect value for ipv4_address[0], expected 143, is {}",
                    msg.ipv4_address[0]
                );
                assert_eq!(
                    msg.ipv4_address[1], 241,
                    "incorrect value for ipv4_address[1], expected 241, is {}",
                    msg.ipv4_address[1]
                );
                assert_eq!(
                    msg.ipv4_address[2], 84,
                    "incorrect value for ipv4_address[2], expected 84, is {}",
                    msg.ipv4_address[2]
                );
                assert_eq!(
                    msg.ipv4_address[3], 180,
                    "incorrect value for ipv4_address[3], expected 180, is {}",
                    msg.ipv4_address[3]
                );
                assert_eq!(
                    msg.ipv4_mask_size, 152,
                    "incorrect value for ipv4_mask_size, expected 152, is {}",
                    msg.ipv4_mask_size
                );
                assert_eq!(
                    msg.ipv6_address[0], 194,
                    "incorrect value for ipv6_address[0], expected 194, is {}",
                    msg.ipv6_address[0]
                );
                assert_eq!(
                    msg.ipv6_address[1], 137,
                    "incorrect value for ipv6_address[1], expected 137, is {}",
                    msg.ipv6_address[1]
                );
                assert_eq!(
                    msg.ipv6_address[2], 32,
                    "incorrect value for ipv6_address[2], expected 32, is {}",
                    msg.ipv6_address[2]
                );
                assert_eq!(
                    msg.ipv6_address[3], 44,
                    "incorrect value for ipv6_address[3], expected 44, is {}",
                    msg.ipv6_address[3]
                );
                assert_eq!(
                    msg.ipv6_address[4], 114,
                    "incorrect value for ipv6_address[4], expected 114, is {}",
                    msg.ipv6_address[4]
                );
                assert_eq!(
                    msg.ipv6_address[5], 147,
                    "incorrect value for ipv6_address[5], expected 147, is {}",
                    msg.ipv6_address[5]
                );
                assert_eq!(
                    msg.ipv6_address[6], 68,
                    "incorrect value for ipv6_address[6], expected 68, is {}",
                    msg.ipv6_address[6]
                );
                assert_eq!(
                    msg.ipv6_address[7], 222,
                    "incorrect value for ipv6_address[7], expected 222, is {}",
                    msg.ipv6_address[7]
                );
                assert_eq!(
                    msg.ipv6_address[8], 92,
                    "incorrect value for ipv6_address[8], expected 92, is {}",
                    msg.ipv6_address[8]
                );
                assert_eq!(
                    msg.ipv6_address[9], 192,
                    "incorrect value for ipv6_address[9], expected 192, is {}",
                    msg.ipv6_address[9]
                );
                assert_eq!(
                    msg.ipv6_address[10], 78,
                    "incorrect value for ipv6_address[10], expected 78, is {}",
                    msg.ipv6_address[10]
                );
                assert_eq!(
                    msg.ipv6_address[11], 235,
                    "incorrect value for ipv6_address[11], expected 235, is {}",
                    msg.ipv6_address[11]
                );
                assert_eq!(
                    msg.ipv6_address[12], 63,
                    "incorrect value for ipv6_address[12], expected 63, is {}",
                    msg.ipv6_address[12]
                );
                assert_eq!(
                    msg.ipv6_address[13], 208,
                    "incorrect value for ipv6_address[13], expected 208, is {}",
                    msg.ipv6_address[13]
                );
                assert_eq!(
                    msg.ipv6_address[14], 114,
                    "incorrect value for ipv6_address[14], expected 114, is {}",
                    msg.ipv6_address[14]
                );
                assert_eq!(
                    msg.ipv6_address[15], 53,
                    "incorrect value for ipv6_address[15], expected 53, is {}",
                    msg.ipv6_address[15]
                );
                assert_eq!(
                    msg.ipv6_mask_size, 183,
                    "incorrect value for ipv6_mask_size, expected 183, is {}",
                    msg.ipv6_mask_size
                );
                assert_eq!(
                    msg.rx_bytes, 451408920,
                    "incorrect value for rx_bytes, expected 451408920, is {}",
                    msg.rx_bytes
                );
                assert_eq!(
                    msg.tx_bytes, 59251049,
                    "incorrect value for tx_bytes, expected 59251049, is {}",
                    msg.tx_bytes
                );
            }
            _ => panic!("Invalid message type! Expected a MsgNetworkStateResp"),
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
fn test_json2sbp_auto_check_sbp_piksi_msg_network_state_resp() {
    {
        let json_input = r#"{"crc":49526,"length":50,"msg_type":187,"payload":"j/FUtJjCiSAscpNE3lzATus/0HI1txj05xppGYgDaWYwAAAAAAAAAAAAAAAAAMPlUJM=","preamble":85,"sender":3880,"ipv4_address":[143,241,84,180],"ipv4_mask_size":152,"ipv6_address":[194,137,32,44,114,147,68,222,92,192,78,235,63,208,114,53],"ipv6_mask_size":183,"rx_bytes":451408920,"tx_bytes":59251049,"interface_name":"if0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","flags":2471552451}"#.as_bytes();

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
            sbp::messages::Sbp::MsgNetworkStateResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xbb,
                    "Incorrect message type, expected 0xbb, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0f28,
                    "incorrect sender id, expected 0x0f28, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 2471552451,
                    "incorrect value for flags, expected 2471552451, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.interface_name.as_bytes(),
                    &[105, 102, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.interface_name, expected string '{:?}', is '{:?}'",
                    &[105, 102, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.interface_name.as_bytes()
                );
                assert_eq!(
                    msg.ipv4_address[0], 143,
                    "incorrect value for ipv4_address[0], expected 143, is {}",
                    msg.ipv4_address[0]
                );
                assert_eq!(
                    msg.ipv4_address[1], 241,
                    "incorrect value for ipv4_address[1], expected 241, is {}",
                    msg.ipv4_address[1]
                );
                assert_eq!(
                    msg.ipv4_address[2], 84,
                    "incorrect value for ipv4_address[2], expected 84, is {}",
                    msg.ipv4_address[2]
                );
                assert_eq!(
                    msg.ipv4_address[3], 180,
                    "incorrect value for ipv4_address[3], expected 180, is {}",
                    msg.ipv4_address[3]
                );
                assert_eq!(
                    msg.ipv4_mask_size, 152,
                    "incorrect value for ipv4_mask_size, expected 152, is {}",
                    msg.ipv4_mask_size
                );
                assert_eq!(
                    msg.ipv6_address[0], 194,
                    "incorrect value for ipv6_address[0], expected 194, is {}",
                    msg.ipv6_address[0]
                );
                assert_eq!(
                    msg.ipv6_address[1], 137,
                    "incorrect value for ipv6_address[1], expected 137, is {}",
                    msg.ipv6_address[1]
                );
                assert_eq!(
                    msg.ipv6_address[2], 32,
                    "incorrect value for ipv6_address[2], expected 32, is {}",
                    msg.ipv6_address[2]
                );
                assert_eq!(
                    msg.ipv6_address[3], 44,
                    "incorrect value for ipv6_address[3], expected 44, is {}",
                    msg.ipv6_address[3]
                );
                assert_eq!(
                    msg.ipv6_address[4], 114,
                    "incorrect value for ipv6_address[4], expected 114, is {}",
                    msg.ipv6_address[4]
                );
                assert_eq!(
                    msg.ipv6_address[5], 147,
                    "incorrect value for ipv6_address[5], expected 147, is {}",
                    msg.ipv6_address[5]
                );
                assert_eq!(
                    msg.ipv6_address[6], 68,
                    "incorrect value for ipv6_address[6], expected 68, is {}",
                    msg.ipv6_address[6]
                );
                assert_eq!(
                    msg.ipv6_address[7], 222,
                    "incorrect value for ipv6_address[7], expected 222, is {}",
                    msg.ipv6_address[7]
                );
                assert_eq!(
                    msg.ipv6_address[8], 92,
                    "incorrect value for ipv6_address[8], expected 92, is {}",
                    msg.ipv6_address[8]
                );
                assert_eq!(
                    msg.ipv6_address[9], 192,
                    "incorrect value for ipv6_address[9], expected 192, is {}",
                    msg.ipv6_address[9]
                );
                assert_eq!(
                    msg.ipv6_address[10], 78,
                    "incorrect value for ipv6_address[10], expected 78, is {}",
                    msg.ipv6_address[10]
                );
                assert_eq!(
                    msg.ipv6_address[11], 235,
                    "incorrect value for ipv6_address[11], expected 235, is {}",
                    msg.ipv6_address[11]
                );
                assert_eq!(
                    msg.ipv6_address[12], 63,
                    "incorrect value for ipv6_address[12], expected 63, is {}",
                    msg.ipv6_address[12]
                );
                assert_eq!(
                    msg.ipv6_address[13], 208,
                    "incorrect value for ipv6_address[13], expected 208, is {}",
                    msg.ipv6_address[13]
                );
                assert_eq!(
                    msg.ipv6_address[14], 114,
                    "incorrect value for ipv6_address[14], expected 114, is {}",
                    msg.ipv6_address[14]
                );
                assert_eq!(
                    msg.ipv6_address[15], 53,
                    "incorrect value for ipv6_address[15], expected 53, is {}",
                    msg.ipv6_address[15]
                );
                assert_eq!(
                    msg.ipv6_mask_size, 183,
                    "incorrect value for ipv6_mask_size, expected 183, is {}",
                    msg.ipv6_mask_size
                );
                assert_eq!(
                    msg.rx_bytes, 451408920,
                    "incorrect value for rx_bytes, expected 451408920, is {}",
                    msg.rx_bytes
                );
                assert_eq!(
                    msg.tx_bytes, 59251049,
                    "incorrect value for tx_bytes, expected 59251049, is {}",
                    msg.tx_bytes
                );
            }
            _ => panic!("Invalid message type! Expected a MsgNetworkStateResp"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_piksi_msg_network_state_resp`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_piksi_msg_network_state_resp() {
    {
        let mut payload = Cursor::new(vec![
            85, 187, 0, 40, 15, 50, 143, 241, 84, 180, 152, 194, 137, 32, 44, 114, 147, 68, 222,
            92, 192, 78, 235, 63, 208, 114, 53, 183, 24, 244, 231, 26, 105, 25, 136, 3, 105, 102,
            48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 195, 229, 80, 147, 118, 193,
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
        let sbp_msg = sbp::messages::Sbp::MsgNetworkStateResp(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgNetworkStateResp(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xbb,
                    "Incorrect message type, expected 0xbb, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0f28,
                    "incorrect sender id, expected 0x0f28, is {sender_id}"
                );
                assert_eq!(
                    msg.flags, 2471552451,
                    "incorrect value for flags, expected 2471552451, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.interface_name.as_bytes(),
                    &[105, 102, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.interface_name, expected string '{:?}', is '{:?}'",
                    &[105, 102, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.interface_name.as_bytes()
                );
                assert_eq!(
                    msg.ipv4_address[0], 143,
                    "incorrect value for ipv4_address[0], expected 143, is {}",
                    msg.ipv4_address[0]
                );
                assert_eq!(
                    msg.ipv4_address[1], 241,
                    "incorrect value for ipv4_address[1], expected 241, is {}",
                    msg.ipv4_address[1]
                );
                assert_eq!(
                    msg.ipv4_address[2], 84,
                    "incorrect value for ipv4_address[2], expected 84, is {}",
                    msg.ipv4_address[2]
                );
                assert_eq!(
                    msg.ipv4_address[3], 180,
                    "incorrect value for ipv4_address[3], expected 180, is {}",
                    msg.ipv4_address[3]
                );
                assert_eq!(
                    msg.ipv4_mask_size, 152,
                    "incorrect value for ipv4_mask_size, expected 152, is {}",
                    msg.ipv4_mask_size
                );
                assert_eq!(
                    msg.ipv6_address[0], 194,
                    "incorrect value for ipv6_address[0], expected 194, is {}",
                    msg.ipv6_address[0]
                );
                assert_eq!(
                    msg.ipv6_address[1], 137,
                    "incorrect value for ipv6_address[1], expected 137, is {}",
                    msg.ipv6_address[1]
                );
                assert_eq!(
                    msg.ipv6_address[2], 32,
                    "incorrect value for ipv6_address[2], expected 32, is {}",
                    msg.ipv6_address[2]
                );
                assert_eq!(
                    msg.ipv6_address[3], 44,
                    "incorrect value for ipv6_address[3], expected 44, is {}",
                    msg.ipv6_address[3]
                );
                assert_eq!(
                    msg.ipv6_address[4], 114,
                    "incorrect value for ipv6_address[4], expected 114, is {}",
                    msg.ipv6_address[4]
                );
                assert_eq!(
                    msg.ipv6_address[5], 147,
                    "incorrect value for ipv6_address[5], expected 147, is {}",
                    msg.ipv6_address[5]
                );
                assert_eq!(
                    msg.ipv6_address[6], 68,
                    "incorrect value for ipv6_address[6], expected 68, is {}",
                    msg.ipv6_address[6]
                );
                assert_eq!(
                    msg.ipv6_address[7], 222,
                    "incorrect value for ipv6_address[7], expected 222, is {}",
                    msg.ipv6_address[7]
                );
                assert_eq!(
                    msg.ipv6_address[8], 92,
                    "incorrect value for ipv6_address[8], expected 92, is {}",
                    msg.ipv6_address[8]
                );
                assert_eq!(
                    msg.ipv6_address[9], 192,
                    "incorrect value for ipv6_address[9], expected 192, is {}",
                    msg.ipv6_address[9]
                );
                assert_eq!(
                    msg.ipv6_address[10], 78,
                    "incorrect value for ipv6_address[10], expected 78, is {}",
                    msg.ipv6_address[10]
                );
                assert_eq!(
                    msg.ipv6_address[11], 235,
                    "incorrect value for ipv6_address[11], expected 235, is {}",
                    msg.ipv6_address[11]
                );
                assert_eq!(
                    msg.ipv6_address[12], 63,
                    "incorrect value for ipv6_address[12], expected 63, is {}",
                    msg.ipv6_address[12]
                );
                assert_eq!(
                    msg.ipv6_address[13], 208,
                    "incorrect value for ipv6_address[13], expected 208, is {}",
                    msg.ipv6_address[13]
                );
                assert_eq!(
                    msg.ipv6_address[14], 114,
                    "incorrect value for ipv6_address[14], expected 114, is {}",
                    msg.ipv6_address[14]
                );
                assert_eq!(
                    msg.ipv6_address[15], 53,
                    "incorrect value for ipv6_address[15], expected 53, is {}",
                    msg.ipv6_address[15]
                );
                assert_eq!(
                    msg.ipv6_mask_size, 183,
                    "incorrect value for ipv6_mask_size, expected 183, is {}",
                    msg.ipv6_mask_size
                );
                assert_eq!(
                    msg.rx_bytes, 451408920,
                    "incorrect value for rx_bytes, expected 451408920, is {}",
                    msg.rx_bytes
                );
                assert_eq!(
                    msg.tx_bytes, 59251049,
                    "incorrect value for tx_bytes, expected 59251049, is {}",
                    msg.tx_bytes
                );
            }
            _ => panic!("Invalid message type! Expected a MsgNetworkStateResp"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
