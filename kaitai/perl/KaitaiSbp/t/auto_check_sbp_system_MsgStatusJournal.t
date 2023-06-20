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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusJournal.yaml
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
sub test_auto_check_sbp_system_msg_status_journal_1() {
    my $buf = decode_base64("Vf3/04ghAQABBGQAAAAQkhAAAAYAAQ26EwAABgABDrgiAAAGAAEPcXc=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x7771, "crc");
    
    is($msg->{'length'}, 33, "length");
    
    is($msg->{'msg_type'}, 0xFFFD, "msg_type");
    
    is($msg->{'payload'}, "AQABBGQAAAAQkhAAAAYAAQ26EwAABgABDrgiAAAGAAEP", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88D3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->journal()), $json->encode($json->decode(q{[{"report":{"component":6,"generic":1,"specific":13},"uptime":4242},{"report":{"component":6,"generic":1,"specific":14},"uptime":5050},{"report":{"component":6,"generic":1,"specific":15},"uptime":8888}]})), "journal");
    
    is($msg->reporting_system(), 1, "reporting_system");
    
    is($msg->sbp_version(), 1025, "sbp_version");
    
    is($msg->sequence_descriptor(), 16, "sequence_descriptor");
    
    is($msg->total_status_reports(), 100, "total_status_reports");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":30577,"journal":[{"report":{"component":6,"generic":1,"specific":13},"uptime":4242},{"report":{"component":6,"generic":1,"specific":14},"uptime":5050},{"report":{"component":6,"generic":1,"specific":15},"uptime":8888}],"length":33,"msg_type":65533,"payload":"AQABBGQAAAAQkhAAAAYAAQ26EwAABgABDrgiAAAGAAEP","preamble":85,"reporting_system":1,"sbp_version":1025,"sender":35027,"sequence_descriptor":16,"total_status_reports":100}})), "raw_json");
}
sub test_auto_check_sbp_system_msg_status_journal_2() {
    my $buf = decode_base64("Vf3/04gRAQABBGQAAAAQkhAAAAYAAQ2QeQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x7990, "crc");
    
    is($msg->{'length'}, 17, "length");
    
    is($msg->{'msg_type'}, 0xFFFD, "msg_type");
    
    is($msg->{'payload'}, "AQABBGQAAAAQkhAAAAYAAQ0=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88D3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->journal()), $json->encode($json->decode(q{[{"report":{"component":6,"generic":1,"specific":13},"uptime":4242}]})), "journal");
    
    is($msg->reporting_system(), 1, "reporting_system");
    
    is($msg->sbp_version(), 1025, "sbp_version");
    
    is($msg->sequence_descriptor(), 16, "sequence_descriptor");
    
    is($msg->total_status_reports(), 100, "total_status_reports");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":31120,"journal":[{"report":{"component":6,"generic":1,"specific":13},"uptime":4242}],"length":17,"msg_type":65533,"payload":"AQABBGQAAAAQkhAAAAYAAQ0=","preamble":85,"reporting_system":1,"sbp_version":1025,"sender":35027,"sequence_descriptor":16,"total_status_reports":100}})), "raw_json");
}
test_auto_check_sbp_system_msg_status_journal_1();
test_auto_check_sbp_system_msg_status_journal_2();

done_testing();