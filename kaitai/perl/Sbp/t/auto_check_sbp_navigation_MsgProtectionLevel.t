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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevel.yaml
# with generate.py.  Do not modify by hand!

use strict;

BEGIN {
    # add grandparent directory to include path
    use Cwd qw(realpath);
    use File::Basename;
    unshift @INC, realpath(dirname($0))."/../../";
}

use Sbp::Sbp;
use Sbp::ParseUtils;
use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_navigation_msg_protection_level_1() {
    my $buf = decode_base64("VRYCABAhiOPpHQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAUsM=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xc352, "crc");
    
    is($msg->{'length'}, 33, "length");
    
    is($msg->{'payload'}, "iOPpHQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", "payload");
    
    is($msg->{'msg_type'}, 0x216, "msg_type");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1000, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->height(), 0.0, "height");
    
    is($msg->hpl(), 0, "hpl");
    
    is($msg->lat(), 0.0, "lat");
    
    is($msg->lon(), 0.0, "lon");
    
    is($msg->tow(), 501867400, "tow");
    
    is($msg->vpl(), 0, "vpl");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":50002,"flags":0,"height":0.0,"hpl":0,"lat":0.0,"length":33,"lon":0.0,"msg_type":534,"payload":"iOPpHQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","preamble":85,"sender":4096,"tow":501867400,"vpl":0}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_protection_level_1();

done_testing();