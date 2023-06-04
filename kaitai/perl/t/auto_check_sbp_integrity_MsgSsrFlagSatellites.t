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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagSatellites.yaml
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
use t::Utils;
sub test_auto_check_sbp_integrity_msg_ssr_flag_satellites_1() {
    my $buf = decode_base64("Vb0LQgAPtAAAAAMAAQIDBAUDCgsMbqU=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'msg_type'}, 0x0BBD, "msg_type");
    
    is($msg->{'sender'}, 0x0042, "sender");
    
    is($msg->{'length'}, 15, "length");
    
    is($msg->{'payload'}, "tAAAAAMAAQIDBAUDCgsM", "payload");
    
    is($msg->{'crc'}, 0xA56E, "crc");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->chain_id(), 4, "chain_id");
    
    is($msg->const_id(), 5, "const_id");
    
    is($json->encode($msg->faulty_sats()), $json->encode($json->decode(q{[10,11,12]})), "faulty_sats");
    
    is($msg->n_faulty_sats(), 3, "n_faulty_sats");
    
    is($msg->num_msgs(), 1, "num_msgs");
    
    is($json->encode($msg->obs_time()), $json->encode($json->decode(q{{"tow":180,"wn":3}})), "obs_time");
    
    is($msg->seq_num(), 2, "seq_num");
    
    is($msg->ssr_sol_id(), 3, "ssr_sol_id");

    is($json->encode($msg), $json->encode($json->decode(q{{"chain_id":4,"const_id":5,"crc":42350,"faulty_sats":[10,11,12],"length":15,"msg_type":3005,"n_faulty_sats":3,"num_msgs":1,"obs_time":{"tow":180,"wn":3},"payload":"tAAAAAMAAQIDBAUDCgsM","preamble":85,"sender":66,"seq_num":2,"ssr_sol_id":3}})), "raw_json");
}
test_auto_check_sbp_integrity_msg_ssr_flag_satellites_1();

done_testing();