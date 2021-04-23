//
// Copyright (C) 2019 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/solution_meta/test_MsgSolnMeta.yaml by generate.py. Do not modify by hand!

use sbp::iter_messages;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

use std::io::Cursor;

#[test]
fn test_auto_check_sbp_solution_meta_68() {
    {
        let mut payload = Cursor::new(vec![
            85, 14, 255, 21, 3, 56, 36, 227, 233, 29, 131, 0, 70, 0, 110, 0, 18, 0, 44, 1, 0, 64,
            9, 0, 10, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 163, 184,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::SBP::MsgSolnMeta(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0xff0e,
                    "Incorrect message type, expected 0xff0e, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x315,
                    "incorrect sender id, expected 0x315, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.age_corrections, 18,
                    "incorrect value for age_corrections, expected 18, is {}",
                    msg.age_corrections
                );
                assert_eq!(
                    msg.age_gnss, 1073742124,
                    "incorrect value for age_gnss, expected 1073742124, is {}",
                    msg.age_gnss
                );
                assert_eq!(
                    msg.hdop, 70,
                    "incorrect value for hdop, expected 70, is {}",
                    msg.hdop
                );
                assert_eq!(
                    msg.pdop, 131,
                    "incorrect value for pdop, expected 131, is {}",
                    msg.pdop
                );
                assert_eq!(
                    msg.sol_in[0].flags, 0,
                    "incorrect value for sol_in[0].flags, expected 0, is {}",
                    msg.sol_in[0].flags
                );
                assert_eq!(
                    msg.sol_in[0].sensor_type, 9,
                    "incorrect value for sol_in[0].sensor_type, expected 9, is {}",
                    msg.sol_in[0].sensor_type
                );
                assert_eq!(
                    msg.sol_in[1].flags, 2,
                    "incorrect value for sol_in[1].flags, expected 2, is {}",
                    msg.sol_in[1].flags
                );
                assert_eq!(
                    msg.sol_in[1].sensor_type, 10,
                    "incorrect value for sol_in[1].sensor_type, expected 10, is {}",
                    msg.sol_in[1].sensor_type
                );
                assert_eq!(
                    msg.sol_in[2].flags, 0,
                    "incorrect value for sol_in[2].flags, expected 0, is {}",
                    msg.sol_in[2].flags
                );
                assert_eq!(
                    msg.sol_in[2].sensor_type, 0,
                    "incorrect value for sol_in[2].sensor_type, expected 0, is {}",
                    msg.sol_in[2].sensor_type
                );
                assert_eq!(
                    msg.sol_in[3].flags, 0,
                    "incorrect value for sol_in[3].flags, expected 0, is {}",
                    msg.sol_in[3].flags
                );
                assert_eq!(
                    msg.sol_in[3].sensor_type, 0,
                    "incorrect value for sol_in[3].sensor_type, expected 0, is {}",
                    msg.sol_in[3].sensor_type
                );
                assert_eq!(
                    msg.sol_in[4].flags, 0,
                    "incorrect value for sol_in[4].flags, expected 0, is {}",
                    msg.sol_in[4].flags
                );
                assert_eq!(
                    msg.sol_in[4].sensor_type, 0,
                    "incorrect value for sol_in[4].sensor_type, expected 0, is {}",
                    msg.sol_in[4].sensor_type
                );
                assert_eq!(
                    msg.sol_in[5].flags, 0,
                    "incorrect value for sol_in[5].flags, expected 0, is {}",
                    msg.sol_in[5].flags
                );
                assert_eq!(
                    msg.sol_in[5].sensor_type, 0,
                    "incorrect value for sol_in[5].sensor_type, expected 0, is {}",
                    msg.sol_in[5].sensor_type
                );
                assert_eq!(
                    msg.sol_in[6].flags, 0,
                    "incorrect value for sol_in[6].flags, expected 0, is {}",
                    msg.sol_in[6].flags
                );
                assert_eq!(
                    msg.sol_in[6].sensor_type, 0,
                    "incorrect value for sol_in[6].sensor_type, expected 0, is {}",
                    msg.sol_in[6].sensor_type
                );
                assert_eq!(
                    msg.sol_in[7].flags, 0,
                    "incorrect value for sol_in[7].flags, expected 0, is {}",
                    msg.sol_in[7].flags
                );
                assert_eq!(
                    msg.sol_in[7].sensor_type, 0,
                    "incorrect value for sol_in[7].sensor_type, expected 0, is {}",
                    msg.sol_in[7].sensor_type
                );
                assert_eq!(
                    msg.sol_in[8].flags, 0,
                    "incorrect value for sol_in[8].flags, expected 0, is {}",
                    msg.sol_in[8].flags
                );
                assert_eq!(
                    msg.sol_in[8].sensor_type, 0,
                    "incorrect value for sol_in[8].sensor_type, expected 0, is {}",
                    msg.sol_in[8].sensor_type
                );
                assert_eq!(
                    msg.sol_in[9].flags, 0,
                    "incorrect value for sol_in[9].flags, expected 0, is {}",
                    msg.sol_in[9].flags
                );
                assert_eq!(
                    msg.sol_in[9].sensor_type, 0,
                    "incorrect value for sol_in[9].sensor_type, expected 0, is {}",
                    msg.sol_in[9].sensor_type
                );
                assert_eq!(
                    msg.sol_in[10].flags, 0,
                    "incorrect value for sol_in[10].flags, expected 0, is {}",
                    msg.sol_in[10].flags
                );
                assert_eq!(
                    msg.sol_in[10].sensor_type, 0,
                    "incorrect value for sol_in[10].sensor_type, expected 0, is {}",
                    msg.sol_in[10].sensor_type
                );
                assert_eq!(
                    msg.sol_in[11].flags, 0,
                    "incorrect value for sol_in[11].flags, expected 0, is {}",
                    msg.sol_in[11].flags
                );
                assert_eq!(
                    msg.sol_in[11].sensor_type, 0,
                    "incorrect value for sol_in[11].sensor_type, expected 0, is {}",
                    msg.sol_in[11].sensor_type
                );
                assert_eq!(
                    msg.sol_in[12].flags, 0,
                    "incorrect value for sol_in[12].flags, expected 0, is {}",
                    msg.sol_in[12].flags
                );
                assert_eq!(
                    msg.sol_in[12].sensor_type, 0,
                    "incorrect value for sol_in[12].sensor_type, expected 0, is {}",
                    msg.sol_in[12].sensor_type
                );
                assert_eq!(
                    msg.sol_in[13].flags, 0,
                    "incorrect value for sol_in[13].flags, expected 0, is {}",
                    msg.sol_in[13].flags
                );
                assert_eq!(
                    msg.sol_in[13].sensor_type, 0,
                    "incorrect value for sol_in[13].sensor_type, expected 0, is {}",
                    msg.sol_in[13].sensor_type
                );
                assert_eq!(
                    msg.sol_in[14].flags, 0,
                    "incorrect value for sol_in[14].flags, expected 0, is {}",
                    msg.sol_in[14].flags
                );
                assert_eq!(
                    msg.sol_in[14].sensor_type, 0,
                    "incorrect value for sol_in[14].sensor_type, expected 0, is {}",
                    msg.sol_in[14].sensor_type
                );
                assert_eq!(
                    msg.sol_in[15].flags, 0,
                    "incorrect value for sol_in[15].flags, expected 0, is {}",
                    msg.sol_in[15].flags
                );
                assert_eq!(
                    msg.sol_in[15].sensor_type, 0,
                    "incorrect value for sol_in[15].sensor_type, expected 0, is {}",
                    msg.sol_in[15].sensor_type
                );
                assert_eq!(
                    msg.sol_in[16].flags, 0,
                    "incorrect value for sol_in[16].flags, expected 0, is {}",
                    msg.sol_in[16].flags
                );
                assert_eq!(
                    msg.sol_in[16].sensor_type, 0,
                    "incorrect value for sol_in[16].sensor_type, expected 0, is {}",
                    msg.sol_in[16].sensor_type
                );
                assert_eq!(
                    msg.sol_in[17].flags, 0,
                    "incorrect value for sol_in[17].flags, expected 0, is {}",
                    msg.sol_in[17].flags
                );
                assert_eq!(
                    msg.sol_in[17].sensor_type, 0,
                    "incorrect value for sol_in[17].sensor_type, expected 0, is {}",
                    msg.sol_in[17].sensor_type
                );
                assert_eq!(
                    msg.sol_in[18].flags, 0,
                    "incorrect value for sol_in[18].flags, expected 0, is {}",
                    msg.sol_in[18].flags
                );
                assert_eq!(
                    msg.sol_in[18].sensor_type, 0,
                    "incorrect value for sol_in[18].sensor_type, expected 0, is {}",
                    msg.sol_in[18].sensor_type
                );
                assert_eq!(
                    msg.sol_in[19].flags, 0,
                    "incorrect value for sol_in[19].flags, expected 0, is {}",
                    msg.sol_in[19].flags
                );
                assert_eq!(
                    msg.sol_in[19].sensor_type, 0,
                    "incorrect value for sol_in[19].sensor_type, expected 0, is {}",
                    msg.sol_in[19].sensor_type
                );
                assert_eq!(
                    msg.tow, 501867300,
                    "incorrect value for tow, expected 501867300, is {}",
                    msg.tow
                );
                assert_eq!(
                    msg.vdop, 110,
                    "incorrect value for vdop, expected 110, is {}",
                    msg.vdop
                );
            }
            _ => panic!("Invalid message type! Expected a MsgSolnMeta"),
        };
        let frame = sbp_msg.to_frame().unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
