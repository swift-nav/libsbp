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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/mag/test_MsgMagRaw.yaml
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
sub test_auto_check_sbp_mag_msg_mag_raw_1() {
    my $buf = decode_base64("VQIJwwQLreOexs5iA+YCbuWfFw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x179f, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x902, "msg_type");
    
    is($msg->{'payload'}, "reOexs5iA+YCbuU=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->mag_x(), 866, "mag_x");
    
    is($msg->mag_y(), 742, "mag_y");
    
    is($msg->mag_z(), -6802, "mag_z");
    
    is($msg->tow(), 3332301741, "tow");
    
    is($msg->tow_f(), 206, "tow_f");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":6047,"length":11,"mag_x":866,"mag_y":742,"mag_z":-6802,"msg_type":2306,"payload":"reOexs5iA+YCbuU=","preamble":85,"sender":1219,"tow":3332301741,"tow_f":206}})), "raw_json");
}
test_auto_check_sbp_mag_msg_mag_raw_1();

done_testing();