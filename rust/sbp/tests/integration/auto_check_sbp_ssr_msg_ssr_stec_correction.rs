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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrection.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_stec_correction() {
    {
        let mut payload = Cursor::new(vec![
            85, 253, 5, 66, 0, 38, 180, 0, 0, 0, 3, 0, 1, 1, 10, 0, 15, 1, 0, 10, 0, 2, 1, 1, 1,
            63, 0, 62, 0, 61, 0, 60, 0, 31, 15, 5, 63, 0, 64, 0, 65, 0, 66, 0, 119, 50,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrStecCorrection(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1533,
                    "Incorrect message type, expected 1533, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
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
                    msg.stec_sat_list[0].stec_coeff[0], 63,
                    "incorrect value for stec_sat_list[0].stec_coeff[0], expected 63, is {}",
                    msg.stec_sat_list[0].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[1], 62,
                    "incorrect value for stec_sat_list[0].stec_coeff[1], expected 62, is {}",
                    msg.stec_sat_list[0].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[2], 61,
                    "incorrect value for stec_sat_list[0].stec_coeff[2], expected 61, is {}",
                    msg.stec_sat_list[0].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[3], 60,
                    "incorrect value for stec_sat_list[0].stec_coeff[3], expected 60, is {}",
                    msg.stec_sat_list[0].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[0].stec_quality_indicator, 1, "incorrect value for stec_sat_list[0].stec_quality_indicator, expected 1, is {}", msg.stec_sat_list[0].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.constellation, 1,
                    "incorrect value for stec_sat_list[0].sv_id.constellation, expected 1, is {}",
                    msg.stec_sat_list[0].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.sat_id, 1,
                    "incorrect value for stec_sat_list[0].sv_id.sat_id, expected 1, is {}",
                    msg.stec_sat_list[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[0], 63,
                    "incorrect value for stec_sat_list[1].stec_coeff[0], expected 63, is {}",
                    msg.stec_sat_list[1].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[1], 64,
                    "incorrect value for stec_sat_list[1].stec_coeff[1], expected 64, is {}",
                    msg.stec_sat_list[1].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[2], 65,
                    "incorrect value for stec_sat_list[1].stec_coeff[2], expected 65, is {}",
                    msg.stec_sat_list[1].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[3], 66,
                    "incorrect value for stec_sat_list[1].stec_coeff[3], expected 66, is {}",
                    msg.stec_sat_list[1].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[1].stec_quality_indicator, 5, "incorrect value for stec_sat_list[1].stec_quality_indicator, expected 5, is {}", msg.stec_sat_list[1].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.constellation, 15,
                    "incorrect value for stec_sat_list[1].sv_id.constellation, expected 15, is {}",
                    msg.stec_sat_list[1].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.sat_id, 31,
                    "incorrect value for stec_sat_list[1].sv_id.sat_id, expected 31, is {}",
                    msg.stec_sat_list[1].sv_id.sat_id
                );
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
            }
            _ => panic!("Invalid message type! Expected a MsgSsrStecCorrection"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_stec_correction() {
    {
        let json_input = r#"{"header": {"time": {"tow": 180, "wn": 3}, "num_msgs": 1, "seq_num": 1, "update_interval": 10, "sol_id": 0}, "ssr_iod_atmo": 15, "tile_set_id": 1, "tile_id": 10, "n_sats": 2, "stec_sat_list": [{"sv_id": {"satId": 1, "constellation": 1}, "stec_quality_indicator": 1, "stec_coeff": [63, 62, 61, 60]}, {"sv_id": {"satId": 31, "constellation": 15}, "stec_quality_indicator": 5, "stec_coeff": [63, 64, 65, 66]}], "preamble": 85, "msg_type": 1533, "sender": 66, "length": 38, "payload": "tAAAAAMAAQEKAA8BAAoAAgEBAT8APgA9ADwAHw8FPwBAAEEAQgA=", "crc": 12919}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrStecCorrection(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1533,
                    "Incorrect message type, expected 1533, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
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
                    msg.stec_sat_list[0].stec_coeff[0], 63,
                    "incorrect value for stec_sat_list[0].stec_coeff[0], expected 63, is {}",
                    msg.stec_sat_list[0].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[1], 62,
                    "incorrect value for stec_sat_list[0].stec_coeff[1], expected 62, is {}",
                    msg.stec_sat_list[0].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[2], 61,
                    "incorrect value for stec_sat_list[0].stec_coeff[2], expected 61, is {}",
                    msg.stec_sat_list[0].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[3], 60,
                    "incorrect value for stec_sat_list[0].stec_coeff[3], expected 60, is {}",
                    msg.stec_sat_list[0].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[0].stec_quality_indicator, 1, "incorrect value for stec_sat_list[0].stec_quality_indicator, expected 1, is {}", msg.stec_sat_list[0].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.constellation, 1,
                    "incorrect value for stec_sat_list[0].sv_id.constellation, expected 1, is {}",
                    msg.stec_sat_list[0].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.sat_id, 1,
                    "incorrect value for stec_sat_list[0].sv_id.sat_id, expected 1, is {}",
                    msg.stec_sat_list[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[0], 63,
                    "incorrect value for stec_sat_list[1].stec_coeff[0], expected 63, is {}",
                    msg.stec_sat_list[1].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[1], 64,
                    "incorrect value for stec_sat_list[1].stec_coeff[1], expected 64, is {}",
                    msg.stec_sat_list[1].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[2], 65,
                    "incorrect value for stec_sat_list[1].stec_coeff[2], expected 65, is {}",
                    msg.stec_sat_list[1].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[3], 66,
                    "incorrect value for stec_sat_list[1].stec_coeff[3], expected 66, is {}",
                    msg.stec_sat_list[1].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[1].stec_quality_indicator, 5, "incorrect value for stec_sat_list[1].stec_quality_indicator, expected 5, is {}", msg.stec_sat_list[1].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.constellation, 15,
                    "incorrect value for stec_sat_list[1].sv_id.constellation, expected 15, is {}",
                    msg.stec_sat_list[1].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.sat_id, 31,
                    "incorrect value for stec_sat_list[1].sv_id.sat_id, expected 31, is {}",
                    msg.stec_sat_list[1].sv_id.sat_id
                );
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
            }
            _ => panic!("Invalid message type! Expected a MsgSsrStecCorrection"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_stec_correction`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_stec_correction() {
    {
        let mut payload = Cursor::new(vec![
            85, 253, 5, 66, 0, 38, 180, 0, 0, 0, 3, 0, 1, 1, 10, 0, 15, 1, 0, 10, 0, 2, 1, 1, 1,
            63, 0, 62, 0, 61, 0, 60, 0, 31, 15, 5, 63, 0, 64, 0, 65, 0, 66, 0, 119, 50,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrStecCorrection(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrStecCorrection(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1533,
                    "Incorrect message type, expected 1533, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
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
                    msg.stec_sat_list[0].stec_coeff[0], 63,
                    "incorrect value for stec_sat_list[0].stec_coeff[0], expected 63, is {}",
                    msg.stec_sat_list[0].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[1], 62,
                    "incorrect value for stec_sat_list[0].stec_coeff[1], expected 62, is {}",
                    msg.stec_sat_list[0].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[2], 61,
                    "incorrect value for stec_sat_list[0].stec_coeff[2], expected 61, is {}",
                    msg.stec_sat_list[0].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[0].stec_coeff[3], 60,
                    "incorrect value for stec_sat_list[0].stec_coeff[3], expected 60, is {}",
                    msg.stec_sat_list[0].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[0].stec_quality_indicator, 1, "incorrect value for stec_sat_list[0].stec_quality_indicator, expected 1, is {}", msg.stec_sat_list[0].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.constellation, 1,
                    "incorrect value for stec_sat_list[0].sv_id.constellation, expected 1, is {}",
                    msg.stec_sat_list[0].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[0].sv_id.sat_id, 1,
                    "incorrect value for stec_sat_list[0].sv_id.sat_id, expected 1, is {}",
                    msg.stec_sat_list[0].sv_id.sat_id
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[0], 63,
                    "incorrect value for stec_sat_list[1].stec_coeff[0], expected 63, is {}",
                    msg.stec_sat_list[1].stec_coeff[0]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[1], 64,
                    "incorrect value for stec_sat_list[1].stec_coeff[1], expected 64, is {}",
                    msg.stec_sat_list[1].stec_coeff[1]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[2], 65,
                    "incorrect value for stec_sat_list[1].stec_coeff[2], expected 65, is {}",
                    msg.stec_sat_list[1].stec_coeff[2]
                );
                assert_eq!(
                    msg.stec_sat_list[1].stec_coeff[3], 66,
                    "incorrect value for stec_sat_list[1].stec_coeff[3], expected 66, is {}",
                    msg.stec_sat_list[1].stec_coeff[3]
                );
                assert_eq!(msg.stec_sat_list[1].stec_quality_indicator, 5, "incorrect value for stec_sat_list[1].stec_quality_indicator, expected 5, is {}", msg.stec_sat_list[1].stec_quality_indicator);
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.constellation, 15,
                    "incorrect value for stec_sat_list[1].sv_id.constellation, expected 15, is {}",
                    msg.stec_sat_list[1].sv_id.constellation
                );
                assert_eq!(
                    msg.stec_sat_list[1].sv_id.sat_id, 31,
                    "incorrect value for stec_sat_list[1].sv_id.sat_id, expected 31, is {}",
                    msg.stec_sat_list[1].sv_id.sat_id
                );
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
            }
            _ => panic!("Invalid message type! Expected a MsgSsrStecCorrection"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
