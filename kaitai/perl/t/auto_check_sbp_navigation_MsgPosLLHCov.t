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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLHCov.yaml
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
sub test_auto_check_sbp_navigation_msg_pos_llh_cov_1() {
    my $buf = decode_base64("VRECQgA2BwAAAAAAAAAAAAAAAAAAAAAAHEAAAAAAAAAAAAAA4EAAAKBAAAAAQQAAwEAAAIA/AAAAQAUFl2I=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6297, "crc");
    
    is($msg->{'length'}, 54, "length");
    
    is($msg->{'msg_type'}, 0x211, "msg_type");
    
    is($msg->{'payload'}, "BwAAAAAAAAAAAAAAAAAAAAAAHEAAAAAAAAAAAAAA4EAAAKBAAAAAQQAAwEAAAIA/AAAAQAUF", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cov_d_d(), 2.0, "cov_d_d");
    
    is($msg->cov_e_d(), 1.0, "cov_e_d");
    
    is($msg->cov_e_e(), 6.0, "cov_e_e");
    
    is($msg->cov_n_d(), 8.0, "cov_n_d");
    
    is($msg->cov_n_e(), 5.0, "cov_n_e");
    
    is($msg->cov_n_n(), 7.0, "cov_n_n");
    
    is($msg->flags(), 5, "flags");
    
    is($msg->height(), 0.0, "height");
    
    is($msg->lat(), 0.0, "lat");
    
    is($msg->lon(), 7.0, "lon");
    
    is($msg->n_sats(), 5, "n_sats");
    
    is($msg->tow(), 7, "tow");

    is($json->encode($msg), $json->encode($json->decode(q{{"cov_d_d":2,"cov_e_d":1,"cov_e_e":6,"cov_n_d":8,"cov_n_e":5,"cov_n_n":7,"crc":25239,"flags":5,"height":0,"lat":0,"length":54,"lon":7,"msg_type":529,"n_sats":5,"payload":"BwAAAAAAAAAAAAAAAAAAAAAAHEAAAAAAAAAAAAAA4EAAAKBAAAAAQQAAwEAAAIA/AAAAQAUF","preamble":85,"sender":66,"tow":7}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_pos_llh_cov_1();

done_testing();