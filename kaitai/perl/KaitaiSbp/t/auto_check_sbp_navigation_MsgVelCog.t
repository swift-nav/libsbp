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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelCog.yaml
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
sub test_auto_check_sbp_navigation_msg_vel_cog_1() {
    my $buf = decode_base64("VRwC04geMPZ6E+gDAADQBwAAuAsAAKAPAACIEwAAcBcAAD4A1ME=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xC1D4, "crc");
    
    is($msg->{'length'}, 30, "length");
    
    is($msg->{'msg_type'}, 0x21C, "msg_type");
    
    is($msg->{'payload'}, "MPZ6E+gDAADQBwAAuAsAAKAPAACIEwAAcBcAAD4A", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88D3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cog(), 1000, "cog");
    
    is($msg->cog_accuracy(), 4000, "cog_accuracy");
    
    is($msg->flags(), 62, "flags");
    
    is($msg->sog(), 2000, "sog");
    
    is($msg->sog_accuracy(), 5000, "sog_accuracy");
    
    is($msg->tow(), 326825520, "tow");
    
    is($msg->v_up(), 3000, "v_up");
    
    is($msg->v_up_accuracy(), 6000, "v_up_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"cog":1000,"cog_accuracy":4000,"crc":49620,"flags":62,"length":30,"msg_type":540,"payload":"MPZ6E+gDAADQBwAAuAsAAKAPAACIEwAAcBcAAD4A","preamble":85,"sender":35027,"sog":2000,"sog_accuracy":5000,"tow":326825520,"v_up":3000,"v_up_accuracy":6000}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_cog_2() {
    my $buf = decode_base64("VRwC04geMPZ6E3sAAADIAQAAGPz//wCVugpkAAAAZAAAAAAAWnI=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x725A, "crc");
    
    is($msg->{'length'}, 30, "length");
    
    is($msg->{'msg_type'}, 0x21C, "msg_type");
    
    is($msg->{'payload'}, "MPZ6E3sAAADIAQAAGPz//wCVugpkAAAAZAAAAAAA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88D3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cog(), 123, "cog");
    
    is($msg->cog_accuracy(), 180000000, "cog_accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->sog(), 456, "sog");
    
    is($msg->sog_accuracy(), 100, "sog_accuracy");
    
    is($msg->tow(), 326825520, "tow");
    
    is($msg->v_up(), -1000, "v_up");
    
    is($msg->v_up_accuracy(), 100, "v_up_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"cog":123,"cog_accuracy":180000000,"crc":29274,"flags":0,"length":30,"msg_type":540,"payload":"MPZ6E3sAAADIAQAAGPz//wCVugpkAAAAZAAAAAAA","preamble":85,"sender":35027,"sog":456,"sog_accuracy":100,"tow":326825520,"v_up":-1000,"v_up_accuracy":100}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_cog_3() {
    my $buf = decode_base64("VRwC04geMPZ6EwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAKtI=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xD22A, "crc");
    
    is($msg->{'length'}, 30, "length");
    
    is($msg->{'msg_type'}, 0x21C, "msg_type");
    
    is($msg->{'payload'}, "MPZ6EwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88D3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cog(), 0, "cog");
    
    is($msg->cog_accuracy(), 0, "cog_accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->sog(), 0, "sog");
    
    is($msg->sog_accuracy(), 0, "sog_accuracy");
    
    is($msg->tow(), 326825520, "tow");
    
    is($msg->v_up(), 0, "v_up");
    
    is($msg->v_up_accuracy(), 0, "v_up_accuracy");

    is($json->encode($msg), $json->encode($json->decode(q{{"cog":0,"cog_accuracy":0,"crc":53802,"flags":0,"length":30,"msg_type":540,"payload":"MPZ6EwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","preamble":85,"sender":35027,"sog":0,"sog_accuracy":0,"tow":326825520,"v_up":0,"v_up_accuracy":0}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_vel_cog_1();
test_auto_check_sbp_navigation_msg_vel_cog_2();
test_auto_check_sbp_navigation_msg_vel_cog_3();

done_testing();