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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqSvProfile.yaml
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
sub test_auto_check_sbp_acquisition_msg_acq_sv_profile_1() {
    my $buf = decode_base64("VS4AwwRjBw0mAGEWAK4ANAAAADEAAAA9AAAAkwAAAC8AAACMAAAAptI7AP0XAXkAvgAAAK8AAACvAAAAjgAAAO0AAAAMAAAAflgVAJkYAAgAggAAAKwAAABbAAAAvwAAAFQAAABSAAAAqLE=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb1a8, "crc");
    
    is($msg->{'length'}, 99, "length");
    
    is($msg->{'msg_type'}, 0x2e, "msg_type");
    
    is($msg->{'payload'}, "Bw0mAGEWAK4ANAAAADEAAAA9AAAAkwAAAC8AAACMAAAAptI7AP0XAXkAvgAAAK8AAACvAAAAjgAAAO0AAAAMAAAAflgVAJkYAAgAggAAAKwAAABbAAAAvwAAAFQAAABSAAAA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->acq_sv_profile()), $json->encode($json->decode(q{[{"bin_width":174,"cf":47,"cf_max":147,"cf_min":61,"cn0":38,"cp":140,"int_time":97,"job_type":7,"sid":{"code":0,"sat":22},"status":13,"time_spent":49,"timestamp":52},{"bin_width":121,"cf":237,"cf_max":142,"cf_min":175,"cn0":59,"cp":12,"int_time":253,"job_type":166,"sid":{"code":1,"sat":23},"status":210,"time_spent":175,"timestamp":190},{"bin_width":8,"cf":84,"cf_max":191,"cf_min":91,"cn0":21,"cp":82,"int_time":153,"job_type":126,"sid":{"code":0,"sat":24},"status":88,"time_spent":172,"timestamp":130}]})), "acq_sv_profile");

    is($json->encode($msg), $json->encode($json->decode(q{{"acq_sv_profile":[{"bin_width":174,"cf":47,"cf_max":147,"cf_min":61,"cn0":38,"cp":140,"int_time":97,"job_type":7,"sid":{"code":0,"sat":22},"status":13,"time_spent":49,"timestamp":52},{"bin_width":121,"cf":237,"cf_max":142,"cf_min":175,"cn0":59,"cp":12,"int_time":253,"job_type":166,"sid":{"code":1,"sat":23},"status":210,"time_spent":175,"timestamp":190},{"bin_width":8,"cf":84,"cf_max":191,"cf_min":91,"cn0":21,"cp":82,"int_time":153,"job_type":126,"sid":{"code":0,"sat":24},"status":88,"time_spent":172,"timestamp":130}],"crc":45480,"length":99,"msg_type":46,"payload":"Bw0mAGEWAK4ANAAAADEAAAA9AAAAkwAAAC8AAACMAAAAptI7AP0XAXkAvgAAAK8AAACvAAAAjgAAAO0AAAAMAAAAflgVAJkYAAgAggAAAKwAAABbAAAAvwAAAFQAAABSAAAA","preamble":85,"sender":1219}})), "raw_json");
}
test_auto_check_sbp_acquisition_msg_acq_sv_profile_1();

done_testing();