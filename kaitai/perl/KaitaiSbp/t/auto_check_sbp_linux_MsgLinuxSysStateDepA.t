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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSysStateDepA.yaml
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
sub test_auto_check_sbp_linux_msg_linux_sys_state_dep_a_1() {
    my $buf = decode_base64("VQJ/VDgKvKPTwnNHZWd8yd/f");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xdfdf, "crc");
    
    is($msg->{'length'}, 10, "length");
    
    is($msg->{'msg_type'}, 0x7f02, "msg_type");
    
    is($msg->{'payload'}, "vKPTwnNHZWd8yQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x3854, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->mem_total(), 41916, "mem_total");
    
    is($msg->pcpu(), 211, "pcpu");
    
    is($msg->pid_count(), 51580, "pid_count");
    
    is($msg->pmem(), 194, "pmem");
    
    is($msg->procs_starting(), 18291, "procs_starting");
    
    is($msg->procs_stopping(), 26469, "procs_stopping");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":57311,"length":10,"mem_total":41916,"msg_type":32514,"payload":"vKPTwnNHZWd8yQ==","pcpu":211,"pid_count":51580,"pmem":194,"preamble":85,"procs_starting":18291,"procs_stopping":26469,"sender":14420}})), "raw_json");
}
test_auto_check_sbp_linux_msg_linux_sys_state_dep_a_1();

done_testing();