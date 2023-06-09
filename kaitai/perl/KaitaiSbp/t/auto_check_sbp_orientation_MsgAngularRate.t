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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgAngularRate.yaml
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
sub test_auto_check_sbp_orientation_msg_angular_rate_1() {
    my $buf = decode_base64("VSICQgARAgAAAAIAAAAFAAAAAgAAAABYRg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x4658, "crc");
    
    is($msg->{'length'}, 17, "length");
    
    is($msg->{'msg_type'}, 0x222, "msg_type");
    
    is($msg->{'payload'}, "AgAAAAIAAAAFAAAAAgAAAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->tow(), 2, "tow");
    
    is($msg->x(), 2, "x");
    
    is($msg->y(), 5, "y");
    
    is($msg->z(), 2, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":18008,"flags":0,"length":17,"msg_type":546,"payload":"AgAAAAIAAAAFAAAAAgAAAAA=","preamble":85,"sender":66,"tow":2,"x":2,"y":5,"z":2}})), "raw_json");
}
test_auto_check_sbp_orientation_msg_angular_rate_1();

done_testing();