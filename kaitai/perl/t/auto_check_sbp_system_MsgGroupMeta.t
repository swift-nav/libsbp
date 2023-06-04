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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgGroupMeta.yaml
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
sub test_auto_check_sbp_system_msg_group_meta_1() {
    my $buf = decode_base64("VQr/7u4JAQIDCv8KAgL/Ag4=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe02, "crc");
    
    is($msg->{'length'}, 9, "length");
    
    is($msg->{'msg_type'}, 0xFF0A, "msg_type");
    
    is($msg->{'payload'}, "AQIDCv8KAgL/", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xEEEE, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 2, "flags");
    
    is($msg->group_id(), 1, "group_id");
    
    is($json->encode($msg->group_msgs()), $json->encode($json->decode(q{[65290,522,65282]})), "group_msgs");
    
    is($msg->n_group_msgs(), 3, "n_group_msgs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":3586,"flags":2,"group_id":1,"group_msgs":[65290,522,65282],"length":9,"msg_type":65290,"n_group_msgs":3,"payload":"AQIDCv8KAgL/","preamble":85,"sender":61166}})), "raw_json");
}
sub test_auto_check_sbp_system_msg_group_meta_2() {
    my $buf = decode_base64("VQr/FQMfAQEOAgEDAQoCEQIJAhQCDgISAg0CFQIhAgP/Bv8O/1Ka");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9a52, "crc");
    
    is($msg->{'length'}, 31, "length");
    
    is($msg->{'payload'}, "AQEOAgEDAQoCEQIJAhQCDgISAg0CFQIhAgP/Bv8O/w==", "payload");
    
    is($msg->{'msg_type'}, 0xFF0A, "msg_type");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x315, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 1, "flags");
    
    is($msg->group_id(), 1, "group_id");
    
    is($json->encode($msg->group_msgs()), $json->encode($json->decode(q{[258,259,522,529,521,532,526,530,525,533,545,65283,65286,65294]})), "group_msgs");
    
    is($msg->n_group_msgs(), 14, "n_group_msgs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":39506,"flags":1,"group_id":1,"group_msgs":[258,259,522,529,521,532,526,530,525,533,545,65283,65286,65294],"length":31,"msg_type":65290,"n_group_msgs":14,"payload":"AQEOAgEDAQoCEQIJAhQCDgISAg0CFQIhAgP/Bv8O/w==","preamble":85,"sender":789}})), "raw_json");
}
test_auto_check_sbp_system_msg_group_meta_1();
test_auto_check_sbp_system_msg_group_meta_2();

done_testing();