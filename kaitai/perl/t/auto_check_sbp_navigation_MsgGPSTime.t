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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTime.yaml
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
sub test_auto_check_sbp_navigation_msg_gps_time_1() {
    my $buf = decode_base64("VQIB04gLgAco9HoT9IsCAAAimA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9822, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x102, "msg_type");
    
    is($msg->{'payload'}, "gAco9HoT9IsCAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), 166900, "ns_residual");
    
    is($msg->tow(), 326825000, "tow");
    
    is($msg->wn(), 1920, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":38946,"flags":0,"length":11,"msg_type":258,"ns_residual":166900,"payload":"gAco9HoT9IsCAAA=","preamble":85,"sender":35027,"tow":326825000,"wn":1920}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_2() {
    my $buf = decode_base64("VQIB04gLgAcc9noTfuoDAABBAw==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x341, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x102, "msg_type");
    
    is($msg->{'payload'}, "gAcc9noTfuoDAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), 256638, "ns_residual");
    
    is($msg->tow(), 326825500, "tow");
    
    is($msg->wn(), 1920, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":833,"flags":0,"length":11,"msg_type":258,"ns_residual":256638,"payload":"gAcc9noTfuoDAAA=","preamble":85,"sender":35027,"tow":326825500,"wn":1920}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_3() {
    my $buf = decode_base64("VQIB04gLgAcQ+HoTgQwEAAAMVA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x540c, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x102, "msg_type");
    
    is($msg->{'payload'}, "gAcQ+HoTgQwEAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), 265345, "ns_residual");
    
    is($msg->tow(), 326826000, "tow");
    
    is($msg->wn(), 1920, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":21516,"flags":0,"length":11,"msg_type":258,"ns_residual":265345,"payload":"gAcQ+HoTgQwEAAA=","preamble":85,"sender":35027,"tow":326826000,"wn":1920}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_4() {
    my $buf = decode_base64("VQIB04gLgAcE+noTicwEAAAypQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa532, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x102, "msg_type");
    
    is($msg->{'payload'}, "gAcE+noTicwEAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), 314505, "ns_residual");
    
    is($msg->tow(), 326826500, "tow");
    
    is($msg->wn(), 1920, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":42290,"flags":0,"length":11,"msg_type":258,"ns_residual":314505,"payload":"gAcE+noTicwEAAA=","preamble":85,"sender":35027,"tow":326826500,"wn":1920}})), "raw_json");
}
sub test_auto_check_sbp_navigation_msg_gps_time_5() {
    my $buf = decode_base64("VQIB04gLgAf4+3oTtYkFAAC0IQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x21b4, "crc");
    
    is($msg->{'length'}, 11, "length");
    
    is($msg->{'msg_type'}, 0x102, "msg_type");
    
    is($msg->{'payload'}, "gAf4+3oTtYkFAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88d3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->ns_residual(), 362933, "ns_residual");
    
    is($msg->tow(), 326827000, "tow");
    
    is($msg->wn(), 1920, "wn");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":8628,"flags":0,"length":11,"msg_type":258,"ns_residual":362933,"payload":"gAf4+3oTtYkFAAA=","preamble":85,"sender":35027,"tow":326827000,"wn":1920}})), "raw_json");
}
test_auto_check_sbp_navigation_msg_gps_time_1();
test_auto_check_sbp_navigation_msg_gps_time_2();
test_auto_check_sbp_navigation_msg_gps_time_3();
test_auto_check_sbp_navigation_msg_gps_time_4();
test_auto_check_sbp_navigation_msg_gps_time_5();

done_testing();