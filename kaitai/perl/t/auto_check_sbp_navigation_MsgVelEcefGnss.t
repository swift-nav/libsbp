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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelEcefGnss.yaml
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
sub test_auto_check_sbp_navigation_msg_vel_ecef_gnss_1() {
    my $buf = decode_base64("VS0CABAU4OXpHf3///8BAAAABAAAAFkAFQLNEA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x10cd, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x22d, "msg_type");
    
    is($msg->{'payload'}, "4OXpHf3///8BAAAABAAAAFkAFQI=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1000, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 89, "accuracy");
    
    is($msg->flags(), 2, "flags");
    
    is($msg->n_sats(), 21, "n_sats");
    
    is($msg->tow(), 501868000, "tow");
    
    is($msg->x(), -3, "x");
    
    is($msg->y(), 1, "y");
    
    is($msg->z(), 4, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":89,"crc":4301,"flags":2,"length":20,"msg_type":557,"n_sats":21,"payload":"4OXpHf3///8BAAAABAAAAFkAFQI=","preamble":85,"sender":4096,"tow":501868000,"x":-3,"y":1,"z":4}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_vel_ecef_gnss_1();

done_testing();