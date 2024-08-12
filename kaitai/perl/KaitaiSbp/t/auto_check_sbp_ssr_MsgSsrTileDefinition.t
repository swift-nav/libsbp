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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinition.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_tile_definition_1() {
    my $buf = decode_base64("VfgFAAAhfzoJAK4IAQIDBAAFALocO6dkAGQABgAGANIClkkAAAAAzF4=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5ECC, "crc");
    
    is($msg->{'length'}, 33, "length");
    
    is($msg->{'msg_type'}, 0x5F8, "msg_type");
    
    is($msg->{'payload'}, "fzoJAK4IAQIDBAAFALocO6dkAGQABgAGANIClkkAAAAA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x0, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->bitmask(), 1234567890, "bitmask");
    
    is($msg->cols(), 6, "cols");
    
    is($msg->corner_nw_lat(), 7354, "corner_nw_lat");
    
    is($msg->corner_nw_lon(), -22725, "corner_nw_lon");
    
    is($msg->iod_atmo(), 3, "iod_atmo");
    
    is($msg->rows(), 6, "rows");
    
    is($msg->sol_id(), 2, "sol_id");
    
    is($msg->spacing_lat(), 100, "spacing_lat");
    
    is($msg->spacing_lon(), 100, "spacing_lon");
    
    is($msg->tile_id(), 5, "tile_id");
    
    is($msg->tile_set_id(), 4, "tile_set_id");
    
    is($json->encode($msg->time()), $json->encode($json->decode(q{{"tow":604799,"wn":2222}})), "time");
    
    is($msg->update_interval(), 1, "update_interval");

    is($json->encode($msg), $json->encode($json->decode(q{{"bitmask":1234567890,"cols":6,"corner_nw_lat":7354,"corner_nw_lon":-22725,"crc":24268,"iod_atmo":3,"length":33,"msg_type":1528,"payload":"fzoJAK4IAQIDBAAFALocO6dkAGQABgAGANIClkkAAAAA","preamble":85,"rows":6,"sender":0,"sol_id":2,"spacing_lat":100,"spacing_lon":100,"tile_id":5,"tile_set_id":4,"time":{"tow":604799,"wn":2222},"update_interval":1}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_tile_definition_1();

done_testing();