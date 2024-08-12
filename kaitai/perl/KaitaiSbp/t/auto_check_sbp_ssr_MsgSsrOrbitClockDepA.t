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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockDepA.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_orbit_clock_dep_a_1() {
    my $buf = decode_base64("VdwFIaYv4XIfvSseAR7C08GvoY/+OD/oB9hFAW6lfMS9G3RYBD0DlxKrky7GVfP14et7tdKd/A==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xfc9d, "crc");
    
    is($msg->{'length'}, 47, "length");
    
    is($msg->{'msg_type'}, 0x5dc, "msg_type");
    
    is($msg->{'payload'}, "4XIfvSseAR7C08GvoY/+OD/oB9hFAW6lfMS9G3RYBD0DlxKrky7GVfP14et7tdI=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xa621, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->along(), 132661048, "along");
    
    is($msg->c0(), -970026069, "c0");
    
    is($msg->c1(), -503975083, "c1");
    
    is($msg->c2(), -759858197, "c2");
    
    is($msg->cross(), 1845577176, "cross");
    
    is($msg->dot_along(), 72905755, "dot_along");
    
    is($msg->dot_cross(), 311886653, "dot_cross");
    
    is($msg->dot_radial(), -1111196507, "dot_radial");
    
    is($msg->iod(), 193, "iod");
    
    is($msg->iod_ssr(), 211, "iod_ssr");
    
    is($msg->radial(), -24141393, "radial");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":30,"sat":1}})), "sid");
    
    is($json->encode($msg->time()), $json->encode($json->decode(q{{"tow":3172954849,"wn":7723}})), "time");
    
    is($msg->update_interval(), 194, "update_interval");

    is($json->encode($msg), $json->encode($json->decode(q{{"along":132661048,"c0":-970026069,"c1":-503975083,"c2":-759858197,"crc":64669,"cross":1845577176,"dot_along":72905755,"dot_cross":311886653,"dot_radial":-1111196507,"iod":193,"iod_ssr":211,"length":47,"msg_type":1500,"payload":"4XIfvSseAR7C08GvoY/+OD/oB9hFAW6lfMS9G3RYBD0DlxKrky7GVfP14et7tdI=","preamble":85,"radial":-24141393,"sender":42529,"sid":{"code":30,"sat":1},"time":{"tow":3172954849,"wn":7723},"update_interval":194}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_orbit_clock_dep_a_1();

done_testing();