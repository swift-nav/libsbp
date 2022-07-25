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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevel.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_protection_level() {
    {
        let mut payload = Cursor::new(vec![
            85, 22, 2, 0, 16, 33, 136, 227, 233, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 82, 195,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgProtectionLevelDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x216,
                    "Incorrect message type, expected 0x216, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert!(
                    msg.height.almost_eq(0.00000000000000000e+00),
                    "incorrect value for height, expected 0.00000000000000000e+00, is {:e}",
                    msg.height
                );
                assert_eq!(
                    msg.hpl, 0,
                    "incorrect value for hpl, expected 0, is {}",
                    msg.hpl
                );
                assert!(
                    msg.lat.almost_eq(0.00000000000000000e+00),
                    "incorrect value for lat, expected 0.00000000000000000e+00, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(0.00000000000000000e+00),
                    "incorrect value for lon, expected 0.00000000000000000e+00, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.tow, 501867400,
                    "incorrect value for tow, expected 501867400, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vpl, 0,
                    "incorrect value for vpl, expected 0, is {}",
                    msg.vpl
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProtectionLevelDepA"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}

#[test]
#[cfg(feature = "json")]
fn test_json2sbp_auto_check_sbp_navigation_msg_protection_level() {
    {
        let json_input = r#"{"tow":501867400,"vpl":0,"hpl":0,"lat":0.0,"lon":0.0,"height":0.0,"flags":0,"preamble":85,"msg_type":534,"sender":4096,"payload":"iOPpHQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","crc":50002,"length":33}"#.as_bytes();

        let sbp_msg = {
            // Json to Sbp message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // Json to Sbp message from payload
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgProtectionLevelDepA(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x216,
                    "Incorrect message type, expected 0x216, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.flags, 0,
                    "incorrect value for flags, expected 0, is {}",
                    msg.flags
                );
                assert!(
                    msg.height.almost_eq(0.00000000000000000e+00),
                    "incorrect value for height, expected 0.00000000000000000e+00, is {:e}",
                    msg.height
                );
                assert_eq!(
                    msg.hpl, 0,
                    "incorrect value for hpl, expected 0, is {}",
                    msg.hpl
                );
                assert!(
                    msg.lat.almost_eq(0.00000000000000000e+00),
                    "incorrect value for lat, expected 0.00000000000000000e+00, is {:e}",
                    msg.lat
                );
                assert!(
                    msg.lon.almost_eq(0.00000000000000000e+00),
                    "incorrect value for lon, expected 0.00000000000000000e+00, is {:e}",
                    msg.lon
                );
                assert_eq!(
                    msg.tow, 501867400,
                    "incorrect value for tow, expected 501867400, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vpl, 0,
                    "incorrect value for vpl, expected 0, is {}",
                    msg.vpl
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProtectionLevelDepA"),
        };
    }
}
