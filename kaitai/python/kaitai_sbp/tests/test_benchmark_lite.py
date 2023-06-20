# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import timeit
from kaitai_sbp.tests.utils import count_messages, get_next_msg_construct, get_next_msg_kaitai, get_next_msg_hybrid1, get_next_msg_hybrid2, get_next_msg_external, PERL_CMD


TEST_DATA = "test_data/benchmark.sbp"
COUNT = 1

# Compare speeds of different parsers
def test_benchmarks():
    print("construct: {}".format(timeit.timeit('count_messages(TEST_DATA, get_next_msg_construct)', number=COUNT, globals=globals())))
    print("kaitai: {}".format(timeit.timeit('count_messages(TEST_DATA, get_next_msg_kaitai)', number=COUNT, globals=globals())))
    print("hybrid1: {}".format(timeit.timeit('count_messages(TEST_DATA, get_next_msg_hybrid1)', number=COUNT, globals=globals())))
    print("hybrid2: {}".format(timeit.timeit('count_messages(TEST_DATA, get_next_msg_hybrid2)', number=COUNT, globals=globals())))
    print("perl: {}".format(timeit.timeit('count_messages(TEST_DATA, get_next_msg_external, PERL_CMD)', number=COUNT, globals=globals())))
