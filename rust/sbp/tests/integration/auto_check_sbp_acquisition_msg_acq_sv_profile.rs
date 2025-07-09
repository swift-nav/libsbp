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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqSvProfile.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_acquisition_msg_acq_sv_profile() {
    {
        let mut payload = Cursor::new(vec![
            85, 46, 0, 195, 4, 99, 7, 13, 38, 0, 97, 22, 0, 174, 0, 52, 0, 0, 0, 49, 0, 0, 0, 61,
            0, 0, 0, 147, 0, 0, 0, 47, 0, 0, 0, 140, 0, 0, 0, 166, 210, 59, 0, 253, 23, 1, 121, 0,
            190, 0, 0, 0, 175, 0, 0, 0, 175, 0, 0, 0, 142, 0, 0, 0, 237, 0, 0, 0, 12, 0, 0, 0, 126,
            88, 21, 0, 153, 24, 0, 8, 0, 130, 0, 0, 0, 172, 0, 0, 0, 91, 0, 0, 0, 191, 0, 0, 0, 84,
            0, 0, 0, 82, 0, 0, 0, 168, 177,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqSvProfile(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2e,
                    "Incorrect message type, expected 0x2e, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.acq_sv_profile[0].bin_width, 174,
                    "incorrect value for acq_sv_profile[0].bin_width, expected 174, is {}",
                    msg.acq_sv_profile[0].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf, 47,
                    "incorrect value for acq_sv_profile[0].cf, expected 47, is {}",
                    msg.acq_sv_profile[0].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf_max, 147,
                    "incorrect value for acq_sv_profile[0].cf_max, expected 147, is {}",
                    msg.acq_sv_profile[0].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf_min, 61,
                    "incorrect value for acq_sv_profile[0].cf_min, expected 61, is {}",
                    msg.acq_sv_profile[0].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cn0, 38,
                    "incorrect value for acq_sv_profile[0].cn0, expected 38, is {}",
                    msg.acq_sv_profile[0].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cp, 140,
                    "incorrect value for acq_sv_profile[0].cp, expected 140, is {}",
                    msg.acq_sv_profile[0].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[0].int_time, 97,
                    "incorrect value for acq_sv_profile[0].int_time, expected 97, is {}",
                    msg.acq_sv_profile[0].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[0].job_type, 7,
                    "incorrect value for acq_sv_profile[0].job_type, expected 7, is {}",
                    msg.acq_sv_profile[0].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.code, 0,
                    "incorrect value for acq_sv_profile[0].sid.code, expected 0, is {}",
                    msg.acq_sv_profile[0].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.sat, 22,
                    "incorrect value for acq_sv_profile[0].sid.sat, expected 22, is {}",
                    msg.acq_sv_profile[0].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[0].status, 13,
                    "incorrect value for acq_sv_profile[0].status, expected 13, is {}",
                    msg.acq_sv_profile[0].status
                );
                assert_eq!(
                    msg.acq_sv_profile[0].time_spent, 49,
                    "incorrect value for acq_sv_profile[0].time_spent, expected 49, is {}",
                    msg.acq_sv_profile[0].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[0].timestamp, 52,
                    "incorrect value for acq_sv_profile[0].timestamp, expected 52, is {}",
                    msg.acq_sv_profile[0].timestamp
                );
                assert_eq!(
                    msg.acq_sv_profile[1].bin_width, 121,
                    "incorrect value for acq_sv_profile[1].bin_width, expected 121, is {}",
                    msg.acq_sv_profile[1].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf, 237,
                    "incorrect value for acq_sv_profile[1].cf, expected 237, is {}",
                    msg.acq_sv_profile[1].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf_max, 142,
                    "incorrect value for acq_sv_profile[1].cf_max, expected 142, is {}",
                    msg.acq_sv_profile[1].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf_min, 175,
                    "incorrect value for acq_sv_profile[1].cf_min, expected 175, is {}",
                    msg.acq_sv_profile[1].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cn0, 59,
                    "incorrect value for acq_sv_profile[1].cn0, expected 59, is {}",
                    msg.acq_sv_profile[1].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cp, 12,
                    "incorrect value for acq_sv_profile[1].cp, expected 12, is {}",
                    msg.acq_sv_profile[1].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[1].int_time, 253,
                    "incorrect value for acq_sv_profile[1].int_time, expected 253, is {}",
                    msg.acq_sv_profile[1].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[1].job_type, 166,
                    "incorrect value for acq_sv_profile[1].job_type, expected 166, is {}",
                    msg.acq_sv_profile[1].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.code, 1,
                    "incorrect value for acq_sv_profile[1].sid.code, expected 1, is {}",
                    msg.acq_sv_profile[1].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.sat, 23,
                    "incorrect value for acq_sv_profile[1].sid.sat, expected 23, is {}",
                    msg.acq_sv_profile[1].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[1].status, 210,
                    "incorrect value for acq_sv_profile[1].status, expected 210, is {}",
                    msg.acq_sv_profile[1].status
                );
                assert_eq!(
                    msg.acq_sv_profile[1].time_spent, 175,
                    "incorrect value for acq_sv_profile[1].time_spent, expected 175, is {}",
                    msg.acq_sv_profile[1].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[1].timestamp, 190,
                    "incorrect value for acq_sv_profile[1].timestamp, expected 190, is {}",
                    msg.acq_sv_profile[1].timestamp
                );
                assert_eq!(
                    msg.acq_sv_profile[2].bin_width, 8,
                    "incorrect value for acq_sv_profile[2].bin_width, expected 8, is {}",
                    msg.acq_sv_profile[2].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf, 84,
                    "incorrect value for acq_sv_profile[2].cf, expected 84, is {}",
                    msg.acq_sv_profile[2].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf_max, 191,
                    "incorrect value for acq_sv_profile[2].cf_max, expected 191, is {}",
                    msg.acq_sv_profile[2].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf_min, 91,
                    "incorrect value for acq_sv_profile[2].cf_min, expected 91, is {}",
                    msg.acq_sv_profile[2].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cn0, 21,
                    "incorrect value for acq_sv_profile[2].cn0, expected 21, is {}",
                    msg.acq_sv_profile[2].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cp, 82,
                    "incorrect value for acq_sv_profile[2].cp, expected 82, is {}",
                    msg.acq_sv_profile[2].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[2].int_time, 153,
                    "incorrect value for acq_sv_profile[2].int_time, expected 153, is {}",
                    msg.acq_sv_profile[2].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[2].job_type, 126,
                    "incorrect value for acq_sv_profile[2].job_type, expected 126, is {}",
                    msg.acq_sv_profile[2].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.code, 0,
                    "incorrect value for acq_sv_profile[2].sid.code, expected 0, is {}",
                    msg.acq_sv_profile[2].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.sat, 24,
                    "incorrect value for acq_sv_profile[2].sid.sat, expected 24, is {}",
                    msg.acq_sv_profile[2].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[2].status, 88,
                    "incorrect value for acq_sv_profile[2].status, expected 88, is {}",
                    msg.acq_sv_profile[2].status
                );
                assert_eq!(
                    msg.acq_sv_profile[2].time_spent, 172,
                    "incorrect value for acq_sv_profile[2].time_spent, expected 172, is {}",
                    msg.acq_sv_profile[2].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[2].timestamp, 130,
                    "incorrect value for acq_sv_profile[2].timestamp, expected 130, is {}",
                    msg.acq_sv_profile[2].timestamp
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqSvProfile"),
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
fn test_json2sbp_auto_check_sbp_acquisition_msg_acq_sv_profile() {
    {
        let json_input = r#"{"crc":45480,"length":99,"msg_type":46,"payload":"Bw0mAGEWAK4ANAAAADEAAAA9AAAAkwAAAC8AAACMAAAAptI7AP0XAXkAvgAAAK8AAACvAAAAjgAAAO0AAAAMAAAAflgVAJkYAAgAggAAAKwAAABbAAAAvwAAAFQAAABSAAAA","preamble":85,"sender":1219,"acq_sv_profile":[{"job_type":7,"status":13,"cn0":38,"int_time":97,"sid":{"sat":22,"code":0},"bin_width":174,"timestamp":52,"time_spent":49,"cf_min":61,"cf_max":147,"cf":47,"cp":140},{"job_type":166,"status":210,"cn0":59,"int_time":253,"sid":{"sat":23,"code":1},"bin_width":121,"timestamp":190,"time_spent":175,"cf_min":175,"cf_max":142,"cf":237,"cp":12},{"job_type":126,"status":88,"cn0":21,"int_time":153,"sid":{"sat":24,"code":0},"bin_width":8,"timestamp":130,"time_spent":172,"cf_min":91,"cf_max":191,"cf":84,"cp":82}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqSvProfile(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2e,
                    "Incorrect message type, expected 0x2e, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.acq_sv_profile[0].bin_width, 174,
                    "incorrect value for acq_sv_profile[0].bin_width, expected 174, is {}",
                    msg.acq_sv_profile[0].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf, 47,
                    "incorrect value for acq_sv_profile[0].cf, expected 47, is {}",
                    msg.acq_sv_profile[0].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf_max, 147,
                    "incorrect value for acq_sv_profile[0].cf_max, expected 147, is {}",
                    msg.acq_sv_profile[0].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf_min, 61,
                    "incorrect value for acq_sv_profile[0].cf_min, expected 61, is {}",
                    msg.acq_sv_profile[0].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cn0, 38,
                    "incorrect value for acq_sv_profile[0].cn0, expected 38, is {}",
                    msg.acq_sv_profile[0].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cp, 140,
                    "incorrect value for acq_sv_profile[0].cp, expected 140, is {}",
                    msg.acq_sv_profile[0].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[0].int_time, 97,
                    "incorrect value for acq_sv_profile[0].int_time, expected 97, is {}",
                    msg.acq_sv_profile[0].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[0].job_type, 7,
                    "incorrect value for acq_sv_profile[0].job_type, expected 7, is {}",
                    msg.acq_sv_profile[0].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.code, 0,
                    "incorrect value for acq_sv_profile[0].sid.code, expected 0, is {}",
                    msg.acq_sv_profile[0].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.sat, 22,
                    "incorrect value for acq_sv_profile[0].sid.sat, expected 22, is {}",
                    msg.acq_sv_profile[0].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[0].status, 13,
                    "incorrect value for acq_sv_profile[0].status, expected 13, is {}",
                    msg.acq_sv_profile[0].status
                );
                assert_eq!(
                    msg.acq_sv_profile[0].time_spent, 49,
                    "incorrect value for acq_sv_profile[0].time_spent, expected 49, is {}",
                    msg.acq_sv_profile[0].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[0].timestamp, 52,
                    "incorrect value for acq_sv_profile[0].timestamp, expected 52, is {}",
                    msg.acq_sv_profile[0].timestamp
                );
                assert_eq!(
                    msg.acq_sv_profile[1].bin_width, 121,
                    "incorrect value for acq_sv_profile[1].bin_width, expected 121, is {}",
                    msg.acq_sv_profile[1].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf, 237,
                    "incorrect value for acq_sv_profile[1].cf, expected 237, is {}",
                    msg.acq_sv_profile[1].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf_max, 142,
                    "incorrect value for acq_sv_profile[1].cf_max, expected 142, is {}",
                    msg.acq_sv_profile[1].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf_min, 175,
                    "incorrect value for acq_sv_profile[1].cf_min, expected 175, is {}",
                    msg.acq_sv_profile[1].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cn0, 59,
                    "incorrect value for acq_sv_profile[1].cn0, expected 59, is {}",
                    msg.acq_sv_profile[1].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cp, 12,
                    "incorrect value for acq_sv_profile[1].cp, expected 12, is {}",
                    msg.acq_sv_profile[1].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[1].int_time, 253,
                    "incorrect value for acq_sv_profile[1].int_time, expected 253, is {}",
                    msg.acq_sv_profile[1].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[1].job_type, 166,
                    "incorrect value for acq_sv_profile[1].job_type, expected 166, is {}",
                    msg.acq_sv_profile[1].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.code, 1,
                    "incorrect value for acq_sv_profile[1].sid.code, expected 1, is {}",
                    msg.acq_sv_profile[1].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.sat, 23,
                    "incorrect value for acq_sv_profile[1].sid.sat, expected 23, is {}",
                    msg.acq_sv_profile[1].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[1].status, 210,
                    "incorrect value for acq_sv_profile[1].status, expected 210, is {}",
                    msg.acq_sv_profile[1].status
                );
                assert_eq!(
                    msg.acq_sv_profile[1].time_spent, 175,
                    "incorrect value for acq_sv_profile[1].time_spent, expected 175, is {}",
                    msg.acq_sv_profile[1].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[1].timestamp, 190,
                    "incorrect value for acq_sv_profile[1].timestamp, expected 190, is {}",
                    msg.acq_sv_profile[1].timestamp
                );
                assert_eq!(
                    msg.acq_sv_profile[2].bin_width, 8,
                    "incorrect value for acq_sv_profile[2].bin_width, expected 8, is {}",
                    msg.acq_sv_profile[2].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf, 84,
                    "incorrect value for acq_sv_profile[2].cf, expected 84, is {}",
                    msg.acq_sv_profile[2].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf_max, 191,
                    "incorrect value for acq_sv_profile[2].cf_max, expected 191, is {}",
                    msg.acq_sv_profile[2].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf_min, 91,
                    "incorrect value for acq_sv_profile[2].cf_min, expected 91, is {}",
                    msg.acq_sv_profile[2].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cn0, 21,
                    "incorrect value for acq_sv_profile[2].cn0, expected 21, is {}",
                    msg.acq_sv_profile[2].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cp, 82,
                    "incorrect value for acq_sv_profile[2].cp, expected 82, is {}",
                    msg.acq_sv_profile[2].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[2].int_time, 153,
                    "incorrect value for acq_sv_profile[2].int_time, expected 153, is {}",
                    msg.acq_sv_profile[2].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[2].job_type, 126,
                    "incorrect value for acq_sv_profile[2].job_type, expected 126, is {}",
                    msg.acq_sv_profile[2].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.code, 0,
                    "incorrect value for acq_sv_profile[2].sid.code, expected 0, is {}",
                    msg.acq_sv_profile[2].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.sat, 24,
                    "incorrect value for acq_sv_profile[2].sid.sat, expected 24, is {}",
                    msg.acq_sv_profile[2].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[2].status, 88,
                    "incorrect value for acq_sv_profile[2].status, expected 88, is {}",
                    msg.acq_sv_profile[2].status
                );
                assert_eq!(
                    msg.acq_sv_profile[2].time_spent, 172,
                    "incorrect value for acq_sv_profile[2].time_spent, expected 172, is {}",
                    msg.acq_sv_profile[2].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[2].timestamp, 130,
                    "incorrect value for acq_sv_profile[2].timestamp, expected 130, is {}",
                    msg.acq_sv_profile[2].timestamp
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqSvProfile"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_acquisition_msg_acq_sv_profile`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_acquisition_msg_acq_sv_profile() {
    {
        let mut payload = Cursor::new(vec![
            85, 46, 0, 195, 4, 99, 7, 13, 38, 0, 97, 22, 0, 174, 0, 52, 0, 0, 0, 49, 0, 0, 0, 61,
            0, 0, 0, 147, 0, 0, 0, 47, 0, 0, 0, 140, 0, 0, 0, 166, 210, 59, 0, 253, 23, 1, 121, 0,
            190, 0, 0, 0, 175, 0, 0, 0, 175, 0, 0, 0, 142, 0, 0, 0, 237, 0, 0, 0, 12, 0, 0, 0, 126,
            88, 21, 0, 153, 24, 0, 8, 0, 130, 0, 0, 0, 172, 0, 0, 0, 91, 0, 0, 0, 191, 0, 0, 0, 84,
            0, 0, 0, 82, 0, 0, 0, 168, 177,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqSvProfile(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqSvProfile(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x2e,
                    "Incorrect message type, expected 0x2e, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.acq_sv_profile[0].bin_width, 174,
                    "incorrect value for acq_sv_profile[0].bin_width, expected 174, is {}",
                    msg.acq_sv_profile[0].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf, 47,
                    "incorrect value for acq_sv_profile[0].cf, expected 47, is {}",
                    msg.acq_sv_profile[0].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf_max, 147,
                    "incorrect value for acq_sv_profile[0].cf_max, expected 147, is {}",
                    msg.acq_sv_profile[0].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf_min, 61,
                    "incorrect value for acq_sv_profile[0].cf_min, expected 61, is {}",
                    msg.acq_sv_profile[0].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cn0, 38,
                    "incorrect value for acq_sv_profile[0].cn0, expected 38, is {}",
                    msg.acq_sv_profile[0].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cp, 140,
                    "incorrect value for acq_sv_profile[0].cp, expected 140, is {}",
                    msg.acq_sv_profile[0].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[0].int_time, 97,
                    "incorrect value for acq_sv_profile[0].int_time, expected 97, is {}",
                    msg.acq_sv_profile[0].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[0].job_type, 7,
                    "incorrect value for acq_sv_profile[0].job_type, expected 7, is {}",
                    msg.acq_sv_profile[0].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.code, 0,
                    "incorrect value for acq_sv_profile[0].sid.code, expected 0, is {}",
                    msg.acq_sv_profile[0].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.sat, 22,
                    "incorrect value for acq_sv_profile[0].sid.sat, expected 22, is {}",
                    msg.acq_sv_profile[0].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[0].status, 13,
                    "incorrect value for acq_sv_profile[0].status, expected 13, is {}",
                    msg.acq_sv_profile[0].status
                );
                assert_eq!(
                    msg.acq_sv_profile[0].time_spent, 49,
                    "incorrect value for acq_sv_profile[0].time_spent, expected 49, is {}",
                    msg.acq_sv_profile[0].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[0].timestamp, 52,
                    "incorrect value for acq_sv_profile[0].timestamp, expected 52, is {}",
                    msg.acq_sv_profile[0].timestamp
                );
                assert_eq!(
                    msg.acq_sv_profile[1].bin_width, 121,
                    "incorrect value for acq_sv_profile[1].bin_width, expected 121, is {}",
                    msg.acq_sv_profile[1].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf, 237,
                    "incorrect value for acq_sv_profile[1].cf, expected 237, is {}",
                    msg.acq_sv_profile[1].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf_max, 142,
                    "incorrect value for acq_sv_profile[1].cf_max, expected 142, is {}",
                    msg.acq_sv_profile[1].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf_min, 175,
                    "incorrect value for acq_sv_profile[1].cf_min, expected 175, is {}",
                    msg.acq_sv_profile[1].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cn0, 59,
                    "incorrect value for acq_sv_profile[1].cn0, expected 59, is {}",
                    msg.acq_sv_profile[1].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cp, 12,
                    "incorrect value for acq_sv_profile[1].cp, expected 12, is {}",
                    msg.acq_sv_profile[1].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[1].int_time, 253,
                    "incorrect value for acq_sv_profile[1].int_time, expected 253, is {}",
                    msg.acq_sv_profile[1].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[1].job_type, 166,
                    "incorrect value for acq_sv_profile[1].job_type, expected 166, is {}",
                    msg.acq_sv_profile[1].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.code, 1,
                    "incorrect value for acq_sv_profile[1].sid.code, expected 1, is {}",
                    msg.acq_sv_profile[1].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.sat, 23,
                    "incorrect value for acq_sv_profile[1].sid.sat, expected 23, is {}",
                    msg.acq_sv_profile[1].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[1].status, 210,
                    "incorrect value for acq_sv_profile[1].status, expected 210, is {}",
                    msg.acq_sv_profile[1].status
                );
                assert_eq!(
                    msg.acq_sv_profile[1].time_spent, 175,
                    "incorrect value for acq_sv_profile[1].time_spent, expected 175, is {}",
                    msg.acq_sv_profile[1].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[1].timestamp, 190,
                    "incorrect value for acq_sv_profile[1].timestamp, expected 190, is {}",
                    msg.acq_sv_profile[1].timestamp
                );
                assert_eq!(
                    msg.acq_sv_profile[2].bin_width, 8,
                    "incorrect value for acq_sv_profile[2].bin_width, expected 8, is {}",
                    msg.acq_sv_profile[2].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf, 84,
                    "incorrect value for acq_sv_profile[2].cf, expected 84, is {}",
                    msg.acq_sv_profile[2].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf_max, 191,
                    "incorrect value for acq_sv_profile[2].cf_max, expected 191, is {}",
                    msg.acq_sv_profile[2].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf_min, 91,
                    "incorrect value for acq_sv_profile[2].cf_min, expected 91, is {}",
                    msg.acq_sv_profile[2].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cn0, 21,
                    "incorrect value for acq_sv_profile[2].cn0, expected 21, is {}",
                    msg.acq_sv_profile[2].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cp, 82,
                    "incorrect value for acq_sv_profile[2].cp, expected 82, is {}",
                    msg.acq_sv_profile[2].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[2].int_time, 153,
                    "incorrect value for acq_sv_profile[2].int_time, expected 153, is {}",
                    msg.acq_sv_profile[2].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[2].job_type, 126,
                    "incorrect value for acq_sv_profile[2].job_type, expected 126, is {}",
                    msg.acq_sv_profile[2].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.code, 0,
                    "incorrect value for acq_sv_profile[2].sid.code, expected 0, is {}",
                    msg.acq_sv_profile[2].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.sat, 24,
                    "incorrect value for acq_sv_profile[2].sid.sat, expected 24, is {}",
                    msg.acq_sv_profile[2].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[2].status, 88,
                    "incorrect value for acq_sv_profile[2].status, expected 88, is {}",
                    msg.acq_sv_profile[2].status
                );
                assert_eq!(
                    msg.acq_sv_profile[2].time_spent, 172,
                    "incorrect value for acq_sv_profile[2].time_spent, expected 172, is {}",
                    msg.acq_sv_profile[2].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[2].timestamp, 130,
                    "incorrect value for acq_sv_profile[2].timestamp, expected 130, is {}",
                    msg.acq_sv_profile[2].timestamp
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqSvProfile"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
