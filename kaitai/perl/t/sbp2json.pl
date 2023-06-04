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

use strict;

use constant SBP_PATH => "$ENV{'PWD'}/kaitai/perl/";
use constant SBP_HEADER_LEN => 6;

BEGIN {
    # add SBP_PATH to include path and load all modules
    unshift @INC, &SBP_PATH;
    require $_ for(glob(&SBP_PATH."*.pm"));
}

use JSON::PP;
use t::Utils;


sub sbp2json($) {
    my $fd = shift || die;

    my $json = JSON::PP->new->convert_blessed;

    my $stream = BufferedKaitaiStream->new($fd, &SBP_HEADER_LEN + 256 + 2); # header + max message + CRC);

    while(!$stream->is_eof()) {
        $stream->reload();

        my $msg = eval { Sbp::SbpMessage->new($stream) };
        last if $@;

        $msg = Utils::get_flattened_msg($msg);
        print $json->encode($msg), "\n";
    }
}

sbp2json(\*STDIN);
