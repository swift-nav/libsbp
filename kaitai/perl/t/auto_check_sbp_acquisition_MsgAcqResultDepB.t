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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepB.yaml
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
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_b_1() {
    my $buf = decode_base64("VRQA9tcQiacSQgAAoUPwGJxFCQAAAFDD");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xc350, "crc");
    
    is($msg->{'length'}, 16, "length");
    
    is($msg->{'msg_type'}, 0x14, "msg_type");
    
    is($msg->{'payload'}, "iacSQgAAoUPwGJxFCQAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), 4995.1171875, "cf");
    
    is($msg->cp(), 322.0, "cp");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":9}})), "sid");
    
    is($msg->snr(), 36.66360855102539, "snr");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":4995.1171875,"cp":322.0,"crc":50000,"length":16,"msg_type":20,"payload":"iacSQgAAoUPwGJxFCQAAAA==","preamble":85,"sender":55286,"sid":{"code":0,"reserved":0,"sat":9},"snr":36.66360855102539}})), "raw_json");
}
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_b_2() {
    my $buf = decode_base64("VRQA9tcQzqwQQgDAUkTGxwDGAwAAAJWP");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8f95, "crc");
    
    is($msg->{'length'}, 16, "length");
    
    is($msg->{'msg_type'}, 0x14, "msg_type");
    
    is($msg->{'payload'}, "zqwQQgDAUkTGxwDGAwAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), -8241.943359375, "cf");
    
    is($msg->cp(), 843.0, "cp");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":3}})), "sid");
    
    is($msg->snr(), 36.16875457763672, "snr");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":-8241.943359375,"cp":843.0,"crc":36757,"length":16,"msg_type":20,"payload":"zqwQQgDAUkTGxwDGAwAAAA==","preamble":85,"sender":55286,"sid":{"code":0,"reserved":0,"sat":3},"snr":36.16875457763672}})), "raw_json");
}
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_b_3() {
    my $buf = decode_base64("VRQA9tcQ5BsPQgCARkTkSpRFEgAAALOb");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9bb3, "crc");
    
    is($msg->{'length'}, 16, "length");
    
    is($msg->{'msg_type'}, 0x14, "msg_type");
    
    is($msg->{'payload'}, "5BsPQgCARkTkSpRFEgAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), 4745.361328125, "cf");
    
    is($msg->cp(), 794.0, "cp");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":18}})), "sid");
    
    is($msg->snr(), 35.77723693847656, "snr");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":4745.361328125,"cp":794.0,"crc":39859,"length":16,"msg_type":20,"payload":"5BsPQgCARkTkSpRFEgAAAA==","preamble":85,"sender":55286,"sid":{"code":0,"reserved":0,"sat":18},"snr":35.77723693847656}})), "raw_json");
}
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_b_4() {
    my $buf = decode_base64("VRQA9tcQLscOQgBAgUPwGBxFEQAAABK1");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb512, "crc");
    
    is($msg->{'length'}, 16, "length");
    
    is($msg->{'msg_type'}, 0x14, "msg_type");
    
    is($msg->{'payload'}, "LscOQgBAgUPwGBxFEQAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), 2497.55859375, "cf");
    
    is($msg->cp(), 258.5, "cp");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":17}})), "sid");
    
    is($msg->snr(), 35.69451141357422, "snr");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":2497.55859375,"cp":258.5,"crc":46354,"length":16,"msg_type":20,"payload":"LscOQgBAgUPwGBxFEQAAAA==","preamble":85,"sender":55286,"sid":{"code":0,"reserved":0,"sat":17},"snr":35.69451141357422}})), "raw_json");
}
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_b_5() {
    my $buf = decode_base64("VRQA9tcQwhgOQgCAAkSBwfnDBQAAACPL");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xcb23, "crc");
    
    is($msg->{'length'}, 16, "length");
    
    is($msg->{'msg_type'}, 0x14, "msg_type");
    
    is($msg->{'payload'}, "whgOQgCAAkSBwfnDBQAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd7f6, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), -499.5117492675781, "cf");
    
    is($msg->cp(), 522.0, "cp");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":5}})), "sid");
    
    is($msg->snr(), 35.52417755126953, "snr");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":-499.5117492675781,"cp":522.0,"crc":52003,"length":16,"msg_type":20,"payload":"whgOQgCAAkSBwfnDBQAAAA==","preamble":85,"sender":55286,"sid":{"code":0,"reserved":0,"sat":5},"snr":35.52417755126953}})), "raw_json");
}
test_auto_check_sbp_acquisition_msg_acq_result_dep_b_1();
test_auto_check_sbp_acquisition_msg_acq_result_dep_b_2();
test_auto_check_sbp_acquisition_msg_acq_result_dep_b_3();
test_auto_check_sbp_acquisition_msg_acq_result_dep_b_4();
test_auto_check_sbp_acquisition_msg_acq_result_dep_b_5();

done_testing();