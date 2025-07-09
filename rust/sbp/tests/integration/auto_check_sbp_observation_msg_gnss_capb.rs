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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGnssCapb.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_observation_msg_gnss_capb() {
    {
        let mut payload = Cursor::new(vec![
            85, 150, 0, 123, 0, 110, 176, 207, 6, 0, 106, 8, 26, 171, 80, 64, 0, 0, 0, 0, 81, 173,
            144, 46, 0, 0, 0, 0, 209, 139, 93, 108, 0, 0, 0, 0, 252, 204, 200, 0, 205, 92, 30, 49,
            240, 203, 21, 24, 212, 93, 182, 32, 0, 0, 0, 0, 105, 32, 192, 27, 0, 0, 0, 0, 40, 75,
            250, 114, 0, 0, 0, 0, 119, 147, 123, 81, 0, 0, 0, 0, 85, 89, 4, 2, 0, 0, 0, 0, 233,
            116, 137, 22, 0, 0, 0, 0, 199, 109, 219, 11, 221, 171, 248, 82, 0, 0, 0, 0, 252, 62,
            221, 28, 0, 0, 0, 0, 163, 90,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgGnssCapb(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x96,
                    "Incorrect message type, expected 0x96, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert_eq!(
                    msg.gc.bds_active, 1929005864,
                    "incorrect value for gc.bds_active, expected 1929005864, is {}",
                    msg.gc.bds_active
                );
                assert_eq!(
                    msg.gc.bds_b2, 33839445,
                    "incorrect value for gc.bds_b2, expected 33839445, is {}",
                    msg.gc.bds_b2
                );
                assert_eq!(
                    msg.gc.bds_b2a, 378107113,
                    "incorrect value for gc.bds_b2a, expected 378107113, is {}",
                    msg.gc.bds_b2a
                );
                assert_eq!(
                    msg.gc.bds_d2nav, 1367053175,
                    "incorrect value for gc.bds_d2nav, expected 1367053175, is {}",
                    msg.gc.bds_d2nav
                );
                assert_eq!(
                    msg.gc.gal_active, 1392028637,
                    "incorrect value for gc.gal_active, expected 1392028637, is {}",
                    msg.gc.gal_active
                );
                assert_eq!(
                    msg.gc.gal_e5, 484261628,
                    "incorrect value for gc.gal_e5, expected 484261628, is {}",
                    msg.gc.gal_e5
                );
                assert_eq!(
                    msg.gc.glo_active, 13159676,
                    "incorrect value for gc.glo_active, expected 13159676, is {}",
                    msg.gc.glo_active
                );
                assert_eq!(
                    msg.gc.glo_l2of, 824073421,
                    "incorrect value for gc.glo_l2of, expected 824073421, is {}",
                    msg.gc.glo_l2of
                );
                assert_eq!(
                    msg.gc.glo_l3, 404081648,
                    "incorrect value for gc.glo_l3, expected 404081648, is {}",
                    msg.gc.glo_l3
                );
                assert_eq!(
                    msg.gc.gps_active, 1079028506,
                    "incorrect value for gc.gps_active, expected 1079028506, is {}",
                    msg.gc.gps_active
                );
                assert_eq!(
                    msg.gc.gps_l2c, 781233489,
                    "incorrect value for gc.gps_l2c, expected 781233489, is {}",
                    msg.gc.gps_l2c
                );
                assert_eq!(
                    msg.gc.gps_l5, 1818069969,
                    "incorrect value for gc.gps_l5, expected 1818069969, is {}",
                    msg.gc.gps_l5
                );
                assert_eq!(
                    msg.gc.qzss_active, 198929863,
                    "incorrect value for gc.qzss_active, expected 198929863, is {}",
                    msg.gc.qzss_active
                );
                assert_eq!(
                    msg.gc.sbas_active, 548822484,
                    "incorrect value for gc.sbas_active, expected 548822484, is {}",
                    msg.gc.sbas_active
                );
                assert_eq!(
                    msg.gc.sbas_l5, 465576041,
                    "incorrect value for gc.sbas_l5, expected 465576041, is {}",
                    msg.gc.sbas_l5
                );
                assert_eq!(
                    msg.t_nmct.tow, 446384,
                    "incorrect value for t_nmct.tow, expected 446384, is {}",
                    msg.t_nmct.tow
                );
                assert_eq!(
                    msg.t_nmct.wn, 2154,
                    "incorrect value for t_nmct.wn, expected 2154, is {}",
                    msg.t_nmct.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGnssCapb"),
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
fn test_json2sbp_auto_check_sbp_observation_msg_gnss_capb() {
    {
        let json_input = r#"{"crc":23203,"length":110,"msg_type":150,"payload":"sM8GAGoIGqtQQAAAAABRrZAuAAAAANGLXWwAAAAA/MzIAM1cHjHwyxUY1F22IAAAAABpIMAbAAAAAChL+nIAAAAAd5N7UQAAAABVWQQCAAAAAOl0iRYAAAAAx23bC92r+FIAAAAA/D7dHAAAAAA=","preamble":85,"sender":123,"t_nmct":{"tow":446384,"wn":2154},"gc":{"gps_active":1079028506,"gps_l2c":781233489,"gps_l5":1818069969,"glo_active":13159676,"glo_l2of":824073421,"glo_l3":404081648,"sbas_active":548822484,"sbas_l5":465576041,"bds_active":1929005864,"bds_d2nav":1367053175,"bds_b2":33839445,"bds_b2a":378107113,"qzss_active":198929863,"gal_active":1392028637,"gal_e5":484261628}}"#.as_bytes();

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
            sbp::messages::Sbp::MsgGnssCapb(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x96,
                    "Incorrect message type, expected 0x96, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert_eq!(
                    msg.gc.bds_active, 1929005864,
                    "incorrect value for gc.bds_active, expected 1929005864, is {}",
                    msg.gc.bds_active
                );
                assert_eq!(
                    msg.gc.bds_b2, 33839445,
                    "incorrect value for gc.bds_b2, expected 33839445, is {}",
                    msg.gc.bds_b2
                );
                assert_eq!(
                    msg.gc.bds_b2a, 378107113,
                    "incorrect value for gc.bds_b2a, expected 378107113, is {}",
                    msg.gc.bds_b2a
                );
                assert_eq!(
                    msg.gc.bds_d2nav, 1367053175,
                    "incorrect value for gc.bds_d2nav, expected 1367053175, is {}",
                    msg.gc.bds_d2nav
                );
                assert_eq!(
                    msg.gc.gal_active, 1392028637,
                    "incorrect value for gc.gal_active, expected 1392028637, is {}",
                    msg.gc.gal_active
                );
                assert_eq!(
                    msg.gc.gal_e5, 484261628,
                    "incorrect value for gc.gal_e5, expected 484261628, is {}",
                    msg.gc.gal_e5
                );
                assert_eq!(
                    msg.gc.glo_active, 13159676,
                    "incorrect value for gc.glo_active, expected 13159676, is {}",
                    msg.gc.glo_active
                );
                assert_eq!(
                    msg.gc.glo_l2of, 824073421,
                    "incorrect value for gc.glo_l2of, expected 824073421, is {}",
                    msg.gc.glo_l2of
                );
                assert_eq!(
                    msg.gc.glo_l3, 404081648,
                    "incorrect value for gc.glo_l3, expected 404081648, is {}",
                    msg.gc.glo_l3
                );
                assert_eq!(
                    msg.gc.gps_active, 1079028506,
                    "incorrect value for gc.gps_active, expected 1079028506, is {}",
                    msg.gc.gps_active
                );
                assert_eq!(
                    msg.gc.gps_l2c, 781233489,
                    "incorrect value for gc.gps_l2c, expected 781233489, is {}",
                    msg.gc.gps_l2c
                );
                assert_eq!(
                    msg.gc.gps_l5, 1818069969,
                    "incorrect value for gc.gps_l5, expected 1818069969, is {}",
                    msg.gc.gps_l5
                );
                assert_eq!(
                    msg.gc.qzss_active, 198929863,
                    "incorrect value for gc.qzss_active, expected 198929863, is {}",
                    msg.gc.qzss_active
                );
                assert_eq!(
                    msg.gc.sbas_active, 548822484,
                    "incorrect value for gc.sbas_active, expected 548822484, is {}",
                    msg.gc.sbas_active
                );
                assert_eq!(
                    msg.gc.sbas_l5, 465576041,
                    "incorrect value for gc.sbas_l5, expected 465576041, is {}",
                    msg.gc.sbas_l5
                );
                assert_eq!(
                    msg.t_nmct.tow, 446384,
                    "incorrect value for t_nmct.tow, expected 446384, is {}",
                    msg.t_nmct.tow
                );
                assert_eq!(
                    msg.t_nmct.wn, 2154,
                    "incorrect value for t_nmct.wn, expected 2154, is {}",
                    msg.t_nmct.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGnssCapb"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_observation_msg_gnss_capb`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_observation_msg_gnss_capb() {
    {
        let mut payload = Cursor::new(vec![
            85, 150, 0, 123, 0, 110, 176, 207, 6, 0, 106, 8, 26, 171, 80, 64, 0, 0, 0, 0, 81, 173,
            144, 46, 0, 0, 0, 0, 209, 139, 93, 108, 0, 0, 0, 0, 252, 204, 200, 0, 205, 92, 30, 49,
            240, 203, 21, 24, 212, 93, 182, 32, 0, 0, 0, 0, 105, 32, 192, 27, 0, 0, 0, 0, 40, 75,
            250, 114, 0, 0, 0, 0, 119, 147, 123, 81, 0, 0, 0, 0, 85, 89, 4, 2, 0, 0, 0, 0, 233,
            116, 137, 22, 0, 0, 0, 0, 199, 109, 219, 11, 221, 171, 248, 82, 0, 0, 0, 0, 252, 62,
            221, 28, 0, 0, 0, 0, 163, 90,
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
        let sbp_msg = sbp::messages::Sbp::MsgGnssCapb(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgGnssCapb(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x96,
                    "Incorrect message type, expected 0x96, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x007b,
                    "incorrect sender id, expected 0x007b, is {sender_id}"
                );
                assert_eq!(
                    msg.gc.bds_active, 1929005864,
                    "incorrect value for gc.bds_active, expected 1929005864, is {}",
                    msg.gc.bds_active
                );
                assert_eq!(
                    msg.gc.bds_b2, 33839445,
                    "incorrect value for gc.bds_b2, expected 33839445, is {}",
                    msg.gc.bds_b2
                );
                assert_eq!(
                    msg.gc.bds_b2a, 378107113,
                    "incorrect value for gc.bds_b2a, expected 378107113, is {}",
                    msg.gc.bds_b2a
                );
                assert_eq!(
                    msg.gc.bds_d2nav, 1367053175,
                    "incorrect value for gc.bds_d2nav, expected 1367053175, is {}",
                    msg.gc.bds_d2nav
                );
                assert_eq!(
                    msg.gc.gal_active, 1392028637,
                    "incorrect value for gc.gal_active, expected 1392028637, is {}",
                    msg.gc.gal_active
                );
                assert_eq!(
                    msg.gc.gal_e5, 484261628,
                    "incorrect value for gc.gal_e5, expected 484261628, is {}",
                    msg.gc.gal_e5
                );
                assert_eq!(
                    msg.gc.glo_active, 13159676,
                    "incorrect value for gc.glo_active, expected 13159676, is {}",
                    msg.gc.glo_active
                );
                assert_eq!(
                    msg.gc.glo_l2of, 824073421,
                    "incorrect value for gc.glo_l2of, expected 824073421, is {}",
                    msg.gc.glo_l2of
                );
                assert_eq!(
                    msg.gc.glo_l3, 404081648,
                    "incorrect value for gc.glo_l3, expected 404081648, is {}",
                    msg.gc.glo_l3
                );
                assert_eq!(
                    msg.gc.gps_active, 1079028506,
                    "incorrect value for gc.gps_active, expected 1079028506, is {}",
                    msg.gc.gps_active
                );
                assert_eq!(
                    msg.gc.gps_l2c, 781233489,
                    "incorrect value for gc.gps_l2c, expected 781233489, is {}",
                    msg.gc.gps_l2c
                );
                assert_eq!(
                    msg.gc.gps_l5, 1818069969,
                    "incorrect value for gc.gps_l5, expected 1818069969, is {}",
                    msg.gc.gps_l5
                );
                assert_eq!(
                    msg.gc.qzss_active, 198929863,
                    "incorrect value for gc.qzss_active, expected 198929863, is {}",
                    msg.gc.qzss_active
                );
                assert_eq!(
                    msg.gc.sbas_active, 548822484,
                    "incorrect value for gc.sbas_active, expected 548822484, is {}",
                    msg.gc.sbas_active
                );
                assert_eq!(
                    msg.gc.sbas_l5, 465576041,
                    "incorrect value for gc.sbas_l5, expected 465576041, is {}",
                    msg.gc.sbas_l5
                );
                assert_eq!(
                    msg.t_nmct.tow, 446384,
                    "incorrect value for t_nmct.tow, expected 446384, is {}",
                    msg.t_nmct.tow
                );
                assert_eq!(
                    msg.t_nmct.wn, 2154,
                    "incorrect value for t_nmct.wn, expected 2154, is {}",
                    msg.t_nmct.wn
                );
            }
            _ => panic!("Invalid message type! Expected a MsgGnssCapb"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
