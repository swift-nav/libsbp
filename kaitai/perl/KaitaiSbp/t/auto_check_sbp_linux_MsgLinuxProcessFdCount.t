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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessFdCount.yaml
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
sub test_auto_check_sbp_linux_msg_linux_process_fd_count_1() {
    my $buf = decode_base64("VQZ/HsMzpL2lBYsvcGF0aC90by9wcm9jZXNzLW5hbWUgYXJnMCBhcmcxIGFyZzIgYXJnMyBhcmc0Al4=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5e02, "crc");
    
    is($msg->{'length'}, 51, "length");
    
    is($msg->{'msg_type'}, 0x7f06, "msg_type");
    
    is($msg->{'payload'}, "pL2lBYsvcGF0aC90by9wcm9jZXNzLW5hbWUgYXJnMCBhcmcxIGFyZzIgYXJnMyBhcmc0", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xc31e, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cmdline(), "/path/to/process-name arg0 arg1 arg2 arg3 arg4", "cmdline");
    
    is($msg->fd_count(), 35589, "fd_count");
    
    is($msg->index(), 164, "index");
    
    is($msg->pid(), 42429, "pid");

    is($json->encode($msg), $json->encode($json->decode(q{{"cmdline":"/path/to/process-name arg0 arg1 arg2 arg3 arg4","crc":24066,"fd_count":35589,"index":164,"length":51,"msg_type":32518,"payload":"pL2lBYsvcGF0aC90by9wcm9jZXNzLW5hbWUgYXJnMCBhcmcxIGFyZzIgYXJnMyBhcmc0","pid":42429,"preamble":85,"sender":49950}})), "raw_json");
}
test_auto_check_sbp_linux_msg_linux_process_fd_count_1();

done_testing();
