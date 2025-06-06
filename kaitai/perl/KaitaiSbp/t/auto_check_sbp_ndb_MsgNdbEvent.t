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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ndb/test_MsgNdbEvent.yaml
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
sub test_auto_check_sbp_ndb_msg_ndb_event_1() {
    my $buf = decode_base64("VQAEpK4S/rxGuUUAAAD5Sc1z7kpiQraUEKY=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa610, "crc");
    
    is($msg->{'length'}, 18, "length");
    
    is($msg->{'msg_type'}, 0x400, "msg_type");
    
    is($msg->{'payload'}, "/rxGuUUAAAD5Sc1z7kpiQraU", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xaea4, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->data_source(), 115, "data_source");
    
    is($msg->event(), 249, "event");
    
    is($json->encode($msg->object_sid()), $json->encode($json->decode(q{{"code":74,"sat":238}})), "object_sid");
    
    is($msg->object_type(), 73, "object_type");
    
    is($msg->original_sender(), 38070, "original_sender");
    
    is($msg->recv_time(), 299461164286, "recv_time");
    
    is($msg->result(), 205, "result");
    
    is($json->encode($msg->src_sid()), $json->encode($json->decode(q{{"code":66,"sat":98}})), "src_sid");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":42512,"data_source":115,"event":249,"length":18,"msg_type":1024,"object_sid":{"code":74,"sat":238},"object_type":73,"original_sender":38070,"payload":"/rxGuUUAAAD5Sc1z7kpiQraU","preamble":85,"recv_time":299461164286,"result":205,"sender":44708,"src_sid":{"code":66,"sat":98}}})), "raw_json");
}
test_auto_check_sbp_ndb_msg_ndb_event_1();

done_testing();
