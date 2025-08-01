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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgMaskSatellite.yaml
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
sub test_auto_check_sbp_piksi_msg_mask_satellite_1() {
    my $buf = decode_base64("VSsArZcDt1c5E5M=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9313, "crc");
    
    is($msg->{'length'}, 3, "length");
    
    is($msg->{'msg_type'}, 0x2b, "msg_type");
    
    is($msg->{'payload'}, "t1c5", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x97ad, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->mask(), 183, "mask");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":57,"sat":87}})), "sid");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":37651,"length":3,"mask":183,"msg_type":43,"payload":"t1c5","preamble":85,"sender":38829,"sid":{"code":57,"sat":87}}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_mask_satellite_1();

done_testing();
