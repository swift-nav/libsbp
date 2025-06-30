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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadDirReq.yaml
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
sub test_auto_check_sbp_file_io_msg_fileio_read_dir_req_1() {
    my $buf = decode_base64("VakAwwQaguf/WsSGL4Yvc29tZS9yYW5kb20vcGF0aAAaug==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xba1a, "crc");
    
    is($msg->{'length'}, 26, "length");
    
    is($msg->{'msg_type'}, 0xa9, "msg_type");
    
    is($msg->{'payload'}, "guf/WsSGL4Yvc29tZS9yYW5kb20vcGF0aAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->dirname(), "/some/random/path\x00", "dirname");
    
    is($msg->offset(), 2251261636, "offset");
    
    is($msg->sequence(), 1526720386, "sequence");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":47642,"dirname":"/some/random/path\u0000","length":26,"msg_type":169,"offset":2251261636,"payload":"guf/WsSGL4Yvc29tZS9yYW5kb20vcGF0aAA=","preamble":85,"sender":1219,"sequence":1526720386}})), "raw_json");
}
test_auto_check_sbp_file_io_msg_fileio_read_dir_req_1();

done_testing();
