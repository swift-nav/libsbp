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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgStartup.yaml
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
sub test_auto_check_sbp_system_msg_startup_1() {
    my $buf = decode_base64("VQD/QgAEAAAAAEag");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa046, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'msg_type'}, 0xff00, "msg_type");
    
    is($msg->{'payload'}, "AAAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cause(), 0, "cause");
    
    is($msg->reserved(), 0, "reserved");
    
    is($msg->startup_type(), 0, "startup_type");

    is($json->encode($msg), $json->encode($json->decode(q{{"cause":0,"crc":41030,"length":4,"msg_type":65280,"payload":"AAAAAA==","preamble":85,"reserved":0,"sender":66,"startup_type":0}})), "raw_json");
}
sub test_auto_check_sbp_system_msg_startup_2() {
    my $buf = decode_base64("VQD/wwQEAAAAAH+1");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb57f, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'msg_type'}, 0xff00, "msg_type");
    
    is($msg->{'payload'}, "AAAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cause(), 0, "cause");
    
    is($msg->reserved(), 0, "reserved");
    
    is($msg->startup_type(), 0, "startup_type");

    is($json->encode($msg), $json->encode($json->decode(q{{"cause":0,"crc":46463,"length":4,"msg_type":65280,"payload":"AAAAAA==","preamble":85,"reserved":0,"sender":1219,"startup_type":0}})), "raw_json");
}
test_auto_check_sbp_system_msg_startup_1();
test_auto_check_sbp_system_msg_startup_2();

done_testing();