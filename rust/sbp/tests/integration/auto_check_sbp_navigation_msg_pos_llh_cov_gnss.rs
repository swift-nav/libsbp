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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhCovGnss.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_navigation_msg_pos_llh_cov_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 49, 2, 0, 16, 54, 24, 229, 233, 29, 73, 123, 28, 207, 101, 234, 66, 64, 100, 168,
            19, 20, 86, 146, 94, 192, 214, 198, 35, 120, 209, 100, 49, 192, 12, 102, 245, 59, 6,
            181, 192, 185, 168, 79, 243, 58, 96, 60, 148, 59, 253, 58, 93, 186, 159, 174, 6, 61,
            18, 4, 10, 196,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhCovGnss(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x231,
                    "Incorrect message type, expected 0x231, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert!(
                    msg.cov_d_d.almost_eq(3.28813754022121429e-02),
                    "incorrect value for cov_d_d, expected 3.28813754022121429e-02, is {:e}",
                    msg.cov_d_d
                );
                assert!(
                    msg.cov_e_d.almost_eq(-8.43927089590579271e-04),
                    "incorrect value for cov_e_d, expected -8.43927089590579271e-04, is {:e}",
                    msg.cov_e_d
                );
                assert!(
                    msg.cov_e_e.almost_eq(4.52379882335662842e-03),
                    "incorrect value for cov_e_e, expected 4.52379882335662842e-03, is {:e}",
                    msg.cov_e_e
                );
                assert!(
                    msg.cov_n_d.almost_eq(1.85631681233644485e-03),
                    "incorrect value for cov_n_d, expected 1.85631681233644485e-03, is {:e}",
                    msg.cov_n_d
                );
                assert!(
                    msg.cov_n_e.almost_eq(-3.67559667211025953e-04),
                    "incorrect value for cov_n_e, expected -3.67559667211025953e-04, is {:e}",
                    msg.cov_n_e
                );
                assert!(
                    msg.cov_n_n.almost_eq(7.48897157609462738e-03),
                    "incorrect value for cov_n_n, expected 7.48897157609462738e-03, is {:e}",
                    msg.cov_n_n
                );
                assert_eq!(
                    msg.flags, 4,
                    "incorrect value for flags, expected 4, is {}",
                    msg.flags
                );
                assert!(
                    msg.height.almost_eq(-1.73938212478013483e+01),
                    "incorrect value for height, expected -1.73938212478013483e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.78312319649763324e+01),
                    "incorrect value for lat, expected 3.78312319649763324e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22286503810116812e+02),
                    "incorrect value for lon, expected -1.22286503810116812e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 18,
                    "incorrect value for n_sats, expected 18, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501867800,
                    "incorrect value for tow, expected 501867800, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHCovGnss"),
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
fn test_json2sbp_auto_check_sbp_navigation_msg_pos_llh_cov_gnss() {
    {
        let json_input = r#"{"tow":501867800,"lat":37.83123196497633,"lon":-122.28650381011681,"height":-17.39382124780135,"cov_n_n":0.007488971576094627,"cov_n_e":-0.00036755966721102595,"cov_n_d":0.0018563168123364449,"cov_e_e":0.004523798823356628,"cov_e_d":-0.0008439270895905793,"cov_d_d":0.03288137540221214,"n_sats":18,"flags":4,"preamble":85,"msg_type":561,"sender":4096,"payload":"GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwAxm9TsGtcC5qE/zOmA8lDv9Ol26n64GPRIE","crc":50186,"length":54}"#.as_bytes();

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
            sbp::messages::Sbp::MsgPosLlhCovGnss(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x231,
                    "Incorrect message type, expected 0x231, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert!(
                    msg.cov_d_d.almost_eq(3.28813754022121429e-02),
                    "incorrect value for cov_d_d, expected 3.28813754022121429e-02, is {:e}",
                    msg.cov_d_d
                );
                assert!(
                    msg.cov_e_d.almost_eq(-8.43927089590579271e-04),
                    "incorrect value for cov_e_d, expected -8.43927089590579271e-04, is {:e}",
                    msg.cov_e_d
                );
                assert!(
                    msg.cov_e_e.almost_eq(4.52379882335662842e-03),
                    "incorrect value for cov_e_e, expected 4.52379882335662842e-03, is {:e}",
                    msg.cov_e_e
                );
                assert!(
                    msg.cov_n_d.almost_eq(1.85631681233644485e-03),
                    "incorrect value for cov_n_d, expected 1.85631681233644485e-03, is {:e}",
                    msg.cov_n_d
                );
                assert!(
                    msg.cov_n_e.almost_eq(-3.67559667211025953e-04),
                    "incorrect value for cov_n_e, expected -3.67559667211025953e-04, is {:e}",
                    msg.cov_n_e
                );
                assert!(
                    msg.cov_n_n.almost_eq(7.48897157609462738e-03),
                    "incorrect value for cov_n_n, expected 7.48897157609462738e-03, is {:e}",
                    msg.cov_n_n
                );
                assert_eq!(
                    msg.flags, 4,
                    "incorrect value for flags, expected 4, is {}",
                    msg.flags
                );
                assert!(
                    msg.height.almost_eq(-1.73938212478013483e+01),
                    "incorrect value for height, expected -1.73938212478013483e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.78312319649763324e+01),
                    "incorrect value for lat, expected 3.78312319649763324e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22286503810116812e+02),
                    "incorrect value for lon, expected -1.22286503810116812e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 18,
                    "incorrect value for n_sats, expected 18, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501867800,
                    "incorrect value for tow, expected 501867800, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHCovGnss"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_navigation_msg_pos_llh_cov_gnss`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_navigation_msg_pos_llh_cov_gnss() {
    {
        let mut payload = Cursor::new(vec![
            85, 49, 2, 0, 16, 54, 24, 229, 233, 29, 73, 123, 28, 207, 101, 234, 66, 64, 100, 168,
            19, 20, 86, 146, 94, 192, 214, 198, 35, 120, 209, 100, 49, 192, 12, 102, 245, 59, 6,
            181, 192, 185, 168, 79, 243, 58, 96, 60, 148, 59, 253, 58, 93, 186, 159, 174, 6, 61,
            18, 4, 10, 196,
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
        let sbp_msg = sbp::messages::Sbp::MsgPosLlhCovGnss(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgPosLlhCovGnss(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x231,
                    "Incorrect message type, expected 0x231, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert!(
                    msg.cov_d_d.almost_eq(3.28813754022121429e-02),
                    "incorrect value for cov_d_d, expected 3.28813754022121429e-02, is {:e}",
                    msg.cov_d_d
                );
                assert!(
                    msg.cov_e_d.almost_eq(-8.43927089590579271e-04),
                    "incorrect value for cov_e_d, expected -8.43927089590579271e-04, is {:e}",
                    msg.cov_e_d
                );
                assert!(
                    msg.cov_e_e.almost_eq(4.52379882335662842e-03),
                    "incorrect value for cov_e_e, expected 4.52379882335662842e-03, is {:e}",
                    msg.cov_e_e
                );
                assert!(
                    msg.cov_n_d.almost_eq(1.85631681233644485e-03),
                    "incorrect value for cov_n_d, expected 1.85631681233644485e-03, is {:e}",
                    msg.cov_n_d
                );
                assert!(
                    msg.cov_n_e.almost_eq(-3.67559667211025953e-04),
                    "incorrect value for cov_n_e, expected -3.67559667211025953e-04, is {:e}",
                    msg.cov_n_e
                );
                assert!(
                    msg.cov_n_n.almost_eq(7.48897157609462738e-03),
                    "incorrect value for cov_n_n, expected 7.48897157609462738e-03, is {:e}",
                    msg.cov_n_n
                );
                assert_eq!(
                    msg.flags, 4,
                    "incorrect value for flags, expected 4, is {}",
                    msg.flags
                );
                assert!(
                    msg.height.almost_eq(-1.73938212478013483e+01),
                    "incorrect value for height, expected -1.73938212478013483e+01, is {:e}",
                    msg.height
                );
                assert!(
                    msg.lat.almost_eq(3.78312319649763324e+01),
                    "incorrect value for lat, expected 3.78312319649763324e+01, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(-1.22286503810116812e+02),
                    "incorrect value for lon, expected -1.22286503810116812e+02, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.n_sats, 18,
                    "incorrect value for n_sats, expected 18, is {}",
                    msg.n_sats
                );
                assert_eq!(
                    msg.tow, 501867800,
                    "incorrect value for tow, expected 501867800, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgPosLLHCovGnss"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
