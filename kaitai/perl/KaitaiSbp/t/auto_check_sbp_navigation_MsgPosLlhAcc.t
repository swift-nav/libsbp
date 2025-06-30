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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhAcc.yaml
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
sub test_auto_check_sbp_navigation_msg_pos_llh_acc_1() {
    my $buf = decode_base64("VRgCAhxDJ3huEjMzMzMzi71AmpmZmRmXwEAzMzMzM6GwQDMzMzMzZbNAM6MWRZoZrUVmhvNEmsnERc3gAEYzI0hFM2MfRV8bSNyx");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb1dc, "crc");
    
    is($msg->{'length'}, 67, "length");
    
    is($msg->{'msg_type'}, 0x218, "msg_type");
    
    is($msg->{'payload'}, "J3huEjMzMzMzi71AmpmZmRmXwEAzMzMzM6GwQDMzMzMzZbNAM6MWRZoZrUVmhvNEmsnERc3gAEYzI0hFM2MfRV8bSA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1c02, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->at_accuracy(), 6297.2001953125, "at_accuracy");
    
    is($msg->confidence_and_geoid(), 95, "confidence_and_geoid");
    
    is($msg->ct_accuracy(), 1948.199951171875, "ct_accuracy");
    
    is($msg->flags(), 72, "flags");
    
    is($msg->h_accuracy(), 2410.199951171875, "h_accuracy");
    
    is($json->encode($msg->h_ellipse()), $json->encode($json->decode(q{{"orientation":2550.199951171875,"semi_major":8248.2001953125,"semi_minor":3202.199951171875}})), "h_ellipse");
    
    is($msg->height(), 4257.2, "height");
    
    is($msg->lat(), 7563.2, "lat");
    
    is($msg->lon(), 8494.2, "lon");
    
    is($msg->n_sats(), 27, "n_sats");
    
    is($msg->orthometric_height(), 4965.2, "orthometric_height");
    
    is($msg->tow(), 309229607, "tow");
    
    is($msg->v_accuracy(), 5539.2001953125, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"at_accuracy":6297.2001953125,"confidence_and_geoid":95,"crc":45532,"ct_accuracy":1948.199951171875,"flags":72,"h_accuracy":2410.199951171875,"h_ellipse":{"orientation":2550.199951171875,"semi_major":8248.2001953125,"semi_minor":3202.199951171875},"height":4257.2,"lat":7563.2,"length":67,"lon":8494.2,"msg_type":536,"n_sats":27,"orthometric_height":4965.2,"payload":"J3huEjMzMzMzi71AmpmZmRmXwEAzMzMzM6GwQDMzMzMzZbNAM6MWRZoZrUVmhvNEmsnERc3gAEYzI0hFM2MfRV8bSA==","preamble":85,"sender":7170,"tow":309229607,"v_accuracy":5539.2001953125}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_pos_llh_acc_1();

done_testing();
