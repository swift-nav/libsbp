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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgPrintDep.yaml
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
sub test_auto_check_sbp_logging_msg_print_dep_1() {
    my $buf = decode_base64("VRAAIiIrSU5GTzogYWNxOiBQUk4gMTUgZm91bmQgQCAtMjQ5NyBIeiwgMjAgU05SCnRn");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6774, "crc");
    
    is($msg->{'length'}, 43, "length");
    
    is($msg->{'msg_type'}, 0x10, "msg_type");
    
    is($msg->{'payload'}, "SU5GTzogYWNxOiBQUk4gMTUgZm91bmQgQCAtMjQ5NyBIeiwgMjAgU05SCg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x2222, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->text(), "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n", "text");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":26484,"length":43,"msg_type":16,"payload":"SU5GTzogYWNxOiBQUk4gMTUgZm91bmQgQCAtMjQ5NyBIeiwgMjAgU05SCg==","preamble":85,"sender":8738,"text":"INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n"}})), "raw_json");
}
sub test_auto_check_sbp_logging_msg_print_dep_2() {
    my $buf = decode_base64("VRAAIiIqSU5GTzogYWNxOiBQUk4gMzEgZm91bmQgQCA0MjQ1IEh6LCAyMSBTTlIKjCs=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x2b8c, "crc");
    
    is($msg->{'length'}, 42, "length");
    
    is($msg->{'msg_type'}, 0x10, "msg_type");
    
    is($msg->{'payload'}, "SU5GTzogYWNxOiBQUk4gMzEgZm91bmQgQCA0MjQ1IEh6LCAyMSBTTlIK", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x2222, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->text(), "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n", "text");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":11148,"length":42,"msg_type":16,"payload":"SU5GTzogYWNxOiBQUk4gMzEgZm91bmQgQCA0MjQ1IEh6LCAyMSBTTlIK","preamble":85,"sender":8738,"text":"INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n"}})), "raw_json");
}
sub test_auto_check_sbp_logging_msg_print_dep_3() {
    my $buf = decode_base64("VRAAIiIjSU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMCAoUFJOIDExKQoXjw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8f17, "crc");
    
    is($msg->{'length'}, 35, "length");
    
    is($msg->{'msg_type'}, 0x10, "msg_type");
    
    is($msg->{'payload'}, "SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMCAoUFJOIDExKQo=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x2222, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->text(), "INFO: Disabling channel 0 (PRN 11)\n", "text");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":36631,"length":35,"msg_type":16,"payload":"SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMCAoUFJOIDExKQo=","preamble":85,"sender":8738,"text":"INFO: Disabling channel 0 (PRN 11)\n"}})), "raw_json");
}
sub test_auto_check_sbp_logging_msg_print_dep_4() {
    my $buf = decode_base64("VRAAIiIpSU5GTzogYWNxOiBQUk4gMiBmb3VuZCBAIDM5OTYgSHosIDIwIFNOUgrvMA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x30ef, "crc");
    
    is($msg->{'length'}, 41, "length");
    
    is($msg->{'msg_type'}, 0x10, "msg_type");
    
    is($msg->{'payload'}, "SU5GTzogYWNxOiBQUk4gMiBmb3VuZCBAIDM5OTYgSHosIDIwIFNOUgo=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x2222, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->text(), "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n", "text");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":12527,"length":41,"msg_type":16,"payload":"SU5GTzogYWNxOiBQUk4gMiBmb3VuZCBAIDM5OTYgSHosIDIwIFNOUgo=","preamble":85,"sender":8738,"text":"INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n"}})), "raw_json");
}
sub test_auto_check_sbp_logging_msg_print_dep_5() {
    my $buf = decode_base64("VRAAIiIqSU5GTzogYWNxOiBQUk4gNCBmb3VuZCBAIC03NDkyIEh6LCAyMCBTTlIKL/g=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf82f, "crc");
    
    is($msg->{'length'}, 42, "length");
    
    is($msg->{'msg_type'}, 0x10, "msg_type");
    
    is($msg->{'payload'}, "SU5GTzogYWNxOiBQUk4gNCBmb3VuZCBAIC03NDkyIEh6LCAyMCBTTlIK", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x2222, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->text(), "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n", "text");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":63535,"length":42,"msg_type":16,"payload":"SU5GTzogYWNxOiBQUk4gNCBmb3VuZCBAIC03NDkyIEh6LCAyMCBTTlIK","preamble":85,"sender":8738,"text":"INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n"}})), "raw_json");
}
sub test_auto_check_sbp_logging_msg_print_dep_6() {
    my $buf = decode_base64("VRAAIiIjSU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMSAoUFJOIDE1KQqeiw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8b9e, "crc");
    
    is($msg->{'length'}, 35, "length");
    
    is($msg->{'msg_type'}, 0x10, "msg_type");
    
    is($msg->{'payload'}, "SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMSAoUFJOIDE1KQo=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x2222, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->text(), "INFO: Disabling channel 1 (PRN 15)\n", "text");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":35742,"length":35,"msg_type":16,"payload":"SU5GTzogRGlzYWJsaW5nIGNoYW5uZWwgMSAoUFJOIDE1KQo=","preamble":85,"sender":8738,"text":"INFO: Disabling channel 1 (PRN 15)\n"}})), "raw_json");
}
test_auto_check_sbp_logging_msg_print_dep_1();
test_auto_check_sbp_logging_msg_print_dep_2();
test_auto_check_sbp_logging_msg_print_dep_3();
test_auto_check_sbp_logging_msg_print_dep_4();
test_auto_check_sbp_logging_msg_print_dep_5();
test_auto_check_sbp_logging_msg_print_dep_6();

done_testing();