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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuRaw.yaml
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
sub test_auto_check_sbp_imu_msg_imu_raw_1() {
    my $buf = decode_base64("VQAJNBIRGgEAwM5gAN//LBA8AND+7v9Ghw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8746, "crc");
    
    is($msg->{'length'}, 17, "length");
    
    is($msg->{'msg_type'}, 0x900, "msg_type");
    
    is($msg->{'payload'}, "GgEAwM5gAN//LBA8AND+7v8=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1234, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->acc_x(), 96, "acc_x");
    
    is($msg->acc_y(), -33, "acc_y");
    
    is($msg->acc_z(), 4140, "acc_z");
    
    is($msg->gyr_x(), 60, "gyr_x");
    
    is($msg->gyr_y(), -304, "gyr_y");
    
    is($msg->gyr_z(), -18, "gyr_z");
    
    is($msg->tow(), 3221225754, "tow");
    
    is($msg->tow_f(), 206, "tow_f");

    is($json->encode($msg), $json->encode($json->decode(q{{"acc_x":96,"acc_y":-33,"acc_z":4140,"crc":34630,"gyr_x":60,"gyr_y":-304,"gyr_z":-18,"length":17,"msg_type":2304,"payload":"GgEAwM5gAN//LBA8AND+7v8=","preamble":85,"sender":4660,"tow":3221225754,"tow_f":206}})), "raw_json");
}
test_auto_check_sbp_imu_msg_imu_raw_1();

done_testing();