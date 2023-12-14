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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGroupDelayDepA.yaml
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
sub test_auto_check_sbp_observation_msg_group_delay_dep_a_1() {
    my $buf = decode_base64("VZIAewAOsM8GAGoIFgH+/aX/7ReiWw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5ba2, "crc");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'msg_type'}, 0x92, "msg_type");
    
    is($msg->{'payload'}, "sM8GAGoIFgH+/aX/7Rc=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x007b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->isc_l1ca(), -91, "isc_l1ca");
    
    is($msg->isc_l2c(), 6125, "isc_l2c");
    
    is($msg->prn(), 22, "prn");
    
    is($json->encode($msg->t_op()), $json->encode($json->decode(q{{"tow":446384,"wn":2154}})), "t_op");
    
    is($msg->tgd(), -514, "tgd");
    
    is($msg->valid(), 1, "valid");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":23458,"isc_l1ca":-91,"isc_l2c":6125,"length":14,"msg_type":146,"payload":"sM8GAGoIFgH+/aX/7Rc=","preamble":85,"prn":22,"sender":123,"t_op":{"tow":446384,"wn":2154},"tgd":-514,"valid":1}})), "raw_json");
}
test_auto_check_sbp_observation_msg_group_delay_dep_a_1();

done_testing();