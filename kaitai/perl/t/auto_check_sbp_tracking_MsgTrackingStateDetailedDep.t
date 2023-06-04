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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDep.yaml
# with generate.py.  Do not modify by hand!

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";

BEGIN {
    # add SBP_PATH to include path and load all modules
    unshift @INC, &SBP_PATH;
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
use t::Utils;
sub test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_1() {
    my $buf = decode_base64("VREAO2c3o5dw1wEAAAAAAAAAAAAAAAAAAAAnBQAAqbHQNg8AAABVPQAAJwABAAAAAAAAACgAbAEACwAACabW");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xd6a6, "crc");
    
    is($msg->{'length'}, 55, "length");
    
    is($msg->{'msg_type'}, 0x11, "msg_type");
    
    is($msg->{'payload'}, "o5dw1wEAAAAAAAAAAAAAAAAAAAAnBQAAqbHQNg8AAABVPQAAJwABAAAAAAAAACgAbAEACwAACQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x673b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->l()), $json->encode($json->decode(q{{"f":169,"i":1319}})), "l");
    
    is($msg->p(), 0, "p");
    
    is($msg->p_std(), 0, "p_std");
    
    is($msg->acceleration(), 108, "acceleration");
    
    is($msg->clock_drift(), 0, "clock_drift");
    
    is($msg->clock_offset(), 0, "clock_offset");
    
    is($msg->cn0(), 177, "cn0");
    
    is($msg->corr_spacing(), 40, "corr_spacing");
    
    is($msg->doppler(), 15701, "doppler");
    
    is($msg->doppler_std(), 39, "doppler_std");
    
    is($msg->lock(), 14032, "lock");
    
    is($msg->misc_flags(), 9, "misc_flags");
    
    is($msg->nav_flags(), 0, "nav_flags");
    
    is($msg->pset_flags(), 0, "pset_flags");
    
    is($msg->recv_time(), 7909447587, "recv_time");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":15}})), "sid");
    
    is($msg->sync_flags(), 1, "sync_flags");
    
    is($json->encode($msg->tot()), $json->encode($json->decode(q{{"tow":0,"wn":0}})), "tot");
    
    is($msg->tow_flags(), 0, "tow_flags");
    
    is($msg->track_flags(), 11, "track_flags");
    
    is($msg->uptime(), 1, "uptime");

    is($json->encode($msg), $json->encode($json->decode(q{{"acceleration":108,"clock_drift":0,"clock_offset":0,"cn0":177,"corr_spacing":40,"crc":54950,"doppler":15701,"doppler_std":39,"l":{"f":169,"i":1319},"length":55,"lock":14032,"misc_flags":9,"msg_type":17,"nav_flags":0,"p":0,"p_std":0,"payload":"o5dw1wEAAAAAAAAAAAAAAAAAAAAnBQAAqbHQNg8AAABVPQAAJwABAAAAAAAAACgAbAEACwAACQ==","preamble":85,"pset_flags":0,"recv_time":7909447587,"sender":26427,"sid":{"code":0,"reserved":0,"sat":15},"sync_flags":1,"tot":{"tow":0,"wn":0},"tow_flags":0,"track_flags":11,"uptime":1}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_2() {
    my $buf = decode_base64("VREAO2c3Yfs99QEAAAAAAAAAAAAAAAAAAAASBwAADq/QNg8AAAAzPQAAHgABAAAAAAAAACgA4AEACwAACYiz");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xb388, "crc");
    
    is($msg->{'length'}, 55, "length");
    
    is($msg->{'msg_type'}, 0x11, "msg_type");
    
    is($msg->{'payload'}, "Yfs99QEAAAAAAAAAAAAAAAAAAAASBwAADq/QNg8AAAAzPQAAHgABAAAAAAAAACgA4AEACwAACQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x673b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->l()), $json->encode($json->decode(q{{"f":14,"i":1810}})), "l");
    
    is($msg->p(), 0, "p");
    
    is($msg->p_std(), 0, "p_std");
    
    is($msg->acceleration(), -32, "acceleration");
    
    is($msg->clock_drift(), 0, "clock_drift");
    
    is($msg->clock_offset(), 0, "clock_offset");
    
    is($msg->cn0(), 175, "cn0");
    
    is($msg->corr_spacing(), 40, "corr_spacing");
    
    is($msg->doppler(), 15667, "doppler");
    
    is($msg->doppler_std(), 30, "doppler_std");
    
    is($msg->lock(), 14032, "lock");
    
    is($msg->misc_flags(), 9, "misc_flags");
    
    is($msg->nav_flags(), 0, "nav_flags");
    
    is($msg->pset_flags(), 0, "pset_flags");
    
    is($msg->recv_time(), 8409447265, "recv_time");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":15}})), "sid");
    
    is($msg->sync_flags(), 1, "sync_flags");
    
    is($json->encode($msg->tot()), $json->encode($json->decode(q{{"tow":0,"wn":0}})), "tot");
    
    is($msg->tow_flags(), 0, "tow_flags");
    
    is($msg->track_flags(), 11, "track_flags");
    
    is($msg->uptime(), 1, "uptime");

    is($json->encode($msg), $json->encode($json->decode(q{{"acceleration":-32,"clock_drift":0,"clock_offset":0,"cn0":175,"corr_spacing":40,"crc":45960,"doppler":15667,"doppler_std":30,"l":{"f":14,"i":1810},"length":55,"lock":14032,"misc_flags":9,"msg_type":17,"nav_flags":0,"p":0,"p_std":0,"payload":"Yfs99QEAAAAAAAAAAAAAAAAAAAASBwAADq/QNg8AAAAzPQAAHgABAAAAAAAAACgA4AEACwAACQ==","preamble":85,"pset_flags":0,"recv_time":8409447265,"sender":26427,"sid":{"code":0,"reserved":0,"sat":15},"sync_flags":1,"tot":{"tow":0,"wn":0},"tow_flags":0,"track_flags":11,"uptime":1}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_3() {
    my $buf = decode_base64("VREAO2c3i9rsEgIAAAAAAAAAAAAAAAAAAAD6CAAACLPQNg8AAABDPQAAFgACAAAAAAAAACgAGwEACwACCdmf");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x9fd9, "crc");
    
    is($msg->{'length'}, 55, "length");
    
    is($msg->{'msg_type'}, 0x11, "msg_type");
    
    is($msg->{'payload'}, "i9rsEgIAAAAAAAAAAAAAAAAAAAD6CAAACLPQNg8AAABDPQAAFgACAAAAAAAAACgAGwEACwACCQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x673b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->l()), $json->encode($json->decode(q{{"f":8,"i":2298}})), "l");
    
    is($msg->p(), 0, "p");
    
    is($msg->p_std(), 0, "p_std");
    
    is($msg->acceleration(), 27, "acceleration");
    
    is($msg->clock_drift(), 0, "clock_drift");
    
    is($msg->clock_offset(), 0, "clock_offset");
    
    is($msg->cn0(), 179, "cn0");
    
    is($msg->corr_spacing(), 40, "corr_spacing");
    
    is($msg->doppler(), 15683, "doppler");
    
    is($msg->doppler_std(), 22, "doppler_std");
    
    is($msg->lock(), 14032, "lock");
    
    is($msg->misc_flags(), 9, "misc_flags");
    
    is($msg->nav_flags(), 0, "nav_flags");
    
    is($msg->pset_flags(), 2, "pset_flags");
    
    is($msg->recv_time(), 8907446923, "recv_time");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":15}})), "sid");
    
    is($msg->sync_flags(), 1, "sync_flags");
    
    is($json->encode($msg->tot()), $json->encode($json->decode(q{{"tow":0,"wn":0}})), "tot");
    
    is($msg->tow_flags(), 0, "tow_flags");
    
    is($msg->track_flags(), 11, "track_flags");
    
    is($msg->uptime(), 2, "uptime");

    is($json->encode($msg), $json->encode($json->decode(q{{"acceleration":27,"clock_drift":0,"clock_offset":0,"cn0":179,"corr_spacing":40,"crc":40921,"doppler":15683,"doppler_std":22,"l":{"f":8,"i":2298},"length":55,"lock":14032,"misc_flags":9,"msg_type":17,"nav_flags":0,"p":0,"p_std":0,"payload":"i9rsEgIAAAAAAAAAAAAAAAAAAAD6CAAACLPQNg8AAABDPQAAFgACAAAAAAAAACgAGwEACwACCQ==","preamble":85,"pset_flags":2,"recv_time":8907446923,"sender":26427,"sid":{"code":0,"reserved":0,"sat":15},"sync_flags":1,"tot":{"tow":0,"wn":0},"tow_flags":0,"track_flags":11,"uptime":2}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_4() {
    my $buf = decode_base64("VREAO2c3//uqMAIAAAAAAAAAAAAAAAAAAADiCgAAfbXQNg8AAAAdPQAACgACAAAAAAAAACgA3AEACwADCUJf");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x5f42, "crc");
    
    is($msg->{'length'}, 55, "length");
    
    is($msg->{'msg_type'}, 0x11, "msg_type");
    
    is($msg->{'payload'}, "//uqMAIAAAAAAAAAAAAAAAAAAADiCgAAfbXQNg8AAAAdPQAACgACAAAAAAAAACgA3AEACwADCQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x673b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->l()), $json->encode($json->decode(q{{"f":125,"i":2786}})), "l");
    
    is($msg->p(), 0, "p");
    
    is($msg->p_std(), 0, "p_std");
    
    is($msg->acceleration(), -36, "acceleration");
    
    is($msg->clock_drift(), 0, "clock_drift");
    
    is($msg->clock_offset(), 0, "clock_offset");
    
    is($msg->cn0(), 181, "cn0");
    
    is($msg->corr_spacing(), 40, "corr_spacing");
    
    is($msg->doppler(), 15645, "doppler");
    
    is($msg->doppler_std(), 10, "doppler_std");
    
    is($msg->lock(), 14032, "lock");
    
    is($msg->misc_flags(), 9, "misc_flags");
    
    is($msg->nav_flags(), 0, "nav_flags");
    
    is($msg->pset_flags(), 3, "pset_flags");
    
    is($msg->recv_time(), 9406446591, "recv_time");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":15}})), "sid");
    
    is($msg->sync_flags(), 1, "sync_flags");
    
    is($json->encode($msg->tot()), $json->encode($json->decode(q{{"tow":0,"wn":0}})), "tot");
    
    is($msg->tow_flags(), 0, "tow_flags");
    
    is($msg->track_flags(), 11, "track_flags");
    
    is($msg->uptime(), 2, "uptime");

    is($json->encode($msg), $json->encode($json->decode(q{{"acceleration":-36,"clock_drift":0,"clock_offset":0,"cn0":181,"corr_spacing":40,"crc":24386,"doppler":15645,"doppler_std":10,"l":{"f":125,"i":2786},"length":55,"lock":14032,"misc_flags":9,"msg_type":17,"nav_flags":0,"p":0,"p_std":0,"payload":"//uqMAIAAAAAAAAAAAAAAAAAAADiCgAAfbXQNg8AAAAdPQAACgACAAAAAAAAACgA3AEACwADCQ==","preamble":85,"pset_flags":3,"recv_time":9406446591,"sender":26427,"sid":{"code":0,"reserved":0,"sat":15},"sync_flags":1,"tot":{"tow":0,"wn":0},"tow_flags":0,"track_flags":11,"uptime":2}})), "raw_json");
}
sub test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_5() {
    my $buf = decode_base64("VREAO2c3vV94TgIAAAAAAAAAAAAAAAAAAADLDAAAQLjQNg8AAAAYPQAABAADAAAAAAAAACgAAgEACwADCcLO");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xcec2, "crc");
    
    is($msg->{'length'}, 55, "length");
    
    is($msg->{'msg_type'}, 0x11, "msg_type");
    
    is($msg->{'payload'}, "vV94TgIAAAAAAAAAAAAAAAAAAADLDAAAQLjQNg8AAAAYPQAABAADAAAAAAAAACgAAgEACwADCQ==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x673b, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->l()), $json->encode($json->decode(q{{"f":64,"i":3275}})), "l");
    
    is($msg->p(), 0, "p");
    
    is($msg->p_std(), 0, "p_std");
    
    is($msg->acceleration(), 2, "acceleration");
    
    is($msg->clock_drift(), 0, "clock_drift");
    
    is($msg->clock_offset(), 0, "clock_offset");
    
    is($msg->cn0(), 184, "cn0");
    
    is($msg->corr_spacing(), 40, "corr_spacing");
    
    is($msg->doppler(), 15640, "doppler");
    
    is($msg->doppler_std(), 4, "doppler_std");
    
    is($msg->lock(), 14032, "lock");
    
    is($msg->misc_flags(), 9, "misc_flags");
    
    is($msg->nav_flags(), 0, "nav_flags");
    
    is($msg->pset_flags(), 3, "pset_flags");
    
    is($msg->recv_time(), 9906446269, "recv_time");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":0,"reserved":0,"sat":15}})), "sid");
    
    is($msg->sync_flags(), 1, "sync_flags");
    
    is($json->encode($msg->tot()), $json->encode($json->decode(q{{"tow":0,"wn":0}})), "tot");
    
    is($msg->tow_flags(), 0, "tow_flags");
    
    is($msg->track_flags(), 11, "track_flags");
    
    is($msg->uptime(), 3, "uptime");

    is($json->encode($msg), $json->encode($json->decode(q{{"acceleration":2,"clock_drift":0,"clock_offset":0,"cn0":184,"corr_spacing":40,"crc":52930,"doppler":15640,"doppler_std":4,"l":{"f":64,"i":3275},"length":55,"lock":14032,"misc_flags":9,"msg_type":17,"nav_flags":0,"p":0,"p_std":0,"payload":"vV94TgIAAAAAAAAAAAAAAAAAAADLDAAAQLjQNg8AAAAYPQAABAADAAAAAAAAACgAAgEACwADCQ==","preamble":85,"pset_flags":3,"recv_time":9906446269,"sender":26427,"sid":{"code":0,"reserved":0,"sat":15},"sync_flags":1,"tot":{"tow":0,"wn":0},"tow_flags":0,"track_flags":11,"uptime":3}})), "raw_json");
}
test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_1();
test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_2();
test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_3();
test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_4();
test_auto_check_sbp_tracking_msg_tracking_state_detailed_dep_5();

done_testing();