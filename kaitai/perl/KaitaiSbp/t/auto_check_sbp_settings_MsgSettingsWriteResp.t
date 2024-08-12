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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsWriteResp.yaml
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
sub test_auto_check_sbp_settings_msg_settings_write_resp_1() {
    my $buf = decode_base64("Va8AWzdDmHNlY3Rpb24tbmFtZQBzZXR0aW5nLW5hbWUAc2V0dGluZy12YWx1ZQBlbnVtO3ZhbHVlMSx2YWx1ZTIsdmFsdWUzADYA");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x0036, "crc");
    
    is($msg->{'length'}, 67, "length");
    
    is($msg->{'msg_type'}, 0xaf, "msg_type");
    
    is($msg->{'payload'}, "mHNlY3Rpb24tbmFtZQBzZXR0aW5nLW5hbWUAc2V0dGluZy12YWx1ZQBlbnVtO3ZhbHVlMSx2YWx1ZTIsdmFsdWUzAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x375b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->setting(), "section-name\x00setting-name\x00setting-value\x00enum;value1,value2,value3\x00", "setting");
    
    is($msg->status(), 152, "status");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":54,"length":67,"msg_type":175,"payload":"mHNlY3Rpb24tbmFtZQBzZXR0aW5nLW5hbWUAc2V0dGluZy12YWx1ZQBlbnVtO3ZhbHVlMSx2YWx1ZTIsdmFsdWUzAA==","preamble":85,"sender":14171,"setting":"section-name\u0000setting-name\u0000setting-value\u0000enum;value1,value2,value3\u0000","status":152}})), "raw_json");
}
test_auto_check_sbp_settings_msg_settings_write_resp_1();

done_testing();