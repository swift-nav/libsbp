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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgOsr.yaml
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
sub test_auto_check_sbp_observation_msg_osr_1() {
    my $buf = decode_base64("VUAGAADv+OHpHQAAAABoCEBLj/FE5vo+B0IPAwEADQAHAAcAzuhpP+wxqgZLDwMNAA0AAwADAC2Rxj4hB5kGgA8DDgANAAMAAwBZhMxDjy4gB38PAw8ADQAFAAUA9P6kPBawXwY3DwMRAAAAAgACAGqdZT6X1o4GbA8DEwANAAMAAwBR7Tw/tXelBs4PAxwADQADAAMAhuRuQLefxQbIDwMeAA0AAwADADWQ8UROcKUFqg8DAQYVAAcABwD76Gk/o4AxBYEPAw0GFQADAAMAcJHGPiUgJAUuDwMOBhUAAwADAKaEzEO4cI0FXw8DDwYVAAUABQB54w==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = Utils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe379, "crc");
    
    is($msg->{'length'}, 239, "length");
    
    is($msg->{'payload'}, "+OHpHQAAAABoCEBLj/FE5vo+B0IPAwEADQAHAAcAzuhpP+wxqgZLDwMNAA0AAwADAC2Rxj4hB5kGgA8DDgANAAMAAwBZhMxDjy4gB38PAw8ADQAFAAUA9P6kPBawXwY3DwMRAAAAAgACAGqdZT6X1o4GbA8DEwANAAMAAwBR7Tw/tXelBs4PAxwADQADAAMAhuRuQLefxQbIDwMeAA0AAwADADWQ8UROcKUFqg8DAQYVAAcABwD76Gk/o4AxBYEPAw0GFQADAAMAcJHGPiUgJAUuDwMOBhUAAwADAKaEzEO4cI0FXw8DDwYVAAUABQA=", "payload");
    
    is($msg->{'msg_type'}, 0x640, "msg_type");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"n_obs":64,"t":{"ns_residual":0,"tow":501867000,"wn":2152}}})), "header");
    
    is($json->encode($msg->obs()), $json->encode($json->decode(q{[{"flags":3,"iono_std":13,"l":{"f":66,"i":121567974},"lock":15,"p":1156681547,"range_std":7,"sid":{"code":0,"sat":1},"tropo_std":7},{"flags":3,"iono_std":13,"l":{"f":75,"i":111817196},"lock":15,"p":1063905486,"range_std":3,"sid":{"code":0,"sat":13},"tropo_std":3},{"flags":3,"iono_std":13,"l":{"f":128,"i":110692129},"lock":15,"p":1053200685,"range_std":3,"sid":{"code":0,"sat":14},"tropo_std":3},{"flags":3,"iono_std":13,"l":{"f":127,"i":119549583},"lock":15,"p":1137476697,"range_std":5,"sid":{"code":0,"sat":15},"tropo_std":5},{"flags":3,"iono_std":0,"l":{"f":55,"i":106934294},"lock":15,"p":1017446132,"range_std":2,"sid":{"code":0,"sat":17},"tropo_std":2},{"flags":3,"iono_std":13,"l":{"f":108,"i":110024343},"lock":15,"p":1046846826,"range_std":3,"sid":{"code":0,"sat":19},"tropo_std":3},{"flags":3,"iono_std":13,"l":{"f":206,"i":111507381},"lock":15,"p":1060957521,"range_std":3,"sid":{"code":0,"sat":28},"tropo_std":3},{"flags":3,"iono_std":13,"l":{"f":200,"i":113614775},"lock":15,"p":1081009286,"range_std":3,"sid":{"code":0,"sat":30},"tropo_std":3},{"flags":3,"iono_std":21,"l":{"f":170,"i":94728270},"lock":15,"p":1156681781,"range_std":7,"sid":{"code":6,"sat":1},"tropo_std":7},{"flags":3,"iono_std":21,"l":{"f":129,"i":87130275},"lock":15,"p":1063905531,"range_std":3,"sid":{"code":6,"sat":13},"tropo_std":3},{"flags":3,"iono_std":21,"l":{"f":46,"i":86253605},"lock":15,"p":1053200752,"range_std":3,"sid":{"code":6,"sat":14},"tropo_std":3},{"flags":3,"iono_std":21,"l":{"f":95,"i":93155512},"lock":15,"p":1137476774,"range_std":5,"sid":{"code":6,"sat":15},"tropo_std":5}]})), "obs");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":58233,"header":{"n_obs":64,"t":{"ns_residual":0,"tow":501867000,"wn":2152}},"length":239,"msg_type":1600,"obs":[{"flags":3,"iono_std":13,"l":{"f":66,"i":121567974},"lock":15,"p":1156681547,"range_std":7,"sid":{"code":0,"sat":1},"tropo_std":7},{"flags":3,"iono_std":13,"l":{"f":75,"i":111817196},"lock":15,"p":1063905486,"range_std":3,"sid":{"code":0,"sat":13},"tropo_std":3},{"flags":3,"iono_std":13,"l":{"f":128,"i":110692129},"lock":15,"p":1053200685,"range_std":3,"sid":{"code":0,"sat":14},"tropo_std":3},{"flags":3,"iono_std":13,"l":{"f":127,"i":119549583},"lock":15,"p":1137476697,"range_std":5,"sid":{"code":0,"sat":15},"tropo_std":5},{"flags":3,"iono_std":0,"l":{"f":55,"i":106934294},"lock":15,"p":1017446132,"range_std":2,"sid":{"code":0,"sat":17},"tropo_std":2},{"flags":3,"iono_std":13,"l":{"f":108,"i":110024343},"lock":15,"p":1046846826,"range_std":3,"sid":{"code":0,"sat":19},"tropo_std":3},{"flags":3,"iono_std":13,"l":{"f":206,"i":111507381},"lock":15,"p":1060957521,"range_std":3,"sid":{"code":0,"sat":28},"tropo_std":3},{"flags":3,"iono_std":13,"l":{"f":200,"i":113614775},"lock":15,"p":1081009286,"range_std":3,"sid":{"code":0,"sat":30},"tropo_std":3},{"flags":3,"iono_std":21,"l":{"f":170,"i":94728270},"lock":15,"p":1156681781,"range_std":7,"sid":{"code":6,"sat":1},"tropo_std":7},{"flags":3,"iono_std":21,"l":{"f":129,"i":87130275},"lock":15,"p":1063905531,"range_std":3,"sid":{"code":6,"sat":13},"tropo_std":3},{"flags":3,"iono_std":21,"l":{"f":46,"i":86253605},"lock":15,"p":1053200752,"range_std":3,"sid":{"code":6,"sat":14},"tropo_std":3},{"flags":3,"iono_std":21,"l":{"f":95,"i":93155512},"lock":15,"p":1137476774,"range_std":5,"sid":{"code":6,"sat":15},"tropo_std":5}],"payload":"+OHpHQAAAABoCEBLj/FE5vo+B0IPAwEADQAHAAcAzuhpP+wxqgZLDwMNAA0AAwADAC2Rxj4hB5kGgA8DDgANAAMAAwBZhMxDjy4gB38PAw8ADQAFAAUA9P6kPBawXwY3DwMRAAAAAgACAGqdZT6X1o4GbA8DEwANAAMAAwBR7Tw/tXelBs4PAxwADQADAAMAhuRuQLefxQbIDwMeAA0AAwADADWQ8UROcKUFqg8DAQYVAAcABwD76Gk/o4AxBYEPAw0GFQADAAMAcJHGPiUgJAUuDwMOBhUAAwADAKaEzEO4cI0FXw8DDwYVAAUABQA=","preamble":85,"sender":0}})), "raw_json");
}
test_auto_check_sbp_observation_msg_osr_1();

done_testing();