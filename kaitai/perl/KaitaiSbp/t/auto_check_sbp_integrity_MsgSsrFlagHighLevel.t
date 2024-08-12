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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagHighLevel.yaml
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
sub test_auto_check_sbp_integrity_msg_ssr_flag_high_level_1() {
    my $buf = decode_base64("VbkLQgAftAAAAAMAaAEAAAYAChQAHgAoAQIDBAAAAAAABQYHCGkD");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'msg_type'}, 0x0BB9, "msg_type");
    
    is($msg->{'sender'}, 0x0042, "sender");
    
    is($msg->{'length'}, 31, "length");
    
    is($msg->{'payload'}, "tAAAAAMAaAEAAAYAChQAHgAoAQIDBAAAAAAABQYHCA==", "payload");
    
    is($msg->{'crc'}, 0x0369, "crc");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->chain_id(), 40, "chain_id");
    
    is($json->encode($msg->corr_time()), $json->encode($json->decode(q{{"tow":360,"wn":6}})), "corr_time");
    
    is($json->encode($msg->obs_time()), $json->encode($json->decode(q{{"tow":180,"wn":3}})), "obs_time");
    
    is($json->encode($msg->reserved()), $json->encode($json->decode(q{[0,0,0,0,0]})), "reserved");
    
    is($msg->ssr_sol_id(), 10, "ssr_sol_id");
    
    is($msg->tile_id(), 30, "tile_id");
    
    is($msg->tile_set_id(), 20, "tile_set_id");
    
    is($msg->use_bds_sat(), 3, "use_bds_sat");
    
    is($msg->use_gal_sat(), 2, "use_gal_sat");
    
    is($msg->use_gps_sat(), 1, "use_gps_sat");
    
    is($msg->use_iono_grid_point_sat_los(), 8, "use_iono_grid_point_sat_los");
    
    is($msg->use_iono_grid_points(), 6, "use_iono_grid_points");
    
    is($msg->use_iono_tile_sat_los(), 7, "use_iono_tile_sat_los");
    
    is($msg->use_qzss_sat(), 4, "use_qzss_sat");
    
    is($msg->use_tropo_grid_points(), 5, "use_tropo_grid_points");

    is($json->encode($msg), $json->encode($json->decode(q{{"chain_id":40,"corr_time":{"tow":360,"wn":6},"crc":873,"length":31,"msg_type":3001,"obs_time":{"tow":180,"wn":3},"payload":"tAAAAAMAaAEAAAYAChQAHgAoAQIDBAAAAAAABQYHCA==","preamble":85,"reserved":[0,0,0,0,0],"sender":66,"ssr_sol_id":10,"tile_id":30,"tile_set_id":20,"use_bds_sat":3,"use_gal_sat":2,"use_gps_sat":1,"use_iono_grid_point_sat_los":8,"use_iono_grid_points":6,"use_iono_tile_sat_los":7,"use_qzss_sat":4,"use_tropo_grid_points":5}})), "raw_json");
}
test_auto_check_sbp_integrity_msg_ssr_flag_high_level_1();

done_testing();