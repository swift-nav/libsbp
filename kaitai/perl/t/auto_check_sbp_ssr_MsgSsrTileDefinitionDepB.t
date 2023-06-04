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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinitionDepB.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_tile_definition_dep_b_1() {
    my $buf = decode_base64("VfcFQgAZHwABAAIABAAIABAAIABAAIDSApZJAAAAANZH");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'msg_type'}, 0x05F7, "msg_type");
    
    is($msg->{'sender'}, 0x0042, "sender");
    
    is($msg->{'length'}, 25, "length");
    
    is($msg->{'payload'}, "HwABAAIABAAIABAAIABAAIDSApZJAAAAAA==", "payload");
    
    is($msg->{'crc'}, 0x47D6, "crc");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->bitmask(), 1234567890, "bitmask");
    
    is($msg->cols(), 32768, "cols");
    
    is($msg->corner_nw_lat(), 1024, "corner_nw_lat");
    
    is($msg->corner_nw_lon(), 2048, "corner_nw_lon");
    
    is($msg->rows(), 16384, "rows");
    
    is($msg->spacing_lat(), 4096, "spacing_lat");
    
    is($msg->spacing_lon(), 8192, "spacing_lon");
    
    is($msg->ssr_sol_id(), 31, "ssr_sol_id");
    
    is($msg->tile_id(), 512, "tile_id");
    
    is($msg->tile_set_id(), 256, "tile_set_id");

    is($json->encode($msg), $json->encode($json->decode(q{{"bitmask":1234567890,"cols":32768,"corner_nw_lat":1024,"corner_nw_lon":2048,"crc":18390,"length":25,"msg_type":1527,"payload":"HwABAAIABAAIABAAIABAAIDSApZJAAAAAA==","preamble":85,"rows":16384,"sender":66,"spacing_lat":4096,"spacing_lon":8192,"ssr_sol_id":31,"tile_id":512,"tile_set_id":256}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_tile_definition_dep_b_1();

done_testing();