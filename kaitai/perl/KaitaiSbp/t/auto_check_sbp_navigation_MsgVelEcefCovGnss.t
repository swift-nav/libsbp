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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelEcefCovGnss.yaml
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
sub test_auto_check_sbp_navigation_msg_vel_ecef_cov_gnss_1() {
    my $buf = decode_base64("VTUCABAq4OXpHf3///8BAAAABAAAAC7gIDsg1g47lpPcuhM/ijsaliO7C8F3OxUCFuY=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe616, "crc");
    
    is($msg->{'length'}, 42, "length");
    
    is($msg->{'msg_type'}, 0x235, "msg_type");
    
    is($msg->{'payload'}, "4OXpHf3///8BAAAABAAAAC7gIDsg1g47lpPcuhM/ijsaliO7C8F3OxUC", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1000, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cov_x_x(), 0.0024547684006392956, "cov_x_x");
    
    is($msg->cov_x_y(), 0.0021795108914375305, "cov_x_y");
    
    is($msg->cov_x_z(), -0.0016828652005642653, "cov_x_z");
    
    is($msg->cov_y_y(), 0.004218944814056158, "cov_y_y");
    
    is($msg->cov_y_z(), -0.0024961293675005436, "cov_y_z");
    
    is($msg->cov_z_z(), 0.0037804271560162306, "cov_z_z");
    
    is($msg->flags(), 2, "flags");
    
    is($msg->n_sats(), 21, "n_sats");
    
    is($msg->tow(), 501868000, "tow");
    
    is($msg->x(), -3, "x");
    
    is($msg->y(), 1, "y");
    
    is($msg->z(), 4, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"cov_x_x":0.0024547684006392956,"cov_x_y":0.0021795108914375305,"cov_x_z":-0.0016828652005642653,"cov_y_y":0.004218944814056158,"cov_y_z":-0.0024961293675005436,"cov_z_z":0.0037804271560162306,"crc":58902,"flags":2,"length":42,"msg_type":565,"n_sats":21,"payload":"4OXpHf3///8BAAAABAAAAC7gIDsg1g47lpPcuhM/ijsaliO7C8F3OxUC","preamble":85,"sender":4096,"tow":501868000,"x":-3,"y":1,"z":4}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_vel_ecef_cov_gnss_1();

done_testing();