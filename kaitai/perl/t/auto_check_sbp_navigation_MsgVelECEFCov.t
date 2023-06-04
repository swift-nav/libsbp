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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEFCov.yaml
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
use t::Utils;
sub test_auto_check_sbp_navigation_msg_vel_ecef_cov_1() {
    my $buf = decode_base64("VRUCQgAqAgAAAAAAAAAAAAAABgAAAAAAAEAAAABAAAAAQAAAAEAAAIA/AABAQAMEW/4=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xfe5b, "crc");
    
    is($msg->{'length'}, 42, "length");
    
    is($msg->{'msg_type'}, 0x215, "msg_type");
    
    is($msg->{'payload'}, "AgAAAAAAAAAAAAAABgAAAAAAAEAAAABAAAAAQAAAAEAAAIA/AABAQAME", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cov_x_x(), 2.0, "cov_x_x");
    
    is($msg->cov_x_y(), 2.0, "cov_x_y");
    
    is($msg->cov_x_z(), 2.0, "cov_x_z");
    
    is($msg->cov_y_y(), 2.0, "cov_y_y");
    
    is($msg->cov_y_z(), 1.0, "cov_y_z");
    
    is($msg->cov_z_z(), 3.0, "cov_z_z");
    
    is($msg->flags(), 4, "flags");
    
    is($msg->n_sats(), 3, "n_sats");
    
    is($msg->tow(), 2, "tow");
    
    is($msg->x(), 0, "x");
    
    is($msg->y(), 0, "y");
    
    is($msg->z(), 6, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"cov_x_x":2,"cov_x_y":2,"cov_x_z":2,"cov_y_y":2,"cov_y_z":1,"cov_z_z":3,"crc":65115,"flags":4,"length":42,"msg_type":533,"n_sats":3,"payload":"AgAAAAAAAAAAAAAABgAAAAAAAEAAAABAAAAAQAAAAEAAAIA/AABAQAME","preamble":85,"sender":66,"tow":2,"x":0,"y":0,"z":6}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_vel_ecef_cov_1();

done_testing();