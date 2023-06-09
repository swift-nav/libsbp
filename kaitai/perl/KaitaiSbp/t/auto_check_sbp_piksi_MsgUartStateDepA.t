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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartStateDepA.yaml
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
sub test_auto_check_sbp_piksi_msg_uart_state_dep_a_1() {
    my $buf = decode_base64("VRgAwwQ6AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAJqZOUEAAAAAAAAAAA8A/////wAAAAAAAAAA//////cF");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5f7, "crc");
    
    is($msg->{'length'}, 58, "length");
    
    is($msg->{'msg_type'}, 0x18, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAJqZOUEAAAAAAAAAAA8A/////wAAAAAAAAAA/////w==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->latency()), $json->encode($json->decode(q{{"avg":-1,"current":-1,"lmax":0,"lmin":0}})), "latency");
    
    is($json->encode($msg->uart_a()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0}})), "uart_a");
    
    is($json->encode($msg->uart_b()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0}})), "uart_b");
    
    is($json->encode($msg->uart_ftdi()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":15,"tx_throughput":11.600000381469727}})), "uart_ftdi");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":1527,"latency":{"avg":-1,"current":-1,"lmax":0,"lmin":0},"length":58,"msg_type":24,"payload":"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAJqZOUEAAAAAAAAAAA8A/////wAAAAAAAAAA/////w==","preamble":85,"sender":1219,"uart_a":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0},"uart_b":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0},"uart_ftdi":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":15,"tx_throughput":11.600000381469727}}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_uart_state_dep_a_2() {
    my $buf = decode_base64("VRgAwwQ6AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////0Fu");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6e41, "crc");
    
    is($msg->{'length'}, 58, "length");
    
    is($msg->{'msg_type'}, 0x18, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////w==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->latency()), $json->encode($json->decode(q{{"avg":-1,"current":-1,"lmax":0,"lmin":0}})), "latency");
    
    is($json->encode($msg->uart_a()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0}})), "uart_a");
    
    is($json->encode($msg->uart_b()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0}})), "uart_b");
    
    is($json->encode($msg->uart_ftdi()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.06599999964237213}})), "uart_ftdi");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":28225,"latency":{"avg":-1,"current":-1,"lmax":0,"lmin":0},"length":58,"msg_type":24,"payload":"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////w==","preamble":85,"sender":1219,"uart_a":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0},"uart_b":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0},"uart_ftdi":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.06599999964237213}}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_uart_state_dep_a_3() {
    my $buf = decode_base64("VRgAwwQ6AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAARWDj4AAAAAAAAAAAoA/////wAAAAAAAAAA/////8Yk");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x24c6, "crc");
    
    is($msg->{'length'}, 58, "length");
    
    is($msg->{'msg_type'}, 0x18, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAARWDj4AAAAAAAAAAAoA/////wAAAAAAAAAA/////w==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->latency()), $json->encode($json->decode(q{{"avg":-1,"current":-1,"lmax":0,"lmin":0}})), "latency");
    
    is($json->encode($msg->uart_a()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0}})), "uart_a");
    
    is($json->encode($msg->uart_b()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0}})), "uart_b");
    
    is($json->encode($msg->uart_ftdi()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":10,"tx_throughput":0.13899999856948853}})), "uart_ftdi");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":9414,"latency":{"avg":-1,"current":-1,"lmax":0,"lmin":0},"length":58,"msg_type":24,"payload":"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAARWDj4AAAAAAAAAAAoA/////wAAAAAAAAAA/////w==","preamble":85,"sender":1219,"uart_a":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0},"uart_b":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0},"uart_ftdi":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":10,"tx_throughput":0.13899999856948853}}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_uart_state_dep_a_4() {
    my $buf = decode_base64("VRgAwwQ6AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////0Fu");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6e41, "crc");
    
    is($msg->{'length'}, 58, "length");
    
    is($msg->{'msg_type'}, 0x18, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////w==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->latency()), $json->encode($json->decode(q{{"avg":-1,"current":-1,"lmax":0,"lmin":0}})), "latency");
    
    is($json->encode($msg->uart_a()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0}})), "uart_a");
    
    is($json->encode($msg->uart_b()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0}})), "uart_b");
    
    is($json->encode($msg->uart_ftdi()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.06599999964237213}})), "uart_ftdi");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":28225,"latency":{"avg":-1,"current":-1,"lmax":0,"lmin":0},"length":58,"msg_type":24,"payload":"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIrhz0AAAAAAAAAAAAA/////wAAAAAAAAAA/////w==","preamble":85,"sender":1219,"uart_a":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0},"uart_b":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.0},"uart_ftdi":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":0,"tx_throughput":0.06599999964237213}}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_uart_state_dep_a_5() {
    my $buf = decode_base64("VRgAwwQ6AAAAAIpLBjwAAAAAAABQcck9AAAAAAAAAAACAJHt/D4AAAAAAAAAACYA/////wAAAAAAAAAA/////3Bv");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6f70, "crc");
    
    is($msg->{'length'}, 58, "length");
    
    is($msg->{'msg_type'}, 0x18, "msg_type");
    
    is($msg->{'payload'}, "AAAAAIpLBjwAAAAAAABQcck9AAAAAAAAAAACAJHt/D4AAAAAAAAAACYA/////wAAAAAAAAAA/////w==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->latency()), $json->encode($json->decode(q{{"avg":-1,"current":-1,"lmax":0,"lmin":0}})), "latency");
    
    is($json->encode($msg->uart_a()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.008196720853447914,"tx_buffer_level":0,"tx_throughput":0.0}})), "uart_a");
    
    is($json->encode($msg->uart_b()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":2,"tx_throughput":0.09836065769195557}})), "uart_b");
    
    is($json->encode($msg->uart_ftdi()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":38,"tx_throughput":0.49399998784065247}})), "uart_ftdi");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":28528,"latency":{"avg":-1,"current":-1,"lmax":0,"lmin":0},"length":58,"msg_type":24,"payload":"AAAAAIpLBjwAAAAAAABQcck9AAAAAAAAAAACAJHt/D4AAAAAAAAAACYA/////wAAAAAAAAAA/////w==","preamble":85,"sender":1219,"uart_a":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.008196720853447914,"tx_buffer_level":0,"tx_throughput":0.0},"uart_b":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":2,"tx_throughput":0.09836065769195557},"uart_ftdi":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":38,"tx_throughput":0.49399998784065247}}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_uart_state_dep_a_6() {
    my $buf = decode_base64("VRgAwwQ6pptEPAAAAAAAAAAAAgCmm0Q8AAAAAAAAAAACAOxRqD8AAAAAAAAAADIA/////wAAAAAAAAAA/////xZI");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x4816, "crc");
    
    is($msg->{'length'}, 58, "length");
    
    is($msg->{'msg_type'}, 0x18, "msg_type");
    
    is($msg->{'payload'}, "pptEPAAAAAAAAAAAAgCmm0Q8AAAAAAAAAAACAOxRqD8AAAAAAAAAADIA/////wAAAAAAAAAA/////w==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->latency()), $json->encode($json->decode(q{{"avg":-1,"current":-1,"lmax":0,"lmin":0}})), "latency");
    
    is($json->encode($msg->uart_a()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":2,"tx_throughput":0.012000000104308128}})), "uart_a");
    
    is($json->encode($msg->uart_b()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":2,"tx_throughput":0.012000000104308128}})), "uart_b");
    
    is($json->encode($msg->uart_ftdi()), $json->encode($json->decode(q{{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":50,"tx_throughput":1.315000057220459}})), "uart_ftdi");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":18454,"latency":{"avg":-1,"current":-1,"lmax":0,"lmin":0},"length":58,"msg_type":24,"payload":"pptEPAAAAAAAAAAAAgCmm0Q8AAAAAAAAAAACAOxRqD8AAAAAAAAAADIA/////wAAAAAAAAAA/////w==","preamble":85,"sender":1219,"uart_a":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":2,"tx_throughput":0.012000000104308128},"uart_b":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":2,"tx_throughput":0.012000000104308128},"uart_ftdi":{"crc_error_count":0,"io_error_count":0,"rx_buffer_level":0,"rx_throughput":0.0,"tx_buffer_level":50,"tx_throughput":1.315000057220459}}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_uart_state_dep_a_1();
test_auto_check_sbp_piksi_msg_uart_state_dep_a_2();
test_auto_check_sbp_piksi_msg_uart_state_dep_a_3();
test_auto_check_sbp_piksi_msg_uart_state_dep_a_4();
test_auto_check_sbp_piksi_msg_uart_state_dep_a_5();
test_auto_check_sbp_piksi_msg_uart_state_dep_a_6();

done_testing();