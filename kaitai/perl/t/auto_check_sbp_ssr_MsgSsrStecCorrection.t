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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrection.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_stec_correction_1() {
    my $buf = decode_base64("Vf0FQgAmtAAAAAMAAQEKAA8BAAoAAgEBAT8APgA9ADwAHw8FPwBAAEEAQgB3Mg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'msg_type'}, 0x05FD, "msg_type");
    
    is($msg->{'sender'}, 0x0042, "sender");
    
    is($msg->{'length'}, 38, "length");
    
    is($msg->{'payload'}, "tAAAAAMAAQEKAA8BAAoAAgEBAT8APgA9ADwAHw8FPwBAAEEAQgA=", "payload");
    
    is($msg->{'crc'}, 0x3277, "crc");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"num_msgs":1,"seq_num":1,"sol_id":0,"time":{"tow":180,"wn":3},"update_interval":10}})), "header");
    
    is($msg->n_sats(), 2, "n_sats");
    
    is($msg->ssr_iod_atmo(), 15, "ssr_iod_atmo");
    
    is($json->encode($msg->stec_sat_list()), $json->encode($json->decode(q{[{"stec_coeff":[63,62,61,60],"stec_quality_indicator":1,"sv_id":{"constellation":1,"sat_id":1}},{"stec_coeff":[63,64,65,66],"stec_quality_indicator":5,"sv_id":{"constellation":15,"sat_id":31}}]})), "stec_sat_list");
    
    is($msg->tile_id(), 10, "tile_id");
    
    is($msg->tile_set_id(), 1, "tile_set_id");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":12919,"header":{"num_msgs":1,"seq_num":1,"sol_id":0,"time":{"tow":180,"wn":3},"update_interval":10},"length":38,"msg_type":1533,"n_sats":2,"payload":"tAAAAAMAAQEKAA8BAAoAAgEBAT8APgA9ADwAHw8FPwBAAEEAQgA=","preamble":85,"sender":66,"ssr_iod_atmo":15,"stec_sat_list":[{"stec_coeff":[63,62,61,60],"stec_quality_indicator":1,"sv_id":{"constellation":1,"sat_id":1}},{"stec_coeff":[63,64,65,66],"stec_quality_indicator":5,"sv_id":{"constellation":15,"sat_id":31}}],"tile_id":10,"tile_set_id":1}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_stec_correction_1();

done_testing();