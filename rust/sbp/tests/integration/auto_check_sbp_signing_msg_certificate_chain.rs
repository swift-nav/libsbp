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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgCertificateChain.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_signing_msg_certificate_chain() {
    {
        let mut payload = Cursor::new(vec![
            85, 9, 12, 66, 0, 144, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
            18, 19, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 21,
            22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 232, 7, 3, 30,
            12, 34, 59, 21, 205, 91, 7, 72, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
            16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
            38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
            60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 227, 224,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgCertificateChain(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC09,
                    "Incorrect message type, expected 0xC09, is {msg_type}"
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
                    msg.signature.data[0], 0,
                    "incorrect value for signature.data[0], expected 0, is {}",
                    msg.signature.data[0]
                );
                assert_eq!(
                    msg.signature.data[1], 1,
                    "incorrect value for signature.data[1], expected 1, is {}",
                    msg.signature.data[1]
                );
                assert_eq!(
                    msg.signature.data[2], 2,
                    "incorrect value for signature.data[2], expected 2, is {}",
                    msg.signature.data[2]
                );
                assert_eq!(
                    msg.signature.data[3], 3,
                    "incorrect value for signature.data[3], expected 3, is {}",
                    msg.signature.data[3]
                );
                assert_eq!(
                    msg.signature.data[4], 4,
                    "incorrect value for signature.data[4], expected 4, is {}",
                    msg.signature.data[4]
                );
                assert_eq!(
                    msg.signature.data[5], 5,
                    "incorrect value for signature.data[5], expected 5, is {}",
                    msg.signature.data[5]
                );
                assert_eq!(
                    msg.signature.data[6], 6,
                    "incorrect value for signature.data[6], expected 6, is {}",
                    msg.signature.data[6]
                );
                assert_eq!(
                    msg.signature.data[7], 7,
                    "incorrect value for signature.data[7], expected 7, is {}",
                    msg.signature.data[7]
                );
                assert_eq!(
                    msg.signature.data[8], 8,
                    "incorrect value for signature.data[8], expected 8, is {}",
                    msg.signature.data[8]
                );
                assert_eq!(
                    msg.signature.data[9], 9,
                    "incorrect value for signature.data[9], expected 9, is {}",
                    msg.signature.data[9]
                );
                assert_eq!(
                    msg.signature.data[10], 10,
                    "incorrect value for signature.data[10], expected 10, is {}",
                    msg.signature.data[10]
                );
                assert_eq!(
                    msg.signature.data[11], 11,
                    "incorrect value for signature.data[11], expected 11, is {}",
                    msg.signature.data[11]
                );
                assert_eq!(
                    msg.signature.data[12], 12,
                    "incorrect value for signature.data[12], expected 12, is {}",
                    msg.signature.data[12]
                );
                assert_eq!(
                    msg.signature.data[13], 13,
                    "incorrect value for signature.data[13], expected 13, is {}",
                    msg.signature.data[13]
                );
                assert_eq!(
                    msg.signature.data[14], 14,
                    "incorrect value for signature.data[14], expected 14, is {}",
                    msg.signature.data[14]
                );
                assert_eq!(
                    msg.signature.data[15], 15,
                    "incorrect value for signature.data[15], expected 15, is {}",
                    msg.signature.data[15]
                );
                assert_eq!(
                    msg.signature.data[16], 16,
                    "incorrect value for signature.data[16], expected 16, is {}",
                    msg.signature.data[16]
                );
                assert_eq!(
                    msg.signature.data[17], 17,
                    "incorrect value for signature.data[17], expected 17, is {}",
                    msg.signature.data[17]
                );
                assert_eq!(
                    msg.signature.data[18], 18,
                    "incorrect value for signature.data[18], expected 18, is {}",
                    msg.signature.data[18]
                );
                assert_eq!(
                    msg.signature.data[19], 19,
                    "incorrect value for signature.data[19], expected 19, is {}",
                    msg.signature.data[19]
                );
                assert_eq!(
                    msg.signature.data[20], 20,
                    "incorrect value for signature.data[20], expected 20, is {}",
                    msg.signature.data[20]
                );
                assert_eq!(
                    msg.signature.data[21], 21,
                    "incorrect value for signature.data[21], expected 21, is {}",
                    msg.signature.data[21]
                );
                assert_eq!(
                    msg.signature.data[22], 22,
                    "incorrect value for signature.data[22], expected 22, is {}",
                    msg.signature.data[22]
                );
                assert_eq!(
                    msg.signature.data[23], 23,
                    "incorrect value for signature.data[23], expected 23, is {}",
                    msg.signature.data[23]
                );
                assert_eq!(
                    msg.signature.data[24], 24,
                    "incorrect value for signature.data[24], expected 24, is {}",
                    msg.signature.data[24]
                );
                assert_eq!(
                    msg.signature.data[25], 25,
                    "incorrect value for signature.data[25], expected 25, is {}",
                    msg.signature.data[25]
                );
                assert_eq!(
                    msg.signature.data[26], 26,
                    "incorrect value for signature.data[26], expected 26, is {}",
                    msg.signature.data[26]
                );
                assert_eq!(
                    msg.signature.data[27], 27,
                    "incorrect value for signature.data[27], expected 27, is {}",
                    msg.signature.data[27]
                );
                assert_eq!(
                    msg.signature.data[28], 28,
                    "incorrect value for signature.data[28], expected 28, is {}",
                    msg.signature.data[28]
                );
                assert_eq!(
                    msg.signature.data[29], 29,
                    "incorrect value for signature.data[29], expected 29, is {}",
                    msg.signature.data[29]
                );
                assert_eq!(
                    msg.signature.data[30], 30,
                    "incorrect value for signature.data[30], expected 30, is {}",
                    msg.signature.data[30]
                );
                assert_eq!(
                    msg.signature.data[31], 31,
                    "incorrect value for signature.data[31], expected 31, is {}",
                    msg.signature.data[31]
                );
                assert_eq!(
                    msg.signature.data[32], 32,
                    "incorrect value for signature.data[32], expected 32, is {}",
                    msg.signature.data[32]
                );
                assert_eq!(
                    msg.signature.data[33], 33,
                    "incorrect value for signature.data[33], expected 33, is {}",
                    msg.signature.data[33]
                );
                assert_eq!(
                    msg.signature.data[34], 34,
                    "incorrect value for signature.data[34], expected 34, is {}",
                    msg.signature.data[34]
                );
                assert_eq!(
                    msg.signature.data[35], 35,
                    "incorrect value for signature.data[35], expected 35, is {}",
                    msg.signature.data[35]
                );
                assert_eq!(
                    msg.signature.data[36], 36,
                    "incorrect value for signature.data[36], expected 36, is {}",
                    msg.signature.data[36]
                );
                assert_eq!(
                    msg.signature.data[37], 37,
                    "incorrect value for signature.data[37], expected 37, is {}",
                    msg.signature.data[37]
                );
                assert_eq!(
                    msg.signature.data[38], 38,
                    "incorrect value for signature.data[38], expected 38, is {}",
                    msg.signature.data[38]
                );
                assert_eq!(
                    msg.signature.data[39], 39,
                    "incorrect value for signature.data[39], expected 39, is {}",
                    msg.signature.data[39]
                );
                assert_eq!(
                    msg.signature.data[40], 40,
                    "incorrect value for signature.data[40], expected 40, is {}",
                    msg.signature.data[40]
                );
                assert_eq!(
                    msg.signature.data[41], 41,
                    "incorrect value for signature.data[41], expected 41, is {}",
                    msg.signature.data[41]
                );
                assert_eq!(
                    msg.signature.data[42], 42,
                    "incorrect value for signature.data[42], expected 42, is {}",
                    msg.signature.data[42]
                );
                assert_eq!(
                    msg.signature.data[43], 43,
                    "incorrect value for signature.data[43], expected 43, is {}",
                    msg.signature.data[43]
                );
                assert_eq!(
                    msg.signature.data[44], 44,
                    "incorrect value for signature.data[44], expected 44, is {}",
                    msg.signature.data[44]
                );
                assert_eq!(
                    msg.signature.data[45], 45,
                    "incorrect value for signature.data[45], expected 45, is {}",
                    msg.signature.data[45]
                );
                assert_eq!(
                    msg.signature.data[46], 46,
                    "incorrect value for signature.data[46], expected 46, is {}",
                    msg.signature.data[46]
                );
                assert_eq!(
                    msg.signature.data[47], 47,
                    "incorrect value for signature.data[47], expected 47, is {}",
                    msg.signature.data[47]
                );
                assert_eq!(
                    msg.signature.data[48], 48,
                    "incorrect value for signature.data[48], expected 48, is {}",
                    msg.signature.data[48]
                );
                assert_eq!(
                    msg.signature.data[49], 49,
                    "incorrect value for signature.data[49], expected 49, is {}",
                    msg.signature.data[49]
                );
                assert_eq!(
                    msg.signature.data[50], 50,
                    "incorrect value for signature.data[50], expected 50, is {}",
                    msg.signature.data[50]
                );
                assert_eq!(
                    msg.signature.data[51], 51,
                    "incorrect value for signature.data[51], expected 51, is {}",
                    msg.signature.data[51]
                );
                assert_eq!(
                    msg.signature.data[52], 52,
                    "incorrect value for signature.data[52], expected 52, is {}",
                    msg.signature.data[52]
                );
                assert_eq!(
                    msg.signature.data[53], 53,
                    "incorrect value for signature.data[53], expected 53, is {}",
                    msg.signature.data[53]
                );
                assert_eq!(
                    msg.signature.data[54], 54,
                    "incorrect value for signature.data[54], expected 54, is {}",
                    msg.signature.data[54]
                );
                assert_eq!(
                    msg.signature.data[55], 55,
                    "incorrect value for signature.data[55], expected 55, is {}",
                    msg.signature.data[55]
                );
                assert_eq!(
                    msg.signature.data[56], 56,
                    "incorrect value for signature.data[56], expected 56, is {}",
                    msg.signature.data[56]
                );
                assert_eq!(
                    msg.signature.data[57], 57,
                    "incorrect value for signature.data[57], expected 57, is {}",
                    msg.signature.data[57]
                );
                assert_eq!(
                    msg.signature.data[58], 58,
                    "incorrect value for signature.data[58], expected 58, is {}",
                    msg.signature.data[58]
                );
                assert_eq!(
                    msg.signature.data[59], 59,
                    "incorrect value for signature.data[59], expected 59, is {}",
                    msg.signature.data[59]
                );
                assert_eq!(
                    msg.signature.data[60], 60,
                    "incorrect value for signature.data[60], expected 60, is {}",
                    msg.signature.data[60]
                );
                assert_eq!(
                    msg.signature.data[61], 61,
                    "incorrect value for signature.data[61], expected 61, is {}",
                    msg.signature.data[61]
                );
                assert_eq!(
                    msg.signature.data[62], 62,
                    "incorrect value for signature.data[62], expected 62, is {}",
                    msg.signature.data[62]
                );
                assert_eq!(
                    msg.signature.data[63], 63,
                    "incorrect value for signature.data[63], expected 63, is {}",
                    msg.signature.data[63]
                );
                assert_eq!(
                    msg.signature.data[64], 64,
                    "incorrect value for signature.data[64], expected 64, is {}",
                    msg.signature.data[64]
                );
                assert_eq!(
                    msg.signature.data[65], 65,
                    "incorrect value for signature.data[65], expected 65, is {}",
                    msg.signature.data[65]
                );
                assert_eq!(
                    msg.signature.data[66], 66,
                    "incorrect value for signature.data[66], expected 66, is {}",
                    msg.signature.data[66]
                );
                assert_eq!(
                    msg.signature.data[67], 67,
                    "incorrect value for signature.data[67], expected 67, is {}",
                    msg.signature.data[67]
                );
                assert_eq!(
                    msg.signature.data[68], 68,
                    "incorrect value for signature.data[68], expected 68, is {}",
                    msg.signature.data[68]
                );
                assert_eq!(
                    msg.signature.data[69], 69,
                    "incorrect value for signature.data[69], expected 69, is {}",
                    msg.signature.data[69]
                );
                assert_eq!(
                    msg.signature.data[70], 70,
                    "incorrect value for signature.data[70], expected 70, is {}",
                    msg.signature.data[70]
                );
                assert_eq!(
                    msg.signature.data[71], 71,
                    "incorrect value for signature.data[71], expected 71, is {}",
                    msg.signature.data[71]
                );
                assert_eq!(
                    msg.signature.len, 72,
                    "incorrect value for signature.len, expected 72, is {}",
                    msg.signature.len
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCertificateChain"),
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
fn test_json2sbp_auto_check_sbp_signing_msg_certificate_chain() {
    {
        let json_input = r#"{"preamble": 85, "msg_type": 3081, "sender": 66, "length": 144, "payload": "AAECAwQFBgcICQoLDA0ODxAREhMKCwwNDg8QERITAAECAwQFBgcICRQVFhcYGRobHB0KCwwNDg8QERIT6AcDHgwiOxXNWwdIAAECAwQFBgcICQoLDA0ODxAREhMUFRYXGBkaGxwdHh8gISIjJCUmJygpKissLS4vMDEyMzQ1Njc4OTo7PD0+P0BBQkNERUZH", "crc": 57571, "root_certificate": [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19], "intermediate_certificate": [10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9], "corrections_certificate": [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19], "expiration": {"year": 2024, "month": 3, "day": 30, "hours": 12, "minutes": 34, "seconds": 59, "ns": 123456789}, "signature": {"len": 72, "data": [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71]}}"#.as_bytes();

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
            sbp::messages::Sbp::MsgCertificateChain(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC09,
                    "Incorrect message type, expected 0xC09, is {}",
                    msg_type
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
                    msg.signature.data[0], 0,
                    "incorrect value for signature.data[0], expected 0, is {}",
                    msg.signature.data[0]
                );
                assert_eq!(
                    msg.signature.data[1], 1,
                    "incorrect value for signature.data[1], expected 1, is {}",
                    msg.signature.data[1]
                );
                assert_eq!(
                    msg.signature.data[2], 2,
                    "incorrect value for signature.data[2], expected 2, is {}",
                    msg.signature.data[2]
                );
                assert_eq!(
                    msg.signature.data[3], 3,
                    "incorrect value for signature.data[3], expected 3, is {}",
                    msg.signature.data[3]
                );
                assert_eq!(
                    msg.signature.data[4], 4,
                    "incorrect value for signature.data[4], expected 4, is {}",
                    msg.signature.data[4]
                );
                assert_eq!(
                    msg.signature.data[5], 5,
                    "incorrect value for signature.data[5], expected 5, is {}",
                    msg.signature.data[5]
                );
                assert_eq!(
                    msg.signature.data[6], 6,
                    "incorrect value for signature.data[6], expected 6, is {}",
                    msg.signature.data[6]
                );
                assert_eq!(
                    msg.signature.data[7], 7,
                    "incorrect value for signature.data[7], expected 7, is {}",
                    msg.signature.data[7]
                );
                assert_eq!(
                    msg.signature.data[8], 8,
                    "incorrect value for signature.data[8], expected 8, is {}",
                    msg.signature.data[8]
                );
                assert_eq!(
                    msg.signature.data[9], 9,
                    "incorrect value for signature.data[9], expected 9, is {}",
                    msg.signature.data[9]
                );
                assert_eq!(
                    msg.signature.data[10], 10,
                    "incorrect value for signature.data[10], expected 10, is {}",
                    msg.signature.data[10]
                );
                assert_eq!(
                    msg.signature.data[11], 11,
                    "incorrect value for signature.data[11], expected 11, is {}",
                    msg.signature.data[11]
                );
                assert_eq!(
                    msg.signature.data[12], 12,
                    "incorrect value for signature.data[12], expected 12, is {}",
                    msg.signature.data[12]
                );
                assert_eq!(
                    msg.signature.data[13], 13,
                    "incorrect value for signature.data[13], expected 13, is {}",
                    msg.signature.data[13]
                );
                assert_eq!(
                    msg.signature.data[14], 14,
                    "incorrect value for signature.data[14], expected 14, is {}",
                    msg.signature.data[14]
                );
                assert_eq!(
                    msg.signature.data[15], 15,
                    "incorrect value for signature.data[15], expected 15, is {}",
                    msg.signature.data[15]
                );
                assert_eq!(
                    msg.signature.data[16], 16,
                    "incorrect value for signature.data[16], expected 16, is {}",
                    msg.signature.data[16]
                );
                assert_eq!(
                    msg.signature.data[17], 17,
                    "incorrect value for signature.data[17], expected 17, is {}",
                    msg.signature.data[17]
                );
                assert_eq!(
                    msg.signature.data[18], 18,
                    "incorrect value for signature.data[18], expected 18, is {}",
                    msg.signature.data[18]
                );
                assert_eq!(
                    msg.signature.data[19], 19,
                    "incorrect value for signature.data[19], expected 19, is {}",
                    msg.signature.data[19]
                );
                assert_eq!(
                    msg.signature.data[20], 20,
                    "incorrect value for signature.data[20], expected 20, is {}",
                    msg.signature.data[20]
                );
                assert_eq!(
                    msg.signature.data[21], 21,
                    "incorrect value for signature.data[21], expected 21, is {}",
                    msg.signature.data[21]
                );
                assert_eq!(
                    msg.signature.data[22], 22,
                    "incorrect value for signature.data[22], expected 22, is {}",
                    msg.signature.data[22]
                );
                assert_eq!(
                    msg.signature.data[23], 23,
                    "incorrect value for signature.data[23], expected 23, is {}",
                    msg.signature.data[23]
                );
                assert_eq!(
                    msg.signature.data[24], 24,
                    "incorrect value for signature.data[24], expected 24, is {}",
                    msg.signature.data[24]
                );
                assert_eq!(
                    msg.signature.data[25], 25,
                    "incorrect value for signature.data[25], expected 25, is {}",
                    msg.signature.data[25]
                );
                assert_eq!(
                    msg.signature.data[26], 26,
                    "incorrect value for signature.data[26], expected 26, is {}",
                    msg.signature.data[26]
                );
                assert_eq!(
                    msg.signature.data[27], 27,
                    "incorrect value for signature.data[27], expected 27, is {}",
                    msg.signature.data[27]
                );
                assert_eq!(
                    msg.signature.data[28], 28,
                    "incorrect value for signature.data[28], expected 28, is {}",
                    msg.signature.data[28]
                );
                assert_eq!(
                    msg.signature.data[29], 29,
                    "incorrect value for signature.data[29], expected 29, is {}",
                    msg.signature.data[29]
                );
                assert_eq!(
                    msg.signature.data[30], 30,
                    "incorrect value for signature.data[30], expected 30, is {}",
                    msg.signature.data[30]
                );
                assert_eq!(
                    msg.signature.data[31], 31,
                    "incorrect value for signature.data[31], expected 31, is {}",
                    msg.signature.data[31]
                );
                assert_eq!(
                    msg.signature.data[32], 32,
                    "incorrect value for signature.data[32], expected 32, is {}",
                    msg.signature.data[32]
                );
                assert_eq!(
                    msg.signature.data[33], 33,
                    "incorrect value for signature.data[33], expected 33, is {}",
                    msg.signature.data[33]
                );
                assert_eq!(
                    msg.signature.data[34], 34,
                    "incorrect value for signature.data[34], expected 34, is {}",
                    msg.signature.data[34]
                );
                assert_eq!(
                    msg.signature.data[35], 35,
                    "incorrect value for signature.data[35], expected 35, is {}",
                    msg.signature.data[35]
                );
                assert_eq!(
                    msg.signature.data[36], 36,
                    "incorrect value for signature.data[36], expected 36, is {}",
                    msg.signature.data[36]
                );
                assert_eq!(
                    msg.signature.data[37], 37,
                    "incorrect value for signature.data[37], expected 37, is {}",
                    msg.signature.data[37]
                );
                assert_eq!(
                    msg.signature.data[38], 38,
                    "incorrect value for signature.data[38], expected 38, is {}",
                    msg.signature.data[38]
                );
                assert_eq!(
                    msg.signature.data[39], 39,
                    "incorrect value for signature.data[39], expected 39, is {}",
                    msg.signature.data[39]
                );
                assert_eq!(
                    msg.signature.data[40], 40,
                    "incorrect value for signature.data[40], expected 40, is {}",
                    msg.signature.data[40]
                );
                assert_eq!(
                    msg.signature.data[41], 41,
                    "incorrect value for signature.data[41], expected 41, is {}",
                    msg.signature.data[41]
                );
                assert_eq!(
                    msg.signature.data[42], 42,
                    "incorrect value for signature.data[42], expected 42, is {}",
                    msg.signature.data[42]
                );
                assert_eq!(
                    msg.signature.data[43], 43,
                    "incorrect value for signature.data[43], expected 43, is {}",
                    msg.signature.data[43]
                );
                assert_eq!(
                    msg.signature.data[44], 44,
                    "incorrect value for signature.data[44], expected 44, is {}",
                    msg.signature.data[44]
                );
                assert_eq!(
                    msg.signature.data[45], 45,
                    "incorrect value for signature.data[45], expected 45, is {}",
                    msg.signature.data[45]
                );
                assert_eq!(
                    msg.signature.data[46], 46,
                    "incorrect value for signature.data[46], expected 46, is {}",
                    msg.signature.data[46]
                );
                assert_eq!(
                    msg.signature.data[47], 47,
                    "incorrect value for signature.data[47], expected 47, is {}",
                    msg.signature.data[47]
                );
                assert_eq!(
                    msg.signature.data[48], 48,
                    "incorrect value for signature.data[48], expected 48, is {}",
                    msg.signature.data[48]
                );
                assert_eq!(
                    msg.signature.data[49], 49,
                    "incorrect value for signature.data[49], expected 49, is {}",
                    msg.signature.data[49]
                );
                assert_eq!(
                    msg.signature.data[50], 50,
                    "incorrect value for signature.data[50], expected 50, is {}",
                    msg.signature.data[50]
                );
                assert_eq!(
                    msg.signature.data[51], 51,
                    "incorrect value for signature.data[51], expected 51, is {}",
                    msg.signature.data[51]
                );
                assert_eq!(
                    msg.signature.data[52], 52,
                    "incorrect value for signature.data[52], expected 52, is {}",
                    msg.signature.data[52]
                );
                assert_eq!(
                    msg.signature.data[53], 53,
                    "incorrect value for signature.data[53], expected 53, is {}",
                    msg.signature.data[53]
                );
                assert_eq!(
                    msg.signature.data[54], 54,
                    "incorrect value for signature.data[54], expected 54, is {}",
                    msg.signature.data[54]
                );
                assert_eq!(
                    msg.signature.data[55], 55,
                    "incorrect value for signature.data[55], expected 55, is {}",
                    msg.signature.data[55]
                );
                assert_eq!(
                    msg.signature.data[56], 56,
                    "incorrect value for signature.data[56], expected 56, is {}",
                    msg.signature.data[56]
                );
                assert_eq!(
                    msg.signature.data[57], 57,
                    "incorrect value for signature.data[57], expected 57, is {}",
                    msg.signature.data[57]
                );
                assert_eq!(
                    msg.signature.data[58], 58,
                    "incorrect value for signature.data[58], expected 58, is {}",
                    msg.signature.data[58]
                );
                assert_eq!(
                    msg.signature.data[59], 59,
                    "incorrect value for signature.data[59], expected 59, is {}",
                    msg.signature.data[59]
                );
                assert_eq!(
                    msg.signature.data[60], 60,
                    "incorrect value for signature.data[60], expected 60, is {}",
                    msg.signature.data[60]
                );
                assert_eq!(
                    msg.signature.data[61], 61,
                    "incorrect value for signature.data[61], expected 61, is {}",
                    msg.signature.data[61]
                );
                assert_eq!(
                    msg.signature.data[62], 62,
                    "incorrect value for signature.data[62], expected 62, is {}",
                    msg.signature.data[62]
                );
                assert_eq!(
                    msg.signature.data[63], 63,
                    "incorrect value for signature.data[63], expected 63, is {}",
                    msg.signature.data[63]
                );
                assert_eq!(
                    msg.signature.data[64], 64,
                    "incorrect value for signature.data[64], expected 64, is {}",
                    msg.signature.data[64]
                );
                assert_eq!(
                    msg.signature.data[65], 65,
                    "incorrect value for signature.data[65], expected 65, is {}",
                    msg.signature.data[65]
                );
                assert_eq!(
                    msg.signature.data[66], 66,
                    "incorrect value for signature.data[66], expected 66, is {}",
                    msg.signature.data[66]
                );
                assert_eq!(
                    msg.signature.data[67], 67,
                    "incorrect value for signature.data[67], expected 67, is {}",
                    msg.signature.data[67]
                );
                assert_eq!(
                    msg.signature.data[68], 68,
                    "incorrect value for signature.data[68], expected 68, is {}",
                    msg.signature.data[68]
                );
                assert_eq!(
                    msg.signature.data[69], 69,
                    "incorrect value for signature.data[69], expected 69, is {}",
                    msg.signature.data[69]
                );
                assert_eq!(
                    msg.signature.data[70], 70,
                    "incorrect value for signature.data[70], expected 70, is {}",
                    msg.signature.data[70]
                );
                assert_eq!(
                    msg.signature.data[71], 71,
                    "incorrect value for signature.data[71], expected 71, is {}",
                    msg.signature.data[71]
                );
                assert_eq!(
                    msg.signature.len, 72,
                    "incorrect value for signature.len, expected 72, is {}",
                    msg.signature.len
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCertificateChain"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_signing_msg_certificate_chain`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_signing_msg_certificate_chain() {
    {
        let mut payload = Cursor::new(vec![
            85, 9, 12, 66, 0, 144, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
            18, 19, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 21,
            22, 23, 24, 25, 26, 27, 28, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 232, 7, 3, 30,
            12, 34, 59, 21, 205, 91, 7, 72, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
            16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
            38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
            60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 227, 224,
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
        let sbp_msg = sbp::messages::Sbp::MsgCertificateChain(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgCertificateChain(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xC09,
                    "Incorrect message type, expected 0xC09, is {}",
                    msg_type
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
                    msg.signature.data[0], 0,
                    "incorrect value for signature.data[0], expected 0, is {}",
                    msg.signature.data[0]
                );
                assert_eq!(
                    msg.signature.data[1], 1,
                    "incorrect value for signature.data[1], expected 1, is {}",
                    msg.signature.data[1]
                );
                assert_eq!(
                    msg.signature.data[2], 2,
                    "incorrect value for signature.data[2], expected 2, is {}",
                    msg.signature.data[2]
                );
                assert_eq!(
                    msg.signature.data[3], 3,
                    "incorrect value for signature.data[3], expected 3, is {}",
                    msg.signature.data[3]
                );
                assert_eq!(
                    msg.signature.data[4], 4,
                    "incorrect value for signature.data[4], expected 4, is {}",
                    msg.signature.data[4]
                );
                assert_eq!(
                    msg.signature.data[5], 5,
                    "incorrect value for signature.data[5], expected 5, is {}",
                    msg.signature.data[5]
                );
                assert_eq!(
                    msg.signature.data[6], 6,
                    "incorrect value for signature.data[6], expected 6, is {}",
                    msg.signature.data[6]
                );
                assert_eq!(
                    msg.signature.data[7], 7,
                    "incorrect value for signature.data[7], expected 7, is {}",
                    msg.signature.data[7]
                );
                assert_eq!(
                    msg.signature.data[8], 8,
                    "incorrect value for signature.data[8], expected 8, is {}",
                    msg.signature.data[8]
                );
                assert_eq!(
                    msg.signature.data[9], 9,
                    "incorrect value for signature.data[9], expected 9, is {}",
                    msg.signature.data[9]
                );
                assert_eq!(
                    msg.signature.data[10], 10,
                    "incorrect value for signature.data[10], expected 10, is {}",
                    msg.signature.data[10]
                );
                assert_eq!(
                    msg.signature.data[11], 11,
                    "incorrect value for signature.data[11], expected 11, is {}",
                    msg.signature.data[11]
                );
                assert_eq!(
                    msg.signature.data[12], 12,
                    "incorrect value for signature.data[12], expected 12, is {}",
                    msg.signature.data[12]
                );
                assert_eq!(
                    msg.signature.data[13], 13,
                    "incorrect value for signature.data[13], expected 13, is {}",
                    msg.signature.data[13]
                );
                assert_eq!(
                    msg.signature.data[14], 14,
                    "incorrect value for signature.data[14], expected 14, is {}",
                    msg.signature.data[14]
                );
                assert_eq!(
                    msg.signature.data[15], 15,
                    "incorrect value for signature.data[15], expected 15, is {}",
                    msg.signature.data[15]
                );
                assert_eq!(
                    msg.signature.data[16], 16,
                    "incorrect value for signature.data[16], expected 16, is {}",
                    msg.signature.data[16]
                );
                assert_eq!(
                    msg.signature.data[17], 17,
                    "incorrect value for signature.data[17], expected 17, is {}",
                    msg.signature.data[17]
                );
                assert_eq!(
                    msg.signature.data[18], 18,
                    "incorrect value for signature.data[18], expected 18, is {}",
                    msg.signature.data[18]
                );
                assert_eq!(
                    msg.signature.data[19], 19,
                    "incorrect value for signature.data[19], expected 19, is {}",
                    msg.signature.data[19]
                );
                assert_eq!(
                    msg.signature.data[20], 20,
                    "incorrect value for signature.data[20], expected 20, is {}",
                    msg.signature.data[20]
                );
                assert_eq!(
                    msg.signature.data[21], 21,
                    "incorrect value for signature.data[21], expected 21, is {}",
                    msg.signature.data[21]
                );
                assert_eq!(
                    msg.signature.data[22], 22,
                    "incorrect value for signature.data[22], expected 22, is {}",
                    msg.signature.data[22]
                );
                assert_eq!(
                    msg.signature.data[23], 23,
                    "incorrect value for signature.data[23], expected 23, is {}",
                    msg.signature.data[23]
                );
                assert_eq!(
                    msg.signature.data[24], 24,
                    "incorrect value for signature.data[24], expected 24, is {}",
                    msg.signature.data[24]
                );
                assert_eq!(
                    msg.signature.data[25], 25,
                    "incorrect value for signature.data[25], expected 25, is {}",
                    msg.signature.data[25]
                );
                assert_eq!(
                    msg.signature.data[26], 26,
                    "incorrect value for signature.data[26], expected 26, is {}",
                    msg.signature.data[26]
                );
                assert_eq!(
                    msg.signature.data[27], 27,
                    "incorrect value for signature.data[27], expected 27, is {}",
                    msg.signature.data[27]
                );
                assert_eq!(
                    msg.signature.data[28], 28,
                    "incorrect value for signature.data[28], expected 28, is {}",
                    msg.signature.data[28]
                );
                assert_eq!(
                    msg.signature.data[29], 29,
                    "incorrect value for signature.data[29], expected 29, is {}",
                    msg.signature.data[29]
                );
                assert_eq!(
                    msg.signature.data[30], 30,
                    "incorrect value for signature.data[30], expected 30, is {}",
                    msg.signature.data[30]
                );
                assert_eq!(
                    msg.signature.data[31], 31,
                    "incorrect value for signature.data[31], expected 31, is {}",
                    msg.signature.data[31]
                );
                assert_eq!(
                    msg.signature.data[32], 32,
                    "incorrect value for signature.data[32], expected 32, is {}",
                    msg.signature.data[32]
                );
                assert_eq!(
                    msg.signature.data[33], 33,
                    "incorrect value for signature.data[33], expected 33, is {}",
                    msg.signature.data[33]
                );
                assert_eq!(
                    msg.signature.data[34], 34,
                    "incorrect value for signature.data[34], expected 34, is {}",
                    msg.signature.data[34]
                );
                assert_eq!(
                    msg.signature.data[35], 35,
                    "incorrect value for signature.data[35], expected 35, is {}",
                    msg.signature.data[35]
                );
                assert_eq!(
                    msg.signature.data[36], 36,
                    "incorrect value for signature.data[36], expected 36, is {}",
                    msg.signature.data[36]
                );
                assert_eq!(
                    msg.signature.data[37], 37,
                    "incorrect value for signature.data[37], expected 37, is {}",
                    msg.signature.data[37]
                );
                assert_eq!(
                    msg.signature.data[38], 38,
                    "incorrect value for signature.data[38], expected 38, is {}",
                    msg.signature.data[38]
                );
                assert_eq!(
                    msg.signature.data[39], 39,
                    "incorrect value for signature.data[39], expected 39, is {}",
                    msg.signature.data[39]
                );
                assert_eq!(
                    msg.signature.data[40], 40,
                    "incorrect value for signature.data[40], expected 40, is {}",
                    msg.signature.data[40]
                );
                assert_eq!(
                    msg.signature.data[41], 41,
                    "incorrect value for signature.data[41], expected 41, is {}",
                    msg.signature.data[41]
                );
                assert_eq!(
                    msg.signature.data[42], 42,
                    "incorrect value for signature.data[42], expected 42, is {}",
                    msg.signature.data[42]
                );
                assert_eq!(
                    msg.signature.data[43], 43,
                    "incorrect value for signature.data[43], expected 43, is {}",
                    msg.signature.data[43]
                );
                assert_eq!(
                    msg.signature.data[44], 44,
                    "incorrect value for signature.data[44], expected 44, is {}",
                    msg.signature.data[44]
                );
                assert_eq!(
                    msg.signature.data[45], 45,
                    "incorrect value for signature.data[45], expected 45, is {}",
                    msg.signature.data[45]
                );
                assert_eq!(
                    msg.signature.data[46], 46,
                    "incorrect value for signature.data[46], expected 46, is {}",
                    msg.signature.data[46]
                );
                assert_eq!(
                    msg.signature.data[47], 47,
                    "incorrect value for signature.data[47], expected 47, is {}",
                    msg.signature.data[47]
                );
                assert_eq!(
                    msg.signature.data[48], 48,
                    "incorrect value for signature.data[48], expected 48, is {}",
                    msg.signature.data[48]
                );
                assert_eq!(
                    msg.signature.data[49], 49,
                    "incorrect value for signature.data[49], expected 49, is {}",
                    msg.signature.data[49]
                );
                assert_eq!(
                    msg.signature.data[50], 50,
                    "incorrect value for signature.data[50], expected 50, is {}",
                    msg.signature.data[50]
                );
                assert_eq!(
                    msg.signature.data[51], 51,
                    "incorrect value for signature.data[51], expected 51, is {}",
                    msg.signature.data[51]
                );
                assert_eq!(
                    msg.signature.data[52], 52,
                    "incorrect value for signature.data[52], expected 52, is {}",
                    msg.signature.data[52]
                );
                assert_eq!(
                    msg.signature.data[53], 53,
                    "incorrect value for signature.data[53], expected 53, is {}",
                    msg.signature.data[53]
                );
                assert_eq!(
                    msg.signature.data[54], 54,
                    "incorrect value for signature.data[54], expected 54, is {}",
                    msg.signature.data[54]
                );
                assert_eq!(
                    msg.signature.data[55], 55,
                    "incorrect value for signature.data[55], expected 55, is {}",
                    msg.signature.data[55]
                );
                assert_eq!(
                    msg.signature.data[56], 56,
                    "incorrect value for signature.data[56], expected 56, is {}",
                    msg.signature.data[56]
                );
                assert_eq!(
                    msg.signature.data[57], 57,
                    "incorrect value for signature.data[57], expected 57, is {}",
                    msg.signature.data[57]
                );
                assert_eq!(
                    msg.signature.data[58], 58,
                    "incorrect value for signature.data[58], expected 58, is {}",
                    msg.signature.data[58]
                );
                assert_eq!(
                    msg.signature.data[59], 59,
                    "incorrect value for signature.data[59], expected 59, is {}",
                    msg.signature.data[59]
                );
                assert_eq!(
                    msg.signature.data[60], 60,
                    "incorrect value for signature.data[60], expected 60, is {}",
                    msg.signature.data[60]
                );
                assert_eq!(
                    msg.signature.data[61], 61,
                    "incorrect value for signature.data[61], expected 61, is {}",
                    msg.signature.data[61]
                );
                assert_eq!(
                    msg.signature.data[62], 62,
                    "incorrect value for signature.data[62], expected 62, is {}",
                    msg.signature.data[62]
                );
                assert_eq!(
                    msg.signature.data[63], 63,
                    "incorrect value for signature.data[63], expected 63, is {}",
                    msg.signature.data[63]
                );
                assert_eq!(
                    msg.signature.data[64], 64,
                    "incorrect value for signature.data[64], expected 64, is {}",
                    msg.signature.data[64]
                );
                assert_eq!(
                    msg.signature.data[65], 65,
                    "incorrect value for signature.data[65], expected 65, is {}",
                    msg.signature.data[65]
                );
                assert_eq!(
                    msg.signature.data[66], 66,
                    "incorrect value for signature.data[66], expected 66, is {}",
                    msg.signature.data[66]
                );
                assert_eq!(
                    msg.signature.data[67], 67,
                    "incorrect value for signature.data[67], expected 67, is {}",
                    msg.signature.data[67]
                );
                assert_eq!(
                    msg.signature.data[68], 68,
                    "incorrect value for signature.data[68], expected 68, is {}",
                    msg.signature.data[68]
                );
                assert_eq!(
                    msg.signature.data[69], 69,
                    "incorrect value for signature.data[69], expected 69, is {}",
                    msg.signature.data[69]
                );
                assert_eq!(
                    msg.signature.data[70], 70,
                    "incorrect value for signature.data[70], expected 70, is {}",
                    msg.signature.data[70]
                );
                assert_eq!(
                    msg.signature.data[71], 71,
                    "incorrect value for signature.data[71], expected 71, is {}",
                    msg.signature.data[71]
                );
                assert_eq!(
                    msg.signature.len, 72,
                    "incorrect value for signature.len, expected 72, is {}",
                    msg.signature.len
                );
            }
            _ => panic!("Invalid message type! Expected a MsgCertificateChain"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
