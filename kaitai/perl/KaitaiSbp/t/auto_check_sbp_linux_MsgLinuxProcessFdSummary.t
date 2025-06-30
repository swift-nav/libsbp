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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessFdSummary.yaml
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
sub test_auto_check_sbp_linux_msg_linux_process_fd_summary_1() {
    my $buf = decode_base64("VQd/Z/gdE4PITWZkMQBmZDIAZmQzAGZkNABmZDUAZmQ2AACBUA==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5081, "crc");
    
    is($msg->{'length'}, 29, "length");
    
    is($msg->{'msg_type'}, 0x7f07, "msg_type");
    
    is($msg->{'payload'}, "E4PITWZkMQBmZDIAZmQzAGZkNABmZDUAZmQ2AAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xf867, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->most_opened(), "fd1\x00fd2\x00fd3\x00fd4\x00fd5\x00fd6\x00\x00", "most_opened");
    
    is($msg->sys_fd_count(), 1304986387, "sys_fd_count");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":20609,"length":29,"most_opened":"fd1\u0000fd2\u0000fd3\u0000fd4\u0000fd5\u0000fd6\u0000\u0000","msg_type":32519,"payload":"E4PITWZkMQBmZDIAZmQzAGZkNABmZDUAZmQ2AAA=","preamble":85,"sender":63591,"sys_fd_count":1304986387}})), "raw_json");
}
test_auto_check_sbp_linux_msg_linux_process_fd_summary_1();

done_testing();
