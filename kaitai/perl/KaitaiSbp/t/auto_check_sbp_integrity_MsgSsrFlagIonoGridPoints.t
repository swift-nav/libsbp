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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagIonoGridPoints.yaml
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
sub test_auto_check_sbp_integrity_msg_ssr_flag_iono_grid_points_1() {
    my $buf = decode_base64("VccLQgAVtAAAAAMAAQIDBAAFAAYDCgALAAwANQc=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'msg_type'}, 0x0BC7, "msg_type");
    
    is($msg->{'sender'}, 0x0042, "sender");
    
    is($msg->{'length'}, 21, "length");
    
    is($msg->{'payload'}, "tAAAAAMAAQIDBAAFAAYDCgALAAwA", "payload");
    
    is($msg->{'crc'}, 0x0735, "crc");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->faulty_points()), $json->encode($json->decode(q{[10,11,12]})), "faulty_points");
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"chain_id":6,"num_msgs":1,"obs_time":{"tow":180,"wn":3},"seq_num":2,"ssr_sol_id":3,"tile_id":5,"tile_set_id":4}})), "header");
    
    is($msg->n_faulty_points(), 3, "n_faulty_points");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":1845,"faulty_points":[10,11,12],"header":{"chain_id":6,"num_msgs":1,"obs_time":{"tow":180,"wn":3},"seq_num":2,"ssr_sol_id":3,"tile_id":5,"tile_set_id":4},"length":21,"msg_type":3015,"n_faulty_points":3,"payload":"tAAAAAMAAQIDBAAFAAYDCgALAAwA","preamble":85,"sender":66}})), "raw_json");
}
test_auto_check_sbp_integrity_msg_ssr_flag_iono_grid_points_1();

done_testing();