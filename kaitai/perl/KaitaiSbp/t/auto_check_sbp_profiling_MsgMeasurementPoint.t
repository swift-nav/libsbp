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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgMeasurementPoint.yaml
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
sub test_auto_check_sbp_profiling_msg_measurement_point_1() {
    my $buf = decode_base64("VQDPABAw+gcAALQAAgAAACgAAACCyZSNYVUAABKCyZQAAAAAQkCdDwAAAAASAHJvdXRlKCkA1KU=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa5d4, "crc");
    
    is($msg->{'length'}, 48, "length");
    
    is($msg->{'msg_type'}, 0xCF00, "msg_type");
    
    is($msg->{'payload'}, "+gcAALQAAgAAACgAAACCyZSNYVUAABKCyZQAAAAAQkCdDwAAAAASAHJvdXRlKCkA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1000, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->func(), "route()\x00", "func");
    
    is($msg->id(), 2496234002, "id");
    
    is($msg->line(), 18, "line");
    
    is($msg->max(), 40, "max");
    
    is($msg->min(), 2, "min");
    
    is($msg->num_executions(), 180, "num_executions");
    
    is($msg->return_addr(), 93877475527042, "return_addr");
    
    is($msg->slice_time(), 261963842, "slice_time");
    
    is($msg->total_time(), 2042, "total_time");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":42452,"func":"route()\u0000","id":2496234002,"length":48,"line":18,"max":40,"min":2,"msg_type":52992,"num_executions":180,"payload":"+gcAALQAAgAAACgAAACCyZSNYVUAABKCyZQAAAAAQkCdDwAAAAASAHJvdXRlKCkA","preamble":85,"return_addr":93877475527042,"sender":4096,"slice_time":261963842,"total_time":2042}})), "raw_json");
}
test_auto_check_sbp_profiling_msg_measurement_point_1();

done_testing();