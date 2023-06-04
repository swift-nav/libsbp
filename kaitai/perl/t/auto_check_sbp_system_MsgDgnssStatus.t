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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgDgnssStatus.yaml
# with generate.py.  Do not modify by hand!

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";

BEGIN {
    # load all modules from SBP_PATH
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_system_msg_dgnss_status_1() {
    my $buf = decode_base64("VQL/QgALADIADFNreWxhcmvKAQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x1ca, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0xff02, "msg_type");
    
    is($msg->{'payload'}, "ADIADFNreWxhcms=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->latency(), 50, "latency");
    
    is($msg->num_signals(), 12, "num_signals");
    
    is($msg->source(), "Skylark", "source");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":458,"flags":0,"latency":50,"length":11,"msg_type":65282,"num_signals":12,"payload":"ADIADFNreWxhcms=","preamble":85,"sender":66,"source":"Skylark"}})), "raw_json");
}
test_auto_check_sbp_system_msg_dgnss_status_1();

done_testing();