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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessSocketQueues.yaml
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
sub test_auto_check_sbp_linux_msg_linux_process_socket_queues_1() {
    my $buf = decode_base64("VQR/u+h5tYdL+dMj/FBtD99hZGRyZXNzIG9mIGxhcmdlc3QAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNAL3");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf702, "crc");
    
    is($msg->{'length'}, 121, "length");
    
    is($msg->{'msg_type'}, 0x7f04, "msg_type");
    
    is($msg->{'payload'}, "tYdL+dMj/FBtD99hZGRyZXNzIG9mIGxhcmdlc3QAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xe8bb, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->address_of_largest(), "address of largest\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", "address_of_largest");
    
    is($msg->cmdline(), "/path/to/process-name arg0 arg1 arg2 arg3 arg4", "cmdline");
    
    is($msg->index(), 181, "index");
    
    is($msg->pid(), 19335, "pid");
    
    is($msg->recv_queued(), 54265, "recv_queued");
    
    is($msg->send_queued(), 64547, "send_queued");
    
    is($msg->socket_states(), 57103, "socket_states");
    
    is($msg->socket_types(), 27984, "socket_types");

    is($json->encode($msg), $json->encode($json->decode(q{{"address_of_largest":"address of largest\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","cmdline":"/path/to/process-name arg0 arg1 arg2 arg3 arg4","crc":63234,"index":181,"length":121,"msg_type":32516,"payload":"tYdL+dMj/FBtD99hZGRyZXNzIG9mIGxhcmdlc3QAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL3BhdGgvdG8vcHJvY2Vzcy1uYW1lIGFyZzAgYXJnMSBhcmcyIGFyZzMgYXJnNA==","pid":19335,"preamble":85,"recv_queued":54265,"send_queued":64547,"sender":59579,"socket_states":57103,"socket_types":27984}})), "raw_json");
}
test_auto_check_sbp_linux_msg_linux_process_socket_queues_1();

done_testing();