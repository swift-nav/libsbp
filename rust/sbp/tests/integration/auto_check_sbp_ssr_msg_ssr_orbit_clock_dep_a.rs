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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_orbit_clock_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 220, 5, 33, 166, 47, 225, 114, 31, 189, 43, 30, 1, 30, 194, 211, 193, 175, 161,
            143, 254, 56, 63, 232, 7, 216, 69, 1, 110, 165, 124, 196, 189, 27, 116, 88, 4, 61, 3,
            151, 18, 171, 147, 46, 198, 85, 243, 245, 225, 235, 123, 181, 210, 157, 252,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrOrbitClockDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5dc,
                    "Incorrect message type, expected 0x5dc, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xa621,
                    "incorrect sender id, expected 0xa621, is {sender_id}"
                );
                assert_eq!(
                    msg.along, 132661048,
                    "incorrect value for along, expected 132661048, is {}",
                    msg.along
                );
                assert_eq!(
                    msg.c0, -970026069,
                    "incorrect value for c0, expected -970026069, is {}",
                    msg.c0
                );
                assert_eq!(
                    msg.c1, -503975083,
                    "incorrect value for c1, expected -503975083, is {}",
                    msg.c1
                );
                assert_eq!(
                    msg.c2, -759858197,
                    "incorrect value for c2, expected -759858197, is {}",
                    msg.c2
                );
                assert_eq!(
                    msg.cross, 1845577176,
                    "incorrect value for cross, expected 1845577176, is {}",
                    msg.cross
                );
                assert_eq!(
                    msg.dot_along, 72905755,
                    "incorrect value for dot_along, expected 72905755, is {}",
                    msg.dot_along
                );
                assert_eq!(
                    msg.dot_cross, 311886653,
                    "incorrect value for dot_cross, expected 311886653, is {}",
                    msg.dot_cross
                );
                assert_eq!(
                    msg.dot_radial, -1111196507,
                    "incorrect value for dot_radial, expected -1111196507, is {}",
                    msg.dot_radial
                );
                assert_eq!(
                    msg.iod, 193,
                    "incorrect value for iod, expected 193, is {}",
                    msg.iod
                );
                assert_eq!(
                    msg.iod_ssr, 211,
                    "incorrect value for iod_ssr, expected 211, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.radial, -24141393,
                    "incorrect value for radial, expected -24141393, is {}",
                    msg.radial
                );
                assert_eq!(
                    msg.sid.code, 30,
                    "incorrect value for sid.code, expected 30, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 1,
                    "incorrect value for sid.sat, expected 1, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.time.tow, 3172954849,
                    "incorrect value for time.tow, expected 3172954849, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 7723,
                    "incorrect value for time.wn, expected 7723, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 194,
                    "incorrect value for update_interval, expected 194, is {}",
                    msg.update_interval
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrOrbitClockDepA"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_orbit_clock_dep_a() {
    {
        let json_input = r#"{"crc":64669,"length":47,"msg_type":1500,"payload":"4XIfvSseAR7C08GvoY/+OD/oB9hFAW6lfMS9G3RYBD0DlxKrky7GVfP14et7tdI=","preamble":85,"sender":42529,"time":{"tow":3172954849,"wn":7723},"sid":{"sat":1,"code":30},"update_interval":194,"iod_ssr":211,"iod":193,"radial":-24141393,"along":132661048,"cross":1845577176,"dot_radial":-1111196507,"dot_along":72905755,"dot_cross":311886653,"c0":-970026069,"c1":-503975083,"c2":-759858197}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrOrbitClockDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5dc,
                    "Incorrect message type, expected 0x5dc, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xa621,
                    "incorrect sender id, expected 0xa621, is {sender_id}"
                );
                assert_eq!(
                    msg.along, 132661048,
                    "incorrect value for along, expected 132661048, is {}",
                    msg.along
                );
                assert_eq!(
                    msg.c0, -970026069,
                    "incorrect value for c0, expected -970026069, is {}",
                    msg.c0
                );
                assert_eq!(
                    msg.c1, -503975083,
                    "incorrect value for c1, expected -503975083, is {}",
                    msg.c1
                );
                assert_eq!(
                    msg.c2, -759858197,
                    "incorrect value for c2, expected -759858197, is {}",
                    msg.c2
                );
                assert_eq!(
                    msg.cross, 1845577176,
                    "incorrect value for cross, expected 1845577176, is {}",
                    msg.cross
                );
                assert_eq!(
                    msg.dot_along, 72905755,
                    "incorrect value for dot_along, expected 72905755, is {}",
                    msg.dot_along
                );
                assert_eq!(
                    msg.dot_cross, 311886653,
                    "incorrect value for dot_cross, expected 311886653, is {}",
                    msg.dot_cross
                );
                assert_eq!(
                    msg.dot_radial, -1111196507,
                    "incorrect value for dot_radial, expected -1111196507, is {}",
                    msg.dot_radial
                );
                assert_eq!(
                    msg.iod, 193,
                    "incorrect value for iod, expected 193, is {}",
                    msg.iod
                );
                assert_eq!(
                    msg.iod_ssr, 211,
                    "incorrect value for iod_ssr, expected 211, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.radial, -24141393,
                    "incorrect value for radial, expected -24141393, is {}",
                    msg.radial
                );
                assert_eq!(
                    msg.sid.code, 30,
                    "incorrect value for sid.code, expected 30, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 1,
                    "incorrect value for sid.sat, expected 1, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.time.tow, 3172954849,
                    "incorrect value for time.tow, expected 3172954849, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 7723,
                    "incorrect value for time.wn, expected 7723, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 194,
                    "incorrect value for update_interval, expected 194, is {}",
                    msg.update_interval
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrOrbitClockDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_orbit_clock_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_orbit_clock_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 220, 5, 33, 166, 47, 225, 114, 31, 189, 43, 30, 1, 30, 194, 211, 193, 175, 161,
            143, 254, 56, 63, 232, 7, 216, 69, 1, 110, 165, 124, 196, 189, 27, 116, 88, 4, 61, 3,
            151, 18, 171, 147, 46, 198, 85, 243, 245, 225, 235, 123, 181, 210, 157, 252,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrOrbitClockDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrOrbitClockDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5dc,
                    "Incorrect message type, expected 0x5dc, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xa621,
                    "incorrect sender id, expected 0xa621, is {sender_id}"
                );
                assert_eq!(
                    msg.along, 132661048,
                    "incorrect value for along, expected 132661048, is {}",
                    msg.along
                );
                assert_eq!(
                    msg.c0, -970026069,
                    "incorrect value for c0, expected -970026069, is {}",
                    msg.c0
                );
                assert_eq!(
                    msg.c1, -503975083,
                    "incorrect value for c1, expected -503975083, is {}",
                    msg.c1
                );
                assert_eq!(
                    msg.c2, -759858197,
                    "incorrect value for c2, expected -759858197, is {}",
                    msg.c2
                );
                assert_eq!(
                    msg.cross, 1845577176,
                    "incorrect value for cross, expected 1845577176, is {}",
                    msg.cross
                );
                assert_eq!(
                    msg.dot_along, 72905755,
                    "incorrect value for dot_along, expected 72905755, is {}",
                    msg.dot_along
                );
                assert_eq!(
                    msg.dot_cross, 311886653,
                    "incorrect value for dot_cross, expected 311886653, is {}",
                    msg.dot_cross
                );
                assert_eq!(
                    msg.dot_radial, -1111196507,
                    "incorrect value for dot_radial, expected -1111196507, is {}",
                    msg.dot_radial
                );
                assert_eq!(
                    msg.iod, 193,
                    "incorrect value for iod, expected 193, is {}",
                    msg.iod
                );
                assert_eq!(
                    msg.iod_ssr, 211,
                    "incorrect value for iod_ssr, expected 211, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.radial, -24141393,
                    "incorrect value for radial, expected -24141393, is {}",
                    msg.radial
                );
                assert_eq!(
                    msg.sid.code, 30,
                    "incorrect value for sid.code, expected 30, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 1,
                    "incorrect value for sid.sat, expected 1, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.time.tow, 3172954849,
                    "incorrect value for time.tow, expected 3172954849, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 7723,
                    "incorrect value for time.wn, expected 7723, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 194,
                    "incorrect value for update_interval, expected 194, is {}",
                    msg.update_interval
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrOrbitClockDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
