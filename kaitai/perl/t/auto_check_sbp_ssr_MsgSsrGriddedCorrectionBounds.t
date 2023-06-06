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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionBounds.yaml
# with generate.py.  Do not modify by hand!

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";

BEGIN {
    # add SBP_PATH to include path and load all modules
    unshift @INC, &SBP_PATH;
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_ssr_msg_ssr_gridded_correction_bounds_1() {
    my $buf = decode_base64("Vf4FQgAttAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQCBQoQABESExQVBgoWABcYGRob7LY=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'msg_type'}, 0x05FE, "msg_type");
    
    is($msg->{'sender'}, 0x0042, "sender");
    
    is($msg->{'length'}, 45, "length");
    
    is($msg->{'payload'}, "tAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQCBQoQABESExQVBgoWABcYGRob", "payload");
    
    is($msg->{'crc'}, 0xB6EC, "crc");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->grid_point_id(), 1000, "grid_point_id");
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"num_msgs":1,"seq_num":0,"sol_id":0,"time":{"tow":180,"wn":3},"update_interval":10}})), "header");
    
    is($msg->n_sats(), 2, "n_sats");
    
    is($msg->ssr_iod_atmo(), 15, "ssr_iod_atmo");
    
    is($json->encode($msg->stec_sat_list()), $json->encode($json->decode(q{[{"stec_bound_mu":18,"stec_bound_mu_dot":20,"stec_bound_sig":19,"stec_bound_sig_dot":21,"stec_residual":{"residual":16,"stddev":17,"sv_id":{"constellation":10,"sat_id":5}}},{"stec_bound_mu":24,"stec_bound_mu_dot":26,"stec_bound_sig":25,"stec_bound_sig_dot":27,"stec_residual":{"residual":22,"stddev":23,"sv_id":{"constellation":10,"sat_id":6}}}]})), "stec_sat_list");
    
    is($msg->tile_id(), 10, "tile_id");
    
    is($msg->tile_set_id(), 1, "tile_set_id");
    
    is($json->encode($msg->tropo_delay_correction()), $json->encode($json->decode(q{{"hydro":500,"stddev":200,"wet":100}})), "tropo_delay_correction");
    
    is($msg->tropo_qi(), 39, "tropo_qi");
    
    is($msg->tropo_v_hydro_bound_mu(), 150, "tropo_v_hydro_bound_mu");
    
    is($msg->tropo_v_hydro_bound_sig(), 100, "tropo_v_hydro_bound_sig");
    
    is($msg->tropo_v_wet_bound_mu(), 150, "tropo_v_wet_bound_mu");
    
    is($msg->tropo_v_wet_bound_sig(), 100, "tropo_v_wet_bound_sig");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":46828,"grid_point_id":1000,"header":{"num_msgs":1,"seq_num":0,"sol_id":0,"time":{"tow":180,"wn":3},"update_interval":10},"length":45,"msg_type":1534,"n_sats":2,"payload":"tAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQCBQoQABESExQVBgoWABcYGRob","preamble":85,"sender":66,"ssr_iod_atmo":15,"stec_sat_list":[{"stec_bound_mu":18,"stec_bound_mu_dot":20,"stec_bound_sig":19,"stec_bound_sig_dot":21,"stec_residual":{"residual":16,"stddev":17,"sv_id":{"constellation":10,"sat_id":5}}},{"stec_bound_mu":24,"stec_bound_mu_dot":26,"stec_bound_sig":25,"stec_bound_sig_dot":27,"stec_residual":{"residual":22,"stddev":23,"sv_id":{"constellation":10,"sat_id":6}}}],"tile_id":10,"tile_set_id":1,"tropo_delay_correction":{"hydro":500,"stddev":200,"wet":100},"tropo_qi":39,"tropo_v_hydro_bound_mu":150,"tropo_v_hydro_bound_sig":100,"tropo_v_wet_bound_mu":150,"tropo_v_wet_bound_sig":100}})), "raw_json");
}
sub test_auto_check_sbp_ssr_msg_ssr_gridded_correction_bounds_2() {
    my $buf = decode_base64("Vf4FQgAbtAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQAmyQ=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'msg_type'}, 0x05FE, "msg_type");
    
    is($msg->{'sender'}, 0x0042, "sender");
    
    is($msg->{'length'}, 27, "length");
    
    is($msg->{'payload'}, "tAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQA", "payload");
    
    is($msg->{'crc'}, 0x249B, "crc");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->grid_point_id(), 1000, "grid_point_id");
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"num_msgs":1,"seq_num":0,"sol_id":0,"time":{"tow":180,"wn":3},"update_interval":10}})), "header");
    
    is($msg->n_sats(), 0, "n_sats");
    
    is($msg->ssr_iod_atmo(), 15, "ssr_iod_atmo");
    
    is($json->encode($msg->stec_sat_list()), $json->encode($json->decode(q{[]})), "stec_sat_list");
    
    is($msg->tile_id(), 10, "tile_id");
    
    is($msg->tile_set_id(), 1, "tile_set_id");
    
    is($json->encode($msg->tropo_delay_correction()), $json->encode($json->decode(q{{"hydro":500,"stddev":200,"wet":100}})), "tropo_delay_correction");
    
    is($msg->tropo_qi(), 39, "tropo_qi");
    
    is($msg->tropo_v_hydro_bound_mu(), 150, "tropo_v_hydro_bound_mu");
    
    is($msg->tropo_v_hydro_bound_sig(), 100, "tropo_v_hydro_bound_sig");
    
    is($msg->tropo_v_wet_bound_mu(), 150, "tropo_v_wet_bound_mu");
    
    is($msg->tropo_v_wet_bound_sig(), 100, "tropo_v_wet_bound_sig");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":9371,"grid_point_id":1000,"header":{"num_msgs":1,"seq_num":0,"sol_id":0,"time":{"tow":180,"wn":3},"update_interval":10},"length":27,"msg_type":1534,"n_sats":0,"payload":"tAAAAAMAAQAKAA8BAAoAJ+gD9AFkyJZklmQA","preamble":85,"sender":66,"ssr_iod_atmo":15,"stec_sat_list":[],"tile_id":10,"tile_set_id":1,"tropo_delay_correction":{"hydro":500,"stddev":200,"wet":100},"tropo_qi":39,"tropo_v_hydro_bound_mu":150,"tropo_v_hydro_bound_sig":100,"tropo_v_wet_bound_mu":150,"tropo_v_wet_bound_sig":100}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_gridded_correction_bounds_1();
test_auto_check_sbp_ssr_msg_ssr_gridded_correction_bounds_2();

done_testing();