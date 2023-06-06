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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgReferenceFrameParam.yaml
# with generate.py.  Do not modify by hand!

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";

BEGIN {
    # add SBP_PATH to include path and load all modules
    unshift @INC, &SBP_PATH;
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_navigation_msg_reference_frame_param_1() {
    my $buf = decode_base64("VUQCQgB8AWZvbwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYmFyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEBQAGAAcAAAAIAAAACQAAAAoAAAALAAAADAAAAA0AAAAOAAAADwAAABAAAAARAAAAEgAAABMAAAAUAAah");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'msg_type'}, 0x0244, "msg_type");
    
    is($msg->{'sender'}, 0x0042, "sender");
    
    is($msg->{'length'}, 124, "length");
    
    is($msg->{'payload'}, "AWZvbwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYmFyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEBQAGAAcAAAAIAAAACQAAAAoAAAALAAAADAAAAA0AAAAOAAAADwAAABAAAAARAAAAEgAAABMAAAAUAA==", "payload");
    
    is($msg->{'crc'}, 0xA106, "crc");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->delta_x0(), 7, "delta_x0");
    
    is($msg->delta_y0(), 8, "delta_y0");
    
    is($msg->delta_z0(), 9, "delta_z0");
    
    is($msg->dot_delta_x0(), 14, "dot_delta_x0");
    
    is($msg->dot_delta_y0(), 15, "dot_delta_y0");
    
    is($msg->dot_delta_z0(), 16, "dot_delta_z0");
    
    is($msg->dot_scale(), 20, "dot_scale");
    
    is($msg->dot_theta_01(), 17, "dot_theta_01");
    
    is($msg->dot_theta_02(), 18, "dot_theta_02");
    
    is($msg->dot_theta_03(), 19, "dot_theta_03");
    
    is($msg->re_t0(), 6, "re_t0");
    
    is($msg->scale(), 13, "scale");
    
    is($msg->sin(), 4, "sin");
    
    is($msg->sn(), "foo\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "sn");
    
    is($msg->ssr_iod(), 1, "ssr_iod");
    
    is($msg->theta_01(), 10, "theta_01");
    
    is($msg->theta_02(), 11, "theta_02");
    
    is($msg->theta_03(), 12, "theta_03");
    
    is($msg->tn(), "bar\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "tn");
    
    is($msg->utn(), 5, "utn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":41222,"delta_x0":7,"delta_y0":8,"delta_z0":9,"dot_delta_x0":14,"dot_delta_y0":15,"dot_delta_z0":16,"dot_scale":20,"dot_theta_01":17,"dot_theta_02":18,"dot_theta_03":19,"length":124,"msg_type":580,"payload":"AWZvbwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYmFyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEBQAGAAcAAAAIAAAACQAAAAoAAAALAAAADAAAAA0AAAAOAAAADwAAABAAAAARAAAAEgAAABMAAAAUAA==","preamble":85,"re_t0":6,"scale":13,"sender":66,"sin":4,"sn":"foo\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","ssr_iod":1,"theta_01":10,"theta_02":11,"theta_03":12,"tn":"bar\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","utn":5}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_reference_frame_param_1();

done_testing();