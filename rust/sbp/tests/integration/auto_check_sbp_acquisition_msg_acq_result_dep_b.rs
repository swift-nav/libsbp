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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepB.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_acquisition_msg_acq_result_dep_b() {
    {
        let mut payload = Cursor::new(vec![
            85, 20, 0, 246, 215, 16, 137, 167, 18, 66, 0, 0, 161, 67, 240, 24, 156, 69, 9, 0, 0, 0,
            80, 195,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepB(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x14,
                    "Incorrect message type, expected 0x14, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(4.99511718750000000e+03),
                    "incorrect value for cf, expected 4.99511718750000000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(3.22000000000000000e+02),
                    "incorrect value for cp, expected 3.22000000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 9,
                    "incorrect value for sid.sat, expected 9, is {}",
                    msg.sid.sat
                );
                assert!(
                    msg.snr.almost_eq(3.66636085510253906e+01),
                    "incorrect value for snr, expected 3.66636085510253906e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 20, 0, 246, 215, 16, 206, 172, 16, 66, 0, 192, 82, 68, 198, 199, 0, 198, 3, 0, 0,
            0, 149, 143,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepB(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x14,
                    "Incorrect message type, expected 0x14, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-8.24194335937500000e+03),
                    "incorrect value for cf, expected -8.24194335937500000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(8.43000000000000000e+02),
                    "incorrect value for cp, expected 8.43000000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 3,
                    "incorrect value for sid.sat, expected 3, is {}",
                    msg.sid.sat
                );
                assert!(
                    msg.snr.almost_eq(3.61687545776367188e+01),
                    "incorrect value for snr, expected 3.61687545776367188e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 20, 0, 246, 215, 16, 228, 27, 15, 66, 0, 128, 70, 68, 228, 74, 148, 69, 18, 0, 0,
            0, 179, 155,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepB(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x14,
                    "Incorrect message type, expected 0x14, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(4.74536132812500000e+03),
                    "incorrect value for cf, expected 4.74536132812500000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(7.94000000000000000e+02),
                    "incorrect value for cp, expected 7.94000000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 18,
                    "incorrect value for sid.sat, expected 18, is {}",
                    msg.sid.sat
                );
                assert!(
                    msg.snr.almost_eq(3.57772369384765625e+01),
                    "incorrect value for snr, expected 3.57772369384765625e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 20, 0, 246, 215, 16, 46, 199, 14, 66, 0, 64, 129, 67, 240, 24, 28, 69, 17, 0, 0, 0,
            18, 181,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepB(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x14,
                    "Incorrect message type, expected 0x14, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(2.49755859375000000e+03),
                    "incorrect value for cf, expected 2.49755859375000000e+03, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(2.58500000000000000e+02),
                    "incorrect value for cp, expected 2.58500000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 17,
                    "incorrect value for sid.sat, expected 17, is {}",
                    msg.sid.sat
                );
                assert!(
                    msg.snr.almost_eq(3.56945114135742188e+01),
                    "incorrect value for snr, expected 3.56945114135742188e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 20, 0, 246, 215, 16, 194, 24, 14, 66, 0, 128, 2, 68, 129, 193, 249, 195, 5, 0, 0,
            0, 35, 203,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgAcqResultDepB(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x14,
                    "Incorrect message type, expected 0x14, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
                    sender_id
                );
                assert!(
                    msg.cf.almost_eq(-4.99511749267578125e+02),
                    "incorrect value for cf, expected -4.99511749267578125e+02, is {:e}",
                    msg.cf
                );
                assert!(
                    msg.cp.almost_eq(5.22000000000000000e+02),
                    "incorrect value for cp, expected 5.22000000000000000e+02, is {:e}",
                    msg.cp
                );
                assert_eq!(
                    msg.sid.code, 0,
                    "incorrect value for sid.code, expected 0, is {}",
                    msg.sid.code
                );
                assert_eq!(
                    msg.sid.reserved, 0,
                    "incorrect value for sid.reserved, expected 0, is {}",
                    msg.sid.reserved
                );
                assert_eq!(
                    msg.sid.sat, 5,
                    "incorrect value for sid.sat, expected 5, is {}",
                    msg.sid.sat
                );
                assert!(
                    msg.snr.almost_eq(3.55241775512695312e+01),
                    "incorrect value for snr, expected 3.55241775512695312e+01, is {:e}",
                    msg.snr
                );
            }
            _ => panic!("Invalid message type! Expected a MsgAcqResultDepB"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
