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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgDeviceMonitor.yaml
# with generate.py.  Do not modify by hand!

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";

BEGIN {
    # load all modules from SBP_PATH
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_piksi_msg_device_monitor_1() {
    my $buf = decode_base64("VbUAX0IK8djbA/0GFRioEs/p");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe9cf, "crc");
    
    is($msg->{'length'}, 10, "length");
    
    is($msg->{'msg_type'}, 0xb5, "msg_type");
    
    is($msg->{'payload'}, "8djbA/0GFRioEg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x425f, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu_temperature(), 6165, "cpu_temperature");
    
    is($msg->cpu_vaux(), 1789, "cpu_vaux");
    
    is($msg->cpu_vint(), 987, "cpu_vint");
    
    is($msg->dev_vin(), -9999, "dev_vin");
    
    is($msg->fe_temperature(), 4776, "fe_temperature");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu_temperature":6165,"cpu_vaux":1789,"cpu_vint":987,"crc":59855,"dev_vin":-9999,"fe_temperature":4776,"length":10,"msg_type":181,"payload":"8djbA/0GFRioEg==","preamble":85,"sender":16991}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_device_monitor_2() {
    my $buf = decode_base64("VbUAX0IK8djbA/4GGBioEqke");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x1ea9, "crc");
    
    is($msg->{'length'}, 10, "length");
    
    is($msg->{'msg_type'}, 0xb5, "msg_type");
    
    is($msg->{'payload'}, "8djbA/4GGBioEg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x425f, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu_temperature(), 6168, "cpu_temperature");
    
    is($msg->cpu_vaux(), 1790, "cpu_vaux");
    
    is($msg->cpu_vint(), 987, "cpu_vint");
    
    is($msg->dev_vin(), -9999, "dev_vin");
    
    is($msg->fe_temperature(), 4776, "fe_temperature");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu_temperature":6168,"cpu_vaux":1790,"cpu_vint":987,"crc":7849,"dev_vin":-9999,"fe_temperature":4776,"length":10,"msg_type":181,"payload":"8djbA/4GGBioEg==","preamble":85,"sender":16991}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_device_monitor_3() {
    my $buf = decode_base64("VbUAX0IK8djbA/0GFhioEhNy");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x7213, "crc");
    
    is($msg->{'length'}, 10, "length");
    
    is($msg->{'msg_type'}, 0xb5, "msg_type");
    
    is($msg->{'payload'}, "8djbA/0GFhioEg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x425f, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu_temperature(), 6166, "cpu_temperature");
    
    is($msg->cpu_vaux(), 1789, "cpu_vaux");
    
    is($msg->cpu_vint(), 987, "cpu_vint");
    
    is($msg->dev_vin(), -9999, "dev_vin");
    
    is($msg->fe_temperature(), 4776, "fe_temperature");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu_temperature":6166,"cpu_vaux":1789,"cpu_vint":987,"crc":29203,"dev_vin":-9999,"fe_temperature":4776,"length":10,"msg_type":181,"payload":"8djbA/0GFhioEg==","preamble":85,"sender":16991}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_device_monitor_4() {
    my $buf = decode_base64("VbUAX0IK8djaA/wGBhioEsdr");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6bc7, "crc");
    
    is($msg->{'length'}, 10, "length");
    
    is($msg->{'msg_type'}, 0xb5, "msg_type");
    
    is($msg->{'payload'}, "8djaA/wGBhioEg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x425f, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu_temperature(), 6150, "cpu_temperature");
    
    is($msg->cpu_vaux(), 1788, "cpu_vaux");
    
    is($msg->cpu_vint(), 986, "cpu_vint");
    
    is($msg->dev_vin(), -9999, "dev_vin");
    
    is($msg->fe_temperature(), 4776, "fe_temperature");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu_temperature":6150,"cpu_vaux":1788,"cpu_vint":986,"crc":27591,"dev_vin":-9999,"fe_temperature":4776,"length":10,"msg_type":181,"payload":"8djaA/wGBhioEg==","preamble":85,"sender":16991}})), "raw_json");
}
sub test_auto_check_sbp_piksi_msg_device_monitor_5() {
    my $buf = decode_base64("VbUAX0IK8djcA/0G6xeoEvE/");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x3ff1, "crc");
    
    is($msg->{'length'}, 10, "length");
    
    is($msg->{'msg_type'}, 0xb5, "msg_type");
    
    is($msg->{'payload'}, "8djcA/0G6xeoEg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x425f, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cpu_temperature(), 6123, "cpu_temperature");
    
    is($msg->cpu_vaux(), 1789, "cpu_vaux");
    
    is($msg->cpu_vint(), 988, "cpu_vint");
    
    is($msg->dev_vin(), -9999, "dev_vin");
    
    is($msg->fe_temperature(), 4776, "fe_temperature");

    is($json->encode($msg), $json->encode($json->decode(q{{"cpu_temperature":6123,"cpu_vaux":1789,"cpu_vint":988,"crc":16369,"dev_vin":-9999,"fe_temperature":4776,"length":10,"msg_type":181,"payload":"8djcA/0G6xeoEg==","preamble":85,"sender":16991}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_device_monitor_1();
test_auto_check_sbp_piksi_msg_device_monitor_2();
test_auto_check_sbp_piksi_msg_device_monitor_3();
test_auto_check_sbp_piksi_msg_device_monitor_4();
test_auto_check_sbp_piksi_msg_device_monitor_5();

done_testing();