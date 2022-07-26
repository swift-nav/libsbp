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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/sbas/test_MsgSbasRaw.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_sbas_msg_sbas_raw() {
    {
        let mut payload = Cursor::new(vec![
            85, 119, 119, 28, 200, 34, 131, 2, 201, 228, 233, 29, 4, 23, 255, 0, 23, 255, 0, 23,
            255, 127, 240, 2, 255, 192, 3, 127, 247, 255, 127, 247, 255, 229, 229, 238, 170, 175,
            255, 240, 167, 14,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgSbasRaw(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x7777,
                    "Incorrect message type, expected 0x7777, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc81c,
                    "incorrect sender id, expected 0xc81c, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.data[0], 23,
                    "incorrect value for data[0], expected 23, is {}",
                    msg.data[0]
                );
                assert_eq!(
                    msg.data[1], 255,
                    "incorrect value for data[1], expected 255, is {}",
                    msg.data[1]
                );
                assert_eq!(
                    msg.data[2], 0,
                    "incorrect value for data[2], expected 0, is {}",
                    msg.data[2]
                );
                assert_eq!(
                    msg.data[3], 23,
                    "incorrect value for data[3], expected 23, is {}",
                    msg.data[3]
                );
                assert_eq!(
                    msg.data[4], 255,
                    "incorrect value for data[4], expected 255, is {}",
                    msg.data[4]
                );
                assert_eq!(
                    msg.data[5], 0,
                    "incorrect value for data[5], expected 0, is {}",
                    msg.data[5]
                );
                assert_eq!(
                    msg.data[6], 23,
                    "incorrect value for data[6], expected 23, is {}",
                    msg.data[6]
                );
                assert_eq!(
                    msg.data[7], 255,
                    "incorrect value for data[7], expected 255, is {}",
                    msg.data[7]
                );
                assert_eq!(
                    msg.data[8], 127,
                    "incorrect value for data[8], expected 127, is {}",
                    msg.data[8]
                );
                assert_eq!(
                    msg.data[9], 240,
                    "incorrect value for data[9], expected 240, is {}",
                    msg.data[9]
                );
                assert_eq!(
                    msg.data[10], 2,
                    "incorrect value for data[10], expected 2, is {}",
                    msg.data[10]
                );
                assert_eq!(
                    msg.data[11], 255,
                    "incorrect value for data[11], expected 255, is {}",
                    msg.data[11]
                );
                assert_eq!(
                    msg.data[12], 192,
                    "incorrect value for data[12], expected 192, is {}",
                    msg.data[12]
                );
                assert_eq!(
                    msg.data[13], 3,
                    "incorrect value for data[13], expected 3, is {}",
                    msg.data[13]
                );
                assert_eq!(
                    msg.data[14], 127,
                    "incorrect value for data[14], expected 127, is {}",
                    msg.data[14]
                );
                assert_eq!(
                    msg.data[15], 247,
                    "incorrect value for data[15], expected 247, is {}",
                    msg.data[15]
                );
                assert_eq!(
                    msg.data[16], 255,
                    "incorrect value for data[16], expected 255, is {}",
                    msg.data[16]
                );
                assert_eq!(
                    msg.data[17], 127,
                    "incorrect value for data[17], expected 127, is {}",
                    msg.data[17]
                );
                assert_eq!(
                    msg.data[18], 247,
                    "incorrect value for data[18], expected 247, is {}",
                    msg.data[18]
                );
                assert_eq!(
                    msg.data[19], 255,
                    "incorrect value for data[19], expected 255, is {}",
                    msg.data[19]
                );
                assert_eq!(
                    msg.data[20], 229,
                    "incorrect value for data[20], expected 229, is {}",
                    msg.data[20]
                );
                assert_eq!(
                    msg.data[21], 229,
                    "incorrect value for data[21], expected 229, is {}",
                    msg.data[21]
                );
                assert_eq!(
                    msg.data[22], 238,
                    "incorrect value for data[22], expected 238, is {}",
                    msg.data[22]
                );
                assert_eq!(
                    msg.data[23], 170,
                    "incorrect value for data[23], expected 170, is {}",
                    msg.data[23]
                );
                assert_eq!(
                    msg.data[24], 175,
                    "incorrect value for data[24], expected 175, is {}",
                    msg.data[24]
                );
                assert_eq!(
                    msg.data[25], 255,
                    "incorrect value for data[25], expected 255, is {}",
                    msg.data[25]
                );
                assert_eq!(
                    msg.data[26], 240,
                    "incorrect value for data[26], expected 240, is {}",
                    msg.data[26]
                );
                assert_eq!(
                    msg.message_type, 4,
                    "incorrect value for message_type, expected 4, is {}",
                    msg.message_type
                );
                assert_eq!(
                    msg.sid.code, 2,
                    "incorrect value for sid.code, expected 2, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 131,
                    "incorrect value for sid.sat, expected 131, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.tow, 501867721,
                    "incorrect value for tow, expected 501867721, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSbasRaw"),
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
fn test_json2sbp_auto_check_sbp_sbas_msg_sbas_raw() {
    {
        let json_input = r#"{"sid":{"sat":131,"code":2},"tow":501867721,"message_type":4,"data":[23,255,0,23,255,0,23,255,127,240,2,255,192,3,127,247,255,127,247,255,229,229,238,170,175,255,240],"preamble":85,"msg_type":30583,"sender":51228,"payload":"gwLJ5OkdBBf/ABf/ABf/f/AC/8ADf/f/f/f/5eXuqq//8A==","crc":3751,"length":34}"#.as_bytes();

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
            sbp::messages::Sbp::MsgSbasRaw(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x7777,
                    "Incorrect message type, expected 0x7777, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc81c,
                    "incorrect sender id, expected 0xc81c, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.data[0], 23,
                    "incorrect value for data[0], expected 23, is {}",
                    msg.data[0]
                );
                assert_eq!(
                    msg.data[1], 255,
                    "incorrect value for data[1], expected 255, is {}",
                    msg.data[1]
                );
                assert_eq!(
                    msg.data[2], 0,
                    "incorrect value for data[2], expected 0, is {}",
                    msg.data[2]
                );
                assert_eq!(
                    msg.data[3], 23,
                    "incorrect value for data[3], expected 23, is {}",
                    msg.data[3]
                );
                assert_eq!(
                    msg.data[4], 255,
                    "incorrect value for data[4], expected 255, is {}",
                    msg.data[4]
                );
                assert_eq!(
                    msg.data[5], 0,
                    "incorrect value for data[5], expected 0, is {}",
                    msg.data[5]
                );
                assert_eq!(
                    msg.data[6], 23,
                    "incorrect value for data[6], expected 23, is {}",
                    msg.data[6]
                );
                assert_eq!(
                    msg.data[7], 255,
                    "incorrect value for data[7], expected 255, is {}",
                    msg.data[7]
                );
                assert_eq!(
                    msg.data[8], 127,
                    "incorrect value for data[8], expected 127, is {}",
                    msg.data[8]
                );
                assert_eq!(
                    msg.data[9], 240,
                    "incorrect value for data[9], expected 240, is {}",
                    msg.data[9]
                );
                assert_eq!(
                    msg.data[10], 2,
                    "incorrect value for data[10], expected 2, is {}",
                    msg.data[10]
                );
                assert_eq!(
                    msg.data[11], 255,
                    "incorrect value for data[11], expected 255, is {}",
                    msg.data[11]
                );
                assert_eq!(
                    msg.data[12], 192,
                    "incorrect value for data[12], expected 192, is {}",
                    msg.data[12]
                );
                assert_eq!(
                    msg.data[13], 3,
                    "incorrect value for data[13], expected 3, is {}",
                    msg.data[13]
                );
                assert_eq!(
                    msg.data[14], 127,
                    "incorrect value for data[14], expected 127, is {}",
                    msg.data[14]
                );
                assert_eq!(
                    msg.data[15], 247,
                    "incorrect value for data[15], expected 247, is {}",
                    msg.data[15]
                );
                assert_eq!(
                    msg.data[16], 255,
                    "incorrect value for data[16], expected 255, is {}",
                    msg.data[16]
                );
                assert_eq!(
                    msg.data[17], 127,
                    "incorrect value for data[17], expected 127, is {}",
                    msg.data[17]
                );
                assert_eq!(
                    msg.data[18], 247,
                    "incorrect value for data[18], expected 247, is {}",
                    msg.data[18]
                );
                assert_eq!(
                    msg.data[19], 255,
                    "incorrect value for data[19], expected 255, is {}",
                    msg.data[19]
                );
                assert_eq!(
                    msg.data[20], 229,
                    "incorrect value for data[20], expected 229, is {}",
                    msg.data[20]
                );
                assert_eq!(
                    msg.data[21], 229,
                    "incorrect value for data[21], expected 229, is {}",
                    msg.data[21]
                );
                assert_eq!(
                    msg.data[22], 238,
                    "incorrect value for data[22], expected 238, is {}",
                    msg.data[22]
                );
                assert_eq!(
                    msg.data[23], 170,
                    "incorrect value for data[23], expected 170, is {}",
                    msg.data[23]
                );
                assert_eq!(
                    msg.data[24], 175,
                    "incorrect value for data[24], expected 175, is {}",
                    msg.data[24]
                );
                assert_eq!(
                    msg.data[25], 255,
                    "incorrect value for data[25], expected 255, is {}",
                    msg.data[25]
                );
                assert_eq!(
                    msg.data[26], 240,
                    "incorrect value for data[26], expected 240, is {}",
                    msg.data[26]
                );
                assert_eq!(
                    msg.message_type, 4,
                    "incorrect value for message_type, expected 4, is {}",
                    msg.message_type
                );
                assert_eq!(
                    msg.sid.code, 2,
                    "incorrect value for sid.code, expected 2, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 131,
                    "incorrect value for sid.sat, expected 131, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.tow, 501867721,
                    "incorrect value for tow, expected 501867721, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSbasRaw"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_sbas_msg_sbas_raw`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_sbas_msg_sbas_raw() {
    {
        let mut payload = Cursor::new(vec![
            85, 119, 119, 28, 200, 34, 131, 2, 201, 228, 233, 29, 4, 23, 255, 0, 23, 255, 0, 23,
            255, 127, 240, 2, 255, 192, 3, 127, 247, 255, 127, 247, 255, 229, 229, 238, 170, 175,
            255, 240, 167, 14,
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
        let sbp_msg = sbp::messages::Sbp::MsgSbasRaw(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgSbasRaw(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x7777,
                    "Incorrect message type, expected 0x7777, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xc81c,
                    "incorrect sender id, expected 0xc81c, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.data[0], 23,
                    "incorrect value for data[0], expected 23, is {}",
                    msg.data[0]
                );
                assert_eq!(
                    msg.data[1], 255,
                    "incorrect value for data[1], expected 255, is {}",
                    msg.data[1]
                );
                assert_eq!(
                    msg.data[2], 0,
                    "incorrect value for data[2], expected 0, is {}",
                    msg.data[2]
                );
                assert_eq!(
                    msg.data[3], 23,
                    "incorrect value for data[3], expected 23, is {}",
                    msg.data[3]
                );
                assert_eq!(
                    msg.data[4], 255,
                    "incorrect value for data[4], expected 255, is {}",
                    msg.data[4]
                );
                assert_eq!(
                    msg.data[5], 0,
                    "incorrect value for data[5], expected 0, is {}",
                    msg.data[5]
                );
                assert_eq!(
                    msg.data[6], 23,
                    "incorrect value for data[6], expected 23, is {}",
                    msg.data[6]
                );
                assert_eq!(
                    msg.data[7], 255,
                    "incorrect value for data[7], expected 255, is {}",
                    msg.data[7]
                );
                assert_eq!(
                    msg.data[8], 127,
                    "incorrect value for data[8], expected 127, is {}",
                    msg.data[8]
                );
                assert_eq!(
                    msg.data[9], 240,
                    "incorrect value for data[9], expected 240, is {}",
                    msg.data[9]
                );
                assert_eq!(
                    msg.data[10], 2,
                    "incorrect value for data[10], expected 2, is {}",
                    msg.data[10]
                );
                assert_eq!(
                    msg.data[11], 255,
                    "incorrect value for data[11], expected 255, is {}",
                    msg.data[11]
                );
                assert_eq!(
                    msg.data[12], 192,
                    "incorrect value for data[12], expected 192, is {}",
                    msg.data[12]
                );
                assert_eq!(
                    msg.data[13], 3,
                    "incorrect value for data[13], expected 3, is {}",
                    msg.data[13]
                );
                assert_eq!(
                    msg.data[14], 127,
                    "incorrect value for data[14], expected 127, is {}",
                    msg.data[14]
                );
                assert_eq!(
                    msg.data[15], 247,
                    "incorrect value for data[15], expected 247, is {}",
                    msg.data[15]
                );
                assert_eq!(
                    msg.data[16], 255,
                    "incorrect value for data[16], expected 255, is {}",
                    msg.data[16]
                );
                assert_eq!(
                    msg.data[17], 127,
                    "incorrect value for data[17], expected 127, is {}",
                    msg.data[17]
                );
                assert_eq!(
                    msg.data[18], 247,
                    "incorrect value for data[18], expected 247, is {}",
                    msg.data[18]
                );
                assert_eq!(
                    msg.data[19], 255,
                    "incorrect value for data[19], expected 255, is {}",
                    msg.data[19]
                );
                assert_eq!(
                    msg.data[20], 229,
                    "incorrect value for data[20], expected 229, is {}",
                    msg.data[20]
                );
                assert_eq!(
                    msg.data[21], 229,
                    "incorrect value for data[21], expected 229, is {}",
                    msg.data[21]
                );
                assert_eq!(
                    msg.data[22], 238,
                    "incorrect value for data[22], expected 238, is {}",
                    msg.data[22]
                );
                assert_eq!(
                    msg.data[23], 170,
                    "incorrect value for data[23], expected 170, is {}",
                    msg.data[23]
                );
                assert_eq!(
                    msg.data[24], 175,
                    "incorrect value for data[24], expected 175, is {}",
                    msg.data[24]
                );
                assert_eq!(
                    msg.data[25], 255,
                    "incorrect value for data[25], expected 255, is {}",
                    msg.data[25]
                );
                assert_eq!(
                    msg.data[26], 240,
                    "incorrect value for data[26], expected 240, is {}",
                    msg.data[26]
                );
                assert_eq!(
                    msg.message_type, 4,
                    "incorrect value for message_type, expected 4, is {}",
                    msg.message_type
                );
                assert_eq!(
                    msg.sid.code, 2,
                    "incorrect value for sid.code, expected 2, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.sat, 131,
                    "incorrect value for sid.sat, expected 131, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.tow, 501867721,
                    "incorrect value for tow, expected 501867721, is {}",
                    msg.tow
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSbasRaw"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
