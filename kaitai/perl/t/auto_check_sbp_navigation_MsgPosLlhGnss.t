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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhGnss.yaml
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
sub test_auto_check_sbp_navigation_msg_pos_llh_gnss_1() {
    my $buf = decode_base64("VSoCABAiGOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwFcAtQASBGk3");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x3769, "crc");
    
    is($msg->{'length'}, 34, "length");
    
    is($msg->{'msg_type'}, 0x22a, "msg_type");
    
    is($msg->{'payload'}, "GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwFcAtQASBA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1000, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 4, "flags");
    
    is($msg->h_accuracy(), 87, "h_accuracy");
    
    is($msg->height(), -17.39382124780135, "height");
    
    is($msg->lat(), 37.83123196497633, "lat");
    
    is($msg->lon(), -122.28650381011681, "lon");
    
    is($msg->n_sats(), 18, "n_sats");
    
    is($msg->tow(), 501867800, "tow");
    
    is($msg->v_accuracy(), 181, "v_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":14185,"flags":4,"h_accuracy":87,"height":-17.39382124780135,"lat":37.83123196497633,"length":34,"lon":-122.28650381011681,"msg_type":554,"n_sats":18,"payload":"GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwFcAtQASBA==","preamble":85,"sender":4096,"tow":501867800,"v_accuracy":181}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_pos_llh_gnss_1();

done_testing();