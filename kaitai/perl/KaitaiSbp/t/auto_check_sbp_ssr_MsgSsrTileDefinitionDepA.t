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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinitionDepA.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_tile_definition_dep_a_1() {
    my $buf = decode_base64("VfYFyIUYOb6y9wi5CbWi8EET/48Vv+/NqwAAAAAAQZo=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9a41, "crc");
    
    is($msg->{'length'}, 24, "length");
    
    is($msg->{'msg_type'}, 0x5f6, "msg_type");
    
    is($msg->{'payload'}, "Ob6y9wi5CbWi8EET/48Vv+/NqwAAAAAA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x85c8, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->bitmask(), 11259375, "bitmask");
    
    is($msg->cols(), 48917, "cols");
    
    is($msg->corner_nw_lat(), -18168, "corner_nw_lat");
    
    is($msg->corner_nw_lon(), -19191, "corner_nw_lon");
    
    is($msg->rows(), 36863, "rows");
    
    is($msg->spacing_lat(), 61602, "spacing_lat");
    
    is($msg->spacing_lon(), 4929, "spacing_lon");
    
    is($msg->tile_id(), 63410, "tile_id");
    
    is($msg->tile_set_id(), 48697, "tile_set_id");

    is($json->encode($msg), $json->encode($json->decode(q{{"bitmask":11259375,"cols":48917,"corner_nw_lat":-18168,"corner_nw_lon":-19191,"crc":39489,"length":24,"msg_type":1526,"payload":"Ob6y9wi5CbWi8EET/48Vv+/NqwAAAAAA","preamble":85,"rows":36863,"sender":34248,"spacing_lat":61602,"spacing_lon":4929,"tile_id":63410,"tile_set_id":48697}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_tile_definition_dep_a_1();

done_testing();
