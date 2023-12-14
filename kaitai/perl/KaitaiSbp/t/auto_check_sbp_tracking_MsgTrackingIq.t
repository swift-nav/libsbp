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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIq.yaml
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
sub test_auto_check_sbp_tracking_msg_tracking_iq_1() {
    my $buf = decode_base64("VS0AAlAPkXnLL9nvNy0mvVifE9AMYac=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xa761, "crc");
    
    is($msg->{'length'}, 15, "length");
    
    is($msg->{'msg_type'}, 0x2d, "msg_type");
    
    is($msg->{'payload'}, "kXnLL9nvNy0mvVifE9AM", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x5002, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->channel(), 145, "channel");
    
    is($json->encode($msg->corrs()), $json->encode($json->decode(q{[{"i":-9937,"q":14319},{"i":9773,"q":22717},{"i":5023,"q":3280}]})), "corrs");
    
    is($json->encode($msg->sid()), $json->encode($json->decode(q{{"code":203,"sat":121}})), "sid");

    is($json->encode($msg), $json->encode($json->decode(q{{"channel":145,"corrs":[{"i":-9937,"q":14319},{"i":9773,"q":22717},{"i":5023,"q":3280}],"crc":42849,"length":15,"msg_type":45,"payload":"kXnLL9nvNy0mvVifE9AM","preamble":85,"sender":20482,"sid":{"code":203,"sat":121}}})), "raw_json");
}
test_auto_check_sbp_tracking_msg_tracking_iq_1();

done_testing();