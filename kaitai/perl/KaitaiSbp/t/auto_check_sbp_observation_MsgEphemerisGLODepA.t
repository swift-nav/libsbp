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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGLODepA.yaml
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
sub test_auto_check_sbp_observation_msg_ephemeris_glo_dep_a_1() {
    my $buf = decode_base64("VYMAwwRwBAADAEbFBgBqCM3MzMzMzBRAYAkAAAEAAAAAAAAAcD0AAAAAMOwVvwAAgEL2OWfBAAAAIqpOIkEAAPDHVFZ1wQAAAGIG+prAAAAA2Trdo8AAAAC4ii6LQAAAAAAAQK8+AAAAAABArz4AAAAAAHDHPsru");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xeeca, "crc");
    
    is($msg->{'length'}, 112, "length");
    
    is($msg->{'msg_type'}, 0x83, "msg_type");
    
    is($msg->{'payload'}, "BAADAEbFBgBqCM3MzMzMzBRAYAkAAAEAAAAAAAAAcD0AAAAAMOwVvwAAgEL2OWfBAAAAIqpOIkEAAPDHVFZ1wQAAAGIG+prAAAAA2Trdo8AAAAC4ii6LQAAAAAAAQK8+AAAAAABArz4AAAAAAHDHPg==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->acc()), $json->encode($json->decode(q{[9.313225746154785e-07,9.313225746154785e-07,2.7939677238464355e-06]})), "acc");
    
    is($json->encode($msg->common()), $json->encode($json->decode(q{{"fit_interval":2400,"health_bits":0,"sid":{"code":3,"reserved":0,"sat":4},"toe":{"tow":443718,"wn":2154},"ura":5.2,"valid":1}})), "common");
    
    is($msg->gamma(), 9.094947017729282e-13, "gamma");
    
    is($json->encode($msg->pos()), $json->encode($json->decode(q{[-12177330.078125,599893.06640625,-22373708.49609375]})), "pos");
    
    is($msg->tau(), -8.36281105875969e-05, "tau");
    
    is($json->encode($msg->vel()), $json->encode($json->decode(q{[-1726.506233215332,-2542.6149368286133,869.8177337646484]})), "vel");

    is($json->encode($msg), $json->encode($json->decode(q{{"acc":[9.313225746154785e-07,9.313225746154785e-07,2.7939677238464355e-06],"common":{"fit_interval":2400,"health_bits":0,"sid":{"code":3,"reserved":0,"sat":4},"toe":{"tow":443718,"wn":2154},"ura":5.2,"valid":1},"crc":61130,"gamma":9.094947017729282e-13,"length":112,"msg_type":131,"payload":"BAADAEbFBgBqCM3MzMzMzBRAYAkAAAEAAAAAAAAAcD0AAAAAMOwVvwAAgEL2OWfBAAAAIqpOIkEAAPDHVFZ1wQAAAGIG+prAAAAA2Trdo8AAAAC4ii6LQAAAAAAAQK8+AAAAAABArz4AAAAAAHDHPg==","pos":[-12177330.078125,599893.06640625,-22373708.49609375],"preamble":85,"sender":1219,"tau":-8.36281105875969e-05,"vel":[-1726.506233215332,-2542.6149368286133,869.8177337646484]}})), "raw_json");
}
test_auto_check_sbp_observation_msg_ephemeris_glo_dep_a_1();

done_testing();