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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrCodePhaseBiasesBounds.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_code_phase_biases_bounds_1() {
    my $buf = decode_base64("VewFQgAftAAAAAMAAQIBDg8BAwADJwEnAQEDJwEnAQEBJwEnARdx");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'msg_type'}, 0x05EC, "msg_type");
    
    is($msg->{'sender'}, 0x0042, "sender");
    
    is($msg->{'length'}, 31, "length");
    
    is($msg->{'payload'}, "tAAAAAMAAQIBDg8BAwADJwEnAQEDJwEnAQEBJwEnAQ==", "payload");
    
    is($msg->{'crc'}, 0x7117, "crc");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($msg->const_id(), 1, "const_id");
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"num_msgs":1,"seq_num":2,"sol_id":14,"time":{"tow":180,"wn":3},"update_interval":1}})), "header");
    
    is($msg->n_sats_signals(), 3, "n_sats_signals");
    
    is($json->encode($msg->satellites_signals()), $json->encode($json->decode(q{[{"code_bias_bound_mu":39,"code_bias_bound_sig":1,"phase_bias_bound_mu":39,"phase_bias_bound_sig":1,"sat_id":0,"signal_id":3},{"code_bias_bound_mu":39,"code_bias_bound_sig":1,"phase_bias_bound_mu":39,"phase_bias_bound_sig":1,"sat_id":1,"signal_id":3},{"code_bias_bound_mu":39,"code_bias_bound_sig":1,"phase_bias_bound_mu":39,"phase_bias_bound_sig":1,"sat_id":1,"signal_id":1}]})), "satellites_signals");
    
    is($msg->ssr_iod(), 15, "ssr_iod");

    is($json->encode($msg), $json->encode($json->decode(q{{"const_id":1,"crc":28951,"header":{"num_msgs":1,"seq_num":2,"sol_id":14,"time":{"tow":180,"wn":3},"update_interval":1},"length":31,"msg_type":1516,"n_sats_signals":3,"payload":"tAAAAAMAAQIBDg8BAwADJwEnAQEDJwEnAQEBJwEnAQ==","preamble":85,"satellites_signals":[{"code_bias_bound_mu":39,"code_bias_bound_sig":1,"phase_bias_bound_mu":39,"phase_bias_bound_sig":1,"sat_id":0,"signal_id":3},{"code_bias_bound_mu":39,"code_bias_bound_sig":1,"phase_bias_bound_mu":39,"phase_bias_bound_sig":1,"sat_id":1,"signal_id":3},{"code_bias_bound_mu":39,"code_bias_bound_sig":1,"phase_bias_bound_mu":39,"phase_bias_bound_sig":1,"sat_id":1,"signal_id":1}],"sender":66,"ssr_iod":15}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_code_phase_biases_bounds_1();

done_testing();