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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIqDepB.yaml
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
sub test_auto_check_sbp_tracking_msg_tracking_iq_dep_b_1() {
    my $buf = decode_base64("VSwAJ2UbLby3SLmdD7v5ZRiHkrTge+uO0GZwGRWxYHRE9pk=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x99f6, "crc");
    
    is($msg->{'length'}, 27, "length");
    
    is($msg->{'msg_type'}, 0x2c, "msg_type");
    
    is($msg->{'payload'}, "Lby3SLmdD7v5ZRiHkrTge+uO0GZwGRWxYHRE", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x6527, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->channel(), 45, "channel");
    
    is($json->encode($msg->corrs()), $json->encode($json->decode(q{[{"i":261994824,"q":409336251},{"i":-525036921,"q":-795939973},{"i":353988710,"q":1148477617}]})), "corrs");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":183,"sat":188}})), "sid");

    is($json->encode($msg), $json->encode($json->decode(q{{"channel":45,"corrs":[{"i":261994824,"q":409336251},{"i":-525036921,"q":-795939973},{"i":353988710,"q":1148477617}],"crc":39414,"length":27,"msg_type":44,"payload":"Lby3SLmdD7v5ZRiHkrTge+uO0GZwGRWxYHRE","preamble":85,"sender":25895,"sid":{"code":183,"sat":188}}})), "raw_json");
}
test_auto_check_sbp_tracking_msg_tracking_iq_dep_b_1();

done_testing();