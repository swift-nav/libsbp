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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgIarState.yaml
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
sub test_auto_check_sbp_piksi_msg_iar_state_1() {
    my $buf = decode_base64("VRkA9tcEAQAAANiM");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8cd8, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'msg_type'}, 0x19, "msg_type");
    
    is($msg->{'payload'}, "AQAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->num_hyps(), 1, "num_hyps");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":36056,"length":4,"msg_type":25,"num_hyps":1,"payload":"AQAAAA==","preamble":85,"sender":55286}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_iar_state_2() {
    my $buf = decode_base64("VRkAwwQEAAAAABKw");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb012, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'msg_type'}, 0x19, "msg_type");
    
    is($msg->{'payload'}, "AAAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->num_hyps(), 0, "num_hyps");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":45074,"length":4,"msg_type":25,"num_hyps":0,"payload":"AAAAAA==","preamble":85,"sender":1219}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_iar_state_3() {
    my $buf = decode_base64("VRkAwwQEAQAAAKbG");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xc6a6, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'msg_type'}, 0x19, "msg_type");
    
    is($msg->{'payload'}, "AQAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->num_hyps(), 1, "num_hyps");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":50854,"length":4,"msg_type":25,"num_hyps":1,"payload":"AQAAAA==","preamble":85,"sender":1219}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_iar_state_4() {
    my $buf = decode_base64("VRkAwwQE2QIAAAaF");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8506, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'msg_type'}, 0x19, "msg_type");
    
    is($msg->{'payload'}, "2QIAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->num_hyps(), 729, "num_hyps");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":34054,"length":4,"msg_type":25,"num_hyps":729,"payload":"2QIAAA==","preamble":85,"sender":1219}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_iar_state_5() {
    my $buf = decode_base64("VRkAwwQE2AIAALLz");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf3b2, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'msg_type'}, 0x19, "msg_type");
    
    is($msg->{'payload'}, "2AIAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->num_hyps(), 728, "num_hyps");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":62386,"length":4,"msg_type":25,"num_hyps":728,"payload":"2AIAAA==","preamble":85,"sender":1219}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_iar_state_6() {
    my $buf = decode_base64("VRkAwwQE1wIAAFwn");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x275c, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'msg_type'}, 0x19, "msg_type");
    
    is($msg->{'payload'}, "1wIAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->num_hyps(), 727, "num_hyps");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":10076,"length":4,"msg_type":25,"num_hyps":727,"payload":"1wIAAA==","preamble":85,"sender":1219}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_iar_state_7() {
    my $buf = decode_base64("VRkAwwQE0wIAAK3t");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xedad, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'msg_type'}, 0x19, "msg_type");
    
    is($msg->{'payload'}, "0wIAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->num_hyps(), 723, "num_hyps");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":60845,"length":4,"msg_type":25,"num_hyps":723,"payload":"0wIAAA==","preamble":85,"sender":1219}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_iar_state_1();
test_auto_check_sbp_piksi_msg_iar_state_2();
test_auto_check_sbp_piksi_msg_iar_state_3();
test_auto_check_sbp_piksi_msg_iar_state_4();
test_auto_check_sbp_piksi_msg_iar_state_5();
test_auto_check_sbp_piksi_msg_iar_state_6();
test_auto_check_sbp_piksi_msg_iar_state_7();

done_testing();