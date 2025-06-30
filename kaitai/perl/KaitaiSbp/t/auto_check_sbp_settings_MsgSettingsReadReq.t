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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadReq.yaml
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
sub test_auto_check_sbp_settings_msg_settings_read_req_1() {
    my $buf = decode_base64("VaQAmNYac2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQC15A==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe4b5, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0xa4, "msg_type");
    
    is($msg->{'payload'}, "c2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xd698, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->setting(), "section-name\x00setting-name\x00", "setting");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":58549,"length":26,"msg_type":164,"payload":"c2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQA=","preamble":85,"sender":54936,"setting":"section-name\u0000setting-name\u0000"}})), "raw_json");
}
test_auto_check_sbp_settings_msg_settings_read_req_1();

done_testing();
