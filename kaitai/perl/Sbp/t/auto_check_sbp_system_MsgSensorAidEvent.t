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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgSensorAidEvent.yaml
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
sub test_auto_check_sbp_system_msg_sensor_aid_event_1() {
    my $buf = decode_base64("VQn/04gPMPZ6EwAAAAAAAAAAAAAAIew=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xEC21, "crc");
    
    is($msg->{'length'}, 15, "length");
    
    is($msg->{'msg_type'}, 0xFF09, "msg_type");
    
    is($msg->{'payload'}, "MPZ6EwAAAAAAAAAAAAAA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x88D3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->flags(), 0, "flags");
    
    is($msg->n_accepted_meas(), 0, "n_accepted_meas");
    
    is($msg->n_attempted_meas(), 0, "n_attempted_meas");
    
    is($msg->n_available_meas(), 0, "n_available_meas");
    
    is($msg->sensor_id(), 0, "sensor_id");
    
    is($msg->sensor_state(), 0, "sensor_state");
    
    is($msg->sensor_type(), 0, "sensor_type");
    
    is($msg->time(), 326825520, "time");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":60449,"flags":0,"length":15,"msg_type":65289,"n_accepted_meas":0,"n_attempted_meas":0,"n_available_meas":0,"payload":"MPZ6EwAAAAAAAAAAAAAA","preamble":85,"sender":35027,"sensor_id":0,"sensor_state":0,"sensor_type":0,"time":326825520}})), "raw_json");
}
test_auto_check_sbp_system_msg_sensor_aid_event_1();

done_testing();