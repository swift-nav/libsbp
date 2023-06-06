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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCov.yaml
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
sub test_auto_check_sbp_navigation_msg_pos_ecef_cov_1() {
    my $buf = decode_base64("VRQCQgA2BwAAAAAAAAAAABhAAAAAAAAA8D8AAAAAAAAQQAAAAEEAAOBAAAAAQAAAwEAAAABBAACgQAQF+ac=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa7f9, "crc");
    
    is($msg->{'length'}, 54, "length");
    
    is($msg->{'msg_type'}, 0x214, "msg_type");
    
    is($msg->{'payload'}, "BwAAAAAAAAAAABhAAAAAAAAA8D8AAAAAAAAQQAAAAEEAAOBAAAAAQAAAwEAAAABBAACgQAQF", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cov_x_x(), 8.0, "cov_x_x");
    
    is($msg->cov_x_y(), 7.0, "cov_x_y");
    
    is($msg->cov_x_z(), 2.0, "cov_x_z");
    
    is($msg->cov_y_y(), 6.0, "cov_y_y");
    
    is($msg->cov_y_z(), 8.0, "cov_y_z");
    
    is($msg->cov_z_z(), 5.0, "cov_z_z");
    
    is($msg->flags(), 5, "flags");
    
    is($msg->n_sats(), 4, "n_sats");
    
    is($msg->tow(), 7, "tow");
    
    is($msg->x(), 6.0, "x");
    
    is($msg->y(), 1.0, "y");
    
    is($msg->z(), 4.0, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"cov_x_x":8,"cov_x_y":7,"cov_x_z":2,"cov_y_y":6,"cov_y_z":8,"cov_z_z":5,"crc":43001,"flags":5,"length":54,"msg_type":532,"n_sats":4,"payload":"BwAAAAAAAAAAABhAAAAAAAAA8D8AAAAAAAAQQAAAAEEAAOBAAAAAQAAAwEAAAABBAACgQAQF","preamble":85,"sender":66,"tow":7,"x":6,"y":1,"z":4}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_pos_ecef_cov_1();

done_testing();