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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgBasePosLLH.yaml
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
sub test_auto_check_sbp_observation_msg_base_pos_llh_1() {
    my $buf = decode_base64("VUQAewAY4e3uWiqgQkA7j0brAHhewDO1fPBB+EJAUuY=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe652, "crc");
    
    is($msg->{'length'}, 24, "length");
    
    is($msg->{'msg_type'}, 0x44, "msg_type");
    
    is($msg->{'payload'}, "4e3uWiqgQkA7j0brAHhewDO1fPBB+EJA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x007b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->height(), 37.939512310879216, "height");
    
    is($msg->lat(), 37.251292578377395, "lat");
    
    is($msg->lon(), -121.87505609407974, "lon");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":58962,"height":37.939512310879216,"lat":37.251292578377395,"length":24,"lon":-121.87505609407974,"msg_type":68,"payload":"4e3uWiqgQkA7j0brAHhewDO1fPBB+EJA","preamble":85,"sender":123}})), "raw_json");
}
test_auto_check_sbp_observation_msg_base_pos_llh_1();

done_testing();