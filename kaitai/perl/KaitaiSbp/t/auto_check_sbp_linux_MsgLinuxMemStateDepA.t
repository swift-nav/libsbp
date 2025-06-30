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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxMemStateDepA.yaml
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
sub test_auto_check_sbp_linux_msg_linux_mem_state_dep_a_1() {
    my $buf = decode_base64("VQF/uW1B910wwXByb2Nlc3MtbmFtZQAAAC9wYXRoL3RvL3Byb2Nlc3MtbmFtZSBhcmcwIGFyZzEgYXJnMiBhcmczIGFyZzQRiQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8911, "crc");
    
    is($msg->{'length'}, 65, "length");
    
    is($msg->{'msg_type'}, 0x7f01, "msg_type");
    
    is($msg->{'payload'}, "910wwXByb2Nlc3MtbmFtZQAAAC9wYXRoL3RvL3Byb2Nlc3MtbmFtZSBhcmcwIGFyZzEgYXJnMiBhcmczIGFyZzQ=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x6db9, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cmdline(), "/path/to/process-name arg0 arg1 arg2 arg3 arg4", "cmdline");
    
    is($msg->index(), 247, "index");
    
    is($msg->pid(), 12381, "pid");
    
    is($msg->pmem(), 193, "pmem");
    
    is($msg->tname(), "process-name\x00\x00\x00", "tname");

    is($json->encode($msg), $json->encode($json->decode(q{{"cmdline":"/path/to/process-name arg0 arg1 arg2 arg3 arg4","crc":35089,"index":247,"length":65,"msg_type":32513,"payload":"910wwXByb2Nlc3MtbmFtZQAAAC9wYXRoL3RvL3Byb2Nlc3MtbmFtZSBhcmcwIGFyZzEgYXJnMiBhcmczIGFyZzQ=","pid":12381,"pmem":193,"preamble":85,"sender":28089,"tname":"process-name\u0000\u0000\u0000"}})), "raw_json");
}
test_auto_check_sbp_linux_msg_linux_mem_state_dep_a_1();

done_testing();
