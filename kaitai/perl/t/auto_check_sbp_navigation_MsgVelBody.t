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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelBody.yaml
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
sub test_auto_check_sbp_navigation_msg_vel_body_1() {
    my $buf = decode_base64("VRMCQgAqAQAAAAQAAAACAAAAAQAAAAAAAAAAAKBAAADgQAAA4EAAAEBAAAAAQAMIeJA=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9078, "crc");
    
    is($msg->{'length'}, 42, "length");
    
    is($msg->{'msg_type'}, 0x213, "msg_type");
    
    is($msg->{'payload'}, "AQAAAAQAAAACAAAAAQAAAAAAAAAAAKBAAADgQAAA4EAAAEBAAAAAQAMI", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cov_x_x(), 0.0, "cov_x_x");
    
    is($msg->cov_x_y(), 5.0, "cov_x_y");
    
    is($msg->cov_x_z(), 7.0, "cov_x_z");
    
    is($msg->cov_y_y(), 7.0, "cov_y_y");
    
    is($msg->cov_y_z(), 3.0, "cov_y_z");
    
    is($msg->cov_z_z(), 2.0, "cov_z_z");
    
    is($msg->flags(), 8, "flags");
    
    is($msg->n_sats(), 3, "n_sats");
    
    is($msg->tow(), 1, "tow");
    
    is($msg->x(), 4, "x");
    
    is($msg->y(), 2, "y");
    
    is($msg->z(), 1, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"cov_x_x":0,"cov_x_y":5,"cov_x_z":7,"cov_y_y":7,"cov_y_z":3,"cov_z_z":2,"crc":36984,"flags":8,"length":42,"msg_type":531,"n_sats":3,"payload":"AQAAAAQAAAACAAAAAQAAAAAAAAAAAKBAAADgQAAA4EAAAEBAAAAAQAMI","preamble":85,"sender":66,"tow":1,"x":4,"y":2,"z":1}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_vel_body_1();

done_testing();