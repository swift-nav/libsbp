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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLH.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_pos_llh() {
    {
        let mut payload = Cursor::new(vec![
            85, 10, 2, 211, 136, 34, 40, 244, 122, 19, 201, 106, 155, 186, 42, 160, 66, 64, 168,
            109, 26, 225, 0, 120, 94, 192, 130, 102, 237, 230, 43, 54, 60, 64, 0, 0, 0, 0, 14, 2,
            175, 162,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.82116073922720787e+01),
                    "incorrect value for height, expected 2.82116073922720787e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72513039835808470e+01),
                    "incorrect value for lat, expected 3.72513039835808470e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875053668793612e+02),
                    "incorrect value for lon, expected -1.21875053668793612e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 14,
                    "incorrect value for n_sats, expected 14, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326825000,
                    "incorrect value for tow, expected 326825000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 10, 2, 211, 136, 34, 16, 248, 122, 19, 52, 177, 251, 178, 42, 160, 66, 64, 237, 22,
            97, 224, 0, 120, 94, 192, 107, 188, 109, 90, 247, 189, 59, 64, 0, 0, 0, 0, 15, 2, 38,
            177,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.77420555608663726e+01),
                    "incorrect value for height, expected 2.77420555608663726e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72513030747381038e+01),
                    "incorrect value for lat, expected 3.72513030747381038e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875053496183412e+02),
                    "incorrect value for lon, expected -1.21875053496183412e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326826000,
                    "incorrect value for tow, expected 326826000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 10, 2, 211, 136, 34, 248, 251, 122, 19, 135, 66, 9, 163, 42, 160, 66, 64, 146, 8,
            99, 225, 0, 120, 94, 192, 45, 181, 143, 219, 28, 157, 59, 64, 0, 0, 0, 0, 15, 2, 51,
            40,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.76137215829705163e+01),
                    "incorrect value for height, expected 2.76137215829705163e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72513011737074109e+01),
                    "incorrect value for lat, expected 3.72513011737074109e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875053736412411e+02),
                    "incorrect value for lon, expected -1.21875053736412411e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326827000,
                    "incorrect value for tow, expected 326827000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 10, 2, 211, 136, 34, 224, 255, 122, 19, 18, 44, 253, 119, 42, 160, 66, 64, 48, 109,
            39, 231, 0, 120, 94, 192, 185, 76, 48, 17, 119, 205, 59, 64, 0, 0, 0, 0, 15, 2, 12,
            194,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.78025980704230484e+01),
                    "incorrect value for height, expected 2.78025980704230484e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72512960420791757e+01),
                    "incorrect value for lat, expected 3.72512960420791757e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875055111410575e+02),
                    "incorrect value for lon, expected -1.21875055111410575e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326828000,
                    "incorrect value for tow, expected 326828000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 10, 2, 211, 136, 34, 200, 3, 123, 19, 225, 237, 238, 90, 42, 160, 66, 64, 59, 143,
            70, 235, 0, 120, 94, 192, 101, 106, 249, 224, 131, 240, 59, 64, 0, 0, 0, 0, 15, 2, 34,
            103,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.79395123108792127e+01),
                    "incorrect value for height, expected 2.79395123108792127e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72512925783773952e+01),
                    "incorrect value for lat, expected 3.72512925783773952e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875056094079739e+02),
                    "incorrect value for lon, expected -1.21875056094079739e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326829000,
                    "incorrect value for tow, expected 326829000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_pos_llh() {
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 14, "sender": 35027, "msg_type": 522, "lon": -121.87505366879361, "tow": 326825000, "height": 28.21160739227208, "crc": 41647, "length": 34, "flags": 2, "h_accuracy": 0, "lat": 37.25130398358085, "preamble": 85, "payload": "KPR6E8lqm7oqoEJAqG0a4QB4XsCCZu3mKzY8QAAAAAAOAg=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.82116073922720787e+01),
                    "incorrect value for height, expected 2.82116073922720787e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72513039835808470e+01),
                    "incorrect value for lat, expected 3.72513039835808470e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875053668793612e+02),
                    "incorrect value for lon, expected -1.21875053668793612e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 14,
                    "incorrect value for n_sats, expected 14, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326825000,
                    "incorrect value for tow, expected 326825000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 15, "sender": 35027, "msg_type": 522, "lon": -121.87505349618341, "tow": 326826000, "height": 27.742055560866373, "crc": 45350, "length": 34, "flags": 2, "h_accuracy": 0, "lat": 37.251303074738104, "preamble": 85, "payload": "EPh6EzSx+7IqoEJA7RZh4AB4XsBrvG1a9707QAAAAAAPAg=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.77420555608663726e+01),
                    "incorrect value for height, expected 2.77420555608663726e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72513030747381038e+01),
                    "incorrect value for lat, expected 3.72513030747381038e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875053496183412e+02),
                    "incorrect value for lon, expected -1.21875053496183412e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326826000,
                    "incorrect value for tow, expected 326826000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 15, "sender": 35027, "msg_type": 522, "lon": -121.87505373641241, "tow": 326827000, "height": 27.613721582970516, "crc": 10291, "length": 34, "flags": 2, "h_accuracy": 0, "lat": 37.25130117370741, "preamble": 85, "payload": "+Pt6E4dCCaMqoEJAkghj4QB4XsAttY/bHJ07QAAAAAAPAg=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.76137215829705163e+01),
                    "incorrect value for height, expected 2.76137215829705163e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72513011737074109e+01),
                    "incorrect value for lat, expected 3.72513011737074109e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875053736412411e+02),
                    "incorrect value for lon, expected -1.21875053736412411e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326827000,
                    "incorrect value for tow, expected 326827000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 15, "sender": 35027, "msg_type": 522, "lon": -121.87505511141057, "tow": 326828000, "height": 27.80259807042305, "crc": 49676, "length": 34, "flags": 2, "h_accuracy": 0, "lat": 37.251296042079176, "preamble": 85, "payload": "4P96ExIs/XcqoEJAMG0n5wB4XsC5TDARd807QAAAAAAPAg=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.78025980704230484e+01),
                    "incorrect value for height, expected 2.78025980704230484e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72512960420791757e+01),
                    "incorrect value for lat, expected 3.72512960420791757e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875055111410575e+02),
                    "incorrect value for lon, expected -1.21875055111410575e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326828000,
                    "incorrect value for tow, expected 326828000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };
    }
    {
        let json_input = r#"{"v_accuracy": 0, "n_sats": 15, "sender": 35027, "msg_type": 522, "lon": -121.87505609407974, "tow": 326829000, "height": 27.939512310879213, "crc": 26402, "length": 34, "flags": 2, "h_accuracy": 0, "lat": 37.251292578377395, "preamble": 85, "payload": "yAN7E+Ht7loqoEJAO49G6wB4XsBlavngg/A7QAAAAAAPAg=="}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.79395123108792127e+01),
                    "incorrect value for height, expected 2.79395123108792127e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72512925783773952e+01),
                    "incorrect value for lat, expected 3.72512925783773952e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875056094079739e+02),
                    "incorrect value for lon, expected -1.21875056094079739e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326829000,
                    "incorrect value for tow, expected 326829000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_pos_llh`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_pos_llh() {
    {
        let mut payload = Cursor::new(vec![
            85, 10, 2, 211, 136, 34, 40, 244, 122, 19, 201, 106, 155, 186, 42, 160, 66, 64, 168,
            109, 26, 225, 0, 120, 94, 192, 130, 102, 237, 230, 43, 54, 60, 64, 0, 0, 0, 0, 14, 2,
            175, 162,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlh(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.82116073922720787e+01),
                    "incorrect value for height, expected 2.82116073922720787e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72513039835808470e+01),
                    "incorrect value for lat, expected 3.72513039835808470e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875053668793612e+02),
                    "incorrect value for lon, expected -1.21875053668793612e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 14,
                    "incorrect value for n_sats, expected 14, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326825000,
                    "incorrect value for tow, expected 326825000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 10, 2, 211, 136, 34, 16, 248, 122, 19, 52, 177, 251, 178, 42, 160, 66, 64, 237, 22,
            97, 224, 0, 120, 94, 192, 107, 188, 109, 90, 247, 189, 59, 64, 0, 0, 0, 0, 15, 2, 38,
            177,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlh(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.77420555608663726e+01),
                    "incorrect value for height, expected 2.77420555608663726e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72513030747381038e+01),
                    "incorrect value for lat, expected 3.72513030747381038e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875053496183412e+02),
                    "incorrect value for lon, expected -1.21875053496183412e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326826000,
                    "incorrect value for tow, expected 326826000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 10, 2, 211, 136, 34, 248, 251, 122, 19, 135, 66, 9, 163, 42, 160, 66, 64, 146, 8,
            99, 225, 0, 120, 94, 192, 45, 181, 143, 219, 28, 157, 59, 64, 0, 0, 0, 0, 15, 2, 51,
            40,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlh(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.76137215829705163e+01),
                    "incorrect value for height, expected 2.76137215829705163e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72513011737074109e+01),
                    "incorrect value for lat, expected 3.72513011737074109e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875053736412411e+02),
                    "incorrect value for lon, expected -1.21875053736412411e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326827000,
                    "incorrect value for tow, expected 326827000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 10, 2, 211, 136, 34, 224, 255, 122, 19, 18, 44, 253, 119, 42, 160, 66, 64, 48, 109,
            39, 231, 0, 120, 94, 192, 185, 76, 48, 17, 119, 205, 59, 64, 0, 0, 0, 0, 15, 2, 12,
            194,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlh(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.78025980704230484e+01),
                    "incorrect value for height, expected 2.78025980704230484e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72512960420791757e+01),
                    "incorrect value for lat, expected 3.72512960420791757e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875055111410575e+02),
                    "incorrect value for lon, expected -1.21875055111410575e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326828000,
                    "incorrect value for tow, expected 326828000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 10, 2, 211, 136, 34, 200, 3, 123, 19, 225, 237, 238, 90, 42, 160, 66, 64, 59, 143,
            70, 235, 0, 120, 94, 192, 101, 106, 249, 224, 131, 240, 59, 64, 0, 0, 0, 0, 15, 2, 34,
            103,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlh(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlh(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x20a,
                    "Incorrect message type, expected 0x20a, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x88d3,
                    "incorrect sender id, expected 0x88d3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 2,
                    "incorrect value for flags, expected 2, is {}",
                    msg.flags
                );
                assert_eq!(
                    msg.h_accuracy, 0,
                    "incorrect value for h_accuracy, expected 0, is {}",
                    msg.h_accuracy
                );
                assert!(
                    msg.height.almost_eq(2.79395123108792127e+01),
                    "incorrect value for height, expected 2.79395123108792127e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.72512925783773952e+01),
                    "incorrect value for lat, expected 3.72512925783773952e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.21875056094079739e+02),
                    "incorrect value for lon, expected -1.21875056094079739e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 15,
                    "incorrect value for n_sats, expected 15, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 326829000,
                    "incorrect value for tow, expected 326829000, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.v_accuracy, 0,
                    "incorrect value for v_accuracy, expected 0, is {}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLH"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
