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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgIono.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_iono() {
    {
        let mut payload = Cursor::new(vec![
            85, 144, 0, 123, 0, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 62, 0, 0, 0, 0, 0, 0,
            80, 62, 0, 0, 0, 0, 0, 0, 112, 190, 0, 0, 0, 0, 0, 0, 112, 190, 0, 0, 0, 0, 0, 0, 243,
            64, 0, 0, 0, 0, 0, 0, 232, 64, 0, 0, 0, 0, 0, 0, 240, 192, 0, 0, 0, 0, 0, 0, 20, 193,
            101, 31,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgIono(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x90,
                    "Incorrect message type, expected 0x90, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert!(
                    msg.a0.almost_eq(4.65661287307739258e-09),
                    "incorrect value for a0, expected 4.65661287307739258e-09, is {:e}",
                    msg.a0
                );
                assert!(
                    msg.a1.almost_eq(1.49011611938476562e-08),
                    "incorrect value for a1, expected 1.49011611938476562e-08, is {:e}",
                    msg.a1
                );
                assert!(
                    msg.a2.almost_eq(-5.96046447753906250e-08),
                    "incorrect value for a2, expected -5.96046447753906250e-08, is {:e}",
                    msg.a2
                );
                assert!(
                    msg.a3.almost_eq(-5.96046447753906250e-08),
                    "incorrect value for a3, expected -5.96046447753906250e-08, is {:e}",
                    msg.a3
                );
                assert!(
                    msg.b0.almost_eq(7.78240000000000000e+04),
                    "incorrect value for b0, expected 7.78240000000000000e+04, is {:e}",
                    msg.b0
                );
                assert!(
                    msg.b1.almost_eq(4.91520000000000000e+04),
                    "incorrect value for b1, expected 4.91520000000000000e+04, is {:e}",
                    msg.b1
                );
                assert!(
                    msg.b2.almost_eq(-6.55360000000000000e+04),
                    "incorrect value for b2, expected -6.55360000000000000e+04, is {:e}",
                    msg.b2
                );
                assert!(
                    msg.b3.almost_eq(-3.27680000000000000e+05),
                    "incorrect value for b3, expected -3.27680000000000000e+05, is {:e}",
                    msg.b3
                );
                assert_eq!(
                    msg.t_nmct.tow, 0,
                    "incorrect value for t_nmct.tow, expected 0, is {}",
                    msg.t_nmct.tow
                );
                assert_eq!(
                    msg.t_nmct.wn, 0,
                    "incorrect value for t_nmct.wn, expected 0, is {}",
                    msg.t_nmct.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgIono"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_iono() {
    {
        let json_input = r#"{"crc":8037,"length":70,"msg_type":144,"payload":"AAAAAAAAAAAAAAAAND4AAAAAAABQPgAAAAAAAHC+AAAAAAAAcL4AAAAAAADzQAAAAAAAAOhAAAAAAAAA8MAAAAAAAAAUwQ==","preamble":85,"sender":123,"t_nmct":{"tow":0,"wn":0},"a0":4.6566128730773926e-09,"a1":1.4901161193847656e-08,"a2":-5.960464477539063e-08,"a3":-5.960464477539063e-08,"b0":77824,"b1":49152,"b2":-65536,"b3":-327680}"#.as_bytes();

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
            sbp::messages::Sbp::MsgIono(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x90,
                    "Incorrect message type, expected 0x90, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert!(
                    msg.a0.almost_eq(4.65661287307739258e-09),
                    "incorrect value for a0, expected 4.65661287307739258e-09, is {:e}",
                    msg.a0
                );
                assert!(
                    msg.a1.almost_eq(1.49011611938476562e-08),
                    "incorrect value for a1, expected 1.49011611938476562e-08, is {:e}",
                    msg.a1
                );
                assert!(
                    msg.a2.almost_eq(-5.96046447753906250e-08),
                    "incorrect value for a2, expected -5.96046447753906250e-08, is {:e}",
                    msg.a2
                );
                assert!(
                    msg.a3.almost_eq(-5.96046447753906250e-08),
                    "incorrect value for a3, expected -5.96046447753906250e-08, is {:e}",
                    msg.a3
                );
                assert!(
                    msg.b0.almost_eq(7.78240000000000000e+04),
                    "incorrect value for b0, expected 7.78240000000000000e+04, is {:e}",
                    msg.b0
                );
                assert!(
                    msg.b1.almost_eq(4.91520000000000000e+04),
                    "incorrect value for b1, expected 4.91520000000000000e+04, is {:e}",
                    msg.b1
                );
                assert!(
                    msg.b2.almost_eq(-6.55360000000000000e+04),
                    "incorrect value for b2, expected -6.55360000000000000e+04, is {:e}",
                    msg.b2
                );
                assert!(
                    msg.b3.almost_eq(-3.27680000000000000e+05),
                    "incorrect value for b3, expected -3.27680000000000000e+05, is {:e}",
                    msg.b3
                );
                assert_eq!(
                    msg.t_nmct.tow, 0,
                    "incorrect value for t_nmct.tow, expected 0, is {}",
                    msg.t_nmct.tow
                );
                assert_eq!(
                    msg.t_nmct.wn, 0,
                    "incorrect value for t_nmct.wn, expected 0, is {}",
                    msg.t_nmct.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgIono"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_iono`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_iono() {
    {
        let mut payload = Cursor::new(vec![
            85, 144, 0, 123, 0, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 62, 0, 0, 0, 0, 0, 0,
            80, 62, 0, 0, 0, 0, 0, 0, 112, 190, 0, 0, 0, 0, 0, 0, 112, 190, 0, 0, 0, 0, 0, 0, 243,
            64, 0, 0, 0, 0, 0, 0, 232, 64, 0, 0, 0, 0, 0, 0, 240, 192, 0, 0, 0, 0, 0, 0, 20, 193,
            101, 31,
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
        let sbp_msg = sbp::messages::Sbp::MsgIono(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgIono(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x90,
                    "Incorrect message type, expected 0x90, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert!(
                    msg.a0.almost_eq(4.65661287307739258e-09),
                    "incorrect value for a0, expected 4.65661287307739258e-09, is {:e}",
                    msg.a0
                );
                assert!(
                    msg.a1.almost_eq(1.49011611938476562e-08),
                    "incorrect value for a1, expected 1.49011611938476562e-08, is {:e}",
                    msg.a1
                );
                assert!(
                    msg.a2.almost_eq(-5.96046447753906250e-08),
                    "incorrect value for a2, expected -5.96046447753906250e-08, is {:e}",
                    msg.a2
                );
                assert!(
                    msg.a3.almost_eq(-5.96046447753906250e-08),
                    "incorrect value for a3, expected -5.96046447753906250e-08, is {:e}",
                    msg.a3
                );
                assert!(
                    msg.b0.almost_eq(7.78240000000000000e+04),
                    "incorrect value for b0, expected 7.78240000000000000e+04, is {:e}",
                    msg.b0
                );
                assert!(
                    msg.b1.almost_eq(4.91520000000000000e+04),
                    "incorrect value for b1, expected 4.91520000000000000e+04, is {:e}",
                    msg.b1
                );
                assert!(
                    msg.b2.almost_eq(-6.55360000000000000e+04),
                    "incorrect value for b2, expected -6.55360000000000000e+04, is {:e}",
                    msg.b2
                );
                assert!(
                    msg.b3.almost_eq(-3.27680000000000000e+05),
                    "incorrect value for b3, expected -3.27680000000000000e+05, is {:e}",
                    msg.b3
                );
                assert_eq!(
                    msg.t_nmct.tow, 0,
                    "incorrect value for t_nmct.tow, expected 0, is {}",
                    msg.t_nmct.tow
                );
                assert_eq!(
                    msg.t_nmct.wn, 0,
                    "incorrect value for t_nmct.wn, expected 0, is {}",
                    msg.t_nmct.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgIono"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
