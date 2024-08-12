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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIqDepA.yaml
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
sub test_auto_check_sbp_tracking_msg_tracking_iq_dep_a_1() {
    my $buf = decode_base64("VRwAuEMdixz6DwBjWqpgR3khoTTTomUpJOJjR0sO8IZSr1MRIg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x2211, "crc");
    
    is($msg->{'length'}, 29, "length");
    
    is($msg->{'msg_type'}, 0x1c, "msg_type");
    
    is($msg->{'payload'}, "ixz6DwBjWqpgR3khoTTTomUpJOJjR0sO8IZSr1M=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x43b8, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->channel(), 139, "channel");
    
    is($json->encode($msg->corrs()), $json->encode($json->decode(q{[{"i":1621776995,"q":-1591641785},{"i":1705169716,"q":1675764777},{"i":-267498681,"q":1403998854}]})), "corrs");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":15,"reserved":0,"sat":64028}})), "sid");

    is($json->encode($msg), $json->encode($json->decode(q{{"channel":139,"corrs":[{"i":1621776995,"q":-1591641785},{"i":1705169716,"q":1675764777},{"i":-267498681,"q":1403998854}],"crc":8721,"length":29,"msg_type":28,"payload":"ixz6DwBjWqpgR3khoTTTomUpJOJjR0sO8IZSr1M=","preamble":85,"sender":17336,"sid":{"code":15,"reserved":0,"sat":64028}}})), "raw_json");
}
test_auto_check_sbp_tracking_msg_tracking_iq_dep_a_1();

done_testing();