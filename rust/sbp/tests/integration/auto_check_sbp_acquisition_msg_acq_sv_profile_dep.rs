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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqSvProfileDep.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_acquisition_msg_acq_sv_profile_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 30, 0, 195, 4, 105, 67, 103, 151, 0, 12, 22, 0, 0, 0, 187, 0, 91, 0, 0, 0, 75, 0,
            0, 0, 132, 0, 0, 0, 36, 0, 0, 0, 60, 0, 0, 0, 241, 0, 0, 0, 238, 38, 111, 0, 179, 23,
            0, 1, 0, 176, 0, 166, 0, 0, 0, 234, 0, 0, 0, 155, 0, 0, 0, 24, 0, 0, 0, 212, 0, 0, 0,
            247, 0, 0, 0, 142, 213, 68, 0, 53, 24, 0, 0, 0, 52, 0, 49, 0, 0, 0, 245, 0, 0, 0, 76,
            0, 0, 0, 248, 0, 0, 0, 212, 0, 0, 0, 101, 0, 0, 0, 67, 132,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqSvProfileDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x1e,
                    "Incorrect message type, expected 0x1e, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.acq_sv_profile[0].bin_width, 187,
                    "incorrect value for acq_sv_profile[0].bin_width, expected 187, is {}",
                    msg.acq_sv_profile[0].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf, 60,
                    "incorrect value for acq_sv_profile[0].cf, expected 60, is {}",
                    msg.acq_sv_profile[0].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf_max, 36,
                    "incorrect value for acq_sv_profile[0].cf_max, expected 36, is {}",
                    msg.acq_sv_profile[0].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf_min, 132,
                    "incorrect value for acq_sv_profile[0].cf_min, expected 132, is {}",
                    msg.acq_sv_profile[0].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cn0, 151,
                    "incorrect value for acq_sv_profile[0].cn0, expected 151, is {}",
                    msg.acq_sv_profile[0].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cp, 241,
                    "incorrect value for acq_sv_profile[0].cp, expected 241, is {}",
                    msg.acq_sv_profile[0].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[0].int_time, 12,
                    "incorrect value for acq_sv_profile[0].int_time, expected 12, is {}",
                    msg.acq_sv_profile[0].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[0].job_type, 67,
                    "incorrect value for acq_sv_profile[0].job_type, expected 67, is {}",
                    msg.acq_sv_profile[0].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.code, 0,
                    "incorrect value for acq_sv_profile[0].sid.code, expected 0, is {}",
                    msg.acq_sv_profile[0].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.reserved, 0,
                    "incorrect value for acq_sv_profile[0].sid.reserved, expected 0, is {}",
                    msg.acq_sv_profile[0].sid.reserved
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.sat, 22,
                    "incorrect value for acq_sv_profile[0].sid.sat, expected 22, is {}",
                    msg.acq_sv_profile[0].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[0].status, 103,
                    "incorrect value for acq_sv_profile[0].status, expected 103, is {}",
                    msg.acq_sv_profile[0].status
                );
                assert_eq!(
                    msg.acq_sv_profile[0].time_spent, 75,
                    "incorrect value for acq_sv_profile[0].time_spent, expected 75, is {}",
                    msg.acq_sv_profile[0].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[0].timestamp, 91,
                    "incorrect value for acq_sv_profile[0].timestamp, expected 91, is {}",
                    msg.acq_sv_profile[0].timestamp
                );
                assert_eq!(
                    msg.acq_sv_profile[1].bin_width, 176,
                    "incorrect value for acq_sv_profile[1].bin_width, expected 176, is {}",
                    msg.acq_sv_profile[1].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf, 212,
                    "incorrect value for acq_sv_profile[1].cf, expected 212, is {}",
                    msg.acq_sv_profile[1].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf_max, 24,
                    "incorrect value for acq_sv_profile[1].cf_max, expected 24, is {}",
                    msg.acq_sv_profile[1].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf_min, 155,
                    "incorrect value for acq_sv_profile[1].cf_min, expected 155, is {}",
                    msg.acq_sv_profile[1].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cn0, 111,
                    "incorrect value for acq_sv_profile[1].cn0, expected 111, is {}",
                    msg.acq_sv_profile[1].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cp, 247,
                    "incorrect value for acq_sv_profile[1].cp, expected 247, is {}",
                    msg.acq_sv_profile[1].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[1].int_time, 179,
                    "incorrect value for acq_sv_profile[1].int_time, expected 179, is {}",
                    msg.acq_sv_profile[1].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[1].job_type, 238,
                    "incorrect value for acq_sv_profile[1].job_type, expected 238, is {}",
                    msg.acq_sv_profile[1].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.code, 1,
                    "incorrect value for acq_sv_profile[1].sid.code, expected 1, is {}",
                    msg.acq_sv_profile[1].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.reserved, 0,
                    "incorrect value for acq_sv_profile[1].sid.reserved, expected 0, is {}",
                    msg.acq_sv_profile[1].sid.reserved
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.sat, 23,
                    "incorrect value for acq_sv_profile[1].sid.sat, expected 23, is {}",
                    msg.acq_sv_profile[1].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[1].status, 38,
                    "incorrect value for acq_sv_profile[1].status, expected 38, is {}",
                    msg.acq_sv_profile[1].status
                );
                assert_eq!(
                    msg.acq_sv_profile[1].time_spent, 234,
                    "incorrect value for acq_sv_profile[1].time_spent, expected 234, is {}",
                    msg.acq_sv_profile[1].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[1].timestamp, 166,
                    "incorrect value for acq_sv_profile[1].timestamp, expected 166, is {}",
                    msg.acq_sv_profile[1].timestamp
                );
                assert_eq!(
                    msg.acq_sv_profile[2].bin_width, 52,
                    "incorrect value for acq_sv_profile[2].bin_width, expected 52, is {}",
                    msg.acq_sv_profile[2].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf, 212,
                    "incorrect value for acq_sv_profile[2].cf, expected 212, is {}",
                    msg.acq_sv_profile[2].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf_max, 248,
                    "incorrect value for acq_sv_profile[2].cf_max, expected 248, is {}",
                    msg.acq_sv_profile[2].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf_min, 76,
                    "incorrect value for acq_sv_profile[2].cf_min, expected 76, is {}",
                    msg.acq_sv_profile[2].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cn0, 68,
                    "incorrect value for acq_sv_profile[2].cn0, expected 68, is {}",
                    msg.acq_sv_profile[2].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cp, 101,
                    "incorrect value for acq_sv_profile[2].cp, expected 101, is {}",
                    msg.acq_sv_profile[2].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[2].int_time, 53,
                    "incorrect value for acq_sv_profile[2].int_time, expected 53, is {}",
                    msg.acq_sv_profile[2].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[2].job_type, 142,
                    "incorrect value for acq_sv_profile[2].job_type, expected 142, is {}",
                    msg.acq_sv_profile[2].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.code, 0,
                    "incorrect value for acq_sv_profile[2].sid.code, expected 0, is {}",
                    msg.acq_sv_profile[2].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.reserved, 0,
                    "incorrect value for acq_sv_profile[2].sid.reserved, expected 0, is {}",
                    msg.acq_sv_profile[2].sid.reserved
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.sat, 24,
                    "incorrect value for acq_sv_profile[2].sid.sat, expected 24, is {}",
                    msg.acq_sv_profile[2].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[2].status, 213,
                    "incorrect value for acq_sv_profile[2].status, expected 213, is {}",
                    msg.acq_sv_profile[2].status
                );
                assert_eq!(
                    msg.acq_sv_profile[2].time_spent, 245,
                    "incorrect value for acq_sv_profile[2].time_spent, expected 245, is {}",
                    msg.acq_sv_profile[2].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[2].timestamp, 49,
                    "incorrect value for acq_sv_profile[2].timestamp, expected 49, is {}",
                    msg.acq_sv_profile[2].timestamp
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqSvProfileDep"),
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
fn test_json2sbp_auto_check_sbp_acquisition_msg_acq_sv_profile_dep() {
    {
        let json_input = r#"{"crc":33859,"length":105,"msg_type":30,"payload":"Q2eXAAwWAAAAuwBbAAAASwAAAIQAAAAkAAAAPAAAAPEAAADuJm8AsxcAAQCwAKYAAADqAAAAmwAAABgAAADUAAAA9wAAAI7VRAA1GAAAADQAMQAAAPUAAABMAAAA+AAAANQAAABlAAAA","preamble":85,"sender":1219,"acq_sv_profile":[{"job_type":67,"status":103,"cn0":151,"int_time":12,"sid":{"sat":22,"code":0,"reserved":0},"bin_width":187,"timestamp":91,"time_spent":75,"cf_min":132,"cf_max":36,"cf":60,"cp":241},{"job_type":238,"status":38,"cn0":111,"int_time":179,"sid":{"sat":23,"code":1,"reserved":0},"bin_width":176,"timestamp":166,"time_spent":234,"cf_min":155,"cf_max":24,"cf":212,"cp":247},{"job_type":142,"status":213,"cn0":68,"int_time":53,"sid":{"sat":24,"code":0,"reserved":0},"bin_width":52,"timestamp":49,"time_spent":245,"cf_min":76,"cf_max":248,"cf":212,"cp":101}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqSvProfileDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x1e,
                    "Incorrect message type, expected 0x1e, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.acq_sv_profile[0].bin_width, 187,
                    "incorrect value for acq_sv_profile[0].bin_width, expected 187, is {}",
                    msg.acq_sv_profile[0].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf, 60,
                    "incorrect value for acq_sv_profile[0].cf, expected 60, is {}",
                    msg.acq_sv_profile[0].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf_max, 36,
                    "incorrect value for acq_sv_profile[0].cf_max, expected 36, is {}",
                    msg.acq_sv_profile[0].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf_min, 132,
                    "incorrect value for acq_sv_profile[0].cf_min, expected 132, is {}",
                    msg.acq_sv_profile[0].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cn0, 151,
                    "incorrect value for acq_sv_profile[0].cn0, expected 151, is {}",
                    msg.acq_sv_profile[0].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cp, 241,
                    "incorrect value for acq_sv_profile[0].cp, expected 241, is {}",
                    msg.acq_sv_profile[0].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[0].int_time, 12,
                    "incorrect value for acq_sv_profile[0].int_time, expected 12, is {}",
                    msg.acq_sv_profile[0].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[0].job_type, 67,
                    "incorrect value for acq_sv_profile[0].job_type, expected 67, is {}",
                    msg.acq_sv_profile[0].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.code, 0,
                    "incorrect value for acq_sv_profile[0].sid.code, expected 0, is {}",
                    msg.acq_sv_profile[0].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.reserved, 0,
                    "incorrect value for acq_sv_profile[0].sid.reserved, expected 0, is {}",
                    msg.acq_sv_profile[0].sid.reserved
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.sat, 22,
                    "incorrect value for acq_sv_profile[0].sid.sat, expected 22, is {}",
                    msg.acq_sv_profile[0].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[0].status, 103,
                    "incorrect value for acq_sv_profile[0].status, expected 103, is {}",
                    msg.acq_sv_profile[0].status
                );
                assert_eq!(
                    msg.acq_sv_profile[0].time_spent, 75,
                    "incorrect value for acq_sv_profile[0].time_spent, expected 75, is {}",
                    msg.acq_sv_profile[0].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[0].timestamp, 91,
                    "incorrect value for acq_sv_profile[0].timestamp, expected 91, is {}",
                    msg.acq_sv_profile[0].timestamp
                );
                assert_eq!(
                    msg.acq_sv_profile[1].bin_width, 176,
                    "incorrect value for acq_sv_profile[1].bin_width, expected 176, is {}",
                    msg.acq_sv_profile[1].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf, 212,
                    "incorrect value for acq_sv_profile[1].cf, expected 212, is {}",
                    msg.acq_sv_profile[1].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf_max, 24,
                    "incorrect value for acq_sv_profile[1].cf_max, expected 24, is {}",
                    msg.acq_sv_profile[1].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf_min, 155,
                    "incorrect value for acq_sv_profile[1].cf_min, expected 155, is {}",
                    msg.acq_sv_profile[1].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cn0, 111,
                    "incorrect value for acq_sv_profile[1].cn0, expected 111, is {}",
                    msg.acq_sv_profile[1].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cp, 247,
                    "incorrect value for acq_sv_profile[1].cp, expected 247, is {}",
                    msg.acq_sv_profile[1].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[1].int_time, 179,
                    "incorrect value for acq_sv_profile[1].int_time, expected 179, is {}",
                    msg.acq_sv_profile[1].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[1].job_type, 238,
                    "incorrect value for acq_sv_profile[1].job_type, expected 238, is {}",
                    msg.acq_sv_profile[1].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.code, 1,
                    "incorrect value for acq_sv_profile[1].sid.code, expected 1, is {}",
                    msg.acq_sv_profile[1].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.reserved, 0,
                    "incorrect value for acq_sv_profile[1].sid.reserved, expected 0, is {}",
                    msg.acq_sv_profile[1].sid.reserved
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.sat, 23,
                    "incorrect value for acq_sv_profile[1].sid.sat, expected 23, is {}",
                    msg.acq_sv_profile[1].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[1].status, 38,
                    "incorrect value for acq_sv_profile[1].status, expected 38, is {}",
                    msg.acq_sv_profile[1].status
                );
                assert_eq!(
                    msg.acq_sv_profile[1].time_spent, 234,
                    "incorrect value for acq_sv_profile[1].time_spent, expected 234, is {}",
                    msg.acq_sv_profile[1].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[1].timestamp, 166,
                    "incorrect value for acq_sv_profile[1].timestamp, expected 166, is {}",
                    msg.acq_sv_profile[1].timestamp
                );
                assert_eq!(
                    msg.acq_sv_profile[2].bin_width, 52,
                    "incorrect value for acq_sv_profile[2].bin_width, expected 52, is {}",
                    msg.acq_sv_profile[2].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf, 212,
                    "incorrect value for acq_sv_profile[2].cf, expected 212, is {}",
                    msg.acq_sv_profile[2].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf_max, 248,
                    "incorrect value for acq_sv_profile[2].cf_max, expected 248, is {}",
                    msg.acq_sv_profile[2].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf_min, 76,
                    "incorrect value for acq_sv_profile[2].cf_min, expected 76, is {}",
                    msg.acq_sv_profile[2].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cn0, 68,
                    "incorrect value for acq_sv_profile[2].cn0, expected 68, is {}",
                    msg.acq_sv_profile[2].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cp, 101,
                    "incorrect value for acq_sv_profile[2].cp, expected 101, is {}",
                    msg.acq_sv_profile[2].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[2].int_time, 53,
                    "incorrect value for acq_sv_profile[2].int_time, expected 53, is {}",
                    msg.acq_sv_profile[2].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[2].job_type, 142,
                    "incorrect value for acq_sv_profile[2].job_type, expected 142, is {}",
                    msg.acq_sv_profile[2].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.code, 0,
                    "incorrect value for acq_sv_profile[2].sid.code, expected 0, is {}",
                    msg.acq_sv_profile[2].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.reserved, 0,
                    "incorrect value for acq_sv_profile[2].sid.reserved, expected 0, is {}",
                    msg.acq_sv_profile[2].sid.reserved
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.sat, 24,
                    "incorrect value for acq_sv_profile[2].sid.sat, expected 24, is {}",
                    msg.acq_sv_profile[2].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[2].status, 213,
                    "incorrect value for acq_sv_profile[2].status, expected 213, is {}",
                    msg.acq_sv_profile[2].status
                );
                assert_eq!(
                    msg.acq_sv_profile[2].time_spent, 245,
                    "incorrect value for acq_sv_profile[2].time_spent, expected 245, is {}",
                    msg.acq_sv_profile[2].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[2].timestamp, 49,
                    "incorrect value for acq_sv_profile[2].timestamp, expected 49, is {}",
                    msg.acq_sv_profile[2].timestamp
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqSvProfileDep"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_acquisition_msg_acq_sv_profile_dep`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_acquisition_msg_acq_sv_profile_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 30, 0, 195, 4, 105, 67, 103, 151, 0, 12, 22, 0, 0, 0, 187, 0, 91, 0, 0, 0, 75, 0,
            0, 0, 132, 0, 0, 0, 36, 0, 0, 0, 60, 0, 0, 0, 241, 0, 0, 0, 238, 38, 111, 0, 179, 23,
            0, 1, 0, 176, 0, 166, 0, 0, 0, 234, 0, 0, 0, 155, 0, 0, 0, 24, 0, 0, 0, 212, 0, 0, 0,
            247, 0, 0, 0, 142, 213, 68, 0, 53, 24, 0, 0, 0, 52, 0, 49, 0, 0, 0, 245, 0, 0, 0, 76,
            0, 0, 0, 248, 0, 0, 0, 212, 0, 0, 0, 101, 0, 0, 0, 67, 132,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqSvProfileDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqSvProfileDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x1e,
                    "Incorrect message type, expected 0x1e, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x04c3,
                    "incorrect sender id, expected 0x04c3, is {sender_id}"
                );
                assert_eq!(
                    msg.acq_sv_profile[0].bin_width, 187,
                    "incorrect value for acq_sv_profile[0].bin_width, expected 187, is {}",
                    msg.acq_sv_profile[0].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf, 60,
                    "incorrect value for acq_sv_profile[0].cf, expected 60, is {}",
                    msg.acq_sv_profile[0].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf_max, 36,
                    "incorrect value for acq_sv_profile[0].cf_max, expected 36, is {}",
                    msg.acq_sv_profile[0].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cf_min, 132,
                    "incorrect value for acq_sv_profile[0].cf_min, expected 132, is {}",
                    msg.acq_sv_profile[0].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cn0, 151,
                    "incorrect value for acq_sv_profile[0].cn0, expected 151, is {}",
                    msg.acq_sv_profile[0].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[0].cp, 241,
                    "incorrect value for acq_sv_profile[0].cp, expected 241, is {}",
                    msg.acq_sv_profile[0].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[0].int_time, 12,
                    "incorrect value for acq_sv_profile[0].int_time, expected 12, is {}",
                    msg.acq_sv_profile[0].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[0].job_type, 67,
                    "incorrect value for acq_sv_profile[0].job_type, expected 67, is {}",
                    msg.acq_sv_profile[0].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.code, 0,
                    "incorrect value for acq_sv_profile[0].sid.code, expected 0, is {}",
                    msg.acq_sv_profile[0].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.reserved, 0,
                    "incorrect value for acq_sv_profile[0].sid.reserved, expected 0, is {}",
                    msg.acq_sv_profile[0].sid.reserved
                );
                assert_eq!(
                    msg.acq_sv_profile[0].sid.sat, 22,
                    "incorrect value for acq_sv_profile[0].sid.sat, expected 22, is {}",
                    msg.acq_sv_profile[0].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[0].status, 103,
                    "incorrect value for acq_sv_profile[0].status, expected 103, is {}",
                    msg.acq_sv_profile[0].status
                );
                assert_eq!(
                    msg.acq_sv_profile[0].time_spent, 75,
                    "incorrect value for acq_sv_profile[0].time_spent, expected 75, is {}",
                    msg.acq_sv_profile[0].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[0].timestamp, 91,
                    "incorrect value for acq_sv_profile[0].timestamp, expected 91, is {}",
                    msg.acq_sv_profile[0].timestamp
                );
                assert_eq!(
                    msg.acq_sv_profile[1].bin_width, 176,
                    "incorrect value for acq_sv_profile[1].bin_width, expected 176, is {}",
                    msg.acq_sv_profile[1].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf, 212,
                    "incorrect value for acq_sv_profile[1].cf, expected 212, is {}",
                    msg.acq_sv_profile[1].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf_max, 24,
                    "incorrect value for acq_sv_profile[1].cf_max, expected 24, is {}",
                    msg.acq_sv_profile[1].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cf_min, 155,
                    "incorrect value for acq_sv_profile[1].cf_min, expected 155, is {}",
                    msg.acq_sv_profile[1].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cn0, 111,
                    "incorrect value for acq_sv_profile[1].cn0, expected 111, is {}",
                    msg.acq_sv_profile[1].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[1].cp, 247,
                    "incorrect value for acq_sv_profile[1].cp, expected 247, is {}",
                    msg.acq_sv_profile[1].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[1].int_time, 179,
                    "incorrect value for acq_sv_profile[1].int_time, expected 179, is {}",
                    msg.acq_sv_profile[1].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[1].job_type, 238,
                    "incorrect value for acq_sv_profile[1].job_type, expected 238, is {}",
                    msg.acq_sv_profile[1].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.code, 1,
                    "incorrect value for acq_sv_profile[1].sid.code, expected 1, is {}",
                    msg.acq_sv_profile[1].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.reserved, 0,
                    "incorrect value for acq_sv_profile[1].sid.reserved, expected 0, is {}",
                    msg.acq_sv_profile[1].sid.reserved
                );
                assert_eq!(
                    msg.acq_sv_profile[1].sid.sat, 23,
                    "incorrect value for acq_sv_profile[1].sid.sat, expected 23, is {}",
                    msg.acq_sv_profile[1].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[1].status, 38,
                    "incorrect value for acq_sv_profile[1].status, expected 38, is {}",
                    msg.acq_sv_profile[1].status
                );
                assert_eq!(
                    msg.acq_sv_profile[1].time_spent, 234,
                    "incorrect value for acq_sv_profile[1].time_spent, expected 234, is {}",
                    msg.acq_sv_profile[1].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[1].timestamp, 166,
                    "incorrect value for acq_sv_profile[1].timestamp, expected 166, is {}",
                    msg.acq_sv_profile[1].timestamp
                );
                assert_eq!(
                    msg.acq_sv_profile[2].bin_width, 52,
                    "incorrect value for acq_sv_profile[2].bin_width, expected 52, is {}",
                    msg.acq_sv_profile[2].bin_width
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf, 212,
                    "incorrect value for acq_sv_profile[2].cf, expected 212, is {}",
                    msg.acq_sv_profile[2].cf
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf_max, 248,
                    "incorrect value for acq_sv_profile[2].cf_max, expected 248, is {}",
                    msg.acq_sv_profile[2].cf_max
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cf_min, 76,
                    "incorrect value for acq_sv_profile[2].cf_min, expected 76, is {}",
                    msg.acq_sv_profile[2].cf_min
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cn0, 68,
                    "incorrect value for acq_sv_profile[2].cn0, expected 68, is {}",
                    msg.acq_sv_profile[2].cn0
                );
                assert_eq!(
                    msg.acq_sv_profile[2].cp, 101,
                    "incorrect value for acq_sv_profile[2].cp, expected 101, is {}",
                    msg.acq_sv_profile[2].cp
                );
                assert_eq!(
                    msg.acq_sv_profile[2].int_time, 53,
                    "incorrect value for acq_sv_profile[2].int_time, expected 53, is {}",
                    msg.acq_sv_profile[2].int_time
                );
                assert_eq!(
                    msg.acq_sv_profile[2].job_type, 142,
                    "incorrect value for acq_sv_profile[2].job_type, expected 142, is {}",
                    msg.acq_sv_profile[2].job_type
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.code, 0,
                    "incorrect value for acq_sv_profile[2].sid.code, expected 0, is {}",
                    msg.acq_sv_profile[2].sid.code
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.reserved, 0,
                    "incorrect value for acq_sv_profile[2].sid.reserved, expected 0, is {}",
                    msg.acq_sv_profile[2].sid.reserved
                );
                assert_eq!(
                    msg.acq_sv_profile[2].sid.sat, 24,
                    "incorrect value for acq_sv_profile[2].sid.sat, expected 24, is {}",
                    msg.acq_sv_profile[2].sid.sat
                );
                assert_eq!(
                    msg.acq_sv_profile[2].status, 213,
                    "incorrect value for acq_sv_profile[2].status, expected 213, is {}",
                    msg.acq_sv_profile[2].status
                );
                assert_eq!(
                    msg.acq_sv_profile[2].time_spent, 245,
                    "incorrect value for acq_sv_profile[2].time_spent, expected 245, is {}",
                    msg.acq_sv_profile[2].time_spent
                );
                assert_eq!(
                    msg.acq_sv_profile[2].timestamp, 49,
                    "incorrect value for acq_sv_profile[2].timestamp, expected 49, is {}",
                    msg.acq_sv_profile[2].timestamp
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqSvProfileDep"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
