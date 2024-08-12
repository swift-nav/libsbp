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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNedCovGnss.yaml
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
sub test_auto_check_sbp_navigation_msg_vel_ned_cov_gnss_1() {
    my $buf = decode_base64("VTICABAqqObpHfv///8AAAAA9v///w86zzr4i3Q3Z8U5Ocu6gTptqyw5hycBPBUCmwM=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x39b, "crc");
    
    is($msg->{'length'}, 42, "length");
    
    is($msg->{'msg_type'}, 0x232, "msg_type");
    
    is($msg->{'payload'}, "qObpHfv///8AAAAA9v///w86zzr4i3Q3Z8U5Ocu6gTptqyw5hycBPBUC", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1000, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cov_d_d(), 0.007882959209382534, "cov_d_d");
    
    is($msg->cov_e_d(), 0.00016467059322167188, "cov_e_d");
    
    is($msg->cov_e_e(), 0.0009897587588056922, "cov_e_e");
    
    is($msg->cov_n_d(), 0.00017716512957122177, "cov_n_d");
    
    is($msg->cov_n_e(), 1.457612233934924e-05, "cov_n_e");
    
    is($msg->cov_n_n(), 0.0015810149488970637, "cov_n_n");
    
    is($msg->d(), -10, "d");
    
    is($msg->e(), 0, "e");
    
    is($msg->flags(), 2, "flags");
    
    is($msg->n(), -5, "n");
    
    is($msg->n_sats(), 21, "n_sats");
    
    is($msg->tow(), 501868200, "tow");

    is($json->encode($msg), $json->encode($json->decode(q{{"cov_d_d":0.007882959209382534,"cov_e_d":0.00016467059322167188,"cov_e_e":0.0009897587588056922,"cov_n_d":0.00017716512957122177,"cov_n_e":1.457612233934924e-05,"cov_n_n":0.0015810149488970637,"crc":923,"d":-10,"e":0,"flags":2,"length":42,"msg_type":562,"n":-5,"n_sats":21,"payload":"qObpHfv///8AAAAA9v///w86zzr4i3Q3Z8U5Ocu6gTptqyw5hycBPBUC","preamble":85,"sender":4096,"tow":501868200}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_vel_ned_cov_gnss_1();

done_testing();