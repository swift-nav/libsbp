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
            85, 248, 5, 0, 0, 33, 127, 58, 9, 0, 174, 8, 1, 2, 3, 4, 0, 5, 0, 186, 28, 59, 167,
            100, 0, 100, 0, 6, 0, 6, 0, 210, 2, 150, 73, 0, 0, 0, 0, 204, 94,
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
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5F8,
                    "Incorrect message type, expected 0x5F8, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0,
                    "incorrect sender id, expected 0x0, is {sender_id}"
                );
                assert_eq!(
                    msg.bitmask, 1234567890,
                    "incorrect value for bitmask, expected 1234567890, is {}",
                    msg.bitmask
                );
                assert_eq!(
                    msg.cols, 6,
                    "incorrect value for cols, expected 6, is {}",
                    msg.cols
                );
                assert_eq!(
                    msg.corner_nw_lat, 7354,
                    "incorrect value for corner_nw_lat, expected 7354, is {}",
                    msg.corner_nw_lat
                );
                assert_eq!(
                    msg.corner_nw_lon, -22725,
                    "incorrect value for corner_nw_lon, expected -22725, is {}",
                    msg.corner_nw_lon
                );
                assert_eq!(
                    msg.iod_atmo, 3,
                    "incorrect value for iod_atmo, expected 3, is {}",
                    msg.iod_atmo
                );
                assert_eq!(
                    msg.rows, 6,
                    "incorrect value for rows, expected 6, is {}",
                    msg.rows
                );
                assert_eq!(
                    msg.sol_id, 2,
                    "incorrect value for sol_id, expected 2, is {}",
                    msg.sol_id
                );
                assert_eq!(
                    msg.spacing_lat, 100,
                    "incorrect value for spacing_lat, expected 100, is {}",
                    msg.spacing_lat
                );
                assert_eq!(
                    msg.spacing_lon, 100,
                    "incorrect value for spacing_lon, expected 100, is {}",
                    msg.spacing_lon
                );
                assert_eq!(
                    msg.tile_id, 5,
                    "incorrect value for tile_id, expected 5, is {}",
                    msg.tile_id
                );
                assert_eq!(
                    msg.tile_set_id, 4,
                    "incorrect value for tile_set_id, expected 4, is {}",
                    msg.tile_set_id
                );
                assert_eq!(
                    msg.time.tow, 604799,
                    "incorrect value for time.tow, expected 604799, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 2222,
                    "incorrect value for time.wn, expected 2222, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 1,
                    "incorrect value for update_interval, expected 1, is {}",
                    msg.update_interval
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
        let json_input = r#"{"preamble": 85, "msg_type": 1528, "sender": 0, "length": 33, "payload": "fzoJAK4IAQIDBAAFALocO6dkAGQABgAGANIClkkAAAAA", "crc": 24268, "time": {"tow": 604799, "wn": 2222}, "update_interval": 1, "sol_id": 2, "iod_atmo": 3, "tile_set_id": 4, "tile_id": 5, "corner_nw_lat": 7354, "corner_nw_lon": -22725, "spacing_lat": 100, "spacing_lon": 100, "rows": 6, "cols": 6, "bitmask": 1234567890}"#.as_bytes();

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
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5F8,
                    "Incorrect message type, expected 0x5F8, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0,
                    "incorrect sender id, expected 0x0, is {sender_id}"
                );
                assert_eq!(
                    msg.bitmask, 1234567890,
                    "incorrect value for bitmask, expected 1234567890, is {}",
                    msg.bitmask
                );
                assert_eq!(
                    msg.cols, 6,
                    "incorrect value for cols, expected 6, is {}",
                    msg.cols
                );
                assert_eq!(
                    msg.corner_nw_lat, 7354,
                    "incorrect value for corner_nw_lat, expected 7354, is {}",
                    msg.corner_nw_lat
                );
                assert_eq!(
                    msg.corner_nw_lon, -22725,
                    "incorrect value for corner_nw_lon, expected -22725, is {}",
                    msg.corner_nw_lon
                );
                assert_eq!(
                    msg.iod_atmo, 3,
                    "incorrect value for iod_atmo, expected 3, is {}",
                    msg.iod_atmo
                );
                assert_eq!(
                    msg.rows, 6,
                    "incorrect value for rows, expected 6, is {}",
                    msg.rows
                );
                assert_eq!(
                    msg.sol_id, 2,
                    "incorrect value for sol_id, expected 2, is {}",
                    msg.sol_id
                );
                assert_eq!(
                    msg.spacing_lat, 100,
                    "incorrect value for spacing_lat, expected 100, is {}",
                    msg.spacing_lat
                );
                assert_eq!(
                    msg.spacing_lon, 100,
                    "incorrect value for spacing_lon, expected 100, is {}",
                    msg.spacing_lon
                );
                assert_eq!(
                    msg.tile_id, 5,
                    "incorrect value for tile_id, expected 5, is {}",
                    msg.tile_id
                );
                assert_eq!(
                    msg.tile_set_id, 4,
                    "incorrect value for tile_set_id, expected 4, is {}",
                    msg.tile_set_id
                );
                assert_eq!(
                    msg.time.tow, 604799,
                    "incorrect value for time.tow, expected 604799, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 2222,
                    "incorrect value for time.wn, expected 2222, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 1,
                    "incorrect value for update_interval, expected 1, is {}",
                    msg.update_interval
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
            85, 248, 5, 0, 0, 33, 127, 58, 9, 0, 174, 8, 1, 2, 3, 4, 0, 5, 0, 186, 28, 59, 167,
            100, 0, 100, 0, 6, 0, 6, 0, 210, 2, 150, 73, 0, 0, 0, 0, 204, 94,
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
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5F8,
                    "Incorrect message type, expected 0x5F8, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0,
                    "incorrect sender id, expected 0x0, is {sender_id}"
                );
                assert_eq!(
                    msg.bitmask, 1234567890,
                    "incorrect value for bitmask, expected 1234567890, is {}",
                    msg.bitmask
                );
                assert_eq!(
                    msg.cols, 6,
                    "incorrect value for cols, expected 6, is {}",
                    msg.cols
                );
                assert_eq!(
                    msg.corner_nw_lat, 7354,
                    "incorrect value for corner_nw_lat, expected 7354, is {}",
                    msg.corner_nw_lat
                );
                assert_eq!(
                    msg.corner_nw_lon, -22725,
                    "incorrect value for corner_nw_lon, expected -22725, is {}",
                    msg.corner_nw_lon
                );
                assert_eq!(
                    msg.iod_atmo, 3,
                    "incorrect value for iod_atmo, expected 3, is {}",
                    msg.iod_atmo
                );
                assert_eq!(
                    msg.rows, 6,
                    "incorrect value for rows, expected 6, is {}",
                    msg.rows
                );
                assert_eq!(
                    msg.sol_id, 2,
                    "incorrect value for sol_id, expected 2, is {}",
                    msg.sol_id
                );
                assert_eq!(
                    msg.spacing_lat, 100,
                    "incorrect value for spacing_lat, expected 100, is {}",
                    msg.spacing_lat
                );
                assert_eq!(
                    msg.spacing_lon, 100,
                    "incorrect value for spacing_lon, expected 100, is {}",
                    msg.spacing_lon
                );
                assert_eq!(
                    msg.tile_id, 5,
                    "incorrect value for tile_id, expected 5, is {}",
                    msg.tile_id
                );
                assert_eq!(
                    msg.tile_set_id, 4,
                    "incorrect value for tile_set_id, expected 4, is {}",
                    msg.tile_set_id
                );
                assert_eq!(
                    msg.time.tow, 604799,
                    "incorrect value for time.tow, expected 604799, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 2222,
                    "incorrect value for time.wn, expected 2222, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 1,
                    "incorrect value for update_interval, expected 1, is {}",
                    msg.update_interval
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrTileDefinition"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
