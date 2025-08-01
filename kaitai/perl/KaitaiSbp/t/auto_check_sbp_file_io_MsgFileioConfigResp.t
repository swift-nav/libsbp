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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioConfigResp.yaml
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
sub test_auto_check_sbp_file_io_msg_fileio_config_resp_1() {
    my $buf = decode_base64("VQIQwwQQqkw0W5W6LAPYl/89DGFCkO9z");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x73ef, "crc");
    
    is($msg->{'length'}, 16, "length");
    
    is($msg->{'msg_type'}, 0x1002, "msg_type");
    
    is($msg->{'payload'}, "qkw0W5W6LAPYl/89DGFCkA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->batch_size(), 1040160728, "batch_size");
    
    is($msg->fileio_version(), 2420269324, "fileio_version");
    
    is($msg->sequence(), 1530154154, "sequence");
    
    is($msg->window_size(), 53262997, "window_size");

    is($json->encode($msg), $json->encode($json->decode(q{{"batch_size":1040160728,"crc":29679,"fileio_version":2420269324,"length":16,"msg_type":4098,"payload":"qkw0W5W6LAPYl/89DGFCkA==","preamble":85,"sender":1219,"sequence":1530154154,"window_size":53262997}})), "raw_json");
}
test_auto_check_sbp_file_io_msg_fileio_config_resp_1();

done_testing();
