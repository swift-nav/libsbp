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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCommandOutput.yaml
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
sub test_auto_check_sbp_piksi_msg_command_output_1() {
    my $buf = decode_base64("VbwAMlQUfqR0lVNvbWUgb3V0cHV0IHRleHQLbQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x6d0b, "crc");
    
    is($msg->{'length'}, 20, "length");
    
    is($msg->{'msg_type'}, 0xbc, "msg_type");
    
    is($msg->{'payload'}, "fqR0lVNvbWUgb3V0cHV0IHRleHQ=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x5432, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->line(), "Some output text", "line");
    
    is($msg->sequence(), 2507449470, "sequence");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":27915,"length":20,"line":"Some output text","msg_type":188,"payload":"fqR0lVNvbWUgb3V0cHV0IHRleHQ=","preamble":85,"sender":21554,"sequence":2507449470}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_command_output_1();

done_testing();
