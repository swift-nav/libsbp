# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from .utils import PYTHON_ROOT
import sbp.sbp2json
import os

TEST_DATA = os.path.join(PYTHON_ROOT, "..", "test_data", "benchmark.sbp")


# make sure that we parse exactly 150000 SBP messages from TEST_DATA
def test_sbp2json():
    msg_count = 0
    def counter(args, res):
        nonlocal msg_count
        msg_count += 1

    sbp.sbp2json.dump = counter

    # anonymous object to emulate parsed arguments
    args = type('',(object,),{
        'file': open(TEST_DATA, "rb"),
        'include': []
    })()

    sbp.sbp2json.sbp_main(args)

    assert msg_count == 150000
