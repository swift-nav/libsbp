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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDopsDepA.yaml
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
sub test_auto_check_sbp_navigation_msg_dops_dep_a_1() {
    my $buf = decode_base64("VQYC9tcOCDAnALQAvgCqAKAAlgB5qg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xaa79, "crc");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'msg_type'}, 0x206, "msg_type");
    
    is($msg->{'payload'}, "CDAnALQAvgCqAKAAlgA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->gdop(), 180, "gdop");
    
    is($msg->hdop(), 160, "hdop");
    
    is($msg->pdop(), 190, "pdop");
    
    is($msg->tdop(), 170, "tdop");
    
    is($msg->tow(), 2568200, "tow");
    
    is($msg->vdop(), 150, "vdop");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":43641,"gdop":180,"hdop":160,"length":14,"msg_type":518,"payload":"CDAnALQAvgCqAKAAlgA=","pdop":190,"preamble":85,"sender":55286,"tdop":170,"tow":2568200,"vdop":150}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_dops_dep_a_2() {
    my $buf = decode_base64("VQYC9tcO8DMnALQAvgCqAKAAlgBOqQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa94e, "crc");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'msg_type'}, 0x206, "msg_type");
    
    is($msg->{'payload'}, "8DMnALQAvgCqAKAAlgA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->gdop(), 180, "gdop");
    
    is($msg->hdop(), 160, "hdop");
    
    is($msg->pdop(), 190, "pdop");
    
    is($msg->tdop(), 170, "tdop");
    
    is($msg->tow(), 2569200, "tow");
    
    is($msg->vdop(), 150, "vdop");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":43342,"gdop":180,"hdop":160,"length":14,"msg_type":518,"payload":"8DMnALQAvgCqAKAAlgA=","pdop":190,"preamble":85,"sender":55286,"tdop":170,"tow":2569200,"vdop":150}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_dops_dep_a_3() {
    my $buf = decode_base64("VQYC9tcO2DcnALQAvgCqAKAAlgBH2g==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xda47, "crc");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'msg_type'}, 0x206, "msg_type");
    
    is($msg->{'payload'}, "2DcnALQAvgCqAKAAlgA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->gdop(), 180, "gdop");
    
    is($msg->hdop(), 160, "hdop");
    
    is($msg->pdop(), 190, "pdop");
    
    is($msg->tdop(), 170, "tdop");
    
    is($msg->tow(), 2570200, "tow");
    
    is($msg->vdop(), 150, "vdop");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":55879,"gdop":180,"hdop":160,"length":14,"msg_type":518,"payload":"2DcnALQAvgCqAKAAlgA=","pdop":190,"preamble":85,"sender":55286,"tdop":170,"tow":2570200,"vdop":150}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_dops_dep_a_4() {
    my $buf = decode_base64("VQYCwwQO1J1DGPcA1wB7ABEBLADOFQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x15ce, "crc");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'msg_type'}, 0x206, "msg_type");
    
    is($msg->{'payload'}, "1J1DGPcA1wB7ABEBLAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->gdop(), 247, "gdop");
    
    is($msg->hdop(), 273, "hdop");
    
    is($msg->pdop(), 215, "pdop");
    
    is($msg->tdop(), 123, "tdop");
    
    is($msg->tow(), 407084500, "tow");
    
    is($msg->vdop(), 44, "vdop");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":5582,"gdop":247,"hdop":273,"length":14,"msg_type":518,"payload":"1J1DGPcA1wB7ABEBLAA=","pdop":215,"preamble":85,"sender":1219,"tdop":123,"tow":407084500,"vdop":44}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_dops_dep_a_5() {
    my $buf = decode_base64("VQYCwwQOAAAAAP////8AAAAAAACSDA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xc92, "crc");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'msg_type'}, 0x206, "msg_type");
    
    is($msg->{'payload'}, "AAAAAP////8AAAAAAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->gdop(), 65535, "gdop");
    
    is($msg->hdop(), 0, "hdop");
    
    is($msg->pdop(), 65535, "pdop");
    
    is($msg->tdop(), 0, "tdop");
    
    is($msg->tow(), 0, "tow");
    
    is($msg->vdop(), 0, "vdop");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":3218,"gdop":65535,"hdop":0,"length":14,"msg_type":518,"payload":"AAAAAP////8AAAAAAAA=","pdop":65535,"preamble":85,"sender":1219,"tdop":0,"tow":0,"vdop":0}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_dops_dep_a_6() {
    my $buf = decode_base64("VQYCwwQOgKVEGFwBOAGbAH0CcQCBXQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5d81, "crc");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'msg_type'}, 0x206, "msg_type");
    
    is($msg->{'payload'}, "gKVEGFwBOAGbAH0CcQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->gdop(), 348, "gdop");
    
    is($msg->hdop(), 637, "hdop");
    
    is($msg->pdop(), 312, "pdop");
    
    is($msg->tdop(), 155, "tdop");
    
    is($msg->tow(), 407152000, "tow");
    
    is($msg->vdop(), 113, "vdop");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":23937,"gdop":348,"hdop":637,"length":14,"msg_type":518,"payload":"gKVEGFwBOAGbAH0CcQA=","pdop":312,"preamble":85,"sender":1219,"tdop":155,"tow":407152000,"vdop":113}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_dops_dep_a_7() {
    my $buf = decode_base64("VQYCwwQOaKlEGFwBNwGbAH0CcQDRgA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x80d1, "crc");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'msg_type'}, 0x206, "msg_type");
    
    is($msg->{'payload'}, "aKlEGFwBNwGbAH0CcQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->gdop(), 348, "gdop");
    
    is($msg->hdop(), 637, "hdop");
    
    is($msg->pdop(), 311, "pdop");
    
    is($msg->tdop(), 155, "tdop");
    
    is($msg->tow(), 407153000, "tow");
    
    is($msg->vdop(), 113, "vdop");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":32977,"gdop":348,"hdop":637,"length":14,"msg_type":518,"payload":"aKlEGFwBNwGbAH0CcQA=","pdop":311,"preamble":85,"sender":1219,"tdop":155,"tow":407153000,"vdop":113}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_dops_dep_a_8() {
    my $buf = decode_base64("VQYCwwQOUK1EGFwBNwGbAH0CcAAeBg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x61e, "crc");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'msg_type'}, 0x206, "msg_type");
    
    is($msg->{'payload'}, "UK1EGFwBNwGbAH0CcAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->gdop(), 348, "gdop");
    
    is($msg->hdop(), 637, "hdop");
    
    is($msg->pdop(), 311, "pdop");
    
    is($msg->tdop(), 155, "tdop");
    
    is($msg->tow(), 407154000, "tow");
    
    is($msg->vdop(), 112, "vdop");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":1566,"gdop":348,"hdop":637,"length":14,"msg_type":518,"payload":"UK1EGFwBNwGbAH0CcAA=","pdop":311,"preamble":85,"sender":1219,"tdop":155,"tow":407154000,"vdop":112}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_dops_dep_a_9() {
    my $buf = decode_base64("VQYCwwQOOLFEGFwBNwGbAH0CcABGQw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x4346, "crc");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'msg_type'}, 0x206, "msg_type");
    
    is($msg->{'payload'}, "OLFEGFwBNwGbAH0CcAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->gdop(), 348, "gdop");
    
    is($msg->hdop(), 637, "hdop");
    
    is($msg->pdop(), 311, "pdop");
    
    is($msg->tdop(), 155, "tdop");
    
    is($msg->tow(), 407155000, "tow");
    
    is($msg->vdop(), 112, "vdop");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":17222,"gdop":348,"hdop":637,"length":14,"msg_type":518,"payload":"OLFEGFwBNwGbAH0CcAA=","pdop":311,"preamble":85,"sender":1219,"tdop":155,"tow":407155000,"vdop":112}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_dops_dep_a_1();
test_auto_check_sbp_navigation_msg_dops_dep_a_2();
test_auto_check_sbp_navigation_msg_dops_dep_a_3();
test_auto_check_sbp_navigation_msg_dops_dep_a_4();
test_auto_check_sbp_navigation_msg_dops_dep_a_5();
test_auto_check_sbp_navigation_msg_dops_dep_a_6();
test_auto_check_sbp_navigation_msg_dops_dep_a_7();
test_auto_check_sbp_navigation_msg_dops_dep_a_8();
test_auto_check_sbp_navigation_msg_dops_dep_a_9();

done_testing();