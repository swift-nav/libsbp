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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionBounds.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_gridded_correction_bounds() {
    {
        let mut payload = Cursor::new(vec![
            85, 254, 5, 66, 0, 45, 180, 0, 0, 0, 3, 0, 1, 1, 10, 0, 15, 1, 0, 10, 0, 39, 232, 3,
            244, 1, 100, 200, 150, 100, 150, 100, 2, 5, 10, 16, 0, 17, 18, 19, 20, 21, 6, 10, 22,
            0, 23, 24, 25, 26, 27, 119, 82,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrGriddedCorrectionBounds(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1534,
                    "Incorrect message type, expected 1534, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.grid_point_id, 1000,
                    "incorrect value for grid_point_id, expected 1000, is {}",
                    msg.grid_point_id
                );
                assert_eq!(
                    msg.header.num_msgs, 1,
                    "incorrect value for header.num_msgs, expected 1, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 1,
                    "incorrect value for header.seq_num, expected 1, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.sol_id, 0,
                    "incorrect value for header.sol_id, expected 0, is {}",
                    msg.header.sol_id
                );
                assert_eq!(
                    msg.header.time.tow, 180,
                    "incorrect value for header.time.tow, expected 180, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 3,
                    "incorrect value for header.time.wn, expected 3, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.update_interval, 10,
                    "incorrect value for header.update_interval, expected 10, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.n_sats, 2,
                    "incorrect value for n_sats, expected 2, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.ssr_iod_atmo, 15,
                    "incorrect value for ssr_iod_atmo, expected 15, is {}",
                    msg.ssr_iod_atmo
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_bound_mu, 18,
                    "incorrect value for stec_sat_list[0].stec_bound_mu, expected 18, is {}",
                    msg.stec_sat_list[0].stec_bound_mu
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_bound_mu_dot, 20,
                    "incorrect value for stec_sat_list[0].stec_bound_mu_dot, expected 20, is {}",
                    msg.stec_sat_list[0].stec_bound_mu_dot
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_bound_sig, 19,
                    "incorrect value for stec_sat_list[0].stec_bound_sig, expected 19, is {}",
                    msg.stec_sat_list[0].stec_bound_sig
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_bound_sig_dot, 21,
                    "incorrect value for stec_sat_list[0].stec_bound_sig_dot, expected 21, is {}",
                    msg.stec_sat_list[0].stec_bound_sig_dot
                );
                assert_eq!(msg.stec_sat_list[0].stec_residual.residual, 16, "incorrect value for stec_sat_list[0].stec_residual.residual, expected 16, is {}", msg.stec_sat_list[0].stec_residual.residual);
                assert_eq!(
                    msg.stec_sat_list[0].stec_residual.stddev, 17,
                    "incorrect value for stec_sat_list[0].stec_residual.stddev, expected 17, is {}",
                    msg.stec_sat_list[0].stec_residual.stddev
                );
                assert_eq!(msg.stec_sat_list[0].stec_residual.sv_id.constellation, 10, "incorrect value for stec_sat_list[0].stec_residual.sv_id.constellation, expected 10, is {}", msg.stec_sat_list[0].stec_residual.sv_id.constellation);
                assert_eq!(msg.stec_sat_list[0].stec_residual.sv_id.sat_id, 5, "incorrect value for stec_sat_list[0].stec_residual.sv_id.sat_id, expected 5, is {}", msg.stec_sat_list[0].stec_residual.sv_id.sat_id);
                assert_eq!(
                    msg.stec_sat_list[1].stec_bound_mu, 24,
                    "incorrect value for stec_sat_list[1].stec_bound_mu, expected 24, is {}",
                    msg.stec_sat_list[1].stec_bound_mu
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_bound_mu_dot, 26,
                    "incorrect value for stec_sat_list[1].stec_bound_mu_dot, expected 26, is {}",
                    msg.stec_sat_list[1].stec_bound_mu_dot
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_bound_sig, 25,
                    "incorrect value for stec_sat_list[1].stec_bound_sig, expected 25, is {}",
                    msg.stec_sat_list[1].stec_bound_sig
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_bound_sig_dot, 27,
                    "incorrect value for stec_sat_list[1].stec_bound_sig_dot, expected 27, is {}",
                    msg.stec_sat_list[1].stec_bound_sig_dot
                );
                assert_eq!(msg.stec_sat_list[1].stec_residual.residual, 22, "incorrect value for stec_sat_list[1].stec_residual.residual, expected 22, is {}", msg.stec_sat_list[1].stec_residual.residual);
                assert_eq!(
                    msg.stec_sat_list[1].stec_residual.stddev, 23,
                    "incorrect value for stec_sat_list[1].stec_residual.stddev, expected 23, is {}",
                    msg.stec_sat_list[1].stec_residual.stddev
                );
                assert_eq!(msg.stec_sat_list[1].stec_residual.sv_id.constellation, 10, "incorrect value for stec_sat_list[1].stec_residual.sv_id.constellation, expected 10, is {}", msg.stec_sat_list[1].stec_residual.sv_id.constellation);
                assert_eq!(msg.stec_sat_list[1].stec_residual.sv_id.sat_id, 6, "incorrect value for stec_sat_list[1].stec_residual.sv_id.sat_id, expected 6, is {}", msg.stec_sat_list[1].stec_residual.sv_id.sat_id);
                assert_eq!(
                    msg.tile_id, 10,
                    "incorrect value for tile_id, expected 10, is {}",
                    msg.tile_id
                );
                assert_eq!(
                    msg.tile_set_id, 1,
                    "incorrect value for tile_set_id, expected 1, is {}",
                    msg.tile_set_id
                );
                assert_eq!(
                    msg.tropo_delay_correction.hydro, 500,
                    "incorrect value for tropo_delay_correction.hydro, expected 500, is {}",
                    msg.tropo_delay_correction.hydro
                );
                assert_eq!(
                    msg.tropo_delay_correction.stddev, 200,
                    "incorrect value for tropo_delay_correction.stddev, expected 200, is {}",
                    msg.tropo_delay_correction.stddev
                );
                assert_eq!(
                    msg.tropo_delay_correction.wet, 100,
                    "incorrect value for tropo_delay_correction.wet, expected 100, is {}",
                    msg.tropo_delay_correction.wet
                );
                assert_eq!(
                    msg.tropo_qi, 39,
                    "incorrect value for tropo_qi, expected 39, is {}",
                    msg.tropo_qi
                );
                assert_eq!(
                    msg.tropo_v_hydro_bound_mu, 150,
                    "incorrect value for tropo_v_hydro_bound_mu, expected 150, is {}",
                    msg.tropo_v_hydro_bound_mu
                );
                assert_eq!(
                    msg.tropo_v_hydro_bound_sig, 100,
                    "incorrect value for tropo_v_hydro_bound_sig, expected 100, is {}",
                    msg.tropo_v_hydro_bound_sig
                );
                assert_eq!(
                    msg.tropo_v_wet_bound_mu, 150,
                    "incorrect value for tropo_v_wet_bound_mu, expected 150, is {}",
                    msg.tropo_v_wet_bound_mu
                );
                assert_eq!(
                    msg.tropo_v_wet_bound_sig, 100,
                    "incorrect value for tropo_v_wet_bound_sig, expected 100, is {}",
                    msg.tropo_v_wet_bound_sig
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGriddedCorrectionBounds"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_gridded_correction_bounds() {
    {
        let json_input = r#"{"header": {"time": {"tow": 180, "wn": 3}, "num_msgs": 1, "seq_num": 1, "update_interval": 10, "sol_id": 0}, "ssr_iod_atmo": 15, "tile_set_id": 1, "tile_id": 10, "tropo_qi": 39, "grid_point_id": 1000, "tropo_delay_correction": {"hydro": 500, "wet": 100, "stddev": 200}, "tropo_v_hydro_bound_mu": 150, "tropo_v_hydro_bound_sig": 100, "tropo_v_wet_bound_mu": 150, "tropo_v_wet_bound_sig": 100, "n_sats": 2, "stec_sat_list": [{"stec_residual": {"sv_id": {"satId": 5, "constellation": 10}, "residual": 16, "stddev": 17}, "stec_bound_mu": 18, "stec_bound_sig": 19, "stec_bound_mu_dot": 20, "stec_bound_sig_dot": 21}, {"stec_residual": {"sv_id": {"satId": 6, "constellation": 10}, "residual": 22, "stddev": 23}, "stec_bound_mu": 24, "stec_bound_sig": 25, "stec_bound_mu_dot": 26, "stec_bound_sig_dot": 27}], "preamble": 85, "msg_type": 1534, "sender": 66, "length": 45, "payload": "tAAAAAMAAQEKAA8BAAoAJ+gD9AFkyJZklmQCBQoQABESExQVBgoWABcYGRob", "crc": 21111}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrGriddedCorrectionBounds(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1534,
                    "Incorrect message type, expected 1534, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.grid_point_id, 1000,
                    "incorrect value for grid_point_id, expected 1000, is {}",
                    msg.grid_point_id
                );
                assert_eq!(
                    msg.header.num_msgs, 1,
                    "incorrect value for header.num_msgs, expected 1, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 1,
                    "incorrect value for header.seq_num, expected 1, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.sol_id, 0,
                    "incorrect value for header.sol_id, expected 0, is {}",
                    msg.header.sol_id
                );
                assert_eq!(
                    msg.header.time.tow, 180,
                    "incorrect value for header.time.tow, expected 180, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 3,
                    "incorrect value for header.time.wn, expected 3, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.update_interval, 10,
                    "incorrect value for header.update_interval, expected 10, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.n_sats, 2,
                    "incorrect value for n_sats, expected 2, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.ssr_iod_atmo, 15,
                    "incorrect value for ssr_iod_atmo, expected 15, is {}",
                    msg.ssr_iod_atmo
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_bound_mu, 18,
                    "incorrect value for stec_sat_list[0].stec_bound_mu, expected 18, is {}",
                    msg.stec_sat_list[0].stec_bound_mu
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_bound_mu_dot, 20,
                    "incorrect value for stec_sat_list[0].stec_bound_mu_dot, expected 20, is {}",
                    msg.stec_sat_list[0].stec_bound_mu_dot
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_bound_sig, 19,
                    "incorrect value for stec_sat_list[0].stec_bound_sig, expected 19, is {}",
                    msg.stec_sat_list[0].stec_bound_sig
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_bound_sig_dot, 21,
                    "incorrect value for stec_sat_list[0].stec_bound_sig_dot, expected 21, is {}",
                    msg.stec_sat_list[0].stec_bound_sig_dot
                );
                assert_eq!(msg.stec_sat_list[0].stec_residual.residual, 16, "incorrect value for stec_sat_list[0].stec_residual.residual, expected 16, is {}", msg.stec_sat_list[0].stec_residual.residual);
                assert_eq!(
                    msg.stec_sat_list[0].stec_residual.stddev, 17,
                    "incorrect value for stec_sat_list[0].stec_residual.stddev, expected 17, is {}",
                    msg.stec_sat_list[0].stec_residual.stddev
                );
                assert_eq!(msg.stec_sat_list[0].stec_residual.sv_id.constellation, 10, "incorrect value for stec_sat_list[0].stec_residual.sv_id.constellation, expected 10, is {}", msg.stec_sat_list[0].stec_residual.sv_id.constellation);
                assert_eq!(msg.stec_sat_list[0].stec_residual.sv_id.sat_id, 5, "incorrect value for stec_sat_list[0].stec_residual.sv_id.sat_id, expected 5, is {}", msg.stec_sat_list[0].stec_residual.sv_id.sat_id);
                assert_eq!(
                    msg.stec_sat_list[1].stec_bound_mu, 24,
                    "incorrect value for stec_sat_list[1].stec_bound_mu, expected 24, is {}",
                    msg.stec_sat_list[1].stec_bound_mu
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_bound_mu_dot, 26,
                    "incorrect value for stec_sat_list[1].stec_bound_mu_dot, expected 26, is {}",
                    msg.stec_sat_list[1].stec_bound_mu_dot
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_bound_sig, 25,
                    "incorrect value for stec_sat_list[1].stec_bound_sig, expected 25, is {}",
                    msg.stec_sat_list[1].stec_bound_sig
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_bound_sig_dot, 27,
                    "incorrect value for stec_sat_list[1].stec_bound_sig_dot, expected 27, is {}",
                    msg.stec_sat_list[1].stec_bound_sig_dot
                );
                assert_eq!(msg.stec_sat_list[1].stec_residual.residual, 22, "incorrect value for stec_sat_list[1].stec_residual.residual, expected 22, is {}", msg.stec_sat_list[1].stec_residual.residual);
                assert_eq!(
                    msg.stec_sat_list[1].stec_residual.stddev, 23,
                    "incorrect value for stec_sat_list[1].stec_residual.stddev, expected 23, is {}",
                    msg.stec_sat_list[1].stec_residual.stddev
                );
                assert_eq!(msg.stec_sat_list[1].stec_residual.sv_id.constellation, 10, "incorrect value for stec_sat_list[1].stec_residual.sv_id.constellation, expected 10, is {}", msg.stec_sat_list[1].stec_residual.sv_id.constellation);
                assert_eq!(msg.stec_sat_list[1].stec_residual.sv_id.sat_id, 6, "incorrect value for stec_sat_list[1].stec_residual.sv_id.sat_id, expected 6, is {}", msg.stec_sat_list[1].stec_residual.sv_id.sat_id);
                assert_eq!(
                    msg.tile_id, 10,
                    "incorrect value for tile_id, expected 10, is {}",
                    msg.tile_id
                );
                assert_eq!(
                    msg.tile_set_id, 1,
                    "incorrect value for tile_set_id, expected 1, is {}",
                    msg.tile_set_id
                );
                assert_eq!(
                    msg.tropo_delay_correction.hydro, 500,
                    "incorrect value for tropo_delay_correction.hydro, expected 500, is {}",
                    msg.tropo_delay_correction.hydro
                );
                assert_eq!(
                    msg.tropo_delay_correction.stddev, 200,
                    "incorrect value for tropo_delay_correction.stddev, expected 200, is {}",
                    msg.tropo_delay_correction.stddev
                );
                assert_eq!(
                    msg.tropo_delay_correction.wet, 100,
                    "incorrect value for tropo_delay_correction.wet, expected 100, is {}",
                    msg.tropo_delay_correction.wet
                );
                assert_eq!(
                    msg.tropo_qi, 39,
                    "incorrect value for tropo_qi, expected 39, is {}",
                    msg.tropo_qi
                );
                assert_eq!(
                    msg.tropo_v_hydro_bound_mu, 150,
                    "incorrect value for tropo_v_hydro_bound_mu, expected 150, is {}",
                    msg.tropo_v_hydro_bound_mu
                );
                assert_eq!(
                    msg.tropo_v_hydro_bound_sig, 100,
                    "incorrect value for tropo_v_hydro_bound_sig, expected 100, is {}",
                    msg.tropo_v_hydro_bound_sig
                );
                assert_eq!(
                    msg.tropo_v_wet_bound_mu, 150,
                    "incorrect value for tropo_v_wet_bound_mu, expected 150, is {}",
                    msg.tropo_v_wet_bound_mu
                );
                assert_eq!(
                    msg.tropo_v_wet_bound_sig, 100,
                    "incorrect value for tropo_v_wet_bound_sig, expected 100, is {}",
                    msg.tropo_v_wet_bound_sig
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGriddedCorrectionBounds"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_gridded_correction_bounds`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_gridded_correction_bounds() {
    {
        let mut payload = Cursor::new(vec![
            85, 254, 5, 66, 0, 45, 180, 0, 0, 0, 3, 0, 1, 1, 10, 0, 15, 1, 0, 10, 0, 39, 232, 3,
            244, 1, 100, 200, 150, 100, 150, 100, 2, 5, 10, 16, 0, 17, 18, 19, 20, 21, 6, 10, 22,
            0, 23, 24, 25, 26, 27, 119, 82,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrGriddedCorrectionBounds(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrGriddedCorrectionBounds(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1534,
                    "Incorrect message type, expected 1534, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.grid_point_id, 1000,
                    "incorrect value for grid_point_id, expected 1000, is {}",
                    msg.grid_point_id
                );
                assert_eq!(
                    msg.header.num_msgs, 1,
                    "incorrect value for header.num_msgs, expected 1, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 1,
                    "incorrect value for header.seq_num, expected 1, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.sol_id, 0,
                    "incorrect value for header.sol_id, expected 0, is {}",
                    msg.header.sol_id
                );
                assert_eq!(
                    msg.header.time.tow, 180,
                    "incorrect value for header.time.tow, expected 180, is {}",
                    msg.header.time.tow
                );
                assert_eq!(
                    msg.header.time.wn, 3,
                    "incorrect value for header.time.wn, expected 3, is {}",
                    msg.header.time.wn
                );
                assert_eq!(
                    msg.header.update_interval, 10,
                    "incorrect value for header.update_interval, expected 10, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.n_sats, 2,
                    "incorrect value for n_sats, expected 2, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.ssr_iod_atmo, 15,
                    "incorrect value for ssr_iod_atmo, expected 15, is {}",
                    msg.ssr_iod_atmo
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_bound_mu, 18,
                    "incorrect value for stec_sat_list[0].stec_bound_mu, expected 18, is {}",
                    msg.stec_sat_list[0].stec_bound_mu
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_bound_mu_dot, 20,
                    "incorrect value for stec_sat_list[0].stec_bound_mu_dot, expected 20, is {}",
                    msg.stec_sat_list[0].stec_bound_mu_dot
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_bound_sig, 19,
                    "incorrect value for stec_sat_list[0].stec_bound_sig, expected 19, is {}",
                    msg.stec_sat_list[0].stec_bound_sig
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_bound_sig_dot, 21,
                    "incorrect value for stec_sat_list[0].stec_bound_sig_dot, expected 21, is {}",
                    msg.stec_sat_list[0].stec_bound_sig_dot
                );
                assert_eq!(msg.stec_sat_list[0].stec_residual.residual, 16, "incorrect value for stec_sat_list[0].stec_residual.residual, expected 16, is {}", msg.stec_sat_list[0].stec_residual.residual);
                assert_eq!(
                    msg.stec_sat_list[0].stec_residual.stddev, 17,
                    "incorrect value for stec_sat_list[0].stec_residual.stddev, expected 17, is {}",
                    msg.stec_sat_list[0].stec_residual.stddev
                );
                assert_eq!(msg.stec_sat_list[0].stec_residual.sv_id.constellation, 10, "incorrect value for stec_sat_list[0].stec_residual.sv_id.constellation, expected 10, is {}", msg.stec_sat_list[0].stec_residual.sv_id.constellation);
                assert_eq!(msg.stec_sat_list[0].stec_residual.sv_id.sat_id, 5, "incorrect value for stec_sat_list[0].stec_residual.sv_id.sat_id, expected 5, is {}", msg.stec_sat_list[0].stec_residual.sv_id.sat_id);
                assert_eq!(
                    msg.stec_sat_list[1].stec_bound_mu, 24,
                    "incorrect value for stec_sat_list[1].stec_bound_mu, expected 24, is {}",
                    msg.stec_sat_list[1].stec_bound_mu
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_bound_mu_dot, 26,
                    "incorrect value for stec_sat_list[1].stec_bound_mu_dot, expected 26, is {}",
                    msg.stec_sat_list[1].stec_bound_mu_dot
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_bound_sig, 25,
                    "incorrect value for stec_sat_list[1].stec_bound_sig, expected 25, is {}",
                    msg.stec_sat_list[1].stec_bound_sig
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_bound_sig_dot, 27,
                    "incorrect value for stec_sat_list[1].stec_bound_sig_dot, expected 27, is {}",
                    msg.stec_sat_list[1].stec_bound_sig_dot
                );
                assert_eq!(msg.stec_sat_list[1].stec_residual.residual, 22, "incorrect value for stec_sat_list[1].stec_residual.residual, expected 22, is {}", msg.stec_sat_list[1].stec_residual.residual);
                assert_eq!(
                    msg.stec_sat_list[1].stec_residual.stddev, 23,
                    "incorrect value for stec_sat_list[1].stec_residual.stddev, expected 23, is {}",
                    msg.stec_sat_list[1].stec_residual.stddev
                );
                assert_eq!(msg.stec_sat_list[1].stec_residual.sv_id.constellation, 10, "incorrect value for stec_sat_list[1].stec_residual.sv_id.constellation, expected 10, is {}", msg.stec_sat_list[1].stec_residual.sv_id.constellation);
                assert_eq!(msg.stec_sat_list[1].stec_residual.sv_id.sat_id, 6, "incorrect value for stec_sat_list[1].stec_residual.sv_id.sat_id, expected 6, is {}", msg.stec_sat_list[1].stec_residual.sv_id.sat_id);
                assert_eq!(
                    msg.tile_id, 10,
                    "incorrect value for tile_id, expected 10, is {}",
                    msg.tile_id
                );
                assert_eq!(
                    msg.tile_set_id, 1,
                    "incorrect value for tile_set_id, expected 1, is {}",
                    msg.tile_set_id
                );
                assert_eq!(
                    msg.tropo_delay_correction.hydro, 500,
                    "incorrect value for tropo_delay_correction.hydro, expected 500, is {}",
                    msg.tropo_delay_correction.hydro
                );
                assert_eq!(
                    msg.tropo_delay_correction.stddev, 200,
                    "incorrect value for tropo_delay_correction.stddev, expected 200, is {}",
                    msg.tropo_delay_correction.stddev
                );
                assert_eq!(
                    msg.tropo_delay_correction.wet, 100,
                    "incorrect value for tropo_delay_correction.wet, expected 100, is {}",
                    msg.tropo_delay_correction.wet
                );
                assert_eq!(
                    msg.tropo_qi, 39,
                    "incorrect value for tropo_qi, expected 39, is {}",
                    msg.tropo_qi
                );
                assert_eq!(
                    msg.tropo_v_hydro_bound_mu, 150,
                    "incorrect value for tropo_v_hydro_bound_mu, expected 150, is {}",
                    msg.tropo_v_hydro_bound_mu
                );
                assert_eq!(
                    msg.tropo_v_hydro_bound_sig, 100,
                    "incorrect value for tropo_v_hydro_bound_sig, expected 100, is {}",
                    msg.tropo_v_hydro_bound_sig
                );
                assert_eq!(
                    msg.tropo_v_wet_bound_mu, 150,
                    "incorrect value for tropo_v_wet_bound_mu, expected 150, is {}",
                    msg.tropo_v_wet_bound_mu
                );
                assert_eq!(
                    msg.tropo_v_wet_bound_sig, 100,
                    "incorrect value for tropo_v_wet_bound_sig, expected 100, is {}",
                    msg.tropo_v_wet_bound_sig
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrGriddedCorrectionBounds"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
