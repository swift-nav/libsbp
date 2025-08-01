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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgMaskSatelliteDep.yaml
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
sub test_auto_check_sbp_piksi_msg_mask_satellite_dep_1() {
    my $buf = decode_base64("VRsAu4YFIQKZXwQdvA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xbc1d, "crc");
    
    is($msg->{'length'}, 5, "length");
    
    is($msg->{'msg_type'}, 0x1b, "msg_type");
    
    is($msg->{'payload'}, "IQKZXwQ=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x86bb, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->mask(), 33, "mask");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":95,"reserved":4,"sat":39170}})), "sid");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":48157,"length":5,"mask":33,"msg_type":27,"payload":"IQKZXwQ=","preamble":85,"sender":34491,"sid":{"code":95,"reserved":4,"sat":39170}}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_mask_satellite_dep_1();

done_testing();
