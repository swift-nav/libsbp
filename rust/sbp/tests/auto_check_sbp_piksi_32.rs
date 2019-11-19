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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartState.yaml by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

#[test]
fn test_auto_check_sbp_piksi_32() {
    {
        let payload: Vec<u8> = vec![
            85, 24, 0, 246, 215, 58, 26, 191, 93, 63, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 123, 50, 62,
            64, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 54, 7, 162, 64, 177, 57, 16, 61, 0, 0, 0, 0, 81, 1,
            255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 71, 124,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    {
        let payload: Vec<u8> = vec![
            85, 24, 0, 246, 215, 58, 237, 232, 95, 63, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 198, 186, 63,
            64, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 214, 72, 217, 64, 29, 72, 180, 62, 0, 0, 0, 0, 85,
            1, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 153, 248,
        ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::MsgUartStateDepa(msg) => {
                assert_eq!(
                    msg.get_message_type(),
                    0x18,
                    "Incorrect message type, expected 0x18, is {}",
                    msg.get_message_type()
                );
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(
                    sender_id, 0xd7f6,
                    "incorrect sender id, expected 0xd7f6, is {}",
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

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
}
