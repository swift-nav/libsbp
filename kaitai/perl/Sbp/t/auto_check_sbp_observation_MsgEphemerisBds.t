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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisBds.yaml
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
sub test_auto_check_sbp_observation_msg_ephemeris_bds_1() {
    my $buf = decode_base64("VYkAgPCTCAyuswYAaggAAABAMCoAAAEAfWM0Ms8ul7AAcGBDAKRqQwA8/zYA4C81AACPswDAvjSSZaLEbWgTPv1XVso+HPs/AAAAYJc8dT8AAICaf125QJfBQAAKpgTAoEuuYgjJI77NHQxHvZYFwLBI+b3BrPA/SPm8tKDLCT4AAAAAXDNNvwCArisAAFihrrMGAGoIBgUAnfk=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf99d, "crc");
    
    is($msg->{'length'}, 147, "length");
    
    is($msg->{'msg_type'}, 0x89, "msg_type");
    
    is($msg->{'payload'}, "CAyuswYAaggAAABAMCoAAAEAfWM0Ms8ul7AAcGBDAKRqQwA8/zYA4C81AACPswDAvjSSZaLEbWgTPv1XVso+HPs/AAAAYJc8dT8AAICaf125QJfBQAAKpgTAoEuuYgjJI77NHQxHvZYFwLBI+b3BrPA/SPm8tKDLCT4AAAAAXDNNvwCArisAAFihrrMGAGoIBgUA", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xf080, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->af0(), -0.0008911322802305222, "af0");
    
    is($msg->af1(), 1.2398970739013748e-12, "af1");
    
    is($msg->af2(), -7.318364664277155e-19, "af2");
    
    is($msg->c_ic(), -6.658956408500671e-08, "c_ic");
    
    is($msg->c_is(), 3.5529956221580505e-07, "c_is");
    
    is($msg->c_rc(), 234.640625, "c_rc");
    
    is($msg->c_rs(), 224.4375, "c_rs");
    
    is($msg->c_uc(), 7.606577128171921e-06, "c_uc");
    
    is($msg->c_us(), 6.551854312419891e-07, "c_us");
    
    is($json->encode($msg->common()), $json->encode($json->decode(q{{"fit_interval":10800,"health_bits":0,"sid":{"code":12,"sat":8},"toe":{"tow":439214,"wn":2154},"ura":2.0,"valid":1}})), "common");
    
    is($msg->dn(), 1.1296899132622133e-09, "dn");
    
    is($msg->ecc(), 0.005184737499803305, "ecc");
    
    is($msg->inc(), 1.0421769543504915, "inc");
    
    is($msg->inc_dot(), 7.507455572801683e-10, "inc_dot");
    
    is($msg->iodc(), 5, "iodc");
    
    is($msg->iode(), 6, "iode");
    
    is($msg->m0(), 1.6943958190727237, "m0");
    
    is($msg->omega0(), -2.581073762870982, "omega0");
    
    is($msg->omegadot(), -2.303310227830545e-09, "omegadot");
    
    is($msg->sqrta(), 6493.49845123291, "sqrta");
    
    is($msg->tgd1(), 1.0499999980595476e-08, "tgd1");
    
    is($msg->tgd2(), -1.0999999799921056e-09, "tgd2");
    
    is($json->encode($msg->toc()), $json->encode($json->decode(q{{"tow":439214,"wn":2154}})), "toc");
    
    is($msg->w(), -2.698603205735458, "w");

    is($json->encode($msg), $json->encode($json->decode(q{{"af0":-0.0008911322802305222,"af1":1.2398970739013748e-12,"af2":-7.318364664277155e-19,"c_ic":-6.658956408500671e-08,"c_is":3.5529956221580505e-07,"c_rc":234.640625,"c_rs":224.4375,"c_uc":7.606577128171921e-06,"c_us":6.551854312419891e-07,"common":{"fit_interval":10800,"health_bits":0,"sid":{"code":12,"sat":8},"toe":{"tow":439214,"wn":2154},"ura":2.0,"valid":1},"crc":63901,"dn":1.1296899132622133e-09,"ecc":0.005184737499803305,"inc":1.0421769543504915,"inc_dot":7.507455572801683e-10,"iodc":5,"iode":6,"length":147,"m0":1.6943958190727237,"msg_type":137,"omega0":-2.581073762870982,"omegadot":-2.303310227830545e-09,"payload":"CAyuswYAaggAAABAMCoAAAEAfWM0Ms8ul7AAcGBDAKRqQwA8/zYA4C81AACPswDAvjSSZaLEbWgTPv1XVso+HPs/AAAAYJc8dT8AAICaf125QJfBQAAKpgTAoEuuYgjJI77NHQxHvZYFwLBI+b3BrPA/SPm8tKDLCT4AAAAAXDNNvwCArisAAFihrrMGAGoIBgUA","preamble":85,"sender":61568,"sqrta":6493.49845123291,"tgd1":1.0499999980595476e-08,"tgd2":-1.0999999799921056e-09,"toc":{"tow":439214,"wn":2154},"w":-2.698603205735458}})), "raw_json");
}
test_auto_check_sbp_observation_msg_ephemeris_bds_1();

done_testing();