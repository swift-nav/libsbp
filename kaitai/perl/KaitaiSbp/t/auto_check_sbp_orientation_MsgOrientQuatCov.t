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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientQuatCov.yaml
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
sub test_auto_check_sbp_orientation_msg_orient_quat_cov_1() {
    my $buf = decode_base64("VSMCQgAtAAAAAAMAAAAHAAAACAAAAAQAAAAAAIA/AAAAPwAAgD4AAABAAAAAPgAAgEABLkk=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x492E, "crc");
    
    is($msg->{'length'}, 45, "length");
    
    is($msg->{'msg_type'}, 0x223, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAMAAAAHAAAACAAAAAQAAAAAAIA/AAAAPwAAgD4AAABAAAAAPgAAgEAB", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cov_xx(), 1.0, "cov_xx");
    
    is($msg->cov_xy(), 0.5, "cov_xy");
    
    is($msg->cov_xz(), 0.25, "cov_xz");
    
    is($msg->cov_yy(), 2.0, "cov_yy");
    
    is($msg->cov_yz(), 0.125, "cov_yz");
    
    is($msg->cov_zz(), 4.0, "cov_zz");
    
    is($msg->flags(), 1, "flags");
    
    is($msg->tow(), 0, "tow");
    
    is($msg->w(), 3, "w");
    
    is($msg->x(), 7, "x");
    
    is($msg->y(), 8, "y");
    
    is($msg->z(), 4, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"cov_xx":1.0,"cov_xy":0.5,"cov_xz":0.25,"cov_yy":2.0,"cov_yz":0.125,"cov_zz":4.0,"crc":18734,"flags":1,"length":45,"msg_type":547,"payload":"AAAAAAMAAAAHAAAACAAAAAQAAAAAAIA/AAAAPwAAgD4AAABAAAAAPgAAgEAB","preamble":85,"sender":66,"tow":0,"w":3,"x":7,"y":8,"z":4}})), "raw_json");
}
test_auto_check_sbp_orientation_msg_orient_quat_cov_1();

done_testing();
