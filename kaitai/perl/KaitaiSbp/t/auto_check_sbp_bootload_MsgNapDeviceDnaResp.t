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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/bootload/test_MsgNapDeviceDnaResp.yaml
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
sub test_auto_check_sbp_bootload_msg_nap_device_dna_resp_1() {
    my $buf = decode_base64("Vd0AqTgIArsBgq30Q3pGWw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5b46, "crc");
    
    is($msg->{'length'}, 8, "length");
    
    is($msg->{'msg_type'}, 0xdd, "msg_type");
    
    is($msg->{'payload'}, "ArsBgq30Q3o=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x38a9, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->dna()), $json->encode($json->decode(q{[2,187,1,130,173,244,67,122]})), "dna");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":23366,"dna":[2,187,1,130,173,244,67,122],"length":8,"msg_type":221,"payload":"ArsBgq30Q3o=","preamble":85,"sender":14505}})), "raw_json");
}
test_auto_check_sbp_bootload_msg_nap_device_dna_resp_1();

done_testing();