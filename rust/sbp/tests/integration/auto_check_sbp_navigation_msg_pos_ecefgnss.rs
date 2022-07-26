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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFGNSS.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_pos_ecefgnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 41, 2, 0, 16, 32, 24, 229, 233, 29, 52, 254, 158, 218, 42, 142, 68, 193, 69, 162,
            89, 91, 34, 68, 80, 193, 131, 21, 176, 129, 239, 174, 77, 65, 182, 0, 18, 4, 135, 2,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x229,
                    "Incorrect message type, expected 0x229, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 182,
                    "incorrect value for accuracy, expected 182, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 4,
                    "incorrect value for flags, expected 4, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 18,
                    "incorrect value for n_sats, expected 18, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501867800,
                    "incorrect value for tow, expected 501867800, is {}",
                    msg.tow
                );
                assert!(
                    msg.x.almost_eq(-2.69422970797708072e+06),
                    "incorrect value for x, expected -2.69422970797708072e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.26407342734581698e+06),
                    "incorrect value for y, expected -4.26407342734581698e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.89065501318615815e+06),
                    "incorrect value for z, expected 3.89065501318615815e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFGnss"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_pos_ecefgnss() {
    {
        let json_input = r#"{"tow":501867800,"x":-2694229.7079770807,"y":-4264073.427345817,"z":3890655.013186158,"accuracy":182,"n_sats":18,"flags":4,"preamble":85,"msg_type":553,"sender":4096,"payload":"GOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQbYAEgQ=","crc":647,"length":32}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosEcefGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x229,
                    "Incorrect message type, expected 0x229, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 182,
                    "incorrect value for accuracy, expected 182, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 4,
                    "incorrect value for flags, expected 4, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 18,
                    "incorrect value for n_sats, expected 18, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501867800,
                    "incorrect value for tow, expected 501867800, is {}",
                    msg.tow
                );
                assert!(
                    msg.x.almost_eq(-2.69422970797708072e+06),
                    "incorrect value for x, expected -2.69422970797708072e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.26407342734581698e+06),
                    "incorrect value for y, expected -4.26407342734581698e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.89065501318615815e+06),
                    "incorrect value for z, expected 3.89065501318615815e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFGnss"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_pos_ecefgnss`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_pos_ecefgnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 41, 2, 0, 16, 32, 24, 229, 233, 29, 52, 254, 158, 218, 42, 142, 68, 193, 69, 162,
            89, 91, 34, 68, 80, 193, 131, 21, 176, 129, 239, 174, 77, 65, 182, 0, 18, 4, 135, 2,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosEcefGnss(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x229,
                    "Incorrect message type, expected 0x229, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.accuracy, 182,
                    "incorrect value for accuracy, expected 182, is {}",
                    msg.accuracy
                );
                assert_eq!(
                    msg.flags, 4,
                    "incorrect value for flags, expected 4, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.n_sats, 18,
                    "incorrect value for n_sats, expected 18, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501867800,
                    "incorrect value for tow, expected 501867800, is {}",
                    msg.tow
                );
                assert!(
                    msg.x.almost_eq(-2.69422970797708072e+06),
                    "incorrect value for x, expected -2.69422970797708072e+06, is {:e}",
                    msg.x
                );
                assert!(
                    msg.y.almost_eq(-4.26407342734581698e+06),
                    "incorrect value for y, expected -4.26407342734581698e+06, is {:e}",
                    msg.y
                );
                assert!(
                    msg.z.almost_eq(3.89065501318615815e+06),
                    "incorrect value for z, expected 3.89065501318615815e+06, is {:e}",
                    msg.z
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosECEFGnss"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
