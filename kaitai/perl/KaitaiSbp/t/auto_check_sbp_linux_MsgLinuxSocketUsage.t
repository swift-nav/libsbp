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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSocketUsage.yaml
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
sub test_auto_check_sbp_linux_msg_linux_socket_usage_1() {
    my $buf = decode_base64("VQV/copIDcRFrUPeurX2mvsR4LMaqbFaldXWBn5AeLlUg8hvII3Z0TQOvpOf9o161HeDHngvGW2aQYSkJx4erwgsHG/s8LBKn4GamaLlgpo=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9a82, "crc");
    
    is($msg->{'length'}, 72, "length");
    
    is($msg->{'msg_type'}, 0x7f05, "msg_type");
    
    is($msg->{'payload'}, "DcRFrUPeurX2mvsR4LMaqbFaldXWBn5AeLlUg8hvII3Z0TQOvpOf9o161HeDHngvGW2aQYSkJx4erwgsHG/s8LBKn4GamaLl", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x8a72, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->avg_queue_depth(), 2907030541, "avg_queue_depth");
    
    is($msg->max_queue_depth(), 3048922691, "max_queue_depth");
    
    is($json->encode($msg->socket_state_counts()), $json->encode($json->decode(q{[39670,4603,46048,43290,23217,54677,1750,16510,47480,33620,28616,36128,53721,3636,37822,63135]})), "socket_state_counts");
    
    is($json->encode($msg->socket_type_counts()), $json->encode($json->decode(q{[31373,30676,7811,12152,27929,16794,42116,7719,44830,11272,28444,61676,19120,33183,39322,58786]})), "socket_type_counts");

    is($json->encode($msg), $json->encode($json->decode(q{{"avg_queue_depth":2907030541,"crc":39554,"length":72,"max_queue_depth":3048922691,"msg_type":32517,"payload":"DcRFrUPeurX2mvsR4LMaqbFaldXWBn5AeLlUg8hvII3Z0TQOvpOf9o161HeDHngvGW2aQYSkJx4erwgsHG/s8LBKn4GamaLl","preamble":85,"sender":35442,"socket_state_counts":[39670,4603,46048,43290,23217,54677,1750,16510,47480,33620,28616,36128,53721,3636,37822,63135],"socket_type_counts":[31373,30676,7811,12152,27929,16794,42116,7719,44830,11272,28444,61676,19120,33183,39322,58786]}})), "raw_json");
}
test_auto_check_sbp_linux_msg_linux_socket_usage_1();

done_testing();