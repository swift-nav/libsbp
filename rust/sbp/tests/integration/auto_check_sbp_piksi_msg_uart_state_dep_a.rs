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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartStateDepA.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_piksi_msg_uart_state_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 195, 4, 58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 154, 153, 57, 65, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 255, 255, 255,
            255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 247, 5,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 0,
                    "incorrect value for uart_b.tx_buffer_level, expected 0, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 15,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 15, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 1.16000003814697266e+01 ), "incorrect value for uart_ftdi.tx_throughput, expected 1.16000003814697266e+01, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 195, 4, 58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 2, 43, 135, 61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255,
            0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 65, 110,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 0,
                    "incorrect value for uart_b.tx_buffer_level, expected 0, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 0,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 6.59999996423721313e-02 ), "incorrect value for uart_ftdi.tx_throughput, expected 6.59999996423721313e-02, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 195, 4, 58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 4, 86, 14, 62, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 255, 255, 255, 255,
            0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 198, 36,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 0,
                    "incorrect value for uart_b.tx_buffer_level, expected 0, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 10,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 10, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 1.38999998569488525e-01 ), "incorrect value for uart_ftdi.tx_throughput, expected 1.38999998569488525e-01, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 195, 4, 58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 2, 43, 135, 61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255,
            0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 65, 110,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 0,
                    "incorrect value for uart_b.tx_buffer_level, expected 0, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 0,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 6.59999996423721313e-02 ), "incorrect value for uart_ftdi.tx_throughput, expected 6.59999996423721313e-02, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 195, 4, 58, 0, 0, 0, 0, 138, 75, 6, 60, 0, 0, 0, 0, 0, 0, 80, 113, 201, 61,
            0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 145, 237, 252, 62, 0, 0, 0, 0, 0, 0, 0, 0, 38, 0, 255,
            255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 112, 111,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 8.19672085344791412e-03 ), "incorrect value for uart_a.rx_throughput, expected 8.19672085344791412e-03, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 2,
                    "incorrect value for uart_b.tx_buffer_level, expected 2, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 9.83606576919555664e-02 ), "incorrect value for uart_b.tx_throughput, expected 9.83606576919555664e-02, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 38,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 38, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 4.93999987840652466e-01 ), "incorrect value for uart_ftdi.tx_throughput, expected 4.93999987840652466e-01, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 195, 4, 58, 166, 155, 68, 60, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 166, 155, 68,
            60, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 236, 81, 168, 63, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 255,
            255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 22, 72,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 2,
                    "incorrect value for uart_a.tx_buffer_level, expected 2, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 1.20000001043081284e-02 ), "incorrect value for uart_a.tx_throughput, expected 1.20000001043081284e-02, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 2,
                    "incorrect value for uart_b.tx_buffer_level, expected 2, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 1.20000001043081284e-02 ), "incorrect value for uart_b.tx_throughput, expected 1.20000001043081284e-02, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 50,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 50, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 1.31500005722045898e+00 ), "incorrect value for uart_ftdi.tx_throughput, expected 1.31500005722045898e+00, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
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
fn test_json2sbp_auto_check_sbp_piksi_msg_uart_state_dep_a() {
    {
        let json_input = r#"{"latency": {"current": -1, "lmax": 0, "avg": -1, "lmin": 0}, "sender": 1219, "msg_type": 24, "crc": 1527, "length": 58, "uart_b": {"rx_buffer_level": 0, "tx_buffer_level": 0, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.0}, "uart_a": {"rx_buffer_level": 0, "tx_buffer_level": 0, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.0}, "preamble": 85, "payload": "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAJqZOUEAAAAAAAAAAA8A/////wAAAAAAAAAA/////w==", "uart_ftdi": {"rx_buffer_level": 0, "tx_buffer_level": 15, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 11.600000381469727}}"#.as_bytes();

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
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 0,
                    "incorrect value for uart_b.tx_buffer_level, expected 0, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 15,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 15, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 1.16000003814697266e+01 ), "incorrect value for uart_ftdi.tx_throughput, expected 1.16000003814697266e+01, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
    }
    {
        let json_input = r#"{"latency": {"current": -1, "lmax": 0, "avg": -1, "lmin": 0}, "sender": 1219, "msg_type": 24, "crc": 28225, "length": 58, "uart_b": {"rx_buffer_level": 0, "tx_buffer_level": 0, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.0}, "uart_a": {"rx_buffer_level": 0, "tx_buffer_level": 0, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.0}, "preamble": 85, "payload": "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////w==", "uart_ftdi": {"rx_buffer_level": 0, "tx_buffer_level": 0, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.06599999964237213}}"#.as_bytes();

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
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 0,
                    "incorrect value for uart_b.tx_buffer_level, expected 0, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 0,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 6.59999996423721313e-02 ), "incorrect value for uart_ftdi.tx_throughput, expected 6.59999996423721313e-02, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
    }
    {
        let json_input = r#"{"latency": {"current": -1, "lmax": 0, "avg": -1, "lmin": 0}, "sender": 1219, "msg_type": 24, "crc": 9414, "length": 58, "uart_b": {"rx_buffer_level": 0, "tx_buffer_level": 0, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.0}, "uart_a": {"rx_buffer_level": 0, "tx_buffer_level": 0, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.0}, "preamble": 85, "payload": "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAARWDj4AAAAAAAAAAAoA/////wAAAAAAAAAA/////w==", "uart_ftdi": {"rx_buffer_level": 0, "tx_buffer_level": 10, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.13899999856948853}}"#.as_bytes();

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
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 0,
                    "incorrect value for uart_b.tx_buffer_level, expected 0, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 10,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 10, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 1.38999998569488525e-01 ), "incorrect value for uart_ftdi.tx_throughput, expected 1.38999998569488525e-01, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
    }
    {
        let json_input = r#"{"latency": {"current": -1, "lmax": 0, "avg": -1, "lmin": 0}, "sender": 1219, "msg_type": 24, "crc": 28225, "length": 58, "uart_b": {"rx_buffer_level": 0, "tx_buffer_level": 0, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.0}, "uart_a": {"rx_buffer_level": 0, "tx_buffer_level": 0, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.0}, "preamble": 85, "payload": "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////w==", "uart_ftdi": {"rx_buffer_level": 0, "tx_buffer_level": 0, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.06599999964237213}}"#.as_bytes();

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
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 0,
                    "incorrect value for uart_b.tx_buffer_level, expected 0, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 0,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 6.59999996423721313e-02 ), "incorrect value for uart_ftdi.tx_throughput, expected 6.59999996423721313e-02, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
    }
    {
        let json_input = r#"{"latency": {"current": -1, "lmax": 0, "avg": -1, "lmin": 0}, "sender": 1219, "msg_type": 24, "crc": 28528, "length": 58, "uart_b": {"rx_buffer_level": 0, "tx_buffer_level": 2, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.09836065769195557}, "uart_a": {"rx_buffer_level": 0, "tx_buffer_level": 0, "rx_throughput": 0.008196720853447914, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.0}, "preamble": 85, "payload": "AAAAAIpLBjwAAAAAAABQcck9AAAAAAAAAAACAJHt/D4AAAAAAAAAACYA/////wAAAAAAAAAA/////w==", "uart_ftdi": {"rx_buffer_level": 0, "tx_buffer_level": 38, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.49399998784065247}}"#.as_bytes();

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
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 8.19672085344791412e-03 ), "incorrect value for uart_a.rx_throughput, expected 8.19672085344791412e-03, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 2,
                    "incorrect value for uart_b.tx_buffer_level, expected 2, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 9.83606576919555664e-02 ), "incorrect value for uart_b.tx_throughput, expected 9.83606576919555664e-02, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 38,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 38, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 4.93999987840652466e-01 ), "incorrect value for uart_ftdi.tx_throughput, expected 4.93999987840652466e-01, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
    }
    {
        let json_input = r#"{"latency": {"current": -1, "lmax": 0, "avg": -1, "lmin": 0}, "sender": 1219, "msg_type": 24, "crc": 18454, "length": 58, "uart_b": {"rx_buffer_level": 0, "tx_buffer_level": 2, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.012000000104308128}, "uart_a": {"rx_buffer_level": 0, "tx_buffer_level": 2, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.012000000104308128}, "preamble": 85, "payload": "pptEPAAAAAAAAAAAAgCmm0Q8AAAAAAAAAAACAOxRqD8AAAAAAAAAADIA/////wAAAAAAAAAA/////w==", "uart_ftdi": {"rx_buffer_level": 0, "tx_buffer_level": 50, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 1.315000057220459}}"#.as_bytes();

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
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 2,
                    "incorrect value for uart_a.tx_buffer_level, expected 2, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 1.20000001043081284e-02 ), "incorrect value for uart_a.tx_throughput, expected 1.20000001043081284e-02, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 2,
                    "incorrect value for uart_b.tx_buffer_level, expected 2, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 1.20000001043081284e-02 ), "incorrect value for uart_b.tx_throughput, expected 1.20000001043081284e-02, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 50,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 50, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 1.31500005722045898e+00 ), "incorrect value for uart_ftdi.tx_throughput, expected 1.31500005722045898e+00, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_piksi_msg_uart_state_dep_a`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_piksi_msg_uart_state_dep_a() {
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 195, 4, 58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 154, 153, 57, 65, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 255, 255, 255,
            255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 247, 5,
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
        let sbp_msg = sbp::messages::Sbp::MsgUartStateDepa(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 0,
                    "incorrect value for uart_b.tx_buffer_level, expected 0, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 15,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 15, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 1.16000003814697266e+01 ), "incorrect value for uart_ftdi.tx_throughput, expected 1.16000003814697266e+01, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 195, 4, 58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 2, 43, 135, 61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255,
            0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 65, 110,
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
        let sbp_msg = sbp::messages::Sbp::MsgUartStateDepa(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 0,
                    "incorrect value for uart_b.tx_buffer_level, expected 0, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 0,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 6.59999996423721313e-02 ), "incorrect value for uart_ftdi.tx_throughput, expected 6.59999996423721313e-02, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 195, 4, 58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 4, 86, 14, 62, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 255, 255, 255, 255,
            0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 198, 36,
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
        let sbp_msg = sbp::messages::Sbp::MsgUartStateDepa(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 0,
                    "incorrect value for uart_b.tx_buffer_level, expected 0, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 10,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 10, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 1.38999998569488525e-01 ), "incorrect value for uart_ftdi.tx_throughput, expected 1.38999998569488525e-01, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 195, 4, 58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 2, 43, 135, 61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255,
            0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 65, 110,
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
        let sbp_msg = sbp::messages::Sbp::MsgUartStateDepa(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 0,
                    "incorrect value for uart_b.tx_buffer_level, expected 0, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 0,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 6.59999996423721313e-02 ), "incorrect value for uart_ftdi.tx_throughput, expected 6.59999996423721313e-02, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 195, 4, 58, 0, 0, 0, 0, 138, 75, 6, 60, 0, 0, 0, 0, 0, 0, 80, 113, 201, 61,
            0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 145, 237, 252, 62, 0, 0, 0, 0, 0, 0, 0, 0, 38, 0, 255,
            255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 112, 111,
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
        let sbp_msg = sbp::messages::Sbp::MsgUartStateDepa(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 8.19672085344791412e-03 ), "incorrect value for uart_a.rx_throughput, expected 8.19672085344791412e-03, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 0,
                    "incorrect value for uart_a.tx_buffer_level, expected 0, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.tx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 2,
                    "incorrect value for uart_b.tx_buffer_level, expected 2, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 9.83606576919555664e-02 ), "incorrect value for uart_b.tx_throughput, expected 9.83606576919555664e-02, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 38,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 38, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 4.93999987840652466e-01 ), "incorrect value for uart_ftdi.tx_throughput, expected 4.93999987840652466e-01, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 195, 4, 58, 166, 155, 68, 60, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 166, 155, 68,
            60, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 236, 81, 168, 63, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 255,
            255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 22, 72,
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
        let sbp_msg = sbp::messages::Sbp::MsgUartStateDepa(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x4c3,
                    "incorrect sender id, expected 0x4c3, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.latency.avg, -1,
                    "incorrect value for latency.avg, expected -1, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, -1,
                    "incorrect value for latency.current, expected -1, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, 0,
                    "incorrect value for latency.lmax, expected 0, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 0,
                    "incorrect value for latency.lmin, expected 0, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 0,
                    "incorrect value for uart_a.crc_error_count, expected 0, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 0,
                    "incorrect value for uart_a.io_error_count, expected 0, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 0,
                    "incorrect value for uart_a.rx_buffer_level, expected 0, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_a.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 2,
                    "incorrect value for uart_a.tx_buffer_level, expected 2, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 1.20000001043081284e-02 ), "incorrect value for uart_a.tx_throughput, expected 1.20000001043081284e-02, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 0,
                    "incorrect value for uart_b.crc_error_count, expected 0, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 0,
                    "incorrect value for uart_b.io_error_count, expected 0, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 0,
                    "incorrect value for uart_b.rx_buffer_level, expected 0, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_b.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 2,
                    "incorrect value for uart_b.tx_buffer_level, expected 2, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 1.20000001043081284e-02 ), "incorrect value for uart_b.tx_throughput, expected 1.20000001043081284e-02, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 0,
                    "incorrect value for uart_ftdi.crc_error_count, expected 0, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 0,
                    "incorrect value for uart_ftdi.io_error_count, expected 0, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 0,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 0.00000000000000000e+00 ), "incorrect value for uart_ftdi.rx_throughput, expected 0.00000000000000000e+00, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 50,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 50, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 1.31500005722045898e+00 ), "incorrect value for uart_ftdi.tx_throughput, expected 1.31500005722045898e+00, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
