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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioRemove.yaml
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
sub test_auto_check_sbp_file_io_msg_fileio_remove_1() {
    my $buf = decode_base64("VawAwwQOL3BhdGgvdG8vZmlsZQAu8w==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf32e, "crc");
    
    is($msg->{'length'}, 14, "length");
    
    is($msg->{'msg_type'}, 0xac, "msg_type");
    
    is($msg->{'payload'}, "L3BhdGgvdG8vZmlsZQA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->filename(), "/path/to/file\x00", "filename");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":62254,"filename":"/path/to/file\u0000","length":14,"msg_type":172,"payload":"L3BhdGgvdG8vZmlsZQA=","preamble":85,"sender":1219}})), "raw_json");
}
test_auto_check_sbp_file_io_msg_fileio_remove_1();

done_testing();
