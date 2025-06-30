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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgAlmanacGPSDep.yaml
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
sub test_auto_check_sbp_observation_msg_almanac_gps_dep_1() {
    my $buf = decode_base64("VXAAwwRgFgAAALDPBgBqCJqZmZmZmQFAQDgAAAEAjikF61+Hlr8AAAAgv/d8PwAAwM6MIbRAKYOzho34/b/jhVE2zB5Dvtg7xydgqO+/RwvZk5Hk7T8AAAAAbLFEvwAAAAAAwKM9kOg=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe890, "crc");
    
    is($msg->{'length'}, 96, "length");
    
    is($msg->{'msg_type'}, 0x70, "msg_type");
    
    is($msg->{'payload'}, "FgAAALDPBgBqCJqZmZmZmQFAQDgAAAEAjikF61+Hlr8AAAAgv/d8PwAAwM6MIbRAKYOzho34/b/jhVE2zB5Dvtg7xydgqO+/RwvZk5Hk7T8AAAAAbLFEvwAAAAAAwKM9", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->af0(), -0.0006315018981695175, "af0");
    
    is($msg->af1(), 8.981260180007666e-12, "af1");
    
    is($json->encode($msg->common()), $json->encode($json->decode(q{{"fit_interval":14400,"health_bits":0,"sid":{"code":0,"reserved":0,"sat":22},"toa":{"tow":446384,"wn":2154},"ura":2.2,"valid":1}})), "common");
    
    is($msg->ecc(), 0.007072207052260637, "ecc");
    
    is($msg->inc(), 0.9341514480259797, "inc");
    
    is($msg->m0(), -0.02200078842114688, "m0");
    
    is($msg->omega0(), -1.8731818448797617, "omega0");
    
    is($msg->omegadot(), -8.903585155774196e-09, "omegadot");
    
    is($msg->sqrta(), 5153.550029754639, "sqrta");
    
    is($msg->w(), -0.9893036629599647, "w");

    is($json->encode($msg), $json->encode($json->decode(q{{"af0":-0.0006315018981695175,"af1":8.981260180007666e-12,"common":{"fit_interval":14400,"health_bits":0,"sid":{"code":0,"reserved":0,"sat":22},"toa":{"tow":446384,"wn":2154},"ura":2.2,"valid":1},"crc":59536,"ecc":0.007072207052260637,"inc":0.9341514480259797,"length":96,"m0":-0.02200078842114688,"msg_type":112,"omega0":-1.8731818448797617,"omegadot":-8.903585155774196e-09,"payload":"FgAAALDPBgBqCJqZmZmZmQFAQDgAAAEAjikF61+Hlr8AAAAgv/d8PwAAwM6MIbRAKYOzho34/b/jhVE2zB5Dvtg7xydgqO+/RwvZk5Hk7T8AAAAAbLFEvwAAAAAAwKM9","preamble":85,"sender":1219,"sqrta":5153.550029754639,"w":-0.9893036629599647}})), "raw_json");
}
test_auto_check_sbp_observation_msg_almanac_gps_dep_1();

done_testing();
