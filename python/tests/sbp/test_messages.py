#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from utils import assert_package
from sbp.table import _SBP_TABLE
import os

ROOTPATH = "../spec/tests/yaml"

def process_files(path, filenames):
  """
  Scans for <msg>.yaml files and verifies decoding

  """
  test_count = 0
  for filename in filenames:
    if filename.endswith(".yaml"):
      filepath = os.path.join(path, filename)
      assert_package(filepath, filename)
      test_count += 1
  return test_count

def process_path(path):
  test_count = 0
  for root, dirs, files in os.walk(path, topdown=True):
    test_count += process_files(root, files)
  for dir in dirs:
    test_count += process_path(os.path.join(root, dir))
  return test_count

def test_messages():
  test_count = process_path(ROOTPATH)

  total_messages = len(_SBP_TABLE)
  missing_messages = total_messages - test_count

  assert test_count > 0, "No message definitions found in %s" % ROOTDIR
  assert test_count <= total_messages, "Found tests for nonexistent messages"

  # TODO: ideally we need tests for every message type
  #assert missing_messages == 0, "Missing tests for %d out of %d messages" % (missing_messages, total_messages)
