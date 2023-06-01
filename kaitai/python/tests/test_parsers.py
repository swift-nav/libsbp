# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from kaitai.python.tests.utils import compare_parser_outputs, count_messages, get_next_msg_construct, get_next_msg_kaitai, get_next_msg_hybrid1, get_next_msg_hybrid2
import os
import random
import tempfile


TEST_DATA = "test_data/benchmark.sbp"


def create_corrupted_file():
    fd_corrupted, filename_corrupted = tempfile.mkstemp()
    random.seed()
    with os.fdopen(fd_corrupted, 'wb') as fp_corrupted:
        with open(TEST_DATA, 'rb') as fp_orig:
            while True:
                # read random amount
                buf = fp_orig.read(random.randrange(8192)) # NOSONAR
                if buf is None or len(buf) == 0:
                    break
                fp_corrupted.write(buf)
                if random.random() < 0.5: # NOSONAR
                    # drop bytes
                    fp_orig.read(random.randrange(3)) # NOSONAR
                else:
                    # write garbage
                    fp_corrupted.write(bytes(chr(random.randrange(127)), encoding='ascii')) # NOSONAR

    return filename_corrupted


# confirm that all parsers produce the same output with uncorrupted input
def test_uncorrupted():
    num_messages = compare_parser_outputs(TEST_DATA)
    print("Uncorrupted test: success, {} messages".format(num_messages))
    assert(num_messages == 150000)


# confirm that all parsers produce the same output with corrupted input
def test_corrupted_output():
    filename_corrupted = create_corrupted_file()
    num_messages = compare_parser_outputs(filename_corrupted)
    print("Corrupted test: success, {} messages".format(num_messages))
    assert(num_messages <= 150000)
    os.unlink(filename_corrupted)


# confirm that all parsers produce the same number of messages with corrupted input
def test_corrupted_counts():
    filename_corrupted = create_corrupted_file()
    num_messages_construct = count_messages(filename_corrupted, get_next_msg_construct)
    num_messages_kaitai = count_messages(filename_corrupted, get_next_msg_kaitai)
    num_messages_hybrid1 = count_messages(filename_corrupted, get_next_msg_hybrid1)
    num_messages_hybrid2 = count_messages(filename_corrupted, get_next_msg_hybrid2)

    assert(num_messages_construct == num_messages_kaitai)
    assert(num_messages_construct == num_messages_hybrid1)
    assert(num_messages_construct == num_messages_hybrid2)
