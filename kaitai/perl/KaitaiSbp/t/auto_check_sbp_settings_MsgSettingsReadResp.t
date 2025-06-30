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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadResp.yaml
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
sub test_auto_check_sbp_settings_msg_settings_read_resp_1() {
    my $buf = decode_base64("VaUAiPBCc2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQBzZXR0aW5nLXZhbHVlAGVudW07dmFsdWUxLHZhbHVlMix2YWx1ZTMAy8c=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xc7cb, "crc");
    
    is($msg->{'length'}, 66, "length");
    
    is($msg->{'msg_type'}, 0xa5, "msg_type");
    
    is($msg->{'payload'}, "c2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQBzZXR0aW5nLXZhbHVlAGVudW07dmFsdWUxLHZhbHVlMix2YWx1ZTMA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xf088, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->setting(), "section-name\x00setting-name\x00setting-value\x00enum;value1,value2,value3\x00", "setting");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":51147,"length":66,"msg_type":165,"payload":"c2VjdGlvbi1uYW1lAHNldHRpbmctbmFtZQBzZXR0aW5nLXZhbHVlAGVudW07dmFsdWUxLHZhbHVlMix2YWx1ZTMA","preamble":85,"sender":61576,"setting":"section-name\u0000setting-name\u0000setting-value\u0000enum;value1,value2,value3\u0000"}})), "raw_json");
}
test_auto_check_sbp_settings_msg_settings_read_resp_1();

done_testing();
