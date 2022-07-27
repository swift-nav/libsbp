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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrCodePhaseBiasesBounds.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_code_phase_biases_bounds() {
    {
        let mut payload = Cursor::new(vec![
            85, 236, 5, 66, 0, 31, 180, 0, 0, 0, 3, 0, 1, 2, 1, 14, 15, 1, 3, 0, 3, 39, 1, 39, 1,
            1, 3, 39, 1, 39, 1, 1, 1, 39, 1, 39, 1, 23, 113,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrCodePhaseBiasesBounds(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1516,
                    "Incorrect message type, expected 1516, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.const_id, 1,
                    "incorrect value for const_id, expected 1, is {}",
                    msg.const_id
                );
                assert_eq!(
                    msg.header.num_msgs, 1,
                    "incorrect value for header.num_msgs, expected 1, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 2,
                    "incorrect value for header.seq_num, expected 2, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.sol_id, 14,
                    "incorrect value for header.sol_id, expected 14, is {}",
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
                    msg.header.update_interval, 1,
                    "incorrect value for header.update_interval, expected 1, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.n_sats_signals, 3,
                    "incorrect value for n_sats_signals, expected 3, is {}",
                    msg.n_sats_signals
                );
                assert_eq!(msg.satellites_signals[0].code_bias_bound_mu, 39, "incorrect value for satellites_signals[0].code_bias_bound_mu, expected 39, is {}", msg.satellites_signals[0].code_bias_bound_mu);
                assert_eq!(msg.satellites_signals[0].code_bias_bound_sig, 1, "incorrect value for satellites_signals[0].code_bias_bound_sig, expected 1, is {}", msg.satellites_signals[0].code_bias_bound_sig);
                assert_eq!(msg.satellites_signals[0].phase_bias_bound_mu, 39, "incorrect value for satellites_signals[0].phase_bias_bound_mu, expected 39, is {}", msg.satellites_signals[0].phase_bias_bound_mu);
                assert_eq!(msg.satellites_signals[0].phase_bias_bound_sig, 1, "incorrect value for satellites_signals[0].phase_bias_bound_sig, expected 1, is {}", msg.satellites_signals[0].phase_bias_bound_sig);
                assert_eq!(
                    msg.satellites_signals[0].sat_id, 0,
                    "incorrect value for satellites_signals[0].sat_id, expected 0, is {}",
                    msg.satellites_signals[0].sat_id
                );
                assert_eq!(
                    msg.satellites_signals[0].signal_id, 3,
                    "incorrect value for satellites_signals[0].signal_id, expected 3, is {}",
                    msg.satellites_signals[0].signal_id
                );
                assert_eq!(msg.satellites_signals[1].code_bias_bound_mu, 39, "incorrect value for satellites_signals[1].code_bias_bound_mu, expected 39, is {}", msg.satellites_signals[1].code_bias_bound_mu);
                assert_eq!(msg.satellites_signals[1].code_bias_bound_sig, 1, "incorrect value for satellites_signals[1].code_bias_bound_sig, expected 1, is {}", msg.satellites_signals[1].code_bias_bound_sig);
                assert_eq!(msg.satellites_signals[1].phase_bias_bound_mu, 39, "incorrect value for satellites_signals[1].phase_bias_bound_mu, expected 39, is {}", msg.satellites_signals[1].phase_bias_bound_mu);
                assert_eq!(msg.satellites_signals[1].phase_bias_bound_sig, 1, "incorrect value for satellites_signals[1].phase_bias_bound_sig, expected 1, is {}", msg.satellites_signals[1].phase_bias_bound_sig);
                assert_eq!(
                    msg.satellites_signals[1].sat_id, 1,
                    "incorrect value for satellites_signals[1].sat_id, expected 1, is {}",
                    msg.satellites_signals[1].sat_id
                );
                assert_eq!(
                    msg.satellites_signals[1].signal_id, 3,
                    "incorrect value for satellites_signals[1].signal_id, expected 3, is {}",
                    msg.satellites_signals[1].signal_id
                );
                assert_eq!(msg.satellites_signals[2].code_bias_bound_mu, 39, "incorrect value for satellites_signals[2].code_bias_bound_mu, expected 39, is {}", msg.satellites_signals[2].code_bias_bound_mu);
                assert_eq!(msg.satellites_signals[2].code_bias_bound_sig, 1, "incorrect value for satellites_signals[2].code_bias_bound_sig, expected 1, is {}", msg.satellites_signals[2].code_bias_bound_sig);
                assert_eq!(msg.satellites_signals[2].phase_bias_bound_mu, 39, "incorrect value for satellites_signals[2].phase_bias_bound_mu, expected 39, is {}", msg.satellites_signals[2].phase_bias_bound_mu);
                assert_eq!(msg.satellites_signals[2].phase_bias_bound_sig, 1, "incorrect value for satellites_signals[2].phase_bias_bound_sig, expected 1, is {}", msg.satellites_signals[2].phase_bias_bound_sig);
                assert_eq!(
                    msg.satellites_signals[2].sat_id, 1,
                    "incorrect value for satellites_signals[2].sat_id, expected 1, is {}",
                    msg.satellites_signals[2].sat_id
                );
                assert_eq!(
                    msg.satellites_signals[2].signal_id, 1,
                    "incorrect value for satellites_signals[2].signal_id, expected 1, is {}",
                    msg.satellites_signals[2].signal_id
                );
                assert_eq!(
                    msg.ssr_iod, 15,
                    "incorrect value for ssr_iod, expected 15, is {}",
                    msg.ssr_iod
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrCodePhaseBiasesBounds"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_code_phase_biases_bounds() {
    {
        let json_input = r#"{"header": {"time": {"tow": 180, "wn": 3}, "num_msgs": 1, "seq_num": 2, "update_interval": 1, "sol_id": 14}, "ssr_iod": 15, "const_id": 1, "n_sats_signals": 3, "satellites_signals": [{ "sat_id": 0, "signal_id": 3, "code_bias_bound_mu": 39, "code_bias_bound_sig": 1, "phase_bias_bound_mu": 39, "phase_bias_bound_sig": 1}, {"sat_id": 1, "signal_id": 3, "code_bias_bound_mu": 39, "code_bias_bound_sig": 1, "phase_bias_bound_mu": 39, "phase_bias_bound_sig": 1}, {"sat_id": 1, "signal_id": 1, "code_bias_bound_mu": 39, "code_bias_bound_sig": 1, "phase_bias_bound_mu": 39, "phase_bias_bound_sig": 1}], "preamble": 85, "msg_type": 1516, "sender": 66, "length": 31, "payload": "tAAAAAMAAQIBDg8BAwADJwEnAQEDJwEnAQEBJwEnAQ==", "crc": 28951}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrCodePhaseBiasesBounds(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1516,
                    "Incorrect message type, expected 1516, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.const_id, 1,
                    "incorrect value for const_id, expected 1, is {}",
                    msg.const_id
                );
                assert_eq!(
                    msg.header.num_msgs, 1,
                    "incorrect value for header.num_msgs, expected 1, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 2,
                    "incorrect value for header.seq_num, expected 2, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.sol_id, 14,
                    "incorrect value for header.sol_id, expected 14, is {}",
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
                    msg.header.update_interval, 1,
                    "incorrect value for header.update_interval, expected 1, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.n_sats_signals, 3,
                    "incorrect value for n_sats_signals, expected 3, is {}",
                    msg.n_sats_signals
                );
                assert_eq!(msg.satellites_signals[0].code_bias_bound_mu, 39, "incorrect value for satellites_signals[0].code_bias_bound_mu, expected 39, is {}", msg.satellites_signals[0].code_bias_bound_mu);
                assert_eq!(msg.satellites_signals[0].code_bias_bound_sig, 1, "incorrect value for satellites_signals[0].code_bias_bound_sig, expected 1, is {}", msg.satellites_signals[0].code_bias_bound_sig);
                assert_eq!(msg.satellites_signals[0].phase_bias_bound_mu, 39, "incorrect value for satellites_signals[0].phase_bias_bound_mu, expected 39, is {}", msg.satellites_signals[0].phase_bias_bound_mu);
                assert_eq!(msg.satellites_signals[0].phase_bias_bound_sig, 1, "incorrect value for satellites_signals[0].phase_bias_bound_sig, expected 1, is {}", msg.satellites_signals[0].phase_bias_bound_sig);
                assert_eq!(
                    msg.satellites_signals[0].sat_id, 0,
                    "incorrect value for satellites_signals[0].sat_id, expected 0, is {}",
                    msg.satellites_signals[0].sat_id
                );
                assert_eq!(
                    msg.satellites_signals[0].signal_id, 3,
                    "incorrect value for satellites_signals[0].signal_id, expected 3, is {}",
                    msg.satellites_signals[0].signal_id
                );
                assert_eq!(msg.satellites_signals[1].code_bias_bound_mu, 39, "incorrect value for satellites_signals[1].code_bias_bound_mu, expected 39, is {}", msg.satellites_signals[1].code_bias_bound_mu);
                assert_eq!(msg.satellites_signals[1].code_bias_bound_sig, 1, "incorrect value for satellites_signals[1].code_bias_bound_sig, expected 1, is {}", msg.satellites_signals[1].code_bias_bound_sig);
                assert_eq!(msg.satellites_signals[1].phase_bias_bound_mu, 39, "incorrect value for satellites_signals[1].phase_bias_bound_mu, expected 39, is {}", msg.satellites_signals[1].phase_bias_bound_mu);
                assert_eq!(msg.satellites_signals[1].phase_bias_bound_sig, 1, "incorrect value for satellites_signals[1].phase_bias_bound_sig, expected 1, is {}", msg.satellites_signals[1].phase_bias_bound_sig);
                assert_eq!(
                    msg.satellites_signals[1].sat_id, 1,
                    "incorrect value for satellites_signals[1].sat_id, expected 1, is {}",
                    msg.satellites_signals[1].sat_id
                );
                assert_eq!(
                    msg.satellites_signals[1].signal_id, 3,
                    "incorrect value for satellites_signals[1].signal_id, expected 3, is {}",
                    msg.satellites_signals[1].signal_id
                );
                assert_eq!(msg.satellites_signals[2].code_bias_bound_mu, 39, "incorrect value for satellites_signals[2].code_bias_bound_mu, expected 39, is {}", msg.satellites_signals[2].code_bias_bound_mu);
                assert_eq!(msg.satellites_signals[2].code_bias_bound_sig, 1, "incorrect value for satellites_signals[2].code_bias_bound_sig, expected 1, is {}", msg.satellites_signals[2].code_bias_bound_sig);
                assert_eq!(msg.satellites_signals[2].phase_bias_bound_mu, 39, "incorrect value for satellites_signals[2].phase_bias_bound_mu, expected 39, is {}", msg.satellites_signals[2].phase_bias_bound_mu);
                assert_eq!(msg.satellites_signals[2].phase_bias_bound_sig, 1, "incorrect value for satellites_signals[2].phase_bias_bound_sig, expected 1, is {}", msg.satellites_signals[2].phase_bias_bound_sig);
                assert_eq!(
                    msg.satellites_signals[2].sat_id, 1,
                    "incorrect value for satellites_signals[2].sat_id, expected 1, is {}",
                    msg.satellites_signals[2].sat_id
                );
                assert_eq!(
                    msg.satellites_signals[2].signal_id, 1,
                    "incorrect value for satellites_signals[2].signal_id, expected 1, is {}",
                    msg.satellites_signals[2].signal_id
                );
                assert_eq!(
                    msg.ssr_iod, 15,
                    "incorrect value for ssr_iod, expected 15, is {}",
                    msg.ssr_iod
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrCodePhaseBiasesBounds"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_code_phase_biases_bounds`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_code_phase_biases_bounds() {
    {
        let mut payload = Cursor::new(vec![
            85, 236, 5, 66, 0, 31, 180, 0, 0, 0, 3, 0, 1, 2, 1, 14, 15, 1, 3, 0, 3, 39, 1, 39, 1,
            1, 3, 39, 1, 39, 1, 1, 1, 39, 1, 39, 1, 23, 113,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrCodePhaseBiasesBounds(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrCodePhaseBiasesBounds(msg) => {
                assert_eq!(
                    msg.message_type(),
                    1516,
                    "Incorrect message type, expected 1516, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.const_id, 1,
                    "incorrect value for const_id, expected 1, is {}",
                    msg.const_id
                );
                assert_eq!(
                    msg.header.num_msgs, 1,
                    "incorrect value for header.num_msgs, expected 1, is {}",
                    msg.header.num_msgs
                );
                assert_eq!(
                    msg.header.seq_num, 2,
                    "incorrect value for header.seq_num, expected 2, is {}",
                    msg.header.seq_num
                );
                assert_eq!(
                    msg.header.sol_id, 14,
                    "incorrect value for header.sol_id, expected 14, is {}",
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
                    msg.header.update_interval, 1,
                    "incorrect value for header.update_interval, expected 1, is {}",
                    msg.header.update_interval
                );
                assert_eq!(
                    msg.n_sats_signals, 3,
                    "incorrect value for n_sats_signals, expected 3, is {}",
                    msg.n_sats_signals
                );
                assert_eq!(msg.satellites_signals[0].code_bias_bound_mu, 39, "incorrect value for satellites_signals[0].code_bias_bound_mu, expected 39, is {}", msg.satellites_signals[0].code_bias_bound_mu);
                assert_eq!(msg.satellites_signals[0].code_bias_bound_sig, 1, "incorrect value for satellites_signals[0].code_bias_bound_sig, expected 1, is {}", msg.satellites_signals[0].code_bias_bound_sig);
                assert_eq!(msg.satellites_signals[0].phase_bias_bound_mu, 39, "incorrect value for satellites_signals[0].phase_bias_bound_mu, expected 39, is {}", msg.satellites_signals[0].phase_bias_bound_mu);
                assert_eq!(msg.satellites_signals[0].phase_bias_bound_sig, 1, "incorrect value for satellites_signals[0].phase_bias_bound_sig, expected 1, is {}", msg.satellites_signals[0].phase_bias_bound_sig);
                assert_eq!(
                    msg.satellites_signals[0].sat_id, 0,
                    "incorrect value for satellites_signals[0].sat_id, expected 0, is {}",
                    msg.satellites_signals[0].sat_id
                );
                assert_eq!(
                    msg.satellites_signals[0].signal_id, 3,
                    "incorrect value for satellites_signals[0].signal_id, expected 3, is {}",
                    msg.satellites_signals[0].signal_id
                );
                assert_eq!(msg.satellites_signals[1].code_bias_bound_mu, 39, "incorrect value for satellites_signals[1].code_bias_bound_mu, expected 39, is {}", msg.satellites_signals[1].code_bias_bound_mu);
                assert_eq!(msg.satellites_signals[1].code_bias_bound_sig, 1, "incorrect value for satellites_signals[1].code_bias_bound_sig, expected 1, is {}", msg.satellites_signals[1].code_bias_bound_sig);
                assert_eq!(msg.satellites_signals[1].phase_bias_bound_mu, 39, "incorrect value for satellites_signals[1].phase_bias_bound_mu, expected 39, is {}", msg.satellites_signals[1].phase_bias_bound_mu);
                assert_eq!(msg.satellites_signals[1].phase_bias_bound_sig, 1, "incorrect value for satellites_signals[1].phase_bias_bound_sig, expected 1, is {}", msg.satellites_signals[1].phase_bias_bound_sig);
                assert_eq!(
                    msg.satellites_signals[1].sat_id, 1,
                    "incorrect value for satellites_signals[1].sat_id, expected 1, is {}",
                    msg.satellites_signals[1].sat_id
                );
                assert_eq!(
                    msg.satellites_signals[1].signal_id, 3,
                    "incorrect value for satellites_signals[1].signal_id, expected 3, is {}",
                    msg.satellites_signals[1].signal_id
                );
                assert_eq!(msg.satellites_signals[2].code_bias_bound_mu, 39, "incorrect value for satellites_signals[2].code_bias_bound_mu, expected 39, is {}", msg.satellites_signals[2].code_bias_bound_mu);
                assert_eq!(msg.satellites_signals[2].code_bias_bound_sig, 1, "incorrect value for satellites_signals[2].code_bias_bound_sig, expected 1, is {}", msg.satellites_signals[2].code_bias_bound_sig);
                assert_eq!(msg.satellites_signals[2].phase_bias_bound_mu, 39, "incorrect value for satellites_signals[2].phase_bias_bound_mu, expected 39, is {}", msg.satellites_signals[2].phase_bias_bound_mu);
                assert_eq!(msg.satellites_signals[2].phase_bias_bound_sig, 1, "incorrect value for satellites_signals[2].phase_bias_bound_sig, expected 1, is {}", msg.satellites_signals[2].phase_bias_bound_sig);
                assert_eq!(
                    msg.satellites_signals[2].sat_id, 1,
                    "incorrect value for satellites_signals[2].sat_id, expected 1, is {}",
                    msg.satellites_signals[2].sat_id
                );
                assert_eq!(
                    msg.satellites_signals[2].signal_id, 1,
                    "incorrect value for satellites_signals[2].signal_id, expected 1, is {}",
                    msg.satellites_signals[2].signal_id
                );
                assert_eq!(
                    msg.ssr_iod, 15,
                    "incorrect value for ssr_iod, expected 15, is {}",
                    msg.ssr_iod
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrCodePhaseBiasesBounds"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
