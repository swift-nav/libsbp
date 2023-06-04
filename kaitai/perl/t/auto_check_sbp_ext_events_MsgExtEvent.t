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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ext_events/test_MsgExtEvent.yaml
# with generate.py.  Do not modify by hand!

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";

BEGIN {
    # add SBP_PATH to include path and load all modules
    unshift @INC, &SBP_PATH;
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
use t::Utils;
sub test_auto_check_sbp_ext_events_msg_ext_event_1() {
    my $buf = decode_base64("VQEB9QYMMAfH2DEPykEPAAMAPsw=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xcc3e, "crc");
    
    is($msg->{'length'}, 12, "length");
    
    is($msg->{'msg_type'}, 0x101, "msg_type");
    
    is($msg->{'payload'}, "MAfH2DEPykEPAAMA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x6f5, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 3, "flags");
    
    is($msg->ns_residual(), 999882, "ns_residual");
    
    is($msg->pin(), 0, "pin");
    
    is($msg->tow(), 254924999, "tow");
    
    is($msg->wn(), 1840, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":52286,"flags":3,"length":12,"msg_type":257,"ns_residual":999882,"payload":"MAfH2DEPykEPAAMA","pin":0,"preamble":85,"sender":1781,"tow":254924999,"wn":1840}})), "raw_json");
}
test_auto_check_sbp_ext_events_msg_ext_event_1();

done_testing();