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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevelDepA.yaml
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
sub test_auto_check_sbp_navigation_msg_protection_level_dep_a_1() {
    my $buf = decode_base64("VRYClBYhNH5FuS9VBIszMzMzM/S+QGZmZmZmzKhAmpmZmRknwED4UWg=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6851, "crc");
    
    is($msg->{'length'}, 33, "length");
    
    is($msg->{'msg_type'}, 0x216, "msg_type");
    
    is($msg->{'payload'}, "NH5FuS9VBIszMzMzM/S+QGZmZmZmzKhAmpmZmRknwED4", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1694, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 248, "flags");
    
    is($msg->height(), 8270.2, "height");
    
    is($msg->hpl(), 35588, "hpl");
    
    is($msg->lat(), 7924.2, "lat");
    
    is($msg->lon(), 3174.2, "lon");
    
    is($msg->tow(), 3108339252, "tow");
    
    is($msg->vpl(), 21807, "vpl");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":26705,"flags":248,"height":8270.2,"hpl":35588,"lat":7924.2,"length":33,"lon":3174.2,"msg_type":534,"payload":"NH5FuS9VBIszMzMzM/S+QGZmZmZmzKhAmpmZmRknwED4","preamble":85,"sender":5780,"tow":3108339252,"vpl":21807}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_protection_level_dep_a_1();

done_testing();