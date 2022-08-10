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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCovGNSS.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_pos_ecef_cov_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 52, 2, 0, 16, 54, 24, 229, 233, 29, 52, 254, 158, 218, 42, 142, 68, 193, 69, 162,
            89, 91, 34, 68, 80, 193, 131, 21, 176, 129, 239, 174, 77, 65, 158, 232, 30, 60, 218,
            221, 20, 60, 129, 136, 198, 187, 205, 120, 166, 60, 5, 166, 35, 188, 122, 177, 115, 60,
            18, 4, 159, 102,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefCovGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x234,
                    "Incorrect message type, expected 0x234, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(9.69901494681835175e-03),
                    "incorrect value for cov_x_x, expected 9.69901494681835175e-03, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(9.08609665930271149e-03),
                    "incorrect value for cov_x_y, expected 9.08609665930271149e-03, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(-6.05875300243496895e-03),
                    "incorrect value for cov_x_z, expected -6.05875300243496895e-03, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(2.03212741762399673e-02),
                    "incorrect value for cov_y_y, expected 2.03212741762399673e-02, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(-9.98831260949373245e-03),
                    "incorrect value for cov_y_z, expected -9.98831260949373245e-03, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(1.48738566786050797e-02),
                    "incorrect value for cov_z_z, expected 1.48738566786050797e-02, is {:e}",
                    msg.cov_z_z
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
            _ => panic!("Invalid message type! Expected a MsgPosECEFCovGnss"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_pos_ecef_cov_gnss() {
    {
        let json_input = r#"{"tow":501867800,"x":-2694229.7079770807,"y":-4264073.427345817,"z":3890655.013186158,"cov_x_x":0.009699014946818352,"cov_x_y":0.009086096659302711,"cov_x_z":-0.006058753002434969,"cov_y_y":0.020321274176239967,"cov_y_z":-0.009988312609493732,"cov_z_z":0.01487385667860508,"n_sats":18,"flags":4,"preamble":85,"msg_type":564,"sender":4096,"payload":"GOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQZ7oHjza3RQ8gYjGu814pjwFpiO8erFzPBIE","crc":26271,"length":54}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosEcefCovGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x234,
                    "Incorrect message type, expected 0x234, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(9.69901494681835175e-03),
                    "incorrect value for cov_x_x, expected 9.69901494681835175e-03, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(9.08609665930271149e-03),
                    "incorrect value for cov_x_y, expected 9.08609665930271149e-03, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(-6.05875300243496895e-03),
                    "incorrect value for cov_x_z, expected -6.05875300243496895e-03, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(2.03212741762399673e-02),
                    "incorrect value for cov_y_y, expected 2.03212741762399673e-02, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(-9.98831260949373245e-03),
                    "incorrect value for cov_y_z, expected -9.98831260949373245e-03, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(1.48738566786050797e-02),
                    "incorrect value for cov_z_z, expected 1.48738566786050797e-02, is {:e}",
                    msg.cov_z_z
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
            _ => panic!("Invalid message type! Expected a MsgPosECEFCovGnss"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_pos_ecef_cov_gnss`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_pos_ecef_cov_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 52, 2, 0, 16, 54, 24, 229, 233, 29, 52, 254, 158, 218, 42, 142, 68, 193, 69, 162,
            89, 91, 34, 68, 80, 193, 131, 21, 176, 129, 239, 174, 77, 65, 158, 232, 30, 60, 218,
            221, 20, 60, 129, 136, 198, 187, 205, 120, 166, 60, 5, 166, 35, 188, 122, 177, 115, 60,
            18, 4, 159, 102,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosEcefCovGnss(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosEcefCovGnss(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x234,
                    "Incorrect message type, expected 0x234, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert!(
                    msg.cov_x_x.almost_eq(9.69901494681835175e-03),
                    "incorrect value for cov_x_x, expected 9.69901494681835175e-03, is {:e}",
                    msg.cov_x_x
                );
                assert!(
                    msg.cov_x_y.almost_eq(9.08609665930271149e-03),
                    "incorrect value for cov_x_y, expected 9.08609665930271149e-03, is {:e}",
                    msg.cov_x_y
                );
                assert!(
                    msg.cov_x_z.almost_eq(-6.05875300243496895e-03),
                    "incorrect value for cov_x_z, expected -6.05875300243496895e-03, is {:e}",
                    msg.cov_x_z
                );
                assert!(
                    msg.cov_y_y.almost_eq(2.03212741762399673e-02),
                    "incorrect value for cov_y_y, expected 2.03212741762399673e-02, is {:e}",
                    msg.cov_y_y
                );
                assert!(
                    msg.cov_y_z.almost_eq(-9.98831260949373245e-03),
                    "incorrect value for cov_y_z, expected -9.98831260949373245e-03, is {:e}",
                    msg.cov_y_z
                );
                assert!(
                    msg.cov_z_z.almost_eq(1.48738566786050797e-02),
                    "incorrect value for cov_z_z, expected 1.48738566786050797e-02, is {:e}",
                    msg.cov_z_z
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
            _ => panic!("Invalid message type! Expected a MsgPosECEFCovGnss"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
