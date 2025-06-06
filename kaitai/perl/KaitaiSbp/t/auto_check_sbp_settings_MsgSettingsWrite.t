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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsWrite.yaml
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
sub test_auto_check_sbp_settings_msg_settings_write_1() {
    my $buf = decode_base64("VaAAewAoc2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQBzZXR0aW5nLXZhbHVlAPQK");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xaf4, "crc");
    
    is($msg->{'length'}, 40, "length");
    
    is($msg->{'msg_type'}, 0xa0, "msg_type");
    
    is($msg->{'payload'}, "c2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQBzZXR0aW5nLXZhbHVlAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x7b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->setting(), "section-name\x00setting-name\x00setting-value\x00", "setting");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":2804,"length":40,"msg_type":160,"payload":"c2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQBzZXR0aW5nLXZhbHVlAA==","preamble":85,"sender":123,"setting":"section-name\u0000setting-name\u0000setting-value\u0000"}})), "raw_json");
}
test_auto_check_sbp_settings_msg_settings_write_1();

done_testing();
