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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgNetworkBandwidthUsage.yaml
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
sub test_auto_check_sbp_piksi_msg_network_bandwidth_usage_1() {
    my $buf = decode_base64("Vb0Az3nIXmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAY2FuMAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAGNhbjEAAAAAAAAAAAAAAABeabKAAAAAAKXrXssAAAAA7Q6U8LjcytpldGgwAAAAAAAAAAAAAAAAXmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAbG8AAAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAHNpdDAAAAAAAAAAAAAAAAAbhQ==");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x851B, "crc");
    
    is($msg->{'length'}, 200, "length");
    
    is($msg->{'msg_type'}, 0xBD, "msg_type");
    
    is($msg->{'payload'}, "XmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAY2FuMAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAGNhbjEAAAAAAAAAAAAAAABeabKAAAAAAKXrXssAAAAA7Q6U8LjcytpldGgwAAAAAAAAAAAAAAAAXmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAbG8AAAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAHNpdDAAAAAAAAAAAAAAAAA=", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x79CF, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->interfaces()), $json->encode($json->decode(q{[{"duration":2159176030,"interface_name":"can0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","rx_bytes":0,"total_bytes":0,"tx_bytes":0},{"duration":2159176030,"interface_name":"can1\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","rx_bytes":0,"total_bytes":0,"tx_bytes":0},{"duration":2159176030,"interface_name":"eth0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","rx_bytes":4036234989,"total_bytes":3411995557,"tx_bytes":3670727864},{"duration":2159176030,"interface_name":"lo\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","rx_bytes":0,"total_bytes":0,"tx_bytes":0},{"duration":2159176030,"interface_name":"sit0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","rx_bytes":0,"total_bytes":0,"tx_bytes":0}]})), "interfaces");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":34075,"interfaces":[{"duration":2159176030,"interface_name":"can0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","rx_bytes":0,"total_bytes":0,"tx_bytes":0},{"duration":2159176030,"interface_name":"can1\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","rx_bytes":0,"total_bytes":0,"tx_bytes":0},{"duration":2159176030,"interface_name":"eth0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","rx_bytes":4036234989,"total_bytes":3411995557,"tx_bytes":3670727864},{"duration":2159176030,"interface_name":"lo\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","rx_bytes":0,"total_bytes":0,"tx_bytes":0},{"duration":2159176030,"interface_name":"sit0\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000","rx_bytes":0,"total_bytes":0,"tx_bytes":0}],"length":200,"msg_type":189,"payload":"XmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAY2FuMAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAGNhbjEAAAAAAAAAAAAAAABeabKAAAAAAKXrXssAAAAA7Q6U8LjcytpldGgwAAAAAAAAAAAAAAAAXmmygAAAAAAAAAAAAAAAAAAAAAAAAAAAbG8AAAAAAAAAAAAAAAAAAF5psoAAAAAAAAAAAAAAAAAAAAAAAAAAAHNpdDAAAAAAAAAAAAAAAAA=","preamble":85,"sender":31183}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_network_bandwidth_usage_1();

done_testing();