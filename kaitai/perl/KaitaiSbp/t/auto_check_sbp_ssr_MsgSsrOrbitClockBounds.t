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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockBounds.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_orbit_clock_bounds_1() {
    my $buf = decode_base64("Vd4FQgAftAAAAAMAAQIDMA8BAhgnJiUBAgMnAQMnJiUBAgMnARVV");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'msg_type'}, 0x05DE, "msg_type");
    
    is($msg->{'sender'}, 0x0042, "sender");
    
    is($msg->{'length'}, 31, "length");
    
    is($msg->{'payload'}, "tAAAAAMAAQIDMA8BAhgnJiUBAgMnAQMnJiUBAgMnAQ==", "payload");
    
    is($msg->{'crc'}, 0x5515, "crc");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->const_id(), 1, "const_id");
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"num_msgs":1,"seq_num":2,"sol_id":48,"time":{"tow":180,"wn":3},"update_interval":3}})), "header");
    
    is($msg->n_sats(), 2, "n_sats");
    
    is($json->encode($msg->orbit_clock_bounds()), $json->encode($json->decode(q{[{"clock_bound_mu":39,"clock_bound_sig":1,"orb_along_bound_mu":38,"orb_along_bound_sig":2,"orb_cross_bound_mu":37,"orb_cross_bound_sig":3,"orb_radial_bound_mu":39,"orb_radial_bound_sig":1,"sat_id":24},{"clock_bound_mu":39,"clock_bound_sig":1,"orb_along_bound_mu":38,"orb_along_bound_sig":2,"orb_cross_bound_mu":37,"orb_cross_bound_sig":3,"orb_radial_bound_mu":39,"orb_radial_bound_sig":1,"sat_id":3}]})), "orbit_clock_bounds");
    
    is($msg->ssr_iod(), 15, "ssr_iod");

    is($json->encode($msg), $json->encode($json->decode(q{{"const_id":1,"crc":21781,"header":{"num_msgs":1,"seq_num":2,"sol_id":48,"time":{"tow":180,"wn":3},"update_interval":3},"length":31,"msg_type":1502,"n_sats":2,"orbit_clock_bounds":[{"clock_bound_mu":39,"clock_bound_sig":1,"orb_along_bound_mu":38,"orb_along_bound_sig":2,"orb_cross_bound_mu":37,"orb_cross_bound_sig":3,"orb_radial_bound_mu":39,"orb_radial_bound_sig":1,"sat_id":24},{"clock_bound_mu":39,"clock_bound_sig":1,"orb_along_bound_mu":38,"orb_along_bound_sig":2,"orb_cross_bound_mu":37,"orb_cross_bound_sig":3,"orb_radial_bound_mu":39,"orb_radial_bound_sig":1,"sat_id":3}],"payload":"tAAAAAMAAQIDMA8BAhgnJiUBAgMnAQMnJiUBAgMnAQ==","preamble":85,"sender":66,"ssr_iod":15}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_orbit_clock_bounds_1();

done_testing();
