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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEF.yaml
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
sub test_auto_check_sbp_navigation_msg_pos_ecef_1() {
    my $buf = decode_base64("VQkC04ggEPh6E0kdLoS2ekTB28AdsHl3UMFTC9JaT0tNQQAADwJUBg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x654, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x209, "msg_type");
    
    is($msg->{'payload'}, "EPh6E0kdLoS2ekTB28AdsHl3UMFTC9JaT0tNQQAADwI=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 2, "flags");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326826000, "tow");
    
    is($msg->x(), -2684269.0326572997, "x");
    
    is($msg->y(), -4316646.751816, "y");
    
    is($msg->z(), 3839646.7095350414, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":1620,"flags":2,"length":32,"msg_type":521,"n_sats":15,"payload":"EPh6E0kdLoS2ekTB28AdsHl3UMFTC9JaT0tNQQAADwI=","preamble":85,"sender":35027,"tow":326826000,"x":-2684269.0326572997,"y":-4316646.751816,"z":3839646.7095350414}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_ecef_2() {
    my $buf = decode_base64("VQkC04gg+Pt6E2dqOYi2ekTBsPLIsHl3UMH0h2E7T0tNQQAADwKT2A==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd893, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x209, "msg_type");
    
    is($msg->{'payload'}, "+Pt6E2dqOYi2ekTBsPLIsHl3UMH0h2E7T0tNQQAADwI=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 2, "flags");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326827000, "tow");
    
    is($msg->x(), -2684269.064252186, "x");
    
    is($msg->y(), -4316646.762264892, "y");
    
    is($msg->z(), 3839646.463913912, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":55443,"flags":2,"length":32,"msg_type":521,"n_sats":15,"payload":"+Pt6E2dqOYi2ekTBsPLIsHl3UMH0h2E7T0tNQQAADwI=","preamble":85,"sender":35027,"tow":326827000,"x":-2684269.064252186,"y":-4316646.762264892,"z":3839646.463913912}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_ecef_3() {
    my $buf = decode_base64("VQkC04gg4P96E2Wz8ra2ekTBgsSRx3l3UMHUCv0PT0tNQQAADwIoyQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xc928, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x209, "msg_type");
    
    is($msg->{'payload'}, "4P96E2Wz8ra2ekTBgsSRx3l3UMHUCv0PT0tNQQAADwI=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 2, "flags");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326828000, "tow");
    
    is($msg->x(), -2684269.4292816394, "x");
    
    is($msg->y(), -4316647.118271949, "y");
    
    is($msg->z(), 3839646.124909738, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":51496,"flags":2,"length":32,"msg_type":521,"n_sats":15,"payload":"4P96E2Wz8ra2ekTBgsSRx3l3UMHUCv0PT0tNQQAADwI=","preamble":85,"sender":35027,"tow":326828000,"x":-2684269.4292816394,"y":-4316647.118271949,"z":3839646.124909738}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_pos_ecef_4() {
    my $buf = decode_base64("VQkC04ggyAN7E5LWhNe2ekTB1UQx13l3UMFHIm7zTktNQQAADwK7Vg==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x56bb, "crc");
    
    is($msg->{'length'}, 32, "length");
    
    is($msg->{'msg_type'}, 0x209, "msg_type");
    
    is($msg->{'payload'}, "yAN7E5LWhNe2ekTB1UQx13l3UMFHIm7zTktNQQAADwI=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->accuracy(), 0, "accuracy");
    
    is($msg->flags(), 2, "flags");
    
    is($msg->n_sats(), 15, "n_sats");
    
    is($msg->tow(), 326829000, "tow");
    
    is($msg->x(), -2684269.683741399, "x");
    
    is($msg->y(), -4316647.3623821335, "y");
    
    is($msg->z(), 3839645.90179852, "z");

    is($json->encode($msg), $json->encode($json->decode(q{{"accuracy":0,"crc":22203,"flags":2,"length":32,"msg_type":521,"n_sats":15,"payload":"yAN7E5LWhNe2ekTB1UQx13l3UMFHIm7zTktNQQAADwI=","preamble":85,"sender":35027,"tow":326829000,"x":-2684269.683741399,"y":-4316647.3623821335,"z":3839645.90179852}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_pos_ecef_1();
test_auto_check_sbp_navigation_msg_pos_ecef_2();
test_auto_check_sbp_navigation_msg_pos_ecef_3();
test_auto_check_sbp_navigation_msg_pos_ecef_4();

done_testing();