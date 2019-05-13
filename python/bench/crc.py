#!/usr/bin/env python

# Copyright (C) 2019 Swift Navigation Inc.
# Contact: Swift Navigation <dev@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import random
import timeit

from sbp.msg import crc16, crc16_nojit

blob_count = 5000
blob_size = 256

blobs = []

print("Start: building random data...")

for _ in range(blob_count):
    blob = bytes(b'').join(
        (chr(int(0xFF * random.random()) & 0xFF)) for X in range(blob_size))
    blobs.append(blob)

print("End: building random data.")


def run_crc():
    for blob in blobs:
        crc16(blob)


def run_crc2():
    for blob in blobs:
        crc16_nojit(blob)


def main():
    t = timeit.Timer('run_crc()', 'from __main__ import run_crc').timeit(100)
    print(t)
    t = timeit.Timer('run_crc2()', 'from __main__ import run_crc2').timeit(100)
    print(t)


if __name__ == '__main__':
    main()
