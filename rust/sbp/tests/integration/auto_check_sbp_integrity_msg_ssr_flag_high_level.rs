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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagHighLevel.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_integrity_msg_ssr_flag_high_level() {
    {
        let mut payload = Cursor::new(vec![
            85, 185, 11, 66, 0, 31, 180, 0, 0, 0, 3, 0, 104, 1, 0, 0, 6, 0, 10, 20, 0, 30, 0, 40,
            1, 2, 3, 0, 0, 0, 0, 0, 0, 4, 5, 6, 7, 102, 67,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrFlagHighLevel(msg) => {
                assert_eq!(
                    msg.message_type(),
                    3001,
                    "Incorrect message type, expected 3001, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.chain_id, 40,
                    "incorrect value for chain_id, expected 40, is {}",
                    msg.chain_id
                );
                assert_eq!(
                    msg.corr_time.tow, 360,
                    "incorrect value for corr_time.tow, expected 360, is {}",
                    msg.corr_time.tow
                );
                assert_eq!(
                    msg.corr_time.wn, 6,
                    "incorrect value for corr_time.wn, expected 6, is {}",
                    msg.corr_time.wn
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
                    msg.reserved[0], 0,
                    "incorrect value for reserved[0], expected 0, is {}",
                    msg.reserved[0]
                );
                assert_eq!(
                    msg.reserved[1], 0,
                    "incorrect value for reserved[1], expected 0, is {}",
                    msg.reserved[1]
                );
                assert_eq!(
                    msg.reserved[2], 0,
                    "incorrect value for reserved[2], expected 0, is {}",
                    msg.reserved[2]
                );
                assert_eq!(
                    msg.reserved[3], 0,
                    "incorrect value for reserved[3], expected 0, is {}",
                    msg.reserved[3]
                );
                assert_eq!(
                    msg.reserved[4], 0,
                    "incorrect value for reserved[4], expected 0, is {}",
                    msg.reserved[4]
                );
                assert_eq!(
                    msg.reserved[5], 0,
                    "incorrect value for reserved[5], expected 0, is {}",
                    msg.reserved[5]
                );
                assert_eq!(
                    msg.ssr_sol_id, 10,
                    "incorrect value for ssr_sol_id, expected 10, is {}",
                    msg.ssr_sol_id
                );
                assert_eq!(
                    msg.tile_id, 30,
                    "incorrect value for tile_id, expected 30, is {}",
                    msg.tile_id
                );
                assert_eq!(
                    msg.tile_set_id, 20,
                    "incorrect value for tile_set_id, expected 20, is {}",
                    msg.tile_set_id
                );
                assert_eq!(
                    msg.use_bds_sat, 3,
                    "incorrect value for use_bds_sat, expected 3, is {}",
                    msg.use_bds_sat
                );
                assert_eq!(
                    msg.use_gal_sat, 2,
                    "incorrect value for use_gal_sat, expected 2, is {}",
                    msg.use_gal_sat
                );
                assert_eq!(
                    msg.use_gps_sat, 1,
                    "incorrect value for use_gps_sat, expected 1, is {}",
                    msg.use_gps_sat
                );
                assert_eq!(
                    msg.use_iono_grid_point_sat_los, 7,
                    "incorrect value for use_iono_grid_point_sat_los, expected 7, is {}",
                    msg.use_iono_grid_point_sat_los
                );
                assert_eq!(
                    msg.use_iono_grid_points, 5,
                    "incorrect value for use_iono_grid_points, expected 5, is {}",
                    msg.use_iono_grid_points
                );
                assert_eq!(
                    msg.use_iono_tile_sat_los, 6,
                    "incorrect value for use_iono_tile_sat_los, expected 6, is {}",
                    msg.use_iono_tile_sat_los
                );
                assert_eq!(
                    msg.use_tropo_grid_points, 4,
                    "incorrect value for use_tropo_grid_points, expected 4, is {}",
                    msg.use_tropo_grid_points
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrFlagHighLevel"),
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
fn test_json2sbp_auto_check_sbp_integrity_msg_ssr_flag_high_level() {
    {
        let json_input = r#"{"obs_time": {"tow": 180, "wn": 3}, "corr_time": {"tow": 360, "wn": 6}, "ssr_sol_id": 10, "tile_set_id": 20, "tile_id": 30, "chain_id": 40, "use_gps_sat": 1, "use_gal_sat": 2, "use_bds_sat": 3, "reserved": [0,0,0,0,0,0], "use_tropo_grid_points": 4, "use_iono_grid_points": 5, "use_iono_tile_sat_los": 6, "use_iono_grid_point_sat_los": 7, "preamble": 85, "msg_type": 3001, "sender": 66, "length": 31, "payload": "tAAAAAMAaAEAAAYAChQAHgAoAQIDAAAAAAAABAUGBw==", "crc": 17254}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrFlagHighLevel(msg) => {
                assert_eq!(
                    msg.message_type(),
                    3001,
                    "Incorrect message type, expected 3001, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.chain_id, 40,
                    "incorrect value for chain_id, expected 40, is {}",
                    msg.chain_id
                );
                assert_eq!(
                    msg.corr_time.tow, 360,
                    "incorrect value for corr_time.tow, expected 360, is {}",
                    msg.corr_time.tow
                );
                assert_eq!(
                    msg.corr_time.wn, 6,
                    "incorrect value for corr_time.wn, expected 6, is {}",
                    msg.corr_time.wn
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
                    msg.reserved[0], 0,
                    "incorrect value for reserved[0], expected 0, is {}",
                    msg.reserved[0]
                );
                assert_eq!(
                    msg.reserved[1], 0,
                    "incorrect value for reserved[1], expected 0, is {}",
                    msg.reserved[1]
                );
                assert_eq!(
                    msg.reserved[2], 0,
                    "incorrect value for reserved[2], expected 0, is {}",
                    msg.reserved[2]
                );
                assert_eq!(
                    msg.reserved[3], 0,
                    "incorrect value for reserved[3], expected 0, is {}",
                    msg.reserved[3]
                );
                assert_eq!(
                    msg.reserved[4], 0,
                    "incorrect value for reserved[4], expected 0, is {}",
                    msg.reserved[4]
                );
                assert_eq!(
                    msg.reserved[5], 0,
                    "incorrect value for reserved[5], expected 0, is {}",
                    msg.reserved[5]
                );
                assert_eq!(
                    msg.ssr_sol_id, 10,
                    "incorrect value for ssr_sol_id, expected 10, is {}",
                    msg.ssr_sol_id
                );
                assert_eq!(
                    msg.tile_id, 30,
                    "incorrect value for tile_id, expected 30, is {}",
                    msg.tile_id
                );
                assert_eq!(
                    msg.tile_set_id, 20,
                    "incorrect value for tile_set_id, expected 20, is {}",
                    msg.tile_set_id
                );
                assert_eq!(
                    msg.use_bds_sat, 3,
                    "incorrect value for use_bds_sat, expected 3, is {}",
                    msg.use_bds_sat
                );
                assert_eq!(
                    msg.use_gal_sat, 2,
                    "incorrect value for use_gal_sat, expected 2, is {}",
                    msg.use_gal_sat
                );
                assert_eq!(
                    msg.use_gps_sat, 1,
                    "incorrect value for use_gps_sat, expected 1, is {}",
                    msg.use_gps_sat
                );
                assert_eq!(
                    msg.use_iono_grid_point_sat_los, 7,
                    "incorrect value for use_iono_grid_point_sat_los, expected 7, is {}",
                    msg.use_iono_grid_point_sat_los
                );
                assert_eq!(
                    msg.use_iono_grid_points, 5,
                    "incorrect value for use_iono_grid_points, expected 5, is {}",
                    msg.use_iono_grid_points
                );
                assert_eq!(
                    msg.use_iono_tile_sat_los, 6,
                    "incorrect value for use_iono_tile_sat_los, expected 6, is {}",
                    msg.use_iono_tile_sat_los
                );
                assert_eq!(
                    msg.use_tropo_grid_points, 4,
                    "incorrect value for use_tropo_grid_points, expected 4, is {}",
                    msg.use_tropo_grid_points
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrFlagHighLevel"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_integrity_msg_ssr_flag_high_level`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_integrity_msg_ssr_flag_high_level() {
    {
        let mut payload = Cursor::new(vec![
            85, 185, 11, 66, 0, 31, 180, 0, 0, 0, 3, 0, 104, 1, 0, 0, 6, 0, 10, 20, 0, 30, 0, 40,
            1, 2, 3, 0, 0, 0, 0, 0, 0, 4, 5, 6, 7, 102, 67,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrFlagHighLevel(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrFlagHighLevel(msg) => {
                assert_eq!(
                    msg.message_type(),
                    3001,
                    "Incorrect message type, expected 3001, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.chain_id, 40,
                    "incorrect value for chain_id, expected 40, is {}",
                    msg.chain_id
                );
                assert_eq!(
                    msg.corr_time.tow, 360,
                    "incorrect value for corr_time.tow, expected 360, is {}",
                    msg.corr_time.tow
                );
                assert_eq!(
                    msg.corr_time.wn, 6,
                    "incorrect value for corr_time.wn, expected 6, is {}",
                    msg.corr_time.wn
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
                    msg.reserved[0], 0,
                    "incorrect value for reserved[0], expected 0, is {}",
                    msg.reserved[0]
                );
                assert_eq!(
                    msg.reserved[1], 0,
                    "incorrect value for reserved[1], expected 0, is {}",
                    msg.reserved[1]
                );
                assert_eq!(
                    msg.reserved[2], 0,
                    "incorrect value for reserved[2], expected 0, is {}",
                    msg.reserved[2]
                );
                assert_eq!(
                    msg.reserved[3], 0,
                    "incorrect value for reserved[3], expected 0, is {}",
                    msg.reserved[3]
                );
                assert_eq!(
                    msg.reserved[4], 0,
                    "incorrect value for reserved[4], expected 0, is {}",
                    msg.reserved[4]
                );
                assert_eq!(
                    msg.reserved[5], 0,
                    "incorrect value for reserved[5], expected 0, is {}",
                    msg.reserved[5]
                );
                assert_eq!(
                    msg.ssr_sol_id, 10,
                    "incorrect value for ssr_sol_id, expected 10, is {}",
                    msg.ssr_sol_id
                );
                assert_eq!(
                    msg.tile_id, 30,
                    "incorrect value for tile_id, expected 30, is {}",
                    msg.tile_id
                );
                assert_eq!(
                    msg.tile_set_id, 20,
                    "incorrect value for tile_set_id, expected 20, is {}",
                    msg.tile_set_id
                );
                assert_eq!(
                    msg.use_bds_sat, 3,
                    "incorrect value for use_bds_sat, expected 3, is {}",
                    msg.use_bds_sat
                );
                assert_eq!(
                    msg.use_gal_sat, 2,
                    "incorrect value for use_gal_sat, expected 2, is {}",
                    msg.use_gal_sat
                );
                assert_eq!(
                    msg.use_gps_sat, 1,
                    "incorrect value for use_gps_sat, expected 1, is {}",
                    msg.use_gps_sat
                );
                assert_eq!(
                    msg.use_iono_grid_point_sat_los, 7,
                    "incorrect value for use_iono_grid_point_sat_los, expected 7, is {}",
                    msg.use_iono_grid_point_sat_los
                );
                assert_eq!(
                    msg.use_iono_grid_points, 5,
                    "incorrect value for use_iono_grid_points, expected 5, is {}",
                    msg.use_iono_grid_points
                );
                assert_eq!(
                    msg.use_iono_tile_sat_los, 6,
                    "incorrect value for use_iono_tile_sat_los, expected 6, is {}",
                    msg.use_iono_tile_sat_los
                );
                assert_eq!(
                    msg.use_tropo_grid_points, 4,
                    "incorrect value for use_tropo_grid_points, expected 4, is {}",
                    msg.use_tropo_grid_points
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrFlagHighLevel"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
