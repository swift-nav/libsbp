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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhAcc.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_pos_llh_acc() {
    {
        let mut payload = Cursor::new(vec![
            85, 24, 2, 2, 28, 67, 39, 120, 110, 18, 51, 51, 51, 51, 51, 139, 189, 64, 154, 153,
            153, 153, 25, 151, 192, 64, 51, 51, 51, 51, 51, 161, 176, 64, 51, 51, 51, 51, 51, 101,
            179, 64, 51, 163, 22, 69, 154, 25, 173, 69, 102, 134, 243, 68, 154, 201, 196, 69, 205,
            224, 0, 70, 51, 35, 72, 69, 51, 99, 31, 69, 95, 27, 72, 220, 177,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhAcc(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x218,
                    "Incorrect message type, expected 0x218, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1c02,
                    "incorrect sender id, expected 0x1c02, is {sender_id}"
                );
                assert!(
                    msg.at_accuracy.almost_eq(6.29720019531250000e+03),
                    "incorrect value for at_accuracy, expected 6.29720019531250000e+03, is {:e}",
                    msg.at_accuracy
                );
                assert_eq!(
                    msg.confidence_and_geoid, 95,
                    "incorrect value for confidence_and_geoid, expected 95, is {}",
                    msg.confidence_and_geoid
                );
                assert!(
                    msg.ct_accuracy.almost_eq(1.94819995117187500e+03),
                    "incorrect value for ct_accuracy, expected 1.94819995117187500e+03, is {:e}",
                    msg.ct_accuracy
                );
                assert_eq!(
                    msg.flags, 72,
                    "incorrect value for flags, expected 72, is {}",
                    msg.flags
                );
                assert!(
                    msg.h_accuracy.almost_eq(2.41019995117187500e+03),
                    "incorrect value for h_accuracy, expected 2.41019995117187500e+03, is {:e}",
                    msg.h_accuracy
                );
                assert!(msg.h_ellipse.orientation.almost_eq( 2.55019995117187500e+03 ), "incorrect value for h_ellipse.orientation, expected 2.55019995117187500e+03, is {:e}", msg.h_ellipse.orientation);
                assert!(msg.h_ellipse.semi_major.almost_eq( 8.24820019531250000e+03 ), "incorrect value for h_ellipse.semi_major, expected 8.24820019531250000e+03, is {:e}", msg.h_ellipse.semi_major);
                assert!(msg.h_ellipse.semi_minor.almost_eq( 3.20219995117187500e+03 ), "incorrect value for h_ellipse.semi_minor, expected 3.20219995117187500e+03, is {:e}", msg.h_ellipse.semi_minor);
                assert!(
                    msg.height.almost_eq(4.25719999999999982e+03),
                    "incorrect value for height, expected 4.25719999999999982e+03, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(7.56319999999999982e+03),
                    "incorrect value for lat, expected 7.56319999999999982e+03, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(8.49420000000000073e+03),
                    "incorrect value for lon, expected 8.49420000000000073e+03, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 27,
                    "incorrect value for n_sats, expected 27, is {}",
                    msg.n_sats
                );
                assert!(msg.orthometric_height.almost_eq( 4.96519999999999982e+03 ), "incorrect value for orthometric_height, expected 4.96519999999999982e+03, is {:e}", msg.orthometric_height);
                assert_eq!(
                    msg.tow, 309229607,
                    "incorrect value for tow, expected 309229607, is {}",
                    msg.tow
                );
                assert!(
                    msg.v_accuracy.almost_eq(5.53920019531250000e+03),
                    "incorrect value for v_accuracy, expected 5.53920019531250000e+03, is {:e}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHAcc"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_pos_llh_acc() {
    {
        let json_input = r#"{"preamble":85,"msg_type":536,"sender":7170,"length":67,"payload":"J3huEjMzMzMzi71AmpmZmRmXwEAzMzMzM6GwQDMzMzMzZbNAM6MWRZoZrUVmhvNEmsnERc3gAEYzI0hFM2MfRV8bSA==","crc":45532,"tow":309229607,"lat":7563.2,"lon":8494.2,"height":4257.2,"orthometric_height":4965.2,"h_accuracy":2410.199951171875,"v_accuracy":5539.2001953125,"ct_accuracy":1948.199951171875,"at_accuracy":6297.2001953125,"h_ellipse":{"semi_major":8248.2001953125,"semi_minor":3202.199951171875,"orientation":2550.199951171875},"confidence_and_geoid":95,"n_sats":27,"flags":72}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlhAcc(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x218,
                    "Incorrect message type, expected 0x218, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1c02,
                    "incorrect sender id, expected 0x1c02, is {sender_id}"
                );
                assert!(
                    msg.at_accuracy.almost_eq(6.29720019531250000e+03),
                    "incorrect value for at_accuracy, expected 6.29720019531250000e+03, is {:e}",
                    msg.at_accuracy
                );
                assert_eq!(
                    msg.confidence_and_geoid, 95,
                    "incorrect value for confidence_and_geoid, expected 95, is {}",
                    msg.confidence_and_geoid
                );
                assert!(
                    msg.ct_accuracy.almost_eq(1.94819995117187500e+03),
                    "incorrect value for ct_accuracy, expected 1.94819995117187500e+03, is {:e}",
                    msg.ct_accuracy
                );
                assert_eq!(
                    msg.flags, 72,
                    "incorrect value for flags, expected 72, is {}",
                    msg.flags
                );
                assert!(
                    msg.h_accuracy.almost_eq(2.41019995117187500e+03),
                    "incorrect value for h_accuracy, expected 2.41019995117187500e+03, is {:e}",
                    msg.h_accuracy
                );
                assert!(msg.h_ellipse.orientation.almost_eq( 2.55019995117187500e+03 ), "incorrect value for h_ellipse.orientation, expected 2.55019995117187500e+03, is {:e}", msg.h_ellipse.orientation);
                assert!(msg.h_ellipse.semi_major.almost_eq( 8.24820019531250000e+03 ), "incorrect value for h_ellipse.semi_major, expected 8.24820019531250000e+03, is {:e}", msg.h_ellipse.semi_major);
                assert!(msg.h_ellipse.semi_minor.almost_eq( 3.20219995117187500e+03 ), "incorrect value for h_ellipse.semi_minor, expected 3.20219995117187500e+03, is {:e}", msg.h_ellipse.semi_minor);
                assert!(
                    msg.height.almost_eq(4.25719999999999982e+03),
                    "incorrect value for height, expected 4.25719999999999982e+03, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(7.56319999999999982e+03),
                    "incorrect value for lat, expected 7.56319999999999982e+03, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(8.49420000000000073e+03),
                    "incorrect value for lon, expected 8.49420000000000073e+03, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 27,
                    "incorrect value for n_sats, expected 27, is {}",
                    msg.n_sats
                );
                assert!(msg.orthometric_height.almost_eq( 4.96519999999999982e+03 ), "incorrect value for orthometric_height, expected 4.96519999999999982e+03, is {:e}", msg.orthometric_height);
                assert_eq!(
                    msg.tow, 309229607,
                    "incorrect value for tow, expected 309229607, is {}",
                    msg.tow
                );
                assert!(
                    msg.v_accuracy.almost_eq(5.53920019531250000e+03),
                    "incorrect value for v_accuracy, expected 5.53920019531250000e+03, is {:e}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHAcc"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_pos_llh_acc`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_pos_llh_acc() {
    {
        let mut payload = Cursor::new(vec![
            85, 24, 2, 2, 28, 67, 39, 120, 110, 18, 51, 51, 51, 51, 51, 139, 189, 64, 154, 153,
            153, 153, 25, 151, 192, 64, 51, 51, 51, 51, 51, 161, 176, 64, 51, 51, 51, 51, 51, 101,
            179, 64, 51, 163, 22, 69, 154, 25, 173, 69, 102, 134, 243, 68, 154, 201, 196, 69, 205,
            224, 0, 70, 51, 35, 72, 69, 51, 99, 31, 69, 95, 27, 72, 220, 177,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlhAcc(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhAcc(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x218,
                    "Incorrect message type, expected 0x218, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1c02,
                    "incorrect sender id, expected 0x1c02, is {sender_id}"
                );
                assert!(
                    msg.at_accuracy.almost_eq(6.29720019531250000e+03),
                    "incorrect value for at_accuracy, expected 6.29720019531250000e+03, is {:e}",
                    msg.at_accuracy
                );
                assert_eq!(
                    msg.confidence_and_geoid, 95,
                    "incorrect value for confidence_and_geoid, expected 95, is {}",
                    msg.confidence_and_geoid
                );
                assert!(
                    msg.ct_accuracy.almost_eq(1.94819995117187500e+03),
                    "incorrect value for ct_accuracy, expected 1.94819995117187500e+03, is {:e}",
                    msg.ct_accuracy
                );
                assert_eq!(
                    msg.flags, 72,
                    "incorrect value for flags, expected 72, is {}",
                    msg.flags
                );
                assert!(
                    msg.h_accuracy.almost_eq(2.41019995117187500e+03),
                    "incorrect value for h_accuracy, expected 2.41019995117187500e+03, is {:e}",
                    msg.h_accuracy
                );
                assert!(msg.h_ellipse.orientation.almost_eq( 2.55019995117187500e+03 ), "incorrect value for h_ellipse.orientation, expected 2.55019995117187500e+03, is {:e}", msg.h_ellipse.orientation);
                assert!(msg.h_ellipse.semi_major.almost_eq( 8.24820019531250000e+03 ), "incorrect value for h_ellipse.semi_major, expected 8.24820019531250000e+03, is {:e}", msg.h_ellipse.semi_major);
                assert!(msg.h_ellipse.semi_minor.almost_eq( 3.20219995117187500e+03 ), "incorrect value for h_ellipse.semi_minor, expected 3.20219995117187500e+03, is {:e}", msg.h_ellipse.semi_minor);
                assert!(
                    msg.height.almost_eq(4.25719999999999982e+03),
                    "incorrect value for height, expected 4.25719999999999982e+03, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(7.56319999999999982e+03),
                    "incorrect value for lat, expected 7.56319999999999982e+03, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(8.49420000000000073e+03),
                    "incorrect value for lon, expected 8.49420000000000073e+03, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 27,
                    "incorrect value for n_sats, expected 27, is {}",
                    msg.n_sats
                );
                assert!(msg.orthometric_height.almost_eq( 4.96519999999999982e+03 ), "incorrect value for orthometric_height, expected 4.96519999999999982e+03, is {:e}", msg.orthometric_height);
                assert_eq!(
                    msg.tow, 309229607,
                    "incorrect value for tow, expected 309229607, is {}",
                    msg.tow
                );
                assert!(
                    msg.v_accuracy.almost_eq(5.53920019531250000e+03),
                    "incorrect value for v_accuracy, expected 5.53920019531250000e+03, is {:e}",
                    msg.v_accuracy
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHAcc"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
