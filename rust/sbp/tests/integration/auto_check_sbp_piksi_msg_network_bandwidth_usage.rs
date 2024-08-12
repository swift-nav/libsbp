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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgNetworkBandwidthUsage.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_piksi_msg_network_bandwidth_usage() {
    {
        let mut payload = Cursor::new(vec![
            85, 189, 0, 207, 121, 200, 94, 105, 178, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 99, 97, 110, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94, 105, 178,
            128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 97, 110, 49, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94, 105, 178, 128, 0, 0, 0, 0, 165, 235, 94, 203, 0, 0,
            0, 0, 237, 14, 148, 240, 184, 220, 202, 218, 101, 116, 104, 48, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 94, 105, 178, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 108, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94, 105, 178, 128, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 115, 105, 116, 48, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 27, 133,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgNetworkBandwidthUsage(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xBD,
                    "Incorrect message type, expected 0xBD, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x79CF,
                    "incorrect sender id, expected 0x79CF, is {sender_id}"
                );
                assert_eq!(
                    msg.interfaces[0].duration, 2159176030,
                    "incorrect value for interfaces[0].duration, expected 2159176030, is {}",
                    msg.interfaces[0].duration
                );
                assert_eq!(msg.interfaces[0].interface_name.as_bytes(), &[99, 97, 110, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[0].interface_name, expected string '{:?}', is '{:?}'", &[99, 97, 110, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[0].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[0].rx_bytes, 0,
                    "incorrect value for interfaces[0].rx_bytes, expected 0, is {}",
                    msg.interfaces[0].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[0].total_bytes, 0,
                    "incorrect value for interfaces[0].total_bytes, expected 0, is {}",
                    msg.interfaces[0].total_bytes
                );
                assert_eq!(
                    msg.interfaces[0].tx_bytes, 0,
                    "incorrect value for interfaces[0].tx_bytes, expected 0, is {}",
                    msg.interfaces[0].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[1].duration, 2159176030,
                    "incorrect value for interfaces[1].duration, expected 2159176030, is {}",
                    msg.interfaces[1].duration
                );
                assert_eq!(msg.interfaces[1].interface_name.as_bytes(), &[99, 97, 110, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[1].interface_name, expected string '{:?}', is '{:?}'", &[99, 97, 110, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[1].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[1].rx_bytes, 0,
                    "incorrect value for interfaces[1].rx_bytes, expected 0, is {}",
                    msg.interfaces[1].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[1].total_bytes, 0,
                    "incorrect value for interfaces[1].total_bytes, expected 0, is {}",
                    msg.interfaces[1].total_bytes
                );
                assert_eq!(
                    msg.interfaces[1].tx_bytes, 0,
                    "incorrect value for interfaces[1].tx_bytes, expected 0, is {}",
                    msg.interfaces[1].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[2].duration, 2159176030,
                    "incorrect value for interfaces[2].duration, expected 2159176030, is {}",
                    msg.interfaces[2].duration
                );
                assert_eq!(msg.interfaces[2].interface_name.as_bytes(), &[101, 116, 104, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[2].interface_name, expected string '{:?}', is '{:?}'", &[101, 116, 104, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[2].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[2].rx_bytes, 4036234989,
                    "incorrect value for interfaces[2].rx_bytes, expected 4036234989, is {}",
                    msg.interfaces[2].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[2].total_bytes, 3411995557,
                    "incorrect value for interfaces[2].total_bytes, expected 3411995557, is {}",
                    msg.interfaces[2].total_bytes
                );
                assert_eq!(
                    msg.interfaces[2].tx_bytes, 3670727864,
                    "incorrect value for interfaces[2].tx_bytes, expected 3670727864, is {}",
                    msg.interfaces[2].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[3].duration, 2159176030,
                    "incorrect value for interfaces[3].duration, expected 2159176030, is {}",
                    msg.interfaces[3].duration
                );
                assert_eq!(msg.interfaces[3].interface_name.as_bytes(), &[108, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[3].interface_name, expected string '{:?}', is '{:?}'", &[108, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[3].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[3].rx_bytes, 0,
                    "incorrect value for interfaces[3].rx_bytes, expected 0, is {}",
                    msg.interfaces[3].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[3].total_bytes, 0,
                    "incorrect value for interfaces[3].total_bytes, expected 0, is {}",
                    msg.interfaces[3].total_bytes
                );
                assert_eq!(
                    msg.interfaces[3].tx_bytes, 0,
                    "incorrect value for interfaces[3].tx_bytes, expected 0, is {}",
                    msg.interfaces[3].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[4].duration, 2159176030,
                    "incorrect value for interfaces[4].duration, expected 2159176030, is {}",
                    msg.interfaces[4].duration
                );
                assert_eq!(msg.interfaces[4].interface_name.as_bytes(), &[115, 105, 116, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[4].interface_name, expected string '{:?}', is '{:?}'", &[115, 105, 116, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[4].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[4].rx_bytes, 0,
                    "incorrect value for interfaces[4].rx_bytes, expected 0, is {}",
                    msg.interfaces[4].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[4].total_bytes, 0,
                    "incorrect value for interfaces[4].total_bytes, expected 0, is {}",
                    msg.interfaces[4].total_bytes
                );
                assert_eq!(
                    msg.interfaces[4].tx_bytes, 0,
                    "incorrect value for interfaces[4].tx_bytes, expected 0, is {}",
                    msg.interfaces[4].tx_bytes
                );
            }
            _ => panic!("Invalid message type! Expected a MsgNetworkBandwidthUsage"),
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
fn test_json2sbp_auto_check_sbp_piksi_msg_network_bandwidth_usage() {
    {
        let json_input = r#"{"preamble": 85, "msg_type": 189, "sender": 31183, "length": 200, "payload": "XmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAY2FuMAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAGNhbjEAAAAAAAAAAAAAAABeabKAAAAAAKXrXssAAAAA7Q6U8LjcytpldGgwAAAAAAAAAAAAAAAAXmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAbG8AAAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAHNpdDAAAAAAAAAAAAAAAAA=", "crc": 34075, "interfaces": [{"duration": 2159176030, "total_bytes": 0, "rx_bytes": 0, "tx_bytes": 0, "interface_name": "can0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"}, {"duration": 2159176030, "total_bytes": 0, "rx_bytes": 0, "tx_bytes": 0, "interface_name": "can1\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"}, {"duration": 2159176030, "total_bytes": 3411995557, "rx_bytes": 4036234989, "tx_bytes": 3670727864, "interface_name": "eth0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"}, {"duration": 2159176030, "total_bytes": 0, "rx_bytes": 0, "tx_bytes": 0, "interface_name": "lo\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"}, {"duration": 2159176030, "total_bytes": 0, "rx_bytes": 0, "tx_bytes": 0, "interface_name": "sit0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"}]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgNetworkBandwidthUsage(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xBD,
                    "Incorrect message type, expected 0xBD, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x79CF,
                    "incorrect sender id, expected 0x79CF, is {sender_id}"
                );
                assert_eq!(
                    msg.interfaces[0].duration, 2159176030,
                    "incorrect value for interfaces[0].duration, expected 2159176030, is {}",
                    msg.interfaces[0].duration
                );
                assert_eq!(msg.interfaces[0].interface_name.as_bytes(), &[99, 97, 110, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[0].interface_name, expected string '{:?}', is '{:?}'", &[99, 97, 110, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[0].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[0].rx_bytes, 0,
                    "incorrect value for interfaces[0].rx_bytes, expected 0, is {}",
                    msg.interfaces[0].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[0].total_bytes, 0,
                    "incorrect value for interfaces[0].total_bytes, expected 0, is {}",
                    msg.interfaces[0].total_bytes
                );
                assert_eq!(
                    msg.interfaces[0].tx_bytes, 0,
                    "incorrect value for interfaces[0].tx_bytes, expected 0, is {}",
                    msg.interfaces[0].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[1].duration, 2159176030,
                    "incorrect value for interfaces[1].duration, expected 2159176030, is {}",
                    msg.interfaces[1].duration
                );
                assert_eq!(msg.interfaces[1].interface_name.as_bytes(), &[99, 97, 110, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[1].interface_name, expected string '{:?}', is '{:?}'", &[99, 97, 110, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[1].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[1].rx_bytes, 0,
                    "incorrect value for interfaces[1].rx_bytes, expected 0, is {}",
                    msg.interfaces[1].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[1].total_bytes, 0,
                    "incorrect value for interfaces[1].total_bytes, expected 0, is {}",
                    msg.interfaces[1].total_bytes
                );
                assert_eq!(
                    msg.interfaces[1].tx_bytes, 0,
                    "incorrect value for interfaces[1].tx_bytes, expected 0, is {}",
                    msg.interfaces[1].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[2].duration, 2159176030,
                    "incorrect value for interfaces[2].duration, expected 2159176030, is {}",
                    msg.interfaces[2].duration
                );
                assert_eq!(msg.interfaces[2].interface_name.as_bytes(), &[101, 116, 104, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[2].interface_name, expected string '{:?}', is '{:?}'", &[101, 116, 104, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[2].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[2].rx_bytes, 4036234989,
                    "incorrect value for interfaces[2].rx_bytes, expected 4036234989, is {}",
                    msg.interfaces[2].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[2].total_bytes, 3411995557,
                    "incorrect value for interfaces[2].total_bytes, expected 3411995557, is {}",
                    msg.interfaces[2].total_bytes
                );
                assert_eq!(
                    msg.interfaces[2].tx_bytes, 3670727864,
                    "incorrect value for interfaces[2].tx_bytes, expected 3670727864, is {}",
                    msg.interfaces[2].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[3].duration, 2159176030,
                    "incorrect value for interfaces[3].duration, expected 2159176030, is {}",
                    msg.interfaces[3].duration
                );
                assert_eq!(msg.interfaces[3].interface_name.as_bytes(), &[108, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[3].interface_name, expected string '{:?}', is '{:?}'", &[108, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[3].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[3].rx_bytes, 0,
                    "incorrect value for interfaces[3].rx_bytes, expected 0, is {}",
                    msg.interfaces[3].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[3].total_bytes, 0,
                    "incorrect value for interfaces[3].total_bytes, expected 0, is {}",
                    msg.interfaces[3].total_bytes
                );
                assert_eq!(
                    msg.interfaces[3].tx_bytes, 0,
                    "incorrect value for interfaces[3].tx_bytes, expected 0, is {}",
                    msg.interfaces[3].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[4].duration, 2159176030,
                    "incorrect value for interfaces[4].duration, expected 2159176030, is {}",
                    msg.interfaces[4].duration
                );
                assert_eq!(msg.interfaces[4].interface_name.as_bytes(), &[115, 105, 116, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[4].interface_name, expected string '{:?}', is '{:?}'", &[115, 105, 116, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[4].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[4].rx_bytes, 0,
                    "incorrect value for interfaces[4].rx_bytes, expected 0, is {}",
                    msg.interfaces[4].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[4].total_bytes, 0,
                    "incorrect value for interfaces[4].total_bytes, expected 0, is {}",
                    msg.interfaces[4].total_bytes
                );
                assert_eq!(
                    msg.interfaces[4].tx_bytes, 0,
                    "incorrect value for interfaces[4].tx_bytes, expected 0, is {}",
                    msg.interfaces[4].tx_bytes
                );
            }
            _ => panic!("Invalid message type! Expected a MsgNetworkBandwidthUsage"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_piksi_msg_network_bandwidth_usage`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_piksi_msg_network_bandwidth_usage() {
    {
        let mut payload = Cursor::new(vec![
            85, 189, 0, 207, 121, 200, 94, 105, 178, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 99, 97, 110, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94, 105, 178,
            128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 97, 110, 49, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94, 105, 178, 128, 0, 0, 0, 0, 165, 235, 94, 203, 0, 0,
            0, 0, 237, 14, 148, 240, 184, 220, 202, 218, 101, 116, 104, 48, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 94, 105, 178, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 108, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94, 105, 178, 128, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 115, 105, 116, 48, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 27, 133,
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
        let sbp_msg = sbp::messages::Sbp::MsgNetworkBandwidthUsage(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgNetworkBandwidthUsage(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xBD,
                    "Incorrect message type, expected 0xBD, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x79CF,
                    "incorrect sender id, expected 0x79CF, is {sender_id}"
                );
                assert_eq!(
                    msg.interfaces[0].duration, 2159176030,
                    "incorrect value for interfaces[0].duration, expected 2159176030, is {}",
                    msg.interfaces[0].duration
                );
                assert_eq!(msg.interfaces[0].interface_name.as_bytes(), &[99, 97, 110, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[0].interface_name, expected string '{:?}', is '{:?}'", &[99, 97, 110, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[0].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[0].rx_bytes, 0,
                    "incorrect value for interfaces[0].rx_bytes, expected 0, is {}",
                    msg.interfaces[0].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[0].total_bytes, 0,
                    "incorrect value for interfaces[0].total_bytes, expected 0, is {}",
                    msg.interfaces[0].total_bytes
                );
                assert_eq!(
                    msg.interfaces[0].tx_bytes, 0,
                    "incorrect value for interfaces[0].tx_bytes, expected 0, is {}",
                    msg.interfaces[0].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[1].duration, 2159176030,
                    "incorrect value for interfaces[1].duration, expected 2159176030, is {}",
                    msg.interfaces[1].duration
                );
                assert_eq!(msg.interfaces[1].interface_name.as_bytes(), &[99, 97, 110, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[1].interface_name, expected string '{:?}', is '{:?}'", &[99, 97, 110, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[1].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[1].rx_bytes, 0,
                    "incorrect value for interfaces[1].rx_bytes, expected 0, is {}",
                    msg.interfaces[1].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[1].total_bytes, 0,
                    "incorrect value for interfaces[1].total_bytes, expected 0, is {}",
                    msg.interfaces[1].total_bytes
                );
                assert_eq!(
                    msg.interfaces[1].tx_bytes, 0,
                    "incorrect value for interfaces[1].tx_bytes, expected 0, is {}",
                    msg.interfaces[1].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[2].duration, 2159176030,
                    "incorrect value for interfaces[2].duration, expected 2159176030, is {}",
                    msg.interfaces[2].duration
                );
                assert_eq!(msg.interfaces[2].interface_name.as_bytes(), &[101, 116, 104, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[2].interface_name, expected string '{:?}', is '{:?}'", &[101, 116, 104, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[2].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[2].rx_bytes, 4036234989,
                    "incorrect value for interfaces[2].rx_bytes, expected 4036234989, is {}",
                    msg.interfaces[2].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[2].total_bytes, 3411995557,
                    "incorrect value for interfaces[2].total_bytes, expected 3411995557, is {}",
                    msg.interfaces[2].total_bytes
                );
                assert_eq!(
                    msg.interfaces[2].tx_bytes, 3670727864,
                    "incorrect value for interfaces[2].tx_bytes, expected 3670727864, is {}",
                    msg.interfaces[2].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[3].duration, 2159176030,
                    "incorrect value for interfaces[3].duration, expected 2159176030, is {}",
                    msg.interfaces[3].duration
                );
                assert_eq!(msg.interfaces[3].interface_name.as_bytes(), &[108, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[3].interface_name, expected string '{:?}', is '{:?}'", &[108, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[3].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[3].rx_bytes, 0,
                    "incorrect value for interfaces[3].rx_bytes, expected 0, is {}",
                    msg.interfaces[3].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[3].total_bytes, 0,
                    "incorrect value for interfaces[3].total_bytes, expected 0, is {}",
                    msg.interfaces[3].total_bytes
                );
                assert_eq!(
                    msg.interfaces[3].tx_bytes, 0,
                    "incorrect value for interfaces[3].tx_bytes, expected 0, is {}",
                    msg.interfaces[3].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[4].duration, 2159176030,
                    "incorrect value for interfaces[4].duration, expected 2159176030, is {}",
                    msg.interfaces[4].duration
                );
                assert_eq!(msg.interfaces[4].interface_name.as_bytes(), &[115, 105, 116, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], "incorrect value for msg.interfaces[4].interface_name, expected string '{:?}', is '{:?}'", &[115, 105, 116, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], msg.interfaces[4].interface_name.as_bytes());
                assert_eq!(
                    msg.interfaces[4].rx_bytes, 0,
                    "incorrect value for interfaces[4].rx_bytes, expected 0, is {}",
                    msg.interfaces[4].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[4].total_bytes, 0,
                    "incorrect value for interfaces[4].total_bytes, expected 0, is {}",
                    msg.interfaces[4].total_bytes
                );
                assert_eq!(
                    msg.interfaces[4].tx_bytes, 0,
                    "incorrect value for interfaces[4].tx_bytes, expected 0, is {}",
                    msg.interfaces[4].tx_bytes
                );
            }
            _ => panic!("Invalid message type! Expected a MsgNetworkBandwidthUsage"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
