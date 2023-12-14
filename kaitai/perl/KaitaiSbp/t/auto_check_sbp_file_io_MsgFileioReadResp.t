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
# Test cases automatically generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadResp.yaml
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
sub test_auto_check_sbp_file_io_msg_fileio_read_resp_1() {
    my $buf = decode_base64("VaMAwwT/Q7dzD0nn47MSTETl2BVit0W+BfywNyBOCDR/MkdqPU+/ai5Pdvh2z87SW0n7UYPNwZLOuYz5o+dBQ176bZhfe03gfO7NQWcjaNEFvy/5sKbVLsBWIGeS/AQQNqE8Bg2/dLYqv9UU2QiOu+54uPoflyUzsYK+m0dEOO5cgiWJkvZydIql2U8KvYC9AvBcHH5p7OTCADM9SikK74Vqvh4bA/DN/XEZHLtRZdh5KbN4mBJ0NdRkAnLGyAqTGSFz0HE8s7cAKdnO/9Phjr+FUQ/4wUK/9N34x/FwMwG0tH1hkRlI0tfQD344JkEEQBNK329tNCunuspvC1sV7OrEJKuTCvA=");
    my $stream = IO::KaitaiStruct::Stream->new($buf);
    my $msg = ParseUtils::get_flattened_msg(Sbp::SbpMessage->new($stream));
    
    is($msg->{'crc'}, 0xf00a, "crc");
    
    is($msg->{'length'}, 255, "length");
    
    is($msg->{'msg_type'}, 0xa3, "msg_type");
    
    is($msg->{'payload'}, "Q7dzD0nn47MSTETl2BVit0W+BfywNyBOCDR/MkdqPU+/ai5Pdvh2z87SW0n7UYPNwZLOuYz5o+dBQ176bZhfe03gfO7NQWcjaNEFvy/5sKbVLsBWIGeS/AQQNqE8Bg2/dLYqv9UU2QiOu+54uPoflyUzsYK+m0dEOO5cgiWJkvZydIql2U8KvYC9AvBcHH5p7OTCADM9SikK74Vqvh4bA/DN/XEZHLtRZdh5KbN4mBJ0NdRkAnLGyAqTGSFz0HE8s7cAKdnO/9Phjr+FUQ/4wUK/9N34x/FwMwG0tH1hkRlI0tfQD344JkEEQBNK329tNCunuspvC1sV7OrEJKuT", "payload");
    
    is($msg->{'preamble'}, 0x55, "preamble");
    
    is($msg->{'sender'}, 0x04c3, "sender");

    my $json = JSON::PP->new->convert_blessed->canonical;
    
    is($json->encode($msg->contents()), $json->encode($json->decode(q{[73,231,227,179,18,76,68,229,216,21,98,183,69,190,5,252,176,55,32,78,8,52,127,50,71,106,61,79,191,106,46,79,118,248,118,207,206,210,91,73,251,81,131,205,193,146,206,185,140,249,163,231,65,67,94,250,109,152,95,123,77,224,124,238,205,65,103,35,104,209,5,191,47,249,176,166,213,46,192,86,32,103,146,252,4,16,54,161,60,6,13,191,116,182,42,191,213,20,217,8,142,187,238,120,184,250,31,151,37,51,177,130,190,155,71,68,56,238,92,130,37,137,146,246,114,116,138,165,217,79,10,189,128,189,2,240,92,28,126,105,236,228,194,0,51,61,74,41,10,239,133,106,190,30,27,3,240,205,253,113,25,28,187,81,101,216,121,41,179,120,152,18,116,53,212,100,2,114,198,200,10,147,25,33,115,208,113,60,179,183,0,41,217,206,255,211,225,142,191,133,81,15,248,193,66,191,244,221,248,199,241,112,51,1,180,180,125,97,145,25,72,210,215,208,15,126,56,38,65,4,64,19,74,223,111,109,52,43,167,186,202,111,11,91,21,236,234,196,36,171,147]})), "contents");
    
    is($msg->sequence(), 259241795, "sequence");

    is($json->encode($msg), $json->encode($json->decode(q{{"contents":[73,231,227,179,18,76,68,229,216,21,98,183,69,190,5,252,176,55,32,78,8,52,127,50,71,106,61,79,191,106,46,79,118,248,118,207,206,210,91,73,251,81,131,205,193,146,206,185,140,249,163,231,65,67,94,250,109,152,95,123,77,224,124,238,205,65,103,35,104,209,5,191,47,249,176,166,213,46,192,86,32,103,146,252,4,16,54,161,60,6,13,191,116,182,42,191,213,20,217,8,142,187,238,120,184,250,31,151,37,51,177,130,190,155,71,68,56,238,92,130,37,137,146,246,114,116,138,165,217,79,10,189,128,189,2,240,92,28,126,105,236,228,194,0,51,61,74,41,10,239,133,106,190,30,27,3,240,205,253,113,25,28,187,81,101,216,121,41,179,120,152,18,116,53,212,100,2,114,198,200,10,147,25,33,115,208,113,60,179,183,0,41,217,206,255,211,225,142,191,133,81,15,248,193,66,191,244,221,248,199,241,112,51,1,180,180,125,97,145,25,72,210,215,208,15,126,56,38,65,4,64,19,74,223,111,109,52,43,167,186,202,111,11,91,21,236,234,196,36,171,147],"crc":61450,"length":255,"msg_type":163,"payload":"Q7dzD0nn47MSTETl2BVit0W+BfywNyBOCDR/MkdqPU+/ai5Pdvh2z87SW0n7UYPNwZLOuYz5o+dBQ176bZhfe03gfO7NQWcjaNEFvy/5sKbVLsBWIGeS/AQQNqE8Bg2/dLYqv9UU2QiOu+54uPoflyUzsYK+m0dEOO5cgiWJkvZydIql2U8KvYC9AvBcHH5p7OTCADM9SikK74Vqvh4bA/DN/XEZHLtRZdh5KbN4mBJ0NdRkAnLGyAqTGSFz0HE8s7cAKdnO/9Phjr+FUQ/4wUK/9N34x/FwMwG0tH1hkRlI0tfQD344JkEEQBNK329tNCunuspvC1sV7OrEJKuT","preamble":85,"sender":1219,"sequence":259241795}})), "raw_json");
}
test_auto_check_sbp_file_io_msg_fileio_read_resp_1();

done_testing();