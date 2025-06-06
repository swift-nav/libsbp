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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGridDefinitionDepA.yaml
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
sub test_auto_check_sbp_ssr_msg_ssr_grid_definition_dep_a_1() {
    my $buf = decode_base64("VfUFtff/C1Sr5YSPLsw0XGgZzLYWYst70yYN/YGtq+v9GssDeH4qLCdXRZoNHLMgLyTDJ8aG64Y5ePOXIxHJ0311pI5l75Ce71o4R3hD3XIKvgTmpKtOuVousVLke97jkcPbGzjj9teQnh/W8f7IVo5ZDHkdfAkTmSwjfg7ZQXQai3pyWnxRALr2LmKz88bZJB7KDIc9KpbdZlOzK/xRPn7Mw+4SgME1XmM/tgK63E264NwN1LZYD5cFXfukEuSo4sMsqpEkOmBrkAvkDKPu95+9AXNBynkvwQtgXUhRz3kTl4jpM4XDTSyTznj8TdREPM5qz/OeXgYDzVxUAtwyPSaNdWxlTIs=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0x8b4c, "crc");
    
    is($msg->{'length'}, 255, "length");
    
    is($msg->{'msg_type'}, 0x5f5, "msg_type");
    
    is($msg->{'payload'}, "C1Sr5YSPLsw0XGgZzLYWYst70yYN/YGtq+v9GssDeH4qLCdXRZoNHLMgLyTDJ8aG64Y5ePOXIxHJ0311pI5l75Ce71o4R3hD3XIKvgTmpKtOuVousVLke97jkcPbGzjj9teQnh/W8f7IVo5ZDHkdfAkTmSwjfg7ZQXQai3pyWnxRALr2LmKz88bZJB7KDIc9KpbdZlOzK/xRPn7Mw+4SgME1XmM/tgK63E264NwN1LZYD5cFXfukEuSo4sMsqpEkOmBrkAvkDKPu95+9AXNBynkvwQtgXUhRz3kTl4jpM4XDTSyTznj8TdREPM5qz/OeXgYDzVxUAtwyPSaNdWxl", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0xf7b5, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->header()), $json->encode($json->decode(q{{"area_width":43860,"lat_nw_corner_enc":34021,"lon_nw_corner_enc":11919,"num_msgs":204,"region_size_inverse":11,"seq_num":52}})), "header");
    
    is($json->encode($msg->rle_list()), $json->encode($json->decode(q{[92,104,25,204,182,22,98,203,123,211,38,13,253,129,173,171,235,253,26,203,3,120,126,42,44,39,87,69,154,13,28,179,32,47,36,195,39,198,134,235,134,57,120,243,151,35,17,201,211,125,117,164,142,101,239,144,158,239,90,56,71,120,67,221,114,10,190,4,230,164,171,78,185,90,46,177,82,228,123,222,227,145,195,219,27,56,227,246,215,144,158,31,214,241,254,200,86,142,89,12,121,29,124,9,19,153,44,35,126,14,217,65,116,26,139,122,114,90,124,81,0,186,246,46,98,179,243,198,217,36,30,202,12,135,61,42,150,221,102,83,179,43,252,81,62,126,204,195,238,18,128,193,53,94,99,63,182,2,186,220,77,186,224,220,13,212,182,88,15,151,5,93,251,164,18,228,168,226,195,44,170,145,36,58,96,107,144,11,228,12,163,238,247,159,189,1,115,65,202,121,47,193,11,96,93,72,81,207,121,19,151,136,233,51,133,195,77,44,147,206,120,252,77,212,68,60,206,106,207,243,158,94,6,3,205,92,84,2,220,50,61,38,141,117,108,101]})), "rle_list");

    is($json->encode($msg), $json->encode($json->decode(q{{"crc":35660,"header":{"area_width":43860,"lat_nw_corner_enc":34021,"lon_nw_corner_enc":11919,"num_msgs":204,"region_size_inverse":11,"seq_num":52},"length":255,"msg_type":1525,"payload":"C1Sr5YSPLsw0XGgZzLYWYst70yYN/YGtq+v9GssDeH4qLCdXRZoNHLMgLyTDJ8aG64Y5ePOXIxHJ0311pI5l75Ce71o4R3hD3XIKvgTmpKtOuVousVLke97jkcPbGzjj9teQnh/W8f7IVo5ZDHkdfAkTmSwjfg7ZQXQai3pyWnxRALr2LmKz88bZJB7KDIc9KpbdZlOzK/xRPn7Mw+4SgME1XmM/tgK63E264NwN1LZYD5cFXfukEuSo4sMsqpEkOmBrkAvkDKPu95+9AXNBynkvwQtgXUhRz3kTl4jpM4XDTSyTznj8TdREPM5qz/OeXgYDzVxUAtwyPSaNdWxl","preamble":85,"rle_list":[92,104,25,204,182,22,98,203,123,211,38,13,253,129,173,171,235,253,26,203,3,120,126,42,44,39,87,69,154,13,28,179,32,47,36,195,39,198,134,235,134,57,120,243,151,35,17,201,211,125,117,164,142,101,239,144,158,239,90,56,71,120,67,221,114,10,190,4,230,164,171,78,185,90,46,177,82,228,123,222,227,145,195,219,27,56,227,246,215,144,158,31,214,241,254,200,86,142,89,12,121,29,124,9,19,153,44,35,126,14,217,65,116,26,139,122,114,90,124,81,0,186,246,46,98,179,243,198,217,36,30,202,12,135,61,42,150,221,102,83,179,43,252,81,62,126,204,195,238,18,128,193,53,94,99,63,182,2,186,220,77,186,224,220,13,212,182,88,15,151,5,93,251,164,18,228,168,226,195,44,170,145,36,58,96,107,144,11,228,12,163,238,247,159,189,1,115,65,202,121,47,193,11,96,93,72,81,207,121,19,151,136,233,51,133,195,77,44,147,206,120,252,77,212,68,60,206,106,207,243,158,94,6,3,205,92,84,2,220,50,61,38,141,117,108,101],"sender":63413}})), "raw_json");
}
test_auto_check_sbp_ssr_msg_ssr_grid_definition_dep_a_1();

done_testing();
