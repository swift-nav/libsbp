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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFGNSS.yaml
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
sub test_auto_check_sbp_navigation_msg_pos_ecefgnss_1() {
    my $buf = decode_base64("VSkCABAgGOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQbYAEgSHAg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x287, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x229, "msg_type");
    
    is($msg->{'payload'}, "GOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQbYAEgQ=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1000, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 182, "accuracy");
    
    is($msg->flags(), 4, "flags");
    
    is($msg->n_sats(), 18, "n_sats");
    
    is($msg->tow(), 501867800, "tow");
    
    is($msg->x(), -2694229.7079770807, "x");
    
    is($msg->y(), -4264073.427345817, "y");
    
    is($msg->z(), 3890655.013186158, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":182,"crc":647,"flags":4,"length":32,"msg_type":553,"n_sats":18,"payload":"GOXpHTT+ntoqjkTBRaJZWyJEUMGDFbCB765NQbYAEgQ=","preamble":85,"sender":4096,"tow":501867800,"x":-2694229.7079770807,"y":-4264073.427345817,"z":3890655.013186158}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_pos_ecefgnss_1();

done_testing();