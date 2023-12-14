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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgNetworkStateResp.yaml
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
sub test_auto_check_sbp_piksi_msg_network_state_resp_1() {
    my $buf = decode_base64("VbsAKA8yj/FUtJjCiSAscpNE3lzATus/0HI1txj05xppGYgDaWYwAAAAAAAAAAAAAAAAAMPlUJN2wQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xc176, "crc");
    
    is($msg->{'length'}, 50, "length");
    
    is($msg->{'msg_type'}, 0xbb, "msg_type");
    
    is($msg->{'payload'}, "j/FUtJjCiSAscpNE3lzATus/0HI1txj05xppGYgDaWYwAAAAAAAAAAAAAAAAAMPlUJM=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x0f28, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 2471552451, "flags");
    
    is($msg->interface_name(), "if0\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "interface_name");
    
    is($json->encode($msg->ipv4_address()), $json->encode($json->decode(q{[143,241,84,180]})), "ipv4_address");
    
    is($msg->ipv4_mask_size(), 152, "ipv4_mask_size");
    
    is($json->encode($msg->ipv6_address()), $json->encode($json->decode(q{[194,137,32,44,114,147,68,222,92,192,78,235,63,208,114,53]})), "ipv6_address");
    
    is($msg->ipv6_mask_size(), 183, "ipv6_mask_size");
    
    is($msg->rx_bytes(), 451408920, "rx_bytes");
    
    is($msg->tx_bytes(), 59251049, "tx_bytes");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":49526,"flags":2471552451,"interface_name":"if0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","ipv4_address":[143,241,84,180],"ipv4_mask_size":152,"ipv6_address":[194,137,32,44,114,147,68,222,92,192,78,235,63,208,114,53],"ipv6_mask_size":183,"length":50,"msg_type":187,"payload":"j/FUtJjCiSAscpNE3lzATus/0HI1txj05xppGYgDaWYwAAAAAAAAAAAAAAAAAMPlUJM=","preamble":85,"rx_bytes":451408920,"sender":3880,"tx_bytes":59251049}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_network_state_resp_1();

done_testing();