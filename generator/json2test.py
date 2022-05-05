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
        description=f"Unit tests for {test_set_name}.{module} {name}",
        generated_on=now_str,
        tests=[test_data],
    )
    print(f"Writing {output} ...")
    test_package.write(output, exists_ok=True)
    print(f"Wrote {output}")
    assert_package(output)


def main():
    parser = argparse.ArgumentParser(description="Swift Navigation SBP Test Generator.")
    parser.add_argument("--msg-id", help="specify message id", required=False)
    parser.add_argument("--input", help="path to input json file", required=True)
    parser.add_argument("--output", help="path to output yaml file", required=True)
    args = parser.parse_args()

    with open(args.input) as f:
        msg = json.loads(f.read())

    msg_type = args.msg_id if args.msg_id else msg.get("msg_type")
    if clazz := lookup(int(msg_type)):
        print("found class: " + str(clazz.__name__))
        msg_obj = clazz(**msg)
        msg_obj.to_binary()  # sets crc, length, payload
        try:
            write_test(msg_obj, args.output)
        except Exception as e:
            raise Exception(f"Failed creating test for {clazz.__name__}: {e}")
    else:
        raise Exception(f"msg id {msg_type} not found!")


if __name__ == "__main__":
    main()
