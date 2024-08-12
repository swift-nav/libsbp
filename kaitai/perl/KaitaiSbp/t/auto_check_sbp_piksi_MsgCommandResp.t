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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCommandResp.yaml
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
sub test_auto_check_sbp_piksi_msg_command_resp_1() {
    my $buf = decode_base64("VbkAOc4IdteDoNJulmek8A==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf0a4, "crc");
    
    is($msg->{'length'}, 8, "length");
    
    is($msg->{'msg_type'}, 0xb9, "msg_type");
    
    is($msg->{'payload'}, "dteDoNJulmc=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xce39, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->code(), 1737912018, "code");
    
    is($msg->sequence(), 2692994934, "sequence");

    is($json->encode($msg), $json->encode($json->decode(q{{"code":1737912018,"crc":61604,"length":8,"msg_type":185,"payload":"dteDoNJulmc=","preamble":85,"sender":52793,"sequence":2692994934}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_command_resp_1();

done_testing();