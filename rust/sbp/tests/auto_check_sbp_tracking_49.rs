//
// Copyright (C) 2019 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDep.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_tracking_49() {
    {
        let payload: Vec<u8> = vec![
            85, 17, 0, 59, 103, 55, 163, 151, 112, 215, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 39, 5, 0, 0, 169, 177, 208, 54, 15, 0, 0, 0, 85, 61, 0, 0, 39, 0, 1, 0, 0, 0, 0,
            0, 0, 0, 40, 0, 108, 1, 0, 11, 0, 0, 9, 166, 214,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.L.f, 169,
                    "incorrect value for L.f, expected 169, is {}",
                    msg.L.f
                );
                assert_eq!(
                    msg.L.i, 1319,
                    "incorrect value for L.i, expected 1319, is {}",
                    msg.L.i
                );
                assert_eq!(msg.P, 0, "incorrect value for P, expected 0, is {}", msg.P);
                assert_eq!(
                    msg.P_std, 0,
                    "incorrect value for P_std, expected 0, is {}",
                    msg.P_std
                );
                assert_eq!(
                    msg.acceleration, 108,
                    "incorrect value for acceleration, expected 108, is {}",
                    msg.acceleration
                );
                assert_eq!(
                    msg.clock_drift, 0,
                    "incorrect value for clock_drift, expected 0, is {}",
                    msg.clock_drift
                );
                assert_eq!(
                    msg.clock_offset, 0,
                    "incorrect value for clock_offset, expected 0, is {}",
                    msg.clock_offset
                );
                assert_eq!(
                    msg.cn0, 177,
                    "incorrect value for cn0, expected 177, is {}",
                    msg.cn0
                );
                assert_eq!(
                    msg.corr_spacing, 40,
                    "incorrect value for corr_spacing, expected 40, is {}",
                    msg.corr_spacing
                );
                assert_eq!(
                    msg.doppler, 15701,
                    "incorrect value for doppler, expected 15701, is {}",
                    msg.doppler
                );
                assert_eq!(
                    msg.doppler_std, 39,
                    "incorrect value for doppler_std, expected 39, is {}",
                    msg.doppler_std
                );
                assert_eq!(
                    msg.lock, 14032,
                    "incorrect value for lock, expected 14032, is {}",
                    msg.lock
                );
                assert_eq!(
                    msg.misc_flags, 9,
                    "incorrect value for misc_flags, expected 9, is {}",
                    msg.misc_flags
                );
                assert_eq!(
                    msg.nav_flags, 0,
                    "incorrect value for nav_flags, expected 0, is {}",
                    msg.nav_flags
                );
                assert_eq!(
                    msg.pset_flags, 0,
                    "incorrect value for pset_flags, expected 0, is {}",
                    msg.pset_flags
                );
                assert_eq!(
                    msg.recv_time, 7909447587,
                    "incorrect value for recv_time, expected 7909447587, is {}",
                    msg.recv_time
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
                    msg.sid.sat, 15,
                    "incorrect value for sid.sat, expected 15, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.sync_flags, 1,
                    "incorrect value for sync_flags, expected 1, is {}",
                    msg.sync_flags
                );
                assert_eq!(
                    msg.tot.tow, 0,
                    "incorrect value for tot.tow, expected 0, is {}",
                    msg.tot.tow
                );
                assert_eq!(
                    msg.tot.wn, 0,
                    "incorrect value for tot.wn, expected 0, is {}",
                    msg.tot.wn
                );
                assert_eq!(
                    msg.tow_flags, 0,
                    "incorrect value for tow_flags, expected 0, is {}",
                    msg.tow_flags
                );
                assert_eq!(
                    msg.track_flags, 11,
                    "incorrect value for track_flags, expected 11, is {}",
                    msg.track_flags
                );
                assert_eq!(
                    msg.uptime, 1,
                    "incorrect value for uptime, expected 1, is {}",
                    msg.uptime
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDetailedDep"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 17, 0, 59, 103, 55, 97, 251, 61, 245, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 18, 7, 0, 0, 14, 175, 208, 54, 15, 0, 0, 0, 51, 61, 0, 0, 30, 0, 1, 0, 0, 0, 0, 0,
            0, 0, 40, 0, 224, 1, 0, 11, 0, 0, 9, 136, 179,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.L.f, 14,
                    "incorrect value for L.f, expected 14, is {}",
                    msg.L.f
                );
                assert_eq!(
                    msg.L.i, 1810,
                    "incorrect value for L.i, expected 1810, is {}",
                    msg.L.i
                );
                assert_eq!(msg.P, 0, "incorrect value for P, expected 0, is {}", msg.P);
                assert_eq!(
                    msg.P_std, 0,
                    "incorrect value for P_std, expected 0, is {}",
                    msg.P_std
                );
                assert_eq!(
                    msg.acceleration, -32,
                    "incorrect value for acceleration, expected -32, is {}",
                    msg.acceleration
                );
                assert_eq!(
                    msg.clock_drift, 0,
                    "incorrect value for clock_drift, expected 0, is {}",
                    msg.clock_drift
                );
                assert_eq!(
                    msg.clock_offset, 0,
                    "incorrect value for clock_offset, expected 0, is {}",
                    msg.clock_offset
                );
                assert_eq!(
                    msg.cn0, 175,
                    "incorrect value for cn0, expected 175, is {}",
                    msg.cn0
                );
                assert_eq!(
                    msg.corr_spacing, 40,
                    "incorrect value for corr_spacing, expected 40, is {}",
                    msg.corr_spacing
                );
                assert_eq!(
                    msg.doppler, 15667,
                    "incorrect value for doppler, expected 15667, is {}",
                    msg.doppler
                );
                assert_eq!(
                    msg.doppler_std, 30,
                    "incorrect value for doppler_std, expected 30, is {}",
                    msg.doppler_std
                );
                assert_eq!(
                    msg.lock, 14032,
                    "incorrect value for lock, expected 14032, is {}",
                    msg.lock
                );
                assert_eq!(
                    msg.misc_flags, 9,
                    "incorrect value for misc_flags, expected 9, is {}",
                    msg.misc_flags
                );
                assert_eq!(
                    msg.nav_flags, 0,
                    "incorrect value for nav_flags, expected 0, is {}",
                    msg.nav_flags
                );
                assert_eq!(
                    msg.pset_flags, 0,
                    "incorrect value for pset_flags, expected 0, is {}",
                    msg.pset_flags
                );
                assert_eq!(
                    msg.recv_time, 8409447265,
                    "incorrect value for recv_time, expected 8409447265, is {}",
                    msg.recv_time
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
                    msg.sid.sat, 15,
                    "incorrect value for sid.sat, expected 15, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.sync_flags, 1,
                    "incorrect value for sync_flags, expected 1, is {}",
                    msg.sync_flags
                );
                assert_eq!(
                    msg.tot.tow, 0,
                    "incorrect value for tot.tow, expected 0, is {}",
                    msg.tot.tow
                );
                assert_eq!(
                    msg.tot.wn, 0,
                    "incorrect value for tot.wn, expected 0, is {}",
                    msg.tot.wn
                );
                assert_eq!(
                    msg.tow_flags, 0,
                    "incorrect value for tow_flags, expected 0, is {}",
                    msg.tow_flags
                );
                assert_eq!(
                    msg.track_flags, 11,
                    "incorrect value for track_flags, expected 11, is {}",
                    msg.track_flags
                );
                assert_eq!(
                    msg.uptime, 1,
                    "incorrect value for uptime, expected 1, is {}",
                    msg.uptime
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDetailedDep"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 17, 0, 59, 103, 55, 139, 218, 236, 18, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 250, 8, 0, 0, 8, 179, 208, 54, 15, 0, 0, 0, 67, 61, 0, 0, 22, 0, 2, 0, 0, 0, 0, 0,
            0, 0, 40, 0, 27, 1, 0, 11, 0, 2, 9, 217, 159,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.L.f, 8,
                    "incorrect value for L.f, expected 8, is {}",
                    msg.L.f
                );
                assert_eq!(
                    msg.L.i, 2298,
                    "incorrect value for L.i, expected 2298, is {}",
                    msg.L.i
                );
                assert_eq!(msg.P, 0, "incorrect value for P, expected 0, is {}", msg.P);
                assert_eq!(
                    msg.P_std, 0,
                    "incorrect value for P_std, expected 0, is {}",
                    msg.P_std
                );
                assert_eq!(
                    msg.acceleration, 27,
                    "incorrect value for acceleration, expected 27, is {}",
                    msg.acceleration
                );
                assert_eq!(
                    msg.clock_drift, 0,
                    "incorrect value for clock_drift, expected 0, is {}",
                    msg.clock_drift
                );
                assert_eq!(
                    msg.clock_offset, 0,
                    "incorrect value for clock_offset, expected 0, is {}",
                    msg.clock_offset
                );
                assert_eq!(
                    msg.cn0, 179,
                    "incorrect value for cn0, expected 179, is {}",
                    msg.cn0
                );
                assert_eq!(
                    msg.corr_spacing, 40,
                    "incorrect value for corr_spacing, expected 40, is {}",
                    msg.corr_spacing
                );
                assert_eq!(
                    msg.doppler, 15683,
                    "incorrect value for doppler, expected 15683, is {}",
                    msg.doppler
                );
                assert_eq!(
                    msg.doppler_std, 22,
                    "incorrect value for doppler_std, expected 22, is {}",
                    msg.doppler_std
                );
                assert_eq!(
                    msg.lock, 14032,
                    "incorrect value for lock, expected 14032, is {}",
                    msg.lock
                );
                assert_eq!(
                    msg.misc_flags, 9,
                    "incorrect value for misc_flags, expected 9, is {}",
                    msg.misc_flags
                );
                assert_eq!(
                    msg.nav_flags, 0,
                    "incorrect value for nav_flags, expected 0, is {}",
                    msg.nav_flags
                );
                assert_eq!(
                    msg.pset_flags, 2,
                    "incorrect value for pset_flags, expected 2, is {}",
                    msg.pset_flags
                );
                assert_eq!(
                    msg.recv_time, 8907446923,
                    "incorrect value for recv_time, expected 8907446923, is {}",
                    msg.recv_time
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
                    msg.sid.sat, 15,
                    "incorrect value for sid.sat, expected 15, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.sync_flags, 1,
                    "incorrect value for sync_flags, expected 1, is {}",
                    msg.sync_flags
                );
                assert_eq!(
                    msg.tot.tow, 0,
                    "incorrect value for tot.tow, expected 0, is {}",
                    msg.tot.tow
                );
                assert_eq!(
                    msg.tot.wn, 0,
                    "incorrect value for tot.wn, expected 0, is {}",
                    msg.tot.wn
                );
                assert_eq!(
                    msg.tow_flags, 0,
                    "incorrect value for tow_flags, expected 0, is {}",
                    msg.tow_flags
                );
                assert_eq!(
                    msg.track_flags, 11,
                    "incorrect value for track_flags, expected 11, is {}",
                    msg.track_flags
                );
                assert_eq!(
                    msg.uptime, 2,
                    "incorrect value for uptime, expected 2, is {}",
                    msg.uptime
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDetailedDep"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 17, 0, 59, 103, 55, 255, 251, 170, 48, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 226, 10, 0, 0, 125, 181, 208, 54, 15, 0, 0, 0, 29, 61, 0, 0, 10, 0, 2, 0, 0, 0, 0,
            0, 0, 0, 40, 0, 220, 1, 0, 11, 0, 3, 9, 66, 95,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.L.f, 125,
                    "incorrect value for L.f, expected 125, is {}",
                    msg.L.f
                );
                assert_eq!(
                    msg.L.i, 2786,
                    "incorrect value for L.i, expected 2786, is {}",
                    msg.L.i
                );
                assert_eq!(msg.P, 0, "incorrect value for P, expected 0, is {}", msg.P);
                assert_eq!(
                    msg.P_std, 0,
                    "incorrect value for P_std, expected 0, is {}",
                    msg.P_std
                );
                assert_eq!(
                    msg.acceleration, -36,
                    "incorrect value for acceleration, expected -36, is {}",
                    msg.acceleration
                );
                assert_eq!(
                    msg.clock_drift, 0,
                    "incorrect value for clock_drift, expected 0, is {}",
                    msg.clock_drift
                );
                assert_eq!(
                    msg.clock_offset, 0,
                    "incorrect value for clock_offset, expected 0, is {}",
                    msg.clock_offset
                );
                assert_eq!(
                    msg.cn0, 181,
                    "incorrect value for cn0, expected 181, is {}",
                    msg.cn0
                );
                assert_eq!(
                    msg.corr_spacing, 40,
                    "incorrect value for corr_spacing, expected 40, is {}",
                    msg.corr_spacing
                );
                assert_eq!(
                    msg.doppler, 15645,
                    "incorrect value for doppler, expected 15645, is {}",
                    msg.doppler
                );
                assert_eq!(
                    msg.doppler_std, 10,
                    "incorrect value for doppler_std, expected 10, is {}",
                    msg.doppler_std
                );
                assert_eq!(
                    msg.lock, 14032,
                    "incorrect value for lock, expected 14032, is {}",
                    msg.lock
                );
                assert_eq!(
                    msg.misc_flags, 9,
                    "incorrect value for misc_flags, expected 9, is {}",
                    msg.misc_flags
                );
                assert_eq!(
                    msg.nav_flags, 0,
                    "incorrect value for nav_flags, expected 0, is {}",
                    msg.nav_flags
                );
                assert_eq!(
                    msg.pset_flags, 3,
                    "incorrect value for pset_flags, expected 3, is {}",
                    msg.pset_flags
                );
                assert_eq!(
                    msg.recv_time, 9406446591,
                    "incorrect value for recv_time, expected 9406446591, is {}",
                    msg.recv_time
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
                    msg.sid.sat, 15,
                    "incorrect value for sid.sat, expected 15, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.sync_flags, 1,
                    "incorrect value for sync_flags, expected 1, is {}",
                    msg.sync_flags
                );
                assert_eq!(
                    msg.tot.tow, 0,
                    "incorrect value for tot.tow, expected 0, is {}",
                    msg.tot.tow
                );
                assert_eq!(
                    msg.tot.wn, 0,
                    "incorrect value for tot.wn, expected 0, is {}",
                    msg.tot.wn
                );
                assert_eq!(
                    msg.tow_flags, 0,
                    "incorrect value for tow_flags, expected 0, is {}",
                    msg.tow_flags
                );
                assert_eq!(
                    msg.track_flags, 11,
                    "incorrect value for track_flags, expected 11, is {}",
                    msg.track_flags
                );
                assert_eq!(
                    msg.uptime, 2,
                    "incorrect value for uptime, expected 2, is {}",
                    msg.uptime
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDetailedDep"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 17, 0, 59, 103, 55, 189, 95, 120, 78, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 203, 12, 0, 0, 64, 184, 208, 54, 15, 0, 0, 0, 24, 61, 0, 0, 4, 0, 3, 0, 0, 0, 0, 0,
            0, 0, 40, 0, 2, 1, 0, 11, 0, 3, 9, 194, 206,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.L.f, 64,
                    "incorrect value for L.f, expected 64, is {}",
                    msg.L.f
                );
                assert_eq!(
                    msg.L.i, 3275,
                    "incorrect value for L.i, expected 3275, is {}",
                    msg.L.i
                );
                assert_eq!(msg.P, 0, "incorrect value for P, expected 0, is {}", msg.P);
                assert_eq!(
                    msg.P_std, 0,
                    "incorrect value for P_std, expected 0, is {}",
                    msg.P_std
                );
                assert_eq!(
                    msg.acceleration, 2,
                    "incorrect value for acceleration, expected 2, is {}",
                    msg.acceleration
                );
                assert_eq!(
                    msg.clock_drift, 0,
                    "incorrect value for clock_drift, expected 0, is {}",
                    msg.clock_drift
                );
                assert_eq!(
                    msg.clock_offset, 0,
                    "incorrect value for clock_offset, expected 0, is {}",
                    msg.clock_offset
                );
                assert_eq!(
                    msg.cn0, 184,
                    "incorrect value for cn0, expected 184, is {}",
                    msg.cn0
                );
                assert_eq!(
                    msg.corr_spacing, 40,
                    "incorrect value for corr_spacing, expected 40, is {}",
                    msg.corr_spacing
                );
                assert_eq!(
                    msg.doppler, 15640,
                    "incorrect value for doppler, expected 15640, is {}",
                    msg.doppler
                );
                assert_eq!(
                    msg.doppler_std, 4,
                    "incorrect value for doppler_std, expected 4, is {}",
                    msg.doppler_std
                );
                assert_eq!(
                    msg.lock, 14032,
                    "incorrect value for lock, expected 14032, is {}",
                    msg.lock
                );
                assert_eq!(
                    msg.misc_flags, 9,
                    "incorrect value for misc_flags, expected 9, is {}",
                    msg.misc_flags
                );
                assert_eq!(
                    msg.nav_flags, 0,
                    "incorrect value for nav_flags, expected 0, is {}",
                    msg.nav_flags
                );
                assert_eq!(
                    msg.pset_flags, 3,
                    "incorrect value for pset_flags, expected 3, is {}",
                    msg.pset_flags
                );
                assert_eq!(
                    msg.recv_time, 9906446269,
                    "incorrect value for recv_time, expected 9906446269, is {}",
                    msg.recv_time
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
                    msg.sid.sat, 15,
                    "incorrect value for sid.sat, expected 15, is {}",
                    msg.sid.sat
                );
                assert_eq!(
                    msg.sync_flags, 1,
                    "incorrect value for sync_flags, expected 1, is {}",
                    msg.sync_flags
                );
                assert_eq!(
                    msg.tot.tow, 0,
                    "incorrect value for tot.tow, expected 0, is {}",
                    msg.tot.tow
                );
                assert_eq!(
                    msg.tot.wn, 0,
                    "incorrect value for tot.wn, expected 0, is {}",
                    msg.tot.wn
                );
                assert_eq!(
                    msg.tow_flags, 0,
                    "incorrect value for tow_flags, expected 0, is {}",
                    msg.tow_flags
                );
                assert_eq!(
                    msg.track_flags, 11,
                    "incorrect value for track_flags, expected 11, is {}",
                    msg.track_flags
                );
                assert_eq!(
                    msg.uptime, 3,
                    "incorrect value for uptime, expected 3, is {}",
                    msg.uptime
                );
            }
            _ => panic!("Invalid message type! Expected a MsgTrackingStateDetailedDep"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
