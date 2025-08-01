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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgSvConfigurationGpsDep.yaml
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
sub test_auto_check_sbp_observation_msg_sv_configuration_gps_dep_1() {
    my $buf = decode_base64("VZEAewAKAAAAAAAAQrxlpxIq");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x2a12, "crc");
    
    is($msg->{'length'}, 10, "length");
    
    is($msg->{'msg_type'}, 0x91, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAAAQrxlpw==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x007b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->l2c_mask(), 2808462402, "l2c_mask");
    
    is($json->encode($msg->t_nmct()), $json->encode($json->decode(q{{"tow":0,"wn":0}})), "t_nmct");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":10770,"l2c_mask":2808462402,"length":10,"msg_type":145,"payload":"AAAAAAAAQrxlpw==","preamble":85,"sender":123,"t_nmct":{"tow":0,"wn":0}}})), "raw_json");
}
test_auto_check_sbp_observation_msg_sv_configuration_gps_dep_1();

done_testing();
