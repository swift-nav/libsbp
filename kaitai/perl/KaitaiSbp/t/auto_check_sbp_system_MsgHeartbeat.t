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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgHeartbeat.yaml
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
sub test_auto_check_sbp_system_msg_heartbeat_1() {
    my $buf = decode_base64("Vf//9tcEADIAAPnY");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd8f9, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'msg_type'}, 0xffff, "msg_type");
    
    is($msg->{'payload'}, "ADIAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 12800, "flags");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":55545,"flags":12800,"length":4,"msg_type":65535,"payload":"ADIAAA==","preamble":85,"sender":55286}})), "raw_json");
}
sub test_auto_check_sbp_system_msg_heartbeat_2() {
    my $buf = decode_base64("Vf//wwQEAAAAAEI5");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x3942, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'msg_type'}, 0xffff, "msg_type");
    
    is($msg->{'payload'}, "AAAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":14658,"flags":0,"length":4,"msg_type":65535,"payload":"AAAAAA==","preamble":85,"sender":1219}})), "raw_json");
}
test_auto_check_sbp_system_msg_heartbeat_1();
test_auto_check_sbp_system_msg_heartbeat_2();

done_testing();