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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartState.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_piksi_msg_uart_state() {
    {
        let mut payload = Cursor::new(vec![
            85, 29, 0, 200, 224, 74, 154, 169, 242, 69, 102, 166, 231, 68, 89, 98, 79, 184, 138,
            244, 154, 73, 201, 69, 154, 65, 211, 69, 201, 16, 103, 249, 143, 161, 154, 17, 186, 69,
            51, 211, 7, 69, 215, 149, 253, 25, 218, 24, 29, 195, 16, 19, 159, 142, 71, 17, 10, 113,
            137, 219, 135, 18, 182, 21, 38, 190, 59, 196, 169, 155, 107, 111, 253, 168, 244, 158,
            112, 19, 251, 131, 100, 225,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartState(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x1d,
                    "Incorrect message type, expected 0x1d, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xe0c8,
                    "incorrect sender id, expected 0xe0c8, is {sender_id}"
                );
                assert_eq!(
                    msg.latency.avg, 319865629,
                    "incorrect value for latency.avg, expected 319865629, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, 364253831,
                    "incorrect value for latency.current, expected 364253831, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, -611749622,
                    "incorrect value for latency.lmax, expected -611749622, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 289902239,
                    "incorrect value for latency.lmin, expected 289902239, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.obs_period.avg, -1002717658,
                    "incorrect value for obs_period.avg, expected -1002717658, is {}",
                    msg.obs_period.avg
                );
                assert_eq!(
                    msg.obs_period.current, -2080697488,
                    "incorrect value for obs_period.current, expected -2080697488, is {}",
                    msg.obs_period.current
                );
                assert_eq!(
                    msg.obs_period.pmax, -1628133123,
                    "incorrect value for obs_period.pmax, expected -1628133123, is {}",
                    msg.obs_period.pmax
                );
                assert_eq!(
                    msg.obs_period.pmin, 1869323177,
                    "incorrect value for obs_period.pmin, expected 1869323177, is {}",
                    msg.obs_period.pmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 25177,
                    "incorrect value for uart_a.crc_error_count, expected 25177, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 47183,
                    "incorrect value for uart_a.io_error_count, expected 47183, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 244,
                    "incorrect value for uart_a.rx_buffer_level, expected 244, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 1.85319995117187500e+03 ), "incorrect value for uart_a.rx_throughput, expected 1.85319995117187500e+03, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 138,
                    "incorrect value for uart_a.tx_buffer_level, expected 138, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 7.76520019531250000e+03 ), "incorrect value for uart_a.tx_throughput, expected 7.76520019531250000e+03, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 4297,
                    "incorrect value for uart_b.crc_error_count, expected 4297, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 63847,
                    "incorrect value for uart_b.io_error_count, expected 63847, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 161,
                    "incorrect value for uart_b.rx_buffer_level, expected 161, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 6.76020019531250000e+03 ), "incorrect value for uart_b.rx_throughput, expected 6.76020019531250000e+03, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 143,
                    "incorrect value for uart_b.tx_buffer_level, expected 143, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 6.44120019531250000e+03 ), "incorrect value for uart_b.tx_throughput, expected 6.44120019531250000e+03, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 38359,
                    "incorrect value for uart_ftdi.crc_error_count, expected 38359, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 6653,
                    "incorrect value for uart_ftdi.io_error_count, expected 6653, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 24,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 24, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 2.17319995117187500e+03 ), "incorrect value for uart_ftdi.rx_throughput, expected 2.17319995117187500e+03, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 218,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 218, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 5.95420019531250000e+03 ), "incorrect value for uart_ftdi.tx_throughput, expected 5.95420019531250000e+03, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartState"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 246, 215, 58, 26, 191, 93, 63, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 123, 50, 62,
            64, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 54, 7, 162, 64, 177, 57, 16, 61, 0, 0, 0, 0, 81, 1,
            255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 71, 124,
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
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x18,
                    "Incorrect message type, expected 0x18, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
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
                    msg.uart_a.tx_buffer_level, 24,
                    "incorrect value for uart_a.tx_buffer_level, expected 24, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 8.66197228431701660e-01 ), "incorrect value for uart_a.tx_throughput, expected 8.66197228431701660e-01, is {:e}", msg.uart_a.tx_throughput);
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
                    msg.uart_b.tx_buffer_level, 40,
                    "incorrect value for uart_b.tx_buffer_level, expected 40, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 2.97183108329772949e+00 ), "incorrect value for uart_b.tx_throughput, expected 2.97183108329772949e+00, is {:e}", msg.uart_b.tx_throughput);
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
                    msg.uart_ftdi.rx_buffer_level, 1,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 3.52112688124179840e-02 ), "incorrect value for uart_ftdi.rx_throughput, expected 3.52112688124179840e-02, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 81,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 81, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 5.06338024139404297e+00 ), "incorrect value for uart_ftdi.tx_throughput, expected 5.06338024139404297e+00, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 246, 215, 58, 237, 232, 95, 63, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 198, 186, 63,
            64, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 214, 72, 217, 64, 29, 72, 180, 62, 0, 0, 0, 0, 85,
            1, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 153, 248,
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
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x18,
                    "Incorrect message type, expected 0x18, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
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
                    msg.uart_a.tx_buffer_level, 24,
                    "incorrect value for uart_a.tx_buffer_level, expected 24, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 8.74647915363311768e-01 ), "incorrect value for uart_a.tx_throughput, expected 8.74647915363311768e-01, is {:e}", msg.uart_a.tx_throughput);
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
                    msg.uart_b.tx_buffer_level, 40,
                    "incorrect value for uart_b.tx_buffer_level, expected 40, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 2.99577474594116211e+00 ), "incorrect value for uart_b.tx_throughput, expected 2.99577474594116211e+00, is {:e}", msg.uart_b.tx_throughput);
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
                    msg.uart_ftdi.rx_buffer_level, 1,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 3.52112680673599243e-01 ), "incorrect value for uart_ftdi.rx_throughput, expected 3.52112680673599243e-01, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 85,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 85, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 6.79014110565185547e+00 ), "incorrect value for uart_ftdi.tx_throughput, expected 6.79014110565185547e+00, is {:e}", msg.uart_ftdi.tx_throughput);
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
fn test_json2sbp_auto_check_sbp_piksi_msg_uart_state() {
    {
        let json_input = r#"{"preamble":85,"msg_type":29,"sender":57544,"length":74,"payload":"mqnyRWam50RZYk+4ivSaSclFmkHTRckQZ/mPoZoRukUz0wdF15X9GdoYHcMQE5+ORxEKcYnbhxK2FSa+O8Spm2tv/aj0nnAT+4M=","crc":57700,"uart_a":{"tx_throughput":7765.2001953125,"rx_throughput":1853.199951171875,"crc_error_count":25177,"io_error_count":47183,"tx_buffer_level":138,"rx_buffer_level":244},"uart_b":{"tx_throughput":6441.2001953125,"rx_throughput":6760.2001953125,"crc_error_count":4297,"io_error_count":63847,"tx_buffer_level":143,"rx_buffer_level":161},"uart_ftdi":{"tx_throughput":5954.2001953125,"rx_throughput":2173.199951171875,"crc_error_count":38359,"io_error_count":6653,"tx_buffer_level":218,"rx_buffer_level":24},"latency":{"avg":319865629,"lmin":289902239,"lmax":-611749622,"current":364253831},"obs_period":{"avg":-1002717658,"pmin":1869323177,"pmax":-1628133123,"current":-2080697488}}"#.as_bytes();

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
            sbp::messages::Sbp::MsgUartState(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x1d,
                    "Incorrect message type, expected 0x1d, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xe0c8,
                    "incorrect sender id, expected 0xe0c8, is {sender_id}"
                );
                assert_eq!(
                    msg.latency.avg, 319865629,
                    "incorrect value for latency.avg, expected 319865629, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, 364253831,
                    "incorrect value for latency.current, expected 364253831, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, -611749622,
                    "incorrect value for latency.lmax, expected -611749622, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 289902239,
                    "incorrect value for latency.lmin, expected 289902239, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.obs_period.avg, -1002717658,
                    "incorrect value for obs_period.avg, expected -1002717658, is {}",
                    msg.obs_period.avg
                );
                assert_eq!(
                    msg.obs_period.current, -2080697488,
                    "incorrect value for obs_period.current, expected -2080697488, is {}",
                    msg.obs_period.current
                );
                assert_eq!(
                    msg.obs_period.pmax, -1628133123,
                    "incorrect value for obs_period.pmax, expected -1628133123, is {}",
                    msg.obs_period.pmax
                );
                assert_eq!(
                    msg.obs_period.pmin, 1869323177,
                    "incorrect value for obs_period.pmin, expected 1869323177, is {}",
                    msg.obs_period.pmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 25177,
                    "incorrect value for uart_a.crc_error_count, expected 25177, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 47183,
                    "incorrect value for uart_a.io_error_count, expected 47183, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 244,
                    "incorrect value for uart_a.rx_buffer_level, expected 244, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 1.85319995117187500e+03 ), "incorrect value for uart_a.rx_throughput, expected 1.85319995117187500e+03, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 138,
                    "incorrect value for uart_a.tx_buffer_level, expected 138, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 7.76520019531250000e+03 ), "incorrect value for uart_a.tx_throughput, expected 7.76520019531250000e+03, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 4297,
                    "incorrect value for uart_b.crc_error_count, expected 4297, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 63847,
                    "incorrect value for uart_b.io_error_count, expected 63847, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 161,
                    "incorrect value for uart_b.rx_buffer_level, expected 161, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 6.76020019531250000e+03 ), "incorrect value for uart_b.rx_throughput, expected 6.76020019531250000e+03, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 143,
                    "incorrect value for uart_b.tx_buffer_level, expected 143, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 6.44120019531250000e+03 ), "incorrect value for uart_b.tx_throughput, expected 6.44120019531250000e+03, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 38359,
                    "incorrect value for uart_ftdi.crc_error_count, expected 38359, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 6653,
                    "incorrect value for uart_ftdi.io_error_count, expected 6653, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 24,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 24, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 2.17319995117187500e+03 ), "incorrect value for uart_ftdi.rx_throughput, expected 2.17319995117187500e+03, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 218,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 218, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 5.95420019531250000e+03 ), "incorrect value for uart_ftdi.tx_throughput, expected 5.95420019531250000e+03, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartState"),
        };
    }
    {
        let json_input = r#"{"latency": {"current": -1, "lmax": 0, "avg": -1, "lmin": 0}, "sender": 55286, "msg_type": 24, "crc": 31815, "length": 58, "uart_b": {"rx_buffer_level": 0, "tx_buffer_level": 40, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 2.9718310832977295}, "uart_a": {"rx_buffer_level": 0, "tx_buffer_level": 24, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.8661972284317017}, "preamble": 85, "payload": "Gr9dPwAAAAAAAAAAGAB7Mj5AAAAAAAAAAAAoADYHokCxORA9AAAAAFEB/////wAAAAAAAAAA/////w==", "uart_ftdi": {"rx_buffer_level": 1, "tx_buffer_level": 81, "rx_throughput": 0.035211268812417984, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 5.063380241394043}}"#.as_bytes();

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
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
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
                    msg.uart_a.tx_buffer_level, 24,
                    "incorrect value for uart_a.tx_buffer_level, expected 24, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 8.66197228431701660e-01 ), "incorrect value for uart_a.tx_throughput, expected 8.66197228431701660e-01, is {:e}", msg.uart_a.tx_throughput);
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
                    msg.uart_b.tx_buffer_level, 40,
                    "incorrect value for uart_b.tx_buffer_level, expected 40, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 2.97183108329772949e+00 ), "incorrect value for uart_b.tx_throughput, expected 2.97183108329772949e+00, is {:e}", msg.uart_b.tx_throughput);
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
                    msg.uart_ftdi.rx_buffer_level, 1,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 3.52112688124179840e-02 ), "incorrect value for uart_ftdi.rx_throughput, expected 3.52112688124179840e-02, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 81,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 81, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 5.06338024139404297e+00 ), "incorrect value for uart_ftdi.tx_throughput, expected 5.06338024139404297e+00, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
    }
    {
        let json_input = r#"{"latency": {"current": -1, "lmax": 0, "avg": -1, "lmin": 0}, "sender": 55286, "msg_type": 24, "crc": 63641, "length": 58, "uart_b": {"rx_buffer_level": 0, "tx_buffer_level": 40, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 2.995774745941162}, "uart_a": {"rx_buffer_level": 0, "tx_buffer_level": 24, "rx_throughput": 0.0, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 0.8746479153633118}, "preamble": 85, "payload": "7ehfPwAAAAAAAAAAGADGuj9AAAAAAAAAAAAoANZI2UAdSLQ+AAAAAFUB/////wAAAAAAAAAA/////w==", "uart_ftdi": {"rx_buffer_level": 1, "tx_buffer_level": 85, "rx_throughput": 0.35211268067359924, "crc_error_count": 0, "io_error_count": 0, "tx_throughput": 6.7901411056518555}}"#.as_bytes();

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
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
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
                    msg.uart_a.tx_buffer_level, 24,
                    "incorrect value for uart_a.tx_buffer_level, expected 24, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 8.74647915363311768e-01 ), "incorrect value for uart_a.tx_throughput, expected 8.74647915363311768e-01, is {:e}", msg.uart_a.tx_throughput);
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
                    msg.uart_b.tx_buffer_level, 40,
                    "incorrect value for uart_b.tx_buffer_level, expected 40, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 2.99577474594116211e+00 ), "incorrect value for uart_b.tx_throughput, expected 2.99577474594116211e+00, is {:e}", msg.uart_b.tx_throughput);
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
                    msg.uart_ftdi.rx_buffer_level, 1,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 3.52112680673599243e-01 ), "incorrect value for uart_ftdi.rx_throughput, expected 3.52112680673599243e-01, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 85,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 85, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 6.79014110565185547e+00 ), "incorrect value for uart_ftdi.tx_throughput, expected 6.79014110565185547e+00, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_piksi_msg_uart_state`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_piksi_msg_uart_state() {
    {
        let mut payload = Cursor::new(vec![
            85, 29, 0, 200, 224, 74, 154, 169, 242, 69, 102, 166, 231, 68, 89, 98, 79, 184, 138,
            244, 154, 73, 201, 69, 154, 65, 211, 69, 201, 16, 103, 249, 143, 161, 154, 17, 186, 69,
            51, 211, 7, 69, 215, 149, 253, 25, 218, 24, 29, 195, 16, 19, 159, 142, 71, 17, 10, 113,
            137, 219, 135, 18, 182, 21, 38, 190, 59, 196, 169, 155, 107, 111, 253, 168, 244, 158,
            112, 19, 251, 131, 100, 225,
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
        let sbp_msg = sbp::messages::Sbp::MsgUartState(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgUartState(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x1d,
                    "Incorrect message type, expected 0x1d, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xe0c8,
                    "incorrect sender id, expected 0xe0c8, is {sender_id}"
                );
                assert_eq!(
                    msg.latency.avg, 319865629,
                    "incorrect value for latency.avg, expected 319865629, is {}",
                    msg.latency.avg
                );
                assert_eq!(
                    msg.latency.current, 364253831,
                    "incorrect value for latency.current, expected 364253831, is {}",
                    msg.latency.current
                );
                assert_eq!(
                    msg.latency.lmax, -611749622,
                    "incorrect value for latency.lmax, expected -611749622, is {}",
                    msg.latency.lmax
                );
                assert_eq!(
                    msg.latency.lmin, 289902239,
                    "incorrect value for latency.lmin, expected 289902239, is {}",
                    msg.latency.lmin
                );
                assert_eq!(
                    msg.obs_period.avg, -1002717658,
                    "incorrect value for obs_period.avg, expected -1002717658, is {}",
                    msg.obs_period.avg
                );
                assert_eq!(
                    msg.obs_period.current, -2080697488,
                    "incorrect value for obs_period.current, expected -2080697488, is {}",
                    msg.obs_period.current
                );
                assert_eq!(
                    msg.obs_period.pmax, -1628133123,
                    "incorrect value for obs_period.pmax, expected -1628133123, is {}",
                    msg.obs_period.pmax
                );
                assert_eq!(
                    msg.obs_period.pmin, 1869323177,
                    "incorrect value for obs_period.pmin, expected 1869323177, is {}",
                    msg.obs_period.pmin
                );
                assert_eq!(
                    msg.uart_a.crc_error_count, 25177,
                    "incorrect value for uart_a.crc_error_count, expected 25177, is {}",
                    msg.uart_a.crc_error_count
                );
                assert_eq!(
                    msg.uart_a.io_error_count, 47183,
                    "incorrect value for uart_a.io_error_count, expected 47183, is {}",
                    msg.uart_a.io_error_count
                );
                assert_eq!(
                    msg.uart_a.rx_buffer_level, 244,
                    "incorrect value for uart_a.rx_buffer_level, expected 244, is {}",
                    msg.uart_a.rx_buffer_level
                );
                assert!(msg.uart_a.rx_throughput.almost_eq( 1.85319995117187500e+03 ), "incorrect value for uart_a.rx_throughput, expected 1.85319995117187500e+03, is {:e}", msg.uart_a.rx_throughput);
                assert_eq!(
                    msg.uart_a.tx_buffer_level, 138,
                    "incorrect value for uart_a.tx_buffer_level, expected 138, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 7.76520019531250000e+03 ), "incorrect value for uart_a.tx_throughput, expected 7.76520019531250000e+03, is {:e}", msg.uart_a.tx_throughput);
                assert_eq!(
                    msg.uart_b.crc_error_count, 4297,
                    "incorrect value for uart_b.crc_error_count, expected 4297, is {}",
                    msg.uart_b.crc_error_count
                );
                assert_eq!(
                    msg.uart_b.io_error_count, 63847,
                    "incorrect value for uart_b.io_error_count, expected 63847, is {}",
                    msg.uart_b.io_error_count
                );
                assert_eq!(
                    msg.uart_b.rx_buffer_level, 161,
                    "incorrect value for uart_b.rx_buffer_level, expected 161, is {}",
                    msg.uart_b.rx_buffer_level
                );
                assert!(msg.uart_b.rx_throughput.almost_eq( 6.76020019531250000e+03 ), "incorrect value for uart_b.rx_throughput, expected 6.76020019531250000e+03, is {:e}", msg.uart_b.rx_throughput);
                assert_eq!(
                    msg.uart_b.tx_buffer_level, 143,
                    "incorrect value for uart_b.tx_buffer_level, expected 143, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 6.44120019531250000e+03 ), "incorrect value for uart_b.tx_throughput, expected 6.44120019531250000e+03, is {:e}", msg.uart_b.tx_throughput);
                assert_eq!(
                    msg.uart_ftdi.crc_error_count, 38359,
                    "incorrect value for uart_ftdi.crc_error_count, expected 38359, is {}",
                    msg.uart_ftdi.crc_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.io_error_count, 6653,
                    "incorrect value for uart_ftdi.io_error_count, expected 6653, is {}",
                    msg.uart_ftdi.io_error_count
                );
                assert_eq!(
                    msg.uart_ftdi.rx_buffer_level, 24,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 24, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 2.17319995117187500e+03 ), "incorrect value for uart_ftdi.rx_throughput, expected 2.17319995117187500e+03, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 218,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 218, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 5.95420019531250000e+03 ), "incorrect value for uart_ftdi.tx_throughput, expected 5.95420019531250000e+03, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartState"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 246, 215, 58, 26, 191, 93, 63, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 123, 50, 62,
            64, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 54, 7, 162, 64, 177, 57, 16, 61, 0, 0, 0, 0, 81, 1,
            255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 71, 124,
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
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
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
                    msg.uart_a.tx_buffer_level, 24,
                    "incorrect value for uart_a.tx_buffer_level, expected 24, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 8.66197228431701660e-01 ), "incorrect value for uart_a.tx_throughput, expected 8.66197228431701660e-01, is {:e}", msg.uart_a.tx_throughput);
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
                    msg.uart_b.tx_buffer_level, 40,
                    "incorrect value for uart_b.tx_buffer_level, expected 40, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 2.97183108329772949e+00 ), "incorrect value for uart_b.tx_throughput, expected 2.97183108329772949e+00, is {:e}", msg.uart_b.tx_throughput);
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
                    msg.uart_ftdi.rx_buffer_level, 1,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 3.52112688124179840e-02 ), "incorrect value for uart_ftdi.rx_throughput, expected 3.52112688124179840e-02, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 81,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 81, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 5.06338024139404297e+00 ), "incorrect value for uart_ftdi.tx_throughput, expected 5.06338024139404297e+00, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    {
        let mut payload = Cursor::new(vec![
            85, 24, 0, 246, 215, 58, 237, 232, 95, 63, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 198, 186, 63,
            64, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 214, 72, 217, 64, 29, 72, 180, 62, 0, 0, 0, 0, 85,
            1, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 153, 248,
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
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {sender_id}"
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
                    msg.uart_a.tx_buffer_level, 24,
                    "incorrect value for uart_a.tx_buffer_level, expected 24, is {}",
                    msg.uart_a.tx_buffer_level
                );
                assert!(msg.uart_a.tx_throughput.almost_eq( 8.74647915363311768e-01 ), "incorrect value for uart_a.tx_throughput, expected 8.74647915363311768e-01, is {:e}", msg.uart_a.tx_throughput);
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
                    msg.uart_b.tx_buffer_level, 40,
                    "incorrect value for uart_b.tx_buffer_level, expected 40, is {}",
                    msg.uart_b.tx_buffer_level
                );
                assert!(msg.uart_b.tx_throughput.almost_eq( 2.99577474594116211e+00 ), "incorrect value for uart_b.tx_throughput, expected 2.99577474594116211e+00, is {:e}", msg.uart_b.tx_throughput);
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
                    msg.uart_ftdi.rx_buffer_level, 1,
                    "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is {}",
                    msg.uart_ftdi.rx_buffer_level
                );
                assert!(msg.uart_ftdi.rx_throughput.almost_eq( 3.52112680673599243e-01 ), "incorrect value for uart_ftdi.rx_throughput, expected 3.52112680673599243e-01, is {:e}", msg.uart_ftdi.rx_throughput);
                assert_eq!(
                    msg.uart_ftdi.tx_buffer_level, 85,
                    "incorrect value for uart_ftdi.tx_buffer_level, expected 85, is {}",
                    msg.uart_ftdi.tx_buffer_level
                );
                assert!(msg.uart_ftdi.tx_throughput.almost_eq( 6.79014110565185547e+00 ), "incorrect value for uart_ftdi.tx_throughput, expected 6.79014110565185547e+00, is {:e}", msg.uart_ftdi.tx_throughput);
            }
            _ => panic!("Invalid message type! Expected a MsgUartStateDepa"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
