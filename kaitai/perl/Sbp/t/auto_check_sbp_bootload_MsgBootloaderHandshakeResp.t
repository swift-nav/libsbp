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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/bootload/test_MsgBootloaderHandshakeResp.yaml
# with generate.py.  Do not modify by hand!

use strict;

BEGIN {
    # add grandparent directory to include path
    use Cwd qw(realpath);
    use File::Basename;
    unshift @INC, realpath(dirname($0))."/../../";
}

use Sbp::Sbp;
use Sbp::ParseUtils;
use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_bootload_msg_bootloader_handshake_resp_1() {
    my $buf = decode_base64("VbQAAAAJAAAAAHYxLjIKyQE=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x1c9, "crc");
    
    is($msg->{'length'}, 9, "length");
    
    is($msg->{'msg_type'}, 0xb4, "msg_type");
    
    is($msg->{'payload'}, "AAAAAHYxLjIK", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x0, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->version(), "v1.2\n", "version");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":457,"flags":0,"length":9,"msg_type":180,"payload":"AAAAAHYxLjIK","preamble":85,"sender":0,"version":"v1.2\n"}})), "raw_json");
}
sub test_auto_check_sbp_bootload_msg_bootloader_handshake_resp_2() {
    my $buf = decode_base64("VbAAwwQEdjEuMgHO");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xce01, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'msg_type'}, 0xb0, "msg_type");
    
    is($msg->{'payload'}, "djEuMg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->handshake()), $json->encode($json->decode(q{[118,49,46,50]})), "handshake");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":52737,"handshake":[118,49,46,50],"length":4,"msg_type":176,"payload":"djEuMg==","preamble":85,"sender":1219}})), "raw_json");
}
test_auto_check_sbp_bootload_msg_bootloader_handshake_resp_1();
test_auto_check_sbp_bootload_msg_bootloader_handshake_resp_2();

done_testing();