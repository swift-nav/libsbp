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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagIonoGridPointSatLos.yaml
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
sub test_auto_check_sbp_integrity_msg_ssr_flag_iono_grid_point_sat_los_1() {
    my $buf = decode_base64("VdELQgAVtAAAAAMAAQIDBAAFAAYeAAIKCw8OYpQ=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'msg_type'}, 0x0BD1, "msg_type");
    
    is($msg->{'sender'}, 0x0042, "sender");
    
    is($msg->{'length'}, 21, "length");
    
    is($msg->{'payload'}, "tAAAAAMAAQIDBAAFAAYeAAIKCw8O", "payload");
    
    is($msg->{'crc'}, 0x9462, "crc");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->faulty_los()), $json->encode($json->decode(q{[{"constellation":11,"sat_id":10},{"constellation":14,"sat_id":15}]})), "faulty_los");
    
    is($msg->grid_point_id(), 30, "grid_point_id");
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"chain_id":6,"num_msgs":1,"obs_time":{"tow":180,"wn":3},"seq_num":2,"ssr_sol_id":3,"tile_id":5,"tile_set_id":4}})), "header");
    
    is($msg->n_faulty_los(), 2, "n_faulty_los");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":37986,"faulty_los":[{"constellation":11,"sat_id":10},{"constellation":14,"sat_id":15}],"grid_point_id":30,"header":{"chain_id":6,"num_msgs":1,"obs_time":{"tow":180,"wn":3},"seq_num":2,"ssr_sol_id":3,"tile_id":5,"tile_set_id":4},"length":21,"msg_type":3025,"n_faulty_los":2,"payload":"tAAAAAMAAQIDBAAFAAYeAAIKCw8O","preamble":85,"sender":66}})), "raw_json");
}
test_auto_check_sbp_integrity_msg_ssr_flag_iono_grid_point_sat_los_1();

done_testing();
