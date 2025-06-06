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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisSbas.yaml
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
sub test_auto_check_sbp_observation_msg_ephemeris_sbas_1() {
    my $buf = decode_base64("VYwAwwRKFgawzwYAaggAAECxAAAAAAEAAACAQvY5Z8EAAAAiqk4iQQAA8MdUVnXBM9DXxNfpHsVWdFlEAAB6NQAAejUAgDs2YIslugAAHi3Akw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x93c0, "crc");
    
    is($msg->{'length'}, 74, "length");
    
    is($msg->{'msg_type'}, 0x8c, "msg_type");
    
    is($msg->{'payload'}, "FgawzwYAaggAAECxAAAAAAEAAACAQvY5Z8EAAAAiqk4iQQAA8MdUVnXBM9DXxNfpHsVWdFlEAAB6NQAAejUAgDs2YIslugAAHi0=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->a_gf0(), -0.0006315018981695175, "a_gf0");
    
    is($msg->a_gf1(), 8.981260180007666e-12, "a_gf1");
    
    is($json->encode($msg->acc()), $json->encode($json->decode(q{[9.313225746154785e-07,9.313225746154785e-07,2.7939677238464355e-06]})), "acc");
    
    is($json->encode($msg->common()), $json->encode($json->decode(q{{"fit_interval":0,"health_bits":0,"sid":{"code":6,"sat":22},"toe":{"tow":446384,"wn":2154},"ura":-2.7939677238464355e-09,"valid":1}})), "common");
    
    is($json->encode($msg->pos()), $json->encode($json->decode(q{[-12177330.078125,599893.06640625,-22373708.49609375]})), "pos");
    
    is($json->encode($msg->vel()), $json->encode($json->decode(q{[-1726.5062255859375,-2542.614990234375,869.8177490234375]})), "vel");

    is($json->encode($msg), $json->encode($json->decode(q{{"a_gf0":-0.0006315018981695175,"a_gf1":8.981260180007666e-12,"acc":[9.313225746154785e-07,9.313225746154785e-07,2.7939677238464355e-06],"common":{"fit_interval":0,"health_bits":0,"sid":{"code":6,"sat":22},"toe":{"tow":446384,"wn":2154},"ura":-2.7939677238464355e-09,"valid":1},"crc":37824,"length":74,"msg_type":140,"payload":"FgawzwYAaggAAECxAAAAAAEAAACAQvY5Z8EAAAAiqk4iQQAA8MdUVnXBM9DXxNfpHsVWdFlEAAB6NQAAejUAgDs2YIslugAAHi0=","pos":[-12177330.078125,599893.06640625,-22373708.49609375],"preamble":85,"sender":1219,"vel":[-1726.5062255859375,-2542.614990234375,869.8177490234375]}})), "raw_json");
}
test_auto_check_sbp_observation_msg_ephemeris_sbas_1();

done_testing();
