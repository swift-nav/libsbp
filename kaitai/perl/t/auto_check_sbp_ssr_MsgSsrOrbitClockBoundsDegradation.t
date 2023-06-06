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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockBoundsDegradation.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_orbit_clock_bounds_degradation_1() {
    my $buf = decode_base64("Vd8FQgActAAAAAMAAQIDMA8BCgAAAAAAAADIx8bFxMPCwch1");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'msg_type'}, 0x05DF, "msg_type");
    
    is($msg->{'sender'}, 0x0042, "sender");
    
    is($msg->{'length'}, 28, "length");
    
    is($msg->{'payload'}, "tAAAAAMAAQIDMA8BCgAAAAAAAADIx8bFxMPCwQ==", "payload");
    
    is($msg->{'crc'}, 0x75C8, "crc");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->const_id(), 1, "const_id");
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"num_msgs":1,"seq_num":2,"sol_id":48,"time":{"tow":180,"wn":3},"update_interval":3}})), "header");
    
    is($json->encode($msg->orbit_clock_bounds_degradation()), $json->encode($json->decode(q{{"clock_bound_mu_dot":194,"clock_bound_sig_dot":193,"orb_along_bound_mu_dot":199,"orb_along_bound_sig_dot":196,"orb_cross_bound_mu_dot":198,"orb_cross_bound_sig_dot":195,"orb_radial_bound_mu_dot":200,"orb_radial_bound_sig_dot":197}})), "orbit_clock_bounds_degradation");
    
    is($msg->sat_bitmask(), 10, "sat_bitmask");
    
    is($msg->ssr_iod(), 15, "ssr_iod");

    is($json->encode($msg), $json->encode($json->decode(q{{"const_id":1,"crc":30152,"header":{"num_msgs":1,"seq_num":2,"sol_id":48,"time":{"tow":180,"wn":3},"update_interval":3},"length":28,"msg_type":1503,"orbit_clock_bounds_degradation":{"clock_bound_mu_dot":194,"clock_bound_sig_dot":193,"orb_along_bound_mu_dot":199,"orb_along_bound_sig_dot":196,"orb_cross_bound_mu_dot":198,"orb_cross_bound_sig_dot":195,"orb_radial_bound_mu_dot":200,"orb_radial_bound_sig_dot":197},"payload":"tAAAAAMAAQIDMA8BCgAAAAAAAADIx8bFxMPCwQ==","preamble":85,"sat_bitmask":10,"sender":66,"ssr_iod":15}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_orbit_clock_bounds_degradation_1();

done_testing();