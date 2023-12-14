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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgIono.yaml
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
sub test_auto_check_sbp_observation_msg_iono_1() {
    my $buf = decode_base64("VZAAewBGAAAAAAAAAAAAAAAAND4AAAAAAABQPgAAAAAAAHC+AAAAAAAAcL4AAAAAAADzQAAAAAAAAOhAAAAAAAAA8MAAAAAAAAAUwWUf");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x1f65, "crc");
    
    is($msg->{'length'}, 70, "length");
    
    is($msg->{'msg_type'}, 0x90, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAAAAAAAAAAAND4AAAAAAABQPgAAAAAAAHC+AAAAAAAAcL4AAAAAAADzQAAAAAAAAOhAAAAAAAAA8MAAAAAAAAAUwQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x007b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->a0(), 4.6566128730773926e-09, "a0");
    
    is($msg->a1(), 1.4901161193847656e-08, "a1");
    
    is($msg->a2(), -5.960464477539063e-08, "a2");
    
    is($msg->a3(), -5.960464477539063e-08, "a3");
    
    is($msg->b0(), 77824.0, "b0");
    
    is($msg->b1(), 49152.0, "b1");
    
    is($msg->b2(), -65536.0, "b2");
    
    is($msg->b3(), -327680.0, "b3");
    
    is($json->encode($msg->t_nmct()), $json->encode($json->decode(q{{"tow":0,"wn":0}})), "t_nmct");

    is($json->encode($msg), $json->encode($json->decode(q{{"a0":4.6566128730773926e-09,"a1":1.4901161193847656e-08,"a2":-5.960464477539063e-08,"a3":-5.960464477539063e-08,"b0":77824,"b1":49152,"b2":-65536,"b3":-327680,"crc":8037,"length":70,"msg_type":144,"payload":"AAAAAAAAAAAAAAAAND4AAAAAAABQPgAAAAAAAHC+AAAAAAAAcL4AAAAAAADzQAAAAAAAAOhAAAAAAAAA8MAAAAAAAAAUwQ==","preamble":85,"sender":123,"t_nmct":{"tow":0,"wn":0}}})), "raw_json");
}
test_auto_check_sbp_observation_msg_iono_1();

done_testing();