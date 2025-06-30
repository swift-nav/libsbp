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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuComp.yaml
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
sub test_auto_check_sbp_imu_msg_imu_comp_1() {
    my $buf = decode_base64("VQUJNBIiGgEAwAAAAADOAGAAAADf////LBAAADwAAADQ/v//7v///09W");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x564f, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x905, "msg_type");
    
    is($msg->{'payload'}, "GgEAwAAAAADOAGAAAADf////LBAAADwAAADQ/v//7v///w==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1234, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->acc_comp_x(), 96, "acc_comp_x");
    
    is($msg->acc_comp_y(), -33, "acc_comp_y");
    
    is($msg->acc_comp_z(), 4140, "acc_comp_z");
    
    is($msg->flags(), 206, "flags");
    
    is($msg->gyr_comp_x(), 60, "gyr_comp_x");
    
    is($msg->gyr_comp_y(), -304, "gyr_comp_y");
    
    is($msg->gyr_comp_z(), -18, "gyr_comp_z");
    
    is($msg->time(), 3221225754, "time");

    is($json->encode($msg), $json->encode($json->decode(q{{"acc_comp_x":96,"acc_comp_y":-33,"acc_comp_z":4140,"crc":22095,"flags":206,"gyr_comp_x":60,"gyr_comp_y":-304,"gyr_comp_z":-18,"length":34,"msg_type":2309,"payload":"GgEAwAAAAADOAGAAAADf////LBAAADwAAADQ/v//7v///w==","preamble":85,"sender":4660,"time":3221225754}})), "raw_json");
}
test_auto_check_sbp_imu_msg_imu_comp_1();

done_testing();
