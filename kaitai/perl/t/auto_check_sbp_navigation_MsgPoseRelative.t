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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPoseRelative.yaml
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
sub test_auto_check_sbp_navigation_msg_pose_relative_1() {
    my $buf = decode_base64("VUUCQgBaVgQAAABWBAAArAgAAEwEAAAmAgAAZAAAAGQDyMz8qJ3/czW6kL4wIiUAAIA/AAAAAAAAAAAAAIA/AAAAAAAAgD8AAABAAAAAAAAAAAAAAABAAAAAAAAAAEAFq7s=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xBBAB, "crc");
    
    is($msg->{'length'}, 90, "length");
    
    is($msg->{'msg_type'}, 0x245, "msg_type");
    
    is($msg->{'payload'}, "VgQAAABWBAAArAgAAEwEAAAmAgAAZAAAAGQDyMz8qJ3/czW6kL4wIiUAAIA/AAAAAAAAAAAAAIA/AAAAAAAAgD8AAABAAAAAAAAAAAAAAABAAAAAAAAAAEAF", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cov_c_x_x(), 2.0, "cov_c_x_x");
    
    is($msg->cov_c_x_y(), 0.0, "cov_c_x_y");
    
    is($msg->cov_c_x_z(), 0.0, "cov_c_x_z");
    
    is($msg->cov_c_y_y(), 2.0, "cov_c_y_y");
    
    is($msg->cov_c_y_z(), 0.0, "cov_c_y_z");
    
    is($msg->cov_c_z_z(), 2.0, "cov_c_z_z");
    
    is($msg->cov_r_x_x(), 1.0, "cov_r_x_x");
    
    is($msg->cov_r_x_y(), 0.0, "cov_r_x_y");
    
    is($msg->cov_r_x_z(), 0.0, "cov_r_x_z");
    
    is($msg->cov_r_y_y(), 1.0, "cov_r_y_y");
    
    is($msg->cov_r_y_z(), 0.0, "cov_r_y_z");
    
    is($msg->cov_r_z_z(), 1.0, "cov_r_z_z");
    
    is($msg->flags(), 5, "flags");
    
    is($msg->sensor_id(), 0, "sensor_id");
    
    is($msg->timestamp_1(), 1110, "timestamp_1");
    
    is($msg->timestamp_2(), 2220, "timestamp_2");
    
    is($msg->tow(), 1110, "tow");
    
    is($json->encode($msg->trans()), $json->encode($json->decode(q{[1100,550,100]})), "trans");
    
    is($msg->w(), -859307164, "w");
    
    is($msg->x(), -6444804, "x");
    
    is($msg->y(), -1866844813, "y");
    
    is($msg->z(), 622997694, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"cov_c_x_x":2.0,"cov_c_x_y":0.0,"cov_c_x_z":0.0,"cov_c_y_y":2.0,"cov_c_y_z":0.0,"cov_c_z_z":2.0,"cov_r_x_x":1.0,"cov_r_x_y":0.0,"cov_r_x_z":0.0,"cov_r_y_y":1.0,"cov_r_y_z":0.0,"cov_r_z_z":1.0,"crc":48043,"flags":5,"length":90,"msg_type":581,"payload":"VgQAAABWBAAArAgAAEwEAAAmAgAAZAAAAGQDyMz8qJ3/czW6kL4wIiUAAIA/AAAAAAAAAAAAAIA/AAAAAAAAgD8AAABAAAAAAAAAAAAAAABAAAAAAAAAAEAF","preamble":85,"sender":66,"sensor_id":0,"timestamp_1":1110,"timestamp_2":2220,"tow":1110,"trans":[1100,550,100],"w":-859307164,"x":-6444804,"y":-1866844813,"z":622997694}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_pose_relative_1();

done_testing();