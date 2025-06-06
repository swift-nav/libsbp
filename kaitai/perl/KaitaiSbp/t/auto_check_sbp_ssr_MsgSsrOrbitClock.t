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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClock.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_orbit_clock_1() {
    my $buf = decode_base64("Vd0FNeUyU9Bmz6Qdy9Ts/5jpzzdeNjqARBt1sG77PfR6Ml80kOgYCiV/o0KxaZz1Cvlr2hG6OEgOFg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x160e, "crc");
    
    is($msg->{'length'}, 50, "length");
    
    is($msg->{'msg_type'}, 0x5dd, "msg_type");
    
    is($msg->{'payload'}, "U9Bmz6Qdy9Ts/5jpzzdeNjqARBt1sG77PfR6Ml80kOgYCiV/o0KxaZz1Cvlr2hG6OEg=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xe535, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->along(), -1334502588, "along");
    
    is($msg->c0(), -174298703, "c0");
    
    is($msg->c1(), -630458102, "c1");
    
    is($msg->c2(), 1211677201, "c2");
    
    is($msg->cross(), -197264530, "cross");
    
    is($msg->dot_along(), 169404560, "dot_along");
    
    is($msg->dot_cross(), 1118011173, "dot_cross");
    
    is($msg->dot_radial(), 878654074, "dot_radial");
    
    is($msg->iod(), 936372632, "iod");
    
    is($msg->iod_ssr(), 255, "iod_ssr");
    
    is($msg->radial(), -2143668642, "radial");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":212,"sat":203}})), "sid");
    
    is($json->encode($msg->time()), $json->encode($json->decode(q{{"tow":3479621715,"wn":7588}})), "time");
    
    is($msg->update_interval(), 236, "update_interval");

    is($json->encode($msg), $json->encode($json->decode(q{{"along":-1334502588,"c0":-174298703,"c1":-630458102,"c2":1211677201,"crc":5646,"cross":-197264530,"dot_along":169404560,"dot_cross":1118011173,"dot_radial":878654074,"iod":936372632,"iod_ssr":255,"length":50,"msg_type":1501,"payload":"U9Bmz6Qdy9Ts/5jpzzdeNjqARBt1sG77PfR6Ml80kOgYCiV/o0KxaZz1Cvlr2hG6OEg=","preamble":85,"radial":-2143668642,"sender":58677,"sid":{"code":212,"sat":203},"time":{"tow":3479621715,"wn":7588},"update_interval":236}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_orbit_clock_1();

done_testing();
