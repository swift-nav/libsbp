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

use KaitaiSbp::Sbp;
use KaitaiSbp::ParseUtils;
use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_navigation_msg_protection_level_1() {
    my $buf = decode_base64("VRcCLQNMblQE8i4zNaBZVKcpORXZ9D2hU2iMiVr2MzMzMzOqtECamZmZGVjDQDMzMzMzw3lA5/sm3dC3p1DfGmGkLS66POvjt6C7XXTgaSggIYW8");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xbc85, "crc");
    
    is($msg->{'length'}, 76, "length");
    
    is($msg->{'msg_type'}, 0x217, "msg_type");
    
    is($msg->{'payload'}, "blQE8i4zNaBZVKcpORXZ9D2hU2iMiVr2MzMzMzOqtECamZmZGVjDQDMzMzMzw3lA5/sm3dC3p1DfGmGkLS66POvjt6C7XXTgaSggIQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x032d, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->atpl(), 10663, "atpl");
    
    is($msg->ctpl(), 5433, "ctpl");
    
    is($msg->flags(), 555755625, "flags");
    
    is($msg->heading(), -529244741, "heading");
    
    is($msg->height(), 412.2, "height");
    
    is($msg->hopl(), 26707, "hopl");
    
    is($msg->hpl(), 41013, "hpl");
    
    is($msg->hvpl(), 62681, "hvpl");
    
    is($msg->lat(), 5290.2, "lat");
    
    is($msg->lon(), 9904.2, "lon");
    
    is($msg->pitch(), -1598561301, "pitch");
    
    is($msg->popl(), 35212, "popl");
    
    is($msg->roll(), 1018834477, "roll");
    
    is($msg->ropl(), 63066, "ropl");
    
    is($msg->tow(), 4060370030, "tow");
    
    is($msg->v_x(), -584647705, "v_x");
    
    is($msg->v_y(), 1353168848, "v_y");
    
    is($msg->v_z(), -1537140001, "v_z");
    
    is($msg->vpl(), 21593, "vpl");
    
    is($msg->vvpl(), 41277, "vvpl");
    
    is($msg->wn(), 13102, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"atpl":10663,"crc":48261,"ctpl":5433,"flags":555755625,"heading":-529244741,"height":412.2,"hopl":26707,"hpl":41013,"hvpl":62681,"lat":5290.2,"length":76,"lon":9904.2,"msg_type":535,"payload":"blQE8i4zNaBZVKcpORXZ9D2hU2iMiVr2MzMzMzOqtECamZmZGVjDQDMzMzMzw3lA5/sm3dC3p1DfGmGkLS66POvjt6C7XXTgaSggIQ==","pitch":-1598561301,"popl":35212,"preamble":85,"roll":1018834477,"ropl":63066,"sender":813,"tow":4060370030,"v_x":-584647705,"v_y":1353168848,"v_z":-1537140001,"vpl":21593,"vvpl":41277,"wn":13102}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_protection_level_1();

done_testing();