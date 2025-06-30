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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResult.yaml
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
sub test_auto_check_sbp_acquisition_msg_acq_result_1() {
    my $buf = decode_base64("VS8AwwQOAABoQWZmkELNxABGCADPvQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xbdcf, "crc");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'msg_type'}, 0x2f, "msg_type");
    
    is($msg->{'payload'}, "AABoQWZmkELNxABGCAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), 8241.2001953125, "cf");
    
    is($msg->cn0(), 14.5, "cn0");
    
    is($msg->cp(), 72.19999694824219, "cp");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"sat":8}})), "sid");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":8241.2001953125,"cn0":14.5,"cp":72.19999694824219,"crc":48591,"length":14,"msg_type":47,"payload":"AABoQWZmkELNxABGCAA=","preamble":85,"sender":1219,"sid":{"code":0,"sat":8}}})), "raw_json");
}
test_auto_check_sbp_acquisition_msg_acq_result_1();

done_testing();
