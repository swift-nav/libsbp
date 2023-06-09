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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgInsUpdates.yaml
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
sub test_auto_check_sbp_system_msg_ins_updates_1() {
    my $buf = decode_base64("VQb/FQMKVOURHgAAAAAAAFE/");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x3f51, "crc");
    
    is($msg->{'length'}, 10, "length");
    
    is($msg->{'payload'}, "VOURHgAAAAAAAA==", "payload");
    
    is($msg->{'msg_type'}, 0xff06, "msg_type");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x315, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->gnsspos(), 0, "gnsspos");
    
    is($msg->gnssvel(), 0, "gnssvel");
    
    is($msg->nhc(), 0, "nhc");
    
    is($msg->speed(), 0, "speed");
    
    is($msg->tow(), 504489300, "tow");
    
    is($msg->wheelticks(), 0, "wheelticks");
    
    is($msg->zerovel(), 0, "zerovel");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":16209,"gnsspos":0,"gnssvel":0,"length":10,"msg_type":65286,"nhc":0,"payload":"VOURHgAAAAAAAA==","preamble":85,"sender":789,"speed":0,"tow":504489300,"wheelticks":0,"zerovel":0}})), "raw_json");
}
test_auto_check_sbp_system_msg_ins_updates_1();

done_testing();