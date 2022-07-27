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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_acquisition_msg_acq_result_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 21, 0, 195, 4, 13, 0, 0, 104, 65, 0, 192, 53, 68, 198, 199, 0, 70, 8, 2, 68,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(8.24194335937500000e+03),
                    "incorrect value for cf, expected 8.24194335937500000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(7.27000000000000000e+02),
                    "incorrect value for cp, expected 7.27000000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 8,
                    "incorrect value for prn, expected 8, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.45000000000000000e+01),
                    "incorrect value for snr, expected 1.45000000000000000e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 21, 0, 195, 4, 13, 205, 204, 116, 65, 0, 192, 179, 67, 33, 81, 59, 68, 9, 219, 27,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(7.49267639160156250e+02),
                    "incorrect value for cf, expected 7.49267639160156250e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(3.59500000000000000e+02),
                    "incorrect value for cp, expected 3.59500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 9,
                    "incorrect value for prn, expected 9, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.53000001907348633e+01),
                    "incorrect value for snr, expected 1.53000001907348633e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 21, 0, 195, 4, 13, 205, 204, 144, 65, 0, 0, 34, 66, 57, 237, 202, 197, 11, 150, 35,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-6.49365283203125000e+03),
                    "incorrect value for cf, expected -6.49365283203125000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(4.05000000000000000e+01),
                    "incorrect value for cp, expected 4.05000000000000000e+01, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 11,
                    "incorrect value for prn, expected 11, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.81000003814697266e+01),
                    "incorrect value for snr, expected 1.81000003814697266e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 21, 0, 195, 4, 13, 205, 204, 116, 65, 0, 32, 9, 68, 129, 193, 121, 196, 12, 146,
            118,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-9.99023498535156250e+02),
                    "incorrect value for cf, expected -9.99023498535156250e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(5.48500000000000000e+02),
                    "incorrect value for cp, expected 5.48500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 12,
                    "incorrect value for prn, expected 12, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.53000001907348633e+01),
                    "incorrect value for snr, expected 1.53000001907348633e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 21, 0, 195, 4, 13, 205, 204, 116, 65, 0, 32, 67, 68, 228, 74, 148, 69, 14, 23, 75,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(4.74536132812500000e+03),
                    "incorrect value for cf, expected 4.74536132812500000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(7.80500000000000000e+02),
                    "incorrect value for cp, expected 7.80500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 14,
                    "incorrect value for prn, expected 14, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.53000001907348633e+01),
                    "incorrect value for snr, expected 1.53000001907348633e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 21, 0, 195, 4, 13, 228, 56, 35, 67, 0, 32, 18, 68, 129, 193, 249, 195, 0, 204, 207,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-4.99511749267578125e+02),
                    "incorrect value for cf, expected -4.99511749267578125e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(5.84500000000000000e+02),
                    "incorrect value for cp, expected 5.84500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 0,
                    "incorrect value for prn, expected 0, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.63222229003906250e+02),
                    "incorrect value for snr, expected 1.63222229003906250e+02, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
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
fn test_json2sbp_auto_check_sbp_acquisition_msg_acq_result_dep_a() {
    {
        let json_input = r#"{"sender": 1219, "msg_type": 21, "prn": 8, "cf": 8241.943359375, "crc": 17410, "length": 13, "snr": 14.5, "cp": 727.0, "preamble": 85, "payload": "AABoQQDANUTGxwBGCA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(8.24194335937500000e+03),
                    "incorrect value for cf, expected 8.24194335937500000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(7.27000000000000000e+02),
                    "incorrect value for cp, expected 7.27000000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 8,
                    "incorrect value for prn, expected 8, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.45000000000000000e+01),
                    "incorrect value for snr, expected 1.45000000000000000e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };
    }
    {
        let json_input = r#"{"sender": 1219, "msg_type": 21, "prn": 9, "cf": 749.2676391601562, "crc": 7131, "length": 13, "snr": 15.300000190734863, "cp": 359.5, "preamble": 85, "payload": "zcx0QQDAs0MhUTtECQ=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(7.49267639160156250e+02),
                    "incorrect value for cf, expected 7.49267639160156250e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(3.59500000000000000e+02),
                    "incorrect value for cp, expected 3.59500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 9,
                    "incorrect value for prn, expected 9, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.53000001907348633e+01),
                    "incorrect value for snr, expected 1.53000001907348633e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };
    }
    {
        let json_input = r#"{"sender": 1219, "msg_type": 21, "prn": 11, "cf": -6493.65283203125, "crc": 9110, "length": 13, "snr": 18.100000381469727, "cp": 40.5, "preamble": 85, "payload": "zcyQQQAAIkI57crFCw=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-6.49365283203125000e+03),
                    "incorrect value for cf, expected -6.49365283203125000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(4.05000000000000000e+01),
                    "incorrect value for cp, expected 4.05000000000000000e+01, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 11,
                    "incorrect value for prn, expected 11, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.81000003814697266e+01),
                    "incorrect value for snr, expected 1.81000003814697266e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };
    }
    {
        let json_input = r#"{"sender": 1219, "msg_type": 21, "prn": 12, "cf": -999.0234985351562, "crc": 30354, "length": 13, "snr": 15.300000190734863, "cp": 548.5, "preamble": 85, "payload": "zcx0QQAgCUSBwXnEDA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-9.99023498535156250e+02),
                    "incorrect value for cf, expected -9.99023498535156250e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(5.48500000000000000e+02),
                    "incorrect value for cp, expected 5.48500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 12,
                    "incorrect value for prn, expected 12, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.53000001907348633e+01),
                    "incorrect value for snr, expected 1.53000001907348633e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };
    }
    {
        let json_input = r#"{"sender": 1219, "msg_type": 21, "prn": 14, "cf": 4745.361328125, "crc": 19223, "length": 13, "snr": 15.300000190734863, "cp": 780.5, "preamble": 85, "payload": "zcx0QQAgQ0TkSpRFDg=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(4.74536132812500000e+03),
                    "incorrect value for cf, expected 4.74536132812500000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(7.80500000000000000e+02),
                    "incorrect value for cp, expected 7.80500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 14,
                    "incorrect value for prn, expected 14, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.53000001907348633e+01),
                    "incorrect value for snr, expected 1.53000001907348633e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };
    }
    {
        let json_input = r#"{"sender": 1219, "msg_type": 21, "prn": 0, "cf": -499.5117492675781, "crc": 53196, "length": 13, "snr": 163.22222900390625, "cp": 584.5, "preamble": 85, "payload": "5DgjQwAgEkSBwfnDAA=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-4.99511749267578125e+02),
                    "incorrect value for cf, expected -4.99511749267578125e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(5.84500000000000000e+02),
                    "incorrect value for cp, expected 5.84500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 0,
                    "incorrect value for prn, expected 0, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.63222229003906250e+02),
                    "incorrect value for snr, expected 1.63222229003906250e+02, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_acquisition_msg_acq_result_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_acquisition_msg_acq_result_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 21, 0, 195, 4, 13, 0, 0, 104, 65, 0, 192, 53, 68, 198, 199, 0, 70, 8, 2, 68,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqResultDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(8.24194335937500000e+03),
                    "incorrect value for cf, expected 8.24194335937500000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(7.27000000000000000e+02),
                    "incorrect value for cp, expected 7.27000000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 8,
                    "incorrect value for prn, expected 8, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.45000000000000000e+01),
                    "incorrect value for snr, expected 1.45000000000000000e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 21, 0, 195, 4, 13, 205, 204, 116, 65, 0, 192, 179, 67, 33, 81, 59, 68, 9, 219, 27,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqResultDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(7.49267639160156250e+02),
                    "incorrect value for cf, expected 7.49267639160156250e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(3.59500000000000000e+02),
                    "incorrect value for cp, expected 3.59500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 9,
                    "incorrect value for prn, expected 9, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.53000001907348633e+01),
                    "incorrect value for snr, expected 1.53000001907348633e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 21, 0, 195, 4, 13, 205, 204, 144, 65, 0, 0, 34, 66, 57, 237, 202, 197, 11, 150, 35,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqResultDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-6.49365283203125000e+03),
                    "incorrect value for cf, expected -6.49365283203125000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(4.05000000000000000e+01),
                    "incorrect value for cp, expected 4.05000000000000000e+01, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 11,
                    "incorrect value for prn, expected 11, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.81000003814697266e+01),
                    "incorrect value for snr, expected 1.81000003814697266e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 21, 0, 195, 4, 13, 205, 204, 116, 65, 0, 32, 9, 68, 129, 193, 121, 196, 12, 146,
            118,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqResultDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-9.99023498535156250e+02),
                    "incorrect value for cf, expected -9.99023498535156250e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(5.48500000000000000e+02),
                    "incorrect value for cp, expected 5.48500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 12,
                    "incorrect value for prn, expected 12, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.53000001907348633e+01),
                    "incorrect value for snr, expected 1.53000001907348633e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 21, 0, 195, 4, 13, 205, 204, 116, 65, 0, 32, 67, 68, 228, 74, 148, 69, 14, 23, 75,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqResultDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(4.74536132812500000e+03),
                    "incorrect value for cf, expected 4.74536132812500000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(7.80500000000000000e+02),
                    "incorrect value for cp, expected 7.80500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 14,
                    "incorrect value for prn, expected 14, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.53000001907348633e+01),
                    "incorrect value for snr, expected 1.53000001907348633e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 21, 0, 195, 4, 13, 228, 56, 35, 67, 0, 32, 18, 68, 129, 193, 249, 195, 0, 204, 207,
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
        let sbp_msg = sbp::messages::Sbp::MsgAcqResultDepA(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x15,
                    "Incorrect message type, expected 0x15, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-4.99511749267578125e+02),
                    "incorrect value for cf, expected -4.99511749267578125e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(5.84500000000000000e+02),
                    "incorrect value for cp, expected 5.84500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.prn, 0,
                    "incorrect value for prn, expected 0, is {}",
                    msg.prn
                );
                assert!(
                    msg.snr.almost_eq(1.63222229003906250e+02),
                    "incorrect value for snr, expected 1.63222229003906250e+02, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepA"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
