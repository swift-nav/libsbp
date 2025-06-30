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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashReadResp.yaml
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
sub test_auto_check_sbp_flash_msg_flash_read_resp_1() {
    my $buf = decode_base64("VeEAwwQFiJs0rHyVhw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8795, "crc");
    
    is($msg->{'length'}, 5, "length");
    
    is($msg->{'msg_type'}, 0xe1, "msg_type");
    
    is($msg->{'payload'}, "iJs0rHw=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->addr_len(), 124, "addr_len");
    
    is($json->encode($msg->addr_start()), $json->encode($json->decode(q{[155,52,172]})), "addr_start");
    
    is($msg->target(), 136, "target");

    is($json->encode($msg), $json->encode($json->decode(q{{"addr_len":124,"addr_start":[155,52,172],"crc":34709,"length":5,"msg_type":225,"payload":"iJs0rHw=","preamble":85,"sender":1219,"target":136}})), "raw_json");
}
test_auto_check_sbp_flash_msg_flash_read_resp_1();

done_testing();
