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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/telemetry/test_MsgTelSv.yaml
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
sub test_auto_check_sbp_telemetry_msg_tel_sv_1() {
    my $buf = decode_base64("VSABlCYUrwjQ3T4YEAEoMgXi/wEAAQEBIQwnaQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6927, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x120, "msg_type");
    
    is($msg->{'payload'}, "rwjQ3T4YEAEoMgXi/wEAAQEBIQw=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x2694, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->n_obs(), 16, "n_obs");
    
    is($msg->origin_flags(), 1, "origin_flags");
    
    is($json->encode($msg->sv_tel()), $json->encode($json->decode(q{[{"availability_flags":5,"az":40,"correction_flags":1,"el":50,"ephemeris_flags":1,"outlier_flags":1,"phase_residual":1,"pseudorange_residual":-30,"sid":{"code":12,"sat":33}}]})), "sv_tel");
    
    is($msg->tow(), 406773200, "tow");
    
    is($msg->wn(), 2223, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":26919,"length":20,"msg_type":288,"n_obs":16,"origin_flags":1,"payload":"rwjQ3T4YEAEoMgXi/wEAAQEBIQw=","preamble":85,"sender":9876,"sv_tel":[{"availability_flags":5,"az":40,"correction_flags":1,"el":50,"ephemeris_flags":1,"outlier_flags":1,"phase_residual":1,"pseudorange_residual":-30,"sid":{"code":12,"sat":33}}],"tow":406773200,"wn":2223}})), "raw_json");
}
test_auto_check_sbp_telemetry_msg_tel_sv_1();

done_testing();
