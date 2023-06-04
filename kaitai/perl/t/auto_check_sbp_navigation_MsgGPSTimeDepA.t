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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTimeDepA.yaml
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
use t::Utils;
sub test_auto_check_sbp_navigation_msg_gps_time_dep_a_1() {
    my $buf = decode_base64("VQAB9tcL+wZ4LicAAAAAAACFJA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x2485, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x100, "msg_type");
    
    is($msg->{'payload'}, "+wZ4LicAAAAAAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), 0, "ns_residual");
    
    is($msg->tow(), 2567800, "tow");
    
    is($msg->wn(), 1787, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":9349,"flags":0,"length":11,"msg_type":256,"ns_residual":0,"payload":"+wZ4LicAAAAAAAA=","preamble":85,"sender":55286,"tow":2567800,"wn":1787}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_dep_a_2() {
    my $buf = decode_base64("VQAB9tcL+wbcLicAAAAAAAAkoA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa024, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x100, "msg_type");
    
    is($msg->{'payload'}, "+wbcLicAAAAAAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), 0, "ns_residual");
    
    is($msg->tow(), 2567900, "tow");
    
    is($msg->wn(), 1787, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":40996,"flags":0,"length":11,"msg_type":256,"ns_residual":0,"payload":"+wbcLicAAAAAAAA=","preamble":85,"sender":55286,"tow":2567900,"wn":1787}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_dep_a_3() {
    my $buf = decode_base64("VQAB9tcL+wZALycAAAAAAACrvg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xbeab, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x100, "msg_type");
    
    is($msg->{'payload'}, "+wZALycAAAAAAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), 0, "ns_residual");
    
    is($msg->tow(), 2568000, "tow");
    
    is($msg->wn(), 1787, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":48811,"flags":0,"length":11,"msg_type":256,"ns_residual":0,"payload":"+wZALycAAAAAAAA=","preamble":85,"sender":55286,"tow":2568000,"wn":1787}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_dep_a_4() {
    my $buf = decode_base64("VQAB9tcL+wakLycAAAAAAADTZQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x65d3, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x100, "msg_type");
    
    is($msg->{'payload'}, "+wakLycAAAAAAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), 0, "ns_residual");
    
    is($msg->tow(), 2568100, "tow");
    
    is($msg->wn(), 1787, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":26067,"flags":0,"length":11,"msg_type":256,"ns_residual":0,"payload":"+wakLycAAAAAAAA=","preamble":85,"sender":55286,"tow":2568100,"wn":1787}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_dep_a_5() {
    my $buf = decode_base64("VQAB9tcL+wYIMCcAAAAAAAD7LA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x2cfb, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x100, "msg_type");
    
    is($msg->{'payload'}, "+wYIMCcAAAAAAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), 0, "ns_residual");
    
    is($msg->tow(), 2568200, "tow");
    
    is($msg->wn(), 1787, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":11515,"flags":0,"length":11,"msg_type":256,"ns_residual":0,"payload":"+wYIMCcAAAAAAAA=","preamble":85,"sender":55286,"tow":2568200,"wn":1787}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_dep_a_6() {
    my $buf = decode_base64("VQABwwQLLgfUnUMYb5P8/wDXvg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xbed7, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x100, "msg_type");
    
    is($msg->{'payload'}, "LgfUnUMYb5P8/wA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), -224401, "ns_residual");
    
    is($msg->tow(), 407084500, "tow");
    
    is($msg->wn(), 1838, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":48855,"flags":0,"length":11,"msg_type":256,"ns_residual":-224401,"payload":"LgfUnUMYb5P8/wA=","preamble":85,"sender":1219,"tow":407084500,"wn":1838}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_dep_a_7() {
    my $buf = decode_base64("VQABwwQLLgc4nkMYbWcDAACGWQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5986, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x100, "msg_type");
    
    is($msg->{'payload'}, "Lgc4nkMYbWcDAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), 223085, "ns_residual");
    
    is($msg->tow(), 407084600, "tow");
    
    is($msg->wn(), 1838, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":22918,"flags":0,"length":11,"msg_type":256,"ns_residual":223085,"payload":"Lgc4nkMYbWcDAAA=","preamble":85,"sender":1219,"tow":407084600,"wn":1838}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_dep_a_8() {
    my $buf = decode_base64("VQABwwQLLgecnkMY6Zj8/wDO8Q==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf1ce, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x100, "msg_type");
    
    is($msg->{'payload'}, "LgecnkMY6Zj8/wA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), -222999, "ns_residual");
    
    is($msg->tow(), 407084700, "tow");
    
    is($msg->wn(), 1838, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":61902,"flags":0,"length":11,"msg_type":256,"ns_residual":-222999,"payload":"LgecnkMY6Zj8/wA=","preamble":85,"sender":1219,"tow":407084700,"wn":1838}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_dep_a_9() {
    my $buf = decode_base64("VQABwwQLLgcAn0MY8JoDAACTYg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6293, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x100, "msg_type");
    
    is($msg->{'payload'}, "LgcAn0MY8JoDAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), 236272, "ns_residual");
    
    is($msg->tow(), 407084800, "tow");
    
    is($msg->wn(), 1838, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":25235,"flags":0,"length":11,"msg_type":256,"ns_residual":236272,"payload":"LgcAn0MY8JoDAAA=","preamble":85,"sender":1219,"tow":407084800,"wn":1838}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_dep_a_10() {
    my $buf = decode_base64("VQABwwQLLgdkn0MYkGX8/wC6mA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x98ba, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x100, "msg_type");
    
    is($msg->{'payload'}, "Lgdkn0MYkGX8/wA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), -236144, "ns_residual");
    
    is($msg->tow(), 407084900, "tow");
    
    is($msg->wn(), 1838, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":39098,"flags":0,"length":11,"msg_type":256,"ns_residual":-236144,"payload":"Lgdkn0MYkGX8/wA=","preamble":85,"sender":1219,"tow":407084900,"wn":1838}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_dep_a_11() {
    my $buf = decode_base64("VQABwwQLLgcuokQYzeb6/wAL4Q==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe10b, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x100, "msg_type");
    
    is($msg->{'payload'}, "LgcuokQYzeb6/wA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), -334131, "ns_residual");
    
    is($msg->tow(), 407151150, "tow");
    
    is($msg->wn(), 1838, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":57611,"flags":0,"length":11,"msg_type":256,"ns_residual":-334131,"payload":"LgcuokQYzeb6/wA=","preamble":85,"sender":1219,"tow":407151150,"wn":1838}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_gps_time_dep_a_1();
test_auto_check_sbp_navigation_msg_gps_time_dep_a_2();
test_auto_check_sbp_navigation_msg_gps_time_dep_a_3();
test_auto_check_sbp_navigation_msg_gps_time_dep_a_4();
test_auto_check_sbp_navigation_msg_gps_time_dep_a_5();
test_auto_check_sbp_navigation_msg_gps_time_dep_a_6();
test_auto_check_sbp_navigation_msg_gps_time_dep_a_7();
test_auto_check_sbp_navigation_msg_gps_time_dep_a_8();
test_auto_check_sbp_navigation_msg_gps_time_dep_a_9();
test_auto_check_sbp_navigation_msg_gps_time_dep_a_10();
test_auto_check_sbp_navigation_msg_gps_time_dep_a_11();

done_testing();