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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepA.yaml
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
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_a_1() {
    my $buf = decode_base64("VRUAwwQNAABoQQDANUTGxwBGCAJE");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x4402, "crc");
    
    is($msg->{'length'}, 13, "length");
    
    is($msg->{'msg_type'}, 0x15, "msg_type");
    
    is($msg->{'payload'}, "AABoQQDANUTGxwBGCA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), 8241.943359375, "cf");
    
    is($msg->cp(), 727.0, "cp");
    
    is($msg->prn(), 8, "prn");
    
    is($msg->snr(), 14.5, "snr");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":8241.943359375,"cp":727.0,"crc":17410,"length":13,"msg_type":21,"payload":"AABoQQDANUTGxwBGCA==","preamble":85,"prn":8,"sender":1219,"snr":14.5}})), "raw_json");
}
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_a_2() {
    my $buf = decode_base64("VRUAwwQNzcx0QQDAs0MhUTtECdsb");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x1bdb, "crc");
    
    is($msg->{'length'}, 13, "length");
    
    is($msg->{'msg_type'}, 0x15, "msg_type");
    
    is($msg->{'payload'}, "zcx0QQDAs0MhUTtECQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), 749.2676391601562, "cf");
    
    is($msg->cp(), 359.5, "cp");
    
    is($msg->prn(), 9, "prn");
    
    is($msg->snr(), 15.300000190734863, "snr");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":749.2676391601562,"cp":359.5,"crc":7131,"length":13,"msg_type":21,"payload":"zcx0QQDAs0MhUTtECQ==","preamble":85,"prn":9,"sender":1219,"snr":15.300000190734863}})), "raw_json");
}
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_a_3() {
    my $buf = decode_base64("VRUAwwQNzcyQQQAAIkI57crFC5Yj");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x2396, "crc");
    
    is($msg->{'length'}, 13, "length");
    
    is($msg->{'msg_type'}, 0x15, "msg_type");
    
    is($msg->{'payload'}, "zcyQQQAAIkI57crFCw==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), -6493.65283203125, "cf");
    
    is($msg->cp(), 40.5, "cp");
    
    is($msg->prn(), 11, "prn");
    
    is($msg->snr(), 18.100000381469727, "snr");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":-6493.65283203125,"cp":40.5,"crc":9110,"length":13,"msg_type":21,"payload":"zcyQQQAAIkI57crFCw==","preamble":85,"prn":11,"sender":1219,"snr":18.100000381469727}})), "raw_json");
}
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_a_4() {
    my $buf = decode_base64("VRUAwwQNzcx0QQAgCUSBwXnEDJJ2");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x7692, "crc");
    
    is($msg->{'length'}, 13, "length");
    
    is($msg->{'msg_type'}, 0x15, "msg_type");
    
    is($msg->{'payload'}, "zcx0QQAgCUSBwXnEDA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), -999.0234985351562, "cf");
    
    is($msg->cp(), 548.5, "cp");
    
    is($msg->prn(), 12, "prn");
    
    is($msg->snr(), 15.300000190734863, "snr");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":-999.0234985351562,"cp":548.5,"crc":30354,"length":13,"msg_type":21,"payload":"zcx0QQAgCUSBwXnEDA==","preamble":85,"prn":12,"sender":1219,"snr":15.300000190734863}})), "raw_json");
}
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_a_5() {
    my $buf = decode_base64("VRUAwwQNzcx0QQAgQ0TkSpRFDhdL");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x4b17, "crc");
    
    is($msg->{'length'}, 13, "length");
    
    is($msg->{'msg_type'}, 0x15, "msg_type");
    
    is($msg->{'payload'}, "zcx0QQAgQ0TkSpRFDg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), 4745.361328125, "cf");
    
    is($msg->cp(), 780.5, "cp");
    
    is($msg->prn(), 14, "prn");
    
    is($msg->snr(), 15.300000190734863, "snr");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":4745.361328125,"cp":780.5,"crc":19223,"length":13,"msg_type":21,"payload":"zcx0QQAgQ0TkSpRFDg==","preamble":85,"prn":14,"sender":1219,"snr":15.300000190734863}})), "raw_json");
}
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_a_6() {
    my $buf = decode_base64("VRUAwwQN5DgjQwAgEkSBwfnDAMzP");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xcfcc, "crc");
    
    is($msg->{'length'}, 13, "length");
    
    is($msg->{'msg_type'}, 0x15, "msg_type");
    
    is($msg->{'payload'}, "5DgjQwAgEkSBwfnDAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x4c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), -499.5117492675781, "cf");
    
    is($msg->cp(), 584.5, "cp");
    
    is($msg->prn(), 0, "prn");
    
    is($msg->snr(), 163.22222900390625, "snr");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":-499.5117492675781,"cp":584.5,"crc":53196,"length":13,"msg_type":21,"payload":"5DgjQwAgEkSBwfnDAA==","preamble":85,"prn":0,"sender":1219,"snr":163.22222900390625}})), "raw_json");
}
test_auto_check_sbp_acquisition_msg_acq_result_dep_a_1();
test_auto_check_sbp_acquisition_msg_acq_result_dep_a_2();
test_auto_check_sbp_acquisition_msg_acq_result_dep_a_3();
test_auto_check_sbp_acquisition_msg_acq_result_dep_a_4();
test_auto_check_sbp_acquisition_msg_acq_result_dep_a_5();
test_auto_check_sbp_acquisition_msg_acq_result_dep_a_6();

done_testing();