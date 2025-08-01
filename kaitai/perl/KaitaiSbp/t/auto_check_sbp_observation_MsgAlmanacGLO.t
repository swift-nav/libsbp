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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgAlmanacGLO.yaml
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
sub test_auto_check_sbp_observation_msg_almanac_glo_1() {
    my $buf = decode_base64("VXMAwwROFgCwzwYAagiamZmZmZkBQEA4AAABAI4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/m1c=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x579b, "crc");
    
    is($msg->{'length'}, 78, "length");
    
    is($msg->{'msg_type'}, 0x73, "msg_type");
    
    is($msg->{'payload'}, "FgCwzwYAagiamZmZmZkBQEA4AAABAI4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->common()), $json->encode($json->decode(q{{"fit_interval":14400,"health_bits":0,"sid":{"code":0,"sat":22},"toa":{"tow":446384,"wn":2154},"ura":2.2,"valid":1}})), "common");
    
    is($msg->epsilon(), -0.9893036629599647, "epsilon");
    
    is($msg->i(), 5153.550029754639, "i");
    
    is($msg->lambda_na(), -0.02200078842114688, "lambda_na");
    
    is($msg->omega(), 0.9341514480259797, "omega");
    
    is($msg->t(), -1.8731818448797617, "t");
    
    is($msg->t_dot(), -8.903585155774196e-09, "t_dot");
    
    is($msg->t_lambda_na(), 0.007072207052260637, "t_lambda_na");

    is($json->encode($msg), $json->encode($json->decode(q{{"common":{"fit_interval":14400,"health_bits":0,"sid":{"code":0,"sat":22},"toa":{"tow":446384,"wn":2154},"ura":2.2,"valid":1},"crc":22427,"epsilon":-0.9893036629599647,"i":5153.550029754639,"lambda_na":-0.02200078842114688,"length":78,"msg_type":115,"omega":0.9341514480259797,"payload":"FgCwzwYAagiamZmZmZkBQEA4AAABAI4pBetfh5a/AAAAIL/3fD8AAMDOjCG0QCmDs4aN+P2/44VRNsweQ77YO8cnYKjvv0cL2ZOR5O0/","preamble":85,"sender":1219,"t":-1.8731818448797617,"t_dot":-8.903585155774196e-09,"t_lambda_na":0.007072207052260637}})), "raw_json");
}
test_auto_check_sbp_observation_msg_almanac_glo_1();

done_testing();
