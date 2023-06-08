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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientQuat.yaml
# with generate.py.  Do not modify by hand!

use strict;

BEGIN {
    # add grandparent directory to include path
    use Cwd qw(realpath);
    use File::Basename;
    unshift @INC, realpath(dirname($0))."/../../";
}

use Sbp::Sbp;
use Sbp::ParseUtils;
use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_orientation_msg_orient_quat_1() {
    my $buf = decode_base64("VSACQgAlAAAAAAMAAAAHAAAACAAAAAQAAAAAAEBAAACAQAAAAEEAAEBAAboG");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6ba, "crc");
    
    is($msg->{'length'}, 37, "length");
    
    is($msg->{'msg_type'}, 0x220, "msg_type");
    
    is($msg->{'payload'}, "AAAAAAMAAAAHAAAACAAAAAQAAAAAAEBAAACAQAAAAEEAAEBAAQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 1, "flags");
    
    is($msg->tow(), 0, "tow");
    
    is($msg->w(), 3, "w");
    
    is($msg->w_accuracy(), 3.0, "w_accuracy");
    
    is($msg->x(), 7, "x");
    
    is($msg->x_accuracy(), 4.0, "x_accuracy");
    
    is($msg->y(), 8, "y");
    
    is($msg->y_accuracy(), 8.0, "y_accuracy");
    
    is($msg->z(), 4, "z");
    
    is($msg->z_accuracy(), 3.0, "z_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":1722,"flags":1,"length":37,"msg_type":544,"payload":"AAAAAAMAAAAHAAAACAAAAAQAAAAAAEBAAACAQAAAAEEAAEBAAQ==","preamble":85,"sender":66,"tow":0,"w":3,"w_accuracy":3,"x":7,"x_accuracy":4,"y":8,"y_accuracy":8,"z":4,"z_accuracy":3}})), "raw_json");
}
test_auto_check_sbp_orientation_msg_orient_quat_1();

done_testing();