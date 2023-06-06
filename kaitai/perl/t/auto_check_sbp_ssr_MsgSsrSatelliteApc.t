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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApc.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_satellite_apc_1() {
    my $buf = decode_base64("VQUGAAApfzoJAK4IAQIDAgAEPQABAP//2QILCggFAfz49vb2+fwABgwWHikpKSmQoQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xA190, "crc");
    
    is($msg->{'length'}, 41, "length");
    
    is($msg->{'msg_type'}, 0x605, "msg_type");
    
    is($msg->{'payload'}, "fzoJAK4IAQIDAgAEPQABAP//2QILCggFAfz49vb2+fwABgwWHikpKSk=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x0, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->apc()), $json->encode($json->decode(q{[{"pco":[1,-1,729],"pcv":[11,10,8,5,1,-4,-8,-10,-10,-10,-7,-4,0,6,12,22,30,41,41,41,41],"sat_info":4,"sid":{"code":0,"sat":2},"svn":61}]})), "apc");
    
    is($msg->iod_ssr(), 3, "iod_ssr");
    
    is($msg->sol_id(), 2, "sol_id");
    
    is($json->encode($msg->time()), $json->encode($json->decode(q{{"tow":604799,"wn":2222}})), "time");
    
    is($msg->update_interval(), 1, "update_interval");

    is($json->encode($msg), $json->encode($json->decode(q{{"apc":[{"pco":[1,-1,729],"pcv":[11,10,8,5,1,-4,-8,-10,-10,-10,-7,-4,0,6,12,22,30,41,41,41,41],"sat_info":4,"sid":{"code":0,"sat":2},"svn":61}],"crc":41360,"iod_ssr":3,"length":41,"msg_type":1541,"payload":"fzoJAK4IAQIDAgAEPQABAP//2QILCggFAfz49vb2+fwABgwWHikpKSk=","preamble":85,"sender":0,"sol_id":2,"time":{"tow":604799,"wn":2222},"update_interval":1}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_satellite_apc_1();

done_testing();