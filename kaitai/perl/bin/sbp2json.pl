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

BEGIN {
    use Cwd qw(realpath);
    use File::Basename;
    my $SBP_PATH = realpath(dirname($0))."/..";
    # add parent directory to search path
    unshift @INC, $SBP_PATH;
    # load all modules from parent directory
    require $_ for(glob("$SBP_PATH/*.pm"));
}

use JSON::XS;
use Digest::CRC qw(crc);


sub sbp2json($) {
    my $fd = shift || die;

    my $json = JSON::XS->new->convert_blessed;

    my $stream = BufferedKaitaiStream->new($fd, &BufferedKaitaiStream::SBP_HEADER_LEN + 256 + 2); # header + max message + CRC

    while(1) {
        $stream->fill_buffer();

        my $msg = eval { SbpTable::SbpMessage->new($stream) };

        if(!defined($msg)) {
            if($stream->is_eof()) {
                last;
            } else {
                $stream->seek(1);
                next;
            }
        }

        my $crc_read = $msg->crc();
        my $crc_expected = crc($stream->get_crc_bytes($msg->length()), 16, 0, 0, 0, 0x1021, 0, 0);
        if($crc_read != $crc_expected) {
            print STDERR "Bad CRC: $crc_read vs $crc_expected\n";
            $stream->seek(1);
            next;
        }

        $msg = ParseUtils::get_flattened_msg($msg);
        print $json->encode($msg), "\n";
    }
}

if(@ARGV) {
    foreach(@ARGV) {
        open(my $fh, '<', $_) || die "Cannot open '$_'";
        sbp2json($fh);
        close $fh;
    }
} else {
    sbp2json(\*STDIN);
}
