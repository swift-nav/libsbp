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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxMemState.yaml
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
sub test_auto_check_sbp_linux_msg_linux_mem_state_1() {
    my $buf = decode_base64("VQl/X/1Gmr/fE/c1GrtMcHJvY2Vzcy1uYW1lAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNAO1");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb503, "crc");
    
    is($msg->{'length'}, 70, "length");
    
    is($msg->{'msg_type'}, 0x7f09, "msg_type");
    
    is($msg->{'payload'}, "mr/fE/c1GrtMcHJvY2Vzcy1uYW1lAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xfd5f, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cmdline(), "/path/to/process-name arg0 arg1 arg2 arg3 arg4", "cmdline");
    
    is($msg->flags(), 76, "flags");
    
    is($msg->index(), 154, "index");
    
    is($msg->pid(), 57279, "pid");
    
    is($msg->pmem(), 19, "pmem");
    
    is($msg->time(), 3139057143, "time");
    
    is($msg->tname(), "process-name\x00\x00\x00", "tname");

    is($json->encode($msg), $json->encode($json->decode(q{{"cmdline":"/path/to/process-name arg0 arg1 arg2 arg3 arg4","crc":46339,"flags":76,"index":154,"length":70,"msg_type":32521,"payload":"mr/fE/c1GrtMcHJvY2Vzcy1uYW1lAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNA==","pid":57279,"pmem":19,"preamble":85,"sender":64863,"time":3139057143,"tname":"process-name\u0000\u0000\u0000"}})), "raw_json");
}
test_auto_check_sbp_linux_msg_linux_mem_state_1();

done_testing();