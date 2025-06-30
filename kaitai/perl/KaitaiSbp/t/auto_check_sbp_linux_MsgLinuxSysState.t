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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSysState.yaml
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
sub test_auto_check_sbp_linux_msg_linux_sys_state_1() {
    my $buf = decode_base64("VQp/VacPFM9918RHoeX6umweagUJ5fI=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf2e5, "crc");
    
    is($msg->{'length'}, 15, "length");
    
    is($msg->{'msg_type'}, 0x7f0a, "msg_type");
    
    is($msg->{'payload'}, "FM9918RHoeX6umweagUJ", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xa755, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 9, "flags");
    
    is($msg->mem_total(), 53012, "mem_total");
    
    is($msg->pcpu(), 125, "pcpu");
    
    is($msg->pid_count(), 47866, "pid_count");
    
    is($msg->pmem(), 215, "pmem");
    
    is($msg->procs_starting(), 18372, "procs_starting");
    
    is($msg->procs_stopping(), 58785, "procs_stopping");
    
    is($msg->time(), 90840684, "time");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":62181,"flags":9,"length":15,"mem_total":53012,"msg_type":32522,"payload":"FM9918RHoeX6umweagUJ","pcpu":125,"pid_count":47866,"pmem":215,"preamble":85,"procs_starting":18372,"procs_stopping":58785,"sender":42837,"time":90840684}})), "raw_json");
}
test_auto_check_sbp_linux_msg_linux_sys_state_1();

done_testing();
