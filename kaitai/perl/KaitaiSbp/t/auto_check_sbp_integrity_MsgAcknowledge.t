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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/integrity/test_MsgAcknowledge.yaml
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
sub test_auto_check_sbp_integrity_msg_acknowledge_1() {
    my $buf = decode_base64("VdILKgALHkDiAQAAAQABAAJWsg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xB256, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0xBD2, "msg_type");
    
    is($msg->{'payload'}, "HkDiAQAAAQABAAI=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x2A, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->area_id(), 123456, "area_id");
    
    is($msg->correction_mask_on_demand(), 1, "correction_mask_on_demand");
    
    is($msg->correction_mask_stream(), 1, "correction_mask_stream");
    
    is($msg->request_id(), 30, "request_id");
    
    is($msg->response_code(), 0, "response_code");
    
    is($msg->solution_id(), 2, "solution_id");

    is($json->encode($msg), $json->encode($json->decode(q{{"area_id":123456,"correction_mask_on_demand":1,"correction_mask_stream":1,"crc":45654,"length":11,"msg_type":3026,"payload":"HkDiAQAAAQABAAI=","preamble":85,"request_id":30,"response_code":0,"sender":42,"solution_id":2}})), "raw_json");
}
test_auto_check_sbp_integrity_msg_acknowledge_1();

done_testing();