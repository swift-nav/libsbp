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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqSvProfileDep.yaml
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
sub test_auto_check_sbp_acquisition_msg_acq_sv_profile_dep_1() {
    my $buf = decode_base64("VR4AwwRpQ2eXAAwWAAAAuwBbAAAASwAAAIQAAAAkAAAAPAAAAPEAAADuJm8AsxcAAQCwAKYAAADqAAAAmwAAABgAAADUAAAA9wAAAI7VRAA1GAAAADQAMQAAAPUAAABMAAAA+AAAANQAAABlAAAAQ4Q=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8443, "crc");
    
    is($msg->{'length'}, 105, "length");
    
    is($msg->{'msg_type'}, 0x1e, "msg_type");
    
    is($msg->{'payload'}, "Q2eXAAwWAAAAuwBbAAAASwAAAIQAAAAkAAAAPAAAAPEAAADuJm8AsxcAAQCwAKYAAADqAAAAmwAAABgAAADUAAAA9wAAAI7VRAA1GAAAADQAMQAAAPUAAABMAAAA+AAAANQAAABlAAAA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->acq_sv_profile()), $json->encode($json->decode(q{[{"bin_width":187,"cf":60,"cf_max":36,"cf_min":132,"cn0":151,"cp":241,"int_time":12,"job_type":67,"sid":{"code":0,"reserved":0,"sat":22},"status":103,"time_spent":75,"timestamp":91},{"bin_width":176,"cf":212,"cf_max":24,"cf_min":155,"cn0":111,"cp":247,"int_time":179,"job_type":238,"sid":{"code":1,"reserved":0,"sat":23},"status":38,"time_spent":234,"timestamp":166},{"bin_width":52,"cf":212,"cf_max":248,"cf_min":76,"cn0":68,"cp":101,"int_time":53,"job_type":142,"sid":{"code":0,"reserved":0,"sat":24},"status":213,"time_spent":245,"timestamp":49}]})), "acq_sv_profile");

    is($json->encode($msg), $json->encode($json->decode(q{{"acq_sv_profile":[{"bin_width":187,"cf":60,"cf_max":36,"cf_min":132,"cn0":151,"cp":241,"int_time":12,"job_type":67,"sid":{"code":0,"reserved":0,"sat":22},"status":103,"time_spent":75,"timestamp":91},{"bin_width":176,"cf":212,"cf_max":24,"cf_min":155,"cn0":111,"cp":247,"int_time":179,"job_type":238,"sid":{"code":1,"reserved":0,"sat":23},"status":38,"time_spent":234,"timestamp":166},{"bin_width":52,"cf":212,"cf_max":248,"cf_min":76,"cn0":68,"cp":101,"int_time":53,"job_type":142,"sid":{"code":0,"reserved":0,"sat":24},"status":213,"time_spent":245,"timestamp":49}],"crc":33859,"length":105,"msg_type":30,"payload":"Q2eXAAwWAAAAuwBbAAAASwAAAIQAAAAkAAAAPAAAAPEAAADuJm8AsxcAAQCwAKYAAADqAAAAmwAAABgAAADUAAAA9wAAAI7VRAA1GAAAADQAMQAAAPUAAABMAAAA+AAAANQAAABlAAAA","preamble":85,"sender":1219}})), "raw_json");
}
test_auto_check_sbp_acquisition_msg_acq_sv_profile_dep_1();

done_testing();