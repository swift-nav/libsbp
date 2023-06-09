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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadByIndexResp.yaml
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
sub test_auto_check_sbp_settings_msg_settings_read_by_index_resp_1() {
    my $buf = decode_base64("VacA9tdOAAB0ZWxlbWV0cnlfcmFkaW8AY29uZmlndXJhdGlvbl9zdHJpbmcAQVQmRixBVFMxPTExNSxBVFMyPTEyOCxBVFM1PTAsQVQmVyxBVFoA+Ok=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe9f8, "crc");
    
    is($msg->{'length'}, 78, "length");
    
    is($msg->{'msg_type'}, 0xa7, "msg_type");
    
    is($msg->{'payload'}, "AAB0ZWxlbWV0cnlfcmFkaW8AY29uZmlndXJhdGlvbl9zdHJpbmcAQVQmRixBVFMxPTExNSxBVFMyPTEyOCxBVFM1PTAsQVQmVyxBVFoA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->index(), 0, "index");
    
    is($msg->setting(), "telemetry_radio\x00configuration_string\x00AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ\x00", "setting");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":59896,"index":0,"length":78,"msg_type":167,"payload":"AAB0ZWxlbWV0cnlfcmFkaW8AY29uZmlndXJhdGlvbl9zdHJpbmcAQVQmRixBVFMxPTExNSxBVFMyPTEyOCxBVFM1PTAsQVQmVyxBVFoA","preamble":85,"sender":55286,"setting":"telemetry_radio\u0000configuration_string\u0000AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ\u0000"}})), "raw_json");
}
sub test_auto_check_sbp_settings_msg_settings_read_by_index_resp_2() {
    my $buf = decode_base64("VacA9tcjAQB1YXJ0X2Z0ZGkAbW9kZQBTQlAAZW51bTpTQlAsTk1FQQCn8w==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf3a7, "crc");
    
    is($msg->{'length'}, 35, "length");
    
    is($msg->{'msg_type'}, 0xa7, "msg_type");
    
    is($msg->{'payload'}, "AQB1YXJ0X2Z0ZGkAbW9kZQBTQlAAZW51bTpTQlAsTk1FQQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->index(), 1, "index");
    
    is($msg->setting(), "uart_ftdi\x00mode\x00SBP\x00enum:SBP,NMEA\x00", "setting");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":62375,"index":1,"length":35,"msg_type":167,"payload":"AQB1YXJ0X2Z0ZGkAbW9kZQBTQlAAZW51bTpTQlAsTk1FQQA=","preamble":85,"sender":55286,"setting":"uart_ftdi\u0000mode\u0000SBP\u0000enum:SBP,NMEA\u0000"}})), "raw_json");
}
sub test_auto_check_sbp_settings_msg_settings_read_by_index_resp_3() {
    my $buf = decode_base64("VacA9tcjAgB1YXJ0X2Z0ZGkAc2JwX21lc3NhZ2VfbWFzawA2NTUzNQAEOA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x3804, "crc");
    
    is($msg->{'length'}, 35, "length");
    
    is($msg->{'msg_type'}, 0xa7, "msg_type");
    
    is($msg->{'payload'}, "AgB1YXJ0X2Z0ZGkAc2JwX21lc3NhZ2VfbWFzawA2NTUzNQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->index(), 2, "index");
    
    is($msg->setting(), "uart_ftdi\x00sbp_message_mask\x0065535\x00", "setting");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":14340,"index":2,"length":35,"msg_type":167,"payload":"AgB1YXJ0X2Z0ZGkAc2JwX21lc3NhZ2VfbWFzawA2NTUzNQA=","preamble":85,"sender":55286,"setting":"uart_ftdi\u0000sbp_message_mask\u000065535\u0000"}})), "raw_json");
}
sub test_auto_check_sbp_settings_msg_settings_read_by_index_resp_4() {
    my $buf = decode_base64("VacA9tcdAwB1YXJ0X2Z0ZGkAYmF1ZHJhdGUAMTAwMDAwMADykg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x92f2, "crc");
    
    is($msg->{'length'}, 29, "length");
    
    is($msg->{'msg_type'}, 0xa7, "msg_type");
    
    is($msg->{'payload'}, "AwB1YXJ0X2Z0ZGkAYmF1ZHJhdGUAMTAwMDAwMAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->index(), 3, "index");
    
    is($msg->setting(), "uart_ftdi\x00baudrate\x001000000\x00", "setting");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":37618,"index":3,"length":29,"msg_type":167,"payload":"AwB1YXJ0X2Z0ZGkAYmF1ZHJhdGUAMTAwMDAwMAA=","preamble":85,"sender":55286,"setting":"uart_ftdi\u0000baudrate\u00001000000\u0000"}})), "raw_json");
}
sub test_auto_check_sbp_settings_msg_settings_read_by_index_resp_5() {
    my $buf = decode_base64("VacA9tckBAB1YXJ0X3VhcnRhAG1vZGUAU0JQAGVudW06U0JQLE5NRUEAFgQ=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x416, "crc");
    
    is($msg->{'length'}, 36, "length");
    
    is($msg->{'msg_type'}, 0xa7, "msg_type");
    
    is($msg->{'payload'}, "BAB1YXJ0X3VhcnRhAG1vZGUAU0JQAGVudW06U0JQLE5NRUEA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->index(), 4, "index");
    
    is($msg->setting(), "uart_uarta\x00mode\x00SBP\x00enum:SBP,NMEA\x00", "setting");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":1046,"index":4,"length":36,"msg_type":167,"payload":"BAB1YXJ0X3VhcnRhAG1vZGUAU0JQAGVudW06U0JQLE5NRUEA","preamble":85,"sender":55286,"setting":"uart_uarta\u0000mode\u0000SBP\u0000enum:SBP,NMEA\u0000"}})), "raw_json");
}
test_auto_check_sbp_settings_msg_settings_read_by_index_resp_1();
test_auto_check_sbp_settings_msg_settings_read_by_index_resp_2();
test_auto_check_sbp_settings_msg_settings_read_by_index_resp_3();
test_auto_check_sbp_settings_msg_settings_read_by_index_resp_4();
test_auto_check_sbp_settings_msg_settings_read_by_index_resp_5();

done_testing();