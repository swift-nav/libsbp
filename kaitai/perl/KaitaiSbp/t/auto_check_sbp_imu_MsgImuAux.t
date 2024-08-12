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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuAux.yaml
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
sub test_auto_check_sbp_imu_msg_imu_aux_1() {
    my $buf = decode_base64("VQEJNBIEAfQKQsj8");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xfcc8, "crc");
    
    is($msg->{'length'}, 4, "length");
    
    is($msg->{'msg_type'}, 0x901, "msg_type");
    
    is($msg->{'payload'}, "AfQKQg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1234, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->imu_conf(), 66, "imu_conf");
    
    is($msg->imu_type(), 1, "imu_type");
    
    is($msg->temp(), 2804, "temp");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":64712,"imu_conf":66,"imu_type":1,"length":4,"msg_type":2305,"payload":"AfQKQg==","preamble":85,"sender":4660,"temp":2804}})), "raw_json");
}
test_auto_check_sbp_imu_msg_imu_aux_1();

done_testing();