#!/usr/bin/env python
# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from .utils import assert_package
from sbp.table import _SBP_TABLE
import os.path

import pytest

HERE = os.path.dirname(__file__)
PYTHON_ROOT = os.path.join(HERE, "..", "..")
ROOTPATH = os.path.join(PYTHON_ROOT, "..", "spec", "tests", "yaml")

EXPECTED_MISSING_MESSAGES = 120


def process_files(path, filenames):
    """
    Scans for <msg>.yaml files
    """
    for filename in filenames:
        if filename.endswith(".yaml"):
            filepath = os.path.join(path, filename)
            filepath = os.path.relpath(filepath, ROOTPATH)
            yield (filepath)


def process_path(path):
    for root, dirs, files in os.walk(path, topdown=True):
        for path in process_files(root, files):
            yield path


CASES = list(process_path(ROOTPATH))


def test_message_case_count():
    total_messages = len(_SBP_TABLE)
    test_count = len(CASES)
    missing_messages = total_messages - test_count

    assert test_count > 0, "No message definitions found in %s" % ROOTPATH
    assert test_count <= total_messages, "Found tests for nonexistent messages"

    # TODO: ideally we need tests for every message type
    assert (
        missing_messages <= EXPECTED_MISSING_MESSAGES
    ), "Missing tests for %d out of %d messages" % (missing_messages, total_messages)

@pytest.mark.parametrize("case", CASES)
def test_message(case):
    assert_package(ROOTPATH + "/" + case)
