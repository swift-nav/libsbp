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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhCovGnss.yaml
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
sub test_auto_check_sbp_navigation_msg_pos_llh_cov_gnss_1() {
    my $buf = decode_base64("VTECABA2GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwAxm9TsGtcC5qE/zOmA8lDv9Ol26n64GPRIECsQ=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xc40a, "crc");
    
    is($msg->{'length'}, 54, "length");
    
    is($msg->{'msg_type'}, 0x231, "msg_type");
    
    is($msg->{'payload'}, "GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwAxm9TsGtcC5qE/zOmA8lDv9Ol26n64GPRIE", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1000, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cov_d_d(), 0.03288137540221214, "cov_d_d");
    
    is($msg->cov_e_d(), -0.0008439270895905793, "cov_e_d");
    
    is($msg->cov_e_e(), 0.004523798823356628, "cov_e_e");
    
    is($msg->cov_n_d(), 0.0018563168123364449, "cov_n_d");
    
    is($msg->cov_n_e(), -0.00036755966721102595, "cov_n_e");
    
    is($msg->cov_n_n(), 0.007488971576094627, "cov_n_n");
    
    is($msg->flags(), 4, "flags");
    
    is($msg->height(), -17.39382124780135, "height");
    
    is($msg->lat(), 37.83123196497633, "lat");
    
    is($msg->lon(), -122.28650381011681, "lon");
    
    is($msg->n_sats(), 18, "n_sats");
    
    is($msg->tow(), 501867800, "tow");

    is($json->encode($msg), $json->encode($json->decode(q{{"cov_d_d":0.03288137540221214,"cov_e_d":-0.0008439270895905793,"cov_e_e":0.004523798823356628,"cov_n_d":0.0018563168123364449,"cov_n_e":-0.00036755966721102595,"cov_n_n":0.007488971576094627,"crc":50186,"flags":4,"height":-17.39382124780135,"lat":37.83123196497633,"length":54,"lon":-122.28650381011681,"msg_type":561,"n_sats":18,"payload":"GOXpHUl7HM9l6kJAZKgTFFaSXsDWxiN40WQxwAxm9TsGtcC5qE/zOmA8lDv9Ol26n64GPRIE","preamble":85,"sender":4096,"tow":501867800}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_pos_llh_cov_gnss_1();

done_testing();
