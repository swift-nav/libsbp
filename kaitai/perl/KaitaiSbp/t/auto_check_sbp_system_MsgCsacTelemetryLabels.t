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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgCsacTelemetryLabels.yaml
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
sub test_auto_check_sbp_system_msg_csac_telemetry_labels_1() {
    my $buf = decode_base64("VQX/W8gMunNvbWUgbGFiZWxzVuw=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xec56, "crc");
    
    is($msg->{'length'}, 12, "length");
    
    is($msg->{'msg_type'}, 0xff05, "msg_type");
    
    is($msg->{'payload'}, "unNvbWUgbGFiZWxz", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xc85b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->id(), 186, "id");
    
    is($msg->telemetry_labels(), "some labels", "telemetry_labels");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":60502,"id":186,"length":12,"msg_type":65285,"payload":"unNvbWUgbGFiZWxz","preamble":85,"sender":51291,"telemetry_labels":"some labels"}})), "raw_json");
}
test_auto_check_sbp_system_msg_csac_telemetry_labels_1();

done_testing();
