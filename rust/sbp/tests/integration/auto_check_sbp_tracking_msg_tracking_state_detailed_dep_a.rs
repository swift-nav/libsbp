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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 33, 0, 155, 110, 57, 46, 31, 180, 38, 219, 0, 0, 0, 133, 100, 71, 94, 192, 2, 160,
            207, 212, 255, 135, 139, 62, 62, 179, 83, 227, 245, 134, 160, 204, 78, 95, 255, 38, 59,
            161, 15, 255, 86, 189, 248, 31, 191, 136, 194, 124, 23, 15, 91, 249, 117, 142, 90, 219,
            67, 25, 83, 62, 122, 100,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDetailedDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x21,
                    "Incorrect message type, expected 0x21, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6e9b,
                    "incorrect sender id, expected 0x6e9b, is {sender_id}"
                );
                assert_eq!(
                    msg.l.f, 204,
                    "incorrect value for l.f, expected 204, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, -1601767965,
                    "incorrect value for l.i, expected -1601767965, is {}",
                    msg.l.i
                );
                assert_eq!(
                    msg.p, 1044286343,
                    "incorrect value for p, expected 1044286343, is {}",
                    msg.p
                );
                assert_eq!(
                    msg.p_std, 21427,
                    "incorrect value for p_std, expected 21427, is {}",
                    msg.p_std
                );
                assert_eq!(
                    msg.acceleration, -114,
                    "incorrect value for acceleration, expected -114, is {}",
                    msg.acceleration
                );
                assert_eq!(
                    msg.clock_drift, 23311,
                    "incorrect value for clock_drift, expected 23311, is {}",
                    msg.clock_drift
                );
                assert_eq!(
                    msg.clock_offset, 6012,
                    "incorrect value for clock_offset, expected 6012, is {}",
                    msg.clock_offset
                );
                assert_eq!(
                    msg.cn0, 78,
                    "incorrect value for cn0, expected 78, is {}",
                    msg.cn0
                );
                assert_eq!(
                    msg.corr_spacing, 30201,
                    "incorrect value for corr_spacing, expected 30201, is {}",
                    msg.corr_spacing
                );
                assert_eq!(
                    msg.doppler, 1459556257,
                    "incorrect value for doppler, expected 1459556257, is {}",
                    msg.doppler
                );
                assert_eq!(
                    msg.doppler_std, 63677,
                    "incorrect value for doppler_std, expected 63677, is {}",
                    msg.doppler_std
                );
                assert_eq!(
                    msg.lock, 65375,
                    "incorrect value for lock, expected 65375, is {}",
                    msg.lock
                );
                assert_eq!(
                    msg.misc_flags, 62,
                    "incorrect value for misc_flags, expected 62, is {}",
                    msg.misc_flags
                );
                assert_eq!(
                    msg.nav_flags, 25,
                    "incorrect value for nav_flags, expected 25, is {}",
                    msg.nav_flags
                );
                assert_eq!(
                    msg.pset_flags, 83,
                    "incorrect value for pset_flags, expected 83, is {}",
                    msg.pset_flags
                );
                assert_eq!(
                    msg.recv_time, 941247176494,
                    "incorrect value for recv_time, expected 941247176494, is {}",
                    msg.recv_time
                );
                assert_eq!(
                    msg.sid.code, 59,
                    "incorrect value for sid.code, expected 59, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 38,
                    "incorrect value for sid.sat, expected 38, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.sync_flags, 90,
                    "incorrect value for sync_flags, expected 90, is {}",
                    msg.sync_flags
                );
                assert_eq!(
                    msg.tot.ns_residual, -811597120,
                    "incorrect value for tot.ns_residual, expected -811597120, is {}",
                    msg.tot.ns_residual
                );
                assert_eq!(
                    msg.tot.tow, 1581737093,
                    "incorrect value for tot.tow, expected 1581737093, is {}",
                    msg.tot.tow
                );
                assert_eq!(
                    msg.tot.wn, 65492,
                    "incorrect value for tot.wn, expected 65492, is {}",
                    msg.tot.wn
                );
                assert_eq!(
                    msg.tow_flags, 219,
                    "incorrect value for tow_flags, expected 219, is {}",
                    msg.tow_flags
                );
                assert_eq!(
                    msg.track_flags, 67,
                    "incorrect value for track_flags, expected 67, is {}",
                    msg.track_flags
                );
                assert_eq!(
                    msg.uptime, 3263741727,
                    "incorrect value for uptime, expected 3263741727, is {}",
                    msg.uptime
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDetailedDepA"),
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
fn test_json2sbp_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_a() {
    {
        let json_input = r#"{"crc":25722,"length":57,"msg_type":33,"payload":"Lh+0JtsAAACFZEdewAKgz9T/h4s+PrNT4/WGoMxOX/8mO6EP/1a9+B+/iMJ8Fw9b+XWOWttDGVM+","preamble":85,"sender":28315,"recv_time":941247176494,"tot":{"tow":1581737093,"ns_residual":-811597120,"wn":65492},"P":1044286343,"P_std":21427,"L":{"i":-1601767965,"f":204},"cn0":78,"lock":65375,"sid":{"sat":38,"code":59},"doppler":1459556257,"doppler_std":63677,"uptime":3263741727,"clock_offset":6012,"clock_drift":23311,"corr_spacing":30201,"acceleration":-114,"sync_flags":90,"tow_flags":219,"track_flags":67,"nav_flags":25,"pset_flags":83,"misc_flags":62}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingStateDetailedDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x21,
                    "Incorrect message type, expected 0x21, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6e9b,
                    "incorrect sender id, expected 0x6e9b, is {sender_id}"
                );
                assert_eq!(
                    msg.l.f, 204,
                    "incorrect value for l.f, expected 204, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, -1601767965,
                    "incorrect value for l.i, expected -1601767965, is {}",
                    msg.l.i
                );
                assert_eq!(
                    msg.p, 1044286343,
                    "incorrect value for p, expected 1044286343, is {}",
                    msg.p
                );
                assert_eq!(
                    msg.p_std, 21427,
                    "incorrect value for p_std, expected 21427, is {}",
                    msg.p_std
                );
                assert_eq!(
                    msg.acceleration, -114,
                    "incorrect value for acceleration, expected -114, is {}",
                    msg.acceleration
                );
                assert_eq!(
                    msg.clock_drift, 23311,
                    "incorrect value for clock_drift, expected 23311, is {}",
                    msg.clock_drift
                );
                assert_eq!(
                    msg.clock_offset, 6012,
                    "incorrect value for clock_offset, expected 6012, is {}",
                    msg.clock_offset
                );
                assert_eq!(
                    msg.cn0, 78,
                    "incorrect value for cn0, expected 78, is {}",
                    msg.cn0
                );
                assert_eq!(
                    msg.corr_spacing, 30201,
                    "incorrect value for corr_spacing, expected 30201, is {}",
                    msg.corr_spacing
                );
                assert_eq!(
                    msg.doppler, 1459556257,
                    "incorrect value for doppler, expected 1459556257, is {}",
                    msg.doppler
                );
                assert_eq!(
                    msg.doppler_std, 63677,
                    "incorrect value for doppler_std, expected 63677, is {}",
                    msg.doppler_std
                );
                assert_eq!(
                    msg.lock, 65375,
                    "incorrect value for lock, expected 65375, is {}",
                    msg.lock
                );
                assert_eq!(
                    msg.misc_flags, 62,
                    "incorrect value for misc_flags, expected 62, is {}",
                    msg.misc_flags
                );
                assert_eq!(
                    msg.nav_flags, 25,
                    "incorrect value for nav_flags, expected 25, is {}",
                    msg.nav_flags
                );
                assert_eq!(
                    msg.pset_flags, 83,
                    "incorrect value for pset_flags, expected 83, is {}",
                    msg.pset_flags
                );
                assert_eq!(
                    msg.recv_time, 941247176494,
                    "incorrect value for recv_time, expected 941247176494, is {}",
                    msg.recv_time
                );
                assert_eq!(
                    msg.sid.code, 59,
                    "incorrect value for sid.code, expected 59, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 38,
                    "incorrect value for sid.sat, expected 38, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.sync_flags, 90,
                    "incorrect value for sync_flags, expected 90, is {}",
                    msg.sync_flags
                );
                assert_eq!(
                    msg.tot.ns_residual, -811597120,
                    "incorrect value for tot.ns_residual, expected -811597120, is {}",
                    msg.tot.ns_residual
                );
                assert_eq!(
                    msg.tot.tow, 1581737093,
                    "incorrect value for tot.tow, expected 1581737093, is {}",
                    msg.tot.tow
                );
                assert_eq!(
                    msg.tot.wn, 65492,
                    "incorrect value for tot.wn, expected 65492, is {}",
                    msg.tot.wn
                );
                assert_eq!(
                    msg.tow_flags, 219,
                    "incorrect value for tow_flags, expected 219, is {}",
                    msg.tow_flags
                );
                assert_eq!(
                    msg.track_flags, 67,
                    "incorrect value for track_flags, expected 67, is {}",
                    msg.track_flags
                );
                assert_eq!(
                    msg.uptime, 3263741727,
                    "incorrect value for uptime, expected 3263741727, is {}",
                    msg.uptime
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDetailedDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 33, 0, 155, 110, 57, 46, 31, 180, 38, 219, 0, 0, 0, 133, 100, 71, 94, 192, 2, 160,
            207, 212, 255, 135, 139, 62, 62, 179, 83, 227, 245, 134, 160, 204, 78, 95, 255, 38, 59,
            161, 15, 255, 86, 189, 248, 31, 191, 136, 194, 124, 23, 15, 91, 249, 117, 142, 90, 219,
            67, 25, 83, 62, 122, 100,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingStateDetailedDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDetailedDepA(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x21,
                    "Incorrect message type, expected 0x21, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x6e9b,
                    "incorrect sender id, expected 0x6e9b, is {sender_id}"
                );
                assert_eq!(
                    msg.l.f, 204,
                    "incorrect value for l.f, expected 204, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, -1601767965,
                    "incorrect value for l.i, expected -1601767965, is {}",
                    msg.l.i
                );
                assert_eq!(
                    msg.p, 1044286343,
                    "incorrect value for p, expected 1044286343, is {}",
                    msg.p
                );
                assert_eq!(
                    msg.p_std, 21427,
                    "incorrect value for p_std, expected 21427, is {}",
                    msg.p_std
                );
                assert_eq!(
                    msg.acceleration, -114,
                    "incorrect value for acceleration, expected -114, is {}",
                    msg.acceleration
                );
                assert_eq!(
                    msg.clock_drift, 23311,
                    "incorrect value for clock_drift, expected 23311, is {}",
                    msg.clock_drift
                );
                assert_eq!(
                    msg.clock_offset, 6012,
                    "incorrect value for clock_offset, expected 6012, is {}",
                    msg.clock_offset
                );
                assert_eq!(
                    msg.cn0, 78,
                    "incorrect value for cn0, expected 78, is {}",
                    msg.cn0
                );
                assert_eq!(
                    msg.corr_spacing, 30201,
                    "incorrect value for corr_spacing, expected 30201, is {}",
                    msg.corr_spacing
                );
                assert_eq!(
                    msg.doppler, 1459556257,
                    "incorrect value for doppler, expected 1459556257, is {}",
                    msg.doppler
                );
                assert_eq!(
                    msg.doppler_std, 63677,
                    "incorrect value for doppler_std, expected 63677, is {}",
                    msg.doppler_std
                );
                assert_eq!(
                    msg.lock, 65375,
                    "incorrect value for lock, expected 65375, is {}",
                    msg.lock
                );
                assert_eq!(
                    msg.misc_flags, 62,
                    "incorrect value for misc_flags, expected 62, is {}",
                    msg.misc_flags
                );
                assert_eq!(
                    msg.nav_flags, 25,
                    "incorrect value for nav_flags, expected 25, is {}",
                    msg.nav_flags
                );
                assert_eq!(
                    msg.pset_flags, 83,
                    "incorrect value for pset_flags, expected 83, is {}",
                    msg.pset_flags
                );
                assert_eq!(
                    msg.recv_time, 941247176494,
                    "incorrect value for recv_time, expected 941247176494, is {}",
                    msg.recv_time
                );
                assert_eq!(
                    msg.sid.code, 59,
                    "incorrect value for sid.code, expected 59, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 38,
                    "incorrect value for sid.sat, expected 38, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.sync_flags, 90,
                    "incorrect value for sync_flags, expected 90, is {}",
                    msg.sync_flags
                );
                assert_eq!(
                    msg.tot.ns_residual, -811597120,
                    "incorrect value for tot.ns_residual, expected -811597120, is {}",
                    msg.tot.ns_residual
                );
                assert_eq!(
                    msg.tot.tow, 1581737093,
                    "incorrect value for tot.tow, expected 1581737093, is {}",
                    msg.tot.tow
                );
                assert_eq!(
                    msg.tot.wn, 65492,
                    "incorrect value for tot.wn, expected 65492, is {}",
                    msg.tot.wn
                );
                assert_eq!(
                    msg.tow_flags, 219,
                    "incorrect value for tow_flags, expected 219, is {}",
                    msg.tow_flags
                );
                assert_eq!(
                    msg.track_flags, 67,
                    "incorrect value for track_flags, expected 67, is {}",
                    msg.track_flags
                );
                assert_eq!(
                    msg.uptime, 3263741727,
                    "incorrect value for uptime, expected 3263741727, is {}",
                    msg.uptime
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDetailedDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
