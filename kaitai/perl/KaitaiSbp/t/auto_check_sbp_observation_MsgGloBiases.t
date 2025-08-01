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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGloBiases.yaml
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
sub test_auto_check_sbp_observation_msg_glo_biases_1() {
    my $buf = decode_base64("VXUAAAAJAAAAAAAAAAAATdM=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd34d, "crc");
    
    is($msg->{'length'}, 9, "length");
    
    is($msg->{'payload'}, "AAAAAAAAAAAA", "payload");
    
    is($msg->{'msg_type'}, 0x75, "msg_type");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->l1ca_bias(), 0, "l1ca_bias");
    
    is($msg->l1p_bias(), 0, "l1p_bias");
    
    is($msg->l2ca_bias(), 0, "l2ca_bias");
    
    is($msg->l2p_bias(), 0, "l2p_bias");
    
    is($msg->mask(), 0, "mask");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":54093,"l1ca_bias":0,"l1p_bias":0,"l2ca_bias":0,"l2p_bias":0,"length":9,"mask":0,"msg_type":117,"payload":"AAAAAAAAAAAA","preamble":85,"sender":0}})), "raw_json");
}
test_auto_check_sbp_observation_msg_glo_biases_1();

done_testing();
