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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepC.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_acquisition_msg_acq_result_dep_c() {
    {
        let mut payload = Cursor::new(vec![
            85, 31, 0, 40, 12, 16, 72, 9, 34, 66, 155, 152, 228, 67, 28, 34, 221, 68, 10, 0, 0, 0,
            9, 189,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(1.76906591796875000e+03),
                    "incorrect value for cf, expected 1.76906591796875000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(4.05090637207031250e+01),
                    "incorrect value for cn0, expected 4.05090637207031250e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(4.57192230224609375e+02),
                    "incorrect value for cp, expected 4.57192230224609375e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 10,
                    "incorrect value for sid.sat, expected 10, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 31, 0, 40, 12, 16, 132, 250, 45, 66, 207, 93, 88, 68, 68, 185, 252, 195, 6, 0, 0,
            0, 136, 185,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-5.05447387695312500e+02),
                    "incorrect value for cf, expected -5.05447387695312500e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(4.34946441650390625e+01),
                    "incorrect value for cn0, expected 4.34946441650390625e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(8.65465759277343750e+02),
                    "incorrect value for cp, expected 8.65465759277343750e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 6,
                    "incorrect value for sid.sat, expected 6, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 31, 0, 40, 12, 16, 163, 223, 24, 66, 64, 91, 102, 67, 202, 243, 157, 196, 13, 0, 0,
            0, 150, 161,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-1.26361840820312500e+03),
                    "incorrect value for cf, expected -1.26361840820312500e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(3.82183952331542969e+01),
                    "incorrect value for cn0, expected 3.82183952331542969e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(2.30356445312500000e+02),
                    "incorrect value for cp, expected 2.30356445312500000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 13,
                    "incorrect value for sid.sat, expected 13, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 31, 0, 40, 12, 16, 129, 65, 21, 66, 224, 214, 124, 67, 243, 138, 61, 69, 1, 0, 0,
            0, 109, 209,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(3.03268432617187500e+03),
                    "incorrect value for cf, expected 3.03268432617187500e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(3.73139686584472656e+01),
                    "incorrect value for cn0, expected 3.73139686584472656e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(2.52839355468750000e+02),
                    "incorrect value for cp, expected 2.52839355468750000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 1,
                    "incorrect value for sid.sat, expected 1, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 31, 0, 40, 12, 16, 126, 35, 62, 66, 226, 37, 102, 68, 202, 243, 29, 69, 27, 0, 0,
            0, 91, 67,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(2.52723681640625000e+03),
                    "incorrect value for cf, expected 2.52723681640625000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(4.75346603393554688e+01),
                    "incorrect value for cn0, expected 4.75346603393554688e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(9.20591918945312500e+02),
                    "incorrect value for cp, expected 9.20591918945312500e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 27,
                    "incorrect value for sid.sat, expected 27, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
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
fn test_json2sbp_auto_check_sbp_acquisition_msg_acq_result_dep_c() {
    {
        let json_input = r#"{"sender": 3112, "msg_type": 31, "cf": 1769.06591796875, "cn0": 40.509063720703125, "crc": 48393, "length": 16, "sid": {"code": 0, "reserved": 0, "sat": 10}, "cp": 457.1922302246094, "preamble": 85, "payload": "SAkiQpuY5EMcIt1ECgAAAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(1.76906591796875000e+03),
                    "incorrect value for cf, expected 1.76906591796875000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(4.05090637207031250e+01),
                    "incorrect value for cn0, expected 4.05090637207031250e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(4.57192230224609375e+02),
                    "incorrect value for cp, expected 4.57192230224609375e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 10,
                    "incorrect value for sid.sat, expected 10, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };
    }
    {
        let json_input = r#"{"sender": 3112, "msg_type": 31, "cf": -505.4473876953125, "cn0": 43.49464416503906, "crc": 47496, "length": 16, "sid": {"code": 0, "reserved": 0, "sat": 6}, "cp": 865.4657592773438, "preamble": 85, "payload": "hPotQs9dWEREufzDBgAAAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-5.05447387695312500e+02),
                    "incorrect value for cf, expected -5.05447387695312500e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(4.34946441650390625e+01),
                    "incorrect value for cn0, expected 4.34946441650390625e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(8.65465759277343750e+02),
                    "incorrect value for cp, expected 8.65465759277343750e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 6,
                    "incorrect value for sid.sat, expected 6, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };
    }
    {
        let json_input = r#"{"sender": 3112, "msg_type": 31, "cf": -1263.618408203125, "cn0": 38.2183952331543, "crc": 41366, "length": 16, "sid": {"code": 0, "reserved": 0, "sat": 13}, "cp": 230.3564453125, "preamble": 85, "payload": "o98YQkBbZkPK853EDQAAAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-1.26361840820312500e+03),
                    "incorrect value for cf, expected -1.26361840820312500e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(3.82183952331542969e+01),
                    "incorrect value for cn0, expected 3.82183952331542969e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(2.30356445312500000e+02),
                    "incorrect value for cp, expected 2.30356445312500000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 13,
                    "incorrect value for sid.sat, expected 13, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };
    }
    {
        let json_input = r#"{"sender": 3112, "msg_type": 31, "cf": 3032.684326171875, "cn0": 37.313968658447266, "crc": 53613, "length": 16, "sid": {"code": 0, "reserved": 0, "sat": 1}, "cp": 252.83935546875, "preamble": 85, "payload": "gUEVQuDWfEPzij1FAQAAAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(3.03268432617187500e+03),
                    "incorrect value for cf, expected 3.03268432617187500e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(3.73139686584472656e+01),
                    "incorrect value for cn0, expected 3.73139686584472656e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(2.52839355468750000e+02),
                    "incorrect value for cp, expected 2.52839355468750000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 1,
                    "incorrect value for sid.sat, expected 1, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };
    }
    {
        let json_input = r#"{"sender": 3112, "msg_type": 31, "cf": 2527.23681640625, "cn0": 47.53466033935547, "crc": 17243, "length": 16, "sid": {"code": 0, "reserved": 0, "sat": 27}, "cp": 920.5919189453125, "preamble": 85, "payload": "fiM+QuIlZkTK8x1FGwAAAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(2.52723681640625000e+03),
                    "incorrect value for cf, expected 2.52723681640625000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(4.75346603393554688e+01),
                    "incorrect value for cn0, expected 4.75346603393554688e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(9.20591918945312500e+02),
                    "incorrect value for cp, expected 9.20591918945312500e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 27,
                    "incorrect value for sid.sat, expected 27, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_acquisition_msg_acq_result_dep_c`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_acquisition_msg_acq_result_dep_c() {
    {
        let mut payload = Cursor::new(vec![
            85, 31, 0, 40, 12, 16, 72, 9, 34, 66, 155, 152, 228, 67, 28, 34, 221, 68, 10, 0, 0, 0,
            9, 189,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqResultDepC(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(1.76906591796875000e+03),
                    "incorrect value for cf, expected 1.76906591796875000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(4.05090637207031250e+01),
                    "incorrect value for cn0, expected 4.05090637207031250e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(4.57192230224609375e+02),
                    "incorrect value for cp, expected 4.57192230224609375e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 10,
                    "incorrect value for sid.sat, expected 10, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 31, 0, 40, 12, 16, 132, 250, 45, 66, 207, 93, 88, 68, 68, 185, 252, 195, 6, 0, 0,
            0, 136, 185,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqResultDepC(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-5.05447387695312500e+02),
                    "incorrect value for cf, expected -5.05447387695312500e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(4.34946441650390625e+01),
                    "incorrect value for cn0, expected 4.34946441650390625e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(8.65465759277343750e+02),
                    "incorrect value for cp, expected 8.65465759277343750e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 6,
                    "incorrect value for sid.sat, expected 6, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 31, 0, 40, 12, 16, 163, 223, 24, 66, 64, 91, 102, 67, 202, 243, 157, 196, 13, 0, 0,
            0, 150, 161,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqResultDepC(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-1.26361840820312500e+03),
                    "incorrect value for cf, expected -1.26361840820312500e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(3.82183952331542969e+01),
                    "incorrect value for cn0, expected 3.82183952331542969e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(2.30356445312500000e+02),
                    "incorrect value for cp, expected 2.30356445312500000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 13,
                    "incorrect value for sid.sat, expected 13, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 31, 0, 40, 12, 16, 129, 65, 21, 66, 224, 214, 124, 67, 243, 138, 61, 69, 1, 0, 0,
            0, 109, 209,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqResultDepC(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(3.03268432617187500e+03),
                    "incorrect value for cf, expected 3.03268432617187500e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(3.73139686584472656e+01),
                    "incorrect value for cn0, expected 3.73139686584472656e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(2.52839355468750000e+02),
                    "incorrect value for cp, expected 2.52839355468750000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 1,
                    "incorrect value for sid.sat, expected 1, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 31, 0, 40, 12, 16, 126, 35, 62, 66, 226, 37, 102, 68, 202, 243, 29, 69, 27, 0, 0,
            0, 91, 67,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqResultDepC(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepC(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x1f,
                    "Incorrect message type, expected 0x1f, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc28,
                    "incorrect sender id, expected 0xc28, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(2.52723681640625000e+03),
                    "incorrect value for cf, expected 2.52723681640625000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cn0.almost_eq(4.75346603393554688e+01),
                    "incorrect value for cn0, expected 4.75346603393554688e+01, is {:e}",
                    msg.cn0
                );
                assert!(
                    msg.cp.almost_eq(9.20591918945312500e+02),
                    "incorrect value for cp, expected 9.20591918945312500e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 27,
                    "incorrect value for sid.sat, expected 27, is {}",
                    msg.sid.sat
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepC"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
