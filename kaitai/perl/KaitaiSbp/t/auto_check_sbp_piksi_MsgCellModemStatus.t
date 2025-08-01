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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCellModemStatus.yaml
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
sub test_auto_check_sbp_piksi_msg_cell_modem_status_1() {
    my $buf = decode_base64("Vb4AExv/Z80wBkZ78i40QLCaYiuExFn9ofquzG4vJrs/ZrGiMVDCJWs84TRlso72FRFdS6lWENFQ8x7O3M5zL5pb41gLAVWSZL7ozz09ydwfTiI5UjtoQd0AK9IJIHod7QuX3xJRzKzqfwNShakMsMEAGHlVN9bGS+qz1lVecxVJeUsunj9ketUUVdSDMuDa19eVAhOBJ6QFrwY+M05C+HRYWoDisQAvjCF+3W6QYUr6tccbsEG5blwiLINgsiiwBFokB7T09Bdsq8zEPTOz8pxRUxAPhij1/ZZelpDFcQWN6CFl5yZLsvN3AfjaVgdYxZTw4wJBrXqP+5zZQ+/bH+CwgVFQKOY=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xe628, "crc");
    
    is($msg->{'length'}, 255, "length");
    
    is($msg->{'msg_type'}, 0xbe, "msg_type");
    
    is($msg->{'payload'}, "Z80wBkZ78i40QLCaYiuExFn9ofquzG4vJrs/ZrGiMVDCJWs84TRlso72FRFdS6lWENFQ8x7O3M5zL5pb41gLAVWSZL7ozz09ydwfTiI5UjtoQd0AK9IJIHod7QuX3xJRzKzqfwNShakMsMEAGHlVN9bGS+qz1lVecxVJeUsunj9ketUUVdSDMuDa19eVAhOBJ6QFrwY+M05C+HRYWoDisQAvjCF+3W6QYUr6tccbsEG5blwiLINgsiiwBFokB7T09Bdsq8zEPTOz8pxRUxAPhij1/ZZelpDFcQWN6CFl5yZLsvN3AfjaVgdYxZTw4wJBrXqP+5zZQ+/bH+CwgVFQ", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x1b13, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->reserved()), $json->encode($json->decode(q{[123,242,46,52,64,176,154,98,43,132,196,89,253,161,250,174,204,110,47,38,187,63,102,177,162,49,80,194,37,107,60,225,52,101,178,142,246,21,17,93,75,169,86,16,209,80,243,30,206,220,206,115,47,154,91,227,88,11,1,85,146,100,190,232,207,61,61,201,220,31,78,34,57,82,59,104,65,221,0,43,210,9,32,122,29,237,11,151,223,18,81,204,172,234,127,3,82,133,169,12,176,193,0,24,121,85,55,214,198,75,234,179,214,85,94,115,21,73,121,75,46,158,63,100,122,213,20,85,212,131,50,224,218,215,215,149,2,19,129,39,164,5,175,6,62,51,78,66,248,116,88,90,128,226,177,0,47,140,33,126,221,110,144,97,74,250,181,199,27,176,65,185,110,92,34,44,131,96,178,40,176,4,90,36,7,180,244,244,23,108,171,204,196,61,51,179,242,156,81,83,16,15,134,40,245,253,150,94,150,144,197,113,5,141,232,33,101,231,38,75,178,243,119,1,248,218,86,7,88,197,148,240,227,2,65,173,122,143,251,156,217,67,239,219,31,224,176,129,81,80]})), "reserved");
    
    is($msg->signal_error_rate(), 8588.2001953125, "signal_error_rate");
    
    is($msg->signal_strength(), 103, "signal_strength");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":58920,"length":255,"msg_type":190,"payload":"Z80wBkZ78i40QLCaYiuExFn9ofquzG4vJrs/ZrGiMVDCJWs84TRlso72FRFdS6lWENFQ8x7O3M5zL5pb41gLAVWSZL7ozz09ydwfTiI5UjtoQd0AK9IJIHod7QuX3xJRzKzqfwNShakMsMEAGHlVN9bGS+qz1lVecxVJeUsunj9ketUUVdSDMuDa19eVAhOBJ6QFrwY+M05C+HRYWoDisQAvjCF+3W6QYUr6tccbsEG5blwiLINgsiiwBFokB7T09Bdsq8zEPTOz8pxRUxAPhij1/ZZelpDFcQWN6CFl5yZLsvN3AfjaVgdYxZTw4wJBrXqP+5zZQ+/bH+CwgVFQ","preamble":85,"reserved":[123,242,46,52,64,176,154,98,43,132,196,89,253,161,250,174,204,110,47,38,187,63,102,177,162,49,80,194,37,107,60,225,52,101,178,142,246,21,17,93,75,169,86,16,209,80,243,30,206,220,206,115,47,154,91,227,88,11,1,85,146,100,190,232,207,61,61,201,220,31,78,34,57,82,59,104,65,221,0,43,210,9,32,122,29,237,11,151,223,18,81,204,172,234,127,3,82,133,169,12,176,193,0,24,121,85,55,214,198,75,234,179,214,85,94,115,21,73,121,75,46,158,63,100,122,213,20,85,212,131,50,224,218,215,215,149,2,19,129,39,164,5,175,6,62,51,78,66,248,116,88,90,128,226,177,0,47,140,33,126,221,110,144,97,74,250,181,199,27,176,65,185,110,92,34,44,131,96,178,40,176,4,90,36,7,180,244,244,23,108,171,204,196,61,51,179,242,156,81,83,16,15,134,40,245,253,150,94,150,144,197,113,5,141,232,33,101,231,38,75,178,243,119,1,248,218,86,7,88,197,148,240,227,2,65,173,122,143,251,156,217,67,239,219,31,224,176,129,81,80],"sender":6931,"signal_error_rate":8588.2001953125,"signal_strength":103}})), "raw_json");
}
test_auto_check_sbp_piksi_msg_cell_modem_status_1();

done_testing();
