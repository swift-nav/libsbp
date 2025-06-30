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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNEDCOV.yaml
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
sub test_auto_check_sbp_navigation_msg_vel_nedcov_1() {
    my $buf = decode_base64("VRICQgAqZAAAAAEAAAABAAAAAQAAAAAAgD8AAIA/AACAPwAAgD8AAIA/AACAPwoAWM0=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'payload'}, "ZAAAAAEAAAABAAAAAQAAAAAAgD8AAIA/AACAPwAAgD8AAIA/AACAPwoA", "payload");
    
    is($msg->{'crc'}, 0xCD58, "crc");
    
    is($msg->{'length'}, 42, "length");
    
    is($msg->{'msg_type'}, 0x212, "msg_type");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cov_d_d(), 1.0, "cov_d_d");
    
    is($msg->cov_e_d(), 1.0, "cov_e_d");
    
    is($msg->cov_e_e(), 1.0, "cov_e_e");
    
    is($msg->cov_n_d(), 1.0, "cov_n_d");
    
    is($msg->cov_n_e(), 1.0, "cov_n_e");
    
    is($msg->cov_n_n(), 1.0, "cov_n_n");
    
    is($msg->d(), 1, "d");
    
    is($msg->e(), 1, "e");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n(), 1, "n");
    
    is($msg->n_sats(), 10, "n_sats");
    
    is($msg->tow(), 100, "tow");

    is($json->encode($msg), $json->encode($json->decode(q{{"cov_d_d":1,"cov_e_d":1,"cov_e_e":1,"cov_n_d":1,"cov_n_e":1,"cov_n_n":1,"crc":52568,"d":1,"e":1,"flags":0,"length":42,"msg_type":530,"n":1,"n_sats":10,"payload":"ZAAAAAEAAAABAAAAAQAAAAAAgD8AAIA/AACAPwAAgD8AAIA/AACAPwoA","preamble":85,"sender":66,"tow":100}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_vel_nedcov_1();

done_testing();
