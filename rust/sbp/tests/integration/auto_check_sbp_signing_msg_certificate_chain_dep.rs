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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgCertificateChainDep.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_signing_msg_certificate_chain_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 5, 12, 66, 0, 135, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
            18, 19, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 21,
            22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 232, 7, 3, 30,
            12, 34, 59, 21, 205, 91, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3,
            4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0,
            1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 112, 100,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgCertificateChainDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC05,
                    "Incorrect message type, expected 0xC05, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {sender_id}"
                );
                assert_eq!(
                    msg.corrections_certificate[0], 20,
                    "incorrect value for corrections_certificate[0], expected 20, is {}",
                    msg.corrections_certificate[0]
                );
                assert_eq!(
                    msg.corrections_certificate[1], 21,
                    "incorrect value for corrections_certificate[1], expected 21, is {}",
                    msg.corrections_certificate[1]
                );
                assert_eq!(
                    msg.corrections_certificate[2], 22,
                    "incorrect value for corrections_certificate[2], expected 22, is {}",
                    msg.corrections_certificate[2]
                );
                assert_eq!(
                    msg.corrections_certificate[3], 23,
                    "incorrect value for corrections_certificate[3], expected 23, is {}",
                    msg.corrections_certificate[3]
                );
                assert_eq!(
                    msg.corrections_certificate[4], 24,
                    "incorrect value for corrections_certificate[4], expected 24, is {}",
                    msg.corrections_certificate[4]
                );
                assert_eq!(
                    msg.corrections_certificate[5], 25,
                    "incorrect value for corrections_certificate[5], expected 25, is {}",
                    msg.corrections_certificate[5]
                );
                assert_eq!(
                    msg.corrections_certificate[6], 26,
                    "incorrect value for corrections_certificate[6], expected 26, is {}",
                    msg.corrections_certificate[6]
                );
                assert_eq!(
                    msg.corrections_certificate[7], 27,
                    "incorrect value for corrections_certificate[7], expected 27, is {}",
                    msg.corrections_certificate[7]
                );
                assert_eq!(
                    msg.corrections_certificate[8], 28,
                    "incorrect value for corrections_certificate[8], expected 28, is {}",
                    msg.corrections_certificate[8]
                );
                assert_eq!(
                    msg.corrections_certificate[9], 29,
                    "incorrect value for corrections_certificate[9], expected 29, is {}",
                    msg.corrections_certificate[9]
                );
                assert_eq!(
                    msg.corrections_certificate[10], 10,
                    "incorrect value for corrections_certificate[10], expected 10, is {}",
                    msg.corrections_certificate[10]
                );
                assert_eq!(
                    msg.corrections_certificate[11], 11,
                    "incorrect value for corrections_certificate[11], expected 11, is {}",
                    msg.corrections_certificate[11]
                );
                assert_eq!(
                    msg.corrections_certificate[12], 12,
                    "incorrect value for corrections_certificate[12], expected 12, is {}",
                    msg.corrections_certificate[12]
                );
                assert_eq!(
                    msg.corrections_certificate[13], 13,
                    "incorrect value for corrections_certificate[13], expected 13, is {}",
                    msg.corrections_certificate[13]
                );
                assert_eq!(
                    msg.corrections_certificate[14], 14,
                    "incorrect value for corrections_certificate[14], expected 14, is {}",
                    msg.corrections_certificate[14]
                );
                assert_eq!(
                    msg.corrections_certificate[15], 15,
                    "incorrect value for corrections_certificate[15], expected 15, is {}",
                    msg.corrections_certificate[15]
                );
                assert_eq!(
                    msg.corrections_certificate[16], 16,
                    "incorrect value for corrections_certificate[16], expected 16, is {}",
                    msg.corrections_certificate[16]
                );
                assert_eq!(
                    msg.corrections_certificate[17], 17,
                    "incorrect value for corrections_certificate[17], expected 17, is {}",
                    msg.corrections_certificate[17]
                );
                assert_eq!(
                    msg.corrections_certificate[18], 18,
                    "incorrect value for corrections_certificate[18], expected 18, is {}",
                    msg.corrections_certificate[18]
                );
                assert_eq!(
                    msg.corrections_certificate[19], 19,
                    "incorrect value for corrections_certificate[19], expected 19, is {}",
                    msg.corrections_certificate[19]
                );
                assert_eq!(
                    msg.expiration.day, 30,
                    "incorrect value for expiration.day, expected 30, is {}",
                    msg.expiration.day
                );
                assert_eq!(
                    msg.expiration.hours, 12,
                    "incorrect value for expiration.hours, expected 12, is {}",
                    msg.expiration.hours
                );
                assert_eq!(
                    msg.expiration.minutes, 34,
                    "incorrect value for expiration.minutes, expected 34, is {}",
                    msg.expiration.minutes
                );
                assert_eq!(
                    msg.expiration.month, 3,
                    "incorrect value for expiration.month, expected 3, is {}",
                    msg.expiration.month
                );
                assert_eq!(
                    msg.expiration.ns, 123456789,
                    "incorrect value for expiration.ns, expected 123456789, is {}",
                    msg.expiration.ns
                );
                assert_eq!(
                    msg.expiration.seconds, 59,
                    "incorrect value for expiration.seconds, expected 59, is {}",
                    msg.expiration.seconds
                );
                assert_eq!(
                    msg.expiration.year, 2024,
                    "incorrect value for expiration.year, expected 2024, is {}",
                    msg.expiration.year
                );
                assert_eq!(
                    msg.intermediate_certificate[0], 10,
                    "incorrect value for intermediate_certificate[0], expected 10, is {}",
                    msg.intermediate_certificate[0]
                );
                assert_eq!(
                    msg.intermediate_certificate[1], 11,
                    "incorrect value for intermediate_certificate[1], expected 11, is {}",
                    msg.intermediate_certificate[1]
                );
                assert_eq!(
                    msg.intermediate_certificate[2], 12,
                    "incorrect value for intermediate_certificate[2], expected 12, is {}",
                    msg.intermediate_certificate[2]
                );
                assert_eq!(
                    msg.intermediate_certificate[3], 13,
                    "incorrect value for intermediate_certificate[3], expected 13, is {}",
                    msg.intermediate_certificate[3]
                );
                assert_eq!(
                    msg.intermediate_certificate[4], 14,
                    "incorrect value for intermediate_certificate[4], expected 14, is {}",
                    msg.intermediate_certificate[4]
                );
                assert_eq!(
                    msg.intermediate_certificate[5], 15,
                    "incorrect value for intermediate_certificate[5], expected 15, is {}",
                    msg.intermediate_certificate[5]
                );
                assert_eq!(
                    msg.intermediate_certificate[6], 16,
                    "incorrect value for intermediate_certificate[6], expected 16, is {}",
                    msg.intermediate_certificate[6]
                );
                assert_eq!(
                    msg.intermediate_certificate[7], 17,
                    "incorrect value for intermediate_certificate[7], expected 17, is {}",
                    msg.intermediate_certificate[7]
                );
                assert_eq!(
                    msg.intermediate_certificate[8], 18,
                    "incorrect value for intermediate_certificate[8], expected 18, is {}",
                    msg.intermediate_certificate[8]
                );
                assert_eq!(
                    msg.intermediate_certificate[9], 19,
                    "incorrect value for intermediate_certificate[9], expected 19, is {}",
                    msg.intermediate_certificate[9]
                );
                assert_eq!(
                    msg.intermediate_certificate[10], 0,
                    "incorrect value for intermediate_certificate[10], expected 0, is {}",
                    msg.intermediate_certificate[10]
                );
                assert_eq!(
                    msg.intermediate_certificate[11], 1,
                    "incorrect value for intermediate_certificate[11], expected 1, is {}",
                    msg.intermediate_certificate[11]
                );
                assert_eq!(
                    msg.intermediate_certificate[12], 2,
                    "incorrect value for intermediate_certificate[12], expected 2, is {}",
                    msg.intermediate_certificate[12]
                );
                assert_eq!(
                    msg.intermediate_certificate[13], 3,
                    "incorrect value for intermediate_certificate[13], expected 3, is {}",
                    msg.intermediate_certificate[13]
                );
                assert_eq!(
                    msg.intermediate_certificate[14], 4,
                    "incorrect value for intermediate_certificate[14], expected 4, is {}",
                    msg.intermediate_certificate[14]
                );
                assert_eq!(
                    msg.intermediate_certificate[15], 5,
                    "incorrect value for intermediate_certificate[15], expected 5, is {}",
                    msg.intermediate_certificate[15]
                );
                assert_eq!(
                    msg.intermediate_certificate[16], 6,
                    "incorrect value for intermediate_certificate[16], expected 6, is {}",
                    msg.intermediate_certificate[16]
                );
                assert_eq!(
                    msg.intermediate_certificate[17], 7,
                    "incorrect value for intermediate_certificate[17], expected 7, is {}",
                    msg.intermediate_certificate[17]
                );
                assert_eq!(
                    msg.intermediate_certificate[18], 8,
                    "incorrect value for intermediate_certificate[18], expected 8, is {}",
                    msg.intermediate_certificate[18]
                );
                assert_eq!(
                    msg.intermediate_certificate[19], 9,
                    "incorrect value for intermediate_certificate[19], expected 9, is {}",
                    msg.intermediate_certificate[19]
                );
                assert_eq!(
                    msg.root_certificate[0], 0,
                    "incorrect value for root_certificate[0], expected 0, is {}",
                    msg.root_certificate[0]
                );
                assert_eq!(
                    msg.root_certificate[1], 1,
                    "incorrect value for root_certificate[1], expected 1, is {}",
                    msg.root_certificate[1]
                );
                assert_eq!(
                    msg.root_certificate[2], 2,
                    "incorrect value for root_certificate[2], expected 2, is {}",
                    msg.root_certificate[2]
                );
                assert_eq!(
                    msg.root_certificate[3], 3,
                    "incorrect value for root_certificate[3], expected 3, is {}",
                    msg.root_certificate[3]
                );
                assert_eq!(
                    msg.root_certificate[4], 4,
                    "incorrect value for root_certificate[4], expected 4, is {}",
                    msg.root_certificate[4]
                );
                assert_eq!(
                    msg.root_certificate[5], 5,
                    "incorrect value for root_certificate[5], expected 5, is {}",
                    msg.root_certificate[5]
                );
                assert_eq!(
                    msg.root_certificate[6], 6,
                    "incorrect value for root_certificate[6], expected 6, is {}",
                    msg.root_certificate[6]
                );
                assert_eq!(
                    msg.root_certificate[7], 7,
                    "incorrect value for root_certificate[7], expected 7, is {}",
                    msg.root_certificate[7]
                );
                assert_eq!(
                    msg.root_certificate[8], 8,
                    "incorrect value for root_certificate[8], expected 8, is {}",
                    msg.root_certificate[8]
                );
                assert_eq!(
                    msg.root_certificate[9], 9,
                    "incorrect value for root_certificate[9], expected 9, is {}",
                    msg.root_certificate[9]
                );
                assert_eq!(
                    msg.root_certificate[10], 10,
                    "incorrect value for root_certificate[10], expected 10, is {}",
                    msg.root_certificate[10]
                );
                assert_eq!(
                    msg.root_certificate[11], 11,
                    "incorrect value for root_certificate[11], expected 11, is {}",
                    msg.root_certificate[11]
                );
                assert_eq!(
                    msg.root_certificate[12], 12,
                    "incorrect value for root_certificate[12], expected 12, is {}",
                    msg.root_certificate[12]
                );
                assert_eq!(
                    msg.root_certificate[13], 13,
                    "incorrect value for root_certificate[13], expected 13, is {}",
                    msg.root_certificate[13]
                );
                assert_eq!(
                    msg.root_certificate[14], 14,
                    "incorrect value for root_certificate[14], expected 14, is {}",
                    msg.root_certificate[14]
                );
                assert_eq!(
                    msg.root_certificate[15], 15,
                    "incorrect value for root_certificate[15], expected 15, is {}",
                    msg.root_certificate[15]
                );
                assert_eq!(
                    msg.root_certificate[16], 16,
                    "incorrect value for root_certificate[16], expected 16, is {}",
                    msg.root_certificate[16]
                );
                assert_eq!(
                    msg.root_certificate[17], 17,
                    "incorrect value for root_certificate[17], expected 17, is {}",
                    msg.root_certificate[17]
                );
                assert_eq!(
                    msg.root_certificate[18], 18,
                    "incorrect value for root_certificate[18], expected 18, is {}",
                    msg.root_certificate[18]
                );
                assert_eq!(
                    msg.root_certificate[19], 19,
                    "incorrect value for root_certificate[19], expected 19, is {}",
                    msg.root_certificate[19]
                );
                assert_eq!(
                    msg.signature[0], 0,
                    "incorrect value for signature[0], expected 0, is {}",
                    msg.signature[0]
                );
                assert_eq!(
                    msg.signature[1], 1,
                    "incorrect value for signature[1], expected 1, is {}",
                    msg.signature[1]
                );
                assert_eq!(
                    msg.signature[2], 2,
                    "incorrect value for signature[2], expected 2, is {}",
                    msg.signature[2]
                );
                assert_eq!(
                    msg.signature[3], 3,
                    "incorrect value for signature[3], expected 3, is {}",
                    msg.signature[3]
                );
                assert_eq!(
                    msg.signature[4], 4,
                    "incorrect value for signature[4], expected 4, is {}",
                    msg.signature[4]
                );
                assert_eq!(
                    msg.signature[5], 5,
                    "incorrect value for signature[5], expected 5, is {}",
                    msg.signature[5]
                );
                assert_eq!(
                    msg.signature[6], 6,
                    "incorrect value for signature[6], expected 6, is {}",
                    msg.signature[6]
                );
                assert_eq!(
                    msg.signature[7], 7,
                    "incorrect value for signature[7], expected 7, is {}",
                    msg.signature[7]
                );
                assert_eq!(
                    msg.signature[8], 0,
                    "incorrect value for signature[8], expected 0, is {}",
                    msg.signature[8]
                );
                assert_eq!(
                    msg.signature[9], 1,
                    "incorrect value for signature[9], expected 1, is {}",
                    msg.signature[9]
                );
                assert_eq!(
                    msg.signature[10], 2,
                    "incorrect value for signature[10], expected 2, is {}",
                    msg.signature[10]
                );
                assert_eq!(
                    msg.signature[11], 3,
                    "incorrect value for signature[11], expected 3, is {}",
                    msg.signature[11]
                );
                assert_eq!(
                    msg.signature[12], 4,
                    "incorrect value for signature[12], expected 4, is {}",
                    msg.signature[12]
                );
                assert_eq!(
                    msg.signature[13], 5,
                    "incorrect value for signature[13], expected 5, is {}",
                    msg.signature[13]
                );
                assert_eq!(
                    msg.signature[14], 6,
                    "incorrect value for signature[14], expected 6, is {}",
                    msg.signature[14]
                );
                assert_eq!(
                    msg.signature[15], 7,
                    "incorrect value for signature[15], expected 7, is {}",
                    msg.signature[15]
                );
                assert_eq!(
                    msg.signature[16], 0,
                    "incorrect value for signature[16], expected 0, is {}",
                    msg.signature[16]
                );
                assert_eq!(
                    msg.signature[17], 1,
                    "incorrect value for signature[17], expected 1, is {}",
                    msg.signature[17]
                );
                assert_eq!(
                    msg.signature[18], 2,
                    "incorrect value for signature[18], expected 2, is {}",
                    msg.signature[18]
                );
                assert_eq!(
                    msg.signature[19], 3,
                    "incorrect value for signature[19], expected 3, is {}",
                    msg.signature[19]
                );
                assert_eq!(
                    msg.signature[20], 4,
                    "incorrect value for signature[20], expected 4, is {}",
                    msg.signature[20]
                );
                assert_eq!(
                    msg.signature[21], 5,
                    "incorrect value for signature[21], expected 5, is {}",
                    msg.signature[21]
                );
                assert_eq!(
                    msg.signature[22], 6,
                    "incorrect value for signature[22], expected 6, is {}",
                    msg.signature[22]
                );
                assert_eq!(
                    msg.signature[23], 7,
                    "incorrect value for signature[23], expected 7, is {}",
                    msg.signature[23]
                );
                assert_eq!(
                    msg.signature[24], 0,
                    "incorrect value for signature[24], expected 0, is {}",
                    msg.signature[24]
                );
                assert_eq!(
                    msg.signature[25], 1,
                    "incorrect value for signature[25], expected 1, is {}",
                    msg.signature[25]
                );
                assert_eq!(
                    msg.signature[26], 2,
                    "incorrect value for signature[26], expected 2, is {}",
                    msg.signature[26]
                );
                assert_eq!(
                    msg.signature[27], 3,
                    "incorrect value for signature[27], expected 3, is {}",
                    msg.signature[27]
                );
                assert_eq!(
                    msg.signature[28], 4,
                    "incorrect value for signature[28], expected 4, is {}",
                    msg.signature[28]
                );
                assert_eq!(
                    msg.signature[29], 5,
                    "incorrect value for signature[29], expected 5, is {}",
                    msg.signature[29]
                );
                assert_eq!(
                    msg.signature[30], 6,
                    "incorrect value for signature[30], expected 6, is {}",
                    msg.signature[30]
                );
                assert_eq!(
                    msg.signature[31], 7,
                    "incorrect value for signature[31], expected 7, is {}",
                    msg.signature[31]
                );
                assert_eq!(
                    msg.signature[32], 0,
                    "incorrect value for signature[32], expected 0, is {}",
                    msg.signature[32]
                );
                assert_eq!(
                    msg.signature[33], 1,
                    "incorrect value for signature[33], expected 1, is {}",
                    msg.signature[33]
                );
                assert_eq!(
                    msg.signature[34], 2,
                    "incorrect value for signature[34], expected 2, is {}",
                    msg.signature[34]
                );
                assert_eq!(
                    msg.signature[35], 3,
                    "incorrect value for signature[35], expected 3, is {}",
                    msg.signature[35]
                );
                assert_eq!(
                    msg.signature[36], 4,
                    "incorrect value for signature[36], expected 4, is {}",
                    msg.signature[36]
                );
                assert_eq!(
                    msg.signature[37], 5,
                    "incorrect value for signature[37], expected 5, is {}",
                    msg.signature[37]
                );
                assert_eq!(
                    msg.signature[38], 6,
                    "incorrect value for signature[38], expected 6, is {}",
                    msg.signature[38]
                );
                assert_eq!(
                    msg.signature[39], 7,
                    "incorrect value for signature[39], expected 7, is {}",
                    msg.signature[39]
                );
                assert_eq!(
                    msg.signature[40], 0,
                    "incorrect value for signature[40], expected 0, is {}",
                    msg.signature[40]
                );
                assert_eq!(
                    msg.signature[41], 1,
                    "incorrect value for signature[41], expected 1, is {}",
                    msg.signature[41]
                );
                assert_eq!(
                    msg.signature[42], 2,
                    "incorrect value for signature[42], expected 2, is {}",
                    msg.signature[42]
                );
                assert_eq!(
                    msg.signature[43], 3,
                    "incorrect value for signature[43], expected 3, is {}",
                    msg.signature[43]
                );
                assert_eq!(
                    msg.signature[44], 4,
                    "incorrect value for signature[44], expected 4, is {}",
                    msg.signature[44]
                );
                assert_eq!(
                    msg.signature[45], 5,
                    "incorrect value for signature[45], expected 5, is {}",
                    msg.signature[45]
                );
                assert_eq!(
                    msg.signature[46], 6,
                    "incorrect value for signature[46], expected 6, is {}",
                    msg.signature[46]
                );
                assert_eq!(
                    msg.signature[47], 7,
                    "incorrect value for signature[47], expected 7, is {}",
                    msg.signature[47]
                );
                assert_eq!(
                    msg.signature[48], 0,
                    "incorrect value for signature[48], expected 0, is {}",
                    msg.signature[48]
                );
                assert_eq!(
                    msg.signature[49], 1,
                    "incorrect value for signature[49], expected 1, is {}",
                    msg.signature[49]
                );
                assert_eq!(
                    msg.signature[50], 2,
                    "incorrect value for signature[50], expected 2, is {}",
                    msg.signature[50]
                );
                assert_eq!(
                    msg.signature[51], 3,
                    "incorrect value for signature[51], expected 3, is {}",
                    msg.signature[51]
                );
                assert_eq!(
                    msg.signature[52], 4,
                    "incorrect value for signature[52], expected 4, is {}",
                    msg.signature[52]
                );
                assert_eq!(
                    msg.signature[53], 5,
                    "incorrect value for signature[53], expected 5, is {}",
                    msg.signature[53]
                );
                assert_eq!(
                    msg.signature[54], 6,
                    "incorrect value for signature[54], expected 6, is {}",
                    msg.signature[54]
                );
                assert_eq!(
                    msg.signature[55], 7,
                    "incorrect value for signature[55], expected 7, is {}",
                    msg.signature[55]
                );
                assert_eq!(
                    msg.signature[56], 0,
                    "incorrect value for signature[56], expected 0, is {}",
                    msg.signature[56]
                );
                assert_eq!(
                    msg.signature[57], 1,
                    "incorrect value for signature[57], expected 1, is {}",
                    msg.signature[57]
                );
                assert_eq!(
                    msg.signature[58], 2,
                    "incorrect value for signature[58], expected 2, is {}",
                    msg.signature[58]
                );
                assert_eq!(
                    msg.signature[59], 3,
                    "incorrect value for signature[59], expected 3, is {}",
                    msg.signature[59]
                );
                assert_eq!(
                    msg.signature[60], 4,
                    "incorrect value for signature[60], expected 4, is {}",
                    msg.signature[60]
                );
                assert_eq!(
                    msg.signature[61], 5,
                    "incorrect value for signature[61], expected 5, is {}",
                    msg.signature[61]
                );
                assert_eq!(
                    msg.signature[62], 6,
                    "incorrect value for signature[62], expected 6, is {}",
                    msg.signature[62]
                );
                assert_eq!(
                    msg.signature[63], 7,
                    "incorrect value for signature[63], expected 7, is {}",
                    msg.signature[63]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCertificateChainDep"),
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
fn test_json2sbp_auto_check_sbp_signing_msg_certificate_chain_dep() {
    {
        let json_input = r#"{"preamble": 85, "msg_type": 3077, "sender": 66, "length": 135, "payload": "AAECAwQFBgcICQoLDA0ODxAREhMKCwwNDg8QERITAAECAwQFBgcICRQVFhcYGRobHB0KCwwNDg8QERIT6AcDHgwiOxXNWwcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYHAAECAwQFBgcAAQIDBAUGBwABAgMEBQYH", "crc": 25712, "root_certificate": [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19], "intermediate_certificate": [10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9], "corrections_certificate": [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19], "expiration": {"year": 2024, "month": 3, "day": 30, "hours": 12, "minutes": 34, "seconds": 59, "ns": 123456789}, "signature": [0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7]}"#.as_bytes();

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
            sbp::messages::Sbp::MsgCertificateChainDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC05,
                    "Incorrect message type, expected 0xC05, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {sender_id}"
                );
                assert_eq!(
                    msg.corrections_certificate[0], 20,
                    "incorrect value for corrections_certificate[0], expected 20, is {}",
                    msg.corrections_certificate[0]
                );
                assert_eq!(
                    msg.corrections_certificate[1], 21,
                    "incorrect value for corrections_certificate[1], expected 21, is {}",
                    msg.corrections_certificate[1]
                );
                assert_eq!(
                    msg.corrections_certificate[2], 22,
                    "incorrect value for corrections_certificate[2], expected 22, is {}",
                    msg.corrections_certificate[2]
                );
                assert_eq!(
                    msg.corrections_certificate[3], 23,
                    "incorrect value for corrections_certificate[3], expected 23, is {}",
                    msg.corrections_certificate[3]
                );
                assert_eq!(
                    msg.corrections_certificate[4], 24,
                    "incorrect value for corrections_certificate[4], expected 24, is {}",
                    msg.corrections_certificate[4]
                );
                assert_eq!(
                    msg.corrections_certificate[5], 25,
                    "incorrect value for corrections_certificate[5], expected 25, is {}",
                    msg.corrections_certificate[5]
                );
                assert_eq!(
                    msg.corrections_certificate[6], 26,
                    "incorrect value for corrections_certificate[6], expected 26, is {}",
                    msg.corrections_certificate[6]
                );
                assert_eq!(
                    msg.corrections_certificate[7], 27,
                    "incorrect value for corrections_certificate[7], expected 27, is {}",
                    msg.corrections_certificate[7]
                );
                assert_eq!(
                    msg.corrections_certificate[8], 28,
                    "incorrect value for corrections_certificate[8], expected 28, is {}",
                    msg.corrections_certificate[8]
                );
                assert_eq!(
                    msg.corrections_certificate[9], 29,
                    "incorrect value for corrections_certificate[9], expected 29, is {}",
                    msg.corrections_certificate[9]
                );
                assert_eq!(
                    msg.corrections_certificate[10], 10,
                    "incorrect value for corrections_certificate[10], expected 10, is {}",
                    msg.corrections_certificate[10]
                );
                assert_eq!(
                    msg.corrections_certificate[11], 11,
                    "incorrect value for corrections_certificate[11], expected 11, is {}",
                    msg.corrections_certificate[11]
                );
                assert_eq!(
                    msg.corrections_certificate[12], 12,
                    "incorrect value for corrections_certificate[12], expected 12, is {}",
                    msg.corrections_certificate[12]
                );
                assert_eq!(
                    msg.corrections_certificate[13], 13,
                    "incorrect value for corrections_certificate[13], expected 13, is {}",
                    msg.corrections_certificate[13]
                );
                assert_eq!(
                    msg.corrections_certificate[14], 14,
                    "incorrect value for corrections_certificate[14], expected 14, is {}",
                    msg.corrections_certificate[14]
                );
                assert_eq!(
                    msg.corrections_certificate[15], 15,
                    "incorrect value for corrections_certificate[15], expected 15, is {}",
                    msg.corrections_certificate[15]
                );
                assert_eq!(
                    msg.corrections_certificate[16], 16,
                    "incorrect value for corrections_certificate[16], expected 16, is {}",
                    msg.corrections_certificate[16]
                );
                assert_eq!(
                    msg.corrections_certificate[17], 17,
                    "incorrect value for corrections_certificate[17], expected 17, is {}",
                    msg.corrections_certificate[17]
                );
                assert_eq!(
                    msg.corrections_certificate[18], 18,
                    "incorrect value for corrections_certificate[18], expected 18, is {}",
                    msg.corrections_certificate[18]
                );
                assert_eq!(
                    msg.corrections_certificate[19], 19,
                    "incorrect value for corrections_certificate[19], expected 19, is {}",
                    msg.corrections_certificate[19]
                );
                assert_eq!(
                    msg.expiration.day, 30,
                    "incorrect value for expiration.day, expected 30, is {}",
                    msg.expiration.day
                );
                assert_eq!(
                    msg.expiration.hours, 12,
                    "incorrect value for expiration.hours, expected 12, is {}",
                    msg.expiration.hours
                );
                assert_eq!(
                    msg.expiration.minutes, 34,
                    "incorrect value for expiration.minutes, expected 34, is {}",
                    msg.expiration.minutes
                );
                assert_eq!(
                    msg.expiration.month, 3,
                    "incorrect value for expiration.month, expected 3, is {}",
                    msg.expiration.month
                );
                assert_eq!(
                    msg.expiration.ns, 123456789,
                    "incorrect value for expiration.ns, expected 123456789, is {}",
                    msg.expiration.ns
                );
                assert_eq!(
                    msg.expiration.seconds, 59,
                    "incorrect value for expiration.seconds, expected 59, is {}",
                    msg.expiration.seconds
                );
                assert_eq!(
                    msg.expiration.year, 2024,
                    "incorrect value for expiration.year, expected 2024, is {}",
                    msg.expiration.year
                );
                assert_eq!(
                    msg.intermediate_certificate[0], 10,
                    "incorrect value for intermediate_certificate[0], expected 10, is {}",
                    msg.intermediate_certificate[0]
                );
                assert_eq!(
                    msg.intermediate_certificate[1], 11,
                    "incorrect value for intermediate_certificate[1], expected 11, is {}",
                    msg.intermediate_certificate[1]
                );
                assert_eq!(
                    msg.intermediate_certificate[2], 12,
                    "incorrect value for intermediate_certificate[2], expected 12, is {}",
                    msg.intermediate_certificate[2]
                );
                assert_eq!(
                    msg.intermediate_certificate[3], 13,
                    "incorrect value for intermediate_certificate[3], expected 13, is {}",
                    msg.intermediate_certificate[3]
                );
                assert_eq!(
                    msg.intermediate_certificate[4], 14,
                    "incorrect value for intermediate_certificate[4], expected 14, is {}",
                    msg.intermediate_certificate[4]
                );
                assert_eq!(
                    msg.intermediate_certificate[5], 15,
                    "incorrect value for intermediate_certificate[5], expected 15, is {}",
                    msg.intermediate_certificate[5]
                );
                assert_eq!(
                    msg.intermediate_certificate[6], 16,
                    "incorrect value for intermediate_certificate[6], expected 16, is {}",
                    msg.intermediate_certificate[6]
                );
                assert_eq!(
                    msg.intermediate_certificate[7], 17,
                    "incorrect value for intermediate_certificate[7], expected 17, is {}",
                    msg.intermediate_certificate[7]
                );
                assert_eq!(
                    msg.intermediate_certificate[8], 18,
                    "incorrect value for intermediate_certificate[8], expected 18, is {}",
                    msg.intermediate_certificate[8]
                );
                assert_eq!(
                    msg.intermediate_certificate[9], 19,
                    "incorrect value for intermediate_certificate[9], expected 19, is {}",
                    msg.intermediate_certificate[9]
                );
                assert_eq!(
                    msg.intermediate_certificate[10], 0,
                    "incorrect value for intermediate_certificate[10], expected 0, is {}",
                    msg.intermediate_certificate[10]
                );
                assert_eq!(
                    msg.intermediate_certificate[11], 1,
                    "incorrect value for intermediate_certificate[11], expected 1, is {}",
                    msg.intermediate_certificate[11]
                );
                assert_eq!(
                    msg.intermediate_certificate[12], 2,
                    "incorrect value for intermediate_certificate[12], expected 2, is {}",
                    msg.intermediate_certificate[12]
                );
                assert_eq!(
                    msg.intermediate_certificate[13], 3,
                    "incorrect value for intermediate_certificate[13], expected 3, is {}",
                    msg.intermediate_certificate[13]
                );
                assert_eq!(
                    msg.intermediate_certificate[14], 4,
                    "incorrect value for intermediate_certificate[14], expected 4, is {}",
                    msg.intermediate_certificate[14]
                );
                assert_eq!(
                    msg.intermediate_certificate[15], 5,
                    "incorrect value for intermediate_certificate[15], expected 5, is {}",
                    msg.intermediate_certificate[15]
                );
                assert_eq!(
                    msg.intermediate_certificate[16], 6,
                    "incorrect value for intermediate_certificate[16], expected 6, is {}",
                    msg.intermediate_certificate[16]
                );
                assert_eq!(
                    msg.intermediate_certificate[17], 7,
                    "incorrect value for intermediate_certificate[17], expected 7, is {}",
                    msg.intermediate_certificate[17]
                );
                assert_eq!(
                    msg.intermediate_certificate[18], 8,
                    "incorrect value for intermediate_certificate[18], expected 8, is {}",
                    msg.intermediate_certificate[18]
                );
                assert_eq!(
                    msg.intermediate_certificate[19], 9,
                    "incorrect value for intermediate_certificate[19], expected 9, is {}",
                    msg.intermediate_certificate[19]
                );
                assert_eq!(
                    msg.root_certificate[0], 0,
                    "incorrect value for root_certificate[0], expected 0, is {}",
                    msg.root_certificate[0]
                );
                assert_eq!(
                    msg.root_certificate[1], 1,
                    "incorrect value for root_certificate[1], expected 1, is {}",
                    msg.root_certificate[1]
                );
                assert_eq!(
                    msg.root_certificate[2], 2,
                    "incorrect value for root_certificate[2], expected 2, is {}",
                    msg.root_certificate[2]
                );
                assert_eq!(
                    msg.root_certificate[3], 3,
                    "incorrect value for root_certificate[3], expected 3, is {}",
                    msg.root_certificate[3]
                );
                assert_eq!(
                    msg.root_certificate[4], 4,
                    "incorrect value for root_certificate[4], expected 4, is {}",
                    msg.root_certificate[4]
                );
                assert_eq!(
                    msg.root_certificate[5], 5,
                    "incorrect value for root_certificate[5], expected 5, is {}",
                    msg.root_certificate[5]
                );
                assert_eq!(
                    msg.root_certificate[6], 6,
                    "incorrect value for root_certificate[6], expected 6, is {}",
                    msg.root_certificate[6]
                );
                assert_eq!(
                    msg.root_certificate[7], 7,
                    "incorrect value for root_certificate[7], expected 7, is {}",
                    msg.root_certificate[7]
                );
                assert_eq!(
                    msg.root_certificate[8], 8,
                    "incorrect value for root_certificate[8], expected 8, is {}",
                    msg.root_certificate[8]
                );
                assert_eq!(
                    msg.root_certificate[9], 9,
                    "incorrect value for root_certificate[9], expected 9, is {}",
                    msg.root_certificate[9]
                );
                assert_eq!(
                    msg.root_certificate[10], 10,
                    "incorrect value for root_certificate[10], expected 10, is {}",
                    msg.root_certificate[10]
                );
                assert_eq!(
                    msg.root_certificate[11], 11,
                    "incorrect value for root_certificate[11], expected 11, is {}",
                    msg.root_certificate[11]
                );
                assert_eq!(
                    msg.root_certificate[12], 12,
                    "incorrect value for root_certificate[12], expected 12, is {}",
                    msg.root_certificate[12]
                );
                assert_eq!(
                    msg.root_certificate[13], 13,
                    "incorrect value for root_certificate[13], expected 13, is {}",
                    msg.root_certificate[13]
                );
                assert_eq!(
                    msg.root_certificate[14], 14,
                    "incorrect value for root_certificate[14], expected 14, is {}",
                    msg.root_certificate[14]
                );
                assert_eq!(
                    msg.root_certificate[15], 15,
                    "incorrect value for root_certificate[15], expected 15, is {}",
                    msg.root_certificate[15]
                );
                assert_eq!(
                    msg.root_certificate[16], 16,
                    "incorrect value for root_certificate[16], expected 16, is {}",
                    msg.root_certificate[16]
                );
                assert_eq!(
                    msg.root_certificate[17], 17,
                    "incorrect value for root_certificate[17], expected 17, is {}",
                    msg.root_certificate[17]
                );
                assert_eq!(
                    msg.root_certificate[18], 18,
                    "incorrect value for root_certificate[18], expected 18, is {}",
                    msg.root_certificate[18]
                );
                assert_eq!(
                    msg.root_certificate[19], 19,
                    "incorrect value for root_certificate[19], expected 19, is {}",
                    msg.root_certificate[19]
                );
                assert_eq!(
                    msg.signature[0], 0,
                    "incorrect value for signature[0], expected 0, is {}",
                    msg.signature[0]
                );
                assert_eq!(
                    msg.signature[1], 1,
                    "incorrect value for signature[1], expected 1, is {}",
                    msg.signature[1]
                );
                assert_eq!(
                    msg.signature[2], 2,
                    "incorrect value for signature[2], expected 2, is {}",
                    msg.signature[2]
                );
                assert_eq!(
                    msg.signature[3], 3,
                    "incorrect value for signature[3], expected 3, is {}",
                    msg.signature[3]
                );
                assert_eq!(
                    msg.signature[4], 4,
                    "incorrect value for signature[4], expected 4, is {}",
                    msg.signature[4]
                );
                assert_eq!(
                    msg.signature[5], 5,
                    "incorrect value for signature[5], expected 5, is {}",
                    msg.signature[5]
                );
                assert_eq!(
                    msg.signature[6], 6,
                    "incorrect value for signature[6], expected 6, is {}",
                    msg.signature[6]
                );
                assert_eq!(
                    msg.signature[7], 7,
                    "incorrect value for signature[7], expected 7, is {}",
                    msg.signature[7]
                );
                assert_eq!(
                    msg.signature[8], 0,
                    "incorrect value for signature[8], expected 0, is {}",
                    msg.signature[8]
                );
                assert_eq!(
                    msg.signature[9], 1,
                    "incorrect value for signature[9], expected 1, is {}",
                    msg.signature[9]
                );
                assert_eq!(
                    msg.signature[10], 2,
                    "incorrect value for signature[10], expected 2, is {}",
                    msg.signature[10]
                );
                assert_eq!(
                    msg.signature[11], 3,
                    "incorrect value for signature[11], expected 3, is {}",
                    msg.signature[11]
                );
                assert_eq!(
                    msg.signature[12], 4,
                    "incorrect value for signature[12], expected 4, is {}",
                    msg.signature[12]
                );
                assert_eq!(
                    msg.signature[13], 5,
                    "incorrect value for signature[13], expected 5, is {}",
                    msg.signature[13]
                );
                assert_eq!(
                    msg.signature[14], 6,
                    "incorrect value for signature[14], expected 6, is {}",
                    msg.signature[14]
                );
                assert_eq!(
                    msg.signature[15], 7,
                    "incorrect value for signature[15], expected 7, is {}",
                    msg.signature[15]
                );
                assert_eq!(
                    msg.signature[16], 0,
                    "incorrect value for signature[16], expected 0, is {}",
                    msg.signature[16]
                );
                assert_eq!(
                    msg.signature[17], 1,
                    "incorrect value for signature[17], expected 1, is {}",
                    msg.signature[17]
                );
                assert_eq!(
                    msg.signature[18], 2,
                    "incorrect value for signature[18], expected 2, is {}",
                    msg.signature[18]
                );
                assert_eq!(
                    msg.signature[19], 3,
                    "incorrect value for signature[19], expected 3, is {}",
                    msg.signature[19]
                );
                assert_eq!(
                    msg.signature[20], 4,
                    "incorrect value for signature[20], expected 4, is {}",
                    msg.signature[20]
                );
                assert_eq!(
                    msg.signature[21], 5,
                    "incorrect value for signature[21], expected 5, is {}",
                    msg.signature[21]
                );
                assert_eq!(
                    msg.signature[22], 6,
                    "incorrect value for signature[22], expected 6, is {}",
                    msg.signature[22]
                );
                assert_eq!(
                    msg.signature[23], 7,
                    "incorrect value for signature[23], expected 7, is {}",
                    msg.signature[23]
                );
                assert_eq!(
                    msg.signature[24], 0,
                    "incorrect value for signature[24], expected 0, is {}",
                    msg.signature[24]
                );
                assert_eq!(
                    msg.signature[25], 1,
                    "incorrect value for signature[25], expected 1, is {}",
                    msg.signature[25]
                );
                assert_eq!(
                    msg.signature[26], 2,
                    "incorrect value for signature[26], expected 2, is {}",
                    msg.signature[26]
                );
                assert_eq!(
                    msg.signature[27], 3,
                    "incorrect value for signature[27], expected 3, is {}",
                    msg.signature[27]
                );
                assert_eq!(
                    msg.signature[28], 4,
                    "incorrect value for signature[28], expected 4, is {}",
                    msg.signature[28]
                );
                assert_eq!(
                    msg.signature[29], 5,
                    "incorrect value for signature[29], expected 5, is {}",
                    msg.signature[29]
                );
                assert_eq!(
                    msg.signature[30], 6,
                    "incorrect value for signature[30], expected 6, is {}",
                    msg.signature[30]
                );
                assert_eq!(
                    msg.signature[31], 7,
                    "incorrect value for signature[31], expected 7, is {}",
                    msg.signature[31]
                );
                assert_eq!(
                    msg.signature[32], 0,
                    "incorrect value for signature[32], expected 0, is {}",
                    msg.signature[32]
                );
                assert_eq!(
                    msg.signature[33], 1,
                    "incorrect value for signature[33], expected 1, is {}",
                    msg.signature[33]
                );
                assert_eq!(
                    msg.signature[34], 2,
                    "incorrect value for signature[34], expected 2, is {}",
                    msg.signature[34]
                );
                assert_eq!(
                    msg.signature[35], 3,
                    "incorrect value for signature[35], expected 3, is {}",
                    msg.signature[35]
                );
                assert_eq!(
                    msg.signature[36], 4,
                    "incorrect value for signature[36], expected 4, is {}",
                    msg.signature[36]
                );
                assert_eq!(
                    msg.signature[37], 5,
                    "incorrect value for signature[37], expected 5, is {}",
                    msg.signature[37]
                );
                assert_eq!(
                    msg.signature[38], 6,
                    "incorrect value for signature[38], expected 6, is {}",
                    msg.signature[38]
                );
                assert_eq!(
                    msg.signature[39], 7,
                    "incorrect value for signature[39], expected 7, is {}",
                    msg.signature[39]
                );
                assert_eq!(
                    msg.signature[40], 0,
                    "incorrect value for signature[40], expected 0, is {}",
                    msg.signature[40]
                );
                assert_eq!(
                    msg.signature[41], 1,
                    "incorrect value for signature[41], expected 1, is {}",
                    msg.signature[41]
                );
                assert_eq!(
                    msg.signature[42], 2,
                    "incorrect value for signature[42], expected 2, is {}",
                    msg.signature[42]
                );
                assert_eq!(
                    msg.signature[43], 3,
                    "incorrect value for signature[43], expected 3, is {}",
                    msg.signature[43]
                );
                assert_eq!(
                    msg.signature[44], 4,
                    "incorrect value for signature[44], expected 4, is {}",
                    msg.signature[44]
                );
                assert_eq!(
                    msg.signature[45], 5,
                    "incorrect value for signature[45], expected 5, is {}",
                    msg.signature[45]
                );
                assert_eq!(
                    msg.signature[46], 6,
                    "incorrect value for signature[46], expected 6, is {}",
                    msg.signature[46]
                );
                assert_eq!(
                    msg.signature[47], 7,
                    "incorrect value for signature[47], expected 7, is {}",
                    msg.signature[47]
                );
                assert_eq!(
                    msg.signature[48], 0,
                    "incorrect value for signature[48], expected 0, is {}",
                    msg.signature[48]
                );
                assert_eq!(
                    msg.signature[49], 1,
                    "incorrect value for signature[49], expected 1, is {}",
                    msg.signature[49]
                );
                assert_eq!(
                    msg.signature[50], 2,
                    "incorrect value for signature[50], expected 2, is {}",
                    msg.signature[50]
                );
                assert_eq!(
                    msg.signature[51], 3,
                    "incorrect value for signature[51], expected 3, is {}",
                    msg.signature[51]
                );
                assert_eq!(
                    msg.signature[52], 4,
                    "incorrect value for signature[52], expected 4, is {}",
                    msg.signature[52]
                );
                assert_eq!(
                    msg.signature[53], 5,
                    "incorrect value for signature[53], expected 5, is {}",
                    msg.signature[53]
                );
                assert_eq!(
                    msg.signature[54], 6,
                    "incorrect value for signature[54], expected 6, is {}",
                    msg.signature[54]
                );
                assert_eq!(
                    msg.signature[55], 7,
                    "incorrect value for signature[55], expected 7, is {}",
                    msg.signature[55]
                );
                assert_eq!(
                    msg.signature[56], 0,
                    "incorrect value for signature[56], expected 0, is {}",
                    msg.signature[56]
                );
                assert_eq!(
                    msg.signature[57], 1,
                    "incorrect value for signature[57], expected 1, is {}",
                    msg.signature[57]
                );
                assert_eq!(
                    msg.signature[58], 2,
                    "incorrect value for signature[58], expected 2, is {}",
                    msg.signature[58]
                );
                assert_eq!(
                    msg.signature[59], 3,
                    "incorrect value for signature[59], expected 3, is {}",
                    msg.signature[59]
                );
                assert_eq!(
                    msg.signature[60], 4,
                    "incorrect value for signature[60], expected 4, is {}",
                    msg.signature[60]
                );
                assert_eq!(
                    msg.signature[61], 5,
                    "incorrect value for signature[61], expected 5, is {}",
                    msg.signature[61]
                );
                assert_eq!(
                    msg.signature[62], 6,
                    "incorrect value for signature[62], expected 6, is {}",
                    msg.signature[62]
                );
                assert_eq!(
                    msg.signature[63], 7,
                    "incorrect value for signature[63], expected 7, is {}",
                    msg.signature[63]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCertificateChainDep"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_signing_msg_certificate_chain_dep`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_signing_msg_certificate_chain_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 5, 12, 66, 0, 135, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
            18, 19, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 21,
            22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 232, 7, 3, 30,
            12, 34, 59, 21, 205, 91, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3,
            4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0,
            1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 112, 100,
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
        let sbp_msg = sbp::messages::Sbp::MsgCertificateChainDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgCertificateChainDep(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC05,
                    "Incorrect message type, expected 0xC05, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x42,
                    "incorrect sender id, expected 0x42, is {sender_id}"
                );
                assert_eq!(
                    msg.corrections_certificate[0], 20,
                    "incorrect value for corrections_certificate[0], expected 20, is {}",
                    msg.corrections_certificate[0]
                );
                assert_eq!(
                    msg.corrections_certificate[1], 21,
                    "incorrect value for corrections_certificate[1], expected 21, is {}",
                    msg.corrections_certificate[1]
                );
                assert_eq!(
                    msg.corrections_certificate[2], 22,
                    "incorrect value for corrections_certificate[2], expected 22, is {}",
                    msg.corrections_certificate[2]
                );
                assert_eq!(
                    msg.corrections_certificate[3], 23,
                    "incorrect value for corrections_certificate[3], expected 23, is {}",
                    msg.corrections_certificate[3]
                );
                assert_eq!(
                    msg.corrections_certificate[4], 24,
                    "incorrect value for corrections_certificate[4], expected 24, is {}",
                    msg.corrections_certificate[4]
                );
                assert_eq!(
                    msg.corrections_certificate[5], 25,
                    "incorrect value for corrections_certificate[5], expected 25, is {}",
                    msg.corrections_certificate[5]
                );
                assert_eq!(
                    msg.corrections_certificate[6], 26,
                    "incorrect value for corrections_certificate[6], expected 26, is {}",
                    msg.corrections_certificate[6]
                );
                assert_eq!(
                    msg.corrections_certificate[7], 27,
                    "incorrect value for corrections_certificate[7], expected 27, is {}",
                    msg.corrections_certificate[7]
                );
                assert_eq!(
                    msg.corrections_certificate[8], 28,
                    "incorrect value for corrections_certificate[8], expected 28, is {}",
                    msg.corrections_certificate[8]
                );
                assert_eq!(
                    msg.corrections_certificate[9], 29,
                    "incorrect value for corrections_certificate[9], expected 29, is {}",
                    msg.corrections_certificate[9]
                );
                assert_eq!(
                    msg.corrections_certificate[10], 10,
                    "incorrect value for corrections_certificate[10], expected 10, is {}",
                    msg.corrections_certificate[10]
                );
                assert_eq!(
                    msg.corrections_certificate[11], 11,
                    "incorrect value for corrections_certificate[11], expected 11, is {}",
                    msg.corrections_certificate[11]
                );
                assert_eq!(
                    msg.corrections_certificate[12], 12,
                    "incorrect value for corrections_certificate[12], expected 12, is {}",
                    msg.corrections_certificate[12]
                );
                assert_eq!(
                    msg.corrections_certificate[13], 13,
                    "incorrect value for corrections_certificate[13], expected 13, is {}",
                    msg.corrections_certificate[13]
                );
                assert_eq!(
                    msg.corrections_certificate[14], 14,
                    "incorrect value for corrections_certificate[14], expected 14, is {}",
                    msg.corrections_certificate[14]
                );
                assert_eq!(
                    msg.corrections_certificate[15], 15,
                    "incorrect value for corrections_certificate[15], expected 15, is {}",
                    msg.corrections_certificate[15]
                );
                assert_eq!(
                    msg.corrections_certificate[16], 16,
                    "incorrect value for corrections_certificate[16], expected 16, is {}",
                    msg.corrections_certificate[16]
                );
                assert_eq!(
                    msg.corrections_certificate[17], 17,
                    "incorrect value for corrections_certificate[17], expected 17, is {}",
                    msg.corrections_certificate[17]
                );
                assert_eq!(
                    msg.corrections_certificate[18], 18,
                    "incorrect value for corrections_certificate[18], expected 18, is {}",
                    msg.corrections_certificate[18]
                );
                assert_eq!(
                    msg.corrections_certificate[19], 19,
                    "incorrect value for corrections_certificate[19], expected 19, is {}",
                    msg.corrections_certificate[19]
                );
                assert_eq!(
                    msg.expiration.day, 30,
                    "incorrect value for expiration.day, expected 30, is {}",
                    msg.expiration.day
                );
                assert_eq!(
                    msg.expiration.hours, 12,
                    "incorrect value for expiration.hours, expected 12, is {}",
                    msg.expiration.hours
                );
                assert_eq!(
                    msg.expiration.minutes, 34,
                    "incorrect value for expiration.minutes, expected 34, is {}",
                    msg.expiration.minutes
                );
                assert_eq!(
                    msg.expiration.month, 3,
                    "incorrect value for expiration.month, expected 3, is {}",
                    msg.expiration.month
                );
                assert_eq!(
                    msg.expiration.ns, 123456789,
                    "incorrect value for expiration.ns, expected 123456789, is {}",
                    msg.expiration.ns
                );
                assert_eq!(
                    msg.expiration.seconds, 59,
                    "incorrect value for expiration.seconds, expected 59, is {}",
                    msg.expiration.seconds
                );
                assert_eq!(
                    msg.expiration.year, 2024,
                    "incorrect value for expiration.year, expected 2024, is {}",
                    msg.expiration.year
                );
                assert_eq!(
                    msg.intermediate_certificate[0], 10,
                    "incorrect value for intermediate_certificate[0], expected 10, is {}",
                    msg.intermediate_certificate[0]
                );
                assert_eq!(
                    msg.intermediate_certificate[1], 11,
                    "incorrect value for intermediate_certificate[1], expected 11, is {}",
                    msg.intermediate_certificate[1]
                );
                assert_eq!(
                    msg.intermediate_certificate[2], 12,
                    "incorrect value for intermediate_certificate[2], expected 12, is {}",
                    msg.intermediate_certificate[2]
                );
                assert_eq!(
                    msg.intermediate_certificate[3], 13,
                    "incorrect value for intermediate_certificate[3], expected 13, is {}",
                    msg.intermediate_certificate[3]
                );
                assert_eq!(
                    msg.intermediate_certificate[4], 14,
                    "incorrect value for intermediate_certificate[4], expected 14, is {}",
                    msg.intermediate_certificate[4]
                );
                assert_eq!(
                    msg.intermediate_certificate[5], 15,
                    "incorrect value for intermediate_certificate[5], expected 15, is {}",
                    msg.intermediate_certificate[5]
                );
                assert_eq!(
                    msg.intermediate_certificate[6], 16,
                    "incorrect value for intermediate_certificate[6], expected 16, is {}",
                    msg.intermediate_certificate[6]
                );
                assert_eq!(
                    msg.intermediate_certificate[7], 17,
                    "incorrect value for intermediate_certificate[7], expected 17, is {}",
                    msg.intermediate_certificate[7]
                );
                assert_eq!(
                    msg.intermediate_certificate[8], 18,
                    "incorrect value for intermediate_certificate[8], expected 18, is {}",
                    msg.intermediate_certificate[8]
                );
                assert_eq!(
                    msg.intermediate_certificate[9], 19,
                    "incorrect value for intermediate_certificate[9], expected 19, is {}",
                    msg.intermediate_certificate[9]
                );
                assert_eq!(
                    msg.intermediate_certificate[10], 0,
                    "incorrect value for intermediate_certificate[10], expected 0, is {}",
                    msg.intermediate_certificate[10]
                );
                assert_eq!(
                    msg.intermediate_certificate[11], 1,
                    "incorrect value for intermediate_certificate[11], expected 1, is {}",
                    msg.intermediate_certificate[11]
                );
                assert_eq!(
                    msg.intermediate_certificate[12], 2,
                    "incorrect value for intermediate_certificate[12], expected 2, is {}",
                    msg.intermediate_certificate[12]
                );
                assert_eq!(
                    msg.intermediate_certificate[13], 3,
                    "incorrect value for intermediate_certificate[13], expected 3, is {}",
                    msg.intermediate_certificate[13]
                );
                assert_eq!(
                    msg.intermediate_certificate[14], 4,
                    "incorrect value for intermediate_certificate[14], expected 4, is {}",
                    msg.intermediate_certificate[14]
                );
                assert_eq!(
                    msg.intermediate_certificate[15], 5,
                    "incorrect value for intermediate_certificate[15], expected 5, is {}",
                    msg.intermediate_certificate[15]
                );
                assert_eq!(
                    msg.intermediate_certificate[16], 6,
                    "incorrect value for intermediate_certificate[16], expected 6, is {}",
                    msg.intermediate_certificate[16]
                );
                assert_eq!(
                    msg.intermediate_certificate[17], 7,
                    "incorrect value for intermediate_certificate[17], expected 7, is {}",
                    msg.intermediate_certificate[17]
                );
                assert_eq!(
                    msg.intermediate_certificate[18], 8,
                    "incorrect value for intermediate_certificate[18], expected 8, is {}",
                    msg.intermediate_certificate[18]
                );
                assert_eq!(
                    msg.intermediate_certificate[19], 9,
                    "incorrect value for intermediate_certificate[19], expected 9, is {}",
                    msg.intermediate_certificate[19]
                );
                assert_eq!(
                    msg.root_certificate[0], 0,
                    "incorrect value for root_certificate[0], expected 0, is {}",
                    msg.root_certificate[0]
                );
                assert_eq!(
                    msg.root_certificate[1], 1,
                    "incorrect value for root_certificate[1], expected 1, is {}",
                    msg.root_certificate[1]
                );
                assert_eq!(
                    msg.root_certificate[2], 2,
                    "incorrect value for root_certificate[2], expected 2, is {}",
                    msg.root_certificate[2]
                );
                assert_eq!(
                    msg.root_certificate[3], 3,
                    "incorrect value for root_certificate[3], expected 3, is {}",
                    msg.root_certificate[3]
                );
                assert_eq!(
                    msg.root_certificate[4], 4,
                    "incorrect value for root_certificate[4], expected 4, is {}",
                    msg.root_certificate[4]
                );
                assert_eq!(
                    msg.root_certificate[5], 5,
                    "incorrect value for root_certificate[5], expected 5, is {}",
                    msg.root_certificate[5]
                );
                assert_eq!(
                    msg.root_certificate[6], 6,
                    "incorrect value for root_certificate[6], expected 6, is {}",
                    msg.root_certificate[6]
                );
                assert_eq!(
                    msg.root_certificate[7], 7,
                    "incorrect value for root_certificate[7], expected 7, is {}",
                    msg.root_certificate[7]
                );
                assert_eq!(
                    msg.root_certificate[8], 8,
                    "incorrect value for root_certificate[8], expected 8, is {}",
                    msg.root_certificate[8]
                );
                assert_eq!(
                    msg.root_certificate[9], 9,
                    "incorrect value for root_certificate[9], expected 9, is {}",
                    msg.root_certificate[9]
                );
                assert_eq!(
                    msg.root_certificate[10], 10,
                    "incorrect value for root_certificate[10], expected 10, is {}",
                    msg.root_certificate[10]
                );
                assert_eq!(
                    msg.root_certificate[11], 11,
                    "incorrect value for root_certificate[11], expected 11, is {}",
                    msg.root_certificate[11]
                );
                assert_eq!(
                    msg.root_certificate[12], 12,
                    "incorrect value for root_certificate[12], expected 12, is {}",
                    msg.root_certificate[12]
                );
                assert_eq!(
                    msg.root_certificate[13], 13,
                    "incorrect value for root_certificate[13], expected 13, is {}",
                    msg.root_certificate[13]
                );
                assert_eq!(
                    msg.root_certificate[14], 14,
                    "incorrect value for root_certificate[14], expected 14, is {}",
                    msg.root_certificate[14]
                );
                assert_eq!(
                    msg.root_certificate[15], 15,
                    "incorrect value for root_certificate[15], expected 15, is {}",
                    msg.root_certificate[15]
                );
                assert_eq!(
                    msg.root_certificate[16], 16,
                    "incorrect value for root_certificate[16], expected 16, is {}",
                    msg.root_certificate[16]
                );
                assert_eq!(
                    msg.root_certificate[17], 17,
                    "incorrect value for root_certificate[17], expected 17, is {}",
                    msg.root_certificate[17]
                );
                assert_eq!(
                    msg.root_certificate[18], 18,
                    "incorrect value for root_certificate[18], expected 18, is {}",
                    msg.root_certificate[18]
                );
                assert_eq!(
                    msg.root_certificate[19], 19,
                    "incorrect value for root_certificate[19], expected 19, is {}",
                    msg.root_certificate[19]
                );
                assert_eq!(
                    msg.signature[0], 0,
                    "incorrect value for signature[0], expected 0, is {}",
                    msg.signature[0]
                );
                assert_eq!(
                    msg.signature[1], 1,
                    "incorrect value for signature[1], expected 1, is {}",
                    msg.signature[1]
                );
                assert_eq!(
                    msg.signature[2], 2,
                    "incorrect value for signature[2], expected 2, is {}",
                    msg.signature[2]
                );
                assert_eq!(
                    msg.signature[3], 3,
                    "incorrect value for signature[3], expected 3, is {}",
                    msg.signature[3]
                );
                assert_eq!(
                    msg.signature[4], 4,
                    "incorrect value for signature[4], expected 4, is {}",
                    msg.signature[4]
                );
                assert_eq!(
                    msg.signature[5], 5,
                    "incorrect value for signature[5], expected 5, is {}",
                    msg.signature[5]
                );
                assert_eq!(
                    msg.signature[6], 6,
                    "incorrect value for signature[6], expected 6, is {}",
                    msg.signature[6]
                );
                assert_eq!(
                    msg.signature[7], 7,
                    "incorrect value for signature[7], expected 7, is {}",
                    msg.signature[7]
                );
                assert_eq!(
                    msg.signature[8], 0,
                    "incorrect value for signature[8], expected 0, is {}",
                    msg.signature[8]
                );
                assert_eq!(
                    msg.signature[9], 1,
                    "incorrect value for signature[9], expected 1, is {}",
                    msg.signature[9]
                );
                assert_eq!(
                    msg.signature[10], 2,
                    "incorrect value for signature[10], expected 2, is {}",
                    msg.signature[10]
                );
                assert_eq!(
                    msg.signature[11], 3,
                    "incorrect value for signature[11], expected 3, is {}",
                    msg.signature[11]
                );
                assert_eq!(
                    msg.signature[12], 4,
                    "incorrect value for signature[12], expected 4, is {}",
                    msg.signature[12]
                );
                assert_eq!(
                    msg.signature[13], 5,
                    "incorrect value for signature[13], expected 5, is {}",
                    msg.signature[13]
                );
                assert_eq!(
                    msg.signature[14], 6,
                    "incorrect value for signature[14], expected 6, is {}",
                    msg.signature[14]
                );
                assert_eq!(
                    msg.signature[15], 7,
                    "incorrect value for signature[15], expected 7, is {}",
                    msg.signature[15]
                );
                assert_eq!(
                    msg.signature[16], 0,
                    "incorrect value for signature[16], expected 0, is {}",
                    msg.signature[16]
                );
                assert_eq!(
                    msg.signature[17], 1,
                    "incorrect value for signature[17], expected 1, is {}",
                    msg.signature[17]
                );
                assert_eq!(
                    msg.signature[18], 2,
                    "incorrect value for signature[18], expected 2, is {}",
                    msg.signature[18]
                );
                assert_eq!(
                    msg.signature[19], 3,
                    "incorrect value for signature[19], expected 3, is {}",
                    msg.signature[19]
                );
                assert_eq!(
                    msg.signature[20], 4,
                    "incorrect value for signature[20], expected 4, is {}",
                    msg.signature[20]
                );
                assert_eq!(
                    msg.signature[21], 5,
                    "incorrect value for signature[21], expected 5, is {}",
                    msg.signature[21]
                );
                assert_eq!(
                    msg.signature[22], 6,
                    "incorrect value for signature[22], expected 6, is {}",
                    msg.signature[22]
                );
                assert_eq!(
                    msg.signature[23], 7,
                    "incorrect value for signature[23], expected 7, is {}",
                    msg.signature[23]
                );
                assert_eq!(
                    msg.signature[24], 0,
                    "incorrect value for signature[24], expected 0, is {}",
                    msg.signature[24]
                );
                assert_eq!(
                    msg.signature[25], 1,
                    "incorrect value for signature[25], expected 1, is {}",
                    msg.signature[25]
                );
                assert_eq!(
                    msg.signature[26], 2,
                    "incorrect value for signature[26], expected 2, is {}",
                    msg.signature[26]
                );
                assert_eq!(
                    msg.signature[27], 3,
                    "incorrect value for signature[27], expected 3, is {}",
                    msg.signature[27]
                );
                assert_eq!(
                    msg.signature[28], 4,
                    "incorrect value for signature[28], expected 4, is {}",
                    msg.signature[28]
                );
                assert_eq!(
                    msg.signature[29], 5,
                    "incorrect value for signature[29], expected 5, is {}",
                    msg.signature[29]
                );
                assert_eq!(
                    msg.signature[30], 6,
                    "incorrect value for signature[30], expected 6, is {}",
                    msg.signature[30]
                );
                assert_eq!(
                    msg.signature[31], 7,
                    "incorrect value for signature[31], expected 7, is {}",
                    msg.signature[31]
                );
                assert_eq!(
                    msg.signature[32], 0,
                    "incorrect value for signature[32], expected 0, is {}",
                    msg.signature[32]
                );
                assert_eq!(
                    msg.signature[33], 1,
                    "incorrect value for signature[33], expected 1, is {}",
                    msg.signature[33]
                );
                assert_eq!(
                    msg.signature[34], 2,
                    "incorrect value for signature[34], expected 2, is {}",
                    msg.signature[34]
                );
                assert_eq!(
                    msg.signature[35], 3,
                    "incorrect value for signature[35], expected 3, is {}",
                    msg.signature[35]
                );
                assert_eq!(
                    msg.signature[36], 4,
                    "incorrect value for signature[36], expected 4, is {}",
                    msg.signature[36]
                );
                assert_eq!(
                    msg.signature[37], 5,
                    "incorrect value for signature[37], expected 5, is {}",
                    msg.signature[37]
                );
                assert_eq!(
                    msg.signature[38], 6,
                    "incorrect value for signature[38], expected 6, is {}",
                    msg.signature[38]
                );
                assert_eq!(
                    msg.signature[39], 7,
                    "incorrect value for signature[39], expected 7, is {}",
                    msg.signature[39]
                );
                assert_eq!(
                    msg.signature[40], 0,
                    "incorrect value for signature[40], expected 0, is {}",
                    msg.signature[40]
                );
                assert_eq!(
                    msg.signature[41], 1,
                    "incorrect value for signature[41], expected 1, is {}",
                    msg.signature[41]
                );
                assert_eq!(
                    msg.signature[42], 2,
                    "incorrect value for signature[42], expected 2, is {}",
                    msg.signature[42]
                );
                assert_eq!(
                    msg.signature[43], 3,
                    "incorrect value for signature[43], expected 3, is {}",
                    msg.signature[43]
                );
                assert_eq!(
                    msg.signature[44], 4,
                    "incorrect value for signature[44], expected 4, is {}",
                    msg.signature[44]
                );
                assert_eq!(
                    msg.signature[45], 5,
                    "incorrect value for signature[45], expected 5, is {}",
                    msg.signature[45]
                );
                assert_eq!(
                    msg.signature[46], 6,
                    "incorrect value for signature[46], expected 6, is {}",
                    msg.signature[46]
                );
                assert_eq!(
                    msg.signature[47], 7,
                    "incorrect value for signature[47], expected 7, is {}",
                    msg.signature[47]
                );
                assert_eq!(
                    msg.signature[48], 0,
                    "incorrect value for signature[48], expected 0, is {}",
                    msg.signature[48]
                );
                assert_eq!(
                    msg.signature[49], 1,
                    "incorrect value for signature[49], expected 1, is {}",
                    msg.signature[49]
                );
                assert_eq!(
                    msg.signature[50], 2,
                    "incorrect value for signature[50], expected 2, is {}",
                    msg.signature[50]
                );
                assert_eq!(
                    msg.signature[51], 3,
                    "incorrect value for signature[51], expected 3, is {}",
                    msg.signature[51]
                );
                assert_eq!(
                    msg.signature[52], 4,
                    "incorrect value for signature[52], expected 4, is {}",
                    msg.signature[52]
                );
                assert_eq!(
                    msg.signature[53], 5,
                    "incorrect value for signature[53], expected 5, is {}",
                    msg.signature[53]
                );
                assert_eq!(
                    msg.signature[54], 6,
                    "incorrect value for signature[54], expected 6, is {}",
                    msg.signature[54]
                );
                assert_eq!(
                    msg.signature[55], 7,
                    "incorrect value for signature[55], expected 7, is {}",
                    msg.signature[55]
                );
                assert_eq!(
                    msg.signature[56], 0,
                    "incorrect value for signature[56], expected 0, is {}",
                    msg.signature[56]
                );
                assert_eq!(
                    msg.signature[57], 1,
                    "incorrect value for signature[57], expected 1, is {}",
                    msg.signature[57]
                );
                assert_eq!(
                    msg.signature[58], 2,
                    "incorrect value for signature[58], expected 2, is {}",
                    msg.signature[58]
                );
                assert_eq!(
                    msg.signature[59], 3,
                    "incorrect value for signature[59], expected 3, is {}",
                    msg.signature[59]
                );
                assert_eq!(
                    msg.signature[60], 4,
                    "incorrect value for signature[60], expected 4, is {}",
                    msg.signature[60]
                );
                assert_eq!(
                    msg.signature[61], 5,
                    "incorrect value for signature[61], expected 5, is {}",
                    msg.signature[61]
                );
                assert_eq!(
                    msg.signature[62], 6,
                    "incorrect value for signature[62], expected 6, is {}",
                    msg.signature[62]
                );
                assert_eq!(
                    msg.signature[63], 7,
                    "incorrect value for signature[63], expected 7, is {}",
                    msg.signature[63]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCertificateChainDep"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
