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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDepA.yaml
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
sub test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_a_1() {
    my $buf = decode_base64("VSEAm245Lh+0JtsAAACFZEdewAKgz9T/h4s+PrNT4/WGoMxOX/8mO6EP/1a9+B+/iMJ8Fw9b+XWOWttDGVM+emQ=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x647a, "crc");
    
    is($msg->{'length'}, 57, "length");
    
    is($msg->{'msg_type'}, 0x21, "msg_type");
    
    is($msg->{'payload'}, "Lh+0JtsAAACFZEdewAKgz9T/h4s+PrNT4/WGoMxOX/8mO6EP/1a9+B+/iMJ8Fw9b+XWOWttDGVM+", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x6e9b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->l()), $json->encode($json->decode(q{{"f":204,"i":-1601767965}})), "l");
    
    is($msg->p(), 1044286343, "p");
    
    is($msg->p_std(), 21427, "p_std");
    
    is($msg->acceleration(), -114, "acceleration");
    
    is($msg->clock_drift(), 23311, "clock_drift");
    
    is($msg->clock_offset(), 6012, "clock_offset");
    
    is($msg->cn0(), 78, "cn0");
    
    is($msg->corr_spacing(), 30201, "corr_spacing");
    
    is($msg->doppler(), 1459556257, "doppler");
    
    is($msg->doppler_std(), 63677, "doppler_std");
    
    is($msg->lock(), 65375, "lock");
    
    is($msg->misc_flags(), 62, "misc_flags");
    
    is($msg->nav_flags(), 25, "nav_flags");
    
    is($msg->pset_flags(), 83, "pset_flags");
    
    is($msg->recv_time(), 941247176494, "recv_time");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":59,"sat":38}})), "sid");
    
    is($msg->sync_flags(), 90, "sync_flags");
    
    is($json->encode($msg->tot()), $json->encode($json->decode(q{{"ns_residual":-811597120,"tow":1581737093,"wn":65492}})), "tot");
    
    is($msg->tow_flags(), 219, "tow_flags");
    
    is($msg->track_flags(), 67, "track_flags");
    
    is($msg->uptime(), 3263741727, "uptime");

    is($json->encode($msg), $json->encode($json->decode(q{{"acceleration":-114,"clock_drift":23311,"clock_offset":6012,"cn0":78,"corr_spacing":30201,"crc":25722,"doppler":1459556257,"doppler_std":63677,"l":{"f":204,"i":-1601767965},"length":57,"lock":65375,"misc_flags":62,"msg_type":33,"nav_flags":25,"p":1044286343,"p_std":21427,"payload":"Lh+0JtsAAACFZEdewAKgz9T/h4s+PrNT4/WGoMxOX/8mO6EP/1a9+B+/iMJ8Fw9b+XWOWttDGVM+","preamble":85,"pset_flags":83,"recv_time":941247176494,"sender":28315,"sid":{"code":59,"sat":38},"sync_flags":90,"tot":{"ns_residual":-811597120,"tow":1581737093,"wn":65492},"tow_flags":219,"track_flags":67,"uptime":3263741727}})), "raw_json");
}
test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_a_1();

done_testing();