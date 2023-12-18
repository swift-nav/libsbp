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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxCpuState.yaml
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
sub test_auto_check_sbp_linux_msg_linux_cpu_state_1() {
    my $buf = decode_base64("VQh/lIVGZXrDYtcjXusUcHJvY2Vzcy1uYW1lAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNETl");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe544, "crc");
    
    is($msg->{'length'}, 70, "length");
    
    is($msg->{'msg_type'}, 0x7f08, "msg_type");
    
    is($msg->{'payload'}, "ZXrDYtcjXusUcHJvY2Vzcy1uYW1lAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x8594, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cmdline(), "/path/to/process-name arg0 arg1 arg2 arg3 arg4", "cmdline");
    
    is($msg->flags(), 20, "flags");
    
    is($msg->index(), 101, "index");
    
    is($msg->pcpu(), 98, "pcpu");
    
    is($msg->pid(), 50042, "pid");
    
    is($msg->time(), 3948815319, "time");
    
    is($msg->tname(), "process-name\x00\x00\x00", "tname");

    is($json->encode($msg), $json->encode($json->decode(q{{"cmdline":"/path/to/process-name arg0 arg1 arg2 arg3 arg4","crc":58692,"flags":20,"index":101,"length":70,"msg_type":32520,"payload":"ZXrDYtcjXusUcHJvY2Vzcy1uYW1lAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNA==","pcpu":98,"pid":50042,"preamble":85,"sender":34196,"time":3948815319,"tname":"process-name\u0000\u0000\u0000"}})), "raw_json");
}
test_auto_check_sbp_linux_msg_linux_cpu_state_1();

done_testing();