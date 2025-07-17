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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApc.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_ssr_msg_ssr_satellite_apc() {
    {
        let mut payload = Cursor::new(vec![
            85, 5, 6, 0, 0, 41, 127, 58, 9, 0, 174, 8, 1, 2, 3, 2, 0, 4, 61, 0, 1, 0, 255, 255,
            217, 2, 11, 10, 8, 5, 1, 252, 248, 246, 246, 246, 249, 252, 0, 6, 12, 22, 30, 41, 41,
            41, 41, 144, 161,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrSatelliteApc(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x605,
                    "Incorrect message type, expected 0x605, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0,
                    "incorrect sender id, expected 0x0, is {sender_id}"
                );
                assert_eq!(
                    msg.apc[0].pco[0], 1,
                    "incorrect value for apc[0].pco[0], expected 1, is {}",
                    msg.apc[0].pco[0]
                );
                assert_eq!(
                    msg.apc[0].pco[1], -1,
                    "incorrect value for apc[0].pco[1], expected -1, is {}",
                    msg.apc[0].pco[1]
                );
                assert_eq!(
                    msg.apc[0].pco[2], 729,
                    "incorrect value for apc[0].pco[2], expected 729, is {}",
                    msg.apc[0].pco[2]
                );
                assert_eq!(
                    msg.apc[0].pcv[0], 11,
                    "incorrect value for apc[0].pcv[0], expected 11, is {}",
                    msg.apc[0].pcv[0]
                );
                assert_eq!(
                    msg.apc[0].pcv[1], 10,
                    "incorrect value for apc[0].pcv[1], expected 10, is {}",
                    msg.apc[0].pcv[1]
                );
                assert_eq!(
                    msg.apc[0].pcv[2], 8,
                    "incorrect value for apc[0].pcv[2], expected 8, is {}",
                    msg.apc[0].pcv[2]
                );
                assert_eq!(
                    msg.apc[0].pcv[3], 5,
                    "incorrect value for apc[0].pcv[3], expected 5, is {}",
                    msg.apc[0].pcv[3]
                );
                assert_eq!(
                    msg.apc[0].pcv[4], 1,
                    "incorrect value for apc[0].pcv[4], expected 1, is {}",
                    msg.apc[0].pcv[4]
                );
                assert_eq!(
                    msg.apc[0].pcv[5], -4,
                    "incorrect value for apc[0].pcv[5], expected -4, is {}",
                    msg.apc[0].pcv[5]
                );
                assert_eq!(
                    msg.apc[0].pcv[6], -8,
                    "incorrect value for apc[0].pcv[6], expected -8, is {}",
                    msg.apc[0].pcv[6]
                );
                assert_eq!(
                    msg.apc[0].pcv[7], -10,
                    "incorrect value for apc[0].pcv[7], expected -10, is {}",
                    msg.apc[0].pcv[7]
                );
                assert_eq!(
                    msg.apc[0].pcv[8], -10,
                    "incorrect value for apc[0].pcv[8], expected -10, is {}",
                    msg.apc[0].pcv[8]
                );
                assert_eq!(
                    msg.apc[0].pcv[9], -10,
                    "incorrect value for apc[0].pcv[9], expected -10, is {}",
                    msg.apc[0].pcv[9]
                );
                assert_eq!(
                    msg.apc[0].pcv[10], -7,
                    "incorrect value for apc[0].pcv[10], expected -7, is {}",
                    msg.apc[0].pcv[10]
                );
                assert_eq!(
                    msg.apc[0].pcv[11], -4,
                    "incorrect value for apc[0].pcv[11], expected -4, is {}",
                    msg.apc[0].pcv[11]
                );
                assert_eq!(
                    msg.apc[0].pcv[12], 0,
                    "incorrect value for apc[0].pcv[12], expected 0, is {}",
                    msg.apc[0].pcv[12]
                );
                assert_eq!(
                    msg.apc[0].pcv[13], 6,
                    "incorrect value for apc[0].pcv[13], expected 6, is {}",
                    msg.apc[0].pcv[13]
                );
                assert_eq!(
                    msg.apc[0].pcv[14], 12,
                    "incorrect value for apc[0].pcv[14], expected 12, is {}",
                    msg.apc[0].pcv[14]
                );
                assert_eq!(
                    msg.apc[0].pcv[15], 22,
                    "incorrect value for apc[0].pcv[15], expected 22, is {}",
                    msg.apc[0].pcv[15]
                );
                assert_eq!(
                    msg.apc[0].pcv[16], 30,
                    "incorrect value for apc[0].pcv[16], expected 30, is {}",
                    msg.apc[0].pcv[16]
                );
                assert_eq!(
                    msg.apc[0].pcv[17], 41,
                    "incorrect value for apc[0].pcv[17], expected 41, is {}",
                    msg.apc[0].pcv[17]
                );
                assert_eq!(
                    msg.apc[0].pcv[18], 41,
                    "incorrect value for apc[0].pcv[18], expected 41, is {}",
                    msg.apc[0].pcv[18]
                );
                assert_eq!(
                    msg.apc[0].pcv[19], 41,
                    "incorrect value for apc[0].pcv[19], expected 41, is {}",
                    msg.apc[0].pcv[19]
                );
                assert_eq!(
                    msg.apc[0].pcv[20], 41,
                    "incorrect value for apc[0].pcv[20], expected 41, is {}",
                    msg.apc[0].pcv[20]
                );
                assert_eq!(
                    msg.apc[0].sat_info, 4,
                    "incorrect value for apc[0].sat_info, expected 4, is {}",
                    msg.apc[0].sat_info
                );
                assert_eq!(
                    msg.apc[0].sid.code, 0,
                    "incorrect value for apc[0].sid.code, expected 0, is {}",
                    msg.apc[0].sid.code
                );
                assert_eq!(
                    msg.apc[0].sid.sat, 2,
                    "incorrect value for apc[0].sid.sat, expected 2, is {}",
                    msg.apc[0].sid.sat
                );
                assert_eq!(
                    msg.apc[0].svn, 61,
                    "incorrect value for apc[0].svn, expected 61, is {}",
                    msg.apc[0].svn
                );
                assert_eq!(
                    msg.iod_ssr, 3,
                    "incorrect value for iod_ssr, expected 3, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.sol_id, 2,
                    "incorrect value for sol_id, expected 2, is {}",
                    msg.sol_id
                );
                assert_eq!(
                    msg.time.tow, 604799,
                    "incorrect value for time.tow, expected 604799, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 2222,
                    "incorrect value for time.wn, expected 2222, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 1,
                    "incorrect value for update_interval, expected 1, is {}",
                    msg.update_interval
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrSatelliteApc"),
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
fn test_json2sbp_auto_check_sbp_ssr_msg_ssr_satellite_apc() {
    {
        let json_input = r#"{"preamble": 85, "msg_type": 1541, "sender": 0, "length": 41, "payload": "fzoJAK4IAQIDAgAEPQABAP//2QILCggFAfz49vb2+fwABgwWHikpKSk=", "crc": 41360, "time": {"tow": 604799, "wn": 2222}, "update_interval": 1, "sol_id": 2, "iod_ssr": 3, "apc": [{"sid": {"sat": 2, "code": 0}, "sat_info": 4, "svn": 61, "pco": [1, -1, 729], "pcv": [11, 10, 8, 5, 1, -4, -8, -10, -10, -10, -7, -4, 0, 6, 12, 22, 30, 41, 41, 41, 41]}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSsrSatelliteApc(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x605,
                    "Incorrect message type, expected 0x605, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0,
                    "incorrect sender id, expected 0x0, is {sender_id}"
                );
                assert_eq!(
                    msg.apc[0].pco[0], 1,
                    "incorrect value for apc[0].pco[0], expected 1, is {}",
                    msg.apc[0].pco[0]
                );
                assert_eq!(
                    msg.apc[0].pco[1], -1,
                    "incorrect value for apc[0].pco[1], expected -1, is {}",
                    msg.apc[0].pco[1]
                );
                assert_eq!(
                    msg.apc[0].pco[2], 729,
                    "incorrect value for apc[0].pco[2], expected 729, is {}",
                    msg.apc[0].pco[2]
                );
                assert_eq!(
                    msg.apc[0].pcv[0], 11,
                    "incorrect value for apc[0].pcv[0], expected 11, is {}",
                    msg.apc[0].pcv[0]
                );
                assert_eq!(
                    msg.apc[0].pcv[1], 10,
                    "incorrect value for apc[0].pcv[1], expected 10, is {}",
                    msg.apc[0].pcv[1]
                );
                assert_eq!(
                    msg.apc[0].pcv[2], 8,
                    "incorrect value for apc[0].pcv[2], expected 8, is {}",
                    msg.apc[0].pcv[2]
                );
                assert_eq!(
                    msg.apc[0].pcv[3], 5,
                    "incorrect value for apc[0].pcv[3], expected 5, is {}",
                    msg.apc[0].pcv[3]
                );
                assert_eq!(
                    msg.apc[0].pcv[4], 1,
                    "incorrect value for apc[0].pcv[4], expected 1, is {}",
                    msg.apc[0].pcv[4]
                );
                assert_eq!(
                    msg.apc[0].pcv[5], -4,
                    "incorrect value for apc[0].pcv[5], expected -4, is {}",
                    msg.apc[0].pcv[5]
                );
                assert_eq!(
                    msg.apc[0].pcv[6], -8,
                    "incorrect value for apc[0].pcv[6], expected -8, is {}",
                    msg.apc[0].pcv[6]
                );
                assert_eq!(
                    msg.apc[0].pcv[7], -10,
                    "incorrect value for apc[0].pcv[7], expected -10, is {}",
                    msg.apc[0].pcv[7]
                );
                assert_eq!(
                    msg.apc[0].pcv[8], -10,
                    "incorrect value for apc[0].pcv[8], expected -10, is {}",
                    msg.apc[0].pcv[8]
                );
                assert_eq!(
                    msg.apc[0].pcv[9], -10,
                    "incorrect value for apc[0].pcv[9], expected -10, is {}",
                    msg.apc[0].pcv[9]
                );
                assert_eq!(
                    msg.apc[0].pcv[10], -7,
                    "incorrect value for apc[0].pcv[10], expected -7, is {}",
                    msg.apc[0].pcv[10]
                );
                assert_eq!(
                    msg.apc[0].pcv[11], -4,
                    "incorrect value for apc[0].pcv[11], expected -4, is {}",
                    msg.apc[0].pcv[11]
                );
                assert_eq!(
                    msg.apc[0].pcv[12], 0,
                    "incorrect value for apc[0].pcv[12], expected 0, is {}",
                    msg.apc[0].pcv[12]
                );
                assert_eq!(
                    msg.apc[0].pcv[13], 6,
                    "incorrect value for apc[0].pcv[13], expected 6, is {}",
                    msg.apc[0].pcv[13]
                );
                assert_eq!(
                    msg.apc[0].pcv[14], 12,
                    "incorrect value for apc[0].pcv[14], expected 12, is {}",
                    msg.apc[0].pcv[14]
                );
                assert_eq!(
                    msg.apc[0].pcv[15], 22,
                    "incorrect value for apc[0].pcv[15], expected 22, is {}",
                    msg.apc[0].pcv[15]
                );
                assert_eq!(
                    msg.apc[0].pcv[16], 30,
                    "incorrect value for apc[0].pcv[16], expected 30, is {}",
                    msg.apc[0].pcv[16]
                );
                assert_eq!(
                    msg.apc[0].pcv[17], 41,
                    "incorrect value for apc[0].pcv[17], expected 41, is {}",
                    msg.apc[0].pcv[17]
                );
                assert_eq!(
                    msg.apc[0].pcv[18], 41,
                    "incorrect value for apc[0].pcv[18], expected 41, is {}",
                    msg.apc[0].pcv[18]
                );
                assert_eq!(
                    msg.apc[0].pcv[19], 41,
                    "incorrect value for apc[0].pcv[19], expected 41, is {}",
                    msg.apc[0].pcv[19]
                );
                assert_eq!(
                    msg.apc[0].pcv[20], 41,
                    "incorrect value for apc[0].pcv[20], expected 41, is {}",
                    msg.apc[0].pcv[20]
                );
                assert_eq!(
                    msg.apc[0].sat_info, 4,
                    "incorrect value for apc[0].sat_info, expected 4, is {}",
                    msg.apc[0].sat_info
                );
                assert_eq!(
                    msg.apc[0].sid.code, 0,
                    "incorrect value for apc[0].sid.code, expected 0, is {}",
                    msg.apc[0].sid.code
                );
                assert_eq!(
                    msg.apc[0].sid.sat, 2,
                    "incorrect value for apc[0].sid.sat, expected 2, is {}",
                    msg.apc[0].sid.sat
                );
                assert_eq!(
                    msg.apc[0].svn, 61,
                    "incorrect value for apc[0].svn, expected 61, is {}",
                    msg.apc[0].svn
                );
                assert_eq!(
                    msg.iod_ssr, 3,
                    "incorrect value for iod_ssr, expected 3, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.sol_id, 2,
                    "incorrect value for sol_id, expected 2, is {}",
                    msg.sol_id
                );
                assert_eq!(
                    msg.time.tow, 604799,
                    "incorrect value for time.tow, expected 604799, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 2222,
                    "incorrect value for time.wn, expected 2222, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 1,
                    "incorrect value for update_interval, expected 1, is {}",
                    msg.update_interval
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrSatelliteApc"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_ssr_msg_ssr_satellite_apc`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_ssr_msg_ssr_satellite_apc() {
    {
        let mut payload = Cursor::new(vec![
            85, 5, 6, 0, 0, 41, 127, 58, 9, 0, 174, 8, 1, 2, 3, 2, 0, 4, 61, 0, 1, 0, 255, 255,
            217, 2, 11, 10, 8, 5, 1, 252, 248, 246, 246, 246, 249, 252, 0, 6, 12, 22, 30, 41, 41,
            41, 41, 144, 161,
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
        let sbp_msg = sbp::messages::Sbp::MsgSsrSatelliteApc(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSsrSatelliteApc(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x605,
                    "Incorrect message type, expected 0x605, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0,
                    "incorrect sender id, expected 0x0, is {sender_id}"
                );
                assert_eq!(
                    msg.apc[0].pco[0], 1,
                    "incorrect value for apc[0].pco[0], expected 1, is {}",
                    msg.apc[0].pco[0]
                );
                assert_eq!(
                    msg.apc[0].pco[1], -1,
                    "incorrect value for apc[0].pco[1], expected -1, is {}",
                    msg.apc[0].pco[1]
                );
                assert_eq!(
                    msg.apc[0].pco[2], 729,
                    "incorrect value for apc[0].pco[2], expected 729, is {}",
                    msg.apc[0].pco[2]
                );
                assert_eq!(
                    msg.apc[0].pcv[0], 11,
                    "incorrect value for apc[0].pcv[0], expected 11, is {}",
                    msg.apc[0].pcv[0]
                );
                assert_eq!(
                    msg.apc[0].pcv[1], 10,
                    "incorrect value for apc[0].pcv[1], expected 10, is {}",
                    msg.apc[0].pcv[1]
                );
                assert_eq!(
                    msg.apc[0].pcv[2], 8,
                    "incorrect value for apc[0].pcv[2], expected 8, is {}",
                    msg.apc[0].pcv[2]
                );
                assert_eq!(
                    msg.apc[0].pcv[3], 5,
                    "incorrect value for apc[0].pcv[3], expected 5, is {}",
                    msg.apc[0].pcv[3]
                );
                assert_eq!(
                    msg.apc[0].pcv[4], 1,
                    "incorrect value for apc[0].pcv[4], expected 1, is {}",
                    msg.apc[0].pcv[4]
                );
                assert_eq!(
                    msg.apc[0].pcv[5], -4,
                    "incorrect value for apc[0].pcv[5], expected -4, is {}",
                    msg.apc[0].pcv[5]
                );
                assert_eq!(
                    msg.apc[0].pcv[6], -8,
                    "incorrect value for apc[0].pcv[6], expected -8, is {}",
                    msg.apc[0].pcv[6]
                );
                assert_eq!(
                    msg.apc[0].pcv[7], -10,
                    "incorrect value for apc[0].pcv[7], expected -10, is {}",
                    msg.apc[0].pcv[7]
                );
                assert_eq!(
                    msg.apc[0].pcv[8], -10,
                    "incorrect value for apc[0].pcv[8], expected -10, is {}",
                    msg.apc[0].pcv[8]
                );
                assert_eq!(
                    msg.apc[0].pcv[9], -10,
                    "incorrect value for apc[0].pcv[9], expected -10, is {}",
                    msg.apc[0].pcv[9]
                );
                assert_eq!(
                    msg.apc[0].pcv[10], -7,
                    "incorrect value for apc[0].pcv[10], expected -7, is {}",
                    msg.apc[0].pcv[10]
                );
                assert_eq!(
                    msg.apc[0].pcv[11], -4,
                    "incorrect value for apc[0].pcv[11], expected -4, is {}",
                    msg.apc[0].pcv[11]
                );
                assert_eq!(
                    msg.apc[0].pcv[12], 0,
                    "incorrect value for apc[0].pcv[12], expected 0, is {}",
                    msg.apc[0].pcv[12]
                );
                assert_eq!(
                    msg.apc[0].pcv[13], 6,
                    "incorrect value for apc[0].pcv[13], expected 6, is {}",
                    msg.apc[0].pcv[13]
                );
                assert_eq!(
                    msg.apc[0].pcv[14], 12,
                    "incorrect value for apc[0].pcv[14], expected 12, is {}",
                    msg.apc[0].pcv[14]
                );
                assert_eq!(
                    msg.apc[0].pcv[15], 22,
                    "incorrect value for apc[0].pcv[15], expected 22, is {}",
                    msg.apc[0].pcv[15]
                );
                assert_eq!(
                    msg.apc[0].pcv[16], 30,
                    "incorrect value for apc[0].pcv[16], expected 30, is {}",
                    msg.apc[0].pcv[16]
                );
                assert_eq!(
                    msg.apc[0].pcv[17], 41,
                    "incorrect value for apc[0].pcv[17], expected 41, is {}",
                    msg.apc[0].pcv[17]
                );
                assert_eq!(
                    msg.apc[0].pcv[18], 41,
                    "incorrect value for apc[0].pcv[18], expected 41, is {}",
                    msg.apc[0].pcv[18]
                );
                assert_eq!(
                    msg.apc[0].pcv[19], 41,
                    "incorrect value for apc[0].pcv[19], expected 41, is {}",
                    msg.apc[0].pcv[19]
                );
                assert_eq!(
                    msg.apc[0].pcv[20], 41,
                    "incorrect value for apc[0].pcv[20], expected 41, is {}",
                    msg.apc[0].pcv[20]
                );
                assert_eq!(
                    msg.apc[0].sat_info, 4,
                    "incorrect value for apc[0].sat_info, expected 4, is {}",
                    msg.apc[0].sat_info
                );
                assert_eq!(
                    msg.apc[0].sid.code, 0,
                    "incorrect value for apc[0].sid.code, expected 0, is {}",
                    msg.apc[0].sid.code
                );
                assert_eq!(
                    msg.apc[0].sid.sat, 2,
                    "incorrect value for apc[0].sid.sat, expected 2, is {}",
                    msg.apc[0].sid.sat
                );
                assert_eq!(
                    msg.apc[0].svn, 61,
                    "incorrect value for apc[0].svn, expected 61, is {}",
                    msg.apc[0].svn
                );
                assert_eq!(
                    msg.iod_ssr, 3,
                    "incorrect value for iod_ssr, expected 3, is {}",
                    msg.iod_ssr
                );
                assert_eq!(
                    msg.sol_id, 2,
                    "incorrect value for sol_id, expected 2, is {}",
                    msg.sol_id
                );
                assert_eq!(
                    msg.time.tow, 604799,
                    "incorrect value for time.tow, expected 604799, is {}",
                    msg.time.tow
                );
                assert_eq!(
                    msg.time.wn, 2222,
                    "incorrect value for time.wn, expected 2222, is {}",
                    msg.time.wn
                );
                assert_eq!(
                    msg.update_interval, 1,
                    "incorrect value for update_interval, expected 1, is {}",
                    msg.update_interval
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSsrSatelliteApc"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
