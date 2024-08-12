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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgThreadState.yaml
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
sub test_auto_check_sbp_piksi_msg_thread_state_1() {
    my $buf = decode_base64("VRcA9tcabWFpbgAAAAAAAAAAAAAAAAAAAAAAAJwJAABJig==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8a49, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0x17, "msg_type");
    
    is($msg->{'payload'}, "bWFpbgAAAAAAAAAAAAAAAAAAAAAAAJwJAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu(), 0, "cpu");
    
    is($msg->name(), "main\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "name");
    
    is($msg->stack_free(), 2460, "stack_free");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu":0,"crc":35401,"length":26,"msg_type":23,"name":"main\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","payload":"bWFpbgAAAAAAAAAAAAAAAAAAAAAAAJwJAAA=","preamble":85,"sender":55286,"stack_free":2460}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_thread_state_2() {
    my $buf = decode_base64("VRcA9tcaaWRsZQAAAAAAAAAAAAAAAAAAAABTAiQAAACXFA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x1497, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0x17, "msg_type");
    
    is($msg->{'payload'}, "aWRsZQAAAAAAAAAAAAAAAAAAAABTAiQAAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu(), 595, "cpu");
    
    is($msg->name(), "idle\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "name");
    
    is($msg->stack_free(), 36, "stack_free");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu":595,"crc":5271,"length":26,"msg_type":23,"name":"idle\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","payload":"aWRsZQAAAAAAAAAAAAAAAAAAAABTAiQAAAA=","preamble":85,"sender":55286,"stack_free":36}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_thread_state_3() {
    my $buf = decode_base64("VRcA9tcaTkFQIElTUgAAAAAAAAAAAAAAAAAOAHQEAADiPA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x3ce2, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0x17, "msg_type");
    
    is($msg->{'payload'}, "TkFQIElTUgAAAAAAAAAAAAAAAAAOAHQEAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu(), 14, "cpu");
    
    is($msg->name(), "NAP ISR\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "name");
    
    is($msg->stack_free(), 1140, "stack_free");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu":14,"crc":15586,"length":26,"msg_type":23,"name":"NAP ISR\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","payload":"TkFQIElTUgAAAAAAAAAAAAAAAAAOAHQEAAA=","preamble":85,"sender":55286,"stack_free":1140}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_thread_state_4() {
    my $buf = decode_base64("VRcA9tcaU0JQAAAAAAAAAAAAAAAAAAAAAAABAMQTAABaqQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa95a, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0x17, "msg_type");
    
    is($msg->{'payload'}, "U0JQAAAAAAAAAAAAAAAAAAAAAAABAMQTAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu(), 1, "cpu");
    
    is($msg->name(), "SBP\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "name");
    
    is($msg->stack_free(), 5060, "stack_free");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu":1,"crc":43354,"length":26,"msg_type":23,"name":"SBP\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","payload":"U0JQAAAAAAAAAAAAAAAAAAAAAAABAMQTAAA=","preamble":85,"sender":55286,"stack_free":5060}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_thread_state_5() {
    my $buf = decode_base64("VRcA9tcabWFuYWdlIGFjcQAAAAAAAAAAAAAHABQJAAAvSw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x4b2f, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0x17, "msg_type");
    
    is($msg->{'payload'}, "bWFuYWdlIGFjcQAAAAAAAAAAAAAHABQJAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu(), 7, "cpu");
    
    is($msg->name(), "manage acq\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "name");
    
    is($msg->stack_free(), 2324, "stack_free");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu":7,"crc":19247,"length":26,"msg_type":23,"name":"manage acq\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","payload":"bWFuYWdlIGFjcQAAAAAAAAAAAAAHABQJAAA=","preamble":85,"sender":55286,"stack_free":2324}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_thread_state_6() {
    my $buf = decode_base64("VRcAwwQabWFpbgAAAAAAAAAAAAAAAAAAAAAAAJQJAADD1A==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd4c3, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0x17, "msg_type");
    
    is($msg->{'payload'}, "bWFpbgAAAAAAAAAAAAAAAAAAAAAAAJQJAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu(), 0, "cpu");
    
    is($msg->name(), "main\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "name");
    
    is($msg->stack_free(), 2452, "stack_free");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu":0,"crc":54467,"length":26,"msg_type":23,"name":"main\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","payload":"bWFpbgAAAAAAAAAAAAAAAAAAAAAAAJQJAAA=","preamble":85,"sender":1219,"stack_free":2452}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_thread_state_7() {
    my $buf = decode_base64("VRcAwwQaaWRsZQAAAAAAAAAAAAAAAAAAAADkASQAAADhEg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x12e1, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0x17, "msg_type");
    
    is($msg->{'payload'}, "aWRsZQAAAAAAAAAAAAAAAAAAAADkASQAAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu(), 484, "cpu");
    
    is($msg->name(), "idle\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "name");
    
    is($msg->stack_free(), 36, "stack_free");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu":484,"crc":4833,"length":26,"msg_type":23,"name":"idle\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","payload":"aWRsZQAAAAAAAAAAAAAAAAAAAADkASQAAAA=","preamble":85,"sender":1219,"stack_free":36}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_thread_state_8() {
    my $buf = decode_base64("VRcAwwQaTkFQIElTUgAAAAAAAAAAAAAAAACKAVwHAACmdA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x74a6, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0x17, "msg_type");
    
    is($msg->{'payload'}, "TkFQIElTUgAAAAAAAAAAAAAAAACKAVwHAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu(), 394, "cpu");
    
    is($msg->name(), "NAP ISR\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "name");
    
    is($msg->stack_free(), 1884, "stack_free");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu":394,"crc":29862,"length":26,"msg_type":23,"name":"NAP ISR\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","payload":"TkFQIElTUgAAAAAAAAAAAAAAAACKAVwHAAA=","preamble":85,"sender":1219,"stack_free":1884}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_thread_state_9() {
    my $buf = decode_base64("VRcAwwQaU0JQAAAAAAAAAAAAAAAAAAAAAAABAAQMAADlrg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xaee5, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0x17, "msg_type");
    
    is($msg->{'payload'}, "U0JQAAAAAAAAAAAAAAAAAAAAAAABAAQMAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu(), 1, "cpu");
    
    is($msg->name(), "SBP\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "name");
    
    is($msg->stack_free(), 3076, "stack_free");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu":1,"crc":44773,"length":26,"msg_type":23,"name":"SBP\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","payload":"U0JQAAAAAAAAAAAAAAAAAAAAAAABAAQMAAA=","preamble":85,"sender":1219,"stack_free":3076}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_thread_state_10() {
    my $buf = decode_base64("VRcAwwQabWFuYWdlIGFjcQAAAAAAAAAAAAAKAHwJAAA0Ag==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x234, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0x17, "msg_type");
    
    is($msg->{'payload'}, "bWFuYWdlIGFjcQAAAAAAAAAAAAAKAHwJAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu(), 10, "cpu");
    
    is($msg->name(), "manage acq\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "name");
    
    is($msg->stack_free(), 2428, "stack_free");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu":10,"crc":564,"length":26,"msg_type":23,"name":"manage acq\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","payload":"bWFuYWdlIGFjcQAAAAAAAAAAAAAKAHwJAAA=","preamble":85,"sender":1219,"stack_free":2428}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_thread_state_11() {
    my $buf = decode_base64("VRcAwwQabWFuYWdlIHRyYWNrAAAAAAAAAAAAABwJAAB6Ng==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x367a, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0x17, "msg_type");
    
    is($msg->{'payload'}, "bWFuYWdlIHRyYWNrAAAAAAAAAAAAABwJAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu(), 0, "cpu");
    
    is($msg->name(), "manage track\x00\x00\x00\x00\x00\x00\x00\x00", "name");
    
    is($msg->stack_free(), 2332, "stack_free");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu":0,"crc":13946,"length":26,"msg_type":23,"name":"manage track\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","payload":"bWFuYWdlIHRyYWNrAAAAAAAAAAAAABwJAAA=","preamble":85,"sender":1219,"stack_free":2332}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_thread_state_1();
test_auto_check_sbp_piksi_msg_thread_state_2();
test_auto_check_sbp_piksi_msg_thread_state_3();
test_auto_check_sbp_piksi_msg_thread_state_4();
test_auto_check_sbp_piksi_msg_thread_state_5();
test_auto_check_sbp_piksi_msg_thread_state_6();
test_auto_check_sbp_piksi_msg_thread_state_7();
test_auto_check_sbp_piksi_msg_thread_state_8();
test_auto_check_sbp_piksi_msg_thread_state_9();
test_auto_check_sbp_piksi_msg_thread_state_10();
test_auto_check_sbp_piksi_msg_thread_state_11();

done_testing();