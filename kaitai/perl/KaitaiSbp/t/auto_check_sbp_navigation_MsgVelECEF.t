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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEF.yaml
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
sub test_auto_check_sbp_navigation_msg_vel_ecef_1() {
    my $buf = decode_base64("VQ0C04gUKPR6E/j////7////CgAAAAAADgC1Yw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x63b5, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x20d, "msg_type");
    
    is($msg->{'payload'}, "KPR6E/j////7////CgAAAAAADgA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 14, "n_sats");
    
    is($msg->tow(), 326825000, "tow");
    
    is($msg->x(), -8, "x");
    
    is($msg->y(), -5, "y");
    
    is($msg->z(), 10, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":25525,"flags":0,"length":20,"msg_type":525,"n_sats":14,"payload":"KPR6E/j////7////CgAAAAAADgA=","preamble":85,"sender":35027,"tow":326825000,"x":-8,"y":-5,"z":10}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_2() {
    my $buf = decode_base64("VQ0C04gUHPZ6E/T////u////CwAAAAAADwDXeA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x78d7, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x20d, "msg_type");
    
    is($msg->{'payload'}, "HPZ6E/T////u////CwAAAAAADwA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326825500, "tow");
    
    is($msg->x(), -12, "x");
    
    is($msg->y(), -18, "y");
    
    is($msg->z(), 11, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":30935,"flags":0,"length":20,"msg_type":525,"n_sats":15,"payload":"HPZ6E/T////u////CwAAAAAADwA=","preamble":85,"sender":35027,"tow":326825500,"x":-12,"y":-18,"z":11}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_3() {
    my $buf = decode_base64("VQ0C04gUEPh6E/j////6////BwAAAAAADwD43Q==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xddf8, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x20d, "msg_type");
    
    is($msg->{'payload'}, "EPh6E/j////6////BwAAAAAADwA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326826000, "tow");
    
    is($msg->x(), -8, "x");
    
    is($msg->y(), -6, "y");
    
    is($msg->z(), 7, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":56824,"flags":0,"length":20,"msg_type":525,"n_sats":15,"payload":"EPh6E/j////6////BwAAAAAADwA=","preamble":85,"sender":35027,"tow":326826000,"x":-8,"y":-6,"z":7}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_4() {
    my $buf = decode_base64("VQ0C04gUBPp6E/n////v////EAAAAAAADwABpw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa701, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x20d, "msg_type");
    
    is($msg->{'payload'}, "BPp6E/n////v////EAAAAAAADwA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326826500, "tow");
    
    is($msg->x(), -7, "x");
    
    is($msg->y(), -17, "y");
    
    is($msg->z(), 16, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":42753,"flags":0,"length":20,"msg_type":525,"n_sats":15,"payload":"BPp6E/n////v////EAAAAAAADwA=","preamble":85,"sender":35027,"tow":326826500,"x":-7,"y":-17,"z":16}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_vel_ecef_5() {
    my $buf = decode_base64("VQ0C04gU+Pt6E/f////z////DgAAAAAADwC/Kw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x2bbf, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0x20d, "msg_type");
    
    is($msg->{'payload'}, "+Pt6E/f////z////DgAAAAAADwA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326827000, "tow");
    
    is($msg->x(), -9, "x");
    
    is($msg->y(), -13, "y");
    
    is($msg->z(), 14, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":11199,"flags":0,"length":20,"msg_type":525,"n_sats":15,"payload":"+Pt6E/f////z////DgAAAAAADwA=","preamble":85,"sender":35027,"tow":326827000,"x":-9,"y":-13,"z":14}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_vel_ecef_1();
test_auto_check_sbp_navigation_msg_vel_ecef_2();
test_auto_check_sbp_navigation_msg_vel_ecef_3();
test_auto_check_sbp_navigation_msg_vel_ecef_4();
test_auto_check_sbp_navigation_msg_vel_ecef_5();

done_testing();