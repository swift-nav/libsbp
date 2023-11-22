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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClock.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_orbit_clock() {
    {
        let mut payload = Cursor::new(vec![
            85, 221, 5, 53, 229, 50, 83, 208, 102, 207, 164, 29, 203, 212, 236, 255, 152, 233, 207,
            55, 94, 54, 58, 128, 68, 27, 117, 176, 110, 251, 61, 244, 122, 50, 95, 52, 144, 232,
            24, 10, 37, 127, 163, 66, 177, 105, 156, 245, 10, 249, 107, 218, 17, 186, 56, 72, 14,
            22,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrOrbitClock(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5dd,
                    "Incorrect message type, expected 0x5dd, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xe535,
                    "incorrect sender id, expected 0xe535, is {sender_id}"
                );
                assert_eq!(
                    msg.along, -1334502588,
                    "incorrect value for along, expected -1334502588, is {}",
                    msg.along
                );
                assert_eq!(
                    msg.c0, -174298703,
                    "incorrect value for c0, expected -174298703, is {}",
                    msg.c0
                );
                assert_eq!(
                    msg.c1, -630458102,
                    "incorrect value for c1, expected -630458102, is {}",
                    msg.c1
                );
                assert_eq!(
                    msg.c2, 1211677201,
                    "incorrect value for c2, expected 1211677201, is {}",
                    msg.c2
                );
                assert_eq!(
                    msg.cross, -197264530,
                    "incorrect value for cross, expected -197264530, is {}",
                    msg.cross
                );
                assert_eq!(
                    msg.dot_along, 169404560,
                    "incorrect value for dot_along, expected 169404560, is {}",
                    msg.dot_along
                );
                assert_eq!(
                    msg.dot_cross, 1118011173,
                    "incorrect value for dot_cross, expected 1118011173, is {}",
                    msg.dot_cross
                );
                assert_eq!(
                    msg.dot_radial, 878654074,
                    "incorrect value for dot_radial, expected 878654074, is {}",
                    msg.dot_radial
                );
                assert_eq!(
                    msg.iod, 936372632,
                    "incorrect value for iod, expected 936372632, is {}",
                    msg.iod
                );
                assert_eq!(
                    msg.iod_ssr, 255,
                    "incorrect value for iod_ssr, expected 255, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.radial, -2143668642,
                    "incorrect value for radial, expected -2143668642, is {}",
                    msg.radial
                );
                assert_eq!(
                    msg.sid.code, 212,
                    "incorrect value for sid.code, expected 212, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 203,
                    "incorrect value for sid.sat, expected 203, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.time.tow, 3479621715,
                    "incorrect value for time.tow, expected 3479621715, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 7588,
                    "incorrect value for time.wn, expected 7588, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 236,
                    "incorrect value for update_interval, expected 236, is {}",
                    msg.update_interval
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrOrbitClock"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_orbit_clock() {
    {
        let json_input = r#"{"crc":5646,"length":50,"msg_type":1501,"payload":"U9Bmz6Qdy9Ts/5jpzzdeNjqARBt1sG77PfR6Ml80kOgYCiV/o0KxaZz1Cvlr2hG6OEg=","preamble":85,"sender":58677,"time":{"tow":3479621715,"wn":7588},"sid":{"sat":203,"code":212},"update_interval":236,"iod_ssr":255,"iod":936372632,"radial":-2143668642,"along":-1334502588,"cross":-197264530,"dot_radial":878654074,"dot_along":169404560,"dot_cross":1118011173,"c0":-174298703,"c1":-630458102,"c2":1211677201}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrOrbitClock(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5dd,
                    "Incorrect message type, expected 0x5dd, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xe535,
                    "incorrect sender id, expected 0xe535, is {sender_id}"
                );
                assert_eq!(
                    msg.along, -1334502588,
                    "incorrect value for along, expected -1334502588, is {}",
                    msg.along
                );
                assert_eq!(
                    msg.c0, -174298703,
                    "incorrect value for c0, expected -174298703, is {}",
                    msg.c0
                );
                assert_eq!(
                    msg.c1, -630458102,
                    "incorrect value for c1, expected -630458102, is {}",
                    msg.c1
                );
                assert_eq!(
                    msg.c2, 1211677201,
                    "incorrect value for c2, expected 1211677201, is {}",
                    msg.c2
                );
                assert_eq!(
                    msg.cross, -197264530,
                    "incorrect value for cross, expected -197264530, is {}",
                    msg.cross
                );
                assert_eq!(
                    msg.dot_along, 169404560,
                    "incorrect value for dot_along, expected 169404560, is {}",
                    msg.dot_along
                );
                assert_eq!(
                    msg.dot_cross, 1118011173,
                    "incorrect value for dot_cross, expected 1118011173, is {}",
                    msg.dot_cross
                );
                assert_eq!(
                    msg.dot_radial, 878654074,
                    "incorrect value for dot_radial, expected 878654074, is {}",
                    msg.dot_radial
                );
                assert_eq!(
                    msg.iod, 936372632,
                    "incorrect value for iod, expected 936372632, is {}",
                    msg.iod
                );
                assert_eq!(
                    msg.iod_ssr, 255,
                    "incorrect value for iod_ssr, expected 255, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.radial, -2143668642,
                    "incorrect value for radial, expected -2143668642, is {}",
                    msg.radial
                );
                assert_eq!(
                    msg.sid.code, 212,
                    "incorrect value for sid.code, expected 212, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 203,
                    "incorrect value for sid.sat, expected 203, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.time.tow, 3479621715,
                    "incorrect value for time.tow, expected 3479621715, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 7588,
                    "incorrect value for time.wn, expected 7588, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 236,
                    "incorrect value for update_interval, expected 236, is {}",
                    msg.update_interval
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrOrbitClock"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_orbit_clock`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_orbit_clock() {
    {
        let mut payload = Cursor::new(vec![
            85, 221, 5, 53, 229, 50, 83, 208, 102, 207, 164, 29, 203, 212, 236, 255, 152, 233, 207,
            55, 94, 54, 58, 128, 68, 27, 117, 176, 110, 251, 61, 244, 122, 50, 95, 52, 144, 232,
            24, 10, 37, 127, 163, 66, 177, 105, 156, 245, 10, 249, 107, 218, 17, 186, 56, 72, 14,
            22,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrOrbitClock(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrOrbitClock(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x5dd,
                    "Incorrect message type, expected 0x5dd, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xe535,
                    "incorrect sender id, expected 0xe535, is {sender_id}"
                );
                assert_eq!(
                    msg.along, -1334502588,
                    "incorrect value for along, expected -1334502588, is {}",
                    msg.along
                );
                assert_eq!(
                    msg.c0, -174298703,
                    "incorrect value for c0, expected -174298703, is {}",
                    msg.c0
                );
                assert_eq!(
                    msg.c1, -630458102,
                    "incorrect value for c1, expected -630458102, is {}",
                    msg.c1
                );
                assert_eq!(
                    msg.c2, 1211677201,
                    "incorrect value for c2, expected 1211677201, is {}",
                    msg.c2
                );
                assert_eq!(
                    msg.cross, -197264530,
                    "incorrect value for cross, expected -197264530, is {}",
                    msg.cross
                );
                assert_eq!(
                    msg.dot_along, 169404560,
                    "incorrect value for dot_along, expected 169404560, is {}",
                    msg.dot_along
                );
                assert_eq!(
                    msg.dot_cross, 1118011173,
                    "incorrect value for dot_cross, expected 1118011173, is {}",
                    msg.dot_cross
                );
                assert_eq!(
                    msg.dot_radial, 878654074,
                    "incorrect value for dot_radial, expected 878654074, is {}",
                    msg.dot_radial
                );
                assert_eq!(
                    msg.iod, 936372632,
                    "incorrect value for iod, expected 936372632, is {}",
                    msg.iod
                );
                assert_eq!(
                    msg.iod_ssr, 255,
                    "incorrect value for iod_ssr, expected 255, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.radial, -2143668642,
                    "incorrect value for radial, expected -2143668642, is {}",
                    msg.radial
                );
                assert_eq!(
                    msg.sid.code, 212,
                    "incorrect value for sid.code, expected 212, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 203,
                    "incorrect value for sid.sat, expected 203, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.time.tow, 3479621715,
                    "incorrect value for time.tow, expected 3479621715, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 7588,
                    "incorrect value for time.wn, expected 7588, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 236,
                    "incorrect value for update_interval, expected 236, is {}",
                    msg.update_interval
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrOrbitClock"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
