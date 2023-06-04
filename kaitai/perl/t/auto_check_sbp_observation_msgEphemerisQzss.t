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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_msgEphemerisQzss.yaml
# with generate.py.  Do not modify by hand!

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";

BEGIN {
    # load all modules from SBP_PATH
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use IO::KaitaiStruct;
use Test::More;
use JSON::PP;
use MIME::Base64;
sub test_auto_check_sbp_observation_msg_ephemeris_qzss_1() {
    my $buf = decode_base64("VY4AgPCLwR/Q3QYAaggAAABAQDgAAAAAAADAsQDo5MMAoBPCAOCHtwBgCjcAwJ21AAAuNKdIa2mzASc+D+Ce0/Gk0z8AAAAY+1OzPwAAACIsXblAjz7O6MG18r/P2EVqYv8nvkGEXxYwD/m/+VJDXh5k5z91p7vpu/21PaCBwbkAAKisAAAAANDdBgBqCDExA34X");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x177e, "crc");
    
    is($msg->{'length'}, 139, "length");
    
    is($msg->{'msg_type'}, 0x8e, "msg_type");
    
    is($msg->{'payload'}, "wR/Q3QYAaggAAABAQDgAAAAAAADAsQDo5MMAoBPCAOCHtwBgCjcAwJ21AAAuNKdIa2mzASc+D+Ce0/Gk0z8AAAAY+1OzPwAAACIsXblAjz7O6MG18r/P2EVqYv8nvkGEXxYwD/m/+VJDXh5k5z91p7vpu/21PaCBwbkAAKisAAAAANDdBgBqCDExAw==", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xf080, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->af0(), -0.00036908406764268875, "af0");
    
    is($msg->af1(), -4.774847184307873e-12, "af1");
    
    is($msg->af2(), 0.0, "af2");
    
    is($msg->c_ic(), -1.1753290891647339e-06, "c_ic");
    
    is($msg->c_is(), 1.6205012798309326e-07, "c_is");
    
    is($msg->c_rc(), -36.90625, "c_rc");
    
    is($msg->c_rs(), -457.8125, "c_rs");
    
    is($msg->c_uc(), -1.6197562217712402e-05, "c_uc");
    
    is($msg->c_us(), 8.247792720794678e-06, "c_us");
    
    is($json->encode($msg->common()), $json->encode($json->decode(q{{"fit_interval":14400,"health_bits":0,"sid":{"code":31,"sat":193},"toe":{"tow":450000,"wn":2154},"ura":2.0,"valid":0}})), "common");
    
    is($msg->dn(), 2.678325848736433e-09, "dn");
    
    is($msg->ecc(), 0.07550019584596157, "ecc");
    
    is($msg->inc(), 0.7309715119432375, "inc");
    
    is($msg->inc_dot(), 2.0000833114980698e-11, "inc_dot");
    
    is($msg->iodc(), 817, "iodc");
    
    is($msg->iode(), 49, "iode");
    
    is($msg->m0(), 0.30694242158961144, "m0");
    
    is($msg->omega0(), -1.1693743795366662, "omega0");
    
    is($msg->omegadot(), -2.7936877968817684e-09, "omegadot");
    
    is($msg->sqrta(), 6493.172393798828, "sqrta");
    
    is($msg->tgd(), -5.587935447692871e-09, "tgd");
    
    is($json->encode($msg->toc()), $json->encode($json->decode(q{{"tow":450000,"wn":2154}})), "toc");
    
    is($msg->w(), -1.5662079690885238, "w");

    is($json->encode($msg), $json->encode($json->decode(q{{"af0":-0.00036908406764268875,"af1":-4.774847184307873e-12,"af2":0.0,"c_ic":-1.1753290891647339e-06,"c_is":1.6205012798309326e-07,"c_rc":-36.90625,"c_rs":-457.8125,"c_uc":-1.6197562217712402e-05,"c_us":8.247792720794678e-06,"common":{"fit_interval":14400,"health_bits":0,"sid":{"code":31,"sat":193},"toe":{"tow":450000,"wn":2154},"ura":2.0,"valid":0},"crc":6014,"dn":2.678325848736433e-09,"ecc":0.07550019584596157,"inc":0.7309715119432375,"inc_dot":2.0000833114980698e-11,"iodc":817,"iode":49,"length":139,"m0":0.30694242158961144,"msg_type":142,"omega0":-1.1693743795366662,"omegadot":-2.7936877968817684e-09,"payload":"wR/Q3QYAaggAAABAQDgAAAAAAADAsQDo5MMAoBPCAOCHtwBgCjcAwJ21AAAuNKdIa2mzASc+D+Ce0/Gk0z8AAAAY+1OzPwAAACIsXblAjz7O6MG18r/P2EVqYv8nvkGEXxYwD/m/+VJDXh5k5z91p7vpu/21PaCBwbkAAKisAAAAANDdBgBqCDExAw==","preamble":85,"sender":61568,"sqrta":6493.172393798828,"tgd":-5.587935447692871e-09,"toc":{"tow":450000,"wn":2154},"w":-1.5662079690885238}})), "raw_json");
}
test_auto_check_sbp_observation_msg_ephemeris_qzss_1();

done_testing();