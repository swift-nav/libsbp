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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDep.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 17, 0, 59, 103, 55, 163, 151, 112, 215, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 39, 5, 0, 0, 169, 177, 208, 54, 15, 0, 0, 0, 85, 61, 0, 0, 39, 0, 1, 0, 0, 0, 0,
            0, 0, 0, 40, 0, 108, 1, 0, 11, 0, 0, 9, 166, 214,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 169,
                    "incorrect value for l.f, expected 169, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 1319,
                    "incorrect value for l.i, expected 1319, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 17, 0, 59, 103, 55, 97, 251, 61, 245, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 18, 7, 0, 0, 14, 175, 208, 54, 15, 0, 0, 0, 51, 61, 0, 0, 30, 0, 1, 0, 0, 0, 0, 0,
            0, 0, 40, 0, 224, 1, 0, 11, 0, 0, 9, 136, 179,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 14,
                    "incorrect value for l.f, expected 14, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 1810,
                    "incorrect value for l.i, expected 1810, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 17, 0, 59, 103, 55, 139, 218, 236, 18, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 250, 8, 0, 0, 8, 179, 208, 54, 15, 0, 0, 0, 67, 61, 0, 0, 22, 0, 2, 0, 0, 0, 0, 0,
            0, 0, 40, 0, 27, 1, 0, 11, 0, 2, 9, 217, 159,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 8,
                    "incorrect value for l.f, expected 8, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 2298,
                    "incorrect value for l.i, expected 2298, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 17, 0, 59, 103, 55, 255, 251, 170, 48, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 226, 10, 0, 0, 125, 181, 208, 54, 15, 0, 0, 0, 29, 61, 0, 0, 10, 0, 2, 0, 0, 0, 0,
            0, 0, 0, 40, 0, 220, 1, 0, 11, 0, 3, 9, 66, 95,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 125,
                    "incorrect value for l.f, expected 125, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 2786,
                    "incorrect value for l.i, expected 2786, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 17, 0, 59, 103, 55, 189, 95, 120, 78, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 203, 12, 0, 0, 64, 184, 208, 54, 15, 0, 0, 0, 24, 61, 0, 0, 4, 0, 3, 0, 0, 0, 0, 0,
            0, 0, 40, 0, 2, 1, 0, 11, 0, 3, 9, 194, 206,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 64,
                    "incorrect value for l.f, expected 64, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 3275,
                    "incorrect value for l.i, expected 3275, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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
fn test_json2sbp_auto_check_sbp_tracking_msg_tracking_state_detailed_dep() {
    {
        let json_input = r#"{"track_flags": 11, "doppler": 15701, "clock_offset": 0, "msg_type": 17, "lock": 14032, "nav_flags": 0, "P_std": 0, "L": {"i": 1319, "f": 169}, "pset_flags": 0, "P": 0, "misc_flags": 9, "preamble": 85, "payload": "o5dw1wEAAAAAAAAAAAAAAAAAAAAnBQAAqbHQNg8AAABVPQAAJwABAAAAAAAAACgAbAEACwAACQ==", "recv_time": 7909447587, "acceleration": 108, "uptime": 1, "sender": 26427, "cn0": 177, "doppler_std": 39, "tow_flags": 0, "tot": {"wn": 0, "tow": 0}, "crc": 54950, "length": 55, "clock_drift": 0, "sid": {"code": 0, "reserved": 0, "sat": 15}, "sync_flags": 1, "corr_spacing": 40}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 169,
                    "incorrect value for l.f, expected 169, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 1319,
                    "incorrect value for l.i, expected 1319, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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
    }
    {
        let json_input = r#"{"track_flags": 11, "doppler": 15667, "clock_offset": 0, "msg_type": 17, "lock": 14032, "nav_flags": 0, "P_std": 0, "L": {"i": 1810, "f": 14}, "pset_flags": 0, "P": 0, "misc_flags": 9, "preamble": 85, "payload": "Yfs99QEAAAAAAAAAAAAAAAAAAAASBwAADq/QNg8AAAAzPQAAHgABAAAAAAAAACgA4AEACwAACQ==", "recv_time": 8409447265, "acceleration": -32, "uptime": 1, "sender": 26427, "cn0": 175, "doppler_std": 30, "tow_flags": 0, "tot": {"wn": 0, "tow": 0}, "crc": 45960, "length": 55, "clock_drift": 0, "sid": {"code": 0, "reserved": 0, "sat": 15}, "sync_flags": 1, "corr_spacing": 40}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 14,
                    "incorrect value for l.f, expected 14, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 1810,
                    "incorrect value for l.i, expected 1810, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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
    }
    {
        let json_input = r#"{"track_flags": 11, "doppler": 15683, "clock_offset": 0, "msg_type": 17, "lock": 14032, "nav_flags": 0, "P_std": 0, "L": {"i": 2298, "f": 8}, "pset_flags": 2, "P": 0, "misc_flags": 9, "preamble": 85, "payload": "i9rsEgIAAAAAAAAAAAAAAAAAAAD6CAAACLPQNg8AAABDPQAAFgACAAAAAAAAACgAGwEACwACCQ==", "recv_time": 8907446923, "acceleration": 27, "uptime": 2, "sender": 26427, "cn0": 179, "doppler_std": 22, "tow_flags": 0, "tot": {"wn": 0, "tow": 0}, "crc": 40921, "length": 55, "clock_drift": 0, "sid": {"code": 0, "reserved": 0, "sat": 15}, "sync_flags": 1, "corr_spacing": 40}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 8,
                    "incorrect value for l.f, expected 8, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 2298,
                    "incorrect value for l.i, expected 2298, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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
    }
    {
        let json_input = r#"{"track_flags": 11, "doppler": 15645, "clock_offset": 0, "msg_type": 17, "lock": 14032, "nav_flags": 0, "P_std": 0, "L": {"i": 2786, "f": 125}, "pset_flags": 3, "P": 0, "misc_flags": 9, "preamble": 85, "payload": "//uqMAIAAAAAAAAAAAAAAAAAAADiCgAAfbXQNg8AAAAdPQAACgACAAAAAAAAACgA3AEACwADCQ==", "recv_time": 9406446591, "acceleration": -36, "uptime": 2, "sender": 26427, "cn0": 181, "doppler_std": 10, "tow_flags": 0, "tot": {"wn": 0, "tow": 0}, "crc": 24386, "length": 55, "clock_drift": 0, "sid": {"code": 0, "reserved": 0, "sat": 15}, "sync_flags": 1, "corr_spacing": 40}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 125,
                    "incorrect value for l.f, expected 125, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 2786,
                    "incorrect value for l.i, expected 2786, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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
    }
    {
        let json_input = r#"{"track_flags": 11, "doppler": 15640, "clock_offset": 0, "msg_type": 17, "lock": 14032, "nav_flags": 0, "P_std": 0, "L": {"i": 3275, "f": 64}, "pset_flags": 3, "P": 0, "misc_flags": 9, "preamble": 85, "payload": "vV94TgIAAAAAAAAAAAAAAAAAAADLDAAAQLjQNg8AAAAYPQAABAADAAAAAAAAACgAAgEACwADCQ==", "recv_time": 9906446269, "acceleration": 2, "uptime": 3, "sender": 26427, "cn0": 184, "doppler_std": 4, "tow_flags": 0, "tot": {"wn": 0, "tow": 0}, "crc": 52930, "length": 55, "clock_drift": 0, "sid": {"code": 0, "reserved": 0, "sat": 15}, "sync_flags": 1, "corr_spacing": 40}"#.as_bytes();

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
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 64,
                    "incorrect value for l.f, expected 64, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 3275,
                    "incorrect value for l.i, expected 3275, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_tracking_msg_tracking_state_detailed_dep() {
    {
        let mut payload = Cursor::new(vec![
            85, 17, 0, 59, 103, 55, 163, 151, 112, 215, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 39, 5, 0, 0, 169, 177, 208, 54, 15, 0, 0, 0, 85, 61, 0, 0, 39, 0, 1, 0, 0, 0, 0,
            0, 0, 0, 40, 0, 108, 1, 0, 11, 0, 0, 9, 166, 214,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingStateDetailedDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 169,
                    "incorrect value for l.f, expected 169, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 1319,
                    "incorrect value for l.i, expected 1319, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 17, 0, 59, 103, 55, 97, 251, 61, 245, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 18, 7, 0, 0, 14, 175, 208, 54, 15, 0, 0, 0, 51, 61, 0, 0, 30, 0, 1, 0, 0, 0, 0, 0,
            0, 0, 40, 0, 224, 1, 0, 11, 0, 0, 9, 136, 179,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingStateDetailedDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 14,
                    "incorrect value for l.f, expected 14, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 1810,
                    "incorrect value for l.i, expected 1810, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 17, 0, 59, 103, 55, 139, 218, 236, 18, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 250, 8, 0, 0, 8, 179, 208, 54, 15, 0, 0, 0, 67, 61, 0, 0, 22, 0, 2, 0, 0, 0, 0, 0,
            0, 0, 40, 0, 27, 1, 0, 11, 0, 2, 9, 217, 159,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingStateDetailedDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 8,
                    "incorrect value for l.f, expected 8, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 2298,
                    "incorrect value for l.i, expected 2298, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 17, 0, 59, 103, 55, 255, 251, 170, 48, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 226, 10, 0, 0, 125, 181, 208, 54, 15, 0, 0, 0, 29, 61, 0, 0, 10, 0, 2, 0, 0, 0, 0,
            0, 0, 0, 40, 0, 220, 1, 0, 11, 0, 3, 9, 66, 95,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingStateDetailedDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 125,
                    "incorrect value for l.f, expected 125, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 2786,
                    "incorrect value for l.i, expected 2786, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 17, 0, 59, 103, 55, 189, 95, 120, 78, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 203, 12, 0, 0, 64, 184, 208, 54, 15, 0, 0, 0, 24, 61, 0, 0, 4, 0, 3, 0, 0, 0, 0, 0,
            0, 0, 40, 0, 2, 1, 0, 11, 0, 3, 9, 194, 206,
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
        let sbp_msg = sbp::messages::Sbp::MsgTrackingStateDetailedDep(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgTrackingStateDetailedDep(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x11,
                    "Incorrect message type, expected 0x11, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x673b,
                    "incorrect sender id, expected 0x673b, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.l.f, 64,
                    "incorrect value for l.f, expected 64, is {}",
                    msg.l.f
                );
                assert_eq!(
                    msg.l.i, 3275,
                    "incorrect value for l.i, expected 3275, is {}",
                    msg.l.i
                );
                assert_eq!(msg.p, 0, "incorrect value for p, expected 0, is {}", msg.p);
                assert_eq!(
                    msg.p_std, 0,
                    "incorrect value for p_std, expected 0, is {}",
                    msg.p_std
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

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
