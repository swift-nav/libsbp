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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgFwd.yaml
# with generate.py.  Do not modify by hand!

use strict;

BEGIN {
    # add grandparent directory to include path
    use Cwd qw(realpath);
    use File::Basename;
    unshift @INC, realpath(dirname($0))."/../../";
}

use Sbp::Sbp;
use Sbp::ParseUtils;
use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_logging_msg_fwd_1() {
    my $buf = decode_base64("VQIEQgASAABWUUQvUWdBRUFBQUFBRWFnfV8=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5f7d, "crc");
    
    is($msg->{'length'}, 18, "length");
    
    is($msg->{'msg_type'}, 0x402, "msg_type");
    
    is($msg->{'payload'}, "AABWUUQvUWdBRUFBQUFBRWFn", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x42, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->fwd_payload()), $json->encode($json->decode(q{[86,81,68,47,81,103,65,69,65,65,65,65,65,69,97,103]})), "fwd_payload");
    
    is($msg->protocol(), 0, "protocol");
    
    is($msg->source(), 0, "source");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":24445,"fwd_payload":[86,81,68,47,81,103,65,69,65,65,65,65,65,69,97,103],"length":18,"msg_type":1026,"payload":"AABWUUQvUWdBRUFBQUFBRWFn","preamble":85,"protocol":0,"sender":66,"source":0}})), "raw_json");
}
test_auto_check_sbp_logging_msg_fwd_1();

done_testing();