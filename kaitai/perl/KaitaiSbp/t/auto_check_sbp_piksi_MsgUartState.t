#!/usr/bin/perl -w
#
# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartState.yaml
# with generate.py.  Do not modify by hand!

use strict;

BEGIN {
    # add grandparent directory to include path
    use Cwd qw(realpath);
    use File::Basename;
    unshift @INC, realpath(dirname($0))."/../../";
}

use KaitaiSbp::Sbp;
use KaitaiSbp::ParseUtils;
use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_piksi_msg_uart_state_1() {
    my $buf = decode_base64("VR0AyOBKmqnyRWam50RZYk+4ivSaSclFmkHTRckQZ/mPoZoRukUz0wdF15X9GdoYHcMQE5+ORxEKcYnbhxK2FSa+O8Spm2tv/aj0nnAT+4Nk4Q==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe164, "crc");
    
    is($msg->{'length'}, 74, "length");
    
    is($msg->{'msg_type'}, 0x1d, "msg_type");
    
    is($msg->{'payload'}, "mqnyRWam50RZYk+4ivSaSclFmkHTRckQZ/mPoZoRukUz0wdF15X9GdoYHcMQE5+ORxEKcYnbhxK2FSa+O8Spm2tv/aj0nnAT+4M=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xe0c8, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->latency()), $json->encode($json->decode(q{{"avg":319865629,"current":364253831,"lmax":-611749622,"lmin":289902239}})), "latency");
    
    is($json->encode($msg->obs_period()), $json->encode($json->decode(q{{"avg":-1002717658,"current":-2080697488,"pmax":-1628133123,"pmin":1869323177}})), "obs_period");
    
    is($json->encode($msg->uart_a()), $json->encode($json->decode(q{{"crc_error_count":25177,"io_error_count":47183,"rx_buffer_level":244,"rx_throughput":1853.199951171875,"tx_buffer_level":138,"tx_throughput":7765.2001953125}})), "uart_a");
    
    is($json->encode($msg->uart_b()), $json->encode($json->decode(q{{"crc_error_count":4297,"io_error_count":63847,"rx_buffer_level":161,"rx_throughput":6760.2001953125,"tx_buffer_level":143,"tx_throughput":6441.2001953125}})), "uart_b");
    
    is($json->encode($msg->uart_ftdi()), $json->encode($json->decode(q{{"crc_error_count":38359,"io_error_count":6653,"rx_buffer_level":24,"rx_throughput":2173.199951171875,"tx_buffer_level":218,"tx_throughput":5954.2001953125}})), "uart_ftdi");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":57700,"latency":{"avg":319865629,"current":364253831,"lmax":-611749622,"lmin":289902239},"length":74,"msg_type":29,"obs_period":{"avg":-1002717658,"current":-2080697488,"pmax":-1628133123,"pmin":1869323177},"payload":"mqnyRWam50RZYk+4ivSaSclFmkHTRckQZ/mPoZoRukUz0wdF15X9GdoYHcMQE5+ORxEKcYnbhxK2FSa+O8Spm2tv/aj0nnAT+4M=","preamble":85,"sender":57544,"uart_a":{"crc_error_count":25177,"io_error_count":47183,"rx_buffer_level":244,"rx_throughput":1853.199951171875,"tx_buffer_level":138,"tx_throughput":7765.2001953125},"uart_b":{"crc_error_count":4297,"io_error_count":63847,"rx_buffer_level":161,"rx_throughput":6760.2001953125,"tx_buffer_level":143,"tx_throughput":6441.2001953125},"uart_ftdi":{"crc_error_count":38359,"io_error_count":6653,"rx_buffer_level":24,"rx_throughput":2173.199951171875,"tx_buffer_level":218,"tx_throughput":5954.2001953125}}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_uart_state_2() {
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
sub test_auto_check_sbp_piksi_msg_uart_state_3() {
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
test_auto_check_sbp_piksi_msg_uart_state_3();

done_testing();