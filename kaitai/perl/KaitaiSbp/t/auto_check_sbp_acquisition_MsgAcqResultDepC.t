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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepC.yaml
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
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_c_1() {
    my $buf = decode_base64("VR8AKAwQSAkiQpuY5EMcIt1ECgAAAAm9");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xbd09, "crc");
    
    is($msg->{'length'}, 16, "length");
    
    is($msg->{'msg_type'}, 0x1f, "msg_type");
    
    is($msg->{'payload'}, "SAkiQpuY5EMcIt1ECgAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xc28, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), 1769.06591796875, "cf");
    
    is($msg->cn0(), 40.509063720703125, "cn0");
    
    is($msg->cp(), 457.1922302246094, "cp");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":10}})), "sid");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":1769.06591796875,"cn0":40.509063720703125,"cp":457.1922302246094,"crc":48393,"length":16,"msg_type":31,"payload":"SAkiQpuY5EMcIt1ECgAAAA==","preamble":85,"sender":3112,"sid":{"code":0,"reserved":0,"sat":10}}})), "raw_json");
}
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_c_2() {
    my $buf = decode_base64("VR8AKAwQhPotQs9dWEREufzDBgAAAIi5");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb988, "crc");
    
    is($msg->{'length'}, 16, "length");
    
    is($msg->{'msg_type'}, 0x1f, "msg_type");
    
    is($msg->{'payload'}, "hPotQs9dWEREufzDBgAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xc28, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), -505.4473876953125, "cf");
    
    is($msg->cn0(), 43.49464416503906, "cn0");
    
    is($msg->cp(), 865.4657592773438, "cp");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":6}})), "sid");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":-505.4473876953125,"cn0":43.49464416503906,"cp":865.4657592773438,"crc":47496,"length":16,"msg_type":31,"payload":"hPotQs9dWEREufzDBgAAAA==","preamble":85,"sender":3112,"sid":{"code":0,"reserved":0,"sat":6}}})), "raw_json");
}
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_c_3() {
    my $buf = decode_base64("VR8AKAwQo98YQkBbZkPK853EDQAAAJah");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa196, "crc");
    
    is($msg->{'length'}, 16, "length");
    
    is($msg->{'msg_type'}, 0x1f, "msg_type");
    
    is($msg->{'payload'}, "o98YQkBbZkPK853EDQAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xc28, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), -1263.618408203125, "cf");
    
    is($msg->cn0(), 38.2183952331543, "cn0");
    
    is($msg->cp(), 230.3564453125, "cp");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":13}})), "sid");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":-1263.618408203125,"cn0":38.2183952331543,"cp":230.3564453125,"crc":41366,"length":16,"msg_type":31,"payload":"o98YQkBbZkPK853EDQAAAA==","preamble":85,"sender":3112,"sid":{"code":0,"reserved":0,"sat":13}}})), "raw_json");
}
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_c_4() {
    my $buf = decode_base64("VR8AKAwQgUEVQuDWfEPzij1FAQAAAG3R");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd16d, "crc");
    
    is($msg->{'length'}, 16, "length");
    
    is($msg->{'msg_type'}, 0x1f, "msg_type");
    
    is($msg->{'payload'}, "gUEVQuDWfEPzij1FAQAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xc28, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), 3032.684326171875, "cf");
    
    is($msg->cn0(), 37.313968658447266, "cn0");
    
    is($msg->cp(), 252.83935546875, "cp");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":1}})), "sid");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":3032.684326171875,"cn0":37.313968658447266,"cp":252.83935546875,"crc":53613,"length":16,"msg_type":31,"payload":"gUEVQuDWfEPzij1FAQAAAA==","preamble":85,"sender":3112,"sid":{"code":0,"reserved":0,"sat":1}}})), "raw_json");
}
sub test_auto_check_sbp_acquisition_msg_acq_result_dep_c_5() {
    my $buf = decode_base64("VR8AKAwQfiM+QuIlZkTK8x1FGwAAAFtD");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x435b, "crc");
    
    is($msg->{'length'}, 16, "length");
    
    is($msg->{'msg_type'}, 0x1f, "msg_type");
    
    is($msg->{'payload'}, "fiM+QuIlZkTK8x1FGwAAAA==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xc28, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->cf(), 2527.23681640625, "cf");
    
    is($msg->cn0(), 47.53466033935547, "cn0");
    
    is($msg->cp(), 920.5919189453125, "cp");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":27}})), "sid");

    is($json->encode($msg), $json->encode($json->decode(q{{"cf":2527.23681640625,"cn0":47.53466033935547,"cp":920.5919189453125,"crc":17243,"length":16,"msg_type":31,"payload":"fiM+QuIlZkTK8x1FGwAAAA==","preamble":85,"sender":3112,"sid":{"code":0,"reserved":0,"sat":27}}})), "raw_json");
}
test_auto_check_sbp_acquisition_msg_acq_result_dep_c_1();
test_auto_check_sbp_acquisition_msg_acq_result_dep_c_2();
test_auto_check_sbp_acquisition_msg_acq_result_dep_c_3();
test_auto_check_sbp_acquisition_msg_acq_result_dep_c_4();
test_auto_check_sbp_acquisition_msg_acq_result_dep_c_5();

done_testing();