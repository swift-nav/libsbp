# Copyright (C) 2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import sys

import pytest


def test_jit_deprecation():
    """
    Test importing deprecated module emits warning.
    """
    if "sbp.jit" in sys.modules:
        del sys.modules["sbp.jit"]
    with pytest.warns(UserWarning) as records:
        import sbp.jit as _unused

        _unused

    assert len(records) == 1
