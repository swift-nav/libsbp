# Copyright (C) 2022 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
"""
Generate test case from json input
"""

import argparse
import datetime
import json
import os.path
import sys

from sbp.table import lookup
from sbp.utils import walk_json_dict, exclude_fields

from sbpg.test_structs import PackageTestSpecification, TestSpecification

HERE = os.path.dirname(__file__)
PYTHON_ROOT = os.path.abspath(os.path.join(HERE, "..", "python"))
sys.path.insert(0, PYTHON_ROOT)

from tests.sbp.test_messages import CASES, ROOTPATH  # noqa
from tests.sbp.utils import assert_package  # noqa


def msg_reducer(msg):
    return {
        "fields": walk_json_dict(exclude_fields(msg)),
        "module": msg.__class__.__module__,
        "name": msg.__class__.__name__,
    }


def write_test(msg, output, test_set_name="swiftnav"):
    module = msg.__class__.__module__
    name = msg.__class__.__name__
    test_msg_data = msg_reducer(msg)
    test_data = TestSpecification.from_msg(msg, test_msg_data)
    now_str = datetime.datetime.now().isoformat(" ")
    test_package = PackageTestSpecification(
        package=module,
        description="Unit tests for {}.{} {}".format(test_set_name, module, name),
        generated_on=now_str,
        tests=[test_data],
    )
    print("Writing {} ...".format(output))
    test_package.write(output, exists_ok=True)
    print("Wrote {}".format(output))
    assert_package(output)


def main():
    parser = argparse.ArgumentParser(description="Swift Navigation SBP Test Generator.")
    parser.add_argument("-id", "--msgid", default="-1", help="specify message id")
    parser.add_argument("-in", "--input", help="path to input json file", required=True)
    parser.add_argument("-out", "--output", help="path to output yaml file", required=True)
    args = parser.parse_args()

    f = open(args.input)
    msg = json.loads(f.read())
    f.close()
    msg_type = args.msgid
    if args.msgid == "-1":
        msg_type = msg.get("msg_type")
    clazz = lookup(msg_type)
    print("found class: " + str(clazz.__name__))
    msg_obj = clazz(**msg)

    msg_obj.to_binary()  # sets crc, length, payload
    try:
        write_test(msg_obj, args.output)
    except Exception as e:
        print("Failed creating test for {}: {}".format(clazz.__name__, e))
        raise


if __name__ == "__main__":
    main()
