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

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
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
                    msg.bitmask, 1234567890,
                    "incorrect value for bitmask, expected 1234567890, is {}",
                    msg.bitmask
                );
                assert_eq!(
                    msg.cols, 32768,
                    "incorrect value for cols, expected 32768, is {}",
                    msg.cols
                );
                assert_eq!(
                    msg.corner_nw_lat, 1024,
                    "incorrect value for corner_nw_lat, expected 1024, is {}",
                    msg.corner_nw_lat
                );
                assert_eq!(
                    msg.corner_nw_lon, 2048,
                    "incorrect value for corner_nw_lon, expected 2048, is {}",
                    msg.corner_nw_lon
                );
                assert_eq!(
                    msg.rows, 16384,
                    "incorrect value for rows, expected 16384, is {}",
                    msg.rows
                );
                assert_eq!(
                    msg.spacing_lat, 4096,
                    "incorrect value for spacing_lat, expected 4096, is {}",
                    msg.spacing_lat
                );
                assert_eq!(
                    msg.spacing_lon, 8192,
                    "incorrect value for spacing_lon, expected 8192, is {}",
                    msg.spacing_lon
                );
                assert_eq!(
                    msg.ssr_sol_id, 31,
                    "incorrect value for ssr_sol_id, expected 31, is {}",
                    msg.ssr_sol_id
                );
                assert_eq!(
                    msg.tile_id, 512,
                    "incorrect value for tile_id, expected 512, is {}",
                    msg.tile_id
                );
                assert_eq!(
                    msg.tile_set_id, 256,
                    "incorrect value for tile_set_id, expected 256, is {}",
                    msg.tile_set_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrTileDefinition"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_tile_definition() {
    {
        let json_input = r#"{"ssr_sol_id": 31, "tile_set_id": 256, "tile_id": 512, "corner_nw_lat": 1024, "corner_nw_lon": 2048, "spacing_lat": 4096, "spacing_lon": 8192, "rows": 16384, "cols": 32768, "bitmask": 1234567890, "preamble": 85, "msg_type": 1527, "sender": 66, "length": 25, "payload": "HwABAAIABAAIABAAIABAAIDSApZJAAAAAA==", "crc": 18390}"#.as_bytes();

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
                    msg.bitmask, 1234567890,
                    "incorrect value for bitmask, expected 1234567890, is {}",
                    msg.bitmask
                );
                assert_eq!(
                    msg.cols, 32768,
                    "incorrect value for cols, expected 32768, is {}",
                    msg.cols
                );
                assert_eq!(
                    msg.corner_nw_lat, 1024,
                    "incorrect value for corner_nw_lat, expected 1024, is {}",
                    msg.corner_nw_lat
                );
                assert_eq!(
                    msg.corner_nw_lon, 2048,
                    "incorrect value for corner_nw_lon, expected 2048, is {}",
                    msg.corner_nw_lon
                );
                assert_eq!(
                    msg.rows, 16384,
                    "incorrect value for rows, expected 16384, is {}",
                    msg.rows
                );
                assert_eq!(
                    msg.spacing_lat, 4096,
                    "incorrect value for spacing_lat, expected 4096, is {}",
                    msg.spacing_lat
                );
                assert_eq!(
                    msg.spacing_lon, 8192,
                    "incorrect value for spacing_lon, expected 8192, is {}",
                    msg.spacing_lon
                );
                assert_eq!(
                    msg.ssr_sol_id, 31,
                    "incorrect value for ssr_sol_id, expected 31, is {}",
                    msg.ssr_sol_id
                );
                assert_eq!(
                    msg.tile_id, 512,
                    "incorrect value for tile_id, expected 512, is {}",
                    msg.tile_id
                );
                assert_eq!(
                    msg.tile_set_id, 256,
                    "incorrect value for tile_set_id, expected 256, is {}",
                    msg.tile_set_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrTileDefinition"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_tile_definition`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_tile_definition() {
    {
        let mut payload = Cursor::new(vec![
            85, 247, 5, 66, 0, 25, 31, 0, 1, 0, 2, 0, 4, 0, 8, 0, 16, 0, 32, 0, 64, 0, 128, 210, 2,
            150, 73, 0, 0, 0, 0, 214, 71,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrTileDefinition(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
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
                    msg.bitmask, 1234567890,
                    "incorrect value for bitmask, expected 1234567890, is {}",
                    msg.bitmask
                );
                assert_eq!(
                    msg.cols, 32768,
                    "incorrect value for cols, expected 32768, is {}",
                    msg.cols
                );
                assert_eq!(
                    msg.corner_nw_lat, 1024,
                    "incorrect value for corner_nw_lat, expected 1024, is {}",
                    msg.corner_nw_lat
                );
                assert_eq!(
                    msg.corner_nw_lon, 2048,
                    "incorrect value for corner_nw_lon, expected 2048, is {}",
                    msg.corner_nw_lon
                );
                assert_eq!(
                    msg.rows, 16384,
                    "incorrect value for rows, expected 16384, is {}",
                    msg.rows
                );
                assert_eq!(
                    msg.spacing_lat, 4096,
                    "incorrect value for spacing_lat, expected 4096, is {}",
                    msg.spacing_lat
                );
                assert_eq!(
                    msg.spacing_lon, 8192,
                    "incorrect value for spacing_lon, expected 8192, is {}",
                    msg.spacing_lon
                );
                assert_eq!(
                    msg.ssr_sol_id, 31,
                    "incorrect value for ssr_sol_id, expected 31, is {}",
                    msg.ssr_sol_id
                );
                assert_eq!(
                    msg.tile_id, 512,
                    "incorrect value for tile_id, expected 512, is {}",
                    msg.tile_id
                );
                assert_eq!(
                    msg.tile_set_id, 256,
                    "incorrect value for tile_set_id, expected 256, is {}",
                    msg.tile_set_id
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrTileDefinition"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
