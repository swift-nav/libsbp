#!/usr/bin/perl -w
#
# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartState.yaml
# with generate.py.  Do not modify by hand!

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";

BEGIN {
    # add SBP_PATH to include path and load all modules
    unshift @INC, &SBP_PATH;
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_piksi_msg_uart_state_1() {
    my $buf = decode_base64("VRgA9tc6Gr9dPwAAAAAAAAAAGAB7Mj5AAAAAAAAAAAAoADYHokCxORA9AAAAAFEB/////wAAAAAAAAAA/////0d8");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x7c47, "crc");
    
    is($msg->{'length'}, 58, "length");
    
    is($msg->{'msg_type'}, 0x18, "msg_type");
    
    is($msg->{'payload'}, "Gr9dPwAAAAAAAAAAGAB7Mj5AAAAAAAAAAAAoADYHokCxORA9AAAAAFEB/////wAAAAAAAAAA/////w==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->latency()), $json->encode($json->decode(q{{"avg":-1,"current":-1,"lmax":0,"lmin":0}})), "latency");
    
    is($json->encode($msg->uart_a()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":24,"tx_throughput":0.8661972284317017}})), "uart_a");
    
    is($json->encode($msg->uart_b()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":40,"tx_throughput":2.9718310832977295}})), "uart_b");
    
    is($json->encode($msg->uart_ftdi()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":1,"rx_throughput":0.035211268812417984,"tx_buffer_level":81,"tx_throughput":5.063380241394043}})), "uart_ftdi");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":31815,"latency":{"avg":-1,"current":-1,"lmax":0,"lmin":0},"length":58,"msg_type":24,"payload":"Gr9dPwAAAAAAAAAAGAB7Mj5AAAAAAAAAAAAoADYHokCxORA9AAAAAFEB/////wAAAAAAAAAA/////w==","preamble":85,"sender":55286,"uart_a":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":24,"tx_throughput":0.8661972284317017},"uart_b":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":40,"tx_throughput":2.9718310832977295},"uart_ftdi":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":1,"rx_throughput":0.035211268812417984,"tx_buffer_level":81,"tx_throughput":5.063380241394043}}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_uart_state_2() {
    my $buf = decode_base64("VRgA9tc67ehfPwAAAAAAAAAAGADGuj9AAAAAAAAAAAAoANZI2UAdSLQ+AAAAAFUB/////wAAAAAAAAAA/////5n4");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf899, "crc");
    
    is($msg->{'length'}, 58, "length");
    
    is($msg->{'msg_type'}, 0x18, "msg_type");
    
    is($msg->{'payload'}, "7ehfPwAAAAAAAAAAGADGuj9AAAAAAAAAAAAoANZI2UAdSLQ+AAAAAFUB/////wAAAAAAAAAA/////w==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->latency()), $json->encode($json->decode(q{{"avg":-1,"current":-1,"lmax":0,"lmin":0}})), "latency");
    
    is($json->encode($msg->uart_a()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":24,"tx_throughput":0.8746479153633118}})), "uart_a");
    
    is($json->encode($msg->uart_b()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":40,"tx_throughput":2.995774745941162}})), "uart_b");
    
    is($json->encode($msg->uart_ftdi()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":1,"rx_throughput":0.35211268067359924,"tx_buffer_level":85,"tx_throughput":6.7901411056518555}})), "uart_ftdi");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":63641,"latency":{"avg":-1,"current":-1,"lmax":0,"lmin":0},"length":58,"msg_type":24,"payload":"7ehfPwAAAAAAAAAAGADGuj9AAAAAAAAAAAAoANZI2UAdSLQ+AAAAAFUB/////wAAAAAAAAAA/////w==","preamble":85,"sender":55286,"uart_a":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":24,"tx_throughput":0.8746479153633118},"uart_b":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":40,"tx_throughput":2.995774745941162},"uart_ftdi":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":1,"rx_throughput":0.35211268067359924,"tx_buffer_level":85,"tx_throughput":6.7901411056518555}}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_uart_state_1();
test_auto_check_sbp_piksi_msg_uart_state_2();

done_testing();